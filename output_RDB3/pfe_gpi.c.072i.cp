
IPA constant propagation start:
Determining dynamic type for call: igqos_class_clear_active_all (gpi_1(D));
  Starting walk at: igqos_class_clear_active_all (gpi_1(D));
  instance pointer: gpi_1(D)  Outer instance pointer: gpi_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_qos_default_init (_2);
Determining dynamic type for call: _3 = igqos_class_is_active (gpi_1(D), ii_2);
  Starting walk at: _3 = igqos_class_is_active (gpi_1(D), ii_2);
  instance pointer: gpi_1(D)  Outer instance pointer: gpi_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = igqos_find_optimal_weight (isl_15(D), _3, is_bps_7, &weight);
  Starting walk at: _4 = igqos_find_optimal_weight (isl_15(D), _3, is_bps_7, &weight);
  instance pointer: &weight  Outer instance pointer: weight offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_shp_get_mode (_1, id_13(D), &mode);
Determining dynamic type for call: entry_id_6 = igqos_class_get_next_active (gpi_4(D));
  Starting walk at: entry_id_6 = igqos_class_get_next_active (gpi_4(D));
  instance pointer: gpi_4(D)  Outer instance pointer: gpi_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  Starting walk at: ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  instance pointer: gpi_4(D)  Outer instance pointer: gpi_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_id_6 = igqos_class_get_next_active (gpi_4(D));
Determining dynamic type for call: ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  Starting walk at: ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  instance pointer: flow_9(D)  Outer instance pointer: flow_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_id_6 = igqos_class_get_next_active (gpi_4(D));
Determining dynamic type for call: entry_id_6 = igqos_class_get_first_active (gpi_4(D));
  Starting walk at: entry_id_6 = igqos_class_get_first_active (gpi_4(D));
  instance pointer: gpi_4(D)  Outer instance pointer: gpi_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  Starting walk at: ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  instance pointer: gpi_4(D)  Outer instance pointer: gpi_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_id_6 = igqos_class_get_first_active (gpi_4(D));
Determining dynamic type for call: ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  Starting walk at: ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  instance pointer: flow_9(D)  Outer instance pointer: flow_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_id_6 = igqos_class_get_first_active (gpi_4(D));
Determining dynamic type for call: _2 = igqos_flow_entry_validate (flow_10(D));
  Starting walk at: _2 = igqos_flow_entry_validate (flow_10(D));
  instance pointer: flow_10(D)  Outer instance pointer: flow_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: igqos_flow_entry_fixup (flow_10(D));
  Starting walk at: igqos_flow_entry_fixup (flow_10(D));
  instance pointer: flow_10(D)  Outer instance pointer: flow_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: entry_id_13 = igqos_class_find_first_free (gpi_12(D));
  Starting walk at: entry_id_13 = igqos_class_find_first_free (gpi_12(D));
  instance pointer: gpi_12(D)  Outer instance pointer: gpi_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:igqos_flow_entry_fixup (flow_10(D));
Determining dynamic type for call: igqos_convert_flow_to_entry (flow_10(D), &class_table_entry);
  Starting walk at: igqos_convert_flow_to_entry (flow_10(D), &class_table_entry);
  instance pointer: flow_10(D)  Outer instance pointer: flow_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:igqos_flow_entry_fixup (flow_10(D));
Determining dynamic type for call: igqos_convert_flow_to_entry (flow_10(D), &class_table_entry);
  Starting walk at: igqos_convert_flow_to_entry (flow_10(D), &class_table_entry);
  instance pointer: &class_table_entry  Outer instance pointer: class_table_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:igqos_flow_entry_fixup (flow_10(D));
Determining dynamic type for call: ret_17 = igqos_entry_ready_timeout.isra.0 (_20);
  Starting walk at: ret_17 = igqos_entry_ready_timeout.isra.0 (_20);
  instance pointer: _20  Outer instance pointer: gpi_12(D) offset: 64 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_qos_write_flow_entry_req (_3, _4, &class_table_entry);
  Function call may change dynamic type:igqos_convert_flow_to_entry (flow_10(D), &class_table_entry);
  Function call may change dynamic type:igqos_flow_entry_fixup (flow_10(D));
Determining dynamic type for call: igqos_class_set_active (gpi_12(D), entry_id_5);
  Starting walk at: igqos_class_set_active (gpi_12(D), entry_id_5);
  instance pointer: gpi_12(D)  Outer instance pointer: gpi_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_17 = igqos_entry_ready_timeout.isra.0 (_20);
  Function call may change dynamic type:pfe_gpi_cfg_qos_write_flow_entry_req (_3, _4, &class_table_entry);
  Function call may change dynamic type:igqos_convert_flow_to_entry (flow_10(D), &class_table_entry);
  Function call may change dynamic type:igqos_flow_entry_fixup (flow_10(D));
Determining dynamic type for call: _1 = igqos_class_is_active (gpi_8(D), id_6(D));
  Starting walk at: _1 = igqos_class_is_active (gpi_8(D), id_6(D));
  instance pointer: gpi_8(D)  Outer instance pointer: gpi_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_11 = igqos_entry_ready_timeout.isra.0 (_13);
  Starting walk at: ret_11 = igqos_entry_ready_timeout.isra.0 (_13);
  instance pointer: _13  Outer instance pointer: gpi_8(D) offset: 64 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_qos_clear_flow_entry_req (_2, _3);
Determining dynamic type for call: igqos_class_clear_active (gpi_8(D), id_6(D));
  Starting walk at: igqos_class_clear_active (gpi_8(D), id_6(D));
  instance pointer: gpi_8(D)  Outer instance pointer: gpi_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = igqos_entry_ready_timeout.isra.0 (_13);
  Function call may change dynamic type:pfe_gpi_cfg_qos_clear_flow_entry_req (_2, _3);
Determining dynamic type for call: ret_12 = igqos_entry_ready_timeout.isra.0 (_17);
  Starting walk at: ret_12 = igqos_entry_ready_timeout.isra.0 (_17);
  instance pointer: _17  Outer instance pointer: gpi_9(D) offset: 64 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_qos_rd_fl_entry_req (_1, _2);
Determining dynamic type for call: igqos_convert_entry_to_flow (&class_table_entry, flow_14(D));
  Starting walk at: igqos_convert_entry_to_flow (&class_table_entry, flow_14(D));
  instance pointer: &class_table_entry  Outer instance pointer: class_table_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_qos_rd_fl_entry_resp (_3, &class_table_entry);
  Function call may change dynamic type:ret_12 = igqos_entry_ready_timeout.isra.0 (_17);
  Function call may change dynamic type:pfe_gpi_cfg_qos_rd_fl_entry_req (_1, _2);
Determining dynamic type for call: igqos_convert_entry_to_flow (&class_table_entry, flow_14(D));
  Starting walk at: igqos_convert_entry_to_flow (&class_table_entry, flow_14(D));
  instance pointer: flow_14(D)  Outer instance pointer: flow_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_qos_rd_fl_entry_resp (_3, &class_table_entry);
  Function call may change dynamic type:ret_12 = igqos_entry_ready_timeout.isra.0 (_17);
  Function call may change dynamic type:pfe_gpi_cfg_qos_rd_fl_entry_req (_1, _2);
Determining dynamic type for call: ret_10 = pfe_gpi_qos_reset (gpi_7(D));
  Starting walk at: ret_10 = pfe_gpi_qos_reset (gpi_7(D));
  instance pointer: gpi_7(D)  Outer instance pointer: gpi_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_gpi_cfg_qos_is_enabled (_1);
Determining dynamic type for call: ret_7 = igqos_class_clear_flow_entry_table (gpi_3(D));
  Starting walk at: ret_7 = igqos_class_clear_flow_entry_table (gpi_3(D));
  instance pointer: gpi_3(D)  Outer instance pointer: gpi_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_9 = igqos_class_clear_lru_entry_table (gpi_3(D));
  Starting walk at: ret_9 = igqos_class_clear_lru_entry_table (gpi_3(D));
  instance pointer: gpi_3(D)  Outer instance pointer: gpi_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_7 = igqos_class_clear_flow_entry_table (gpi_3(D));
Determining dynamic type for call: ret_4 = pfe_gpi_qos_reset.part.0 (gpi_3(D));
  Starting walk at: ret_4 = pfe_gpi_qos_reset.part.0 (gpi_3(D));
  instance pointer: gpi_3(D)  Outer instance pointer: gpi_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_9 = igqos_class_clear_lru_entry_table (gpi_3(D));
  Function call may change dynamic type:ret_7 = igqos_class_clear_flow_entry_table (gpi_3(D));
Determining dynamic type for call: pfe_gpi_disable (gpi_4(D));
  Starting walk at: pfe_gpi_disable (gpi_4(D));
  instance pointer: gpi_4(D)  Outer instance pointer: gpi_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_8 = pfe_gpi_qos_reset (gpi_4(D));
  Starting walk at: ret_8 = pfe_gpi_qos_reset (gpi_4(D));
  instance pointer: gpi_4(D)  Outer instance pointer: gpi_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_disable (gpi_4(D));
