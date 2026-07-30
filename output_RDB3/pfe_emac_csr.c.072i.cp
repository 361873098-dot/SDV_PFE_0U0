
IPA constant propagation start:
Determining dynamic type for call: pfe_emac_cfg_report_hm_event (instance_id_8, &mtl_ecc_events, 7, mtl_ecc_status_9);
  Starting walk at: pfe_emac_cfg_report_hm_event (instance_id_8, &mtl_ecc_events, 7, mtl_ecc_status_9);
  instance pointer: &mtl_ecc_events  Outer instance pointer: mtl_ecc_events offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_emac_cfg_report_hm_event (instance_id_8, &dpp_fsm_events, 25, dpp_fsm_status_10);
  Starting walk at: pfe_emac_cfg_report_hm_event (instance_id_8, &dpp_fsm_events, 25, dpp_fsm_status_10);
  instance pointer: &dpp_fsm_events  Outer instance pointer: dpp_fsm_events offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = crc32_reversed (addr_2(D), 6);
  Starting walk at: _3 = crc32_reversed (addr_2(D), 6);
  instance pointer: addr_2(D)  Outer instance pointer: addr_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_34 = reg_wait_for_clear (_4, 8, 10);
  Starting walk at: ret_34 = reg_wait_for_clear (_4, 8, 10);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = is_eclk_enabled (base_va_21(D));
Determining dynamic type for call: ret_27 = reg_wait_for_clear (_11, 4, 10);
  Starting walk at: ret_27 = reg_wait_for_clear (_11, 4, 10);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = is_eclk_enabled (base_va_16(D));
Determining dynamic type for call: ret_34 = reg_wait_for_clear (_11, 32, 10);
  Starting walk at: ret_34 = reg_wait_for_clear (_11, 32, 10);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = is_eclk_enabled (base_va_17(D));
Determining dynamic type for call: ret_40 = reg_wait_for_clear (_2, 32, 10);
  Starting walk at: ret_40 = reg_wait_for_clear (_2, 32, 10);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_47 = reg_wait_for_clear (_2, 4, 10);
  Starting walk at: ret_47 = reg_wait_for_clear (_2, 4, 10);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_40 = reg_wait_for_clear (_2, 32, 10);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Dem_SetEventStatus/73:
  Jump functions of caller  autolibc_memset/68:
  Jump functions of caller  oal_time_usleep/67:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/66:
  Jump functions of caller  pfe_hm_report/65:
  Jump functions of caller  oal_time_udelay/64:
  Jump functions of caller  pfe_feature_mgr_is_available/63:
  Jump functions of caller  pfe_emac_cfg_isr/62:
    callsite  pfe_emac_cfg_isr/62 -> pfe_emac_cfg_report_hm_event/61 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: &dpp_fsm_events
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 25
         value: 0x19, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_cfg_isr/62 -> pfe_emac_cfg_report_hm_event/61 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: &mtl_ecc_events
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 7
         value: 0x7, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_cfg_isr/62 -> pfe_emac_cfg_get_index/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_cfg_report_hm_event/61:
    callsite  pfe_emac_cfg_report_hm_event/61 -> pfe_emac_get_emac_err_src_index/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_cfg_get_rx_cnt/60:
  Jump functions of caller  pfe_emac_cfg_get_tx_cnt/59:
  Jump functions of caller  pfe_emac_cfg_pps0_set_pulse_width/58:
  Jump functions of caller  pfe_emac_cfg_pps0_set_period/57:
  Jump functions of caller  pfe_emac_cfg_pps0_set_target_time/56:
  Jump functions of caller  pfe_emac_cfg_pps_cmd/55:
  Jump functions of caller  pfe_emac_cfg_pps0_configure/54:
  Jump functions of caller  pfe_emac_cfg_mdio_write45/53:
  Jump functions of caller  pfe_emac_cfg_mdio_write22/52:
  Jump functions of caller  pfe_emac_cfg_mdio_read45/51:
  Jump functions of caller  pfe_emac_cfg_mdio_read22/50:
  Jump functions of caller  pfe_emac_cfg_set_rx_flow_control/49:
  Jump functions of caller  pfe_emac_cfg_set_tx_flow_control/48:
  Jump functions of caller  pfe_emac_cfg_get_rx_flow_control/47:
  Jump functions of caller  pfe_emac_cfg_get_tx_flow_control/46:
  Jump functions of caller  pfe_emac_cfg_set_enable/45:
  Jump functions of caller  pfe_emac_cfg_set_broadcast/44:
  Jump functions of caller  pfe_emac_cfg_set_allmulti_mode/43:
  Jump functions of caller  pfe_emac_cfg_set_promisc_mode/42:
  Jump functions of caller  pfe_emac_cfg_set_loopback/41:
  Jump functions of caller  pfe_emac_cfg_clear_hash_table/40:
  Jump functions of caller  pfe_emac_cfg_set_hash_group/39:
  Jump functions of caller  pfe_emac_cfg_get_hash/38:
    callsite  pfe_emac_cfg_get_hash/38 -> crc32_reversed/14 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_emac_cfg_read_addr_slot/37:
  Jump functions of caller  pfe_emac_cfg_write_addr_slot/36:
  Jump functions of caller  pfe_emac_cfg_set_max_frame_length/35:
  Jump functions of caller  pfe_emac_cfg_get_link_status/34:
  Jump functions of caller  pfe_emac_cfg_set_speed/33:
  Jump functions of caller  pfe_emac_cfg_set_mii_mode/32:
  Jump functions of caller  pfe_emac_cfg_set_duplex/31:
  Jump functions of caller  pfe_emac_cfg_tx_disable/30:
  Jump functions of caller  pfe_emac_cfg_get_stat_value/29:
  Jump functions of caller  pfe_emac_cfg_get_link_config/28:
  Jump functions of caller  pfe_emac_cfg_adjust_ts_time/27:
    callsite  pfe_emac_cfg_adjust_ts_time/27 -> reg_wait_for_clear/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 8
         value: 0x8, mask: 0x0
         Unknown VR
       param 2: CONST: 10
         value: 0xa, mask: 0x0
         Unknown VR
    callsite  pfe_emac_cfg_adjust_ts_time/27 -> is_eclk_enabled/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_cfg_set_ts_time/26:
    callsite  pfe_emac_cfg_set_ts_time/26 -> reg_wait_for_clear/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 2: CONST: 10
         value: 0xa, mask: 0x0
         Unknown VR
    callsite  pfe_emac_cfg_set_ts_time/26 -> is_eclk_enabled/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_cfg_get_ts_time/25:
  Jump functions of caller  pfe_emac_cfg_adjust_ts_freq/24:
    callsite  pfe_emac_cfg_adjust_ts_freq/24 -> reg_wait_for_clear/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 32
         value: 0x20, mask: 0x0
         Unknown VR
       param 2: CONST: 10
         value: 0xa, mask: 0x0
         Unknown VR
    callsite  pfe_emac_cfg_adjust_ts_freq/24 -> is_eclk_enabled/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_cfg_get_index/23:
  Jump functions of caller  reg_wait_for_clear/22:
  Jump functions of caller  is_eclk_enabled/21:
  Jump functions of caller  pfe_emac_cfg_disable_ts/20:
  Jump functions of caller  pfe_emac_cfg_enable_ts/19:
    callsite  pfe_emac_cfg_enable_ts/19 -> reg_wait_for_clear/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 2: CONST: 10
         value: 0xa, mask: 0x0
         Unknown VR
    callsite  pfe_emac_cfg_enable_ts/19 -> reg_wait_for_clear/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 32
         value: 0x20, mask: 0x0
         Unknown VR
       param 2: CONST: 10
         value: 0xa, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_emac_cfg_init/18:
    callsite  pfe_emac_cfg_init/18 -> pfe_emac_cfg_set_duplex/31 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_cfg_init/18 -> pfe_emac_cfg_set_speed/33 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_cfg_init/18 -> pfe_emac_cfg_clear_registers/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_cfg_pre_init/17:
  Jump functions of caller  pfe_emac_cfg_clear_registers/16:
  Jump functions of caller  pfe_emac_get_emac_err_src_index/15:
  Jump functions of caller  crc32_reversed/14:
    callsite  crc32_reversed/14 -> reverse_bits_32/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  reverse_bits_32/13:

 Propagating constants:

Not considering pfe_emac_cfg_isr for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_rx_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_tx_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_pps0_set_pulse_width for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_pps0_set_period for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_pps0_set_target_time for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_pps_cmd for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_pps0_configure for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_mdio_write45 for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_mdio_write22 for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_mdio_read45 for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_mdio_read22 for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_rx_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_tx_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_rx_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_tx_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_broadcast for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_allmulti_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_promisc_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_loopback for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_clear_hash_table for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_hash_group for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_hash for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_read_addr_slot for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_write_addr_slot for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_max_frame_length for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_link_status for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_speed for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_mii_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_duplex for cloning; -fipa-cp-clone disabled.
Function pfe_emac_cfg_tx_disable/30 is not versionable, reason: not a tree_versionable_function.
Not considering pfe_emac_cfg_get_stat_value for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_link_config for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_adjust_ts_time for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_set_ts_time for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_ts_time for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_adjust_ts_freq for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_get_index for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_disable_ts for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_enable_ts for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_cfg_pre_init for cloning; -fipa-cp-clone disabled.

