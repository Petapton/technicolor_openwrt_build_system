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

#ifndef RDD_RUNNER_PROJ_DEFS_H_
#define RDD_RUNNER_PROJ_DEFS_H_

#define NUM_OF_GLOBAL_REGS                                      8
#define NUM_OF_MAIN_RUNNER_THREADS                              16
#define NUM_OF_RUNNER_CORES                                     16

#define MAX_FRAG_SIZE                                           128

/* TIMER DEFINES */
#define GHOST_REPORTING_TIMER_INTERVAL_IN_USEC                  40
#define FLUSH_TASK_TIMER_INTERVAL_IN_USEC                       15
#define RATE_LIMITER_TIMER_PERIOD_IN_USEC                       1000
#define CPU_RX_METER_TIMER_PERIOD                               10000
#define CPU_RX_METER_TIMER_PERIOD_IN_USEC                       CPU_RX_METER_TIMER_PERIOD
#define GHOST_REPORTING_TIMER_INTERVAL                          GHOST_REPORTING_TIMER_INTERVAL_IN_USEC
#define FLUSH_TASK_TIMER_INTERVAL                               FLUSH_TASK_TIMER_INTERVAL_IN_USEC
#define RATE_LIMITER_TIMER_PERIOD                               RATE_LIMITER_TIMER_PERIOD_IN_USEC

/* NATC */
#define NATC_16BYTE_KEY_MASK                                    0xc000

#define RDD_WAN0_VPORT       RDD_VPORT_ID_0
#define RDD_LAN0_VPORT       RDD_VPORT_ID_1
#define RDD_LAN1_VPORT       RDD_VPORT_ID_2
#define RDD_LAN2_VPORT       RDD_VPORT_ID_3
#define RDD_LAN3_VPORT       RDD_VPORT_ID_4
#define RDD_LAN4_VPORT       RDD_VPORT_ID_5
#define RDD_LAN5_VPORT       RDD_VPORT_ID_6
#define RDD_LAN6_VPORT       RDD_VPORT_ID_7
#define RDD_LAN7_VPORT       RDD_VPORT_ID_8
#define RDD_LAN8_VPORT       RDD_VPORT_ID_9
#define RDD_LAN9_VPORT       RDD_VPORT_ID_10
#define RDD_LAN10_VPORT       RDD_VPORT_ID_11
#define RDD_LAN11_VPORT       RDD_VPORT_ID_12
#define RDD_LAN12_VPORT       RDD_VPORT_ID_13
#define RDD_LAN13_VPORT       RDD_VPORT_ID_14
#define RDD_LAN14_VPORT       RDD_VPORT_ID_15
#define RDD_LAN15_VPORT       RDD_VPORT_ID_16
#define RDD_LAN16_VPORT       RDD_VPORT_ID_17
#define RDD_LAN17_VPORT       RDD_VPORT_ID_18
#define RDD_LAN18_VPORT       RDD_VPORT_ID_19
#define RDD_LAN19_VPORT       RDD_VPORT_ID_20
#define RDD_LAN20_VPORT       RDD_VPORT_ID_21
#define RDD_LAN21_VPORT       RDD_VPORT_ID_22
#define RDD_LAN22_VPORT       RDD_VPORT_ID_23
#define RDD_LAN23_VPORT       RDD_VPORT_ID_24
#define RDD_LAN24_VPORT       RDD_VPORT_ID_25
#define RDD_LAN25_VPORT       RDD_VPORT_ID_26
#define RDD_LAN26_VPORT       RDD_VPORT_ID_27
#define RDD_LAN27_VPORT       RDD_VPORT_ID_28
#define RDD_LAN28_VPORT       RDD_VPORT_ID_29
#define RDD_LAN29_VPORT       RDD_VPORT_ID_30
#define RDD_LAN30_VPORT       RDD_VPORT_ID_31
#define RDD_LAN31_VPORT       RDD_VPORT_ID_32
#define RDD_LAN32_VPORT       RDD_VPORT_ID_33
#define RDD_LAN33_VPORT       RDD_VPORT_ID_34
#define RDD_LAN34_VPORT       RDD_VPORT_ID_35
#define RDD_LAN35_VPORT       RDD_VPORT_ID_36

#define RDD_LAN_VPORT_LAST   RDD_LAN35_VPORT

#define RDD_WAN1_VPORT       (RDD_VPORT_LAST - 3)
#define RDD_VIRTUAL_VPORT    (RDD_VPORT_LAST - 1)

#define RDD_CPU0_VPORT       (RDD_LAN_VPORT_LAST + 1)
#define RDD_CPU_VPORT_FIRST  RDD_CPU0_VPORT
#define RDD_CPU_VPORT_LAST   RDD_CPU0_VPORT

/* TM */
#define DS_TM_UPDATE_FIFO_THREAD_NUMBER  IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER
#define US_TM_UPDATE_FIFO_THREAD_NUMBER  IMAGE_3_US_TM_UPDATE_FIFO_THREAD_NUMBER

/* REPORTING */
#define REPORTING_THREAD_NUMBER     IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER
#define REPORTING_COUNTER_ADDRESS   IMAGE_2_REPORTING_COUNTER_TABLE_ADDRESS

/* Images */
#define processing_image    image_4

/* CPU TX */
#define RECYCLE_INTERRUPT_COALESCING_THREAD_NUMBER IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER

/* Ingress Filters */
#define INGRESS_FILTER_L2_REASON_TABLE_SIZE RDD_IMAGE_4_INGRESS_FILTER_L2_REASON_TABLE_SIZE

#define INTERRUPT_COALESCING_THREAD_NUMBER IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER
#define CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER IMAGE_2_CPU_IF_2_CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER

/* Ingress classifier and VLAN actions */
#define RDD_US_IC_RULE_CFG_TABLE_SIZE                           128
#define RDD_DS_IC_RULE_CFG_TABLE_SIZE                           128
#define RDD_IC_SHARED_CONTEXT_TABLE_SIZE                        512
#define RDD_DS_IC_CONTEXT_TABLE_SIZE                            RDD_IC_SHARED_CONTEXT_TABLE_SIZE
#define RDD_US_IC_CONTEXT_TABLE_SIZE                            RDD_IC_SHARED_CONTEXT_TABLE_SIZE
#define NUM_OF_GENERIC_RULE_CFG                                 4
#define RDD_VLAN_COMMAND_SKIP                                   128

#endif /* RDD_RUNNER_PROJ_DEFS_H_ */

