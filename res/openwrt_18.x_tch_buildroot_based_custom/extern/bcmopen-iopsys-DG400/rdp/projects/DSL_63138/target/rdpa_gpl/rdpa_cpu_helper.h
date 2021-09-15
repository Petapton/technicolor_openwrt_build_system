/*
* <:copyright-BRCM:2013:DUAL/GPL:standard
* 
*    Copyright (c) 2013 Broadcom 
*    All Rights Reserved
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License, version 2, as published by
* the Free Software Foundation (the "GPL").
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* 
* A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
* writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
* Boston, MA 02111-1307, USA.
* 
* :>
*/
#ifndef _RDPA_CPU_HELPER_H
#define _RDPA_CPU_HELPER_H

#ifndef CM3390
#include "rdp_cpu_ring_defs.h"
#include "rdp_mm.h"
#include "linux/nbuff.h"
#include "linux/prefetch.h"
#else
#include "packing.h"
#include "rdp_drv_bpm.h"
#include "bdmf_system_common.h"
#include "rdpa_cpu.h"
#endif
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
#include "rdd_data_structures_auto.h"
#include "rdd_runner_proj_defs.h"
#endif

#define SIZE_OF_RING_DESCRIPTOR sizeof(CPU_RX_DESCRIPTOR)

#if defined(DSL_63138) || defined(DSL_63148) || defined(WL4908)
#define RUNNER_SOURCE_PORT_PCI  19
#else
#define RUNNER_SOURCE_PORT_PCI  8
#endif

extern rdpa_if map_rdd_to_rdpa_if[];

#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
extern rdpa_if rdd_vport_to_rdpa_if_map[];

static inline void decode_rnr_src(CPU_RX_DESCRIPTOR *rx_desc, rdpa_cpu_rx_info_t *rx_pd)
{
    rx_pd->src_port = rdd_vport_to_rdpa_if_map[rx_desc->wan.source_port];

/* need to change via 6836 rx desc  */
#if defined(CONFIG_BCM96836)
    if (!rx_desc->wan.is_src_lan)
#else
    if (rx_desc->wan.is_src_wan)
#endif
        rx_pd->reason_data = rx_desc->wan.wan_flow_id;
    else if (rx_desc->cpu_vport.vport >= RDD_CPU_VPORT_FIRST && rx_desc->cpu_vport.vport <= RDD_CPU_VPORT_LAST)
        rx_pd->dest_ssid = rx_desc->cpu_vport.ssid;
}
#else
static inline rdpa_if rdpa_cpu_rx_srcport_to_rdpa_if(uint16_t rdd_srcport, int flow_id)
{
#ifndef BRCM_FTTDP
    /* Special case for wifi packets: if src_port is PCI then need to set
     * SSID */
    return (rdd_srcport == RUNNER_SOURCE_PORT_PCI) ? rdpa_if_ssid0 +
        flow_id : map_rdd_to_rdpa_if[rdd_srcport];
#else
    switch (rdd_srcport)
    {
    case 0:
        return rdpa_if_wan0;
    /* .. upto number-of-lan-ifs + 1 */
    case 1 ... rdpa_if_lan_max - rdpa_if_lan0 + 1 + 1:
        return rdpa_if_lan0 + rdd_srcport - 1;
    default:
        return rdpa_if_none;
    }
#endif
}
#endif

#ifdef CM3390

#pragma pack(push, 1)
typedef struct
{
    uint32_t offset:9         __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t rsv1:7           __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t priority:3       __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t src_subid:5      __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t src_port:5       __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t rsv2:2           __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t pd_size:1        __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t packet_size:12   __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t token_idx:16     __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t ddr:2            __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t rsv0:1           __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t valid:1          __PACKING_ATTRIBUTE_FIELD_LEVEL__;
} DOCSIS_PD;
#pragma pack(pop)

typedef void (*cpu_tx_dir_queue)(const rdpa_cpu_tx_info_t *info, void *raw_desc);

static inline int cpu_get_docsis_hdr_len(void)
{
    return 8;
}

