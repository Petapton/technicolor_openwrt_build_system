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

#include "rdd.h"
#include "rdd_defs.h"
#include "rdd_init.h"
#ifndef G9991
#include "rdd_tunnels_parsing.h"
#endif

#include "rdd_iptv_processing.h"
#include "rdd_qos_mapper.h"
#include "XRDP_AG.h"
#include "rdd_map_auto.h"
#include "rdd_ghost_reporting.h"
#include "rdd_scheduling.h"
#include "rdd_common.h"
#include "rdd_cpu.h"
#include "rdp_common.h"
#include "rdd_tuple_lkp.h"
#include "rdd_runner_proj_defs.h"
#ifndef _CFE_
#ifdef CONFIG_DHD_RUNNER
#include "rdd_dhd_helper.h"
#include "rdp_drv_dhd.h"
#endif
#include "rdd_tcam_ic.h"
#include "rdd_ingress_filter.h"
#include "rdd_iptv.h"
#include "rdd_dscp_to_pbit.h"
#include "rdd_bridge.h"
#include "rdp_drv_rnr.h"
#endif

extern uintptr_t xrdp_virt2phys(const ru_block_rec *ru_block, uint8_t addr_idx);
static void rdd_proj_init(rdd_init_params_t *init_params);
static void rdd_actions_proj_init(void);
static void rdd_tm_actions_proj_init(void);
static void rdd_tcam_cmd_init(void);

#ifdef RDP_SIM
extern uint8_t *soc_base_address;
extern uint32_t natc_lkp_table_ptr;
extern int rdd_sim_alloc_segments(void);
extern void rdd_sim_free_segments(void);
#endif

extern int reg_id[32];
#ifndef _CFE_
DEFINE_BDMF_FASTLOCK(int_lock);
DEFINE_BDMF_FASTLOCK(iptv_lock);
DEFINE_BDMF_FASTLOCK(int_lock_irq);
#endif

#ifdef USE_BDMF_SHELL
extern int rdd_make_shell_commands(void);
#endif /* USE_BDMF_SHELL */

rdd_bb_id rdpa_emac_to_bb_id_rx[rdpa_emac__num_of] = {
#ifdef BCM6858_B0
    BB_ID_RX_XLMAC1_0_RGMII,
    BB_ID_RX_XLMAC0_1_2P5G,
    BB_ID_RX_XLMAC0_2_1G,
    BB_ID_RX_XLMAC0_3_1G,
    BB_ID_RX_XLMAC0_0_10G,
#else
    BB_ID_RX_XLMAC0_0_10G,
    BB_ID_RX_XLMAC0_1_2P5G,
    BB_ID_RX_XLMAC0_2_1G,
    BB_ID_RX_XLMAC0_3_1G,
    BB_ID_RX_XLMAC1_0_RGMII,
#endif
    BB_ID_RX_XLMAC1_1_RGMII,
    BB_ID_RX_XLMAC1_2_RGMII,
    BB_ID_LAST,
};

rdd_bb_id rdpa_emac_to_bb_id_tx[rdpa_emac__num_of] = {
#ifdef BCM6858_B0
    BB_ID_TX_XLMAC1_0_RGMII,
    BB_ID_TX_XLMAC0_1_2P5G,
    BB_ID_TX_XLMAC0_2_1G,
    BB_ID_TX_XLMAC0_3_1G,
    BB_ID_TX_XLMAC0_0_10G,
#else
    BB_ID_TX_XLMAC0_0_10G,
    BB_ID_TX_XLMAC0_1_2P5G,
    BB_ID_TX_XLMAC0_2_1G,
    BB_ID_TX_XLMAC0_3_1G,
    BB_ID_TX_XLMAC1_0_RGMII,
#endif
    BB_ID_TX_XLMAC1_1_RGMII,
    BB_ID_TX_XLMAC1_2_RGMII,
    BB_ID_LAST,
};

bbh_id_e rdpa_emac_to_bbh_id_e[rdpa_emac__num_of] = {
#ifdef BCM6858_B0
    BBH_ID_XLMAC1_0_RGMII,
    BBH_ID_XLMAC0_1_2p5G,
    BBH_ID_XLMAC0_2_1G,
    BBH_ID_XLMAC0_3_1G,
    BBH_ID_XLMAC0_0_10G,
#else
    BBH_ID_XLMAC0_0_10G,
    BBH_ID_XLMAC0_1_2p5G,
    BBH_ID_XLMAC0_2_1G,
    BBH_ID_XLMAC0_3_1G,
    BBH_ID_XLMAC1_0_RGMII,
#endif
    BBH_ID_XLMAC1_1_RGMII,
    BBH_ID_XLMAC1_2_RGMII,
    BBH_ID_NULL,
};

#ifndef G9991
rdd_vport_id_t rx_flow_to_vport[RX_FLOW_CONTEXTS_NUMBER] = {
    [0 ... RDD_MAX_WAN_FLOW]  = RDD_WAN0_VPORT,
#ifdef BCM6858_B0
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC1_0_RGMII] = RDD_LAN0_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC0_1_2P5G] = RDD_LAN1_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC0_2_1G] = RDD_LAN2_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC0_3_1G] = RDD_LAN3_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC0_0_10G] = RDD_LAN4_VPORT,
#else
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC0_0_10G] = RDD_LAN0_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC0_1_2P5G] = RDD_LAN1_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC0_2_1G] = RDD_LAN2_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC0_3_1G] = RDD_LAN3_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC1_0_RGMII] = RDD_LAN4_VPORT,
#endif
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC1_1_RGMII] = RDD_LAN5_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_RX_XLMAC1_2_RGMII] = RDD_LAN6_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_CPU0] = RDD_CPU0_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_CPU1] = RDD_CPU1_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + BB_ID_CPU2] = RDD_CPU2_VPORT,
};
#else
rdd_vport_id_t rx_flow_to_vport[RX_FLOW_CONTEXTS_NUMBER] = {
    [0 ... RDD_MAX_WAN_FLOW]  = RDD_WAN0_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN0_VPORT ] = RDD_LAN0_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN1_VPORT ] = RDD_LAN1_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN2_VPORT ] = RDD_LAN2_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN3_VPORT ] = RDD_LAN3_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN4_VPORT ] = RDD_LAN4_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN5_VPORT ] = RDD_LAN5_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN6_VPORT ] = RDD_LAN6_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN7_VPORT ] = RDD_LAN7_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN8_VPORT ] = RDD_LAN8_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN9_VPORT ] = RDD_LAN9_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN10_VPORT ] = RDD_LAN10_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN11_VPORT ] = RDD_LAN11_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN12_VPORT ] = RDD_LAN12_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN13_VPORT ] = RDD_LAN13_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN14_VPORT ] = RDD_LAN14_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN15_VPORT ] = RDD_LAN15_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN16_VPORT ] = RDD_LAN16_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN17_VPORT ] = RDD_LAN17_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN18_VPORT ] = RDD_LAN18_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN19_VPORT ] = RDD_LAN19_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN20_VPORT ] = RDD_LAN20_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN21_VPORT ] = RDD_LAN21_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN22_VPORT ] = RDD_LAN22_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN23_VPORT ] = RDD_LAN23_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN24_VPORT ] = RDD_LAN24_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN25_VPORT ] = RDD_LAN25_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN26_VPORT ] = RDD_LAN26_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN27_VPORT ] = RDD_LAN27_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN28_VPORT ] = RDD_LAN28_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN29_VPORT ] = RDD_LAN29_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN30_VPORT ] = RDD_LAN30_VPORT,
    [RDD_NUM_OF_WAN_FLOWS + RDD_LAN31_VPORT ] = RDD_LAN31_VPORT,
};
#endif

rdpa_emac bbh_id_to_rdpa_emac[BBH_ID_NUM] = {
#ifdef BCM6858_B0
    rdpa_emac4,
    rdpa_emac1,
    rdpa_emac2,
    rdpa_emac3,
    rdpa_emac0,
    rdpa_emac5,
    rdpa_emac6,
    rdpa_emac7,
#else
    rdpa_emac0,
    rdpa_emac1,
    rdpa_emac2,
    rdpa_emac3,
    rdpa_emac4,
    rdpa_emac5,
    rdpa_emac6,
#endif
    rdpa_emac_none
};

extern RDD_FPM_GLOBAL_CFG_DTS g_fpm_hw_cfg;

int rdd_init(void)
{
#ifdef RDP_SIM
    if (rdd_sim_alloc_segments())
        return -1;
#endif
    return 0;
}

void rdd_exit(void)
{
#ifdef RDP_SIM
    rdd_sim_free_segments();
#endif
}

#ifndef RDP_SIM
void rdp_rnr_write_context(void *__to, void *__from, unsigned int __n);
#endif

static void rdd_global_registers_init(void)
{
    static uint32_t global_regs[8] = {};
    uint32_t i;

    /********** common to all runners **********/
    global_regs[1] = 1; /* R1 = 1 */

    global_regs[2] = IMAGE_2_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS;

#ifdef BCM6858_A0
    global_regs[3] |= (1 << GLOBAL_CFG_REG_IS_6858A0);
#endif

    for (i = 0; i < 8; ++i)
        RDD_BYTES_4_BITS_WRITE_G(global_regs[i], RDD_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS_ARR, i);
}

static void image_0_context_set(uint32_t core_index, rdd_init_params_t *init_params)
{
    static uint32_t local_regs[NUM_OF_MAIN_RUNNER_THREADS][32];
    uint32_t mem_cntxt_byte_num;
    uint32_t *sram_context;

    sram_context = (uint32_t *)RUNNER_CORE_CONTEXT_ADDRESS(core_index);
    mem_cntxt_byte_num = (RU_REG_RAM_CNT(RNR_CNTXT, MEM_ENTRY) + 1) * sizeof(uint32_t);
#ifndef XRDP_EMULATION
    /* read the local registers from the Context memory - maybe it was initialized by the ACE compiler */
    MREAD_BLK_32(local_regs, sram_context, mem_cntxt_byte_num);
#endif
#ifndef G9991
    /* Budget allocation: thread 0 */
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, budget_allocator_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[12]] = IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[13]] = (RDD_BASIC_RATE_LIMITER_TABLE_SIZE / 4) * sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS);
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[10]] = IMAGE_0_RATE_LIMITER_VALID_TABLE_ADDRESS;
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[9]]  = IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* UPDATE_FIFO_READ: thread 1 */
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, update_fifo_read_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[14]] = IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS | (IMAGE_0_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[12]] = (IMAGE_0_PD_FIFO_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_0_UPDATE_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[10]] = BB_ID_QM_RNR_GRID | (IMAGE_0_BBH_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[9]]  = IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* FLUSH TASK: thread 2 */
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, flush_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[12]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[11]] = IMAGE_0_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS;
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[10]] = (BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_DS_TM_FLUSH << 6));
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[9]] = IMAGE_0_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS;
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[8]] = xrdp_virt2phys(&RU_BLK(QM), 0) + RU_REG_OFFSET(QM, GLOBAL_CFG_AGGREGATION_CONTEXT_VALID) +
        (QM_QUEUE_DS_START / 8);

    /* SCHEDULING LAN 0: thread 4 */
    local_regs[IMAGE_0_DS_TM_LAN0_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_LAN0_THREAD_NUMBER][reg_id[12]] = (IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS << 16);
