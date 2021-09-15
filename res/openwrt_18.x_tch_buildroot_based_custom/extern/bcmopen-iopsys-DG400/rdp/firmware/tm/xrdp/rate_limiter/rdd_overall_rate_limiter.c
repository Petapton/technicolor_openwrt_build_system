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

#include "rdd_overall_rate_limiter.h"

extern uint32_t exponent_list[EXPONENT_LIST_LEN];

/* API to RDPA level */
bdmf_error_t rdd_overall_rate_limiter_rate_cfg(uint32_t rate, uint32_t limit)
{
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS *ovl_rl_entry;
    uint32_t alloc_rate, limit_rate;
    rdd_rl_float_t rl_float;

    ovl_rl_entry = (RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_OVERALL_RATE_LIMITER_TABLE_PTR(get_runner_idx(us_tm_runner_image));
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_WRITE(OVERALL_RATE_LIMITER_INIT_RATE, ovl_rl_entry);

    if (!rate)
    {
        RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_WRITE(OVERALL_RATE_LIMITER_UNLIMITED_EXP, ovl_rl_entry);
        RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_WRITE(OVERALL_RATE_LIMITER_UNLIMITED_MAN, ovl_rl_entry);
        RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_WRITE(OVERALL_RATE_LIMITER_UNLIMITED_EXP, ovl_rl_entry);
        RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_WRITE(OVERALL_RATE_LIMITER_UNLIMITED_MAN, ovl_rl_entry);

        return BDMF_ERR_OK;
    }

    /* set overall rl rate */
    alloc_rate = rdd_rate_to_alloc_unit(rate, RATE_LIMITER_TIMER_PERIOD_IN_USEC);
    rl_float = rdd_rate_limiter_get_floating_point_rep(alloc_rate, exponent_list);
    if ((!rl_float.exponent) && (!rl_float.mantissa))
        return BDMF_ERR_PARM;

    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_WRITE(rl_float.exponent, ovl_rl_entry);
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_WRITE(rl_float.mantissa, ovl_rl_entry);

    limit_rate = rdd_rate_to_alloc_unit(limit, RATE_LIMITER_TIMER_PERIOD_IN_USEC);
    rl_float = rdd_rate_limiter_get_floating_point_rep(limit_rate, exponent_list);
    if ((!rl_float.exponent) && (!rl_float.mantissa))
        return BDMF_ERR_PARM;

    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_WRITE(rl_float.exponent, ovl_rl_entry);
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_WRITE(rl_float.mantissa, ovl_rl_entry);

    return BDMF_ERR_OK;
}

bdmf_error_t rdd_overall_rate_limiter_bbh_queue_cfg(uint8_t bbh_queue_index, bdmf_boolean is_high_priority)
{
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS *ovl_rl_entry;
    RDD_BBH_QUEUE_DESCRIPTOR_DTS *bbh_queue_entry;
    RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS *basic_scheduler_entry;
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *complex_scheduler_entry;
    uint32_t bbh_queue_vec, sched_idx;
    bdmf_boolean sched_type;

    if (bbh_queue_index >= RDD_BBH_QUEUE_TABLE_SIZE)
        return BDMF_ERR_PARM;

    ovl_rl_entry = (RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_OVERALL_RATE_LIMITER_TABLE_PTR(get_runner_idx(us_tm_runner_image));
    bbh_queue_entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + bbh_queue_index;

    /* map overall rl to scheduler */
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_BBH_QUEUE_EN_VEC_READ(bbh_queue_vec, ovl_rl_entry);
    bbh_queue_vec |= (1 << bbh_queue_index);
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_BBH_QUEUE_EN_VEC_WRITE(bbh_queue_vec, ovl_rl_entry);

    /* map scheduler to overall rl */
    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ(sched_idx, bbh_queue_entry);
    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_READ(sched_type, bbh_queue_entry);
    RDD_BBH_QUEUE_DESCRIPTOR_PRIORITY_WRITE(is_high_priority, bbh_queue_entry);
    if (sched_type == RDD_SCHED_TYPE_BASIC)
    {
        basic_scheduler_entry = (RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS *)RDD_BASIC_SCHEDULER_TABLE_PTR(get_runner_idx(us_tm_runner_image)) + sched_idx;
        RDD_BASIC_SCHEDULER_DESCRIPTOR_OVL_RL_EN_WRITE(1, basic_scheduler_entry);
    }
    else
    {
        complex_scheduler_entry = (RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(us_tm_runner_image)) + sched_idx;
        RDD_COMPLEX_SCHEDULER_DESCRIPTOR_OVL_RL_EN_WRITE(1, complex_scheduler_entry);
    }

    return BDMF_ERR_OK;
}

bdmf_error_t rdd_overall_rate_limiter_remove(uint8_t bbh_queue_index)
{
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS *ovl_rl_entry;
    RDD_BBH_QUEUE_DESCRIPTOR_DTS *bbh_queue_entry;
    RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS *basic_scheduler_entry;
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *complex_scheduler_entry;
    uint32_t sched_idx;
    bdmf_boolean sched_type;

    if (bbh_queue_index >= RDD_BBH_QUEUE_TABLE_SIZE)
        return BDMF_ERR_PARM;

    ovl_rl_entry = (RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_OVERALL_RATE_LIMITER_TABLE_PTR(get_runner_idx(us_tm_runner_image));
    bbh_queue_entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + bbh_queue_index;

    /* remove mapping of scheduler to overall rl */
    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ(sched_idx, bbh_queue_entry);
    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_READ(sched_type, bbh_queue_entry);
    if (sched_type == RDD_SCHED_TYPE_BASIC)
    {
        basic_scheduler_entry = (RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS *)RDD_BASIC_SCHEDULER_TABLE_PTR(get_runner_idx(us_tm_runner_image)) + sched_idx;
        RDD_BASIC_SCHEDULER_DESCRIPTOR_OVL_RL_EN_WRITE(0, basic_scheduler_entry);
    }
    else
    {
        complex_scheduler_entry = (RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(us_tm_runner_image)) + sched_idx;
        RDD_COMPLEX_SCHEDULER_DESCRIPTOR_OVL_RL_EN_WRITE(0, complex_scheduler_entry);
    }

    /* rl will be removed from vector by the budget allocator task */
    RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_WRITE(OVERALL_RATE_LIMITER_INIT_RATE, ovl_rl_entry);

    return BDMF_ERR_OK;
}