static inline void cpu_tx_encode_docsis_hdr(void *docsis_hdr, uint32_t offset, uint32_t token, uint32_t wan_type, rdpa_if srcport)
{
    DOCSIS_PD *docsispd = (DOCSIS_PD *)docsis_hdr;
    uint32_t *swapptr = (uint32_t *)docsis_hdr;
    rdp_fpm_index fpm_idx = *(rdp_fpm_index *)&token;

    memset(docsispd, 0, sizeof(DOCSIS_PD));

    /* fill the docsis header */
    docsispd->pd_size = 0; /* always 8 */
    switch (srcport)
    {
        case rdpa_if_lan0:
            docsispd->src_port = RDD_LAN0_VPORT;
            break;
        case rdpa_if_lan1:
            docsispd->src_port = RDD_LAN1_VPORT;
            break;
        case rdpa_if_lan2:
            docsispd->src_port = RDD_LAN2_VPORT;
            break;
        case rdpa_if_lan3:
            docsispd->src_port = RDD_LAN3_VPORT;
            break;
        case rdpa_if_lan4:
            docsispd->src_port = RDD_LAN4_VPORT;
            break;

        case rdpa_if_ssid0 ... rdpa_if_ssid7:
            docsispd->src_port = RDD_WIFI_VPORT;
            docsispd->src_subid = srcport - rdpa_if_ssid0;
            break;

        case rdpa_if_ssid8 ... rdpa_if_ssid15:
            docsispd->src_port = RDD_WIFI_VPORT;
            docsispd->src_subid = srcport - rdpa_if_ssid8;
            break;

        default:
        case rdpa_if_cpu:
            docsispd->src_port = RDD_CPU_VPORT;
            break;
    }
    docsispd->ddr = fpm_idx.ddr;
    docsispd->valid = wan_type;
    docsispd->offset = offset + sizeof(DOCSIS_PD);
    docsispd->token_idx = fpm_idx.token_index;
    docsispd->packet_size = fpm_idx.token_size;

    *swapptr = swap4bytes(*swapptr);
    swapptr++;
    *swapptr = swap4bytes(*swapptr);
}

static void cpu_tx_ds_forward(const rdpa_cpu_tx_info_t *info, void *raw_desc)
{
    RDD_CPU_TX_DS_FORWARD_DESCRIPTOR_DTS *rnr_desc = (RDD_CPU_TX_DS_FORWARD_DESCRIPTOR_DTS *)raw_desc;
    rdp_fpm_index fpm_idx = *(rdp_fpm_index *)&info->data;

    memset(rnr_desc, 0, sizeof(RDD_CPU_TX_DS_FORWARD_DESCRIPTOR_DTS));

    rnr_desc->src_bridge_port = info->port == rdpa_if_wan0 ? RDD_WAN0_VPORT : RDD_WAN1_VPORT;
    rnr_desc->payload_offset = info->data_offset;
    rnr_desc->packet_length = info->data_size;
    rnr_desc->ih_class = info->port == rdpa_if_wan0 ? 8 : 9;
    rnr_desc->buffer_number = fpm_idx.token_index;
    rnr_desc->ddr_id = fpm_idx.ddr;
    rnr_desc->valid = 1;
}

static void cpu_tx_us_forward(const rdpa_cpu_tx_info_t *info, void *raw_desc)
{
    RDD_CPU_TX_US_FORWARD_DESCRIPTOR_DTS *rnr_desc = (RDD_CPU_TX_US_FORWARD_DESCRIPTOR_DTS *)raw_desc;
    rdp_fpm_index fpm_idx = *(rdp_fpm_index *)&info->data;

    memset(rnr_desc, 0, sizeof(RDD_CPU_TX_US_FORWARD_DESCRIPTOR_DTS));
    /* TODO:Convert switch to map */
    if (info->port >= rdpa_if_ssid0  && info->port <= rdpa_if_ssid15)
    {
        rnr_desc->src_bridge_port = RDD_WIFI_VPORT;
        rnr_desc->src_ssid = info->port - rdpa_if_ssid0;
        rnr_desc->ih_class = 2;
    }
    else
    {
        rnr_desc->src_bridge_port = info->port - rdpa_if_lan0 + RDD_VPORT_ID_1;
        rnr_desc->ih_class = info->port - rdpa_if_lan0 + 10;
    }
    rnr_desc->payload_offset = info->data_offset;
    rnr_desc->packet_length = info->data_size + 4; /*must padd the packet for the runner*/
    rnr_desc->buffer_number = fpm_idx.token_index;
    rnr_desc->ddr_id = fpm_idx.ddr;
    rnr_desc->valid = 1;
}

