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
 * tcont object header file.
 * This header file is generated automatically. Do not edit!
 */
#ifndef _RDPA_AG_TCONT_H_
#define _RDPA_AG_TCONT_H_

/** \addtogroup tcont
 * @{
 */


/** Get tcont type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create a tcont object.
 * \return tcont type handle
 */
bdmf_type_handle rdpa_tcont_drv(void);

/* tcont: Attribute types */
typedef enum {
    rdpa_tcont_attr_index = 0, /* index : KRI : number : TCONT index */
    rdpa_tcont_attr_management = 1, /* management : RI : bool : Yes: OMCI management TCONT */
    rdpa_tcont_attr_egress_tm = 2, /* egress_tm : RW : object : US scheduler object */
    rdpa_tcont_attr_enable = 3, /* enable : RW : bool : Enable TCONT */
    rdpa_tcont_attr_orl_prty = 4, /* orl_prty : RW : enum : Priority for overall rate limiter */
} rdpa_tcont_attr_types;

extern int (*f_rdpa_tcont_get)(bdmf_number index_, bdmf_object_handle *pmo);

/** Get tcont object by key.

 * This function returns tcont object instance by key.
 * \param[in] index_    Object key
 * \param[out] tcont_obj    Object handle
 * \return    0=OK or error <0
 */
int rdpa_tcont_get(bdmf_number index_, bdmf_object_handle *tcont_obj);

/** Get tcont/index attribute.
 *
 * Get TCONT index.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[out]  index_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_tcont_index_get(bdmf_object_handle mo_, bdmf_number *index_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_tcont_attr_index, &_nn_);
    *index_ = (bdmf_number)_nn_;
    return _rc_;
}


/** Set tcont/index attribute.
 *
 * Set TCONT index.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[in]   index_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_tcont_index_set(bdmf_object_handle mo_, bdmf_number index_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_tcont_attr_index, index_);
}


/** Get tcont/management attribute.
 *
 * Get Yes: OMCI management TCONT.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[out]  management_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_tcont_management_get(bdmf_object_handle mo_, bdmf_boolean *management_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_tcont_attr_management, &_nn_);
    *management_ = (bdmf_boolean)_nn_;
    return _rc_;
}


/** Set tcont/management attribute.
 *
 * Set Yes: OMCI management TCONT.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[in]   management_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_tcont_management_set(bdmf_object_handle mo_, bdmf_boolean management_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_tcont_attr_management, management_);
}


/** Get tcont/egress_tm attribute.
 *
 * Get US scheduler object.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[out]  egress_tm_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_tcont_egress_tm_get(bdmf_object_handle mo_, bdmf_object_handle *egress_tm_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_tcont_attr_egress_tm, &_nn_);
    *egress_tm_ = (bdmf_object_handle)(long)_nn_;
    return _rc_;
}


/** Set tcont/egress_tm attribute.
 *
 * Set US scheduler object.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[in]   egress_tm_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_tcont_egress_tm_set(bdmf_object_handle mo_, bdmf_object_handle egress_tm_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_tcont_attr_egress_tm, (long)egress_tm_);
}


/** Get tcont/enable attribute.
 *
 * Get Enable TCONT.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[out]  enable_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_tcont_enable_get(bdmf_object_handle mo_, bdmf_boolean *enable_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_tcont_attr_enable, &_nn_);
    *enable_ = (bdmf_boolean)_nn_;
    return _rc_;
}


/** Set tcont/enable attribute.
 *
 * Set Enable TCONT.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[in]   enable_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task and softirq contexts.
 */
static inline int rdpa_tcont_enable_set(bdmf_object_handle mo_, bdmf_boolean enable_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_tcont_attr_enable, enable_);
}


/** Get tcont/orl_prty attribute.
 *
 * Get Priority for overall rate limiter.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[out]  orl_prty_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_tcont_orl_prty_get(bdmf_object_handle mo_, rdpa_tm_orl_prty *orl_prty_)
{
    bdmf_number _nn_;
    int _rc_;
    _rc_ = bdmf_attr_get_as_num(mo_, rdpa_tcont_attr_orl_prty, &_nn_);
    *orl_prty_ = (rdpa_tm_orl_prty)_nn_;
    return _rc_;
}


/** Set tcont/orl_prty attribute.
 *
 * Set Priority for overall rate limiter.
 * \param[in]   mo_ tcont object handle or mattr transaction handle
 * \param[in]   orl_prty_ Attribute value
 * \return 0 or error code < 0
 * The function can be called in task context only.
 */
static inline int rdpa_tcont_orl_prty_set(bdmf_object_handle mo_, rdpa_tm_orl_prty orl_prty_)
{
    return bdmf_attr_set_as_num(mo_, rdpa_tcont_attr_orl_prty, orl_prty_);
}

/** @} end of tcont Doxygen group */




#endif /* _RDPA_AG_TCONT_H_ */
