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
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PD_FIFO_TABLE =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT COMPLEX_SCHEDULER_TABLE =
{
	64,
	{
		{ dump_RDD_COMPLEX_SCHEDULER_DESCRIPTOR, 0x1400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_QUEUE_TABLE =
{
	8,
	{
		{ dump_RDD_SCHEDULING_QUEUE_DESCRIPTOR, 0x1800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TM_FLOW_CNTR_TABLE =
{
	1,
	{
		{ dump_RDD_TM_FLOW_CNTR_ENTRY, 0x1d00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_EGRESS_COUNTER_TABLE =
{
	8,
	{
		{ dump_RDD_BBH_TX_EGRESS_COUNTER_ENTRY, 0x1d80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TM_ACTION_PTR_TABLE =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1dc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BUDGET_ALLOCATION_TIMER_VALUE =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1de2 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BB_DESTINATION_TABLE =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1de4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_COUNTER_MAX =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x1de6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x1de8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FLUSH_DISPATCHER_CREDIT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1df0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TASK_IDX =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1dfc },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BASIC_SCHEDULER_TABLE =
{
	16,
	{
		{ dump_RDD_BASIC_SCHEDULER_DESCRIPTOR, 0x1e00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BASIC_RATE_LIMITER_TABLE =
{
	16,
	{
		{ dump_RDD_BASIC_RATE_LIMITER_DESCRIPTOR, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x2800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2a80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x2b00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TX_MIRRORING_DISPATCHER_CREDIT_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2b30 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_GLOBAL_FLUSH_CFG =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2b3c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_FLUSH_GLOBAL_CFG =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2b3d },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2b3e },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2b40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DIRECT_PROCESSING_PD_TABLE =
{
	16,
	{
		{ dump_RDD_PROCESSING_RX_DESCRIPTOR, 0x2b60 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT UPDATE_FIFO_TABLE =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x2b80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_FLUSH_VECTOR =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ba0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TX_MIRRORING_CONFIGURATION =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0x2bb4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2bb6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT MAC_TYPE =
{
	1,
	{
		{ dump_RDD_MAC_TYPE_ENTRY, 0x2bb7 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_QUEUE_ID_TABLE =
{
	4,
	{
		{ dump_RDD_BBH_TX_QUEUE_ID_ENTRY, 0x2bb8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_QUEUE_AGING_VECTOR =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2bc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_FIFO_SIZE =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2bd4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FIRST_QUEUE_MAPPING =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2bd5 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT MIRRORING_SCRATCH =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2bd8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_AGGREGATION_CONTEXT_VECTOR =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2be0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DIRECT_PROCESSING_EPON_CONTROL_SCRATCH =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2bf8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x2c00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_QUEUE_TABLE =
{
	4,
	{
		{ dump_RDD_BBH_QUEUE_DESCRIPTOR, 0x2e00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCRATCH =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ea0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RATE_LIMITER_VALID_TABLE =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x2ed0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x2ee0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PD_FIFO_TABLE_1 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT COMPLEX_SCHEDULER_TABLE_1 =
{
	64,
	{
		{ dump_RDD_COMPLEX_SCHEDULER_DESCRIPTOR, 0x1400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_QUEUE_TABLE_1 =
{
	8,
	{
		{ dump_RDD_SCHEDULING_QUEUE_DESCRIPTOR, 0x1800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REPORTING_COUNTER_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1d00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x1da0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_EGRESS_COUNTER_TABLE_1 =
{
	8,
	{
		{ dump_RDD_BBH_TX_EGRESS_COUNTER_ENTRY, 0x1dc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BASIC_SCHEDULER_TABLE_1 =
{
	16,
	{
		{ dump_RDD_BASIC_SCHEDULER_DESCRIPTOR, 0x1e00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REPORTING_QUEUE_DESCRIPTOR_TABLE_1 =
{
	16,
	{
		{ dump_RDD_REPORTING_QUEUE_DESCRIPTOR, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_QUEUE_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BBH_QUEUE_DESCRIPTOR, 0x2a00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_FLUSH_VECTOR_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2aa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT GHOST_REPORTING_GLOBAL_CFG_1 =
{
	4,
	{
		{ dump_RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY, 0x2ab4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_QUEUE_ID_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BBH_TX_QUEUE_ID_ENTRY, 0x2ab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_EPON_INGRESS_COUNTER_TABLE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2ac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_EPON_QUEUE_ID_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BBH_TX_QUEUE_ID_ENTRY, 0x2ae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT XGPON_REPORT_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2af0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TM_FLOW_CNTR_TABLE_1 =
{
	1,
	{
		{ dump_RDD_TM_FLOW_CNTR_ENTRY, 0x2b00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REPORTING_QUEUE_ACCUMULATED_TABLE_1 =
{
	8,
	{
		{ dump_RDD_REPORTING_ACCUMULATED_DATA, 0x2b80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_1 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x2c00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2e00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_EPON_EGRESS_COUNTER_TABLE_1 =
{
	8,
	{
		{ dump_RDD_BBH_TX_EGRESS_COUNTER_ENTRY, 0x2e80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT MIRRORING_SCRATCH_1 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2ea8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT OVERALL_RATE_LIMITER_TABLE_1 =
{
	16,
	{
		{ dump_RDD_OVERALL_RATE_LIMITER_DESCRIPTOR, 0x2eb0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TM_ACTION_PTR_TABLE_1 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2ec0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BUDGET_ALLOCATION_TIMER_VALUE_1 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2ee2 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BB_DESTINATION_TABLE_1 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2ee4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_GLOBAL_FLUSH_CFG_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2ee6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_FLUSH_GLOBAL_CFG_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2ee7 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REPORT_BBH_TX_QUEUE_ID_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ee8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FLUSH_DISPATCHER_CREDIT_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ef0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TASK_IDX_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2efc },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_1 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x2f00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DISPATCHER_CREDIT_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2f30 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TX_MIRRORING_CONFIGURATION_1 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0x2f3c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2f3e },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_FIFO_SIZE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2f3f },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT EPON_UPDATE_FIFO_TABLE_1 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x2f40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_QUEUE_AGING_VECTOR_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2f60 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FIRST_QUEUE_MAPPING_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2f74 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_INGRESS_COUNTER_TABLE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2f75 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BBH_TX_EGRESS_REPORT_COUNTER_TABLE_1 =
{
	8,
	{
		{ dump_RDD_BBH_TX_EGRESS_COUNTER_ENTRY, 0x2f78 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT UPDATE_FIFO_TABLE_1 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x2f80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SCHEDULING_AGGREGATION_CONTEXT_VECTOR_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2fa0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2fc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RATE_LIMITER_VALID_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2fe0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TX_MIRRORING_DISPATCHER_CREDIT_TABLE_1 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2ff0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BASIC_RATE_LIMITER_TABLE_1 =
{
	16,
	{
		{ dump_RDD_BASIC_RATE_LIMITER_DESCRIPTOR, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_1 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x3800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT XGPON_REPORT_ZERO_SENT_TABLE_1 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x3810 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_TX_SCRATCHPAD_2 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_2 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_2 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x4f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_2 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_2 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_2 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x7d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x7e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_2 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_2 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_2 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x2280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_2 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x22d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_2 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x22e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_2 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x2300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2380 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_2 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x23c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_2 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x2400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2608 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_2 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0x2688 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_REPLY_2 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2690 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_2 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0x26a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_2 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x26b8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x26c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_2 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x26e8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_2 =
{
	16,
	{
		{ dump_RDD_CPU_INTERRUPT_COALESCING_ENTRY, 0x26f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2700 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_2 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0x2740 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2790 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x27a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TASK_IDX_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x27ac },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x27b0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x27bc },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x27bd },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x27be },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT QUEUE_THRESHOLD_VECTOR_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x27c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_2 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0x27e4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x27e6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x27e7 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_2 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x27e8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_DESCRIPTOR_TABLE_2 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x27f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_2 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0x2800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_2 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x2a08 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_2 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0x2a18 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_2 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x2a20 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_2 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x2a30 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_2 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2a3c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2a40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_2 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0x2a68 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_2 =
{
	8,
	{
		{ dump_RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY, 0x2a70 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_2 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0x2a78 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2a80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_2 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0x2aa8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_2 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0x2ab0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_2 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0x2ab8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2ac0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_2 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0x2ae8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_2 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x2b00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2b40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2b80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_TX_EGRESS_UPDATE_FIFO_TABLE_2 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x2bc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_2 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x2c00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_2 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x2e00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_TX_INGRESS_UPDATE_FIFO_TABLE_2 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x2f80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_TX_EGRESS_PD_FIFO_TABLE_2 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x2fc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_2 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_TX_INGRESS_PD_FIFO_TABLE_2 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x3140 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_SCRATCH_2 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x3180 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SRAM_PD_FIFO_2 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x3200 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SHADOW_RD_IDX_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x3300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SHADOW_WR_IDX_2 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x3380 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_3 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DS_CPU_RX_METER_TABLE_3 =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_SCRATCHPAD_3 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT US_CPU_RX_METER_TABLE_3 =
{
	8,
	{
		{ dump_RDD_CPU_RX_METER_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RING_INTERRUPT_COUNTER_TABLE_3 =
{
	8,
	{
		{ dump_RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_3 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x590 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_3 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_3 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_3 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x7f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_3 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_3 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_3 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_3 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0x2208 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_3 =
{
	16,
	{
		{ dump_RDD_CPU_INTERRUPT_COALESCING_ENTRY, 0x2210 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_3 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x2220 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_3 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x2240 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_REASON_AND_VPORT_TO_METER_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_3 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x22f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_3 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x2300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_3 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x2380 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x23d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_3 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0x23e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_3 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x23f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_3 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0x2400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_3 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x2608 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2610 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2620 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_SCRATCH_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x262c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_DESCRIPTOR_TABLE_3 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x2630 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DS_CPU_REASON_TO_METER_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2640 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_3 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x2680 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_3 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x26d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_INTERRUPT_COALESCING_TABLE_3 =
{
	16,
	{
		{ dump_RDD_CPU_INTERRUPT_COALESCING_ENTRY, 0x26e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_3 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x26f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_COPY_PD_FIFO_TABLE_3 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x2700 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT US_CPU_REASON_TO_METER_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2740 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_3 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x2800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_3 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x2a00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2b80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2bc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_LOCAL_SCRATCH_3 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2be8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_3 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0x2bf8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_3 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x2c00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_3 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0x2d40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_3 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x2d90 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TASK_IDX_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2d9c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_3 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0x2da0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2da5 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2da6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2da7 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_3 =
{
	8,
	{
		{ dump_RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY, 0x2da8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_COPY_LOCAL_SCRATCH_3 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2db0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_3 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0x2db8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2dc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2de2 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_COUNTER_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2de4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_3 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0x2de6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_3 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0x2de8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_3 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0x2df0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_3 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0x2df8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2dff },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SRAM_PD_FIFO_3 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x2e00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_3 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x2f00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_3 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0x2f30 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2f32 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2f40 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2f80 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2fc0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RING_DESCRIPTORS_TABLE_3 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x3000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x3100 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT UPDATE_FIFO_TABLE_3 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x3140 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_COPY_UPDATE_FIFO_TABLE_3 =
{
	4,
	{
		{ dump_RDD_UPDATE_FIFO_ENTRY, 0x3180 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PD_FIFO_TABLE_3 =
{
	16,
	{
		{ dump_RDD_PROCESSING_TX_DESCRIPTOR, 0x31c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_REASON_TO_TC_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x31e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TC_TO_CPU_RXQ_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x3220 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT EXC_TC_TO_CPU_RXQ_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x3260 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_TO_CPU_OBJ_3 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x32c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_INTERRUPT_SCRATCH_3 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x3300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SHADOW_RD_IDX_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x3380 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RECYCLE_SHADOW_WR_IDX_3 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x3400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_4 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_4 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_4 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_4 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_4 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_4 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_4 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_4 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_4 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_4 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_4 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_4 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_4 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2208 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_4 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0x2288 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_4 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2290 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_4 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x2298 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_4 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0x22a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_4 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0x22b8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x22c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_4 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0x22e8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x22ed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x22ee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x22ef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_4 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x22f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_4 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0x2340 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_4 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x2390 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TASK_IDX_4 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x239c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_4 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0x23a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_4 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0x23a8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_4 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0x23b0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_4 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0x23b8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x23bf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x23c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x23e2 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_4 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0x23e4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_4 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x23e6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_4 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0x23e8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_4 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0x2400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2640 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2680 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x26c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_4 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x2700 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_4 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2740 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_4 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x2800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_4 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x2a00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_4 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x2c00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_TABLE_5 =
{
	2,
	{
		{ dump_RDD_RX_FLOW_ENTRY, 0x0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LAYER2_HEADER_COPY_MAPPING_TABLE_5 =
{
	4,
	{
		{ dump_RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY, 0x280 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_CONFIGURATION_TABLE_5 =
{
	8,
	{
		{ dump_RDD_HW_IPTV_CONFIGURATION, 0x2f8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DSCP_TO_PBITS_MAP_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PROCESSING_CPU_RX_SCRATCHPAD_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_GLOBAL_REGISTERS_INIT_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x420 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT GLOBAL_DSCP_TO_PBITS_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x440 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_CFG_TABLE_5 =
{
	2,
	{
		{ dump_RDD_VPORT_CFG_ENTRY, 0x480 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_POOL_NUMBER_MAPPING_TABLE_5 =
{
	1,
	{
		{ dump_RDD_FPM_POOL_NUMBER, 0x4d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VPORT_TO_DSCP_TO_PBITS_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x4e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_PROFILE_TABLE_5 =
{
	8,
	{
		{ dump_RDD_INGRESS_FILTER_CTRL, 0x500 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT POLICER_PARAMS_TABLE_5 =
{
	1,
	{
		{ dump_RDD_POLICER_PARAMS_ENTRY, 0x580 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_L2_REASON_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x5d0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_HANDLER_TABLE_5 =
{
	2,
	{
		{ dump_RDD_TCAM_IC_HANDLER, 0x5e0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LAYER2_GRE_TUNNEL_TABLE_5 =
{
	32,
	{
		{ dump_RDD_LAYER2_GRE_TUNNEL_ENTRY, 0x600 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PBIT_TO_GEM_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x780 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DUAL_STACK_LITE_TABLE_5 =
{
	64,
	{
		{ dump_RDD_DUAL_STACK_LITE_ENTRY, 0x7c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IC_EXT_CONTEXT_TABLE_5 =
{
	4,
	{
		{ dump_RDD_IC_EXT_CONTEXT_ENTRY, 0x800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DS_PACKET_BUFFER_5 =
{
	512,
	{
		{ dump_RDD_PACKET_BUFFER, 0x1000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TC_TO_QUEUE_TABLE_5 =
{
	8,
	{
		{ dump_RDD_TC_TO_QUEUE_8, 0x2000 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT REGISTERS_BUFFER_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x2208 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_FLOW_CONTEXT_DDR_ADDR_5 =
{
	8,
	{
		{ dump_RDD_DEF_FLOW_CONTEXT_DDR_ADDR, 0x2288 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NULL_BUFFER_5 =
{
	8,
	{
		{ dump_RDD_BYTES_8, 0x2290 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_RX_INTERRUPT_ID_DDR_ADDR_5 =
{
	8,
	{
		{ dump_RDD_DDR_ADDRESS, 0x2298 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT BRIDGE_CFG_TABLE_5 =
{
	8,
	{
		{ dump_RDD_BRIDGE_CFG, 0x22a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT DEFAULT_BRIDGE_CFG_5 =
{
	8,
	{
		{ dump_RDD_BRIDGE_AND_VLAN_LKP_RESULT, 0x22b8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT LOOPBACK_QUEUE_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x22c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SYSTEM_CONFIGURATION_5 =
{
	5,
	{
		{ dump_RDD_SYSTEM_CONFIGURATION_ENTRY, 0x22e8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FORCE_DSCP_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x22ed },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CORE_ID_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x22ee },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT SRAM_DUMMY_STORE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x22ef },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_DESCRIPTOR_TABLE_5 =
{
	16,
	{
		{ dump_RDD_CPU_RING_DESCRIPTOR, 0x22f0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x2300 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_CFG_TABLE_5 =
{
	16,
	{
		{ dump_RDD_TCAM_IC_CFG, 0x2340 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FPM_GLOBAL_CFG_5 =
{
	12,
	{
		{ dump_RDD_FPM_GLOBAL_CFG, 0x2390 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TASK_IDX_5 =
{
	4,
	{
		{ dump_RDD_BYTES_4, 0x239c },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TUNNELS_PARSING_CFG_5 =
{
	8,
	{
		{ dump_RDD_TUNNELS_PARSING_CFG, 0x23a0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_CFG_TABLE_5 =
{
	8,
	{
		{ dump_RDD_IPTV_CFG, 0x23a8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_DDR_CTX_TABLE_ADDRESS_5 =
{
	8,
	{
		{ dump_RDD_IPTV_DDR_CTX_TABLE_ADDRESS, 0x23b0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NAT_CACHE_CFG_5 =
{
	7,
	{
		{ dump_RDD_NAT_CACHE_CFG, 0x23b8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IC_DEBUG_COUNTER_MODE_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x23bf },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT FLOW_BASED_ACTION_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x23c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT CPU_FEED_RING_INTERRUPT_THRESHOLD_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x23e2 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RX_MIRRORING_CONFIGURATION_5 =
{
	2,
	{
		{ dump_RDD_MIRRORING_DESCRIPTOR, 0x23e4 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_1588_CFG_5 =
{
	1,
	{
		{ dump_RDD_BYTE_1, 0x23e6 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT INGRESS_FILTER_CFG_5 =
{
	2,
	{
		{ dump_RDD_INGRESS_FILTER_CFG, 0x23e8 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT PBIT_TO_QUEUE_TABLE_5 =
{
	8,
	{
		{ dump_RDD_PBIT_TO_QUEUE_8, 0x2400 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RULE_BASED_ACTION_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2640 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RULE_BASED_CONTEXT_ACTION_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2680 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT IPTV_ACTION_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x26c0 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT NATC_TBL_CFG_5 =
{
	24,
	{
		{ dump_RDD_NATC_TBL_CONFIGURATION, 0x2700 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT VLAN_ACTION_GPE_HANDLER_PTR_TABLE_5 =
{
	2,
	{
		{ dump_RDD_BYTES_2, 0x2740 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT RUNNER_PROFILING_TRACE_BUFFER_5 =
{
	4,
	{
		{ dump_RDD_TRACE_EVENT, 0x2800 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TCAM_IC_CMD_TABLE_5 =
{
	4,
	{
		{ dump_RDD_TCAM_IC_CMD, 0x2a00 },
		{ 0, 0 },
	}
};
#endif
#if defined BCM6836
static DUMP_RUNNERREG_STRUCT TX_FLOW_TABLE_5 =
{
	1,
	{
		{ dump_RDD_TX_FLOW_ENTRY, 0x2c00 },
		{ 0, 0 },
	}
};
#endif

TABLE_STRUCT RUNNER_TABLES[NUMBER_OF_TABLES] =
{
#if defined BCM6836
	{ "PD_FIFO_TABLE", 1, CORE_0_INDEX, &PD_FIFO_TABLE, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "COMPLEX_SCHEDULER_TABLE", 1, CORE_0_INDEX, &COMPLEX_SCHEDULER_TABLE, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_QUEUE_TABLE", 1, CORE_0_INDEX, &SCHEDULING_QUEUE_TABLE, 160, 1, 1 },
#endif
#if defined BCM6836
	{ "TM_FLOW_CNTR_TABLE", 1, CORE_0_INDEX, &TM_FLOW_CNTR_TABLE, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_EGRESS_COUNTER_TABLE", 1, CORE_0_INDEX, &BBH_TX_EGRESS_COUNTER_TABLE, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "TM_ACTION_PTR_TABLE", 1, CORE_0_INDEX, &TM_ACTION_PTR_TABLE, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "BUDGET_ALLOCATION_TIMER_VALUE", 1, CORE_0_INDEX, &BUDGET_ALLOCATION_TIMER_VALUE, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BB_DESTINATION_TABLE", 1, CORE_0_INDEX, &BB_DESTINATION_TABLE, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_INTERRUPT_COUNTER_MAX", 1, CORE_0_INDEX, &CPU_FEED_RING_INTERRUPT_COUNTER_MAX, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_0_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FLUSH_DISPATCHER_CREDIT_TABLE", 1, CORE_0_INDEX, &FLUSH_DISPATCHER_CREDIT_TABLE, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "TASK_IDX", 1, CORE_0_INDEX, &TASK_IDX, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BASIC_SCHEDULER_TABLE", 1, CORE_0_INDEX, &BASIC_SCHEDULER_TABLE, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "BASIC_RATE_LIMITER_TABLE", 1, CORE_0_INDEX, &BASIC_RATE_LIMITER_TABLE, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_TABLE", 1, CORE_0_INDEX, &RX_FLOW_TABLE, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "REGISTERS_BUFFER", 1, CORE_0_INDEX, &REGISTERS_BUFFER, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "NATC_TBL_CFG", 1, CORE_0_INDEX, &NATC_TBL_CFG, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "TX_MIRRORING_DISPATCHER_CREDIT_TABLE", 1, CORE_0_INDEX, &TX_MIRRORING_DISPATCHER_CREDIT_TABLE, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_GLOBAL_FLUSH_CFG", 1, CORE_0_INDEX, &SCHEDULING_GLOBAL_FLUSH_CFG, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_FLUSH_GLOBAL_CFG", 1, CORE_0_INDEX, &SCHEDULING_FLUSH_GLOBAL_CFG, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_0_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_0_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "DIRECT_PROCESSING_PD_TABLE", 1, CORE_0_INDEX, &DIRECT_PROCESSING_PD_TABLE, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "UPDATE_FIFO_TABLE", 1, CORE_0_INDEX, &UPDATE_FIFO_TABLE, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_FLUSH_VECTOR", 1, CORE_0_INDEX, &SCHEDULING_FLUSH_VECTOR, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "TX_MIRRORING_CONFIGURATION", 1, CORE_0_INDEX, &TX_MIRRORING_CONFIGURATION, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SRAM_DUMMY_STORE", 1, CORE_0_INDEX, &SRAM_DUMMY_STORE, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "MAC_TYPE", 1, CORE_0_INDEX, &MAC_TYPE, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_QUEUE_ID_TABLE", 1, CORE_0_INDEX, &BBH_TX_QUEUE_ID_TABLE, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_QUEUE_AGING_VECTOR", 1, CORE_0_INDEX, &SCHEDULING_QUEUE_AGING_VECTOR, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_FIFO_SIZE", 1, CORE_0_INDEX, &BBH_TX_FIFO_SIZE, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FIRST_QUEUE_MAPPING", 1, CORE_0_INDEX, &FIRST_QUEUE_MAPPING, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "MIRRORING_SCRATCH", 1, CORE_0_INDEX, &MIRRORING_SCRATCH, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_AGGREGATION_CONTEXT_VECTOR", 1, CORE_0_INDEX, &SCHEDULING_AGGREGATION_CONTEXT_VECTOR, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "DIRECT_PROCESSING_EPON_CONTROL_SCRATCH", 1, CORE_0_INDEX, &DIRECT_PROCESSING_EPON_CONTROL_SCRATCH, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_0_INDEX, &RUNNER_PROFILING_TRACE_BUFFER, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_QUEUE_TABLE", 1, CORE_0_INDEX, &BBH_QUEUE_TABLE, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "SCRATCH", 1, CORE_0_INDEX, &SCRATCH, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "RATE_LIMITER_VALID_TABLE", 1, CORE_0_INDEX, &RATE_LIMITER_VALID_TABLE, 4, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_0_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_GLOBAL_CFG", 1, CORE_0_INDEX, &FPM_GLOBAL_CFG, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "PD_FIFO_TABLE", 1, CORE_1_INDEX, &PD_FIFO_TABLE_1, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "COMPLEX_SCHEDULER_TABLE", 1, CORE_1_INDEX, &COMPLEX_SCHEDULER_TABLE_1, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_QUEUE_TABLE", 1, CORE_1_INDEX, &SCHEDULING_QUEUE_TABLE_1, 160, 1, 1 },
#endif
#if defined BCM6836
	{ "REPORTING_COUNTER_TABLE", 1, CORE_1_INDEX, &REPORTING_COUNTER_TABLE_1, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_1_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_1, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_EGRESS_COUNTER_TABLE", 1, CORE_1_INDEX, &BBH_TX_EGRESS_COUNTER_TABLE_1, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "BASIC_SCHEDULER_TABLE", 1, CORE_1_INDEX, &BASIC_SCHEDULER_TABLE_1, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "REPORTING_QUEUE_DESCRIPTOR_TABLE", 1, CORE_1_INDEX, &REPORTING_QUEUE_DESCRIPTOR_TABLE_1, 160, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_QUEUE_TABLE", 1, CORE_1_INDEX, &BBH_QUEUE_TABLE_1, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_FLUSH_VECTOR", 1, CORE_1_INDEX, &SCHEDULING_FLUSH_VECTOR_1, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "GHOST_REPORTING_GLOBAL_CFG", 1, CORE_1_INDEX, &GHOST_REPORTING_GLOBAL_CFG_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_QUEUE_ID_TABLE", 1, CORE_1_INDEX, &BBH_TX_QUEUE_ID_TABLE_1, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_EPON_INGRESS_COUNTER_TABLE", 1, CORE_1_INDEX, &BBH_TX_EPON_INGRESS_COUNTER_TABLE_1, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_EPON_QUEUE_ID_TABLE", 1, CORE_1_INDEX, &BBH_TX_EPON_QUEUE_ID_TABLE_1, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "XGPON_REPORT_TABLE", 1, CORE_1_INDEX, &XGPON_REPORT_TABLE_1, 4, 1, 1 },
#endif
#if defined BCM6836
	{ "TM_FLOW_CNTR_TABLE", 1, CORE_1_INDEX, &TM_FLOW_CNTR_TABLE_1, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "REPORTING_QUEUE_ACCUMULATED_TABLE", 1, CORE_1_INDEX, &REPORTING_QUEUE_ACCUMULATED_TABLE_1, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_1_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_1, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "REGISTERS_BUFFER", 1, CORE_1_INDEX, &REGISTERS_BUFFER_1, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_EPON_EGRESS_COUNTER_TABLE", 1, CORE_1_INDEX, &BBH_TX_EPON_EGRESS_COUNTER_TABLE_1, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "MIRRORING_SCRATCH", 1, CORE_1_INDEX, &MIRRORING_SCRATCH_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "OVERALL_RATE_LIMITER_TABLE", 1, CORE_1_INDEX, &OVERALL_RATE_LIMITER_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TM_ACTION_PTR_TABLE", 1, CORE_1_INDEX, &TM_ACTION_PTR_TABLE_1, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "BUDGET_ALLOCATION_TIMER_VALUE", 1, CORE_1_INDEX, &BUDGET_ALLOCATION_TIMER_VALUE_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BB_DESTINATION_TABLE", 1, CORE_1_INDEX, &BB_DESTINATION_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_GLOBAL_FLUSH_CFG", 1, CORE_1_INDEX, &SCHEDULING_GLOBAL_FLUSH_CFG_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_FLUSH_GLOBAL_CFG", 1, CORE_1_INDEX, &SCHEDULING_FLUSH_GLOBAL_CFG_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "REPORT_BBH_TX_QUEUE_ID_TABLE", 1, CORE_1_INDEX, &REPORT_BBH_TX_QUEUE_ID_TABLE_1, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "FLUSH_DISPATCHER_CREDIT_TABLE", 1, CORE_1_INDEX, &FLUSH_DISPATCHER_CREDIT_TABLE_1, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "TASK_IDX", 1, CORE_1_INDEX, &TASK_IDX_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "NATC_TBL_CFG", 1, CORE_1_INDEX, &NATC_TBL_CFG_1, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "DISPATCHER_CREDIT_TABLE", 1, CORE_1_INDEX, &DISPATCHER_CREDIT_TABLE_1, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "TX_MIRRORING_CONFIGURATION", 1, CORE_1_INDEX, &TX_MIRRORING_CONFIGURATION_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SRAM_DUMMY_STORE", 1, CORE_1_INDEX, &SRAM_DUMMY_STORE_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_FIFO_SIZE", 1, CORE_1_INDEX, &BBH_TX_FIFO_SIZE_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "EPON_UPDATE_FIFO_TABLE", 1, CORE_1_INDEX, &EPON_UPDATE_FIFO_TABLE_1, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_QUEUE_AGING_VECTOR", 1, CORE_1_INDEX, &SCHEDULING_QUEUE_AGING_VECTOR_1, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "FIRST_QUEUE_MAPPING", 1, CORE_1_INDEX, &FIRST_QUEUE_MAPPING_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_INGRESS_COUNTER_TABLE", 1, CORE_1_INDEX, &BBH_TX_INGRESS_COUNTER_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BBH_TX_EGRESS_REPORT_COUNTER_TABLE", 1, CORE_1_INDEX, &BBH_TX_EGRESS_REPORT_COUNTER_TABLE_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "UPDATE_FIFO_TABLE", 1, CORE_1_INDEX, &UPDATE_FIFO_TABLE_1, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "SCHEDULING_AGGREGATION_CONTEXT_VECTOR", 1, CORE_1_INDEX, &SCHEDULING_AGGREGATION_CONTEXT_VECTOR_1, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE", 1, CORE_1_INDEX, &GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_1, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "RATE_LIMITER_VALID_TABLE", 1, CORE_1_INDEX, &RATE_LIMITER_VALID_TABLE_1, 4, 1, 1 },
#endif
#if defined BCM6836
	{ "TX_MIRRORING_DISPATCHER_CREDIT_TABLE", 1, CORE_1_INDEX, &TX_MIRRORING_DISPATCHER_CREDIT_TABLE_1, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "BASIC_RATE_LIMITER_TABLE", 1, CORE_1_INDEX, &BASIC_RATE_LIMITER_TABLE_1, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_GLOBAL_CFG", 1, CORE_1_INDEX, &FPM_GLOBAL_CFG_1, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "XGPON_REPORT_ZERO_SENT_TABLE", 1, CORE_1_INDEX, &XGPON_REPORT_ZERO_SENT_TABLE_1, 10, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_TX_SCRATCHPAD", 1, CORE_2_INDEX, &CPU_TX_SCRATCHPAD_2, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_2_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_2, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_2_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_2, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_2_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_2, 1, 64, 1 },
#endif
#if defined BCM6836
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_2_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_2, 30, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_2_INDEX, &IPTV_CONFIGURATION_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_2_INDEX, &DSCP_TO_PBITS_MAP_TABLE_2, 4, 64, 1 },
#endif
#if defined BCM6836
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_2_INDEX, &LAYER2_GRE_TUNNEL_TABLE_2, 12, 1, 1 },
#endif
#if defined BCM6836
	{ "VPORT_CFG_TABLE", 1, CORE_2_INDEX, &VPORT_CFG_TABLE_2, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_2_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_2, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_2_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_2, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_2_INDEX, &IC_EXT_CONTEXT_TABLE_2, 512, 1, 1 },
#endif
#if defined BCM6836
	{ "DS_PACKET_BUFFER", 1, CORE_2_INDEX, &DS_PACKET_BUFFER_2, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_TABLE", 1, CORE_2_INDEX, &RX_FLOW_TABLE_2, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "POLICER_PARAMS_TABLE", 1, CORE_2_INDEX, &POLICER_PARAMS_TABLE_2, 80, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_2_INDEX, &CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_2, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_2_INDEX, &TCAM_IC_HANDLER_TABLE_2, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_2_INDEX, &INGRESS_FILTER_PROFILE_TABLE_2, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "PBIT_TO_GEM_TABLE", 1, CORE_2_INDEX, &PBIT_TO_GEM_TABLE_2, 8, 8, 1 },
#endif
#if defined BCM6836
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_2_INDEX, &DUAL_STACK_LITE_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TC_TO_QUEUE_TABLE", 1, CORE_2_INDEX, &TC_TO_QUEUE_TABLE_2, 65, 1, 1 },
#endif
#if defined BCM6836
	{ "REGISTERS_BUFFER", 1, CORE_2_INDEX, &REGISTERS_BUFFER_2, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_2_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_REPLY", 1, CORE_2_INDEX, &FPM_REPLY_2, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "BRIDGE_CFG_TABLE", 1, CORE_2_INDEX, &BRIDGE_CFG_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "NULL_BUFFER", 1, CORE_2_INDEX, &NULL_BUFFER_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_2_INDEX, &LOOPBACK_QUEUE_TABLE_2, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR", 1, CORE_2_INDEX, &CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_INTERRUPT_COALESCING_TABLE", 1, CORE_2_INDEX, &CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_2_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_2, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_CFG_TABLE", 1, CORE_2_INDEX, &TCAM_IC_CFG_TABLE_2, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_2_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_2, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE", 1, CORE_2_INDEX, &CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "TASK_IDX", 1, CORE_2_INDEX, &TASK_IDX_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE", 1, CORE_2_INDEX, &CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_2, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "FORCE_DSCP", 1, CORE_2_INDEX, &FORCE_DSCP_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CORE_ID_TABLE", 1, CORE_2_INDEX, &CORE_ID_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_2_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "QUEUE_THRESHOLD_VECTOR", 1, CORE_2_INDEX, &QUEUE_THRESHOLD_VECTOR_2, 9, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_2_INDEX, &RX_MIRRORING_CONFIGURATION_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SRAM_DUMMY_STORE", 1, CORE_2_INDEX, &SRAM_DUMMY_STORE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_2_INDEX, &IC_DEBUG_COUNTER_MODE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_2_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_RING_DESCRIPTOR_TABLE", 1, CORE_2_INDEX, &CPU_RECYCLE_RING_DESCRIPTOR_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_2_INDEX, &PBIT_TO_QUEUE_TABLE_2, 65, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE", 1, CORE_2_INDEX, &CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_2, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_2_INDEX, &DEFAULT_BRIDGE_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_2_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_GLOBAL_CFG", 1, CORE_2_INDEX, &FPM_GLOBAL_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_2_INDEX, &INGRESS_FILTER_1588_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_2_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_2, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "SYSTEM_CONFIGURATION", 1, CORE_2_INDEX, &SYSTEM_CONFIGURATION_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE", 1, CORE_2_INDEX, &CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TUNNELS_PARSING_CFG", 1, CORE_2_INDEX, &TUNNELS_PARSING_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_2_INDEX, &RULE_BASED_ACTION_PTR_TABLE_2, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_CFG_TABLE", 1, CORE_2_INDEX, &IPTV_CFG_TABLE_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_2_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "NAT_CACHE_CFG", 1, CORE_2_INDEX, &NAT_CACHE_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_2_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_2, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_CFG", 1, CORE_2_INDEX, &INGRESS_FILTER_CFG_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "NATC_TBL_CFG", 1, CORE_2_INDEX, &NATC_TBL_CFG_2, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_2_INDEX, &IPTV_ACTION_PTR_TABLE_2, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_2_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_2, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_TX_EGRESS_UPDATE_FIFO_TABLE", 1, CORE_2_INDEX, &CPU_TX_EGRESS_UPDATE_FIFO_TABLE_2, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_2_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_2, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_CMD_TABLE", 1, CORE_2_INDEX, &TCAM_IC_CMD_TABLE_2, 6, 16, 1 },
#endif
#if defined BCM6836
	{ "CPU_TX_INGRESS_UPDATE_FIFO_TABLE", 1, CORE_2_INDEX, &CPU_TX_INGRESS_UPDATE_FIFO_TABLE_2, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_TX_EGRESS_PD_FIFO_TABLE", 1, CORE_2_INDEX, &CPU_TX_EGRESS_PD_FIFO_TABLE_2, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "TX_FLOW_TABLE", 1, CORE_2_INDEX, &TX_FLOW_TABLE_2, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_TX_INGRESS_PD_FIFO_TABLE", 1, CORE_2_INDEX, &CPU_TX_INGRESS_PD_FIFO_TABLE_2, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_INTERRUPT_SCRATCH", 1, CORE_2_INDEX, &CPU_RECYCLE_INTERRUPT_SCRATCH_2, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_SRAM_PD_FIFO", 1, CORE_2_INDEX, &CPU_RECYCLE_SRAM_PD_FIFO_2, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_SHADOW_RD_IDX", 1, CORE_2_INDEX, &CPU_RECYCLE_SHADOW_RD_IDX_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_SHADOW_WR_IDX", 1, CORE_2_INDEX, &CPU_RECYCLE_SHADOW_WR_IDX_2, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_TABLE", 1, CORE_3_INDEX, &RX_FLOW_TABLE_3, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "DS_CPU_RX_METER_TABLE", 1, CORE_3_INDEX, &DS_CPU_RX_METER_TABLE_3, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_3_INDEX, &DSCP_TO_PBITS_MAP_TABLE_3, 4, 64, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_SCRATCHPAD", 1, CORE_3_INDEX, &CPU_RX_SCRATCHPAD_3, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_3_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_3, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_3_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_3, 1, 64, 1 },
#endif
#if defined BCM6836
	{ "US_CPU_RX_METER_TABLE", 1, CORE_3_INDEX, &US_CPU_RX_METER_TABLE_3, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RING_INTERRUPT_COUNTER_TABLE", 1, CORE_3_INDEX, &CPU_RING_INTERRUPT_COUNTER_TABLE_3, 18, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_3_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_3, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_3_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_3, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "PBIT_TO_GEM_TABLE", 1, CORE_3_INDEX, &PBIT_TO_GEM_TABLE_3, 8, 8, 1 },
#endif
#if defined BCM6836
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_3_INDEX, &LAYER2_GRE_TUNNEL_TABLE_3, 12, 1, 1 },
#endif
#if defined BCM6836
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_3_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_3, 30, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_3_INDEX, &IPTV_CONFIGURATION_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_3_INDEX, &IC_EXT_CONTEXT_TABLE_3, 512, 1, 1 },
#endif
#if defined BCM6836
	{ "DS_PACKET_BUFFER", 1, CORE_3_INDEX, &DS_PACKET_BUFFER_3, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "TC_TO_QUEUE_TABLE", 1, CORE_3_INDEX, &TC_TO_QUEUE_TABLE_3, 65, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_3_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_INTERRUPT_COALESCING_TABLE", 1, CORE_3_INDEX, &CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_3_INDEX, &TCAM_IC_HANDLER_TABLE_3, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_3_INDEX, &DUAL_STACK_LITE_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_REASON_AND_VPORT_TO_METER_TABLE", 1, CORE_3_INDEX, &CPU_REASON_AND_VPORT_TO_METER_TABLE_3, 120, 1, 1 },
#endif
#if defined BCM6836
	{ "NULL_BUFFER", 1, CORE_3_INDEX, &NULL_BUFFER_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_3_INDEX, &INGRESS_FILTER_PROFILE_TABLE_3, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "VPORT_CFG_TABLE", 1, CORE_3_INDEX, &VPORT_CFG_TABLE_3, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD", 1, CORE_3_INDEX, &CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_3, 4, 1, 1 },
#endif
#if defined BCM6836
	{ "BRIDGE_CFG_TABLE", 1, CORE_3_INDEX, &BRIDGE_CFG_TABLE_3, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR", 1, CORE_3_INDEX, &CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_3_INDEX, &PBIT_TO_QUEUE_TABLE_3, 65, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_3_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_3_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_3, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_COPY_DISPATCHER_CREDIT_TABLE", 1, CORE_3_INDEX, &CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_3, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_INTERRUPT_SCRATCH", 1, CORE_3_INDEX, &CPU_RX_INTERRUPT_SCRATCH_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_RING_DESCRIPTOR_TABLE", 1, CORE_3_INDEX, &CPU_RECYCLE_RING_DESCRIPTOR_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "DS_CPU_REASON_TO_METER_TABLE", 1, CORE_3_INDEX, &DS_CPU_REASON_TO_METER_TABLE_3, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "POLICER_PARAMS_TABLE", 1, CORE_3_INDEX, &POLICER_PARAMS_TABLE_3, 80, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE", 1, CORE_3_INDEX, &CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_3, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_INTERRUPT_COALESCING_TABLE", 1, CORE_3_INDEX, &CPU_INTERRUPT_COALESCING_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_3_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_COPY_PD_FIFO_TABLE", 1, CORE_3_INDEX, &CPU_RX_COPY_PD_FIFO_TABLE_3, 4, 1, 1 },
#endif
#if defined BCM6836
	{ "US_CPU_REASON_TO_METER_TABLE", 1, CORE_3_INDEX, &US_CPU_REASON_TO_METER_TABLE_3, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "REGISTERS_BUFFER", 1, CORE_3_INDEX, &REGISTERS_BUFFER_3, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_3_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_3, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_CMD_TABLE", 1, CORE_3_INDEX, &TCAM_IC_CMD_TABLE_3, 6, 16, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_3_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_3, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_3_INDEX, &LOOPBACK_QUEUE_TABLE_3, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_LOCAL_SCRATCH", 1, CORE_3_INDEX, &CPU_RX_LOCAL_SCRATCH_3, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_3_INDEX, &DEFAULT_BRIDGE_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TX_FLOW_TABLE", 1, CORE_3_INDEX, &TX_FLOW_TABLE_3, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_CFG_TABLE", 1, CORE_3_INDEX, &TCAM_IC_CFG_TABLE_3, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_GLOBAL_CFG", 1, CORE_3_INDEX, &FPM_GLOBAL_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TASK_IDX", 1, CORE_3_INDEX, &TASK_IDX_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SYSTEM_CONFIGURATION", 1, CORE_3_INDEX, &SYSTEM_CONFIGURATION_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FORCE_DSCP", 1, CORE_3_INDEX, &FORCE_DSCP_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CORE_ID_TABLE", 1, CORE_3_INDEX, &CORE_ID_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SRAM_DUMMY_STORE", 1, CORE_3_INDEX, &SRAM_DUMMY_STORE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE", 1, CORE_3_INDEX, &CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_COPY_LOCAL_SCRATCH", 1, CORE_3_INDEX, &CPU_RX_COPY_LOCAL_SCRATCH_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TUNNELS_PARSING_CFG", 1, CORE_3_INDEX, &TUNNELS_PARSING_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_3_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_3, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_3_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_INTERRUPT_COUNTER", 1, CORE_3_INDEX, &CPU_FEED_RING_INTERRUPT_COUNTER_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_3_INDEX, &RX_MIRRORING_CONFIGURATION_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_CFG_TABLE", 1, CORE_3_INDEX, &IPTV_CFG_TABLE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_3_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "NAT_CACHE_CFG", 1, CORE_3_INDEX, &NAT_CACHE_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_3_INDEX, &IC_DEBUG_COUNTER_MODE_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_SRAM_PD_FIFO", 1, CORE_3_INDEX, &CPU_RECYCLE_SRAM_PD_FIFO_3, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "NATC_TBL_CFG", 1, CORE_3_INDEX, &NATC_TBL_CFG_3, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_CFG", 1, CORE_3_INDEX, &INGRESS_FILTER_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_3_INDEX, &INGRESS_FILTER_1588_CFG_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_3_INDEX, &RULE_BASED_ACTION_PTR_TABLE_3, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_3_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_3, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_3_INDEX, &IPTV_ACTION_PTR_TABLE_3, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RING_DESCRIPTORS_TABLE", 1, CORE_3_INDEX, &CPU_RING_DESCRIPTORS_TABLE_3, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_3_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_3, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "UPDATE_FIFO_TABLE", 1, CORE_3_INDEX, &UPDATE_FIFO_TABLE_3, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_COPY_UPDATE_FIFO_TABLE", 1, CORE_3_INDEX, &CPU_RX_COPY_UPDATE_FIFO_TABLE_3, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "PD_FIFO_TABLE", 1, CORE_3_INDEX, &PD_FIFO_TABLE_3, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_REASON_TO_TC", 1, CORE_3_INDEX, &CPU_REASON_TO_TC_3, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "TC_TO_CPU_RXQ", 1, CORE_3_INDEX, &TC_TO_CPU_RXQ_3, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "EXC_TC_TO_CPU_RXQ", 1, CORE_3_INDEX, &EXC_TC_TO_CPU_RXQ_3, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "VPORT_TO_CPU_OBJ", 1, CORE_3_INDEX, &VPORT_TO_CPU_OBJ_3, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_INTERRUPT_SCRATCH", 1, CORE_3_INDEX, &CPU_RECYCLE_INTERRUPT_SCRATCH_3, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_SHADOW_RD_IDX", 1, CORE_3_INDEX, &CPU_RECYCLE_SHADOW_RD_IDX_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RECYCLE_SHADOW_WR_IDX", 1, CORE_3_INDEX, &CPU_RECYCLE_SHADOW_WR_IDX_3, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_TABLE", 1, CORE_4_INDEX, &RX_FLOW_TABLE_4, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_4_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_4, 30, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_4_INDEX, &IPTV_CONFIGURATION_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_4_INDEX, &DSCP_TO_PBITS_MAP_TABLE_4, 4, 64, 1 },
#endif
#if defined BCM6836
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_4_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_4, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_4_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_4, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_4_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_4, 1, 64, 1 },
#endif
#if defined BCM6836
	{ "VPORT_CFG_TABLE", 1, CORE_4_INDEX, &VPORT_CFG_TABLE_4, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_4_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_4, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_4_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_4, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_4_INDEX, &INGRESS_FILTER_PROFILE_TABLE_4, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "POLICER_PARAMS_TABLE", 1, CORE_4_INDEX, &POLICER_PARAMS_TABLE_4, 80, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_4_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_4, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_4_INDEX, &TCAM_IC_HANDLER_TABLE_4, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_4_INDEX, &LAYER2_GRE_TUNNEL_TABLE_4, 12, 1, 1 },
#endif
#if defined BCM6836
	{ "PBIT_TO_GEM_TABLE", 1, CORE_4_INDEX, &PBIT_TO_GEM_TABLE_4, 8, 8, 1 },
#endif
#if defined BCM6836
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_4_INDEX, &DUAL_STACK_LITE_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_4_INDEX, &IC_EXT_CONTEXT_TABLE_4, 512, 1, 1 },
#endif
#if defined BCM6836
	{ "DS_PACKET_BUFFER", 1, CORE_4_INDEX, &DS_PACKET_BUFFER_4, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "TC_TO_QUEUE_TABLE", 1, CORE_4_INDEX, &TC_TO_QUEUE_TABLE_4, 65, 1, 1 },
#endif
#if defined BCM6836
	{ "REGISTERS_BUFFER", 1, CORE_4_INDEX, &REGISTERS_BUFFER_4, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_4_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "NULL_BUFFER", 1, CORE_4_INDEX, &NULL_BUFFER_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_4_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BRIDGE_CFG_TABLE", 1, CORE_4_INDEX, &BRIDGE_CFG_TABLE_4, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_4_INDEX, &DEFAULT_BRIDGE_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_4_INDEX, &LOOPBACK_QUEUE_TABLE_4, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "SYSTEM_CONFIGURATION", 1, CORE_4_INDEX, &SYSTEM_CONFIGURATION_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FORCE_DSCP", 1, CORE_4_INDEX, &FORCE_DSCP_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CORE_ID_TABLE", 1, CORE_4_INDEX, &CORE_ID_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SRAM_DUMMY_STORE", 1, CORE_4_INDEX, &SRAM_DUMMY_STORE_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_4_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_4_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_4, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_CFG_TABLE", 1, CORE_4_INDEX, &TCAM_IC_CFG_TABLE_4, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_GLOBAL_CFG", 1, CORE_4_INDEX, &FPM_GLOBAL_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TASK_IDX", 1, CORE_4_INDEX, &TASK_IDX_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TUNNELS_PARSING_CFG", 1, CORE_4_INDEX, &TUNNELS_PARSING_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_CFG_TABLE", 1, CORE_4_INDEX, &IPTV_CFG_TABLE_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_4_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "NAT_CACHE_CFG", 1, CORE_4_INDEX, &NAT_CACHE_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_4_INDEX, &IC_DEBUG_COUNTER_MODE_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_4_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_4_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_4_INDEX, &RX_MIRRORING_CONFIGURATION_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_4_INDEX, &INGRESS_FILTER_1588_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_CFG", 1, CORE_4_INDEX, &INGRESS_FILTER_CFG_4, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_4_INDEX, &PBIT_TO_QUEUE_TABLE_4, 65, 1, 1 },
#endif
#if defined BCM6836
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_4_INDEX, &RULE_BASED_ACTION_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_4_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_4_INDEX, &IPTV_ACTION_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "NATC_TBL_CFG", 1, CORE_4_INDEX, &NATC_TBL_CFG_4, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_4_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_4, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_4_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_4, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_CMD_TABLE", 1, CORE_4_INDEX, &TCAM_IC_CMD_TABLE_4, 6, 16, 1 },
#endif
#if defined BCM6836
	{ "TX_FLOW_TABLE", 1, CORE_4_INDEX, &TX_FLOW_TABLE_4, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_TABLE", 1, CORE_5_INDEX, &RX_FLOW_TABLE_5, 320, 1, 1 },
#endif
#if defined BCM6836
	{ "LAYER2_HEADER_COPY_MAPPING_TABLE", 1, CORE_5_INDEX, &LAYER2_HEADER_COPY_MAPPING_TABLE_5, 30, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_CONFIGURATION_TABLE", 1, CORE_5_INDEX, &IPTV_CONFIGURATION_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "DSCP_TO_PBITS_MAP_TABLE", 1, CORE_5_INDEX, &DSCP_TO_PBITS_MAP_TABLE_5, 4, 64, 1 },
#endif
#if defined BCM6836
	{ "PROCESSING_CPU_RX_SCRATCHPAD", 1, CORE_5_INDEX, &PROCESSING_CPU_RX_SCRATCHPAD_5, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_GLOBAL_REGISTERS_INIT", 1, CORE_5_INDEX, &RUNNER_GLOBAL_REGISTERS_INIT_5, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "GLOBAL_DSCP_TO_PBITS_TABLE", 1, CORE_5_INDEX, &GLOBAL_DSCP_TO_PBITS_TABLE_5, 1, 64, 1 },
#endif
#if defined BCM6836
	{ "VPORT_CFG_TABLE", 1, CORE_5_INDEX, &VPORT_CFG_TABLE_5, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_POOL_NUMBER_MAPPING_TABLE", 1, CORE_5_INDEX, &FPM_POOL_NUMBER_MAPPING_TABLE_5, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "VPORT_TO_DSCP_TO_PBITS_TABLE", 1, CORE_5_INDEX, &VPORT_TO_DSCP_TO_PBITS_TABLE_5, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_PROFILE_TABLE", 1, CORE_5_INDEX, &INGRESS_FILTER_PROFILE_TABLE_5, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "POLICER_PARAMS_TABLE", 1, CORE_5_INDEX, &POLICER_PARAMS_TABLE_5, 80, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_L2_REASON_TABLE", 1, CORE_5_INDEX, &INGRESS_FILTER_L2_REASON_TABLE_5, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_HANDLER_TABLE", 1, CORE_5_INDEX, &TCAM_IC_HANDLER_TABLE_5, 16, 1, 1 },
#endif
#if defined BCM6836
	{ "LAYER2_GRE_TUNNEL_TABLE", 1, CORE_5_INDEX, &LAYER2_GRE_TUNNEL_TABLE_5, 12, 1, 1 },
#endif
#if defined BCM6836
	{ "PBIT_TO_GEM_TABLE", 1, CORE_5_INDEX, &PBIT_TO_GEM_TABLE_5, 8, 8, 1 },
#endif
#if defined BCM6836
	{ "DUAL_STACK_LITE_TABLE", 1, CORE_5_INDEX, &DUAL_STACK_LITE_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IC_EXT_CONTEXT_TABLE", 1, CORE_5_INDEX, &IC_EXT_CONTEXT_TABLE_5, 512, 1, 1 },
#endif
#if defined BCM6836
	{ "DS_PACKET_BUFFER", 1, CORE_5_INDEX, &DS_PACKET_BUFFER_5, 8, 1, 1 },
#endif
#if defined BCM6836
	{ "TC_TO_QUEUE_TABLE", 1, CORE_5_INDEX, &TC_TO_QUEUE_TABLE_5, 65, 1, 1 },
#endif
#if defined BCM6836
	{ "REGISTERS_BUFFER", 1, CORE_5_INDEX, &REGISTERS_BUFFER_5, 32, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_FLOW_CONTEXT_DDR_ADDR", 1, CORE_5_INDEX, &RX_FLOW_CONTEXT_DDR_ADDR_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "NULL_BUFFER", 1, CORE_5_INDEX, &NULL_BUFFER_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_RX_INTERRUPT_ID_DDR_ADDR", 1, CORE_5_INDEX, &CPU_RX_INTERRUPT_ID_DDR_ADDR_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "BRIDGE_CFG_TABLE", 1, CORE_5_INDEX, &BRIDGE_CFG_TABLE_5, 3, 1, 1 },
#endif
#if defined BCM6836
	{ "DEFAULT_BRIDGE_CFG", 1, CORE_5_INDEX, &DEFAULT_BRIDGE_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "LOOPBACK_QUEUE_TABLE", 1, CORE_5_INDEX, &LOOPBACK_QUEUE_TABLE_5, 40, 1, 1 },
#endif
#if defined BCM6836
	{ "SYSTEM_CONFIGURATION", 1, CORE_5_INDEX, &SYSTEM_CONFIGURATION_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FORCE_DSCP", 1, CORE_5_INDEX, &FORCE_DSCP_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CORE_ID_TABLE", 1, CORE_5_INDEX, &CORE_ID_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "SRAM_DUMMY_STORE", 1, CORE_5_INDEX, &SRAM_DUMMY_STORE_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_DESCRIPTOR_TABLE", 1, CORE_5_INDEX, &CPU_FEED_RING_DESCRIPTOR_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_VPORT_TO_PROFILE_TABLE", 1, CORE_5_INDEX, &INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_5, 64, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_CFG_TABLE", 1, CORE_5_INDEX, &TCAM_IC_CFG_TABLE_5, 5, 1, 1 },
#endif
#if defined BCM6836
	{ "FPM_GLOBAL_CFG", 1, CORE_5_INDEX, &FPM_GLOBAL_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TASK_IDX", 1, CORE_5_INDEX, &TASK_IDX_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "TUNNELS_PARSING_CFG", 1, CORE_5_INDEX, &TUNNELS_PARSING_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_CFG_TABLE", 1, CORE_5_INDEX, &IPTV_CFG_TABLE_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_DDR_CTX_TABLE_ADDRESS", 1, CORE_5_INDEX, &IPTV_DDR_CTX_TABLE_ADDRESS_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "NAT_CACHE_CFG", 1, CORE_5_INDEX, &NAT_CACHE_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "IC_DEBUG_COUNTER_MODE", 1, CORE_5_INDEX, &IC_DEBUG_COUNTER_MODE_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "FLOW_BASED_ACTION_PTR_TABLE", 1, CORE_5_INDEX, &FLOW_BASED_ACTION_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "CPU_FEED_RING_INTERRUPT_THRESHOLD", 1, CORE_5_INDEX, &CPU_FEED_RING_INTERRUPT_THRESHOLD_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "RX_MIRRORING_CONFIGURATION", 1, CORE_5_INDEX, &RX_MIRRORING_CONFIGURATION_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_1588_CFG", 1, CORE_5_INDEX, &INGRESS_FILTER_1588_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "INGRESS_FILTER_CFG", 1, CORE_5_INDEX, &INGRESS_FILTER_CFG_5, 1, 1, 1 },
#endif
#if defined BCM6836
	{ "PBIT_TO_QUEUE_TABLE", 1, CORE_5_INDEX, &PBIT_TO_QUEUE_TABLE_5, 65, 1, 1 },
#endif
#if defined BCM6836
	{ "RULE_BASED_ACTION_PTR_TABLE", 1, CORE_5_INDEX, &RULE_BASED_ACTION_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "RULE_BASED_CONTEXT_ACTION_PTR_TABLE", 1, CORE_5_INDEX, &RULE_BASED_CONTEXT_ACTION_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "IPTV_ACTION_PTR_TABLE", 1, CORE_5_INDEX, &IPTV_ACTION_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "NATC_TBL_CFG", 1, CORE_5_INDEX, &NATC_TBL_CFG_5, 2, 1, 1 },
#endif
#if defined BCM6836
	{ "VLAN_ACTION_GPE_HANDLER_PTR_TABLE", 1, CORE_5_INDEX, &VLAN_ACTION_GPE_HANDLER_PTR_TABLE_5, 17, 1, 1 },
#endif
#if defined BCM6836
	{ "RUNNER_PROFILING_TRACE_BUFFER", 1, CORE_5_INDEX, &RUNNER_PROFILING_TRACE_BUFFER_5, 128, 1, 1 },
#endif
#if defined BCM6836
	{ "TCAM_IC_CMD_TABLE", 1, CORE_5_INDEX, &TCAM_IC_CMD_TABLE_5, 6, 16, 1 },
#endif
#if defined BCM6836
	{ "TX_FLOW_TABLE", 1, CORE_5_INDEX, &TX_FLOW_TABLE_5, 320, 1, 1 },
#endif
};