#ifdef BCM6858_B0
    local_regs[IMAGE_0_DS_TM_LAN0_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC1_0_RGMII | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
#else
    local_regs[IMAGE_0_DS_TM_LAN0_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC0_0_10G | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
#endif
    local_regs[IMAGE_0_DS_TM_LAN0_THREAD_NUMBER][reg_id[10]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN0_THREAD_NUMBER][reg_id[9]] = (IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN0_THREAD_NUMBER][reg_id[8]]  = IMAGE_0_BBH_QUEUE_TABLE_ADDRESS | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* SCHEDULING LAN 1: thread 5 */
    local_regs[IMAGE_0_DS_TM_LAN1_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_LAN1_THREAD_NUMBER][reg_id[12]] = ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + 1*sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_LAN1_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC0_1_2P5G | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN1_THREAD_NUMBER][reg_id[10]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN1_THREAD_NUMBER][reg_id[9]]  = (IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN1_THREAD_NUMBER][reg_id[8]]  = (IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS))
        | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* SCHEDULING LAN 2: thread 6 */
    local_regs[IMAGE_0_DS_TM_LAN2_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_LAN2_THREAD_NUMBER][reg_id[12]] = ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + 2*sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_LAN2_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC0_2_1G | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN2_THREAD_NUMBER][reg_id[10]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN2_THREAD_NUMBER][reg_id[9]]  = (IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN2_THREAD_NUMBER][reg_id[8]]  = (IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (2 * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)))
        | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* SCHEDULING LAN 3: thread 7 */
    local_regs[IMAGE_0_DS_TM_LAN3_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_LAN3_THREAD_NUMBER][reg_id[12]] = ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + 3*sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_LAN3_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC0_3_1G | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN3_THREAD_NUMBER][reg_id[10]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN3_THREAD_NUMBER][reg_id[9]]  = (IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN3_THREAD_NUMBER][reg_id[8]]  = (IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (3 * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)))
        | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* SCHEDULING LAN 4: thread 8 */
    local_regs[IMAGE_0_DS_TM_LAN4_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_LAN4_THREAD_NUMBER][reg_id[12]] = ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + 4*sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
#ifdef BCM6858_B0
    local_regs[IMAGE_0_DS_TM_LAN4_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC0_0_10G | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
#else
    local_regs[IMAGE_0_DS_TM_LAN4_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC1_0_RGMII | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
#endif
    local_regs[IMAGE_0_DS_TM_LAN4_THREAD_NUMBER][reg_id[10]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN4_THREAD_NUMBER][reg_id[9]]  = (IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN4_THREAD_NUMBER][reg_id[8]]  = (IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (4 * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)))
        | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* SCHEDULING LAN 5: thread 9 */
    local_regs[IMAGE_0_DS_TM_LAN5_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_LAN5_THREAD_NUMBER][reg_id[12]] = ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + 5*sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_LAN5_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC1_1_RGMII | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN5_THREAD_NUMBER][reg_id[10]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN5_THREAD_NUMBER][reg_id[9]]  = (IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN5_THREAD_NUMBER][reg_id[8]]  = (IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (5 * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)))
        | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* SCHEDULING LAN 6: thread 10 */
    local_regs[IMAGE_0_DS_TM_LAN6_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_LAN6_THREAD_NUMBER][reg_id[12]] = ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + 6*sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_LAN6_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC1_2_RGMII | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN6_THREAD_NUMBER][reg_id[10]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN6_THREAD_NUMBER][reg_id[9]]  = (IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_LAN6_THREAD_NUMBER][reg_id[8]]  = (IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (6 * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)))
        | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);
#else
    /* G9991 FLOW CONTROL: thread 0 */
    local_regs[IMAGE_0_DS_TM_FLOW_CONTROL_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, g9991_flow_control_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_FLOW_CONTROL_THREAD_NUMBER][reg_id[15]] = IMAGE_0_DS_TM_FLOW_CONTROL_THREAD_NUMBER;
    local_regs[IMAGE_0_DS_TM_FLOW_CONTROL_THREAD_NUMBER][reg_id[14]] = BB_ID_SBPM;
    local_regs[IMAGE_0_DS_TM_FLOW_CONTROL_THREAD_NUMBER][reg_id[13]] = BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_0_DS_TM_FLOW_CONTROL_THREAD_NUMBER][reg_id[12]] = IMAGE_0_G9991_FLOW_CONTROL_PACKET_HEDAER_ADDRESS;

    /* Budget allocation: thread 1 */
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, budget_allocator_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[13]] = (RDD_BASIC_RATE_LIMITER_TABLE_SIZE / 4) * sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS);
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[12]] = IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[10]] = IMAGE_0_RATE_LIMITER_VALID_TABLE_ADDRESS;
    local_regs[IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[9]]  = IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* UPDATE_FIFO_READ: thread 2 */
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, update_fifo_read_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[14]] = IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS | (IMAGE_0_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[13]] = (((IMAGE_0_DS_TM_SCHEDULING_TASK_THREAD_NUMBER) << 4) + 1);
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_0_UPDATE_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[10]] = BB_ID_QM_RNR_GRID | (IMAGE_0_BBH_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[9]]  = IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* FLUSH TASK: thread 3 */
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, flush_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[12]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[11]] = IMAGE_0_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS;
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[10]] = (BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_DS_TM_FLUSH << 6));
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[9]] = IMAGE_0_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS;
    local_regs[IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER][reg_id[8]] = xrdp_virt2phys(&RU_BLK(QM), 0) + RU_REG_OFFSET(QM, GLOBAL_CFG_AGGREGATION_CONTEXT_VALID) +
        (QM_QUEUE_DS_START / 8);

    /* SCHEDULING TASK: thread 4 */
    local_regs[IMAGE_0_DS_TM_SCHEDULING_TASK_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_SCHEDULING_TASK_THREAD_NUMBER][reg_id[12]] = IMAGE_0_G9991_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_SCHEDULING_TASK_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_XLMAC0_0_10G | (IMAGE_0_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_SCHEDULING_TASK_THREAD_NUMBER][reg_id[10]] = IMAGE_0_PD_FIFO_TABLE_ADDRESS | (IMAGE_0_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_SCHEDULING_TASK_THREAD_NUMBER][reg_id[9]]  = (IMAGE_0_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_SCHEDULING_TASK_THREAD_NUMBER][reg_id[8]]  = IMAGE_0_BBH_QUEUE_TABLE_ADDRESS | (IMAGE_0_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* Fragmentation 0: thread 5 */
    local_regs[IMAGE_0_DS_TM_FRAG0_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, g9991_tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_FRAG0_THREAD_NUMBER][reg_id[14]] = IMAGE_0_G9991_CONTROL_SID_TABLE_ADDRESS;
    local_regs[IMAGE_0_DS_TM_FRAG0_THREAD_NUMBER][reg_id[13]] = MAX_FRAG_SIZE;
    local_regs[IMAGE_0_DS_TM_FRAG0_THREAD_NUMBER][reg_id[12]] = IMAGE_0_G9991_FIFO_DESCRIPTOR_TABLE_ADDRESS |
      (IMAGE_0_G9991_SID_TO_PHYSICAL_PORT_MASK_ADDRESS << 16);
    local_regs[IMAGE_0_DS_TM_FRAG0_THREAD_NUMBER][reg_id[11]] = IMAGE_0_G9991_PHYS_PORT_BB_ID_TABLE_ADDRESS |
        ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + (init_params->g9991_port[0]) * sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_FRAG0_THREAD_NUMBER][reg_id[10]] = IMAGE_0_G9991_PD_FIFO_TABLE_ADDRESS |
        ((IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (init_params->g9991_port[0]) * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)) << 16);

    /* Fragmentation 1: thread 6 */
    local_regs[IMAGE_0_DS_TM_FRAG1_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, g9991_tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_FRAG1_THREAD_NUMBER][reg_id[14]] = IMAGE_0_G9991_CONTROL_SID_TABLE_ADDRESS + 4;
    local_regs[IMAGE_0_DS_TM_FRAG1_THREAD_NUMBER][reg_id[13]] = MAX_FRAG_SIZE;
    local_regs[IMAGE_0_DS_TM_FRAG1_THREAD_NUMBER][reg_id[12]] = IMAGE_0_G9991_FIFO_DESCRIPTOR_TABLE_ADDRESS |
      ((IMAGE_0_G9991_SID_TO_PHYSICAL_PORT_MASK_ADDRESS + 4) << 16);
    local_regs[IMAGE_0_DS_TM_FRAG1_THREAD_NUMBER][reg_id[11]] = (IMAGE_0_G9991_PHYS_PORT_BB_ID_TABLE_ADDRESS + 1) |
      ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + (init_params->g9991_port[1]) * sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_FRAG1_THREAD_NUMBER][reg_id[10]] = IMAGE_0_G9991_PD_FIFO_TABLE_ADDRESS |
        ((IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (init_params->g9991_port[1]) * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)) << 16);

    /* Fragmentation 2: thread 7 */
    local_regs[IMAGE_0_DS_TM_FRAG2_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, g9991_tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_FRAG2_THREAD_NUMBER][reg_id[13]] = MAX_FRAG_SIZE;
    local_regs[IMAGE_0_DS_TM_FRAG2_THREAD_NUMBER][reg_id[12]] = IMAGE_0_G9991_FIFO_DESCRIPTOR_TABLE_ADDRESS |
      ((IMAGE_0_G9991_SID_TO_PHYSICAL_PORT_MASK_ADDRESS + 8) << 16);
    local_regs[IMAGE_0_DS_TM_FRAG2_THREAD_NUMBER][reg_id[11]] = (IMAGE_0_G9991_PHYS_PORT_BB_ID_TABLE_ADDRESS + 2) |
      ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + (init_params->g9991_port[2]) * sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_FRAG2_THREAD_NUMBER][reg_id[10]] = IMAGE_0_G9991_PD_FIFO_TABLE_ADDRESS |
        ((IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (init_params->g9991_port[2]) * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)) << 16);

    /* Fragmentation 3: thread 8 */
    local_regs[IMAGE_0_DS_TM_FRAG3_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_0, g9991_tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_0_DS_TM_FRAG3_THREAD_NUMBER][reg_id[13]] = MAX_FRAG_SIZE;
    local_regs[IMAGE_0_DS_TM_FRAG3_THREAD_NUMBER][reg_id[12]] = IMAGE_0_G9991_FIFO_DESCRIPTOR_TABLE_ADDRESS |
      ((IMAGE_0_G9991_SID_TO_PHYSICAL_PORT_MASK_ADDRESS + 12) << 16);
    local_regs[IMAGE_0_DS_TM_FRAG3_THREAD_NUMBER][reg_id[11]] = (IMAGE_0_G9991_PHYS_PORT_BB_ID_TABLE_ADDRESS + 3) |
      ((IMAGE_0_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS + (init_params->g9991_port[3]) * sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS)) << 16);
    local_regs[IMAGE_0_DS_TM_FRAG3_THREAD_NUMBER][reg_id[10]] = IMAGE_0_G9991_PD_FIFO_TABLE_ADDRESS |
        ((IMAGE_0_BBH_QUEUE_TABLE_ADDRESS + (init_params->g9991_port[3]) * sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS)) << 16);
