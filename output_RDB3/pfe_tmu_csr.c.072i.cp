
IPA constant propagation start:
Determining dynamic type for call: ret_12 = pfe_tmu_cntx_mem_read (cbus_base_va_3(D), phy_1(D), _11, &reg);
  Starting walk at: ret_12 = pfe_tmu_cntx_mem_read (cbus_base_va_3(D), phy_1(D), _11, &reg);
  instance pointer: &reg  Outer instance pointer: reg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:queue_temp_5 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_3(D), phy_1(D), queue_4(D));
Determining dynamic type for call: _3 = pfe_tmu_q_cfg_get_fill_level (base_va_34(D), _1, _2, &reg);
  Starting walk at: _3 = pfe_tmu_q_cfg_get_fill_level (base_va_34(D), _1, _2, &reg);
  instance pointer: &reg  Outer instance pointer: reg offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = pfe_tmu_q_cfg_get_drop_count (base_va_34(D), _1, _2, &reg);
  Starting walk at: _4 = pfe_tmu_q_cfg_get_drop_count (base_va_34(D), _1, _2, &reg);
  instance pointer: &reg  Outer instance pointer: reg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_tmu_q_cfg_get_fill_level (base_va_34(D), _1, _2, &reg);
Determining dynamic type for call: _5 = pfe_tmu_q_cfg_get_tx_count (base_va_34(D), _1, _2, &reg);
  Starting walk at: _5 = pfe_tmu_q_cfg_get_tx_count (base_va_34(D), _1, _2, &reg);
  instance pointer: &reg  Outer instance pointer: reg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = pfe_tmu_q_cfg_get_drop_count (base_va_34(D), _1, _2, &reg);
  Function call may change dynamic type:_3 = pfe_tmu_q_cfg_get_fill_level (base_va_34(D), _1, _2, &reg);
Determining dynamic type for call: _8 = pfe_tmu_cntx_mem_read (base_va_34(D), _1, _7, &reg);
  Starting walk at: _8 = pfe_tmu_cntx_mem_read (base_va_34(D), _1, _7, &reg);
  instance pointer: &reg  Outer instance pointer: reg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = pfe_tmu_q_cfg_get_tx_count (base_va_34(D), _1, _2, &reg);
  Function call may change dynamic type:_4 = pfe_tmu_q_cfg_get_drop_count (base_va_34(D), _1, _2, &reg);
  Function call may change dynamic type:_3 = pfe_tmu_q_cfg_get_fill_level (base_va_34(D), _1, _2, &reg);
Determining dynamic type for call: _17 = pfe_tmu_q_get_wred_probability (base_va_34(D), _1, _2, zone_21, &prob);
  Starting walk at: _17 = pfe_tmu_q_get_wred_probability (base_va_34(D), _1, _2, zone_21, &prob);
  instance pointer: &prob  Outer instance pointer: prob offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = pfe_tmu_cntx_mem_read (base_va_34(D), _1, _7, &reg);
  Function call may change dynamic type:_5 = pfe_tmu_q_cfg_get_tx_count (base_va_34(D), _1, _2, &reg);
  Function call may change dynamic type:_4 = pfe_tmu_q_cfg_get_drop_count (base_va_34(D), _1, _2, &reg);
  Function call may change dynamic type:_3 = pfe_tmu_q_cfg_get_fill_level (base_va_34(D), _1, _2, &reg);
  Function call may change dynamic type:_17 = pfe_tmu_q_get_wred_probability (base_va_34(D), _1, _2, zone_21, &prob);
Determining dynamic type for call: ret_8 = pfe_tmu_q_get_wred_probability.part.0 (cbus_base_va_6(D), phy_4(D), queue_2(D), zone_3(D), prob_9(D));
  Starting walk at: ret_8 = pfe_tmu_q_get_wred_probability.part.0 (cbus_base_va_6(D), phy_4(D), queue_2(D), zone_3(D), prob_9(D));
  instance pointer: prob_9(D)  Outer instance pointer: prob_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_30 = pfe_tmu_cntx_mem_read (cbus_base_va_25(D), phy_23(D), _4, &reg);
  Starting walk at: ret_30 = pfe_tmu_cntx_mem_read (cbus_base_va_25(D), phy_23(D), _4, &reg);
  instance pointer: &reg  Outer instance pointer: reg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:queue_temp_27 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_25(D), phy_23(D), queue_20(D));
Determining dynamic type for call: ret_21 = pfe_tmu_cntx_mem_read (cbus_base_va_17(D), phy_15(D), _3, &reg);
  Starting walk at: ret_21 = pfe_tmu_cntx_mem_read (cbus_base_va_17(D), phy_15(D), _3, &reg);
  instance pointer: &reg  Outer instance pointer: reg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:temp_19 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_17(D), phy_15(D), queue_14(D));
Determining dynamic type for call: ret_14 = pfe_tmu_cntx_mem_read (cbus_base_va_9(D), phy_7(D), _3, cnt_12(D));
  Starting walk at: ret_14 = pfe_tmu_cntx_mem_read (cbus_base_va_9(D), phy_7(D), _3, cnt_12(D));
  instance pointer: cnt_12(D)  Outer instance pointer: cnt_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:temp_11 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_9(D), phy_7(D), queue_6(D));
Determining dynamic type for call: ret_15 = pfe_tmu_cntx_mem_read (cbus_base_va_11(D), phy_9(D), _3, &drops);
  Starting walk at: ret_15 = pfe_tmu_cntx_mem_read (cbus_base_va_11(D), phy_9(D), _3, &drops);
  instance pointer: &drops  Outer instance pointer: drops offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:temp_13 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_11(D), phy_9(D), queue_8(D));
Determining dynamic type for call: ret_14 = pfe_tmu_cntx_mem_read (cbus_base_va_9(D), phy_7(D), _3, level_12(D));
  Starting walk at: ret_14 = pfe_tmu_cntx_mem_read (cbus_base_va_9(D), phy_7(D), _3, level_12(D));
  instance pointer: level_12(D)  Outer instance pointer: level_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:queue_temp_11 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_9(D), phy_7(D), queue_6(D));
Determining dynamic type for call: pfe_tmu_cntx_mem_read (cbus_base_va_44(D), 0, 2, &dropped_packets);
  Starting walk at: pfe_tmu_cntx_mem_read (cbus_base_va_44(D), 0, 2, &dropped_packets);
  instance pointer: &dropped_packets  Outer instance pointer: dropped_packets offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:_26 = pfe_tmu_context_memory (cbus_base_va_44(D), 0, 0, 0, 0);
  Function call may change dynamic type:_25 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  Function call may change dynamic type:pfe_tmu_cntx_mem_read (cbus_base_va_44(D), 0, 2, &dropped_packets);
  Function call may change dynamic type:oal_time_usleep (10);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_tmu_sch_cfg_bind_queue.part.0/80:
  Jump functions of caller  pfe_tmu_sch_cfg_set_algo.part.0/74:
  Jump functions of caller  pfe_tmu_q_get_wred_probability.part.0/73:
    callsite  pfe_tmu_q_get_wred_probability.part.0/73 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_tmu_q_get_wred_probability.part.0/73 -> pfe_tmu_cntx_mem_read/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_tmu_q_mode_set_tail_drop.part.0/72:
    callsite  pfe_tmu_q_mode_set_tail_drop.part.0/72 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_tmu_q_mode_set_tail_drop.part.0/72 -> pfe_tmu_cntx_mem_write/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfc
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x7f801
         VR  [1, 522241]
  Jump functions of caller  pfe_tmu_cfg_reset.part.0/71:
  Jump functions of caller  pfe_tmu_hif_q_to_tmu_q.part.0/70:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/68:
  Jump functions of caller  pfe_hm_report/67:
  Jump functions of caller  oal_time_usleep/66:
  Jump functions of caller  pfe_feature_mgr_is_available/65:
  Jump functions of caller  pfe_tmu_cfg_get_queue_stats/64:
    callsite  pfe_tmu_cfg_get_queue_stats/64 -> pfe_tmu_q_get_wred_probability/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
       param 3: UNKNOWN
         value: 0x0, mask: 0x3f
         VR  [0, 32]
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_tmu_cfg_get_queue_stats/64 -> pfe_tmu_cntx_mem_read/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x3c
         VR  [4, 60]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_tmu_cfg_get_queue_stats/64 -> pfe_tmu_q_cfg_get_tx_count/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_tmu_cfg_get_queue_stats/64 -> pfe_tmu_q_cfg_get_drop_count/31 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_tmu_cfg_get_queue_stats/64 -> pfe_tmu_q_cfg_get_fill_level/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
       param 3: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_tmu_cfg_get_special_stats/63:
  Jump functions of caller  pfe_tmu_cfg_get_stat_value/62:
  Jump functions of caller  pfe_tmu_sch_cfg_get_bound_sched_output/61:
  Jump functions of caller  pfe_tmu_sch_cfg_bind_sched_output/60:
    callsite  pfe_tmu_sch_cfg_bind_sched_output/60 -> pfe_tmu_sch_cfg_bind_queue/58 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: CONST: 255
         value: 0xff, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_tmu_sch_cfg_get_bound_queue/59:
  Jump functions of caller  pfe_tmu_sch_cfg_bind_queue/58:
    callsite  pfe_tmu_sch_cfg_bind_queue/58 -> pfe_tmu_sch_cfg_bind_queue.part.0/80 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_sch_cfg_get_input_weight/57:
  Jump functions of caller  pfe_tmu_sch_cfg_set_input_weight/56:
  Jump functions of caller  pfe_tmu_sch_cfg_get_algo/55:
  Jump functions of caller  pfe_tmu_sch_cfg_set_algo/54:
    callsite  pfe_tmu_sch_cfg_set_algo/54 -> pfe_tmu_sch_cfg_set_algo.part.0/74 : 
    callsite  pfe_tmu_sch_cfg_set_algo/54 -> pfe_tmu_sch_cfg_get_rate_mode/53 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_sch_cfg_get_rate_mode/53:
  Jump functions of caller  pfe_tmu_sch_cfg_set_rate_mode/52:
  Jump functions of caller  pfe_tmu_sch_cfg_init/51:
  Jump functions of caller  pfe_tmu_shp_cfg_init/50:
    callsite  pfe_tmu_shp_cfg_init/50 -> pfe_tmu_shp_cfg_disable/49 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_shp_cfg_disable/49:
  Jump functions of caller  pfe_tmu_shp_cfg_get_idle_slope/48:
    callsite  pfe_tmu_shp_cfg_get_idle_slope/48 -> pfe_tmu_shp_cfg_get_rate_mode/46 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_shp_cfg_set_idle_slope/47:
    callsite  pfe_tmu_shp_cfg_set_idle_slope/47 -> pfe_tmu_shp_cfg_get_rate_mode/46 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_shp_cfg_get_rate_mode/46:
  Jump functions of caller  pfe_tmu_shp_cfg_set_rate_mode/45:
  Jump functions of caller  pfe_tmu_shp_cfg_enable/44:
  Jump functions of caller  pfe_tmu_shp_cfg_get_position/43:
  Jump functions of caller  pfe_tmu_shp_cfg_set_position/42:
  Jump functions of caller  pfe_tmu_shp_cfg_get_limits/41:
  Jump functions of caller  pfe_tmu_shp_cfg_set_limits/40:
  Jump functions of caller  pfe_tmu_q_get_wred_zones/39:
  Jump functions of caller  pfe_tmu_q_get_wred_probability/38:
    callsite  pfe_tmu_q_get_wred_probability/38 -> pfe_tmu_q_get_wred_probability.part.0/73 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_tmu_q_set_wred_probability/37:
    callsite  pfe_tmu_q_set_wred_probability/37 -> pfe_tmu_cntx_mem_write/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_tmu_q_set_wred_probability/37 -> pfe_tmu_cntx_mem_read/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_tmu_q_set_wred_probability/37 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_q_mode_set_wred/36:
    callsite  pfe_tmu_q_mode_set_wred/36 -> pfe_tmu_context_memory/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pfe_tmu_q_mode_set_wred/36 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_q_mode_set_tail_drop/35:
    callsite  pfe_tmu_q_mode_set_tail_drop/35 -> pfe_tmu_q_mode_set_tail_drop.part.0/72 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pfe_tmu_q_mode_set_default/34:
    callsite  pfe_tmu_q_mode_set_default/34 -> pfe_tmu_cntx_mem_write/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfc
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_q_mode_set_default/34 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_q_get_mode/33:
    callsite  pfe_tmu_q_get_mode/33 -> pfe_tmu_cntx_mem_read/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfc
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_tmu_q_get_mode/33 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_q_cfg_get_tx_count/32:
    callsite  pfe_tmu_q_cfg_get_tx_count/32 -> pfe_tmu_cntx_mem_read/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfb
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_tmu_q_cfg_get_tx_count/32 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_q_cfg_get_drop_count/31:
    callsite  pfe_tmu_q_cfg_get_drop_count/31 -> pfe_tmu_reclaim_mem_wrkarnd/30 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_tmu_q_cfg_get_drop_count/31 -> pfe_tmu_cntx_mem_read/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfa
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_tmu_q_cfg_get_drop_count/31 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_reclaim_mem_wrkarnd/30:
  Jump functions of caller  pfe_tmu_q_cfg_get_fill_level/29:
    callsite  pfe_tmu_q_cfg_get_fill_level/29 -> pfe_tmu_cntx_mem_read/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xf9
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_tmu_q_cfg_get_fill_level/29 -> pfe_tmu_hif_q_to_tmu_q/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_context_memory/28:
    callsite  pfe_tmu_context_memory/28 -> pfe_tmu_cntx_mem_write/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfc
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x7fffffe
         VR  [2, 134217727]
    callsite  pfe_tmu_context_memory/28 -> pfe_tmu_cntx_mem_write/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfe
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_context_memory/28 -> pfe_tmu_cntx_mem_write/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfd
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_tmu_hif_q_to_tmu_q/27:
    callsite  pfe_tmu_hif_q_to_tmu_q/27 -> pfe_tmu_hif_q_to_tmu_q.part.0/70 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_tmu_cntx_mem_read/26:
  Jump functions of caller  pfe_tmu_cntx_mem_write/25:
  Jump functions of caller  pfe_tmu_cfg_disable/24:
  Jump functions of caller  pfe_tmu_cfg_enable/23:
  Jump functions of caller  pfe_tmu_cfg_reset/22:
    callsite  pfe_tmu_cfg_reset/22 -> pfe_tmu_cfg_reset.part.0/71 : 
  Jump functions of caller  pfe_tmu_cfg_init/21:
    callsite  pfe_tmu_cfg_init/21 -> pfe_tmu_set_default_queue_mode/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 6]
       param 2: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
    callsite  pfe_tmu_cfg_init/21 -> pfe_tmu_tdq_shp_on_phy5_g2/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 6]
    callsite  pfe_tmu_cfg_init/21 -> pfe_tmu_cfg_reset/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_tmu_tdq_shp_on_phy5_g2/20:
    callsite  pfe_tmu_tdq_shp_on_phy5_g2/20 -> pfe_tmu_sch_cfg_bind_queue/58 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [0, 8]
       param 4: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [0, 8]
    callsite  pfe_tmu_tdq_shp_on_phy5_g2/20 -> pfe_tmu_shp_cfg_init/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_tdq_shp_on_phy5_g2/20 -> pfe_tmu_shp_cfg_init/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_tdq_shp_on_phy5_g2/20 -> pfe_tmu_shp_cfg_init/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_tdq_shp_on_phy5_g2/20 -> pfe_tmu_shp_cfg_init/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_tdq_shp_on_phy5_g2/20 -> pfe_tmu_sch_cfg_init/51 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_tdq_shp_on_phy5_g2/20 -> pfe_tmu_sch_cfg_init/51 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_tmu_set_default_queue_mode/19:
    callsite  pfe_tmu_set_default_queue_mode/19 -> pfe_tmu_q_mode_set_tail_drop.part.0/72 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [0, 8]
       param 3: CONST: 31
         value: 0x1f, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_set_default_queue_mode/19 -> pfe_tmu_q_mode_set_tail_drop.part.0/72 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [0, 8]
       param 3: CONST: 16
         value: 0x10, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_set_default_queue_mode/19 -> pfe_tmu_sch_cfg_set_rate_mode/52 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_tmu_q_reset_tail_drop_policy/18:
    callsite  pfe_tmu_q_reset_tail_drop_policy/18 -> pfe_tmu_q_mode_set_tail_drop/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [0, 8]
       param 3: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
  Jump functions of caller  pfe_tmu_reclaim_init/17:
    callsite  pfe_tmu_reclaim_init/17 -> pfe_tmu_q_mode_set_default/34 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_tmu_reclaim_init/17 -> pfe_tmu_cntx_mem_read/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_tmu_reclaim_init/17 -> pfe_tmu_context_memory/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_tmu_cfg_get_phy_config/16:

 Propagating constants:

Not considering pfe_tmu_cfg_get_queue_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_cfg_get_special_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_cfg_get_stat_value for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_get_bound_sched_output for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_bind_sched_output for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_get_bound_queue for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_bind_queue for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_get_input_weight for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_set_input_weight for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_get_algo for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_set_algo for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_get_rate_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_set_rate_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_sch_cfg_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_get_idle_slope for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_set_idle_slope for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_get_rate_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_set_rate_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_get_position for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_set_position for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_get_limits for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_shp_cfg_set_limits for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_get_wred_zones for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_get_wred_probability for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_set_wred_probability for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_mode_set_wred for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_mode_set_tail_drop for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_mode_set_default for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_get_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_cfg_get_tx_count for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_cfg_get_drop_count for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_cfg_get_fill_level for cloning; -fipa-cp-clone disabled.
Function pfe_tmu_cfg_disable/24 is not versionable, reason: not a tree_versionable_function.
Not considering pfe_tmu_cfg_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_cfg_reset for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_cfg_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_q_reset_tail_drop_policy for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_reclaim_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_tmu_cfg_get_phy_config for cloning; -fipa-cp-clone disabled.

overall_size: 1391, max_new_size: 11001
 - context independent values, size: 10, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 3.000000
 - context independent values, size: 2, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: pfe_tmu_sch_cfg_bind_queue.part.0/80:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_tmu_sch_cfg_set_algo.part.0/74:
  Node: pfe_tmu_q_get_wred_probability.part.0/73:
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
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_tmu_q_mode_set_tail_drop.part.0/72:
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
               16 [loc_time: 2, loc_size: 21, prop_time: 0, prop_size: 0]
               31 [loc_time: 2, loc_size: 21, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_tmu_cfg_reset.part.0/71:
  Node: pfe_tmu_hif_q_to_tmu_q.part.0/70:
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
  Node: pfe_tmu_cfg_get_queue_stats/64:
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
  Node: pfe_tmu_cfg_get_special_stats/63:
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
  Node: pfe_tmu_cfg_get_stat_value/62:
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
  Node: pfe_tmu_sch_cfg_get_bound_sched_output/61:
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
  Node: pfe_tmu_sch_cfg_bind_sched_output/60:
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
  Node: pfe_tmu_sch_cfg_get_bound_queue/59:
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
  Node: pfe_tmu_sch_cfg_bind_queue/58:
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
  Node: pfe_tmu_sch_cfg_get_input_weight/57:
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
  Node: pfe_tmu_sch_cfg_set_input_weight/56:
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
  Node: pfe_tmu_sch_cfg_get_algo/55:
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
  Node: pfe_tmu_sch_cfg_set_algo/54:
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
  Node: pfe_tmu_sch_cfg_get_rate_mode/53:
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
  Node: pfe_tmu_sch_cfg_set_rate_mode/52:
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
  Node: pfe_tmu_sch_cfg_init/51:
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
  Node: pfe_tmu_shp_cfg_init/50:
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
  Node: pfe_tmu_shp_cfg_disable/49:
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
  Node: pfe_tmu_shp_cfg_get_idle_slope/48:
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
  Node: pfe_tmu_shp_cfg_set_idle_slope/47:
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
  Node: pfe_tmu_shp_cfg_get_rate_mode/46:
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
  Node: pfe_tmu_shp_cfg_set_rate_mode/45:
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
  Node: pfe_tmu_shp_cfg_enable/44:
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
  Node: pfe_tmu_shp_cfg_get_position/43:
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
  Node: pfe_tmu_shp_cfg_set_position/42:
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
  Node: pfe_tmu_shp_cfg_get_limits/41:
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
  Node: pfe_tmu_shp_cfg_set_limits/40:
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
  Node: pfe_tmu_q_get_wred_zones/39:
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
  Node: pfe_tmu_q_get_wred_probability/38:
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
  Node: pfe_tmu_q_set_wred_probability/37:
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
  Node: pfe_tmu_q_mode_set_wred/36:
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
  Node: pfe_tmu_q_mode_set_tail_drop/35:
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
  Node: pfe_tmu_q_mode_set_default/34:
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
  Node: pfe_tmu_q_get_mode/33:
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
  Node: pfe_tmu_q_cfg_get_tx_count/32:
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
  Node: pfe_tmu_q_cfg_get_drop_count/31:
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
  Node: pfe_tmu_reclaim_mem_wrkarnd/30:
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
  Node: pfe_tmu_q_cfg_get_fill_level/29:
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
  Node: pfe_tmu_context_memory/28:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 1, loc_size: 33, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
               0 [loc_time: 3, loc_size: 29, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
               0 [loc_time: 1, loc_size: 32, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
               0 [loc_time: 1, loc_size: 32, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_tmu_hif_q_to_tmu_q/27:
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
  Node: pfe_tmu_cntx_mem_read/26:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 5, loc_size: 26, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
               2 [loc_time: 1, loc_size: 36, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_tmu_cntx_mem_write/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 5, loc_size: 25, prop_time: 0, prop_size: 0]
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
               0 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_tmu_cfg_disable/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_tmu_cfg_enable/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_tmu_cfg_reset/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_tmu_cfg_init/21:
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
  Node: pfe_tmu_tdq_shp_on_phy5_g2/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint32_t [0, 6]
        AGGS VARIABLE
  Node: pfe_tmu_set_default_queue_mode/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint32_t [0, 6]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         bool_t [0, 1]
        AGGS VARIABLE
  Node: pfe_tmu_q_reset_tail_drop_policy/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_tmu_reclaim_init/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_tmu_cfg_get_phy_config/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:

Propagated bits info for function pfe_tmu_tdq_shp_on_phy5_g2/20:
 param 1: value = 0x0, mask = 0x7
Propagated bits info for function pfe_tmu_set_default_queue_mode/19:
 param 1: value = 0x0, mask = 0x7
 param 2: value = 0x0, mask = 0x1

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_tmu_sch_cfg_bind_queue.part.0/80 (pfe_tmu_sch_cfg_bind_queue.part.0) @06fa59a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_tmu_sch_cfg_bind_queue/58 (177884490 (estimated locally),0.17 per call) 
  Calls: pfe_hm_report/67 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/68 (1073741824 (estimated locally),1.00 per call) 
CSWTCH.82/79 (CSWTCH.82) @07a28cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: pfe_tmu_sch_cfg_get_algo/55 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_tmu_sch_cfg_set_algo.part.0/74 (pfe_tmu_sch_cfg_set_algo.part.0) @06fa5700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_tmu_sch_cfg_set_algo/54 (25460437 (estimated locally),0.02 per call) 
  Calls: pfe_hm_report/67 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/68 (1073741824 (estimated locally),1.00 per call) 
pfe_tmu_q_get_wred_probability.part.0/73 (pfe_tmu_q_get_wred_probability.part.0) @0704b540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_tmu_q_get_wred_probability/38 (697932184 (estimated locally),0.65 per call) 
  Calls: pfe_tmu_hif_q_to_tmu_q/27 (536870913 (estimated locally),0.50 per call) pfe_tmu_cntx_mem_read/26 (957133463 (estimated locally),0.89 per call) 
pfe_tmu_q_mode_set_tail_drop.part.0/72 (pfe_tmu_q_mode_set_tail_drop.part.0) @0702dc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_tmu_set_default_queue_mode/19 (629936411 (estimated locally),3.41 per call) pfe_tmu_set_default_queue_mode/19 (324512696 (estimated locally),1.76 per call) pfe_tmu_q_mode_set_tail_drop/35 (697932184 (estimated locally),0.65 per call) 
  Calls: pfe_tmu_hif_q_to_tmu_q/27 (536870913 (estimated locally),0.50 per call) pfe_tmu_cntx_mem_write/25 (957133463 (estimated locally),0.89 per call) 
pfe_tmu_cfg_reset.part.0/71 (pfe_tmu_cfg_reset.part.0) @0702d9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_tmu_cfg_reset/22 (22836878 (estimated locally),0.33 per call) 
  Calls: pfe_hm_report/67 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/68 (1073741824 (estimated locally),1.00 per call) 
pfe_tmu_hif_q_to_tmu_q.part.0/70 (pfe_tmu_hif_q_to_tmu_q.part.0) @06df3d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:137140916 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_tmu_hif_q_to_tmu_q/27 (137140916 (estimated locally),0.65 per call) 
  Calls: 
Eth_43_PFE_InternalCfgPtr/69 (Eth_43_PFE_InternalCfgPtr) @07864630
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: pfe_tmu_q_reset_tail_drop_policy/18 (read)
  Availability: not_available
  Varpool flags:
oal_util_raise_dem_for_drv_runtime_err/68 (oal_util_raise_dem_for_drv_runtime_err) @07852a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_tmu_sch_cfg_bind_sched_output/60 (801907846 (estimated locally),0.75 per call) pfe_tmu_sch_cfg_get_bound_queue/59 (225056286 (estimated locally),0.21 per call) pfe_tmu_sch_cfg_bind_queue/58 (225056286 (estimated locally),0.21 per call) pfe_tmu_sch_cfg_bind_queue.part.0/80 (1073741824 (estimated locally),1.00 per call) pfe_tmu_sch_cfg_get_input_weight/57 (354334802 (estimated locally),0.33 per call) pfe_tmu_sch_cfg_set_input_weight/56 (225056286 (estimated locally),0.21 per call) pfe_tmu_sch_cfg_set_algo.part.0/74 (1073741824 (estimated locally),1.00 per call) pfe_tmu_shp_cfg_set_position/42 (225056286 (estimated locally),0.21 per call) pfe_tmu_shp_cfg_set_limits/40 (177884489 (estimated locally),0.17 per call) pfe_tmu_shp_cfg_set_limits/40 (225056286 (estimated locally),0.21 per call) pfe_tmu_q_mode_set_wred/36 (522096225 (estimated locally),0.49 per call) pfe_tmu_q_reset_tail_drop_policy/18 (52489451 (estimated locally),1.37 per call) pfe_tmu_reclaim_init/17 (1604094 (estimated locally),0.08 per call) pfe_tmu_cfg_reset.part.0/71 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hm_report/67 (pfe_hm_report) @078529a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_tmu_sch_cfg_bind_sched_output/60 (801907846 (estimated locally),0.75 per call) pfe_tmu_sch_cfg_get_bound_queue/59 (225056286 (estimated locally),0.21 per call) pfe_tmu_sch_cfg_bind_queue/58 (225056286 (estimated locally),0.21 per call) pfe_tmu_sch_cfg_bind_queue.part.0/80 (1073741824 (estimated locally),1.00 per call) pfe_tmu_sch_cfg_get_input_weight/57 (354334802 (estimated locally),0.33 per call) pfe_tmu_sch_cfg_set_input_weight/56 (225056286 (estimated locally),0.21 per call) pfe_tmu_sch_cfg_set_algo.part.0/74 (1073741824 (estimated locally),1.00 per call) pfe_tmu_shp_cfg_set_position/42 (225056286 (estimated locally),0.21 per call) pfe_tmu_shp_cfg_set_limits/40 (177884489 (estimated locally),0.17 per call) pfe_tmu_shp_cfg_set_limits/40 (225056286 (estimated locally),0.21 per call) pfe_tmu_q_mode_set_wred/36 (522096225 (estimated locally),0.49 per call) pfe_tmu_q_reset_tail_drop_policy/18 (52489451 (estimated locally),1.37 per call) pfe_tmu_reclaim_init/17 (1604094 (estimated locally),0.08 per call) pfe_tmu_cfg_reset.part.0/71 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_time_usleep/66 (oal_time_usleep) @078528c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_tmu_reclaim_init/17 (21951157 (estimated locally),1.10 per call) pfe_tmu_cfg_reset/22 (1073741824 (estimated locally),15.52 per call) pfe_tmu_cntx_mem_read/26 (1073741824 (estimated locally),6.52 per call) pfe_tmu_cntx_mem_write/25 (1073741824 (estimated locally),10.34 per call) 
  Calls: 
pfe_feature_mgr_is_available/65 (pfe_feature_mgr_is_available) @078527e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_tmu_reclaim_init/17 (19889078 (estimated locally),1.00 per call) pfe_tmu_reclaim_mem_wrkarnd/30 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_cfg_get_queue_stats/64 (pfe_tmu_cfg_get_queue_stats) @078522a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: phy_if_id_temp/15 (read)
  Referring: 
  Availability: available
  Function flags: count:260275024 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_q_get_wred_probability/38 (1041207447 (estimated locally),4.00 per call) pfe_tmu_cntx_mem_read/26 (260275024 (estimated locally),1.00 per call) pfe_tmu_q_cfg_get_tx_count/32 (260275024 (estimated locally),1.00 per call) pfe_tmu_q_cfg_get_drop_count/31 (260275024 (estimated locally),1.00 per call) pfe_tmu_q_cfg_get_fill_level/29 (260275024 (estimated locally),1.00 per call) 
pfe_tmu_cfg_get_special_stats/63 (pfe_tmu_cfg_get_special_stats) @07852000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_cfg_get_stat_value/62 (pfe_tmu_cfg_get_stat_value) @07849a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_sch_cfg_get_bound_sched_output/61 (pfe_tmu_sch_cfg_get_bound_sched_output) @07849e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_sch_cfg_bind_sched_output/60 (pfe_tmu_sch_cfg_bind_sched_output) @078499a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_sch_cfg_bind_queue/58 (271833978 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/68 (801907846 (estimated locally),0.75 per call) pfe_hm_report/67 (801907846 (estimated locally),0.75 per call) 
pfe_tmu_sch_cfg_get_bound_queue/59 (pfe_tmu_sch_cfg_get_bound_queue) @07849460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/68 (225056286 (estimated locally),0.21 per call) pfe_hm_report/67 (225056286 (estimated locally),0.21 per call) 
pfe_tmu_sch_cfg_bind_queue/58 (pfe_tmu_sch_cfg_bind_queue) @0783eb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_sch_cfg_bind_sched_output/60 (271833978 (estimated locally),0.25 per call) pfe_tmu_tdq_shp_on_phy5_g2/20 (954449109 (estimated locally),5.56 per call) 
  Calls: pfe_tmu_sch_cfg_bind_queue.part.0/80 (177884490 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/68 (225056286 (estimated locally),0.21 per call) pfe_hm_report/67 (225056286 (estimated locally),0.21 per call) 
pfe_tmu_sch_cfg_get_input_weight/57 (pfe_tmu_sch_cfg_get_input_weight) @0783ea80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/68 (354334802 (estimated locally),0.33 per call) pfe_hm_report/67 (354334802 (estimated locally),0.33 per call) 
pfe_tmu_sch_cfg_set_input_weight/56 (pfe_tmu_sch_cfg_set_input_weight) @0783e540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/68 (225056286 (estimated locally),0.21 per call) pfe_hm_report/67 (225056286 (estimated locally),0.21 per call) 
pfe_tmu_sch_cfg_get_algo/55 (pfe_tmu_sch_cfg_get_algo) @0783e000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: CSWTCH.82/79 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_sch_cfg_set_algo/54 (pfe_tmu_sch_cfg_set_algo) @07831ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_sch_cfg_set_algo.part.0/74 (25460437 (estimated locally),0.02 per call) pfe_tmu_sch_cfg_get_rate_mode/53 (74905668 (estimated locally),0.07 per call) 
pfe_tmu_sch_cfg_get_rate_mode/53 (pfe_tmu_sch_cfg_get_rate_mode) @078319a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_sch_cfg_set_algo/54 (74905668 (estimated locally),0.07 per call) 
  Calls: 
pfe_tmu_sch_cfg_set_rate_mode/52 (pfe_tmu_sch_cfg_set_rate_mode) @07831540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_set_default_queue_mode/19 (37420653 (estimated locally),0.20 per call) 
  Calls: 
pfe_tmu_sch_cfg_init/51 (pfe_tmu_sch_cfg_init) @078310e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_tdq_shp_on_phy5_g2/20 (171787418 (estimated locally),1.00 per call) pfe_tmu_tdq_shp_on_phy5_g2/20 (171787418 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_shp_cfg_init/50 (pfe_tmu_shp_cfg_init) @0772cd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_tdq_shp_on_phy5_g2/20 (171787418 (estimated locally),1.00 per call) pfe_tmu_tdq_shp_on_phy5_g2/20 (171787418 (estimated locally),1.00 per call) pfe_tmu_tdq_shp_on_phy5_g2/20 (171787418 (estimated locally),1.00 per call) pfe_tmu_tdq_shp_on_phy5_g2/20 (171787418 (estimated locally),1.00 per call) 
  Calls: pfe_tmu_shp_cfg_disable/49 (1073741824 (estimated locally),1.00 per call) 
pfe_tmu_shp_cfg_disable/49 (pfe_tmu_shp_cfg_disable) @0772c700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_shp_cfg_init/50 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_shp_cfg_get_idle_slope/48 (pfe_tmu_shp_cfg_get_idle_slope) @0772c1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_shp_cfg_get_rate_mode/46 (1073741824 (estimated locally),1.00 per call) 
pfe_tmu_shp_cfg_set_idle_slope/47 (pfe_tmu_shp_cfg_set_idle_slope) @07721620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_shp_cfg_get_rate_mode/46 (1073741824 (estimated locally),1.00 per call) 
pfe_tmu_shp_cfg_get_rate_mode/46 (pfe_tmu_shp_cfg_get_rate_mode) @07721a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_shp_cfg_get_idle_slope/48 (1073741824 (estimated locally),1.00 per call) pfe_tmu_shp_cfg_set_idle_slope/47 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_shp_cfg_set_rate_mode/45 (pfe_tmu_shp_cfg_set_rate_mode) @07721540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_shp_cfg_enable/44 (pfe_tmu_shp_cfg_enable) @07721000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_shp_cfg_get_position/43 (pfe_tmu_shp_cfg_get_position) @07717d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_shp_cfg_set_position/42 (pfe_tmu_shp_cfg_set_position) @077178c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/68 (225056286 (estimated locally),0.21 per call) pfe_hm_report/67 (225056286 (estimated locally),0.21 per call) 
pfe_tmu_shp_cfg_get_limits/41 (pfe_tmu_shp_cfg_get_limits) @077172a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_shp_cfg_set_limits/40 (pfe_tmu_shp_cfg_set_limits) @0770c9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/68 (177884489 (estimated locally),0.17 per call) pfe_hm_report/67 (177884489 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/68 (225056286 (estimated locally),0.21 per call) pfe_hm_report/67 (225056286 (estimated locally),0.21 per call) 
pfe_tmu_q_get_wred_zones/39 (pfe_tmu_q_get_wred_zones) @0770cb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_tmu_q_get_wred_probability/38 (pfe_tmu_q_get_wred_probability) @0770c8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_cfg_get_queue_stats/64 (1041207447 (estimated locally),4.00 per call) 
  Calls: pfe_tmu_q_get_wred_probability.part.0/73 (697932184 (estimated locally),0.65 per call) 
pfe_tmu_q_set_wred_probability/37 (pfe_tmu_q_set_wred_probability) @0770c620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_cntx_mem_write/25 (133448333 (estimated locally),0.12 per call) pfe_tmu_cntx_mem_read/26 (404388888 (estimated locally),0.38 per call) pfe_tmu_hif_q_to_tmu_q/27 (226827960 (estimated locally),0.21 per call) 
pfe_tmu_q_mode_set_wred/36 (pfe_tmu_q_mode_set_wred) @0770c380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_context_memory/28 (491736887 (estimated locally),0.46 per call) pfe_tmu_hif_q_to_tmu_q/27 (275822800 (estimated locally),0.26 per call) oal_util_raise_dem_for_drv_runtime_err/68 (522096225 (estimated locally),0.49 per call) pfe_hm_report/67 (522096225 (estimated locally),0.49 per call) 
pfe_tmu_q_mode_set_tail_drop/35 (pfe_tmu_q_mode_set_tail_drop) @0770c000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_q_reset_tail_drop_policy/18 (954353663 (estimated locally),24.98 per call) 
  Calls: pfe_tmu_q_mode_set_tail_drop.part.0/72 (697932184 (estimated locally),0.65 per call) 
pfe_tmu_q_mode_set_default/34 (pfe_tmu_q_mode_set_default) @076fcb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_reclaim_init/17 (3281698 (estimated locally),0.17 per call) 
  Calls: pfe_tmu_cntx_mem_write/25 (957133463 (estimated locally),0.89 per call) pfe_tmu_hif_q_to_tmu_q/27 (536870913 (estimated locally),0.50 per call) 
pfe_tmu_q_get_mode/33 (pfe_tmu_q_get_mode) @076fc620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_cntx_mem_read/26 (957133463 (estimated locally),0.89 per call) pfe_tmu_hif_q_to_tmu_q/27 (536870913 (estimated locally),0.50 per call) 
pfe_tmu_q_cfg_get_tx_count/32 (pfe_tmu_q_cfg_get_tx_count) @076fc0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_cfg_get_queue_stats/64 (260275024 (estimated locally),1.00 per call) 
  Calls: pfe_tmu_cntx_mem_read/26 (957133463 (estimated locally),0.89 per call) pfe_tmu_hif_q_to_tmu_q/27 (536870913 (estimated locally),0.50 per call) 
pfe_tmu_q_cfg_get_drop_count/31 (pfe_tmu_q_cfg_get_drop_count) @076fcd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_cfg_get_queue_stats/64 (260275024 (estimated locally),1.00 per call) 
  Calls: pfe_tmu_reclaim_mem_wrkarnd/30 (315854042 (estimated locally),0.29 per call) pfe_tmu_cntx_mem_read/26 (957133463 (estimated locally),0.89 per call) pfe_tmu_hif_q_to_tmu_q/27 (536870913 (estimated locally),0.50 per call) 
pfe_tmu_reclaim_mem_wrkarnd/30 (pfe_tmu_reclaim_mem_wrkarnd) @076fca80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_tmu_q_cfg_get_drop_count/31 (315854042 (estimated locally),0.29 per call) 
  Calls: pfe_feature_mgr_is_available/65 (1073741824 (estimated locally),1.00 per call) 
pfe_tmu_q_cfg_get_fill_level/29 (pfe_tmu_q_cfg_get_fill_level) @076fc7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_tmu_cfg_get_queue_stats/64 (260275024 (estimated locally),1.00 per call) 
  Calls: pfe_tmu_cntx_mem_read/26 (957133463 (estimated locally),0.89 per call) pfe_tmu_hif_q_to_tmu_q/27 (536870913 (estimated locally),0.50 per call) 
pfe_tmu_context_memory/28 (pfe_tmu_context_memory) @076fc540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_tmu_q_mode_set_wred/36 (491736887 (estimated locally),0.46 per call) pfe_tmu_reclaim_init/17 (6563396 (estimated locally),0.33 per call) 
  Calls: pfe_tmu_cntx_mem_write/25 (116930485 (estimated locally),0.11 per call) pfe_tmu_cntx_mem_write/25 (354334802 (estimated locally),0.33 per call) pfe_tmu_cntx_mem_write/25 (1073741824 (estimated locally),1.00 per call) 
pfe_tmu_hif_q_to_tmu_q/27 (pfe_tmu_hif_q_to_tmu_q) @076fc2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:210986025 (estimated locally) body local optimize_size
  Called by: pfe_tmu_q_get_wred_probability.part.0/73 (536870913 (estimated locally),0.50 per call) pfe_tmu_q_set_wred_probability/37 (226827960 (estimated locally),0.21 per call) pfe_tmu_q_mode_set_wred/36 (275822800 (estimated locally),0.26 per call) pfe_tmu_q_mode_set_tail_drop.part.0/72 (536870913 (estimated locally),0.50 per call) pfe_tmu_q_mode_set_default/34 (536870913 (estimated locally),0.50 per call) pfe_tmu_q_get_mode/33 (536870913 (estimated locally),0.50 per call) pfe_tmu_q_cfg_get_tx_count/32 (536870913 (estimated locally),0.50 per call) pfe_tmu_q_cfg_get_drop_count/31 (536870913 (estimated locally),0.50 per call) pfe_tmu_q_cfg_get_fill_level/29 (536870913 (estimated locally),0.50 per call) 
  Calls: pfe_tmu_hif_q_to_tmu_q.part.0/70 (137140916 (estimated locally),0.65 per call) 
pfe_tmu_cntx_mem_read/26 (pfe_tmu_cntx_mem_read) @076fc000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:164701623 (estimated locally) body local optimize_size
  Called by: pfe_tmu_cfg_get_queue_stats/64 (260275024 (estimated locally),1.00 per call) pfe_tmu_q_get_wred_probability.part.0/73 (957133463 (estimated locally),0.89 per call) pfe_tmu_q_set_wred_probability/37 (404388888 (estimated locally),0.38 per call) pfe_tmu_reclaim_init/17 (21951157 (estimated locally),1.10 per call) pfe_tmu_q_get_mode/33 (957133463 (estimated locally),0.89 per call) pfe_tmu_q_cfg_get_tx_count/32 (957133463 (estimated locally),0.89 per call) pfe_tmu_q_cfg_get_drop_count/31 (957133463 (estimated locally),0.89 per call) pfe_tmu_q_cfg_get_fill_level/29 (957133463 (estimated locally),0.89 per call) 
  Calls: oal_time_usleep/66 (1073741824 (estimated locally),6.52 per call) 
pfe_tmu_cntx_mem_write/25 (pfe_tmu_cntx_mem_write) @076979a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:103814371 (estimated locally) body local optimize_size
  Called by: pfe_tmu_q_set_wred_probability/37 (133448333 (estimated locally),0.12 per call) pfe_tmu_q_mode_set_tail_drop.part.0/72 (957133463 (estimated locally),0.89 per call) pfe_tmu_q_mode_set_default/34 (957133463 (estimated locally),0.89 per call) pfe_tmu_context_memory/28 (116930485 (estimated locally),0.11 per call) pfe_tmu_context_memory/28 (354334802 (estimated locally),0.33 per call) pfe_tmu_context_memory/28 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_time_usleep/66 (1073741824 (estimated locally),10.34 per call) 
pfe_tmu_cfg_disable/24 (pfe_tmu_cfg_disable) @07697460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: pfe_tmu_cfg_enable/23 (1073741824 (estimated locally),1.00 per call) 
pfe_tmu_cfg_enable/23 (pfe_tmu_cfg_enable) @07697ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: pfe_tmu_cfg_disable/24 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_cfg_reset/22 (pfe_tmu_cfg_reset) @07697c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:69202660 (estimated locally) body optimize_size
  Called by: pfe_tmu_cfg_init/21 (204054434 (estimated locally),1.00 per call) 
  Calls: pfe_tmu_cfg_reset.part.0/71 (22836878 (estimated locally),0.33 per call) oal_time_usleep/66 (1073741824 (estimated locally),15.52 per call) 
pfe_tmu_cfg_init/21 (pfe_tmu_cfg_init) @076978c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: phy_if_id_temp/15 (read)
  Referring: 
  Availability: available
  Function flags: count:204054434 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_set_default_queue_mode/19 (303700358 (estimated locally),1.49 per call) pfe_tmu_tdq_shp_on_phy5_g2/20 (186269553 (estimated locally),0.91 per call) pfe_tmu_cfg_reset/22 (204054434 (estimated locally),1.00 per call) 
pfe_tmu_tdq_shp_on_phy5_g2/20 (pfe_tmu_tdq_shp_on_phy5_g2) @07697620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: phy_if_id_temp/15 (read)
  Referring: 
  Availability: local
  Function flags: count:171787418 (estimated locally) body local optimize_size
  Called by: pfe_tmu_cfg_init/21 (186269553 (estimated locally),0.91 per call) 
  Calls: pfe_tmu_sch_cfg_bind_queue/58 (954449109 (estimated locally),5.56 per call) pfe_tmu_shp_cfg_init/50 (171787418 (estimated locally),1.00 per call) pfe_tmu_shp_cfg_init/50 (171787418 (estimated locally),1.00 per call) pfe_tmu_shp_cfg_init/50 (171787418 (estimated locally),1.00 per call) pfe_tmu_shp_cfg_init/50 (171787418 (estimated locally),1.00 per call) pfe_tmu_sch_cfg_init/51 (171787418 (estimated locally),1.00 per call) pfe_tmu_sch_cfg_init/51 (171787418 (estimated locally),1.00 per call) 
pfe_tmu_set_default_queue_mode/19 (pfe_tmu_set_default_queue_mode) @07697380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: phy_if_id_temp/15 (read)phy_if_id_temp/15 (read)
  Referring: 
  Availability: local
  Function flags: count:184884649 (estimated locally) body local optimize_size
  Called by: pfe_tmu_cfg_init/21 (303700358 (estimated locally),1.49 per call) 
  Calls: pfe_tmu_q_mode_set_tail_drop.part.0/72 (629936411 (estimated locally),3.41 per call) pfe_tmu_q_mode_set_tail_drop.part.0/72 (324512696 (estimated locally),1.76 per call) pfe_tmu_sch_cfg_set_rate_mode/52 (37420653 (estimated locally),0.20 per call) 
pfe_tmu_q_reset_tail_drop_policy/18 (pfe_tmu_q_reset_tail_drop_policy) @076970e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/69 (read)phy_if_id_temp/15 (read)
  Referring: 
  Availability: available
  Function flags: count:38199761 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/68 (52489451 (estimated locally),1.37 per call) pfe_hm_report/67 (52489451 (estimated locally),1.37 per call) pfe_tmu_q_mode_set_tail_drop/35 (954353663 (estimated locally),24.98 per call) 
pfe_tmu_reclaim_init/17 (pfe_tmu_reclaim_init) @076749a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:19889078 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_tmu_q_mode_set_default/34 (3281698 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/68 (1604094 (estimated locally),0.08 per call) pfe_hm_report/67 (1604094 (estimated locally),0.08 per call) pfe_tmu_cntx_mem_read/26 (21951157 (estimated locally),1.10 per call) oal_time_usleep/66 (21951157 (estimated locally),1.10 per call) pfe_tmu_context_memory/28 (6563396 (estimated locally),0.33 per call) pfe_feature_mgr_is_available/65 (19889078 (estimated locally),1.00 per call) 
pfe_tmu_cfg_get_phy_config/16 (pfe_tmu_cfg_get_phy_config) @07674b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tmu_phys/14 (addr)tmu_phys/14 (read)
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: 
phy_if_id_temp/15 (phy_if_id_temp) @07785bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_tmu_tdq_shp_on_phy5_g2/20 (read)pfe_tmu_set_default_queue_mode/19 (read)pfe_tmu_set_default_queue_mode/19 (read)pfe_tmu_cfg_init/21 (read)pfe_tmu_q_reset_tail_drop_policy/18 (read)pfe_tmu_cfg_get_queue_stats/64 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
tmu_phys/14 (tmu_phys) @07785c18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_tmu_cfg_get_phy_config/16 (addr)pfe_tmu_cfg_get_phy_config/16 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function pfe_tmu_cntx_mem_write (pfe_tmu_cntx_mem_write, funcdef_no=21, decl_uid=10531, cgraph_uid=22, symbol_order=25)

Modification phase of node pfe_tmu_cntx_mem_write/25
pfe_tmu_cntx_mem_write (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t loc, uint32_t data)
{
  errno_t ret;
  pfe_ct_phy_if_id_t phy_temp;
  uint32_t timeout;
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;
  long unsigned int _9;
  unsigned int _10;
  volatile uint32_t * _11;
  unsigned int _12;
  volatile uint32_t * _13;
  long unsigned int _14;

  <bb 2> [local count: 103814371]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 200
  # DEBUG BEGIN_STMT
  # DEBUG phy_temp => phy_19(D)
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = cbus_base_va_20(D) + 524596;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  switch (phy_19(D)) <default: <L25> [33.33%], case 0 ... 2: <L24> [33.33%], case 3: <L22> [33.33%], case 4 ... 5: <L24> [33.33%], case 6 ... 9: <L22> [33.33%]>

  <bb 3> [local count: 34601330]:
<L22>:
  # DEBUG BEGIN_STMT
  # DEBUG phy_temp => 3
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG phy_temp => 3
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 69202660]:
  # phy_temp_32 = PHI <3(3), phy_19(D)(2)>
<L24>:
  # DEBUG ret => NULL
  # DEBUG phy_temp => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = (long unsigned int) phy_temp_32;
  _4 = _3 << 16;
  _5 = _4 & 2031616;
  _6 = (long unsigned int) loc_24(D);
  _7 = cbus_base_va_20(D) + 524600;
  _8 = (volatile uint32_t *) _7;
  _9 = _5 | _6;
  *_8 ={v} _9;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = cbus_base_va_20(D) + 524604;
  _11 = (volatile uint32_t *) _10;
  *_11 ={v} data_26(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = cbus_base_va_20(D) + 524608;
  _13 = (volatile uint32_t *) _12;
  *_13 ={v} 3;

  <bb 5> [local count: 1073741824]:
  # timeout_15 = PHI <200(4), timeout_30(10)>
  # DEBUG timeout => timeout_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oal_time_usleep (1);
  # DEBUG BEGIN_STMT
  timeout_30 = timeout_15 + 4294967295;
  # DEBUG timeout => timeout_30
  # DEBUG BEGIN_STMT
  reg_31 ={v} *_13;
  # DEBUG reg => reg_31
  # DEBUG BEGIN_STMT
  _14 = reg_31 & 4;
  if (_14 == 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686023]:
  if (timeout_30 != 0)
    goto <bb 10>; [99.00%]
  else
    goto <bb 7>; [1.00%]

  <bb 10> [local count: 1004539164]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 69202661]:
  # timeout_23 = PHI <timeout_30(5), timeout_30(6)>
  # DEBUG BEGIN_STMT
  if (timeout_23 == 0)
    goto <bb 8>; [35.00%]
  else
    goto <bb 9>; [65.00%]

  <bb 8> [local count: 24220931]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 110

  <bb 9> [local count: 103803991]:
  # ret_16 = PHI <22(2), 0(7), 110(8)>
<L25>:
  # DEBUG phy_temp => NULL
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  return ret_16;

}



;; Function pfe_tmu_context_memory (pfe_tmu_context_memory, funcdef_no=24, decl_uid=10542, cgraph_uid=25, symbol_order=28)

Modification phase of node pfe_tmu_context_memory/28
pfe_tmu_context_memory (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue_temp, uint16_t min, uint16_t max)
{
  errno_t ret;
  uint32_t reg;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  unsigned char _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG reg => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = queue_temp_12(D) * 8;
  _2 = _1 + 5;
  ret_17 = pfe_tmu_cntx_mem_write (cbus_base_va_14(D), phy_15(D), _2, 0);
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  if (ret_17 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _3 = _1 + 6;
  ret_19 = pfe_tmu_cntx_mem_write (cbus_base_va_14(D), phy_15(D), _3, 0);
  # DEBUG ret => ret_19
  # DEBUG BEGIN_STMT
  if (ret_19 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 116930485]:
  # DEBUG BEGIN_STMT
  _4 = (long unsigned int) max_20(D);
  _5 = _4 << 11;
  _6 = (long unsigned int) min_21(D);
  _7 = _6 << 2;
  _8 = _5 | _7;
  reg_22 = _8 | 2;
  # DEBUG reg => reg_22
  # DEBUG BEGIN_STMT
  _9 = _1 + 4;
  ret_24 = pfe_tmu_cntx_mem_write (cbus_base_va_14(D), phy_15(D), _9, reg_22);
  # DEBUG ret => ret_24

  <bb 5> [local count: 1073741824]:
  # ret_10 = PHI <ret_17(2), ret_19(3), ret_24(4)>
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  return ret_10;

}



;; Function pfe_tmu_cntx_mem_read (pfe_tmu_cntx_mem_read, funcdef_no=22, decl_uid=10536, cgraph_uid=23, symbol_order=26)

Modification phase of node pfe_tmu_cntx_mem_read/26
pfe_tmu_cntx_mem_read (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t loc, uint32_t * data)
{
  errno_t ret;
  pfe_ct_phy_if_id_t phy_temp;
  uint32_t timeout;
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;
  long unsigned int _9;
  unsigned int _10;
  volatile uint32_t * _11;
  long unsigned int _12;
  unsigned int _13;
  volatile uint32_t * _14;
  long unsigned int _15;

  <bb 2> [local count: 164701623]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 20
  # DEBUG BEGIN_STMT
  # DEBUG phy_temp => phy_20(D)
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = cbus_base_va_21(D) + 524596;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  switch (phy_20(D)) <default: <L26> [33.33%], case 0 ... 2: <L25> [33.33%], case 3: <L23> [33.33%], case 4 ... 5: <L25> [33.33%], case 6 ... 9: <L23> [33.33%]>

  <bb 3> [local count: 54895051]:
<L23>:
  # DEBUG BEGIN_STMT
  # DEBUG phy_temp => 3
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG phy_temp => 3
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 109790102]:
  # phy_temp_33 = PHI <3(3), phy_20(D)(2)>
<L25>:
  # DEBUG ret => NULL
  # DEBUG phy_temp => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = (long unsigned int) phy_temp_33;
  _4 = _3 << 16;
  _5 = _4 & 2031616;
  _6 = (long unsigned int) loc_25(D);
  _7 = cbus_base_va_21(D) + 524600;
  _8 = (volatile uint32_t *) _7;
  _9 = _5 | _6;
  *_8 ={v} _9;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = cbus_base_va_21(D) + 524608;
  _11 = (volatile uint32_t *) _10;
  *_11 ={v} 2;

  <bb 5> [local count: 1073741824]:
  # timeout_16 = PHI <20(4), timeout_29(10)>
  # DEBUG timeout => timeout_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oal_time_usleep (10);
  # DEBUG BEGIN_STMT
  timeout_29 = timeout_16 + 4294967295;
  # DEBUG timeout => timeout_29
  # DEBUG BEGIN_STMT
  reg_30 ={v} *_11;
  # DEBUG reg => reg_30
  # DEBUG BEGIN_STMT
  _12 = reg_30 & 4;
  if (_12 == 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686025]:
  if (timeout_29 != 0)
    goto <bb 10>; [95.00%]
  else
    goto <bb 7>; [5.00%]

  <bb 10> [local count: 963951723]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 109790102]:
  # timeout_24 = PHI <timeout_29(5), timeout_29(6)>
  # DEBUG BEGIN_STMT
  if (timeout_24 == 0)
    goto <bb 9>; [35.00%]
  else
    goto <bb 8>; [65.00%]

  <bb 8> [local count: 71363566]:
  # DEBUG BEGIN_STMT
  _13 = cbus_base_va_21(D) + 524604;
  _14 = (volatile uint32_t *) _13;
  _15 ={v} *_14;
  *data_31(D) = _15;

  <bb 9> [local count: 164685153]:
  # ret_17 = PHI <22(2), 110(7), 0(8)>
<L26>:
  # DEBUG phy_temp => NULL
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  return ret_17;

}



;; Function pfe_tmu_hif_q_to_tmu_q (pfe_tmu_hif_q_to_tmu_q, funcdef_no=23, decl_uid=10546, cgraph_uid=24, symbol_order=27)

Modification phase of node pfe_tmu_hif_q_to_tmu_q/27
pfe_tmu_hif_q_to_tmu_q (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue)
{
  uint8_t tmu_queue;
  unsigned char _1;

  <bb 2> [local count: 210986025]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG hif_queue => -1
  # DEBUG BEGIN_STMT
  # DEBUG tmu_queue => 255
  # DEBUG BEGIN_STMT
  _1 = phy_6(D) + 250;
  if (_1 <= 3)
    goto <bb 3>; [65.00%]
  else
    goto <bb 4>; [35.00%]

  <bb 3> [local count: 137140916]:
  tmu_queue_2 = pfe_tmu_hif_q_to_tmu_q.part.0 (cbus_base_va_7(D), phy_6(D), queue_9(D));

  <bb 4> [local count: 210986024]:
  # tmu_queue_3 = PHI <255(2), tmu_queue_2(3)>
  # DEBUG tmu_queue => tmu_queue_3
  # DEBUG BEGIN_STMT
  return tmu_queue_3;

}



;; Function pfe_tmu_q_mode_set_tail_drop.part.0 (pfe_tmu_q_mode_set_tail_drop.part.0, funcdef_no=63, decl_uid=11468, cgraph_uid=68, symbol_order=72)

Modification phase of node pfe_tmu_q_mode_set_tail_drop.part.0/72
pfe_tmu_q_mode_set_tail_drop.part.0 (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint16_t max)
{
  uint32_t reg;
  uint8_t queue_temp;
  errno_t ret;
  unsigned char _2;
  long unsigned int _7;
  long unsigned int _8;
  unsigned char _11;
  unsigned char _12;

  <bb 6> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = phy_1(D) + 250;
  if (_2 <= 3)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  queue_temp_5 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_3(D), phy_1(D), queue_4(D));
  # DEBUG queue_temp => queue_temp_5
  # DEBUG BEGIN_STMT
  if (queue_temp_5 == 255)
    goto <bb 5>; [21.72%]
  else
    goto <bb 4>; [78.28%]

  <bb 4> [local count: 957133463]:
  # queue_temp_10 = PHI <queue_4(D)(2), queue_temp_5(3)>
  # DEBUG ret => NULL
  # DEBUG queue_temp => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = (long unsigned int) max_6(D);
  _8 = _7 << 11;
  reg_9 = _8 | 1;
  # DEBUG reg => reg_9
  # DEBUG BEGIN_STMT
  _11 = queue_temp_10 * 8;
  _12 = _11 + 4;
  ret_13 = pfe_tmu_cntx_mem_write (cbus_base_va_3(D), phy_1(D), _12, reg_9);
  # DEBUG ret => ret_13

  <bb 5> [local count: 1073741824]:
  # ret_14 = PHI <22(3), ret_13(4)>
  # DEBUG queue_temp => NULL
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  return ret_14;

}



;; Function pfe_tmu_cfg_get_phy_config (pfe_tmu_cfg_get_phy_config, funcdef_no=12, decl_uid=9449, cgraph_uid=13, symbol_order=16)

Modification phase of node pfe_tmu_cfg_get_phy_config/16
pfe_tmu_cfg_get_phy_config (pfe_ct_phy_if_id_t phy)
{
  const struct pfe_tmu_phy_cfg_t * phy_config;
  uint32_t ii;
  <unnamed type> _2;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG phy_config => 0B
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  if (_2 == phy_6(D))
    goto <bb 4>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 4> [local count: 55807731]:
  # ii_1 = PHI <ii_3(3)>
  # DEBUG BEGIN_STMT
  phy_config_8 = &tmu_phys[ii_1];
  # DEBUG phy_config => phy_config_8
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  ii_7 = ii_3 + 1;
  # DEBUG ii => ii_7

  <bb 6> [local count: 1073741824]:
  # ii_3 = PHI <0(2), ii_7(5)>
  # DEBUG ii => ii_3
  # DEBUG BEGIN_STMT
  _2 = tmu_phys[ii_3].id;
  if (_2 != 10)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 114863532]:
  # phy_config_4 = PHI <phy_config_8(4), 0B(6)>
  # DEBUG phy_config => phy_config_4
  # DEBUG BEGIN_STMT
  return phy_config_4;

}



;; Function pfe_tmu_cfg_reset (pfe_tmu_cfg_reset, funcdef_no=18, decl_uid=9616, cgraph_uid=19, symbol_order=22)

Modification phase of node pfe_tmu_cfg_reset/22
pfe_tmu_cfg_reset (addr_t cbus_base_va)
{
  uint32_t reg;
  uint32_t timeout;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _5;

  <bb 2> [local count: 69202660]:
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 200
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = cbus_base_va_9(D) + 524344;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 1;

  <bb 3> [local count: 1073741824]:
  # timeout_6 = PHI <200(2), timeout_13(8)>
  # DEBUG timeout => timeout_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oal_time_usleep (10);
  # DEBUG BEGIN_STMT
  timeout_13 = timeout_6 + 4294967295;
  # DEBUG timeout => timeout_13
  # DEBUG BEGIN_STMT
  reg_14 ={v} *_2;
  # DEBUG reg => reg_14
  # DEBUG BEGIN_STMT
  _5 = reg_14 & 1;
  if (_5 != 0)
    goto <bb 4>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 4> [local count: 1014686024]:
  if (timeout_13 != 0)
    goto <bb 8>; [99.00%]
  else
    goto <bb 5>; [1.00%]

  <bb 8> [local count: 1004539166]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 69202661]:
  # timeout_3 = PHI <timeout_13(3), timeout_13(4)>
  # DEBUG BEGIN_STMT
  if (timeout_3 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 22836878]:
  # DEBUG D#1 => cbus_base_va_9(D)
  pfe_tmu_cfg_reset.part.0 ();

  <bb 7> [local count: 69202661]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_tmu_cfg_enable (pfe_tmu_cfg_enable, funcdef_no=19, decl_uid=9618, cgraph_uid=20, symbol_order=23)

Modification phase of node pfe_tmu_cfg_enable/23
pfe_tmu_cfg_enable (addr_t cbus_base_va)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_tmu_cfg_disable (pfe_tmu_cfg_disable, funcdef_no=68, decl_uid=9620, cgraph_uid=21, symbol_order=24)

Modification phase of node pfe_tmu_cfg_disable/24
pfe_tmu_cfg_disable (addr_t cbus_base_va)
{
  <bb 2> [local count: 1073741824]:
  pfe_tmu_cfg_enable (cbus_base_va_1(D)); [tail call]
  return;

}



;; Function pfe_tmu_q_cfg_get_fill_level (pfe_tmu_q_cfg_get_fill_level, funcdef_no=25, decl_uid=9454, cgraph_uid=26, symbol_order=29)

Modification phase of node pfe_tmu_q_cfg_get_fill_level/29
pfe_tmu_q_cfg_get_fill_level (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint32_t * level)
{
  errno_t ret;
  uint8_t queue_temp;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG queue_temp => queue_6(D)
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = phy_7(D) + 250;
  if (_1 <= 3)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  queue_temp_11 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_9(D), phy_7(D), queue_6(D));
  # DEBUG queue_temp => queue_temp_11
  # DEBUG BEGIN_STMT
  if (queue_temp_11 == 255)
    goto <bb 8>; [21.72%]
  else
    goto <bb 7>; [78.28%]

  <bb 7> [local count: 957133463]:
  # queue_temp_15 = PHI <queue_temp_11(4), queue_6(D)(2)>
  # DEBUG ret => NULL
  # DEBUG queue_temp => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = queue_temp_15 * 8;
  _3 = _2 + 1;
  ret_14 = pfe_tmu_cntx_mem_read (cbus_base_va_9(D), phy_7(D), _3, level_12(D));
  # DEBUG ret => ret_14

  <bb 8> [local count: 1073741824]:
  # ret_4 = PHI <22(4), ret_14(7)>
  # DEBUG queue_temp => NULL
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_tmu_q_cfg_get_drop_count (pfe_tmu_q_cfg_get_drop_count, funcdef_no=27, decl_uid=9459, cgraph_uid=28, symbol_order=31)

Modification phase of node pfe_tmu_q_cfg_get_drop_count/31
pfe_tmu_q_cfg_get_drop_count (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint32_t * cnt)
{
  uint8_t temp;
  errno_t ret;
  uint32_t drops;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  long unsigned int drops.12_4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG temp => queue_8(D)
  # DEBUG BEGIN_STMT
  _1 = phy_9(D) + 250;
  if (_1 <= 3)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  temp_13 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_11(D), phy_9(D), queue_8(D));
  # DEBUG temp => temp_13
  # DEBUG BEGIN_STMT
  if (temp_13 == 255)
    goto <bb 9>; [21.72%]
  else
    goto <bb 7>; [78.28%]

  <bb 7> [local count: 957133463]:
  # temp_20 = PHI <temp_13(4), queue_8(D)(2)>
  # DEBUG temp => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = temp_20 * 8;
  _3 = _2 + 2;
  ret_15 = pfe_tmu_cntx_mem_read (cbus_base_va_11(D), phy_9(D), _3, &drops);
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  if (ret_15 == 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 315854042]:
  # DEBUG BEGIN_STMT
  drops.12_4 = drops;
  _5 = pfe_tmu_reclaim_mem_wrkarnd (drops.12_4, queue_8(D), phy_9(D));
  *cnt_17(D) = _5;

  <bb 9> [local count: 1073741824]:
  # ret_6 = PHI <22(4), ret_15(7), 0(8)>
  # DEBUG temp => NULL
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  drops ={v} {CLOBBER};
  return ret_6;

}



;; Function pfe_tmu_q_cfg_get_tx_count (pfe_tmu_q_cfg_get_tx_count, funcdef_no=28, decl_uid=9464, cgraph_uid=29, symbol_order=32)

Modification phase of node pfe_tmu_q_cfg_get_tx_count/32
pfe_tmu_q_cfg_get_tx_count (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint32_t * cnt)
{
  errno_t ret;
  uint8_t temp;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG temp => queue_6(D)
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = phy_7(D) + 250;
  if (_1 <= 3)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  temp_11 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_9(D), phy_7(D), queue_6(D));
  # DEBUG temp => temp_11
  # DEBUG BEGIN_STMT
  if (temp_11 == 255)
    goto <bb 8>; [21.72%]
  else
    goto <bb 7>; [78.28%]

  <bb 7> [local count: 957133463]:
  # temp_15 = PHI <temp_11(4), queue_6(D)(2)>
  # DEBUG ret => NULL
  # DEBUG temp => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = temp_15 * 8;
  _3 = _2 + 3;
  ret_14 = pfe_tmu_cntx_mem_read (cbus_base_va_9(D), phy_7(D), _3, cnt_12(D));
  # DEBUG ret => ret_14

  <bb 8> [local count: 1073741824]:
  # ret_4 = PHI <22(4), ret_14(7)>
  # DEBUG temp => NULL
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_tmu_q_get_mode (pfe_tmu_q_get_mode, funcdef_no=29, decl_uid=9470, cgraph_uid=30, symbol_order=33)

Modification phase of node pfe_tmu_q_get_mode/33
pfe_tmu_q_get_mode (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint32_t * min, uint32_t * max)
{
  uint8_t temp;
  pfe_tmu_queue_mode_t mode;
  errno_t ret;
  uint32_t reg;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  long unsigned int reg.13_4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mode => 2
  # DEBUG BEGIN_STMT
  # DEBUG temp => queue_14(D)
  # DEBUG BEGIN_STMT
  _1 = phy_15(D) + 250;
  if (_1 <= 3)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  temp_19 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_17(D), phy_15(D), queue_14(D));
  # DEBUG temp => temp_19
  # DEBUG BEGIN_STMT
  if (temp_19 == 255)
    goto <bb 12>; [21.72%]
  else
    goto <bb 7>; [78.28%]

  <bb 7> [local count: 957133463]:
  # temp_31 = PHI <temp_19(4), queue_14(D)(2)>
  # DEBUG temp => NULL
  # DEBUG mode => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = temp_31 * 8;
  _3 = _2 + 4;
  ret_21 = pfe_tmu_cntx_mem_read (cbus_base_va_17(D), phy_15(D), _3, &reg);
  # DEBUG ret => ret_21
  # DEBUG BEGIN_STMT
  if (ret_21 != 0)
    goto <bb 12>; [35.00%]
  else
    goto <bb 8>; [65.00%]

  <bb 8> [local count: 622136751]:
  # DEBUG BEGIN_STMT
  reg.13_4 = reg;
  _5 = reg.13_4 & 3;
  switch (_5) <default: <L9> [33.33%], case 1: <L7> [33.33%], case 2: <L8> [33.33%]>

  <bb 9> [local count: 207358179]:
<L7>:
  # DEBUG BEGIN_STMT
  # DEBUG mode => 0
  # DEBUG BEGIN_STMT
  _6 = reg.13_4 >> 11;
  _7 = _6 & 511;
  *max_22(D) = _7;
  # DEBUG BEGIN_STMT
  *min_24(D) = 0;
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 10> [local count: 207358179]:
<L8>:
  # DEBUG BEGIN_STMT
  # DEBUG mode => 1
  # DEBUG BEGIN_STMT
  _8 = reg.13_4 >> 11;
  _9 = _8 & 511;
  *max_22(D) = _9;
  # DEBUG BEGIN_STMT
  _10 = reg.13_4 >> 2;
  _11 = _10 & 511;
  *min_24(D) = _11;
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 207358179]:
<L9>:
  # DEBUG BEGIN_STMT
  # DEBUG mode => 2
  # DEBUG BEGIN_STMT
  *max_22(D) = 0;
  # DEBUG BEGIN_STMT
  *min_24(D) = 0;
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073679612]:
  # mode_12 = PHI <3(4), 3(7), 0(9), 1(10), 2(11)>
  # DEBUG temp => NULL
  # DEBUG mode => mode_12
  # DEBUG BEGIN_STMT
  reg ={v} {CLOBBER};
  return mode_12;

}



;; Function pfe_tmu_q_mode_set_default (pfe_tmu_q_mode_set_default, funcdef_no=30, decl_uid=9474, cgraph_uid=31, symbol_order=34)

Modification phase of node pfe_tmu_q_mode_set_default/34
pfe_tmu_q_mode_set_default (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue)
{
  errno_t ret;
  uint8_t temp;
  unsigned char _1;
  unsigned int _2;
  volatile uint32_t * _3;
  unsigned char _4;
  unsigned char _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG temp => queue_8(D)
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = phy_9(D) + 250;
  if (_1 <= 3)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  temp_13 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_11(D), phy_9(D), queue_8(D));
  # DEBUG temp => temp_13
  # DEBUG BEGIN_STMT
  if (temp_13 == 255)
    goto <bb 8>; [21.72%]
  else
    goto <bb 7>; [78.28%]

  <bb 7> [local count: 957133463]:
  # temp_17 = PHI <temp_13(4), queue_8(D)(2)>
  # DEBUG ret => NULL
  # DEBUG temp => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = cbus_base_va_11(D) + 524364;
  _3 = (volatile uint32_t *) _2;
  *_3 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = temp_17 * 8;
  _5 = _4 + 4;
  ret_16 = pfe_tmu_cntx_mem_write (cbus_base_va_11(D), phy_9(D), _5, 0);
  # DEBUG ret => ret_16

  <bb 8> [local count: 1073741824]:
  # ret_6 = PHI <22(4), ret_16(7)>
  # DEBUG temp => NULL
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_tmu_reclaim_init (pfe_tmu_reclaim_init, funcdef_no=13, decl_uid=9614, cgraph_uid=14, symbol_order=17)

Modification phase of node pfe_tmu_reclaim_init/17
pfe_tmu_reclaim_init (addr_t cbus_base_va)
{
  uint32_t retries;
  uint32_t dropped_packets;
  uint32_t ii;
  uint8_t queue;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  unsigned int _6;
  volatile uint32_t * _7;
  long unsigned int _8;
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
  unsigned int _21;
  volatile uint32_t * _22;
  unsigned int _23;
  volatile uint32_t * _24;
  unsigned char _25;
  int _26;
  unsigned int _27;
  volatile uint32_t * _28;
  long unsigned int dropped_packets.1_29;
  long unsigned int dropped_packets.1_30;
  unsigned char _43;

  <bb 2> [local count: 19889078]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dropped_packets = 0;
  # DEBUG BEGIN_STMT
  # DEBUG retries => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = cbus_base_va_44(D) + 524596;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 954449108]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = ii_32 << 8;
  _4 = _3;
  _43 = queue_31;
  _5 = (long unsigned int) _43;
  _6 = cbus_base_va_44(D) + 524308;
  _7 = (volatile uint32_t *) _6;
  _8 = _4 | _5;
  *_7 ={v} _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("nop" :  :  : "memory");
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = cbus_base_va_44(D) + 524312;
  _10 = (volatile uint32_t *) _9;
  *_10 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = cbus_base_va_44(D) + 524316;
  _12 = (volatile uint32_t *) _11;
  *_12 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = cbus_base_va_44(D) + 524320;
  _14 = (volatile uint32_t *) _13;
  *_14 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = cbus_base_va_44(D) + 524324;
  _16 = (volatile uint32_t *) _15;
  *_16 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _17 = cbus_base_va_44(D) + 524328;
  _18 = (volatile uint32_t *) _17;
  *_18 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = cbus_base_va_44(D) + 524332;
  _20 = (volatile uint32_t *) _19;
  *_20 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _21 = cbus_base_va_44(D) + 524336;
  _22 = (volatile uint32_t *) _21;
  *_22 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = cbus_base_va_44(D) + 524340;
  _24 = (volatile uint32_t *) _23;
  *_24 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  queue_68 = queue_31 + 1;
  # DEBUG queue => queue_68

  <bb 4> [local count: 1073741824]:
  # queue_31 = PHI <queue_68(3), 0(19)>
  # DEBUG queue => queue_31
  # DEBUG BEGIN_STMT
  if (queue_31 != 8)
    goto <bb 3>; [88.89%]
  else
    goto <bb 5>; [11.11%]

  <bb 5> [local count: 119292717]:
  # DEBUG BEGIN_STMT
  ii_57 = ii_32 + 1;
  # DEBUG ii => ii_57

  <bb 6> [local count: 139181795]:
  # ii_32 = PHI <0(2), ii_57(5)>
  # DEBUG ii => ii_32
  # DEBUG BEGIN_STMT
  if (ii_32 != 6)
    goto <bb 19>; [85.71%]
  else
    goto <bb 7>; [14.29%]

  <bb 19> [local count: 119292716]:
  goto <bb 4>; [100.00%]

  <bb 7> [local count: 19889078]:
  # DEBUG BEGIN_STMT
  _25 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  if (_25 == 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 8> [local count: 6563396]:
  # DEBUG BEGIN_STMT
  _26 = pfe_tmu_context_memory (cbus_base_va_44(D), 0, 0, 0, 0);
  if (_26 == 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 18> [local count: 3281698]:
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 324888103]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _27 = cbus_base_va_44(D) + 524300;
  _28 = (volatile uint32_t *) _27;
  *_28 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ii_55 = ii_33 + 1;
  # DEBUG ii => ii_55

  <bb 10> [local count: 328169801]:
  # ii_33 = PHI <ii_55(9), 0(18)>
  # DEBUG ii => ii_33
  # DEBUG BEGIN_STMT
  if (ii_33 != 256)
    goto <bb 9>; [99.00%]
  else
    goto <bb 17>; [1.00%]

  <bb 17> [local count: 3281698]:

  <bb 11> [local count: 21951157]:
  # retries_34 = PHI <0(17), retries_50(20)>
  # DEBUG retries => retries_34
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oal_time_usleep (10);
  # DEBUG BEGIN_STMT
  pfe_tmu_cntx_mem_read (cbus_base_va_44(D), 0, 2, &dropped_packets);
  # DEBUG BEGIN_STMT
  retries_50 = retries_34 + 1;
  # DEBUG retries => retries_50
  # DEBUG BEGIN_STMT
  dropped_packets.1_29 = dropped_packets;
  if (dropped_packets.1_29 != 256)
    goto <bb 12>; [94.50%]
  else
    goto <bb 13>; [5.50%]

  <bb 12> [local count: 20743844]:
  if (retries_50 != 10)
    goto <bb 20>; [90.00%]
  else
    goto <bb 13>; [10.00%]

  <bb 20> [local count: 18669459]:
  goto <bb 11>; [100.00%]

  <bb 13> [local count: 3281698]:
  # dropped_packets.1_30 = PHI <dropped_packets.1_29(11), dropped_packets.1_29(12)>
  # DEBUG BEGIN_STMT
  if (dropped_packets.1_30 != 256)
    goto <bb 14>; [48.88%]
  else
    goto <bb 15>; [51.12%]

  <bb 14> [local count: 1604094]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Failed to initialize TMU reclaim memory %u\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 196, dropped_packets.1_30, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 15> [local count: 3281698]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_tmu_q_mode_set_default (cbus_base_va_44(D), 0, 0);

  <bb 16> [local count: 19889078]:
  dropped_packets ={v} {CLOBBER};
  return;

}



;; Function pfe_tmu_q_mode_set_tail_drop (pfe_tmu_q_mode_set_tail_drop, funcdef_no=31, decl_uid=9479, cgraph_uid=32, symbol_order=35)

Modification phase of node pfe_tmu_q_mode_set_tail_drop/35
pfe_tmu_q_mode_set_tail_drop (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint16_t max)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG queue_temp => queue_2(D)
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (max_3(D) > 255)
    goto <bb 4>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932184]:
  ret_7 = pfe_tmu_q_mode_set_tail_drop.part.0 (cbus_base_va_6(D), phy_4(D), queue_2(D), max_3(D));

  <bb 4> [local count: 1073741824]:
  # ret_1 = PHI <22(2), ret_7(3)>
  # DEBUG queue_temp => NULL
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_tmu_q_reset_tail_drop_policy (pfe_tmu_q_reset_tail_drop_policy, funcdef_no=14, decl_uid=9503, cgraph_uid=15, symbol_order=18)

Modification phase of node pfe_tmu_q_reset_tail_drop_policy/18
pfe_tmu_q_reset_tail_drop_policy (addr_t cbus_base_va)
{
  uint16_t max;
  uint8_t queue;
  errno_t ret;
  uint32_t ii;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.4_1;
  const struct Eth_43_PFE_EmacCfg * _2;
  unsigned int _4;
  const struct Eth_43_PFE_EmacCfg * _5;
  int _6;
  unsigned char _7;
  int _8;
  <unnamed type> _9;
  int _10;
  long unsigned int _23;
  long unsigned int _26;

  <bb 2> [local count: 38199761]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 12>; [100.00%]

  <bb 3> [local count: 954449108]:
  # DEBUG BEGIN_STMT
  switch (ii_12) <default: <L6> [33.33%], case 0 ... 2: <L2> [33.33%], case 3: <L16> [33.33%]>

  <bb 4> [local count: 318117888]:
<L2>:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.4_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = Eth_43_PFE_InternalCfgPtr.4_1->emac;
  _23 = ii_12;
  _4 = _23 * 20;
  _5 = _2 + _4;
  _6 = (int) queue_17;
  _7 = _5->EthTmuQueueSizes[_6];
  max_27 = (uint16_t) _7;
  # DEBUG max => max_27
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 318117888]:
<L6>:
  # DEBUG BEGIN_STMT
  # DEBUG max => 31
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 954353663]:
  # max_18 = PHI <max_27(4), 16(3), 31(5)>
