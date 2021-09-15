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


#ifndef _RDD_AG_BRIDGE_H_
#define _RDD_AG_BRIDGE_H_

#include "rdd.h"

int rdd_ag_bridge_default_bridge_cfg_set(bdmf_boolean aggregation_en, bdmf_boolean arl_lookup_method, uint16_t wan_vid, uint8_t port_isolation_map_31_24, uint32_t port_isolation_map_23_0);
int rdd_ag_bridge_default_bridge_cfg_get(bdmf_boolean *aggregation_en, bdmf_boolean *arl_lookup_method, uint16_t *wan_vid, uint8_t *port_isolation_map_31_24, uint32_t *port_isolation_map_23_0);
int rdd_ag_bridge_bridge_cfg_table_bridge_aggregation_en_set(uint32_t _entry, bdmf_boolean bridge_aggregation_en);
int rdd_ag_bridge_bridge_cfg_table_bridge_aggregation_en_get(uint32_t _entry, bdmf_boolean *bridge_aggregation_en);

#endif /* _RDD_AG_BRIDGE_H_ */
