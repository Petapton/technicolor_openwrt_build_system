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
#ifndef _RDD_TUPLE_LKP_H
#define _RDD_TUPLE_LKP_H


#include "rdd.h"
#include "rdd_common.h"


typedef struct natc_params
{
    uint32_t connection_key_offset;
} natc_params_t;

int rdd_nat_cache_init(const rdd_module_t *module);

int rdd_ip_class_key_entry_compose(rdpa_ip_flow_key_t *tuple_entry, uint8_t *connection_entry);
void rdd_ip_class_key_entry_decompose(rdpa_ip_flow_key_t *tuple_entry, uint8_t *sub_tbl_id, uint8_t *tuple_entry_ptr);
void rdd_3_tupples_ip_flows_enable(bdmf_boolean enable);
void rdd_esp_filter_set(rdd_action action);
#endif /* RDD_TUPLE_LKP_H_ */

