
DECLARE_FULL_REG_VAR ( bb_fpm_id_dest )
DECLARE_FULL_REG_VAR ( bb_fpm_mcast_inc )
DECLARE_FULL_REG_VAR ( dispatcher_credit )
DECLARE_FULL_REG_VAR ( used_credit )
DECLARE_FULL_REG_VAR ( mirroring_dst_q_vport )
DECLARE_QUAD_REG_VAR ( mirror_pd )

:tx_mirroring
    // check for dispatcher credit
    // in A0 - drop mirrored packet if no credit is available. 
    // in B0 - move this code section send before sending PD to dispatcher, and schedule self wakeup
    // increment MC counter of FPM
    ld32    dispatcher_credit  ( TX_MIRRORING_DISPATCHER_CREDIT_TABLE_ADDRESS + 4 )
    ld16    used_credit  ( TX_MIRRORING_DISPATCHER_CREDIT_TABLE_ADDRESS + 8 )
    mov     bb_fpm_id_dest  BB_ID_FPM  clear
    MARK_JUMP_AS_FUNCTION_RETURN()
    jmp_cmp return_address  dispatcher_credit == used_credit  ds0
    
    alu     used_credit  +=  1
    alu     used_credit  used_credit AND~ h.f0  <<8
    st16    used_credit  ( TX_MIRRORING_DISPATCHER_CREDIT_TABLE_ADDRESS + 8 )
    extract bb_fpm_mcast_inc  packet_descriptor_3  BBH_TX_DESCRIPTOR_BN0_FIRST_F_OFFSET  FPM_BBMSG_MCAST_BUFFER_NUM_F_WIDTH
    insert  bb_fpm_mcast_inc->FPM_BBMSG_MCAST_INCREMENT_CTR  R1
    insert  bb_fpm_mcast_inc->FPM_BBMSG_MCAST_MCAST_VALUE  R1

    mov     mirror_pd_2  0  clear
    jmp_set :tx_mirroring_aggregated  packet_descriptor_3  BBH_TX_DESCRIPTOR_AGG_PD_F_OFFSET  ds2  take_branch  
    bbmsg   BBMSG_TYPE_FPM_BUFFER_MCAST_INCREMENT  bb_fpm_id_dest  bb_fpm_mcast_inc  32bit
    ld16    mirroring_dst_q_vport  TX_MIRRORING_CONFIGURATION_ADDRESS
    
    // Set LAN Bit and set VPORT in PD 
    insert  mirror_pd_2->PROCESSING_TX_DESCRIPTOR_SOURCE_PORT  mirroring_dst_q_vport->MIRRORING_DESCRIPTOR_DST_VPORT source_width
    insert  mirror_pd_2->PROCESSING_TX_DESCRIPTOR_LAN  R1
    
    // Set HN, coherent ,1588 bits and Insert first level dst queue
    extract mirror_pd_1  packet_descriptor_1  BBH_TX_DESCRIPTOR_PACKET_LENGTH_F_OFFSET  (BBH_TX_DESCRIPTOR_PACKET_LENGTH_F_WIDTH + BBH_TX_DESCRIPTOR_BN_NUM_F_WIDTH + 1)
    jmp     :tx_mirroring_queue_update_done
    extract mirror_pd_0  packet_descriptor_1  BBH_TX_DESCRIPTOR_HN_F_OFFSET  ( BBH_TX_DESCRIPTOR_HN_F_WIDTH + PROCESSING_TX_DESCRIPTOR_COHERENT_F_WIDTH + PROCESSING_TX_DESCRIPTOR_FLAG_1588_F_WIDTH )
    insert  mirror_pd_0->PROCESSING_TX_DESCRIPTOR_FIRST_LEVEL_Q  mirroring_dst_q_vport->MIRRORING_DESCRIPTOR_DST_QUEUE
    
:tx_mirroring_aggregated
    
    insert  mirror_pd_2->AGGREGATED_PD_DESCRIPTOR_MAC_FLOW_0  mirroring_dst_q_vport->MIRRORING_DESCRIPTOR_DST_VPORT source_width
    insert  mirror_pd_2->AGGREGATED_PD_DESCRIPTOR_MAC_FLOW_1  mirroring_dst_q_vport->MIRRORING_DESCRIPTOR_DST_VPORT source_width
    alu     mirror_pd_0  packet_descriptor_0 + R0
    extract mirror_pd_1  mirroring_dst_q_vport->AGGREGATED_PD_DESCRIPTOR_SECOND_LEVEL_QUEUE_0  
    
    // Using the aggregated PD structure to set MAC flow 2 and MAC flow 3 in PD
    alu     mirror_pd_2  +=  mirror_pd_2 <<16

