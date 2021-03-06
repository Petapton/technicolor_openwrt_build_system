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

#ifndef _RDD_TCAM_IC_H
#define _RDD_TCAM_IC_H

#include <rdp_drv_tcam.h>
#include "rdd_defs.h"
#include "rdd_stubs.h"
#include "rdd_platform.h"

/** Ingress set id */
typedef rdd_tcam_ic_module rdd_tcam_table_id;

/** Max number of classification tables */
#define RDD_TCAM_MAX_TABLES       (TCAM_IC_MODULE_LAST + 1)

/** Max number of generic fields per table */
#define RDD_TCAM_MAX_GEN_FIELDS   4

/** Max number of generic fields per rule */
#define RDD_TCAM_MAX_GEN_FIELDS_PER_RULE   2

/** IC table parameters */
typedef struct rdd_tcam_table_parm
{
    uint32_t max_cmds;                  /* Max number of FW commands */
    bdmf_boolean invert_match;          /* TRUE = invert match when making forward/drop/host decision */
    rdd_tcam_ic_module module_id;       /* FW module id */
    uint16_t scratch_offset;            /* TCAM scratchpad offset from PACKET_SCRATCH */
} rdd_tcam_table_parm_t;


/*****************************************************************************************
 * This module is responsible for
 * - lookup key management. It maintains list of IC fields that are in use or were in use
 *   per classification type. This information is used to build low-level TCAM key.
 * - FW key builder command management. It builds per classification type sets of
 *   instructions that FW uses to build lookup key on packet ingress
 *****************************************************************************************/


/****************************************************************************************
 * Initialize tcam_ic module instance
 * \param[in]   module          Module to be initialized
 * \returns: 0 if succesful
 * The function calls rdd_tcam_table_create internally
 *****************************************************************************************/
int rdd_tcam_module_init(const rdd_module_t *module);


/****************************************************************************************
 * Create IC table
 * \param[in]   table_id        Classification table id
 * \param[in]   parm            Classification table parameters
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_PARM - error in parameters
 * - BDMF_ERR_ALREADY - table already exists
 *****************************************************************************************/
bdmf_error_t rdd_tcam_table_create(rdd_tcam_table_id table_id, const rdd_tcam_table_parm_t *table_parms);


/****************************************************************************************
 * Destroy IC table
 * \param[in]   table_id        Classification table id
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_PARM - error in parameters
 * - BDMF_ERR_NOENT - table doesn't exist
 * - BDMF_ERR_STATE - table is busy (contains entries)
 *****************************************************************************************/
bdmf_error_t rdd_tcam_table_destroy(rdd_tcam_table_id table_id);


/****************************************************************************************
 * Set "invert_match" property
 * \param[in]   table_id        Classification table id
 * \param[in]   invert_match    TRUE=Invert match
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_PARM - error in parameters
 * - BDMF_ERR_NOENT - table doesn't exist
 * - BDMF_ERR_STATE - table is busy (contains entries)
 *****************************************************************************************/
bdmf_error_t rdd_tcam_table_invert_match_set(rdd_tcam_table_id table_id, bdmf_boolean invert_match);


/****************************************************************************************
 * Get "invert_match" property
 * \param[in]   table_id        Classification table id
 * \param[out]  invert_match    TRUE=Invert match
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_PARM - error in parameters
 * - BDMF_ERR_NOENT - table doesn't exist
 *****************************************************************************************/
bdmf_error_t rdd_tcam_table_invert_match_get(rdd_tcam_table_id table_id, bdmf_boolean *invert_match);


/****************************************************************************************
 * Add ingress classification rule.
 *
 * This function builds low-level TCAM key. If there is a change in cumulative list
 * of active IC classification fields, it also updates list of FW instructions
 * that are used to build lookup key on ingress.
 *
 * The expected high-level "add ingress classification rule" control flow is
 * 1) rdd_ic_rule_add() --> tcam_key, tcam_mask
 * 2) drv_tcam_rule_add(rule_priority, tcam_key, tcam_mask)
 *
 * \param[in]   table_id        Classification table id
 * \param[in]   rule_key_mask   Bitmask of active fields in rule_key
 * \param[in]   gen_indexes     Generic key index array
 * \param[in]   rule_key        Key fields
 * \param[out]  tcam_key        Low-level TCAM key
 * \param[out]  tcam_mask       Low-level TCAM mask
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_TOO_MANY - too many active fields. FW table overflow
 * - BDMF_ERR_OVERFLOW - 256 bit key overflow
 * - BDMF_ERR_PARM - error in parameters
 * - BDMF_ERR_NOENT - table doesn't exist. Must be created first
 *****************************************************************************************/
