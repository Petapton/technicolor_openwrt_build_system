/*
  Copyright (c) 2014 Broadcom
  All Rights Reserved

  <:label-BRCM:2014:DUAL/GPL:standard
  
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

#include "rdd.h"
#ifndef WL4908
#include "rdd_legacy_conv.h"
#endif
#include "rdd_service_queues.h"

extern BL_LILAC_RDD_ERROR_DTE f_ds_rate_limiter_config ( RDD_RATE_LIMITER_ID_DTE  xi_rate_limiter_id,
                                                         RDD_RATE_LIMIT_PARAMS    *xi_budget );

void rdd_service_queues_initialize ( void )
{
#ifndef G9991
    RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_DTS   *service_queue_descriptor_ptr;
    RDD_DDR_QUEUE_DESCRIPTOR_DTS              *service_queue_descriptor_entry_ptr;
    RDD_SERVICE_QUEUES_CFG_ENTRY_DTS          *service_tm_descriptor_ptr;
    uint32_t                                  queue_id;

    service_queue_descriptor_ptr = RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_PTR ();

    for ( queue_id = 0; queue_id < RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_SIZE; queue_id++ )
    {
        service_queue_descriptor_entry_ptr = &( service_queue_descriptor_ptr->entry[ queue_id ] );

        RDD_DDR_QUEUE_DESCRIPTOR_QUEUE_MASK_WRITE ( 1 << queue_id , service_queue_descriptor_entry_ptr );
        RDD_DDR_QUEUE_DESCRIPTOR_PACKET_COUNTER_WRITE ( 0 , service_queue_descriptor_entry_ptr );
        RDD_DDR_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_WRITE ( 128 , service_queue_descriptor_entry_ptr );
        RDD_DDR_QUEUE_DESCRIPTOR_HEAD_IDX_WRITE ( 0, service_queue_descriptor_entry_ptr );
        RDD_DDR_QUEUE_DESCRIPTOR_TAIL_IDX_WRITE ( 0, service_queue_descriptor_entry_ptr );
        RDD_DDR_QUEUE_DESCRIPTOR_RATE_CONTROLLER_ID_WRITE ( RDD_RATE_LIMITER_IDLE, service_queue_descriptor_entry_ptr );
        RDD_DDR_QUEUE_DESCRIPTOR_PROFILE_ID_WRITE ( 0, service_queue_descriptor_entry_ptr );
        RDD_DDR_QUEUE_DESCRIPTOR_PROFILE_EN_WRITE ( 0, service_queue_descriptor_entry_ptr );
        RDD_DDR_QUEUE_DESCRIPTOR_CACHE_PTR_WRITE ( SERVICE_QUEUES_DDR_CACHE_FIFO_ADDRESS + queue_id * (SERVICE_QUEUES_DDR_CACHE_FIFO_BYTE_SIZE / 32), service_queue_descriptor_entry_ptr );
    }

    service_tm_descriptor_ptr = ( RDD_SERVICE_QUEUES_CFG_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_CFG_ADDRESS );

    RDD_SERVICE_QUEUES_CFG_ENTRY_SERVICE_QUEUES_STATUS_WRITE ( 0, service_tm_descriptor_ptr );
    RDD_SERVICE_QUEUES_CFG_ENTRY_RATE_LIMITER_STATUS_WRITE ( 0, service_tm_descriptor_ptr );
    RDD_SERVICE_QUEUES_CFG_ENTRY_OVERALL_RATE_LIMITER_MODE_WRITE ( 0, service_tm_descriptor_ptr );
#endif /* !G9991 */
}

