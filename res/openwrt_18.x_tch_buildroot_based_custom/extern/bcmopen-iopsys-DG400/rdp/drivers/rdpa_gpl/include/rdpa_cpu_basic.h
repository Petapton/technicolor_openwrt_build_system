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


#ifndef RDPA_CPU_BASIC_H_
#define RDPA_CPU_BASIC_H_

/** \addtogroup cpu CPU Interface
 *
 * @{
 */

/** CPU trap reasons */
typedef enum
{
    rdpa_cpu_reason_min = 0,

    rdpa_cpu_rx_reason_oam                 = 0, /**< OAM packet */
    rdpa_cpu_rx_reason_omci                = 1, /**< OMCI packet */
    rdpa_cpu_rx_reason_flow                = 2,
    rdpa_cpu_rx_reason_mcast               = 3, /**< Multicat packet */
    rdpa_cpu_rx_reason_bcast               = 4, /**< Broadcast packet */
    rdpa_cpu_rx_reason_igmp                = 5, /**< Igmp packet */
    rdpa_cpu_rx_reason_icmpv6              = 6, /**< Icmpv6 packet */
    rdpa_cpu_rx_reason_mac_trap_0          = 7,
    rdpa_cpu_rx_reason_mac_trap_1          = 8,
    rdpa_cpu_rx_reason_mac_trap_2          = 9,
    rdpa_cpu_rx_reason_mac_trap_3          = 10,
    rdpa_cpu_rx_reason_dhcp                = 11, /**< DHCP packet */
    rdpa_cpu_rx_reason_non_tcp_udp         = 12, /**< Packet is non TCP or UDP */
    rdpa_cpu_rx_reason_cpu_mirroring       = 13, /**< CPU ingress packet copy */
    rdpa_cpu_rx_reason_hdr_err             = 14, /**< Packet with IP header error */
    rdpa_cpu_rx_reason_sa_moved            = 15, /**< SA move indication*/
    rdpa_cpu_rx_reason_unknown_sa          = 16, /**< Unknown SA indication */
    rdpa_cpu_rx_reason_unknown_da          = 17, /**< Unknown DA indication */
    rdpa_cpu_rx_reason_ip_frag             = 18, /**< Packet is fragmented */
    rdpa_cpu_rx_reason_mac_spoofing        = 19, /**< Mac spoofing \XRDP_LIMITED */
    rdpa_cpu_rx_reason_direct_queue_0      = 20, /* */
    rdpa_cpu_rx_reason_direct_queue_1      = 21, /* */
    rdpa_cpu_rx_reason_direct_queue_2      = 22, /* */
    rdpa_cpu_rx_reason_direct_queue_3      = 23, /* */
    rdpa_cpu_rx_reason_direct_queue_4      = 24, /* */
    rdpa_cpu_rx_reason_direct_queue_5      = 25, /* */
    rdpa_cpu_rx_reason_direct_queue_6      = 26, /* */
    rdpa_cpu_rx_reason_direct_queue_7      = 27, /* */
    rdpa_cpu_rx_reason_etype_udef_0        = 28, /**< User defined ethertype 1 */
    rdpa_cpu_rx_reason_etype_udef_1        = 29, /**< User defined ethertype 2 */
    rdpa_cpu_rx_reason_etype_udef_2        = 30, /**< User defined ethertype 3 */
    rdpa_cpu_rx_reason_etype_udef_3        = 31, /**< User defined ethertype 4 */
    rdpa_cpu_rx_reason_etype_pppoe_d       = 32, /**< PPPoE Discovery */
    rdpa_cpu_rx_reason_etype_pppoe_s       = 33, /**< PPPoE Source */
    rdpa_cpu_rx_reason_etype_arp           = 34, /**< Packet with ethertype Arp */
    rdpa_cpu_rx_reason_etype_ptp_1588      = 35, /**< Packet with ethertype 1588 */
    rdpa_cpu_rx_reason_etype_802_1x        = 36, /**< Packet with ethertype 802_1x */
    rdpa_cpu_rx_reason_etype_801_1ag_cfm   = 37, /**< Packet with ethertype v801 Lag CFG*/
    rdpa_cpu_rx_reason_pci_ip_flow_miss_1  = 38, /**< DHD PCI flow miss radio 1 */
    rdpa_cpu_rx_reason_pci_ip_flow_miss_2  = 39, /**< DHD PCI flow miss radio 2 */
    rdpa_cpu_rx_reason_pci_ip_flow_miss_3  = 40, /**< DHD PCI flow miss radio 3 */
    rdpa_cpu_rx_reason_ip_flow_miss        = 41, /**< Flow miss indication */
    rdpa_cpu_rx_reason_tcp_flags           = 42, /**< TCP flag indication */
    rdpa_cpu_rx_reason_ttl_expired         = 43, /**< TTL expired indication */
    rdpa_cpu_rx_reason_mtu_exceeded        = 44, /**< MTU exceeded indication */
    rdpa_cpu_rx_reason_l4_icmp             = 45, /**< layer-4 ICMP protocol */
    rdpa_cpu_rx_reason_l4_esp              = 46, /**< layer-4 ESP protocol */
    rdpa_cpu_rx_reason_l4_gre              = 47, /**< layer-4 GRE protocol */
    rdpa_cpu_rx_reason_l4_ah               = 48, /**< layer-4 AH protocol */
    rdpa_cpu_rx_reason_parser_error        = 49, /**< Error when parsing packet \XRDP_LIMITED */
    rdpa_cpu_rx_reason_l4_ipv6             = 50, /**< layer-4 IPV6 protocol */
    rdpa_cpu_rx_reason_l4_udef_0           = 51, /**< User defined layer-4 1 */
    rdpa_cpu_rx_reason_l4_udef_1           = 52, /**< User defined layer-4 2 */
    rdpa_cpu_rx_reason_l4_udef_2           = 53, /**< User defined layer-4 3 */
    rdpa_cpu_rx_reason_l4_udef_3           = 54, /**< User defined layer-4 4 */
    rdpa_cpu_rx_reason_reserved8           = 55, /* */
    rdpa_cpu_rx_reason_udef_0              = 56, /**< User defined 1 */
    rdpa_cpu_rx_reason_udef_1              = 57, /**< User defined 2 */
    rdpa_cpu_rx_reason_udef_2              = 58, /**< User defined 3 */
    rdpa_cpu_rx_reason_udef_3              = 59, /**< User defined 4 */
    rdpa_cpu_rx_reason_udef_4              = 60, /**< User defined 5 */
    rdpa_cpu_rx_reason_udef_5              = 61, /**< User defined 6 */
    rdpa_cpu_rx_reason_udef_6              = 62, /**< User defined 7 */
    rdpa_cpu_rx_reason_udef_7              = 63, /**< User defined 8 */
    rdpa_cpu_rx_reason_pbit_0              = rdpa_cpu_rx_reason_udef_0, /**< Vlan Pbit 0 */
    rdpa_cpu_rx_reason_pbit_1              = rdpa_cpu_rx_reason_udef_1, /**< Vlan Pbit 1 */
    rdpa_cpu_rx_reason_pbit_2              = rdpa_cpu_rx_reason_udef_2, /**< Vlan Pbit 2 */
    rdpa_cpu_rx_reason_pbit_3              = rdpa_cpu_rx_reason_udef_3, /**< Vlan Pbit 3 */
    rdpa_cpu_rx_reason_pbit_4              = rdpa_cpu_rx_reason_udef_4, /**< Vlan Pbit 4 */
    rdpa_cpu_rx_reason_pbit_5              = rdpa_cpu_rx_reason_udef_5, /**< Vlan Pbit 5 */
    rdpa_cpu_rx_reason_pbit_6              = rdpa_cpu_rx_reason_udef_6, /**< Vlan Pbit 6 */
    rdpa_cpu_rx_reason_pbit_7              = rdpa_cpu_rx_reason_udef_7, /**< Vlan Pbit 7 */

    rdpa_cpu_reason__num_of
} rdpa_cpu_reason;