static void cpu_tx_ds_egress(const rdpa_cpu_tx_info_t *info, void *raw_desc)
{
    RDD_CPU_TX_DS_EGRESS_DESCRIPTOR_DTS *rnr_desc = (RDD_CPU_TX_DS_EGRESS_DESCRIPTOR_DTS *)raw_desc;
    rdp_fpm_index fpm_idx = *(rdp_fpm_index *)&info->data;

    memset(rnr_desc , 0 , sizeof(RDD_CPU_TX_DS_EGRESS_DESCRIPTOR_DTS));
    if (info->port >= rdpa_if_ssid0  && info->port <= rdpa_if_ssid15)
    {
        rnr_desc->emac = RDD_WIFI_VPORT;
        rnr_desc->dst_ssid = info->port - rdpa_if_ssid0;
    }
    else
    {
        rnr_desc->emac = info->port - rdpa_if_lan0 + RDD_LAN0_VPORT;
    }
    rnr_desc->tx_queue = info->x.lan.queue_id;
    rnr_desc->src_bridge_port = RDD_CPU_VPORT;
    rnr_desc->payload_offset = info->data_offset;
    rnr_desc->packet_length = info->data_size; /*must padd the packet for the runner*/
    rnr_desc->buffer_number = fpm_idx.token_index;
    rnr_desc->ddr_id = fpm_idx.ddr;
    rnr_desc->valid = 1;
}

static void cpu_tx_us_egress(const rdpa_cpu_tx_info_t *info, void *raw_desc)
{
    RDD_CPU_TX_US_EGRESS_DESCRIPTOR_DTS *rnr_desc = (RDD_CPU_TX_US_EGRESS_DESCRIPTOR_DTS *)raw_desc;
    rdp_fpm_index fpm_idx = *(rdp_fpm_index *)&info->data;

    memset(rnr_desc, 0, sizeof(RDD_CPU_TX_US_EGRESS_DESCRIPTOR_DTS));
    rnr_desc->wan_flow = info->port;
    rnr_desc->tx_queue = info->x.wan.queue_id;
    rnr_desc->payload_offset = info->data_offset;
    rnr_desc->packet_length = info->data_size + 4; /*must padd the packet for the runner*/
    rnr_desc->buffer_number = fpm_idx.token_index;
    rnr_desc->ddr_id = fpm_idx.ddr;
    rnr_desc->valid = 1;
}

static cpu_tx_dir_queue cpu_tx_array[2][2] =
{
    {cpu_tx_ds_egress, cpu_tx_us_egress},
    {cpu_tx_us_forward, cpu_tx_ds_forward}
};

inline int rdpa_cpu_tx_pd_set(const rdpa_cpu_tx_info_t *info, void *raw_desc)
{
    int dir = (info->port == rdpa_if_wan0) | (info->port == rdpa_if_wan1);
    cpu_tx_array[info->method][dir](info, raw_desc);

    return 0;
}

#define CMIM_INC_BM_MASK    0x8000
#define CMIM_PRIORITY_MASK  0x7000

