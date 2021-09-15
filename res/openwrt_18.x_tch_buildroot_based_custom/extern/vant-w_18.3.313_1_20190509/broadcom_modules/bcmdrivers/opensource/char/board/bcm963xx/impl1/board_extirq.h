/*
* <:copyright-BRCM:2016:DUAL/GPL:standard
* 
*    Copyright (c) 2016 Broadcom 
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
*/


#ifndef _BOARD_EXTIRQ_H_
#define _BOARD_EXIIRQ_H_

#include <bcm_intr.h>

#if defined(CONFIG_BCM96838) || defined(CONFIG_BCM963138) || defined(CONFIG_BCM963148)
#define NUM_EXT_INT    (INTERRUPT_ID_EXTERNAL_5-INTERRUPT_ID_EXTERNAL_0+1)
#elif defined(CONFIG_BCM963381) || defined(CONFIG_BCM96848)
#define NUM_EXT_INT    (INTERRUPT_ID_EXTERNAL_7-INTERRUPT_ID_EXTERNAL_0+1)
#elif defined(CONFIG_BCM94908) ||  (CONFIG_BCM_CHIP_REV==0x6858A0)
#define NUM_EXT_INT    (INTERRUPT_PER_EXT_5-INTERRUPT_PER_EXT_0+1)
#elif defined(CONFIG_BCM963158) || defined(CONFIG_BCM96836)
#define NUM_EXT_INT    (INTERRUPT_PER_EXT_7-INTERRUPT_PER_EXT_0+1)
#elif (defined(CONFIG_BCM96858) && (CONFIG_BCM_CHIP_REV != 0x6858A0))
#define NUM_EXT_INT    8  
#elif defined(CONFIG_BCM947189)
#define NUM_EXT_INT    0
#else
#define NUM_EXT_INT    (INTERRUPT_ID_EXTERNAL_3-INTERRUPT_ID_EXTERNAL_0+1)
#endif

extern unsigned int extIntrInfo[NUM_EXT_INT];

int map_external_irq (int irq);
void init_ext_irq_info(void);
void init_reset_irq(void);
void board_extirq_init(void);
#if defined(CONFIG_BCM960333)
void mapBcm960333GpioToIntr( unsigned int gpio, unsigned int extIrq );
#endif
#endif