#endif
#ifdef RDP_SIM
    /* copy the local registers initial values to the Context memory */
    MWRITE_BLK_32(sram_context, local_regs, mem_cntxt_byte_num);
#else
    rdp_rnr_write_context(sram_context, local_regs, mem_cntxt_byte_num);
#endif
}

static void image_1_context_set(uint32_t core_index)
{
    static uint32_t local_regs[NUM_OF_MAIN_RUNNER_THREADS][32];
    uint32_t mem_cntxt_byte_num;
    uint32_t *sram_context;

    sram_context = (uint32_t *)RUNNER_CORE_CONTEXT_ADDRESS(core_index);
    mem_cntxt_byte_num = (RU_REG_RAM_CNT(RNR_CNTXT, MEM_ENTRY) + 1) * sizeof(uint32_t);
#ifndef XRDP_EMULATION
    /* read the local registers from the Context memory - maybe it was initialized by the ACE compiler */
    MREAD_BLK_32(local_regs, sram_context, mem_cntxt_byte_num);
#endif

#ifdef G9991
    /* G9991 us processing : thread 0 */
    local_regs[IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER][reg_id[16]]  = IMAGE_1_G9991_PD_TABLE_ADDRESS | (ADDRESS_OF(image_1, g9991_reassembly_wakeup_request) << 16);
    local_regs[IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER][reg_id[14]]  = (DISP_REOR_VIQ_G9991_REASS0 << 6) |  BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER][reg_id[13]]  = BB_ID_SBPM;
    local_regs[IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER][reg_id[12]]  = IMAGE_1_G9991_US_SID_CONTEXT_TABLE_ADDRESS | (IMAGE_1_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS << 16);
    local_regs[IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER][reg_id[11]]  = BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER][reg_id[10]]  = (IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER << 6) |  BB_ID_DISPATCHER_REORDER;

    /* G9991 us processing : thread 1 */
    local_regs[IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER][reg_id[16]]  = (IMAGE_1_G9991_PD_TABLE_ADDRESS + 32) | (ADDRESS_OF(image_1, g9991_reassembly_wakeup_request) << 16);
    local_regs[IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER][reg_id[14]]  = (DISP_REOR_VIQ_G9991_REASS1 << 6) |  BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER][reg_id[13]]  = BB_ID_SBPM;
    local_regs[IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER][reg_id[12]]  = IMAGE_1_G9991_US_SID_CONTEXT_TABLE_ADDRESS | ((IMAGE_1_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS + 16) << 16);
    local_regs[IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER][reg_id[11]]  = BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER][reg_id[10]]  = (IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER << 6) |  BB_ID_DISPATCHER_REORDER;
    
    /* G9991 us processing : thread 2 */
    local_regs[IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER][reg_id[16]]  = (IMAGE_1_G9991_PD_TABLE_ADDRESS + 64) | (ADDRESS_OF(image_1, g9991_reassembly_wakeup_request) << 16);
    local_regs[IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER][reg_id[14]]  = (DISP_REOR_VIQ_G9991_REASS2 << 6) |  BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER][reg_id[13]]  = BB_ID_SBPM;
    local_regs[IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER][reg_id[12]]  = IMAGE_1_G9991_US_SID_CONTEXT_TABLE_ADDRESS | ((IMAGE_1_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS + 32) << 16);
    local_regs[IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER][reg_id[11]]  = BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER][reg_id[10]]  = (IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER << 6) |  BB_ID_DISPATCHER_REORDER;

    /* G9991 us processing : thread 3 */
    local_regs[IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER][reg_id[16]]  = (IMAGE_1_G9991_PD_TABLE_ADDRESS + 96) | (ADDRESS_OF(image_1, g9991_reassembly_wakeup_request) << 16);
    local_regs[IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER][reg_id[14]]  = (DISP_REOR_VIQ_G9991_REASS3 << 6) |  BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER][reg_id[13]]  = BB_ID_SBPM;
    local_regs[IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER][reg_id[12]]  = IMAGE_1_G9991_US_SID_CONTEXT_TABLE_ADDRESS | ((IMAGE_1_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS + 48) << 16);
    local_regs[IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER][reg_id[11]]  = BB_ID_DISPATCHER_REORDER;
    local_regs[IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER][reg_id[10]]  = (IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER << 6) |  BB_ID_DISPATCHER_REORDER;
#else
    /* DIRECT PROCESSING : thread 0 */
    local_regs[IMAGE_1_CPU_IF_1_WAN_DIRECT_THREAD_NUMBER][reg_id[9]] = IMAGE_1_RX_FLOW_TABLE_ADDRESS << 16 | IMAGE_1_CPU_IF_1_WAN_DIRECT_THREAD_NUMBER;
    local_regs[IMAGE_1_CPU_IF_1_WAN_DIRECT_THREAD_NUMBER][reg_id[10]] = BB_ID_DISPATCHER_REORDER;
#ifdef BCM6858_A0
    local_regs[IMAGE_1_CPU_IF_1_WAN_DIRECT_THREAD_NUMBER][reg_id[11]] = QM_QUEUE_CPU_RX | ( IMAGE_1_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS << 16 );
#else
    local_regs[IMAGE_1_CPU_IF_1_WAN_DIRECT_THREAD_NUMBER][reg_id[11]] = QM_QUEUE_CPU_RX_COPY_EXCLUSIVE | ( IMAGE_1_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS << 16 );
#endif    
#ifndef _CFE_
    local_regs[IMAGE_1_CPU_IF_1_WAN_DIRECT_THREAD_NUMBER][reg_id[16]] =
        ADDRESS_OF(image_1, gpon_control_wakeup_request) << 16 | IMAGE_1_DIRECT_PROCESSING_PD_TABLE_ADDRESS;
#else
    local_regs[IMAGE_1_CPU_IF_1_WAN_DIRECT_THREAD_NUMBER][reg_id[16]] =
        ADDRESS_OF(image_1, direct_processing_wakeup_request) << 16 | IMAGE_1_DIRECT_PROCESSING_PD_TABLE_ADDRESS;
#endif

    /* CPU_RX_FIFO_READ: thread 1 */
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, cpu_rx_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_THREAD_NUMBER][reg_id[14]] = IMAGE_1_CPU_RX_SCRATCHPAD_ADDRESS |
        (IMAGE_1_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS << 16);
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_THREAD_NUMBER][reg_id[12]] = IMAGE_1_CPU_RING_DESCRIPTORS_TABLE_ADDRESS;
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_THREAD_NUMBER][reg_id[11]] = IMAGE_1_PD_FIFO_TABLE_ADDRESS | (IMAGE_1_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS << 16);

    /* CPU_RX_UPDATE_FIFO_READ: thread 2 */
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, cpu_rx_update_fifo_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_UPDATE_FIFO_THREAD_NUMBER][reg_id[12]] = (((IMAGE_1_CPU_IF_1_CPU_RX_THREAD_NUMBER) << 4) + 9);
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_1_UPDATE_FIFO_TABLE_ADDRESS;

    /* CPU_RX_INTERRUPT_COALESCING: thread 3 */
    local_regs[IMAGE_1_CPU_IF_1_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, interrupt_coalescing_1st_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[13]] = IMAGE_1_CPU_INTERRUPT_COALESCING_TABLE_ADDRESS;
    local_regs[IMAGE_1_CPU_IF_1_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[12]] = IMAGE_1_CPU_RING_DESCRIPTORS_TABLE_ADDRESS | (IMAGE_1_CPU_RING_INTERRUPT_COUNTER_TABLE_ADDRESS << 16);

    /* CPU_RX_METER_BUDGET_ALLOCATOR: thread 4 */
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER][reg_id[16]] =
        ADDRESS_OF(image_1, cpu_rx_meter_budget_allocator_1st_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER][reg_id[11]] = CPU_RX_METER_TIMER_PERIOD;

