
IPA constant propagation start:
Determining dynamic type for call: ipvx_ct_query_cont (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_query_cont (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: fci_ret_4(D)  Outer instance pointer: fci_ret_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ipvx_ct_query_cont (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_query_cont (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ipvx_ct_query_cont (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_query_cont (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_len_9(D)  Outer instance pointer: reply_len_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ipvx_ct_query (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_query (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: fci_ret_4(D)  Outer instance pointer: fci_ret_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ipvx_ct_query (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_query (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ipvx_ct_query (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_query (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_len_9(D)  Outer instance pointer: reply_len_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = ipvx_ct_update (ipv6_3(D), msg_1(D), fci_ret_4(D));
  Starting walk at: ret_7 = ipvx_ct_update (ipv6_3(D), msg_1(D), fci_ret_4(D));
  instance pointer: msg_1(D)  Outer instance pointer: msg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = ipvx_ct_update (ipv6_3(D), msg_1(D), fci_ret_4(D));
  Starting walk at: ret_7 = ipvx_ct_update (ipv6_3(D), msg_1(D), fci_ret_4(D));
  instance pointer: fci_ret_4(D)  Outer instance pointer: fci_ret_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_6 = ipvx_ct_deregister (ipv6_3(D), msg_1(D), fci_ret_4(D));
  Starting walk at: ret_6 = ipvx_ct_deregister (ipv6_3(D), msg_1(D), fci_ret_4(D));
  instance pointer: msg_1(D)  Outer instance pointer: msg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_6 = ipvx_ct_deregister (ipv6_3(D), msg_1(D), fci_ret_4(D));
  Starting walk at: ret_6 = ipvx_ct_deregister (ipv6_3(D), msg_1(D), fci_ret_4(D));
  instance pointer: fci_ret_4(D)  Outer instance pointer: fci_ret_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_5 = ipvx_ct_register (ipv6_3(D), msg_1(D), fci_ret_4(D));
  Starting walk at: ret_5 = ipvx_ct_register (ipv6_3(D), msg_1(D), fci_ret_4(D));
  instance pointer: msg_1(D)  Outer instance pointer: msg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_5 = ipvx_ct_register (ipv6_3(D), msg_1(D), fci_ret_4(D));
  Starting walk at: ret_5 = ipvx_ct_register (ipv6_3(D), msg_1(D), fci_ret_4(D));
  instance pointer: fci_ret_4(D)  Outer instance pointer: fci_ret_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: fci_connections_drop_one (entry_4);
  Starting walk at: fci_connections_drop_one (entry_4);
  instance pointer: entry_4  Outer instance pointer: entry_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_8 = pfe_rtable_get_first (_1, 0, 0B);
  Function call may change dynamic type:entry_12 = pfe_rtable_get_next (_3);
  Function call may change dynamic type:pfe_rtable_entry_free (_2, entry_4);
  Function call may change dynamic type:fci_connections_drop_one (entry_4);
Determining dynamic type for call: ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  Starting walk at: ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  instance pointer: msg_2(D)  Outer instance pointer: msg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  Starting walk at: ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  instance pointer: fci_ret_3(D)  Outer instance pointer: fci_ret_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  Starting walk at: ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  instance pointer: reply_buf_4(D)  Outer instance pointer: reply_buf_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  Starting walk at: ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  instance pointer: reply_len_5(D)  Outer instance pointer: reply_len_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  Starting walk at: ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  instance pointer: msg_2(D)  Outer instance pointer: msg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  Starting walk at: ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  instance pointer: fci_ret_3(D)  Outer instance pointer: fci_ret_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  Starting walk at: ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  instance pointer: reply_buf_4(D)  Outer instance pointer: reply_buf_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  Starting walk at: ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  instance pointer: reply_len_5(D)  Outer instance pointer: reply_len_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_11 = ipvx_ct_check_args_clear_buf.isra.0 (ipv6_5(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ret_11 = ipvx_ct_check_args_clear_buf.isra.0 (ipv6_5(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_11 = ipvx_ct_check_args_clear_buf.isra.0 (ipv6_5(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ret_11 = ipvx_ct_check_args_clear_buf.isra.0 (ipv6_5(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_len_9(D)  Outer instance pointer: reply_len_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_1 = fci_connections_ipvx_ct_cmd.part.0 (ipv6_5(D), msg_6(D), fci_ret_7(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ret_1 = fci_connections_ipvx_ct_cmd.part.0 (ipv6_5(D), msg_6(D), fci_ret_7(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: msg_6(D)  Outer instance pointer: msg_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = ipvx_ct_check_args_clear_buf.isra.0 (ipv6_5(D), reply_buf_8(D), reply_len_9(D));
Determining dynamic type for call: ret_1 = fci_connections_ipvx_ct_cmd.part.0 (ipv6_5(D), msg_6(D), fci_ret_7(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ret_1 = fci_connections_ipvx_ct_cmd.part.0 (ipv6_5(D), msg_6(D), fci_ret_7(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: fci_ret_7(D)  Outer instance pointer: fci_ret_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = ipvx_ct_check_args_clear_buf.isra.0 (ipv6_5(D), reply_buf_8(D), reply_len_9(D));
Determining dynamic type for call: ret_1 = fci_connections_ipvx_ct_cmd.part.0 (ipv6_5(D), msg_6(D), fci_ret_7(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ret_1 = fci_connections_ipvx_ct_cmd.part.0 (ipv6_5(D), msg_6(D), fci_ret_7(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = ipvx_ct_check_args_clear_buf.isra.0 (ipv6_5(D), reply_buf_8(D), reply_len_9(D));
Determining dynamic type for call: ret_1 = fci_connections_ipvx_ct_cmd.part.0 (ipv6_5(D), msg_6(D), fci_ret_7(D), reply_buf_8(D), reply_len_9(D));
  Starting walk at: ret_1 = fci_connections_ipvx_ct_cmd.part.0 (ipv6_5(D), msg_6(D), fci_ret_7(D), reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_len_9(D)  Outer instance pointer: reply_len_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = ipvx_ct_check_args_clear_buf.isra.0 (ipv6_5(D), reply_buf_8(D), reply_len_9(D));
Determining dynamic type for call: ipvx_ct_compile_fci_reply (ipv6_7(D), entry_6, reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_compile_fci_reply (ipv6_7(D), entry_6, reply_buf_8(D), reply_len_9(D));
  instance pointer: entry_6  Outer instance pointer: entry_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_6 = pfe_rtable_get_next (_1);
Determining dynamic type for call: ipvx_ct_compile_fci_reply (ipv6_7(D), entry_6, reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_compile_fci_reply (ipv6_7(D), entry_6, reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_buf_8(D)  Outer instance pointer: reply_buf_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_6 = pfe_rtable_get_next (_1);
Determining dynamic type for call: ipvx_ct_compile_fci_reply (ipv6_7(D), entry_6, reply_buf_8(D), reply_len_9(D));
  Starting walk at: ipvx_ct_compile_fci_reply (ipv6_7(D), entry_6, reply_buf_8(D), reply_len_9(D));
  instance pointer: reply_len_9(D)  Outer instance pointer: reply_len_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_6 = pfe_rtable_get_next (_1);
Determining dynamic type for call: ipvx_ct_compile_fci_reply (ipv6_5(D), entry_8, reply_buf_9(D), reply_len_10(D));
  Starting walk at: ipvx_ct_compile_fci_reply (ipv6_5(D), entry_8, reply_buf_9(D), reply_len_10(D));
  instance pointer: entry_8  Outer instance pointer: entry_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_8 = pfe_rtable_get_first (_1, iftmp.11_3, 0B);
Determining dynamic type for call: ipvx_ct_compile_fci_reply (ipv6_5(D), entry_8, reply_buf_9(D), reply_len_10(D));
  Starting walk at: ipvx_ct_compile_fci_reply (ipv6_5(D), entry_8, reply_buf_9(D), reply_len_10(D));
  instance pointer: reply_buf_9(D)  Outer instance pointer: reply_buf_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_8 = pfe_rtable_get_first (_1, iftmp.11_3, 0B);
Determining dynamic type for call: ipvx_ct_compile_fci_reply (ipv6_5(D), entry_8, reply_buf_9(D), reply_len_10(D));
  Starting walk at: ipvx_ct_compile_fci_reply (ipv6_5(D), entry_8, reply_buf_9(D), reply_len_10(D));
  instance pointer: reply_len_10(D)  Outer instance pointer: reply_len_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_8 = pfe_rtable_get_first (_1, iftmp.11_3, 0B);
Determining dynamic type for call: ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Starting walk at: ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  instance pointer: reply_buf_5(D)  Outer instance pointer: reply_buf_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Starting walk at: ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  instance pointer: entry_11(D)  Outer instance pointer: entry_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Starting walk at: ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  instance pointer: reply_buf_5(D)  Outer instance pointer: reply_buf_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
Determining dynamic type for call: ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Starting walk at: ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  instance pointer: entry_11(D)  Outer instance pointer: entry_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
Determining dynamic type for call: ipvx_ct_compile_fci_reply_nat_modifications_ipv4 (reply_buf_5(D), actions_15, &tuple);
  Starting walk at: ipvx_ct_compile_fci_reply_nat_modifications_ipv4 (reply_buf_5(D), actions_15, &tuple);
  instance pointer: reply_buf_5(D)  Outer instance pointer: reply_buf_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_rtable_entry_to_5t_out (entry_11(D), &tuple);
  Function call may change dynamic type:actions_15 = pfe_rtable_entry_get_action_flags (entry_11(D));
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get output tuple\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_connections.c", 1462, "");
Determining dynamic type for call: ipvx_ct_compile_fci_reply_nat_modifications_ipv4 (reply_buf_5(D), actions_15, &tuple);
  Starting walk at: ipvx_ct_compile_fci_reply_nat_modifications_ipv4 (reply_buf_5(D), actions_15, &tuple);
  instance pointer: &tuple  Outer instance pointer: tuple offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_rtable_entry_to_5t_out (entry_11(D), &tuple);
  Function call may change dynamic type:actions_15 = pfe_rtable_entry_get_action_flags (entry_11(D));
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get output tuple\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_connections.c", 1462, "");
Determining dynamic type for call: ipvx_ct_compile_fci_reply_nat_modifications_ipv6 (reply_buf_5(D), actions_15, &tuple);
  Starting walk at: ipvx_ct_compile_fci_reply_nat_modifications_ipv6 (reply_buf_5(D), actions_15, &tuple);
  instance pointer: reply_buf_5(D)  Outer instance pointer: reply_buf_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_rtable_entry_to_5t_out (entry_11(D), &tuple);
  Function call may change dynamic type:actions_15 = pfe_rtable_entry_get_action_flags (entry_11(D));
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get output tuple\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_connections.c", 1462, "");
Determining dynamic type for call: ipvx_ct_compile_fci_reply_nat_modifications_ipv6 (reply_buf_5(D), actions_15, &tuple);
  Starting walk at: ipvx_ct_compile_fci_reply_nat_modifications_ipv6 (reply_buf_5(D), actions_15, &tuple);
  instance pointer: &tuple  Outer instance pointer: tuple offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_rtable_entry_to_5t_out (entry_11(D), &tuple);
  Function call may change dynamic type:actions_15 = pfe_rtable_entry_get_action_flags (entry_11(D));
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Function call may change dynamic type:ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get output tuple\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_connections.c", 1462, "");
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t (ct_cmd_17, &tuple);
  Starting walk at: fci_connections_ipv4_cmd_to_5t (ct_cmd_17, &tuple);
  instance pointer: ct_cmd_17  Outer instance pointer: msg_16(D) offset: 128 (bits) vtbl reference: 
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t (ct_cmd_17, &tuple);
  Starting walk at: fci_connections_ipv4_cmd_to_5t (ct_cmd_17, &tuple);
  instance pointer: &tuple  Outer instance pointer: tuple offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t (ct6_cmd_20, &tuple);
  Starting walk at: fci_connections_ipv6_cmd_to_5t (ct6_cmd_20, &tuple);
  instance pointer: ct6_cmd_20  Outer instance pointer: msg_16(D) offset: 128 (bits) vtbl reference: 
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t (ct6_cmd_20, &tuple);
  Starting walk at: fci_connections_ipv6_cmd_to_5t (ct6_cmd_20, &tuple);
  instance pointer: &tuple  Outer instance pointer: tuple offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t (ct_cmd_17, &tuple);
  Starting walk at: fci_connections_ipv4_cmd_to_5t (ct_cmd_17, &tuple);
  instance pointer: ct_cmd_17  Outer instance pointer: msg_16(D) offset: 128 (bits) vtbl reference: 
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t (ct_cmd_17, &tuple);
  Starting walk at: fci_connections_ipv4_cmd_to_5t (ct_cmd_17, &tuple);
  instance pointer: &tuple  Outer instance pointer: tuple offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t (ct6_cmd_19, &tuple);
  Starting walk at: fci_connections_ipv6_cmd_to_5t (ct6_cmd_19, &tuple);
  instance pointer: ct6_cmd_19  Outer instance pointer: msg_16(D) offset: 128 (bits) vtbl reference: 
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t (ct6_cmd_19, &tuple);
  Starting walk at: fci_connections_ipv6_cmd_to_5t (ct6_cmd_19, &tuple);
  instance pointer: &tuple  Outer instance pointer: tuple offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  Starting walk at: _1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  instance pointer: msg_13(D)  Outer instance pointer: msg_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  Starting walk at: _1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  instance pointer: &entry  Outer instance pointer: entry offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  Starting walk at: _1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  instance pointer: &rep_entry  Outer instance pointer: rep_entry offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
  Starting walk at: ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
Determining dynamic type for call: ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
  Starting walk at: ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
  instance pointer: fci_ret_15(D)  Outer instance pointer: fci_ret_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
Determining dynamic type for call: ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
  Starting walk at: ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
  instance pointer: &entry  Outer instance pointer: entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
Determining dynamic type for call: ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
  Starting walk at: ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
  instance pointer: &rep_entry  Outer instance pointer: rep_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
Determining dynamic type for call: ret_20 = ipvx_ct_register_add_rep_entry (fci_ret_15(D), &entry, &rep_entry);
  Starting walk at: ret_20 = ipvx_ct_register_add_rep_entry (fci_ret_15(D), &entry, &rep_entry);
  instance pointer: fci_ret_15(D)  Outer instance pointer: fci_ret_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  Function call may change dynamic type:ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
Determining dynamic type for call: ret_20 = ipvx_ct_register_add_rep_entry (fci_ret_15(D), &entry, &rep_entry);
  Starting walk at: ret_20 = ipvx_ct_register_add_rep_entry (fci_ret_15(D), &entry, &rep_entry);
  instance pointer: &entry  Outer instance pointer: entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  Function call may change dynamic type:ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
Determining dynamic type for call: ret_20 = ipvx_ct_register_add_rep_entry (fci_ret_15(D), &entry, &rep_entry);
  Starting walk at: ret_20 = ipvx_ct_register_add_rep_entry (fci_ret_15(D), &entry, &rep_entry);
  instance pointer: &rep_entry  Outer instance pointer: rep_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipvx_ct_register_get_rtable_entries (ipv6_12(D), msg_13(D), &entry, &rep_entry);
  Function call may change dynamic type:ret_18 = ipvx_ct_register_add_entry (_3, fci_ret_15(D), &entry, &rep_entry);
Determining dynamic type for call: result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Starting walk at: result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  instance pointer: ct_cmd_8  Outer instance pointer: msg_7(D) offset: 128 (bits) vtbl reference: 
Determining dynamic type for call: result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Starting walk at: result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  instance pointer: entry_12(D)  Outer instance pointer: entry_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Starting walk at: result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  instance pointer: &phy_if  Outer instance pointer: phy_if offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Starting walk at: result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  instance pointer: ct_cmd_8  Outer instance pointer: msg_7(D) offset: 128 (bits) vtbl reference: 
Determining dynamic type for call: result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Starting walk at: result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  instance pointer: entry_12(D)  Outer instance pointer: entry_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Starting walk at: result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  instance pointer: &phy_if  Outer instance pointer: phy_if offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: result_19 = fci_connections_ipv4_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  Starting walk at: result_19 = fci_connections_ipv4_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  instance pointer: ct_cmd_8  Outer instance pointer: msg_7(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Function call may change dynamic type:result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
Determining dynamic type for call: result_19 = fci_connections_ipv4_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  Starting walk at: result_19 = fci_connections_ipv4_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  instance pointer: rep_entry_17(D)  Outer instance pointer: rep_entry_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Function call may change dynamic type:result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
Determining dynamic type for call: result_19 = fci_connections_ipv4_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  Starting walk at: result_19 = fci_connections_ipv4_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  instance pointer: &phy_if  Outer instance pointer: phy_if offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Function call may change dynamic type:result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
Determining dynamic type for call: result_21 = fci_connections_ipv6_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  Starting walk at: result_21 = fci_connections_ipv6_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  instance pointer: ct_cmd_8  Outer instance pointer: msg_7(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Function call may change dynamic type:result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
Determining dynamic type for call: result_21 = fci_connections_ipv6_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  Starting walk at: result_21 = fci_connections_ipv6_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  instance pointer: rep_entry_17(D)  Outer instance pointer: rep_entry_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Function call may change dynamic type:result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
Determining dynamic type for call: result_21 = fci_connections_ipv6_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  Starting walk at: result_21 = fci_connections_ipv6_cmd_to_rep_entry (ct_cmd_8, rep_entry_17(D), &phy_if);
  instance pointer: &phy_if  Outer instance pointer: phy_if offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:result_16 = fci_connections_ipv6_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
  Function call may change dynamic type:result_14 = fci_connections_ipv4_cmd_to_entry (ct_cmd_8, entry_12(D), &phy_if);
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  Starting walk at: fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  instance pointer: ct6_cmd_13(D)  Outer instance pointer: ct6_cmd_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  Starting walk at: fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  instance pointer: &tuple_rep_buf  Outer instance pointer: tuple_rep_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_buf);
  Starting walk at: fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_buf);
  instance pointer: ct6_cmd_13(D)  Outer instance pointer: ct6_cmd_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_buf);
  Starting walk at: fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_buf);
  instance pointer: &tuple_buf  Outer instance pointer: tuple_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: route_15  Outer instance pointer: route_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: &tuple_buf  Outer instance pointer: tuple_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: &tuple_rep_buf  Outer instance pointer: tuple_rep_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  Starting walk at: fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  instance pointer: ct6_cmd_13(D)  Outer instance pointer: ct6_cmd_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  Starting walk at: fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  instance pointer: &tuple_buf  Outer instance pointer: tuple_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_rep_buf);
  Starting walk at: fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_rep_buf);
  instance pointer: ct6_cmd_13(D)  Outer instance pointer: ct6_cmd_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_rep_buf);
  Starting walk at: fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_rep_buf);
  instance pointer: &tuple_rep_buf  Outer instance pointer: tuple_rep_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: route_15  Outer instance pointer: route_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: &tuple_buf  Outer instance pointer: tuple_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: &tuple_rep_buf  Outer instance pointer: tuple_rep_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t_rep (ct6_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:fci_connections_ipv6_cmd_to_5t (ct6_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  Starting walk at: fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  instance pointer: ct_cmd_13(D)  Outer instance pointer: ct_cmd_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  Starting walk at: fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  instance pointer: &tuple_rep_buf  Outer instance pointer: tuple_rep_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_buf);
  Starting walk at: fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_buf);
  instance pointer: ct_cmd_13(D)  Outer instance pointer: ct_cmd_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_buf);
  Starting walk at: fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_buf);
  instance pointer: &tuple_buf  Outer instance pointer: tuple_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: route_15  Outer instance pointer: route_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: &tuple_buf  Outer instance pointer: tuple_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: &tuple_rep_buf  Outer instance pointer: tuple_rep_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  Starting walk at: fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  instance pointer: ct_cmd_13(D)  Outer instance pointer: ct_cmd_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  Starting walk at: fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  instance pointer: &tuple_buf  Outer instance pointer: tuple_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_rep_buf);
  Starting walk at: fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_rep_buf);
  instance pointer: ct_cmd_13(D)  Outer instance pointer: ct_cmd_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_rep_buf);
  Starting walk at: fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_rep_buf);
  instance pointer: &tuple_rep_buf  Outer instance pointer: tuple_rep_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: route_15  Outer instance pointer: route_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: &tuple_buf  Outer instance pointer: tuple_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  Starting walk at: _4 = fci_connections_create_entry (route_15, &tuple_buf, &tuple_rep_buf);
  instance pointer: &tuple_rep_buf  Outer instance pointer: tuple_rep_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t_rep (ct_cmd_13(D), &tuple_rep_buf);
  Function call may change dynamic type:fci_connections_ipv4_cmd_to_5t (ct_cmd_13(D), &tuple_buf);
  Function call may change dynamic type:route_15 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 5, _3);
Determining dynamic type for call: create_entry_check_nat (&new_entry, tuple_19(D), tuple_rep_27(D));
  Starting walk at: create_entry_check_nat (&new_entry, tuple_19(D), tuple_rep_27(D));
  instance pointer: &new_entry  Outer instance pointer: new_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_rtable_entry_set_out_mac_addrs (new_entry.10_12, _13, _14);
  Function call may change dynamic type:pfe_rtable_entry_set_ttl_decrement (new_entry.9_11);
  Function call may change dynamic type:pfe_rtable_entry_set_route_id (new_entry.8_9, _10);
  Function call may change dynamic type:pfe_rtable_entry_set_timeout (new_entry.7_6, _8);
  Function call may change dynamic type:pfe_rtable_entry_set_dstif (new_entry.6_4, _5);
  Function call may change dynamic type:_2 = pfe_rtable_entry_set_5t (_1, tuple_19(D));
  Function call may change dynamic type:_1 = pfe_rtable_entry_create ();
Determining dynamic type for call: create_entry_check_nat (&new_entry, tuple_19(D), tuple_rep_27(D));
  Starting walk at: create_entry_check_nat (&new_entry, tuple_19(D), tuple_rep_27(D));
  instance pointer: tuple_19(D)  Outer instance pointer: tuple_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_rtable_entry_set_out_mac_addrs (new_entry.10_12, _13, _14);
  Function call may change dynamic type:pfe_rtable_entry_set_ttl_decrement (new_entry.9_11);
  Function call may change dynamic type:pfe_rtable_entry_set_route_id (new_entry.8_9, _10);
  Function call may change dynamic type:pfe_rtable_entry_set_timeout (new_entry.7_6, _8);
  Function call may change dynamic type:pfe_rtable_entry_set_dstif (new_entry.6_4, _5);
  Function call may change dynamic type:_2 = pfe_rtable_entry_set_5t (_1, tuple_19(D));
  Function call may change dynamic type:_1 = pfe_rtable_entry_create ();
Determining dynamic type for call: create_entry_check_nat (&new_entry, tuple_19(D), tuple_rep_27(D));
  Starting walk at: create_entry_check_nat (&new_entry, tuple_19(D), tuple_rep_27(D));
  instance pointer: tuple_rep_27(D)  Outer instance pointer: tuple_rep_27(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_rtable_entry_set_out_mac_addrs (new_entry.10_12, _13, _14);
  Function call may change dynamic type:pfe_rtable_entry_set_ttl_decrement (new_entry.9_11);
  Function call may change dynamic type:pfe_rtable_entry_set_route_id (new_entry.8_9, _10);
  Function call may change dynamic type:pfe_rtable_entry_set_timeout (new_entry.7_6, _8);
  Function call may change dynamic type:pfe_rtable_entry_set_dstif (new_entry.6_4, _5);
  Function call may change dynamic type:_2 = pfe_rtable_entry_set_5t (_1, tuple_19(D));
  Function call may change dynamic type:_1 = pfe_rtable_entry_create ();

IPA structures before propagation:

Jump functions:
  Jump functions of caller  fci_connections_ipvx_ct_cmd.part.0/90:
    callsite  fci_connections_ipvx_ct_cmd.part.0/90 -> ipvx_ct_register/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_connections_ipvx_ct_cmd.part.0/90 -> ipvx_ct_deregister/30 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_connections_ipvx_ct_cmd.part.0/90 -> ipvx_ct_update/31 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_connections_ipvx_ct_cmd.part.0/90 -> ipvx_ct_query/37 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_connections_ipvx_ct_cmd.part.0/90 -> ipvx_ct_query_cont/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipvx_ct_check_args_clear_buf.isra.0/89:
  Jump functions of caller  fci_core_client_send/88:
  Jump functions of caller  pfe_rtable_entry_get_refptr/87:
  Jump functions of caller  pfe_rtable_entry_to_5t/86:
  Jump functions of caller  pfe_rtable_get_next/85:
  Jump functions of caller  pfe_rtable_entry_get_proto/84:
  Jump functions of caller  pfe_rtable_entry_get_dport/83:
  Jump functions of caller  pfe_rtable_entry_get_sport/82:
  Jump functions of caller  pfe_rtable_entry_get_out_vlan/81:
  Jump functions of caller  pfe_rtable_entry_get_route_id/80:
  Jump functions of caller  pfe_rtable_entry_get_dip/79:
  Jump functions of caller  pfe_rtable_entry_get_sip/78:
  Jump functions of caller  pfe_rtable_get_stats/77:
  Jump functions of caller  pfe_rtable_entry_get_stats_index/76:
  Jump functions of caller  pfe_rtable_entry_to_5t_out/75:
  Jump functions of caller  pfe_rtable_entry_get_action_flags/74:
  Jump functions of caller  pfe_rtable_entry_remove_ttl_decrement/73:
  Jump functions of caller  pfe_rtable_entry_get_child/72:
  Jump functions of caller  pfe_rtable_get_first/71:
  Jump functions of caller  pfe_rtable_del_entry/70:
  Jump functions of caller  pfe_rtable_add_entry/69:
  Jump functions of caller  pfe_rtable_entry_set_refptr/68:
  Jump functions of caller  pfe_rtable_entry_set_child/67:
  Jump functions of caller  pfe_rtable_entry_set_out_dport/66:
  Jump functions of caller  pfe_rtable_entry_set_out_sport/65:
  Jump functions of caller  pfe_rtable_entry_set_out_dip/64:
  Jump functions of caller  pfe_rtable_entry_set_out_sip/63:
  Jump functions of caller  autolibc_memcmp/62:
  Jump functions of caller  pfe_rtable_entry_set_out_mac_addrs/61:
  Jump functions of caller  pfe_rtable_entry_set_ttl_decrement/60:
  Jump functions of caller  pfe_rtable_entry_set_route_id/59:
  Jump functions of caller  pfe_rtable_entry_set_timeout/58:
  Jump functions of caller  pfe_rtable_entry_set_dstif/57:
  Jump functions of caller  pfe_rtable_entry_free/56:
  Jump functions of caller  pfe_rtable_entry_set_5t/55:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/54:
  Jump functions of caller  pfe_hm_report/53:
  Jump functions of caller  pfe_rtable_entry_create/52:
  Jump functions of caller  autolibc_memcpy/51:
  Jump functions of caller  pfe_rtable_entry_set_out_vlan/50:
  Jump functions of caller  fci_rt_db_get_first/49:
  Jump functions of caller  autolibc_memset/47:
  Jump functions of caller  fci_connections_get_default_timeout/46:
  Jump functions of caller  fci_connections_set_default_timeout/45:
  Jump functions of caller  fci_connections_drop_all/44:
    callsite  fci_connections_drop_all/44 -> fci_connections_drop_one/43 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_connections_drop_one/43:
  Jump functions of caller  fci_connections_ipv4_timeout_cmd/42:
    callsite  fci_connections_ipv4_timeout_cmd/42 -> fci_connections_get_default_timeout/46 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  fci_connections_ipv4_timeout_cmd/42 -> fci_connections_set_default_timeout/45 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_connections_ipv6_ct_cmd/41:
    callsite  fci_connections_ipv6_ct_cmd/41 -> fci_connections_ipvx_ct_cmd/39 : 
       param 0: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_connections_ipv4_ct_cmd/40:
    callsite  fci_connections_ipv4_ct_cmd/40 -> fci_connections_ipvx_ct_cmd/39 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_connections_ipvx_ct_cmd/39:
    callsite  fci_connections_ipvx_ct_cmd/39 -> fci_connections_ipvx_ct_cmd.part.0/90 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_connections_ipvx_ct_cmd/39 -> ipvx_ct_check_args_clear_buf.isra.0/89 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipvx_ct_query_cont/38:
    callsite  ipvx_ct_query_cont/38 -> ipvx_ct_compile_fci_reply/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipvx_ct_query/37:
    callsite  ipvx_ct_query/37 -> ipvx_ct_compile_fci_reply/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipvx_ct_compile_fci_reply/36:
    callsite  ipvx_ct_compile_fci_reply/36 -> ipvx_ct_compile_fci_reply_nat_modifications_ipv4/32 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_compile_fci_reply/36 -> ipvx_ct_compile_fci_reply_nat_modifications_ipv6/33 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_compile_fci_reply/36 -> ipvx_ct_compile_fci_reply_replydir/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipvx_ct_compile_fci_reply/36 -> ipvx_ct_compile_fci_reply_basic/34 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipvx_ct_compile_fci_reply_replydir/35:
  Jump functions of caller  ipvx_ct_compile_fci_reply_basic/34:
  Jump functions of caller  ipvx_ct_compile_fci_reply_nat_modifications_ipv6/33:
  Jump functions of caller  ipvx_ct_compile_fci_reply_nat_modifications_ipv4/32:
  Jump functions of caller  ipvx_ct_update/31:
    callsite  ipvx_ct_update/31 -> fci_connections_ipv4_cmd_to_5t/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_update/31 -> fci_connections_ipv6_cmd_to_5t/17 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  ipvx_ct_deregister/30:
    callsite  ipvx_ct_deregister/30 -> fci_connections_ipv4_cmd_to_5t/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_deregister/30 -> fci_connections_ipv6_cmd_to_5t/17 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  ipvx_ct_register/29:
    callsite  ipvx_ct_register/29 -> ipvx_ct_register_add_rep_entry/28 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_register/29 -> ipvx_ct_register_add_entry/27 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_register/29 -> ipvx_ct_register_get_rtable_entries/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0B
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0B
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  ipvx_ct_register_add_rep_entry/28:
  Jump functions of caller  ipvx_ct_register_add_entry/27:
  Jump functions of caller  ipvx_ct_register_get_rtable_entries/26:
    callsite  ipvx_ct_register_get_rtable_entries/26 -> fci_connections_ipv4_cmd_to_rep_entry/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_register_get_rtable_entries/26 -> fci_connections_ipv6_cmd_to_rep_entry/24 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_register_get_rtable_entries/26 -> fci_connections_ipv4_cmd_to_entry/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipvx_ct_register_get_rtable_entries/26 -> fci_connections_ipv6_cmd_to_entry/23 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  fci_connections_ipv6_cmd_to_rep_entry/24:
    callsite  fci_connections_ipv6_cmd_to_rep_entry/24 -> fci_connections_create_entry/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_connections_ipv6_cmd_to_rep_entry/24 -> fci_connections_ipv6_cmd_to_5t_rep/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_connections_ipv6_cmd_to_rep_entry/24 -> fci_connections_ipv6_cmd_to_5t/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  fci_connections_ipv6_cmd_to_entry/23:
    callsite  fci_connections_ipv6_cmd_to_entry/23 -> fci_connections_create_entry/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_connections_ipv6_cmd_to_entry/23 -> fci_connections_ipv6_cmd_to_5t_rep/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_connections_ipv6_cmd_to_entry/23 -> fci_connections_ipv6_cmd_to_5t/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  fci_connections_ipv4_cmd_to_rep_entry/22:
    callsite  fci_connections_ipv4_cmd_to_rep_entry/22 -> fci_connections_create_entry/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_connections_ipv4_cmd_to_rep_entry/22 -> fci_connections_ipv4_cmd_to_5t_rep/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_connections_ipv4_cmd_to_rep_entry/22 -> fci_connections_ipv4_cmd_to_5t/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  fci_connections_ipv4_cmd_to_entry/21:
    callsite  fci_connections_ipv4_cmd_to_entry/21 -> fci_connections_create_entry/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_connections_ipv4_cmd_to_entry/21 -> fci_connections_ipv4_cmd_to_5t_rep/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_connections_ipv4_cmd_to_entry/21 -> fci_connections_ipv4_cmd_to_5t/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  fci_connections_create_entry/20:
    callsite  fci_connections_create_entry/20 -> create_entry_check_nat/19 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_connections_create_entry/20 -> fci_connections_get_default_timeout/46 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  create_entry_check_nat/19:
  Jump functions of caller  fci_connections_ipv6_cmd_to_5t_rep/18:
  Jump functions of caller  fci_connections_ipv6_cmd_to_5t/17:
  Jump functions of caller  fci_connections_ipv4_cmd_to_5t_rep/16:
  Jump functions of caller  fci_connections_ipv4_cmd_to_5t/15:

 Propagating constants:

Not considering fci_connections_get_default_timeout for cloning; -fipa-cp-clone disabled.
Not considering fci_connections_set_default_timeout for cloning; -fipa-cp-clone disabled.
Not considering fci_connections_drop_all for cloning; -fipa-cp-clone disabled.
Not considering fci_connections_drop_one for cloning; -fipa-cp-clone disabled.
Not considering fci_connections_ipv4_timeout_cmd for cloning; -fipa-cp-clone disabled.
Not considering fci_connections_ipv6_ct_cmd for cloning; -fipa-cp-clone disabled.
Not considering fci_connections_ipv4_ct_cmd for cloning; -fipa-cp-clone disabled.

overall_size: 1413, max_new_size: 11001
 - context independent values, size: 32, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 40, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 41, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: fci_connections_ipvx_ct_cmd.part.0/90:
    param [0]: 1 [loc_time: 1, loc_size: 42, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 42, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_check_args_clear_buf.isra.0/89:
    param [0]: 1 [loc_time: 3, loc_size: 11, prop_time: 0, prop_size: 0]
               0 [loc_time: 3, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: fci_connections_get_default_timeout/46:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: fci_connections_set_default_timeout/45:
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
  Node: fci_connections_drop_all/44:
  Node: fci_connections_drop_one/43:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: fci_connections_ipv4_timeout_cmd/42:
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
  Node: fci_connections_ipv6_ct_cmd/41:
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
  Node: fci_connections_ipv4_ct_cmd/40:
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
  Node: fci_connections_ipvx_ct_cmd/39:
    param [0]: 0 [loc_time: 1, loc_size: 17, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 17, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_query_cont/38:
    param [0]: 0 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_query/37:
    param [0]: 0 [loc_time: 3, loc_size: 22, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 22, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_compile_fci_reply/36:
    param [0]: 1 [loc_time: 5, loc_size: 34, prop_time: 0, prop_size: 0]
               0 [loc_time: 5, loc_size: 34, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_compile_fci_reply_replydir/35:
    param [0]: 0 [loc_time: 3, loc_size: 67, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 67, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_compile_fci_reply_basic/34:
    param [0]: 0 [loc_time: 3, loc_size: 121, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 121, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_compile_fci_reply_nat_modifications_ipv6/33:
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
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipvx_ct_compile_fci_reply_nat_modifications_ipv4/32:
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
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipvx_ct_update/31:
    param [0]: 0 [loc_time: 4, loc_size: 29, prop_time: 0, prop_size: 0]
               1 [loc_time: 4, loc_size: 29, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_deregister/30:
    param [0]: 0 [loc_time: 3, loc_size: 55, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 55, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_register/29:
    param [0]: 0 [loc_time: 1, loc_size: 32, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 32, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
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
  Node: ipvx_ct_register_add_rep_entry/28:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipvx_ct_register_add_entry/27:
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
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipvx_ct_register_get_rtable_entries/26:
    param [0]: 1 [loc_time: 4, loc_size: 18, prop_time: 0, prop_size: 0]
               0 [loc_time: 4, loc_size: 18, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        ref offset 0: 0B [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        ref offset 0: 0B [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: fci_connections_ipv6_cmd_to_rep_entry/24:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_ct6_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_phy_if_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_connections_ipv6_cmd_to_entry/23:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_ct6_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        ref offset 0: 0B [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_phy_if_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_connections_ipv4_cmd_to_rep_entry/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_ct_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_phy_if_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_connections_ipv4_cmd_to_entry/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_ct_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        ref offset 0: 0B [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_phy_if_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_connections_create_entry/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: create_entry_check_nat/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_connections_ipv6_cmd_to_5t_rep/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_ct6_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_connections_ipv6_cmd_to_5t/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_ct6_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_connections_ipv4_cmd_to_5t_rep/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_ct_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_connections_ipv4_cmd_to_5t/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct fpp_ct_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_5_tuple_t * ~[0B, 0B]
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of ipvx_ct_register_get_rtable_entries/26 for all known contexts.
 - Creating a specialized node of fci_connections_ipv6_cmd_to_entry/23 for all known contexts.
 - Creating a specialized node of fci_connections_ipv4_cmd_to_entry/21 for all known contexts.
Propagated bits info for function fci_connections_ipv4_cmd_to_entry.constprop/93:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv6_cmd_to_entry.constprop/92:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function ipvx_ct_register_get_rtable_entries.constprop/91:
 param 0: value = 0x1, mask = 0x1
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipvx_ct_cmd.part.0/90:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_check_args_clear_buf.isra.0/89:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function fci_connections_ipvx_ct_cmd/39:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_query_cont/38:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_query/37:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_compile_fci_reply/36:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_compile_fci_reply_replydir/35:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_compile_fci_reply_basic/34:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_compile_fci_reply_nat_modifications_ipv6/33:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function ipvx_ct_compile_fci_reply_nat_modifications_ipv4/32:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function ipvx_ct_update/31:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_deregister/30:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_register/29:
 param 0: value = 0x1, mask = 0x1
Propagated bits info for function ipvx_ct_register_add_rep_entry/28:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function ipvx_ct_register_add_entry/27:
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function ipvx_ct_register_get_rtable_entries/26:
 param 0: value = 0x1, mask = 0x1
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv6_cmd_to_rep_entry/24:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv6_cmd_to_entry/23:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv4_cmd_to_rep_entry/22:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv4_cmd_to_entry/21:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_create_entry/20:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function create_entry_check_nat/19:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv6_cmd_to_5t_rep/18:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv6_cmd_to_5t/17:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv4_cmd_to_5t_rep/16:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_connections_ipv4_cmd_to_5t/15:
 param 1: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: ipvx_ct_register_get_rtable_entries/26 fci_connections_ipv6_cmd_to_entry/23 fci_connections_ipv4_cmd_to_entry/21
Reclaiming variables:
Clearing address taken flags:
Symbol table:

fci_connections_ipv4_cmd_to_entry.constprop.0/93 (fci_connections_ipv4_cmd_to_entry.constprop) @071d9e00
  Type: function definition analyzed
  Visibility:
  References: context/48 (addr)
  Referring: 
  Clone of fci_connections_ipv4_cmd_to_entry/21
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: ipvx_ct_register_get_rtable_entries.constprop/91 (708669605 (estimated locally),0.66 per call) 
  Calls: fci_rt_db_get_first/49 (354334802 (estimated locally),0.33 per call) fci_connections_ipv4_cmd_to_5t/15 (241266567 (estimated locally),0.22 per call) fci_connections_ipv4_cmd_to_5t_rep/16 (241266567 (estimated locally),0.22 per call) fci_connections_create_entry/20 (241266567 (estimated locally),0.22 per call) pfe_rtable_entry_set_out_vlan/50 (64689598 (estimated locally),0.06 per call) 
fci_connections_ipv6_cmd_to_entry.constprop.0/92 (fci_connections_ipv6_cmd_to_entry.constprop) @071d9380
  Type: function definition analyzed
  Visibility:
  References: context/48 (addr)
  Referring: 
  Clone of fci_connections_ipv6_cmd_to_entry/23
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: ipvx_ct_register_get_rtable_entries.constprop/91 (365072220 (estimated locally),0.34 per call) 
  Calls: fci_rt_db_get_first/49 (354334802 (estimated locally),0.33 per call) fci_connections_ipv6_cmd_to_5t/17 (241266567 (estimated locally),0.22 per call) fci_connections_ipv6_cmd_to_5t_rep/18 (241266567 (estimated locally),0.22 per call) fci_connections_create_entry/20 (241266567 (estimated locally),0.22 per call) pfe_rtable_entry_set_out_vlan/50 (64689598 (estimated locally),0.06 per call) 
ipvx_ct_register_get_rtable_entries.constprop.0/91 (ipvx_ct_register_get_rtable_entries.constprop) @07639ee0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of ipvx_ct_register_get_rtable_entries/26
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: ipvx_ct_register/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: fci_connections_ipv6_cmd_to_entry.constprop/92 (365072220 (estimated locally),0.34 per call) fci_connections_ipv4_cmd_to_entry.constprop/93 (708669605 (estimated locally),0.66 per call) fci_connections_ipv6_cmd_to_rep_entry/24 (285778534 (estimated locally),0.27 per call) fci_connections_ipv4_cmd_to_rep_entry/22 (554746567 (estimated locally),0.52 per call) 
fci_connections_ipvx_ct_cmd.part.0/90 (fci_connections_ipvx_ct_cmd.part.0) @071d90e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073527120 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: fci_connections_ipvx_ct_cmd/39 (536817231 (estimated locally),0.50 per call) 
  Calls: ipvx_ct_register/29 (178956971 (estimated locally),0.17 per call) ipvx_ct_deregister/30 (178956971 (estimated locally),0.17 per call) ipvx_ct_update/31 (178956971 (estimated locally),0.17 per call) ipvx_ct_query/37 (178956971 (estimated locally),0.17 per call) ipvx_ct_query_cont/38 (178956971 (estimated locally),0.17 per call) 
ipvx_ct_check_args_clear_buf.isra.0/89 (ipvx_ct_check_args_clear_buf.isra.0) @06f07540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_ipvx_ct_cmd/39 (1073634462 (estimated locally),1.00 per call) 
  Calls: autolibc_memset/47 (512926469 (estimated locally),0.48 per call) 
fci_core_client_send/88 (fci_core_client_send) @078319a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_drop_one/43 (189462819 (estimated locally),0.18 per call) fci_connections_drop_one/43 (97602058 (estimated locally),0.09 per call) 
  Calls: 
pfe_rtable_entry_get_refptr/87 (pfe_rtable_entry_get_refptr) @078318c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_drop_one/43 (354334802 (estimated locally),0.33 per call) fci_connections_drop_one/43 (182536110 (estimated locally),0.17 per call) 
  Calls: 
pfe_rtable_entry_to_5t/86 (pfe_rtable_entry_to_5t) @078317e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_drop_one/43 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_get_next/85 (pfe_rtable_get_next) @07831380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_ipv4_timeout_cmd/42 (955630225 (estimated locally),3.87 per call) fci_connections_drop_all/44 (955630223 (estimated locally),8.09 per call) ipvx_ct_query_cont/38 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_get_proto/84 (pfe_rtable_entry_get_proto) @0781b7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_ipv4_timeout_cmd/42 (955630225 (estimated locally),3.87 per call) ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_rtable_entry_get_dport/83 (pfe_rtable_entry_get_dport) @0781bee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_rtable_entry_get_sport/82 (pfe_rtable_entry_get_sport) @0781be00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_rtable_entry_get_out_vlan/81 (pfe_rtable_entry_get_out_vlan) @0781bd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_basic/34 (1073741824 (estimated locally),1.00 per call) ipvx_ct_compile_fci_reply_replydir/35 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_rtable_entry_get_route_id/80 (pfe_rtable_entry_get_route_id) @0781bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_basic/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_get_dip/79 (pfe_rtable_entry_get_dip) @0781bb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_basic/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_get_sip/78 (pfe_rtable_entry_get_sip) @0781ba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_basic/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_get_stats/77 (pfe_rtable_get_stats) @0781b9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_basic/34 (1073741824 (estimated locally),1.00 per call) ipvx_ct_compile_fci_reply_replydir/35 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_rtable_entry_get_stats_index/76 (pfe_rtable_entry_get_stats_index) @0781b8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_basic/34 (1073741824 (estimated locally),1.00 per call) ipvx_ct_compile_fci_reply_replydir/35 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_rtable_entry_to_5t_out/75 (pfe_rtable_entry_to_5t_out) @0781b700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply/36 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_get_action_flags/74 (pfe_rtable_entry_get_action_flags) @0781b620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply/36 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_remove_ttl_decrement/73 (pfe_rtable_entry_remove_ttl_decrement) @0781b380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_update/31 (287897026 (estimated locally),0.27 per call) ipvx_ct_update/31 (148310589 (estimated locally),0.14 per call) 
  Calls: 
pfe_rtable_entry_get_child/72 (pfe_rtable_entry_get_child) @0781b1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_compile_fci_reply_replydir/35 (1073741824 (estimated locally),1.00 per call) ipvx_ct_deregister/30 (574129753 (estimated locally),0.53 per call) 
  Calls: 
pfe_rtable_get_first/71 (pfe_rtable_get_first) @0781b0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_ipv4_timeout_cmd/42 (118111600 (estimated locally),0.48 per call) fci_connections_drop_all/44 (118111600 (estimated locally),1.00 per call) ipvx_ct_query/37 (1073741824 (estimated locally),1.00 per call) ipvx_ct_update/31 (1073741823 (estimated locally),1.00 per call) ipvx_ct_deregister/30 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_del_entry/70 (pfe_rtable_del_entry) @07803e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_drop_one/43 (536870912 (estimated locally),0.50 per call) ipvx_ct_deregister/30 (153493589 (estimated locally),0.14 per call) ipvx_ct_deregister/30 (574129753 (estimated locally),0.53 per call) ipvx_ct_register_add_rep_entry/28 (354334802 (estimated locally),0.33 per call) ipvx_ct_register_add_rep_entry/28 (189462819 (estimated locally),0.18 per call) ipvx_ct_register_add_entry/27 (151115544 (estimated locally),0.14 per call) ipvx_ct_register_add_entry/27 (282617438 (estimated locally),0.26 per call) ipvx_ct_register_add_entry/27 (116203862 (estimated locally),0.11 per call) ipvx_ct_register_add_entry/27 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_rtable_add_entry/69 (pfe_rtable_add_entry) @07803d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_register_add_rep_entry/28 (1073741824 (estimated locally),1.00 per call) ipvx_ct_register_add_entry/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_set_refptr/68 (pfe_rtable_entry_set_refptr) @07803c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_register_add_entry/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_set_child/67 (pfe_rtable_entry_set_child) @07803b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipvx_ct_register_add_entry/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_set_out_dport/66 (pfe_rtable_entry_set_out_dport) @07803540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: create_entry_check_nat/19 (196444236 (estimated locally),0.18 per call) 
  Calls: 
pfe_rtable_entry_set_out_sport/65 (pfe_rtable_entry_set_out_sport) @07803460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: create_entry_check_nat/19 (196444236 (estimated locally),0.18 per call) 
  Calls: 
pfe_rtable_entry_set_out_dip/64 (pfe_rtable_entry_set_out_dip) @07803380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: create_entry_check_nat/19 (189462818 (estimated locally),0.18 per call) 
  Calls: 
pfe_rtable_entry_set_out_sip/63 (pfe_rtable_entry_set_out_sip) @078032a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: create_entry_check_nat/19 (354334802 (estimated locally),0.33 per call) 
  Calls: 
autolibc_memcmp/62 (autolibc_memcmp) @078031c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: create_entry_check_nat/19 (574129754 (estimated locally),0.53 per call) create_entry_check_nat/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_set_out_mac_addrs/61 (pfe_rtable_entry_set_out_mac_addrs) @07803000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_create_entry/20 (375809638 (estimated locally),0.35 per call) 
  Calls: 
pfe_rtable_entry_set_ttl_decrement/60 (pfe_rtable_entry_set_ttl_decrement) @077f5ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_create_entry/20 (375809638 (estimated locally),0.35 per call) ipvx_ct_update/31 (287897026 (estimated locally),0.27 per call) ipvx_ct_update/31 (148310589 (estimated locally),0.14 per call) 
  Calls: 
pfe_rtable_entry_set_route_id/59 (pfe_rtable_entry_set_route_id) @077f5e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_create_entry/20 (375809638 (estimated locally),0.35 per call) 
  Calls: 
pfe_rtable_entry_set_timeout/58 (pfe_rtable_entry_set_timeout) @077f5d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_ipv4_timeout_cmd/42 (955630225 (estimated locally),3.87 per call) fci_connections_create_entry/20 (375809638 (estimated locally),0.35 per call) 
  Calls: 
pfe_rtable_entry_set_dstif/57 (pfe_rtable_entry_set_dstif) @077f5c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_create_entry/20 (375809638 (estimated locally),0.35 per call) 
  Calls: 
pfe_rtable_entry_free/56 (pfe_rtable_entry_free) @077f5b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_ipv4_timeout_cmd/42 (955630225 (estimated locally),3.87 per call) fci_connections_create_entry/20 (375809638 (estimated locally),0.35 per call) fci_connections_drop_all/44 (955630223 (estimated locally),8.09 per call) ipvx_ct_query_cont/38 (574129754 (estimated locally),0.53 per call) ipvx_ct_query/37 (574129754 (estimated locally),0.53 per call) ipvx_ct_compile_fci_reply_replydir/35 (574129754 (estimated locally),0.53 per call) ipvx_ct_update/31 (872415232 (estimated locally),0.81 per call) ipvx_ct_deregister/30 (76746795 (estimated locally),0.07 per call) ipvx_ct_deregister/30 (76746795 (estimated locally),0.07 per call) ipvx_ct_deregister/30 (287064876 (estimated locally),0.27 per call) ipvx_ct_deregister/30 (287064876 (estimated locally),0.27 per call) ipvx_ct_register_add_rep_entry/28 (354334802 (estimated locally),0.33 per call) ipvx_ct_register_add_rep_entry/28 (189462819 (estimated locally),0.18 per call) ipvx_ct_register_add_entry/27 (151115544 (estimated locally),0.14 per call) ipvx_ct_register_add_entry/27 (282617438 (estimated locally),0.26 per call) ipvx_ct_register_add_entry/27 (116203862 (estimated locally),0.11 per call) ipvx_ct_register_add_entry/27 (217325345 (estimated locally),0.20 per call) create_entry_check_nat/19 (62522730 (estimated locally),0.06 per call) create_entry_check_nat/19 (116930485 (estimated locally),0.11 per call) 
  Calls: 
pfe_rtable_entry_set_5t/55 (pfe_rtable_entry_set_5t) @077f5a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_create_entry/20 (751619277 (estimated locally),0.70 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/54 (oal_util_raise_dem_for_drv_runtime_err) @077f59a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_create_entry/20 (322122547 (estimated locally),0.30 per call) fci_connections_drop_one/43 (177167401 (estimated locally),0.17 per call) fci_connections_drop_one/43 (536870913 (estimated locally),0.50 per call) ipvx_ct_compile_fci_reply/36 (354334802 (estimated locally),0.33 per call) ipvx_ct_compile_fci_reply_basic/34 (354334802 (estimated locally),0.33 per call) ipvx_ct_compile_fci_reply_replydir/35 (189462818 (estimated locally),0.18 per call) 
  Calls: 
pfe_hm_report/53 (pfe_hm_report) @077f58c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_create_entry/20 (322122547 (estimated locally),0.30 per call) fci_connections_drop_one/43 (177167401 (estimated locally),0.17 per call) fci_connections_drop_one/43 (536870913 (estimated locally),0.50 per call) ipvx_ct_compile_fci_reply/36 (354334802 (estimated locally),0.33 per call) ipvx_ct_compile_fci_reply_basic/34 (354334802 (estimated locally),0.33 per call) ipvx_ct_compile_fci_reply_replydir/35 (189462818 (estimated locally),0.18 per call) 
  Calls: 
pfe_rtable_entry_create/52 (pfe_rtable_entry_create) @077f57e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_create_entry/20 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memcpy/51 (autolibc_memcpy) @077f5540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_drop_one/43 (189462819 (estimated locally),0.18 per call) fci_connections_drop_one/43 (189462819 (estimated locally),0.18 per call) fci_connections_drop_one/43 (97602058 (estimated locally),0.09 per call) fci_connections_drop_one/43 (97602058 (estimated locally),0.09 per call) ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) ipvx_ct_compile_fci_reply_basic/34 (365072220 (estimated locally),0.34 per call) ipvx_ct_compile_fci_reply_nat_modifications_ipv4/32 (354334802 (estimated locally),0.33 per call) ipvx_ct_compile_fci_reply_nat_modifications_ipv4/32 (354334802 (estimated locally),0.33 per call) ipvx_ct_compile_fci_reply_nat_modifications_ipv6/33 (354334802 (estimated locally),0.33 per call) ipvx_ct_compile_fci_reply_nat_modifications_ipv6/33 (354334802 (estimated locally),0.33 per call) fci_connections_ipv4_cmd_to_5t_rep/16 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv4_cmd_to_5t_rep/16 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv4_cmd_to_5t/15 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv4_cmd_to_5t/15 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv6_cmd_to_5t_rep/18 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv6_cmd_to_5t_rep/18 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv6_cmd_to_5t/17 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv6_cmd_to_5t/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_set_out_vlan/50 (pfe_rtable_entry_set_out_vlan) @077f5380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_ipv4_cmd_to_entry.constprop/93 (64689598 (estimated locally),0.06 per call) fci_connections_ipv6_cmd_to_entry.constprop/92 (64689598 (estimated locally),0.06 per call) fci_connections_ipv4_cmd_to_rep_entry/22 (64689598 (estimated locally),0.06 per call) fci_connections_ipv6_cmd_to_rep_entry/24 (64689598 (estimated locally),0.06 per call) 
  Calls: 
fci_rt_db_get_first/49 (fci_rt_db_get_first) @077f52a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_ipv4_cmd_to_entry.constprop/93 (354334802 (estimated locally),0.33 per call) fci_connections_ipv6_cmd_to_entry.constprop/92 (354334802 (estimated locally),0.33 per call) fci_connections_ipv4_cmd_to_rep_entry/22 (354334802 (estimated locally),0.33 per call) fci_connections_ipv6_cmd_to_rep_entry/24 (354334802 (estimated locally),0.33 per call) 
  Calls: 
context/48 (context) @077fb3f0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: fci_connections_set_default_timeout/45 (write)fci_connections_get_default_timeout/46 (read)fci_connections_ipv4_cmd_to_entry.constprop.0/93 (addr)fci_connections_ipv6_cmd_to_entry.constprop.0/92 (addr)fci_connections_drop_all/44 (read)fci_connections_ipv4_cmd_to_rep_entry/22 (addr)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_rep_entry/28 (read)ipvx_ct_compile_fci_reply_replydir/35 (read)ipvx_ct_update/31 (read)ipvx_ct_deregister/30 (read)ipvx_ct_compile_fci_reply_basic/34 (read)fci_connections_ipv6_cmd_to_rep_entry/24 (addr)ipvx_ct_query/37 (read)ipvx_ct_query_cont/38 (read)fci_connections_drop_one/43 (read)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_entry/27 (read)ipvx_ct_register_add_rep_entry/28 (read)ipvx_ct_register_add_rep_entry/28 (read)ipvx_ct_register_add_rep_entry/28 (read)ipvx_ct_register_add_rep_entry/28 (read)ipvx_ct_deregister/30 (read)ipvx_ct_deregister/30 (read)ipvx_ct_deregister/30 (read)ipvx_ct_deregister/30 (read)ipvx_ct_deregister/30 (read)ipvx_ct_deregister/30 (read)ipvx_ct_deregister/30 (read)ipvx_ct_update/31 (read)ipvx_ct_compile_fci_reply_replydir/35 (read)ipvx_ct_compile_fci_reply_replydir/35 (read)ipvx_ct_query/37 (read)ipvx_ct_query_cont/38 (read)fci_connections_drop_all/44 (read)fci_connections_drop_all/44 (read)fci_connections_set_default_timeout/45 (write)fci_connections_set_default_timeout/45 (write)fci_connections_get_default_timeout/46 (read)fci_connections_get_default_timeout/46 (read)fci_connections_ipv4_timeout_cmd/42 (read)fci_connections_ipv4_timeout_cmd/42 (read)fci_connections_ipv4_timeout_cmd/42 (read)
  Availability: not_available
  Varpool flags:
autolibc_memset/47 (autolibc_memset) @077e6a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_connections_ipv4_timeout_cmd/42 (118111600 (estimated locally),0.48 per call) fci_connections_drop_one/43 (536870913 (estimated locally),0.50 per call) fci_connections_ipv4_cmd_to_5t_rep/16 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv4_cmd_to_5t/15 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv6_cmd_to_5t_rep/18 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv6_cmd_to_5t/17 (1073741824 (estimated locally),1.00 per call) ipvx_ct_check_args_clear_buf.isra.0/89 (512926469 (estimated locally),0.48 per call) 
  Calls: 
fci_connections_get_default_timeout/46 (fci_connections_get_default_timeout) @077e6c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/48 (read)context/48 (read)context/48 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: fci_connections_ipv4_timeout_cmd/42 (955630225 (estimated locally),3.87 per call) fci_connections_create_entry/20 (375809638 (estimated locally),0.35 per call) 
  Calls: 
fci_connections_set_default_timeout/45 (fci_connections_set_default_timeout) @077e69a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/48 (write)context/48 (write)context/48 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: fci_connections_ipv4_timeout_cmd/42 (118111600 (estimated locally),0.48 per call) 
  Calls: 
fci_connections_drop_all/44 (fci_connections_drop_all) @077e6700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/48 (read)context/48 (read)context/48 (read)
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_rtable_get_next/85 (955630223 (estimated locally),8.09 per call) pfe_rtable_entry_free/56 (955630223 (estimated locally),8.09 per call) fci_connections_drop_one/43 (955630223 (estimated locally),8.09 per call) pfe_rtable_get_first/71 (118111600 (estimated locally),1.00 per call) 
fci_connections_drop_one/43 (fci_connections_drop_one) @077e6460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/48 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: fci_connections_drop_all/44 (955630223 (estimated locally),8.09 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/54 (177167401 (estimated locally),0.17 per call) pfe_hm_report/53 (177167401 (estimated locally),0.17 per call) pfe_rtable_del_entry/70 (536870912 (estimated locally),0.50 per call) fci_core_client_send/88 (189462819 (estimated locally),0.18 per call) autolibc_memcpy/51 (189462819 (estimated locally),0.18 per call) autolibc_memcpy/51 (189462819 (estimated locally),0.18 per call) pfe_rtable_entry_get_refptr/87 (354334802 (estimated locally),0.33 per call) fci_core_client_send/88 (97602058 (estimated locally),0.09 per call) autolibc_memcpy/51 (97602058 (estimated locally),0.09 per call) autolibc_memcpy/51 (97602058 (estimated locally),0.09 per call) pfe_rtable_entry_get_refptr/87 (182536110 (estimated locally),0.17 per call) autolibc_memset/47 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/54 (536870913 (estimated locally),0.50 per call) pfe_hm_report/53 (536870913 (estimated locally),0.50 per call) pfe_rtable_entry_to_5t/86 (1073741824 (estimated locally),1.00 per call) 
fci_connections_ipv4_timeout_cmd/42 (fci_connections_ipv4_timeout_cmd) @077e6000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/48 (read)context/48 (read)context/48 (read)
  Referring: 
  Availability: available
  Function flags: count:247250576 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_rtable_get_next/85 (955630225 (estimated locally),3.87 per call) pfe_rtable_entry_free/56 (955630225 (estimated locally),3.87 per call) pfe_rtable_entry_set_timeout/58 (955630225 (estimated locally),3.87 per call) fci_connections_get_default_timeout/46 (955630225 (estimated locally),3.87 per call) pfe_rtable_entry_get_proto/84 (955630225 (estimated locally),3.87 per call) pfe_rtable_get_first/71 (118111600 (estimated locally),0.48 per call) fci_connections_set_default_timeout/45 (118111600 (estimated locally),0.48 per call) autolibc_memset/47 (118111600 (estimated locally),0.48 per call) 
fci_connections_ipv6_ct_cmd/41 (fci_connections_ipv6_ct_cmd) @077d4a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_connections_ipvx_ct_cmd/39 (1073741824 (estimated locally),1.00 per call) 
fci_connections_ipv4_ct_cmd/40 (fci_connections_ipv4_ct_cmd) @077d4460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_connections_ipvx_ct_cmd/39 (1073741824 (estimated locally),1.00 per call) 
fci_connections_ipvx_ct_cmd/39 (fci_connections_ipvx_ct_cmd) @077d4ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073634462 (estimated locally) body local optimize_size
  Called by: fci_connections_ipv6_ct_cmd/41 (1073741824 (estimated locally),1.00 per call) fci_connections_ipv4_ct_cmd/40 (1073741824 (estimated locally),1.00 per call) 
  Calls: fci_connections_ipvx_ct_cmd.part.0/90 (536817231 (estimated locally),0.50 per call) ipvx_ct_check_args_clear_buf.isra.0/89 (1073634462 (estimated locally),1.00 per call) 
ipvx_ct_query_cont/38 (ipvx_ct_query_cont) @077d4c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (read)context/48 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_ipvx_ct_cmd.part.0/90 (178956971 (estimated locally),0.17 per call) 
  Calls: pfe_rtable_entry_free/56 (574129754 (estimated locally),0.53 per call) ipvx_ct_compile_fci_reply/36 (574129754 (estimated locally),0.53 per call) pfe_rtable_get_next/85 (1073741824 (estimated locally),1.00 per call) 
ipvx_ct_query/37 (ipvx_ct_query) @077d49a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (read)context/48 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_ipvx_ct_cmd.part.0/90 (178956971 (estimated locally),0.17 per call) 
  Calls: pfe_rtable_entry_free/56 (574129754 (estimated locally),0.53 per call) ipvx_ct_compile_fci_reply/36 (574129754 (estimated locally),0.53 per call) pfe_rtable_get_first/71 (1073741824 (estimated locally),1.00 per call) 
ipvx_ct_compile_fci_reply/36 (ipvx_ct_compile_fci_reply) @077d4700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_query_cont/38 (574129754 (estimated locally),0.53 per call) ipvx_ct_query/37 (574129754 (estimated locally),0.53 per call) 
  Calls: ipvx_ct_compile_fci_reply_nat_modifications_ipv4/32 (708669605 (estimated locally),0.66 per call) ipvx_ct_compile_fci_reply_nat_modifications_ipv6/33 (365072220 (estimated locally),0.34 per call) oal_util_raise_dem_for_drv_runtime_err/54 (354334802 (estimated locally),0.33 per call) pfe_hm_report/53 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t_out/75 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_action_flags/74 (1073741824 (estimated locally),1.00 per call) ipvx_ct_compile_fci_reply_replydir/35 (1073741824 (estimated locally),1.00 per call) ipvx_ct_compile_fci_reply_basic/34 (1073741824 (estimated locally),1.00 per call) 
ipvx_ct_compile_fci_reply_replydir/35 (ipvx_ct_compile_fci_reply_replydir) @077d4380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (read)context/48 (read)context/48 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_compile_fci_reply/36 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_rtable_entry_free/56 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_get_out_vlan/81 (574129754 (estimated locally),0.53 per call) oal_util_raise_dem_for_drv_runtime_err/54 (189462818 (estimated locally),0.18 per call) pfe_hm_report/53 (189462818 (estimated locally),0.18 per call) pfe_rtable_get_stats/77 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_get_stats_index/76 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_get_child/72 (1073741824 (estimated locally),1.00 per call) 
ipvx_ct_compile_fci_reply_basic/34 (ipvx_ct_compile_fci_reply_basic) @077d4000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_compile_fci_reply/36 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_rtable_entry_get_proto/84 (708669605 (estimated locally),0.66 per call) pfe_rtable_entry_get_proto/84 (708669605 (estimated locally),0.66 per call) autolibc_memcpy/51 (708669605 (estimated locally),0.66 per call) autolibc_memcpy/51 (708669605 (estimated locally),0.66 per call) pfe_rtable_entry_get_dport/83 (708669605 (estimated locally),0.66 per call) pfe_rtable_entry_get_dport/83 (708669605 (estimated locally),0.66 per call) pfe_rtable_entry_get_sport/82 (708669605 (estimated locally),0.66 per call) pfe_rtable_entry_get_sport/82 (708669605 (estimated locally),0.66 per call) autolibc_memcpy/51 (708669605 (estimated locally),0.66 per call) autolibc_memcpy/51 (708669605 (estimated locally),0.66 per call) pfe_rtable_entry_get_proto/84 (365072220 (estimated locally),0.34 per call) pfe_rtable_entry_get_proto/84 (365072220 (estimated locally),0.34 per call) autolibc_memcpy/51 (365072220 (estimated locally),0.34 per call) autolibc_memcpy/51 (365072220 (estimated locally),0.34 per call) pfe_rtable_entry_get_dport/83 (365072220 (estimated locally),0.34 per call) pfe_rtable_entry_get_dport/83 (365072220 (estimated locally),0.34 per call) pfe_rtable_entry_get_sport/82 (365072220 (estimated locally),0.34 per call) pfe_rtable_entry_get_sport/82 (365072220 (estimated locally),0.34 per call) autolibc_memcpy/51 (365072220 (estimated locally),0.34 per call) autolibc_memcpy/51 (365072220 (estimated locally),0.34 per call) pfe_rtable_entry_get_out_vlan/81 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_route_id/80 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_dip/79 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_sip/78 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/54 (354334802 (estimated locally),0.33 per call) pfe_hm_report/53 (354334802 (estimated locally),0.33 per call) pfe_rtable_get_stats/77 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_stats_index/76 (1073741824 (estimated locally),1.00 per call) 
ipvx_ct_compile_fci_reply_nat_modifications_ipv6/33 (ipvx_ct_compile_fci_reply_nat_modifications_ipv6) @076fa7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_compile_fci_reply/36 (365072220 (estimated locally),0.34 per call) 
  Calls: autolibc_memcpy/51 (354334802 (estimated locally),0.33 per call) autolibc_memcpy/51 (354334802 (estimated locally),0.33 per call) 
ipvx_ct_compile_fci_reply_nat_modifications_ipv4/32 (ipvx_ct_compile_fci_reply_nat_modifications_ipv4) @076fa2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_compile_fci_reply/36 (708669605 (estimated locally),0.66 per call) 
  Calls: autolibc_memcpy/51 (354334802 (estimated locally),0.33 per call) autolibc_memcpy/51 (354334802 (estimated locally),0.33 per call) 
ipvx_ct_update/31 (ipvx_ct_update) @076faee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (read)context/48 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: fci_connections_ipvx_ct_cmd.part.0/90 (178956971 (estimated locally),0.17 per call) 
  Calls: pfe_rtable_entry_free/56 (872415232 (estimated locally),0.81 per call) pfe_rtable_entry_remove_ttl_decrement/73 (287897026 (estimated locally),0.27 per call) pfe_rtable_entry_set_ttl_decrement/60 (287897026 (estimated locally),0.27 per call) pfe_rtable_entry_remove_ttl_decrement/73 (148310589 (estimated locally),0.14 per call) pfe_rtable_entry_set_ttl_decrement/60 (148310589 (estimated locally),0.14 per call) pfe_rtable_get_first/71 (1073741823 (estimated locally),1.00 per call) fci_connections_ipv4_cmd_to_5t/15 (708669604 (estimated locally),0.66 per call) fci_connections_ipv6_cmd_to_5t/17 (365072220 (estimated locally),0.34 per call) 
ipvx_ct_deregister/30 (ipvx_ct_deregister) @076fac40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: fci_connections_ipvx_ct_cmd.part.0/90 (178956971 (estimated locally),0.17 per call) 
  Calls: pfe_rtable_entry_free/56 (76746795 (estimated locally),0.07 per call) pfe_rtable_entry_free/56 (76746795 (estimated locally),0.07 per call) pfe_rtable_del_entry/70 (153493589 (estimated locally),0.14 per call) pfe_rtable_entry_free/56 (287064876 (estimated locally),0.27 per call) pfe_rtable_entry_free/56 (287064876 (estimated locally),0.27 per call) pfe_rtable_del_entry/70 (574129753 (estimated locally),0.53 per call) pfe_rtable_entry_get_child/72 (574129753 (estimated locally),0.53 per call) pfe_rtable_get_first/71 (1073741823 (estimated locally),1.00 per call) fci_connections_ipv4_cmd_to_5t/15 (708669604 (estimated locally),0.66 per call) fci_connections_ipv6_cmd_to_5t/17 (365072220 (estimated locally),0.34 per call) 
ipvx_ct_register/29 (ipvx_ct_register) @076fa9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_ipvx_ct_cmd.part.0/90 (178956971 (estimated locally),0.17 per call) 
  Calls: ipvx_ct_register_add_rep_entry/28 (287064877 (estimated locally),0.27 per call) ipvx_ct_register_add_entry/27 (287064877 (estimated locally),0.27 per call) ipvx_ct_register_get_rtable_entries.constprop/91 (1073741824 (estimated locally),1.00 per call) 
ipvx_ct_register_add_rep_entry/28 (ipvx_ct_register_add_rep_entry) @076fa700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_register/29 (287064877 (estimated locally),0.27 per call) 
  Calls: pfe_rtable_entry_free/56 (354334802 (estimated locally),0.33 per call) pfe_rtable_del_entry/70 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_free/56 (189462819 (estimated locally),0.18 per call) pfe_rtable_del_entry/70 (189462819 (estimated locally),0.18 per call) pfe_rtable_add_entry/69 (1073741824 (estimated locally),1.00 per call) 
ipvx_ct_register_add_entry/27 (ipvx_ct_register_add_entry) @076fa460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)context/48 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_register/29 (287064877 (estimated locally),0.27 per call) 
  Calls: pfe_rtable_entry_free/56 (151115544 (estimated locally),0.14 per call) pfe_rtable_del_entry/70 (151115544 (estimated locally),0.14 per call) pfe_rtable_entry_free/56 (282617438 (estimated locally),0.26 per call) pfe_rtable_del_entry/70 (282617438 (estimated locally),0.26 per call) pfe_rtable_entry_free/56 (116203862 (estimated locally),0.11 per call) pfe_rtable_del_entry/70 (116203862 (estimated locally),0.11 per call) pfe_rtable_entry_free/56 (217325345 (estimated locally),0.20 per call) pfe_rtable_del_entry/70 (217325345 (estimated locally),0.20 per call) pfe_rtable_add_entry/69 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_set_refptr/68 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_set_child/67 (1073741824 (estimated locally),1.00 per call) 
ipvx_ct_register_get_rtable_entries/26 (ipvx_ct_register_get_rtable_entries) @076fa1c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fci_connections_ipv6_cmd_to_rep_entry/24 (fci_connections_ipv6_cmd_to_rep_entry) @076399a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_register_get_rtable_entries.constprop/91 (285778534 (estimated locally),0.27 per call) 
  Calls: pfe_rtable_entry_set_out_vlan/50 (64689598 (estimated locally),0.06 per call) fci_connections_create_entry/20 (241266567 (estimated locally),0.22 per call) fci_connections_ipv6_cmd_to_5t_rep/18 (241266567 (estimated locally),0.22 per call) fci_connections_ipv6_cmd_to_5t/17 (241266567 (estimated locally),0.22 per call) fci_rt_db_get_first/49 (354334802 (estimated locally),0.33 per call) 
fci_connections_ipv6_cmd_to_entry/23 (fci_connections_ipv6_cmd_to_entry) @07639380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fci_connections_ipv4_cmd_to_rep_entry/22 (fci_connections_ipv4_cmd_to_rep_entry) @07639e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/48 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipvx_ct_register_get_rtable_entries.constprop/91 (554746567 (estimated locally),0.52 per call) 
  Calls: pfe_rtable_entry_set_out_vlan/50 (64689598 (estimated locally),0.06 per call) fci_connections_create_entry/20 (241266567 (estimated locally),0.22 per call) fci_connections_ipv4_cmd_to_5t_rep/16 (241266567 (estimated locally),0.22 per call) fci_connections_ipv4_cmd_to_5t/15 (241266567 (estimated locally),0.22 per call) fci_rt_db_get_first/49 (354334802 (estimated locally),0.33 per call) 
fci_connections_ipv4_cmd_to_entry/21 (fci_connections_ipv4_cmd_to_entry) @07639b60
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fci_connections_create_entry/20 (fci_connections_create_entry) @076398c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: fci_connections_ipv4_cmd_to_entry.constprop/93 (241266567 (estimated locally),0.22 per call) fci_connections_ipv6_cmd_to_entry.constprop/92 (241266567 (estimated locally),0.22 per call) fci_connections_ipv4_cmd_to_rep_entry/22 (241266567 (estimated locally),0.22 per call) fci_connections_ipv6_cmd_to_rep_entry/24 (241266567 (estimated locally),0.22 per call) 
  Calls: create_entry_check_nat/19 (375809638 (estimated locally),0.35 per call) pfe_rtable_entry_set_out_mac_addrs/61 (375809638 (estimated locally),0.35 per call) pfe_rtable_entry_set_ttl_decrement/60 (375809638 (estimated locally),0.35 per call) pfe_rtable_entry_set_route_id/59 (375809638 (estimated locally),0.35 per call) pfe_rtable_entry_set_timeout/58 (375809638 (estimated locally),0.35 per call) fci_connections_get_default_timeout/46 (375809638 (estimated locally),0.35 per call) pfe_rtable_entry_set_dstif/57 (375809638 (estimated locally),0.35 per call) pfe_rtable_entry_free/56 (375809638 (estimated locally),0.35 per call) pfe_rtable_entry_set_5t/55 (751619277 (estimated locally),0.70 per call) oal_util_raise_dem_for_drv_runtime_err/54 (322122547 (estimated locally),0.30 per call) pfe_hm_report/53 (322122547 (estimated locally),0.30 per call) pfe_rtable_entry_create/52 (1073741823 (estimated locally),1.00 per call) 
create_entry_check_nat/19 (create_entry_check_nat) @07639540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_create_entry/20 (375809638 (estimated locally),0.35 per call) 
  Calls: pfe_rtable_entry_set_out_dport/66 (196444236 (estimated locally),0.18 per call) pfe_rtable_entry_set_out_sport/65 (196444236 (estimated locally),0.18 per call) pfe_rtable_entry_free/56 (62522730 (estimated locally),0.06 per call) pfe_rtable_entry_set_out_dip/64 (189462818 (estimated locally),0.18 per call) autolibc_memcmp/62 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_free/56 (116930485 (estimated locally),0.11 per call) pfe_rtable_entry_set_out_sip/63 (354334802 (estimated locally),0.33 per call) autolibc_memcmp/62 (1073741824 (estimated locally),1.00 per call) 
fci_connections_ipv6_cmd_to_5t_rep/18 (fci_connections_ipv6_cmd_to_5t_rep) @076392a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_ipv6_cmd_to_entry.constprop/92 (241266567 (estimated locally),0.22 per call) fci_connections_ipv6_cmd_to_rep_entry/24 (241266567 (estimated locally),0.22 per call) 
  Calls: autolibc_memcpy/51 (1073741824 (estimated locally),1.00 per call) autolibc_memcpy/51 (1073741824 (estimated locally),1.00 per call) autolibc_memset/47 (1073741824 (estimated locally),1.00 per call) 
fci_connections_ipv6_cmd_to_5t/17 (fci_connections_ipv6_cmd_to_5t) @07639000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_ipv6_cmd_to_entry.constprop/92 (241266567 (estimated locally),0.22 per call) fci_connections_ipv6_cmd_to_rep_entry/24 (241266567 (estimated locally),0.22 per call) ipvx_ct_update/31 (365072220 (estimated locally),0.34 per call) ipvx_ct_deregister/30 (365072220 (estimated locally),0.34 per call) 
  Calls: autolibc_memcpy/51 (1073741824 (estimated locally),1.00 per call) autolibc_memcpy/51 (1073741824 (estimated locally),1.00 per call) autolibc_memset/47 (1073741824 (estimated locally),1.00 per call) 
fci_connections_ipv4_cmd_to_5t_rep/16 (fci_connections_ipv4_cmd_to_5t_rep) @077ccb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_ipv4_cmd_to_entry.constprop/93 (241266567 (estimated locally),0.22 per call) fci_connections_ipv4_cmd_to_rep_entry/22 (241266567 (estimated locally),0.22 per call) 
  Calls: autolibc_memcpy/51 (1073741824 (estimated locally),1.00 per call) autolibc_memcpy/51 (1073741824 (estimated locally),1.00 per call) autolibc_memset/47 (1073741824 (estimated locally),1.00 per call) 
fci_connections_ipv4_cmd_to_5t/15 (fci_connections_ipv4_cmd_to_5t) @077ccd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_connections_ipv4_cmd_to_entry.constprop/93 (241266567 (estimated locally),0.22 per call) fci_connections_ipv4_cmd_to_rep_entry/22 (241266567 (estimated locally),0.22 per call) ipvx_ct_update/31 (708669604 (estimated locally),0.66 per call) ipvx_ct_deregister/30 (708669604 (estimated locally),0.66 per call) 
  Calls: autolibc_memcpy/51 (1073741824 (estimated locally),1.00 per call) autolibc_memcpy/51 (1073741824 (estimated locally),1.00 per call) autolibc_memset/47 (1073741824 (estimated locally),1.00 per call) 

;; Function fci_connections_ipv6_cmd_to_5t (fci_connections_ipv6_cmd_to_5t, funcdef_no=14, decl_uid=12335, cgraph_uid=15, symbol_order=17)

Modification phase of node fci_connections_ipv6_cmd_to_5t/17
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
fci_connections_ipv6_cmd_to_5t (const struct fpp_ct6_cmd_t * ct6_cmd, struct pfe_5_tuple_t * tuple)
{
  union 
{
  uint16_t v6[8];
} * _1;
  const uint32_t * _2;
  union 
{
  uint16_t v6[8];
} * _3;
  const uint32_t * _4;
  short unsigned int _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  unsigned char _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  autolibc_memset (tuple_13(D), 0, 50);
  # DEBUG BEGIN_STMT
  _1 = &tuple_13(D)->src_ip.v6;
  _2 = &ct6_cmd_15(D)->saddr[0];
  autolibc_memcpy (_1, _2, 16);
  # DEBUG BEGIN_STMT
  _3 = &tuple_13(D)->dst_ip.v6;
  _4 = &ct6_cmd_15(D)->daddr[0];
  autolibc_memcpy (_3, _4, 16);
  # DEBUG BEGIN_STMT
  tuple_13(D)->src_ip.is_ipv4 = 0;
  # DEBUG BEGIN_STMT
  tuple_13(D)->dst_ip.is_ipv4 = 0;
  # DEBUG BEGIN_STMT
  _5 = ct6_cmd_15(D)->sport;
  _6 = _5 r>> 8;
  tuple_13(D)->sport = _6;
  # DEBUG BEGIN_STMT
  _7 = ct6_cmd_15(D)->dport;
  _8 = _7 r>> 8;
  tuple_13(D)->dport = _8;
  # DEBUG BEGIN_STMT
  _9 = ct6_cmd_15(D)->protocol;
  _10 = _9 >> 8;
  _11 = (unsigned char) _10;
  tuple_13(D)->proto = _11;
  return;

}



;; Function fci_connections_ipv6_cmd_to_5t_rep (fci_connections_ipv6_cmd_to_5t_rep, funcdef_no=15, decl_uid=12338, cgraph_uid=16, symbol_order=18)

Modification phase of node fci_connections_ipv6_cmd_to_5t_rep/18
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
fci_connections_ipv6_cmd_to_5t_rep (const struct fpp_ct6_cmd_t * ct6_cmd, struct pfe_5_tuple_t * tuple)
{
  union 
{
  uint16_t v6[8];
} * _1;
  const uint32_t * _2;
  union 
{
  uint16_t v6[8];
} * _3;
  const uint32_t * _4;
  short unsigned int _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  unsigned char _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  autolibc_memset (tuple_13(D), 0, 50);
  # DEBUG BEGIN_STMT
  _1 = &tuple_13(D)->src_ip.v6;
  _2 = &ct6_cmd_15(D)->saddr_reply[0];
  autolibc_memcpy (_1, _2, 16);
  # DEBUG BEGIN_STMT
  _3 = &tuple_13(D)->dst_ip.v6;
  _4 = &ct6_cmd_15(D)->daddr_reply[0];
  autolibc_memcpy (_3, _4, 16);
  # DEBUG BEGIN_STMT
  tuple_13(D)->src_ip.is_ipv4 = 0;
  # DEBUG BEGIN_STMT
  tuple_13(D)->dst_ip.is_ipv4 = 0;
  # DEBUG BEGIN_STMT
  _5 = ct6_cmd_15(D)->sport_reply;
  _6 = _5 r>> 8;
  tuple_13(D)->sport = _6;
  # DEBUG BEGIN_STMT
  _7 = ct6_cmd_15(D)->dport_reply;
  _8 = _7 r>> 8;
  tuple_13(D)->dport = _8;
  # DEBUG BEGIN_STMT
  _9 = ct6_cmd_15(D)->protocol;
  _10 = _9 >> 8;
  _11 = (unsigned char) _10;
  tuple_13(D)->proto = _11;
  return;

}



;; Function fci_connections_ipv4_cmd_to_5t (fci_connections_ipv4_cmd_to_5t, funcdef_no=12, decl_uid=12329, cgraph_uid=13, symbol_order=15)

Modification phase of node fci_connections_ipv4_cmd_to_5t/15
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
fci_connections_ipv4_cmd_to_5t (const struct fpp_ct_cmd_t * ct_cmd, struct pfe_5_tuple_t * tuple)
{
  union 
{
  uint8_t v4[4];
} * _1;
  const uint32_t * _2;
  union 
{
  uint8_t v4[4];
} * _3;
  const uint32_t * _4;
  short unsigned int _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  unsigned char _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  autolibc_memset (tuple_13(D), 0, 50);
  # DEBUG BEGIN_STMT
  _1 = &tuple_13(D)->src_ip.v4;
  _2 = &ct_cmd_15(D)->saddr;
  autolibc_memcpy (_1, _2, 4);
  # DEBUG BEGIN_STMT
  _3 = &tuple_13(D)->dst_ip.v4;
  _4 = &ct_cmd_15(D)->daddr;
  autolibc_memcpy (_3, _4, 4);
  # DEBUG BEGIN_STMT
  tuple_13(D)->src_ip.is_ipv4 = 1;
  # DEBUG BEGIN_STMT
  tuple_13(D)->dst_ip.is_ipv4 = 1;
  # DEBUG BEGIN_STMT
  _5 = ct_cmd_15(D)->sport;
  _6 = _5 r>> 8;
  tuple_13(D)->sport = _6;
  # DEBUG BEGIN_STMT
  _7 = ct_cmd_15(D)->dport;
  _8 = _7 r>> 8;
  tuple_13(D)->dport = _8;
  # DEBUG BEGIN_STMT
  _9 = ct_cmd_15(D)->protocol;
  _10 = _9 >> 8;
  _11 = (unsigned char) _10;
  tuple_13(D)->proto = _11;
  return;

}



;; Function fci_connections_ipv4_cmd_to_5t_rep (fci_connections_ipv4_cmd_to_5t_rep, funcdef_no=13, decl_uid=12332, cgraph_uid=14, symbol_order=16)

Modification phase of node fci_connections_ipv4_cmd_to_5t_rep/16
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
fci_connections_ipv4_cmd_to_5t_rep (const struct fpp_ct_cmd_t * ct_cmd, struct pfe_5_tuple_t * tuple)
{
  union 
{
  uint8_t v4[4];
} * _1;
  const uint32_t * _2;
  union 
{
  uint8_t v4[4];
} * _3;
  const uint32_t * _4;
  short unsigned int _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  unsigned char _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  autolibc_memset (tuple_13(D), 0, 50);
  # DEBUG BEGIN_STMT
  _1 = &tuple_13(D)->src_ip.v4;
  _2 = &ct_cmd_15(D)->saddr_reply;
  autolibc_memcpy (_1, _2, 4);
  # DEBUG BEGIN_STMT
  _3 = &tuple_13(D)->dst_ip.v4;
  _4 = &ct_cmd_15(D)->daddr_reply;
  autolibc_memcpy (_3, _4, 4);
  # DEBUG BEGIN_STMT
  tuple_13(D)->src_ip.is_ipv4 = 1;
  # DEBUG BEGIN_STMT
  tuple_13(D)->dst_ip.is_ipv4 = 1;
  # DEBUG BEGIN_STMT
  _5 = ct_cmd_15(D)->sport_reply;
  _6 = _5 r>> 8;
  tuple_13(D)->sport = _6;
  # DEBUG BEGIN_STMT
  _7 = ct_cmd_15(D)->dport_reply;
  _8 = _7 r>> 8;
  tuple_13(D)->dport = _8;
  # DEBUG BEGIN_STMT
  _9 = ct_cmd_15(D)->protocol;
  _10 = _9 >> 8;
  _11 = (unsigned char) _10;
  tuple_13(D)->proto = _11;
  return;

}



;; Function ipvx_ct_compile_fci_reply (ipvx_ct_compile_fci_reply, funcdef_no=33, decl_uid=12421, cgraph_uid=34, symbol_order=36)

Modification phase of node ipvx_ct_compile_fci_reply/36
Adjusting mask for param 0 to 0x1
Setting value range of param 0 [0, 1]
ipvx_ct_compile_fci_reply (bool_t ipv6, struct pfe_rtable_entry_t * entry, void * reply_buf, uint32_t * reply_len)
{
  const pfe_ct_route_actions_t actions;
  struct pfe_5_tuple_t tuple;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ct6_reply => reply_buf_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG ct_reply => reply_buf_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipv6_6(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  *reply_len_8(D) = 112;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  *reply_len_8(D) = 64;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ipvx_ct_compile_fci_reply_basic (ipv6_6(D), reply_buf_5(D), entry_11(D));
  # DEBUG BEGIN_STMT
  ipvx_ct_compile_fci_reply_replydir (ipv6_6(D), reply_buf_5(D), entry_11(D));
  # DEBUG BEGIN_STMT
  actions_15 = pfe_rtable_entry_get_action_flags (entry_11(D));
  # DEBUG actions => actions_15
  # DEBUG BEGIN_STMT
  _1 = pfe_rtable_entry_to_5t_out (entry_11(D), &tuple);
  if (_1 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get output tuple\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_connections.c", 1462, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipv6_6(D) == 1)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  ipvx_ct_compile_fci_reply_nat_modifications_ipv6 (reply_buf_5(D), actions_15, &tuple);
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  ipvx_ct_compile_fci_reply_nat_modifications_ipv4 (reply_buf_5(D), actions_15, &tuple);

  <bb 10> [local count: 1073741824]:
  tuple ={v} {CLOBBER};
  return;

}



;; Function fci_connections_drop_one (fci_connections_drop_one, funcdef_no=40, decl_uid=12220, cgraph_uid=41, symbol_order=43)

Modification phase of node fci_connections_drop_one/43
fci_connections_drop_one (struct pfe_rtable_entry_t * entry)
{
  errno_t ret;
  struct pfe_5_tuple_t tuple;
  struct fci_core_client_t * client;
  struct fci_msg_t msg;
  unsigned char _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  unsigned char _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  unsigned char _13;
  short unsigned int _14;
  short unsigned int _15;
  struct pfe_rtable_t * _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG ct_cmd => 0B
  # DEBUG BEGIN_STMT
  # DEBUG ct6_cmd => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tuple = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_24 = pfe_rtable_entry_to_5t (entry_22(D), &tuple);
  # DEBUG ret => ret_24
  # DEBUG BEGIN_STMT
  if (ret_24 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t convert entry to 5 tuple: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_connections.c", 1765, ret_24, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  autolibc_memset (&msg, 0, 276);
  # DEBUG BEGIN_STMT
  msg.type = 4099;
  # DEBUG BEGIN_STMT
  _1 = tuple.src_ip.is_ipv4;
  if (_1 == 1)
    goto <bb 5>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 5> [local count: 182536110]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_38 = pfe_rtable_entry_get_refptr (entry_22(D));
  # DEBUG client => client_38
  # DEBUG BEGIN_STMT
  if (client_38 != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 6> [local count: 97602058]:
  # DEBUG BEGIN_STMT
  msg.msg_cmd.code = 788;
  # DEBUG BEGIN_STMT
  # DEBUG ct_cmd => &msg.msg_cmd.payload
  # DEBUG BEGIN_STMT
  MEM[(struct fpp_ct_cmd_t *)&msg + 16B].action = 3;
  # DEBUG BEGIN_STMT
  autolibc_memcpy (&MEM[(struct fpp_ct_cmd_t *)&msg + 16B].saddr, &tuple.src_ip.v4, 4);
  # DEBUG BEGIN_STMT
  autolibc_memcpy (&MEM[(struct fpp_ct_cmd_t *)&msg + 16B].daddr, &tuple.dst_ip.v4, 4);
  # DEBUG BEGIN_STMT
  _2 = tuple.sport;
  _3 = _2 r>> 8;
  MEM[(struct fpp_ct_cmd_t *)&msg + 16B].sport = _3;
  # DEBUG BEGIN_STMT
  _4 = tuple.dport;
  _5 = _4 r>> 8;
  MEM[(struct fpp_ct_cmd_t *)&msg + 16B].dport = _5;
  # DEBUG BEGIN_STMT
  _6 = tuple.proto;
  _7 = (short unsigned int) _6;
  _8 = _7 << 8;
  MEM[(struct fpp_ct_cmd_t *)&msg + 16B].protocol = _8;
  # DEBUG BEGIN_STMT
  fci_core_client_send (client_38, &msg, 0B);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_28 = pfe_rtable_entry_get_refptr (entry_22(D));
  # DEBUG client => client_28
  # DEBUG BEGIN_STMT
  if (client_28 != 0B)
    goto <bb 8>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 8> [local count: 189462819]:
  # DEBUG BEGIN_STMT
  msg.msg_cmd.code = 1044;
  # DEBUG BEGIN_STMT
  # DEBUG ct6_cmd => &msg.msg_cmd.payload
  # DEBUG BEGIN_STMT
  MEM[(struct fpp_ct6_cmd_t *)&msg + 16B].action = 3;
  # DEBUG BEGIN_STMT
  autolibc_memcpy (&MEM[(struct fpp_ct6_cmd_t *)&msg + 16B].saddr[0], &tuple.src_ip.v6, 16);
  # DEBUG BEGIN_STMT
  autolibc_memcpy (&MEM[(struct fpp_ct6_cmd_t *)&msg + 16B].daddr[0], &tuple.dst_ip.v6, 16);
  # DEBUG BEGIN_STMT
  _9 = tuple.sport;
  _10 = _9 r>> 8;
  MEM[(struct fpp_ct6_cmd_t *)&msg + 16B].sport = _10;
  # DEBUG BEGIN_STMT
  _11 = tuple.dport;
  _12 = _11 r>> 8;
  MEM[(struct fpp_ct6_cmd_t *)&msg + 16B].dport = _12;
  # DEBUG BEGIN_STMT
  _13 = tuple.proto;
  _14 = (short unsigned int) _13;
  _15 = _14 << 8;
  MEM[(struct fpp_ct6_cmd_t *)&msg + 16B].protocol = _15;
  # DEBUG BEGIN_STMT
  fci_core_client_send (client_28, &msg, 0B);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 536870912]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = context.rtable;
  ret_48 = pfe_rtable_del_entry (_16, entry_22(D));
  # DEBUG ret => ret_48
  # DEBUG BEGIN_STMT
  if (ret_48 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Fatal: Can\'t remove rtable entry = memory leak\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_connections.c", 1839, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  # ret_17 = PHI <ret_24(3), ret_48(9), ret_48(10)>
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  msg ={v} {CLOBBER};
  tuple ={v} {CLOBBER};
  return ret_17;

}



;; Function fci_connections_drop_all (fci_connections_drop_all, funcdef_no=41, decl_uid=12233, cgraph_uid=42, symbol_order=44)

Modification phase of node fci_connections_drop_all/44
fci_connections_drop_all ()
{
  struct pfe_rtable_entry_t * entry;
  struct pfe_rtable_t * _1;
  struct pfe_rtable_t * _2;
  struct pfe_rtable_t * _3;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = context.rtable;
  entry_8 = pfe_rtable_get_first (_1, 0, 0B);
  # DEBUG entry => entry_8
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  fci_connections_drop_one (entry_4);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = context.rtable;
  pfe_rtable_entry_free (_2, entry_4);
  # DEBUG BEGIN_STMT
  _3 = context.rtable;
  entry_12 = pfe_rtable_get_next (_3);
  # DEBUG entry => entry_12

  <bb 4> [local count: 1073741824]:
  # entry_4 = PHI <entry_8(2), entry_12(3)>
  # DEBUG entry => entry_4
  # DEBUG BEGIN_STMT
  if (entry_4 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  return;

}



;; Function fci_connections_set_default_timeout (fci_connections_set_default_timeout, funcdef_no=42, decl_uid=12223, cgraph_uid=43, symbol_order=45)

Modification phase of node fci_connections_set_default_timeout/45
fci_connections_set_default_timeout (uint8_t ip_proto, uint32_t timeout)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  switch (ip_proto_2(D)) <default: <L2> [33.33%], case 6: <L0> [33.33%], case 17: <L1> [33.33%]>

  <bb 3> [local count: 357878150]:
<L0>:
  # DEBUG BEGIN_STMT
  context.default_timeouts.timeout_tcp = timeout_4(D);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  context.default_timeouts.timeout_udp = timeout_4(D);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 357878150]:
<L2>:
  # DEBUG BEGIN_STMT
  context.default_timeouts.timeout_other = timeout_4(D);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073634451]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function fci_connections_get_default_timeout (fci_connections_get_default_timeout, funcdef_no=43, decl_uid=12225, cgraph_uid=44, symbol_order=46)

Modification phase of node fci_connections_get_default_timeout/46
fci_connections_get_default_timeout (uint8_t ip_proto)
{
  uint32_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  switch (ip_proto_2(D)) <default: <L2> [33.33%], case 6: <L0> [33.33%], case 17: <L1> [33.33%]>

  <bb 3> [local count: 357878150]:
<L0>:
  # DEBUG BEGIN_STMT
  ret_5 = context.default_timeouts.timeout_tcp;
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  ret_4 = context.default_timeouts.timeout_udp;
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 357878150]:
<L2>:
  # DEBUG BEGIN_STMT
  ret_6 = context.default_timeouts.timeout_other;
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073634451]:
  # ret_1 = PHI <ret_5(3), ret_4(4), ret_6(5)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function fci_connections_create_entry (fci_connections_create_entry, funcdef_no=17, decl_uid=12342, cgraph_uid=18, symbol_order=20)

Modification phase of node fci_connections_create_entry/20
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 2 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
Setting nonnull for 2
fci_connections_create_entry (const struct fci_rt_db_entry_t * route, const struct pfe_5_tuple_t * tuple, const struct pfe_5_tuple_t * tuple_rep)
{
  struct pfe_rtable_entry_t * new_entry;
  struct pfe_rtable_entry_t * _1;
  int _2;
  struct pfe_rtable_entry_t * new_entry.5_3;
  struct pfe_rtable_entry_t * new_entry.6_4;
  struct pfe_phy_if_t * _5;
  struct pfe_rtable_entry_t * new_entry.7_6;
  unsigned char _7;
  long unsigned int _8;
  struct pfe_rtable_entry_t * new_entry.8_9;
  long unsigned int _10;
  struct pfe_rtable_entry_t * new_entry.9_11;
  struct pfe_rtable_entry_t * new_entry.10_12;
  const uint8_t[6] * _13;
  const uint8_t[6] * _14;
  struct pfe_rtable_entry_t * _33;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_rtable_entry_create ();
  new_entry = _1;
  # DEBUG BEGIN_STMT
  if (_1 == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create routing table entry\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_connections.c", 553, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 751619277]:
  # DEBUG BEGIN_STMT
  _2 = pfe_rtable_entry_set_5t (_1, tuple_19(D));
  if (_2 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  new_entry.5_3 = new_entry;
  pfe_rtable_entry_free (0B, new_entry.5_3);
  # DEBUG BEGIN_STMT
  new_entry = 0B;
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  new_entry.6_4 = new_entry;
  _5 = route_21(D)->iface;
  pfe_rtable_entry_set_dstif (new_entry.6_4, _5);
  # DEBUG BEGIN_STMT
  new_entry.7_6 = new_entry;
  _7 = tuple_19(D)->proto;
  _8 = fci_connections_get_default_timeout (_7);
  pfe_rtable_entry_set_timeout (new_entry.7_6, _8);
  # DEBUG BEGIN_STMT
  new_entry.8_9 = new_entry;
  _10 = route_21(D)->id;
  pfe_rtable_entry_set_route_id (new_entry.8_9, _10);
  # DEBUG BEGIN_STMT
  new_entry.9_11 = new_entry;
  pfe_rtable_entry_set_ttl_decrement (new_entry.9_11);
  # DEBUG BEGIN_STMT
  new_entry.10_12 = new_entry;
  _13 = &route_21(D)->src_mac;
  _14 = &route_21(D)->dst_mac;
  pfe_rtable_entry_set_out_mac_addrs (new_entry.10_12, _13, _14);
  # DEBUG BEGIN_STMT
  create_entry_check_nat (&new_entry, tuple_19(D), tuple_rep_27(D));

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _33 = new_entry;
  new_entry ={v} {CLOBBER};
  return _33;

}



;; Function fci_connections_ipvx_ct_cmd.part.0 (fci_connections_ipvx_ct_cmd.part.0, funcdef_no=45, decl_uid=13076, cgraph_uid=87, symbol_order=90)

Modification phase of node fci_connections_ipvx_ct_cmd.part.0/90
Adjusting mask for param 0 to 0x1
Setting value range of param 0 [0, 1]
fci_connections_ipvx_ct_cmd.part.0 (bool_t ipv6, const struct fci_msg_t * msg, uint16_t * fci_ret, void * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  struct fpp_ct_cmd_t * ct_cmd;
  short unsigned int _2;

  <bb 10> [local count: 1073527120]:

  <bb 2> [local count: 1073527120]:
  # DEBUG BEGIN_STMT
  # DEBUG D#3 => &msg_1(D)->msg_cmd.payload
  # DEBUG ct_cmd => D#3
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_ct_cmd_t *)msg_1(D) + 16B].action;
  switch (_2) <default: <L5> [16.67%], case 0: <L0> [16.67%], case 1: <L1> [16.67%], case 4: <L2> [16.67%], case 6: <L3> [16.67%], case 7: <L4> [16.67%]>

  <bb 3> [local count: 178956971]:
<L0>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_5 = ipvx_ct_register (ipv6_3(D), msg_1(D), fci_ret_4(D));
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 4> [local count: 178956971]:
<L1>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_6 = ipvx_ct_deregister (ipv6_3(D), msg_1(D), fci_ret_4(D));
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 178956971]:
<L2>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_7 = ipvx_ct_update (ipv6_3(D), msg_1(D), fci_ret_4(D));
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 178956971]:
<L3>:
  # DEBUG BEGIN_STMT
  ipvx_ct_query (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 178956971]:
<L4>:
  # DEBUG BEGIN_STMT
  ipvx_ct_query_cont (ipv6_3(D), fci_ret_4(D), reply_buf_8(D), reply_len_9(D));
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 178956971]:
<L5>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_4(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  # ret_10 = PHI <ret_5(3), ret_6(4), ret_7(5), 0(6), 0(7), 0(8)>
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  return ret_10;

}



;; Function fci_connections_ipv4_ct_cmd (fci_connections_ipv4_ct_cmd, funcdef_no=37, decl_uid=12208, cgraph_uid=38, symbol_order=40)

Modification phase of node fci_connections_ipv4_ct_cmd/40
fci_connections_ipv4_ct_cmd (const struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_ct_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_7 = fci_connections_ipvx_ct_cmd (0, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function fci_connections_ipv6_ct_cmd (fci_connections_ipv6_ct_cmd, funcdef_no=38, decl_uid=12213, cgraph_uid=39, symbol_order=41)

Modification phase of node fci_connections_ipv6_ct_cmd/41
fci_connections_ipv6_ct_cmd (const struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_ct6_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_7 = fci_connections_ipvx_ct_cmd (1, msg_2(D), fci_ret_3(D), reply_buf_4(D), reply_len_5(D));
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function fci_connections_ipv4_timeout_cmd (fci_connections_ipv4_timeout_cmd, funcdef_no=39, decl_uid=12218, cgraph_uid=40, symbol_order=42)

Modification phase of node fci_connections_ipv4_timeout_cmd/42
fci_connections_ipv4_timeout_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_timeout_cmd_t * reply_buf, uint32_t * reply_len)
{
  errno_t ret;
  uint32_t timeout;
  uint8_t proto;
  struct pfe_rtable_entry_t * entry;
  long unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  unsigned char _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  struct pfe_rtable_t * _15;
  struct pfe_rtable_t * _16;
  struct pfe_rtable_t * _17;

  <bb 2> [local count: 247250576]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = *reply_len_23(D);
  if (_1 <= 11)
    goto <bb 7>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  *reply_len_23(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_25(D), 0, 12);
  # DEBUG BEGIN_STMT
  # DEBUG D#4 => &msg_27(D)->msg_cmd.payload
  # DEBUG timeout_cmd => D#4
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_timeout_cmd_t *)msg_27(D) + 16B].protocol;
  _3 = _2 >> 8;
  _4 = (unsigned char) _3;
  _5 = MEM[(struct fpp_timeout_cmd_t *)msg_27(D) + 16B].timeout_value1;
  _6 = _5 >> 24;
  _7 = _5 >> 8;
  _8 = _7 & 65280;
  _9 = _6 | _8;
  _10 = _5 << 8;
  _11 = _10 & 16711680;
  _12 = _9 | _11;
  _13 = _5 << 24;
  _14 = _12 | _13;
  fci_connections_set_default_timeout (_4, _14);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = context.rtable;
  entry_30 = pfe_rtable_get_first (_15, 0, 0B);
  # DEBUG entry => entry_30
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  proto_34 = pfe_rtable_entry_get_proto (entry_18);
  # DEBUG proto => proto_34
  # DEBUG BEGIN_STMT
  timeout_35 = fci_connections_get_default_timeout (proto_34);
  # DEBUG timeout => timeout_35
  # DEBUG BEGIN_STMT
  pfe_rtable_entry_set_timeout (entry_18, timeout_35);
  # DEBUG BEGIN_STMT
  _16 = context.rtable;
  pfe_rtable_entry_free (_16, entry_18);
  # DEBUG BEGIN_STMT
  _17 = context.rtable;
  entry_39 = pfe_rtable_get_next (_17);
  # DEBUG entry => entry_39

  <bb 5> [local count: 1073741824]:
  # entry_18 = PHI <entry_30(3), entry_39(4)>
  # DEBUG entry => entry_18
  # DEBUG BEGIN_STMT
  if (entry_18 != 0B)
    goto <bb 4>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 6> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  *fci_ret_31(D) = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 247250577]:
  # ret_19 = PHI <22(2), 0(6)>
  # DEBUG ret => ret_19
  # DEBUG BEGIN_STMT
  return ret_19;

}