/* in 3390 Cpu RX descriptor is different than Legacy RDP */
inline int rdpa_cpu_rx_pd_get(void *raw_desc /* Input */, rdpa_cpu_rx_info_t *rx_pd/* Output */)
{
    RDD_CPU_RX_DESCRIPTOR_DTS *p_desc = (RDD_CPU_RX_DESCRIPTOR_DTS *)raw_desc;
    RDD_CPU_RX_DESCRIPTOR_DTS rx_desc;
    rdp_fpm_index fpm_idx = {};

    /* copy descriptor to local cached memory, assuming arm memcpy is efficiany */
    memcpy(&rx_desc, p_desc, sizeof(RDD_CPU_RX_DESCRIPTOR_DTS));

    fpm_idx.token_size = rx_desc.packet_length;
    fpm_idx.ddr = rx_desc.ddr_id;
    fpm_idx.token_index = rx_desc.buffer_number;
    fpm_idx.token_valid = 1;

    rx_pd->data = *((uint32_t *)&fpm_idx);
    rx_pd->size = rx_desc.packet_length;
    rx_pd->src_port = rdpa_cpu_rx_srcport_to_rdpa_if(rx_desc.src_bridge_port, rx_desc.src_ssid);
    rx_pd->reason = (rdpa_cpu_reason) rx_desc.reason;
    rx_pd->data_offset = rx_desc.payload_offset;
    rx_pd->dest_ssid = rx_desc.wifi_cmim_union;
    rx_pd->cmim_priority = (rx_desc.wifi_cmim_union & CMIM_PRIORITY_MASK) >> 12;
    rx_pd->cmim_inc_bm = (rx_desc.wifi_cmim_union & CMIM_INC_BM_MASK) ? 1 : 0;
    rx_pd->cmim_if_bitmask = (rx_desc.wifi_cmim_union & CMIM_INC_BM_MASK) ? rx_desc.wifi_egress_params_cmim_union : 0;

    if (rx_pd->cmim_inc_bm)
        rx_pd->cmim_if_bitmask = rdpa_cpu_rx_srcport_to_rdpa_if(rx_pd->cmim_if_bitmask, 0);
    else
        rx_pd->cmim_if_bitmask = 0;

    return 0;
}
#endif

#ifndef CM3390
/** \addtogroup cpu_rx
 * @{
 */
#define RDPA_MAX_BUFFERS_IN_RING_CACHE   32

#if defined(CONFIG_BCM963138)
#define PACKET_PREFETCH_CACHE_LINES 3
#else
#define PACKET_PREFETCH_CACHE_LINES 2
#endif

typedef struct
{
    uint32_t ring_size;
    uint32_t descriptor_size;
    CPU_RX_DESCRIPTOR *head;
    CPU_RX_DESCRIPTOR *base;
    CPU_RX_DESCRIPTOR *end;
    uint32_t buff_cache_cnt;
    void ** buff_cache;
} RING_DESCRIPTOR_S;
#endif

#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)

/** Translates raw packet to formated rdpa_cpu_rx_info_t structure.
 *
 * \param[in]   raw_desc           Raw packet descriptor.
 * \param[out]  rx_pd              Formated packet descriptor.
 * \return BDMF_ERR_NO_MORE if packet descriptor owned by runner subsystem.
 */
inline int rdpa_cpu_rx_pd_get(void *raw_desc, rdpa_cpu_rx_info_t *rx_pd)
{
    CPU_RX_DESCRIPTOR rx_desc;
    register uint64_t dword0 asm ("x8");
    register uint64_t dword1 asm ("x9");

    /* Using this Aarch64 Assembly optimization to reduce uncached descriptor read time
     * ldnp: load pair of registers with non-temporal hint (Uncached) */

    __asm__("ldnp   %1, %2,[%0]" \
        :  "=r" (raw_desc), "=r" (dword0), "=r" (dword1) \
        : "0" (raw_desc));

    /* Swap two 32bit words in single instruction */
    *(uint64_t*)&rx_desc.word0 = swap4bytes64(dword0);
    *(uint64_t*)&rx_desc.word2 = swap4bytes64(dword1);

/* xxx: need to change via 6836 rx desc  */
#if defined(CONFIG_BCM96836)
    if (0)
#else
    if (rx_desc.abs.ownership == OWNERSHIP_HOST)
#endif
    {
        uintptr_t phys_ptr;

        phys_ptr = ((uintptr_t)rx_desc.abs.host_buffer_data_ptr_hi) << 32;
        phys_ptr |= rx_desc.abs.host_buffer_data_ptr_low;
        rx_pd->data = (void *)phys_to_virt(phys_ptr);

        rx_pd->size = rx_desc.abs.packet_length;

        /* The place of data_ofset is the same in all structures in this union we could use any.*/
        rx_pd->data_offset = rx_desc.wan.data_offset;

        decode_rnr_src(&rx_desc, rx_pd);

        rx_pd->reason = (rdpa_cpu_reason)rx_desc.wan.reason;
        rx_pd->wl_metadata = rx_desc.wl_metadata;
        rx_pd->mcast_tx_prio = rx_desc.mcast_tx_prio;

        return 0;
    }

    return BDMF_ERR_NO_MORE;
}