<L16>:
  # DEBUG max => max_18
  # DEBUG BEGIN_STMT
  _26 = ii_12;
  _8 = (int) _26;
  _9 = phy_if_id_temp[_8];
  ret_30 = pfe_tmu_q_mode_set_tail_drop (cbus_base_va_28(D), _9, queue_17, max_18);
  # DEBUG ret => ret_30
  # DEBUG BEGIN_STMT
  if (ret_30 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 7> [local count: 52489451]:
  # queue_3 = PHI <queue_17(6)>
  # ret_11 = PHI <ret_30(6)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = (int) queue_3;
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t set the default queue size for PHY#%u queue %hhu: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 243, ii_12, _10, ret_11, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 901864212]:
  # DEBUG BEGIN_STMT
  queue_31 = queue_17 + 1;
  # DEBUG queue => queue_31

  <bb 9> [local count: 1073741824]:
  # ret_13 = PHI <0(8), ret_15(14)>
  # queue_17 = PHI <queue_31(8), 0(14)>
  # DEBUG queue => queue_17
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  if (queue_17 != 8)
    goto <bb 3>; [88.89%]
  else
    goto <bb 10>; [11.11%]

  <bb 10> [local count: 171782168]:
  # ret_14 = PHI <ret_11(7), ret_13(9)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  if (ret_14 != 0)
    goto <bb 13>; [5.50%]
  else
    goto <bb 11>; [94.50%]

  <bb 11> [local count: 162334149]:
  # DEBUG BEGIN_STMT
  ii_34 = ii_12 + 1;
  # DEBUG ii => ii_34

  <bb 12> [local count: 200533910]:
  # ii_12 = PHI <0(2), ii_34(11)>
  # ret_15 = PHI <ret_24(D)(2), 0(11)>
  # DEBUG ret => ret_15
  # DEBUG ii => ii_12
  # DEBUG BEGIN_STMT
  if (ii_12 != 6)
    goto <bb 14>; [85.71%]
  else
    goto <bb 13>; [14.29%]

  <bb 14> [local count: 171877614]:
  goto <bb 9>; [100.00%]

  <bb 13> [local count: 38104315]:
  # ret_16 = PHI <ret_14(10), ret_15(12)>
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  return ret_16;

}



