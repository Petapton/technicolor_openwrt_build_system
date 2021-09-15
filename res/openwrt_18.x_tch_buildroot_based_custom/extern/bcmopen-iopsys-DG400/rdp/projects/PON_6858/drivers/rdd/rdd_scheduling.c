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

#include "rdd_scheduling.h"
#include "rdp_drv_rnr.h"
#include "rdd_basic_rate_limiter.h"
#include "rdd_ghost_reporting.h"

uint32_t exponent_list[] = {0, 3, 6, 9};

extern rdd_bb_id rdpa_emac_to_bb_id_tx[rdpa_emac__num_of];
extern bdmf_error_t rdd_complex_scheduler_rate_set(rdpa_traffic_dir dir, uint8_t complex_scheduler_index, uint32_t block_bit_mask);
extern bdmf_error_t rdd_basic_scheduler_rate_set(rdpa_traffic_dir dir, uint8_t basic_scheduler_index, uint8_t queue_bit_mask);

void rdd_bbh_queue_init(void)
{
    RDD_BBH_QUEUE_DESCRIPTOR_DTS *entry;
    int i;

    RDD_BTRACE("\n");
    /* init all tconts to bbh-tx wan */
    for (i = 0; i < RDD_IMAGE_3_BBH_QUEUE_TABLE_SIZE; ++i)
    {
        entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + i;
        RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_PON_ETH_PD, entry);
    }

#ifndef XRDP_BBH_PER_LAN_PORT
    for (i = 0; i < RDD_IMAGE_0_BBH_QUEUE_TABLE_SIZE; ++i)
    {
        entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + i;
        RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_LAN, entry);
    }
    rdd_ag_ds_tm_bb_destination_table_set(BB_ID_TX_LAN);
#else
    /* init lan0 */
    entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image)));
#ifdef BCM6858_B0
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC1_0_RGMII, entry);
#else
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC0_0_10G, entry);
#endif

    /* init lan1 */
    entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + 1;
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC0_1_2P5G, entry);

    /* init lan2 */
    entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + 2;
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC0_2_1G, entry);

    /* init lan3 */
    entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + 3;
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC0_3_1G, entry);

    /* init lan4 */
    entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + 4;
#ifdef BCM6858_B0
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC0_0_10G, entry);
#else
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC1_0_RGMII, entry);
#endif

    /* init lan5 */
    entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + 5;
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC1_1_RGMII, entry);

    /* init lan6 */
    entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + 6;
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC1_2_RGMII, entry);

#ifdef BCM6858_B0
    /* init lan7 */
    entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + 7;
    RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(BB_ID_TX_XLMAC1_3_RGMII, entry);
#endif
#endif
}

bdmf_error_t rdd_tm_epon_cfg(void)
{
    bdmf_error_t rc = BDMF_ERR_OK;
    uint32_t llid;
    rdd_scheduling_queue_descriptor_t cfg = {};
    cfg.enable = 1;

    RDD_BTRACE("\n");
    for (llid = 0; (!rc) && (llid < MAX_NUM_OF_LLID); ++llid)
    {
        cfg.bbh_queue_index = llid;
        rc = rc ? rc : rdd_scheduling_scheduler_block_cfg(rdpa_dir_us, llid + QM_QUEUE_US_EPON_START, &cfg, 0, 0);
    }

    return rc;
}

bdmf_error_t rdd_scheduling_flush_timer_set(void)
{
    RDD_SCHEDULING_FLUSH_GLOBAL_CFG_DTS *entry;
    bdmf_error_t rc = BDMF_ERR_OK;

    RDD_BTRACE("\n");
    /* flush task - ds core */
    entry = RDD_SCHEDULING_FLUSH_GLOBAL_CFG_PTR(get_runner_idx(ds_tm_runner_image));
    RDD_BYTE_1_BITS_WRITE(FLUSH_TASK_TIMER_INTERVAL, entry);

    /* flush task - us core */
    entry = RDD_SCHEDULING_FLUSH_GLOBAL_CFG_PTR(get_runner_idx(us_tm_runner_image));
    RDD_BYTE_1_BITS_WRITE(FLUSH_TASK_TIMER_INTERVAL, entry);

    /* Make sure the timer configured before the cpu weakeup */
    WMB();

    rc = ag_drv_rnr_regs_cfg_cpu_wakeup_set(get_runner_idx(us_tm_runner_image), IMAGE_3_US_TM_FLUSH_THREAD_NUMBER);
    rc = rc ? rc : ag_drv_rnr_regs_cfg_cpu_wakeup_set(get_runner_idx(ds_tm_runner_image), IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER);

    return rc;
}

