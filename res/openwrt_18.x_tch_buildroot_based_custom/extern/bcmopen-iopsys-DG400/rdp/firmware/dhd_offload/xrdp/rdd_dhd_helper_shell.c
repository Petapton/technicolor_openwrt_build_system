/*
   Copyright (c) 2013 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2013:DUAL/GPL:standard
    
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


#include "bdmf_shell.h"
#include "rdd.h"
#include "dhd_defs.h"
#include "rdpa_dhd_helper_basic.h"
#include "rdp_drv_proj_cntr.h"
#include "rdd_dhd_helper.h"


#define MAKE_BDMF_SHELL_CMD_NOPARM(dir, cmd, help, cb) \
    bdmfmon_cmd_add(dir, cmd, cb, help, BDMF_ACCESS_ADMIN, NULL, NULL)

#define MAKE_BDMF_SHELL_CMD(dir, cmd, help, cb, parms...)   \
{                                                           \
    static bdmfmon_cmd_parm_t cmd_parms[]={                 \
        parms,                                              \
        BDMFMON_PARM_LIST_TERMINATOR                        \
    };                                                      \
    bdmfmon_cmd_add(dir, cmd, cb, help, BDMF_ACCESS_ADMIN, NULL, cmd_parms); \
}

static int _rdd_print_dhd_tx_post_desc(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    RDD_DHD_POST_COMMON_RADIO_DATA_DTS *radio_instance_table_ptr;
    RDD_DHD_POST_COMMON_RADIO_ENTRY_DTS *radio_instance_entry_ptr;
    RDD_DHD_TX_POST_DESCRIPTOR_DTS *desc_ptr;
    RDD_DHD_TX_POST_DESCRIPTOR_DTS desc;
    void *base_ptr;

    uint32_t radio_idx, ring_id, desc_num;
    uint32_t addr_lo,addr_hi;
    rdpa_dhd_flring_cache_t *entry_ptr;

    radio_idx = (uint32_t)parm[0].value.unumber;
    ring_id = (uint32_t)parm[1].value.unumber;
    desc_num = (uint32_t)parm[2].value.unumber;

    radio_instance_table_ptr = (RDD_DHD_POST_COMMON_RADIO_DATA_DTS *) RDD_DHD_POST_COMMON_RADIO_DATA_PTR(get_runner_idx(dhd_tx_post_runner_image));
    radio_instance_entry_ptr = &radio_instance_table_ptr->entry[radio_idx];

    
    RDD_DHD_POST_COMMON_RADIO_ENTRY_TX_POST_MGMT_FR_BASE_PTR_LOW_READ(addr_lo, radio_instance_entry_ptr);
    RDD_DHD_POST_COMMON_RADIO_ENTRY_TX_POST_MGMT_FR_BASE_PTR_HIGH_READ(addr_hi, radio_instance_entry_ptr);
    
#ifdef PHYS_ADDR_64BIT
    base_ptr = (void*) (((uint64_t)addr_hi << 32) + addr_lo);
#else
    addr_hi = 0;
    base_ptr = (void*) (addr_lo | addr_hi);            
#endif
    
    entry_ptr = (rdpa_dhd_flring_cache_t *)(base_ptr) + ring_id;

#ifdef PHYS_ADDR_64BIT
    desc_ptr = (RDD_DHD_TX_POST_DESCRIPTOR_DTS *)RDD_RSV_PHYS_TO_VIRT(((uint64_t)entry_ptr->base_addr_high << 32) + entry_ptr->base_addr_low) + desc_num;
#else
    desc_ptr = (RDD_DHD_TX_POST_DESCRIPTOR_DTS *)RDD_RSV_PHYS_TO_VIRT(entry_ptr->base_addr_low) + desc_num;
#endif

    memcpy(&desc, desc_ptr, sizeof(RDD_DHD_TX_POST_DESCRIPTOR_DTS));

    bdmf_session_print(session, "TX POST descriptor\n");
    bdmf_session_print(session, "msg_type                 = 0x%4.4x\n", desc.msg_type);
    bdmf_session_print(session, "if_id                    = 0x%4.4x\n", desc.if_id);
    bdmf_session_print(session, "common_hdr_flags         = 0x%4.4x\n", desc.common_hdr_flags);
    bdmf_session_print(session, "epoch                    = 0x%4.4x\n", desc.epoch);
    bdmf_session_print(session, "request_id               = 0x%8.8x\n", desc.request_id);
    bdmf_session_print(session, "tx_eth_hdr_0             = 0x%8.8x\n", desc.tx_eth_hdr_0);
    bdmf_session_print(session, "tx_eth_hdr_1             = 0x%8.8x\n", desc.tx_eth_hdr_1);
    bdmf_session_print(session, "tx_eth_hdr_2             = 0x%8.8x\n", desc.tx_eth_hdr_2);
    bdmf_session_print(session, "tx_eth_hdr_3             = 0x%4.4x\n", desc.tx_eth_hdr_3);
    bdmf_session_print(session, "flags                    = 0x%4.4x\n", desc.flags);
    bdmf_session_print(session, "seg_cnt                  = 0x%4.4x\n", desc.seg_cnt);
    bdmf_session_print(session, "metadata_buf_addr_low	= 0x%8.8x\n", desc.metadata_buf_addr_low);
    bdmf_session_print(session, "metadata_buf_addr_hi 	= 0x%8.8x\n", desc.metadata_buf_addr_hi);
    bdmf_session_print(session, "data_buf_addr_low    	= 0x%8.8x\n", cpu_to_le32(desc.data_buf_addr_low));
    bdmf_session_print(session, "data_buf_addr_hi         = 0x%8.8x\n", desc.data_buf_addr_hi);
    bdmf_session_print(session, "meta_buf_len             = 0x%4.4x\n", desc.meta_buf_len);
    bdmf_session_print(session, "data_len                 = 0x%4.4x\n", cpu_to_le16(desc.data_len));

    return 0;
}

static int _rdd_print_dhd_tx_complete_desc(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    RDD_DHD_COMPLETE_COMMON_RADIO_DATA_DTS      *radio_instance_table_ptr;
    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS     *radio_instance_entry_ptr;
    RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS          *desc_ptr;
    RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS          desc;
    uint32_t                                    desc_num, radio_idx; 
    bdmf_phys_addr_t                            base_ptr;
    uint32_t                                    addr_lo,addr_hi;

    radio_idx = (uint32_t)parm[0].value.unumber;
    desc_num = (uint32_t)parm[1].value.unumber;

    radio_instance_table_ptr = (RDD_DHD_COMPLETE_COMMON_RADIO_DATA_DTS *) RDD_DHD_COMPLETE_COMMON_RADIO_DATA_PTR(get_runner_idx(dhd_complete_runner_image));
    radio_instance_entry_ptr = &radio_instance_table_ptr->entry[radio_idx];

    
    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_TX_COMPLETE_FR_BASE_PTR_LOW_READ(addr_lo, radio_instance_entry_ptr);
    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_TX_COMPLETE_FR_BASE_PTR_HIGH_READ(addr_hi, radio_instance_entry_ptr);

#ifdef PHYS_ADDR_64BIT
    base_ptr = ((uint64_t)addr_hi << 32) + addr_lo;
#else
    addr_hi = 0;
    base_ptr = addr_lo | addr_hi;            
#endif      

    desc_ptr = (RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS *)RDD_RSV_PHYS_TO_VIRT(base_ptr) + desc_num;

    memcpy(&desc, desc_ptr, sizeof(RDD_DHD_TX_COMPLETE_DESCRIPTOR_DTS));

    bdmf_session_print(session, "TX COMPLETE descriptor\n");
    bdmf_session_print(session, "msg_type                 = 0x%4.4x\n", desc.msg_type);
    bdmf_session_print(session, "if_id                    = 0x%4.4x\n", desc.if_id);
    bdmf_session_print(session, "common_hdr_flags         = 0x%4.4x\n", desc.common_hdr_flags);
    bdmf_session_print(session, "epoch                    = 0x%4.4x\n", desc.epoch);
    bdmf_session_print(session, "request_id               = 0x%8.8x\n", desc.request_id);
    bdmf_session_print(session, "status                   = 0x%4.4x\n", desc.status);
    bdmf_session_print(session, "flow_ring_id             = 0x%4.4x\n", desc.flow_ring_id);
    bdmf_session_print(session, "dma_done_mark 	          = 0x%8.8x\n", desc.dma_done_mark);

    return 0;
}

static int _rdd_print_dhd_rx_complete_desc(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    RDD_DHD_COMPLETE_COMMON_RADIO_DATA_DTS   *radio_instance_table_ptr;
    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS  *radio_instance_entry_ptr;
    RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS       *desc_ptr;
    RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS       desc;
    uint32_t                                 desc_num, radio_idx;
    bdmf_phys_addr_t                         base_ptr;
    uint32_t                                 addr_lo,addr_hi;

    radio_idx = (uint32_t)parm[0].value.unumber;
    desc_num = (uint32_t)parm[1].value.unumber;

    radio_instance_table_ptr = (RDD_DHD_COMPLETE_COMMON_RADIO_DATA_DTS *) RDD_DHD_COMPLETE_COMMON_RADIO_DATA_PTR(get_runner_idx(dhd_complete_runner_image));
    radio_instance_entry_ptr = &radio_instance_table_ptr->entry[radio_idx];

    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_RX_COMPLETE_FR_BASE_PTR_LOW_READ(addr_lo, radio_instance_entry_ptr);
    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_RX_COMPLETE_FR_BASE_PTR_HIGH_READ(addr_hi, radio_instance_entry_ptr);
    
#ifdef PHYS_ADDR_64BIT
    base_ptr = ((uint64_t)addr_hi << 32) + addr_lo;
#else
    addr_hi = 0;
    base_ptr = addr_lo | addr_hi;            
#endif

    desc_ptr = (RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS *)RDD_RSV_PHYS_TO_VIRT(base_ptr) + desc_num;
   

    memcpy(&desc, desc_ptr, sizeof(RDD_DHD_RX_COMPLETE_DESCRIPTOR_DTS));

    bdmf_session_print(session, "RX COMPLETE descriptor\n");
    bdmf_session_print(session, "msg_type                 = 0x%4.4x\n", desc.msg_type);
    bdmf_session_print(session, "if_id                    = 0x%4.4x\n", desc.if_id);
    bdmf_session_print(session, "common_hdr_flags         = 0x%4.4x\n", desc.common_hdr_flags);
    bdmf_session_print(session, "epoch                    = 0x%4.4x\n", desc.epoch);
    bdmf_session_print(session, "request_id               = 0x%8.8x\n", desc.request_id);
    bdmf_session_print(session, "compl_msg_hdr_status     = 0x%4.4x\n", desc.compl_msg_hdr_status);
    bdmf_session_print(session, "flow_ring_id             = 0x%4.4x\n", desc.flow_ring_id);
    bdmf_session_print(session, "data_len                 = 0x%4.4x\n", cpu_to_le16(desc.data_len));
    bdmf_session_print(session, "data_offset              = 0x%4.4x\n", cpu_to_le16(desc.data_offset));
    bdmf_session_print(session, "flags                    = 0x%4.4x\n", desc.flags);
    bdmf_session_print(session, "rx_status_0              = 0x%8.8x\n", desc.rx_status_0);
    bdmf_session_print(session, "rx_status_1	          = 0x%8.8x\n", desc.rx_status_1);
    bdmf_session_print(session, "dma_done_mark 	          = 0x%8.8x\n", desc.dma_done_mark);

    return 0;
}

static int _rdd_print_dhd_rx_post_desc(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    RDD_DHD_COMPLETE_COMMON_RADIO_DATA_DTS   *radio_instance_table_ptr;
    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_DTS  *radio_instance_entry_ptr;
    RDD_DHD_RX_POST_DESCRIPTOR_DTS           *desc_ptr;
    RDD_DHD_RX_POST_DESCRIPTOR_DTS           desc;
    uint32_t                                 desc_num, radio_idx;
    bdmf_phys_addr_t                         base_ptr;
    uint32_t                                 addr_lo,addr_hi;
    
    
    radio_idx = (uint32_t)parm[0].value.unumber;
    desc_num = (uint32_t)parm[1].value.unumber;


    radio_instance_table_ptr = (RDD_DHD_COMPLETE_COMMON_RADIO_DATA_DTS *) RDD_DHD_COMPLETE_COMMON_RADIO_DATA_PTR(get_runner_idx(dhd_complete_runner_image));
    radio_instance_entry_ptr = &radio_instance_table_ptr->entry[radio_idx];

    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_RX_POST_FR_BASE_PTR_LOW_READ(addr_lo, radio_instance_entry_ptr);
    RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY_RX_POST_FR_BASE_PTR_HIGH_READ(addr_hi, radio_instance_entry_ptr);
    
#ifdef PHYS_ADDR_64BIT
    base_ptr = ((uint64_t)addr_hi << 32) + addr_lo;
#else
    addr_hi = 0;
    base_ptr = addr_lo | addr_hi;            
#endif

    desc_ptr = (RDD_DHD_RX_POST_DESCRIPTOR_DTS *)RDD_RSV_PHYS_TO_VIRT(base_ptr) + desc_num;
    

    memcpy(&desc, desc_ptr, sizeof(RDD_DHD_RX_POST_DESCRIPTOR_DTS));

    bdmf_session_print(session, "RX POST descriptor\n");
    bdmf_session_print(session, "msg_type                 = 0x%4.4x\n", desc.msg_type);
    bdmf_session_print(session, "if_id                    = 0x%4.4x\n", desc.if_id);
    bdmf_session_print(session, "common_hdr_flags         = 0x%4.4x\n", desc.common_hdr_flags);
    bdmf_session_print(session, "epoch                    = 0x%4.4x\n", desc.epoch);
    bdmf_session_print(session, "request_id               = 0x%8.8x\n", desc.request_id);
    bdmf_session_print(session, "meta_buf_len             = 0x%4.4x\n", desc.meta_buf_len);
    bdmf_session_print(session, "data_len                 = 0x%4.4x\n", cpu_to_le16(desc.data_len));
    bdmf_session_print(session, "metadata_buf_addr_low    = 0x%8.8x\n", desc.metadata_buf_addr_low);
    bdmf_session_print(session, "metadata_buf_addr_hi     = 0x%8.8x\n", desc.metadata_buf_addr_hi);
    bdmf_session_print(session, "data_buf_addr_low        = 0x%8.8x\n", cpu_to_le32(desc.data_buf_addr_low));
    bdmf_session_print(session, "data_buf_addr_hi	      = 0x%8.8x\n", desc.data_buf_addr_hi);

    return 0;
}


static int _rdd_print_dhd_general_counters(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    uint32_t radio_idx;
    uint32_t cntr_arr[MAX_NUM_OF_COUNTERS_PER_READ] = {};
    
    radio_idx = (uint32_t)parm[0].value.unumber;
    
    bdmf_session_print(session, "General DHD counters\n");


    bdmf_session_print(session, "Radio %d\n", radio_idx);                
    
    drv_cntr_counter_read(GENERAL_CNTR_GROUP_ID, GENERAL_COUNTER_DHD_TX_POST_PKTS_0 + radio_idx, cntr_arr);
    bdmf_session_print(session, "\tTX_POST packets = %d\n", cntr_arr[0]);
    
    drv_cntr_counter_read(GENERAL_CNTR_GROUP_ID, GENERAL_COUNTER_DHD_TX_COMPLETE_PKTS_0 + radio_idx, cntr_arr);
    bdmf_session_print(session, "\tTX_COMPLETE packets = %d\n", cntr_arr[0]);
    
    drv_cntr_counter_read(GENERAL_CNTR_GROUP_ID, GENERAL_COUNTER_DHD_RX_COMPLETE_PKTS_0 + radio_idx, cntr_arr);
    bdmf_session_print(session, "\tRX_COMPLETE packets = %d\n", cntr_arr[0]);        

    drv_cntr_counter_read(VARIOUS_CNTR_GROUP_ID, COUNTER_DHD_TX_FPM_USED_0 + radio_idx, cntr_arr);
    bdmf_session_print(session, "\tFPM in use = %d\n", cntr_arr[(COUNTER_DHD_TX_FPM_USED_0 + radio_idx) % 2]);
   
    return 0;
}


static int _rdd_print_dhd_drop_counters(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    uint32_t radio_idx, i, cntr_id;
    uint32_t cntr_arr[MAX_NUM_OF_COUNTERS_PER_READ] = {};
    
    radio_idx = (uint32_t)parm[0].value.unumber;
    
    bdmf_session_print(session, "SSID drop counters\n");

    bdmf_session_print(session, "Radio %d\n", radio_idx);                    
    for (i = 0; i < 16; i++)
    {
        cntr_id = COUNTER_DHD_TX_DROP_0_SSID_0 + radio_idx*16 + i;
        drv_cntr_counter_read(VARIOUS_CNTR_GROUP_ID, cntr_id, cntr_arr);
        bdmf_session_print(session, "\tSSID%d = %d\n", i, cntr_arr[cntr_id % 2]);
    }

    bdmf_session_print(session, "AC Flow Ring Full counters\n");


    bdmf_session_print(session, "Radio %d\n", radio_idx);                
    for (i = 0; i < 5; i++)
    {
        cntr_id = COUNTER_DHD_TX_FR_FULL_0_AC_0 + radio_idx*5 + i;
        drv_cntr_counter_read(VARIOUS_CNTR_GROUP_ID, cntr_id, cntr_arr);
        bdmf_session_print(session, "\tAC%d = %d\n", i, cntr_arr[cntr_id % 2]);
    }

    cntr_id = COUNTER_DHD_RX_DROP_0 + radio_idx;
    drv_cntr_counter_read(VARIOUS_CNTR_GROUP_ID, cntr_id, cntr_arr);
    bdmf_session_print(session, "FPM alloc failed for radio %d = %d\n", radio_idx, cntr_arr[cntr_id % 2]);

    return 0;
}

static int _rdd_print_dhd_flow_rings_cache(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    uint32_t radio_idx,i;
    RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS *cache_lkp_ptr, cache_lkp;
    RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_DTS *cache_ctx_ptr, ctx_entry;

    radio_idx = (uint32_t)parm[0].value.unumber;
    
    bdmf_session_print(session, "FlowRings Cache\n");

    cache_lkp_ptr = (RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_DTS *)RDD_DHD_FLOW_RING_CACHE_LKP_TABLE_PTR(get_runner_idx(dhd_tx_post_runner_image));
    cache_ctx_ptr = (RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_DTS *)RDD_DHD_FLOW_RING_CACHE_CTX_TABLE_PTR(get_runner_idx(dhd_tx_post_runner_image));

    bdmf_session_print(session, "Radio   Ring ID  Inv  Base        Size    Flags       SSID   RD_Idx  WR_Idx\n");
    bdmf_session_print(session, "=================================================================\n");

    cache_lkp_ptr += radio_idx*16;
    cache_ctx_ptr += radio_idx*16;
    
    for (i = 0; i < 16; i++, cache_lkp_ptr++, cache_ctx_ptr++)
    {
        /* Read Flowring cache entry */
        RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_FLOW_RING_ID_READ(cache_lkp.flow_ring_id, cache_lkp_ptr);        
        RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY_INVALID_READ(cache_lkp.invalid, cache_lkp_ptr);
        bdmf_session_print(session, "%-5d   %-7d  %-3d  ", (i >> 4), cache_lkp.flow_ring_id, cache_lkp.invalid);

        /* Read FlowRing context entry */
        RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLOW_RING_BASE_LOW_READ(ctx_entry.flow_ring_base_low, cache_ctx_ptr);
        RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_SIZE_READ(ctx_entry.size, cache_ctx_ptr);
        RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_FLAGS_READ(ctx_entry.flags, cache_ctx_ptr);
        RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_SSID_READ(ctx_entry.ssid, cache_ctx_ptr);
        RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_RD_IDX_READ(ctx_entry.rd_idx, cache_ctx_ptr);
        RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY_WR_IDX_READ(ctx_entry.wr_idx, cache_ctx_ptr);
        bdmf_session_print(session, "0x%-8x  %-5d   0x%-8x  %-4d  %-6d  %-6d\n",
            ctx_entry.flow_ring_base_low, ctx_entry.size, ctx_entry.flags, ctx_entry.ssid, ctx_entry.rd_idx, ctx_entry.wr_idx);
    }

    return 0;
}

