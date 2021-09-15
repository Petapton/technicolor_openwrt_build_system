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

#include "rdd_complex_scheduler.h"
#include "rdd_basic_scheduler.h"
#include "rdd_ag_us_tm.h"
#include "rdd_ag_ds_tm.h"

extern rdd_bb_id rdpa_emac_to_bb_id_tx[rdpa_emac__num_of];

typedef struct
{
    uint8_t bbh_queue;
    bdmf_boolean type; /* bs - 1, queues - 0 */
} complex_scheduler_info_t;

/* mappping between complex scheduler to bbh queue */
static complex_scheduler_info_t complex_scheduler_info[2][RDD_COMPLEX_SCHEDULER_TABLE_SIZE];

/* API to RDPA level */
bdmf_error_t rdd_complex_scheduler_cfg(rdpa_traffic_dir dir, uint8_t complex_scheduler_index,
    complex_scheduler_cfg_t *cfg)
{
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *entry;
    rdd_bbh_queue_descriptor_t bbh_queue_cfg;
    bdmf_error_t rc;

    RDD_BTRACE("dir = %d, complex_scheduler_index = %d, cfg %p = { dwrr_offset_sir = %d, dwrr_offset_pir = %d, "
        "bbh_queue_index = %d, is_scheduler = %d }\n",
        dir, complex_scheduler_index, cfg, cfg->dwrr_offset_sir, cfg->dwrr_offset_pir, cfg->bbh_queue_index,
        cfg->is_scheduler);

    if ((complex_scheduler_index >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE) ||
        (cfg->dwrr_offset_sir >= complex_scheduler_num_of_dwrr_offset) ||
        (cfg->dwrr_offset_pir >= complex_scheduler_num_of_dwrr_offset) ||
        (cfg->bbh_queue_index >= RDD_BBH_QUEUE_TABLE_SIZE))
    {
        return BDMF_ERR_PARM;
    }

    if (dir == rdpa_dir_ds)
        entry = ((RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + complex_scheduler_index;
    else
        entry = ((RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + complex_scheduler_index;

    /* initialize budget for all queues - relevent for the case no rate limiter was configured */
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_WRITE(COMPLEX_SCHEDULER_FULL_BUDGET_VECTOR, entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_WRITE(cfg->dwrr_offset_sir, entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_WRITE(cfg->dwrr_offset_pir, entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BASIC_SCHEDULER_EXISTS_WRITE(cfg->is_scheduler, entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_WRITE(1, entry);
    bbh_queue_cfg.scheduler_index = complex_scheduler_index;
    bbh_queue_cfg.scheduler_type = RDD_SCHED_TYPE_COMPLEX;
    if (dir == rdpa_dir_ds)
    {
#ifdef XRDP_BBH_PER_LAN_PORT
        RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BBH_QUEUE_WRITE(rdpa_emac_to_bb_id_tx[cfg->bbh_queue_index], entry);
#else
        RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BBH_QUEUE_WRITE(cfg->bbh_queue_index, entry);
#endif
        rc = rdd_ag_ds_tm_bbh_queue_descriptor_set(cfg->bbh_queue_index, &bbh_queue_cfg);
    }
    else
    {
        RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BBH_QUEUE_WRITE(cfg->bbh_queue_index, entry);
        rc = rdd_ag_us_tm_bbh_queue_descriptor_set(cfg->bbh_queue_index, &bbh_queue_cfg);
    }

    /* set which block type connected to the complex scheduler */
    complex_scheduler_info[dir][complex_scheduler_index].type = cfg->is_scheduler;
    complex_scheduler_info[dir][complex_scheduler_index].bbh_queue = cfg->bbh_queue_index;

    return rc;
}

bdmf_error_t rdd_complex_scheduler_block_cfg(rdpa_traffic_dir dir, uint8_t complex_scheduler_index,
    complex_scheduler_block_t *block)
{
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *entry;
    rdd_scheduling_queue_descriptor_t block_cfg = {};
    bdmf_error_t rc = BDMF_ERR_OK;

    RDD_BTRACE("dir = %d, complex_scheduler_index = %d, block %p = { block_index = %d, scheduler_slot_index = %d, "
        "bs_dwrr_offset = %d, quantum_number = %d }\n",
        dir, complex_scheduler_index, block, block->block_index, block->scheduler_slot_index, block->bs_dwrr_offset,
        block->quantum_number);

    if ((complex_scheduler_index >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE) ||
        (block->scheduler_slot_index >= COMPLEX_SCHEDULER_NUM_OF_QUEUES))
    {
        return BDMF_ERR_PARM;
    }

    if (dir == rdpa_dir_ds)
    {
        entry = ((RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + complex_scheduler_index;
        if (complex_scheduler_info[dir][complex_scheduler_index].type)
            rdd_ag_ds_tm_basic_scheduler_table_quantum_number_set(block->block_index, block->quantum_number);
        else
            rc = rdd_ag_ds_tm_scheduling_queue_table_quantum_number_set((block->block_index - QM_QUEUE_DS_START), block->quantum_number);
    }
    else
    {
        entry = ((RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + complex_scheduler_index;
        if (complex_scheduler_info[dir][complex_scheduler_index].type)
            rdd_ag_us_tm_basic_scheduler_table_quantum_number_set(block->block_index, block->quantum_number);
        else
            rc = rdd_ag_us_tm_scheduling_queue_table_quantum_number_set((block->block_index - QM_QUEUE_US_START), block->quantum_number);
    }

    /* mapping block to complex scheduler */
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_WRITE(block->block_index, entry, block->scheduler_slot_index);

    /* mapping complex scheduler to block */
    block_cfg.bbh_queue_index = complex_scheduler_info[dir][complex_scheduler_index].bbh_queue;
    block_cfg.scheduler_index = complex_scheduler_index;
    block_cfg.block_type = 1; /* complex scheduler */
    block_cfg.queue_bit_mask = block->scheduler_slot_index; /* in case of queue under complex scheduler bit mask is the index */
    block_cfg.enable = 1;

    rc = rc ? rc : rdd_scheduling_scheduler_block_cfg(dir, block->block_index, &block_cfg,
        complex_scheduler_info[dir][complex_scheduler_index].type, block->bs_dwrr_offset);

    return rc;
}

bdmf_error_t rdd_complex_scheduler_block_remove(rdpa_traffic_dir dir, uint8_t complex_scheduler_index, uint8_t scheduler_slot_index)
{
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *entry;
    rdd_scheduling_queue_descriptor_t block_cfg = {};
    uint8_t block_index;
    bdmf_error_t rc = BDMF_ERR_OK;

    RDD_BTRACE("dir = %d, complex_scheduler_index = %d, scheduler_slot_index = %d\n",
        dir, complex_scheduler_index, scheduler_slot_index);

    if (complex_scheduler_index >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
    {
        return BDMF_ERR_PARM;
    }

    if (dir == rdpa_dir_ds)
        entry = ((RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + complex_scheduler_index;
    else
        entry = ((RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + complex_scheduler_index;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_READ(block_index, entry, scheduler_slot_index);
    if (dir == rdpa_dir_ds && !complex_scheduler_info[dir][complex_scheduler_index].type)
        block_index += QM_QUEUE_DS_START;

    rc = rdd_scheduling_scheduler_block_cfg(dir, block_index, &block_cfg,
        complex_scheduler_info[dir][complex_scheduler_index].type, 0);

    return rc;
}

/* API to block */
bdmf_error_t rdd_complex_scheduler_rate_set(rdpa_traffic_dir dir, uint8_t complex_scheduler_index, uint32_t block_bit_mask)
{
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *entry;
    uint32_t budget;

    RDD_BTRACE("dir = %d, complex_scheduler_index = %d, block_bit_mask = %d\n",
        dir, complex_scheduler_index, block_bit_mask);

    if (complex_scheduler_index >= RDD_COMPLEX_SCHEDULER_TABLE_SIZE)
    {
        return BDMF_ERR_PARM;
    }

    if (dir == rdpa_dir_ds)
        entry = ((RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + complex_scheduler_index;
    else
        entry = ((RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS *)RDD_COMPLEX_SCHEDULER_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + complex_scheduler_index;

    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_READ(budget, entry);
    budget |= block_bit_mask;
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_WRITE(budget, entry);
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_1_READ(budget, entry);
    budget |= block_bit_mask;
    RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_1_WRITE(budget, entry);

    return BDMF_ERR_OK;
}

