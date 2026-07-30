
IPA constant propagation start:
Determining dynamic type for call: prepare_mac_src (&src_mac, phy_if_8, rt_cmd_4(D));
  Starting walk at: prepare_mac_src (&src_mac, phy_if_8, rt_cmd_4(D));
  instance pointer: &src_mac  Outer instance pointer: src_mac offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_1 = pfe_if_db_lock (&session_id);
  Function call may change dynamic type:pfe_if_db_get_first (_2, session_id.0_3, 3, _5, &if_entry);
Determining dynamic type for call: prepare_mac_src (&src_mac, phy_if_8, rt_cmd_4(D));
  Starting walk at: prepare_mac_src (&src_mac, phy_if_8, rt_cmd_4(D));
  instance pointer: phy_if_8  Outer instance pointer: phy_if_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_1 = pfe_if_db_lock (&session_id);
  Function call may change dynamic type:pfe_if_db_get_first (_2, session_id.0_3, 3, _5, &if_entry);
Determining dynamic type for call: prepare_mac_src (&src_mac, phy_if_8, rt_cmd_4(D));
  Starting walk at: prepare_mac_src (&src_mac, phy_if_8, rt_cmd_4(D));
  instance pointer: rt_cmd_4(D)  Outer instance pointer: rt_cmd_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_1 = pfe_if_db_lock (&session_id);
  Function call may change dynamic type:pfe_if_db_get_first (_2, session_id.0_3, 3, _5, &if_entry);
Determining dynamic type for call: fci_routes_drop_one (entry_2);
  Starting walk at: fci_routes_drop_one (entry_2);
  instance pointer: entry_2  Outer instance pointer: entry_2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_7 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
  Function call may change dynamic type:entry_10 = fci_rt_db_get_next (&MEM[(void *)&context + 24B]);
  Function call may change dynamic type:fci_routes_drop_one (entry_2);
Determining dynamic type for call: fci_routes_drop_one (entry_2);
  Starting walk at: fci_routes_drop_one (entry_2);
  instance pointer: entry_2  Outer instance pointer: entry_2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_7 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
  Function call may change dynamic type:entry_10 = fci_rt_db_get_next (&MEM[(void *)&context + 24B]);
  Function call may change dynamic type:fci_routes_drop_one (entry_2);
Determining dynamic type for call: fci_routes_drop_one (entry_1);
  Starting walk at: fci_routes_drop_one (entry_1);
  instance pointer: entry_1  Outer instance pointer: entry_1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_5 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
  Function call may change dynamic type:entry_8 = fci_rt_db_get_next (&MEM[(void *)&context + 24B]);
  Function call may change dynamic type:fci_routes_drop_one (entry_1);
Determining dynamic type for call: fci_routes_remove_related_connections (route_10(D));
  Starting walk at: fci_routes_remove_related_connections (route_10(D));
  instance pointer: route_10(D)  Outer instance pointer: route_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&msg, 0, 276);
  Function call may change dynamic type:fci_core_client_send (_1, &msg, 0B);