void rdd_service_queue_cfg(rdd_service_queue_id_t queue_id, uint16_t pkt_threshold, uint32_t rate_limiter_id, rdd_queue_profile_id_t profile_id)
{
#ifndef G9991
    RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_DTS   *service_queue_descriptor_ptr;
    RDD_DDR_QUEUE_DESCRIPTOR_DTS              *service_queue_descriptor_entry_ptr;
    RDD_SERVICE_QUEUES_CFG_ENTRY_DTS          *service_tm_descriptor_ptr;
    uint32_t                                  rate_limiter_status;
    uint32_t                                  sustain_vector;

    service_queue_descriptor_ptr = RDD_SERVICE_QUEUES_DESCRIPTOR_TABLE_PTR ();

    service_queue_descriptor_entry_ptr = &( service_queue_descriptor_ptr->entry[ queue_id ] );

    RDD_DDR_QUEUE_DESCRIPTOR_PROFILE_ID_WRITE ( profile_id, service_queue_descriptor_entry_ptr );
    RDD_DDR_QUEUE_DESCRIPTOR_PROFILE_EN_WRITE ( profile_id == RDD_QUEUE_PROFILE_DISABLED ? 0 : 1, service_queue_descriptor_entry_ptr );
    RDD_DDR_QUEUE_DESCRIPTOR_PACKET_THRESHOLD_WRITE ( pkt_threshold, service_queue_descriptor_entry_ptr );

    if ( rate_limiter_id == SERVICE_QUEUE_RATE_LIMITER_IDLE )
    {
        service_tm_descriptor_ptr = ( RDD_SERVICE_QUEUES_CFG_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_CFG_ADDRESS );

        RDD_DDR_QUEUE_DESCRIPTOR_RATE_CONTROLLER_ID_WRITE ( SERVICE_QUEUE_RATE_LIMITER_IDLE, service_queue_descriptor_entry_ptr );
        RDD_SERVICE_QUEUES_CFG_ENTRY_RATE_LIMITER_STATUS_READ ( rate_limiter_status, service_tm_descriptor_ptr );
        rate_limiter_status |= ( 1<<queue_id );
        RDD_SERVICE_QUEUES_CFG_ENTRY_RATE_LIMITER_STATUS_WRITE ( rate_limiter_status, service_tm_descriptor_ptr );

        RDD_SERVICE_QUEUES_CFG_ENTRY_SUSTAIN_VECTOR_READ ( sustain_vector, service_tm_descriptor_ptr );
        sustain_vector |= ( 1<<queue_id );
        RDD_SERVICE_QUEUES_CFG_ENTRY_SUSTAIN_VECTOR_WRITE ( sustain_vector, service_tm_descriptor_ptr );
    }
    else
    {
        RDD_DDR_QUEUE_DESCRIPTOR_RATE_CONTROLLER_ID_WRITE ( queue_id, service_queue_descriptor_entry_ptr );
    }
#endif /* !G9991 */
}


void rdd_service_queue_addr_cfg (rdd_service_queue_id_t queue_id, uint32_t ddr_address, uint16_t queue_size)
{
#ifndef G9991
    RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_DTS  *service_queue_addr_ptr;
    RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS                 *service_queue_addr_entry;

    service_queue_addr_ptr = RDD_SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE_PTR();
    service_queue_addr_entry = ( RDD_DDR_QUEUE_ADDRESS_ENTRY_DTS * ) &service_queue_addr_ptr->entry[ queue_id ];

    /* set DDR q base address for each queue */
    RDD_DDR_QUEUE_ADDRESS_ENTRY_ADDR_WRITE ( ddr_address, service_queue_addr_entry );
    RDD_DDR_QUEUE_ADDRESS_ENTRY_SIZE_WRITE ( queue_size, service_queue_addr_entry );
#endif /* !G9991 */
}


