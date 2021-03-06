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


#ifndef _RDPA_PORT_H_
#define _RDPA_PORT_H_

/** \defgroup port Port Management
 * \ingroup rdpa
 * Logical port properties.\n
 * - Traffic management properties.
 *      - Ports can form an hierarchy for port aggregation and LAG.
 *        For example, SSID2 can be owned by PCI1
 *      - Port can own a scheduler.
 * - Bridge properies
 *      - SA/DA lookup enable and miss action
 *      - Default VID
 *      - Port can be linked to multiple bridge objects
 *      - Port can be linked to multiple VLAN objects
 * @{
 */

/** External physical port ID - identifies the external switch physical port */
typedef enum
{
    rdpa_physical_port0, /**< Physical port 0 */
    rdpa_physical_port1, /**< Physical port 1 */
    rdpa_physical_port2, /**< Physical port 2 */
    rdpa_physical_port3, /**< Physical port 3 */
    rdpa_physical_port4, /**< Physical port 4 */
    rdpa_physical_port5, /**< Physical port 5 */
    rdpa_physical_port6, /**< Physical port 6 */
    rdpa_physical_port7, /**< Physical port 7 */
    rdpa_physical_none
} rdpa_physical_port;

/** Data path port configuration.
 * Underlying type for port_dp aggregate
 */
typedef struct
{
    rdpa_emac emac; /**< EMAC */
    bdmf_boolean enable; /**< Set=false to remove port from bridge */
    bdmf_boolean sal_enable; /**< Do SA lookup */
    bdmf_boolean dal_enable; /**< Do DA lookup */
    rdpa_forward_action sal_miss_action; /**< SA miss action */
    rdpa_forward_action dal_miss_action; /**< DA miss action */
    rdpa_physical_port physical_port; /**< Physical port for external switch */
    bdmf_boolean ls_fc_enable; /**< Local switching via flow cache enable */
} rdpa_port_dp_cfg_t;


/** sa_limit
 * Underlying structure for port_sa_limit aggregate
 */
typedef struct
{
    uint16_t max_sa;                        /**< Max number of SAs that can be learnt on the port */
    uint16_t num_sa;                        /**< RO: Number of SAs learnt on the port. Ignored when setting configuration */
} rdpa_port_sa_limit_t;


/** Port TM configuration.
 * Underlying type for port_tm aggregate
 */
typedef struct
{
    bdmf_object_handle sched;               /**< Traffic scheduler */
    rdpa_discard_prty discard_prty;         /**< Port Ingress QOS priotity */
} rdpa_port_tm_cfg_t;


/** Port QoS mapping configuration.
 * Underlying type for port_qos aggregate
 */
typedef struct
{
    bdmf_object_handle dscp_to_pbit;        /**< DSCP --> PBIT mapping table ID */
    bdmf_object_handle pbit_to_pbit;        /**< PBIT --> PBIT mapping table ID */
    bdmf_object_handle pbit_to_prty;        /**< PBIT --> PRTY mapping table ID */
} rdpa_port_qos_cfg_t;

/** Port statistics */
typedef struct {
   uint32_t rx_valid_pkt;               /**< Valid Received packets */
   uint32_t rx_crc_error_pkt;           /**< Received packets with CRC error */
   uint32_t rx_discard_1;               /**< RX discard 1 */
   uint32_t rx_discard_2;               /**< RX discard 2  */    
   uint32_t bbh_drop_1;                 /**< BBH drop 1  */    
   uint32_t bbh_drop_2;                 /**< BBH drop 2 */    
   uint32_t bbh_drop_3;                 /**< BBH drop 3 */    
   uint32_t rx_discard_max_length;      /**< Packets discarded due to size bigger than MTU  */    
   uint32_t rx_discard_min_length;      /**< Packets discarded due to size smaller than 64  */    
   uint32_t tx_valid_pkt;               /**< Valid transmitted packets */    
   uint32_t tx_discard;                 /**< TX discarded packets (TX FIFO full) */
   uint32_t discard_pkt;                /**< Dropped filtered Packets */    
   uint32_t rx_valid_bytes;             /**< FTTdp only: Received valid bytes */    
   uint32_t rx_multicast_pkt;           /**< FTTdp only: Received multicast Packets */    
   uint32_t rx_broadcast_pkt;           /**< FTTdp only: Received broadcast Packets */    
   uint32_t tx_valid_bytes;             /**< FTTdp only: Sent valid bytes */    
   uint32_t tx_multicast_pkt;           /**< FTTdp only: Sent multicast Packets */    
   uint32_t tx_broadcast_pkt;           /**< FTTdp only: Sent broadcast Packets */    
} rdpa_port_stat_t;

/** Flow control configuration parameters */
typedef struct {
    uint32_t rate; /**< Ingress limit rate [bits/sec] */
    uint32_t mbs; /**< Maximal burst size in bytes */
    uint32_t threshold; /**< Flow control threshold */
    bdmf_mac_t src_address; /**< Flow control mac source address */
} rdpa_port_flow_ctrl_t;

