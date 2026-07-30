
IPA constant propagation start:
Determining dynamic type for call: phy_if_3 = fci_get_phy_if_by_name (_2);
  Starting walk at: phy_if_3 = fci_get_phy_if_by_name (_2);
  instance pointer: _2  Outer instance pointer: shp_1(D) offset: 16 (bits) vtbl reference: 
Determining dynamic type for call: _22 = check_scheduler_input.isra.0 (_20, ii_21);
  Starting walk at: _22 = check_scheduler_input.isra.0 (_20, ii_21);
  instance pointer: _20  Outer instance pointer: _20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:cnt_8 = pfe_tmu_sch_get_input_cnt (_2, _4, _7);
  Function call may change dynamic type:ret_26 = pfe_tmu_sch_bind_queue (_23, _24, _25, ii_21, 255);
  Function call may change dynamic type:ret_60 = pfe_tmu_sch_set_input_weight (_46, _47, _49, ii_21, _59);
  Function call may change dynamic type:ret_37 = pfe_tmu_sch_bind_queue (_34, _35, _36, ii_21, _33);
  Function call may change dynamic type:ret_43 = pfe_tmu_sch_bind_sch_output (_39, _40, _42, _41, ii_21);
Determining dynamic type for call: phy_if_14 = fci_get_phy_if_by_name (_1);
  Starting walk at: phy_if_14 = fci_get_phy_if_by_name (_1);
  instance pointer: _1  Outer instance pointer: msg_6(D) offset: 144 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: gpi_16 = fci_qos_get_gpi (phy_if_14);
  Starting walk at: gpi_16 = fci_qos_get_gpi (phy_if_14);
  instance pointer: phy_if_14  Outer instance pointer: phy_if_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  Starting walk at: ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  Starting walk at: ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  instance pointer: fci_ret_7(D)  Outer instance pointer: fci_ret_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  Starting walk at: ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  instance pointer: shp_cmd_12  Outer instance pointer: msg_6(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  Starting walk at: ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  instance pointer: gpi_16  Outer instance pointer: gpi_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_23 = policer_shp_cmd_action_update (fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  Starting walk at: ret_23 = policer_shp_cmd_action_update (fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  instance pointer: fci_ret_7(D)  Outer instance pointer: fci_ret_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_23 = policer_shp_cmd_action_update (fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  Starting walk at: ret_23 = policer_shp_cmd_action_update (fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  instance pointer: shp_cmd_12  Outer instance pointer: msg_6(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_23 = policer_shp_cmd_action_update (fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  Starting walk at: ret_23 = policer_shp_cmd_action_update (fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  instance pointer: gpi_16  Outer instance pointer: gpi_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: phy_if_14 = fci_get_phy_if_by_name (_1);
  Starting walk at: phy_if_14 = fci_get_phy_if_by_name (_1);
  instance pointer: _1  Outer instance pointer: msg_6(D) offset: 144 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: gpi_16 = fci_qos_get_gpi (phy_if_14);
  Starting walk at: gpi_16 = fci_qos_get_gpi (phy_if_14);
  instance pointer: phy_if_14  Outer instance pointer: phy_if_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  Starting walk at: ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  Starting walk at: ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  instance pointer: fci_ret_7(D)  Outer instance pointer: fci_ret_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  Starting walk at: ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  instance pointer: wred_cmd_12  Outer instance pointer: msg_6(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  Starting walk at: ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  instance pointer: gpi_16  Outer instance pointer: gpi_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: ret_23 = policer_wred_cmd_action_update (fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  Starting walk at: ret_23 = policer_wred_cmd_action_update (fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  instance pointer: fci_ret_7(D)  Outer instance pointer: fci_ret_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: ret_23 = policer_wred_cmd_action_update (fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  Starting walk at: ret_23 = policer_wred_cmd_action_update (fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  instance pointer: wred_cmd_12  Outer instance pointer: msg_6(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: ret_23 = policer_wred_cmd_action_update (fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  Starting walk at: ret_23 = policer_wred_cmd_action_update (fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  instance pointer: gpi_16  Outer instance pointer: gpi_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_16 = fci_qos_get_gpi (phy_if_14);
  Function call may change dynamic type:phy_if_14 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 32);
Determining dynamic type for call: ret_15 = wred_thr_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  Starting walk at: ret_15 = wred_thr_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  instance pointer: gpi_6(D)  Outer instance pointer: gpi_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_13 = pfe_gpi_wred_enable (gpi_6(D), queue_7(D));
Determining dynamic type for call: ret_15 = wred_thr_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  Starting walk at: ret_15 = wred_thr_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  instance pointer: wred_cmd_5(D)  Outer instance pointer: wred_cmd_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_13 = pfe_gpi_wred_enable (gpi_6(D), queue_7(D));
Determining dynamic type for call: ret_17 = wred_prob_zone_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  Starting walk at: ret_17 = wred_prob_zone_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  instance pointer: gpi_6(D)  Outer instance pointer: gpi_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_15 = wred_thr_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  Function call may change dynamic type:ret_13 = pfe_gpi_wred_enable (gpi_6(D), queue_7(D));
Determining dynamic type for call: ret_17 = wred_prob_zone_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  Starting walk at: ret_17 = wred_prob_zone_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  instance pointer: wred_cmd_5(D)  Outer instance pointer: wred_cmd_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_15 = wred_thr_set_reg (gpi_6(D), queue_7(D), wred_cmd_5(D));
  Function call may change dynamic type:ret_13 = pfe_gpi_wred_enable (gpi_6(D), queue_7(D));
Determining dynamic type for call: phy_if_21 = fci_get_phy_if_by_name (_1);
  Starting walk at: phy_if_21 = fci_get_phy_if_by_name (_1);
  instance pointer: _1  Outer instance pointer: msg_13(D) offset: 144 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: gpi_23 = fci_qos_get_gpi (phy_if_21);
  Starting walk at: gpi_23 = fci_qos_get_gpi (phy_if_21);
  instance pointer: phy_if_21  Outer instance pointer: phy_if_21 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _8);
  Starting walk at: fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _8);
  instance pointer: &gpi_flow  Outer instance pointer: gpi_flow offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_29 = pfe_gpi_qos_get_next_flow (gpi_23, _7, &gpi_flow);
  Function call may change dynamic type:autolibc_strncpy (_6, _1, 16);
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _8);
  Starting walk at: fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _8);
  instance pointer: _8  Outer instance pointer: reply_buf_15(D) offset: 160 (bits) vtbl reference: 
  Function call may change dynamic type:ret_29 = pfe_gpi_qos_get_next_flow (gpi_23, _7, &gpi_flow);
  Function call may change dynamic type:autolibc_strncpy (_6, _1, 16);
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _5);
  Starting walk at: fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _5);
  instance pointer: &gpi_flow  Outer instance pointer: gpi_flow offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_37 = pfe_gpi_qos_get_first_flow (gpi_23, _4, &gpi_flow);
  Function call may change dynamic type:autolibc_strncpy (_3, _1, 16);
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _5);
  Starting walk at: fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _5);
  instance pointer: _5  Outer instance pointer: reply_buf_15(D) offset: 160 (bits) vtbl reference: 
  Function call may change dynamic type:ret_37 = pfe_gpi_qos_get_first_flow (gpi_23, _4, &gpi_flow);
  Function call may change dynamic type:autolibc_strncpy (_3, _1, 16);
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: ret_42 = policer_flow_cmd_action_deregister.isra.0 (fci_ret_14(D), _50, gpi_23);
  Starting walk at: ret_42 = policer_flow_cmd_action_deregister.isra.0 (fci_ret_14(D), _50, gpi_23);
  instance pointer: fci_ret_14(D)  Outer instance pointer: fci_ret_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: ret_42 = policer_flow_cmd_action_deregister.isra.0 (fci_ret_14(D), _50, gpi_23);
  Starting walk at: ret_42 = policer_flow_cmd_action_deregister.isra.0 (fci_ret_14(D), _50, gpi_23);
  instance pointer: gpi_23  Outer instance pointer: gpi_23 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  Starting walk at: ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  instance pointer: fci_ret_14(D)  Outer instance pointer: fci_ret_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  Starting walk at: ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  instance pointer: flow_cmd_19  Outer instance pointer: msg_13(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  Starting walk at: ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  instance pointer: &gpi_flow  Outer instance pointer: gpi_flow offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  Starting walk at: ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  instance pointer: gpi_23  Outer instance pointer: gpi_23 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:gpi_23 = fci_qos_get_gpi (phy_if_21);
  Function call may change dynamic type:phy_if_21 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_15(D), 0, 56);
  Function call may change dynamic type:autolibc_memset (&gpi_flow, 0, 36);
Determining dynamic type for call: fci_qos_flow_entry_convert_to_gpi (_1, gpi_flow_6(D));
  Starting walk at: fci_qos_flow_entry_convert_to_gpi (_1, gpi_flow_6(D));
  instance pointer: _1  Outer instance pointer: flow_cmd_4(D) offset: 160 (bits) vtbl reference: 
Determining dynamic type for call: fci_qos_flow_entry_convert_to_gpi (_1, gpi_flow_6(D));
  Starting walk at: fci_qos_flow_entry_convert_to_gpi (_1, gpi_flow_6(D));
  instance pointer: gpi_flow_6(D)  Outer instance pointer: gpi_flow_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: phy_if_18 = fci_get_phy_if_by_name (_1);
  Starting walk at: phy_if_18 = fci_get_phy_if_by_name (_1);
  instance pointer: _1  Outer instance pointer: msg_11(D) offset: 144 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_13(D), 0, 20);
Determining dynamic type for call: gpi_20 = fci_qos_get_gpi (phy_if_18);
  Starting walk at: gpi_20 = fci_qos_get_gpi (phy_if_18);
  instance pointer: phy_if_18  Outer instance pointer: phy_if_18 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:phy_if_18 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:autolibc_memset (reply_buf_13(D), 0, 20);
Determining dynamic type for call: ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  Starting walk at: ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  Starting walk at: ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  instance pointer: fci_ret_12(D)  Outer instance pointer: fci_ret_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  Starting walk at: ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  instance pointer: &MEM[(void *)&context + 6508B]  Outer instance pointer: context offset: 52064 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  Starting walk at: ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  instance pointer: shp_11  Outer instance pointer: msg_10(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_19 = shaper_cmd_action_update (fci_ret_12(D), &context, shp_11);
  Starting walk at: ret_19 = shaper_cmd_action_update (fci_ret_12(D), &context, shp_11);
  instance pointer: fci_ret_12(D)  Outer instance pointer: fci_ret_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_19 = shaper_cmd_action_update (fci_ret_12(D), &context, shp_11);
  Starting walk at: ret_19 = shaper_cmd_action_update (fci_ret_12(D), &context, shp_11);
  instance pointer: &context  Outer instance pointer: context offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: ret_19 = shaper_cmd_action_update (fci_ret_12(D), &context, shp_11);
  Starting walk at: ret_19 = shaper_cmd_action_update (fci_ret_12(D), &context, shp_11);
  instance pointer: shp_11  Outer instance pointer: msg_10(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 36);
Determining dynamic type for call: phy_if_16 = fci_get_phy_if_by_name (_1);
  Starting walk at: phy_if_16 = fci_get_phy_if_by_name (_1);
  instance pointer: _1  Outer instance pointer: shp_13(D) offset: 16 (bits) vtbl reference: 
Determining dynamic type for call: ret_24 = set_shaper_cmd_props.isra.0 (fci_ret_22(D), _33, shp_13(D), phy_if_16);
  Starting walk at: ret_24 = set_shaper_cmd_props.isra.0 (fci_ret_22(D), _33, shp_13(D), phy_if_16);
  instance pointer: fci_ret_22(D)  Outer instance pointer: fci_ret_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_21 = pfe_tmu_shp_enable (_6, _7, _8);
  Function call may change dynamic type:ret_19 = pfe_tmu_check_shaper (_3, _2, _4);
  Function call may change dynamic type:phy_if_16 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_24 = set_shaper_cmd_props.isra.0 (fci_ret_22(D), _33, shp_13(D), phy_if_16);
  Starting walk at: ret_24 = set_shaper_cmd_props.isra.0 (fci_ret_22(D), _33, shp_13(D), phy_if_16);
  instance pointer: _33  Outer instance pointer: fci_17(D) offset: 52064 (bits) vtbl reference: 
  Function call may change dynamic type:ret_21 = pfe_tmu_shp_enable (_6, _7, _8);
  Function call may change dynamic type:ret_19 = pfe_tmu_check_shaper (_3, _2, _4);
  Function call may change dynamic type:phy_if_16 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_24 = set_shaper_cmd_props.isra.0 (fci_ret_22(D), _33, shp_13(D), phy_if_16);
  Starting walk at: ret_24 = set_shaper_cmd_props.isra.0 (fci_ret_22(D), _33, shp_13(D), phy_if_16);
  instance pointer: shp_13(D)  Outer instance pointer: shp_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_21 = pfe_tmu_shp_enable (_6, _7, _8);
  Function call may change dynamic type:ret_19 = pfe_tmu_check_shaper (_3, _2, _4);
  Function call may change dynamic type:phy_if_16 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_24 = set_shaper_cmd_props.isra.0 (fci_ret_22(D), _33, shp_13(D), phy_if_16);
  Starting walk at: ret_24 = set_shaper_cmd_props.isra.0 (fci_ret_22(D), _33, shp_13(D), phy_if_16);
  instance pointer: phy_if_16  Outer instance pointer: phy_if_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_21 = pfe_tmu_shp_enable (_6, _7, _8);
  Function call may change dynamic type:ret_19 = pfe_tmu_check_shaper (_3, _2, _4);
  Function call may change dynamic type:phy_if_16 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: shaper_disconnect_and_disable.isra.0 (fci_ret_22(D), _32, shp_13(D), phy_if_16);
  Starting walk at: shaper_disconnect_and_disable.isra.0 (fci_ret_22(D), _32, shp_13(D), phy_if_16);
  instance pointer: fci_ret_22(D)  Outer instance pointer: fci_ret_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_19 = pfe_tmu_check_shaper (_3, _2, _4);
  Function call may change dynamic type:phy_if_16 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: shaper_disconnect_and_disable.isra.0 (fci_ret_22(D), _32, shp_13(D), phy_if_16);
  Starting walk at: shaper_disconnect_and_disable.isra.0 (fci_ret_22(D), _32, shp_13(D), phy_if_16);
  instance pointer: _32  Outer instance pointer: fci_17(D) offset: 52064 (bits) vtbl reference: 
  Function call may change dynamic type:ret_19 = pfe_tmu_check_shaper (_3, _2, _4);
  Function call may change dynamic type:phy_if_16 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: shaper_disconnect_and_disable.isra.0 (fci_ret_22(D), _32, shp_13(D), phy_if_16);
  Starting walk at: shaper_disconnect_and_disable.isra.0 (fci_ret_22(D), _32, shp_13(D), phy_if_16);
  instance pointer: shp_13(D)  Outer instance pointer: shp_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_19 = pfe_tmu_check_shaper (_3, _2, _4);
  Function call may change dynamic type:phy_if_16 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: shaper_disconnect_and_disable.isra.0 (fci_ret_22(D), _32, shp_13(D), phy_if_16);
  Starting walk at: shaper_disconnect_and_disable.isra.0 (fci_ret_22(D), _32, shp_13(D), phy_if_16);
  instance pointer: phy_if_16  Outer instance pointer: phy_if_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_19 = pfe_tmu_check_shaper (_3, _2, _4);
  Function call may change dynamic type:phy_if_16 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  Starting walk at: ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 188);
Determining dynamic type for call: ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  Starting walk at: ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  instance pointer: fci_ret_12(D)  Outer instance pointer: fci_ret_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 188);
Determining dynamic type for call: ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  Starting walk at: ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  instance pointer: &context  Outer instance pointer: context offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 188);
Determining dynamic type for call: ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  Starting walk at: ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  instance pointer: sch_11  Outer instance pointer: msg_10(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 188);
Determining dynamic type for call: ret_19 = scheduler_cmd_action_update (fci_ret_12(D), &context, sch_11);
  Starting walk at: ret_19 = scheduler_cmd_action_update (fci_ret_12(D), &context, sch_11);
  instance pointer: fci_ret_12(D)  Outer instance pointer: fci_ret_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 188);
Determining dynamic type for call: ret_19 = scheduler_cmd_action_update (fci_ret_12(D), &context, sch_11);
  Starting walk at: ret_19 = scheduler_cmd_action_update (fci_ret_12(D), &context, sch_11);
  instance pointer: &context  Outer instance pointer: context offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 188);
Determining dynamic type for call: ret_19 = scheduler_cmd_action_update (fci_ret_12(D), &context, sch_11);
  Starting walk at: ret_19 = scheduler_cmd_action_update (fci_ret_12(D), &context, sch_11);
  instance pointer: sch_11  Outer instance pointer: msg_10(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 188);
Determining dynamic type for call: phy_if_17 = fci_get_phy_if_by_name (_1);
  Starting walk at: phy_if_17 = fci_get_phy_if_by_name (_1);
  instance pointer: _1  Outer instance pointer: sch_14(D) offset: 16 (bits) vtbl reference: 
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  instance pointer: _29  Outer instance pointer: fci_18(D) offset: 52064 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_strncpy (_10, _1, 16);
  Function call may change dynamic type:ret_20 = pfe_tmu_check_scheduler (_3, _4, _5);
  Function call may change dynamic type:phy_if_17 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  instance pointer: _30  Outer instance pointer: sch_14(D) offset: 144 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_strncpy (_10, _1, 16);
  Function call may change dynamic type:ret_20 = pfe_tmu_check_scheduler (_3, _4, _5);
  Function call may change dynamic type:phy_if_17 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  instance pointer: &fci_ret  Outer instance pointer: fci_ret offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_strncpy (_10, _1, 16);
  Function call may change dynamic type:ret_20 = pfe_tmu_check_scheduler (_3, _4, _5);
  Function call may change dynamic type:phy_if_17 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  instance pointer: &reply_buf  Outer instance pointer: reply_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_strncpy (_10, _1, 16);
  Function call may change dynamic type:ret_20 = pfe_tmu_check_scheduler (_3, _4, _5);
  Function call may change dynamic type:phy_if_17 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_query_get_sch.isra.0 (_29, _30, &fci_ret, &reply_buf, phy_if_17);
  instance pointer: phy_if_17  Outer instance pointer: phy_if_17 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_strncpy (_10, _1, 16);
  Function call may change dynamic type:ret_20 = pfe_tmu_check_scheduler (_3, _4, _5);
  Function call may change dynamic type:phy_if_17 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: phy_if_19 = fci_get_phy_if_by_name (_2);
  Starting walk at: phy_if_19 = fci_get_phy_if_by_name (_2);
  instance pointer: _2  Outer instance pointer: sch.6_1 offset: 16 (bits) vtbl reference: 
Determining dynamic type for call: ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Starting walk at: ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  instance pointer: _30  Outer instance pointer: fci_20(D) offset: 52064 (bits) vtbl reference: 
  Function call may change dynamic type:ret_22 = pfe_tmu_check_scheduler (_4, _5, _7);
  Function call may change dynamic type:phy_if_19 = fci_get_phy_if_by_name (_2);
Determining dynamic type for call: ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Starting walk at: ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  instance pointer: &sch  Outer instance pointer: sch offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_22 = pfe_tmu_check_scheduler (_4, _5, _7);
  Function call may change dynamic type:phy_if_19 = fci_get_phy_if_by_name (_2);
Determining dynamic type for call: ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Starting walk at: ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  instance pointer: &fci_ret  Outer instance pointer: fci_ret offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_22 = pfe_tmu_check_scheduler (_4, _5, _7);
  Function call may change dynamic type:phy_if_19 = fci_get_phy_if_by_name (_2);
Determining dynamic type for call: ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Starting walk at: ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  instance pointer: phy_if_19  Outer instance pointer: phy_if_19 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_22 = pfe_tmu_check_scheduler (_4, _5, _7);
  Function call may change dynamic type:phy_if_19 = fci_get_phy_if_by_name (_2);
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  instance pointer: _30  Outer instance pointer: fci_20(D) offset: 52064 (bits) vtbl reference: 
  Function call may change dynamic type:ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Function call may change dynamic type:ret_22 = pfe_tmu_check_scheduler (_4, _5, _7);
  Function call may change dynamic type:phy_if_19 = fci_get_phy_if_by_name (_2);
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  instance pointer: &sch  Outer instance pointer: sch offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Function call may change dynamic type:ret_22 = pfe_tmu_check_scheduler (_4, _5, _7);
  Function call may change dynamic type:phy_if_19 = fci_get_phy_if_by_name (_2);
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  instance pointer: &fci_ret  Outer instance pointer: fci_ret offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Function call may change dynamic type:ret_22 = pfe_tmu_check_scheduler (_4, _5, _7);
  Function call may change dynamic type:phy_if_19 = fci_get_phy_if_by_name (_2);
Determining dynamic type for call: ret_26 = fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Starting walk at: ret_26 = fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  instance pointer: phy_if_19  Outer instance pointer: phy_if_19 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_24 = fci_qos_scheduler_cmd_update_set_mode.isra.0 (_30, &sch, &fci_ret, phy_if_19);
  Function call may change dynamic type:ret_22 = pfe_tmu_check_scheduler (_4, _5, _7);
  Function call may change dynamic type:phy_if_19 = fci_get_phy_if_by_name (_2);
Determining dynamic type for call: ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  Starting walk at: ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 60);
Determining dynamic type for call: ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  Starting walk at: ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  instance pointer: fci_ret_12(D)  Outer instance pointer: fci_ret_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 60);
Determining dynamic type for call: ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  Starting walk at: ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  instance pointer: q_11  Outer instance pointer: msg_10(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 60);
Determining dynamic type for call: ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  Starting walk at: ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  instance pointer: &context  Outer instance pointer: context offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 60);
Determining dynamic type for call: ret_19 = qos_queue_cmd_action_update (fci_ret_12(D), q_11, &context);
  Starting walk at: ret_19 = qos_queue_cmd_action_update (fci_ret_12(D), q_11, &context);
  instance pointer: fci_ret_12(D)  Outer instance pointer: fci_ret_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 60);