static int _rdd_set_dhd_fpm_th(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    uint16_t  low_th, high_th;
       
    low_th = (uint32_t)parm[0].value.unumber;
    high_th = (uint32_t)parm[1].value.unumber;
    
    rdd_dhd_helper_fpm_thresholds_set(low_th, high_th);
    
    return 0;
}

static int _rdd_get_dhd_fpm_th(bdmf_session_handle session, const bdmfmon_cmd_parm_t parm[], uint16_t n_parms)
{
    uint16_t  low_th, high_th;

    rdd_dhd_helper_fpm_thresholds_get(&low_th, &high_th);
    
    bdmf_session_print(session, "DHD FPM low threshold = %d, high threshold = %d\n", low_th, high_th);
    
    return 0;    
}


void rdd_dhd_helper_shell_cmds_init(bdmfmon_handle_t rdd_dir)
{
    MAKE_BDMF_SHELL_CMD(rdd_dir, "pdtxp", "print DHD TX POST descriptor", _rdd_print_dhd_tx_post_desc,
        BDMFMON_MAKE_PARM("radio_idx", "radio index", BDMFMON_PARM_NUMBER, 0),
        BDMFMON_MAKE_PARM("ring_id", "ring id", BDMFMON_PARM_NUMBER, 0),
        BDMFMON_MAKE_PARM("desc_id", "desc id", BDMFMON_PARM_NUMBER, 0));
    MAKE_BDMF_SHELL_CMD(rdd_dir, "pdrxp",   "print DHD RX POST descriptor", _rdd_print_dhd_rx_post_desc,
        BDMFMON_MAKE_PARM("radio_idx", "radio index", BDMFMON_PARM_NUMBER, 0),
        BDMFMON_MAKE_PARM("desc_id", "desc id", BDMFMON_PARM_NUMBER, 0));
    MAKE_BDMF_SHELL_CMD(rdd_dir, "pdtxc",   "print DHD TX COMPLETE descriptor", _rdd_print_dhd_tx_complete_desc,
        BDMFMON_MAKE_PARM("radio_idx", "radio index", BDMFMON_PARM_NUMBER, 0),
        BDMFMON_MAKE_PARM("desc_id", "desc id", BDMFMON_PARM_NUMBER, 0));
    MAKE_BDMF_SHELL_CMD(rdd_dir, "pdrxc",   "print DHD RX COMPLETE descriptor", _rdd_print_dhd_rx_complete_desc,
        BDMFMON_MAKE_PARM("radio_idx", "radio index", BDMFMON_PARM_NUMBER, 0),
        BDMFMON_MAKE_PARM("desc_id", "desc id", BDMFMON_PARM_NUMBER, 0));  
    MAKE_BDMF_SHELL_CMD(rdd_dir, "pddc",   "print DHD drop counters", _rdd_print_dhd_drop_counters,
        BDMFMON_MAKE_PARM("radio_idx", "radio index", BDMFMON_PARM_NUMBER, 0));
    MAKE_BDMF_SHELL_CMD(rdd_dir, "pdfrc",   "print DHD Flow Rings cache", _rdd_print_dhd_flow_rings_cache,
        BDMFMON_MAKE_PARM("radio_idx", "radio index", BDMFMON_PARM_NUMBER, 0));
    MAKE_BDMF_SHELL_CMD(rdd_dir, "pdgc",   "print DHD general counters", _rdd_print_dhd_general_counters,
        BDMFMON_MAKE_PARM("radio_idx", "radio index", BDMFMON_PARM_NUMBER, 0));
    MAKE_BDMF_SHELL_CMD(rdd_dir, "sdfl",   "set DHD FPM thresholds", _rdd_set_dhd_fpm_th,
        BDMFMON_MAKE_PARM("low_prio_limit", "low_prio_limit", BDMFMON_PARM_NUMBER, 0),
        BDMFMON_MAKE_PARM("high_prio_limit", "high_prio_limit", BDMFMON_PARM_NUMBER, 0));
    MAKE_BDMF_SHELL_CMD_NOPARM(rdd_dir, "gdfl",  "get DHD FPM thresholds", _rdd_get_dhd_fpm_th);
}