#ifndef _CFE_
#ifdef CONFIG_DHD_RUNNER      
    /* DHD_TX_POST_0: thread 5 */
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_0_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, dhd_tx_post_wakeup_request) << 16;
    /* high = post_common_radio_ptr , low =radio_idx */
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_0_THREAD_NUMBER][reg_id[13]] = 0 | ((IMAGE_1_DHD_POST_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_POST_COMMON_RADIO_ENTRY_DTS)*0)) << 16;
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_0_THREAD_NUMBER][reg_id[12]] = 0;                                                        
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_0_THREAD_NUMBER][reg_id[11]] = IMAGE_1_DHD_TX_POST_PD_FIFO_TABLE_ADDRESS + sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS)*0;

    /* DHD_TX_POST_1: thread 6 */
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_1_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, dhd_tx_post_wakeup_request) << 16;
    /* high = post_common_radio_ptr , low =radio_idx */
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_1_THREAD_NUMBER][reg_id[13]] = 1 | ((IMAGE_1_DHD_POST_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_POST_COMMON_RADIO_ENTRY_DTS)*1)) << 16;
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_1_THREAD_NUMBER][reg_id[12]] = 0;                                                        
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_1_THREAD_NUMBER][reg_id[11]] = IMAGE_1_DHD_TX_POST_PD_FIFO_TABLE_ADDRESS + sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS)*4;
    
    /* DHD_TX_POST_2: thread 7 */
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_2_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, dhd_tx_post_wakeup_request) << 16;
    /* high = post_common_radio_ptr , low =radio_idx */
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_2_THREAD_NUMBER][reg_id[13]] = 2 | ((IMAGE_1_DHD_POST_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_POST_COMMON_RADIO_ENTRY_DTS)*2)) << 16;
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_2_THREAD_NUMBER][reg_id[12]] = 0;                                                        
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_2_THREAD_NUMBER][reg_id[11]] = IMAGE_1_DHD_TX_POST_PD_FIFO_TABLE_ADDRESS + sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS)*8;          
    
    /* DHD_TX_POST_UPDATE_FIFO_READ: thread 8 */
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, dhd_tx_post_update_fifo_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_UPDATE_FIFO_THREAD_NUMBER][reg_id[12]] = (((IMAGE_1_CPU_IF_1_DHD_TX_POST_0_THREAD_NUMBER) << 4) + 9);
    local_regs[IMAGE_1_CPU_IF_1_DHD_TX_POST_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_1_DHD_TX_POST_UPDATE_FIFO_TABLE_ADDRESS;
	
    /* DHD_TIMER_THREAD_NUMBER: thread 9 */
    local_regs[IMAGE_1_CPU_IF_1_DHD_TIMER_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, dhd_timer_1st_wakeup_request) << 16;

    /* DHD_MCAST: thread 10 */
    local_regs[IMAGE_1_CPU_IF_1_DHD_MCAST_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, dhd_mcast_wakeup_request) << 16;
    /* high = PD fifo bit ( = 0), low = DHD TX Post update fifo task number */
    local_regs[IMAGE_1_CPU_IF_1_DHD_MCAST_THREAD_NUMBER][reg_id[12]] = (((IMAGE_1_CPU_IF_1_DHD_TX_POST_UPDATE_FIFO_THREAD_NUMBER) << 4) + 9);                                           
    local_regs[IMAGE_1_CPU_IF_1_DHD_MCAST_THREAD_NUMBER][reg_id[11]] = IMAGE_1_DHD_MCAST_PD_FIFO_TABLE_ADDRESS;          

    /* DHD_MCAST_UPDATE_FIFO: thread 11 */
    local_regs[IMAGE_1_CPU_IF_1_DHD_MCAST_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, dhd_mcast_update_fifo_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_DHD_MCAST_UPDATE_FIFO_THREAD_NUMBER][reg_id[12]] = (((IMAGE_1_CPU_IF_1_DHD_MCAST_THREAD_NUMBER) << 4) + 9);
    local_regs[IMAGE_1_CPU_IF_1_DHD_MCAST_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_1_DHD_MCAST_UPDATE_FIFO_TABLE_ADDRESS;

#endif /* CONFIG_DHD_RUNNER */
#endif /* !CFE */
    /* CPU_RECYCLE: thread 12 */
    local_regs[IMAGE_1_CPU_IF_1_CPU_RECYCLE_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, cpu_recycle_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_CPU_RECYCLE_THREAD_NUMBER][reg_id[8]] = IMAGE_1_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS;

#ifndef BCM6858_A0
    /* CPU_RX_COPY_FIFO_READ: thread 13 */
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_COPY_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, cpu_rx_copy_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_COPY_THREAD_NUMBER][reg_id[14]] = IMAGE_1_CPU_RX_SCRATCHPAD_ADDRESS |
        (IMAGE_1_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS << 16);
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_COPY_THREAD_NUMBER][reg_id[12]] = 0;
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_COPY_THREAD_NUMBER][reg_id[11]] = (IMAGE_1_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS) | (IMAGE_1_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS << 16);

    /* CPU_RX_COPY_UPDATE_FIFO_READ: thread 14 */
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_1, cpu_rx_copy_update_fifo_wakeup_request) << 16;
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER][reg_id[12]] = (((IMAGE_1_CPU_IF_1_CPU_RX_COPY_THREAD_NUMBER) << 4) + 9);
    local_regs[IMAGE_1_CPU_IF_1_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_1_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS;
#endif
    
#endif /* G9991 */

#ifdef RDP_SIM
    /* copy the local registers initial values to the Context memory */
    MWRITE_BLK_32(sram_context, local_regs, mem_cntxt_byte_num);
#else
    rdp_rnr_write_context(sram_context, local_regs, mem_cntxt_byte_num);
#endif
}

static void image_2_context_set(uint32_t core_index)
{
    static uint32_t local_regs[NUM_OF_MAIN_RUNNER_THREADS][32];
    uint32_t mem_cntxt_byte_num;
    uint32_t *sram_context;

    sram_context = (uint32_t *)RUNNER_CORE_CONTEXT_ADDRESS(core_index);
    mem_cntxt_byte_num = (RU_REG_RAM_CNT(RNR_CNTXT, MEM_ENTRY) + 1) * sizeof(uint32_t);
#ifndef XRDP_EMULATION
    /* read the local registers from the Context memory - maybe it was initialized by the ACE compiler */
    MREAD_BLK_32(local_regs, sram_context, mem_cntxt_byte_num);
#endif

    /* CPU_RECYCLE: thread 0 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_RECYCLE_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_recycle_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_RECYCLE_THREAD_NUMBER][reg_id[8]] = IMAGE_2_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS;

    /* CPU_TX_UPDATE_FIFO_EGRESS: thread 1 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_EGRESS_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_tx_update_fifo_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_EGRESS_THREAD_NUMBER][reg_id[12]] = (((IMAGE_2_CPU_IF_2_CPU_TX_EGRESS_THREAD_NUMBER) << 4) + 9);
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_EGRESS_THREAD_NUMBER][reg_id[11]] = IMAGE_2_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_EGRESS_THREAD_NUMBER][reg_id[10]] = BB_ID_QM_RNR_GRID;
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_EGRESS_THREAD_NUMBER][reg_id[9]] = QM_QUEUE_CPU_TX_EGRESS;

    /* CPU_TX_UPDATE_FIFO_INGRESS: thread 2 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_INGRESS_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_tx_update_fifo_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_INGRESS_THREAD_NUMBER][reg_id[12]] = (((IMAGE_2_CPU_IF_2_CPU_TX_INGRESS_THREAD_NUMBER) << 4) + 9);
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_INGRESS_THREAD_NUMBER][reg_id[11]] = IMAGE_2_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_INGRESS_THREAD_NUMBER][reg_id[10]] = BB_ID_QM_RNR_GRID;
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_INGRESS_THREAD_NUMBER][reg_id[9]] = QM_QUEUE_CPU_TX_INGRESS;

    /* CPU_TX_EGRESS: thread 3 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_EGRESS_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_tx_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_EGRESS_THREAD_NUMBER][reg_id[10]] = IMAGE_2_CPU_IF_2_CPU_TX_EGRESS_THREAD_NUMBER | (IMAGE_2_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS << 16);
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_EGRESS_THREAD_NUMBER][reg_id[9]] = QM_QUEUE_CPU_TX_EGRESS | ((BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_CPU_TX_EGRESS << 6)) << 16);
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_EGRESS_THREAD_NUMBER][reg_id[8]] = IMAGE_2_CPU_TX_EGRESS_PD_FIFO_TABLE_ADDRESS;

    /* CPU_TX_INGRESS: thread 4 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_INGRESS_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_tx_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_INGRESS_THREAD_NUMBER][reg_id[10]] = IMAGE_2_CPU_IF_2_CPU_TX_INGRESS_THREAD_NUMBER | (IMAGE_2_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS << 16);
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_INGRESS_THREAD_NUMBER][reg_id[9]] = QM_QUEUE_CPU_TX_INGRESS | (((BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_CPU_TX_FORWARD << 6))) << 16);
    local_regs[IMAGE_2_CPU_IF_2_CPU_TX_INGRESS_THREAD_NUMBER][reg_id[8]] = IMAGE_2_CPU_TX_INGRESS_PD_FIFO_TABLE_ADDRESS;

    /* REPORTING : thread 5 */
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[17]] = XGPON_MAC_REPORT_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, ghost_reporting_1st_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[15]] = xrdp_virt2phys(&RU_BLK(QM), 0) + RU_REG_OFFSET(QM, TOTAL_VALID_COUNTER_COUNTER);
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[14]] = BB_ID_TX_PON_ETH_STAT;
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[13]] = IMAGE_2_REPORTING_QUEUE_DESCRIPTOR_TABLE_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[12]] = IMAGE_2_REPORTING_QUEUE_ACCUMULATED_TABLE_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[11]] = IMAGE_2_GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[10]] = xrdp_virt2phys(&RU_BLK(QM), 0) + RU_REG_OFFSET(QM, EPON_RPT_CNT_COUNTER);
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[9]] = xrdp_virt2phys(&RU_BLK(QM), 0) + RU_REG_OFFSET(QM, EPON_RPT_CNT_QUEUE_STATUS);
    local_regs[IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER][reg_id[8]] = IMAGE_2_REPORTING_COUNTER_TABLE_ADDRESS;

#ifndef G9991
    /* CPU_TX_INTERRUPT_COALESCING: thread 6 */
    local_regs[IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, interrupt_coalescing_1st_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[13]] = IMAGE_2_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[12]] = IMAGE_2_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS |
        (IMAGE_2_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_ADDRESS << 16);
#endif

#ifndef _CFE_
#ifdef CONFIG_DHD_RUNNER    
	/* DHD_TX_COMPLETE_0: thread 7 */
	local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_0_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, dhd_tx_complete_wakeup_request) << 16;
	local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_0_THREAD_NUMBER][reg_id[12]] = (IMAGE_2_DHD_COMPLETE_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS)*0);
    local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_0_THREAD_NUMBER][reg_id[11]] = 0;    
    
    /* DHD_TX_COMPLETE_1: thread 8 */
    local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_1_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, dhd_tx_complete_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_1_THREAD_NUMBER][reg_id[12]] = (IMAGE_2_DHD_COMPLETE_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS)*1);
    local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_1_THREAD_NUMBER][reg_id[11]] = 1;    

    /* DHD_TX_COMPLETE_2: thread 9 */
    local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_2_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, dhd_tx_complete_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_2_THREAD_NUMBER][reg_id[12]] = (IMAGE_2_DHD_COMPLETE_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS)*2);
    local_regs[IMAGE_2_CPU_IF_2_DHD_TX_COMPLETE_2_THREAD_NUMBER][reg_id[11]] = 2;
    

    /* DHD_RX_COMPLETE_0: thread 10 */
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_0_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, dhd_rx_complete_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_0_THREAD_NUMBER][reg_id[13]] = ((IMAGE_2_DHD_COMPLETE_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS)*0));
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_0_THREAD_NUMBER][reg_id[12]] = 0;
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_0_THREAD_NUMBER][reg_id[11]] = (BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_DHD_RX_COMPLETE_0 << 6));
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_0_THREAD_NUMBER][reg_id[10]] = 0;
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_0_THREAD_NUMBER][reg_id[9]] = IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_0_THREAD_NUMBER | (IMAGE_2_DHD_RX_COMPLETE_0_DISPATCHER_CREDIT_TABLE_ADDRESS << 16);
    
    /* DHD_RX_COMPLETE_1: thread 11 */
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_1_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, dhd_rx_complete_wakeup_request) << 16;    
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_1_THREAD_NUMBER][reg_id[13]] = ((IMAGE_2_DHD_COMPLETE_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS)*1));
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_1_THREAD_NUMBER][reg_id[12]] = 1;
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_1_THREAD_NUMBER][reg_id[11]] = (BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_DHD_RX_COMPLETE_1 << 6));
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_1_THREAD_NUMBER][reg_id[10]] = 0;
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_1_THREAD_NUMBER][reg_id[9]] = IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_1_THREAD_NUMBER | (IMAGE_2_DHD_RX_COMPLETE_1_DISPATCHER_CREDIT_TABLE_ADDRESS << 16);
    
    
    /* DHD_RX_COMPLETE_2: thread 12 */
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_2_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, dhd_rx_complete_wakeup_request) << 16;    
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_2_THREAD_NUMBER][reg_id[13]] = ((IMAGE_2_DHD_COMPLETE_COMMON_RADIO_DATA_ADDRESS + sizeof(RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS)*2));
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_2_THREAD_NUMBER][reg_id[12]] = 2;
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_2_THREAD_NUMBER][reg_id[11]] = (BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_DHD_RX_COMPLETE_2 << 6));
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_2_THREAD_NUMBER][reg_id[10]] = 0;
    local_regs[IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_2_THREAD_NUMBER][reg_id[9]] = IMAGE_2_CPU_IF_2_DHD_RX_COMPLETE_2_THREAD_NUMBER | (IMAGE_2_DHD_RX_COMPLETE_2_DISPATCHER_CREDIT_TABLE_ADDRESS << 16);