int rdd_service_queue_counters_get(rdd_service_queue_id_t queue_id, rdd_service_queue_pm_counters_t  *counters)
{
    BL_LILAC_RDD_ERROR_DTE  rdd_error = BL_LILAC_RDD_OK;
#ifndef G9991
    rdd_error = rdd_4_bytes_counter_get ( SERVICE_QUEUE_PACKET_GROUP, queue_id,
#if defined(OREN)
                                          LILAC_RDD_TRUE,
#endif
                                          &counters->good_tx_packet );

    if ( rdd_error != BL_LILAC_RDD_OK )
    {
        return ( rdd_error );
    }

    rdd_error = rdd_2_bytes_counter_get ( SERVICE_QUEUE_DROP_PACKET_GROUP, queue_id,
#if defined(OREN)
                                          LILAC_RDD_TRUE,
#endif
                                          &counters->error_tx_packets_discard );
#endif /* !G9991 */
    return ( rdd_error );
}


void rdd_service_queue_overall_rate_limiter_enable(bdmf_boolean enable)
{
#ifndef G9991
    RDD_SERVICE_QUEUES_CFG_ENTRY_DTS  *service_tm_descriptor_ptr;

    service_tm_descriptor_ptr = ( RDD_SERVICE_QUEUES_CFG_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_CFG_ADDRESS );

    RDD_SERVICE_QUEUES_CFG_ENTRY_OVERALL_RATE_LIMITER_MODE_WRITE ( enable, service_tm_descriptor_ptr );
#endif /* !G9991 */
}


void rdd_service_queue_overall_rate_limiter_cfg(rdd_rate_limit_params_t *budget)
{
#ifndef G9991
    f_ds_rate_limiter_config ( RDD_RATE_LIMITER_SERVICE_QUEUE_OVERALL, budget );
#endif
}