;; Function pfe_tmu_q_mode_set_wred (pfe_tmu_q_mode_set_wred, funcdef_no=32, decl_uid=9485, cgraph_uid=33, symbol_order=36)

Modification phase of node pfe_tmu_q_mode_set_wred/36
pfe_tmu_q_mode_set_wred (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint16_t min, uint16_t max)
{
  uint8_t queue_temp;
  errno_t ret;
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG queue_temp => queue_4(D)
  # DEBUG BEGIN_STMT
  if (max_5(D) > 511)
    goto <bb 4>; [20.96%]
  else
    goto <bb 3>; [79.04%]

  <bb 3> [local count: 848685538]:
  if (min_6(D) > 511)
    goto <bb 4>; [35.00%]
  else
    goto <bb 5>; [65.00%]

  <bb 4> [local count: 522096225]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Queue WRED \'min and/or \'max\' argument out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 981, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 11>; [100.00%]

  <bb 5> [local count: 551645600]:
  # DEBUG BEGIN_STMT
  _1 = phy_7(D) + 250;
  if (_1 <= 3)
    goto <bb 7>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 7> [local count: 275822800]:
  # DEBUG BEGIN_STMT
  queue_temp_11 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_9(D), phy_7(D), queue_4(D));
  # DEBUG queue_temp => queue_temp_11
  # DEBUG BEGIN_STMT
  if (queue_temp_11 == 255)
    goto <bb 11>; [21.72%]
  else
    goto <bb 10>; [78.28%]

  <bb 10> [local count: 491736887]:
  # queue_temp_16 = PHI <queue_temp_11(7), queue_4(D)(5)>
  # DEBUG queue_temp => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  ret_13 = pfe_tmu_context_memory (cbus_base_va_9(D), phy_7(D), queue_temp_16, min_6(D), max_5(D));
  # DEBUG ret => ret_13

  <bb 11> [local count: 1073741824]:
  # ret_2 = PHI <22(4), 22(7), ret_13(10)>
  # DEBUG queue_temp => NULL
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_tmu_q_set_wred_probability (pfe_tmu_q_set_wred_probability, funcdef_no=33, decl_uid=9491, cgraph_uid=34, symbol_order=37)

