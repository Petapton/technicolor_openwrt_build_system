/*
<:copyright-BRCM:2016:DUAL/GPL:standard

   Copyright (c) 2016 Broadcom 
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


#ifndef TRX_DESCR_GEN_H_INCLUDED
#define TRX_DESCR_GEN_H_INCLUDED

#include <linux/types.h>
#include <bdmf_system.h>
#include <bdmf_dev.h>
#include "detect.h"



typedef enum {
     TRX_SFF = 0x2,
     TRX_SFP = 0x3,
     TRX_XFP = 0x6,
     TRX_PMD = 0xff,
} TRX_FORM_FACTOR; 


typedef struct
{
    TRX_FORM_FACTOR form_factor;
    uint8_t  vendor_name[20];
    uint8_t  vendor_pn[20];
    TRX_SIG_ACTIVE_POLARITY    lbe_polarity;
    TRX_SIG_ACTIVE_POLARITY    tx_sd_polarity;
    TRX_SIG_ACTIVE_POLARITY    tx_pwr_down_polarity;
    bdmf_boolean               tx_pwr_down_cfg_req;
}  TRX_DESCRIPTOR;


/*
 * List of xPON and AE transcievers used by BRCM.
 * To extend/override this list put the entries to trx_usr[] array in ./trx_descr_usr.h
 */

static TRX_DESCRIPTOR trx_lst[] = {
  {
    .form_factor           = TRX_SFP,
    .vendor_name           = "SOURCEPHOTONICS",
    .vendor_pn             = "SPPS2748FN2CDFA",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_TRUE
  },
  {
    .form_factor           = TRX_XFP,
    .vendor_name           = "Hisense",
    .vendor_pn             = "LTW2601C-BC+",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
  {
    .form_factor           = TRX_XFP,
    .vendor_name           = "Hisense",
    .vendor_pn             = "LTW2601-BC",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
  {
    .form_factor           = TRX_SFP,
    .vendor_name           = "Ligent Photonics",
    .vendor_pn             = "LTF7219-BC",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
  {
    .form_factor           = TRX_SFP,
    .vendor_name           = "NEOPHOTONICS",
    .vendor_pn             = "PTNEN3-41CP-ST+",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
  {
    .form_factor           = TRX_SFF,              
    .vendor_name           = "DELTA",
    .vendor_pn             = "OPGP-34-A4B3SN",
    .lbe_polarity          = TRX_ACTIVE_HIGH,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
  {
    .form_factor           = TRX_XFP,
    .vendor_name           = "Ligent",
    .vendor_pn             = "LTW2601C-BC",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
  {
    .form_factor           = TRX_SFP,
    .vendor_name           = "Ligent Photonics",
    .vendor_pn             = "LTF7221-BH",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
  {
    .form_factor           = TRX_SFP,
    .vendor_name           = "Ligent Photonics",
    .vendor_pn             = "LTF7221-BC",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
  {
    .form_factor           = TRX_SFP,
    .vendor_name           = "Ligent Photonics",
    .vendor_pn             = "LTF7225-BC",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
  },
} ;



#endif /* TRX_DESCR_GEN_H_INCLUDED */
