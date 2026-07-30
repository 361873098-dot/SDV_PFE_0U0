
IPA constant propagation start:
Determining dynamic type for call: ret_16 = remove_fp_filter (0, addr_15, fci_ret_6(D));
  Starting walk at: ret_16 = remove_fp_filter (0, addr_15, fci_ret_6(D));
  instance pointer: fci_ret_6(D)  Outer instance pointer: fci_ret_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:addr_15 = pfe_mirror_get_filter (_14);
  Function call may change dynamic type:_12 = fci_fp_db_get_first (1, _11);
Determining dynamic type for call: ret_7 = remove_fp_filter (0, addr_5, fci_ret_6(D));
  Starting walk at: ret_7 = remove_fp_filter (0, addr_5, fci_ret_6(D));
  instance pointer: fci_ret_6(D)  Outer instance pointer: fci_ret_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:addr_5 = pfe_mirror_get_filter (_4);
Determining dynamic type for call: ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  Starting walk at: ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  instance pointer: &mirror  Outer instance pointer: mirror offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:_5 = pfe_mirror_get_first (0, 0B);
Determining dynamic type for call: ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  Starting walk at: ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  instance pointer: fci_ret_16(D)  Outer instance pointer: fci_ret_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:_5 = pfe_mirror_get_first (0, 0B);
Determining dynamic type for call: ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  Starting walk at: ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  instance pointer: reply_buf_20(D)  Outer instance pointer: reply_buf_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:_5 = pfe_mirror_get_first (0, 0B);
Determining dynamic type for call: ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  Starting walk at: ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  instance pointer: reply_len_18(D)  Outer instance pointer: reply_len_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:_5 = pfe_mirror_get_first (0, 0B);
Determining dynamic type for call: ret_31 = mirror_cmd_fpp_action_deregister (fci_ret_16(D), mirror_cmd_23);
  Starting walk at: ret_31 = mirror_cmd_fpp_action_deregister (fci_ret_16(D), mirror_cmd_23);
  instance pointer: fci_ret_16(D)  Outer instance pointer: fci_ret_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