#endif    
#endif    
    
#ifdef G9991
    /* CPU_TX_INTERRUPT_COALESCING: thread 6 */
    local_regs[IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, interrupt_coalescing_1st_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[13]] = IMAGE_2_CPU_INTERRUPT_COALESCING_TABLE_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER][reg_id[12]] = IMAGE_2_CPU_RING_DESCRIPTORS_TABLE_ADDRESS | (IMAGE_2_CPU_RING_INTERRUPT_COUNTER_TABLE_ADDRESS << 16);

    /* DIRECT PROCESSING : thread 5 */
    local_regs[IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER][reg_id[9]] = IMAGE_2_RX_FLOW_TABLE_ADDRESS << 16 | IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER;
    local_regs[IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER][reg_id[10]] = BB_ID_DISPATCHER_REORDER;
#ifdef BCM6858_A0
    local_regs[IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER][reg_id[11]] = QM_QUEUE_CPU_RX | ( IMAGE_2_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS << 16 );
#else
    local_regs[IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER][reg_id[11]] = QM_QUEUE_CPU_RX_COPY_EXCLUSIVE | ( IMAGE_2_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS << 16 );
#endif    
    local_regs[IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER][reg_id[16]] =
        ADDRESS_OF(image_2, gpon_control_wakeup_request) << 16 | IMAGE_2_DIRECT_PROCESSING_PD_TABLE_ADDRESS;

    /* DIRECT PROCESSING : thread 6 */
    local_regs[IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER][reg_id[9]] = IMAGE_2_RX_FLOW_TABLE_ADDRESS << 16 | IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER;
    local_regs[IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER][reg_id[10]] = BB_ID_DISPATCHER_REORDER;
#ifdef BCM6858_A0    
    local_regs[IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER][reg_id[11]] = QM_QUEUE_CPU_RX | ( IMAGE_2_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS << 16 );
#else
    local_regs[IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER][reg_id[11]] = QM_QUEUE_CPU_RX_COPY_EXCLUSIVE | ( IMAGE_2_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS << 16 );
#endif
    local_regs[IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER][reg_id[16]] =
        ADDRESS_OF(image_2, direct_processing_wakeup_request) << 16 | (IMAGE_2_DIRECT_PROCESSING_PD_TABLE_ADDRESS + sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS));

    /* CPU_RX_FIFO_READ: thread 7 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_rx_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_THREAD_NUMBER][reg_id[14]] = IMAGE_2_CPU_RX_SCRATCHPAD_ADDRESS |
        (IMAGE_2_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS << 16);
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_THREAD_NUMBER][reg_id[12]] = IMAGE_2_CPU_RING_DESCRIPTORS_TABLE_ADDRESS;
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_THREAD_NUMBER][reg_id[11]] = IMAGE_2_PD_FIFO_TABLE_ADDRESS | (IMAGE_2_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS << 16);

    /* CPU_RX_UPDATE_FIFO_READ: thread 2 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_rx_update_fifo_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_UPDATE_FIFO_THREAD_NUMBER][reg_id[12]] = (((IMAGE_2_CPU_IF_2_CPU_RX_THREAD_NUMBER) << 4) + 9);
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_2_UPDATE_FIFO_TABLE_ADDRESS;

    /* CPU_RX_METER_BUDGET_ALLOCATOR: thread 11 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER][reg_id[16]] =
        ADDRESS_OF(image_2, cpu_rx_meter_budget_allocator_1st_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER][reg_id[11]] = CPU_RX_METER_TIMER_PERIOD;
	
#ifndef BCM6858_A0
    /* CPU_RX_COPY_FIFO_READ: thread 13 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_COPY_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_rx_copy_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_COPY_THREAD_NUMBER][reg_id[14]] = IMAGE_2_CPU_RX_SCRATCHPAD_ADDRESS |
        (IMAGE_2_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS << 16);
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_COPY_THREAD_NUMBER][reg_id[12]] = 0;
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_COPY_THREAD_NUMBER][reg_id[11]] = (IMAGE_2_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS) | (IMAGE_2_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS << 16);

    /* CPU_RX_COPY_UPDATE_FIFO_READ: thread 14 */
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_2, cpu_rx_copy_update_fifo_wakeup_request) << 16;
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER][reg_id[12]] = (((IMAGE_2_CPU_IF_2_CPU_RX_COPY_THREAD_NUMBER) << 4) + 9);
    local_regs[IMAGE_2_CPU_IF_2_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_2_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS;
#endif
 
	
#endif
#ifdef RDP_SIM
    /* copy the local registers initial values to the Context memory */
    MWRITE_BLK_32(sram_context, local_regs, mem_cntxt_byte_num);
#else
    rdp_rnr_write_context(sram_context, local_regs, mem_cntxt_byte_num);
#endif
}

static void image_3_context_set(uint32_t core_index)
{
    static uint32_t local_regs[NUM_OF_MAIN_RUNNER_THREADS][32];
    uint32_t mem_cntxt_byte_num;
    uint32_t *sram_context;

    sram_context = (uint32_t *)DEVICE_ADDRESS(RU_BLK(RNR_CNTXT).addr[core_index] + RU_REG_OFFSET(RNR_CNTXT, MEM_ENTRY));
    mem_cntxt_byte_num = (RU_REG_RAM_CNT(RNR_CNTXT, MEM_ENTRY) + 1) * sizeof(uint32_t);
#ifndef XRDP_EMULATION
    /* read the local registers from the Context memory - maybe it was initialized by the ACE compiler */
    MREAD_BLK_32(local_regs, sram_context, mem_cntxt_byte_num);
#endif
    /* Budget allocation: thread 0 */
    local_regs[IMAGE_3_US_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_3, budget_allocator_1st_wakeup_request) << 16;
    local_regs[IMAGE_3_US_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[13]] = (RDD_BASIC_RATE_LIMITER_TABLE_SIZE / 4) * sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS);
    local_regs[IMAGE_3_US_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[12]] = IMAGE_3_SCHEDULING_QUEUE_TABLE_ADDRESS | (IMAGE_3_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[10]] = IMAGE_3_RATE_LIMITER_VALID_TABLE_ADDRESS;
    local_regs[IMAGE_3_US_TM_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[9]]  = IMAGE_3_BASIC_RATE_LIMITER_TABLE_ADDRESS | (IMAGE_3_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* Overall budget allocation (for ovlr rl): thread 1 */
    local_regs[IMAGE_3_US_TM_OVL_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[8]] = IMAGE_3_BBH_QUEUE_TABLE_ADDRESS | (IMAGE_3_BASIC_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_OVL_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[11]] = (IMAGE_3_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_OVL_BUDGET_ALLOCATION_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_3, ovl_budget_allocator_1st_wakeup_request) << 16;

    /* UPDATE_FIFO_READ: thread 2 */
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_3, update_fifo_read_1st_wakeup_request) << 16;
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[14]] = IMAGE_3_COMPLEX_SCHEDULER_TABLE_ADDRESS | (IMAGE_3_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[12]] = (IMAGE_3_PD_FIFO_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[11]] = IMAGE_3_UPDATE_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[10]] = BB_ID_QM_RNR_GRID | (IMAGE_3_BBH_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_THREAD_NUMBER][reg_id[9]]  = IMAGE_3_SCHEDULING_QUEUE_TABLE_ADDRESS | (IMAGE_3_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* EPON UPDATE_FIFO_READ: thread 3 */
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_EPON_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_3, epon_update_fifo_read_1st_wakeup_request) << 16;
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_EPON_THREAD_NUMBER][reg_id[12]] = BB_ID_TX_PON_ETH_PD;
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_EPON_THREAD_NUMBER][reg_id[11]] = IMAGE_3_EPON_UPDATE_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_EPON_THREAD_NUMBER][reg_id[10]] = BB_ID_QM_RNR_GRID;
    local_regs[IMAGE_3_US_TM_UPDATE_FIFO_EPON_THREAD_NUMBER][reg_id[9]]  = IMAGE_3_SCHEDULING_QUEUE_TABLE_ADDRESS;

    /* FLUSH TASK: thread 4 */
    local_regs[IMAGE_3_US_TM_FLUSH_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_3, flush_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_3_US_TM_FLUSH_THREAD_NUMBER][reg_id[12]] = IMAGE_3_PD_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_3_US_TM_FLUSH_THREAD_NUMBER][reg_id[11]] = IMAGE_3_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS;
    local_regs[IMAGE_3_US_TM_FLUSH_THREAD_NUMBER][reg_id[10]] = (BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_US_TM_FLUSH << 6));
    local_regs[IMAGE_3_US_TM_FLUSH_THREAD_NUMBER][reg_id[9]] = IMAGE_3_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS;
    local_regs[IMAGE_3_US_TM_FLUSH_THREAD_NUMBER][reg_id[8]] = xrdp_virt2phys(&RU_BLK(QM), 0) + RU_REG_OFFSET(QM, GLOBAL_CFG_AGGREGATION_CONTEXT_VALID) +
        (QM_QUEUE_US_START / 8);

    /* SCHEDULING WAN: thread 8 */
    local_regs[IMAGE_3_US_TM_WAN_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_3, tx_task_1st_wakeup_request) << 16;
    local_regs[IMAGE_3_US_TM_WAN_THREAD_NUMBER][reg_id[12]] = (IMAGE_3_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_WAN_THREAD_NUMBER][reg_id[11]] = BB_ID_TX_PON_ETH_PD | (IMAGE_3_COMPLEX_SCHEDULER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_WAN_THREAD_NUMBER][reg_id[10]] = IMAGE_3_PD_FIFO_TABLE_ADDRESS | (IMAGE_3_BASIC_RATE_LIMITER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_WAN_THREAD_NUMBER][reg_id[9]]  = (BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_EPON_TM << 6)) | (IMAGE_3_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_WAN_THREAD_NUMBER][reg_id[8]]  = IMAGE_3_BBH_QUEUE_TABLE_ADDRESS | (IMAGE_3_BASIC_SCHEDULER_TABLE_ADDRESS << 16);

    /* EPON SCHEDULING WAN: thread 9 */
    local_regs[IMAGE_3_US_TM_WAN_EPON_THREAD_NUMBER][reg_id[16]] = ADDRESS_OF(image_3, epon_tx_task_wakeup_request) << 16;
    local_regs[IMAGE_3_US_TM_WAN_EPON_THREAD_NUMBER][reg_id[12]] = BB_ID_TX_PON_ETH_PD | (IMAGE_3_BBH_TX_EPON_EGRESS_COUNTER_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_WAN_EPON_THREAD_NUMBER][reg_id[11]] = IMAGE_3_PD_FIFO_TABLE_ADDRESS;
    local_regs[IMAGE_3_US_TM_WAN_EPON_THREAD_NUMBER][reg_id[10]] = BB_ID_QM_RNR_GRID | (IMAGE_3_SCHEDULING_QUEUE_TABLE_ADDRESS << 16);
    local_regs[IMAGE_3_US_TM_WAN_EPON_THREAD_NUMBER][reg_id[9]]  = IMAGE_3_BBH_TX_EPON_INGRESS_COUNTER_TABLE_ADDRESS;
