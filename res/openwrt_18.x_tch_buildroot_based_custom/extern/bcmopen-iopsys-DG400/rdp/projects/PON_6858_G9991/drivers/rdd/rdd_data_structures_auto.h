/*
   Copyright (c) 2015 Broadcom
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



/* This is an automated file. Do not edit its contents. */


#ifndef _RDD_DATA_STRUCTURES_AUTO_H_
#define _RDD_DATA_STRUCTURES_AUTO_H_

#define GROUPED_EN_SEGMENTS_NUM       16
#define INVALID_TABLE_ADDRESS         0xFFFFFF

/* DDR */
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_NUMBER	16
#define RDD_IPTV_DDR_CONTEXT_ENTRY_DST_IPV6_ADDR_NUMBER	16
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RULE_BASED_RESULT_NUMBER	8

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	valid                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_ver                                                                   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	any_vid                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	any_src_ip                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid                                                                      	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	next_entry_idx                                                           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid_vector_0                                                            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid_vector_1                                                            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid_vector_2                                                            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	radio_dhd_vector                                                         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                                	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_proxy_enabled                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_index                                                         	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_tx_prio                                                       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                                                                	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pool_num                                                                 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	replications                                                             	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cntr_id                                                                  	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_ports_vector                                                      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_ip                                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	src_ipv6_addr[RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_NUMBER];
	uint8_t	dst_ipv6_addr[RDD_IPTV_DDR_CONTEXT_ENTRY_DST_IPV6_ADDR_NUMBER];
	uint8_t	rule_based_result[RDD_IPTV_DDR_CONTEXT_ENTRY_RULE_BASED_RESULT_NUMBER];
#else
	uint32_t	next_entry_idx                                                           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid                                                                      	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	any_src_ip                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	any_vid                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_ver                                                                   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid_vector_1                                                            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid_vector_0                                                            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_index                                                         	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_proxy_enabled                                                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                                	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	radio_dhd_vector                                                         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid_vector_2                                                            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cntr_id                                                                  	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	replications                                                             	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pool_num                                                                 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                                                                	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wlan_mcast_tx_prio                                                       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_ports_vector                                                      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_ip                                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	src_ipv6_addr[RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_NUMBER];
	uint8_t	dst_ipv6_addr[RDD_IPTV_DDR_CONTEXT_ENTRY_DST_IPV6_ADDR_NUMBER];
	uint8_t	rule_based_result[RDD_IPTV_DDR_CONTEXT_ENTRY_RULE_BASED_RESULT_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_DDR_CONTEXT_ENTRY_DTS;

#define RDD_IPTV_DDR_CONTEXT_ENTRY_VALID_READ_G(r, g, idx)                             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 7, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_VALID_WRITE_G(v, g, idx)                            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 7, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_VALID_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_VALID_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_IP_VER_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 6, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_IP_VER_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 6, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_IP_VER_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_IP_VER_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_ANY_VID_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 5, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_ANY_VID_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 5, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_ANY_VID_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_ANY_VID_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 4, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 4, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_VID_READ_G(r, g, idx)                               GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 0, 12, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_VID_WRITE_G(v, g, idx)                              GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS), 0, 12, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_VID_READ(r, p)                                      FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_VID_WRITE(v, p)                                     FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_NEXT_ENTRY_IDX_READ_G(r, g, idx)                    GROUP_MREAD_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 2, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_NEXT_ENTRY_IDX_WRITE_G(v, g, idx)                   GROUP_MWRITE_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 2, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_NEXT_ENTRY_IDX_READ(r, p)                           MREAD_16((uint8_t *)p + 2, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_NEXT_ENTRY_IDX_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 2, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_0_READ_G(r, g, idx)                     GROUP_MREAD_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 4, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_0_WRITE_G(v, g, idx)                    GROUP_MWRITE_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 4, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_0_READ(r, p)                            MREAD_16((uint8_t *)p + 4, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_0_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 4, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_1_READ_G(r, g, idx)                     GROUP_MREAD_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 6, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_1_WRITE_G(v, g, idx)                    GROUP_MWRITE_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 6, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_1_READ(r, p)                            MREAD_16((uint8_t *)p + 6, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_1_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 6, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_2_READ_G(r, g, idx)                     GROUP_MREAD_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 8, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_2_WRITE_G(v, g, idx)                    GROUP_MWRITE_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 8, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_2_READ(r, p)                            MREAD_16((uint8_t *)p + 8, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_2_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 8, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RADIO_DHD_VECTOR_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 10, 5, 3, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RADIO_DHD_VECTOR_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 10, 5, 3, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RADIO_DHD_VECTOR_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 10, 5, 3, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RADIO_DHD_VECTOR_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 10, 5, 3, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_PROXY_ENABLED_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 11, 7, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_PROXY_ENABLED_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 11, 7, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_PROXY_ENABLED_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 11, 7, 1, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_PROXY_ENABLED_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 11, 7, 1, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_INDEX_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 11, 0, 7, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_INDEX_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 11, 0, 7, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_INDEX_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 11, 0, 7, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_INDEX_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 11, 0, 7, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 12, 4, 3, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 12, 4, 3, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 12, 4, 3, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 12, 4, 3, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 13, 6, 2, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 13, 6, 2, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 13, 6, 2, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 13, 6, 2, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 13, 0, 6, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 13, 0, 6, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 13, 0, 6, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 13, 0, 6, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_CNTR_ID_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 14, 0, 10, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_CNTR_ID_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 14, 0, 10, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_CNTR_ID_READ(r, p)                                  FIELD_MREAD_16((uint8_t *)p + 14, 0, 10, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_CNTR_ID_WRITE(v, p)                                 FIELD_MWRITE_16((uint8_t *)p + 14, 0, 10, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_EGRESS_PORTS_VECTOR_READ_G(r, g, idx)               GROUP_MREAD_32(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 16, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_EGRESS_PORTS_VECTOR_WRITE_G(v, g, idx)              GROUP_MWRITE_32(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 16, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_EGRESS_PORTS_VECTOR_READ(r, p)                      MREAD_32((uint8_t *)p + 16, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_EGRESS_PORTS_VECTOR_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 16, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IP_READ_G(r, g, idx)                            GROUP_MREAD_32(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 20, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IP_WRITE_G(v, g, idx)                           GROUP_MWRITE_32(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 20, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IP_READ(r, p)                                   MREAD_32((uint8_t *)p + 20, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IP_WRITE(v, p)                                  MWRITE_32((uint8_t *)p + 20, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_READ_G(r, g, idx, i)                  GROUP_MREAD_I_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 24, i, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_WRITE_G(v, g, idx, i)                 GROUP_MWRITE_I_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 24, i, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_READ(r, p, i)                         MREAD_I_8((uint8_t *)p + 24, i, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_WRITE(v, p, i)                        MWRITE_I_8((uint8_t *)p + 24, i, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_DST_IPV6_ADDR_READ_G(r, g, idx, i)                  GROUP_MREAD_I_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 40, i, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_DST_IPV6_ADDR_WRITE_G(v, g, idx, i)                 GROUP_MWRITE_I_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 40, i, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_DST_IPV6_ADDR_READ(r, p, i)                         MREAD_I_8((uint8_t *)p + 40, i, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_DST_IPV6_ADDR_WRITE(v, p, i)                        MWRITE_I_8((uint8_t *)p + 40, i, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RULE_BASED_RESULT_READ_G(r, g, idx, i)              GROUP_MREAD_I_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 56, i, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RULE_BASED_RESULT_WRITE_G(v, g, idx, i)             GROUP_MWRITE_I_8(g, idx*sizeof(RDD_IPTV_DDR_CONTEXT_ENTRY_DTS) + 56, i, v)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RULE_BASED_RESULT_READ(r, p, i)                     MREAD_I_8((uint8_t *)p + 56, i, r)
#define RDD_IPTV_DDR_CONTEXT_ENTRY_RULE_BASED_RESULT_WRITE(v, p, i)                    MWRITE_I_8((uint8_t *)p + 56, i, v)

#define RDD_IPTV_DDR_CONTEXT_TABLE_SIZE     1024
typedef struct
{
	RDD_IPTV_DDR_CONTEXT_ENTRY_DTS	entry[ RDD_IPTV_DDR_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_DDR_CONTEXT_TABLE_DTS;

/* PSRAM */
/* CORE_0 */

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	valid         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	headroom      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dont_agg      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mc_copy       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reprocess     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	color         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	force_copy    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	second_level_q	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	first_level_q 	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flag_1588     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	coherent      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hn            	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	serial_num    	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn_num        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_1  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cong_state    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_cong  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lan           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_port  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = ingress_port, size = 8 bits
	uint32_t	flow          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_port   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	union3        	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union3, size = 18 bits
	uint32_t	bn1_first     	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs3          	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	agg_pd        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_0  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset_or_abs_1	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = payload_offset_or_abs_1, size = 11 bits
	uint32_t	sop           	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs1          	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	buffer_number_0_or_abs_0	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = buffer_number_0_or_abs_0, size = 18 bits
	uint32_t	bn0_first     	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs0          	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
#else
	uint32_t	hn            	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	coherent      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flag_1588     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	first_level_q 	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	second_level_q	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	force_copy    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	color         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reprocess     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mc_copy       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dont_agg      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	headroom      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn_num        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	serial_num    	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	union3        	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = union3, size = 18 bits
	uint32_t	bn1_first     	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs3          	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	ingress_port  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = ingress_port, size = 8 bits
	uint32_t	flow          	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_port   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	lan           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_cong  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cong_state    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_1  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number_0_or_abs_0	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = buffer_number_0_or_abs_0, size = 18 bits
	uint32_t	bn0_first     	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs0          	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	payload_offset_or_abs_1	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = payload_offset_or_abs_1, size = 11 bits
	uint32_t	sop           	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs1          	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	abs           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_0  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	agg_pd        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PROCESSING_TX_DESCRIPTOR_DTS;

#define RDD_PROCESSING_TX_DESCRIPTOR_VALID_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_VALID_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_VALID_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_VALID_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_HEADROOM_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 6, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_HEADROOM_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 6, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_HEADROOM_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_HEADROOM_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_DONT_AGG_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 5, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_DONT_AGG_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 5, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_DONT_AGG_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_DONT_AGG_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_MC_COPY_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 4, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_MC_COPY_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 4, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_MC_COPY_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_MC_COPY_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_REPROCESS_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 3, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_REPROCESS_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 3, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_REPROCESS_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 3, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_REPROCESS_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 3, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_COLOR_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 2, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_COLOR_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 2, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_COLOR_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p, 2, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_COLOR_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p, 2, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_FORCE_COPY_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 1, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_FORCE_COPY_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 1, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_FORCE_COPY_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_FORCE_COPY_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_SECOND_LEVEL_Q_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 0, 9, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_SECOND_LEVEL_Q_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS), 0, 9, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_SECOND_LEVEL_Q_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 0, 9, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_SECOND_LEVEL_Q_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 0, 9, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_FIRST_LEVEL_Q_READ_G(r, g, idx)           GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 2, 7, 9, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_FIRST_LEVEL_Q_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 2, 7, 9, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_FIRST_LEVEL_Q_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p + 2, 7, 9, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_FIRST_LEVEL_Q_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p + 2, 7, 9, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_FLAG_1588_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 3, 6, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_FLAG_1588_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 3, 6, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_FLAG_1588_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 3, 6, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_FLAG_1588_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 3, 6, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_COHERENT_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 3, 5, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_COHERENT_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 3, 5, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_COHERENT_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 3, 5, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_COHERENT_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 3, 5, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_HN_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 3, 0, 5, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_HN_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 3, 0, 5, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_HN_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 3, 0, 5, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_HN_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 3, 0, 5, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_SERIAL_NUM_READ_G(r, g, idx)              GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 4, 6, 10, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_SERIAL_NUM_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 4, 6, 10, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_SERIAL_NUM_READ(r, p)                     FIELD_MREAD_16((uint8_t *)p + 4, 6, 10, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_SERIAL_NUM_WRITE(v, p)                    FIELD_MWRITE_16((uint8_t *)p + 4, 6, 10, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_PRIORITY_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 5, 5, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_PRIORITY_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 5, 5, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_PRIORITY_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 5, 5, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_PRIORITY_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 5, 5, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN_NUM_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 4, 14, 7, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN_NUM_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 4, 14, 7, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN_NUM_READ(r, p)                         FIELD_MREAD_32((uint8_t *)p + 4, 14, 7, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN_NUM_WRITE(v, p)                        FIELD_MWRITE_32((uint8_t *)p + 4, 14, 7, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_PACKET_LENGTH_READ_G(r, g, idx)           GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 6, 0, 14, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_PACKET_LENGTH_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 6, 0, 14, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_DROP_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 7, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_DROP_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 7, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_DROP_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_DROP_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_TARGET_MEM_1_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 6, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_TARGET_MEM_1_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 6, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_TARGET_MEM_1_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_TARGET_MEM_1_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_CONG_STATE_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 4, 2, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_CONG_STATE_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 4, 2, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_CONG_STATE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 8, 4, 2, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_CONG_STATE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 8, 4, 2, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_INGRESS_CONG_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 3, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_INGRESS_CONG_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 3, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_INGRESS_CONG_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 8, 3, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_INGRESS_CONG_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 8, 3, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_LAN_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 2, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_LAN_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 2, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_LAN_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 8, 2, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_LAN_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 8, 2, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_INGRESS_PORT_READ_G(r, g, idx)            GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 2, 8, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_INGRESS_PORT_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 2, 8, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_INGRESS_PORT_READ(r, p)                   FIELD_MREAD_16((uint8_t *)p + 8, 2, 8, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_INGRESS_PORT_WRITE(v, p)                  FIELD_MWRITE_16((uint8_t *)p + 8, 2, 8, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_FLOW_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 2, 8, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_FLOW_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 2, 8, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_FLOW_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p + 8, 2, 8, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_FLOW_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p + 8, 2, 8, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_SOURCE_PORT_READ_G(r, g, idx)             GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 2, 8, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_SOURCE_PORT_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 2, 8, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_SOURCE_PORT_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 8, 2, 8, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_SOURCE_PORT_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 8, 2, 8, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_UNION3_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_UNION3_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_UNION3_READ(r, p)                         FIELD_MREAD_32((uint8_t *)p + 8, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_UNION3_WRITE(v, p)                        FIELD_MWRITE_32((uint8_t *)p + 8, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN1_FIRST_READ_G(r, g, idx)               GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN1_FIRST_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN1_FIRST_READ(r, p)                      FIELD_MREAD_32((uint8_t *)p + 8, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN1_FIRST_WRITE(v, p)                     FIELD_MWRITE_32((uint8_t *)p + 8, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS3_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS3_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 8, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS3_READ(r, p)                           FIELD_MREAD_32((uint8_t *)p + 8, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS3_WRITE(v, p)                          FIELD_MWRITE_32((uint8_t *)p + 8, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_AGG_PD_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 7, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_AGG_PD_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 7, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_AGG_PD_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_AGG_PD_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_TARGET_MEM_0_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 6, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_TARGET_MEM_0_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 6, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_TARGET_MEM_0_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 12, 6, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_TARGET_MEM_0_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 12, 6, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 5, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 5, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 12, 5, 1, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 12, 5, 1, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_READ_G(r, g, idx) GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 2, 11, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_WRITE_G(v, g, idx)GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 2, 11, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_READ(r, p)        FIELD_MREAD_16((uint8_t *)p + 12, 2, 11, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_WRITE(v, p)       FIELD_MWRITE_16((uint8_t *)p + 12, 2, 11, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_SOP_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 2, 11, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_SOP_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 2, 11, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_SOP_READ(r, p)                            FIELD_MREAD_16((uint8_t *)p + 12, 2, 11, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_SOP_WRITE(v, p)                           FIELD_MWRITE_16((uint8_t *)p + 12, 2, 11, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS1_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 2, 11, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS1_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 2, 11, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS1_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p + 12, 2, 11, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS1_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p + 12, 2, 11, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_READ_G(r, g, idx)GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_WRITE_G(v, g, idx)GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_READ(r, p)       FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_WRITE(v, p)      FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN0_FIRST_READ_G(r, g, idx)               GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN0_FIRST_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN0_FIRST_READ(r, p)                      FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_BN0_FIRST_WRITE(v, p)                     FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS0_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS0_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_TX_DESCRIPTOR_DTS) + 12, 0, 18, v)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS0_READ(r, p)                           FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_PROCESSING_TX_DESCRIPTOR_ABS0_WRITE(v, p)                          FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)

#define RDD_PD_FIFO_TABLE_SIZE     320
typedef struct
{
	RDD_PROCESSING_TX_DESCRIPTOR_DTS	entry[ RDD_PD_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PD_FIFO_TABLE_DTS;

extern uint32_t RDD_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_PD_FIFO_TABLE_PTR(core_id)	( RDD_PD_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_PD_FIFO_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	rate_limit_enable 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	block_type        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	prefetch_pd       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	enable            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved          	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_queue_index   	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scheduler_index   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue_bit_mask    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_index	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	quantum_number    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	deficit_counter   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	queue_bit_mask    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scheduler_index   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_queue_index   	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved          	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	enable            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	prefetch_pd       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	block_type        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limit_enable 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	deficit_counter   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	quantum_number    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_index	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS;

#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS), 6, 1, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS), 6, 1, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_BLOCK_TYPE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_PREFETCH_PD_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS), 5, 1, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_PREFETCH_PD_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS), 5, 1, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_PREFETCH_PD_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_PREFETCH_PD_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS), 4, 1, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS), 4, 1, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_ENABLE_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 1, 0, 6, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 1, 0, 6, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 0, 6, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_BBH_QUEUE_INDEX_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 0, 6, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ_G(r, g, idx)             GROUP_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 2, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE_G(v, g, idx)            GROUP_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 2, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ(r, p)                    MREAD_8((uint8_t *)p + 2, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE(v, p)                   MWRITE_8((uint8_t *)p + 2, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_READ_G(r, g, idx)              GROUP_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 3, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_WRITE_G(v, g, idx)             GROUP_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 3, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_READ(r, p)                     MREAD_8((uint8_t *)p + 3, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUEUE_BIT_MASK_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 3, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 4, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 4, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_READ(r, p)                 MREAD_8((uint8_t *)p + 4, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE(v, p)                MWRITE_8((uint8_t *)p + 4, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_READ_G(r, g, idx)              GROUP_MREAD_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 5, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_WRITE_G(v, g, idx)             GROUP_MWRITE_8(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 5, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_READ(r, p)                     MREAD_8((uint8_t *)p + 5, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_QUANTUM_NUMBER_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 5, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_DEFICIT_COUNTER_READ_G(r, g, idx)             GROUP_MREAD_16(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 6, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_DEFICIT_COUNTER_WRITE_G(v, g, idx)            GROUP_MWRITE_16(g, idx*sizeof(RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS) + 6, v)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_DEFICIT_COUNTER_READ(r, p)                    MREAD_16((uint8_t *)p + 6, r)
#define RDD_SCHEDULING_QUEUE_DESCRIPTOR_DEFICIT_COUNTER_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 6, v)

#define RDD_SCHEDULING_QUEUE_TABLE_SIZE     128
typedef struct
{
	RDD_SCHEDULING_QUEUE_DESCRIPTOR_DTS	entry[ RDD_SCHEDULING_QUEUE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SCHEDULING_QUEUE_TABLE_DTS;

extern uint32_t RDD_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SCHEDULING_QUEUE_TABLE_PTR(core_id)	( RDD_SCHEDULING_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SCHEDULING_QUEUE_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_G9991_PD_FIFO_TABLE_SIZE     64
typedef struct
{
	RDD_PROCESSING_TX_DESCRIPTOR_DTS	entry[ RDD_G9991_PD_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_PD_FIFO_TABLE_DTS;

extern uint32_t RDD_G9991_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_PD_FIFO_TABLE_PTR(core_id)	( RDD_G9991_PD_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_PD_FIFO_TABLE_ADDRESS_ARR[core_id] ))

#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RESERVED1_NUMBER	12
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_NUMBER	32

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	rate_limit_enable                                                   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_positive_budget                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	basic_scheduler_exists                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_queue                                                           	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_index                                                  	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dwrr_offset_pir                                                     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dwrr_offset_sir                                                     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	last_served_block_pir                                               	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	last_served_block_sir                                               	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	status_bit_vector                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	slot_budget_bit_vector_0                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	slot_budget_bit_vector_1                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ovl_rl_en                                                           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                           	:31	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved1[RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RESERVED1_NUMBER];
	uint8_t	block_index[RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_NUMBER];
#else
	uint32_t	last_served_block_sir                                               	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	last_served_block_pir                                               	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dwrr_offset_sir                                                     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dwrr_offset_pir                                                     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_index                                                  	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_queue                                                           	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	basic_scheduler_exists                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_positive_budget                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limit_enable                                                   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	status_bit_vector                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	slot_budget_bit_vector_0                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	slot_budget_bit_vector_1                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                           	:31	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ovl_rl_en                                                           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved1[RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RESERVED1_NUMBER];
	uint8_t	block_index[RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS;

#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS), 6, 1, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS), 6, 1, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BASIC_SCHEDULER_EXISTS_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS), 5, 1, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BASIC_SCHEDULER_EXISTS_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS), 5, 1, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BASIC_SCHEDULER_EXISTS_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BASIC_SCHEDULER_EXISTS_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BBH_QUEUE_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS), 7, 6, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BBH_QUEUE_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS), 7, 6, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BBH_QUEUE_READ(r, p)                                FIELD_MREAD_16((uint8_t *)p, 7, 6, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BBH_QUEUE_WRITE(v, p)                               FIELD_MWRITE_16((uint8_t *)p, 7, 6, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 1, 0, 7, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 1, 0, 7, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 0, 7, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 0, 7, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 2, 5, 3, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 2, 5, 3, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 2, 5, 3, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_PIR_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 2, 5, 3, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 2, 2, 3, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 2, 2, 3, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 2, 2, 3, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_SIR_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 2, 2, 3, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_LAST_SERVED_BLOCK_PIR_READ_G(r, g, idx)             GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 2, 5, 5, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_LAST_SERVED_BLOCK_PIR_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 2, 5, 5, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_LAST_SERVED_BLOCK_PIR_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p + 2, 5, 5, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_LAST_SERVED_BLOCK_PIR_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p + 2, 5, 5, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_LAST_SERVED_BLOCK_SIR_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 3, 0, 5, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_LAST_SERVED_BLOCK_SIR_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 3, 0, 5, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_LAST_SERVED_BLOCK_SIR_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 3, 0, 5, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_LAST_SERVED_BLOCK_SIR_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 3, 0, 5, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_STATUS_BIT_VECTOR_READ_G(r, g, idx)                 GROUP_MREAD_32(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 4, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_STATUS_BIT_VECTOR_WRITE_G(v, g, idx)                GROUP_MWRITE_32(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 4, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_STATUS_BIT_VECTOR_READ(r, p)                        MREAD_32((uint8_t *)p + 4, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_STATUS_BIT_VECTOR_WRITE(v, p)                       MWRITE_32((uint8_t *)p + 4, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 8, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 8, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_READ(r, p)                 MREAD_32((uint8_t *)p + 8, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_0_WRITE(v, p)                MWRITE_32((uint8_t *)p + 8, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_1_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 12, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_1_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 12, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_1_READ(r, p)                 MREAD_32((uint8_t *)p + 12, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_1_WRITE(v, p)                MWRITE_32((uint8_t *)p + 12, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_OVL_RL_EN_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 16, 7, 1, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_OVL_RL_EN_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 16, 7, 1, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_OVL_RL_EN_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 16, 7, 1, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_OVL_RL_EN_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 16, 7, 1, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_READ_G(r, g, idx, i)                    GROUP_MREAD_I_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 32, i, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_WRITE_G(v, g, idx, i)                   GROUP_MWRITE_I_8(g, idx*sizeof(RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS) + 32, i, v)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_READ(r, p, i)                           MREAD_I_8((uint8_t *)p + 32, i, r)
#define RDD_COMPLEX_SCHEDULER_DESCRIPTOR_BLOCK_INDEX_WRITE(v, p, i)                          MWRITE_I_8((uint8_t *)p + 32, i, v)

#define RDD_COMPLEX_SCHEDULER_TABLE_SIZE     16
typedef struct
{
	RDD_COMPLEX_SCHEDULER_DESCRIPTOR_DTS	entry[ RDD_COMPLEX_SCHEDULER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_COMPLEX_SCHEDULER_TABLE_DTS;

extern uint32_t RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_COMPLEX_SCHEDULER_TABLE_PTR(core_id)	( RDD_COMPLEX_SCHEDULER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_COMPLEX_SCHEDULER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	rl_type       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2     	:21	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	block_type    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	block_index   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_budget	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	alloc_mantissa	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	alloc_exponent	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	limit_mantissa	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	limit_exponent	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	block_index   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	block_type    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2     	:21	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rl_type       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_budget	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	limit_exponent	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	limit_mantissa	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	alloc_exponent	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	alloc_mantissa	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS;

#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_RL_TYPE_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_RL_TYPE_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_RL_TYPE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_RL_TYPE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 2, 0, 2, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 2, 0, 2, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 2, 0, 2, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 2, 0, 2, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_READ_G(r, g, idx)             GROUP_MREAD_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 3, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_WRITE_G(v, g, idx)            GROUP_MWRITE_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 3, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_READ(r, p)                    MREAD_8((uint8_t *)p + 3, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_WRITE(v, p)                   MWRITE_8((uint8_t *)p + 3, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 4, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 4, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 8, 2, 14, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 8, 2, 14, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 8, 2, 14, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 8, 2, 14, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 9, 0, 2, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 9, 0, 2, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 9, 0, 2, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 9, 0, 2, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 10, 2, 14, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 10, 2, 14, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 10, 2, 14, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 10, 2, 14, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 11, 0, 2, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS) + 11, 0, 2, v)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 11, 0, 2, r)
#define RDD_BASIC_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 11, 0, 2, v)

#define RDD_BASIC_RATE_LIMITER_TABLE_SIZE     128
typedef struct
{
	RDD_BASIC_RATE_LIMITER_DESCRIPTOR_DTS	entry[ RDD_BASIC_RATE_LIMITER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BASIC_RATE_LIMITER_TABLE_DTS;

extern uint32_t RDD_BASIC_RATE_LIMITER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BASIC_RATE_LIMITER_TABLE_PTR(core_id)	( RDD_BASIC_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BASIC_RATE_LIMITER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	timestamp              	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	event_id               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	trace_event_info       	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = trace_event_info, size = 18 bits
	uint32_t	incoming_task_num      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	task_pc                	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	incoming_bbhrx_src_addr	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_wr                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_rd                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_wr_reply           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ramrd                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	parser                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbhtx                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbhrx_async            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbhrx_sync             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fw_self                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fw                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2              	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	acc_type               	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
#else
	uint32_t	trace_event_info       	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = trace_event_info, size = 18 bits
	uint32_t	incoming_task_num      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	task_pc                	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	incoming_bbhrx_src_addr	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_wr                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_rd                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_wr_reply           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ramrd                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	parser                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbhtx                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbhrx_async            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbhrx_sync             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fw_self                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fw                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2              	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	acc_type               	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	event_id               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timestamp              	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TRACE_EVENT_DTS;

#define RDD_TRACE_EVENT_TIMESTAMP_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_TRACE_EVENT_DTS), 4, 12, r)
#define RDD_TRACE_EVENT_TIMESTAMP_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_TRACE_EVENT_DTS), 4, 12, v)
#define RDD_TRACE_EVENT_TIMESTAMP_READ(r, p)                               FIELD_MREAD_16((uint8_t *)p, 4, 12, r)
#define RDD_TRACE_EVENT_TIMESTAMP_WRITE(v, p)                              FIELD_MWRITE_16((uint8_t *)p, 4, 12, v)
#define RDD_TRACE_EVENT_EVENT_ID_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 1, 2, 2, r)
#define RDD_TRACE_EVENT_EVENT_ID_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 1, 2, 2, v)
#define RDD_TRACE_EVENT_EVENT_ID_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 1, 2, 2, r)
#define RDD_TRACE_EVENT_EVENT_ID_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 1, 2, 2, v)
#define RDD_TRACE_EVENT_TRACE_EVENT_INFO_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 0, 0, 18, r)
#define RDD_TRACE_EVENT_TRACE_EVENT_INFO_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 0, 0, 18, v)
#define RDD_TRACE_EVENT_TRACE_EVENT_INFO_READ(r, p)                        FIELD_MREAD_32((uint8_t *)p + 0, 0, 18, r)
#define RDD_TRACE_EVENT_TRACE_EVENT_INFO_WRITE(v, p)                       FIELD_MWRITE_32((uint8_t *)p + 0, 0, 18, v)
#define RDD_TRACE_EVENT_INCOMING_TASK_NUM_READ_G(r, g, idx)                GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 0, 14, 4, r)
#define RDD_TRACE_EVENT_INCOMING_TASK_NUM_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 0, 14, 4, v)
#define RDD_TRACE_EVENT_INCOMING_TASK_NUM_READ(r, p)                       FIELD_MREAD_32((uint8_t *)p + 0, 14, 4, r)
#define RDD_TRACE_EVENT_INCOMING_TASK_NUM_WRITE(v, p)                      FIELD_MWRITE_32((uint8_t *)p + 0, 14, 4, v)
#define RDD_TRACE_EVENT_TASK_PC_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 0, 13, r)
#define RDD_TRACE_EVENT_TASK_PC_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 0, 13, v)
#define RDD_TRACE_EVENT_TASK_PC_READ(r, p)                                 FIELD_MREAD_16((uint8_t *)p + 2, 0, 13, r)
#define RDD_TRACE_EVENT_TASK_PC_WRITE(v, p)                                FIELD_MWRITE_16((uint8_t *)p + 2, 0, 13, v)
#define RDD_TRACE_EVENT_INCOMING_BBHRX_SRC_ADDR_READ_G(r, g, idx)          GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 0, 12, 6, r)
#define RDD_TRACE_EVENT_INCOMING_BBHRX_SRC_ADDR_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 0, 12, 6, v)
#define RDD_TRACE_EVENT_INCOMING_BBHRX_SRC_ADDR_READ(r, p)                 FIELD_MREAD_32((uint8_t *)p + 0, 12, 6, r)
#define RDD_TRACE_EVENT_INCOMING_BBHRX_SRC_ADDR_WRITE(v, p)                FIELD_MWRITE_32((uint8_t *)p + 0, 12, 6, v)
#define RDD_TRACE_EVENT_DMA_WR_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 3, 1, r)
#define RDD_TRACE_EVENT_DMA_WR_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 3, 1, v)
#define RDD_TRACE_EVENT_DMA_WR_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 2, 3, 1, r)
#define RDD_TRACE_EVENT_DMA_WR_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 2, 3, 1, v)
#define RDD_TRACE_EVENT_DMA_RD_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 2, 1, r)
#define RDD_TRACE_EVENT_DMA_RD_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 2, 1, v)
#define RDD_TRACE_EVENT_DMA_RD_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 2, 2, 1, r)
#define RDD_TRACE_EVENT_DMA_RD_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 2, 2, 1, v)
#define RDD_TRACE_EVENT_DMA_WR_REPLY_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 1, 1, r)
#define RDD_TRACE_EVENT_DMA_WR_REPLY_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 1, 1, v)
#define RDD_TRACE_EVENT_DMA_WR_REPLY_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 2, 1, 1, r)
#define RDD_TRACE_EVENT_DMA_WR_REPLY_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 2, 1, 1, v)
#define RDD_TRACE_EVENT_RAMRD_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 0, 1, r)
#define RDD_TRACE_EVENT_RAMRD_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 0, 1, v)
#define RDD_TRACE_EVENT_RAMRD_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_TRACE_EVENT_RAMRD_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_TRACE_EVENT_PARSER_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 7, 1, r)
#define RDD_TRACE_EVENT_PARSER_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 7, 1, v)
#define RDD_TRACE_EVENT_PARSER_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 3, 7, 1, r)
#define RDD_TRACE_EVENT_PARSER_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 3, 7, 1, v)
#define RDD_TRACE_EVENT_BBHTX_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 6, 1, r)
#define RDD_TRACE_EVENT_BBHTX_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 6, 1, v)
#define RDD_TRACE_EVENT_BBHTX_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 3, 6, 1, r)
#define RDD_TRACE_EVENT_BBHTX_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 3, 6, 1, v)
#define RDD_TRACE_EVENT_BBHRX_ASYNC_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 5, 1, r)
#define RDD_TRACE_EVENT_BBHRX_ASYNC_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 5, 1, v)
#define RDD_TRACE_EVENT_BBHRX_ASYNC_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 3, 5, 1, r)
#define RDD_TRACE_EVENT_BBHRX_ASYNC_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 3, 5, 1, v)
#define RDD_TRACE_EVENT_BBHRX_SYNC_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 4, 1, r)
#define RDD_TRACE_EVENT_BBHRX_SYNC_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 4, 1, v)
#define RDD_TRACE_EVENT_BBHRX_SYNC_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 3, 4, 1, r)
#define RDD_TRACE_EVENT_BBHRX_SYNC_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 3, 4, 1, v)
#define RDD_TRACE_EVENT_CPU_READ_G(r, g, idx)                              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 3, 1, r)
#define RDD_TRACE_EVENT_CPU_WRITE_G(v, g, idx)                             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 3, 1, v)
#define RDD_TRACE_EVENT_CPU_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 3, 3, 1, r)
#define RDD_TRACE_EVENT_CPU_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 3, 3, 1, v)
#define RDD_TRACE_EVENT_FW_SELF_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 2, 1, r)
#define RDD_TRACE_EVENT_FW_SELF_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 2, 1, v)
#define RDD_TRACE_EVENT_FW_SELF_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 3, 2, 1, r)
#define RDD_TRACE_EVENT_FW_SELF_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 3, 2, 1, v)
#define RDD_TRACE_EVENT_FW_READ_G(r, g, idx)                               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 1, 1, r)
#define RDD_TRACE_EVENT_FW_WRITE_G(v, g, idx)                              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 1, 1, v)
#define RDD_TRACE_EVENT_FW_READ(r, p)                                      FIELD_MREAD_8((uint8_t *)p + 3, 1, 1, r)
#define RDD_TRACE_EVENT_FW_WRITE(v, p)                                     FIELD_MWRITE_8((uint8_t *)p + 3, 1, 1, v)
#define RDD_TRACE_EVENT_TIMER_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 0, 1, r)
#define RDD_TRACE_EVENT_TIMER_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 3, 0, 1, v)
#define RDD_TRACE_EVENT_TIMER_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 3, 0, 1, r)
#define RDD_TRACE_EVENT_TIMER_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 3, 0, 1, v)
#define RDD_TRACE_EVENT_ACC_TYPE_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 0, 12, r)
#define RDD_TRACE_EVENT_ACC_TYPE_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_TRACE_EVENT_DTS) + 2, 0, 12, v)
#define RDD_TRACE_EVENT_ACC_TYPE_READ(r, p)                                FIELD_MREAD_16((uint8_t *)p + 2, 0, 12, r)
#define RDD_TRACE_EVENT_ACC_TYPE_WRITE(v, p)                               FIELD_MWRITE_16((uint8_t *)p + 2, 0, 12, v)

#define RDD_RUNNER_PROFILING_TRACE_BUFFER_SIZE     128
typedef struct
{
	RDD_TRACE_EVENT_DTS	entry[ RDD_RUNNER_PROFILING_TRACE_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_PROFILING_TRACE_BUFFER_DTS;

extern uint32_t RDD_RUNNER_PROFILING_TRACE_BUFFER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_RUNNER_PROFILING_TRACE_BUFFER_PTR(core_id)	( RDD_RUNNER_PROFILING_TRACE_BUFFER_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_RUNNER_PROFILING_TRACE_BUFFER_ADDRESS_ARR[core_id] ))

#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUEUE_INDEX_NUMBER	8

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	rate_limit_enable                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	complex_scheduler_exists                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dwrr_offset                                                      	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	last_served_queue                                                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	parent_index                                                     	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = parent_index, size = 9 bits
	uint32_t	complex_scheduler_slot_index                                     	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	complex_scheduler_index                                          	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_queue                                                        	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ovl_rl_en                                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_positive_budget                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	slot_budget_bit_vector                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	status_bit_vector                                                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_index                                               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	quantum_number                                                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	deficit_counter                                                  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	queue_index[RDD_BASIC_SCHEDULER_DESCRIPTOR_QUEUE_INDEX_NUMBER];
#else
	uint32_t	status_bit_vector                                                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	slot_budget_bit_vector                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	parent_index                                                     	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = parent_index, size = 9 bits
	uint32_t	complex_scheduler_slot_index                                     	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	complex_scheduler_index                                          	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbh_queue                                                        	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ovl_rl_en                                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_positive_budget                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	last_served_queue                                                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dwrr_offset                                                      	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	complex_scheduler_exists                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limit_enable                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	deficit_counter                                                  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	quantum_number                                                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rate_limiter_index                                               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	queue_index[RDD_BASIC_SCHEDULER_DESCRIPTOR_QUEUE_INDEX_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS;

#define RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMIT_ENABLE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_EXISTS_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 6, 1, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_EXISTS_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 6, 1, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_EXISTS_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_EXISTS_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 4, 2, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 4, 2, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p, 4, 2, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_DWRR_OFFSET_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p, 4, 2, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_LAST_SERVED_QUEUE_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 1, 3, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_LAST_SERVED_QUEUE_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 1, 3, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_LAST_SERVED_QUEUE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p, 1, 3, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_LAST_SERVED_QUEUE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p, 1, 3, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_PARENT_INDEX_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 0, 9, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_PARENT_INDEX_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 0, 9, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_PARENT_INDEX_READ(r, p)                                 FIELD_MREAD_16((uint8_t *)p, 0, 9, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_PARENT_INDEX_WRITE(v, p)                                FIELD_MWRITE_16((uint8_t *)p, 0, 9, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_SLOT_INDEX_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 4, 5, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_SLOT_INDEX_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 4, 5, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_SLOT_INDEX_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 4, 5, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_SLOT_INDEX_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 4, 5, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_INDEX_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 1, 0, 4, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_INDEX_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 1, 0, 4, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_INDEX_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 1, 0, 4, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_COMPLEX_SCHEDULER_INDEX_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 1, 0, 4, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_BBH_QUEUE_READ_G(r, g, idx)                             GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 3, 6, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_BBH_QUEUE_WRITE_G(v, g, idx)                            GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS), 3, 6, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_BBH_QUEUE_READ(r, p)                                    FIELD_MREAD_16((uint8_t *)p, 3, 6, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_BBH_QUEUE_WRITE(v, p)                                   FIELD_MWRITE_16((uint8_t *)p, 3, 6, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_OVL_RL_EN_READ_G(r, g, idx)                             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 1, 2, 1, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_OVL_RL_EN_WRITE_G(v, g, idx)                            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 1, 2, 1, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_OVL_RL_EN_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 1, 2, 1, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_OVL_RL_EN_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 1, 2, 1, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 1, 1, 1, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 1, 1, 1, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_IS_POSITIVE_BUDGET_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_READ_G(r, g, idx)                GROUP_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 2, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_WRITE_G(v, g, idx)               GROUP_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 2, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_READ(r, p)                       MREAD_8((uint8_t *)p + 2, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_SLOT_BUDGET_BIT_VECTOR_WRITE(v, p)                      MWRITE_8((uint8_t *)p + 2, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_STATUS_BIT_VECTOR_READ_G(r, g, idx)                     GROUP_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 3, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_STATUS_BIT_VECTOR_WRITE_G(v, g, idx)                    GROUP_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 3, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_STATUS_BIT_VECTOR_READ(r, p)                            MREAD_8((uint8_t *)p + 3, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_STATUS_BIT_VECTOR_WRITE(v, p)                           MWRITE_8((uint8_t *)p + 3, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_READ_G(r, g, idx)                    GROUP_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 4, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE_G(v, g, idx)                   GROUP_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 4, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_READ(r, p)                           MREAD_8((uint8_t *)p + 4, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_RATE_LIMITER_INDEX_WRITE(v, p)                          MWRITE_8((uint8_t *)p + 4, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_READ_G(r, g, idx)                        GROUP_MREAD_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 5, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_WRITE_G(v, g, idx)                       GROUP_MWRITE_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 5, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_READ(r, p)                               MREAD_8((uint8_t *)p + 5, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUANTUM_NUMBER_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 5, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_DEFICIT_COUNTER_READ_G(r, g, idx)                       GROUP_MREAD_16(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 6, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_DEFICIT_COUNTER_WRITE_G(v, g, idx)                      GROUP_MWRITE_16(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 6, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_DEFICIT_COUNTER_READ(r, p)                              MREAD_16((uint8_t *)p + 6, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_DEFICIT_COUNTER_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 6, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUEUE_INDEX_READ_G(r, g, idx, i)                        GROUP_MREAD_I_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 8, i, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUEUE_INDEX_WRITE_G(v, g, idx, i)                       GROUP_MWRITE_I_8(g, idx*sizeof(RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS) + 8, i, v)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUEUE_INDEX_READ(r, p, i)                               MREAD_I_8((uint8_t *)p + 8, i, r)
#define RDD_BASIC_SCHEDULER_DESCRIPTOR_QUEUE_INDEX_WRITE(v, p, i)                              MWRITE_I_8((uint8_t *)p + 8, i, v)

#define RDD_BASIC_SCHEDULER_TABLE_SIZE     32
typedef struct
{
	RDD_BASIC_SCHEDULER_DESCRIPTOR_DTS	entry[ RDD_BASIC_SCHEDULER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BASIC_SCHEDULER_TABLE_DTS;

extern uint32_t RDD_BASIC_SCHEDULER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BASIC_SCHEDULER_TABLE_PTR(core_id)	( RDD_BASIC_SCHEDULER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BASIC_SCHEDULER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	reserved       	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mirroring_en   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scheduler_index	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scheduler_type 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bb_destination 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_counter	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	ingress_counter	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bb_destination 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scheduler_type 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scheduler_index	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	priority       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mirroring_en   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved       	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_QUEUE_DESCRIPTOR_DTS;

#define RDD_BBH_QUEUE_DESCRIPTOR_MIRRORING_EN_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS), 1, 1, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_MIRRORING_EN_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS), 1, 1, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_MIRRORING_EN_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_MIRRORING_EN_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_PRIORITY_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS), 0, 1, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_PRIORITY_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS), 0, 1, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_PRIORITY_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_PRIORITY_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) + 1, 1, 7, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) + 1, 1, 7, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 1, 7, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_INDEX_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 1, 7, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) + 1, 0, 1, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) + 1, 0, 1, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 1, 0, 1, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_SCHEDULER_TYPE_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 1, 0, 1, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_READ_G(r, g, idx)           GROUP_MREAD_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) + 2, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE_G(v, g, idx)          GROUP_MWRITE_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) + 2, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_READ(r, p)                  MREAD_8((uint8_t *)p + 2, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_BB_DESTINATION_WRITE(v, p)                 MWRITE_8((uint8_t *)p + 2, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_INGRESS_COUNTER_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) + 3, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_INGRESS_COUNTER_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_BBH_QUEUE_DESCRIPTOR_DTS) + 3, v)
#define RDD_BBH_QUEUE_DESCRIPTOR_INGRESS_COUNTER_READ(r, p)                 MREAD_8((uint8_t *)p + 3, r)
#define RDD_BBH_QUEUE_DESCRIPTOR_INGRESS_COUNTER_WRITE(v, p)                MWRITE_8((uint8_t *)p + 3, v)

#define RDD_BBH_QUEUE_TABLE_SIZE     40
typedef struct
{
	RDD_BBH_QUEUE_DESCRIPTOR_DTS	entry[ RDD_BBH_QUEUE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_QUEUE_TABLE_DTS;

extern uint32_t RDD_BBH_QUEUE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_QUEUE_TABLE_PTR(core_id)	( RDD_BBH_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_QUEUE_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	counter   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0 	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	reserved0 	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	counter   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS;

#define RDD_BBH_TX_EGRESS_COUNTER_ENTRY_COUNTER_READ_G(r, g, idx)            GROUP_MREAD_8(g, idx*sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS), r)
#define RDD_BBH_TX_EGRESS_COUNTER_ENTRY_COUNTER_WRITE_G(v, g, idx)           GROUP_MWRITE_8(g, idx*sizeof(RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS), v)
#define RDD_BBH_TX_EGRESS_COUNTER_ENTRY_COUNTER_READ(r, p)                   MREAD_8((uint8_t *)p, r)
#define RDD_BBH_TX_EGRESS_COUNTER_ENTRY_COUNTER_WRITE(v, p)                  MWRITE_8((uint8_t *)p, v)

#define RDD_BBH_TX_EGRESS_COUNTER_TABLE_SIZE     4
typedef struct
{
	RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS	entry[ RDD_BBH_TX_EGRESS_COUNTER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_EGRESS_COUNTER_TABLE_DTS;

extern uint32_t RDD_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_TX_EGRESS_COUNTER_TABLE_PTR(core_id)	( RDD_BBH_TX_EGRESS_COUNTER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_TX_EGRESS_COUNTER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	remaining_bytes	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	not_sof        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	not_sof        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	remaining_bytes	:15	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_FIFO_DESCRIPTOR_ENTRY_DTS;

#define RDD_G9991_FIFO_DESCRIPTOR_ENTRY_REMAINING_BYTES_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_G9991_FIFO_DESCRIPTOR_ENTRY_DTS), 1, 15, r)
#define RDD_G9991_FIFO_DESCRIPTOR_ENTRY_REMAINING_BYTES_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_G9991_FIFO_DESCRIPTOR_ENTRY_DTS), 1, 15, v)
#define RDD_G9991_FIFO_DESCRIPTOR_ENTRY_REMAINING_BYTES_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 1, 15, r)
#define RDD_G9991_FIFO_DESCRIPTOR_ENTRY_REMAINING_BYTES_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 1, 15, v)
#define RDD_G9991_FIFO_DESCRIPTOR_ENTRY_NOT_SOF_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_G9991_FIFO_DESCRIPTOR_ENTRY_DTS) + 1, 0, 1, r)
#define RDD_G9991_FIFO_DESCRIPTOR_ENTRY_NOT_SOF_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_G9991_FIFO_DESCRIPTOR_ENTRY_DTS) + 1, 0, 1, v)
#define RDD_G9991_FIFO_DESCRIPTOR_ENTRY_NOT_SOF_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 1, 0, 1, r)
#define RDD_G9991_FIFO_DESCRIPTOR_ENTRY_NOT_SOF_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 1, 0, 1, v)

#define RDD_G9991_FIFO_DESCRIPTOR_TABLE_SIZE     32
typedef struct
{
	RDD_G9991_FIFO_DESCRIPTOR_ENTRY_DTS	entry[ RDD_G9991_FIFO_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_FIFO_DESCRIPTOR_TABLE_DTS;

extern uint32_t RDD_G9991_FIFO_DESCRIPTOR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_FIFO_DESCRIPTOR_TABLE_PTR(core_id)	( RDD_G9991_FIFO_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_FIFO_DESCRIPTOR_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	cntr_id   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint8_t	cntr_id   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TM_FLOW_CNTR_ENTRY_DTS;

#define RDD_TM_FLOW_CNTR_ENTRY_CNTR_ID_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_TM_FLOW_CNTR_ENTRY_DTS), r)
#define RDD_TM_FLOW_CNTR_ENTRY_CNTR_ID_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_TM_FLOW_CNTR_ENTRY_DTS), v)
#define RDD_TM_FLOW_CNTR_ENTRY_CNTR_ID_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_TM_FLOW_CNTR_ENTRY_CNTR_ID_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)

#define RDD_TM_FLOW_CNTR_TABLE_SIZE     128
typedef struct
{
	RDD_TM_FLOW_CNTR_ENTRY_DTS	entry[ RDD_TM_FLOW_CNTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TM_FLOW_CNTR_TABLE_DTS;

extern uint32_t RDD_TM_FLOW_CNTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TM_FLOW_CNTR_TABLE_PTR(core_id)	( RDD_TM_FLOW_CNTR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TM_FLOW_CNTR_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	bits      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	bits      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BYTES_4_DTS;

#define RDD_BYTES_4_BITS_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_BYTES_4_DTS), r)
#define RDD_BYTES_4_BITS_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_BYTES_4_DTS), v)
#define RDD_BYTES_4_BITS_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_BYTES_4_BITS_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)

#define RDD_REGISTERS_BUFFER_SIZE     32
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_REGISTERS_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REGISTERS_BUFFER_DTS;

extern uint32_t RDD_REGISTERS_BUFFER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_REGISTERS_BUFFER_PTR(core_id)	( RDD_REGISTERS_BUFFER_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_REGISTERS_BUFFER_ADDRESS_ARR[core_id] ))

#define RDD_NATC_TBL_CONFIGURATION_RESERVED1_NUMBER	5

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	key_addr_low                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_addr_high                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	res_addr_low                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	res_addr_high                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                                                 	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	miss_cache_enable                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_size                                                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_size                                             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved1[RDD_NATC_TBL_CONFIGURATION_RESERVED1_NUMBER];
#else
	uint32_t	key_addr_low                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_addr_high                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	res_addr_low                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	res_addr_high                                            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved1[RDD_NATC_TBL_CONFIGURATION_RESERVED1_NUMBER];
	uint32_t	context_size                                             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_size                                                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	miss_cache_enable                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                                                 	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NATC_TBL_CONFIGURATION_DTS;

#define RDD_NATC_TBL_CONFIGURATION_KEY_ADDR_LOW_READ_G(r, g, idx)               GROUP_MREAD_32(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS), r)
#define RDD_NATC_TBL_CONFIGURATION_KEY_ADDR_LOW_WRITE_G(v, g, idx)              GROUP_MWRITE_32(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS), v)
#define RDD_NATC_TBL_CONFIGURATION_KEY_ADDR_LOW_READ(r, p)                      MREAD_32((uint8_t *)p, r)
#define RDD_NATC_TBL_CONFIGURATION_KEY_ADDR_LOW_WRITE(v, p)                     MWRITE_32((uint8_t *)p, v)
#define RDD_NATC_TBL_CONFIGURATION_KEY_ADDR_HIGH_READ_G(r, g, idx)              GROUP_MREAD_32(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 4, r)
#define RDD_NATC_TBL_CONFIGURATION_KEY_ADDR_HIGH_WRITE_G(v, g, idx)             GROUP_MWRITE_32(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 4, v)
#define RDD_NATC_TBL_CONFIGURATION_KEY_ADDR_HIGH_READ(r, p)                     MREAD_32((uint8_t *)p + 4, r)
#define RDD_NATC_TBL_CONFIGURATION_KEY_ADDR_HIGH_WRITE(v, p)                    MWRITE_32((uint8_t *)p + 4, v)
#define RDD_NATC_TBL_CONFIGURATION_RES_ADDR_LOW_READ_G(r, g, idx)               GROUP_MREAD_32(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 8, r)
#define RDD_NATC_TBL_CONFIGURATION_RES_ADDR_LOW_WRITE_G(v, g, idx)              GROUP_MWRITE_32(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 8, v)
#define RDD_NATC_TBL_CONFIGURATION_RES_ADDR_LOW_READ(r, p)                      MREAD_32((uint8_t *)p + 8, r)
#define RDD_NATC_TBL_CONFIGURATION_RES_ADDR_LOW_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 8, v)
#define RDD_NATC_TBL_CONFIGURATION_RES_ADDR_HIGH_READ_G(r, g, idx)              GROUP_MREAD_32(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 12, r)
#define RDD_NATC_TBL_CONFIGURATION_RES_ADDR_HIGH_WRITE_G(v, g, idx)             GROUP_MWRITE_32(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 12, v)
#define RDD_NATC_TBL_CONFIGURATION_RES_ADDR_HIGH_READ(r, p)                     MREAD_32((uint8_t *)p + 12, r)
#define RDD_NATC_TBL_CONFIGURATION_RES_ADDR_HIGH_WRITE(v, p)                    MWRITE_32((uint8_t *)p + 12, v)
#define RDD_NATC_TBL_CONFIGURATION_MISS_CACHE_ENABLE_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 16, 0, 1, r)
#define RDD_NATC_TBL_CONFIGURATION_MISS_CACHE_ENABLE_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 16, 0, 1, v)
#define RDD_NATC_TBL_CONFIGURATION_MISS_CACHE_ENABLE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 16, 0, 1, r)
#define RDD_NATC_TBL_CONFIGURATION_MISS_CACHE_ENABLE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 16, 0, 1, v)
#define RDD_NATC_TBL_CONFIGURATION_KEY_SIZE_READ_G(r, g, idx)                   GROUP_MREAD_8(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 17, r)
#define RDD_NATC_TBL_CONFIGURATION_KEY_SIZE_WRITE_G(v, g, idx)                  GROUP_MWRITE_8(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 17, v)
#define RDD_NATC_TBL_CONFIGURATION_KEY_SIZE_READ(r, p)                          MREAD_8((uint8_t *)p + 17, r)
#define RDD_NATC_TBL_CONFIGURATION_KEY_SIZE_WRITE(v, p)                         MWRITE_8((uint8_t *)p + 17, v)
#define RDD_NATC_TBL_CONFIGURATION_CONTEXT_SIZE_READ_G(r, g, idx)               GROUP_MREAD_8(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 18, r)
#define RDD_NATC_TBL_CONFIGURATION_CONTEXT_SIZE_WRITE_G(v, g, idx)              GROUP_MWRITE_8(g, idx*sizeof(RDD_NATC_TBL_CONFIGURATION_DTS) + 18, v)
#define RDD_NATC_TBL_CONFIGURATION_CONTEXT_SIZE_READ(r, p)                      MREAD_8((uint8_t *)p + 18, r)
#define RDD_NATC_TBL_CONFIGURATION_CONTEXT_SIZE_WRITE(v, p)                     MWRITE_8((uint8_t *)p + 18, v)

#define RDD_NATC_TBL_CFG_SIZE     2
typedef struct
{
	RDD_NATC_TBL_CONFIGURATION_DTS	entry[ RDD_NATC_TBL_CFG_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NATC_TBL_CFG_DTS;

extern uint32_t RDD_NATC_TBL_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_NATC_TBL_CFG_PTR(core_id)	( RDD_NATC_TBL_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_NATC_TBL_CFG_ADDRESS_ARR[core_id] ))


#define RDD_G9991_CONTROL_SID_TABLE_SIZE     4
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_G9991_CONTROL_SID_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_CONTROL_SID_TABLE_DTS;

extern uint32_t RDD_G9991_CONTROL_SID_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_CONTROL_SID_TABLE_PTR(core_id)	( RDD_G9991_CONTROL_SID_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_CONTROL_SID_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	bits      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	bits      	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BYTES_2_DTS;

#define RDD_BYTES_2_BITS_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_BYTES_2_DTS), r)
#define RDD_BYTES_2_BITS_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_BYTES_2_DTS), v)
#define RDD_BYTES_2_BITS_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_BYTES_2_BITS_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)

#define RDD_TM_ACTION_PTR_TABLE_SIZE     17
typedef struct
{
	RDD_BYTES_2_DTS	entry[ RDD_TM_ACTION_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TM_ACTION_PTR_TABLE_DTS;

extern uint32_t RDD_TM_ACTION_PTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TM_ACTION_PTR_TABLE_PTR(core_id)	( RDD_TM_ACTION_PTR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TM_ACTION_PTR_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_2_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TM_ERROR_DEBUG_COUNTER_DTS;

extern uint32_t RDD_TM_ERROR_DEBUG_COUNTER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TM_ERROR_DEBUG_COUNTER_PTR(core_id)	( RDD_TM_ERROR_DEBUG_COUNTER_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TM_ERROR_DEBUG_COUNTER_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_4_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_FLOW_CONTROL_VECTOR_DTS;

extern uint32_t RDD_G9991_FLOW_CONTROL_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_FLOW_CONTROL_VECTOR_PTR(core_id)	( RDD_G9991_FLOW_CONTROL_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_FLOW_CONTROL_VECTOR_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	ingress_vector	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_vector 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	ingress_vector	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_vector 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_FIFO_POINTER_ENTRY_DTS;

#define RDD_G9991_FIFO_POINTER_ENTRY_INGRESS_VECTOR_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_G9991_FIFO_POINTER_ENTRY_DTS), r)
#define RDD_G9991_FIFO_POINTER_ENTRY_INGRESS_VECTOR_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_G9991_FIFO_POINTER_ENTRY_DTS), v)
#define RDD_G9991_FIFO_POINTER_ENTRY_INGRESS_VECTOR_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_G9991_FIFO_POINTER_ENTRY_INGRESS_VECTOR_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_G9991_FIFO_POINTER_ENTRY_EGRESS_VECTOR_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_G9991_FIFO_POINTER_ENTRY_DTS) + 4, r)
#define RDD_G9991_FIFO_POINTER_ENTRY_EGRESS_VECTOR_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_G9991_FIFO_POINTER_ENTRY_DTS) + 4, v)
#define RDD_G9991_FIFO_POINTER_ENTRY_EGRESS_VECTOR_READ(r, p)                  MREAD_32((uint8_t *)p + 4, r)
#define RDD_G9991_FIFO_POINTER_ENTRY_EGRESS_VECTOR_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 4, v)
typedef struct
{
	RDD_G9991_FIFO_POINTER_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_FIFO_POINTER_VECTOR_DTS;

extern uint32_t RDD_G9991_FIFO_POINTER_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_FIFO_POINTER_VECTOR_PTR(core_id)	( RDD_G9991_FIFO_POINTER_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_FIFO_POINTER_VECTOR_ADDRESS_ARR[core_id] ))


#define RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_SIZE     4
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_DTS;

extern uint32_t RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_PTR(core_id)	( RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_SID_TO_PHYSICAL_PORT_MASK_ADDRESS_ARR[core_id] ))


#define RDD_RUNNER_GLOBAL_REGISTERS_INIT_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_RUNNER_GLOBAL_REGISTERS_INIT_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RUNNER_GLOBAL_REGISTERS_INIT_DTS;

extern uint32_t RDD_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_RUNNER_GLOBAL_REGISTERS_INIT_PTR(core_id)	( RDD_RUNNER_GLOBAL_REGISTERS_INIT_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_RUNNER_GLOBAL_REGISTERS_INIT_ADDRESS_ARR[core_id] ))


#define RDD_SCHEDULING_FLUSH_VECTOR_SIZE     5
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_SCHEDULING_FLUSH_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SCHEDULING_FLUSH_VECTOR_DTS;

extern uint32_t RDD_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SCHEDULING_FLUSH_VECTOR_PTR(core_id)	( RDD_SCHEDULING_FLUSH_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SCHEDULING_FLUSH_VECTOR_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_4_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_NOT_FULL_VECTOR_DTS;

extern uint32_t RDD_G9991_NOT_FULL_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_NOT_FULL_VECTOR_PTR(core_id)	( RDD_G9991_NOT_FULL_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_NOT_FULL_VECTOR_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	vector         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved       	:27	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	last_served_sid	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	vector         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	last_served_sid	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved       	:27	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_PENDING_VECTOR_ENTRY_DTS;

#define RDD_G9991_PENDING_VECTOR_ENTRY_VECTOR_READ_G(r, g, idx)                   GROUP_MREAD_32(g, idx*sizeof(RDD_G9991_PENDING_VECTOR_ENTRY_DTS), r)
#define RDD_G9991_PENDING_VECTOR_ENTRY_VECTOR_WRITE_G(v, g, idx)                  GROUP_MWRITE_32(g, idx*sizeof(RDD_G9991_PENDING_VECTOR_ENTRY_DTS), v)
#define RDD_G9991_PENDING_VECTOR_ENTRY_VECTOR_READ(r, p)                          MREAD_32((uint8_t *)p, r)
#define RDD_G9991_PENDING_VECTOR_ENTRY_VECTOR_WRITE(v, p)                         MWRITE_32((uint8_t *)p, v)
#define RDD_G9991_PENDING_VECTOR_ENTRY_LAST_SERVED_SID_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_G9991_PENDING_VECTOR_ENTRY_DTS) + 7, 0, 5, r)
#define RDD_G9991_PENDING_VECTOR_ENTRY_LAST_SERVED_SID_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_G9991_PENDING_VECTOR_ENTRY_DTS) + 7, 0, 5, v)
#define RDD_G9991_PENDING_VECTOR_ENTRY_LAST_SERVED_SID_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 7, 0, 5, r)
#define RDD_G9991_PENDING_VECTOR_ENTRY_LAST_SERVED_SID_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 7, 0, 5, v)
typedef struct
{
	RDD_G9991_PENDING_VECTOR_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_NOT_EMPTY_VECTOR_DTS;

extern uint32_t RDD_G9991_NOT_EMPTY_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_NOT_EMPTY_VECTOR_PTR(core_id)	( RDD_G9991_NOT_EMPTY_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_NOT_EMPTY_VECTOR_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	valid            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pd_fifo_write_ptr	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue_number     	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	queue_number     	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0        	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pd_fifo_write_ptr	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_UPDATE_FIFO_ENTRY_DTS;

#define RDD_UPDATE_FIFO_ENTRY_VALID_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_UPDATE_FIFO_ENTRY_DTS), 7, 1, r)
#define RDD_UPDATE_FIFO_ENTRY_VALID_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_UPDATE_FIFO_ENTRY_DTS), 7, 1, v)
#define RDD_UPDATE_FIFO_ENTRY_VALID_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_UPDATE_FIFO_ENTRY_VALID_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_UPDATE_FIFO_ENTRY_PD_FIFO_WRITE_PTR_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_UPDATE_FIFO_ENTRY_DTS), 0, 14, r)
#define RDD_UPDATE_FIFO_ENTRY_PD_FIFO_WRITE_PTR_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_UPDATE_FIFO_ENTRY_DTS), 0, 14, v)
#define RDD_UPDATE_FIFO_ENTRY_PD_FIFO_WRITE_PTR_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 0, 14, r)
#define RDD_UPDATE_FIFO_ENTRY_PD_FIFO_WRITE_PTR_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 0, 14, v)
#define RDD_UPDATE_FIFO_ENTRY_QUEUE_NUMBER_READ_G(r, g, idx)               GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_UPDATE_FIFO_ENTRY_DTS) + 2, 0, 9, r)
#define RDD_UPDATE_FIFO_ENTRY_QUEUE_NUMBER_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_UPDATE_FIFO_ENTRY_DTS) + 2, 0, 9, v)
#define RDD_UPDATE_FIFO_ENTRY_QUEUE_NUMBER_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 2, 0, 9, r)
#define RDD_UPDATE_FIFO_ENTRY_QUEUE_NUMBER_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 2, 0, 9, v)

#define RDD_UPDATE_FIFO_TABLE_SIZE     8
typedef struct
{
	RDD_UPDATE_FIFO_ENTRY_DTS	entry[ RDD_UPDATE_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_UPDATE_FIFO_TABLE_DTS;

extern uint32_t RDD_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_UPDATE_FIFO_TABLE_PTR(core_id)	( RDD_UPDATE_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_UPDATE_FIFO_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_SCHEDULING_QUEUE_AGING_VECTOR_SIZE     5
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_SCHEDULING_QUEUE_AGING_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SCHEDULING_QUEUE_AGING_VECTOR_DTS;

extern uint32_t RDD_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SCHEDULING_QUEUE_AGING_VECTOR_PTR(core_id)	( RDD_SCHEDULING_QUEUE_AGING_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SCHEDULING_QUEUE_AGING_VECTOR_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	bits      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint8_t	bits      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BYTE_1_DTS;

#define RDD_BYTE_1_BITS_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_BYTE_1_DTS), r)
#define RDD_BYTE_1_BITS_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_BYTE_1_DTS), v)
#define RDD_BYTE_1_BITS_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_BYTE_1_BITS_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)

#define RDD_G9991_PHYS_PORT_BB_ID_TABLE_SIZE     4
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_G9991_PHYS_PORT_BB_ID_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_PHYS_PORT_BB_ID_TABLE_DTS;

extern uint32_t RDD_G9991_PHYS_PORT_BB_ID_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_PHYS_PORT_BB_ID_TABLE_PTR(core_id)	( RDD_G9991_PHYS_PORT_BB_ID_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_PHYS_PORT_BB_ID_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_G9991_PENDING_VECTOR_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PENDING_VECTOR_DTS;

extern uint32_t RDD_PENDING_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_PENDING_VECTOR_PTR(core_id)	( RDD_PENDING_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_PENDING_VECTOR_ADDRESS_ARR[core_id] ))


#define RDD_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_SIZE     5
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_DTS;

extern uint32_t RDD_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_PTR(core_id)	( RDD_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SCHEDULING_AGGREGATION_CONTEXT_VECTOR_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_4_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_BBH_TX_BYTES_FIFO_SIZE_DTS;

extern uint32_t RDD_G9991_BBH_TX_BYTES_FIFO_SIZE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_BBH_TX_BYTES_FIFO_SIZE_PTR(core_id)	( RDD_G9991_BBH_TX_BYTES_FIFO_SIZE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_BBH_TX_BYTES_FIFO_SIZE_ADDRESS_ARR[core_id] ))

#define RDD_BYTES_8_BITS_NUMBER	2

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	bits[RDD_BYTES_8_BITS_NUMBER];
#else
	uint32_t	bits[RDD_BYTES_8_BITS_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BYTES_8_DTS;

#define RDD_BYTES_8_BITS_READ_G(r, g, idx, i)       GROUP_MREAD_I_32(g, idx*sizeof(RDD_BYTES_8_DTS), i, r)
#define RDD_BYTES_8_BITS_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_32(g, idx*sizeof(RDD_BYTES_8_DTS), i, v)
#define RDD_BYTES_8_BITS_READ(r, p, i)              MREAD_I_32((uint8_t *)p, i, r)
#define RDD_BYTES_8_BITS_WRITE(v, p, i)             MWRITE_I_32((uint8_t *)p, i, v)
typedef struct
{
	RDD_BYTES_8_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_FLOW_CONTROL_PACKET_HEDAER_DTS;

extern uint32_t RDD_G9991_FLOW_CONTROL_PACKET_HEDAER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_FLOW_CONTROL_PACKET_HEDAER_PTR(core_id)	( RDD_G9991_FLOW_CONTROL_PACKET_HEDAER_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_FLOW_CONTROL_PACKET_HEDAER_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	pd_info           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = pd_info, size = 32 bits
	uint32_t	key_index         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fragment_type     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	options           	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0         	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ctrl_key_index    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ctrl_fragment_type	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sfc               	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1         	:19	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_sof     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_eof     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_const   	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_sid_1_0 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_sid_9_2 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_length_time 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timestamp         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	serial_num        	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ploam             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn_num            	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_1      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cong_state        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_cong      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lan               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_port      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = ingress_port, size = 8 bits
	uint32_t	flow              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_port       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	bn1_last_or_abs1  	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = bn1_last_or_abs1, size = 18 bits
	uint32_t	bn1_last          	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs1              	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	agg_pd            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_0      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error_type        	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sop               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn0_first         	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	pd_info           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = pd_info, size = 32 bits
	uint32_t	key_index         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fragment_type     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	options           	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0         	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ctrl_key_index    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ctrl_fragment_type	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sfc               	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1         	:19	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_sof     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_eof     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_const   	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_sid_1_0 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_tci_sid_9_2 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_length_time 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timestamp         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	packet_length     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn_num            	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ploam             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	serial_num        	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn1_last_or_abs1  	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = bn1_last_or_abs1, size = 18 bits
	uint32_t	bn1_last          	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs1              	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	ingress_port      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = ingress_port, size = 8 bits
	uint32_t	flow              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_port       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	lan               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ingress_cong      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cong_state        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_1      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn0_first         	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sop               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error_type        	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_0      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	agg_pd            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PROCESSING_RX_DESCRIPTOR_DTS;

#define RDD_PROCESSING_RX_DESCRIPTOR_PD_INFO_READ_G(r, g, idx)                     GROUP_MREAD_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), r)
#define RDD_PROCESSING_RX_DESCRIPTOR_PD_INFO_WRITE_G(v, g, idx)                    GROUP_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), v)
#define RDD_PROCESSING_RX_DESCRIPTOR_PD_INFO_READ(r, p)                            MREAD_32((uint8_t *)p, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_PD_INFO_WRITE(v, p)                           MWRITE_32((uint8_t *)p, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_KEY_INDEX_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 6, 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_KEY_INDEX_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 6, 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_KEY_INDEX_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p, 6, 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_KEY_INDEX_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p, 6, 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_FRAGMENT_TYPE_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 5, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_FRAGMENT_TYPE_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 5, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_FRAGMENT_TYPE_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_FRAGMENT_TYPE_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_OPTIONS_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 11, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_OPTIONS_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 11, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_OPTIONS_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p, 11, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_OPTIONS_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p, 11, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_CTRL_KEY_INDEX_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 6, 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_CTRL_KEY_INDEX_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 6, 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_CTRL_KEY_INDEX_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 6, 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_CTRL_KEY_INDEX_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 6, 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_CTRL_FRAGMENT_TYPE_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 5, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_CTRL_FRAGMENT_TYPE_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 5, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_CTRL_FRAGMENT_TYPE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_CTRL_FRAGMENT_TYPE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_SFC_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 3, 10, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_SFC_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 3, 10, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_SFC_READ(r, p)                                FIELD_MREAD_16((uint8_t *)p, 3, 10, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_SFC_WRITE(v, p)                               FIELD_MWRITE_16((uint8_t *)p, 3, 10, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SOF_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SOF_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SOF_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SOF_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_EOF_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 6, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_EOF_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 6, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_EOF_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_EOF_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_CONST_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 2, 4, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_CONST_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 2, 4, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_CONST_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 2, 4, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_CONST_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 2, 4, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SID_1_0_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 0, 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SID_1_0_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), 0, 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SID_1_0_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p, 0, 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SID_1_0_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p, 0, 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SID_9_2_READ_G(r, g, idx)           GROUP_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SID_9_2_WRITE_G(v, g, idx)          GROUP_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SID_9_2_READ(r, p)                  MREAD_8((uint8_t *)p + 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_TCI_SID_9_2_WRITE(v, p)                 MWRITE_8((uint8_t *)p + 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_LENGTH_TIME_READ_G(r, g, idx)           GROUP_MREAD_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_LENGTH_TIME_WRITE_G(v, g, idx)          GROUP_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_LENGTH_TIME_READ(r, p)                  MREAD_16((uint8_t *)p + 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_G9991_LENGTH_TIME_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_TIMESTAMP_READ_G(r, g, idx)                   GROUP_MREAD_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), r)
#define RDD_PROCESSING_RX_DESCRIPTOR_TIMESTAMP_WRITE_G(v, g, idx)                  GROUP_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS), v)
#define RDD_PROCESSING_RX_DESCRIPTOR_TIMESTAMP_READ(r, p)                          MREAD_32((uint8_t *)p, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_TIMESTAMP_WRITE(v, p)                         MWRITE_32((uint8_t *)p, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_SERIAL_NUM_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 4, 6, 10, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_SERIAL_NUM_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 4, 6, 10, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_SERIAL_NUM_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p + 4, 6, 10, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_SERIAL_NUM_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p + 4, 6, 10, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_PLOAM_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 5, 5, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_PLOAM_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 5, 5, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_PLOAM_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 5, 5, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_PLOAM_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 5, 5, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN_NUM_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 4, 14, 7, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN_NUM_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 4, 14, 7, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN_NUM_READ(r, p)                             FIELD_MREAD_32((uint8_t *)p + 4, 14, 7, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN_NUM_WRITE(v, p)                            FIELD_MWRITE_32((uint8_t *)p + 4, 14, 7, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_PACKET_LENGTH_READ_G(r, g, idx)               GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 6, 0, 14, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_PACKET_LENGTH_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 6, 0, 14, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_ERROR_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 7, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_ERROR_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 7, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_ERROR_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_ERROR_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_TARGET_MEM_1_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 6, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_TARGET_MEM_1_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 6, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_TARGET_MEM_1_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_TARGET_MEM_1_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_CONG_STATE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 4, 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_CONG_STATE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 4, 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_CONG_STATE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 8, 4, 2, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_CONG_STATE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 8, 4, 2, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_INGRESS_CONG_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 3, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_INGRESS_CONG_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 3, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_INGRESS_CONG_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 8, 3, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_INGRESS_CONG_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 8, 3, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_LAN_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 2, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_LAN_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 2, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_LAN_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 8, 2, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_LAN_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 8, 2, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_INGRESS_PORT_READ_G(r, g, idx)                GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 2, 8, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_INGRESS_PORT_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 2, 8, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_INGRESS_PORT_READ(r, p)                       FIELD_MREAD_16((uint8_t *)p + 8, 2, 8, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_INGRESS_PORT_WRITE(v, p)                      FIELD_MWRITE_16((uint8_t *)p + 8, 2, 8, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_FLOW_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 2, 8, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_FLOW_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 2, 8, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_FLOW_READ(r, p)                               FIELD_MREAD_16((uint8_t *)p + 8, 2, 8, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_FLOW_WRITE(v, p)                              FIELD_MWRITE_16((uint8_t *)p + 8, 2, 8, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_SOURCE_PORT_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 2, 8, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_SOURCE_PORT_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 2, 8, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_SOURCE_PORT_READ(r, p)                        FIELD_MREAD_16((uint8_t *)p + 8, 2, 8, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_SOURCE_PORT_WRITE(v, p)                       FIELD_MWRITE_16((uint8_t *)p + 8, 2, 8, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN1_LAST_OR_ABS1_READ_G(r, g, idx)            GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 0, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN1_LAST_OR_ABS1_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 0, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN1_LAST_OR_ABS1_READ(r, p)                   FIELD_MREAD_32((uint8_t *)p + 8, 0, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN1_LAST_OR_ABS1_WRITE(v, p)                  FIELD_MWRITE_32((uint8_t *)p + 8, 0, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN1_LAST_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 0, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN1_LAST_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 0, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN1_LAST_READ(r, p)                           FIELD_MREAD_32((uint8_t *)p + 8, 0, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN1_LAST_WRITE(v, p)                          FIELD_MWRITE_32((uint8_t *)p + 8, 0, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_ABS1_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 0, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_ABS1_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 8, 0, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_ABS1_READ(r, p)                               FIELD_MREAD_32((uint8_t *)p + 8, 0, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_ABS1_WRITE(v, p)                              FIELD_MWRITE_32((uint8_t *)p + 8, 0, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_AGG_PD_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 7, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_AGG_PD_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 7, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_AGG_PD_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_AGG_PD_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_TARGET_MEM_0_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 6, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_TARGET_MEM_0_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 6, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_TARGET_MEM_0_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 12, 6, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_TARGET_MEM_0_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 12, 6, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_ABS_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 5, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_ABS_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 5, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_ABS_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 12, 5, 1, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_ABS_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 12, 5, 1, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_ERROR_TYPE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 1, 4, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_ERROR_TYPE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 1, 4, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_ERROR_TYPE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 12, 1, 4, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_ERROR_TYPE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 12, 1, 4, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_SOP_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 2, 7, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_SOP_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 2, 7, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_SOP_READ(r, p)                                FIELD_MREAD_16((uint8_t *)p + 12, 2, 7, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_SOP_WRITE(v, p)                               FIELD_MWRITE_16((uint8_t *)p + 12, 2, 7, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN0_FIRST_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 0, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN0_FIRST_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_PROCESSING_RX_DESCRIPTOR_DTS) + 12, 0, 18, v)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN0_FIRST_READ(r, p)                          FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_PROCESSING_RX_DESCRIPTOR_BN0_FIRST_WRITE(v, p)                         FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
typedef struct
{
	RDD_PROCESSING_RX_DESCRIPTOR_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_FLOW_CONTROL_PD_DTS;

extern uint32_t RDD_G9991_FLOW_CONTROL_PD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_FLOW_CONTROL_PD_PTR(core_id)	( RDD_G9991_FLOW_CONTROL_PD_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_FLOW_CONTROL_PD_ADDRESS_ARR[core_id] ))


#define RDD_BBH_TX_QUEUE_ID_TABLE_SIZE     4
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_BBH_TX_QUEUE_ID_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_QUEUE_ID_TABLE_DTS;

extern uint32_t RDD_BBH_TX_QUEUE_ID_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_TX_QUEUE_ID_TABLE_PTR(core_id)	( RDD_BBH_TX_QUEUE_ID_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_TX_QUEUE_ID_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_RATE_LIMITER_VALID_TABLE_SIZE     4
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_RATE_LIMITER_VALID_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RATE_LIMITER_VALID_TABLE_DTS;

extern uint32_t RDD_RATE_LIMITER_VALID_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_RATE_LIMITER_VALID_TABLE_PTR(core_id)	( RDD_RATE_LIMITER_VALID_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_RATE_LIMITER_VALID_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_FLUSH_DISPATCHER_CREDIT_TABLE_SIZE     3
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_FLUSH_DISPATCHER_CREDIT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FLUSH_DISPATCHER_CREDIT_TABLE_DTS;

extern uint32_t RDD_FLUSH_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_FLUSH_DISPATCHER_CREDIT_TABLE_PTR(core_id)	( RDD_FLUSH_DISPATCHER_CREDIT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_FLUSH_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_2_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BUDGET_ALLOCATION_TIMER_VALUE_DTS;

extern uint32_t RDD_BUDGET_ALLOCATION_TIMER_VALUE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BUDGET_ALLOCATION_TIMER_VALUE_PTR(core_id)	( RDD_BUDGET_ALLOCATION_TIMER_VALUE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BUDGET_ALLOCATION_TIMER_VALUE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SCHEDULING_GLOBAL_FLUSH_CFG_DTS;

extern uint32_t RDD_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SCHEDULING_GLOBAL_FLUSH_CFG_PTR(core_id)	( RDD_SCHEDULING_GLOBAL_FLUSH_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SCHEDULING_GLOBAL_FLUSH_CFG_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SCHEDULING_FLUSH_GLOBAL_CFG_DTS;

extern uint32_t RDD_SCHEDULING_FLUSH_GLOBAL_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SCHEDULING_FLUSH_GLOBAL_CFG_PTR(core_id)	( RDD_SCHEDULING_FLUSH_GLOBAL_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SCHEDULING_FLUSH_GLOBAL_CFG_ADDRESS_ARR[core_id] ))


#define RDD_TX_MIRRORING_DISPATCHER_CREDIT_TABLE_SIZE     3
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_TX_MIRRORING_DISPATCHER_CREDIT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TX_MIRRORING_DISPATCHER_CREDIT_TABLE_DTS;

extern uint32_t RDD_TX_MIRRORING_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TX_MIRRORING_DISPATCHER_CREDIT_TABLE_PTR(core_id)	( RDD_TX_MIRRORING_DISPATCHER_CREDIT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TX_MIRRORING_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_4_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TASK_IDX_DTS;

extern uint32_t RDD_TASK_IDX_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TASK_IDX_PTR(core_id)	( RDD_TASK_IDX_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TASK_IDX_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_8_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MIRRORING_SCRATCH_DTS;

extern uint32_t RDD_MIRRORING_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_MIRRORING_SCRATCH_PTR(core_id)	( RDD_MIRRORING_SCRATCH_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_MIRRORING_SCRATCH_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	mirror_en 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	dst_vport 	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	dst_queue 	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	dst_queue 	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	dst_vport 	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	mirror_en 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MIRRORING_DESCRIPTOR_DTS;

#define RDD_MIRRORING_DESCRIPTOR_MIRROR_EN_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_MIRRORING_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_MIRRORING_DESCRIPTOR_MIRROR_EN_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_MIRRORING_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_MIRRORING_DESCRIPTOR_MIRROR_EN_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_MIRRORING_DESCRIPTOR_MIRROR_EN_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_MIRRORING_DESCRIPTOR_DST_VPORT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_MIRRORING_DESCRIPTOR_DTS), 1, 6, r)
#define RDD_MIRRORING_DESCRIPTOR_DST_VPORT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_MIRRORING_DESCRIPTOR_DTS), 1, 6, v)
#define RDD_MIRRORING_DESCRIPTOR_DST_VPORT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 1, 6, r)
#define RDD_MIRRORING_DESCRIPTOR_DST_VPORT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 1, 6, v)
#define RDD_MIRRORING_DESCRIPTOR_DST_QUEUE_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_MIRRORING_DESCRIPTOR_DTS), 0, 9, r)
#define RDD_MIRRORING_DESCRIPTOR_DST_QUEUE_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_MIRRORING_DESCRIPTOR_DTS), 0, 9, v)
#define RDD_MIRRORING_DESCRIPTOR_DST_QUEUE_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 0, 9, r)
#define RDD_MIRRORING_DESCRIPTOR_DST_QUEUE_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 0, 9, v)
typedef struct
{
	RDD_MIRRORING_DESCRIPTOR_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TX_MIRRORING_CONFIGURATION_DTS;

extern uint32_t RDD_TX_MIRRORING_CONFIGURATION_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TX_MIRRORING_CONFIGURATION_PTR(core_id)	( RDD_TX_MIRRORING_CONFIGURATION_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TX_MIRRORING_CONFIGURATION_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SRAM_DUMMY_STORE_DTS;

extern uint32_t RDD_SRAM_DUMMY_STORE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SRAM_DUMMY_STORE_PTR(core_id)	( RDD_SRAM_DUMMY_STORE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SRAM_DUMMY_STORE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FIRST_QUEUE_MAPPING_DTS;

extern uint32_t RDD_FIRST_QUEUE_MAPPING_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_FIRST_QUEUE_MAPPING_PTR(core_id)	( RDD_FIRST_QUEUE_MAPPING_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_FIRST_QUEUE_MAPPING_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	fpm_base_low        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_base_high       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_token_size_asr_8	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0           	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	fpm_base_low        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_base_high       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0           	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_token_size_asr_8	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FPM_GLOBAL_CFG_DTS;

#define RDD_FPM_GLOBAL_CFG_FPM_BASE_LOW_READ_G(r, g, idx)                  GROUP_MREAD_32(g, idx*sizeof(RDD_FPM_GLOBAL_CFG_DTS), r)
#define RDD_FPM_GLOBAL_CFG_FPM_BASE_LOW_WRITE_G(v, g, idx)                 GROUP_MWRITE_32(g, idx*sizeof(RDD_FPM_GLOBAL_CFG_DTS), v)
#define RDD_FPM_GLOBAL_CFG_FPM_BASE_LOW_READ(r, p)                         MREAD_32((uint8_t *)p, r)
#define RDD_FPM_GLOBAL_CFG_FPM_BASE_LOW_WRITE(v, p)                        MWRITE_32((uint8_t *)p, v)
#define RDD_FPM_GLOBAL_CFG_FPM_BASE_HIGH_READ_G(r, g, idx)                 GROUP_MREAD_32(g, idx*sizeof(RDD_FPM_GLOBAL_CFG_DTS) + 4, r)
#define RDD_FPM_GLOBAL_CFG_FPM_BASE_HIGH_WRITE_G(v, g, idx)                GROUP_MWRITE_32(g, idx*sizeof(RDD_FPM_GLOBAL_CFG_DTS) + 4, v)
#define RDD_FPM_GLOBAL_CFG_FPM_BASE_HIGH_READ(r, p)                        MREAD_32((uint8_t *)p + 4, r)
#define RDD_FPM_GLOBAL_CFG_FPM_BASE_HIGH_WRITE(v, p)                       MWRITE_32((uint8_t *)p + 4, v)
#define RDD_FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_FPM_GLOBAL_CFG_DTS) + 8, r)
#define RDD_FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_FPM_GLOBAL_CFG_DTS) + 8, v)
#define RDD_FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_READ(r, p)                 MREAD_8((uint8_t *)p + 8, r)
#define RDD_FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_WRITE(v, p)                MWRITE_8((uint8_t *)p + 8, v)
typedef struct
{
	RDD_FPM_GLOBAL_CFG_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FPM_GLOBAL_CFG_TABLE_DTS;

extern uint32_t RDD_FPM_GLOBAL_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_FPM_GLOBAL_CFG_PTR(core_id)	( RDD_FPM_GLOBAL_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_FPM_GLOBAL_CFG_ADDRESS_ARR[core_id] ))

/* CORE_1 */
#define RDD_G9991_US_SID_CONTEXT_ENTRY_RESERVED6_NUMBER	6

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	reserved0                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	plen                                                         	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fragment_count                                               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                    	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	state                                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn1_last                                                     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn0                                                          	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn1                                                          	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved6[RDD_G9991_US_SID_CONTEXT_ENTRY_RESERVED6_NUMBER];
#else
	uint32_t	state                                                        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                    	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fragment_count                                               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	plen                                                         	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn0                                                          	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn1_last                                                     	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved6[RDD_G9991_US_SID_CONTEXT_ENTRY_RESERVED6_NUMBER];
	uint32_t	bn1                                                          	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5                                                    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_US_SID_CONTEXT_ENTRY_DTS;

#define RDD_G9991_US_SID_CONTEXT_ENTRY_PLEN_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS), 0, 14, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_PLEN_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS), 0, 14, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_PLEN_READ(r, p)                           FIELD_MREAD_16((uint8_t *)p, 0, 14, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_PLEN_WRITE(v, p)                          FIELD_MWRITE_16((uint8_t *)p, 0, 14, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_FRAGMENT_COUNT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 2, 0, 7, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_FRAGMENT_COUNT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 2, 0, 7, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_FRAGMENT_COUNT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 0, 7, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_FRAGMENT_COUNT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 0, 7, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_STATE_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 3, 0, 1, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_STATE_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 3, 0, 1, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_STATE_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 3, 0, 1, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_STATE_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 3, 0, 1, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN1_LAST_READ_G(r, g, idx)                GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 4, 0, 14, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN1_LAST_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 4, 0, 14, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN1_LAST_READ(r, p)                       FIELD_MREAD_16((uint8_t *)p + 4, 0, 14, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN1_LAST_WRITE(v, p)                      FIELD_MWRITE_16((uint8_t *)p + 4, 0, 14, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN0_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 6, 0, 14, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN0_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 6, 0, 14, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN0_READ(r, p)                            FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN0_WRITE(v, p)                           FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN1_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 8, 0, 14, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN1_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_G9991_US_SID_CONTEXT_ENTRY_DTS) + 8, 0, 14, v)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN1_READ(r, p)                            FIELD_MREAD_16((uint8_t *)p + 8, 0, 14, r)
#define RDD_G9991_US_SID_CONTEXT_ENTRY_BN1_WRITE(v, p)                           FIELD_MWRITE_16((uint8_t *)p + 8, 0, 14, v)

#define RDD_G9991_US_SID_CONTEXT_TABLE_SIZE     40
typedef struct
{
	RDD_G9991_US_SID_CONTEXT_ENTRY_DTS	entry[ RDD_G9991_US_SID_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_US_SID_CONTEXT_TABLE_DTS;

extern uint32_t RDD_G9991_US_SID_CONTEXT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_US_SID_CONTEXT_TABLE_PTR(core_id)	( RDD_G9991_US_SID_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_US_SID_CONTEXT_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_G9991_PD_TABLE_SIZE     8
typedef struct
{
	RDD_PROCESSING_RX_DESCRIPTOR_DTS	entry[ RDD_G9991_PD_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_G9991_PD_TABLE_DTS;

extern uint32_t RDD_G9991_PD_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_G9991_PD_TABLE_PTR(core_id)	( RDD_G9991_PD_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_G9991_PD_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_REASSEMBLY_DISPATCHER_CREDIT_TABLE_SIZE     16
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_REASSEMBLY_DISPATCHER_CREDIT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REASSEMBLY_DISPATCHER_CREDIT_TABLE_DTS;

extern uint32_t RDD_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_REASSEMBLY_DISPATCHER_CREDIT_TABLE_PTR(core_id)	( RDD_REASSEMBLY_DISPATCHER_CREDIT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_REASSEMBLY_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[core_id] ))

/* CORE_2 */

#define RDD_CPU_TX_SCRATCHPAD_SIZE     128
typedef struct
{
	RDD_BYTES_8_DTS	entry[ RDD_CPU_TX_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_SCRATCHPAD_DTS;

extern uint32_t RDD_CPU_TX_SCRATCHPAD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_TX_SCRATCHPAD_PTR(core_id)	( RDD_CPU_TX_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_TX_SCRATCHPAD_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RX_SCRATCHPAD_SIZE     64
typedef struct
{
	RDD_BYTES_8_DTS	entry[ RDD_CPU_RX_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_SCRATCHPAD_DTS;

extern uint32_t RDD_CPU_RX_SCRATCHPAD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_SCRATCHPAD_PTR(core_id)	( RDD_CPU_RX_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_SCRATCHPAD_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	valid        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	qos_table_ptr	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint8_t	qos_table_ptr	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	valid        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TX_FLOW_ENTRY_DTS;

#define RDD_TX_FLOW_ENTRY_VALID_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TX_FLOW_ENTRY_DTS), 7, 1, r)
#define RDD_TX_FLOW_ENTRY_VALID_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TX_FLOW_ENTRY_DTS), 7, 1, v)
#define RDD_TX_FLOW_ENTRY_VALID_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_TX_FLOW_ENTRY_VALID_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_TX_FLOW_ENTRY_QOS_TABLE_PTR_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TX_FLOW_ENTRY_DTS), 0, 7, r)
#define RDD_TX_FLOW_ENTRY_QOS_TABLE_PTR_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TX_FLOW_ENTRY_DTS), 0, 7, v)
#define RDD_TX_FLOW_ENTRY_QOS_TABLE_PTR_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 0, 7, r)
#define RDD_TX_FLOW_ENTRY_QOS_TABLE_PTR_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 0, 7, v)

#define RDD_TX_FLOW_TABLE_SIZE     320
typedef struct
{
	RDD_TX_FLOW_ENTRY_DTS	entry[ RDD_TX_FLOW_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TX_FLOW_TABLE_DTS;

extern uint32_t RDD_TX_FLOW_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TX_FLOW_TABLE_PTR(core_id)	( RDD_TX_FLOW_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TX_FLOW_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_DS_CPU_REASON_TO_METER_TABLE_SIZE     64
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_DS_CPU_REASON_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_REASON_TO_METER_TABLE_DTS;

extern uint32_t RDD_DS_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_DS_CPU_REASON_TO_METER_TABLE_PTR(core_id)	( RDD_DS_CPU_REASON_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_DS_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	current_budget  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	budget_limit    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_budget	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	budget_limit    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_budget  	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	allocated_budget	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_METER_ENTRY_DTS;

#define RDD_CPU_RX_METER_ENTRY_CURRENT_BUDGET_READ_G(r, g, idx)            GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RX_METER_ENTRY_DTS), r)
#define RDD_CPU_RX_METER_ENTRY_CURRENT_BUDGET_WRITE_G(v, g, idx)           GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_METER_ENTRY_DTS), v)
#define RDD_CPU_RX_METER_ENTRY_CURRENT_BUDGET_READ(r, p)                   MREAD_16((uint8_t *)p, r)
#define RDD_CPU_RX_METER_ENTRY_CURRENT_BUDGET_WRITE(v, p)                  MWRITE_16((uint8_t *)p, v)
#define RDD_CPU_RX_METER_ENTRY_BUDGET_LIMIT_READ_G(r, g, idx)              GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RX_METER_ENTRY_DTS) + 2, r)
#define RDD_CPU_RX_METER_ENTRY_BUDGET_LIMIT_WRITE_G(v, g, idx)             GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_METER_ENTRY_DTS) + 2, v)
#define RDD_CPU_RX_METER_ENTRY_BUDGET_LIMIT_READ(r, p)                     MREAD_16((uint8_t *)p + 2, r)
#define RDD_CPU_RX_METER_ENTRY_BUDGET_LIMIT_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 2, v)
#define RDD_CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RX_METER_ENTRY_DTS) + 4, r)
#define RDD_CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_METER_ENTRY_DTS) + 4, v)
#define RDD_CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_READ(r, p)                 MREAD_16((uint8_t *)p + 4, r)
#define RDD_CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_WRITE(v, p)                MWRITE_16((uint8_t *)p + 4, v)

#define RDD_DS_CPU_RX_METER_TABLE_SIZE     16
typedef struct
{
	RDD_CPU_RX_METER_ENTRY_DTS	entry[ RDD_DS_CPU_RX_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_CPU_RX_METER_TABLE_DTS;

extern uint32_t RDD_DS_CPU_RX_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_DS_CPU_RX_METER_TABLE_PTR(core_id)	( RDD_DS_CPU_RX_METER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_DS_CPU_RX_METER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	virtual_port	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	flow_dest   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	exception   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reserved    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	cntr_id     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	cntr_id     	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reserved    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	exception   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	flow_dest   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	virtual_port	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RX_FLOW_ENTRY_DTS;

#define RDD_RX_FLOW_ENTRY_VIRTUAL_PORT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RX_FLOW_ENTRY_DTS), 3, 5, r)
#define RDD_RX_FLOW_ENTRY_VIRTUAL_PORT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RX_FLOW_ENTRY_DTS), 3, 5, v)
#define RDD_RX_FLOW_ENTRY_VIRTUAL_PORT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 3, 5, r)
#define RDD_RX_FLOW_ENTRY_VIRTUAL_PORT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 3, 5, v)
#define RDD_RX_FLOW_ENTRY_FLOW_DEST_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RX_FLOW_ENTRY_DTS), 2, 1, r)
#define RDD_RX_FLOW_ENTRY_FLOW_DEST_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RX_FLOW_ENTRY_DTS), 2, 1, v)
#define RDD_RX_FLOW_ENTRY_FLOW_DEST_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 2, 1, r)
#define RDD_RX_FLOW_ENTRY_FLOW_DEST_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 2, 1, v)
#define RDD_RX_FLOW_ENTRY_EXCEPTION_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RX_FLOW_ENTRY_DTS), 1, 1, r)
#define RDD_RX_FLOW_ENTRY_EXCEPTION_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RX_FLOW_ENTRY_DTS), 1, 1, v)
#define RDD_RX_FLOW_ENTRY_EXCEPTION_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_RX_FLOW_ENTRY_EXCEPTION_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_RX_FLOW_ENTRY_CNTR_ID_READ_G(r, g, idx)               GROUP_MREAD_8(g, idx*sizeof(RDD_RX_FLOW_ENTRY_DTS) + 1, r)
#define RDD_RX_FLOW_ENTRY_CNTR_ID_WRITE_G(v, g, idx)              GROUP_MWRITE_8(g, idx*sizeof(RDD_RX_FLOW_ENTRY_DTS) + 1, v)
#define RDD_RX_FLOW_ENTRY_CNTR_ID_READ(r, p)                      MREAD_8((uint8_t *)p + 1, r)
#define RDD_RX_FLOW_ENTRY_CNTR_ID_WRITE(v, p)                     MWRITE_8((uint8_t *)p + 1, v)

#define RDD_RX_FLOW_TABLE_SIZE     320
typedef struct
{
	RDD_RX_FLOW_ENTRY_DTS	entry[ RDD_RX_FLOW_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RX_FLOW_TABLE_DTS;

extern uint32_t RDD_RX_FLOW_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_RX_FLOW_TABLE_PTR(core_id)	( RDD_RX_FLOW_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_RX_FLOW_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_US_CPU_RX_METER_TABLE_SIZE     16
typedef struct
{
	RDD_CPU_RX_METER_ENTRY_DTS	entry[ RDD_US_CPU_RX_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_RX_METER_TABLE_DTS;

extern uint32_t RDD_US_CPU_RX_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_US_CPU_RX_METER_TABLE_PTR(core_id)	( RDD_US_CPU_RX_METER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_US_CPU_RX_METER_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_REPORTING_COUNTER_TABLE_SIZE     40
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_REPORTING_COUNTER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REPORTING_COUNTER_TABLE_DTS;

extern uint32_t RDD_REPORTING_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_REPORTING_COUNTER_TABLE_PTR(core_id)	( RDD_REPORTING_COUNTER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_REPORTING_COUNTER_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_US_CPU_REASON_TO_METER_TABLE_SIZE     64
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_US_CPU_REASON_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_US_CPU_REASON_TO_METER_TABLE_DTS;

extern uint32_t RDD_US_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_US_CPU_REASON_TO_METER_TABLE_PTR(core_id)	( RDD_US_CPU_REASON_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_US_CPU_REASON_TO_METER_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RECYCLE_SRAM_PD_FIFO_SIZE     16
typedef struct
{
	RDD_PROCESSING_TX_DESCRIPTOR_DTS	entry[ RDD_CPU_RECYCLE_SRAM_PD_FIFO_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_SRAM_PD_FIFO_DTS;

extern uint32_t RDD_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_SRAM_PD_FIFO_PTR(core_id)	( RDD_CPU_RECYCLE_SRAM_PD_FIFO_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_SRAM_PD_FIFO_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	counter   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	max_size  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	counter   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	max_size  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_DTS;

#define RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_COUNTER_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_DTS), r)
#define RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_COUNTER_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_DTS), v)
#define RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_COUNTER_READ(r, p)                  MREAD_32((uint8_t *)p, r)
#define RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_COUNTER_WRITE(v, p)                 MWRITE_32((uint8_t *)p, v)
#define RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_MAX_SIZE_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_DTS) + 4, r)
#define RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_MAX_SIZE_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_DTS) + 4, v)
#define RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_MAX_SIZE_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_MAX_SIZE_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)

#define RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_SIZE     18
typedef struct
{
	RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_DTS	entry[ RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_DTS;

extern uint32_t RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_PTR(core_id)	( RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	reserved   	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	pool_number	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint8_t	pool_number	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved   	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FPM_POOL_NUMBER_DTS;

#define RDD_FPM_POOL_NUMBER_POOL_NUMBER_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FPM_POOL_NUMBER_DTS), 0, 2, r)
#define RDD_FPM_POOL_NUMBER_POOL_NUMBER_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FPM_POOL_NUMBER_DTS), 0, 2, v)
#define RDD_FPM_POOL_NUMBER_POOL_NUMBER_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 0, 2, r)
#define RDD_FPM_POOL_NUMBER_POOL_NUMBER_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 0, 2, v)

#define RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_SIZE     16
typedef struct
{
	RDD_FPM_POOL_NUMBER_DTS	entry[ RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_DTS;

extern uint32_t RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_PTR(core_id)	( RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_TX_FPM_POOL_NUMBER_MAPPING_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_DIRECT_PROCESSING_PD_TABLE_SIZE     2
typedef struct
{
	RDD_PROCESSING_RX_DESCRIPTOR_DTS	entry[ RDD_DIRECT_PROCESSING_PD_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DIRECT_PROCESSING_PD_TABLE_DTS;

extern uint32_t RDD_DIRECT_PROCESSING_PD_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_DIRECT_PROCESSING_PD_TABLE_PTR(core_id)	( RDD_DIRECT_PROCESSING_PD_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_DIRECT_PROCESSING_PD_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_QUEUE_THRESHOLD_VECTOR_SIZE     9
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_QUEUE_THRESHOLD_VECTOR_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_QUEUE_THRESHOLD_VECTOR_DTS;

extern uint32_t RDD_QUEUE_THRESHOLD_VECTOR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_QUEUE_THRESHOLD_VECTOR_PTR(core_id)	( RDD_QUEUE_THRESHOLD_VECTOR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_QUEUE_THRESHOLD_VECTOR_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	mac_type      	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved      	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_interval	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	timer_interval	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved      	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_type      	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_DTS;

#define RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_MAC_TYPE_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_DTS), 5, 3, r)
#define RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_MAC_TYPE_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_DTS), 5, 3, v)
#define RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_MAC_TYPE_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 5, 3, r)
#define RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_MAC_TYPE_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 5, 3, v)
#define RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_TIMER_INTERVAL_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_DTS) + 2, r)
#define RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_TIMER_INTERVAL_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_DTS) + 2, v)
#define RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_TIMER_INTERVAL_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_TIMER_INTERVAL_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
typedef struct
{
	RDD_GHOST_REPORTING_GLOBAL_CFG_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GHOST_REPORTING_GLOBAL_CFG_DTS;

extern uint32_t RDD_GHOST_REPORTING_GLOBAL_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_GHOST_REPORTING_GLOBAL_CFG_PTR(core_id)	( RDD_GHOST_REPORTING_GLOBAL_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_GHOST_REPORTING_GLOBAL_CFG_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	low       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	high      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	low       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	high      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DDR_ADDRESS_DTS;

#define RDD_DDR_ADDRESS_LOW_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_DDR_ADDRESS_DTS), r)
#define RDD_DDR_ADDRESS_LOW_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_DDR_ADDRESS_DTS), v)
#define RDD_DDR_ADDRESS_LOW_READ(r, p)                  MREAD_32((uint8_t *)p, r)
#define RDD_DDR_ADDRESS_LOW_WRITE(v, p)                 MWRITE_32((uint8_t *)p, v)
#define RDD_DDR_ADDRESS_HIGH_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_DDR_ADDRESS_DTS) + 4, r)
#define RDD_DDR_ADDRESS_HIGH_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_DDR_ADDRESS_DTS) + 4, v)
#define RDD_DDR_ADDRESS_HIGH_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_DDR_ADDRESS_HIGH_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
typedef struct
{
	RDD_DDR_ADDRESS_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_DTS;

extern uint32_t RDD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_PTR(core_id)	( RDD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR[core_id] ))


#define RDD_FPM_REPLY_SIZE     2
typedef struct
{
	RDD_BYTES_8_DTS	entry[ RDD_FPM_REPLY_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FPM_REPLY_DTS;

extern uint32_t RDD_FPM_REPLY_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_FPM_REPLY_PTR(core_id)	( RDD_FPM_REPLY_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_FPM_REPLY_ADDRESS_ARR[core_id] ))

#define RDD_REPORTING_QUEUE_DESCRIPTOR_RESERVED_NUMBER	6

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	reported_bytes                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reported_overhead                                          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	counter_ptr                                                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved[RDD_REPORTING_QUEUE_DESCRIPTOR_RESERVED_NUMBER];
#else
	uint32_t	reported_bytes                                             	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reported_overhead                                          	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved[RDD_REPORTING_QUEUE_DESCRIPTOR_RESERVED_NUMBER];
	uint32_t	counter_ptr                                                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REPORTING_QUEUE_DESCRIPTOR_DTS;

#define RDD_REPORTING_QUEUE_DESCRIPTOR_REPORTED_BYTES_READ_G(r, g, idx)             GROUP_MREAD_32(g, idx*sizeof(RDD_REPORTING_QUEUE_DESCRIPTOR_DTS), r)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_REPORTED_BYTES_WRITE_G(v, g, idx)            GROUP_MWRITE_32(g, idx*sizeof(RDD_REPORTING_QUEUE_DESCRIPTOR_DTS), v)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_REPORTED_BYTES_READ(r, p)                    MREAD_32((uint8_t *)p, r)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_REPORTED_BYTES_WRITE(v, p)                   MWRITE_32((uint8_t *)p, v)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_REPORTED_OVERHEAD_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_REPORTING_QUEUE_DESCRIPTOR_DTS) + 4, r)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_REPORTED_OVERHEAD_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_REPORTING_QUEUE_DESCRIPTOR_DTS) + 4, v)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_REPORTED_OVERHEAD_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_REPORTED_OVERHEAD_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_COUNTER_PTR_READ_G(r, g, idx)                GROUP_MREAD_16(g, idx*sizeof(RDD_REPORTING_QUEUE_DESCRIPTOR_DTS) + 8, r)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_COUNTER_PTR_WRITE_G(v, g, idx)               GROUP_MWRITE_16(g, idx*sizeof(RDD_REPORTING_QUEUE_DESCRIPTOR_DTS) + 8, v)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_COUNTER_PTR_READ(r, p)                       MREAD_16((uint8_t *)p + 8, r)
#define RDD_REPORTING_QUEUE_DESCRIPTOR_COUNTER_PTR_WRITE(v, p)                      MWRITE_16((uint8_t *)p + 8, v)

#define RDD_REPORTING_QUEUE_DESCRIPTOR_TABLE_SIZE     160
typedef struct
{
	RDD_REPORTING_QUEUE_DESCRIPTOR_DTS	entry[ RDD_REPORTING_QUEUE_DESCRIPTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REPORTING_QUEUE_DESCRIPTOR_TABLE_DTS;

extern uint32_t RDD_REPORTING_QUEUE_DESCRIPTOR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_REPORTING_QUEUE_DESCRIPTOR_TABLE_PTR(core_id)	( RDD_REPORTING_QUEUE_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_REPORTING_QUEUE_DESCRIPTOR_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	accumulated_bytes   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	accumulated_overhead	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	accumulated_bytes   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	accumulated_overhead	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REPORTING_ACCUMULATED_DATA_DTS;

#define RDD_REPORTING_ACCUMULATED_DATA_ACCUMULATED_BYTES_READ_G(r, g, idx)             GROUP_MREAD_32(g, idx*sizeof(RDD_REPORTING_ACCUMULATED_DATA_DTS), r)
#define RDD_REPORTING_ACCUMULATED_DATA_ACCUMULATED_BYTES_WRITE_G(v, g, idx)            GROUP_MWRITE_32(g, idx*sizeof(RDD_REPORTING_ACCUMULATED_DATA_DTS), v)
#define RDD_REPORTING_ACCUMULATED_DATA_ACCUMULATED_BYTES_READ(r, p)                    MREAD_32((uint8_t *)p, r)
#define RDD_REPORTING_ACCUMULATED_DATA_ACCUMULATED_BYTES_WRITE(v, p)                   MWRITE_32((uint8_t *)p, v)
#define RDD_REPORTING_ACCUMULATED_DATA_ACCUMULATED_OVERHEAD_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_REPORTING_ACCUMULATED_DATA_DTS) + 4, r)
#define RDD_REPORTING_ACCUMULATED_DATA_ACCUMULATED_OVERHEAD_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_REPORTING_ACCUMULATED_DATA_DTS) + 4, v)
#define RDD_REPORTING_ACCUMULATED_DATA_ACCUMULATED_OVERHEAD_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_REPORTING_ACCUMULATED_DATA_ACCUMULATED_OVERHEAD_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)

#define RDD_REPORTING_QUEUE_ACCUMULATED_TABLE_SIZE     16
typedef struct
{
	RDD_REPORTING_ACCUMULATED_DATA_DTS	entry[ RDD_REPORTING_QUEUE_ACCUMULATED_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REPORTING_QUEUE_ACCUMULATED_TABLE_DTS;

extern uint32_t RDD_REPORTING_QUEUE_ACCUMULATED_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_REPORTING_QUEUE_ACCUMULATED_TABLE_PTR(core_id)	( RDD_REPORTING_QUEUE_ACCUMULATED_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_REPORTING_QUEUE_ACCUMULATED_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_SIZE     120
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_DTS;

extern uint32_t RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_PTR(core_id)	( RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_REASON_AND_VPORT_TO_METER_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_DDR_ADDRESS_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_INTERRUPT_ID_DDR_ADDR_DTS;

extern uint32_t RDD_CPU_RX_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_INTERRUPT_ID_DDR_ADDR_PTR(core_id)	( RDD_CPU_RX_INTERRUPT_ID_DDR_ADDR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_INTERRUPT_ID_DDR_ADDR_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RX_COPY_PD_FIFO_TABLE_SIZE     4
typedef struct
{
	RDD_PROCESSING_TX_DESCRIPTOR_DTS	entry[ RDD_CPU_RX_COPY_PD_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_COPY_PD_FIFO_TABLE_DTS;

extern uint32_t RDD_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_COPY_PD_FIFO_TABLE_PTR(core_id)	( RDD_CPU_RX_COPY_PD_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_COPY_PD_FIFO_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_SIZE     5
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_DTS;

extern uint32_t RDD_GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_PTR(core_id)	( RDD_GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_GHOST_REPORTING_QUEUE_STATUS_BIT_VECTOR_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_4_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_INTERRUPT_SCRATCH_DTS;

extern uint32_t RDD_CPU_RX_INTERRUPT_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_INTERRUPT_SCRATCH_PTR(core_id)	( RDD_CPU_RX_INTERRUPT_SCRATCH_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_INTERRUPT_SCRATCH_ADDRESS_ARR[core_id] ))


#define RDD_REPORT_BBH_TX_QUEUE_ID_TABLE_SIZE     2
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_REPORT_BBH_TX_QUEUE_ID_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_REPORT_BBH_TX_QUEUE_ID_TABLE_DTS;

extern uint32_t RDD_REPORT_BBH_TX_QUEUE_ID_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_REPORT_BBH_TX_QUEUE_ID_TABLE_PTR(core_id)	( RDD_REPORT_BBH_TX_QUEUE_ID_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_REPORT_BBH_TX_QUEUE_ID_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	timer_period	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_armed 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scratch     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	timer_period	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_armed 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scratch     	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS;

#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_TIMER_PERIOD_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS), r)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_TIMER_PERIOD_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS), v)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_TIMER_PERIOD_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_TIMER_PERIOD_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_TIMER_ARMED_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS) + 4, r)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_TIMER_ARMED_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS) + 4, v)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_TIMER_ARMED_READ(r, p)                  MREAD_32((uint8_t *)p + 4, r)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_TIMER_ARMED_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 4, v)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_SCRATCH_READ_G(r, g, idx)               GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS) + 8, r)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_SCRATCH_WRITE_G(v, g, idx)              GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS) + 8, v)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_SCRATCH_READ(r, p)                      MREAD_32((uint8_t *)p + 8, r)
#define RDD_CPU_INTERRUPT_COALESCING_ENTRY_SCRATCH_WRITE(v, p)                     MWRITE_32((uint8_t *)p + 8, v)
typedef struct
{
	RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_DTS;

extern uint32_t RDD_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_PTR(core_id)	( RDD_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_SIZE     8
typedef struct
{
	RDD_UPDATE_FIFO_ENTRY_DTS	entry[ RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_DTS;

extern uint32_t RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_PTR(core_id)	( RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_TX_EGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_SCRATCH_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SCRATCH_DTS;

extern uint32_t RDD_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SCRATCH_PTR(core_id)	( RDD_SCRATCH_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SCRATCH_ADDRESS_ARR[core_id] ))


#define RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_SIZE     8
typedef struct
{
	RDD_UPDATE_FIFO_ENTRY_DTS	entry[ RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_DTS;

extern uint32_t RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_PTR(core_id)	( RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_TX_INGRESS_UPDATE_FIFO_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_SIZE     4
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_DTS;

extern uint32_t RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_PTR(core_id)	( RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_PSRAM_GET_NEXT_SCRATCHPAD_ADDRESS_ARR[core_id] ))


#define RDD_XGPON_REPORT_TABLE_SIZE     4
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_XGPON_REPORT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_XGPON_REPORT_TABLE_DTS;

extern uint32_t RDD_XGPON_REPORT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_XGPON_REPORT_TABLE_PTR(core_id)	( RDD_XGPON_REPORT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_XGPON_REPORT_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_SIZE     8
typedef struct
{
	RDD_UPDATE_FIFO_ENTRY_DTS	entry[ RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_DTS;

extern uint32_t RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_PTR(core_id)	( RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_COPY_UPDATE_FIFO_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_SIZE     3
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_DTS;

extern uint32_t RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_PTR(core_id)	( RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_TX_EGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_SIZE     3
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_DTS;

extern uint32_t RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_PTR(core_id)	( RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_TX_INGRESS_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_2_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_FEED_RING_INTERRUPT_THRESHOLD_DTS;

extern uint32_t RDD_CPU_FEED_RING_INTERRUPT_THRESHOLD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_FEED_RING_INTERRUPT_THRESHOLD_PTR(core_id)	( RDD_CPU_FEED_RING_INTERRUPT_THRESHOLD_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_FEED_RING_INTERRUPT_THRESHOLD_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_2_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_FEED_RING_INTERRUPT_COUNTER_DTS;

extern uint32_t RDD_CPU_FEED_RING_INTERRUPT_COUNTER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_FEED_RING_INTERRUPT_COUNTER_PTR(core_id)	( RDD_CPU_FEED_RING_INTERRUPT_COUNTER_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_FEED_RING_INTERRUPT_COUNTER_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_SIZE     3
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_DTS;

extern uint32_t RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_PTR(core_id)	( RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_COPY_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	type      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint8_t	type      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAC_TYPE_ENTRY_DTS;

#define RDD_MAC_TYPE_ENTRY_TYPE_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_MAC_TYPE_ENTRY_DTS), r)
#define RDD_MAC_TYPE_ENTRY_TYPE_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_MAC_TYPE_ENTRY_DTS), v)
#define RDD_MAC_TYPE_ENTRY_TYPE_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_MAC_TYPE_ENTRY_TYPE_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
typedef struct
{
	RDD_MAC_TYPE_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_MAC_TYPE_DTS;

extern uint32_t RDD_MAC_TYPE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_MAC_TYPE_PTR(core_id)	( RDD_MAC_TYPE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_MAC_TYPE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_INGRESS_COUNTER_TABLE_DTS;

extern uint32_t RDD_BBH_TX_INGRESS_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_TX_INGRESS_COUNTER_TABLE_PTR(core_id)	( RDD_BBH_TX_INGRESS_COUNTER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_TX_INGRESS_COUNTER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	size_of_entry         	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	number_of_entries     	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	interrupt_id          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_counter          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	write_idx             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	base_addr_low         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	read_idx              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	low_priority_threshold	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	base_addr_high        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	interrupt_id          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	number_of_entries     	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	size_of_entry         	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	write_idx             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_counter          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	base_addr_low         	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	base_addr_high        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	low_priority_threshold	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	read_idx              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RING_DESCRIPTOR_DTS;

#define RDD_CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS), 3, 5, r)
#define RDD_CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS), 3, 5, v)
#define RDD_CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p, 3, 5, r)
#define RDD_CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p, 3, 5, v)
#define RDD_CPU_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_READ_G(r, g, idx)               GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS), 0, 11, r)
#define RDD_CPU_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS), 0, 11, v)
#define RDD_CPU_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p, 0, 11, r)
#define RDD_CPU_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p, 0, 11, v)
#define RDD_CPU_RING_DESCRIPTOR_INTERRUPT_ID_READ_G(r, g, idx)                    GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 2, r)
#define RDD_CPU_RING_DESCRIPTOR_INTERRUPT_ID_WRITE_G(v, g, idx)                   GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 2, v)
#define RDD_CPU_RING_DESCRIPTOR_INTERRUPT_ID_READ(r, p)                           MREAD_16((uint8_t *)p + 2, r)
#define RDD_CPU_RING_DESCRIPTOR_INTERRUPT_ID_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 2, v)
#define RDD_CPU_RING_DESCRIPTOR_DROP_COUNTER_READ_G(r, g, idx)                    GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 4, r)
#define RDD_CPU_RING_DESCRIPTOR_DROP_COUNTER_WRITE_G(v, g, idx)                   GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 4, v)
#define RDD_CPU_RING_DESCRIPTOR_DROP_COUNTER_READ(r, p)                           MREAD_16((uint8_t *)p + 4, r)
#define RDD_CPU_RING_DESCRIPTOR_DROP_COUNTER_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 4, v)
#define RDD_CPU_RING_DESCRIPTOR_WRITE_IDX_READ_G(r, g, idx)                       GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 6, r)
#define RDD_CPU_RING_DESCRIPTOR_WRITE_IDX_WRITE_G(v, g, idx)                      GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 6, v)
#define RDD_CPU_RING_DESCRIPTOR_WRITE_IDX_READ(r, p)                              MREAD_16((uint8_t *)p + 6, r)
#define RDD_CPU_RING_DESCRIPTOR_WRITE_IDX_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 6, v)
#define RDD_CPU_RING_DESCRIPTOR_BASE_ADDR_LOW_READ_G(r, g, idx)                   GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 8, r)
#define RDD_CPU_RING_DESCRIPTOR_BASE_ADDR_LOW_WRITE_G(v, g, idx)                  GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 8, v)
#define RDD_CPU_RING_DESCRIPTOR_BASE_ADDR_LOW_READ(r, p)                          MREAD_32((uint8_t *)p + 8, r)
#define RDD_CPU_RING_DESCRIPTOR_BASE_ADDR_LOW_WRITE(v, p)                         MWRITE_32((uint8_t *)p + 8, v)
#define RDD_CPU_RING_DESCRIPTOR_READ_IDX_READ_G(r, g, idx)                        GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 12, r)
#define RDD_CPU_RING_DESCRIPTOR_READ_IDX_WRITE_G(v, g, idx)                       GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 12, v)
#define RDD_CPU_RING_DESCRIPTOR_READ_IDX_READ(r, p)                               MREAD_16((uint8_t *)p + 12, r)
#define RDD_CPU_RING_DESCRIPTOR_READ_IDX_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 12, v)
#define RDD_CPU_RING_DESCRIPTOR_LOW_PRIORITY_THRESHOLD_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 14, r)
#define RDD_CPU_RING_DESCRIPTOR_LOW_PRIORITY_THRESHOLD_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 14, v)
#define RDD_CPU_RING_DESCRIPTOR_LOW_PRIORITY_THRESHOLD_READ(r, p)                 MREAD_8((uint8_t *)p + 14, r)
#define RDD_CPU_RING_DESCRIPTOR_LOW_PRIORITY_THRESHOLD_WRITE(v, p)                MWRITE_8((uint8_t *)p + 14, v)
#define RDD_CPU_RING_DESCRIPTOR_BASE_ADDR_HIGH_READ_G(r, g, idx)                  GROUP_MREAD_8(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 15, r)
#define RDD_CPU_RING_DESCRIPTOR_BASE_ADDR_HIGH_WRITE_G(v, g, idx)                 GROUP_MWRITE_8(g, idx*sizeof(RDD_CPU_RING_DESCRIPTOR_DTS) + 15, v)
#define RDD_CPU_RING_DESCRIPTOR_BASE_ADDR_HIGH_READ(r, p)                         MREAD_8((uint8_t *)p + 15, r)
#define RDD_CPU_RING_DESCRIPTOR_BASE_ADDR_HIGH_WRITE(v, p)                        MWRITE_8((uint8_t *)p + 15, v)
typedef struct
{
	RDD_CPU_RING_DESCRIPTOR_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_DTS;

extern uint32_t RDD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_PTR(core_id)	( RDD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_RING_DESCRIPTOR_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_SIZE     2
typedef struct
{
	RDD_PROCESSING_TX_DESCRIPTOR_DTS	entry[ RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_DTS;

extern uint32_t RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_PTR(core_id)	( RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_TX_EGRESS_PD_FIFO_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_SIZE     2
typedef struct
{
	RDD_DDR_ADDRESS_DTS	entry[ RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_DTS;

extern uint32_t RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_PTR(core_id)	( RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_RING_INDEX_DDR_ADDR_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_CPU_INTERRUPT_COALESCING_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_INTERRUPT_COALESCING_TABLE_DTS;

extern uint32_t RDD_CPU_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_INTERRUPT_COALESCING_TABLE_PTR(core_id)	( RDD_CPU_INTERRUPT_COALESCING_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_INTERRUPT_COALESCING_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_SIZE     2
typedef struct
{
	RDD_PROCESSING_TX_DESCRIPTOR_DTS	entry[ RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_DTS;

extern uint32_t RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_PTR(core_id)	( RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_TX_INGRESS_PD_FIFO_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_REASON_TO_TC_SIZE     64
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_CPU_REASON_TO_TC_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_REASON_TO_TC_DTS;

extern uint32_t RDD_CPU_REASON_TO_TC_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_REASON_TO_TC_PTR(core_id)	( RDD_CPU_REASON_TO_TC_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_REASON_TO_TC_ADDRESS_ARR[core_id] ))


#define RDD_TC_TO_CPU_RXQ_SIZE     64
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_TC_TO_CPU_RXQ_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TC_TO_CPU_RXQ_DTS;

extern uint32_t RDD_TC_TO_CPU_RXQ_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TC_TO_CPU_RXQ_PTR(core_id)	( RDD_TC_TO_CPU_RXQ_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TC_TO_CPU_RXQ_ADDRESS_ARR[core_id] ))


#define RDD_EXC_TC_TO_CPU_RXQ_SIZE     64
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_EXC_TC_TO_CPU_RXQ_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EXC_TC_TO_CPU_RXQ_DTS;

extern uint32_t RDD_EXC_TC_TO_CPU_RXQ_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_EXC_TC_TO_CPU_RXQ_PTR(core_id)	( RDD_EXC_TC_TO_CPU_RXQ_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_EXC_TC_TO_CPU_RXQ_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_CPU_RING_DESCRIPTOR_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_FEED_RING_DESCRIPTOR_TABLE_DTS;

extern uint32_t RDD_CPU_FEED_RING_DESCRIPTOR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_FEED_RING_DESCRIPTOR_TABLE_PTR(core_id)	( RDD_CPU_FEED_RING_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_FEED_RING_DESCRIPTOR_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RX_LOCAL_SCRATCH_SIZE     2
typedef struct
{
	RDD_BYTES_8_DTS	entry[ RDD_CPU_RX_LOCAL_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_LOCAL_SCRATCH_DTS;

extern uint32_t RDD_CPU_RX_LOCAL_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_LOCAL_SCRATCH_PTR(core_id)	( RDD_CPU_RX_LOCAL_SCRATCH_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_LOCAL_SCRATCH_ADDRESS_ARR[core_id] ))


#define RDD_VPORT_TO_CPU_OBJ_SIZE     40
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_VPORT_TO_CPU_OBJ_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_VPORT_TO_CPU_OBJ_DTS;

extern uint32_t RDD_VPORT_TO_CPU_OBJ_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_VPORT_TO_CPU_OBJ_PTR(core_id)	( RDD_VPORT_TO_CPU_OBJ_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_VPORT_TO_CPU_OBJ_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_CPU_RING_INTERRUPT_COUNTER_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_DTS;

extern uint32_t RDD_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_PTR(core_id)	( RDD_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_RING_INTERRUPT_COUNTER_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_XGPON_REPORT_ZERO_SENT_TABLE_SIZE     10
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_XGPON_REPORT_ZERO_SENT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_XGPON_REPORT_ZERO_SENT_TABLE_DTS;

extern uint32_t RDD_XGPON_REPORT_ZERO_SENT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_XGPON_REPORT_ZERO_SENT_TABLE_PTR(core_id)	( RDD_XGPON_REPORT_ZERO_SENT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_XGPON_REPORT_ZERO_SENT_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_8_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_COPY_LOCAL_SCRATCH_DTS;

extern uint32_t RDD_CPU_RX_COPY_LOCAL_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RX_COPY_LOCAL_SCRATCH_PTR(core_id)	( RDD_CPU_RX_COPY_LOCAL_SCRATCH_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RX_COPY_LOCAL_SCRATCH_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_EGRESS_REPORT_COUNTER_TABLE_DTS;

extern uint32_t RDD_BBH_TX_EGRESS_REPORT_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_TX_EGRESS_REPORT_COUNTER_TABLE_PTR(core_id)	( RDD_BBH_TX_EGRESS_REPORT_COUNTER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_TX_EGRESS_REPORT_COUNTER_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_DTS;

extern uint32_t RDD_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_PTR(core_id)	( RDD_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_DIRECT_PROCESSING_EPON_CONTROL_SCRATCH_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_SIZE     2
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_DTS;

extern uint32_t RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_PTR(core_id)	( RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_INTERRUPT_SCRATCH_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_2_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_SHADOW_RD_IDX_DTS;

extern uint32_t RDD_CPU_RECYCLE_SHADOW_RD_IDX_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_SHADOW_RD_IDX_PTR(core_id)	( RDD_CPU_RECYCLE_SHADOW_RD_IDX_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_SHADOW_RD_IDX_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_2_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RECYCLE_SHADOW_WR_IDX_DTS;

extern uint32_t RDD_CPU_RECYCLE_SHADOW_WR_IDX_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RECYCLE_SHADOW_WR_IDX_PTR(core_id)	( RDD_CPU_RECYCLE_SHADOW_WR_IDX_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RECYCLE_SHADOW_WR_IDX_ADDRESS_ARR[core_id] ))


#define RDD_CPU_RING_DESCRIPTORS_TABLE_SIZE     16
typedef struct
{
	RDD_CPU_RING_DESCRIPTOR_DTS	entry[ RDD_CPU_RING_DESCRIPTORS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RING_DESCRIPTORS_TABLE_DTS;

extern uint32_t RDD_CPU_RING_DESCRIPTORS_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CPU_RING_DESCRIPTORS_TABLE_PTR(core_id)	( RDD_CPU_RING_DESCRIPTORS_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CPU_RING_DESCRIPTORS_TABLE_ADDRESS_ARR[core_id] ))

/* CORE_3 */

#define RDD_BBH_TX_EPON_INGRESS_COUNTER_TABLE_SIZE     40
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_BBH_TX_EPON_INGRESS_COUNTER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_EPON_INGRESS_COUNTER_TABLE_DTS;

extern uint32_t RDD_BBH_TX_EPON_INGRESS_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_TX_EPON_INGRESS_COUNTER_TABLE_PTR(core_id)	( RDD_BBH_TX_EPON_INGRESS_COUNTER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_TX_EPON_INGRESS_COUNTER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	bytes_in_bbh	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	queue       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bytes_in_bbh	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_QUEUE_ID_ENTRY_DTS;

#define RDD_BBH_TX_QUEUE_ID_ENTRY_BYTES_IN_BBH_READ_G(r, g, idx)          GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_BBH_TX_QUEUE_ID_ENTRY_DTS), 8, 24, r)
#define RDD_BBH_TX_QUEUE_ID_ENTRY_BYTES_IN_BBH_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_BBH_TX_QUEUE_ID_ENTRY_DTS), 8, 24, v)
#define RDD_BBH_TX_QUEUE_ID_ENTRY_BYTES_IN_BBH_READ(r, p)                 FIELD_MREAD_32((uint8_t *)p, 8, 24, r)
#define RDD_BBH_TX_QUEUE_ID_ENTRY_BYTES_IN_BBH_WRITE(v, p)                FIELD_MWRITE_32((uint8_t *)p, 8, 24, v)
#define RDD_BBH_TX_QUEUE_ID_ENTRY_QUEUE_READ_G(r, g, idx)                 GROUP_MREAD_8(g, idx*sizeof(RDD_BBH_TX_QUEUE_ID_ENTRY_DTS) + 3, r)
#define RDD_BBH_TX_QUEUE_ID_ENTRY_QUEUE_WRITE_G(v, g, idx)                GROUP_MWRITE_8(g, idx*sizeof(RDD_BBH_TX_QUEUE_ID_ENTRY_DTS) + 3, v)
#define RDD_BBH_TX_QUEUE_ID_ENTRY_QUEUE_READ(r, p)                        MREAD_8((uint8_t *)p + 3, r)
#define RDD_BBH_TX_QUEUE_ID_ENTRY_QUEUE_WRITE(v, p)                       MWRITE_8((uint8_t *)p + 3, v)

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	bbh_queue_en_vec	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_budget  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	alloc_mantissa  	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	alloc_exponent  	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	limit_mantissa  	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	limit_exponent  	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	bbh_queue_en_vec	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_budget  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	limit_exponent  	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	limit_mantissa  	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	alloc_exponent  	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	alloc_mantissa  	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS;

#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_BBH_QUEUE_EN_VEC_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS), r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_BBH_QUEUE_EN_VEC_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS), v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_BBH_QUEUE_EN_VEC_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_BBH_QUEUE_EN_VEC_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_READ_G(r, g, idx)            GROUP_MREAD_32(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 4, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_WRITE_G(v, g, idx)           GROUP_MWRITE_32(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 4, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_READ(r, p)                   MREAD_32((uint8_t *)p + 4, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_CURRENT_BUDGET_WRITE(v, p)                  MWRITE_32((uint8_t *)p + 4, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_READ_G(r, g, idx)            GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 8, 2, 14, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 8, 2, 14, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_READ(r, p)                   FIELD_MREAD_16((uint8_t *)p + 8, 2, 14, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_MANTISSA_WRITE(v, p)                  FIELD_MWRITE_16((uint8_t *)p + 8, 2, 14, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 9, 0, 2, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 9, 0, 2, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 9, 0, 2, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_ALLOC_EXPONENT_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 9, 0, 2, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_READ_G(r, g, idx)            GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 10, 2, 14, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 10, 2, 14, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_READ(r, p)                   FIELD_MREAD_16((uint8_t *)p + 10, 2, 14, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_MANTISSA_WRITE(v, p)                  FIELD_MWRITE_16((uint8_t *)p + 10, 2, 14, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 11, 0, 2, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS) + 11, 0, 2, v)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 11, 0, 2, r)
#define RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_LIMIT_EXPONENT_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 11, 0, 2, v)
typedef struct
{
	RDD_OVERALL_RATE_LIMITER_DESCRIPTOR_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_OVERALL_RATE_LIMITER_TABLE_DTS;

extern uint32_t RDD_OVERALL_RATE_LIMITER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_OVERALL_RATE_LIMITER_TABLE_PTR(core_id)	( RDD_OVERALL_RATE_LIMITER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_OVERALL_RATE_LIMITER_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_BBH_TX_EPON_EGRESS_COUNTER_TABLE_SIZE     5
typedef struct
{
	RDD_BBH_TX_EGRESS_COUNTER_ENTRY_DTS	entry[ RDD_BBH_TX_EPON_EGRESS_COUNTER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_EPON_EGRESS_COUNTER_TABLE_DTS;

extern uint32_t RDD_BBH_TX_EPON_EGRESS_COUNTER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_TX_EPON_EGRESS_COUNTER_TABLE_PTR(core_id)	( RDD_BBH_TX_EPON_EGRESS_COUNTER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_TX_EPON_EGRESS_COUNTER_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_BBH_TX_EPON_QUEUE_ID_TABLE_SIZE     2
typedef struct
{
	RDD_BBH_TX_QUEUE_ID_ENTRY_DTS	entry[ RDD_BBH_TX_EPON_QUEUE_ID_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_EPON_QUEUE_ID_TABLE_DTS;

extern uint32_t RDD_BBH_TX_EPON_QUEUE_ID_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_TX_EPON_QUEUE_ID_TABLE_PTR(core_id)	( RDD_BBH_TX_EPON_QUEUE_ID_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_TX_EPON_QUEUE_ID_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_2_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BB_DESTINATION_TABLE_DTS;

extern uint32_t RDD_BB_DESTINATION_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BB_DESTINATION_TABLE_PTR(core_id)	( RDD_BB_DESTINATION_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BB_DESTINATION_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_DISPATCHER_CREDIT_TABLE_SIZE     3
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_DISPATCHER_CREDIT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DISPATCHER_CREDIT_TABLE_DTS;

extern uint32_t RDD_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_DISPATCHER_CREDIT_TABLE_PTR(core_id)	( RDD_DISPATCHER_CREDIT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_DISPATCHER_CREDIT_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BBH_TX_FIFO_SIZE_DTS;

extern uint32_t RDD_BBH_TX_FIFO_SIZE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BBH_TX_FIFO_SIZE_PTR(core_id)	( RDD_BBH_TX_FIFO_SIZE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BBH_TX_FIFO_SIZE_ADDRESS_ARR[core_id] ))


#define RDD_EPON_UPDATE_FIFO_TABLE_SIZE     8
typedef struct
{
	RDD_UPDATE_FIFO_ENTRY_DTS	entry[ RDD_EPON_UPDATE_FIFO_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_EPON_UPDATE_FIFO_TABLE_DTS;

extern uint32_t RDD_EPON_UPDATE_FIFO_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_EPON_UPDATE_FIFO_TABLE_PTR(core_id)	( RDD_EPON_UPDATE_FIFO_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_EPON_UPDATE_FIFO_TABLE_ADDRESS_ARR[core_id] ))

/* CORE_4 */

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	routine          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_buffer_offset	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	dst_buffer_offset	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	routine          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DTS;

#define RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_ROUTINE_READ_G(r, g, idx)                    GROUP_MREAD_16(g, idx*sizeof(RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DTS), r)
#define RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_ROUTINE_WRITE_G(v, g, idx)                   GROUP_MWRITE_16(g, idx*sizeof(RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DTS), v)
#define RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_ROUTINE_READ(r, p)                           MREAD_16((uint8_t *)p, r)
#define RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_ROUTINE_WRITE(v, p)                          MWRITE_16((uint8_t *)p, v)
#define RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DST_BUFFER_OFFSET_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DTS) + 2, r)
#define RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DST_BUFFER_OFFSET_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DTS) + 2, v)
#define RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DST_BUFFER_OFFSET_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DST_BUFFER_OFFSET_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)

#define RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_SIZE     30
typedef struct
{
	RDD_LAYER2_HEADER_COPY_MAPPING_ENTRY_DTS	entry[ RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_DTS;

extern uint32_t RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_PTR(core_id)	( RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_LAYER2_HEADER_COPY_MAPPING_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	fpm_base_token_size	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hn_size1           	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hn_size0           	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2          	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_sop_offset0    	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3          	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_sop_offset1    	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	hn_size0           	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hn_size1           	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_base_token_size	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_sop_offset1    	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3          	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ddr_sop_offset0    	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2          	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_HW_IPTV_CONFIGURATION_DTS;

#define RDD_HW_IPTV_CONFIGURATION_FPM_BASE_TOKEN_SIZE_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS), r)
#define RDD_HW_IPTV_CONFIGURATION_FPM_BASE_TOKEN_SIZE_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS), v)
#define RDD_HW_IPTV_CONFIGURATION_FPM_BASE_TOKEN_SIZE_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_HW_IPTV_CONFIGURATION_FPM_BASE_TOKEN_SIZE_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#define RDD_HW_IPTV_CONFIGURATION_HN_SIZE1_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS) + 2, 0, 7, r)
#define RDD_HW_IPTV_CONFIGURATION_HN_SIZE1_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS) + 2, 0, 7, v)
#define RDD_HW_IPTV_CONFIGURATION_HN_SIZE1_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 2, 0, 7, r)
#define RDD_HW_IPTV_CONFIGURATION_HN_SIZE1_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 2, 0, 7, v)
#define RDD_HW_IPTV_CONFIGURATION_HN_SIZE0_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS) + 3, 0, 7, r)
#define RDD_HW_IPTV_CONFIGURATION_HN_SIZE0_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS) + 3, 0, 7, v)
#define RDD_HW_IPTV_CONFIGURATION_HN_SIZE0_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 3, 0, 7, r)
#define RDD_HW_IPTV_CONFIGURATION_HN_SIZE0_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 3, 0, 7, v)
#define RDD_HW_IPTV_CONFIGURATION_DDR_SOP_OFFSET0_READ_G(r, g, idx)              GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS) + 4, 0, 11, r)
#define RDD_HW_IPTV_CONFIGURATION_DDR_SOP_OFFSET0_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS) + 4, 0, 11, v)
#define RDD_HW_IPTV_CONFIGURATION_DDR_SOP_OFFSET0_READ(r, p)                     FIELD_MREAD_16((uint8_t *)p + 4, 0, 11, r)
#define RDD_HW_IPTV_CONFIGURATION_DDR_SOP_OFFSET0_WRITE(v, p)                    FIELD_MWRITE_16((uint8_t *)p + 4, 0, 11, v)
#define RDD_HW_IPTV_CONFIGURATION_DDR_SOP_OFFSET1_READ_G(r, g, idx)              GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS) + 6, 0, 11, r)
#define RDD_HW_IPTV_CONFIGURATION_DDR_SOP_OFFSET1_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_HW_IPTV_CONFIGURATION_DTS) + 6, 0, 11, v)
#define RDD_HW_IPTV_CONFIGURATION_DDR_SOP_OFFSET1_READ(r, p)                     FIELD_MREAD_16((uint8_t *)p + 6, 0, 11, r)
#define RDD_HW_IPTV_CONFIGURATION_DDR_SOP_OFFSET1_WRITE(v, p)                    FIELD_MWRITE_16((uint8_t *)p + 6, 0, 11, v)
typedef struct
{
	RDD_HW_IPTV_CONFIGURATION_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_CONFIGURATION_TABLE_DTS;

extern uint32_t RDD_IPTV_CONFIGURATION_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_IPTV_CONFIGURATION_TABLE_PTR(core_id)	( RDD_IPTV_CONFIGURATION_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_IPTV_CONFIGURATION_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_DSCP_TO_PBITS_MAP_TABLE_SIZE     4

#define RDD_DSCP_TO_PBITS_MAP_TABLE_SIZE2    64
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_DSCP_TO_PBITS_MAP_TABLE_SIZE ][ RDD_DSCP_TO_PBITS_MAP_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DSCP_TO_PBITS_MAP_TABLE_DTS;

extern uint32_t RDD_DSCP_TO_PBITS_MAP_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_DSCP_TO_PBITS_MAP_TABLE_PTR(core_id)	( RDD_DSCP_TO_PBITS_MAP_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_DSCP_TO_PBITS_MAP_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_PROCESSING_CPU_RX_SCRATCHPAD_SIZE     8
typedef struct
{
	RDD_BYTES_4_DTS	entry[ RDD_PROCESSING_CPU_RX_SCRATCHPAD_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PROCESSING_CPU_RX_SCRATCHPAD_DTS;

extern uint32_t RDD_PROCESSING_CPU_RX_SCRATCHPAD_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_PROCESSING_CPU_RX_SCRATCHPAD_PTR(core_id)	( RDD_PROCESSING_CPU_RX_SCRATCHPAD_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_PROCESSING_CPU_RX_SCRATCHPAD_ADDRESS_ARR[core_id] ))


#define RDD_GLOBAL_DSCP_TO_PBITS_TABLE_SIZE2    64
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_GLOBAL_DSCP_TO_PBITS_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GLOBAL_DSCP_TO_PBITS_TABLE_DTS;

extern uint32_t RDD_GLOBAL_DSCP_TO_PBITS_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_GLOBAL_DSCP_TO_PBITS_TABLE_PTR(core_id)	( RDD_GLOBAL_DSCP_TO_PBITS_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_GLOBAL_DSCP_TO_PBITS_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	loopback_en                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	mirroring_en                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	sa_lookup_en                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	da_lookup_en                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	egress_isolation_en          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	ingress_isolation_en         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	bridge_and_vlan_lookup_method	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_bridge_and_vlan_ctx_lookup_method enumeration*/
	uint16_t	reserved                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reserved2                    	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	sa_lookup_miss_action        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_action enumeration*/
	uint16_t	da_lookup_miss_action        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_action enumeration*/
	uint16_t	ls_fc_cfg                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	ls_fc_cfg                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	da_lookup_miss_action        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_action enumeration*/
	uint16_t	sa_lookup_miss_action        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_action enumeration*/
	uint16_t	reserved2                    	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	reserved                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	bridge_and_vlan_lookup_method	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_bridge_and_vlan_ctx_lookup_method enumeration*/
	uint16_t	ingress_isolation_en         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	egress_isolation_en          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	da_lookup_en                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	sa_lookup_en                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	mirroring_en                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	loopback_en                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_VPORT_CFG_ENTRY_DTS;

#define RDD_VPORT_CFG_ENTRY_LOOPBACK_EN_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 7, 1, r)
#define RDD_VPORT_CFG_ENTRY_LOOPBACK_EN_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 7, 1, v)
#define RDD_VPORT_CFG_ENTRY_LOOPBACK_EN_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_VPORT_CFG_ENTRY_LOOPBACK_EN_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_VPORT_CFG_ENTRY_MIRRORING_EN_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 6, 1, r)
#define RDD_VPORT_CFG_ENTRY_MIRRORING_EN_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 6, 1, v)
#define RDD_VPORT_CFG_ENTRY_MIRRORING_EN_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_VPORT_CFG_ENTRY_MIRRORING_EN_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_VPORT_CFG_ENTRY_SA_LOOKUP_EN_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 5, 1, r)
#define RDD_VPORT_CFG_ENTRY_SA_LOOKUP_EN_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 5, 1, v)
#define RDD_VPORT_CFG_ENTRY_SA_LOOKUP_EN_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_VPORT_CFG_ENTRY_SA_LOOKUP_EN_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_VPORT_CFG_ENTRY_DA_LOOKUP_EN_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 4, 1, r)
#define RDD_VPORT_CFG_ENTRY_DA_LOOKUP_EN_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 4, 1, v)
#define RDD_VPORT_CFG_ENTRY_DA_LOOKUP_EN_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_VPORT_CFG_ENTRY_DA_LOOKUP_EN_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 3, 1, r)
#define RDD_VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 3, 1, v)
#define RDD_VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 3, 1, r)
#define RDD_VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 3, 1, v)
#define RDD_VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 2, 1, r)
#define RDD_VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 2, 1, v)
#define RDD_VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p, 2, 1, r)
#define RDD_VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p, 2, 1, v)
#define RDD_VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 1, 1, r) /*defined by rdd_bridge_and_vlan_ctx_lookup_method enumeration*/
#define RDD_VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS), 1, 1, v) /*defined by rdd_bridge_and_vlan_ctx_lookup_method enumeration*/
#define RDD_VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 1, 1, r) /*defined by rdd_bridge_and_vlan_ctx_lookup_method enumeration*/
#define RDD_VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 1, 1, v) /*defined by rdd_bridge_and_vlan_ctx_lookup_method enumeration*/
#define RDD_VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS) + 1, 3, 2, r) /*defined by rdd_action enumeration*/
#define RDD_VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS) + 1, 3, 2, v) /*defined by rdd_action enumeration*/
#define RDD_VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 1, 3, 2, r) /*defined by rdd_action enumeration*/
#define RDD_VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 1, 3, 2, v) /*defined by rdd_action enumeration*/
#define RDD_VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS) + 1, 1, 2, r) /*defined by rdd_action enumeration*/
#define RDD_VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS) + 1, 1, 2, v) /*defined by rdd_action enumeration*/
#define RDD_VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 1, 1, 2, r) /*defined by rdd_action enumeration*/
#define RDD_VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 1, 1, 2, v) /*defined by rdd_action enumeration*/
#define RDD_VPORT_CFG_ENTRY_LS_FC_CFG_READ_G(r, g, idx)                              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS) + 1, 0, 1, r)
#define RDD_VPORT_CFG_ENTRY_LS_FC_CFG_WRITE_G(v, g, idx)                             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VPORT_CFG_ENTRY_DTS) + 1, 0, 1, v)
#define RDD_VPORT_CFG_ENTRY_LS_FC_CFG_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 1, 0, 1, r)
#define RDD_VPORT_CFG_ENTRY_LS_FC_CFG_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 1, 0, 1, v)

#define RDD_VPORT_CFG_TABLE_SIZE     40
typedef struct
{
	RDD_VPORT_CFG_ENTRY_DTS	entry[ RDD_VPORT_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_VPORT_CFG_TABLE_DTS;

extern uint32_t RDD_VPORT_CFG_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_VPORT_CFG_TABLE_PTR(core_id)	( RDD_VPORT_CFG_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_VPORT_CFG_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_FPM_POOL_NUMBER_MAPPING_TABLE_SIZE     16
typedef struct
{
	RDD_FPM_POOL_NUMBER_DTS	entry[ RDD_FPM_POOL_NUMBER_MAPPING_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FPM_POOL_NUMBER_MAPPING_TABLE_DTS;

extern uint32_t RDD_FPM_POOL_NUMBER_MAPPING_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_FPM_POOL_NUMBER_MAPPING_TABLE_PTR(core_id)	( RDD_FPM_POOL_NUMBER_MAPPING_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_FPM_POOL_NUMBER_MAPPING_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_VPORT_TO_DSCP_TO_PBITS_TABLE_SIZE     32
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_VPORT_TO_DSCP_TO_PBITS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_VPORT_TO_DSCP_TO_PBITS_TABLE_DTS;

extern uint32_t RDD_VPORT_TO_DSCP_TO_PBITS_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_VPORT_TO_DSCP_TO_PBITS_TABLE_PTR(core_id)	( RDD_VPORT_TO_DSCP_TO_PBITS_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_VPORT_TO_DSCP_TO_PBITS_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	enable_vector	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	action_vector	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	enable_vector	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	action_vector	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_FILTER_CTRL_DTS;

#define RDD_INGRESS_FILTER_CTRL_ENABLE_VECTOR_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_INGRESS_FILTER_CTRL_DTS), r)
#define RDD_INGRESS_FILTER_CTRL_ENABLE_VECTOR_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_INGRESS_FILTER_CTRL_DTS), v)
#define RDD_INGRESS_FILTER_CTRL_ENABLE_VECTOR_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_INGRESS_FILTER_CTRL_ENABLE_VECTOR_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_INGRESS_FILTER_CTRL_ACTION_VECTOR_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_INGRESS_FILTER_CTRL_DTS) + 4, r)
#define RDD_INGRESS_FILTER_CTRL_ACTION_VECTOR_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_INGRESS_FILTER_CTRL_DTS) + 4, v)
#define RDD_INGRESS_FILTER_CTRL_ACTION_VECTOR_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_INGRESS_FILTER_CTRL_ACTION_VECTOR_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)

#define RDD_INGRESS_FILTER_PROFILE_TABLE_SIZE     16
typedef struct
{
	RDD_INGRESS_FILTER_CTRL_DTS	entry[ RDD_INGRESS_FILTER_PROFILE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_FILTER_PROFILE_TABLE_DTS;

extern uint32_t RDD_INGRESS_FILTER_PROFILE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_INGRESS_FILTER_PROFILE_TABLE_PTR(core_id)	( RDD_INGRESS_FILTER_PROFILE_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_INGRESS_FILTER_PROFILE_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	factor_bytes	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	dei_mode    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint8_t	reserved    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	dei_mode    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	factor_bytes	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_POLICER_PARAMS_ENTRY_DTS;

#define RDD_POLICER_PARAMS_ENTRY_FACTOR_BYTES_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_POLICER_PARAMS_ENTRY_DTS), 5, 3, r)
#define RDD_POLICER_PARAMS_ENTRY_FACTOR_BYTES_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_POLICER_PARAMS_ENTRY_DTS), 5, 3, v)
#define RDD_POLICER_PARAMS_ENTRY_FACTOR_BYTES_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 5, 3, r)
#define RDD_POLICER_PARAMS_ENTRY_FACTOR_BYTES_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 5, 3, v)
#define RDD_POLICER_PARAMS_ENTRY_DEI_MODE_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_POLICER_PARAMS_ENTRY_DTS), 4, 1, r)
#define RDD_POLICER_PARAMS_ENTRY_DEI_MODE_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_POLICER_PARAMS_ENTRY_DTS), 4, 1, v)
#define RDD_POLICER_PARAMS_ENTRY_DEI_MODE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_POLICER_PARAMS_ENTRY_DEI_MODE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)

#define RDD_POLICER_PARAMS_TABLE_SIZE     80
typedef struct
{
	RDD_POLICER_PARAMS_ENTRY_DTS	entry[ RDD_POLICER_PARAMS_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_POLICER_PARAMS_TABLE_DTS;

extern uint32_t RDD_POLICER_PARAMS_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_POLICER_PARAMS_TABLE_PTR(core_id)	( RDD_POLICER_PARAMS_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_POLICER_PARAMS_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_INGRESS_FILTER_L2_REASON_TABLE_SIZE     16
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_INGRESS_FILTER_L2_REASON_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_FILTER_L2_REASON_TABLE_DTS;

extern uint32_t RDD_INGRESS_FILTER_L2_REASON_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_INGRESS_FILTER_L2_REASON_TABLE_PTR(core_id)	( RDD_INGRESS_FILTER_L2_REASON_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_INGRESS_FILTER_L2_REASON_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	ptr       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	ptr       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TCAM_IC_HANDLER_DTS;

#define RDD_TCAM_IC_HANDLER_PTR_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_TCAM_IC_HANDLER_DTS), r)
#define RDD_TCAM_IC_HANDLER_PTR_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_TCAM_IC_HANDLER_DTS), v)
#define RDD_TCAM_IC_HANDLER_PTR_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_TCAM_IC_HANDLER_PTR_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#define RDD_TCAM_IC_HANDLER_PTR_L_READ( wv )               FIELD_GET( wv, 0, 16 )
#define RDD_TCAM_IC_HANDLER_PTR_L_WRITE( v, wv )           FIELD_SET( v, 0, 16, wv )

#define RDD_TCAM_IC_HANDLER_TABLE_SIZE     16
typedef struct
{
	RDD_TCAM_IC_HANDLER_DTS	entry[ RDD_TCAM_IC_HANDLER_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TCAM_IC_HANDLER_TABLE_DTS;

extern uint32_t RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TCAM_IC_HANDLER_TABLE_PTR(core_id)	( RDD_TCAM_IC_HANDLER_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TCAM_IC_HANDLER_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	src_offset	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	size      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cmdid     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	zero      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1 	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	terminator	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_offset	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	dst_offset	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	terminator	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1 	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	zero      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cmdid     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	size      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_offset	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TCAM_IC_CMD_DTS;

#define RDD_TCAM_IC_CMD_SRC_OFFSET_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS), r)
#define RDD_TCAM_IC_CMD_SRC_OFFSET_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS), v)
#define RDD_TCAM_IC_CMD_SRC_OFFSET_READ(r, p)                 MREAD_8((uint8_t *)p, r)
#define RDD_TCAM_IC_CMD_SRC_OFFSET_WRITE(v, p)                MWRITE_8((uint8_t *)p, v)
#define RDD_TCAM_IC_CMD_SRC_OFFSET_L_READ( wv )               FIELD_GET( wv, 24, 8 )
#define RDD_TCAM_IC_CMD_SRC_OFFSET_L_WRITE( v, wv )           FIELD_SET( v, 24, 8, wv )
#define RDD_TCAM_IC_CMD_SIZE_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 1, 4, 4, r)
#define RDD_TCAM_IC_CMD_SIZE_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 1, 4, 4, v)
#define RDD_TCAM_IC_CMD_SIZE_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 4, 4, r)
#define RDD_TCAM_IC_CMD_SIZE_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 4, 4, v)
#define RDD_TCAM_IC_CMD_SIZE_L_READ( wv )                     FIELD_GET( wv, 20, 4 )
#define RDD_TCAM_IC_CMD_SIZE_L_WRITE( v, wv )                 FIELD_SET( v, 20, 4, wv )
#define RDD_TCAM_IC_CMD_CMDID_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 1, 0, 4, r)
#define RDD_TCAM_IC_CMD_CMDID_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 1, 0, 4, v)
#define RDD_TCAM_IC_CMD_CMDID_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 1, 0, 4, r)
#define RDD_TCAM_IC_CMD_CMDID_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 1, 0, 4, v)
#define RDD_TCAM_IC_CMD_CMDID_L_READ( wv )                    FIELD_GET( wv, 16, 4 )
#define RDD_TCAM_IC_CMD_CMDID_L_WRITE( v, wv )                FIELD_SET( v, 16, 4, wv )
#define RDD_TCAM_IC_CMD_ZERO_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 2, 7, 1, r)
#define RDD_TCAM_IC_CMD_ZERO_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 2, 7, 1, v)
#define RDD_TCAM_IC_CMD_ZERO_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 2, 7, 1, r)
#define RDD_TCAM_IC_CMD_ZERO_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 2, 7, 1, v)
#define RDD_TCAM_IC_CMD_ZERO_L_READ( wv )                     FIELD_GET( wv, 15, 1 )
#define RDD_TCAM_IC_CMD_ZERO_L_WRITE( v, wv )                 FIELD_SET( v, 15, 1, wv )
#define RDD_TCAM_IC_CMD_TERMINATOR_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 3, 7, 1, r)
#define RDD_TCAM_IC_CMD_TERMINATOR_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 3, 7, 1, v)
#define RDD_TCAM_IC_CMD_TERMINATOR_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 3, 7, 1, r)
#define RDD_TCAM_IC_CMD_TERMINATOR_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 3, 7, 1, v)
#define RDD_TCAM_IC_CMD_TERMINATOR_L_READ( wv )               FIELD_GET( wv, 7, 1 )
#define RDD_TCAM_IC_CMD_TERMINATOR_L_WRITE( v, wv )           FIELD_SET( v, 7, 1, wv )
#define RDD_TCAM_IC_CMD_DST_OFFSET_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 3, 0, 6, r)
#define RDD_TCAM_IC_CMD_DST_OFFSET_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_TCAM_IC_CMD_DTS) + 3, 0, 6, v)
#define RDD_TCAM_IC_CMD_DST_OFFSET_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 3, 0, 6, r)
#define RDD_TCAM_IC_CMD_DST_OFFSET_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 3, 0, 6, v)
#define RDD_TCAM_IC_CMD_DST_OFFSET_L_READ( wv )               FIELD_GET( wv, 0, 6 )
#define RDD_TCAM_IC_CMD_DST_OFFSET_L_WRITE( v, wv )           FIELD_SET( v, 0, 6, wv )

#define RDD_TCAM_IC_CMD_TABLE_SIZE     6

#define RDD_TCAM_IC_CMD_TABLE_SIZE2    16
typedef struct
{
	RDD_TCAM_IC_CMD_DTS	entry[ RDD_TCAM_IC_CMD_TABLE_SIZE ][ RDD_TCAM_IC_CMD_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TCAM_IC_CMD_TABLE_DTS;

extern uint32_t RDD_TCAM_IC_CMD_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TCAM_IC_CMD_TABLE_PTR(core_id)	( RDD_TCAM_IC_CMD_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TCAM_IC_CMD_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_PBIT_TO_GEM_TABLE_SIZE     8

#define RDD_PBIT_TO_GEM_TABLE_SIZE2    8
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_PBIT_TO_GEM_TABLE_SIZE ][ RDD_PBIT_TO_GEM_TABLE_SIZE2 ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PBIT_TO_GEM_TABLE_DTS;

extern uint32_t RDD_PBIT_TO_GEM_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_PBIT_TO_GEM_TABLE_PTR(core_id)	( RDD_PBIT_TO_GEM_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_PBIT_TO_GEM_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_LOOPBACK_QUEUE_TABLE_SIZE     40
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_LOOPBACK_QUEUE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_LOOPBACK_QUEUE_TABLE_DTS;

extern uint32_t RDD_LOOPBACK_QUEUE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_LOOPBACK_QUEUE_TABLE_PTR(core_id)	( RDD_LOOPBACK_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_LOOPBACK_QUEUE_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	low       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	high      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	low       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	high      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DEF_FLOW_CONTEXT_DDR_ADDR_DTS;

#define RDD_DEF_FLOW_CONTEXT_DDR_ADDR_LOW_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_DEF_FLOW_CONTEXT_DDR_ADDR_DTS), r)
#define RDD_DEF_FLOW_CONTEXT_DDR_ADDR_LOW_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_DEF_FLOW_CONTEXT_DDR_ADDR_DTS), v)
#define RDD_DEF_FLOW_CONTEXT_DDR_ADDR_LOW_READ(r, p)                  MREAD_32((uint8_t *)p, r)
#define RDD_DEF_FLOW_CONTEXT_DDR_ADDR_LOW_WRITE(v, p)                 MWRITE_32((uint8_t *)p, v)
#define RDD_DEF_FLOW_CONTEXT_DDR_ADDR_HIGH_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_DEF_FLOW_CONTEXT_DDR_ADDR_DTS) + 4, r)
#define RDD_DEF_FLOW_CONTEXT_DDR_ADDR_HIGH_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_DEF_FLOW_CONTEXT_DDR_ADDR_DTS) + 4, v)
#define RDD_DEF_FLOW_CONTEXT_DDR_ADDR_HIGH_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_DEF_FLOW_CONTEXT_DDR_ADDR_HIGH_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
typedef struct
{
	RDD_DEF_FLOW_CONTEXT_DDR_ADDR_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RX_FLOW_CONTEXT_DDR_ADDR_DTS;

extern uint32_t RDD_RX_FLOW_CONTEXT_DDR_ADDR_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_RX_FLOW_CONTEXT_DDR_ADDR_PTR(core_id)	( RDD_RX_FLOW_CONTEXT_DDR_ADDR_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_RX_FLOW_CONTEXT_DDR_ADDR_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTES_8_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NULL_BUFFER_DTS;

extern uint32_t RDD_NULL_BUFFER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_NULL_BUFFER_PTR(core_id)	( RDD_NULL_BUFFER_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_NULL_BUFFER_ADDRESS_ARR[core_id] ))

#define RDD_TC_TO_QUEUE_8_QUEUE_OFFSET_NUMBER	8

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	queue_offset[RDD_TC_TO_QUEUE_8_QUEUE_OFFSET_NUMBER];
#else
	uint8_t	queue_offset[RDD_TC_TO_QUEUE_8_QUEUE_OFFSET_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TC_TO_QUEUE_8_DTS;

#define RDD_TC_TO_QUEUE_8_QUEUE_OFFSET_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_TC_TO_QUEUE_8_DTS), i, r)
#define RDD_TC_TO_QUEUE_8_QUEUE_OFFSET_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_TC_TO_QUEUE_8_DTS), i, v)
#define RDD_TC_TO_QUEUE_8_QUEUE_OFFSET_READ(r, p, i)              MREAD_I_8((uint8_t *)p, i, r)
#define RDD_TC_TO_QUEUE_8_QUEUE_OFFSET_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p, i, v)

#define RDD_TC_TO_QUEUE_TABLE_SIZE     65
typedef struct
{
	RDD_TC_TO_QUEUE_8_DTS	entry[ RDD_TC_TO_QUEUE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TC_TO_QUEUE_TABLE_DTS;

extern uint32_t RDD_TC_TO_QUEUE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TC_TO_QUEUE_TABLE_PTR(core_id)	( RDD_TC_TO_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TC_TO_QUEUE_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	reserved                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aggregation_en          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	arl_lookup_method       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_bridge_arl_lookup_method enumeration*/
	uint32_t	wan_vid                 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port_isolation_map_31_24	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port_isolation_map_23_0 	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	wan_vid                 	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	arl_lookup_method       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_bridge_arl_lookup_method enumeration*/
	uint32_t	aggregation_en          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port_isolation_map_23_0 	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port_isolation_map_31_24	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS;

#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 2, 5, 1, r)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 2, 5, 1, v)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 2, 5, 1, r)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 2, 5, 1, v)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 2, 4, 1, r) /*defined by rdd_bridge_arl_lookup_method enumeration*/
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 2, 4, 1, v) /*defined by rdd_bridge_arl_lookup_method enumeration*/
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 2, 4, 1, r) /*defined by rdd_bridge_arl_lookup_method enumeration*/
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 2, 4, 1, v) /*defined by rdd_bridge_arl_lookup_method enumeration*/
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 2, 0, 12, r)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 2, 0, 12, v)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_READ(r, p)                                  FIELD_MREAD_16((uint8_t *)p + 2, 0, 12, r)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_WRITE(v, p)                                 FIELD_MWRITE_16((uint8_t *)p + 2, 0, 12, v)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 4, r)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 4, v)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_READ(r, p)                 MREAD_8((uint8_t *)p + 4, r)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_WRITE(v, p)                MWRITE_8((uint8_t *)p + 4, v)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_READ_G(r, g, idx)           GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 4, 0, 24, r)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS) + 4, 0, 24, v)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_READ(r, p)                  FIELD_MREAD_32((uint8_t *)p + 4, 0, 24, r)
#define RDD_BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_WRITE(v, p)                 FIELD_MWRITE_32((uint8_t *)p + 4, 0, 24, v)
typedef struct
{
	RDD_BRIDGE_AND_VLAN_LKP_RESULT_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DEFAULT_BRIDGE_CFG_DTS;

extern uint32_t RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_DEFAULT_BRIDGE_CFG_PTR(core_id)	( RDD_DEFAULT_BRIDGE_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_DEFAULT_BRIDGE_CFG_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	res_offset           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_offset       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cmd_table            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scratch_offset       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_size             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	classification_result	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	context_offset       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	res_offset           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scratch_offset       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cmd_table            	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_size             	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	classification_result	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TCAM_IC_CFG_DTS;

#define RDD_TCAM_IC_CFG_RES_OFFSET_READ_G(r, g, idx)                     GROUP_MREAD_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS), r)
#define RDD_TCAM_IC_CFG_RES_OFFSET_WRITE_G(v, g, idx)                    GROUP_MWRITE_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS), v)
#define RDD_TCAM_IC_CFG_RES_OFFSET_READ(r, p)                            MREAD_16((uint8_t *)p, r)
#define RDD_TCAM_IC_CFG_RES_OFFSET_WRITE(v, p)                           MWRITE_16((uint8_t *)p, v)
#define RDD_TCAM_IC_CFG_RES_OFFSET_L_READ( wv )                          FIELD_GET( wv, 16, 16 )
#define RDD_TCAM_IC_CFG_RES_OFFSET_L_WRITE( v, wv )                      FIELD_SET( v, 16, 16, wv )
#define RDD_TCAM_IC_CFG_CONTEXT_OFFSET_READ_G(r, g, idx)                 GROUP_MREAD_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 2, r)
#define RDD_TCAM_IC_CFG_CONTEXT_OFFSET_WRITE_G(v, g, idx)                GROUP_MWRITE_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 2, v)
#define RDD_TCAM_IC_CFG_CONTEXT_OFFSET_READ(r, p)                        MREAD_16((uint8_t *)p + 2, r)
#define RDD_TCAM_IC_CFG_CONTEXT_OFFSET_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 2, v)
#define RDD_TCAM_IC_CFG_CONTEXT_OFFSET_L_READ( wv )                      FIELD_GET( wv, 0, 16 )
#define RDD_TCAM_IC_CFG_CONTEXT_OFFSET_L_WRITE( v, wv )                  FIELD_SET( v, 0, 16, wv )
#define RDD_TCAM_IC_CFG_CMD_TABLE_READ_G(r, g, idx)                      GROUP_MREAD_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 4, r)
#define RDD_TCAM_IC_CFG_CMD_TABLE_WRITE_G(v, g, idx)                     GROUP_MWRITE_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 4, v)
#define RDD_TCAM_IC_CFG_CMD_TABLE_READ(r, p)                             MREAD_16((uint8_t *)p + 4, r)
#define RDD_TCAM_IC_CFG_CMD_TABLE_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 4, v)
#define RDD_TCAM_IC_CFG_CMD_TABLE_L_READ( wv )                           FIELD_GET( wv, 16, 16 )
#define RDD_TCAM_IC_CFG_CMD_TABLE_L_WRITE( v, wv )                       FIELD_SET( v, 16, 16, wv )
#define RDD_TCAM_IC_CFG_SCRATCH_OFFSET_READ_G(r, g, idx)                 GROUP_MREAD_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 6, r)
#define RDD_TCAM_IC_CFG_SCRATCH_OFFSET_WRITE_G(v, g, idx)                GROUP_MWRITE_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 6, v)
#define RDD_TCAM_IC_CFG_SCRATCH_OFFSET_READ(r, p)                        MREAD_16((uint8_t *)p + 6, r)
#define RDD_TCAM_IC_CFG_SCRATCH_OFFSET_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 6, v)
#define RDD_TCAM_IC_CFG_SCRATCH_OFFSET_L_READ( wv )                      FIELD_GET( wv, 0, 16 )
#define RDD_TCAM_IC_CFG_SCRATCH_OFFSET_L_WRITE( v, wv )                  FIELD_SET( v, 0, 16, wv )
#define RDD_TCAM_IC_CFG_KEY_SIZE_READ_G(r, g, idx)                       GROUP_MREAD_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 8, r)
#define RDD_TCAM_IC_CFG_KEY_SIZE_WRITE_G(v, g, idx)                      GROUP_MWRITE_16(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 8, v)
#define RDD_TCAM_IC_CFG_KEY_SIZE_READ(r, p)                              MREAD_16((uint8_t *)p + 8, r)
#define RDD_TCAM_IC_CFG_KEY_SIZE_WRITE(v, p)                             MWRITE_16((uint8_t *)p + 8, v)
#define RDD_TCAM_IC_CFG_KEY_SIZE_L_READ( wv )                            FIELD_GET( wv, 16, 16 )
#define RDD_TCAM_IC_CFG_KEY_SIZE_L_WRITE( v, wv )                        FIELD_SET( v, 16, 16, wv )
#define RDD_TCAM_IC_CFG_CLASSIFICATION_RESULT_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 12, r)
#define RDD_TCAM_IC_CFG_CLASSIFICATION_RESULT_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_TCAM_IC_CFG_DTS) + 12, v)
#define RDD_TCAM_IC_CFG_CLASSIFICATION_RESULT_READ(r, p)                 MREAD_32((uint8_t *)p + 12, r)
#define RDD_TCAM_IC_CFG_CLASSIFICATION_RESULT_WRITE(v, p)                MWRITE_32((uint8_t *)p + 12, v)
#define RDD_TCAM_IC_CFG_CLASSIFICATION_RESULT_L_READ( wv )               FIELD_GET( wv, 0, 32 )
#define RDD_TCAM_IC_CFG_CLASSIFICATION_RESULT_L_WRITE( v, wv )           FIELD_SET( v, 0, 32, wv )

#define RDD_TCAM_IC_CFG_TABLE_SIZE     5
typedef struct
{
	RDD_TCAM_IC_CFG_DTS	entry[ RDD_TCAM_IC_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TCAM_IC_CFG_TABLE_DTS;

extern uint32_t RDD_TCAM_IC_CFG_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_TCAM_IC_CFG_TABLE_PTR(core_id)	( RDD_TCAM_IC_CFG_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_TCAM_IC_CFG_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_SIZE     64
typedef struct
{
	RDD_BYTE_1_DTS	entry[ RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_DTS;

extern uint32_t RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_PTR(core_id)	( RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_INGRESS_FILTER_VPORT_TO_PROFILE_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FORCE_DSCP_DTS;

extern uint32_t RDD_FORCE_DSCP_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_FORCE_DSCP_PTR(core_id)	( RDD_FORCE_DSCP_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_FORCE_DSCP_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CORE_ID_TABLE_DTS;

extern uint32_t RDD_CORE_ID_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_CORE_ID_TABLE_PTR(core_id)	( RDD_CORE_ID_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_CORE_ID_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	ds_drop_precedence_eligibility_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	us_drop_precedence_eligibility_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	full_flow_cache_mode                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                             	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	us_drop_precedence_eligibility_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ds_drop_precedence_eligibility_vector	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                             	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	full_flow_cache_mode                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SYSTEM_CONFIGURATION_ENTRY_DTS;

#define RDD_SYSTEM_CONFIGURATION_ENTRY_DS_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_SYSTEM_CONFIGURATION_ENTRY_DTS), r)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_DS_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_SYSTEM_CONFIGURATION_ENTRY_DTS), v)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_DS_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_DS_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_US_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_SYSTEM_CONFIGURATION_ENTRY_DTS) + 2, r)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_US_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_SYSTEM_CONFIGURATION_ENTRY_DTS) + 2, v)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_US_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_US_DROP_PRECEDENCE_ELIGIBILITY_VECTOR_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_FULL_FLOW_CACHE_MODE_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_SYSTEM_CONFIGURATION_ENTRY_DTS) + 4, 7, 1, r)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_FULL_FLOW_CACHE_MODE_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_SYSTEM_CONFIGURATION_ENTRY_DTS) + 4, 7, 1, v)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_FULL_FLOW_CACHE_MODE_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_SYSTEM_CONFIGURATION_ENTRY_FULL_FLOW_CACHE_MODE_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
typedef struct
{
	RDD_SYSTEM_CONFIGURATION_ENTRY_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_SYSTEM_CONFIGURATION_DTS;

extern uint32_t RDD_SYSTEM_CONFIGURATION_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_SYSTEM_CONFIGURATION_PTR(core_id)	( RDD_SYSTEM_CONFIGURATION_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_SYSTEM_CONFIGURATION_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_MIRRORING_DESCRIPTOR_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RX_MIRRORING_CONFIGURATION_DTS;

extern uint32_t RDD_RX_MIRRORING_CONFIGURATION_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_RX_MIRRORING_CONFIGURATION_PTR(core_id)	( RDD_RX_MIRRORING_CONFIGURATION_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_RX_MIRRORING_CONFIGURATION_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	res_offset    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_offset	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_offset    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hash_tbl_idx  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_mcast      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	context_offset	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	res_offset    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_mcast      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hash_tbl_idx  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_offset    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_CFG_DTS;

#define RDD_IPTV_CFG_RES_OFFSET_READ_G(r, g, idx)              GROUP_MREAD_16(g, idx*sizeof(RDD_IPTV_CFG_DTS), r)
#define RDD_IPTV_CFG_RES_OFFSET_WRITE_G(v, g, idx)             GROUP_MWRITE_16(g, idx*sizeof(RDD_IPTV_CFG_DTS), v)
#define RDD_IPTV_CFG_RES_OFFSET_READ(r, p)                     MREAD_16((uint8_t *)p, r)
#define RDD_IPTV_CFG_RES_OFFSET_WRITE(v, p)                    MWRITE_16((uint8_t *)p, v)
#define RDD_IPTV_CFG_CONTEXT_OFFSET_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_IPTV_CFG_DTS) + 2, r)
#define RDD_IPTV_CFG_CONTEXT_OFFSET_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_IPTV_CFG_DTS) + 2, v)
#define RDD_IPTV_CFG_CONTEXT_OFFSET_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_IPTV_CFG_CONTEXT_OFFSET_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_IPTV_CFG_KEY_OFFSET_READ_G(r, g, idx)              GROUP_MREAD_16(g, idx*sizeof(RDD_IPTV_CFG_DTS) + 4, r)
#define RDD_IPTV_CFG_KEY_OFFSET_WRITE_G(v, g, idx)             GROUP_MWRITE_16(g, idx*sizeof(RDD_IPTV_CFG_DTS) + 4, v)
#define RDD_IPTV_CFG_KEY_OFFSET_READ(r, p)                     MREAD_16((uint8_t *)p + 4, r)
#define RDD_IPTV_CFG_KEY_OFFSET_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 4, v)
#define RDD_IPTV_CFG_HASH_TBL_IDX_READ_G(r, g, idx)            GROUP_MREAD_8(g, idx*sizeof(RDD_IPTV_CFG_DTS) + 6, r)
#define RDD_IPTV_CFG_HASH_TBL_IDX_WRITE_G(v, g, idx)           GROUP_MWRITE_8(g, idx*sizeof(RDD_IPTV_CFG_DTS) + 6, v)
#define RDD_IPTV_CFG_HASH_TBL_IDX_READ(r, p)                   MREAD_8((uint8_t *)p + 6, r)
#define RDD_IPTV_CFG_HASH_TBL_IDX_WRITE(v, p)                  MWRITE_8((uint8_t *)p + 6, v)
#define RDD_IPTV_CFG_L2_MCAST_READ_G(r, g, idx)                GROUP_MREAD_8(g, idx*sizeof(RDD_IPTV_CFG_DTS) + 7, r)
#define RDD_IPTV_CFG_L2_MCAST_WRITE_G(v, g, idx)               GROUP_MWRITE_8(g, idx*sizeof(RDD_IPTV_CFG_DTS) + 7, v)
#define RDD_IPTV_CFG_L2_MCAST_READ(r, p)                       MREAD_8((uint8_t *)p + 7, r)
#define RDD_IPTV_CFG_L2_MCAST_WRITE(v, p)                      MWRITE_8((uint8_t *)p + 7, v)
typedef struct
{
	RDD_IPTV_CFG_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_CFG_TABLE_DTS;

extern uint32_t RDD_IPTV_CFG_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_IPTV_CFG_TABLE_PTR(core_id)	( RDD_IPTV_CFG_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_IPTV_CFG_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	low       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	high      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	low       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	high      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_DDR_CTX_TABLE_ADDRESS_DTS;

#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_LOW_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_IPTV_DDR_CTX_TABLE_ADDRESS_DTS), r)
#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_LOW_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_IPTV_DDR_CTX_TABLE_ADDRESS_DTS), v)
#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_LOW_READ(r, p)                  MREAD_32((uint8_t *)p, r)
#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_LOW_WRITE(v, p)                 MWRITE_32((uint8_t *)p, v)
#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_HIGH_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_IPTV_DDR_CTX_TABLE_ADDRESS_DTS) + 4, r)
#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_HIGH_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_IPTV_DDR_CTX_TABLE_ADDRESS_DTS) + 4, v)
#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_HIGH_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_HIGH_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
typedef struct
{
	RDD_IPTV_DDR_CTX_TABLE_ADDRESS_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_DDR_CTX_TABLE_ADDRESS_TABLE_DTS;

extern uint32_t RDD_IPTV_DDR_CTX_TABLE_ADDRESS_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_IPTV_DDR_CTX_TABLE_ADDRESS_PTR(core_id)	( RDD_IPTV_DDR_CTX_TABLE_ADDRESS_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_IPTV_DDR_CTX_TABLE_ADDRESS_ADDRESS_ARR[core_id] ))


#define RDD_FLOW_BASED_ACTION_PTR_TABLE_SIZE     17
typedef struct
{
	RDD_BYTES_2_DTS	entry[ RDD_FLOW_BASED_ACTION_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FLOW_BASED_ACTION_PTR_TABLE_DTS;

extern uint32_t RDD_FLOW_BASED_ACTION_PTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_FLOW_BASED_ACTION_PTR_TABLE_PTR(core_id)	( RDD_FLOW_BASED_ACTION_PTR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_FLOW_BASED_ACTION_PTR_TABLE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IC_DEBUG_COUNTER_MODE_DTS;

extern uint32_t RDD_IC_DEBUG_COUNTER_MODE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_IC_DEBUG_COUNTER_MODE_PTR(core_id)	( RDD_IC_DEBUG_COUNTER_MODE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_IC_DEBUG_COUNTER_MODE_ADDRESS_ARR[core_id] ))

typedef struct
{
	RDD_BYTE_1_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_FILTER_1588_CFG_DTS;

extern uint32_t RDD_INGRESS_FILTER_1588_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_INGRESS_FILTER_1588_CFG_PTR(core_id)	( RDD_INGRESS_FILTER_1588_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_INGRESS_FILTER_1588_CFG_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	res_offset        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context_offset    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_offset        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved          	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	three_tuple_enable	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	esp_filter_action 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	esp_filter_enable 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	context_offset    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	res_offset        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	esp_filter_enable 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	esp_filter_action 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	three_tuple_enable	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved          	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_offset        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_CFG_DTS;

#define RDD_NAT_CACHE_CFG_RES_OFFSET_READ_G(r, g, idx)                  GROUP_MREAD_16(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS), r)
#define RDD_NAT_CACHE_CFG_RES_OFFSET_WRITE_G(v, g, idx)                 GROUP_MWRITE_16(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS), v)
#define RDD_NAT_CACHE_CFG_RES_OFFSET_READ(r, p)                         MREAD_16((uint8_t *)p, r)
#define RDD_NAT_CACHE_CFG_RES_OFFSET_WRITE(v, p)                        MWRITE_16((uint8_t *)p, v)
#define RDD_NAT_CACHE_CFG_RES_OFFSET_L_READ( wv )                       FIELD_GET( wv, 16, 16 )
#define RDD_NAT_CACHE_CFG_RES_OFFSET_L_WRITE( v, wv )                   FIELD_SET( v, 16, 16, wv )
#define RDD_NAT_CACHE_CFG_CONTEXT_OFFSET_READ_G(r, g, idx)              GROUP_MREAD_16(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 2, r)
#define RDD_NAT_CACHE_CFG_CONTEXT_OFFSET_WRITE_G(v, g, idx)             GROUP_MWRITE_16(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 2, v)
#define RDD_NAT_CACHE_CFG_CONTEXT_OFFSET_READ(r, p)                     MREAD_16((uint8_t *)p + 2, r)
#define RDD_NAT_CACHE_CFG_CONTEXT_OFFSET_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 2, v)
#define RDD_NAT_CACHE_CFG_CONTEXT_OFFSET_L_READ( wv )                   FIELD_GET( wv, 0, 16 )
#define RDD_NAT_CACHE_CFG_CONTEXT_OFFSET_L_WRITE( v, wv )               FIELD_SET( v, 0, 16, wv )
#define RDD_NAT_CACHE_CFG_KEY_OFFSET_READ_G(r, g, idx)                  GROUP_MREAD_16(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 4, r)
#define RDD_NAT_CACHE_CFG_KEY_OFFSET_WRITE_G(v, g, idx)                 GROUP_MWRITE_16(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 4, v)
#define RDD_NAT_CACHE_CFG_KEY_OFFSET_READ(r, p)                         MREAD_16((uint8_t *)p + 4, r)
#define RDD_NAT_CACHE_CFG_KEY_OFFSET_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 4, v)
#define RDD_NAT_CACHE_CFG_KEY_OFFSET_L_READ( wv )                       FIELD_GET( wv, 16, 16 )
#define RDD_NAT_CACHE_CFG_KEY_OFFSET_L_WRITE( v, wv )                   FIELD_SET( v, 16, 16, wv )
#define RDD_NAT_CACHE_CFG_THREE_TUPLE_ENABLE_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 6, 2, 1, r)
#define RDD_NAT_CACHE_CFG_THREE_TUPLE_ENABLE_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 6, 2, 1, v)
#define RDD_NAT_CACHE_CFG_THREE_TUPLE_ENABLE_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 6, 2, 1, r)
#define RDD_NAT_CACHE_CFG_THREE_TUPLE_ENABLE_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 6, 2, 1, v)
#define RDD_NAT_CACHE_CFG_THREE_TUPLE_ENABLE_L_READ( wv )               FIELD_GET( wv, 10, 1 )
#define RDD_NAT_CACHE_CFG_THREE_TUPLE_ENABLE_L_WRITE( v, wv )           FIELD_SET( v, 10, 1, wv )
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ACTION_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 6, 1, 1, r)
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ACTION_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 6, 1, 1, v)
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ACTION_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 6, 1, 1, r)
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ACTION_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 6, 1, 1, v)
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ACTION_L_READ( wv )                FIELD_GET( wv, 9, 1 )
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ACTION_L_WRITE( v, wv )            FIELD_SET( v, 9, 1, wv )
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ENABLE_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 6, 0, 1, r)
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ENABLE_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NAT_CACHE_CFG_DTS) + 6, 0, 1, v)
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ENABLE_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 6, 0, 1, r)
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ENABLE_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 6, 0, 1, v)
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ENABLE_L_READ( wv )                FIELD_GET( wv, 8, 1 )
#define RDD_NAT_CACHE_CFG_ESP_FILTER_ENABLE_L_WRITE( v, wv )            FIELD_SET( v, 8, 1, wv )
typedef struct
{
	RDD_NAT_CACHE_CFG_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_CFG_TABLE_DTS;

extern uint32_t RDD_NAT_CACHE_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_NAT_CACHE_CFG_PTR(core_id)	( RDD_NAT_CACHE_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_NAT_CACHE_CFG_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	res_offset	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	res_offset	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_FILTER_CFG_DTS;

#define RDD_INGRESS_FILTER_CFG_RES_OFFSET_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_INGRESS_FILTER_CFG_DTS), r)
#define RDD_INGRESS_FILTER_CFG_RES_OFFSET_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_INGRESS_FILTER_CFG_DTS), v)
#define RDD_INGRESS_FILTER_CFG_RES_OFFSET_READ(r, p)                 MREAD_16((uint8_t *)p, r)
#define RDD_INGRESS_FILTER_CFG_RES_OFFSET_WRITE(v, p)                MWRITE_16((uint8_t *)p, v)
typedef struct
{
	RDD_INGRESS_FILTER_CFG_DTS	entry;
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_INGRESS_FILTER_CFG_TABLE_DTS;

extern uint32_t RDD_INGRESS_FILTER_CFG_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_INGRESS_FILTER_CFG_PTR(core_id)	( RDD_INGRESS_FILTER_CFG_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_INGRESS_FILTER_CFG_ADDRESS_ARR[core_id] ))


#define RDD_RULE_BASED_ACTION_PTR_TABLE_SIZE     17
typedef struct
{
	RDD_BYTES_2_DTS	entry[ RDD_RULE_BASED_ACTION_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RULE_BASED_ACTION_PTR_TABLE_DTS;

extern uint32_t RDD_RULE_BASED_ACTION_PTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_RULE_BASED_ACTION_PTR_TABLE_PTR(core_id)	( RDD_RULE_BASED_ACTION_PTR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_RULE_BASED_ACTION_PTR_TABLE_ADDRESS_ARR[core_id] ))

#define RDD_PBIT_TO_QUEUE_8_QUEUE_OFFSET_NUMBER	8

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	queue_offset[RDD_PBIT_TO_QUEUE_8_QUEUE_OFFSET_NUMBER];
#else
	uint8_t	queue_offset[RDD_PBIT_TO_QUEUE_8_QUEUE_OFFSET_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PBIT_TO_QUEUE_8_DTS;

#define RDD_PBIT_TO_QUEUE_8_QUEUE_OFFSET_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_PBIT_TO_QUEUE_8_DTS), i, r)
#define RDD_PBIT_TO_QUEUE_8_QUEUE_OFFSET_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PBIT_TO_QUEUE_8_DTS), i, v)
#define RDD_PBIT_TO_QUEUE_8_QUEUE_OFFSET_READ(r, p, i)              MREAD_I_8((uint8_t *)p, i, r)
#define RDD_PBIT_TO_QUEUE_8_QUEUE_OFFSET_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p, i, v)

#define RDD_PBIT_TO_QUEUE_TABLE_SIZE     65
typedef struct
{
	RDD_PBIT_TO_QUEUE_8_DTS	entry[ RDD_PBIT_TO_QUEUE_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PBIT_TO_QUEUE_TABLE_DTS;

extern uint32_t RDD_PBIT_TO_QUEUE_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_PBIT_TO_QUEUE_TABLE_PTR(core_id)	( RDD_PBIT_TO_QUEUE_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_PBIT_TO_QUEUE_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	hit                            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_fw_failed               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_aggregation               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                      	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_and_vlan_lkp_miss_no_fwd	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_and_vlan_lkp_miss_action	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_no_fwd_action enumeration*/
	uint32_t	bridge_aggregation_en          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_results_available       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	res_offset                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	res_offset                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_results_available       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_aggregation_en          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_and_vlan_lkp_miss_action	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_no_fwd_action enumeration*/
	uint32_t	bridge_and_vlan_lkp_miss_no_fwd	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                      	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_aggregation               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_fw_failed               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hit                            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                       	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_CFG_DTS;

#define RDD_BRIDGE_CFG_HIT_READ_G(r, g, idx)                                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS), 7, 1, r)
#define RDD_BRIDGE_CFG_HIT_WRITE_G(v, g, idx)                                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS), 7, 1, v)
#define RDD_BRIDGE_CFG_HIT_READ(r, p)                                             FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_BRIDGE_CFG_HIT_WRITE(v, p)                                            FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_BRIDGE_CFG_BRIDGE_FW_FAILED_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS), 6, 1, r)
#define RDD_BRIDGE_CFG_BRIDGE_FW_FAILED_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS), 6, 1, v)
#define RDD_BRIDGE_CFG_BRIDGE_FW_FAILED_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_BRIDGE_CFG_BRIDGE_FW_FAILED_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_BRIDGE_CFG_VLAN_AGGREGATION_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS), 5, 1, r)
#define RDD_BRIDGE_CFG_VLAN_AGGREGATION_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS), 5, 1, v)
#define RDD_BRIDGE_CFG_VLAN_AGGREGATION_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_BRIDGE_CFG_VLAN_AGGREGATION_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 1, 3, 1, r)
#define RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 1, 3, 1, v)
#define RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 3, 1, r)
#define RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 3, 1, v)
#define RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 1, 2, 1, r) /*defined by rdd_no_fwd_action enumeration*/
#define RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 1, 2, 1, v) /*defined by rdd_no_fwd_action enumeration*/
#define RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 2, 1, r) /*defined by rdd_no_fwd_action enumeration*/
#define RDD_BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 2, 1, v) /*defined by rdd_no_fwd_action enumeration*/
#define RDD_BRIDGE_CFG_BRIDGE_AGGREGATION_EN_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 1, 1, 1, r)
#define RDD_BRIDGE_CFG_BRIDGE_AGGREGATION_EN_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 1, 1, 1, v)
#define RDD_BRIDGE_CFG_BRIDGE_AGGREGATION_EN_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_BRIDGE_CFG_BRIDGE_AGGREGATION_EN_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 1, 0, 1, r)
#define RDD_BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 1, 0, 1, v)
#define RDD_BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 1, 0, 1, r)
#define RDD_BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 1, 0, 1, v)
#define RDD_BRIDGE_CFG_RES_OFFSET_READ_G(r, g, idx)                               GROUP_MREAD_16(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 2, r)
#define RDD_BRIDGE_CFG_RES_OFFSET_WRITE_G(v, g, idx)                              GROUP_MWRITE_16(g, idx*sizeof(RDD_BRIDGE_CFG_DTS) + 2, v)
#define RDD_BRIDGE_CFG_RES_OFFSET_READ(r, p)                                      MREAD_16((uint8_t *)p + 2, r)
#define RDD_BRIDGE_CFG_RES_OFFSET_WRITE(v, p)                                     MWRITE_16((uint8_t *)p + 2, v)

#define RDD_BRIDGE_CFG_TABLE_SIZE     3
typedef struct
{
	RDD_BRIDGE_CFG_DTS	entry[ RDD_BRIDGE_CFG_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_CFG_TABLE_DTS;

extern uint32_t RDD_BRIDGE_CFG_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_BRIDGE_CFG_TABLE_PTR(core_id)	( RDD_BRIDGE_CFG_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_BRIDGE_CFG_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_SIZE     17
typedef struct
{
	RDD_BYTES_2_DTS	entry[ RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_DTS;

extern uint32_t RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_PTR(core_id)	( RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_RULE_BASED_CONTEXT_ACTION_PTR_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_IPTV_ACTION_PTR_TABLE_SIZE     17
typedef struct
{
	RDD_BYTES_2_DTS	entry[ RDD_IPTV_ACTION_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_ACTION_PTR_TABLE_DTS;

extern uint32_t RDD_IPTV_ACTION_PTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_IPTV_ACTION_PTR_TABLE_PTR(core_id)	( RDD_IPTV_ACTION_PTR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_IPTV_ACTION_PTR_TABLE_ADDRESS_ARR[core_id] ))


#define RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_SIZE     17
typedef struct
{
	RDD_BYTES_2_DTS	entry[ RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_DTS;

extern uint32_t RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_PTR(core_id)	( RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_VLAN_ACTION_GPE_HANDLER_PTR_TABLE_ADDRESS_ARR[core_id] ))


typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	cntr_id                  	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_id               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_rule_wan_flow_overrun	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	opbit_remark_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipbit_remark_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbit               	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbit               	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	inner_pbit               	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbit               	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipbit_remark_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	opbit_remark_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_rule_wan_flow_overrun	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_id               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cntr_id                  	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IC_EXT_CONTEXT_ENTRY_DTS;

#define RDD_IC_EXT_CONTEXT_ENTRY_CNTR_ID_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS), 5, 11, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_CNTR_ID_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS), 5, 11, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_CNTR_ID_READ(r, p)                                   FIELD_MREAD_16((uint8_t *)p, 5, 11, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_CNTR_ID_WRITE(v, p)                                  FIELD_MWRITE_16((uint8_t *)p, 5, 11, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_POLICER_ID_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 2, 1, 7, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_POLICER_ID_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 2, 1, 7, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_POLICER_ID_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 2, 1, 7, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_POLICER_ID_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 2, 1, 7, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_QOS_RULE_WAN_FLOW_OVERRUN_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 2, 0, 1, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_QOS_RULE_WAN_FLOW_OVERRUN_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 2, 0, 1, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_QOS_RULE_WAN_FLOW_OVERRUN_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_QOS_RULE_WAN_FLOW_OVERRUN_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_OPBIT_REMARK_MODE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 3, 7, 1, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_OPBIT_REMARK_MODE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 3, 7, 1, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_OPBIT_REMARK_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 3, 7, 1, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_OPBIT_REMARK_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 3, 7, 1, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_IPBIT_REMARK_MODE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 3, 6, 1, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_IPBIT_REMARK_MODE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 3, 6, 1, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_IPBIT_REMARK_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 3, 6, 1, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_IPBIT_REMARK_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 3, 6, 1, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_OUTER_PBIT_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 3, 3, 3, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_OUTER_PBIT_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 3, 3, 3, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_OUTER_PBIT_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 3, 3, 3, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_OUTER_PBIT_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 3, 3, 3, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_INNER_PBIT_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 3, 0, 3, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_INNER_PBIT_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IC_EXT_CONTEXT_ENTRY_DTS) + 3, 0, 3, v)
#define RDD_IC_EXT_CONTEXT_ENTRY_INNER_PBIT_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 3, 0, 3, r)
#define RDD_IC_EXT_CONTEXT_ENTRY_INNER_PBIT_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 3, 0, 3, v)

#define RDD_IC_EXT_CONTEXT_TABLE_SIZE     1024
typedef struct
{
	RDD_IC_EXT_CONTEXT_ENTRY_DTS	entry[ RDD_IC_EXT_CONTEXT_TABLE_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IC_EXT_CONTEXT_TABLE_DTS;

extern uint32_t RDD_IC_EXT_CONTEXT_TABLE_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_IC_EXT_CONTEXT_TABLE_PTR(core_id)	( RDD_IC_EXT_CONTEXT_TABLE_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_IC_EXT_CONTEXT_TABLE_ADDRESS_ARR[core_id] ))

#define RDD_PACKET_BUFFER_PACKET_HEADER_NUMBER	128
#define RDD_PACKET_BUFFER_PARSER_RESULT_NUMBER	56
#define RDD_PACKET_BUFFER_SCRATCH_NUMBER	136
#define RDD_PACKET_BUFFER_PD_NUMBER	16
#define RDD_PACKET_BUFFER_RESOLUTION_CONTEXT_NUMBER	16
#define RDD_PACKET_BUFFER_CLASSIFICATION_RESULTS_NUMBER	7
#define RDD_PACKET_BUFFER_RESERVED_NUMBER	4
#define RDD_PACKET_BUFFER_CLASSIFICATION_CONTEXTS_LIST_NUMBER	128

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	packet_header[RDD_PACKET_BUFFER_PACKET_HEADER_NUMBER];
	uint8_t	parser_result[RDD_PACKET_BUFFER_PARSER_RESULT_NUMBER];
	uint8_t	scratch[RDD_PACKET_BUFFER_SCRATCH_NUMBER];
	uint8_t	pd[RDD_PACKET_BUFFER_PD_NUMBER];
	uint8_t	resolution_context[RDD_PACKET_BUFFER_RESOLUTION_CONTEXT_NUMBER];
	uint32_t	classification_results[RDD_PACKET_BUFFER_CLASSIFICATION_RESULTS_NUMBER];
	uint8_t	reserved[RDD_PACKET_BUFFER_RESERVED_NUMBER];
	uint8_t	classification_contexts_list[RDD_PACKET_BUFFER_CLASSIFICATION_CONTEXTS_LIST_NUMBER];
#else
	uint8_t	packet_header[RDD_PACKET_BUFFER_PACKET_HEADER_NUMBER];
	uint8_t	parser_result[RDD_PACKET_BUFFER_PARSER_RESULT_NUMBER];
	uint8_t	scratch[RDD_PACKET_BUFFER_SCRATCH_NUMBER];
	uint8_t	pd[RDD_PACKET_BUFFER_PD_NUMBER];
	uint8_t	resolution_context[RDD_PACKET_BUFFER_RESOLUTION_CONTEXT_NUMBER];
	uint32_t	classification_results[RDD_PACKET_BUFFER_CLASSIFICATION_RESULTS_NUMBER];
	uint8_t	reserved[RDD_PACKET_BUFFER_RESERVED_NUMBER];
	uint8_t	classification_contexts_list[RDD_PACKET_BUFFER_CLASSIFICATION_CONTEXTS_LIST_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PACKET_BUFFER_DTS;

#define RDD_PACKET_BUFFER_PACKET_HEADER_READ_G(r, g, idx, i)                      GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS), i, r)
#define RDD_PACKET_BUFFER_PACKET_HEADER_WRITE_G(v, g, idx, i)                     GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS), i, v)
#define RDD_PACKET_BUFFER_PACKET_HEADER_READ(r, p, i)                             MREAD_I_8((uint8_t *)p, i, r)
#define RDD_PACKET_BUFFER_PACKET_HEADER_WRITE(v, p, i)                            MWRITE_I_8((uint8_t *)p, i, v)
#define RDD_PACKET_BUFFER_PARSER_RESULT_READ_G(r, g, idx, i)                      GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 128, i, r)
#define RDD_PACKET_BUFFER_PARSER_RESULT_WRITE_G(v, g, idx, i)                     GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 128, i, v)
#define RDD_PACKET_BUFFER_PARSER_RESULT_READ(r, p, i)                             MREAD_I_8((uint8_t *)p + 128, i, r)
#define RDD_PACKET_BUFFER_PARSER_RESULT_WRITE(v, p, i)                            MWRITE_I_8((uint8_t *)p + 128, i, v)
#define RDD_PACKET_BUFFER_SCRATCH_READ_G(r, g, idx, i)                            GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 184, i, r)
#define RDD_PACKET_BUFFER_SCRATCH_WRITE_G(v, g, idx, i)                           GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 184, i, v)
#define RDD_PACKET_BUFFER_SCRATCH_READ(r, p, i)                                   MREAD_I_8((uint8_t *)p + 184, i, r)
#define RDD_PACKET_BUFFER_SCRATCH_WRITE(v, p, i)                                  MWRITE_I_8((uint8_t *)p + 184, i, v)
#define RDD_PACKET_BUFFER_PD_READ_G(r, g, idx, i)                                 GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 320, i, r)
#define RDD_PACKET_BUFFER_PD_WRITE_G(v, g, idx, i)                                GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 320, i, v)
#define RDD_PACKET_BUFFER_PD_READ(r, p, i)                                        MREAD_I_8((uint8_t *)p + 320, i, r)
#define RDD_PACKET_BUFFER_PD_WRITE(v, p, i)                                       MWRITE_I_8((uint8_t *)p + 320, i, v)
#define RDD_PACKET_BUFFER_RESOLUTION_CONTEXT_READ_G(r, g, idx, i)                 GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 336, i, r)
#define RDD_PACKET_BUFFER_RESOLUTION_CONTEXT_WRITE_G(v, g, idx, i)                GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 336, i, v)
#define RDD_PACKET_BUFFER_RESOLUTION_CONTEXT_READ(r, p, i)                        MREAD_I_8((uint8_t *)p + 336, i, r)
#define RDD_PACKET_BUFFER_RESOLUTION_CONTEXT_WRITE(v, p, i)                       MWRITE_I_8((uint8_t *)p + 336, i, v)
#define RDD_PACKET_BUFFER_CLASSIFICATION_RESULTS_READ_G(r, g, idx, i)             GROUP_MREAD_I_32(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 352, i, r)
#define RDD_PACKET_BUFFER_CLASSIFICATION_RESULTS_WRITE_G(v, g, idx, i)            GROUP_MWRITE_I_32(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 352, i, v)
#define RDD_PACKET_BUFFER_CLASSIFICATION_RESULTS_READ(r, p, i)                    MREAD_I_32((uint8_t *)p + 352, i, r)
#define RDD_PACKET_BUFFER_CLASSIFICATION_RESULTS_WRITE(v, p, i)                   MWRITE_I_32((uint8_t *)p + 352, i, v)
#define RDD_PACKET_BUFFER_CLASSIFICATION_CONTEXTS_LIST_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 384, i, r)
#define RDD_PACKET_BUFFER_CLASSIFICATION_CONTEXTS_LIST_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_DTS) + 384, i, v)
#define RDD_PACKET_BUFFER_CLASSIFICATION_CONTEXTS_LIST_READ(r, p, i)              MREAD_I_8((uint8_t *)p + 384, i, r)
#define RDD_PACKET_BUFFER_CLASSIFICATION_CONTEXTS_LIST_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p + 384, i, v)

#define RDD_DS_PACKET_BUFFER_SIZE     8
typedef struct
{
	RDD_PACKET_BUFFER_DTS	entry[ RDD_DS_PACKET_BUFFER_SIZE ];
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_DS_PACKET_BUFFER_DTS;

extern uint32_t RDD_DS_PACKET_BUFFER_ADDRESS_ARR[GROUPED_EN_SEGMENTS_NUM];

#define RDD_DS_PACKET_BUFFER_PTR(core_id)	( RDD_DS_PACKET_BUFFER_DTS * )(DEVICE_ADDRESS( rdp_runner_core_addr[core_id] + RDD_DS_PACKET_BUFFER_ADDRESS_ARR[core_id] ))

/* CORE_5 */
/* CORE_6 */
/* CORE_7 */
/* CORE_8 */
/* CORE_9 */
/* CORE_10 */
/* CORE_11 */
/* CORE_12 */
/* CORE_13 */
/* CORE_14 */
/* CORE_15 */

#ifdef G9991
typedef enum
{
	DISP_REOR_VIQ_FIRST             = 0,
	DISP_REOR_VIQ_BBH_RX0_NORMAL    = 0,
	DISP_REOR_VIQ_BBH_RX1_NORMAL    = 1,
	DISP_REOR_VIQ_BBH_RX2_NORMAL    = 2,
	DISP_REOR_VIQ_BBH_RX3_NORMAL    = 3,
	DISP_REOR_VIQ_BBH_RX4_NORMAL    = 4,
	DISP_REOR_VIQ_BBH_RX5_NORMAL    = 5,
	DISP_REOR_VIQ_BBH_RX6_NORMAL    = 6,
	DISP_REOR_VIQ_BBH_RX7_NORMAL    = 7,
	DISP_REOR_VIQ_BBH_RX8_NORMAL    = 8,
	DISP_REOR_VIQ_BBH_RX0_EXCL      = 9,
	DISP_REOR_VIQ_BBH_RX1_EXCL      = 10,
	DISP_REOR_VIQ_BBH_RX2_EXCL      = 11,
	DISP_REOR_VIQ_BBH_RX3_EXCL      = 12,
	DISP_REOR_VIQ_BBH_RX4_EXCL      = 13,
	DISP_REOR_VIQ_BBH_RX5_EXCL      = 14,
	DISP_REOR_VIQ_BBH_RX6_EXCL      = 15,
	DISP_REOR_VIQ_BBH_RX7_EXCL      = 16,
	DISP_REOR_VIQ_BBH_RX8_EXCL      = 17,
	DISP_REOR_VIQ_EPON_TM           = 18,
	DISP_REOR_VIQ_CPU_TX_EGRESS     = 19,
	DISP_REOR_VIQ_CPU_TX_FORWARD    = 20,
	DISP_REOR_VIQ_US_TM_FLUSH       = 21,
	DISP_REOR_VIQ_DS_TM_FLUSH       = 22,
	DISP_REOR_VIQ_TX_MIRRORING      = 23,
	DISP_REOR_VIQ_G9991_REASS0      = 24,
	DISP_REOR_VIQ_G9991_REASS1      = 25,
	DISP_REOR_VIQ_G9991_REASS2      = 26,
	DISP_REOR_VIQ_G9991_REASS3      = 27,
	DISP_REOR_VIQ_CPU_RX_COPY       = 28,
	DISP_REOR_VIQ_LAST              = 28
} rdd_disp_reor_viq;
typedef enum
{
	IMAGE_0_DS_TM_TIMER_INDEX_FIRST       = 0,
	IMAGE_0_DS_TM_TIMER_INDEX_FLUSH       = 0,
	IMAGE_0_DS_TM_TIMER_INDEX_BUDGET_ALLOCATOR = 2,
	IMAGE_0_DS_TM_TIMER_INDEX_LAST        = 2
} rdd_ds_tm_timer_index;
typedef enum
{
	IMAGE_2_CPU_IF_2_TIMER_INDEX_FIRST                    = 0,
	IMAGE_2_CPU_IF_2_TIMER_INDEX_REPORTING                = 0,
	IMAGE_2_CPU_IF_2_TIMER_INDEX_CPU_RX_METER_BUDGET_ALLOCATOR = 1,
	IMAGE_2_CPU_IF_2_TIMER_INDEX_INTERRUPT_COALESCING     = 2,
	IMAGE_2_CPU_IF_2_TIMER_INDEX_LAST                     = 2
} rdd_cpu_if_2_timer_index;
typedef enum
{
	IMAGE_3_US_TM_TIMER_INDEX_FIRST           = 0,
	IMAGE_3_US_TM_TIMER_INDEX_FLUSH           = 0,
	IMAGE_3_US_TM_TIMER_INDEX_OVL_BUDGET_ALLOCATOR = 1,
	IMAGE_3_US_TM_TIMER_INDEX_BUDGET_ALLOCATOR = 2,
	IMAGE_3_US_TM_TIMER_INDEX_LAST            = 2
} rdd_us_tm_timer_index;
typedef enum
{
	GENERAL_COUNTER_FIRST             = 0,
	GENERAL_COUNTER_WAN_CRC_ERR_ID    = 0,
	GENERAL_COUNTER_LAST              = 0
} rdd_general_counter;
typedef enum
{
	QM_QUEUE_FIRST                    = 0,
	QM_QUEUE_US_START                 = 0,
	QM_QUEUE_US_EPON_START            = 64,
	QM_QUEUE_US_END                   = 95,
	QM_QUEUE_DS_START                 = 96,
	QM_QUEUE_DS_END                   = 255,
	QM_QUEUE_CPU_RX                   = 256,
	QM_QUEUE_CPU_TX_EGRESS            = 257,
	QM_QUEUE_CPU_TX_INGRESS           = 258,
	QM_QUEUE_DROP                     = 259,
	QM_QUEUE_CPU_RX_COPY_EXCLUSIVE    = 260,
	QM_QUEUE_CPU_RX_COPY_NORMAL       = 261,
	QM_QUEUE_LAST                     = 261
} rdd_qm_queue;
typedef enum
{
	IMAGE_0_DS_TM_FIRST                      = 0,
	IMAGE_0_DS_TM_FLOW_CONTROL_THREAD_NUMBER = 0,
	IMAGE_0_DS_TM_BUDGET_ALLOCATION_THREAD_NUMBER = 1,
	IMAGE_0_DS_TM_UPDATE_FIFO_THREAD_NUMBER  = 2,
	IMAGE_0_DS_TM_FLUSH_THREAD_NUMBER        = 3,
	IMAGE_0_DS_TM_SCHEDULING_TASK_THREAD_NUMBER = 4,
	IMAGE_0_DS_TM_FRAG0_THREAD_NUMBER        = 5,
	IMAGE_0_DS_TM_FRAG1_THREAD_NUMBER        = 6,
	IMAGE_0_DS_TM_FRAG2_THREAD_NUMBER        = 7,
	IMAGE_0_DS_TM_FRAG3_THREAD_NUMBER        = 8,
	IMAGE_0_DS_TM_LAST                       = 8
} rdd_ds_tm;
typedef enum
{
	IMAGE_1_REASSEMBLY_FIRST            = 0,
	IMAGE_1_REASSEMBLY_G9991_0_THREAD_NUMBER = 0,
	IMAGE_1_REASSEMBLY_G9991_1_THREAD_NUMBER = 1,
	IMAGE_1_REASSEMBLY_G9991_2_THREAD_NUMBER = 2,
	IMAGE_1_REASSEMBLY_G9991_3_THREAD_NUMBER = 3,
	IMAGE_1_REASSEMBLY_LAST             = 3
} rdd_reassembly;
typedef enum
{
	IMAGE_2_CPU_IF_2_FIRST                                  = 0,
	IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_EGRESS_THREAD_NUMBER = 0,
	IMAGE_2_CPU_IF_2_CPU_TX_UPDATE_FIFO_INGRESS_THREAD_NUMBER = 1,
	IMAGE_2_CPU_IF_2_CPU_TX_EGRESS_THREAD_NUMBER            = 2,
	IMAGE_2_CPU_IF_2_CPU_TX_INGRESS_THREAD_NUMBER           = 3,
	IMAGE_2_CPU_IF_2_REPORTING_THREAD_NUMBER                = 4,
	IMAGE_2_CPU_IF_2_WAN_DIRECT_THREAD_NUMBER               = 5,
	IMAGE_2_CPU_IF_2_CPU_RX_THREAD_NUMBER                   = 6,
	IMAGE_2_CPU_IF_2_DIRECT_SYSTEM_PORT_THREAD_NUMBER       = 7,
	IMAGE_2_CPU_IF_2_CPU_RX_UPDATE_FIFO_THREAD_NUMBER       = 8,
	IMAGE_2_CPU_IF_2_CPU_TX_RECYCLE_THREAD_NUMBER           = 9,
	IMAGE_2_CPU_IF_2_INTERRUPT_COALESCING_THREAD_NUMBER     = 10,
	IMAGE_2_CPU_IF_2_CPU_RX_METER_BUDGET_ALLOCATOR_THREAD_NUMBER = 11,
	IMAGE_2_CPU_IF_2_CPU_RECYCLE_THREAD_NUMBER              = 12,
	IMAGE_2_CPU_IF_2_CPU_RX_COPY_THREAD_NUMBER              = 13,
	IMAGE_2_CPU_IF_2_CPU_RX_COPY_UPDATE_FIFO_THREAD_NUMBER  = 14,
	IMAGE_2_CPU_IF_2_LAST                                   = 14
} rdd_cpu_if_2;
typedef enum
{
	IMAGE_3_US_TM_FIRST                          = 0,
	IMAGE_3_US_TM_BUDGET_ALLOCATION_THREAD_NUMBER = 0,
	IMAGE_3_US_TM_OVL_BUDGET_ALLOCATION_THREAD_NUMBER = 1,
	IMAGE_3_US_TM_UPDATE_FIFO_THREAD_NUMBER      = 2,
	IMAGE_3_US_TM_UPDATE_FIFO_EPON_THREAD_NUMBER = 3,
	IMAGE_3_US_TM_FLUSH_THREAD_NUMBER            = 4,
	IMAGE_3_US_TM_WAN_THREAD_NUMBER              = 8,
	IMAGE_3_US_TM_WAN_EPON_THREAD_NUMBER         = 9,
	IMAGE_3_US_TM_LAST                           = 9
} rdd_us_tm;
typedef enum
{
	IMAGE_4_PROCESSING_FIRST      = 0,
	IMAGE_4_PROCESSING_0_THREAD_NUMBER = 0,
	IMAGE_4_PROCESSING_1_THREAD_NUMBER = 1,
	IMAGE_4_PROCESSING_2_THREAD_NUMBER = 2,
	IMAGE_4_PROCESSING_3_THREAD_NUMBER = 3,
	IMAGE_4_PROCESSING_4_THREAD_NUMBER = 4,
	IMAGE_4_PROCESSING_5_THREAD_NUMBER = 5,
	IMAGE_4_PROCESSING_6_THREAD_NUMBER = 6,
	IMAGE_4_PROCESSING_7_THREAD_NUMBER = 7,
	IMAGE_4_PROCESSING_LAST       = 7
} rdd_processing;
typedef enum
{
	GLOBAL_CFG_REG_FIRST        = 0,
	GLOBAL_CFG_REG_IS_6858A0    = 0,
	GLOBAL_CFG_REG_LAST         = 0
} rdd_global_cfg_reg;
typedef enum
{
	HASH_TABLE_FIRST                  = 1,
	HASH_TABLE_IPTV                   = 1,
	HASH_TABLE_ARL                    = 2,
	HASH_TABLE_BRIDGE_AND_VLAN_LKP    = 3,
	HASH_TABLE_LAST                   = 3
} rdd_hash_table;
typedef enum
{
	NATC_FIRST                     = 3,
	NATC_LOOKUP_DEPTH_SIZE_LOG2    = 3,
	NATC_LOOKUP_DEPTH_SIZE         = 8,
	NATC_MAX_TABLES_NUM            = 8,
	NATC_TABLE_KEY_SIZE            = 16,
	NATC_TABLE_RES_SIZE            = 64,
	NATC_MAX_ENTRY_LEN             = 128,
	NATC_LAST                      = 128
} rdd_natc;
typedef enum
{
	CLASSIFICATION_RESULT_INDEX_FIRST              = 0,
	CLASSIFICATION_RESULT_INDEX_TUNNELS_PARSING    = 0,
	CLASSIFICATION_RESULT_INDEX_INGRESS_FILTERS    = 1,
	CLASSIFICATION_RESULT_INDEX_NAT_CACHE          = 2,
	CLASSIFICATION_RESULT_INDEX_TCAM_IC_FLOW       = 3,
	CLASSIFICATION_RESULT_INDEX_TCAM_IC_ACL        = 4,
	CLASSIFICATION_RESULT_INDEX_TCAM_IC_QOS        = 5,
	CLASSIFICATION_RESULT_INDEX_IPTV               = 6,
	CLASSIFICATION_RESULT_INDEX_BRIDGE             = 7,
	CLASSIFICATION_RESULT_INDEX_LAST               = 7
} rdd_classification_result_index;
typedef enum
{
	ACTION_ID_FIRST               = 0,
	ACTION_ID_TRAP                = 0,
	ACTION_ID_TTL                 = 2,
	ACTION_ID_DSCP                = 4,
	ACTION_ID_NAT_DS              = 5,
	ACTION_ID_GRE                 = 6,
	ACTION_ID_OPBITS_DS           = 7,
	ACTION_ID_IPBITS_DS           = 8,
	ACTION_ID_PPPOE               = 9,
	ACTION_ID_NAT_US              = 10,
	ACTION_ID_OPBITS_US           = 11,
	ACTION_ID_IPBITS_US           = 12,
	ACTION_ID_DS_LITE             = 13,
	ACTION_ID_DEFAULT             = 14,
	ACTION_ID_GRE_TUNNEL          = 14,
	ACTION_ID_LLC_SNAP_SET_LEN    = 15,
	ACTION_ID_TOTAL_NUM           = 17,
	ACTION_ID_LAST                = 17
} rdd_action_id;
typedef enum
{
	RULE_BASED_ACTION_VECTOR_FIRST               = 0,
	RULE_BASED_ACTION_VECTOR_DEI                 = 0,
	RULE_BASED_ACTION_VECTOR_NO_FWD              = 1,
	RULE_BASED_ACTION_VECTOR_DSCP_REMARK         = 2,
	RULE_BASED_ACTION_VECTOR_VLAN_ACTION         = 3,
	RULE_BASED_ACTION_VECTOR_PBIT_REMARK         = 4,
	RULE_BASED_ACTION_VECTOR_PBIT_TO_QUEUE_DS    = 5,
	RULE_BASED_ACTION_VECTOR_TC_TO_QUEUE_DS      = 6,
	RULE_BASED_ACTION_VECTOR_PBIT_TO_GEM         = 7,
	RULE_BASED_ACTION_VECTOR_PBIT_TO_QUEUE_US    = 8,
	RULE_BASED_ACTION_VECTOR_TC_TO_QUEUE_US      = 9,
	RULE_BASED_ACTION_VECTOR_BRIDGE_DS           = 10,
	RULE_BASED_ACTION_VECTOR_DROP_PRECEDENCE     = 11,
	RULE_BASED_ACTION_VECTOR_LAST                = 11
} rdd_rule_based_action_vector;
typedef enum
{
	CPU_IF_RDD_FIRST      = 0,
	CPU_IF_RDD_DATA       = 0,
	CPU_IF_RDD_RECYCLE    = 1,
	CPU_IF_RDD_FEED       = 2,
	CPU_IF_RDD_LAST       = 2
} rdd_cpu_if_rdd;
typedef enum
{
	TM_UPDATE_VECTOR_FIRST              = 0,
	TM_UPDATE_VECTOR_BS_DWRR_Q          = 0,
	TM_UPDATE_VECTOR_CS_DWRR_Q          = 1,
	TM_UPDATE_VECTOR_CS_DWRR_BS         = 2,
	TM_UPDATE_VECTOR_BS_Q_BRL           = 3,
	TM_UPDATE_VECTOR_CS_BS_Q_BRL        = 4,
	TM_UPDATE_VECTOR_CS_Q_CRL_SIR       = 5,
	TM_UPDATE_VECTOR_CS_Q_CRL_PIR       = 6,
	TM_UPDATE_VECTOR_BS_BRL_Q           = 7,
	TM_UPDATE_VECTOR_CS_BS_CRL_SIR_Q    = 8,
	TM_UPDATE_VECTOR_CS_BS_CRL_PIR_Q    = 9,
	TM_UPDATE_VECTOR_CS_BRL             = 10,
	TM_UPDATE_VECTOR_OVL_RL             = 11,
	TM_UPDATE_VECTOR_LAST               = 11
} rdd_tm_update_vector;
typedef enum
{
	CNPL_GROUP_FIRST                   = 0,
	CNPL_GROUP_RX_FLOW                 = 0,
	CNPL_GROUP_RX_FLOW_DROP            = 1,
	CNPL_GROUP_TX_FLOW                 = 2,
	CNPL_GROUP_IPTV_TCAM_DEF           = 3,
	CNPL_GROUP_VARIOUS                 = 4,
	CNPL_GROUP_GENERAL                 = 5,
	CNPL_GROUP_US_TX_QUEUE             = 6,
	CNPL_GROUP_DS_TX_QUEUE             = 7,
	CNPL_GROUP_CPU_IF                  = 8,
	CNPL_GROUP_CPU_RX_METER_DROP       = 9,
	CNPL_GROUP_POLICER_GREEN_COLOR     = 10,
	CNPL_GROUP_POLICER_YELLOW_COLOR    = 11,
	CNPL_GROUP_POLICER_RED_COLOR       = 12,
	CNPL_GROUP_LAST                    = 12
} rdd_cnpl_group;
typedef enum
{
	COUNTER_CPU_GROUP_FIRST              = 0,
	COUNTER_CPU_GROUP_SPINLOCK_FEED      = 0,
	COUNTER_CPU_GROUP_READ_PTR_FEED      = 1,
	COUNTER_CPU_GROUP_SPINLOCK_DHD_0     = 2,
	COUNTER_CPU_GROUP_SPINLOCK_DHD_1     = 3,
	COUNTER_CPU_GROUP_SPINLOCK_DHD_2     = 4,
	COUNTER_CPU_GROUP_WRITE_PTR_DHD_0    = 5,
	COUNTER_CPU_GROUP_WRITE_PTR_DHD_1    = 6,
	COUNTER_CPU_GROUP_WRITE_PTR_DHD_2    = 7,
	COUNTER_CPU_GROUP_LAST               = 7
} rdd_counter_cpu_group;
typedef enum
{
	COUNTER_FIRST                                   = 0,
	COUNTER_TM_PD_NOT_VALID_ID                      = 0,
	COUNTER_TM_ACTION_NOT_VALID_ID                  = 1,
	COUNTER_EPON_TM_PD_NOT_VALID_ID                 = 2,
	COUNTER_G9991_TM_PD_NOT_VALID_ID                = 3,
	COUNTER_PROCESSING_ACTION_NOT_VALID_ID          = 4,
	COUNTER_CPU_RECYCLE_RING_CONGESTION             = 5,
	COUNTER_CPU_RX_FEED_RING_CONGESTION             = 6,
	COUNTER_CPU_RX_PSRAM_DROP                       = 7,
	COUNTER_IPTV_HASH_LKP_MISS_DROP                 = 8,
	COUNTER_IPTV_SIP_VID_LKP_MISS_DROP              = 9,
	COUNTER_IPTV_INVALID_CTX_ENTRY_DROP             = 10,
	COUNTER_IPTV_FPM_ALLOC_NACK_DROP                = 11,
	COUNTER_IPTV_FIRST_REPL_DISP_ALLOC_NACK_DROP    = 12,
	COUNTER_IPTV_EXCEPTION_DROP                     = 13,
	COUNTER_IPTV_OTHER_REPL_DISP_ALLOC_NACK_DROP    = 14,
	COUNTER_CPU_TX_COPY_NO_FPM                      = 15,
	COUNTER_CPU_TX_COPY_NO_SBPM                     = 16,
	COUNTER_CPU_RX_TC_TO_RXQ_MAP_DROP               = 17,
	COUNTER_CPU_RX_VPORT_TO_CPU_OBJ_MAP_DROP        = 18,
	COUNTER_ETHERNET_FLOW_DROP_ACTION               = 19,
	COUNTER_SBPM_ALLOC_EXCEPTION_DROP               = 20,
	COUNTER_DROP_CONNECTION_ACTION_DROP_ID          = 21,
	COUNTER_DROP_RESOURCE_CONGESTION                = 22,
	COUNTER_INGRESS_FILTER_DROP_FIRST_DS            = 23,
	COUNTER_INGRESS_FILTER_DROP_FIRST_US            = 44,
	COUNTER_INGRESS_FILTER_DROP_LAST                = 64,
	COUNTER_CPU_RX_METER_DROP                       = 65,
	COUNTER_INGRESS_ISOLATION_DROP                  = 66,
	COUNTER_EGRESS_ISOLATION_DROP                   = 67,
	COUNTER_DA_LKP_MISS_DROP                        = 68,
	COUNTER_SA_LKP_MISS_DROP                        = 69,
	COUNTER_BRIDGE_FW_ELIGABILITY_DROP              = 70,
	COUNTER_DA_LKP_MATCH_DROP                       = 71,
	COUNTER_SA_LKP_MATCH_DROP                       = 72,
	COUNTER_DROP_DISABLED_QUEUE                     = 73,
	COUNTER_DROP_DISABLED_TX_FLOW                   = 74,
	COUNTER_CPU_FEED_RING_DISP_CONGESTION           = 75,
	COUNTER_SBPM_LIB_DISP_CONG                      = 76,
	COUNTER_LAST_NON_DHD                            = 77,
	COUNTER_CPU_MCAST_SBPM_ALLOC                    = 77,
	COUNTER_DHD_RX_DROP_0                           = 78,
	COUNTER_DHD_RX_DROP_1                           = 79,
	COUNTER_DHD_RX_DROP_2                           = 80,
	COUNTER_DHD_TX_FPM_USED_0                       = 81,
	COUNTER_DHD_TX_FPM_USED_1                       = 82,
	COUNTER_DHD_TX_FPM_USED_2                       = 83,
	COUNTER_DHD_TX_DROP_0_SSID_0                    = 84,
	COUNTER_DHD_TX_DROP_1_SSID_0                    = 100,
	COUNTER_DHD_TX_DROP_2_SSID_0                    = 116,
	COUNTER_DHD_TX_FR_FULL_0_AC_0                   = 132,
	COUNTER_DHD_TX_FR_FULL_1_AC_0                   = 137,
	COUNTER_DHD_TX_FR_FULL_2_AC_0                   = 142,
	COUNTER_LAST                                    = 142
} rdd_counter;
typedef enum
{
	FLOW_DEST_FIRST      = 0,
	FLOW_DEST_ETH_ID     = 0,
	FLOW_DEST_IPTV_ID    = 1,
	FLOW_DEST_LAST       = 1
} rdd_flow_dest;
typedef enum
{
	ACTION_FIRST        = 0,
	ACTION_FORWARD      = 0,
	ACTION_TRAP         = 1,
	ACTION_DROP         = 2,
	ACTION_MULTICAST    = 3,
	ACTION_LAST         = 3
} rdd_action;
typedef enum
{
	LAYER3_IPV6_HEADER_FIRST            = 8,
	LAYER3_IPV6_HEADER_SRC_IP_OFFSET    = 8,
	LAYER3_IPV6_HEADER_DST_IP_OFFSET    = 24,
	LAYER3_IPV6_HEADER_LAST             = 24
} rdd_layer3_ipv6_header;
typedef enum
{
	LAYER3_HEADER_FIRST                  = 0,
	LAYER3_HEADER_TRAFIC_CLASS_OFFSET    = 0,
	LAYER3_HEADER_TOS_OFFSET             = 1,
	LAYER3_HEADER_FLAGS_OFFSET           = 6,
	LAYER3_HEADER_HOP_LIMIT_OFFSET       = 7,
	LAYER3_HEADER_TTL_OFFSET             = 8,
	LAYER3_HEADER_PROTOCOL_OFFSET        = 9,
	LAYER3_HEADER_IP_CHECKSUM_OFFSET     = 10,
	LAYER3_HEADER_SRC_IP_OFFSET          = 12,
	LAYER3_HEADER_DST_IP_OFFSET          = 16,
	LAYER3_HEADER_LAST                   = 16
} rdd_layer3_header;
typedef enum
{
	LAYER4_HEADER_FIRST                  = 0,
	LAYER4_HEADER_SRC_PORT_OFFSET        = 0,
	LAYER4_HEADER_ESP_SPI_OFFSET         = 0,
	LAYER4_HEADER_DST_PORT_OFFSET        = 2,
	LAYER4_HEADER_UDP_CHECKSUM_OFFSET    = 6,
	LAYER4_HEADER_GRE_CALL_ID_OFFSET     = 6,
	LAYER4_HEADER_TCP_FLAGS_OFFSET       = 13,
	LAYER4_HEADER_TCP_CHECKSUM_OFFSET    = 16,
	LAYER4_HEADER_LAST                   = 16
} rdd_layer4_header;
typedef enum
{
	PARSER_L2_PROTOCOL_FIRST             = 1,
	PARSER_L2_PROTOCOL_PPPOE_D           = 1,
	PARSER_L2_PROTOCOL_PPPOE_S           = 2,
	PARSER_L2_PROTOCOL_USER_DEFINED_0    = 8,
	PARSER_L2_PROTOCOL_USER_DEFINED_1    = 9,
	PARSER_L2_PROTOCOL_USER_DEFINED_2    = 10,
	PARSER_L2_PROTOCOL_USER_DEFINED_3    = 11,
	PARSER_L2_PROTOCOL_ARP               = 12,
	PARSER_L2_PROTOCOL__1588             = 13,
	PARSER_L2_PROTOCOL__802_1X           = 14,
	PARSER_L2_PROTOCOL_MASK              = 15,
	PARSER_L2_PROTOCOL__802_1AG_CFM      = 15,
	PARSER_L2_PROTOCOL_LAST              = 15
} rdd_parser_l2_protocol;
typedef enum
{
	PARSER_L3_PROTOCOL_FIRST    = 0,
	PARSER_L3_PROTOCOL_OTHER    = 0,
	PARSER_L3_PROTOCOL_IPV4     = 1,
	PARSER_L3_PROTOCOL_IPV6     = 2,
	PARSER_L3_PROTOCOL_MASK     = 3,
	PARSER_L3_PROTOCOL_LAST     = 3
} rdd_parser_l3_protocol;
typedef enum
{
	PARSER_L4_PROTOCOL_FIRST             = 0,
	PARSER_L4_PROTOCOL_OTHER             = 0,
	PARSER_L4_PROTOCOL_TCP               = 1,
	PARSER_L4_PROTOCOL_UDP               = 2,
	PARSER_L4_PROTOCOL_IGMP              = 3,
	PARSER_L4_PROTOCOL_ICMP              = 4,
	PARSER_L4_PROTOCOL_ICMPV6            = 5,
	PARSER_L4_PROTOCOL_ESP               = 6,
	PARSER_L4_PROTOCOL_GRE               = 7,
	PARSER_L4_PROTOCOL_USER_DEFINED_0    = 8,
	PARSER_L4_PROTOCOL_USER_DEFINED_1    = 9,
	PARSER_L4_PROTOCOL_USER_DEFINED_2    = 10,
	PARSER_L4_PROTOCOL_USER_DEFINED_3    = 11,
	PARSER_L4_PROTOCOL_RESERVED          = 12,
	PARSER_L4_PROTOCOL_IPV6              = 13,
	PARSER_L4_PROTOCOL_AH                = 14,
	PARSER_L4_PROTOCOL_NOT_PARSED        = 15,
	PARSER_L4_PROTOCOL_MASK              = 15,
	PARSER_L4_PROTOCOL_LAST              = 15
} rdd_parser_l4_protocol;
typedef enum
{
	ACTION_ECN_FIRST               = 0,
	ACTION_ECN_REMARKING_OFFSET    = 0,
	ACTION_ECN_REMARKING_WIDTH     = 2,
	ACTION_ECN_LAST                = 2
} rdd_action_ecn;
typedef enum
{
	ACTION_DSCP_FIRST                             = 2,
	ACTION_DSCP_REMARKING_OFFSET                  = 2,
	ACTION_DSCP_REMARKING_TRAFFIC_CLASS_OFFSET    = 4,
	ACTION_DSCP_REMARKING_WIDTH                   = 6,
	ACTION_DSCP_REMARKING_TRAFFIC_CLASS_WIDTH     = 8,
	ACTION_DSCP_LAST                              = 8
} rdd_action_dscp;
typedef enum
{
	ACTION_OUTER_FIRST                         = 14,
	ACTION_OUTER_PBITS_REMARKING_VID_OFFSET    = 14,
	ACTION_OUTER_LAST                          = 14
} rdd_action_outer;
typedef enum
{
	ACTION_INNER_FIRST                         = 18,
	ACTION_INNER_PBITS_REMARKING_VID_OFFSET    = 18,
	ACTION_INNER_LAST                          = 18
} rdd_action_inner;
typedef enum
{
	ACTION_PBITS_FIRST                      = 2,
	ACTION_PBITS_REMARKING_DSCP_OFFSET      = 2,
	ACTION_PBITS_REMARKING_PACKET_WIDTH     = 3,
	ACTION_PBITS_REMARKING_DSCP_WIDTH       = 6,
	ACTION_PBITS_REMARKING_PACKET_OFFSET    = 13,
	ACTION_PBITS_LAST                       = 13
} rdd_action_pbits;
typedef enum
{
	ACTION_DS_LITE_FIRST   = 40,
	ACTION_DS_LITE_SIZE    = 40,
	ACTION_DS_LITE_LAST    = 40
} rdd_action_ds_lite;
typedef enum
{
	DS_ACTION_ID_FIRST        = 0,
	DS_ACTION_ID_TRAP         = 0,
	DS_ACTION_ID_TTL          = 2,
	DS_ACTION_ID_DSCP         = 4,
	DS_ACTION_ID_NAT          = 5,
	DS_ACTION_ID_GRE          = 6,
	DS_ACTION_ID_OPBITS       = 7,
	DS_ACTION_ID_IPBITS       = 8,
	DS_ACTION_ID_DS_LITE      = 9,
	DS_ACTION_ID_PPPOE        = 10,
	DS_ACTION_ID_TOTAL_NUM    = 17,
	DS_ACTION_ID_LAST         = 17
} rdd_ds_action_id;
typedef enum
{
	US_ACTION_ID_FIRST        = 0,
	US_ACTION_ID_TRAP         = 0,
	US_ACTION_ID_TTL          = 2,
	US_ACTION_ID_DSCP         = 4,
	US_ACTION_ID_NAT          = 5,
	US_ACTION_ID_GRE          = 6,
	US_ACTION_ID_OPBITS       = 7,
	US_ACTION_ID_IPBITS       = 8,
	US_ACTION_ID_DS_LITE      = 9,
	US_ACTION_ID_PPPOE        = 10,
	US_ACTION_ID_TOTAL_NUM    = 17,
	US_ACTION_ID_LAST         = 17
} rdd_us_action_id;
typedef enum
{
	RDD_VPORT_FIRST    = 0,
	RDD_VPORT_ID_0     = 0,
	RDD_VPORT_ID_1     = 1,
	RDD_VPORT_ID_2     = 2,
	RDD_VPORT_ID_3     = 3,
	RDD_VPORT_ID_4     = 4,
	RDD_VPORT_ID_5     = 5,
	RDD_VPORT_ID_6     = 6,
	RDD_VPORT_ID_7     = 7,
	RDD_VPORT_ID_8     = 8,
	RDD_VPORT_ID_9     = 9,
	RDD_VPORT_ID_10    = 10,
	RDD_VPORT_ID_11    = 11,
	RDD_VPORT_ID_12    = 12,
	RDD_VPORT_ID_13    = 13,
	RDD_VPORT_ID_14    = 14,
	RDD_VPORT_ID_15    = 15,
	RDD_VPORT_ID_16    = 16,
	RDD_VPORT_ID_17    = 17,
	RDD_VPORT_ID_18    = 18,
	RDD_VPORT_ID_19    = 19,
	RDD_VPORT_ID_20    = 20,
	RDD_VPORT_ID_21    = 21,
	RDD_VPORT_ID_22    = 22,
	RDD_VPORT_ID_23    = 23,
	RDD_VPORT_ID_24    = 24,
	RDD_VPORT_ID_25    = 25,
	RDD_VPORT_ID_26    = 26,
	RDD_VPORT_ID_27    = 27,
	RDD_VPORT_ID_28    = 28,
	RDD_VPORT_ID_29    = 29,
	RDD_VPORT_ID_30    = 30,
	RDD_VPORT_ID_31    = 31,
	RDD_VPORT_ID_32    = 32,
	RDD_VPORT_ID_33    = 33,
	RDD_VPORT_ID_34    = 34,
	RDD_VPORT_ID_35    = 35,
	RDD_VPORT_ID_36    = 36,
	RDD_VPORT_ID_37    = 37,
	RDD_VPORT_ID_38    = 38,
	RDD_VPORT_ID_39    = 39,
	RDD_VPORT_ID_40    = 40,
	RDD_VPORT_LAST     = 40
} rdd_rdd_vport;
typedef enum
{
	DSCP_TO_FIRST                 = 6,
	DSCP_TO_PBITS_SHIFT_OFFSET    = 6,
	DSCP_TO_LAST                  = 6
} rdd_dscp_to;
typedef enum
{
	RESOLUTION_CONTEXT_FIRST                          = 0,
	RESOLUTION_CONTEXT_VIRTUAL_SRC_PORT_OFFSET        = 0,
	RESOLUTION_CONTEXT_GPE_DMA_OFFSET_WIDTH           = 1,
	RESOLUTION_CONTEXT_GPE_HEADER_LENGTH_WIDTH        = 1,
	RESOLUTION_CONTEXT_GPE_HEADER_IH_PTR_WIDTH        = 2,
	RESOLUTION_CONTEXT_GPE_COMMAND_LIST_PTR_WIDTH     = 2,
	RESOLUTION_CONTEXT_GPE_PACKET_DRR_PTR_WIDTH       = 4,
	RESOLUTION_CONTEXT_GPE_HEADER_LENGTH_OFFSET       = 6,
	RESOLUTION_CONTEXT_GPE_DMA_OFFSET_OFFSET          = 7,
	RESOLUTION_CONTEXT_GPE_COMMAND_LIST_PTR_OFFSET    = 8,
	RESOLUTION_CONTEXT_GPE_HEADER_IH_PTR_OFFSET       = 10,
	RESOLUTION_CONTEXT_GPE_PACKET_DRR_PTR_OFFSET      = 12,
	RESOLUTION_CONTEXT_LAST                           = 12
} rdd_resolution_context;
typedef enum
{
	CPU_RX_REASON_FIRST                 = 0,
	CPU_RX_REASON_OAM                   = 0,
	CPU_RX_REASON_PLOAM                 = 0,
	CPU_RX_REASON_OMCI                  = 1,
	CPU_RX_REASON_MPCP                  = 1,
	CPU_RX_REASON_FLOW                  = 2,
	CPU_RX_REASON_MULTICAST             = 3,
	CPU_RX_REASON_BROADCAST             = 4,
	CPU_RX_REASON_IGMP                  = 5,
	CPU_RX_REASON_ICMPV6                = 6,
	CPU_RX_REASON_MAC_TRAP_0            = 7,
	CPU_RX_REASON_MAC_TRAP_1            = 8,
	CPU_RX_REASON_MAC_TRAP_2            = 9,
	CPU_RX_REASON_MAC_TRAP_3            = 10,
	CPU_RX_REASON_DHCP                  = 11,
	CPU_RX_REASON_NON_TCP_UDP           = 12,
	CPU_RX_REASON_LOCAL_IP              = 13,
	CPU_RX_REASON_IP_HEADER_ERROR       = 14,
	CPU_RX_REASON_SA_MOVE               = 15,
	CPU_RX_REASON_UNKNOWN_SA            = 16,
	CPU_RX_REASON_UNKNOWN_DA            = 17,
	CPU_RX_REASON_IP_FRAGMENT           = 18,
	CPU_RX_REASON_MAC_SPOOFING          = 19,
	CPU_RX_REASON_DIRECT_QUEUE_0        = 20,
	CPU_RX_REASON_DIRECT_QUEUE_1        = 21,
	CPU_RX_REASON_DIRECT_QUEUE_2        = 22,
	CPU_RX_REASON_DIRECT_QUEUE_3        = 23,
	CPU_RX_REASON_DIRECT_QUEUE_4        = 24,
	CPU_RX_REASON_DIRECT_QUEUE_5        = 25,
	CPU_RX_REASON_DIRECT_QUEUE_6        = 26,
	CPU_RX_REASON_DIRECT_QUEUE_7        = 27,
	CPU_RX_REASON_ETYPE_UDEF_0          = 28,
	CPU_RX_REASON_ETYPE_UDEF_1          = 29,
	CPU_RX_REASON_ETYPE_UDEF_2          = 30,
	CPU_RX_REASON_ETYPE_UDEF_3          = 31,
	CPU_RX_REASON_ETYPE_PPPOE_D         = 32,
	CPU_RX_REASON_ETYPE_PPPOE_S         = 33,
	CPU_RX_REASON_ETYPE_ARP             = 34,
	CPU_RX_REASON__1588                 = 35,
	CPU_RX_REASON_ETYPE_802_1X          = 36,
	CPU_RX_REASON_ETYPE_801_1AG_CFM     = 37,
	CPU_RX_REASON_PCI_IP_FLOW_MISS_1    = 38,
	CPU_RX_REASON_PCI_IP_FLOW_MISS_2    = 39,
	CPU_RX_REASON_PCI_IP_FLOW_MISS_3    = 40,
	CPU_RX_REASON_IP_FLOW_MISS          = 41,
	CPU_RX_REASON_TCP_FLAGS             = 42,
	CPU_RX_REASON_TTL_EXPIRED           = 43,
	CPU_RX_REASON_MTU_EXCEEDED          = 44,
	CPU_RX_REASON_L4_ICMP               = 45,
	CPU_RX_REASON_L4_ESP                = 46,
	CPU_RX_REASON_L4_GRE                = 47,
	CPU_RX_REASON_L4_AH                 = 48,
	CPU_RX_REASON_PARSER_ERROR          = 49,
	CPU_RX_REASON_L4_IPV6               = 50,
	CPU_RX_REASON_L4_UDEF_0             = 51,
	CPU_RX_REASON_L4_UDEF_1             = 52,
	CPU_RX_REASON_L4_UDEF_2             = 53,
	CPU_RX_REASON_L4_UDEF_3             = 54,
	CPU_RX_REASON_WIFI                  = 55,
	CPU_RX_REASON_UDEF_0                = 56,
	CPU_RX_REASON_UDEF_1                = 57,
	CPU_RX_REASON_UDEF_2                = 58,
	CPU_RX_REASON_UDEF_3                = 59,
	CPU_RX_REASON_UDEF_4                = 60,
	CPU_RX_REASON_UDEF_5                = 61,
	CPU_RX_REASON_UDEF_6                = 62,
	CPU_RX_REASON_UDEF_7                = 63,
	CPU_RX_REASON_INGRESS_ISOLATION     = 64,
	CPU_RX_REASON_LAST                  = 64
} rdd_cpu_rx_reason;
typedef enum
{
	CPU_RX_METER_FIRST      = 0,
	CPU_RX_METER_ID_0       = 0,
	CPU_RX_METER_ID_1       = 1,
	CPU_RX_METER_ID_2       = 2,
	CPU_RX_METER_ID_3       = 3,
	CPU_RX_METER_ID_4       = 4,
	CPU_RX_METER_ID_5       = 5,
	CPU_RX_METER_ID_6       = 6,
	CPU_RX_METER_ID_7       = 7,
	CPU_RX_METER_ID_8       = 8,
	CPU_RX_METER_ID_9       = 9,
	CPU_RX_METER_ID_10      = 10,
	CPU_RX_METER_ID_11      = 11,
	CPU_RX_METER_ID_12      = 12,
	CPU_RX_METER_ID_13      = 13,
	CPU_RX_METER_ID_14      = 14,
	CPU_RX_METER_ID_15      = 15,
	CPU_RX_METER_DISABLE    = 255,
	CPU_RX_METER_LAST       = 255
} rdd_cpu_rx_meter;
typedef enum
{
	TCAM_IC_CMD_TYPE_FIRST             = 0,
	TCAM_IC_CMD_TYPE_PARSER_1          = 0,
	TCAM_IC_CMD_TYPE_PARSER_2          = 1,
	TCAM_IC_CMD_TYPE_PARSER_4          = 2,
	TCAM_IC_CMD_TYPE_PARSER_6          = 3,
	TCAM_IC_CMD_TYPE_PARSER_8          = 4,
	TCAM_IC_CMD_TYPE_PACKET            = 5,
	TCAM_IC_CMD_TYPE_L3                = 6,
	TCAM_IC_CMD_TYPE_L4                = 7,
	TCAM_IC_CMD_TYPE_INGRESS_PORT      = 8,
	TCAM_IC_CMD_TYPE_GEM_FLOW          = 9,
	TCAM_IC_CMD_TYPE_SOURCE_IP         = 10,
	TCAM_IC_CMD_TYPE_DESTINATION_IP    = 11,
	TCAM_IC_CMD_TYPE_LAST              = 11
} rdd_tcam_ic_cmd_type;
typedef enum
{
	TCAM_IC_MODULE_FIRST      = 0,
	TCAM_IC_MODULE_FLOW_DS    = 0,
	TCAM_IC_MODULE_FLOW_US    = 1,
	TCAM_IC_MODULE_ACL_US     = 2,
	TCAM_IC_MODULE_QOS_US     = 3,
	TCAM_IC_MODULE_QOS_DS     = 4,
	TCAM_IC_MODULE_LAST       = 4
} rdd_tcam_ic_module;
typedef enum
{
	TCAM_HIT_MISS_INVERT_FIRST     = 0,
	TCAM_HIT_MISS_INVERT_NONE      = 0,
	TCAM_HIT_MISS_INVERT_INVERT    = 2147483648,
	TCAM_HIT_MISS_INVERT_LAST      = 2147483648
} rdd_tcam_hit_miss_invert;
typedef enum
{
	BRIDGE_AND_VLAN_LKP_MISS_ACTION_FIRST      = 0,
	BRIDGE_AND_VLAN_LKP_MISS_ACTION_DROP       = 0,
	BRIDGE_AND_VLAN_LKP_MISS_ACTION_TRAP       = 1,
	BRIDGE_AND_VLAN_LKP_MISS_ACTION_FORWARD    = 2,
	BRIDGE_AND_VLAN_LKP_MISS_ACTION_LAST       = 2
} rdd_bridge_and_vlan_lkp_miss_action;
typedef enum
{
	BRIDGE_ARL_LOOKUP_METHOD_FIRST       = 0,
	BRIDGE_ARL_LOOKUP_METHOD_MAC_ONLY    = 0,
	BRIDGE_ARL_LOOKUP_METHOD_MAC_VID     = 1,
	BRIDGE_ARL_LOOKUP_METHOD_LAST        = 1
} rdd_bridge_arl_lookup_method;
typedef enum
{
	BRIDGE_AND_VLAN_CTX_LOOKUP_METHOD_FIRST         = 0,
	BRIDGE_AND_VLAN_CTX_LOOKUP_METHOD_VPORT_ONLY    = 0,
	BRIDGE_AND_VLAN_CTX_LOOKUP_METHOD_VPORT_VID     = 1,
	BRIDGE_AND_VLAN_CTX_LOOKUP_METHOD_LAST          = 1
} rdd_bridge_and_vlan_ctx_lookup_method;
typedef enum
{
	BRIDGE_FLOW_FIRST           = 0,
	BRIDGE_FLOW_LOCAL_SWITCH    = 0,
	BRIDGE_FLOW_US              = 1,
	BRIDGE_FLOW_DS              = 2,
	BRIDGE_FLOW_LAST            = 2
} rdd_bridge_flow;
typedef enum
{
	NO_FWD_ACTION_FIRST   = 0,
	NO_FWD_ACTION_DROP    = 0,
	NO_FWD_ACTION_TRAP    = 1,
	NO_FWD_ACTION_LAST    = 1
} rdd_no_fwd_action;
typedef enum
{
	INGRESS_FILTER_FIRST                = 0,
	INGRESS_FILTER_DHCP                 = 0,
	INGRESS_FILTER_ETYPE_PPPOE_D        = 1,
	INGRESS_FILTER_ETYPE_PPPOE_S        = 2,
	INGRESS_FILTER_IGMP                 = 3,
	INGRESS_FILTER_MLD                  = 4,
	INGRESS_FILTER_ICMPV6               = 5,
	INGRESS_FILTER_HDR_ERR              = 6,
	INGRESS_FILTER_IP_FRAGMENT          = 7,
	INGRESS_FILTER_ETYPE_UDEF_0         = 8,
	INGRESS_FILTER_ETYPE_UDEF_1         = 9,
	INGRESS_FILTER_ETYPE_UDEF_2         = 10,
	INGRESS_FILTER_ETYPE_UDEF_3         = 11,
	INGRESS_FILTER_ETYPE_ARP            = 12,
	INGRESS_FILTER_ETYPE_PTP_1588       = 13,
	INGRESS_FILTER_ETYPE_802_1X         = 14,
	INGRESS_FILTER_ETYPE_802_1AG_CFM    = 15,
	INGRESS_FILTER_MAC_SPOOFING         = 16,
	INGRESS_FILTER_IP_MCAST_CONTROL     = 17,
	INGRESS_FILTER_MCAST                = 18,
	INGRESS_FILTER_BCAST                = 19,
	INGRESS_FILTER_L4_PTP_1588          = 20,
	INGRESS_FILTER_LAST                 = 20
} rdd_ingress_filter;
typedef enum
{
	BBMSG_TYPE_FIRST                                              = 0,
	BBMSG_TYPE_QM_PD_FIFO_CREDIT_FREE                             = 0,
	BBMSG_TYPE_BBH_TX_PACKET_DESCRIPTOR                           = 1,
	BBMSG_TYPE_RUNNER_SBPM_BUFFER_ALLOC                           = 1,
	BBMSG_TYPE_QM_UPDATE_FIFO_CREDIT_FREE                         = 1,
	BBMSG_TYPE_FPM_BUFFER_ALLOC                                   = 1,
	BBMSG_TYPE_FPM_BUFFER_MCAST_INCREMENT                         = 2,
	BBMSG_TYPE_RUNNER_SBPM_MCAST_INC_REQUEST                      = 2,
	BBMSG_TYPE_BBH_TX_NACK                                        = 2,
	BBMSG_TYPE_BBH_TX_ACK                                         = 3,
	BBMSG_TYPE_FPM_BUFFER_FREE                                    = 3,
	BBMSG_TYPE_BBH_SBPM_BUFFER_FREE                               = 3,
	BBMSG_TYPE_BBH_GHOST_DBR                                      = 4,
	BBMSG_TYPE_RUNNER_SBPM_CONNECT                                = 4,
	BBMSG_TYPE_RUNNER_SBPM_GET_NEXT                               = 5,
	BBMSG_TYPE_BBH_TX_REPORT_ACK                                  = 5,
	BBMSG_TYPE_BBH_SBPM_BUFFER_FREE_WITHOUT_CONTEXT               = 6,
	BBMSG_TYPE_RUNNER_SBPM_BUFFER_FREE_WITHOUT_CONTEXT            = 6,
	BBMSG_TYPE_BBH_TX_REPORT_NACK                                 = 7,
	BBMSG_TYPE_RUNNER_SBPM_INGRESS_TO_EGRESS                      = 7,
	BBMSG_TYPE_RUNNER_REORDER_PD_WRITE                            = 8,
	BBMSG_TYPE_RUNNER_DISPATCHER_PD_ACK                           = 9,
	BBMSG_TYPE_RUNNER_DISPATCHER_PD_WRITE                         = 10,
	BBMSG_TYPE_RUNNER_REORDER_TOKEN_REQUEST                       = 11,
	BBMSG_TYPE_RUNNER_REORDER_BUFFER_CONNECT                      = 12,
	BBMSG_TYPE_RUNNER_DISPATCHER_WAKEUP_PENDING                   = 13,
	BBMSG_TYPE_RUNNER_REORDER_CONNECT_REQUEST_BUFFER_CONNECTED    = 14,
	BBMSG_TYPE_BBH_RX_DISPATCHER_PD_WRITE                         = 24,
	BBMSG_TYPE_LAST                                               = 24
} rdd_bbmsg_type;
typedef enum
{
	ERR_RX_PD_FIRST                 = 1,
	ERR_RX_PD_NO_SBPM               = 1,
	ERR_RX_PD_PACKET_TOO_SHORT      = 2,
	ERR_RX_PD_PACKET_TOO_LONG       = 3,
	ERR_RX_PD_CRC                   = 4,
	ERR_RX_PD_ENCRYPT               = 5,
	ERR_RX_PD_NO_SDMA_CHUNK         = 6,
	ERR_RX_PD_SOP_AFTER_SOP         = 7,
	ERR_RX_PD_THIRD_FLOW_ARRIVAL    = 8,
	ERR_RX_PD_LAST                  = 8
} rdd_err_rx_pd;
typedef enum
{
	SBPM_OPCODE_FIRST                   = 0,
	SBPM_OPCODE_MULTI_GET_NEXT          = 0,
	SBPM_OPCODE_BN_ALLOC                = 1,
	SBPM_OPCODE_MCST_INC                = 2,
	SBPM_OPCODE_BN_FREE_WITH_CONTEXT    = 3,
	SBPM_OPCODE_BN_CONNECT              = 4,
	SBPM_OPCODE_GET_NEXT                = 5,
	SBPM_OPCODE_BN_FREE_WO_CONTEXT      = 6,
	SBPM_OPCODE_INGRESS_TO_EGRESS       = 7,
	SBPM_OPCODE_LAST                    = 7
} rdd_sbpm_opcode;
typedef enum
{
	RDD_LAN_FIRST           = 1,
	RDD_LAN_BRIDGE_PORT0    = 1,
	RDD_LAN_BRIDGE_PORT1    = 2,
	RDD_LAN_BRIDGE_PORT2    = 3,
	RDD_LAN_BRIDGE_PORT3    = 4,
	RDD_LAN_BRIDGE_PORT4    = 5,
	RDD_LAN_BRIDGE_PORT5    = 6,
	RDD_LAN_LAST            = 6
} rdd_rdd_lan;
typedef enum
{
	MAC_TYPE_FIRST    = 0,
	MAC_TYPE_EMAC     = 0,
	MAC_TYPE_GPON     = 1,
	MAC_TYPE_XGPON    = 2,
	MAC_TYPE_EPON     = 3,
	MAC_TYPE_XEPON    = 4,
	MAC_TYPE_LAST     = 4
} rdd_mac_type;
typedef enum
{
	SBPM_FIRST                    = 16383,
	SBPM_INVALID_BUFFER_NUMBER    = 16383,
	SBPM_LAST                     = 16383
} rdd_sbpm;
typedef enum
{
	FPM_POOL_ID_FIRST            = 0,
	FPM_POOL_ID_EIGHT_BUFFERS    = 0,
	FPM_POOL_ID_FOUR_BUFFERS     = 1,
	FPM_POOL_ID_TWO_BUFFERS      = 2,
	FPM_POOL_ID_ONE_BUFFER       = 3,
	FPM_POOL_ID_LAST             = 3
} rdd_fpm_pool_id;
typedef enum
{
	RNR_FIRST        = 0,
	RNR_CORE0_ID     = 0,
	RNR_CORE1_ID     = 1,
	RNR_CORE2_ID     = 2,
	RNR_CORE3_ID     = 3,
	RNR_CORE4_ID     = 4,
	RNR_CORE5_ID     = 5,
	RNR_CORE6_ID     = 6,
	RNR_CORE7_ID     = 7,
	RNR_CORE8_ID     = 8,
	RNR_CORE9_ID     = 9,
	RNR_CORE10_ID    = 10,
	RNR_CORE11_ID    = 11,
	RNR_CORE12_ID    = 12,
	RNR_CORE13_ID    = 13,
	RNR_CORE14_ID    = 14,
	RNR_CORE15_ID    = 15,
	RNR_LAST         = 15
} rdd_rnr;
typedef enum
{
	BB_ID_FIRST                 = 0,
	BB_ID_RNR0                  = 0,
	BB_ID_RNR1                  = 1,
	BB_ID_RNR2                  = 2,
	BB_ID_RNR3                  = 3,
	BB_ID_RNR4                  = 4,
	BB_ID_RNR5                  = 5,
	BB_ID_RNR6                  = 6,
	BB_ID_RNR7                  = 7,
	BB_ID_RNR8                  = 8,
	BB_ID_RNR9                  = 9,
	BB_ID_RNR10                 = 10,
	BB_ID_RNR11                 = 11,
	BB_ID_RNR12                 = 12,
	BB_ID_RNR13                 = 13,
	BB_ID_RNR14                 = 14,
	BB_ID_RNR15                 = 15,
	BB_ID_BBHLB                 = 16,
	BB_ID_CNPL                  = 17,
	BB_ID_DISPATCHER_REORDER    = 18,
	BB_ID_DMA0                  = 19,
	BB_ID_DMA1                  = 20,
	BB_ID_SDMA0                 = 21,
	BB_ID_SDMA1                 = 22,
	BB_ID_FPM                   = 23,
	BB_ID_HASH                  = 24,
	BB_ID_NATC                  = 25,
	BB_ID_QM_CP_SDMA            = 26,
	BB_ID_QM_RNR_GRID           = 27,
	BB_ID_QM_BBHTX              = 28,
	BB_ID_QM_TOP                = 29,
	BB_ID_QM_CP_MACHINE         = 30,
	BB_ID_RX_XLMAC0_0_10G       = 31,
	BB_ID_TX_XLMAC0_0_10G       = 32,
	BB_ID_RX_XLMAC0_1_2P5G      = 33,
	BB_ID_TX_XLMAC0_1_2P5G      = 34,
	BB_ID_RX_XLMAC0_2_1G        = 35,
	BB_ID_TX_XLMAC0_2_1G        = 36,
	BB_ID_RX_XLMAC0_3_1G        = 37,
	BB_ID_TX_XLMAC0_3_1G        = 38,
	BB_ID_RX_XLMAC1_0_RGMII     = 39,
	BB_ID_TX_XLMAC1_0_RGMII     = 40,
	BB_ID_RX_XLMAC1_1_RGMII     = 41,
	BB_ID_TX_XLMAC1_1_RGMII     = 42,
	BB_ID_RX_XLMAC1_2_RGMII     = 43,
	BB_ID_TX_XLMAC1_2_RGMII     = 44,
	BB_ID_RX_PON_ETH            = 45,
	BB_ID_TX_PON_ETH_PD         = 46,
	BB_ID_TX_PON_ETH_STAT       = 47,
	BB_ID_SBPM                  = 48,
	BB_ID_TCAM_0                = 49,
	BB_ID_TCAM_1                = 50,
	BB_ID_RX_XLMAC1_3_RGMII     = 51,
	BB_ID_TX_XLMAC1_3_RGMII     = 52,
	BB_ID_LAST                  = 52
} rdd_bb_id;
typedef enum
{
	GPE_COMMAND_LIST_FIRST         = 0,
	GPE_COMMAND_LIST_TERMINATOR    = 0,
	GPE_COMMAND_LIST_LAST          = 0
} rdd_gpe_command_list;
typedef enum
{
	VLAN_ACTION_GPE_OPCODE_FIRST              = 0,
	VLAN_ACTION_GPE_OPCODE_DROP               = 0,
	VLAN_ACTION_GPE_OPCODE_DSCP               = 1,
	VLAN_ACTION_GPE_OPCODE_MAC_HDR_COPY       = 2,
	VLAN_ACTION_GPE_OPCODE_REPLACE_16         = 3,
	VLAN_ACTION_GPE_OPCODE_REPLACE_32         = 4,
	VLAN_ACTION_GPE_OPCODE_REPLACE_BITS_16    = 5,
	VLAN_ACTION_GPE_OPCODE_COPY_BITS_16       = 6,
	VLAN_ACTION_GPE_OPCODE_SKIP_IF            = 7,
	VLAN_ACTION_GPE_OPCODE_LAST               = 7
} rdd_vlan_action_gpe_opcode;
typedef enum
{
	VLAN_ACTION_TPID_VALUE_FIRST         = 0,
	VLAN_ACTION_TPID_VALUE_UNASSIGNED    = 0,
	VLAN_ACTION_TPID_VALUE_LAST          = 0
} rdd_vlan_action_tpid_value;
typedef enum
{
	VLAN_ACTION_CL_OFFSET_FIRST          = 0,
	VLAN_ACTION_CL_OFFSET_UNTAGGED       = 0,
	VLAN_ACTION_CL_OFFSET_1TAG           = 1,
	VLAN_ACTION_CL_OFFSET_2TAGS          = 2,
	VLAN_ACTION_CL_OFFSET_PTAG           = 3,
	VLAN_ACTION_CL_OFFSET_TRANSPARENT    = 255,
	VLAN_ACTION_CL_OFFSET_LAST           = 255
} rdd_vlan_action_cl_offset;
#endif


/* Hardware defines */
#define PACKET_BUFFER_SCRATCH_ENTRY_NATC_CFG_OFFSET                                0
#define RDD_PACKET_BUFFER_SCRATCH_ENTRY_NATC_CFG_NUMBER	8
#define RDD_PACKET_BUFFER_SCRATCH_ENTRY_RESERVED_NUMBER	128

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	natc_cfg[RDD_PACKET_BUFFER_SCRATCH_ENTRY_NATC_CFG_NUMBER];
	uint8_t	reserved[RDD_PACKET_BUFFER_SCRATCH_ENTRY_RESERVED_NUMBER];
#else
	uint8_t	natc_cfg[RDD_PACKET_BUFFER_SCRATCH_ENTRY_NATC_CFG_NUMBER];
	uint8_t	reserved[RDD_PACKET_BUFFER_SCRATCH_ENTRY_RESERVED_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PACKET_BUFFER_SCRATCH_ENTRY_DTS;

#define RDD_PACKET_BUFFER_SCRATCH_ENTRY_NATC_CFG_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_SCRATCH_ENTRY_DTS), i, r)
#define RDD_PACKET_BUFFER_SCRATCH_ENTRY_NATC_CFG_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_SCRATCH_ENTRY_DTS), i, v)
#define RDD_PACKET_BUFFER_SCRATCH_ENTRY_NATC_CFG_READ(r, p, i)              MREAD_I_8((uint8_t *)p, i, r)
#define RDD_PACKET_BUFFER_SCRATCH_ENTRY_NATC_CFG_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p, i, v)
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_F_OFFSET                     31
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_F_WIDTH                      1
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_OFFSET                       0
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_F_OFFSET_MOD8                7
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_F_OFFSET_MOD16               15
#define PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_F_OFFSET                                24
#define PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_F_WIDTH                                 1
#define PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_OFFSET                                  0
#define PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_F_OFFSET_MOD8                           0
#define PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_F_OFFSET_MOD16                          8
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_FLOW_F_OFFSET                               16
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_FLOW_F_WIDTH                                8
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_FLOW_OFFSET                                 1
#define PACKET_BUFFER_RESOLUTION_ENTRY_RX_FLOW_F_OFFSET_MOD16                         0
#define PACKET_BUFFER_RESOLUTION_ENTRY_G9991_BUFFER_F_OFFSET                          16
#define PACKET_BUFFER_RESOLUTION_ENTRY_G9991_BUFFER_F_WIDTH                           16
#define PACKET_BUFFER_RESOLUTION_ENTRY_G9991_BUFFER_OFFSET                            4
#define PACKET_BUFFER_RESOLUTION_ENTRY_TX_FLOW_F_OFFSET                               0
#define PACKET_BUFFER_RESOLUTION_ENTRY_TX_FLOW_F_WIDTH                                16
#define PACKET_BUFFER_RESOLUTION_ENTRY_TX_FLOW_OFFSET                                 6
#define PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_OFFSET                     8
#define PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_F_OFFSET_MOD16             8
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_NUMBER	8

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	rx_mirroring_flag                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_0                                                                           	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_lan                                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_flow                                                                              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_1                                                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_2                                                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_buffer                                                                         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_flow                                                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	per_flow_resolution[RDD_PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_NUMBER];
#else
	uint32_t	reserved_2                                                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_1                                                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_flow                                                                              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_lan                                                                               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_0                                                                           	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rx_mirroring_flag                                                                    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_flow                                                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	g9991_buffer                                                                         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	per_flow_resolution[RDD_PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS;

#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS), 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS), 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_RX_MIRRORING_FLAG_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS), 0, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS), 0, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_IS_LAN_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_RX_FLOW_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS) + 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_RX_FLOW_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS) + 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_RX_FLOW_READ(r, p)                             MREAD_8((uint8_t *)p + 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_RX_FLOW_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_G9991_BUFFER_READ_G(r, g, idx)                 GROUP_MREAD_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS) + 4, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_G9991_BUFFER_WRITE_G(v, g, idx)                GROUP_MWRITE_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS) + 4, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_G9991_BUFFER_READ(r, p)                        MREAD_16((uint8_t *)p + 4, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_G9991_BUFFER_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 4, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_TX_FLOW_READ_G(r, g, idx)                      GROUP_MREAD_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS) + 6, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_TX_FLOW_WRITE_G(v, g, idx)                     GROUP_MWRITE_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS) + 6, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_TX_FLOW_READ(r, p)                             MREAD_16((uint8_t *)p + 6, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_TX_FLOW_WRITE(v, p)                            MWRITE_16((uint8_t *)p + 6, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS) + 8, i, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_ENTRY_DTS) + 8, i, v)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_READ(r, p, i)              MREAD_I_8((uint8_t *)p + 8, i, r)
#define RDD_PACKET_BUFFER_RESOLUTION_ENTRY_PER_FLOW_RESOLUTION_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p + 8, i, v)
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_F_OFFSET                         31
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_F_WIDTH                          1
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_OFFSET                           0
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_F_OFFSET_MOD8                    7
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_F_OFFSET_MOD16                   15
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_F_OFFSET                         28
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_F_WIDTH                          3
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_OFFSET                           0
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_F_OFFSET_MOD8                    4
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_F_OFFSET_MOD16                   12
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_RESERVED_F_OFFSET                   16
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_RESERVED_F_WIDTH                    12
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_RESERVED_OFFSET                     0
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_RESERVED_F_OFFSET_MOD16             0
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_POLICER_DEI_F_OFFSET                           8
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_POLICER_DEI_F_WIDTH                            1
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_POLICER_DEI_OFFSET                             2
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_POLICER_DEI_F_OFFSET_MOD8                      0
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RULE2BRIDGE_RESOLUTION_F_OFFSET                16
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RULE2BRIDGE_RESOLUTION_F_WIDTH                 16
#define PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RULE2BRIDGE_RESOLUTION_OFFSET                  4
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RESERVED_4_NUMBER	2

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	egress_is_cpu                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_tc                                                              	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_reserved                                                        	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                  	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_dei                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                                  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rule2bridge_resolution                                                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = rule2bridge_resolution, size = 16 bits
	uint32_t	egress_port_resolved                                                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_egress_vport                                                        	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                                  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved7                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc_to_queue                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_to_queue                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_action                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	forw_mode                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc                                                                         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_precedence                                                            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_remark                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved6                                                                  	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint8_t	reserved_4[RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RESERVED_4_NUMBER];
#else
	uint32_t	reserved2                                                                  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_dei                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1                                                                  	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_reserved                                                        	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_tc                                                              	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_is_cpu                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved_4[RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RESERVED_4_NUMBER];
	uint32_t	rule2bridge_resolution                                                     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = rule2bridge_resolution, size = 16 bits
	uint32_t	egress_port_resolved                                                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_egress_vport                                                        	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                                                                  	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved7                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc_to_queue                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_to_queue                                                              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_action                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	forw_mode                                                                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc                                                                         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_precedence                                                            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_remark                                                                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved6                                                                  	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS;

#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS), 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS), 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_IS_CPU_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS), 4, 3, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS), 4, 3, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 4, 3, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_TC_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 4, 3, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_RESERVED_READ_G(r, g, idx)           GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS), 0, 12, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_RESERVED_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS), 0, 12, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_RESERVED_READ(r, p)                  FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_CPU_RESERVED_WRITE(v, p)                 FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_POLICER_DEI_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 2, 0, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_POLICER_DEI_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 2, 0, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_POLICER_DEI_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_POLICER_DEI_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RULE2BRIDGE_RESOLUTION_READ_G(r, g, idx)        GROUP_MREAD_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RULE2BRIDGE_RESOLUTION_WRITE_G(v, g, idx)       GROUP_MWRITE_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RULE2BRIDGE_RESOLUTION_READ(r, p)               MREAD_16((uint8_t *)p + 4, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_RULE2BRIDGE_RESOLUTION_WRITE(v, p)              MWRITE_16((uint8_t *)p + 4, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_PORT_RESOLVED_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_PORT_RESOLVED_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_PORT_RESOLVED_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_EGRESS_PORT_RESOLVED_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_BRIDGE_EGRESS_VPORT_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 0, 6, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_BRIDGE_EGRESS_VPORT_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 0, 6, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_BRIDGE_EGRESS_VPORT_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 4, 0, 6, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_BRIDGE_EGRESS_VPORT_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 4, 0, 6, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_TC_TO_QUEUE_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 6, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_TC_TO_QUEUE_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 6, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_TC_TO_QUEUE_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_TC_TO_QUEUE_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_PBIT_TO_QUEUE_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 5, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_PBIT_TO_QUEUE_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 5, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_PBIT_TO_QUEUE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 4, 5, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_PBIT_TO_QUEUE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 4, 5, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_VLAN_ACTION_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 4, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_VLAN_ACTION_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 4, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_VLAN_ACTION_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 4, 4, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_VLAN_ACTION_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 4, 4, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_FORW_MODE_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 3, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_FORW_MODE_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 3, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_FORW_MODE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 4, 3, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_FORW_MODE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 4, 3, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_TC_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 0, 3, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_TC_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 4, 0, 3, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_TC_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 4, 0, 3, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_TC_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 4, 0, 3, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DROP_PRECEDENCE_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 5, 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DROP_PRECEDENCE_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 5, 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DROP_PRECEDENCE_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 5, 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DROP_PRECEDENCE_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 5, 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_PBIT_REMARK_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 5, 6, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_PBIT_REMARK_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_DTS) + 5, 6, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_PBIT_REMARK_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 5, 6, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_UNICAST_ENTRY_PBIT_REMARK_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 5, 6, 1, v)
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_F_OFFSET                         31
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_F_WIDTH                          1
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_OFFSET                           0
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_F_OFFSET_MOD8                    7
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_F_OFFSET_MOD16                   15
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_F_OFFSET                         28
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_F_WIDTH                          3
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_OFFSET                           0
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_F_OFFSET_MOD8                    4
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_F_OFFSET_MOD16                   12
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_RESERVED_F_OFFSET                   16
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_RESERVED_F_WIDTH                    12
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_RESERVED_OFFSET                     0
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_RESERVED_F_OFFSET_MOD16             0
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_OFFSET                               4
#define PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_F_OFFSET_MOD16                       8
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_NUMBER	4

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	egress_is_cpu                                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_tc                                                         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_reserved                                                   	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved                                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	timestamp[RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_NUMBER];
#else
	uint32_t	reserved                                                              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_reserved                                                   	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_tc                                                         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_is_cpu                                                         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	timestamp[RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS;

#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS), 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS), 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_IS_CPU_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS), 4, 3, r)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS), 4, 3, v)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 4, 3, r)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_TC_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 4, 3, v)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_RESERVED_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS), 0, 12, r)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_RESERVED_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS), 0, 12, v)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_RESERVED_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_EGRESS_CPU_RESERVED_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_READ_G(r, g, idx, i)                 GROUP_MREAD_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS) + 4, i, r)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_WRITE_G(v, g, idx, i)                GROUP_MWRITE_I_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_DTS) + 4, i, v)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_READ(r, p, i)                        MREAD_I_8((uint8_t *)p + 4, i, r)
#define RDD_PACKET_BUFFER_RESOLUTION_1588_ENTRY_TIMESTAMP_WRITE(v, p, i)                       MWRITE_I_8((uint8_t *)p + 4, i, v)
#define FLOW_BASED_CONTEXT_FLOW_CACHE_OFFSET                              0
#define RDD_FLOW_BASED_CONTEXT_FLOW_CACHE_NUMBER	64
#define RDD_FLOW_BASED_CONTEXT_RESERVED_NUMBER	64

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	flow_cache[RDD_FLOW_BASED_CONTEXT_FLOW_CACHE_NUMBER];
	uint8_t	reserved[RDD_FLOW_BASED_CONTEXT_RESERVED_NUMBER];
#else
	uint8_t	flow_cache[RDD_FLOW_BASED_CONTEXT_FLOW_CACHE_NUMBER];
	uint8_t	reserved[RDD_FLOW_BASED_CONTEXT_RESERVED_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FLOW_BASED_CONTEXT_DTS;

#define RDD_FLOW_BASED_CONTEXT_FLOW_CACHE_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_FLOW_BASED_CONTEXT_DTS), i, r)
#define RDD_FLOW_BASED_CONTEXT_FLOW_CACHE_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_FLOW_BASED_CONTEXT_DTS), i, v)
#define RDD_FLOW_BASED_CONTEXT_FLOW_CACHE_READ(r, p, i)              MREAD_I_8((uint8_t *)p, i, r)
#define RDD_FLOW_BASED_CONTEXT_FLOW_CACHE_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p, i, v)
#define RULE_BASED_CONTEXT_TCAM_RESULT_OFFSET                             0
#define RULE_BASED_CONTEXT_NATC_KEY_OFFSET                                16
#define RULE_BASED_CONTEXT_NATC_KEY_F_OFFSET_MOD16                        8
#define RULE_BASED_CONTEXT_NATC_KEY_DATA_OFFSET                           24
#define RULE_BASED_CONTEXT_NATC_CONTEXT_OFFSET                            40
#define RULE_BASED_CONTEXT_TCAM_QOS_RESULT_OFFSET                         104
#define RDD_RULE_BASED_CONTEXT_TCAM_RESULT_NUMBER	16
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_NUMBER	8
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_DATA_NUMBER	16
#define RDD_RULE_BASED_CONTEXT_NATC_CONTEXT_NUMBER	64
#define RDD_RULE_BASED_CONTEXT_TCAM_QOS_RESULT_NUMBER	8
#define RDD_RULE_BASED_CONTEXT_RESERVED_NUMBER	16

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	tcam_result[RDD_RULE_BASED_CONTEXT_TCAM_RESULT_NUMBER];
	uint8_t	natc_key[RDD_RULE_BASED_CONTEXT_NATC_KEY_NUMBER];
	uint8_t	natc_key_data[RDD_RULE_BASED_CONTEXT_NATC_KEY_DATA_NUMBER];
	uint8_t	natc_context[RDD_RULE_BASED_CONTEXT_NATC_CONTEXT_NUMBER];
	uint8_t	tcam_qos_result[RDD_RULE_BASED_CONTEXT_TCAM_QOS_RESULT_NUMBER];
	uint8_t	reserved[RDD_RULE_BASED_CONTEXT_RESERVED_NUMBER];
#else
	uint8_t	tcam_result[RDD_RULE_BASED_CONTEXT_TCAM_RESULT_NUMBER];
	uint8_t	natc_key[RDD_RULE_BASED_CONTEXT_NATC_KEY_NUMBER];
	uint8_t	natc_key_data[RDD_RULE_BASED_CONTEXT_NATC_KEY_DATA_NUMBER];
	uint8_t	natc_context[RDD_RULE_BASED_CONTEXT_NATC_CONTEXT_NUMBER];
	uint8_t	tcam_qos_result[RDD_RULE_BASED_CONTEXT_TCAM_QOS_RESULT_NUMBER];
	uint8_t	reserved[RDD_RULE_BASED_CONTEXT_RESERVED_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RULE_BASED_CONTEXT_DTS;

#define RDD_RULE_BASED_CONTEXT_TCAM_RESULT_READ_G(r, g, idx, i)           GROUP_MREAD_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS), i, r)
#define RDD_RULE_BASED_CONTEXT_TCAM_RESULT_WRITE_G(v, g, idx, i)          GROUP_MWRITE_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS), i, v)
#define RDD_RULE_BASED_CONTEXT_TCAM_RESULT_READ(r, p, i)                  MREAD_I_8((uint8_t *)p, i, r)
#define RDD_RULE_BASED_CONTEXT_TCAM_RESULT_WRITE(v, p, i)                 MWRITE_I_8((uint8_t *)p, i, v)
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_READ_G(r, g, idx, i)              GROUP_MREAD_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS) + 16, i, r)
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_WRITE_G(v, g, idx, i)             GROUP_MWRITE_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS) + 16, i, v)
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_READ(r, p, i)                     MREAD_I_8((uint8_t *)p + 16, i, r)
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_WRITE(v, p, i)                    MWRITE_I_8((uint8_t *)p + 16, i, v)
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_DATA_READ_G(r, g, idx, i)         GROUP_MREAD_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS) + 24, i, r)
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_DATA_WRITE_G(v, g, idx, i)        GROUP_MWRITE_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS) + 24, i, v)
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_DATA_READ(r, p, i)                MREAD_I_8((uint8_t *)p + 24, i, r)
#define RDD_RULE_BASED_CONTEXT_NATC_KEY_DATA_WRITE(v, p, i)               MWRITE_I_8((uint8_t *)p + 24, i, v)
#define RDD_RULE_BASED_CONTEXT_NATC_CONTEXT_READ_G(r, g, idx, i)          GROUP_MREAD_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS) + 40, i, r)
#define RDD_RULE_BASED_CONTEXT_NATC_CONTEXT_WRITE_G(v, g, idx, i)         GROUP_MWRITE_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS) + 40, i, v)
#define RDD_RULE_BASED_CONTEXT_NATC_CONTEXT_READ(r, p, i)                 MREAD_I_8((uint8_t *)p + 40, i, r)
#define RDD_RULE_BASED_CONTEXT_NATC_CONTEXT_WRITE(v, p, i)                MWRITE_I_8((uint8_t *)p + 40, i, v)
#define RDD_RULE_BASED_CONTEXT_TCAM_QOS_RESULT_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS) + 104, i, r)
#define RDD_RULE_BASED_CONTEXT_TCAM_QOS_RESULT_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_DTS) + 104, i, v)
#define RDD_RULE_BASED_CONTEXT_TCAM_QOS_RESULT_READ(r, p, i)              MREAD_I_8((uint8_t *)p + 104, i, r)
#define RDD_RULE_BASED_CONTEXT_TCAM_QOS_RESULT_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p + 104, i, v)
#define RULE_BASED_NATC_CONTEXT_NATC_CONTROL_F_OFFSET                          0
#define RULE_BASED_NATC_CONTEXT_NATC_CONTROL_F_WIDTH                           32
#define RULE_BASED_NATC_CONTEXT_NATC_CONTROL_OFFSET                            0
#define RULE_BASED_NATC_CONTEXT_CMD_LIST_OFFSET                                12
#define RDD_RULE_BASED_NATC_CONTEXT_RESERVED0_NUMBER	8
#define RDD_RULE_BASED_NATC_CONTEXT_CMD_LIST_NUMBER	52
#define RDD_RULE_BASED_NATC_CONTEXT_RESERVED1_NUMBER	64

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	natc_control                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved0[RDD_RULE_BASED_NATC_CONTEXT_RESERVED0_NUMBER];
	uint8_t	cmd_list[RDD_RULE_BASED_NATC_CONTEXT_CMD_LIST_NUMBER];
	uint8_t	reserved1[RDD_RULE_BASED_NATC_CONTEXT_RESERVED1_NUMBER];
#else
	uint32_t	natc_control                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved0[RDD_RULE_BASED_NATC_CONTEXT_RESERVED0_NUMBER];
	uint8_t	cmd_list[RDD_RULE_BASED_NATC_CONTEXT_CMD_LIST_NUMBER];
	uint8_t	reserved1[RDD_RULE_BASED_NATC_CONTEXT_RESERVED1_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RULE_BASED_NATC_CONTEXT_DTS;

#define RDD_RULE_BASED_NATC_CONTEXT_NATC_CONTROL_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_DTS), r)
#define RDD_RULE_BASED_NATC_CONTEXT_NATC_CONTROL_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_DTS), v)
#define RDD_RULE_BASED_NATC_CONTEXT_NATC_CONTROL_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_RULE_BASED_NATC_CONTEXT_NATC_CONTROL_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_RULE_BASED_NATC_CONTEXT_CMD_LIST_READ_G(r, g, idx, i)           GROUP_MREAD_I_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_DTS) + 12, i, r)
#define RDD_RULE_BASED_NATC_CONTEXT_CMD_LIST_WRITE_G(v, g, idx, i)          GROUP_MWRITE_I_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_DTS) + 12, i, v)
#define RDD_RULE_BASED_NATC_CONTEXT_CMD_LIST_READ(r, p, i)                  MREAD_I_8((uint8_t *)p + 12, i, r)
#define RDD_RULE_BASED_NATC_CONTEXT_CMD_LIST_WRITE(v, p, i)                 MWRITE_I_8((uint8_t *)p + 12, i, v)
#define IPTV_CONTEXT_IPTV_CONTEXT_OFFSET                            0
#define RDD_IPTV_CONTEXT_IPTV_CONTEXT_NUMBER	32

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	iptv_context[RDD_IPTV_CONTEXT_IPTV_CONTEXT_NUMBER];
/* fields union = iptv_context, size = 32 bits
	uint8_t	natc_command[RDD_IPTV_CONTEXT_NATC_COMMAND_NUMBER];
	uint8_t	reserved[RDD_IPTV_CONTEXT_RESERVED_NUMBER];
	uint8_t	vlan_action_ctx[RDD_IPTV_CONTEXT_VLAN_ACTION_CTX_NUMBER];
	uint8_t	iptv_ctx[RDD_IPTV_CONTEXT_IPTV_CTX_NUMBER];
	uint8_t	reserved_2[RDD_IPTV_CONTEXT_RESERVED_2_NUMBER];
 end fields union*/
#else
	uint32_t	iptv_context[RDD_IPTV_CONTEXT_IPTV_CONTEXT_NUMBER];
/* fields union = iptv_context, size = 32 bits
	uint8_t	natc_command[RDD_IPTV_CONTEXT_NATC_COMMAND_NUMBER];
	uint8_t	reserved[RDD_IPTV_CONTEXT_RESERVED_NUMBER];
	uint8_t	vlan_action_ctx[RDD_IPTV_CONTEXT_VLAN_ACTION_CTX_NUMBER];
	uint8_t	iptv_ctx[RDD_IPTV_CONTEXT_IPTV_CTX_NUMBER];
	uint8_t	reserved_2[RDD_IPTV_CONTEXT_RESERVED_2_NUMBER];
 end fields union*/
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_CONTEXT_DTS;

#define RDD_IPTV_CONTEXT_IPTV_CONTEXT_READ_G(r, g, idx, i)          GROUP_MREAD_I_32(g, idx*sizeof(RDD_IPTV_CONTEXT_DTS), i, r)
#define RDD_IPTV_CONTEXT_IPTV_CONTEXT_WRITE_G(v, g, idx, i)         GROUP_MWRITE_I_32(g, idx*sizeof(RDD_IPTV_CONTEXT_DTS), i, v)
#define RDD_IPTV_CONTEXT_IPTV_CONTEXT_READ(r, p, i)                 MREAD_I_32((uint8_t *)p, i, r)
#define RDD_IPTV_CONTEXT_IPTV_CONTEXT_WRITE(v, p, i)                MWRITE_I_32((uint8_t *)p, i, v)
#define RDD_IPTV_CONTEXT_NATC_COMMAND_READ_G(r, g, idx, i)          GROUP_MREAD_I_8(g, idx*sizeof(RDD_IPTV_CONTEXT_DTS), i, r)
#define RDD_IPTV_CONTEXT_NATC_COMMAND_WRITE_G(v, g, idx, i)         GROUP_MWRITE_I_8(g, idx*sizeof(RDD_IPTV_CONTEXT_DTS), i, v)
#define RDD_IPTV_CONTEXT_NATC_COMMAND_READ(r, p, i)                 MREAD_I_8((uint8_t *)p, i, r)
#define RDD_IPTV_CONTEXT_NATC_COMMAND_WRITE(v, p, i)                MWRITE_I_8((uint8_t *)p, i, v)
#define RDD_IPTV_CONTEXT_VLAN_ACTION_CTX_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_IPTV_CONTEXT_DTS) + 64, i, r)
#define RDD_IPTV_CONTEXT_VLAN_ACTION_CTX_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_IPTV_CONTEXT_DTS) + 64, i, v)
#define RDD_IPTV_CONTEXT_VLAN_ACTION_CTX_READ(r, p, i)              MREAD_I_8((uint8_t *)p + 64, i, r)
#define RDD_IPTV_CONTEXT_VLAN_ACTION_CTX_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p + 64, i, v)
#define RDD_IPTV_CONTEXT_IPTV_CTX_READ_G(r, g, idx, i)              GROUP_MREAD_I_8(g, idx*sizeof(RDD_IPTV_CONTEXT_DTS), i, r)
#define RDD_IPTV_CONTEXT_IPTV_CTX_WRITE_G(v, g, idx, i)             GROUP_MWRITE_I_8(g, idx*sizeof(RDD_IPTV_CONTEXT_DTS), i, v)
#define RDD_IPTV_CONTEXT_IPTV_CTX_READ(r, p, i)                     MREAD_I_8((uint8_t *)p, i, r)
#define RDD_IPTV_CONTEXT_IPTV_CTX_WRITE(v, p, i)                    MWRITE_I_8((uint8_t *)p, i, v)
#define FLOW_CACHE_CONTEXT_ENTRY_NATC_CONTROL_F_OFFSET                          0
#define FLOW_CACHE_CONTEXT_ENTRY_NATC_CONTROL_F_WIDTH                           32
#define FLOW_CACHE_CONTEXT_ENTRY_NATC_CONTROL_OFFSET                            0
#define FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_F_OFFSET                            31
#define FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_F_WIDTH                             1
#define FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_OFFSET                              4
#define FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_F_OFFSET_MOD8                       7
#define FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_F_OFFSET_MOD16                      15
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_F_OFFSET         30
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_F_WIDTH          1
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_OFFSET           4
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_F_OFFSET_MOD8    6
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_F_OFFSET_MOD16   14
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_F_OFFSET                            27
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_F_WIDTH                             3
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_OFFSET                              4
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_F_OFFSET_MOD8                       3
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_F_OFFSET_MOD16                      11
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_F_OFFSET                         24
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_F_WIDTH                          3
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_OFFSET                           4
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_F_OFFSET_MOD8                    0
#define FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_F_OFFSET_MOD16                   8
#define FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_F_OFFSET                            18
#define FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_F_WIDTH                             6
#define FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_OFFSET                              5
#define FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_F_OFFSET_MOD8                       2
#define FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_F_OFFSET_MOD16                      2
#define FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_F_OFFSET                             16
#define FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_F_WIDTH                              2
#define FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_OFFSET                               5
#define FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_F_OFFSET_MOD8                        0
#define FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_F_OFFSET_MOD16                       0
#define FLOW_CACHE_CONTEXT_ENTRY_NAT_PORT_F_OFFSET                              0
#define FLOW_CACHE_CONTEXT_ENTRY_NAT_PORT_F_WIDTH                               16
#define FLOW_CACHE_CONTEXT_ENTRY_NAT_PORT_OFFSET                                6
#define FLOW_CACHE_CONTEXT_ENTRY_IP_CHECKSUM_DELTA_F_OFFSET                     16
#define FLOW_CACHE_CONTEXT_ENTRY_IP_CHECKSUM_DELTA_F_WIDTH                      16
#define FLOW_CACHE_CONTEXT_ENTRY_IP_CHECKSUM_DELTA_OFFSET                       8
#define FLOW_CACHE_CONTEXT_ENTRY_L4_CHECKSUM_DELTA_F_OFFSET                     0
#define FLOW_CACHE_CONTEXT_ENTRY_L4_CHECKSUM_DELTA_F_WIDTH                      16
#define FLOW_CACHE_CONTEXT_ENTRY_L4_CHECKSUM_DELTA_OFFSET                       10
#define FLOW_CACHE_CONTEXT_ENTRY_NAT_IP_F_OFFSET                                0
#define FLOW_CACHE_CONTEXT_ENTRY_NAT_IP_F_WIDTH                                 32
#define FLOW_CACHE_CONTEXT_ENTRY_NAT_IP_OFFSET                                  12
#define FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_F_OFFSET                  28
#define FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_F_WIDTH                   4
#define FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_OFFSET                    16
#define FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_F_OFFSET_MOD8             4
#define FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_F_OFFSET_MOD16            12
#define FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_F_OFFSET                            23
#define FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_F_WIDTH                             1
#define FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_OFFSET                              17
#define FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_F_OFFSET_MOD8                       7
#define FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_F_OFFSET_MOD16                      7
#define FLOW_CACHE_CONTEXT_ENTRY_SSID_F_OFFSET                                  19
#define FLOW_CACHE_CONTEXT_ENTRY_SSID_F_WIDTH                                   4
#define FLOW_CACHE_CONTEXT_ENTRY_SSID_OFFSET                                    17
#define FLOW_CACHE_CONTEXT_ENTRY_SSID_F_OFFSET_MOD8                             3
#define FLOW_CACHE_CONTEXT_ENTRY_SSID_F_OFFSET_MOD16                            3
#define FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_F_OFFSET                      18
#define FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_F_WIDTH                       1
#define FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_OFFSET                        17
#define FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_F_OFFSET_MOD8                 2
#define FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_F_OFFSET_MOD16                2
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_F_OFFSET                             16
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_F_WIDTH                              1
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_OFFSET                               17
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_F_OFFSET_MOD8                        0
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_F_OFFSET_MOD16                       0
#define FLOW_CACHE_CONTEXT_ENTRY_OUTER_VID_OFFSET_F_OFFSET                      13
#define FLOW_CACHE_CONTEXT_ENTRY_OUTER_VID_OFFSET_F_WIDTH                       3
#define FLOW_CACHE_CONTEXT_ENTRY_OUTER_VID_OFFSET_OFFSET                        18
#define FLOW_CACHE_CONTEXT_ENTRY_OUTER_VID_OFFSET_F_OFFSET_MOD8                 5
#define FLOW_CACHE_CONTEXT_ENTRY_POLICER_ID_F_OFFSET                            8
#define FLOW_CACHE_CONTEXT_ENTRY_POLICER_ID_F_WIDTH                             5
#define FLOW_CACHE_CONTEXT_ENTRY_POLICER_ID_OFFSET                              18
#define FLOW_CACHE_CONTEXT_ENTRY_POLICER_ID_F_OFFSET_MOD8                       0
#define FLOW_CACHE_CONTEXT_ENTRY_OVERFLOW_F_OFFSET                              7
#define FLOW_CACHE_CONTEXT_ENTRY_OVERFLOW_F_WIDTH                               1
#define FLOW_CACHE_CONTEXT_ENTRY_OVERFLOW_OFFSET                                19
#define FLOW_CACHE_CONTEXT_ENTRY_OUTER_PBIT_REMAP_ACTION_F_OFFSET               5
#define FLOW_CACHE_CONTEXT_ENTRY_OUTER_PBIT_REMAP_ACTION_F_WIDTH                2
#define FLOW_CACHE_CONTEXT_ENTRY_OUTER_PBIT_REMAP_ACTION_OFFSET                 19
#define FLOW_CACHE_CONTEXT_ENTRY_INNER_PBIT_REMAP_ACTION_F_OFFSET               3
#define FLOW_CACHE_CONTEXT_ENTRY_INNER_PBIT_REMAP_ACTION_F_WIDTH                2
#define FLOW_CACHE_CONTEXT_ENTRY_INNER_PBIT_REMAP_ACTION_OFFSET                 19
#define FLOW_CACHE_CONTEXT_ENTRY_IS_WFD_F_OFFSET                                2
#define FLOW_CACHE_CONTEXT_ENTRY_IS_WFD_F_WIDTH                                 1
#define FLOW_CACHE_CONTEXT_ENTRY_IS_WFD_OFFSET                                  19
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_NUMBER_OF_TAGS_F_OFFSET              0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_NUMBER_OF_TAGS_F_WIDTH               2
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_NUMBER_OF_TAGS_OFFSET                19
#define FLOW_CACHE_CONTEXT_ENTRY_L2_OFFSET_F_OFFSET                             24
#define FLOW_CACHE_CONTEXT_ENTRY_L2_OFFSET_F_WIDTH                              8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_OFFSET_OFFSET                               20
#define FLOW_CACHE_CONTEXT_ENTRY_L2_OFFSET_F_OFFSET_MOD16                       8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_SIZE_F_OFFSET                               16
#define FLOW_CACHE_CONTEXT_ENTRY_L2_SIZE_F_WIDTH                                8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_SIZE_OFFSET                                 21
#define FLOW_CACHE_CONTEXT_ENTRY_L2_SIZE_F_OFFSET_MOD16                         0
#define FLOW_CACHE_CONTEXT_ENTRY_ACTIONS_VECTOR_F_OFFSET                        0
#define FLOW_CACHE_CONTEXT_ENTRY_ACTIONS_VECTOR_F_WIDTH                         16
#define FLOW_CACHE_CONTEXT_ENTRY_ACTIONS_VECTOR_OFFSET                          22
#define FLOW_CACHE_CONTEXT_ENTRY_QUEUE_F_OFFSET                                 24
#define FLOW_CACHE_CONTEXT_ENTRY_QUEUE_F_WIDTH                                  8
#define FLOW_CACHE_CONTEXT_ENTRY_QUEUE_OFFSET                                   24
#define FLOW_CACHE_CONTEXT_ENTRY_QUEUE_F_OFFSET_MOD16                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_F_OFFSET                             8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_F_WIDTH                              8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_OFFSET                               26
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_1_F_OFFSET                           0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_1_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_1_OFFSET                             27
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_2_F_OFFSET                           24
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_2_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_2_OFFSET                             28
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_2_F_OFFSET_MOD16                     8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_3_F_OFFSET                           16
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_3_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_3_OFFSET                             29
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_3_F_OFFSET_MOD16                     0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_4_F_OFFSET                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_4_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_4_OFFSET                             30
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_5_F_OFFSET                           0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_5_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_5_OFFSET                             31
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_6_F_OFFSET                           24
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_6_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_6_OFFSET                             32
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_6_F_OFFSET_MOD16                     8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_7_F_OFFSET                           16
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_7_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_7_OFFSET                             33
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_7_F_OFFSET_MOD16                     0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_8_F_OFFSET                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_8_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_8_OFFSET                             34
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_9_F_OFFSET                           0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_9_F_WIDTH                            8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_9_OFFSET                             35
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_10_F_OFFSET                          24
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_10_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_10_OFFSET                            36
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_10_F_OFFSET_MOD16                    8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_11_F_OFFSET                          16
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_11_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_11_OFFSET                            37
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_11_F_OFFSET_MOD16                    0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_12_F_OFFSET                          8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_12_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_12_OFFSET                            38
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_13_F_OFFSET                          0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_13_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_13_OFFSET                            39
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_14_F_OFFSET                          24
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_14_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_14_OFFSET                            40
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_14_F_OFFSET_MOD16                    8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_15_F_OFFSET                          16
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_15_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_15_OFFSET                            41
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_15_F_OFFSET_MOD16                    0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_16_F_OFFSET                          8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_16_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_16_OFFSET                            42
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_17_F_OFFSET                          0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_17_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_17_OFFSET                            43
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_18_F_OFFSET                          24
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_18_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_18_OFFSET                            44
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_18_F_OFFSET_MOD16                    8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_19_F_OFFSET                          16
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_19_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_19_OFFSET                            45
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_19_F_OFFSET_MOD16                    0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_20_F_OFFSET                          8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_20_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_20_OFFSET                            46
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_21_F_OFFSET                          0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_21_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_21_OFFSET                            47
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_22_F_OFFSET                          24
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_22_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_22_OFFSET                            48
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_22_F_OFFSET_MOD16                    8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_23_F_OFFSET                          16
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_23_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_23_OFFSET                            49
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_23_F_OFFSET_MOD16                    0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_24_F_OFFSET                          8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_24_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_24_OFFSET                            50
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_25_F_OFFSET                          0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_25_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_25_OFFSET                            51
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_26_F_OFFSET                          24
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_26_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_26_OFFSET                            52
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_26_F_OFFSET_MOD16                    8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_27_F_OFFSET                          16
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_27_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_27_OFFSET                            53
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_27_F_OFFSET_MOD16                    0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_28_F_OFFSET                          8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_28_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_28_OFFSET                            54
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_29_F_OFFSET                          0
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_29_F_WIDTH                           8
#define FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_29_OFFSET                            55
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_F_OFFSET                   31
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_F_WIDTH                    1
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_OFFSET                     56
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_F_OFFSET_MOD8              7
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_F_OFFSET_MOD16             15
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_F_OFFSET                      30
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_F_WIDTH                       1
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_OFFSET                        56
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_F_OFFSET_MOD8                 6
#define FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_F_OFFSET_MOD16                14
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_PARAMS_UNION_F_OFFSET                      16
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_PARAMS_UNION_F_WIDTH                       14
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_PARAMS_UNION_OFFSET                        56
#define FLOW_CACHE_CONTEXT_ENTRY_CPU_PARAMS_UNION_F_OFFSET_MOD16                0
#define FLOW_CACHE_CONTEXT_ENTRY_EGRESS_CPU_VPORT_F_OFFSET                      15
#define FLOW_CACHE_CONTEXT_ENTRY_EGRESS_CPU_VPORT_F_WIDTH                       1
#define FLOW_CACHE_CONTEXT_ENTRY_EGRESS_CPU_VPORT_OFFSET                        58
#define FLOW_CACHE_CONTEXT_ENTRY_EGRESS_CPU_VPORT_F_OFFSET_MOD8                 7
#define FLOW_CACHE_CONTEXT_ENTRY_TC_F_OFFSET                                    12
#define FLOW_CACHE_CONTEXT_ENTRY_TC_F_WIDTH                                     3
#define FLOW_CACHE_CONTEXT_ENTRY_TC_OFFSET                                      58
#define FLOW_CACHE_CONTEXT_ENTRY_TC_F_OFFSET_MOD8                               4
#define FLOW_CACHE_CONTEXT_ENTRY_TO_LAN_F_OFFSET                                8
#define FLOW_CACHE_CONTEXT_ENTRY_TO_LAN_F_WIDTH                                 1
#define FLOW_CACHE_CONTEXT_ENTRY_TO_LAN_OFFSET                                  58
#define FLOW_CACHE_CONTEXT_ENTRY_TO_LAN_F_OFFSET_MOD8                           0
#define FLOW_CACHE_CONTEXT_ENTRY_TX_FLOW_F_OFFSET                               0
#define FLOW_CACHE_CONTEXT_ENTRY_TX_FLOW_F_WIDTH                                8
#define FLOW_CACHE_CONTEXT_ENTRY_TX_FLOW_OFFSET                                 59

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	natc_control            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fwd_action              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_mode_miss_union	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = service_queue_mode_miss_union, size = 1 bits
	uint32_t	service_queues_mode     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	trap_type               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	cpu_reason              	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue           	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_value              	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ecn_value               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	nat_port                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_checksum_delta       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l4_checksum_delta       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	nat_ip                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	physical_egress_port    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0               	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_version              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid                    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_mapping_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_queue               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_vid_offset        	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_id              	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overflow                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbit_remap_action 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbit_remap_action 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_wfd                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_number_of_tags	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_offset               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_size                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	actions_vector          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_1             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_2             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_3             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_4             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_5             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_6             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_7             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_8             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_9             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_10            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_11            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_12            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_13            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_14            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_15            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_16            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_17            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_18            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_19            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_20            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_21            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_22            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_23            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_24            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_25            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_26            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_27            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_28            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_29            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_eligibility_en     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_eligibility        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_params_union        	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = cpu_params_union, size = 14 bits
	uint32_t	metatada_0              	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_1              	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_priority           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id            	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	egress_cpu_vport        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc                      	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3               	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	to_lan                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_flow                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	natc_control            	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	nat_port                	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ecn_value               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_value              	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue           	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_reason              	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	service_queue_mode_miss_union	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = service_queue_mode_miss_union, size = 1 bits
	uint32_t	service_queues_mode     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	trap_type               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	fwd_action              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l4_checksum_delta       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_checksum_delta       	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	nat_ip                  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_number_of_tags	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_wfd                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_pbit_remap_action 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_pbit_remap_action 	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	overflow                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_id              	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_vid_offset        	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_queue               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	qos_mapping_mode        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid                    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_version              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0               	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	physical_egress_port    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	actions_vector          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_size                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_offset               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_1             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue                   	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_5             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_4             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_3             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_2             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_9             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_8             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_7             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_6             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_13            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_12            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_11            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_10            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_17            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_16            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_15            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_14            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_21            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_20            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_19            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_18            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_25            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_24            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_23            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_22            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_29            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_28            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_27            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l2_header_26            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tx_flow                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	to_lan                  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3               	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc                      	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_cpu_vport        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_params_union        	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = cpu_params_union, size = 14 bits
	uint32_t	metatada_0              	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_1              	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wifi_priority           	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_ring_id            	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	drop_eligibility        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop_eligibility_en     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS;

#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NATC_CONTROL_READ_G(r, g, idx)                      GROUP_MREAD_32(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS), r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NATC_CONTROL_WRITE_G(v, g, idx)                     GROUP_MWRITE_32(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS), v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NATC_CONTROL_READ(r, p)                             MREAD_32((uint8_t *)p, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NATC_CONTROL_WRITE(v, p)                            MWRITE_32((uint8_t *)p, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 4, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_FWD_ACTION_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 4, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_READ_G(r, g, idx)     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 6, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_WRITE_G(v, g, idx)    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 6, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_READ(r, p)            FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_MODE_MISS_UNION_WRITE(v, p)           FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUES_MODE_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 6, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUES_MODE_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 6, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUES_MODE_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUES_MODE_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TRAP_TYPE_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 6, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TRAP_TYPE_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 6, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TRAP_TYPE_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 4, 6, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TRAP_TYPE_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 4, 6, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 3, 3, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 3, 3, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 4, 3, 3, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_REASON_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 4, 3, 3, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 0, 3, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 4, 0, 3, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 4, 0, 3, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SERVICE_QUEUE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 4, 0, 3, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 5, 2, 6, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 5, 2, 6, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 5, 2, 6, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DSCP_VALUE_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 5, 2, 6, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 5, 0, 2, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 5, 0, 2, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 5, 0, 2, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_ECN_VALUE_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 5, 0, 2, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NAT_PORT_READ_G(r, g, idx)                          GROUP_MREAD_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 6, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NAT_PORT_WRITE_G(v, g, idx)                         GROUP_MWRITE_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 6, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NAT_PORT_READ(r, p)                                 MREAD_16((uint8_t *)p + 6, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NAT_PORT_WRITE(v, p)                                MWRITE_16((uint8_t *)p + 6, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IP_CHECKSUM_DELTA_READ_G(r, g, idx)                 GROUP_MREAD_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 8, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IP_CHECKSUM_DELTA_WRITE_G(v, g, idx)                GROUP_MWRITE_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 8, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IP_CHECKSUM_DELTA_READ(r, p)                        MREAD_16((uint8_t *)p + 8, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IP_CHECKSUM_DELTA_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 8, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L4_CHECKSUM_DELTA_READ_G(r, g, idx)                 GROUP_MREAD_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 10, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L4_CHECKSUM_DELTA_WRITE_G(v, g, idx)                GROUP_MWRITE_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 10, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L4_CHECKSUM_DELTA_READ(r, p)                        MREAD_16((uint8_t *)p + 10, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L4_CHECKSUM_DELTA_WRITE(v, p)                       MWRITE_16((uint8_t *)p + 10, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NAT_IP_READ_G(r, g, idx)                            GROUP_MREAD_32(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 12, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NAT_IP_WRITE_G(v, g, idx)                           GROUP_MWRITE_32(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 12, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NAT_IP_READ(r, p)                                   MREAD_32((uint8_t *)p + 12, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_NAT_IP_WRITE(v, p)                                  MWRITE_32((uint8_t *)p + 12, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 16, 4, 4, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 16, 4, 4, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 16, 4, 4, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_PHYSICAL_EGRESS_PORT_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 16, 4, 4, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 17, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 17, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 17, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IP_VERSION_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 17, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SSID_READ_G(r, g, idx)                              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 17, 3, 4, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SSID_WRITE_G(v, g, idx)                             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 17, 3, 4, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SSID_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 17, 3, 4, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_SSID_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 17, 3, 4, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 17, 2, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 17, 2, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 17, 2, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_QOS_MAPPING_MODE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 17, 2, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 17, 0, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 17, 0, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 17, 0, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_QUEUE_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 17, 0, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OUTER_VID_OFFSET_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 18, 5, 3, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OUTER_VID_OFFSET_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 18, 5, 3, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OUTER_VID_OFFSET_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 18, 5, 3, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OUTER_VID_OFFSET_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 18, 5, 3, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_POLICER_ID_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 18, 0, 5, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_POLICER_ID_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 18, 0, 5, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_POLICER_ID_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 18, 0, 5, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_POLICER_ID_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 18, 0, 5, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OVERFLOW_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OVERFLOW_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OVERFLOW_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 19, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OVERFLOW_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 19, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OUTER_PBIT_REMAP_ACTION_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 5, 2, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OUTER_PBIT_REMAP_ACTION_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 5, 2, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OUTER_PBIT_REMAP_ACTION_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 19, 5, 2, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_OUTER_PBIT_REMAP_ACTION_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 19, 5, 2, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_INNER_PBIT_REMAP_ACTION_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 3, 2, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_INNER_PBIT_REMAP_ACTION_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 3, 2, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_INNER_PBIT_REMAP_ACTION_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 19, 3, 2, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_INNER_PBIT_REMAP_ACTION_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 19, 3, 2, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IS_WFD_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 2, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IS_WFD_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 2, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IS_WFD_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 19, 2, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_IS_WFD_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 19, 2, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_NUMBER_OF_TAGS_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 0, 2, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_NUMBER_OF_TAGS_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 19, 0, 2, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_NUMBER_OF_TAGS_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 19, 0, 2, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_NUMBER_OF_TAGS_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 19, 0, 2, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_OFFSET_READ_G(r, g, idx)                         GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 20, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_OFFSET_WRITE_G(v, g, idx)                        GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 20, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_OFFSET_READ(r, p)                                MREAD_8((uint8_t *)p + 20, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_OFFSET_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 20, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_SIZE_READ_G(r, g, idx)                           GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 21, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_SIZE_WRITE_G(v, g, idx)                          GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 21, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_SIZE_READ(r, p)                                  MREAD_8((uint8_t *)p + 21, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_SIZE_WRITE(v, p)                                 MWRITE_8((uint8_t *)p + 21, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_ACTIONS_VECTOR_READ_G(r, g, idx)                    GROUP_MREAD_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 22, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_ACTIONS_VECTOR_WRITE_G(v, g, idx)                   GROUP_MWRITE_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 22, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_ACTIONS_VECTOR_READ(r, p)                           MREAD_16((uint8_t *)p + 22, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_ACTIONS_VECTOR_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 22, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_QUEUE_READ_G(r, g, idx)                             GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 24, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_QUEUE_WRITE_G(v, g, idx)                            GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 24, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_QUEUE_READ(r, p)                                    MREAD_8((uint8_t *)p + 24, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_QUEUE_WRITE(v, p)                                   MWRITE_8((uint8_t *)p + 24, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_READ_G(r, g, idx)                         GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 26, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_WRITE_G(v, g, idx)                        GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 26, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_READ(r, p)                                MREAD_8((uint8_t *)p + 26, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 26, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_1_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 27, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_1_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 27, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_1_READ(r, p)                              MREAD_8((uint8_t *)p + 27, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_1_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 27, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_2_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 28, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_2_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 28, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_2_READ(r, p)                              MREAD_8((uint8_t *)p + 28, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_2_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 28, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_3_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 29, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_3_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 29, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_3_READ(r, p)                              MREAD_8((uint8_t *)p + 29, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_3_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 29, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_4_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 30, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_4_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 30, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_4_READ(r, p)                              MREAD_8((uint8_t *)p + 30, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_4_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 30, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_5_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 31, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_5_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 31, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_5_READ(r, p)                              MREAD_8((uint8_t *)p + 31, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_5_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 31, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_6_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 32, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_6_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 32, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_6_READ(r, p)                              MREAD_8((uint8_t *)p + 32, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_6_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 32, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_7_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 33, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_7_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 33, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_7_READ(r, p)                              MREAD_8((uint8_t *)p + 33, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_7_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 33, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_8_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 34, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_8_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 34, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_8_READ(r, p)                              MREAD_8((uint8_t *)p + 34, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_8_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 34, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_9_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 35, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_9_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 35, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_9_READ(r, p)                              MREAD_8((uint8_t *)p + 35, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_9_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 35, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_10_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 36, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_10_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 36, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_10_READ(r, p)                             MREAD_8((uint8_t *)p + 36, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_10_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 36, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_11_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 37, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_11_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 37, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_11_READ(r, p)                             MREAD_8((uint8_t *)p + 37, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_11_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 37, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_12_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 38, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_12_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 38, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_12_READ(r, p)                             MREAD_8((uint8_t *)p + 38, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_12_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 38, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_13_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 39, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_13_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 39, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_13_READ(r, p)                             MREAD_8((uint8_t *)p + 39, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_13_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 39, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_14_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 40, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_14_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 40, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_14_READ(r, p)                             MREAD_8((uint8_t *)p + 40, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_14_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 40, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_15_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 41, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_15_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 41, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_15_READ(r, p)                             MREAD_8((uint8_t *)p + 41, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_15_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 41, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_16_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 42, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_16_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 42, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_16_READ(r, p)                             MREAD_8((uint8_t *)p + 42, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_16_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 42, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_17_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 43, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_17_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 43, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_17_READ(r, p)                             MREAD_8((uint8_t *)p + 43, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_17_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 43, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_18_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 44, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_18_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 44, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_18_READ(r, p)                             MREAD_8((uint8_t *)p + 44, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_18_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 44, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_19_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 45, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_19_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 45, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_19_READ(r, p)                             MREAD_8((uint8_t *)p + 45, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_19_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 45, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_20_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 46, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_20_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 46, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_20_READ(r, p)                             MREAD_8((uint8_t *)p + 46, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_20_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 46, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_21_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 47, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_21_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 47, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_21_READ(r, p)                             MREAD_8((uint8_t *)p + 47, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_21_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 47, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_22_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 48, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_22_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 48, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_22_READ(r, p)                             MREAD_8((uint8_t *)p + 48, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_22_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 48, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_23_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 49, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_23_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 49, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_23_READ(r, p)                             MREAD_8((uint8_t *)p + 49, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_23_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 49, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_24_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 50, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_24_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 50, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_24_READ(r, p)                             MREAD_8((uint8_t *)p + 50, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_24_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 50, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_25_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 51, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_25_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 51, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_25_READ(r, p)                             MREAD_8((uint8_t *)p + 51, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_25_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 51, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_26_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 52, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_26_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 52, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_26_READ(r, p)                             MREAD_8((uint8_t *)p + 52, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_26_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 52, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_27_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 53, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_27_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 53, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_27_READ(r, p)                             MREAD_8((uint8_t *)p + 53, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_27_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 53, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_28_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 54, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_28_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 54, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_28_READ(r, p)                             MREAD_8((uint8_t *)p + 54, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_28_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 54, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_29_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 55, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_29_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 55, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_29_READ(r, p)                             MREAD_8((uint8_t *)p + 55, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_L2_HEADER_29_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 55, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 56, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_EN_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 56, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 6, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 6, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 56, 6, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_DROP_ELIGIBILITY_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 56, 6, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_PARAMS_UNION_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 0, 14, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_PARAMS_UNION_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 0, 14, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_PARAMS_UNION_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p + 56, 0, 14, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_CPU_PARAMS_UNION_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p + 56, 0, 14, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_METATADA_0_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 2, 4, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_METATADA_0_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 2, 4, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_METATADA_0_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 56, 2, 4, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_METATADA_0_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 56, 2, 4, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_METADATA_1_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 0, 10, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_METADATA_1_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 0, 10, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_METADATA_1_READ(r, p)                               FIELD_MREAD_16((uint8_t *)p + 56, 0, 10, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_METADATA_1_WRITE(v, p)                              FIELD_MWRITE_16((uint8_t *)p + 56, 0, 10, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_WIFI_PRIORITY_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 2, 4, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_WIFI_PRIORITY_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 2, 4, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_WIFI_PRIORITY_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 56, 2, 4, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_WIFI_PRIORITY_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 56, 2, 4, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_FLOW_RING_ID_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 0, 10, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_FLOW_RING_ID_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 56, 0, 10, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_FLOW_RING_ID_READ(r, p)                             FIELD_MREAD_16((uint8_t *)p + 56, 0, 10, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_FLOW_RING_ID_WRITE(v, p)                            FIELD_MWRITE_16((uint8_t *)p + 56, 0, 10, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_EGRESS_CPU_VPORT_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 58, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_EGRESS_CPU_VPORT_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 58, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_EGRESS_CPU_VPORT_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 58, 7, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_EGRESS_CPU_VPORT_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 58, 7, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TC_READ_G(r, g, idx)                                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 58, 4, 3, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TC_WRITE_G(v, g, idx)                               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 58, 4, 3, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TC_READ(r, p)                                       FIELD_MREAD_8((uint8_t *)p + 58, 4, 3, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TC_WRITE(v, p)                                      FIELD_MWRITE_8((uint8_t *)p + 58, 4, 3, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TO_LAN_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 58, 0, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TO_LAN_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 58, 0, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TO_LAN_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 58, 0, 1, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TO_LAN_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 58, 0, 1, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TX_FLOW_READ_G(r, g, idx)                           GROUP_MREAD_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 59, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TX_FLOW_WRITE_G(v, g, idx)                          GROUP_MWRITE_8(g, idx*sizeof(RDD_FLOW_CACHE_CONTEXT_ENTRY_DTS) + 59, v)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TX_FLOW_READ(r, p)                                  MREAD_8((uint8_t *)p + 59, r)
#define RDD_FLOW_CACHE_CONTEXT_ENTRY_TX_FLOW_WRITE(v, p)                                 MWRITE_8((uint8_t *)p + 59, v)
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_F_OFFSET                           31
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_F_WIDTH                            1
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_OFFSET                             0
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_F_OFFSET_MOD8                      7
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_F_OFFSET_MOD16                     15
#define RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_F_OFFSET                               30
#define RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_F_WIDTH                                1
#define RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_OFFSET                                 0
#define RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_F_OFFSET_MOD8                          6
#define RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_F_OFFSET_MOD16                         14
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_F_OFFSET                             29
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_F_WIDTH                              1
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_OFFSET                               0
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_F_OFFSET_MOD8                        5
#define RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_F_OFFSET_MOD16                       13
#define RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_F_OFFSET                           28
#define RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_F_WIDTH                            1
#define RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_OFFSET                             0
#define RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_F_OFFSET_MOD8                      4
#define RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_F_OFFSET_MOD16                     12
#define RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_F_OFFSET                           27
#define RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_F_WIDTH                            1
#define RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_OFFSET                             0
#define RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_F_OFFSET_MOD8                      3
#define RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_F_OFFSET_MOD16                     11
#define RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_F_OFFSET                           26
#define RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_F_WIDTH                            1
#define RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_OFFSET                             0
#define RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_F_OFFSET_MOD8                      2
#define RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_F_OFFSET_MOD16                     10
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_F_OFFSET                                25
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_F_WIDTH                                 1
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_OFFSET                                  0
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_F_OFFSET_MOD8                           1
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_F_OFFSET_MOD16                          9
#define RULE_BASED_CONTEXT_ENTRY_DEI_F_OFFSET                                   24
#define RULE_BASED_CONTEXT_ENTRY_DEI_F_WIDTH                                    1
#define RULE_BASED_CONTEXT_ENTRY_DEI_OFFSET                                     0
#define RULE_BASED_CONTEXT_ENTRY_DEI_F_OFFSET_MOD8                              0
#define RULE_BASED_CONTEXT_ENTRY_DEI_F_OFFSET_MOD16                             8
#define RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_F_OFFSET                            18
#define RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_F_WIDTH                             6
#define RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_OFFSET                              1
#define RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_F_OFFSET_MOD8                       2
#define RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_F_OFFSET_MOD16                      2
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_F_OFFSET                         17
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_F_WIDTH                          1
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_OFFSET                           1
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_F_OFFSET_MOD8                    1
#define RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_F_OFFSET_MOD16                   1
#define RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_F_OFFSET                    16
#define RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_F_WIDTH                     1
#define RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_OFFSET                      1
#define RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_F_OFFSET_MOD8               0
#define RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_F_OFFSET_MOD16              0
#define RULE_BASED_CONTEXT_ENTRY_GEM_MAPPING_TABLE_F_OFFSET                     13
#define RULE_BASED_CONTEXT_ENTRY_GEM_MAPPING_TABLE_F_WIDTH                      3
#define RULE_BASED_CONTEXT_ENTRY_GEM_MAPPING_TABLE_OFFSET                       2
#define RULE_BASED_CONTEXT_ENTRY_GEM_MAPPING_TABLE_F_OFFSET_MOD8                5
#define RULE_BASED_CONTEXT_ENTRY_TRAP_REASON_F_OFFSET                           10
#define RULE_BASED_CONTEXT_ENTRY_TRAP_REASON_F_WIDTH                            3
#define RULE_BASED_CONTEXT_ENTRY_TRAP_REASON_OFFSET                             2
#define RULE_BASED_CONTEXT_ENTRY_TRAP_REASON_F_OFFSET_MOD8                      2
#define RULE_BASED_CONTEXT_ENTRY_POLICER_ENABLE_F_OFFSET                        9
#define RULE_BASED_CONTEXT_ENTRY_POLICER_ENABLE_F_WIDTH                         1
#define RULE_BASED_CONTEXT_ENTRY_POLICER_ENABLE_OFFSET                          2
#define RULE_BASED_CONTEXT_ENTRY_POLICER_ENABLE_F_OFFSET_MOD8                   1
#define RULE_BASED_CONTEXT_ENTRY_QUEUE_F_OFFSET                                 0
#define RULE_BASED_CONTEXT_ENTRY_QUEUE_F_WIDTH                                  9
#define RULE_BASED_CONTEXT_ENTRY_QUEUE_OFFSET                                   2
#define RULE_BASED_CONTEXT_ENTRY_TO_LAN_F_OFFSET                                24
#define RULE_BASED_CONTEXT_ENTRY_TO_LAN_F_WIDTH                                 1
#define RULE_BASED_CONTEXT_ENTRY_TO_LAN_OFFSET                                  4
#define RULE_BASED_CONTEXT_ENTRY_TO_LAN_F_OFFSET_MOD8                           0
#define RULE_BASED_CONTEXT_ENTRY_TO_LAN_F_OFFSET_MOD16                          8
#define RULE_BASED_CONTEXT_ENTRY_FLOW_OR_PORT_F_OFFSET                          16
#define RULE_BASED_CONTEXT_ENTRY_FLOW_OR_PORT_F_WIDTH                           8
#define RULE_BASED_CONTEXT_ENTRY_FLOW_OR_PORT_OFFSET                            5
#define RULE_BASED_CONTEXT_ENTRY_FLOW_OR_PORT_F_OFFSET_MOD16                    0
#define RULE_BASED_CONTEXT_ENTRY_RULE_F_OFFSET                                  0
#define RULE_BASED_CONTEXT_ENTRY_RULE_F_WIDTH                                   16
#define RULE_BASED_CONTEXT_ENTRY_RULE_OFFSET                                    6

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	pbit_to_gem       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc_to_q           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_to_q         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_remark       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_action       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_remark       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_fwd            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_value        	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_fwd_action     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_based_forward	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	gem_mapping_table 	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	trap_reason       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	policer_enable    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	queue             	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = queue, size = 9 bits
	uint32_t	queue             	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2         	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	reserved3         	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	to_lan            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_or_port      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rule              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	queue             	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = queue, size = 9 bits
	uint32_t	queue             	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2         	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	policer_enable    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	trap_reason       	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	gem_mapping_table 	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_based_forward	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_fwd_action     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_value        	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dei               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_fwd            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dscp_remark       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_action       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_remark       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_to_q         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc_to_q           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pbit_to_gem       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rule              	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flow_or_port      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	to_lan            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3         	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RULE_BASED_CONTEXT_ENTRY_DTS;

#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 7, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 7, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_TO_GEM_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 6, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 6, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TC_TO_Q_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 5, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 5, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_TO_Q_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 4, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 4, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_PBIT_REMARK_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 3, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 3, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 3, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_VLAN_ACTION_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 3, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 2, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 2, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 2, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DSCP_REMARK_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 2, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_NO_FWD_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 1, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_NO_FWD_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 1, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_NO_FWD_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_NO_FWD_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DEI_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 0, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DEI_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS), 0, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DEI_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DEI_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 1, 2, 6, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 1, 2, 6, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 1, 2, 6, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_DSCP_VALUE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 1, 2, 6, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 1, 1, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 1, 1, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 1, 1, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_NO_FWD_ACTION_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 1, 1, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 1, 0, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 1, 0, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 0, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_FLOW_BASED_FORWARD_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 0, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_GEM_MAPPING_TABLE_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 5, 3, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_GEM_MAPPING_TABLE_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 5, 3, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_GEM_MAPPING_TABLE_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 2, 5, 3, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_GEM_MAPPING_TABLE_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 2, 5, 3, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TRAP_REASON_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 2, 3, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TRAP_REASON_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 2, 3, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TRAP_REASON_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 2, 2, 3, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TRAP_REASON_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 2, 2, 3, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_POLICER_ENABLE_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 1, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_POLICER_ENABLE_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 1, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_POLICER_ENABLE_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 2, 1, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_POLICER_ENABLE_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 2, 1, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_QUEUE_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 0, 9, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_QUEUE_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 0, 9, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_QUEUE_READ(r, p)                              FIELD_MREAD_16((uint8_t *)p + 2, 0, 9, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_QUEUE_WRITE(v, p)                             FIELD_MWRITE_16((uint8_t *)p + 2, 0, 9, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_QUEUE_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 0, 9, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_QUEUE_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 2, 0, 9, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_QUEUE_READ(r, p)                              FIELD_MREAD_16((uint8_t *)p + 2, 0, 9, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_QUEUE_WRITE(v, p)                             FIELD_MWRITE_16((uint8_t *)p + 2, 0, 9, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TC_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 3, 0, 3, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TC_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 3, 0, 3, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TC_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 3, 0, 3, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TC_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 3, 0, 3, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TO_LAN_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 4, 0, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TO_LAN_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 4, 0, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TO_LAN_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 4, 0, 1, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_TO_LAN_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 4, 0, 1, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_FLOW_OR_PORT_READ_G(r, g, idx)                GROUP_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 5, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_FLOW_OR_PORT_WRITE_G(v, g, idx)               GROUP_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 5, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_FLOW_OR_PORT_READ(r, p)                       MREAD_8((uint8_t *)p + 5, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_FLOW_OR_PORT_WRITE(v, p)                      MWRITE_8((uint8_t *)p + 5, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_RULE_READ_G(r, g, idx)                        GROUP_MREAD_16(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 6, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_RULE_WRITE_G(v, g, idx)                       GROUP_MWRITE_16(g, idx*sizeof(RDD_RULE_BASED_CONTEXT_ENTRY_DTS) + 6, v)
#define RDD_RULE_BASED_CONTEXT_ENTRY_RULE_READ(r, p)                               MREAD_16((uint8_t *)p + 6, r)
#define RDD_RULE_BASED_CONTEXT_ENTRY_RULE_WRITE(v, p)                              MWRITE_16((uint8_t *)p + 6, v)
#define IC_EXT_CONTEXT_ENTRY_CNTR_ID_F_OFFSET                               21
#define IC_EXT_CONTEXT_ENTRY_CNTR_ID_F_WIDTH                                11
#define IC_EXT_CONTEXT_ENTRY_CNTR_ID_OFFSET                                 0
#define IC_EXT_CONTEXT_ENTRY_CNTR_ID_F_OFFSET_MOD16                         5
#define IC_EXT_CONTEXT_ENTRY_POLICER_ID_F_OFFSET                            9
#define IC_EXT_CONTEXT_ENTRY_POLICER_ID_F_WIDTH                             7
#define IC_EXT_CONTEXT_ENTRY_POLICER_ID_OFFSET                              2
#define IC_EXT_CONTEXT_ENTRY_POLICER_ID_F_OFFSET_MOD8                       1
#define IC_EXT_CONTEXT_ENTRY_QOS_RULE_WAN_FLOW_OVERRUN_F_OFFSET             8
#define IC_EXT_CONTEXT_ENTRY_QOS_RULE_WAN_FLOW_OVERRUN_F_WIDTH              1
#define IC_EXT_CONTEXT_ENTRY_QOS_RULE_WAN_FLOW_OVERRUN_OFFSET               2
#define IC_EXT_CONTEXT_ENTRY_QOS_RULE_WAN_FLOW_OVERRUN_F_OFFSET_MOD8        0
#define IC_EXT_CONTEXT_ENTRY_OPBIT_REMARK_MODE_F_OFFSET                     7
#define IC_EXT_CONTEXT_ENTRY_OPBIT_REMARK_MODE_F_WIDTH                      1
#define IC_EXT_CONTEXT_ENTRY_OPBIT_REMARK_MODE_OFFSET                       3
#define IC_EXT_CONTEXT_ENTRY_IPBIT_REMARK_MODE_F_OFFSET                     6
#define IC_EXT_CONTEXT_ENTRY_IPBIT_REMARK_MODE_F_WIDTH                      1
#define IC_EXT_CONTEXT_ENTRY_IPBIT_REMARK_MODE_OFFSET                       3
#define IC_EXT_CONTEXT_ENTRY_OUTER_PBIT_F_OFFSET                            3
#define IC_EXT_CONTEXT_ENTRY_OUTER_PBIT_F_WIDTH                             3
#define IC_EXT_CONTEXT_ENTRY_OUTER_PBIT_OFFSET                              3
#define IC_EXT_CONTEXT_ENTRY_INNER_PBIT_F_OFFSET                            0
#define IC_EXT_CONTEXT_ENTRY_INNER_PBIT_F_WIDTH                             3
#define IC_EXT_CONTEXT_ENTRY_INNER_PBIT_OFFSET                              3
#define CPU_TX_DESCRIPTOR_VALID_F_OFFSET                                 31
#define CPU_TX_DESCRIPTOR_VALID_F_WIDTH                                  1
#define CPU_TX_DESCRIPTOR_VALID_OFFSET                                   0
#define CPU_TX_DESCRIPTOR_VALID_F_OFFSET_MOD8                            7
#define CPU_TX_DESCRIPTOR_VALID_F_OFFSET_MOD16                           15
#define CPU_TX_DESCRIPTOR_FIRST_LEVEL_Q_F_OFFSET                         22
#define CPU_TX_DESCRIPTOR_FIRST_LEVEL_Q_F_WIDTH                          9
#define CPU_TX_DESCRIPTOR_FIRST_LEVEL_Q_OFFSET                           0
#define CPU_TX_DESCRIPTOR_FIRST_LEVEL_Q_F_OFFSET_MOD16                   6
#define CPU_TX_DESCRIPTOR_ABS_DATA1_F_OFFSET                             0
#define CPU_TX_DESCRIPTOR_ABS_DATA1_F_WIDTH                              22
#define CPU_TX_DESCRIPTOR_ABS_DATA1_OFFSET                               0
#define CPU_TX_DESCRIPTOR_ABS_DATA0_F_OFFSET                             14
#define CPU_TX_DESCRIPTOR_ABS_DATA0_F_WIDTH                              18
#define CPU_TX_DESCRIPTOR_ABS_DATA0_OFFSET                               4
#define CPU_TX_DESCRIPTOR_PACKET_LENGTH_F_OFFSET                         0
#define CPU_TX_DESCRIPTOR_PACKET_LENGTH_F_WIDTH                          14
#define CPU_TX_DESCRIPTOR_PACKET_LENGTH_OFFSET                           6
#define CPU_TX_DESCRIPTOR_DROP_F_OFFSET                                  31
#define CPU_TX_DESCRIPTOR_DROP_F_WIDTH                                   1
#define CPU_TX_DESCRIPTOR_DROP_OFFSET                                    8
#define CPU_TX_DESCRIPTOR_DROP_F_OFFSET_MOD8                             7
#define CPU_TX_DESCRIPTOR_DROP_F_OFFSET_MOD16                            15
#define CPU_TX_DESCRIPTOR_FLAG_1588_F_OFFSET                             30
#define CPU_TX_DESCRIPTOR_FLAG_1588_F_WIDTH                              1
#define CPU_TX_DESCRIPTOR_FLAG_1588_OFFSET                               8
#define CPU_TX_DESCRIPTOR_FLAG_1588_F_OFFSET_MOD8                        6
#define CPU_TX_DESCRIPTOR_FLAG_1588_F_OFFSET_MOD16                       14
#define CPU_TX_DESCRIPTOR_COLOR_F_OFFSET                                 29
#define CPU_TX_DESCRIPTOR_COLOR_F_WIDTH                                  1
#define CPU_TX_DESCRIPTOR_COLOR_OFFSET                                   8
#define CPU_TX_DESCRIPTOR_COLOR_F_OFFSET_MOD8                            5
#define CPU_TX_DESCRIPTOR_COLOR_F_OFFSET_MOD16                           13
#define CPU_TX_DESCRIPTOR_LAN_F_OFFSET                                   26
#define CPU_TX_DESCRIPTOR_LAN_F_WIDTH                                    1
#define CPU_TX_DESCRIPTOR_LAN_OFFSET                                     8
#define CPU_TX_DESCRIPTOR_LAN_F_OFFSET_MOD8                              2
#define CPU_TX_DESCRIPTOR_LAN_F_OFFSET_MOD16                             10
#define CPU_TX_DESCRIPTOR_WAN_FLOW_SOURCE_PORT_F_OFFSET                  18
#define CPU_TX_DESCRIPTOR_WAN_FLOW_SOURCE_PORT_F_WIDTH                   8
#define CPU_TX_DESCRIPTOR_WAN_FLOW_SOURCE_PORT_OFFSET                    8
#define CPU_TX_DESCRIPTOR_WAN_FLOW_SOURCE_PORT_F_OFFSET_MOD16            2
#define CPU_TX_DESCRIPTOR_BN1_OR_ABS2_OR_1588_F_OFFSET                   0
#define CPU_TX_DESCRIPTOR_BN1_OR_ABS2_OR_1588_F_WIDTH                    18
#define CPU_TX_DESCRIPTOR_BN1_OR_ABS2_OR_1588_OFFSET                     8
#define CPU_TX_DESCRIPTOR_AGG_PD_F_OFFSET                                31
#define CPU_TX_DESCRIPTOR_AGG_PD_F_WIDTH                                 1
#define CPU_TX_DESCRIPTOR_AGG_PD_OFFSET                                  12
#define CPU_TX_DESCRIPTOR_AGG_PD_F_OFFSET_MOD8                           7
#define CPU_TX_DESCRIPTOR_AGG_PD_F_OFFSET_MOD16                          15
#define CPU_TX_DESCRIPTOR_TARGET_MEM_0_F_OFFSET                          30
#define CPU_TX_DESCRIPTOR_TARGET_MEM_0_F_WIDTH                           1
#define CPU_TX_DESCRIPTOR_TARGET_MEM_0_OFFSET                            12
#define CPU_TX_DESCRIPTOR_TARGET_MEM_0_F_OFFSET_MOD8                     6
#define CPU_TX_DESCRIPTOR_TARGET_MEM_0_F_OFFSET_MOD16                    14
#define CPU_TX_DESCRIPTOR_ABS_F_OFFSET                                   29
#define CPU_TX_DESCRIPTOR_ABS_F_WIDTH                                    1
#define CPU_TX_DESCRIPTOR_ABS_OFFSET                                     12
#define CPU_TX_DESCRIPTOR_ABS_F_OFFSET_MOD8                              5
#define CPU_TX_DESCRIPTOR_ABS_F_OFFSET_MOD16                             13
#define CPU_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_F_OFFSET               18
#define CPU_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_F_WIDTH                11
#define CPU_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_OFFSET                 12
#define CPU_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_F_OFFSET_MOD16         2
#define CPU_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_F_OFFSET              0
#define CPU_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_F_WIDTH               18
#define CPU_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_OFFSET                12

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	valid               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	first_level_q       	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_data1           	:22	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_data0           	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length       	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flag_1588           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	color               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lan                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	wan_flow_source_port	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn1_or_abs2_or_1588 	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = bn1_or_abs2_or_1588, size = 18 bits
	uint32_t	ssid                	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_fallback        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sbpm_copy           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn1_first           	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_ssid               	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_fpm_fallback       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_sbpm_copy          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs2                	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_1588           	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	agg_pd              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_0        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	payload_offset_or_abs_1	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = payload_offset_or_abs_1, size = 11 bits
	uint32_t	sop                 	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs1                	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	buffer_number_0_or_abs_0	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = buffer_number_0_or_abs_0, size = 18 bits
	uint32_t	bn0_first           	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs0                	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
#else
	uint32_t	abs_data1           	:22	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	first_level_q       	:9	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	packet_length       	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs_data0           	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn1_or_abs2_or_1588 	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = bn1_or_abs2_or_1588, size = 18 bits
	uint32_t	ssid                	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_fallback        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sbpm_copy           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bn1_first           	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_ssid               	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_fpm_fallback       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_sbpm_copy          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs2                	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_1588           	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	wan_flow_source_port	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lan                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	color               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flag_1588           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	drop                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	buffer_number_0_or_abs_0	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = buffer_number_0_or_abs_0, size = 18 bits
	uint32_t	bn0_first           	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs0                	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	payload_offset_or_abs_1	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = payload_offset_or_abs_1, size = 11 bits
	uint32_t	sop                 	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs1                	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	abs                 	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	target_mem_0        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	agg_pd              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_TX_DESCRIPTOR_DTS;

#define RDD_CPU_TX_DESCRIPTOR_VALID_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_VALID_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_VALID_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_VALID_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_FIRST_LEVEL_Q_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS), 6, 9, r)
#define RDD_CPU_TX_DESCRIPTOR_FIRST_LEVEL_Q_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS), 6, 9, v)
#define RDD_CPU_TX_DESCRIPTOR_FIRST_LEVEL_Q_READ(r, p)                        FIELD_MREAD_16((uint8_t *)p, 6, 9, r)
#define RDD_CPU_TX_DESCRIPTOR_FIRST_LEVEL_Q_WRITE(v, p)                       FIELD_MWRITE_16((uint8_t *)p, 6, 9, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS_DATA1_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 0, 0, 22, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS_DATA1_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 0, 0, 22, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS_DATA1_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 0, 0, 22, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS_DATA1_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 0, 0, 22, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS_DATA0_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 4, 14, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS_DATA0_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 4, 14, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS_DATA0_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 4, 14, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS_DATA0_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 4, 14, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_PACKET_LENGTH_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 6, 0, 14, r)
#define RDD_CPU_TX_DESCRIPTOR_PACKET_LENGTH_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 6, 0, 14, v)
#define RDD_CPU_TX_DESCRIPTOR_PACKET_LENGTH_READ(r, p)                        FIELD_MREAD_16((uint8_t *)p + 6, 0, 14, r)
#define RDD_CPU_TX_DESCRIPTOR_PACKET_LENGTH_WRITE(v, p)                       FIELD_MWRITE_16((uint8_t *)p + 6, 0, 14, v)
#define RDD_CPU_TX_DESCRIPTOR_DROP_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_DROP_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_DROP_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_DROP_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_FLAG_1588_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 6, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_FLAG_1588_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 6, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_FLAG_1588_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 8, 6, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_FLAG_1588_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 8, 6, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_COLOR_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_COLOR_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_COLOR_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 8, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_COLOR_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 8, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_LAN_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 2, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_LAN_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 2, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_LAN_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 8, 2, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_LAN_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 8, 2, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_WAN_FLOW_SOURCE_PORT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 2, 8, r)
#define RDD_CPU_TX_DESCRIPTOR_WAN_FLOW_SOURCE_PORT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 2, 8, v)
#define RDD_CPU_TX_DESCRIPTOR_WAN_FLOW_SOURCE_PORT_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 8, 2, 8, r)
#define RDD_CPU_TX_DESCRIPTOR_WAN_FLOW_SOURCE_PORT_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 8, 2, 8, v)
#define RDD_CPU_TX_DESCRIPTOR_BN1_OR_ABS2_OR_1588_READ_G(r, g, idx)           GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_BN1_OR_ABS2_OR_1588_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_BN1_OR_ABS2_OR_1588_READ(r, p)                  FIELD_MREAD_32((uint8_t *)p + 8, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_BN1_OR_ABS2_OR_1588_WRITE(v, p)                 FIELD_MWRITE_32((uint8_t *)p + 8, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_SSID_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 14, 4, r)
#define RDD_CPU_TX_DESCRIPTOR_SSID_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 14, 4, v)
#define RDD_CPU_TX_DESCRIPTOR_SSID_READ(r, p)                                 FIELD_MREAD_32((uint8_t *)p + 8, 14, 4, r)
#define RDD_CPU_TX_DESCRIPTOR_SSID_WRITE(v, p)                                FIELD_MWRITE_32((uint8_t *)p + 8, 14, 4, v)
#define RDD_CPU_TX_DESCRIPTOR_FPM_FALLBACK_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_FPM_FALLBACK_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_FPM_FALLBACK_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 10, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_FPM_FALLBACK_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 10, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_SBPM_COPY_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 4, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_SBPM_COPY_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 4, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_SBPM_COPY_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 10, 4, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_SBPM_COPY_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 10, 4, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_BN1_FIRST_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 0, 12, r)
#define RDD_CPU_TX_DESCRIPTOR_BN1_FIRST_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 0, 12, v)
#define RDD_CPU_TX_DESCRIPTOR_BN1_FIRST_READ(r, p)                            FIELD_MREAD_16((uint8_t *)p + 10, 0, 12, r)
#define RDD_CPU_TX_DESCRIPTOR_BN1_FIRST_WRITE(v, p)                           FIELD_MWRITE_16((uint8_t *)p + 10, 0, 12, v)
#define RDD_CPU_TX_DESCRIPTOR__SSID_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 14, 4, r)
#define RDD_CPU_TX_DESCRIPTOR__SSID_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 14, 4, v)
#define RDD_CPU_TX_DESCRIPTOR__SSID_READ(r, p)                                FIELD_MREAD_32((uint8_t *)p + 8, 14, 4, r)
#define RDD_CPU_TX_DESCRIPTOR__SSID_WRITE(v, p)                               FIELD_MWRITE_32((uint8_t *)p + 8, 14, 4, v)
#define RDD_CPU_TX_DESCRIPTOR__FPM_FALLBACK_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR__FPM_FALLBACK_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR__FPM_FALLBACK_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 10, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR__FPM_FALLBACK_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 10, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR__SBPM_COPY_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 4, 1, r)
#define RDD_CPU_TX_DESCRIPTOR__SBPM_COPY_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 4, 1, v)
#define RDD_CPU_TX_DESCRIPTOR__SBPM_COPY_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 10, 4, 1, r)
#define RDD_CPU_TX_DESCRIPTOR__SBPM_COPY_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 10, 4, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS2_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 0, 12, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS2_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 10, 0, 12, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS2_READ(r, p)                                 FIELD_MREAD_16((uint8_t *)p + 10, 0, 12, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS2_WRITE(v, p)                                FIELD_MWRITE_16((uint8_t *)p + 10, 0, 12, v)
#define RDD_CPU_TX_DESCRIPTOR_DATA_1588_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_DATA_1588_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 8, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_DATA_1588_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 8, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_DATA_1588_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 8, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_AGG_PD_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_AGG_PD_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_AGG_PD_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_AGG_PD_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_TARGET_MEM_0_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 6, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_TARGET_MEM_0_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 6, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_TARGET_MEM_0_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 12, 6, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_TARGET_MEM_0_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 12, 6, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 12, 5, 1, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 12, 5, 1, v)
#define RDD_CPU_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_READ_G(r, g, idx)       GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 2, 11, r)
#define RDD_CPU_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_WRITE_G(v, g, idx)      GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 2, 11, v)
#define RDD_CPU_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_READ(r, p)              FIELD_MREAD_16((uint8_t *)p + 12, 2, 11, r)
#define RDD_CPU_TX_DESCRIPTOR_PAYLOAD_OFFSET_OR_ABS_1_WRITE(v, p)             FIELD_MWRITE_16((uint8_t *)p + 12, 2, 11, v)
#define RDD_CPU_TX_DESCRIPTOR_SOP_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 2, 11, r)
#define RDD_CPU_TX_DESCRIPTOR_SOP_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 2, 11, v)
#define RDD_CPU_TX_DESCRIPTOR_SOP_READ(r, p)                                  FIELD_MREAD_16((uint8_t *)p + 12, 2, 11, r)
#define RDD_CPU_TX_DESCRIPTOR_SOP_WRITE(v, p)                                 FIELD_MWRITE_16((uint8_t *)p + 12, 2, 11, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS1_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 2, 11, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS1_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 2, 11, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS1_READ(r, p)                                 FIELD_MREAD_16((uint8_t *)p + 12, 2, 11, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS1_WRITE(v, p)                                FIELD_MWRITE_16((uint8_t *)p + 12, 2, 11, v)
#define RDD_CPU_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_READ_G(r, g, idx)      GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_WRITE_G(v, g, idx)     GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_READ(r, p)             FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_BUFFER_NUMBER_0_OR_ABS_0_WRITE(v, p)            FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_BN0_FIRST_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_BN0_FIRST_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_BN0_FIRST_READ(r, p)                            FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_BN0_FIRST_WRITE(v, p)                           FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS0_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS0_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_TX_DESCRIPTOR_DTS) + 12, 0, 18, v)
#define RDD_CPU_TX_DESCRIPTOR_ABS0_READ(r, p)                                 FIELD_MREAD_32((uint8_t *)p + 12, 0, 18, r)
#define RDD_CPU_TX_DESCRIPTOR_ABS0_WRITE(v, p)                                FIELD_MWRITE_32((uint8_t *)p + 12, 0, 18, v)
#define TC_TO_QUEUE_8_QUEUE_OFFSET_OFFSET                            0
#define TC_TO_QUEUE_32_QUEUE_OFFSET_OFFSET                            0
#define RDD_TC_TO_QUEUE_32_QUEUE_OFFSET_NUMBER	32

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	queue_offset[RDD_TC_TO_QUEUE_32_QUEUE_OFFSET_NUMBER];
#else
	uint8_t	queue_offset[RDD_TC_TO_QUEUE_32_QUEUE_OFFSET_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TC_TO_QUEUE_32_DTS;

#define RDD_TC_TO_QUEUE_32_QUEUE_OFFSET_READ_G(r, g, idx, i)       GROUP_MREAD_I_8(g, idx*sizeof(RDD_TC_TO_QUEUE_32_DTS), i, r)
#define RDD_TC_TO_QUEUE_32_QUEUE_OFFSET_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_8(g, idx*sizeof(RDD_TC_TO_QUEUE_32_DTS), i, v)
#define RDD_TC_TO_QUEUE_32_QUEUE_OFFSET_READ(r, p, i)              MREAD_I_8((uint8_t *)p, i, r)
#define RDD_TC_TO_QUEUE_32_QUEUE_OFFSET_WRITE(v, p, i)             MWRITE_I_8((uint8_t *)p, i, v)
#define PBIT_TO_QUEUE_8_QUEUE_OFFSET_OFFSET                            0
#define VPORT_CFG_ENTRY_LOOPBACK_EN_F_OFFSET                           15
#define VPORT_CFG_ENTRY_LOOPBACK_EN_F_WIDTH                            1
#define VPORT_CFG_ENTRY_LOOPBACK_EN_OFFSET                             0
#define VPORT_CFG_ENTRY_LOOPBACK_EN_F_OFFSET_MOD8                      7
#define VPORT_CFG_ENTRY_MIRRORING_EN_F_OFFSET                          14
#define VPORT_CFG_ENTRY_MIRRORING_EN_F_WIDTH                           1
#define VPORT_CFG_ENTRY_MIRRORING_EN_OFFSET                            0
#define VPORT_CFG_ENTRY_MIRRORING_EN_F_OFFSET_MOD8                     6
#define VPORT_CFG_ENTRY_SA_LOOKUP_EN_F_OFFSET                          13
#define VPORT_CFG_ENTRY_SA_LOOKUP_EN_F_WIDTH                           1
#define VPORT_CFG_ENTRY_SA_LOOKUP_EN_OFFSET                            0
#define VPORT_CFG_ENTRY_SA_LOOKUP_EN_F_OFFSET_MOD8                     5
#define VPORT_CFG_ENTRY_DA_LOOKUP_EN_F_OFFSET                          12
#define VPORT_CFG_ENTRY_DA_LOOKUP_EN_F_WIDTH                           1
#define VPORT_CFG_ENTRY_DA_LOOKUP_EN_OFFSET                            0
#define VPORT_CFG_ENTRY_DA_LOOKUP_EN_F_OFFSET_MOD8                     4
#define VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_F_OFFSET                   11
#define VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_F_WIDTH                    1
#define VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_OFFSET                     0
#define VPORT_CFG_ENTRY_EGRESS_ISOLATION_EN_F_OFFSET_MOD8              3
#define VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_F_OFFSET                  10
#define VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_F_WIDTH                   1
#define VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_OFFSET                    0
#define VPORT_CFG_ENTRY_INGRESS_ISOLATION_EN_F_OFFSET_MOD8             2
#define VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_F_OFFSET         9
#define VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_F_WIDTH          1
#define VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_OFFSET           0
#define VPORT_CFG_ENTRY_BRIDGE_AND_VLAN_LOOKUP_METHOD_F_OFFSET_MOD8    1
#define VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_F_OFFSET                 3
#define VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_F_WIDTH                  2
#define VPORT_CFG_ENTRY_SA_LOOKUP_MISS_ACTION_OFFSET                   1
#define VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_F_OFFSET                 1
#define VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_F_WIDTH                  2
#define VPORT_CFG_ENTRY_DA_LOOKUP_MISS_ACTION_OFFSET                   1
#define VPORT_CFG_ENTRY_LS_FC_CFG_F_OFFSET                             0
#define VPORT_CFG_ENTRY_LS_FC_CFG_F_WIDTH                              1
#define VPORT_CFG_ENTRY_LS_FC_CFG_OFFSET                               1
#define FPM_GLOBAL_CFG_FPM_BASE_LOW_F_OFFSET                          0
#define FPM_GLOBAL_CFG_FPM_BASE_LOW_F_WIDTH                           32
#define FPM_GLOBAL_CFG_FPM_BASE_LOW_OFFSET                            0
#define FPM_GLOBAL_CFG_FPM_BASE_HIGH_F_OFFSET                         0
#define FPM_GLOBAL_CFG_FPM_BASE_HIGH_F_WIDTH                          32
#define FPM_GLOBAL_CFG_FPM_BASE_HIGH_OFFSET                           4
#define FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_F_OFFSET                  24
#define FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_F_WIDTH                   8
#define FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_OFFSET                    8
#define FPM_GLOBAL_CFG_FPM_TOKEN_SIZE_ASR_8_F_OFFSET_MOD16            8
#define VLAN_TAG_PBITS_F_OFFSET                                 13
#define VLAN_TAG_PBITS_F_WIDTH                                  3
#define VLAN_TAG_PBITS_OFFSET                                   0
#define VLAN_TAG_PBITS_F_OFFSET_MOD8                            5
#define VLAN_TAG_CFI_F_OFFSET                                   12
#define VLAN_TAG_CFI_F_WIDTH                                    1
#define VLAN_TAG_CFI_OFFSET                                     0
#define VLAN_TAG_CFI_F_OFFSET_MOD8                              4
#define VLAN_TAG_VID_F_OFFSET                                   0
#define VLAN_TAG_VID_F_WIDTH                                    12
#define VLAN_TAG_VID_OFFSET                                     0

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	pbits     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	cfi       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	vid       	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	vid       	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	cfi       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	pbits     	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_VLAN_TAG_DTS;

#define RDD_VLAN_TAG_PBITS_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VLAN_TAG_DTS), 5, 3, r)
#define RDD_VLAN_TAG_PBITS_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VLAN_TAG_DTS), 5, 3, v)
#define RDD_VLAN_TAG_PBITS_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 5, 3, r)
#define RDD_VLAN_TAG_PBITS_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 5, 3, v)
#define RDD_VLAN_TAG_CFI_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_VLAN_TAG_DTS), 4, 1, r)
#define RDD_VLAN_TAG_CFI_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_VLAN_TAG_DTS), 4, 1, v)
#define RDD_VLAN_TAG_CFI_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_VLAN_TAG_CFI_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_VLAN_TAG_VID_READ_G(r, g, idx)            GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_VLAN_TAG_DTS), 0, 12, r)
#define RDD_VLAN_TAG_VID_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_VLAN_TAG_DTS), 0, 12, v)
#define RDD_VLAN_TAG_VID_READ(r, p)                   FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_VLAN_TAG_VID_WRITE(v, p)                  FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#define CPU_RX_METER_ENTRY_CURRENT_BUDGET_F_OFFSET                        16
#define CPU_RX_METER_ENTRY_CURRENT_BUDGET_F_WIDTH                         16
#define CPU_RX_METER_ENTRY_CURRENT_BUDGET_OFFSET                          0
#define CPU_RX_METER_ENTRY_BUDGET_LIMIT_F_OFFSET                          0
#define CPU_RX_METER_ENTRY_BUDGET_LIMIT_F_WIDTH                           16
#define CPU_RX_METER_ENTRY_BUDGET_LIMIT_OFFSET                            2
#define CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_F_OFFSET                      16
#define CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_F_WIDTH                       16
#define CPU_RX_METER_ENTRY_ALLOCATED_BUDGET_OFFSET                        4
#define IPTV_HASH_LKP_ENTRY_ADDR_HIGH_F_OFFSET                             0
#define IPTV_HASH_LKP_ENTRY_ADDR_HIGH_F_WIDTH                              32
#define IPTV_HASH_LKP_ENTRY_ADDR_HIGH_OFFSET                               0
#define IPTV_HASH_LKP_ENTRY_DST_IP_OR_MAC_LOW_F_OFFSET                     0
#define IPTV_HASH_LKP_ENTRY_DST_IP_OR_MAC_LOW_F_WIDTH                      32
#define IPTV_HASH_LKP_ENTRY_DST_IP_OR_MAC_LOW_OFFSET                       4

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	addr_high        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = addr_high, size = 32 bits
	uint32_t	reserved0        	:31	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv6             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_high         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	dst_ip_or_mac_low	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	addr_high        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = addr_high, size = 32 bits
	uint32_t	reserved0        	:31	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv6             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_high         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	dst_ip_or_mac_low	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_HASH_LKP_ENTRY_DTS;

#define RDD_IPTV_HASH_LKP_ENTRY_ADDR_HIGH_READ_G(r, g, idx)                  GROUP_MREAD_32(g, idx*sizeof(RDD_IPTV_HASH_LKP_ENTRY_DTS), r)
#define RDD_IPTV_HASH_LKP_ENTRY_ADDR_HIGH_WRITE_G(v, g, idx)                 GROUP_MWRITE_32(g, idx*sizeof(RDD_IPTV_HASH_LKP_ENTRY_DTS), v)
#define RDD_IPTV_HASH_LKP_ENTRY_ADDR_HIGH_READ(r, p)                         MREAD_32((uint8_t *)p, r)
#define RDD_IPTV_HASH_LKP_ENTRY_ADDR_HIGH_WRITE(v, p)                        MWRITE_32((uint8_t *)p, v)
#define RDD_IPTV_HASH_LKP_ENTRY_IPV6_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_IPTV_HASH_LKP_ENTRY_DTS) + 3, 0, 1, r)
#define RDD_IPTV_HASH_LKP_ENTRY_IPV6_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_IPTV_HASH_LKP_ENTRY_DTS) + 3, 0, 1, v)
#define RDD_IPTV_HASH_LKP_ENTRY_IPV6_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 3, 0, 1, r)
#define RDD_IPTV_HASH_LKP_ENTRY_IPV6_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 3, 0, 1, v)
#define RDD_IPTV_HASH_LKP_ENTRY_MAC_HIGH_READ_G(r, g, idx)                   GROUP_MREAD_16(g, idx*sizeof(RDD_IPTV_HASH_LKP_ENTRY_DTS) + 2, r)
#define RDD_IPTV_HASH_LKP_ENTRY_MAC_HIGH_WRITE_G(v, g, idx)                  GROUP_MWRITE_16(g, idx*sizeof(RDD_IPTV_HASH_LKP_ENTRY_DTS) + 2, v)
#define RDD_IPTV_HASH_LKP_ENTRY_MAC_HIGH_READ(r, p)                          MREAD_16((uint8_t *)p + 2, r)
#define RDD_IPTV_HASH_LKP_ENTRY_MAC_HIGH_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 2, v)
#define RDD_IPTV_HASH_LKP_ENTRY_DST_IP_OR_MAC_LOW_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_IPTV_HASH_LKP_ENTRY_DTS) + 4, r)
#define RDD_IPTV_HASH_LKP_ENTRY_DST_IP_OR_MAC_LOW_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_IPTV_HASH_LKP_ENTRY_DTS) + 4, v)
#define RDD_IPTV_HASH_LKP_ENTRY_DST_IP_OR_MAC_LOW_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_IPTV_HASH_LKP_ENTRY_DST_IP_OR_MAC_LOW_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define IPTV_HASH_RESULT_ENTRY_CTX_IDX_F_OFFSET                               22
#define IPTV_HASH_RESULT_ENTRY_CTX_IDX_F_WIDTH                                10
#define IPTV_HASH_RESULT_ENTRY_CTX_IDX_OFFSET                                 0
#define IPTV_HASH_RESULT_ENTRY_CTX_IDX_F_OFFSET_MOD16                         6

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	ctx_idx   	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	reserved0 	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ctx_idx   	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_IPTV_HASH_RESULT_ENTRY_DTS;

#define RDD_IPTV_HASH_RESULT_ENTRY_CTX_IDX_READ_G(r, g, idx)            GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_IPTV_HASH_RESULT_ENTRY_DTS), 6, 10, r)
#define RDD_IPTV_HASH_RESULT_ENTRY_CTX_IDX_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_IPTV_HASH_RESULT_ENTRY_DTS), 6, 10, v)
#define RDD_IPTV_HASH_RESULT_ENTRY_CTX_IDX_READ(r, p)                   FIELD_MREAD_16((uint8_t *)p, 6, 10, r)
#define RDD_IPTV_HASH_RESULT_ENTRY_CTX_IDX_WRITE(v, p)                  FIELD_MWRITE_16((uint8_t *)p, 6, 10, v)
#define IPTV_DDR_CONTEXT_ENTRY_VALID_F_OFFSET                                 31
#define IPTV_DDR_CONTEXT_ENTRY_VALID_F_WIDTH                                  1
#define IPTV_DDR_CONTEXT_ENTRY_VALID_OFFSET                                   0
#define IPTV_DDR_CONTEXT_ENTRY_VALID_F_OFFSET_MOD8                            7
#define IPTV_DDR_CONTEXT_ENTRY_VALID_F_OFFSET_MOD16                           15
#define IPTV_DDR_CONTEXT_ENTRY_IP_VER_F_OFFSET                                30
#define IPTV_DDR_CONTEXT_ENTRY_IP_VER_F_WIDTH                                 1
#define IPTV_DDR_CONTEXT_ENTRY_IP_VER_OFFSET                                  0
#define IPTV_DDR_CONTEXT_ENTRY_IP_VER_F_OFFSET_MOD8                           6
#define IPTV_DDR_CONTEXT_ENTRY_IP_VER_F_OFFSET_MOD16                          14
#define IPTV_DDR_CONTEXT_ENTRY_ANY_VID_F_OFFSET                               29
#define IPTV_DDR_CONTEXT_ENTRY_ANY_VID_F_WIDTH                                1
#define IPTV_DDR_CONTEXT_ENTRY_ANY_VID_OFFSET                                 0
#define IPTV_DDR_CONTEXT_ENTRY_ANY_VID_F_OFFSET_MOD8                          5
#define IPTV_DDR_CONTEXT_ENTRY_ANY_VID_F_OFFSET_MOD16                         13
#define IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_F_OFFSET                            28
#define IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_F_WIDTH                             1
#define IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_OFFSET                              0
#define IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_F_OFFSET_MOD8                       4
#define IPTV_DDR_CONTEXT_ENTRY_ANY_SRC_IP_F_OFFSET_MOD16                      12
#define IPTV_DDR_CONTEXT_ENTRY_VID_F_OFFSET                                   16
#define IPTV_DDR_CONTEXT_ENTRY_VID_F_WIDTH                                    12
#define IPTV_DDR_CONTEXT_ENTRY_VID_OFFSET                                     0
#define IPTV_DDR_CONTEXT_ENTRY_VID_F_OFFSET_MOD16                             0
#define IPTV_DDR_CONTEXT_ENTRY_NEXT_ENTRY_IDX_F_OFFSET                        0
#define IPTV_DDR_CONTEXT_ENTRY_NEXT_ENTRY_IDX_F_WIDTH                         16
#define IPTV_DDR_CONTEXT_ENTRY_NEXT_ENTRY_IDX_OFFSET                          2
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_0_F_OFFSET                         16
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_0_F_WIDTH                          16
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_0_OFFSET                           4
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_1_F_OFFSET                         0
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_1_F_WIDTH                          16
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_1_OFFSET                           6
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_2_F_OFFSET                         16
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_2_F_WIDTH                          16
#define IPTV_DDR_CONTEXT_ENTRY_SSID_VECTOR_2_OFFSET                           8
#define IPTV_DDR_CONTEXT_ENTRY_RADIO_DHD_VECTOR_F_OFFSET                      13
#define IPTV_DDR_CONTEXT_ENTRY_RADIO_DHD_VECTOR_F_WIDTH                       3
#define IPTV_DDR_CONTEXT_ENTRY_RADIO_DHD_VECTOR_OFFSET                        10
#define IPTV_DDR_CONTEXT_ENTRY_RADIO_DHD_VECTOR_F_OFFSET_MOD8                 5
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_PROXY_ENABLED_F_OFFSET              7
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_PROXY_ENABLED_F_WIDTH               1
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_PROXY_ENABLED_OFFSET                11
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_INDEX_F_OFFSET                      0
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_INDEX_F_WIDTH                       7
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_INDEX_OFFSET                        11
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_F_OFFSET                    28
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_F_WIDTH                     3
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_OFFSET                      12
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_F_OFFSET_MOD8               4
#define IPTV_DDR_CONTEXT_ENTRY_WLAN_MCAST_TX_PRIO_F_OFFSET_MOD16              12
#define IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_F_OFFSET                              22
#define IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_F_WIDTH                               2
#define IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_OFFSET                                13
#define IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_F_OFFSET_MOD8                         6
#define IPTV_DDR_CONTEXT_ENTRY_POOL_NUM_F_OFFSET_MOD16                        6
#define IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_F_OFFSET                          16
#define IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_F_WIDTH                           6
#define IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_OFFSET                            13
#define IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_F_OFFSET_MOD8                     0
#define IPTV_DDR_CONTEXT_ENTRY_REPLICATIONS_F_OFFSET_MOD16                    0
#define IPTV_DDR_CONTEXT_ENTRY_CNTR_ID_F_OFFSET                               0
#define IPTV_DDR_CONTEXT_ENTRY_CNTR_ID_F_WIDTH                                10
#define IPTV_DDR_CONTEXT_ENTRY_CNTR_ID_OFFSET                                 14
#define IPTV_DDR_CONTEXT_ENTRY_EGRESS_PORTS_VECTOR_F_OFFSET                   0
#define IPTV_DDR_CONTEXT_ENTRY_EGRESS_PORTS_VECTOR_F_WIDTH                    32
#define IPTV_DDR_CONTEXT_ENTRY_EGRESS_PORTS_VECTOR_OFFSET                     16
#define IPTV_DDR_CONTEXT_ENTRY_SRC_IP_F_OFFSET                                0
#define IPTV_DDR_CONTEXT_ENTRY_SRC_IP_F_WIDTH                                 32
#define IPTV_DDR_CONTEXT_ENTRY_SRC_IP_OFFSET                                  20
#define IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_OFFSET                           24
#define IPTV_DDR_CONTEXT_ENTRY_SRC_IPV6_ADDR_F_OFFSET_MOD16                   8
#define IPTV_DDR_CONTEXT_ENTRY_DST_IPV6_ADDR_OFFSET                           40
#define IPTV_DDR_CONTEXT_ENTRY_RULE_BASED_RESULT_OFFSET                       56
#define NAT_CACHE_LKP_ENTRY_VALID_F_OFFSET                                 31
#define NAT_CACHE_LKP_ENTRY_VALID_F_WIDTH                                  1
#define NAT_CACHE_LKP_ENTRY_VALID_OFFSET                                   0
#define NAT_CACHE_LKP_ENTRY_VALID_F_OFFSET_MOD8                            7
#define NAT_CACHE_LKP_ENTRY_VALID_F_OFFSET_MOD16                           15
#define NAT_CACHE_LKP_ENTRY_SUB_TABLE_ID_F_OFFSET                          12
#define NAT_CACHE_LKP_ENTRY_SUB_TABLE_ID_F_WIDTH                           3
#define NAT_CACHE_LKP_ENTRY_SUB_TABLE_ID_OFFSET                            2
#define NAT_CACHE_LKP_ENTRY_SUB_TABLE_ID_F_OFFSET_MOD8                     4
#define NAT_CACHE_LKP_ENTRY_KEY_EXTEND_F_OFFSET                            8
#define NAT_CACHE_LKP_ENTRY_KEY_EXTEND_F_WIDTH                             4
#define NAT_CACHE_LKP_ENTRY_KEY_EXTEND_OFFSET                              2
#define NAT_CACHE_LKP_ENTRY_KEY_EXTEND_F_OFFSET_MOD8                       0
#define NAT_CACHE_LKP_ENTRY_PROTOCOL_F_OFFSET                              0
#define NAT_CACHE_LKP_ENTRY_PROTOCOL_F_WIDTH                               8
#define NAT_CACHE_LKP_ENTRY_PROTOCOL_OFFSET                                3
#define NAT_CACHE_LKP_ENTRY_SRC_PORT_F_OFFSET                              16
#define NAT_CACHE_LKP_ENTRY_SRC_PORT_F_WIDTH                               16
#define NAT_CACHE_LKP_ENTRY_SRC_PORT_OFFSET                                4
#define NAT_CACHE_LKP_ENTRY_DST_PORT_F_OFFSET                              0
#define NAT_CACHE_LKP_ENTRY_DST_PORT_F_WIDTH                               16
#define NAT_CACHE_LKP_ENTRY_DST_PORT_OFFSET                                6
#define NAT_CACHE_LKP_ENTRY_SRC_IP_F_OFFSET                                0
#define NAT_CACHE_LKP_ENTRY_SRC_IP_F_WIDTH                                 32
#define NAT_CACHE_LKP_ENTRY_SRC_IP_OFFSET                                  8
#define NAT_CACHE_LKP_ENTRY_DST_IP_F_OFFSET                                0
#define NAT_CACHE_LKP_ENTRY_DST_IP_F_WIDTH                                 32
#define NAT_CACHE_LKP_ENTRY_DST_IP_OFFSET                                  12

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	valid       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sub_table_id	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_extend  	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	protocol    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_port    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_port    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_ip      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_ip      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	protocol    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_extend  	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sub_table_id	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_port    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_port    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	src_ip      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dst_ip      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NAT_CACHE_LKP_ENTRY_DTS;

#define RDD_NAT_CACHE_LKP_ENTRY_VALID_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS), 7, 1, r)
#define RDD_NAT_CACHE_LKP_ENTRY_VALID_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS), 7, 1, v)
#define RDD_NAT_CACHE_LKP_ENTRY_VALID_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_NAT_CACHE_LKP_ENTRY_VALID_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_NAT_CACHE_LKP_ENTRY_SUB_TABLE_ID_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 2, 4, 3, r)
#define RDD_NAT_CACHE_LKP_ENTRY_SUB_TABLE_ID_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 2, 4, 3, v)
#define RDD_NAT_CACHE_LKP_ENTRY_SUB_TABLE_ID_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 4, 3, r)
#define RDD_NAT_CACHE_LKP_ENTRY_SUB_TABLE_ID_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 4, 3, v)
#define RDD_NAT_CACHE_LKP_ENTRY_KEY_EXTEND_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 2, 0, 4, r)
#define RDD_NAT_CACHE_LKP_ENTRY_KEY_EXTEND_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 2, 0, 4, v)
#define RDD_NAT_CACHE_LKP_ENTRY_KEY_EXTEND_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 2, 0, 4, r)
#define RDD_NAT_CACHE_LKP_ENTRY_KEY_EXTEND_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 2, 0, 4, v)
#define RDD_NAT_CACHE_LKP_ENTRY_PROTOCOL_READ_G(r, g, idx)              GROUP_MREAD_8(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 3, r)
#define RDD_NAT_CACHE_LKP_ENTRY_PROTOCOL_WRITE_G(v, g, idx)             GROUP_MWRITE_8(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 3, v)
#define RDD_NAT_CACHE_LKP_ENTRY_PROTOCOL_READ(r, p)                     MREAD_8((uint8_t *)p + 3, r)
#define RDD_NAT_CACHE_LKP_ENTRY_PROTOCOL_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 3, v)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_PORT_READ_G(r, g, idx)              GROUP_MREAD_16(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 4, r)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_PORT_WRITE_G(v, g, idx)             GROUP_MWRITE_16(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 4, v)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_PORT_READ(r, p)                     MREAD_16((uint8_t *)p + 4, r)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_PORT_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 4, v)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_PORT_READ_G(r, g, idx)              GROUP_MREAD_16(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 6, r)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_PORT_WRITE_G(v, g, idx)             GROUP_MWRITE_16(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 6, v)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_PORT_READ(r, p)                     MREAD_16((uint8_t *)p + 6, r)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_PORT_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 6, v)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_IP_READ_G(r, g, idx)                GROUP_MREAD_32(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 8, r)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_IP_WRITE_G(v, g, idx)               GROUP_MWRITE_32(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 8, v)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_IP_READ(r, p)                       MREAD_32((uint8_t *)p + 8, r)
#define RDD_NAT_CACHE_LKP_ENTRY_SRC_IP_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 8, v)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_IP_READ_G(r, g, idx)                GROUP_MREAD_32(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 12, r)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_IP_WRITE_G(v, g, idx)               GROUP_MWRITE_32(g, idx*sizeof(RDD_NAT_CACHE_LKP_ENTRY_DTS) + 12, v)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_IP_READ(r, p)                       MREAD_32((uint8_t *)p + 12, r)
#define RDD_NAT_CACHE_LKP_ENTRY_DST_IP_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 12, v)
#define TCAM_IC_SCRATCH_KEY_OFFSET                                     8
#define TCAM_IC_SCRATCH_RESULT_OFFSET                                  72
#define RDD_TCAM_IC_SCRATCH_RESERVED0_NUMBER	8
#define RDD_TCAM_IC_SCRATCH_KEY_NUMBER	64
#define RDD_TCAM_IC_SCRATCH_RESULT_NUMBER	16

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint8_t	reserved0[RDD_TCAM_IC_SCRATCH_RESERVED0_NUMBER];
	uint8_t	key[RDD_TCAM_IC_SCRATCH_KEY_NUMBER];
	uint8_t	result[RDD_TCAM_IC_SCRATCH_RESULT_NUMBER];
#else
	uint8_t	reserved0[RDD_TCAM_IC_SCRATCH_RESERVED0_NUMBER];
	uint8_t	key[RDD_TCAM_IC_SCRATCH_KEY_NUMBER];
	uint8_t	result[RDD_TCAM_IC_SCRATCH_RESULT_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_TCAM_IC_SCRATCH_DTS;

#define RDD_TCAM_IC_SCRATCH_KEY_READ_G(r, g, idx, i)             GROUP_MREAD_I_8(g, idx*sizeof(RDD_TCAM_IC_SCRATCH_DTS) + 8, i, r)
#define RDD_TCAM_IC_SCRATCH_KEY_WRITE_G(v, g, idx, i)            GROUP_MWRITE_I_8(g, idx*sizeof(RDD_TCAM_IC_SCRATCH_DTS) + 8, i, v)
#define RDD_TCAM_IC_SCRATCH_KEY_READ(r, p, i)                    MREAD_I_8((uint8_t *)p + 8, i, r)
#define RDD_TCAM_IC_SCRATCH_KEY_WRITE(v, p, i)                   MWRITE_I_8((uint8_t *)p + 8, i, v)
#define RDD_TCAM_IC_SCRATCH_RESULT_READ_G(r, g, idx, i)          GROUP_MREAD_I_8(g, idx*sizeof(RDD_TCAM_IC_SCRATCH_DTS) + 72, i, r)
#define RDD_TCAM_IC_SCRATCH_RESULT_WRITE_G(v, g, idx, i)         GROUP_MWRITE_I_8(g, idx*sizeof(RDD_TCAM_IC_SCRATCH_DTS) + 72, i, v)
#define RDD_TCAM_IC_SCRATCH_RESULT_READ(r, p, i)                 MREAD_I_8((uint8_t *)p + 72, i, r)
#define RDD_TCAM_IC_SCRATCH_RESULT_WRITE(v, p, i)                MWRITE_I_8((uint8_t *)p + 72, i, v)
#define BRIDGE_CFG_HIT_F_OFFSET                                   31
#define BRIDGE_CFG_HIT_F_WIDTH                                    1
#define BRIDGE_CFG_HIT_OFFSET                                     0
#define BRIDGE_CFG_HIT_F_OFFSET_MOD8                              7
#define BRIDGE_CFG_HIT_F_OFFSET_MOD16                             15
#define BRIDGE_CFG_BRIDGE_FW_FAILED_F_OFFSET                      30
#define BRIDGE_CFG_BRIDGE_FW_FAILED_F_WIDTH                       1
#define BRIDGE_CFG_BRIDGE_FW_FAILED_OFFSET                        0
#define BRIDGE_CFG_BRIDGE_FW_FAILED_F_OFFSET_MOD8                 6
#define BRIDGE_CFG_BRIDGE_FW_FAILED_F_OFFSET_MOD16                14
#define BRIDGE_CFG_VLAN_AGGREGATION_F_OFFSET                      29
#define BRIDGE_CFG_VLAN_AGGREGATION_F_WIDTH                       1
#define BRIDGE_CFG_VLAN_AGGREGATION_OFFSET                        0
#define BRIDGE_CFG_VLAN_AGGREGATION_F_OFFSET_MOD8                 5
#define BRIDGE_CFG_VLAN_AGGREGATION_F_OFFSET_MOD16                13
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_F_OFFSET       19
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_F_WIDTH        1
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_OFFSET         1
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_F_OFFSET_MOD8  3
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_NO_FWD_F_OFFSET_MOD16 3
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_F_OFFSET       18
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_F_WIDTH        1
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_OFFSET         1
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_F_OFFSET_MOD8  2
#define BRIDGE_CFG_BRIDGE_AND_VLAN_LKP_MISS_ACTION_F_OFFSET_MOD16 2
#define BRIDGE_CFG_BRIDGE_AGGREGATION_EN_F_OFFSET                 17
#define BRIDGE_CFG_BRIDGE_AGGREGATION_EN_F_WIDTH                  1
#define BRIDGE_CFG_BRIDGE_AGGREGATION_EN_OFFSET                   1
#define BRIDGE_CFG_BRIDGE_AGGREGATION_EN_F_OFFSET_MOD8            1
#define BRIDGE_CFG_BRIDGE_AGGREGATION_EN_F_OFFSET_MOD16           1
#define BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_F_OFFSET              16
#define BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_F_WIDTH               1
#define BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_OFFSET                1
#define BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_F_OFFSET_MOD8         0
#define BRIDGE_CFG_BRIDGE_RESULTS_AVAILABLE_F_OFFSET_MOD16        0
#define BRIDGE_CFG_RES_OFFSET_F_OFFSET                            0
#define BRIDGE_CFG_RES_OFFSET_F_WIDTH                             16
#define BRIDGE_CFG_RES_OFFSET_OFFSET                              2
#define BRIDGE_AND_VLAN_LKP_CMD_VPORT_F_OFFSET                                 12
#define BRIDGE_AND_VLAN_LKP_CMD_VPORT_F_WIDTH                                  6
#define BRIDGE_AND_VLAN_LKP_CMD_VPORT_OFFSET                                   5
#define BRIDGE_AND_VLAN_LKP_CMD_VPORT_F_OFFSET_MOD8                            4
#define BRIDGE_AND_VLAN_LKP_CMD_VID_F_OFFSET                                   0
#define BRIDGE_AND_VLAN_LKP_CMD_VID_F_WIDTH                                    12
#define BRIDGE_AND_VLAN_LKP_CMD_VID_OFFSET                                     6

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	reserved2 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved  	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vport     	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid       	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	reserved2 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid       	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vport     	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved  	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_AND_VLAN_LKP_CMD_DTS;

#define RDD_BRIDGE_AND_VLAN_LKP_CMD_VPORT_READ_G(r, g, idx)              GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_CMD_DTS) + 4, 12, 6, r)
#define RDD_BRIDGE_AND_VLAN_LKP_CMD_VPORT_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_CMD_DTS) + 4, 12, 6, v)
#define RDD_BRIDGE_AND_VLAN_LKP_CMD_VPORT_READ(r, p)                     FIELD_MREAD_32((uint8_t *)p + 4, 12, 6, r)
#define RDD_BRIDGE_AND_VLAN_LKP_CMD_VPORT_WRITE(v, p)                    FIELD_MWRITE_32((uint8_t *)p + 4, 12, 6, v)
#define RDD_BRIDGE_AND_VLAN_LKP_CMD_VID_READ_G(r, g, idx)                GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_CMD_DTS) + 6, 0, 12, r)
#define RDD_BRIDGE_AND_VLAN_LKP_CMD_VID_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BRIDGE_AND_VLAN_LKP_CMD_DTS) + 6, 0, 12, v)
#define RDD_BRIDGE_AND_VLAN_LKP_CMD_VID_READ(r, p)                       FIELD_MREAD_16((uint8_t *)p + 6, 0, 12, r)
#define RDD_BRIDGE_AND_VLAN_LKP_CMD_VID_WRITE(v, p)                      FIELD_MWRITE_16((uint8_t *)p + 6, 0, 12, v)
#define BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_F_OFFSET                        13
#define BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_F_WIDTH                         1
#define BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_OFFSET                          2
#define BRIDGE_AND_VLAN_LKP_RESULT_AGGREGATION_EN_F_OFFSET_MOD8                   5
#define BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_F_OFFSET                     12
#define BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_F_WIDTH                      1
#define BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_OFFSET                       2
#define BRIDGE_AND_VLAN_LKP_RESULT_ARL_LOOKUP_METHOD_F_OFFSET_MOD8                4
#define BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_F_OFFSET                               0
#define BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_F_WIDTH                                12
#define BRIDGE_AND_VLAN_LKP_RESULT_WAN_VID_OFFSET                                 2
#define BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_F_OFFSET              24
#define BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_F_WIDTH               8
#define BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_OFFSET                4
#define BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_31_24_F_OFFSET_MOD16        8
#define BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_F_OFFSET               0
#define BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_F_WIDTH                24
#define BRIDGE_AND_VLAN_LKP_RESULT_PORT_ISOLATION_MAP_23_0_OFFSET                 4
#define BRIDGE_ARL_LKP_CMD_VID_F_OFFSET                                   16
#define BRIDGE_ARL_LKP_CMD_VID_F_WIDTH                                    12
#define BRIDGE_ARL_LKP_CMD_VID_OFFSET                                     0
#define BRIDGE_ARL_LKP_CMD_VID_F_OFFSET_MOD16                             0
#define BRIDGE_ARL_LKP_CMD_MAC_1_2_F_OFFSET                               0
#define BRIDGE_ARL_LKP_CMD_MAC_1_2_F_WIDTH                                16
#define BRIDGE_ARL_LKP_CMD_MAC_1_2_OFFSET                                 2
#define BRIDGE_ARL_LKP_CMD_MAC_3_6_F_OFFSET                               0
#define BRIDGE_ARL_LKP_CMD_MAC_3_6_F_WIDTH                                32
#define BRIDGE_ARL_LKP_CMD_MAC_3_6_OFFSET                                 4

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	reserved  	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid       	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_1_2   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_3_6   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	mac_1_2   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid       	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved  	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_3_6   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_ARL_LKP_CMD_DTS;

#define RDD_BRIDGE_ARL_LKP_CMD_VID_READ_G(r, g, idx)               GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_CMD_DTS), 0, 12, r)
#define RDD_BRIDGE_ARL_LKP_CMD_VID_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_CMD_DTS), 0, 12, v)
#define RDD_BRIDGE_ARL_LKP_CMD_VID_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_BRIDGE_ARL_LKP_CMD_VID_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#define RDD_BRIDGE_ARL_LKP_CMD_MAC_1_2_READ_G(r, g, idx)           GROUP_MREAD_16(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_CMD_DTS) + 2, r)
#define RDD_BRIDGE_ARL_LKP_CMD_MAC_1_2_WRITE_G(v, g, idx)          GROUP_MWRITE_16(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_CMD_DTS) + 2, v)
#define RDD_BRIDGE_ARL_LKP_CMD_MAC_1_2_READ(r, p)                  MREAD_16((uint8_t *)p + 2, r)
#define RDD_BRIDGE_ARL_LKP_CMD_MAC_1_2_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 2, v)
#define RDD_BRIDGE_ARL_LKP_CMD_MAC_3_6_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_CMD_DTS) + 4, r)
#define RDD_BRIDGE_ARL_LKP_CMD_MAC_3_6_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_CMD_DTS) + 4, v)
#define RDD_BRIDGE_ARL_LKP_CMD_MAC_3_6_READ(r, p)                  MREAD_32((uint8_t *)p + 4, r)
#define RDD_BRIDGE_ARL_LKP_CMD_MAC_3_6_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 4, v)
#define BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_F_OFFSET                       14
#define BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_F_WIDTH                        2
#define BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_OFFSET                         2
#define BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_F_OFFSET_MOD8                  6
#define BRIDGE_ARL_LKP_RESULT_VPORT_F_OFFSET                                 8
#define BRIDGE_ARL_LKP_RESULT_VPORT_F_WIDTH                                  6
#define BRIDGE_ARL_LKP_RESULT_VPORT_OFFSET                                   2
#define BRIDGE_ARL_LKP_RESULT_VPORT_F_OFFSET_MOD8                            0
#define BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_F_OFFSET                   7
#define BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_F_WIDTH                    1
#define BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_OFFSET                     3
#define BRIDGE_ARL_LKP_RESULT_LAN_VID_MSB_AND_DA_NO_FWD_ACTION_F_OFFSET      0
#define BRIDGE_ARL_LKP_RESULT_LAN_VID_MSB_AND_DA_NO_FWD_ACTION_F_WIDTH       4
#define BRIDGE_ARL_LKP_RESULT_LAN_VID_MSB_AND_DA_NO_FWD_ACTION_OFFSET        3
#define BRIDGE_ARL_LKP_RESULT_LAN_VID_8LSB_F_OFFSET                          24
#define BRIDGE_ARL_LKP_RESULT_LAN_VID_8LSB_F_WIDTH                           8
#define BRIDGE_ARL_LKP_RESULT_LAN_VID_8LSB_OFFSET                            4
#define BRIDGE_ARL_LKP_RESULT_LAN_VID_8LSB_F_OFFSET_MOD16                    8

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	reserved                 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sa_match_action          	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_action enumeration*/
	uint32_t	vport                    	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da_match_action_fwd      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lan_vid_msb_and_da_no_fwd_action	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = lan_vid_msb_and_da_no_fwd_action, size = 4 bits
	uint32_t	lan_vid_4msb             	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da_match_action_trap_drop	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	lan_vid_8lsb             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4                	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	lan_vid_msb_and_da_no_fwd_action	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = lan_vid_msb_and_da_no_fwd_action, size = 4 bits
	uint32_t	lan_vid_4msb             	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da_match_action_trap_drop	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	reserved2                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da_match_action_fwd      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vport                    	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sa_match_action          	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_action enumeration*/
	uint32_t	reserved                 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4                	:24	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	lan_vid_8lsb             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_ARL_LKP_RESULT_DTS;

#define RDD_BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 2, 6, 2, r) /*defined by rdd_action enumeration*/
#define RDD_BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 2, 6, 2, v) /*defined by rdd_action enumeration*/
#define RDD_BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p + 2, 6, 2, r) /*defined by rdd_action enumeration*/
#define RDD_BRIDGE_ARL_LKP_RESULT_SA_MATCH_ACTION_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p + 2, 6, 2, v) /*defined by rdd_action enumeration*/
#define RDD_BRIDGE_ARL_LKP_RESULT_VPORT_READ_G(r, g, idx)                              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 2, 0, 6, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_VPORT_WRITE_G(v, g, idx)                             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 2, 0, 6, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_VPORT_READ(r, p)                                     FIELD_MREAD_8((uint8_t *)p + 2, 0, 6, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_VPORT_WRITE(v, p)                                    FIELD_MWRITE_8((uint8_t *)p + 2, 0, 6, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 3, 7, 1, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 3, 7, 1, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 3, 7, 1, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_FWD_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 3, 7, 1, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_MSB_AND_DA_NO_FWD_ACTION_READ_G(r, g, idx)   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 3, 0, 4, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_MSB_AND_DA_NO_FWD_ACTION_WRITE_G(v, g, idx)  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 3, 0, 4, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_MSB_AND_DA_NO_FWD_ACTION_READ(r, p)          FIELD_MREAD_8((uint8_t *)p + 3, 0, 4, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_MSB_AND_DA_NO_FWD_ACTION_WRITE(v, p)         FIELD_MWRITE_8((uint8_t *)p + 3, 0, 4, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_4MSB_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 3, 0, 4, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_4MSB_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 3, 0, 4, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_4MSB_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 3, 0, 4, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_4MSB_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 3, 0, 4, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_TRAP_DROP_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 3, 0, 1, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_TRAP_DROP_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 3, 0, 1, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_TRAP_DROP_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 3, 0, 1, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_DA_MATCH_ACTION_TRAP_DROP_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 3, 0, 1, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_8LSB_READ_G(r, g, idx)                       GROUP_MREAD_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 4, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_8LSB_WRITE_G(v, g, idx)                      GROUP_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_ARL_LKP_RESULT_DTS) + 4, v)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_8LSB_READ(r, p)                              MREAD_8((uint8_t *)p + 4, r)
#define RDD_BRIDGE_ARL_LKP_RESULT_LAN_VID_8LSB_WRITE(v, p)                             MWRITE_8((uint8_t *)p + 4, v)
#define BRIDGE_CLASSIFICATION_RESULT_HIT_F_OFFSET                                   31
#define BRIDGE_CLASSIFICATION_RESULT_HIT_F_WIDTH                                    1
#define BRIDGE_CLASSIFICATION_RESULT_HIT_OFFSET                                     0
#define BRIDGE_CLASSIFICATION_RESULT_HIT_F_OFFSET_MOD8                              7
#define BRIDGE_CLASSIFICATION_RESULT_HIT_F_OFFSET_MOD16                             15
#define BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_F_OFFSET                      30
#define BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_F_WIDTH                       1
#define BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_OFFSET                        0
#define BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_F_OFFSET_MOD8                 6
#define BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_F_OFFSET_MOD16                14
#define BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_F_OFFSET                      29
#define BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_F_WIDTH                       1
#define BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_OFFSET                        0
#define BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_F_OFFSET_MOD8                 5
#define BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_F_OFFSET_MOD16                13
#define BRIDGE_CLASSIFICATION_RESULT_EGRESS_VID_F_OFFSET                            16
#define BRIDGE_CLASSIFICATION_RESULT_EGRESS_VID_F_WIDTH                             12
#define BRIDGE_CLASSIFICATION_RESULT_EGRESS_VID_OFFSET                              0
#define BRIDGE_CLASSIFICATION_RESULT_EGRESS_VID_F_OFFSET_MOD16                      0
#define BRIDGE_CLASSIFICATION_RESULT_EGRESS_VPORT_F_OFFSET                          0
#define BRIDGE_CLASSIFICATION_RESULT_EGRESS_VPORT_F_WIDTH                           6
#define BRIDGE_CLASSIFICATION_RESULT_EGRESS_VPORT_OFFSET                            3

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	hit             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_fw_failed	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_aggregation	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_vid      	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2       	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_vport    	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	egress_vport    	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2       	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	egress_vid      	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlan_aggregation	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bridge_fw_failed	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hit             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_BRIDGE_CLASSIFICATION_RESULT_DTS;

#define RDD_BRIDGE_CLASSIFICATION_RESULT_HIT_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS), 7, 1, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_HIT_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS), 7, 1, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_HIT_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_HIT_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS), 6, 1, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS), 6, 1, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_BRIDGE_FW_FAILED_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS), 5, 1, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS), 5, 1, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_VLAN_AGGREGATION_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_EGRESS_VID_READ_G(r, g, idx)                GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS), 0, 12, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_EGRESS_VID_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS), 0, 12, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_EGRESS_VID_READ(r, p)                       FIELD_MREAD_16((uint8_t *)p, 0, 12, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_EGRESS_VID_WRITE(v, p)                      FIELD_MWRITE_16((uint8_t *)p, 0, 12, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_EGRESS_VPORT_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS) + 3, 0, 6, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_EGRESS_VPORT_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_BRIDGE_CLASSIFICATION_RESULT_DTS) + 3, 0, 6, v)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_EGRESS_VPORT_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 3, 0, 6, r)
#define RDD_BRIDGE_CLASSIFICATION_RESULT_EGRESS_VPORT_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 3, 0, 6, v)
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_EGRESS_PORTS_VECTOR_F_OFFSET                   0
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_EGRESS_PORTS_VECTOR_F_WIDTH                    32
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_EGRESS_PORTS_VECTOR_OFFSET                     0
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_IPTV_REPL_0_SOP_F_OFFSET                       24
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_IPTV_REPL_0_SOP_F_WIDTH                        8
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_IPTV_REPL_0_SOP_OFFSET                         4
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_IPTV_REPL_0_SOP_F_OFFSET_MOD16                 8
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_F_OFFSET                              22
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_F_WIDTH                               2
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_OFFSET                                5
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_F_OFFSET_MOD8                         6
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_F_OFFSET_MOD16                        6
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_F_OFFSET                          16
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_F_WIDTH                           6
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_OFFSET                            5
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_F_OFFSET_MOD8                     0
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_F_OFFSET_MOD16                    0
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_TC_F_OFFSET                                    0
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_TC_F_WIDTH                                     3
#define PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_TC_OFFSET                                      7

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	egress_ports_vector	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	iptv_repl_0_sop    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pool_num           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	replications       	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1          	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc                 	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	egress_ports_vector	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tc                 	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1          	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	replications       	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pool_num           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	iptv_repl_0_sop    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS;

#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_EGRESS_PORTS_VECTOR_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS), r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_EGRESS_PORTS_VECTOR_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS), v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_EGRESS_PORTS_VECTOR_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_EGRESS_PORTS_VECTOR_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_IPTV_REPL_0_SOP_READ_G(r, g, idx)              GROUP_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS) + 4, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_IPTV_REPL_0_SOP_WRITE_G(v, g, idx)             GROUP_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS) + 4, v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_IPTV_REPL_0_SOP_READ(r, p)                     MREAD_8((uint8_t *)p + 4, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_IPTV_REPL_0_SOP_WRITE(v, p)                    MWRITE_8((uint8_t *)p + 4, v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS) + 5, 6, 2, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS) + 5, 6, 2, v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 5, 6, 2, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_POOL_NUM_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 5, 6, 2, v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS) + 5, 0, 6, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS) + 5, 0, 6, v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 5, 0, 6, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_REPLICATIONS_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 5, 0, 6, v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_TC_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS) + 7, 0, 3, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_TC_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_DTS) + 7, 0, 3, v)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_TC_READ(r, p)                                  FIELD_MREAD_8((uint8_t *)p + 7, 0, 3, r)
#define RDD_PACKET_BUFFER_RESOLUTION_MCAST_ENTRY_TC_WRITE(v, p)                                 FIELD_MWRITE_8((uint8_t *)p + 7, 0, 3, v)
#define MIRRORING_DESCRIPTOR_MIRROR_EN_F_OFFSET                             15
#define MIRRORING_DESCRIPTOR_MIRROR_EN_F_WIDTH                              1
#define MIRRORING_DESCRIPTOR_MIRROR_EN_OFFSET                               0
#define MIRRORING_DESCRIPTOR_MIRROR_EN_F_OFFSET_MOD8                        7
#define MIRRORING_DESCRIPTOR_DST_VPORT_F_OFFSET                             9
#define MIRRORING_DESCRIPTOR_DST_VPORT_F_WIDTH                              6
#define MIRRORING_DESCRIPTOR_DST_VPORT_OFFSET                               0
#define MIRRORING_DESCRIPTOR_DST_VPORT_F_OFFSET_MOD8                        1
#define MIRRORING_DESCRIPTOR_DST_QUEUE_F_OFFSET                             0
#define MIRRORING_DESCRIPTOR_DST_QUEUE_F_WIDTH                              9
#define MIRRORING_DESCRIPTOR_DST_QUEUE_OFFSET                               0
#define PARSER_SUMMARY_DA_FILTER_MATCH_F_OFFSET                       31
#define PARSER_SUMMARY_DA_FILTER_MATCH_F_WIDTH                        1
#define PARSER_SUMMARY_DA_FILTER_MATCH_OFFSET                         0
#define PARSER_SUMMARY_DA_FILTER_MATCH_F_OFFSET_MOD8                  7
#define PARSER_SUMMARY_DA_FILTER_MATCH_F_OFFSET_MOD16                 15
#define PARSER_SUMMARY_FIRST_IP_FRAGMENT_F_OFFSET                     30
#define PARSER_SUMMARY_FIRST_IP_FRAGMENT_F_WIDTH                      1
#define PARSER_SUMMARY_FIRST_IP_FRAGMENT_OFFSET                       0
#define PARSER_SUMMARY_FIRST_IP_FRAGMENT_F_OFFSET_MOD8                6
#define PARSER_SUMMARY_FIRST_IP_FRAGMENT_F_OFFSET_MOD16               14
#define PARSER_SUMMARY_IP_FRAGMENT_F_OFFSET                           29
#define PARSER_SUMMARY_IP_FRAGMENT_F_WIDTH                            1
#define PARSER_SUMMARY_IP_FRAGMENT_OFFSET                             0
#define PARSER_SUMMARY_IP_FRAGMENT_F_OFFSET_MOD8                      5
#define PARSER_SUMMARY_IP_FRAGMENT_F_OFFSET_MOD16                     13
#define PARSER_SUMMARY_IP_FILTER_MATCH_F_OFFSET                       28
#define PARSER_SUMMARY_IP_FILTER_MATCH_F_WIDTH                        1
#define PARSER_SUMMARY_IP_FILTER_MATCH_OFFSET                         0
#define PARSER_SUMMARY_IP_FILTER_MATCH_F_OFFSET_MOD8                  4
#define PARSER_SUMMARY_IP_FILTER_MATCH_F_OFFSET_MOD16                 12
#define PARSER_SUMMARY_IP_FILTER_NUM_F_OFFSET                         26
#define PARSER_SUMMARY_IP_FILTER_NUM_F_WIDTH                          2
#define PARSER_SUMMARY_IP_FILTER_NUM_OFFSET                           0
#define PARSER_SUMMARY_IP_FILTER_NUM_F_OFFSET_MOD8                    2
#define PARSER_SUMMARY_IP_FILTER_NUM_F_OFFSET_MOD16                   10
#define PARSER_SUMMARY_TCP_UDP_F_OFFSET                               25
#define PARSER_SUMMARY_TCP_UDP_F_WIDTH                                1
#define PARSER_SUMMARY_TCP_UDP_OFFSET                                 0
#define PARSER_SUMMARY_TCP_UDP_F_OFFSET_MOD8                          1
#define PARSER_SUMMARY_TCP_UDP_F_OFFSET_MOD16                         9
#define PARSER_SUMMARY_IPV6_EXT_HEADER_F_OFFSET                       24
#define PARSER_SUMMARY_IPV6_EXT_HEADER_F_WIDTH                        1
#define PARSER_SUMMARY_IPV6_EXT_HEADER_OFFSET                         0
#define PARSER_SUMMARY_IPV6_EXT_HEADER_F_OFFSET_MOD8                  0
#define PARSER_SUMMARY_IPV6_EXT_HEADER_F_OFFSET_MOD16                 8
#define PARSER_SUMMARY_TCP_FLAG_F_OFFSET                              23
#define PARSER_SUMMARY_TCP_FLAG_F_WIDTH                               1
#define PARSER_SUMMARY_TCP_FLAG_OFFSET                                1
#define PARSER_SUMMARY_TCP_FLAG_F_OFFSET_MOD8                         7
#define PARSER_SUMMARY_TCP_FLAG_F_OFFSET_MOD16                        7
#define PARSER_SUMMARY_P_TAG_F_OFFSET                                 22
#define PARSER_SUMMARY_P_TAG_F_WIDTH                                  1
#define PARSER_SUMMARY_P_TAG_OFFSET                                   1
#define PARSER_SUMMARY_P_TAG_F_OFFSET_MOD8                            6
#define PARSER_SUMMARY_P_TAG_F_OFFSET_MOD16                           6
#define PARSER_SUMMARY_VID_FILTER_HIT_F_OFFSET                        21
#define PARSER_SUMMARY_VID_FILTER_HIT_F_WIDTH                         1
#define PARSER_SUMMARY_VID_FILTER_HIT_OFFSET                          1
#define PARSER_SUMMARY_VID_FILTER_HIT_F_OFFSET_MOD8                   5
#define PARSER_SUMMARY_VID_FILTER_HIT_F_OFFSET_MOD16                  5
#define PARSER_SUMMARY_EXCEPTION_F_OFFSET                             20
#define PARSER_SUMMARY_EXCEPTION_F_WIDTH                              1
#define PARSER_SUMMARY_EXCEPTION_OFFSET                               1
#define PARSER_SUMMARY_EXCEPTION_F_OFFSET_MOD8                        4
#define PARSER_SUMMARY_EXCEPTION_F_OFFSET_MOD16                       4
#define PARSER_SUMMARY_DA_FILTER_NUMBER_F_OFFSET                      16
#define PARSER_SUMMARY_DA_FILTER_NUMBER_F_WIDTH                       4
#define PARSER_SUMMARY_DA_FILTER_NUMBER_OFFSET                        1
#define PARSER_SUMMARY_DA_FILTER_NUMBER_F_OFFSET_MOD8                 0
#define PARSER_SUMMARY_DA_FILTER_NUMBER_F_OFFSET_MOD16                0
#define PARSER_SUMMARY_L4_PROTOCOL_F_OFFSET                           12
#define PARSER_SUMMARY_L4_PROTOCOL_F_WIDTH                            4
#define PARSER_SUMMARY_L4_PROTOCOL_OFFSET                             2
#define PARSER_SUMMARY_L4_PROTOCOL_F_OFFSET_MOD8                      4
#define PARSER_SUMMARY__5_TUP_VALID_F_OFFSET                          11
#define PARSER_SUMMARY__5_TUP_VALID_F_WIDTH                           1
#define PARSER_SUMMARY__5_TUP_VALID_OFFSET                            2
#define PARSER_SUMMARY__5_TUP_VALID_F_OFFSET_MOD8                     3
#define PARSER_SUMMARY_DHCP_F_OFFSET                                  10
#define PARSER_SUMMARY_DHCP_F_WIDTH                                   1
#define PARSER_SUMMARY_DHCP_OFFSET                                    2
#define PARSER_SUMMARY_DHCP_F_OFFSET_MOD8                             2
#define PARSER_SUMMARY_VLANS_NUM_F_OFFSET                             8
#define PARSER_SUMMARY_VLANS_NUM_F_WIDTH                              2
#define PARSER_SUMMARY_VLANS_NUM_OFFSET                               2
#define PARSER_SUMMARY_VLANS_NUM_F_OFFSET_MOD8                        0
#define PARSER_SUMMARY_BROADCAST_F_OFFSET                             7
#define PARSER_SUMMARY_BROADCAST_F_WIDTH                              1
#define PARSER_SUMMARY_BROADCAST_OFFSET                               3
#define PARSER_SUMMARY_MULTICAST_F_OFFSET                             6
#define PARSER_SUMMARY_MULTICAST_F_WIDTH                              1
#define PARSER_SUMMARY_MULTICAST_OFFSET                               3
#define PARSER_SUMMARY_L3_PROTOCOL_F_OFFSET                           4
#define PARSER_SUMMARY_L3_PROTOCOL_F_WIDTH                            2
#define PARSER_SUMMARY_L3_PROTOCOL_OFFSET                             3
#define PARSER_SUMMARY_L2_PROTOCOL_F_OFFSET                           0
#define PARSER_SUMMARY_L2_PROTOCOL_F_WIDTH                            4
#define PARSER_SUMMARY_L2_PROTOCOL_OFFSET                             3

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	da_filter_match  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	first_ip_fragment	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_fragment      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_filter_match  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_filter_num    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv6_ext_header  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_flag         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	p_tag            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid_filter_hit   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	exception        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da_filter_number 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l4_protocol      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_parser_l4_protocol enumeration*/
	uint32_t	_5_tup_valid     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhcp             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlans_num        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	broadcast        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l3_protocol      	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_parser_l3_protocol enumeration*/
	uint32_t	l2_protocol      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	l2_protocol      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l3_protocol      	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_parser_l3_protocol enumeration*/
	uint32_t	multicast        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	broadcast        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlans_num        	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhcp             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_5_tup_valid     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	l4_protocol      	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_parser_l4_protocol enumeration*/
	uint32_t	da_filter_number 	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	exception        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid_filter_hit   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	p_tag            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_flag         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv6_ext_header  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_filter_num    	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_filter_match  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_fragment      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	first_ip_fragment	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da_filter_match  	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PARSER_SUMMARY_DTS;

#define RDD_PARSER_SUMMARY_DA_FILTER_MATCH_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 7, 1, r)
#define RDD_PARSER_SUMMARY_DA_FILTER_MATCH_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 7, 1, v)
#define RDD_PARSER_SUMMARY_DA_FILTER_MATCH_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_PARSER_SUMMARY_DA_FILTER_MATCH_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_PARSER_SUMMARY_FIRST_IP_FRAGMENT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 6, 1, r)
#define RDD_PARSER_SUMMARY_FIRST_IP_FRAGMENT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 6, 1, v)
#define RDD_PARSER_SUMMARY_FIRST_IP_FRAGMENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_PARSER_SUMMARY_FIRST_IP_FRAGMENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_PARSER_SUMMARY_IP_FRAGMENT_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 5, 1, r)
#define RDD_PARSER_SUMMARY_IP_FRAGMENT_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 5, 1, v)
#define RDD_PARSER_SUMMARY_IP_FRAGMENT_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_PARSER_SUMMARY_IP_FRAGMENT_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_PARSER_SUMMARY_IP_FILTER_MATCH_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 4, 1, r)
#define RDD_PARSER_SUMMARY_IP_FILTER_MATCH_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 4, 1, v)
#define RDD_PARSER_SUMMARY_IP_FILTER_MATCH_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_PARSER_SUMMARY_IP_FILTER_MATCH_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_PARSER_SUMMARY_IP_FILTER_NUM_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 2, 2, r)
#define RDD_PARSER_SUMMARY_IP_FILTER_NUM_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 2, 2, v)
#define RDD_PARSER_SUMMARY_IP_FILTER_NUM_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 2, 2, r)
#define RDD_PARSER_SUMMARY_IP_FILTER_NUM_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 2, 2, v)
#define RDD_PARSER_SUMMARY_TCP_UDP_READ_G(r, g, idx)                    GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 1, 1, r)
#define RDD_PARSER_SUMMARY_TCP_UDP_WRITE_G(v, g, idx)                   GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 1, 1, v)
#define RDD_PARSER_SUMMARY_TCP_UDP_READ(r, p)                           FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_PARSER_SUMMARY_TCP_UDP_WRITE(v, p)                          FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_PARSER_SUMMARY_IPV6_EXT_HEADER_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 0, 1, r)
#define RDD_PARSER_SUMMARY_IPV6_EXT_HEADER_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS), 0, 1, v)
#define RDD_PARSER_SUMMARY_IPV6_EXT_HEADER_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_PARSER_SUMMARY_IPV6_EXT_HEADER_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_PARSER_SUMMARY_TCP_FLAG_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 7, 1, r)
#define RDD_PARSER_SUMMARY_TCP_FLAG_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 7, 1, v)
#define RDD_PARSER_SUMMARY_TCP_FLAG_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 1, 7, 1, r)
#define RDD_PARSER_SUMMARY_TCP_FLAG_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 1, 7, 1, v)
#define RDD_PARSER_SUMMARY_P_TAG_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 6, 1, r)
#define RDD_PARSER_SUMMARY_P_TAG_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 6, 1, v)
#define RDD_PARSER_SUMMARY_P_TAG_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 1, 6, 1, r)
#define RDD_PARSER_SUMMARY_P_TAG_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 1, 6, 1, v)
#define RDD_PARSER_SUMMARY_VID_FILTER_HIT_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 5, 1, r)
#define RDD_PARSER_SUMMARY_VID_FILTER_HIT_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 5, 1, v)
#define RDD_PARSER_SUMMARY_VID_FILTER_HIT_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 1, 5, 1, r)
#define RDD_PARSER_SUMMARY_VID_FILTER_HIT_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 1, 5, 1, v)
#define RDD_PARSER_SUMMARY_EXCEPTION_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 4, 1, r)
#define RDD_PARSER_SUMMARY_EXCEPTION_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 4, 1, v)
#define RDD_PARSER_SUMMARY_EXCEPTION_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 1, 4, 1, r)
#define RDD_PARSER_SUMMARY_EXCEPTION_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 1, 4, 1, v)
#define RDD_PARSER_SUMMARY_DA_FILTER_NUMBER_READ_G(r, g, idx)           GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 0, 4, r)
#define RDD_PARSER_SUMMARY_DA_FILTER_NUMBER_WRITE_G(v, g, idx)          GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 1, 0, 4, v)
#define RDD_PARSER_SUMMARY_DA_FILTER_NUMBER_READ(r, p)                  FIELD_MREAD_8((uint8_t *)p + 1, 0, 4, r)
#define RDD_PARSER_SUMMARY_DA_FILTER_NUMBER_WRITE(v, p)                 FIELD_MWRITE_8((uint8_t *)p + 1, 0, 4, v)
#define RDD_PARSER_SUMMARY_L4_PROTOCOL_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 2, 4, 4, r) /*defined by rdd_parser_l4_protocol enumeration*/
#define RDD_PARSER_SUMMARY_L4_PROTOCOL_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 2, 4, 4, v) /*defined by rdd_parser_l4_protocol enumeration*/
#define RDD_PARSER_SUMMARY_L4_PROTOCOL_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 2, 4, 4, r) /*defined by rdd_parser_l4_protocol enumeration*/
#define RDD_PARSER_SUMMARY_L4_PROTOCOL_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 2, 4, 4, v) /*defined by rdd_parser_l4_protocol enumeration*/
#define RDD_PARSER_SUMMARY__5_TUP_VALID_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 2, 3, 1, r)
#define RDD_PARSER_SUMMARY__5_TUP_VALID_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 2, 3, 1, v)
#define RDD_PARSER_SUMMARY__5_TUP_VALID_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 2, 3, 1, r)
#define RDD_PARSER_SUMMARY__5_TUP_VALID_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 2, 3, 1, v)
#define RDD_PARSER_SUMMARY_DHCP_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 2, 2, 1, r)
#define RDD_PARSER_SUMMARY_DHCP_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 2, 2, 1, v)
#define RDD_PARSER_SUMMARY_DHCP_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 2, 2, 1, r)
#define RDD_PARSER_SUMMARY_DHCP_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 2, 2, 1, v)
#define RDD_PARSER_SUMMARY_VLANS_NUM_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 2, 0, 2, r)
#define RDD_PARSER_SUMMARY_VLANS_NUM_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 2, 0, 2, v)
#define RDD_PARSER_SUMMARY_VLANS_NUM_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 2, 0, 2, r)
#define RDD_PARSER_SUMMARY_VLANS_NUM_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 2, 0, 2, v)
#define RDD_PARSER_SUMMARY_BROADCAST_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 3, 7, 1, r)
#define RDD_PARSER_SUMMARY_BROADCAST_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 3, 7, 1, v)
#define RDD_PARSER_SUMMARY_BROADCAST_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 3, 7, 1, r)
#define RDD_PARSER_SUMMARY_BROADCAST_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 3, 7, 1, v)
#define RDD_PARSER_SUMMARY_MULTICAST_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 3, 6, 1, r)
#define RDD_PARSER_SUMMARY_MULTICAST_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 3, 6, 1, v)
#define RDD_PARSER_SUMMARY_MULTICAST_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 3, 6, 1, r)
#define RDD_PARSER_SUMMARY_MULTICAST_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 3, 6, 1, v)
#define RDD_PARSER_SUMMARY_L3_PROTOCOL_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 3, 4, 2, r) /*defined by rdd_parser_l3_protocol enumeration*/
#define RDD_PARSER_SUMMARY_L3_PROTOCOL_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 3, 4, 2, v) /*defined by rdd_parser_l3_protocol enumeration*/
#define RDD_PARSER_SUMMARY_L3_PROTOCOL_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 3, 4, 2, r) /*defined by rdd_parser_l3_protocol enumeration*/
#define RDD_PARSER_SUMMARY_L3_PROTOCOL_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 3, 4, 2, v) /*defined by rdd_parser_l3_protocol enumeration*/
#define RDD_PARSER_SUMMARY_L2_PROTOCOL_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 3, 0, 4, r)
#define RDD_PARSER_SUMMARY_L2_PROTOCOL_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_SUMMARY_DTS) + 3, 0, 4, v)
#define RDD_PARSER_SUMMARY_L2_PROTOCOL_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 3, 0, 4, r)
#define RDD_PARSER_SUMMARY_L2_PROTOCOL_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 3, 0, 4, v)
#define PARSER_RESULT_DA_FILTER_MATCH_F_OFFSET                       31
#define PARSER_RESULT_DA_FILTER_MATCH_F_WIDTH                        1
#define PARSER_RESULT_DA_FILTER_MATCH_OFFSET                         0
#define PARSER_RESULT_DA_FILTER_MATCH_F_OFFSET_MOD8                  7
#define PARSER_RESULT_DA_FILTER_MATCH_F_OFFSET_MOD16                 15
#define PARSER_RESULT_FIRST_IP_FRAGMENT_F_OFFSET                     30
#define PARSER_RESULT_FIRST_IP_FRAGMENT_F_WIDTH                      1
#define PARSER_RESULT_FIRST_IP_FRAGMENT_OFFSET                       0
#define PARSER_RESULT_FIRST_IP_FRAGMENT_F_OFFSET_MOD8                6
#define PARSER_RESULT_FIRST_IP_FRAGMENT_F_OFFSET_MOD16               14
#define PARSER_RESULT_IP_FRAGMENT_F_OFFSET                           29
#define PARSER_RESULT_IP_FRAGMENT_F_WIDTH                            1
#define PARSER_RESULT_IP_FRAGMENT_OFFSET                             0
#define PARSER_RESULT_IP_FRAGMENT_F_OFFSET_MOD8                      5
#define PARSER_RESULT_IP_FRAGMENT_F_OFFSET_MOD16                     13
#define PARSER_RESULT_IP_FILTER_MATCH_F_OFFSET                       28
#define PARSER_RESULT_IP_FILTER_MATCH_F_WIDTH                        1
#define PARSER_RESULT_IP_FILTER_MATCH_OFFSET                         0
#define PARSER_RESULT_IP_FILTER_MATCH_F_OFFSET_MOD8                  4
#define PARSER_RESULT_IP_FILTER_MATCH_F_OFFSET_MOD16                 12
#define PARSER_RESULT_IP_FILTER_NUM_F_OFFSET                         26
#define PARSER_RESULT_IP_FILTER_NUM_F_WIDTH                          2
#define PARSER_RESULT_IP_FILTER_NUM_OFFSET                           0
#define PARSER_RESULT_IP_FILTER_NUM_F_OFFSET_MOD8                    2
#define PARSER_RESULT_IP_FILTER_NUM_F_OFFSET_MOD16                   10
#define PARSER_RESULT_TCP_UDP_F_OFFSET                               25
#define PARSER_RESULT_TCP_UDP_F_WIDTH                                1
#define PARSER_RESULT_TCP_UDP_OFFSET                                 0
#define PARSER_RESULT_TCP_UDP_F_OFFSET_MOD8                          1
#define PARSER_RESULT_TCP_UDP_F_OFFSET_MOD16                         9
#define PARSER_RESULT_IPV6_EXT_HEADER_F_OFFSET                       24
#define PARSER_RESULT_IPV6_EXT_HEADER_F_WIDTH                        1
#define PARSER_RESULT_IPV6_EXT_HEADER_OFFSET                         0
#define PARSER_RESULT_IPV6_EXT_HEADER_F_OFFSET_MOD8                  0
#define PARSER_RESULT_IPV6_EXT_HEADER_F_OFFSET_MOD16                 8
#define PARSER_RESULT_TCP_FLAG_F_OFFSET                              23
#define PARSER_RESULT_TCP_FLAG_F_WIDTH                               1
#define PARSER_RESULT_TCP_FLAG_OFFSET                                1
#define PARSER_RESULT_TCP_FLAG_F_OFFSET_MOD8                         7
#define PARSER_RESULT_TCP_FLAG_F_OFFSET_MOD16                        7
#define PARSER_RESULT_P_TAG_F_OFFSET                                 22
#define PARSER_RESULT_P_TAG_F_WIDTH                                  1
#define PARSER_RESULT_P_TAG_OFFSET                                   1
#define PARSER_RESULT_P_TAG_F_OFFSET_MOD8                            6
#define PARSER_RESULT_P_TAG_F_OFFSET_MOD16                           6
#define PARSER_RESULT_VID_FILTER_HIT_F_OFFSET                        21
#define PARSER_RESULT_VID_FILTER_HIT_F_WIDTH                         1
#define PARSER_RESULT_VID_FILTER_HIT_OFFSET                          1
#define PARSER_RESULT_VID_FILTER_HIT_F_OFFSET_MOD8                   5
#define PARSER_RESULT_VID_FILTER_HIT_F_OFFSET_MOD16                  5
#define PARSER_RESULT_EXCEPTION_F_OFFSET                             20
#define PARSER_RESULT_EXCEPTION_F_WIDTH                              1
#define PARSER_RESULT_EXCEPTION_OFFSET                               1
#define PARSER_RESULT_EXCEPTION_F_OFFSET_MOD8                        4
#define PARSER_RESULT_EXCEPTION_F_OFFSET_MOD16                       4
#define PARSER_RESULT_DA_FILTER_NUMBER_F_OFFSET                      16
#define PARSER_RESULT_DA_FILTER_NUMBER_F_WIDTH                       4
#define PARSER_RESULT_DA_FILTER_NUMBER_OFFSET                        1
#define PARSER_RESULT_DA_FILTER_NUMBER_F_OFFSET_MOD8                 0
#define PARSER_RESULT_DA_FILTER_NUMBER_F_OFFSET_MOD16                0
#define PARSER_RESULT_LAYER4_PROTOCOL_F_OFFSET                       12
#define PARSER_RESULT_LAYER4_PROTOCOL_F_WIDTH                        4
#define PARSER_RESULT_LAYER4_PROTOCOL_OFFSET                         2
#define PARSER_RESULT_LAYER4_PROTOCOL_F_OFFSET_MOD8                  4
#define PARSER_RESULT__5_TUP_VALID_F_OFFSET                          11
#define PARSER_RESULT__5_TUP_VALID_F_WIDTH                           1
#define PARSER_RESULT__5_TUP_VALID_OFFSET                            2
#define PARSER_RESULT__5_TUP_VALID_F_OFFSET_MOD8                     3
#define PARSER_RESULT_DHCP_F_OFFSET                                  10
#define PARSER_RESULT_DHCP_F_WIDTH                                   1
#define PARSER_RESULT_DHCP_OFFSET                                    2
#define PARSER_RESULT_DHCP_F_OFFSET_MOD8                             2
#define PARSER_RESULT_VLANS_NUM_F_OFFSET                             8
#define PARSER_RESULT_VLANS_NUM_F_WIDTH                              2
#define PARSER_RESULT_VLANS_NUM_OFFSET                               2
#define PARSER_RESULT_VLANS_NUM_F_OFFSET_MOD8                        0
#define PARSER_RESULT_BROADCAST_F_OFFSET                             7
#define PARSER_RESULT_BROADCAST_F_WIDTH                              1
#define PARSER_RESULT_BROADCAST_OFFSET                               3
#define PARSER_RESULT_MULTICAST_F_OFFSET                             6
#define PARSER_RESULT_MULTICAST_F_WIDTH                              1
#define PARSER_RESULT_MULTICAST_OFFSET                               3
#define PARSER_RESULT_LAYER3_PROTOCOL_F_OFFSET                       4
#define PARSER_RESULT_LAYER3_PROTOCOL_F_WIDTH                        2
#define PARSER_RESULT_LAYER3_PROTOCOL_OFFSET                         3
#define PARSER_RESULT_LAYER2_PROTOCOL_F_OFFSET                       0
#define PARSER_RESULT_LAYER2_PROTOCOL_F_WIDTH                        4
#define PARSER_RESULT_LAYER2_PROTOCOL_OFFSET                         3
#define PARSER_RESULT_TAG_TYPE_F_OFFSET                              30
#define PARSER_RESULT_TAG_TYPE_F_WIDTH                               2
#define PARSER_RESULT_TAG_TYPE_OFFSET                                4
#define PARSER_RESULT_TAG_TYPE_F_OFFSET_MOD8                         6
#define PARSER_RESULT_TAG_TYPE_F_OFFSET_MOD16                        14
#define PARSER_RESULT_MAC_SPOOF_F_OFFSET                             29
#define PARSER_RESULT_MAC_SPOOF_F_WIDTH                              1
#define PARSER_RESULT_MAC_SPOOF_OFFSET                               4
#define PARSER_RESULT_MAC_SPOOF_F_OFFSET_MOD8                        5
#define PARSER_RESULT_MAC_SPOOF_F_OFFSET_MOD16                       13
#define PARSER_RESULT_TPID_VLAN_0_F_OFFSET                           26
#define PARSER_RESULT_TPID_VLAN_0_F_WIDTH                            3
#define PARSER_RESULT_TPID_VLAN_0_OFFSET                             4
#define PARSER_RESULT_TPID_VLAN_0_F_OFFSET_MOD8                      2
#define PARSER_RESULT_TPID_VLAN_0_F_OFFSET_MOD16                     10
#define PARSER_RESULT_TPID_VLAN_1_F_OFFSET                           23
#define PARSER_RESULT_TPID_VLAN_1_F_WIDTH                            3
#define PARSER_RESULT_TPID_VLAN_1_OFFSET                             4
#define PARSER_RESULT_TPID_VLAN_1_F_OFFSET_MOD8                      7
#define PARSER_RESULT_TPID_VLAN_1_F_OFFSET_MOD16                     7
#define PARSER_RESULT_TPID_VLAN_2_F_OFFSET                           20
#define PARSER_RESULT_TPID_VLAN_2_F_WIDTH                            3
#define PARSER_RESULT_TPID_VLAN_2_OFFSET                             5
#define PARSER_RESULT_TPID_VLAN_2_F_OFFSET_MOD8                      4
#define PARSER_RESULT_TPID_VLAN_2_F_OFFSET_MOD16                     4
#define PARSER_RESULT_IN_CFI_F_OFFSET                                19
#define PARSER_RESULT_IN_CFI_F_WIDTH                                 1
#define PARSER_RESULT_IN_CFI_OFFSET                                  5
#define PARSER_RESULT_IN_CFI_F_OFFSET_MOD8                           3
#define PARSER_RESULT_IN_CFI_F_OFFSET_MOD16                          3
#define PARSER_RESULT_OUT_CFI_F_OFFSET                               18
#define PARSER_RESULT_OUT_CFI_F_WIDTH                                1
#define PARSER_RESULT_OUT_CFI_OFFSET                                 5
#define PARSER_RESULT_OUT_CFI_F_OFFSET_MOD8                          2
#define PARSER_RESULT_OUT_CFI_F_OFFSET_MOD16                         2
#define PARSER_RESULT_NO_OUTER_F_OFFSET                              17
#define PARSER_RESULT_NO_OUTER_F_WIDTH                               1
#define PARSER_RESULT_NO_OUTER_OFFSET                                5
#define PARSER_RESULT_NO_OUTER_F_OFFSET_MOD8                         1
#define PARSER_RESULT_NO_OUTER_F_OFFSET_MOD16                        1
#define PARSER_RESULT_NO_INNER_F_OFFSET                              16
#define PARSER_RESULT_NO_INNER_F_WIDTH                               1
#define PARSER_RESULT_NO_INNER_OFFSET                                5
#define PARSER_RESULT_NO_INNER_F_OFFSET_MOD8                         0
#define PARSER_RESULT_NO_INNER_F_OFFSET_MOD16                        0
#define PARSER_RESULT_ETH_VERSION_F_OFFSET                           14
#define PARSER_RESULT_ETH_VERSION_F_WIDTH                            2
#define PARSER_RESULT_ETH_VERSION_OFFSET                             6
#define PARSER_RESULT_ETH_VERSION_F_OFFSET_MOD8                      6
#define PARSER_RESULT_VID_FILTER_MATCH_F_OFFSET                      8
#define PARSER_RESULT_VID_FILTER_MATCH_F_WIDTH                       4
#define PARSER_RESULT_VID_FILTER_MATCH_OFFSET                        6
#define PARSER_RESULT_VID_FILTER_MATCH_F_OFFSET_MOD8                 0
#define PARSER_RESULT_LAYER2_ADDRESS_F_OFFSET                        0
#define PARSER_RESULT_LAYER2_ADDRESS_F_WIDTH                         8
#define PARSER_RESULT_LAYER2_ADDRESS_OFFSET                          7
#define PARSER_RESULT_OUTER_VLAN_F_OFFSET                            16
#define PARSER_RESULT_OUTER_VLAN_F_WIDTH                             16
#define PARSER_RESULT_OUTER_VLAN_OFFSET                              8
#define PARSER_RESULT_DA1_2_F_OFFSET                                 0
#define PARSER_RESULT_DA1_2_F_WIDTH                                  16
#define PARSER_RESULT_DA1_2_OFFSET                                   10
#define PARSER_RESULT_DA3_6_F_OFFSET                                 0
#define PARSER_RESULT_DA3_6_F_WIDTH                                  32
#define PARSER_RESULT_DA3_6_OFFSET                                   12
#define PARSER_RESULT_INNER_VLAN_F_OFFSET                            16
#define PARSER_RESULT_INNER_VLAN_F_WIDTH                             16
#define PARSER_RESULT_INNER_VLAN_OFFSET                              16
#define PARSER_RESULT_SA1_2_F_OFFSET                                 0
#define PARSER_RESULT_SA1_2_F_WIDTH                                  16
#define PARSER_RESULT_SA1_2_OFFSET                                   18
#define PARSER_RESULT_SA3_6_F_OFFSET                                 0
#define PARSER_RESULT_SA3_6_F_WIDTH                                  32
#define PARSER_RESULT_SA3_6_OFFSET                                   20
#define PARSER_RESULT__3RD_VLAN_F_OFFSET                             16
#define PARSER_RESULT__3RD_VLAN_F_WIDTH                              16
#define PARSER_RESULT__3RD_VLAN_OFFSET                               24
#define PARSER_RESULT_ETHERTYPE_F_OFFSET                             0
#define PARSER_RESULT_ETHERTYPE_F_WIDTH                              16
#define PARSER_RESULT_ETHERTYPE_OFFSET                               26
#define PARSER_RESULT_IP_LENGTH_F_OFFSET                             16
#define PARSER_RESULT_IP_LENGTH_F_WIDTH                              16
#define PARSER_RESULT_IP_LENGTH_OFFSET                               28
#define PARSER_RESULT_IP_TTL_F_OFFSET                                8
#define PARSER_RESULT_IP_TTL_F_WIDTH                                 8
#define PARSER_RESULT_IP_TTL_OFFSET                                  30
#define PARSER_RESULT_TOS_F_OFFSET                                   0
#define PARSER_RESULT_TOS_F_WIDTH                                    8
#define PARSER_RESULT_TOS_OFFSET                                     31
#define PARSER_RESULT_LAYER4_OFFSET_F_OFFSET                         24
#define PARSER_RESULT_LAYER4_OFFSET_F_WIDTH                          8
#define PARSER_RESULT_LAYER4_OFFSET_OFFSET                           32
#define PARSER_RESULT_LAYER4_OFFSET_F_OFFSET_MOD16                   8
#define PARSER_RESULT_LAYER3_OFFSET_F_OFFSET                         16
#define PARSER_RESULT_LAYER3_OFFSET_F_WIDTH                          8
#define PARSER_RESULT_LAYER3_OFFSET_OFFSET                           33
#define PARSER_RESULT_LAYER3_OFFSET_F_OFFSET_MOD16                   0
#define PARSER_RESULT_ERROR_F_OFFSET                                 10
#define PARSER_RESULT_ERROR_F_WIDTH                                  1
#define PARSER_RESULT_ERROR_OFFSET                                   34
#define PARSER_RESULT_ERROR_F_OFFSET_MOD8                            2
#define PARSER_RESULT_NON_FIVE_TUPLE_F_OFFSET                        9
#define PARSER_RESULT_NON_FIVE_TUPLE_F_WIDTH                         1
#define PARSER_RESULT_NON_FIVE_TUPLE_OFFSET                          34
#define PARSER_RESULT_NON_FIVE_TUPLE_F_OFFSET_MOD8                   1
#define PARSER_RESULT_IP_LEN_ERROR_F_OFFSET                          8
#define PARSER_RESULT_IP_LEN_ERROR_F_WIDTH                           1
#define PARSER_RESULT_IP_LEN_ERROR_OFFSET                            34
#define PARSER_RESULT_IP_LEN_ERROR_F_OFFSET_MOD8                     0
#define PARSER_RESULT_PROTOCOL_F_OFFSET                              0
#define PARSER_RESULT_PROTOCOL_F_WIDTH                               8
#define PARSER_RESULT_PROTOCOL_OFFSET                                35
#define PARSER_RESULT_SOURCE_PORT_F_OFFSET                           16
#define PARSER_RESULT_SOURCE_PORT_F_WIDTH                            16
#define PARSER_RESULT_SOURCE_PORT_OFFSET                             36
#define PARSER_RESULT_DESTINATION_PORT_F_OFFSET                      0
#define PARSER_RESULT_DESTINATION_PORT_F_WIDTH                       16
#define PARSER_RESULT_DESTINATION_PORT_OFFSET                        38
#define PARSER_RESULT_SOURCE_IP_F_OFFSET                             0
#define PARSER_RESULT_SOURCE_IP_F_WIDTH                              32
#define PARSER_RESULT_SOURCE_IP_OFFSET                               40
#define PARSER_RESULT_DESTINATION_IP_F_OFFSET                        0
#define PARSER_RESULT_DESTINATION_IP_F_WIDTH                         32
#define PARSER_RESULT_DESTINATION_IP_OFFSET                          44
#define PARSER_RESULT_FLAGS_F_OFFSET                                 24
#define PARSER_RESULT_FLAGS_F_WIDTH                                  8
#define PARSER_RESULT_FLAGS_OFFSET                                   48
#define PARSER_RESULT_FLAGS_F_OFFSET_MOD16                           8
#define PARSER_RESULT_ICMPV6_F_OFFSET                                23
#define PARSER_RESULT_ICMPV6_F_WIDTH                                 1
#define PARSER_RESULT_ICMPV6_OFFSET                                  49
#define PARSER_RESULT_ICMPV6_F_OFFSET_MOD8                           7
#define PARSER_RESULT_ICMPV6_F_OFFSET_MOD16                          7
#define PARSER_RESULT_V6_AH_F_OFFSET                                 22
#define PARSER_RESULT_V6_AH_F_WIDTH                                  1
#define PARSER_RESULT_V6_AH_OFFSET                                   49
#define PARSER_RESULT_V6_AH_F_OFFSET_MOD8                            6
#define PARSER_RESULT_V6_AH_F_OFFSET_MOD16                           6
#define PARSER_RESULT_V6_DEST_OPT_F_OFFSET                           21
#define PARSER_RESULT_V6_DEST_OPT_F_WIDTH                            1
#define PARSER_RESULT_V6_DEST_OPT_OFFSET                             49
#define PARSER_RESULT_V6_DEST_OPT_F_OFFSET_MOD8                      5
#define PARSER_RESULT_V6_DEST_OPT_F_OFFSET_MOD16                     5
#define PARSER_RESULT_V6_ROUTE_F_OFFSET                              20
#define PARSER_RESULT_V6_ROUTE_F_WIDTH                               1
#define PARSER_RESULT_V6_ROUTE_OFFSET                                49
#define PARSER_RESULT_V6_ROUTE_F_OFFSET_MOD8                         4
#define PARSER_RESULT_V6_ROUTE_F_OFFSET_MOD16                        4
#define PARSER_RESULT_V6_HOP_F_OFFSET                                19
#define PARSER_RESULT_V6_HOP_F_WIDTH                                 1
#define PARSER_RESULT_V6_HOP_OFFSET                                  49
#define PARSER_RESULT_V6_HOP_F_OFFSET_MOD8                           3
#define PARSER_RESULT_V6_HOP_F_OFFSET_MOD16                          3
#define PARSER_RESULT_HDR_LEN_ERR_F_OFFSET                           18
#define PARSER_RESULT_HDR_LEN_ERR_F_WIDTH                            1
#define PARSER_RESULT_HDR_LEN_ERR_OFFSET                             49
#define PARSER_RESULT_HDR_LEN_ERR_F_OFFSET_MOD8                      2
#define PARSER_RESULT_HDR_LEN_ERR_F_OFFSET_MOD16                     2
#define PARSER_RESULT_CHKSM_ERR_F_OFFSET                             17
#define PARSER_RESULT_CHKSM_ERR_F_WIDTH                              1
#define PARSER_RESULT_CHKSM_ERR_OFFSET                               49
#define PARSER_RESULT_CHKSM_ERR_F_OFFSET_MOD8                        1
#define PARSER_RESULT_CHKSM_ERR_F_OFFSET_MOD16                       1
#define PARSER_RESULT_VER_MISS_F_OFFSET                              16
#define PARSER_RESULT_VER_MISS_F_WIDTH                               1
#define PARSER_RESULT_VER_MISS_OFFSET                                49
#define PARSER_RESULT_VER_MISS_F_OFFSET_MOD8                         0
#define PARSER_RESULT_VER_MISS_F_OFFSET_MOD16                        0
#define PARSER_RESULT_LAYER3_CHECKSUM_F_OFFSET                       0
#define PARSER_RESULT_LAYER3_CHECKSUM_F_WIDTH                        16
#define PARSER_RESULT_LAYER3_CHECKSUM_OFFSET                         50
#define PARSER_RESULT_LAYER4_CALC_CHECKSUM_F_OFFSET                  16
#define PARSER_RESULT_LAYER4_CALC_CHECKSUM_F_WIDTH                   16
#define PARSER_RESULT_LAYER4_CALC_CHECKSUM_OFFSET                    52
#define PARSER_RESULT_LAYER4_CHECKSUM_F_OFFSET                       0
#define PARSER_RESULT_LAYER4_CHECKSUM_F_WIDTH                        16
#define PARSER_RESULT_LAYER4_CHECKSUM_OFFSET                         54

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	da_filter_match     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	first_ip_fragment   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_fragment         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_filter_match     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_filter_num       	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv6_ext_header     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_flag            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	p_tag               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid_filter_hit      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	exception           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da_filter_number    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer4_protocol     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_parser_l4_protocol enumeration*/
	uint32_t	_5_tup_valid        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhcp                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlans_num           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	broadcast           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	multicast           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer3_protocol     	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_parser_l3_protocol enumeration*/
	uint32_t	layer2_protocol     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tag_type            	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_spoof           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tpid_vlan_0         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tpid_vlan_1         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tpid_vlan_2         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	in_cfi              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	out_cfi             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_outer            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_inner            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_version         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid_filter_match    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer2_address      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_vlan          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da1_2               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da3_6               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_vlan          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sa1_2               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sa3_6               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_3rd_vlan           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ethertype           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_length           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_ttl              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer4_offset       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer3_offset       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3           	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	non_five_tuple      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_len_error        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	protocol            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_port         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	destination_port    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_ip           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	destination_ip      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flags               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	icmpv6              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	v6_ah               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	v6_dest_opt         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	v6_route            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	v6_hop              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hdr_len_err         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	chksm_err           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ver_miss            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer3_checksum     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer4_calc_checksum	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer4_checksum     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	layer2_protocol     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer3_protocol     	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_parser_l3_protocol enumeration*/
	uint32_t	multicast           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	broadcast           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vlans_num           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dhcp                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_5_tup_valid        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer4_protocol     	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__; /*defined by rdd_parser_l4_protocol enumeration*/
	uint32_t	da_filter_number    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	exception           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid_filter_hit      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	p_tag               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_flag            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ipv6_ext_header     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tcp_udp             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_filter_num       	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_filter_match     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_fragment         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	first_ip_fragment   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da_filter_match     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer2_address      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vid_filter_match    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2           	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	eth_version         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_inner            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	no_outer            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	out_cfi             	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	in_cfi              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tpid_vlan_2         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tpid_vlan_1         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tpid_vlan_0         	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mac_spoof           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tag_type            	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da1_2               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	outer_vlan          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	da3_6               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sa1_2               	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	inner_vlan          	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sa3_6               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ethertype           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	_3rd_vlan           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	tos                 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_ttl              	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_length           	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	protocol            	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ip_len_error        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	non_five_tuple      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	error               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3           	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer3_offset       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer4_offset       	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	destination_port    	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_port         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	source_ip           	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	destination_ip      	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer3_checksum     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ver_miss            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	chksm_err           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hdr_len_err         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	v6_hop              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	v6_route            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	v6_dest_opt         	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	v6_ah               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	icmpv6              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	flags               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer4_checksum     	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	layer4_calc_checksum	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PARSER_RESULT_DTS;

#define RDD_PARSER_RESULT_DA_FILTER_MATCH_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 7, 1, r)
#define RDD_PARSER_RESULT_DA_FILTER_MATCH_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 7, 1, v)
#define RDD_PARSER_RESULT_DA_FILTER_MATCH_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_PARSER_RESULT_DA_FILTER_MATCH_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_PARSER_RESULT_FIRST_IP_FRAGMENT_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 6, 1, r)
#define RDD_PARSER_RESULT_FIRST_IP_FRAGMENT_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 6, 1, v)
#define RDD_PARSER_RESULT_FIRST_IP_FRAGMENT_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_PARSER_RESULT_FIRST_IP_FRAGMENT_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_PARSER_RESULT_IP_FRAGMENT_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 5, 1, r)
#define RDD_PARSER_RESULT_IP_FRAGMENT_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 5, 1, v)
#define RDD_PARSER_RESULT_IP_FRAGMENT_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_PARSER_RESULT_IP_FRAGMENT_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_PARSER_RESULT_IP_FILTER_MATCH_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 4, 1, r)
#define RDD_PARSER_RESULT_IP_FILTER_MATCH_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 4, 1, v)
#define RDD_PARSER_RESULT_IP_FILTER_MATCH_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_PARSER_RESULT_IP_FILTER_MATCH_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_PARSER_RESULT_IP_FILTER_NUM_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 2, 2, r)
#define RDD_PARSER_RESULT_IP_FILTER_NUM_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 2, 2, v)
#define RDD_PARSER_RESULT_IP_FILTER_NUM_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 2, 2, r)
#define RDD_PARSER_RESULT_IP_FILTER_NUM_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 2, 2, v)
#define RDD_PARSER_RESULT_TCP_UDP_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 1, 1, r)
#define RDD_PARSER_RESULT_TCP_UDP_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 1, 1, v)
#define RDD_PARSER_RESULT_TCP_UDP_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p, 1, 1, r)
#define RDD_PARSER_RESULT_TCP_UDP_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p, 1, 1, v)
#define RDD_PARSER_RESULT_IPV6_EXT_HEADER_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 0, 1, r)
#define RDD_PARSER_RESULT_IPV6_EXT_HEADER_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS), 0, 1, v)
#define RDD_PARSER_RESULT_IPV6_EXT_HEADER_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p, 0, 1, r)
#define RDD_PARSER_RESULT_IPV6_EXT_HEADER_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p, 0, 1, v)
#define RDD_PARSER_RESULT_TCP_FLAG_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 7, 1, r)
#define RDD_PARSER_RESULT_TCP_FLAG_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 7, 1, v)
#define RDD_PARSER_RESULT_TCP_FLAG_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 1, 7, 1, r)
#define RDD_PARSER_RESULT_TCP_FLAG_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 1, 7, 1, v)
#define RDD_PARSER_RESULT_P_TAG_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 6, 1, r)
#define RDD_PARSER_RESULT_P_TAG_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 6, 1, v)
#define RDD_PARSER_RESULT_P_TAG_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 1, 6, 1, r)
#define RDD_PARSER_RESULT_P_TAG_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 1, 6, 1, v)
#define RDD_PARSER_RESULT_VID_FILTER_HIT_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 5, 1, r)
#define RDD_PARSER_RESULT_VID_FILTER_HIT_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 5, 1, v)
#define RDD_PARSER_RESULT_VID_FILTER_HIT_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 1, 5, 1, r)
#define RDD_PARSER_RESULT_VID_FILTER_HIT_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 1, 5, 1, v)
#define RDD_PARSER_RESULT_EXCEPTION_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 4, 1, r)
#define RDD_PARSER_RESULT_EXCEPTION_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 4, 1, v)
#define RDD_PARSER_RESULT_EXCEPTION_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 1, 4, 1, r)
#define RDD_PARSER_RESULT_EXCEPTION_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 1, 4, 1, v)
#define RDD_PARSER_RESULT_DA_FILTER_NUMBER_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 0, 4, r)
#define RDD_PARSER_RESULT_DA_FILTER_NUMBER_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 1, 0, 4, v)
#define RDD_PARSER_RESULT_DA_FILTER_NUMBER_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 1, 0, 4, r)
#define RDD_PARSER_RESULT_DA_FILTER_NUMBER_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 1, 0, 4, v)
#define RDD_PARSER_RESULT_LAYER4_PROTOCOL_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 2, 4, 4, r) /*defined by rdd_parser_l4_protocol enumeration*/
#define RDD_PARSER_RESULT_LAYER4_PROTOCOL_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 2, 4, 4, v) /*defined by rdd_parser_l4_protocol enumeration*/
#define RDD_PARSER_RESULT_LAYER4_PROTOCOL_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 2, 4, 4, r) /*defined by rdd_parser_l4_protocol enumeration*/
#define RDD_PARSER_RESULT_LAYER4_PROTOCOL_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 2, 4, 4, v) /*defined by rdd_parser_l4_protocol enumeration*/
#define RDD_PARSER_RESULT__5_TUP_VALID_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 2, 3, 1, r)
#define RDD_PARSER_RESULT__5_TUP_VALID_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 2, 3, 1, v)
#define RDD_PARSER_RESULT__5_TUP_VALID_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 2, 3, 1, r)
#define RDD_PARSER_RESULT__5_TUP_VALID_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 2, 3, 1, v)
#define RDD_PARSER_RESULT_DHCP_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 2, 2, 1, r)
#define RDD_PARSER_RESULT_DHCP_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 2, 2, 1, v)
#define RDD_PARSER_RESULT_DHCP_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 2, 2, 1, r)
#define RDD_PARSER_RESULT_DHCP_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 2, 2, 1, v)
#define RDD_PARSER_RESULT_VLANS_NUM_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 2, 0, 2, r)
#define RDD_PARSER_RESULT_VLANS_NUM_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 2, 0, 2, v)
#define RDD_PARSER_RESULT_VLANS_NUM_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 2, 0, 2, r)
#define RDD_PARSER_RESULT_VLANS_NUM_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 2, 0, 2, v)
#define RDD_PARSER_RESULT_BROADCAST_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 3, 7, 1, r)
#define RDD_PARSER_RESULT_BROADCAST_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 3, 7, 1, v)
#define RDD_PARSER_RESULT_BROADCAST_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 3, 7, 1, r)
#define RDD_PARSER_RESULT_BROADCAST_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 3, 7, 1, v)
#define RDD_PARSER_RESULT_MULTICAST_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 3, 6, 1, r)
#define RDD_PARSER_RESULT_MULTICAST_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 3, 6, 1, v)
#define RDD_PARSER_RESULT_MULTICAST_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 3, 6, 1, r)
#define RDD_PARSER_RESULT_MULTICAST_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 3, 6, 1, v)
#define RDD_PARSER_RESULT_LAYER3_PROTOCOL_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 3, 4, 2, r) /*defined by rdd_parser_l3_protocol enumeration*/
#define RDD_PARSER_RESULT_LAYER3_PROTOCOL_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 3, 4, 2, v) /*defined by rdd_parser_l3_protocol enumeration*/
#define RDD_PARSER_RESULT_LAYER3_PROTOCOL_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 3, 4, 2, r) /*defined by rdd_parser_l3_protocol enumeration*/
#define RDD_PARSER_RESULT_LAYER3_PROTOCOL_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 3, 4, 2, v) /*defined by rdd_parser_l3_protocol enumeration*/
#define RDD_PARSER_RESULT_LAYER2_PROTOCOL_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 3, 0, 4, r)
#define RDD_PARSER_RESULT_LAYER2_PROTOCOL_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 3, 0, 4, v)
#define RDD_PARSER_RESULT_LAYER2_PROTOCOL_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 3, 0, 4, r)
#define RDD_PARSER_RESULT_LAYER2_PROTOCOL_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 3, 0, 4, v)
#define RDD_PARSER_RESULT_TAG_TYPE_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 4, 6, 2, r)
#define RDD_PARSER_RESULT_TAG_TYPE_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 4, 6, 2, v)
#define RDD_PARSER_RESULT_TAG_TYPE_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 4, 6, 2, r)
#define RDD_PARSER_RESULT_TAG_TYPE_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 4, 6, 2, v)
#define RDD_PARSER_RESULT_MAC_SPOOF_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 4, 5, 1, r)
#define RDD_PARSER_RESULT_MAC_SPOOF_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 4, 5, 1, v)
#define RDD_PARSER_RESULT_MAC_SPOOF_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 4, 5, 1, r)
#define RDD_PARSER_RESULT_MAC_SPOOF_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 4, 5, 1, v)
#define RDD_PARSER_RESULT_TPID_VLAN_0_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 4, 2, 3, r)
#define RDD_PARSER_RESULT_TPID_VLAN_0_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 4, 2, 3, v)
#define RDD_PARSER_RESULT_TPID_VLAN_0_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 4, 2, 3, r)
#define RDD_PARSER_RESULT_TPID_VLAN_0_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 4, 2, 3, v)
#define RDD_PARSER_RESULT_TPID_VLAN_1_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 4, 7, 3, r)
#define RDD_PARSER_RESULT_TPID_VLAN_1_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 4, 7, 3, v)
#define RDD_PARSER_RESULT_TPID_VLAN_1_READ(r, p)                          FIELD_MREAD_16((uint8_t *)p + 4, 7, 3, r)
#define RDD_PARSER_RESULT_TPID_VLAN_1_WRITE(v, p)                         FIELD_MWRITE_16((uint8_t *)p + 4, 7, 3, v)
#define RDD_PARSER_RESULT_TPID_VLAN_2_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 4, 3, r)
#define RDD_PARSER_RESULT_TPID_VLAN_2_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 4, 3, v)
#define RDD_PARSER_RESULT_TPID_VLAN_2_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 5, 4, 3, r)
#define RDD_PARSER_RESULT_TPID_VLAN_2_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 5, 4, 3, v)
#define RDD_PARSER_RESULT_IN_CFI_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 3, 1, r)
#define RDD_PARSER_RESULT_IN_CFI_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 3, 1, v)
#define RDD_PARSER_RESULT_IN_CFI_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 5, 3, 1, r)
#define RDD_PARSER_RESULT_IN_CFI_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 5, 3, 1, v)
#define RDD_PARSER_RESULT_OUT_CFI_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 2, 1, r)
#define RDD_PARSER_RESULT_OUT_CFI_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 2, 1, v)
#define RDD_PARSER_RESULT_OUT_CFI_READ(r, p)                              FIELD_MREAD_8((uint8_t *)p + 5, 2, 1, r)
#define RDD_PARSER_RESULT_OUT_CFI_WRITE(v, p)                             FIELD_MWRITE_8((uint8_t *)p + 5, 2, 1, v)
#define RDD_PARSER_RESULT_NO_OUTER_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 1, 1, r)
#define RDD_PARSER_RESULT_NO_OUTER_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 1, 1, v)
#define RDD_PARSER_RESULT_NO_OUTER_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 5, 1, 1, r)
#define RDD_PARSER_RESULT_NO_OUTER_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 5, 1, 1, v)
#define RDD_PARSER_RESULT_NO_INNER_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 0, 1, r)
#define RDD_PARSER_RESULT_NO_INNER_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 5, 0, 1, v)
#define RDD_PARSER_RESULT_NO_INNER_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 5, 0, 1, r)
#define RDD_PARSER_RESULT_NO_INNER_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 5, 0, 1, v)
#define RDD_PARSER_RESULT_ETH_VERSION_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 6, 6, 2, r)
#define RDD_PARSER_RESULT_ETH_VERSION_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 6, 6, 2, v)
#define RDD_PARSER_RESULT_ETH_VERSION_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 6, 6, 2, r)
#define RDD_PARSER_RESULT_ETH_VERSION_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 6, 6, 2, v)
#define RDD_PARSER_RESULT_VID_FILTER_MATCH_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 6, 0, 4, r)
#define RDD_PARSER_RESULT_VID_FILTER_MATCH_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 6, 0, 4, v)
#define RDD_PARSER_RESULT_VID_FILTER_MATCH_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 6, 0, 4, r)
#define RDD_PARSER_RESULT_VID_FILTER_MATCH_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 6, 0, 4, v)
#define RDD_PARSER_RESULT_LAYER2_ADDRESS_READ_G(r, g, idx)                GROUP_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 7, r)
#define RDD_PARSER_RESULT_LAYER2_ADDRESS_WRITE_G(v, g, idx)               GROUP_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 7, v)
#define RDD_PARSER_RESULT_LAYER2_ADDRESS_READ(r, p)                       MREAD_8((uint8_t *)p + 7, r)
#define RDD_PARSER_RESULT_LAYER2_ADDRESS_WRITE(v, p)                      MWRITE_8((uint8_t *)p + 7, v)
#define RDD_PARSER_RESULT_OUTER_VLAN_READ_G(r, g, idx)                    GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 8, r)
#define RDD_PARSER_RESULT_OUTER_VLAN_WRITE_G(v, g, idx)                   GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 8, v)
#define RDD_PARSER_RESULT_OUTER_VLAN_READ(r, p)                           MREAD_16((uint8_t *)p + 8, r)
#define RDD_PARSER_RESULT_OUTER_VLAN_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 8, v)
#define RDD_PARSER_RESULT_DA1_2_READ_G(r, g, idx)                         GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 10, r)
#define RDD_PARSER_RESULT_DA1_2_WRITE_G(v, g, idx)                        GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 10, v)
#define RDD_PARSER_RESULT_DA1_2_READ(r, p)                                MREAD_16((uint8_t *)p + 10, r)
#define RDD_PARSER_RESULT_DA1_2_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 10, v)
#define RDD_PARSER_RESULT_DA3_6_READ_G(r, g, idx)                         GROUP_MREAD_32(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 12, r)
#define RDD_PARSER_RESULT_DA3_6_WRITE_G(v, g, idx)                        GROUP_MWRITE_32(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 12, v)
#define RDD_PARSER_RESULT_DA3_6_READ(r, p)                                MREAD_32((uint8_t *)p + 12, r)
#define RDD_PARSER_RESULT_DA3_6_WRITE(v, p)                               MWRITE_32((uint8_t *)p + 12, v)
#define RDD_PARSER_RESULT_INNER_VLAN_READ_G(r, g, idx)                    GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 16, r)
#define RDD_PARSER_RESULT_INNER_VLAN_WRITE_G(v, g, idx)                   GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 16, v)
#define RDD_PARSER_RESULT_INNER_VLAN_READ(r, p)                           MREAD_16((uint8_t *)p + 16, r)
#define RDD_PARSER_RESULT_INNER_VLAN_WRITE(v, p)                          MWRITE_16((uint8_t *)p + 16, v)
#define RDD_PARSER_RESULT_SA1_2_READ_G(r, g, idx)                         GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 18, r)
#define RDD_PARSER_RESULT_SA1_2_WRITE_G(v, g, idx)                        GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 18, v)
#define RDD_PARSER_RESULT_SA1_2_READ(r, p)                                MREAD_16((uint8_t *)p + 18, r)
#define RDD_PARSER_RESULT_SA1_2_WRITE(v, p)                               MWRITE_16((uint8_t *)p + 18, v)
#define RDD_PARSER_RESULT_SA3_6_READ_G(r, g, idx)                         GROUP_MREAD_32(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 20, r)
#define RDD_PARSER_RESULT_SA3_6_WRITE_G(v, g, idx)                        GROUP_MWRITE_32(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 20, v)
#define RDD_PARSER_RESULT_SA3_6_READ(r, p)                                MREAD_32((uint8_t *)p + 20, r)
#define RDD_PARSER_RESULT_SA3_6_WRITE(v, p)                               MWRITE_32((uint8_t *)p + 20, v)
#define RDD_PARSER_RESULT__3RD_VLAN_READ_G(r, g, idx)                     GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 24, r)
#define RDD_PARSER_RESULT__3RD_VLAN_WRITE_G(v, g, idx)                    GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 24, v)
#define RDD_PARSER_RESULT__3RD_VLAN_READ(r, p)                            MREAD_16((uint8_t *)p + 24, r)
#define RDD_PARSER_RESULT__3RD_VLAN_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 24, v)
#define RDD_PARSER_RESULT_ETHERTYPE_READ_G(r, g, idx)                     GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 26, r)
#define RDD_PARSER_RESULT_ETHERTYPE_WRITE_G(v, g, idx)                    GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 26, v)
#define RDD_PARSER_RESULT_ETHERTYPE_READ(r, p)                            MREAD_16((uint8_t *)p + 26, r)
#define RDD_PARSER_RESULT_ETHERTYPE_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 26, v)
#define RDD_PARSER_RESULT_IP_LENGTH_READ_G(r, g, idx)                     GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 28, r)
#define RDD_PARSER_RESULT_IP_LENGTH_WRITE_G(v, g, idx)                    GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 28, v)
#define RDD_PARSER_RESULT_IP_LENGTH_READ(r, p)                            MREAD_16((uint8_t *)p + 28, r)
#define RDD_PARSER_RESULT_IP_LENGTH_WRITE(v, p)                           MWRITE_16((uint8_t *)p + 28, v)
#define RDD_PARSER_RESULT_IP_TTL_READ_G(r, g, idx)                        GROUP_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 30, r)
#define RDD_PARSER_RESULT_IP_TTL_WRITE_G(v, g, idx)                       GROUP_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 30, v)
#define RDD_PARSER_RESULT_IP_TTL_READ(r, p)                               MREAD_8((uint8_t *)p + 30, r)
#define RDD_PARSER_RESULT_IP_TTL_WRITE(v, p)                              MWRITE_8((uint8_t *)p + 30, v)
#define RDD_PARSER_RESULT_TOS_READ_G(r, g, idx)                           GROUP_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 31, r)
#define RDD_PARSER_RESULT_TOS_WRITE_G(v, g, idx)                          GROUP_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 31, v)
#define RDD_PARSER_RESULT_TOS_READ(r, p)                                  MREAD_8((uint8_t *)p + 31, r)
#define RDD_PARSER_RESULT_TOS_WRITE(v, p)                                 MWRITE_8((uint8_t *)p + 31, v)
#define RDD_PARSER_RESULT_LAYER4_OFFSET_READ_G(r, g, idx)                 GROUP_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 32, r)
#define RDD_PARSER_RESULT_LAYER4_OFFSET_WRITE_G(v, g, idx)                GROUP_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 32, v)
#define RDD_PARSER_RESULT_LAYER4_OFFSET_READ(r, p)                        MREAD_8((uint8_t *)p + 32, r)
#define RDD_PARSER_RESULT_LAYER4_OFFSET_WRITE(v, p)                       MWRITE_8((uint8_t *)p + 32, v)
#define RDD_PARSER_RESULT_LAYER3_OFFSET_READ_G(r, g, idx)                 GROUP_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 33, r)
#define RDD_PARSER_RESULT_LAYER3_OFFSET_WRITE_G(v, g, idx)                GROUP_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 33, v)
#define RDD_PARSER_RESULT_LAYER3_OFFSET_READ(r, p)                        MREAD_8((uint8_t *)p + 33, r)
#define RDD_PARSER_RESULT_LAYER3_OFFSET_WRITE(v, p)                       MWRITE_8((uint8_t *)p + 33, v)
#define RDD_PARSER_RESULT_ERROR_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 34, 2, 1, r)
#define RDD_PARSER_RESULT_ERROR_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 34, 2, 1, v)
#define RDD_PARSER_RESULT_ERROR_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 34, 2, 1, r)
#define RDD_PARSER_RESULT_ERROR_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 34, 2, 1, v)
#define RDD_PARSER_RESULT_NON_FIVE_TUPLE_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 34, 1, 1, r)
#define RDD_PARSER_RESULT_NON_FIVE_TUPLE_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 34, 1, 1, v)
#define RDD_PARSER_RESULT_NON_FIVE_TUPLE_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 34, 1, 1, r)
#define RDD_PARSER_RESULT_NON_FIVE_TUPLE_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 34, 1, 1, v)
#define RDD_PARSER_RESULT_IP_LEN_ERROR_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 34, 0, 1, r)
#define RDD_PARSER_RESULT_IP_LEN_ERROR_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 34, 0, 1, v)
#define RDD_PARSER_RESULT_IP_LEN_ERROR_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 34, 0, 1, r)
#define RDD_PARSER_RESULT_IP_LEN_ERROR_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 34, 0, 1, v)
#define RDD_PARSER_RESULT_PROTOCOL_READ_G(r, g, idx)                      GROUP_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 35, r)
#define RDD_PARSER_RESULT_PROTOCOL_WRITE_G(v, g, idx)                     GROUP_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 35, v)
#define RDD_PARSER_RESULT_PROTOCOL_READ(r, p)                             MREAD_8((uint8_t *)p + 35, r)
#define RDD_PARSER_RESULT_PROTOCOL_WRITE(v, p)                            MWRITE_8((uint8_t *)p + 35, v)
#define RDD_PARSER_RESULT_SOURCE_PORT_READ_G(r, g, idx)                   GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 36, r)
#define RDD_PARSER_RESULT_SOURCE_PORT_WRITE_G(v, g, idx)                  GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 36, v)
#define RDD_PARSER_RESULT_SOURCE_PORT_READ(r, p)                          MREAD_16((uint8_t *)p + 36, r)
#define RDD_PARSER_RESULT_SOURCE_PORT_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 36, v)
#define RDD_PARSER_RESULT_DESTINATION_PORT_READ_G(r, g, idx)              GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 38, r)
#define RDD_PARSER_RESULT_DESTINATION_PORT_WRITE_G(v, g, idx)             GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 38, v)
#define RDD_PARSER_RESULT_DESTINATION_PORT_READ(r, p)                     MREAD_16((uint8_t *)p + 38, r)
#define RDD_PARSER_RESULT_DESTINATION_PORT_WRITE(v, p)                    MWRITE_16((uint8_t *)p + 38, v)
#define RDD_PARSER_RESULT_SOURCE_IP_READ_G(r, g, idx)                     GROUP_MREAD_32(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 40, r)
#define RDD_PARSER_RESULT_SOURCE_IP_WRITE_G(v, g, idx)                    GROUP_MWRITE_32(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 40, v)
#define RDD_PARSER_RESULT_SOURCE_IP_READ(r, p)                            MREAD_32((uint8_t *)p + 40, r)
#define RDD_PARSER_RESULT_SOURCE_IP_WRITE(v, p)                           MWRITE_32((uint8_t *)p + 40, v)
#define RDD_PARSER_RESULT_DESTINATION_IP_READ_G(r, g, idx)                GROUP_MREAD_32(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 44, r)
#define RDD_PARSER_RESULT_DESTINATION_IP_WRITE_G(v, g, idx)               GROUP_MWRITE_32(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 44, v)
#define RDD_PARSER_RESULT_DESTINATION_IP_READ(r, p)                       MREAD_32((uint8_t *)p + 44, r)
#define RDD_PARSER_RESULT_DESTINATION_IP_WRITE(v, p)                      MWRITE_32((uint8_t *)p + 44, v)
#define RDD_PARSER_RESULT_FLAGS_READ_G(r, g, idx)                         GROUP_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 48, r)
#define RDD_PARSER_RESULT_FLAGS_WRITE_G(v, g, idx)                        GROUP_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 48, v)
#define RDD_PARSER_RESULT_FLAGS_READ(r, p)                                MREAD_8((uint8_t *)p + 48, r)
#define RDD_PARSER_RESULT_FLAGS_WRITE(v, p)                               MWRITE_8((uint8_t *)p + 48, v)
#define RDD_PARSER_RESULT_ICMPV6_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 7, 1, r)
#define RDD_PARSER_RESULT_ICMPV6_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 7, 1, v)
#define RDD_PARSER_RESULT_ICMPV6_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 49, 7, 1, r)
#define RDD_PARSER_RESULT_ICMPV6_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 49, 7, 1, v)
#define RDD_PARSER_RESULT_V6_AH_READ_G(r, g, idx)                         GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 6, 1, r)
#define RDD_PARSER_RESULT_V6_AH_WRITE_G(v, g, idx)                        GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 6, 1, v)
#define RDD_PARSER_RESULT_V6_AH_READ(r, p)                                FIELD_MREAD_8((uint8_t *)p + 49, 6, 1, r)
#define RDD_PARSER_RESULT_V6_AH_WRITE(v, p)                               FIELD_MWRITE_8((uint8_t *)p + 49, 6, 1, v)
#define RDD_PARSER_RESULT_V6_DEST_OPT_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 5, 1, r)
#define RDD_PARSER_RESULT_V6_DEST_OPT_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 5, 1, v)
#define RDD_PARSER_RESULT_V6_DEST_OPT_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 49, 5, 1, r)
#define RDD_PARSER_RESULT_V6_DEST_OPT_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 49, 5, 1, v)
#define RDD_PARSER_RESULT_V6_ROUTE_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 4, 1, r)
#define RDD_PARSER_RESULT_V6_ROUTE_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 4, 1, v)
#define RDD_PARSER_RESULT_V6_ROUTE_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 49, 4, 1, r)
#define RDD_PARSER_RESULT_V6_ROUTE_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 49, 4, 1, v)
#define RDD_PARSER_RESULT_V6_HOP_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 3, 1, r)
#define RDD_PARSER_RESULT_V6_HOP_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 3, 1, v)
#define RDD_PARSER_RESULT_V6_HOP_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 49, 3, 1, r)
#define RDD_PARSER_RESULT_V6_HOP_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 49, 3, 1, v)
#define RDD_PARSER_RESULT_HDR_LEN_ERR_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 2, 1, r)
#define RDD_PARSER_RESULT_HDR_LEN_ERR_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 2, 1, v)
#define RDD_PARSER_RESULT_HDR_LEN_ERR_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p + 49, 2, 1, r)
#define RDD_PARSER_RESULT_HDR_LEN_ERR_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p + 49, 2, 1, v)
#define RDD_PARSER_RESULT_CHKSM_ERR_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 1, 1, r)
#define RDD_PARSER_RESULT_CHKSM_ERR_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 1, 1, v)
#define RDD_PARSER_RESULT_CHKSM_ERR_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 49, 1, 1, r)
#define RDD_PARSER_RESULT_CHKSM_ERR_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 49, 1, 1, v)
#define RDD_PARSER_RESULT_VER_MISS_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 0, 1, r)
#define RDD_PARSER_RESULT_VER_MISS_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 49, 0, 1, v)
#define RDD_PARSER_RESULT_VER_MISS_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 49, 0, 1, r)
#define RDD_PARSER_RESULT_VER_MISS_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 49, 0, 1, v)
#define RDD_PARSER_RESULT_LAYER3_CHECKSUM_READ_G(r, g, idx)               GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 50, r)
#define RDD_PARSER_RESULT_LAYER3_CHECKSUM_WRITE_G(v, g, idx)              GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 50, v)
#define RDD_PARSER_RESULT_LAYER3_CHECKSUM_READ(r, p)                      MREAD_16((uint8_t *)p + 50, r)
#define RDD_PARSER_RESULT_LAYER3_CHECKSUM_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 50, v)
#define RDD_PARSER_RESULT_LAYER4_CALC_CHECKSUM_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 52, r)
#define RDD_PARSER_RESULT_LAYER4_CALC_CHECKSUM_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 52, v)
#define RDD_PARSER_RESULT_LAYER4_CALC_CHECKSUM_READ(r, p)                 MREAD_16((uint8_t *)p + 52, r)
#define RDD_PARSER_RESULT_LAYER4_CALC_CHECKSUM_WRITE(v, p)                MWRITE_16((uint8_t *)p + 52, v)
#define RDD_PARSER_RESULT_LAYER4_CHECKSUM_READ_G(r, g, idx)               GROUP_MREAD_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 54, r)
#define RDD_PARSER_RESULT_LAYER4_CHECKSUM_WRITE_G(v, g, idx)              GROUP_MWRITE_16(g, idx*sizeof(RDD_PARSER_RESULT_DTS) + 54, v)
#define RDD_PARSER_RESULT_LAYER4_CHECKSUM_READ(r, p)                      MREAD_16((uint8_t *)p + 54, r)
#define RDD_PARSER_RESULT_LAYER4_CHECKSUM_WRITE(v, p)                     MWRITE_16((uint8_t *)p + 54, v)
#define NATC_CONTROL_ENTRY_DONE_F_OFFSET                                  31
#define NATC_CONTROL_ENTRY_DONE_F_WIDTH                                   1
#define NATC_CONTROL_ENTRY_DONE_OFFSET                                    0
#define NATC_CONTROL_ENTRY_DONE_F_OFFSET_MOD8                             7
#define NATC_CONTROL_ENTRY_DONE_F_OFFSET_MOD16                            15
#define NATC_CONTROL_ENTRY_NATC_HIT_F_OFFSET                              30
#define NATC_CONTROL_ENTRY_NATC_HIT_F_WIDTH                               1
#define NATC_CONTROL_ENTRY_NATC_HIT_OFFSET                                0
#define NATC_CONTROL_ENTRY_NATC_HIT_F_OFFSET_MOD8                         6
#define NATC_CONTROL_ENTRY_NATC_HIT_F_OFFSET_MOD16                        14
#define NATC_CONTROL_ENTRY_CACHE_HIT_F_OFFSET                             29
#define NATC_CONTROL_ENTRY_CACHE_HIT_F_WIDTH                              1
#define NATC_CONTROL_ENTRY_CACHE_HIT_OFFSET                               0
#define NATC_CONTROL_ENTRY_CACHE_HIT_F_OFFSET_MOD8                        5
#define NATC_CONTROL_ENTRY_CACHE_HIT_F_OFFSET_MOD16                       13
#define NATC_CONTROL_ENTRY_HW_RESERVED0_F_OFFSET                          24
#define NATC_CONTROL_ENTRY_HW_RESERVED0_F_WIDTH                           5
#define NATC_CONTROL_ENTRY_HW_RESERVED0_OFFSET                            0
#define NATC_CONTROL_ENTRY_HW_RESERVED0_F_OFFSET_MOD8                     0
#define NATC_CONTROL_ENTRY_HW_RESERVED0_F_OFFSET_MOD16                    8
#define NATC_CONTROL_ENTRY_HAS_ITER_F_OFFSET                              20
#define NATC_CONTROL_ENTRY_HAS_ITER_F_WIDTH                               4
#define NATC_CONTROL_ENTRY_HAS_ITER_OFFSET                                1
#define NATC_CONTROL_ENTRY_HAS_ITER_F_OFFSET_MOD8                         4
#define NATC_CONTROL_ENTRY_HAS_ITER_F_OFFSET_MOD16                        4
#define NATC_CONTROL_ENTRY_HW_RESERVED1_F_OFFSET                          18
#define NATC_CONTROL_ENTRY_HW_RESERVED1_F_WIDTH                           2
#define NATC_CONTROL_ENTRY_HW_RESERVED1_OFFSET                            1
#define NATC_CONTROL_ENTRY_HW_RESERVED1_F_OFFSET_MOD8                     2
#define NATC_CONTROL_ENTRY_HW_RESERVED1_F_OFFSET_MOD16                    2
#define NATC_CONTROL_ENTRY_HASH_VAL_F_OFFSET                              0
#define NATC_CONTROL_ENTRY_HASH_VAL_F_WIDTH                               18
#define NATC_CONTROL_ENTRY_HASH_VAL_OFFSET                                0
#define NATC_CONTROL_ENTRY_HW_RESERVED2_F_OFFSET                          0
#define NATC_CONTROL_ENTRY_HW_RESERVED2_F_WIDTH                           32
#define NATC_CONTROL_ENTRY_HW_RESERVED2_OFFSET                            4

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	done        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	natc_hit    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cache_hit   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hw_reserved0	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	has_iter    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hw_reserved1	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hash_val    	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hw_reserved2	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	hash_val    	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hw_reserved1	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	has_iter    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hw_reserved0	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cache_hit   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	natc_hit    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	done        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hw_reserved2	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NATC_CONTROL_ENTRY_DTS;

#define RDD_NATC_CONTROL_ENTRY_DONE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS), 7, 1, r)
#define RDD_NATC_CONTROL_ENTRY_DONE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS), 7, 1, v)
#define RDD_NATC_CONTROL_ENTRY_DONE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_NATC_CONTROL_ENTRY_DONE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_NATC_CONTROL_ENTRY_NATC_HIT_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS), 6, 1, r)
#define RDD_NATC_CONTROL_ENTRY_NATC_HIT_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS), 6, 1, v)
#define RDD_NATC_CONTROL_ENTRY_NATC_HIT_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p, 6, 1, r)
#define RDD_NATC_CONTROL_ENTRY_NATC_HIT_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p, 6, 1, v)
#define RDD_NATC_CONTROL_ENTRY_CACHE_HIT_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS), 5, 1, r)
#define RDD_NATC_CONTROL_ENTRY_CACHE_HIT_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS), 5, 1, v)
#define RDD_NATC_CONTROL_ENTRY_CACHE_HIT_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p, 5, 1, r)
#define RDD_NATC_CONTROL_ENTRY_CACHE_HIT_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p, 5, 1, v)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED0_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS), 0, 5, r)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED0_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS), 0, 5, v)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED0_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 0, 5, r)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED0_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 0, 5, v)
#define RDD_NATC_CONTROL_ENTRY_HAS_ITER_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS) + 1, 4, 4, r)
#define RDD_NATC_CONTROL_ENTRY_HAS_ITER_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS) + 1, 4, 4, v)
#define RDD_NATC_CONTROL_ENTRY_HAS_ITER_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 1, 4, 4, r)
#define RDD_NATC_CONTROL_ENTRY_HAS_ITER_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 1, 4, 4, v)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED1_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS) + 1, 2, 2, r)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED1_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS) + 1, 2, 2, v)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED1_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 2, 2, r)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED1_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 2, 2, v)
#define RDD_NATC_CONTROL_ENTRY_HASH_VAL_READ_G(r, g, idx)              GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS) + 0, 0, 18, r)
#define RDD_NATC_CONTROL_ENTRY_HASH_VAL_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS) + 0, 0, 18, v)
#define RDD_NATC_CONTROL_ENTRY_HASH_VAL_READ(r, p)                     FIELD_MREAD_32((uint8_t *)p + 0, 0, 18, r)
#define RDD_NATC_CONTROL_ENTRY_HASH_VAL_WRITE(v, p)                    FIELD_MWRITE_32((uint8_t *)p + 0, 0, 18, v)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED2_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS) + 4, r)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED2_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_NATC_CONTROL_ENTRY_DTS) + 4, v)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED2_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_NATC_CONTROL_ENTRY_HW_RESERVED2_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define NATC_COUNTERS_ENTRY_HIT_COUNTER_F_OFFSET                           0
#define NATC_COUNTERS_ENTRY_HIT_COUNTER_F_WIDTH                            32
#define NATC_COUNTERS_ENTRY_HIT_COUNTER_OFFSET                             0
#define NATC_COUNTERS_ENTRY_BYTES_COUNTER_F_OFFSET                         0
#define NATC_COUNTERS_ENTRY_BYTES_COUNTER_F_WIDTH                          32
#define NATC_COUNTERS_ENTRY_BYTES_COUNTER_OFFSET                           4

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	hit_counter  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bytes_counter	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	hit_counter  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bytes_counter	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_NATC_COUNTERS_ENTRY_DTS;

#define RDD_NATC_COUNTERS_ENTRY_HIT_COUNTER_READ_G(r, g, idx)            GROUP_MREAD_32(g, idx*sizeof(RDD_NATC_COUNTERS_ENTRY_DTS), r)
#define RDD_NATC_COUNTERS_ENTRY_HIT_COUNTER_WRITE_G(v, g, idx)           GROUP_MWRITE_32(g, idx*sizeof(RDD_NATC_COUNTERS_ENTRY_DTS), v)
#define RDD_NATC_COUNTERS_ENTRY_HIT_COUNTER_READ(r, p)                   MREAD_32((uint8_t *)p, r)
#define RDD_NATC_COUNTERS_ENTRY_HIT_COUNTER_WRITE(v, p)                  MWRITE_32((uint8_t *)p, v)
#define RDD_NATC_COUNTERS_ENTRY_BYTES_COUNTER_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_NATC_COUNTERS_ENTRY_DTS) + 4, r)
#define RDD_NATC_COUNTERS_ENTRY_BYTES_COUNTER_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_NATC_COUNTERS_ENTRY_DTS) + 4, v)
#define RDD_NATC_COUNTERS_ENTRY_BYTES_COUNTER_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_NATC_COUNTERS_ENTRY_BYTES_COUNTER_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define HASH_RESULT_MATCH_F_OFFSET                                 30
#define HASH_RESULT_MATCH_F_WIDTH                                  2
#define HASH_RESULT_MATCH_OFFSET                                   0
#define HASH_RESULT_MATCH_F_OFFSET_MOD8                            6
#define HASH_RESULT_MATCH_F_OFFSET_MOD16                           14
#define HASH_RESULT_MATCH_INDEX_F_OFFSET                           19
#define HASH_RESULT_MATCH_INDEX_F_WIDTH                            11
#define HASH_RESULT_MATCH_INDEX_OFFSET                             0
#define HASH_RESULT_MATCH_INDEX_F_OFFSET_MOD16                     3
#define HASH_RESULT_MATCH_ENGINE_F_OFFSET                          17
#define HASH_RESULT_MATCH_ENGINE_F_WIDTH                           2
#define HASH_RESULT_MATCH_ENGINE_OFFSET                            1
#define HASH_RESULT_MATCH_ENGINE_F_OFFSET_MOD8                     1
#define HASH_RESULT_MATCH_ENGINE_F_OFFSET_MOD16                    1
#define HASH_RESULT_CONTEXT0_32_47_F_OFFSET                        0
#define HASH_RESULT_CONTEXT0_32_47_F_WIDTH                         16
#define HASH_RESULT_CONTEXT0_32_47_OFFSET                          2
#define HASH_RESULT_CONTEXT0_0_31_F_OFFSET                         0
#define HASH_RESULT_CONTEXT0_0_31_F_WIDTH                          32
#define HASH_RESULT_CONTEXT0_0_31_OFFSET                           4
#define HASH_RESULT_CONTEXT1_16_47_F_OFFSET                        0
#define HASH_RESULT_CONTEXT1_16_47_F_WIDTH                         32
#define HASH_RESULT_CONTEXT1_16_47_OFFSET                          8
#define HASH_RESULT_CONTEXT1_0_15_F_OFFSET                         16
#define HASH_RESULT_CONTEXT1_0_15_F_WIDTH                          16
#define HASH_RESULT_CONTEXT1_0_15_OFFSET                           12
#define HASH_RESULT_CONTEXT2_32_47_F_OFFSET                        0
#define HASH_RESULT_CONTEXT2_32_47_F_WIDTH                         16
#define HASH_RESULT_CONTEXT2_32_47_OFFSET                          14
#define HASH_RESULT_CONTEXT2_0_31_F_OFFSET                         0
#define HASH_RESULT_CONTEXT2_0_31_F_WIDTH                          32
#define HASH_RESULT_CONTEXT2_0_31_OFFSET                           16

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	match         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	match_index   	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	match_engine  	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_0    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context0_32_47	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context0_0_31 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context1_16_47	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context1_0_15 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context2_32_47	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context2_0_31 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_1    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	context0_32_47	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_0    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	match_engine  	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	match_index   	:11	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	match         	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context0_0_31 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context1_16_47	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context2_32_47	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context1_0_15 	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	context2_0_31 	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_1    	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_HASH_RESULT_DTS;

#define RDD_HASH_RESULT_MATCH_READ_G(r, g, idx)                   GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_HASH_RESULT_DTS), 6, 2, r)
#define RDD_HASH_RESULT_MATCH_WRITE_G(v, g, idx)                  GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_HASH_RESULT_DTS), 6, 2, v)
#define RDD_HASH_RESULT_MATCH_READ(r, p)                          FIELD_MREAD_8((uint8_t *)p, 6, 2, r)
#define RDD_HASH_RESULT_MATCH_WRITE(v, p)                         FIELD_MWRITE_8((uint8_t *)p, 6, 2, v)
#define RDD_HASH_RESULT_MATCH_INDEX_READ_G(r, g, idx)             GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_HASH_RESULT_DTS), 3, 11, r)
#define RDD_HASH_RESULT_MATCH_INDEX_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_HASH_RESULT_DTS), 3, 11, v)
#define RDD_HASH_RESULT_MATCH_INDEX_READ(r, p)                    FIELD_MREAD_16((uint8_t *)p, 3, 11, r)
#define RDD_HASH_RESULT_MATCH_INDEX_WRITE(v, p)                   FIELD_MWRITE_16((uint8_t *)p, 3, 11, v)
#define RDD_HASH_RESULT_MATCH_ENGINE_READ_G(r, g, idx)            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 1, 1, 2, r)
#define RDD_HASH_RESULT_MATCH_ENGINE_WRITE_G(v, g, idx)           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 1, 1, 2, v)
#define RDD_HASH_RESULT_MATCH_ENGINE_READ(r, p)                   FIELD_MREAD_8((uint8_t *)p + 1, 1, 2, r)
#define RDD_HASH_RESULT_MATCH_ENGINE_WRITE(v, p)                  FIELD_MWRITE_8((uint8_t *)p + 1, 1, 2, v)
#define RDD_HASH_RESULT_CONTEXT0_32_47_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 2, r)
#define RDD_HASH_RESULT_CONTEXT0_32_47_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 2, v)
#define RDD_HASH_RESULT_CONTEXT0_32_47_READ(r, p)                 MREAD_16((uint8_t *)p + 2, r)
#define RDD_HASH_RESULT_CONTEXT0_32_47_WRITE(v, p)                MWRITE_16((uint8_t *)p + 2, v)
#define RDD_HASH_RESULT_CONTEXT0_0_31_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 4, r)
#define RDD_HASH_RESULT_CONTEXT0_0_31_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 4, v)
#define RDD_HASH_RESULT_CONTEXT0_0_31_READ(r, p)                  MREAD_32((uint8_t *)p + 4, r)
#define RDD_HASH_RESULT_CONTEXT0_0_31_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 4, v)
#define RDD_HASH_RESULT_CONTEXT1_16_47_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 8, r)
#define RDD_HASH_RESULT_CONTEXT1_16_47_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 8, v)
#define RDD_HASH_RESULT_CONTEXT1_16_47_READ(r, p)                 MREAD_32((uint8_t *)p + 8, r)
#define RDD_HASH_RESULT_CONTEXT1_16_47_WRITE(v, p)                MWRITE_32((uint8_t *)p + 8, v)
#define RDD_HASH_RESULT_CONTEXT1_0_15_READ_G(r, g, idx)           GROUP_MREAD_16(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 12, r)
#define RDD_HASH_RESULT_CONTEXT1_0_15_WRITE_G(v, g, idx)          GROUP_MWRITE_16(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 12, v)
#define RDD_HASH_RESULT_CONTEXT1_0_15_READ(r, p)                  MREAD_16((uint8_t *)p + 12, r)
#define RDD_HASH_RESULT_CONTEXT1_0_15_WRITE(v, p)                 MWRITE_16((uint8_t *)p + 12, v)
#define RDD_HASH_RESULT_CONTEXT2_32_47_READ_G(r, g, idx)          GROUP_MREAD_16(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 14, r)
#define RDD_HASH_RESULT_CONTEXT2_32_47_WRITE_G(v, g, idx)         GROUP_MWRITE_16(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 14, v)
#define RDD_HASH_RESULT_CONTEXT2_32_47_READ(r, p)                 MREAD_16((uint8_t *)p + 14, r)
#define RDD_HASH_RESULT_CONTEXT2_32_47_WRITE(v, p)                MWRITE_16((uint8_t *)p + 14, v)
#define RDD_HASH_RESULT_CONTEXT2_0_31_READ_G(r, g, idx)           GROUP_MREAD_32(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 16, r)
#define RDD_HASH_RESULT_CONTEXT2_0_31_WRITE_G(v, g, idx)          GROUP_MWRITE_32(g, idx*sizeof(RDD_HASH_RESULT_DTS) + 16, v)
#define RDD_HASH_RESULT_CONTEXT2_0_31_READ(r, p)                  MREAD_32((uint8_t *)p + 16, r)
#define RDD_HASH_RESULT_CONTEXT2_0_31_WRITE(v, p)                 MWRITE_32((uint8_t *)p + 16, v)
#define TRACE_EVENT_TIMESTAMP_F_OFFSET                             20
#define TRACE_EVENT_TIMESTAMP_F_WIDTH                              12
#define TRACE_EVENT_TIMESTAMP_OFFSET                               0
#define TRACE_EVENT_TIMESTAMP_F_OFFSET_MOD16                       4
#define TRACE_EVENT_EVENT_ID_F_OFFSET                              18
#define TRACE_EVENT_EVENT_ID_F_WIDTH                               2
#define TRACE_EVENT_EVENT_ID_OFFSET                                1
#define TRACE_EVENT_EVENT_ID_F_OFFSET_MOD8                         2
#define TRACE_EVENT_EVENT_ID_F_OFFSET_MOD16                        2
#define TRACE_EVENT_TRACE_EVENT_INFO_F_OFFSET                      0
#define TRACE_EVENT_TRACE_EVENT_INFO_F_WIDTH                       18
#define TRACE_EVENT_TRACE_EVENT_INFO_OFFSET                        0
#define CPU_RX_DESCRIPTOR_CPU_RX_DATA_PTR0_UNION_F_OFFSET                0
#define CPU_RX_DESCRIPTOR_CPU_RX_DATA_PTR0_UNION_F_WIDTH                 32
#define CPU_RX_DESCRIPTOR_CPU_RX_DATA_PTR0_UNION_OFFSET                  0
#define CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_HI_F_OFFSET               24
#define CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_HI_F_WIDTH                8
#define CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_HI_OFFSET                 4
#define CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_HI_F_OFFSET_MOD16         8
#define CPU_RX_DESCRIPTOR_ABS_F_OFFSET                                   16
#define CPU_RX_DESCRIPTOR_ABS_F_WIDTH                                    1
#define CPU_RX_DESCRIPTOR_ABS_OFFSET                                     5
#define CPU_RX_DESCRIPTOR_ABS_F_OFFSET_MOD8                              0
#define CPU_RX_DESCRIPTOR_ABS_F_OFFSET_MOD16                             0
#define CPU_RX_DESCRIPTOR_PLEN_F_OFFSET                                  2
#define CPU_RX_DESCRIPTOR_PLEN_F_WIDTH                                   14
#define CPU_RX_DESCRIPTOR_PLEN_OFFSET                                    6
#define CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_F_OFFSET                    1
#define CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_F_WIDTH                     1
#define CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_OFFSET                      7
#define CPU_RX_DESCRIPTOR_IS_SRC_LAN_F_OFFSET                            31
#define CPU_RX_DESCRIPTOR_IS_SRC_LAN_F_WIDTH                             1
#define CPU_RX_DESCRIPTOR_IS_SRC_LAN_OFFSET                              8
#define CPU_RX_DESCRIPTOR_IS_SRC_LAN_F_OFFSET_MOD8                       7
#define CPU_RX_DESCRIPTOR_IS_SRC_LAN_F_OFFSET_MOD16                      15
#define CPU_RX_DESCRIPTOR_VPORT_F_OFFSET                                 25
#define CPU_RX_DESCRIPTOR_VPORT_F_WIDTH                                  5
#define CPU_RX_DESCRIPTOR_VPORT_OFFSET                                   8
#define CPU_RX_DESCRIPTOR_VPORT_F_OFFSET_MOD8                            1
#define CPU_RX_DESCRIPTOR_VPORT_F_OFFSET_MOD16                           9
#define CPU_RX_DESCRIPTOR_CPU_RX_SRC_UNION_F_OFFSET                      13
#define CPU_RX_DESCRIPTOR_CPU_RX_SRC_UNION_F_WIDTH                       12
#define CPU_RX_DESCRIPTOR_CPU_RX_SRC_UNION_OFFSET                        8
#define CPU_RX_DESCRIPTOR_DATA_OFFSET_F_OFFSET                           6
#define CPU_RX_DESCRIPTOR_DATA_OFFSET_F_WIDTH                            7
#define CPU_RX_DESCRIPTOR_DATA_OFFSET_OFFSET                             10
#define CPU_RX_DESCRIPTOR_REASON_F_OFFSET                                0
#define CPU_RX_DESCRIPTOR_REASON_F_WIDTH                                 6
#define CPU_RX_DESCRIPTOR_REASON_OFFSET                                  11
#define CPU_RX_DESCRIPTOR_IS_EXCEPTION_F_OFFSET                          31
#define CPU_RX_DESCRIPTOR_IS_EXCEPTION_F_WIDTH                           1
#define CPU_RX_DESCRIPTOR_IS_EXCEPTION_OFFSET                            12
#define CPU_RX_DESCRIPTOR_IS_EXCEPTION_F_OFFSET_MOD8                     7
#define CPU_RX_DESCRIPTOR_IS_EXCEPTION_F_OFFSET_MOD16                    15
#define CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_F_OFFSET                         30
#define CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_F_WIDTH                          1
#define CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_OFFSET                           12
#define CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_F_OFFSET_MOD8                    6
#define CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_F_OFFSET_MOD16                   14
#define CPU_RX_DESCRIPTOR_IS_UCAST_F_OFFSET                              29
#define CPU_RX_DESCRIPTOR_IS_UCAST_F_WIDTH                               1
#define CPU_RX_DESCRIPTOR_IS_UCAST_OFFSET                                12
#define CPU_RX_DESCRIPTOR_IS_UCAST_F_OFFSET_MOD8                         5
#define CPU_RX_DESCRIPTOR_IS_UCAST_F_OFFSET_MOD16                        13
#define CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_UNION_F_OFFSET                   16
#define CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_UNION_F_WIDTH                    13
#define CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_UNION_OFFSET                     12
#define CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_UNION_F_OFFSET_MOD16             0
#define CPU_RX_DESCRIPTOR_CPU_RX_METADATA_UNION_F_OFFSET                 0
#define CPU_RX_DESCRIPTOR_CPU_RX_METADATA_UNION_F_WIDTH                  16
#define CPU_RX_DESCRIPTOR_CPU_RX_METADATA_UNION_OFFSET                   14

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	cpu_rx_data_ptr0_union  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = cpu_rx_data_ptr0_union, size = 32 bits
	uint32_t	host_buffer_data_ptr_low	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_idx                 	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	host_buffer_data_ptr_hi 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	plen                    	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_chksum_verified      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_src_lan              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved7               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	vport                   	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_rx_src_union        	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = cpu_rx_src_union, size = 12 bits
	uint32_t	wan_flow_id             	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3               	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid                    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	data_offset             	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reason                  	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_exception            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_rx_offload           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_ucast                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	mcast_tx_prio_union     	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = mcast_tx_prio_union, size = 13 bits
	uint32_t	mcast_tx_prio           	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5               	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved6               	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	cpu_rx_metadata_union   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = cpu_rx_metadata_union, size = 16 bits
	uint32_t	dst_ssid_vector         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved6               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_0              	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_1              	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
#else
	uint32_t	cpu_rx_data_ptr0_union  	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = cpu_rx_data_ptr0_union, size = 32 bits
	uint32_t	host_buffer_data_ptr_low	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	fpm_idx                 	:18	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	reserved2               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_chksum_verified      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	plen                    	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	abs                     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved1               	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	host_buffer_data_ptr_hi 	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reason                  	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	data_offset             	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_rx_src_union        	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = cpu_rx_src_union, size = 12 bits
	uint32_t	wan_flow_id             	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3               	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ssid                    	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4               	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	vport                   	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved7               	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_src_lan              	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	cpu_rx_metadata_union   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = cpu_rx_metadata_union, size = 16 bits
	uint32_t	dst_ssid_vector         	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved6               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_0              	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	metadata_1              	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	mcast_tx_prio_union     	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
/* fields union = mcast_tx_prio_union, size = 13 bits
	uint32_t	mcast_tx_prio           	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5               	:10	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved6               	:13	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
 end fields union*/
	uint32_t	is_ucast                	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_rx_offload           	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	is_exception            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_RX_DESCRIPTOR_DTS;

#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_DATA_PTR0_UNION_READ_G(r, g, idx)            GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS), r)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_DATA_PTR0_UNION_WRITE_G(v, g, idx)           GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS), v)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_DATA_PTR0_UNION_READ(r, p)                   MREAD_32((uint8_t *)p, r)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_DATA_PTR0_UNION_WRITE(v, p)                  MWRITE_32((uint8_t *)p, v)
#define RDD_CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_LOW_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS), r)
#define RDD_CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_LOW_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS), v)
#define RDD_CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_LOW_READ(r, p)                 MREAD_32((uint8_t *)p, r)
#define RDD_CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_LOW_WRITE(v, p)                MWRITE_32((uint8_t *)p, v)
#define RDD_CPU_RX_DESCRIPTOR_FPM_IDX_READ_G(r, g, idx)                           GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS), 14, 18, r)
#define RDD_CPU_RX_DESCRIPTOR_FPM_IDX_WRITE_G(v, g, idx)                          GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS), 14, 18, v)
#define RDD_CPU_RX_DESCRIPTOR_FPM_IDX_READ(r, p)                                  FIELD_MREAD_32((uint8_t *)p, 14, 18, r)
#define RDD_CPU_RX_DESCRIPTOR_FPM_IDX_WRITE(v, p)                                 FIELD_MWRITE_32((uint8_t *)p, 14, 18, v)
#define RDD_CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_HI_READ_G(r, g, idx)           GROUP_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 4, r)
#define RDD_CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_HI_WRITE_G(v, g, idx)          GROUP_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 4, v)
#define RDD_CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_HI_READ(r, p)                  MREAD_8((uint8_t *)p + 4, r)
#define RDD_CPU_RX_DESCRIPTOR_HOST_BUFFER_DATA_PTR_HI_WRITE(v, p)                 MWRITE_8((uint8_t *)p + 4, v)
#define RDD_CPU_RX_DESCRIPTOR_ABS_READ_G(r, g, idx)                               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 5, 0, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_ABS_WRITE_G(v, g, idx)                              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 5, 0, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_ABS_READ(r, p)                                      FIELD_MREAD_8((uint8_t *)p + 5, 0, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_ABS_WRITE(v, p)                                     FIELD_MWRITE_8((uint8_t *)p + 5, 0, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_PLEN_READ_G(r, g, idx)                              GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 6, 2, 14, r)
#define RDD_CPU_RX_DESCRIPTOR_PLEN_WRITE_G(v, g, idx)                             GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 6, 2, 14, v)
#define RDD_CPU_RX_DESCRIPTOR_PLEN_READ(r, p)                                     FIELD_MREAD_16((uint8_t *)p + 6, 2, 14, r)
#define RDD_CPU_RX_DESCRIPTOR_PLEN_WRITE(v, p)                                    FIELD_MWRITE_16((uint8_t *)p + 6, 2, 14, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 7, 1, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 7, 1, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p + 7, 1, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_CHKSUM_VERIFIED_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p + 7, 1, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_SRC_LAN_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 7, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_SRC_LAN_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 7, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_SRC_LAN_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 8, 7, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_SRC_LAN_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 8, 7, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_VPORT_READ_G(r, g, idx)                             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 1, 5, r)
#define RDD_CPU_RX_DESCRIPTOR_VPORT_WRITE_G(v, g, idx)                            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 1, 5, v)
#define RDD_CPU_RX_DESCRIPTOR_VPORT_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 8, 1, 5, r)
#define RDD_CPU_RX_DESCRIPTOR_VPORT_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 8, 1, 5, v)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_SRC_UNION_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 13, 12, r)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_SRC_UNION_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 13, 12, v)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_SRC_UNION_READ(r, p)                         FIELD_MREAD_32((uint8_t *)p + 8, 13, 12, r)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_SRC_UNION_WRITE(v, p)                        FIELD_MWRITE_32((uint8_t *)p + 8, 13, 12, v)
#define RDD_CPU_RX_DESCRIPTOR_WAN_FLOW_ID_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 13, 12, r)
#define RDD_CPU_RX_DESCRIPTOR_WAN_FLOW_ID_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 13, 12, v)
#define RDD_CPU_RX_DESCRIPTOR_WAN_FLOW_ID_READ(r, p)                              FIELD_MREAD_32((uint8_t *)p + 8, 13, 12, r)
#define RDD_CPU_RX_DESCRIPTOR_WAN_FLOW_ID_WRITE(v, p)                             FIELD_MWRITE_32((uint8_t *)p + 8, 13, 12, v)
#define RDD_CPU_RX_DESCRIPTOR_SSID_READ_G(r, g, idx)                              GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 5, 4, r)
#define RDD_CPU_RX_DESCRIPTOR_SSID_WRITE_G(v, g, idx)                             GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 8, 5, 4, v)
#define RDD_CPU_RX_DESCRIPTOR_SSID_READ(r, p)                                     FIELD_MREAD_16((uint8_t *)p + 8, 5, 4, r)
#define RDD_CPU_RX_DESCRIPTOR_SSID_WRITE(v, p)                                    FIELD_MWRITE_16((uint8_t *)p + 8, 5, 4, v)
#define RDD_CPU_RX_DESCRIPTOR_DATA_OFFSET_READ_G(r, g, idx)                       GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 10, 6, 7, r)
#define RDD_CPU_RX_DESCRIPTOR_DATA_OFFSET_WRITE_G(v, g, idx)                      GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 10, 6, 7, v)
#define RDD_CPU_RX_DESCRIPTOR_DATA_OFFSET_READ(r, p)                              FIELD_MREAD_16((uint8_t *)p + 10, 6, 7, r)
#define RDD_CPU_RX_DESCRIPTOR_DATA_OFFSET_WRITE(v, p)                             FIELD_MWRITE_16((uint8_t *)p + 10, 6, 7, v)
#define RDD_CPU_RX_DESCRIPTOR_REASON_READ_G(r, g, idx)                            GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 11, 0, 6, r)
#define RDD_CPU_RX_DESCRIPTOR_REASON_WRITE_G(v, g, idx)                           GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 11, 0, 6, v)
#define RDD_CPU_RX_DESCRIPTOR_REASON_READ(r, p)                                   FIELD_MREAD_8((uint8_t *)p + 11, 0, 6, r)
#define RDD_CPU_RX_DESCRIPTOR_REASON_WRITE(v, p)                                  FIELD_MWRITE_8((uint8_t *)p + 11, 0, 6, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_EXCEPTION_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 7, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_EXCEPTION_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 7, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_EXCEPTION_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 12, 7, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_EXCEPTION_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 12, 7, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 6, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 6, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 12, 6, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_RX_OFFLOAD_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 12, 6, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_UCAST_READ_G(r, g, idx)                          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 5, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_UCAST_WRITE_G(v, g, idx)                         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 5, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_IS_UCAST_READ(r, p)                                 FIELD_MREAD_8((uint8_t *)p + 12, 5, 1, r)
#define RDD_CPU_RX_DESCRIPTOR_IS_UCAST_WRITE(v, p)                                FIELD_MWRITE_8((uint8_t *)p + 12, 5, 1, v)
#define RDD_CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_UNION_READ_G(r, g, idx)               GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 0, 13, r)
#define RDD_CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_UNION_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 0, 13, v)
#define RDD_CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_UNION_READ(r, p)                      FIELD_MREAD_16((uint8_t *)p + 12, 0, 13, r)
#define RDD_CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_UNION_WRITE(v, p)                     FIELD_MWRITE_16((uint8_t *)p + 12, 0, 13, v)
#define RDD_CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 2, 3, r)
#define RDD_CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 12, 2, 3, v)
#define RDD_CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p + 12, 2, 3, r)
#define RDD_CPU_RX_DESCRIPTOR_MCAST_TX_PRIO_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p + 12, 2, 3, v)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_METADATA_UNION_READ_G(r, g, idx)             GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 14, r)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_METADATA_UNION_WRITE_G(v, g, idx)            GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 14, v)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_METADATA_UNION_READ(r, p)                    MREAD_16((uint8_t *)p + 14, r)
#define RDD_CPU_RX_DESCRIPTOR_CPU_RX_METADATA_UNION_WRITE(v, p)                   MWRITE_16((uint8_t *)p + 14, v)
#define RDD_CPU_RX_DESCRIPTOR_DST_SSID_VECTOR_READ_G(r, g, idx)                   GROUP_MREAD_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 14, r)
#define RDD_CPU_RX_DESCRIPTOR_DST_SSID_VECTOR_WRITE_G(v, g, idx)                  GROUP_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 14, v)
#define RDD_CPU_RX_DESCRIPTOR_DST_SSID_VECTOR_READ(r, p)                          MREAD_16((uint8_t *)p + 14, r)
#define RDD_CPU_RX_DESCRIPTOR_DST_SSID_VECTOR_WRITE(v, p)                         MWRITE_16((uint8_t *)p + 14, v)
#define RDD_CPU_RX_DESCRIPTOR_METADATA_0_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 14, 2, 4, r)
#define RDD_CPU_RX_DESCRIPTOR_METADATA_0_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 14, 2, 4, v)
#define RDD_CPU_RX_DESCRIPTOR_METADATA_0_READ(r, p)                               FIELD_MREAD_8((uint8_t *)p + 14, 2, 4, r)
#define RDD_CPU_RX_DESCRIPTOR_METADATA_0_WRITE(v, p)                              FIELD_MWRITE_8((uint8_t *)p + 14, 2, 4, v)
#define RDD_CPU_RX_DESCRIPTOR_METADATA_1_READ_G(r, g, idx)                        GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 14, 0, 10, r)
#define RDD_CPU_RX_DESCRIPTOR_METADATA_1_WRITE_G(v, g, idx)                       GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_CPU_RX_DESCRIPTOR_DTS) + 14, 0, 10, v)
#define RDD_CPU_RX_DESCRIPTOR_METADATA_1_READ(r, p)                               FIELD_MREAD_16((uint8_t *)p + 14, 0, 10, r)
#define RDD_CPU_RX_DESCRIPTOR_METADATA_1_WRITE(v, p)                              FIELD_MWRITE_16((uint8_t *)p + 14, 0, 10, v)
#define CPU_FEED_DESCRIPTOR_PTR_LOW_F_OFFSET                               0
#define CPU_FEED_DESCRIPTOR_PTR_LOW_F_WIDTH                                32
#define CPU_FEED_DESCRIPTOR_PTR_LOW_OFFSET                                 0
#define CPU_FEED_DESCRIPTOR_TYPE_F_OFFSET                                  8
#define CPU_FEED_DESCRIPTOR_TYPE_F_WIDTH                                   1
#define CPU_FEED_DESCRIPTOR_TYPE_OFFSET                                    6
#define CPU_FEED_DESCRIPTOR_TYPE_F_OFFSET_MOD8                             0
#define CPU_FEED_DESCRIPTOR_PTR_HI_F_OFFSET                                0
#define CPU_FEED_DESCRIPTOR_PTR_HI_F_WIDTH                                 8
#define CPU_FEED_DESCRIPTOR_PTR_HI_OFFSET                                  7

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	ptr_low   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0 	:23	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	type      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ptr_hi    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	ptr_low   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ptr_hi    	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	type      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0 	:23	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_CPU_FEED_DESCRIPTOR_DTS;

#define RDD_CPU_FEED_DESCRIPTOR_PTR_LOW_READ_G(r, g, idx)            GROUP_MREAD_32(g, idx*sizeof(RDD_CPU_FEED_DESCRIPTOR_DTS), r)
#define RDD_CPU_FEED_DESCRIPTOR_PTR_LOW_WRITE_G(v, g, idx)           GROUP_MWRITE_32(g, idx*sizeof(RDD_CPU_FEED_DESCRIPTOR_DTS), v)
#define RDD_CPU_FEED_DESCRIPTOR_PTR_LOW_READ(r, p)                   MREAD_32((uint8_t *)p, r)
#define RDD_CPU_FEED_DESCRIPTOR_PTR_LOW_WRITE(v, p)                  MWRITE_32((uint8_t *)p, v)
#define RDD_CPU_FEED_DESCRIPTOR_TYPE_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_CPU_FEED_DESCRIPTOR_DTS) + 6, 0, 1, r)
#define RDD_CPU_FEED_DESCRIPTOR_TYPE_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_CPU_FEED_DESCRIPTOR_DTS) + 6, 0, 1, v)
#define RDD_CPU_FEED_DESCRIPTOR_TYPE_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 6, 0, 1, r)
#define RDD_CPU_FEED_DESCRIPTOR_TYPE_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 6, 0, 1, v)
#define RDD_CPU_FEED_DESCRIPTOR_PTR_HI_READ_G(r, g, idx)             GROUP_MREAD_8(g, idx*sizeof(RDD_CPU_FEED_DESCRIPTOR_DTS) + 7, r)
#define RDD_CPU_FEED_DESCRIPTOR_PTR_HI_WRITE_G(v, g, idx)            GROUP_MWRITE_8(g, idx*sizeof(RDD_CPU_FEED_DESCRIPTOR_DTS) + 7, v)
#define RDD_CPU_FEED_DESCRIPTOR_PTR_HI_READ(r, p)                    MREAD_8((uint8_t *)p + 7, r)
#define RDD_CPU_FEED_DESCRIPTOR_PTR_HI_WRITE(v, p)                   MWRITE_8((uint8_t *)p + 7, v)
#define CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_F_OFFSET                         27
#define CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_F_WIDTH                          5
#define CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_OFFSET                           0
#define CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_F_OFFSET_MOD8                    3
#define CPU_RING_DESCRIPTOR_SIZE_OF_ENTRY_F_OFFSET_MOD16                   11
#define CPU_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_F_OFFSET                     16
#define CPU_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_F_WIDTH                      11
#define CPU_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_OFFSET                       0
#define CPU_RING_DESCRIPTOR_NUMBER_OF_ENTRIES_F_OFFSET_MOD16               0
#define CPU_RING_DESCRIPTOR_INTERRUPT_ID_F_OFFSET                          0
#define CPU_RING_DESCRIPTOR_INTERRUPT_ID_F_WIDTH                           16
#define CPU_RING_DESCRIPTOR_INTERRUPT_ID_OFFSET                            2
#define CPU_RING_DESCRIPTOR_DROP_COUNTER_F_OFFSET                          16
#define CPU_RING_DESCRIPTOR_DROP_COUNTER_F_WIDTH                           16
#define CPU_RING_DESCRIPTOR_DROP_COUNTER_OFFSET                            4
#define CPU_RING_DESCRIPTOR_WRITE_IDX_F_OFFSET                             0
#define CPU_RING_DESCRIPTOR_WRITE_IDX_F_WIDTH                              16
#define CPU_RING_DESCRIPTOR_WRITE_IDX_OFFSET                               6
#define CPU_RING_DESCRIPTOR_BASE_ADDR_LOW_F_OFFSET                         0
#define CPU_RING_DESCRIPTOR_BASE_ADDR_LOW_F_WIDTH                          32
#define CPU_RING_DESCRIPTOR_BASE_ADDR_LOW_OFFSET                           8
#define CPU_RING_DESCRIPTOR_READ_IDX_F_OFFSET                              16
#define CPU_RING_DESCRIPTOR_READ_IDX_F_WIDTH                               16
#define CPU_RING_DESCRIPTOR_READ_IDX_OFFSET                                12
#define CPU_RING_DESCRIPTOR_LOW_PRIORITY_THRESHOLD_F_OFFSET                8
#define CPU_RING_DESCRIPTOR_LOW_PRIORITY_THRESHOLD_F_WIDTH                 8
#define CPU_RING_DESCRIPTOR_LOW_PRIORITY_THRESHOLD_OFFSET                  14
#define CPU_RING_DESCRIPTOR_BASE_ADDR_HIGH_F_OFFSET                        0
#define CPU_RING_DESCRIPTOR_BASE_ADDR_HIGH_F_WIDTH                         8
#define CPU_RING_DESCRIPTOR_BASE_ADDR_HIGH_OFFSET                          15
#define PERIPHERALS_STS_SCHEDULER_DEBUG_F_OFFSET                       27
#define PERIPHERALS_STS_SCHEDULER_DEBUG_F_WIDTH                        5
#define PERIPHERALS_STS_SCHEDULER_DEBUG_OFFSET                         0
#define PERIPHERALS_STS_SCHEDULER_DEBUG_F_OFFSET_MOD8                  3
#define PERIPHERALS_STS_SCHEDULER_DEBUG_F_OFFSET_MOD16                 11
#define PERIPHERALS_STS_NEXT_THREAD_IS_READY_F_OFFSET                  26
#define PERIPHERALS_STS_NEXT_THREAD_IS_READY_F_WIDTH                   1
#define PERIPHERALS_STS_NEXT_THREAD_IS_READY_OFFSET                    0
#define PERIPHERALS_STS_NEXT_THREAD_IS_READY_F_OFFSET_MOD8             2
#define PERIPHERALS_STS_NEXT_THREAD_IS_READY_F_OFFSET_MOD16            10
#define PERIPHERALS_STS_NEXT_THREAD_NUMBER_F_OFFSET                    21
#define PERIPHERALS_STS_NEXT_THREAD_NUMBER_F_WIDTH                     5
#define PERIPHERALS_STS_NEXT_THREAD_NUMBER_OFFSET                      0
#define PERIPHERALS_STS_NEXT_THREAD_NUMBER_F_OFFSET_MOD8               5
#define PERIPHERALS_STS_NEXT_THREAD_NUMBER_F_OFFSET_MOD16              5
#define PERIPHERALS_STS_CURRENT_THREAD_NUMBER_F_OFFSET                 16
#define PERIPHERALS_STS_CURRENT_THREAD_NUMBER_F_WIDTH                  5
#define PERIPHERALS_STS_CURRENT_THREAD_NUMBER_OFFSET                   1
#define PERIPHERALS_STS_CURRENT_THREAD_NUMBER_F_OFFSET_MOD8            0
#define PERIPHERALS_STS_CURRENT_THREAD_NUMBER_F_OFFSET_MOD16           0
#define PERIPHERALS_STS_TIMER_1_STATUS_F_OFFSET                        12
#define PERIPHERALS_STS_TIMER_1_STATUS_F_WIDTH                         1
#define PERIPHERALS_STS_TIMER_1_STATUS_OFFSET                          2
#define PERIPHERALS_STS_TIMER_1_STATUS_F_OFFSET_MOD8                   4
#define PERIPHERALS_STS_TIMER_0_STATUS_F_OFFSET                        11
#define PERIPHERALS_STS_TIMER_0_STATUS_F_WIDTH                         1
#define PERIPHERALS_STS_TIMER_0_STATUS_OFFSET                          2
#define PERIPHERALS_STS_TIMER_0_STATUS_F_OFFSET_MOD8                   3
#define PERIPHERALS_STS_RAM_READ_COMMAND_FIFO_FULL_F_OFFSET            8
#define PERIPHERALS_STS_RAM_READ_COMMAND_FIFO_FULL_F_WIDTH             1
#define PERIPHERALS_STS_RAM_READ_COMMAND_FIFO_FULL_OFFSET              2
#define PERIPHERALS_STS_RAM_READ_COMMAND_FIFO_FULL_F_OFFSET_MOD8       0
#define PERIPHERALS_STS_QUAD_ID_F_OFFSET                               6
#define PERIPHERALS_STS_QUAD_ID_F_WIDTH                                2
#define PERIPHERALS_STS_QUAD_ID_OFFSET                                 3
#define PERIPHERALS_STS_CORE_ID_F_OFFSET                               4
#define PERIPHERALS_STS_CORE_ID_F_WIDTH                                2
#define PERIPHERALS_STS_CORE_ID_OFFSET                                 3
#define PERIPHERALS_STS_BB_MESSAGE_PENDING_F_OFFSET                    3
#define PERIPHERALS_STS_BB_MESSAGE_PENDING_F_WIDTH                     1
#define PERIPHERALS_STS_BB_MESSAGE_PENDING_OFFSET                      3
#define PERIPHERALS_STS_BBTX_COMMAND_FIFO_IS_EMPTY_F_OFFSET            2
#define PERIPHERALS_STS_BBTX_COMMAND_FIFO_IS_EMPTY_F_WIDTH             1
#define PERIPHERALS_STS_BBTX_COMMAND_FIFO_IS_EMPTY_OFFSET              3
#define PERIPHERALS_STS_BBTX_COMMAND_FIFO_FULL_F_OFFSET                1
#define PERIPHERALS_STS_BBTX_COMMAND_FIFO_FULL_F_WIDTH                 1
#define PERIPHERALS_STS_BBTX_COMMAND_FIFO_FULL_OFFSET                  3
#define PERIPHERALS_STS_DMA_COMMAND_FIFO_FULL_F_OFFSET                 0
#define PERIPHERALS_STS_DMA_COMMAND_FIFO_FULL_F_WIDTH                  1
#define PERIPHERALS_STS_DMA_COMMAND_FIFO_FULL_OFFSET                   3

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	scheduler_debug           	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	next_thread_is_ready      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	next_thread_number        	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_thread_number     	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_1                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_1_status            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_0_status            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_2                	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ram_read_command_fifo_full	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	quad_id                   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	core_id                   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bb_message_pending        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbtx_command_fifo_is_empty	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbtx_command_fifo_full    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dma_command_fifo_full     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	dma_command_fifo_full     	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbtx_command_fifo_full    	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bbtx_command_fifo_is_empty	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	bb_message_pending        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	core_id                   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	quad_id                   	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	ram_read_command_fifo_full	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_2                	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_0_status            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	timer_1_status            	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved_1                	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	current_thread_number     	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	next_thread_number        	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	next_thread_is_ready      	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	scheduler_debug           	:5	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_PERIPHERALS_STS_DTS;

#define RDD_PERIPHERALS_STS_SCHEDULER_DEBUG_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS), 3, 5, r)
#define RDD_PERIPHERALS_STS_SCHEDULER_DEBUG_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS), 3, 5, v)
#define RDD_PERIPHERALS_STS_SCHEDULER_DEBUG_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p, 3, 5, r)
#define RDD_PERIPHERALS_STS_SCHEDULER_DEBUG_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p, 3, 5, v)
#define RDD_PERIPHERALS_STS_NEXT_THREAD_IS_READY_READ_G(r, g, idx)                GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS), 2, 1, r)
#define RDD_PERIPHERALS_STS_NEXT_THREAD_IS_READY_WRITE_G(v, g, idx)               GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS), 2, 1, v)
#define RDD_PERIPHERALS_STS_NEXT_THREAD_IS_READY_READ(r, p)                       FIELD_MREAD_8((uint8_t *)p, 2, 1, r)
#define RDD_PERIPHERALS_STS_NEXT_THREAD_IS_READY_WRITE(v, p)                      FIELD_MWRITE_8((uint8_t *)p, 2, 1, v)
#define RDD_PERIPHERALS_STS_NEXT_THREAD_NUMBER_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS), 5, 5, r)
#define RDD_PERIPHERALS_STS_NEXT_THREAD_NUMBER_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS), 5, 5, v)
#define RDD_PERIPHERALS_STS_NEXT_THREAD_NUMBER_READ(r, p)                         FIELD_MREAD_16((uint8_t *)p, 5, 5, r)
#define RDD_PERIPHERALS_STS_NEXT_THREAD_NUMBER_WRITE(v, p)                        FIELD_MWRITE_16((uint8_t *)p, 5, 5, v)
#define RDD_PERIPHERALS_STS_CURRENT_THREAD_NUMBER_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 1, 0, 5, r)
#define RDD_PERIPHERALS_STS_CURRENT_THREAD_NUMBER_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 1, 0, 5, v)
#define RDD_PERIPHERALS_STS_CURRENT_THREAD_NUMBER_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 1, 0, 5, r)
#define RDD_PERIPHERALS_STS_CURRENT_THREAD_NUMBER_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 1, 0, 5, v)
#define RDD_PERIPHERALS_STS_TIMER_1_STATUS_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 2, 4, 1, r)
#define RDD_PERIPHERALS_STS_TIMER_1_STATUS_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 2, 4, 1, v)
#define RDD_PERIPHERALS_STS_TIMER_1_STATUS_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 2, 4, 1, r)
#define RDD_PERIPHERALS_STS_TIMER_1_STATUS_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 2, 4, 1, v)
#define RDD_PERIPHERALS_STS_TIMER_0_STATUS_READ_G(r, g, idx)                      GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 2, 3, 1, r)
#define RDD_PERIPHERALS_STS_TIMER_0_STATUS_WRITE_G(v, g, idx)                     GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 2, 3, 1, v)
#define RDD_PERIPHERALS_STS_TIMER_0_STATUS_READ(r, p)                             FIELD_MREAD_8((uint8_t *)p + 2, 3, 1, r)
#define RDD_PERIPHERALS_STS_TIMER_0_STATUS_WRITE(v, p)                            FIELD_MWRITE_8((uint8_t *)p + 2, 3, 1, v)
#define RDD_PERIPHERALS_STS_RAM_READ_COMMAND_FIFO_FULL_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 2, 0, 1, r)
#define RDD_PERIPHERALS_STS_RAM_READ_COMMAND_FIFO_FULL_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 2, 0, 1, v)
#define RDD_PERIPHERALS_STS_RAM_READ_COMMAND_FIFO_FULL_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_PERIPHERALS_STS_RAM_READ_COMMAND_FIFO_FULL_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_PERIPHERALS_STS_QUAD_ID_READ_G(r, g, idx)                             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 6, 2, r)
#define RDD_PERIPHERALS_STS_QUAD_ID_WRITE_G(v, g, idx)                            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 6, 2, v)
#define RDD_PERIPHERALS_STS_QUAD_ID_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 3, 6, 2, r)
#define RDD_PERIPHERALS_STS_QUAD_ID_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 3, 6, 2, v)
#define RDD_PERIPHERALS_STS_CORE_ID_READ_G(r, g, idx)                             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 4, 2, r)
#define RDD_PERIPHERALS_STS_CORE_ID_WRITE_G(v, g, idx)                            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 4, 2, v)
#define RDD_PERIPHERALS_STS_CORE_ID_READ(r, p)                                    FIELD_MREAD_8((uint8_t *)p + 3, 4, 2, r)
#define RDD_PERIPHERALS_STS_CORE_ID_WRITE(v, p)                                   FIELD_MWRITE_8((uint8_t *)p + 3, 4, 2, v)
#define RDD_PERIPHERALS_STS_BB_MESSAGE_PENDING_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 3, 1, r)
#define RDD_PERIPHERALS_STS_BB_MESSAGE_PENDING_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 3, 1, v)
#define RDD_PERIPHERALS_STS_BB_MESSAGE_PENDING_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 3, 3, 1, r)
#define RDD_PERIPHERALS_STS_BB_MESSAGE_PENDING_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 3, 3, 1, v)
#define RDD_PERIPHERALS_STS_BBTX_COMMAND_FIFO_IS_EMPTY_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 2, 1, r)
#define RDD_PERIPHERALS_STS_BBTX_COMMAND_FIFO_IS_EMPTY_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 2, 1, v)
#define RDD_PERIPHERALS_STS_BBTX_COMMAND_FIFO_IS_EMPTY_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 3, 2, 1, r)
#define RDD_PERIPHERALS_STS_BBTX_COMMAND_FIFO_IS_EMPTY_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 3, 2, 1, v)
#define RDD_PERIPHERALS_STS_BBTX_COMMAND_FIFO_FULL_READ_G(r, g, idx)              GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 1, 1, r)
#define RDD_PERIPHERALS_STS_BBTX_COMMAND_FIFO_FULL_WRITE_G(v, g, idx)             GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 1, 1, v)
#define RDD_PERIPHERALS_STS_BBTX_COMMAND_FIFO_FULL_READ(r, p)                     FIELD_MREAD_8((uint8_t *)p + 3, 1, 1, r)
#define RDD_PERIPHERALS_STS_BBTX_COMMAND_FIFO_FULL_WRITE(v, p)                    FIELD_MWRITE_8((uint8_t *)p + 3, 1, 1, v)
#define RDD_PERIPHERALS_STS_DMA_COMMAND_FIFO_FULL_READ_G(r, g, idx)               GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 0, 1, r)
#define RDD_PERIPHERALS_STS_DMA_COMMAND_FIFO_FULL_WRITE_G(v, g, idx)              GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_PERIPHERALS_STS_DTS) + 3, 0, 1, v)
#define RDD_PERIPHERALS_STS_DMA_COMMAND_FIFO_FULL_READ(r, p)                      FIELD_MREAD_8((uint8_t *)p + 3, 0, 1, r)
#define RDD_PERIPHERALS_STS_DMA_COMMAND_FIFO_FULL_WRITE(v, p)                     FIELD_MWRITE_8((uint8_t *)p + 3, 0, 1, v)
#define HASH_COMMAND_CONFIGURATION_F_OFFSET                         29
#define HASH_COMMAND_CONFIGURATION_F_WIDTH                          3
#define HASH_COMMAND_CONFIGURATION_OFFSET                           0
#define HASH_COMMAND_CONFIGURATION_F_OFFSET_MOD8                    5
#define HASH_COMMAND_CONFIGURATION_F_OFFSET_MOD16                   13
#define HASH_COMMAND_AGING_F_OFFSET                                 28
#define HASH_COMMAND_AGING_F_WIDTH                                  1
#define HASH_COMMAND_AGING_OFFSET                                   0
#define HASH_COMMAND_AGING_F_OFFSET_MOD8                            4
#define HASH_COMMAND_AGING_F_OFFSET_MOD16                           12
#define HASH_COMMAND_KEY_1_F_OFFSET                                 0
#define HASH_COMMAND_KEY_1_F_WIDTH                                  28
#define HASH_COMMAND_KEY_1_OFFSET                                   0
#define HASH_COMMAND_KEY_0_F_OFFSET                                 0
#define HASH_COMMAND_KEY_0_F_WIDTH                                  32
#define HASH_COMMAND_KEY_0_OFFSET                                   4

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	configuration	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aging        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_1        	:28	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_0        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	key_1        	:28	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	aging        	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	configuration	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	key_0        	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_HASH_COMMAND_DTS;

#define RDD_HASH_COMMAND_CONFIGURATION_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_HASH_COMMAND_DTS), 5, 3, r)
#define RDD_HASH_COMMAND_CONFIGURATION_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_HASH_COMMAND_DTS), 5, 3, v)
#define RDD_HASH_COMMAND_CONFIGURATION_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p, 5, 3, r)
#define RDD_HASH_COMMAND_CONFIGURATION_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p, 5, 3, v)
#define RDD_HASH_COMMAND_AGING_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_HASH_COMMAND_DTS), 4, 1, r)
#define RDD_HASH_COMMAND_AGING_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_HASH_COMMAND_DTS), 4, 1, v)
#define RDD_HASH_COMMAND_AGING_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p, 4, 1, r)
#define RDD_HASH_COMMAND_AGING_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p, 4, 1, v)
#define RDD_HASH_COMMAND_KEY_1_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_32(g, idx*sizeof(RDD_HASH_COMMAND_DTS), 0, 28, r)
#define RDD_HASH_COMMAND_KEY_1_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_32(g, idx*sizeof(RDD_HASH_COMMAND_DTS), 0, 28, v)
#define RDD_HASH_COMMAND_KEY_1_READ(r, p)                         FIELD_MREAD_32((uint8_t *)p, 0, 28, r)
#define RDD_HASH_COMMAND_KEY_1_WRITE(v, p)                        FIELD_MWRITE_32((uint8_t *)p, 0, 28, v)
#define RDD_HASH_COMMAND_KEY_0_READ_G(r, g, idx)                  GROUP_MREAD_32(g, idx*sizeof(RDD_HASH_COMMAND_DTS) + 4, r)
#define RDD_HASH_COMMAND_KEY_0_WRITE_G(v, g, idx)                 GROUP_MWRITE_32(g, idx*sizeof(RDD_HASH_COMMAND_DTS) + 4, v)
#define RDD_HASH_COMMAND_KEY_0_READ(r, p)                         MREAD_32((uint8_t *)p + 4, r)
#define RDD_HASH_COMMAND_KEY_0_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 4, v)
#define GPE_COMMAND_OPCODE_F_OFFSET                                12
#define GPE_COMMAND_OPCODE_F_WIDTH                                 4
#define GPE_COMMAND_OPCODE_OFFSET                                  0
#define GPE_COMMAND_OPCODE_F_OFFSET_MOD8                           4
#define GPE_COMMAND_OFFSET_F_OFFSET                                6
#define GPE_COMMAND_OFFSET_F_WIDTH                                 6
#define GPE_COMMAND_OFFSET_OFFSET                                  0
#define GPE_COMMAND_TARGET_MEMORY_F_OFFSET                         4
#define GPE_COMMAND_TARGET_MEMORY_F_WIDTH                          2
#define GPE_COMMAND_TARGET_MEMORY_OFFSET                           1
#define GPE_COMMAND_LENGTH_F_OFFSET                                0
#define GPE_COMMAND_LENGTH_F_WIDTH                                 4
#define GPE_COMMAND_LENGTH_OFFSET                                  1

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	opcode       	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	offset       	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	target_memory	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	length       	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint16_t	length       	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	target_memory	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	offset       	:6	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint16_t	opcode       	:4	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_GPE_COMMAND_DTS;

#define RDD_GPE_COMMAND_OPCODE_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_GPE_COMMAND_DTS), 4, 4, r)
#define RDD_GPE_COMMAND_OPCODE_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_GPE_COMMAND_DTS), 4, 4, v)
#define RDD_GPE_COMMAND_OPCODE_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 4, 4, r)
#define RDD_GPE_COMMAND_OPCODE_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 4, 4, v)
#define RDD_GPE_COMMAND_OFFSET_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_GPE_COMMAND_DTS), 6, 6, r)
#define RDD_GPE_COMMAND_OFFSET_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_GPE_COMMAND_DTS), 6, 6, v)
#define RDD_GPE_COMMAND_OFFSET_READ(r, p)                        FIELD_MREAD_16((uint8_t *)p, 6, 6, r)
#define RDD_GPE_COMMAND_OFFSET_WRITE(v, p)                       FIELD_MWRITE_16((uint8_t *)p, 6, 6, v)
#define RDD_GPE_COMMAND_TARGET_MEMORY_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_GPE_COMMAND_DTS) + 1, 4, 2, r)
#define RDD_GPE_COMMAND_TARGET_MEMORY_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_GPE_COMMAND_DTS) + 1, 4, 2, v)
#define RDD_GPE_COMMAND_TARGET_MEMORY_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 1, 4, 2, r)
#define RDD_GPE_COMMAND_TARGET_MEMORY_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 1, 4, 2, v)
#define RDD_GPE_COMMAND_LENGTH_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_GPE_COMMAND_DTS) + 1, 0, 4, r)
#define RDD_GPE_COMMAND_LENGTH_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_GPE_COMMAND_DTS) + 1, 0, 4, v)
#define RDD_GPE_COMMAND_LENGTH_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p + 1, 0, 4, r)
#define RDD_GPE_COMMAND_LENGTH_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p + 1, 0, 4, v)
#define RULE_BASED_NATC_KEY_ENTRY_VALID_F_OFFSET                                 31
#define RULE_BASED_NATC_KEY_ENTRY_VALID_F_WIDTH                                  1
#define RULE_BASED_NATC_KEY_ENTRY_VALID_OFFSET                                   0
#define RULE_BASED_NATC_KEY_ENTRY_VALID_F_OFFSET_MOD8                            7
#define RULE_BASED_NATC_KEY_ENTRY_VALID_F_OFFSET_MOD16                           15
#define RULE_BASED_NATC_KEY_ENTRY_SUB_TABLE_ID_F_OFFSET                          12
#define RULE_BASED_NATC_KEY_ENTRY_SUB_TABLE_ID_F_WIDTH                           3
#define RULE_BASED_NATC_KEY_ENTRY_SUB_TABLE_ID_OFFSET                            2
#define RULE_BASED_NATC_KEY_ENTRY_SUB_TABLE_ID_F_OFFSET_MOD8                     4
#define RULE_BASED_NATC_KEY_ENTRY_EXTENSION_F_OFFSET                             24
#define RULE_BASED_NATC_KEY_ENTRY_EXTENSION_F_WIDTH                              1
#define RULE_BASED_NATC_KEY_ENTRY_EXTENSION_OFFSET                               12
#define RULE_BASED_NATC_KEY_ENTRY_EXTENSION_F_OFFSET_MOD8                        0
#define RULE_BASED_NATC_KEY_ENTRY_EXTENSION_F_OFFSET_MOD16                       8
#define RULE_BASED_NATC_KEY_ENTRY_PORT_F_OFFSET                                  16
#define RULE_BASED_NATC_KEY_ENTRY_PORT_F_WIDTH                                   8
#define RULE_BASED_NATC_KEY_ENTRY_PORT_OFFSET                                    13
#define RULE_BASED_NATC_KEY_ENTRY_PORT_F_OFFSET_MOD16                            0
#define RULE_BASED_NATC_KEY_ENTRY_RULE_F_OFFSET                                  0
#define RULE_BASED_NATC_KEY_ENTRY_RULE_F_WIDTH                                   16
#define RULE_BASED_NATC_KEY_ENTRY_RULE_OFFSET                                    14

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	valid       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sub_table_id	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2   	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5   	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	extension   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rule        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#else
	uint32_t	reserved2   	:12	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sub_table_id	:3	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved0   	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	valid       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved3   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved4   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rule        	:16	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	port        	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	extension   	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved5   	:7	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RULE_BASED_NATC_KEY_ENTRY_DTS;

#define RDD_RULE_BASED_NATC_KEY_ENTRY_VALID_READ_G(r, g, idx)                 GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS), 7, 1, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_VALID_WRITE_G(v, g, idx)                GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS), 7, 1, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_VALID_READ(r, p)                        FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_VALID_WRITE(v, p)                       FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_SUB_TABLE_ID_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS) + 2, 4, 3, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_SUB_TABLE_ID_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS) + 2, 4, 3, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_SUB_TABLE_ID_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 2, 4, 3, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_SUB_TABLE_ID_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 2, 4, 3, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_EXTENSION_READ_G(r, g, idx)             GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS) + 12, 0, 1, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_EXTENSION_WRITE_G(v, g, idx)            GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS) + 12, 0, 1, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_EXTENSION_READ(r, p)                    FIELD_MREAD_8((uint8_t *)p + 12, 0, 1, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_EXTENSION_WRITE(v, p)                   FIELD_MWRITE_8((uint8_t *)p + 12, 0, 1, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_PORT_READ_G(r, g, idx)                  GROUP_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS) + 13, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_PORT_WRITE_G(v, g, idx)                 GROUP_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS) + 13, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_PORT_READ(r, p)                         MREAD_8((uint8_t *)p + 13, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_PORT_WRITE(v, p)                        MWRITE_8((uint8_t *)p + 13, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_RULE_READ_G(r, g, idx)                  GROUP_MREAD_16(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS) + 14, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_RULE_WRITE_G(v, g, idx)                 GROUP_MWRITE_16(g, idx*sizeof(RDD_RULE_BASED_NATC_KEY_ENTRY_DTS) + 14, v)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_RULE_READ(r, p)                         MREAD_16((uint8_t *)p + 14, r)
#define RDD_RULE_BASED_NATC_KEY_ENTRY_RULE_WRITE(v, p)                        MWRITE_16((uint8_t *)p + 14, v)
#define RULE_BASED_NATC_CONTEXT_ENTRY_NATC_CONTROL_F_OFFSET                          0
#define RULE_BASED_NATC_CONTEXT_ENTRY_NATC_CONTROL_F_WIDTH                           32
#define RULE_BASED_NATC_CONTEXT_ENTRY_NATC_CONTROL_OFFSET                            0
#define RULE_BASED_NATC_CONTEXT_ENTRY_HW_RESERVED0_F_OFFSET                          0
#define RULE_BASED_NATC_CONTEXT_ENTRY_HW_RESERVED0_F_WIDTH                           32
#define RULE_BASED_NATC_CONTEXT_ENTRY_HW_RESERVED0_OFFSET                            4
#define RULE_BASED_NATC_CONTEXT_ENTRY_UNTAGGED_OFFSET_F_OFFSET                       24
#define RULE_BASED_NATC_CONTEXT_ENTRY_UNTAGGED_OFFSET_F_WIDTH                        8
#define RULE_BASED_NATC_CONTEXT_ENTRY_UNTAGGED_OFFSET_OFFSET                         8
#define RULE_BASED_NATC_CONTEXT_ENTRY_UNTAGGED_OFFSET_F_OFFSET_MOD16                 8
#define RULE_BASED_NATC_CONTEXT_ENTRY_SINGLE_TAG_CL_OFFSET_F_OFFSET                  16
#define RULE_BASED_NATC_CONTEXT_ENTRY_SINGLE_TAG_CL_OFFSET_F_WIDTH                   8
#define RULE_BASED_NATC_CONTEXT_ENTRY_SINGLE_TAG_CL_OFFSET_OFFSET                    9
#define RULE_BASED_NATC_CONTEXT_ENTRY_SINGLE_TAG_CL_OFFSET_F_OFFSET_MOD16            0
#define RULE_BASED_NATC_CONTEXT_ENTRY_DUAL_TAG_CL_OFFSET_F_OFFSET                    8
#define RULE_BASED_NATC_CONTEXT_ENTRY_DUAL_TAG_CL_OFFSET_F_WIDTH                     8
#define RULE_BASED_NATC_CONTEXT_ENTRY_DUAL_TAG_CL_OFFSET_OFFSET                      10
#define RULE_BASED_NATC_CONTEXT_ENTRY_P_TAG_CL_OFFSET_F_OFFSET                       0
#define RULE_BASED_NATC_CONTEXT_ENTRY_P_TAG_CL_OFFSET_F_WIDTH                        8
#define RULE_BASED_NATC_CONTEXT_ENTRY_P_TAG_CL_OFFSET_OFFSET                         11
#define RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_OFFSET                                12
#define RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_F_OFFSET_MOD16                        8
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_NUMBER	52

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	natc_control                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hw_reserved0                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	untagged_offset                                                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	single_tag_cl_offset                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dual_tag_cl_offset                                             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	p_tag_cl_offset                                                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	cmd_list[RDD_RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_NUMBER];
#else
	uint32_t	natc_control                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	hw_reserved0                                                   	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	p_tag_cl_offset                                                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	dual_tag_cl_offset                                             	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	single_tag_cl_offset                                           	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	untagged_offset                                                	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	cmd_list[RDD_RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS;

#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_NATC_CONTROL_READ_G(r, g, idx)                  GROUP_MREAD_32(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS), r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_NATC_CONTROL_WRITE_G(v, g, idx)                 GROUP_MWRITE_32(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS), v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_NATC_CONTROL_READ(r, p)                         MREAD_32((uint8_t *)p, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_NATC_CONTROL_WRITE(v, p)                        MWRITE_32((uint8_t *)p, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_HW_RESERVED0_READ_G(r, g, idx)                  GROUP_MREAD_32(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 4, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_HW_RESERVED0_WRITE_G(v, g, idx)                 GROUP_MWRITE_32(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 4, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_HW_RESERVED0_READ(r, p)                         MREAD_32((uint8_t *)p + 4, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_HW_RESERVED0_WRITE(v, p)                        MWRITE_32((uint8_t *)p + 4, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_UNTAGGED_OFFSET_READ_G(r, g, idx)               GROUP_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 8, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_UNTAGGED_OFFSET_WRITE_G(v, g, idx)              GROUP_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 8, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_UNTAGGED_OFFSET_READ(r, p)                      MREAD_8((uint8_t *)p + 8, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_UNTAGGED_OFFSET_WRITE(v, p)                     MWRITE_8((uint8_t *)p + 8, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_SINGLE_TAG_CL_OFFSET_READ_G(r, g, idx)          GROUP_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 9, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_SINGLE_TAG_CL_OFFSET_WRITE_G(v, g, idx)         GROUP_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 9, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_SINGLE_TAG_CL_OFFSET_READ(r, p)                 MREAD_8((uint8_t *)p + 9, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_SINGLE_TAG_CL_OFFSET_WRITE(v, p)                MWRITE_8((uint8_t *)p + 9, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DUAL_TAG_CL_OFFSET_READ_G(r, g, idx)            GROUP_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 10, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DUAL_TAG_CL_OFFSET_WRITE_G(v, g, idx)           GROUP_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 10, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DUAL_TAG_CL_OFFSET_READ(r, p)                   MREAD_8((uint8_t *)p + 10, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DUAL_TAG_CL_OFFSET_WRITE(v, p)                  MWRITE_8((uint8_t *)p + 10, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_P_TAG_CL_OFFSET_READ_G(r, g, idx)               GROUP_MREAD_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 11, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_P_TAG_CL_OFFSET_WRITE_G(v, g, idx)              GROUP_MWRITE_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 11, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_P_TAG_CL_OFFSET_READ(r, p)                      MREAD_8((uint8_t *)p + 11, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_P_TAG_CL_OFFSET_WRITE(v, p)                     MWRITE_8((uint8_t *)p + 11, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_READ_G(r, g, idx, i)                   GROUP_MREAD_I_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 12, i, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_WRITE_G(v, g, idx, i)                  GROUP_MWRITE_I_8(g, idx*sizeof(RDD_RULE_BASED_NATC_CONTEXT_ENTRY_DTS) + 12, i, v)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_READ(r, p, i)                          MREAD_I_8((uint8_t *)p + 12, i, r)
#define RDD_RULE_BASED_NATC_CONTEXT_ENTRY_CMD_LIST_WRITE(v, p, i)                         MWRITE_I_8((uint8_t *)p + 12, i, v)
#define VLAN_ACTION_CONTEXT_ENTRY_CMD_OFFSET                                     0
#define RDD_VLAN_ACTION_CONTEXT_ENTRY_CMD_NUMBER	32

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint16_t	cmd[RDD_VLAN_ACTION_CONTEXT_ENTRY_CMD_NUMBER];
#else
	uint16_t	cmd[RDD_VLAN_ACTION_CONTEXT_ENTRY_CMD_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_VLAN_ACTION_CONTEXT_ENTRY_DTS;

#define RDD_VLAN_ACTION_CONTEXT_ENTRY_CMD_READ_G(r, g, idx, i)       GROUP_MREAD_I_16(g, idx*sizeof(RDD_VLAN_ACTION_CONTEXT_ENTRY_DTS), i, r)
#define RDD_VLAN_ACTION_CONTEXT_ENTRY_CMD_WRITE_G(v, g, idx, i)      GROUP_MWRITE_I_16(g, idx*sizeof(RDD_VLAN_ACTION_CONTEXT_ENTRY_DTS), i, v)
#define RDD_VLAN_ACTION_CONTEXT_ENTRY_CMD_READ(r, p, i)              MREAD_I_16((uint8_t *)p, i, r)
#define RDD_VLAN_ACTION_CONTEXT_ENTRY_CMD_WRITE(v, p, i)             MWRITE_I_16((uint8_t *)p, i, v)
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_F_OFFSET                               31
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_F_WIDTH                                1
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_OFFSET                                 0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_F_OFFSET_MOD8                          7
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_F_OFFSET_MOD16                         15
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_F_OFFSET                            8
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_F_WIDTH                             1
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_OFFSET                              2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_F_OFFSET_MOD8                       0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_F_OFFSET                           0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_F_WIDTH                            8
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_OFFSET                             3
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_F_OFFSET                    0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_F_WIDTH                     32
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_OFFSET                      4
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_F_OFFSET                    18
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_F_WIDTH                     14
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_OFFSET                      8
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_F_OFFSET_MOD16              2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_F_OFFSET                    16
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_F_WIDTH                     2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_OFFSET                      9
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_F_OFFSET_MOD8               0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_F_OFFSET_MOD16              0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_MANTISSA_F_OFFSET                    2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_MANTISSA_F_WIDTH                     14
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_MANTISSA_OFFSET                      10
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_EXPONENT_F_OFFSET                    0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_EXPONENT_F_WIDTH                     2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_EXPONENT_OFFSET                      11
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_F_OFFSET                    0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_F_WIDTH                     32
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_OFFSET                      12
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_F_OFFSET                    18
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_F_WIDTH                     14
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_OFFSET                      16
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_F_OFFSET_MOD16              2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_F_OFFSET                    16
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_F_WIDTH                     2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_OFFSET                      17
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_F_OFFSET_MOD8               0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_F_OFFSET_MOD16              0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_MANTISSA_F_OFFSET                    2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_MANTISSA_F_WIDTH                     14
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_MANTISSA_OFFSET                      18
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_EXPONENT_F_OFFSET                    0
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_EXPONENT_F_WIDTH                     2
#define COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_EXPONENT_OFFSET                      19
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_RESERVED_NUMBER	12

typedef struct
{
#ifndef FIRMWARE_LITTLE_ENDIAN
	uint32_t	rl_type                                                          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                        	:22	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	block_type                                                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	block_index                                                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_current_budget                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_alloc_mantissa                                               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_alloc_exponent                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_limit_mantissa                                               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_limit_exponent                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_current_budget                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_alloc_mantissa                                               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_alloc_exponent                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_limit_mantissa                                               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_limit_exponent                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved[RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_RESERVED_NUMBER];
#else
	uint32_t	block_index                                                      	:8	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	block_type                                                       	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	reserved2                                                        	:22	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	rl_type                                                          	:1	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_current_budget                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_limit_exponent                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_limit_mantissa                                               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_alloc_exponent                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	sir_alloc_mantissa                                               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_current_budget                                               	:32	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_limit_exponent                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_limit_mantissa                                               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_alloc_exponent                                               	:2	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint32_t	pir_alloc_mantissa                                               	:14	__PACKING_ATTRIBUTE_FIELD_LEVEL__;
	uint8_t	reserved[RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_RESERVED_NUMBER];
#endif
}
__PACKING_ATTRIBUTE_STRUCT_END__ RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS;

#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_READ_G(r, g, idx)                     GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS), 7, 1, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_WRITE_G(v, g, idx)                    GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS), 7, 1, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_READ(r, p)                            FIELD_MREAD_8((uint8_t *)p, 7, 1, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_RL_TYPE_WRITE(v, p)                           FIELD_MWRITE_8((uint8_t *)p, 7, 1, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_READ_G(r, g, idx)                  GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 2, 0, 1, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_WRITE_G(v, g, idx)                 GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 2, 0, 1, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_READ(r, p)                         FIELD_MREAD_8((uint8_t *)p + 2, 0, 1, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_TYPE_WRITE(v, p)                        FIELD_MWRITE_8((uint8_t *)p + 2, 0, 1, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_READ_G(r, g, idx)                 GROUP_MREAD_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 3, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_WRITE_G(v, g, idx)                GROUP_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 3, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_READ(r, p)                        MREAD_8((uint8_t *)p + 3, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_BLOCK_INDEX_WRITE(v, p)                       MWRITE_8((uint8_t *)p + 3, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 4, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 4, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_READ(r, p)                 MREAD_32((uint8_t *)p + 4, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_CURRENT_BUDGET_WRITE(v, p)                MWRITE_32((uint8_t *)p + 4, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 8, 2, 14, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 8, 2, 14, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 8, 2, 14, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_MANTISSA_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 8, 2, 14, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 9, 0, 2, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 9, 0, 2, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 9, 0, 2, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_ALLOC_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 9, 0, 2, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_MANTISSA_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 10, 2, 14, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_MANTISSA_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 10, 2, 14, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_MANTISSA_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 10, 2, 14, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_MANTISSA_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 10, 2, 14, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_EXPONENT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 11, 0, 2, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_EXPONENT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 11, 0, 2, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 11, 0, 2, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_SIR_LIMIT_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 11, 0, 2, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_READ_G(r, g, idx)          GROUP_MREAD_32(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 12, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_WRITE_G(v, g, idx)         GROUP_MWRITE_32(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 12, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_READ(r, p)                 MREAD_32((uint8_t *)p + 12, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_CURRENT_BUDGET_WRITE(v, p)                MWRITE_32((uint8_t *)p + 12, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 16, 2, 14, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 16, 2, 14, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 16, 2, 14, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_MANTISSA_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 16, 2, 14, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 17, 0, 2, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 17, 0, 2, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 17, 0, 2, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_ALLOC_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 17, 0, 2, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_MANTISSA_READ_G(r, g, idx)          GROUP_FIELD_MREAD_16(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 18, 2, 14, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_MANTISSA_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_16(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 18, 2, 14, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_MANTISSA_READ(r, p)                 FIELD_MREAD_16((uint8_t *)p + 18, 2, 14, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_MANTISSA_WRITE(v, p)                FIELD_MWRITE_16((uint8_t *)p + 18, 2, 14, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_EXPONENT_READ_G(r, g, idx)          GROUP_FIELD_MREAD_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 19, 0, 2, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_EXPONENT_WRITE_G(v, g, idx)         GROUP_FIELD_MWRITE_8(g, idx*sizeof(RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_DTS) + 19, 0, 2, v)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_EXPONENT_READ(r, p)                 FIELD_MREAD_8((uint8_t *)p + 19, 0, 2, r)
#define RDD_COMPLEX_RATE_LIMITER_DESCRIPTOR_PIR_LIMIT_EXPONENT_WRITE(v, p)                FIELD_MWRITE_8((uint8_t *)p + 19, 0, 2, v)
#endif /* _RDD_DATA_STRUCTURES_AUTO_H_ */
