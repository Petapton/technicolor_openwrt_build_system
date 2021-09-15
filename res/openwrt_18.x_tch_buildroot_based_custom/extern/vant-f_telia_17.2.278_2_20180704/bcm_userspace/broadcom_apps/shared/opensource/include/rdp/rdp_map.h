/*
   Copyright (c) 2013 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2013:DUAL/GPL:standard
    
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

#ifndef __RDP_MAP_H
#define __RDP_MAP_H

#if defined CONFIG_BCM96838
 #include "96838_rdp_map.h"
#elif defined CONFIG_BCM963138
#include "963138_rdp_map.h"
#elif defined CONFIG_BCM963148
#include "963148_rdp_map.h"
#else
 #error "did not included the rdp_map.h correctly!!!"
#endif

#endif /* __RDP_MAP_H */
