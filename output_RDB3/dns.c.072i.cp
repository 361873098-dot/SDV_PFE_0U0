
IPA constant propagation start:
Determining dynamic type for call: _3 = dns_lookup (hostname_8(D), addr_7(D));
  Starting walk at: _3 = dns_lookup (hostname_8(D), addr_7(D));
  instance pointer: hostname_8(D)  Outer instance pointer: hostname_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = ip4addr_aton (hostname_8(D), addr_7(D));
Determining dynamic type for call: _3 = dns_lookup (hostname_8(D), addr_7(D));
  Starting walk at: _3 = dns_lookup (hostname_8(D), addr_7(D));
  instance pointer: addr_7(D)  Outer instance pointer: addr_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = ip4addr_aton (hostname_8(D), addr_7(D));
Determining dynamic type for call: _16 = dns_enqueue (hostname_8(D), hostnamelen_10, found_13(D), callback_arg_14(D));
  Starting walk at: _16 = dns_enqueue (hostname_8(D), hostnamelen_10, found_13(D), callback_arg_14(D));
  instance pointer: hostname_8(D)  Outer instance pointer: hostname_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = dns_lookup (hostname_8(D), addr_7(D));
  Function call may change dynamic type:_2 = ip4addr_aton (hostname_8(D), addr_7(D));
Determining dynamic type for call: _16 = dns_enqueue (hostname_8(D), hostnamelen_10, found_13(D), callback_arg_14(D));
  Starting walk at: _16 = dns_enqueue (hostname_8(D), hostnamelen_10, found_13(D), callback_arg_14(D));
  instance pointer: found_13(D)  Outer instance pointer: found_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = dns_lookup (hostname_8(D), addr_7(D));
  Function call may change dynamic type:_2 = ip4addr_aton (hostname_8(D), addr_7(D));
Determining dynamic type for call: _16 = dns_enqueue (hostname_8(D), hostnamelen_10, found_13(D), callback_arg_14(D));
  Starting walk at: _16 = dns_enqueue (hostname_8(D), hostnamelen_10, found_13(D), callback_arg_14(D));
  instance pointer: callback_arg_14(D)  Outer instance pointer: callback_arg_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = dns_lookup (hostname_8(D), addr_7(D));
  Function call may change dynamic type:_2 = ip4addr_aton (hostname_8(D), addr_7(D));
Determining dynamic type for call: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  Starting walk at: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  instance pointer: hostname_2(D)  Outer instance pointer: hostname_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  Starting walk at: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  instance pointer: addr_3(D)  Outer instance pointer: addr_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  Starting walk at: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  instance pointer: found_4(D)  Outer instance pointer: found_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  Starting walk at: _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  instance pointer: callback_arg_5(D)  Outer instance pointer: callback_arg_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_idx_60 = dns_compare_name (_15, p_48(D), 12);
  Starting walk at: res_idx_60 = dns_compare_name (_15, p_48(D), 12);
  instance pointer: _15  Outer instance pointer: &MEM[(struct dns_table_entry *)&dns_table][_26].name offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:nanswers_57 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_55 = lwip_htons (_7);
  Function call may change dynamic type:txid_51 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_48(D), &hdr, 12, 0);
Determining dynamic type for call: res_idx_60 = dns_compare_name (_15, p_48(D), 12);
  Starting walk at: res_idx_60 = dns_compare_name (_15, p_48(D), 12);
  instance pointer: p_48(D)  Outer instance pointer: p_48(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:nanswers_57 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_55 = lwip_htons (_7);
  Function call may change dynamic type:txid_51 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_48(D), &hdr, 12, 0);
Determining dynamic type for call: res_idx_64 = dns_skip_name (p_48(D), res_idx_41);
  Starting walk at: res_idx_64 = dns_skip_name (p_48(D), res_idx_41);
  instance pointer: p_48(D)  Outer instance pointer: p_48(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_36 = lwip_htons (_35);
  Function call may change dynamic type:_32 = lwip_htons (_31);
  Function call may change dynamic type:_21 = pbuf_copy_partial (p_48(D), &ans, 10, res_idx_64);
  Function call may change dynamic type:res_idx_64 = dns_skip_name (p_48(D), res_idx_41);
  Function call may change dynamic type:_16 = pbuf_copy_partial (p_48(D), &qry, 4, res_idx_60);
  Function call may change dynamic type:res_idx_60 = dns_compare_name (_15, p_48(D), 12);
  Function call may change dynamic type:nanswers_57 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_55 = lwip_htons (_7);
  Function call may change dynamic type:txid_51 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_48(D), &hdr, 12, 0);
Determining dynamic type for call: _20 = dns_backupserver_available (entry_39);
  Starting walk at: _20 = dns_backupserver_available (entry_39);
  instance pointer: entry_39  Outer instance pointer: &dns_table[_4] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_16 = pbuf_copy_partial (p_48(D), &qry, 4, res_idx_60);
  Function call may change dynamic type:res_idx_60 = dns_compare_name (_15, p_48(D), 12);
  Function call may change dynamic type:nanswers_57 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_55 = lwip_htons (_7);
  Function call may change dynamic type:txid_51 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_48(D), &hdr, 12, 0);
Determining dynamic type for call: dns_call_found (i_38, 0B);
  Starting walk at: dns_call_found (i_38, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_48(D));
  Function call may change dynamic type:_16 = pbuf_copy_partial (p_48(D), &qry, 4, res_idx_60);
  Function call may change dynamic type:res_idx_60 = dns_compare_name (_15, p_48(D), 12);
  Function call may change dynamic type:nanswers_57 = lwip_htons (_8);
  Function call may change dynamic type:nquestions_55 = lwip_htons (_7);
  Function call may change dynamic type:txid_51 = lwip_htons (_3);
  Function call may change dynamic type:_2 = pbuf_copy_partial (p_48(D), &hdr, 12, 0);
  Function call may change dynamic type:_36 = lwip_htons (_35);
  Function call may change dynamic type:_32 = lwip_htons (_31);
  Function call may change dynamic type:_21 = pbuf_copy_partial (p_48(D), &ans, 10, res_idx_64);
  Function call may change dynamic type:res_idx_64 = dns_skip_name (p_48(D), res_idx_41);
