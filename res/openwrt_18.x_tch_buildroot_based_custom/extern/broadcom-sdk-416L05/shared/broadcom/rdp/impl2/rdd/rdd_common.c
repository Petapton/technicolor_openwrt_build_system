/*
   Copyright (c) 2013 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2013:DUAL/GPL:standard
    
    Unless you and Broadcom execute a separate written software license
    agreement governing use of this software, this software is licensed
    to you under the terms of the GNU General Public License version 2
    (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
    with the following added to such license:
    
       As a special exception, the copyright holders of this software give
       you permission to link this software with independent modules, and
       to copy and distribute the resulting executable under terms of your
       choice, provided that you also meet, for each linked independent
       module, the terms and conditions of the license of that module.
       An independent module is a module which is not derived from this
       software.  The special exception does not apply to any modifications
       of the software.
    
    Not withstanding the above, under no circumstances may you combine
    this software in any way with any other Broadcom software provided
    under a license other than the GPL, without Broadcom's express prior
    written consent.
    
:>
*/

#include "rdd.h"


/******************************************************************************/
/*                                                                            */
/*                            Global Variables                                */
/*                                                                            */
/******************************************************************************/

#if defined(FIRMWARE_INIT)
extern uint32_t  DsConnectionTableBase;
extern uint32_t  UsConnectionTableBase;
extern uint32_t  ContextTableBase;
extern uint32_t  IPTVTableBase;
extern uint32_t  IPTVContextTableBase;
extern uint32_t  IPTVSsmContextTableBase;
extern uint32_t  FirewallRulesMapTable;
extern uint32_t  FirewallRulesTable;
extern uint32_t  GenericClassifierTable;
#if !defined(DSL_63138) && !defined(DSL_63148)
extern uint32_t  DdrAddressForSyncDmaBase;
#endif
extern uint32_t  CpuRxRingBase;
#endif

#if defined(DSL_63138) || defined(DSL_63148)
int                                g_dbg_lvl;
RDD_FC_MCAST_CONNECTION2_TABLE_DTS *g_fc_mcast_connection2_table_ptr;
RDD_CONNECTION_TABLE_DTS    *g_ds_connection_table_ptr;
#endif

uint32_t  g_runner_ddr_base_addr;
uint32_t  g_runner_extra_ddr_base_addr;
uint32_t  g_mac_table_size;
uint32_t  g_mac_table_search_depth;
uint32_t  g_iptv_table_size;
uint32_t  g_ddr_headroom_size;
uint32_t  g_runner_tables_ptr;
uint8_t   g_broadcom_switch_mode = 0;
#ifdef G9991
uint8_t   g_G9991_mode = 1;
#else
uint8_t   g_G9991_mode = 0;
#endif
uint32_t  g_bridge_flow_cache_mode;
uint32_t  g_iptv_table_search_depth;
uint32_t  g_cpu_tx_queue_write_ptr[ 4 ];
uint32_t  g_cpu_tx_queue_free_counter[ 4 ] = { 0, 0, 0, 0 };
uint32_t  g_cpu_tx_queue_abs_data_ptr_write_ptr[ 4 ];
uint32_t  g_rate_controllers_pool_idx;
uint32_t  g_downstream_rate_shaper[ RDD_DS_RATE_SHAPERS_TABLE_SIZE ];
uint32_t  g_ih_lookup_mode_occupied[ 2 ];
uint32_t  g_free_context_entries_number;
uint32_t  g_free_context_entries_head;
uint32_t  g_free_context_entries_tail;
uint32_t  g_iptv_context_tables_free_list_head;
uint32_t  g_iptv_context_tables_free_list_tail;
uint32_t  *g_free_connection_context_entries;
uint32_t  g_iptv_source_ip_counter[ LILAC_RDD_IPTV_NUMBER_OF_SERVICE_PROVIDERS ];
uint32_t  g_iptv_source_ip_cam_counter[ LILAC_RDD_IPTV_NUMBER_OF_SERVICE_PROVIDERS ];
uint32_t  g_src_mac_anti_spoofing_last_rule_index[ 6 ];
uint32_t  g_acl_layer2_vlan_index_counter[ 6 ][ 32 ];
uint32_t  g_acl_layer2_last_vlan_index[ 6 ];
uint32_t  g_acl_layer2_last_rule_index[ 6 ];
uint32_t  g_acl_layer3_last_rule_index[ 6 ];
uint32_t  g_vlan_mapping_command_to_action[ rdd_max_vlan_command ][ rdd_max_pbits_command ];
uint32_t  g_epon_mode;
uint32_t  g_chip_revision;
#if !defined(FIRMWARE_INIT) && !defined(RDD_BASIC)
bdmf_sysb  *g_pci_tx_skb_reference_pointers_array[ LILAC_RDD_PCI_TX_NUMBER_OF_FIFOS ][ LILAC_RDD_PCI_TX_FIFO_SIZE ];
#endif
RDD_INGRESS_CLASSIFICATION_RULE_CFG_TABLE_DTE  g_ingress_classification_rule_cfg_table[ 2 ];
BL_LILAC_RDD_WAN_PHYSICAL_PORT_DTE             g_wan_physical_port;
RDD_WAN_TX_POINTERS_TABLE_DTS                  *wan_tx_pointers_table_ptr;
BL_LILAC_RDD_VLAN_ACTIONS_MATRIX_DTS           *g_vlan_actions_matrix_ptr;
RDD_64_BIT_TABLE_CFG                           g_hash_table_cfg[ BL_LILAC_RDD_MAX_HASH_TABLE ];
RDD_DDR_TABLE_CFG                              g_ddr_hash_table_cfg[ BL_LILAC_RDD_MAX_HASH_TABLE ];
BL_LILAC_RDD_CONTEXT_TABLES_FREE_LIST_DTS      *g_iptv_context_tables_free_list;
BL_LILAC_RDD_ACL_LAYER3_FILTER_MODE_DTE        g_acl_layer3_filter_mode[ 6 ];
BL_LILAC_RDD_ETHER_TYPE_FILTER_MATRIX_DTS      *g_ether_type_filter_mode;
BL_LILAC_RDD_BRIDGE_PORT_DTE                   g_broadcom_switch_physical_port = 0;
uint32_t                                       g_bbh_peripheral_eth_rx[] =
{
    BBH_PERIPHERAL_ETH0_RX,
	BBH_PERIPHERAL_ETH1_RX,
	BBH_PERIPHERAL_ETH2_RX,
	BBH_PERIPHERAL_ETH3_RX,
	BBH_PERIPHERAL_ETH4_RX
};
#if !defined(DSL_63138) && !defined(DSL_63148)
uint32_t  g_cpu_tx_skb_free_indexes_head_ptr = 0;
uint32_t  g_cpu_tx_skb_free_indexes_counter = 0;
#endif
uint32_t  g_cpu_tx_skb_free_indexes_release_ptr = 0;
uint32_t  g_cpu_tx_released_skb_counter = 0;
uint32_t  g_cpu_tx_no_free_skb_counter = 0;
uint32_t  g_cpu_tx_sent_abs_packets_counter = 0;
#if !defined(FIRMWARE_INIT)
#if defined(DSL_63138) || defined(DSL_63148)
cpu_tx_skb_free_indexes_cache_t g_cpu_tx_skb_free_indexes_cache;
uint32_t  g_cpu_tx_pending_free_indexes_counter = 0;
#endif
#endif
uint32_t  g_cpu_tx_abs_packet_limit = 0;
uint16_t  *g_free_skb_indexes_fifo_table = NULL;
uint32_t  *g_cpu_tx_skb_pointers_reference_array = NULL;
uint32_t  *g_cpu_tx_data_pointers_reference_array = NULL;
uint16_t  *g_free_skb_indexes_fifo_table_physical_address = NULL;
uint16_t  *g_free_skb_indexes_fifo_table_physical_address_last_idx = NULL;

#if defined(CONFIG_BCM_PKTRUNNER_GSO)
uint32_t  g_cpu_tx_no_free_gso_desc_counter = 0;
uint32_t  g_cpu_tx_sent_abs_gso_packets_counter = 0;
uint32_t  g_cpu_tx_sent_abs_gso_bytes_counter = 0;
#endif

#if defined(DSL_63138) || defined(DSL_63148)
typedef struct
{
    bdmf_ipv6_t ipv6_address;
    uint16_t    ref_count;
} ipv6_host_table_t;

/*missing-braces warning is enabled, so can't use {0} initializer. Relying on BSS zero init rule instead.*/
static ipv6_host_table_t g_ipv6_host_table[RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE];
static uint16_t g_ipv4_host_ref_count_table[RDD_IPV4_HOST_ADDRESS_TABLE_SIZE];

#endif

BL_LILAC_RDD_VERSION_DTS  gs_rdd_version =
{
    LILAC_RDD_RELEASE,
    LILAC_RDD_VERSION,
    LILAC_RDD_PATCH,
    LILAC_RDD_REVISION
};

BL_LILAC_RDD_LOCK_CRITICAL_SECTION_FP_DTE        f_rdd_lock;
BL_LILAC_RDD_UNLOCK_CRITICAL_SECTION_FP_DTE      f_rdd_unlock;
BL_LILAC_RDD_LOCK_CRITICAL_SECTION_FP_IRQ_DTE    f_rdd_lock_irq;
BL_LILAC_RDD_UNLOCK_CRITICAL_SECTION_FP_IRQ_DTE  f_rdd_unlock_irq;

DEFINE_BDMF_FASTLOCK( int_lock );
DEFINE_BDMF_FASTLOCK( int_lock_irq );

#if defined(FIRMWARE_INIT)
int  g_lock_state = LILAC_RDD_FALSE;
void fw_init_lock ( bdmf_fastlock * );
void fw_init_unlock ( bdmf_fastlock * );
void fw_init_lock_irq ( bdmf_fastlock  *xo_int_lock, unsigned long *flags );
void fw_init_unlock_irq ( bdmf_fastlock  *xi_int_lock, unsigned long flags );
#endif