bdmf_error_t rdd_us_budget_allocation_timer_set(void)
{
    RDD_BUDGET_ALLOCATION_TIMER_VALUE_DTS *entry;
    bdmf_error_t rc = BDMF_ERR_OK;

    RDD_BTRACE("\n");
    /* budget allocation task - us core */
    entry = RDD_BUDGET_ALLOCATION_TIMER_VALUE_PTR(get_runner_idx(us_tm_runner_image));
    RDD_BYTES_2_BITS_WRITE(RATE_LIMITER_TIMER_PERIOD, entry);

    /* Make sure the timer configured before the cpu weakeup */
    WMB();

    rc = ag_drv_rnr_regs_cfg_cpu_wakeup_set(get_runner_idx(us_tm_runner_image), IMAGE_3_US_TM_BUDGET_ALLOCATION_THREAD_NUMBER);
    rc = rc ? rc : ag_drv_rnr_regs_cfg_cpu_wakeup_set(get_runner_idx(us_tm_runner_image), IMAGE_3_US_TM_OVL_BUDGET_ALLOCATION_THREAD_NUMBER);

    return rc;
}

bdmf_error_t rdd_ds_budget_allocation_timer_set(void)
{
    RDD_BUDGET_ALLOCATION_TIMER_VALUE_DTS *entry;
    bdmf_error_t rc = BDMF_ERR_OK;

    RDD_BTRACE("\n");
    /* budget allocation task - ds core */
    entry = RDD_BUDGET_ALLOCATION_TIMER_VALUE_PTR(get_runner_idx(ds_tm_runner_image));
    RDD_BYTES_2_BITS_WRITE(RATE_LIMITER_TIMER_PERIOD, entry);

    /* Make sure the timer configured before the cpu weakeup */
    WMB();

    rc = ag_drv_rnr_regs_cfg_cpu_wakeup_set(get_runner_idx(ds_tm_runner_image), IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER);

    return rc;
}

/* API to RDPA level */
void rdd_set_queue_enable(uint32_t qm_queue_index, bdmf_boolean enable)
{
    uint32_t q_vec;

    RDD_BTRACE("set queue %d threshold\n", qm_queue_index);

    /* set/clear the queue in the threshold vector */
    RDD_BYTES_4_BITS_READ(q_vec, (((RDD_BYTES_4_DTS *)RDD_QUEUE_THRESHOLD_VECTOR_PTR(get_runner_idx(cpu_tx_runner_image))) +
        (qm_queue_index >> 5)));
    if (enable)
        q_vec |= (1 << (qm_queue_index & 0x1f));
    else
        q_vec &= (~(1 << (qm_queue_index & 0x1f)));
    RDD_BYTES_4_BITS_WRITE_G(q_vec, RDD_QUEUE_THRESHOLD_VECTOR_ADDRESS_ARR, (qm_queue_index >> 5));
}