Determining dynamic type for call: ret_12 = pfe_gpi_reset (gpi_4(D));
  Starting walk at: ret_12 = pfe_gpi_reset (gpi_4(D));
  instance pointer: gpi_4(D)  Outer instance pointer: gpi_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_disable (gpi_4(D));
  Function call may change dynamic type:ret_8 = pfe_gpi_qos_reset (gpi_4(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] GPI QOS reset timed-out\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_gpi.c", 910, "");
Determining dynamic type for call: ret_23 = pfe_gpi_reset (gpi_12);
  Starting walk at: ret_23 = pfe_gpi_reset (gpi_12);
  instance pointer: gpi_12  Outer instance pointer: &xxgpi_instance[_4] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = pfe_gpi_cfg_get_sys_clk_mhz (cbus_base_va_15(D));
  Function call may change dynamic type:autolibc_memset (gpi_12, 0, 32);
Determining dynamic type for call: ret_25 = pfe_gpi_qos_reset (gpi_12);
  Starting walk at: ret_25 = pfe_gpi_qos_reset (gpi_12);
  instance pointer: gpi_12  Outer instance pointer: &xxgpi_instance[_4] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_23 = pfe_gpi_reset (gpi_12);
  Function call may change dynamic type:_6 = pfe_gpi_cfg_get_sys_clk_mhz (cbus_base_va_15(D));
  Function call may change dynamic type:autolibc_memset (gpi_12, 0, 32);
Determining dynamic type for call: pfe_gpi_disable (gpi_12);
  Starting walk at: pfe_gpi_disable (gpi_12);
  instance pointer: gpi_12  Outer instance pointer: &xxgpi_instance[_4] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_25 = pfe_gpi_qos_reset (gpi_12);
  Function call may change dynamic type:ret_23 = pfe_gpi_reset (gpi_12);
  Function call may change dynamic type:_6 = pfe_gpi_cfg_get_sys_clk_mhz (cbus_base_va_15(D));
  Function call may change dynamic type:autolibc_memset (gpi_12, 0, 32);
Determining dynamic type for call: igqos_convert_flow_to_entry_reg0123 (flow_25(D), entry_27(D));
  Starting walk at: igqos_convert_flow_to_entry_reg0123 (flow_25(D), entry_27(D));
  instance pointer: flow_25(D)  Outer instance pointer: flow_25(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: igqos_convert_flow_to_entry_reg0123 (flow_25(D), entry_27(D));
  Starting walk at: igqos_convert_flow_to_entry_reg0123 (flow_25(D), entry_27(D));
  instance pointer: entry_27(D)  Outer instance pointer: entry_27(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: igqos_convert_flow_to_entry_reg45 (flow_25(D), entry_27(D));
  Starting walk at: igqos_convert_flow_to_entry_reg45 (flow_25(D), entry_27(D));
  instance pointer: flow_25(D)  Outer instance pointer: flow_25(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:igqos_convert_flow_to_entry_reg0123 (flow_25(D), entry_27(D));
Determining dynamic type for call: igqos_convert_flow_to_entry_reg45 (flow_25(D), entry_27(D));
  Starting walk at: igqos_convert_flow_to_entry_reg45 (flow_25(D), entry_27(D));
  instance pointer: entry_27(D)  Outer instance pointer: entry_27(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:igqos_convert_flow_to_entry_reg0123 (flow_25(D), entry_27(D));
Determining dynamic type for call: ret_7 = igqos_flow_entry_validate_args (flow_6(D));
  Starting walk at: ret_7 = igqos_flow_entry_validate_args (flow_6(D));
  instance pointer: flow_6(D)  Outer instance pointer: flow_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = igqos_class_find_entry (gpi_5(D), _2, 1);
  Starting walk at: _3 = igqos_class_find_entry (gpi_5(D), _2, 1);
  instance pointer: gpi_5(D)  Outer instance pointer: gpi_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_4 = igqos_class_find_entry.part.0 (gpi_2(D), 0, 1);
  Starting walk at: ret_4 = igqos_class_find_entry.part.0 (gpi_2(D), 0, 1);
  instance pointer: gpi_2(D)  Outer instance pointer: gpi_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_3 = igqos_class_find_entry.part.0 (gpi_2(D), 0, 0);
  Starting walk at: ret_3 = igqos_class_find_entry.part.0 (gpi_2(D), 0, 0);
  instance pointer: gpi_2(D)  Outer instance pointer: gpi_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_4 = igqos_class_find_entry.part.0 (gpi_11(D), start_9(D), is_active_12(D));
  Starting walk at: ret_4 = igqos_class_find_entry.part.0 (gpi_11(D), start_9(D), is_active_12(D));
  instance pointer: gpi_11(D)  Outer instance pointer: gpi_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_12 = igqos_entry_ready_timeout.isra.0 (_14);
  Starting walk at: ret_12 = igqos_entry_ready_timeout.isra.0 (_14);
  instance pointer: _14  Outer instance pointer: gpi_9(D) offset: 64 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_qos_clear_lru_entry_req (_1, ii_2);
  Function call may change dynamic type:ret_12 = igqos_entry_ready_timeout.isra.0 (_14);
  Function call may change dynamic type:pfe_gpi_cfg_qos_clear_lru_entry_req (_1, ii_2);
Determining dynamic type for call: ret_12 = igqos_entry_ready_timeout.isra.0 (_14);
  Starting walk at: ret_12 = igqos_entry_ready_timeout.isra.0 (_14);
  instance pointer: _14  Outer instance pointer: gpi_9(D) offset: 64 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_gpi_cfg_qos_clear_flow_entry_req (_1, ii_2);
  Function call may change dynamic type:ret_12 = igqos_entry_ready_timeout.isra.0 (_14);
  Function call may change dynamic type:pfe_gpi_cfg_qos_clear_flow_entry_req (_1, ii_2);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_gpi_qos_reset.part.0/137:
    callsite  pfe_gpi_qos_reset.part.0/137 -> igqos_class_clear_active_all/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_reset.part.0/132:
  Jump functions of caller  igqos_entry_ready_timeout.isra.0/130:
  Jump functions of caller  igqos_class_find_entry.part.0/127:
    callsite  igqos_class_find_entry.part.0/127 -> igqos_class_is_active/21 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  igqos_l4_port_range_is_valid.isra.0/120:
  Jump functions of caller  pfe_gpi_cfg_get_special_stats/117:
  Jump functions of caller  pfe_gpi_cfg_get_stat_value/116:
  Jump functions of caller  pfe_gpi_cfg_shp_get_drop_cnt/115:
  Jump functions of caller  pfe_gpi_cfg_shp_get_limits/114:
  Jump functions of caller  pfe_gpi_cfg_shp_set_limits/113:
  Jump functions of caller  pfe_gpi_cfg_shp_get_isl_weight/112:
  Jump functions of caller  pfe_gpi_cfg_shp_set_isl_weight/111:
  Jump functions of caller  pfe_gpi_cfg_shp_get_type/110:
  Jump functions of caller  pfe_gpi_cfg_shp_set_type/109:
  Jump functions of caller  pfe_gpi_cfg_shp_get_mode/108:
  Jump functions of caller  pfe_gpi_cfg_shp_set_mode/107:
  Jump functions of caller  pfe_gpi_cfg_shp_disable/106:
  Jump functions of caller  pfe_gpi_cfg_shp_enable/105:
  Jump functions of caller  pfe_gpi_cfg_shp_default_init/104:
  Jump functions of caller  pfe_gpi_cfg_shp_is_enabled/103:
  Jump functions of caller  pfe_gpi_cfg_wred_get_thr/102:
  Jump functions of caller  pfe_gpi_cfg_wred_set_thr/101:
  Jump functions of caller  pfe_gpi_cfg_wred_get_prob/100:
  Jump functions of caller  pfe_gpi_cfg_wred_set_prob/99:
  Jump functions of caller  pfe_gpi_cfg_wred_disable/98:
  Jump functions of caller  pfe_gpi_cfg_wred_enable/97:
  Jump functions of caller  pfe_gpi_cfg_wred_is_enabled/96:
  Jump functions of caller  pfe_gpi_cfg_qos_write_flow_entry_req/95:
  Jump functions of caller  pfe_gpi_cfg_qos_rd_fl_entry_resp/94:
  Jump functions of caller  pfe_gpi_cfg_qos_rd_fl_entry_req/93:
  Jump functions of caller  pfe_gpi_cfg_qos_disable/92:
  Jump functions of caller  pfe_gpi_cfg_qos_enable/91:
  Jump functions of caller  pfe_gpi_cfg_qos_clear_lru_entry_req/90:
  Jump functions of caller  oal_time_usleep/89:
  Jump functions of caller  pfe_gpi_cfg_qos_entry_ready/88:
  Jump functions of caller  pfe_gpi_cfg_qos_clear_flow_entry_req/87:
  Jump functions of caller  pfe_gpi_cfg_qos_default_init/86:
  Jump functions of caller  pfe_gpi_cfg_qos_is_enabled/85:
  Jump functions of caller  pfe_gpi_cfg_disable/84:
  Jump functions of caller  pfe_gpi_cfg_enable/83:
  Jump functions of caller  pfe_gpi_cfg_reset/82:
  Jump functions of caller  pfe_gpi_cfg_init/81:
  Jump functions of caller  pfe_gpi_cfg_get_sys_clk_mhz/80:
  Jump functions of caller  autolibc_memset/79:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/78:
  Jump functions of caller  pfe_hm_report/77:
  Jump functions of caller  __builtin_expect/76:
  Jump functions of caller  pfe_gpi_get_special_stats/75:
  Jump functions of caller  pfe_gpi_get_stat_value/74:
  Jump functions of caller  pfe_gpi_shp_get_drop_cnt/73:
  Jump functions of caller  pfe_gpi_shp_get_limits/72:
  Jump functions of caller  pfe_gpi_shp_set_limits/71:
  Jump functions of caller  pfe_gpi_shp_get_idle_slope/70:
    callsite  pfe_gpi_shp_get_idle_slope/70 -> igqos_convert_weight_to_isl/39 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
  Jump functions of caller  pfe_gpi_shp_set_idle_slope/69:
    callsite  pfe_gpi_shp_set_idle_slope/69 -> igqos_find_optimal_weight/40 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_gpi_shp_get_type/68:
  Jump functions of caller  pfe_gpi_shp_set_type/67:
  Jump functions of caller  pfe_gpi_shp_get_mode/66:
  Jump functions of caller  pfe_gpi_shp_set_mode/65:
  Jump functions of caller  pfe_gpi_shp_disable/64:
  Jump functions of caller  pfe_gpi_shp_enable/63:
  Jump functions of caller  pfe_gpi_shp_is_enabled/62:
  Jump functions of caller  pfe_gpi_wred_get_thr/61:
  Jump functions of caller  pfe_gpi_wred_set_thr/60:
  Jump functions of caller  pfe_gpi_wred_get_prob/59:
  Jump functions of caller  pfe_gpi_wred_set_prob/58:
  Jump functions of caller  pfe_gpi_wred_disable/57:
  Jump functions of caller  pfe_gpi_wred_enable/56:
  Jump functions of caller  pfe_gpi_wred_is_enabled/55:
  Jump functions of caller  pfe_gpi_qos_get_next_flow/54:
    callsite  pfe_gpi_qos_get_next_flow/54 -> pfe_gpi_qos_get_flow/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_qos_get_next_flow/54 -> igqos_class_get_next_active/25 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_qos_get_first_flow/53:
    callsite  pfe_gpi_qos_get_first_flow/53 -> pfe_gpi_qos_get_flow/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_qos_get_first_flow/53 -> igqos_class_get_first_active/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_qos_add_flow/52:
    callsite  pfe_gpi_qos_add_flow/52 -> igqos_class_set_active/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_gpi_qos_add_flow/52 -> igqos_entry_ready_timeout.isra.0/130 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_gpi_qos_add_flow/52 -> igqos_convert_flow_to_entry/35 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_gpi_qos_add_flow/52 -> igqos_class_find_first_free/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_qos_add_flow/52 -> igqos_flow_entry_fixup/30 : 
       param 0: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_qos_add_flow/52 -> igqos_flow_entry_validate/32 : 
       param 0: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_qos_rem_flow/51:
    callsite  pfe_gpi_qos_rem_flow/51 -> igqos_class_clear_active/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_gpi_qos_rem_flow/51 -> igqos_entry_ready_timeout.isra.0/130 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_gpi_qos_rem_flow/51 -> igqos_class_is_active/21 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_gpi_qos_get_flow/50:
    callsite  pfe_gpi_qos_get_flow/50 -> igqos_convert_entry_to_flow/28 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_qos_get_flow/50 -> igqos_entry_ready_timeout.isra.0/130 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_gpi_qos_disable/49:
  Jump functions of caller  pfe_gpi_qos_enable/48:
    callsite  pfe_gpi_qos_enable/48 -> pfe_gpi_qos_reset/47 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_qos_reset/47:
    callsite  pfe_gpi_qos_reset/47 -> pfe_gpi_qos_reset.part.0/137 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_qos_reset/47 -> igqos_class_clear_lru_entry_table/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_qos_reset/47 -> igqos_class_clear_flow_entry_table/17 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_qos_is_enabled/46:
  Jump functions of caller  pfe_gpi_destroy/45:
    callsite  pfe_gpi_destroy/45 -> pfe_gpi_reset/42 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_destroy/45 -> pfe_gpi_qos_reset/47 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_gpi_destroy/45 -> pfe_gpi_disable/44 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_gpi_disable/44:
  Jump functions of caller  pfe_gpi_enable/43:
  Jump functions of caller  pfe_gpi_reset/42:
    callsite  pfe_gpi_reset/42 -> pfe_gpi_reset.part.0/132 : 
  Jump functions of caller  pfe_gpi_create/41:
    callsite  pfe_gpi_create/41 -> pfe_gpi_disable/44 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_gpi_create/41 -> pfe_gpi_qos_reset/47 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_gpi_create/41 -> pfe_gpi_reset/42 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  igqos_find_optimal_weight/40:
    callsite  igqos_find_optimal_weight/40 -> igqos_convert_isl_to_weight/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7fffffff
         VR  [0, 2147483647]
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  igqos_find_optimal_weight/40 -> igqos_convert_isl_to_weight/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7fffffff
         VR  [0, 2147483647]
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  igqos_find_optimal_weight/40 -> igqos_convert_isl_to_weight/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 15
         value: 0xf, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  igqos_find_optimal_weight/40 -> igqos_convert_isl_to_weight/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  igqos_convert_weight_to_isl/39:
  Jump functions of caller  igqos_convert_isl_to_weight/38:
  Jump functions of caller  igqos_convert_flow_to_entry/35:
    callsite  igqos_convert_flow_to_entry/35 -> igqos_convert_flow_to_entry_reg45/34 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  igqos_convert_flow_to_entry/35 -> igqos_convert_flow_to_entry_reg0123/33 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  igqos_convert_flow_to_entry_reg45/34:
  Jump functions of caller  igqos_convert_flow_to_entry_reg0123/33:
  Jump functions of caller  igqos_flow_entry_validate/32:
    callsite  igqos_flow_entry_validate/32 -> igqos_flow_entry_validate_args/31 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  igqos_flow_entry_validate_args/31:
    callsite  igqos_flow_entry_validate_args/31 -> igqos_l4_port_range_is_valid.isra.0/120 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  igqos_flow_entry_validate_args/31 -> igqos_l4_port_range_is_valid.isra.0/120 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  igqos_flow_entry_fixup/30:
  Jump functions of caller  igqos_convert_entry_to_flow/28:
  Jump functions of caller  igqos_class_get_next_active/25:
    callsite  igqos_class_get_next_active/25 -> igqos_class_find_entry/22 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  igqos_class_get_first_active/24:
    callsite  igqos_class_get_first_active/24 -> igqos_class_find_entry.part.0/127 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  igqos_class_find_first_free/23:
    callsite  igqos_class_find_first_free/23 -> igqos_class_find_entry.part.0/127 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  igqos_class_find_entry/22:
    callsite  igqos_class_find_entry/22 -> igqos_class_find_entry.part.0/127 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  igqos_class_is_active/21:
  Jump functions of caller  igqos_class_clear_active/20:
  Jump functions of caller  igqos_class_set_active/19:
  Jump functions of caller  igqos_class_clear_lru_entry_table/18:
    callsite  igqos_class_clear_lru_entry_table/18 -> igqos_entry_ready_timeout.isra.0/130 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  igqos_class_clear_flow_entry_table/17:
    callsite  igqos_class_clear_flow_entry_table/17 -> igqos_entry_ready_timeout.isra.0/130 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  igqos_class_clear_active_all/15:

 Propagating constants:

Not considering pfe_gpi_get_special_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_get_stat_value for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_get_drop_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_get_limits for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_set_limits for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_get_idle_slope for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_set_idle_slope for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_get_type for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_set_type for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_get_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_set_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_shp_is_enabled for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_wred_get_thr for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_wred_set_thr for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_wred_get_prob for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_wred_set_prob for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_wred_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_wred_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_wred_is_enabled for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_get_next_flow for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_get_first_flow for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_add_flow for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_rem_flow for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_get_flow for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_reset for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_qos_is_enabled for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_reset for cloning; -fipa-cp-clone disabled.
Not considering pfe_gpi_create for cloning; -fipa-cp-clone disabled.

overall_size: 1155, max_new_size: 11001
 - context independent values, size: 9, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_gpi_qos_reset.part.0/137:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_gpi_reset.part.0/132:
  Node: igqos_entry_ready_timeout.isra.0/130:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const addr_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: igqos_class_find_entry.part.0/127:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 65, loc_size: 12, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 1, loc_size: 12, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 12, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
        AGGS VARIABLE
  Node: igqos_l4_port_range_is_valid.isra.0/120:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_gpi_get_special_stats/75:
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
  Node: pfe_gpi_get_stat_value/74:
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
  Node: pfe_gpi_shp_get_drop_cnt/73:
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
  Node: pfe_gpi_shp_get_limits/72:
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
  Node: pfe_gpi_shp_set_limits/71:
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
  Node: pfe_gpi_shp_get_idle_slope/70:
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
  Node: pfe_gpi_shp_set_idle_slope/69:
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
  Node: pfe_gpi_shp_get_type/68:
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
  Node: pfe_gpi_shp_set_type/67:
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
  Node: pfe_gpi_shp_get_mode/66:
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
  Node: pfe_gpi_shp_set_mode/65:
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
  Node: pfe_gpi_shp_disable/64:
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
  Node: pfe_gpi_shp_enable/63:
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
  Node: pfe_gpi_shp_is_enabled/62:
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
  Node: pfe_gpi_wred_get_thr/61:
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
  Node: pfe_gpi_wred_set_thr/60:
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
  Node: pfe_gpi_wred_get_prob/59:
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
  Node: pfe_gpi_wred_set_prob/58:
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
  Node: pfe_gpi_wred_disable/57:
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
  Node: pfe_gpi_wred_enable/56:
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
  Node: pfe_gpi_wred_is_enabled/55:
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
  Node: pfe_gpi_qos_get_next_flow/54:
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
  Node: pfe_gpi_qos_get_first_flow/53:
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
  Node: pfe_gpi_qos_add_flow/52:
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
  Node: pfe_gpi_qos_rem_flow/51:
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
  Node: pfe_gpi_qos_get_flow/50:
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
  Node: pfe_gpi_qos_disable/49:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_qos_enable/48:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_qos_reset/47:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_qos_is_enabled/46:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_destroy/45:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_disable/44:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_enable/43:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_reset/42:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_gpi_create/41:
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
  Node: igqos_find_optimal_weight/40:
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
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         bool_t [0, 1]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: igqos_convert_weight_to_isl/39:
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
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         bool_t [0, 1]
        AGGS VARIABLE
  Node: igqos_convert_isl_to_weight/38:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 3, loc_size: 10, prop_time: 0, prop_size: 0]
               15 [loc_time: 3, loc_size: 10, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7fffffff
         uint32_t [0, 2147483647]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         bool_t [0, 1]
        AGGS VARIABLE
  Node: igqos_convert_flow_to_entry/35:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: igqos_convert_flow_to_entry_reg45/34:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: igqos_convert_flow_to_entry_reg0123/33:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: igqos_flow_entry_validate/32:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_flow_entry_validate_args/31:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_flow_entry_fixup/30:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_convert_entry_to_flow/28:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const uint32_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_get_next_active/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_get_first_active/24:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_find_first_free/23:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_find_entry/22:
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
    param [2]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         bool_t [1, 1]
        AGGS VARIABLE
  Node: igqos_class_is_active/21:
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
  Node: igqos_class_clear_active/20:
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
  Node: igqos_class_set_active/19:
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
  Node: igqos_class_clear_lru_entry_table/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_clear_flow_entry_table/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: igqos_class_clear_active_all/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of igqos_class_find_entry/22 for all known contexts.
    replacing param #2 is_active with const 1
Propagated bits info for function igqos_class_find_entry.constprop/157:
 param 2: value = 0x1, mask = 0x0
Propagated bits info for function igqos_class_find_entry.part.0/127:
 param 2: value = 0x1, mask = 0x1
Propagated bits info for function igqos_find_optimal_weight/40:
 param 2: value = 0x0, mask = 0x1
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function igqos_convert_weight_to_isl/39:
 param 3: value = 0x0, mask = 0x1
Propagated bits info for function igqos_convert_isl_to_weight/38:
 param 1: value = 0x0, mask = 0x7fffffff
 param 3: value = 0x0, mask = 0x1
Propagated bits info for function igqos_convert_flow_to_entry/35:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function igqos_convert_flow_to_entry_reg45/34:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function igqos_convert_flow_to_entry_reg0123/33:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function igqos_convert_entry_to_flow/28:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function igqos_class_find_entry/22:
 param 2: value = 0x1, mask = 0x0

IPA constant propagation end

Reclaiming functions: igqos_class_find_entry/22
Reclaiming variables:
Clearing address taken flags:
Symbol table:

igqos_class_find_entry.constprop.0/157 (igqos_class_find_entry.constprop) @074bb380
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of igqos_class_find_entry/22
  Availability: local
  Function flags: count:127626147 (estimated locally) local optimize_size
  Called by: igqos_class_get_next_active/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: __builtin_expect/76 (127626147 (estimated locally),1.00 per call) igqos_class_find_entry.part.0/127 (114863532 (estimated locally),0.90 per call) 
pfe_gpi_qos_reset.part.0/137 (pfe_gpi_qos_reset.part.0) @074c5d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_gpi_qos_reset/47 (116930484 (estimated locally),0.11 per call) 
  Calls: pfe_gpi_cfg_qos_default_init/86 (1073741824 (estimated locally),1.00 per call) igqos_class_clear_active_all/15 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_reset.part.0/132 (pfe_gpi_reset.part.0) @0701f540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_gpi_reset/42 (354334800 (estimated locally),0.33 per call) 
  Calls: pfe_hm_report/77 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/78 (1073741824 (estimated locally),1.00 per call) 
igqos_entry_ready_timeout.isra.0/130 (igqos_entry_ready_timeout.isra.0) @06f7ac40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:69202660 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_add_flow/52 (333402205 (estimated locally),0.31 per call) pfe_gpi_qos_rem_flow/51 (333402205 (estimated locally),0.31 per call) pfe_gpi_qos_get_flow/50 (512926469 (estimated locally),0.48 per call) igqos_class_clear_lru_entry_table/18 (1057206201 (estimated locally),14.16 per call) igqos_class_clear_flow_entry_table/17 (1057206201 (estimated locally),14.16 per call) 
  Calls: pfe_gpi_cfg_qos_entry_ready/88 (11418439 (estimated locally),0.17 per call) oal_time_usleep/89 (1004539164 (estimated locally),14.52 per call) pfe_gpi_cfg_qos_entry_ready/88 (1063004405 (estimated locally),15.36 per call) 
igqos_class_find_entry.part.0/127 (igqos_class_find_entry.part.0) @0753fee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: igqos_class_find_entry.constprop/157 (114863532 (estimated locally),0.90 per call) igqos_class_get_first_active/24 (1073741824 (estimated locally),1.00 per call) igqos_class_find_first_free/23 (1073741824 (estimated locally),1.00 per call) 
  Calls: igqos_class_is_active/21 (1014686025 (estimated locally),8.83 per call) 
igqos_l4_port_range_is_valid.isra.0/120 (igqos_l4_port_range_is_valid.isra.0) @074c5000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: igqos_flow_entry_validate_args/31 (1073741824 (estimated locally),1.00 per call) igqos_flow_entry_validate_args/31 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_get_special_stats/117 (pfe_gpi_cfg_get_special_stats) @076097e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_get_special_stats/75 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_get_stat_value/116 (pfe_gpi_cfg_get_stat_value) @07609620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_get_stat_value/74 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_shp_get_drop_cnt/115 (pfe_gpi_cfg_shp_get_drop_cnt) @07609460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_get_drop_cnt/73 (604946144 (estimated locally),0.56 per call) 
  Calls: 
pfe_gpi_cfg_shp_get_limits/114 (pfe_gpi_cfg_shp_get_limits) @076092a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_get_limits/72 (604946144 (estimated locally),0.56 per call) 
  Calls: 
pfe_gpi_cfg_shp_set_limits/113 (pfe_gpi_cfg_shp_set_limits) @076090e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_set_limits/71 (310797130 (estimated locally),0.29 per call) 
  Calls: 
pfe_gpi_cfg_shp_get_isl_weight/112 (pfe_gpi_cfg_shp_get_isl_weight) @075f9e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_get_idle_slope/70 (604946144 (estimated locally),0.56 per call) 
  Calls: 
pfe_gpi_cfg_shp_set_isl_weight/111 (pfe_gpi_cfg_shp_set_isl_weight) @075f99a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_set_idle_slope/69 (604946144 (estimated locally),0.56 per call) 
  Calls: 
pfe_gpi_cfg_shp_get_type/110 (pfe_gpi_cfg_shp_get_type) @075f97e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_get_type/68 (604946144 (estimated locally),0.56 per call) 
  Calls: 
pfe_gpi_cfg_shp_set_type/109 (pfe_gpi_cfg_shp_set_type) @075f9620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_set_type/67 (288982773 (estimated locally),0.27 per call) 
  Calls: 
pfe_gpi_cfg_shp_get_mode/108 (pfe_gpi_cfg_shp_get_mode) @075f9460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_get_idle_slope/70 (604946144 (estimated locally),0.56 per call) pfe_gpi_shp_set_idle_slope/69 (604946144 (estimated locally),0.56 per call) pfe_gpi_shp_get_mode/66 (604946144 (estimated locally),0.56 per call) 
  Calls: 
pfe_gpi_cfg_shp_set_mode/107 (pfe_gpi_cfg_shp_set_mode) @075f92a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_set_mode/65 (235082071 (estimated locally),0.22 per call) 
  Calls: 
pfe_gpi_cfg_shp_disable/106 (pfe_gpi_cfg_shp_disable) @075f90e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_disable/64 (604946144 (estimated locally),0.56 per call) 
  Calls: 
pfe_gpi_cfg_shp_enable/105 (pfe_gpi_cfg_shp_enable) @075ecee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_enable/63 (295697675 (estimated locally),0.28 per call) 
  Calls: 
pfe_gpi_cfg_shp_default_init/104 (pfe_gpi_cfg_shp_default_init) @075ece00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_enable/63 (295697675 (estimated locally),0.28 per call) 
  Calls: 
pfe_gpi_cfg_shp_is_enabled/103 (pfe_gpi_cfg_shp_is_enabled) @075ecb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_enable/63 (604946144 (estimated locally),0.56 per call) pfe_gpi_shp_is_enabled/62 (604946144 (estimated locally),0.56 per call) 
  Calls: 
pfe_gpi_cfg_wred_get_thr/102 (pfe_gpi_cfg_wred_get_thr) @075ec9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_wred_get_thr/61 (333402205 (estimated locally),0.31 per call) 
  Calls: 
pfe_gpi_cfg_wred_set_thr/101 (pfe_gpi_cfg_wred_set_thr) @075ec7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_wred_set_thr/60 (286500726 (estimated locally),0.27 per call) 
  Calls: 
pfe_gpi_cfg_wred_get_prob/100 (pfe_gpi_cfg_wred_get_prob) @075ec620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_wred_get_prob/59 (333402205 (estimated locally),0.31 per call) 
  Calls: 
pfe_gpi_cfg_wred_set_prob/99 (pfe_gpi_cfg_wred_set_prob) @075ec460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_wred_set_prob/58 (216711433 (estimated locally),0.20 per call) 
  Calls: 
pfe_gpi_cfg_wred_disable/98 (pfe_gpi_cfg_wred_disable) @075ec2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_wred_disable/57 (512926469 (estimated locally),0.48 per call) 
  Calls: 
pfe_gpi_cfg_wred_enable/97 (pfe_gpi_cfg_wred_enable) @075ec0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_wred_enable/56 (250718458 (estimated locally),0.23 per call) 
  Calls: 
pfe_gpi_cfg_wred_is_enabled/96 (pfe_gpi_cfg_wred_is_enabled) @075c87e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_wred_enable/56 (512926469 (estimated locally),0.48 per call) pfe_gpi_wred_is_enabled/55 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_gpi_cfg_qos_write_flow_entry_req/95 (pfe_gpi_cfg_qos_write_flow_entry_req) @075c80e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_qos_add_flow/52 (333402205 (estimated locally),0.31 per call) 
  Calls: 
pfe_gpi_cfg_qos_rd_fl_entry_resp/94 (pfe_gpi_cfg_qos_rd_fl_entry_resp) @07593b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_qos_get_flow/50 (169265735 (estimated locally),0.16 per call) 
  Calls: 
pfe_gpi_cfg_qos_rd_fl_entry_req/93 (pfe_gpi_cfg_qos_rd_fl_entry_req) @07593a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_qos_get_flow/50 (512926469 (estimated locally),0.48 per call) 
  Calls: 
pfe_gpi_cfg_qos_disable/92 (pfe_gpi_cfg_qos_disable) @075938c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_qos_disable/49 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_qos_enable/91 (pfe_gpi_cfg_qos_enable) @07593700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_qos_enable/48 (173198851 (estimated locally),0.16 per call) 
  Calls: 
pfe_gpi_cfg_qos_clear_lru_entry_req/90 (pfe_gpi_cfg_qos_clear_lru_entry_req) @07593460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: igqos_class_clear_lru_entry_table/18 (1057206201 (estimated locally),14.16 per call) 
  Calls: 
oal_time_usleep/89 (oal_time_usleep) @075932a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: igqos_entry_ready_timeout.isra.0/130 (1004539164 (estimated locally),14.52 per call) 
  Calls: 
pfe_gpi_cfg_qos_entry_ready/88 (pfe_gpi_cfg_qos_entry_ready) @075931c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: igqos_entry_ready_timeout.isra.0/130 (11418439 (estimated locally),0.17 per call) igqos_entry_ready_timeout.isra.0/130 (1063004405 (estimated locally),15.36 per call) 
  Calls: 
pfe_gpi_cfg_qos_clear_flow_entry_req/87 (pfe_gpi_cfg_qos_clear_flow_entry_req) @07593000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_qos_rem_flow/51 (333402205 (estimated locally),0.31 per call) igqos_class_clear_flow_entry_table/17 (1057206201 (estimated locally),14.16 per call) 
  Calls: 
pfe_gpi_cfg_qos_default_init/86 (pfe_gpi_cfg_qos_default_init) @0758ae00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_qos_reset.part.0/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_qos_is_enabled/85 (pfe_gpi_cfg_qos_is_enabled) @0758ac40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_qos_enable/48 (1073741824 (estimated locally),1.00 per call) pfe_gpi_qos_is_enabled/46 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_disable/84 (pfe_gpi_cfg_disable) @0758a9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_disable/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_enable/83 (pfe_gpi_cfg_enable) @0758a7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_enable/43 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_reset/82 (pfe_gpi_cfg_reset) @0758a540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_reset/42 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_cfg_init/81 (pfe_gpi_cfg_init) @0758a380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_create/41 (628658390 (estimated locally),0.59 per call) 
  Calls: 
pfe_gpi_cfg_get_sys_clk_mhz/80 (pfe_gpi_cfg_get_sys_clk_mhz) @0758a2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_enable/63 (295697675 (estimated locally),0.28 per call) pfe_gpi_create/41 (966367642 (estimated locally),0.90 per call) 
  Calls: 
autolibc_memset/79 (autolibc_memset) @0758a1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_create/41 (966367642 (estimated locally),0.90 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/78 (oal_util_raise_dem_for_drv_runtime_err) @0758a0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_set_limits/71 (167352301 (estimated locally),0.16 per call) pfe_gpi_shp_set_limits/71 (126796712 (estimated locally),0.12 per call) pfe_gpi_destroy/45 (189462818 (estimated locally),0.18 per call) pfe_gpi_destroy/45 (123636888 (estimated locally),0.12 per call) pfe_gpi_create/41 (57462636 (estimated locally),0.05 per call) pfe_gpi_create/41 (107374182 (estimated locally),0.10 per call) pfe_gpi_reset.part.0/132 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hm_report/77 (pfe_hm_report) @0758a000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_gpi_shp_set_limits/71 (167352301 (estimated locally),0.16 per call) pfe_gpi_shp_set_limits/71 (126796712 (estimated locally),0.12 per call) pfe_gpi_destroy/45 (189462818 (estimated locally),0.18 per call) pfe_gpi_destroy/45 (123636888 (estimated locally),0.12 per call) pfe_gpi_create/41 (57462636 (estimated locally),0.05 per call) pfe_gpi_create/41 (107374182 (estimated locally),0.10 per call) pfe_gpi_reset.part.0/132 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
__builtin_expect/76 (__builtin_expect) @07580d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: igqos_class_find_entry.constprop/157 (127626147 (estimated locally),1.00 per call) pfe_gpi_create/41 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_get_special_stats/75 (pfe_gpi_get_special_stats) @07580ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_get_special_stats/117 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_get_stat_value/74 (pfe_gpi_get_stat_value) @07580c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_get_stat_value/116 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_shp_get_drop_cnt/73 (pfe_gpi_shp_get_drop_cnt) @075809a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_get_drop_cnt/115 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_shp_get_limits/72 (pfe_gpi_shp_get_limits) @07580700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_get_limits/114 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_shp_set_limits/71 (pfe_gpi_shp_set_limits) @07580460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_set_limits/113 (310797130 (estimated locally),0.29 per call) oal_util_raise_dem_for_drv_runtime_err/78 (167352301 (estimated locally),0.16 per call) pfe_hm_report/77 (167352301 (estimated locally),0.16 per call) oal_util_raise_dem_for_drv_runtime_err/78 (126796712 (estimated locally),0.12 per call) pfe_hm_report/77 (126796712 (estimated locally),0.12 per call) 
pfe_gpi_shp_get_idle_slope/70 (pfe_gpi_shp_get_idle_slope) @07580000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_convert_weight_to_isl/39 (604946144 (estimated locally),0.56 per call) pfe_gpi_cfg_shp_get_isl_weight/112 (604946144 (estimated locally),0.56 per call) pfe_gpi_cfg_shp_get_mode/108 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_shp_set_idle_slope/69 (pfe_gpi_shp_set_idle_slope) @07575b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_set_isl_weight/111 (604946144 (estimated locally),0.56 per call) igqos_find_optimal_weight/40 (604946144 (estimated locally),0.56 per call) pfe_gpi_cfg_shp_get_mode/108 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_shp_get_type/68 (pfe_gpi_shp_get_type) @07575620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_get_type/110 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_shp_set_type/67 (pfe_gpi_shp_set_type) @075750e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_set_type/109 (288982773 (estimated locally),0.27 per call) 
pfe_gpi_shp_get_mode/66 (pfe_gpi_shp_get_mode) @07575d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_get_mode/108 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_shp_set_mode/65 (pfe_gpi_shp_set_mode) @07575a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_set_mode/107 (235082071 (estimated locally),0.22 per call) 
pfe_gpi_shp_disable/64 (pfe_gpi_shp_disable) @075757e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_disable/106 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_shp_enable/63 (pfe_gpi_shp_enable) @07575540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_enable/105 (295697675 (estimated locally),0.28 per call) pfe_gpi_cfg_shp_default_init/104 (295697675 (estimated locally),0.28 per call) pfe_gpi_cfg_get_sys_clk_mhz/80 (295697675 (estimated locally),0.28 per call) pfe_gpi_cfg_shp_is_enabled/103 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_shp_is_enabled/62 (pfe_gpi_shp_is_enabled) @075752a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_shp_is_enabled/103 (604946144 (estimated locally),0.56 per call) 
pfe_gpi_wred_get_thr/61 (pfe_gpi_wred_get_thr) @07575000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_wred_get_thr/102 (333402205 (estimated locally),0.31 per call) 
pfe_gpi_wred_set_thr/60 (pfe_gpi_wred_set_thr) @0756db60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_wred_set_thr/101 (286500726 (estimated locally),0.27 per call) 
pfe_gpi_wred_get_prob/59 (pfe_gpi_wred_get_prob) @0756d620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_wred_get_prob/100 (333402205 (estimated locally),0.31 per call) 
pfe_gpi_wred_set_prob/58 (pfe_gpi_wred_set_prob) @0756d0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_wred_set_prob/99 (216711433 (estimated locally),0.20 per call) 
pfe_gpi_wred_disable/57 (pfe_gpi_wred_disable) @0756dd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_wred_disable/98 (512926469 (estimated locally),0.48 per call) 
pfe_gpi_wred_enable/56 (pfe_gpi_wred_enable) @0756da80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_wred_enable/97 (250718458 (estimated locally),0.23 per call) pfe_gpi_cfg_wred_is_enabled/96 (512926469 (estimated locally),0.48 per call) 
pfe_gpi_wred_is_enabled/55 (pfe_gpi_wred_is_enabled) @0756d7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_wred_is_enabled/96 (354334802 (estimated locally),0.33 per call) 
pfe_gpi_qos_get_next_flow/54 (pfe_gpi_qos_get_next_flow) @0756d540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_qos_get_flow/50 (686872646 (estimated locally),0.64 per call) igqos_class_get_next_active/25 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_qos_get_first_flow/53 (pfe_gpi_qos_get_first_flow) @0756d2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_qos_get_flow/50 (686872646 (estimated locally),0.64 per call) igqos_class_get_first_active/24 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_qos_add_flow/52 (pfe_gpi_qos_add_flow) @0756d000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_class_set_active/19 (110022728 (estimated locally),0.10 per call) igqos_entry_ready_timeout.isra.0/130 (333402205 (estimated locally),0.31 per call) pfe_gpi_cfg_qos_write_flow_entry_req/95 (333402205 (estimated locally),0.31 per call) igqos_convert_flow_to_entry/35 (333402205 (estimated locally),0.31 per call) igqos_class_find_first_free/23 (113356750 (estimated locally),0.11 per call) igqos_flow_entry_fixup/30 (333402205 (estimated locally),0.31 per call) igqos_flow_entry_validate/32 (697932186 (estimated locally),0.65 per call) 
pfe_gpi_qos_rem_flow/51 (pfe_gpi_qos_rem_flow) @07552a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: igqos_class_clear_active/20 (110022728 (estimated locally),0.10 per call) igqos_entry_ready_timeout.isra.0/130 (333402205 (estimated locally),0.31 per call) pfe_gpi_cfg_qos_clear_flow_entry_req/87 (333402205 (estimated locally),0.31 per call) igqos_class_is_active/21 (697932186 (estimated locally),0.65 per call) 
pfe_gpi_qos_get_flow/50 (pfe_gpi_qos_get_flow) @07552540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_gpi_qos_get_next_flow/54 (686872646 (estimated locally),0.64 per call) pfe_gpi_qos_get_first_flow/53 (686872646 (estimated locally),0.64 per call) 
  Calls: igqos_convert_entry_to_flow/28 (169265735 (estimated locally),0.16 per call) pfe_gpi_cfg_qos_rd_fl_entry_resp/94 (169265735 (estimated locally),0.16 per call) igqos_entry_ready_timeout.isra.0/130 (512926469 (estimated locally),0.48 per call) pfe_gpi_cfg_qos_rd_fl_entry_req/93 (512926469 (estimated locally),0.48 per call) 
pfe_gpi_qos_disable/49 (pfe_gpi_qos_disable) @07552ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_qos_disable/92 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_qos_enable/48 (pfe_gpi_qos_enable) @07552c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_qos_enable/91 (173198851 (estimated locally),0.16 per call) pfe_gpi_qos_reset/47 (524845004 (estimated locally),0.49 per call) pfe_gpi_cfg_qos_is_enabled/85 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_qos_reset/47 (pfe_gpi_qos_reset) @075529a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_gpi_qos_enable/48 (524845004 (estimated locally),0.49 per call) pfe_gpi_destroy/45 (374657235 (estimated locally),0.35 per call) pfe_gpi_create/41 (343060513 (estimated locally),0.32 per call) 
  Calls: pfe_gpi_qos_reset.part.0/137 (116930484 (estimated locally),0.11 per call) igqos_class_clear_lru_entry_table/18 (354334802 (estimated locally),0.33 per call) igqos_class_clear_flow_entry_table/17 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_qos_is_enabled/46 (pfe_gpi_qos_is_enabled) @07552700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_qos_is_enabled/85 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_destroy/45 (pfe_gpi_destroy) @07552460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/78 (189462818 (estimated locally),0.18 per call) pfe_hm_report/77 (189462818 (estimated locally),0.18 per call) pfe_gpi_reset/42 (574129754 (estimated locally),0.53 per call) oal_util_raise_dem_for_drv_runtime_err/78 (123636888 (estimated locally),0.12 per call) pfe_hm_report/77 (123636888 (estimated locally),0.12 per call) pfe_gpi_qos_reset/47 (374657235 (estimated locally),0.35 per call) pfe_gpi_disable/44 (574129754 (estimated locally),0.53 per call) 
pfe_gpi_disable/44 (pfe_gpi_disable) @07552000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_gpi_destroy/45 (574129754 (estimated locally),0.53 per call) pfe_gpi_create/41 (628658390 (estimated locally),0.59 per call) 
  Calls: pfe_gpi_cfg_disable/84 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_enable/43 (pfe_gpi_enable) @075487e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_enable/83 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_reset/42 (pfe_gpi_reset) @075480e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_gpi_destroy/45 (574129754 (estimated locally),0.53 per call) pfe_gpi_create/41 (966367642 (estimated locally),0.90 per call) 
  Calls: pfe_gpi_reset.part.0/132 (354334800 (estimated locally),0.33 per call) pfe_gpi_cfg_reset/82 (1073741824 (estimated locally),1.00 per call) 
pfe_gpi_create/41 (pfe_gpi_create) @07548c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xxgpi_instance/13 (addr)xxgpi_instance/13 (write)xxgpi_instance/13 (write)xxgpi_instance/13 (write)xxgpi_instance/13 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_cfg_init/81 (628658390 (estimated locally),0.59 per call) pfe_gpi_disable/44 (628658390 (estimated locally),0.59 per call) oal_util_raise_dem_for_drv_runtime_err/78 (57462636 (estimated locally),0.05 per call) pfe_hm_report/77 (57462636 (estimated locally),0.05 per call) pfe_gpi_qos_reset/47 (343060513 (estimated locally),0.32 per call) pfe_gpi_reset/42 (966367642 (estimated locally),0.90 per call) pfe_gpi_cfg_get_sys_clk_mhz/80 (966367642 (estimated locally),0.90 per call) autolibc_memset/79 (966367642 (estimated locally),0.90 per call) oal_util_raise_dem_for_drv_runtime_err/78 (107374182 (estimated locally),0.10 per call) pfe_hm_report/77 (107374182 (estimated locally),0.10 per call) __builtin_expect/76 (1073741824 (estimated locally),1.00 per call) 
igqos_find_optimal_weight/40 (igqos_find_optimal_weight) @07548700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:279554087 (estimated locally) body local optimize_size
  Called by: pfe_gpi_shp_set_idle_slope/69 (604946144 (estimated locally),0.56 per call) 
  Calls: igqos_convert_isl_to_weight/38 (59055800 (estimated locally),0.21 per call) igqos_convert_isl_to_weight/38 (1014686025 (estimated locally),3.63 per call) igqos_convert_isl_to_weight/38 (139777043 (estimated locally),0.50 per call) igqos_convert_isl_to_weight/38 (279554087 (estimated locally),1.00 per call) 
igqos_convert_weight_to_isl/39 (igqos_convert_weight_to_isl) @07548380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_shp_get_idle_slope/70 (604946144 (estimated locally),0.56 per call) 
  Calls: 
igqos_convert_isl_to_weight/38 (igqos_convert_isl_to_weight) @07548000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: igqos_find_optimal_weight/40 (59055800 (estimated locally),0.21 per call) igqos_find_optimal_weight/40 (1014686025 (estimated locally),3.63 per call) igqos_find_optimal_weight/40 (139777043 (estimated locally),0.50 per call) igqos_find_optimal_weight/40 (279554087 (estimated locally),1.00 per call) 
  Calls: 
igqos_convert_flow_to_entry/35 (igqos_convert_flow_to_entry) @0753f9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_add_flow/52 (333402205 (estimated locally),0.31 per call) 
  Calls: igqos_convert_flow_to_entry_reg45/34 (1073741824 (estimated locally),1.00 per call) igqos_convert_flow_to_entry_reg0123/33 (1073741824 (estimated locally),1.00 per call) 
igqos_convert_flow_to_entry_reg45/34 (igqos_convert_flow_to_entry_reg45) @0753ba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: igqos_convert_flow_to_entry/35 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igqos_convert_flow_to_entry_reg0123/33 (igqos_convert_flow_to_entry_reg0123) @07521d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: igqos_convert_flow_to_entry/35 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igqos_flow_entry_validate/32 (igqos_flow_entry_validate) @07516b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_add_flow/52 (697932186 (estimated locally),0.65 per call) 
  Calls: igqos_flow_entry_validate_args/31 (294876349 (estimated locally),0.27 per call) 
igqos_flow_entry_validate_args/31 (igqos_flow_entry_validate_args) @075168c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: igqos_flow_entry_validate/32 (294876349 (estimated locally),0.27 per call) 
  Calls: igqos_l4_port_range_is_valid.isra.0/120 (1073741824 (estimated locally),1.00 per call) igqos_l4_port_range_is_valid.isra.0/120 (1073741824 (estimated locally),1.00 per call) 
igqos_flow_entry_fixup/30 (igqos_flow_entry_fixup) @07516620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_add_flow/52 (333402205 (estimated locally),0.31 per call) 
  Calls: 
igqos_convert_entry_to_flow/28 (igqos_convert_entry_to_flow) @075160e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_get_flow/50 (169265735 (estimated locally),0.16 per call) 
  Calls: 
igqos_class_get_next_active/25 (igqos_class_get_next_active) @074c5a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_get_next_flow/54 (1073741824 (estimated locally),1.00 per call) 
  Calls: igqos_class_find_entry.constprop/157 (1073741824 (estimated locally),1.00 per call) 
igqos_class_get_first_active/24 (igqos_class_get_first_active) @074c5700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_get_first_flow/53 (1073741824 (estimated locally),1.00 per call) 
  Calls: igqos_class_find_entry.part.0/127 (1073741824 (estimated locally),1.00 per call) 
igqos_class_find_first_free/23 (igqos_class_find_first_free) @074c5460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_add_flow/52 (113356750 (estimated locally),0.11 per call) 
  Calls: igqos_class_find_entry.part.0/127 (1073741824 (estimated locally),1.00 per call) 
igqos_class_find_entry/22 (igqos_class_find_entry) @074c51c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:127626147 (estimated locally) body optimize_size
  Called by: 
  Calls: 
igqos_class_is_active/21 (igqos_class_is_active) @074bbee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_rem_flow/51 (697932186 (estimated locally),0.65 per call) igqos_class_find_entry.part.0/127 (1014686025 (estimated locally),8.83 per call) 
  Calls: 
igqos_class_clear_active/20 (igqos_class_clear_active) @074bb9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_rem_flow/51 (110022728 (estimated locally),0.10 per call) 
  Calls: 
igqos_class_set_active/19 (igqos_class_set_active) @074bb460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_add_flow/52 (110022728 (estimated locally),0.10 per call) 
  Calls: 
igqos_class_clear_lru_entry_table/18 (igqos_class_clear_lru_entry_table) @074bbe00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:74681964 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_reset/47 (354334802 (estimated locally),0.33 per call) 
  Calls: igqos_entry_ready_timeout.isra.0/130 (1057206201 (estimated locally),14.16 per call) pfe_gpi_cfg_qos_clear_lru_entry_req/90 (1057206201 (estimated locally),14.16 per call) 
igqos_class_clear_flow_entry_table/17 (igqos_class_clear_flow_entry_table) @074bbb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:74681964 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_reset/47 (1073741824 (estimated locally),1.00 per call) 
  Calls: igqos_entry_ready_timeout.isra.0/130 (1057206201 (estimated locally),14.16 per call) pfe_gpi_cfg_qos_clear_flow_entry_req/87 (1057206201 (estimated locally),14.16 per call) 
igqos_class_clear_active_all/15 (igqos_class_clear_active_all) @074bb620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357878150 (estimated locally) body local optimize_size
  Called by: pfe_gpi_qos_reset.part.0/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
xxgpi_instance/13 (xxgpi_instance) @074aae10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_gpi_create/41 (addr)pfe_gpi_create/41 (write)pfe_gpi_create/41 (write)pfe_gpi_create/41 (write)pfe_gpi_create/41 (write)
  Availability: available
  Varpool flags:

;; Function igqos_entry_ready_timeout.isra.0 (igqos_entry_ready_timeout.isra.0, funcdef_no=77, decl_uid=10584, cgraph_uid=128, symbol_order=130)

Modification phase of node igqos_entry_ready_timeout.isra.0/130
Setting nonnull for 0
igqos_entry_ready_timeout.isra.0 (const addr_t * ISRA.43)
{
  errno_t ret;
  uint32_t timeout;
  bool_t ready;
  unsigned int _2;
  unsigned int _8;

  <bb 12> [local count: 69202660]:
  # DEBUG gpi s=> gpi

  <bb 2> [local count: 69202660]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 200
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1063004405]:
  # DEBUG BEGIN_STMT
  _2 = *ISRA.43_21(D);
  ready_3 = pfe_gpi_cfg_qos_entry_ready (_2);
  # DEBUG ready => ready_3
  # DEBUG BEGIN_STMT
  if (ready_3 == 1)
    goto <bb 6>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 1004539164]:
  # DEBUG BEGIN_STMT
  oal_time_usleep (5);
  # DEBUG BEGIN_STMT
  timeout_5 = timeout_4 + 4294967295;
  # DEBUG timeout => timeout_5

  <bb 5> [local count: 1073741824]:
  # timeout_4 = PHI <200(2), timeout_5(4)>
  # ready_12 = PHI <ready_13(D)(2), ready_3(4)>
  # DEBUG ready => ready_12
  # DEBUG timeout => timeout_4
  # DEBUG BEGIN_STMT
  if (timeout_4 != 0)
    goto <bb 3>; [99.00%]
  else
    goto <bb 6>; [1.00%]

  <bb 6> [local count: 69202660]:
  # ready_7 = PHI <ready_3(3), ready_12(5)>
  # timeout_6 = PHI <timeout_4(3), timeout_4(5)>
  # DEBUG ready => ready_7
  # DEBUG BEGIN_STMT
  if (timeout_6 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 7> [local count: 34601330]:
  if (ready_7 == 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 11418439]:
  # DEBUG BEGIN_STMT
  _8 = *ISRA.43_21(D);
  ready_9 = pfe_gpi_cfg_qos_entry_ready (_8);
  # DEBUG ready => ready_9

  <bb 9> [local count: 69202660]:
  # ready_10 = PHI <ready_7(6), ready_7(7), ready_9(8)>
  # DEBUG ready => ready_10
  # DEBUG BEGIN_STMT
  if (ready_10 == 0)
    goto <bb 10>; [35.00%]
  else
    goto <bb 11>; [65.00%]

  <bb 10> [local count: 24220931]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 110

  <bb 11> [local count: 69202661]:
  # ret_11 = PHI <0(9), 110(10)>
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  return ret_11;

}



;; Function igqos_class_find_entry.part.0 (igqos_class_find_entry.part.0, funcdef_no=76, decl_uid=10560, cgraph_uid=125, symbol_order=127)

Modification phase of node igqos_class_find_entry.part.0/127
Adjusting mask for param 2 to 0x1
Setting value range of param 2 [0, 1]
igqos_class_find_entry.part.0 (const struct pfe_gpi_t * gpi, uint8_t start, bool_t is_active)
{
  uint8_t ii;
  uint8_t ret;
  unsigned char _3;

  <bb 6> [local count: 114863532]:
  goto <bb 4>; [100.00%]

  <bb 2> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _3 = igqos_class_is_active (gpi_1(D), ii_2);
  if (_3 == is_active_4(D))
    goto <bb 5>; [5.50%]
  else
    goto <bb 3>; [94.50%]

  <bb 3> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  ii_5 = ii_2 + 1;
  # DEBUG ii => ii_5

  <bb 4> [local count: 1073741824]:
  # ii_2 = PHI <ii_5(3), start_7(D)(6)>
  # DEBUG ii => ii_2
  # DEBUG BEGIN_STMT
  if (ii_2 <= 63)
    goto <bb 2>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 5> [local count: 114863532]:
  # ret_6 = PHI <ii_2(2), ii_2(4)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_gpi_reset (pfe_gpi_reset, funcdef_no=39, decl_uid=8633, cgraph_uid=40, symbol_order=42)

Modification phase of node pfe_gpi_reset/42
pfe_gpi_reset (const struct pfe_gpi_t * gpi)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_4(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_4(D)->gpi_base_va;
  ret_7 = pfe_gpi_cfg_reset (_1);
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  if (ret_7 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG D#14 => gpi_4(D)
  pfe_gpi_reset.part.0 ();

  <bb 4> [local count: 1073741824]:
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_gpi_enable (pfe_gpi_enable, funcdef_no=40, decl_uid=8631, cgraph_uid=41, symbol_order=43)

Modification phase of node pfe_gpi_enable/43
pfe_gpi_enable (const struct pfe_gpi_t * gpi)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_3(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_3(D)->gpi_base_va;
  pfe_gpi_cfg_enable (_1);
  return;

}



;; Function pfe_gpi_disable (pfe_gpi_disable, funcdef_no=41, decl_uid=8635, cgraph_uid=42, symbol_order=44)

Modification phase of node pfe_gpi_disable/44
pfe_gpi_disable (const struct pfe_gpi_t * gpi)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_3(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_3(D)->gpi_base_va;
  pfe_gpi_cfg_disable (_1);
  return;

}



;; Function pfe_gpi_qos_is_enabled (pfe_gpi_qos_is_enabled, funcdef_no=43, decl_uid=8645, cgraph_uid=44, symbol_order=46)

Modification phase of node pfe_gpi_qos_is_enabled/46
pfe_gpi_qos_is_enabled (const struct pfe_gpi_t * gpi)
{
  bool_t is_enabled;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_3(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_3(D)->gpi_base_va;
  is_enabled_5 = pfe_gpi_cfg_qos_is_enabled (_1);
  # DEBUG is_enabled => is_enabled_5
  # DEBUG BEGIN_STMT
  return is_enabled_5;

}



;; Function pfe_gpi_qos_reset (pfe_gpi_qos_reset, funcdef_no=44, decl_uid=8647, cgraph_uid=45, symbol_order=47)

Modification phase of node pfe_gpi_qos_reset/47
pfe_gpi_qos_reset (struct pfe_gpi_t * gpi)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_3(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_7 = igqos_class_clear_flow_entry_table (gpi_3(D));
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  if (ret_7 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  ret_9 = igqos_class_clear_lru_entry_table (gpi_3(D));
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  if (ret_9 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 116930484]:
  ret_4 = pfe_gpi_qos_reset.part.0 (gpi_3(D));

  <bb 5> [local count: 1073741824]:
  # ret_1 = PHI <ret_4(4), ret_7(2), ret_9(3)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_gpi_create (pfe_gpi_create, funcdef_no=38, decl_uid=8629, cgraph_uid=39, symbol_order=41)

Modification phase of node pfe_gpi_create/41
pfe_gpi_create (addr_t cbus_base_va, addr_t gpi_base, const struct pfe_gpi_cfg_t * cfg, pfe_xxgpi_id_t xxgpi_id)
{
  errno_t ret;
  struct pfe_gpi_t * gpi;
  _Bool _1;
  long int _2;
  long int _3;
  int _4;
  unsigned int _5;
  long unsigned int _6;
  unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = xxgpi_id_11(D) > 6;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] xxGPI id out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_gpi.c", 796, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG gpi => 0B
  goto <bb 9>; [100.00%]

  <bb 4> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _4 = (int) xxgpi_id_11(D);
  gpi_12 = &xxgpi_instance[_4];
  # DEBUG gpi => gpi_12
  # DEBUG BEGIN_STMT
  autolibc_memset (gpi_12, 0, 32);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_gpi_t *)&xxgpi_instance][_4].cbus_base_va = cbus_base_va_15(D);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_gpi_t *)&xxgpi_instance][_4].gpi_base_offset = gpi_base_17(D);
  # DEBUG BEGIN_STMT
  _5 = cbus_base_va_15(D) + gpi_base_17(D);
  MEM[(struct pfe_gpi_t *)&xxgpi_instance][_4].gpi_base_va = _5;
  # DEBUG BEGIN_STMT
  _6 = pfe_gpi_cfg_get_sys_clk_mhz (cbus_base_va_15(D));
  MEM[(struct pfe_gpi_t *)&xxgpi_instance][_4].sys_clk_mhz = _6;
  # DEBUG BEGIN_STMT
  ret_23 = pfe_gpi_reset (gpi_12);
  # DEBUG ret => ret_23
  # DEBUG BEGIN_STMT
  if (ret_23 != 0)
    goto <bb 9>; [29.00%]
  else
    goto <bb 5>; [71.00%]

  <bb 5> [local count: 686121026]:
  # DEBUG BEGIN_STMT
  switch (gpi_base_17(D)) <default: <L16> [50.00%], case 704512: <L4> [50.00%], case 720896: <L4> [50.00%], case 737280: <L4> [50.00%]>

  <bb 6> [local count: 343060513]:
<L4>:
  # DEBUG BEGIN_STMT
  ret_25 = pfe_gpi_qos_reset (gpi_12);
  # DEBUG ret => ret_25
  # DEBUG BEGIN_STMT
  if (ret_25 != 0)
    goto <bb 7>; [16.75%]
  else
    goto <bb 8>; [83.25%]

  <bb 7> [local count: 57462636]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] GPI QOS reset timed-out\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_gpi.c", 827, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG gpi => 0B
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 628658390]:
<L16>:
  # DEBUG gpi => gpi_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_gpi_disable (gpi_12);
  # DEBUG BEGIN_STMT
  _7 = gpi_12->gpi_base_va;
  pfe_gpi_cfg_init (_7, cfg_29(D));

  <bb 9> [local count: 1073741824]:
  # gpi_8 = PHI <0B(3), 0B(4), 0B(7), gpi_12(8)>
  # DEBUG gpi => gpi_8
  # DEBUG BEGIN_STMT
  return gpi_8;

}



;; Function pfe_gpi_destroy (pfe_gpi_destroy, funcdef_no=42, decl_uid=8637, cgraph_uid=43, symbol_order=45)

Modification phase of node pfe_gpi_destroy/45
pfe_gpi_destroy (struct pfe_gpi_t * gpi)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (gpi_4(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 10>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pfe_gpi_disable (gpi_4(D));
  # DEBUG BEGIN_STMT
  _1 = gpi_4(D)->gpi_base_offset;
  if (_1 == 704512)
    goto <bb 6>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 4> [local count: 457925891]:
  if (_1 == 720896)
    goto <bb 6>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 302231088]:
  if (_1 == 737280)
    goto <bb 6>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 6> [local count: 374657235]:
  # DEBUG BEGIN_STMT
  ret_8 = pfe_gpi_qos_reset (gpi_4(D));
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  if (ret_8 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 123636888]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] GPI QOS reset timed-out\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_gpi.c", 910, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 8> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_12 = pfe_gpi_reset (gpi_4(D));
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  if (ret_12 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 189462818]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] GPI reset timed-out\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_gpi.c", 917, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_gpi_qos_enable (pfe_gpi_qos_enable, funcdef_no=45, decl_uid=8641, cgraph_uid=46, symbol_order=48)

Modification phase of node pfe_gpi_qos_enable/48
pfe_gpi_qos_enable (struct pfe_gpi_t * gpi)
{
  errno_t ret;
  unsigned int _1;
  unsigned char _2;
  unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_7(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_7(D)->gpi_base_va;
  _2 = pfe_gpi_cfg_qos_is_enabled (_1);
  if (_2 != 1)
    goto <bb 3>; [48.88%]
  else
    goto <bb 5>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  ret_10 = pfe_gpi_qos_reset (gpi_7(D));
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  if (ret_10 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 173198851]:
  # DEBUG BEGIN_STMT
  _3 = gpi_7(D)->gpi_base_va;
  pfe_gpi_cfg_qos_enable (_3);

  <bb 5> [local count: 1073741824]:
  # ret_4 = PHI <0(4), 0(2), ret_10(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_gpi_qos_disable (pfe_gpi_qos_disable, funcdef_no=46, decl_uid=8643, cgraph_uid=47, symbol_order=49)

Modification phase of node pfe_gpi_qos_disable/49
pfe_gpi_qos_disable (const struct pfe_gpi_t * gpi)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_3(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_3(D)->gpi_base_va;
  pfe_gpi_cfg_qos_disable (_1);
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_gpi_qos_get_flow (pfe_gpi_qos_get_flow, funcdef_no=47, decl_uid=8658, cgraph_uid=48, symbol_order=50)

Modification phase of node pfe_gpi_qos_get_flow/50
pfe_gpi_qos_get_flow (const struct pfe_gpi_t * gpi, uint8_t id, struct pfe_iqos_flow_spec_t * flow)
{
  errno_t ret;
  uint32_t class_table_entry[8];
  unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  const addr_t * _17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  class_table_entry = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_8(D) > 63)
    goto <bb 5>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  _1 = gpi_9(D)->gpi_base_va;
  _2 = (long unsigned int) id_8(D);
  pfe_gpi_cfg_qos_rd_fl_entry_req (_1, _2);
  # DEBUG BEGIN_STMT
  _17 = &MEM[(unsigned int *)gpi_9(D) + 8B];
  # DEBUG D#13 => gpi_9(D)
  ret_12 = igqos_entry_ready_timeout.isra.0 (_17);
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  if (ret_12 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 169265735]:
  # DEBUG BEGIN_STMT
  _3 = gpi_9(D)->gpi_base_va;
  pfe_gpi_cfg_qos_rd_fl_entry_resp (_3, &class_table_entry);
  # DEBUG BEGIN_STMT
  igqos_convert_entry_to_flow (&class_table_entry, flow_14(D));

  <bb 5> [local count: 1073741824]:
  # ret_4 = PHI <22(2), ret_12(3), 0(4)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  class_table_entry ={v} {CLOBBER};
  return ret_4;

}



;; Function pfe_gpi_qos_rem_flow (pfe_gpi_qos_rem_flow, funcdef_no=48, decl_uid=8654, cgraph_uid=49, symbol_order=51)

Modification phase of node pfe_gpi_qos_rem_flow/51
pfe_gpi_qos_rem_flow (struct pfe_gpi_t * gpi, uint8_t id)
{
  errno_t ret;
  unsigned char _1;
  unsigned int _2;
  long unsigned int _3;
  const addr_t * _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_6(D) > 63)
    goto <bb 6>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _1 = igqos_class_is_active (gpi_8(D), id_6(D));
  if (_1 != 0)
    goto <bb 4>; [47.77%]
  else
    goto <bb 6>; [52.23%]

  <bb 4> [local count: 333402205]:
  # DEBUG BEGIN_STMT
  _2 = gpi_8(D)->gpi_base_va;
  _3 = (long unsigned int) id_6(D);
  pfe_gpi_cfg_qos_clear_flow_entry_req (_2, _3);
  # DEBUG BEGIN_STMT
  _13 = &MEM[(unsigned int *)gpi_8(D) + 8B];
  # DEBUG D#13 => gpi_8(D)
  ret_11 = igqos_entry_ready_timeout.isra.0 (_13);
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  if (ret_11 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 110022728]:
  # DEBUG BEGIN_STMT
  igqos_class_clear_active (gpi_8(D), id_6(D));

  <bb 6> [local count: 1073741824]:
  # ret_4 = PHI <22(2), 0(5), 22(3), ret_11(4)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_gpi_qos_add_flow (pfe_gpi_qos_add_flow, funcdef_no=49, decl_uid=8651, cgraph_uid=50, symbol_order=52)

Modification phase of node pfe_gpi_qos_add_flow/52
pfe_gpi_qos_add_flow (struct pfe_gpi_t * gpi, uint8_t id, struct pfe_iqos_flow_spec_t * flow)
{
  errno_t ret;
  uint8_t entry_id;
  uint32_t class_table_entry[8];
  unsigned char _1;
  int _2;
  unsigned int _3;
  long unsigned int _4;
  const addr_t * _20;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = id_8(D) + 192;
  if (_1 <= 190)
    goto <bb 8>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _2 = igqos_flow_entry_validate (flow_10(D));
  if (_2 != 0)
    goto <bb 8>; [52.23%]
  else
    goto <bb 4>; [47.77%]

  <bb 4> [local count: 333402205]:
  # DEBUG BEGIN_STMT
  igqos_flow_entry_fixup (flow_10(D));
  # DEBUG BEGIN_STMT
  if (id_8(D) == 255)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 113356750]:
  # DEBUG BEGIN_STMT
  entry_id_13 = igqos_class_find_first_free (gpi_12(D));
  # DEBUG entry_id => entry_id_13

  <bb 6> [local count: 333402205]:
  # entry_id_5 = PHI <entry_id_13(5), id_8(D)(4)>
  # DEBUG entry_id => entry_id_5
  # DEBUG BEGIN_STMT
  igqos_convert_flow_to_entry (flow_10(D), &class_table_entry);
  # DEBUG BEGIN_STMT
  _3 = gpi_12(D)->gpi_base_va;
  _4 = (long unsigned int) entry_id_5;
  pfe_gpi_cfg_qos_write_flow_entry_req (_3, _4, &class_table_entry);
  # DEBUG BEGIN_STMT
  _20 = &MEM[(unsigned int *)gpi_12(D) + 8B];
  # DEBUG D#13 => gpi_12(D)
  ret_17 = igqos_entry_ready_timeout.isra.0 (_20);
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  if (ret_17 == 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 110022728]:
  # DEBUG BEGIN_STMT
  igqos_class_set_active (gpi_12(D), entry_id_5);

  <bb 8> [local count: 1073741824]:
  # ret_6 = PHI <22(2), 22(3), ret_17(6), 0(7)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  class_table_entry ={v} {CLOBBER};
  return ret_6;

}



;; Function pfe_gpi_qos_get_first_flow (pfe_gpi_qos_get_first_flow, funcdef_no=50, decl_uid=8662, cgraph_uid=51, symbol_order=53)

Modification phase of node pfe_gpi_qos_get_first_flow/53
pfe_gpi_qos_get_first_flow (struct pfe_gpi_t * gpi, uint8_t * id, struct pfe_iqos_flow_spec_t * flow)
{
  uint8_t entry_id;
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_id_6 = igqos_class_get_first_active (gpi_4(D));
  # DEBUG entry_id => entry_id_6
  # DEBUG BEGIN_STMT
  if (entry_id_6 == 64)
    goto <bb 4>; [36.03%]
  else
    goto <bb 3>; [63.97%]

  <bb 3> [local count: 686872646]:
  # DEBUG BEGIN_STMT
  *id_7(D) = entry_id_6;
  # DEBUG BEGIN_STMT
  ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  # DEBUG ret => ret_11

  <bb 4> [local count: 1073741824]:
  # ret_1 = PHI <75(2), ret_11(3)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_gpi_qos_get_next_flow (pfe_gpi_qos_get_next_flow, funcdef_no=51, decl_uid=8666, cgraph_uid=52, symbol_order=54)

Modification phase of node pfe_gpi_qos_get_next_flow/54
pfe_gpi_qos_get_next_flow (struct pfe_gpi_t * gpi, uint8_t * id, struct pfe_iqos_flow_spec_t * flow)
{
  uint8_t entry_id;
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_id_6 = igqos_class_get_next_active (gpi_4(D));
  # DEBUG entry_id => entry_id_6
  # DEBUG BEGIN_STMT
  if (entry_id_6 == 64)
    goto <bb 4>; [36.03%]
  else
    goto <bb 3>; [63.97%]

  <bb 3> [local count: 686872646]:
  # DEBUG BEGIN_STMT
  *id_7(D) = entry_id_6;
  # DEBUG BEGIN_STMT
  ret_11 = pfe_gpi_qos_get_flow (gpi_4(D), entry_id_6, flow_9(D));
  # DEBUG ret => ret_11

  <bb 4> [local count: 1073741824]:
  # ret_1 = PHI <75(2), ret_11(3)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_gpi_wred_is_enabled (pfe_gpi_wred_is_enabled, funcdef_no=52, decl_uid=8675, cgraph_uid=53, symbol_order=55)

Modification phase of node pfe_gpi_wred_is_enabled/55
pfe_gpi_wred_is_enabled (const struct pfe_gpi_t * gpi, pfe_iqos_queue_t queue)
{
  bool_t is_enabled;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_5(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queue_6(D) > 2)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  is_enabled_8 = pfe_gpi_cfg_wred_is_enabled (_1, queue_6(D));
  # DEBUG is_enabled => is_enabled_8

  <bb 4> [local count: 1073741824]:
  # is_enabled_2 = PHI <is_enabled_8(3), 0(2)>
  # DEBUG is_enabled => is_enabled_2
  # DEBUG BEGIN_STMT
  return is_enabled_2;

}



;; Function pfe_gpi_wred_enable (pfe_gpi_wred_enable, funcdef_no=53, decl_uid=8669, cgraph_uid=54, symbol_order=56)

Modification phase of node pfe_gpi_wred_enable/56
pfe_gpi_wred_enable (const struct pfe_gpi_t * gpi, pfe_iqos_queue_t queue)
{
  errno_t ret;
  unsigned int _1;
  unsigned char _2;
  unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_7(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queue_8(D) > 2)
    goto <bb 5>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  _1 = gpi_7(D)->gpi_base_va;
  _2 = pfe_gpi_cfg_wred_is_enabled (_1, queue_8(D));
  if (_2 == 1)
    goto <bb 5>; [51.12%]
  else
    goto <bb 4>; [48.88%]

  <bb 4> [local count: 250718458]:
  # DEBUG BEGIN_STMT
  _3 = gpi_7(D)->gpi_base_va;
  pfe_gpi_cfg_wred_enable (_3, queue_8(D));

  <bb 5> [local count: 1073741824]:
  # ret_4 = PHI <0(4), 22(2), 0(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_gpi_wred_disable (pfe_gpi_wred_disable, funcdef_no=54, decl_uid=8672, cgraph_uid=55, symbol_order=57)

Modification phase of node pfe_gpi_wred_disable/57
pfe_gpi_wred_disable (const struct pfe_gpi_t * gpi, pfe_iqos_queue_t queue)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_5(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queue_6(D) > 2)
    goto <bb 4>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  pfe_gpi_cfg_wred_disable (_1, queue_6(D));

  <bb 4> [local count: 1073741824]:
  # ret_2 = PHI <0(3), 22(2)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_gpi_wred_set_prob (pfe_gpi_wred_set_prob, funcdef_no=55, decl_uid=8680, cgraph_uid=56, symbol_order=58)

Modification phase of node pfe_gpi_wred_set_prob/58
pfe_gpi_wred_set_prob (const struct pfe_gpi_t * gpi, pfe_iqos_queue_t queue, pfe_iqos_wred_zone_t zone, uint8_t val)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_5(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queue_6(D) > 2)
    goto <bb 6>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  if (zone_7(D) > 3)
    goto <bb 6>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 453655921]:
  if (val_8(D) > 15)
    goto <bb 6>; [52.23%]
  else
    goto <bb 5>; [47.77%]

  <bb 5> [local count: 216711433]:
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  pfe_gpi_cfg_wred_set_prob (_1, queue_6(D), zone_7(D), val_8(D));

  <bb 6> [local count: 1073741824]:
  # ret_2 = PHI <0(5), 22(3), 22(2), 22(4)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_gpi_wred_get_prob (pfe_gpi_wred_get_prob, funcdef_no=56, decl_uid=8685, cgraph_uid=57, symbol_order=59)

Modification phase of node pfe_gpi_wred_get_prob/59
pfe_gpi_wred_get_prob (const struct pfe_gpi_t * gpi, pfe_iqos_queue_t queue, pfe_iqos_wred_zone_t zone, uint8_t * val)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_5(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queue_6(D) > 2)
    goto <bb 5>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  if (zone_7(D) > 3)
    goto <bb 5>; [52.23%]
  else
    goto <bb 4>; [47.77%]

  <bb 4> [local count: 333402205]:
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  pfe_gpi_cfg_wred_get_prob (_1, queue_6(D), zone_7(D), val_8(D));

  <bb 5> [local count: 1073741824]:
  # ret_2 = PHI <0(4), 22(3), 22(2)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_gpi_wred_set_thr (pfe_gpi_wred_set_thr, funcdef_no=57, decl_uid=8690, cgraph_uid=58, symbol_order=60)

Modification phase of node pfe_gpi_wred_set_thr/60
pfe_gpi_wred_set_thr (const struct pfe_gpi_t * gpi, pfe_iqos_queue_t queue, pfe_iqos_wred_thr_t thr, uint16_t val)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_5(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queue_6(D) > 2)
    goto <bb 9>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932185]:
  if (thr_7(D) > 2)
    goto <bb 9>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 453655920]:
  # DEBUG BEGIN_STMT
  if (queue_6(D) == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 226827960]:
  if (val_8(D) > 8192)
    goto <bb 9>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 6> [local count: 374266134]:
  # DEBUG BEGIN_STMT
  if (queue_6(D) != 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 7> [local count: 250758310]:
  if (val_8(D) > 512)
    goto <bb 9>; [35.00%]
  else
    goto <bb 8>; [65.00%]

  <bb 8> [local count: 286500726]:
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  pfe_gpi_cfg_wred_set_thr (_1, queue_6(D), thr_7(D), val_8(D));

  <bb 9> [local count: 1073741824]:
  # ret_2 = PHI <0(8), 22(3), 22(5), 22(7), 22(2)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_gpi_wred_get_thr (pfe_gpi_wred_get_thr, funcdef_no=58, decl_uid=8695, cgraph_uid=59, symbol_order=61)

Modification phase of node pfe_gpi_wred_get_thr/61
pfe_gpi_wred_get_thr (const struct pfe_gpi_t * gpi, pfe_iqos_queue_t queue, pfe_iqos_wred_thr_t thr, uint16_t * val)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => gpi_5(D)
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queue_6(D) > 2)
    goto <bb 5>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  if (thr_7(D) > 2)
    goto <bb 5>; [52.23%]
  else
    goto <bb 4>; [47.77%]

  <bb 4> [local count: 333402205]:
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  pfe_gpi_cfg_wred_get_thr (_1, queue_6(D), thr_7(D), val_8(D));

  <bb 5> [local count: 1073741824]:
  # ret_2 = PHI <0(4), 22(3), 22(2)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_gpi_shp_is_enabled (pfe_gpi_shp_is_enabled, funcdef_no=59, decl_uid=8704, cgraph_uid=60, symbol_order=62)

Modification phase of node pfe_gpi_shp_is_enabled/62
pfe_gpi_shp_is_enabled (const struct pfe_gpi_t * gpi, uint8_t id)
{
  bool_t is_enabled;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG is_enabled => 0
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_5(D)
  # DEBUG id => id_6(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_6(D) > 1)
    goto <bb 4>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  is_enabled_8 = pfe_gpi_cfg_shp_is_enabled (_1, id_6(D));
  # DEBUG is_enabled => is_enabled_8

  <bb 4> [local count: 1073741824]:
  # is_enabled_2 = PHI <0(2), is_enabled_8(3)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG is_enabled => is_enabled_2
  # DEBUG BEGIN_STMT
  return is_enabled_2;

}



;; Function pfe_gpi_shp_enable (pfe_gpi_shp_enable, funcdef_no=60, decl_uid=8698, cgraph_uid=61, symbol_order=63)

Modification phase of node pfe_gpi_shp_enable/63
pfe_gpi_shp_enable (struct pfe_gpi_t * gpi, uint8_t id)
{
  errno_t ret;
  unsigned int _1;
  unsigned char _2;
  unsigned int _3;
  long unsigned int _4;
  unsigned int _5;
  unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_9(D)
  # DEBUG id => id_10(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_10(D) > 1)
    goto <bb 5>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_9(D)->gpi_base_va;
  _2 = pfe_gpi_cfg_shp_is_enabled (_1, id_10(D));
  if (_2 != 1)
    goto <bb 4>; [48.88%]
  else
    goto <bb 5>; [51.12%]

  <bb 4> [local count: 295697675]:
  # DEBUG BEGIN_STMT
  _3 = gpi_9(D)->cbus_base_va;
  _4 = pfe_gpi_cfg_get_sys_clk_mhz (_3);
  gpi_9(D)->sys_clk_mhz = _4;
  # DEBUG BEGIN_STMT
  gpi_9(D)->clk_div_log2 = 0;
  # DEBUG BEGIN_STMT
  _5 = gpi_9(D)->gpi_base_va;
  pfe_gpi_cfg_shp_default_init (_5, id_10(D));
  # DEBUG BEGIN_STMT
  _6 = gpi_9(D)->gpi_base_va;
  pfe_gpi_cfg_shp_enable (_6, id_10(D));

  <bb 5> [local count: 1073741824]:
  # ret_17 = PHI <22(2), 0(3), 0(4)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  return ret_17;

}



;; Function pfe_gpi_shp_disable (pfe_gpi_shp_disable, funcdef_no=61, decl_uid=8701, cgraph_uid=62, symbol_order=64)

Modification phase of node pfe_gpi_shp_disable/64
pfe_gpi_shp_disable (const struct pfe_gpi_t * gpi, uint8_t id)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_4(D)
  # DEBUG id => id_5(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_5(D) > 1)
    goto <bb 4>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_4(D)->gpi_base_va;
  pfe_gpi_cfg_shp_disable (_1, id_5(D));

  <bb 4> [local count: 1073741824]:
  # ret_7 = PHI <22(2), 0(3)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_gpi_shp_set_mode (pfe_gpi_shp_set_mode, funcdef_no=62, decl_uid=8708, cgraph_uid=63, symbol_order=65)

Modification phase of node pfe_gpi_shp_set_mode/65
pfe_gpi_shp_set_mode (const struct pfe_gpi_t * gpi, uint8_t id, pfe_iqos_shp_rate_mode_t mode)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_5(D)
  # DEBUG id => id_6(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_6(D) > 1)
    goto <bb 5>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mode_7(D) > 1)
    goto <bb 5>; [61.14%]
  else
    goto <bb 4>; [38.86%]

  <bb 4> [local count: 235082071]:
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  pfe_gpi_cfg_shp_set_mode (_1, id_6(D), mode_7(D));

  <bb 5> [local count: 1073741824]:
  # ret_2 = PHI <22(2), 22(3), 0(4)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_gpi_shp_get_mode (pfe_gpi_shp_get_mode, funcdef_no=63, decl_uid=8712, cgraph_uid=64, symbol_order=66)

Modification phase of node pfe_gpi_shp_get_mode/66
pfe_gpi_shp_get_mode (const struct pfe_gpi_t * gpi, uint8_t id, pfe_iqos_shp_rate_mode_t * mode)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_4(D)
  # DEBUG id => id_5(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_5(D) > 1)
    goto <bb 4>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_4(D)->gpi_base_va;
  pfe_gpi_cfg_shp_get_mode (_1, id_5(D), mode_6(D));

  <bb 4> [local count: 1073741824]:
  # ret_8 = PHI <22(2), 0(3)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  return ret_8;

}



;; Function pfe_gpi_shp_set_type (pfe_gpi_shp_set_type, funcdef_no=64, decl_uid=8716, cgraph_uid=65, symbol_order=67)

Modification phase of node pfe_gpi_shp_set_type/67
pfe_gpi_shp_set_type (const struct pfe_gpi_t * gpi, uint8_t id, pfe_iqos_shp_type_t type)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_5(D)
  # DEBUG id => id_6(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_6(D) > 1)
    goto <bb 5>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (type_7(D) > 2)
    goto <bb 5>; [52.23%]
  else
    goto <bb 4>; [47.77%]

  <bb 4> [local count: 288982773]:
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  pfe_gpi_cfg_shp_set_type (_1, id_6(D), type_7(D));

  <bb 5> [local count: 1073741824]:
  # ret_2 = PHI <22(2), 22(3), 0(4)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_gpi_shp_get_type (pfe_gpi_shp_get_type, funcdef_no=65, decl_uid=8720, cgraph_uid=66, symbol_order=68)

Modification phase of node pfe_gpi_shp_get_type/68
pfe_gpi_shp_get_type (const struct pfe_gpi_t * gpi, uint8_t id, pfe_iqos_shp_type_t * type)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_4(D)
  # DEBUG id => id_5(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_5(D) > 1)
    goto <bb 4>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_4(D)->gpi_base_va;
  pfe_gpi_cfg_shp_get_type (_1, id_5(D), type_6(D));

  <bb 4> [local count: 1073741824]:
  # ret_8 = PHI <22(2), 0(3)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  return ret_8;

}



;; Function pfe_gpi_shp_set_idle_slope (pfe_gpi_shp_set_idle_slope, funcdef_no=66, decl_uid=8724, cgraph_uid=67, symbol_order=69)

Modification phase of node pfe_gpi_shp_set_idle_slope/69
pfe_gpi_shp_set_idle_slope (struct pfe_gpi_t * gpi, uint8_t id, uint32_t isl)
{
  errno_t ret;
  bool_t is_bps;
  uint32_t weight;
  pfe_iqos_shp_rate_mode_t mode;
  unsigned int _1;
  <unnamed type> mode.3_2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned int _5;
  long unsigned int weight.4_6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  mode = 0;
  # DEBUG BEGIN_STMT
  weight = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_12(D)
  # DEBUG id => id_13(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_13(D) > 1)
    goto <bb 6>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_12(D)->gpi_base_va;
  pfe_gpi_cfg_shp_get_mode (_1, id_13(D), &mode);
  # DEBUG BEGIN_STMT
  mode.3_2 = mode;
  if (mode.3_2 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 302473072]:
  # DEBUG BEGIN_STMT
  # DEBUG is_bps => 0

  <bb 5> [local count: 604946144]:
  # is_bps_7 = PHI <1(3), 0(4)>
  # DEBUG is_bps => is_bps_7
  # DEBUG BEGIN_STMT
  _3 = gpi_12(D)->sys_clk_mhz;
  _4 = igqos_find_optimal_weight (isl_15(D), _3, is_bps_7, &weight);
  gpi_12(D)->clk_div_log2 = _4;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = gpi_12(D)->gpi_base_va;
  weight.4_6 = weight;
  pfe_gpi_cfg_shp_set_isl_weight (_5, id_13(D), _4, weight.4_6);

  <bb 6> [local count: 1073741824]:
  # ret_21 = PHI <22(2), 0(5)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  mode ={v} {CLOBBER};
  weight ={v} {CLOBBER};
  return ret_21;

}



;; Function pfe_gpi_shp_get_idle_slope (pfe_gpi_shp_get_idle_slope, funcdef_no=67, decl_uid=8728, cgraph_uid=68, symbol_order=70)

Modification phase of node pfe_gpi_shp_get_idle_slope/70
pfe_gpi_shp_get_idle_slope (const struct pfe_gpi_t * gpi, uint8_t id, uint32_t * isl)
{
  errno_t ret;
  bool_t is_bps;
  uint32_t weight;
  pfe_iqos_shp_rate_mode_t mode;
  unsigned int _1;
  <unnamed type> mode.5_2;
  unsigned int _3;
  long unsigned int weight.6_4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  mode = 0;
  # DEBUG BEGIN_STMT
  weight = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_13(D)
  # DEBUG id => id_14(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_14(D) > 1)
    goto <bb 6>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_13(D)->gpi_base_va;
  pfe_gpi_cfg_shp_get_mode (_1, id_14(D), &mode);
  # DEBUG BEGIN_STMT
  mode.5_2 = mode;
  if (mode.5_2 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 302473072]:
  # DEBUG BEGIN_STMT
  # DEBUG is_bps => 0

  <bb 5> [local count: 604946144]:
  # is_bps_8 = PHI <1(3), 0(4)>
  # DEBUG is_bps => is_bps_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = gpi_13(D)->gpi_base_va;
  pfe_gpi_cfg_shp_get_isl_weight (_3, id_14(D), &weight);
  # DEBUG BEGIN_STMT
  weight.6_4 = weight;
  _5 = gpi_13(D)->clk_div_log2;
  _6 = gpi_13(D)->sys_clk_mhz;
  _7 = igqos_convert_weight_to_isl (weight.6_4, _5, _6, is_bps_8);
  *isl_17(D) = _7;

  <bb 6> [local count: 1073741824]:
  # ret_21 = PHI <22(2), 0(5)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mode ={v} {CLOBBER};
  weight ={v} {CLOBBER};
  return ret_21;

}



;; Function pfe_gpi_shp_set_limits (pfe_gpi_shp_set_limits, funcdef_no=68, decl_uid=8733, cgraph_uid=69, symbol_order=71)

Modification phase of node pfe_gpi_shp_set_limits/71
pfe_gpi_shp_set_limits (const struct pfe_gpi_t * gpi, uint8_t id, int32_t max_credit, int32_t min_credit)
{
  errno_t ret;
  unsigned int max_credit.7_1;
  unsigned int min_credit.8_2;
  unsigned int _3;
  unsigned int _4;
  long int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_10(D)
  # DEBUG id => id_11(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_11(D) > 1)
    goto <bb 8>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  max_credit.7_1 = (unsigned int) max_credit_12(D);
  if (max_credit.7_1 > 4194303)
    goto <bb 4>; [20.96%]
  else
    goto <bb 5>; [79.04%]

  <bb 4> [local count: 126796712]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Max credit value exceeded\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_gpi.c", 1470, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 478149431]:
  # DEBUG BEGIN_STMT
  min_credit.8_2 = (unsigned int) min_credit_13(D);
  _3 = min_credit.8_2 + 4194303;
  if (_3 > 4194303)
    goto <bb 6>; [35.00%]
  else
    goto <bb 7>; [65.00%]

  <bb 6> [local count: 167352301]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Min credit value exceeded\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_gpi.c", 1475, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 310797130]:
  # DEBUG BEGIN_STMT
  _4 = gpi_10(D)->gpi_base_va;
  _5 = -min_credit_13(D);
  _6 = (long unsigned int) _5;
  pfe_gpi_cfg_shp_set_limits (_4, id_11(D), max_credit.7_1, _6);

  <bb 8> [local count: 1073741824]:
  # ret_7 = PHI <22(2), 22(4), 22(6), 0(7)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_gpi_shp_get_limits (pfe_gpi_shp_get_limits, funcdef_no=69, decl_uid=8738, cgraph_uid=70, symbol_order=72)

Modification phase of node pfe_gpi_shp_get_limits/72
pfe_gpi_shp_get_limits (const struct pfe_gpi_t * gpi, uint8_t id, int32_t * max_credit, int32_t * min_credit)
{
  errno_t ret;
  uint32_t abs_min_cred;
  uint32_t abs_max_cred;
  unsigned int _1;
  long unsigned int abs_max_cred.10_2;
  signed int abs_max_cred.11_3;
  long unsigned int abs_min_cred.12_4;
  signed int abs_min_cred.13_5;
  long int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  abs_max_cred = 0;
  abs_min_cred = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_11(D)
  # DEBUG id => id_12(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_12(D) > 1)
    goto <bb 4>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_11(D)->gpi_base_va;
  pfe_gpi_cfg_shp_get_limits (_1, id_12(D), &abs_max_cred, &abs_min_cred);
  # DEBUG BEGIN_STMT
  abs_max_cred.10_2 = abs_max_cred;
  abs_max_cred.11_3 = (signed int) abs_max_cred.10_2;
  # DEBUG BEGIN_STMT
  abs_min_cred.12_4 = abs_min_cred;
  abs_min_cred.13_5 = (signed int) abs_min_cred.12_4;
  # DEBUG BEGIN_STMT
  *max_credit_14(D) = abs_max_cred.11_3;
  # DEBUG BEGIN_STMT
  _6 = -abs_min_cred.13_5;
  *min_credit_16(D) = _6;

  <bb 4> [local count: 1073741824]:
  # ret_20 = PHI <22(2), 0(3)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  abs_max_cred ={v} {CLOBBER};
  abs_min_cred ={v} {CLOBBER};
  return ret_20;

}



;; Function pfe_gpi_shp_get_drop_cnt (pfe_gpi_shp_get_drop_cnt, funcdef_no=70, decl_uid=8742, cgraph_uid=71, symbol_order=73)

Modification phase of node pfe_gpi_shp_get_drop_cnt/73
pfe_gpi_shp_get_drop_cnt (const struct pfe_gpi_t * gpi, uint8_t id, uint32_t * cnt)
{
  errno_t ret;
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#12 => gpi_5(D)
  # DEBUG id => id_6(D)
  # DEBUG INLINE_ENTRY pfe_gpi_shp_args_checks
  # DEBUG gpi => D#12
  # DEBUG D#11 => D#12
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => D#11
  # DEBUG D#2 => 22
  # DEBUG INLINE_ENTRY NULL
  # DEBUG gpi => D#1
  # DEBUG err => D#2
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (id_6(D) > 1)
    goto <bb 4>; [43.66%]
  else
    goto <bb 3>; [56.34%]

  <bb 3> [local count: 604946144]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_5(D)->gpi_base_va;
  _2 = pfe_gpi_cfg_shp_get_drop_cnt (_1, id_6(D));
  *cnt_8(D) = _2;

  <bb 4> [local count: 1073741824]:
  # ret_10 = PHI <22(2), 0(3)>
  # DEBUG id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  return ret_10;

}



;; Function pfe_gpi_get_stat_value (pfe_gpi_get_stat_value, funcdef_no=71, decl_uid=8745, cgraph_uid=72, symbol_order=74)

Modification phase of node pfe_gpi_get_stat_value/74
pfe_gpi_get_stat_value (const struct pfe_gpi_t * gpi, uint32_t stat_id)
{
  uint32_t stat_value;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = gpi_3(D)->gpi_base_va;
  stat_value_6 = pfe_gpi_cfg_get_stat_value (_1, stat_id_4(D));
  # DEBUG stat_value => stat_value_6
  # DEBUG BEGIN_STMT
  return stat_value_6;

}



;; Function pfe_gpi_get_special_stats (pfe_gpi_get_special_stats, funcdef_no=72, decl_uid=8748, cgraph_uid=73, symbol_order=75)

Modification phase of node pfe_gpi_get_special_stats/75
pfe_gpi_get_special_stats (const struct pfe_gpi_t * gpi, struct pfe_gpi_special_stats_t * special_stats)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = gpi_3(D)->gpi_base_va;
  pfe_gpi_cfg_get_special_stats (_1, special_stats_4(D));
  # DEBUG BEGIN_STMT
  return 0;

}


