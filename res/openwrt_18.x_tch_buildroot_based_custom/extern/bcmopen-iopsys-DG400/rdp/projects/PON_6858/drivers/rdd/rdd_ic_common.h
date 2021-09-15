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

#ifndef _RDD_IC_COMMON_H
#define _RDD_IC_COMMON_H

/****************************************************************************************
* Compose rule based ctx entry from rdd_ic_context_t
*
* \param[in]   index         rule index
* \param[in]   ctx           ic context to copy
* \param[out]  entry         rule based ctx entry
 *****************************************************************************************/
void rdd_ic_result_entry_compose(uint16_t index, const rdd_ic_context_t *ctx, uint8_t *entry);

/****************************************************************************************
* Compose rdd_ic_context_t entry from rule based ctx
*
* \param[in]  entry         rule based ctx entry to copy
* \param[out] index         rule index
* \param[out] ctx           ic context
 *****************************************************************************************/
void rdd_ic_result_entry_decompose(uint8_t *entry, uint16_t *index, rdd_ic_context_t *ctx);

#endif /* _RDD_IC_COMMON_H */
