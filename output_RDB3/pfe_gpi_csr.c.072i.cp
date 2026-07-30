
IPA constant propagation start:
Determining dynamic type for call: igqos_class_read_entry_data (base_va_2(D), entry_3(D));
  Starting walk at: igqos_class_read_entry_data (base_va_2(D), entry_3(D));
  instance pointer: entry_3(D)  Outer instance pointer: entry_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: igqos_class_prepare_entry_data (base_va_2(D), entry_3(D));
  Starting walk at: igqos_class_prepare_entry_data (base_va_2(D), entry_3(D));
  instance pointer: entry_3(D)  Outer instance pointer: entry_3(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  oal_time_usleep/60:
  Jump functions of caller  pfe_feature_mgr_is_available/59:
  Jump functions of caller  pfe_gpi_cfg_get_special_stats/58:
  Jump functions of caller  pfe_gpi_cfg_get_stat_value/57:
  Jump functions of caller  pfe_gpi_cfg_shp_get_drop_cnt/56:
  Jump functions of caller  pfe_gpi_cfg_shp_get_limits/55:
  Jump functions of caller  pfe_gpi_cfg_shp_set_limits/54:
  Jump functions of caller  pfe_gpi_cfg_shp_get_isl_weight/53:
  Jump functions of caller  pfe_gpi_cfg_shp_set_isl_weight/52:
  Jump functions of caller  pfe_gpi_cfg_shp_get_mode/51:
  Jump functions of caller  pfe_gpi_cfg_shp_set_mode/50:
  Jump functions of caller  pfe_gpi_cfg_shp_get_type/49:
  Jump functions of caller  pfe_gpi_cfg_shp_set_type/48:
  Jump functions of caller  pfe_gpi_cfg_shp_is_enabled/47:
  Jump functions of caller  pfe_gpi_cfg_shp_disable/46:
  Jump functions of caller  pfe_gpi_cfg_shp_enable/45:
  Jump functions of caller  pfe_gpi_cfg_shp_default_init/44:
    callsite  pfe_gpi_cfg_shp_default_init/44 -> pfe_gpi_cfg_shp_set_mode/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_gpi_cfg_shp_default_init/44 -> pfe_gpi_cfg_shp_set_type/48 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_get_sys_clk_mhz/43:
  Jump functions of caller  pfe_gpi_cfg_wred_get_thr/42:
  Jump functions of caller  pfe_gpi_cfg_wred_set_thr/41:
  Jump functions of caller  pfe_gpi_cfg_wred_get_prob/40:
  Jump functions of caller  pfe_gpi_cfg_wred_set_prob/39:
  Jump functions of caller  pfe_gpi_cfg_wred_is_enabled/38:
    callsite  pfe_gpi_cfg_wred_is_enabled/38 -> igqos_wred_queue_enable_bit/13 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_wred_disable/37:
    callsite  pfe_gpi_cfg_wred_disable/37 -> igqos_wred_queue_enable_bit/13 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_wred_enable/36:
    callsite  pfe_gpi_cfg_wred_enable/36 -> igqos_wred_queue_enable_bit/13 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_wred_default_init/35:
  Jump functions of caller  pfe_gpi_cfg_qos_entry_ready/34:
  Jump functions of caller  pfe_gpi_cfg_qos_rd_fl_entry_resp/33:
    callsite  pfe_gpi_cfg_qos_rd_fl_entry_resp/33 -> igqos_class_read_entry_data/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_qos_rd_fl_entry_req/32:
    callsite  pfe_gpi_cfg_qos_rd_fl_entry_req/32 -> igqos_class_read_flow_cmd/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_qos_clear_lru_entry_req/31:
    callsite  pfe_gpi_cfg_qos_clear_lru_entry_req/31 -> igqos_class_write_lru_cmd/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_cfg_qos_clear_lru_entry_req/31 -> igqos_class_clear_entry_data/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_qos_clear_flow_entry_req/30:
    callsite  pfe_gpi_cfg_qos_clear_flow_entry_req/30 -> igqos_class_write_flow_cmd/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_cfg_qos_clear_flow_entry_req/30 -> igqos_class_clear_entry_data/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_qos_write_flow_entry_req/29:
    callsite  pfe_gpi_cfg_qos_write_flow_entry_req/29 -> igqos_class_write_flow_cmd/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_cfg_qos_write_flow_entry_req/29 -> igqos_class_prepare_entry_data/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_qos_is_enabled/28:
  Jump functions of caller  pfe_gpi_cfg_qos_disable/27:
  Jump functions of caller  pfe_gpi_cfg_qos_enable/26:
  Jump functions of caller  pfe_gpi_cfg_qos_default_init/25:
    callsite  pfe_gpi_cfg_qos_default_init/25 -> pfe_gpi_cfg_shp_default_init/44 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_gpi_cfg_qos_default_init/25 -> pfe_gpi_cfg_shp_default_init/44 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_gpi_cfg_qos_default_init/25 -> pfe_gpi_cfg_wred_default_init/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_cfg_disable/24:
  Jump functions of caller  pfe_gpi_cfg_enable/23:
  Jump functions of caller  pfe_gpi_cfg_reset/22:
  Jump functions of caller  pfe_gpi_cfg_init/21:
  Jump functions of caller  igqos_class_write_lru_cmd/20:
    callsite  igqos_class_write_lru_cmd/20 -> igqos_class_request_entry_cmd/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  igqos_class_read_flow_cmd/19:
  Jump functions of caller  igqos_class_write_flow_cmd/18:
  Jump functions of caller  igqos_class_request_entry_cmd/17:
  Jump functions of caller  igqos_class_clear_entry_data/16:
  Jump functions of caller  igqos_class_prepare_entry_data/15:
  Jump functions of caller  igqos_class_read_entry_data/14:
  Jump functions of caller  igqos_wred_queue_enable_bit/13:

 Propagating constants:

Not considering pfe_gpi_cfg_get_special_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_get_stat_value for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_get_drop_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_get_limits for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_set_limits for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_get_isl_weight for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_set_isl_weight for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_get_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_set_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_get_type for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_set_type for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_is_enabled for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_shp_default_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_get_sys_clk_mhz for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_wred_get_thr for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_wred_set_thr for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_wred_get_prob for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_wred_set_prob for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_wred_is_enabled for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_wred_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_wred_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_wred_default_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_entry_ready for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_rd_fl_entry_resp for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_rd_fl_entry_req for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_clear_lru_entry_req for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_clear_flow_entry_req for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_write_flow_entry_req for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_is_enabled for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_qos_default_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_reset for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_cfg_init for cloning; -fipa-cp-clone disabled.

overall_size: 601, max_new_size: 11001
 - context independent values, size: 7, time_benefit: 6.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_gpi_cfg_get_special_stats/58:
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
  Node: pfe_gpi_cfg_get_stat_value/57:
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
  Node: pfe_gpi_cfg_shp_get_drop_cnt/56:
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
  Node: pfe_gpi_cfg_shp_get_limits/55:
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
  Node: pfe_gpi_cfg_shp_set_limits/54:
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
  Node: pfe_gpi_cfg_shp_get_isl_weight/53:
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
  Node: pfe_gpi_cfg_shp_set_isl_weight/52:
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
  Node: pfe_gpi_cfg_shp_get_mode/51:
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
  Node: pfe_gpi_cfg_shp_set_mode/50:
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
  Node: pfe_gpi_cfg_shp_get_type/49:
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
  Node: pfe_gpi_cfg_shp_set_type/48:
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
  Node: pfe_gpi_cfg_shp_is_enabled/47:
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
  Node: pfe_gpi_cfg_shp_disable/46:
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
  Node: pfe_gpi_cfg_shp_enable/45:
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
  Node: pfe_gpi_cfg_shp_default_init/44:
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
  Node: pfe_gpi_cfg_get_sys_clk_mhz/43:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_wred_get_thr/42:
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
  Node: pfe_gpi_cfg_wred_set_thr/41:
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
  Node: pfe_gpi_cfg_wred_get_prob/40:
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
  Node: pfe_gpi_cfg_wred_set_prob/39:
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
  Node: pfe_gpi_cfg_wred_is_enabled/38:
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
  Node: pfe_gpi_cfg_wred_disable/37:
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
  Node: pfe_gpi_cfg_wred_enable/36:
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
  Node: pfe_gpi_cfg_wred_default_init/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_qos_entry_ready/34:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_qos_rd_fl_entry_resp/33:
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
  Node: pfe_gpi_cfg_qos_rd_fl_entry_req/32:
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
  Node: pfe_gpi_cfg_qos_clear_lru_entry_req/31:
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
  Node: pfe_gpi_cfg_qos_clear_flow_entry_req/30:
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
  Node: pfe_gpi_cfg_qos_write_flow_entry_req/29:
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
  Node: pfe_gpi_cfg_qos_is_enabled/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_qos_disable/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_qos_enable/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_qos_default_init/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_disable/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_enable/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_reset/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_cfg_init/21:
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
  Node: igqos_class_write_lru_cmd/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_read_flow_cmd/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_write_flow_cmd/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_request_entry_cmd/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         bool_t [1, 1]
        AGGS VARIABLE
    param [2]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         bool_t [1, 1]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_clear_entry_data/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_prepare_entry_data/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_read_entry_data/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_wred_queue_enable_bit/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of igqos_class_request_entry_cmd/17 for all known contexts.
    replacing param #1 write with const 1
    replacing param #2 is_lru with const 1
Propagated bits info for function igqos_class_request_entry_cmd.constprop/70:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x1, mask = 0x0
Propagated bits info for function igqos_class_request_entry_cmd/17:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x1, mask = 0x0

IPA constant propagation end

Reclaiming functions: igqos_class_request_entry_cmd/17
Reclaiming variables:
Clearing address taken flags:
Symbol table:

igqos_class_request_entry_cmd.constprop.0/70 (igqos_class_request_entry_cmd.constprop) @07362460
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of igqos_class_request_entry_cmd/17
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: igqos_class_write_lru_cmd/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_time_usleep/60 (oal_time_usleep) @076799a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_cfg_reset/22 (1073741824 (estimated locally),9.78 per call) 
  Calls: 
pfe_feature_mgr_is_available/59 (pfe_feature_mgr_is_available) @076791c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_cfg_init/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_get_special_stats/58 (pfe_gpi_cfg_get_special_stats) @07679b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_get_stat_value/57 (pfe_gpi_cfg_get_stat_value) @076798c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_get_drop_cnt/56 (pfe_gpi_cfg_shp_get_drop_cnt) @07679540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_get_limits/55 (pfe_gpi_cfg_shp_get_limits) @076790e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_set_limits/54 (pfe_gpi_cfg_shp_set_limits) @07673d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_get_isl_weight/53 (pfe_gpi_cfg_shp_get_isl_weight) @07673620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_set_isl_weight/52 (pfe_gpi_cfg_shp_set_isl_weight) @076730e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_get_mode/51 (pfe_gpi_cfg_shp_get_mode) @0766dc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_set_mode/50 (pfe_gpi_cfg_shp_set_mode) @0766d8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_gpi_cfg_shp_default_init/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_shp_get_type/49 (pfe_gpi_cfg_shp_get_type) @0766d460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_set_type/48 (pfe_gpi_cfg_shp_set_type) @0766d0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_gpi_cfg_shp_default_init/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_shp_is_enabled/47 (pfe_gpi_cfg_shp_is_enabled) @076671c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_disable/46 (pfe_gpi_cfg_shp_disable) @07667b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_enable/45 (pfe_gpi_cfg_shp_enable) @07667620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_shp_default_init/44 (pfe_gpi_cfg_shp_default_init) @076670e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_gpi_cfg_qos_default_init/25 (1073741824 (estimated locally),1.00 per call) pfe_gpi_cfg_qos_default_init/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_gpi_cfg_shp_set_mode/50 (1073741824 (estimated locally),1.00 per call) pfe_gpi_cfg_shp_set_type/48 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_get_sys_clk_mhz/43 (pfe_gpi_cfg_get_sys_clk_mhz) @07661b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_wred_get_thr/42 (pfe_gpi_cfg_wred_get_thr) @076618c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_wred_set_thr/41 (pfe_gpi_cfg_wred_set_thr) @076610e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_wred_get_prob/40 (pfe_gpi_cfg_wred_get_prob) @0765b9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_wred_set_prob/39 (pfe_gpi_cfg_wred_set_prob) @0765b540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_wred_is_enabled/38 (pfe_gpi_cfg_wred_is_enabled) @0765b000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_wred_queue_enable_bit/13 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_wred_disable/37 (pfe_gpi_cfg_wred_disable) @07652ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_wred_queue_enable_bit/13 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_wred_enable/36 (pfe_gpi_cfg_wred_enable) @07652a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_wred_queue_enable_bit/13 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_wred_default_init/35 (pfe_gpi_cfg_wred_default_init) @07652620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_gpi_cfg_qos_default_init/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_qos_entry_ready/34 (pfe_gpi_cfg_qos_entry_ready) @0764e380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_qos_rd_fl_entry_resp/33 (pfe_gpi_cfg_qos_rd_fl_entry_resp) @0764ed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_class_read_entry_data/14 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_qos_rd_fl_entry_req/32 (pfe_gpi_cfg_qos_rd_fl_entry_req) @0764ea80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_class_read_flow_cmd/19 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_qos_clear_lru_entry_req/31 (pfe_gpi_cfg_qos_clear_lru_entry_req) @0764e7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_class_write_lru_cmd/20 (1073741824 (estimated locally),1.00 per call) igqos_class_clear_entry_data/16 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_qos_clear_flow_entry_req/30 (pfe_gpi_cfg_qos_clear_flow_entry_req) @0764e540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_class_write_flow_cmd/18 (1073741824 (estimated locally),1.00 per call) igqos_class_clear_entry_data/16 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_qos_write_flow_entry_req/29 (pfe_gpi_cfg_qos_write_flow_entry_req) @0764e2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_class_write_flow_cmd/18 (1073741824 (estimated locally),1.00 per call) igqos_class_prepare_entry_data/15 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_qos_is_enabled/28 (pfe_gpi_cfg_qos_is_enabled) @0764e000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_qos_disable/27 (pfe_gpi_cfg_qos_disable) @076462a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_qos_enable/26 (pfe_gpi_cfg_qos_enable) @07646b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_qos_default_init/25 (pfe_gpi_cfg_qos_default_init) @07646700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_default_init/44 (1073741824 (estimated locally),1.00 per call) pfe_gpi_cfg_shp_default_init/44 (1073741824 (estimated locally),1.00 per call) pfe_gpi_cfg_wred_default_init/35 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_cfg_disable/24 (pfe_gpi_cfg_disable) @076461c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_enable/23 (pfe_gpi_cfg_enable) @0763d700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_gpi_cfg_reset/22 (pfe_gpi_cfg_reset) @0763db60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:109790102 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_time_usleep/60 (1073741824 (estimated locally),9.78 per call) 
pfe_gpi_cfg_init/21 (pfe_gpi_cfg_init) @0763d620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_feature_mgr_is_available/59 (1073741824 (estimated locally),1.00 per call) 
igqos_class_write_lru_cmd/20 (igqos_class_write_lru_cmd) @075ef540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_cfg_qos_clear_lru_entry_req/31 (1073741824 (estimated locally),1.00 per call) 
  Calls: igqos_class_request_entry_cmd.constprop/70 (1073741824 (estimated locally),1.00 per call) 
igqos_class_read_flow_cmd/19 (igqos_class_read_flow_cmd) @075ef2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_cfg_qos_rd_fl_entry_req/32 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igqos_class_write_flow_cmd/18 (igqos_class_write_flow_cmd) @075ef000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_cfg_qos_clear_flow_entry_req/30 (1073741824 (estimated locally),1.00 per call) pfe_gpi_cfg_qos_write_flow_entry_req/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igqos_class_request_entry_cmd/17 (igqos_class_request_entry_cmd) @075e99a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
igqos_class_clear_entry_data/16 (igqos_class_clear_entry_data) @075e9d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:119292716 (estimated locally) body local optimize_size
  Called by: pfe_gpi_cfg_qos_clear_lru_entry_req/31 (1073741824 (estimated locally),1.00 per call) pfe_gpi_cfg_qos_clear_flow_entry_req/30 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igqos_class_prepare_entry_data/15 (igqos_class_prepare_entry_data) @075e98c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:119292716 (estimated locally) body local optimize_size
  Called by: pfe_gpi_cfg_qos_write_flow_entry_req/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igqos_class_read_entry_data/14 (igqos_class_read_entry_data) @075e9460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:119292716 (estimated locally) body local optimize_size
  Called by: pfe_gpi_cfg_qos_rd_fl_entry_resp/33 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igqos_wred_queue_enable_bit/13 (igqos_wred_queue_enable_bit) @075e9000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_cfg_wred_is_enabled/38 (1073741824 (estimated locally),1.00 per call) pfe_gpi_cfg_wred_disable/37 (1073741824 (estimated locally),1.00 per call) pfe_gpi_cfg_wred_enable/36 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function pfe_gpi_cfg_init (pfe_gpi_cfg_init, funcdef_no=19, decl_uid=9446, cgraph_uid=20, symbol_order=21)

Modification phase of node pfe_gpi_cfg_init/21
pfe_gpi_cfg_init (addr_t base_va, const struct pfe_gpi_cfg_t * cfg)
{
  uint32_t regval;
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned char _3;
  long unsigned int _4;
  long unsigned int _5;
  unsigned int _6;
  volatile uint32_t * _7;
  long unsigned int _8;
  short unsigned int _9;
  long unsigned int _10;
  unsigned int _11;
  volatile uint32_t * _12;
  long unsigned int _13;
  unsigned int _14;
  volatile uint32_t * _15;
  unsigned int _16;
  volatile uint32_t * _17;
  unsigned int _18;
  volatile uint32_t * _19;
  unsigned int _20;
  volatile uint32_t * _21;
  unsigned int _22;
  volatile uint32_t * _23;
  unsigned int _24;
  volatile uint32_t * _25;
  unsigned int _26;
  volatile uint32_t * _27;
  unsigned int _28;
  volatile uint32_t * _29;
  unsigned int _30;
  volatile uint32_t * _31;
  unsigned int _32;
  volatile uint32_t * _33;
  long unsigned int _34;
  unsigned int _35;
  volatile uint32_t * _36;
  long unsigned int _37;
  unsigned int _38;
  volatile uint32_t * _39;
  unsigned char _40;
  unsigned char _41;
  unsigned int _42;
  volatile uint32_t * _43;
  unsigned int _44;
  volatile uint32_t * _45;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_48(D) + 316;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = cfg_51(D)->emac_1588_ts_en;
  if (_3 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} 3585;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = cfg_51(D)->alloc_retry_cycles;
  _5 = _4 << 16;
  _6 = base_va_48(D) + 8;
  _7 = (volatile uint32_t *) _6;
  _8 = _5 | 3;
  *_7 ={v} _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = cfg_51(D)->lmem_header_size;
  _10 = (long unsigned int) _9;
  _11 = base_va_48(D) + 12;
  _12 = (volatile uint32_t *) _11;
  _13 = _10 | 33554432;
  *_12 ={v} _13;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = base_va_48(D) + 16;
  _15 = (volatile uint32_t *) _14;
  *_15 ={v} 134217984;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = base_va_48(D) + 20;
  _17 = (volatile uint32_t *) _16;
  *_17 ={v} 3221782576;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _18 = base_va_48(D) + 24;
  _19 = (volatile uint32_t *) _18;
  *_19 ={v} 3221782580;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = base_va_48(D) + 28;
  _21 = (volatile uint32_t *) _20;
  *_21 ={v} 3221798960;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 = base_va_48(D) + 32;
  _23 = (volatile uint32_t *) _22;
  *_23 ={v} 3221798964;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _24 = base_va_48(D) + 36;
  _25 = (volatile uint32_t *) _24;
  *_25 ={v} 3221815312;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _26 = base_va_48(D) + 52;
  _27 = (volatile uint32_t *) _26;
  *_27 ={v} 512;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _28 = base_va_48(D) + 56;
  _29 = (volatile uint32_t *) _28;
  *_29 ={v} 48;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _30 = base_va_48(D) + 96;
  _31 = (volatile uint32_t *) _30;
  *_31 ={v} _10;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _32 = base_va_48(D) + 76;
  _33 = (volatile uint32_t *) _32;
  _34 = cfg_51(D)->gpi_tmlf_txthres;
  *_33 ={v} _34;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _35 = base_va_48(D) + 80;
  _36 = (volatile uint32_t *) _35;
  _37 = cfg_51(D)->gpi_dtx_aseq_len;
  *_36 ={v} _37;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _38 = base_va_48(D) + 104;
  _39 = (volatile uint32_t *) _38;
  *_39 ={v} 1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _40 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  if (_40 == 1)
    goto <bb 6>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 708669605]:
  _41 = cfg_51(D)->g2_ordered_class_writes;
  if (_41 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  _42 = base_va_48(D) + 332;
  _43 = (volatile uint32_t *) _42;
  regval_68 ={v} *_43;
  # DEBUG regval => regval_68
  # DEBUG BEGIN_STMT
  regval_69 = regval_68 | 3;
  # DEBUG regval => regval_69
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_43 ={v} regval_69;

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _44 = base_va_48(D) + 520;
  _45 = (volatile uint32_t *) _44;
  *_45 ={v} 4294967295;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_reset (pfe_gpi_cfg_reset, funcdef_no=20, decl_uid=9448, cgraph_uid=21, symbol_order=22)

Modification phase of node pfe_gpi_cfg_reset/22
pfe_gpi_cfg_reset (addr_t base_va)
{
  uint32_t reg;
  uint32_t timeout;
  errno_t ret;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _4;

  <bb 2> [local count: 109790102]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 20
  # DEBUG BEGIN_STMT
  _1 = base_va_8(D) + 4;
  _2 = (volatile uint32_t *) _1;
  reg_10 ={v} *_2;
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  reg_11 = reg_10 | 2;
  # DEBUG reg => reg_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_11;

  <bb 3> [local count: 1073741824]:
  # timeout_6 = PHI <20(2), timeout_15(8)>
  # DEBUG timeout => timeout_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oal_time_usleep (100);
  # DEBUG BEGIN_STMT
  reg_14 ={v} *_2;
  # DEBUG reg => reg_14
  # DEBUG BEGIN_STMT
  timeout_15 = timeout_6 + 4294967295;
  # DEBUG timeout => timeout_15
  # DEBUG BEGIN_STMT
  _4 = reg_14 & 2;
  if (_4 != 0)
    goto <bb 4>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 4> [local count: 1014686025]:
  if (timeout_15 != 0)
    goto <bb 8>; [95.00%]
  else
    goto <bb 5>; [5.00%]

  <bb 8> [local count: 963951724]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 109790101]:
  # timeout_3 = PHI <timeout_15(3), timeout_15(4)>
  # DEBUG BEGIN_STMT
  if (timeout_3 == 0)
    goto <bb 6>; [35.00%]
  else
    goto <bb 7>; [65.00%]

  <bb 6> [local count: 38426536]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 110

  <bb 7> [local count: 109790101]:
  # ret_5 = PHI <0(5), 110(6)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_gpi_cfg_enable (pfe_gpi_cfg_enable, funcdef_no=21, decl_uid=9450, cgraph_uid=22, symbol_order=23)

Modification phase of node pfe_gpi_cfg_enable/23
pfe_gpi_cfg_enable (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 4;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 | 1;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_disable (pfe_gpi_cfg_disable, funcdef_no=22, decl_uid=9452, cgraph_uid=23, symbol_order=24)

Modification phase of node pfe_gpi_cfg_disable/24
pfe_gpi_cfg_disable (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 4;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 & 4294967294;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_qos_enable (pfe_gpi_cfg_qos_enable, funcdef_no=24, decl_uid=9456, cgraph_uid=25, symbol_order=26)

Modification phase of node pfe_gpi_cfg_qos_enable/26
pfe_gpi_cfg_qos_enable (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 372;
  _2 = (volatile uint32_t *) _1;
  reg_5 ={v} *_2;
  # DEBUG reg => reg_5
  # DEBUG BEGIN_STMT
  reg_6 = reg_5 | 1;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_qos_disable (pfe_gpi_cfg_qos_disable, funcdef_no=25, decl_uid=9458, cgraph_uid=26, symbol_order=27)

Modification phase of node pfe_gpi_cfg_qos_disable/27
pfe_gpi_cfg_qos_disable (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 372;
  _2 = (volatile uint32_t *) _1;
  reg_5 ={v} *_2;
  # DEBUG reg => reg_5
  # DEBUG BEGIN_STMT
  reg_6 = reg_5 & 4294967294;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_qos_is_enabled (pfe_gpi_cfg_qos_is_enabled, funcdef_no=26, decl_uid=9460, cgraph_uid=27, symbol_order=28)

Modification phase of node pfe_gpi_cfg_qos_is_enabled/28
pfe_gpi_cfg_qos_is_enabled (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  unsigned char _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 372;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  _3 = reg_6 & 1;
  _7 = (unsigned char) _3;
  # DEBUG ret => _7
  # DEBUG BEGIN_STMT
  return _7;

}



;; Function pfe_gpi_cfg_qos_write_flow_entry_req (pfe_gpi_cfg_qos_write_flow_entry_req, funcdef_no=27, decl_uid=9464, cgraph_uid=28, symbol_order=29)

Modification phase of node pfe_gpi_cfg_qos_write_flow_entry_req/29
pfe_gpi_cfg_qos_write_flow_entry_req (addr_t base_va, uint32_t addr, const uint32_t * entry)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  igqos_class_prepare_entry_data (base_va_2(D), entry_3(D));
  # DEBUG BEGIN_STMT
  igqos_class_write_flow_cmd (base_va_2(D), addr_5(D));
  return;

}



;; Function pfe_gpi_cfg_qos_clear_flow_entry_req (pfe_gpi_cfg_qos_clear_flow_entry_req, funcdef_no=28, decl_uid=9467, cgraph_uid=29, symbol_order=30)

Modification phase of node pfe_gpi_cfg_qos_clear_flow_entry_req/30
pfe_gpi_cfg_qos_clear_flow_entry_req (addr_t base_va, uint32_t addr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  igqos_class_clear_entry_data (base_va_2(D));
  # DEBUG BEGIN_STMT
  igqos_class_write_flow_cmd (base_va_2(D), addr_4(D));
  return;

}



;; Function pfe_gpi_cfg_qos_clear_lru_entry_req (pfe_gpi_cfg_qos_clear_lru_entry_req, funcdef_no=29, decl_uid=9470, cgraph_uid=30, symbol_order=31)

Modification phase of node pfe_gpi_cfg_qos_clear_lru_entry_req/31
pfe_gpi_cfg_qos_clear_lru_entry_req (addr_t base_va, uint32_t addr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  igqos_class_clear_entry_data (base_va_2(D));
  # DEBUG BEGIN_STMT
  igqos_class_write_lru_cmd (base_va_2(D), addr_4(D));
  return;

}



;; Function pfe_gpi_cfg_qos_rd_fl_entry_req (pfe_gpi_cfg_qos_rd_fl_entry_req, funcdef_no=30, decl_uid=9473, cgraph_uid=31, symbol_order=32)

Modification phase of node pfe_gpi_cfg_qos_rd_fl_entry_req/32
pfe_gpi_cfg_qos_rd_fl_entry_req (addr_t base_va, uint32_t addr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  igqos_class_read_flow_cmd (base_va_2(D), addr_3(D));
  return;

}



;; Function pfe_gpi_cfg_qos_rd_fl_entry_resp (pfe_gpi_cfg_qos_rd_fl_entry_resp, funcdef_no=31, decl_uid=9476, cgraph_uid=32, symbol_order=33)

Modification phase of node pfe_gpi_cfg_qos_rd_fl_entry_resp/33
pfe_gpi_cfg_qos_rd_fl_entry_resp (addr_t base_va, uint32_t * entry)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  igqos_class_read_entry_data (base_va_2(D), entry_3(D));
  return;

}



;; Function pfe_gpi_cfg_qos_entry_ready (pfe_gpi_cfg_qos_entry_ready, funcdef_no=32, decl_uid=9478, cgraph_uid=33, symbol_order=34)

Modification phase of node pfe_gpi_cfg_qos_entry_ready/34
pfe_gpi_cfg_qos_entry_ready (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  unsigned char _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 384;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  _3 = reg_6 & 1;
  _7 = (unsigned char) _3;
  # DEBUG ret => _7
  # DEBUG BEGIN_STMT
  return _7;

}



;; Function pfe_gpi_cfg_wred_default_init (pfe_gpi_cfg_wred_default_init, funcdef_no=33, decl_uid=9480, cgraph_uid=34, symbol_order=35)

Modification phase of node pfe_gpi_cfg_wred_default_init/35
pfe_gpi_cfg_wred_default_init (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  volatile uint32_t * _6;
  unsigned int _7;
  volatile uint32_t * _8;
  unsigned int _9;
  volatile uint32_t * _10;
  unsigned int _11;
  volatile uint32_t * _12;
  unsigned int _13;
  volatile uint32_t * _14;
  unsigned int _15;
  volatile uint32_t * _16;
  unsigned int _17;
  volatile uint32_t * _18;
  unsigned int _19;
  volatile uint32_t * _20;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_21(D) + 380;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG val => 65536
  # DEBUG BEGIN_STMT
  # DEBUG val => 98304
  # DEBUG BEGIN_STMT
  # DEBUG val => 99328
  # DEBUG BEGIN_STMT
  # DEBUG val => 99360
  # DEBUG BEGIN_STMT
  # DEBUG val => 99361
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = base_va_21(D) + 336;
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} 99361;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = base_va_21(D) + 348;
  _6 = (volatile uint32_t *) _5;
  *_6 ={v} 99361;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = base_va_21(D) + 360;
  _8 = (volatile uint32_t *) _7;
  *_8 ={v} 99361;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG val => 8192
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = base_va_21(D) + 340;
  _10 = (volatile uint32_t *) _9;
  *_10 ={v} 8192;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG val => 268443632
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = base_va_21(D) + 344;
  _12 = (volatile uint32_t *) _11;
  *_12 ={v} 268443632;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG val => 512
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = base_va_21(D) + 352;
  _14 = (volatile uint32_t *) _13;
  *_14 ={v} 512;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = base_va_21(D) + 364;
  _16 = (volatile uint32_t *) _15;
  *_16 ={v} 512;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG val => 16777712
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _17 = base_va_21(D) + 356;
  _18 = (volatile uint32_t *) _17;
  *_18 ={v} 16777712;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = base_va_21(D) + 368;
  _20 = (volatile uint32_t *) _19;
  *_20 ={v} 16777712;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_wred_enable (pfe_gpi_cfg_wred_enable, funcdef_no=34, decl_uid=9483, cgraph_uid=35, symbol_order=36)

Modification phase of node pfe_gpi_cfg_wred_enable/36
pfe_gpi_cfg_wred_enable (addr_t base_va, pfe_iqos_queue_t queue)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 380;
  _2 = (volatile uint32_t *) _1;
  reg_5 ={v} *_2;
  # DEBUG reg => reg_5
  # DEBUG BEGIN_STMT
  _7 = igqos_wred_queue_enable_bit (queue_6(D));
  reg_8 = reg_5 | _7;
  # DEBUG reg => reg_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_8;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_wred_disable (pfe_gpi_cfg_wred_disable, funcdef_no=35, decl_uid=9486, cgraph_uid=36, symbol_order=37)

Modification phase of node pfe_gpi_cfg_wred_disable/37
pfe_gpi_cfg_wred_disable (addr_t base_va, pfe_iqos_queue_t queue)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 380;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  _3 = igqos_wred_queue_enable_bit (queue_7(D));
  _8 = ~_3;
  reg_9 = reg_6 & _8;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_9;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_wred_is_enabled (pfe_gpi_cfg_wred_is_enabled, funcdef_no=36, decl_uid=9489, cgraph_uid=37, symbol_order=38)

Modification phase of node pfe_gpi_cfg_wred_is_enabled/38
pfe_gpi_cfg_wred_is_enabled (addr_t base_va, pfe_iqos_queue_t queue)
{
  uint32_t reg;
  uint32_t wred_q_en;
  bool_t ret;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  wred_q_en_7 = igqos_wred_queue_enable_bit (queue_6(D));
  # DEBUG wred_q_en => wred_q_en_7
  # DEBUG BEGIN_STMT
  _1 = base_va_8(D) + 380;
  _2 = (volatile uint32_t *) _1;
  reg_9 ={v} *_2;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  _3 = wred_q_en_7 & reg_9;
  if (_3 == wred_q_en_7)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1

  <bb 4> [local count: 1073741824]:
  # ret_4 = PHI <0(2), 1(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_gpi_cfg_wred_set_prob (pfe_gpi_cfg_wred_set_prob, funcdef_no=37, decl_uid=9494, cgraph_uid=38, symbol_order=39)

Modification phase of node pfe_gpi_cfg_wred_set_prob/39
pfe_gpi_cfg_wred_set_prob (addr_t base_va, pfe_iqos_queue_t queue, pfe_iqos_wred_zone_t zone, uint8_t val)
{
  uint32_t reg;
  const addr_t reg_offset;
  long unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned char _21;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) queue_11(D);
  _2 = _1 * 12;
  reg_offset_12 = _2 + 336;
  # DEBUG reg_offset => reg_offset_12
  # DEBUG BEGIN_STMT
  _3 = reg_offset_12 + base_va_13(D);
  _4 = (volatile uint32_t *) _3;
  reg_15 ={v} *_4;
  # DEBUG reg => reg_15
  # DEBUG BEGIN_STMT
  _5 = (unsigned int) zone_16(D);
  _6 = _5 * 4;
  _7 = 15 << _6;
  _8 = ~_7;
  reg_17 = _8 & reg_15;
  # DEBUG reg => reg_17
  # DEBUG BEGIN_STMT
  _21 = val_18(D) & 15;
  _9 = (long unsigned int) _21;
  _10 = _9 << _6;
  reg_19 = _10 | reg_17;
  # DEBUG reg => reg_19
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_4 ={v} reg_19;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_wred_get_prob (pfe_gpi_cfg_wred_get_prob, funcdef_no=38, decl_uid=9499, cgraph_uid=39, symbol_order=40)

Modification phase of node pfe_gpi_cfg_wred_get_prob/40
pfe_gpi_cfg_wred_get_prob (addr_t base_va, pfe_iqos_queue_t queue, pfe_iqos_wred_zone_t zone, uint8_t * val)
{
  uint32_t reg;
  const addr_t reg_offset;
  long unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  unsigned int _6;
  unsigned char _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) queue_8(D);
  _2 = _1 * 12;
  reg_offset_9 = _2 + 336;
  # DEBUG reg_offset => reg_offset_9
  # DEBUG BEGIN_STMT
  _3 = reg_offset_9 + base_va_10(D);
  _4 = (volatile uint32_t *) _3;
  reg_12 ={v} *_4;
  # DEBUG reg => reg_12
  # DEBUG BEGIN_STMT
  _5 = (unsigned int) zone_13(D);
  _6 = _5 * 4;
  reg_14 = reg_12 >> _6;
  # DEBUG reg => reg_14
  # DEBUG BEGIN_STMT
  reg_15 = reg_14 & 15;
  # DEBUG reg => reg_15
  # DEBUG BEGIN_STMT
  _7 = (unsigned char) reg_15;
  *val_16(D) = _7;
  return;

}



;; Function pfe_gpi_cfg_wred_set_thr (pfe_gpi_cfg_wred_set_thr, funcdef_no=39, decl_uid=9504, cgraph_uid=40, symbol_order=41)

Modification phase of node pfe_gpi_cfg_wred_set_thr/41
pfe_gpi_cfg_wred_set_thr (addr_t base_va, pfe_iqos_queue_t queue, pfe_iqos_wred_thr_t thr, uint16_t val)
{
  uint32_t reg;
  const addr_t reg_offset;
  uint32_t reg;
  const addr_t reg_offset;
  const addr_t reg_offset;
  long unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  unsigned int _15;
  volatile uint32_t * _16;
  long unsigned int _17;
  long unsigned int _18;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  switch (thr_20(D)) <default: <L5> [25.00%], case 0: <L1> [25.00%], case 1: <L2> [25.00%], case 2: <L0> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) queue_22(D);
  _2 = _1 * 12;
  reg_offset_23 = _2 + 340;
  # DEBUG reg_offset => reg_offset_23
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_offset_23 + base_va_24(D);
  _4 = (volatile uint32_t *) _3;
  _5 = (long unsigned int) val_25(D);
  *_4 ={v} _5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  _6 = (long unsigned int) queue_22(D);
  _7 = _6 * 12;
  reg_offset_31 = _7 + 344;
  # DEBUG reg_offset => reg_offset_31
  # DEBUG BEGIN_STMT
  _8 = base_va_24(D) + reg_offset_31;
  _9 = (volatile uint32_t *) _8;
  reg_32 ={v} *_9;
  # DEBUG reg => reg_32
  # DEBUG BEGIN_STMT
  _10 = reg_32 & 65535;
  _11 = (long unsigned int) val_25(D);
  _12 = _11 << 16;
  reg_33 = _10 | _12;
  # DEBUG reg => reg_33
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_9 ={v} reg_33;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  _13 = (long unsigned int) queue_22(D);
  _14 = _13 * 12;
  reg_offset_27 = _14 + 344;
  # DEBUG reg_offset => reg_offset_27
  # DEBUG BEGIN_STMT
  _15 = base_va_24(D) + reg_offset_27;
  _16 = (volatile uint32_t *) _15;
  reg_28 ={v} *_16;
  # DEBUG reg => reg_28
  # DEBUG BEGIN_STMT
  _17 = reg_28 & 4294901760;
  _18 = (long unsigned int) val_25(D);
  reg_29 = _17 | _18;
  # DEBUG reg => reg_29
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_16 ={v} reg_29;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L5>:
  return;

}



;; Function pfe_gpi_cfg_wred_get_thr (pfe_gpi_cfg_wred_get_thr, funcdef_no=40, decl_uid=9509, cgraph_uid=41, symbol_order=42)

Modification phase of node pfe_gpi_cfg_wred_get_thr/42
pfe_gpi_cfg_wred_get_thr (addr_t base_va, pfe_iqos_queue_t queue, pfe_iqos_wred_thr_t thr, uint16_t * val)
{
  const uint32_t reg;
  const addr_t reg_offset;
  const uint32_t reg;
  const addr_t reg_offset;
  const uint32_t reg;
  const addr_t reg_offset;
  long unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  short unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  long unsigned int _10;
  short unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  unsigned int _14;
  volatile uint32_t * _15;
  short unsigned int _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  switch (thr_18(D)) <default: <L5> [25.00%], case 0: <L1> [25.00%], case 1: <L2> [25.00%], case 2: <L0> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) queue_20(D);
  _2 = _1 * 12;
  reg_offset_21 = _2 + 340;
  # DEBUG reg_offset => reg_offset_21
  # DEBUG BEGIN_STMT
  _3 = reg_offset_21 + base_va_22(D);
  _4 = (volatile uint32_t *) _3;
  reg_23 ={v} *_4;
  # DEBUG reg => reg_23
  # DEBUG BEGIN_STMT
  _5 = (short unsigned int) reg_23;
  *val_24(D) = _5;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  _6 = (long unsigned int) queue_20(D);
  _7 = _6 * 12;
  reg_offset_29 = _7 + 344;
  # DEBUG reg_offset => reg_offset_29
  # DEBUG BEGIN_STMT
  _8 = base_va_22(D) + reg_offset_29;
  _9 = (volatile uint32_t *) _8;
  reg_30 ={v} *_9;
  # DEBUG reg => reg_30
  # DEBUG BEGIN_STMT
  _10 = reg_30 >> 16;
  _11 = (short unsigned int) _10;
  *val_24(D) = _11;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  _12 = (long unsigned int) queue_20(D);
  _13 = _12 * 12;
  reg_offset_26 = _13 + 344;
  # DEBUG reg_offset => reg_offset_26
  # DEBUG BEGIN_STMT
  _14 = base_va_22(D) + reg_offset_26;
  _15 = (volatile uint32_t *) _14;
  reg_27 ={v} *_15;
  # DEBUG reg => reg_27
  # DEBUG BEGIN_STMT
  _16 = (short unsigned int) reg_27;
  *val_24(D) = _16;
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L5>:
  return;

}



;; Function pfe_gpi_cfg_get_sys_clk_mhz (pfe_gpi_cfg_get_sys_clk_mhz, funcdef_no=41, decl_uid=8639, cgraph_uid=42, symbol_order=43)

Modification phase of node pfe_gpi_cfg_get_sys_clk_mhz/43
pfe_gpi_cfg_get_sys_clk_mhz (addr_t cbus_base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  uint32_t _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = cbus_base_va_4(D) + 606272;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  _6 = _3 & 65535;
  return _6;

}



;; Function pfe_gpi_cfg_shp_enable (pfe_gpi_cfg_shp_enable, funcdef_no=43, decl_uid=9515, cgraph_uid=44, symbol_order=45)

Modification phase of node pfe_gpi_cfg_shp_enable/45
pfe_gpi_cfg_shp_enable (addr_t base_va, uint8_t id)
{
  uint32_t reg;
  const addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_5(D);
  _2 = _1 * 12;
  reg_offset_6 = _2 + 480;
  # DEBUG reg_offset => reg_offset_6
  # DEBUG BEGIN_STMT
  _3 = reg_offset_6 + base_va_7(D);
  _4 = (volatile uint32_t *) _3;
  reg_9 ={v} *_4;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  reg_10 = reg_9 | 1;
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_4 ={v} reg_10;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_shp_disable (pfe_gpi_cfg_shp_disable, funcdef_no=44, decl_uid=9518, cgraph_uid=45, symbol_order=46)

Modification phase of node pfe_gpi_cfg_shp_disable/46
pfe_gpi_cfg_shp_disable (addr_t base_va, uint8_t id)
{
  uint32_t reg;
  const addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_5(D);
  _2 = _1 * 12;
  reg_offset_6 = _2 + 480;
  # DEBUG reg_offset => reg_offset_6
  # DEBUG BEGIN_STMT
  _3 = reg_offset_6 + base_va_7(D);
  _4 = (volatile uint32_t *) _3;
  reg_9 ={v} *_4;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  reg_10 = reg_9 & 4294967294;
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_4 ={v} reg_10;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_shp_is_enabled (pfe_gpi_cfg_shp_is_enabled, funcdef_no=45, decl_uid=9521, cgraph_uid=46, symbol_order=47)

Modification phase of node pfe_gpi_cfg_shp_is_enabled/47
pfe_gpi_cfg_shp_is_enabled (addr_t base_va, uint8_t id)
{
  uint32_t reg;
  const addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  unsigned char _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_6(D);
  _2 = _1 * 12;
  reg_offset_7 = _2 + 480;
  # DEBUG reg_offset => reg_offset_7
  # DEBUG BEGIN_STMT
  _3 = reg_offset_7 + base_va_8(D);
  _4 = (volatile uint32_t *) _3;
  reg_10 ={v} *_4;
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  _5 = reg_10 & 1;
  _11 = (unsigned char) _5;
  # DEBUG ret => _11
  # DEBUG BEGIN_STMT
  return _11;

}



;; Function pfe_gpi_cfg_shp_set_type (pfe_gpi_cfg_shp_set_type, funcdef_no=46, decl_uid=9525, cgraph_uid=47, symbol_order=48)

Modification phase of node pfe_gpi_cfg_shp_set_type/48
pfe_gpi_cfg_shp_set_type (addr_t base_va, uint8_t id, pfe_iqos_shp_type_t type)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  <unnamed type> _18;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_10(D) + 504;
  _2 = (volatile uint32_t *) _1;
  reg_12 ={v} *_2;
  # DEBUG reg => reg_12
  # DEBUG BEGIN_STMT
  _3 = (unsigned int) id_13(D);
  _4 = _3 + 1;
  _5 = _4 * 2;
  _6 = 3 << _5;
  _7 = ~_6;
  reg_14 = _7 & reg_12;
  # DEBUG reg => reg_14
  # DEBUG BEGIN_STMT
  _18 = type_15(D) & 3;
  _8 = (long unsigned int) _18;
  _9 = _8 << _5;
  reg_16 = _9 | reg_14;
  # DEBUG reg => reg_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_16;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_shp_get_type (pfe_gpi_cfg_shp_get_type, funcdef_no=47, decl_uid=9529, cgraph_uid=48, symbol_order=49)

Modification phase of node pfe_gpi_cfg_shp_get_type/49
pfe_gpi_cfg_shp_get_type (addr_t base_va, uint8_t id, pfe_iqos_shp_type_t * type)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_7(D) + 504;
  _2 = (volatile uint32_t *) _1;
  reg_9 ={v} *_2;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  _3 = (unsigned int) id_10(D);
  _4 = _3 + 1;
  _5 = _4 * 2;
  reg_11 = reg_9 >> _5;
  # DEBUG reg => reg_11
  # DEBUG BEGIN_STMT
  reg_12 = reg_11 & 3;
  # DEBUG reg => reg_12
  # DEBUG BEGIN_STMT
  switch (reg_12) <default: <L5> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  *type_13(D) = 0;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  *type_13(D) = 1;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  *type_13(D) = 2;
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L5>:
  return;

}



;; Function pfe_gpi_cfg_shp_set_mode (pfe_gpi_cfg_shp_set_mode, funcdef_no=48, decl_uid=9533, cgraph_uid=49, symbol_order=50)

Modification phase of node pfe_gpi_cfg_shp_set_mode/50
pfe_gpi_cfg_shp_set_mode (addr_t base_va, uint8_t id, pfe_iqos_shp_rate_mode_t mode)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_7(D) + 504;
  _2 = (volatile uint32_t *) _1;
  reg_9 ={v} *_2;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  _3 = (int) id_10(D);
  _4 = 1 << _3;
  _5 = ~_4;
  reg_11 = _5 & reg_9;
  # DEBUG reg => reg_11
  # DEBUG BEGIN_STMT
  if (mode_12(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  reg_13 = _4 | reg_11;
  # DEBUG reg => reg_13

  <bb 4> [local count: 1073741824]:
  # reg_6 = PHI <reg_11(2), reg_13(3)>
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_shp_default_init (pfe_gpi_cfg_shp_default_init, funcdef_no=42, decl_uid=9512, cgraph_uid=43, symbol_order=44)

Modification phase of node pfe_gpi_cfg_shp_default_init/44
pfe_gpi_cfg_shp_default_init (addr_t base_va, uint8_t id)
{
  addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  unsigned int _6;
  volatile uint32_t * _7;
  unsigned int _8;
  volatile uint32_t * _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_10(D);
  _2 = _1 * 12;
  reg_offset_11 = _2 + 484;
  # DEBUG reg_offset => reg_offset_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_offset_11 + base_va_12(D);
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = _1 + 80;
  reg_offset_15 = _5 * 4;
  # DEBUG reg_offset => reg_offset_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = base_va_12(D) + reg_offset_15;
  _7 = (volatile uint32_t *) _6;
  *_7 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_gpi_cfg_shp_set_type (base_va_12(D), id_10(D), 0);
  # DEBUG BEGIN_STMT
  pfe_gpi_cfg_shp_set_mode (base_va_12(D), id_10(D), 0);
  # DEBUG BEGIN_STMT
  reg_offset_19 = _2 + 480;
  # DEBUG reg_offset => reg_offset_19
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = base_va_12(D) + reg_offset_19;
  _9 = (volatile uint32_t *) _8;
  *_9 ={v} 0;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_qos_default_init (pfe_gpi_cfg_qos_default_init, funcdef_no=23, decl_uid=9454, cgraph_uid=24, symbol_order=25)

Modification phase of node pfe_gpi_cfg_qos_default_init/25
pfe_gpi_cfg_qos_default_init (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  volatile uint32_t * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_7(D) + 372;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_gpi_cfg_wred_default_init (base_va_7(D));
  # DEBUG BEGIN_STMT
  pfe_gpi_cfg_shp_default_init (base_va_7(D), 0);
  # DEBUG BEGIN_STMT
  pfe_gpi_cfg_shp_default_init (base_va_7(D), 1);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = base_va_7(D) + 536;
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} 2164293888;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = base_va_7(D) + 376;
  _6 = (volatile uint32_t *) _5;
  *_6 ={v} 48;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_shp_get_mode (pfe_gpi_cfg_shp_get_mode, funcdef_no=49, decl_uid=9537, cgraph_uid=50, symbol_order=51)

Modification phase of node pfe_gpi_cfg_shp_get_mode/51
pfe_gpi_cfg_shp_get_mode (addr_t base_va, uint8_t id, pfe_iqos_shp_rate_mode_t * mode)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_7(D) + 504;
  _2 = (volatile uint32_t *) _1;
  reg_9 ={v} *_2;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  _3 = (int) id_10(D);
  _4 = reg_9 >> _3;
  _5 = _4 & 1;
  if (_5 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  *mode_11(D) = 1;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  *mode_11(D) = 0;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function pfe_gpi_cfg_shp_set_isl_weight (pfe_gpi_cfg_shp_set_isl_weight, funcdef_no=50, decl_uid=9542, cgraph_uid=51, symbol_order=52)

Modification phase of node pfe_gpi_cfg_shp_set_isl_weight/52
pfe_gpi_cfg_shp_set_isl_weight (addr_t base_va, uint8_t id, uint32_t clk_div_log2, uint32_t weight)
{
  uint32_t reg;
  addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_10(D);
  _2 = _1 * 12;
  reg_offset_11 = _2 + 480;
  # DEBUG reg_offset => reg_offset_11
  # DEBUG BEGIN_STMT
  _3 = reg_offset_11 + base_va_12(D);
  _4 = (volatile uint32_t *) _3;
  reg_14 ={v} *_4;
  # DEBUG reg => reg_14
  # DEBUG BEGIN_STMT
  reg_15 = reg_14 & 4294967265;
  # DEBUG reg => reg_15
  # DEBUG BEGIN_STMT
  _5 = clk_div_log2_16(D) << 1;
  _6 = _5 & 30;
  reg_17 = _6 | reg_15;
  # DEBUG reg => reg_17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_4 ={v} reg_17;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  reg_offset_19 = _2 + 484;
  # DEBUG reg_offset => reg_offset_19
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = base_va_12(D) + reg_offset_19;
  _8 = (volatile uint32_t *) _7;
  _9 = weight_20(D) & 2047;
  *_8 ={v} _9;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_shp_get_isl_weight (pfe_gpi_cfg_shp_get_isl_weight, funcdef_no=51, decl_uid=9546, cgraph_uid=52, symbol_order=53)

Modification phase of node pfe_gpi_cfg_shp_get_isl_weight/53
pfe_gpi_cfg_shp_get_isl_weight (addr_t base_va, uint8_t id, uint32_t * weight)
{
  uint32_t reg;
  addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_6(D);
  _2 = _1 * 12;
  reg_offset_7 = _2 + 484;
  # DEBUG reg_offset => reg_offset_7
  # DEBUG BEGIN_STMT
  _3 = reg_offset_7 + base_va_8(D);
  _4 = (volatile uint32_t *) _3;
  reg_10 ={v} *_4;
  # DEBUG reg => reg_10
  # DEBUG BEGIN_STMT
  _5 = reg_10 & 2047;
  *weight_11(D) = _5;
  return;

}



;; Function pfe_gpi_cfg_shp_set_limits (pfe_gpi_cfg_shp_set_limits, funcdef_no=52, decl_uid=9551, cgraph_uid=53, symbol_order=54)

Modification phase of node pfe_gpi_cfg_shp_set_limits/54
pfe_gpi_cfg_shp_set_limits (addr_t base_va, uint8_t id, uint32_t max_credit, uint32_t min_credit)
{
  uint32_t reg;
  addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_11(D);
  _2 = _1 + 128;
  reg_offset_12 = _2 * 4;
  # DEBUG reg_offset => reg_offset_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_offset_12 + base_va_13(D);
  _4 = (volatile uint32_t *) _3;
  _5 = min_credit_14(D) & 4194303;
  *_4 ={v} _5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = _1 * 12;
  reg_offset_17 = _6 + 480;
  # DEBUG reg_offset => reg_offset_17
  # DEBUG BEGIN_STMT
  _7 = base_va_13(D) + reg_offset_17;
  _8 = (volatile uint32_t *) _7;
  reg_18 ={v} *_8;
  # DEBUG reg => reg_18
  # DEBUG BEGIN_STMT
  reg_19 = reg_18 & 3221225727;
  # DEBUG reg => reg_19
  # DEBUG BEGIN_STMT
  _9 = max_credit_20(D) << 8;
  _10 = _9 & 1073741568;
  reg_21 = _10 | reg_19;
  # DEBUG reg => reg_21
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_8 ={v} reg_21;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_cfg_shp_get_limits (pfe_gpi_cfg_shp_get_limits, funcdef_no=53, decl_uid=9556, cgraph_uid=54, symbol_order=55)

Modification phase of node pfe_gpi_cfg_shp_get_limits/55
pfe_gpi_cfg_shp_get_limits (addr_t base_va, uint8_t id, uint32_t * max_credit, uint32_t * min_credit)
{
  uint32_t reg;
  addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  unsigned int _6;
  volatile uint32_t * _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_8(D);
  _2 = _1 + 128;
  reg_offset_9 = _2 * 4;
  # DEBUG reg_offset => reg_offset_9
  # DEBUG BEGIN_STMT
  _3 = reg_offset_9 + base_va_10(D);
  _4 = (volatile uint32_t *) _3;
  reg_12 ={v} *_4;
  # DEBUG reg => reg_12
  # DEBUG BEGIN_STMT
  reg_13 = reg_12 & 4194303;
  # DEBUG reg => reg_13
  # DEBUG BEGIN_STMT
  *min_credit_14(D) = reg_13;
  # DEBUG BEGIN_STMT
  _5 = _1 * 12;
  reg_offset_16 = _5 + 480;
  # DEBUG reg_offset => reg_offset_16
  # DEBUG BEGIN_STMT
  _6 = base_va_10(D) + reg_offset_16;
  _7 = (volatile uint32_t *) _6;
  reg_17 ={v} *_7;
  # DEBUG reg => reg_17
  # DEBUG BEGIN_STMT
  reg_18 = reg_17 >> 8;
  # DEBUG reg => reg_18
  # DEBUG BEGIN_STMT
  reg_19 = reg_18 & 4194303;
  # DEBUG reg => reg_19
  # DEBUG BEGIN_STMT
  *max_credit_20(D) = reg_19;
  return;

}



;; Function pfe_gpi_cfg_shp_get_drop_cnt (pfe_gpi_cfg_shp_get_drop_cnt, funcdef_no=54, decl_uid=9559, cgraph_uid=55, symbol_order=56)

Modification phase of node pfe_gpi_cfg_shp_get_drop_cnt/56
pfe_gpi_cfg_shp_get_drop_cnt (addr_t base_va, uint8_t id)
{
  const addr_t reg_offset;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  uint32_t _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) id_5(D);
  _2 = _1 + 111;
  reg_offset_6 = _2 * 4;
  # DEBUG reg_offset => reg_offset_6
  # DEBUG BEGIN_STMT
  _3 = reg_offset_6 + base_va_7(D);
  _4 = (volatile uint32_t *) _3;
  _9 ={v} *_4;
  return _9;

}



;; Function pfe_gpi_cfg_get_stat_value (pfe_gpi_cfg_get_stat_value, funcdef_no=55, decl_uid=9562, cgraph_uid=56, symbol_order=57)

Modification phase of node pfe_gpi_cfg_get_stat_value/57
pfe_gpi_cfg_get_stat_value (addr_t base_va, uint32_t stat_id)
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



;; Function pfe_gpi_cfg_get_special_stats (pfe_gpi_cfg_get_special_stats, funcdef_no=56, decl_uid=9565, cgraph_uid=57, symbol_order=58)

Modification phase of node pfe_gpi_cfg_get_special_stats/58
pfe_gpi_cfg_get_special_stats (addr_t base_va, struct pfe_gpi_special_stats_t * special_stats)
{
  uint32_t stat_value;
  uint32_t stat_value;
  uint32_t stat_value;
  uint32_t stat_value;
  uint32_t stat_value;
  uint32_t stat_value;
  uint32_t stat_value;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  unsigned int _25;
  volatile uint32_t * _26;
  volatile uint32_t * _30;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_13(D)
  # DEBUG stat_id => 0
  # DEBUG INLINE_ENTRY pfe_gpi_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _30 = (volatile uint32_t *) base_va_13(D);
  stat_value_31 ={v} *_30;
  # DEBUG stat_value => stat_value_31
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _1 = stat_value_31 >> 24;
  special_stats_14(D)->revision = _1;
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_13(D)
  # DEBUG stat_id => 0
  # DEBUG INLINE_ENTRY pfe_gpi_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stat_value_29 ={v} *_30;
  # DEBUG stat_value => stat_value_29
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _2 = stat_value_29 >> 16;
  _3 = _2 & 255;
  special_stats_14(D)->version = _3;
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_13(D)
  # DEBUG stat_id => 0
  # DEBUG INLINE_ENTRY pfe_gpi_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stat_value_28 ={v} *_30;
  # DEBUG stat_value => stat_value_28
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _4 = stat_value_28 & 65535;
  special_stats_14(D)->id = _4;
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_13(D)
  # DEBUG stat_id => 88
  # DEBUG INLINE_ENTRY pfe_gpi_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = base_va_13(D) + 88;
  _26 = (volatile uint32_t *) _25;
  stat_value_27 ={v} *_26;
  # DEBUG stat_value => stat_value_27
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _5 = stat_value_27 & 31;
  special_stats_14(D)->tx_fifo_packets = _5;
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_13(D)
  # DEBUG stat_id => 88
  # DEBUG INLINE_ENTRY pfe_gpi_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stat_value_24 ={v} *_26;
  # DEBUG stat_value => stat_value_24
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _6 = stat_value_24 >> 6;
  _7 = _6 & 31;
  special_stats_14(D)->rx_fifo_packets = _7;
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_13(D)
  # DEBUG stat_id => 88
  # DEBUG INLINE_ENTRY pfe_gpi_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stat_value_23 ={v} *_26;
  # DEBUG stat_value => stat_value_23
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _8 = stat_value_23 >> 12;
  _9 = _8 & 255;
  special_stats_14(D)->tx_fifo_level = _9;
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_13(D)
  # DEBUG stat_id => 88
  # DEBUG INLINE_ENTRY pfe_gpi_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stat_value_22 ={v} *_26;
  # DEBUG stat_value => stat_value_22
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _10 = stat_value_22 >> 20;
  _11 = _10 & 255;
  special_stats_14(D)->rx_fifo_level = _11;
  return;

}