void rdd_service_queue_rate_limiter_cfg(uint32_t rate_limiter, rdd_rate_cntrl_params_t *budget)
{
#ifndef G9991
#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_CFG_TIMER_TARGET          runner_timer_target_register;
#endif
    RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_DTS      *rate_limiters_table_ptr;
    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_DTS *rate_limiter_descriptor_ptr;
    RDD_SERVICE_QUEUES_CFG_ENTRY_DTS               *service_tm_descriptor_ptr;
    RDD_RATE_CONTROLLER_EXPONENT_TABLE_DTS  *exponent_table_ptr;
    RDD_RATE_CONTROLLER_EXPONENT_ENTRY_DTS  *exponent_entry_ptr;
    uint16_t                                rate_limiter_status;
    uint32_t                                exponent_list[ RDD_RATE_CONTROL_EXPONENT_NUM ];
    uint32_t                                exponent_table_index;
    uint32_t                                peak_budget_exponent;
    uint32_t                                peak_limit_exponent;
    uint32_t                                sustain_budget;
    uint32_t                                peak_budget;
    uint32_t                                peak_limit;
    static uint32_t                         api_first_time_call_service_queue_rate_limiter = LILAC_RDD_TRUE;

    rate_limiters_table_ptr = RDD_SERVICE_QUEUES_RATE_LIMITER_TABLE_PTR();

    rate_limiter_descriptor_ptr = &rate_limiters_table_ptr->entry[ rate_limiter ];

    MEMSET ( rate_limiter_descriptor_ptr, 0, sizeof ( RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_DTS ) );

    /* read exponents table */
#if defined(OREN)
    exponent_table_ptr = RDD_RATE_CONTROLLER_EXPONENT_TABLE_PTR();
#else
    exponent_table_ptr = (RDD_RATE_CONTROLLER_EXPONENT_TABLE_DTS *)( DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + DS_RATE_CONTROLLER_EXPONENT_TABLE_ADDRESS );
#endif

    for ( exponent_table_index = 0; exponent_table_index < RDD_RATE_CONTROL_EXPONENT_NUM; exponent_table_index++ )
    {
        exponent_entry_ptr = &( exponent_table_ptr->entry[ exponent_table_index ] );
        RDD_RATE_CONTROLLER_EXPONENT_ENTRY_EXPONENT_READ ( exponent_list[ exponent_table_index ], exponent_entry_ptr );
    }

    /* convert sustain rate to allocation units */
    sustain_budget = rdd_budget_to_alloc_unit ( budget->sustain_budget, SERVICE_QUEUE_RATE_LIMITER_TIMER_PERIOD, 0 );

    /* convert peak budget to allocation unit and divide to exponent and mantissa */
    peak_budget = rdd_budget_to_alloc_unit ( budget->peak_budget.rate, SERVICE_QUEUE_RATE_LIMITER_TIMER_PERIOD, 0 );

    peak_budget_exponent = rdd_get_exponent ( budget->peak_budget.rate, 14, RDD_RATE_CONTROL_EXPONENT_NUM, exponent_list );

    peak_budget = peak_budget >> exponent_list[ peak_budget_exponent ];

    /* convert peak limit to allocation unit and divide to exponent and mantissa */
    peak_limit_exponent = rdd_get_exponent ( budget->peak_budget.limit, 14, RDD_RATE_CONTROL_EXPONENT_NUM, exponent_list );

    peak_limit = budget->peak_budget.limit >> exponent_list[ peak_limit_exponent ];

    /* initialize the hardcoded parameters of the rate controller descriptor */
    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_RATE_LIMITER_MASK_WRITE ( ( 1 << rate_limiter ), rate_limiter_descriptor_ptr );

    /* write rate control parameters to descriptor */
    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_EXPONENT_WRITE ( peak_budget_exponent, rate_limiter_descriptor_ptr );
    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_PEAK_BUDGET_WRITE ( peak_budget, rate_limiter_descriptor_ptr );
    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BUDGET_LIMIT_EXPONENT_WRITE ( peak_limit_exponent, rate_limiter_descriptor_ptr );
    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BUDGET_LIMIT_WRITE ( peak_limit, rate_limiter_descriptor_ptr );
    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_ALLOCATED_SUSTAIN_BUDGET_WRITE ( sustain_budget, rate_limiter_descriptor_ptr );
    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_WEIGHT_WRITE ( budget->peak_weight >> 8, rate_limiter_descriptor_ptr );

    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_PEAK_BURST_FLAG_WRITE ( LILAC_RDD_ON, rate_limiter_descriptor_ptr );

    RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR_RATE_LIMITER_MASK_WRITE ( ( 1 << rate_limiter ), rate_limiter_descriptor_ptr );

    service_tm_descriptor_ptr = ( RDD_SERVICE_QUEUES_CFG_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + SERVICE_QUEUES_CFG_ADDRESS );
    RDD_SERVICE_QUEUES_CFG_ENTRY_RATE_LIMITER_STATUS_READ ( rate_limiter_status, service_tm_descriptor_ptr );

    rate_limiter_status |= ( 1 << rate_limiter );

    RDD_SERVICE_QUEUES_CFG_ENTRY_RATE_LIMITER_STATUS_WRITE ( rate_limiter_status, service_tm_descriptor_ptr );

    if ( api_first_time_call_service_queue_rate_limiter )
    {
#if !defined(FIRMWARE_INIT)
        RUNNER_REGS_0_CFG_TIMER_TARGET_READ ( runner_timer_target_register );

        runner_timer_target_register.timer_4_6 = RUNNER_REGS_CFG_TIMER_TARGET_TIMER_4_6_PICO_CORE_VALUE;

        RUNNER_REGS_0_CFG_TIMER_TARGET_WRITE ( runner_timer_target_register );

        rdd_timer_task_config ( rdpa_dir_ds, SERVICE_QUEUE_RATE_LIMITER_TIMER_PERIOD, DOWNSTREAM_SERVICE_QUEUES_RATE_LIMITER_BUDGET_ALLOCATE_CODE_ID );
#else
        rdd_timer_task_config ( rdpa_dir_ds, 100, DOWNSTREAM_SERVICE_QUEUES_RATE_LIMITER_BUDGET_ALLOCATE_CODE_ID ); 
#endif

        api_first_time_call_service_queue_rate_limiter = LILAC_RDD_FALSE;
    }
#endif /* !G9991 */
}