bdmf_error_t rdd_scheduling_scheduler_block_cfg(rdpa_traffic_dir dir, uint8_t qm_queue_index,
    rdd_scheduling_queue_descriptor_t *scheduler_cfg, bdmf_boolean type, uint8_t dwrr_offset)
{
    RDD_BTRACE("dir = %d, qm_queue_index = %d, type = %d, scheduler_cfg %p = { scheduler_index = %d, bit_mask = %x, "
        "bbh_queue = %d, scheduler_type = %d }\n",
        dir, qm_queue_index, type, scheduler_cfg,
        scheduler_cfg->scheduler_index, scheduler_cfg->queue_bit_mask, scheduler_cfg->bbh_queue_index,
        scheduler_cfg->block_type);

    if (type)
        return rdd_basic_scheduler_block_cfg(dir, qm_queue_index, scheduler_cfg, dwrr_offset);
    else
    {
        if (dir == rdpa_dir_ds)
            return rdd_ag_ds_tm_scheduling_queue_descriptor_set(qm_queue_index - QM_QUEUE_DS_START, scheduler_cfg);
        rdd_ghost_reporting_mapping_queue_to_wan_channel((qm_queue_index - QM_QUEUE_US_START), scheduler_cfg->bbh_queue_index);
        return rdd_ag_us_tm_scheduling_queue_descriptor_set(qm_queue_index - QM_QUEUE_US_START, scheduler_cfg);    
    }
}