Determining dynamic type for call: dns_call_found (idx_7(D), _2);
  Starting walk at: dns_call_found (idx_7(D), _2);
  instance pointer: _2  Outer instance pointer: &MEM[(struct dns_table_entry *)&dns_table][_1].ipaddr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = dns_backupserver_available (entry_19);
  Starting walk at: _8 = dns_backupserver_available (entry_19);
  instance pointer: entry_19  Outer instance pointer: &dns_table[_1] offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: dns_call_found (i_18(D), 0B);
  Starting walk at: dns_call_found (i_18(D), 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 (_5, addr_32(D), _6);
  Starting walk at: _2 (_5, addr_32(D), _6);
  instance pointer: _5  Outer instance pointer: &dns_table[_4].name offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 (_5, addr_32(D), _6);
Determining dynamic type for call: _2 (_5, addr_32(D), _6);
  Starting walk at: _2 (_5, addr_32(D), _6);
  instance pointer: addr_32(D)  Outer instance pointer: addr_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 (_5, addr_32(D), _6);
Determining dynamic type for call: _2 (_5, addr_32(D), _6);
  Starting walk at: _2 (_5, addr_32(D), _6);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 (_5, addr_32(D), _6);
Determining dynamic type for call: dns_call_found (idx_34(D), 0B);
  Starting walk at: dns_call_found (idx_34(D), 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  dns_backupserver_available.part.0/50:
  Jump functions of caller  pbuf_try_get_at/48:
  Jump functions of caller  lwip_htonl/47:
  Jump functions of caller  pbuf_copy_partial/46:
  Jump functions of caller  udp_recv/45:
  Jump functions of caller  udp_bind/44:
  Jump functions of caller  udp_new_ip_type/43:
  Jump functions of caller  memcpy/42:
  Jump functions of caller  lwip_strnicmp/41:
  Jump functions of caller  ip4addr_aton/40:
  Jump functions of caller  udp_sendto/39:
  Jump functions of caller  pbuf_take_at/38:
  Jump functions of caller  pbuf_put_at/37:
  Jump functions of caller  pbuf_free/36:
  Jump functions of caller  pbuf_take/35:
  Jump functions of caller  lwip_htons/34:
  Jump functions of caller  memset/33:
  Jump functions of caller  pbuf_alloc/32:
  Jump functions of caller  strlen/31:
  Jump functions of caller  udp_remove/30:
  Jump functions of caller  rand/29:
  Jump functions of caller  dns_gethostbyname_addrtype/27:
    callsite  dns_gethostbyname_addrtype/27 -> dns_enqueue/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7fffffff
         VR  [0, 2147483645]
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  dns_gethostbyname_addrtype/27 -> dns_lookup/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  dns_gethostbyname/26:
    callsite  dns_gethostbyname/26 -> dns_gethostbyname_addrtype/27 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  dns_enqueue/25:
    callsite  dns_enqueue/25 -> dns_check_entry/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  dns_enqueue/25 -> dns_alloc_pcb/17 : 
  Jump functions of caller  dns_recv/24:
    callsite  dns_recv/24 -> dns_call_found/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
    callsite  dns_recv/24 -> dns_correct_response/23 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  dns_recv/24 -> dns_skip_name/14 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  dns_recv/24 -> dns_check_entry/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
    callsite  dns_recv/24 -> dns_backupserver_available/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  dns_recv/24 -> dns_compare_name/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 12
         value: 0xc, mask: 0x0
         Unknown VR
  Jump functions of caller  dns_correct_response/23:
    callsite  dns_correct_response/23 -> dns_call_found/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  dns_check_entries/22:
    callsite  dns_check_entries/22 -> dns_check_entry/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 4]
  Jump functions of caller  dns_check_entry/21:
    callsite  dns_check_entry/21 -> dns_send/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  dns_check_entry/21 -> dns_call_found/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
    callsite  dns_check_entry/21 -> dns_backupserver_available/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  dns_check_entry/21 -> dns_send/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  dns_check_entry/21 -> dns_create_txid/19 : 
  Jump functions of caller  dns_backupserver_available/20:
    callsite  dns_backupserver_available/20 -> dns_backupserver_available.part.0/50 : 
  Jump functions of caller  dns_create_txid/19:
  Jump functions of caller  dns_call_found/18:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 (_5, addr_32(D), _6);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  dns_alloc_pcb/17:
    callsite  dns_alloc_pcb/17 -> dns_alloc_random_port/16 : 
  Jump functions of caller  dns_alloc_random_port/16:
  Jump functions of caller  dns_send/15:
    callsite  dns_send/15 -> dns_call_found/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  dns_skip_name/14:
  Jump functions of caller  dns_compare_name/13:
  Jump functions of caller  dns_lookup/12:
  Jump functions of caller  dns_tmr/11:
    callsite  dns_tmr/11 -> dns_check_entries/22 : 
  Jump functions of caller  dns_getserver/10:
  Jump functions of caller  dns_setserver/9:
  Jump functions of caller  dns_init/8:

 Propagating constants:

Not considering dns_gethostbyname_addrtype for cloning; -fipa-cp-clone disabled.
Not considering dns_gethostbyname for cloning; -fipa-cp-clone disabled.
Not considering dns_recv for cloning; -fipa-cp-clone disabled.
Not considering dns_tmr for cloning; -fipa-cp-clone disabled.
Not considering dns_getserver for cloning; -fipa-cp-clone disabled.
Not considering dns_setserver for cloning; -fipa-cp-clone disabled.
Not considering dns_init for cloning; -fipa-cp-clone disabled.

overall_size: 720, max_new_size: 11001
 - context independent values, size: 35, time_benefit: 1.000000
 - context independent values, size: 153, time_benefit: 3.000000
 - context independent values, size: 57, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: dns_backupserver_available.part.0/50:
  Node: dns_gethostbyname_addrtype/27:
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
  Node: dns_gethostbyname/26:
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
  Node: dns_enqueue/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7fffffff
         size_t [0, 2147483645]
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
  Node: dns_recv/24:
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
  Node: dns_correct_response/23:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x3
         u8_t [0, 3]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_check_entries/22:
  Node: dns_check_entry/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_backupserver_available/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct dns_table_entry * ~[0B, 0B]
        AGGS VARIABLE
  Node: dns_create_txid/19:
  Node: dns_call_found/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0B [loc_time: 1, loc_size: 42, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_alloc_pcb/17:
  Node: dns_alloc_random_port/16:
  Node: dns_send/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: dns_skip_name/14:
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
  Node: dns_compare_name/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const char * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 12 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0xc, mask = 0x0
         u16_t [12, 12]
        AGGS VARIABLE
  Node: dns_lookup/12:
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
  Node: dns_tmr/11:
  Node: dns_getserver/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: dns_setserver/9:
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
  Node: dns_init/8:

IPA decision stage:

 - Creating a specialized node of dns_compare_name/13 for all known contexts.
    replacing param #2 start_offset with const 12
Propagated bits info for function dns_compare_name.constprop/51:
 param 2: value = 0xc, mask = 0x0
Propagated bits info for function dns_enqueue/25:
 param 1: value = 0x0, mask = 0x7fffffff
Propagated bits info for function dns_correct_response/23:
 param 0: value = 0x0, mask = 0x3
Propagated bits info for function dns_backupserver_available/20:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function dns_compare_name/13:
 param 2: value = 0xc, mask = 0x0

IPA constant propagation end

Reclaiming functions: dns_compare_name/13
Reclaiming variables:
Clearing address taken flags:
Symbol table:

dns_compare_name.constprop.0/51 (dns_compare_name.constprop) @0727d0e0
  Type: function definition analyzed
  Visibility:
  References: _ctype_/49 (addr)_ctype_/49 (addr)
  Referring: 
  Clone of dns_compare_name/13
  Availability: local
  Function flags: count:92050635 (estimated locally) local optimize_size
  Called by: dns_recv/24 (700549 (estimated locally),0.00 per call) 
  Calls: pbuf_try_get_at/48 (120409230 (estimated locally),1.31 per call) pbuf_try_get_at/48 (1044213925 (estimated locally),11.34 per call) pbuf_try_get_at/48 (29527900 (estimated locally),0.32 per call) 
dns_backupserver_available.part.0/50 (dns_backupserver_available.part.0) @06e33620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: dns_servers/6 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: dns_backupserver_available/20 (375809639 (estimated locally),0.35 per call) 
  Calls: 
_ctype_/49 (_ctype_) @0710ebd0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: dns_compare_name.constprop.0/51 (addr)dns_compare_name.constprop.0/51 (addr)
  Availability: not_available
  Varpool flags: read-only
pbuf_try_get_at/48 (pbuf_try_get_at) @071038c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_compare_name.constprop/51 (120409230 (estimated locally),1.31 per call) dns_compare_name.constprop/51 (1044213925 (estimated locally),11.34 per call) dns_compare_name.constprop/51 (29527900 (estimated locally),0.32 per call) dns_skip_name/14 (990385272 (estimated locally),8.08 per call) dns_skip_name/14 (1073741824 (estimated locally),8.76 per call) 
  Calls: 
lwip_htonl/47 (lwip_htonl) @07103540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_recv/24 (102 (estimated locally),0.00 per call) 
  Calls: 
pbuf_copy_partial/46 (pbuf_copy_partial) @07103460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_recv/24 (503 (estimated locally),0.00 per call) dns_recv/24 (150773 (estimated locally),0.00 per call) dns_recv/24 (455287 (estimated locally),0.00 per call) dns_recv/24 (524845004 (estimated locally),0.49 per call) 
  Calls: 
udp_recv/45 (udp_recv) @071030e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/16 (10734218 (estimated locally),0.76 per call) 
  Calls: 
udp_bind/44 (udp_bind) @07103000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/16 (118111601 (estimated locally),8.34 per call) 
  Calls: 
udp_new_ip_type/43 (udp_new_ip_type) @070eeb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/16 (14163606 (estimated locally),1.00 per call) 
  Calls: 
memcpy/42 (memcpy) @070eec40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_enqueue/25 (114504709 (estimated locally),0.51 per call) 
  Calls: 
lwip_strnicmp/41 (lwip_strnicmp) @070ee7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_enqueue/25 (173860276 (estimated locally),0.78 per call) dns_lookup/12 (173860276 (estimated locally),0.78 per call) 
  Calls: 
ip4addr_aton/40 (ip4addr_aton) @070ee620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_gethostbyname_addrtype/27 (1031024857 (estimated locally),0.96 per call) 
  Calls: 
udp_sendto/39 (udp_sendto) @070ee380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/15 (23511 (estimated locally),0.13 per call) 
  Calls: 
pbuf_take_at/38 (pbuf_take_at) @070ee2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/15 (23511 (estimated locally),0.13 per call) dns_send/15 (427466 (estimated locally),2.35 per call) 
  Calls: 
pbuf_put_at/37 (pbuf_put_at) @070ee1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/15 (23511 (estimated locally),0.13 per call) dns_send/15 (427466 (estimated locally),2.35 per call) 
  Calls: 
pbuf_free/36 (pbuf_free) @070ee0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_recv/24 (1073722794 (estimated locally),1.00 per call) dns_recv/24 (18927 (estimated locally),0.00 per call) dns_recv/24 (102 (estimated locally),0.00 per call) dns_send/15 (23511 (estimated locally),0.13 per call) dns_send/15 (24879 (estimated locally),0.14 per call) 
  Calls: 
pbuf_take/35 (pbuf_take) @070ee000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/15 (48390 (estimated locally),0.27 per call) 
  Calls: 
lwip_htons/34 (lwip_htons) @070b89a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_recv/24 (141413 (estimated locally),0.00 per call) dns_recv/24 (144299 (estimated locally),0.00 per call) dns_recv/24 (7392912 (estimated locally),0.01 per call) dns_recv/24 (7392912 (estimated locally),0.01 per call) dns_recv/24 (106228629 (estimated locally),0.10 per call) dns_send/15 (48390 (estimated locally),0.27 per call) 
  Calls: 
memset/33 (memset) @070b8ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/15 (48390 (estimated locally),0.27 per call) 
  Calls: 
pbuf_alloc/32 (pbuf_alloc) @070b8e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_send/15 (49246 (estimated locally),0.27 per call) 
  Calls: 
strlen/31 (strlen) @070b8d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_gethostbyname_addrtype/27 (1053033253 (estimated locally),0.98 per call) dns_send/15 (49246 (estimated locally),0.27 per call) 
  Calls: 
udp_remove/30 (udp_remove) @070b8a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/16 (2258058 (estimated locally),0.16 per call) dns_call_found/18 (70866960 (estimated locally),0.33 per call) 
  Calls: 
rand/29 (rand) @070b8700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: dns_alloc_random_port/16 (1073741824 (estimated locally),75.81 per call) dns_create_txid/19 (230811542 (estimated locally),1.07 per call) 
  Calls: 
ip_addr_any/28 (ip_addr_any) @070bb0d8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: dns_setserver/9 (read)dns_alloc_random_port/16 (addr)dns_getserver/10 (addr)
  Availability: not_available
  Varpool flags: read-only
dns_gethostbyname_addrtype/27 (dns_gethostbyname_addrtype) @070a6ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: dns_servers/6 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: dns_gethostbyname/26 (1073741824 (estimated locally),1.00 per call) 
  Calls: dns_enqueue/25 (325665174 (estimated locally),0.30 per call) dns_lookup/12 (503964950 (estimated locally),0.47 per call) ip4addr_aton/40 (1031024857 (estimated locally),0.96 per call) strlen/31 (1053033253 (estimated locally),0.98 per call) 
dns_gethostbyname/26 (dns_gethostbyname) @070a6c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: dns_gethostbyname_addrtype/27 (1073741824 (estimated locally),1.00 per call) 
dns_enqueue/25 (dns_enqueue) @070a69a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_table/4 (addr)dns_requests/5 (read)dns_requests/5 (write)dns_requests/5 (write)dns_requests/5 (write)dns_table/4 (addr)dns_table/4 (read)dns_seqno/3 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (addr)dns_requests/5 (read)dns_requests/5 (addr)dns_seqno/3 (read)dns_seqno/3 (read)dns_seqno/3 (write)
  Referring: 
  Availability: local
  Function flags: count:223213368 (estimated locally) body local optimize_size
  Called by: dns_gethostbyname_addrtype/27 (325665174 (estimated locally),0.30 per call) 
  Calls: dns_check_entry/21 (55969902 (estimated locally),0.25 per call) dns_alloc_pcb/17 (114504709 (estimated locally),0.51 per call) memcpy/42 (114504709 (estimated locally),0.51 per call) lwip_strnicmp/41 (173860276 (estimated locally),0.78 per call) 
dns_recv/24 (dns_recv) @070a6700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: dns_table/4 (addr)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_servers/6 (read)dns_table/4 (addr)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)
  Referring: dns_alloc_random_port/16 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/36 (1073722794 (estimated locally),1.00 per call) dns_call_found/18 (18927 (estimated locally),0.00 per call) pbuf_free/36 (18927 (estimated locally),0.00 per call) lwip_htons/34 (141413 (estimated locally),0.00 per call) lwip_htons/34 (144299 (estimated locally),0.00 per call) dns_correct_response/23 (102 (estimated locally),0.00 per call) lwip_htonl/47 (102 (estimated locally),0.00 per call) pbuf_free/36 (102 (estimated locally),0.00 per call) pbuf_copy_partial/46 (503 (estimated locally),0.00 per call) pbuf_copy_partial/46 (150773 (estimated locally),0.00 per call) dns_skip_name/14 (153850 (estimated locally),0.00 per call) dns_check_entry/21 (6198 (estimated locally),0.00 per call) dns_backupserver_available/20 (18781 (estimated locally),0.00 per call) pbuf_copy_partial/46 (455287 (estimated locally),0.00 per call) dns_compare_name.constprop/51 (700549 (estimated locally),0.00 per call) lwip_htons/34 (7392912 (estimated locally),0.01 per call) lwip_htons/34 (7392912 (estimated locally),0.01 per call) lwip_htons/34 (106228629 (estimated locally),0.10 per call) pbuf_copy_partial/46 (524845004 (estimated locally),0.49 per call) 
dns_correct_response/23 (dns_correct_response) @070a61c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (addr)dns_table/4 (read)dns_table/4 (read)dns_table/4 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: dns_recv/24 (102 (estimated locally),0.00 per call) 
  Calls: dns_call_found/18 (1073741824 (estimated locally),1.00 per call) 
dns_check_entries/22 (dns_check_entries) @0709bc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748364 (estimated locally) body local optimize_size
  Called by: dns_tmr/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: dns_check_entry/21 (858993459 (estimated locally),4.00 per call) 
dns_check_entry/21 (dns_check_entry) @0709b9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (addr)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (write)dns_table/4 (read)dns_table/4 (write)dns_table/4 (write)
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: dns_recv/24 (6198 (estimated locally),0.00 per call) dns_enqueue/25 (55969902 (estimated locally),0.25 per call) dns_check_entries/22 (858993459 (estimated locally),4.00 per call) 
  Calls: dns_send/15 (9533 (estimated locally),0.04 per call) dns_call_found/18 (1205 (estimated locally),0.01 per call) dns_backupserver_available/20 (3651 (estimated locally),0.02 per call) dns_send/15 (21475 (estimated locally),0.10 per call) dns_create_txid/19 (21475 (estimated locally),0.10 per call) 
dns_backupserver_available/20 (dns_backupserver_available) @0709b620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: dns_recv/24 (18781 (estimated locally),0.00 per call) dns_check_entry/21 (3651 (estimated locally),0.02 per call) 
  Calls: dns_backupserver_available.part.0/50 (375809639 (estimated locally),0.35 per call) 
dns_create_txid/19 (dns_create_txid) @0709b2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_table/4 (read)
  Referring: 
  Availability: local
  Function flags: count:214748364 (estimated locally) body local optimize_size
  Called by: dns_check_entry/21 (21475 (estimated locally),0.10 per call) 
  Calls: rand/29 (230811542 (estimated locally),1.07 per call) 
dns_call_found/18 (dns_call_found) @0709b000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_requests/5 (read)dns_requests/5 (read)dns_table/4 (addr)dns_requests/5 (read)dns_requests/5 (write)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_table/4 (write)dns_table/4 (read)dns_pcbs/1 (read)dns_table/4 (read)dns_pcbs/1 (write)dns_table/4 (write)
  Referring: 
  Availability: local
  Function flags: count:214748364 (estimated locally) body local optimize_size
  Called by: dns_recv/24 (18927 (estimated locally),0.00 per call) dns_check_entry/21 (1205 (estimated locally),0.01 per call) dns_send/15 (25369 (estimated locally),0.14 per call) dns_correct_response/23 (1073741824 (estimated locally),1.00 per call) 
  Calls: udp_remove/30 (70866960 (estimated locally),0.33 per call) 
   Indirect call(204440443 (estimated locally),0.95 per call) 
dns_alloc_pcb/17 (dns_alloc_pcb) @0706ae00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_pcbs/1 (read)dns_pcbs/1 (write)dns_last_pcb_idx/2 (write)dns_last_pcb_idx/2 (read)dns_pcbs/1 (read)dns_last_pcb_idx/2 (write)
  Referring: 
  Availability: local
  Function flags: count:261993004 (estimated locally) body local optimize_size
  Called by: dns_enqueue/25 (114504709 (estimated locally),0.51 per call) 
  Calls: dns_alloc_random_port/16 (128062181 (estimated locally),0.49 per call) 
dns_alloc_random_port/16 (dns_alloc_random_port) @0706ab60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ip_addr_any/28 (addr)dns_recv/24 (addr)
  Referring: 
  Availability: local
  Function flags: count:14163606 (estimated locally) body local optimize_size
  Called by: dns_alloc_pcb/17 (128062181 (estimated locally),0.49 per call) 
  Calls: udp_recv/45 (10734218 (estimated locally),0.76 per call) udp_remove/30 (2258058 (estimated locally),0.16 per call) udp_bind/44 (118111601 (estimated locally),8.34 per call) rand/29 (1073741824 (estimated locally),75.81 per call) udp_new_ip_type/43 (14163606 (estimated locally),1.00 per call) 
dns_send/15 (dns_send) @0706a8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_servers/6 (read)dns_table/4 (write)dns_table/4 (addr)dns_table/4 (read)dns_table/4 (read)dns_table/4 (read)dns_servers/6 (addr)dns_pcbs/1 (read)
  Referring: 
  Availability: local
  Function flags: count:181990 (estimated locally) body local optimize_size
  Called by: dns_check_entry/21 (9533 (estimated locally),0.04 per call) dns_check_entry/21 (21475 (estimated locally),0.10 per call) 
  Calls: pbuf_free/36 (23511 (estimated locally),0.13 per call) udp_sendto/39 (23511 (estimated locally),0.13 per call) pbuf_take_at/38 (23511 (estimated locally),0.13 per call) pbuf_put_at/37 (23511 (estimated locally),0.13 per call) pbuf_take_at/38 (427466 (estimated locally),2.35 per call) pbuf_put_at/37 (427466 (estimated locally),2.35 per call) pbuf_free/36 (24879 (estimated locally),0.14 per call) pbuf_take/35 (48390 (estimated locally),0.27 per call) lwip_htons/34 (48390 (estimated locally),0.27 per call) memset/33 (48390 (estimated locally),0.27 per call) pbuf_alloc/32 (49246 (estimated locally),0.27 per call) strlen/31 (49246 (estimated locally),0.27 per call) dns_call_found/18 (25369 (estimated locally),0.14 per call) 
dns_skip_name/14 (dns_skip_name) @0706a620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:122575812 (estimated locally) body local optimize_size
  Called by: dns_recv/24 (153850 (estimated locally),0.00 per call) 
  Calls: pbuf_try_get_at/48 (990385272 (estimated locally),8.08 per call) pbuf_try_get_at/48 (1073741824 (estimated locally),8.76 per call) 
dns_compare_name/13 (dns_compare_name) @0706a380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:92050635 (estimated locally) body optimize_size
  Called by: 
  Calls: 
dns_lookup/12 (dns_lookup) @07051540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dns_table/4 (read)dns_table/4 (addr)dns_table/4 (read)
  Referring: 
  Availability: local
  Function flags: count:224310680 (estimated locally) body local optimize_size
  Called by: dns_gethostbyname_addrtype/27 (503964950 (estimated locally),0.47 per call) 
  Calls: lwip_strnicmp/41 (173860276 (estimated locally),0.78 per call) 
dns_tmr/11 (dns_tmr) @07051c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: dns_check_entries/22 (1073741824 (estimated locally),1.00 per call) 
dns_getserver/10 (dns_getserver) @070519a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: dns_servers/6 (addr)ip_addr_any/28 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
dns_setserver/9 (dns_setserver) @07051700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: dns_servers/6 (write)dns_servers/6 (write)ip_addr_any/28 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
dns_init/8 (dns_init) @07051460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
dns_mquery_v4group/7 (dns_mquery_v4group) @0704e438
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
dns_servers/6 (dns_servers) @0704e3a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_send/15 (read)dns_send/15 (addr)dns_recv/24 (read)dns_backupserver_available.part.0/50 (read)dns_setserver/9 (write)dns_getserver/10 (addr)dns_setserver/9 (write)dns_gethostbyname_addrtype/27 (read)
  Availability: available
  Varpool flags:
dns_requests/5 (dns_requests) @0704e318
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_call_found/18 (write)dns_call_found/18 (read)dns_call_found/18 (read)dns_call_found/18 (read)dns_enqueue/25 (read)dns_enqueue/25 (write)dns_enqueue/25 (write)dns_enqueue/25 (write)dns_enqueue/25 (read)dns_enqueue/25 (addr)
  Availability: available
  Varpool flags:
dns_table/4 (dns_table) @0704e288
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_correct_response/23 (write)dns_lookup/12 (read)dns_create_txid/19 (read)dns_check_entry/21 (write)dns_check_entry/21 (write)dns_check_entry/21 (read)dns_check_entry/21 (write)dns_check_entry/21 (write)dns_lookup/12 (read)dns_lookup/12 (addr)dns_enqueue/25 (read)dns_enqueue/25 (addr)dns_call_found/18 (write)dns_enqueue/25 (read)dns_create_txid/19 (read)dns_send/15 (read)dns_call_found/18 (addr)dns_call_found/18 (read)dns_call_found/18 (read)dns_call_found/18 (read)dns_call_found/18 (write)dns_call_found/18 (read)dns_call_found/18 (read)dns_correct_response/23 (write)dns_correct_response/23 (write)dns_correct_response/23 (write)dns_correct_response/23 (addr)dns_correct_response/23 (read)dns_correct_response/23 (read)dns_send/15 (read)dns_send/15 (write)dns_send/15 (addr)dns_send/15 (read)dns_send/15 (read)dns_check_entry/21 (addr)dns_check_entry/21 (read)dns_check_entry/21 (write)dns_check_entry/21 (write)dns_check_entry/21 (write)dns_check_entry/21 (write)dns_check_entry/21 (write)dns_check_entry/21 (read)dns_check_entry/21 (write)dns_check_entry/21 (read)dns_check_entry/21 (write)dns_check_entry/21 (read)dns_check_entry/21 (write)dns_check_entry/21 (write)dns_check_entry/21 (write)dns_enqueue/25 (read)dns_enqueue/25 (addr)dns_enqueue/25 (addr)dns_enqueue/25 (read)dns_recv/24 (addr)dns_recv/24 (read)dns_recv/24 (read)dns_recv/24 (read)dns_recv/24 (addr)dns_recv/24 (write)dns_recv/24 (write)dns_recv/24 (write)dns_recv/24 (write)
  Availability: available
  Varpool flags:
dns_seqno/3 (dns_seqno) @0704e1f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_enqueue/25 (read)dns_enqueue/25 (read)dns_enqueue/25 (read)dns_enqueue/25 (write)
  Availability: available
  Varpool flags:
dns_last_pcb_idx/2 (dns_last_pcb_idx) @0704e168
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_alloc_pcb/17 (write)dns_alloc_pcb/17 (read)dns_alloc_pcb/17 (write)
  Availability: available
  Varpool flags:
dns_pcbs/1 (dns_pcbs) @0704e0d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: dns_call_found/18 (read)dns_call_found/18 (write)dns_send/15 (read)dns_alloc_pcb/17 (read)dns_alloc_pcb/17 (write)dns_alloc_pcb/17 (read)
  Availability: available
  Varpool flags:

;; Function dns_call_found (dns_call_found, funcdef_no=11, decl_uid=7208, cgraph_uid=12, symbol_order=18)

Modification phase of node dns_call_found/18
dns_call_found (u8_t idx, struct ip_addr_t * addr)
{
  u8_t i;
  int _1;
  void (*<T6bc>) (const char *, const struct ip_addr_t *, void *) _2;
  unsigned char _3;
  int _4;
  char[256] * _5;
  void * _6;
  int _7;
  unsigned char _8;
  int _9;
  unsigned char _10;
  int _11;
  unsigned char _12;
  int _13;
  unsigned char _14;
  int _15;
  struct udp_pcb * _16;
  unsigned char _17;
  int _18;

  <bb 2> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  _1 = (int) i_19;
  _2 = dns_requests[_1].found;
  if (_2 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 4> [local count: 601295421]:
  _3 = dns_requests[_1].dns_table_idx;
  if (_3 == idx_26(D))
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 204440443]:
  # DEBUG BEGIN_STMT
  _4 = (int) idx_26(D);
  _5 = &dns_table[_4].name;
  _6 = dns_requests[_1].arg;
  _2 (_5, addr_32(D), _6);
  # DEBUG BEGIN_STMT
  dns_requests[_1].found = 0B;

  <bb 6> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  i_35 = i_19 + 1;
  # DEBUG i => i_35

  <bb 7> [local count: 1073741824]:
  # i_19 = PHI <0(2), i_35(6)>
  # DEBUG i => i_19
  # DEBUG BEGIN_STMT
  if (i_19 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 18>; [20.00%]

  <bb 18> [local count: 214748365]:
  goto <bb 14>; [100.00%]

  <bb 8> [local count: 810630832]:
  # DEBUG BEGIN_STMT
  if (i_20 == idx_26(D))
    goto <bb 9>; [20.24%]
  else
    goto <bb 10>; [79.76%]

  <bb 9> [local count: 164071680]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 13>; [100.00%]

  <bb 10> [local count: 646559152]:
  # DEBUG BEGIN_STMT
  _7 = (int) i_20;
  _8 = dns_table[_7].state;
  if (_8 == 2)
    goto <bb 11>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 11> [local count: 219830111]:
  # DEBUG BEGIN_STMT
  _10 = dns_table[_7].pcb_idx;
  _11 = (int) idx_26(D);
  _12 = dns_table[_11].pcb_idx;
  if (_10 == _12)
    goto <bb 12>; [5.50%]
  else
    goto <bb 13>; [94.50%]

  <bb 12> [local count: 12090656]:
  # _9 = PHI <_11(11)>
  # DEBUG BEGIN_STMT
  dns_table[_9].pcb_idx = 4;
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 13> [local count: 798540176]:
  # DEBUG BEGIN_STMT
  i_28 = i_20 + 1;
  # DEBUG i => i_28

  <bb 14> [local count: 1013288540]:
  # i_20 = PHI <i_28(13), 0(18)>
  # DEBUG i => i_20
  # DEBUG BEGIN_STMT
  if (i_20 != 4)
    goto <bb 8>; [80.00%]
  else
    goto <bb 15>; [20.00%]

  <bb 15> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  _13 = (int) idx_26(D);
  _14 = dns_table[_13].pcb_idx;
  if (_14 <= 3)
    goto <bb 16>; [33.00%]
  else
    goto <bb 17>; [67.00%]

  <bb 16> [local count: 70866960]:
  # DEBUG BEGIN_STMT
  _15 = (int) _14;
  _16 = dns_pcbs[_15];
  udp_remove (_16);
  # DEBUG BEGIN_STMT
  _17 = dns_table[_13].pcb_idx;
  _18 = (int) _17;
  dns_pcbs[_18] = 0B;
  # DEBUG BEGIN_STMT
  dns_table[_13].pcb_idx = 4;

  <bb 17> [local count: 214748364]:
  return;

}



;; Function dns_send (dns_send, funcdef_no=8, decl_uid=7265, cgraph_uid=9, symbol_order=15)

Modification phase of node dns_send/15
dns_send (u8_t idx)
{
  const struct ip_addr_t * dst;
  u8_t pcb_idx;
  u8_t n;
  const char * hostname;
  u16_t copy_len;
  u16_t query_idx;
  struct pbuf * p;
  struct dns_query qry;
  struct dns_hdr hdr;
  err_t err;
  int _1;
  unsigned char _2;
  short unsigned int _3;
  int _4;
  long unsigned int _5;
  char[256] * _6;
  unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  char _12;
  int _14;
  int _15;
  int _16;
  int _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  char _21;
  unsigned char _22;
  int _23;
  int _24;
  struct udp_pcb * _25;
  err_t _30;

  <bb 2> [local count: 181990]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) idx_34(D);
  # DEBUG D#4 => &dns_table[_1]
  # DEBUG entry => D#4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct dns_table_entry *)&dns_table][_1].server_idx;
  if (_2 > 1)
    goto <bb 17>; [59.00%]
  else
    goto <bb 4>; [41.00%]

  <bb 17> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 74616]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = (int) _2;
  _5 = dns_servers[_4].addr;
  if (_5 == 0)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 25369]:
  # DEBUG BEGIN_STMT
  dns_call_found (idx_34(D), 0B);
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 0;
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 6> [local count: 49246]:
  # DEBUG BEGIN_STMT
  _6 = &MEM[(struct dns_table_entry *)&dns_table][_1].name;
  _7 = strlen (_6);
  _8 = (short unsigned int) _7;
  _9 = _8 + 18;
  p_37 = pbuf_alloc (54, _9, 640);
  # DEBUG p => p_37
  # DEBUG BEGIN_STMT
  if (p_37 != 0B)
    goto <bb 7>; [98.26%]
  else
    goto <bb 16>; [1.74%]

  <bb 7> [local count: 48390]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (&hdr, 0, 12);
  # DEBUG BEGIN_STMT
  _10 = MEM[(struct dns_table_entry *)&dns_table][_1].txid;
  _11 = lwip_htons (_10);
  hdr.id = _11;
  # DEBUG BEGIN_STMT
  hdr.flags1 = 1;
  # DEBUG BEGIN_STMT
  hdr.numquestions = 256;
  # DEBUG BEGIN_STMT
  pbuf_take (p_37, &hdr, 12);
  # DEBUG BEGIN_STMT
  # DEBUG hostname => _6
  # DEBUG BEGIN_STMT
  hostname_45 = _6 + 4294967295;
  # DEBUG hostname => hostname_45
  # DEBUG BEGIN_STMT
  # DEBUG query_idx => 12

  <bb 8> [local count: 452345]:
  # query_idx_26 = PHI <12(7), query_idx_53(19)>
  # hostname_27 = PHI <hostname_45(7), hostname_44(19)>
  # DEBUG hostname => hostname_27
  # DEBUG query_idx => query_idx_26
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  hostname_46 = hostname_27 + 1;
  # DEBUG hostname => hostname_46
  # DEBUG BEGIN_STMT
  # DEBUG hostname_part => hostname_46
  # DEBUG BEGIN_STMT
  # DEBUG n => 0
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 3776163]:
  # DEBUG BEGIN_STMT
  n_48 = n_29 + 1;
  # DEBUG n => n_48
  # DEBUG BEGIN_STMT
  hostname_49 = hostname_28 + 1;
  # DEBUG hostname => hostname_49

  <bb 10> [local count: 4228507]:
  # hostname_28 = PHI <hostname_46(8), hostname_49(9)>
  # n_29 = PHI <0(8), n_48(9)>
  # DEBUG n => n_29
  # DEBUG hostname => hostname_28
  # DEBUG BEGIN_STMT
  _12 = *hostname_28;
  if (_12 != 46)
    goto <bb 11>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 11> [local count: 3995939]:
  if (_12 != 0)
    goto <bb 9>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 12> [local count: 452345]:
  # hostname_44 = PHI <hostname_28(10), hostname_28(11)>
  # n_47 = PHI <n_29(10), n_29(11)>
  # DEBUG BEGIN_STMT
  _14 = hostname_44 - hostname_46;
  copy_len_50 = (u16_t) _14;
  # DEBUG copy_len => copy_len_50
  # DEBUG BEGIN_STMT
  _15 = (int) query_idx_26;
  _16 = (int) n_47;
  _17 = _15 + _16;
  if (_17 > 65534)
    goto <bb 13>; [5.50%]
  else
    goto <bb 14>; [94.50%]

  <bb 13> [local count: 24879]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  # DEBUG overflow_return => NULL
  # DEBUG BEGIN_STMT
  pbuf_free (p_37);
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 14> [local count: 427466]:
  # DEBUG BEGIN_STMT
  pbuf_put_at (p_37, query_idx_26, n_47);
  # DEBUG BEGIN_STMT
  _18 = query_idx_26 + 1;
  pbuf_take_at (p_37, hostname_46, copy_len_50, _18);
  # DEBUG BEGIN_STMT
  _19 = (short unsigned int) n_47;
  _20 = _19 + query_idx_26;
  query_idx_53 = _20 + 1;
  # DEBUG query_idx => query_idx_53
  # DEBUG BEGIN_STMT
  _21 = *hostname_44;
  if (_21 != 0)
    goto <bb 19>; [94.50%]
  else
    goto <bb 15>; [5.50%]

  <bb 19> [local count: 403955]:
  goto <bb 8>; [100.00%]

  <bb 15> [local count: 23511]:
  # _3 = PHI <_20(14)>
  # query_idx_13 = PHI <query_idx_53(14)>
  # DEBUG BEGIN_STMT
  pbuf_put_at (p_37, query_idx_13, 0);
  # DEBUG BEGIN_STMT
  query_idx_55 = _3 + 2;
  # DEBUG query_idx => query_idx_55
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  qry.type = 256;
  # DEBUG BEGIN_STMT
  qry.cls = 256;
  # DEBUG BEGIN_STMT
  pbuf_take_at (p_37, &qry, 4, query_idx_55);
  # DEBUG BEGIN_STMT
  pcb_idx_59 = MEM[(struct dns_table_entry *)&dns_table][_1].pcb_idx;
  # DEBUG pcb_idx => pcb_idx_59
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG dst_port => 53
  # DEBUG BEGIN_STMT
  _22 = MEM[(struct dns_table_entry *)&dns_table][_1].server_idx;
  _23 = (int) _22;
  dst_60 = &dns_servers[_23];
  # DEBUG dst => dst_60
  # DEBUG BEGIN_STMT
  _24 = (int) pcb_idx_59;
  _25 = dns_pcbs[_24];
  err_62 = udp_sendto (_25, p_37, dst_60, 53);
  # DEBUG err => err_62
  # DEBUG BEGIN_STMT
  pbuf_free (p_37);

  <bb 16> [local count: 74616]:
  # _30 = PHI <0(5), -1(6), -6(13), err_62(15)>
  # DEBUG err => NULL
  hdr ={v} {CLOBBER};
  qry ={v} {CLOBBER};
  return _30;

}