BL_LILAC_RDD_ERROR_DTE rdd_us_padding_config ( BL_LILAC_RDD_UPSTREAM_PADDING_MODE_DTE  xi_control,
                                               BL_LILAC_RDD_UPSTREAM_PADDING_MODE_DTE  xi_cpu_control,
		                                       uint16_t                                xi_size )
{
    RDD_BRIDGE_CONFIGURATION_REGISTER_DTS  *bridge_cfg_register;
    uint16_t                               cpu_size;

    bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

    if ( xi_control == BL_LILAC_RDD_UPSTREAM_PADDING_DISABLE )
    {
        xi_size = 0;
        cpu_size = 0;
    }
    else
    {
        cpu_size = xi_size;

        if ( xi_cpu_control == BL_LILAC_RDD_UPSTREAM_PADDING_DISABLE )
        {
            cpu_size = 0;
        }
    }

    RDD_BRIDGE_CONFIGURATION_REGISTER_US_PADDING_MAX_SIZE_WRITE ( xi_size, bridge_cfg_register );
    RDD_BRIDGE_CONFIGURATION_REGISTER_US_PADDING_CPU_MAX_SIZE_WRITE ( cpu_size, bridge_cfg_register );

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_mtu_config ( uint16_t  xi_mtu_size )
{
    RDD_BRIDGE_CONFIGURATION_REGISTER_DTS  *bridge_cfg_register;

    /* configuration will be made only in US direction for the time being*/
    bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

    if ( xi_mtu_size <= RDD_IPV6_HEADER_SIZE )
    {
        return ( BL_LILAC_RDD_ERROR_MTU_INVALID_LENGTH );
    }

    RDD_BRIDGE_CONFIGURATION_REGISTER_MTU_MINUS_40_WRITE ( ( xi_mtu_size - RDD_IPV6_HEADER_SIZE ), bridge_cfg_register );

#ifdef G9991
    /*maximum number of non EOF fragments is MTU/104, unless there's no reminder and it is MTU/104 - 1*/
    RDD_BRIDGE_CONFIGURATION_REGISTER_US_G9991_MTU_MAX_FRAGMENTS_WRITE ( ( xi_mtu_size % US_G9991_FRAGMENT_PAYLOAD_LENGTH ) ? ( xi_mtu_size / US_G9991_FRAGMENT_PAYLOAD_LENGTH ) : ( xi_mtu_size / US_G9991_FRAGMENT_PAYLOAD_LENGTH ) - 1 , bridge_cfg_register );

    /*in case number of non EOF fragments is in maximum, EOF max size is reminder from MTU/104, unless there's no reminder and it will be exactly 104*/
    RDD_BRIDGE_CONFIGURATION_REGISTER_US_G9991_MTU_MAX_EOF_LENGTH_WRITE ( ( xi_mtu_size % US_G9991_FRAGMENT_PAYLOAD_LENGTH ) ? ( xi_mtu_size % US_G9991_FRAGMENT_PAYLOAD_LENGTH ) : US_G9991_FRAGMENT_PAYLOAD_LENGTH , bridge_cfg_register );
#endif

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_ddr_headroom_size_config ( uint16_t  xi_ddr_headroom_size )
{
    unsigned long           flags;
    BL_LILAC_RDD_ERROR_DTE  rdd_error = BL_LILAC_RDD_OK;

    /* updating global var */
    g_ddr_headroom_size = xi_ddr_headroom_size;

    /* updating DDR buffers base address (taken from f_rdd_bpm_initialize() ) */
    f_rdd_ddr_optimized_base_config ( g_runner_ddr_base_addr, xi_ddr_headroom_size );

    /* updating actual ddr headroom size to runner memory (taken from f_rdd_ddr_initialize) */
    f_rdd_ddr_headroom_size_private_config ( xi_ddr_headroom_size );
    
    /*sending message to runner to update io memory for dma access*/
    f_rdd_lock_irq ( &int_lock_irq, &flags );

#if !defined(FIRMWARE_INIT)
    rdd_error = f_rdd_cpu_tx_send_message ( LILAC_RDD_CPU_TX_MESSAGE_DDR_HEADROOM_SIZE_SET, FAST_RUNNER_A, RUNNER_PRIVATE_0_OFFSET, 0, 0, 0, BL_LILAC_RDD_WAIT );

    if ( rdd_error == BL_LILAC_RDD_OK )
        rdd_error = f_rdd_cpu_tx_send_message ( LILAC_RDD_CPU_TX_MESSAGE_DDR_HEADROOM_SIZE_SET, FAST_RUNNER_B, RUNNER_PRIVATE_1_OFFSET, 0, 0, 0, BL_LILAC_RDD_WAIT );

    if ( rdd_error == BL_LILAC_RDD_OK )
        rdd_error = f_rdd_cpu_tx_send_message ( LILAC_RDD_CPU_TX_MESSAGE_DDR_HEADROOM_SIZE_SET, PICO_RUNNER_A, RUNNER_PRIVATE_0_OFFSET, 0, 0, 0, BL_LILAC_RDD_WAIT );

    if ( rdd_error == BL_LILAC_RDD_OK )
        rdd_error = f_rdd_cpu_tx_send_message ( LILAC_RDD_CPU_TX_MESSAGE_DDR_HEADROOM_SIZE_SET, PICO_RUNNER_B, RUNNER_PRIVATE_1_OFFSET, 0, 0, 0, BL_LILAC_RDD_WAIT );
#endif
    f_rdd_unlock_irq ( &int_lock_irq, flags );

    return ( rdd_error );
}


BL_LILAC_RDD_ERROR_DTE f_rdd_ddr_optimized_base_config ( uint32_t  xi_runner_ddr_pool_ptr,
                                                         uint32_t  xi_ddr_headroom_size )
{
    uint32_t  *bpm_ddr_optimized_base_ptr;

    bpm_ddr_optimized_base_ptr = ( uint32_t * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_BPM_DDR_OPTIMIZED_BUFFERS_BASE_ADDRESS );

#if defined(DSL_63138) || defined(DSL_63148)
    MWRITE_32( bpm_ddr_optimized_base_ptr, VIRT_TO_PHYS( xi_runner_ddr_pool_ptr + xi_ddr_headroom_size + LILAC_RDD_PACKET_DDR_OFFSET ) );
#else
    MWRITE_32( bpm_ddr_optimized_base_ptr, ( xi_runner_ddr_pool_ptr + xi_ddr_headroom_size + LILAC_RDD_PACKET_DDR_OFFSET ) & 0x1FFFFFFF );
#endif

    bpm_ddr_optimized_base_ptr = ( uint32_t * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BPM_DDR_OPTIMIZED_BUFFERS_BASE_ADDRESS );

#if defined(DSL_63138) || defined(DSL_63148)
    MWRITE_32( bpm_ddr_optimized_base_ptr, VIRT_TO_PHYS( xi_runner_ddr_pool_ptr + xi_ddr_headroom_size + LILAC_RDD_PACKET_DDR_OFFSET ) );
#else
    MWRITE_32( bpm_ddr_optimized_base_ptr, ( xi_runner_ddr_pool_ptr + xi_ddr_headroom_size + LILAC_RDD_PACKET_DDR_OFFSET ) & 0x1FFFFFFF );
#endif

    return ( BL_LILAC_RDD_OK );
}

BL_LILAC_RDD_ERROR_DTE f_rdd_ddr_headroom_size_private_config ( uint32_t  xi_ddr_headroom_size )
{
    uint16_t  *headroom_size_ptr;

    headroom_size_ptr = ( uint16_t * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_BPM_DDR_BUFFER_HEADROOM_SIZE_ADDRESS );
    MWRITE_16( headroom_size_ptr, xi_ddr_headroom_size );

    headroom_size_ptr = ( uint16_t * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION_ADDRESS );
    MWRITE_16( headroom_size_ptr, ( xi_ddr_headroom_size >> 1 ) );

    headroom_size_ptr = ( uint16_t * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BPM_DDR_BUFFER_HEADROOM_SIZE_ADDRESS );
    MWRITE_16( headroom_size_ptr, xi_ddr_headroom_size );

    headroom_size_ptr = ( uint16_t * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BPM_DDR_BUFFER_HEADROOM_SIZE_2_BYTE_RESOLUTION_ADDRESS );
    MWRITE_16( headroom_size_ptr, ( xi_ddr_headroom_size >> 1 ) );

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_critical_section_config ( BL_LILAC_RDD_LOCK_CRITICAL_SECTION_FP_DTE        xi_lock_function,
                                                     BL_LILAC_RDD_UNLOCK_CRITICAL_SECTION_FP_DTE      xi_unlock_function,
                                                     BL_LILAC_RDD_LOCK_CRITICAL_SECTION_FP_IRQ_DTE    xi_lock_irq_function,
                                                     BL_LILAC_RDD_UNLOCK_CRITICAL_SECTION_FP_IRQ_DTE  xi_unlock_irq_function )
{
    f_rdd_lock = xi_lock_function;
    f_rdd_unlock = xi_unlock_function;
    f_rdd_lock_irq = xi_lock_irq_function;
    f_rdd_unlock_irq = xi_unlock_irq_function;

    return ( BL_LILAC_RDD_OK );
}


#if !defined(DSL_63138) && !defined(DSL_63148)
BL_LILAC_RDD_ERROR_DTE rdd_1588_mode_config ( BL_LILAC_RDD_1588_MODE_DTE  xi_1588_mode )
{
    RDD_BRIDGE_CONFIGURATION_REGISTER_DTS  *bridge_cfg_register;

    bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

    RDD_BRIDGE_CONFIGURATION_REGISTER_IP_SYNC_1588_MODE_WRITE ( xi_1588_mode, bridge_cfg_register );

    bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

    RDD_BRIDGE_CONFIGURATION_REGISTER_IP_SYNC_1588_MODE_WRITE ( xi_1588_mode, bridge_cfg_register );

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_smart_card_global_params_config ( uint32_t  xi_waiting_time,
                                                             uint8_t   xi_guard_time,
                                                             uint8_t   xi_etu,
                                                             uint8_t   xi_max_retransmit )
{
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_DTS  *smart_card_cfg_ptr;
    uint8_t                              sampling_time;

    sampling_time = ( uint8_t )( ( ( int )xi_etu ) / 5 );

    smart_card_cfg_ptr = ( RDD_SMART_CARD_DESCRIPTOR_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + SMART_CARD_DESCRIPTOR_TABLE_ADDRESS );

    RDD_SMART_CARD_DESCRIPTOR_ENTRY_WAITING_TIME_WRITE ( xi_waiting_time, smart_card_cfg_ptr );
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_GUARD_TIME_WRITE ( xi_guard_time, smart_card_cfg_ptr );
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_ETU_WRITE ( xi_etu, smart_card_cfg_ptr );
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_SAMPLING_TIME_WRITE ( sampling_time, smart_card_cfg_ptr );
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_MAX_RETRANSMIT_WRITE ( xi_max_retransmit, smart_card_cfg_ptr );

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_smart_card_command_params_config ( uint8_t   xi_task_type,
                                                              uint16_t  xi_send_length,
                                                              uint16_t  xi_receive_length,
                                                              uint8_t   *xi_header_array,
                                                              uint8_t   *xi_data_array )
{
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_DTS  *smart_card_cfg_ptr;
    int32_t                              i;

    smart_card_cfg_ptr = ( RDD_SMART_CARD_DESCRIPTOR_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + SMART_CARD_DESCRIPTOR_TABLE_ADDRESS );

    RDD_SMART_CARD_DESCRIPTOR_ENTRY_TASK_TYPE_WRITE ( xi_task_type, smart_card_cfg_ptr );

    if ( xi_task_type == BL_LILAC_RDD_SMART_CARD_TASK_TYPE_NORMAL )
    {
        if ( xi_send_length > 255 )
        {
            return ( BL_LILAC_RDD_ERROR_SMC_INVALID_SEND_LENGTH );
        }

        if ( xi_receive_length > 255 )
        {
            return ( BL_LILAC_RDD_ERROR_SMC_INVALID_RECEIVE_LENGTH );
        }

        RDD_SMART_CARD_DESCRIPTOR_ENTRY_SEND_LENGTH_WRITE ( xi_send_length, smart_card_cfg_ptr );
        RDD_SMART_CARD_DESCRIPTOR_ENTRY_RECEIVE_LENGTH_WRITE ( xi_receive_length, smart_card_cfg_ptr );
    }
    else if ( xi_task_type == BL_LILAC_RDD_SMART_CARD_TASK_TYPE_PPS )
    {
        if ( xi_send_length < 3 )
        {
            return ( BL_LILAC_RDD_ERROR_SMC_PPS_SEND_LEN_LESS_THEN_3 );
        }

        RDD_SMART_CARD_DESCRIPTOR_ENTRY_SEND_LENGTH_WRITE ( xi_send_length, smart_card_cfg_ptr );
        RDD_SMART_CARD_DESCRIPTOR_ENTRY_RECEIVE_LENGTH_WRITE ( xi_send_length, smart_card_cfg_ptr );
    }
    else if (xi_task_type == BL_LILAC_RDD_SMART_CARD_TASK_TYPE_ATR )
    {
        RDD_SMART_CARD_DESCRIPTOR_ENTRY_SEND_LENGTH_WRITE ( 0, smart_card_cfg_ptr );
        RDD_SMART_CARD_DESCRIPTOR_ENTRY_RECEIVE_LENGTH_WRITE ( 2, smart_card_cfg_ptr );

        xi_send_length = 0;
    }
    else
    {   /*tx/rx task */
        for ( i = 0; i < 5; i++ )
        {
            RDD_SMART_CARD_DESCRIPTOR_ENTRY_HEADER_BYTES_WRITE ( xi_header_array[ i ], ( uint8_t * )smart_card_cfg_ptr + i );
        }

        if ( ( xi_task_type == BL_LILAC_RDD_SMART_CARD_TASK_TYPE_RX ) && ( xi_send_length != 0 ) )
        {
            return ( BL_LILAC_RDD_ERROR_SMC_INVALID_SEND_LENGTH );
        }
        else if ( xi_task_type == BL_LILAC_RDD_SMART_CARD_TASK_TYPE_TX )
        {
            xi_send_length = xi_header_array[ 4 ];
        }
    }

    /*  initialize status */
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_STATUS_BYTE_WRITE ( 0 ,smart_card_cfg_ptr );

    for ( i = 0; i < xi_send_length; i++ )
    {
        RDD_SMART_CARD_DESCRIPTOR_ENTRY_DATA_BYTES_WRITE ( xi_data_array[ i ], smart_card_cfg_ptr, i );
    }

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_smart_card_command_params_read ( uint16_t  *xo_send_length,
                                                            uint16_t  *xo_receive_length,
                                                            uint8_t   *xo_data_array,
                                                            uint8_t   *xo_status_byte,
                                                            uint32_t  *xo_send_error_counter,
                                                            uint32_t  *xo_receive_error_counter )
{
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_DTS      *smart_card_cfg_ptr;
    RDD_SMART_CARD_ERROR_COUNTERS_ENTRY_DTS  *smart_card_error_counters_ptr;
    int32_t                                  i;

    smart_card_cfg_ptr = ( RDD_SMART_CARD_DESCRIPTOR_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + SMART_CARD_DESCRIPTOR_TABLE_ADDRESS );
	smart_card_error_counters_ptr = ( RDD_SMART_CARD_ERROR_COUNTERS_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + SMART_CARD_ERROR_COUNTERS_TABLE_ADDRESS);

    RDD_SMART_CARD_DESCRIPTOR_ENTRY_SEND_LENGTH_READ ( *xo_send_length, smart_card_cfg_ptr );
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_RECEIVE_LENGTH_READ ( *xo_receive_length, smart_card_cfg_ptr );
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_STATUS_BYTE_READ ( *xo_status_byte, smart_card_cfg_ptr );

    RDD_SMART_CARD_ERROR_COUNTERS_ENTRY_TRANSMIT_ERRORS_READ ( *xo_send_error_counter, smart_card_error_counters_ptr );
    RDD_SMART_CARD_ERROR_COUNTERS_ENTRY_RECEIVE_ERRORS_READ ( *xo_receive_error_counter, smart_card_error_counters_ptr );

    for ( i = 0; i < *xo_receive_length; i++ )
    {
        RDD_SMART_CARD_DESCRIPTOR_ENTRY_DATA_BYTES_READ ( xo_data_array[ i ], smart_card_cfg_ptr, i );
    }

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE  rdd_smart_card_status_get ( uint8_t  *xo_smart_card_status )
{
    RDD_SMART_CARD_DESCRIPTOR_ENTRY_DTS  *smart_card_cfg_ptr;

    smart_card_cfg_ptr = ( RDD_SMART_CARD_DESCRIPTOR_ENTRY_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + SMART_CARD_DESCRIPTOR_TABLE_ADDRESS );

    RDD_SMART_CARD_DESCRIPTOR_ENTRY_STATUS_BYTE_READ ( *xo_smart_card_status, smart_card_cfg_ptr );

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_smart_card_task_start ( void )
{
    RUNNER_REGS_CFG_CPU_WAKEUP  runner_cpu_wakeup_register;

    /* Send Asyncronic wakeup */
    runner_cpu_wakeup_register.req_trgt = SMART_CARD_THREAD_NUMBER / 32;
    runner_cpu_wakeup_register.thread_num = SMART_CARD_THREAD_NUMBER % 32;
    runner_cpu_wakeup_register.urgent_req = LILAC_RDD_FALSE;

    RUNNER_REGS_1_CFG_CPU_WAKEUP_WRITE ( runner_cpu_wakeup_register );

    return ( BL_LILAC_RDD_OK );
}
#endif /* !DSL */


BL_LILAC_RDD_ERROR_DTE rdd_interrupt_vector_get ( uint32_t  xi_interrupt_number,
                                                  uint8_t   *xo_sub_interrpt_vector )
{
#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_CFG_INT_CTRL  runner_interrupt_controller_0_register;
    RUNNER_REGS_CFG_INT_CTRL  runner_interrupt_controller_1_register;
    RUNNER_REGS_CFG_INT_MASK  runner_interrupt_mask_register;

    RUNNER_REGS_0_CFG_INT_CTRL_READ ( runner_interrupt_controller_0_register );
    RUNNER_REGS_1_CFG_INT_CTRL_READ ( runner_interrupt_controller_1_register );

    RUNNER_REGS_0_CFG_INT_MASK_READ ( runner_interrupt_mask_register );

    /* clear the interrupt by writing "1" to the corresponding bit in the Runner's interrupt register */
    switch ( xi_interrupt_number )
    {
    case 0:
        *xo_sub_interrpt_vector = ( runner_interrupt_controller_0_register.int0_sts | runner_interrupt_controller_1_register.int0_sts ) & runner_interrupt_mask_register.int0_mask;
        break;
    case 1:
        *xo_sub_interrpt_vector = ( runner_interrupt_controller_0_register.int1_sts | runner_interrupt_controller_1_register.int1_sts ) & runner_interrupt_mask_register.int1_mask;
        break;
    }
#endif

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_interrupt_clear ( uint32_t  xi_interrupt_number,
                                             uint32_t  xi_sub_interrpt_number )
{
#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_CFG_INT_CTRL  runner_interrupt_controller_register;

    RDD_CLEAR_REGISTER ( &runner_interrupt_controller_register );

    /* clear the interrupt by writing "1" to the corresponding bit in the Runner's interrupt register */
    switch ( xi_interrupt_number )
    {
    case 0:
        runner_interrupt_controller_register.int0_sts = ( 1 << xi_sub_interrpt_number );
        break;
    case 1:
        runner_interrupt_controller_register.int1_sts = ( 1 << xi_sub_interrpt_number );
        break;
    case 2:
        runner_interrupt_controller_register.int2_sts = 1;
        break;
    case 3:
        runner_interrupt_controller_register.int3_sts = 1;
        break;
    case 4:
        runner_interrupt_controller_register.int4_sts = 1;
        break;
    case 5:
        runner_interrupt_controller_register.int5_sts = 1;
        break;
    case 6:
        runner_interrupt_controller_register.int6_sts = 1;
        break;
    case 7:
        runner_interrupt_controller_register.int7_sts = 1;
        break;
    case 8:
        runner_interrupt_controller_register.int8_sts = 1;
        break;
    case 9:
        runner_interrupt_controller_register.int9_sts = 1;
        break;
    }

    RUNNER_REGS_0_CFG_INT_CTRL_WRITE ( runner_interrupt_controller_register );
    RUNNER_REGS_1_CFG_INT_CTRL_WRITE ( runner_interrupt_controller_register );
#endif

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_interrupt_mask ( uint32_t  xi_interrupt_number,
                                            uint32_t  xi_sub_interrpt_number )
{
    unsigned long             flags;
#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_CFG_INT_MASK  runner_interrupt_mask_register;
#endif

    f_rdd_lock_irq(&int_lock_irq, &flags);

#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_0_CFG_INT_MASK_READ ( runner_interrupt_mask_register );
#endif


    /* mask the interrupt by writing "1" to the corresponding bit in the Runner's interrupt register */
    switch ( xi_interrupt_number )
    {
#if !defined(FIRMWARE_INIT)
    case 0:
        runner_interrupt_mask_register.int0_mask &= ~( 1 << xi_sub_interrpt_number );
        break;
    case 1:
        runner_interrupt_mask_register.int1_mask &= ~( 1 << xi_sub_interrpt_number );
        break;
#endif
    default:
        break;
    }

#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_0_CFG_INT_MASK_WRITE ( runner_interrupt_mask_register );
    RUNNER_REGS_1_CFG_INT_MASK_WRITE ( runner_interrupt_mask_register );
#endif

    f_rdd_unlock_irq (&int_lock_irq, flags);
    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_interrupt_unmask ( uint32_t  xi_interrupt_number,
                                              uint32_t  xi_sub_interrpt_number )
{
    unsigned long             flags;
#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_CFG_INT_MASK  runner_interrupt_mask_register;
#endif
    BL_LILAC_RDD_ERROR_DTE    rdd_error = BL_LILAC_RDD_OK;

    f_rdd_lock_irq (&int_lock_irq, &flags);

#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_0_CFG_INT_MASK_READ ( runner_interrupt_mask_register );
#endif
    
    /* mask the interrupt by writing "1" to the corresponding bit in the Runner's interrupt register */
    switch ( xi_interrupt_number )
    {
#if !defined(FIRMWARE_INIT)
    case 0:
        runner_interrupt_mask_register.int0_mask |= ( 1 << xi_sub_interrpt_number );
        break;
    case 1:
        runner_interrupt_mask_register.int1_mask |= ( 1 << xi_sub_interrpt_number );
        break;
#endif
    default:
        break;
    }

#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_0_CFG_INT_MASK_WRITE ( runner_interrupt_mask_register );
    RUNNER_REGS_1_CFG_INT_MASK_WRITE ( runner_interrupt_mask_register );
#endif

    f_rdd_unlock_irq (&int_lock_irq, flags);
    return ( rdd_error );
}


BL_LILAC_RDD_ERROR_DTE rdd_interrupt_mask_get ( uint32_t  xi_interrupt_number,
                                                uint8_t   *xo_sub_interrpt_mask )
{
#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_CFG_INT_MASK  runner_interrupt_mask_register;

    switch ( xi_interrupt_number )
    {
    case 0:
        RUNNER_REGS_0_CFG_INT_MASK_READ ( runner_interrupt_mask_register );
        *xo_sub_interrpt_mask = runner_interrupt_mask_register.int0_mask;
        break;
    case 1:
        RUNNER_REGS_1_CFG_INT_MASK_READ ( runner_interrupt_mask_register );
        *xo_sub_interrpt_mask = runner_interrupt_mask_register.int1_mask;
        break;
    }
#endif

    return ( BL_LILAC_RDD_OK );
}


#if !defined(DSL_63138) && !defined(DSL_63148)
BL_LILAC_RDD_ERROR_DTE rdd_sa_mac_lookup_config ( BL_LILAC_RDD_BRIDGE_PORT_DTE  xi_bridge_port,
                                                  BL_LILAC_RDD_MAC_LOOKUP_DTE   xi_src_mac_lookup_mode )
{
    RDD_INGRESS_FILTERS_CONFIGURATION_TABLE_DTS  *filters_cfg_table_ptr;
    RDD_INGRESS_FILTERS_CONFIGURATION_ENTRY_DTS  *filters_cfg_entry_ptr;
    int32_t                                      bridge_port_index;

    if ( ( xi_bridge_port == BL_LILAC_RDD_WAN_BRIDGE_PORT ) || ( xi_bridge_port == BL_LILAC_RDD_WAN_IPTV_BRIDGE_PORT ) )
    {
        filters_cfg_table_ptr = ( RDD_INGRESS_FILTERS_CONFIGURATION_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + INGRESS_FILTERS_CONFIGURATION_TABLE_ADDRESS );
    }
    else if ( ( ( xi_bridge_port >= BL_LILAC_RDD_LAN0_BRIDGE_PORT ) && ( xi_bridge_port <= BL_LILAC_RDD_LAN4_BRIDGE_PORT ) ) || ( xi_bridge_port == BL_LILAC_RDD_PCI_BRIDGE_PORT ) )
    {
        filters_cfg_table_ptr = ( RDD_INGRESS_FILTERS_CONFIGURATION_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + INGRESS_FILTERS_CONFIGURATION_TABLE_ADDRESS );
    }
    else
    {
        return ( BL_LILAC_RDD_ERROR_ILLEGAL_BRIDGE_PORT_ID );
    }

    if ( ( bridge_port_index = rdd_bridge_port_to_port_index ( xi_bridge_port, 0 ) ) < 0 )
    {
        return ( BL_LILAC_RDD_ERROR_ILLEGAL_BRIDGE_PORT_ID );
    }

    filters_cfg_entry_ptr = &( filters_cfg_table_ptr->entry[ bridge_port_index ] );

    RDD_INGRESS_FILTERS_CONFIGURATION_ENTRY_SRC_MAC_LOOKUP_WRITE ( xi_src_mac_lookup_mode, filters_cfg_entry_ptr );

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_da_mac_lookup_config ( BL_LILAC_RDD_BRIDGE_PORT_DTE  xi_bridge_port,
                                                  BL_LILAC_RDD_MAC_LOOKUP_DTE   xi_dst_mac_lookup_mode )
{
    RDD_INGRESS_FILTERS_CONFIGURATION_TABLE_DTS  *filters_cfg_table_ptr;
    RDD_INGRESS_FILTERS_CONFIGURATION_ENTRY_DTS  *filters_cfg_entry_ptr;
    int32_t                                      bridge_port_index;

    if ( ( xi_bridge_port == BL_LILAC_RDD_WAN_BRIDGE_PORT ) || ( xi_bridge_port == BL_LILAC_RDD_WAN_ROUTER_PORT ) )
    {
        filters_cfg_table_ptr = ( RDD_INGRESS_FILTERS_CONFIGURATION_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + INGRESS_FILTERS_CONFIGURATION_TABLE_ADDRESS );
    }
    else if ( ( ( xi_bridge_port >= BL_LILAC_RDD_LAN0_BRIDGE_PORT ) && ( xi_bridge_port <= BL_LILAC_RDD_LAN4_BRIDGE_PORT ) ) || ( xi_bridge_port == BL_LILAC_RDD_PCI_BRIDGE_PORT ) )
    {
        filters_cfg_table_ptr = ( RDD_INGRESS_FILTERS_CONFIGURATION_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + INGRESS_FILTERS_CONFIGURATION_TABLE_ADDRESS );
    }
    else
    {
        return ( BL_LILAC_RDD_ERROR_ILLEGAL_BRIDGE_PORT_ID );
    }

    if ( ( bridge_port_index = rdd_bridge_port_to_port_index ( xi_bridge_port, BL_LILAC_RDD_SUBNET_FLOW_CACHE ) ) < 0 )
    {
        return ( BL_LILAC_RDD_ERROR_ILLEGAL_BRIDGE_PORT_ID );
    }

    filters_cfg_entry_ptr = &( filters_cfg_table_ptr->entry[ bridge_port_index ] );

    RDD_INGRESS_FILTERS_CONFIGURATION_ENTRY_DST_MAC_LOOKUP_WRITE ( xi_dst_mac_lookup_mode,filters_cfg_entry_ptr );

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_unknown_sa_mac_cmd_config ( BL_LILAC_RDD_BRIDGE_PORT_DTE          xi_bridge_port,
                                                       BL_LILAC_RDD_UNKNOWN_MAC_COMMAND_DTE  xi_slf_cmd )
{
    RDD_BRIDGE_CONFIGURATION_REGISTER_DTS  *bridge_cfg_register;

    if ( ( xi_bridge_port == BL_LILAC_RDD_WAN_BRIDGE_PORT ) || ( xi_bridge_port == BL_LILAC_RDD_WAN_IPTV_BRIDGE_PORT ) || ( xi_bridge_port == BL_LILAC_RDD_WAN_ROUTER_PORT ) )
    {
        bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

        switch ( xi_bridge_port )
        {
        case BL_LILAC_RDD_WAN_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_WAN_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_WAN_IPTV_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_WAN_IPTV_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_WAN_ROUTER_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_WAN_ROUTER_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        default:
            break;
        }
    }
    else
    {
        bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

        switch ( xi_bridge_port )
        {
        case BL_LILAC_RDD_LAN0_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH0_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_LAN1_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH1_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_LAN2_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH2_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_LAN3_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH3_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_LAN4_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH4_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_PCI_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_PCI_UNKNOWN_SA_COMMAND_WRITE ( xi_slf_cmd, bridge_cfg_register );
            break;

        default:
            break;
        }
    }

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_unknown_da_mac_cmd_config ( BL_LILAC_RDD_BRIDGE_PORT_DTE          xi_bridge_port,
                                                       BL_LILAC_RDD_UNKNOWN_MAC_COMMAND_DTE  xi_dlf_cmd )
{
    RDD_BRIDGE_CONFIGURATION_REGISTER_DTS  *bridge_cfg_register;

    if ( ( xi_bridge_port == BL_LILAC_RDD_WAN_BRIDGE_PORT ) || ( xi_bridge_port == BL_LILAC_RDD_WAN_ROUTER_PORT ) )
    {
        bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

        switch ( xi_bridge_port )
        {
        case BL_LILAC_RDD_WAN_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_WAN_UNKNOWN_DA_COMMAND_WRITE ( xi_dlf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_WAN_ROUTER_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_WAN_ROUTER_UNKNOWN_DA_COMMAND_WRITE ( xi_dlf_cmd, bridge_cfg_register );
            break;

        default:
            break;
        }
    }
    else
    {
        bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

        switch ( xi_bridge_port )
        {
        case BL_LILAC_RDD_LAN0_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH0_UNKNOWN_DA_COMMAND_WRITE ( xi_dlf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_LAN1_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH1_UNKNOWN_DA_COMMAND_WRITE ( xi_dlf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_LAN2_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH2_UNKNOWN_DA_COMMAND_WRITE ( xi_dlf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_LAN3_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH3_UNKNOWN_DA_COMMAND_WRITE ( xi_dlf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_LAN4_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_ETH4_UNKNOWN_DA_COMMAND_WRITE ( xi_dlf_cmd, bridge_cfg_register );
            break;

        case BL_LILAC_RDD_PCI_BRIDGE_PORT:

            RDD_BRIDGE_CONFIGURATION_REGISTER_PCI_UNKNOWN_DA_COMMAND_WRITE ( xi_dlf_cmd, bridge_cfg_register );
            break;

        default:
            break;
        }
    }

    return ( BL_LILAC_RDD_OK );
}
#endif /* !DSL */


BL_LILAC_RDD_ERROR_DTE rdd_timer_task_config ( rdpa_traffic_dir  xi_direction,
                                               uint16_t          xi_task_period_in_usec,
                                               uint16_t          xi_firmware_routine_address_id )
{
    RDD_TIMER_CONTROL_DESCRIPTOR_DTS       *timer_control_descriptor_ptr;
    RDD_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS    *timer_tasks_table_ptr;
    RDD_TIMER_TASK_DESCRIPTOR_ENTRY_DTS    *timer_tasks_entry_ptr;
    RDD_BRIDGE_CONFIGURATION_REGISTER_DTS  *bridge_cfg_register_ptr;
#if !defined(FIRMWARE_INIT)
    RUNNER_REGS_CFG_CPU_WAKEUP             runner_cpu_wakeup_register;
#endif
    uint16_t                               number_of_active_tasks;
    uint16_t                               task_period_reload;

    if ( ( xi_task_period_in_usec % TIMER_SCHEDULER_TASK_PERIOD ) != 0 )
    {
        return ( BL_LILAC_RDD_ERROR_TIMER_TASK_PERIOD );
    }

    if ( xi_direction == rdpa_dir_ds )
    {

        bridge_cfg_register_ptr = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

        if ( ( xi_firmware_routine_address_id == CPU_RX_METER_BUDGET_ALLOCATE_CODE_ID ) ||
             ( xi_firmware_routine_address_id == FREE_SKB_INDEX_ALLOCATE_CODE_ID ) )
        {
            timer_control_descriptor_ptr = ( RDD_TIMER_CONTROL_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MAIN_TIMER_CONTROL_DESCRIPTOR_ADDRESS );

            timer_tasks_table_ptr = ( RDD_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS );
        }
        else
        {
            timer_control_descriptor_ptr = ( RDD_TIMER_CONTROL_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_TIMER_CONTROL_DESCRIPTOR_ADDRESS );

            timer_tasks_table_ptr = ( RDD_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_PICO_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS );
        }
    }
    else
    {
        bridge_cfg_register_ptr = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

        if ( ( xi_firmware_routine_address_id == CPU_RX_METER_BUDGET_ALLOCATE_CODE_ID ) || ( xi_firmware_routine_address_id == UPSTREAM_RATE_LIMITER_BUDGET_ALLOCATE_CODE_ID ) ||
             ( xi_firmware_routine_address_id == FREE_SKB_INDEX_ALLOCATE_CODE_ID ) )
        {
            timer_control_descriptor_ptr = ( RDD_TIMER_CONTROL_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_MAIN_TIMER_CONTROL_DESCRIPTOR_ADDRESS );

            timer_tasks_table_ptr = ( RDD_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS );
        }
        else
        {
            timer_control_descriptor_ptr = ( RDD_TIMER_CONTROL_DESCRIPTOR_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_TIMER_CONTROL_DESCRIPTOR_ADDRESS );

            timer_tasks_table_ptr = ( RDD_MAIN_TIMER_TASK_DESCRIPTOR_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_PICO_TIMER_TASK_DESCRIPTOR_TABLE_ADDRESS );
        }
    }

    RDD_BRIDGE_CONFIGURATION_REGISTER_TIMER_SCHEDULER_PERIOD_WRITE ( TIMER_SCHEDULER_TASK_PERIOD - 1, bridge_cfg_register_ptr );

    RDD_TIMER_CONTROL_DESCRIPTOR_NUMBER_OF_ACTIVE_TASKS_READ ( number_of_active_tasks, timer_control_descriptor_ptr );

    if ( number_of_active_tasks == LILAC_RDD_NUMBER_OF_TIMER_TASKS )
    {
        return ( BL_LILAC_RDD_ERROR_TIMER_TASK_TABLE_FULL );
    }

    timer_tasks_entry_ptr = &timer_tasks_table_ptr->entry[ number_of_active_tasks ];

    RDD_TIMER_TASK_DESCRIPTOR_ENTRY_FIRMWARE_PTR_WRITE ( xi_firmware_routine_address_id, timer_tasks_entry_ptr );

    task_period_reload = xi_task_period_in_usec / TIMER_SCHEDULER_TASK_PERIOD;

    RDD_TIMER_TASK_DESCRIPTOR_ENTRY_COUNTER_RELOAD_WRITE ( task_period_reload, timer_tasks_entry_ptr );
    RDD_TIMER_TASK_DESCRIPTOR_ENTRY_PERIOD_WRITE ( 1, timer_tasks_entry_ptr );

    number_of_active_tasks++;

    RDD_TIMER_CONTROL_DESCRIPTOR_NUMBER_OF_ACTIVE_TASKS_WRITE ( number_of_active_tasks, timer_control_descriptor_ptr );

#if !defined(FIRMWARE_INIT)
    if ( number_of_active_tasks == 1 )
    {
        if ( ( xi_firmware_routine_address_id == UPSTREAM_INGRESS_RATE_LIMITER_BUDGET_ALLOCATE_CODE_ID ) ||
             ( xi_firmware_routine_address_id == UPSTREAM_QUASI_BUDGET_ALLOCATE_CODE_ID ) ||
             ( xi_firmware_routine_address_id == DOWNSTREAM_RATE_LIMITER_BUDGET_ALLOCATE_CODE_ID ) )
        {
            runner_cpu_wakeup_register.req_trgt = TIMER_SCHEDULER_PICO_THREAD_NUMBER / 32;
            runner_cpu_wakeup_register.thread_num = TIMER_SCHEDULER_PICO_THREAD_NUMBER % 32;
        }
        else
        {
            runner_cpu_wakeup_register.req_trgt = TIMER_SCHEDULER_MAIN_THREAD_NUMBER / 32;
            runner_cpu_wakeup_register.thread_num = TIMER_SCHEDULER_MAIN_THREAD_NUMBER % 32;
        }

        if ( xi_direction == rdpa_dir_ds )
        {
            RUNNER_REGS_0_CFG_CPU_WAKEUP_WRITE ( runner_cpu_wakeup_register );
        }
        else
        {
            RUNNER_REGS_1_CFG_CPU_WAKEUP_WRITE ( runner_cpu_wakeup_register );
        }
    }
#endif

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_4_bytes_counter_get ( uint32_t  xi_counter_group, 
                                                 uint32_t  xi_counter_num,
                                                 uint32_t  *xo_counter )
{
    BL_LILAC_RDD_ERROR_DTE  rdd_error;
    uint32_t                *pm_counters_buffer_ptr;
    unsigned long           flags;

    f_rdd_lock_irq ( &int_lock_irq, &flags );

    /* read user counter and reset its value */
    rdd_error = f_rdd_cpu_tx_send_message ( LILAC_RDD_CPU_TX_MESSAGE_PM_COUNTER_GET, FAST_RUNNER_A, RUNNER_PRIVATE_0_OFFSET,
                                            xi_counter_group + xi_counter_num / 16, xi_counter_num % 16, LILAC_RDD_TRUE, BL_LILAC_RDD_WAIT );

    if ( rdd_error != BL_LILAC_RDD_OK )
    {
        f_rdd_unlock_irq ( &int_lock_irq, flags );
        return ( rdd_error );
    }

    pm_counters_buffer_ptr = ( uint32_t * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + PM_COUNTERS_BUFFER_ADDRESS );

    MREAD_32( ( uint32_t * )pm_counters_buffer_ptr, *xo_counter );

    f_rdd_unlock_irq ( &int_lock_irq, flags );
    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE rdd_2_bytes_counter_get ( uint32_t  xi_counter_group,
                                                 uint32_t  xi_counter_num,
                                                 uint16_t  *xo_counter )
{
    BL_LILAC_RDD_ERROR_DTE  rdd_error;
    uint16_t                *pm_counters_buffer_ptr;
    unsigned long           flags;

    f_rdd_lock_irq ( &int_lock_irq, &flags );

    /* read user counter and reset its value */
    rdd_error = f_rdd_cpu_tx_send_message ( LILAC_RDD_CPU_TX_MESSAGE_PM_COUNTER_GET, FAST_RUNNER_A, RUNNER_PRIVATE_0_OFFSET,
                                            xi_counter_group + xi_counter_num / 32, xi_counter_num % 32, LILAC_RDD_FALSE, BL_LILAC_RDD_WAIT );

    if ( rdd_error != BL_LILAC_RDD_OK )
    {
        f_rdd_unlock_irq ( &int_lock_irq, flags );
        return ( rdd_error );
    }

    pm_counters_buffer_ptr = ( uint16_t * )(DEVICE_ADDRESS( RUNNER_COMMON_0_OFFSET ) + PM_COUNTERS_BUFFER_ADDRESS );

    MREAD_16( ( uint16_t * )pm_counters_buffer_ptr, *xo_counter );

    f_rdd_unlock_irq ( &int_lock_irq, flags );
    return ( BL_LILAC_RDD_OK );
}


void rdd_local_switching_fc_enable ( BL_LILAC_RDD_EMAC_ID_DTE      emac_id,
                                     bdmf_boolean                  fc_mode )
{
}


BL_LILAC_RDD_ERROR_DTE rdd_debug_mode_config ( bdmf_boolean  xi_enable )
{
    RDD_BRIDGE_CONFIGURATION_REGISTER_DTS  *bridge_cfg_register;

    bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

    RDD_BRIDGE_CONFIGURATION_REGISTER_DEBUG_MODE_WRITE ( xi_enable, bridge_cfg_register );

    bridge_cfg_register = ( RDD_BRIDGE_CONFIGURATION_REGISTER_DTS * )(DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_BRIDGE_CONFIGURATION_REGISTER_ADDRESS );

    RDD_BRIDGE_CONFIGURATION_REGISTER_DEBUG_MODE_WRITE ( xi_enable, bridge_cfg_register );

    return ( BL_LILAC_RDD_OK );
}


/******************************************************************************/
/*                                                                            */
/*               CRC Software Variables (HASH Function)                       */
/*                                                                            */
/******************************************************************************/

static const int32_t  order[2] = { 16, 32 };
static const int32_t  direct[2] = { 1, 1 };
static const int32_t  refin[2] = { 0, 0 };
static const int32_t  refout[2] = { 0, 0 };
static const uint32_t polynom[2] = { 0x1021, 0x04C11DB7 };
static const uint32_t crcinit[2] = { 0xFFFF, 0xFFFFFFFF };
static const uint32_t crcxor[2] = { 0x0, 0xFFFFFFFF };

static uint32_t crcmask[2];
static uint32_t crchighbit[2];
static uint32_t crcinit_direct[2];
static uint32_t crcinit_nondirect[2];
static uint32_t crctab[2][256];

static uint32_t reflect ( uint32_t crc, int32_t bitnum ) {

    /* reflects the lower 'bitnum' bits of 'crc' */
    uint32_t i, j = 1, crcout = 0;

    for ( i = (uint32_t)1 << ( bitnum - 1 ); i; i >>= 1 ) {
        if ( crc & i )
            crcout |= j;

        j <<= 1;
    }

    return ( crcout );
}


uint32_t crcbitbybit ( uint8_t *p, uint32_t byte_len, uint32_t bit_len, uint32_t crc_residue, uint32_t crc_type )
{
    /* bit by bit algorithm with augmented zero bytes.
       does not use lookup table, suited for polynom orders between 1...32. */
    uint32_t  i, j, c, bit;
    uint32_t  crc = crc_residue;

    if ( bit_len != 0 )
    {
        c = *p++;

        if ( refin[crc_type] )
        {
            c = reflect ( c, 8 );
        }

        j = ( 1 << ( bit_len - 1 ) );

        for ( ; j ; j >>= 1 )
        {
            bit = crc & crchighbit[crc_type];
            crc <<= 1;

            if ( c & j )
            {
                bit ^= crchighbit[crc_type];
            }

            if ( bit )
            {
                crc ^= polynom[crc_type];
            }
        }
    }

    for ( i = 0; i < byte_len; i++ ) {
        c = (uint32_t)*p++;

        if ( refin[crc_type] )
            c = reflect (c, 8);

        for ( j = 0x80; j; j >>= 1 ) {
            bit = crc & crchighbit[crc_type];
            crc <<= 1;

            if ( c & j )
                bit ^= crchighbit[crc_type];

            if ( bit )
                crc^= polynom[crc_type];
        }
    }

    if ( refout[crc_type] )
        crc = reflect (crc, order[crc_type]);

    crc ^= crcxor[crc_type];
    crc &= crcmask[crc_type];

    return ( crc );
}


static void generate_crc_table ( void )
{
    /* make CRC lookup table used by table algorithms */
    int32_t   i, j;
    uint32_t  bit, crc;
    uint32_t  crc_type;

    for ( crc_type = RDD_CRC_TYPE_16; crc_type <= RDD_CRC_TYPE_32; crc_type++ )
    {
        for ( i = 0; i < 256; i++ ) {
            crc = ( uint32_t )i;

            if ( refin[crc_type] )
                crc = reflect ( crc, 8 );

            crc <<= order[crc_type] - 8;

            for ( j = 0; j < 8; j++ ) {
                bit = crc & crchighbit[crc_type];
                crc <<= 1;

                if ( bit )
                    crc ^= polynom[crc_type];
            }

            if ( refin[crc_type] )
                crc = reflect ( crc, order[crc_type] );

            crc &= crcmask[crc_type];
            crctab[crc_type][i] = crc;
        }
    }
}

void init_crc ( void )
{
    uint32_t  i;
    uint32_t  bit, crc;
    uint32_t  crc_type;

    for ( crc_type = RDD_CRC_TYPE_16; crc_type <= RDD_CRC_TYPE_32; crc_type++ )
    {
        /* at first, compute constant bit masks for whole CRC and CRC high bit */
        crcmask[crc_type] = ((((uint32_t)1 << (order[crc_type]-1)) - 1) << 1) | 1;
        crchighbit[crc_type] = (uint32_t)1 << (order[crc_type]-1);

        generate_crc_table ();

        /* compute missing initial CRC value */
        if ( !direct[crc_type] ) {
            crcinit_nondirect[crc_type] = crcinit[crc_type];
            crc = crcinit[crc_type];

            for ( i = 0; i < order[crc_type]; i++ ) {
                bit = crc & crchighbit[crc_type];
                crc <<= 1;

                if ( bit )
                    crc ^= polynom[crc_type];
            }

            crc &= crcmask[crc_type];
            crcinit_direct[crc_type] = crc;
        }
        else {
            crcinit_direct[crc_type] = crcinit[crc_type];
            crc = crcinit[crc_type];

            for ( i = 0; i < order[crc_type]; i++ ) {
                bit = crc & 1;

                if ( bit )
                    crc ^= polynom[crc_type];

                crc >>= 1;

                if ( bit )
                    crc |= crchighbit[crc_type];
            }

            crcinit_nondirect[crc_type] = crc;
        }
    }
}


uint32_t get_crc_init_value ( uint32_t crc_type )
{
    return ( crcinit_direct[crc_type] );
}

#if defined(FIRMWARE_INIT)

BL_LILAC_RDD_ERROR_DTE bl_lilac_rdd_print_connection ( uint32_t  xi_entry_index )
{
#if !defined(DSL_63138) && !defined(DSL_63148)
    RDD_CONNECTION_TABLE_DTS     *connection_table_ptr;
    RDD_CONNECTION_ENTRY_DTS     *connection_entry_ptr;
    RDD_CONTEXT_TABLE_DTS        *context_table_ptr;
    RDD_CONTEXT_ENTRY_UNION_DTS  *context_entry_ptr;
    uint16_t                     index;

    if ( xi_entry_index >= RDD_CONTEXT_TABLE_SIZE )
    {
        return ( BL_LILAC_RDD_ERROR_CONTEXT_ENTRY_INVALID );
    }

    context_table_ptr = ( RDD_CONTEXT_TABLE_DTS * )ContextTableBase;

    context_entry_ptr = &( context_table_ptr->entry[ xi_entry_index ] );

    if ( context_entry_ptr->ds_context_entry.connection_direction == rdpa_dir_ds )
    {
        connection_table_ptr = ( RDD_CONNECTION_TABLE_DTS * )DsConnectionTableBase;
    }
    else
    {
        connection_table_ptr = ( RDD_CONNECTION_TABLE_DTS * )UsConnectionTableBase;
    }

    connection_entry_ptr = &( connection_table_ptr->entry[ context_entry_ptr->ds_context_entry.connection_table_index ] );

    printf ( "Lookup Entry Index     = %08X\n", ( unsigned int )context_entry_ptr->ds_context_entry.connection_table_index );

    if ( context_entry_ptr->ds_context_entry.connection_direction == rdpa_dir_ds )
    {
        printf ( "Connection number      = %02X\n", ( unsigned char ) xi_entry_index );
        printf ( "Direction              = Downstream\n");
        printf ( "Protocol               = %02X\n", ( unsigned char ) connection_entry_ptr->protocol );
        printf ( "Src Port               = %08X\n", ( unsigned int ) connection_entry_ptr->src_port );
        printf ( "Dst Port               = %08X\n", ( unsigned int ) connection_entry_ptr->dst_port );
        printf ( "Src IP                 = %08X\n", ( unsigned int ) connection_entry_ptr->src_ip );
        printf ( "Dst IP                 = %08X\n", ( unsigned int ) connection_entry_ptr->dst_ip );
        printf ( "Context Entry Index    = %08X\n", ( unsigned int ) connection_entry_ptr->context_index );
        printf ( "Activity               = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.activity_status );
        printf ( "Packet counter         = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.valid_packets_counter );
        printf ( "FWD Action             = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.fwd_action );
        printf ( "Reason                 = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.cpu_reason );
        printf ( "DSCP En                = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.dscp_enable );
        printf ( "DSCP Value             = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.dscp_value );
        printf ( "NAT Port               = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.nat_port );
        printf ( "NAT IP                 = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.nat_ip );
        printf ( "Route IP index         = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.dst_route_ip_index );
        printf ( "TCP Chksm Delta        = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.layer4_checksum_delta );
        printf ( "IP Chksm Delta         = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.ip_checksum_delta );
        printf ( "Second direction valid = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.second_direction_valid );
        printf ( "Second direction index = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.second_direction_index );
        printf ( "Table Index            = %08X\n", ( unsigned int ) context_entry_ptr->ds_context_entry.connection_table_index );
    }
    else
    {
        printf ( "Connection number      = %02X\n", ( unsigned char ) xi_entry_index );
        printf ( "Direction              = Upstream\n");
        printf ( "Protocol               = %02X\n", ( unsigned char ) connection_entry_ptr->protocol );
        printf ( "Src Port               = %08X\n", ( unsigned int ) connection_entry_ptr->src_port );
        printf ( "Dst Port               = %08X\n", ( unsigned int ) connection_entry_ptr->dst_port );
        printf ( "Src IP                 = %08X\n", ( unsigned int ) connection_entry_ptr->src_ip );
        printf ( "Dst IP                 = %08X\n", ( unsigned int ) connection_entry_ptr->dst_ip );
        printf ( "Context Entry Index    = %08X\n", ( unsigned int ) connection_entry_ptr->context_index );
        printf ( "Activity               = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.activity_status );
        printf ( "Packet counter         = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.valid_packets_counter );
        printf ( "FWD Action             = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.fwd_action );
        printf ( "Reason                 = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.cpu_reason );
        printf ( "DSCP En                = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.dscp_enable );
        printf ( "DSCP Value             = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.dscp_value );
        printf ( "NAT Port               = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.nat_port );
        printf ( "Route IP index         = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.dst_route_ip_index );
        printf ( "Subnet ID              = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.wan_subnet_id );
        printf ( "TCP Chksm Delta        = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.layer4_checksum_delta );
        printf ( "IP Chksm Delta         = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.ip_checksum_delta );
        printf ( "Second direction valid = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.second_direction_valid );
        printf ( "Second direction index = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.second_direction_index );
        printf ( "Table Index            = %08X\n", ( unsigned int ) context_entry_ptr->us_context_entry.connection_table_index );
    }

    printf ( "User Defined:          = " );

    for ( index = 0; index < 24; index++ )
    {
        printf (  "%02X ", ( unsigned char )context_entry_ptr->ds_context_entry.user_defined[ index ] );
    }

    printf ( "\n" );
#endif

    return ( BL_LILAC_RDD_OK );
}


#ifdef USE_DFP
#define SET_DDR_FORMAT "set ddr h.%08x h.%08x\n"
#define SET_PSRAM_FORMAT "set psram h.%08x h.%08x\n"
#else
#define SET_DDR_FORMAT "set ddr %08x %08x\n"
#define SET_PSRAM_FORMAT "set psram %08x %08x\n"
#endif

void save_connection_table ( FILE                      *ddr_tables,
                             RDD_CONNECTION_TABLE_DTS  *lookup_table_ptr,
                             uint32_t                  lookup_table_offset )
{
    RDD_CONTEXT_TABLE_DTS        *context_table_ptr = ( RDD_CONTEXT_TABLE_DTS * )ContextTableBase;
    RDD_CONNECTION_ENTRY_DTS     *lookup_entry_ptr;
    RDD_CONTEXT_ENTRY_UNION_DTS  *context_entry_ptr;
    uint32_t                     *ptr;
    uint32_t                     valid;
    uint32_t                     lookup_entry_address;
    uint32_t                     context_entry_address;
    uint16_t                     context_index;
    uint32_t                     i, j;

    for ( i = 0; i < RDD_CONNECTION_TABLE_SIZE; i++ )
    {
        lookup_entry_ptr = &( lookup_table_ptr->entry[ i ] );

        RDD_CONNECTION_ENTRY_VALID_READ ( valid, lookup_entry_ptr );

        if ( valid )
        {
            lookup_entry_address = g_runner_ddr_base_addr + lookup_table_offset + i * LILAC_RDD_CONNECTION_ENTRY_SIZE;

            for ( j = 0, ptr = ( uint32_t * )lookup_entry_ptr; j < sizeof ( RDD_CONNECTION_ENTRY_DTS ); j += 4, ptr++ )
            {
                fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )( lookup_entry_address + j ), ( unsigned int )MGET_32( ptr ) );
            }

            RDD_CONNECTION_ENTRY_CONTEXT_INDEX_READ ( context_index, lookup_entry_ptr );

            context_entry_ptr = &( context_table_ptr->entry[ context_index ] );

            context_entry_address = g_runner_tables_ptr + CONTEXT_TABLE_ADDRESS + context_index * LILAC_RDD_CONTEXT_ENTRY_SIZE;

            for ( j = 0, ptr = ( uint32_t * )context_entry_ptr; j < sizeof ( RDD_CONTEXT_ENTRY_UNION_DTS ); j += 4, ptr++ )
            {
                fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )( context_entry_address + j ), ( unsigned int )MGET_32( ptr ) );
            }
        }
    }

    return;
}



BL_LILAC_RDD_ERROR_DTE bl_lilac_rdd_save_ddr_tables ( void )
{
    FILE                            *ddr_tables;
#if !defined(DSL_63138) && !defined(DSL_63148)
    RDD_IPTV_DDR_LOOKUP_TABLE_DTS   *iptv_table_ptr;
    RDD_IPTV_DDR_CONTEXT_TABLE_DTS  *iptv_context_table_ptr;
    RDD_IPTV_DDR_CONTEXT_TABLE_DTS  *iptv_ssm_context_table_ptr;
    RDD_IPTV_LOOKUP_DDR_UNION_DTS   *iptv_entry_ptr;
    RDD_IPTV_DDR_CONTEXT_ENTRY_DTS  *iptv_context_entry_ptr;
    uint32_t                        *rules_map_table_ptr;
    uint32_t                        *rules_table_ptr;
    uint32_t                        lookup_entry_address;
    uint32_t                        context_entry_address;
    uint32_t                        lookup_entry_valid;
    uint32_t                        context_entry_valid;
    uint32_t                        rule_entry;
    uint32_t                        rule_entry_address;
#endif /* !DSL */
    uint32_t                        packet_descriptor_address;
    uint32_t                        *ptr;
    uint32_t                        i, j;
#if !defined(DSL_63138) && !defined(DSL_63148)
    uint32_t                        *ddr_address_for_sync_dma_ptr;
#endif /* !DSL */

    ddr_tables = fopen ( "ddr_tables.dfp", "w+b" );

    if ( ddr_tables == NULL )
    {
        printf ( "Error: Can't open ddr_tables.dfp file\n" );
        return ( BL_LILAC_RDD_OK );
    }

    save_connection_table ( ddr_tables, ( RDD_CONNECTION_TABLE_DTS * )DsConnectionTableBase, g_runner_tables_ptr + DS_CONNECTION_TABLE_ADDRESS );
    save_connection_table ( ddr_tables, ( RDD_CONNECTION_TABLE_DTS * )UsConnectionTableBase, g_runner_tables_ptr + US_CONNECTION_TABLE_ADDRESS );

#if defined(DSL_UNIT_TEST)
    {
        RDD_CONTEXT_TABLE_DTS        *context_table_ptr = ( RDD_CONTEXT_TABLE_DTS* )ContextTableBase;
        extern wlan_mcast_dhd_list_table_t wlan_mcast_dhd_list_table_g;
        extern uint32_t *FcPortHeaderBuffers;
        uint32_t i, addr;
        uint32_t *ptr = FcPortHeaderBuffers;

        /* Add multicast port header buffers. */
        for( i = 0; i < (RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE * RDD_FC_MCAST_PORT_HEADER_BUFFER_SIZE2) / 4; i++ )
        {
            addr = g_runner_ddr_base_addr + SIMULATOR_DDR_PORT_HEADER_BUFFERS_OFFSET + i * 4;
            fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )addr, ( unsigned int )MGET_32( &ptr[i] ) );
        }

        /* Add first 10 context entries because multicast contextes do not get written out in save_connection_table. */
        addr = g_runner_ddr_base_addr + CONTEXT_TABLE_ADDRESS;
        for ( i = 0, ptr = ( uint32_t * )&( context_table_ptr->entry[ 0 ] ); i < sizeof ( RDD_CONTEXT_ENTRY_UNION_DTS ) * 10; i += 4, ptr++ )
        {
            fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )( addr + i ), ( unsigned int )MGET_32( ptr ) );
        }

        /* Add first 4 wlan multicast dhd lists */
        ptr = ( uint32_t * )wlan_mcast_dhd_list_table_g.virt_p;
        printf("SIMULATOR_DDR_WLAN_MCAST_DHD_LIST 0x%08x\n", g_runner_ddr_base_addr + SIMULATOR_DDR_WLAN_MCAST_DHD_LIST_OFFSET);
        for( i = 0; i < (RDD_WLAN_MCAST_DHD_LIST_ENTRY_ARRAY_DHD_STATION_NUMBER/4) * 4; i++ )
        {
            addr = g_runner_ddr_base_addr + SIMULATOR_DDR_WLAN_MCAST_DHD_LIST_OFFSET + i * 4;
            fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )addr, ( unsigned int )MGET_32( &ptr[i] ) );
        }
    }
#endif

#if !defined(DSL_63138) && !defined(DSL_63148)
    iptv_table_ptr = ( RDD_IPTV_DDR_LOOKUP_TABLE_DTS * )IPTVTableBase;

    iptv_context_table_ptr = ( RDD_IPTV_DDR_CONTEXT_TABLE_DTS * )IPTVContextTableBase;

    for ( i = 0; i < RDD_IPTV_DDR_LOOKUP_TABLE_SIZE; i++ )
    {
        iptv_entry_ptr = &( iptv_table_ptr->entry[ i ] );

        RDD_IPTV_L3_DDR_LOOKUP_ENTRY_VALID_READ ( lookup_entry_valid, iptv_entry_ptr );

        if ( lookup_entry_valid )
        {
            lookup_entry_address = g_runner_ddr_base_addr + IPTV_DDR_LOOKUP_TABLE_ADDRESS + i * LILAC_RDD_IPTV_ENTRY_SIZE;

            for ( j = 0, ptr = ( uint32_t * )iptv_entry_ptr; j < sizeof ( RDD_IPTV_LOOKUP_DDR_UNION_DTS ); j += 4, ptr++ )
            {
                fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )( lookup_entry_address + j ), ( unsigned int )MGET_32( ptr ) );
            }

            iptv_context_entry_ptr = &( iptv_context_table_ptr->entry[ i ] );

            context_entry_address = g_runner_ddr_base_addr + IPTV_DDR_CONTEXT_TABLE_ADDRESS + i * LILAC_RDD_IPTV_CONTEXT_ENTRY_SIZE;

            for ( j = 0, ptr = ( uint32_t * )iptv_context_entry_ptr; j < sizeof ( RDD_IPTV_DDR_CONTEXT_ENTRY_DTS ); j += 4, ptr++ )
            {
                fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )( context_entry_address + j ), ( unsigned int )MGET_32( ptr ) );
            }
        }
    }

    iptv_ssm_context_table_ptr = ( RDD_IPTV_DDR_CONTEXT_TABLE_DTS * )IPTVSsmContextTableBase;

    for ( i = 0; i < LILAC_RDD_IPTV_SSM_CONTEXT_TABLE_SIZE; i++ )
    {
        iptv_context_entry_ptr = &( iptv_ssm_context_table_ptr->entry[ i ] );

        RDD_IPTV_DDR_CONTEXT_ENTRY_VALID_READ ( context_entry_valid, iptv_context_entry_ptr );

        if ( context_entry_valid )
        {
            context_entry_address = g_runner_ddr_base_addr + IPTV_SSM_DDR_CONTEXT_TABLE_ADDRESS + i * LILAC_RDD_IPTV_CONTEXT_ENTRY_SIZE;

            for ( j = 0, ptr = ( uint32_t * )iptv_context_entry_ptr; j < sizeof ( RDD_IPTV_DDR_CONTEXT_ENTRY_DTS ); j += 4, ptr++ )
            {
                fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )( context_entry_address + j ), ( unsigned int )MGET_32( ptr ) );
            }
        }
    }

    /* Save firewall rules map table */
    rules_map_table_ptr = ( uint32_t * )FirewallRulesMapTable;

    for ( i = 0; i < ( ( RDD_FIREWALL_RULES_MAP_TABLE_SIZE * RDD_FIREWALL_RULES_MAP_TABLE_SIZE2 * RDD_FIREWALL_RULES_MAP_TABLE_SIZE3 ) / 4 ); i++ )
    {
        rule_entry = rules_map_table_ptr[ i ];

        if ( rule_entry )
        {
#ifdef FIRMWARE_LITTLE_ENDIAN
            rule_entry = swap4bytes ( rule_entry );
#endif
            rule_entry_address = g_runner_ddr_base_addr + FIREWALL_RULES_MAP_TABLE_ADDRESS + i * 4;
            fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )rule_entry_address, ( unsigned int )rule_entry );
        }
    }

    /* Save firewall rules table */
    rules_table_ptr = ( uint32_t * )FirewallRulesTable;

    for ( i = 0; i < ( RDD_FIREWALL_RULES_TABLE_SIZE * sizeof ( RDD_FIREWALL_RULE_ENTRY_DTS ) ) / 4; i++ )
    {
        rule_entry = rules_table_ptr[ i ];

        if ( rule_entry )
        {
#ifdef FIRMWARE_LITTLE_ENDIAN
            rule_entry = swap4bytes ( rule_entry );
#endif
            rule_entry_address = g_runner_ddr_base_addr + FIREWALL_RULES_TABLE_ADDRESS + i * 4;
            fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )rule_entry_address, ( unsigned int )rule_entry );
        }
    }
#endif /* !DSL */

    /* Save DDR packet descriptors in rings */
    for ( i = 0, ptr = ( uint32_t * )CpuRxRingBase; i < ( RDD_RING_DESCRIPTORS_TABLE_SIZE * 10 ); i++ )
    {
        packet_descriptor_address = SIMULATOR_DDR_RING_OFFSET + sizeof ( RDD_CPU_RX_DESCRIPTOR_DTS ) * i;

        for ( j = 0; j < sizeof ( RDD_CPU_RX_DESCRIPTOR_DTS ); j += 4, ptr++ )
        {
            fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )( packet_descriptor_address + j ), ( unsigned int )MGET_32( ptr ) );
        }
    }

#if !defined(DSL_63138) && !defined(DSL_63148)
    ddr_address_for_sync_dma_ptr = ( uint32_t * )DdrAddressForSyncDmaBase;

    fprintf ( ddr_tables, SET_DDR_FORMAT, ( unsigned int )( g_runner_ddr_base_addr + DDR_ADDRESS_FOR_SYNC_DMA_ADDRESS ), ( unsigned int )MGET_32( ddr_address_for_sync_dma_ptr ) );
#endif /* !DSL */

    fclose ( ddr_tables );
    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE bl_lilac_rdd_copy_tx_pointers_table ( uint16_t  *copy_buffer )
{
    RDD_WAN_TX_POINTERS_ENTRY_DTS  *wan_tx_pointers_entry_ptr;
    uint32_t                       wan_channel_id;
    uint32_t                       rate_controller_id;
    uint32_t                       queue_id;

    for ( wan_channel_id = 0; wan_channel_id < ( RDD_WAN_CHANNELS_0_7_TABLE_SIZE + RDD_WAN_CHANNELS_8_39_TABLE_SIZE ); wan_channel_id++ )
    {
        for ( rate_controller_id = 0; rate_controller_id < RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLER_ADDR_NUMBER; rate_controller_id++ )
        {
            for ( queue_id = 0; queue_id < RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_NUMBER; queue_id++ )
            {
                wan_tx_pointers_entry_ptr = &( wan_tx_pointers_table_ptr->entry[ wan_channel_id ][ rate_controller_id ][ queue_id ] );

                if ( wan_tx_pointers_entry_ptr->wan_tx_queue_ptr )
                {
                    copy_buffer[ wan_channel_id * RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLER_ADDR_NUMBER * RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_NUMBER +
                                 rate_controller_id * RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_NUMBER + queue_id ] =
#ifdef FIRMWARE_LITTLE_ENDIAN
                        swap2bytes ( ( wan_tx_pointers_entry_ptr->wan_tx_queue_ptr - WAN_TX_QUEUES_TABLE_ADDRESS ) / sizeof ( RDD_WAN_TX_QUEUE_DESCRIPTOR_DTS ) );
#else
                        ( wan_tx_pointers_entry_ptr->wan_tx_queue_ptr - WAN_TX_QUEUES_TABLE_ADDRESS ) / sizeof ( RDD_WAN_TX_QUEUE_DESCRIPTOR_DTS );
#endif
                }
                else
                {
                    copy_buffer[ wan_channel_id * RDD_WAN_CHANNEL_0_7_DESCRIPTOR_RATE_CONTROLLER_ADDR_NUMBER * RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_NUMBER +
                                 rate_controller_id * RDD_US_RATE_CONTROLLER_DESCRIPTOR_TX_QUEUE_ADDR_NUMBER + queue_id ] = 0xFFFF;
                }
            }
        }
    }

    return ( BL_LILAC_RDD_OK );
}


BL_LILAC_RDD_ERROR_DTE bl_lilac_rdd_save_sim_config ( void )
{
    FILE                               *sim_config;
    RUNNER_REGS_CFG_DDR_CFG            runner_ddr_config_register;
    RUNNER_REGS_CFG_DDR_LKUP_MASK0     runner_ddr_lkup_mask0_register;
    RUNNER_REGS_CFG_DDR_LKUP_MASK1     runner_ddr_lkup_mask1_register;
    RUNNER_REGS_CFG_CNTR_CFG           runner_counter_cfg_register;
    RUNNER_REGS_CFG_CAM_CFG            runner_cam_cfg_register;
    RUNNER_REGS_CFG_LKUP0_CFG          hash_lkup_0_cfg_register;
    RUNNER_REGS_CFG_LKUP0_CAM_CFG      hash_lkup_0_cam_cfg_register;
    RUNNER_REGS_CFG_LKUP_GLBL_MASK0_H  hash_lkup_0_global_mask_high_register;
    RUNNER_REGS_CFG_LKUP_GLBL_MASK0_L  hash_lkup_0_global_mask_low_register;
    RUNNER_REGS_CFG_LKUP1_CFG          hash_lkup_1_cfg_register;
    RUNNER_REGS_CFG_LKUP1_CAM_CFG      hash_lkup_1_cam_cfg_register;
    RUNNER_REGS_CFG_LKUP_GLBL_MASK1_H  hash_lkup_1_global_mask_high_register;
    RUNNER_REGS_CFG_LKUP_GLBL_MASK1_L  hash_lkup_1_global_mask_low_register;
    RUNNER_REGS_CFG_LKUP2_CFG          hash_lkup_2_cfg_register;
    RUNNER_REGS_CFG_LKUP2_CAM_CFG      hash_lkup_2_cam_cfg_register;
    RUNNER_REGS_CFG_LKUP_GLBL_MASK2_H  hash_lkup_2_global_mask_high_register;
    RUNNER_REGS_CFG_LKUP_GLBL_MASK2_L  hash_lkup_2_global_mask_low_register;
    RUNNER_REGS_CFG_LKUP3_CFG          hash_lkup_3_cfg_register;
    RUNNER_REGS_CFG_LKUP3_CAM_CFG      hash_lkup_3_cam_cfg_register;
    RUNNER_REGS_CFG_LKUP_GLBL_MASK3_H  hash_lkup_3_global_mask_high_register;
    RUNNER_REGS_CFG_LKUP_GLBL_MASK3_L  hash_lkup_3_global_mask_low_register;
    uint32_t                           scheduler_config_register;

    sim_config = fopen ( "sim_config", "w+b" );

    if ( sim_config == NULL )
    {
        printf ( "Error: Can't open sim_config file\n" );
        return ( BL_LILAC_RDD_OK );
    }

    RUNNER_REGS_0_CFG_DDR_CFG_READ ( runner_ddr_config_register );
    fprintf ( sim_config, "ddr_base %08x %08x %d\n", ( runner_ddr_config_register.dma_base << 21 ), ( runner_ddr_config_register.dma_base << 21 ) + 0x1800000, runner_ddr_config_register.buffer_offset );

    RUNNER_REGS_0_CFG_DDR_LKUP_MASK0_READ( runner_ddr_lkup_mask0_register );
    fprintf ( sim_config, "set dma_lkp_global_0 %08x\n", runner_ddr_lkup_mask0_register.global_mask );

    RUNNER_REGS_0_CFG_DDR_LKUP_MASK1_READ( runner_ddr_lkup_mask1_register );
    fprintf ( sim_config, "set dma_lkp_global_1 %08x\n", runner_ddr_lkup_mask1_register.global_mask );

    RUNNER_REGS_0_CFG_PSRAM_LKUP_MASK0_READ( runner_ddr_lkup_mask0_register );
    fprintf ( sim_config, "set psram_lkp_global_0 %08x\n", runner_ddr_lkup_mask0_register.global_mask );

    RUNNER_REGS_0_CFG_CNTR_CFG_READ ( runner_counter_cfg_register );
    fprintf ( sim_config, "set counter A %x common\n", runner_counter_cfg_register.base_address << 3 );

    RUNNER_REGS_1_CFG_CNTR_CFG_READ ( runner_counter_cfg_register );
    fprintf ( sim_config, "set counter B %x common\n", runner_counter_cfg_register.base_address << 3 );

    RUNNER_REGS_0_CFG_CAM_CFG_READ ( runner_cam_cfg_register );
    fprintf ( sim_config, "set cam_stop_value A %x\n", runner_cam_cfg_register.stop_value );

    RUNNER_REGS_1_CFG_CAM_CFG_READ ( runner_cam_cfg_register );
    fprintf ( sim_config, "set cam_stop_value B %x\n", runner_cam_cfg_register.stop_value );


    /* save mac table 0 configuration - Runner A ( ingress classification ) */
    RUNNER_REGS_0_CFG_LKUP0_CFG_READ ( hash_lkup_0_cfg_register );
    RUNNER_REGS_0_CFG_LKUP0_CAM_CFG_READ ( hash_lkup_0_cam_cfg_register );

    fprintf ( sim_config, "set mac0 A %x %d %d %d", ( unsigned int )( hash_lkup_0_cfg_register.base_address << 3 ), ( int ) 32 * ( 1 << hash_lkup_0_cfg_register.table_size ),
                                                    ( int )( 1 << hash_lkup_0_cfg_register.max_hop ), ( int )hash_lkup_0_cfg_register.hash_type );

    if ( hash_lkup_0_cam_cfg_register.cam_en )
        fprintf ( sim_config, " %x\n", ( unsigned int )( hash_lkup_0_cam_cfg_register.base_address << 3 ) );
    else
        fprintf ( sim_config, " \n" );

    RUNNER_REGS_0_CFG_LKUP_GLBL_MASK0_H_READ ( hash_lkup_0_global_mask_high_register );
    RUNNER_REGS_0_CFG_LKUP_GLBL_MASK0_L_READ ( hash_lkup_0_global_mask_low_register );

    fprintf ( sim_config, "set global_mask_0 A %08x %08x\n", ( unsigned int )hash_lkup_0_global_mask_high_register.base_address, ( unsigned int )hash_lkup_0_global_mask_low_register.base_address );

    /* save mac table 0 configuration - Runner B ( ingress classification ) */
    RUNNER_REGS_1_CFG_LKUP0_CFG_READ ( hash_lkup_0_cfg_register );
    RUNNER_REGS_1_CFG_LKUP0_CAM_CFG_READ ( hash_lkup_0_cam_cfg_register );

    fprintf ( sim_config, "set mac0 B %x %d %d %d", ( unsigned int )( hash_lkup_0_cfg_register.base_address << 3 ), ( int ) 32 * ( 1 << hash_lkup_0_cfg_register.table_size ),
                                                    ( int )( 1 << hash_lkup_0_cfg_register.max_hop ), ( int )hash_lkup_0_cfg_register.hash_type );

    if ( hash_lkup_0_cam_cfg_register.cam_en )
        fprintf ( sim_config, " %x\n", ( unsigned int )( hash_lkup_0_cam_cfg_register.base_address << 3 ) );
    else
        fprintf ( sim_config, " \n" );

    RUNNER_REGS_1_CFG_LKUP_GLBL_MASK0_H_READ ( hash_lkup_0_global_mask_high_register );
    RUNNER_REGS_1_CFG_LKUP_GLBL_MASK0_L_READ ( hash_lkup_0_global_mask_low_register );

    fprintf ( sim_config, "set global_mask_0 B %08x %08x\n", ( unsigned int )hash_lkup_0_global_mask_high_register.base_address, ( unsigned int )hash_lkup_0_global_mask_low_register.base_address );


    /* save mac table 1 configuration - Runner A ( MAC lookup for downstream ) */
    RUNNER_REGS_0_CFG_LKUP1_CFG_READ ( hash_lkup_1_cfg_register );
    RUNNER_REGS_0_CFG_LKUP1_CAM_CFG_READ ( hash_lkup_1_cam_cfg_register );

    fprintf ( sim_config, "set mac1 A %x %d %d %d", hash_lkup_1_cfg_register.base_address << 3, 32 * ( 1 << hash_lkup_1_cfg_register.table_size ), 1 * ( 1 << hash_lkup_1_cfg_register.max_hop ), hash_lkup_1_cfg_register.hash_type );

    if ( hash_lkup_1_cam_cfg_register.cam_en )
        fprintf ( sim_config, " %x\n", hash_lkup_1_cam_cfg_register.base_address << 3 );
    else
        fprintf ( sim_config, " \n" );

    RUNNER_REGS_0_CFG_LKUP_GLBL_MASK1_H_READ ( hash_lkup_1_global_mask_high_register );
    RUNNER_REGS_0_CFG_LKUP_GLBL_MASK1_L_READ ( hash_lkup_1_global_mask_low_register );

    fprintf ( sim_config, "set global_mask_1 A %08x %08x\n", ( unsigned int )hash_lkup_1_global_mask_high_register.base_address, ( unsigned int )hash_lkup_1_global_mask_low_register.base_address );

    /* save mac table 1 configuration - Runner B ( MAC lookup for upstream ) */
    RUNNER_REGS_1_CFG_LKUP1_CFG_READ ( hash_lkup_1_cfg_register );
    RUNNER_REGS_1_CFG_LKUP1_CAM_CFG_READ ( hash_lkup_1_cam_cfg_register );

    fprintf ( sim_config, "set mac1 B %x %d %d %d", ( unsigned int )( hash_lkup_1_cfg_register.base_address << 3 ), ( int ) 32 * ( 1 << hash_lkup_1_cfg_register.table_size ),
                                                    ( int )( 1 << hash_lkup_1_cfg_register.max_hop ), ( int )hash_lkup_1_cfg_register.hash_type );

    if ( hash_lkup_1_cam_cfg_register.cam_en )
        fprintf ( sim_config, " %x\n", ( unsigned int )( hash_lkup_1_cam_cfg_register.base_address << 3 ) );
    else
        fprintf ( sim_config, " \n" );

    RUNNER_REGS_1_CFG_LKUP_GLBL_MASK1_H_READ ( hash_lkup_1_global_mask_high_register );
    RUNNER_REGS_1_CFG_LKUP_GLBL_MASK1_L_READ ( hash_lkup_1_global_mask_low_register );

    fprintf ( sim_config, "set global_mask_1 B %08x %08x\n", ( unsigned int )hash_lkup_1_global_mask_high_register.base_address, ( unsigned int )hash_lkup_1_global_mask_low_register.base_address );

    /* save mac table 2 configuration - Runner A ( ARP lookup for downstream ) */
    RUNNER_REGS_0_CFG_LKUP2_CFG_READ ( hash_lkup_2_cfg_register );
    RUNNER_REGS_0_CFG_LKUP2_CAM_CFG_READ ( hash_lkup_2_cam_cfg_register );

    fprintf ( sim_config, "set mac2 A %x %d %d %d", ( unsigned int )( hash_lkup_2_cfg_register.base_address << 3 ), ( int )32 * ( 1 << hash_lkup_2_cfg_register.table_size ),
                                                    ( int )( 1 << hash_lkup_2_cfg_register.max_hop ), ( int )hash_lkup_2_cfg_register.hash_type );

    if ( hash_lkup_2_cam_cfg_register.cam_en )
        fprintf ( sim_config, " %x\n", hash_lkup_2_cam_cfg_register.base_address << 3 );
    else
        fprintf ( sim_config, " \n" );

    RUNNER_REGS_0_CFG_LKUP_GLBL_MASK2_H_READ ( hash_lkup_2_global_mask_high_register );
    RUNNER_REGS_0_CFG_LKUP_GLBL_MASK2_L_READ ( hash_lkup_2_global_mask_low_register );

    fprintf ( sim_config, "set global_mask_2 A %08x %08x\n", ( unsigned int )hash_lkup_2_global_mask_high_register.base_address, ( unsigned int )hash_lkup_2_global_mask_low_register.base_address );

    /* save mac table 2 configuration - Runner B ( MAC lookup for upstream ) */
    RUNNER_REGS_1_CFG_LKUP2_CFG_READ ( hash_lkup_2_cfg_register );
    RUNNER_REGS_1_CFG_LKUP2_CAM_CFG_READ ( hash_lkup_2_cam_cfg_register );

    fprintf ( sim_config, "set mac2 B %x %d %d %d", ( unsigned int )( hash_lkup_2_cfg_register.base_address << 3 ), ( int )32 * ( 1 << hash_lkup_2_cfg_register.table_size ),
                                                    ( int )( 1 << hash_lkup_2_cfg_register.max_hop ), ( int )hash_lkup_2_cfg_register.hash_type);

    if ( hash_lkup_2_cam_cfg_register.cam_en )
        fprintf ( sim_config, " %x\n", ( unsigned int )hash_lkup_2_cam_cfg_register.base_address << 3 );
    else
        fprintf ( sim_config, " \n" );

    RUNNER_REGS_1_CFG_LKUP_GLBL_MASK2_H_READ ( hash_lkup_2_global_mask_high_register );
    RUNNER_REGS_1_CFG_LKUP_GLBL_MASK2_L_READ ( hash_lkup_2_global_mask_low_register );

    fprintf ( sim_config, "set global_mask_2 B %08x %08x\n", ( unsigned int )hash_lkup_2_global_mask_high_register.base_address, ( unsigned int )hash_lkup_2_global_mask_low_register.base_address );

    /* save mac table 3 configuration - Runner A ( ingress classification ) */
    RUNNER_REGS_0_CFG_LKUP3_CFG_READ ( hash_lkup_3_cfg_register );
    RUNNER_REGS_0_CFG_LKUP3_CAM_CFG_READ ( hash_lkup_3_cam_cfg_register );

    fprintf ( sim_config, "set mac3 A %x %d %d %d", ( unsigned int )( hash_lkup_3_cfg_register.base_address << 3 ), ( int )32 * ( 1 << hash_lkup_3_cfg_register.table_size ),
                                                    ( int )( 1 << hash_lkup_3_cfg_register.max_hop ), ( int )hash_lkup_3_cfg_register.hash_type );

    if ( hash_lkup_3_cam_cfg_register.cam_en )
        fprintf ( sim_config, " %x\n", ( unsigned int )( hash_lkup_3_cam_cfg_register.base_address << 3 ) );
    else
        fprintf ( sim_config, " \n" );

    RUNNER_REGS_0_CFG_LKUP_GLBL_MASK3_H_READ ( hash_lkup_3_global_mask_high_register );
    RUNNER_REGS_0_CFG_LKUP_GLBL_MASK3_L_READ ( hash_lkup_3_global_mask_low_register );

    fprintf ( sim_config, "set global_mask_3 A %08x %08x\n", ( unsigned int )hash_lkup_3_global_mask_high_register.base_address, ( unsigned int )hash_lkup_3_global_mask_low_register.base_address );


    /* save mac table 3 configuration - Runner B ( ingress classification ) */
    RUNNER_REGS_1_CFG_LKUP3_CFG_READ ( hash_lkup_3_cfg_register );
    RUNNER_REGS_1_CFG_LKUP3_CAM_CFG_READ ( hash_lkup_3_cam_cfg_register );

    fprintf ( sim_config, "set mac3 B %x %d %d %d", ( unsigned int )( hash_lkup_3_cfg_register.base_address << 3 ), ( int )32 * ( 1 << hash_lkup_3_cfg_register.table_size ),
                                                    ( int )( 1 << hash_lkup_3_cfg_register.max_hop ), ( int )hash_lkup_3_cfg_register.hash_type );

    if ( hash_lkup_3_cam_cfg_register.cam_en )
        fprintf ( sim_config, " %x\n", ( unsigned int )( hash_lkup_3_cam_cfg_register.base_address << 3 ) );
    else
        fprintf ( sim_config, " \n" );

    RUNNER_REGS_1_CFG_LKUP_GLBL_MASK3_H_READ ( hash_lkup_3_global_mask_high_register );
    RUNNER_REGS_1_CFG_LKUP_GLBL_MASK3_L_READ ( hash_lkup_3_global_mask_low_register );

    fprintf ( sim_config, "set global_mask_3 B %08x %08x\n", ( unsigned int )hash_lkup_3_global_mask_high_register.base_address, ( unsigned int )hash_lkup_3_global_mask_low_register.base_address );


    /* save scheduller configuration */
    RUNNER_REGS_0_CFG_MAIN_SCH_CFG_READ ( scheduler_config_register );

    fprintf ( sim_config, "set scheduler_cfg A CLASS_%c group_0=%s group_1=%s group_2=%s group_3=%s\n",
                          ( scheduler_config_register & 0x10 ) ? 'A' : ( ( scheduler_config_register & 0x20 ) ? 'B' : 'C' ) ,
                          ( scheduler_config_register & 0x01 ) ? "RR" : "SP",
                          ( scheduler_config_register & 0x02 ) ? "RR" : "SP",
                          ( scheduler_config_register & 0x04 ) ? "RR" : "SP",
                          ( scheduler_config_register & 0x08 ) ? "RR" : "SP" );

    RUNNER_REGS_1_CFG_MAIN_SCH_CFG_READ ( scheduler_config_register );

    fprintf ( sim_config, "set scheduler_cfg B CLASS_%c group_0=%s group_1=%s group_2=%s group_3=%s\n",
                          ( scheduler_config_register & 0x10 ) ? 'A' : ( ( scheduler_config_register & 0x20 ) ? 'B' : 'C' ) ,
                          ( scheduler_config_register & 0x01 ) ? "RR" : "SP",
                          ( scheduler_config_register & 0x02 ) ? "RR" : "SP",
                          ( scheduler_config_register & 0x04 ) ? "RR" : "SP",
                          ( scheduler_config_register & 0x08 ) ? "RR" : "SP" );

    RUNNER_REGS_0_CFG_PICO_SCH_CFG_READ ( scheduler_config_register );

    fprintf ( sim_config, "set scheduler_cfg C CLASS_%c group_0=%s group_1=%s group_2=SP group_3=SP\n",
                          ( scheduler_config_register & 0x10 ) ? 'A' : ( ( scheduler_config_register & 0x20 ) ? 'B' : 'C' ) ,
                          ( scheduler_config_register & 0x01 ) ? "RR" : "SP",
                          ( scheduler_config_register & 0x02 ) ? "RR" : "SP" );

    RUNNER_REGS_1_CFG_PICO_SCH_CFG_READ ( scheduler_config_register );

    fprintf ( sim_config, "set scheduler_cfg D CLASS_%c group_0=%s group_1=%s group_2=SP group_3=SP\n",
                          ( scheduler_config_register & 0x10 ) ? 'A' : ( ( scheduler_config_register & 0x20 ) ? 'B' : 'C' ) ,
                          ( scheduler_config_register & 0x01 ) ? "RR" : "SP",
                          ( scheduler_config_register & 0x02 ) ? "RR" : "SP" );

    fclose ( sim_config );
    return ( BL_LILAC_RDD_OK );
}


/* Tal Meged Debug functions */
BL_LILAC_RDD_ERROR_DTE bl_lilac_rdd_set_flow_classification_tables ( void )
{
#ifdef UNDEF
    RDD_DS_FLOW_CLASSIFICATION_LOOKUP_TABLE_DTS  *ds_flow_classification_lookup_table_ptr;
    RDD_DS_FLOW_CLASSIFICATION_LOOKUP_ENTRY_DTS  *ds_flow_classification_lookup_entry_ptr;
    RDD_US_FLOW_CLASSIFICATION_LOOKUP_TABLE_DTS  *us_flow_classification_lookup_table_ptr;
    RDD_US_FLOW_CLASSIFICATION_LOOKUP_ENTRY_DTS  *us_flow_classification_lookup_entry_ptr;
    uint32_t                                     i;

    ds_flow_classification_lookup_table_ptr = ( RDD_DS_FLOW_CLASSIFICATION_LOOKUP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + DS_FLOW_CLASSIFICATION_LOOKUP_TABLE_ADDRESS - sizeof ( RUNNER_COMMON ) );

    for ( i = 0; i < RDD_DS_FLOW_CLASSIFICATION_LOOKUP_TABLE_SIZE; i++ )
    {
        ds_flow_classification_lookup_entry_ptr = &( ds_flow_classification_lookup_table_ptr->entry[ i ] );

        RDD_DS_FLOW_CLASSIFICATION_LOOKUP_ENTRY_VALID_WRITE ( LILAC_RDD_ON, ds_flow_classification_lookup_entry_ptr );
    }

    us_flow_classification_lookup_table_ptr = ( RDD_US_FLOW_CLASSIFICATION_LOOKUP_TABLE_DTS * )(DEVICE_ADDRESS( RUNNER_COMMON_1_OFFSET ) + US_FLOW_CLASSIFICATION_LOOKUP_TABLE_ADDRESS - sizeof ( RUNNER_COMMON ) );

    for ( i = 0; i < RDD_US_FLOW_CLASSIFICATION_LOOKUP_TABLE_SIZE; i++ )
    {
        us_flow_classification_lookup_entry_ptr = &( us_flow_classification_lookup_table_ptr->entry[ i ] );

        RDD_US_FLOW_CLASSIFICATION_LOOKUP_ENTRY_VALID_WRITE ( LILAC_RDD_ON, us_flow_classification_lookup_entry_ptr );
    }
#endif
    return ( BL_LILAC_RDD_OK );
}


void fw_init_lock ( bdmf_fastlock  *xo_int_lock )
{
    if ( g_lock_state == LILAC_RDD_TRUE )
    {
        printf ( "LOCK APPLIED WHEN INTERRUPTS LOCKED!!!\n" );
    }

    g_lock_state = LILAC_RDD_TRUE;

    return;
}


void fw_init_unlock ( bdmf_fastlock  *xi_int_lock )
{
    if ( g_lock_state == LILAC_RDD_FALSE )
    {
        printf ( "UNLOCK APPLIED WHEN INTERRUPTS UNLOCKED!!!\n" );
    }

    g_lock_state = LILAC_RDD_FALSE;

    return;
}


void fw_init_lock_irq ( bdmf_fastlock  *xo_int_lock,
                        unsigned long  *flags )
{
    fw_init_lock ( xo_int_lock );
}

 
void fw_init_unlock_irq ( bdmf_fastlock  *xi_int_lock, unsigned long flags )
{
    fw_init_unlock ( xi_int_lock );
}

int _segment_file_init(const char *file_name, const char *mode, uint8_t *segment_mem, int segment_size)
{
    FILE *segment_file;

    segment_file = fopen(file_name, mode);
    if (!segment_file)
    {
        printf("Error: Can't open %s\n", file_name);
        return -1;
    }

    fwrite(segment_mem, sizeof(uint8_t), segment_size, segment_file);

    fclose(segment_file);
    return 0;
}

int segment_file_init(const char *file_name, const char *mode, int segment, int segment_size)
{
    return _segment_file_init(file_name, mode, (uint8_t *)DEVICE_ADDRESS(segment), segment_size);
}
#endif

#if defined(DSL_63138) || defined(DSL_63148)
BL_LILAC_RDD_ERROR_DTE rdd_unknown_sa_mac_cmd_config ( BL_LILAC_RDD_BRIDGE_PORT_DTE          xi_bridge_port,
                                                       BL_LILAC_RDD_UNKNOWN_MAC_COMMAND_DTE  xi_slf_cmd )
{
    return ( BL_LILAC_RDD_OK );
}

BL_LILAC_RDD_ERROR_DTE rdd_sa_mac_lookup_config ( BL_LILAC_RDD_BRIDGE_PORT_DTE  xi_bridge_port,
                                                  BL_LILAC_RDD_MAC_LOOKUP_DTE   xi_src_mac_lookup_mode )
{
    return ( BL_LILAC_RDD_OK );
}

BL_LILAC_RDD_ERROR_DTE rdd_1588_mode_config ( BL_LILAC_RDD_1588_MODE_DTE  xi_1588_mode )
{
    return ( BL_LILAC_RDD_OK );
}

BL_LILAC_RDD_ERROR_DTE rdd_unknown_da_mac_cmd_config ( BL_LILAC_RDD_BRIDGE_PORT_DTE          xi_bridge_port,
                                                       BL_LILAC_RDD_UNKNOWN_MAC_COMMAND_DTE  xi_dlf_cmd )
{
    return ( BL_LILAC_RDD_OK );
}

BL_LILAC_RDD_ERROR_DTE rdd_da_mac_lookup_config ( BL_LILAC_RDD_BRIDGE_PORT_DTE  xi_bridge_port,
                                                  BL_LILAC_RDD_MAC_LOOKUP_DTE   xi_dst_mac_lookup_mode )
{
    return ( BL_LILAC_RDD_OK );
}

/*The reserve FFI table is a byte lookup table used by Runner FW that returns the bit position of the
 *highest '1' of the given byte key.*/
void rdd_init_reverse_ffi_table ( void )
{
  int ii;
  RDD_REVERSE_FFI_TABLE_DTS *reverseFFItable=RDD_REVERSE_FFI_TABLE_PTR();

  /*Assumption is that this table has 256 entries. Otherwise precondition for below algo fails.*/
  reverseFFItable->entry[0].reserved_fw_only=8;
  
  for (ii=1; ii<RDD_REVERSE_FFI_TABLE_SIZE; ++ii)
  {
    int exp=8;
    
    /*This loop finds the bit position of the highest '1' in ii.*/
    while ((1<<exp)>ii)
    {
      --exp;
    }
    
    reverseFFItable->entry[ii].reserved_fw_only=(uint8_t)exp;
  }  
}

BL_LILAC_RDD_ERROR_DTE rdd_ipv4_host_address_table_set(uint32_t xi_table_index, 
                                                       bdmf_ipv4 xi_ipv4_host_addr,
                                                       uint16_t xi_ref_count)
{
    RDD_IPV4_HOST_ADDRESS_TABLE_DTS *host_table = RDD_IPV4_HOST_ADDRESS_TABLE_PTR();

    if (xi_table_index >= RDD_IPV4_HOST_ADDRESS_TABLE_SIZE)
    {
        return BL_LILAC_RDD_ERROR_IPHOST_TABLE_INDEX_INVALID;
    }

    MWRITE_32( host_table->entry + xi_table_index, xi_ipv4_host_addr);
    g_ipv4_host_ref_count_table[xi_table_index] = xi_ref_count;

    return BL_LILAC_RDD_OK;
}

BL_LILAC_RDD_ERROR_DTE rdd_ipv4_host_address_table_get(uint32_t xi_table_index, 
                                                       bdmf_ipv4 *xo_ipv4_host_addr,
                                                       uint16_t *xo_ref_count)
{
    RDD_IPV4_HOST_ADDRESS_TABLE_DTS *host_table = RDD_IPV4_HOST_ADDRESS_TABLE_PTR();

    if (xi_table_index >= RDD_IPV4_HOST_ADDRESS_TABLE_SIZE)
    {
        return BL_LILAC_RDD_ERROR_IPHOST_TABLE_INDEX_INVALID;
    }

    /*Retrieve host address from RDD table*/
    MREAD_32( host_table->entry + xi_table_index, *xo_ipv4_host_addr);
    /*Retrieve reference count from local table*/
    *xo_ref_count = g_ipv4_host_ref_count_table[xi_table_index];

    return BL_LILAC_RDD_OK;
}
 
BL_LILAC_RDD_ERROR_DTE rdd_ipv6_host_address_table_set(uint32_t xi_table_index, 
                                                       const bdmf_ipv6_t *xi_ipv6_host_addr,
                                                       uint16_t xi_ref_count)
{
    RDD_IPV6_HOST_ADDRESS_CRC_TABLE_DTS *host_table = RDD_IPV6_HOST_ADDRESS_CRC_TABLE_PTR();
    uint32_t ipv6_crc, crc_init_value;

    if (xi_table_index >= RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE)
    {
        return BL_LILAC_RDD_ERROR_IPHOST_TABLE_INDEX_INVALID;
    }

    /*Reduce IPV6 address to a 32-bit value using CRC. This reduced value is what RDP FW will be using for lookup.*/
    crc_init_value = get_crc_init_value ( RDD_CRC_TYPE_32 );
    ipv6_crc = crcbitbybit ( (uint8_t *)xi_ipv6_host_addr->data, 16, 0, crc_init_value, RDD_CRC_TYPE_32 );

    /*Store ipv6 address in a local table so we can return in the get accessor*/
    g_ipv6_host_table[xi_table_index].ipv6_address = *xi_ipv6_host_addr;
    g_ipv6_host_table[xi_table_index].ref_count = xi_ref_count;

    /*Store the CRC in the RDP FW table*/
    MWRITE_32( host_table->entry + xi_table_index, ipv6_crc);

    return BL_LILAC_RDD_OK;
}

BL_LILAC_RDD_ERROR_DTE rdd_ipv6_host_address_table_get(uint32_t xi_table_index, 
                                                       bdmf_ipv6_t *xo_ipv6_host_addr,
                                                       uint16_t *xo_ref_count)
{
    if (xi_table_index >= RDD_IPV6_HOST_ADDRESS_CRC_TABLE_SIZE)
    {
        return BL_LILAC_RDD_ERROR_IPHOST_TABLE_INDEX_INVALID;
    }

    /*Look up address in local table. The full IP address is not stored in an RDP table, only the CRC is.*/
    *xo_ipv6_host_addr = g_ipv6_host_table[xi_table_index].ipv6_address;
    *xo_ref_count = g_ipv6_host_table[xi_table_index].ref_count;

    return BL_LILAC_RDD_OK;
}
#endif /* DSL */

BL_LILAC_RDD_ERROR_DTE rdd_fw_mac_da_filter_table_set(uint32_t xi_mac_table_index, 
                                                      uint8_t *xi_mac_address)
{
    uint8_t * p_runner_table_ds;
    uint8_t * p_runner_table_us;
    uint8_t * p_entry_count_ds;
    uint8_t * p_entry_count_us;
    /* entry_size should be 8 (2 bytes padding plus 6 bytes of mac addr) */
    uint8_t   entry_size = (DS_FW_MAC_ADDRS_BYTE_SIZE / RDD_DS_FW_MAC_ADDRS_SIZE);
    uint8_t   new_mac_is_valid = 0;
    uint8_t   entry_was_valid  = 0;

    if (xi_mac_table_index >= RDD_DS_FW_MAC_ADDRS_SIZE)
    {
        return BL_LILAC_RDD_ERROR_HOST_MAC_TABLE_INDEX_INVALID;
    }

    p_runner_table_ds = (uint8_t *) ((DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FW_MAC_ADDRS_ADDRESS) + (xi_mac_table_index * entry_size));
    p_runner_table_us = (uint8_t *) ((DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FW_MAC_ADDRS_ADDRESS) + (xi_mac_table_index * entry_size));

    p_runner_table_ds[0] = 0;
    p_runner_table_us[0] = 0;
    p_runner_table_ds[1] = 0;
    p_runner_table_us[1] = 0;

    entry_was_valid  |= p_runner_table_ds[2];
    new_mac_is_valid |= xi_mac_address[0];
    p_runner_table_ds[2] = xi_mac_address[0];
    p_runner_table_us[2] = xi_mac_address[0];

    entry_was_valid  |= p_runner_table_ds[3];
    new_mac_is_valid |= xi_mac_address[1];
    p_runner_table_ds[3] = xi_mac_address[1];
    p_runner_table_us[3] = xi_mac_address[1];

    entry_was_valid  |= p_runner_table_ds[4];
    new_mac_is_valid |= xi_mac_address[2];
    p_runner_table_ds[4] = xi_mac_address[2];
    p_runner_table_us[4] = xi_mac_address[2];

    entry_was_valid  |= p_runner_table_ds[5];
    new_mac_is_valid |= xi_mac_address[3];
    p_runner_table_ds[5] = xi_mac_address[3];
    p_runner_table_us[5] = xi_mac_address[3];

    entry_was_valid  |= p_runner_table_ds[6];
    new_mac_is_valid |= xi_mac_address[4];
    p_runner_table_ds[6] = xi_mac_address[4];
    p_runner_table_us[6] = xi_mac_address[4];

    entry_was_valid  |= p_runner_table_ds[7];
    new_mac_is_valid |= xi_mac_address[5];
    p_runner_table_ds[7] = xi_mac_address[5];
    p_runner_table_us[7] = xi_mac_address[5];

    p_entry_count_ds = (uint8_t*) (DEVICE_ADDRESS( RUNNER_PRIVATE_0_OFFSET ) + DS_FW_MAC_ADDRS_COUNT_ADDRESS);
    p_entry_count_us = (uint8_t*) (DEVICE_ADDRESS( RUNNER_PRIVATE_1_OFFSET ) + US_FW_MAC_ADDRS_COUNT_ADDRESS);

    // Update the entry count based on changes made
    if (entry_was_valid)
    {
        if (!new_mac_is_valid)
        {
            /* Deleted an entry */
            (*p_entry_count_ds)--;
            (*p_entry_count_us)--;
        }
        /* ELSE: Update... no change in count */
    }
    else
    {
        if (new_mac_is_valid)
        {
            /* Add an entry */
            (*p_entry_count_ds)++;
            (*p_entry_count_us)++;
        }
    }

    return BL_LILAC_RDD_OK;
}