overall_size: 981, max_new_size: 11001
 - context independent values, size: 7, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 2.000000
 - context independent values, size: 7, time_benefit: 65.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 69, time_benefit: 1.000000
 - context independent values, size: 21, time_benefit: 65.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_emac_cfg_isr/62:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_report_hm_event/61:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &mtl_ecc_events [loc_time: 1, loc_size: 73, prop_time: 0, prop_size: 0]
               &dpp_fsm_events [loc_time: 1, loc_size: 73, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const pfe_hm_evt_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: 7 [loc_time: 65, loc_size: 73, prop_time: 0, prop_size: 0]
               25 [loc_time: 65, loc_size: 73, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x19, mask = 0x1e
         uint8_t [7, 25]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_emac_cfg_get_rx_cnt/60:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_tx_cnt/59:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_pps0_set_pulse_width/58:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_pps0_set_period/57:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_pps0_set_target_time/56:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_pps_cmd/55:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_pps0_configure/54:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_mdio_write45/53:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_mdio_write22/52:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_mdio_read45/51:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_mdio_read22/50:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_rx_flow_control/49:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_tx_flow_control/48:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_rx_flow_control/47:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_tx_flow_control/46:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_enable/45:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_broadcast/44:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_allmulti_mode/43:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_promisc_mode/42:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_loopback/41:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_clear_hash_table/40:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_hash_group/39:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_hash/38:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_read_addr_slot/37:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_write_addr_slot/36:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_max_frame_length/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_link_status/34:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_speed/33:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_mii_mode/32:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_duplex/31:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_tx_disable/30:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_stat_value/29:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_link_config/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_adjust_ts_time/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_set_ts_time/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_ts_time/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_adjust_ts_freq/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_get_index/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: reg_wait_for_clear/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 32 [loc_time: 66, loc_size: 12, prop_time: 0, prop_size: 0]
               4 [loc_time: 66, loc_size: 12, prop_time: 0, prop_size: 0]
               8 [loc_time: 66, loc_size: 12, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x8, mask = 0x2c
         uint32_t [4, 32]
        AGGS VARIABLE
    param [2]: 10 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0xa, mask = 0x0
         uint8_t [10, 10]
        AGGS VARIABLE
  Node: is_eclk_enabled/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_emac_cfg_disable_ts/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_enable_ts/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_init/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_pre_init/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_cfg_clear_registers/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_emac_get_emac_err_src_index/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: crc32_reversed/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 6 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x6, mask = 0x0
         const uint32_t [6, 6]
        AGGS VARIABLE
  Node: reverse_bits_32/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of reg_wait_for_clear/22 for all known contexts.
    replacing param #2 timeout_100us with const 10
 - Creating a specialized node of crc32_reversed/14 for all known contexts.
    replacing param #1 len with const 6
Propagated bits info for function crc32_reversed.constprop/76:
 param 1: value = 0x6, mask = 0x0
Propagated bits info for function reg_wait_for_clear.constprop/75:
 param 1: value = 0x8, mask = 0x2c
 param 2: value = 0xa, mask = 0x0
Propagated bits info for function pfe_emac_cfg_report_hm_event/61:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x19, mask = 0x1e
Propagated bits info for function reg_wait_for_clear/22:
 param 1: value = 0x8, mask = 0x2c
 param 2: value = 0xa, mask = 0x0
Propagated bits info for function crc32_reversed/14:
 param 1: value = 0x6, mask = 0x0

IPA constant propagation end

Reclaiming functions: reg_wait_for_clear/22 crc32_reversed/14
Reclaiming variables:
Clearing address taken flags:
Symbol table:

crc32_reversed.constprop.0/76 (crc32_reversed.constprop) @070a69a0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of crc32_reversed/14
  Availability: local
  Function flags: count:14744043 (estimated locally) local optimize_size
  Called by: pfe_emac_cfg_get_hash/38 (1073741824 (estimated locally),1.00 per call) 
  Calls: reverse_bits_32/13 (14744044 (estimated locally),1.00 per call) 
reg_wait_for_clear.constprop.0/75 (reg_wait_for_clear.constprop) @06eeed20
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of reg_wait_for_clear/22
  Availability: local
  Function flags: count:114863532 (estimated locally) local optimize_size
  Called by: pfe_emac_cfg_enable_ts/19 (267575274 (estimated locally),0.25 per call) pfe_emac_cfg_enable_ts/19 (88299840 (estimated locally),0.08 per call) pfe_emac_cfg_adjust_ts_freq/24 (664351040 (estimated locally),0.62 per call) pfe_emac_cfg_set_ts_time/26 (390349724 (estimated locally),0.36 per call) pfe_emac_cfg_adjust_ts_time/27 (394078092 (estimated locally),0.37 per call) 
  Calls: oal_time_usleep/67 (958878293 (estimated locally),8.35 per call) 
Dem_SetEventStatus/73 (Dem_SetEventStatus) @076deee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_cfg_report_hm_event/61 (39054403 (estimated locally),0.23 per call) 
  Calls: 
hm_src.9858/72 (hm_src) @076f5438
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_emac_cfg_report_hm_event/61 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
*.LC0/71 (*.LC0) @076e8e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: pfe_emac_cfg_report_hm_event/61 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
dpp_fsm_events.9890/70 (dpp_fsm_events) @076e8d80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_emac_cfg_isr/62 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
mtl_ecc_events.9889/69 (mtl_ecc_events) @076e8cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_emac_cfg_isr/62 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
autolibc_memset/68 (autolibc_memset) @076bf620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_cfg_read_addr_slot/37 (445388109 (estimated locally),0.41 per call) 
  Calls: 
oal_time_usleep/67 (oal_time_usleep) @07698380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: reg_wait_for_clear.constprop/75 (958878293 (estimated locally),8.35 per call) pfe_emac_cfg_mdio_write45/53 (1004539164 (estimated locally),14.52 per call) pfe_emac_cfg_mdio_write22/52 (1004539164 (estimated locally),14.52 per call) pfe_emac_cfg_mdio_read45/51 (1004539164 (estimated locally),14.52 per call) pfe_emac_cfg_mdio_read22/50 (1063004405 (estimated locally),15.36 per call) pfe_emac_cfg_set_tx_flow_control/48 (1073741824 (estimated locally),6.69 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/66 (oal_util_raise_dem_for_drv_runtime_err) @076981c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_cfg_set_tx_flow_control/48 (32490139 (estimated locally),0.20 per call) pfe_emac_cfg_adjust_ts_freq/24 (176174061 (estimated locally),0.16 per call) pfe_emac_cfg_enable_ts/19 (441094331 (estimated locally),0.41 per call) pfe_emac_cfg_report_hm_event/61 (56586383 (estimated locally),0.33 per call) pfe_emac_get_emac_err_src_index/15 (214748364 (estimated locally),0.20 per call) 
  Calls: 
pfe_hm_report/65 (pfe_hm_report) @076980e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_cfg_set_tx_flow_control/48 (32490139 (estimated locally),0.20 per call) pfe_emac_cfg_adjust_ts_freq/24 (176174061 (estimated locally),0.16 per call) pfe_emac_cfg_enable_ts/19 (441094331 (estimated locally),0.41 per call) pfe_emac_cfg_report_hm_event/61 (56586383 (estimated locally),0.33 per call) pfe_emac_cfg_report_hm_event/61 (39054403 (estimated locally),0.23 per call) pfe_emac_cfg_report_hm_event/61 (79898534 (estimated locally),0.47 per call) pfe_emac_get_emac_err_src_index/15 (214748364 (estimated locally),0.20 per call) 
  Calls: 
oal_time_udelay/64 (oal_time_udelay) @076882a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_cfg_clear_hash_table/40 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_set_hash_group/39 (524845004 (estimated locally),0.49 per call) pfe_emac_cfg_write_addr_slot/36 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_clear_registers/16 (134217728 (estimated locally),1.00 per call) 
  Calls: 
pfe_feature_mgr_is_available/63 (pfe_feature_mgr_is_available) @07688e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_cfg_init/18 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_isr/62 (pfe_emac_cfg_isr) @076888c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mtl_ecc_events.9889/69 (addr)dpp_fsm_events.9890/70 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_report_hm_event/61 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_report_hm_event/61 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_get_index/23 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_cfg_report_hm_event/61 (pfe_emac_cfg_report_hm_event) @076881c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: *.LC0/71 (read)hm_src.9858/72 (read)
  Referring: 
  Availability: local
  Function flags: count:171473887 (estimated locally) body local optimize_size
  Called by: pfe_emac_cfg_isr/62 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_isr/62 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/66 (56586383 (estimated locally),0.33 per call) pfe_hm_report/65 (56586383 (estimated locally),0.33 per call) Dem_SetEventStatus/73 (39054403 (estimated locally),0.23 per call) pfe_hm_report/65 (39054403 (estimated locally),0.23 per call) pfe_emac_get_emac_err_src_index/15 (79898534 (estimated locally),0.47 per call) pfe_hm_report/65 (79898534 (estimated locally),0.47 per call) 
pfe_emac_cfg_get_rx_cnt/60 (pfe_emac_cfg_get_rx_cnt) @076838c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_get_tx_cnt/59 (pfe_emac_cfg_get_tx_cnt) @07683ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_pps0_set_pulse_width/58 (pfe_emac_cfg_pps0_set_pulse_width) @07683b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_pps0_set_period/57 (pfe_emac_cfg_pps0_set_period) @076837e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_pps0_set_target_time/56 (pfe_emac_cfg_pps0_set_target_time) @07683460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_pps_cmd/55 (pfe_emac_cfg_pps_cmd) @07683000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_pps0_configure/54 (pfe_emac_cfg_pps0_configure) @0767ed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_mdio_write45/53 (pfe_emac_cfg_mdio_write45) @0767e8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:69202660 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_time_usleep/67 (1004539164 (estimated locally),14.52 per call) 
pfe_emac_cfg_mdio_write22/52 (pfe_emac_cfg_mdio_write22) @07677d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:69202660 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_time_usleep/67 (1004539164 (estimated locally),14.52 per call) 
pfe_emac_cfg_mdio_read45/51 (pfe_emac_cfg_mdio_read45) @07677000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:69202660 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_time_usleep/67 (1004539164 (estimated locally),14.52 per call) 
pfe_emac_cfg_mdio_read22/50 (pfe_emac_cfg_mdio_read22) @076742a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:69202660 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_time_usleep/67 (1063004405 (estimated locally),15.36 per call) 
pfe_emac_cfg_set_rx_flow_control/49 (pfe_emac_cfg_set_rx_flow_control) @07670700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_set_tx_flow_control/48 (pfe_emac_cfg_set_tx_flow_control) @076700e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:160524402 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/66 (32490139 (estimated locally),0.20 per call) pfe_hm_report/65 (32490139 (estimated locally),0.20 per call) oal_time_usleep/67 (1073741824 (estimated locally),6.69 per call) 
pfe_emac_cfg_get_rx_flow_control/47 (pfe_emac_cfg_get_rx_flow_control) @07668a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_get_tx_flow_control/46 (pfe_emac_cfg_get_tx_flow_control) @07668620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_set_enable/45 (pfe_emac_cfg_set_enable) @076681c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_set_broadcast/44 (pfe_emac_cfg_set_broadcast) @07664c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_set_allmulti_mode/43 (pfe_emac_cfg_set_allmulti_mode) @07664620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_set_promisc_mode/42 (pfe_emac_cfg_set_promisc_mode) @07664000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_set_loopback/41 (pfe_emac_cfg_set_loopback) @0765dd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_clear_hash_table/40 (pfe_emac_cfg_clear_hash_table) @0765d700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_time_udelay/64 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_cfg_set_hash_group/39 (pfe_emac_cfg_set_hash_group) @0765d2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_time_udelay/64 (524845004 (estimated locally),0.49 per call) 
pfe_emac_cfg_get_hash/38 (pfe_emac_cfg_get_hash) @0765d000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: crc32_reversed.constprop/76 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_cfg_read_addr_slot/37 (pfe_emac_cfg_read_addr_slot) @07652c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memset/68 (445388109 (estimated locally),0.41 per call) 
pfe_emac_cfg_write_addr_slot/36 (pfe_emac_cfg_write_addr_slot) @07652e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_time_udelay/64 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_cfg_set_max_frame_length/35 (pfe_emac_cfg_set_max_frame_length) @07652b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_get_link_status/34 (pfe_emac_cfg_get_link_status) @07652000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_set_speed/33 (pfe_emac_cfg_set_speed) @0764bee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: pfe_emac_cfg_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_mii_mode/32 (pfe_emac_cfg_set_mii_mode) @0764b1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_set_duplex/31 (pfe_emac_cfg_set_duplex) @075e1c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_emac_cfg_init/18 (512926469 (estimated locally),0.48 per call) 
  Calls: 
pfe_emac_cfg_tx_disable/30 (pfe_emac_cfg_tx_disable) @075e1b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: pfe_emac_cfg_disable_ts/20 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_cfg_get_stat_value/29 (pfe_emac_cfg_get_stat_value) @075e17e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_get_link_config/28 (pfe_emac_cfg_get_link_config) @075e1460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_adjust_ts_time/27 (pfe_emac_cfg_adjust_ts_time) @075e10e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: reg_wait_for_clear.constprop/75 (394078092 (estimated locally),0.37 per call) is_eclk_enabled/21 (610207479 (estimated locally),0.57 per call) 
pfe_emac_cfg_set_ts_time/26 (pfe_emac_cfg_set_ts_time) @075dc540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: reg_wait_for_clear.constprop/75 (390349724 (estimated locally),0.36 per call) is_eclk_enabled/21 (610207479 (estimated locally),0.57 per call) 
pfe_emac_cfg_get_ts_time/25 (pfe_emac_cfg_get_ts_time) @075d3e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_adjust_ts_freq/24 (pfe_emac_cfg_adjust_ts_freq) @075d37e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: reg_wait_for_clear.constprop/75 (664351040 (estimated locally),0.62 per call) oal_util_raise_dem_for_drv_runtime_err/66 (176174061 (estimated locally),0.16 per call) pfe_hm_report/65 (176174061 (estimated locally),0.16 per call) is_eclk_enabled/21 (1073741823 (estimated locally),1.00 per call) 
pfe_emac_cfg_get_index/23 (pfe_emac_cfg_get_index) @075cde00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_emac_cfg_isr/62 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
reg_wait_for_clear/22 (reg_wait_for_clear) @075cd620
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: 
is_eclk_enabled/21 (is_eclk_enabled) @075cdd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_emac_cfg_adjust_ts_time/27 (610207479 (estimated locally),0.57 per call) pfe_emac_cfg_set_ts_time/26 (610207479 (estimated locally),0.57 per call) pfe_emac_cfg_adjust_ts_freq/24 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_disable_ts/20 (pfe_emac_cfg_disable_ts) @075cd8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: pfe_emac_cfg_tx_disable/30 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_enable_ts/19 (pfe_emac_cfg_enable_ts) @075cd540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: reg_wait_for_clear.constprop/75 (88299840 (estimated locally),0.08 per call) reg_wait_for_clear.constprop/75 (267575274 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/66 (441094331 (estimated locally),0.41 per call) pfe_hm_report/65 (441094331 (estimated locally),0.41 per call) 
pfe_emac_cfg_init/18 (pfe_emac_cfg_init) @075c0d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_duplex/31 (512926469 (estimated locally),0.48 per call) pfe_emac_cfg_set_speed/33 (1073741824 (estimated locally),1.00 per call) pfe_feature_mgr_is_available/63 (1073741824 (estimated locally),1.00 per call) pfe_feature_mgr_is_available/63 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_clear_registers/16 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_cfg_pre_init/17 (pfe_emac_cfg_pre_init) @0759be00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_clear_registers/16 (pfe_emac_cfg_clear_registers) @0759ba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:134217728 (estimated locally) body local optimize_size
  Called by: pfe_emac_cfg_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_time_udelay/64 (134217728 (estimated locally),1.00 per call) 
pfe_emac_get_emac_err_src_index/15 (pfe_emac_get_emac_err_src_index) @0759b620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_emac_cfg_report_hm_event/61 (79898534 (estimated locally),0.47 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/66 (214748364 (estimated locally),0.20 per call) pfe_hm_report/65 (214748364 (estimated locally),0.20 per call) 
crc32_reversed/14 (crc32_reversed) @0759b2a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:14744043 (estimated locally) body optimize_size
  Called by: 
  Calls: 
reverse_bits_32/13 (reverse_bits_32) @0759b000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:32534378 (estimated locally) body local optimize_size
  Called by: crc32_reversed.constprop/76 (14744044 (estimated locally),1.00 per call) 
  Calls: 

;; Function pfe_emac_cfg_report_hm_event (pfe_emac_cfg_report_hm_event, funcdef_no=59, decl_uid=9856, cgraph_uid=60, symbol_order=61)

Modification phase of node pfe_emac_cfg_report_hm_event/61
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 2 to 0x1e
Setting nonnull for 1
Setting value range of param 2 [7, 25]
pfe_emac_cfg_report_hm_event (uint8_t id, const pfe_hm_evt_t * events, uint8_t events_len, uint32_t flags)
{
  const Dem_EventIdType emac_dem_err_id[3][4];
  uint8_t emac_err_src_index;
  pfe_hm_src_t src;
  uint32_t isr_flags;
  uint8_t index;
  static const pfe_hm_src_t hm_src[3] = {3, 4, 5};
  int _1;
  long unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  const pfe_hm_evt_t * _5;
  <unnamed type> _6;
  <unnamed type> _7;
  int _8;
  short unsigned int _9;

  <bb 2> [local count: 171473887]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG index => 0
  # DEBUG BEGIN_STMT
  # DEBUG isr_flags => flags_15(D)
  # DEBUG BEGIN_STMT
  # DEBUG src => 3
  # DEBUG BEGIN_STMT
  # DEBUG emac_err_src_index => 0
  # DEBUG BEGIN_STMT
  emac_dem_err_id = *.LC0;
  # DEBUG BEGIN_STMT
  if (id_18(D) <= 2)
    goto <bb 3>; [67.00%]
  else
    goto <bb 13>; [33.00%]

  <bb 3> [local count: 114887504]:
  # DEBUG BEGIN_STMT
  _1 = (int) id_18(D);
  src_21 = hm_src[_1];
  # DEBUG src => src_21
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 958878294]:
  # DEBUG BEGIN_STMT
  _2 = isr_flags_11 & 1;
  if (_2 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 5> [local count: 479439147]:
  _3 = (unsigned int) index_10;
  _4 = _3 * 4;
  _5 = events_23(D) + _4;
  _6 = *_5;
  if (_6 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 6> [local count: 239719573]:
  # DEBUG BEGIN_STMT
  switch (_6) <default: <L30> [33.33%], case 30: <L4> [33.33%], case 31 ... 32: <L6> [33.33%], case 33: <L4> [33.33%], case 34 ... 44: <L6> [33.33%]>

  <bb 7> [local count: 79898534]:
<L4>:
  # DEBUG BEGIN_STMT
  pfe_hm_report (src_21, 1, _6, "[%s:%d] ", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac_csr.c", 1882, "");
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 79898534]:
<L6>:
  # DEBUG BEGIN_STMT
  emac_err_src_index_25 = pfe_emac_get_emac_err_src_index (_6);
  # DEBUG emac_err_src_index => emac_err_src_index_25
  # DEBUG BEGIN_STMT
  if (emac_err_src_index_25 != 255)
    goto <bb 9>; [48.88%]
  else
    goto <bb 10>; [51.12%]

  <bb 9> [local count: 39054403]:
  # DEBUG BEGIN_STMT
  _7 = *_5;
  pfe_hm_report (src_21, 2, _7, "[%s:%d] ", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac_csr.c", 1902, "");
  # DEBUG BEGIN_STMT
  _8 = (int) emac_err_src_index_25;
  _9 = emac_dem_err_id[_1][_8];
  Dem_SetEventStatus (_9, 3);

  <bb 10> [local count: 958854324]:
<L30>:
  # DEBUG BEGIN_STMT
  index_29 = index_10 + 1;
  # DEBUG index => index_29
  # DEBUG BEGIN_STMT
  isr_flags_30 = isr_flags_11 >> 1;
  # DEBUG isr_flags => isr_flags_30

  <bb 11> [local count: 1073741824]:
  # index_10 = PHI <0(3), index_29(10)>
  # isr_flags_11 = PHI <flags_15(D)(3), isr_flags_30(10)>
  # DEBUG isr_flags => isr_flags_11
  # DEBUG index => index_10
  # DEBUG BEGIN_STMT
  if (isr_flags_11 != 0)
    goto <bb 12>; [94.50%]
  else
    goto <bb 14>; [5.50%]

  <bb 12> [local count: 1014686026]:
  if (index_10 < events_len_22(D))
    goto <bb 4>; [94.50%]
  else
    goto <bb 14>; [5.50%]

  <bb 13> [local count: 56586383]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Argument out of range", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac_csr.c", 1922, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 14> [local count: 171449915]:
  # DEBUG BEGIN_STMT
  emac_dem_err_id ={v} {CLOBBER};
  return;

}



;; Function reg_wait_for_clear.constprop (reg_wait_for_clear.constprop.0, funcdef_no=64, decl_uid=10276, cgraph_uid=70, symbol_order=75)

Modification phase of node reg_wait_for_clear.constprop/75
Adjusting mask for param 1 to 0x2c
Setting value range of param 1 [4, 32]
reg_wait_for_clear.constprop (const uint32_t * reg_address, uint32_t value)
{
  errno_t result;
  uint8_t timeout_cnt;
  uint32_t regval;
  uint8_t timeout_100us;
  long unsigned int _4;

  <bb 7> [local count: 114863532]:
  # DEBUG timeout_100us => 10

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG result => 62
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG timeout_cnt => 0
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  regval_2 ={v} *reg_address_1(D);
  # DEBUG regval => regval_2
  # DEBUG BEGIN_STMT
  _4 = regval_2 & value_3(D);
  if (_4 == 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  oal_time_usleep (100);
  # DEBUG BEGIN_STMT
  timeout_cnt_6 = timeout_cnt_5 + 1;
  # DEBUG timeout_cnt => timeout_cnt_6

  <bb 5> [local count: 1073741824]:
  # timeout_cnt_5 = PHI <0(2), timeout_cnt_6(4)>
  # DEBUG timeout_cnt => timeout_cnt_5
  # DEBUG BEGIN_STMT
  if (timeout_cnt_5 <= 9)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 114863532]:
  # result_7 = PHI <0(3), 62(5)>
  # DEBUG result => result_7
  # DEBUG BEGIN_STMT
  return result_7;

}



;; Function pfe_emac_cfg_pre_init (pfe_emac_cfg_pre_init, funcdef_no=15, decl_uid=9205, cgraph_uid=16, symbol_order=17)

Modification phase of node pfe_emac_cfg_pre_init/17
pfe_emac_cfg_pre_init (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 3296;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 1;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_enable_ts (pfe_emac_cfg_enable_ts, funcdef_no=17, decl_uid=9218, cgraph_uid=18, symbol_order=19)

Modification phase of node pfe_emac_cfg_enable_ts/19
pfe_emac_cfg_enable_ts (addr_t base_va, bool_t eclk, uint32_t i_clk_hz, uint32_t o_clk_hz)
{
  const uint32_t u32_addend;
  const uint64_t u64_addend;
  const uint8_t sns;
  errno_t ret;
  uint32_t regval;
  uint32_t ss;
  unsigned int _1;
  volatile uint32_t * _2;
  long long unsigned int _3;
  long long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  int _7;
  int _8;
  long unsigned int _9;
  unsigned int _10;
  volatile uint32_t * _11;
  long unsigned int _12;
  long long unsigned int _13;
  long long unsigned int _14;
  unsigned int _15;
  volatile uint32_t * _16;
  long unsigned int _17;
  unsigned int _18;
  volatile uint32_t * _19;
  unsigned int _20;
  volatile uint32_t * _21;
  long unsigned int iftmp.3_23;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ss => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (eclk_25(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.3_23 = PHI <1130243(2), 81667(3)>
  _1 = base_va_26(D) + 2816;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} iftmp.3_23;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (eclk_25(D) == 1)
    goto <bb 10>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  if (o_clk_hz_29(D) == 0)
    goto <bb 7>; [20.96%]
  else
    goto <bb 6>; [79.04%]

  <bb 6> [local count: 560132456]:
  if (i_clk_hz_30(D) == 0)
    goto <bb 7>; [52.23%]
  else
    goto <bb 8>; [47.77%]

  <bb 7> [local count: 441094331]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid frequency value", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac_csr.c", 410, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 267575274]:
  # DEBUG BEGIN_STMT
  ss_31 = 1000000000 / o_clk_hz_29(D);
  # DEBUG ss => ss_31
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = (long long unsigned int) o_clk_hz_29(D);
  _4 = 256000000000 / _3;
  sns_32 = (const uint8_t) _4;
  # DEBUG sns => sns_32
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = ss_31 << 16;
  _6 = _5 & 16711680;
  _7 = (int) sns_32;
  _8 = _7 << 8;
  _9 = (long unsigned int) _8;
  _10 = base_va_26(D) + 2820;
  _11 = (volatile uint32_t *) _10;
  _12 = _6 | _9;
  *_11 ={v} _12;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = _3 << 32;
  _14 = (long long unsigned int) i_clk_hz_30(D);
  u64_addend_34 = _13 / _14;
  # DEBUG u64_addend => u64_addend_34
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32_addend_35 = (const uint32_t) u64_addend_34;
  # DEBUG u32_addend => u32_addend_35
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = base_va_26(D) + 2840;
  _16 = (volatile uint32_t *) _15;
  *_16 ={v} u32_addend_35;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  regval_37 ={v} *_2;
  # DEBUG regval => regval_37
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _17 = regval_37 | 32;
  *_2 ={v} _17;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_40 = reg_wait_for_clear (_2, 32, 10);
  # DEBUG ret => ret_40
  # DEBUG BEGIN_STMT
  if (ret_40 == 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 88299840]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _18 = base_va_26(D) + 2832;
  _19 = (volatile uint32_t *) _18;
  *_19 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = base_va_26(D) + 2836;
  _21 = (volatile uint32_t *) _20;
  *_21 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  regval_43 ={v} *_2;
  # DEBUG regval => regval_43
  # DEBUG BEGIN_STMT
  regval_44 = regval_43 | 4;
  # DEBUG regval => regval_44
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} regval_44;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_47 = reg_wait_for_clear (_2, 4, 10);
  # DEBUG ret => ret_47

  <bb 10> [local count: 1073741824]:
  # ret_22 = PHI <0(4), 22(7), ret_40(8), ret_47(9)>
  # DEBUG ret => ret_22
  # DEBUG BEGIN_STMT
  return ret_22;

}



;; Function pfe_emac_cfg_disable_ts (pfe_emac_cfg_disable_ts, funcdef_no=18, decl_uid=9220, cgraph_uid=19, symbol_order=20)

Modification phase of node pfe_emac_cfg_disable_ts/20
pfe_emac_cfg_disable_ts (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 2816;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_get_index (pfe_emac_cfg_get_index, funcdef_no=21, decl_uid=9213, cgraph_uid=22, symbol_order=23)

Modification phase of node pfe_emac_cfg_get_index/23
pfe_emac_cfg_get_index (addr_t emac_base, addr_t cbus_base)
{
  uint8_t idx;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_base_3(D) - cbus_base_4(D);
  switch (_1) <default: <L3> [25.00%], case 655360: <L6> [25.00%], case 671744: <L1> [25.00%], case 688128: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  # DEBUG idx => 1
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  # DEBUG idx => 2
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L3>:
  # DEBUG BEGIN_STMT
  # DEBUG idx => 255
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # idx_2 = PHI <0(2), 1(3), 2(4), 255(5)>
<L6>:
  # DEBUG idx => idx_2
  # DEBUG BEGIN_STMT
  return idx_2;

}



;; Function pfe_emac_cfg_adjust_ts_freq (pfe_emac_cfg_adjust_ts_freq, funcdef_no=22, decl_uid=9226, cgraph_uid=23, symbol_order=24)

Modification phase of node pfe_emac_cfg_adjust_ts_freq/24
pfe_emac_cfg_adjust_ts_freq (addr_t base_va, uint32_t i_clk_hz, uint32_t o_clk_hz, uint32_t ppb, bool_t sgn)
{
  const uint64_t u64_delta;
  const uint64_t u64_nil;
  errno_t ret;
  uint32_t regval;
  uint32_t delta;
  uint32_t nil;
  unsigned char _1;
  long long unsigned int _2;
  long long unsigned int _3;
  long long unsigned int _4;
  long long unsigned int _5;
  long long unsigned int _6;
  long long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  unsigned int _10;
  volatile uint32_t * _11;
  long unsigned int _12;
  long long unsigned int _28;
  long long unsigned int _37;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = is_eclk_enabled (base_va_17(D));
  if (_1 == 1)
    goto <bb 11>; [21.72%]
  else
    goto <bb 3>; [78.28%]

  <bb 3> [local count: 840525099]:
  # DEBUG BEGIN_STMT
  if (i_clk_hz_19(D) == 0)
    goto <bb 4>; [20.96%]
  else
    goto <bb 5>; [79.04%]

  <bb 4> [local count: 176174061]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid frequency value", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac_csr.c", 623, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 11>; [100.00%]

  <bb 5> [local count: 664351039]:
  # DEBUG BEGIN_STMT
  _2 = (long long unsigned int) o_clk_hz_20(D);
  _3 = _2 << 32;
  _4 = (long long unsigned int) i_clk_hz_19(D);
  u64_nil_21 = _3 / _4;
  # DEBUG u64_nil => u64_nil_21
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  nil_22 = (uint32_t) u64_nil_21;
  # DEBUG nil => nil_22
  # DEBUG BEGIN_STMT
  _28 = u64_nil_21 & 4294967295;
  _5 = (long long unsigned int) ppb_23(D);
  _6 = _5 * _28;
  u64_delta_24 = _6 / 1000000000;
  # DEBUG u64_delta => u64_delta_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  delta_25 = (uint32_t) u64_delta_24;
  # DEBUG delta => delta_25
  # DEBUG BEGIN_STMT
  if (sgn_26(D) != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 332175519]:
  # DEBUG BEGIN_STMT
  _37 = u64_delta_24 & 4294967295;
  _7 = _28 + _37;
  if (_7 > 4294967295)
    goto <bb 10>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 166087760]:
  # DEBUG BEGIN_STMT
  regval_29 = nil_22 + delta_25;
  # DEBUG regval => regval_29
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 332175519]:
  # DEBUG BEGIN_STMT
  if (nil_22 < delta_25)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 166087760]:
  # DEBUG BEGIN_STMT
  regval_27 = nil_22 - delta_25;
  # DEBUG regval => regval_27

  <bb 10> [local count: 664351040]:
  # regval_13 = PHI <regval_29(7), 0(8), regval_27(9), 4294967295(6)>
  # DEBUG regval => regval_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = base_va_17(D) + 2840;
  _9 = (volatile uint32_t *) _8;
  *_9 ={v} regval_13;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = base_va_17(D) + 2816;
  _11 = (volatile uint32_t *) _10;
  regval_31 ={v} *_11;
  # DEBUG regval => regval_31
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = regval_31 | 32;
  *_11 ={v} _12;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_34 = reg_wait_for_clear (_11, 32, 10);
  # DEBUG ret => ret_34

  <bb 11> [local count: 1073741824]:
  # ret_14 = PHI <13(2), 22(4), ret_34(10)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  return ret_14;

}



;; Function pfe_emac_cfg_get_ts_time (pfe_emac_cfg_get_ts_time, funcdef_no=23, decl_uid=9231, cgraph_uid=24, symbol_order=25)

Modification phase of node pfe_emac_cfg_get_ts_time/25
pfe_emac_cfg_get_ts_time (addr_t base_va, uint32_t * sec, uint32_t * nsec, uint16_t * sec_hi)
{
  uint32_t sec_tmp;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  unsigned int _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;
  long unsigned int _9;
  short unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 118111600]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_14(D) + 2824;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  *sec_15(D) = _3;
  # DEBUG BEGIN_STMT
  _4 = base_va_14(D) + 2828;
  _5 = (volatile uint32_t *) _4;
  _6 ={v} *_5;
  *nsec_17(D) = _6;
  # DEBUG BEGIN_STMT
  _7 = base_va_14(D) + 2844;
  _8 = (volatile uint32_t *) _7;
  _9 ={v} *_8;
  _10 = (short unsigned int) _9;
  *sec_hi_19(D) = _10;
  # DEBUG BEGIN_STMT
  sec_tmp_21 ={v} *_2;
  # DEBUG sec_tmp => sec_tmp_21
  # DEBUG BEGIN_STMT
  _11 = *sec_15(D);
  if (_11 != sec_tmp_21)
    goto <bb 5>; [89.00%]
  else
    goto <bb 4>; [11.00%]

  <bb 5> [local count: 955630223]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 118111601]:
  return;

}



;; Function pfe_emac_cfg_set_ts_time (pfe_emac_cfg_set_ts_time, funcdef_no=24, decl_uid=9236, cgraph_uid=25, symbol_order=26)

Modification phase of node pfe_emac_cfg_set_ts_time/26
pfe_emac_cfg_set_ts_time (addr_t base_va, uint32_t sec, uint32_t nsec, uint16_t sec_hi)
{
  errno_t ret;
  uint32_t regval;
  signed int nsec.5_1;
  unsigned char _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  volatile uint32_t * _6;
  unsigned int _7;
  volatile uint32_t * _8;
  long unsigned int _9;
  unsigned int _10;
  volatile uint32_t * _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  nsec.5_1 = (signed int) nsec_14(D);
  if (nsec.5_1 < 0)
    goto <bb 5>; [43.17%]
  else
    goto <bb 3>; [56.83%]

  <bb 3> [local count: 610207479]:
  # DEBUG BEGIN_STMT
  _2 = is_eclk_enabled (base_va_16(D));
  if (_2 == 1)
    goto <bb 5>; [36.03%]
  else
    goto <bb 4>; [63.97%]

  <bb 4> [local count: 390349724]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = base_va_16(D) + 2832;
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} sec_18(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = base_va_16(D) + 2836;
  _6 = (volatile uint32_t *) _5;
  *_6 ={v} nsec_14(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = base_va_16(D) + 2844;
  _8 = (volatile uint32_t *) _7;
  _9 = (long unsigned int) sec_hi_21(D);
  *_8 ={v} _9;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = base_va_16(D) + 2816;
  _11 = (volatile uint32_t *) _10;
  regval_23 ={v} *_11;
  # DEBUG regval => regval_23
  # DEBUG BEGIN_STMT
  regval_24 = regval_23 | 4;
  # DEBUG regval => regval_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_11 ={v} regval_24;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_27 = reg_wait_for_clear (_11, 4, 10);
  # DEBUG ret => ret_27

  <bb 5> [local count: 1073741824]:
  # ret_12 = PHI <22(2), 13(3), ret_27(4)>
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  return ret_12;

}



;; Function pfe_emac_cfg_adjust_ts_time (pfe_emac_cfg_adjust_ts_time, funcdef_no=25, decl_uid=9241, cgraph_uid=26, symbol_order=27)

Modification phase of node pfe_emac_cfg_adjust_ts_time/27
pfe_emac_cfg_adjust_ts_time (addr_t base_va, uint32_t sec, uint32_t nsec, bool_t sgn)
{
  errno_t ret;
  uint32_t sec_temp;
  uint32_t nsec_temp;
  uint32_t regval;
  signed int nsec_temp.6_1;
  unsigned char _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;
  unsigned int _9;
  volatile uint32_t * _10;
  long unsigned int _11;
  long unsigned int iftmp.7_16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG nsec_temp => nsec_18(D)
  # DEBUG BEGIN_STMT
  # DEBUG sec_temp => sec_19(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  nsec_temp.6_1 = (signed int) nsec_18(D);
  if (nsec_temp.6_1 < 0)
    goto <bb 14>; [43.17%]
  else
    goto <bb 3>; [56.83%]

  <bb 3> [local count: 610207479]:
  # DEBUG BEGIN_STMT
  _2 = is_eclk_enabled (base_va_21(D));
  if (_2 == 1)
    goto <bb 14>; [21.72%]
  else
    goto <bb 4>; [78.28%]

  <bb 4> [local count: 477670414]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _3 = base_va_21(D) + 2816;
  _4 = (volatile uint32_t *) _3;
  regval_23 ={v} *_4;
  # DEBUG regval => regval_23
  # DEBUG BEGIN_STMT
  if (sgn_24(D) == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 5> [local count: 238835207]:
  # DEBUG BEGIN_STMT
  _5 = regval_23 & 512;
  if (_5 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 119417604]:
  # DEBUG BEGIN_STMT
  nsec_temp_26 = 1000000000 - nsec_18(D);
  # DEBUG nsec_temp => nsec_temp_26
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 119417604]:
  # DEBUG BEGIN_STMT
  nsec_temp_25 = 2147483648 - nsec_18(D);
  # DEBUG nsec_temp => nsec_temp_25

  <bb 8> [local count: 238835207]:
  # nsec_temp_12 = PHI <nsec_temp_26(6), nsec_temp_25(7)>
  # DEBUG nsec_temp => nsec_temp_12
  # DEBUG BEGIN_STMT
  sec_temp_27 = -sec_19(D);
  # DEBUG sec_temp => sec_temp_27

  <bb 9> [local count: 477670414]:
  # nsec_temp_13 = PHI <nsec_18(D)(4), nsec_temp_12(8)>
  # sec_temp_14 = PHI <sec_19(D)(4), sec_temp_27(8)>
  # DEBUG sec_temp => sec_temp_14
  # DEBUG nsec_temp => nsec_temp_13
  # DEBUG BEGIN_STMT
  _6 = regval_23 & 512;
  if (_6 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 238835207]:
  # DEBUG BEGIN_STMT
  if (nsec_temp_13 > 999999999)
    goto <bb 14>; [35.00%]
  else
    goto <bb 11>; [65.00%]

  <bb 11> [local count: 394078092]:
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = base_va_21(D) + 2832;
  _8 = (volatile uint32_t *) _7;
  *_8 ={v} sec_temp_14;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (sgn_24(D) == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 197039046]:

  <bb 13> [local count: 394078092]:
  # iftmp.7_16 = PHI <2147483648(11), 0(12)>
  _9 = base_va_21(D) + 2836;
  _10 = (volatile uint32_t *) _9;
  _11 = nsec_temp_13 | iftmp.7_16;
  *_10 ={v} _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  regval_30 ={v} *_4;
  # DEBUG regval => regval_30
  # DEBUG BEGIN_STMT
  regval_31 = regval_30 | 8;
  # DEBUG regval => regval_31
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_4 ={v} regval_31;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_34 = reg_wait_for_clear (_4, 8, 10);
  # DEBUG ret => ret_34

  <bb 14> [local count: 1073741824]:
  # ret_15 = PHI <22(2), 13(3), 22(10), ret_34(13)>
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  return ret_15;

}



;; Function pfe_emac_cfg_get_link_config (pfe_emac_cfg_get_link_config, funcdef_no=26, decl_uid=9259, cgraph_uid=27, symbol_order=28)

Modification phase of node pfe_emac_cfg_get_link_config/28
pfe_emac_cfg_get_link_config (addr_t base_va, pfe_emac_speed_t * speed, pfe_emac_duplex_t * duplex)
{
  uint32_t reg;
  volatile uint32_t * base_va.8_1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  <unnamed type> _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  base_va.8_1 = (volatile uint32_t *) base_va_7(D);
  reg_9 ={v} *base_va.8_1;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  _2 = reg_9 >> 14;
  _3 = _2 & 3;
  switch (_3) <default: <L3> [25.00%], case 1: <L0> [25.00%], case 2: <L1> [25.00%], case 3: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  *speed_10(D) = 4;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  *speed_10(D) = 1;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  *speed_10(D) = 2;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 268435456]:
<L3>:
  # DEBUG BEGIN_STMT
  *speed_10(D) = 3;
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 = reg_9 >> 13;
  _5 = _4 & 1;
  _15 = _5 + 1;
  *duplex_16(D) = _15;
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_emac_cfg_get_stat_value (pfe_emac_cfg_get_stat_value, funcdef_no=27, decl_uid=9355, cgraph_uid=28, symbol_order=29)

Modification phase of node pfe_emac_cfg_get_stat_value/29
pfe_emac_cfg_get_stat_value (addr_t base_va, uint32_t stat_id)
{
  uint32_t stat_value;
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + stat_id_4(D);
  _2 = (volatile uint32_t *) _1;
  stat_value_6 ={v} *_2;
  # DEBUG stat_value => stat_value_6
  # DEBUG BEGIN_STMT
  return stat_value_6;

}



;; Function pfe_emac_cfg_tx_disable (pfe_emac_cfg_tx_disable, funcdef_no=62, decl_uid=9243, cgraph_uid=29, symbol_order=30)

Modification phase of node pfe_emac_cfg_tx_disable/30
pfe_emac_cfg_tx_disable (addr_t base_va)
{
  <bb 2> [local count: 1073741824]:
  pfe_emac_cfg_disable_ts (base_va_2(D)); [tail call]
  return;

}



;; Function pfe_emac_cfg_set_duplex (pfe_emac_cfg_set_duplex, funcdef_no=29, decl_uid=9246, cgraph_uid=30, symbol_order=31)

Modification phase of node pfe_emac_cfg_set_duplex/31
pfe_emac_cfg_set_duplex (addr_t base_va, pfe_emac_duplex_t duplex)
{
  errno_t ret;
  uint32_t reg;
  volatile uint32_t * base_va.10_1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  base_va.10_1 = (volatile uint32_t *) base_va_4(D);
  _2 ={v} *base_va.10_1;
  reg_6 = _2 & 4294959103;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  switch (duplex_7(D)) <default: <L9> [33.33%], case 1: <L10> [33.33%], case 2: <L1> [33.33%]>

  <bb 3> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  reg_8 = reg_6 | 8192;
  # DEBUG reg => reg_8
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG reg => reg_8
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 715756301]:
  # reg_10 = PHI <reg_8(3), reg_6(2)>
<L10>:
  # DEBUG ret => NULL
  # DEBUG reg => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *base_va.10_1 ={v} reg_10;

  <bb 5> [local count: 1073634451]:
  # ret_11 = PHI <22(2), 0(4)>
<L9>:
  # DEBUG ret => NULL
  # DEBUG reg => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_11;

}



;; Function pfe_emac_cfg_set_mii_mode (pfe_emac_cfg_set_mii_mode, funcdef_no=30, decl_uid=9249, cgraph_uid=31, symbol_order=32)

Modification phase of node pfe_emac_cfg_set_mii_mode/32
pfe_emac_cfg_set_mii_mode (addr_t base_va, pfe_emac_mii_mode_t mode)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_emac_cfg_set_speed (pfe_emac_cfg_set_speed, funcdef_no=31, decl_uid=9252, cgraph_uid=32, symbol_order=33)

Modification phase of node pfe_emac_cfg_set_speed/33
pfe_emac_cfg_set_speed (addr_t base_va, pfe_emac_speed_t speed)
{
  errno_t ret;
  uint32_t reg;
  volatile uint32_t * base_va.12_1;
  long unsigned int _2;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  base_va.12_1 = (volatile uint32_t *) base_va_4(D);
  _2 ={v} *base_va.12_1;
  reg_6 = _2 & 4294918143;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  switch (speed_7(D)) <default: <L11> [20.00%], case 1: <L0> [20.00%], case 2: <L1> [20.00%], case 3: <L12> [20.00%], case 4: <L3> [20.00%]>

  <bb 3> [local count: 214748364]:
<L0>:
  # DEBUG BEGIN_STMT
  reg_10 = reg_6 | 32768;
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 214748364]:
<L1>:
  # DEBUG BEGIN_STMT
  # DEBUG reg => reg_6 | 32768
  # DEBUG BEGIN_STMT
  reg_9 = reg_6 | 49152;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 214748364]:
<L3>:
  # DEBUG BEGIN_STMT
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  reg_8 = reg_6 | 16384;
  # DEBUG reg => reg_8
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG reg => reg_8
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 858993459]:
  # reg_12 = PHI <reg_9(4), reg_10(3), reg_8(5), reg_6(2)>
<L12>:
  # DEBUG ret => NULL
  # DEBUG reg => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *base_va.12_1 ={v} reg_12;

  <bb 7> [local count: 1073741824]:
  # ret_13 = PHI <22(2), 0(6)>
<L11>:
  # DEBUG ret => NULL
  # DEBUG reg => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_13;

}



;; Function pfe_emac_cfg_init (pfe_emac_cfg_init, funcdef_no=16, decl_uid=9210, cgraph_uid=17, symbol_order=18)

Modification phase of node pfe_emac_cfg_init/18
pfe_emac_cfg_init (addr_t base_va, pfe_emac_mii_mode_t mode, pfe_emac_speed_t speed, pfe_emac_duplex_t duplex)
{
  errno_t ret;
  uint32_t reg;
  volatile uint32_t * base_va.0_1;
  unsigned int _2;
  volatile uint32_t * _3;
  unsigned int _4;
  volatile uint32_t * _5;
  unsigned int _6;
  volatile uint32_t * _7;
  unsigned int _8;
  volatile uint32_t * _9;
  unsigned int _10;
  volatile uint32_t * _11;
  unsigned int _12;
  volatile uint32_t * _13;
  unsigned int _14;
  volatile uint32_t * _15;
  unsigned int _16;
  volatile uint32_t * _17;
  unsigned int _18;
  volatile uint32_t * _19;
  unsigned int _20;
  volatile uint32_t * _21;
  long unsigned int _22;
  unsigned int _23;
  volatile uint32_t * _24;
  unsigned int _25;
  volatile uint32_t * _26;
  unsigned char _27;
  unsigned int _28;
  volatile uint32_t * _29;
  unsigned int _30;
  volatile uint32_t * _31;
  unsigned char _32;
  unsigned int _33;
  volatile uint32_t * _34;
  unsigned int _35;
  volatile uint32_t * _36;
  unsigned int _37;
  volatile uint32_t * _38;
  unsigned int _39;
  volatile uint32_t * _40;
  int _41;
  int _42;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_emac_cfg_clear_registers (base_va_48(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  base_va.0_1 = (volatile uint32_t *) base_va_48(D);
  *base_va.0_1 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = base_va_48(D) + 768;
  _3 = (volatile uint32_t *) _2;
  *_3 ={v} 2147549166;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = base_va_48(D) + 772;
  _5 = (volatile uint32_t *) _4;
  *_5 ={v} 3721182122;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = base_va_48(D) + 8;
  _7 = (volatile uint32_t *) _6;
  *_7 ={v} 1094;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = base_va_48(D) + 112;
  _9 = (volatile uint32_t *) _8;
  reg_54 ={v} *_9;
  # DEBUG reg => reg_54
  # DEBUG BEGIN_STMT
  reg_55 = reg_54 & 4294967293;
  # DEBUG reg => reg_55
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_9 ={v} reg_55;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = base_va_48(D) + 180;
  _11 = (volatile uint32_t *) _10;
  *_11 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = base_va_48(D) + 1804;
  _13 = (volatile uint32_t *) _12;
  *_13 ={v} 4294967295;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = base_va_48(D) + 1808;
  _15 = (volatile uint32_t *) _14;
  *_15 ={v} 4294967295;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = base_va_48(D) + 2048;
  _17 = (volatile uint32_t *) _16;
  *_17 ={v} 4294967295;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _18 = base_va_48(D) + 3264;
  _19 = (volatile uint32_t *) _18;
  *_19 ={v} 31;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = base_va_48(D) + 332;
  _21 = (volatile uint32_t *) _20;
  reg_62 ={v} *_21;
  # DEBUG reg => reg_62
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 = reg_62 | 2228524;
  *_21 ={v} _22;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = base_va_48(D) + 3296;
  _24 = (volatile uint32_t *) _23;
  *_24 ={v} 5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = base_va_48(D) + 328;
  _26 = (volatile uint32_t *) _25;
  *_26 ={v} 3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG reg => 146415616
  # DEBUG BEGIN_STMT
  _27 = pfe_feature_mgr_is_available ("jumbo_frames");
  if (_27 == 1)
    goto <bb 4>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  # DEBUG reg => 146415616

  <bb 4> [local count: 1073741824]:
  # reg_43 = PHI <146481152(2), 146415616(3)>
  # DEBUG reg => reg_43
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *base_va.0_1 ={v} reg_43;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _28 = base_va_48(D) + 3376;
  _29 = (volatile uint32_t *) _28;
  *_29 ={v} 16;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _30 = base_va_48(D) + 3328;
  _31 = (volatile uint32_t *) _30;
  *_31 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _32 = pfe_feature_mgr_is_available ("jumbo_frames");
  if (_32 == 1)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _33 = base_va_48(D) + 4;
  _34 = (volatile uint32_t *) _33;
  *_34 ={v} 9022;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _35 = base_va_48(D) + 4;
  _36 = (volatile uint32_t *) _35;
  *_36 ={v} 1522;

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _37 = base_va_48(D) + 2816;
  _38 = (volatile uint32_t *) _37;
  *_38 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _39 = base_va_48(D) + 2820;
  _40 = (volatile uint32_t *) _39;
  *_40 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _41 = pfe_emac_cfg_set_speed (base_va_48(D), speed_75(D));
  if (_41 != 0)
    goto <bb 10>; [52.23%]
  else
    goto <bb 8>; [47.77%]

  <bb 8> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_48(D)
  # DEBUG mode => mode_77(D)
  # DEBUG INLINE_ENTRY NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG mode => NULL
  # DEBUG BEGIN_STMT
  _42 = pfe_emac_cfg_set_duplex (base_va_48(D), duplex_78(D));
  if (_42 != 0)
    goto <bb 10>; [35.00%]
  else
    goto <bb 9>; [65.00%]

  <bb 9> [local count: 333402205]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 10> [local count: 1073741824]:
  # ret_44 = PHI <22(7), 0(9), 22(8)>
  # DEBUG ret => ret_44
  # DEBUG BEGIN_STMT
  return ret_44;

}



;; Function pfe_emac_cfg_get_link_status (pfe_emac_cfg_get_link_status, funcdef_no=32, decl_uid=9264, cgraph_uid=33, symbol_order=34)

Modification phase of node pfe_emac_cfg_get_link_status/34
pfe_emac_cfg_get_link_status (addr_t base_va, pfe_emac_link_speed_t * link_speed, pfe_emac_duplex_t * duplex, bool_t * link)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  <unnamed type> _8;
  _Bool _9;
  unsigned char _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_12(D) + 248;
  _2 = (volatile uint32_t *) _1;
  reg_14 ={v} *_2;
  # DEBUG reg => reg_14
  # DEBUG BEGIN_STMT
  _3 = reg_14 >> 17;
  _4 = _3 & 3;
  switch (_4) <default: <L3> [25.00%], case 1: <L0> [25.00%], case 2: <L1> [25.00%], case 3: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  *link_speed_15(D) = 2;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  *link_speed_15(D) = 3;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  *link_speed_15(D) = 0;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 268435456]:
<L3>:
  # DEBUG BEGIN_STMT
  *link_speed_15(D) = 1;
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = reg_14 >> 16;
  _6 = _5 & 1;
  _8 = _6 + 1;
  *duplex_20(D) = _8;
  # DEBUG BEGIN_STMT
  _7 = reg_14 >> 19;
  _9 = (_Bool) _7;
  _10 = (unsigned char) _9;
  *link_22(D) = _10;
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_emac_cfg_set_max_frame_length (pfe_emac_cfg_set_max_frame_length, funcdef_no=33, decl_uid=9255, cgraph_uid=34, symbol_order=35)

Modification phase of node pfe_emac_cfg_set_max_frame_length/35
pfe_emac_cfg_set_max_frame_length (addr_t base_va, uint32_t len)
{
  errno_t ret;
  uint32_t maxlen;
  uint32_t reg;
  volatile uint32_t * base_va.15_1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned int _5;
  volatile uint32_t * _6;
  long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  unsigned int _10;
  volatile uint32_t * _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG maxlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  base_va.15_1 = (volatile uint32_t *) base_va_20(D);
  reg_22 ={v} *base_va.15_1;
  # DEBUG reg => reg_22
  # DEBUG BEGIN_STMT
  _2 = reg_22 & 65536;
  # DEBUG D#4 => _2 != 0
  # DEBUG je => (bool_t) D#4
  # DEBUG BEGIN_STMT
  _3 = reg_22 & 4194304;
  # DEBUG D#3 => _3 != 0
  # DEBUG s2kp => (bool_t) D#3
  # DEBUG BEGIN_STMT
  _4 = reg_22 & 8388608;
  # DEBUG D#2 => _4 != 0
  # DEBUG gpslce => (bool_t) D#2
  # DEBUG BEGIN_STMT
  _5 = base_va_20(D) + 80;
  _6 = (volatile uint32_t *) _5;
  reg_23 ={v} *_6;
  # DEBUG reg => reg_23
  # DEBUG BEGIN_STMT
  _7 = reg_23 & 67108864;
  # DEBUG D#1 => _7 != 0
  # DEBUG edvlp => (bool_t) D#1
  # DEBUG BEGIN_STMT
  if (_2 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  if (_7 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG maxlen => 9026

  <bb 5> [local count: 1073741824]:
  # maxlen_12 = PHI <0(2), 0(3), 9026(4)>
  # DEBUG maxlen => maxlen_12
  # DEBUG BEGIN_STMT
  if (_2 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 536870913]:
  if (_3 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG maxlen => 2000

  <bb 8> [local count: 1073741824]:
  # maxlen_13 = PHI <maxlen_12(5), maxlen_12(6), 2000(7)>
  # DEBUG maxlen => maxlen_13
  # DEBUG BEGIN_STMT
  if (_2 == 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 9> [local count: 536870913]:
  if (_3 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 10> [local count: 268435456]:
  if (_4 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 11> [local count: 134217728]:
  if (_7 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  _8 = base_va_20(D) + 4;
  _9 = (volatile uint32_t *) _8;
  reg_24 ={v} *_9;
  # DEBUG reg => reg_24
  # DEBUG BEGIN_STMT
  maxlen_25 = reg_24 & 16383;
  # DEBUG maxlen => maxlen_25
  # DEBUG BEGIN_STMT
  maxlen_26 = maxlen_25 + 8;
  # DEBUG maxlen => maxlen_26

  <bb 13> [local count: 1073741824]:
  # maxlen_14 = PHI <maxlen_13(8), maxlen_13(9), maxlen_13(10), maxlen_13(11), maxlen_26(12)>
  # DEBUG maxlen => maxlen_14
  # DEBUG BEGIN_STMT
  if (_2 == 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 14> [local count: 536870913]:
  if (_3 == 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 15> [local count: 268435456]:
  if (_4 == 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 16> [local count: 134217728]:
  if (_7 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 17> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  # DEBUG maxlen => 1526

  <bb 18> [local count: 1073741824]:
  # maxlen_15 = PHI <maxlen_14(13), maxlen_14(14), maxlen_14(15), maxlen_14(16), 1526(17)>
  # DEBUG maxlen => maxlen_15
  # DEBUG BEGIN_STMT
  if (_2 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 19> [local count: 536870913]:
  if (_7 == 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 20> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG maxlen => 9022

  <bb 21> [local count: 1073741824]:
  # maxlen_16 = PHI <maxlen_15(18), maxlen_15(19), 9022(20)>
  # DEBUG maxlen => maxlen_16
  # DEBUG BEGIN_STMT
  if (_2 == 0)
    goto <bb 22>; [50.00%]
  else
    goto <bb 26>; [50.00%]

  <bb 22> [local count: 536870913]:
  if (_3 == 0)
    goto <bb 23>; [50.00%]
  else
    goto <bb 26>; [50.00%]

  <bb 23> [local count: 268435456]:
  if (_4 != 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 26>; [50.00%]

  <bb 24> [local count: 134217728]:
  if (_7 == 0)
    goto <bb 25>; [50.00%]
  else
    goto <bb 26>; [50.00%]

  <bb 25> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  _10 = base_va_20(D) + 4;
  _11 = (volatile uint32_t *) _10;
  reg_27 ={v} *_11;
  # DEBUG reg => reg_27
  # DEBUG BEGIN_STMT
  maxlen_28 = reg_27 & 16383;
  # DEBUG maxlen => maxlen_28
  # DEBUG BEGIN_STMT
  maxlen_29 = maxlen_28 + 4;
  # DEBUG maxlen => maxlen_29

  <bb 26> [local count: 1073741824]:
  # maxlen_17 = PHI <maxlen_16(21), maxlen_16(22), maxlen_16(23), maxlen_16(24), maxlen_29(25)>
  # DEBUG maxlen => maxlen_17
  # DEBUG BEGIN_STMT
  if (_2 == 0)
    goto <bb 27>; [50.00%]
  else
    goto <bb 31>; [50.00%]

  <bb 27> [local count: 536870913]:
  if (_3 == 0)
    goto <bb 28>; [50.00%]
  else
    goto <bb 31>; [50.00%]

  <bb 28> [local count: 268435456]:
  if (_4 == 0)
    goto <bb 29>; [50.00%]
  else
    goto <bb 31>; [50.00%]

  <bb 29> [local count: 134217728]:
  if (_7 == 0)
    goto <bb 30>; [50.00%]
  else
    goto <bb 31>; [50.00%]

  <bb 30> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  # DEBUG maxlen => 1522

  <bb 31> [local count: 1073741824]:
  # maxlen_18 = PHI <maxlen_17(26), maxlen_17(27), maxlen_17(28), maxlen_17(29), 1522(30)>
  # DEBUG maxlen => maxlen_18
  # DEBUG BEGIN_STMT
  if (maxlen_18 < len_30(D))
    goto <bb 33>; [35.00%]
  else
    goto <bb 32>; [65.00%]

  <bb 32> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 33> [local count: 1073741824]:
  # ret_19 = PHI <22(31), 0(32)>
  # DEBUG ret => ret_19
  # DEBUG BEGIN_STMT
  return ret_19;

}



;; Function pfe_emac_cfg_write_addr_slot (pfe_emac_cfg_write_addr_slot, funcdef_no=34, decl_uid=9268, cgraph_uid=35, symbol_order=36)

Modification phase of node pfe_emac_cfg_write_addr_slot/36
pfe_emac_cfg_write_addr_slot (addr_t base_va, const uint8_t * addr, uint8_t slot)
{
  uint32_t top;
  uint32_t bottom;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned char _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned char _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  unsigned char _12;
  long unsigned int _13;
  unsigned char _14;
  long unsigned int _15;
  long unsigned int _16;
  unsigned char _17;
  long unsigned int _18;
  unsigned int _19;
  unsigned int _20;
  unsigned int _21;
  unsigned int _22;
  volatile uint32_t * _23;
  unsigned int _24;
  unsigned int _25;
  unsigned int _26;
  volatile uint32_t * _27;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = MEM[(const uint8_t *)addr_29(D) + 3B];
  _2 = (long unsigned int) _1;
  _3 = _2 << 24;
  _4 = MEM[(const uint8_t *)addr_29(D) + 2B];
  _5 = (long unsigned int) _4;
  _6 = _5 << 16;
  _7 = _3 | _6;
  _8 = MEM[(const uint8_t *)addr_29(D) + 1B];
  _9 = (long unsigned int) _8;
  _10 = _9 << 8;
  _11 = _7 | _10;
  _12 = *addr_29(D);
  _13 = (long unsigned int) _12;
  bottom_31 = _11 | _13;
  # DEBUG bottom => bottom_31
  # DEBUG BEGIN_STMT
  _14 = MEM[(const uint8_t *)addr_29(D) + 5B];
  _15 = (long unsigned int) _14;
  _16 = _15 << 8;
  _17 = MEM[(const uint8_t *)addr_29(D) + 4B];
  _18 = (long unsigned int) _17;
  top_32 = _16 | _18;
  # DEBUG top => top_32
  # DEBUG BEGIN_STMT
  if (top_32 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  if (bottom_31 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 805306369]:
  # DEBUG BEGIN_STMT
  top_33 = top_32 | 2147483648;
  # DEBUG top => top_33

  <bb 5> [local count: 1073741824]:
  # top_28 = PHI <0(3), top_33(4)>
  # DEBUG top => top_28
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = (unsigned int) slot_34(D);
  _20 = _19 + 96;
  _21 = _20 * 8;
  _22 = _21 + base_va_35(D);
  _23 = (volatile uint32_t *) _22;
  *_23 ={v} top_28;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _24 = _19 * 8;
  _25 = _24 + base_va_35(D);
  _26 = _25 + 772;
  _27 = (volatile uint32_t *) _26;
  *_27 ={v} bottom_31;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oal_time_udelay (10);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_27 ={v} bottom_31;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_read_addr_slot (pfe_emac_cfg_read_addr_slot, funcdef_no=35, decl_uid=9272, cgraph_uid=36, symbol_order=37)

Modification phase of node pfe_emac_cfg_read_addr_slot/37
pfe_emac_cfg_read_addr_slot (addr_t base_va, uint8_t * addr, uint8_t slot)
{
  uint32_t bottom;
  uint32_t top;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  volatile uint32_t * _5;
  unsigned int _6;
  unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  signed int top.16_10;
  unsigned char _11;
  long unsigned int _12;
  unsigned char _13;
  long unsigned int _14;
  unsigned char _15;
  long unsigned int _16;
  unsigned char _17;
  unsigned char _18;
  long unsigned int _19;
  unsigned char _20;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) slot_22(D);
  _2 = _1 + 96;
  _3 = _2 * 8;
  _4 = _3 + base_va_23(D);
  _5 = (volatile uint32_t *) _4;
  top_25 ={v} *_5;
  # DEBUG top => top_25
  # DEBUG BEGIN_STMT
  _6 = _1 * 8;
  _7 = _6 + base_va_23(D);
  _8 = _7 + 772;
  _9 = (volatile uint32_t *) _8;
  bottom_26 ={v} *_9;
  # DEBUG bottom => bottom_26
  # DEBUG BEGIN_STMT
  top.16_10 = (signed int) top_25;
  if (top.16_10 < 0)
    goto <bb 3>; [58.52%]
  else
    goto <bb 4>; [41.48%]

  <bb 3> [local count: 628353716]:
  # DEBUG BEGIN_STMT
  _11 = (unsigned char) bottom_26;
  *addr_27(D) = _11;
  # DEBUG BEGIN_STMT
  _12 = bottom_26 >> 8;
  _13 = (unsigned char) _12;
  MEM[(uint8_t *)addr_27(D) + 1B] = _13;
  # DEBUG BEGIN_STMT
  _14 = bottom_26 >> 16;
  _15 = (unsigned char) _14;
  MEM[(uint8_t *)addr_27(D) + 2B] = _15;
  # DEBUG BEGIN_STMT
  _16 = bottom_26 >> 24;
  _17 = (unsigned char) _16;
  MEM[(uint8_t *)addr_27(D) + 3B] = _17;
  # DEBUG BEGIN_STMT
  _18 = (unsigned char) top_25;
  MEM[(uint8_t *)addr_27(D) + 4B] = _18;
  # DEBUG BEGIN_STMT
  _19 = top_25 >> 8;
  _20 = (unsigned char) _19;
  MEM[(uint8_t *)addr_27(D) + 5B] = _20;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 445388109]:
  # DEBUG BEGIN_STMT
  autolibc_memset (addr_27(D), 0, 6);

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function pfe_emac_cfg_get_hash (pfe_emac_cfg_get_hash, funcdef_no=36, decl_uid=9275, cgraph_uid=37, symbol_order=38)

Modification phase of node pfe_emac_cfg_get_hash/38
pfe_emac_cfg_get_hash (addr_t base_va, const uint8_t * addr)
{
  uint32_t _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = crc32_reversed (addr_2(D), 6);
  return _3;

}



;; Function pfe_emac_cfg_set_hash_group (pfe_emac_cfg_set_hash_group, funcdef_no=37, decl_uid=9279, cgraph_uid=38, symbol_order=39)

Modification phase of node pfe_emac_cfg_set_hash_group/39
pfe_emac_cfg_set_hash_group (addr_t base_va, uint32_t hash, bool_t en)
{
  uint8_t pos;
  uint32_t val;
  uint32_t reg;
  unsigned char _1;
  unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;
  volatile uint32_t * _6;
  int _7;
  long unsigned int _8;
  int _9;
  long unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  val_15 = hash_14(D) >> 26;
  # DEBUG val => val_15
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) val_15;
  _2 = hash_14(D) >> 31;
  # DEBUG hash_table_idx => (unsigned char) _2
  # DEBUG BEGIN_STMT
  pos_16 = _1 & 31;
  # DEBUG pos => pos_16
  # DEBUG BEGIN_STMT
  _3 = _2 + 4;
  _4 = _3 * 4;
  _5 = _4 + base_va_17(D);
  _6 = (volatile uint32_t *) _5;
  reg_19 ={v} *_6;
  # DEBUG reg => reg_19
  # DEBUG BEGIN_STMT
  # DEBUG old_reg => reg_19
  # DEBUG BEGIN_STMT
  if (en_20(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _7 = (int) pos_16;
  _8 = 1 << _7;
  reg_22 = _8 | reg_19;
  # DEBUG reg => reg_22
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _9 = (int) pos_16;
  _10 = 1 << _9;
  _11 = ~_10;
  reg_21 = _11 & reg_19;
  # DEBUG reg => reg_21

  <bb 5> [local count: 1073741824]:
  # reg_12 = PHI <reg_22(3), reg_21(4)>
  # DEBUG reg => reg_12
  # DEBUG BEGIN_STMT
  if (reg_12 != reg_19)
    goto <bb 6>; [48.88%]
  else
    goto <bb 7>; [51.12%]

  <bb 6> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_6 ={v} reg_12;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oal_time_udelay (10);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_6 ={v} reg_12;

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_clear_hash_table (pfe_emac_cfg_clear_hash_table, funcdef_no=38, decl_uid=9281, cgraph_uid=39, symbol_order=40)

Modification phase of node pfe_emac_cfg_clear_hash_table/40
pfe_emac_cfg_clear_hash_table (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  volatile uint32_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_5(D) + 16;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = base_va_5(D) + 20;
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oal_time_udelay (10);
  return;

}



;; Function pfe_emac_cfg_set_loopback (pfe_emac_cfg_set_loopback, funcdef_no=39, decl_uid=9284, cgraph_uid=40, symbol_order=41)

Modification phase of node pfe_emac_cfg_set_loopback/41
pfe_emac_cfg_set_loopback (addr_t base_va, bool_t en)
{
  uint32_t reg;
  volatile uint32_t * base_va.18_1;
  long unsigned int _2;
  long unsigned int iftmp.19_3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  base_va.18_1 = (volatile uint32_t *) base_va_4(D);
  _2 ={v} *base_va.18_1;
  reg_6 = _2 & 4294963199;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  if (en_7(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.19_3 = PHI <4096(2), 0(3)>
  reg_8 = iftmp.19_3 | reg_6;
  # DEBUG reg => reg_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *base_va.18_1 ={v} reg_8;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_set_promisc_mode (pfe_emac_cfg_set_promisc_mode, funcdef_no=40, decl_uid=9287, cgraph_uid=41, symbol_order=42)

Modification phase of node pfe_emac_cfg_set_promisc_mode/42
pfe_emac_cfg_set_promisc_mode (addr_t base_va, bool_t en)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int iftmp.21_4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_5(D) + 8;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  reg_7 = _3 & 4294967294;
  # DEBUG reg => reg_7
  # DEBUG BEGIN_STMT
  if (en_8(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.21_4 = PHI <1(2), 0(3)>
  reg_9 = iftmp.21_4 | reg_7;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_9;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_set_allmulti_mode (pfe_emac_cfg_set_allmulti_mode, funcdef_no=41, decl_uid=9290, cgraph_uid=42, symbol_order=43)

Modification phase of node pfe_emac_cfg_set_allmulti_mode/43
pfe_emac_cfg_set_allmulti_mode (addr_t base_va, bool_t en)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int iftmp.22_4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_5(D) + 8;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  reg_7 = _3 & 4294967279;
  # DEBUG reg => reg_7
  # DEBUG BEGIN_STMT
  if (en_8(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.22_4 = PHI <16(2), 0(3)>
  reg_9 = iftmp.22_4 | reg_7;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_9;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_set_broadcast (pfe_emac_cfg_set_broadcast, funcdef_no=42, decl_uid=9293, cgraph_uid=43, symbol_order=44)

Modification phase of node pfe_emac_cfg_set_broadcast/44
pfe_emac_cfg_set_broadcast (addr_t base_va, bool_t en)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int iftmp.23_4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_5(D) + 8;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  reg_7 = _3 & 4294967263;
  # DEBUG reg => reg_7
  # DEBUG BEGIN_STMT
  if (en_8(D) == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.23_4 = PHI <32(2), 0(3)>
  reg_9 = iftmp.23_4 | reg_7;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_9;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_set_enable (pfe_emac_cfg_set_enable, funcdef_no=43, decl_uid=9296, cgraph_uid=44, symbol_order=45)

Modification phase of node pfe_emac_cfg_set_enable/45
pfe_emac_cfg_set_enable (addr_t base_va, bool_t en)
{
  uint32_t reg;
  volatile uint32_t * base_va.24_1;
  long unsigned int _2;
  long unsigned int iftmp.25_3;
  long unsigned int iftmp.26_4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  base_va.24_1 = (volatile uint32_t *) base_va_5(D);
  reg_7 ={v} *base_va.24_1;
  # DEBUG reg => reg_7
  # DEBUG BEGIN_STMT
  reg_8 = reg_7 & 4294967292;
  # DEBUG reg => reg_8
  # DEBUG BEGIN_STMT
  if (en_9(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.25_3 = PHI <2(2), 0(3)>
  if (en_9(D) != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 536870913]:

  <bb 6> [local count: 1073741824]:
  # iftmp.26_4 = PHI <1(4), 0(5)>
  _2 = iftmp.25_3 | iftmp.26_4;
  reg_10 = _2 | reg_8;
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *base_va.24_1 ={v} reg_10;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_get_tx_flow_control (pfe_emac_cfg_get_tx_flow_control, funcdef_no=44, decl_uid=9305, cgraph_uid=45, symbol_order=46)

Modification phase of node pfe_emac_cfg_get_tx_flow_control/46
pfe_emac_cfg_get_tx_flow_control (addr_t base_va, bool_t * en)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  _Bool _4;
  unsigned char _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_6(D) + 112;
  _2 = (volatile uint32_t *) _1;
  reg_8 ={v} *_2;
  # DEBUG reg => reg_8
  # DEBUG BEGIN_STMT
  _3 = reg_8 & 2;
  _4 = _3 != 0;
  _5 = (unsigned char) _4;
  *en_9(D) = _5;
  return;

}



;; Function pfe_emac_cfg_get_rx_flow_control (pfe_emac_cfg_get_rx_flow_control, funcdef_no=45, decl_uid=9308, cgraph_uid=46, symbol_order=47)

Modification phase of node pfe_emac_cfg_get_rx_flow_control/47
pfe_emac_cfg_get_rx_flow_control (addr_t base_va, bool_t * en)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  _Bool _3;
  unsigned char _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_5(D) + 144;
  _2 = (volatile uint32_t *) _1;
  reg_7 ={v} *_2;
  # DEBUG reg => reg_7
  # DEBUG BEGIN_STMT
  _3 = (_Bool) reg_7;
  _4 = (unsigned char) _3;
  *en_8(D) = _4;
  return;

}



;; Function pfe_emac_cfg_set_tx_flow_control (pfe_emac_cfg_set_tx_flow_control, funcdef_no=46, decl_uid=9299, cgraph_uid=47, symbol_order=48)

Modification phase of node pfe_emac_cfg_set_tx_flow_control/48
pfe_emac_cfg_set_tx_flow_control (addr_t base_va, bool_t en)
{
  uint32_t ii;
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int iftmp.28_7;
  volatile uint32_t * _19;

  <bb 2> [local count: 160524402]:
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0

  <bb 3> [local count: 1073741824]:
  # ii_6 = PHI <0(2), ii_14(11)>
  # DEBUG ii => ii_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_11(D) + 112;
  _2 = (volatile uint32_t *) _1;
  reg_12 ={v} *_2;
  # DEBUG reg => reg_12
  # DEBUG BEGIN_STMT
  oal_time_usleep (100);
  # DEBUG BEGIN_STMT
  ii_14 = ii_6 + 1;
  # DEBUG ii => ii_14
  # DEBUG BEGIN_STMT
  _3 = reg_12 & 1;
  if (_3 != 0)
    goto <bb 4>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 4> [local count: 1014686025]:
  if (ii_14 != 10)
    goto <bb 11>; [90.00%]
  else
    goto <bb 5>; [10.00%]

  <bb 11> [local count: 913217422]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 160524403]:
  # _19 = PHI <_2(3), _2(4)>
  # reg_4 = PHI <reg_12(3), reg_12(4)>
  # ii_5 = PHI <ii_14(3), ii_14(4)>
  # DEBUG BEGIN_STMT
  if (ii_5 == 10)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 32490139]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Flow control is busy, exiting...\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac_csr.c", 1518, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 128034264]:
  # DEBUG BEGIN_STMT
  reg_15 = reg_4 & 4294967293;
  # DEBUG reg => reg_15
  # DEBUG BEGIN_STMT
  if (en_16(D) != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 64017132]:

  <bb 9> [local count: 128034264]:
  # iftmp.28_7 = PHI <2(7), 0(8)>
  reg_17 = iftmp.28_7 | reg_15;
  # DEBUG reg => reg_17
  # DEBUG BEGIN_STMT
  reg_18 = reg_17 | 4026531840;
  # DEBUG reg => reg_18
  # DEBUG BEGIN_STMT
  # DEBUG reg => reg_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_19 ={v} reg_18;

  <bb 10> [local count: 160524403]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_set_rx_flow_control (pfe_emac_cfg_set_rx_flow_control, funcdef_no=47, decl_uid=9302, cgraph_uid=48, symbol_order=49)

Modification phase of node pfe_emac_cfg_set_rx_flow_control/49
pfe_emac_cfg_set_rx_flow_control (addr_t base_va, bool_t en)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int iftmp.29_3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 144;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  reg_7 = reg_6 & 4294967294;
  # DEBUG reg => reg_7
  # DEBUG BEGIN_STMT
  if (en_8(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.29_3 = PHI <1(2), 0(3)>
  reg_9 = iftmp.29_3 | reg_7;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_9;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_mdio_read22 (pfe_emac_cfg_mdio_read22, funcdef_no=48, decl_uid=9313, cgraph_uid=49, symbol_order=50)

Modification phase of node pfe_emac_cfg_mdio_read22/50
pfe_emac_cfg_mdio_read22 (addr_t base_va, uint8_t pa, uint8_t ra, uint16_t * val)
{
  errno_t ret;
  uint32_t timeout;
  uint32_t reg;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  long unsigned int _10;
  unsigned int _11;
  volatile uint32_t * _12;
  short unsigned int _13;

  <bb 2> [local count: 69202660]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 500
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) ra_19(D);
  _2 = _1 << 16;
  _3 = _2 & 2031616;
  _4 = (long unsigned int) pa_20(D);
  _5 = _4 << 21;
  _6 = _5 & 65011712;
  _7 = _3 | _6;
  reg_21 = _7 | 1549;
  # DEBUG reg => reg_21
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = base_va_22(D) + 512;
  _9 = (volatile uint32_t *) _8;
  *_9 ={v} reg_21;

  <bb 3> [local count: 1073741824]:
  # timeout_14 = PHI <500(2), timeout_26(8)>
  # DEBUG timeout => timeout_14
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  reg_25 ={v} *_9;
  # DEBUG reg => reg_25
  # DEBUG BEGIN_STMT
  if (timeout_14 == 0)
    goto <bb 5>; [1.00%]
  else
    goto <bb 4>; [99.00%]

  <bb 4> [local count: 1063004405]:
  # DEBUG BEGIN_STMT
  timeout_26 = timeout_14 + 4294967295;
  # DEBUG timeout => timeout_26
  # DEBUG BEGIN_STMT
  oal_time_usleep (10);
  # DEBUG BEGIN_STMT
  _10 = reg_25 & 1;
  if (_10 != 0)
    goto <bb 8>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 8> [local count: 1004539164]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 69202660]:
  # ret_15 = PHI <62(3), 0(4)>
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  if (ret_15 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 34601330]:
  # DEBUG BEGIN_STMT
  _11 = base_va_22(D) + 516;
  _12 = (volatile uint32_t *) _11;
  reg_28 ={v} *_12;
  # DEBUG reg => reg_28
  # DEBUG BEGIN_STMT
  _13 = (short unsigned int) reg_28;
  *val_29(D) = _13;

  <bb 7> [local count: 69202660]:
  # DEBUG BEGIN_STMT
  return ret_15;

}



;; Function pfe_emac_cfg_mdio_read45 (pfe_emac_cfg_mdio_read45, funcdef_no=49, decl_uid=9319, cgraph_uid=50, symbol_order=51)

Modification phase of node pfe_emac_cfg_mdio_read45/51
pfe_emac_cfg_mdio_read45 (addr_t base_va, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t * val)
{
  errno_t ret;
  uint32_t timeout;
  uint32_t reg;
  long unsigned int _1;
  unsigned int _2;
  volatile uint32_t * _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned int _11;
  volatile uint32_t * _12;
  long unsigned int _13;
  long unsigned int _14;
  short unsigned int _15;

  <bb 2> [local count: 69202660]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 500
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) ra_20(D);
  reg_21 = _1 << 16;
  # DEBUG reg => reg_21
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = base_va_22(D) + 516;
  _3 = (volatile uint32_t *) _2;
  *_3 ={v} reg_21;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = (long unsigned int) dev_25(D);
  _5 = _4 << 16;
  _6 = _5 & 2031616;
  _7 = (long unsigned int) pa_26(D);
  _8 = _7 << 21;
  _9 = _8 & 65011712;
  _10 = _6 | _9;
  reg_27 = _10 | 1551;
  # DEBUG reg => reg_27
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = base_va_22(D) + 512;
  _12 = (volatile uint32_t *) _11;
  *_12 ={v} reg_27;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  timeout_29 = timeout_16 + 4294967295;
  # DEBUG timeout => timeout_29
  if (timeout_16 == 0)
    goto <bb 6>; [1.00%]
  else
    goto <bb 4>; [99.00%]

  <bb 4> [local count: 1004539164]:
  # DEBUG BEGIN_STMT
  oal_time_usleep (10);

  <bb 5> [local count: 1073741824]:
  # timeout_16 = PHI <500(2), timeout_29(4)>
  # DEBUG timeout => timeout_16
  # DEBUG BEGIN_STMT
  _13 ={v} *_12;
  _14 = _13 & 1;
  if (_14 != 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 69202661]:
  # ret_17 = PHI <62(3), 0(5)>
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  if (ret_17 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 34601330]:
  # DEBUG BEGIN_STMT
  reg_31 ={v} *_3;
  # DEBUG reg => reg_31
  # DEBUG BEGIN_STMT
  _15 = (short unsigned int) reg_31;
  *val_32(D) = _15;

  <bb 8> [local count: 69202661]:
  # DEBUG BEGIN_STMT
  return ret_17;

}



;; Function pfe_emac_cfg_mdio_write22 (pfe_emac_cfg_mdio_write22, funcdef_no=50, decl_uid=9324, cgraph_uid=51, symbol_order=52)

Modification phase of node pfe_emac_cfg_mdio_write22/52
pfe_emac_cfg_mdio_write22 (addr_t base_va, uint8_t pa, uint8_t ra, uint16_t val)
{
  errno_t ret;
  uint32_t timeout;
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  unsigned int _10;
  volatile uint32_t * _11;
  long unsigned int _12;
  long unsigned int _13;

  <bb 2> [local count: 69202660]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 500
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  reg_18 = (uint32_t) val_17(D);
  # DEBUG reg => reg_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_19(D) + 516;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} reg_18;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = (long unsigned int) ra_22(D);
  _4 = _3 << 16;
  _5 = _4 & 2031616;
  _6 = (long unsigned int) pa_23(D);
  _7 = _6 << 21;
  _8 = _7 & 65011712;
  _9 = _5 | _8;
  reg_24 = _9 | 1541;
  # DEBUG reg => reg_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = base_va_19(D) + 512;
  _11 = (volatile uint32_t *) _10;
  *_11 ={v} reg_24;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  timeout_26 = timeout_14 + 4294967295;
  # DEBUG timeout => timeout_26
  if (timeout_14 == 0)
    goto <bb 6>; [1.00%]
  else
    goto <bb 4>; [99.00%]

  <bb 4> [local count: 1004539164]:
  # DEBUG BEGIN_STMT
  oal_time_usleep (10);

  <bb 5> [local count: 1073741824]:
  # timeout_14 = PHI <500(2), timeout_26(4)>
  # DEBUG timeout => timeout_14
  # DEBUG BEGIN_STMT
  _12 ={v} *_11;
  _13 = _12 & 1;
  if (_13 != 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 69202661]:
  # ret_15 = PHI <62(3), 0(5)>
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  return ret_15;

}



;; Function pfe_emac_cfg_mdio_write45 (pfe_emac_cfg_mdio_write45, funcdef_no=51, decl_uid=9330, cgraph_uid=52, symbol_order=53)

Modification phase of node pfe_emac_cfg_mdio_write45/53
pfe_emac_cfg_mdio_write45 (addr_t base_va, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t val)
{
  errno_t ret;
  uint32_t timeout;
  uint32_t reg;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned int _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  unsigned int _13;
  volatile uint32_t * _14;
  long unsigned int _15;
  long unsigned int _16;

  <bb 2> [local count: 69202660]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 500
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) val_20(D);
  _2 = (long unsigned int) ra_21(D);
  _3 = _2 << 16;
  reg_22 = _1 | _3;
  # DEBUG reg => reg_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = base_va_23(D) + 516;
  _5 = (volatile uint32_t *) _4;
  *_5 ={v} reg_22;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = (long unsigned int) dev_26(D);
  _7 = _6 << 16;
  _8 = _7 & 2031616;
  _9 = (long unsigned int) pa_27(D);
  _10 = _9 << 21;
  _11 = _10 & 65011712;
  _12 = _8 | _11;
  reg_28 = _12 | 1543;
  # DEBUG reg => reg_28
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = base_va_23(D) + 512;
  _14 = (volatile uint32_t *) _13;
  *_14 ={v} reg_28;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  timeout_30 = timeout_17 + 4294967295;
  # DEBUG timeout => timeout_30
  if (timeout_17 == 0)
    goto <bb 6>; [1.00%]
  else
    goto <bb 4>; [99.00%]

  <bb 4> [local count: 1004539164]:
  # DEBUG BEGIN_STMT
  oal_time_usleep (10);

  <bb 5> [local count: 1073741824]:
  # timeout_17 = PHI <500(2), timeout_30(4)>
  # DEBUG timeout => timeout_17
  # DEBUG BEGIN_STMT
  _15 ={v} *_14;
  _16 = _15 & 1;
  if (_16 != 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 69202661]:
  # ret_18 = PHI <62(3), 0(5)>
  # DEBUG ret => ret_18
  # DEBUG BEGIN_STMT
  return ret_18;

}



;; Function pfe_emac_cfg_pps0_configure (pfe_emac_cfg_pps0_configure, funcdef_no=52, decl_uid=9335, cgraph_uid=53, symbol_order=54)

Modification phase of node pfe_emac_cfg_pps0_configure/54
pfe_emac_cfg_pps0_configure (addr_t base_va, bool_t mcgr_en, uint8_t trgtmodsel, bool_t flexible_en)
{
  uint32_t regval;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_7(D) + 2928;
  _2 = (volatile uint32_t *) _1;
  regval_9 ={v} *_2;
  # DEBUG regval => regval_9
  # DEBUG BEGIN_STMT
  if (mcgr_en_10(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  regval_12 = regval_9 | 128;
  # DEBUG regval => regval_12
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  regval_11 = regval_9 & 4294967167;
  # DEBUG regval => regval_11

  <bb 5> [local count: 1073741824]:
  # regval_5 = PHI <regval_12(3), regval_11(4)>
  # DEBUG regval => regval_5
  # DEBUG BEGIN_STMT
  regval_13 = regval_5 & 4294967199;
  # DEBUG regval => regval_13
  # DEBUG BEGIN_STMT
  _3 = (long unsigned int) trgtmodsel_14(D);
  _4 = _3 << 5;
  regval_15 = _4 | regval_13;
  # DEBUG regval => regval_15
  # DEBUG BEGIN_STMT
  if (flexible_en_16(D) != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  regval_18 = regval_15 | 16;
  # DEBUG regval => regval_18
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  regval_17 = regval_15 & 4294967279;
  # DEBUG regval => regval_17

  <bb 8> [local count: 1073741824]:
  # regval_6 = PHI <regval_18(6), regval_17(7)>
  # DEBUG regval => regval_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} regval_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_pps_cmd (pfe_emac_cfg_pps_cmd, funcdef_no=53, decl_uid=9338, cgraph_uid=54, symbol_order=55)

Modification phase of node pfe_emac_cfg_pps_cmd/55
pfe_emac_cfg_pps_cmd (addr_t base_va, uint8_t cmd)
{
  uint32_t regval;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 2928;
  _2 = (volatile uint32_t *) _1;
  regval_6 ={v} *_2;
  # DEBUG regval => regval_6
  # DEBUG BEGIN_STMT
  regval_7 = regval_6 & 4294967280;
  # DEBUG regval => regval_7
  # DEBUG BEGIN_STMT
  _3 = (long unsigned int) cmd_8(D);
  regval_9 = _3 | regval_7;
  # DEBUG regval => regval_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} regval_9;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_pps0_set_target_time (pfe_emac_cfg_pps0_set_target_time, funcdef_no=54, decl_uid=9342, cgraph_uid=55, symbol_order=56)

Modification phase of node pfe_emac_cfg_pps0_set_target_time/56
pfe_emac_cfg_pps0_set_target_time (addr_t base_va, uint32_t seconds, uint32_t nanoseconds)
{
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  volatile uint32_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_5(D) + 2948;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} nanoseconds_7(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = base_va_5(D) + 2944;
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} seconds_9(D);
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_pps0_set_period (pfe_emac_cfg_pps0_set_period, funcdef_no=55, decl_uid=9345, cgraph_uid=56, symbol_order=57)

Modification phase of node pfe_emac_cfg_pps0_set_period/57
pfe_emac_cfg_pps0_set_period (addr_t base_va, uint32_t period)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 2952;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} period_5(D);
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_pps0_set_pulse_width (pfe_emac_cfg_pps0_set_pulse_width, funcdef_no=56, decl_uid=9348, cgraph_uid=57, symbol_order=58)

Modification phase of node pfe_emac_cfg_pps0_set_pulse_width/58
pfe_emac_cfg_pps0_set_pulse_width (addr_t base_va, uint32_t pulse_width)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 2956;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} pulse_width_5(D);
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_cfg_get_tx_cnt (pfe_emac_cfg_get_tx_cnt, funcdef_no=57, decl_uid=9350, cgraph_uid=58, symbol_order=59)

Modification phase of node pfe_emac_cfg_get_tx_cnt/59
pfe_emac_cfg_get_tx_cnt (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;
  uint32_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 1816;
  _2 = (volatile uint32_t *) _1;
  _5 ={v} *_2;
  return _5;

}



;; Function pfe_emac_cfg_get_rx_cnt (pfe_emac_cfg_get_rx_cnt, funcdef_no=58, decl_uid=9352, cgraph_uid=59, symbol_order=60)

Modification phase of node pfe_emac_cfg_get_rx_cnt/60
pfe_emac_cfg_get_rx_cnt (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;
  uint32_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 1920;
  _2 = (volatile uint32_t *) _1;
  _5 ={v} *_2;
  return _5;

}



;; Function pfe_emac_cfg_isr (pfe_emac_cfg_isr, funcdef_no=60, decl_uid=9358, cgraph_uid=61, symbol_order=62)

Modification phase of node pfe_emac_cfg_isr/62
pfe_emac_cfg_isr (addr_t base_va, addr_t cbus_base)
{
  uint32_t dpp_fsm_status;
  uint32_t mtl_ecc_status;
  static const pfe_hm_evt_t dpp_fsm_events[25] = {36, 0, 0, 38, 0, 37, 0, 0, 40, 41, 0, 42, 43, 0, 0, 0, 44, 0, 0, 0, 0, 0, 0, 0, 39};
  static const pfe_hm_evt_t mtl_ecc_events[7] = {30, 32, 31, 0, 33, 35, 34};
  uint8_t instance_id;
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  volatile uint32_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  instance_id_8 = pfe_emac_cfg_get_index (base_va_6(D), cbus_base_7(D));
  # DEBUG instance_id => instance_id_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_6(D) + 3276;
  _2 = (volatile uint32_t *) _1;
  mtl_ecc_status_9 ={v} *_2;
  # DEBUG mtl_ecc_status => mtl_ecc_status_9
  # DEBUG BEGIN_STMT
  _3 = base_va_6(D) + 320;
  _4 = (volatile uint32_t *) _3;
  dpp_fsm_status_10 ={v} *_4;
  # DEBUG dpp_fsm_status => dpp_fsm_status_10
  # DEBUG BEGIN_STMT
  pfe_emac_cfg_report_hm_event (instance_id_8, &mtl_ecc_events, 7, mtl_ecc_status_9);
  # DEBUG BEGIN_STMT
  pfe_emac_cfg_report_hm_event (instance_id_8, &dpp_fsm_events, 25, dpp_fsm_status_10);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} mtl_ecc_status_9;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_4 ={v} dpp_fsm_status_10;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}