;; Function dns_check_entry (dns_check_entry, funcdef_no=14, decl_uid=7332, cgraph_uid=15, symbol_order=21)

Modification phase of node dns_check_entry/21
dns_check_entry (u8_t i)
{
  struct dns_table_entry * entry;
  int _1;
  unsigned char _2;
  short unsigned int _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char _10;
  long unsigned int _11;
  long unsigned int _12;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) i_18(D);
  entry_19 = &dns_table[_1];
  # DEBUG entry => entry_19
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (i_18(D) > 3)
    goto <bb 18>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 18> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 20> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct dns_table_entry *)&dns_table][_1].state;
  switch (_2) <default: <L31> [20.00%], case 0: <L27> [20.00%], case 1: <L3> [20.00%], case 2: <L6> [20.00%], case 3: <L17> [20.00%]>

  <bb 19> [local count: 21475]:
<L31>:
  goto <bb 16>; [100.00%]

  <bb 5> [local count: 21475]:
<L3>:
  # DEBUG BEGIN_STMT
  _3 = dns_create_txid ();
  MEM[(struct dns_table_entry *)&dns_table][_1].txid = _3;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 2;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].server_idx = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].tmr = 1;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].retries = 0;
  # DEBUG BEGIN_STMT
  dns_send (i_18(D));
  # DEBUG err => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 6> [local count: 21475]:
