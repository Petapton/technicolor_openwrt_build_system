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
 ***************************************************************************/

#include <dsphal.h>

#include <linux/delay.h>

#include <dsphal_dect.h>

#include <pmc/pmc_drv.h>
#include <pmc/BPCM.h>

/****************************************************************************
* Typedefs and Constants
****************************************************************************/
#define PLL_RESETB            0x80000000
#define PLL_P_RESETB          0x40000000
#define PLL_PWRON             0x08000000
#define PLL_PWRDWN_CH1        0x04000000
#define PLL_PWRDWN_CH2        0x02000000
#define PLL_PWRDWN_CH3        0x01000000

#define XTAL_CTL_WORD         0x80B27003

/* Maximum number of 1ms iterations to wait for DPLL lock */
#define DPLL_LOCK_MAX_WAIT    100
#define DPLL_LOCK_RETRY_CNT   2

/****************************************************************************
* Local function declaration
****************************************************************************/
static void dect_pll_cfg(void);
static void dect_dpll_wait_lock(void);


/****************************************************************************
* Functions
****************************************************************************/

/*****************************************************************************
*  FUNCTION:   dect_power_up
*
*  PURPOSE:    Handle powering up of the dect block
*
*  PARAMETERS: none
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int dect_power_up(void)
{
   BPCM_PWR_ZONE_N_CONTROL pwr_zone_ctrl;

   /* RESET DECT via BPCM ( Block Power Control Module ) */
   ReadBPCMRegister(PMB_ADDR_DECT_UBUS, BPCMRegOffset(zones[0].control),
                    &pwr_zone_ctrl.Reg32);
   pwr_zone_ctrl.Bits.pwr_dn_req = 0;
   pwr_zone_ctrl.Bits.dpg_ctl_en = 1;
   pwr_zone_ctrl.Bits.pwr_up_req = 1;
   pwr_zone_ctrl.Bits.mem_pwr_ctl_en = 1;
   pwr_zone_ctrl.Bits.blk_reset_assert = 1;
   WriteBPCMRegister(PMB_ADDR_DECT_UBUS, BPCMRegOffset(zones[0].control),
                     pwr_zone_ctrl.Reg32);
   mdelay(1);

   return 0;
}


/*****************************************************************************
*  FUNCTION:   dect_power_down
*
*  PURPOSE:    Handle powering down of the dect block
*
*  PARAMETERS: none
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int dect_power_down(void)
{
   BPCM_PWR_ZONE_N_CONTROL pwr_zone_ctrl;

   /* RESET DECT via BPCM ( Block Power Control Module ) */
   ReadBPCMRegister(PMB_ADDR_DECT_UBUS, BPCMRegOffset(zones[0].control),
                    &pwr_zone_ctrl.Reg32);
   pwr_zone_ctrl.Bits.pwr_dn_req = 1;
   pwr_zone_ctrl.Bits.dpg_ctl_en = 1;
   pwr_zone_ctrl.Bits.pwr_up_req = 0;
   WriteBPCMRegister(PMB_ADDR_DECT_UBUS, BPCMRegOffset(zones[0].control),
                     pwr_zone_ctrl.Reg32);

   return 0;
}


/*****************************************************************************
*  FUNCTION:   dect_clk_init
*
*  PURPOSE:    Configure the dect clock
*
*  PARAMETERS: none
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int dect_clk_init(void)
{
   DHLOG_INFO("%s: starting DECT clock\n", __func__);

   DECT_CTRL->dect_shm_ctrl &= ~AHB_SWAP_MASK;
   DECT_CTRL->dect_shm_ctrl |= AHB_SWAP_ACCESS;
   DECT_CTRL->dect_shm_ctrl |= UBUS3_SWAP;
   DECT_CTRL->dect_shim_dcxo_ctrl0 = XTAL_CTL_WORD;

   /* Turn on the PLL */
   DECT_CTRL->dect_shm_pll_reg_1 |= PLL_PWRON;
   dect_pll_cfg();

   return 0;
}


/*****************************************************************************
*  FUNCTION:   dect_clk_deinit
*
*  PURPOSE:    Disables the dect clock
*
*  PARAMETERS: none
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int dect_clk_deinit(void)
{
   /* Disable the PLL */
   DECT_CTRL->dect_shm_pll_reg_1 &= ~PLL_PWRON;

   return 0;
}


/*****************************************************************************
*  FUNCTION:   dect_pll_cfg
*
*  PURPOSE:    Configure and start the DECT DPLL
*
*  PARAMETERS: none
*
*  RETURNS:    none
*
*****************************************************************************/
static void dect_pll_cfg(void)
{
   mdelay( 1 ); 
   DECT_CTRL->dect_shm_pll_reg_1 |= PLL_RESETB;

   dect_dpll_wait_lock();

   /* Bring digital portion out of reset */
   DECT_CTRL->dect_shm_pll_reg_1 |= PLL_P_RESETB;
   DECT_CTRL->dect_shm_pll_reg_1 &= ~(PLL_PWRDWN_CH1 | PLL_PWRDWN_CH2 | PLL_PWRDWN_CH3);

   mdelay(1);

   DECT_CTRL->dect_shm_ctrl |= DECT_PLL_REF_DECT
                             | DECT_CLK_CORE_DECT
                             | DECT_CLK_OUT_XTAL
                             | PHCNT_CLK_SRC_PLL
                             | PCM_PULSE_COUNT_ENABLE
                             | DECT_PULSE_COUNT_ENABLE;

   DECT_CTRL->dect_shm_ctrl &= ~DECT_CLK_OUT_PLL;

   /* Route undivided  dectclk of 10.368Mhz to PCM DPLL */
   DECT_CTRL->dect_shim_pcm_ctrl = 0;
}


/*****************************************************************************
*  FUNCTION:   dect_dpll_wait_lock
*
*  PURPOSE:    Wait for the DPLL to lock, if configured
*
*  PARAMETERS: none
*
*  RETURNS:    none
*
*****************************************************************************/
static void dect_dpll_wait_lock(void)
{
#ifdef BRCM_VOICE_DPLL_LOCK_WAIT
   volatile unsigned int temp = 0;
   unsigned int i = 0, retry = 0;

   /* Wait for the DPLL_IN_SYNC and DPLL_ACQ_FREQ_VALID bits to be set */
   temp = DECT_CTRL->dect_shm_irq_status;
   while( 1 )
   {
      temp = DECT_CTRL->dect_shm_irq_status;
      i++;

      if( temp & (1 << DECT_SHM_IRQ_PLL_PHASE_LOCK) )
      {
         DHLOG_DEBUG("%s: DPLL locked, iteration = %u, dect_shm_irq_status = "
                     "0x%08x\n", __func__, i, temp);
         return;
      }
      else if( i == DPLL_LOCK_MAX_WAIT )
      {
         DHLOG_ERR("%s: DPLL failed to lock, dect_shm_irq_status = 0x%08x\n",
                   __func__, temp);
         retry++;
         i = 0;
         if(retry >= DPLL_LOCK_RETRY_CNT)
            break;
      }
      msleep(1);
   }
#else
   DHLOG_DEBUG("%s: DPLL lock wait skipped, dect_shm_irq_status = 0x%08x",
               __func__, (unsigned int)DECT_CTRL->dect_shm_irq_status);
#endif
}
