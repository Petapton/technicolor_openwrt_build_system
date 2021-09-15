/*
 * <:copyright-BRCM:2014:DUAL/GPL:standard
 * 
 *    Copyright (c) 2014 Broadcom 
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
#ifndef BCM_MISC_HW_INIT_H
#define BCM_MISC_HW_INIT_H

#ifdef _CFE_
#include "lib_types.h"
#else
#include <linux/types.h>
#endif
int bcm_misc_hw_init(void);
int rdp_pre_init(void);
int rdp_post_init(void);
int rdp_shut_down(void);
uint32_t pmu_clk(uint8_t mdiv_shift);

#if defined(CONFIG_BCM960333) && defined(CONFIG_PCI)
void stop_100mhz_afe_clock(void);
#endif

#if defined (CONFIG_BCM96858) || defined(_BCM96858_) 
#if (CONFIG_BCM_CHIP_REV == 0x6858B0)
#define UCB_NODE_ID_SLV_SYS     0
#define UCB_NODE_ID_MST_PCIE0   3
#define UCB_NODE_ID_SLV_PCIE0   4
#define UCB_NODE_ID_MST_PCIE2   5
#define UCB_NODE_ID_SLV_PCIE2   6
#define UCB_NODE_ID_MST_SATA    UCB_NODE_ID_MST_PCIE2
#define UCB_NODE_ID_SLV_SATA    UCB_NODE_ID_SLV_PCIE2
#define UCB_NODE_ID_MST_USB     14
#define UCB_NODE_ID_SLV_USB     15
#define UCB_NODE_ID_SLV_LPORT   19
#define UCB_NODE_ID_SLV_WAN     21
#else
#define UCB_NODE_ID_SLV_SYS     0
#define UCB_NODE_ID_MST_PCIE0   3
#define UCB_NODE_ID_SLV_PCIE0   4
#define UCB_NODE_ID_MST_PCIE1   5
#define UCB_NODE_ID_SLV_PCIE1   6
#define UCB_NODE_ID_MST_PCIE2   10
#define UCB_NODE_ID_SLV_PCIE2   11
#define UCB_NODE_ID_MST_SATA    12
#define UCB_NODE_ID_SLV_SATA    13
#define UCB_NODE_ID_MST_USB     14
#define UCB_NODE_ID_SLV_USB     15
#define UCB_NODE_ID_SLV_MEMC    16
#define UCB_NODE_ID_MST_APM     19
#define UCB_NODE_ID_SLV_APM     20
#define UCB_NODE_ID_SLV_WAN     21
#define UCB_NODE_ID_SLV_LPORT   24
#endif

typedef enum
{
    MST_PORT_NODE_PCIE0,
    MST_PORT_NODE_PCIE1,
    MST_PORT_NODE_B53,
    MST_PORT_NODE_PCIE2,
    MST_PORT_NODE_SATA,
    MST_PORT_NODE_USB,
    MST_PORT_NODE_PMC,
    MST_PORT_NODE_APM,
    MST_PORT_NODE_PER,
    MST_PORT_NODE_DMA0,
    MST_PORT_NODE_DMA1,
    MST_PORT_NODE_RQ0,
    MST_PORT_NODE_RQ1,
    MST_PORT_NODE_RQ2,
    MST_PORT_NODE_RQ3,
    MST_PORT_NODE_NATC,
    MST_PORT_NODE_DQM,
    MST_PORT_NODE_QM
}MST_PORT_NODE;

int ubus_master_set_rte_addr(MST_PORT_NODE node, int port, int val);
int configure_biu_pid_to_queue(void);
#endif


#if defined (CONFIG_BCM96836) || defined(_BCM96836_)
#define UCB_NODE_ID_SLV_SYS     0
#define UCB_NODE_ID_MST_PCIE0   3
#define UCB_NODE_ID_SLV_PCIE0   4
#define UCB_NODE_ID_MST_SATA    10
#define UCB_NODE_ID_SLV_SATA    11
#define UCB_NODE_ID_MST_USB     14
#define UCB_NODE_ID_SLV_USB     15
#define UCB_NODE_ID_SLV_MEMC    16

extern unsigned int g_board_size_power_of_2;

typedef enum
{
    MST_PORT_NODE_PCIE0, //0
    MST_PORT_NODE_SATA,  //1
    MST_PORT_NODE_USB,   //2
    MST_PORT_NODE_PER,   //3
    MST_PORT_NODE_PERDMA,//4
    MST_PORT_NODE_DMA0,  //5   
    MST_PORT_NODE_RQ0,   //6
    MST_PORT_NODE_NATC,  //7
    MST_PORT_NODE_DQM,   //8   
    MST_PORT_NODE_QM,    //9
    MST_PORT_NODE_LAST   //10
}MST_PORT_NODE;
#endif

#if defined (CONFIG_BCM96858) || defined(_BCM96858_) || defined (CONFIG_BCM96836) || defined(_BCM96836_)
int ubus_master_decode_wnd_cfg(MST_PORT_NODE node, int win, unsigned int phys_addr, unsigned int size_power_of_2, int port_id, unsigned int cache_bit_en);
int log2_32 (unsigned int value);
int ubus_master_set_token_credits(MST_PORT_NODE node, int token, int credits);

void ubus_deregister_port(int ucbid);
void ubus_register_port(int ucbid);

int ubus_remap_to_biu_cfg_queue_srcpid(unsigned long lut_idx, unsigned int *p_srcpid_queus_value);
int ubus_remap_to_biu_cfg_queue_depth(unsigned long q_depth_idx, unsigned int *p_depth_queus_value);
int ubus_remap_to_biu_cfg_queue_thresh(unsigned long q_depth_idx, unsigned int *p_depth_queus_value);
int ubus_remap_to_biu_cfg_cir_incr(unsigned long q_depth_idx, unsigned int *p_cirinc_queus_value);
int ubus_remap_to_biu_cfg_ref_cnt(unsigned long q_depth_idx, unsigned int *p_cirinc_queus_value);

#endif

#endif//BCM_MISC_HW_INIT_H
