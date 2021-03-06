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
 * router object GPL shim file.
 * This file is generated automatically. Do not edit!
 */

bdmf_type_handle (*f_rdpa_router_drv)(void);

EXPORT_SYMBOL(f_rdpa_router_drv);

/** Get router type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create a router object.
 * \return router type handle
 */
bdmf_type_handle rdpa_router_drv(void)
{
   if (!f_rdpa_router_drv)
       return NULL;
   return f_rdpa_router_drv();
}

EXPORT_SYMBOL(rdpa_router_drv);

int (*f_rdpa_router_get)(bdmf_object_handle *pmo);
EXPORT_SYMBOL(f_rdpa_router_get);

/** Get router object.

 * This function returns router object instance.
 * \param[out] router_obj    Object handle
 * \return    0=OK or error <0
 */
int rdpa_router_get(bdmf_object_handle *router_obj)
{
   if (!f_rdpa_router_get)
       return BDMF_ERR_STATE;
   return f_rdpa_router_get(router_obj);
}
EXPORT_SYMBOL(rdpa_router_get);

bdmf_type_handle (*f_rdpa_subnet_drv)(void);

EXPORT_SYMBOL(f_rdpa_subnet_drv);

/** Get subnet type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create a subnet object.
 * \return subnet type handle
 */
bdmf_type_handle rdpa_subnet_drv(void)
{
   if (!f_rdpa_subnet_drv)
       return NULL;
   return f_rdpa_subnet_drv();
}

EXPORT_SYMBOL(rdpa_subnet_drv);

int (*f_rdpa_subnet_get)(rdpa_subnet index_, bdmf_object_handle *pmo);
EXPORT_SYMBOL(f_rdpa_subnet_get);

/** Get subnet object by key.

 * This function returns subnet object instance by key.
 * \param[in] index_    Object key
 * \param[out] subnet_obj    Object handle
 * \return    0=OK or error <0
 */
int rdpa_subnet_get(rdpa_subnet index_, bdmf_object_handle *subnet_obj)
{
   if (!f_rdpa_subnet_get)
       return BDMF_ERR_STATE;
   return f_rdpa_subnet_get(index_, subnet_obj);
}
EXPORT_SYMBOL(rdpa_subnet_get);

bdmf_type_handle (*f_rdpa_fw_rule_drv)(void);

EXPORT_SYMBOL(f_rdpa_fw_rule_drv);

/** Get fw_rule type handle.
 *
 * This handle should be passed to bdmf_new_and_set() function in
 * order to create a fw_rule object.
 * \return fw_rule type handle
 */
bdmf_type_handle rdpa_fw_rule_drv(void)
{
   if (!f_rdpa_fw_rule_drv)
       return NULL;
   return f_rdpa_fw_rule_drv();
}

EXPORT_SYMBOL(rdpa_fw_rule_drv);

int (*f_rdpa_fw_rule_get)(bdmf_number index_, bdmf_object_handle *pmo);
EXPORT_SYMBOL(f_rdpa_fw_rule_get);

/** Get fw_rule object by key.

 * This function returns fw_rule object instance by key.
 * \param[in] index_    Object key
 * \param[out] fw_rule_obj    Object handle
 * \return    0=OK or error <0
 */
int rdpa_fw_rule_get(bdmf_number index_, bdmf_object_handle *fw_rule_obj)
{
   if (!f_rdpa_fw_rule_get)
       return BDMF_ERR_STATE;
   return f_rdpa_fw_rule_get(index_, fw_rule_obj);
}
EXPORT_SYMBOL(rdpa_fw_rule_get);

MODULE_LICENSE("GPL");
