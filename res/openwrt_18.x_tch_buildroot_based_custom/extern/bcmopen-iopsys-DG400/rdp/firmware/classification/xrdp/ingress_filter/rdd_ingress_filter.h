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

#ifndef _RDD_INGRESS_FILTER_H
#define _RDD_INGRESS_FILTER_H

#include "rdd.h"

#define MAX_NUMBER_OF_INGRESS_FILTERS       32

/* Ingress filter action */
typedef enum
{
    rdd_filter_action_drop    = 0, 
    rdd_filter_action_trap    = 1, 
} rdd_filter_action;

/* modular firmware */
int rdd_ingress_filter_module_init(const rdd_module_t *module);

void rdd_ingress_filter_vport_to_profile_set(uint8_t vport, uint8_t profile);
void rdd_ingress_filter_profile_cfg(uint8_t profile, uint32_t filter_mask, uint32_t action_mask);
void rdd_ingress_filter_1588_cfg(int enable);
int rdd_ingress_filter_drop_counter_get(uint8_t filter, rdpa_traffic_dir dir, uint16_t *drop_counter);

#endif