Determining dynamic type for call: ret_19 = qos_queue_cmd_action_update (fci_ret_12(D), q_11, &context);
  Starting walk at: ret_19 = qos_queue_cmd_action_update (fci_ret_12(D), q_11, &context);
  instance pointer: q_11  Outer instance pointer: msg_10(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 60);
Determining dynamic type for call: ret_19 = qos_queue_cmd_action_update (fci_ret_12(D), q_11, &context);
  Starting walk at: ret_19 = qos_queue_cmd_action_update (fci_ret_12(D), q_11, &context);
  instance pointer: &context  Outer instance pointer: context offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_8(D), 0, 60);
Determining dynamic type for call: phy_if_61 = fci_get_phy_if_by_name (_1);
  Starting walk at: phy_if_61 = fci_get_phy_if_by_name (_1);
  instance pointer: _1  Outer instance pointer: q_58(D) offset: 16 (bits) vtbl reference: 
Determining dynamic type for call: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  Starting walk at: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  instance pointer: reply_buf_65(D)  Outer instance pointer: reply_buf_65(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = pfe_tmu_queue_get_mode (_8, _9, _10, _11, _12);
  Function call may change dynamic type:autolibc_strncpy (_7, _1, 16);
  Function call may change dynamic type:ret_64 = pfe_tmu_check_queue (_2, _3, _4);
  Function call may change dynamic type:phy_if_61 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  Starting walk at: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  instance pointer: fci_ret_76(D)  Outer instance pointer: fci_ret_76(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = pfe_tmu_queue_get_mode (_8, _9, _10, _11, _12);
  Function call may change dynamic type:autolibc_strncpy (_7, _1, 16);
  Function call may change dynamic type:ret_64 = pfe_tmu_check_queue (_2, _3, _4);
  Function call may change dynamic type:phy_if_61 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  Starting walk at: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  instance pointer: _90  Outer instance pointer: q_58(D) offset: 144 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = pfe_tmu_queue_get_mode (_8, _9, _10, _11, _12);
  Function call may change dynamic type:autolibc_strncpy (_7, _1, 16);
  Function call may change dynamic type:ret_64 = pfe_tmu_check_queue (_2, _3, _4);
  Function call may change dynamic type:phy_if_61 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  Starting walk at: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  instance pointer: _91  Outer instance pointer: fci_62(D) offset: 52064 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = pfe_tmu_queue_get_mode (_8, _9, _10, _11, _12);
  Function call may change dynamic type:autolibc_strncpy (_7, _1, 16);
  Function call may change dynamic type:ret_64 = pfe_tmu_check_queue (_2, _3, _4);
  Function call may change dynamic type:phy_if_61 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  Starting walk at: ret_78 = get_wred_zone_probs.isra.0 (reply_buf_65(D), fci_ret_76(D), _90, _91, phy_if_61);
  instance pointer: phy_if_61  Outer instance pointer: phy_if_61 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = pfe_tmu_queue_get_mode (_8, _9, _10, _11, _12);
  Function call may change dynamic type:autolibc_strncpy (_7, _1, 16);
  Function call may change dynamic type:ret_64 = pfe_tmu_check_queue (_2, _3, _4);
  Function call may change dynamic type:phy_if_61 = fci_get_phy_if_by_name (_1);
Determining dynamic type for call: phy_if_39 = fci_get_phy_if_by_name (_1);
  Starting walk at: phy_if_39 = fci_get_phy_if_by_name (_1);
  instance pointer: _1  Outer instance pointer: q_36(D) offset: 16 (bits) vtbl reference: 
Determining dynamic type for call: ret_49 = queue_mode_wred.isra.0 (fci_ret_47(D), q_36(D), _56, phy_if_39);
  Starting walk at: ret_49 = queue_mode_wred.isra.0 (fci_ret_47(D), q_36(D), _56, phy_if_39);
  instance pointer: fci_ret_47(D)  Outer instance pointer: fci_ret_47(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_46 = pfe_tmu_queue_set_mode (_6, _7, _4, 0, 0, 0);
  Function call may change dynamic type:cnt_42 = pfe_tmu_queue_get_cnt (_3, _2);
  Function call may change dynamic type:phy_if_39 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:ret_44 = pfe_tmu_queue_set_mode (_8, _9, _4, _11, _21, _31);
Determining dynamic type for call: ret_49 = queue_mode_wred.isra.0 (fci_ret_47(D), q_36(D), _56, phy_if_39);
  Starting walk at: ret_49 = queue_mode_wred.isra.0 (fci_ret_47(D), q_36(D), _56, phy_if_39);
  instance pointer: q_36(D)  Outer instance pointer: q_36(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_46 = pfe_tmu_queue_set_mode (_6, _7, _4, 0, 0, 0);
  Function call may change dynamic type:cnt_42 = pfe_tmu_queue_get_cnt (_3, _2);
  Function call may change dynamic type:phy_if_39 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:ret_44 = pfe_tmu_queue_set_mode (_8, _9, _4, _11, _21, _31);
Determining dynamic type for call: ret_49 = queue_mode_wred.isra.0 (fci_ret_47(D), q_36(D), _56, phy_if_39);
  Starting walk at: ret_49 = queue_mode_wred.isra.0 (fci_ret_47(D), q_36(D), _56, phy_if_39);
  instance pointer: _56  Outer instance pointer: fci_40(D) offset: 52064 (bits) vtbl reference: 
  Function call may change dynamic type:ret_46 = pfe_tmu_queue_set_mode (_6, _7, _4, 0, 0, 0);
  Function call may change dynamic type:cnt_42 = pfe_tmu_queue_get_cnt (_3, _2);
  Function call may change dynamic type:phy_if_39 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:ret_44 = pfe_tmu_queue_set_mode (_8, _9, _4, _11, _21, _31);
Determining dynamic type for call: ret_49 = queue_mode_wred.isra.0 (fci_ret_47(D), q_36(D), _56, phy_if_39);
  Starting walk at: ret_49 = queue_mode_wred.isra.0 (fci_ret_47(D), q_36(D), _56, phy_if_39);
  instance pointer: phy_if_39  Outer instance pointer: phy_if_39 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_46 = pfe_tmu_queue_set_mode (_6, _7, _4, 0, 0, 0);
  Function call may change dynamic type:cnt_42 = pfe_tmu_queue_get_cnt (_3, _2);
  Function call may change dynamic type:phy_if_39 = fci_get_phy_if_by_name (_1);
  Function call may change dynamic type:ret_44 = pfe_tmu_queue_set_mode (_8, _9, _4, _11, _21, _31);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  policer_flow_cmd_action_deregister.isra.0/129:
  Jump functions of caller  shaper_cmd_action_query.isra.0/128:
    callsite  shaper_cmd_action_query.isra.0/128 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  set_shaper_cmd_props.isra.0/127:
  Jump functions of caller  shaper_disconnect_and_disable.isra.0/126:
  Jump functions of caller  fci_qos_scheduler_cmd_query_get_sch.isra.0/125:
  Jump functions of caller  fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124:
    callsite  fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 -> check_scheduler_input.isra.0/119 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  fci_qos_scheduler_cmd_update_set_mode.isra.0/123:
  Jump functions of caller  get_wred_zone_probs.isra.0/122:
  Jump functions of caller  queue_mode_wred.isra.0/121:
  Jump functions of caller  check_scheduler_input.isra.0/119:
  Jump functions of caller  pfe_gpi_shp_get_limits/118:
  Jump functions of caller  pfe_gpi_shp_get_idle_slope/117:
  Jump functions of caller  pfe_gpi_shp_get_mode/116:
  Jump functions of caller  pfe_gpi_shp_get_type/115:
  Jump functions of caller  pfe_gpi_shp_is_enabled/114:
  Jump functions of caller  pfe_gpi_shp_set_limits/113:
  Jump functions of caller  pfe_gpi_shp_set_idle_slope/112:
  Jump functions of caller  pfe_gpi_shp_set_mode/111:
  Jump functions of caller  pfe_gpi_shp_set_type/110:
  Jump functions of caller  pfe_gpi_shp_disable/109:
  Jump functions of caller  pfe_gpi_shp_enable/108:
  Jump functions of caller  pfe_gpi_wred_get_prob/107:
  Jump functions of caller  pfe_gpi_wred_get_thr/106:
  Jump functions of caller  pfe_gpi_wred_is_enabled/105:
  Jump functions of caller  pfe_gpi_wred_set_prob/104:
  Jump functions of caller  pfe_gpi_wred_set_thr/103:
  Jump functions of caller  pfe_gpi_wred_disable/102:
  Jump functions of caller  pfe_gpi_wred_enable/101:
  Jump functions of caller  pfe_gpi_qos_rem_flow/100:
  Jump functions of caller  pfe_gpi_qos_add_flow/99:
  Jump functions of caller  pfe_gpi_qos_get_next_flow/98:
  Jump functions of caller  pfe_gpi_qos_get_first_flow/97:
  Jump functions of caller  pfe_emac_get_gpi/96:
  Jump functions of caller  pfe_phy_if_get_emac/95:
  Jump functions of caller  pfe_gpi_qos_is_enabled/94:
  Jump functions of caller  pfe_gpi_qos_disable/93:
  Jump functions of caller  pfe_gpi_qos_enable/92:
  Jump functions of caller  pfe_tmu_shp_get_position/91:
  Jump functions of caller  pfe_tmu_shp_get_idle_slope/90:
  Jump functions of caller  pfe_tmu_shp_get_limits/89:
  Jump functions of caller  pfe_tmu_shp_get_rate_mode/88:
  Jump functions of caller  pfe_tmu_shp_set_idle_slope/87:
  Jump functions of caller  pfe_tmu_shp_set_limits/86:
  Jump functions of caller  pfe_tmu_shp_set_rate_mode/85:
  Jump functions of caller  pfe_tmu_shp_disable/84:
  Jump functions of caller  pfe_tmu_shp_set_position/83:
  Jump functions of caller  pfe_tmu_shp_enable/82:
  Jump functions of caller  pfe_tmu_check_shaper/81:
  Jump functions of caller  pfe_tmu_sch_get_input_weight/80:
  Jump functions of caller  pfe_tmu_sch_get_bound_sch_output/79:
  Jump functions of caller  pfe_tmu_sch_get_bound_queue/78:
  Jump functions of caller  pfe_tmu_sch_get_algo/77:
  Jump functions of caller  pfe_tmu_sch_get_rate_mode/76:
  Jump functions of caller  pfe_tmu_sch_set_input_weight/75:
  Jump functions of caller  pfe_tmu_sch_bind_sch_output/74:
  Jump functions of caller  pfe_tmu_sch_bind_queue/73:
  Jump functions of caller  pfe_tmu_sch_get_input_cnt/72:
  Jump functions of caller  pfe_tmu_sch_set_algo/71:
  Jump functions of caller  pfe_tmu_sch_set_rate_mode/70:
  Jump functions of caller  pfe_tmu_check_scheduler/69:
  Jump functions of caller  pfe_tmu_queue_get_wred_prob/68:
  Jump functions of caller  pfe_tmu_queue_get_wred_zones/67:
  Jump functions of caller  pfe_tmu_queue_get_mode/66:
  Jump functions of caller  autolibc_strncpy/65:
  Jump functions of caller  pfe_tmu_check_queue/64:
  Jump functions of caller  pfe_tmu_queue_set_wred_prob/63:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/62:
  Jump functions of caller  pfe_hm_report/61:
  Jump functions of caller  pfe_if_db_unlock/60:
  Jump functions of caller  pfe_if_db_entry_get_phy_if/59:
  Jump functions of caller  pfe_if_db_get_first/58:
  Jump functions of caller  pfe_if_db_lock/57:
  Jump functions of caller  pfe_tmu_queue_set_mode/56:
  Jump functions of caller  pfe_tmu_queue_get_cnt/55:
  Jump functions of caller  pfe_phy_if_get_id/54:
  Jump functions of caller  autolibc_memset/53:
  Jump functions of caller  fci_qos_policer_shp_cmd/51:
    callsite  fci_qos_policer_shp_cmd/51 -> policer_shp_cmd_action_query/50 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  fci_qos_policer_shp_cmd/51 -> policer_shp_cmd_action_update/49 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  fci_qos_policer_shp_cmd/51 -> fci_qos_get_gpi/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_qos_policer_shp_cmd/51 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  policer_shp_cmd_action_query/50:
  Jump functions of caller  policer_shp_cmd_action_update/49:
  Jump functions of caller  fci_qos_policer_wred_cmd/48:
    callsite  fci_qos_policer_wred_cmd/48 -> policer_wred_cmd_action_query/47 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  fci_qos_policer_wred_cmd/48 -> policer_wred_cmd_action_update/46 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  fci_qos_policer_wred_cmd/48 -> fci_qos_get_gpi/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_qos_policer_wred_cmd/48 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  policer_wred_cmd_action_query/47:
  Jump functions of caller  policer_wred_cmd_action_update/46:
    callsite  policer_wred_cmd_action_update/46 -> wred_prob_zone_set_reg/45 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  policer_wred_cmd_action_update/46 -> wred_thr_set_reg/44 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  wred_prob_zone_set_reg/45:
  Jump functions of caller  wred_thr_set_reg/44:
  Jump functions of caller  fci_qos_policer_flow_cmd/43:
    callsite  fci_qos_policer_flow_cmd/43 -> fci_qos_flow_entry_convert_from_gpi/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: ANCESTOR: 2, offset 160
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  fci_qos_policer_flow_cmd/43 -> fci_qos_flow_entry_convert_from_gpi/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: ANCESTOR: 2, offset 160
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  fci_qos_policer_flow_cmd/43 -> policer_flow_cmd_action_deregister.isra.0/129 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_qos_policer_flow_cmd/43 -> policer_flow_cmd_action_register/41 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_qos_policer_flow_cmd/43 -> fci_qos_get_gpi/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_qos_policer_flow_cmd/43 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  policer_flow_cmd_action_register/41:
    callsite  policer_flow_cmd_action_register/41 -> fci_qos_flow_entry_convert_to_gpi/39 : 
       param 0: ANCESTOR: 1, offset 160, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_qos_flow_entry_convert_from_gpi/40:
  Jump functions of caller  fci_qos_flow_entry_convert_to_gpi/39:
  Jump functions of caller  fci_qos_policer_cmd/38:
    callsite  fci_qos_policer_cmd/38 -> fci_qos_get_gpi/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_qos_policer_cmd/38 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  fci_qos_get_gpi/36:
  Jump functions of caller  fci_qos_shaper_cmd/35:
    callsite  fci_qos_shaper_cmd/35 -> shaper_cmd_action_query.isra.0/128 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: &MEM[(void *)&context + 6508B]
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  fci_qos_shaper_cmd/35 -> shaper_cmd_action_update/33 : 
       param 0: PASS THROUGH: 1, op nop_expr
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  shaper_cmd_action_update/33:
    callsite  shaper_cmd_action_update/33 -> set_shaper_cmd_props.isra.0/127 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  shaper_cmd_action_update/33 -> shaper_disconnect_and_disable.isra.0/126 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  shaper_cmd_action_update/33 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  fci_qos_scheduler_cmd/30:
    callsite  fci_qos_scheduler_cmd/30 -> scheduler_cmd_action_query/29 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  fci_qos_scheduler_cmd/30 -> scheduler_cmd_action_update/28 : 
       param 0: PASS THROUGH: 1, op nop_expr
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  scheduler_cmd_action_query/29:
    callsite  scheduler_cmd_action_query/29 -> fci_qos_scheduler_cmd_query_get_sch.isra.0/125 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  scheduler_cmd_action_query/29 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  scheduler_cmd_action_update/28:
    callsite  scheduler_cmd_action_update/28 -> fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  scheduler_cmd_action_update/28 -> fci_qos_scheduler_cmd_update_set_mode.isra.0/123 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  scheduler_cmd_action_update/28 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  fci_qos_queue_cmd/23:
    callsite  fci_qos_queue_cmd/23 -> qos_queue_cmd_action_query/22 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_qos_queue_cmd/23 -> qos_queue_cmd_action_update/20 : 
       param 0: PASS THROUGH: 1, op nop_expr
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  qos_queue_cmd_action_query/22:
    callsite  qos_queue_cmd_action_query/22 -> get_wred_zone_probs.isra.0/122 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 152, cst: 3
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  qos_queue_cmd_action_query/22 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  qos_queue_cmd_action_update/20:
    callsite  qos_queue_cmd_action_update/20 -> queue_mode_wred.isra.0/121 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  qos_queue_cmd_action_update/20 -> fci_get_phy_if_by_name/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  fci_get_phy_if_by_name/18:

 Propagating constants:

Not considering fci_qos_policer_shp_cmd for cloning; -fipa-cp-clone disabled.
Not considering fci_qos_policer_wred_cmd for cloning; -fipa-cp-clone disabled.
Not considering fci_qos_policer_flow_cmd for cloning; -fipa-cp-clone disabled.
Not considering fci_qos_policer_cmd for cloning; -fipa-cp-clone disabled.
Not considering fci_qos_shaper_cmd for cloning; -fipa-cp-clone disabled.
Not considering fci_qos_scheduler_cmd for cloning; -fipa-cp-clone disabled.
Not considering fci_qos_queue_cmd for cloning; -fipa-cp-clone disabled.

overall_size: 2012, max_new_size: 11001
 - context independent values, size: 128, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 63, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 41, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 52, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 122, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 86, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: policer_flow_cmd_action_deregister.isra.0/129:
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
  Node: shaper_cmd_action_query.isra.0/128:
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
    param [2]: &MEM[(void *)&context + 6508B] [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_tmu_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_shaper_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: set_shaper_cmd_props.isra.0/127:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_tmu_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_shaper_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: shaper_disconnect_and_disable.isra.0/126:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_tmu_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_shaper_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fci_qos_scheduler_cmd_query_get_sch.isra.0/125:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_tmu_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         uint8_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fpp_qos_scheduler_cmd_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_tmu_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fpp_qos_scheduler_cmd_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fci_qos_scheduler_cmd_update_set_mode.isra.0/123:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_tmu_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fpp_qos_scheduler_cmd_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: get_wred_zone_probs.isra.0/122:
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
         uint8_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_tmu_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: queue_mode_wred.isra.0/121:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_queue_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_tmu_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: check_scheduler_input.isra.0/119:
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
  Node: fci_qos_policer_shp_cmd/51:
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
  Node: policer_shp_cmd_action_query/50:
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
         struct fpp_qos_policer_shp_cmd_t * ~[0B, 0B]
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
  Node: policer_shp_cmd_action_update/49:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_policer_shp_cmd_t * ~[0B, 0B]
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
  Node: fci_qos_policer_wred_cmd/48:
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
  Node: policer_wred_cmd_action_query/47:
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
         struct fpp_qos_policer_wred_cmd_t * ~[0B, 0B]
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
  Node: policer_wred_cmd_action_update/46:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_policer_wred_cmd_t * ~[0B, 0B]
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
  Node: wred_prob_zone_set_reg/45:
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
         struct fpp_qos_policer_wred_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: wred_thr_set_reg/44:
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
         struct fpp_qos_policer_wred_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_qos_policer_flow_cmd/43:
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
  Node: policer_flow_cmd_action_register/41:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_policer_flow_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_iqos_flow_spec_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fci_qos_flow_entry_convert_from_gpi/40:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_iqos_flow_spec_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_iqos_flow_spec_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_qos_flow_entry_convert_to_gpi/39:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_iqos_flow_spec_t * ~[0B, 0B]
        AGGS BOTTOM
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_iqos_flow_spec_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_qos_policer_cmd/38:
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
  Node: fci_qos_get_gpi/36:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fci_qos_shaper_cmd/35:
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
  Node: shaper_cmd_action_update/33:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct fci_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_shaper_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_qos_scheduler_cmd/30:
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
  Node: scheduler_cmd_action_query/29:
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
    param [2]: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct fci_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_scheduler_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: scheduler_cmd_action_update/28:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct fci_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_scheduler_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_qos_queue_cmd/23:
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
  Node: qos_queue_cmd_action_query/22:
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
         struct fpp_qos_queue_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct fci_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: qos_queue_cmd_action_update/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_qos_queue_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct fci_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_get_phy_if_by_name/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of shaper_cmd_action_query.isra.0/128 for all known contexts.
    replacing param #2 ISRA.76 with const &MEM[(void *)&context + 6508B]
 - Creating a specialized node of shaper_cmd_action_update/33 for all known contexts.
    replacing param #1 fci with const &context
 - Creating a specialized node of scheduler_cmd_action_query/29 for all known contexts.
    replacing param #2 fci with const &context
 - Creating a specialized node of scheduler_cmd_action_update/28 for all known contexts.
    replacing param #1 fci with const &context
 - Creating a specialized node of qos_queue_cmd_action_query/22 for all known contexts.
    replacing param #3 fci with const &context
 - Creating a specialized node of qos_queue_cmd_action_update/20 for all known contexts.
    replacing param #2 fci with const &context
Propagated bits info for function qos_queue_cmd_action_update.constprop/138:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function qos_queue_cmd_action_query.constprop/137:
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function scheduler_cmd_action_update.constprop/136:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function scheduler_cmd_action_query.constprop/135:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function shaper_cmd_action_update.constprop/134:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function shaper_cmd_action_query.isra.0.constprop/133:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function shaper_cmd_action_query.isra.0/128:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_qos_scheduler_cmd_query_get_sch.isra.0/125:
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_qos_scheduler_cmd_update_set_mode.isra.0/123:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function policer_flow_cmd_action_register/41:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_qos_flow_entry_convert_from_gpi/40:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_qos_flow_entry_convert_to_gpi/39:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function shaper_cmd_action_update/33:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function scheduler_cmd_action_query/29:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function scheduler_cmd_action_update/28:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function qos_queue_cmd_action_query/22:
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function qos_queue_cmd_action_update/20:
 param 2: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: shaper_cmd_action_query.isra.0/128 shaper_cmd_action_update/33 scheduler_cmd_action_query/29 scheduler_cmd_action_update/28 qos_queue_cmd_action_query/22 qos_queue_cmd_action_update/20
Reclaiming variables:
Clearing address taken flags:
Symbol table:

qos_queue_cmd_action_update.constprop.0/138 (qos_queue_cmd_action_update.constprop) @07930620
  Type: function definition analyzed
  Visibility:
  References: fci_qmode_to_qmode/16 (read)context/52 (addr)
  Referring: 
  Clone of qos_queue_cmd_action_update/20
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: fci_qos_queue_cmd/23 (170958392 (estimated locally),0.16 per call) 
  Calls: fci_get_phy_if_by_name/18 (1073741823 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (751619277 (estimated locally),0.70 per call) pfe_tmu_queue_get_cnt/55 (367391502 (estimated locally),0.34 per call) pfe_phy_if_get_id/54 (45923938 (estimated locally),0.04 per call) pfe_tmu_queue_set_mode/56 (45923938 (estimated locally),0.04 per call) pfe_phy_if_get_id/54 (45923938 (estimated locally),0.04 per call) pfe_tmu_queue_set_mode/56 (45923938 (estimated locally),0.04 per call) queue_mode_wred.isra.0/121 (30309799 (estimated locally),0.03 per call) 
qos_queue_cmd_action_query.constprop.0/137 (qos_queue_cmd_action_query.constprop) @07930b60
  Type: function definition analyzed
  Visibility:
  References: context/52 (addr)
  Referring: 
  Clone of qos_queue_cmd_action_query/22
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: fci_qos_queue_cmd/23 (170958392 (estimated locally),0.16 per call) 
  Calls: fci_get_phy_if_by_name/18 (1073741824 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (574129754 (estimated locally),0.53 per call) pfe_tmu_check_queue/64 (574129754 (estimated locally),0.53 per call) autolibc_strncpy/65 (189462818 (estimated locally),0.18 per call) pfe_phy_if_get_id/54 (189462818 (estimated locally),0.18 per call) pfe_tmu_queue_get_mode/66 (189462818 (estimated locally),0.18 per call) get_wred_zone_probs.isra.0/122 (47365705 (estimated locally),0.04 per call) pfe_hm_report/61 (47365705 (estimated locally),0.04 per call) oal_util_raise_dem_for_drv_runtime_err/62 (47365705 (estimated locally),0.04 per call) 
scheduler_cmd_action_update.constprop.0/136 (scheduler_cmd_action_update.constprop) @079307e0
  Type: function definition analyzed
  Visibility:
  References: context/52 (addr)
  Referring: 
  Clone of scheduler_cmd_action_update/28
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: fci_qos_scheduler_cmd/30 (170958392 (estimated locally),0.16 per call) 
  Calls: fci_get_phy_if_by_name/18 (1073741824 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (574129754 (estimated locally),0.53 per call) pfe_tmu_check_scheduler/69 (574129754 (estimated locally),0.53 per call) pfe_phy_if_get_id/54 (287064877 (estimated locally),0.27 per call) fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (62522730 (estimated locally),0.06 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (20632501 (estimated locally),0.02 per call) 
scheduler_cmd_action_query.constprop.0/135 (scheduler_cmd_action_query.constprop) @07930540
  Type: function definition analyzed
  Visibility:
  References: context/52 (addr)
  Referring: 
  Clone of scheduler_cmd_action_query/29
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: fci_qos_scheduler_cmd/30 (170958392 (estimated locally),0.16 per call) 
  Calls: fci_get_phy_if_by_name/18 (1073741824 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (574129754 (estimated locally),0.53 per call) pfe_tmu_check_scheduler/69 (574129754 (estimated locally),0.53 per call) autolibc_strncpy/65 (189462818 (estimated locally),0.18 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (189462818 (estimated locally),0.18 per call) 
shaper_cmd_action_update.constprop.0/134 (shaper_cmd_action_update.constprop) @07906ee0
  Type: function definition analyzed
  Visibility:
  References: context/52 (addr)
  Referring: 
  Clone of shaper_cmd_action_update/33
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: fci_qos_shaper_cmd/35 (170958392 (estimated locally),0.16 per call) 
  Calls: fci_get_phy_if_by_name/18 (1073741823 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (751619277 (estimated locally),0.70 per call) pfe_tmu_check_shaper/81 (367391502 (estimated locally),0.34 per call) shaper_disconnect_and_disable.isra.0/126 (91847875 (estimated locally),0.09 per call) pfe_phy_if_get_id/54 (91847875 (estimated locally),0.09 per call) pfe_tmu_shp_enable/82 (91847875 (estimated locally),0.09 per call) pfe_hm_report/61 (45923938 (estimated locally),0.04 per call) oal_util_raise_dem_for_drv_runtime_err/62 (45923938 (estimated locally),0.04 per call) set_shaper_cmd_props.isra.0/127 (45923938 (estimated locally),0.04 per call) 
shaper_cmd_action_query.isra.0.constprop.0/133 (shaper_cmd_action_query.isra.0.constprop) @079069a0
  Type: function definition analyzed
  Visibility: artificial
  References: context/52 (addr)
  Referring: 
  Clone of shaper_cmd_action_query.isra.0/128
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: fci_qos_shaper_cmd/35 (170958392 (estimated locally),0.16 per call) 
  Calls: fci_get_phy_if_by_name/18 (1073741824 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (574129754 (estimated locally),0.53 per call) pfe_tmu_check_shaper/81 (574129754 (estimated locally),0.53 per call) autolibc_strncpy/65 (189462818 (estimated locally),0.18 per call) pfe_phy_if_get_id/54 (189462818 (estimated locally),0.18 per call) pfe_tmu_shp_get_rate_mode/88 (189462818 (estimated locally),0.18 per call) pfe_phy_if_get_id/54 (189443872 (estimated locally),0.18 per call) pfe_tmu_shp_get_limits/89 (189443872 (estimated locally),0.18 per call) pfe_hm_report/61 (62516478 (estimated locally),0.06 per call) oal_util_raise_dem_for_drv_runtime_err/62 (62516478 (estimated locally),0.06 per call) pfe_phy_if_get_id/54 (189443872 (estimated locally),0.18 per call) pfe_tmu_shp_get_idle_slope/90 (189443872 (estimated locally),0.18 per call) pfe_phy_if_get_id/54 (189443872 (estimated locally),0.18 per call) pfe_tmu_shp_get_position/91 (189443872 (estimated locally),0.18 per call) 
policer_flow_cmd_action_deregister.isra.0/129 (policer_flow_cmd_action_deregister.isra.0) @07393d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_qos_policer_flow_cmd/43 (77223579 (estimated locally),0.07 per call) 
  Calls: pfe_gpi_qos_rem_flow/100 (354334802 (estimated locally),0.33 per call) 
shaper_cmd_action_query.isra.0/128 (shaper_cmd_action_query.isra.0) @07393a80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
set_shaper_cmd_props.isra.0/127 (set_shaper_cmd_props.isra.0) @073937e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: shaper_cmd_action_update.constprop/134 (45923938 (estimated locally),0.04 per call) 
  Calls: pfe_tmu_shp_set_idle_slope/87 (27688203 (estimated locally),0.03 per call) pfe_phy_if_get_id/54 (27688203 (estimated locally),0.03 per call) pfe_tmu_shp_set_position/83 (83903646 (estimated locally),0.08 per call) pfe_phy_if_get_id/54 (83903646 (estimated locally),0.08 per call) pfe_tmu_shp_set_limits/86 (254253474 (estimated locally),0.24 per call) pfe_phy_if_get_id/54 (254253474 (estimated locally),0.24 per call) oal_util_raise_dem_for_drv_runtime_err/62 (254253474 (estimated locally),0.24 per call) pfe_hm_report/61 (254253474 (estimated locally),0.24 per call) oal_util_raise_dem_for_drv_runtime_err/62 (565234877 (estimated locally),0.53 per call) pfe_hm_report/61 (565234877 (estimated locally),0.53 per call) pfe_tmu_shp_set_rate_mode/85 (291181603 (estimated locally),0.27 per call) pfe_phy_if_get_id/54 (291181603 (estimated locally),0.27 per call) pfe_tmu_shp_set_rate_mode/85 (217325345 (estimated locally),0.20 per call) pfe_phy_if_get_id/54 (217325345 (estimated locally),0.20 per call) 
shaper_disconnect_and_disable.isra.0/126 (shaper_disconnect_and_disable.isra.0) @07364700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: shaper_cmd_action_update.constprop/134 (91847875 (estimated locally),0.09 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/62 (314578437 (estimated locally),0.29 per call) pfe_hm_report/61 (314578437 (estimated locally),0.29 per call) pfe_tmu_shp_disable/84 (953267993 (estimated locally),0.89 per call) pfe_phy_if_get_id/54 (953267993 (estimated locally),0.89 per call) oal_util_raise_dem_for_drv_runtime_err/62 (120473833 (estimated locally),0.11 per call) pfe_hm_report/61 (120473833 (estimated locally),0.11 per call) pfe_tmu_shp_set_position/83 (365072220 (estimated locally),0.34 per call) pfe_phy_if_get_id/54 (365072220 (estimated locally),0.34 per call) 
fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (fci_qos_scheduler_cmd_query_get_sch.isra.0) @07364460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:150898585 (estimated locally) body local optimize_size
  Called by: scheduler_cmd_action_query.constprop/135 (189462818 (estimated locally),0.18 per call) 
  Calls: pfe_tmu_sch_get_input_weight/80 (630715948 (estimated locally),4.18 per call) pfe_phy_if_get_id/54 (630715948 (estimated locally),4.18 per call) pfe_tmu_sch_get_input_weight/80 (158818098 (estimated locally),1.05 per call) pfe_phy_if_get_id/54 (158818098 (estimated locally),1.05 per call) pfe_tmu_sch_get_bound_sch_output/79 (324914276 (estimated locally),2.15 per call) pfe_phy_if_get_id/54 (324914276 (estimated locally),2.15 per call) pfe_tmu_sch_get_bound_queue/78 (955630224 (estimated locally),6.33 per call) pfe_phy_if_get_id/54 (955630224 (estimated locally),6.33 per call) pfe_tmu_sch_get_input_cnt/72 (118111600 (estimated locally),0.78 per call) pfe_phy_if_get_id/54 (118111600 (estimated locally),0.78 per call) oal_util_raise_dem_for_drv_runtime_err/62 (32771895 (estimated locally),0.22 per call) pfe_hm_report/61 (32771895 (estimated locally),0.22 per call) pfe_tmu_sch_get_algo/77 (150883496 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (150883496 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/62 (50294499 (estimated locally),0.33 per call) pfe_hm_report/61 (50294499 (estimated locally),0.33 per call) pfe_tmu_sch_get_rate_mode/76 (150898585 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (150898585 (estimated locally),1.00 per call) 
fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0) @0735e8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:65411690 (estimated locally) body local optimize_size
  Called by: scheduler_cmd_action_update.constprop/136 (20632501 (estimated locally),0.02 per call) 
  Calls: pfe_tmu_sch_set_input_weight/75 (681660195 (estimated locally),10.42 per call) pfe_phy_if_get_id/54 (681660195 (estimated locally),10.42 per call) pfe_tmu_sch_bind_sch_output/74 (462915397 (estimated locally),7.08 per call) pfe_phy_if_get_id/54 (462915397 (estimated locally),7.08 per call) pfe_tmu_sch_bind_queue/73 (232656231 (estimated locally),3.56 per call) pfe_phy_if_get_id/54 (232656231 (estimated locally),3.56 per call) oal_util_raise_dem_for_drv_runtime_err/62 (6944962 (estimated locally),0.11 per call) pfe_hm_report/61 (6944962 (estimated locally),0.11 per call) pfe_tmu_sch_bind_queue/73 (347248106 (estimated locally),5.31 per call) pfe_phy_if_get_id/54 (347248106 (estimated locally),5.31 per call) check_scheduler_input.isra.0/119 (1052266988 (estimated locally),16.09 per call) pfe_tmu_sch_get_input_cnt/72 (65411690 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (65411690 (estimated locally),1.00 per call) 
fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (fci_qos_scheduler_cmd_update_set_mode.isra.0) @0735e620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: sch_algos/17 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: scheduler_cmd_action_update.constprop/136 (62522730 (estimated locally),0.06 per call) 
  Calls: pfe_tmu_sch_set_algo/71 (209397184 (estimated locally),0.20 per call) pfe_phy_if_get_id/54 (209397184 (estimated locally),0.20 per call) pfe_tmu_sch_set_rate_mode/70 (86669348 (estimated locally),0.08 per call) pfe_phy_if_get_id/54 (86669348 (estimated locally),0.08 per call) pfe_tmu_sch_set_rate_mode/70 (108662673 (estimated locally),0.10 per call) pfe_phy_if_get_id/54 (108662673 (estimated locally),0.10 per call) 
get_wred_zone_probs.isra.0/122 (get_wred_zone_probs.isra.0) @0702d540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:51432292 (estimated locally) body local optimize_size
  Called by: qos_queue_cmd_action_query.constprop/137 (47365705 (estimated locally),0.04 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/62 (18897915 (estimated locally),0.37 per call) pfe_hm_report/61 (18897915 (estimated locally),0.37 per call) pfe_tmu_queue_get_wred_prob/68 (343598457 (estimated locally),6.68 per call) pfe_phy_if_get_id/54 (343598457 (estimated locally),6.68 per call) pfe_tmu_queue_get_wred_zones/67 (51432292 (estimated locally),1.00 per call) pfe_phy_if_get_id/54 (51432292 (estimated locally),1.00 per call) 
queue_mode_wred.isra.0/121 (queue_mode_wred.isra.0) @0700fc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:718000470 (estimated locally) body local optimize_size
  Called by: qos_queue_cmd_action_update.constprop/138 (30309799 (estimated locally),0.03 per call) 
  Calls: pfe_tmu_queue_set_wred_prob/63 (1014686025 (estimated locally),1.41 per call) pfe_phy_if_get_id/54 (1014686025 (estimated locally),1.41 per call) oal_util_raise_dem_for_drv_runtime_err/62 (30459763 (estimated locally),0.04 per call) pfe_hm_report/61 (30459763 (estimated locally),0.04 per call) pfe_tmu_queue_get_cnt/55 (145323295 (estimated locally),0.20 per call) pfe_phy_if_get_id/54 (145323295 (estimated locally),0.20 per call) 
check_scheduler_input.isra.0/119 (check_scheduler_input.isra.0) @06dd2d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (1052266988 (estimated locally),16.09 per call) 
  Calls: 
pfe_gpi_shp_get_limits/118 (pfe_gpi_shp_get_limits) @0c933b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_query/50 (38587060 (estimated locally),0.04 per call) 
  Calls: 
pfe_gpi_shp_get_idle_slope/117 (pfe_gpi_shp_get_idle_slope) @0c933a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_query/50 (116930485 (estimated locally),0.11 per call) 
  Calls: 
pfe_gpi_shp_get_mode/116 (pfe_gpi_shp_get_mode) @0c9339a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_query/50 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_gpi_shp_get_type/115 (pfe_gpi_shp_get_type) @0c9338c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_query/50 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_shp_is_enabled/114 (pfe_gpi_shp_is_enabled) @0c9337e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_query/50 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_shp_set_limits/113 (pfe_gpi_shp_set_limits) @0c933620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_update/49 (6366865 (estimated locally),0.01 per call) 
  Calls: 
pfe_gpi_shp_set_idle_slope/112 (pfe_gpi_shp_set_idle_slope) @0c933540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_update/49 (19293530 (estimated locally),0.02 per call) 
  Calls: 
pfe_gpi_shp_set_mode/111 (pfe_gpi_shp_set_mode) @0c933460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_update/49 (58465242 (estimated locally),0.05 per call) 
  Calls: 
pfe_gpi_shp_set_type/110 (pfe_gpi_shp_set_type) @0c933380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_update/49 (177167401 (estimated locally),0.17 per call) 
  Calls: 
pfe_gpi_shp_disable/109 (pfe_gpi_shp_disable) @0c9332a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_update/49 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_gpi_shp_enable/108 (pfe_gpi_shp_enable) @0c9331c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_shp_cmd_action_update/49 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_gpi_wred_get_prob/107 (pfe_gpi_wred_get_prob) @0c91be00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_wred_cmd_action_query/47 (858993459 (estimated locally),3.28 per call) 
  Calls: 
pfe_gpi_wred_get_thr/106 (pfe_gpi_wred_get_thr) @0c91bd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_wred_cmd_action_query/47 (674660097 (estimated locally),2.58 per call) 
  Calls: 
pfe_gpi_wred_is_enabled/105 (pfe_gpi_wred_is_enabled) @0c91bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_wred_cmd_action_query/47 (261993004 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_wred_set_prob/104 (pfe_gpi_wred_set_prob) @0c91ba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: wred_prob_zone_set_reg/45 (419876003 (estimated locally),1.77 per call) 
  Calls: 
pfe_gpi_wred_set_thr/103 (pfe_gpi_wred_set_thr) @0c91b8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: wred_thr_set_reg/44 (393633753 (estimated locally),1.36 per call) 
  Calls: 
pfe_gpi_wred_disable/102 (pfe_gpi_wred_disable) @0c91b700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_wred_cmd_action_update/46 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_gpi_wred_enable/101 (pfe_gpi_wred_enable) @0c91b620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_wred_cmd_action_update/46 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_gpi_qos_rem_flow/100 (pfe_gpi_qos_rem_flow) @0c91b2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_flow_cmd_action_deregister.isra.0/129 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_gpi_qos_add_flow/99 (pfe_gpi_qos_add_flow) @0c91b000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: policer_flow_cmd_action_register/41 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_qos_get_next_flow/98 (pfe_gpi_qos_get_next_flow) @0c8c3ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_policer_flow_cmd/43 (77223579 (estimated locally),0.07 per call) 
  Calls: 
pfe_gpi_qos_get_first_flow/97 (pfe_gpi_qos_get_first_flow) @0c8c3e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_policer_flow_cmd/43 (77223579 (estimated locally),0.07 per call) 
  Calls: 
pfe_emac_get_gpi/96 (pfe_emac_get_gpi) @0c8c3c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_get_gpi/36 (792206719 (estimated locally),0.74 per call) 
  Calls: 
pfe_phy_if_get_emac/95 (pfe_phy_if_get_emac) @0c8c3b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_get_gpi/36 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_gpi_qos_is_enabled/94 (pfe_gpi_qos_is_enabled) @0c8c38c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_policer_cmd/38 (128693095 (estimated locally),0.12 per call) 
  Calls: 
pfe_gpi_qos_disable/93 (pfe_gpi_qos_disable) @0c8c37e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_policer_cmd/38 (64346547 (estimated locally),0.06 per call) 
  Calls: 
pfe_gpi_qos_enable/92 (pfe_gpi_qos_enable) @0c8c3700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_policer_cmd/38 (64346547 (estimated locally),0.06 per call) 
  Calls: 
pfe_tmu_shp_get_position/91 (pfe_tmu_shp_get_position) @0c8c3540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shaper_cmd_action_query.isra.0.constprop/133 (189443872 (estimated locally),0.18 per call) 
  Calls: 
pfe_tmu_shp_get_idle_slope/90 (pfe_tmu_shp_get_idle_slope) @0c8c3460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shaper_cmd_action_query.isra.0.constprop/133 (189443872 (estimated locally),0.18 per call) 
  Calls: 
pfe_tmu_shp_get_limits/89 (pfe_tmu_shp_get_limits) @0c8c3380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shaper_cmd_action_query.isra.0.constprop/133 (189443872 (estimated locally),0.18 per call) 
  Calls: 
pfe_tmu_shp_get_rate_mode/88 (pfe_tmu_shp_get_rate_mode) @0c8c32a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shaper_cmd_action_query.isra.0.constprop/133 (189462818 (estimated locally),0.18 per call) 
  Calls: 
pfe_tmu_shp_set_idle_slope/87 (pfe_tmu_shp_set_idle_slope) @0c8c30e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: set_shaper_cmd_props.isra.0/127 (27688203 (estimated locally),0.03 per call) 
  Calls: 
pfe_tmu_shp_set_limits/86 (pfe_tmu_shp_set_limits) @0c8c3000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: set_shaper_cmd_props.isra.0/127 (254253474 (estimated locally),0.24 per call) 
  Calls: 
pfe_tmu_shp_set_rate_mode/85 (pfe_tmu_shp_set_rate_mode) @0c8a6460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: set_shaper_cmd_props.isra.0/127 (291181603 (estimated locally),0.27 per call) set_shaper_cmd_props.isra.0/127 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_tmu_shp_disable/84 (pfe_tmu_shp_disable) @0c8a6ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shaper_disconnect_and_disable.isra.0/126 (953267993 (estimated locally),0.89 per call) 
  Calls: 
pfe_tmu_shp_set_position/83 (pfe_tmu_shp_set_position) @0c8a6e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: set_shaper_cmd_props.isra.0/127 (83903646 (estimated locally),0.08 per call) shaper_disconnect_and_disable.isra.0/126 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_tmu_shp_enable/82 (pfe_tmu_shp_enable) @0c8a6c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shaper_cmd_action_update.constprop/134 (91847875 (estimated locally),0.09 per call) 
  Calls: 
pfe_tmu_check_shaper/81 (pfe_tmu_check_shaper) @0c8a6b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shaper_cmd_action_update.constprop/134 (367391502 (estimated locally),0.34 per call) shaper_cmd_action_query.isra.0.constprop/133 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_tmu_sch_get_input_weight/80 (pfe_tmu_sch_get_input_weight) @0c8a68c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (630715948 (estimated locally),4.18 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (158818098 (estimated locally),1.05 per call) 
  Calls: 
pfe_tmu_sch_get_bound_sch_output/79 (pfe_tmu_sch_get_bound_sch_output) @0c8a67e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (324914276 (estimated locally),2.15 per call) 
  Calls: 
pfe_tmu_sch_get_bound_queue/78 (pfe_tmu_sch_get_bound_queue) @0c8a6700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (955630224 (estimated locally),6.33 per call) 
  Calls: 
pfe_tmu_sch_get_algo/77 (pfe_tmu_sch_get_algo) @0c8a6620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (150883496 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_sch_get_rate_mode/76 (pfe_tmu_sch_get_rate_mode) @0c8a6540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (150898585 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_sch_set_input_weight/75 (pfe_tmu_sch_set_input_weight) @0c8a61c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (681660195 (estimated locally),10.42 per call) 
  Calls: 
pfe_tmu_sch_bind_sch_output/74 (pfe_tmu_sch_bind_sch_output) @0c8a60e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (462915397 (estimated locally),7.08 per call) 
  Calls: 
pfe_tmu_sch_bind_queue/73 (pfe_tmu_sch_bind_queue) @0c8a6000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (232656231 (estimated locally),3.56 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (347248106 (estimated locally),5.31 per call) 
  Calls: 
pfe_tmu_sch_get_input_cnt/72 (pfe_tmu_sch_get_input_cnt) @0c888ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (118111600 (estimated locally),0.78 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (65411690 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_sch_set_algo/71 (pfe_tmu_sch_set_algo) @0c888e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (209397184 (estimated locally),0.20 per call) 
  Calls: 
pfe_tmu_sch_set_rate_mode/70 (pfe_tmu_sch_set_rate_mode) @0c888d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (86669348 (estimated locally),0.08 per call) fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (108662673 (estimated locally),0.10 per call) 
  Calls: 
pfe_tmu_check_scheduler/69 (pfe_tmu_check_scheduler) @0c888b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: scheduler_cmd_action_update.constprop/136 (574129754 (estimated locally),0.53 per call) scheduler_cmd_action_query.constprop/135 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_tmu_queue_get_wred_prob/68 (pfe_tmu_queue_get_wred_prob) @0c8888c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: get_wred_zone_probs.isra.0/122 (343598457 (estimated locally),6.68 per call) 
  Calls: 
pfe_tmu_queue_get_wred_zones/67 (pfe_tmu_queue_get_wred_zones) @0c8887e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: get_wred_zone_probs.isra.0/122 (51432292 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_queue_get_mode/66 (pfe_tmu_queue_get_mode) @0c888620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: qos_queue_cmd_action_query.constprop/137 (189462818 (estimated locally),0.18 per call) 
  Calls: 
autolibc_strncpy/65 (autolibc_strncpy) @0c888540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: qos_queue_cmd_action_query.constprop/137 (189462818 (estimated locally),0.18 per call) scheduler_cmd_action_query.constprop/135 (189462818 (estimated locally),0.18 per call) shaper_cmd_action_query.isra.0.constprop/133 (189462818 (estimated locally),0.18 per call) fci_qos_policer_flow_cmd/43 (77223579 (estimated locally),0.07 per call) fci_qos_policer_flow_cmd/43 (77223579 (estimated locally),0.07 per call) fci_qos_policer_cmd/38 (128693095 (estimated locally),0.12 per call) policer_shp_cmd_action_query/50 (1073741824 (estimated locally),1.00 per call) policer_wred_cmd_action_query/47 (261993004 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_check_queue/64 (pfe_tmu_check_queue) @0c888460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: qos_queue_cmd_action_query.constprop/137 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_tmu_queue_set_wred_prob/63 (pfe_tmu_queue_set_wred_prob) @0c8882a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: queue_mode_wred.isra.0/121 (1014686025 (estimated locally),1.41 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/62 (oal_util_raise_dem_for_drv_runtime_err) @0c8880e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: qos_queue_cmd_action_query.constprop/137 (47365705 (estimated locally),0.04 per call) shaper_cmd_action_update.constprop/134 (45923938 (estimated locally),0.04 per call) shaper_cmd_action_query.isra.0.constprop/133 (62516478 (estimated locally),0.06 per call) set_shaper_cmd_props.isra.0/127 (254253474 (estimated locally),0.24 per call) set_shaper_cmd_props.isra.0/127 (565234877 (estimated locally),0.53 per call) shaper_disconnect_and_disable.isra.0/126 (314578437 (estimated locally),0.29 per call) shaper_disconnect_and_disable.isra.0/126 (120473833 (estimated locally),0.11 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (32771895 (estimated locally),0.22 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (50294499 (estimated locally),0.33 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (6944962 (estimated locally),0.11 per call) get_wred_zone_probs.isra.0/122 (18897915 (estimated locally),0.37 per call) queue_mode_wred.isra.0/121 (30459763 (estimated locally),0.04 per call) fci_get_phy_if_by_name/18 (193714836 (estimated locally),0.18 per call) 
  Calls: 
pfe_hm_report/61 (pfe_hm_report) @0c888000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: qos_queue_cmd_action_query.constprop/137 (47365705 (estimated locally),0.04 per call) shaper_cmd_action_update.constprop/134 (45923938 (estimated locally),0.04 per call) shaper_cmd_action_query.isra.0.constprop/133 (62516478 (estimated locally),0.06 per call) set_shaper_cmd_props.isra.0/127 (254253474 (estimated locally),0.24 per call) set_shaper_cmd_props.isra.0/127 (565234877 (estimated locally),0.53 per call) shaper_disconnect_and_disable.isra.0/126 (314578437 (estimated locally),0.29 per call) shaper_disconnect_and_disable.isra.0/126 (120473833 (estimated locally),0.11 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (32771895 (estimated locally),0.22 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (50294499 (estimated locally),0.33 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (6944962 (estimated locally),0.11 per call) get_wred_zone_probs.isra.0/122 (18897915 (estimated locally),0.37 per call) queue_mode_wred.isra.0/121 (30459763 (estimated locally),0.04 per call) fci_get_phy_if_by_name/18 (193714836 (estimated locally),0.18 per call) 
  Calls: 
pfe_if_db_unlock/60 (pfe_if_db_unlock) @0c8790e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_get_phy_if_by_name/18 (587014656 (estimated locally),0.55 per call) 
  Calls: 
pfe_if_db_entry_get_phy_if/59 (pfe_if_db_entry_get_phy_if) @0c879ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_get_phy_if_by_name/18 (410910259 (estimated locally),0.38 per call) 
  Calls: 
pfe_if_db_get_first/58 (pfe_if_db_get_first) @0c879e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_get_phy_if_by_name/18 (587014656 (estimated locally),0.55 per call) 
  Calls: 
pfe_if_db_lock/57 (pfe_if_db_lock) @0c879d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_get_phy_if_by_name/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_queue_set_mode/56 (pfe_tmu_queue_set_mode) @0c879b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: qos_queue_cmd_action_update.constprop/138 (45923938 (estimated locally),0.04 per call) qos_queue_cmd_action_update.constprop/138 (45923938 (estimated locally),0.04 per call) 
  Calls: 
pfe_tmu_queue_get_cnt/55 (pfe_tmu_queue_get_cnt) @0c879a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: qos_queue_cmd_action_update.constprop/138 (367391502 (estimated locally),0.34 per call) queue_mode_wred.isra.0/121 (145323295 (estimated locally),0.20 per call) 
  Calls: 
pfe_phy_if_get_id/54 (pfe_phy_if_get_id) @0c8799a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: qos_queue_cmd_action_update.constprop/138 (751619277 (estimated locally),0.70 per call) qos_queue_cmd_action_update.constprop/138 (45923938 (estimated locally),0.04 per call) qos_queue_cmd_action_update.constprop/138 (45923938 (estimated locally),0.04 per call) qos_queue_cmd_action_query.constprop/137 (574129754 (estimated locally),0.53 per call) qos_queue_cmd_action_query.constprop/137 (189462818 (estimated locally),0.18 per call) scheduler_cmd_action_update.constprop/136 (574129754 (estimated locally),0.53 per call) scheduler_cmd_action_update.constprop/136 (287064877 (estimated locally),0.27 per call) scheduler_cmd_action_query.constprop/135 (574129754 (estimated locally),0.53 per call) shaper_cmd_action_update.constprop/134 (751619277 (estimated locally),0.70 per call) shaper_cmd_action_update.constprop/134 (91847875 (estimated locally),0.09 per call) shaper_cmd_action_query.isra.0.constprop/133 (574129754 (estimated locally),0.53 per call) shaper_cmd_action_query.isra.0.constprop/133 (189462818 (estimated locally),0.18 per call) shaper_cmd_action_query.isra.0.constprop/133 (189443872 (estimated locally),0.18 per call) shaper_cmd_action_query.isra.0.constprop/133 (189443872 (estimated locally),0.18 per call) shaper_cmd_action_query.isra.0.constprop/133 (189443872 (estimated locally),0.18 per call) set_shaper_cmd_props.isra.0/127 (27688203 (estimated locally),0.03 per call) set_shaper_cmd_props.isra.0/127 (83903646 (estimated locally),0.08 per call) set_shaper_cmd_props.isra.0/127 (254253474 (estimated locally),0.24 per call) set_shaper_cmd_props.isra.0/127 (291181603 (estimated locally),0.27 per call) set_shaper_cmd_props.isra.0/127 (217325345 (estimated locally),0.20 per call) shaper_disconnect_and_disable.isra.0/126 (953267993 (estimated locally),0.89 per call) shaper_disconnect_and_disable.isra.0/126 (365072220 (estimated locally),0.34 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (630715948 (estimated locally),4.18 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (158818098 (estimated locally),1.05 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (324914276 (estimated locally),2.15 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (955630224 (estimated locally),6.33 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (118111600 (estimated locally),0.78 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (150883496 (estimated locally),1.00 per call) fci_qos_scheduler_cmd_query_get_sch.isra.0/125 (150898585 (estimated locally),1.00 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (681660195 (estimated locally),10.42 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (462915397 (estimated locally),7.08 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (232656231 (estimated locally),3.56 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (347248106 (estimated locally),5.31 per call) fci_qos_scheduler_cmd_update_cfg_scheduler.isra.0/124 (65411690 (estimated locally),1.00 per call) fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (209397184 (estimated locally),0.20 per call) fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (86669348 (estimated locally),0.08 per call) fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (108662673 (estimated locally),0.10 per call) get_wred_zone_probs.isra.0/122 (343598457 (estimated locally),6.68 per call) get_wred_zone_probs.isra.0/122 (51432292 (estimated locally),1.00 per call) queue_mode_wred.isra.0/121 (1014686025 (estimated locally),1.41 per call) queue_mode_wred.isra.0/121 (145323295 (estimated locally),0.20 per call) 
  Calls: 
autolibc_memset/53 (autolibc_memset) @0c879700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_qos_policer_shp_cmd/51 (697932186 (estimated locally),0.65 per call) fci_qos_policer_wred_cmd/48 (697932186 (estimated locally),0.65 per call) fci_qos_policer_flow_cmd/43 (697932186 (estimated locally),0.65 per call) fci_qos_policer_flow_cmd/43 (1073741824 (estimated locally),1.00 per call) fci_qos_policer_cmd/38 (697932186 (estimated locally),0.65 per call) fci_qos_shaper_cmd/35 (512926469 (estimated locally),0.48 per call) fci_qos_scheduler_cmd/30 (512926469 (estimated locally),0.48 per call) fci_qos_queue_cmd/23 (512926469 (estimated locally),0.48 per call) policer_shp_cmd_action_query/50 (1073741824 (estimated locally),1.00 per call) policer_shp_cmd_action_query/50 (1073741824 (estimated locally),1.00 per call) policer_shp_cmd_action_update/49 (1073741824 (estimated locally),1.00 per call) policer_shp_cmd_action_update/49 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
context/52 (context) @0c87c438
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: fci_qos_scheduler_cmd/30 (addr)fci_qos_queue_cmd/23 (addr)fci_get_phy_if_by_name/18 (read)fci_qos_queue_cmd/23 (addr)fci_qos_scheduler_cmd/30 (addr)fci_qos_shaper_cmd/35 (addr)fci_qos_shaper_cmd/35 (addr)shaper_cmd_action_query.isra.0.constprop.0/133 (addr)shaper_cmd_action_update.constprop.0/134 (addr)scheduler_cmd_action_query.constprop.0/135 (addr)scheduler_cmd_action_update.constprop.0/136 (addr)qos_queue_cmd_action_query.constprop.0/137 (addr)qos_queue_cmd_action_update.constprop.0/138 (addr)
  Availability: not_available
  Varpool flags:
fci_qos_policer_shp_cmd/51 (fci_qos_policer_shp_cmd) @0c8792a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: policer_shp_cmd_action_query/50 (72505690 (estimated locally),0.07 per call) policer_shp_cmd_action_update/49 (72505690 (estimated locally),0.07 per call) fci_qos_get_gpi/36 (475222025 (estimated locally),0.44 per call) fci_get_phy_if_by_name/18 (697932186 (estimated locally),0.65 per call) autolibc_memset/53 (697932186 (estimated locally),0.65 per call) 
policer_shp_cmd_action_query/50 (policer_shp_cmd_action_query) @0c879000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_qos_policer_shp_cmd/51 (72505690 (estimated locally),0.07 per call) 
  Calls: pfe_gpi_shp_get_limits/118 (38587060 (estimated locally),0.04 per call) pfe_gpi_shp_get_idle_slope/117 (116930485 (estimated locally),0.11 per call) pfe_gpi_shp_get_mode/116 (354334802 (estimated locally),0.33 per call) pfe_gpi_shp_get_type/115 (1073741824 (estimated locally),1.00 per call) pfe_gpi_shp_is_enabled/114 (1073741824 (estimated locally),1.00 per call) autolibc_strncpy/65 (1073741824 (estimated locally),1.00 per call) autolibc_memset/53 (1073741824 (estimated locally),1.00 per call) autolibc_memset/53 (1073741824 (estimated locally),1.00 per call) 
policer_shp_cmd_action_update/49 (policer_shp_cmd_action_update) @07a2bb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_qos_policer_shp_cmd/51 (72505690 (estimated locally),0.07 per call) 
  Calls: pfe_gpi_shp_set_limits/113 (6366865 (estimated locally),0.01 per call) pfe_gpi_shp_set_idle_slope/112 (19293530 (estimated locally),0.02 per call) pfe_gpi_shp_set_mode/111 (58465242 (estimated locally),0.05 per call) pfe_gpi_shp_set_type/110 (177167401 (estimated locally),0.17 per call) pfe_gpi_shp_disable/109 (536870913 (estimated locally),0.50 per call) pfe_gpi_shp_enable/108 (536870913 (estimated locally),0.50 per call) autolibc_memset/53 (1073741824 (estimated locally),1.00 per call) autolibc_memset/53 (1073741824 (estimated locally),1.00 per call) 
fci_qos_policer_wred_cmd/48 (fci_qos_policer_wred_cmd) @07a2b620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: policer_wred_cmd_action_query/47 (83650512 (estimated locally),0.08 per call) policer_wred_cmd_action_update/46 (83650512 (estimated locally),0.08 per call) fci_qos_get_gpi/36 (475222025 (estimated locally),0.44 per call) fci_get_phy_if_by_name/18 (697932186 (estimated locally),0.65 per call) autolibc_memset/53 (697932186 (estimated locally),0.65 per call) 
policer_wred_cmd_action_query/47 (policer_wred_cmd_action_query) @07a2b0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:261993004 (estimated locally) body local optimize_size
  Called by: fci_qos_policer_wred_cmd/48 (83650512 (estimated locally),0.08 per call) 
  Calls: pfe_gpi_wred_get_prob/107 (858993459 (estimated locally),3.28 per call) pfe_gpi_wred_get_thr/106 (674660097 (estimated locally),2.58 per call) pfe_gpi_wred_is_enabled/105 (261993004 (estimated locally),1.00 per call) autolibc_strncpy/65 (261993004 (estimated locally),1.00 per call) 
policer_wred_cmd_action_update/46 (policer_wred_cmd_action_update) @07a2bd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_qos_policer_wred_cmd/48 (83650512 (estimated locally),0.08 per call) 
  Calls: wred_prob_zone_set_reg/45 (58465242 (estimated locally),0.05 per call) wred_thr_set_reg/44 (177167401 (estimated locally),0.17 per call) pfe_gpi_wred_disable/102 (536870913 (estimated locally),0.50 per call) pfe_gpi_wred_enable/101 (536870913 (estimated locally),0.50 per call) 
wred_prob_zone_set_reg/45 (wred_prob_zone_set_reg) @07a2ba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:237841546 (estimated locally) body local optimize_size
  Called by: policer_wred_cmd_action_update/46 (58465242 (estimated locally),0.05 per call) 
  Calls: pfe_gpi_wred_set_prob/104 (419876003 (estimated locally),1.77 per call) 
wred_thr_set_reg/44 (wred_thr_set_reg) @07a2b7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:290085312 (estimated locally) body local optimize_size
  Called by: policer_wred_cmd_action_update/46 (177167401 (estimated locally),0.17 per call) 
  Calls: pfe_gpi_wred_set_thr/103 (393633753 (estimated locally),1.36 per call) 
fci_qos_policer_flow_cmd/43 (fci_qos_policer_flow_cmd) @07a2b540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_qos_flow_entry_convert_from_gpi/40 (25483781 (estimated locally),0.02 per call) pfe_gpi_qos_get_next_flow/98 (77223579 (estimated locally),0.07 per call) autolibc_strncpy/65 (77223579 (estimated locally),0.07 per call) fci_qos_flow_entry_convert_from_gpi/40 (25483781 (estimated locally),0.02 per call) pfe_gpi_qos_get_first_flow/97 (77223579 (estimated locally),0.07 per call) autolibc_strncpy/65 (77223579 (estimated locally),0.07 per call) policer_flow_cmd_action_deregister.isra.0/129 (77223579 (estimated locally),0.07 per call) policer_flow_cmd_action_register/41 (77223579 (estimated locally),0.07 per call) fci_qos_get_gpi/36 (475222025 (estimated locally),0.44 per call) fci_get_phy_if_by_name/18 (697932186 (estimated locally),0.65 per call) autolibc_memset/53 (697932186 (estimated locally),0.65 per call) autolibc_memset/53 (1073741824 (estimated locally),1.00 per call) 
policer_flow_cmd_action_register/41 (policer_flow_cmd_action_register) @07a2b000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_qos_policer_flow_cmd/43 (77223579 (estimated locally),0.07 per call) 
  Calls: pfe_gpi_qos_add_flow/99 (1073741824 (estimated locally),1.00 per call) fci_qos_flow_entry_convert_to_gpi/39 (1073741824 (estimated locally),1.00 per call) 
fci_qos_flow_entry_convert_from_gpi/40 (fci_qos_flow_entry_convert_from_gpi) @07a0fa80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_qos_policer_flow_cmd/43 (25483781 (estimated locally),0.02 per call) fci_qos_policer_flow_cmd/43 (25483781 (estimated locally),0.02 per call) 
  Calls: 
fci_qos_flow_entry_convert_to_gpi/39 (fci_qos_flow_entry_convert_to_gpi) @07a0f540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: policer_flow_cmd_action_register/41 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
fci_qos_policer_cmd/38 (fci_qos_policer_cmd) @07a0fee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_qos_is_enabled/94 (128693095 (estimated locally),0.12 per call) autolibc_strncpy/65 (128693095 (estimated locally),0.12 per call) pfe_gpi_qos_disable/93 (64346547 (estimated locally),0.06 per call) pfe_gpi_qos_enable/92 (64346547 (estimated locally),0.06 per call) fci_qos_get_gpi/36 (475222025 (estimated locally),0.44 per call) fci_get_phy_if_by_name/18 (697932186 (estimated locally),0.65 per call) autolibc_memset/53 (697932186 (estimated locally),0.65 per call) 
fci_qos_get_gpi/36 (fci_qos_get_gpi) @07a0f9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_qos_policer_shp_cmd/51 (475222025 (estimated locally),0.44 per call) fci_qos_policer_wred_cmd/48 (475222025 (estimated locally),0.44 per call) fci_qos_policer_flow_cmd/43 (475222025 (estimated locally),0.44 per call) fci_qos_policer_cmd/38 (475222025 (estimated locally),0.44 per call) 
  Calls: pfe_emac_get_gpi/96 (792206719 (estimated locally),0.74 per call) pfe_phy_if_get_emac/95 (1073741824 (estimated locally),1.00 per call) 
fci_qos_shaper_cmd/35 (fci_qos_shaper_cmd) @07a0f700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/52 (addr)context/52 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: shaper_cmd_action_query.isra.0.constprop/133 (170958392 (estimated locally),0.16 per call) shaper_cmd_action_update.constprop/134 (170958392 (estimated locally),0.16 per call) autolibc_memset/53 (512926469 (estimated locally),0.48 per call) 
shaper_cmd_action_update/33 (shaper_cmd_action_update) @07a0f000
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fci_qos_scheduler_cmd/30 (fci_qos_scheduler_cmd) @079ff460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/52 (addr)context/52 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: scheduler_cmd_action_query.constprop/135 (170958392 (estimated locally),0.16 per call) scheduler_cmd_action_update.constprop/136 (170958392 (estimated locally),0.16 per call) autolibc_memset/53 (512926469 (estimated locally),0.48 per call) 
scheduler_cmd_action_query/29 (scheduler_cmd_action_query) @079ff1c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
scheduler_cmd_action_update/28 (scheduler_cmd_action_update) @07930c40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fci_qos_queue_cmd/23 (fci_qos_queue_cmd) @079302a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/52 (addr)context/52 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: qos_queue_cmd_action_query.constprop/137 (170958392 (estimated locally),0.16 per call) qos_queue_cmd_action_update.constprop/138 (170958392 (estimated locally),0.16 per call) autolibc_memset/53 (512926469 (estimated locally),0.48 per call) 
qos_queue_cmd_action_query/22 (qos_queue_cmd_action_query) @07930000
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
qos_queue_cmd_action_update/20 (qos_queue_cmd_action_update) @07906c40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fci_get_phy_if_by_name/18 (fci_get_phy_if_by_name) @07906620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/52 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: qos_queue_cmd_action_update.constprop/138 (1073741823 (estimated locally),1.00 per call) qos_queue_cmd_action_query.constprop/137 (1073741824 (estimated locally),1.00 per call) scheduler_cmd_action_update.constprop/136 (1073741824 (estimated locally),1.00 per call) scheduler_cmd_action_query.constprop/135 (1073741824 (estimated locally),1.00 per call) shaper_cmd_action_update.constprop/134 (1073741823 (estimated locally),1.00 per call) shaper_cmd_action_query.isra.0.constprop/133 (1073741824 (estimated locally),1.00 per call) fci_qos_policer_shp_cmd/51 (697932186 (estimated locally),0.65 per call) fci_qos_policer_wred_cmd/48 (697932186 (estimated locally),0.65 per call) fci_qos_policer_flow_cmd/43 (697932186 (estimated locally),0.65 per call) fci_qos_policer_cmd/38 (697932186 (estimated locally),0.65 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/62 (193714836 (estimated locally),0.18 per call) pfe_hm_report/61 (193714836 (estimated locally),0.18 per call) pfe_if_db_unlock/60 (587014656 (estimated locally),0.55 per call) pfe_if_db_entry_get_phy_if/59 (410910259 (estimated locally),0.38 per call) pfe_if_db_get_first/58 (587014656 (estimated locally),0.55 per call) pfe_if_db_lock/57 (1073741824 (estimated locally),1.00 per call) 
sch_algos/17 (sch_algos) @078c3f30
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: fci_qos_scheduler_cmd_update_set_mode.isra.0/123 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
fci_qmode_to_qmode/16 (fci_qmode_to_qmode) @078c3ea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: qos_queue_cmd_action_update.constprop.0/138 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function fci_qos_flow_entry_convert_from_gpi (fci_qos_flow_entry_convert_from_gpi, funcdef_no=35, decl_uid=12736, cgraph_uid=36, symbol_order=40)

Modification phase of node fci_qos_flow_entry_convert_from_gpi/40
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
fci_qos_flow_entry_convert_from_gpi (const struct pfe_iqos_flow_spec_t * gpi_flow, struct fpp_iqos_flow_spec_t * flow)
{
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  <unnamed type> _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  short unsigned int _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  long unsigned int _36;
  long unsigned int _37;
  unsigned char _38;
  unsigned char _39;
  unsigned char _40;
  unsigned char _41;
  unsigned char _42;
  unsigned char _43;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = gpi_flow_45(D)->type_mask;
  _2 = _1 r>> 8;
  flow_46(D)->type_mask = _2;
  # DEBUG BEGIN_STMT
  _3 = gpi_flow_45(D)->arg_type_mask;
  _4 = _3 r>> 8;
  flow_46(D)->arg_type_mask = _4;
  # DEBUG BEGIN_STMT
  _5 = gpi_flow_45(D)->action;
  flow_46(D)->action = _5;
  # DEBUG BEGIN_STMT
  _6 = gpi_flow_45(D)->args.vlan;
  _7 = _6 r>> 8;
  flow_46(D)->args.vlan = _7;
  # DEBUG BEGIN_STMT
  _8 = gpi_flow_45(D)->args.vlan_m;
  _9 = _8 r>> 8;
  flow_46(D)->args.vlan_m = _9;
  # DEBUG BEGIN_STMT
  _10 = gpi_flow_45(D)->args.sport_max;
  _11 = _10 r>> 8;
  flow_46(D)->args.sport_max = _11;
  # DEBUG BEGIN_STMT
  _12 = gpi_flow_45(D)->args.sport_min;
  _13 = _12 r>> 8;
  flow_46(D)->args.sport_min = _13;
  # DEBUG BEGIN_STMT
  _14 = gpi_flow_45(D)->args.dport_max;
  _15 = _14 r>> 8;
  flow_46(D)->args.dport_max = _15;
  # DEBUG BEGIN_STMT
  _16 = gpi_flow_45(D)->args.dport_min;
  _17 = _16 r>> 8;
  flow_46(D)->args.dport_min = _17;
  # DEBUG BEGIN_STMT
  _18 = gpi_flow_45(D)->args.sip;
  _19 = _18 >> 24;
  _20 = _18 >> 8;
  _21 = _20 & 65280;
  _22 = _19 | _21;
  _23 = _18 << 8;
  _24 = _23 & 16711680;
  _25 = _22 | _24;
  _26 = _18 << 24;
  _27 = _25 | _26;
  flow_46(D)->args.sip = _27;
  # DEBUG BEGIN_STMT
  _28 = gpi_flow_45(D)->args.dip;
  _29 = _28 >> 24;
  _30 = _28 >> 8;
  _31 = _30 & 65280;
  _32 = _29 | _31;
  _33 = _28 << 8;
  _34 = _33 & 16711680;
  _35 = _32 | _34;
  _36 = _28 << 24;
  _37 = _35 | _36;
  flow_46(D)->args.dip = _37;
  # DEBUG BEGIN_STMT
  _38 = gpi_flow_45(D)->args.tos;
  flow_46(D)->args.tos = _38;
  # DEBUG BEGIN_STMT
  _39 = gpi_flow_45(D)->args.tos_m;
  flow_46(D)->args.tos_m = _39;
  # DEBUG BEGIN_STMT
  _40 = gpi_flow_45(D)->args.l4proto;
  flow_46(D)->args.l4proto = _40;
  # DEBUG BEGIN_STMT
  _41 = gpi_flow_45(D)->args.l4proto_m;
  flow_46(D)->args.l4proto_m = _41;
  # DEBUG BEGIN_STMT
  _42 = gpi_flow_45(D)->args.sip_m;
  flow_46(D)->args.sip_m = _42;
  # DEBUG BEGIN_STMT
  _43 = gpi_flow_45(D)->args.dip_m;
  flow_46(D)->args.dip_m = _43;
  return;

}



;; Function fci_get_phy_if_by_name (fci_get_phy_if_by_name, funcdef_no=13, decl_uid=12638, cgraph_uid=14, symbol_order=18)

Modification phase of node fci_get_phy_if_by_name/18
fci_get_phy_if_by_name (char_t * name)
{
  uint32_t sid;
  errno_t ret;
  struct pfe_phy_if_t * phy_if;
  struct pfe_if_db_entry_t * entry;
  struct pfe_if_db_t * _1;
  long unsigned int sid.0_2;
  struct pfe_if_db_entry_t * entry.1_3;
  long unsigned int sid.3_4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG fci => &context
  # DEBUG BEGIN_STMT
  entry = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG phy_if => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_11 = pfe_if_db_lock (&sid);
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  if (ret_11 != 0)
    goto <bb 7>; [45.33%]
  else
    goto <bb 3>; [54.67%]

  <bb 3> [local count: 587014656]:
  # DEBUG BEGIN_STMT
  _1 = context.phy_if_db;
  sid.0_2 = sid;
  pfe_if_db_get_first (_1, sid.0_2, 3, name_12(D), &entry);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry.1_3 = entry;
  if (entry.1_3 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 410910259]:
  # DEBUG BEGIN_STMT
  phy_if_14 = pfe_if_db_entry_get_phy_if (entry.1_3);
  # DEBUG phy_if => phy_if_14

  <bb 5> [local count: 587014656]:
  # phy_if_5 = PHI <0B(3), phy_if_14(4)>
  # DEBUG phy_if => phy_if_5
  # DEBUG BEGIN_STMT
  sid.3_4 = sid;
  ret_16 = pfe_if_db_unlock (sid.3_4);
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  if (ret_16 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 193714836]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Interface DB unlock failed: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_qos.c", 150, ret_16, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 7> [local count: 1073741824]:
  # phy_if_6 = PHI <0B(2), phy_if_5(5), phy_if_5(6)>
  # DEBUG phy_if => phy_if_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry ={v} {CLOBBER};
  sid ={v} {CLOBBER};
  return phy_if_6;

}



;; Function fci_qos_get_gpi (fci_qos_get_gpi, funcdef_no=31, decl_uid=12640, cgraph_uid=32, symbol_order=36)

Modification phase of node fci_qos_get_gpi/36
fci_qos_get_gpi (const struct pfe_phy_if_t * phy_if)
{
  struct pfe_gpi_t * gpi;
  const struct pfe_emac_t * emac;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  emac_6 = pfe_phy_if_get_emac (phy_if_4(D));
  # DEBUG emac => emac_6
  # DEBUG BEGIN_STMT
  # DEBUG gpi => 0B
  # DEBUG BEGIN_STMT
  if (emac_6 != 0B)
    goto <bb 3>; [73.78%]
  else
    goto <bb 4>; [26.22%]

  <bb 3> [local count: 792206719]:
  # DEBUG BEGIN_STMT
  gpi_8 = pfe_emac_get_gpi (emac_6);
  # DEBUG gpi => gpi_8

  <bb 4> [local count: 1073741824]:
  # gpi_1 = PHI <0B(2), gpi_8(3)>
  # DEBUG gpi => gpi_1
  # DEBUG BEGIN_STMT
  return gpi_1;

}



;; Function fci_qos_queue_cmd (fci_qos_queue_cmd, funcdef_no=18, decl_uid=12568, cgraph_uid=19, symbol_order=23)

Modification phase of node fci_qos_queue_cmd/23
fci_qos_queue_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_qos_queue_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  struct fpp_qos_queue_cmd_t * q;
  long unsigned int _1;
  short unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG fci => &context
  # DEBUG BEGIN_STMT
  _1 = *reply_len_6(D);
  if (_1 <= 59)
    goto <bb 7>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  *reply_len_6(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_8(D), 0, 60);
  # DEBUG BEGIN_STMT
  q_11 = &msg_10(D)->msg_cmd.payload;
  # DEBUG q => q_11
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_qos_queue_cmd_t *)msg_10(D) + 16B].action;
  switch (_2) <default: <L4> [33.33%], case 4: <L2> [33.33%], case 6: <L3> [33.33%]>

  <bb 4> [local count: 170958392]:
<L2>:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 0;
  # DEBUG BEGIN_STMT
  ret_19 = qos_queue_cmd_action_update (fci_ret_12(D), q_11, &context);
  # DEBUG ret => ret_19
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 170958392]:
<L3>:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 0;
  # DEBUG BEGIN_STMT
  ret_15 = qos_queue_cmd_action_query (reply_buf_8(D), fci_ret_12(D), q_11, &context);
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  *reply_len_6(D) = 60;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 170958392]:
<L4>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073690532]:
  # ret_3 = PHI <22(2), ret_19(4), ret_15(5), 0(6)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function fci_qos_scheduler_cmd (fci_qos_scheduler_cmd, funcdef_no=25, decl_uid=12573, cgraph_uid=26, symbol_order=30)

Modification phase of node fci_qos_scheduler_cmd/30
fci_qos_scheduler_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_qos_scheduler_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  struct fpp_qos_scheduler_cmd_t * sch;
  long unsigned int _1;
  short unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG fci => &context
  # DEBUG BEGIN_STMT
  _1 = *reply_len_6(D);
  if (_1 <= 187)
    goto <bb 7>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  *reply_len_6(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_8(D), 0, 188);
  # DEBUG BEGIN_STMT
  sch_11 = &msg_10(D)->msg_cmd.payload;
  # DEBUG sch => sch_11
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_qos_scheduler_cmd_t *)msg_10(D) + 16B].action;
  switch (_2) <default: <L4> [33.33%], case 4: <L2> [33.33%], case 6: <L3> [33.33%]>

  <bb 4> [local count: 170958392]:
<L2>:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 0;
  # DEBUG BEGIN_STMT
  ret_19 = scheduler_cmd_action_update (fci_ret_12(D), &context, sch_11);
  # DEBUG ret => ret_19
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 170958392]:
<L3>:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 0;
  # DEBUG BEGIN_STMT
  ret_15 = scheduler_cmd_action_query (reply_buf_8(D), fci_ret_12(D), &context, sch_11);
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  *reply_len_6(D) = 188;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 170958392]:
<L4>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073690532]:
  # ret_3 = PHI <22(2), ret_19(4), ret_15(5), 0(6)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function fci_qos_shaper_cmd (fci_qos_shaper_cmd, funcdef_no=30, decl_uid=12578, cgraph_uid=31, symbol_order=35)

Modification phase of node fci_qos_shaper_cmd/35
fci_qos_shaper_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_qos_shaper_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  struct fpp_qos_shaper_cmd_t * shp;
  long unsigned int _1;
  short unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG fci => &context
  # DEBUG BEGIN_STMT
  _1 = *reply_len_6(D);
  if (_1 <= 35)
    goto <bb 7>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  *reply_len_6(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_8(D), 0, 36);
  # DEBUG BEGIN_STMT
  shp_11 = &msg_10(D)->msg_cmd.payload;
  # DEBUG shp => shp_11
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_qos_shaper_cmd_t *)msg_10(D) + 16B].action;
  switch (_2) <default: <L4> [33.33%], case 4: <L2> [33.33%], case 6: <L3> [33.33%]>

  <bb 4> [local count: 170958392]:
<L2>:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 0;
  # DEBUG BEGIN_STMT
  ret_19 = shaper_cmd_action_update (fci_ret_12(D), &context, shp_11);
  # DEBUG ret => ret_19
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 170958392]:
<L3>:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 0;
  # DEBUG BEGIN_STMT
  # DEBUG D#15 => &context
  ret_15 = shaper_cmd_action_query.isra.0 (reply_buf_8(D), fci_ret_12(D), &MEM[(void *)&context + 6508B], shp_11);
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  *reply_len_6(D) = 36;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 170958392]:
<L4>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073690532]:
  # ret_3 = PHI <22(2), ret_19(4), ret_15(5), 0(6)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function fci_qos_policer_cmd (fci_qos_policer_cmd, funcdef_no=33, decl_uid=12583, cgraph_uid=34, symbol_order=38)

Modification phase of node fci_qos_policer_cmd/38
fci_qos_policer_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_qos_policer_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  struct pfe_gpi_t * gpi;
  struct pfe_phy_if_t * phy_if;
  char[16] * _1;
  short unsigned int _2;
  unsigned char _3;
  char[16] * _4;
  unsigned char _5;
  long unsigned int _36;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG phy_if => 0B
  # DEBUG BEGIN_STMT
  # DEBUG gpi => 0B
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => msg_11(D)
  # DEBUG D#3 => fci_ret_12(D)
  # DEBUG D#4 => reply_buf_13(D)
  _36 = *reply_len_14(D);
  # DEBUG D#5 => reply_len_14(D)
  # DEBUG cmd_len => 20
  # DEBUG INLINE_ENTRY fci_validate_cmd_params
  # DEBUG msg => D#2
  # DEBUG fci_ret => D#3
  # DEBUG reply_buf => D#4
  # DEBUG reply_len => D#5
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_36 <= 19)
    goto <bb 15>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG cmd_len => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *reply_len_14(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_13(D), 0, 20);
  # DEBUG BEGIN_STMT
  # DEBUG D#17 => &msg_11(D)->msg_cmd.payload
  # DEBUG pol_cmd => D#17
  # DEBUG BEGIN_STMT
  _1 = &MEM[(struct fpp_qos_policer_cmd_t *)msg_11(D) + 16B].if_name;
  phy_if_18 = fci_get_phy_if_by_name (_1);
  # DEBUG phy_if => phy_if_18
  # DEBUG BEGIN_STMT
  if (phy_if_18 == 0B)
    goto <bb 4>; [31.91%]
  else
    goto <bb 5>; [68.09%]

  <bb 4> [local count: 222710160]:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 15>; [100.00%]

  <bb 5> [local count: 475222025]:
  # DEBUG BEGIN_STMT
  gpi_20 = fci_qos_get_gpi (phy_if_18);
  # DEBUG gpi => gpi_20
  # DEBUG BEGIN_STMT
  if (gpi_20 == 0B)
    goto <bb 6>; [18.75%]
  else
    goto <bb 7>; [81.25%]

  <bb 6> [local count: 89104130]:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 15>; [100.00%]

  <bb 7> [local count: 386117896]:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 0;
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_qos_policer_cmd_t *)msg_11(D) + 16B].action;
  switch (_2) <default: <L12> [33.33%], case 4: <L5> [33.33%], case 6: <L11> [33.33%]>

  <bb 8> [local count: 128693095]:
<L5>:
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct fpp_qos_policer_cmd_t *)msg_11(D) + 16B].enable;
  if (_3 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 64346547]:
  # DEBUG BEGIN_STMT
  ret_31 = pfe_gpi_qos_enable (gpi_20);
  # DEBUG ret => ret_31
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 64346547]:
  # DEBUG BEGIN_STMT
  ret_29 = pfe_gpi_qos_disable (gpi_20);
  # DEBUG ret => ret_29

  <bb 11> [local count: 128693095]:
  # ret_6 = PHI <ret_31(9), ret_29(10)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  if (ret_6 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 12> [local count: 64346547]:
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 65535;
  goto <bb 15>; [100.00%]

  <bb 13> [local count: 128693095]:
<L11>:
  # DEBUG BEGIN_STMT
  reply_buf_13(D)->action = _2;
  # DEBUG BEGIN_STMT
  _4 = &reply_buf_13(D)->if_name;
  autolibc_strncpy (_4, _1, 16);
  # DEBUG BEGIN_STMT
  reply_buf_13(D)->if_name[15] = 0;
  # DEBUG BEGIN_STMT
  _5 = pfe_gpi_qos_is_enabled (gpi_20);
  reply_buf_13(D)->enable = _5;
  # DEBUG BEGIN_STMT
  *reply_len_14(D) = 20;
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 128693095]:
<L12>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_12(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073703214]:
  # ret_7 = PHI <22(2), 2(4), 2(6), ret_6(12), 0(13), 0(14), ret_6(11)>
  # DEBUG cmd_len => NULL
  # DEBUG ret => NULL
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function fci_qos_policer_flow_cmd (fci_qos_policer_flow_cmd, funcdef_no=38, decl_uid=12588, cgraph_uid=39, symbol_order=43)

Modification phase of node fci_qos_policer_flow_cmd/43
fci_qos_policer_flow_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_qos_policer_flow_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  struct pfe_gpi_t * gpi;
  struct pfe_phy_if_t * phy_if;
  struct pfe_iqos_flow_spec_t gpi_flow;
  struct fpp_qos_policer_flow_cmd_t * flow_cmd;
  char[16] * _1;
  short unsigned int _2;
  char[16] * _3;
  uint8_t * _4;
  struct fpp_iqos_flow_spec_t * _5;
  char[16] * _6;
  uint8_t * _7;
  struct fpp_iqos_flow_spec_t * _8;
  long unsigned int _49;
  unsigned char _50;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG phy_if => 0B
  # DEBUG BEGIN_STMT
  # DEBUG gpi => 0B
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  autolibc_memset (&gpi_flow, 0, 36);
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => msg_13(D)
  # DEBUG D#3 => fci_ret_14(D)
  # DEBUG D#4 => reply_buf_15(D)
  _49 = *reply_len_16(D);
  # DEBUG D#5 => reply_len_16(D)
  # DEBUG cmd_len => 56
  # DEBUG INLINE_ENTRY fci_validate_cmd_params
  # DEBUG msg => D#2
  # DEBUG fci_ret => D#3
  # DEBUG reply_buf => D#4
  # DEBUG reply_len => D#5
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_49 <= 55)
    goto <bb 17>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG cmd_len => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *reply_len_16(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_15(D), 0, 56);
  # DEBUG BEGIN_STMT
  flow_cmd_19 = &msg_13(D)->msg_cmd.payload;
  # DEBUG flow_cmd => flow_cmd_19
  # DEBUG BEGIN_STMT
  _1 = &MEM[(struct fpp_qos_policer_flow_cmd_t *)msg_13(D) + 16B].if_name;
  phy_if_21 = fci_get_phy_if_by_name (_1);
  # DEBUG phy_if => phy_if_21
  # DEBUG BEGIN_STMT
  if (phy_if_21 == 0B)
    goto <bb 4>; [31.91%]
  else
    goto <bb 5>; [68.09%]

  <bb 4> [local count: 222710160]:
  # DEBUG BEGIN_STMT
  *fci_ret_14(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 17>; [100.00%]

  <bb 5> [local count: 475222025]:
  # DEBUG BEGIN_STMT
  gpi_23 = fci_qos_get_gpi (phy_if_21);
  # DEBUG gpi => gpi_23
  # DEBUG BEGIN_STMT
  if (gpi_23 == 0B)
    goto <bb 6>; [18.75%]
  else
    goto <bb 7>; [81.25%]

  <bb 6> [local count: 89104130]:
  # DEBUG BEGIN_STMT
  *fci_ret_14(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 17>; [100.00%]

  <bb 7> [local count: 386117896]:
  # DEBUG BEGIN_STMT
  *fci_ret_14(D) = 0;
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_qos_policer_flow_cmd_t *)msg_13(D) + 16B].action;
  switch (_2) <default: <L13> [20.00%], case 0: <L5> [20.00%], case 1: <L6> [20.00%], case 6: <L7> [20.00%], case 7: <L10> [20.00%]>

  <bb 8> [local count: 77223579]:
<L5>:
  # DEBUG BEGIN_STMT
  ret_44 = policer_flow_cmd_action_register (fci_ret_14(D), flow_cmd_19, &gpi_flow, gpi_23);
  # DEBUG ret => ret_44
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 9> [local count: 77223579]:
<L6>:
  # DEBUG BEGIN_STMT
  _50 = MEM[(unsigned char *)msg_13(D) + 34B];
  # DEBUG D#16 => flow_cmd_19
  ret_42 = policer_flow_cmd_action_deregister.isra.0 (fci_ret_14(D), _50, gpi_23);
  # DEBUG ret => ret_42
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 10> [local count: 77223579]:
<L7>:
  # DEBUG BEGIN_STMT
  reply_buf_15(D)->action = _2;
  # DEBUG BEGIN_STMT
  _3 = &reply_buf_15(D)->if_name;
  autolibc_strncpy (_3, _1, 16);
  # DEBUG BEGIN_STMT
  reply_buf_15(D)->if_name[15] = 0;
  # DEBUG BEGIN_STMT
  _4 = &reply_buf_15(D)->id;
  ret_37 = pfe_gpi_qos_get_first_flow (gpi_23, _4, &gpi_flow);
  # DEBUG ret => ret_37
  # DEBUG BEGIN_STMT
  if (ret_37 != 0)
    goto <bb 11>; [67.00%]
  else
    goto <bb 12>; [33.00%]

  <bb 11> [local count: 51739798]:
  # DEBUG BEGIN_STMT
  *fci_ret_14(D) = 62530;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 12> [local count: 25483781]:
  # DEBUG BEGIN_STMT
  _5 = &reply_buf_15(D)->flow;
  fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _5);
  # DEBUG BEGIN_STMT
  *reply_len_16(D) = 56;
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 13> [local count: 77223579]:
<L10>:
  # DEBUG BEGIN_STMT
  reply_buf_15(D)->action = _2;
  # DEBUG BEGIN_STMT
  _6 = &reply_buf_15(D)->if_name;
  autolibc_strncpy (_6, _1, 16);
  # DEBUG BEGIN_STMT
  reply_buf_15(D)->if_name[15] = 0;
  # DEBUG BEGIN_STMT
  _7 = &reply_buf_15(D)->id;
  ret_29 = pfe_gpi_qos_get_next_flow (gpi_23, _7, &gpi_flow);
  # DEBUG ret => ret_29
  # DEBUG BEGIN_STMT
  if (ret_29 != 0)
    goto <bb 14>; [67.00%]
  else
    goto <bb 15>; [33.00%]

  <bb 14> [local count: 51739798]:
  # DEBUG BEGIN_STMT
  *fci_ret_14(D) = 62530;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 15> [local count: 25483781]:
  # DEBUG BEGIN_STMT
  _8 = &reply_buf_15(D)->flow;
  fci_qos_flow_entry_convert_from_gpi (&gpi_flow, _8);
  # DEBUG BEGIN_STMT
  *reply_len_16(D) = 56;
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 16> [local count: 77223579]:
<L13>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_14(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  # ret_9 = PHI <22(2), 2(4), 2(6), ret_44(8), ret_42(9), 0(11), 0(12), 0(14), 0(15), 0(16)>
  # DEBUG cmd_len => NULL
  # DEBUG ret => NULL
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  gpi_flow ={v} {CLOBBER};
  return ret_9;

}



;; Function fci_qos_policer_wred_cmd (fci_qos_policer_wred_cmd, funcdef_no=43, decl_uid=12593, cgraph_uid=44, symbol_order=48)

Modification phase of node fci_qos_policer_wred_cmd/48
fci_qos_policer_wred_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_qos_policer_wred_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  struct pfe_gpi_t * gpi;
  struct pfe_phy_if_t * phy_if;
  fpp_iqos_queue_t queue;
  struct fpp_qos_policer_wred_cmd_t * wred_cmd;
  char[16] * _1;
  short unsigned int _2;
  long unsigned int _28;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => msg_6(D)
  # DEBUG D#3 => fci_ret_7(D)
  # DEBUG D#4 => reply_buf_8(D)
  _28 = *reply_len_9(D);
  # DEBUG D#5 => reply_len_9(D)
  # DEBUG cmd_len => 32
  # DEBUG INLINE_ENTRY fci_validate_cmd_params
  # DEBUG msg => D#2
  # DEBUG fci_ret => D#3
  # DEBUG reply_buf => D#4
  # DEBUG reply_len => D#5
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_28 <= 31)
    goto <bb 13>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG cmd_len => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *reply_len_9(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_8(D), 0, 32);
  # DEBUG BEGIN_STMT
  wred_cmd_12 = &msg_6(D)->msg_cmd.payload;
  # DEBUG wred_cmd => wred_cmd_12
  # DEBUG BEGIN_STMT
  _1 = &MEM[(struct fpp_qos_policer_wred_cmd_t *)msg_6(D) + 16B].if_name;
  phy_if_14 = fci_get_phy_if_by_name (_1);
  # DEBUG phy_if => phy_if_14
  # DEBUG BEGIN_STMT
  if (phy_if_14 == 0B)
    goto <bb 4>; [31.91%]
  else
    goto <bb 5>; [68.09%]

  <bb 4> [local count: 222710160]:
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 13>; [100.00%]

  <bb 5> [local count: 475222025]:
  # DEBUG BEGIN_STMT
  gpi_16 = fci_qos_get_gpi (phy_if_14);
  # DEBUG gpi => gpi_16
  # DEBUG BEGIN_STMT
  if (gpi_16 == 0B)
    goto <bb 6>; [18.75%]
  else
    goto <bb 7>; [81.25%]

  <bb 6> [local count: 89104130]:
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 386117896]:
  # DEBUG BEGIN_STMT
  queue_17 = MEM[(struct fpp_qos_policer_wred_cmd_t *)msg_6(D) + 16B].queue;
  # DEBUG queue => queue_17
  # DEBUG BEGIN_STMT
  if (queue_17 > 2)
    goto <bb 8>; [35.00%]
  else
    goto <bb 9>; [65.00%]

  <bb 8> [local count: 135141263]:
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 250976632]:
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 0;
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_qos_policer_wred_cmd_t *)msg_6(D) + 16B].action;
  switch (_2) <default: <L9> [33.33%], case 4: <L7> [33.33%], case 6: <L8> [33.33%]>

  <bb 10> [local count: 83650512]:
<L7>:
  # DEBUG BEGIN_STMT
  ret_23 = policer_wred_cmd_action_update (fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  # DEBUG ret => ret_23
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 83650512]:
<L8>:
  # DEBUG BEGIN_STMT
  ret_20 = policer_wred_cmd_action_query (reply_buf_8(D), fci_ret_7(D), wred_cmd_12, gpi_16, queue_17);
  # DEBUG ret => ret_20
  # DEBUG BEGIN_STMT
  *reply_len_9(D) = 32;
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 83650512]:
<L9>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073716729]:
  # ret_3 = PHI <22(2), 2(4), 2(6), 22(8), ret_23(10), ret_20(11), 0(12)>
  # DEBUG cmd_len => NULL
  # DEBUG ret => NULL
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function fci_qos_policer_shp_cmd (fci_qos_policer_shp_cmd, funcdef_no=46, decl_uid=12598, cgraph_uid=47, symbol_order=51)

Modification phase of node fci_qos_policer_shp_cmd/51
fci_qos_policer_shp_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_qos_policer_shp_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  struct pfe_gpi_t * gpi;
  struct pfe_phy_if_t * phy_if;
  uint8_t shp_id;
  struct fpp_qos_policer_shp_cmd_t * shp_cmd;
  char[16] * _1;
  short unsigned int _2;
  long unsigned int _28;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => msg_6(D)
  # DEBUG D#3 => fci_ret_7(D)
  # DEBUG D#4 => reply_buf_8(D)
  _28 = *reply_len_9(D);
  # DEBUG D#5 => reply_len_9(D)
  # DEBUG cmd_len => 36
  # DEBUG INLINE_ENTRY fci_validate_cmd_params
  # DEBUG msg => D#2
  # DEBUG fci_ret => D#3
  # DEBUG reply_buf => D#4
  # DEBUG reply_len => D#5
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_28 <= 35)
    goto <bb 13>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG cmd_len => NULL
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *reply_len_9(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_8(D), 0, 36);
  # DEBUG BEGIN_STMT
  shp_cmd_12 = &msg_6(D)->msg_cmd.payload;
  # DEBUG shp_cmd => shp_cmd_12
  # DEBUG BEGIN_STMT
  _1 = &MEM[(struct fpp_qos_policer_shp_cmd_t *)msg_6(D) + 16B].if_name;
  phy_if_14 = fci_get_phy_if_by_name (_1);
  # DEBUG phy_if => phy_if_14
  # DEBUG BEGIN_STMT
  if (phy_if_14 == 0B)
    goto <bb 4>; [31.91%]
  else
    goto <bb 5>; [68.09%]

  <bb 4> [local count: 222710160]:
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 13>; [100.00%]

  <bb 5> [local count: 475222025]:
  # DEBUG BEGIN_STMT
  gpi_16 = fci_qos_get_gpi (phy_if_14);
  # DEBUG gpi => gpi_16
  # DEBUG BEGIN_STMT
  if (gpi_16 == 0B)
    goto <bb 6>; [18.75%]
  else
    goto <bb 7>; [81.25%]

  <bb 6> [local count: 89104130]:
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 386117896]:
  # DEBUG BEGIN_STMT
  shp_id_17 = MEM[(struct fpp_qos_policer_shp_cmd_t *)msg_6(D) + 16B].id;
  # DEBUG shp_id => shp_id_17
  # DEBUG BEGIN_STMT
  if (shp_id_17 > 1)
    goto <bb 8>; [43.66%]
  else
    goto <bb 9>; [56.34%]

  <bb 8> [local count: 168579073]:
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 217538822]:
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 0;
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_qos_policer_shp_cmd_t *)msg_6(D) + 16B].action;
  switch (_2) <default: <L9> [33.33%], case 4: <L7> [33.33%], case 6: <L8> [33.33%]>

  <bb 10> [local count: 72505690]:
<L7>:
  # DEBUG BEGIN_STMT
  ret_23 = policer_shp_cmd_action_update (fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  # DEBUG ret => ret_23
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 72505690]:
<L8>:
  # DEBUG BEGIN_STMT
  ret_20 = policer_shp_cmd_action_query (reply_buf_8(D), fci_ret_7(D), shp_cmd_12, gpi_16, shp_id_17);
  # DEBUG ret => ret_20
  # DEBUG BEGIN_STMT
  *reply_len_9(D) = 36;
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 72505690]:
<L9>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_7(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073720073]:
  # ret_3 = PHI <22(2), 2(4), 2(6), 22(8), ret_23(10), ret_20(11), 0(12)>
  # DEBUG cmd_len => NULL
  # DEBUG ret => NULL
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}