<L6>:
  # DEBUG BEGIN_STMT
  _4 = MEM[(struct dns_table_entry *)&dns_table][_1].tmr;
  _5 = _4 + 255;
  MEM[(struct dns_table_entry *)&dns_table][_1].tmr = _5;
  if (_5 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 7> [local count: 10737]:
  # DEBUG BEGIN_STMT
  _6 = MEM[(struct dns_table_entry *)&dns_table][_1].retries;
  _7 = _6 + 1;
  MEM[(struct dns_table_entry *)&dns_table][_1].retries = _7;
  if (_7 == 4)
    goto <bb 8>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 8> [local count: 3651]:
  # DEBUG BEGIN_STMT
  _8 = dns_backupserver_available (entry_19);
  if (_8 != 0)
    goto <bb 9>; [67.00%]
  else
    goto <bb 10>; [33.00%]

  <bb 9> [local count: 2446]:
  # DEBUG BEGIN_STMT
  _9 = MEM[(struct dns_table_entry *)&dns_table][_1].server_idx;
  _10 = _9 + 1;
  MEM[(struct dns_table_entry *)&dns_table][_1].server_idx = _10;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].tmr = 1;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].retries = 0;
  goto <bb 12>; [100.00%]

  <bb 10> [local count: 1205]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_call_found (i_18(D), 0B);
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 0;
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 11> [local count: 7087]:
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].tmr = _7;

  <bb 12> [local count: 9533]:
  # DEBUG BEGIN_STMT
  dns_send (i_18(D));
  # DEBUG err => NULL
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 13> [local count: 21475]:
<L17>:
  # DEBUG BEGIN_STMT
  _11 = MEM[(struct dns_table_entry *)&dns_table][_1].ttl;
  if (_11 == 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 14> [local count: 10737]:
  _12 = _11 + 4294967295;
  MEM[(struct dns_table_entry *)&dns_table][_1].ttl = _12;
  if (_12 == 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 15> [local count: 16106]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_1].state = 0;
  goto <bb 17>; [100.00%]

  <bb 21> [local count: 214748365]:

  <bb 16> [local count: 214748365]:
<L28>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT
  goto <bb 21>; [100.00%]

  <bb 17> [local count: 85899]:
<L27>:
  return;

}



