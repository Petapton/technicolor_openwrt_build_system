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


#include "bdmf_shell.h"
#include "rdp_map.h"
#include "rdd_runner_reg_dump.h"
#include "rdd_runner_reg_dump_addrs.h"
unsigned int SEGMENTS_ADDRESSES[NUMBER_OF_SEGMENTS] =
{
#ifdef DSL_63138
 0x0 + RUNNER_PRIVATE_0_OFFSET, 0x0 + RUNNER_PRIVATE_1_OFFSET, 0x0 + RUNNER_COMMON_0_OFFSET, 0x8000 + RUNNER_COMMON_1_OFFSET, 0x0, 0x0 + PSRAM_BLOCK_OFFSET,
#endif
#ifdef DSL_63148
 0x0 + RUNNER_PRIVATE_0_OFFSET, 0x0 + RUNNER_PRIVATE_1_OFFSET, 0x0 + RUNNER_COMMON_0_OFFSET, 0x8000 + RUNNER_COMMON_1_OFFSET, 0x0, 0x0 + PSRAM_BLOCK_OFFSET,
#endif
#ifdef WL4908
 0x0 + RUNNER_PRIVATE_0_OFFSET, 0x0 + RUNNER_PRIVATE_1_OFFSET, 0x0 + RUNNER_COMMON_0_OFFSET, 0x8000 + RUNNER_COMMON_1_OFFSET, 0x0, 0x0 + PSRAM_BLOCK_OFFSET,
#endif
};
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT INGRESS_HANDLER_BUFFER =
{
	256,
	{
		{ dump_RDD_IH_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FREE_PACKET_DESCRIPTORS_POOL =
{
	8,
	{
		{ dump_RDD_PACKET_DESCRIPTOR, 0x2000 },
#if defined DSL_63138
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0x2000 },
#endif
		{ dump_RDD_SERVICE_QUEUE_DESCRIPTOR, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_CONTEXT_BUFFER =
{
	128,
	{
		{ dump_RDD_CONNECTION_CONTEXT_BUFFER_ENTRY, 0x6000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_GSO_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_GSO_BUFFER_ENTRY, 0x6400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_GSO_PSEUDO_HEADER_BUFFER =
{
	40,
	{
		{ dump_RDD_GSO_PSEUDO_HEADER_BUFFER_ENTRY, 0x6480 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_PARAMETERS_BLOCK =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x64a8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE =
{
	2,
	{
		{ dump_RDD_BUDGET_ALLOCATOR_ENTRY, 0x64b0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_REASON_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0x64c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_GSO_CHUNK_BUFFER =
{
	128,
	{
		{ dump_RDD_GSO_BUFFER_ENTRY, 0x6500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_SERVICE_QUEUES_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_DS_SERVICE_QUEUE_DESCRIPTOR, 0x6580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_POLICER_TABLE =
{
	16,
	{
		{ dump_RDD_POLICER_ENTRY, 0x6600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_BUFFER_POOL =
{
	176,
	{
		{ dump_RDD_IPSEC_DS_BUFFER, 0x6700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_TABLE =
{
	80,
	{
		{ dump_RDD_IPSEC_SA_DESC, 0x6860 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_TABLE =
{
	80,
	{
		{ dump_RDD_IPSEC_SA_DESC, 0x6d60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_RATE_LIMITER_TABLE =
{
	24,
	{
		{ dump_RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR, 0x7260 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x7560 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH_TX_LOCAL_REGISTERS =
{
	8,
	{
		{ dump_RDD_ETH_TX_LOCAL_REGISTERS_ENTRY, 0x7580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_HEADER_DESCRIPTOR =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_DESCRIPTOR, 0x75c8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_TIMER_SCHEDULER_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY, 0x75d0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_MAIN_PROFILING_BUFFER_RUNNER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x75e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x76e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_CONTROL_TABLE =
{
	148,
	{
		{ dump_RDD_WLAN_MCAST_CONTROL_ENTRY, 0x7700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_WAN_UDP_FILTER_CONTROL_TABLE =
{
	4,
	{
		{ dump_RDD_DS_WAN_UDP_FILTER_CONTROL_ENTRY, 0x7794 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_WLAN_SCRATCH =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x7798 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FC_L2_UCAST_TUPLE_BUFFER =
{
	32,
	{
		{ dump_RDD_FC_L2_UCAST_TUPLE_ENTRY, 0x77a0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RATE_LIMITER_REMAINDER_TABLE =
{
	2,
	{
		{ dump_RDD_RATE_LIMITER_REMAINDER_ENTRY, 0x77c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE =
{
#if defined DSL_63138
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY, 0x7800 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FC_MCAST_CONNECTION2_TABLE =
{
	16,
	{
		{ dump_RDD_FC_MCAST_CONNECTION2_ENTRY, 0x8000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH_TX_QUEUES_POINTERS_TABLE =
{
	4,
	{
		{ dump_RDD_ETH_TX_QUEUE_POINTERS_ENTRY, 0x8800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x8920 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x8940 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT SBPM_REPLY =
{
	128,
	{
		{ dump_RDD_SBPM_REPLY_ENTRY, 0x8980 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH_TX_QUEUES_TABLE =
{
	16,
	{
		{ dump_RDD_ETH_TX_QUEUE_DESCRIPTOR, 0x8a00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_METER_TABLE =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x8e80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FORWARDING_MATRIX_TABLE =
{
	1,
	{
		{ dump_RDD_FORWARDING_MATRIX_ENTRY, 0x8f00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FC_L2_UCAST_CONNECTION_BUFFER =
{
	16,
	{
		{ dump_RDD_FC_L2_UCAST_CONNECTION_ENTRY, 0x8f90 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x8fa0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_FLOW_RING_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_COMPLETE_DESCRIPTOR, 0x8fc0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x8ff0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH_TX_MAC_TABLE =
{
	32,
	{
		{ dump_RDD_ETH_TX_MAC_DESCRIPTOR, 0x9000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT REVERSE_FFI_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x9140 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9240 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9280 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_COMPLETE_RING_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_COMPLETE_RING_DESCRIPTOR, 0x92c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOA_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x92f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_RATE_LIMITER_TABLE =
{
	8,
	{
		{ dump_RDD_RATE_LIMITER_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_ETH_TX_RS_QUEUE_DESCRIPTOR, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_WAN_FLOW_TABLE =
{
	2,
	{
		{ dump_RDD_DS_WAN_FLOW_ENTRY, 0x9c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH0_RX_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_ETH_RX_DESCRIPTORS, 0x9e00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT INGRESS_HANDLER_SKB_DATA_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9f00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_BUFFER, 0x9f80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_WAN_UDP_FILTER_TABLE =
{
	16,
	{
		{ dump_RDD_DS_WAN_UDP_FILTER_ENTRY, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FC_MCAST_PORT_HEADER_BUFFER =
{
	1,
	{
		{ dump_RDD_FC_MCAST_PORT_HEADER_ENTRY, 0xa200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GSO_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xa400 },
#if defined DSL_63138
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xa400 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xa400 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xa400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_CONTEXT_MULTICAST_BUFFER =
{
	64,
	{
		{ dump_RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY, 0xa600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_LAN_ENQUEUE_SQ_PD =
{
#if defined DSL_63138
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xa800 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_TX_BBH_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY, 0xaa00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PROFILING_BUFFER_PICO_RUNNER =
{
	256,
	{
		{ dump_RDD_PROFILING_BUFFER_PICO_RUNNER, 0xab00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_FAST_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xac00 },
#if defined DSL_63138
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xac00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xac00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xac00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE =
{
	8,
	{
		{ dump_RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY, 0xac80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xad00 },
#if defined DSL_63138
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xad00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xad00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR, 0xad00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_SPDSVC_CONTEXT_TABLE =
{
	72,
	{
		{ dump_RDD_SPDSVC_CONTEXT_ENTRY, 0xad80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_STATS_STATE_TABLE =
{
	6,
	{
		{ dump_RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY, 0xadc8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_MAIN_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xadce },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xadd0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_NULL_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xade0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_SERVICE_TM_DESCRIPTOR =
{
	4,
	{
		{ dump_RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY, 0xadf8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_BPM_EXTRA_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xadfc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xae00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xaf00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_QUEUE_PROFILE_TABLE =
{
	16,
	{
		{ dump_RDD_QUEUE_PROFILE, 0xaf80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_RX_SQ_PD_INGRESS_QUEUE =
{
#if defined DSL_63138
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xb000 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xb280 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT EMAC_ABSOLUTE_TX_BBH_COUNTER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb2c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR =
{
#if defined DSL_63138
	10,
	{
		{ dump_RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY, 0xb310 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PICO_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xb31a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb31c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FIFO =
{
	32,
	{
		{ dump_RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY, 0xb320 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_TX_MESSAGE_DATA_BUFFER =
{
	64,
	{
		{ dump_RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY, 0xb3c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GPON_RX_DIRECT_DESCRIPTORS =
{
#if defined DSL_63138
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xb400 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_RX_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_GSO_DESC_TABLE =
{
	128,
	{
		{ dump_RDD_GSO_DESC_ENTRY, 0xb580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_RX_FAST_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_SQ_ENQUEUE_QUEUE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xb680 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xb6c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FLOW_IH_RESPONSE =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_IH_RESPONSE, 0xb6f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb6f8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONNECTION_TABLE_CONFIG, 0xb6fc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_GSO_CONTEXT_TABLE =
{
	132,
	{
		{ dump_RDD_GSO_CONTEXT_ENTRY, 0xb700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CONTEXT_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONTEXT_TABLE_CONFIG, 0xb784 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_ENTRY, 0xb788 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DEBUG_PERIPHERALS_STATUS_REGISTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb78c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xb790 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_COMPLETE_RING_BUFFER =
{
	8,
	{
		{ dump_RDD_DHD_COMPLETE_RING_ENTRY, 0xb7a0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY, 0xb7b8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CONTEXT_CONTINUATION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb7bc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT MULTICAST_HEADER_BUFFER =
{
	64,
	{
		{ dump_RDD_MULTICAST_HEADER_BUFFER, 0xb7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GPON_RX_NORMAL_DESCRIPTORS =
{
#if defined DSL_63138
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xb800 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_PICO_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xb900 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_GPE_COMMAND_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_GPE_COMMAND_PRIMITIVE_ENTRY, 0xb940 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xb980 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FC_MCAST_CONNECTION_TABLE_PLUS =
{
	20,
	{
		{ dump_RDD_FC_MCAST_CONNECTION_ENTRY, 0xb9c0 },
		{ dump_RDD_FC_MCAST_PORT_CONTEXT_ENTRY, 0xb9c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GSO_DESC_PTR =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb9d4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xb9d8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DATA_POINTER_DUMMY_TARGET =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb9e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FIREWALL_IPV6_R16_BUFFER =
{
	4,
	{
		{ dump_RDD_FIREWALL_IPV6_R16_BUFFER_ENTRY, 0xb9f4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT =
{
	8,
	{
		{ dump_RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY, 0xb9f8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_ROUTER_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xba00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_FLOW_RING_DROP_COUNTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xba40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPTV_COUNTERS_BUFFER =
{
	2,
	{
		{ dump_RDD_IPTV_COUNTERS_BUFFER, 0xba54 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_TX_PICO_INGRESS_QUEUE_PTR, 0xba56 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT =
{
	8,
	{
		{ dump_RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY, 0xba58 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xba60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT HASH_BUFFER =
{
	16,
	{
		{ dump_RDD_HASH_BUFFER, 0xba70 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_FAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xba80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DEBUG_BUFFER =
{
	4,
	{
		{ dump_RDD_DEBUG_BUFFER_ENTRY, 0xbac0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FW_MAC_ADDRS =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xbb40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_SYSTEM_CONFIGURATION =
{
	36,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION, 0xbbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD =
{
	2,
	{
		{ dump_RDD_FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD, 0xbbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH_TX_EMACS_STATUS =
{
#if defined DSL_63138
	1,
	{
		{ dump_RDD_ETH_TX_EMACS_STATUS_ENTRY, 0xbbed },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_RX_PD_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbbee },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR_IPSEC, 0xbc00 },
		{ dump_RDD_CPU_RX_DESCRIPTOR_IPSEC, 0xbc00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xbe00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xbe40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xbe50 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_CAM_TABLE =
{
	2,
	{
		{ dump_RDD_IPSEC_SA_DESC_CAM, 0xbe60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xbe80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_CAM_TABLE =
{
	2,
	{
		{ dump_RDD_IPSEC_SA_DESC_CAM, 0xbec0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GSO_TX_DHD_L2_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbee0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_PICO_INGRESS_QUEUE_PTR, 0xbef6 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_L2_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbef8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFER_HEADROOM_SIZE =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE, 0xbf0e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH_TX_SCRATCH =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf10 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_KEY_BUFFER =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0xbf20 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbf30 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbf40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbf50 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT HASH_BASED_FORWARDING_PORT_TABLE =
{
	1,
	{
		{ dump_RDD_HASH_BASED_FORWARDING_PORT_ENTRY, 0xbf60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 0xbf64 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_FAST_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_FAST_INGRESS_QUEUE_PTR, 0xbf66 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR =
{
	2,
	{
		{ dump_RDD_PARALLEL_PROCESSING_IH_BUFFER_PTR, 0xbf68 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_ANY_SRC_PORT_FLOW_COUNTER =
{
	2,
	{
		{ dump_RDD_ANY_SRC_PORT_FLOW_COUNTER, 0xbf6a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbf6c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GSO_TX_DHD_HOST_BUF_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf70 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_DDR_SA_DESC_TABLE_PTR =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbf74 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_HOST_BUF_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf78 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GSO_PICO_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf7c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_MEMLIB_SEMAPHORE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf7e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WAN_PHYSICAL_PORT =
{
	2,
	{
		{ dump_RDD_WAN_PHYSICAL_PORT, 0xbf80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf82 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_RUNNER_CONGESTION_STATE =
{
	2,
	{
		{ dump_RDD_RUNNER_CONGESTION_STATE_ENTRY, 0xbf84 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_BPM_REF_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf86 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_CPU_BPM_REF_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf88 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf8a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf8c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_DDR_SA_DESC_SIZE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf8e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf90 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_IP_LENGTH =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf92 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT PRIVATE_A_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xbf94 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH_TX_INTER_LAN_SCHEDULING_OFFSET =
{
#if defined DSL_63138
	1,
	{
		{ dump_RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY, 0xbf95 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf96 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf97 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_PICO_SEMAPHORE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf98 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FC_ACCEL_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf99 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_SIZE_ASR_8 =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9b },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_MAIN_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PICO_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9d },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_IH_RESPONSE_MUTEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_SLAVE_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_SLAVE_VECTOR, 0xbf9f },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_FW_MAC_ADDRS_COUNT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa1 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_DMA_SYNCHRONIZATION =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa2 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_CPU_SEMAPHORE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa3 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_NEXT_REPLACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_NEXT_REPLACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa5 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_HANDLER_BUFFER =
{
	256,
	{
		{ dump_RDD_IH_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CSO_CHUNK_BUFFER =
{
	128,
	{
		{ dump_RDD_CSO_BUFFER_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CSO_PSEUDO_HEADER_BUFFER =
{
	40,
	{
		{ dump_RDD_CSO_PSEUDO_HEADER_BUFFER_ENTRY, 0x2080 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_PARAMETERS_BLOCK =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x20a8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE =
{
	2,
	{
		{ dump_RDD_BUDGET_ALLOCATOR_ENTRY, 0x20b0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_REASON_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0x20c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_MAIN_PROFILING_BUFFER_RUNNER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x2100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FREE_PACKET_DESCRIPTORS_POOL =
{
	8,
	{
		{ dump_RDD_PACKET_DESCRIPTOR, 0x2200 },
#if defined DSL_63138
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0x2200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_BUFFER, 0x8200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_QUEUE_PROFILE_TABLE =
{
	16,
	{
		{ dump_RDD_QUEUE_PROFILE, 0x8380 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WAN_CHANNELS_8_39_TABLE =
{
	32,
	{
		{ dump_RDD_WAN_CHANNEL_8_39_DESCRIPTOR, 0x8400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_POLICER_TABLE =
{
	16,
	{
		{ dump_RDD_POLICER_ENTRY, 0x8800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_RX_METER_TABLE =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x8900 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_SBPM_REPLY =
{
	128,
	{
		{ dump_RDD_SBPM_REPLY_ENTRY, 0x8980 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_TX_BBH_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY, 0x8a00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FORWARDING_MATRIX_TABLE =
{
	1,
	{
		{ dump_RDD_FORWARDING_MATRIX_ENTRY, 0x8b00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_TIMER_SCHEDULER_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY, 0x8b90 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x8ba0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_TRAFFIC_CLASS_TO_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_US_QUEUE_ENTRY, 0x8bc0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_WAN_FLOW_TABLE =
{
	4,
	{
		{ dump_RDD_US_WAN_FLOW_ENTRY, 0x8c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_HANDLER_SKB_DATA_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE =
{
	8,
	{
		{ dump_RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY, 0x9080 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PROFILING_BUFFER_PICO_RUNNER =
{
	256,
	{
		{ dump_RDD_PROFILING_BUFFER_PICO_RUNNER, 0x9100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x9200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9240 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9280 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PICO_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x92c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FC_L2_UCAST_TUPLE_BUFFER =
{
	32,
	{
		{ dump_RDD_FC_L2_UCAST_TUPLE_ENTRY, 0x92e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RATE_LIMITER_TABLE =
{
	8,
	{
		{ dump_RDD_RATE_LIMITER_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_FLOW_RING_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0x9380 },
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0x9380 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FAST_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x93e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CONNECTION_CONTEXT_BUFFER =
{
	128,
	{
		{ dump_RDD_CONNECTION_CONTEXT_BUFFER_ENTRY, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_CONTEXT_TABLE =
{
	8,
	{
		{ dump_RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY, 0x9800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WAN_CHANNELS_0_7_TABLE =
{
	88,
	{
		{ dump_RDD_WAN_CHANNEL_0_7_DESCRIPTOR, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_TX_MESSAGE_DATA_BUFFER =
{
	64,
	{
		{ dump_RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY, 0xa2c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_RX_POST_FLOW_RING_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0xa300 },
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0xa300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PICO_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0xa360 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_RATE_LIMITER_TABLE =
{
	16,
	{
		{ dump_RDD_INGRESS_RATE_LIMITER_ENTRY, 0xa380 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FC_L2_UCAST_CONNECTION_BUFFER =
{
	16,
	{
		{ dump_RDD_FC_L2_UCAST_CONNECTION_ENTRY, 0xa3d0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_HEADER_DESCRIPTOR =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_DESCRIPTOR, 0xa3e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_ONE_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa3f8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_SPDSVC_CONTEXT_TABLE =
{
	72,
	{
		{ dump_RDD_SPDSVC_CONTEXT_ENTRY, 0xa400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GPON_ABSOLUTE_TX_FIRMWARE_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa448 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa470 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_RX_PICO_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa480 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_GPE_COMMAND_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_GPE_COMMAND_PRIMITIVE_ENTRY, 0xa4c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_ROUTER_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xa540 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOB_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa570 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_RX_FAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DEBUG_BUFFER =
{
	4,
	{
		{ dump_RDD_DEBUG_BUFFER_ENTRY, 0xa5c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FW_MAC_ADDRS =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa640 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xa6c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa6f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE =
{
	2,
	{
		{ dump_RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY, 0xa740 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xa7a0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xa7b0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_FLOW_RING_DROP_COUNTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_ETH0_EEE_MODE_CONFIG_MESSAGE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa7d4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_NULL_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa7d8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xa7e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WAN_TX_SCRATCH =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa7f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CSO_CONTEXT_TABLE =
{
	84,
	{
		{ dump_RDD_CSO_CONTEXT_ENTRY, 0xa800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_BPM_EXTRA_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa854 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE =
{
	1,
	{
		{ dump_RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY, 0xa858 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR =
{
#if defined DSL_63138
	6,
	{
		{ dump_RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY, 0xa878 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_MAIN_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xa87e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_SYSTEM_CONFIGURATION =
{
	36,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION, 0xa880 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_OPTIMIZED_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa8a4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0xa8a8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PICO_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xa8ba },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa8bc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_KEY_BUFFER =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0xa8c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xa8d0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_LAYER2_HEADER_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa8e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_RX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_PICO_INGRESS_QUEUE_PTR, 0xa8ee },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DATA_POINTER_DUMMY_TARGET =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa8f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CONNECTION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONNECTION_TABLE_CONFIG, 0xa8f8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CONTEXT_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONTEXT_TABLE_CONFIG, 0xa8fc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_ENTRY, 0xa900 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DEBUG_PERIPHERALS_STATUS_REGISTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa904 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_TASK_REORDER_FIFO =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY, 0xa908 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IH_BUFFER_BBH_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa90c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa910 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xa918 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CONTEXT_CONTINUATION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa920 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFER_HEADROOM_SIZE =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE, 0xa924 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 0xa926 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROLLER_EXPONENT_TABLE =
{
	1,
	{
		{ dump_RDD_RATE_CONTROLLER_EXPONENT_ENTRY, 0xa928 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_RX_FAST_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_FAST_INGRESS_QUEUE_PTR, 0xa92c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 0xa92e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 0xa930 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR =
{
	2,
	{
		{ dump_RDD_PARALLEL_PROCESSING_IH_BUFFER_PTR, 0xa932 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_ANY_SRC_PORT_FLOW_COUNTER =
{
	2,
	{
		{ dump_RDD_ANY_SRC_PORT_FLOW_COUNTER, 0xa934 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_MEMLIB_SEMAPHORE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa936 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_HOST_DATA_PTR_BUFFER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa938 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETHWAN2_RX_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa93c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RUNNER_CONGESTION_STATE =
{
	2,
	{
		{ dump_RDD_RUNNER_CONGESTION_STATE_ENTRY, 0xa93e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_WAN_ENQUEUE_INGRESS_QUEUE_PTR_ENTRY, 0xa940 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa942 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa944 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT PRIVATE_B_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xa946 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa947 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa948 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FC_ACCEL_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa949 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETHWAN2_SWITCH_PORT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94b },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PACKET_BUFFER_SIZE_ASR_8 =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_MAIN_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94d },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PICO_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_IH_RESPONSE_MUTEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94f },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DSL_PTM_BOND_TX_CONTROL =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa950 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DSL_BUFFER_ALIGNMENT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa951 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_SLAVE_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_SLAVE_VECTOR, 0xa952 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa953 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_FW_MAC_ADDRS_COUNT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa954 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_DMA_SYNCHRONIZATION =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa955 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETHWAN_ABSOLUTE_TX_BBH_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa980 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa988 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GPON_ABSOLUTE_TX_BBH_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa990 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_TX_FAST_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xac00 },
#if defined DSL_63138
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xac00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xac00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xac00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_TX_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xad00 },
#if defined DSL_63138
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xad00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xad00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR, 0xad00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETH1_RX_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_ETH_RX_DESCRIPTORS, 0xb200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_IH_RESPONSE =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_IH_RESPONSE, 0xb6f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT BBH_TX_WAN_CHANNEL_INDEX =
{
	4,
	{
		{ dump_RDD_BBH_TX_WAN_CHANNEL_INDEX, 0xbcb8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DDR_CACHE_FIFO =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FC_MCAST_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x1800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_RX_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x3800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_STATION_TABLE =
{
	10,
	{
		{ dump_RDD_WLAN_MCAST_DHD_STATION_ENTRY, 0x3c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY, 0x3e80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_RADIO_INSTANCE_COMMON_A_DATA =
{
	16,
	{
		{ dump_RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY, 0x3f00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x3f30 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x3f34 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FREE_SKB_INDEXES_DDR_FIFO_TAIL =
{
	4,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_TAIL, 0x3f38 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT BPM_REPLY_RUNNER_A =
{
	48,
	{
		{ dump_RDD_BPM_REPLY, 0x3f40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RATE_SHAPERS_STATUS_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x3f70 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_CURR_OFFSET =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x3ff0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_FIFO =
{
	48,
	{
		{ dump_RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY, 0x4000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_FWD_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_FWD_ENTRY, 0x4600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOA_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x4800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_DDR_QUEUE_DESCRIPTOR, 0x4c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_MAC_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY, 0x4e00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_CONFIG_TABLE =
{
	4,
	{
		{ dump_RDD_INTERRUPT_COALESCING_CONFIG, 0x4f80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_DEI_TABLE =
{
	1,
	{
		{ dump_RDD_DSCP_TO_PBITS_DEI_ENTRY, 0x4fc0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_STATS_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_SSID_STATS_ENTRY, 0x5000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT TRACE_C_TABLE =
{
	8,
	{
		{ dump_RDD_TRACE_C_ENTRY, 0x5180 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_CFG =
{
	20,
	{
		{ dump_RDD_SERVICE_QUEUES_CFG_ENTRY, 0x51a0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x51b4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_RATE_CONTROLLER_EXPONENT_TABLE =
{
	1,
	{
		{ dump_RDD_RATE_CONTROLLER_EXPONENT_ENTRY, 0x51b8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_TIMER_PERIOD =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x51bc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_TIMER_ARMED =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x51be },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_FLOW_RING_CACHE_LKP_TABLE =
{
	2,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY, 0x51c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT PM_COUNTERS_BUFFER =
{
	32,
	{
		{ dump_RDD_PM_COUNTERS_BUFFER, 0x51e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_BUFFER_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x5200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_L4_DST_PORT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_ENTRY, 0x5340 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT L4_DST_PORT_CONTEXT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_CONTEXT, 0x5540 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_SHADOW_WR_PTR_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5740 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0x5760 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_BUFFERS_THRESHOLD =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5770 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_BUFFERS_IN_USE_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5772 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT COMMON_A_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0x5774 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FC_SERVICE_QUEUE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x5775 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT PM_COUNTERS =
{
	6208,
	{
		{ dump_RDD_PM_COUNTERS, 0x5800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_DDR_QUEUE_ADDRESS_ENTRY, 0x7100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT ETHWAN2_RX_INGRESS_QUEUE =
{
#if defined DSL_63138
	8,
	{
		{ dump_RDD_ETHWAN2_RX_DESCRIPTOR, 0x7200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_RING_PACKET_DESCRIPTORS_CACHE =
{
	16,
	{
		{ dump_RDD_CPU_RX_DESCRIPTOR, 0x7300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RING_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_RING_DESCRIPTOR, 0x7500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT MAIN_A_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x7a00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT PICO_A_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x7c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WAN_TX_QUEUES_TABLE =
{
	16,
	{
		{ dump_RDD_WAN_TX_QUEUE_DESCRIPTOR, 0x8000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CONNECTION_BUFFER_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x9000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPV6_HOST_ADDRESS_CRC_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9140 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT EPON_DDR_QUEUE_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_DDR_QUEUE_ADDRESS_ENTRY, 0x9180 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE =
{
#if defined DSL_63138
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0x9200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOB_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x9800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0x9c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_L4_DST_PORT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_ENTRY, 0x9d00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WAN_TX_RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x9f00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_LOOKUP_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0xa800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_RX_RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0xb000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT EPON_DDR_CACHE_FIFO =
{
#if defined DSL_63138
	8,
	{
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0xc000 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_CACHE_CTX_TABLE =
{
	16,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY, 0xc600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT FC_FLOW_IP_ADDRESSES_TABLE =
{
	48,
	{
		{ dump_RDD_FC_FLOW_IP_ADDRESSES_ENTRY, 0xc700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DSL_PTM_BOND_TX_HDR_TABLE =
{
#if defined DSL_63138
	2,
	{
		{ dump_RDD_DSL_PTM_BOND_TX_HDR_ENTRY, 0xc7c0 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT BPM_REPLY_RUNNER_B =
{
	48,
	{
		{ dump_RDD_BPM_REPLY, 0xc7d0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROLLERS_TABLE =
{
	48,
	{
		{ dump_RDD_US_RATE_CONTROLLER_DESCRIPTOR, 0xc800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0xe000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_RING_PACKET_DESCRIPTORS_CACHE =
{
	16,
	{
		{ dump_RDD_CPU_RX_DESCRIPTOR, 0xe800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT IPV4_HOST_ADDRESS_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xe8e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_RADIO_INSTANCE_COMMON_B_DATA =
{
	64,
	{
		{ dump_RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY, 0xe900 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DUMMY_RATE_CONTROLLER_DESCRIPTOR =
{
	64,
	{
		{ dump_RDD_DUMMY_RATE_CONTROLLER_DESCRIPTOR, 0xe9c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT MAIN_B_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xea00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT PICO_B_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xec00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT EPON_DDR_QUEUE_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_DDR_QUEUE_DESCRIPTOR, 0xee00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_FREE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xef00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_CURR_OFFSET =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xef50 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DUMMY_WAN_TX_QUEUE_DESCRIPTOR =
{
	16,
	{
		{ dump_RDD_DUMMY_WAN_TX_QUEUE_DESCRIPTOR, 0xef60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0xef70 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_PUT_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xef80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY, 0xefd0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xf050 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xf058 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR =
{
	2,
	{
		{ dump_RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR, 0xf05c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT COMMON_B_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xf05e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xf05f },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT PACKET_SRAM_TO_DDR_COPY_BUFFER_1 =
{
	128,
	{
		{ dump_RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER, 0xf080 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT PACKET_SRAM_TO_DDR_COPY_BUFFER_2 =
{
	128,
	{
		{ dump_RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER, 0xf100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LAN0_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf180 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LAN5_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf1c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LAN1_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LAN6_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf240 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LAN2_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf280 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LAN7_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf2c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LAN3_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_DHD_FLOW_RING_CACHE_LKP_TABLE =
{
	2,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY, 0xf340 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT LAN4_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf380 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WAN_ENQUEUE_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xf400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT BPM_PACKET_BUFFERS =
{
	2048,
	{
		{ dump_RDD_BPM_PACKET_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT US_CONNECTION_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x80000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT CONTEXT_TABLE =
{
	132,
	{
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_ENTRY, 0x100000 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY, 0x100000 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY, 0x100000 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY, 0x100000 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY, 0x100000 },
		{ dump_RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY, 0x100000 },
		{ dump_RDD_FC_MCAST_FLOW_CONTEXT_ENTRY, 0x100000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0x5d1500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_RX_POST_DDR_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0x5c1100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_DDR_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0x5c9100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_DDR_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0x5d1580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_DDR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_COMPLETE_DESCRIPTOR, 0x5d2d80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT R2D_WR_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT D2R_RD_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT R2D_RD_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT D2R_WR_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_LIST_TABLE =
{
	64,
	{
		{ dump_RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY, 0x5c0000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63138
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_LIST_FORMAT_TABLE =
{
	1,
	{
		{ dump_RDD_WLAN_MCAST_DHD_LIST_ENTRY, 0x5c1000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT INGRESS_HANDLER_BUFFER =
{
	256,
	{
		{ dump_RDD_IH_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FREE_PACKET_DESCRIPTORS_POOL =
{
	8,
	{
		{ dump_RDD_PACKET_DESCRIPTOR, 0x2000 },
#if defined DSL_63148
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0x2000 },
#endif
		{ dump_RDD_SERVICE_QUEUE_DESCRIPTOR, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_CONTEXT_BUFFER =
{
	128,
	{
		{ dump_RDD_CONNECTION_CONTEXT_BUFFER_ENTRY, 0x6000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_GSO_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_GSO_BUFFER_ENTRY, 0x6400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_GSO_PSEUDO_HEADER_BUFFER =
{
	40,
	{
		{ dump_RDD_GSO_PSEUDO_HEADER_BUFFER_ENTRY, 0x6480 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_PARAMETERS_BLOCK =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x64a8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE =
{
	2,
	{
		{ dump_RDD_BUDGET_ALLOCATOR_ENTRY, 0x64b0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_REASON_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0x64c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_GSO_CHUNK_BUFFER =
{
	128,
	{
		{ dump_RDD_GSO_BUFFER_ENTRY, 0x6500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_SERVICE_QUEUES_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_DS_SERVICE_QUEUE_DESCRIPTOR, 0x6580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_POLICER_TABLE =
{
	16,
	{
		{ dump_RDD_POLICER_ENTRY, 0x6600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_BUFFER_POOL =
{
	176,
	{
		{ dump_RDD_IPSEC_DS_BUFFER, 0x6700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_TABLE =
{
	80,
	{
		{ dump_RDD_IPSEC_SA_DESC, 0x6860 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_TABLE =
{
	80,
	{
		{ dump_RDD_IPSEC_SA_DESC, 0x6d60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_RATE_LIMITER_TABLE =
{
	24,
	{
		{ dump_RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR, 0x7260 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x7560 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH_TX_LOCAL_REGISTERS =
{
	8,
	{
		{ dump_RDD_ETH_TX_LOCAL_REGISTERS_ENTRY, 0x7580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_HEADER_DESCRIPTOR =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_DESCRIPTOR, 0x75c8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_TIMER_SCHEDULER_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY, 0x75d0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_MAIN_PROFILING_BUFFER_RUNNER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x75e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x76e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_CONTROL_TABLE =
{
	148,
	{
		{ dump_RDD_WLAN_MCAST_CONTROL_ENTRY, 0x7700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_WAN_UDP_FILTER_CONTROL_TABLE =
{
	4,
	{
		{ dump_RDD_DS_WAN_UDP_FILTER_CONTROL_ENTRY, 0x7794 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_WLAN_SCRATCH =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x7798 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FC_L2_UCAST_TUPLE_BUFFER =
{
	32,
	{
		{ dump_RDD_FC_L2_UCAST_TUPLE_ENTRY, 0x77a0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RATE_LIMITER_REMAINDER_TABLE =
{
	2,
	{
		{ dump_RDD_RATE_LIMITER_REMAINDER_ENTRY, 0x77c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE =
{
#if defined DSL_63148
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY, 0x7800 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FC_MCAST_CONNECTION2_TABLE =
{
	16,
	{
		{ dump_RDD_FC_MCAST_CONNECTION2_ENTRY, 0x8000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH_TX_QUEUES_POINTERS_TABLE =
{
	4,
	{
		{ dump_RDD_ETH_TX_QUEUE_POINTERS_ENTRY, 0x8800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x8920 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x8940 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT SBPM_REPLY =
{
	128,
	{
		{ dump_RDD_SBPM_REPLY_ENTRY, 0x8980 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH_TX_QUEUES_TABLE =
{
	16,
	{
		{ dump_RDD_ETH_TX_QUEUE_DESCRIPTOR, 0x8a00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_METER_TABLE =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x8e80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FORWARDING_MATRIX_TABLE =
{
	1,
	{
		{ dump_RDD_FORWARDING_MATRIX_ENTRY, 0x8f00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FC_L2_UCAST_CONNECTION_BUFFER =
{
	16,
	{
		{ dump_RDD_FC_L2_UCAST_CONNECTION_ENTRY, 0x8f90 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x8fa0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_FLOW_RING_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_COMPLETE_DESCRIPTOR, 0x8fc0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x8ff0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH_TX_MAC_TABLE =
{
	32,
	{
		{ dump_RDD_ETH_TX_MAC_DESCRIPTOR, 0x9000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT REVERSE_FFI_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x9140 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9240 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9280 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_COMPLETE_RING_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_COMPLETE_RING_DESCRIPTOR, 0x92c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOA_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x92f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_RATE_LIMITER_TABLE =
{
	8,
	{
		{ dump_RDD_RATE_LIMITER_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_ETH_TX_RS_QUEUE_DESCRIPTOR, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_WAN_FLOW_TABLE =
{
	2,
	{
		{ dump_RDD_DS_WAN_FLOW_ENTRY, 0x9c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH0_RX_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_ETH_RX_DESCRIPTORS, 0x9e00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT INGRESS_HANDLER_SKB_DATA_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9f00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_BUFFER, 0x9f80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_WAN_UDP_FILTER_TABLE =
{
	16,
	{
		{ dump_RDD_DS_WAN_UDP_FILTER_ENTRY, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FC_MCAST_PORT_HEADER_BUFFER =
{
	1,
	{
		{ dump_RDD_FC_MCAST_PORT_HEADER_ENTRY, 0xa200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GSO_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xa400 },
#if defined DSL_63148
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xa400 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xa400 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xa400 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xa400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_CONTEXT_MULTICAST_BUFFER =
{
	64,
	{
		{ dump_RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY, 0xa600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_LAN_ENQUEUE_SQ_PD =
{
#if defined DSL_63148
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xa800 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_TX_BBH_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY, 0xaa00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PROFILING_BUFFER_PICO_RUNNER =
{
	256,
	{
		{ dump_RDD_PROFILING_BUFFER_PICO_RUNNER, 0xab00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_FAST_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xac00 },
#if defined DSL_63148
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xac00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xac00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xac00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE =
{
	8,
	{
		{ dump_RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY, 0xac80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xad00 },
#if defined DSL_63148
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xad00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xad00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR, 0xad00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_SPDSVC_CONTEXT_TABLE =
{
	72,
	{
		{ dump_RDD_SPDSVC_CONTEXT_ENTRY, 0xad80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_STATS_STATE_TABLE =
{
	6,
	{
		{ dump_RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY, 0xadc8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_MAIN_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xadce },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xadd0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_NULL_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xade0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_SERVICE_TM_DESCRIPTOR =
{
	4,
	{
		{ dump_RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY, 0xadf8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_BPM_EXTRA_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xadfc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xae00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xaf00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_QUEUE_PROFILE_TABLE =
{
	16,
	{
		{ dump_RDD_QUEUE_PROFILE, 0xaf80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_RX_SQ_PD_INGRESS_QUEUE =
{
#if defined DSL_63148
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xb000 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xb280 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT EMAC_ABSOLUTE_TX_BBH_COUNTER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb2c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR =
{
#if defined DSL_63148
	10,
	{
		{ dump_RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY, 0xb310 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PICO_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xb31a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb31c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FIFO =
{
	32,
	{
		{ dump_RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY, 0xb320 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_TX_MESSAGE_DATA_BUFFER =
{
	64,
	{
		{ dump_RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY, 0xb3c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GPON_RX_DIRECT_DESCRIPTORS =
{
#if defined DSL_63148
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xb400 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_RX_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_GSO_DESC_TABLE =
{
	128,
	{
		{ dump_RDD_GSO_DESC_ENTRY, 0xb580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_RX_FAST_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_SQ_ENQUEUE_QUEUE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xb680 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xb6c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FLOW_IH_RESPONSE =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_IH_RESPONSE, 0xb6f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb6f8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONNECTION_TABLE_CONFIG, 0xb6fc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_GSO_CONTEXT_TABLE =
{
	132,
	{
		{ dump_RDD_GSO_CONTEXT_ENTRY, 0xb700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CONTEXT_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONTEXT_TABLE_CONFIG, 0xb784 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_ENTRY, 0xb788 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DEBUG_PERIPHERALS_STATUS_REGISTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb78c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xb790 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_COMPLETE_RING_BUFFER =
{
	8,
	{
		{ dump_RDD_DHD_COMPLETE_RING_ENTRY, 0xb7a0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY, 0xb7b8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CONTEXT_CONTINUATION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb7bc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT MULTICAST_HEADER_BUFFER =
{
	64,
	{
		{ dump_RDD_MULTICAST_HEADER_BUFFER, 0xb7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GPON_RX_NORMAL_DESCRIPTORS =
{
#if defined DSL_63148
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xb800 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_PICO_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xb900 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_GPE_COMMAND_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_GPE_COMMAND_PRIMITIVE_ENTRY, 0xb940 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xb980 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FC_MCAST_CONNECTION_TABLE_PLUS =
{
	20,
	{
		{ dump_RDD_FC_MCAST_CONNECTION_ENTRY, 0xb9c0 },
		{ dump_RDD_FC_MCAST_PORT_CONTEXT_ENTRY, 0xb9c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GSO_DESC_PTR =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb9d4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xb9d8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DATA_POINTER_DUMMY_TARGET =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb9e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FIREWALL_IPV6_R16_BUFFER =
{
	4,
	{
		{ dump_RDD_FIREWALL_IPV6_R16_BUFFER_ENTRY, 0xb9f4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT =
{
	8,
	{
		{ dump_RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY, 0xb9f8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_ROUTER_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xba00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_FLOW_RING_DROP_COUNTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xba40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPTV_COUNTERS_BUFFER =
{
	2,
	{
		{ dump_RDD_IPTV_COUNTERS_BUFFER, 0xba54 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_TX_PICO_INGRESS_QUEUE_PTR, 0xba56 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT =
{
	8,
	{
		{ dump_RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY, 0xba58 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xba60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT HASH_BUFFER =
{
	16,
	{
		{ dump_RDD_HASH_BUFFER, 0xba70 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_FAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xba80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DEBUG_BUFFER =
{
	4,
	{
		{ dump_RDD_DEBUG_BUFFER_ENTRY, 0xbac0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FW_MAC_ADDRS =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xbb40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_SYSTEM_CONFIGURATION =
{
	36,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION, 0xbbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD =
{
	2,
	{
		{ dump_RDD_FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD, 0xbbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH_TX_EMACS_STATUS =
{
#if defined DSL_63148
	1,
	{
		{ dump_RDD_ETH_TX_EMACS_STATUS_ENTRY, 0xbbed },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_RX_PD_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbbee },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR_IPSEC, 0xbc00 },
		{ dump_RDD_CPU_RX_DESCRIPTOR_IPSEC, 0xbc00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xbe00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xbe40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xbe50 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_CAM_TABLE =
{
	2,
	{
		{ dump_RDD_IPSEC_SA_DESC_CAM, 0xbe60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xbe80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_CAM_TABLE =
{
	2,
	{
		{ dump_RDD_IPSEC_SA_DESC_CAM, 0xbec0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GSO_TX_DHD_L2_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbee0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_PICO_INGRESS_QUEUE_PTR, 0xbef6 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_L2_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbef8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFER_HEADROOM_SIZE =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE, 0xbf0e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH_TX_SCRATCH =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf10 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_KEY_BUFFER =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0xbf20 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbf30 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbf40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbf50 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT HASH_BASED_FORWARDING_PORT_TABLE =
{
	1,
	{
		{ dump_RDD_HASH_BASED_FORWARDING_PORT_ENTRY, 0xbf60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 0xbf64 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_FAST_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_FAST_INGRESS_QUEUE_PTR, 0xbf66 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR =
{
	2,
	{
		{ dump_RDD_PARALLEL_PROCESSING_IH_BUFFER_PTR, 0xbf68 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_ANY_SRC_PORT_FLOW_COUNTER =
{
	2,
	{
		{ dump_RDD_ANY_SRC_PORT_FLOW_COUNTER, 0xbf6a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbf6c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GSO_TX_DHD_HOST_BUF_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf70 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_DDR_SA_DESC_TABLE_PTR =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbf74 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_HOST_BUF_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf78 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GSO_PICO_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf7c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_MEMLIB_SEMAPHORE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf7e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WAN_PHYSICAL_PORT =
{
	2,
	{
		{ dump_RDD_WAN_PHYSICAL_PORT, 0xbf80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf82 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_RUNNER_CONGESTION_STATE =
{
	2,
	{
		{ dump_RDD_RUNNER_CONGESTION_STATE_ENTRY, 0xbf84 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_BPM_REF_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf86 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_CPU_BPM_REF_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf88 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf8a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf8c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_DDR_SA_DESC_SIZE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf8e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf90 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_IP_LENGTH =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbf92 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT PRIVATE_A_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xbf94 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH_TX_INTER_LAN_SCHEDULING_OFFSET =
{
#if defined DSL_63148
	1,
	{
		{ dump_RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY, 0xbf95 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf96 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf97 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_PICO_SEMAPHORE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf98 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FC_ACCEL_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf99 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_SIZE_ASR_8 =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9b },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_MAIN_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PICO_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9d },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_IH_RESPONSE_MUTEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbf9e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_SLAVE_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_SLAVE_VECTOR, 0xbf9f },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_FW_MAC_ADDRS_COUNT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa1 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_DMA_SYNCHRONIZATION =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa2 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_CPU_SEMAPHORE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa3 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_NEXT_REPLACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_NEXT_REPLACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbfa5 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_HANDLER_BUFFER =
{
	256,
	{
		{ dump_RDD_IH_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CSO_CHUNK_BUFFER =
{
	128,
	{
		{ dump_RDD_CSO_BUFFER_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CSO_PSEUDO_HEADER_BUFFER =
{
	40,
	{
		{ dump_RDD_CSO_PSEUDO_HEADER_BUFFER_ENTRY, 0x2080 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_PARAMETERS_BLOCK =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x20a8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE =
{
	2,
	{
		{ dump_RDD_BUDGET_ALLOCATOR_ENTRY, 0x20b0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_REASON_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0x20c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_MAIN_PROFILING_BUFFER_RUNNER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x2100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FREE_PACKET_DESCRIPTORS_POOL =
{
	8,
	{
		{ dump_RDD_PACKET_DESCRIPTOR, 0x2200 },
#if defined DSL_63148
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0x2200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_BUFFER, 0x8200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_QUEUE_PROFILE_TABLE =
{
	16,
	{
		{ dump_RDD_QUEUE_PROFILE, 0x8380 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WAN_CHANNELS_8_39_TABLE =
{
	32,
	{
		{ dump_RDD_WAN_CHANNEL_8_39_DESCRIPTOR, 0x8400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_POLICER_TABLE =
{
	16,
	{
		{ dump_RDD_POLICER_ENTRY, 0x8800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_RX_METER_TABLE =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x8900 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_SBPM_REPLY =
{
	128,
	{
		{ dump_RDD_SBPM_REPLY_ENTRY, 0x8980 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_TX_BBH_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY, 0x8a00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FORWARDING_MATRIX_TABLE =
{
	1,
	{
		{ dump_RDD_FORWARDING_MATRIX_ENTRY, 0x8b00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_TIMER_SCHEDULER_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY, 0x8b90 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x8ba0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_TRAFFIC_CLASS_TO_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_US_QUEUE_ENTRY, 0x8bc0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_WAN_FLOW_TABLE =
{
	4,
	{
		{ dump_RDD_US_WAN_FLOW_ENTRY, 0x8c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_HANDLER_SKB_DATA_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE =
{
	8,
	{
		{ dump_RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY, 0x9080 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PROFILING_BUFFER_PICO_RUNNER =
{
	256,
	{
		{ dump_RDD_PROFILING_BUFFER_PICO_RUNNER, 0x9100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x9200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9240 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9280 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PICO_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x92c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FC_L2_UCAST_TUPLE_BUFFER =
{
	32,
	{
		{ dump_RDD_FC_L2_UCAST_TUPLE_ENTRY, 0x92e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RATE_LIMITER_TABLE =
{
	8,
	{
		{ dump_RDD_RATE_LIMITER_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_FLOW_RING_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0x9380 },
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0x9380 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FAST_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x93e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CONNECTION_CONTEXT_BUFFER =
{
	128,
	{
		{ dump_RDD_CONNECTION_CONTEXT_BUFFER_ENTRY, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_CONTEXT_TABLE =
{
	8,
	{
		{ dump_RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY, 0x9800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WAN_CHANNELS_0_7_TABLE =
{
	88,
	{
		{ dump_RDD_WAN_CHANNEL_0_7_DESCRIPTOR, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_TX_MESSAGE_DATA_BUFFER =
{
	64,
	{
		{ dump_RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY, 0xa2c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_RX_POST_FLOW_RING_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0xa300 },
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0xa300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PICO_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0xa360 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_RATE_LIMITER_TABLE =
{
	16,
	{
		{ dump_RDD_INGRESS_RATE_LIMITER_ENTRY, 0xa380 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FC_L2_UCAST_CONNECTION_BUFFER =
{
	16,
	{
		{ dump_RDD_FC_L2_UCAST_CONNECTION_ENTRY, 0xa3d0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_HEADER_DESCRIPTOR =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_DESCRIPTOR, 0xa3e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_ONE_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa3f8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_SPDSVC_CONTEXT_TABLE =
{
	72,
	{
		{ dump_RDD_SPDSVC_CONTEXT_ENTRY, 0xa400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GPON_ABSOLUTE_TX_FIRMWARE_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa448 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa470 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_RX_PICO_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa480 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_GPE_COMMAND_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_GPE_COMMAND_PRIMITIVE_ENTRY, 0xa4c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_ROUTER_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xa540 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOB_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa570 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_RX_FAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DEBUG_BUFFER =
{
	4,
	{
		{ dump_RDD_DEBUG_BUFFER_ENTRY, 0xa5c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FW_MAC_ADDRS =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa640 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xa6c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa6f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE =
{
	2,
	{
		{ dump_RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY, 0xa740 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xa7a0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xa7b0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_FLOW_RING_DROP_COUNTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_ETH0_EEE_MODE_CONFIG_MESSAGE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa7d4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_NULL_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa7d8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xa7e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WAN_TX_SCRATCH =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa7f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CSO_CONTEXT_TABLE =
{
	84,
	{
		{ dump_RDD_CSO_CONTEXT_ENTRY, 0xa800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_BPM_EXTRA_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa854 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE =
{
	1,
	{
		{ dump_RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY, 0xa858 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR =
{
#if defined DSL_63148
	6,
	{
		{ dump_RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY, 0xa878 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_MAIN_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xa87e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_SYSTEM_CONFIGURATION =
{
	36,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION, 0xa880 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_OPTIMIZED_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa8a4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0xa8a8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PICO_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xa8ba },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa8bc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_KEY_BUFFER =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0xa8c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xa8d0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_LAYER2_HEADER_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa8e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_RX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_PICO_INGRESS_QUEUE_PTR, 0xa8ee },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DATA_POINTER_DUMMY_TARGET =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa8f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CONNECTION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONNECTION_TABLE_CONFIG, 0xa8f8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CONTEXT_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONTEXT_TABLE_CONFIG, 0xa8fc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_ENTRY, 0xa900 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DEBUG_PERIPHERALS_STATUS_REGISTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa904 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_TASK_REORDER_FIFO =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY, 0xa908 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IH_BUFFER_BBH_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa90c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa910 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xa918 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CONTEXT_CONTINUATION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa920 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFER_HEADROOM_SIZE =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE, 0xa924 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 0xa926 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROLLER_EXPONENT_TABLE =
{
	1,
	{
		{ dump_RDD_RATE_CONTROLLER_EXPONENT_ENTRY, 0xa928 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_RX_FAST_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_FAST_INGRESS_QUEUE_PTR, 0xa92c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 0xa92e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 0xa930 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR =
{
	2,
	{
		{ dump_RDD_PARALLEL_PROCESSING_IH_BUFFER_PTR, 0xa932 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_ANY_SRC_PORT_FLOW_COUNTER =
{
	2,
	{
		{ dump_RDD_ANY_SRC_PORT_FLOW_COUNTER, 0xa934 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_MEMLIB_SEMAPHORE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa936 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_HOST_DATA_PTR_BUFFER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa938 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETHWAN2_RX_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa93c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RUNNER_CONGESTION_STATE =
{
	2,
	{
		{ dump_RDD_RUNNER_CONGESTION_STATE_ENTRY, 0xa93e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_WAN_ENQUEUE_INGRESS_QUEUE_PTR_ENTRY, 0xa940 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa942 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa944 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT PRIVATE_B_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xa946 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa947 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa948 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FC_ACCEL_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa949 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETHWAN2_SWITCH_PORT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94a },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94b },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PACKET_BUFFER_SIZE_ASR_8 =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_MAIN_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94d },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PICO_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_IH_RESPONSE_MUTEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa94f },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DSL_PTM_BOND_TX_CONTROL =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa950 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DSL_BUFFER_ALIGNMENT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa951 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_SLAVE_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_SLAVE_VECTOR, 0xa952 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa953 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_FW_MAC_ADDRS_COUNT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa954 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_DMA_SYNCHRONIZATION =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa955 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETHWAN_ABSOLUTE_TX_BBH_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa980 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa988 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GPON_ABSOLUTE_TX_BBH_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa990 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_TX_FAST_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xac00 },
#if defined DSL_63148
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xac00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xac00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xac00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_TX_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xad00 },
#if defined DSL_63148
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xad00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xad00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR, 0xad00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETH1_RX_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_ETH_RX_DESCRIPTORS, 0xb200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_IH_RESPONSE =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_IH_RESPONSE, 0xb6f0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT BBH_TX_WAN_CHANNEL_INDEX =
{
	4,
	{
		{ dump_RDD_BBH_TX_WAN_CHANNEL_INDEX, 0xbcb8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DDR_CACHE_FIFO =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FC_MCAST_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x1800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_RX_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x3800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_STATION_TABLE =
{
	10,
	{
		{ dump_RDD_WLAN_MCAST_DHD_STATION_ENTRY, 0x3c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY, 0x3e80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_RADIO_INSTANCE_COMMON_A_DATA =
{
	16,
	{
		{ dump_RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY, 0x3f00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x3f30 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x3f34 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FREE_SKB_INDEXES_DDR_FIFO_TAIL =
{
	4,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_TAIL, 0x3f38 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT BPM_REPLY_RUNNER_A =
{
	48,
	{
		{ dump_RDD_BPM_REPLY, 0x3f40 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RATE_SHAPERS_STATUS_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x3f70 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_CURR_OFFSET =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x3ff0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_FIFO =
{
	48,
	{
		{ dump_RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY, 0x4000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_FWD_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_FWD_ENTRY, 0x4600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOA_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x4800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_DDR_QUEUE_DESCRIPTOR, 0x4c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_MAC_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY, 0x4e00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_CONFIG_TABLE =
{
	4,
	{
		{ dump_RDD_INTERRUPT_COALESCING_CONFIG, 0x4f80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_DEI_TABLE =
{
	1,
	{
		{ dump_RDD_DSCP_TO_PBITS_DEI_ENTRY, 0x4fc0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_STATS_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_SSID_STATS_ENTRY, 0x5000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT TRACE_C_TABLE =
{
	8,
	{
		{ dump_RDD_TRACE_C_ENTRY, 0x5180 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_CFG =
{
	20,
	{
		{ dump_RDD_SERVICE_QUEUES_CFG_ENTRY, 0x51a0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x51b4 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_RATE_CONTROLLER_EXPONENT_TABLE =
{
	1,
	{
		{ dump_RDD_RATE_CONTROLLER_EXPONENT_ENTRY, 0x51b8 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_TIMER_PERIOD =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x51bc },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_TIMER_ARMED =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x51be },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_FLOW_RING_CACHE_LKP_TABLE =
{
	2,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY, 0x51c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT PM_COUNTERS_BUFFER =
{
	32,
	{
		{ dump_RDD_PM_COUNTERS_BUFFER, 0x51e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_BUFFER_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x5200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_L4_DST_PORT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_ENTRY, 0x5340 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT L4_DST_PORT_CONTEXT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_CONTEXT, 0x5540 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_SHADOW_WR_PTR_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5740 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0x5760 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_BUFFERS_THRESHOLD =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5770 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_BUFFERS_IN_USE_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5772 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT COMMON_A_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0x5774 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FC_SERVICE_QUEUE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x5775 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT PM_COUNTERS =
{
	6208,
	{
		{ dump_RDD_PM_COUNTERS, 0x5800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_DDR_QUEUE_ADDRESS_ENTRY, 0x7100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT ETHWAN2_RX_INGRESS_QUEUE =
{
#if defined DSL_63148
	8,
	{
		{ dump_RDD_ETHWAN2_RX_DESCRIPTOR, 0x7200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_RING_PACKET_DESCRIPTORS_CACHE =
{
	16,
	{
		{ dump_RDD_CPU_RX_DESCRIPTOR, 0x7300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RING_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_RING_DESCRIPTOR, 0x7500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT MAIN_A_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x7a00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT PICO_A_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x7c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WAN_TX_QUEUES_TABLE =
{
	16,
	{
		{ dump_RDD_WAN_TX_QUEUE_DESCRIPTOR, 0x8000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CONNECTION_BUFFER_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x9000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPV6_HOST_ADDRESS_CRC_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9140 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT EPON_DDR_QUEUE_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_DDR_QUEUE_ADDRESS_ENTRY, 0x9180 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE =
{
#if defined DSL_63148
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0x9200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOB_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x9800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0x9c00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_L4_DST_PORT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_ENTRY, 0x9d00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WAN_TX_RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x9f00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_LOOKUP_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0xa800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_RX_RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0xb000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT EPON_DDR_CACHE_FIFO =
{
#if defined DSL_63148
	8,
	{
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0xc000 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_CACHE_CTX_TABLE =
{
	16,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY, 0xc600 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT FC_FLOW_IP_ADDRESSES_TABLE =
{
	48,
	{
		{ dump_RDD_FC_FLOW_IP_ADDRESSES_ENTRY, 0xc700 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DSL_PTM_BOND_TX_HDR_TABLE =
{
#if defined DSL_63148
	2,
	{
		{ dump_RDD_DSL_PTM_BOND_TX_HDR_ENTRY, 0xc7c0 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT BPM_REPLY_RUNNER_B =
{
	48,
	{
		{ dump_RDD_BPM_REPLY, 0xc7d0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROLLERS_TABLE =
{
	48,
	{
		{ dump_RDD_US_RATE_CONTROLLER_DESCRIPTOR, 0xc800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0xe000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_RING_PACKET_DESCRIPTORS_CACHE =
{
	16,
	{
		{ dump_RDD_CPU_RX_DESCRIPTOR, 0xe800 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT IPV4_HOST_ADDRESS_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xe8e0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_RADIO_INSTANCE_COMMON_B_DATA =
{
	64,
	{
		{ dump_RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY, 0xe900 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DUMMY_RATE_CONTROLLER_DESCRIPTOR =
{
	64,
	{
		{ dump_RDD_DUMMY_RATE_CONTROLLER_DESCRIPTOR, 0xe9c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT MAIN_B_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xea00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT PICO_B_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xec00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT EPON_DDR_QUEUE_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_DDR_QUEUE_DESCRIPTOR, 0xee00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_FREE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xef00 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_CURR_OFFSET =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xef50 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DUMMY_WAN_TX_QUEUE_DESCRIPTOR =
{
	16,
	{
		{ dump_RDD_DUMMY_WAN_TX_QUEUE_DESCRIPTOR, 0xef60 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0xef70 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_PUT_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xef80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY, 0xefd0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xf050 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xf058 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR =
{
	2,
	{
		{ dump_RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR, 0xf05c },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT COMMON_B_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xf05e },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xf05f },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT PACKET_SRAM_TO_DDR_COPY_BUFFER_1 =
{
	128,
	{
		{ dump_RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER, 0xf080 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT PACKET_SRAM_TO_DDR_COPY_BUFFER_2 =
{
	128,
	{
		{ dump_RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER, 0xf100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LAN0_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf180 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LAN5_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf1c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LAN1_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LAN6_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf240 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LAN2_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf280 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LAN7_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf2c0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LAN3_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_DHD_FLOW_RING_CACHE_LKP_TABLE =
{
	2,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY, 0xf340 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT LAN4_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf380 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WAN_ENQUEUE_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xf400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT BPM_PACKET_BUFFERS =
{
	2048,
	{
		{ dump_RDD_BPM_PACKET_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT US_CONNECTION_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x80000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT CONTEXT_TABLE =
{
	132,
	{
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_ENTRY, 0x100000 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY, 0x100000 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY, 0x100000 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY, 0x100000 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY, 0x100000 },
		{ dump_RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY, 0x100000 },
		{ dump_RDD_FC_MCAST_FLOW_CONTEXT_ENTRY, 0x100000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0x5d1500 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_RX_POST_DDR_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0x5c1100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_DDR_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0x5c9100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_DDR_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0x5d1580 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_DDR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_COMPLETE_DESCRIPTOR, 0x5d2d80 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT R2D_WR_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1100 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT D2R_RD_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1200 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT R2D_RD_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1300 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT D2R_WR_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1400 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_LIST_TABLE =
{
	64,
	{
		{ dump_RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY, 0x5c0000 },
		{ 0, 0 },
	}
};
#endif
#if defined DSL_63148
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_LIST_FORMAT_TABLE =
{
	1,
	{
		{ dump_RDD_WLAN_MCAST_DHD_LIST_ENTRY, 0x5c1000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT INGRESS_HANDLER_BUFFER =
{
	256,
	{
		{ dump_RDD_IH_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FREE_PACKET_DESCRIPTORS_POOL =
{
	8,
	{
		{ dump_RDD_PACKET_DESCRIPTOR, 0x2000 },
#if defined WL4908
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0x2000 },
#endif
		{ dump_RDD_SERVICE_QUEUE_DESCRIPTOR, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_CONTEXT_BUFFER =
{
	128,
	{
		{ dump_RDD_CONNECTION_CONTEXT_BUFFER_ENTRY, 0x6000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_GSO_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_GSO_BUFFER_ENTRY, 0x6400 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_GSO_PSEUDO_HEADER_BUFFER =
{
	40,
	{
		{ dump_RDD_GSO_PSEUDO_HEADER_BUFFER_ENTRY, 0x6480 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_PARAMETERS_BLOCK =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x64a8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE =
{
	2,
	{
		{ dump_RDD_BUDGET_ALLOCATOR_ENTRY, 0x64b0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_REASON_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0x64c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_GSO_CHUNK_BUFFER =
{
	128,
	{
		{ dump_RDD_GSO_BUFFER_ENTRY, 0x6500 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_SERVICE_QUEUES_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_DS_SERVICE_QUEUE_DESCRIPTOR, 0x6580 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_POLICER_TABLE =
{
	16,
	{
		{ dump_RDD_POLICER_ENTRY, 0x6600 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_BUFFER_POOL =
{
	176,
	{
		{ dump_RDD_IPSEC_DS_BUFFER, 0x6700 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_TABLE =
{
	80,
	{
		{ dump_RDD_IPSEC_SA_DESC, 0x6860 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_TABLE =
{
	80,
	{
		{ dump_RDD_IPSEC_SA_DESC, 0x6d60 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_RATE_LIMITER_TABLE =
{
	24,
	{
		{ dump_RDD_SERVICE_QUEUES_RATE_LIMITER_DESCRIPTOR, 0x7260 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x7560 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH_TX_LOCAL_REGISTERS =
{
	8,
	{
		{ dump_RDD_ETH_TX_LOCAL_REGISTERS_ENTRY, 0x7580 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_HEADER_DESCRIPTOR =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_DESCRIPTOR, 0x75c8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_TIMER_SCHEDULER_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY, 0x75d0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_MAIN_PROFILING_BUFFER_RUNNER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x75e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x76e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_CONTROL_TABLE =
{
	148,
	{
		{ dump_RDD_WLAN_MCAST_CONTROL_ENTRY, 0x7700 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_WAN_UDP_FILTER_CONTROL_TABLE =
{
	4,
	{
		{ dump_RDD_DS_WAN_UDP_FILTER_CONTROL_ENTRY, 0x7794 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_WLAN_SCRATCH =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x7798 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FC_L2_UCAST_TUPLE_BUFFER =
{
	32,
	{
		{ dump_RDD_FC_L2_UCAST_TUPLE_ENTRY, 0x77a0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RATE_LIMITER_REMAINDER_TABLE =
{
	2,
	{
		{ dump_RDD_RATE_LIMITER_REMAINDER_ENTRY, 0x77c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE =
{
#if defined WL4908
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_CONTEXT_ENTRY, 0x7800 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FC_MCAST_CONNECTION2_TABLE =
{
	16,
	{
		{ dump_RDD_FC_MCAST_CONNECTION2_ENTRY, 0x8000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH_TX_QUEUES_POINTERS_TABLE =
{
	4,
	{
		{ dump_RDD_ETH_TX_QUEUE_POINTERS_ENTRY, 0x8800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x8920 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x8940 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT SBPM_REPLY =
{
	128,
	{
		{ dump_RDD_SBPM_REPLY_ENTRY, 0x8980 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_ETH_TX_RS_QUEUE_DESCRIPTOR, 0x8a00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x9200 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9240 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9280 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_FLOW_RING_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_COMPLETE_DESCRIPTOR, 0x92c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FC_L2_UCAST_CONNECTION_BUFFER =
{
	16,
	{
		{ dump_RDD_FC_L2_UCAST_CONNECTION_ENTRY, 0x92f0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RATE_LIMITER_TABLE =
{
	8,
	{
		{ dump_RDD_RATE_LIMITER_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH_TX_QUEUES_TABLE =
{
	16,
	{
		{ dump_RDD_ETH_TX_QUEUE_DESCRIPTOR, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_METER_TABLE =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x9880 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FORWARDING_MATRIX_TABLE =
{
	1,
	{
		{ dump_RDD_FORWARDING_MATRIX_ENTRY, 0x9900 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x9990 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x99a0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_COMPLETE_RING_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_COMPLETE_RING_DESCRIPTOR, 0x99c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOA_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x99f0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_WAN_FLOW_TABLE =
{
	2,
	{
		{ dump_RDD_DS_WAN_FLOW_ENTRY, 0x9a00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_WAN_UDP_FILTER_TABLE =
{
	16,
	{
		{ dump_RDD_DS_WAN_UDP_FILTER_ENTRY, 0x9c00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FC_MCAST_PORT_HEADER_BUFFER =
{
	1,
	{
		{ dump_RDD_FC_MCAST_PORT_HEADER_ENTRY, 0x9e00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GSO_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xa000 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xa000 },
#if defined WL4908
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xa000 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xa000 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xa000 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xa000 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xa000 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xa000 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_CONTEXT_MULTICAST_BUFFER =
{
	64,
	{
		{ dump_RDD_CONNECTION_CONTEXT_MULTICAST_BUFFER_ENTRY, 0xa200 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_LAN_ENQUEUE_SQ_PD =
{
#if defined WL4908
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xa400 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_TX_BBH_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY, 0xa600 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT REVERSE_FFI_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa700 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_RX_SQ_PD_INGRESS_QUEUE =
{
#if defined WL4908
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xa800 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xaa00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT INGRESS_HANDLER_SKB_DATA_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xab00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_BUFFER, 0xab80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_FAST_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xac00 },
#if defined WL4908
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xac00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xac00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xac00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE =
{
	8,
	{
		{ dump_RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY, 0xac80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xad00 },
#if defined WL4908
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xad00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xad00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR, 0xad00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_SPDSVC_CONTEXT_TABLE =
{
	72,
	{
		{ dump_RDD_SPDSVC_CONTEXT_ENTRY, 0xad80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FAST_MALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xadc8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xadd0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xade0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PROFILING_BUFFER_PICO_RUNNER =
{
	256,
	{
		{ dump_RDD_PROFILING_BUFFER_PICO_RUNNER, 0xae00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xaf00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_QUEUE_PROFILE_TABLE =
{
	16,
	{
		{ dump_RDD_QUEUE_PROFILE, 0xaf80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR_IPSEC, 0xb000 },
		{ dump_RDD_CPU_RX_DESCRIPTOR_IPSEC, 0xb000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb200 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_SQ_ENQUEUE_QUEUE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xb280 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT EMAC_ABSOLUTE_TX_BBH_COUNTER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb2c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR =
{
#if defined WL4908
	10,
	{
		{ dump_RDD_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY, 0xb310 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_MAIN_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xb31a },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_BPM_EXTRA_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb31c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FIFO =
{
	32,
	{
		{ dump_RDD_EMAC_SKB_ENQUEUED_INDEXES_FIFO_ENTRY, 0xb320 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_TX_MESSAGE_DATA_BUFFER =
{
	64,
	{
		{ dump_RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY, 0xb3c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GPON_RX_DIRECT_DESCRIPTORS =
{
#if defined WL4908
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xb400 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_RX_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb500 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_GSO_DESC_TABLE =
{
	128,
	{
		{ dump_RDD_GSO_DESC_ENTRY, 0xb580 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_RX_FAST_PD_INGRESS_QUEUE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb600 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_PICO_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xb680 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb6c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xb6e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FLOW_IH_RESPONSE =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_IH_RESPONSE, 0xb6f0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_MALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb6f8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_GSO_CONTEXT_TABLE =
{
	132,
	{
		{ dump_RDD_GSO_CONTEXT_ENTRY, 0xb700 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb784 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_STATS_STATE_TABLE =
{
	6,
	{
		{ dump_RDD_WLAN_MCAST_SSID_STATS_STATE_ENTRY, 0xb788 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xb78e },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xb790 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_NULL_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb7a0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_SERVICE_TM_DESCRIPTOR =
{
	4,
	{
		{ dump_RDD_DS_SERVICE_TM_DESCRIPTOR_ENTRY, 0xb7b8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_1_OPTIMIZED_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xb7bc },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT MULTICAST_HEADER_BUFFER =
{
	64,
	{
		{ dump_RDD_MULTICAST_HEADER_BUFFER, 0xb7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xb800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_GPE_COMMAND_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_GPE_COMMAND_PRIMITIVE_ENTRY, 0xb840 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_ROUTER_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xb880 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xb8c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT HASH_BUFFER =
{
	16,
	{
		{ dump_RDD_HASH_BUFFER, 0xb8f0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_FAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xb900 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DEBUG_BUFFER =
{
	4,
	{
		{ dump_RDD_DEBUG_BUFFER_ENTRY, 0xb940 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FW_MAC_ADDRS =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xb9c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_COMPLETE_RING_BUFFER =
{
	8,
	{
		{ dump_RDD_DHD_COMPLETE_RING_ENTRY, 0xba40 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xba58 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_1_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xba5c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FC_MCAST_CONNECTION_TABLE_PLUS =
{
	20,
	{
		{ dump_RDD_FC_MCAST_CONNECTION_ENTRY, 0xba60 },
		{ dump_RDD_FC_MCAST_PORT_CONTEXT_ENTRY, 0xba60 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONNECTION_TABLE_CONFIG, 0xba74 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CONTEXT_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONTEXT_TABLE_CONFIG, 0xba78 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_ENTRY, 0xba7c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xba80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DATA_POINTER_DUMMY_TARGET =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbac0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DEBUG_PERIPHERALS_STATUS_REGISTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbad4 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY, 0xbad8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CONTEXT_CONTINUATION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbadc },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xbae0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH_TX_MAC_TABLE =
{
	32,
	{
		{ dump_RDD_ETH_TX_MAC_DESCRIPTOR, 0xbb00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xbc00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_FLOW_RING_DROP_COUNTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbc40 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GSO_DESC_PTR =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbc54 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbc58 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xbc60 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH_TX_SCRATCH =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbc70 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_SYSTEM_CONFIGURATION =
{
	36,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION, 0xbc80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FIREWALL_IPV6_R16_BUFFER =
{
	4,
	{
		{ dump_RDD_FIREWALL_IPV6_R16_BUFFER_ENTRY, 0xbca4 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_CAM_TABLE =
{
	2,
	{
		{ dump_RDD_IPSEC_SA_DESC_CAM, 0xbca8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_CAM_TABLE =
{
	2,
	{
		{ dump_RDD_IPSEC_SA_DESC_CAM, 0xbcc8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GSO_TX_DHD_L2_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbce8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPTV_COUNTERS_BUFFER =
{
	2,
	{
		{ dump_RDD_IPTV_COUNTERS_BUFFER, 0xbcfe },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_L2_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbd00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_TX_PICO_INGRESS_QUEUE_PTR, 0xbd16 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT =
{
	8,
	{
		{ dump_RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY, 0xbd18 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_KEY_BUFFER =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0xbd20 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbd30 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbd40 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xbd50 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT =
{
	8,
	{
		{ dump_RDD_ENQUEUE_PCI_PACKET_CONTEXT_ENTRY, 0xbd60 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbd68 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH_TX_EMACS_STATUS =
{
#if defined WL4908
	1,
	{
		{ dump_RDD_ETH_TX_EMACS_STATUS_ENTRY, 0xbd6d },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD =
{
	2,
	{
		{ dump_RDD_FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD, 0xbd6e },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT HASH_BASED_FORWARDING_PORT_TABLE =
{
	1,
	{
		{ dump_RDD_HASH_BASED_FORWARDING_PORT_ENTRY, 0xbd70 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbd74 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_RX_PD_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbd76 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_PICO_INGRESS_QUEUE_PTR, 0xbd78 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFER_HEADROOM_SIZE =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE, 0xbd7a },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 0xbd7c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_FAST_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_FAST_INGRESS_QUEUE_PTR, 0xbd7e },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR =
{
	2,
	{
		{ dump_RDD_PARALLEL_PROCESSING_IH_BUFFER_PTR, 0xbd80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_ANY_SRC_PORT_FLOW_COUNTER =
{
	2,
	{
		{ dump_RDD_ANY_SRC_PORT_FLOW_COUNTER, 0xbd82 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbd84 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GSO_TX_DHD_HOST_BUF_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbd88 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_DDR_SA_DESC_TABLE_PTR =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xbd8c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_HOST_BUF_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbd90 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GSO_PICO_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbd94 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_MEMLIB_SEMAPHORE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbd96 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WAN_PHYSICAL_PORT =
{
	2,
	{
		{ dump_RDD_WAN_PHYSICAL_PORT, 0xbd98 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbd9a },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RUNNER_CONGESTION_STATE =
{
	2,
	{
		{ dump_RDD_RUNNER_CONGESTION_STATE_ENTRY, 0xbd9c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_PTR =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbd9e },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_BPM_REF_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbda0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_CPU_BPM_REF_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbda2 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbda4 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbda6 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_DDR_SA_DESC_SIZE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbda8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbdaa },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_IP_LENGTH =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xbdac },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT PRIVATE_A_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xbdae },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH_TX_INTER_LAN_SCHEDULING_OFFSET =
{
#if defined WL4908
	1,
	{
		{ dump_RDD_ETH_TX_INTER_LAN_SCHEDULING_OFFSET_ENTRY, 0xbdaf },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb1 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_PICO_SEMAPHORE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb2 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FC_ACCEL_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb3 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb4 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_SIZE_ASR_8 =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb5 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_MAIN_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb6 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb7 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RUNNER_FLOW_IH_RESPONSE_MUTEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdb8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_SLAVE_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_SLAVE_VECTOR, 0xbdb9 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdba },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FAST_MALLOC_RESULT_MUTEX =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbdbb },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_PICO_MALLOC_RESULT_MUTEX =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbdbc },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RX_SBPM_TO_FPM_COPY_SEMAPHORE =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbdbd },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_FW_MAC_ADDRS_COUNT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdbe },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_DMA_SYNCHRONIZATION =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdbf },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_CPU_SEMAPHORE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdc0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_DS_SA_DESC_NEXT_REPLACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdc1 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPSEC_US_SA_DESC_NEXT_REPLACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xbdc2 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GPON_RX_NORMAL_DESCRIPTORS =
{
#if defined WL4908
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0xbe00 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_HANDLER_BUFFER =
{
	256,
	{
		{ dump_RDD_IH_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CSO_CHUNK_BUFFER =
{
	128,
	{
		{ dump_RDD_CSO_BUFFER_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CSO_PSEUDO_HEADER_BUFFER =
{
	40,
	{
		{ dump_RDD_CSO_PSEUDO_HEADER_BUFFER_ENTRY, 0x2080 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_PARAMETERS_BLOCK =
{
	8,
	{
		{ dump_RDD_CPU_PARAMETERS_BLOCK_ENTRY, 0x20a8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE =
{
	2,
	{
		{ dump_RDD_BUDGET_ALLOCATOR_ENTRY, 0x20b0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_REASON_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0x20c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_MAIN_PROFILING_BUFFER_RUNNER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x2100 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FREE_PACKET_DESCRIPTORS_POOL =
{
	8,
	{
		{ dump_RDD_PACKET_DESCRIPTOR, 0x2200 },
#if defined WL4908
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0x2200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_HEADER_BUFFER =
{
	128,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_BUFFER, 0x8200 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_QUEUE_PROFILE_TABLE =
{
	16,
	{
		{ dump_RDD_QUEUE_PROFILE, 0x8380 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WAN_CHANNELS_8_39_TABLE =
{
	32,
	{
		{ dump_RDD_WAN_CHANNEL_8_39_DESCRIPTOR, 0x8400 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_POLICER_TABLE =
{
	16,
	{
		{ dump_RDD_POLICER_ENTRY, 0x8800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_RX_METER_TABLE =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x8900 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_SBPM_REPLY =
{
	128,
	{
		{ dump_RDD_SBPM_REPLY_ENTRY, 0x8980 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_TX_BBH_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_CPU_TX_BBH_DESCRIPTORS_ENTRY, 0x8a00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FORWARDING_MATRIX_TABLE =
{
	1,
	{
		{ dump_RDD_FORWARDING_MATRIX_ENTRY, 0x8b00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_TIMER_SCHEDULER_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TIMER_SCHEDULER_PRIMITIVE_ENTRY, 0x8b90 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x8ba0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_TRAFFIC_CLASS_TO_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_US_QUEUE_ENTRY, 0x8bc0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_WAN_FLOW_TABLE =
{
	4,
	{
		{ dump_RDD_US_WAN_FLOW_ENTRY, 0x8c00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_HANDLER_SKB_DATA_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE =
{
	8,
	{
		{ dump_RDD_INGRESS_CLASSIFICATION_RULE_CFG_ENTRY, 0x9080 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PROFILING_BUFFER_PICO_RUNNER =
{
	256,
	{
		{ dump_RDD_PROFILING_BUFFER_PICO_RUNNER, 0x9100 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x9200 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9240 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9280 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_TIMER_TASK_DESCRIPTOR_TABLE =
{
	8,
	{
		{ dump_RDD_TIMER_TASK_DESCRIPTOR_ENTRY, 0x92c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FC_L2_UCAST_TUPLE_BUFFER =
{
	32,
	{
		{ dump_RDD_FC_L2_UCAST_TUPLE_ENTRY, 0x92e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RATE_LIMITER_TABLE =
{
	8,
	{
		{ dump_RDD_RATE_LIMITER_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_FLOW_RING_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0x9380 },
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0x9380 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FAST_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_FAST_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0x93e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CONNECTION_CONTEXT_BUFFER =
{
	128,
	{
		{ dump_RDD_CONNECTION_CONTEXT_BUFFER_ENTRY, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_CONTEXT_TABLE =
{
	8,
	{
		{ dump_RDD_US_INGRESS_CLASSIFICATION_CONTEXT_ENTRY, 0x9800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WAN_CHANNELS_0_7_TABLE =
{
	88,
	{
		{ dump_RDD_WAN_CHANNEL_0_7_DESCRIPTOR, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_TX_MESSAGE_DATA_BUFFER =
{
	64,
	{
		{ dump_RDD_CPU_TX_MESSAGE_DATA_BUFFER_ENTRY, 0xa2c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_RX_POST_FLOW_RING_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0xa300 },
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0xa300 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_PICO_RUNNER_GLOBAL_REGISTERS_INIT_ENTRY, 0xa360 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_RATE_LIMITER_TABLE =
{
	16,
	{
		{ dump_RDD_INGRESS_RATE_LIMITER_ENTRY, 0xa380 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FC_L2_UCAST_CONNECTION_BUFFER =
{
	16,
	{
		{ dump_RDD_FC_L2_UCAST_CONNECTION_ENTRY, 0xa3d0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_RX_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa3e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_SPDSVC_CONTEXT_TABLE =
{
	72,
	{
		{ dump_RDD_SPDSVC_CONTEXT_ENTRY, 0xa400 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_ONE_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa448 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa450 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa460 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_RX_PICO_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa480 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa4c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_ROUTER_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa500 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa540 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa560 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_RX_FAST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa580 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DEBUG_BUFFER =
{
	4,
	{
		{ dump_RDD_DEBUG_BUFFER_ENTRY, 0xa5c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FW_MAC_ADDRS =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa640 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa6c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_HEADER_DESCRIPTOR =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_HEADER_DESCRIPTOR, 0xa6e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_NULL_BUFFER =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa6f8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xa700 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE =
{
	2,
	{
		{ dump_RDD_US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_ENTRY, 0xa740 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_GPE_COMMAND_PRIMITIVE_TABLE =
{
	2,
	{
		{ dump_RDD_GPE_COMMAND_PRIMITIVE_ENTRY, 0xa7a0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xa7e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOB_PARAM =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xa7f0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CSO_CONTEXT_TABLE =
{
	84,
	{
		{ dump_RDD_CSO_CONTEXT_ENTRY, 0xa800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_ETH0_EEE_MODE_CONFIG_MESSAGE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa854 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GPON_ABSOLUTE_TX_FIRMWARE_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa858 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xa880 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xa8b0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xa8c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xa8f0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_FLOW_RING_DROP_COUNTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa900 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_BPM_EXTRA_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa914 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FAST_MALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa918 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE =
{
	2,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_ENTRY, 0xa920 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WAN_TX_SCRATCH =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa930 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_SYSTEM_CONFIGURATION =
{
	36,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION, 0xa940 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_OPTIMIZED_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa964 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_METER_ENTRY, 0xa968 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_MAIN_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xa97a },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_1_OPTIMIZED_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa97c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETHWAN_ABSOLUTE_TX_BBH_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa980 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT PRIVATE_B_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xa981 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_TIMER_CONTROL_DESCRIPTOR =
{
	2,
	{
		{ dump_RDD_TIMER_CONTROL_DESCRIPTOR, 0xa982 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa984 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa988 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xa989 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_RX_PICO_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_PICO_INGRESS_QUEUE_PTR, 0xa98a },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_1_BUFFERS_BASE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xa98c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GPON_ABSOLUTE_TX_BBH_COUNTER =
{
	1,
	{
		{ dump_RDD_GPON_ABSOLUTE_TX_COUNTER, 0xa990 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE =
{
	1,
	{
		{ dump_RDD_US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_ENTRY, 0xa9b8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_MALLOC_RESULT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa9d8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_KEY_BUFFER =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0xa9e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_CONTEXT_ENTRY, 0xa9f0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_DHD_LAYER2_HEADER_BUFFER =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFER_HEADROOM_SIZE =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE, 0xaa0e },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR =
{
#if defined WL4908
	6,
	{
		{ dump_RDD_US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR_ENTRY, 0xaa10 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION =
{
	2,
	{
		{ dump_RDD_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 0xaa16 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DATA_POINTER_DUMMY_TARGET =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xaa18 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CONNECTION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONNECTION_TABLE_CONFIG, 0xaa20 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CONTEXT_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_CONTEXT_TABLE_CONFIG, 0xaa24 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_ENTRY, 0xaa28 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DEBUG_PERIPHERALS_STATUS_REGISTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xaa2c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_TASK_REORDER_FIFO =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_TASK_REORDER_ENTRY, 0xaa30 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IH_BUFFER_BBH_POINTER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xaa34 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa38 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xaa40 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CONTEXT_CONTINUATION_TABLE_CONFIG =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xaa48 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_RX_FAST_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_CPU_RX_FAST_INGRESS_QUEUE_PTR, 0xaa4c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 0xaa4e },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROLLER_EXPONENT_TABLE =
{
	1,
	{
		{ dump_RDD_RATE_CONTROLLER_EXPONENT_ENTRY, 0xaa50 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 0xaa54 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR =
{
	2,
	{
		{ dump_RDD_PARALLEL_PROCESSING_IH_BUFFER_PTR, 0xaa56 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_ANY_SRC_PORT_FLOW_COUNTER =
{
	2,
	{
		{ dump_RDD_ANY_SRC_PORT_FLOW_COUNTER, 0xaa58 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_MEMLIB_SEMAPHORE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xaa5a },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_HOST_DATA_PTR_BUFFER =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xaa5c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETHWAN2_RX_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xaa60 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RUNNER_CONGESTION_STATE =
{
	2,
	{
		{ dump_RDD_RUNNER_CONGESTION_STATE_ENTRY, 0xaa62 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WAN_ENQUEUE_INGRESS_QUEUE_PTR =
{
	2,
	{
		{ dump_RDD_WAN_ENQUEUE_INGRESS_QUEUE_PTR_ENTRY, 0xaa64 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_PTR =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xaa66 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xaa68 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xaa6a },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa6c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FC_ACCEL_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa6d },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETHWAN2_SWITCH_PORT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa6e },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa6f },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PACKET_BUFFER_SIZE_ASR_8 =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa70 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_MAIN_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa71 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_DMA_SYNCRONIZATION_ADDRESS =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa72 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_IH_RESPONSE_MUTEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa73 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DSL_BUFFER_ALIGNMENT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa74 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_SLAVE_VECTOR =
{
	1,
	{
		{ dump_RDD_PARALLEL_PROCESSING_SLAVE_VECTOR, 0xaa75 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa76 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FAST_MALLOC_RESULT_MUTEX =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaa77 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_PICO_MALLOC_RESULT_MUTEX =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaa78 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_RX_FPM_ALLOC_RESULT_MUTEX =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaa79 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RX_SBPM_TO_FPM_COPY_SEMAPHORE =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaa7a },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_FW_MAC_ADDRS_COUNT =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa7b },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_DMA_SYNCHRONIZATION =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xaa7c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_TX_FAST_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xac00 },
#if defined WL4908
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xac00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xac00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xac00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xac00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_TX_PICO_QUEUE =
{
	8,
	{
		{ dump_RDD_CPU_TX_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_CORE, 0xad00 },
#if defined WL4908
		{ dump_RDD_CPU_TX_DESCRIPTOR_BPM, 0xad00 },
#endif
		{ dump_RDD_CPU_TX_DESCRIPTOR_ABS, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_US_FAST, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO, 0xad00 },
		{ dump_RDD_CPU_TX_DESCRIPTOR_DS_PICO_WIFI, 0xad00 },
		{ dump_RDD_CPU_TX_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_DHD_MESSAGE_DESCRIPTOR, 0xad00 },
		{ dump_RDD_CPU_TX_UPDATE_PD_POOL_QUOTA_MESSAGE_DESCRIPTOR, 0xad00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RUNNER_FLOW_IH_RESPONSE =
{
	8,
	{
		{ dump_RDD_RUNNER_FLOW_IH_RESPONSE, 0xb6f0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH2_RX_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_ETH_RX_DESCRIPTORS, 0xba00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH1_RX_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_ETH_RX_DESCRIPTORS, 0xbc00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETH0_RX_DESCRIPTORS =
{
	8,
	{
		{ dump_RDD_ETH_RX_DESCRIPTORS, 0xbe00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT BBH_TX_WAN_CHANNEL_INDEX =
{
	4,
	{
		{ dump_RDD_BBH_TX_WAN_CHANNEL_INDEX, 0xbfe8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_RX_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DDR_CACHE_FIFO =
{
	16,
	{
		{ dump_RDD_SIXTEEN_BYTES, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FC_MCAST_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x2800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_RUNNER_A_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x3800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_STATION_TABLE =
{
	10,
	{
		{ dump_RDD_WLAN_MCAST_DHD_STATION_ENTRY, 0x3c00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY, 0x3e80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_RADIO_INSTANCE_COMMON_A_DATA =
{
	16,
	{
		{ dump_RDD_DHD_RADIO_INSTANCE_COMMON_A_ENTRY, 0x3f00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x3f30 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x3f34 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FREE_SKB_INDEXES_DDR_FIFO_TAIL =
{
	4,
	{
		{ dump_RDD_FREE_SKB_INDEXES_FIFO_TAIL, 0x3f38 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT BPM_REPLY_RUNNER_A =
{
	48,
	{
		{ dump_RDD_BPM_REPLY, 0x3f40 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RATE_SHAPERS_STATUS_DESCRIPTOR =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x3f70 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINA_CURR_OFFSET =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x3ff0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_FIFO =
{
	48,
	{
		{ dump_RDD_GPON_SKB_ENQUEUED_INDEXES_FIFO_ENTRY, 0x4000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_FWD_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_FWD_ENTRY, 0x4600 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOA_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x4800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_DDR_QUEUE_DESCRIPTOR, 0x4c00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_MAC_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY, 0x4e00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_CONFIG_TABLE =
{
	4,
	{
		{ dump_RDD_INTERRUPT_COALESCING_CONFIG, 0x4f80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_DEI_TABLE =
{
	1,
	{
		{ dump_RDD_DSCP_TO_PBITS_DEI_ENTRY, 0x4fc0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_STATS_TABLE =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_SSID_STATS_ENTRY, 0x5000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT TRACE_C_TABLE =
{
	8,
	{
		{ dump_RDD_TRACE_C_ENTRY, 0x5180 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_CFG =
{
	20,
	{
		{ dump_RDD_SERVICE_QUEUES_CFG_ENTRY, 0x51a0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x51b4 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RATE_CONTROLLER_EXPONENT_TABLE =
{
	1,
	{
		{ dump_RDD_RATE_CONTROLLER_EXPONENT_ENTRY, 0x51b8 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_TIMER_PERIOD =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x51bc },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT INTERRUPT_COALESCING_TIMER_ARMED =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x51be },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_FLOW_RING_CACHE_LKP_TABLE =
{
	2,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY, 0x51c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT PM_COUNTERS_BUFFER =
{
	32,
	{
		{ dump_RDD_PM_COUNTERS_BUFFER, 0x51e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_CONNECTION_BUFFER_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x5200 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_L4_DST_PORT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_ENTRY, 0x5340 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT L4_DST_PORT_CONTEXT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_CONTEXT, 0x5540 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_SHADOW_WR_PTR_TABLE =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5740 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0x5760 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_BUFFERS_THRESHOLD =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5770 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT COMMON_A_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0x5774 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FC_SERVICE_QUEUE_MODE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x5775 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_BUFFERS_IN_USE_COUNTER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5778 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT PM_COUNTERS =
{
	6208,
	{
		{ dump_RDD_PM_COUNTERS, 0x5800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_DDR_QUEUE_ADDRESS_ENTRY, 0x7100 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT ETHWAN2_RX_INGRESS_QUEUE =
{
#if defined WL4908
	8,
	{
		{ dump_RDD_ETHWAN2_RX_DESCRIPTOR, 0x7200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_RING_PACKET_DESCRIPTORS_CACHE =
{
	16,
	{
		{ dump_RDD_CPU_RX_DESCRIPTOR, 0x7300 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RING_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_RING_DESCRIPTOR, 0x7500 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT MAIN_A_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x7a00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT PICO_A_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0x7c00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WAN_TX_QUEUES_TABLE =
{
	16,
	{
		{ dump_RDD_WAN_TX_QUEUE_DESCRIPTOR, 0x8000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CONNECTION_BUFFER_TABLE =
{
	16,
	{
		{ dump_RDD_CONNECTION_ENTRY, 0x9000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPV6_HOST_ADDRESS_CRC_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0x9140 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT EPON_DDR_QUEUE_ADDRESS_TABLE =
{
	8,
	{
		{ dump_RDD_DDR_QUEUE_ADDRESS_ENTRY, 0x9180 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE =
{
#if defined WL4908
	8,
	{
		{ dump_RDD_BBH_RX_DESCRIPTOR, 0x9200 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9300 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0x9300 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x9400 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_PICOB_BASE =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0x9800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0x9c00 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0x9c00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_L4_DST_PORT_TABLE =
{
	2,
	{
		{ dump_RDD_L4_DST_PORT_ENTRY, 0x9d00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WAN_TX_RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0x9f00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa000 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0xa000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_INGRESS_CLASSIFICATION_LOOKUP_TABLE =
{
	8,
	{
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_IH_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_DS_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_US_INGRESS_CLASSIFICATION_OPTIMIZED_LOOKUP_ENTRY, 0xa800 },
		{ dump_RDD_INGRESS_CLASSIFICATION_SHORT_LOOKUP_ENTRY, 0xa800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_RX_RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0xb000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT EPON_DDR_CACHE_FIFO =
{
#if defined WL4908
	8,
	{
		{ dump_RDD_BBH_TX_DESCRIPTOR, 0xc000 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_CACHE_CTX_TABLE =
{
	16,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY, 0xc600 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT FC_FLOW_IP_ADDRESSES_TABLE =
{
	48,
	{
		{ dump_RDD_FC_FLOW_IP_ADDRESSES_ENTRY, 0xc700 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_FWTRACE_MAINB_CURR_OFFSET =
{
	8,
	{
		{ dump_RDD_EIGHT_BYTES, 0xc7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT BPM_REPLY_RUNNER_B =
{
	48,
	{
		{ dump_RDD_BPM_REPLY, 0xc7d0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RATE_CONTROLLERS_TABLE =
{
	48,
	{
		{ dump_RDD_US_RATE_CONTROLLER_DESCRIPTOR, 0xc800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT RUNNER_B_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0xe000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RING_PACKET_DESCRIPTORS_CACHE =
{
	16,
	{
		{ dump_RDD_CPU_RX_DESCRIPTOR, 0xe800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT IPV4_HOST_ADDRESS_TABLE =
{
	4,
	{
		{ dump_RDD_FOUR_BYTES, 0xe8e0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_RADIO_INSTANCE_COMMON_B_DATA =
{
	64,
	{
		{ dump_RDD_DHD_RADIO_INSTANCE_COMMON_B_ENTRY, 0xe900 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DUMMY_RATE_CONTROLLER_DESCRIPTOR =
{
	64,
	{
		{ dump_RDD_DUMMY_RATE_CONTROLLER_DESCRIPTOR, 0xe9c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT MAIN_B_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xea00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT PICO_B_DEBUG_TRACE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xec00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT EPON_DDR_QUEUE_DESCRIPTORS_TABLE =
{
	16,
	{
		{ dump_RDD_DDR_QUEUE_DESCRIPTOR, 0xee00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_FREE_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xef00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DUMMY_WAN_TX_QUEUE_DESCRIPTOR =
{
	16,
	{
		{ dump_RDD_DUMMY_WAN_TX_QUEUE_DESCRIPTOR, 0xef50 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0xef60 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE =
{
	1,
	{
		{ dump_RDD_BROADCOM_SWITCH_PORT_MAPPING, 0xef70 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xef78 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR =
{
	2,
	{
		{ dump_RDD_BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR, 0xef7c },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT COMMON_B_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_DUMMY_STORE_ENTRY, 0xef7e },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX =
{
	1,
	{
		{ dump_RDD_ONE_BYTE, 0xef7f },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT GPON_SKB_ENQUEUED_INDEXES_PUT_PTR =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0xef80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD =
{
	256,
	{
		{ dump_RDD_RUNNER_SCRATCHPAD, 0xf000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE =
{
	1,
	{
		{ dump_RDD_CPU_REASON_TO_CPU_RX_QUEUE_ENTRY, 0xf800 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT PACKET_SRAM_TO_DDR_COPY_BUFFER_1 =
{
	128,
	{
		{ dump_RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER, 0xf880 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT PACKET_SRAM_TO_DDR_COPY_BUFFER_2 =
{
	128,
	{
		{ dump_RDD_PACKET_SRAM_TO_DDR_COPY_BUFFER, 0xf900 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LAN0_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf980 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LAN5_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xf9c0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LAN1_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xfa00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LAN6_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xfa40 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LAN2_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xfa80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LAN7_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xfac0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LAN3_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xfb00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT US_DHD_FLOW_RING_CACHE_LKP_TABLE =
{
	2,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY, 0xfb40 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT LAN4_INGRESS_FIFO =
{
	64,
	{
		{ dump_RDD_LAN_INGRESS_FIFO_ENTRY, 0xfb80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WAN_ENQUEUE_INGRESS_QUEUE =
{
	1,
	{
		{ dump_RDD_INGRESS_QUEUE_ENTRY, 0xfc00 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT BPM_PACKET_BUFFERS =
{
	2048,
	{
		{ dump_RDD_BPM_PACKET_BUFFER, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CONTEXT_TABLE =
{
	132,
	{
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_ENTRY, 0x0 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY, 0x0 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY, 0x0 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY, 0x0 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY, 0x0 },
		{ dump_RDD_FC_L2_UCAST_FLOW_CONTEXT_ENTRY, 0x0 },
		{ dump_RDD_FC_MCAST_FLOW_CONTEXT_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT NAT_CACHE_TABLE =
{
	16,
	{
		{ dump_RDD_NAT_CACHE_LKP_ENTRY, 0x0 },
		{ dump_RDD_NAT_CACHE_L2_LKP_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT NAT_CACHE_EXTENSION_TABLE =
{
	16,
	{
		{ dump_RDD_NAT_CACHE_LKP_ENTRY, 0x0 },
		{ dump_RDD_NAT_CACHE_L2_LKP_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT NATC_CONTEXT_TABLE =
{
	64,
	{
		{ dump_RDD_FC_NATC_UCAST_FLOW_CONTEXT_ENTRY, 0x0 },
		{ dump_RDD_FC_NATC_L2_UCAST_FLOW_CONTEXT_ENTRY, 0x0 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_ETH_XTM_ENTRY, 0x0 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_WFD_NIC_ENTRY, 0x0 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_WFD_DHD_ENTRY, 0x0 },
		{ dump_RDD_FC_UCAST_FLOW_CONTEXT_RNR_DHD_ENTRY, 0x0 },
		{ dump_RDD_FC_NATC_MCAST_FLOW_CONTEXT_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT CONTEXT_CONTINUATION_TABLE =
{
#if defined WL4908
	76,
	{
		{ dump_RDD_CONTEXT_CONTINUATION_ENTRY, 0x0 },
#endif
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0x5d1500 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_RX_POST_DDR_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0x5c1100 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_DDR_BUFFER =
{
	32,
	{
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0x5c9100 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_DDR_BUFFER =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0x5d1580 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_DDR_BUFFER =
{
	16,
	{
		{ dump_RDD_DHD_TX_COMPLETE_DESCRIPTOR, 0x5d2d80 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT R2D_WR_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1100 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT D2R_RD_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1200 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT R2D_RD_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1300 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT D2R_WR_ARR_DDR_BUFFER =
{
	2,
	{
		{ dump_RDD_TWO_BYTES, 0x5d1400 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_LIST_TABLE =
{
	64,
	{
		{ dump_RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY, 0x5c0000 },
		{ 0, 0 },
	}
};
#endif
#if defined WL4908
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_LIST_FORMAT_TABLE =
{
	1,
	{
		{ dump_RDD_WLAN_MCAST_DHD_LIST_ENTRY, 0x5c1000 },
		{ 0, 0 },
	}
};
#endif

TABLE_STRUCT RUNNER_TABLES[NUMBER_OF_TABLES] =
{
#if defined DSL_63138
	{ "INGRESS_HANDLER_BUFFER", 1, PRIVATE_A_INDEX, &INGRESS_HANDLER_BUFFER, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FREE_PACKET_DESCRIPTORS_POOL", 1, PRIVATE_A_INDEX, &DS_FREE_PACKET_DESCRIPTORS_POOL, 2048, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CONNECTION_CONTEXT_BUFFER", 1, PRIVATE_A_INDEX, &DS_CONNECTION_CONTEXT_BUFFER, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_GSO_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_GSO_PSEUDO_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_PSEUDO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_PARAMETERS_BLOCK", 1, PRIVATE_A_INDEX, &DS_CPU_PARAMETERS_BLOCK, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE", 1, PRIVATE_A_INDEX, &DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_REASON_TO_METER_TABLE", 1, PRIVATE_A_INDEX, &DS_CPU_REASON_TO_METER_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_GSO_CHUNK_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_CHUNK_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_SERVICE_QUEUES_DESCRIPTORS_TABLE", 1, PRIVATE_A_INDEX, &DS_SERVICE_QUEUES_DESCRIPTORS_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_POLICER_TABLE", 1, PRIVATE_A_INDEX, &DS_POLICER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_BUFFER_POOL", 1, PRIVATE_A_INDEX, &IPSEC_DS_BUFFER_POOL, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_SA_DESC_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_US_SA_DESC_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "SERVICE_QUEUES_RATE_LIMITER_TABLE", 1, PRIVATE_A_INDEX, &SERVICE_QUEUES_RATE_LIMITER_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH_TX_LOCAL_REGISTERS", 1, PRIVATE_A_INDEX, &ETH_TX_LOCAL_REGISTERS, 9, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_RUNNER_FLOW_HEADER_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_HEADER_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_TIMER_SCHEDULER_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_TIMER_SCHEDULER_PRIMITIVE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_MAIN_PROFILING_BUFFER_RUNNER", 1, PRIVATE_A_INDEX, &DS_MAIN_PROFILING_BUFFER_RUNNER, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_CONTROL_TABLE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_CONTROL_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_WAN_UDP_FILTER_CONTROL_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_UDP_FILTER_CONTROL_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "SERVICE_QUEUES_WLAN_SCRATCH", 1, PRIVATE_A_INDEX, &SERVICE_QUEUES_WLAN_SCRATCH, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FC_L2_UCAST_TUPLE_BUFFER", 1, PRIVATE_A_INDEX, &DS_FC_L2_UCAST_TUPLE_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "RATE_LIMITER_REMAINDER_TABLE", 1, PRIVATE_A_INDEX, &RATE_LIMITER_REMAINDER_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "FC_MCAST_CONNECTION2_TABLE", 1, PRIVATE_A_INDEX, &FC_MCAST_CONNECTION2_TABLE, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH_TX_QUEUES_POINTERS_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_QUEUES_POINTERS_TABLE, 72, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_A_INDEX, &DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "SBPM_REPLY", 1, PRIVATE_A_INDEX, &SBPM_REPLY, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH_TX_QUEUES_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_QUEUES_TABLE, 72, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_RX_METER_TABLE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_METER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FORWARDING_MATRIX_TABLE", 1, PRIVATE_A_INDEX, &DS_FORWARDING_MATRIX_TABLE, 9, 16, 1 },
#endif
#if defined DSL_63138
	{ "DS_FC_L2_UCAST_CONNECTION_BUFFER", 1, PRIVATE_A_INDEX, &DS_FC_L2_UCAST_CONNECTION_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_A_INDEX, &DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_COMPLETE_FLOW_RING_BUFFER", 1, PRIVATE_A_INDEX, &DHD_TX_COMPLETE_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_MAINA_PARAM", 1, PRIVATE_A_INDEX, &RUNNER_FWTRACE_MAINA_PARAM, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH_TX_MAC_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_MAC_TABLE, 10, 1, 1 },
#endif
#if defined DSL_63138
	{ "REVERSE_FFI_TABLE", 1, PRIVATE_A_INDEX, &REVERSE_FFI_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_A_INDEX, &DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_A_INDEX, &DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_COMPLETE_RING_DESCRIPTOR_BUFFER", 1, PRIVATE_A_INDEX, &DHD_COMPLETE_RING_DESCRIPTOR_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_PICOA_PARAM", 1, PRIVATE_A_INDEX, &RUNNER_FWTRACE_PICOA_PARAM, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_RATE_LIMITER_TABLE", 1, PRIVATE_A_INDEX, &DS_RATE_LIMITER_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_WAN_FLOW_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_FLOW_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH0_RX_DESCRIPTORS", 1, PRIVATE_A_INDEX, &ETH0_RX_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "INGRESS_HANDLER_SKB_DATA_POINTER", 1, PRIVATE_A_INDEX, &INGRESS_HANDLER_SKB_DATA_POINTER, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_RUNNER_FLOW_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_WAN_UDP_FILTER_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_UDP_FILTER_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "FC_MCAST_PORT_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &FC_MCAST_PORT_HEADER_BUFFER, 8, 64, 1 },
#endif
#if defined DSL_63138
	{ "GSO_PICO_QUEUE", 1, PRIVATE_A_INDEX, &GSO_PICO_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CONNECTION_CONTEXT_MULTICAST_BUFFER", 1, PRIVATE_A_INDEX, &DS_CONNECTION_CONTEXT_MULTICAST_BUFFER, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DOWNSTREAM_LAN_ENQUEUE_SQ_PD", 1, PRIVATE_A_INDEX, &DOWNSTREAM_LAN_ENQUEUE_SQ_PD, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_TX_BBH_DESCRIPTORS", 1, PRIVATE_A_INDEX, &DS_CPU_TX_BBH_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PROFILING_BUFFER_PICO_RUNNER", 1, PRIVATE_A_INDEX, &DS_PROFILING_BUFFER_PICO_RUNNER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_FAST_QUEUE", 1, PRIVATE_A_INDEX, &CPU_TX_FAST_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_PICO_QUEUE", 1, PRIVATE_A_INDEX, &CPU_TX_PICO_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_SPDSVC_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_SPDSVC_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_SSID_STATS_STATE_TABLE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_SSID_STATS_STATE_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_MAIN_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_MAIN_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_NULL_BUFFER", 1, PRIVATE_A_INDEX, &DS_NULL_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_SERVICE_TM_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_SERVICE_TM_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_BPM_EXTRA_DDR_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_EXTRA_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_POST_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DHD_TX_POST_PD_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_QUEUE_PROFILE_TABLE", 1, PRIVATE_A_INDEX, &DS_QUEUE_PROFILE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_RX_SQ_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_SQ_PD_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "EMAC_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_A_INDEX, &EMAC_ABSOLUTE_TX_BBH_COUNTER, 10, 1, 1 },
#endif
#if defined DSL_63138
	{ "FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PICO_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_PICO_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "EMAC_SKB_ENQUEUED_INDEXES_FIFO", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FIFO, 5, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_TX_MESSAGE_DATA_BUFFER", 1, PRIVATE_A_INDEX, &DS_CPU_TX_MESSAGE_DATA_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GPON_RX_DIRECT_DESCRIPTORS", 1, PRIVATE_A_INDEX, &GPON_RX_DIRECT_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_RX_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_PD_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_GSO_DESC_TABLE", 1, PRIVATE_A_INDEX, &DS_GSO_DESC_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_RX_FAST_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_FAST_PD_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_SQ_ENQUEUE_QUEUE", 1, PRIVATE_A_INDEX, &DS_SQ_ENQUEUE_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FLOW_IH_RESPONSE", 1, PRIVATE_A_INDEX, &RUNNER_FLOW_IH_RESPONSE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_BPM_DDR_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CONNECTION_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONNECTION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_GSO_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_GSO_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CONTEXT_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONTEXT_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DEBUG_PERIPHERALS_STATUS_REGISTER", 1, PRIVATE_A_INDEX, &DS_DEBUG_PERIPHERALS_STATUS_REGISTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_COMPLETE_RING_BUFFER", 1, PRIVATE_A_INDEX, &DHD_COMPLETE_RING_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CONTEXT_CONTINUATION_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONTEXT_CONTINUATION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "MULTICAST_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &MULTICAST_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GPON_RX_NORMAL_DESCRIPTORS", 1, PRIVATE_A_INDEX, &GPON_RX_NORMAL_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_RX_PICO_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_PICO_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_GPE_COMMAND_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_GPE_COMMAND_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DOWNSTREAM_MULTICAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "FC_MCAST_CONNECTION_TABLE_PLUS", 1, PRIVATE_A_INDEX, &FC_MCAST_CONNECTION_TABLE_PLUS, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GSO_DESC_PTR", 1, PRIVATE_A_INDEX, &GSO_DESC_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DATA_POINTER_DUMMY_TARGET", 1, PRIVATE_A_INDEX, &DS_DATA_POINTER_DUMMY_TARGET, 5, 1, 1 },
#endif
#if defined DSL_63138
	{ "FIREWALL_IPV6_R16_BUFFER", 1, PRIVATE_A_INDEX, &FIREWALL_IPV6_R16_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT", 1, PRIVATE_A_INDEX, &GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_ROUTER_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_ROUTER_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_FLOW_RING_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_FLOW_RING_DROP_COUNTER, 5, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPTV_COUNTERS_BUFFER", 1, PRIVATE_A_INDEX, &IPTV_COUNTERS_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &CPU_TX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT", 1, PRIVATE_A_INDEX, &CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_A_INDEX, &DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "HASH_BUFFER", 1, PRIVATE_A_INDEX, &HASH_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_RX_FAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_FAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DEBUG_BUFFER", 1, PRIVATE_A_INDEX, &DS_DEBUG_BUFFER, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FW_MAC_ADDRS", 1, PRIVATE_A_INDEX, &DS_FW_MAC_ADDRS, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_SYSTEM_CONFIGURATION", 1, PRIVATE_A_INDEX, &DS_SYSTEM_CONFIGURATION, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD", 1, PRIVATE_A_INDEX, &FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS, 5, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH_TX_EMACS_STATUS", 1, PRIVATE_A_INDEX, &ETH_TX_EMACS_STATUS, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_RX_PD_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &CPU_RX_PD_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_QUEUE", 1, PRIVATE_A_INDEX, &IPSEC_DS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_TX_POST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_A_INDEX, &DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE", 1, PRIVATE_A_INDEX, &DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_SA_DESC_CAM_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_CAM_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_US_SA_DESC_CAM_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_CAM_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "GSO_TX_DHD_L2_BUFFER", 1, PRIVATE_A_INDEX, &GSO_TX_DHD_L2_BUFFER, 22, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_RX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DS_CPU_RX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_DHD_L2_BUFFER", 1, PRIVATE_A_INDEX, &CPU_TX_DHD_L2_BUFFER, 22, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_BPM_DDR_BUFFER_HEADROOM_SIZE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFER_HEADROOM_SIZE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH_TX_SCRATCH", 1, PRIVATE_A_INDEX, &ETH_TX_SCRATCH, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_INGRESS_CLASSIFICATION_KEY_BUFFER", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_KEY_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &WLAN_MCAST_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "HASH_BASED_FORWARDING_PORT_TABLE", 1, PRIVATE_A_INDEX, &HASH_BASED_FORWARDING_PORT_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_RX_FAST_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DS_CPU_RX_FAST_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_ANY_SRC_PORT_FLOW_COUNTER", 1, PRIVATE_A_INDEX, &DS_ANY_SRC_PORT_FLOW_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GSO_TX_DHD_HOST_BUF_PTR", 1, PRIVATE_A_INDEX, &GSO_TX_DHD_HOST_BUF_PTR, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_DDR_SA_DESC_TABLE_PTR", 1, PRIVATE_A_INDEX, &IPSEC_DS_DDR_SA_DESC_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_DHD_HOST_BUF_PTR", 1, PRIVATE_A_INDEX, &CPU_TX_DHD_HOST_BUF_PTR, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "GSO_PICO_QUEUE_PTR", 1, PRIVATE_A_INDEX, &GSO_PICO_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_MEMLIB_SEMAPHORE", 1, PRIVATE_A_INDEX, &DS_MEMLIB_SEMAPHORE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "WAN_PHYSICAL_PORT", 1, PRIVATE_A_INDEX, &WAN_PHYSICAL_PORT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_RUNNER_CONGESTION_STATE", 1, PRIVATE_A_INDEX, &DS_RUNNER_CONGESTION_STATE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_COMPLETE_BPM_REF_COUNTER", 1, PRIVATE_A_INDEX, &DHD_TX_COMPLETE_BPM_REF_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_POST_CPU_BPM_REF_COUNTER", 1, PRIVATE_A_INDEX, &DHD_TX_POST_CPU_BPM_REF_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_DDR_SA_DESC_SIZE", 1, PRIVATE_A_INDEX, &IPSEC_DS_DDR_SA_DESC_SIZE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &IPSEC_DS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_IP_LENGTH", 1, PRIVATE_A_INDEX, &IPSEC_DS_IP_LENGTH, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "PRIVATE_A_DUMMY_STORE", 1, PRIVATE_A_INDEX, &PRIVATE_A_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH_TX_INTER_LAN_SCHEDULING_OFFSET", 1, PRIVATE_A_INDEX, &ETH_TX_INTER_LAN_SCHEDULING_OFFSET, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_A_INDEX, &DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_A_INDEX, &DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_DS_PICO_SEMAPHORE", 1, PRIVATE_A_INDEX, &CPU_TX_DS_PICO_SEMAPHORE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FC_ACCEL_MODE", 1, PRIVATE_A_INDEX, &DS_FC_ACCEL_MODE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PACKET_BUFFER_SIZE_ASR_8", 1, PRIVATE_A_INDEX, &DS_PACKET_BUFFER_SIZE_ASR_8, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_MAIN_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_A_INDEX, &DS_MAIN_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PICO_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_A_INDEX, &DS_PICO_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_RUNNER_FLOW_IH_RESPONSE_MUTEX", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_IH_RESPONSE_MUTEX, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PARALLEL_PROCESSING_SLAVE_VECTOR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_SLAVE_VECTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_FW_MAC_ADDRS_COUNT", 1, PRIVATE_A_INDEX, &DS_FW_MAC_ADDRS_COUNT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_DMA_SYNCHRONIZATION", 1, PRIVATE_A_INDEX, &DS_DHD_DMA_SYNCHRONIZATION, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_POST_CPU_SEMAPHORE", 1, PRIVATE_A_INDEX, &DHD_TX_POST_CPU_SEMAPHORE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_DS_SA_DESC_NEXT_REPLACE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_NEXT_REPLACE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPSEC_US_SA_DESC_NEXT_REPLACE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_NEXT_REPLACE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_HANDLER_BUFFER", 1, PRIVATE_B_INDEX, &US_INGRESS_HANDLER_BUFFER, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CSO_CHUNK_BUFFER", 1, PRIVATE_B_INDEX, &US_CSO_CHUNK_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CSO_PSEUDO_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &US_CSO_PSEUDO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_PARAMETERS_BLOCK", 1, PRIVATE_B_INDEX, &US_CPU_PARAMETERS_BLOCK, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_REASON_TO_METER_TABLE", 1, PRIVATE_B_INDEX, &US_CPU_REASON_TO_METER_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_MAIN_PROFILING_BUFFER_RUNNER", 1, PRIVATE_B_INDEX, &US_MAIN_PROFILING_BUFFER_RUNNER, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FREE_PACKET_DESCRIPTORS_POOL", 1, PRIVATE_B_INDEX, &US_FREE_PACKET_DESCRIPTORS_POOL, 3072, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RUNNER_FLOW_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_HEADER_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_QUEUE_PROFILE_TABLE", 1, PRIVATE_B_INDEX, &US_QUEUE_PROFILE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "WAN_CHANNELS_8_39_TABLE", 1, PRIVATE_B_INDEX, &WAN_CHANNELS_8_39_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_POLICER_TABLE", 1, PRIVATE_B_INDEX, &US_POLICER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_RX_METER_TABLE", 1, PRIVATE_B_INDEX, &US_CPU_RX_METER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_SBPM_REPLY", 1, PRIVATE_B_INDEX, &US_SBPM_REPLY, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_TX_BBH_DESCRIPTORS", 1, PRIVATE_B_INDEX, &US_CPU_TX_BBH_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FORWARDING_MATRIX_TABLE", 1, PRIVATE_B_INDEX, &US_FORWARDING_MATRIX_TABLE, 9, 16, 1 },
#endif
#if defined DSL_63138
	{ "US_TIMER_SCHEDULER_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_TIMER_SCHEDULER_PRIMITIVE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_B_INDEX, &US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_TRAFFIC_CLASS_TO_QUEUE_TABLE", 1, PRIVATE_B_INDEX, &US_TRAFFIC_CLASS_TO_QUEUE_TABLE, 8, 8, 1 },
#endif
#if defined DSL_63138
	{ "US_WAN_FLOW_TABLE", 1, PRIVATE_B_INDEX, &US_WAN_FLOW_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_HANDLER_SKB_DATA_POINTER", 1, PRIVATE_B_INDEX, &US_INGRESS_HANDLER_SKB_DATA_POINTER, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PROFILING_BUFFER_PICO_RUNNER", 1, PRIVATE_B_INDEX, &US_PROFILING_BUFFER_PICO_RUNNER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_B_INDEX, &US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_B_INDEX, &US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PICO_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_B_INDEX, &US_PICO_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FC_L2_UCAST_TUPLE_BUFFER", 1, PRIVATE_B_INDEX, &US_FC_L2_UCAST_TUPLE_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RATE_LIMITER_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_LIMITER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_RX_COMPLETE_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &DHD_RX_COMPLETE_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FAST_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_B_INDEX, &US_FAST_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CONNECTION_CONTEXT_BUFFER", 1, PRIVATE_B_INDEX, &US_CONNECTION_CONTEXT_BUFFER, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_CLASSIFICATION_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "WAN_CHANNELS_0_7_TABLE", 1, PRIVATE_B_INDEX, &WAN_CHANNELS_0_7_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_TX_MESSAGE_DATA_BUFFER", 1, PRIVATE_B_INDEX, &US_CPU_TX_MESSAGE_DATA_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_RX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &DHD_RX_POST_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PICO_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_B_INDEX, &US_PICO_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_RATE_LIMITER_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_RATE_LIMITER_TABLE, 5, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FC_L2_UCAST_CONNECTION_BUFFER", 1, PRIVATE_B_INDEX, &US_FC_L2_UCAST_CONNECTION_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RUNNER_FLOW_HEADER_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_HEADER_DESCRIPTOR, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_ONE_BUFFER", 1, PRIVATE_B_INDEX, &US_ONE_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_SPDSVC_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_SPDSVC_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GPON_ABSOLUTE_TX_FIRMWARE_COUNTER", 1, PRIVATE_B_INDEX, &GPON_ABSOLUTE_TX_FIRMWARE_COUNTER, 40, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_MAINB_PARAM", 1, PRIVATE_B_INDEX, &RUNNER_FWTRACE_MAINB_PARAM, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_RX_PICO_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_RX_PICO_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_GPE_COMMAND_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_GPE_COMMAND_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_ROUTER_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_ROUTER_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_PICOB_PARAM", 1, PRIVATE_B_INDEX, &RUNNER_FWTRACE_PICOB_PARAM, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_RX_FAST_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_RX_FAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DEBUG_BUFFER", 1, PRIVATE_B_INDEX, &US_DEBUG_BUFFER, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FW_MAC_ADDRS", 1, PRIVATE_B_INDEX, &US_FW_MAC_ADDRS, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_TX_POST_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE", 1, PRIVATE_B_INDEX, &US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE, 48, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_B_INDEX, &US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE", 1, PRIVATE_B_INDEX, &US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_FLOW_RING_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_FLOW_RING_DROP_COUNTER, 5, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_ETH0_EEE_MODE_CONFIG_MESSAGE", 1, PRIVATE_B_INDEX, &US_ETH0_EEE_MODE_CONFIG_MESSAGE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_NULL_BUFFER", 1, PRIVATE_B_INDEX, &US_NULL_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_B_INDEX, &US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "WAN_TX_SCRATCH", 1, PRIVATE_B_INDEX, &WAN_TX_SCRATCH, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CSO_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_CSO_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_BPM_EXTRA_DDR_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_EXTRA_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_MAIN_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_MAIN_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_SYSTEM_CONFIGURATION", 1, PRIVATE_B_INDEX, &US_SYSTEM_CONFIGURATION, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_BPM_DDR_OPTIMIZED_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_OPTIMIZED_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE", 1, PRIVATE_B_INDEX, &CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE, 3, 6, 1 },
#endif
#if defined DSL_63138
	{ "US_PICO_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_PICO_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_BPM_DDR_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_CLASSIFICATION_KEY_BUFFER", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_KEY_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT", 1, PRIVATE_B_INDEX, &CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_DHD_LAYER2_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &CPU_TX_DHD_LAYER2_HEADER_BUFFER, 14, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_RX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &US_CPU_RX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DATA_POINTER_DUMMY_TARGET", 1, PRIVATE_B_INDEX, &DATA_POINTER_DUMMY_TARGET, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CONNECTION_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONNECTION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CONTEXT_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONTEXT_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DEBUG_PERIPHERALS_STATUS_REGISTER", 1, PRIVATE_B_INDEX, &US_DEBUG_PERIPHERALS_STATUS_REGISTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PARALLEL_PROCESSING_TASK_REORDER_FIFO", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_TASK_REORDER_FIFO, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "IH_BUFFER_BBH_POINTER", 1, PRIVATE_B_INDEX, &IH_BUFFER_BBH_POINTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE", 1, PRIVATE_B_INDEX, &BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CONTEXT_CONTINUATION_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONTEXT_CONTINUATION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_BPM_DDR_BUFFER_HEADROOM_SIZE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFER_HEADROOM_SIZE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RATE_CONTROLLER_EXPONENT_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_CONTROLLER_EXPONENT_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_RX_FAST_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &US_CPU_RX_FAST_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_ANY_SRC_PORT_FLOW_COUNTER", 1, PRIVATE_B_INDEX, &US_ANY_SRC_PORT_FLOW_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_MEMLIB_SEMAPHORE", 1, PRIVATE_B_INDEX, &US_MEMLIB_SEMAPHORE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_TX_POST_HOST_DATA_PTR_BUFFER", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_HOST_DATA_PTR_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETHWAN2_RX_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &ETHWAN2_RX_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RUNNER_CONGESTION_STATE", 1, PRIVATE_B_INDEX, &US_RUNNER_CONGESTION_STATE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "WAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &WAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "PRIVATE_B_DUMMY_STORE", 1, PRIVATE_B_INDEX, &PRIVATE_B_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_B_INDEX, &US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_B_INDEX, &US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FC_ACCEL_MODE", 1, PRIVATE_B_INDEX, &US_FC_ACCEL_MODE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETHWAN2_SWITCH_PORT", 1, PRIVATE_B_INDEX, &ETHWAN2_SWITCH_PORT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PACKET_BUFFER_SIZE_ASR_8", 1, PRIVATE_B_INDEX, &US_PACKET_BUFFER_SIZE_ASR_8, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_MAIN_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_B_INDEX, &US_MAIN_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PICO_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_B_INDEX, &US_PICO_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RUNNER_FLOW_IH_RESPONSE_MUTEX", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_IH_RESPONSE_MUTEX, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DSL_PTM_BOND_TX_CONTROL", 1, PRIVATE_B_INDEX, &DSL_PTM_BOND_TX_CONTROL, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DSL_BUFFER_ALIGNMENT", 1, PRIVATE_B_INDEX, &DSL_BUFFER_ALIGNMENT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PARALLEL_PROCESSING_SLAVE_VECTOR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_SLAVE_VECTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_FW_MAC_ADDRS_COUNT", 1, PRIVATE_B_INDEX, &US_FW_MAC_ADDRS_COUNT, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_DMA_SYNCHRONIZATION", 1, PRIVATE_B_INDEX, &US_DHD_DMA_SYNCHRONIZATION, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETHWAN_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_B_INDEX, &ETHWAN_ABSOLUTE_TX_BBH_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER", 1, PRIVATE_B_INDEX, &ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GPON_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_B_INDEX, &GPON_ABSOLUTE_TX_BBH_COUNTER, 40, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_TX_FAST_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_TX_FAST_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_TX_PICO_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_TX_PICO_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETH1_RX_DESCRIPTORS", 1, PRIVATE_B_INDEX, &ETH1_RX_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RUNNER_FLOW_IH_RESPONSE", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_IH_RESPONSE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "BBH_TX_WAN_CHANNEL_INDEX", 1, PRIVATE_B_INDEX, &BBH_TX_WAN_CHANNEL_INDEX, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "SERVICE_QUEUES_DDR_CACHE_FIFO", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DDR_CACHE_FIFO, 384, 1, 1 },
#endif
#if defined DSL_63138
	{ "FC_MCAST_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &FC_MCAST_RUNNER_A_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_RX_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &CPU_RX_RUNNER_A_SCRATCHPAD, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &WLAN_MCAST_RUNNER_A_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_MAINA_BASE", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_MAINA_BASE, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_DHD_STATION_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_DHD_STATION_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE", 1, COMMON_A_INDEX, &DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE, 2, 64, 1 },
#endif
#if defined DSL_63138
	{ "DHD_RADIO_INSTANCE_COMMON_A_DATA", 1, COMMON_A_INDEX, &DHD_RADIO_INSTANCE_COMMON_A_DATA, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "FREE_SKB_INDEXES_DDR_FIFO_TAIL", 1, COMMON_A_INDEX, &FREE_SKB_INDEXES_DDR_FIFO_TAIL, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "BPM_REPLY_RUNNER_A", 1, COMMON_A_INDEX, &BPM_REPLY_RUNNER_A, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "RATE_SHAPERS_STATUS_DESCRIPTOR", 1, COMMON_A_INDEX, &RATE_SHAPERS_STATUS_DESCRIPTOR, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_MAINA_CURR_OFFSET", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_MAINA_CURR_OFFSET, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "GPON_SKB_ENQUEUED_INDEXES_FIFO", 1, COMMON_A_INDEX, &GPON_SKB_ENQUEUED_INDEXES_FIFO, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_FWD_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_FWD_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_PICOA_BASE", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_PICOA_BASE, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "SERVICE_QUEUES_DESCRIPTOR_TABLE", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DESCRIPTOR_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_SSID_MAC_ADDRESS_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_SSID_MAC_ADDRESS_TABLE, 48, 1, 1 },
#endif
#if defined DSL_63138
	{ "INTERRUPT_COALESCING_CONFIG_TABLE", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_CONFIG_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "GLOBAL_DSCP_TO_PBITS_DEI_TABLE", 1, COMMON_A_INDEX, &GLOBAL_DSCP_TO_PBITS_DEI_TABLE, 1, 64, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_SSID_STATS_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_SSID_STATS_TABLE, 48, 1, 1 },
#endif
#if defined DSL_63138
	{ "TRACE_C_TABLE", 1, COMMON_A_INDEX, &TRACE_C_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "SERVICE_QUEUES_CFG", 1, COMMON_A_INDEX, &SERVICE_QUEUES_CFG, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_RATE_CONTROLLER_EXPONENT_TABLE", 1, COMMON_A_INDEX, &DS_RATE_CONTROLLER_EXPONENT_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "INTERRUPT_COALESCING_TIMER_PERIOD", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_TIMER_PERIOD, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "INTERRUPT_COALESCING_TIMER_ARMED", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_TIMER_ARMED, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_FLOW_RING_CACHE_LKP_TABLE", 1, COMMON_A_INDEX, &DS_DHD_FLOW_RING_CACHE_LKP_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "PM_COUNTERS_BUFFER", 1, COMMON_A_INDEX, &PM_COUNTERS_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CONNECTION_BUFFER_TABLE", 1, COMMON_A_INDEX, &DS_CONNECTION_BUFFER_TABLE, 5, 4, 1 },
#endif
#if defined DSL_63138
	{ "DS_L4_DST_PORT_TABLE", 1, COMMON_A_INDEX, &DS_L4_DST_PORT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "L4_DST_PORT_CONTEXT_TABLE", 1, COMMON_A_INDEX, &L4_DST_PORT_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_FLOW_RING_SHADOW_WR_PTR_TABLE", 1, COMMON_A_INDEX, &DHD_FLOW_RING_SHADOW_WR_PTR_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER", 1, COMMON_A_INDEX, &DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_POST_BUFFERS_THRESHOLD", 1, COMMON_A_INDEX, &DHD_TX_POST_BUFFERS_THRESHOLD, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_POST_BUFFERS_IN_USE_COUNTER", 1, COMMON_A_INDEX, &DHD_TX_POST_BUFFERS_IN_USE_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "COMMON_A_DUMMY_STORE", 1, COMMON_A_INDEX, &COMMON_A_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "FC_SERVICE_QUEUE_MODE", 1, COMMON_A_INDEX, &FC_SERVICE_QUEUE_MODE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "PM_COUNTERS", 1, COMMON_A_INDEX, &PM_COUNTERS, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "ETHWAN2_RX_INGRESS_QUEUE", 1, COMMON_A_INDEX, &ETHWAN2_RX_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_RING_PACKET_DESCRIPTORS_CACHE", 1, COMMON_A_INDEX, &DS_RING_PACKET_DESCRIPTORS_CACHE, 14, 1, 1 },
#endif
#if defined DSL_63138
	{ "RING_DESCRIPTORS_TABLE", 1, COMMON_A_INDEX, &RING_DESCRIPTORS_TABLE, 12, 1, 1 },
#endif
#if defined DSL_63138
	{ "MAIN_A_DEBUG_TRACE", 1, COMMON_A_INDEX, &MAIN_A_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined DSL_63138
	{ "PICO_A_DEBUG_TRACE", 1, COMMON_A_INDEX, &PICO_A_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined DSL_63138
	{ "WAN_TX_QUEUES_TABLE", 1, COMMON_B_INDEX, &WAN_TX_QUEUES_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CONNECTION_BUFFER_TABLE", 1, COMMON_B_INDEX, &US_CONNECTION_BUFFER_TABLE, 5, 4, 1 },
#endif
#if defined DSL_63138
	{ "IPV6_HOST_ADDRESS_CRC_TABLE", 1, COMMON_B_INDEX, &IPV6_HOST_ADDRESS_CRC_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "EPON_DDR_QUEUE_ADDRESS_TABLE", 1, COMMON_B_INDEX, &EPON_DDR_QUEUE_ADDRESS_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE", 1, COMMON_B_INDEX, &LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE", 1, COMMON_B_INDEX, &DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_MAINB_BASE", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_MAINB_BASE, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_PICOB_BASE", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_PICOB_BASE, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE", 1, COMMON_B_INDEX, &US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_L4_DST_PORT_TABLE", 1, COMMON_B_INDEX, &US_L4_DST_PORT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "WAN_TX_RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &WAN_TX_RUNNER_B_SCRATCHPAD, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE", 1, COMMON_B_INDEX, &DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_INGRESS_CLASSIFICATION_LOOKUP_TABLE", 1, COMMON_B_INDEX, &US_INGRESS_CLASSIFICATION_LOOKUP_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_RX_RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &CPU_RX_RUNNER_B_SCRATCHPAD, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "EPON_DDR_CACHE_FIFO", 1, COMMON_B_INDEX, &EPON_DDR_CACHE_FIFO, 192, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_FLOW_RING_CACHE_CTX_TABLE", 1, COMMON_B_INDEX, &DHD_FLOW_RING_CACHE_CTX_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "FC_FLOW_IP_ADDRESSES_TABLE", 1, COMMON_B_INDEX, &FC_FLOW_IP_ADDRESSES_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "DSL_PTM_BOND_TX_HDR_TABLE", 1, COMMON_B_INDEX, &DSL_PTM_BOND_TX_HDR_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "BPM_REPLY_RUNNER_B", 1, COMMON_B_INDEX, &BPM_REPLY_RUNNER_B, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RATE_CONTROLLERS_TABLE", 1, COMMON_B_INDEX, &US_RATE_CONTROLLERS_TABLE, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &RUNNER_B_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_RING_PACKET_DESCRIPTORS_CACHE", 1, COMMON_B_INDEX, &US_RING_PACKET_DESCRIPTORS_CACHE, 14, 1, 1 },
#endif
#if defined DSL_63138
	{ "IPV4_HOST_ADDRESS_TABLE", 1, COMMON_B_INDEX, &IPV4_HOST_ADDRESS_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_RADIO_INSTANCE_COMMON_B_DATA", 1, COMMON_B_INDEX, &DHD_RADIO_INSTANCE_COMMON_B_DATA, 3, 1, 1 },
#endif
#if defined DSL_63138
	{ "DUMMY_RATE_CONTROLLER_DESCRIPTOR", 1, COMMON_B_INDEX, &DUMMY_RATE_CONTROLLER_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "MAIN_B_DEBUG_TRACE", 1, COMMON_B_INDEX, &MAIN_B_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined DSL_63138
	{ "PICO_B_DEBUG_TRACE", 1, COMMON_B_INDEX, &PICO_B_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined DSL_63138
	{ "EPON_DDR_QUEUE_DESCRIPTORS_TABLE", 1, COMMON_B_INDEX, &EPON_DDR_QUEUE_DESCRIPTORS_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "GPON_SKB_ENQUEUED_INDEXES_FREE_PTR", 1, COMMON_B_INDEX, &GPON_SKB_ENQUEUED_INDEXES_FREE_PTR, 40, 1, 1 },
#endif
#if defined DSL_63138
	{ "RUNNER_FWTRACE_MAINB_CURR_OFFSET", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_MAINB_CURR_OFFSET, 2, 1, 1 },
#endif
#if defined DSL_63138
	{ "DUMMY_WAN_TX_QUEUE_DESCRIPTOR", 1, COMMON_B_INDEX, &DUMMY_WAN_TX_QUEUE_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER", 1, COMMON_B_INDEX, &US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "GPON_SKB_ENQUEUED_INDEXES_PUT_PTR", 1, COMMON_B_INDEX, &GPON_SKB_ENQUEUED_INDEXES_PUT_PTR, 40, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE", 1, COMMON_B_INDEX, &US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE, 2, 64, 1 },
#endif
#if defined DSL_63138
	{ "BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE", 1, COMMON_B_INDEX, &BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE", 1, COMMON_B_INDEX, &CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63138
	{ "BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR", 1, COMMON_B_INDEX, &BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "COMMON_B_DUMMY_STORE", 1, COMMON_B_INDEX, &COMMON_B_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX", 1, COMMON_B_INDEX, &DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "PACKET_SRAM_TO_DDR_COPY_BUFFER_1", 1, COMMON_B_INDEX, &PACKET_SRAM_TO_DDR_COPY_BUFFER_1, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "PACKET_SRAM_TO_DDR_COPY_BUFFER_2", 1, COMMON_B_INDEX, &PACKET_SRAM_TO_DDR_COPY_BUFFER_2, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LAN0_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN0_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LAN5_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN5_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LAN1_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN1_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LAN6_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN6_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LAN2_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN2_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LAN7_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN7_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "LAN3_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN3_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_DHD_FLOW_RING_CACHE_LKP_TABLE", 1, COMMON_B_INDEX, &US_DHD_FLOW_RING_CACHE_LKP_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "LAN4_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN4_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63138
	{ "WAN_ENQUEUE_INGRESS_QUEUE", 1, COMMON_B_INDEX, &WAN_ENQUEUE_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "BPM_PACKET_BUFFERS", 1, DDR_INDEX, &BPM_PACKET_BUFFERS, 7680, 1, 1 },
#endif
#if defined DSL_63138
	{ "DS_CONNECTION_TABLE", 1, DDR_INDEX, &DS_CONNECTION_TABLE, 32768, 1, 1 },
#endif
#if defined DSL_63138
	{ "US_CONNECTION_TABLE", 1, DDR_INDEX, &US_CONNECTION_TABLE, 32768, 1, 1 },
#endif
#if defined DSL_63138
	{ "CONTEXT_TABLE", 1, DDR_INDEX, &CONTEXT_TABLE, 16512, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE", 1, DDR_INDEX, &DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_RX_POST_DDR_BUFFER", 1, DDR_INDEX, &DHD_RX_POST_DDR_BUFFER, 1024, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_RX_COMPLETE_DDR_BUFFER", 1, DDR_INDEX, &DHD_RX_COMPLETE_DDR_BUFFER, 1024, 1, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_POST_DDR_BUFFER", 1, DDR_INDEX, &DHD_TX_POST_DDR_BUFFER, 8, 16, 1 },
#endif
#if defined DSL_63138
	{ "DHD_TX_COMPLETE_DDR_BUFFER", 1, DDR_INDEX, &DHD_TX_COMPLETE_DDR_BUFFER, 16, 1, 1 },
#endif
#if defined DSL_63138
	{ "R2D_WR_ARR_DDR_BUFFER", 1, DDR_INDEX, &R2D_WR_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "D2R_RD_ARR_DDR_BUFFER", 1, DDR_INDEX, &D2R_RD_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "R2D_RD_ARR_DDR_BUFFER", 1, DDR_INDEX, &R2D_RD_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "D2R_WR_ARR_DDR_BUFFER", 1, DDR_INDEX, &D2R_WR_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_DHD_LIST_TABLE", 1, DDR_INDEX, &WLAN_MCAST_DHD_LIST_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63138
	{ "WLAN_MCAST_DHD_LIST_FORMAT_TABLE", 1, DDR_INDEX, &WLAN_MCAST_DHD_LIST_FORMAT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "INGRESS_HANDLER_BUFFER", 1, PRIVATE_A_INDEX, &INGRESS_HANDLER_BUFFER, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FREE_PACKET_DESCRIPTORS_POOL", 1, PRIVATE_A_INDEX, &DS_FREE_PACKET_DESCRIPTORS_POOL, 2048, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CONNECTION_CONTEXT_BUFFER", 1, PRIVATE_A_INDEX, &DS_CONNECTION_CONTEXT_BUFFER, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_GSO_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_GSO_PSEUDO_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_PSEUDO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_PARAMETERS_BLOCK", 1, PRIVATE_A_INDEX, &DS_CPU_PARAMETERS_BLOCK, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE", 1, PRIVATE_A_INDEX, &DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_REASON_TO_METER_TABLE", 1, PRIVATE_A_INDEX, &DS_CPU_REASON_TO_METER_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_GSO_CHUNK_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_CHUNK_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_SERVICE_QUEUES_DESCRIPTORS_TABLE", 1, PRIVATE_A_INDEX, &DS_SERVICE_QUEUES_DESCRIPTORS_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_POLICER_TABLE", 1, PRIVATE_A_INDEX, &DS_POLICER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_BUFFER_POOL", 1, PRIVATE_A_INDEX, &IPSEC_DS_BUFFER_POOL, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_SA_DESC_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_US_SA_DESC_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "SERVICE_QUEUES_RATE_LIMITER_TABLE", 1, PRIVATE_A_INDEX, &SERVICE_QUEUES_RATE_LIMITER_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH_TX_LOCAL_REGISTERS", 1, PRIVATE_A_INDEX, &ETH_TX_LOCAL_REGISTERS, 9, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_RUNNER_FLOW_HEADER_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_HEADER_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_TIMER_SCHEDULER_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_TIMER_SCHEDULER_PRIMITIVE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_MAIN_PROFILING_BUFFER_RUNNER", 1, PRIVATE_A_INDEX, &DS_MAIN_PROFILING_BUFFER_RUNNER, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_CONTROL_TABLE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_CONTROL_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_WAN_UDP_FILTER_CONTROL_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_UDP_FILTER_CONTROL_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "SERVICE_QUEUES_WLAN_SCRATCH", 1, PRIVATE_A_INDEX, &SERVICE_QUEUES_WLAN_SCRATCH, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FC_L2_UCAST_TUPLE_BUFFER", 1, PRIVATE_A_INDEX, &DS_FC_L2_UCAST_TUPLE_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "RATE_LIMITER_REMAINDER_TABLE", 1, PRIVATE_A_INDEX, &RATE_LIMITER_REMAINDER_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "FC_MCAST_CONNECTION2_TABLE", 1, PRIVATE_A_INDEX, &FC_MCAST_CONNECTION2_TABLE, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH_TX_QUEUES_POINTERS_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_QUEUES_POINTERS_TABLE, 72, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_A_INDEX, &DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "SBPM_REPLY", 1, PRIVATE_A_INDEX, &SBPM_REPLY, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH_TX_QUEUES_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_QUEUES_TABLE, 72, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_RX_METER_TABLE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_METER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FORWARDING_MATRIX_TABLE", 1, PRIVATE_A_INDEX, &DS_FORWARDING_MATRIX_TABLE, 9, 16, 1 },
#endif
#if defined DSL_63148
	{ "DS_FC_L2_UCAST_CONNECTION_BUFFER", 1, PRIVATE_A_INDEX, &DS_FC_L2_UCAST_CONNECTION_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_A_INDEX, &DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_COMPLETE_FLOW_RING_BUFFER", 1, PRIVATE_A_INDEX, &DHD_TX_COMPLETE_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_MAINA_PARAM", 1, PRIVATE_A_INDEX, &RUNNER_FWTRACE_MAINA_PARAM, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH_TX_MAC_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_MAC_TABLE, 10, 1, 1 },
#endif
#if defined DSL_63148
	{ "REVERSE_FFI_TABLE", 1, PRIVATE_A_INDEX, &REVERSE_FFI_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_A_INDEX, &DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_A_INDEX, &DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_COMPLETE_RING_DESCRIPTOR_BUFFER", 1, PRIVATE_A_INDEX, &DHD_COMPLETE_RING_DESCRIPTOR_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_PICOA_PARAM", 1, PRIVATE_A_INDEX, &RUNNER_FWTRACE_PICOA_PARAM, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_RATE_LIMITER_TABLE", 1, PRIVATE_A_INDEX, &DS_RATE_LIMITER_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_WAN_FLOW_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_FLOW_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH0_RX_DESCRIPTORS", 1, PRIVATE_A_INDEX, &ETH0_RX_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "INGRESS_HANDLER_SKB_DATA_POINTER", 1, PRIVATE_A_INDEX, &INGRESS_HANDLER_SKB_DATA_POINTER, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_RUNNER_FLOW_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_WAN_UDP_FILTER_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_UDP_FILTER_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "FC_MCAST_PORT_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &FC_MCAST_PORT_HEADER_BUFFER, 8, 64, 1 },
#endif
#if defined DSL_63148
	{ "GSO_PICO_QUEUE", 1, PRIVATE_A_INDEX, &GSO_PICO_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CONNECTION_CONTEXT_MULTICAST_BUFFER", 1, PRIVATE_A_INDEX, &DS_CONNECTION_CONTEXT_MULTICAST_BUFFER, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DOWNSTREAM_LAN_ENQUEUE_SQ_PD", 1, PRIVATE_A_INDEX, &DOWNSTREAM_LAN_ENQUEUE_SQ_PD, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_TX_BBH_DESCRIPTORS", 1, PRIVATE_A_INDEX, &DS_CPU_TX_BBH_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PROFILING_BUFFER_PICO_RUNNER", 1, PRIVATE_A_INDEX, &DS_PROFILING_BUFFER_PICO_RUNNER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_FAST_QUEUE", 1, PRIVATE_A_INDEX, &CPU_TX_FAST_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_PICO_QUEUE", 1, PRIVATE_A_INDEX, &CPU_TX_PICO_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_SPDSVC_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_SPDSVC_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_SSID_STATS_STATE_TABLE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_SSID_STATS_STATE_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_MAIN_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_MAIN_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_NULL_BUFFER", 1, PRIVATE_A_INDEX, &DS_NULL_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_SERVICE_TM_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_SERVICE_TM_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_BPM_EXTRA_DDR_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_EXTRA_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_POST_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DHD_TX_POST_PD_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_QUEUE_PROFILE_TABLE", 1, PRIVATE_A_INDEX, &DS_QUEUE_PROFILE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_RX_SQ_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_SQ_PD_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "EMAC_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_A_INDEX, &EMAC_ABSOLUTE_TX_BBH_COUNTER, 10, 1, 1 },
#endif
#if defined DSL_63148
	{ "FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PICO_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_PICO_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "EMAC_SKB_ENQUEUED_INDEXES_FIFO", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FIFO, 5, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_TX_MESSAGE_DATA_BUFFER", 1, PRIVATE_A_INDEX, &DS_CPU_TX_MESSAGE_DATA_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GPON_RX_DIRECT_DESCRIPTORS", 1, PRIVATE_A_INDEX, &GPON_RX_DIRECT_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_RX_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_PD_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_GSO_DESC_TABLE", 1, PRIVATE_A_INDEX, &DS_GSO_DESC_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_RX_FAST_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_FAST_PD_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_SQ_ENQUEUE_QUEUE", 1, PRIVATE_A_INDEX, &DS_SQ_ENQUEUE_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FLOW_IH_RESPONSE", 1, PRIVATE_A_INDEX, &RUNNER_FLOW_IH_RESPONSE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_BPM_DDR_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CONNECTION_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONNECTION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_GSO_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_GSO_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CONTEXT_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONTEXT_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DEBUG_PERIPHERALS_STATUS_REGISTER", 1, PRIVATE_A_INDEX, &DS_DEBUG_PERIPHERALS_STATUS_REGISTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_COMPLETE_RING_BUFFER", 1, PRIVATE_A_INDEX, &DHD_COMPLETE_RING_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CONTEXT_CONTINUATION_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONTEXT_CONTINUATION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "MULTICAST_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &MULTICAST_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GPON_RX_NORMAL_DESCRIPTORS", 1, PRIVATE_A_INDEX, &GPON_RX_NORMAL_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_RX_PICO_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_PICO_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_GPE_COMMAND_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_GPE_COMMAND_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DOWNSTREAM_MULTICAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "FC_MCAST_CONNECTION_TABLE_PLUS", 1, PRIVATE_A_INDEX, &FC_MCAST_CONNECTION_TABLE_PLUS, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GSO_DESC_PTR", 1, PRIVATE_A_INDEX, &GSO_DESC_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DATA_POINTER_DUMMY_TARGET", 1, PRIVATE_A_INDEX, &DS_DATA_POINTER_DUMMY_TARGET, 5, 1, 1 },
#endif
#if defined DSL_63148
	{ "FIREWALL_IPV6_R16_BUFFER", 1, PRIVATE_A_INDEX, &FIREWALL_IPV6_R16_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT", 1, PRIVATE_A_INDEX, &GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_ROUTER_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_ROUTER_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_FLOW_RING_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_FLOW_RING_DROP_COUNTER, 5, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPTV_COUNTERS_BUFFER", 1, PRIVATE_A_INDEX, &IPTV_COUNTERS_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &CPU_TX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT", 1, PRIVATE_A_INDEX, &CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_A_INDEX, &DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "HASH_BUFFER", 1, PRIVATE_A_INDEX, &HASH_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_RX_FAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_FAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DEBUG_BUFFER", 1, PRIVATE_A_INDEX, &DS_DEBUG_BUFFER, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FW_MAC_ADDRS", 1, PRIVATE_A_INDEX, &DS_FW_MAC_ADDRS, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_SYSTEM_CONFIGURATION", 1, PRIVATE_A_INDEX, &DS_SYSTEM_CONFIGURATION, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD", 1, PRIVATE_A_INDEX, &FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS, 5, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH_TX_EMACS_STATUS", 1, PRIVATE_A_INDEX, &ETH_TX_EMACS_STATUS, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_RX_PD_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &CPU_RX_PD_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_QUEUE", 1, PRIVATE_A_INDEX, &IPSEC_DS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_TX_POST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_A_INDEX, &DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE", 1, PRIVATE_A_INDEX, &DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_SA_DESC_CAM_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_CAM_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_US_SA_DESC_CAM_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_CAM_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "GSO_TX_DHD_L2_BUFFER", 1, PRIVATE_A_INDEX, &GSO_TX_DHD_L2_BUFFER, 22, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_RX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DS_CPU_RX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_DHD_L2_BUFFER", 1, PRIVATE_A_INDEX, &CPU_TX_DHD_L2_BUFFER, 22, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_BPM_DDR_BUFFER_HEADROOM_SIZE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFER_HEADROOM_SIZE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH_TX_SCRATCH", 1, PRIVATE_A_INDEX, &ETH_TX_SCRATCH, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_INGRESS_CLASSIFICATION_KEY_BUFFER", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_KEY_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &WLAN_MCAST_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "HASH_BASED_FORWARDING_PORT_TABLE", 1, PRIVATE_A_INDEX, &HASH_BASED_FORWARDING_PORT_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_RX_FAST_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DS_CPU_RX_FAST_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_ANY_SRC_PORT_FLOW_COUNTER", 1, PRIVATE_A_INDEX, &DS_ANY_SRC_PORT_FLOW_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GSO_TX_DHD_HOST_BUF_PTR", 1, PRIVATE_A_INDEX, &GSO_TX_DHD_HOST_BUF_PTR, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_DDR_SA_DESC_TABLE_PTR", 1, PRIVATE_A_INDEX, &IPSEC_DS_DDR_SA_DESC_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_DHD_HOST_BUF_PTR", 1, PRIVATE_A_INDEX, &CPU_TX_DHD_HOST_BUF_PTR, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "GSO_PICO_QUEUE_PTR", 1, PRIVATE_A_INDEX, &GSO_PICO_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_MEMLIB_SEMAPHORE", 1, PRIVATE_A_INDEX, &DS_MEMLIB_SEMAPHORE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "WAN_PHYSICAL_PORT", 1, PRIVATE_A_INDEX, &WAN_PHYSICAL_PORT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_RUNNER_CONGESTION_STATE", 1, PRIVATE_A_INDEX, &DS_RUNNER_CONGESTION_STATE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_COMPLETE_BPM_REF_COUNTER", 1, PRIVATE_A_INDEX, &DHD_TX_COMPLETE_BPM_REF_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_POST_CPU_BPM_REF_COUNTER", 1, PRIVATE_A_INDEX, &DHD_TX_POST_CPU_BPM_REF_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_DDR_SA_DESC_SIZE", 1, PRIVATE_A_INDEX, &IPSEC_DS_DDR_SA_DESC_SIZE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &IPSEC_DS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_IP_LENGTH", 1, PRIVATE_A_INDEX, &IPSEC_DS_IP_LENGTH, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "PRIVATE_A_DUMMY_STORE", 1, PRIVATE_A_INDEX, &PRIVATE_A_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH_TX_INTER_LAN_SCHEDULING_OFFSET", 1, PRIVATE_A_INDEX, &ETH_TX_INTER_LAN_SCHEDULING_OFFSET, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_A_INDEX, &DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_A_INDEX, &DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_DS_PICO_SEMAPHORE", 1, PRIVATE_A_INDEX, &CPU_TX_DS_PICO_SEMAPHORE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FC_ACCEL_MODE", 1, PRIVATE_A_INDEX, &DS_FC_ACCEL_MODE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PACKET_BUFFER_SIZE_ASR_8", 1, PRIVATE_A_INDEX, &DS_PACKET_BUFFER_SIZE_ASR_8, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_MAIN_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_A_INDEX, &DS_MAIN_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PICO_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_A_INDEX, &DS_PICO_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_RUNNER_FLOW_IH_RESPONSE_MUTEX", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_IH_RESPONSE_MUTEX, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PARALLEL_PROCESSING_SLAVE_VECTOR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_SLAVE_VECTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_FW_MAC_ADDRS_COUNT", 1, PRIVATE_A_INDEX, &DS_FW_MAC_ADDRS_COUNT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_DMA_SYNCHRONIZATION", 1, PRIVATE_A_INDEX, &DS_DHD_DMA_SYNCHRONIZATION, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_POST_CPU_SEMAPHORE", 1, PRIVATE_A_INDEX, &DHD_TX_POST_CPU_SEMAPHORE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_DS_SA_DESC_NEXT_REPLACE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_NEXT_REPLACE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPSEC_US_SA_DESC_NEXT_REPLACE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_NEXT_REPLACE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_HANDLER_BUFFER", 1, PRIVATE_B_INDEX, &US_INGRESS_HANDLER_BUFFER, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CSO_CHUNK_BUFFER", 1, PRIVATE_B_INDEX, &US_CSO_CHUNK_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CSO_PSEUDO_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &US_CSO_PSEUDO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_PARAMETERS_BLOCK", 1, PRIVATE_B_INDEX, &US_CPU_PARAMETERS_BLOCK, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_REASON_TO_METER_TABLE", 1, PRIVATE_B_INDEX, &US_CPU_REASON_TO_METER_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_MAIN_PROFILING_BUFFER_RUNNER", 1, PRIVATE_B_INDEX, &US_MAIN_PROFILING_BUFFER_RUNNER, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FREE_PACKET_DESCRIPTORS_POOL", 1, PRIVATE_B_INDEX, &US_FREE_PACKET_DESCRIPTORS_POOL, 3072, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RUNNER_FLOW_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_HEADER_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_QUEUE_PROFILE_TABLE", 1, PRIVATE_B_INDEX, &US_QUEUE_PROFILE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "WAN_CHANNELS_8_39_TABLE", 1, PRIVATE_B_INDEX, &WAN_CHANNELS_8_39_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_POLICER_TABLE", 1, PRIVATE_B_INDEX, &US_POLICER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_RX_METER_TABLE", 1, PRIVATE_B_INDEX, &US_CPU_RX_METER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_SBPM_REPLY", 1, PRIVATE_B_INDEX, &US_SBPM_REPLY, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_TX_BBH_DESCRIPTORS", 1, PRIVATE_B_INDEX, &US_CPU_TX_BBH_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FORWARDING_MATRIX_TABLE", 1, PRIVATE_B_INDEX, &US_FORWARDING_MATRIX_TABLE, 9, 16, 1 },
#endif
#if defined DSL_63148
	{ "US_TIMER_SCHEDULER_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_TIMER_SCHEDULER_PRIMITIVE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_B_INDEX, &US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_TRAFFIC_CLASS_TO_QUEUE_TABLE", 1, PRIVATE_B_INDEX, &US_TRAFFIC_CLASS_TO_QUEUE_TABLE, 8, 8, 1 },
#endif
#if defined DSL_63148
	{ "US_WAN_FLOW_TABLE", 1, PRIVATE_B_INDEX, &US_WAN_FLOW_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_HANDLER_SKB_DATA_POINTER", 1, PRIVATE_B_INDEX, &US_INGRESS_HANDLER_SKB_DATA_POINTER, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PROFILING_BUFFER_PICO_RUNNER", 1, PRIVATE_B_INDEX, &US_PROFILING_BUFFER_PICO_RUNNER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_B_INDEX, &US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_B_INDEX, &US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PICO_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_B_INDEX, &US_PICO_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FC_L2_UCAST_TUPLE_BUFFER", 1, PRIVATE_B_INDEX, &US_FC_L2_UCAST_TUPLE_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RATE_LIMITER_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_LIMITER_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_RX_COMPLETE_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &DHD_RX_COMPLETE_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FAST_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_B_INDEX, &US_FAST_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CONNECTION_CONTEXT_BUFFER", 1, PRIVATE_B_INDEX, &US_CONNECTION_CONTEXT_BUFFER, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_CLASSIFICATION_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "WAN_CHANNELS_0_7_TABLE", 1, PRIVATE_B_INDEX, &WAN_CHANNELS_0_7_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_TX_MESSAGE_DATA_BUFFER", 1, PRIVATE_B_INDEX, &US_CPU_TX_MESSAGE_DATA_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_RX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &DHD_RX_POST_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PICO_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_B_INDEX, &US_PICO_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_RATE_LIMITER_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_RATE_LIMITER_TABLE, 5, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FC_L2_UCAST_CONNECTION_BUFFER", 1, PRIVATE_B_INDEX, &US_FC_L2_UCAST_CONNECTION_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RUNNER_FLOW_HEADER_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_HEADER_DESCRIPTOR, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_ONE_BUFFER", 1, PRIVATE_B_INDEX, &US_ONE_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_SPDSVC_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_SPDSVC_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GPON_ABSOLUTE_TX_FIRMWARE_COUNTER", 1, PRIVATE_B_INDEX, &GPON_ABSOLUTE_TX_FIRMWARE_COUNTER, 40, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_MAINB_PARAM", 1, PRIVATE_B_INDEX, &RUNNER_FWTRACE_MAINB_PARAM, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_RX_PICO_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_RX_PICO_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_GPE_COMMAND_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_GPE_COMMAND_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_ROUTER_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_ROUTER_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_PICOB_PARAM", 1, PRIVATE_B_INDEX, &RUNNER_FWTRACE_PICOB_PARAM, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_RX_FAST_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_RX_FAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DEBUG_BUFFER", 1, PRIVATE_B_INDEX, &US_DEBUG_BUFFER, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FW_MAC_ADDRS", 1, PRIVATE_B_INDEX, &US_FW_MAC_ADDRS, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_TX_POST_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE", 1, PRIVATE_B_INDEX, &US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE, 48, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_B_INDEX, &US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE", 1, PRIVATE_B_INDEX, &US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_FLOW_RING_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_FLOW_RING_DROP_COUNTER, 5, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_ETH0_EEE_MODE_CONFIG_MESSAGE", 1, PRIVATE_B_INDEX, &US_ETH0_EEE_MODE_CONFIG_MESSAGE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_NULL_BUFFER", 1, PRIVATE_B_INDEX, &US_NULL_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_B_INDEX, &US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "WAN_TX_SCRATCH", 1, PRIVATE_B_INDEX, &WAN_TX_SCRATCH, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CSO_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_CSO_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_BPM_EXTRA_DDR_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_EXTRA_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_MAIN_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_MAIN_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_SYSTEM_CONFIGURATION", 1, PRIVATE_B_INDEX, &US_SYSTEM_CONFIGURATION, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_BPM_DDR_OPTIMIZED_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_OPTIMIZED_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE", 1, PRIVATE_B_INDEX, &CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE, 3, 6, 1 },
#endif
#if defined DSL_63148
	{ "US_PICO_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_PICO_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_BPM_DDR_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_CLASSIFICATION_KEY_BUFFER", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_KEY_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT", 1, PRIVATE_B_INDEX, &CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_DHD_LAYER2_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &CPU_TX_DHD_LAYER2_HEADER_BUFFER, 14, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_RX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &US_CPU_RX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DATA_POINTER_DUMMY_TARGET", 1, PRIVATE_B_INDEX, &DATA_POINTER_DUMMY_TARGET, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CONNECTION_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONNECTION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CONTEXT_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONTEXT_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DEBUG_PERIPHERALS_STATUS_REGISTER", 1, PRIVATE_B_INDEX, &US_DEBUG_PERIPHERALS_STATUS_REGISTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PARALLEL_PROCESSING_TASK_REORDER_FIFO", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_TASK_REORDER_FIFO, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "IH_BUFFER_BBH_POINTER", 1, PRIVATE_B_INDEX, &IH_BUFFER_BBH_POINTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE", 1, PRIVATE_B_INDEX, &BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CONTEXT_CONTINUATION_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONTEXT_CONTINUATION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_BPM_DDR_BUFFER_HEADROOM_SIZE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFER_HEADROOM_SIZE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RATE_CONTROLLER_EXPONENT_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_CONTROLLER_EXPONENT_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_RX_FAST_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &US_CPU_RX_FAST_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_ANY_SRC_PORT_FLOW_COUNTER", 1, PRIVATE_B_INDEX, &US_ANY_SRC_PORT_FLOW_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_MEMLIB_SEMAPHORE", 1, PRIVATE_B_INDEX, &US_MEMLIB_SEMAPHORE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_TX_POST_HOST_DATA_PTR_BUFFER", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_HOST_DATA_PTR_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETHWAN2_RX_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &ETHWAN2_RX_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RUNNER_CONGESTION_STATE", 1, PRIVATE_B_INDEX, &US_RUNNER_CONGESTION_STATE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "WAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &WAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "PRIVATE_B_DUMMY_STORE", 1, PRIVATE_B_INDEX, &PRIVATE_B_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_B_INDEX, &US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_B_INDEX, &US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FC_ACCEL_MODE", 1, PRIVATE_B_INDEX, &US_FC_ACCEL_MODE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETHWAN2_SWITCH_PORT", 1, PRIVATE_B_INDEX, &ETHWAN2_SWITCH_PORT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PACKET_BUFFER_SIZE_ASR_8", 1, PRIVATE_B_INDEX, &US_PACKET_BUFFER_SIZE_ASR_8, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_MAIN_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_B_INDEX, &US_MAIN_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PICO_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_B_INDEX, &US_PICO_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RUNNER_FLOW_IH_RESPONSE_MUTEX", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_IH_RESPONSE_MUTEX, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DSL_PTM_BOND_TX_CONTROL", 1, PRIVATE_B_INDEX, &DSL_PTM_BOND_TX_CONTROL, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DSL_BUFFER_ALIGNMENT", 1, PRIVATE_B_INDEX, &DSL_BUFFER_ALIGNMENT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PARALLEL_PROCESSING_SLAVE_VECTOR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_SLAVE_VECTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_FW_MAC_ADDRS_COUNT", 1, PRIVATE_B_INDEX, &US_FW_MAC_ADDRS_COUNT, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_DMA_SYNCHRONIZATION", 1, PRIVATE_B_INDEX, &US_DHD_DMA_SYNCHRONIZATION, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETHWAN_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_B_INDEX, &ETHWAN_ABSOLUTE_TX_BBH_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER", 1, PRIVATE_B_INDEX, &ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GPON_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_B_INDEX, &GPON_ABSOLUTE_TX_BBH_COUNTER, 40, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_TX_FAST_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_TX_FAST_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_TX_PICO_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_TX_PICO_QUEUE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETH1_RX_DESCRIPTORS", 1, PRIVATE_B_INDEX, &ETH1_RX_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RUNNER_FLOW_IH_RESPONSE", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_IH_RESPONSE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "BBH_TX_WAN_CHANNEL_INDEX", 1, PRIVATE_B_INDEX, &BBH_TX_WAN_CHANNEL_INDEX, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "SERVICE_QUEUES_DDR_CACHE_FIFO", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DDR_CACHE_FIFO, 384, 1, 1 },
#endif
#if defined DSL_63148
	{ "FC_MCAST_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &FC_MCAST_RUNNER_A_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_RX_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &CPU_RX_RUNNER_A_SCRATCHPAD, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &WLAN_MCAST_RUNNER_A_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_MAINA_BASE", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_MAINA_BASE, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_DHD_STATION_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_DHD_STATION_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE", 1, COMMON_A_INDEX, &DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE, 2, 64, 1 },
#endif
#if defined DSL_63148
	{ "DHD_RADIO_INSTANCE_COMMON_A_DATA", 1, COMMON_A_INDEX, &DHD_RADIO_INSTANCE_COMMON_A_DATA, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "FREE_SKB_INDEXES_DDR_FIFO_TAIL", 1, COMMON_A_INDEX, &FREE_SKB_INDEXES_DDR_FIFO_TAIL, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "BPM_REPLY_RUNNER_A", 1, COMMON_A_INDEX, &BPM_REPLY_RUNNER_A, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "RATE_SHAPERS_STATUS_DESCRIPTOR", 1, COMMON_A_INDEX, &RATE_SHAPERS_STATUS_DESCRIPTOR, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_MAINA_CURR_OFFSET", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_MAINA_CURR_OFFSET, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "GPON_SKB_ENQUEUED_INDEXES_FIFO", 1, COMMON_A_INDEX, &GPON_SKB_ENQUEUED_INDEXES_FIFO, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_FWD_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_FWD_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_PICOA_BASE", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_PICOA_BASE, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "SERVICE_QUEUES_DESCRIPTOR_TABLE", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DESCRIPTOR_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_SSID_MAC_ADDRESS_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_SSID_MAC_ADDRESS_TABLE, 48, 1, 1 },
#endif
#if defined DSL_63148
	{ "INTERRUPT_COALESCING_CONFIG_TABLE", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_CONFIG_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "GLOBAL_DSCP_TO_PBITS_DEI_TABLE", 1, COMMON_A_INDEX, &GLOBAL_DSCP_TO_PBITS_DEI_TABLE, 1, 64, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_SSID_STATS_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_SSID_STATS_TABLE, 48, 1, 1 },
#endif
#if defined DSL_63148
	{ "TRACE_C_TABLE", 1, COMMON_A_INDEX, &TRACE_C_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "SERVICE_QUEUES_CFG", 1, COMMON_A_INDEX, &SERVICE_QUEUES_CFG, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_RATE_CONTROLLER_EXPONENT_TABLE", 1, COMMON_A_INDEX, &DS_RATE_CONTROLLER_EXPONENT_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "INTERRUPT_COALESCING_TIMER_PERIOD", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_TIMER_PERIOD, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "INTERRUPT_COALESCING_TIMER_ARMED", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_TIMER_ARMED, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_FLOW_RING_CACHE_LKP_TABLE", 1, COMMON_A_INDEX, &DS_DHD_FLOW_RING_CACHE_LKP_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "PM_COUNTERS_BUFFER", 1, COMMON_A_INDEX, &PM_COUNTERS_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CONNECTION_BUFFER_TABLE", 1, COMMON_A_INDEX, &DS_CONNECTION_BUFFER_TABLE, 5, 4, 1 },
#endif
#if defined DSL_63148
	{ "DS_L4_DST_PORT_TABLE", 1, COMMON_A_INDEX, &DS_L4_DST_PORT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "L4_DST_PORT_CONTEXT_TABLE", 1, COMMON_A_INDEX, &L4_DST_PORT_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_FLOW_RING_SHADOW_WR_PTR_TABLE", 1, COMMON_A_INDEX, &DHD_FLOW_RING_SHADOW_WR_PTR_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER", 1, COMMON_A_INDEX, &DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_POST_BUFFERS_THRESHOLD", 1, COMMON_A_INDEX, &DHD_TX_POST_BUFFERS_THRESHOLD, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_POST_BUFFERS_IN_USE_COUNTER", 1, COMMON_A_INDEX, &DHD_TX_POST_BUFFERS_IN_USE_COUNTER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "COMMON_A_DUMMY_STORE", 1, COMMON_A_INDEX, &COMMON_A_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "FC_SERVICE_QUEUE_MODE", 1, COMMON_A_INDEX, &FC_SERVICE_QUEUE_MODE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "PM_COUNTERS", 1, COMMON_A_INDEX, &PM_COUNTERS, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "ETHWAN2_RX_INGRESS_QUEUE", 1, COMMON_A_INDEX, &ETHWAN2_RX_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_RING_PACKET_DESCRIPTORS_CACHE", 1, COMMON_A_INDEX, &DS_RING_PACKET_DESCRIPTORS_CACHE, 14, 1, 1 },
#endif
#if defined DSL_63148
	{ "RING_DESCRIPTORS_TABLE", 1, COMMON_A_INDEX, &RING_DESCRIPTORS_TABLE, 12, 1, 1 },
#endif
#if defined DSL_63148
	{ "MAIN_A_DEBUG_TRACE", 1, COMMON_A_INDEX, &MAIN_A_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined DSL_63148
	{ "PICO_A_DEBUG_TRACE", 1, COMMON_A_INDEX, &PICO_A_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined DSL_63148
	{ "WAN_TX_QUEUES_TABLE", 1, COMMON_B_INDEX, &WAN_TX_QUEUES_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CONNECTION_BUFFER_TABLE", 1, COMMON_B_INDEX, &US_CONNECTION_BUFFER_TABLE, 5, 4, 1 },
#endif
#if defined DSL_63148
	{ "IPV6_HOST_ADDRESS_CRC_TABLE", 1, COMMON_B_INDEX, &IPV6_HOST_ADDRESS_CRC_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "EPON_DDR_QUEUE_ADDRESS_TABLE", 1, COMMON_B_INDEX, &EPON_DDR_QUEUE_ADDRESS_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE", 1, COMMON_B_INDEX, &LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE", 1, COMMON_B_INDEX, &DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_MAINB_BASE", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_MAINB_BASE, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_PICOB_BASE", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_PICOB_BASE, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE", 1, COMMON_B_INDEX, &US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE, 32, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_L4_DST_PORT_TABLE", 1, COMMON_B_INDEX, &US_L4_DST_PORT_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "WAN_TX_RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &WAN_TX_RUNNER_B_SCRATCHPAD, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE", 1, COMMON_B_INDEX, &DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_INGRESS_CLASSIFICATION_LOOKUP_TABLE", 1, COMMON_B_INDEX, &US_INGRESS_CLASSIFICATION_LOOKUP_TABLE, 256, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_RX_RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &CPU_RX_RUNNER_B_SCRATCHPAD, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "EPON_DDR_CACHE_FIFO", 1, COMMON_B_INDEX, &EPON_DDR_CACHE_FIFO, 192, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_FLOW_RING_CACHE_CTX_TABLE", 1, COMMON_B_INDEX, &DHD_FLOW_RING_CACHE_CTX_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "FC_FLOW_IP_ADDRESSES_TABLE", 1, COMMON_B_INDEX, &FC_FLOW_IP_ADDRESSES_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "DSL_PTM_BOND_TX_HDR_TABLE", 1, COMMON_B_INDEX, &DSL_PTM_BOND_TX_HDR_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "BPM_REPLY_RUNNER_B", 1, COMMON_B_INDEX, &BPM_REPLY_RUNNER_B, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RATE_CONTROLLERS_TABLE", 1, COMMON_B_INDEX, &US_RATE_CONTROLLERS_TABLE, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &RUNNER_B_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_RING_PACKET_DESCRIPTORS_CACHE", 1, COMMON_B_INDEX, &US_RING_PACKET_DESCRIPTORS_CACHE, 14, 1, 1 },
#endif
#if defined DSL_63148
	{ "IPV4_HOST_ADDRESS_TABLE", 1, COMMON_B_INDEX, &IPV4_HOST_ADDRESS_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_RADIO_INSTANCE_COMMON_B_DATA", 1, COMMON_B_INDEX, &DHD_RADIO_INSTANCE_COMMON_B_DATA, 3, 1, 1 },
#endif
#if defined DSL_63148
	{ "DUMMY_RATE_CONTROLLER_DESCRIPTOR", 1, COMMON_B_INDEX, &DUMMY_RATE_CONTROLLER_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "MAIN_B_DEBUG_TRACE", 1, COMMON_B_INDEX, &MAIN_B_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined DSL_63148
	{ "PICO_B_DEBUG_TRACE", 1, COMMON_B_INDEX, &PICO_B_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined DSL_63148
	{ "EPON_DDR_QUEUE_DESCRIPTORS_TABLE", 1, COMMON_B_INDEX, &EPON_DDR_QUEUE_DESCRIPTORS_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "GPON_SKB_ENQUEUED_INDEXES_FREE_PTR", 1, COMMON_B_INDEX, &GPON_SKB_ENQUEUED_INDEXES_FREE_PTR, 40, 1, 1 },
#endif
#if defined DSL_63148
	{ "RUNNER_FWTRACE_MAINB_CURR_OFFSET", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_MAINB_CURR_OFFSET, 2, 1, 1 },
#endif
#if defined DSL_63148
	{ "DUMMY_WAN_TX_QUEUE_DESCRIPTOR", 1, COMMON_B_INDEX, &DUMMY_WAN_TX_QUEUE_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER", 1, COMMON_B_INDEX, &US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "GPON_SKB_ENQUEUED_INDEXES_PUT_PTR", 1, COMMON_B_INDEX, &GPON_SKB_ENQUEUED_INDEXES_PUT_PTR, 40, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE", 1, COMMON_B_INDEX, &US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE, 2, 64, 1 },
#endif
#if defined DSL_63148
	{ "BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE", 1, COMMON_B_INDEX, &BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE", 1, COMMON_B_INDEX, &CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE, 4, 1, 1 },
#endif
#if defined DSL_63148
	{ "BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR", 1, COMMON_B_INDEX, &BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "COMMON_B_DUMMY_STORE", 1, COMMON_B_INDEX, &COMMON_B_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX", 1, COMMON_B_INDEX, &DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "PACKET_SRAM_TO_DDR_COPY_BUFFER_1", 1, COMMON_B_INDEX, &PACKET_SRAM_TO_DDR_COPY_BUFFER_1, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "PACKET_SRAM_TO_DDR_COPY_BUFFER_2", 1, COMMON_B_INDEX, &PACKET_SRAM_TO_DDR_COPY_BUFFER_2, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LAN0_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN0_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LAN5_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN5_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LAN1_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN1_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LAN6_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN6_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LAN2_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN2_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LAN7_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN7_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "LAN3_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN3_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_DHD_FLOW_RING_CACHE_LKP_TABLE", 1, COMMON_B_INDEX, &US_DHD_FLOW_RING_CACHE_LKP_TABLE, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "LAN4_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN4_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined DSL_63148
	{ "WAN_ENQUEUE_INGRESS_QUEUE", 1, COMMON_B_INDEX, &WAN_ENQUEUE_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "BPM_PACKET_BUFFERS", 1, DDR_INDEX, &BPM_PACKET_BUFFERS, 7680, 1, 1 },
#endif
#if defined DSL_63148
	{ "DS_CONNECTION_TABLE", 1, DDR_INDEX, &DS_CONNECTION_TABLE, 32768, 1, 1 },
#endif
#if defined DSL_63148
	{ "US_CONNECTION_TABLE", 1, DDR_INDEX, &US_CONNECTION_TABLE, 32768, 1, 1 },
#endif
#if defined DSL_63148
	{ "CONTEXT_TABLE", 1, DDR_INDEX, &CONTEXT_TABLE, 16512, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE", 1, DDR_INDEX, &DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE, 8, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_RX_POST_DDR_BUFFER", 1, DDR_INDEX, &DHD_RX_POST_DDR_BUFFER, 1024, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_RX_COMPLETE_DDR_BUFFER", 1, DDR_INDEX, &DHD_RX_COMPLETE_DDR_BUFFER, 1024, 1, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_POST_DDR_BUFFER", 1, DDR_INDEX, &DHD_TX_POST_DDR_BUFFER, 8, 16, 1 },
#endif
#if defined DSL_63148
	{ "DHD_TX_COMPLETE_DDR_BUFFER", 1, DDR_INDEX, &DHD_TX_COMPLETE_DDR_BUFFER, 16, 1, 1 },
#endif
#if defined DSL_63148
	{ "R2D_WR_ARR_DDR_BUFFER", 1, DDR_INDEX, &R2D_WR_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "D2R_RD_ARR_DDR_BUFFER", 1, DDR_INDEX, &D2R_RD_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "R2D_RD_ARR_DDR_BUFFER", 1, DDR_INDEX, &R2D_RD_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "D2R_WR_ARR_DDR_BUFFER", 1, DDR_INDEX, &D2R_WR_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_DHD_LIST_TABLE", 1, DDR_INDEX, &WLAN_MCAST_DHD_LIST_TABLE, 64, 1, 1 },
#endif
#if defined DSL_63148
	{ "WLAN_MCAST_DHD_LIST_FORMAT_TABLE", 1, DDR_INDEX, &WLAN_MCAST_DHD_LIST_FORMAT_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "INGRESS_HANDLER_BUFFER", 1, PRIVATE_A_INDEX, &INGRESS_HANDLER_BUFFER, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FREE_PACKET_DESCRIPTORS_POOL", 1, PRIVATE_A_INDEX, &DS_FREE_PACKET_DESCRIPTORS_POOL, 2048, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CONNECTION_CONTEXT_BUFFER", 1, PRIVATE_A_INDEX, &DS_CONNECTION_CONTEXT_BUFFER, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_GSO_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_GSO_PSEUDO_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_PSEUDO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_PARAMETERS_BLOCK", 1, PRIVATE_A_INDEX, &DS_CPU_PARAMETERS_BLOCK, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE", 1, PRIVATE_A_INDEX, &DS_RATE_SHAPER_BUDGET_ALLOCATOR_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_REASON_TO_METER_TABLE", 1, PRIVATE_A_INDEX, &DS_CPU_REASON_TO_METER_TABLE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_GSO_CHUNK_BUFFER", 1, PRIVATE_A_INDEX, &DS_GSO_CHUNK_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_SERVICE_QUEUES_DESCRIPTORS_TABLE", 1, PRIVATE_A_INDEX, &DS_SERVICE_QUEUES_DESCRIPTORS_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_POLICER_TABLE", 1, PRIVATE_A_INDEX, &DS_POLICER_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_BUFFER_POOL", 1, PRIVATE_A_INDEX, &IPSEC_DS_BUFFER_POOL, 2, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_SA_DESC_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_US_SA_DESC_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "SERVICE_QUEUES_RATE_LIMITER_TABLE", 1, PRIVATE_A_INDEX, &SERVICE_QUEUES_RATE_LIMITER_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "ETH_TX_LOCAL_REGISTERS", 1, PRIVATE_A_INDEX, &ETH_TX_LOCAL_REGISTERS, 9, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RUNNER_FLOW_HEADER_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_HEADER_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_TIMER_SCHEDULER_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_TIMER_SCHEDULER_PRIMITIVE_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_MAIN_PROFILING_BUFFER_RUNNER", 1, PRIVATE_A_INDEX, &DS_MAIN_PROFILING_BUFFER_RUNNER, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_CONTROL_TABLE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_CONTROL_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_WAN_UDP_FILTER_CONTROL_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_UDP_FILTER_CONTROL_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "SERVICE_QUEUES_WLAN_SCRATCH", 1, PRIVATE_A_INDEX, &SERVICE_QUEUES_WLAN_SCRATCH, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FC_L2_UCAST_TUPLE_BUFFER", 1, PRIVATE_A_INDEX, &DS_FC_L2_UCAST_TUPLE_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "RATE_LIMITER_REMAINDER_TABLE", 1, PRIVATE_A_INDEX, &RATE_LIMITER_REMAINDER_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "FC_MCAST_CONNECTION2_TABLE", 1, PRIVATE_A_INDEX, &FC_MCAST_CONNECTION2_TABLE, 128, 1, 1 },
#endif
#if defined WL4908
	{ "ETH_TX_QUEUES_POINTERS_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_QUEUES_POINTERS_TABLE, 72, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_A_INDEX, &DS_FAST_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "SBPM_REPLY", 1, PRIVATE_A_INDEX, &SBPM_REPLY, 1, 1, 1 },
#endif
#if defined WL4908
	{ "ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_RS_QUEUE_DESCRIPTOR_TABLE, 128, 1, 1 },
#endif
#if defined WL4908
	{ "DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_LAN_ENQUEUE_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_A_INDEX, &DS_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_A_INDEX, &DS_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_COMPLETE_FLOW_RING_BUFFER", 1, PRIVATE_A_INDEX, &DHD_TX_COMPLETE_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FC_L2_UCAST_CONNECTION_BUFFER", 1, PRIVATE_A_INDEX, &DS_FC_L2_UCAST_CONNECTION_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RATE_LIMITER_TABLE", 1, PRIVATE_A_INDEX, &DS_RATE_LIMITER_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "ETH_TX_QUEUES_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_QUEUES_TABLE, 72, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_RX_METER_TABLE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_METER_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FORWARDING_MATRIX_TABLE", 1, PRIVATE_A_INDEX, &DS_FORWARDING_MATRIX_TABLE, 9, 16, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_MAINA_PARAM", 1, PRIVATE_A_INDEX, &RUNNER_FWTRACE_MAINA_PARAM, 2, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_A_INDEX, &DS_PICO_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_COMPLETE_RING_DESCRIPTOR_BUFFER", 1, PRIVATE_A_INDEX, &DHD_COMPLETE_RING_DESCRIPTOR_BUFFER, 3, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_PICOA_PARAM", 1, PRIVATE_A_INDEX, &RUNNER_FWTRACE_PICOA_PARAM, 2, 1, 1 },
#endif
#if defined WL4908
	{ "DS_WAN_FLOW_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_FLOW_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "DS_WAN_UDP_FILTER_TABLE", 1, PRIVATE_A_INDEX, &DS_WAN_UDP_FILTER_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "FC_MCAST_PORT_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &FC_MCAST_PORT_HEADER_BUFFER, 8, 64, 1 },
#endif
#if defined WL4908
	{ "GSO_PICO_QUEUE", 1, PRIVATE_A_INDEX, &GSO_PICO_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CONNECTION_CONTEXT_MULTICAST_BUFFER", 1, PRIVATE_A_INDEX, &DS_CONNECTION_CONTEXT_MULTICAST_BUFFER, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DOWNSTREAM_LAN_ENQUEUE_SQ_PD", 1, PRIVATE_A_INDEX, &DOWNSTREAM_LAN_ENQUEUE_SQ_PD, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_TX_BBH_DESCRIPTORS", 1, PRIVATE_A_INDEX, &DS_CPU_TX_BBH_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined WL4908
	{ "REVERSE_FFI_TABLE", 1, PRIVATE_A_INDEX, &REVERSE_FFI_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_RX_SQ_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_SQ_PD_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_POST_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DHD_TX_POST_PD_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "INGRESS_HANDLER_SKB_DATA_POINTER", 1, PRIVATE_A_INDEX, &INGRESS_HANDLER_SKB_DATA_POINTER, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RUNNER_FLOW_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_FAST_QUEUE", 1, PRIVATE_A_INDEX, &CPU_TX_FAST_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_RULE_CFG_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_PICO_QUEUE", 1, PRIVATE_A_INDEX, &CPU_TX_PICO_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_SPDSVC_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_SPDSVC_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FAST_MALLOC_RESULT_TABLE", 1, PRIVATE_A_INDEX, &DS_FAST_MALLOC_RESULT_TABLE, 2, 1, 1 },
#endif
#if defined WL4908
	{ "EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_PUT_PTR, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_A_INDEX, &DS_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PROFILING_BUFFER_PICO_RUNNER", 1, PRIVATE_A_INDEX, &DS_PROFILING_BUFFER_PICO_RUNNER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_QUEUE_PROFILE_TABLE", 1, PRIVATE_A_INDEX, &DS_QUEUE_PROFILE_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_QUEUE", 1, PRIVATE_A_INDEX, &IPSEC_DS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_SQ_ENQUEUE_QUEUE", 1, PRIVATE_A_INDEX, &DS_SQ_ENQUEUE_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "EMAC_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_A_INDEX, &EMAC_ABSOLUTE_TX_BBH_COUNTER, 10, 1, 1 },
#endif
#if defined WL4908
	{ "FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_MAIN_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_MAIN_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_BPM_EXTRA_DDR_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_EXTRA_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "EMAC_SKB_ENQUEUED_INDEXES_FIFO", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FIFO, 5, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_TX_MESSAGE_DATA_BUFFER", 1, PRIVATE_A_INDEX, &DS_CPU_TX_MESSAGE_DATA_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "GPON_RX_DIRECT_DESCRIPTORS", 1, PRIVATE_A_INDEX, &GPON_RX_DIRECT_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_RX_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_PD_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_GSO_DESC_TABLE", 1, PRIVATE_A_INDEX, &DS_GSO_DESC_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_RX_FAST_PD_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &CPU_RX_FAST_PD_INGRESS_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_RX_PICO_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_PICO_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_A_INDEX, &DS_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_A_INDEX, &DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FLOW_IH_RESPONSE", 1, PRIVATE_A_INDEX, &RUNNER_FLOW_IH_RESPONSE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_MALLOC_RESULT_TABLE", 1, PRIVATE_A_INDEX, &DS_PICO_MALLOC_RESULT_TABLE, 2, 1, 1 },
#endif
#if defined WL4908
	{ "DS_GSO_CONTEXT_TABLE", 1, PRIVATE_A_INDEX, &DS_GSO_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_SSID_STATS_STATE_TABLE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_SSID_STATS_STATE_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_PICO_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FREE_PTR, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_NULL_BUFFER", 1, PRIVATE_A_INDEX, &DS_NULL_BUFFER, 3, 1, 1 },
#endif
#if defined WL4908
	{ "DS_SERVICE_TM_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_SERVICE_TM_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_BPM_DDR_1_OPTIMIZED_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_1_OPTIMIZED_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "MULTICAST_HEADER_BUFFER", 1, PRIVATE_A_INDEX, &MULTICAST_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DOWNSTREAM_MULTICAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_GPE_COMMAND_PRIMITIVE_TABLE", 1, PRIVATE_A_INDEX, &DS_GPE_COMMAND_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_ROUTER_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_ROUTER_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "HASH_BUFFER", 1, PRIVATE_A_INDEX, &HASH_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_RX_FAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_CPU_RX_FAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DEBUG_BUFFER", 1, PRIVATE_A_INDEX, &DS_DEBUG_BUFFER, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FW_MAC_ADDRS", 1, PRIVATE_A_INDEX, &DS_FW_MAC_ADDRS, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_COMPLETE_RING_BUFFER", 1, PRIVATE_A_INDEX, &DHD_COMPLETE_RING_BUFFER, 3, 1, 1 },
#endif
#if defined WL4908
	{ "DS_BPM_DDR_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_BPM_DDR_1_BUFFERS_BASE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_1_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "FC_MCAST_CONNECTION_TABLE_PLUS", 1, PRIVATE_A_INDEX, &FC_MCAST_CONNECTION_TABLE_PLUS, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CONNECTION_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONNECTION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CONTEXT_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONTEXT_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR, 4, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_TX_POST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DATA_POINTER_DUMMY_TARGET", 1, PRIVATE_A_INDEX, &DS_DATA_POINTER_DUMMY_TARGET, 5, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DEBUG_PERIPHERALS_STATUS_REGISTER", 1, PRIVATE_A_INDEX, &DS_DEBUG_PERIPHERALS_STATUS_REGISTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_TASK_REORDER_FIFO, 4, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CONTEXT_CONTINUATION_TABLE_CONFIG", 1, PRIVATE_A_INDEX, &DS_CONTEXT_CONTINUATION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_A_INDEX, &DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM, 8, 1, 1 },
#endif
#if defined WL4908
	{ "ETH_TX_MAC_TABLE", 1, PRIVATE_A_INDEX, &ETH_TX_MAC_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_INGRESS_QUEUE", 1, PRIVATE_A_INDEX, &WLAN_MCAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_FLOW_RING_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_FLOW_RING_DROP_COUNTER, 5, 1, 1 },
#endif
#if defined WL4908
	{ "GSO_DESC_PTR", 1, PRIVATE_A_INDEX, &GSO_DESC_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE", 1, PRIVATE_A_INDEX, &DS_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "ETH_TX_SCRATCH", 1, PRIVATE_A_INDEX, &ETH_TX_SCRATCH, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_SYSTEM_CONFIGURATION", 1, PRIVATE_A_INDEX, &DS_SYSTEM_CONFIGURATION, 1, 1, 1 },
#endif
#if defined WL4908
	{ "FIREWALL_IPV6_R16_BUFFER", 1, PRIVATE_A_INDEX, &FIREWALL_IPV6_R16_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_SA_DESC_CAM_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_CAM_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_US_SA_DESC_CAM_TABLE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_CAM_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "GSO_TX_DHD_L2_BUFFER", 1, PRIVATE_A_INDEX, &GSO_TX_DHD_L2_BUFFER, 22, 1, 1 },
#endif
#if defined WL4908
	{ "IPTV_COUNTERS_BUFFER", 1, PRIVATE_A_INDEX, &IPTV_COUNTERS_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_DHD_L2_BUFFER", 1, PRIVATE_A_INDEX, &CPU_TX_DHD_L2_BUFFER, 22, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &CPU_TX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT", 1, PRIVATE_A_INDEX, &GSO_TX_ENQUEUE_PCI_PACKET_CONTEXT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_INGRESS_CLASSIFICATION_KEY_BUFFER", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_KEY_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &CPU_TX_DS_PICO_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &WLAN_MCAST_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT", 1, PRIVATE_A_INDEX, &GSO_TX_DS_PICO_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT", 1, PRIVATE_A_INDEX, &CPU_TX_ENQUEUE_PCI_PACKET_CONTEXT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS", 1, PRIVATE_A_INDEX, &EMAC_SKB_ENQUEUED_INDEXES_FIFO_COUNTERS, 5, 1, 1 },
#endif
#if defined WL4908
	{ "ETH_TX_EMACS_STATUS", 1, PRIVATE_A_INDEX, &ETH_TX_EMACS_STATUS, 1, 1, 1 },
#endif
#if defined WL4908
	{ "FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD", 1, PRIVATE_A_INDEX, &FREE_PACKET_DESCRIPTORS_POOL_THRESHOLD, 1, 1, 1 },
#endif
#if defined WL4908
	{ "HASH_BASED_FORWARDING_PORT_TABLE", 1, PRIVATE_A_INDEX, &HASH_BASED_FORWARDING_PORT_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_RX_PD_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &CPU_RX_PD_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_RX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DS_CPU_RX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_BPM_DDR_BUFFER_HEADROOM_SIZE", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFER_HEADROOM_SIZE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION", 1, PRIVATE_A_INDEX, &DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_RX_FAST_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DS_CPU_RX_FAST_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_ANY_SRC_PORT_FLOW_COUNTER", 1, PRIVATE_A_INDEX, &DS_ANY_SRC_PORT_FLOW_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER", 1, PRIVATE_A_INDEX, &DS_DHD_TX_POST_HOST_DATA_PTR_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "GSO_TX_DHD_HOST_BUF_PTR", 1, PRIVATE_A_INDEX, &GSO_TX_DHD_HOST_BUF_PTR, 4, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_DDR_SA_DESC_TABLE_PTR", 1, PRIVATE_A_INDEX, &IPSEC_DS_DDR_SA_DESC_TABLE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_DHD_HOST_BUF_PTR", 1, PRIVATE_A_INDEX, &CPU_TX_DHD_HOST_BUF_PTR, 4, 1, 1 },
#endif
#if defined WL4908
	{ "GSO_PICO_QUEUE_PTR", 1, PRIVATE_A_INDEX, &GSO_PICO_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_MEMLIB_SEMAPHORE", 1, PRIVATE_A_INDEX, &DS_MEMLIB_SEMAPHORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "WAN_PHYSICAL_PORT", 1, PRIVATE_A_INDEX, &WAN_PHYSICAL_PORT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &DOWNSTREAM_MULTICAST_LAN_ENQUEUE_SERVICE_QUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RUNNER_CONGESTION_STATE", 1, PRIVATE_A_INDEX, &DS_RUNNER_CONGESTION_STATE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_PTR", 1, PRIVATE_A_INDEX, &DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_COMPLETE_BPM_REF_COUNTER", 1, PRIVATE_A_INDEX, &DHD_TX_COMPLETE_BPM_REF_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_POST_CPU_BPM_REF_COUNTER", 1, PRIVATE_A_INDEX, &DHD_TX_POST_CPU_BPM_REF_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_BPM_CONGESTION_UG3_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER", 1, PRIVATE_A_INDEX, &DS_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_DDR_SA_DESC_SIZE", 1, PRIVATE_A_INDEX, &IPSEC_DS_DDR_SA_DESC_SIZE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_QUEUE_PTR", 1, PRIVATE_A_INDEX, &IPSEC_DS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_IP_LENGTH", 1, PRIVATE_A_INDEX, &IPSEC_DS_IP_LENGTH, 1, 1, 1 },
#endif
#if defined WL4908
	{ "PRIVATE_A_DUMMY_STORE", 1, PRIVATE_A_INDEX, &PRIVATE_A_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "ETH_TX_INTER_LAN_SCHEDULING_OFFSET", 1, PRIVATE_A_INDEX, &ETH_TX_INTER_LAN_SCHEDULING_OFFSET, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_A_INDEX, &DS_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_A_INDEX, &DS_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_DS_PICO_SEMAPHORE", 1, PRIVATE_A_INDEX, &CPU_TX_DS_PICO_SEMAPHORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FC_ACCEL_MODE", 1, PRIVATE_A_INDEX, &DS_FC_ACCEL_MODE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR", 1, PRIVATE_A_INDEX, &DS_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PACKET_BUFFER_SIZE_ASR_8", 1, PRIVATE_A_INDEX, &DS_PACKET_BUFFER_SIZE_ASR_8, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_MAIN_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_A_INDEX, &DS_MAIN_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_A_INDEX, &DS_PICO_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RUNNER_FLOW_IH_RESPONSE_MUTEX", 1, PRIVATE_A_INDEX, &DS_RUNNER_FLOW_IH_RESPONSE_MUTEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PARALLEL_PROCESSING_SLAVE_VECTOR", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_SLAVE_VECTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE", 1, PRIVATE_A_INDEX, &DS_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FAST_MALLOC_RESULT_MUTEX", 1, PRIVATE_A_INDEX, &DS_FAST_MALLOC_RESULT_MUTEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_PICO_MALLOC_RESULT_MUTEX", 1, PRIVATE_A_INDEX, &DS_PICO_MALLOC_RESULT_MUTEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RX_SBPM_TO_FPM_COPY_SEMAPHORE", 1, PRIVATE_A_INDEX, &DS_RX_SBPM_TO_FPM_COPY_SEMAPHORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_FW_MAC_ADDRS_COUNT", 1, PRIVATE_A_INDEX, &DS_FW_MAC_ADDRS_COUNT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_DMA_SYNCHRONIZATION", 1, PRIVATE_A_INDEX, &DS_DHD_DMA_SYNCHRONIZATION, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_POST_CPU_SEMAPHORE", 1, PRIVATE_A_INDEX, &DHD_TX_POST_CPU_SEMAPHORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_DS_SA_DESC_NEXT_REPLACE", 1, PRIVATE_A_INDEX, &IPSEC_DS_SA_DESC_NEXT_REPLACE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "IPSEC_US_SA_DESC_NEXT_REPLACE", 1, PRIVATE_A_INDEX, &IPSEC_US_SA_DESC_NEXT_REPLACE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "GPON_RX_NORMAL_DESCRIPTORS", 1, PRIVATE_A_INDEX, &GPON_RX_NORMAL_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_HANDLER_BUFFER", 1, PRIVATE_B_INDEX, &US_INGRESS_HANDLER_BUFFER, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_CSO_CHUNK_BUFFER", 1, PRIVATE_B_INDEX, &US_CSO_CHUNK_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_CSO_PSEUDO_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &US_CSO_PSEUDO_HEADER_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_PARAMETERS_BLOCK", 1, PRIVATE_B_INDEX, &US_CPU_PARAMETERS_BLOCK, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_CONTROL_BUDGET_ALLOCATOR_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_REASON_TO_METER_TABLE", 1, PRIVATE_B_INDEX, &US_CPU_REASON_TO_METER_TABLE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "US_MAIN_PROFILING_BUFFER_RUNNER", 1, PRIVATE_B_INDEX, &US_MAIN_PROFILING_BUFFER_RUNNER, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_FREE_PACKET_DESCRIPTORS_POOL", 1, PRIVATE_B_INDEX, &US_FREE_PACKET_DESCRIPTORS_POOL, 3072, 1, 1 },
#endif
#if defined WL4908
	{ "US_RUNNER_FLOW_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_HEADER_BUFFER, 3, 1, 1 },
#endif
#if defined WL4908
	{ "US_QUEUE_PROFILE_TABLE", 1, PRIVATE_B_INDEX, &US_QUEUE_PROFILE_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "WAN_CHANNELS_8_39_TABLE", 1, PRIVATE_B_INDEX, &WAN_CHANNELS_8_39_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_POLICER_TABLE", 1, PRIVATE_B_INDEX, &US_POLICER_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_RX_METER_TABLE", 1, PRIVATE_B_INDEX, &US_CPU_RX_METER_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_SBPM_REPLY", 1, PRIVATE_B_INDEX, &US_SBPM_REPLY, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_TX_BBH_DESCRIPTORS", 1, PRIVATE_B_INDEX, &US_CPU_TX_BBH_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_FORWARDING_MATRIX_TABLE", 1, PRIVATE_B_INDEX, &US_FORWARDING_MATRIX_TABLE, 9, 16, 1 },
#endif
#if defined WL4908
	{ "US_TIMER_SCHEDULER_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_TIMER_SCHEDULER_PRIMITIVE_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_B_INDEX, &US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "US_TRAFFIC_CLASS_TO_QUEUE_TABLE", 1, PRIVATE_B_INDEX, &US_TRAFFIC_CLASS_TO_QUEUE_TABLE, 8, 8, 1 },
#endif
#if defined WL4908
	{ "US_WAN_FLOW_TABLE", 1, PRIVATE_B_INDEX, &US_WAN_FLOW_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_HANDLER_SKB_DATA_POINTER", 1, PRIVATE_B_INDEX, &US_INGRESS_HANDLER_SKB_DATA_POINTER, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_RULE_CFG_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_PROFILING_BUFFER_PICO_RUNNER", 1, PRIVATE_B_INDEX, &US_PROFILING_BUFFER_PICO_RUNNER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_KEY_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_B_INDEX, &US_FAST_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE", 1, PRIVATE_B_INDEX, &US_PICO_CPU_TX_DESCRIPTOR_ABS_DATA_PTR_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_TIMER_TASK_DESCRIPTOR_TABLE", 1, PRIVATE_B_INDEX, &US_PICO_TIMER_TASK_DESCRIPTOR_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "US_FC_L2_UCAST_TUPLE_BUFFER", 1, PRIVATE_B_INDEX, &US_FC_L2_UCAST_TUPLE_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_RATE_LIMITER_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_LIMITER_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_RX_COMPLETE_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &DHD_RX_COMPLETE_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined WL4908
	{ "US_FAST_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_B_INDEX, &US_FAST_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_CONNECTION_CONTEXT_BUFFER", 1, PRIVATE_B_INDEX, &US_CONNECTION_CONTEXT_BUFFER, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_CLASSIFICATION_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "WAN_CHANNELS_0_7_TABLE", 1, PRIVATE_B_INDEX, &WAN_CHANNELS_0_7_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_TX_MESSAGE_DATA_BUFFER", 1, PRIVATE_B_INDEX, &US_CPU_TX_MESSAGE_DATA_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_RX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &DHD_RX_POST_FLOW_RING_BUFFER, 3, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_RUNNER_GLOBAL_REGISTERS_INIT", 1, PRIVATE_B_INDEX, &US_PICO_RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_RATE_LIMITER_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_RATE_LIMITER_TABLE, 5, 1, 1 },
#endif
#if defined WL4908
	{ "US_FC_L2_UCAST_CONNECTION_BUFFER", 1, PRIVATE_B_INDEX, &US_FC_L2_UCAST_CONNECTION_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_RX_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &DHD_RX_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_SPDSVC_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_SPDSVC_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_ONE_BUFFER", 1, PRIVATE_B_INDEX, &US_ONE_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_MAINB_PARAM", 1, PRIVATE_B_INDEX, &RUNNER_FWTRACE_MAINB_PARAM, 2, 1, 1 },
#endif
#if defined WL4908
	{ "US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &US_0_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_RX_PICO_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_RX_PICO_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &US_0_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &US_1_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_ROUTER_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_ROUTER_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &US_1_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &US_2_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_RX_FAST_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_RX_FAST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "US_DEBUG_BUFFER", 1, PRIVATE_B_INDEX, &US_DEBUG_BUFFER, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_FW_MAC_ADDRS", 1, PRIVATE_B_INDEX, &US_FW_MAC_ADDRS, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &US_2_MCAST_RX_SBPM_TO_FPM_COPY_FPM_ALLOC_RESULT_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_RUNNER_FLOW_HEADER_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_HEADER_DESCRIPTOR, 3, 1, 1 },
#endif
#if defined WL4908
	{ "US_NULL_BUFFER", 1, PRIVATE_B_INDEX, &US_NULL_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_TX_POST_INGRESS_QUEUE", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE", 1, PRIVATE_B_INDEX, &US_OVERALL_RATE_LIMITER_WAN_CHANNEL_PTR_TABLE, 48, 1, 1 },
#endif
#if defined WL4908
	{ "US_GPE_COMMAND_PRIMITIVE_TABLE", 1, PRIVATE_B_INDEX, &US_GPE_COMMAND_PRIMITIVE_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_B_INDEX, &US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_PICOB_PARAM", 1, PRIVATE_B_INDEX, &RUNNER_FWTRACE_PICOB_PARAM, 2, 1, 1 },
#endif
#if defined WL4908
	{ "US_CSO_CONTEXT_TABLE", 1, PRIVATE_B_INDEX, &US_CSO_CONTEXT_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_ETH0_EEE_MODE_CONFIG_MESSAGE", 1, PRIVATE_B_INDEX, &US_ETH0_EEE_MODE_CONFIG_MESSAGE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "GPON_ABSOLUTE_TX_FIRMWARE_COUNTER", 1, PRIVATE_B_INDEX, &GPON_ABSOLUTE_TX_FIRMWARE_COUNTER, 40, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_CAM, 8, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER", 1, PRIVATE_B_INDEX, &CPU_TX_DS_EGRESS_DHD_TX_POST_FLOW_RING_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE", 1, PRIVATE_B_INDEX, &US_BRIDGE_PORT_TO_LOOKUP_PORT_MAPPING_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_FLOW_RING_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_FLOW_RING_DROP_COUNTER, 5, 1, 1 },
#endif
#if defined WL4908
	{ "US_BPM_EXTRA_DDR_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_EXTRA_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_FAST_MALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &US_FAST_MALLOC_RESULT_TABLE, 2, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE", 1, PRIVATE_B_INDEX, &US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "WAN_TX_SCRATCH", 1, PRIVATE_B_INDEX, &WAN_TX_SCRATCH, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_SYSTEM_CONFIGURATION", 1, PRIVATE_B_INDEX, &US_SYSTEM_CONFIGURATION, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_BPM_DDR_OPTIMIZED_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_OPTIMIZED_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE", 1, PRIVATE_B_INDEX, &CPU_REASON_AND_SRC_BRIDGE_PORT_TO_METER_TABLE, 3, 6, 1 },
#endif
#if defined WL4908
	{ "US_MAIN_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_MAIN_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_BPM_DDR_1_OPTIMIZED_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_1_OPTIMIZED_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "ETHWAN_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_B_INDEX, &ETHWAN_ABSOLUTE_TX_BBH_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "PRIVATE_B_DUMMY_STORE", 1, PRIVATE_B_INDEX, &PRIVATE_B_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_TIMER_CONTROL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_PICO_TIMER_CONTROL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_BPM_DDR_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER", 1, PRIVATE_B_INDEX, &ETHWAN_ABSOLUTE_TX_FIRMWARE_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_B_INDEX, &US_FAST_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_RX_PICO_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &US_CPU_RX_PICO_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_BPM_DDR_1_BUFFERS_BASE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_1_BUFFERS_BASE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "GPON_ABSOLUTE_TX_BBH_COUNTER", 1, PRIVATE_B_INDEX, &GPON_ABSOLUTE_TX_BBH_COUNTER, 40, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_DEFAULT_FLOWS_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_MALLOC_RESULT_TABLE", 1, PRIVATE_B_INDEX, &US_PICO_MALLOC_RESULT_TABLE, 2, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_CLASSIFICATION_KEY_BUFFER", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_KEY_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT", 1, PRIVATE_B_INDEX, &CPU_TX_DS_EGRESS_DHD_TX_POST_CONTEXT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_DHD_LAYER2_HEADER_BUFFER", 1, PRIVATE_B_INDEX, &CPU_TX_DHD_LAYER2_HEADER_BUFFER, 14, 1, 1 },
#endif
#if defined WL4908
	{ "US_BPM_DDR_BUFFER_HEADROOM_SIZE", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFER_HEADROOM_SIZE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_FREE_PACKET_DESCRIPTORS_POOL_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION", 1, PRIVATE_B_INDEX, &US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DATA_POINTER_DUMMY_TARGET", 1, PRIVATE_B_INDEX, &DATA_POINTER_DUMMY_TARGET, 2, 1, 1 },
#endif
#if defined WL4908
	{ "US_CONNECTION_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONNECTION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_CONTEXT_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONTEXT_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR, 4, 1, 1 },
#endif
#if defined WL4908
	{ "US_DEBUG_PERIPHERALS_STATUS_REGISTER", 1, PRIVATE_B_INDEX, &US_DEBUG_PERIPHERALS_STATUS_REGISTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PARALLEL_PROCESSING_TASK_REORDER_FIFO", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_TASK_REORDER_FIFO, 4, 1, 1 },
#endif
#if defined WL4908
	{ "IH_BUFFER_BBH_POINTER", 1, PRIVATE_B_INDEX, &IH_BUFFER_BBH_POINTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_INDEX_CACHE_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE", 1, PRIVATE_B_INDEX, &BROADCOM_SWITCH_PORT_TO_BRIDGE_PORT_MAPPING_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_CONTEXT_CONTINUATION_TABLE_CONFIG", 1, PRIVATE_B_INDEX, &US_CONTEXT_CONTINUATION_TABLE_CONFIG, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_RX_FAST_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &US_CPU_RX_FAST_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &LOCAL_SWITCHING_MULTICAST_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_RATE_CONTROLLER_EXPONENT_TABLE", 1, PRIVATE_B_INDEX, &US_RATE_CONTROLLER_EXPONENT_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_IH_BUFFER_VECTOR_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_ANY_SRC_PORT_FLOW_COUNTER", 1, PRIVATE_B_INDEX, &US_ANY_SRC_PORT_FLOW_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_MEMLIB_SEMAPHORE", 1, PRIVATE_B_INDEX, &US_MEMLIB_SEMAPHORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_TX_POST_HOST_DATA_PTR_BUFFER", 1, PRIVATE_B_INDEX, &US_DHD_TX_POST_HOST_DATA_PTR_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "ETHWAN2_RX_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &ETHWAN2_RX_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_RUNNER_CONGESTION_STATE", 1, PRIVATE_B_INDEX, &US_RUNNER_CONGESTION_STATE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "WAN_ENQUEUE_INGRESS_QUEUE_PTR", 1, PRIVATE_B_INDEX, &WAN_ENQUEUE_INGRESS_QUEUE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_PTR", 1, PRIVATE_B_INDEX, &US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_BPM_CONGESTION_UG3_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER", 1, PRIVATE_B_INDEX, &US_DHD_BPM_CONGESTION_ALLOC_FAIL_DROP_COUNTER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR", 1, PRIVATE_B_INDEX, &US_PICO_FREE_SKB_INDEXES_FIFO_LOCAL_TABLE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_FC_ACCEL_MODE", 1, PRIVATE_B_INDEX, &US_FC_ACCEL_MODE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "ETHWAN2_SWITCH_PORT", 1, PRIVATE_B_INDEX, &ETHWAN2_SWITCH_PORT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR", 1, PRIVATE_B_INDEX, &US_INGRESS_CLASSIFICATION_RULE_CFG_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PACKET_BUFFER_SIZE_ASR_8", 1, PRIVATE_B_INDEX, &US_PACKET_BUFFER_SIZE_ASR_8, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_MAIN_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_B_INDEX, &US_MAIN_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_DMA_SYNCRONIZATION_ADDRESS", 1, PRIVATE_B_INDEX, &US_PICO_DMA_SYNCRONIZATION_ADDRESS, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_RUNNER_FLOW_IH_RESPONSE_MUTEX", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_IH_RESPONSE_MUTEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DSL_BUFFER_ALIGNMENT", 1, PRIVATE_B_INDEX, &DSL_BUFFER_ALIGNMENT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PARALLEL_PROCESSING_SLAVE_VECTOR", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_SLAVE_VECTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE", 1, PRIVATE_B_INDEX, &US_PARALLEL_PROCESSING_CONTEXT_CACHE_MODE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_FAST_MALLOC_RESULT_MUTEX", 1, PRIVATE_B_INDEX, &US_FAST_MALLOC_RESULT_MUTEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_PICO_MALLOC_RESULT_MUTEX", 1, PRIVATE_B_INDEX, &US_PICO_MALLOC_RESULT_MUTEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_RX_FPM_ALLOC_RESULT_MUTEX", 1, PRIVATE_B_INDEX, &DHD_RX_FPM_ALLOC_RESULT_MUTEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_RX_SBPM_TO_FPM_COPY_SEMAPHORE", 1, PRIVATE_B_INDEX, &US_RX_SBPM_TO_FPM_COPY_SEMAPHORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_FW_MAC_ADDRS_COUNT", 1, PRIVATE_B_INDEX, &US_FW_MAC_ADDRS_COUNT, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_DMA_SYNCHRONIZATION", 1, PRIVATE_B_INDEX, &US_DHD_DMA_SYNCHRONIZATION, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_TX_FAST_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_TX_FAST_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_TX_PICO_QUEUE", 1, PRIVATE_B_INDEX, &US_CPU_TX_PICO_QUEUE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "US_RUNNER_FLOW_IH_RESPONSE", 1, PRIVATE_B_INDEX, &US_RUNNER_FLOW_IH_RESPONSE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "ETH2_RX_DESCRIPTORS", 1, PRIVATE_B_INDEX, &ETH2_RX_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined WL4908
	{ "ETH1_RX_DESCRIPTORS", 1, PRIVATE_B_INDEX, &ETH1_RX_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined WL4908
	{ "ETH0_RX_DESCRIPTORS", 1, PRIVATE_B_INDEX, &ETH0_RX_DESCRIPTORS, 32, 1, 1 },
#endif
#if defined WL4908
	{ "BBH_TX_WAN_CHANNEL_INDEX", 1, PRIVATE_B_INDEX, &BBH_TX_WAN_CHANNEL_INDEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_RX_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &CPU_RX_RUNNER_A_SCRATCHPAD, 16, 1, 1 },
#endif
#if defined WL4908
	{ "SERVICE_QUEUES_DDR_CACHE_FIFO", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DDR_CACHE_FIFO, 256, 1, 1 },
#endif
#if defined WL4908
	{ "FC_MCAST_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &FC_MCAST_RUNNER_A_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD", 1, COMMON_A_INDEX, &DS_RX_SBPM_TO_FPM_COPY_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_RUNNER_A_SCRATCHPAD", 1, COMMON_A_INDEX, &WLAN_MCAST_RUNNER_A_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_MAINA_BASE", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_MAINA_BASE, 128, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_DHD_STATION_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_DHD_STATION_TABLE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE", 1, COMMON_A_INDEX, &DS_CPU_REASON_TO_CPU_RX_QUEUE_TABLE, 2, 64, 1 },
#endif
#if defined WL4908
	{ "DHD_RADIO_INSTANCE_COMMON_A_DATA", 1, COMMON_A_INDEX, &DHD_RADIO_INSTANCE_COMMON_A_DATA, 3, 1, 1 },
#endif
#if defined WL4908
	{ "DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_FREE_SKB_INDEXES_FIFO_TABLE_LAST_ENTRY, 1, 1, 1 },
#endif
#if defined WL4908
	{ "FREE_SKB_INDEXES_DDR_FIFO_TAIL", 1, COMMON_A_INDEX, &FREE_SKB_INDEXES_DDR_FIFO_TAIL, 2, 1, 1 },
#endif
#if defined WL4908
	{ "BPM_REPLY_RUNNER_A", 1, COMMON_A_INDEX, &BPM_REPLY_RUNNER_A, 1, 1, 1 },
#endif
#if defined WL4908
	{ "RATE_SHAPERS_STATUS_DESCRIPTOR", 1, COMMON_A_INDEX, &RATE_SHAPERS_STATUS_DESCRIPTOR, 128, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_MAINA_CURR_OFFSET", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_MAINA_CURR_OFFSET, 2, 1, 1 },
#endif
#if defined WL4908
	{ "GPON_SKB_ENQUEUED_INDEXES_FIFO", 1, COMMON_A_INDEX, &GPON_SKB_ENQUEUED_INDEXES_FIFO, 32, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_FWD_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_FWD_TABLE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_PICOA_BASE", 1, COMMON_A_INDEX, &RUNNER_FWTRACE_PICOA_BASE, 128, 1, 1 },
#endif
#if defined WL4908
	{ "SERVICE_QUEUES_DESCRIPTOR_TABLE", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DESCRIPTOR_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_SSID_MAC_ADDRESS_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_SSID_MAC_ADDRESS_TABLE, 48, 1, 1 },
#endif
#if defined WL4908
	{ "INTERRUPT_COALESCING_CONFIG_TABLE", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_CONFIG_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "GLOBAL_DSCP_TO_PBITS_DEI_TABLE", 1, COMMON_A_INDEX, &GLOBAL_DSCP_TO_PBITS_DEI_TABLE, 1, 64, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_SSID_STATS_TABLE", 1, COMMON_A_INDEX, &WLAN_MCAST_SSID_STATS_TABLE, 48, 1, 1 },
#endif
#if defined WL4908
	{ "TRACE_C_TABLE", 1, COMMON_A_INDEX, &TRACE_C_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "SERVICE_QUEUES_CFG", 1, COMMON_A_INDEX, &SERVICE_QUEUES_CFG, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE", 1, COMMON_A_INDEX, &DDR_ADDRESS_FOR_SKB_DATA_POINTERS_TABLE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RATE_CONTROLLER_EXPONENT_TABLE", 1, COMMON_A_INDEX, &DS_RATE_CONTROLLER_EXPONENT_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "INTERRUPT_COALESCING_TIMER_PERIOD", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_TIMER_PERIOD, 1, 1, 1 },
#endif
#if defined WL4908
	{ "INTERRUPT_COALESCING_TIMER_ARMED", 1, COMMON_A_INDEX, &INTERRUPT_COALESCING_TIMER_ARMED, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_FLOW_RING_CACHE_LKP_TABLE", 1, COMMON_A_INDEX, &DS_DHD_FLOW_RING_CACHE_LKP_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "PM_COUNTERS_BUFFER", 1, COMMON_A_INDEX, &PM_COUNTERS_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_CONNECTION_BUFFER_TABLE", 1, COMMON_A_INDEX, &DS_CONNECTION_BUFFER_TABLE, 5, 4, 1 },
#endif
#if defined WL4908
	{ "DS_L4_DST_PORT_TABLE", 1, COMMON_A_INDEX, &DS_L4_DST_PORT_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "L4_DST_PORT_CONTEXT_TABLE", 1, COMMON_A_INDEX, &L4_DST_PORT_CONTEXT_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_FLOW_RING_SHADOW_WR_PTR_TABLE", 1, COMMON_A_INDEX, &DHD_FLOW_RING_SHADOW_WR_PTR_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER", 1, COMMON_A_INDEX, &DS_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_POST_BUFFERS_THRESHOLD", 1, COMMON_A_INDEX, &DHD_TX_POST_BUFFERS_THRESHOLD, 2, 1, 1 },
#endif
#if defined WL4908
	{ "COMMON_A_DUMMY_STORE", 1, COMMON_A_INDEX, &COMMON_A_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "FC_SERVICE_QUEUE_MODE", 1, COMMON_A_INDEX, &FC_SERVICE_QUEUE_MODE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_POST_BUFFERS_IN_USE_COUNTER", 1, COMMON_A_INDEX, &DHD_TX_POST_BUFFERS_IN_USE_COUNTER, 2, 1, 1 },
#endif
#if defined WL4908
	{ "PM_COUNTERS", 1, COMMON_A_INDEX, &PM_COUNTERS, 1, 1, 1 },
#endif
#if defined WL4908
	{ "SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE", 1, COMMON_A_INDEX, &SERVICE_QUEUES_DDR_QUEUE_ADDRESS_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "ETHWAN2_RX_INGRESS_QUEUE", 1, COMMON_A_INDEX, &ETHWAN2_RX_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_RING_PACKET_DESCRIPTORS_CACHE", 1, COMMON_A_INDEX, &DS_RING_PACKET_DESCRIPTORS_CACHE, 14, 1, 1 },
#endif
#if defined WL4908
	{ "RING_DESCRIPTORS_TABLE", 1, COMMON_A_INDEX, &RING_DESCRIPTORS_TABLE, 12, 1, 1 },
#endif
#if defined WL4908
	{ "MAIN_A_DEBUG_TRACE", 1, COMMON_A_INDEX, &MAIN_A_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined WL4908
	{ "PICO_A_DEBUG_TRACE", 1, COMMON_A_INDEX, &PICO_A_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined WL4908
	{ "WAN_TX_QUEUES_TABLE", 1, COMMON_B_INDEX, &WAN_TX_QUEUES_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "US_CONNECTION_BUFFER_TABLE", 1, COMMON_B_INDEX, &US_CONNECTION_BUFFER_TABLE, 5, 4, 1 },
#endif
#if defined WL4908
	{ "IPV6_HOST_ADDRESS_CRC_TABLE", 1, COMMON_B_INDEX, &IPV6_HOST_ADDRESS_CRC_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "EPON_DDR_QUEUE_ADDRESS_TABLE", 1, COMMON_B_INDEX, &EPON_DDR_QUEUE_ADDRESS_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE", 1, COMMON_B_INDEX, &LOCAL_SWITCHING_LAN_ENQUEUE_INGRESS_QUEUE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE", 1, COMMON_B_INDEX, &DS_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_MAINB_BASE", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_MAINB_BASE, 128, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_PICOB_BASE", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_PICOB_BASE, 128, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE", 1, COMMON_B_INDEX, &US_INGRESS_CLASSIFICATION_LOOKUP_CAM_TABLE, 32, 1, 1 },
#endif
#if defined WL4908
	{ "US_L4_DST_PORT_TABLE", 1, COMMON_B_INDEX, &US_L4_DST_PORT_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "WAN_TX_RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &WAN_TX_RUNNER_B_SCRATCHPAD, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE", 1, COMMON_B_INDEX, &DS_INGRESS_CLASSIFICATION_LOOKUP_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "US_INGRESS_CLASSIFICATION_LOOKUP_TABLE", 1, COMMON_B_INDEX, &US_INGRESS_CLASSIFICATION_LOOKUP_TABLE, 256, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_RX_RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &CPU_RX_RUNNER_B_SCRATCHPAD, 16, 1, 1 },
#endif
#if defined WL4908
	{ "EPON_DDR_CACHE_FIFO", 1, COMMON_B_INDEX, &EPON_DDR_CACHE_FIFO, 192, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_FLOW_RING_CACHE_CTX_TABLE", 1, COMMON_B_INDEX, &DHD_FLOW_RING_CACHE_CTX_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "FC_FLOW_IP_ADDRESSES_TABLE", 1, COMMON_B_INDEX, &FC_FLOW_IP_ADDRESSES_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_FWTRACE_MAINB_CURR_OFFSET", 1, COMMON_B_INDEX, &RUNNER_FWTRACE_MAINB_CURR_OFFSET, 2, 1, 1 },
#endif
#if defined WL4908
	{ "BPM_REPLY_RUNNER_B", 1, COMMON_B_INDEX, &BPM_REPLY_RUNNER_B, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_RATE_CONTROLLERS_TABLE", 1, COMMON_B_INDEX, &US_RATE_CONTROLLERS_TABLE, 128, 1, 1 },
#endif
#if defined WL4908
	{ "RUNNER_B_SCRATCHPAD", 1, COMMON_B_INDEX, &RUNNER_B_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_RING_PACKET_DESCRIPTORS_CACHE", 1, COMMON_B_INDEX, &US_RING_PACKET_DESCRIPTORS_CACHE, 14, 1, 1 },
#endif
#if defined WL4908
	{ "IPV4_HOST_ADDRESS_TABLE", 1, COMMON_B_INDEX, &IPV4_HOST_ADDRESS_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_RADIO_INSTANCE_COMMON_B_DATA", 1, COMMON_B_INDEX, &DHD_RADIO_INSTANCE_COMMON_B_DATA, 3, 1, 1 },
#endif
#if defined WL4908
	{ "DUMMY_RATE_CONTROLLER_DESCRIPTOR", 1, COMMON_B_INDEX, &DUMMY_RATE_CONTROLLER_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "MAIN_B_DEBUG_TRACE", 1, COMMON_B_INDEX, &MAIN_B_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined WL4908
	{ "PICO_B_DEBUG_TRACE", 1, COMMON_B_INDEX, &PICO_B_DEBUG_TRACE, 512, 1, 1 },
#endif
#if defined WL4908
	{ "EPON_DDR_QUEUE_DESCRIPTORS_TABLE", 1, COMMON_B_INDEX, &EPON_DDR_QUEUE_DESCRIPTORS_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "GPON_SKB_ENQUEUED_INDEXES_FREE_PTR", 1, COMMON_B_INDEX, &GPON_SKB_ENQUEUED_INDEXES_FREE_PTR, 40, 1, 1 },
#endif
#if defined WL4908
	{ "DUMMY_WAN_TX_QUEUE_DESCRIPTOR", 1, COMMON_B_INDEX, &DUMMY_WAN_TX_QUEUE_DESCRIPTOR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER", 1, COMMON_B_INDEX, &US_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER, 1, 1, 1 },
#endif
#if defined WL4908
	{ "BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE", 1, COMMON_B_INDEX, &BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE", 1, COMMON_B_INDEX, &CPU_TX_DESCRIPTOR_QUEUE_TAIL_TABLE, 4, 1, 1 },
#endif
#if defined WL4908
	{ "BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR", 1, COMMON_B_INDEX, &BRIDGE_PORT_TO_BROADCOM_SWITCH_PORT_MAPPING_TABLE_PTR, 1, 1, 1 },
#endif
#if defined WL4908
	{ "COMMON_B_DUMMY_STORE", 1, COMMON_B_INDEX, &COMMON_B_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX", 1, COMMON_B_INDEX, &DHD_FLOW_RING_CACHE_CTX_NEXT_INDEX, 1, 1, 1 },
#endif
#if defined WL4908
	{ "GPON_SKB_ENQUEUED_INDEXES_PUT_PTR", 1, COMMON_B_INDEX, &GPON_SKB_ENQUEUED_INDEXES_PUT_PTR, 40, 1, 1 },
#endif
#if defined WL4908
	{ "US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD", 1, COMMON_B_INDEX, &US_RX_SBPM_TO_FPM_COPY_SCRATCHPAD, 8, 1, 1 },
#endif
#if defined WL4908
	{ "US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE", 1, COMMON_B_INDEX, &US_CPU_REASON_TO_CPU_RX_QUEUE_TABLE, 2, 64, 1 },
#endif
#if defined WL4908
	{ "PACKET_SRAM_TO_DDR_COPY_BUFFER_1", 1, COMMON_B_INDEX, &PACKET_SRAM_TO_DDR_COPY_BUFFER_1, 1, 1, 1 },
#endif
#if defined WL4908
	{ "PACKET_SRAM_TO_DDR_COPY_BUFFER_2", 1, COMMON_B_INDEX, &PACKET_SRAM_TO_DDR_COPY_BUFFER_2, 1, 1, 1 },
#endif
#if defined WL4908
	{ "LAN0_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN0_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined WL4908
	{ "LAN5_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN5_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined WL4908
	{ "LAN1_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN1_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined WL4908
	{ "LAN6_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN6_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined WL4908
	{ "LAN2_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN2_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined WL4908
	{ "LAN7_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN7_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined WL4908
	{ "LAN3_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN3_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined WL4908
	{ "US_DHD_FLOW_RING_CACHE_LKP_TABLE", 1, COMMON_B_INDEX, &US_DHD_FLOW_RING_CACHE_LKP_TABLE, 16, 1, 1 },
#endif
#if defined WL4908
	{ "LAN4_INGRESS_FIFO", 1, COMMON_B_INDEX, &LAN4_INGRESS_FIFO, 1, 1, 1 },
#endif
#if defined WL4908
	{ "WAN_ENQUEUE_INGRESS_QUEUE", 1, COMMON_B_INDEX, &WAN_ENQUEUE_INGRESS_QUEUE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "BPM_PACKET_BUFFERS", 1, DDR_INDEX, &BPM_PACKET_BUFFERS, 7680, 1, 1 },
#endif
#if defined WL4908
	{ "CONTEXT_TABLE", 1, DDR_INDEX, &CONTEXT_TABLE, 0, 1, 1 },
#endif
#if defined WL4908
	{ "NAT_CACHE_TABLE", 1, DDR_INDEX, &NAT_CACHE_TABLE, 65536, 1, 1 },
#endif
#if defined WL4908
	{ "NAT_CACHE_EXTENSION_TABLE", 1, DDR_INDEX, &NAT_CACHE_EXTENSION_TABLE, 7, 1, 1 },
#endif
#if defined WL4908
	{ "NATC_CONTEXT_TABLE", 1, DDR_INDEX, &NATC_CONTEXT_TABLE, 65536, 1, 1 },
#endif
#if defined WL4908
	{ "CONTEXT_CONTINUATION_TABLE", 1, DDR_INDEX, &CONTEXT_CONTINUATION_TABLE, 65536, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE", 1, DDR_INDEX, &DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_TABLE, 8, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_RX_POST_DDR_BUFFER", 1, DDR_INDEX, &DHD_RX_POST_DDR_BUFFER, 1024, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_RX_COMPLETE_DDR_BUFFER", 1, DDR_INDEX, &DHD_RX_COMPLETE_DDR_BUFFER, 1024, 1, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_POST_DDR_BUFFER", 1, DDR_INDEX, &DHD_TX_POST_DDR_BUFFER, 8, 16, 1 },
#endif
#if defined WL4908
	{ "DHD_TX_COMPLETE_DDR_BUFFER", 1, DDR_INDEX, &DHD_TX_COMPLETE_DDR_BUFFER, 16, 1, 1 },
#endif
#if defined WL4908
	{ "R2D_WR_ARR_DDR_BUFFER", 1, DDR_INDEX, &R2D_WR_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined WL4908
	{ "D2R_RD_ARR_DDR_BUFFER", 1, DDR_INDEX, &D2R_RD_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined WL4908
	{ "R2D_RD_ARR_DDR_BUFFER", 1, DDR_INDEX, &R2D_RD_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined WL4908
	{ "D2R_WR_ARR_DDR_BUFFER", 1, DDR_INDEX, &D2R_WR_ARR_DDR_BUFFER, 128, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_DHD_LIST_TABLE", 1, DDR_INDEX, &WLAN_MCAST_DHD_LIST_TABLE, 64, 1, 1 },
#endif
#if defined WL4908
	{ "WLAN_MCAST_DHD_LIST_FORMAT_TABLE", 1, DDR_INDEX, &WLAN_MCAST_DHD_LIST_FORMAT_TABLE, 1, 1, 1 },
#endif
};