bdmf_error_t rdd_tcam_rule_add(rdd_tcam_table_id table_id, rdpa_ic_fields rule_key_mask,
    const uint8_t gen_indexes[], const rdpa_ic_key_t *rule_key,
    rdp_tcam_key_area_t *tcam_key, rdp_tcam_key_area_t *tcam_mask);


/****************************************************************************************
 * Get low-level TCAM key and mask for existing rule.
 *
 * \param[in]   table_id        Classification table id
 * \param[in]   rule_key_mask   Bitmask of active fields in rule_key
 * \param[in]   rule_key        Key fields
 * \param[in]   gen_indexes     Generic key index array
 * \param[out]  tcam_key        Low-level TCAM key
 * \param[out]  tcam_mask       Low-level TCAM mask
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_PARM - error in parameters
 *****************************************************************************************/
bdmf_error_t rdd_tcam_rule_key_get(rdd_tcam_table_id table_id, rdpa_ic_fields rule_key_mask,
    const uint8_t gen_indexes[], const rdpa_ic_key_t *rule_key,
    rdp_tcam_key_area_t *tcam_key, rdp_tcam_key_area_t *tcam_mask);


/****************************************************************************************
 * Delete ingress classification rule
 *
 * This function updates list of FW instructions if there is a change in
 * per rule type list of active classification fields.
 * Note that the same classification field can be referenced by multiple flows.
 * Classification field becomes inactive only when it is not referenced.
 *
 * The expected high-level "delete ingress classification rule" control flow is
 * 1) rdd_ic_rule_key_get() --> tcam_key, tcam_mask
 * 2) drv_tcam_rule_delete(tcam_key, tcam_mask)
 * 3) rdd_ic_rule_delete()
 * \param[in]   table_id        Classification table id
 * \param[in]   rule_key_mask   Bitmask of active fields
 * \param[in]   gen_indexes     Generic key index array
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_PARM - error in parameters
 *****************************************************************************************/
bdmf_error_t rdd_tcam_rule_delete(rdd_tcam_table_id table_id, rdpa_ic_fields rule_key_mask,
    const uint8_t gen_indexes[]);


/****************************************************************************************
 * Set generic key configuration
 *
 * \param[in]   table_id        Classification table id
 * \param[in]   gen_index       Generic field index 0..RDD_IC_MAX_GEN_FIELDS-1
 * \param[in]   cfg             Configuration
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_PARM - error in parameters
 * - BDMF_ERR_STATE - field is in use (referenced by classification rule)
 * - BDMF_ERR_NOENT - table doesn't exist. Must be created first
 *****************************************************************************************/
bdmf_error_t rdd_tcam_generic_key_set(rdd_tcam_table_id table_id, uint8_t gen_index,
    const rdpa_ic_gen_rule_cfg_t *cfg);


/****************************************************************************************
 * Get generic key configuration
 *
 * \param[in]   table_id        Classification table id
 * \param[in]   gen_index       Generic field index 0..RDD_IC_MAX_GEN_FIELDS-1
 * \param[out]  cfg             Configuration
 *
 * \returns:
 * - BDMF_ERR_OK - OK
 * - BDMF_ERR_PARM - error in parameters
 * - BDMF_ERR_NOENT - field is not configured
 *****************************************************************************************/
bdmf_error_t rdd_tcam_generic_key_get(rdd_tcam_table_id table_id, uint8_t gen_index,
    rdpa_ic_gen_rule_cfg_t *cfg);


/****************************************************************************************
* Compose tcam entry from ic context
*
* \param[in]   index         rule index
* \param[in]   ctx           context to copy
* \param[out]  entry         tcam entry
 *****************************************************************************************/
void rdd_tcam_ic_result_entry_compose(uint16_t index, const rdd_ic_context_t *ctx, uint8_t *entry);

uint32_t rdd_tcam_debug_cntr_id_get(uint16_t index);
void rdd_ic_debug_mode_enable(bdmf_boolean enable);
void rdd_tcam_debug_cntr_id_cfg(uint16_t index, uint32_t cntr_id);

#endif /* _RDD_TCAM_IC_H */