Modification phase of node pfe_tmu_q_set_wred_probability/37
pfe_tmu_q_set_wred_probability (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint8_t zone, uint8_t prob)
{
  uint8_t queue_temp;
  uint8_t pos;
  uint32_t reg;
  errno_t ret;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;
  unsigned int _6;
  unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int reg.17_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG queue_temp => queue_20(D)
  # DEBUG BEGIN_STMT
  if (prob_21(D) > 100)
    goto <bb 11>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  if (zone_22(D) > 7)
    goto <bb 11>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 453655921]:
  # DEBUG BEGIN_STMT
  _1 = phy_23(D) + 250;
  if (_1 <= 3)
    goto <bb 6>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 6> [local count: 226827960]:
  # DEBUG BEGIN_STMT
  queue_temp_27 = pfe_tmu_hif_q_to_tmu_q (cbus_base_va_25(D), phy_23(D), queue_20(D));
  # DEBUG queue_temp => queue_temp_27
  # DEBUG BEGIN_STMT
  if (queue_temp_27 == 255)
    goto <bb 11>; [21.72%]
  else
    goto <bb 9>; [78.28%]

  <bb 9> [local count: 404388888]:
  # queue_temp_35 = PHI <queue_temp_27(6), queue_20(D)(4)>
  # DEBUG queue_temp => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = zone_22(D) / 6;
  pos_28 = _2 + 5;
  # DEBUG pos => pos_28
  # DEBUG BEGIN_STMT
  _3 = queue_temp_35 * 8;
  _4 = _3 + pos_28;
  ret_30 = pfe_tmu_cntx_mem_read (cbus_base_va_25(D), phy_23(D), _4, &reg);
  # DEBUG ret => ret_30
  # DEBUG BEGIN_STMT
  if (ret_30 == 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 133448333]:
  # DEBUG BEGIN_STMT
  _5 = zone_22(D) % 6;
  _6 = (unsigned int) _5;
  _7 = _6 * 5;
  _8 = 31 << _7;
  _9 = ~_8;
  reg.17_10 = reg;
  _11 = _9 & reg.17_10;
  # DEBUG BEGIN_STMT
  _12 = (long unsigned int) prob_21(D);
  _13 = _12 * 31;
  _14 = _13 / 100;
  _15 = _14;
  _16 = _15 << _7;
  _17 = _11 | _16;
  reg = _17;
  # DEBUG BEGIN_STMT
  ret_33 = pfe_tmu_cntx_mem_write (cbus_base_va_25(D), phy_23(D), _4, _17);
  # DEBUG ret => ret_33

  <bb 11> [local count: 1073741824]:
  # ret_18 = PHI <22(3), 22(6), ret_30(9), ret_33(10), 22(2)>
  # DEBUG queue_temp => NULL
  # DEBUG ret => ret_18
  # DEBUG BEGIN_STMT
  reg ={v} {CLOBBER};
  return ret_18;

}



