/*
    Copyright (c) 2017 Broadcom
    All Rights Reserved

    <:label-BRCM:2017:DUAL/GPL:standard
    
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

#ifndef _linux_osl_dslcpe_h_
#define _linux_osl_dslcpe_h_

/* backward compatible for kernel/bridge use (defined in wl_pktc.h) */
#define UPDATE_BRC_HOT			4 /* PKTC_TBL_UPDATE */
#define GET_PKTC_TX_MODE		7 /* PKTC_TBL_GET_TX_MODE */
#define INVALID_CHAIN_IDX		0x3FFE /* PKTC_INVALID_CHAIN_IDX */
#define WFD_IDX_UINT16_BIT_MASK		(0xC000) /* PKTC_TBL_WFD_IDX_BITMASK */
#define WFD_IDX_UINT16_BIT_POS		14 /* PKTC_WFD_IDX_BITPOS */

#endif	/* _linux_osl_dslcpe_h_ */
