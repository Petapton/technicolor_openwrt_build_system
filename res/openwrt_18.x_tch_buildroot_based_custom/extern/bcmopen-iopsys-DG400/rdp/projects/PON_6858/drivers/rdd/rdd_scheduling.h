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

#ifndef _SCHEDULING_H
#define _SCHEDULING_H

#include "rdd.h"
#include "rdd_defs.h"
#include "rdd_ag_us_tm.h"
#include "rdd_ag_ds_tm.h"
#include "rdd_basic_scheduler.h"

#define SCHEDULING
#define MAX_NUM_OF_LLID 32

typedef struct
{
    bdmf_boolean rl_en;
    uint8_t rl_index;
    uint32_t rl_rate;
} rdd_tm_rl_info;

typedef struct
{
    uint8_t queue_index;
    uint8_t queue_weight;
    rdd_tm_rl_info queue_rl;
    uint8_t queue_bit_mask;
} rdd_tm_queue_info;

typedef struct
{
    bdmf_boolean enable;
    rdd_tm_rl_info sched_rl;
    uint8_t sched_index;
    uint8_t dwrr_offset;
    rdd_tm_queue_info queue_info[BASIC_SCHEDULER_NUM_OF_QUEUES];
} rdd_tm_bs_info;

/* API to RDPA level */
void rdd_set_queue_enable(uint32_t qm_queue_index, bdmf_boolean enable);

/*XXX: change to AUTO */
/* API to scheduler module */
bdmf_error_t rdd_scheduling_scheduler_block_cfg(rdpa_traffic_dir dir, uint8_t qm_queue_index, rdd_scheduling_queue_descriptor_t *scheduler_cfg, bdmf_boolean type, uint8_t dwrr_offset);

/*XXX: change to AUTO */
/* API to rate limiter module */
bdmf_error_t rdd_scheduling_queue_rate_limiter_remove(rdpa_traffic_dir dir, uint8_t qm_queue_index);

/* Internal RDD init function */
void rdd_bbh_queue_init(void);
bdmf_error_t rdd_ds_budget_allocation_timer_set(void);
bdmf_error_t rdd_us_budget_allocation_timer_set(void);
bdmf_error_t rdd_tm_epon_cfg(void);
bdmf_error_t rdd_scheduling_flush_timer_set(void);

/* TM debug */
void rdd_ds_tm_debug_get(rdpa_emac emac, rdd_tm_bs_info *info);

#ifdef G9991
/* API for g9991 vport to physical port mapping */
int rdd_g9991_vport_to_emac_mapping_cfg(rdd_rdd_vport vport, rdpa_emac emac);
int rdd_g9991_control_sid_set(rdd_rdd_vport vport, rdpa_emac emac);
uint32_t rdd_g9991_thread_number_get(rdpa_emac emac, uint32_t mask);
#endif

#endif
