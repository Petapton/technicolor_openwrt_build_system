// <:copyright-BRCM:2013:DUAL/GPL:standard
// 
//    Copyright (c) 2013 Broadcom 
//    All Rights Reserved
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, version 2, as published by
// the Free Software Foundation (the "GPL").
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// 
// A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
// writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.
// 
// :>
/*
 * system object header file.
 * This header file is generated automatically. Do not edit!
 */
#ifndef _RDPA_AG_SYSTEM_H_
#define _RDPA_AG_SYSTEM_H_

/** \addtogroup system
 * @{
 */


/** Get system type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create a system object.
 * \return system type handle
 */
bdmf_type_handle rdpa_system_drv(void);

/* system: Attribute types */
typedef enum {
    rdpa_system_attr_init_cfg = 0, /* init_cfg : MRI : aggregate system_init_config(rdpa_system_init_cfg_t) : Initial System Configuration */
    rdpa_system_attr_cfg = 1, /* cfg : RW : aggregate system_config(rdpa_system_cfg_t) : System Configuration that can be changes in run-time */
    rdpa_system_attr_sw_version = 2, /* sw_version : R : aggregate sw_version(rdpa_sw_version_t) : software version */
    rdpa_system_attr_drop_precedence = 4, /* drop_precedence : RWF : bool[(dp_key)] : Drop precedence flow entry */
    rdpa_system_attr_tpid_detect = 5, /* tpid_detect : RWF : aggregate[(rdpa_tpid_detect_t)] system_tpid_detect_cfg(rdpa_tpid_detect_cfg_t) : TPID Detect */
    rdpa_system_attr_tod = 6, /* tod : R : aggregate system_tod(rdpa_system_tod_t) : Time Of Day */
    rdpa_system_attr_cpu_reason_to_tc = 7, /* cpu_reason_to_tc : RWF : number[(rdpa_cpu_reason)] : CPU Reason to TC global configuration */
} rdpa_system_attr_types;

extern int (*f_rdpa_system_get)(bdmf_object_handle *pmo);

/** Get system object.

 * This function returns system object instance.
 * \param[out] system_obj    Object handle
 * \return    0=OK or error <0
 */
int rdpa_system_get(bdmf_object_handle *system_obj);

/** Get system/init_cfg attribute.
 *
 * Get Initial System Configuration.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  init_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_system_init_cfg_get(bdmf_object_handle mo_, rdpa_system_init_cfg_t * init_cfg_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_system_attr_init_cfg, init_cfg_, sizeof(*init_cfg_));
}


/** Set system/init_cfg attribute.
 *
 * Set Initial System Configuration.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   init_cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_system_init_cfg_set(bdmf_object_handle mo_, const rdpa_system_init_cfg_t * init_cfg_)
{
    return bdmf_attr_set_as_buf(mo_, rdpa_system_attr_init_cfg, init_cfg_, sizeof(*init_cfg_));
}


/** Get system/cfg attribute.
 *
 * Get System Configuration that can be changes in run-time.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_cfg_get(bdmf_object_handle mo_, rdpa_system_cfg_t * cfg_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_system_attr_cfg, cfg_, sizeof(*cfg_));
}


/** Set system/cfg attribute.
 *
 * Set System Configuration that can be changes in run-time.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   cfg_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_cfg_set(bdmf_object_handle mo_, const rdpa_system_cfg_t * cfg_)
{
    return bdmf_attr_set_as_buf(mo_, rdpa_system_attr_cfg, cfg_, sizeof(*cfg_));
}


/** Get system/sw_version attribute.
 *
 * Get software version.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  sw_version_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_sw_version_get(bdmf_object_handle mo_, rdpa_sw_version_t * sw_version_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_system_attr_sw_version, sw_version_, sizeof(*sw_version_));
}


/** Get system/drop_precedence attribute entry.
 *
 * Get Drop precedence flow entry.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  drop_precedence_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_drop_precedence_get(bdmf_object_handle mo_, rdpa_dp_key_t * ai_, bdmf_boolean *drop_precedence_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attrelem_get_as_num(mo_, rdpa_system_attr_drop_precedence, (bdmf_index)ai_, &_nn_);
    *drop_precedence_ = (bdmf_boolean)_nn_;
    return _rc_;
}


/** Set system/drop_precedence attribute entry.
 *
 * Set Drop precedence flow entry.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   drop_precedence_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_drop_precedence_set(bdmf_object_handle mo_, rdpa_dp_key_t * ai_, bdmf_boolean drop_precedence_)
{
    return bdmf_attrelem_set_as_num(mo_, rdpa_system_attr_drop_precedence, (bdmf_index)ai_, drop_precedence_);
}


/** Get next system/drop_precedence attribute entry.
 *
 * Get next Drop precedence flow entry.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_drop_precedence_get_next(bdmf_object_handle mo_, rdpa_dp_key_t * ai_)
{
    return bdmf_attrelem_get_next(mo_, rdpa_system_attr_drop_precedence, (bdmf_index *)ai_);
}


/** Get system/tpid_detect attribute entry.
 *
 * Get TPID Detect.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  tpid_detect_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_tpid_detect_get(bdmf_object_handle mo_, rdpa_tpid_detect_t ai_, rdpa_tpid_detect_cfg_t * tpid_detect_)
{
    return bdmf_attrelem_get_as_buf(mo_, rdpa_system_attr_tpid_detect, (bdmf_index)ai_, tpid_detect_, sizeof(*tpid_detect_));
}


/** Set system/tpid_detect attribute entry.
 *
 * Set TPID Detect.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   tpid_detect_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_tpid_detect_set(bdmf_object_handle mo_, rdpa_tpid_detect_t ai_, const rdpa_tpid_detect_cfg_t * tpid_detect_)
{
    return bdmf_attrelem_set_as_buf(mo_, rdpa_system_attr_tpid_detect, (bdmf_index)ai_, tpid_detect_, sizeof(*tpid_detect_));
}


/** Get system/tod attribute.
 *
 * Get Time Of Day.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[out]  tod_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_tod_get(bdmf_object_handle mo_, rdpa_system_tod_t * tod_)
{
    return bdmf_attr_get_as_buf(mo_, rdpa_system_attr_tod, tod_, sizeof(*tod_));
}


/** Get system/cpu_reason_to_tc attribute entry.
 *
 * Get CPU Reason to TC global configuration.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  cpu_reason_to_tc_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_cpu_reason_to_tc_get(bdmf_object_handle mo_, rdpa_cpu_reason ai_, bdmf_number *cpu_reason_to_tc_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attrelem_get_as_num(mo_, rdpa_system_attr_cpu_reason_to_tc, (bdmf_index)ai_, &_nn_);
    *cpu_reason_to_tc_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Set system/cpu_reason_to_tc attribute entry.
 *
 * Set CPU Reason to TC global configuration.
 * \param[in]   mo_ system object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   cpu_reason_to_tc_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_system_cpu_reason_to_tc_set(bdmf_object_handle mo_, rdpa_cpu_reason ai_, bdmf_number cpu_reason_to_tc_)
{
    return bdmf_attrelem_set_as_num(mo_, rdpa_system_attr_cpu_reason_to_tc, (bdmf_index)ai_, cpu_reason_to_tc_);
}

/** @} end of system Doxygen group */




#endif /* _RDPA_AG_SYSTEM_H_ */