Determining dynamic type for call: ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  Starting walk at: ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  instance pointer: fci_ret_36(D)  Outer instance pointer: fci_ret_36(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
  Function call may change dynamic type:rt_entry_35 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
Determining dynamic type for call: ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  Starting walk at: ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  instance pointer: reply_buf_24(D)  Outer instance pointer: reply_buf_24(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
  Function call may change dynamic type:rt_entry_35 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
Determining dynamic type for call: ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  Starting walk at: ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  instance pointer: reply_len_22(D)  Outer instance pointer: reply_len_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
  Function call may change dynamic type:rt_entry_35 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
Determining dynamic type for call: ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  Starting walk at: ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  instance pointer: rt_entry_17  Outer instance pointer: rt_entry_35 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
  Function call may change dynamic type:rt_entry_35 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
Determining dynamic type for call: ret_42 = routes_cmd_action_deregister (fci_ret_36(D), rt_cmd_27, &MEM[(void *)&context + 24B]);
  Starting walk at: ret_42 = routes_cmd_action_deregister (fci_ret_36(D), rt_cmd_27, &MEM[(void *)&context + 24B]);
  instance pointer: fci_ret_36(D)  Outer instance pointer: fci_ret_36(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
Determining dynamic type for call: ret_42 = routes_cmd_action_deregister (fci_ret_36(D), rt_cmd_27, &MEM[(void *)&context + 24B]);
  Starting walk at: ret_42 = routes_cmd_action_deregister (fci_ret_36(D), rt_cmd_27, &MEM[(void *)&context + 24B]);
  instance pointer: rt_cmd_27  Outer instance pointer: msg_26(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
Determining dynamic type for call: ret_42 = routes_cmd_action_deregister (fci_ret_36(D), rt_cmd_27, &MEM[(void *)&context + 24B]);
  Starting walk at: ret_42 = routes_cmd_action_deregister (fci_ret_36(D), rt_cmd_27, &MEM[(void *)&context + 24B]);
  instance pointer: &MEM[(void *)&context + 24B]  Outer instance pointer: context offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
Determining dynamic type for call: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  Starting walk at: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  instance pointer: _48  Outer instance pointer: msg_26(D) offset: 2176 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
Determining dynamic type for call: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  Starting walk at: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  instance pointer: fci_ret_36(D)  Outer instance pointer: fci_ret_36(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
Determining dynamic type for call: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  Starting walk at: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  instance pointer: rt_cmd_27  Outer instance pointer: msg_26(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
Determining dynamic type for call: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  Starting walk at: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  instance pointer: &ip  Outer instance pointer: ip offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
Determining dynamic type for call: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  Starting walk at: ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  instance pointer: &dst_mac  Outer instance pointer: dst_mac offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (&ip.v6, _13, 16);
  Function call may change dynamic type:autolibc_memset (&ip, 0, 22);
  Function call may change dynamic type:autolibc_memcpy (&dst_mac, _12, 6);
  Function call may change dynamic type:autolibc_memset (reply_buf_24(D), 0, 92);
  Function call may change dynamic type:autolibc_memcpy (&ip.v4, _14, 4);
Determining dynamic type for call: ret_10 = fci_routes_drop_one (rt_entry_8);
  Starting walk at: ret_10 = fci_routes_drop_one (rt_entry_8);
  instance pointer: rt_entry_8  Outer instance pointer: rt_entry_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:rt_entry_8 = fci_rt_db_get_first (route_db_6(D), 5, _1);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  routes_cmd_action_register.isra.0/49:
    callsite  routes_cmd_action_register.isra.0/49 -> prepare_mac_src/17 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_get_next/48:
  Jump functions of caller  pfe_rtable_entry_free/47:
  Jump functions of caller  fci_connections_drop_one/46:
  Jump functions of caller  pfe_rtable_get_first/45:
  Jump functions of caller  fci_rt_db_remove/44:
  Jump functions of caller  fci_core_client_send/43:
  Jump functions of caller  autolibc_strncpy/42:
  Jump functions of caller  pfe_phy_if_get_name/41:
  Jump functions of caller  fci_rt_db_get_next/40:
  Jump functions of caller  pfe_phy_if_get_mac_addr_first/39:
  Jump functions of caller  pfe_phy_if_get_id/38:
  Jump functions of caller  autolibc_memcmp/37:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/36:
  Jump functions of caller  pfe_hm_report/35:
  Jump functions of caller  pfe_if_db_unlock/34:
  Jump functions of caller  fci_rt_db_add/33:
  Jump functions of caller  pfe_if_db_entry_get_phy_if/32:
  Jump functions of caller  pfe_if_db_get_first/31:
  Jump functions of caller  pfe_if_db_lock/30:
  Jump functions of caller  fci_rt_db_get_first/29:
  Jump functions of caller  autolibc_memcpy/28:
  Jump functions of caller  autolibc_memset/27:
  Jump functions of caller  fci_routes_drop_all_ipv6/25:
    callsite  fci_routes_drop_all_ipv6/25 -> fci_routes_drop_one/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_routes_drop_all_ipv4/24:
    callsite  fci_routes_drop_all_ipv4/24 -> fci_routes_drop_one/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_routes_drop_all/23:
    callsite  fci_routes_drop_all/23 -> fci_routes_drop_one/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_routes_drop_one/22:
    callsite  fci_routes_drop_one/22 -> fci_routes_remove_related_connections/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  fci_routes_cmd/21:
    callsite  fci_routes_cmd/21 -> routes_cmd_query_cont/19 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  fci_routes_cmd/21 -> routes_cmd_action_deregister/20 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: &MEM[(void *)&context + 24B]
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  fci_routes_cmd/21 -> routes_cmd_action_register.isra.0/49 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 4: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  routes_cmd_action_deregister/20:
    callsite  routes_cmd_action_deregister/20 -> fci_routes_drop_one/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  routes_cmd_query_cont/19:
  Jump functions of caller  prepare_mac_src/17:
    callsite  prepare_mac_src/17 -> check_if_hif/16 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  check_if_hif/16:
  Jump functions of caller  fci_routes_remove_related_connections/15:

 Propagating constants:

Not considering fci_routes_drop_all_ipv6 for cloning; -fipa-cp-clone disabled.
Not considering fci_routes_drop_all_ipv4 for cloning; -fipa-cp-clone disabled.
Not considering fci_routes_drop_all for cloning; -fipa-cp-clone disabled.
Not considering fci_routes_drop_one for cloning; -fipa-cp-clone disabled.
Not considering fci_routes_cmd for cloning; -fipa-cp-clone disabled.

overall_size: 369, max_new_size: 11001
 - context independent values, size: 26, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: routes_cmd_action_register.isra.0/49:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         void * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_rt_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_ip_addr_t * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint8_t[6] * ~[0B, 0B]
        AGGS VARIABLE
  Node: fci_routes_drop_all_ipv6/25:
  Node: fci_routes_drop_all_ipv4/24:
  Node: fci_routes_drop_all/23:
  Node: fci_routes_drop_one/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: fci_routes_cmd/21:
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
  Node: routes_cmd_action_deregister/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_rt_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: &MEM[(void *)&context + 24B] [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fci_rt_db_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: routes_cmd_query_cont/19:
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
  Node: prepare_mac_src/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint8_t[6] * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct fpp_rt_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: check_if_hif/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fci_routes_remove_related_connections/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of routes_cmd_action_deregister/20 for all known contexts.
    replacing param #2 route_db with const &MEM[(void *)&context + 24B]
Propagated bits info for function routes_cmd_action_deregister.constprop/50:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function routes_cmd_action_register.isra.0/49:
 param 3: value = 0x0, mask = 0xfffffffc
 param 4: value = 0x0, mask = 0xfffffffc
Propagated bits info for function routes_cmd_action_deregister/20:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function prepare_mac_src/17:
 param 0: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: routes_cmd_action_deregister/20
Reclaiming variables:
Clearing address taken flags:
Symbol table:

routes_cmd_action_deregister.constprop.0/50 (routes_cmd_action_deregister.constprop) @077fe0e0
  Type: function definition analyzed
  Visibility:
  References: context/26 (addr)
  Referring: 
  Clone of routes_cmd_action_deregister/20
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: fci_routes_cmd/21 (85496674 (estimated locally),0.08 per call) 
  Calls: fci_rt_db_get_first/29 (1073741824 (estimated locally),1.00 per call) fci_routes_drop_one/22 (574129754 (estimated locally),0.53 per call) pfe_hm_report/35 (189462818 (estimated locally),0.18 per call) oal_util_raise_dem_for_drv_runtime_err/36 (189462818 (estimated locally),0.18 per call) 
routes_cmd_action_register.isra.0/49 (routes_cmd_action_register.isra.0) @06f59a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: context/26 (read)context/26 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_routes_cmd/21 (85496674 (estimated locally),0.08 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/36 (354334802 (estimated locally),0.33 per call) pfe_hm_report/35 (354334802 (estimated locally),0.33 per call) pfe_if_db_unlock/34 (1073741824 (estimated locally),1.00 per call) fci_rt_db_add/33 (574129754 (estimated locally),0.53 per call) prepare_mac_src/17 (574129754 (estimated locally),0.53 per call) pfe_if_db_entry_get_phy_if/32 (574129754 (estimated locally),0.53 per call) pfe_if_db_get_first/31 (354334802 (estimated locally),0.33 per call) pfe_if_db_lock/30 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_get_next/48 (pfe_rtable_get_next) @078c5c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_remove_related_connections/15 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_rtable_entry_free/47 (pfe_rtable_entry_free) @078c5b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_remove_related_connections/15 (955630223 (estimated locally),8.09 per call) 
  Calls: 
fci_connections_drop_one/46 (fci_connections_drop_one) @078c5a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_remove_related_connections/15 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_rtable_get_first/45 (pfe_rtable_get_first) @078c59a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_remove_related_connections/15 (118111600 (estimated locally),1.00 per call) 
  Calls: 
fci_rt_db_remove/44 (fci_rt_db_remove) @078c57e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_drop_one/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
fci_core_client_send/43 (fci_core_client_send) @078c5700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_drop_one/22 (574129754 (estimated locally),0.53 per call) 
  Calls: 
autolibc_strncpy/42 (autolibc_strncpy) @078c5540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_query_cont/19 (977105061 (estimated locally),0.91 per call) 
  Calls: 
pfe_phy_if_get_name/41 (pfe_phy_if_get_name) @078c5460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_query_cont/19 (977105061 (estimated locally),0.91 per call) 
  Calls: 
fci_rt_db_get_next/40 (fci_rt_db_get_next) @078c5380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_drop_all_ipv6/25 (955630223 (estimated locally),8.09 per call) fci_routes_drop_all_ipv4/24 (955630223 (estimated locally),8.09 per call) fci_routes_drop_all/23 (955630223 (estimated locally),8.09 per call) routes_cmd_query_cont/19 (322122547 (estimated locally),0.30 per call) 
  Calls: 
pfe_phy_if_get_mac_addr_first/39 (pfe_phy_if_get_mac_addr_first) @078c5000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prepare_mac_src/17 (351646152 (estimated locally),0.33 per call) 
  Calls: 
pfe_phy_if_get_id/38 (pfe_phy_if_get_id) @078abee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prepare_mac_src/17 (719407023 (estimated locally),0.67 per call) 
  Calls: 
autolibc_memcmp/37 (autolibc_memcmp) @078abe00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prepare_mac_src/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/36 (oal_util_raise_dem_for_drv_runtime_err) @078abc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_action_deregister.constprop/50 (189462818 (estimated locally),0.18 per call) fci_routes_drop_one/22 (354334802 (estimated locally),0.33 per call) routes_cmd_action_register.isra.0/49 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_hm_report/35 (pfe_hm_report) @078abb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_action_deregister.constprop/50 (189462818 (estimated locally),0.18 per call) fci_routes_drop_one/22 (354334802 (estimated locally),0.33 per call) routes_cmd_action_register.isra.0/49 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_if_db_unlock/34 (pfe_if_db_unlock) @078aba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_action_register.isra.0/49 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
fci_rt_db_add/33 (fci_rt_db_add) @078ab9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_action_register.isra.0/49 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_if_db_entry_get_phy_if/32 (pfe_if_db_entry_get_phy_if) @078ab8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_action_register.isra.0/49 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_if_db_get_first/31 (pfe_if_db_get_first) @078ab7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_action_register.isra.0/49 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_if_db_lock/30 (pfe_if_db_lock) @078ab700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_action_register.isra.0/49 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
fci_rt_db_get_first/29 (fci_rt_db_get_first) @078ab540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: routes_cmd_action_deregister.constprop/50 (1073741824 (estimated locally),1.00 per call) fci_routes_drop_all_ipv6/25 (118111602 (estimated locally),1.00 per call) fci_routes_drop_all_ipv4/24 (118111602 (estimated locally),1.00 per call) fci_routes_drop_all/23 (118111600 (estimated locally),1.00 per call) fci_routes_cmd/21 (85496674 (estimated locally),0.08 per call) 
  Calls: 
autolibc_memcpy/28 (autolibc_memcpy) @078ab460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_cmd/21 (338499130 (estimated locally),0.32 per call) fci_routes_cmd/21 (174378340 (estimated locally),0.16 per call) fci_routes_cmd/21 (512877470 (estimated locally),0.48 per call) routes_cmd_query_cont/19 (488552530 (estimated locally),0.46 per call) routes_cmd_query_cont/19 (488552530 (estimated locally),0.46 per call) routes_cmd_query_cont/19 (977105061 (estimated locally),0.91 per call) routes_cmd_query_cont/19 (977105061 (estimated locally),0.91 per call) prepare_mac_src/17 (354334802 (estimated locally),0.33 per call) 
  Calls: 
autolibc_memset/27 (autolibc_memset) @078ab380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_routes_cmd/21 (512877470 (estimated locally),0.48 per call) fci_routes_cmd/21 (512877470 (estimated locally),0.48 per call) fci_routes_drop_one/22 (1073741824 (estimated locally),1.00 per call) prepare_mac_src/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
context/26 (context) @078a5870
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: fci_routes_remove_related_connections/15 (read)fci_routes_drop_all/23 (addr)fci_routes_drop_all_ipv4/24 (addr)routes_cmd_query_cont/19 (addr)routes_cmd_action_register.isra.0/49 (addr)fci_routes_drop_one/22 (addr)fci_routes_cmd/21 (addr)fci_routes_drop_all_ipv6/25 (addr)fci_routes_drop_all_ipv6/25 (addr)routes_cmd_action_register.isra.0/49 (read)fci_routes_remove_related_connections/15 (read)fci_routes_remove_related_connections/15 (read)fci_routes_cmd/21 (addr)fci_routes_drop_all/23 (addr)fci_routes_drop_all_ipv4/24 (addr)routes_cmd_action_deregister.constprop.0/50 (addr)
  Availability: not_available
  Varpool flags:
fci_routes_drop_all_ipv6/25 (fci_routes_drop_all_ipv6) @077fee00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/26 (addr)context/26 (addr)
  Referring: 
  Availability: available
  Function flags: count:118111602 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_rt_db_get_next/40 (955630223 (estimated locally),8.09 per call) fci_routes_drop_one/22 (315357973 (estimated locally),2.67 per call) fci_rt_db_get_first/29 (118111602 (estimated locally),1.00 per call) 
fci_routes_drop_all_ipv4/24 (fci_routes_drop_all_ipv4) @077fe7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/26 (addr)context/26 (addr)
  Referring: 
  Availability: available
  Function flags: count:118111602 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_rt_db_get_next/40 (955630223 (estimated locally),8.09 per call) fci_routes_drop_one/22 (315357973 (estimated locally),2.67 per call) fci_rt_db_get_first/29 (118111602 (estimated locally),1.00 per call) 
fci_routes_drop_all/23 (fci_routes_drop_all) @077fe1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/26 (addr)context/26 (addr)
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_rt_db_get_next/40 (955630223 (estimated locally),8.09 per call) fci_routes_drop_one/22 (955630223 (estimated locally),8.09 per call) fci_rt_db_get_first/29 (118111600 (estimated locally),1.00 per call) 
fci_routes_drop_one/22 (fci_routes_drop_one) @077fed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/26 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: routes_cmd_action_deregister.constprop/50 (574129754 (estimated locally),0.53 per call) fci_routes_drop_all_ipv6/25 (315357973 (estimated locally),2.67 per call) fci_routes_drop_all_ipv4/24 (315357973 (estimated locally),2.67 per call) fci_routes_drop_all/23 (955630223 (estimated locally),8.09 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/36 (354334802 (estimated locally),0.33 per call) pfe_hm_report/35 (354334802 (estimated locally),0.33 per call) fci_rt_db_remove/44 (1073741824 (estimated locally),1.00 per call) fci_routes_remove_related_connections/15 (1073741824 (estimated locally),1.00 per call) fci_core_client_send/43 (574129754 (estimated locally),0.53 per call) autolibc_memset/27 (1073741824 (estimated locally),1.00 per call) 
fci_routes_cmd/21 (fci_routes_cmd) @077fe9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: context/26 (addr)context/26 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073639251 (estimated locally) body optimize_size
  Called by: 
  Calls: routes_cmd_query_cont/19 (145344346 (estimated locally),0.14 per call) fci_rt_db_get_first/29 (85496674 (estimated locally),0.08 per call) routes_cmd_action_deregister.constprop/50 (85496674 (estimated locally),0.08 per call) routes_cmd_action_register.isra.0/49 (85496674 (estimated locally),0.08 per call) autolibc_memcpy/28 (338499130 (estimated locally),0.32 per call) autolibc_memcpy/28 (174378340 (estimated locally),0.16 per call) autolibc_memset/27 (512877470 (estimated locally),0.48 per call) autolibc_memcpy/28 (512877470 (estimated locally),0.48 per call) autolibc_memset/27 (512877470 (estimated locally),0.48 per call) 
routes_cmd_action_deregister/20 (routes_cmd_action_deregister) @077fe700
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
routes_cmd_query_cont/19 (routes_cmd_query_cont) @077fe380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/26 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: fci_routes_cmd/21 (145344346 (estimated locally),0.14 per call) 
  Calls: autolibc_strncpy/42 (977105061 (estimated locally),0.91 per call) pfe_phy_if_get_name/41 (977105061 (estimated locally),0.91 per call) autolibc_memcpy/28 (488552530 (estimated locally),0.46 per call) autolibc_memcpy/28 (488552530 (estimated locally),0.46 per call) autolibc_memcpy/28 (977105061 (estimated locally),0.91 per call) autolibc_memcpy/28 (977105061 (estimated locally),0.91 per call) fci_rt_db_get_next/40 (322122547 (estimated locally),0.30 per call) 
prepare_mac_src/17 (prepare_mac_src) @077f1c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: routes_cmd_action_register.isra.0/49 (574129754 (estimated locally),0.53 per call) 
  Calls: autolibc_memcpy/28 (354334802 (estimated locally),0.33 per call) pfe_phy_if_get_mac_addr_first/39 (351646152 (estimated locally),0.33 per call) check_if_hif/16 (719407023 (estimated locally),0.67 per call) pfe_phy_if_get_id/38 (719407023 (estimated locally),0.67 per call) autolibc_memcmp/37 (1073741824 (estimated locally),1.00 per call) autolibc_memset/27 (1073741824 (estimated locally),1.00 per call) 
check_if_hif/16 (check_if_hif) @077f1e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: prepare_mac_src/17 (719407023 (estimated locally),0.67 per call) 
  Calls: 
fci_routes_remove_related_connections/15 (fci_routes_remove_related_connections) @077f1b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: context/26 (read)context/26 (read)context/26 (read)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: fci_routes_drop_one/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_rtable_get_next/48 (955630223 (estimated locally),8.09 per call) pfe_rtable_entry_free/47 (955630223 (estimated locally),8.09 per call) fci_connections_drop_one/46 (955630223 (estimated locally),8.09 per call) pfe_rtable_get_first/45 (118111600 (estimated locally),1.00 per call) 

;; Function fci_routes_drop_one (fci_routes_drop_one, funcdef_no=19, decl_uid=12248, cgraph_uid=20, symbol_order=22)

Modification phase of node fci_routes_drop_one/22
fci_routes_drop_one (struct fci_rt_db_entry_t * route)
{
  errno_t ret;
  struct fci_msg_t msg;
  void * _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG rt_cmd => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&msg, 0, 276);
  # DEBUG BEGIN_STMT
  msg.type = 4099;
  # DEBUG BEGIN_STMT
  msg.msg_cmd.code = 787;
  # DEBUG BEGIN_STMT
  # DEBUG rt_cmd => &msg.msg_cmd.payload
  # DEBUG BEGIN_STMT
  MEM[(struct fpp_rt_cmd_t *)&msg + 16B].action = 3;
  # DEBUG BEGIN_STMT
  _1 = route_10(D)->refptr;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _2 = route_10(D)->id;
  MEM[(struct fpp_rt_cmd_t *)&msg + 16B].id = _2;
  # DEBUG BEGIN_STMT
  fci_core_client_send (_1, &msg, 0B);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  fci_routes_remove_related_connections (route_10(D));
  # DEBUG BEGIN_STMT
  ret_15 = fci_rt_db_remove (&MEM[(void *)&context + 24B], route_10(D));
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  if (ret_15 != 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t remove route: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/fci_routes.c", 473, ret_15, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  msg ={v} {CLOBBER};
  return ret_15;

}



;; Function fci_routes_cmd (fci_routes_cmd, funcdef_no=18, decl_uid=12203, cgraph_uid=19, symbol_order=21)

Modification phase of node fci_routes_cmd/21
fci_routes_cmd (struct fci_msg_t * msg, uint16_t * fci_ret, struct fpp_rt_cmd_t * reply_buf, uint32_t * reply_len)
{
  struct fci_rt_db_entry_t * rt_entry;
  struct pfe_ip_addr_t ip;
  uint8_t dst_mac[6];
  errno_t ret;
  struct fpp_rt_cmd_t * rt_cmd;
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
  uint8_t[6] * _12;
  uint32_t * _13;
  uint32_t * _14;
  short unsigned int _15;
  void * * _48;

  <bb 2> [local count: 1073639251]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG is_ipv6 => 0
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG rt_entry => 0B
  # DEBUG BEGIN_STMT
  _1 = *reply_len_22(D);
  if (_1 <= 91)
    goto <bb 14>; [52.23%]
  else
    goto <bb 3>; [47.77%]

  <bb 3> [local count: 512877470]:
  # DEBUG BEGIN_STMT
  *reply_len_22(D) = 0;
  # DEBUG BEGIN_STMT
  autolibc_memset (reply_buf_24(D), 0, 92);
  # DEBUG BEGIN_STMT
  rt_cmd_27 = &msg_26(D)->msg_cmd.payload;
  # DEBUG rt_cmd => rt_cmd_27
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct fpp_rt_cmd_t *)msg_26(D) + 16B].flags;
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  _11 = _9 | _10;
  # DEBUG D#2 => _11 == 2
  # DEBUG is_ipv6 => (bool_t) D#2
  # DEBUG BEGIN_STMT
  _12 = &MEM[(struct fpp_rt_cmd_t *)msg_26(D) + 16B].dst_mac;
  autolibc_memcpy (&dst_mac, _12, 6);
  # DEBUG BEGIN_STMT
  autolibc_memset (&ip, 0, 22);
  # DEBUG BEGIN_STMT
  if (_11 == 2)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 174378340]:
  # DEBUG BEGIN_STMT
  _13 = &MEM[(struct fpp_rt_cmd_t *)msg_26(D) + 16B].dst_addr[0];
  autolibc_memcpy (&ip.v6, _13, 16);
  # DEBUG BEGIN_STMT
  ip.is_ipv4 = 0;
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 338499130]:
  # DEBUG BEGIN_STMT
  _14 = &MEM[(struct fpp_rt_cmd_t *)msg_26(D) + 16B].dst_addr[0];
  autolibc_memcpy (&ip.v4, _14, 4);
  # DEBUG BEGIN_STMT
  ip.is_ipv4 = 1;

  <bb 6> [local count: 512877469]:
  # DEBUG BEGIN_STMT
  _15 = MEM[(struct fpp_rt_cmd_t *)msg_26(D) + 16B].action;
  switch (_15) <default: <L12> [16.67%], case 0: <L5> [16.67%], case 1: <L6> [16.67%], case 4: <L7> [16.67%], case 6: <L8> [16.67%], case 7: <L10> [16.67%]>

  <bb 7> [local count: 85496674]:
<L5>:
  # DEBUG BEGIN_STMT
  _48 = &MEM[(void * *)msg_26(D) + 272B];
  # DEBUG D#1 => msg_26(D)
  ret_44 = routes_cmd_action_register.isra.0 (_48, fci_ret_36(D), rt_cmd_27, &ip, &dst_mac);
  # DEBUG ret => ret_44
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 8> [local count: 85496674]:
<L6>:
  # DEBUG BEGIN_STMT
  ret_42 = routes_cmd_action_deregister (fci_ret_36(D), rt_cmd_27, &MEM[(void *)&context + 24B]);
  # DEBUG ret => ret_42
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 9> [local count: 85496674]:
<L7>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_36(D) = 1;
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 10> [local count: 85496674]:
<L8>:
  # DEBUG BEGIN_STMT
  rt_entry_35 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
  # DEBUG rt_entry => rt_entry_35
  # DEBUG BEGIN_STMT
  if (rt_entry_35 == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 12>; [70.00%]

  <bb 11> [local count: 25649002]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  *fci_ret_36(D) = 201;
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 12> [local count: 145344346]:
  # rt_entry_17 = PHI <0B(6), rt_entry_35(10)>
<L10>:
  # DEBUG rt_entry => rt_entry_17
  # DEBUG BEGIN_STMT
  ret_39 = routes_cmd_query_cont (fci_ret_36(D), reply_buf_24(D), reply_len_22(D), rt_entry_17);
  # DEBUG ret => ret_39
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 85496674]:
<L12>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *fci_ret_36(D) = 4;
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 1073741824]:
  # ret_16 = PHI <22(2), ret_44(7), ret_42(8), 0(9), 0(11), ret_39(12), 0(13)>
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  dst_mac ={v} {CLOBBER};
  ip ={v} {CLOBBER};
  return ret_16;

}



;; Function fci_routes_drop_all (fci_routes_drop_all, funcdef_no=20, decl_uid=12227, cgraph_uid=21, symbol_order=23)

Modification phase of node fci_routes_drop_all/23
fci_routes_drop_all ()
{
  struct fci_rt_db_entry_t * entry;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_5 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
  # DEBUG entry => entry_5
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  fci_routes_drop_one (entry_1);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_8 = fci_rt_db_get_next (&MEM[(void *)&context + 24B]);
  # DEBUG entry => entry_8

  <bb 4> [local count: 1073741824]:
  # entry_1 = PHI <entry_5(2), entry_8(3)>
  # DEBUG entry => entry_1
  # DEBUG BEGIN_STMT
  if (entry_1 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  return;

}



;; Function fci_routes_drop_all_ipv4 (fci_routes_drop_all_ipv4, funcdef_no=21, decl_uid=12229, cgraph_uid=22, symbol_order=24)

Modification phase of node fci_routes_drop_all_ipv4/24
fci_routes_drop_all_ipv4 ()
{
  struct fci_rt_db_entry_t * entry;
  unsigned char _1;

  <bb 2> [local count: 118111602]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_7 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
  # DEBUG entry => entry_7
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = entry_2->dst_ip.is_ipv4;
  if (_1 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 315357973]:
  # DEBUG BEGIN_STMT
  fci_routes_drop_one (entry_2);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_10 = fci_rt_db_get_next (&MEM[(void *)&context + 24B]);
  # DEBUG entry => entry_10

  <bb 6> [local count: 1073741824]:
  # entry_2 = PHI <entry_7(2), entry_10(5)>
  # DEBUG entry => entry_2
  # DEBUG BEGIN_STMT
  if (entry_2 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  return;

}



;; Function fci_routes_drop_all_ipv6 (fci_routes_drop_all_ipv6, funcdef_no=22, decl_uid=12231, cgraph_uid=23, symbol_order=25)

Modification phase of node fci_routes_drop_all_ipv6/25
fci_routes_drop_all_ipv6 ()
{
  struct fci_rt_db_entry_t * entry;
  unsigned char _1;

  <bb 2> [local count: 118111602]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_7 = fci_rt_db_get_first (&MEM[(void *)&context + 24B], 0, 0B);
  # DEBUG entry => entry_7
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = entry_2->dst_ip.is_ipv4;
  if (_1 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 315357973]:
  # DEBUG BEGIN_STMT
  fci_routes_drop_one (entry_2);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_10 = fci_rt_db_get_next (&MEM[(void *)&context + 24B]);
  # DEBUG entry => entry_10

  <bb 6> [local count: 1073741824]:
  # entry_2 = PHI <entry_7(2), entry_10(5)>
  # DEBUG entry => entry_2
  # DEBUG BEGIN_STMT
  if (entry_2 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  return;

}