/** CPU port */
typedef enum
{
    rdpa_cpu_port_first = 0,
#ifndef XRDP
    rdpa_cpu_host = rdpa_cpu_port_first,      /**< Host RX */
    rdpa_cpu_wlan0,     /**< WLAN 0 TX */
    rdpa_cpu_wlan1,     /* Reserved for future use */
#else
    rdpa_cpu0 = rdpa_cpu_port_first,
    rdpa_cpu_host = rdpa_cpu0, /**< Host RX */
    rdpa_cpu1,
    rdpa_cpu2,
    rdpa_cpu3,
    rdpa_cpu4,
    rdpa_cpu5,
    rdpa_cpu_wlan0 = rdpa_cpu5,     /**< WLAN 0 TX */
    rdpa_cpu6,
    rdpa_cpu_wlan1 = rdpa_cpu6,
    rdpa_cpu7,
    rdpa_cpu_wlan2 = rdpa_cpu7,
#endif
    rdpa_cpu_port__num_of,
    rdpa_cpu_none
} rdpa_cpu_port;

#define RDPA_CPU_MAX_QUEUES 8 /**< Max number of queues on host port */
#ifndef XRDP
#define RDPA_WLAN_MAX_QUEUES 6 /**< Max number of queues on WLAN port */
#endif

