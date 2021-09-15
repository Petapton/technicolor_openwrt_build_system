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

#include "rdd_basic_rate_limiter.h"
#include "rdd_scheduling.h"
#include "rdd_basic_scheduler.h"
#include "rdd_complex_scheduler.h"

extern uint32_t exponent_list[EXPONENT_LIST_LEN];

/* API to RDPA level */
bdmf_error_t rdd_basic_rate_limiter_cfg(rdpa_traffic_dir dir, uint8_t basic_rl_index, rdd_basic_rl_cfg_t *rl_cfg)
{
    bdmf_error_t rc = BDMF_ERR_OK;
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS *entry;
    uint32_t basic_rl_vec_en, *valid_vector, alloc_rate, limit_rate;
    rdd_rl_float_t basic_rl_float;

    RDD_BTRACE("dir = %d, basic_rl_index = %d, rl_cfg %p = { rate = %d, block type = %d, block_index = %d  }\n",
        dir, basic_rl_index, rl_cfg, rl_cfg->rate, rl_cfg->type, rl_cfg->block_index);
    if (basic_rl_index >= RDD_BASIC_RATE_LIMITER_TABLE_SIZE)
    {
        return BDMF_ERR_PARM;
    }

    if (dir == rdpa_dir_ds)
    {
        valid_vector = ((uint32_t *)RDD_RATE_LIMITER_VALID_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + ((uint32_t)(basic_rl_index / 32));
        entry = ((RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + basic_rl_index;
    }
    else
    {
        valid_vector = ((uint32_t *)RDD_RATE_LIMITER_VALID_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + ((uint32_t)(basic_rl_index / 32));
        entry = ((RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + basic_rl_index;
    }

    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_WRITE(BASIC_RATE_LIMITER_INIT_RATE, entry);
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_WRITE(rl_cfg->type, entry);
    if (rl_cfg->type == rdd_basic_rl_queue)
        if (dir == rdpa_dir_ds)
            RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_WRITE((rl_cfg->block_index - QM_QUEUE_DS_START), entry);
        else
            RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_WRITE((rl_cfg->block_index - QM_QUEUE_US_START), entry);
    else
        RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_WRITE(rl_cfg->block_index, entry);
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_RL_TYPE_WRITE(RDD_RL_TYPE_BASIC, entry);

    alloc_rate = rdd_rate_to_alloc_unit(rl_cfg->rate, RATE_LIMITER_TIMER_PERIOD_IN_USEC);
    basic_rl_float = rdd_rate_limiter_get_floating_point_rep(alloc_rate, exponent_list);
    if ((!basic_rl_float.exponent) && (!basic_rl_float.mantissa))
        return BDMF_ERR_PARM;

    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_WRITE(basic_rl_float.exponent, entry);
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_WRITE(basic_rl_float.mantissa, entry);

    limit_rate = rl_cfg->limit;
    if (!limit_rate)
        limit_rate = alloc_rate;
    if (limit_rate > RL_MAX_BUCKET_SIZE)
        limit_rate = RL_MAX_BUCKET_SIZE;
    basic_rl_float = rdd_rate_limiter_get_floating_point_rep(limit_rate, exponent_list);
    if ((!basic_rl_float.exponent) && (!basic_rl_float.mantissa))
        return BDMF_ERR_PARM;

    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_WRITE(basic_rl_float.exponent, entry);
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_WRITE(basic_rl_float.mantissa, entry);

    switch ((uint32_t)rl_cfg->type)
    {
        case rdd_basic_rl_queue:
            if (dir == rdpa_dir_us)
            {
                rc = rdd_ag_us_tm_scheduling_queue_table_rate_limiter_index_set(rl_cfg->block_index - QM_QUEUE_US_START, basic_rl_index);
                rc = rc ? rc : rdd_ag_us_tm_scheduling_queue_table_rate_limit_enable_set(rl_cfg->block_index - QM_QUEUE_US_START, 1);
            }
            else
            {
                rc = rdd_ag_ds_tm_scheduling_queue_table_rate_limiter_index_set(rl_cfg->block_index - QM_QUEUE_DS_START, basic_rl_index);
                rc = rc ? rc : rdd_ag_ds_tm_scheduling_queue_table_rate_limit_enable_set(rl_cfg->block_index - QM_QUEUE_DS_START, 1);
            }
            break;
        case rdd_basic_rl_basic_scheduler:
            rc = rdd_basic_scheduler_rate_limiter_cfg(dir, rl_cfg->block_index, basic_rl_index);
            break;
        case rdd_basic_rl_complex_scheduler:
            {
                rdd_complex_scheduler_rl_cfg_t cs_rl_cfg = 
                {
                    .rate_limit_enable = 1,
                    .is_positive_budget = 1,
                    .rate_limiter_index = basic_rl_index
                };
                if (dir == rdpa_dir_ds)
                    rc = rdd_ag_ds_tm_complex_scheduler_rl_cfg_set(rl_cfg->block_index, &cs_rl_cfg);
                else
                    rc = rdd_ag_us_tm_complex_scheduler_rl_cfg_set(rl_cfg->block_index, &cs_rl_cfg);
            }
            break;
    }

    /* enable the rate limiter */
    RDD_BYTES_4_BITS_READ(basic_rl_vec_en, valid_vector);
    basic_rl_vec_en |= (1 << (basic_rl_index & 0x1f));
    RDD_BYTES_4_BITS_WRITE(basic_rl_vec_en, valid_vector);

    return rc;
}

bdmf_error_t rdd_basic_rate_limiter_remove(rdpa_traffic_dir dir, uint8_t basic_rl_index)
{
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS *entry;
    uint32_t block_index, type;
    bdmf_error_t rc;

    RDD_BTRACE("dir = %d, basic_rl_index = %d\n", dir, basic_rl_index);

    if (basic_rl_index >= RDD_BASIC_RATE_LIMITER_TABLE_SIZE)
    {
        return BDMF_ERR_PARM;
    }

    if (dir == rdpa_dir_ds)
        entry = ((RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + basic_rl_index;
    else
        entry = ((RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + basic_rl_index;

    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_READ(type, entry);
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_READ(block_index, entry);
    switch (type)
    {
        case rdd_basic_rl_queue:
            if (dir == rdpa_dir_ds)
                block_index += QM_QUEUE_DS_START;
            rc = rdd_scheduling_queue_rate_limiter_remove(dir, block_index);
            break;
        case rdd_basic_rl_basic_scheduler:
            rc = rdd_basic_scheduler_rate_limiter_remove(dir, block_index);
            break;
        case rdd_basic_rl_complex_scheduler:
            {
                rdd_complex_scheduler_rl_cfg_t rl_cfg =
                {
                    .rate_limit_enable = 0,
                    .is_positive_budget = 1,
                    .rate_limiter_index = 0
                };
                if (dir == rdpa_dir_ds)
                    rc = rdd_ag_ds_tm_complex_scheduler_rl_cfg_set(block_index, &rl_cfg);
                else
                    rc = rdd_ag_us_tm_complex_scheduler_rl_cfg_set(block_index, &rl_cfg);
            }
            break;
        default:
            return BDMF_ERR_INTERNAL;
    }
    /* rl will be removed from rl_vec_en by the budget allocator task */
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_WRITE(BASIC_RATE_LIMITER_INIT_RATE, entry);

    return rc;
}

