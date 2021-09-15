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


#include "rdd_ag_processing.h"

int rdd_ag_processing_vport_cfg_entry_get(uint32_t _entry, rdd_vport_cfg_entry_t *vport_cfg_entry)
{
    if(!vport_cfg_entry || _entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_SA_LOOKUP_EN_READ_G(vport_cfg_entry->sa_lookup_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);
    RDD_VPORT_CFG_ENTRY_DA_LOOKUP_EN_READ_G(vport_cfg_entry->da_lookup_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);
    RDD_VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_READ_G(vport_cfg_entry->sa_lookup_miss_action, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);
    RDD_VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_READ_G(vport_cfg_entry->da_lookup_miss_action, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_entry_set(uint32_t _entry, rdd_vport_cfg_entry_t *vport_cfg_entry)
{
    if(!vport_cfg_entry || _entry >= RDD_VPORT_CFG_TABLE_SIZE || vport_cfg_entry->sa_lookup_miss_action >= 4 || vport_cfg_entry->da_lookup_miss_action >= 4)
          return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_SA_LOOKUP_EN_WRITE_G(vport_cfg_entry->sa_lookup_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);
    RDD_VPORT_CFG_ENTRY_DA_LOOKUP_EN_WRITE_G(vport_cfg_entry->da_lookup_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);
    RDD_VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_WRITE_G(vport_cfg_entry->sa_lookup_miss_action, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);
    RDD_VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_WRITE_G(vport_cfg_entry->da_lookup_miss_action, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_loopback_en_set(uint32_t _entry, bdmf_boolean loopback_en)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_LOOPBACK_EN_WRITE_G(loopback_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_loopback_en_get(uint32_t _entry, bdmf_boolean *loopback_en)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_LOOPBACK_EN_READ_G(*loopback_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_mirroring_en_set(uint32_t _entry, bdmf_boolean mirroring_en)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_MIRRORING_EN_WRITE_G(mirroring_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_mirroring_en_get(uint32_t _entry, bdmf_boolean *mirroring_en)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_MIRRORING_EN_READ_G(*mirroring_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_egress_isolation_en_set(uint32_t _entry, bdmf_boolean egress_isolation_en)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_WRITE_G(egress_isolation_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_egress_isolation_en_get(uint32_t _entry, bdmf_boolean *egress_isolation_en)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_READ_G(*egress_isolation_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_ingress_isolation_en_set(uint32_t _entry, bdmf_boolean ingress_isolation_en)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_WRITE_G(ingress_isolation_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_ingress_isolation_en_get(uint32_t _entry, bdmf_boolean *ingress_isolation_en)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_READ_G(*ingress_isolation_en, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_bridge_and_vlan_lookup_method_set(uint32_t _entry, bdmf_boolean bridge_and_vlan_lookup_method)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_WRITE_G(bridge_and_vlan_lookup_method, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_bridge_and_vlan_lookup_method_get(uint32_t _entry, bdmf_boolean *bridge_and_vlan_lookup_method)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_READ_G(*bridge_and_vlan_lookup_method, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_ls_fc_cfg_set(uint32_t _entry, bdmf_boolean ls_fc_cfg)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_LS_FC_CFG_WRITE_G(ls_fc_cfg, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

int rdd_ag_processing_vport_cfg_table_ls_fc_cfg_get(uint32_t _entry, bdmf_boolean *ls_fc_cfg)
{
    if(_entry >= RDD_VPORT_CFG_TABLE_SIZE)
         return BDMF_ERR_PARM;

    RDD_VPORT_CFG_ENTRY_LS_FC_CFG_READ_G(*ls_fc_cfg, RDD_VPORT_CFG_TABLE_ADDRESS_ARR, _entry);

    return BDMF_ERR_OK;
}

