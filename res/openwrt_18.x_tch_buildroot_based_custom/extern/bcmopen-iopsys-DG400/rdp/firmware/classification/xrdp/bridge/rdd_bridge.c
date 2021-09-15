/*
   Copyright (c) 2013 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2013:DUAL/GPL:standard
    
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
#include "rdd_bridge.h"
#include "rdd_ag_bridge.h"



/******************************************************************************/
/*                                                                            */
/*                            F/W tables configuration helpers                */
/*                                                                            */
/******************************************************************************/


/* module init */
static void _rdd_bridge_fw_module_init(const rdd_module_t *module)
{
    const rdd_bridge_module_param_t *params = module->params;   

    /* Module init. Set up module configuration */
    RDD_BRIDGE_CFG_RES_OFFSET_WRITE_G(module->res_offset, module->cfg_ptr, params->module_id);
}

/* Module params init*/
static void _rdd_bridge_fw_module_params_init(const rdd_module_t *module)
{
    const rdd_bridge_module_param_t *params = module->params;   

    /* Module init. Set up module params configuration */
    RDD_BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_WRITE_G(params->bridge_lkps_ready, module->cfg_ptr, params->module_id);
    RDD_BRIDGE_CFG_BRIDGE_AGGREGATION_EN_WRITE_G(params->aggregation_en, module->cfg_ptr, params->module_id);
    RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_WRITE_G(
       params->bridge_and_vlan_lookup_fail_action != BRIDGE_AND_VLAN_LKP_MISS_ACTION_FORWARD,
       module->cfg_ptr,
       params->module_id);
    RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_WRITE_G(
       params->bridge_and_vlan_lookup_fail_action == BRIDGE_AND_VLAN_LKP_MISS_ACTION_DROP,
       module->cfg_ptr,
       params->module_id);
    RDD_BRIDGE_CFG_VLAN_AGGREGATION_WRITE_G(
       params->bridge_module_actions.vlan_aggregation_action,
       module->cfg_ptr,
       params->module_id);
    RDD_BRIDGE_CFG_BRIDGE_FW_FAILED_WRITE_G(
       params->bridge_module_actions.bridge_fw_failed_action,
       module->cfg_ptr,
       params->module_id);
    RDD_BRIDGE_CFG_HIT_WRITE_G(
       params->bridge_module_actions.hit,
       module->cfg_ptr,
       params->module_id);                       
}

/******************************************************************************/
/*                                                                            */
/*                            External interface                              */
/*                                                                            */
/******************************************************************************/

/****************************************************************************************
 * module->init callback
 *****************************************************************************************/
int rdd_bridge_module_init(const rdd_module_t *module)
{
    _rdd_bridge_fw_module_init(module);
    _rdd_bridge_fw_module_params_init(module);
    return BDMF_ERR_OK;
}

void rdd_bridge_ports_init(void)
{
   int idx;

   for (idx = 0; idx < RDD_VPORT_CFG_TABLE_SIZE; idx++)
   {
      RDD_VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_WRITE_G(ACTION_TRAP, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, idx);
      RDD_VPORT_CFG_ENTRY_SA_LOOKUP_EN_WRITE_G(1, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, idx);
      RDD_VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_WRITE_G(ACTION_TRAP, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, idx);
      RDD_VPORT_CFG_ENTRY_DA_LOOKUP_EN_WRITE_G(1, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, idx);
      RDD_VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_WRITE_G(0, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, idx);
      RDD_VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_WRITE_G(0, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, idx);
      RDD_VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_WRITE_G(0, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, idx);
      RDD_VPORT_CFG_ENTRY_LS_FC_CFG_WRITE_G(0, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, idx);
   }
}


/********************************************************************
 * RDD integration
 ********************************************************************/

/***************************************************************************
 * Low-overhead FDB access functions
 * ToDo: implement
 **************************************************************************/

rdpa_forward_action rdd_action2rdpa_forward_action(rdd_action_t rdd_action)
{
    rdpa_forward_action fa = rdpa_forward_action_host;

    switch (rdd_action)
    {
    case ACTION_FORWARD:
        fa = rdpa_forward_action_forward;
        break;

    case ACTION_DROP:
        fa = rdpa_forward_action_drop;
        break;

    case ACTION_MULTICAST:
       fa = rdpa_forward_action_flood;
       break;

    default:
        break;
    }
    return fa;
}

rdd_action_t rdpa_forward_action2rdd_action(rdpa_forward_action fa)
{
    rdd_action ra;

    switch (fa)
    {
    case rdpa_forward_action_forward:
        ra = ACTION_FORWARD;
        break;

    case rdpa_forward_action_drop:
        ra = ACTION_DROP;
        break;

    case rdpa_forward_action_flood:
       ra = ACTION_MULTICAST;
       break;

    case rdpa_forward_action_host:
    default:
        ra = ACTION_TRAP;
        break;
    }
    return ra;
}

