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


#include "rdd_runner_tasks_auto.h"


char *image_task_names[5][16] = {
	{"DS_TM_FLOW_CONTROL","DS_TM_BUDGET_ALLOCATION","DS_TM_UPDATE_FIFO","DS_TM_FLUSH","DS_TM_SCHEDULING_TASK","DS_TM_FRAG0","DS_TM_FRAG1","DS_TM_FRAG2","DS_TM_FRAG3"},
	{"REASSEMBLY_G9991_0","REASSEMBLY_G9991_1","REASSEMBLY_G9991_2","REASSEMBLY_G9991_3"},
	{"CPU_IF_2_CPU_TX_UPDATE_FIFO_EGRESS","CPU_IF_2_CPU_TX_UPDATE_FIFO_INGRESS","CPU_IF_2_CPU_TX_EGRESS","CPU_IF_2_CPU_TX_INGRESS","CPU_IF_2_REPORTING","CPU_IF_2_WAN_DIRECT","CPU_IF_2_CPU_RX","CPU_IF_2_DIRECT_SYSTEM_PORT","CPU_IF_2_CPU_RX_UPDATE_FIFO","CPU_IF_2_CPU_TX_RECYCLE","CPU_IF_2_INTERRUPT_COALESCING","CPU_IF_2_CPU_RX_METER_BUDGET_ALLOCATOR","CPU_IF_2_CPU_RECYCLE","CPU_IF_2_CPU_RX_COPY","CPU_IF_2_CPU_RX_COPY_UPDATE_FIFO"},
	{"US_TM_BUDGET_ALLOCATION","US_TM_OVL_BUDGET_ALLOCATION","US_TM_UPDATE_FIFO","US_TM_UPDATE_FIFO_EPON","US_TM_FLUSH","US_TM_WAN","US_TM_WAN_EPON"},
	{"PROCESSING_0","PROCESSING_1","PROCESSING_2","PROCESSING_3","PROCESSING_4","PROCESSING_5","PROCESSING_6","PROCESSING_7"}
	};