/** Resets the descriptor with a new data pointer and sets descriptor ownership to the runner subsystem.
 *
 * \param[in]   raw_desc           Raw packet descriptor.
 * \param[out]  data               New data pointer.
 */
inline void rdpa_cpu_ring_rest_desc(volatile void *__restrict__ raw_desc, void *__restrict__ data)
{
    /* in XRDP address is 48 bits, using 64bit register to store the descriptor at once */
    uint64_t *word0 = (uint64_t *)raw_desc;

    /* set 48bit address and clean ownership to runner */
    *word0 = swap4bytes64((uint64_t)data & 0x1FFFFFFFFFFFF);
}

/** Check if there is a valid packet in descriptor
 *
 * \param[in]   raw_desc            Raw packet descriptor.
 * \return true if there is a valid packet in descriptor.
 */
const inline int rdpa_cpu_ring_not_empty(const void *raw_desc)
{
    CPU_RX_DESCRIPTOR *rx_desc = (CPU_RX_DESCRIPTOR *)raw_desc;

/* xxx: need to change via 6836 rx desc  */
#if defined(CONFIG_BCM96836)
    return 0;
#else
    return rx_desc->abs.ownership == OWNERSHIP_HOST;
#endif

}

/** Check if there is a valid packet in descriptor
 *
 * \param[in]   raw_desc            Raw packet descriptor.
 * \return      Data pointer.
 */
const inline uintptr_t rdpa_cpu_ring_get_data_ptr(const void *raw_desc)
{
    CPU_RX_DESCRIPTOR *rx_desc = (CPU_RX_DESCRIPTOR *)raw_desc;
    return (uintptr_t)rx_desc->abs.host_buffer_data_ptr_hi << 32 |
            rx_desc->abs.host_buffer_data_ptr_low;
}
#elif !defined(CM3390)
static inline int rdpa_cpu_rx_pd_get(void *raw_desc, rdpa_cpu_rx_info_t *rx_pd)
{
    CPU_RX_DESCRIPTOR rx_desc;
#if defined(__ARMEL__)
    register uint32_t w0 __asm__("r8");
    register uint32_t w1 __asm__("r9");
    register uint32_t w2 __asm__("r10");

    READ_RX_DESC(raw_desc, w0, w1, w2);
#elif defined(__AARCH64EL__)
    register uint64_t dw0 __asm__("x9");
    register uint64_t dw1 __asm__("x10");

    READ_RX_DESC(raw_desc, dw0, dw1);
#else
    CPU_RX_DESCRIPTOR *p_desc = (CPU_RX_DESCRIPTOR *)raw_desc;
#endif

    /* p_desc is in uncached mem so reading 32bits at a time into
     cached mem improves performance will be change to BurstBank read later*/
#if defined(__ARMEL__)
    rx_desc.word2 = swap4bytes(w2);
#elif defined(__AARCH64EL__)
    *((uint64_t *)&rx_desc.word2) = swap4bytes64(dw1);
#else
    rx_desc.word2 = p_desc->word2;
#endif
    if (rx_desc.word2 & 0x80000000)
    {
        rx_desc.word2 &= ~0x80000000;
        rx_pd->data = (void *)PHYS_TO_CACHED(rx_desc.word2);

#if defined(__ARMEL__)
        rx_desc.word0 = swap4bytes(w0);
#elif defined(__AARCH64EL__)
        *((uint64_t *)&rx_desc.word0) = swap4bytes64(dw0);
#else
        rx_desc.word0 = p_desc->word0;
#endif
        rx_pd->size = rx_desc.packet_length;
        rx_pd->reason_data = rx_desc.flow_id;
        cache_invalidate_len_outer_first((void *)rx_pd->data, rx_pd->size);

#if !defined(DSL_63138) && !defined(DSL_63148) && !defined(WL4908)
#if !defined(__AARCH64EL__)
        rx_desc.word1 = p_desc->word1;
        rx_desc.word1 = swap4bytes(rx_desc.word1);
        rx_desc.word3 = p_desc->word3;
        rx_desc.word3 = swap4bytes(rx_desc.word3);
#endif
        rx_pd->reason = (rdpa_cpu_reason)rx_desc.reason;
        rx_pd->dest_ssid = rx_desc.dst_ssid;
        rx_pd->wl_metadata = rx_desc.wl_metadata;
        rx_pd->ptp_index = p_desc->ip_sync_1588_idx;
        rx_pd->data_offset = 0;
#else
        rx_pd->reason = rdpa_cpu_rx_reason_ip_flow_miss;
#endif

#if defined(CONFIG_BCM_PKTRUNNER_CSUM_OFFLOAD)
        rx_pd->rx_csum_verified = rx_desc.is_chksum_verified;
#endif
        rx_pd->src_port = rdpa_cpu_rx_srcport_to_rdpa_if(rx_desc.source_port, rx_desc.flow_id);
        return 0;
    }

    return BDMF_ERR_NO_MORE;
}