/** TC */
#define RDPA_CPU_TC_LOW 0
#define RDPA_CPU_TC_NUM 8

/** CPU reason table indicies */
#define CPU_REASON_LAN_TABLE_INDEX  0
#define CPU_REASON_WAN0_TABLE_INDEX 0
#define CPU_REASON_WAN1_TABLE_INDEX 1

/** @} end of cpu Doxygen group */

/** \addtogroup cpu_tx Transmit
 *
 * @{
 */

/** CPU tx packet insertion point */
typedef enum
{
    rdpa_cpu_tx_port = 0,           /**< Egress port and priority are specified explicitly. This is the most common mode */
    rdpa_cpu_tx_egress = 0,         /**< Egress port and priority are specified explicitly. This is the most common mode same as rdpa_cpu_tx_egress*/
    rdpa_cpu_tx_bridge = 1,         /**< Before bridge forwarding decision, before classification */
    rdpa_cpu_tx_ingress = 1,        /**< Before bridge forwarding decision, before classification same as rdpa_cpu_tx_bridge*/

    rdpa_cpu_tx_entry__num_of   /**< Number of CPU TX entries */
} rdpa_cpu_tx_method;

/** Extra data that can be passed along with the packet to be transmitted */
typedef struct
{
    rdpa_cpu_tx_method method;  /**< Packet transmit method */
    rdpa_if port;               /**< Destination port for method=port, source port for method=bridge */
    rdpa_cpu_port cpu_port;     /**< CPU object index \XRDP_LIMITED */
    uint8_t ssid;               /**< SSID, in use when port is wlan */
    uint8_t no_lock;            /**< BOOL flag, TRUE=never lock QM access, only for send dying gasp. Default should be FALSE!! */

    union {
        /* queue_id in the following substructures must overlap */
        struct {
            uint32_t queue_id;          /**< Egress queue id */
        } lan;

        struct {
            uint32_t queue_id;          /**< Egress queue id. method=port only */
            rdpa_flow flow;             /**< Destination flow for method=port, Source flow for method=bridge,port=wan */
        } wan;

        uint32_t oam_data;              /**< Extra data entry-specific */
    } x;
    uint32_t data;   /**<data pointer or FPM/BPM hw token */
    uint32_t data_offset;    /**<data offset inside pointer */
    uint32_t data_size; /**<size of actuall data */
    int is_spdsvc_setup_packet; /**<when set, indicates that a Speed Service Setup packet is being transmitted */
    rdpa_discard_prty drop_precedence; /**< Indicates drop precedence */
    uint32_t ptp_info;
} rdpa_cpu_tx_info_t;

/** @} end of cpu_tx Doxygen group */

#endif /* RDPA_CPU_BASIC_H_ */