;; Function dns_recv (dns_recv, funcdef_no=17, decl_uid=7203, cgraph_uid=18, symbol_order=24)

Modification phase of node dns_recv/24
dns_recv (void * arg, struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * addr, u16_t port)
{
  struct ip4_addr_t ip4addr;
  struct dns_table_entry * entry;
  u16_t nanswers;
  u16_t nquestions;
  struct dns_query qry;
  struct dns_answer ans;
  struct dns_hdr hdr;
  u16_t res_idx;
  u16_t txid;
  u8_t i;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  int _4;
  unsigned char _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  unsigned char _9;
  signed char _10;
  long unsigned int _11;
  unsigned char _12;
  int _13;
  long unsigned int _14;
  char[256] * _15;
  short unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  unsigned char _19;
  unsigned char _20;
  short unsigned int _21;
  short unsigned int _22;
  short unsigned int _23;
  short unsigned int _24;
  short unsigned int _25;
  int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  int _30;
  short unsigned int _31;
  short unsigned int _32;
  int _33;
  int _34;
  short unsigned int _35;
  short unsigned int _36;
  short unsigned int _37;
  unsigned char _52;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_48(D)->tot_len;
  if (_1 <= 15)
    goto <bb 3>; [51.12%]
  else
    goto <bb 4>; [48.88%]

  <bb 3> [local count: 548896821]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 4> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _2 = pbuf_copy_partial (p_48(D), &hdr, 12, 0);
  if (_2 == 12)
    goto <bb 5>; [20.24%]
  else
    goto <bb 46>; [79.76%]

  <bb 5> [local count: 106228629]:
  # DEBUG BEGIN_STMT
  _3 = hdr.id;
  txid_51 = lwip_htons (_3);
  # DEBUG txid => txid_51
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 45>; [100.00%]

  <bb 6> [local count: 395342869]:
  # DEBUG BEGIN_STMT
  _4 = (int) i_40;
  entry_53 = &dns_table[_4];
  # DEBUG entry => entry_53
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct dns_table_entry *)&dns_table][_4].state;
  if (_5 == 2)
    goto <bb 7>; [34.00%]
  else
    goto <bb 44>; [66.00%]

  <bb 7> [local count: 134416575]:
  _6 = MEM[(struct dns_table_entry *)&dns_table][_4].txid;
  if (_6 == txid_51)
    goto <bb 8>; [5.50%]
  else
    goto <bb 44>; [94.50%]

  <bb 8> [local count: 7392912]:
  # _26 = PHI <_4(7)>
  # i_38 = PHI <i_40(7)>
  # entry_39 = PHI <entry_53(7)>
  # DEBUG BEGIN_STMT
  _7 = hdr.numquestions;
  nquestions_55 = lwip_htons (_7);
  # DEBUG nquestions => nquestions_55
  # DEBUG BEGIN_STMT
  _8 = hdr.numanswers;
  nanswers_57 = lwip_htons (_8);
  # DEBUG nanswers => nanswers_57
  # DEBUG BEGIN_STMT
  _9 = hdr.flags1;
  _10 = (signed char) _9;
  if (_10 >= 0)
    goto <bb 9>; [42.57%]
  else
    goto <bb 10>; [57.43%]

  <bb 9> [local count: 3147162]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 10> [local count: 4245749]:
  # DEBUG BEGIN_STMT
  if (nquestions_55 != 1)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 2122875]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 12> [local count: 2122875]:
  # DEBUG BEGIN_STMT
  _11 = addr_58(D)->addr;
  _12 = MEM[(struct dns_table_entry *)&dns_table][_26].server_idx;
  _13 = (int) _12;
  _14 = dns_servers[_13].addr;
  if (_11 != _14)
    goto <bb 13>; [67.00%]
  else
    goto <bb 14>; [33.00%]

  <bb 13> [local count: 1422326]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 14> [local count: 700549]:
  # DEBUG BEGIN_STMT
  _15 = &MEM[(struct dns_table_entry *)&dns_table][_26].name;
  res_idx_60 = dns_compare_name (_15, p_48(D), 12);
  # DEBUG res_idx => res_idx_60
  # DEBUG BEGIN_STMT
  if (res_idx_60 == 65535)
    goto <bb 15>; [35.01%]
  else
    goto <bb 16>; [64.99%]

  <bb 15> [local count: 245262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 16> [local count: 455287]:
  # DEBUG BEGIN_STMT
  _16 = pbuf_copy_partial (p_48(D), &qry, 4, res_idx_60);
  if (_16 != 4)
    goto <bb 17>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 17> [local count: 227643]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 18> [local count: 227643]:
  # DEBUG BEGIN_STMT
  _17 = qry.cls;
  if (_17 != 256)
    goto <bb 20>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 19> [local count: 113822]:
  _18 = qry.type;
  if (_18 != 256)
    goto <bb 20>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 20> [local count: 170732]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 21> [local count: 56911]:
  # DEBUG BEGIN_STMT
  if (res_idx_60 > 65531)
    goto <bb 22>; [34.00%]
  else
    goto <bb 23>; [66.00%]

  <bb 22> [local count: 19350]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 23> [local count: 37561]:
  # DEBUG BEGIN_STMT
  res_idx_62 = res_idx_60 + 4;
  # DEBUG res_idx => res_idx_62
  # DEBUG BEGIN_STMT
  _19 = hdr.flags2;
  _52 = _19 & 15;
  if (_52 != 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 48>; [50.00%]

  <bb 48> [local count: 18781]:
  goto <bb 41>; [100.00%]

  <bb 24> [local count: 18781]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = dns_backupserver_available (entry_39);
  if (_20 != 0)
    goto <bb 25>; [33.00%]
  else
    goto <bb 43>; [67.00%]

  <bb 25> [local count: 6198]:
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_26].retries = 3;
  # DEBUG BEGIN_STMT
  MEM[(struct dns_table_entry *)&dns_table][_26].tmr = 1;
  # DEBUG BEGIN_STMT
  dns_check_entry (i_38);
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 26> [local count: 153850]:
  # DEBUG BEGIN_STMT
  res_idx_64 = dns_skip_name (p_48(D), res_idx_41);
  # DEBUG res_idx => res_idx_64
  # DEBUG BEGIN_STMT
  if (res_idx_64 == 65535)
    goto <bb 27>; [2.00%]
  else
    goto <bb 28>; [98.00%]

  <bb 27> [local count: 3077]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 28> [local count: 150773]:
  # DEBUG BEGIN_STMT
  _21 = pbuf_copy_partial (p_48(D), &ans, 10, res_idx_64);
  if (_21 != 10)
    goto <bb 29>; [2.00%]
  else
    goto <bb 30>; [98.00%]

  <bb 29> [local count: 3015]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 30> [local count: 147757]:
  # DEBUG BEGIN_STMT
  if (res_idx_64 > 65525)
    goto <bb 31>; [2.00%]
  else
    goto <bb 32>; [98.00%]

  <bb 31> [local count: 2955]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 32> [local count: 144802]:
  # DEBUG BEGIN_STMT
  res_idx_66 = res_idx_64 + 10;
  # DEBUG res_idx => res_idx_66
  # DEBUG BEGIN_STMT
  _22 = ans.cls;
  if (_22 == 256)
    goto <bb 33>; [51.12%]
  else
    goto <bb 38>; [48.88%]

  <bb 33> [local count: 74023]:
  # DEBUG BEGIN_STMT
  _23 = ans.type;
  if (_23 == 256)
    goto <bb 34>; [34.00%]
  else
    goto <bb 38>; [66.00%]

  <bb 34> [local count: 25168]:
  _24 = ans.len;
  if (_24 == 1024)
    goto <bb 35>; [2.00%]
  else
    goto <bb 38>; [98.00%]

  <bb 35> [local count: 503]:
  # res_idx_78 = PHI <res_idx_66(34)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = pbuf_copy_partial (p_48(D), &ip4addr, 4, res_idx_78);
  if (_25 != 4)
    goto <bb 36>; [79.76%]
  else
    goto <bb 37>; [20.24%]

  <bb 36> [local count: 401]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  ip4addr ={v} {CLOBBER};
  goto <bb 46>; [100.00%]

  <bb 37> [local count: 102]:
  # DEBUG BEGIN_STMT
  _27 = ip4addr.addr;
  dns_table[_26].ipaddr.addr = _27;
  # DEBUG BEGIN_STMT
  pbuf_free (p_48(D));
  # DEBUG BEGIN_STMT
  _28 = ans.ttl;
  _29 = lwip_htonl (_28);
  dns_correct_response (i_38, _29);
  # DEBUG BEGIN_STMT
  ip4addr ={v} {CLOBBER};
  goto <bb 47>; [100.00%]

  <bb 38> [local count: 144299]:
  # DEBUG BEGIN_STMT
  _30 = (int) res_idx_66;
  _31 = ans.len;
  _32 = lwip_htons (_31);
  _33 = (int) _32;
  _34 = _30 + _33;
  if (_34 > 65535)
    goto <bb 39>; [2.00%]
  else
    goto <bb 40>; [98.00%]

  <bb 39> [local count: 2886]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 46>; [100.00%]

  <bb 40> [local count: 141413]:
  # DEBUG BEGIN_STMT
  _35 = ans.len;
  _36 = lwip_htons (_35);
  res_idx_76 = _36 + res_idx_66;
  # DEBUG res_idx => res_idx_76
  # DEBUG BEGIN_STMT
  nanswers_77 = nanswers_42 + 65535;
  # DEBUG nanswers => nanswers_77

  <bb 41> [local count: 160193]:
  # res_idx_41 = PHI <res_idx_76(40), res_idx_62(48)>
  # nanswers_42 = PHI <nanswers_77(40), nanswers_57(48)>
  # DEBUG nanswers => nanswers_42
  # DEBUG res_idx => res_idx_41
  # DEBUG BEGIN_STMT
  if (nanswers_42 != 0)
    goto <bb 42>; [98.00%]
  else
    goto <bb 43>; [2.00%]

  <bb 42> [local count: 156989]:
  _37 = p_48(D)->tot_len;
  if (_37 > res_idx_41)
    goto <bb 26>; [98.00%]
  else
    goto <bb 43>; [2.00%]

  <bb 43> [local count: 18927]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_48(D));
  # DEBUG BEGIN_STMT
  dns_call_found (i_38, 0B);
  # DEBUG BEGIN_STMT
  dns_table[_26].state = 0;
  # DEBUG BEGIN_STMT
  goto <bb 47>; [100.00%]

  <bb 44> [local count: 387949957]:
  # DEBUG BEGIN_STMT
  i_85 = i_40 + 1;
  # DEBUG i => i_85

  <bb 45> [local count: 494178586]:
  # i_40 = PHI <0(5), i_85(44)>
  # DEBUG i => i_40
  # DEBUG BEGIN_STMT
  if (i_40 != 4)
    goto <bb 6>; [80.00%]
  else
    goto <bb 46>; [20.00%]

  <bb 46> [local count: 1073722794]:
