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

#include "rdd_complex_rate_limiter.h"
#include "rdd_scheduling.h"
#include "rdd_basic_scheduler.h"
#include "rdd_complex_scheduler.h"

extern uint32_t exponent_list[EXPONENT_LIST_LEN];

/* API to RDPA level */
bdmf_error_t rdd_complex_rate_limiter_cfg(rdpa_traffic_dir dir, uint8_t rl_index, rdd_complex_rl_cfg_t *rl_cfg)
{
    bdmf_error_t rc;
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS *entry;
    uint32_t rl_vec_en, *valid_vector, sir_alloc, pir_alloc, pir_limit;
    rdd_rl_float_t complex_rl_float;

    RDD_BTRACE("dir = %d, rl_index = %d, rl_cfg %p = { sustain_budget = %d, peak_limit = %d, peak_rate = %d, "
        "block type =%d, block_index = %d }\n",
        dir, rl_index, rl_cfg, rl_cfg->sustain_budget, rl_cfg->peak_limit, rl_cfg->peak_rate, rl_cfg->type,
        rl_cfg->block_index);

    if ((rl_index >= MAX_INDEX_OF_COMPLEX_RL) ||
        (rl_index % 2 != 0) ||
        (rl_cfg->type >= num_of_rdd_complex_rl_block))
    {
        return BDMF_ERR_PARM;
    }

    if (dir == rdpa_dir_ds)
    {
        valid_vector = ((uint32_t *)RDD_RATE_LIMITER_VALID_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + ((uint32_t)(rl_index / 32));
        entry = ((RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + (rl_index / 2);
    }
    else
    {
        valid_vector = ((uint32_t *)RDD_RATE_LIMITER_VALID_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + ((uint32_t)(rl_index / 32));
        entry = ((RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + (rl_index / 2);
    }

    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_WRITE(COMPLEX_RATE_LIMITER_SIR_INIT_RATE, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_WRITE(COMPLEX_RATE_LIMITER_PIR_INIT_RATE, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_WRITE(rl_cfg->block_index, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_WRITE(rl_cfg->type, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_WRITE(RDD_RL_TYPE_COMPLEX, entry);

    sir_alloc = rdd_rate_to_alloc_unit(rl_cfg->sustain_budget, RATE_LIMITER_TIMER_PERIOD_IN_USEC);
    complex_rl_float = rdd_rate_limiter_get_floating_point_rep(sir_alloc, exponent_list);
    if ((!complex_rl_float.exponent) && (!complex_rl_float.mantissa))
        return BDMF_ERR_PARM;

    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_WRITE(complex_rl_float.exponent, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_WRITE(complex_rl_float.mantissa, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_EXPONENT_WRITE(complex_rl_float.exponent, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_MANTISSA_WRITE(complex_rl_float.mantissa, entry);

    pir_alloc = rdd_rate_to_alloc_unit(rl_cfg->peak_rate, RATE_LIMITER_TIMER_PERIOD_IN_USEC);
    complex_rl_float = rdd_rate_limiter_get_floating_point_rep(pir_alloc, exponent_list);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_WRITE(complex_rl_float.exponent, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_WRITE(complex_rl_float.mantissa, entry);

    pir_limit = rl_cfg->peak_limit;
    if (!pir_limit)
        pir_limit = pir_alloc;
    if (pir_limit > RL_MAX_BUCKET_SIZE)
        pir_limit = RL_MAX_BUCKET_SIZE;
    complex_rl_float = rdd_rate_limiter_get_floating_point_rep(pir_limit, exponent_list);
    if ((!complex_rl_float.exponent) && (!complex_rl_float.mantissa))
        return BDMF_ERR_PARM;

    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_EXPONENT_WRITE(complex_rl_float.exponent, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_MANTISSA_WRITE(complex_rl_float.mantissa, entry);

    switch ((uint32_t)rl_cfg->type)
    {
        case rdd_complex_rl_queue:
            if (dir == rdpa_dir_us)
            {
                rc = rdd_ag_us_tm_scheduling_queue_table_rate_limiter_index_set(rl_cfg->block_index - QM_QUEUE_US_START, rl_index);
                rc = rc ? rc : rdd_ag_us_tm_scheduling_queue_table_rate_limit_enable_set(rl_cfg->block_index - QM_QUEUE_US_START, 1);
            }
            else
            {
                rc = rdd_ag_ds_tm_scheduling_queue_table_rate_limiter_index_set(rl_cfg->block_index - QM_QUEUE_DS_START, rl_index);
                rc = rc ? rc : rdd_ag_ds_tm_scheduling_queue_table_rate_limit_enable_set(rl_cfg->block_index - QM_QUEUE_DS_START, 1);
            }
            break;
        case rdd_complex_rl_basic_scheduler:
            rc = rdd_basic_scheduler_rate_limiter_cfg(dir, rl_cfg->block_index, rl_index);
            break;
        default:
            return BDMF_ERR_INTERNAL;
    }

    /* enable the rate limiter */
    RDD_BYTES_4_BITS_READ(rl_vec_en, valid_vector);
    rl_vec_en |= (1 << (rl_index & 0x1f));
    RDD_BYTES_4_BITS_WRITE(rl_vec_en, valid_vector);

    return rc;
}

bdmf_error_t rdd_complex_rate_limiter_remove(rdpa_traffic_dir dir, uint8_t rl_index)
{
    bdmf_error_t rc;
    uint32_t type, block_index;
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS *entry;

    RDD_BTRACE("dir = %d, rl_index = %d\n", dir, rl_index);

    if (rl_index >= MAX_INDEX_OF_COMPLEX_RL)
    {
        return BDMF_ERR_PARM;
    }

    if (dir == rdpa_dir_ds)
        entry = ((RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + (rl_index / 2);
    else
        entry = ((RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + (rl_index / 2);

    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_READ(type, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_READ(block_index, entry);
    switch (type)
    {
        case rdd_complex_rl_queue:
            rc = rdd_scheduling_queue_rate_limiter_remove(dir, block_index);
            break;
        case rdd_complex_rl_basic_scheduler:
            rc = rdd_basic_scheduler_rate_limiter_remove(dir, block_index);
            break;
        default:
            return BDMF_ERR_INTERNAL;
    }
    /* rl will be removed from rl_vec_en by the budget allocator task */
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_WRITE(COMPLEX_RATE_LIMITER_SIR_INIT_RATE, entry);
    RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_WRITE(COMPLEX_RATE_LIMITER_PIR_INIT_RATE, entry);

    return rc;
}

