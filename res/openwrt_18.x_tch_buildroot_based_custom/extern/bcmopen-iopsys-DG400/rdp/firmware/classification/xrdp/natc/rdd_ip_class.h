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
#ifndef _RDD_IP_CLASS_H
#define _RDD_IP_CLASS_H

#include "rdd.h"
#include "rdd_common.h"
#include "rdd_ip_class_inline.h"
#include "rdd_defs.h"

void rdd_ip_class_result_entry_compose(rdd_fc_context_t *ctx, uint8_t *entry, rdpa_traffic_dir dir);
void rdd_ip_class_result_entry_decompose(rdd_fc_context_t *ctx, uint8_t *entry);
void rdd_ip_class_natc_cfg(uint8_t tbl_idx, uint32_t key_addr_hi, uint32_t key_addr_lo, uint32_t res_addr_hi, uint32_t res_addr_lo);

#endif /* RDD_IP_CLASS_H_ */