ignore_packet:
  # DEBUG BEGIN_STMT
  pbuf_free (p_48(D));
  # DEBUG BEGIN_STMT

  <bb 47> [local count: 1073741822]:
  hdr ={v} {CLOBBER};
  ans ={v} {CLOBBER};
  qry ={v} {CLOBBER};
  return;

}



;; Function dns_init (dns_init, funcdef_no=1, decl_uid=7055, cgraph_uid=2, symbol_order=8)

Modification phase of node dns_init/8
dns_init ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function dns_setserver (dns_setserver, funcdef_no=2, decl_uid=7060, cgraph_uid=3, symbol_order=9)

Modification phase of node dns_setserver/9
dns_setserver (u8_t numdns, const struct ip_addr_t * dnsserver)
{
  int _1;
  int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (numdns_4(D) <= 1)
    goto <bb 3>; [41.00%]
  else
    goto <bb 6>; [59.00%]

  <bb 3> [local count: 440234148]:
  # DEBUG BEGIN_STMT
  if (dnsserver_6(D) != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 308163903]:
  # DEBUG BEGIN_STMT
  _1 = (int) numdns_4(D);
  dns_servers[_1] = *dnsserver_6(D);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 132070244]:
  # DEBUG BEGIN_STMT
  _2 = (int) numdns_4(D);
  dns_servers[_2] = ip_addr_any;

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function dns_getserver (dns_getserver, funcdef_no=3, decl_uid=7062, cgraph_uid=4, symbol_order=10)