Determining dynamic type for call: ret_31 = mirror_cmd_fpp_action_deregister (fci_ret_16(D), mirror_cmd_23);
  Starting walk at: ret_31 = mirror_cmd_fpp_action_deregister (fci_ret_16(D), mirror_cmd_23);
  instance pointer: mirror_cmd_23  Outer instance pointer: msg_22(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
Determining dynamic type for call: ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  Starting walk at: ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  instance pointer: &mirror  Outer instance pointer: mirror offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
Determining dynamic type for call: ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  Starting walk at: ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  instance pointer: fci_ret_16(D)  Outer instance pointer: fci_ret_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
Determining dynamic type for call: ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  Starting walk at: ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  instance pointer: mirror_cmd_23  Outer instance pointer: msg_22(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
Determining dynamic type for call: ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  Starting walk at: ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  instance pointer: &break_switch  Outer instance pointer: break_switch offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
Determining dynamic type for call: ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  Starting walk at: ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  instance pointer: &mirror  Outer instance pointer: mirror offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
Determining dynamic type for call: ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  Starting walk at: ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  instance pointer: fci_ret_16(D)  Outer instance pointer: fci_ret_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
Determining dynamic type for call: ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  Starting walk at: ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  instance pointer: mirror_cmd_23  Outer instance pointer: msg_22(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
Determining dynamic type for call: ret_37 = mirror_cmd_fpp_action_update (&mirror, fci_ret_16(D), mirror_cmd_23);
  Starting walk at: ret_37 = mirror_cmd_fpp_action_update (&mirror, fci_ret_16(D), mirror_cmd_23);
  instance pointer: &mirror  Outer instance pointer: mirror offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
Determining dynamic type for call: ret_37 = mirror_cmd_fpp_action_update (&mirror, fci_ret_16(D), mirror_cmd_23);
  Starting walk at: ret_37 = mirror_cmd_fpp_action_update (&mirror, fci_ret_16(D), mirror_cmd_23);
  instance pointer: fci_ret_16(D)  Outer instance pointer: fci_ret_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
Determining dynamic type for call: ret_37 = mirror_cmd_fpp_action_update (&mirror, fci_ret_16(D), mirror_cmd_23);
  Starting walk at: ret_37 = mirror_cmd_fpp_action_update (&mirror, fci_ret_16(D), mirror_cmd_23);
  instance pointer: mirror_cmd_23  Outer instance pointer: msg_22(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  Function call may change dynamic type:autolibc_memset (reply_buf_20(D), 0, 56);
  Function call may change dynamic type:ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
Determining dynamic type for call: ret_8 = fci_mirror_cmd_query_cont_get_mirror (&context, mirror_6(D), &fci_ret, &reply_buf);
  Starting walk at: ret_8 = fci_mirror_cmd_query_cont_get_mirror (&context, mirror_6(D), &fci_ret, &reply_buf);
  instance pointer: &context  Outer instance pointer: context offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_8 = fci_mirror_cmd_query_cont_get_mirror (&context, mirror_6(D), &fci_ret, &reply_buf);
  Starting walk at: ret_8 = fci_mirror_cmd_query_cont_get_mirror (&context, mirror_6(D), &fci_ret, &reply_buf);
  instance pointer: mirror_6(D)  Outer instance pointer: mirror_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_8 = fci_mirror_cmd_query_cont_get_mirror (&context, mirror_6(D), &fci_ret, &reply_buf);
  Starting walk at: ret_8 = fci_mirror_cmd_query_cont_get_mirror (&context, mirror_6(D), &fci_ret, &reply_buf);
  instance pointer: &fci_ret  Outer instance pointer: fci_ret offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_8 = fci_mirror_cmd_query_cont_get_mirror (&context, mirror_6(D), &fci_ret, &reply_buf);
  Starting walk at: ret_8 = fci_mirror_cmd_query_cont_get_mirror (&context, mirror_6(D), &fci_ret, &reply_buf);
  instance pointer: &reply_buf  Outer instance pointer: reply_buf offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  Starting walk at: ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  instance pointer: &fci_context  Outer instance pointer: fci_context offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  Starting walk at: ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  instance pointer: mirror_33(D)  Outer instance pointer: mirror_33(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  Starting walk at: ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  instance pointer: &fci_ret  Outer instance pointer: fci_ret offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  Starting walk at: ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  instance pointer: mirror_cmd_34(D)  Outer instance pointer: mirror_cmd_34(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_38 = fci_mirror_cmd_update_set_filter.isra.0 (_54, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  Starting walk at: ret_38 = fci_mirror_cmd_update_set_filter.isra.0 (_54, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  instance pointer: _54  Outer instance pointer: fci_context.5_3 offset: 52128 (bits) vtbl reference: 
  Function call may change dynamic type:ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
Determining dynamic type for call: ret_38 = fci_mirror_cmd_update_set_filter.isra.0 (_54, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  Starting walk at: ret_38 = fci_mirror_cmd_update_set_filter.isra.0 (_54, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  instance pointer: mirror_33(D)  Outer instance pointer: mirror_33(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
Determining dynamic type for call: ret_38 = fci_mirror_cmd_update_set_filter.isra.0 (_54, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  Starting walk at: ret_38 = fci_mirror_cmd_update_set_filter.isra.0 (_54, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  instance pointer: &fci_ret  Outer instance pointer: fci_ret offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
Determining dynamic type for call: ret_38 = fci_mirror_cmd_update_set_filter.isra.0 (_54, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  Starting walk at: ret_38 = fci_mirror_cmd_update_set_filter.isra.0 (_54, mirror_33(D), &fci_ret, mirror_cmd_34(D));
  instance pointer: mirror_cmd_34(D)  Outer instance pointer: mirror_cmd_34(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_36 = fci_mirror_cmd_update_egress_port (&fci_context, mirror_33(D), &fci_ret, mirror_cmd_34(D));
Determining dynamic type for call: egress_id_34 = get_egress_interface (reply_buf_32(D), _7);
  Starting walk at: egress_id_34 = get_egress_interface (reply_buf_32(D), _7);
  instance pointer: reply_buf_32(D)  Outer instance pointer: reply_buf_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_mirror_get_next ();
Determining dynamic type for call: egress_id_34 = get_egress_interface (reply_buf_32(D), _7);
  Starting walk at: egress_id_34 = get_egress_interface (reply_buf_32(D), _7);
  instance pointer: _7  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_mirror_get_next ();
Determining dynamic type for call: ret_41 = fill_reply_buf.isra.0 (reply_buf_32(D), phy_if_21, _19, _8);
  Starting walk at: ret_41 = fill_reply_buf.isra.0 (reply_buf_32(D), phy_if_21, _19, _8);
  instance pointer: reply_buf_32(D)  Outer instance pointer: reply_buf_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_if_db_get_single (_10, _11, 1, _13, &entry);
  Function call may change dynamic type:ret_37 = pfe_if_db_lock (_8);
  Function call may change dynamic type:egress_id_34 = get_egress_interface (reply_buf_32(D), _7);
  Function call may change dynamic type:_3 = pfe_mirror_get_next ();
Determining dynamic type for call: ret_41 = fill_reply_buf.isra.0 (reply_buf_32(D), phy_if_21, _19, _8);
  Starting walk at: ret_41 = fill_reply_buf.isra.0 (reply_buf_32(D), phy_if_21, _19, _8);
  instance pointer: phy_if_21  Outer instance pointer: phy_if_39 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_if_db_get_single (_10, _11, 1, _13, &entry);
  Function call may change dynamic type:ret_37 = pfe_if_db_lock (_8);
  Function call may change dynamic type:egress_id_34 = get_egress_interface (reply_buf_32(D), _7);
  Function call may change dynamic type:_3 = pfe_mirror_get_next ();
Determining dynamic type for call: ret_41 = fill_reply_buf.isra.0 (reply_buf_32(D), phy_if_21, _19, _8);
  Starting walk at: ret_41 = fill_reply_buf.isra.0 (reply_buf_32(D), phy_if_21, _19, _8);
  instance pointer: _19  Outer instance pointer: _19 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_if_db_get_single (_10, _11, 1, _13, &entry);
  Function call may change dynamic type:ret_37 = pfe_if_db_lock (_8);
  Function call may change dynamic type:egress_id_34 = get_egress_interface (reply_buf_32(D), _7);
  Function call may change dynamic type:_3 = pfe_mirror_get_next ();
Determining dynamic type for call: ret_41 = fill_reply_buf.isra.0 (reply_buf_32(D), phy_if_21, _19, _8);
  Starting walk at: ret_41 = fill_reply_buf.isra.0 (reply_buf_32(D), phy_if_21, _19, _8);
  instance pointer: _8  Outer instance pointer: fci_context_35(D) offset: 160 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_if_db_get_single (_10, _11, 1, _13, &entry);
  Function call may change dynamic type:ret_37 = pfe_if_db_lock (_8);
  Function call may change dynamic type:egress_id_34 = get_egress_interface (reply_buf_32(D), _7);
  Function call may change dynamic type:_3 = pfe_mirror_get_next ();
Determining dynamic type for call: ret_6 = remove_fp_filter.part.0 (addr_2(D), fci_ret_5(D));
  Starting walk at: ret_6 = remove_fp_filter.part.0 (addr_2(D), fci_ret_5(D));
  instance pointer: fci_ret_5(D)  Outer instance pointer: fci_ret_5(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  fill_reply_buf.isra.0/58:
  Jump functions of caller  fci_mirror_cmd_update_set_filter.isra.0/57:
    callsite  fci_mirror_cmd_update_set_filter.isra.0/57 -> remove_fp_filter/16 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_mirror_cmd_update_set_filter.isra.0/57 -> remove_fp_filter/16 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  remove_fp_filter.part.0/56:
  Jump functions of caller  pfe_mirror_get_actions/55:
  Jump functions of caller  pfe_phy_if_get_name/54:
  Jump functions of caller  pfe_mirror_get_egress_port/53:
  Jump functions of caller  autolibc_strncpy/52:
  Jump functions of caller  pfe_mirror_get_name/51:
  Jump functions of caller  pfe_if_db_get_single/50:
  Jump functions of caller  pfe_mirror_get_next/49:
  Jump functions of caller  pfe_mirror_destroy/48:
  Jump functions of caller  fci_fp_db_pop_table_from_hw/47:
  Jump functions of caller  fci_fp_db_get_table_from_addr/46:
  Jump functions of caller  fci_fp_db_push_table_to_hw/45:
  Jump functions of caller  fci_fp_db_get_table_dmem_addr/44:
  Jump functions of caller  fci_fp_db_get_first/43:
  Jump functions of caller  pfe_mirror_set_filter/42:
  Jump functions of caller  pfe_mirror_get_filter/41:
  Jump functions of caller  pfe_mirror_set_egress_port/40:
  Jump functions of caller  pfe_phy_if_get_id/39:
  Jump functions of caller  pfe_if_db_unlock/38:
  Jump functions of caller  pfe_if_db_entry_get_phy_if/37:
  Jump functions of caller  pfe_if_db_get_first/36:
  Jump functions of caller  pfe_if_db_lock/35:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/34:
  Jump functions of caller  pfe_hm_report/33:
  Jump functions of caller  pfe_mirror_set_actions/32:
  Jump functions of caller  pfe_mirror_create/30:
  Jump functions of caller  pfe_mirror_get_first/29:
  Jump functions of caller  pfe_mirror_put/28:
  Jump functions of caller  autolibc_memset/27:
  Jump functions of caller  fci_mirror_cmd/26:
    callsite  fci_mirror_cmd/26 -> mirror_cmd_fpp_query_cont/25 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_mirror_cmd/26 -> mirror_cmd_fpp_action_deregister/23 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  fci_mirror_cmd/26 -> mirror_cmd_fpp_action_update/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  fci_mirror_cmd/26 -> mirror_cmd_get_mirror/24 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  fci_mirror_cmd/26 -> mirror_cmd_fpp_action_register/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  mirror_cmd_fpp_query_cont/25:
    callsite  mirror_cmd_fpp_query_cont/25 -> fci_mirror_cmd_query_cont_get_mirror/20 : 
       param 0: CONST: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  mirror_cmd_get_mirror/24:
  Jump functions of caller  mirror_cmd_fpp_action_deregister/23:
  Jump functions of caller  mirror_cmd_fpp_action_update/22:
    callsite  mirror_cmd_fpp_action_update/22 -> fci_mirror_cmd_update_set_filter.isra.0/57 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mirror_cmd_fpp_action_update/22 -> fci_mirror_cmd_update_egress_port/15 : 
       param 0: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: &context
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mirror_cmd_fpp_action_register/21:
  Jump functions of caller  fci_mirror_cmd_query_cont_get_mirror/20:
    callsite  fci_mirror_cmd_query_cont_get_mirror/20 -> fill_reply_buf.isra.0/58 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  fci_mirror_cmd_query_cont_get_mirror/20 -> get_egress_interface/19 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  get_egress_interface/19:
  Jump functions of caller  remove_fp_filter/16:
    callsite  remove_fp_filter/16 -> remove_fp_filter.part.0/56 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_mirror_cmd_update_egress_port/15:

 Propagating constants:

Not considering fci_mirror_cmd for cloning; -fipa-cp-clone disabled.

overall_size: 607, max_new_size: 11001
 - context independent values, size: 75, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 7, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 66, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: fill_reply_buf.isra.0/58:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fpp_mirror_cmd_t * * ~[0B, 0B]
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
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_mirror_cmd_update_set_filter.isra.0/57:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_class_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_mirror_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_mirror_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: remove_fp_filter.part.0/56:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_mirror_cmd/26:
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
  Node: mirror_cmd_fpp_query_cont/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_mirror_t * * ~[0B, 0B]
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
  Node: mirror_cmd_get_mirror/24:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_mirror_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_mirror_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: mirror_cmd_fpp_action_deregister/23:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_mirror_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: mirror_cmd_fpp_action_update/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_mirror_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_mirror_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: mirror_cmd_fpp_action_register/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_mirror_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_mirror_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         bool_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_mirror_cmd_query_cont_get_mirror/20:
    param [0]: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fci_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_mirror_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fpp_mirror_cmd_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: get_egress_interface/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fpp_mirror_cmd_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: remove_fp_filter/16:
    param [0]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         errno_t [0, 0]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_mirror_cmd_update_egress_port/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fci_t * * ~[0B, 0B]
        ref offset 0: &context [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_mirror_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_mirror_cmd_t * ~[0B, 0B]
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of fci_mirror_cmd_query_cont_get_mirror/20 for all known contexts.
    replacing param #0 fci_context with const &context
 - Creating a specialized node of remove_fp_filter/16 for all known contexts.
    replacing param #0 ret with const 0
 - Creating a specialized node of fci_mirror_cmd_update_egress_port/15 for all known contexts.
Propagated bits info for function fci_mirror_cmd_update_egress_port.constprop/61:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function remove_fp_filter.constprop/60:
 param 0: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_mirror_cmd_query_cont_get_mirror.constprop/59:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fill_reply_buf.isra.0/58:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_mirror_cmd_update_set_filter.isra.0/57:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function remove_fp_filter.part.0/56:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mirror_cmd_fpp_query_cont/25:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mirror_cmd_get_mirror/24:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mirror_cmd_fpp_action_update/22:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mirror_cmd_fpp_action_register/21:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_mirror_cmd_query_cont_get_mirror/20:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function get_egress_interface/19:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function remove_fp_filter/16:
 param 0: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function fci_mirror_cmd_update_egress_port/15:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: fci_mirror_cmd_query_cont_get_mirror/20 remove_fp_filter/16 fci_mirror_cmd_update_egress_port/15
Reclaiming variables:
Clearing address taken flags:
Symbol table:

fci_mirror_cmd_update_egress_port.constprop.0/61 (fci_mirror_cmd_update_egress_port.constprop) @07180540
  Type: function definition analyzed
  Visibility:
  References: context/31 (addr)
  Referring: 
  Clone of fci_mirror_cmd_update_egress_port/15
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: mirror_cmd_fpp_action_update/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_if_db_lock/35 (1073741823 (estimated locally),1.00 per call) pfe_if_db_get_first/36 (354334802 (estimated locally),0.33 per call) pfe_if_db_entry_get_phy_if/37 (248034361 (estimated locally),0.23 per call) pfe_if_db_unlock/38 (197895353 (estimated locally),0.18 per call) pfe_phy_if_get_id/39 (156439449 (estimated locally),0.15 per call) pfe_mirror_set_egress_port/40 (156439449 (estimated locally),0.15 per call) pfe_if_db_unlock/38 (78219725 (estimated locally),0.07 per call) pfe_hm_report/33 (78219725 (estimated locally),0.07 per call) oal_util_raise_dem_for_drv_runtime_err/34 (78219725 (estimated locally),0.07 per call) pfe_if_db_unlock/38 (78219725 (estimated locally),0.07 per call) 
remove_fp_filter.constprop.0/60 (remove_fp_filter.constprop) @076a8a80
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of remove_fp_filter/16
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: fci_mirror_cmd_update_set_filter.isra.0/57 (536870913 (estimated locally),0.50 per call) fci_mirror_cmd_update_set_filter.isra.0/57 (287064877 (estimated locally),0.27 per call) 
  Calls: remove_fp_filter.part.0/56 (354334800 (estimated locally),0.33 per call) 
fci_mirror_cmd_query_cont_get_mirror.constprop.0/59 (fci_mirror_cmd_query_cont_get_mirror.constprop) @076a87e0
  Type: function definition analyzed
  Visibility:
  References: context/31 (addr)
  Referring: 
  Clone of fci_mirror_cmd_query_cont_get_mirror/20
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: mirror_cmd_fpp_query_cont/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_mirror_get_next/49 (187153200 (estimated locally),0.17 per call) get_egress_interface/19 (354334802 (estimated locally),0.33 per call) pfe_if_db_lock/35 (354334802 (estimated locally),0.33 per call) pfe_if_db_get_single/50 (116930485 (estimated locally),0.11 per call) pfe_if_db_entry_get_phy_if/37 (81851339 (estimated locally),0.08 per call) pfe_if_db_unlock/38 (45441512 (estimated locally),0.04 per call) pfe_mirror_get_name/51 (45441512 (estimated locally),0.04 per call) pfe_hm_report/33 (45441512 (estimated locally),0.04 per call) oal_util_raise_dem_for_drv_runtime_err/34 (45441512 (estimated locally),0.04 per call) fill_reply_buf.isra.0/58 (71488973 (estimated locally),0.07 per call) 
fill_reply_buf.isra.0/58 (fill_reply_buf.isra.0) @07173c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_mirror_cmd_query_cont_get_mirror.constprop/59 (71488973 (estimated locally),0.07 per call) 
  Calls: pfe_mirror_get_actions/55 (1073741824 (estimated locally),1.00 per call) autolibc_memset/27 (1073741824 (estimated locally),1.00 per call) autolibc_strncpy/52 (116930485 (estimated locally),0.11 per call) fci_fp_db_get_table_from_addr/46 (354334802 (estimated locally),0.33 per call) pfe_mirror_get_filter/41 (1073741824 (estimated locally),1.00 per call) autolibc_memset/27 (1073741824 (estimated locally),1.00 per call) pfe_if_db_unlock/38 (1073741824 (estimated locally),1.00 per call) autolibc_strncpy/52 (1073741824 (estimated locally),1.00 per call) pfe_phy_if_get_name/54 (1073741824 (estimated locally),1.00 per call) 
fci_mirror_cmd_update_set_filter.isra.0/57 (fci_mirror_cmd_update_set_filter.isra.0) @071739a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mirror_cmd_fpp_action_update/22 (354334802 (estimated locally),0.33 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/34 (10316250 (estimated locally),0.01 per call) pfe_hm_report/33 (10316250 (estimated locally),0.01 per call) pfe_mirror_set_filter/42 (31261365 (estimated locally),0.03 per call) fci_fp_db_get_table_dmem_addr/44 (31261365 (estimated locally),0.03 per call) fci_fp_db_push_table_to_hw/45 (31261365 (estimated locally),0.03 per call) fci_fp_db_get_table_dmem_addr/44 (94731409 (estimated locally),0.09 per call) remove_fp_filter.constprop/60 (287064877 (estimated locally),0.27 per call) pfe_mirror_get_filter/41 (287064877 (estimated locally),0.27 per call) fci_fp_db_get_first/43 (536870913 (estimated locally),0.50 per call) pfe_mirror_set_filter/42 (177167401 (estimated locally),0.17 per call) remove_fp_filter.constprop/60 (536870913 (estimated locally),0.50 per call) pfe_mirror_get_filter/41 (536870913 (estimated locally),0.50 per call) 
remove_fp_filter.part.0/56 (remove_fp_filter.part.0) @06e6b540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: remove_fp_filter.constprop/60 (354334800 (estimated locally),0.33 per call) 
  Calls: fci_fp_db_get_table_from_addr/46 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/33 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/34 (536870913 (estimated locally),0.50 per call) fci_fp_db_pop_table_from_hw/47 (536870913 (estimated locally),0.50 per call) 
pfe_mirror_get_actions/55 (pfe_mirror_get_actions) @07790000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fill_reply_buf.isra.0/58 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_get_name/54 (pfe_phy_if_get_name) @07781ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fill_reply_buf.isra.0/58 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_mirror_get_egress_port/53 (pfe_mirror_get_egress_port) @07781e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: get_egress_interface/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_strncpy/52 (autolibc_strncpy) @07781d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fill_reply_buf.isra.0/58 (116930485 (estimated locally),0.11 per call) fill_reply_buf.isra.0/58 (1073741824 (estimated locally),1.00 per call) get_egress_interface/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_mirror_get_name/51 (pfe_mirror_get_name) @07781b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_query_cont_get_mirror.constprop/59 (45441512 (estimated locally),0.04 per call) get_egress_interface/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_if_db_get_single/50 (pfe_if_db_get_single) @07781a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_query_cont_get_mirror.constprop/59 (116930485 (estimated locally),0.11 per call) 
  Calls: 
pfe_mirror_get_next/49 (pfe_mirror_get_next) @077819a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_query_cont_get_mirror.constprop/59 (187153200 (estimated locally),0.17 per call) 
  Calls: 
pfe_mirror_destroy/48 (pfe_mirror_destroy) @07781700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mirror_cmd_fpp_action_deregister/23 (574129754 (estimated locally),0.53 per call) 
  Calls: 
fci_fp_db_pop_table_from_hw/47 (fci_fp_db_pop_table_from_hw) @07781540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mirror_cmd_fpp_action_deregister/23 (75557772 (estimated locally),0.07 per call) remove_fp_filter.part.0/56 (536870913 (estimated locally),0.50 per call) 
  Calls: 
fci_fp_db_get_table_from_addr/46 (fci_fp_db_get_table_from_addr) @07781460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fill_reply_buf.isra.0/58 (354334802 (estimated locally),0.33 per call) mirror_cmd_fpp_action_deregister/23 (151115544 (estimated locally),0.14 per call) remove_fp_filter.part.0/56 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
fci_fp_db_push_table_to_hw/45 (fci_fp_db_push_table_to_hw) @077812a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_set_filter.isra.0/57 (31261365 (estimated locally),0.03 per call) 
  Calls: 
fci_fp_db_get_table_dmem_addr/44 (fci_fp_db_get_table_dmem_addr) @077811c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_set_filter.isra.0/57 (31261365 (estimated locally),0.03 per call) fci_mirror_cmd_update_set_filter.isra.0/57 (94731409 (estimated locally),0.09 per call) 
  Calls: 
fci_fp_db_get_first/43 (fci_fp_db_get_first) @077810e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_set_filter.isra.0/57 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_mirror_set_filter/42 (pfe_mirror_set_filter) @07781000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_set_filter.isra.0/57 (31261365 (estimated locally),0.03 per call) fci_mirror_cmd_update_set_filter.isra.0/57 (177167401 (estimated locally),0.17 per call) 
  Calls: 
pfe_mirror_get_filter/41 (pfe_mirror_get_filter) @07760ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fill_reply_buf.isra.0/58 (1073741824 (estimated locally),1.00 per call) mirror_cmd_fpp_action_deregister/23 (574129754 (estimated locally),0.53 per call) fci_mirror_cmd_update_set_filter.isra.0/57 (287064877 (estimated locally),0.27 per call) fci_mirror_cmd_update_set_filter.isra.0/57 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_mirror_set_egress_port/40 (pfe_mirror_set_egress_port) @07760d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_egress_port.constprop/61 (156439449 (estimated locally),0.15 per call) 
  Calls: 
pfe_phy_if_get_id/39 (pfe_phy_if_get_id) @07760c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_egress_port.constprop/61 (156439449 (estimated locally),0.15 per call) 
  Calls: 
pfe_if_db_unlock/38 (pfe_if_db_unlock) @07760b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_egress_port.constprop/61 (197895353 (estimated locally),0.18 per call) fci_mirror_cmd_update_egress_port.constprop/61 (78219725 (estimated locally),0.07 per call) fci_mirror_cmd_update_egress_port.constprop/61 (78219725 (estimated locally),0.07 per call) fci_mirror_cmd_query_cont_get_mirror.constprop/59 (45441512 (estimated locally),0.04 per call) fill_reply_buf.isra.0/58 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_if_db_entry_get_phy_if/37 (pfe_if_db_entry_get_phy_if) @07760a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_egress_port.constprop/61 (248034361 (estimated locally),0.23 per call) fci_mirror_cmd_query_cont_get_mirror.constprop/59 (81851339 (estimated locally),0.08 per call) 
  Calls: 
pfe_if_db_get_first/36 (pfe_if_db_get_first) @077609a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_egress_port.constprop/61 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_if_db_lock/35 (pfe_if_db_lock) @077608c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_egress_port.constprop/61 (1073741823 (estimated locally),1.00 per call) fci_mirror_cmd_query_cont_get_mirror.constprop/59 (354334802 (estimated locally),0.33 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/34 (oal_util_raise_dem_for_drv_runtime_err) @07760700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_egress_port.constprop/61 (78219725 (estimated locally),0.07 per call) fci_mirror_cmd_query_cont_get_mirror.constprop/59 (45441512 (estimated locally),0.04 per call) mirror_cmd_fpp_action_deregister/23 (75557772 (estimated locally),0.07 per call) mirror_cmd_fpp_action_update/22 (29232621 (estimated locally),0.03 per call) mirror_cmd_fpp_action_update/22 (29232621 (estimated locally),0.03 per call) fci_mirror_cmd_update_set_filter.isra.0/57 (10316250 (estimated locally),0.01 per call) remove_fp_filter.part.0/56 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_hm_report/33 (pfe_hm_report) @07760620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd_update_egress_port.constprop/61 (78219725 (estimated locally),0.07 per call) fci_mirror_cmd_query_cont_get_mirror.constprop/59 (45441512 (estimated locally),0.04 per call) mirror_cmd_fpp_action_deregister/23 (75557772 (estimated locally),0.07 per call) mirror_cmd_fpp_action_update/22 (29232621 (estimated locally),0.03 per call) mirror_cmd_fpp_action_update/22 (29232621 (estimated locally),0.03 per call) fci_mirror_cmd_update_set_filter.isra.0/57 (10316250 (estimated locally),0.01 per call) remove_fp_filter.part.0/56 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_mirror_set_actions/32 (pfe_mirror_set_actions) @07760540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mirror_cmd_fpp_action_update/22 (88583701 (estimated locally),0.08 per call) mirror_cmd_fpp_action_update/22 (88583701 (estimated locally),0.08 per call) 
  Calls: 
context/31 (context) @077654c8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: mirror_cmd_fpp_action_update/22 (addr)mirror_cmd_fpp_query_cont/25 (addr)fci_mirror_cmd_query_cont_get_mirror.constprop.0/59 (addr)fci_mirror_cmd_update_egress_port.constprop.0/61 (addr)
  Availability: not_available
  Varpool flags:
pfe_mirror_create/30 (pfe_mirror_create) @077602a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mirror_cmd_fpp_action_register/21 (322122547 (estimated locally),0.30 per call) 
  Calls: 
pfe_mirror_get_first/29 (pfe_mirror_get_first) @077600e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd/26 (85496674 (estimated locally),0.08 per call) mirror_cmd_fpp_action_deregister/23 (1073741824 (estimated locally),1.00 per call) mirror_cmd_fpp_action_register/21 (1073741823 (estimated locally),1.00 per call) mirror_cmd_get_mirror/24 (187153200 (estimated locally),0.17 per call) 
  Calls: 
pfe_mirror_put/28 (pfe_mirror_put) @07760000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd/26 (145344346 (estimated locally),0.14 per call) fci_mirror_cmd/26 (141924479 (estimated locally),0.13 per call) mirror_cmd_fpp_action_deregister/23 (116203862 (estimated locally),0.11 per call) mirror_cmd_fpp_action_register/21 (751619277 (estimated locally),0.70 per call) 
  Calls: 
autolibc_memset/27 (autolibc_memset) @07751d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_mirror_cmd/26 (512877469 (estimated locally),0.48 per call) fill_reply_buf.isra.0/58 (1073741824 (estimated locally),1.00 per call) fill_reply_buf.isra.0/58 (1073741824 (estimated locally),1.00 per call) mirror_cmd_fpp_action_update/22 (88583701 (estimated locally),0.08 per call) 
  Calls: 
fci_mirror_cmd/26 (fci_mirror_cmd) @07751ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073639249 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_mirror_put/28 (145344346 (estimated locally),0.14 per call) mirror_cmd_fpp_query_cont/25 (145344346 (estimated locally),0.14 per call) pfe_mirror_get_first/29 (85496674 (estimated locally),0.08 per call) mirror_cmd_fpp_action_deregister/23 (85496674 (estimated locally),0.08 per call) pfe_mirror_put/28 (141924479 (estimated locally),0.13 per call) mirror_cmd_fpp_action_update/22 (46835078 (estimated locally),0.04 per call) mirror_cmd_get_mirror/24 (141924479 (estimated locally),0.13 per call) mirror_cmd_fpp_action_register/21 (85496674 (estimated locally),0.08 per call) autolibc_memset/27 (512877469 (estimated locally),0.48 per call) 
mirror_cmd_fpp_query_cont/25 (mirror_cmd_fpp_query_cont) @07751c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/31 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_mirror_cmd/26 (145344346 (estimated locally),0.14 per call) 
  Calls: fci_mirror_cmd_query_cont_get_mirror.constprop/59 (1073741824 (estimated locally),1.00 per call) 
mirror_cmd_get_mirror/24 (mirror_cmd_get_mirror) @077519a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_mirror_cmd/26 (141924479 (estimated locally),0.13 per call) 
  Calls: pfe_mirror_get_first/29 (187153200 (estimated locally),0.17 per call) 
mirror_cmd_fpp_action_deregister/23 (mirror_cmd_fpp_action_deregister) @07751700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_mirror_cmd/26 (85496674 (estimated locally),0.08 per call) 
  Calls: fci_fp_db_pop_table_from_hw/47 (75557772 (estimated locally),0.07 per call) oal_util_raise_dem_for_drv_runtime_err/34 (75557772 (estimated locally),0.07 per call) pfe_hm_report/33 (75557772 (estimated locally),0.07 per call) fci_fp_db_get_table_from_addr/46 (151115544 (estimated locally),0.14 per call) pfe_mirror_put/28 (116203862 (estimated locally),0.11 per call) pfe_mirror_destroy/48 (574129754 (estimated locally),0.53 per call) pfe_mirror_get_filter/41 (574129754 (estimated locally),0.53 per call) pfe_mirror_get_first/29 (1073741824 (estimated locally),1.00 per call) 
mirror_cmd_fpp_action_update/22 (mirror_cmd_fpp_action_update) @07751380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/31 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_mirror_cmd/26 (46835078 (estimated locally),0.04 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/34 (29232621 (estimated locally),0.03 per call) pfe_hm_report/33 (29232621 (estimated locally),0.03 per call) pfe_mirror_set_actions/32 (88583701 (estimated locally),0.08 per call) autolibc_memset/27 (88583701 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/34 (29232621 (estimated locally),0.03 per call) pfe_hm_report/33 (29232621 (estimated locally),0.03 per call) pfe_mirror_set_actions/32 (88583701 (estimated locally),0.08 per call) fci_mirror_cmd_update_set_filter.isra.0/57 (354334802 (estimated locally),0.33 per call) fci_mirror_cmd_update_egress_port.constprop/61 (1073741824 (estimated locally),1.00 per call) 
mirror_cmd_fpp_action_register/21 (mirror_cmd_fpp_action_register) @076a8e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: fci_mirror_cmd/26 (85496674 (estimated locally),0.08 per call) 
  Calls: pfe_mirror_create/30 (322122547 (estimated locally),0.30 per call) pfe_mirror_put/28 (751619277 (estimated locally),0.70 per call) pfe_mirror_get_first/29 (1073741823 (estimated locally),1.00 per call) 
fci_mirror_cmd_query_cont_get_mirror/20 (fci_mirror_cmd_query_cont_get_mirror) @076a88c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
get_egress_interface/19 (get_egress_interface) @076a8d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_mirror_cmd_query_cont_get_mirror.constprop/59 (354334802 (estimated locally),0.33 per call) 
  Calls: pfe_mirror_get_egress_port/53 (1073741824 (estimated locally),1.00 per call) autolibc_strncpy/52 (1073741824 (estimated locally),1.00 per call) pfe_mirror_get_name/51 (1073741824 (estimated locally),1.00 per call) 
remove_fp_filter/16 (remove_fp_filter) @076a8460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fci_mirror_cmd_update_egress_port/15 (fci_mirror_cmd_update_egress_port) @076a80e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function remove_fp_filter.part.0 (remove_fp_filter.part.0, funcdef_no=24, decl_uid=12696, cgraph_uid=53, symbol_order=56)

Modification phase of node remove_fp_filter.part.0/56
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
remove_fp_filter.part.0 (uint32_t addr, uint16_t * * fci_ret)
{
  const char * str;
  errno_t ret;
  uint16_t * _4;
  const char * str.12_5;

  <bb 6> [local count: 1073741824]:
  # DEBUG D#2 s=> ret
  # DEBUG ret => D#2

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ret_2 = fci_fp_db_get_table_from_addr (addr_1(D), &str);
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  if (ret_2 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Cannot obtain filter name.\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_mirror.c", 160, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = *fci_ret_3(D);
  *_4 = 65535;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  str.12_5 = str;
  fci_fp_db_pop_table_from_hw (str.12_5);

  <bb 5> [local count: 1073741824]:
  # ret_6 = PHI <ret_2(3), 0(4)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  str ={v} {CLOBBER};
  return ret_6;

}



;; Function fci_mirror_cmd (fci_mirror_cmd, funcdef_no=23, decl_uid=12393, cgraph_uid=24, symbol_order=26)

Modification phase of node fci_mirror_cmd/26
fci_mirror_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_mirror_cmd_t * reply_buf, uint32_t * reply_len)
{
  bool_t break_switch;
  struct pfe_mirror_t * mirror;
  errno_t ret;
  struct fpp_mirror_cmd_t * mirror_cmd;
  long unsigned int _1;
  short unsigned int _2;
  unsigned char break_switch.0_3;
  struct pfe_mirror_t * mirror.1_4;
  struct pfe_mirror_t * _5;
  struct pfe_mirror_t * mirror.3_6;

  <bb 2> [local count: 1073639249]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  mirror = 0B;
  # DEBUG BEGIN_STMT
  break_switch = 0;
  # DEBUG BEGIN_STMT
  *fci_ret_16(D) = 0;
  # DEBUG BEGIN_STMT
  _1 = *reply_len_18(D);
  if (_1 <= 55)
    goto <bb 3>; [52.23%]
  else
    goto <bb 4>; [47.77%]

  <bb 3> [local count: 560761781]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_16(D) = 65535;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 14>; [100.00%]

  <bb 4> [local count: 512877469]:
  # DEBUG BEGIN_STMT
  *reply_len_18(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_20(D), 0, 56);
  # DEBUG BEGIN_STMT
  mirror_cmd_23 = &msg_22(D)->msg_cmd.payload;
  # DEBUG mirror_cmd => mirror_cmd_23
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_mirror_cmd_t *)msg_22(D) + 16B].action;
  switch (_2) <default: <L12> [16.67%], case 0: <L2> [16.67%], case 1: <L7> [16.67%], case 4: <L3> [16.67%], case 6: <L8> [16.67%], case 7: <L10> [16.67%]>

  <bb 5> [local count: 85496674]:
<L2>:
  # DEBUG BEGIN_STMT
  ret_33 = mirror_cmd_fpp_action_register (&mirror, fci_ret_16(D), mirror_cmd_23, &break_switch);
  # DEBUG ret => ret_33
  # DEBUG BEGIN_STMT
  break_switch.0_3 = break_switch;
  if (break_switch.0_3 == 1)
    goto <bb 14>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 141924479]:
<L3>:
  # DEBUG BEGIN_STMT
  ret_35 = mirror_cmd_get_mirror (&mirror, fci_ret_16(D), mirror_cmd_23);
  # DEBUG ret => ret_35
  # DEBUG BEGIN_STMT
  if (ret_35 == 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 46835078]:
  # DEBUG BEGIN_STMT
  ret_37 = mirror_cmd_fpp_action_update (&mirror, fci_ret_16(D), mirror_cmd_23);
  # DEBUG ret => ret_37

  <bb 8> [local count: 141924479]:
  # ret_7 = PHI <ret_35(6), ret_37(7)>
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  mirror.1_4 = mirror;
  pfe_mirror_put (mirror.1_4);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 9> [local count: 85496674]:
<L7>:
  # DEBUG BEGIN_STMT
  ret_31 = mirror_cmd_fpp_action_deregister (fci_ret_16(D), mirror_cmd_23);
  # DEBUG ret => ret_31
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 10> [local count: 85496674]:
<L8>:
  # DEBUG BEGIN_STMT
  _5 = pfe_mirror_get_first (0, 0B);
  mirror = _5;
  # DEBUG BEGIN_STMT
  if (_5 == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 12>; [70.00%]

  <bb 11> [local count: 25649002]:
  # DEBUG BEGIN_STMT
  *fci_ret_16(D) = 61746;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 12> [local count: 145344346]:
<L10>:
  # DEBUG BEGIN_STMT
  ret_28 = mirror_cmd_fpp_query_cont (&mirror, fci_ret_16(D), reply_buf_20(D), reply_len_18(D));
  # DEBUG ret => ret_28
  # DEBUG BEGIN_STMT
  mirror.3_6 = mirror;
  pfe_mirror_put (mirror.3_6);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 85496674]:
<L12>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_16(D) = 4;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 1073741824]:
  # ret_8 = PHI <22(3), ret_33(5), ret_7(8), ret_31(9), 0(11), ret_28(12), 0(13)>
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  mirror ={v} {CLOBBER};
  break_switch ={v} {CLOBBER};
  return ret_8;

}


