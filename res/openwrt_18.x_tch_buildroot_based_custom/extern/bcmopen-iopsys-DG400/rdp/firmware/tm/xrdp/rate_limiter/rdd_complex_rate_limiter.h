/*
   Copyright (c) 2015 Broadcom Corporation
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

#ifndef _RDD_COMPLEX_RATE_LIMITER_H
#define _RDD_COMPLEX_RATE_LIMITER_H

#include "rdd.h"

#define COMPLEX_RATE_LIMITER
#define COMPLEX_RATE_LIMITER_SIR_INIT_RATE          0
#define COMPLEX_RATE_LIMITER_PIR_INIT_RATE          0
#define MAX_INDEX_OF_COMPLEX_RL                     127

typedef enum
{
    RDD_RL_SIR,
    RDD_RL_PIR,
} rdd_complex_rl_bucket_t;

typedef enum
{
    rdd_complex_rl_queue = 0,
    rdd_complex_rl_basic_scheduler = 1,
    num_of_rdd_complex_rl_block = 2
} rdd_complex_rl_block_t;

typedef struct
{
    uint32_t sustain_budget;
    uint32_t peak_limit;
    uint32_t peak_rate;
    rdd_complex_rl_block_t type;
    uint8_t block_index;
} rdd_complex_rl_cfg_t;

/* API to RDPA level */
bdmf_error_t rdd_complex_rate_limiter_cfg(rdpa_traffic_dir dir, uint8_t rl_index, rdd_complex_rl_cfg_t *rl_cfg);
bdmf_error_t rdd_complex_rate_limiter_remove(rdpa_traffic_dir dir, uint8_t rl_index);

#endif