Modification phase of node dns_getserver/10
dns_getserver (u8_t numdns)
{
  int _1;
  const struct ip_addr_t * _2;
  const struct ip_addr_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (numdns_3(D) <= 1)
    goto <bb 3>; [41.00%]
  else
    goto <bb 4>; [59.00%]

  <bb 3> [local count: 440234148]:
  # DEBUG BEGIN_STMT
  _1 = (int) numdns_3(D);
  _4 = &dns_servers[_1];

  <bb 4> [local count: 1073741824]:
  # _2 = PHI <_4(3), &ip_addr_any(2)>
  return _2;

}



;; Function dns_tmr (dns_tmr, funcdef_no=4, decl_uid=7057, cgraph_uid=5, symbol_order=11)

Modification phase of node dns_tmr/11
dns_tmr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  dns_check_entries ();
  return;

}



;; Function dns_gethostbyname_addrtype (dns_gethostbyname_addrtype, funcdef_no=20, decl_uid=7073, cgraph_uid=21, symbol_order=27)

Modification phase of node dns_gethostbyname_addrtype/27
dns_gethostbyname_addrtype (const char * hostname, struct ip_addr_t * addr, void (*dns_found_callback) (const char *, const struct ip_addr_t *, void *) found, void * callback_arg, u8_t dns_addrtype)
{
  size_t hostnamelen;
  char _1;
  int _2;
  signed char _3;
  long unsigned int _4;
  err_t _5;
  err_t _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (addr_7(D) == 0B)
    goto <bb 10>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  if (hostname_8(D) == 0B)
    goto <bb 10>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 1064099892]:
  _1 = *hostname_8(D);
  if (_1 == 0)
    goto <bb 10>; [1.04%]
  else
    goto <bb 5>; [98.96%]

  <bb 5> [local count: 1053033253]:
  # DEBUG BEGIN_STMT
  hostnamelen_10 = strlen (hostname_8(D));
  # DEBUG hostnamelen => hostnamelen_10
  # DEBUG BEGIN_STMT
  if (hostnamelen_10 > 255)
    goto <bb 10>; [2.09%]
  else
    goto <bb 6>; [97.91%]

  <bb 6> [local count: 1031024857]:
  # DEBUG BEGIN_STMT
  _2 = ip4addr_aton (hostname_8(D), addr_7(D));
  if (_2 != 0)
    goto <bb 10>; [51.12%]
  else
    goto <bb 7>; [48.88%]

  <bb 7> [local count: 503964950]:
  # DEBUG BEGIN_STMT
  _3 = dns_lookup (hostname_8(D), addr_7(D));
  if (_3 == 0)
    goto <bb 10>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 8> [local count: 332616867]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = dns_servers[0].addr;
  if (_4 == 0)
    goto <bb 10>; [2.09%]
  else
    goto <bb 9>; [97.91%]

  <bb 9> [local count: 325665174]:
  # DEBUG BEGIN_STMT
  _16 = dns_enqueue (hostname_8(D), hostnamelen_10, found_13(D), callback_arg_14(D));

  <bb 10> [local count: 1073741824]:
  # _5 = PHI <-16(3), -16(5), 0(6), 0(7), -6(8), _16(9), -16(2), -16(4)>
  return _5;

}



;; Function dns_gethostbyname (dns_gethostbyname, funcdef_no=19, decl_uid=7067, cgraph_uid=20, symbol_order=26)

Modification phase of node dns_gethostbyname/26
dns_gethostbyname (const char * hostname, struct ip_addr_t * addr, void (*dns_found_callback) (const char *, const struct ip_addr_t *, void *) found, void * callback_arg)
{
  err_t _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _7 = dns_gethostbyname_addrtype (hostname_2(D), addr_3(D), found_4(D), callback_arg_5(D), 0);
  return _7;

}