bdmf_error_t rdd_scheduling_queue_rate_limiter_remove(rdpa_traffic_dir dir, uint8_t qm_queue_index)
{
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS *entry;
    bdmf_boolean block_type;
    uint8_t block_index, bit_mask;
    bdmf_error_t rc;

    RDD_BTRACE("dir = %d, qm_queue_index = %d\n", dir, qm_queue_index);

    if (dir == rdpa_dir_ds)
    {
        entry = ((RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS *)RDD_SCHEDULING_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) +
            (qm_queue_index - QM_QUEUE_DS_START);
    }
    else
    {
        entry = ((RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS *)RDD_SCHEDULING_QUEUE_TABLE_PTR(get_runner_idx(us_tm_runner_image))) +
            (qm_queue_index - QM_QUEUE_US_START);
    }

    RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE(0, entry);

    /* make sure the queue has budget in scheduler */
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_READ(block_type, entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ(block_index, entry);
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_READ(bit_mask, entry);
    if (block_type)
        rc = rdd_complex_scheduler_rate_set(dir, block_index, (1 << bit_mask));
    else
        rc = rdd_basic_scheduler_rate_set(dir, block_index, bit_mask);

    return rc;
}

static uint8_t rdd_ds_tm_debug_sched_index_get(rdpa_emac emac)
{
    uint8_t sched_index;

    RDD_BBH_QUEUE_DESCRIPTOR_DTS *entry = ((RDD_BBH_QUEUE_DESCRIPTOR_DTS *)RDD_BBH_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + emac;
    RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ(sched_index, entry);

    return sched_index;
}

static uint32_t rdd_ds_tm_debug_rl_rate_get(uint8_t rl_index)
{
    uint32_t man, exp;
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS *entry = ((RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS *)RDD_BASIC_RATE_LIMITER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + rl_index;

    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_READ(exp, entry);
    RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_READ(man, entry);

    return (8 * ((man << (exp * exponent_list[1])) * RATE_LIMITER_TIMER_PERIOD));
}

void rdd_ds_tm_debug_get(rdpa_emac emac, rdd_tm_bs_info *info)
{
    uint8_t bbh_queue, i, basic_scheduler_index = rdd_ds_tm_debug_sched_index_get(emac);
    RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS *entry = ((RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS *)RDD_BASIC_SCHEDULER_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + basic_scheduler_index;
    RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS *base_queue_entry = ((RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS *)RDD_SCHEDULING_QUEUE_TABLE_PTR(get_runner_idx(ds_tm_runner_image)));

    info->sched_index = basic_scheduler_index;
    RDD_BASIC_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_READ(info->dwrr_offset, entry);
    RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_READ(info->sched_rl.rl_en, entry);
    RDD_BASIC_SCHEDULER_DESCRIPTOR_BBH_QUEUE_READ(bbh_queue, entry);
    if (bbh_queue == rdpa_emac_to_bb_id_tx[emac])
        info->enable = 1;
    else
        info->enable = 0;
    
    info->sched_rl.rl_rate = rdd_ds_tm_debug_rl_rate_get(info->sched_rl.rl_index);

    for (i = 0; i < BASIC_SCHEDULER_NUM_OF_QUEUES; i++)
    {
        RDD_BASIC_SCHEDULER_DESCRIPTOR_QUEUE_INDEX_READ(info->queue_info[i].queue_index, entry, i);
        RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_READ(info->queue_info[i].queue_rl.rl_en, (base_queue_entry + info->queue_info[i].queue_index));
        RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_READ(info->queue_info[i].queue_rl.rl_index, (base_queue_entry + info->queue_info[i].queue_index));
        RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_READ(info->queue_info[i].queue_bit_mask , (base_queue_entry + info->queue_info[i].queue_index));
        RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_READ(info->queue_info[i].queue_weight , (base_queue_entry + info->queue_info[i].queue_index));
        info->queue_info[i].queue_rl.rl_rate = rdd_ds_tm_debug_rl_rate_get(info->queue_info[i].queue_rl.rl_index);
        info->queue_info[i].queue_index += QM_QUEUE_DS_START;
    }
}

#ifdef G9991
static int rdd_g9991_emac_id_to_port_mask_idx(rdpa_emac emac)
{
    RDD_BYTE_1_DTS *entry;
    uint8_t i, bb_id;
    int idx = -1;

    RDD_BTRACE("emac = %d\n", emac);

    entry = (RDD_BYTE_1_DTS *)RDD_G9991_PHYS_PORT_BB_ID_TABLE_PTR(get_runner_idx(ds_tm_runner_image));

    for (i = 0; i < RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_SIZE; i++)
    {
        RDD_BYTE_1_BITS_READ(bb_id, entry + i);
        if (bb_id == (rdpa_emac_to_bb_id_tx[emac]))
            return i;
    }

    return idx;
}

int rdd_g9991_control_sid_set(rdd_rdd_vport vport, rdpa_emac emac)
{
    int mask_idx, rc;
    unsigned int sid_bit_mask;
    static uint8_t first_time[4] = {1, 1, 1, 1};

    RDD_BTRACE("vport = %d, emac = %d\n", vport, emac);

    mask_idx = rdd_g9991_emac_id_to_port_mask_idx(emac);

    if ((vport >= RDD_VPORT_ID_32) || (mask_idx < 0))
        return BDMF_ERR_NOT_SUPPORTED;

    if (first_time[mask_idx]) {
       sid_bit_mask = 0;
       first_time[mask_idx] = 0;
       rc = 0;
    }
    else
       rc = rdd_ag_ds_tm_g9991_control_sid_table_get(mask_idx, &sid_bit_mask);

    rc = rc ? rc : rdd_ag_ds_tm_g9991_control_sid_table_set(mask_idx, sid_bit_mask | (1 << vport));

    return rc;
}

int rdd_g9991_vport_to_emac_mapping_cfg(rdd_rdd_vport vport, rdpa_emac emac)
{
    RDD_BYTES_4_DTS *entry;
    uint32_t port_mask, i;
    int mask_idx;

    RDD_BTRACE("vport = %d, emac = %d\n", vport, emac);

    entry = (RDD_BYTES_4_DTS *)RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_PTR(get_runner_idx(ds_tm_runner_image));

    /* TODO: currently only 32 vports are supported */
    mask_idx = rdd_g9991_emac_id_to_port_mask_idx(emac);
    if ((vport >= RDD_VPORT_ID_32) || (mask_idx < 0))
    {
        return BDMF_ERR_NOT_SUPPORTED;
    }

    /* removes last configuration and write the new configuration of vport */
    for (i = 0; i < RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_SIZE; i++)
    {
        RDD_BYTES_4_BITS_READ(port_mask, (entry + i));
        if (i == mask_idx)
            port_mask |= (1 << vport);
        else
            port_mask &= ~(1 << vport);
        RDD_BYTES_4_BITS_WRITE(port_mask, (entry + i));
    }

    return BDMF_ERR_OK;
}

uint32_t rdd_g9991_thread_number_get(rdpa_emac emac, uint32_t mask)
{
    uint32_t thread_num, bit_mask;

    bit_mask = (((1 << emac) - 1) & mask);
    thread_num = asserted_bits_count_get(bit_mask);

    return (IMAGE_0_DS_TM_FRAG0_THREAD_NUMBER + thread_num);
}
#endif