/** Resets the descriptor with a new data pointer and sets descriptor ownership to the runner subsystem.
 *
 * \param[in]   raw_desc           Raw packet descriptor.
 * \param[out]  data               New data pointer.
 */
static inline void rdpa_cpu_ring_rest_desc(volatile void *__restrict__ raw_desc, void *__restrict__ data)
{
    volatile CPU_RX_DESCRIPTOR *p_desc = (volatile CPU_RX_DESCRIPTOR *)raw_desc;

    p_desc->word2 = swap4bytes(((VIRT_TO_PHYS(data)) & 0x7fffffff));
}

/** Check if there is a valid packet in descriptor
 *
 * \param[in]   raw_desc            Raw packet descriptor.
 * \return true if there is a valid packet in descriptor.
 */
static const inline int rdpa_cpu_ring_not_empty(const void *raw_desc)
{
   CPU_RX_DESCRIPTOR *p_desc = (CPU_RX_DESCRIPTOR *)raw_desc;

#if defined(__ARMEL__) || defined(WL4908)
    return p_desc->word2 & 0x80;
#else
    return p_desc->word2 & 0x80000000;
#endif
}

/** Check if there is a valid packet in descriptor
 *
 * \param[in]   raw_desc            Raw packet descriptor.
 * \return      Data pointer.
 */
static const inline uintptr_t rdpa_cpu_ring_get_data_ptr(const void *raw_desc)
{
    CPU_RX_DESCRIPTOR *rx_desc = (CPU_RX_DESCRIPTOR *)raw_desc;
    return rx_desc->host_buffer_data_pointer;
}

/** Allocate buffers in the ring buffer cache.
 *
 * \param[in]   p_ring           Ring descriptor.
 * \return Buffer Pointer, NULL - Error.
 */
static inline void *rdpa_cpu_databuf_alloc(RING_DESCRIPTOR_S *p_ring)
{
    if (likely(p_ring->buff_cache_cnt))
    {
        return (void *)(p_ring->buff_cache[--p_ring->buff_cache_cnt]);
    }
    else
    {
        uint32_t alloc_cnt;
        /* refill the local cache from global pool */
#if (defined(CONFIG_BCM_BPM) || defined(CONFIG_BCM_BPM_MODULE))
        int i;
        if (gbpm_alloc_mult_buf(RDPA_MAX_BUFFERS_IN_RING_CACHE, (void **)p_ring->buff_cache) == GBPM_ERROR)
        {
            /* BPM returns either all the buffers requested or none */
            alloc_cnt = 0;
            goto test_alloc;
        }

        /* no cache invalidation of buffers is needed for buffers coming from BPM */

        /*reserve space for headroom & FKB */
        for (i = 0; i < RDPA_MAX_BUFFERS_IN_RING_CACHE; i++)
        {
            p_ring->buff_cache[i] = (void *)PFKBUFF_TO_PDATA((void *)(p_ring->buff_cache[i]), BCM_PKT_HEADROOM);
        }

        alloc_cnt = RDPA_MAX_BUFFERS_IN_RING_CACHE;
#else
        uint32_t *datap;
        /* allocate from kernel directly */
        datap = kmalloc(BCM_PKTBUF_SIZE, GFP_ATOMIC);

        if (!datap)
        {
            alloc_cnt = 0;
        }
        /* do a cache invalidate of the buffer */
        INV_RANGE((unsigned long)datap, BCM_PKTBUF_SIZE);

        /*reserve space for headroom & FKB */
        p_ring->buff_cache[0] = (void *)PFKBUFF_TO_PDATA((void *)(datap), BCM_PKT_HEADROOM);

        /* always return only one buffer when BPM is not enabled */
        alloc_cnt = 1;
        goto test_alloc;
#endif
test_alloc:
        if (alloc_cnt)
        {
            p_ring->buff_cache_cnt = alloc_cnt;
            return (void *)(p_ring->buff_cache[--p_ring->buff_cache_cnt]);
        }
    }
    return NULL;
}

