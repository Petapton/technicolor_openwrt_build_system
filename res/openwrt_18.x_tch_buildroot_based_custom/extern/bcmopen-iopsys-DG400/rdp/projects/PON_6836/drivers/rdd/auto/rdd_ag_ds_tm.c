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


#include "rdd_ag_ds_tm.h"

int rdd_ag_ds_tm_complex_scheduler_rl_cfg_get(uint32_t _entry, rdd_complex_scheduler_rl_cfg_t *complex_scheduler_rl_cfg)
{
    int i;

    if(!complex_scheduler_rl_cfg || _entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_READ(complex_scheduler_rl_cfg->rate_limit_enable, ((uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_READ(complex_scheduler_rl_cfg->is_positive_budget, ((uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_READ(complex_scheduler_rl_cfg->rate_limiter_index, ((uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_complex_scheduler_rl_cfg_set(uint32_t _entry, rdd_complex_scheduler_rl_cfg_t *complex_scheduler_rl_cfg)
{
    int i;

    if(!complex_scheduler_rl_cfg || _entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE || complex_scheduler_rl_cfg->rate_limiter_index >= 128)
          return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE(complex_scheduler_rl_cfg->rate_limit_enable, (uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)+ (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_WRITE(complex_scheduler_rl_cfg->is_positive_budget, (uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)+ (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE(complex_scheduler_rl_cfg->rate_limiter_index, (uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)+ (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));

        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_descriptor_get(uint32_t _entry, rdd_scheduling_queue_descriptor_t *scheduling_queue_descriptor)
{
    int i;

    if(!scheduling_queue_descriptor || _entry >= RDD_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_READ(scheduling_queue_descriptor->block_type, ((uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_READ(scheduling_queue_descriptor->enable, ((uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_READ(scheduling_queue_descriptor->bbh_queue_index, ((uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ(scheduling_queue_descriptor->scheduler_index, ((uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_READ(scheduling_queue_descriptor->queue_bit_mask, ((uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_scheduling_queue_descriptor_set(uint32_t _entry, rdd_scheduling_queue_descriptor_t *scheduling_queue_descriptor)
{
    int i;

    if(!scheduling_queue_descriptor || _entry >= RDD_SCHEDULING_QUEUE_TABLE_SIZE || scheduling_queue_descriptor->bbh_queue_index >= 64)
          return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_WRITE(scheduling_queue_descriptor->block_type, (uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)+ (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_WRITE(scheduling_queue_descriptor->enable, (uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)+ (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_WRITE(scheduling_queue_descriptor->bbh_queue_index, (uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)+ (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE(scheduling_queue_descriptor->scheduler_index, (uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)+ (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_WRITE(scheduling_queue_descriptor->queue_bit_mask, (uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)+ (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));

        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_bbh_queue_descriptor_get(uint32_t _entry, rdd_bbh_queue_descriptor_t *bbh_queue_descriptor)
{
    int i;

    if(!bbh_queue_descriptor || _entry >= RDD_BBH_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ(bbh_queue_descriptor->scheduler_index, ((uint8_t *)RDD_BBH_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_READ(bbh_queue_descriptor->scheduler_type, ((uint8_t *)RDD_BBH_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_bbh_queue_descriptor_set(uint32_t _entry, rdd_bbh_queue_descriptor_t *bbh_queue_descriptor)
{
    int i;

    if(!bbh_queue_descriptor || _entry >= RDD_BBH_QUEUE_TABLE_SIZE || bbh_queue_descriptor->scheduler_index >= 128)
          return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE(bbh_queue_descriptor->scheduler_index, (uint8_t *)RDD_BBH_QUEUE_TABLE_PTR(i)+ (sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) * _entry));
            RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_WRITE(bbh_queue_descriptor->scheduler_type, (uint8_t *)RDD_BBH_QUEUE_TABLE_PTR(i)+ (sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) * _entry));

        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_complex_scheduler_table_dwrr_offset_pir_set(uint32_t _entry, uint8_t dwrr_offset_pir)
{
    int i;

    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE || dwrr_offset_pir >= 8)
          return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_WRITE(dwrr_offset_pir, (uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_complex_scheduler_table_dwrr_offset_pir_get(uint32_t _entry, uint8_t *dwrr_offset_pir)
{
    int i;

    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_READ(*dwrr_offset_pir, ((uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_complex_scheduler_table_dwrr_offset_sir_set(uint32_t _entry, uint8_t dwrr_offset_sir)
{
    int i;

    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE || dwrr_offset_sir >= 8)
          return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_WRITE(dwrr_offset_sir, (uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_complex_scheduler_table_dwrr_offset_sir_get(uint32_t _entry, uint8_t *dwrr_offset_sir)
{
    int i;

    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_READ(*dwrr_offset_sir, ((uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_complex_scheduler_table_slot_budget_bit_vector_0_set(uint32_t _entry, uint32_t slot_budget_bit_vector_0)
{
    int i;

    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_WRITE(slot_budget_bit_vector_0, (uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_complex_scheduler_table_slot_budget_bit_vector_0_get(uint32_t _entry, uint32_t *slot_budget_bit_vector_0)
{
    int i;

    if(_entry >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_READ(*slot_budget_bit_vector_0, ((uint8_t *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(i)) + (sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_scheduling_queue_table_rate_limit_enable_set(uint32_t _entry, bdmf_boolean rate_limit_enable)
{
    int i;

    if(_entry >= RDD_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE(rate_limit_enable, (uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_rate_limit_enable_get(uint32_t _entry, bdmf_boolean *rate_limit_enable)
{
    int i;

    if(_entry >= RDD_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_READ(*rate_limit_enable, ((uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_scheduling_queue_table_rate_limiter_index_set(uint32_t _entry, uint8_t rate_limiter_index)
{
    int i;

    if(_entry >= RDD_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE(rate_limiter_index, (uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_rate_limiter_index_get(uint32_t _entry, uint8_t *rate_limiter_index)
{
    int i;

    if(_entry >= RDD_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_READ(*rate_limiter_index, ((uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_scheduling_queue_table_quantum_number_set(uint32_t _entry, uint8_t quantum_number)
{
    int i;

    if(_entry >= RDD_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_WRITE(quantum_number, (uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_queue_table_quantum_number_get(uint32_t _entry, uint8_t *quantum_number)
{
    int i;

    if(_entry >= RDD_SCHEDULING_QUEUE_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_READ(*quantum_number, ((uint8_t *)RDD_SCHEDULING_QUEUE_TABLE_PTR(i)) + (sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_bb_destination_table_set(uint16_t bits)
{
    int i;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTES_2_BITS_WRITE(bits, (uint8_t *)RDD_BB_DESTINATION_TABLE_PTR(i));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_bb_destination_table_get(uint16_t *bits)
{
    int i;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTES_2_BITS_READ(*bits, ((uint8_t *)RDD_BB_DESTINATION_TABLE_PTR(i)));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_basic_scheduler_table_quantum_number_set(uint32_t _entry, uint8_t quantum_number)
{
    int i;

    if(_entry >= RDD_BASIC_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_WRITE(quantum_number, (uint8_t *)RDD_BASIC_SCHEDULER_TABLE_PTR(i) + (sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) * _entry));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_basic_scheduler_table_quantum_number_get(uint32_t _entry, uint8_t *quantum_number)
{
    int i;

    if(_entry >= RDD_BASIC_SCHEDULER_TABLE_SIZE)
         return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_READ(*quantum_number, ((uint8_t *)RDD_BASIC_SCHEDULER_TABLE_PTR(i)) + (sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_scheduling_global_flush_cfg_set(uint8_t bits)
{
    int i;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTE_1_BITS_WRITE(bits, (uint8_t *)RDD_SCHEDULING_GLOBAL_FLUSH_CFG_PTR(i));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_global_flush_cfg_get(uint8_t *bits)
{
    int i;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTE_1_BITS_READ(*bits, ((uint8_t *)RDD_SCHEDULING_GLOBAL_FLUSH_CFG_PTR(i)));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_scheduling_flush_vector_set(uint32_t _entry, uint32_t bits)
{
    int i;

    if(_entry >= RDD_SCHEDULING_FLUSH_VECTOR_SIZE)
          return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTES_4_BITS_WRITE(bits, (uint8_t *)RDD_SCHEDULING_FLUSH_VECTOR_PTR(i) + (sizeof(RDD_BYTES_4_DTS) * _entry));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_scheduling_flush_vector_get(uint32_t _entry, uint32_t *bits)
{
    int i;

    if(_entry >= RDD_SCHEDULING_FLUSH_VECTOR_SIZE)
          return BDMF_ERR_PARM;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTES_4_BITS_READ(*bits, ((uint8_t *)RDD_SCHEDULING_FLUSH_VECTOR_PTR(i)) + (sizeof(RDD_BYTES_4_DTS) * _entry));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_bbh_tx_fifo_size_set(uint8_t bits)
{
    int i;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTE_1_BITS_WRITE(bits, (uint8_t *)RDD_BBH_TX_FIFO_SIZE_PTR(i));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_bbh_tx_fifo_size_get(uint8_t *bits)
{
    int i;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTE_1_BITS_READ(*bits, ((uint8_t *)RDD_BBH_TX_FIFO_SIZE_PTR(i)));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

int rdd_ag_ds_tm_first_queue_mapping_set(uint8_t bits)
{
    int i;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTE_1_BITS_WRITE(bits, (uint8_t *)RDD_FIRST_QUEUE_MAPPING_PTR(i));
        }
    }
    return BDMF_ERR_OK;
}

int rdd_ag_ds_tm_first_queue_mapping_get(uint8_t *bits)
{
    int i;

    for(i = 0; i < NUM_OF_RUNNER_CORES; i++)
    {
        if(rdp_core_to_image_map[i] == image_0_runner_image)
        {
            RDD_BYTE_1_BITS_READ(*bits, ((uint8_t *)RDD_FIRST_QUEUE_MAPPING_PTR(i)));
            return BDMF_ERR_OK;
        }
    }
    return BDMF_ERR_INTERNAL;
}

