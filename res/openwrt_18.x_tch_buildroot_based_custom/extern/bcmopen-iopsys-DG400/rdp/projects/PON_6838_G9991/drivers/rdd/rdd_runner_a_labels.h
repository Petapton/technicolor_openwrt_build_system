#ifndef RUNNER_A_CODE_ADDRESSES
#define RUNNER_A_CODE_ADDRESSES

#define runner_a_start_task_initialization_task		(0x14)
#define runner_a_initialization_task		(0x14)
#define runner_a_start_task_timer_scheduler_set		(0x3CC0)
#define runner_a_timer_scheduler_set		(0x3CC0)
#define runner_a_start_task_cpu_rx_wakeup_request		(0x3048)
#define runner_a_cpu_rx_wakeup_request		(0x3048)
#define runner_a_start_task_downstream_multicast_wakeup_request		(0x2970)
#define runner_a_downstream_multicast_wakeup_request		(0x2970)
#define runner_a_start_task_cpu_tx_wakeup_request		(0x36E8)
#define runner_a_cpu_tx_wakeup_request		(0x36E8)
#define runner_a_start_task_policer_budget_allocator_1st_wakeup_request		(0x3D88)
#define runner_a_policer_budget_allocator_1st_wakeup_request		(0x3D88)
#define runner_a_start_task_wan_direct_wakeup_request		(0x2A4)
#define runner_a_wan_direct_wakeup_request		(0x2A4)
#define runner_a_start_task_wan_cpu_wakeup_request		(0x5E8)
#define runner_a_wan_cpu_wakeup_request		(0x5E8)
#define runner_a_start_task_wan_normal_wakeup_request		(0x60C)
#define runner_a_wan_normal_wakeup_request		(0x60C)
#define runner_a_start_task_debug_routine		(0x1BC)
#define runner_a_debug_routine		(0x1BC)
#define runner_a_start_task_G9991_fragment_wakeup_request		(0x409C)
#define runner_a_G9991_fragment_wakeup_request		(0x409C)
#define runner_a_ingress_classification_key_src_ip		(0x1560)
#define runner_a_ingress_classification_key_dst_ip		(0x15AC)
#define runner_a_ingress_classification_key_ipv6_flow_label		(0x15F8)
#define runner_a_ingress_classification_key_generic_rule_1		(0x1620)
#define runner_a_ingress_classification_key_generic_rule_2		(0x1628)
#define runner_a_ingress_classification_key_outer_tpid		(0x1694)
#define runner_a_ingress_classification_key_inner_tpid		(0x16A0)
#define runner_a_ingress_classification_key_src_port		(0x16BC)
#define runner_a_ingress_classification_key_dst_port		(0x16DC)
#define runner_a_ingress_classification_key_outer_vlan		(0x16FC)
#define runner_a_ingress_classification_key_inner_vlan		(0x1714)
#define runner_a_ingress_classification_key_dst_mac		(0x1730)
#define runner_a_ingress_classification_key_src_mac		(0x1738)
#define runner_a_ingress_classification_key_ether_type		(0x1760)
#define runner_a_ingress_classification_key_ip_protocol		(0x1774)
#define runner_a_ingress_classification_key_dscp		(0x1798)
#define runner_a_ingress_classification_key_ssid		(0x17B4)
#define runner_a_ingress_classification_key_ingress_port		(0x17B8)
#define runner_a_ingress_classification_key_outer_pbits		(0x17C8)
#define runner_a_ingress_classification_key_inner_pbits		(0x17E0)
#define runner_a_ingress_classification_key_number_of_vlans		(0x17FC)
#define runner_a_ingress_classification_key_layer3_protocol		(0x180C)
#define runner_a_vlan_command_transparent		(0x1A0C)
#define runner_a_vlan_command_add_outer_tag		(0x1A30)
#define runner_a_vlan_command_add_always		(0x1A90)
#define runner_a_vlan_command_add_3rd_tag		(0x1AF8)
#define runner_a_vlan_command_add_two_tags		(0x1B58)
#define runner_a_vlan_command_add_outer_tag_replace_inner_tag		(0x1BC8)
#define runner_a_vlan_command_replace_outer_tag		(0x1C34)
#define runner_a_vlan_command_replace_two_tags		(0x1C64)
#define runner_a_vlan_command_remove_tag		(0x1CA0)
#define runner_a_vlan_command_remove_tag_dont_save		(0x1CFC)
#define runner_a_vlan_command_remove_two_tags		(0x1D4C)
#define runner_a_vlan_command_remove_outer_tag_replace_inner_tag		(0x1DA0)
#define runner_a_vlan_command_remove_outer_tag_replace_inner_tag_copy		(0x1E00)
#define runner_a_vlan_command_remove_outer_tag_copy		(0x1E60)
#define runner_a_vlan_command_replace_outer_tag_replace_inner_tag		(0x1EC4)
#define runner_a_pbits_command_transparent		(0x1F00)
#define runner_a_pbits_command_outer_configured		(0x1F10)
#define runner_a_pbits_command_inner_configured		(0x1F2C)
#define runner_a_pbits_command_dscp_copy		(0x1F48)
#define runner_a_pbits_command_copy_inner_to_outer		(0x1F94)
#define runner_a_pbits_command_increment_offset_copy_inner_to_outer		(0x1FBC)
#define runner_a_pbits_command_remap		(0x1FEC)
#define runner_a_pbits_command_decrement_offset_remap		(0x201C)
#define runner_a_pbits_command_remap_outer_by_inner		(0x2050)
#define runner_a_pbits_command_configured_two_tags		(0x2090)
#define runner_a_pbits_command_dscp_copy_two_tags		(0x20C4)
#define runner_a_global_register_update_r0		(0x3C80)
#define runner_a_global_register_update_r1		(0x3C88)
#define runner_a_global_register_update_r2		(0x3C90)
#define runner_a_global_register_update_r3		(0x3C98)
#define runner_a_global_register_update_r4		(0x3CA0)
#define runner_a_global_register_update_r5		(0x3CA8)
#define runner_a_global_register_update_r6		(0x3CB0)
#define runner_a_global_register_update_r7		(0x3CB8)
#define runner_a_cpu_rx_meter_budget_allocate		(0x3D3C)

#endif
