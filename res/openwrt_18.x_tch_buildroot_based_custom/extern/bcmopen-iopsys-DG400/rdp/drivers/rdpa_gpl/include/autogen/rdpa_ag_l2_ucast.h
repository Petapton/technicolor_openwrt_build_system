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
 * l2_ucast object header file.
 * This header file is generated automatically. Do not edit!
 */
#ifndef _RDPA_AG_L2_UCAST_H_
#define _RDPA_AG_L2_UCAST_H_

/** \addtogroup l2_ucast
 * @{
 */


/** Get l2_ucast type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create a l2_ucast object.
 * \return l2_ucast type handle
 */
bdmf_type_handle rdpa_l2_ucast_drv(void);

/* l2_ucast: Attribute types */
typedef enum {
    rdpa_l2_ucast_attr_nflows = 0, /* nflows : R : number : number of configured L2 flows */
    rdpa_l2_ucast_attr_flow = 1, /* flow : RWADF : aggregate[] l2_flow_info(rdpa_l2_flow_info_t) : l2_ucast flow entry */
    rdpa_l2_ucast_attr_flow_stat = 2, /* flow_stat : RF : aggregate[] rdpa_stat(rdpa_stat_t) : l2_ucast flow entry statistics */
} rdpa_l2_ucast_attr_types;

extern int (*f_rdpa_l2_ucast_get)(bdmf_object_handle *pmo);

/** Get l2_ucast object.

 * This function returns l2_ucast object instance.
 * \param[out] l2_ucast_obj    Object handle
 * \return    0=OK or error <0
 */
int rdpa_l2_ucast_get(bdmf_object_handle *l2_ucast_obj);

/** Get l2_ucast/nflows attribute.
 *
 * Get number of configured L2 flows.
 * \param[in]   mo_ l2_ucast object handle or mattr transaction handle
 * \param[out]  nflows_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_l2_ucast_nflows_get(bdmf_object_handle mo_, bdmf_number *nflows_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_l2_ucast_attr_nflows, &_nn_);
    *nflows_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Get l2_ucast/flow attribute entry.
 *
 * Get l2_ucast flow entry.
 * \param[in]   mo_ l2_ucast object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  flow_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_l2_ucast_flow_get(bdmf_object_handle mo_, bdmf_index ai_, rdpa_l2_flow_info_t * flow_)
{
    return bdmf_attrelem_get_as_buf(mo_, rdpa_l2_ucast_attr_flow, (bdmf_index)ai_, flow_, sizeof(*flow_));
}


/** Set l2_ucast/flow attribute entry.
 *
 * Set l2_ucast flow entry.
 * \param[in]   mo_ l2_ucast object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[in]   flow_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_l2_ucast_flow_set(bdmf_object_handle mo_, bdmf_index ai_, const rdpa_l2_flow_info_t * flow_)
{
    return bdmf_attrelem_set_as_buf(mo_, rdpa_l2_ucast_attr_flow, (bdmf_index)ai_, flow_, sizeof(*flow_));
}


/** Add l2_ucast/flow attribute entry.
 *
 * Add l2_ucast flow entry.
 * \param[in]   mo_ l2_ucast object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \param[in]   flow_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_l2_ucast_flow_add(bdmf_object_handle mo_, bdmf_index * ai_, const rdpa_l2_flow_info_t * flow_)
{
    int rc;
    rc = bdmf_attrelem_add_as_buf(mo_, rdpa_l2_ucast_attr_flow, (bdmf_index *)ai_, flow_, sizeof(*flow_));
    return rc;
}


/** Delete l2_ucast/flow attribute entry.
 *
 * Delete l2_ucast flow entry.
 * \param[in]   mo_ l2_ucast object handle
 * \param[in]   ai_ Attribute array index
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_l2_ucast_flow_delete(bdmf_object_handle mo_, bdmf_index ai_)
{
    return bdmf_attrelem_delete(mo_, rdpa_l2_ucast_attr_flow, (bdmf_index)ai_);
}


/** Find l2_ucast/flow attribute entry.
 *
 * Find l2_ucast flow entry.
 * \param[in]   mo_ l2_ucast object handle or mattr transaction handle
 * \param[in,out]   ai_ Attribute array index
 * \param[in,out]   flow_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_l2_ucast_flow_find(bdmf_object_handle mo_, bdmf_index * ai_, rdpa_l2_flow_info_t * flow_)
{
    int rc;
    rc = bdmf_attrelem_find(mo_, rdpa_l2_ucast_attr_flow, (bdmf_index *)ai_, flow_, sizeof(*flow_));
    return rc;
}


/** Get l2_ucast/flow_stat attribute entry.
 *
 * Get l2_ucast flow entry statistics.
 * \param[in]   mo_ l2_ucast object handle or mattr transaction handle
 * \param[in]   ai_ Attribute array index
 * \param[out]  flow_stat_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_l2_ucast_flow_stat_get(bdmf_object_handle mo_, bdmf_index ai_, rdpa_stat_t * flow_stat_)
{
    return bdmf_attrelem_get_as_buf(mo_, rdpa_l2_ucast_attr_flow_stat, (bdmf_index)ai_, flow_stat_, sizeof(*flow_stat_));
}

/** @} end of l2_ucast Doxygen group */




#endif /* _RDPA_AG_L2_UCAST_H_ */
