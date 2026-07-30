
IPA constant propagation start:
Determining dynamic type for call: _5 = _3 (_4, arg_2(D), err_1(D));
  Starting walk at: _5 = _3 (_4, arg_2(D), err_1(D));
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = _3 (_4, arg_2(D), err_1(D));
  Starting walk at: _5 = _3 (_4, arg_2(D), err_1(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = altcp_proxyconnect_send_request (arg_2(D));
  Starting walk at: _6 = altcp_proxyconnect_send_request (arg_2(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _18 = _16 (_17, arg_1(D), 0);
  Starting walk at: _18 = _16 (_17, arg_1(D), 0);
  instance pointer: _17  Outer instance pointer: _17 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_5(D));
  Function call may change dynamic type:altcp_recved (inner_conn_4(D), _13);
  Function call may change dynamic type:idx_12 = pbuf_memfind (p_5(D), "\r\n\r\n", 4, 0);
Determining dynamic type for call: _18 = _16 (_17, arg_1(D), 0);
  Starting walk at: _18 = _16 (_17, arg_1(D), 0);
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_5(D));
  Function call may change dynamic type:altcp_recved (inner_conn_4(D), _13);
  Function call may change dynamic type:idx_12 = pbuf_memfind (p_5(D), "\r\n\r\n", 4, 0);
Determining dynamic type for call: _10 = _8 (_9, arg_1(D), p_5(D), 0);
  Starting walk at: _10 = _8 (_9, arg_1(D), p_5(D), 0);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = _8 (_9, arg_1(D), p_5(D), 0);
  Starting walk at: _10 = _8 (_9, arg_1(D), p_5(D), 0);
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = _8 (_9, arg_1(D), p_5(D), 0);
  Starting walk at: _10 = _8 (_9, arg_1(D), p_5(D), 0);
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = _2 (_3, arg_1(D));
  Starting walk at: _4 = _2 (_3, arg_1(D));
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = _2 (_3, arg_1(D));
  Starting walk at: _4 = _2 (_3, arg_1(D));
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = _2 (_3, arg_1(D), len_4(D));
  Starting walk at: _5 = _2 (_3, arg_1(D), len_4(D));
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = _2 (_3, arg_1(D), len_4(D));
  Starting walk at: _5 = _2 (_3, arg_1(D), len_4(D));
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: altcp_proxyconnect_state_free (state_4);
  Starting walk at: altcp_proxyconnect_state_free (state_4);
  instance pointer: state_4  Outer instance pointer: state_4 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: altcp_proxyconnect_set_poll.part.0 (conn_1(D), interval_3(D));
  Starting walk at: altcp_proxyconnect_set_poll.part.0 (conn_1(D), interval_3(D));
  instance pointer: conn_1(D)  Outer instance pointer: conn_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = altcp_proxyconnect_new_tcp (arg_2(D), ip_type_3(D));
  Starting walk at: _5 = altcp_proxyconnect_new_tcp (arg_2(D), ip_type_3(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_9 = altcp_proxyconnect_new (config_7(D), inner_pcb_6);
  Starting walk at: ret_9 = altcp_proxyconnect_new (config_7(D), inner_pcb_6);
  instance pointer: config_7(D)  Outer instance pointer: config_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:inner_pcb_6 = altcp_tcp_new_ip_type (ip_type_4(D));
Determining dynamic type for call: ret_9 = altcp_proxyconnect_new (config_7(D), inner_pcb_6);
  Starting walk at: ret_9 = altcp_proxyconnect_new (config_7(D), inner_pcb_6);
  instance pointer: inner_pcb_6  Outer instance pointer: inner_pcb_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:inner_pcb_6 = altcp_tcp_new_ip_type (ip_type_4(D));
Determining dynamic type for call: _1 = altcp_proxyconnect_setup (config_8(D), ret_7, inner_pcb_4(D));
  Starting walk at: _1 = altcp_proxyconnect_setup (config_8(D), ret_7, inner_pcb_4(D));
  instance pointer: config_8(D)  Outer instance pointer: config_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_7 = altcp_alloc ();
Determining dynamic type for call: _1 = altcp_proxyconnect_setup (config_8(D), ret_7, inner_pcb_4(D));
  Starting walk at: _1 = altcp_proxyconnect_setup (config_8(D), ret_7, inner_pcb_4(D));
  instance pointer: ret_7  Outer instance pointer: ret_7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_7 = altcp_alloc ();
Determining dynamic type for call: _1 = altcp_proxyconnect_setup (config_8(D), ret_7, inner_pcb_4(D));
  Starting walk at: _1 = altcp_proxyconnect_setup (config_8(D), ret_7, inner_pcb_4(D));
  instance pointer: inner_pcb_4(D)  Outer instance pointer: inner_pcb_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_7 = altcp_alloc ();
Determining dynamic type for call: altcp_proxyconnect_setup_callbacks (conn_5(D), inner_conn_6(D));
  Starting walk at: altcp_proxyconnect_setup_callbacks (conn_5(D), inner_conn_6(D));
  instance pointer: conn_5(D)  Outer instance pointer: conn_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:state_9 = altcp_proxyconnect_state_alloc ();
Determining dynamic type for call: altcp_proxyconnect_setup_callbacks (conn_5(D), inner_conn_6(D));
  Starting walk at: altcp_proxyconnect_setup_callbacks (conn_5(D), inner_conn_6(D));
  instance pointer: inner_conn_6(D)  Outer instance pointer: inner_conn_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:state_9 = altcp_proxyconnect_state_alloc ();
Determining dynamic type for call: _1 (_2, err_8(D));
  Starting walk at: _1 (_2, err_8(D));
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = altcp_proxyconnect_lower_poll.part.0 (arg_5(D));
  Starting walk at: _2 = altcp_proxyconnect_lower_poll.part.0 (arg_5(D));
  instance pointer: arg_5(D)  Outer instance pointer: arg_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = altcp_proxyconnect_lower_sent.part.0 (arg_8(D), len_13(D));
  Starting walk at: _3 = altcp_proxyconnect_lower_sent.part.0 (arg_8(D), len_13(D));
  instance pointer: arg_8(D)  Outer instance pointer: arg_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = altcp_proxyconnect_lower_recv.part.0 (arg_7(D), inner_conn_10(D), p_11(D));
  Starting walk at: _1 = altcp_proxyconnect_lower_recv.part.0 (arg_7(D), inner_conn_10(D), p_11(D));
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = altcp_proxyconnect_lower_recv.part.0 (arg_7(D), inner_conn_10(D), p_11(D));
  Starting walk at: _1 = altcp_proxyconnect_lower_recv.part.0 (arg_7(D), inner_conn_10(D), p_11(D));
  instance pointer: inner_conn_10(D)  Outer instance pointer: inner_conn_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = altcp_proxyconnect_lower_recv.part.0 (arg_7(D), inner_conn_10(D), p_11(D));
  Starting walk at: _1 = altcp_proxyconnect_lower_recv.part.0 (arg_7(D), inner_conn_10(D), p_11(D));
  instance pointer: p_11(D)  Outer instance pointer: p_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = altcp_proxyconnect_lower_connected.part.0 (arg_6(D), err_10(D));
  Starting walk at: _3 = altcp_proxyconnect_lower_connected.part.0 (arg_6(D), err_10(D));
  instance pointer: arg_6(D)  Outer instance pointer: arg_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: len_16 = altcp_proxyconnect_format_request (0B, 0, "", _2);
  Starting walk at: len_16 = altcp_proxyconnect_format_request (0B, 0, "", _2);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: len_16 = altcp_proxyconnect_format_request (0B, 0, "", _2);
  Starting walk at: len_16 = altcp_proxyconnect_format_request (0B, 0, "", _2);
  instance pointer: ""  Outer instance pointer: "" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: len2_24 = altcp_proxyconnect_format_request (buffer_20, _4, host_22, _6);
  Starting walk at: len2_24 = altcp_proxyconnect_format_request (buffer_20, _4, host_22, _6);
  instance pointer: buffer_20  Outer instance pointer: buffer_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:host_22 = ip4addr_ntoa (_3);
  Function call may change dynamic type:buffer_20 = mem_malloc (alloc_len_18);
  Function call may change dynamic type:len_16 = altcp_proxyconnect_format_request (0B, 0, "", _2);
Determining dynamic type for call: len2_24 = altcp_proxyconnect_format_request (buffer_20, _4, host_22, _6);
  Starting walk at: len2_24 = altcp_proxyconnect_format_request (buffer_20, _4, host_22, _6);
  instance pointer: host_22  Outer instance pointer: host_22 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:host_22 = ip4addr_ntoa (_3);
  Function call may change dynamic type:buffer_20 = mem_malloc (alloc_len_18);
  Function call may change dynamic type:len_16 = altcp_proxyconnect_format_request (0B, 0, "", _2);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  altcp_proxyconnect_set_poll.part.0/64:
  Jump functions of caller  altcp_proxyconnect_lower_connected.part.0/63:
    callsite  altcp_proxyconnect_lower_connected.part.0/63 -> altcp_proxyconnect_send_request/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 160, by reference, for stmt _5 = _3 (_4, arg_2(D), err_1(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_lower_recv.part.0/62:
    indirect aggregate callsite, calling param 0, offset 192, by reference, for stmt _10 = _8 (_9, arg_1(D), p_5(D), 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 160, by reference, for stmt _18 = _16 (_17, arg_1(D), 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_lower_poll.part.0/61:
    indirect aggregate callsite, calling param 0, offset 256, by reference, for stmt _4 = _2 (_3, arg_1(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_lower_sent.part.0/60:
    indirect aggregate callsite, calling param 0, offset 224, by reference, for stmt _5 = _2 (_3, arg_1(D), len_4(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  altcp_poll/59:
  Jump functions of caller  snprintf/58:
  Jump functions of caller  ip4addr_ntoa/57:
  Jump functions of caller  mem_malloc/56:
  Jump functions of caller  altcp_connect/55:
  Jump functions of caller  altcp_write/54:
  Jump functions of caller  mem_free/53:
  Jump functions of caller  altcp_default_get_port/52:
  Jump functions of caller  altcp_default_get_ip/51:
  Jump functions of caller  altcp_default_get_tcp_addrinfo/50:
  Jump functions of caller  altcp_default_setprio/49:
  Jump functions of caller  altcp_default_nagle_disabled/48:
  Jump functions of caller  altcp_default_nagle_enable/47:
  Jump functions of caller  altcp_default_nagle_disable/46:
  Jump functions of caller  altcp_default_sndqueuelen/45:
  Jump functions of caller  altcp_default_sndbuf/44:
  Jump functions of caller  altcp_default_mss/43:
  Jump functions of caller  altcp_default_output/42:
  Jump functions of caller  altcp_default_shutdown/41:
  Jump functions of caller  altcp_default_bind/40:
  Jump functions of caller  altcp_tcp_new_ip_type/39:
  Jump functions of caller  altcp_recved/38:
  Jump functions of caller  pbuf_memfind/37:
  Jump functions of caller  altcp_abort/36:
  Jump functions of caller  altcp_close/35:
  Jump functions of caller  pbuf_free/34:
  Jump functions of caller  altcp_err/33:
  Jump functions of caller  altcp_sent/32:
  Jump functions of caller  altcp_recv/31:
  Jump functions of caller  altcp_arg/30:
  Jump functions of caller  mem_calloc/29:
  Jump functions of caller  altcp_free/28:
  Jump functions of caller  altcp_alloc/27:
  Jump functions of caller  altcp_proxyconnect_dealloc/25:
    callsite  altcp_proxyconnect_dealloc/25 -> altcp_proxyconnect_state_free/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_write/24:
  Jump functions of caller  altcp_proxyconnect_close/23:
  Jump functions of caller  altcp_proxyconnect_abort/22:
  Jump functions of caller  altcp_proxyconnect_listen/21:
  Jump functions of caller  altcp_proxyconnect_connect/20:
  Jump functions of caller  altcp_proxyconnect_recved/19:
  Jump functions of caller  altcp_proxyconnect_set_poll/18:
    callsite  altcp_proxyconnect_set_poll/18 -> altcp_proxyconnect_set_poll.part.0/64 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_alloc/17:
    callsite  altcp_proxyconnect_alloc/17 -> altcp_proxyconnect_new_tcp/16 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_new_tcp/16:
    callsite  altcp_proxyconnect_new_tcp/16 -> altcp_proxyconnect_new/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_new/15:
    callsite  altcp_proxyconnect_new/15 -> altcp_proxyconnect_setup/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_setup/14:
    callsite  altcp_proxyconnect_setup/14 -> altcp_proxyconnect_setup_callbacks/13 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  altcp_proxyconnect_setup/14 -> altcp_proxyconnect_state_alloc/4 : 
  Jump functions of caller  altcp_proxyconnect_setup_callbacks/13:
  Jump functions of caller  altcp_proxyconnect_lower_err/12:
    indirect aggregate callsite, calling param 0, offset 288, by reference, for stmt _1 (_2, err_8(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_lower_poll/11:
    callsite  altcp_proxyconnect_lower_poll/11 -> altcp_proxyconnect_lower_poll.part.0/61 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_lower_sent/10:
    callsite  altcp_proxyconnect_lower_sent/10 -> altcp_proxyconnect_lower_sent.part.0/60 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_lower_recv/9:
    callsite  altcp_proxyconnect_lower_recv/9 -> altcp_proxyconnect_lower_recv.part.0/62 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_lower_connected/8:
    callsite  altcp_proxyconnect_lower_connected/8 -> altcp_proxyconnect_lower_connected.part.0/63 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  altcp_proxyconnect_send_request/7:
    callsite  altcp_proxyconnect_send_request/7 -> altcp_proxyconnect_format_request/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [16, 65535]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
    callsite  altcp_proxyconnect_send_request/7 -> altcp_proxyconnect_format_request/6 : 
       param 0: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: ""
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
  Jump functions of caller  altcp_proxyconnect_format_request/6:
  Jump functions of caller  altcp_proxyconnect_state_free/5:
  Jump functions of caller  altcp_proxyconnect_state_alloc/4:

 Propagating constants:

Not considering altcp_proxyconnect_dealloc for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_write for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_close for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_abort for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_listen for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_connect for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_recved for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_set_poll for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_alloc for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_new_tcp for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_new for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_lower_err for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_lower_poll for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_lower_sent for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_lower_recv for cloning; -fipa-cp-clone disabled.
Not considering altcp_proxyconnect_lower_connected for cloning; -fipa-cp-clone disabled.

overall_size: 484, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 3.000000

IPA lattices after all propagation:

Lattices:
  Node: altcp_proxyconnect_set_poll.part.0/64:
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
  Node: altcp_proxyconnect_lower_connected.part.0/63:
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
  Node: altcp_proxyconnect_lower_recv.part.0/62:
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
  Node: altcp_proxyconnect_lower_poll.part.0/61:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_proxyconnect_lower_sent.part.0/60:
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
  Node: altcp_proxyconnect_dealloc/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_proxyconnect_write/24:
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
  Node: altcp_proxyconnect_close/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_proxyconnect_abort/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_proxyconnect_listen/21:
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
  Node: altcp_proxyconnect_connect/20:
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
  Node: altcp_proxyconnect_recved/19:
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
  Node: altcp_proxyconnect_set_poll/18:
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
  Node: altcp_proxyconnect_alloc/17:
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
  Node: altcp_proxyconnect_new_tcp/16:
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
  Node: altcp_proxyconnect_new/15:
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
  Node: altcp_proxyconnect_setup/14:
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
  Node: altcp_proxyconnect_setup_callbacks/13:
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
  Node: altcp_proxyconnect_lower_err/12:
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
  Node: altcp_proxyconnect_lower_poll/11:
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
  Node: altcp_proxyconnect_lower_sent/10:
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
  Node: altcp_proxyconnect_lower_recv/9:
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
  Node: altcp_proxyconnect_lower_connected/8:
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
  Node: altcp_proxyconnect_send_request/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_proxyconnect_format_request/6:
    param [0]: VARIABLE
               0B [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xffff
         size_t [0, 65535]
        AGGS VARIABLE
    param [2]: VARIABLE
               "" [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xffff
         int [0, 65535]
        AGGS VARIABLE
  Node: altcp_proxyconnect_state_free/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_proxyconnect_state_alloc/4:

IPA decision stage:

Propagated bits info for function altcp_proxyconnect_format_request/6:
 param 1: value = 0x0, mask = 0xffff
 param 3: value = 0x0, mask = 0xffff

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

altcp_proxyconnect_set_poll.part.0/64 (altcp_proxyconnect_set_poll.part.0) @07378620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: altcp_proxyconnect_lower_poll/11 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_proxyconnect_set_poll/18 (574129752 (estimated locally),0.53 per call) 
  Calls: altcp_poll/59 (1073741824 (estimated locally),1.00 per call) 
altcp_proxyconnect_lower_connected.part.0/63 (altcp_proxyconnect_lower_connected.part.0) @071c20e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_proxyconnect_lower_connected/8 (46017 (estimated locally),0.29 per call) 
  Calls: altcp_proxyconnect_send_request/7 (372251086 (estimated locally),0.35 per call) 
   Indirect call(701490739 (estimated locally),0.65 per call)  of param:0 loaded from aggregate passed by reference at offset 160 (vptr maybe changed)
altcp_proxyconnect_lower_recv.part.0/62 (altcp_proxyconnect_lower_recv.part.0) @071bde00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:153391 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_proxyconnect_lower_recv/9 (106891 (estimated locally),0.50 per call) 
  Calls: pbuf_free/34 (111 (estimated locally),0.00 per call) altcp_close/35 (207 (estimated locally),0.00 per call) pbuf_free/34 (3992 (estimated locally),0.03 per call) altcp_close/35 (6872 (estimated locally),0.04 per call) altcp_abort/36 (69 (estimated locally),0.00 per call) pbuf_memfind/37 (16034 (estimated locally),0.10 per call) altcp_recved/38 (16034 (estimated locally),0.10 per call) pbuf_free/34 (16034 (estimated locally),0.10 per call) 
   Indirect call(18913 (estimated locally),0.12 per call)  of param:0 loaded from aggregate passed by reference at offset 192 (vptr maybe changed)
   Indirect call(8870 (estimated locally),0.06 per call)  of param:0 loaded from aggregate passed by reference at offset 160 (vptr maybe changed)
altcp_proxyconnect_lower_poll.part.0/61 (altcp_proxyconnect_lower_poll.part.0) @071bd9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_proxyconnect_lower_poll/11 (46017 (estimated locally),0.21 per call) 
  Calls: 
   Indirect call(586155663 (estimated locally),0.55 per call)  of param:0 loaded from aggregate passed by reference at offset 256 (vptr maybe changed)
altcp_proxyconnect_lower_sent.part.0/60 (altcp_proxyconnect_lower_sent.part.0) @06fbd620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_proxyconnect_lower_sent/10 (24877 (estimated locally),0.11 per call) 
  Calls: 
   Indirect call(586155663 (estimated locally),0.55 per call)  of param:0 loaded from aggregate passed by reference at offset 224 (vptr maybe changed)
altcp_poll/59 (altcp_poll) @07244a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_set_poll.part.0/64 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
snprintf/58 (snprintf) @072447e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_format_request/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ip4addr_ntoa/57 (ip4addr_ntoa) @07244620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_send_request/7 (1004937957 (estimated locally),0.94 per call) 
  Calls: 
mem_malloc/56 (mem_malloc) @07244540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_send_request/7 (1014166876 (estimated locally),0.94 per call) 
  Calls: 
altcp_connect/55 (altcp_connect) @072442a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_connect/20 (1037171832 (estimated locally),0.97 per call) 
  Calls: 
altcp_write/54 (altcp_write) @0723dee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_send_request/7 (247063996 (estimated locally),0.23 per call) altcp_proxyconnect_write/24 (1041860204 (estimated locally),0.97 per call) 
  Calls: 
mem_free/53 (mem_free) @0723dd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_send_request/7 (954932204 (estimated locally),0.89 per call) altcp_proxyconnect_send_request/7 (50005753 (estimated locally),0.05 per call) altcp_proxyconnect_state_free/5 (123389 (estimated locally),0.53 per call) 
  Calls: 
altcp_default_get_port/52 (altcp_default_get_port) @0723da80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_get_ip/51 (altcp_default_get_ip) @0723d9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_get_tcp_addrinfo/50 (altcp_default_get_tcp_addrinfo) @0723d8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_setprio/49 (altcp_default_setprio) @0723d7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_nagle_disabled/48 (altcp_default_nagle_disabled) @0723d700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_nagle_enable/47 (altcp_default_nagle_enable) @0723d620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_nagle_disable/46 (altcp_default_nagle_disable) @0723d540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_sndqueuelen/45 (altcp_default_sndqueuelen) @0723d460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_sndbuf/44 (altcp_default_sndbuf) @0723d380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_mss/43 (altcp_default_mss) @0723d2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_output/42 (altcp_default_output) @0723d1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_shutdown/41 (altcp_default_shutdown) @0723d0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_default_bind/40 (altcp_default_bind) @0721fee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
altcp_tcp_new_ip_type/39 (altcp_tcp_new_ip_type) @0721fd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_new_tcp/16 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
altcp_recved/38 (altcp_recved) @0721fb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_recved/19 (352131534 (estimated locally),0.33 per call) altcp_proxyconnect_lower_recv.part.0/62 (16034 (estimated locally),0.10 per call) 
  Calls: 
pbuf_memfind/37 (pbuf_memfind) @0721fa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_lower_recv.part.0/62 (16034 (estimated locally),0.10 per call) 
  Calls: 
altcp_abort/36 (altcp_abort) @0721f9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_lower_recv.part.0/62 (69 (estimated locally),0.00 per call) altcp_proxyconnect_abort/22 (401890828 (estimated locally),0.37 per call) 
  Calls: 
altcp_close/35 (altcp_close) @0721f8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_new_tcp/16 (158200600 (estimated locally),0.15 per call) altcp_proxyconnect_lower_recv/9 (483 (estimated locally),0.00 per call) altcp_proxyconnect_lower_recv.part.0/62 (207 (estimated locally),0.00 per call) altcp_proxyconnect_lower_recv.part.0/62 (6872 (estimated locally),0.04 per call) altcp_proxyconnect_close/23 (748236991 (estimated locally),0.70 per call) 
  Calls: 
pbuf_free/34 (pbuf_free) @0721f7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_lower_recv/9 (258 (estimated locally),0.00 per call) altcp_proxyconnect_lower_recv.part.0/62 (111 (estimated locally),0.00 per call) altcp_proxyconnect_lower_recv.part.0/62 (3992 (estimated locally),0.03 per call) altcp_proxyconnect_lower_recv.part.0/62 (16034 (estimated locally),0.10 per call) 
  Calls: 
altcp_err/33 (altcp_err) @0721f2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_setup_callbacks/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
altcp_sent/32 (altcp_sent) @0721f1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_setup_callbacks/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
altcp_recv/31 (altcp_recv) @0721f0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_setup_callbacks/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
altcp_arg/30 (altcp_arg) @0721f000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_setup_callbacks/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mem_calloc/29 (mem_calloc) @0721be00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_state_alloc/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
altcp_free/28 (altcp_free) @0721bb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_new/15 (45570786 (estimated locally),0.04 per call) altcp_proxyconnect_abort/22 (751619278 (estimated locally),0.70 per call) altcp_proxyconnect_close/23 (814509410 (estimated locally),0.76 per call) altcp_proxyconnect_lower_err/12 (751619278 (estimated locally),0.70 per call) 
  Calls: 
altcp_alloc/27 (altcp_alloc) @0721ba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_proxyconnect_new/15 (907633963 (estimated locally),0.85 per call) 
  Calls: 
altcp_proxyconnect_functions/26 (altcp_proxyconnect_functions) @072192d0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: altcp_proxyconnect_set_poll/18 (addr)altcp_proxyconnect_recved/19 (addr)altcp_default_bind/40 (addr)altcp_proxyconnect_connect/20 (addr)altcp_proxyconnect_listen/21 (addr)altcp_proxyconnect_abort/22 (addr)altcp_proxyconnect_close/23 (addr)altcp_default_shutdown/41 (addr)altcp_proxyconnect_write/24 (addr)altcp_default_output/42 (addr)altcp_default_mss/43 (addr)altcp_default_sndbuf/44 (addr)altcp_default_sndqueuelen/45 (addr)altcp_default_nagle_disable/46 (addr)altcp_default_nagle_enable/47 (addr)altcp_default_nagle_disabled/48 (addr)altcp_default_setprio/49 (addr)altcp_proxyconnect_dealloc/25 (addr)altcp_default_get_tcp_addrinfo/50 (addr)altcp_default_get_ip/51 (addr)altcp_default_get_port/52 (addr)
  Referring: altcp_proxyconnect_setup/14 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
altcp_proxyconnect_dealloc/25 (altcp_proxyconnect_dealloc) @0721b460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_proxyconnect_state_free/5 (401890827 (estimated locally),0.37 per call) 
altcp_proxyconnect_write/24 (altcp_proxyconnect_write) @0721b1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_write/54 (1041860204 (estimated locally),0.97 per call) 
altcp_proxyconnect_close/23 (altcp_proxyconnect_close) @07213ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_free/28 (814509410 (estimated locally),0.76 per call) altcp_close/35 (748236991 (estimated locally),0.70 per call) 
altcp_proxyconnect_abort/22 (altcp_proxyconnect_abort) @07213c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_free/28 (751619278 (estimated locally),0.70 per call) altcp_abort/36 (401890828 (estimated locally),0.37 per call) 
altcp_proxyconnect_listen/21 (altcp_proxyconnect_listen) @072139a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_proxyconnect_connect/20 (altcp_proxyconnect_connect) @07213700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: altcp_proxyconnect_lower_connected/8 (addr)
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_connect/55 (1037171832 (estimated locally),0.97 per call) 
altcp_proxyconnect_recved/19 (altcp_proxyconnect_recved) @07213380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_recved/38 (352131534 (estimated locally),0.33 per call) 
altcp_proxyconnect_set_poll/18 (altcp_proxyconnect_set_poll) @072130e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_functions/26 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_proxyconnect_set_poll.part.0/64 (574129752 (estimated locally),0.53 per call) 
altcp_proxyconnect_alloc/17 (altcp_proxyconnect_alloc) @071f7c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_proxyconnect_new_tcp/16 (1073741824 (estimated locally),1.00 per call) 
altcp_proxyconnect_new_tcp/16 (altcp_proxyconnect_new_tcp) @071f7e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: altcp_proxyconnect_alloc/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: altcp_close/35 (158200600 (estimated locally),0.15 per call) altcp_proxyconnect_new/15 (907633963 (estimated locally),0.85 per call) altcp_tcp_new_ip_type/39 (1073741823 (estimated locally),1.00 per call) 
altcp_proxyconnect_new/15 (altcp_proxyconnect_new) @071f7b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: altcp_proxyconnect_new_tcp/16 (907633963 (estimated locally),0.85 per call) 
  Calls: altcp_free/28 (45570786 (estimated locally),0.04 per call) altcp_proxyconnect_setup/14 (485311880 (estimated locally),0.45 per call) altcp_alloc/27 (907633963 (estimated locally),0.85 per call) 
altcp_proxyconnect_setup/14 (altcp_proxyconnect_setup) @071f78c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: altcp_proxyconnect_functions/26 (addr)
  Referring: 
  Availability: local
  Function flags: count:231806 (estimated locally) body local optimize_size
  Called by: altcp_proxyconnect_new/15 (485311880 (estimated locally),0.45 per call) 
  Calls: altcp_proxyconnect_setup_callbacks/13 (122266 (estimated locally),0.53 per call) altcp_proxyconnect_state_alloc/4 (123389 (estimated locally),0.53 per call) 
altcp_proxyconnect_setup_callbacks/13 (altcp_proxyconnect_setup_callbacks) @071f7540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: altcp_proxyconnect_lower_recv/9 (addr)altcp_proxyconnect_lower_sent/10 (addr)altcp_proxyconnect_lower_err/12 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: altcp_proxyconnect_setup/14 (122266 (estimated locally),0.53 per call) 
  Calls: altcp_err/33 (1073741824 (estimated locally),1.00 per call) altcp_sent/32 (1073741824 (estimated locally),1.00 per call) altcp_recv/31 (1073741824 (estimated locally),1.00 per call) altcp_arg/30 (1073741824 (estimated locally),1.00 per call) 
altcp_proxyconnect_lower_err/12 (altcp_proxyconnect_lower_err) @071f72a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_setup_callbacks/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_free/28 (751619278 (estimated locally),0.70 per call) 
   Indirect call(526133494 (estimated locally),0.49 per call)  of param:0 loaded from aggregate passed by reference at offset 288 (vptr maybe changed)
altcp_proxyconnect_lower_poll/11 (altcp_proxyconnect_lower_poll) @071f7000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_set_poll.part.0/64 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_proxyconnect_lower_poll.part.0/61 (46017 (estimated locally),0.21 per call) 
altcp_proxyconnect_lower_sent/10 (altcp_proxyconnect_lower_sent) @071cad20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_setup_callbacks/13 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_proxyconnect_lower_sent.part.0/60 (24877 (estimated locally),0.11 per call) 
altcp_proxyconnect_lower_recv/9 (altcp_proxyconnect_lower_recv) @071caa80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_setup_callbacks/13 (addr)
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_proxyconnect_lower_recv.part.0/62 (106891 (estimated locally),0.50 per call) altcp_close/35 (483 (estimated locally),0.00 per call) pbuf_free/34 (258 (estimated locally),0.00 per call) 
altcp_proxyconnect_lower_connected/8 (altcp_proxyconnect_lower_connected) @071ca700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_proxyconnect_connect/20 (addr)
  Availability: available
  Function flags: count:156096 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_proxyconnect_lower_connected.part.0/63 (46017 (estimated locally),0.29 per call) 
altcp_proxyconnect_send_request/7 (altcp_proxyconnect_send_request) @071ca460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: altcp_proxyconnect_lower_connected.part.0/63 (372251086 (estimated locally),0.35 per call) 
  Calls: mem_free/53 (954932204 (estimated locally),0.89 per call) mem_free/53 (50005753 (estimated locally),0.05 per call) altcp_write/54 (247063996 (estimated locally),0.23 per call) altcp_proxyconnect_format_request/6 (1004937957 (estimated locally),0.94 per call) ip4addr_ntoa/57 (1004937957 (estimated locally),0.94 per call) mem_malloc/56 (1014166876 (estimated locally),0.94 per call) altcp_proxyconnect_format_request/6 (1063970774 (estimated locally),0.99 per call) 
altcp_proxyconnect_format_request/6 (altcp_proxyconnect_format_request) @071ca1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: altcp_proxyconnect_send_request/7 (1004937957 (estimated locally),0.94 per call) altcp_proxyconnect_send_request/7 (1063970774 (estimated locally),0.99 per call) 
  Calls: snprintf/58 (1073741824 (estimated locally),1.00 per call) 
altcp_proxyconnect_state_free/5 (altcp_proxyconnect_state_free) @071c2d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:230763 (estimated locally) body local optimize_size
  Called by: altcp_proxyconnect_dealloc/25 (401890827 (estimated locally),0.37 per call) 
  Calls: mem_free/53 (123389 (estimated locally),0.53 per call) 
altcp_proxyconnect_state_alloc/4 (altcp_proxyconnect_state_alloc) @071c2a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: altcp_proxyconnect_setup/14 (123389 (estimated locally),0.53 per call) 
  Calls: mem_calloc/29 (1073741824 (estimated locally),1.00 per call) 

;; Function altcp_proxyconnect_listen (altcp_proxyconnect_listen, funcdef_no=21, decl_uid=7564, cgraph_uid=22, symbol_order=21)

Modification phase of node altcp_proxyconnect_listen/21
altcp_proxyconnect_listen (struct altcp_pcb * conn, u8_t backlog, err_t * err)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0B;

}



;; Function altcp_proxyconnect_lower_err (altcp_proxyconnect_lower_err, funcdef_no=12, decl_uid=7516, cgraph_uid=13, symbol_order=12)

Modification phase of node altcp_proxyconnect_lower_err/12
altcp_proxyconnect_lower_err (void * arg, err_t err)
{
  void (*<T647>) (void *, err_t) _1;
  void * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_5(D)
  # DEBUG BEGIN_STMT
  if (arg_5(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  MEM[(struct altcp_pcb *)arg_5(D)].inner_conn = 0B;
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct altcp_pcb *)arg_5(D)].err;
  if (_1 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 526133494]:
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct altcp_pcb *)arg_5(D)].arg;
  _1 (_2, err_8(D));

  <bb 5> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  altcp_free (arg_5(D));

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function altcp_proxyconnect_close (altcp_proxyconnect_close, funcdef_no=23, decl_uid=7570, cgraph_uid=24, symbol_order=23)

Modification phase of node altcp_proxyconnect_close/23
altcp_proxyconnect_close (struct altcp_pcb * conn)
{
  err_t err;
  struct altcp_pcb * _1;
  err_t _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (conn_5(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  _1 = conn_5(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 748236991]:
  # DEBUG BEGIN_STMT
  err_8 = altcp_close (_1);
  # DEBUG err => err_8
  # DEBUG BEGIN_STMT
  if (err_8 != 0)
    goto <bb 6>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 814509410]:
  # DEBUG BEGIN_STMT
  altcp_free (conn_5(D));
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # _2 = PHI <-6(2), err_8(4), 0(5)>
  return _2;

}



;; Function altcp_proxyconnect_abort (altcp_proxyconnect_abort, funcdef_no=22, decl_uid=7567, cgraph_uid=23, symbol_order=22)

Modification phase of node altcp_proxyconnect_abort/22
altcp_proxyconnect_abort (struct altcp_pcb * conn)
{
  struct altcp_pcb * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (conn_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 401890828]:
  # DEBUG BEGIN_STMT
  altcp_abort (_1);

  <bb 5> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  altcp_free (conn_4(D));

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function altcp_proxyconnect_recved (altcp_proxyconnect_recved, funcdef_no=19, decl_uid=7551, cgraph_uid=20, symbol_order=19)

Modification phase of node altcp_proxyconnect_recved/19
altcp_proxyconnect_recved (struct altcp_pcb * conn, u16_t len)
{
  struct altcp_proxyconnect_state_t * state;
  unsigned char _1;
  struct altcp_pcb * _2;
  unsigned char _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  state_6 = conn_4(D)->state;
  # DEBUG state => state_6
  # DEBUG BEGIN_STMT
  if (state_6 == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 4> [local count: 720400030]:
  # DEBUG BEGIN_STMT
  _1 = state_6->flags;
  _9 = _1 & 2;
  if (_9 == 0)
    goto <bb 6>; [51.12%]
  else
    goto <bb 5>; [48.88%]

  <bb 5> [local count: 352131534]:
  # DEBUG BEGIN_STMT
  _2 = conn_4(D)->inner_conn;
  altcp_recved (_2, len_7(D));

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function altcp_proxyconnect_dealloc (altcp_proxyconnect_dealloc, funcdef_no=25, decl_uid=7581, cgraph_uid=26, symbol_order=25)

Modification phase of node altcp_proxyconnect_dealloc/25
altcp_proxyconnect_dealloc (struct altcp_pcb * conn)
{
  struct altcp_proxyconnect_state_t * state;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  if (conn_2(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619277]:
  # DEBUG BEGIN_STMT
  state_4 = conn_2(D)->state;
  # DEBUG state => state_4
  # DEBUG BEGIN_STMT
  if (state_4 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 401890827]:
  # DEBUG BEGIN_STMT
  altcp_proxyconnect_state_free (state_4);
  # DEBUG BEGIN_STMT
  conn_2(D)->state = 0B;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function altcp_proxyconnect_write (altcp_proxyconnect_write, funcdef_no=24, decl_uid=7577, cgraph_uid=25, symbol_order=24)

Modification phase of node altcp_proxyconnect_write/24
altcp_proxyconnect_write (struct altcp_pcb * conn, const void * dataptr, u16_t len, u8_t apiflags)
{
  struct altcp_proxyconnect_state_t * state;
  unsigned char _1;
  struct altcp_pcb * _2;
  err_t _3;
  err_t _12;
  unsigned char _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_5(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  state_7 = conn_5(D)->state;
  # DEBUG state => state_7
  # DEBUG BEGIN_STMT
  if (state_7 == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 1064099892]:
  # DEBUG BEGIN_STMT
  _1 = state_7->flags;
  _13 = _1 & 2;
  if (_13 == 0)
    goto <bb 6>; [2.09%]
  else
    goto <bb 5>; [97.91%]

  <bb 5> [local count: 1041860204]:
  # DEBUG BEGIN_STMT
  _2 = conn_5(D)->inner_conn;
  _12 = altcp_write (_2, dataptr_8(D), len_9(D), apiflags_10(D));

  <bb 6> [local count: 1073741824]:
  # _3 = PHI <-6(2), -15(3), -6(4), _12(5)>
  return _3;

}



;; Function altcp_proxyconnect_connect (altcp_proxyconnect_connect, funcdef_no=20, decl_uid=7558, cgraph_uid=21, symbol_order=20)

Modification phase of node altcp_proxyconnect_connect/20
altcp_proxyconnect_connect (struct altcp_pcb * conn, const struct ip_addr_t * ipaddr, u16_t port, err_t (*altcp_connected_fn) (void *, struct altcp_pcb *, err_t) connected)
{
  struct altcp_proxyconnect_state_t * state;
  unsigned char _1;
  unsigned char _2;
  long unsigned int _3;
  struct altcp_pcb * _4;
  struct altcp_proxyconnect_config * _5;
  struct ip_addr_t * _6;
  short unsigned int _7;
  err_t _8;
  err_t _21;
  unsigned char _22;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_10(D) == 0B)
    goto <bb 7>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  if (ipaddr_11(D) == 0B)
    goto <bb 7>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 1064099892]:
  # DEBUG BEGIN_STMT
  state_13 = conn_10(D)->state;
  # DEBUG state => state_13
  # DEBUG BEGIN_STMT
  if (state_13 == 0B)
    goto <bb 7>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 1059311441]:
  # DEBUG BEGIN_STMT
  _1 = state_13->flags;
  _22 = _1 & 1;
  if (_22 != 0)
    goto <bb 7>; [2.09%]
  else
    goto <bb 6>; [97.91%]

  <bb 6> [local count: 1037171832]:
  # DEBUG BEGIN_STMT
  _2 = _1 | 1;
  state_13->flags = _2;
  # DEBUG BEGIN_STMT
  conn_10(D)->connected = connected_15(D);
  # DEBUG BEGIN_STMT
  _3 = ipaddr_11(D)->addr;
  state_13->outer_addr.addr = _3;
  # DEBUG BEGIN_STMT
  state_13->outer_port = port_18(D);
  # DEBUG BEGIN_STMT
  _4 = conn_10(D)->inner_conn;
  _5 = state_13->conf;
  _6 = &_5->proxy_addr;
  _7 = _5->proxy_port;
  _21 = altcp_connect (_4, _6, _7, altcp_proxyconnect_lower_connected);

  <bb 7> [local count: 1073741824]:
  # _8 = PHI <-6(3), -6(4), -6(5), _21(6), -6(2)>
  return _8;

}



;; Function altcp_proxyconnect_lower_sent (altcp_proxyconnect_lower_sent, funcdef_no=10, decl_uid=7503, cgraph_uid=11, symbol_order=10)

Modification phase of node altcp_proxyconnect_lower_sent/10
altcp_proxyconnect_lower_sent (void * arg, struct altcp_pcb * inner_conn, u16_t len)
{
  struct altcp_proxyconnect_state_t * state;
  struct altcp_pcb * _1;
  unsigned char _2;
  signed char _3;
  err_t _6;
  unsigned char _9;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_8(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_8(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  state_11 = MEM[(struct altcp_pcb *)arg_8(D)].state;
  # DEBUG state => state_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct altcp_pcb *)arg_8(D)].inner_conn;
  if (_1 != inner_conn_12(D))
    goto <bb 9>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 9> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (state_11 == 0B)
    goto <bb 8>; [18.09%]
  else
    goto <bb 6>; [81.91%]

  <bb 6> [local count: 37693]:
  _2 = state_11->flags;
  _9 = _2 & 2;
  if (_9 == 0)
    goto <bb 8>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 7> [local count: 24877]:
  # DEBUG D#1 => inner_conn_12(D)
  _3 = altcp_proxyconnect_lower_sent.part.0 (arg_8(D), len_13(D));

  <bb 8> [local count: 111757]:
  # _6 = PHI <0(6), _3(7), 0(2), 0(5)>
  return _6;

}



;; Function altcp_proxyconnect_lower_poll (altcp_proxyconnect_lower_poll, funcdef_no=11, decl_uid=7510, cgraph_uid=12, symbol_order=11)

Modification phase of node altcp_proxyconnect_lower_poll/11
altcp_proxyconnect_lower_poll (void * arg, struct altcp_pcb * inner_conn)
{
  struct altcp_pcb * _1;
  signed char _2;
  err_t _3;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_5(D)
  # DEBUG BEGIN_STMT
  if (arg_5(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct altcp_pcb *)arg_5(D)].inner_conn;
  if (_1 != inner_conn_8(D))
    goto <bb 7>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG D#3 => inner_conn_8(D)
  _2 = altcp_proxyconnect_lower_poll.part.0 (arg_5(D));

  <bb 6> [local count: 111757]:
  # _3 = PHI <_2(5), 0(2)>
  return _3;

}



;; Function altcp_proxyconnect_lower_recv (altcp_proxyconnect_lower_recv, funcdef_no=9, decl_uid=7493, cgraph_uid=10, symbol_order=9)

Modification phase of node altcp_proxyconnect_lower_recv/9
altcp_proxyconnect_lower_recv (void * arg, struct altcp_pcb * inner_conn, struct pbuf * p, err_t err)
{
  signed char _1;
  err_t _4;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_7(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_8(D) != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 10> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_7(D) == 0B)
    goto <bb 5>; [0.45%]
  else
    goto <bb 8>; [99.55%]

  <bb 5> [local count: 483]:
  # DEBUG BEGIN_STMT
  if (p_11(D) != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 6> [local count: 258]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_11(D));

  <bb 7> [local count: 483]:
  # DEBUG BEGIN_STMT
  altcp_close (inner_conn_10(D));
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 106891]:
  # DEBUG D#5 => err_8(D)
  _1 = altcp_proxyconnect_lower_recv.part.0 (arg_7(D), inner_conn_10(D), p_11(D));

  <bb 9> [local count: 32550]:
  # _4 = PHI <-15(7), _1(8)>
  return _4;

}



;; Function altcp_proxyconnect_set_poll (altcp_proxyconnect_set_poll, funcdef_no=18, decl_uid=7547, cgraph_uid=19, symbol_order=18)

Modification phase of node altcp_proxyconnect_set_poll/18
altcp_proxyconnect_set_poll (struct altcp_pcb * conn, u8_t interval)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (conn_1(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129752]:
  altcp_proxyconnect_set_poll.part.0 (conn_1(D), interval_3(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function altcp_proxyconnect_lower_connected (altcp_proxyconnect_lower_connected, funcdef_no=8, decl_uid=7485, cgraph_uid=9, symbol_order=8)

Modification phase of node altcp_proxyconnect_lower_connected/8
altcp_proxyconnect_lower_connected (void * arg, struct altcp_pcb * inner_conn, err_t err)
{
  void * _1;
  struct altcp_pcb * _2;
  signed char _3;
  err_t _4;

  <bb 2> [local count: 156096]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_6(D)
  # DEBUG BEGIN_STMT
  if (arg_6(D) != 0B)
    goto <bb 3>; [99.13%]
  else
    goto <bb 7>; [0.87%]

  <bb 3> [local count: 154738]:
  _1 = MEM[(struct altcp_pcb *)arg_6(D)].state;
  if (_1 != 0B)
    goto <bb 4>; [99.13%]
  else
    goto <bb 7>; [0.87%]

  <bb 4> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct altcp_pcb *)arg_6(D)].inner_conn;
  if (_2 != inner_conn_9(D))
    goto <bb 8>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 8> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 46017]:
  # DEBUG D#7 => inner_conn_9(D)
  _3 = altcp_proxyconnect_lower_connected.part.0 (arg_6(D), err_10(D));

  <bb 7> [local count: 48722]:
  # _4 = PHI <_3(6), -6(2), -6(3)>
  return _4;

}



;; Function altcp_proxyconnect_new (altcp_proxyconnect_new, funcdef_no=15, decl_uid=6431, cgraph_uid=16, symbol_order=15)

Modification phase of node altcp_proxyconnect_new/15
altcp_proxyconnect_new (struct altcp_proxyconnect_config * config, struct altcp_pcb * inner_pcb)
{
  struct altcp_pcb * ret;
  signed char _1;
  struct altcp_pcb * _2;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (inner_pcb_4(D) == 0B)
    goto <bb 6>; [15.47%]
  else
    goto <bb 3>; [84.53%]

  <bb 3> [local count: 907633963]:
  # DEBUG BEGIN_STMT
  ret_7 = altcp_alloc ();
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  if (ret_7 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 4> [local count: 485311880]:
  # DEBUG BEGIN_STMT
  _1 = altcp_proxyconnect_setup (config_8(D), ret_7, inner_pcb_4(D));
  if (_1 != 0)
    goto <bb 5>; [9.39%]
  else
    goto <bb 6>; [90.61%]

  <bb 5> [local count: 45570786]:
  # DEBUG BEGIN_STMT
  altcp_free (ret_7);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # _2 = PHI <0B(2), 0B(5), ret_7(4), ret_7(3)>
  return _2;

}



;; Function altcp_proxyconnect_new_tcp (altcp_proxyconnect_new_tcp, funcdef_no=16, decl_uid=6434, cgraph_uid=17, symbol_order=16)

Modification phase of node altcp_proxyconnect_new_tcp/16
altcp_proxyconnect_new_tcp (struct altcp_proxyconnect_config * config, u8_t ip_type)
{
  struct altcp_pcb * ret;
  struct altcp_pcb * inner_pcb;
  struct altcp_pcb * _1;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  inner_pcb_6 = altcp_tcp_new_ip_type (ip_type_4(D));
  # DEBUG inner_pcb => inner_pcb_6
  # DEBUG BEGIN_STMT
  if (inner_pcb_6 == 0B)
    goto <bb 5>; [15.47%]
  else
    goto <bb 3>; [84.53%]

  <bb 3> [local count: 907633963]:
  # DEBUG BEGIN_STMT
  ret_9 = altcp_proxyconnect_new (config_7(D), inner_pcb_6);
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  if (ret_9 == 0B)
    goto <bb 4>; [17.43%]
  else
    goto <bb 5>; [82.57%]

  <bb 4> [local count: 158200600]:
  # DEBUG BEGIN_STMT
  altcp_close (inner_pcb_6);

  <bb 5> [local count: 1073741824]:
  # _1 = PHI <0B(2), ret_9(4), ret_9(3)>
  return _1;

}



;; Function altcp_proxyconnect_alloc (altcp_proxyconnect_alloc, funcdef_no=17, decl_uid=6437, cgraph_uid=18, symbol_order=17)

Modification phase of node altcp_proxyconnect_alloc/17
altcp_proxyconnect_alloc (void * arg, u8_t ip_type)
{
  struct altcp_pcb * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = altcp_proxyconnect_new_tcp (arg_2(D), ip_type_3(D));
  return _5;

}


