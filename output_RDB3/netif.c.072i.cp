
IPA constant propagation start:
Determining dynamic type for call: netif_issue_reports (netif_3(D), 1);
  Starting walk at: netif_issue_reports (netif_3(D), 1);
  instance pointer: netif_3(D)  Outer instance pointer: netif_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_do_ip_addr_changed (old_addr_5(D), &new_addr);
Determining dynamic type for call: netif_do_ip_addr_changed (old_addr_5(D), &new_addr);
  Starting walk at: netif_do_ip_addr_changed (old_addr_5(D), &new_addr);
  instance pointer: old_addr_5(D)  Outer instance pointer: old_addr_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_do_ip_addr_changed (old_addr_5(D), &new_addr);
  Starting walk at: netif_do_ip_addr_changed (old_addr_5(D), &new_addr);
  instance pointer: &new_addr  Outer instance pointer: new_addr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_6 = netif_find (name_4(D));
  Starting walk at: netif_6 = netif_find (name_4(D));
  instance pointer: name_4(D)  Outer instance pointer: name_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_issue_reports (netif_4(D), 3);
  Starting walk at: netif_issue_reports (netif_4(D), 3);
  instance pointer: netif_4(D)  Outer instance pointer: netif_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_issue_reports.part.0 (netif_8(D));
  Starting walk at: netif_issue_reports.part.0 (netif_8(D));
  instance pointer: netif_8(D)  Outer instance pointer: netif_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:etharp_request (netif_8(D), _5);
Determining dynamic type for call: netif_issue_reports (netif_6(D), 3);
  Starting walk at: netif_issue_reports (netif_6(D), 3);
  instance pointer: netif_6(D)  Outer instance pointer: netif_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = sys_now ();
Determining dynamic type for call: netif_do_ip_addr_changed (_2, 0B);
  Starting walk at: netif_do_ip_addr_changed (_2, 0B);
  instance pointer: _2  Outer instance pointer: netif_18(D) offset: 32 (bits) vtbl reference: 
Determining dynamic type for call: netif_do_ip_addr_changed (_2, 0B);
  Starting walk at: netif_do_ip_addr_changed (_2, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_set_down (netif_18(D));
  Starting walk at: netif_set_down (netif_18(D));
  instance pointer: netif_18(D)  Outer instance pointer: netif_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_do_ip_addr_changed (_2, 0B);
  Function call may change dynamic type:igmp_stop (netif_18(D));
Determining dynamic type for call: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  instance pointer: netif_11(D)  Outer instance pointer: netif_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  instance pointer: ipaddr_2  Outer instance pointer: ipaddr_2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  instance pointer: &old_addr  Outer instance pointer: old_addr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  instance pointer: netif_11(D)  Outer instance pointer: netif_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
Determining dynamic type for call: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  instance pointer: ipaddr_2  Outer instance pointer: ipaddr_2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
Determining dynamic type for call: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
  instance pointer: &old_addr  Outer instance pointer: old_addr offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);