#ifdef RDP_SIM
   /* copy the local registers initial values to the Context memory */
   MWRITE_BLK_32(sram_context, local_regs, mem_cntxt_byte_num);
#else
   rdp_rnr_write_context(sram_context, local_regs, mem_cntxt_byte_num);
#endif
}

static void image_4_context_set(uint32_t core_index)
{
    static uint32_t local_regs[NUM_OF_MAIN_RUNNER_THREADS][32];
    uint32_t mem_cntxt_byte_num;
    uint32_t *sram_context;
    uint32_t task;

    sram_context = (uint32_t *)RUNNER_CORE_CONTEXT_ADDRESS(core_index);
    mem_cntxt_byte_num = (RU_REG_RAM_CNT(RNR_CNTXT, MEM_ENTRY) + 1) * sizeof(uint32_t);
#ifndef XRDP_EMULATION
    /* read the local registers from the Context memory - maybe it was initialized by the ACE compiler */
    MREAD_BLK_32(local_regs, sram_context, mem_cntxt_byte_num);
#endif
    for (task = IMAGE_4_PROCESSING_0_THREAD_NUMBER; task <= IMAGE_4_PROCESSING_7_THREAD_NUMBER; task++)
    {
        /* PROCESSING : thread 0 */
        local_regs[task][reg_id[9]] = IMAGE_4_RX_FLOW_TABLE_ADDRESS << 16 | task;
        local_regs[task][reg_id[16]] = ADDRESS_OF(image_4, processing_wakeup_request) << 16 |
            PACKET_BUFFER_PD_PTR(IMAGE_4_DS_PACKET_BUFFER_ADDRESS, task);
    }
#ifdef RDP_SIM
    /* copy the local registers initial values to the Context memory */
    MWRITE_BLK_32(sram_context, local_regs, mem_cntxt_byte_num);
#else
    rdp_rnr_write_context(sram_context, local_regs, mem_cntxt_byte_num);
#endif
}

static void rdd_local_registers_init(rdd_init_params_t *init_params)
{
    uint32_t core_index;

    for (core_index = 0; core_index < GROUPED_EN_SEGMENTS_NUM; core_index++)
    {
        switch (rdp_core_to_image_map[core_index])
        {
        case image_0_runner_image:
            image_0_context_set(core_index, init_params);
            break;

        case image_1_runner_image:
            image_1_context_set(core_index);
            break;

        case image_2_runner_image:
            image_2_context_set(core_index);
            break;

        case image_3_runner_image:
            image_3_context_set(core_index);
            break;

        case image_4_runner_image:
            image_4_context_set(core_index);
            break;

        default:
            bdmf_trace("ERROR driver %s:%u| unsupported Runner image = %d\n", __FILE__, __LINE__, rdp_core_to_image_map[core_index]);
            break;
        }
    }
}

static void rdd_layer2_header_copy_ptr_init(void)
{
    LAYER2_HEADER_COPY_ROUTINE_ARRAY(layer2_header_copy_routine_arr, processing_image, processing_layer2_header_copy);
    uint16_t i;

    RDD_BTRACE("\n");

    for (i = 0; i < RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_SIZE; i++)
        RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_ROUTINE_WRITE_G(layer2_header_copy_routine_arr[i], RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_ADDRESS_ARR, i);
}

static int rdd_cpu_proj_init(void)
{
#ifndef _CFE_
    uint8_t def_idx = (uint8_t)BDMF_INDEX_UNASSIGNED;
#else
    uint8_t def_idx = 0;
#endif
    int rc = 0;

    rdd_cpu_tc_to_rqx_init(def_idx);
    rdd_cpu_vport_cpu_obj_init(def_idx);
    rdd_cpu_rx_meters_init();
#ifndef _CFE_
    rc = ag_drv_rnr_regs_cfg_cpu_wakeup_set(get_runner_idx(cpu_rx_runner_image),
        CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER);
#endif
    return rc;
}

#ifdef G9991
static void rdd_g9991_ds_tx_init(rdd_init_params_t *init_params)
{
    int i;

    RDD_BYTES_4_BITS_WRITE_G(DS_BBH_TX_BYTES_FIFO_VALUE, RDD_G9991_BBH_TX_BYTES_FIFO_SIZE_ADDRESS_ARR, 0);
    RDD_BYTES_4_BITS_WRITE_G(PD_FIFO_CREDIT_INIT_VALUE, RDD_G9991_NOT_FULL_VECTOR_ADDRESS_ARR, 0);
    RDD_BYTES_4_BITS_WRITE_G(FLOW_CONTROL_INIT_VALUE, RDD_G9991_FLOW_CONTROL_VECTOR_ADDRESS_ARR, 0);
    for (i = 0; i < RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_SIZE; i++)
    {
        if (init_params->g9991_port[i] >= 0)
            RDD_BYTE_1_BITS_WRITE_G(rdpa_emac_to_bb_id_tx[init_params->g9991_port[i]], RDD_G9991_PHYS_PORT_BB_ID_TABLE_ADDRESS_ARR, i);
    }
}

static void rdd_g9991_us_tx_init(void)
{
    int i;

    for (i = 0; i < RDD_G9991_US_SID_CONTEXT_TABLE_SIZE; ++i)
    {
        RDD_G9991_US_SID_CONTEXT_ENTRY_STATE_WRITE_G(1, RDD_G9991_US_SID_CONTEXT_TABLE_ADDRESS_ARR, i);
        RDD_G9991_US_SID_CONTEXT_ENTRY_FRAGMENT_COUNT_WRITE_G(1, RDD_G9991_US_SID_CONTEXT_TABLE_ADDRESS_ARR, i);
    }
}
#endif

int rdd_data_structures_init(rdd_init_params_t *init_params, RDD_HW_IPTV_CONFIGURATION_DTS *iptv_hw_config)
{
    bdmf_error_t rc = BDMF_ERR_OK;
#ifdef _CFE_
    int i;
#endif
    rdd_global_registers_init();
    rdd_local_registers_init(init_params);

    rdd_cpu_if_init();

    rdd_fpm_pool_number_mapping_cfg(iptv_hw_config->fpm_base_token_size);
#ifndef _CFE_
#ifdef CONFIG_DHD_RUNNER
    rdp_drv_dhd_skb_fifo_tbl_init();
#endif	
    rdd_bridge_ports_init();
    if (!init_params->is_basic)
    {
        
		/* write global FPM congifuration */
        RDD_FPM_GLOBAL_CFG_FPM_BASE_LOW_WRITE_G(g_fpm_hw_cfg.fpm_base_low,RDD_FPM_GLOBAL_CFG_ADDRESS_ARR,0);
        RDD_FPM_GLOBAL_CFG_FPM_BASE_HIGH_WRITE_G(g_fpm_hw_cfg.fpm_base_high,RDD_FPM_GLOBAL_CFG_ADDRESS_ARR,0);
        RDD_FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_WRITE_G(g_fpm_hw_cfg.fpm_token_size_asr_8,RDD_FPM_GLOBAL_CFG_ADDRESS_ARR,0);
#ifdef CONFIG_DHD_RUNNER       
        rdd_dhd_hw_cfg(&init_params->dhd_hw_config);
#endif		                
        rdd_iptv_processing_cfg(iptv_hw_config);
        rdd_qos_mapper_init();
    }
#endif
#ifdef G9991
    /* DS: init G9991 fragmentation */
    rdd_g9991_ds_tx_init(init_params);

    /* US: init G9991 reassembly */
    rdd_g9991_us_tx_init();
#endif
    /* init first queue mapping */
    rdd_ag_us_tm_first_queue_mapping_set(QM_QUEUE_US_START);
    rdd_ag_ds_tm_first_queue_mapping_set(QM_QUEUE_DS_START);

    /* init bbh-queue */
    rdd_bbh_queue_init();

    /* WA for A0 - enable queue in fw */
    rdd_set_queue_enable(QM_QUEUE_CPU_RX, 1);
    rdd_set_queue_enable(QM_QUEUE_CPU_RX_COPY_NORMAL, 1);
    rdd_set_queue_enable(QM_QUEUE_CPU_RX_COPY_EXCLUSIVE, 1);
        
#ifndef _CFE_ 
#ifdef CONFIG_DHD_RUNNER
    rdd_set_queue_enable(QM_QUEUE_DHD_TX_POST_0, 1);
    rdd_set_queue_enable(QM_QUEUE_DHD_TX_POST_1, 1);
    rdd_set_queue_enable(QM_QUEUE_DHD_TX_POST_2, 1);
    rdd_set_queue_enable(QM_QUEUE_DHD_CPU_TX_POST_0, 1);
    rdd_set_queue_enable(QM_QUEUE_DHD_CPU_TX_POST_1, 1);
    rdd_set_queue_enable(QM_QUEUE_DHD_CPU_TX_POST_2, 1);
#endif
    /* start flush task */
    rc = rc ? rc : rdd_scheduling_flush_timer_set();

    /* start budget allocation task */
    rc = rc ? rc : rdd_ds_budget_allocation_timer_set();

    rdd_rx_default_flow_init();
#else
    /* enable all tx_flow (ports) */
    for (i=0; i <= 8; i++)
    {
        rdd_tx_flow_enable(i, rdpa_dir_ds, 1);
        rdd_tx_flow_enable(i, rdpa_dir_us, 1);
    }
#endif
    rdd_layer2_header_copy_mapping_init();
    rdd_layer2_header_copy_ptr_init();

    rdd_proj_init(init_params);
    rdd_actions_proj_init();
    rdd_tm_actions_proj_init();
    rdd_tcam_cmd_init();

    rc = rc ? rc : rdd_cpu_proj_init();

#ifdef USE_BDMF_SHELL
    /* register shell commands */
    rc = rc ? : rdd_make_shell_commands();
#endif
    return rc;
}

