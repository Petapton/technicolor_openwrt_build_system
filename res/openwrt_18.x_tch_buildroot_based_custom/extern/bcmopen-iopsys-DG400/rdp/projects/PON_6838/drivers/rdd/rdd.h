/*
    <:copyright-BRCM:2013:DUAL/GPL:standard
    
       Copyright (c) 2013 Broadcom 
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

#ifndef _BL_LILAC_DRV_RUNNER_H
#define _BL_LILAC_DRV_RUNNER_H

#if defined(FIRMWARE_INIT)

#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "netinet/in.h"

#else

#include "bl_os_wraper.h"
#include "pmc_drv.h" 

#ifdef LINUX_KERNEL

#include <access_macros.h>
#include <linux/string.h>

#else

#include "access_macros.h"

#endif /* LINUX_KERNEL */


#endif /* defined(FIRMWARE_INIT) */

#ifdef _CFE_
#define RDD_VIRT_TO_PHYS(_addr)                 K0_TO_PHYS((uint32_t)_addr)
#elif defined(__KERNEL__)
#define RDD_VIRT_TO_PHYS(_addr)                 CPHYSADDR(_addr)
#else
#define RDD_VIRT_TO_PHYS(_addr)		        ((uint32_t)_addr)
#endif

#ifndef __PACKING_ATTRIBUTE_STRUCT_END__
#include "packing.h"
#endif
#include "rdp_runner.h"
#include "rdpa_types.h"

#ifndef RDD_BASIC
#if !defined(FIRMWARE_INIT) || defined(BDMF_SYSTEM_SIM)
#include "bdmf_system.h"
#else
#define bdmf_sysb void *
static inline void *bdmf_sysb_data(const bdmf_sysb sysb)
{
    return ((void *)sysb);
}
#endif
#include "rdpa_ip_class_basic.h"
#include "rdpa_ingress_class_basic.h"
#include "rdpa_cpu_basic.h"
#endif

#if !defined(FIRMWARE_INIT) || defined(BDMF_SYSTEM_SIM)

#include "rdp_drv_bpm.h"

/* temporary until complete stratosphere removal */

#ifndef RDD_BASIC

#undef malloc
/* Full RDD as part of RDPA */
#define malloc(s) bdmf_alloc(s)

#else

#define bdmf_fastlock int
#define DEFINE_BDMF_FASTLOCK(lock) int lock = 0

#if !defined _CFE_

#undef malloc
#undef printf
/* Minimal RDD for builtr-in kernel drivers */
#define malloc(s) kmalloc(s, GFP_KERNEL)
#define printf    printk

#endif /* !defined _CFE_ */

#endif /* RDD_BASIC */

#else

#define bdmf_fastlock int
#define DEFINE_BDMF_FASTLOCK(lock) int lock = 0

#endif /* !defined(FIRMWARE_INIT) */

/* task addresses labels from fw compilation */
#include "rdd_runner_a_labels.h"
#include "rdd_runner_b_labels.h"
#include "rdd_runner_c_labels.h"
#include "rdd_runner_d_labels.h"

#include "rdd_defs.h"
#include "rdd_runner_defs_auto.h"
#include "rdd_runner_defs.h"
#include "rdd_data_structures_auto.h"
#include "rdd_data_structures.h"
#include "rdd_common.h"
#include "rdd_cpu.h"
#include "rdd_init.h"
#ifndef G9991
#include "rdd_wlan_mcast.h"
#endif
#ifndef RDD_BASIC
#include "rdd_router.h"
#include "rdd_bridge.h"
#include "rdd_interworking.h"
#endif
#include "rdd_lookup_engine.h"
#include "rdd_tm.h"
#endif /* _BL_LILAC_DRV_RUNNER_H */

