/*
   <:copyright-BRCM:2014:DUAL/GPL:standard
   
      Copyright (c) 2014 Broadcom 
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

#ifdef _CFE_
#include "lib_types.h"
#include "lib_string.h"
#endif
#include "rdd_tuple_lkp.h"

int rdd_nat_cache_init(const rdd_module_t *module)
{
    RDD_NAT_CACHE_CFG_RES_OFFSET_WRITE_G(module->res_offset, module->cfg_ptr, 0);
    RDD_NAT_CACHE_CFG_CONTEXT_OFFSET_WRITE_G(module->context_offset, module->cfg_ptr, 0);
    RDD_NAT_CACHE_CFG_KEY_OFFSET_WRITE_G(((natc_params_t *)module->params)->connection_key_offset, module->cfg_ptr, 0);

    return BDMF_ERR_OK;
}

#define RDD_TRACE_IPV4_FLOW_KEY(title, src_ip, dst_ip, src_port, dst_port, proto) do { \
    RDD_TRACE("%s = { src_ip = %u.%u.%u.%u, dst_ip = %u.%u.%u.%u, prot = %d, src_port = %d, dst_port = %d\n", \
        title, (uint8_t)(src_ip >> 24) & 0xff, \
        (uint8_t)(src_ip >> 16) & 0xff, \
        (uint8_t)(src_ip >> 8) & 0xff, \
        (uint8_t)(src_ip) & 0xff, \
        (uint8_t)(dst_ip >> 24) & 0xff, \
        (uint8_t)(dst_ip >> 16) & 0xff, \
        (uint8_t)(dst_ip >> 8) & 0xff, \
        (uint8_t)(dst_ip) & 0xff, \
        proto, src_port, dst_port); \
} while (0)


void rdd_ip_class_key_entry_decompose(rdpa_ip_flow_key_t *tuple_entry, uint8_t *sub_tbl_id, uint8_t *tuple_entry_ptr)
{
    RDD_NAT_CACHE_LKP_ENTRY_DTS lkp_entry;

    RDD_BTRACE("tuple_entry %p, tuple_entry_ptr = %p\n", tuple_entry, tuple_entry_ptr);

#ifdef FIRMWARE_LITTLE_ENDIAN
    SWAPBYTES(tuple_entry_ptr, sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS));
#endif
    memcpy(&lkp_entry, tuple_entry_ptr, sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS));

    RDD_TRACE_IPV4_FLOW_KEY("tuple_entry_ptr", lkp_entry.src_ip, lkp_entry.dst_ip, lkp_entry.src_port,
        lkp_entry.dst_port, lkp_entry.protocol);

    if (tuple_entry)
    {
        tuple_entry->dst_ip.addr.ipv4 = lkp_entry.dst_ip;
        tuple_entry->src_ip.addr.ipv4 = lkp_entry.src_ip;
        tuple_entry->dst_port = lkp_entry.dst_port;
        tuple_entry->src_port = lkp_entry.src_port;
        tuple_entry->prot = lkp_entry.protocol;
        tuple_entry->dst_ip.family = lkp_entry.key_extend;
    }
    if (sub_tbl_id)
        *sub_tbl_id = lkp_entry.sub_table_id;
}

int rdd_ip_class_key_entry_compose(rdpa_ip_flow_key_t *tuple_entry, uint8_t *connection_entry)
{
    RDD_NAT_CACHE_LKP_ENTRY_DTS lkp_entry = {};
    bdmf_error_t rc = BDMF_ERR_OK;
    uint32_t ipv6_src_ip_crc, ipv6_dst_ip_crc;

    RDD_BTRACE("tuple_entry %p, connection_entry = %p\n", tuple_entry, connection_entry);
    RDD_TRACE_IPV4_FLOW_KEY("tuple_entry", tuple_entry->src_ip.addr.ipv4, tuple_entry->dst_ip.addr.ipv4,
        tuple_entry->src_port, tuple_entry->dst_port, tuple_entry->prot);

    if (tuple_entry->dst_ip.family == bdmf_ip_family_ipv4)
    {
        lkp_entry.dst_ip = tuple_entry->dst_ip.addr.ipv4;
        lkp_entry.src_ip = tuple_entry->src_ip.addr.ipv4;
    }
    else
    {
        rdd_crc_ipv6_addr_calc(&tuple_entry->src_ip, &ipv6_src_ip_crc);
        rdd_crc_ipv6_addr_calc(&tuple_entry->dst_ip, &ipv6_dst_ip_crc);
        lkp_entry.dst_ip = ipv6_dst_ip_crc;
        lkp_entry.src_ip = ipv6_src_ip_crc;
    }

    lkp_entry.dst_port = tuple_entry->dst_port;
    lkp_entry.src_port = tuple_entry->src_port;
    lkp_entry.protocol = tuple_entry->prot;
    lkp_entry.key_extend = tuple_entry->dst_ip.family;
    lkp_entry.valid = 1;

    memcpy(connection_entry, &lkp_entry, sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS));
#ifdef FIRMWARE_LITTLE_ENDIAN
    SWAPBYTES(connection_entry, sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS));
#endif

    return rc;
}

void rdd_3_tupples_ip_flows_enable(bdmf_boolean enable)
{
    RDD_NAT_CACHE_CFG_THREE_TUPLE_ENABLE_WRITE_G(enable, RDD_NAT_CACHE_CFG_ADDRESS_ARR, 0);
}

void rdd_esp_filter_set(rdd_action action)
{
    RDD_NAT_CACHE_CFG_ESP_FILTER_ENABLE_WRITE_G(1, RDD_NAT_CACHE_CFG_ADDRESS_ARR, 0);
    RDD_NAT_CACHE_CFG_ESP_FILTER_ACTION_WRITE_G((action == ACTION_FORWARD) ? 1 : 0, RDD_NAT_CACHE_CFG_ADDRESS_ARR, 0);
}