/*  Classification chain: Flow based
 *
 *   Module list
 *   -----------
 *  1. Ingress Filter
 *  2. Ingress flow classifier
 *  3. ACL
 *  4. QoS
 *  5. tunnel parsing (just for DS)
 *  6. natc lookup
 *  7. IPTV
 *
 */
#ifndef _CFE_
static rdd_tcam_table_parm_t tcam_ic_acl_params =
{
    .module_id = TCAM_IC_MODULE_ACL_US,
    .scratch_offset = offsetof(RDD_PACKET_BUFFER_DTS, scratch) + TCAM_IC_SCRATCH_KEY_OFFSET,
};

static rdd_module_t tcam_ic_acl_module =
{
    .context_offset = offsetof(RDD_PACKET_BUFFER_DTS, classification_contexts_list), /* runs over ic_flow */
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_TCAM_IC_ACL * 4)),
    .cfg_ptr = RDD_TCAM_IC_CFG_TABLE_ADDRESS_ARR,   /* Instance offset will be added at init time */
    .init = rdd_tcam_module_init,
    .params = &tcam_ic_acl_params
};

static rdd_tcam_table_parm_t tcam_ic_flow_us_params =
{
    .module_id = TCAM_IC_MODULE_FLOW_US,
    .scratch_offset = offsetof(RDD_PACKET_BUFFER_DTS, scratch) + TCAM_IC_SCRATCH_KEY_OFFSET,
};

static rdd_module_t tcam_ic_flow_us_module =
{
    .context_offset = offsetof(RDD_PACKET_BUFFER_DTS, classification_contexts_list),
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_TCAM_IC_FLOW * 4)),
    .cfg_ptr = RDD_TCAM_IC_CFG_TABLE_ADDRESS_ARR,   /* Instance offset will be added at init time */
    .init = rdd_tcam_module_init,
    .params = &tcam_ic_flow_us_params
};

static rdd_tcam_table_parm_t tcam_ic_flow_ds_params =
{
    .module_id = TCAM_IC_MODULE_FLOW_DS,
    .scratch_offset = offsetof(RDD_PACKET_BUFFER_DTS, scratch) + TCAM_IC_SCRATCH_KEY_OFFSET,
};

static rdd_module_t tcam_ic_flow_ds_module =
{
    .context_offset = offsetof(RDD_PACKET_BUFFER_DTS, classification_contexts_list),
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_TCAM_IC_FLOW * 4)),
    .cfg_ptr = RDD_TCAM_IC_CFG_TABLE_ADDRESS_ARR,   /* Instance offset will be added at init time */
    .init = rdd_tcam_module_init,
    .params = &tcam_ic_flow_ds_params
};

static rdd_tcam_table_parm_t tcam_ic_qos_us_params =
{
    .module_id = TCAM_IC_MODULE_QOS_US,
    .scratch_offset = offsetof(RDD_PACKET_BUFFER_DTS, scratch) + TCAM_IC_SCRATCH_KEY_OFFSET,
};

static rdd_module_t tcam_ic_qos_us_module =
{
    .context_offset = offsetof(RDD_PACKET_BUFFER_DTS, classification_contexts_list) + 
        offsetof(RDD_RULE_BASED_CONTEXT_DTS, tcam_qos_result),
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_TCAM_IC_QOS * 4)),
    .cfg_ptr = RDD_TCAM_IC_CFG_TABLE_ADDRESS_ARR,  /* Instance offset will be added at init time */
    .init = rdd_tcam_module_init,
    .params = &tcam_ic_qos_us_params
};

static rdd_tcam_table_parm_t tcam_ic_qos_ds_params =
{
    .module_id = TCAM_IC_MODULE_QOS_DS,
    .scratch_offset = offsetof(RDD_PACKET_BUFFER_DTS, scratch) + TCAM_IC_SCRATCH_KEY_OFFSET,
};

static rdd_module_t tcam_ic_qos_ds_module =
{
    .context_offset = offsetof(RDD_PACKET_BUFFER_DTS, classification_contexts_list) +
        offsetof(RDD_RULE_BASED_CONTEXT_DTS, tcam_qos_result),
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_TCAM_IC_QOS * 4)),
    .cfg_ptr = RDD_TCAM_IC_CFG_TABLE_ADDRESS_ARR,  /* Instance offset will be added at init time */
    .init = rdd_tcam_module_init,
    .params = &tcam_ic_qos_ds_params
};

static rdd_module_t ingress_filter_module =
{
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_INGRESS_FILTERS * 4)),
    .cfg_ptr = RDD_INGRESS_FILTER_CFG_ADDRESS_ARR,
    .init = rdd_ingress_filter_module_init,
    .params = NULL
};
/* Bridge */

static rdd_bridge_module_param_t bridge_params_ds =
{
    .bridge_lkps_ready = 0,
    .bridge_and_vlan_lookup_fail_action = BRIDGE_AND_VLAN_LKP_MISS_ACTION_FORWARD,
    .aggregation_en = 0,
    .bridge_module_actions.hit = 1,
    .bridge_module_actions.bridge_fw_failed_action = 0,
    .bridge_module_actions.vlan_aggregation_action = 0,
    .module_id = BRIDGE_FLOW_DS
};

static rdd_bridge_module_param_t bridge_params_us =
{
    .bridge_lkps_ready = 1,
    .bridge_and_vlan_lookup_fail_action = BRIDGE_AND_VLAN_LKP_MISS_ACTION_FORWARD,
    .aggregation_en = 0,
    .bridge_module_actions.hit = 1,
    .bridge_module_actions.bridge_fw_failed_action = 0,
    .bridge_module_actions.vlan_aggregation_action = 0,
    .module_id = BRIDGE_FLOW_US
};

static rdd_bridge_module_param_t bridge_params_ls =
{
    .bridge_lkps_ready = 1,
    .bridge_and_vlan_lookup_fail_action = BRIDGE_AND_VLAN_LKP_MISS_ACTION_FORWARD,
    .aggregation_en = 0,
    .bridge_module_actions.hit = 1,
    .bridge_module_actions.bridge_fw_failed_action = 0,
    .bridge_module_actions.vlan_aggregation_action = 0,
    .module_id = BRIDGE_FLOW_LOCAL_SWITCH
};

static rdd_module_t bridge_module_ds =
{
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_BRIDGE * 4)),
    .cfg_ptr = RDD_BRIDGE_CFG_TABLE_ADDRESS_ARR,
    .init = rdd_bridge_module_init,
    .params = &bridge_params_ds
};

static rdd_module_t bridge_module_us =
{
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_BRIDGE * 4)),
    .cfg_ptr = RDD_BRIDGE_CFG_TABLE_ADDRESS_ARR,
    .init = rdd_bridge_module_init,
    .params = &bridge_params_us
};

static rdd_module_t bridge_module_ls =
{
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_BRIDGE * 4)),
    .cfg_ptr = RDD_BRIDGE_CFG_TABLE_ADDRESS_ARR,
    .init = rdd_bridge_module_init,
    .params = &bridge_params_ls
};

/* IPTV */
static iptv_params_t iptv_params =
{
    .key_offset = offsetof(RDD_PACKET_BUFFER_DTS, scratch),
    .hash_tbl_idx = 1
};

static rdd_module_t iptv_module =
{
    .init = rdd_iptv_module_init,
    .context_offset = offsetof(RDD_PACKET_BUFFER_DTS, classification_contexts_list),
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_IPTV * 4)),
    .cfg_ptr = RDD_IPTV_CFG_TABLE_ADDRESS_ARR,
    .params = (void *)&iptv_params
};
#endif

/* IP CLASS */
static natc_params_t natc_params =
{
    .connection_key_offset = offsetof(RDD_PACKET_BUFFER_DTS, scratch),
};

static rdd_module_t ip_flow =
{
    .init = rdd_nat_cache_init,
    /* NTAC returns 60B (first 4B are control) */
    /* For 8B alignment, 4B are added */
    /* LD_CONTEXT macro adds 8B (control) */
    .context_offset = offsetof(RDD_PACKET_BUFFER_DTS, classification_contexts_list) +
        offsetof(RDD_FLOW_BASED_CONTEXT_DTS, flow_cache),
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_NAT_CACHE * 4)),
    .cfg_ptr = RDD_NAT_CACHE_CFG_ADDRESS_ARR,
    .params = (void *)&natc_params
};

#ifndef G9991
/* Tunnels parser */
static tunnels_parsing_params_t tunnels_parsing_params =
{
    .tunneling_enable = 0
};

rdd_module_t tunnels_parsing =
{
    .init = rdd_tunnels_parsing_init,
    .cfg_ptr = RDD_TUNNELS_PARSING_CFG_ADDRESS_ARR,
    .res_offset = (offsetof(RDD_PACKET_BUFFER_DTS, classification_results) +
        (CLASSIFICATION_RESULT_INDEX_TUNNELS_PARSING * 4)),
    .params = (void *)&tunnels_parsing_params
};
#endif

static void rdd_proj_init(rdd_init_params_t *init_params)
{
    /* Classification modules initialization */
#ifndef G9991
    _rdd_module_init(&tunnels_parsing);
#endif
    _rdd_module_init(&ip_flow);
    if (init_params->is_basic)
        return;
#ifndef _CFE_
    _rdd_module_init(&tcam_ic_acl_module);
    _rdd_module_init(&tcam_ic_flow_us_module);
    _rdd_module_init(&tcam_ic_qos_us_module);
    _rdd_module_init(&tcam_ic_flow_ds_module);
    _rdd_module_init(&tcam_ic_qos_ds_module);
    _rdd_module_init(&ingress_filter_module);
    _rdd_module_init(&iptv_module);
    _rdd_module_init(&bridge_module_ls);
    _rdd_module_init(&bridge_module_ds);
    _rdd_module_init(&bridge_module_us);
#endif
}

