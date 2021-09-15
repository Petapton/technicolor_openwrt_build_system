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
#ifndef _RDP_DRV_PROJ_POLICER_H_
#define _RDP_DRV_PROJ_POLICER_H_

#include "rdp_drv_proj_cntr.h"

/****************************************************************************** 
  * 
  * POLICER GROUP 0 :
  * --------------
  * Structure: 8B 
  * Parameters: 8B 
  *  
  * Usage: 
  *   Policer   | amount
  *   -------------------
  *   Double    | 80
  *  
  *  
*******************************************************************************/
#define CNPL_POLICER_NUM  80
#define CNPL_POLICER_SIZE  8

/* first group defined as dual bucket */
/* to set single bucket parameters of second bucket should be zero */
#define CNPL_GROUP_DUAL_BUCKET_INDEX  0

/* second group not used. workaround so policer index 0 won't be runover
   by the second group*/
#define CNPL_GROUP_ONE_INDEX 1

/* POLICER GROUP 0: Double */
#define CNPL_POLICER_BASE_ADDR  CNTR_END_ADDR
#define CNPL_POLICER_END_ADDR  (CNPL_POLICER_BASE_ADDR + ((CNPL_POLICER_NUM * CNPL_POLICER_SIZE) >> 3))

#define CNPL_POLICER_PARAM_BASE_ADDR  CNPL_POLICER_END_ADDR
#define CNPL_POLICER_PARAM_END_ADDR  (CNPL_POLICER_PARAM_BASE_ADDR + ((CNPL_POLICER_NUM * CNPL_POLICER_SIZE) >> 3))


#ifdef BCM6858_A0
#define CNPL_MEMROY_END_ADDR  ((3200*4) >> 3)
#else
#define CNPL_MEMROY_END_ADDR  ((3584*4) >> 3)
#endif
#endif

