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
#define RDD_LAN_VPORT_LAST   RDD_LAN7_VPORT

#define RDD_CPU0_VPORT       (RDD_LAN_VPORT_LAST + 1)
#define RDD_CPU_VPORT_FIRST  RDD_CPU0_VPORT
#define RDD_CPU1_VPORT       (RDD_LAN_VPORT_LAST + 2)
#define RDD_CPU2_VPORT       (RDD_LAN_VPORT_LAST + 3)
#define RDD_CPU3_VPORT       (RDD_LAN_VPORT_LAST + 4)
#define RDD_CPU4_VPORT       (RDD_LAN_VPORT_LAST + 5)
#define RDD_CPU5_VPORT       (RDD_LAN_VPORT_LAST + 6)
#define RDD_WLAN0_VPORT      RDD_CPU5_VPORT
#define RDD_CPU6_VPORT       (RDD_LAN_VPORT_LAST + 7)
#define RDD_WLAN1_VPORT      RDD_CPU6_VPORT
#define RDD_CPU7_VPORT       (RDD_LAN_VPORT_LAST + 8)
#define RDD_WLAN2_VPORT      RDD_CPU7_VPORT
#define RDD_CPU_VPORT_LAST   RDD_CPU7_VPORT
#define RDD_WAN1_VPORT       (RDD_VPORT_LAST - 3)
#define RDD_VIRTUAL_VPORT    (RDD_VPORT_LAST - 1)

#define RDD_CPU_VPORT_MASK ((1 << RDD_CPU0_VPORT) | (1 << RDD_CPU1_VPORT) | (1 << RDD_CPU2_VPORT) | \
    (1 << RDD_CPU3_VPORT) | (1 << RDD_CPU4_VPORT) | (1 << RDD_CPU5_VPORT) | (1 << RDD_CPU6_VPORT) | (1 << RDD_CPU7_VPORT))

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

#define INTERRUPT_COALESCING_THREAD_NUMBER IMAGE_1_CPU_IF_1_INTERRUPT_COALESCING_THREAD_NUMBER
#define CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER IMAGE_1_CPU_IF_1_CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER

/* Ingress classifier and VLAN actions */
#define RDD_US_IC_RULE_CFG_TABLE_SIZE                           128
#define RDD_DS_IC_RULE_CFG_TABLE_SIZE                           128
#define RDD_IC_SHARED_CONTEXT_TABLE_SIZE                        1024
#define RDD_DS_IC_CONTEXT_TABLE_SIZE                            RDD_IC_SHARED_CONTEXT_TABLE_SIZE
#define RDD_US_IC_CONTEXT_TABLE_SIZE                            RDD_IC_SHARED_CONTEXT_TABLE_SIZE
#define NUM_OF_GENERIC_RULE_CFG                                 4
#define RDD_VLAN_COMMAND_SKIP                                   128

#endif /* RDD_RUNNER_PROJ_DEFS_H_ */