static void rdd_tcam_cmd_init(void)
{
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_parser_1, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_PARSER_1);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_parser_2, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_PARSER_2);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_parser_4, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_PARSER_4);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_parser_6, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_PARSER_6);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_parser_8, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_PARSER_8);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_packet, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_PACKET);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_l3_hdr, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_L3);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_l4_hdr, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_L4);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_ingress_port, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_INGRESS_PORT);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_gem_flow, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_GEM_FLOW);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_src_ip, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_SOURCE_IP);
    RDD_TCAM_IC_HANDLER_PTR_WRITE_G(image_4_tcam_cmd_dst_ip, RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR, TCAM_IC_CMD_TYPE_DESTINATION_IP);
}

static void rdd_tm_actions_proj_init(void)
{
    uint32_t action_index;
    RDD_BYTES_2_DTS *tm_action_ptr;
    uint16_t ds_actions_arr[] = {
        [0]  = ADDRESS_OF(image_0, basic_scheduler_update_dwrr),
        [1]  = ADDRESS_OF(image_0, complex_scheduler_update_dwrr_queues),
        [2]  = ADDRESS_OF(image_0, complex_scheduler_update_dwrr_basic_schedulers),
        [3]  = ADDRESS_OF(image_0, basic_rate_limiter_queue_with_bs),
        [4]  = ADDRESS_OF(image_0, basic_rate_limiter_queue_with_cs_bs),
        [5]  = ADDRESS_OF(image_0, complex_rate_limiter_queue_sir),
        [6]  = ADDRESS_OF(image_0, complex_rate_limiter_queue_pir),
        [7]  = ADDRESS_OF(image_0, basic_rate_limiter_basic_scheduler_no_cs),
        [8]  = ADDRESS_OF(image_0, complex_rate_limiter_basic_scheduler_sir),
        [9]  = ADDRESS_OF(image_0, complex_rate_limiter_basic_scheduler_pir),
        [10] = ADDRESS_OF(image_0, basic_rate_limiter_complex_scheduler),
        [11 ... 15] = ADDRESS_OF(image_0, scheduling_action_not_valid),
        [16] = ADDRESS_OF(image_0, scheduling_update_status)
    };
    uint16_t us_actions_arr[] = {
        [0]  = ADDRESS_OF(image_3, basic_scheduler_update_dwrr),
        [1]  = ADDRESS_OF(image_3, complex_scheduler_update_dwrr_queues),
        [2]  = ADDRESS_OF(image_3, complex_scheduler_update_dwrr_basic_schedulers),
        [3]  = ADDRESS_OF(image_3, basic_rate_limiter_queue_with_bs),
        [4]  = ADDRESS_OF(image_3, basic_rate_limiter_queue_with_cs_bs),
        [5]  = ADDRESS_OF(image_3, complex_rate_limiter_queue_sir),
        [6]  = ADDRESS_OF(image_3, complex_rate_limiter_queue_pir),
        [7]  = ADDRESS_OF(image_3, basic_rate_limiter_basic_scheduler_no_cs),
        [8]  = ADDRESS_OF(image_3, complex_rate_limiter_basic_scheduler_sir),
        [9]  = ADDRESS_OF(image_3, complex_rate_limiter_basic_scheduler_pir),
        [10] = ADDRESS_OF(image_3, basic_rate_limiter_complex_scheduler),
        [11] = ADDRESS_OF(image_3, ovl_rate_limiter),
        [12 ... 15] = ADDRESS_OF(image_3, scheduling_action_not_valid),
        [16] = ADDRESS_OF(image_3, scheduling_update_status)
    };

    for (action_index = 0; action_index < RDD_TM_ACTION_PTR_TABLE_SIZE; action_index++)
    {
        tm_action_ptr = ((RDD_BYTES_2_DTS *)RDD_TM_ACTION_PTR_TABLE_PTR(get_runner_idx(us_tm_runner_image))) + action_index;
        RDD_BYTES_2_BITS_WRITE(us_actions_arr[action_index], tm_action_ptr);

        tm_action_ptr = ((RDD_BYTES_2_DTS *)RDD_TM_ACTION_PTR_TABLE_PTR(get_runner_idx(ds_tm_runner_image))) + action_index;
        RDD_BYTES_2_BITS_WRITE(ds_actions_arr[action_index], tm_action_ptr);
    }
}

static void rdd_actions_proj_init(void)
{
    uint32_t action_index;
    uint16_t flow_actions_arr[] = {
        [0] = ADDRESS_OF(image_4, action_exception),
        [1] = ADDRESS_OF(image_4, action_default),
        [2] = ADDRESS_OF(image_4, action_ttl_decrement),
        [3] = ADDRESS_OF(image_4, action_default),
        [4] = ADDRESS_OF(image_4, action_dscp_remarking_flow_based),
        [5] = ADDRESS_OF(image_4, action_nat_ds),
        [6] = ADDRESS_OF(image_4, action_gre_remark),
        [7] = ADDRESS_OF(image_4, action_outer_pbits_remarking_ds),
        [8] = ADDRESS_OF(image_4, action_inner_pbits_remarking_ds),
        [9] = ADDRESS_OF(image_4, action_pppoe),
        [10] = ADDRESS_OF(image_4, action_nat_us),
        [11] = ADDRESS_OF(image_4, action_outer_pbits_remarking_us),
        [12] = ADDRESS_OF(image_4, action_inner_pbits_remarking_us),
#ifndef G9991
        [13] = ADDRESS_OF(image_4, action_dslite),
        [14] = ADDRESS_OF(image_4, action_l2gre),
        [15] = ADDRESS_OF(image_4, action_llc_snap_set_len),
#else
        [13 ... 15] = ADDRESS_OF(image_4, action_default),
#endif
        [16] = ADDRESS_OF(image_4, processing_header_update)
    };
    uint16_t rule_actions_arr[] = {
        [0] = ADDRESS_OF(image_4, action_dei_rule_based),
        [1] = ADDRESS_OF(image_4, action_no_fwd),
        [2] = ADDRESS_OF(image_4, action_dscp_remarking_rule_based),
        [3] = ADDRESS_OF(image_4, action_vlan_rule_base),
        [4] = ADDRESS_OF(image_4, action_pbits_remarking_rule_based),
        [5] = ADDRESS_OF(image_4, action_pbit_to_queue_ds_rule_based),
        [6] = ADDRESS_OF(image_4, action_tc_to_queue_ds_rule_based),
        [7] = ADDRESS_OF(image_4, action_pbit_to_gem_us_rule_based),
        [8] = ADDRESS_OF(image_4, action_pbit_to_queue_us_rule_based),
        [9] = ADDRESS_OF(image_4, action_tc_to_queue_us_rule_based),
        [10] = ADDRESS_OF(image_4, rule_based_resolution_invoke_bridge_ds),
        [11] = ADDRESS_OF(image_4, action_drop_precedence_rule_based),
        [12 ... 15] = ADDRESS_OF(image_4, action_exception),
        [16] = ADDRESS_OF(image_4, processing_header_update_length_calc)
    };

    uint16_t rule_based_context_actions_arr[] = {
        [0] = ADDRESS_OF(image_4, action_no_fwd),
        [1] = ADDRESS_OF(image_4, mcast_resolution_common_actions_done),
        [2 ... 16] = ADDRESS_OF(image_4, action_default)
    };

    uint16_t iptv_actions_arr[] = {
        [0] = ADDRESS_OF(image_4, action_tc_to_queue_iptv),
        [1] = ADDRESS_OF(image_4, action_vlan_iptv),
        [2] = ADDRESS_OF(image_4, mcast_repl_0_header_update),
#ifndef G9991
        [3] = ADDRESS_OF(image_4, cpu_mcast_execution_engine_done),
        [4 ... 15] = ADDRESS_OF(image_4, action_exception),
#else
        [3 ... 15] = ADDRESS_OF(image_4, action_exception),
#endif
        [16] = ADDRESS_OF(image_4, mcast_repl_res_loop_header_update)
    };

    uint16_t vlan_actions_arr[] = {
        [0] = ADDRESS_OF(image_4, gpe_vlan_action_cmd_drop),
        [1] = ADDRESS_OF(image_4, gpe_vlan_action_cmd_dscp),
        [2] = ADDRESS_OF(image_4, gpe_vlan_action_cmd_mac_hdr_copy),                
        [3] = ADDRESS_OF(image_4, gpe_cmd_replace_16),
        [4] = ADDRESS_OF(image_4, gpe_cmd_replace_32),
        [5] = ADDRESS_OF(image_4, gpe_cmd_replace_bits_16),                
        [6] = ADDRESS_OF(image_4, gpe_cmd_copy_bits_16),
        [7 ... 16] = ADDRESS_OF(image_4, gpe_cmd_skip_if),
    };

    for (action_index = 0; action_index < RDD_FLOW_BASED_ACTION_PTR_TABLE_SIZE; action_index++)
    {
        RDD_BYTES_2_BITS_WRITE_G(flow_actions_arr[action_index], RDD_FLOW_BASED_ACTION_PTR_TABLE_ADDRESS_ARR, action_index);
    }

    for (action_index = 0; action_index < RDD_RULE_BASED_ACTION_PTR_TABLE_SIZE; action_index++)
    {
        if (action_index < sizeof(rule_actions_arr)/sizeof(rule_actions_arr[0]))
            RDD_BYTES_2_BITS_WRITE_G(rule_actions_arr[action_index], RDD_RULE_BASED_ACTION_PTR_TABLE_ADDRESS_ARR, action_index);
        else
            RDD_BYTES_2_BITS_WRITE_G(image_4_action_exception, RDD_RULE_BASED_ACTION_PTR_TABLE_ADDRESS_ARR, action_index);
    }
    for (action_index = 0; action_index < RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_SIZE; action_index++)
    {
        if (action_index < sizeof(rule_based_context_actions_arr)/sizeof(rule_based_context_actions_arr[0]))
            RDD_BYTES_2_BITS_WRITE_G(rule_based_context_actions_arr[action_index], RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_ADDRESS_ARR, action_index);
        else
            RDD_BYTES_2_BITS_WRITE_G(image_4_action_exception, RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_ADDRESS_ARR, action_index);
    }
   for (action_index = 0; action_index < RDD_IPTV_ACTION_PTR_TABLE_SIZE; action_index++)
   {
       if (action_index < sizeof(iptv_actions_arr)/sizeof(iptv_actions_arr[0]))
           RDD_BYTES_2_BITS_WRITE_G(iptv_actions_arr[action_index], RDD_IPTV_ACTION_PTR_TABLE_ADDRESS_ARR, action_index);
       else
           RDD_BYTES_2_BITS_WRITE_G(image_4_action_exception, RDD_IPTV_ACTION_PTR_TABLE_ADDRESS_ARR, action_index);
   }
    for (action_index = 0; action_index < RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_SIZE; action_index++)
    {
        RDD_BYTES_2_BITS_WRITE_G(vlan_actions_arr[action_index], RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_ADDRESS_ARR, action_index);
    }

}
