/*
<:copyright-BRCM:2013:DUAL/GPL:standard

   Copyright (c) 2013 Broadcom 
   All Rights Reserved

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation (the "GPL").

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.


A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.

:>
*/
#ifndef _CFE_
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#else
extern void msleep (unsigned int);
#endif

#include "pmc_drv.h"
#include "bcm_map_part.h"
#include "pmc_pcm.h"
#include "BPCM.h"

void pmc_pcm_power_up(void)
{
#if !defined(CONFIG_BCM96836)
   BPCM_PWR_ZONE_N_CONTROL bpcmPwrZoneControl;
   BPCM_SR_CONTROL sr_control;
#endif

#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
   /* This is needed to swap the endianness on the BUS */
   *(unsigned int*)PCM_BUS_BASE = 0x5;
   msleep(5);
#endif

#if !defined(CONFIG_BCM96836)
   /* Enable power only if it is currently down */
   ReadZoneRegister(PMB_ADDR_PCM, PCM_Zone_Main, BPCMZoneRegOffset(control), &bpcmPwrZoneControl.Reg32);

#if defined(CONFIG_BCM96858)
   {
#else
   if (!bpcmPwrZoneControl.Bits.pwr_on_state) {
#endif
      /* zone0 is not powered so the whole device is powered off */
      /* just power on the device */
      PowerOnDevice(PMB_ADDR_PCM);

      /* Assert PCM SoftResets via BPCM */
      ReadBPCMRegister(PMB_ADDR_PCM, BPCMRegOffset(sr_control), &sr_control.Reg32);
#if defined(CONFIG_BCM96858) && ( CONFIG_BCM_CHIP_REV != 0x6858B0 )
      sr_control.Bits.sr |= ( BPCM_PCM_SRESET_BUS_N );
      WriteBPCMRegister(PMB_ADDR_PCM, BPCMRegOffset(sr_control), sr_control.Reg32);

      /* Assert PCM SoftResets via BPCM */
      ReadBPCMRegister(PMB_ADDR_PCM, BPCMRegOffset(sr_control), &sr_control.Reg32);
#endif
      sr_control.Bits.sr |= ( BPCM_PCM_SRESET_PCM_N );
      WriteBPCMRegister(PMB_ADDR_PCM, BPCMRegOffset(sr_control), sr_control.Reg32);

      /* Sleep to ensure full soft reset */
      msleep(10);

      /* De-assert PCM SoftResets via BPCM */
      ReadBPCMRegister(PMB_ADDR_PCM, BPCMRegOffset(sr_control), &sr_control.Reg32);
      sr_control.Bits.sr &= ~( BPCM_PCM_SRESET_PCM_N );
      WriteBPCMRegister(PMB_ADDR_PCM, BPCMRegOffset(sr_control), sr_control.Reg32);

       /* Sleep to ensure full soft reset */
      msleep(10);
   }
#endif //!defined(CONFIG_BCM96836)  
}

void pmc_pcm_power_down(void)
{
#if !defined(CONFIG_BCM96836)
   BPCM_SR_CONTROL sr_control;

   /* Assert PCM SoftResets via BPCM */
   ReadBPCMRegister(PMB_ADDR_PCM, BPCMRegOffset(sr_control), &sr_control.Reg32);
   sr_control.Bits.sr |= ( BPCM_PCM_SRESET_PCM_N );
   WriteBPCMRegister(PMB_ADDR_PCM, BPCMRegOffset(sr_control), sr_control.Reg32);

   /* Sleep to ensure full soft reset */
   msleep(10);

   /* Power off PCM zone */
   PowerOffZone(PMB_ADDR_PCM, PCM_Zone_PCM  );
#if ( CONFIG_BCM_CHIP_REV != 0x6858B0 ) 
   PowerOffZone(PMB_ADDR_PCM, PCM_Zone_Main );
#endif
#endif
}

#ifndef _CFE_
EXPORT_SYMBOL(pmc_pcm_power_up);
EXPORT_SYMBOL(pmc_pcm_power_down);
#endif

