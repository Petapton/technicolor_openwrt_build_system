/****************************************************************************
 *
 * <:copyright-BRCM:2015:DUAL/GPL:standard
 * 
 *    Copyright (c) 2015 Broadcom 
 *    All Rights Reserved
 * 
 * Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed
 * to you under the terms of the GNU General Public License version 2
 * (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
 * with the following added to such license:
 * 
 *    As a special exception, the copyright holders of this software give
 *    you permission to link this software with independent modules, and
 *    to copy and distribute the resulting executable under terms of your
 *    choice, provided that you also meet, for each linked independent
 *    module, the terms and conditions of the license of that module.
 *    An independent module is a module which is not derived from this
 *    software.  The special exception does not apply to any modifications
 *    of the software.
 * 
 * Not withstanding the above, under no circumstances may you combine
 * this software in any way with any other Broadcom software provided
 * under a license other than the GPL, without Broadcom's express prior
 * written consent.
 * 
 * :>
 *
 ****************************************************************************/
#ifndef _BCM_DSPHAL_H
#define _BCM_DSPHAL_H

#include <linux/ioctl.h>

/****************************************************************************
* Typedefs and Constants
****************************************************************************/
#define DSPHAL_DEV_NAME                "dsphal"
#define DEV_MAJOR                      3050
#define DEV_MINOR                      0

#define DSPHAL_CMD_INIT                _IOW (DEV_MAJOR,  0, unsigned int)
#define DSPHAL_CMD_ENABLE              _IOWR(DEV_MAJOR,  1, struct dsphal_cmdenable)
#define DSPHAL_CMD_SETLOGLEVEL         _IOW (DEV_MAJOR,  2, unsigned int)
#define DSPHAL_CMD_GETNUMEPT           _IO  (DEV_MAJOR,  3)
#define DSPHAL_CMD_GETCHANCFG          _IOWR(DEV_MAJOR,  4, struct dsphal_chancfg)
#define DSPHAL_CMD_SETCLEARCHAN        _IOW (DEV_MAJOR,  5, struct dsphal_cmdenable)
#define DSPHAL_CMD_SETDSPRATE          _IOW (DEV_MAJOR,  6, unsigned int)
#define DSPHAL_CMD_WAITTICK            _IO  (DEV_MAJOR,  7)
#define DSPHAL_CMD_SETTICKENABLE       _IOW (DEV_MAJOR,  8, unsigned int)
#define DSPHAL_CMD_SETDECTSTACKSTATUS  _IOW (DEV_MAJOR,  9, unsigned int)
#define DSPHAL_CMD_SETVOICEIDLE        _IOW (DEV_MAJOR, 10, unsigned int)
#ifdef BRCM_VOICE_KERNEL_DSP
#define DSPHAL_CMD_BIND                _IO  (DEV_MAJOR,  11)
#define DSPHAL_CMD_UNBIND              _IO  (DEV_MAJOR,  12)
#endif
/* Channel type */
enum dh_type
{
   DSPHAL_TYPE_NONE,
   DSPHAL_TYPE_FXS,
   DSPHAL_TYPE_FXO,
   DSPHAL_TYPE_DECT
};

/* Channel sampling rate */
enum dh_sample_rate
{
   DSPHAL_RATE_8KHZ,
   DSPHAL_RATE_16KHZ,
};

/* Channel audio interface type */
enum dh_intf
{
   DSPHAL_INTF_PCM,
   DSPHAL_INTF_APM,
   DSPHAL_INTF_DECT,

   DSPHAL_INTF_MAX
};

struct dsphal_cmdenable
{
   unsigned int    id;
   unsigned int    enable;
} __attribute__((aligned(4),packed));

struct dsphal_chancfg
{
   unsigned int         id;
   int                  type;
   int                  interface;
   int                  rate;
   unsigned int         enabled;
} __attribute__((aligned(4),packed));

#endif /* _BCM_DSPHAL_H */