Determining dynamic type for call: netif_do_set_ipaddr (netif_3(D), ipaddr_1, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_3(D), ipaddr_1, &old_addr);
  instance pointer: netif_3(D)  Outer instance pointer: netif_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_do_set_ipaddr (netif_3(D), ipaddr_1, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_3(D), ipaddr_1, &old_addr);
  instance pointer: ipaddr_1  Outer instance pointer: ipaddr_1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_do_set_ipaddr (netif_3(D), ipaddr_1, &old_addr);
  Starting walk at: netif_do_set_ipaddr (netif_3(D), ipaddr_1, &old_addr);
  instance pointer: &old_addr  Outer instance pointer: old_addr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = netif_do_set_ipaddr.part.0 (netif_8(D), ipaddr_5(D), old_addr_7(D));
  Starting walk at: _2 = netif_do_set_ipaddr.part.0 (netif_8(D), ipaddr_5(D), old_addr_7(D));
  instance pointer: netif_8(D)  Outer instance pointer: netif_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = netif_do_set_ipaddr.part.0 (netif_8(D), ipaddr_5(D), old_addr_7(D));
  Starting walk at: _2 = netif_do_set_ipaddr.part.0 (netif_8(D), ipaddr_5(D), old_addr_7(D));
  instance pointer: ipaddr_5(D)  Outer instance pointer: ipaddr_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = netif_do_set_ipaddr.part.0 (netif_8(D), ipaddr_5(D), old_addr_7(D));
  Starting walk at: _2 = netif_do_set_ipaddr.part.0 (netif_8(D), ipaddr_5(D), old_addr_7(D));
  instance pointer: old_addr_7(D)  Outer instance pointer: old_addr_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = init_28(D) (netif_27(D));
  Starting walk at: _3 = init_28(D) (netif_27(D));
  instance pointer: netif_27(D)  Outer instance pointer: netif_27(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
Determining dynamic type for call: netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  Starting walk at: netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  instance pointer: netif_27(D)  Outer instance pointer: netif_27(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  Starting walk at: netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  instance pointer: ipaddr_14  Outer instance pointer: ipaddr_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (_1, 0, 8);
Determining dynamic type for call: netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  Starting walk at: netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  instance pointer: netmask_15  Outer instance pointer: netmask_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (_1, 0, 8);
Determining dynamic type for call: netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  Starting walk at: netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  instance pointer: gw_16  Outer instance pointer: gw_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (_1, 0, 8);
Determining dynamic type for call: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  Starting walk at: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  instance pointer: netif_2(D)  Outer instance pointer: netif_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  Starting walk at: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  Starting walk at: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  Starting walk at: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  Starting walk at: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  instance pointer: state_3(D)  Outer instance pointer: state_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  Starting walk at: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  instance pointer: init_4(D)  Outer instance pointer: init_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  Starting walk at: _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  instance pointer: input_5(D)  Outer instance pointer: input_5(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  netif_do_set_ipaddr.part.0/47:
    callsite  netif_do_set_ipaddr.part.0/47 -> netif_do_ip_addr_changed/9 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  netif_do_set_ipaddr.part.0/47 -> netif_issue_reports/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  netif_issue_reports.part.0/46:
  Jump functions of caller  atoi/43:
  Jump functions of caller  lwip_itoa/42:
  Jump functions of caller  etharp_cleanup_netif/41:
  Jump functions of caller  sys_now/40:
  Jump functions of caller  igmp_stop/39:
  Jump functions of caller  igmp_report_groups/38:
  Jump functions of caller  etharp_request/37:
  Jump functions of caller  udp_netif_ip_addr_changed/36:
  Jump functions of caller  tcp_netif_ip_addr_changed/35:
  Jump functions of caller  igmp_start/34:
  Jump functions of caller  memset/33:
  Jump functions of caller  ip4_input/31:
  Jump functions of caller  ethernet_input/30:
  Jump functions of caller  netif_find/29:
  Jump functions of caller  netif_get_by_index/28:
  Jump functions of caller  netif_index_to_name/27:
    callsite  netif_index_to_name/27 -> netif_get_by_index/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  netif_name_to_index/26:
    callsite  netif_name_to_index/26 -> netif_find/29 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  netif_null_output_ip4/25:
  Jump functions of caller  netif_alloc_client_data_id/24:
  Jump functions of caller  netif_set_link_down/23:
  Jump functions of caller  netif_set_link_up/22:
    callsite  netif_set_link_up/22 -> netif_issue_reports/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
  Jump functions of caller  netif_set_down/21:
  Jump functions of caller  netif_issue_reports/20:
    callsite  netif_issue_reports/20 -> netif_issue_reports.part.0/46 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  netif_set_up/19:
    callsite  netif_set_up/19 -> netif_issue_reports/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
  Jump functions of caller  netif_set_default/18:
  Jump functions of caller  netif_remove/17:
    callsite  netif_remove/17 -> netif_set_down/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  netif_remove/17 -> netif_do_ip_addr_changed/9 : 
       param 0: ANCESTOR: 0, offset 32, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  netif_set_addr/16:
    callsite  netif_set_addr/16 -> netif_do_set_ipaddr/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  netif_set_addr/16 -> netif_do_set_ipaddr/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  netif_set_gw/15:
  Jump functions of caller  netif_set_netmask/13:
  Jump functions of caller  netif_set_ipaddr/11:
    callsite  netif_set_ipaddr/11 -> netif_do_set_ipaddr/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  netif_do_set_ipaddr/10:
    callsite  netif_do_set_ipaddr/10 -> netif_do_set_ipaddr.part.0/47 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  netif_do_ip_addr_changed/9:
  Jump functions of caller  netif_add/8:
    callsite  netif_add/8 -> netif_set_addr/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 864, cst: 0B
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
         Unknown VR
    indirect simple callsite, calling param 5, offset 0, for stmt _3 = init_28(D) (netif_27(D));
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  netif_add_noaddr/7:
    callsite  netif_add_noaddr/7 -> netif_add/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 2: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 3: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 4: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  netif_input/6:
  Jump functions of caller  netif_init/5:

 Propagating constants:

Not considering netif_find for cloning; -fipa-cp-clone disabled.
Not considering netif_get_by_index for cloning; -fipa-cp-clone disabled.
Not considering netif_index_to_name for cloning; -fipa-cp-clone disabled.
Not considering netif_name_to_index for cloning; -fipa-cp-clone disabled.
Not considering netif_null_output_ip4 for cloning; -fipa-cp-clone disabled.
Not considering netif_alloc_client_data_id for cloning; -fipa-cp-clone disabled.
Not considering netif_set_link_down for cloning; -fipa-cp-clone disabled.
Not considering netif_set_link_up for cloning; -fipa-cp-clone disabled.
Not considering netif_set_down for cloning; -fipa-cp-clone disabled.
Not considering netif_set_up for cloning; -fipa-cp-clone disabled.
Not considering netif_set_default for cloning; -fipa-cp-clone disabled.
Not considering netif_remove for cloning; -fipa-cp-clone disabled.
Not considering netif_set_addr for cloning; -fipa-cp-clone disabled.
Not considering netif_set_gw for cloning; -fipa-cp-clone disabled.
Not considering netif_set_netmask for cloning; -fipa-cp-clone disabled.
Not considering netif_set_ipaddr for cloning; -fipa-cp-clone disabled.
Not considering netif_add for cloning; -fipa-cp-clone disabled.
Not considering netif_add_noaddr for cloning; -fipa-cp-clone disabled.
Not considering netif_input for cloning; -fipa-cp-clone disabled.
Not considering netif_init for cloning; -fipa-cp-clone disabled.

overall_size: 452, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 3.000000

IPA lattices after all propagation:

Lattices:
  Node: netif_do_set_ipaddr.part.0/47:
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
         struct ip_addr_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: netif_issue_reports.part.0/46:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: netif_find/29:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_get_by_index/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_index_to_name/27:
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
  Node: netif_name_to_index/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_null_output_ip4/25:
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
  Node: netif_alloc_client_data_id/24:
  Node: netif_set_link_down/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_set_link_up/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_set_down/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_issue_reports/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 2, loc_size: 22, prop_time: 0, prop_size: 0]
               3 [loc_time: 2, loc_size: 22, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x3, mask = 0x2
         u8_t [1, 3]
        AGGS VARIABLE
  Node: netif_set_up/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_set_default/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_remove/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_set_addr/16:
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
  Node: netif_set_gw/15:
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
  Node: netif_set_netmask/13:
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
  Node: netif_set_ipaddr/11:
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
  Node: netif_do_set_ipaddr/10:
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
         struct ip_addr_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: netif_do_ip_addr_changed/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct ip_addr_t * ~[0B, 0B]
        AGGS BOTTOM
    param [1]: VARIABLE
               0B [loc_time: 1, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         VARYING
        AGGS VARIABLE
  Node: netif_add/8:
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
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: netif_add_noaddr/7:
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
  Node: netif_input/6:
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
  Node: netif_init/5:

IPA decision stage:

Propagated bits info for function netif_do_set_ipaddr.part.0/47:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function netif_issue_reports/20:
 param 1: value = 0x3, mask = 0x2
Propagated bits info for function netif_do_set_ipaddr/10:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function netif_do_ip_addr_changed/9:
 param 1: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

netif_do_set_ipaddr.part.0/47 (netif_do_set_ipaddr.part.0) @07279b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: netif_do_set_ipaddr/10 (175378 (estimated locally),0.49 per call) 
  Calls: netif_do_ip_addr_changed/9 (354334802 (estimated locally),0.33 per call) netif_issue_reports/20 (354334802 (estimated locally),0.33 per call) 
netif_issue_reports.part.0/46 (netif_issue_reports.part.0) @07279460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: netif_issue_reports/20 (31317 (estimated locally),0.09 per call) 
  Calls: igmp_report_groups/38 (354334802 (estimated locally),0.33 per call) 
atoi/43 (atoi) @07224a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_find/29 (76616578 (estimated locally),0.85 per call) 
  Calls: 
lwip_itoa/42 (lwip_itoa) @072247e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_index_to_name/27 (635440412 (estimated locally),0.59 per call) 
  Calls: 
etharp_cleanup_netif/41 (etharp_cleanup_netif) @072242a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_set_down/21 (95777760 (estimated locally),0.09 per call) 
  Calls: 
sys_now/40 (sys_now) @072240e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_set_down/21 (290235636 (estimated locally),0.27 per call) netif_set_up/19 (290235636 (estimated locally),0.27 per call) 
  Calls: 
igmp_stop/39 (igmp_stop) @07211e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_remove/17 (54149951 (estimated locally),0.27 per call) 
  Calls: 
igmp_report_groups/38 (igmp_report_groups) @07211620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_issue_reports.part.0/46 (354334802 (estimated locally),0.33 per call) 
  Calls: 
etharp_request/37 (etharp_request) @07211540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_issue_reports/20 (10335 (estimated locally),0.03 per call) 
  Calls: 
udp_netif_ip_addr_changed/36 (udp_netif_ip_addr_changed) @07211380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_do_ip_addr_changed/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_netif_ip_addr_changed/35 (tcp_netif_ip_addr_changed) @072112a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_do_ip_addr_changed/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igmp_start/34 (igmp_start) @071cf000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_add/8 (2582 (estimated locally),0.01 per call) 
  Calls: 
memset/33 (memset) @071cfee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_add/8 (185391 (estimated locally),0.84 per call) 
  Calls: 
ip_addr_any/32 (ip_addr_any) @071dd048
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: netif_set_addr/16 (addr)netif_set_addr/16 (addr)netif_set_gw/15 (addr)netif_set_netmask/13 (addr)netif_set_addr/16 (addr)netif_set_ipaddr/11 (addr)netif_add/8 (addr)netif_add/8 (addr)netif_add/8 (addr)
  Availability: not_available
  Varpool flags: read-only
ip4_input/31 (ip4_input) @071cfa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_input/6 (87689 (estimated locally),0.25 per call) 
  Calls: 
ethernet_input/30 (ethernet_input) @071cf9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netif_input/6 (87689 (estimated locally),0.25 per call) 
  Calls: 
netif_find/29 (netif_find) @071cf460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: netif_list/1 (read)
  Referring: 
  Availability: available
  Function flags: count:90638327 (estimated locally) body optimize_size
  Called by: netif_name_to_index/26 (1073741824 (estimated locally),1.00 per call) 
  Calls: atoi/43 (76616578 (estimated locally),0.85 per call) 
netif_get_by_index/28 (netif_get_by_index) @071cf1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: netif_list/1 (read)
  Referring: 
  Availability: available
  Function flags: count:161779623 (estimated locally) body optimize_size
  Called by: netif_index_to_name/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_index_to_name/27 (netif_index_to_name) @071c4e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: lwip_itoa/42 (635440412 (estimated locally),0.59 per call) netif_get_by_index/28 (1073741824 (estimated locally),1.00 per call) 
netif_name_to_index/26 (netif_name_to_index) @071c48c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: netif_find/29 (1073741824 (estimated locally),1.00 per call) 
netif_null_output_ip4/25 (netif_null_output_ip4) @071c42a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: netif_add/8 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
netif_alloc_client_data_id/24 (netif_alloc_client_data_id) @071c4d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: netif_client_id/4 (read)netif_client_id/4 (write)
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: 
netif_set_link_down/23 (netif_set_link_down) @071c4a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
netif_set_link_up/22 (netif_set_link_up) @071c47e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: netif_issue_reports/20 (290235636 (estimated locally),0.27 per call) 
netif_set_down/21 (netif_set_down) @071c4540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: netif_remove/17 (54149951 (estimated locally),0.27 per call) 
  Calls: etharp_cleanup_netif/41 (95777760 (estimated locally),0.09 per call) sys_now/40 (290235636 (estimated locally),0.27 per call) 
netif_issue_reports/20 (netif_issue_reports) @071c41c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: netif_set_link_up/22 (290235636 (estimated locally),0.27 per call) netif_set_up/19 (290235636 (estimated locally),0.27 per call) netif_do_set_ipaddr.part.0/47 (354334802 (estimated locally),0.33 per call) 
  Calls: netif_issue_reports.part.0/46 (31317 (estimated locally),0.09 per call) etharp_request/37 (10335 (estimated locally),0.03 per call) 
netif_set_up/19 (netif_set_up) @071bd7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: netif_issue_reports/20 (290235636 (estimated locally),0.27 per call) sys_now/40 (290235636 (estimated locally),0.27 per call) 
netif_set_default/18 (netif_set_default) @071bdee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: netif_default/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
netif_remove/17 (netif_remove) @071bdc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: netif_default/2 (read)netif_default/2 (write)netif_list/1 (read)netif_list/1 (write)
  Referring: 
  Availability: available
  Function flags: count:200330558 (estimated locally) body optimize_size
  Called by: 
  Calls: netif_set_down/21 (54149951 (estimated locally),0.27 per call) igmp_stop/39 (54149951 (estimated locally),0.27 per call) netif_do_ip_addr_changed/9 (54149951 (estimated locally),0.27 per call) 
netif_set_addr/16 (netif_set_addr) @071bd700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/32 (addr)ip_addr_any/32 (addr)ip_addr_any/32 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: netif_add/8 (185391 (estimated locally),0.84 per call) 
  Calls: netif_do_set_ipaddr/10 (354334802 (estimated locally),0.33 per call) netif_do_set_ipaddr/10 (630447513 (estimated locally),0.59 per call) 
netif_set_gw/15 (netif_set_gw) @071bd380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/32 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
netif_set_netmask/13 (netif_set_netmask) @071b3ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/32 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
netif_set_ipaddr/11 (netif_set_ipaddr) @071b38c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/32 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: netif_do_set_ipaddr/10 (879501928 (estimated locally),0.82 per call) 
netif_do_set_ipaddr/10 (netif_do_set_ipaddr) @071b3620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: netif_set_addr/16 (354334802 (estimated locally),0.33 per call) netif_set_addr/16 (630447513 (estimated locally),0.59 per call) netif_set_ipaddr/11 (879501928 (estimated locally),0.82 per call) 
  Calls: netif_do_set_ipaddr.part.0/47 (175378 (estimated locally),0.49 per call) 
netif_do_ip_addr_changed/9 (netif_do_ip_addr_changed) @071b31c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: netif_remove/17 (54149951 (estimated locally),0.27 per call) netif_do_set_ipaddr.part.0/47 (354334802 (estimated locally),0.33 per call) 
  Calls: udp_netif_ip_addr_changed/36 (1073741824 (estimated locally),1.00 per call) tcp_netif_ip_addr_changed/35 (1073741824 (estimated locally),1.00 per call) 
netif_add/8 (netif_add) @071a62a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/32 (addr)ip_addr_any/32 (addr)netif_null_output_ip4/25 (addr)netif_num/3 (read)ip_addr_any/32 (addr)netif_list/1 (read)netif_num/3 (write)netif_num/3 (write)netif_list/1 (write)
  Referring: 
  Availability: available
  Function flags: count:220326 (estimated locally) body optimize_size
  Called by: netif_add_noaddr/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: igmp_start/34 (2582 (estimated locally),0.01 per call) netif_set_addr/16 (185391 (estimated locally),0.84 per call) memset/33 (185391 (estimated locally),0.84 per call) 
   Indirect call(185391 (estimated locally),0.84 per call)  of param:5 (vptr maybe changed)
netif_add_noaddr/7 (netif_add_noaddr) @071a61c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: netif_add/8 (1073741824 (estimated locally),1.00 per call) 
netif_input/6 (netif_input) @071a1e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: ip4_input/31 (87689 (estimated locally),0.25 per call) ethernet_input/30 (87689 (estimated locally),0.25 per call) 
netif_init/5 (netif_init) @071a1540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
netif_client_id/4 (netif_client_id) @071a3360
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: netif_alloc_client_data_id/24 (read)netif_alloc_client_data_id/24 (write)
  Availability: available
  Varpool flags:
netif_num/3 (netif_num) @071a32d0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: netif_add/8 (read)netif_add/8 (write)netif_add/8 (write)
  Availability: available
  Varpool flags:
netif_default/2 (netif_default) @071a31f8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: netif_set_default/18 (write)netif_remove/17 (read)netif_remove/17 (write)
  Availability: available
  Varpool flags:
netif_list/1 (netif_list) @071a31b0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: netif_get_by_index/28 (read)netif_add/8 (write)netif_remove/17 (write)netif_add/8 (read)netif_remove/17 (read)netif_find/29 (read)
  Availability: available
  Varpool flags:

;; Function netif_null_output_ip4 (netif_null_output_ip4, funcdef_no=21, decl_uid=7644, cgraph_uid=22, symbol_order=25)

Modification phase of node netif_null_output_ip4/25
netif_null_output_ip4 (struct netif * netif, struct pbuf * p, const struct ip4_addr_t * ipaddr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return -12;

}



;; Function netif_issue_reports (netif_issue_reports, funcdef_no=16, decl_uid=7640, cgraph_uid=17, symbol_order=20)

Modification phase of node netif_issue_reports/20
Adjusting mask for param 1 to 0x2
Setting value range of param 1 [1, 3]
netif_issue_reports (struct netif * netif, u8_t report_type)
{
  unsigned char _1;
  long unsigned int _4;
  struct ip_addr_t * _5;
  unsigned char _13;
  unsigned char _14;
  unsigned char _15;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_8(D) == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 11> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_8(D)->flags;
  _13 = _1 & 5;
  if (_13 != 5)
    goto <bb 10>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 125270]:
  # DEBUG BEGIN_STMT
  _14 = report_type_10(D) & 1;
  if (_14 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 6> [local count: 62635]:
  _4 = MEM[(const struct ip4_addr_t *)netif_8(D) + 4B].addr;
  if (_4 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 7> [local count: 31317]:
  # DEBUG BEGIN_STMT
  _15 = _1 & 8;
  if (_15 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 10335]:
  # DEBUG BEGIN_STMT
  _5 = &netif_8(D)->ip_addr;
  etharp_request (netif_8(D), _5);

  <bb 9> [local count: 31317]:
  # DEBUG D#5 => report_type_10(D)
  netif_issue_reports.part.0 (netif_8(D));

  <bb 10> [local count: 250539]:
  return;

}



;; Function netif_do_set_ipaddr (netif_do_set_ipaddr, funcdef_no=6, decl_uid=7685, cgraph_uid=7, symbol_order=10)

Modification phase of node netif_do_set_ipaddr/10
Adjusting mask for param 2 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 2
netif_do_set_ipaddr (struct netif * netif, const struct ip4_addr_t * ipaddr, struct ip_addr_t * old_addr)
{
  int _2;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_5(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (old_addr_7(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 8> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  _2 = netif_do_set_ipaddr.part.0 (netif_8(D), ipaddr_5(D), old_addr_7(D));
  return _2;

}



;; Function netif_init (netif_init, funcdef_no=1, decl_uid=6898, cgraph_uid=2, symbol_order=5)

Modification phase of node netif_init/5
netif_init ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function netif_input (netif_input, funcdef_no=2, decl_uid=6942, cgraph_uid=3, symbol_order=6)

Modification phase of node netif_input/6
netif_input (struct pbuf * p, struct netif * inp)
{
  unsigned char _1;
  err_t _2;
  err_t _10;
  err_t _12;
  unsigned char _15;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_6(D) == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 10> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (inp_8(D) == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 11> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = inp_8(D)->flags;
  _15 = _1 & 24;
  if (_15 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 87689]:
  # DEBUG BEGIN_STMT
  _12 = ethernet_input (p_6(D), inp_8(D));
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 87689]:
  # DEBUG BEGIN_STMT
  _10 = ip4_input (p_6(D), inp_8(D));

  <bb 9> [local count: 175378]:
  # _2 = PHI <_12(7), _10(8)>
  return _2;

}



;; Function netif_set_ipaddr (netif_set_ipaddr, funcdef_no=7, decl_uid=6925, cgraph_uid=8, symbol_order=11)

Modification phase of node netif_set_ipaddr/11
netif_set_ipaddr (struct netif * netif, const struct ip4_addr_t * ipaddr)
{
  struct ip_addr_t old_addr;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_3(D) == 0B)
    goto <bb 3>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 3> [local count: 194239896]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  old_addr ={v} {CLOBBER};
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_4(D) == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 5> [local count: 263850578]:
  # DEBUG BEGIN_STMT
  # DEBUG ipaddr => &ip_addr_any

  <bb 6> [local count: 879501928]:
  # ipaddr_1 = PHI <ipaddr_4(D)(4), &ip_addr_any(5)>
  # DEBUG ipaddr => ipaddr_1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_do_set_ipaddr (netif_3(D), ipaddr_1, &old_addr);
  # DEBUG BEGIN_STMT
  old_addr ={v} {CLOBBER};

  <bb 7> [local count: 1073741824]:
  return;

}



;; Function netif_set_netmask (netif_set_netmask, funcdef_no=9, decl_uid=6928, cgraph_uid=10, symbol_order=13)

Modification phase of node netif_set_netmask/13
netif_set_netmask (struct netif * netif, const struct ip4_addr_t * netmask)
{
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG old_nm => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_3(D) == 0B)
    goto <bb 7>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netmask_4(D) == 0B)
    goto <bb 4>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 4> [local count: 263850578]:
  # DEBUG BEGIN_STMT
  # DEBUG netmask => &ip_addr_any

  <bb 5> [local count: 879501928]:
  # netmask_1 = PHI <netmask_4(D)(3), &ip_addr_any(4)>
  # DEBUG netmask => netmask_1
  # DEBUG BEGIN_STMT
  _6 = MEM[(long unsigned int *)netmask_1];
  # DEBUG D#1 => netmask_1
  # DEBUG D#2 => 0B
  # DEBUG netif => netif_3(D)
  # DEBUG INLINE_ENTRY netif_do_set_netmask
  # DEBUG netmask => D#1
  # DEBUG old_nm => D#2
  # DEBUG BEGIN_STMT
  _7 = MEM[(const struct ip4_addr_t *)netif_3(D) + 8B].addr;
  if (_6 != _7)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 439750964]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_3(D)->netmask.addr = _6;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  # DEBUG netif => NULL
  # DEBUG BEGIN_STMT
  return;

}



;; Function netif_set_gw (netif_set_gw, funcdef_no=11, decl_uid=6931, cgraph_uid=12, symbol_order=15)

Modification phase of node netif_set_gw/15
netif_set_gw (struct netif * netif, const struct ip4_addr_t * gw)
{
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG old_gw => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_3(D) == 0B)
    goto <bb 7>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (gw_4(D) == 0B)
    goto <bb 4>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 4> [local count: 263850578]:
  # DEBUG BEGIN_STMT
  # DEBUG gw => &ip_addr_any

  <bb 5> [local count: 879501928]:
  # gw_1 = PHI <gw_4(D)(3), &ip_addr_any(4)>
  # DEBUG gw => gw_1
  # DEBUG BEGIN_STMT
  _6 = MEM[(long unsigned int *)gw_1];
  # DEBUG D#3 => gw_1
  # DEBUG D#4 => 0B
  # DEBUG netif => netif_3(D)
  # DEBUG INLINE_ENTRY netif_do_set_gw
  # DEBUG gw => D#3
  # DEBUG old_gw => D#4
  # DEBUG BEGIN_STMT
  _7 = MEM[(const struct ip4_addr_t *)netif_3(D) + 12B].addr;
  if (_6 != _7)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 439750964]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_3(D)->gw.addr = _6;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  # DEBUG netif => NULL
  # DEBUG BEGIN_STMT
  return;

}



;; Function netif_set_addr (netif_set_addr, funcdef_no=12, decl_uid=6916, cgraph_uid=13, symbol_order=16)

Modification phase of node netif_set_addr/16
netif_set_addr (struct netif * netif, const struct ip4_addr_t * ipaddr, const struct ip4_addr_t * netmask, const struct ip4_addr_t * gw)
{
  struct ip_addr_t old_addr;
  long unsigned int _1;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  int iftmp.5_18;
  long unsigned int _19;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG old_nm => 0B
  # DEBUG BEGIN_STMT
  # DEBUG old_gw => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_7(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG ipaddr => &ip_addr_any

  <bb 4> [local count: 1073741824]:
  # ipaddr_2 = PHI <ipaddr_7(D)(2), &ip_addr_any(3)>
  # DEBUG ipaddr => ipaddr_2
  # DEBUG BEGIN_STMT
  if (netmask_8(D) == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 5> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG netmask => &ip_addr_any

  <bb 6> [local count: 1073741824]:
  # netmask_3 = PHI <netmask_8(D)(4), &ip_addr_any(5)>
  # DEBUG netmask => netmask_3
  # DEBUG BEGIN_STMT
  if (gw_9(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 7> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG gw => &ip_addr_any

  <bb 8> [local count: 1073741824]:
  # gw_4 = PHI <gw_9(D)(6), &ip_addr_any(7)>
  # DEBUG gw => gw_4
  # DEBUG BEGIN_STMT
  if (ipaddr_2 == 0B)
    goto <bb 10>; [17.43%]
  else
    goto <bb 9>; [82.57%]

  <bb 9> [local count: 886588625]:
  _1 = ipaddr_2->addr;
  if (_1 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 630447513]:
  # DEBUG remove => NULL
  # DEBUG BEGIN_STMT
  netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);

  <bb 11> [local count: 1073741824]:
  # iftmp.5_18 = PHI <0(9), 1(10)>
  # DEBUG remove => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = MEM[(long unsigned int *)netmask_3];
  # DEBUG D#1 => netmask_3
  # DEBUG D#2 => 0B
  # DEBUG netif => netif_11(D)
  # DEBUG INLINE_ENTRY netif_do_set_netmask
  # DEBUG netmask => D#1
  # DEBUG old_nm => D#2
  # DEBUG BEGIN_STMT
  _19 = MEM[(const struct ip4_addr_t *)netif_11(D) + 8B].addr;
  if (_15 != _19)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_11(D)->netmask.addr = _15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  # DEBUG netif => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = MEM[(long unsigned int *)gw_4];
  # DEBUG D#3 => gw_4
  # DEBUG D#4 => 0B
  # DEBUG netif => netif_11(D)
  # DEBUG INLINE_ENTRY netif_do_set_gw
  # DEBUG gw => D#3
  # DEBUG old_gw => D#4
  # DEBUG BEGIN_STMT
  _17 = MEM[(const struct ip4_addr_t *)netif_11(D) + 12B].addr;
  if (_16 != _17)
    goto <bb 14>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 14> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_11(D)->gw.addr = _16;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  # DEBUG netif => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (iftmp.5_18 == 0)
    goto <bb 16>; [33.00%]
  else
    goto <bb 17>; [67.00%]

  <bb 16> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  netif_do_set_ipaddr (netif_11(D), ipaddr_2, &old_addr);

  <bb 17> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  old_addr ={v} {CLOBBER};
  return;

}



;; Function netif_add (netif_add, funcdef_no=4, decl_uid=6911, cgraph_uid=5, symbol_order=8)

Modification phase of node netif_add/8
netif_add (struct netif * netif, const struct ip4_addr_t * ipaddr, const struct ip4_addr_t * netmask, const struct ip4_addr_t * gw, void * state, err_t (*netif_init_fn) (struct netif *) init, err_t (*netif_input_fn) (struct pbuf *, struct netif *) input)
{
  int num_netifs;
  struct netif * netif2;
  void *[2] * _1;
  unsigned char netif_num.0_2;
  signed char _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char _11;
  unsigned char _13;
  struct netif * _19;
  unsigned char _30;

  <bb 2> [local count: 220326]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_27(D) == 0B)
    goto <bb 28>; [8.27%]
  else
    goto <bb 3>; [91.73%]

  <bb 3> [local count: 202105]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (init_28(D) == 0B)
    goto <bb 28>; [8.27%]
  else
    goto <bb 4>; [91.73%]

  <bb 4> [local count: 185391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_29(D) == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 5> [local count: 55617]:
  # DEBUG BEGIN_STMT
  # DEBUG ipaddr => &ip_addr_any

  <bb 6> [local count: 185391]:
  # ipaddr_14 = PHI <ipaddr_29(D)(4), &ip_addr_any(5)>
  # DEBUG ipaddr => ipaddr_14
  # DEBUG BEGIN_STMT
  if (netmask_31(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 7> [local count: 55617]:
  # DEBUG BEGIN_STMT
  # DEBUG netmask => &ip_addr_any

  <bb 8> [local count: 185391]:
  # netmask_15 = PHI <netmask_31(D)(6), &ip_addr_any(7)>
  # DEBUG netmask => netmask_15
  # DEBUG BEGIN_STMT
  if (gw_33(D) == 0B)
    goto <bb 9>; [30.00%]
  else
    goto <bb 10>; [70.00%]

  <bb 9> [local count: 55617]:
  # DEBUG BEGIN_STMT
  # DEBUG gw => &ip_addr_any

  <bb 10> [local count: 185391]:
  # gw_16 = PHI <gw_33(D)(8), &ip_addr_any(9)>
  # DEBUG gw => gw_16
  # DEBUG BEGIN_STMT
  netif_27(D)->ip_addr.addr = 0;
  # DEBUG BEGIN_STMT
  netif_27(D)->netmask.addr = 0;
  # DEBUG BEGIN_STMT
  netif_27(D)->gw.addr = 0;
  # DEBUG BEGIN_STMT
  netif_27(D)->output = netif_null_output_ip4;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_27(D)->mtu = 0;
  # DEBUG BEGIN_STMT
  netif_27(D)->flags = 0;
  # DEBUG BEGIN_STMT
  _1 = &netif_27(D)->client_data;
  memset (_1, 0, 8);
  # DEBUG BEGIN_STMT
  netif_27(D)->igmp_mac_filter = 0B;
  # DEBUG BEGIN_STMT
  netif_27(D)->state = state_43(D);
  # DEBUG BEGIN_STMT
  netif_num.0_2 = netif_num;
  netif_27(D)->num = netif_num.0_2;
  # DEBUG BEGIN_STMT
  netif_27(D)->input = input_46(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_set_addr (netif_27(D), ipaddr_14, netmask_15, gw_16);
  # DEBUG BEGIN_STMT
  _3 = init_28(D) (netif_27(D));
  if (_3 != 0)
    goto <bb 28>; [17.38%]
  else
    goto <bb 31>; [82.62%]

  <bb 31> [local count: 153170]:

  <bb 11> [local count: 359133]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = netif_27(D)->num;
  if (_4 == 255)
    goto <bb 12>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 12> [local count: 122105]:
  # DEBUG BEGIN_STMT
  netif_27(D)->num = 0;

  <bb 13> [local count: 359133]:
  # DEBUG BEGIN_STMT
  # DEBUG num_netifs => 0
  # DEBUG BEGIN_STMT
  netif2_51 = netif_list;
  # DEBUG netif2 => netif2_51
  goto <bb 21>; [100.00%]

  <bb 14> [local count: 3904509]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif2_17 == netif_27(D))
    goto <bb 29>; [2.75%]
  else
    goto <bb 16>; [97.25%]

  <bb 29> [local count: 107374]:

  <bb 15> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 32> [local count: 1073741824]:
  goto <bb 15>; [100.00%]

  <bb 16> [local count: 3797135]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  num_netifs_52 = num_netifs_18 + 1;
  # DEBUG num_netifs => num_netifs_52
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (num_netifs_52 == 256)
    goto <bb 30>; [1.00%]
  else
    goto <bb 18>; [99.00%]

  <bb 30> [local count: 37971]:

  <bb 17> [local count: 379714154]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 379714154]:
  goto <bb 17>; [100.00%]

  <bb 18> [local count: 3759164]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = netif2_17->num;
  _6 = netif_27(D)->num;
  if (_5 == _6)
    goto <bb 19>; [2.75%]
  else
    goto <bb 20>; [97.25%]

  <bb 19> [local count: 103377]:
  # _7 = PHI <_6(18)>
  # netif2_10 = PHI <netif2_17(18)>
  # DEBUG BEGIN_STMT
  _8 = _7 + 1;
  netif_27(D)->num = _8;
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 20> [local count: 3655787]:
  # DEBUG BEGIN_STMT
  netif2_53 = netif2_17->next;
  # DEBUG netif2 => netif2_53

  <bb 21> [local count: 4014919]:
  # netif2_17 = PHI <netif2_51(13), netif2_53(20)>
  # num_netifs_18 = PHI <0(13), num_netifs_52(20)>
  # DEBUG num_netifs => num_netifs_18
  # DEBUG netif2 => netif2_17
  # DEBUG BEGIN_STMT
  if (netif2_17 != 0B)
    goto <bb 14>; [97.25%]
  else
    goto <bb 22>; [2.75%]

  <bb 22> [local count: 213787]:
  # netif2_12 = PHI <netif2_10(19), netif2_17(21)>
  # DEBUG BEGIN_STMT
  if (netif2_12 != 0B)
    goto <bb 34>; [96.34%]
  else
    goto <bb 23>; [3.66%]

  <bb 34> [local count: 205962]:
  goto <bb 11>; [100.00%]

  <bb 23> [local count: 7825]:
  # netif2_32 = PHI <netif2_51(22)>
  # DEBUG BEGIN_STMT
  _9 = netif_27(D)->num;
  if (_9 == 254)
    goto <bb 24>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 24> [local count: 2660]:
  # DEBUG BEGIN_STMT
  netif_num = 0;
  goto <bb 26>; [100.00%]

  <bb 25> [local count: 5164]:
  # DEBUG BEGIN_STMT
  _11 = _9 + 1;
  netif_num = _11;

  <bb 26> [local count: 7825]:
  # DEBUG BEGIN_STMT
  netif_27(D)->next = netif2_32;
  # DEBUG BEGIN_STMT
  netif_list = netif_27(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = netif_27(D)->flags;
  _30 = _13 & 32;
  if (_30 != 0)
    goto <bb 27>; [33.00%]
  else
    goto <bb 28>; [67.00%]

  <bb 27> [local count: 2582]:
  # DEBUG BEGIN_STMT
  igmp_start (netif_27(D));

  <bb 28> [local count: 74981]:
  # _19 = PHI <0B(2), 0B(3), 0B(10), netif_27(D)(27), netif_27(D)(26)>
  return _19;

}



;; Function netif_add_noaddr (netif_add_noaddr, funcdef_no=3, decl_uid=6903, cgraph_uid=4, symbol_order=7)

Modification phase of node netif_add_noaddr/7
netif_add_noaddr (struct netif * netif, void * state, err_t (*netif_init_fn) (struct netif *) init, err_t (*netif_input_fn) (struct pbuf *, struct netif *) input)
{
  struct netif * _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _7 = netif_add (netif_2(D), 0B, 0B, 0B, state_3(D), init_4(D), input_5(D));
  return _7;

}



;; Function netif_set_default (netif_set_default, funcdef_no=14, decl_uid=6922, cgraph_uid=15, symbol_order=18)

Modification phase of node netif_set_default/18
netif_set_default (struct netif * netif)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_default = netif_2(D);
  # DEBUG BEGIN_STMT
  return;

}



;; Function netif_set_up (netif_set_up, funcdef_no=15, decl_uid=6933, cgraph_uid=16, symbol_order=19)

Modification phase of node netif_set_up/19
netif_set_up (struct netif * netif)
{
  unsigned char _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_6(D) == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_6(D)->flags;
  _12 = _1 & 1;
  if (_12 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 290235636]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = _1 | 1;
  netif_6(D)->flags = _2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = sys_now ();
  _4 = _3 / 10;
  netif_6(D)->ts = _4;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_issue_reports (netif_6(D), 3);

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function netif_set_down (netif_set_down, funcdef_no=17, decl_uid=6935, cgraph_uid=18, symbol_order=21)

Modification phase of node netif_set_down/21
netif_set_down (struct netif * netif)
{
  unsigned char _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _5;
  unsigned char _13;
  unsigned char _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_7(D) == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_7(D)->flags;
  _13 = _1 & 1;
  if (_13 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 4> [local count: 290235636]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = _1 & 254;
  netif_7(D)->flags = _2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = sys_now ();
  _4 = _3 / 10;
  netif_7(D)->ts = _4;
  # DEBUG BEGIN_STMT
  _5 = netif_7(D)->flags;
  _14 = _5 & 8;
  if (_14 != 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 95777760]:
  # DEBUG BEGIN_STMT
  etharp_cleanup_netif (netif_7(D));

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function netif_remove (netif_remove, funcdef_no=13, decl_uid=6918, cgraph_uid=14, symbol_order=17)

Modification phase of node netif_remove/17
netif_remove (struct netif * netif)
{
  struct netif * tmp_netif;
  long unsigned int _1;
  struct ip_addr_t * _2;
  unsigned char _3;
  unsigned char _4;
  _Bool _5;
  struct netif * netif_default.6_6;
  struct netif * netif_list.7_7;
  struct netif * _8;
  struct netif * _9;
  struct netif * _10;
  unsigned char _23;

  <bb 2> [local count: 200330558]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_18(D) == 0B)
    goto <bb 17>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 164090760]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(const struct ip4_addr_t *)netif_18(D) + 4B].addr;
  if (_1 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 54149951]:
  # DEBUG BEGIN_STMT
  _2 = &netif_18(D)->ip_addr;
  netif_do_ip_addr_changed (_2, 0B);

  <bb 5> [local count: 164090760]:
  # DEBUG BEGIN_STMT
  _3 = netif_18(D)->flags;
  _23 = _3 & 32;
  if (_23 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 54149951]:
  # DEBUG BEGIN_STMT
  igmp_stop (netif_18(D));

  <bb 7> [local count: 164090760]:
  # DEBUG BEGIN_STMT
  _4 = netif_18(D)->flags;
  _5 = (_Bool) _4;
  if (_5 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 54149951]:
  # DEBUG BEGIN_STMT
  netif_set_down (netif_18(D));

  <bb 9> [local count: 164090760]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_default.6_6 = netif_default;
  if (netif_default.6_6 == netif_18(D))
    goto <bb 10>; [30.00%]
  else
    goto <bb 11>; [70.00%]

  <bb 10> [local count: 49227228]:
  # DEBUG BEGIN_STMT
  # DEBUG netif => 0B
  # DEBUG INLINE_ENTRY netif_set_default
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_default = 0B;
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 164090760]:
  # DEBUG netif => NULL
  # DEBUG BEGIN_STMT
  netif_list.7_7 = netif_list;
  if (netif_list.7_7 == netif_18(D))
    goto <bb 12>; [30.00%]
  else
    goto <bb 18>; [70.00%]

  <bb 12> [local count: 49227228]:
  # DEBUG BEGIN_STMT
  _8 = netif_18(D)->next;
  netif_list = _8;
  goto <bb 17>; [100.00%]

  <bb 13> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _9 = tmp_netif_11->next;
  if (_9 == netif_18(D))
    goto <bb 14>; [5.50%]
  else
    goto <bb 19>; [94.50%]

  <bb 19> [local count: 958878294]:
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 55807731]:
  # tmp_netif_24 = PHI <tmp_netif_11(13)>
  # DEBUG BEGIN_STMT
  _10 = netif_18(D)->next;
  tmp_netif_24->next = _10;
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 18> [local count: 114863532]:

  <bb 15> [local count: 1073741824]:
  # tmp_netif_11 = PHI <netif_list.7_7(18), _9(19)>
  # DEBUG tmp_netif => tmp_netif_11
  # DEBUG BEGIN_STMT
  if (tmp_netif_11 != 0B)
    goto <bb 13>; [94.50%]
  else
    goto <bb 16>; [5.50%]

  <bb 16> [local count: 114863532]:
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 200330558]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function netif_set_link_up (netif_set_link_up, funcdef_no=18, decl_uid=6937, cgraph_uid=19, symbol_order=22)

Modification phase of node netif_set_link_up/22
netif_set_link_up (struct netif * netif)
{
  unsigned char _1;
  unsigned char _2;
  unsigned char _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_4(D) == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_4(D)->flags;
  _8 = _1 & 4;
  if (_8 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 290235636]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = _1 | 4;
  netif_4(D)->flags = _2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_issue_reports (netif_4(D), 3);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function netif_set_link_down (netif_set_link_down, funcdef_no=19, decl_uid=6939, cgraph_uid=20, symbol_order=23)

Modification phase of node netif_set_link_down/23
netif_set_link_down (struct netif * netif)
{
  unsigned char _1;
  unsigned char _2;
  unsigned char _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_4(D) == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_4(D)->flags;
  _7 = _1 & 4;
  if (_7 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 439750964]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = _1 & 251;
  netif_4(D)->flags = _2;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function netif_alloc_client_data_id (netif_alloc_client_data_id, funcdef_no=20, decl_uid=6873, cgraph_uid=21, symbol_order=24)

Modification phase of node netif_alloc_client_data_id/24
netif_alloc_client_data_id ()
{
  u8_t result;
  unsigned char _1;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  result_4 = netif_client_id;
  # DEBUG result => result_4
  # DEBUG BEGIN_STMT
  _1 = result_4 + 1;
  netif_client_id = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (result_4 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 1;

}



;; Function netif_get_by_index (netif_get_by_index, funcdef_no=24, decl_uid=6949, cgraph_uid=25, symbol_order=28)

Modification phase of node netif_get_by_index/28
netif_get_by_index (u8_t idx)
{
  struct netif * netif;
  unsigned char _1;
  unsigned char _2;
  struct netif * _4;

  <bb 2> [local count: 161779623]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (idx_5(D) != 0)
    goto <bb 3>; [71.00%]
  else
    goto <bb 8>; [29.00%]

  <bb 3> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  netif_7 = netif_list;
  # DEBUG netif => netif_7
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  _1 = netif_3->num;
  _2 = _1 + 1;
  if (_2 == idx_5(D))
    goto <bb 5>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 5> [local count: 55807731]:
  # netif_9 = PHI <netif_3(4)>
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  netif_8 = netif_3->next;
  # DEBUG netif => netif_8

  <bb 7> [local count: 1073741824]:
  # netif_3 = PHI <netif_7(3), netif_8(6)>
  # DEBUG netif => netif_3
  # DEBUG BEGIN_STMT
  if (netif_3 != 0B)
    goto <bb 4>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 161779622]:
  # _4 = PHI <netif_9(5), 0B(7), 0B(2)>
  return _4;

}



;; Function netif_index_to_name (netif_index_to_name, funcdef_no=23, decl_uid=6947, cgraph_uid=24, symbol_order=27)

Modification phase of node netif_index_to_name/27
netif_index_to_name (u8_t idx, char * name)
{
  struct netif * netif;
  char _1;
  char _2;
  char * _3;
  int _4;
  int _5;
  char * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  netif_10 = netif_get_by_index (idx_9(D));
  # DEBUG netif => netif_10
  # DEBUG BEGIN_STMT
  if (netif_10 != 0B)
    goto <bb 3>; [59.18%]
  else
    goto <bb 4>; [40.82%]

  <bb 3> [local count: 635440412]:
  # DEBUG BEGIN_STMT
  _1 = netif_10->name[0];
  *name_11(D) = _1;
  # DEBUG BEGIN_STMT
  _2 = netif_10->name[1];
  MEM[(char *)name_11(D) + 1B] = _2;
  # DEBUG BEGIN_STMT
  _3 = name_11(D) + 2;
  _4 = (int) idx_9(D);
  _5 = _4 + -1;
  lwip_itoa (_3, 4, _5);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # _6 = PHI <name_11(D)(3), 0B(2)>
  return _6;

}



;; Function netif_find (netif_find, funcdef_no=25, decl_uid=6920, cgraph_uid=26, symbol_order=29)

Modification phase of node netif_find/29
netif_find (const char * name)
{
  u8_t num;
  struct netif * netif;
  const char * _1;
  int _2;
  char _3;
  unsigned char _4;
  char _5;
  char _6;
  char _7;
  char _8;
  struct netif * _10;

  <bb 2> [local count: 90638327]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (name_12(D) == 0B)
    goto <bb 12>; [15.47%]
  else
    goto <bb 3>; [84.53%]

  <bb 3> [local count: 76616578]:
  # DEBUG BEGIN_STMT
  _1 = name_12(D) + 2;
  _2 = atoi (_1);
  num_15 = (u8_t) _2;
  # DEBUG num => num_15
  # DEBUG BEGIN_STMT
  if (num_15 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 38308289]:
  _3 = MEM[(const char *)name_12(D) + 2B];
  if (_3 != 48)
    goto <bb 12>; [29.00%]
  else
    goto <bb 5>; [71.00%]

  <bb 5> [local count: 65507174]:
  # DEBUG BEGIN_STMT
  netif_16 = netif_list;
  # DEBUG netif => netif_16
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _4 = netif_9->num;
  if (_4 == num_15)
    goto <bb 7>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 7> [local count: 344993248]:
  _5 = *name_12(D);
  _6 = netif_9->name[0];
  if (_5 == _6)
    goto <bb 8>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 8> [local count: 117297704]:
  _7 = MEM[(const char *)name_12(D) + 1B];
  _8 = netif_9->name[1];
  if (_7 == _8)
    goto <bb 9>; [5.50%]
  else
    goto <bb 10>; [94.50%]

  <bb 9> [local count: 6451374]:
  # netif_17 = PHI <netif_9(8)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 10> [local count: 1008234651]:
  # DEBUG BEGIN_STMT
  netif_18 = netif_9->next;
  # DEBUG netif => netif_18

  <bb 11> [local count: 1073741824]:
  # netif_9 = PHI <netif_16(5), netif_18(10)>
  # DEBUG netif => netif_9
  # DEBUG BEGIN_STMT
  if (netif_9 != 0B)
    goto <bb 6>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 12> [local count: 90638327]:
  # _10 = PHI <0B(2), 0B(4), netif_17(9), 0B(11)>
  return _10;

}



;; Function netif_name_to_index (netif_name_to_index, funcdef_no=22, decl_uid=6944, cgraph_uid=23, symbol_order=26)

Modification phase of node netif_name_to_index/26
netif_name_to_index (const char * name)
{
  struct netif * netif;
  unsigned char _1;
  u8_t _2;
  u8_t _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  netif_6 = netif_find (name_4(D));
  # DEBUG netif => netif_6
  # DEBUG BEGIN_STMT
  if (netif_6 != 0B)
    goto <bb 3>; [54.59%]
  else
    goto <bb 4>; [45.41%]

  <bb 3> [local count: 586155663]:
  # DEBUG BEGIN_STMT
  _1 = netif_6->num;
  _7 = _1 + 1;

  <bb 4> [local count: 1073741824]:
  # _2 = PHI <_7(3), 0(2)>
  return _2;

}


