/*
* <:copyright-BRCM:2013:DUAL/GPL:standard
* 
*    Copyright (c) 2013 Broadcom 
*    All Rights Reserved
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License, version 2, as published by
* the Free Software Foundation (the "GPL").
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* 
* A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
* writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
* Boston, MA 02111-1307, USA.
* 
* :> 
*/


#ifndef _RDPA_VLAN_H_
#define _RDPA_VLAN_H_

/** \defgroup vlan VLAN Container Object
 * VLAN container object contains a list of VIDs supported by
 * a given port in a given bridge.\n
 * The object supports multiple VIDs with individual vlan_action per VID.\n
 * \n
 * A VLAN object must have a port object parent.\n
 * Once created, VLAN object is attached to the appropriate bridge using \ref bdmf_link "link" operation.
 * @{
 */

#define RDPA_MAX_VLANS                  128     /**< Max number of VIDs */
#ifdef XRDP
/* Number of AGGR WAN VLANS is derived from number of bridges since we support single
 * wan vid per Aggregatating Bridge 
 */
#define RDPA_MAX_AGGR_WAN_VLANS         16      /**< Max number of aggregated WAN VIDs */
#else
#define RDPA_MAX_AGGR_WAN_VLANS         4       /**< Max number of aggregated WAN VIDs */
#endif
/** @} end of vlan Doxygen group */

#endif /* _RDPA_VLAN_H_ */