/** Free a data buffer pointer.
 *
 * \param[in]   databuff           Data buffer ptr.
 */

static void rdpa_cpu_databuff_free(void *databuff)
{
    cache_invalidate_len(databuff, BCM_MAX_PKT_LEN);
#if (defined(CONFIG_BCM_BPM) || defined(CONFIG_BCM_BPM_MODULE))
    gbpm_free_buf(databuff);
#else
    kfree(databuff);
#endif
}

/** Delete a runner ring, free the buffer descriptors and
 *  buffers in buff_cache.
 *
 * \param[in]   p_ring           Ring Descriptor ptr.
 * \return 0 - Success, Error otherwise.
 */

static int rdpa_cpu_rx_delete_ring(RING_DESCRIPTOR_S *p_ring)
{
    uint32_t entry;
    volatile CPU_RX_DESCRIPTOR *p_desc;

    if (!p_ring->ring_size)
    {
        return -1;
    }

    /*free the data buffers in ring */
    for (p_desc = (volatile CPU_RX_DESCRIPTOR *)p_ring->base, entry = 0; entry < p_ring->ring_size;
                    p_desc++, entry++)
    {
        if (p_desc->word2)
        {
            p_desc->ownership = OWNERSHIP_HOST;
            rdpa_cpu_databuff_free((void *)PHYS_TO_CACHED(p_desc->word2));
            p_desc->word2 = 0;
        }
    }

    /* free any buffers in buff_cache */
    while (p_ring->buff_cache_cnt)
    {
        void *free_ptr = (void *)p_ring->buff_cache[--p_ring->buff_cache_cnt];
        if (free_ptr)
            rdpa_cpu_databuff_free(free_ptr);
    }

    /*free buff_cache */
    if (p_ring->buff_cache)
        CACHED_FREE(p_ring->buff_cache);

    /*delete the ring of descriptors*/
    if (p_ring->base)
        rdp_mm_aligned_free((void *)NONCACHE_TO_CACHE(p_ring->base),
                        p_ring->ring_size * sizeof(CPU_RX_DESCRIPTOR));

    p_ring->ring_size = 0;

    return 0;
}

/** Create a runner ring, free the buffer descriptors and
 *  buffers in buff_cache.
 *
 * \param[in]   p_ring           Ring Descriptor.
 * \param[in]   size             Ring size.
 * \param[out]  ring_base        Pointer to allocated ring.
 *
 * \return 0 - Success, Error otherwise.
 */

