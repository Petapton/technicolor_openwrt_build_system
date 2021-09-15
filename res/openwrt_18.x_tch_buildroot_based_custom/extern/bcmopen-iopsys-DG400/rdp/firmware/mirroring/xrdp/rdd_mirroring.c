/*
   Copyright (c) 2015 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2015:DUAL/GPL:standard
    
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

#include "rdd.h"
#include "rdd_common.h"
#include "rdd_mirroring.h"

void rdd_mirroring_set(rdd_mirroring_cfg_t *rdd_mirroring_cfg)
{
    int i;
    uint32_t RDD_TX_MIRRORING_CONFIGURATION_TM_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];
    uint32_t RDD_BBH_QUEUE_TM_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

    if (!rdd_mirroring_cfg->lan)
    {
        RDD_BTRACE("Configuring RDD WAN mirroring: rx_dst_queue = %d, tx_dst_queue = %d",
                   rdd_mirroring_cfg->rx_dst_queue, rdd_mirroring_cfg->tx_dst_queue);
    }
    else
    {
        RDD_BTRACE("Configuring RDD LAN mirroring: src_tx_bbh_id = %d, rx_dst_queue = %d, tx_dst_queue = %d\n, ",
                    rdd_mirroring_cfg->src_tx_bbh_id, rdd_mirroring_cfg->rx_dst_queue, 
                    rdd_mirroring_cfg->tx_dst_queue);
    }

    for (i = 0; i < GROUPED_EN_SEGMENTS_NUM; i++)
    {
            RDD_TX_MIRRORING_CONFIGURATION_TM_ADDRESS_ARR[i] = 
                (get_runner_idx(ds_tm_runner_image) == i ||  get_runner_idx(us_tm_runner_image) == i) ?
                RDD_TX_MIRRORING_CONFIGURATION_ADDRESS_ARR[i] : INVALID_TABLE_ADDRESS;
    }

    RDD_MIRRORING_DESCRIPTOR_DST_QUEUE_WRITE_G(rdd_mirroring_cfg->rx_dst_queue,
         RDD_RX_MIRRORING_CONFIGURATION_ADDRESS_ARR, 0);
    RDD_MIRRORING_DESCRIPTOR_DST_VPORT_WRITE_G(rdd_mirroring_cfg->rx_dst_vport,                                         
         RDD_RX_MIRRORING_CONFIGURATION_ADDRESS_ARR, 0);
    RDD_MIRRORING_DESCRIPTOR_DST_QUEUE_WRITE_G(rdd_mirroring_cfg->tx_dst_queue,                                         
         RDD_TX_MIRRORING_CONFIGURATION_TM_ADDRESS_ARR, 0);
    RDD_MIRRORING_DESCRIPTOR_DST_VPORT_WRITE_G(rdd_mirroring_cfg->tx_dst_vport,                                        
         RDD_TX_MIRRORING_CONFIGURATION_TM_ADDRESS_ARR, 0);
    
    if (rdd_mirroring_cfg->lan) 
    {
       for (i = 0; i < GROUPED_EN_SEGMENTS_NUM; i++)
        {
                RDD_BBH_QUEUE_TM_ADDRESS_ARR[i] = (get_runner_idx(ds_tm_runner_image) == i) ?
                        RDD_BBH_QUEUE_TABLE_ADDRESS_ARR[i] : INVALID_TABLE_ADDRESS;
        }
            /* For LAN Configure mirroring only for target BBH */
        RDD_BBH_QUEUE_DESCRIPTOR_MIRRORING_EN_WRITE_G(IS_MIRRORING_CFG(rdd_mirroring_cfg->tx_dst_queue),
            RDD_BBH_QUEUE_TM_ADDRESS_ARR, rdd_mirroring_cfg->src_tx_bbh_id);
    }
    else /* WAN mirroring */
    {
        RDD_MIRRORING_DESCRIPTOR_MIRROR_EN_WRITE_G(IS_MIRRORING_CFG(rdd_mirroring_cfg->tx_dst_queue), 
            RDD_TX_MIRRORING_CONFIGURATION_TM_ADDRESS_ARR, 0);

        for (i = 0; i < GROUPED_EN_SEGMENTS_NUM; i++)
        {
            RDD_BBH_QUEUE_TM_ADDRESS_ARR[i] = (get_runner_idx(us_tm_runner_image) == i) ?
                RDD_BBH_QUEUE_TABLE_ADDRESS_ARR[i] : INVALID_TABLE_ADDRESS;
        }
        for (i = 0; i < RDD_BBH_QUEUE_TABLE_SIZE; i++)
        {
            /* For WAN Configure mirroring only for all TCONTS/LLIDs */
            RDD_BBH_QUEUE_DESCRIPTOR_MIRRORING_EN_WRITE_G(IS_MIRRORING_CFG(rdd_mirroring_cfg->tx_dst_queue), 
                RDD_BBH_QUEUE_TM_ADDRESS_ARR ,i);
        }
    }
}

void rdd_mirroring_cfg_init(void)
{
    int i;

    RDD_MIRRORING_DESCRIPTOR_MIRROR_EN_WRITE_G(0, RDD_TX_MIRRORING_CONFIGURATION_ADDRESS_ARR, 0);
    RDD_MIRRORING_DESCRIPTOR_MIRROR_EN_WRITE_G(0, RDD_RX_MIRRORING_CONFIGURATION_ADDRESS_ARR, 0);
    for (i = 0; i < RDD_BBH_QUEUE_TABLE_SIZE; i++)
        RDD_BBH_QUEUE_DESCRIPTOR_MIRRORING_EN_WRITE_G(0, RDD_BBH_QUEUE_TABLE_ADDRESS_ARR, i); 
}