;; Function pfe_tmu_q_get_wred_probability (pfe_tmu_q_get_wred_probability, funcdef_no=34, decl_uid=9497, cgraph_uid=35, symbol_order=38)

Modification phase of node pfe_tmu_q_get_wred_probability/38
pfe_tmu_q_get_wred_probability (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue, uint8_t zone, uint8_t * prob)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG queue_temp => queue_2(D)
  # DEBUG BEGIN_STMT
  if (zone_3(D) > 7)
    goto <bb 4>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932184]:
  ret_8 = pfe_tmu_q_get_wred_probability.part.0 (cbus_base_va_6(D), phy_4(D), queue_2(D), zone_3(D), prob_9(D));

  <bb 4> [local count: 1073741824]:
  # ret_1 = PHI <22(2), ret_8(3)>
  # DEBUG queue_temp => NULL
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_tmu_q_get_wred_zones (pfe_tmu_q_get_wred_zones, funcdef_no=35, decl_uid=9501, cgraph_uid=36, symbol_order=39)

Modification phase of node pfe_tmu_q_get_wred_zones/39
pfe_tmu_q_get_wred_zones (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t queue)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 8;

}



;; Function pfe_tmu_shp_cfg_set_limits (pfe_tmu_shp_cfg_set_limits, funcdef_no=36, decl_uid=9535, cgraph_uid=37, symbol_order=40)

Modification phase of node pfe_tmu_shp_cfg_set_limits/40
pfe_tmu_shp_cfg_set_limits (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp, int32_t max_credit, int32_t min_credit)
{
  errno_t ret;
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int max_credit.22_8;
  unsigned int min_credit.23_9;
  unsigned int _10;
  unsigned int _11;
  volatile uint32_t * _12;
  long unsigned int _13;
  long int _14;
  unsigned int _15;
  volatile uint32_t * _16;
  long unsigned int _17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_20(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_21(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_23 = _7 + cbus_base_va_22(D);
  # DEBUG shp_base_va => shp_base_va_23
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  max_credit.22_8 = (unsigned int) max_credit_24(D);
  if (max_credit.22_8 > 4194303)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Max credit value exceeded\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 1159, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  min_credit.23_9 = (unsigned int) min_credit_25(D);
  _10 = min_credit.23_9 + 4194303;
  if (_10 > 4194303)
    goto <bb 5>; [20.96%]
  else
    goto <bb 6>; [79.04%]

  <bb 5> [local count: 177884489]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Min credit value exceeded\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 1164, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 670801049]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = shp_base_va_23 + 8;
  _12 = (volatile uint32_t *) _11;
  _13 = max_credit.22_8 << 10;
  *_12 ={v} _13;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = -min_credit_25(D);
  _15 = shp_base_va_23 + 16;
  _16 = (volatile uint32_t *) _15;
  _17 = (long unsigned int) _14;
  *_16 ={v} _17;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741824]:
  # ret_18 = PHI <22(3), 22(5), 0(6)>
  # DEBUG ret => ret_18
  # DEBUG BEGIN_STMT
  return ret_18;

}



;; Function pfe_tmu_shp_cfg_get_limits (pfe_tmu_shp_cfg_get_limits, funcdef_no=37, decl_uid=9541, cgraph_uid=38, symbol_order=41)

