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
	{"DS_TM_WAN_DIRECT","DS_TM_BUDGET_ALLOCATION","DS_TM_UPDATE_FIFO","DS_TM_TX_TASK","DS_TM_FLUSH"},
	{"IMAGE_1_PROCESSING0","IMAGE_1_PROCESSING1","IMAGE_1_PROCESSING2","IMAGE_1_PROCESSING3","IMAGE_1_PROCESSING4","IMAGE_1_PROCESSING5","IMAGE_1_PROCESSING6","IMAGE_1_PROCESSING7","IMAGE_1_CPU_RX","IMAGE_1_CPU_RX_UPDATE_FIFO","IMAGE_1_INTERRUPT_COALESCING","IMAGE_1_CPU_RX_METER_BUDGET_ALLOCATOR","IMAGE_1_CPU_RECYCLE","IMAGE_1_CPU_RX_COPY","IMAGE_1_CPU_RX_COPY_UPDATE_FIFO"},
	{"IMAGE_2_PROCESSING0","IMAGE_2_PROCESSING1","IMAGE_2_PROCESSING2","IMAGE_2_PROCESSING3","IMAGE_2_PROCESSING4","IMAGE_2_PROCESSING5","IMAGE_2_PROCESSING6","IMAGE_2_PROCESSING7","IMAGE_2_CPU_TX_UPDATE_FIFO_EGRESS","IMAGE_2_CPU_TX_UPDATE_FIFO_INGRESS","IMAGE_2_CPU_RECYCLE","IMAGE_2_CPU_TX_EGRESS","IMAGE_2_CPU_TX_INGRESS","IMAGE_2_INTERRUPT_COALESCING"},
	{"US_TM_BUDGET_ALLOCATION","US_TM_OVL_BUDGET_ALLOCATION","US_TM_UPDATE_FIFO","US_TM_UPDATE_FIFO_EPON","US_TM_FLUSH","US_TM_WAN","US_TM_WAN_EPON","US_TM_REPORTING"},
	{"PROCESSING_0","PROCESSING_1","PROCESSING_2","PROCESSING_3","PROCESSING_4","PROCESSING_5","PROCESSING_6","PROCESSING_7"}
	};

