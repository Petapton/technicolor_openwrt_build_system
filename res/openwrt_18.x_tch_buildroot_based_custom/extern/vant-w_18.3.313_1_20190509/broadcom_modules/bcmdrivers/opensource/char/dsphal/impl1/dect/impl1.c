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


/****************************************************************************
* Typedefs and Constants
****************************************************************************/
#define PLL_VCO_RNG             0x00000040
#define PLL_DECT_PWRDWN         0x01000000
#define PLL_REFCOMP_PWRDOWN     0x02000000
#define PLL_NDIV_PWRDOWN        0x04000000
#define PLL_CH1_PWRDOWN         0x08000000
#define PLL_CH2_PWRDOWN         0x10000000
#define PLL_CH3_PWRDOWN         0x20000000
#define PLL_DRESET              0x40000000
#define PLL_ARESET              0x80000000

#define XTAL_CTL_WORD           0x7F400E3E
#define PLL_REG_0_WORD          0x210064C0
#define PLL_REG_2_WORD          0x60000000
#define PLL_REG_3_WORD          0x11181808

/* Maximum number of 1ms iterations to wait for DPLL lock */
#define DPLL_LOCK_MAX_WAIT      100
#define DPLL_LOCK_RETRY_CNT     2

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
#if defined(CONFIG_BCM963268)
   PERF->softResetB |= SOFT_RST_DECT;
#endif /* CONFIG_BCM9631268 */
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
   PERF->blkEnables &= ~DECT_CLKEN;
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

   /* Enable master clock to the DECT block */
   PERF->blkEnables |= DECT_CLKEN;

   DECT_CTRL->dect_shm_ctrl &= ~AHB_SWAP_MASK;
   DECT_CTRL->dect_shm_ctrl |= AHB_SWAP_ACCESS;

   DECT_CTRL->dect_shim_dcxo_ctrl0 = XTAL_CTL_WORD;

   /* Turn on the PLL */
   DECT_CTRL->dect_shm_pll_reg_1 &= ~( PLL_DECT_PWRDWN
                                     | PLL_REFCOMP_PWRDOWN
                                     | PLL_NDIV_PWRDOWN
                                     | PLL_CH1_PWRDOWN
                                     | PLL_CH2_PWRDOWN
                                     | PLL_CH3_PWRDOWN );

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
   DECT_CTRL->dect_shm_pll_reg_1 |= PLL_DECT_PWRDWN
                                  | PLL_REFCOMP_PWRDOWN
                                  | PLL_NDIV_PWRDOWN
                                  | PLL_CH1_PWRDOWN
                                  | PLL_CH2_PWRDOWN
                                  | PLL_CH3_PWRDOWN
                                  | PLL_ARESET
                                  | PLL_DRESET;
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
   DECT_CTRL->dect_shm_pll_reg_0  = PLL_REG_0_WORD;
   DECT_CTRL->dect_shm_pll_reg_1 &= ~PLL_VCO_RNG;
   DECT_CTRL->dect_shm_pll_reg_2  = PLL_REG_2_WORD;
   DECT_CTRL->dect_shm_pll_reg_3  = PLL_REG_3_WORD;

   /* Bring analog portion out of reset */
   DECT_CTRL->dect_shm_pll_reg_1 &= ~PLL_ARESET;

   dect_dpll_wait_lock();

   /* Bring digital portion out of reset */
   DECT_CTRL->dect_shm_pll_reg_1 &= ~PLL_DRESET;

   DECT_CTRL->dect_shm_ctrl |= DECT_PLL_REF_DECT
                             | DECT_CLK_CORE_DECT
                             | DECT_CLK_OUT_XTAL
                             | PHCNT_CLK_SRC_PLL
                             | PCM_PULSE_COUNT_ENABLE
                             | DECT_PULSE_COUNT_ENABLE;

   DECT_CTRL->dect_shm_ctrl &= ~DECT_CLK_OUT_PLL;
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
