/*
    <:copyright-BRCM:2015:DUAL/GPL:standard
    
       Copyright (c) 2015 Broadcom 
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

#include "bdmf_data_types.h"
#include "bdmf_errno.h"
#include "rdp_drv_proj_cntr.h"

bdmf_boolean cntr_group_0_occupied[CNTR0_CNTR_NUM]={};
bdmf_boolean cntr_group_1_occupied[CNTR1_CNTR_NUM]={};
bdmf_boolean cntr_group_2_occupied[CNTR2_CNTR_NUM]={};
bdmf_boolean cntr_group_3_occupied[CNTR3_CNTR_NUM]={};
bdmf_boolean cntr_group_4_occupied[CNTR4_CNTR_NUM]={};
bdmf_boolean cntr_group_5_occupied[CNTR5_CNTR_NUM]={};
bdmf_boolean cntr_group_6_occupied[CNTR6_CNTR_NUM]={};
bdmf_boolean cntr_group_7_occupied[CNTR7_CNTR_NUM]={};
bdmf_boolean cntr_group_8_occupied[CNTR8_CNTR_NUM]={};
bdmf_boolean cntr_group_9_occupied[CNTR9_CNTR_NUM]={};

cntr_group_cfg_t cntr_group_cfg[CNTR_GROUPS_NUMBER] = {
#ifdef BCM6858_A0
     {RX_FLOW_CNTR_GROUP_ID, cntr_group_0_occupied, CNTR0_CNTR_NUM,
      {{0, CNTR0_CNPL0_BASE_ADDR, CNTR0_CNPL0_CNTR_SIZE, CNTR0_CNPL0_CNTR_TYPE, 1,  0, 1},
       {1, CNTR0_CNPL1_BASE_ADDR, CNTR0_CNPL1_CNTR_SIZE, CNTR0_CNPL1_CNTR_TYPE, 1,  0, 1},
       {}}},
     {TX_FLOW_CNTR_GROUP_ID, cntr_group_1_occupied, CNTR1_CNTR_NUM,
      {{2, CNTR1_CNPL2_BASE_ADDR, CNTR1_CNPL2_CNTR_SIZE, CNTR1_CNPL2_CNTR_TYPE, 1,  0, 1},
       {},
       {}}},
#else
     {RX_FLOW_CNTR_GROUP_ID, cntr_group_0_occupied, CNTR0_CNTR_NUM,
      {{0, CNTR0_CNPL0_BASE_ADDR, CNTR0_CNPL0_CNTR_SIZE, CNTR0_CNPL0_CNTR_TYPE, 1,  1, 1},
       {1, CNTR0_CNPL1_BASE_ADDR, CNTR0_CNPL1_CNTR_SIZE, CNTR0_CNPL1_CNTR_TYPE, 1,  1, 1},
       {}}},
     {TX_FLOW_CNTR_GROUP_ID, cntr_group_1_occupied, CNTR1_CNTR_NUM,
      {{2, CNTR1_CNPL2_BASE_ADDR, CNTR1_CNPL2_CNTR_SIZE, CNTR1_CNPL2_CNTR_TYPE, 1,  1, 1},
       {},
       {}}},
#endif
     {TCAM_IPTV_DEF_CNTR_GROUP_ID, cntr_group_2_occupied, CNTR2_CNTR_NUM,
      {{3, CNTR2_CNPL3_BASE_ADDR, CNTR2_CNPL3_CNTR_SIZE, CNTR2_CNPL3_CNTR_TYPE, 1,  0, 1},
       {},
       {}}},
     {VARIOUS_CNTR_GROUP_ID, cntr_group_3_occupied, CNTR3_CNTR_NUM,
      {{4, CNTR3_CNPL4_BASE_ADDR, CNTR3_CNPL4_CNTR_SIZE, CNTR3_CNPL4_CNTR_TYPE, 1,  0, 1},
       {},
       {}}},
     {GENERAL_CNTR_GROUP_ID, cntr_group_4_occupied, CNTR4_CNTR_NUM,
      {{5, CNTR4_CNPL5_BASE_ADDR, CNTR4_CNPL5_CNTR_SIZE, CNTR4_CNPL5_CNTR_TYPE, 1,  0, 1},
       {},
       {}}},
     {US_TX_QUEUE_CNTR_GROUP_ID, cntr_group_5_occupied, CNTR5_CNTR_NUM,
      {{6, CNTR5_CNPL6_BASE_ADDR, CNTR5_CNPL6_CNTR_SIZE, CNTR5_CNPL6_CNTR_TYPE, 1,  0, 1},
       {},
       {}}},
     {DS_TX_QUEUE_CNTR_GROUP_ID, cntr_group_6_occupied, CNTR6_CNTR_NUM,
      {{7, CNTR6_CNPL7_BASE_ADDR, CNTR6_CNPL7_CNTR_SIZE, CNTR6_CNPL7_CNTR_TYPE, 1,  0, 1},
       {},
       {}}},
     {CPU_RX_CNTR_GROUP_ID, cntr_group_7_occupied, CNTR7_CNTR_NUM,
      {{8, CNTR7_CNPL8_BASE_ADDR, CNTR7_CNPL8_CNTR_SIZE, CNTR7_CNPL8_CNTR_TYPE, 0,  0, 1},
       {},
       {}}},
     {CPU_RX_METER_DROP_CNTR_GROUP_ID, cntr_group_8_occupied, CNTR8_CNTR_NUM,
      {{9, CNTR8_CNPL9_BASE_ADDR, CNTR8_CNPL9_CNTR_SIZE, CNTR8_CNPL9_CNTR_TYPE, 1,  1, 1},
       {},
       {}}},
     {POLICER_CNTR_GROUP_ID, cntr_group_9_occupied, CNTR9_CNTR_NUM,
      {{10, CNTR9_CNPL10_BASE_ADDR, CNTR9_CNPL10_CNTR_SIZE, CNTR9_CNPL10_CNTR_TYPE, 1,  0, 1},
       {11, CNTR9_CNPL11_BASE_ADDR, CNTR9_CNPL11_CNTR_SIZE, CNTR9_CNPL11_CNTR_TYPE, 1,  0, 1},
       {12, CNTR9_CNPL12_BASE_ADDR, CNTR9_CNPL12_CNTR_SIZE, CNTR9_CNPL12_CNTR_TYPE, 1,  0, 1}}}
};

