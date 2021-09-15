/*
    <:copyright-BRCM:2015:DUAL/GPL:standard
    
       Copyright (c) 2015 Broadcom 
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

#ifndef _RDD_MIRRORING_H
#define _RDD_MIRRORING_H

#include "rdd.h"
#include "rdd_common.h"
#include "rdpa_types.h"
#include "rdp_platform.h"

#ifndef G9991
#define RDD_MIRRORING_GET_TM_LAN_TASK(lan_port) (IMAGE_0_DS_TM_LAN0_THREAD_NUMBER + lan_port)
#endif /* G9991 */
#define IS_MIRRORING_CFG(qm_queue) (qm_queue <= QM_QUEUE_LAST + 1) 
typedef struct
{
    bbh_id_e src_tx_bbh_id;
    bdmf_boolean lan;
    uint16_t rx_dst_queue;
    uint16_t tx_dst_queue;
    rdd_vport_id_t  rx_dst_vport;
    rdd_vport_id_t  tx_dst_vport;
} rdd_mirroring_cfg_t;

/* API to RDPA level */
void rdd_mirroring_set(rdd_mirroring_cfg_t *rdd_mirroring_cfg);

/* Init Function */
void rdd_mirroring_cfg_init(void);

#endif
