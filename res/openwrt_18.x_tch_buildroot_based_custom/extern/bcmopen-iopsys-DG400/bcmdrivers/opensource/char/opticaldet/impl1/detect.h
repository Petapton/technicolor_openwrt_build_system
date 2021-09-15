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

#ifndef DETECT_H_INCLUDED
#define DETECT_H_INCLUDED

typedef enum {
    TRX_ACTIVE_LOW,
    TRX_ACTIVE_HIGH
} TRX_SIG_ACTIVE_POLARITY;

#define EPON2G (1 << 31)
#define RDPA_WAN_MASK 0xF

#define DEV_MAJOR 3020
#define DEV_CLASS "opticaldetect"

#define OPTICALDET_IOCTL_DETECT 1
#define OPTICALDET_IOCTL_SD 2

int opticaldetect(void);
int signalDetect(void);
int trx_get_lbe_polarity(TRX_SIG_ACTIVE_POLARITY *lbe_polarity_p);
int trx_get_tx_sd_polarity(TRX_SIG_ACTIVE_POLARITY *tx_sd_polarity_p);
int trx_get_vendor_name_part_num(char *vendor_name_p, int vendor_name_len,
                                 char *part_num_p, int part_num_len);

#endif /* DETECT_H_INCLUDED */
