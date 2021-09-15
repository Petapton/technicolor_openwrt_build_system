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

#ifndef _RDD_IPTV_H
#define _RDD_IPTV_H

#include "rdd.h"
#include "rdd_common.h"
#include "rdpa_types.h"
#include "rdpa_wlan_mcast.h"

typedef struct iptv_params
{
    uint32_t key_offset;
    uint32_t hash_tbl_idx;;
} iptv_params_t;

typedef struct
{
    uint16_t wlan_mcast_index;
    uint64_t egress_port_vector;
    uint16_t ic_context;
    rdpa_iptv_channel_key_t key;
    rdpa_wlan_mcast_fwd_table_t wlan_mcast_fwd_table;
#define mc_key_vid key.vid
#define mc_key_mac key.mcast_group.mac
#define mc_key_gr_ip key.mcast_group.l3.gr_ip
#define mc_key_src_ip key.mcast_group.l3.src_ip
#define mc_wlan_idx wlan_mcast_index
#define mc_egress_port_vector egress_port_vector
#define mc_ic_context ic_context
} rdd_iptv_entry_t;

#define IPTV_DDR_CTX_TBL (RDD_IPTV_DDR_CONTEXT_TABLE_SIZE * sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS))
#define ANY_VID                          0xFFFF

#define IPTV_CHANNEL_INDEX_GET(key_idx, ctx_idx) ((key_idx << RDD_IPTV_DDR_CONTEXT_TABLE_LOG2_SIZE) | (ctx_idx & ((1 << RDD_IPTV_DDR_CONTEXT_TABLE_LOG2_SIZE) - 1)))
#define IPTV_KEY_INDEX_GET(channel_idx)          (channel_idx >> RDD_IPTV_DDR_CONTEXT_TABLE_LOG2_SIZE)
#define IPTV_CTX_INDEX_GET(channel_idx)          (channel_idx & ((1 << RDD_IPTV_DDR_CONTEXT_TABLE_LOG2_SIZE) - 1))

int rdd_iptv_module_init(const rdd_module_t *module);
void rdd_iptv_lkp_method_set(rdpa_iptv_lookup_method method);
int rdd_iptv_ctx_table_ddr_init(uint16_t fpm_min_pool_size);
void rdd_iptv_ctx_table_ddr_destroy(void);
void rdd_iptv_ddr_context_entry_get(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS *ddr_ctx_entry, uint32_t entry_idx);

void rdd_iptv_hash_key_entry_compose(rdpa_iptv_channel_key_t *key, RDD_IPTV_HASH_LKP_ENTRY_DTS *hash_key_entry);
void rdd_iptv_hash_key_entry_decompose(RDD_IPTV_HASH_LKP_ENTRY_DTS hash_key_entry, rdpa_iptv_channel_key_t *key);
void rdd_iptv_hash_result_entry_compose(uint32_t ctx_idx, RDD_IPTV_HASH_RESULT_ENTRY_DTS *hash_result_entry);
void rdd_iptv_hash_result_entry_decompose(RDD_IPTV_HASH_RESULT_ENTRY_DTS hash_result_entry, uint32_t *ctx_idx);

/* TODO: move to Rdd_mcast_resolution*/
int rdd_iptv_result_entry_add(rdd_iptv_entry_t *iptv_entry, uint8_t *ic_ctx, uint32_t *head_idx, uint32_t ctr,
    uint32_t *entry_idx);
void rdd_iptv_result_entry_modify(rdd_iptv_entry_t *iptv_entry, uint8_t *ic_ctx, uint32_t entry_idx);
int rdd_iptv_result_entry_get(uint32_t ctx_idx, rdd_iptv_entry_t *rdd_iptv_entry, uint8_t *ic_ctx);
int rdd_iptv_result_entry_find(rdpa_iptv_channel_key_t *key, uint32_t head_idx, uint32_t *entry_idx);
int rdd_iptv_result_entry_delete(uint32_t entry_idx, uint32_t *head_idx, uint32_t *cntr_id);
int rdd_iptv_result_entry_next_idx_get(uint32_t entry_idx, uint32_t *next_idx);
int rdd_iptv_cntr_idx_get(uint32_t entry_idx, uint32_t *cntr_idx);
#endif /* _RDD_IPTV_H */
