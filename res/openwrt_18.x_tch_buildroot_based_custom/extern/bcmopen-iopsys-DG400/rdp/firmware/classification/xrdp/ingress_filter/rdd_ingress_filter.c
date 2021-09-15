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

#include "rdd_ingress_filter.h"
#include "rdp_drv_proj_cntr.h"

int rdd_ingress_filter_module_init(const rdd_module_t *module)
{
    uint8_t ix, l2_filter_reasons[INGRESS_FILTER_L2_REASON_TABLE_SIZE] = { };

    /* init L2 filter reasons */
    l2_filter_reasons[INGRESS_FILTER_ETYPE_PPPOE_D] = CPU_RX_REASON_ETYPE_PPPOE_D;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_PPPOE_S] = CPU_RX_REASON_ETYPE_PPPOE_S;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_UDEF_0] = CPU_RX_REASON_ETYPE_UDEF_0;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_UDEF_1] = CPU_RX_REASON_ETYPE_UDEF_1;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_UDEF_2] = CPU_RX_REASON_ETYPE_UDEF_2;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_UDEF_3] = CPU_RX_REASON_ETYPE_UDEF_3;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_ARP] = CPU_RX_REASON_ETYPE_ARP;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_802_1X] = CPU_RX_REASON_ETYPE_802_1X;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_802_1AG_CFM] = CPU_RX_REASON_ETYPE_801_1AG_CFM;
    l2_filter_reasons[INGRESS_FILTER_ETYPE_PTP_1588] = CPU_RX_REASON__1588;

    /* init res_offset in cfg... */
    RDD_INGRESS_FILTER_CFG_RES_OFFSET_WRITE_G((uint16_t)module->res_offset, RDD_INGRESS_FILTER_CFG_ADDRESS_ARR, 0);

    /* init profiles table */
    for (ix = 0; ix < RDD_INGRESS_FILTER_PROFILE_TABLE_SIZE; ix++)
    {
        RDD_INGRESS_FILTER_CTRL_ENABLE_VECTOR_WRITE_G(0, RDD_INGRESS_FILTER_PROFILE_TABLE_ADDRESS_ARR, ix);
        RDD_INGRESS_FILTER_CTRL_ACTION_VECTOR_WRITE_G(0, RDD_INGRESS_FILTER_PROFILE_TABLE_ADDRESS_ARR, ix);
    }

    for (ix = 0; ix < INGRESS_FILTER_L2_REASON_TABLE_SIZE; ix++)
        RDD_BYTE_1_BITS_WRITE_G(l2_filter_reasons[ix], RDD_INGRESS_FILTER_L2_REASON_TABLE_ADDRESS_ARR, ix);

    for (ix = 0; ix < RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_SIZE; ix++)
        RDD_BYTE_1_BITS_WRITE_G(0xff, RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_ADDRESS_ARR, ix); /* XXX: Use define */

    return 0;
}

void rdd_ingress_filter_vport_to_profile_set(uint8_t vport, uint8_t profile)
{
    RDD_BYTE_1_BITS_WRITE_G(profile, RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_ADDRESS_ARR, vport);
}

void rdd_ingress_filter_profile_cfg(uint8_t profile, uint32_t filter_mask, uint32_t action_mask)
{
    RDD_INGRESS_FILTER_CTRL_ENABLE_VECTOR_WRITE_G(filter_mask, RDD_INGRESS_FILTER_PROFILE_TABLE_ADDRESS_ARR, profile);
    RDD_INGRESS_FILTER_CTRL_ACTION_VECTOR_WRITE_G(action_mask, RDD_INGRESS_FILTER_PROFILE_TABLE_ADDRESS_ARR, profile);
}

void rdd_ingress_filter_1588_cfg(int enable)
{
    RDD_BYTE_1_BITS_WRITE_G(enable, RDD_INGRESS_FILTER_1588_CFG_ADDRESS_ARR, 0);
}

int rdd_ingress_filter_drop_counter_get(uint8_t filter, rdpa_traffic_dir dir, uint16_t *drop_counter)
{
    int counter_idx;

    if (dir == rdpa_dir_ds)
        counter_idx = filter + COUNTER_INGRESS_FILTER_DROP_FIRST_DS;
    else
        counter_idx = filter + COUNTER_INGRESS_FILTER_DROP_FIRST_US;

    return drv_cntr_varios_counter_get(counter_idx, drop_counter);
}