void rdd_bridge_bridge_and_vlan_ctx_hash_ctx_compose(
   rdd_vport_vector_t vport_vector, 
   RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS *bridge_and_vlan_lkp_result, 
   uint8_t *int_ctx, 
   uint8_t *ext_ctx)
{

   bridge_and_vlan_lkp_result->port_isolation_map_23_0 = (uint32_t)(vport_vector & 0xFFFFFF);
   bridge_and_vlan_lkp_result->port_isolation_map_31_24 = (uint32_t)((vport_vector >> 24) & 0xFF);

   RDD_BTRACE("Composing hash context to bridge id resolution: "
       "port_isolation_map_23_0 = %d, port_isolation_map_31_24 = %d, wan_vid = %d\n",
       bridge_and_vlan_lkp_result->port_isolation_map_23_0, bridge_and_vlan_lkp_result->port_isolation_map_31_24, 
       bridge_and_vlan_lkp_result->wan_vid);

   int_ctx[0] = bridge_and_vlan_lkp_result->port_isolation_map_23_0 & 0xFF;
   int_ctx[1] = (bridge_and_vlan_lkp_result->port_isolation_map_23_0 >> 8) & 0xFF;
   int_ctx[2] = (bridge_and_vlan_lkp_result->port_isolation_map_23_0 >> 16) & 0xFF;

   ext_ctx[0] = bridge_and_vlan_lkp_result->port_isolation_map_31_24;
   ext_ctx[1] = bridge_and_vlan_lkp_result->wan_vid & 0xFF;
   ext_ctx[2] = (bridge_and_vlan_lkp_result->wan_vid >> 8) | 
       (bridge_and_vlan_lkp_result->aggregation_en << BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_F_OFFSET_MOD8) |
       (bridge_and_vlan_lkp_result->arl_lookup_method << BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_F_OFFSET_MOD8);
   

   return;
}

void rdd_bridge_bridge_and_vlan_hash_ctx_decompose(
   rdd_vport_vector_t *vport_vector, 
   RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS *bridge_and_vlan_lkp_result, 
   const uint8_t *int_ctx, 
   const uint8_t *ext_ctx)
{
   RDD_BTRACE("decomposing hash context to bridge id lkp result: "
       "int_ctx: [0] = %d, [1] = %d, [2] = %d"
       "ext_ctx: [0] = %d, [1] = %d, [2] = %d\n"
       ,int_ctx[0], int_ctx[1], int_ctx[2], ext_ctx[0], ext_ctx[1], ext_ctx[2]);

    memcpy(bridge_and_vlan_lkp_result, ext_ctx, 3);
    bridge_and_vlan_lkp_result->port_isolation_map_23_0 = 
        int_ctx[0] | (int_ctx[1] << 8) | (int_ctx[2] << 16);
    bridge_and_vlan_lkp_result->port_isolation_map_31_24 = ext_ctx[2] >> 24 & 0xFF;
    *vport_vector = bridge_and_vlan_lkp_result->port_isolation_map_23_0 | 
        (bridge_and_vlan_lkp_result->port_isolation_map_31_24 << 24);
    return;
}

void map_rdd_arl_data_to_ext_ctx(RDD_BRIDGE_ARL_LKP_RESULT_DTS *rdd_arl_data, 
   uint8_t* ext_ctx)
{
    RDD_BTRACE("Mapping rdd arl data to external hash context: "
        "lan_vid_8msb = %d, lan_vid_lsb_and_da_no_fwd_action = %d"
        " vport = %d",
       rdd_arl_data->lan_vid_8lsb, rdd_arl_data->lan_vid_msb_and_da_no_fwd_action, rdd_arl_data->vport);

    memset(ext_ctx, 0, 3);
    ext_ctx[0] = rdd_arl_data->lan_vid_8lsb;
    ext_ctx[1] = rdd_arl_data->lan_vid_msb_and_da_no_fwd_action
       | (rdd_arl_data->da_match_action_fwd << BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_F_OFFSET);
    ext_ctx[2] = rdd_arl_data->vport 
       | (rdd_arl_data->sa_match_action << BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_F_OFFSET_MOD8);
}

void map_ext_ctx_to_rdd_arl_data(uint8_t* ext_ctx, RDD_BRIDGE_ARL_LKP_RESULT_DTS *rdd_arl_data)
{
   RDD_BTRACE("Mapping hash external context to rdd arl data: [0] = %d, [1] = %d, [2] = %d\n", 
       ext_ctx[0], ext_ctx[1], ext_ctx[2]);
   rdd_arl_data->lan_vid_8lsb = ext_ctx[2];
   rdd_arl_data->da_match_action_fwd = (ext_ctx[1] >> BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_F_OFFSET) & 0x1;
   if (rdd_arl_data->da_match_action_fwd) /* lan_vid*/
      rdd_arl_data->lan_vid_msb_and_da_no_fwd_action = ext_ctx[1] & 0xF;
   else /* match action drop/trap*/
      rdd_arl_data->lan_vid_msb_and_da_no_fwd_action = ext_ctx[1] & 0x1;
   rdd_arl_data->vport = ext_ctx[0] & 0x3F;
   rdd_arl_data->sa_match_action = (ext_ctx[0] >> BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_F_OFFSET_MOD8) & 0x3;
}

