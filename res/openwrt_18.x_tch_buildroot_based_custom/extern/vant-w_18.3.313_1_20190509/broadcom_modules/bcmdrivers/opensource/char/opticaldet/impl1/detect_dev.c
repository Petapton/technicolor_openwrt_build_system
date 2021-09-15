/*
<:copyright-BRCM:2015:DUAL/GPL:standard

   Copyright (c) 2015 Broadcom 
   All Rights Reserved

Unless you and Broadcom execute a separate written software license
agreement governing use of this software, this software is licensed
to you under the terms of the GNU General Public License version 2
(the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
with the following added to such license:

   As a special exception, the copyright holders of this software give
   you permission to link this software with independent modules, and
   to copy and distribute the resulting executable under terms of your
   choice, provided that you also meet, for each linked independent
   module, the terms and conditions of the license of that module.
   An independent module is a module which is not derived from this
   software.  The special exception does not apply to any modifications
   of the software.

Not withstanding the above, under no circumstances may you combine
this software in any way with any other Broadcom software provided
under a license other than the GPL, without Broadcom's express prior
written consent.

:>
*/

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/i2c.h>
#include <linux/slab.h>  /* kzalloc() */
#include <linux/types.h>
#include <pon_i2c.h>
#include "detect.h"
#include <bcm_intr.h>
#include <boardparms.h>
#include <linux/interrupt.h>
#include <board.h>
#include "detect_dev_trx_data.h"


static int _file_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int _file_release(struct inode *inode, struct file *file)
{
    return 0;
}

static long _detect_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
#ifdef CONFIG_BCM96838
    unsigned long *val = (unsigned long *)arg;
#endif

    switch (cmd)
    {
#ifdef CONFIG_BCM96838
        case OPTICALDET_IOCTL_DETECT:
            *val = opticaldetect();
            break;
        case OPTICALDET_IOCTL_SD:
            *val = signalDetect();
            break;
#endif
        default:
            printk("%s: ERROR: No such IOCTL", __FILE__);
            return -1;
    }

    return 0;
}

static const struct file_operations detect_file_ops =
{
    .owner = THIS_MODULE,
    .open = _file_open,
    .release = _file_release,
    .unlocked_ioctl = _detect_ioctl,
#if defined(CONFIG_COMPAT)
    .compat_ioctl = _detect_ioctl,
#endif
};


static void work_cb(struct work_struct *work)
{
   i2c_read_trx_data();
   trx_fixup();
}

static DECLARE_DELAYED_WORK(i2c_work, work_cb);

static irqreturn_t pres_isr(int irq, void *arg)
{
    queue_delayed_work(system_unbound_wq, &i2c_work, HZ/3); /* Wait a bit for trx */

#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
    BcmHalExternalIrqClear(irq);
#endif
    return IRQ_HANDLED;
}



int __init detect_init(void)
{
    int ret;
    unsigned short intr, gpio;

    if (!BpGetOpticalModuleFixupGpio(&gpio))
        kerSysSetGpioDir(gpio);

    if (BpGetOpticalModulePresenceExtIntr(&intr) == BP_SUCCESS)
    {
      ret = ponPhy_read_byte(0, 0) ;
      if (ret >= 0) { /* Check if trx is already inserted */
          i2c_read_trx_data();
          trx_fixup();
      }

      ret = ext_irq_connect(intr, (void *)0, (FN_HANDLER)pres_isr);
      if (ret)
        return -1;
    }

    ret = register_chrdev(DEV_MAJOR, DEV_CLASS, &detect_file_ops);
    pr_info(KERN_ALERT "Optical WAN detection module %s.\n", ret ?
        "failed to load" : "loaded");

    return ret;
}
module_init(detect_init);

static void __exit detect_exit(void)
{
    unsigned short intr;

    unregister_chrdev(DEV_MAJOR, DEV_CLASS);
    if (BpGetOpticalModulePresenceExtIntr(&intr) == BP_SUCCESS)
        free_irq(intr, NULL);
}
module_exit(detect_exit);

MODULE_AUTHOR("Broadcom");
MODULE_DESCRIPTION("Optical WAN detect driver");
MODULE_LICENSE("GPL");

