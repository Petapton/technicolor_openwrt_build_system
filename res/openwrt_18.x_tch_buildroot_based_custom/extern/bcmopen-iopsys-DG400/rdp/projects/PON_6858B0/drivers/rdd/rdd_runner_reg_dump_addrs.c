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
#include "rdd_map_auto.h"
#include "rdd_runner_reg_dump.h"
#include "rdd_runner_reg_dump_addrs.h"
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PD_FIFO_TABLE =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT COMPLEX_SCHEDULER_TABLE =
{
	64,
	{
		{ dump_RDD_COMPLEX_SCHEDULER_DESCRIPTOR, 0x1400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_QUEUE_TABLE =
{
	8,
	{
		{ dump_RDD_SCHEDULING_QUEUE_DESCRIPTOR, 0x1800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TM_FLOW_CNTR_TABLE =
{
	1,
	{
		{ dump_RDD_TM_FLOW_CNTR_ENTRY, 0x1d00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_EGRESS_COUNTER_TABLE =
{
	8,
	{
		{ dump_RDD_BBH_TX_EGRESS_COUNTER_ENTRY, 0x1d80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TM_ACTION_PTR_TABLE =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1dc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BUDGET_ALLOCATION_TIMER_VALUE =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1de2 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BB_DESTINATION_TABLE =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1de4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_GLOBAL_FLUSH_CFG =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1de6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_FLUSH_GLOBAL_CFG =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1de7 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_QUEUE_ID_TABLE =
{
	4,
	{
		{ dump_RDD_BBH_TX_QUEUE_ID_ENTRY, 0x1de8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLUSH_DISPATCHER_CREDIT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1df0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1dfc },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BASIC_SCHEDULER_TABLE =
{
	16,
	{
		{ dump_RDD_BASIC_SCHEDULER_DESCRIPTOR, 0x1e00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BASIC_RATE_LIMITER_TABLE =
{
	16,
	{
		{ dump_RDD_BASIC_RATE_LIMITER_DESCRIPTOR, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x2800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_QUEUE_TABLE =
{
	4,
	{
		{ dump_RDD_BBH_QUEUE_DESCRIPTOR, 0x2a00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2aa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2b20 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT UPDATE_FIFO_TABLE =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x2b40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_FLUSH_VECTOR =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2b60 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_MIRRORING_CONFIGURATION =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0x2b74 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2b76 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_FIFO_SIZE =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2b77 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT MIRRORING_SCRATCH =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2b78 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_QUEUE_AGING_VECTOR =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2b80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FIRST_QUEUE_MAPPING =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2b94 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_AGGREGATION_CONTEXT_VECTOR =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RATE_LIMITER_VALID_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2bc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_MIRRORING_DISPATCHER_CREDIT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2bd0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x2be0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x2c00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_CACHE_CTX_TABLE_1 =
{
	16,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_CTX_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_POST_COMMON_RADIO_DATA_1 =
{
	64,
	{
		{ dump_RDD_DHD_POST_COMMON_RADIO_ENTRY, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_CPU_REASON_TO_METER_TABLE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x3c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_SCRATCHPAD_1 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_1 =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_METER_TABLE_1 =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_1 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT US_CPU_RX_METER_TABLE_1 =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0xa80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RING_INTERRUPT_COUNTER_TABLE_1 =
{
	8,
	{
		{ dump_RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_POOL_NUMBER_MAPPING_TABLE_1 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT US_CPU_REASON_TO_METER_TABLE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_1 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SRAM_PD_FIFO_1 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0xe00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_FLOW_RING_BUFFER_1 =
{
	48,
	{
		{ dump_RDD_DHD_TX_POST_DESCRIPTOR, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_1 =
{
	16,
	{
		{ dump_RDD_CPU_INTERRUPT_COALESCING_ENTRY, 0xf90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DIRECT_PROCESSING_PD_TABLE_1 =
{
	16,
	{
		{ dump_RDD_PROCESSING_RX_DESCRIPTOR, 0xfa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DFT_LIST_ENTRY_SCRATCH_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xfc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_STATION_TABLE_1 =
{
	8,
	{
		{ dump_RDD_WLAN_MCAST_DHD_STATION_ENTRY, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_PD_FIFO_TABLE_1 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x1200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT UPDATE_FIFO_TABLE_1 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x12c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCRATCH_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x12e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_REASON_AND_VPORT_TO_METER_TABLE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_1 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x1378 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_L2_HEADER_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1380 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_1 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x13c8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x13d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_MCAST_DISPATCHER_CREDIT_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x13e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_SCRATCH_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x13ec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x13f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x13fc },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FLOW_RING_CACHE_LKP_TABLE_1 =
{
	2,
	{
		{ dump_RDD_DHD_FLOW_RING_CACHE_LKP_ENTRY, 0x1400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_DOORBELL_VALUE_1 =
{
	4,
	{
		{ dump_RDD_DHD_DOORBELL, 0x1460 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_1 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x146c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_COUNTER_1 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x146e },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_DESCRIPTOR_TABLE_1 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x1470 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_COPY_PD_FIFO_TABLE_1 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x1480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x14c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_UPDATE_FIFO_TABLE_1 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x1540 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_1 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x1560 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_INTERRUPT_COALESCING_TABLE_1 =
{
	16,
	{
		{ dump_RDD_CPU_INTERRUPT_COALESCING_ENTRY, 0x1570 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DFT_LIST_SIZE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_MCAST_UPDATE_FIFO_TABLE_1 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x15c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_1 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x15e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_LOCAL_SCRATCH_1 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x15f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_1 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x1600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_1 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x1630 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DFT_ADDR_1 =
{
	8,
	{
		{ dump_RDD_PHYS_ADDR_64_PTR, 0x1638 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_COPY_UPDATE_FIFO_TABLE_1 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x1640 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_1 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x1660 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x166c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT MAC_TYPE_1 =
{
	1,
	{
		{ dump_RDD_MAC_TYPE_ENTRY, 0x166d },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_1 =
{
	8,
	{
		{ dump_RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY, 0x1670 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_COPY_LOCAL_SCRATCH_1 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x1678 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_1 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x1680 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_SCRATCHPAD_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x16b0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x16b8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PD_FIFO_TABLE_1 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x16c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER_1 =
{
	16,
	{
		{ dump_RDD_DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR, 0x1700 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_MCAST_PD_FIFO_TABLE_1 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x1740 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_REASON_TO_TC_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1760 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_CPU_RXQ_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x17a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT WLAN_MCAST_DHD_STATION_CTX_TABLE_1 =
{
	1,
	{
		{ dump_RDD_WLAN_MCAST_DHD_STATION_CTX_ENTRY, 0x1800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT EXC_TC_TO_CPU_RXQ_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1840 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_CPU_OBJ_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1880 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_HW_CFG_1 =
{
	12,
	{
		{ dump_RDD_DHD_HW_CONFIGURATION, 0x1900 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_SCRATCH_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1980 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SHADOW_RD_IDX_1 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1a00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SHADOW_WR_IDX_1 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1a80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RING_DESCRIPTORS_TABLE_1 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REPORTING_QUEUE_DESCRIPTOR_TABLE_2 =
{
	16,
	{
		{ dump_RDD_REPORTING_QUEUE_DESCRIPTOR, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_2 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0xa00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_FLOW_RING_BUFFER_2 =
{
	16,
	{
		{ dump_RDD_DHD_TX_COMPLETE_DESCRIPTOR, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_2 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0xb70 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REPORTING_QUEUE_ACCUMULATED_TABLE_2 =
{
	8,
	{
		{ dump_RDD_REPORTING_ACCUMULATED_DATA, 0xb80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_TX_SCRATCHPAD_2 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_2 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_COMPLETE_COMMON_RADIO_DATA_2 =
{
	104,
	{
		{ dump_RDD_DHD_COMPLETE_COMMON_RADIO_ENTRY, 0x1200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_2 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x1338 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1340 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GHOST_REPORTING_GLOBAL_CFG_2 =
{
	4,
	{
		{ dump_RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY, 0x1364 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_2 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x1368 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_REPLY_2 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x1370 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_FLOW_RING_BUFFER_2 =
{
	32,
	{
		{ dump_RDD_DHD_RX_COMPLETE_DESCRIPTOR, 0x1380 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x13e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SRAM_PD_FIFO_2 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x1400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REPORTING_COUNTER_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x15a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x15b4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REPORT_BBH_TX_QUEUE_ID_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x15b8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_TX_EGRESS_UPDATE_FIFO_TABLE_2 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x15c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_2 =
{
	16,
	{
		{ dump_RDD_CPU_INTERRUPT_COALESCING_ENTRY, 0x15e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT XGPON_REPORT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x15f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_RX_POST_FLOW_RING_BUFFER_2 =
{
	32,
	{
		{ dump_RDD_DHD_RX_POST_DESCRIPTOR, 0x1600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1660 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x16e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_RX_POST_RING_SIZE_2 =
{
	2,
	{
		{ dump_RDD_DHD_RING_SIZE, 0x16ec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_RING_SIZE_2 =
{
	2,
	{
		{ dump_RDD_DHD_RING_SIZE, 0x16ee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x16f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_TX_COMPLETE_RING_SIZE_2 =
{
	2,
	{
		{ dump_RDD_DHD_RING_SIZE, 0x16fc },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x16fe },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_INGRESS_COUNTER_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x16ff },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_2 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x1700 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_0_DISPATCHER_CREDIT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1730 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_TX_INGRESS_UPDATE_FIFO_TABLE_2 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x1740 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_1_DISPATCHER_CREDIT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1760 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_RX_COMPLETE_2_DISPATCHER_CREDIT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1770 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_2 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x1780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_DOORBELL_VALUE_2 =
{
	4,
	{
		{ dump_RDD_DHD_DOORBELL, 0x17b0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_TX_EGRESS_PD_FIFO_TABLE_2 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x17c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_DESCRIPTOR_TABLE_2 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x17e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_2 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x17f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_TX_INGRESS_PD_FIFO_TABLE_2 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x1800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_2 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x1820 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT XGPON_REPORT_ZERO_SENT_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1830 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_REPLY_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1840 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_2 =
{
	8,
	{
		{ dump_RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY, 0x1858 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_EGRESS_REPORT_COUNTER_TABLE_2 =
{
	8,
	{
		{ dump_RDD_BBH_TX_EGRESS_COUNTER_ENTRY, 0x1860 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_HW_CFG_2 =
{
	12,
	{
		{ dump_RDD_DHD_HW_CONFIGURATION, 0x1880 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_SCRATCH_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1900 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SHADOW_RD_IDX_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1980 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SHADOW_WR_IDX_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1a00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PD_FIFO_TABLE_3 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT COMPLEX_SCHEDULER_TABLE_3 =
{
	64,
	{
		{ dump_RDD_COMPLEX_SCHEDULER_DESCRIPTOR, 0x1400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_QUEUE_TABLE_3 =
{
	8,
	{
		{ dump_RDD_SCHEDULING_QUEUE_DESCRIPTOR, 0x1800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TM_FLOW_CNTR_TABLE_3 =
{
	1,
	{
		{ dump_RDD_TM_FLOW_CNTR_ENTRY, 0x1d00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_EGRESS_COUNTER_TABLE_3 =
{
	8,
	{
		{ dump_RDD_BBH_TX_EGRESS_COUNTER_ENTRY, 0x1d80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_EPON_INGRESS_COUNTER_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x1dc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_QUEUE_ID_TABLE_3 =
{
	4,
	{
		{ dump_RDD_BBH_TX_QUEUE_ID_ENTRY, 0x1de8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT OVERALL_RATE_LIMITER_TABLE_3 =
{
	16,
	{
		{ dump_RDD_OVERALL_RATE_LIMITER_DESCRIPTOR, 0x1df0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BASIC_SCHEDULER_TABLE_3 =
{
	16,
	{
		{ dump_RDD_BASIC_SCHEDULER_DESCRIPTOR, 0x1e00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BASIC_RATE_LIMITER_TABLE_3 =
{
	16,
	{
		{ dump_RDD_BASIC_RATE_LIMITER_DESCRIPTOR, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_3 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x2800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_QUEUE_TABLE_3 =
{
	4,
	{
		{ dump_RDD_BBH_QUEUE_DESCRIPTOR, 0x2a00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2aa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2b20 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_EPON_EGRESS_COUNTER_TABLE_3 =
{
	8,
	{
		{ dump_RDD_BBH_TX_EGRESS_COUNTER_ENTRY, 0x2b40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_EPON_QUEUE_ID_TABLE_3 =
{
	4,
	{
		{ dump_RDD_BBH_TX_QUEUE_ID_ENTRY, 0x2b68 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLUSH_DISPATCHER_CREDIT_TABLE_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2b70 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BUDGET_ALLOCATION_TIMER_VALUE_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2b7c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BB_DESTINATION_TABLE_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2b7e },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TM_ACTION_PTR_TABLE_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2b80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_GLOBAL_FLUSH_CFG_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2ba2 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_FLUSH_GLOBAL_CFG_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2ba3 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ba4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT MIRRORING_SCRATCH_3 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2ba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DISPATCHER_CREDIT_TABLE_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2bb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_MIRRORING_CONFIGURATION_3 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0x2bbc },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2bbe },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BBH_TX_FIFO_SIZE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2bbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT EPON_UPDATE_FIFO_TABLE_3 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x2bc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_FLUSH_VECTOR_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2be0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FIRST_QUEUE_MAPPING_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2bf4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_3 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x2c00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_MIRRORING_DISPATCHER_CREDIT_TABLE_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2c30 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT UPDATE_FIFO_TABLE_3 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x2c40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_QUEUE_AGING_VECTOR_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2c60 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SCHEDULING_AGGREGATION_CONTEXT_VECTOR_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2c80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RATE_LIMITER_VALID_TABLE_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ca0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_3 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x2cb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_4 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_4 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_4 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_4 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_4 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_4 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_4 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_4 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_4 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_4 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_4 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_4 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_4 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_4 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_4 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_4 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_4 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_4 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_4 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_4 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_4 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_4 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_4 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_4 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_4 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_4 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_4 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_4 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_4 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_4 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_4 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_4 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_4 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_5 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_5 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_5 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_5 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_5 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_5 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_5 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_5 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_5 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_5 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_5 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_5 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_5 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_5 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_5 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_5 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_5 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_5 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_5 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_5 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_5 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_5 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_5 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_5 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_5 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_5 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_5 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_5 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_5 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_5 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_5 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_5 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_5 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_6 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_6 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_6 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_6 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_6 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_6 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_6 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_6 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_6 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_6 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_6 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_6 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_6 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_6 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_6 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_6 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_6 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_6 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_6 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_6 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_6 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_6 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_6 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_6 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_6 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_6 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_6 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_6 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_6 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_6 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_6 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_6 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_6 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_6 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_6 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_6 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_6 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_6 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_6 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_6 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_6 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_6 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_6 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_6 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_6 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_6 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_6 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_7 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_7 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_7 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_7 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_7 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_7 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_7 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_7 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_7 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_7 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_7 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_7 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_7 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_7 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_7 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_7 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_7 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_7 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_7 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_7 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_7 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_7 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_7 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_7 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_7 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_7 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_7 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_7 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_7 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_7 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_7 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_7 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_7 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_7 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_7 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_7 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_7 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_7 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_7 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_7 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_7 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_7 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_7 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_7 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_7 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_7 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_7 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_8 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_8 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_8 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_8 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_8 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_8 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_8 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_8 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_8 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_8 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_8 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_8 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_8 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_8 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_8 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_8 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_8 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_8 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_8 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_8 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_8 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_8 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_8 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_8 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_8 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_8 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_8 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_8 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_8 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_8 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_8 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_8 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_8 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_8 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_8 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_8 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_8 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_8 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_8 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_8 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_8 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_8 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_8 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_8 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_8 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_8 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_8 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_9 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_9 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_9 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_9 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_9 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_9 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_9 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_9 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_9 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_9 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_9 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_9 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_9 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_9 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_9 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_9 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_9 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_9 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_9 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_9 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_9 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_9 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_9 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_9 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_9 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_9 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_9 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_9 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_9 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_9 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_9 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_9 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_9 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_9 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_9 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_9 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_9 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_9 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_9 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_9 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_9 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_9 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_9 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_9 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_9 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_9 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_9 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_10 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_10 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_10 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_10 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_10 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_10 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_10 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_10 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_10 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_10 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_10 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_10 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_10 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_10 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_10 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_10 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_10 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_10 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_10 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_10 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_10 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_10 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_10 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_10 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_10 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_10 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_10 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_10 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_10 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_10 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_10 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_10 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_10 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_10 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_10 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_10 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_10 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_10 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_10 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_10 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_10 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_10 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_10 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_10 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_10 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_10 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_10 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_11 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_11 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_11 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_11 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_11 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_11 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_11 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_11 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_11 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_11 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_11 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_11 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_11 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_11 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_11 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_11 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_11 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_11 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_11 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_11 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_11 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_11 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_11 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_11 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_11 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_11 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_11 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_11 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_11 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_11 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_11 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_11 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_11 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_11 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_11 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_11 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_11 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_11 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_11 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_11 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_11 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_11 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_11 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_11 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_11 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_11 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_11 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_12 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_12 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_12 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_12 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_12 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_12 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_12 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_12 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_12 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_12 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_12 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_12 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_12 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_12 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_12 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_12 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_12 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_12 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_12 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_12 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_12 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_12 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_12 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_12 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_12 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_12 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_12 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_12 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_12 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_12 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_12 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_12 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_12 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_12 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_12 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_12 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_12 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_12 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_12 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_12 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_12 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_12 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_12 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_12 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_12 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_12 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_12 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_13 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_13 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_13 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_13 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_13 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_13 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_13 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_13 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_13 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_13 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_13 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_13 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_13 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_13 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_13 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_13 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_13 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_13 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_13 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_13 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_13 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_13 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_13 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_13 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_13 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_13 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_13 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_13 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_13 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_13 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_13 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_13 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_13 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_13 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_13 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_13 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_13 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_13 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_13 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_13 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_13 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_13 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_13 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_13 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_13 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_13 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_13 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_14 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_14 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_14 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_14 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_14 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_14 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_14 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_14 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_14 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_14 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_14 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_14 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_14 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_14 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_14 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_14 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_14 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_14 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_14 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_14 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_14 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_14 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_14 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_14 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_14 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_14 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_14 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_14 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_14 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_14 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_14 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_14 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_14 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_14 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_14 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_14 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_14 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_14 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_14 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_14 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_14 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_14 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_14 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_14 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_14 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_14 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_14 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_15 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_15 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_15 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_15 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_15 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_15 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_15 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_15 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_15 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_15 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_15 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_15 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_15 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_15 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xa08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_15 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0xa88 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_15 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0xa90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_15 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0xa98 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_15 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0xaa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_15 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0xab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_15 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0xae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xaef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_15 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0xaf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xb00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_15 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0xb40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_15 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0xb90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TASK_IDX_15 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xb9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_15 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0xba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_15 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0xba8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_15 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0xbb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_15 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0xbb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbbf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_15 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0xbc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_15 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_LOW_THRESHOLD_15 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DHD_FPM_HIGH_THRESHOLD_15 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xbe8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_15 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0xbea },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_15 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0xbec },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_15 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0xbf0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_15 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0xc00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_15 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_15 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xe80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_15 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_15 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0xf00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_15 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_15 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0xf80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_15 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_15 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_15 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_15 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6858
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_15 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3400 },
		{ 0, 0 },
	}
};
#endif

TABLE_STRUCT RUNNER_TABLES[NUMBER_OF_TABLES] =
{
#if defined BCM6858
	{ "PD_FIFO_TABLE", 1, CORE_0_INDEX, &PD_FIFO_TABLE, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "COMPLEX_SCHEDULER_TABLE", 1, CORE_0_INDEX, &COMPLEX_SCHEDULER_TABLE, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_QUEUE_TABLE", 1, CORE_0_INDEX, &SCHEDULING_QUEUE_TABLE, 160, 1, 1 },
#endif
#if defined BCM6858
	{ "TM_FLOW_CNTR_TABLE", 1, CORE_0_INDEX, &TM_FLOW_CNTR_TABLE, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_EGRESS_COUNTER_TABLE", 1, CORE_0_INDEX, &BBH_TX_EGRESS_COUNTER_TABLE, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "TM_ACTION_PTR_TABLE", 1, CORE_0_INDEX, &TM_ACTION_PTR_TABLE, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "BUDGET_ALLOCATION_TIMER_VALUE", 1, CORE_0_INDEX, &BUDGET_ALLOCATION_TIMER_VALUE, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BB_DESTINATION_TABLE", 1, CORE_0_INDEX, &BB_DESTINATION_TABLE, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_GLOBAL_FLUSH_CFG", 1, CORE_0_INDEX, &SCHEDULING_GLOBAL_FLUSH_CFG, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_FLUSH_GLOBAL_CFG", 1, CORE_0_INDEX, &SCHEDULING_FLUSH_GLOBAL_CFG, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_QUEUE_ID_TABLE", 1, CORE_0_INDEX, &BBH_TX_QUEUE_ID_TABLE, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "FLUSH_DISPATCHER_CREDIT_TABLE", 1, CORE_0_INDEX, &FLUSH_DISPATCHER_CREDIT_TABLE, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_0_INDEX, &TASK_IDX, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BASIC_SCHEDULER_TABLE", 1, CORE_0_INDEX, &BASIC_SCHEDULER_TABLE, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "BASIC_RATE_LIMITER_TABLE", 1, CORE_0_INDEX, &BASIC_RATE_LIMITER_TABLE, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_0_INDEX, &RUNNER_PROFILING_TRACE_BUFFER, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_QUEUE_TABLE", 1, CORE_0_INDEX, &BBH_QUEUE_TABLE, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_0_INDEX, &REGISTERS_BUFFER, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_0_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "UPDATE_FIFO_TABLE", 1, CORE_0_INDEX, &UPDATE_FIFO_TABLE, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_FLUSH_VECTOR", 1, CORE_0_INDEX, &SCHEDULING_FLUSH_VECTOR, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "TX_MIRRORING_CONFIGURATION", 1, CORE_0_INDEX, &TX_MIRRORING_CONFIGURATION, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_0_INDEX, &SRAM_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_FIFO_SIZE", 1, CORE_0_INDEX, &BBH_TX_FIFO_SIZE, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "MIRRORING_SCRATCH", 1, CORE_0_INDEX, &MIRRORING_SCRATCH, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_QUEUE_AGING_VECTOR", 1, CORE_0_INDEX, &SCHEDULING_QUEUE_AGING_VECTOR, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FIRST_QUEUE_MAPPING", 1, CORE_0_INDEX, &FIRST_QUEUE_MAPPING, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_AGGREGATION_CONTEXT_VECTOR", 1, CORE_0_INDEX, &SCHEDULING_AGGREGATION_CONTEXT_VECTOR, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "RATE_LIMITER_VALID_TABLE", 1, CORE_0_INDEX, &RATE_LIMITER_VALID_TABLE, 4, 1, 1 },
#endif
#if defined BCM6858
	{ "TX_MIRRORING_DISPATCHER_CREDIT_TABLE", 1, CORE_0_INDEX, &TX_MIRRORING_DISPATCHER_CREDIT_TABLE, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_0_INDEX, &FPM_GLOBAL_CFG, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_0_INDEX, &NATC_TBL_CFG, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FLOW_RING_CACHE_CTX_TABLE", 1, CORE_1_INDEX, &DHD_FLOW_RING_CACHE_CTX_TABLE_1, 48, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_POST_COMMON_RADIO_DATA", 1, CORE_1_INDEX, &DHD_POST_COMMON_RADIO_DATA_1, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_CPU_REASON_TO_METER_TABLE", 1, CORE_1_INDEX, &DS_CPU_REASON_TO_METER_TABLE_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_SCRATCHPAD", 1, CORE_1_INDEX, &CPU_RX_SCRATCHPAD_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "WLAN_MCAST_SSID_MAC_ADDRESS_TABLE", 1, CORE_1_INDEX, &WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_1, 48, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_CPU_RX_METER_TABLE", 1, CORE_1_INDEX, &DS_CPU_RX_METER_TABLE_1, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_1_INDEX, &RX_FLOW_TABLE_1, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "US_CPU_RX_METER_TABLE", 1, CORE_1_INDEX, &US_CPU_RX_METER_TABLE_1, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RING_INTERRUPT_COUNTER_TABLE", 1, CORE_1_INDEX, &CPU_RING_INTERRUPT_COUNTER_TABLE_1, 18, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_1_INDEX, &DHD_FPM_POOL_NUMBER_MAPPING_TABLE_1, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_1_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_1, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "US_CPU_REASON_TO_METER_TABLE", 1, CORE_1_INDEX, &US_CPU_REASON_TO_METER_TABLE_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_1_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_1, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_SRAM_PD_FIFO", 1, CORE_1_INDEX, &CPU_RECYCLE_SRAM_PD_FIFO_1, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_TX_POST_FLOW_RING_BUFFER", 1, CORE_1_INDEX, &DHD_TX_POST_FLOW_RING_BUFFER_1, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_INTERRUPT_COALESCING_TABLE", 1, CORE_1_INDEX, &CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DIRECT_PROCESSING_PD_TABLE", 1, CORE_1_INDEX, &DIRECT_PROCESSING_PD_TABLE_1, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "WLAN_MCAST_DFT_LIST_ENTRY_SCRATCH", 1, CORE_1_INDEX, &WLAN_MCAST_DFT_LIST_ENTRY_SCRATCH_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "WLAN_MCAST_DHD_STATION_TABLE", 1, CORE_1_INDEX, &WLAN_MCAST_DHD_STATION_TABLE_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_TX_POST_PD_FIFO_TABLE", 1, CORE_1_INDEX, &DHD_TX_POST_PD_FIFO_TABLE_1, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "UPDATE_FIFO_TABLE", 1, CORE_1_INDEX, &UPDATE_FIFO_TABLE_1, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "SCRATCH", 1, CORE_1_INDEX, &SCRATCH_1, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_REASON_AND_VPORT_TO_METER_TABLE", 1, CORE_1_INDEX, &CPU_REASON_AND_VPORT_TO_METER_TABLE_1, 120, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR", 1, CORE_1_INDEX, &CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_L2_HEADER", 1, CORE_1_INDEX, &DHD_L2_HEADER_1, 72, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_1_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD", 1, CORE_1_INDEX, &CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_1, 4, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_MCAST_DISPATCHER_CREDIT_TABLE", 1, CORE_1_INDEX, &DHD_MCAST_DISPATCHER_CREDIT_TABLE_1, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_SCRATCH", 1, CORE_1_INDEX, &CPU_RX_INTERRUPT_SCRATCH_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_COPY_DISPATCHER_CREDIT_TABLE", 1, CORE_1_INDEX, &CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_1, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_1_INDEX, &TASK_IDX_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FLOW_RING_CACHE_LKP_TABLE", 1, CORE_1_INDEX, &DHD_FLOW_RING_CACHE_LKP_TABLE_1, 48, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_DOORBELL_VALUE", 1, CORE_1_INDEX, &DHD_DOORBELL_VALUE_1, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_1_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_COUNTER", 1, CORE_1_INDEX, &CPU_FEED_RING_INTERRUPT_COUNTER_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_RING_DESCRIPTOR_TABLE", 1, CORE_1_INDEX, &CPU_RECYCLE_RING_DESCRIPTOR_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_COPY_PD_FIFO_TABLE", 1, CORE_1_INDEX, &CPU_RX_COPY_PD_FIFO_TABLE_1, 4, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_1_INDEX, &REGISTERS_BUFFER_1, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_TX_POST_UPDATE_FIFO_TABLE", 1, CORE_1_INDEX, &DHD_TX_POST_UPDATE_FIFO_TABLE_1, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE", 1, CORE_1_INDEX, &CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_1, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_INTERRUPT_COALESCING_TABLE", 1, CORE_1_INDEX, &CPU_INTERRUPT_COALESCING_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "WLAN_MCAST_DFT_LIST_SIZE", 1, CORE_1_INDEX, &WLAN_MCAST_DFT_LIST_SIZE_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_MCAST_UPDATE_FIFO_TABLE", 1, CORE_1_INDEX, &DHD_MCAST_UPDATE_FIFO_TABLE_1, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_1_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_LOCAL_SCRATCH", 1, CORE_1_INDEX, &CPU_RX_LOCAL_SCRATCH_1, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_1_INDEX, &NATC_TBL_CFG_1, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR", 1, CORE_1_INDEX, &DHD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "WLAN_MCAST_DFT_ADDR", 1, CORE_1_INDEX, &WLAN_MCAST_DFT_ADDR_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_COPY_UPDATE_FIFO_TABLE", 1, CORE_1_INDEX, &CPU_RX_COPY_UPDATE_FIFO_TABLE_1, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_1_INDEX, &FPM_GLOBAL_CFG_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_1_INDEX, &SRAM_DUMMY_STORE_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "MAC_TYPE", 1, CORE_1_INDEX, &MAC_TYPE_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE", 1, CORE_1_INDEX, &CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_COPY_LOCAL_SCRATCH", 1, CORE_1_INDEX, &CPU_RX_COPY_LOCAL_SCRATCH_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE", 1, CORE_1_INDEX, &DHD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_1, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "WLAN_MCAST_SCRATCHPAD", 1, CORE_1_INDEX, &WLAN_MCAST_SCRATCHPAD_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DIRECT_PROCESSING_EPON_CONTROL_SCRATCH", 1, CORE_1_INDEX, &DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PD_FIFO_TABLE", 1, CORE_1_INDEX, &PD_FIFO_TABLE_1, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER", 1, CORE_1_INDEX, &DHD_TX_POST_FLOW_RING_MGMT_DESCRIPTOR_BUFFER_1, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_MCAST_PD_FIFO_TABLE", 1, CORE_1_INDEX, &DHD_MCAST_PD_FIFO_TABLE_1, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_REASON_TO_TC", 1, CORE_1_INDEX, &CPU_REASON_TO_TC_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_CPU_RXQ", 1, CORE_1_INDEX, &TC_TO_CPU_RXQ_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "WLAN_MCAST_DHD_STATION_CTX_TABLE", 1, CORE_1_INDEX, &WLAN_MCAST_DHD_STATION_CTX_TABLE_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "EXC_TC_TO_CPU_RXQ", 1, CORE_1_INDEX, &EXC_TC_TO_CPU_RXQ_1, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_CPU_OBJ", 1, CORE_1_INDEX, &VPORT_TO_CPU_OBJ_1, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_HW_CFG", 1, CORE_1_INDEX, &DHD_HW_CFG_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_INTERRUPT_SCRATCH", 1, CORE_1_INDEX, &CPU_RECYCLE_INTERRUPT_SCRATCH_1, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_SHADOW_RD_IDX", 1, CORE_1_INDEX, &CPU_RECYCLE_SHADOW_RD_IDX_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_SHADOW_WR_IDX", 1, CORE_1_INDEX, &CPU_RECYCLE_SHADOW_WR_IDX_1, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RING_DESCRIPTORS_TABLE", 1, CORE_1_INDEX, &CPU_RING_DESCRIPTORS_TABLE_1, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "REPORTING_QUEUE_DESCRIPTOR_TABLE", 1, CORE_2_INDEX, &REPORTING_QUEUE_DESCRIPTOR_TABLE_2, 160, 1, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_2_INDEX, &TX_FLOW_TABLE_2, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_TX_COMPLETE_FLOW_RING_BUFFER", 1, CORE_2_INDEX, &DHD_TX_COMPLETE_FLOW_RING_BUFFER_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_2_INDEX, &CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_2, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "REPORTING_QUEUE_ACCUMULATED_TABLE", 1, CORE_2_INDEX, &REPORTING_QUEUE_ACCUMULATED_TABLE_2, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_TX_SCRATCHPAD", 1, CORE_2_INDEX, &CPU_TX_SCRATCHPAD_2, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_2_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_2, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_COMPLETE_COMMON_RADIO_DATA", 1, CORE_2_INDEX, &DHD_COMPLETE_COMMON_RADIO_DATA_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR", 1, CORE_2_INDEX, &CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_2_INDEX, &QUEUE_THRESHOLD_VECTOR_2, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "GHOST_REPORTING_GLOBAL_CFG", 1, CORE_2_INDEX, &GHOST_REPORTING_GLOBAL_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR", 1, CORE_2_INDEX, &DHD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_REPLY", 1, CORE_2_INDEX, &FPM_REPLY_2, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_RX_COMPLETE_FLOW_RING_BUFFER", 1, CORE_2_INDEX, &DHD_RX_COMPLETE_FLOW_RING_BUFFER_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_2_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_2, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_SRAM_PD_FIFO", 1, CORE_2_INDEX, &CPU_RECYCLE_SRAM_PD_FIFO_2, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "REPORTING_COUNTER_TABLE", 1, CORE_2_INDEX, &REPORTING_COUNTER_TABLE_2, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE", 1, CORE_2_INDEX, &GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_2, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_2_INDEX, &TASK_IDX_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "REPORT_BBH_TX_QUEUE_ID_TABLE", 1, CORE_2_INDEX, &REPORT_BBH_TX_QUEUE_ID_TABLE_2, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_TX_EGRESS_UPDATE_FIFO_TABLE", 1, CORE_2_INDEX, &CPU_TX_EGRESS_UPDATE_FIFO_TABLE_2, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_INTERRUPT_COALESCING_TABLE", 1, CORE_2_INDEX, &CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "XGPON_REPORT_TABLE", 1, CORE_2_INDEX, &XGPON_REPORT_TABLE_2, 4, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_RX_POST_FLOW_RING_BUFFER", 1, CORE_2_INDEX, &DHD_RX_POST_FLOW_RING_BUFFER_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_2_INDEX, &REGISTERS_BUFFER_2, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE", 1, CORE_2_INDEX, &CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_RX_POST_RING_SIZE", 1, CORE_2_INDEX, &DHD_RX_POST_RING_SIZE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_RX_COMPLETE_RING_SIZE", 1, CORE_2_INDEX, &DHD_RX_COMPLETE_RING_SIZE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE", 1, CORE_2_INDEX, &CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_TX_COMPLETE_RING_SIZE", 1, CORE_2_INDEX, &DHD_TX_COMPLETE_RING_SIZE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_2_INDEX, &SRAM_DUMMY_STORE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_INGRESS_COUNTER_TABLE", 1, CORE_2_INDEX, &BBH_TX_INGRESS_COUNTER_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_2_INDEX, &NATC_TBL_CFG_2, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_RX_COMPLETE_0_DISPATCHER_CREDIT_TABLE", 1, CORE_2_INDEX, &DHD_RX_COMPLETE_0_DISPATCHER_CREDIT_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_TX_INGRESS_UPDATE_FIFO_TABLE", 1, CORE_2_INDEX, &CPU_TX_INGRESS_UPDATE_FIFO_TABLE_2, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_RX_COMPLETE_1_DISPATCHER_CREDIT_TABLE", 1, CORE_2_INDEX, &DHD_RX_COMPLETE_1_DISPATCHER_CREDIT_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_RX_COMPLETE_2_DISPATCHER_CREDIT_TABLE", 1, CORE_2_INDEX, &DHD_RX_COMPLETE_2_DISPATCHER_CREDIT_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE", 1, CORE_2_INDEX, &DHD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_DOORBELL_VALUE", 1, CORE_2_INDEX, &DHD_DOORBELL_VALUE_2, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_TX_EGRESS_PD_FIFO_TABLE", 1, CORE_2_INDEX, &CPU_TX_EGRESS_PD_FIFO_TABLE_2, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_RING_DESCRIPTOR_TABLE", 1, CORE_2_INDEX, &CPU_RECYCLE_RING_DESCRIPTOR_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE", 1, CORE_2_INDEX, &CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_2, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_TX_INGRESS_PD_FIFO_TABLE", 1, CORE_2_INDEX, &CPU_TX_INGRESS_PD_FIFO_TABLE_2, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_2_INDEX, &FPM_GLOBAL_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "XGPON_REPORT_ZERO_SENT_TABLE", 1, CORE_2_INDEX, &XGPON_REPORT_ZERO_SENT_TABLE_2, 10, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_REPLY", 1, CORE_2_INDEX, &DHD_FPM_REPLY_2, 24, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE", 1, CORE_2_INDEX, &CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_EGRESS_REPORT_COUNTER_TABLE", 1, CORE_2_INDEX, &BBH_TX_EGRESS_REPORT_COUNTER_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_HW_CFG", 1, CORE_2_INDEX, &DHD_HW_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_INTERRUPT_SCRATCH", 1, CORE_2_INDEX, &CPU_RECYCLE_INTERRUPT_SCRATCH_2, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_SHADOW_RD_IDX", 1, CORE_2_INDEX, &CPU_RECYCLE_SHADOW_RD_IDX_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RECYCLE_SHADOW_WR_IDX", 1, CORE_2_INDEX, &CPU_RECYCLE_SHADOW_WR_IDX_2, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PD_FIFO_TABLE", 1, CORE_3_INDEX, &PD_FIFO_TABLE_3, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "COMPLEX_SCHEDULER_TABLE", 1, CORE_3_INDEX, &COMPLEX_SCHEDULER_TABLE_3, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_QUEUE_TABLE", 1, CORE_3_INDEX, &SCHEDULING_QUEUE_TABLE_3, 160, 1, 1 },
#endif
#if defined BCM6858
	{ "TM_FLOW_CNTR_TABLE", 1, CORE_3_INDEX, &TM_FLOW_CNTR_TABLE_3, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_EGRESS_COUNTER_TABLE", 1, CORE_3_INDEX, &BBH_TX_EGRESS_COUNTER_TABLE_3, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_EPON_INGRESS_COUNTER_TABLE", 1, CORE_3_INDEX, &BBH_TX_EPON_INGRESS_COUNTER_TABLE_3, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_QUEUE_ID_TABLE", 1, CORE_3_INDEX, &BBH_TX_QUEUE_ID_TABLE_3, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "OVERALL_RATE_LIMITER_TABLE", 1, CORE_3_INDEX, &OVERALL_RATE_LIMITER_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BASIC_SCHEDULER_TABLE", 1, CORE_3_INDEX, &BASIC_SCHEDULER_TABLE_3, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "BASIC_RATE_LIMITER_TABLE", 1, CORE_3_INDEX, &BASIC_RATE_LIMITER_TABLE_3, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_3_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_3, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_QUEUE_TABLE", 1, CORE_3_INDEX, &BBH_QUEUE_TABLE_3, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_3_INDEX, &REGISTERS_BUFFER_3, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_3_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_3, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_EPON_EGRESS_COUNTER_TABLE", 1, CORE_3_INDEX, &BBH_TX_EPON_EGRESS_COUNTER_TABLE_3, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_EPON_QUEUE_ID_TABLE", 1, CORE_3_INDEX, &BBH_TX_EPON_QUEUE_ID_TABLE_3, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "FLUSH_DISPATCHER_CREDIT_TABLE", 1, CORE_3_INDEX, &FLUSH_DISPATCHER_CREDIT_TABLE_3, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "BUDGET_ALLOCATION_TIMER_VALUE", 1, CORE_3_INDEX, &BUDGET_ALLOCATION_TIMER_VALUE_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BB_DESTINATION_TABLE", 1, CORE_3_INDEX, &BB_DESTINATION_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TM_ACTION_PTR_TABLE", 1, CORE_3_INDEX, &TM_ACTION_PTR_TABLE_3, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_GLOBAL_FLUSH_CFG", 1, CORE_3_INDEX, &SCHEDULING_GLOBAL_FLUSH_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_FLUSH_GLOBAL_CFG", 1, CORE_3_INDEX, &SCHEDULING_FLUSH_GLOBAL_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_3_INDEX, &TASK_IDX_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "MIRRORING_SCRATCH", 1, CORE_3_INDEX, &MIRRORING_SCRATCH_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DISPATCHER_CREDIT_TABLE", 1, CORE_3_INDEX, &DISPATCHER_CREDIT_TABLE_3, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "TX_MIRRORING_CONFIGURATION", 1, CORE_3_INDEX, &TX_MIRRORING_CONFIGURATION_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_3_INDEX, &SRAM_DUMMY_STORE_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BBH_TX_FIFO_SIZE", 1, CORE_3_INDEX, &BBH_TX_FIFO_SIZE_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "EPON_UPDATE_FIFO_TABLE", 1, CORE_3_INDEX, &EPON_UPDATE_FIFO_TABLE_3, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_FLUSH_VECTOR", 1, CORE_3_INDEX, &SCHEDULING_FLUSH_VECTOR_3, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FIRST_QUEUE_MAPPING", 1, CORE_3_INDEX, &FIRST_QUEUE_MAPPING_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_3_INDEX, &NATC_TBL_CFG_3, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "TX_MIRRORING_DISPATCHER_CREDIT_TABLE", 1, CORE_3_INDEX, &TX_MIRRORING_DISPATCHER_CREDIT_TABLE_3, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "UPDATE_FIFO_TABLE", 1, CORE_3_INDEX, &UPDATE_FIFO_TABLE_3, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_QUEUE_AGING_VECTOR", 1, CORE_3_INDEX, &SCHEDULING_QUEUE_AGING_VECTOR_3, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "SCHEDULING_AGGREGATION_CONTEXT_VECTOR", 1, CORE_3_INDEX, &SCHEDULING_AGGREGATION_CONTEXT_VECTOR_3, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "RATE_LIMITER_VALID_TABLE", 1, CORE_3_INDEX, &RATE_LIMITER_VALID_TABLE_3, 4, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_3_INDEX, &FPM_GLOBAL_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_4_INDEX, &RX_FLOW_TABLE_4, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_4_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_4, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_4_INDEX, &IPTV_CONFIGURATION_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_4_INDEX, &DSCP_TO_PBITS_MAP_TABLE_4, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_4_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_4, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_4_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_4, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_4_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_4, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_4_INDEX, &VPORT_CFG_TABLE_4, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_4_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_4, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_4_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_4, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_4_INDEX, &INGRESS_FILTER_PROFILE_TABLE_4, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_4_INDEX, &POLICER_PARAMS_TABLE_4, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_4_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_4, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_4_INDEX, &TCAM_IC_HANDLER_TABLE_4, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_4_INDEX, &LAYER2_GRE_TUNNEL_TABLE_4, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_4_INDEX, &PBIT_TO_GEM_TABLE_4, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_4_INDEX, &DUAL_STACK_LITE_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_4_INDEX, &TC_TO_QUEUE_TABLE_4, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_4_INDEX, &REGISTERS_BUFFER_4, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_4_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_4_INDEX, &NULL_BUFFER_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_4_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_4_INDEX, &BRIDGE_CFG_TABLE_4, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_4_INDEX, &DEFAULT_BRIDGE_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_4_INDEX, &LOOPBACK_QUEUE_TABLE_4, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_4_INDEX, &SYSTEM_CONFIGURATION_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_4_INDEX, &FORCE_DSCP_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_4_INDEX, &CORE_ID_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_4_INDEX, &SRAM_DUMMY_STORE_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_4_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_4_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_4, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_4_INDEX, &TCAM_IC_CFG_TABLE_4, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_4_INDEX, &FPM_GLOBAL_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_4_INDEX, &TASK_IDX_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_4_INDEX, &TUNNELS_PARSING_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_4_INDEX, &IPTV_CFG_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_4_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_4_INDEX, &NAT_CACHE_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_4_INDEX, &IC_DEBUG_COUNTER_MODE_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_4_INDEX, &QUEUE_THRESHOLD_VECTOR_4, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_4_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_4_INDEX, &DHD_FPM_LOW_THRESHOLD_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_4_INDEX, &DHD_FPM_HIGH_THRESHOLD_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_4_INDEX, &RX_MIRRORING_CONFIGURATION_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_4_INDEX, &INGRESS_FILTER_1588_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_4_INDEX, &INGRESS_FILTER_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_4_INDEX, &PBIT_TO_QUEUE_TABLE_4, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_4_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_4_INDEX, &RULE_BASED_ACTION_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_4_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_4_INDEX, &NATC_TBL_CFG_4, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_4_INDEX, &IPTV_ACTION_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_4_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_4_INDEX, &DS_PACKET_BUFFER_4, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_4_INDEX, &IC_EXT_CONTEXT_TABLE_4, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_4_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_4, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_4_INDEX, &TCAM_IC_CMD_TABLE_4, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_4_INDEX, &TX_FLOW_TABLE_4, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_5_INDEX, &RX_FLOW_TABLE_5, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_5_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_5, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_5_INDEX, &IPTV_CONFIGURATION_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_5_INDEX, &DSCP_TO_PBITS_MAP_TABLE_5, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_5_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_5, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_5_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_5, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_5_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_5, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_5_INDEX, &VPORT_CFG_TABLE_5, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_5_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_5, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_5_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_5, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_5_INDEX, &INGRESS_FILTER_PROFILE_TABLE_5, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_5_INDEX, &POLICER_PARAMS_TABLE_5, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_5_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_5, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_5_INDEX, &TCAM_IC_HANDLER_TABLE_5, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_5_INDEX, &LAYER2_GRE_TUNNEL_TABLE_5, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_5_INDEX, &PBIT_TO_GEM_TABLE_5, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_5_INDEX, &DUAL_STACK_LITE_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_5_INDEX, &TC_TO_QUEUE_TABLE_5, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_5_INDEX, &REGISTERS_BUFFER_5, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_5_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_5_INDEX, &NULL_BUFFER_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_5_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_5_INDEX, &BRIDGE_CFG_TABLE_5, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_5_INDEX, &DEFAULT_BRIDGE_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_5_INDEX, &LOOPBACK_QUEUE_TABLE_5, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_5_INDEX, &SYSTEM_CONFIGURATION_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_5_INDEX, &FORCE_DSCP_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_5_INDEX, &CORE_ID_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_5_INDEX, &SRAM_DUMMY_STORE_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_5_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_5_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_5, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_5_INDEX, &TCAM_IC_CFG_TABLE_5, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_5_INDEX, &FPM_GLOBAL_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_5_INDEX, &TASK_IDX_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_5_INDEX, &TUNNELS_PARSING_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_5_INDEX, &IPTV_CFG_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_5_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_5_INDEX, &NAT_CACHE_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_5_INDEX, &IC_DEBUG_COUNTER_MODE_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_5_INDEX, &QUEUE_THRESHOLD_VECTOR_5, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_5_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_5_INDEX, &DHD_FPM_LOW_THRESHOLD_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_5_INDEX, &DHD_FPM_HIGH_THRESHOLD_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_5_INDEX, &RX_MIRRORING_CONFIGURATION_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_5_INDEX, &INGRESS_FILTER_1588_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_5_INDEX, &INGRESS_FILTER_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_5_INDEX, &PBIT_TO_QUEUE_TABLE_5, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_5_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_5_INDEX, &RULE_BASED_ACTION_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_5_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_5_INDEX, &NATC_TBL_CFG_5, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_5_INDEX, &IPTV_ACTION_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_5_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_5_INDEX, &DS_PACKET_BUFFER_5, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_5_INDEX, &IC_EXT_CONTEXT_TABLE_5, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_5_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_5, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_5_INDEX, &TCAM_IC_CMD_TABLE_5, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_5_INDEX, &TX_FLOW_TABLE_5, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_6_INDEX, &RX_FLOW_TABLE_6, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_6_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_6, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_6_INDEX, &IPTV_CONFIGURATION_TABLE_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_6_INDEX, &DSCP_TO_PBITS_MAP_TABLE_6, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_6_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_6, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_6_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_6, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_6_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_6, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_6_INDEX, &VPORT_CFG_TABLE_6, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_6_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_6, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_6_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_6, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_6_INDEX, &INGRESS_FILTER_PROFILE_TABLE_6, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_6_INDEX, &POLICER_PARAMS_TABLE_6, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_6_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_6, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_6_INDEX, &TCAM_IC_HANDLER_TABLE_6, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_6_INDEX, &LAYER2_GRE_TUNNEL_TABLE_6, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_6_INDEX, &PBIT_TO_GEM_TABLE_6, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_6_INDEX, &DUAL_STACK_LITE_TABLE_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_6_INDEX, &TC_TO_QUEUE_TABLE_6, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_6_INDEX, &REGISTERS_BUFFER_6, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_6_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_6_INDEX, &NULL_BUFFER_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_6_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_6_INDEX, &BRIDGE_CFG_TABLE_6, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_6_INDEX, &DEFAULT_BRIDGE_CFG_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_6_INDEX, &LOOPBACK_QUEUE_TABLE_6, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_6_INDEX, &SYSTEM_CONFIGURATION_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_6_INDEX, &FORCE_DSCP_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_6_INDEX, &CORE_ID_TABLE_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_6_INDEX, &SRAM_DUMMY_STORE_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_6_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_6_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_6, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_6_INDEX, &TCAM_IC_CFG_TABLE_6, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_6_INDEX, &FPM_GLOBAL_CFG_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_6_INDEX, &TASK_IDX_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_6_INDEX, &TUNNELS_PARSING_CFG_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_6_INDEX, &IPTV_CFG_TABLE_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_6_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_6_INDEX, &NAT_CACHE_CFG_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_6_INDEX, &IC_DEBUG_COUNTER_MODE_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_6_INDEX, &QUEUE_THRESHOLD_VECTOR_6, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_6_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_6_INDEX, &DHD_FPM_LOW_THRESHOLD_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_6_INDEX, &DHD_FPM_HIGH_THRESHOLD_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_6_INDEX, &RX_MIRRORING_CONFIGURATION_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_6_INDEX, &INGRESS_FILTER_1588_CFG_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_6_INDEX, &INGRESS_FILTER_CFG_6, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_6_INDEX, &PBIT_TO_QUEUE_TABLE_6, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_6_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_6, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_6_INDEX, &RULE_BASED_ACTION_PTR_TABLE_6, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_6_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_6, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_6_INDEX, &NATC_TBL_CFG_6, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_6_INDEX, &IPTV_ACTION_PTR_TABLE_6, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_6_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_6, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_6_INDEX, &DS_PACKET_BUFFER_6, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_6_INDEX, &IC_EXT_CONTEXT_TABLE_6, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_6_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_6, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_6_INDEX, &TCAM_IC_CMD_TABLE_6, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_6_INDEX, &TX_FLOW_TABLE_6, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_7_INDEX, &RX_FLOW_TABLE_7, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_7_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_7, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_7_INDEX, &IPTV_CONFIGURATION_TABLE_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_7_INDEX, &DSCP_TO_PBITS_MAP_TABLE_7, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_7_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_7, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_7_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_7, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_7_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_7, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_7_INDEX, &VPORT_CFG_TABLE_7, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_7_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_7, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_7_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_7, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_7_INDEX, &INGRESS_FILTER_PROFILE_TABLE_7, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_7_INDEX, &POLICER_PARAMS_TABLE_7, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_7_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_7, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_7_INDEX, &TCAM_IC_HANDLER_TABLE_7, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_7_INDEX, &LAYER2_GRE_TUNNEL_TABLE_7, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_7_INDEX, &PBIT_TO_GEM_TABLE_7, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_7_INDEX, &DUAL_STACK_LITE_TABLE_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_7_INDEX, &TC_TO_QUEUE_TABLE_7, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_7_INDEX, &REGISTERS_BUFFER_7, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_7_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_7_INDEX, &NULL_BUFFER_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_7_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_7_INDEX, &BRIDGE_CFG_TABLE_7, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_7_INDEX, &DEFAULT_BRIDGE_CFG_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_7_INDEX, &LOOPBACK_QUEUE_TABLE_7, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_7_INDEX, &SYSTEM_CONFIGURATION_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_7_INDEX, &FORCE_DSCP_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_7_INDEX, &CORE_ID_TABLE_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_7_INDEX, &SRAM_DUMMY_STORE_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_7_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_7_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_7, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_7_INDEX, &TCAM_IC_CFG_TABLE_7, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_7_INDEX, &FPM_GLOBAL_CFG_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_7_INDEX, &TASK_IDX_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_7_INDEX, &TUNNELS_PARSING_CFG_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_7_INDEX, &IPTV_CFG_TABLE_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_7_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_7_INDEX, &NAT_CACHE_CFG_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_7_INDEX, &IC_DEBUG_COUNTER_MODE_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_7_INDEX, &QUEUE_THRESHOLD_VECTOR_7, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_7_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_7_INDEX, &DHD_FPM_LOW_THRESHOLD_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_7_INDEX, &DHD_FPM_HIGH_THRESHOLD_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_7_INDEX, &RX_MIRRORING_CONFIGURATION_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_7_INDEX, &INGRESS_FILTER_1588_CFG_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_7_INDEX, &INGRESS_FILTER_CFG_7, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_7_INDEX, &PBIT_TO_QUEUE_TABLE_7, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_7_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_7, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_7_INDEX, &RULE_BASED_ACTION_PTR_TABLE_7, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_7_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_7, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_7_INDEX, &NATC_TBL_CFG_7, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_7_INDEX, &IPTV_ACTION_PTR_TABLE_7, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_7_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_7, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_7_INDEX, &DS_PACKET_BUFFER_7, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_7_INDEX, &IC_EXT_CONTEXT_TABLE_7, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_7_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_7, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_7_INDEX, &TCAM_IC_CMD_TABLE_7, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_7_INDEX, &TX_FLOW_TABLE_7, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_8_INDEX, &RX_FLOW_TABLE_8, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_8_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_8, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_8_INDEX, &IPTV_CONFIGURATION_TABLE_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_8_INDEX, &DSCP_TO_PBITS_MAP_TABLE_8, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_8_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_8, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_8_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_8, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_8_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_8, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_8_INDEX, &VPORT_CFG_TABLE_8, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_8_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_8, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_8_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_8, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_8_INDEX, &INGRESS_FILTER_PROFILE_TABLE_8, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_8_INDEX, &POLICER_PARAMS_TABLE_8, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_8_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_8, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_8_INDEX, &TCAM_IC_HANDLER_TABLE_8, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_8_INDEX, &LAYER2_GRE_TUNNEL_TABLE_8, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_8_INDEX, &PBIT_TO_GEM_TABLE_8, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_8_INDEX, &DUAL_STACK_LITE_TABLE_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_8_INDEX, &TC_TO_QUEUE_TABLE_8, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_8_INDEX, &REGISTERS_BUFFER_8, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_8_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_8_INDEX, &NULL_BUFFER_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_8_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_8_INDEX, &BRIDGE_CFG_TABLE_8, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_8_INDEX, &DEFAULT_BRIDGE_CFG_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_8_INDEX, &LOOPBACK_QUEUE_TABLE_8, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_8_INDEX, &SYSTEM_CONFIGURATION_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_8_INDEX, &FORCE_DSCP_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_8_INDEX, &CORE_ID_TABLE_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_8_INDEX, &SRAM_DUMMY_STORE_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_8_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_8_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_8, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_8_INDEX, &TCAM_IC_CFG_TABLE_8, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_8_INDEX, &FPM_GLOBAL_CFG_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_8_INDEX, &TASK_IDX_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_8_INDEX, &TUNNELS_PARSING_CFG_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_8_INDEX, &IPTV_CFG_TABLE_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_8_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_8_INDEX, &NAT_CACHE_CFG_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_8_INDEX, &IC_DEBUG_COUNTER_MODE_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_8_INDEX, &QUEUE_THRESHOLD_VECTOR_8, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_8_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_8_INDEX, &DHD_FPM_LOW_THRESHOLD_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_8_INDEX, &DHD_FPM_HIGH_THRESHOLD_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_8_INDEX, &RX_MIRRORING_CONFIGURATION_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_8_INDEX, &INGRESS_FILTER_1588_CFG_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_8_INDEX, &INGRESS_FILTER_CFG_8, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_8_INDEX, &PBIT_TO_QUEUE_TABLE_8, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_8_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_8, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_8_INDEX, &RULE_BASED_ACTION_PTR_TABLE_8, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_8_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_8, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_8_INDEX, &NATC_TBL_CFG_8, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_8_INDEX, &IPTV_ACTION_PTR_TABLE_8, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_8_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_8, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_8_INDEX, &DS_PACKET_BUFFER_8, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_8_INDEX, &IC_EXT_CONTEXT_TABLE_8, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_8_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_8, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_8_INDEX, &TCAM_IC_CMD_TABLE_8, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_8_INDEX, &TX_FLOW_TABLE_8, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_9_INDEX, &RX_FLOW_TABLE_9, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_9_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_9, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_9_INDEX, &IPTV_CONFIGURATION_TABLE_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_9_INDEX, &DSCP_TO_PBITS_MAP_TABLE_9, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_9_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_9, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_9_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_9, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_9_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_9, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_9_INDEX, &VPORT_CFG_TABLE_9, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_9_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_9, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_9_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_9, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_9_INDEX, &INGRESS_FILTER_PROFILE_TABLE_9, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_9_INDEX, &POLICER_PARAMS_TABLE_9, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_9_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_9, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_9_INDEX, &TCAM_IC_HANDLER_TABLE_9, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_9_INDEX, &LAYER2_GRE_TUNNEL_TABLE_9, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_9_INDEX, &PBIT_TO_GEM_TABLE_9, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_9_INDEX, &DUAL_STACK_LITE_TABLE_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_9_INDEX, &TC_TO_QUEUE_TABLE_9, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_9_INDEX, &REGISTERS_BUFFER_9, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_9_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_9_INDEX, &NULL_BUFFER_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_9_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_9_INDEX, &BRIDGE_CFG_TABLE_9, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_9_INDEX, &DEFAULT_BRIDGE_CFG_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_9_INDEX, &LOOPBACK_QUEUE_TABLE_9, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_9_INDEX, &SYSTEM_CONFIGURATION_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_9_INDEX, &FORCE_DSCP_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_9_INDEX, &CORE_ID_TABLE_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_9_INDEX, &SRAM_DUMMY_STORE_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_9_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_9_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_9, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_9_INDEX, &TCAM_IC_CFG_TABLE_9, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_9_INDEX, &FPM_GLOBAL_CFG_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_9_INDEX, &TASK_IDX_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_9_INDEX, &TUNNELS_PARSING_CFG_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_9_INDEX, &IPTV_CFG_TABLE_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_9_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_9_INDEX, &NAT_CACHE_CFG_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_9_INDEX, &IC_DEBUG_COUNTER_MODE_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_9_INDEX, &QUEUE_THRESHOLD_VECTOR_9, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_9_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_9_INDEX, &DHD_FPM_LOW_THRESHOLD_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_9_INDEX, &DHD_FPM_HIGH_THRESHOLD_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_9_INDEX, &RX_MIRRORING_CONFIGURATION_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_9_INDEX, &INGRESS_FILTER_1588_CFG_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_9_INDEX, &INGRESS_FILTER_CFG_9, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_9_INDEX, &PBIT_TO_QUEUE_TABLE_9, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_9_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_9, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_9_INDEX, &RULE_BASED_ACTION_PTR_TABLE_9, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_9_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_9, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_9_INDEX, &NATC_TBL_CFG_9, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_9_INDEX, &IPTV_ACTION_PTR_TABLE_9, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_9_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_9, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_9_INDEX, &DS_PACKET_BUFFER_9, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_9_INDEX, &IC_EXT_CONTEXT_TABLE_9, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_9_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_9, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_9_INDEX, &TCAM_IC_CMD_TABLE_9, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_9_INDEX, &TX_FLOW_TABLE_9, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_10_INDEX, &RX_FLOW_TABLE_10, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_10_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_10, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_10_INDEX, &IPTV_CONFIGURATION_TABLE_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_10_INDEX, &DSCP_TO_PBITS_MAP_TABLE_10, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_10_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_10, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_10_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_10, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_10_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_10, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_10_INDEX, &VPORT_CFG_TABLE_10, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_10_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_10, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_10_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_10, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_10_INDEX, &INGRESS_FILTER_PROFILE_TABLE_10, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_10_INDEX, &POLICER_PARAMS_TABLE_10, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_10_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_10, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_10_INDEX, &TCAM_IC_HANDLER_TABLE_10, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_10_INDEX, &LAYER2_GRE_TUNNEL_TABLE_10, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_10_INDEX, &PBIT_TO_GEM_TABLE_10, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_10_INDEX, &DUAL_STACK_LITE_TABLE_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_10_INDEX, &TC_TO_QUEUE_TABLE_10, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_10_INDEX, &REGISTERS_BUFFER_10, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_10_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_10_INDEX, &NULL_BUFFER_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_10_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_10_INDEX, &BRIDGE_CFG_TABLE_10, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_10_INDEX, &DEFAULT_BRIDGE_CFG_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_10_INDEX, &LOOPBACK_QUEUE_TABLE_10, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_10_INDEX, &SYSTEM_CONFIGURATION_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_10_INDEX, &FORCE_DSCP_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_10_INDEX, &CORE_ID_TABLE_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_10_INDEX, &SRAM_DUMMY_STORE_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_10_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_10_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_10, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_10_INDEX, &TCAM_IC_CFG_TABLE_10, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_10_INDEX, &FPM_GLOBAL_CFG_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_10_INDEX, &TASK_IDX_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_10_INDEX, &TUNNELS_PARSING_CFG_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_10_INDEX, &IPTV_CFG_TABLE_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_10_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_10_INDEX, &NAT_CACHE_CFG_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_10_INDEX, &IC_DEBUG_COUNTER_MODE_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_10_INDEX, &QUEUE_THRESHOLD_VECTOR_10, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_10_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_10_INDEX, &DHD_FPM_LOW_THRESHOLD_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_10_INDEX, &DHD_FPM_HIGH_THRESHOLD_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_10_INDEX, &RX_MIRRORING_CONFIGURATION_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_10_INDEX, &INGRESS_FILTER_1588_CFG_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_10_INDEX, &INGRESS_FILTER_CFG_10, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_10_INDEX, &PBIT_TO_QUEUE_TABLE_10, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_10_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_10, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_10_INDEX, &RULE_BASED_ACTION_PTR_TABLE_10, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_10_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_10, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_10_INDEX, &NATC_TBL_CFG_10, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_10_INDEX, &IPTV_ACTION_PTR_TABLE_10, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_10_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_10, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_10_INDEX, &DS_PACKET_BUFFER_10, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_10_INDEX, &IC_EXT_CONTEXT_TABLE_10, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_10_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_10, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_10_INDEX, &TCAM_IC_CMD_TABLE_10, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_10_INDEX, &TX_FLOW_TABLE_10, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_11_INDEX, &RX_FLOW_TABLE_11, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_11_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_11, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_11_INDEX, &IPTV_CONFIGURATION_TABLE_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_11_INDEX, &DSCP_TO_PBITS_MAP_TABLE_11, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_11_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_11, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_11_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_11, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_11_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_11, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_11_INDEX, &VPORT_CFG_TABLE_11, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_11_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_11, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_11_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_11, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_11_INDEX, &INGRESS_FILTER_PROFILE_TABLE_11, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_11_INDEX, &POLICER_PARAMS_TABLE_11, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_11_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_11, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_11_INDEX, &TCAM_IC_HANDLER_TABLE_11, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_11_INDEX, &LAYER2_GRE_TUNNEL_TABLE_11, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_11_INDEX, &PBIT_TO_GEM_TABLE_11, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_11_INDEX, &DUAL_STACK_LITE_TABLE_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_11_INDEX, &TC_TO_QUEUE_TABLE_11, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_11_INDEX, &REGISTERS_BUFFER_11, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_11_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_11_INDEX, &NULL_BUFFER_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_11_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_11_INDEX, &BRIDGE_CFG_TABLE_11, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_11_INDEX, &DEFAULT_BRIDGE_CFG_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_11_INDEX, &LOOPBACK_QUEUE_TABLE_11, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_11_INDEX, &SYSTEM_CONFIGURATION_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_11_INDEX, &FORCE_DSCP_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_11_INDEX, &CORE_ID_TABLE_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_11_INDEX, &SRAM_DUMMY_STORE_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_11_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_11_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_11, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_11_INDEX, &TCAM_IC_CFG_TABLE_11, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_11_INDEX, &FPM_GLOBAL_CFG_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_11_INDEX, &TASK_IDX_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_11_INDEX, &TUNNELS_PARSING_CFG_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_11_INDEX, &IPTV_CFG_TABLE_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_11_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_11_INDEX, &NAT_CACHE_CFG_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_11_INDEX, &IC_DEBUG_COUNTER_MODE_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_11_INDEX, &QUEUE_THRESHOLD_VECTOR_11, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_11_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_11_INDEX, &DHD_FPM_LOW_THRESHOLD_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_11_INDEX, &DHD_FPM_HIGH_THRESHOLD_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_11_INDEX, &RX_MIRRORING_CONFIGURATION_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_11_INDEX, &INGRESS_FILTER_1588_CFG_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_11_INDEX, &INGRESS_FILTER_CFG_11, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_11_INDEX, &PBIT_TO_QUEUE_TABLE_11, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_11_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_11, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_11_INDEX, &RULE_BASED_ACTION_PTR_TABLE_11, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_11_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_11, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_11_INDEX, &NATC_TBL_CFG_11, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_11_INDEX, &IPTV_ACTION_PTR_TABLE_11, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_11_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_11, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_11_INDEX, &DS_PACKET_BUFFER_11, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_11_INDEX, &IC_EXT_CONTEXT_TABLE_11, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_11_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_11, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_11_INDEX, &TCAM_IC_CMD_TABLE_11, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_11_INDEX, &TX_FLOW_TABLE_11, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_12_INDEX, &RX_FLOW_TABLE_12, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_12_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_12, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_12_INDEX, &IPTV_CONFIGURATION_TABLE_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_12_INDEX, &DSCP_TO_PBITS_MAP_TABLE_12, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_12_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_12, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_12_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_12, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_12_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_12, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_12_INDEX, &VPORT_CFG_TABLE_12, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_12_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_12, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_12_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_12, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_12_INDEX, &INGRESS_FILTER_PROFILE_TABLE_12, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_12_INDEX, &POLICER_PARAMS_TABLE_12, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_12_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_12, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_12_INDEX, &TCAM_IC_HANDLER_TABLE_12, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_12_INDEX, &LAYER2_GRE_TUNNEL_TABLE_12, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_12_INDEX, &PBIT_TO_GEM_TABLE_12, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_12_INDEX, &DUAL_STACK_LITE_TABLE_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_12_INDEX, &TC_TO_QUEUE_TABLE_12, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_12_INDEX, &REGISTERS_BUFFER_12, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_12_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_12_INDEX, &NULL_BUFFER_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_12_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_12_INDEX, &BRIDGE_CFG_TABLE_12, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_12_INDEX, &DEFAULT_BRIDGE_CFG_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_12_INDEX, &LOOPBACK_QUEUE_TABLE_12, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_12_INDEX, &SYSTEM_CONFIGURATION_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_12_INDEX, &FORCE_DSCP_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_12_INDEX, &CORE_ID_TABLE_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_12_INDEX, &SRAM_DUMMY_STORE_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_12_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_12_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_12, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_12_INDEX, &TCAM_IC_CFG_TABLE_12, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_12_INDEX, &FPM_GLOBAL_CFG_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_12_INDEX, &TASK_IDX_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_12_INDEX, &TUNNELS_PARSING_CFG_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_12_INDEX, &IPTV_CFG_TABLE_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_12_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_12_INDEX, &NAT_CACHE_CFG_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_12_INDEX, &IC_DEBUG_COUNTER_MODE_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_12_INDEX, &QUEUE_THRESHOLD_VECTOR_12, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_12_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_12_INDEX, &DHD_FPM_LOW_THRESHOLD_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_12_INDEX, &DHD_FPM_HIGH_THRESHOLD_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_12_INDEX, &RX_MIRRORING_CONFIGURATION_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_12_INDEX, &INGRESS_FILTER_1588_CFG_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_12_INDEX, &INGRESS_FILTER_CFG_12, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_12_INDEX, &PBIT_TO_QUEUE_TABLE_12, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_12_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_12, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_12_INDEX, &RULE_BASED_ACTION_PTR_TABLE_12, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_12_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_12, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_12_INDEX, &NATC_TBL_CFG_12, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_12_INDEX, &IPTV_ACTION_PTR_TABLE_12, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_12_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_12, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_12_INDEX, &DS_PACKET_BUFFER_12, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_12_INDEX, &IC_EXT_CONTEXT_TABLE_12, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_12_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_12, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_12_INDEX, &TCAM_IC_CMD_TABLE_12, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_12_INDEX, &TX_FLOW_TABLE_12, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_13_INDEX, &RX_FLOW_TABLE_13, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_13_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_13, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_13_INDEX, &IPTV_CONFIGURATION_TABLE_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_13_INDEX, &DSCP_TO_PBITS_MAP_TABLE_13, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_13_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_13, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_13_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_13, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_13_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_13, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_13_INDEX, &VPORT_CFG_TABLE_13, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_13_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_13, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_13_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_13, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_13_INDEX, &INGRESS_FILTER_PROFILE_TABLE_13, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_13_INDEX, &POLICER_PARAMS_TABLE_13, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_13_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_13, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_13_INDEX, &TCAM_IC_HANDLER_TABLE_13, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_13_INDEX, &LAYER2_GRE_TUNNEL_TABLE_13, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_13_INDEX, &PBIT_TO_GEM_TABLE_13, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_13_INDEX, &DUAL_STACK_LITE_TABLE_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_13_INDEX, &TC_TO_QUEUE_TABLE_13, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_13_INDEX, &REGISTERS_BUFFER_13, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_13_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_13_INDEX, &NULL_BUFFER_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_13_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_13_INDEX, &BRIDGE_CFG_TABLE_13, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_13_INDEX, &DEFAULT_BRIDGE_CFG_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_13_INDEX, &LOOPBACK_QUEUE_TABLE_13, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_13_INDEX, &SYSTEM_CONFIGURATION_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_13_INDEX, &FORCE_DSCP_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_13_INDEX, &CORE_ID_TABLE_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_13_INDEX, &SRAM_DUMMY_STORE_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_13_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_13_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_13, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_13_INDEX, &TCAM_IC_CFG_TABLE_13, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_13_INDEX, &FPM_GLOBAL_CFG_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_13_INDEX, &TASK_IDX_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_13_INDEX, &TUNNELS_PARSING_CFG_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_13_INDEX, &IPTV_CFG_TABLE_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_13_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_13_INDEX, &NAT_CACHE_CFG_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_13_INDEX, &IC_DEBUG_COUNTER_MODE_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_13_INDEX, &QUEUE_THRESHOLD_VECTOR_13, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_13_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_13_INDEX, &DHD_FPM_LOW_THRESHOLD_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_13_INDEX, &DHD_FPM_HIGH_THRESHOLD_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_13_INDEX, &RX_MIRRORING_CONFIGURATION_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_13_INDEX, &INGRESS_FILTER_1588_CFG_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_13_INDEX, &INGRESS_FILTER_CFG_13, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_13_INDEX, &PBIT_TO_QUEUE_TABLE_13, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_13_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_13, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_13_INDEX, &RULE_BASED_ACTION_PTR_TABLE_13, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_13_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_13, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_13_INDEX, &NATC_TBL_CFG_13, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_13_INDEX, &IPTV_ACTION_PTR_TABLE_13, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_13_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_13, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_13_INDEX, &DS_PACKET_BUFFER_13, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_13_INDEX, &IC_EXT_CONTEXT_TABLE_13, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_13_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_13, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_13_INDEX, &TCAM_IC_CMD_TABLE_13, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_13_INDEX, &TX_FLOW_TABLE_13, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_14_INDEX, &RX_FLOW_TABLE_14, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_14_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_14, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_14_INDEX, &IPTV_CONFIGURATION_TABLE_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_14_INDEX, &DSCP_TO_PBITS_MAP_TABLE_14, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_14_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_14, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_14_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_14, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_14_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_14, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_14_INDEX, &VPORT_CFG_TABLE_14, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_14_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_14, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_14_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_14, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_14_INDEX, &INGRESS_FILTER_PROFILE_TABLE_14, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_14_INDEX, &POLICER_PARAMS_TABLE_14, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_14_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_14, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_14_INDEX, &TCAM_IC_HANDLER_TABLE_14, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_14_INDEX, &LAYER2_GRE_TUNNEL_TABLE_14, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_14_INDEX, &PBIT_TO_GEM_TABLE_14, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_14_INDEX, &DUAL_STACK_LITE_TABLE_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_14_INDEX, &TC_TO_QUEUE_TABLE_14, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_14_INDEX, &REGISTERS_BUFFER_14, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_14_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_14_INDEX, &NULL_BUFFER_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_14_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_14_INDEX, &BRIDGE_CFG_TABLE_14, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_14_INDEX, &DEFAULT_BRIDGE_CFG_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_14_INDEX, &LOOPBACK_QUEUE_TABLE_14, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_14_INDEX, &SYSTEM_CONFIGURATION_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_14_INDEX, &FORCE_DSCP_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_14_INDEX, &CORE_ID_TABLE_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_14_INDEX, &SRAM_DUMMY_STORE_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_14_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_14_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_14, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_14_INDEX, &TCAM_IC_CFG_TABLE_14, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_14_INDEX, &FPM_GLOBAL_CFG_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_14_INDEX, &TASK_IDX_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_14_INDEX, &TUNNELS_PARSING_CFG_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_14_INDEX, &IPTV_CFG_TABLE_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_14_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_14_INDEX, &NAT_CACHE_CFG_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_14_INDEX, &IC_DEBUG_COUNTER_MODE_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_14_INDEX, &QUEUE_THRESHOLD_VECTOR_14, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_14_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_14_INDEX, &DHD_FPM_LOW_THRESHOLD_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_14_INDEX, &DHD_FPM_HIGH_THRESHOLD_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_14_INDEX, &RX_MIRRORING_CONFIGURATION_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_14_INDEX, &INGRESS_FILTER_1588_CFG_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_14_INDEX, &INGRESS_FILTER_CFG_14, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_14_INDEX, &PBIT_TO_QUEUE_TABLE_14, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_14_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_14, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_14_INDEX, &RULE_BASED_ACTION_PTR_TABLE_14, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_14_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_14, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_14_INDEX, &NATC_TBL_CFG_14, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_14_INDEX, &IPTV_ACTION_PTR_TABLE_14, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_14_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_14, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_14_INDEX, &DS_PACKET_BUFFER_14, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_14_INDEX, &IC_EXT_CONTEXT_TABLE_14, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_14_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_14, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_14_INDEX, &TCAM_IC_CMD_TABLE_14, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_14_INDEX, &TX_FLOW_TABLE_14, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_TABLE", 1, CORE_15_INDEX, &RX_FLOW_TABLE_15, 320, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_15_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_15, 30, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_15_INDEX, &IPTV_CONFIGURATION_TABLE_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_15_INDEX, &DSCP_TO_PBITS_MAP_TABLE_15, 4, 64, 1 },
#endif
#if defined BCM6858
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_15_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_15, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_15_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_15, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_15_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_15, 1, 64, 1 },
#endif
#if defined BCM6858
	{ "VPORT_CFG_TABLE", 1, CORE_15_INDEX, &VPORT_CFG_TABLE_15, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_15_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_15, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_15_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_15, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_15_INDEX, &INGRESS_FILTER_PROFILE_TABLE_15, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "POLICER_PARAMS_TABLE", 1, CORE_15_INDEX, &POLICER_PARAMS_TABLE_15, 80, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_15_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_15, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_15_INDEX, &TCAM_IC_HANDLER_TABLE_15, 16, 1, 1 },
#endif
#if defined BCM6858
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_15_INDEX, &LAYER2_GRE_TUNNEL_TABLE_15, 12, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_GEM_TABLE", 1, CORE_15_INDEX, &PBIT_TO_GEM_TABLE_15, 8, 8, 1 },
#endif
#if defined BCM6858
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_15_INDEX, &DUAL_STACK_LITE_TABLE_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TC_TO_QUEUE_TABLE", 1, CORE_15_INDEX, &TC_TO_QUEUE_TABLE_15, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "REGISTERS_BUFFER", 1, CORE_15_INDEX, &REGISTERS_BUFFER_15, 32, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_15_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NULL_BUFFER", 1, CORE_15_INDEX, &NULL_BUFFER_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_15_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "BRIDGE_CFG_TABLE", 1, CORE_15_INDEX, &BRIDGE_CFG_TABLE_15, 3, 1, 1 },
#endif
#if defined BCM6858
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_15_INDEX, &DEFAULT_BRIDGE_CFG_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_15_INDEX, &LOOPBACK_QUEUE_TABLE_15, 40, 1, 1 },
#endif
#if defined BCM6858
	{ "SYSTEM_CONFIGURATION", 1, CORE_15_INDEX, &SYSTEM_CONFIGURATION_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "FORCE_DSCP", 1, CORE_15_INDEX, &FORCE_DSCP_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CORE_ID_TABLE", 1, CORE_15_INDEX, &CORE_ID_TABLE_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "SRAM_DUMMY_STORE", 1, CORE_15_INDEX, &SRAM_DUMMY_STORE_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_15_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_15_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_15, 64, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CFG_TABLE", 1, CORE_15_INDEX, &TCAM_IC_CFG_TABLE_15, 5, 1, 1 },
#endif
#if defined BCM6858
	{ "FPM_GLOBAL_CFG", 1, CORE_15_INDEX, &FPM_GLOBAL_CFG_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TASK_IDX", 1, CORE_15_INDEX, &TASK_IDX_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "TUNNELS_PARSING_CFG", 1, CORE_15_INDEX, &TUNNELS_PARSING_CFG_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_CFG_TABLE", 1, CORE_15_INDEX, &IPTV_CFG_TABLE_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_15_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "NAT_CACHE_CFG", 1, CORE_15_INDEX, &NAT_CACHE_CFG_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_15_INDEX, &IC_DEBUG_COUNTER_MODE_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_15_INDEX, &QUEUE_THRESHOLD_VECTOR_15, 9, 1, 1 },
#endif
#if defined BCM6858
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_15_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_LOW_THRESHOLD", 1, CORE_15_INDEX, &DHD_FPM_LOW_THRESHOLD_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "DHD_FPM_HIGH_THRESHOLD", 1, CORE_15_INDEX, &DHD_FPM_HIGH_THRESHOLD_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_15_INDEX, &RX_MIRRORING_CONFIGURATION_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_15_INDEX, &INGRESS_FILTER_1588_CFG_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "INGRESS_FILTER_CFG", 1, CORE_15_INDEX, &INGRESS_FILTER_CFG_15, 1, 1, 1 },
#endif
#if defined BCM6858
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_15_INDEX, &PBIT_TO_QUEUE_TABLE_15, 65, 1, 1 },
#endif
#if defined BCM6858
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_15_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_15, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_15_INDEX, &RULE_BASED_ACTION_PTR_TABLE_15, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_15_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_15, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "NATC_TBL_CFG", 1, CORE_15_INDEX, &NATC_TBL_CFG_15, 2, 1, 1 },
#endif
#if defined BCM6858
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_15_INDEX, &IPTV_ACTION_PTR_TABLE_15, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_15_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_15, 17, 1, 1 },
#endif
#if defined BCM6858
	{ "DS_PACKET_BUFFER", 1, CORE_15_INDEX, &DS_PACKET_BUFFER_15, 8, 1, 1 },
#endif
#if defined BCM6858
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_15_INDEX, &IC_EXT_CONTEXT_TABLE_15, 1024, 1, 1 },
#endif
#if defined BCM6858
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_15_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_15, 128, 1, 1 },
#endif
#if defined BCM6858
	{ "TCAM_IC_CMD_TABLE", 1, CORE_15_INDEX, &TCAM_IC_CMD_TABLE_15, 6, 16, 1 },
#endif
#if defined BCM6858
	{ "TX_FLOW_TABLE", 1, CORE_15_INDEX, &TX_FLOW_TABLE_15, 320, 1, 1 },
#endif
};