:tx_mirroring_queue_update_done
#if defined(DS_CORE) 
    // If multicast non first replication in a non aggregated packet
    // MC counter for header FPM should be increased as well
    // HN mask should be 0x1F
    nop
    jmp_cmp :tx_mirroring_inc_header_fpm_mc_count  packet_descriptor_0 !AND (1 << (PROCESSING_TX_DESCRIPTOR_HN_F_OFFSET + 1) - 1)  ds0 
#endif

DECLARE_FULL_REG_VAR ( bb_fpm_req_data )
DECLARE_FULL_REG_VAR ( min_fpm_pool_size )

// Allocating a dummy buffer and busty waiting until allocation to sync 
// FPM's MC counter update before sending mirrored packet to BBH-TX
:tx_mirroring_header_fpm_update_done
  
    st32    R0  ( MIRRORING_SCRATCH_ADDRESS + 4 )
    mov     min_fpm_pool_size  FPM_POOL_ID_ONE_BUFFER  clear
    mov     bb_fpm_req_data  (MIRRORING_SCRATCH_ADDRESS >> 3)  clear
    insert  bb_fpm_req_data->FPM_BBMSG_ALLOC_POOL_NUM  min_fpm_pool_size
    bbmsg   BBMSG_TYPE_FPM_BUFFER_ALLOC  bb_fpm_id_dest  bb_fpm_req_data  32bit
    mov     dummy_fpm_reply  d.0  clear  

DECLARE_FULL_REG_VAR ( dummy_fpm_reply )
DECLARE_FULL_REG_VAR ( mirror_disp_bb_id )
DECLARE_FULL_REG_VAR ( bb_fpm_free_data )

//  TODO:  A0 workaround - change in B0/ 6836 when FPM mcast replies

:tx_mirroring_dummy_fpm_busy_waiting  

    jmpz    :tx_mirroring_dummy_fpm_busy_waiting  dummy_fpm_reply  ds1
    ld32    dummy_fpm_reply  ( MIRRORING_SCRATCH_ADDRESS + 4 )

    alu     mirror_pd_3  packet_descriptor_3 + R0
    insert  mirror_pd_3  R0  FPM_BBMSG_REPLY_BUFFER_NUM_F_WIDTH  FPM_BBMSG_ALLOC_POOL_NUM_F_WIDTH
    jmp_clr :tx_mirroring_dummy_fpm_free_done  dummy_fpm_reply  FPM_BBMSG_REPLY_VALID_F_OFFSET
        
    extract bb_fpm_free_data  dummy_fpm_reply->FPM_BBMSG_REPLY_BUFFER_NUM  
    bbmsg   BBMSG_TYPE_FPM_BUFFER_FREE  bb_fpm_id_dest  bb_fpm_free_data  32bit

:tx_mirroring_dummy_fpm_free_done
// TODO : ifdef should be omitted when VIQ for mirroring is changed

    mov     mirror_disp_bb_id  (BB_ID_DISPATCHER_REORDER + (DISP_REOR_VIQ_TX_MIRRORING << 6))  clear
    bbmsg   BBMSG_TYPE_RUNNER_DISPATCHER_PD_WRITE  mirror_disp_bb_id  mirror_pd_0  mirror_pd_2

MARK_JUMP_AS_FUNCTION_RETURN()
    jmp     return_address  ds0

:tx_mirroring_inc_header_fpm_mc_count
    // Replace body's BN with header's BN in mcast increment message
    jmp     :tx_mirroring_header_fpm_update_done  ds2
    insert  bb_fpm_mcast_inc->FPM_BBMSG_MCAST_BUFFER_NUM  packet_descriptor_2->BBH_TX_DESCRIPTOR_BN0_FIRST
    bbmsg   BBMSG_TYPE_FPM_BUFFER_MCAST_INCREMENT  bb_fpm_id_dest  bb_fpm_mcast_inc  32bit