static inline int rdpa_cpu_rx_create_ring(RING_DESCRIPTOR_S *p_ring, uint32_t size, uint32_t **ring_base)
{
    volatile CPU_RX_DESCRIPTOR *p_desc;
    uint32_t        entry;
    void            *data_ptr = 0;
    bdmf_phys_addr_t        phy_addr;

    if (p_ring->ring_size)
    {
        return -1;
    }

    /*set ring parameters*/
    p_ring->ring_size     = size;
    p_ring->descriptor_size = sizeof(CPU_RX_DESCRIPTOR);
    p_ring->buff_cache_cnt = 0;


    /*TODO:update the comment  allocate buff_cache which helps to reduce the overhead of when
     * allocating data buffers to ring descriptor */
    p_ring->buff_cache = (void **)(kmalloc(sizeof(void *) * RDPA_MAX_BUFFERS_IN_RING_CACHE, GFP_ATOMIC));
    if (p_ring->buff_cache == NULL)
    {
        return -1;
    }

    /*allocate ring descriptors - must be non-cacheable memory*/
    p_ring->base = (CPU_RX_DESCRIPTOR *)rdp_mm_aligned_alloc(sizeof(CPU_RX_DESCRIPTOR) * size, &phy_addr);
    if (p_ring->base == NULL)
    {
        rdpa_cpu_rx_delete_ring(p_ring);
        return -1;
    }

    /*initialize descriptors*/
    for (p_desc = p_ring->base, entry = 0; entry < size; p_desc++, entry++)
    {
        memset((void *)p_desc, 0, sizeof(*p_desc));

        /*allocate actual packet in DDR*/
        data_ptr = rdpa_cpu_databuf_alloc(p_ring);
        if (!data_ptr)
        {
            rdpa_cpu_rx_delete_ring(p_ring);
            return -1;
        }
        rdpa_cpu_ring_rest_desc(p_desc, data_ptr);
    }

    /*set the ring header to the first entry*/
    p_ring->head = p_ring->base;

    /*using pointer arithmetics calculate the end of the ring*/
    p_ring->end  = p_ring->base + size;

    *ring_base = (uint32_t *)(uintptr_t)phy_addr;

    return 0;
}

/** @} end of add to cpu_rx Doxygen group */
#endif

#ifndef CM3390
/** Get packet from ring.
 *
 * \param[in]   p_ring           Ring Descriptor ptr.
 * \param[out]  p_fkb            Allocated fkb.
 * \param[out]  info             Recieved packet metadata.
 * \return 0 - Success, Error otherwise.
 */
static inline int rdpa_cpu_get_pkt_from_ring(RING_DESCRIPTOR_S *__restrict__ p_ring,
                                             struct fkbuff **__restrict__ p_fkb,
                                             rdpa_cpu_rx_info_t *__restrict__ info)
{
    uint32_t ret;
    CPU_RX_DESCRIPTOR *p_desc = p_ring->head;
    void *p_newbuf;
    struct fkbuff *fkb_p;

    ret = rdpa_cpu_rx_pd_get(p_desc, info);
    if (unlikely(ret))
    {
        return  ret;
    }

    /* A valid packet is received try to allocate a new data buffer and
    * refill the ring before giving the packet to upper layers
    */
    p_newbuf = rdpa_cpu_databuf_alloc(p_ring);

    /*validate allocation*/
    if (unlikely(!p_newbuf))
    {
        /*assign old data buffer back to ring*/
        p_newbuf   = (void *)info->data;
        info->data = NULL;
    }

    rdpa_cpu_ring_rest_desc(p_desc, p_newbuf);

    /* move to next descriptor, wrap around if needed */
    if (++p_ring->head == p_ring->end)
        p_ring->head = p_ring->base;

    if (!info->data)
        return BDMF_ERR_INTERNAL;

    /* create the fkb */
    fkb_p = PDATA_TO_PFKBUFF(info->data, BCM_PKT_HEADROOM);

#if defined(CONFIG_BCM_KF_ARM_PLD)
    /* Prefetch one cache line of the FKB buffer */
    bcm_prefetch(fkb_p, 1);
#endif

    *p_fkb = fkb_init((void *)info->data , BCM_PKT_HEADROOM, (void *)info->data, info->size);

#if defined(CONFIG_BCM_PKTRUNNER_CSUM_OFFLOAD)
    (*p_fkb)->rx_csum_verified = info->rx_csum_verified;
#endif

#if defined(CONFIG_BCM_KF_ARM_PLD)
     /* Prefetch the first 96/128 bytes of the packet */
    bcm_prefetch((const void *)(info->data - L1_CACHE_BYTES), PACKET_PREFETCH_CACHE_LINES);
#endif
    return 0;
}
#endif
#endif
