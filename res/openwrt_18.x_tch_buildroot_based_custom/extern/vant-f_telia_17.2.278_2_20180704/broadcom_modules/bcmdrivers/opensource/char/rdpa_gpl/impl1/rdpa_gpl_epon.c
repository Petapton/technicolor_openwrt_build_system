// <:copyright-BRCM:2013:DUAL/GPL:standard
// 
//    Copyright (c) 2013 Broadcom Corporation
//    All Rights Reserved
// 
// Unless you and Broadcom execute a separate written software license
// agreement governing use of this software, this software is licensed
// to you under the terms of the GNU General Public License version 2
// (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
// with the following added to such license:
// 
//    As a special exception, the copyright holders of this software give
//    you permission to link this software with independent modules, and
//    to copy and distribute the resulting executable under terms of your
//    choice, provided that you also meet, for each linked independent
//    module, the terms and conditions of the license of that module.
//    An independent module is a module which is not derived from this
//    software.  The special exception does not apply to any modifications
//    of the software.
// 
// Not withstanding the above, under no circumstances may you combine
// this software in any way with any other Broadcom software provided
// under a license other than the GPL, without Broadcom's express prior
// written consent.
// 
// :>
/*
 * epon object GPL shim file.
 * This file is generated automatically. Do not edit!
 */

bdmf_type_handle (*f_rdpa_epon_drv)(void);

EXPORT_SYMBOL(f_rdpa_epon_drv);

/** Get epon type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create an epon object.
 * \return epon type handle
 */
bdmf_type_handle rdpa_epon_drv(void)
{
   if (!f_rdpa_epon_drv)
       return NULL;
   return f_rdpa_epon_drv();
}

EXPORT_SYMBOL(rdpa_epon_drv);

int (*f_rdpa_epon_get)(bdmf_object_handle *pmo);
EXPORT_SYMBOL(f_rdpa_epon_get);

/** Get epon object.

 * This function returns epon object instance.
 * \param[out] epon_obj    Object handle
 * \return    0=OK or error <0
 */
int rdpa_epon_get(bdmf_object_handle *epon_obj)
{
   if (!f_rdpa_epon_get)
       return BDMF_ERR_STATE;
   return f_rdpa_epon_get(epon_obj);
}
EXPORT_SYMBOL(rdpa_epon_get);

MODULE_LICENSE("GPL");
