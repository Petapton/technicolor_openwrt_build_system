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


#ifndef _RDD_AG_PROCESSING_H_
#define _RDD_AG_PROCESSING_H_

#include "rdd.h"

typedef struct
{
    bdmf_boolean sa_lookup_en;
    bdmf_boolean da_lookup_en;
    uint8_t sa_lookup_miss_action;
    uint8_t da_lookup_miss_action;
} rdd_vport_cfg_entry_t;

int rdd_ag_processing_vport_cfg_entry_get(uint32_t _entry, rdd_vport_cfg_entry_t *vport_cfg_entry);
int rdd_ag_processing_vport_cfg_entry_set(uint32_t _entry, rdd_vport_cfg_entry_t *vport_cfg_entry);
int rdd_ag_processing_vport_cfg_table_loopback_en_set(uint32_t _entry, bdmf_boolean loopback_en);
int rdd_ag_processing_vport_cfg_table_loopback_en_get(uint32_t _entry, bdmf_boolean *loopback_en);
int rdd_ag_processing_vport_cfg_table_mirroring_en_set(uint32_t _entry, bdmf_boolean mirroring_en);
int rdd_ag_processing_vport_cfg_table_mirroring_en_get(uint32_t _entry, bdmf_boolean *mirroring_en);
int rdd_ag_processing_vport_cfg_table_egress_isolation_en_set(uint32_t _entry, bdmf_boolean egress_isolation_en);
int rdd_ag_processing_vport_cfg_table_egress_isolation_en_get(uint32_t _entry, bdmf_boolean *egress_isolation_en);
int rdd_ag_processing_vport_cfg_table_ingress_isolation_en_set(uint32_t _entry, bdmf_boolean ingress_isolation_en);
int rdd_ag_processing_vport_cfg_table_ingress_isolation_en_get(uint32_t _entry, bdmf_boolean *ingress_isolation_en);
int rdd_ag_processing_vport_cfg_table_bridge_and_vlan_lookup_method_set(uint32_t _entry, bdmf_boolean bridge_and_vlan_lookup_method);
int rdd_ag_processing_vport_cfg_table_bridge_and_vlan_lookup_method_get(uint32_t _entry, bdmf_boolean *bridge_and_vlan_lookup_method);
int rdd_ag_processing_vport_cfg_table_ls_fc_cfg_set(uint32_t _entry, bdmf_boolean ls_fc_cfg);
int rdd_ag_processing_vport_cfg_table_ls_fc_cfg_get(uint32_t _entry, bdmf_boolean *ls_fc_cfg);

#endif /* _RDD_AG_PROCESSING_H_ */
