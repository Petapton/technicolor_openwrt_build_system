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

#ifndef _RDD_BRIDGE_H
#define _RDD_BRIDGE_H

#include "rdd_data_structures_auto.h"

typedef rdd_bridge_flow  rdd_bridge_module;
typedef rdd_action rdd_action_t;


typedef struct rdd_bridge_default_actions
{
    bdmf_boolean vlan_aggregation_action;                           
    bdmf_boolean bridge_fw_failed_action;
    bdmf_boolean hit;                        
} rdd_bridge_default_actions_t;

/** Bridge table parameters */
typedef struct rdd_bridge_module_param
{
    rdd_bridge_default_actions_t bridge_module_actions;             /* Default actions for module flow*/
    bdmf_boolean bridge_lkps_ready;                                 /* TRUE = bridge_id & da lookup results are expected to be valid in module  */
    bdmf_boolean aggregation_en;                                    /* TRUE = aggergation is enabled for bridge */
    rdd_bridge_and_vlan_lkp_miss_action bridge_and_vlan_lookup_fail_action;     /* Action taken upon bridge_id lookup failure */  
    rdd_bridge_module module_id;                                    /* FW module id */
    
} rdd_bridge_module_param_t;


/*****************************************************************************************
 * This module is responsible for bridge functionality: 
 * 1) Ingress isolation 
 * 2) SA/DA lookup 
 * 3) forwarding decision
 * 4) Vlan aggregation
 * 5) Egress isolation 
 *****************************************************************************************/


/****************************************************************************************
 * Initialize tcam_ic module instance
 * \param[in]   module          Module to be initialized
 * \returns: 0 if succesful
 *****************************************************************************************/
int rdd_bridge_module_init(const rdd_module_t *module);

/****************************************************************************************
* Transforms rdd_action to rdpa_forward_action
*
* \param[in]        rdd_action  forward action @ FW level
* \param[out]       rdpa_forward_action  forward action @ RDPA level
 *****************************************************************************************/
rdpa_forward_action rdd_action2rdpa_forward_action(rdd_action_t rdd_action);

/****************************************************************************************
* Transforms rdd_action to rdpa_forward_action
*
* \param[in]        rdpa_forward_action  forward action @ RDPA level
* \param[out]       rdd_action  forward action @ FW level
 *****************************************************************************************/
rdd_action_t rdpa_forward_action2rdd_action(rdpa_forward_action fa);

/****************************************************************************************
* Updates bridge_id clasiifcation result with vport_vector and creates
* internal and external hash contexts
*
* \param[in]        vport_vector  egress isolation vport vector
* \param[in/out]    bridge_id_lkp_result  
* \param[out]       int_ctx[3]    hash internal context
* \param[out]       ext_ctx[3]    hash external context
 *****************************************************************************************/
void rdd_bridge_bridge_and_vlan_ctx_hash_ctx_compose(rdd_vport_vector_t vport_vector, 
    RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS *bridge_id_lkp_result, uint8_t *int_ctx, uint8_t *ext_ctx);

/****************************************************************************************
* Updates bridge_id classifcation result with vport_vector and creates
* internal and external hash contexts
*
* \param[out]       vport_vector  egress isolation vport vector
* \param[in/out]    bridge_id_lkp_result  
* \param[in]        int_ctx[3]    hash internal context
* \param[oin]       ext_ctx[3]    hash external context
 *****************************************************************************************/
void rdd_bridge_bridge_id_hash_ctx_decompose(
   rdd_vport_vector_t *vport_vector, 
   RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS *bridge_id_lkp_result, 
   const uint8_t *int_ctx, 
   const uint8_t *ext_ctx);

/****************************************************************************************
* Creates Hash external context from RDD_BRIDGE_ARL_LKP_RESULT_DTS
* 
*
* \param[out]       ext_ctx[3]    Hash external context
* \param[in]        rdd_arl_data  
 *****************************************************************************************/
void map_rdd_arl_data_to_ext_ctx(RDD_BRIDGE_ARL_LKP_RESULT_DTS *rdd_arl_data, 
   uint8_t* ext_ctx);

void map_ext_ctx_to_rdd_arl_data(uint8_t* ext_ctx,
    RDD_BRIDGE_ARL_LKP_RESULT_DTS *rdd_arl_data);

/****************************************************************************************
* Init Runner bridge ports representation
 *****************************************************************************************/
void rdd_bridge_ports_init(void);

#endif /* _RDD_BRIDGE_H */
