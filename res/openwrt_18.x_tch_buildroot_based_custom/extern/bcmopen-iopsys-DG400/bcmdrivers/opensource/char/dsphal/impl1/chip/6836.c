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
#ifndef _CFE_
#include <linux/delay.h>
#endif

#include <dsphal_pcm.h>

#include <bcm_pinmux.h>

#ifdef BRCM_NTR_SUPPORT
typedef enum
{
    rdpa_wan_none,              /**< Not configured */
    rdpa_wan_gpon,              /**< GPON */
    rdpa_wan_xgpon,             /**< XGPON */
    rdpa_wan_epon,              /**< EPON */
    rdpa_wan_xepon,             /**< XEPON */
    rdpa_wan_xepon_ae,          /**< XEPON AE*/    
    rdpa_wan_gbe,               /**< GbE */
    rdpa_wan_dsl,               /**< xDSL */
    rdpa_wan_type__num_of
} rdpa_wan_type;

extern rdpa_wan_type rdpa_wan_type_get(void);
#endif /* BRCM_NTR_SUPPORT */

void pcm_cfg_dpll_div(void)
{
#ifdef BRCM_NTR_SUPPORT
   rdpa_wan_type wan_type = 0;

  *(unsigned int*)(WAN_BASE + 0x48) |= 0x40000000;
  *(unsigned int*)(WAN_BASE + 0x4C) &= ~( 0xf << 8);

   wan_type = rdpa_wan_type_get();
   /* Setup DPLL registers based on WAN type */
   switch (wan_type)
   {
     case rdpa_wan_gpon:
         /* Generate 39.81KHz ntr_sync_pulse clock */
         *(unsigned int*)(WAN_BASE + 0x4c) |= (14 << 8); 
         /* Local clk is generated via DPLL NCO @ 65.536Mhz
          * Ref clk from EPON Serdes is @ 40Khz
          * Phase comparator compares both clocks @ 8Khz
          * 8Khz = 65.536Mhz / (8191+1) = 40Khz / (4+1)
          * local_div = 8191, ref_div = 4 */
         DPLL->dpll_div = (4 << DPLL_REF_DIV_SHIFT) | 8191;
         DHLOG_INFO("%s: DPLL programmed for GPON refclk @ 39.81KHz\n",
                     __func__);
         break;

      case rdpa_wan_epon:
         /* Generate 40KHz ntr_sync_pulse clock */
         *(unsigned int*)(WAN_BASE + 0x4c) |= (14 << 8);
         /* Local clk is generated via DPLL NCO @ 65.536Mhz
          * Ref clk from EPON Serdes is @ 40KHz
          * Phase comparator compares both clocks @ 8Khz
          * 8Khz = 65.536Mhz / (8191+1) = 40Khz / (4+1)
          * local_div = 8191, ref_div = 4 */
         DPLL->dpll_div = (4 << DPLL_REF_DIV_SHIFT) | 8191;
         DHLOG_INFO("%s: DPLL programmed for EPON refclk @ 40Khz\n",
                     __func__);
         break;

      default:
         DHLOG_INFO("%s: Unknown WAN mode, using standalone\n",
                     __func__);
         break;
   }
#endif /* BRCM_NTR_SUPPORT */
}