/** Port mirroring configuration parameters */
typedef struct {
    bdmf_object_handle rx_dst_port; /**< Destination port for rx traffic */
    bdmf_object_handle tx_dst_port; /**< Destination port for tx traffic */
} rdpa_port_mirror_cfg_t;

/** VLAN Isolation configuration */
typedef struct {
    bdmf_boolean us; /**< Enables VLAN isolation at ingress */
    bdmf_boolean ds; /**< Enables VLAN isolation at egress */
} rdpa_port_vlan_isolation_t;

/** loopback type - identifies the point of loopback in the system */
typedef enum
{
    rdpa_loopback_type_none,
    rdpa_loopback_type_fw,  /**< loopback in firmware */
    rdpa_loopback_type_mac, /**< loopback in mac */
    rdpa_loopback_type_phy,  /**< loopback in phy */
} rdpa_loopback_type;

/** loopback operation - identifies the loopback operation in respect of onu */
typedef enum
{
    rdpa_loopback_op_none,   /**< no loopback operation */
    rdpa_loopback_op_local,  /**< loopback is local */
    rdpa_loopback_op_remote, /**< loopback in remote */
} rdpa_loopback_op;

/** port loopback configuration */
typedef struct {
    rdpa_loopback_type  type; /**< loopback type */
    rdpa_loopback_op    op;  /**< loopback direction bitmask */
    int32_t             wan_flow; /**< gem id or llid  on which wan-wan loopback will return */
    int32_t             queue; /**< queue id on which wan-wan loopback will return */
    uint32_t            ic_idx; /** < IC context for wan-wan loopback */
} rdpa_port_loopback_t;

#define FFS(n, port) do { \
    port = ffs(n) - 1; \
    n &= ~(1L << port); \
} while (0)

/** Get index (rdpa_if) of next port from ports.
 * \param [in, out] ports Ports iterator, represented as a combination of rdpa_if_id mask. When next port is found, it's
 *     cleared from the mask. Hence, the function can be called in a loop until mask is empty.
 * \return  rdpa_if if next port found, rdpa_if_none otherwise.
 */
static inline rdpa_if rdpa_port_get_next(rdpa_ports *ports)
{
    rdpa_if port;
    unsigned long low, high;

    if (!*ports)
        return rdpa_if_none;

    high = *ports >> 32;
    low = *ports & 0xffffffff;
    if (low)
        FFS(low, port);
    else
    {
        FFS(high, port);
        port += 32;
    }
    *ports = ((unsigned long long)high << 32) | low;
    return port;
}

#ifdef BDMF_DRIVER

/* Increment/decrement num_sa on port.
 * The operation can fail if port doesn't exist
 * or num_sa exceeds max_sa.
 *
 * The function must be called under lock!
 *
 * \param[in]   port    port
 * \param[in]   is_inc  1=increment
 * \return 0 if OK or error code < 0
 */
int rdpa_port_inc_dec_num_sa(rdpa_if port, bdmf_boolean is_inc);

int rdpa_port_transparent(rdpa_if index, bdmf_boolean *enable);
#endif

/* port object private data */
typedef struct
{
    rdpa_if index; /**< port index */
    rdpa_wan_type wan_type; /**< WAN type */
    rdpa_port_dp_cfg_t cfg; /**< Logical configuration */
    rdpa_port_tm_cfg_t tm_cfg; /**< TM configuration */
    rdpa_port_sa_limit_t sa_limit; /**< SA limit configuration */
    rdpa_port_flow_ctrl_t flow_ctrl; /**< Ingress flow control */
    bdmf_index def_flow_index;  /**index of def flow context configuration */
    rdpa_port_mirror_cfg_t mirror_cfg; /**< Port mirroring configuration */
    rdpa_stat_tx_rx_t host_stat;  /**< Host statistics shadow */
    rdpa_port_vlan_isolation_t vlan_isolation;  /**<Port VLAN isolation control */
    bdmf_boolean transparent;  /**<Port  transparent control */
    int channel;        /* port channel (RDD) */
    rdpa_port_loopback_t  loopback_cfg; /* port loopbacks configuration */
    uint32_t mtu_size;  /*port mtu size*/
} port_drv_priv_t;

extern bdmf_fastlock port_fastlock;
extern struct bdmf_object *port_objects[];
static inline int _rdpa_port_channel(rdpa_if index)
{
    struct bdmf_object *mo;
    port_drv_priv_t *port;
    int channel;

    if ((unsigned)index >= rdpa_if__number_of)
        return -1;
    bdmf_fastlock_lock(&port_fastlock);
    mo = port_objects[index];
    if (!mo)
    {
        bdmf_fastlock_unlock(&port_fastlock);
        return -1;
    }
    port = (port_drv_priv_t *)bdmf_obj_data(mo);
    channel = port->channel;
    bdmf_fastlock_unlock(&port_fastlock);
    return channel;
}

rdpa_if rdpa_physical_port_to_rdpa_if(rdpa_physical_port port);

rdpa_wan_type rdpa_wan_type_get(void);

/** @} end of port Doxygen group */

#endif /* _RDPA_PORT_H_ */
