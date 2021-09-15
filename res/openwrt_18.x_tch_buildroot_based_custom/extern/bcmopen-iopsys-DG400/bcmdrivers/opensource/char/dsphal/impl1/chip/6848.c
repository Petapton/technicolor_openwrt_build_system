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

#include <linux/delay.h>

#include <dsphal_pcm.h>

#include <bcm_pinmux.h>

#ifdef BRCM_NTR_SUPPORT
#include <rdpa_api.h>
#endif /* BRCM_NTR_SUPPORT */

void pcm_pinmux()
{
   /* Add PinMux for PCM pins (TODO:Remove Magic Numbers) */
   bcm_set_pinmux( 0, PINMUX_PCM ); /* GPIO0 - PCM_SDIN */
   bcm_set_pinmux( 1, PINMUX_PCM ); /* GPIO1 - PCM_SDOUT */
   bcm_set_pinmux( 2, PINMUX_PCM ); /* GPIO2 - PCM_CLK */
   bcm_set_pinmux( 3, PINMUX_PCM ); /* GPIO3 - PCM_FS */
}

void pcm_cfg_dpll_div(void)
{
#ifdef BRCM_NTR_SUPPORT
   /* Setup DPLL registers based on WAN type */
   switch (rdpa_wan_type_get())
   {
      case rdpa_wan_gpon:
         /* Local clk is generated via DPLL NCO @ 65.536Mhz
          * Ref clk from GPON Serdes is @ 256Khz
          * Phase comparator compares both clocks @ 8Khz
          * 8Khz = 65.536Mhz / (8191+1) = 256Khz / (31+1)
          * local_div = 8191, ref_div = 31 */
         PCM->dpll_div = (31 << DPLL_REF_DIV_SHIFT) | 8191;
         DHLOG_INFO("%s: DPLL programmed for GPON refclk @ 256Khz\n",
                     __func__);
         break;

      case rdpa_wan_epon:
         /* Local clk is generated via DPLL NCO @ 65.536Mhz
          * Ref clk from EPON Serdes is @ 40Khz
          * Phase comparator compares both clocks @ 8Khz
          * 8Khz = 65.536Mhz / (8191+1) = 40Khz / (4+1)
          * local_div = 8191, ref_div = 4 */
         PCM->dpll_div = (4 << DPLL_REF_DIV_SHIFT) | 8191;
         DHLOG_INFO("%s: DPLL programmed for EPON refclk @ 40Khz\n",
                     __func__);
         break;

      default:
         DHLOG_INFO("%s: Unknown WAN mode, using standalone\n",
                     __func__);
         break;
   }
#endif
}
