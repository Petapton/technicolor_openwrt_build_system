/*
   Copyright (c) 2015 Broadcom
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



/* This is an automated file. Do not edit its contents. */


#include "rdd_ag_bridge.h"

int rdd_ag_bridge_default_bridge_cfg_set(bdmf_boolean aggregation_en, bdmf_boolean arl_lookup_method, uint16_t wan_vid, uint8_t port_isolation_map_31_24, uint32_t port_isolation_map_23_0)
{
    if(wan_vid >= 4096 || port_isolation_map_23_0 >= 16777216)
          return BDMF_ERR_PARM;

    RDD_BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_WRITE_G(aggregation_en, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_WRITE_G(arl_lookup_method, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_WRITE_G(wan_vid, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_WRITE_G(port_isolation_map_31_24, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_WRITE_G(port_isolation_map_23_0, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_bridge_default_bridge_cfg_get(bdmf_boolean *aggregation_en, bdmf_boolean *arl_lookup_method, uint16_t *wan_vid, uint8_t *port_isolation_map_31_24, uint32_t *port_isolation_map_23_0)
{
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_READ_G(*aggregation_en, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_READ_G(*arl_lookup_method, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_READ_G(*wan_vid, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_READ_G(*port_isolation_map_31_24, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_READ_G(*port_isolation_map_23_0, RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR, 0);

    return BDMF_ERR_OK;
}

int rdd_ag_bridge_bridge_cfg_table_bridge_aggregation_en_set(uint32_t _entry, bdmf_boolean bridge_aggregation_en)
{
    if(_entry >= RDD_BRIDGE_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_BRIDGE_CFG_BRIDGE_AGGREGATION_EN_WRITE_G(bridge_aggregation_en, RDD_BRIDGE_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_bridge_bridge_cfg_table_bridge_aggregation_en_get(uint32_t _entry, bdmf_boolean *bridge_aggregation_en)
{
    if(_entry >= RDD_BRIDGE_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_BRIDGE_CFG_BRIDGE_AGGREGATION_EN_READ_G(*bridge_aggregation_en, RDD_BRIDGE_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