Modification phase of node pfe_tmu_shp_cfg_get_limits/41
pfe_tmu_shp_cfg_get_limits (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp, int32_t * max_credit, int32_t * min_credit)
{
  const uint32_t min_credit_hw;
  addr_t shp_base_va;
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
  long unsigned int _11;
  long int _12;
  unsigned int _13;
  volatile uint32_t * _14;
  long int min_credit_hw.25_15;
  long int _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_17(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_18(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_20 = _7 + cbus_base_va_19(D);
  # DEBUG shp_base_va => shp_base_va_20
  # DEBUG BEGIN_STMT
  _8 = shp_base_va_20 + 8;
  _9 = (volatile uint32_t *) _8;
  _10 ={v} *_9;
  _11 = _10 >> 10;
  _12 = (long int) _11;
  *max_credit_22(D) = _12;
  # DEBUG BEGIN_STMT
  _13 = shp_base_va_20 + 16;
  _14 = (volatile uint32_t *) _13;
  min_credit_hw_24 ={v} *_14;
  # DEBUG min_credit_hw => min_credit_hw_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  min_credit_hw.25_15 = (long int) min_credit_hw_24;
  _16 = -min_credit_hw.25_15;
  *min_credit_25(D) = _16;
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_tmu_shp_cfg_set_position (pfe_tmu_shp_cfg_set_position, funcdef_no=38, decl_uid=9546, cgraph_uid=39, symbol_order=42)

Modification phase of node pfe_tmu_shp_cfg_set_position/42
pfe_tmu_shp_cfg_set_position (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp, uint8_t pos)
{
  errno_t ret;
  uint32_t reg;
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned char _8;
  int _9;
  unsigned int _10;
  volatile uint32_t * _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_17(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_18(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_20 = _7 + cbus_base_va_19(D);
  # DEBUG shp_base_va => shp_base_va_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = pos_21(D) + 239;
  if (_8 <= 237)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = (int) pos_21(D);
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid shaper position: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 1220, _9, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  _10 = shp_base_va_20 + 12;
  _11 = (volatile uint32_t *) _10;
  reg_23 ={v} *_11;
  # DEBUG reg => reg_23
  # DEBUG BEGIN_STMT
  reg_24 = reg_23 & 4294967233;
  # DEBUG reg => reg_24
  # DEBUG BEGIN_STMT
  _12 = (long unsigned int) pos_21(D);
  _13 = _12 << 1;
  _14 = _13 & 62;
  reg_25 = _14 | reg_24;
  # DEBUG reg => reg_25
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_11 ={v} reg_25;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_15 = PHI <22(3), 0(4)>
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  return ret_15;

}



;; Function pfe_tmu_shp_cfg_get_position (pfe_tmu_shp_cfg_get_position, funcdef_no=39, decl_uid=9550, cgraph_uid=40, symbol_order=43)

Modification phase of node pfe_tmu_shp_cfg_get_position/43
pfe_tmu_shp_cfg_get_position (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp)
{
  addr_t shp_base_va;
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
  long unsigned int _11;
  unsigned char _12;
  uint8_t _18;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_13(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_14(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_16 = _7 + cbus_base_va_15(D);
  # DEBUG shp_base_va => shp_base_va_16
  # DEBUG BEGIN_STMT
  _8 = shp_base_va_16 + 12;
  _9 = (volatile uint32_t *) _8;
  _10 ={v} *_9;
  _11 = _10 >> 1;
  _12 = (unsigned char) _11;
  _18 = _12 & 31;
  return _18;

}



;; Function pfe_tmu_shp_cfg_enable (pfe_tmu_shp_cfg_enable, funcdef_no=40, decl_uid=9511, cgraph_uid=41, symbol_order=44)

Modification phase of node pfe_tmu_shp_cfg_enable/44
pfe_tmu_shp_cfg_enable (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp)
{
  uint32_t reg;
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  volatile uint32_t * shp_base_va.26_8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_10(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_11(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_13 = _7 + cbus_base_va_12(D);
  # DEBUG shp_base_va => shp_base_va_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  shp_base_va.26_8 = (volatile uint32_t *) shp_base_va_13;
  _9 ={v} *shp_base_va.26_8;
  reg_15 = _9 | 1;
  # DEBUG reg => reg_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *shp_base_va.26_8 ={v} reg_15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_tmu_shp_cfg_set_rate_mode (pfe_tmu_shp_cfg_set_rate_mode, funcdef_no=41, decl_uid=9516, cgraph_uid=42, symbol_order=45)

Modification phase of node pfe_tmu_shp_cfg_set_rate_mode/45
pfe_tmu_shp_cfg_set_rate_mode (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp, pfe_tmu_rate_mode_t mode)
{
  uint32_t reg;
  errno_t ret;
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_11(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_12(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_14 = _7 + cbus_base_va_13(D);
  # DEBUG shp_base_va => shp_base_va_14
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = shp_base_va_14 + 12;
  _9 = (volatile uint32_t *) _8;
  reg_16 ={v} *_9;
  # DEBUG reg => reg_16
  # DEBUG BEGIN_STMT
  if (mode_17(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  reg_19 = reg_16 & 4294967294;
  # DEBUG reg => reg_19
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (mode_17(D) == 1)
    goto <bb 5>; [48.89%]
  else
    goto <bb 7>; [51.11%]

  <bb 5> [local count: 262476189]:
  # DEBUG BEGIN_STMT
  reg_18 = reg_16 | 1;
  # DEBUG reg => reg_18
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 799347102]:
  # reg_22 = PHI <reg_18(5), reg_19(3)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_9 ={v} reg_22;

  <bb 7> [local count: 1073741824]:
  # ret_21 = PHI <22(4), 0(6)>
  # DEBUG reg => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_21;

}



;; Function pfe_tmu_shp_cfg_get_rate_mode (pfe_tmu_shp_cfg_get_rate_mode, funcdef_no=42, decl_uid=9520, cgraph_uid=43, symbol_order=46)

Modification phase of node pfe_tmu_shp_cfg_get_rate_mode/46
pfe_tmu_shp_cfg_get_rate_mode (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp)
{
  uint32_t reg;
  pfe_tmu_rate_mode_t rate_mode;
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  volatile uint32_t * shp_base_va.28_8;
  long unsigned int _9;
  unsigned int _10;
  volatile uint32_t * _11;
  long unsigned int _12;
  <unnamed type> _21;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_14(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_15(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_17 = _7 + cbus_base_va_16(D);
  # DEBUG shp_base_va => shp_base_va_17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  shp_base_va.28_8 = (volatile uint32_t *) shp_base_va_17;
  reg_19 ={v} *shp_base_va.28_8;
  # DEBUG reg => reg_19
  # DEBUG BEGIN_STMT
  _9 = reg_19 & 1;
  if (_9 == 0)
    goto <bb 4>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _10 = shp_base_va_17 + 12;
  _11 = (volatile uint32_t *) _10;
  reg_20 ={v} *_11;
  # DEBUG reg => reg_20
  # DEBUG BEGIN_STMT
  _12 = reg_20 & 1;
  _21 = (<unnamed type>) _12;

  <bb 4> [local count: 1073741824]:
  # rate_mode_13 = PHI <2(2), _21(3)>
  # DEBUG rate_mode => rate_mode_13
  # DEBUG BEGIN_STMT
  return rate_mode_13;

}



;; Function pfe_tmu_shp_cfg_set_idle_slope (pfe_tmu_shp_cfg_set_idle_slope, funcdef_no=43, decl_uid=9525, cgraph_uid=44, symbol_order=47)

Modification phase of node pfe_tmu_shp_cfg_set_idle_slope/47
pfe_tmu_shp_cfg_set_idle_slope (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp, uint32_t isl)
{
  uint64_t sys_clk_hz;
  uint64_t wgt;
  errno_t ret;
  uint32_t reg;
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  long long unsigned int _10;
  <unnamed type> _11;
  long long unsigned int _12;
  long long unsigned int _13;
  long long unsigned int _14;
  long long unsigned int _15;
  long long unsigned int _16;
  long long unsigned int _17;
  long long unsigned int _18;
  long unsigned int _19;
  unsigned int _20;
  volatile uint32_t * _21;
  long unsigned int _22;
  volatile uint32_t * shp_base_va.29_23;
  long unsigned int _24;
  long unsigned int _30;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_26(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_27(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_29 = _7 + cbus_base_va_28(D);
  # DEBUG shp_base_va => shp_base_va_29
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = cbus_base_va_28(D) + 606272;
  _9 = (volatile uint32_t *) _8;
  reg_32 ={v} *_9;
  # DEBUG reg => reg_32
  # DEBUG BEGIN_STMT
  _30 = reg_32 & 65535;
  _10 = (long long unsigned int) _30;
  sys_clk_hz_33 = _10 * 1000000;
  # DEBUG sys_clk_hz => sys_clk_hz_33
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = pfe_tmu_shp_cfg_get_rate_mode (cbus_base_va_28(D), phy_26(D), shp_27(D));
  switch (_11) <default: <L11> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357878150]:
<L0>:
  # DEBUG BEGIN_STMT
  _12 = (long long unsigned int) isl_35(D);
  _13 = _12 + 1;
  _14 = _13 * 1048576;
  _15 = _10 * 8000000;
  wgt_37 = _14 / _15;
  # DEBUG wgt => wgt_37
  # DEBUG BEGIN_STMT
  # DEBUG wgt => wgt_37
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  _16 = (long long unsigned int) isl_35(D);
  _17 = _16 + 1;
  _18 = _17 * 1048576;
  wgt_36 = _18 / sys_clk_hz_33;
  # DEBUG wgt => wgt_36
  # DEBUG BEGIN_STMT
  # DEBUG wgt => wgt_36
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 715756301]:
  # wgt_44 = PHI <wgt_36(4), wgt_37(3)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = (long unsigned int) wgt_44;
  _20 = shp_base_va_29 + 4;
  _21 = (volatile uint32_t *) _20;
  _22 = _19 & 1048575;
  *_21 ={v} _22;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  shp_base_va.29_23 = (volatile uint32_t *) shp_base_va_29;
  reg_40 ={v} *shp_base_va.29_23;
  # DEBUG reg => reg_40
  # DEBUG BEGIN_STMT
  reg_41 = reg_40 & 1;
  # DEBUG reg => reg_41
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _24 = reg_41 | 14;
  *shp_base_va.29_23 ={v} _24;

  <bb 6> [local count: 1073634451]:
  # ret_43 = PHI <22(2), 0(5)>
<L11>:
  # DEBUG wgt => NULL
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_43;

}



;; Function pfe_tmu_shp_cfg_get_idle_slope (pfe_tmu_shp_cfg_get_idle_slope, funcdef_no=44, decl_uid=9529, cgraph_uid=45, symbol_order=48)

Modification phase of node pfe_tmu_shp_cfg_get_idle_slope/48
pfe_tmu_shp_cfg_get_idle_slope (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp)
{
  uint64_t isl;
  uint32_t reg;
  uint32_t wgt;
  uint64_t sys_clk_hz;
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  long long unsigned int _10;
  unsigned int _11;
  volatile uint32_t * _12;
  long unsigned int _13;
  <unnamed type> _14;
  long long unsigned int _15;
  long long unsigned int _16;
  long long unsigned int _17;
  long long unsigned int _18;
  long long unsigned int _19;
  long unsigned int _32;
  uint32_t _33;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_21(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_22(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_24 = _7 + cbus_base_va_23(D);
  # DEBUG shp_base_va => shp_base_va_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = cbus_base_va_23(D) + 606272;
  _9 = (volatile uint32_t *) _8;
  reg_26 ={v} *_9;
  # DEBUG reg => reg_26
  # DEBUG BEGIN_STMT
  _32 = reg_26 & 65535;
  _10 = (long long unsigned int) _32;
  sys_clk_hz_27 = _10 * 1000000;
  # DEBUG sys_clk_hz => sys_clk_hz_27
  # DEBUG BEGIN_STMT
  _11 = shp_base_va_24 + 4;
  _12 = (volatile uint32_t *) _11;
  _13 ={v} *_12;
  wgt_28 = _13 & 1048575;
  # DEBUG wgt => wgt_28
  # DEBUG BEGIN_STMT
  _14 = pfe_tmu_shp_cfg_get_rate_mode (cbus_base_va_23(D), phy_21(D), shp_22(D));
  switch (_14) <default: <L5> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357878150]:
<L0>:
  # DEBUG BEGIN_STMT
  _15 = (long long unsigned int) wgt_28;
  _16 = _15 * sys_clk_hz_27;
  _17 = _16 * 8;
  isl_31 = _17 >> 20;
  # DEBUG isl => isl_31
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  _18 = (long long unsigned int) wgt_28;
  _19 = _18 * sys_clk_hz_27;
  isl_30 = _19 >> 20;
  # DEBUG isl => isl_30
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073634451]:
  # isl_20 = PHI <isl_31(3), isl_30(4), 0(2)>
<L5>:
  # DEBUG isl => isl_20
  # DEBUG BEGIN_STMT
  _33 = (uint32_t) isl_20;
  return _33;

}



;; Function pfe_tmu_shp_cfg_disable (pfe_tmu_shp_cfg_disable, funcdef_no=45, decl_uid=9554, cgraph_uid=46, symbol_order=49)

Modification phase of node pfe_tmu_shp_cfg_disable/49
pfe_tmu_shp_cfg_disable (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp)
{
  uint32_t reg;
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  volatile uint32_t * shp_base_va.31_8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_10(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_11(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_13 = _7 + cbus_base_va_12(D);
  # DEBUG shp_base_va => shp_base_va_13
  # DEBUG BEGIN_STMT
  shp_base_va.31_8 = (volatile uint32_t *) shp_base_va_13;
  _9 ={v} *shp_base_va.31_8;
  reg_15 = _9 & 4294967294;
  # DEBUG reg => reg_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *shp_base_va.31_8 ={v} reg_15;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_tmu_shp_cfg_init (pfe_tmu_shp_cfg_init, funcdef_no=46, decl_uid=9507, cgraph_uid=47, symbol_order=50)

Modification phase of node pfe_tmu_shp_cfg_init/50
pfe_tmu_shp_cfg_init (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t shp)
{
  addr_t shp_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  unsigned int _10;
  volatile uint32_t * _11;
  unsigned int _12;
  volatile uint32_t * _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_14(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) shp_15(D);
  _5 = _3 + _4;
  _6 = _5 + 2;
  _7 = _6 * 256;
  shp_base_va_17 = _7 + cbus_base_va_16(D);
  # DEBUG shp_base_va => shp_base_va_17
  # DEBUG BEGIN_STMT
  pfe_tmu_shp_cfg_disable (cbus_base_va_16(D), phy_14(D), shp_15(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = shp_base_va_17 + 12;
  _9 = (volatile uint32_t *) _8;
  *_9 ={v} 62;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = shp_base_va_17 + 8;
  _11 = (volatile uint32_t *) _10;
  *_11 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = shp_base_va_17 + 16;
  _13 = (volatile uint32_t *) _12;
  *_13 ={v} 0;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_tmu_sch_cfg_init (pfe_tmu_sch_cfg_init, funcdef_no=47, decl_uid=9558, cgraph_uid=48, symbol_order=51)

Modification phase of node pfe_tmu_sch_cfg_init/51
pfe_tmu_sch_cfg_init (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch)
{
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;
  unsigned int _9;
  volatile uint32_t * _10;
  unsigned int _11;
  volatile uint32_t * _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_14(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_15(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_17 = _6 + cbus_base_va_16(D);
  # DEBUG sch_base_va => sch_base_va_17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = sch_base_va_17 + 64;
  _8 = (volatile uint32_t *) _7;
  *_8 ={v} 4294967295;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = sch_base_va_17 + 68;
  _10 = (volatile uint32_t *) _9;
  *_10 ={v} 4294967295;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (sch_15(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = sch_base_va_17 + 84;
  _12 = (volatile uint32_t *) _11;
  *_12 ={v} 15;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_tmu_sch_cfg_set_rate_mode (pfe_tmu_sch_cfg_set_rate_mode, funcdef_no=48, decl_uid=9563, cgraph_uid=49, symbol_order=52)

Modification phase of node pfe_tmu_sch_cfg_set_rate_mode/52
pfe_tmu_sch_cfg_set_rate_mode (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch, pfe_tmu_rate_mode_t mode)
{
  errno_t ret;
  uint32_t reg;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_10(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_11(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_13 = _6 + cbus_base_va_12(D);
  # DEBUG sch_base_va => sch_base_va_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (mode_14(D) == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (mode_14(D) == 1)
    goto <bb 4>; [48.89%]
  else
    goto <bb 5>; [51.11%]

  <bb 4> [local count: 799347102]:
  # reg_18 = PHI <1(3), 0(2)>
  # DEBUG ret => NULL
  # DEBUG reg => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = sch_base_va_13 + 72;
  _8 = (volatile uint32_t *) _7;
  *_8 ={v} reg_18;

  <bb 5> [local count: 1073741824]:
  # ret_19 = PHI <22(3), 0(4)>
  # DEBUG ret => NULL
  # DEBUG reg => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_19;

}



;; Function pfe_tmu_sch_cfg_get_rate_mode (pfe_tmu_sch_cfg_get_rate_mode, funcdef_no=49, decl_uid=9567, cgraph_uid=50, symbol_order=53)

Modification phase of node pfe_tmu_sch_cfg_get_rate_mode/53
pfe_tmu_sch_cfg_get_rate_mode (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch)
{
  uint32_t reg;
  pfe_tmu_rate_mode_t rmode;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _7;
  volatile uint32_t * _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_10(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_11(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_13 = _6 + cbus_base_va_12(D);
  # DEBUG sch_base_va => sch_base_va_13
  # DEBUG BEGIN_STMT
  # DEBUG rmode => 2
  # DEBUG BEGIN_STMT
  _7 = sch_base_va_13 + 72;
  _8 = (volatile uint32_t *) _7;
  reg_15 ={v} *_8;
  # DEBUG reg => reg_15
  # DEBUG BEGIN_STMT
  if (reg_15 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (reg_15 == 1)
    goto <bb 5>; [48.89%]
  else
    goto <bb 4>; [51.11%]

  <bb 4> [local count: 274394723]:
  # DEBUG BEGIN_STMT
  # DEBUG rmode => 2

  <bb 5> [local count: 1073741824]:
  # rmode_9 = PHI <0(2), 1(3), 2(4)>
  # DEBUG rmode => rmode_9
  # DEBUG BEGIN_STMT
  return rmode_9;

}



;; Function pfe_tmu_sch_cfg_set_algo (pfe_tmu_sch_cfg_set_algo, funcdef_no=50, decl_uid=9572, cgraph_uid=51, symbol_order=54)

Modification phase of node pfe_tmu_sch_cfg_set_algo/54
pfe_tmu_sch_cfg_set_algo (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch, pfe_tmu_sched_algo_t algo)
{
  errno_t ret;
  uint32_t reg;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  <unnamed type> _7;
  volatile uint32_t * sch_base_va.33_8;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_9(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_10(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_12 = _6 + cbus_base_va_11(D);
  # DEBUG sch_base_va => sch_base_va_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (algo_13(D) == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  if (algo_13(D) == 1)
    goto <bb 8>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 4> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  if (algo_13(D) == 2)
    goto <bb 8>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 233860969]:
  # DEBUG BEGIN_STMT
  if (algo_13(D) == 3)
    goto <bb 6>; [32.03%]
  else
    goto <bb 9>; [67.97%]

  <bb 6> [local count: 74905668]:
  # DEBUG BEGIN_STMT
  _7 = pfe_tmu_sch_cfg_get_rate_mode (cbus_base_va_11(D), phy_9(D), sch_10(D));
  if (_7 != 1)
    goto <bb 7>; [33.99%]
  else
    goto <bb 8>; [66.01%]

  <bb 7> [local count: 25460437]:
  # DEBUG D#3 => cbus_base_va_11(D)
  # DEBUG D#4 => phy_9(D)
  # DEBUG D#5 => sch_10(D)
  # DEBUG D#6 => algo_13(D)
  ret_17 = pfe_tmu_sch_cfg_set_algo.part.0 ();
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 889326086]:
  # reg_21 = PHI <2(3), 0(2), 4(6), 3(4)>
  # DEBUG ret => NULL
  # DEBUG reg => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sch_base_va.33_8 = (volatile uint32_t *) sch_base_va_12;
  *sch_base_va.33_8 ={v} reg_21;

  <bb 9> [local count: 1073741824]:
  # ret_22 = PHI <22(5), 0(8), ret_17(7)>
  # DEBUG ret => NULL
  # DEBUG reg => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_22;

}



;; Function pfe_tmu_sch_cfg_get_algo (pfe_tmu_sch_cfg_get_algo, funcdef_no=51, decl_uid=9576, cgraph_uid=52, symbol_order=55)

Modification phase of node pfe_tmu_sch_cfg_get_algo/55
pfe_tmu_sch_cfg_get_algo (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch)
{
  pfe_tmu_sched_algo_t algo;
  uint32_t reg;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  volatile uint32_t * sch_base_va.34_7;
  long unsigned int _8;
  <unnamed type> _17;
  unsigned int _19;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_10(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_11(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_13 = _6 + cbus_base_va_12(D);
  # DEBUG sch_base_va => sch_base_va_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG algo => 4
  # DEBUG BEGIN_STMT
  sch_base_va.34_7 = (volatile uint32_t *) sch_base_va_13;
  reg_16 ={v} *sch_base_va.34_7;
  # DEBUG reg => reg_16
  # DEBUG BEGIN_STMT
  _8 = reg_16 & 15;
  _19 = _8;
  if (_19 <= 4)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
<L8>:
  algo_18 = 4;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
<L9>:
  _17 = CSWTCH.82[_19];
  algo_14 = _17;

  <bb 5> [local count: 1073741824]:
  # algo_9 = PHI <algo_18(3), algo_14(4)>
<L10>:
<L7>:
  # DEBUG algo => algo_9
  # DEBUG BEGIN_STMT
  return algo_9;

}



;; Function pfe_tmu_sch_cfg_set_input_weight (pfe_tmu_sch_cfg_set_input_weight, funcdef_no=52, decl_uid=9582, cgraph_uid=53, symbol_order=56)

Modification phase of node pfe_tmu_sch_cfg_set_input_weight/56
pfe_tmu_sch_cfg_set_input_weight (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch, uint8_t input, uint32_t weight)
{
  errno_t ret;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  int _7;
  long unsigned int _8;
  long unsigned int _9;
  unsigned int _10;
  unsigned int _11;
  volatile uint32_t * _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_15(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_16(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_18 = _6 + cbus_base_va_17(D);
  # DEBUG sch_base_va => sch_base_va_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (input_19(D) > 7)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = (int) input_19(D);
  pfe_hm_report (1, 2, 1, "[%s:%d] Scheduler input (%d) out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 1723, _7, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = (long unsigned int) input_19(D);
  _9 = _8 * 4;
  _10 = _9 + sch_base_va_18;
  _11 = _10 + 32;
  _12 = (volatile uint32_t *) _11;
  *_12 ={v} weight_21(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_13 = PHI <22(3), 0(4)>
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  return ret_13;

}



;; Function pfe_tmu_sch_cfg_get_input_weight (pfe_tmu_sch_cfg_get_input_weight, funcdef_no=53, decl_uid=9587, cgraph_uid=54, symbol_order=57)

Modification phase of node pfe_tmu_sch_cfg_get_input_weight/57
pfe_tmu_sch_cfg_get_input_weight (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch, uint8_t input)
{
  uint32_t input_weight;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  int _7;
  long unsigned int _8;
  long unsigned int _9;
  unsigned int _10;
  unsigned int _11;
  volatile uint32_t * _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_15(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_16(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_18 = _6 + cbus_base_va_17(D);
  # DEBUG sch_base_va => sch_base_va_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (input_19(D) > 7)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = (int) input_19(D);
  pfe_hm_report (1, 2, 1, "[%s:%d] Scheduler input (%d) out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 1752, _7, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG input_weight => 0
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  _8 = (long unsigned int) input_19(D);
  _9 = _8 * 4;
  _10 = _9 + sch_base_va_18;
  _11 = _10 + 32;
  _12 = (volatile uint32_t *) _11;
  input_weight_21 ={v} *_12;
  # DEBUG input_weight => input_weight_21

  <bb 5> [local count: 1073741824]:
  # input_weight_13 = PHI <0(3), input_weight_21(4)>
  # DEBUG input_weight => input_weight_13
  # DEBUG BEGIN_STMT
  return input_weight_13;

}



;; Function pfe_tmu_sch_cfg_bind_queue (pfe_tmu_sch_cfg_bind_queue, funcdef_no=54, decl_uid=9604, cgraph_uid=55, symbol_order=58)

Modification phase of node pfe_tmu_sch_cfg_bind_queue/58
pfe_tmu_sch_cfg_bind_queue (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch, uint8_t input, uint8_t queue)
{
  errno_t ret;
  uint32_t reg;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned char _7;
  unsigned char _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned int _11;
  unsigned int _12;
  volatile uint32_t * _13;
  unsigned int _15;
  unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _20;
  long unsigned int _22;
  unsigned char _35;
  unsigned char _36;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_24(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_25(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_27 = _6 + cbus_base_va_26(D);
  # DEBUG sch_base_va => sch_base_va_27
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = queue_28(D) + 248;
  if (_7 <= 246)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid queue\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 1784, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  if (input_29(D) > 7)
    goto <bb 5>; [20.96%]
  else
    goto <bb 6>; [79.04%]

  <bb 5> [local count: 177884490]:
  # DEBUG D#11 => cbus_base_va_26(D)
  # DEBUG D#12 => phy_24(D)
  # DEBUG D#13 => sch_25(D)
  # DEBUG D#14 => queue_28(D)
  ret_14 = pfe_tmu_sch_cfg_bind_queue.part.0 (input_29(D));
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 670801049]:
  # DEBUG BEGIN_STMT
  _8 = input_29(D) >> 2;
  _9 = (long unsigned int) _8;
  _10 = _9 * 4;
  _11 = _10 + sch_base_va_27;
  _12 = _11 + 64;
  _13 = (volatile uint32_t *) _12;
  reg_31 ={v} *_13;
  # DEBUG reg => reg_31
  # DEBUG BEGIN_STMT
  _35 = input_29(D) & 3;
  _15 = (unsigned int) _35;
  _16 = _15 * 8;
  _17 = 255 << _16;
  _18 = ~_17;
  reg_32 = _18 & reg_31;
  # DEBUG reg => reg_32
  # DEBUG BEGIN_STMT
  _36 = queue_28(D) & 31;
  _20 = (long unsigned int) _36;
  _22 = _20 << _16;
  reg_33 = _22 | reg_32;
  # DEBUG reg => reg_33
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_13 ={v} reg_33;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741824]:
  # ret_23 = PHI <22(3), ret_14(5), 0(6)>
  # DEBUG ret => ret_23
  # DEBUG BEGIN_STMT
  return ret_23;

}



;; Function pfe_tmu_cfg_init (pfe_tmu_cfg_init, funcdef_no=17, decl_uid=9612, cgraph_uid=18, symbol_order=21)

Modification phase of node pfe_tmu_cfg_init/21
pfe_tmu_cfg_init (addr_t cbus_base_va, const struct pfe_tmu_cfg_t * cfg)
{
  bool_t has_tlite_phy5;
  uint32_t regval;
  errno_t ret;
  uint32_t ii;
  unsigned char _1;
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
  unsigned int _22;
  volatile uint32_t * _23;
  unsigned int _24;
  volatile uint32_t * _25;
  unsigned char _26;
  <unnamed type> _27;
  unsigned int _28;
  volatile uint32_t * _29;
  unsigned int _30;
  volatile uint32_t * _31;
  unsigned int _32;
  volatile uint32_t * _33;
  unsigned int _34;
  volatile uint32_t * _35;
  unsigned int _36;
  volatile uint32_t * _37;
  int iftmp.6_43;

  <bb 2> [local count: 204054434]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = cfg_51(D)->on_g3;
  if (_1 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 69378508]:
  # DEBUG BEGIN_STMT
  _2 = cbus_base_va_52(D) + 524364;
  _3 = (volatile uint32_t *) _2;
  regval_53 ={v} *_3;
  # DEBUG regval => regval_53
  # DEBUG BEGIN_STMT
  regval_54 = regval_53 | 4;
  # DEBUG regval => regval_54
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_3 ={v} regval_54;

  <bb 4> [local count: 204054434]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = cbus_base_va_52(D) + 524528;
  _5 = (volatile uint32_t *) _4;
  *_5 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = cbus_base_va_52(D) + 524532;
  _7 = (volatile uint32_t *) _6;
  *_7 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = cbus_base_va_52(D) + 524536;
  _9 = (volatile uint32_t *) _8;
  *_9 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = cbus_base_va_52(D) + 524540;
  _11 = (volatile uint32_t *) _10;
  *_11 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = cbus_base_va_52(D) + 524548;
  _13 = (volatile uint32_t *) _12;
  *_13 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_tmu_cfg_reset (cbus_base_va_52(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = cbus_base_va_52(D) + 524388;
  _15 = (volatile uint32_t *) _14;
  *_15 ={v} 3221930032;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = cbus_base_va_52(D) + 524392;
  _17 = (volatile uint32_t *) _16;
  *_17 ={v} 3221946416;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _18 = cbus_base_va_52(D) + 524396;
  _19 = (volatile uint32_t *) _18;
  *_19 ={v} 3221962800;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = cbus_base_va_52(D) + 524452;
  _21 = (volatile uint32_t *) _20;
  *_21 ={v} 3221864496;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 = cbus_base_va_52(D) + 524400;
  _23 = (volatile uint32_t *) _22;
  *_23 ={v} 3221864496;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _24 = cbus_base_va_52(D) + 524408;
  _25 = (volatile uint32_t *) _24;
  *_25 ={v} 3222061072;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 14>; [100.00%]

  <bb 5> [local count: 920304117]:
  # DEBUG BEGIN_STMT
  _26 = cfg_51(D)->on_g3;
  if (_26 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 460152058]:
  _27 = phy_if_id_temp[ii_38];
  if (_27 != 5)
    goto <bb 8>; [66.00%]
  else
    goto <bb 7>; [34.00%]

  <bb 7> [local count: 156451700]:

  <bb 8> [local count: 920304117]:
  # iftmp.6_43 = PHI <1(6), 0(7), 1(5)>
  has_tlite_phy5_68 = (bool_t) iftmp.6_43;
  # DEBUG has_tlite_phy5 => has_tlite_phy5_68
  # DEBUG BEGIN_STMT
  if (has_tlite_phy5_68 == 1)
    goto <bb 9>; [20.24%]
  else
    goto <bb 10>; [79.76%]

  <bb 9> [local count: 186269553]:
  # DEBUG BEGIN_STMT
  ret_70 = pfe_tmu_tdq_shp_on_phy5_g2 (cbus_base_va_52(D), ii_38);
  # DEBUG ret => ret_70

  <bb 10> [local count: 920304117]:
  # ret_39 = PHI <ret_41(8), ret_70(9)>
  # DEBUG ret => ret_39
  # DEBUG BEGIN_STMT
  if (ret_39 == 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 11> [local count: 303700358]:
  # DEBUG BEGIN_STMT
  ret_72 = pfe_tmu_set_default_queue_mode (cbus_base_va_52(D), ii_38, has_tlite_phy5_68);
  # DEBUG ret => ret_72

  <bb 12> [local count: 920304117]:
  # ret_40 = PHI <ret_39(10), ret_72(11)>
  # DEBUG ret => ret_40
  # DEBUG BEGIN_STMT
  if (ret_40 != 0)
    goto <bb 15>; [5.50%]
  else
    goto <bb 13>; [94.50%]

  <bb 13> [local count: 869687391]:
  # DEBUG BEGIN_STMT
  ii_73 = ii_38 + 1;
  # DEBUG ii => ii_73

  <bb 14> [local count: 1073741824]:
  # ii_38 = PHI <0(4), ii_73(13)>
  # ret_41 = PHI <0(4), 0(13)>
  # DEBUG ret => ret_41
  # DEBUG ii => ii_38
  # DEBUG BEGIN_STMT
  if (ii_38 != 6)
    goto <bb 5>; [85.71%]
  else
    goto <bb 15>; [14.29%]

  <bb 15> [local count: 204054433]:
  # ret_42 = PHI <ret_40(12), ret_41(14)>
  # DEBUG ret => ret_42
  # DEBUG BEGIN_STMT
  if (ret_42 == 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 16> [local count: 102027217]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _28 = cbus_base_va_52(D) + 524348;
  _29 = (volatile uint32_t *) _28;
  *_29 ={v} 3221782580;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _30 = cbus_base_va_52(D) + 524368;
  _31 = (volatile uint32_t *) _30;
  *_31 ={v} 3221798964;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _32 = cbus_base_va_52(D) + 524352;
  _33 = (volatile uint32_t *) _32;
  *_33 ={v} 256;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _34 = cbus_base_va_52(D) + 524292;
  _35 = (volatile uint32_t *) _34;
  *_35 ={v} 252;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_5 ={v} 15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_7 ={v} 15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_9 ={v} 15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _36 = cbus_base_va_52(D) + 524592;
  _37 = (volatile uint32_t *) _36;
  *_37 ={v} 15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_11 ={v} 15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_13 ={v} 15;

  <bb 17> [local count: 204054433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_42;

}



;; Function pfe_tmu_sch_cfg_get_bound_queue (pfe_tmu_sch_cfg_get_bound_queue, funcdef_no=55, decl_uid=9609, cgraph_uid=56, symbol_order=59)

Modification phase of node pfe_tmu_sch_cfg_get_bound_queue/59
pfe_tmu_sch_cfg_get_bound_queue (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch, uint8_t input)
{
  uint8_t queue;
  uint32_t reg;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  int _7;
  unsigned char _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned int _11;
  unsigned int _12;
  volatile uint32_t * _13;
  unsigned int _14;
  unsigned int _15;
  long unsigned int _16;
  unsigned char _27;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_19(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) sch_20(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_22 = _6 + cbus_base_va_21(D);
  # DEBUG sch_base_va => sch_base_va_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (input_23(D) > 7)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = (int) input_23(D);
  pfe_hm_report (1, 2, 1, "[%s:%d] Scheduler input (%d) out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 1823, _7, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG queue => 255
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  _8 = input_23(D) >> 2;
  _9 = (long unsigned int) _8;
  _10 = _9 * 4;
  _11 = _10 + sch_base_va_22;
  _12 = _11 + 64;
  _13 = (volatile uint32_t *) _12;
  reg_25 ={v} *_13;
  # DEBUG reg => reg_25
  # DEBUG BEGIN_STMT
  _27 = input_23(D) & 3;
  _14 = (unsigned int) _27;
  _15 = _14 * 8;
  _16 = reg_25 >> _15;
  queue_26 = (uint8_t) _16;
  # DEBUG queue => queue_26
  # DEBUG BEGIN_STMT
  if (queue_26 > 7)
    goto <bb 5>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 5> [local count: 297039938]:
  # DEBUG BEGIN_STMT
  # DEBUG queue => 255

  <bb 6> [local count: 1073741824]:
  # queue_17 = PHI <255(3), queue_26(4), 255(5)>
  # DEBUG queue => queue_17
  # DEBUG BEGIN_STMT
  return queue_17;

}



;; Function pfe_tmu_sch_cfg_bind_sched_output (pfe_tmu_sch_cfg_bind_sched_output, funcdef_no=56, decl_uid=9593, cgraph_uid=57, symbol_order=60)

Modification phase of node pfe_tmu_sch_cfg_bind_sched_output/60
pfe_tmu_sch_cfg_bind_sched_output (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t src_sch, uint8_t dst_sch, uint8_t input)
{
  errno_t ret;
  addr_t sch_base_va;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  int _7;
  unsigned int _8;
  volatile uint32_t * _9;
  long unsigned int _10;
  unsigned char _22;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_13(D);
  _2 = _1 + 129;
  _3 = _2 * 16;
  _4 = (long unsigned int) src_sch_14(D);
  _5 = _3 + _4;
  _6 = _5 * 256;
  sch_base_va_16 = _6 + cbus_base_va_15(D);
  # DEBUG sch_base_va => sch_base_va_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (src_sch_14(D) != 0)
    goto <bb 4>; [20.96%]
  else
    goto <bb 3>; [79.04%]

  <bb 3> [local count: 848685538]:
  if (dst_sch_17(D) != 1)
    goto <bb 4>; [67.97%]
  else
    goto <bb 5>; [32.03%]

  <bb 4> [local count: 801907846]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Scheduler 0 output can only be connected to Scheduler 1 input\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_tmu_csr.c", 1859, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 271833978]:
  # DEBUG BEGIN_STMT
  _7 = pfe_tmu_sch_cfg_bind_queue (cbus_base_va_15(D), phy_13(D), 1, input_19(D), 255);
  if (_7 != 0)
    goto <bb 7>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 6> [local count: 176692085]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = sch_base_va_16 + 84;
  _9 = (volatile uint32_t *) _8;
  _22 = input_19(D) & 15;
  _10 = (long unsigned int) _22;
  *_9 ={v} _10;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741823]:
  # ret_11 = PHI <22(4), 22(5), 0(6)>
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  return ret_11;

}



;; Function pfe_tmu_sch_cfg_get_bound_sched_output (pfe_tmu_sch_cfg_get_bound_sched_output, funcdef_no=57, decl_uid=9598, cgraph_uid=58, symbol_order=61)

Modification phase of node pfe_tmu_sch_cfg_get_bound_sched_output/61
pfe_tmu_sch_cfg_get_bound_sched_output (addr_t cbus_base_va, pfe_ct_phy_if_id_t phy, uint8_t sch, uint8_t input)
{
  uint8_t sched_id;
  uint32_t reg;
  long unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) phy_9(D);
  _2 = _1 * 4096;
  _3 = _2 + cbus_base_va_10(D);
  # DEBUG sch_base_va => _3 + 528384
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG sched_id => NULL
  # DEBUG BEGIN_STMT
  _4 = _3 + 528468;
  _5 = (volatile uint32_t *) _4;
  _6 ={v} *_5;
  reg_13 = _6 & 255;
  # DEBUG reg => reg_13
  # DEBUG BEGIN_STMT
  _7 = (long unsigned int) input_14(D);
  if (_7 == reg_13)
    goto <bb 4>; [48.89%]
  else
    goto <bb 3>; [51.11%]

  <bb 3> [local count: 548789447]:
  # DEBUG BEGIN_STMT
  # DEBUG sched_id => 255

  <bb 4> [local count: 1073741824]:
  # sched_id_8 = PHI <0(2), 255(3)>
  # DEBUG sched_id => sched_id_8
  # DEBUG BEGIN_STMT
  return sched_id_8;

}



;; Function pfe_tmu_cfg_get_stat_value (pfe_tmu_cfg_get_stat_value, funcdef_no=58, decl_uid=9623, cgraph_uid=59, symbol_order=62)

Modification phase of node pfe_tmu_cfg_get_stat_value/62
pfe_tmu_cfg_get_stat_value (addr_t base_va, uint32_t stat_id)
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



;; Function pfe_tmu_cfg_get_special_stats (pfe_tmu_cfg_get_special_stats, funcdef_no=59, decl_uid=9626, cgraph_uid=60, symbol_order=63)

Modification phase of node pfe_tmu_cfg_get_special_stats/63
pfe_tmu_cfg_get_special_stats (addr_t base_va, struct pfe_tmu_stats_special_t * special_stats)
{
  uint32_t stat_value;
  uint32_t stat_value;
  uint32_t stat_value;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned int _13;
  volatile uint32_t * _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_6(D)
  # DEBUG stat_id => 524288
  # DEBUG INLINE_ENTRY pfe_tmu_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = base_va_6(D) + 524288;
  _14 = (volatile uint32_t *) _13;
  stat_value_15 ={v} *_14;
  # DEBUG stat_value => stat_value_15
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _1 = stat_value_15 >> 24;
  special_stats_7(D)->revision = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_6(D)
  # DEBUG stat_id => 524288
  # DEBUG INLINE_ENTRY pfe_tmu_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stat_value_12 ={v} *_14;
  # DEBUG stat_value => stat_value_12
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _2 = stat_value_12 >> 16;
  _3 = _2 & 255;
  special_stats_7(D)->version = _3;
  # DEBUG BEGIN_STMT
  # DEBUG base_va => base_va_6(D)
  # DEBUG stat_id => 524288
  # DEBUG INLINE_ENTRY pfe_tmu_cfg_get_stat_value
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stat_value_11 ={v} *_14;
  # DEBUG stat_value => stat_value_11
  # DEBUG BEGIN_STMT
  # DEBUG base_va => NULL
  # DEBUG stat_id => NULL
  # DEBUG stat_value => NULL
  _4 = stat_value_11 & 255;
  special_stats_7(D)->id = _4;
  return;

}



;; Function pfe_tmu_cfg_get_queue_stats (pfe_tmu_cfg_get_queue_stats, funcdef_no=60, decl_uid=9631, cgraph_uid=61, symbol_order=64)

Modification phase of node pfe_tmu_cfg_get_queue_stats/64
pfe_tmu_cfg_get_queue_stats (addr_t base_va, uint32_t phy_id, uint32_t queue_id, struct pfe_tmu_queue_stats * queue_stats)
{
  errno_t ret;
  uint8_t prob;
  uint8_t zone;
  uint32_t reg;
  <unnamed type> _1;
  unsigned char _2;
  int _3;
  int _4;
  int _5;
  unsigned char _6;
  unsigned char _7;
  int _8;
  long unsigned int reg.38_9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  int _17;
  int _18;
  int _19;
  unsigned char prob.42_20;
  long unsigned int iftmp.35_23;
  long unsigned int iftmp.36_24;
  long unsigned int iftmp.37_25;
  long unsigned int iftmp.35_36;
  long unsigned int iftmp.36_40;
  long unsigned int iftmp.37_43;

  <bb 2> [local count: 260275024]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1
  # DEBUG BEGIN_STMT
  reg = 0;
  # DEBUG BEGIN_STMT
  queue_id_32 = queue_id_31(D) & 7;
  # DEBUG queue_id => queue_id_32
  # DEBUG BEGIN_STMT
  _1 = phy_if_id_temp[phy_id_33(D)];
  _2 = (unsigned char) queue_id_32;
  _3 = pfe_tmu_q_cfg_get_fill_level (base_va_34(D), _1, _2, &reg);
  if (_3 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 130137512]:
  iftmp.35_36 = reg;

  <bb 4> [local count: 260275024]:
  # iftmp.35_23 = PHI <iftmp.35_36(3), 4294967295(2)>
  queue_stats_37(D)->level = iftmp.35_23;
  # DEBUG BEGIN_STMT
  _4 = pfe_tmu_q_cfg_get_drop_count (base_va_34(D), _1, _2, &reg);
  if (_4 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 130137512]:
  iftmp.36_40 = reg;

  <bb 6> [local count: 260275024]:
  # iftmp.36_24 = PHI <iftmp.36_40(5), 4294967295(4)>
  queue_stats_37(D)->drops = iftmp.36_24;
  # DEBUG BEGIN_STMT
  _5 = pfe_tmu_q_cfg_get_tx_count (base_va_34(D), _1, _2, &reg);
  if (_5 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 130137512]:
  iftmp.37_43 = reg;

  <bb 8> [local count: 260275024]:
  # iftmp.37_25 = PHI <iftmp.37_43(7), 4294967295(6)>
  queue_stats_37(D)->tx = iftmp.37_25;
  # DEBUG BEGIN_STMT
  _6 = _2 * 8;
  _7 = _6 + 4;
  _8 = pfe_tmu_cntx_mem_read (base_va_34(D), _1, _7, &reg);
  if (_8 == 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 9> [local count: 130137512]:
  # DEBUG BEGIN_STMT
  reg.38_9 = reg;
  _10 = reg.38_9 & 3;
  switch (_10) <default: <L19> [25.00%], case 0: <L10> [25.00%], case 1: <L11> [25.00%], case 2: <L12> [25.00%]>

  <bb 10> [local count: 32534378]:
<L10>:
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->mode = 2;
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->max = 0;
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->min = 0;
  # DEBUG BEGIN_STMT
  goto <bb 20>; [100.00%]

  <bb 11> [local count: 32534378]:
<L11>:
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->mode = 0;
  # DEBUG BEGIN_STMT
  _11 = reg.38_9 >> 11;
  _12 = _11 & 511;
  queue_stats_37(D)->max = _12;
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->min = 0;
  # DEBUG BEGIN_STMT
  goto <bb 20>; [100.00%]

  <bb 12> [local count: 32534378]:
<L12>:
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->mode = 1;
  # DEBUG BEGIN_STMT
  _13 = reg.38_9 >> 11;
  _14 = _13 & 511;
  queue_stats_37(D)->max = _14;
  # DEBUG BEGIN_STMT
  _15 = reg.38_9 >> 2;
  _16 = _15 & 511;
  queue_stats_37(D)->min = _16;
  # DEBUG BEGIN_STMT
  # DEBUG zone => 0
  goto <bb 17>; [100.00%]

  <bb 13> [local count: 1041207447]:
  # DEBUG BEGIN_STMT
  _17 = pfe_tmu_q_get_wred_probability (base_va_34(D), _1, _2, zone_21, &prob);
  if (_17 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 14> [local count: 520603723]:
  # DEBUG BEGIN_STMT
  _18 = (int) zone_21;
  queue_stats_37(D)->zprob[_18] = 255;
  goto <bb 16>; [100.00%]

  <bb 15> [local count: 520603723]:
  # DEBUG BEGIN_STMT
  _19 = (int) zone_21;
  prob.42_20 = prob;
  queue_stats_37(D)->zprob[_19] = prob.42_20;

  <bb 16> [local count: 1041207447]:
  # DEBUG BEGIN_STMT
  zone_52 = zone_21 + 1;
  # DEBUG zone => zone_52

  <bb 17> [local count: 1073741824]:
  # zone_21 = PHI <0(12), zone_52(16)>
  # DEBUG zone => zone_21
  # DEBUG BEGIN_STMT
  if (zone_21 != 32)
    goto <bb 13>; [96.97%]
  else
    goto <bb 20>; [3.03%]

  <bb 18> [local count: 32534378]:
<L19>:
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->mode = 3;
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->max = 0;
  # DEBUG BEGIN_STMT
  queue_stats_37(D)->min = 0;
  # DEBUG BEGIN_STMT

  <bb 20> [local count: 260275023]:
  # ret_22 = PHI <1(8), 0(11), 0(10), 0(18), 0(17)>
  # DEBUG ret => ret_22
  # DEBUG BEGIN_STMT
  reg ={v} {CLOBBER};
  prob ={v} {CLOBBER};
  return ret_22;

}


