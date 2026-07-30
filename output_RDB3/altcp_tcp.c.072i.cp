
IPA constant propagation start:
Determining dynamic type for call: altcp_tcp_remove_callbacks (pcb_2);
  Starting walk at: altcp_tcp_remove_callbacks (pcb_2);
  instance pointer: pcb_2  Outer instance pointer: pcb_2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: altcp_tcp_setup_callbacks (conn_1(D), pcb_2);
  Starting walk at: altcp_tcp_setup_callbacks (conn_1(D), pcb_2);
  instance pointer: conn_1(D)  Outer instance pointer: conn_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_4 = tcp_close (pcb_2);
  Function call may change dynamic type:altcp_tcp_remove_callbacks (pcb_2);
Determining dynamic type for call: altcp_tcp_setup_callbacks (conn_1(D), pcb_2);
  Starting walk at: altcp_tcp_setup_callbacks (conn_1(D), pcb_2);
  instance pointer: pcb_2  Outer instance pointer: pcb_2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_4 = tcp_close (pcb_2);
  Function call may change dynamic type:altcp_tcp_remove_callbacks (pcb_2);
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
Determining dynamic type for call: _5 = _2 (_3, arg_1(D), err_4(D));
  Starting walk at: _5 = _2 (_3, arg_1(D), err_4(D));
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = _2 (_3, arg_1(D), err_4(D));
  Starting walk at: _5 = _2 (_3, arg_1(D), err_4(D));
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = altcp_tcp_sndbuf.part.0 (conn_6(D));
  Starting walk at: _4 = altcp_tcp_sndbuf.part.0 (conn_6(D));
  instance pointer: conn_6(D)  Outer instance pointer: conn_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = altcp_tcp_output.part.0 (conn_4(D));
  Starting walk at: _7 = altcp_tcp_output.part.0 (conn_4(D));
  instance pointer: conn_4(D)  Outer instance pointer: conn_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = altcp_tcp_write.part.0 (conn_4(D), dataptr_6(D), len_7(D), apiflags_8(D));
  Starting walk at: _10 = altcp_tcp_write.part.0 (conn_4(D), dataptr_6(D), len_7(D), apiflags_8(D));
  instance pointer: conn_4(D)  Outer instance pointer: conn_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = altcp_tcp_write.part.0 (conn_4(D), dataptr_6(D), len_7(D), apiflags_8(D));
  Starting walk at: _10 = altcp_tcp_write.part.0 (conn_4(D), dataptr_6(D), len_7(D), apiflags_8(D));
  instance pointer: dataptr_6(D)  Outer instance pointer: dataptr_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = altcp_tcp_shutdown.part.0 (conn_4(D), shut_rx_6(D), shut_tx_7(D));
  Starting walk at: _9 = altcp_tcp_shutdown.part.0 (conn_4(D), shut_rx_6(D), shut_tx_7(D));
  instance pointer: conn_4(D)  Outer instance pointer: conn_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = altcp_tcp_close.part.0 (conn_4(D));
  Starting walk at: _6 = altcp_tcp_close.part.0 (conn_4(D));
  instance pointer: conn_4(D)  Outer instance pointer: conn_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = altcp_tcp_listen.part.0 (conn_4(D), backlog_6(D), err_7(D));
  Starting walk at: _8 = altcp_tcp_listen.part.0 (conn_4(D), backlog_6(D), err_7(D));
  instance pointer: conn_4(D)  Outer instance pointer: conn_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = altcp_tcp_listen.part.0 (conn_4(D), backlog_6(D), err_7(D));
  Starting walk at: _8 = altcp_tcp_listen.part.0 (conn_4(D), backlog_6(D), err_7(D));
  instance pointer: err_7(D)  Outer instance pointer: err_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = altcp_tcp_connect.part.0 (conn_4(D), ipaddr_7(D), port_8(D), connected_6(D));
  Starting walk at: _10 = altcp_tcp_connect.part.0 (conn_4(D), ipaddr_7(D), port_8(D), connected_6(D));
  instance pointer: conn_4(D)  Outer instance pointer: conn_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = altcp_tcp_connect.part.0 (conn_4(D), ipaddr_7(D), port_8(D), connected_6(D));
  Starting walk at: _10 = altcp_tcp_connect.part.0 (conn_4(D), ipaddr_7(D), port_8(D), connected_6(D));
  instance pointer: ipaddr_7(D)  Outer instance pointer: ipaddr_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = altcp_tcp_connect.part.0 (conn_4(D), ipaddr_7(D), port_8(D), connected_6(D));
  Starting walk at: _10 = altcp_tcp_connect.part.0 (conn_4(D), ipaddr_7(D), port_8(D), connected_6(D));
  instance pointer: connected_6(D)  Outer instance pointer: connected_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = altcp_tcp_bind.part.0 (conn_4(D), ipaddr_6(D), port_7(D));
  Starting walk at: _9 = altcp_tcp_bind.part.0 (conn_4(D), ipaddr_6(D), port_7(D));
  instance pointer: conn_4(D)  Outer instance pointer: conn_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = altcp_tcp_bind.part.0 (conn_4(D), ipaddr_6(D), port_7(D));
  Starting walk at: _9 = altcp_tcp_bind.part.0 (conn_4(D), ipaddr_6(D), port_7(D));
  instance pointer: ipaddr_6(D)  Outer instance pointer: ipaddr_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: altcp_tcp_setup (ret_6, tpcb_3(D));
  Starting walk at: altcp_tcp_setup (ret_6, tpcb_3(D));
  instance pointer: ret_6  Outer instance pointer: ret_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_6 = altcp_alloc ();
Determining dynamic type for call: altcp_tcp_setup (ret_6, tpcb_3(D));
  Starting walk at: altcp_tcp_setup (ret_6, tpcb_3(D));
  instance pointer: tpcb_3(D)  Outer instance pointer: tpcb_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_6 = altcp_alloc ();
Determining dynamic type for call: altcp_tcp_setup (ret_8, tpcb_6);
  Starting walk at: altcp_tcp_setup (ret_8, tpcb_6);
  instance pointer: ret_8  Outer instance pointer: ret_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_8 = altcp_alloc ();
  Function call may change dynamic type:tpcb_6 = tcp_new_ip_type (ip_type_4(D));
Determining dynamic type for call: altcp_tcp_setup (ret_8, tpcb_6);
  Starting walk at: altcp_tcp_setup (ret_8, tpcb_6);
  instance pointer: tpcb_6  Outer instance pointer: tpcb_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_8 = altcp_alloc ();
  Function call may change dynamic type:tpcb_6 = tcp_new_ip_type (ip_type_4(D));
Determining dynamic type for call: altcp_tcp_setup_callbacks (conn_2(D), tpcb_3(D));
  Starting walk at: altcp_tcp_setup_callbacks (conn_2(D), tpcb_3(D));
  instance pointer: conn_2(D)  Outer instance pointer: conn_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: altcp_tcp_setup_callbacks (conn_2(D), tpcb_3(D));
  Starting walk at: altcp_tcp_setup_callbacks (conn_2(D), tpcb_3(D));
  instance pointer: tpcb_3(D)  Outer instance pointer: tpcb_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: altcp_tcp_setup_callbacks.part.0 (tpcb_3(D));
  Starting walk at: altcp_tcp_setup_callbacks.part.0 (tpcb_3(D));
  instance pointer: tpcb_3(D)  Outer instance pointer: tpcb_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_arg (tpcb_3(D), conn_4(D));
Determining dynamic type for call: _1 (_2, err_8(D));
  Starting walk at: _1 (_2, err_8(D));
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = altcp_tcp_poll.part.0 (arg_7(D));
  Starting walk at: _3 = altcp_tcp_poll.part.0 (arg_7(D));
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = altcp_tcp_sent.part.0 (arg_7(D), len_11(D));
  Starting walk at: _3 = altcp_tcp_sent.part.0 (arg_7(D), len_11(D));
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _17 = _3 (_5, arg_10(D), p_14(D), err_15(D));
  Starting walk at: _17 = _3 (_5, arg_10(D), p_14(D), err_15(D));
  instance pointer: _5  Outer instance pointer: _5 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _17 = _3 (_5, arg_10(D), p_14(D), err_15(D));
  Starting walk at: _17 = _3 (_5, arg_10(D), p_14(D), err_15(D));
  instance pointer: arg_10(D)  Outer instance pointer: arg_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _17 = _3 (_5, arg_10(D), p_14(D), err_15(D));
  Starting walk at: _17 = _3 (_5, arg_10(D), p_14(D), err_15(D));
  instance pointer: p_14(D)  Outer instance pointer: p_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = altcp_tcp_recv.part.0 (p_14(D));
  Starting walk at: _9 = altcp_tcp_recv.part.0 (p_14(D));
  instance pointer: p_14(D)  Outer instance pointer: p_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = altcp_tcp_connected.part.0 (arg_7(D), err_11(D));
  Starting walk at: _3 = altcp_tcp_connected.part.0 (arg_7(D), err_11(D));
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _14 = _2 (_3, new_conn_9, err_12(D));
  Starting walk at: _14 = _2 (_3, new_conn_9, err_12(D));
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:altcp_tcp_setup (new_conn_9, new_tpcb_10(D));
  Function call may change dynamic type:new_conn_9 = altcp_alloc ();
Determining dynamic type for call: _14 = _2 (_3, new_conn_9, err_12(D));
  Starting walk at: _14 = _2 (_3, new_conn_9, err_12(D));
  instance pointer: new_conn_9  Outer instance pointer: new_conn_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:altcp_tcp_setup (new_conn_9, new_tpcb_10(D));
  Function call may change dynamic type:new_conn_9 = altcp_alloc ();
Determining dynamic type for call: altcp_tcp_setup (new_conn_9, new_tpcb_10(D));
  Starting walk at: altcp_tcp_setup (new_conn_9, new_tpcb_10(D));
  instance pointer: new_conn_9  Outer instance pointer: new_conn_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:new_conn_9 = altcp_alloc ();
Determining dynamic type for call: altcp_tcp_setup (new_conn_9, new_tpcb_10(D));
  Starting walk at: altcp_tcp_setup (new_conn_9, new_tpcb_10(D));
  instance pointer: new_tpcb_10(D)  Outer instance pointer: new_tpcb_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:new_conn_9 = altcp_alloc ();

IPA structures before propagation:

Jump functions:
  Jump functions of caller  altcp_tcp_bind.part.0/68:
  Jump functions of caller  altcp_tcp_connect.part.0/67:
  Jump functions of caller  altcp_tcp_listen.part.0/66:
  Jump functions of caller  altcp_tcp_close.part.0/65:
    callsite  altcp_tcp_close.part.0/65 -> altcp_tcp_remove_callbacks/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  altcp_tcp_close.part.0/65 -> altcp_tcp_setup_callbacks/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_shutdown.part.0/64:
  Jump functions of caller  altcp_tcp_write.part.0/63:
  Jump functions of caller  altcp_tcp_output.part.0/62:
  Jump functions of caller  altcp_tcp_recv.part.0/61:
  Jump functions of caller  altcp_tcp_setup_callbacks.part.0/60:
  Jump functions of caller  altcp_tcp_sndbuf.part.0/59:
  Jump functions of caller  altcp_tcp_poll.part.0/58:
    indirect aggregate callsite, calling param 0, offset 256, by reference, for stmt _4 = _2 (_3, arg_1(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_sent.part.0/57:
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
  Jump functions of caller  altcp_tcp_connected.part.0/56:
    indirect aggregate callsite, calling param 0, offset 160, by reference, for stmt _5 = _2 (_3, arg_1(D), err_4(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  tcp_recved/55:
  Jump functions of caller  tcp_bind/54:
  Jump functions of caller  tcp_connect/53:
  Jump functions of caller  tcp_accept/52:
  Jump functions of caller  tcp_listen_with_backlog_and_err/51:
  Jump functions of caller  tcp_abort/50:
  Jump functions of caller  tcp_poll/49:
  Jump functions of caller  tcp_shutdown/48:
  Jump functions of caller  tcp_write/47:
  Jump functions of caller  tcp_output/46:
  Jump functions of caller  tcp_setprio/45:
  Jump functions of caller  tcp_tcp_get_tcp_addrinfo/44:
  Jump functions of caller  pbuf_free/43:
  Jump functions of caller  altcp_free/42:
  Jump functions of caller  tcp_err/41:
  Jump functions of caller  tcp_sent/40:
  Jump functions of caller  tcp_recv/39:
  Jump functions of caller  tcp_arg/38:
  Jump functions of caller  tcp_close/37:
  Jump functions of caller  altcp_alloc/36:
  Jump functions of caller  tcp_new_ip_type/35:
  Jump functions of caller  altcp_tcp_get_port/33:
  Jump functions of caller  altcp_tcp_get_ip/32:
  Jump functions of caller  altcp_tcp_get_tcp_addrinfo/31:
  Jump functions of caller  altcp_tcp_dealloc/30:
  Jump functions of caller  altcp_tcp_setprio/29:
  Jump functions of caller  altcp_tcp_nagle_disabled/28:
  Jump functions of caller  altcp_tcp_nagle_enable/27:
  Jump functions of caller  altcp_tcp_nagle_disable/26:
  Jump functions of caller  altcp_tcp_sndqueuelen/25:
  Jump functions of caller  altcp_tcp_sndbuf/24:
    callsite  altcp_tcp_sndbuf/24 -> altcp_tcp_sndbuf.part.0/59 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_mss/23:
  Jump functions of caller  altcp_tcp_output/22:
    callsite  altcp_tcp_output/22 -> altcp_tcp_output.part.0/62 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_write/21:
    callsite  altcp_tcp_write/21 -> altcp_tcp_write.part.0/63 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  altcp_tcp_shutdown/20:
    callsite  altcp_tcp_shutdown/20 -> altcp_tcp_shutdown.part.0/64 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_close/19:
    callsite  altcp_tcp_close/19 -> altcp_tcp_close.part.0/65 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_abort/18:
  Jump functions of caller  altcp_tcp_listen/17:
    callsite  altcp_tcp_listen/17 -> altcp_tcp_listen.part.0/66 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_connect/16:
    callsite  altcp_tcp_connect/16 -> altcp_tcp_connect.part.0/67 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_bind/15:
    callsite  altcp_tcp_bind/15 -> altcp_tcp_bind.part.0/68 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  altcp_tcp_recved/14:
  Jump functions of caller  altcp_tcp_set_poll/13:
  Jump functions of caller  altcp_tcp_wrap/12:
    callsite  altcp_tcp_wrap/12 -> altcp_tcp_setup/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_alloc/11:
    callsite  altcp_tcp_alloc/11 -> altcp_tcp_new_ip_type/10 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  altcp_tcp_new_ip_type/10:
    callsite  altcp_tcp_new_ip_type/10 -> altcp_tcp_setup/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_setup/9:
    callsite  altcp_tcp_setup/9 -> altcp_tcp_setup_callbacks/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_setup_callbacks/8:
    callsite  altcp_tcp_setup_callbacks/8 -> altcp_tcp_setup_callbacks.part.0/60 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_remove_callbacks/7:
  Jump functions of caller  altcp_tcp_err/6:
    indirect aggregate callsite, calling param 0, offset 288, by reference, for stmt _1 (_2, err_8(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_poll/5:
    callsite  altcp_tcp_poll/5 -> altcp_tcp_poll.part.0/58 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_sent/4:
    callsite  altcp_tcp_sent/4 -> altcp_tcp_sent.part.0/57 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  altcp_tcp_recv/3:
    callsite  altcp_tcp_recv/3 -> altcp_tcp_recv.part.0/61 : 
       param 0: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 192, by reference, for stmt _17 = _3 (_5, arg_10(D), p_14(D), err_15(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_connected/2:
    callsite  altcp_tcp_connected/2 -> altcp_tcp_connected.part.0/56 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  altcp_tcp_accept/1:
    callsite  altcp_tcp_accept/1 -> altcp_tcp_setup/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 128, by reference, for stmt _14 = _2 (_3, new_conn_9, err_12(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR

 Propagating constants:

Not considering altcp_tcp_get_port for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_get_ip for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_get_tcp_addrinfo for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_dealloc for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_setprio for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_nagle_disabled for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_nagle_enable for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_nagle_disable for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_sndqueuelen for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_sndbuf for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_mss for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_output for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_write for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_shutdown for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_close for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_abort for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_listen for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_connect for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_bind for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_recved for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_set_poll for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_wrap for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_alloc for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_new_ip_type for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_err for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_poll for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_sent for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_recv for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_connected for cloning; -fipa-cp-clone disabled.
Not considering altcp_tcp_accept for cloning; -fipa-cp-clone disabled.

overall_size: 660, max_new_size: 11001
 - context independent values, size: 6, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: altcp_tcp_bind.part.0/68:
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
  Node: altcp_tcp_connect.part.0/67:
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
  Node: altcp_tcp_listen.part.0/66:
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
  Node: altcp_tcp_close.part.0/65:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_tcp_shutdown.part.0/64:
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
  Node: altcp_tcp_write.part.0/63:
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
  Node: altcp_tcp_output.part.0/62:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_tcp_recv.part.0/61:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_tcp_setup_callbacks.part.0/60:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_tcp_sndbuf.part.0/59:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_tcp_poll.part.0/58:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_tcp_sent.part.0/57:
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
  Node: altcp_tcp_connected.part.0/56:
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
  Node: altcp_tcp_get_port/33:
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
  Node: altcp_tcp_get_ip/32:
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
  Node: altcp_tcp_get_tcp_addrinfo/31:
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
  Node: altcp_tcp_dealloc/30:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_setprio/29:
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
  Node: altcp_tcp_nagle_disabled/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_nagle_enable/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_nagle_disable/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_sndqueuelen/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_sndbuf/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_mss/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_output/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_write/21:
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
  Node: altcp_tcp_shutdown/20:
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
  Node: altcp_tcp_close/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_abort/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_listen/17:
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
  Node: altcp_tcp_connect/16:
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
  Node: altcp_tcp_bind/15:
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
  Node: altcp_tcp_recved/14:
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
  Node: altcp_tcp_set_poll/13:
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
  Node: altcp_tcp_wrap/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_alloc/11:
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
  Node: altcp_tcp_new_ip_type/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: altcp_tcp_setup/9:
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
  Node: altcp_tcp_setup_callbacks/8:
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
  Node: altcp_tcp_remove_callbacks/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: altcp_tcp_err/6:
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
  Node: altcp_tcp_poll/5:
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
  Node: altcp_tcp_sent/4:
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
  Node: altcp_tcp_recv/3:
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
  Node: altcp_tcp_connected/2:
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
  Node: altcp_tcp_accept/1:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

altcp_tcp_bind.part.0/68 (altcp_tcp_bind.part.0) @073ac000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_bind/15 (22666 (estimated locally),0.17 per call) 
  Calls: tcp_bind/54 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_connect.part.0/67 (altcp_tcp_connect.part.0) @073aca80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: altcp_tcp_connected/2 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_connect/16 (22666 (estimated locally),0.17 per call) 
  Calls: tcp_connect/53 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_listen.part.0/66 (altcp_tcp_listen.part.0) @073ac540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: altcp_tcp_accept/1 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_listen/17 (22666 (estimated locally),0.16 per call) 
  Calls: tcp_listen_with_backlog_and_err/51 (1073741824 (estimated locally),1.00 per call) tcp_accept/52 (635440412 (estimated locally),0.59 per call) 
altcp_tcp_close.part.0/65 (altcp_tcp_close.part.0) @0739eee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_close/19 (46017 (estimated locally),0.30 per call) 
  Calls: altcp_tcp_remove_callbacks/7 (751619277 (estimated locally),0.70 per call) tcp_close/37 (751619277 (estimated locally),0.70 per call) altcp_tcp_setup_callbacks/8 (152127742 (estimated locally),0.14 per call) tcp_poll/49 (152127742 (estimated locally),0.14 per call) altcp_free/42 (921614082 (estimated locally),0.86 per call) 
altcp_tcp_shutdown.part.0/64 (altcp_tcp_shutdown.part.0) @0739e8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_shutdown/20 (22666 (estimated locally),0.17 per call) 
  Calls: tcp_shutdown/48 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_write.part.0/63 (altcp_tcp_write.part.0) @0739e380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_write/21 (22666 (estimated locally),0.17 per call) 
  Calls: tcp_write/47 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_output.part.0/62 (altcp_tcp_output.part.0) @072dfb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_output/22 (22666 (estimated locally),0.17 per call) 
  Calls: tcp_output/46 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_recv.part.0/61 (altcp_tcp_recv.part.0) @072dfa80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_recv/3 (72008 (estimated locally),0.33 per call) 
  Calls: pbuf_free/43 (574129754 (estimated locally),0.53 per call) 
altcp_tcp_setup_callbacks.part.0/60 (altcp_tcp_setup_callbacks.part.0) @072df620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: altcp_tcp_recv/3 (addr)altcp_tcp_sent/4 (addr)altcp_tcp_err/6 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_setup_callbacks/8 (524845000 (estimated locally),0.49 per call) 
  Calls: tcp_recv/39 (1073741824 (estimated locally),1.00 per call) tcp_sent/40 (1073741824 (estimated locally),1.00 per call) tcp_err/41 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_sndbuf.part.0/59 (altcp_tcp_sndbuf.part.0) @072df0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_sndbuf/24 (46017 (estimated locally),0.25 per call) 
  Calls: 
altcp_tcp_poll.part.0/58 (altcp_tcp_poll.part.0) @072a1b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_poll/5 (13805 (estimated locally),0.06 per call) 
  Calls: 
   Indirect call(586155663 (estimated locally),0.55 per call)  of param:0 loaded from aggregate passed by reference at offset 256 (vptr maybe changed)
altcp_tcp_sent.part.0/57 (altcp_tcp_sent.part.0) @072a2ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_sent/4 (13805 (estimated locally),0.06 per call) 
  Calls: 
   Indirect call(586155663 (estimated locally),0.55 per call)  of param:0 loaded from aggregate passed by reference at offset 224 (vptr maybe changed)
altcp_tcp_connected.part.0/56 (altcp_tcp_connected.part.0) @06f69620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: altcp_tcp_connected/2 (13805 (estimated locally),0.06 per call) 
  Calls: 
   Indirect call(586155663 (estimated locally),0.55 per call)  of param:0 loaded from aggregate passed by reference at offset 160 (vptr maybe changed)
tcp_recved/55 (tcp_recved) @07279ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_recved/14 (22666 (estimated locally),0.12 per call) 
  Calls: 
tcp_bind/54 (tcp_bind) @07279d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_bind.part.0/68 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_connect/53 (tcp_connect) @07279a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_connect.part.0/67 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_accept/52 (tcp_accept) @072797e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_listen.part.0/66 (635440412 (estimated locally),0.59 per call) 
  Calls: 
tcp_listen_with_backlog_and_err/51 (tcp_listen_with_backlog_and_err) @07279700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_listen.part.0/66 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_abort/50 (tcp_abort) @07279540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_abort/18 (24606 (estimated locally),0.11 per call) 
  Calls: 
tcp_poll/49 (tcp_poll) @072792a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_set_poll/13 (22666 (estimated locally),0.12 per call) altcp_tcp_close.part.0/65 (152127742 (estimated locally),0.14 per call) altcp_tcp_remove_callbacks/7 (524845004 (estimated locally),0.49 per call) 
  Calls: 
tcp_shutdown/48 (tcp_shutdown) @072790e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_shutdown.part.0/64 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_write/47 (tcp_write) @072680e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_write.part.0/63 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_output/46 (tcp_output) @07268e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_output.part.0/62 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_setprio/45 (tcp_setprio) @07268700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_setprio/29 (22666 (estimated locally),0.12 per call) 
  Calls: 
tcp_tcp_get_tcp_addrinfo/44 (tcp_tcp_get_tcp_addrinfo) @07268460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_get_tcp_addrinfo/31 (11679 (estimated locally),0.10 per call) 
  Calls: 
pbuf_free/43 (pbuf_free) @0722ce00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_recv.part.0/61 (574129754 (estimated locally),0.53 per call) 
  Calls: 
altcp_free/42 (altcp_free) @0722cb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_close.part.0/65 (921614082 (estimated locally),0.86 per call) altcp_tcp_err/6 (751619278 (estimated locally),0.70 per call) 
  Calls: 
tcp_err/41 (tcp_err) @0722c9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_remove_callbacks/7 (524845004 (estimated locally),0.49 per call) altcp_tcp_setup_callbacks.part.0/60 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_sent/40 (tcp_sent) @0722c8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_remove_callbacks/7 (524845004 (estimated locally),0.49 per call) altcp_tcp_setup_callbacks.part.0/60 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_recv/39 (tcp_recv) @0722c7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_remove_callbacks/7 (524845004 (estimated locally),0.49 per call) altcp_tcp_setup_callbacks.part.0/60 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_arg/38 (tcp_arg) @0722c700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_remove_callbacks/7 (1073741824 (estimated locally),1.00 per call) altcp_tcp_setup_callbacks/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_close/37 (tcp_close) @0722c460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_new_ip_type/10 (200903624 (estimated locally),0.19 per call) altcp_tcp_close.part.0/65 (751619277 (estimated locally),0.70 per call) 
  Calls: 
altcp_alloc/36 (altcp_alloc) @0722c380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_wrap/12 (792206719 (estimated locally),0.74 per call) altcp_tcp_new_ip_type/10 (792206719 (estimated locally),0.74 per call) altcp_tcp_accept/1 (1045879706 (estimated locally),0.97 per call) 
  Calls: 
tcp_new_ip_type/35 (tcp_new_ip_type) @0722c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: altcp_tcp_new_ip_type/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
altcp_tcp_functions/34 (altcp_tcp_functions) @0722a048
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: altcp_tcp_set_poll/13 (addr)altcp_tcp_recved/14 (addr)altcp_tcp_bind/15 (addr)altcp_tcp_connect/16 (addr)altcp_tcp_listen/17 (addr)altcp_tcp_abort/18 (addr)altcp_tcp_close/19 (addr)altcp_tcp_shutdown/20 (addr)altcp_tcp_write/21 (addr)altcp_tcp_output/22 (addr)altcp_tcp_mss/23 (addr)altcp_tcp_sndbuf/24 (addr)altcp_tcp_sndqueuelen/25 (addr)altcp_tcp_nagle_disable/26 (addr)altcp_tcp_nagle_enable/27 (addr)altcp_tcp_nagle_disabled/28 (addr)altcp_tcp_setprio/29 (addr)altcp_tcp_dealloc/30 (addr)altcp_tcp_get_tcp_addrinfo/31 (addr)altcp_tcp_get_ip/32 (addr)altcp_tcp_get_port/33 (addr)
  Referring: altcp_tcp_setup/9 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
altcp_tcp_get_port/33 (altcp_tcp_get_port) @07225c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_tcp_get_ip/32 (altcp_tcp_get_ip) @072259a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:180248 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_tcp_get_tcp_addrinfo/31 (altcp_tcp_get_tcp_addrinfo) @07225700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:120098 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_tcp_get_tcp_addrinfo/44 (11679 (estimated locally),0.10 per call) 
altcp_tcp_dealloc/30 (altcp_tcp_dealloc) @07225460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:153391 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_tcp_setprio/29 (altcp_tcp_setprio) @072251c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:185771 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_setprio/45 (22666 (estimated locally),0.12 per call) 
altcp_tcp_nagle_disabled/28 (altcp_tcp_nagle_disabled) @0721cee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:267526 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_tcp_nagle_enable/27 (altcp_tcp_nagle_enable) @0721cb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:313044 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_tcp_nagle_disable/26 (altcp_tcp_nagle_disable) @0721c8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:313044 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_tcp_sndqueuelen/25 (altcp_tcp_sndqueuelen) @0721c620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:187268 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_tcp_sndbuf/24 (altcp_tcp_sndbuf) @0721c380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:187268 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_sndbuf.part.0/59 (46017 (estimated locally),0.25 per call) 
altcp_tcp_mss/23 (altcp_tcp_mss) @0721c000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:187268 (estimated locally) body optimize_size
  Called by: 
  Calls: 
altcp_tcp_output/22 (altcp_tcp_output) @07213d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:130628 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_output.part.0/62 (22666 (estimated locally),0.17 per call) 
altcp_tcp_write/21 (altcp_tcp_write) @07213a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:130628 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_write.part.0/63 (22666 (estimated locally),0.17 per call) 
altcp_tcp_shutdown/20 (altcp_tcp_shutdown) @072137e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:130628 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_shutdown.part.0/64 (22666 (estimated locally),0.17 per call) 
altcp_tcp_close/19 (altcp_tcp_close) @07213540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:154085 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_close.part.0/65 (46017 (estimated locally),0.30 per call) 
altcp_tcp_abort/18 (altcp_tcp_abort) @072132a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_abort/50 (24606 (estimated locally),0.11 per call) 
altcp_tcp_listen/17 (altcp_tcp_listen) @07213000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:141764 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_listen.part.0/66 (22666 (estimated locally),0.16 per call) 
altcp_tcp_connect/16 (altcp_tcp_connect) @07209ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:130628 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_connect.part.0/67 (22666 (estimated locally),0.17 per call) 
altcp_tcp_bind/15 (altcp_tcp_bind) @07209c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:130628 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_bind.part.0/68 (22666 (estimated locally),0.17 per call) 
altcp_tcp_recved/14 (altcp_tcp_recved) @072099a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:185771 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_recved/55 (22666 (estimated locally),0.12 per call) 
altcp_tcp_set_poll/13 (altcp_tcp_set_poll) @07209700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: altcp_tcp_poll/5 (addr)
  Referring: altcp_tcp_functions/34 (addr)
  Availability: available
  Function flags: count:185771 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_poll/49 (22666 (estimated locally),0.12 per call) 
altcp_tcp_wrap/12 (altcp_tcp_wrap) @07209460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_setup/9 (468827936 (estimated locally),0.44 per call) altcp_alloc/36 (792206719 (estimated locally),0.74 per call) 
altcp_tcp_alloc/11 (altcp_tcp_alloc) @072091c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_new_ip_type/10 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_new_ip_type/10 (altcp_tcp_new_ip_type) @07203ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: altcp_tcp_alloc/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: tcp_close/37 (200903624 (estimated locally),0.19 per call) altcp_tcp_setup/9 (591303095 (estimated locally),0.55 per call) altcp_alloc/36 (792206719 (estimated locally),0.74 per call) tcp_new_ip_type/35 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_setup/9 (altcp_tcp_setup) @07203e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: altcp_tcp_functions/34 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: altcp_tcp_wrap/12 (468827936 (estimated locally),0.44 per call) altcp_tcp_new_ip_type/10 (591303095 (estimated locally),0.55 per call) altcp_tcp_accept/1 (1027681399 (estimated locally),0.96 per call) 
  Calls: altcp_tcp_setup_callbacks/8 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_setup_callbacks/8 (altcp_tcp_setup_callbacks) @07203b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: altcp_tcp_close.part.0/65 (152127742 (estimated locally),0.14 per call) altcp_tcp_setup/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: altcp_tcp_setup_callbacks.part.0/60 (524845000 (estimated locally),0.49 per call) tcp_arg/38 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_remove_callbacks/7 (altcp_tcp_remove_callbacks) @072038c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: altcp_tcp_close.part.0/65 (751619277 (estimated locally),0.70 per call) 
  Calls: tcp_poll/49 (524845004 (estimated locally),0.49 per call) tcp_err/41 (524845004 (estimated locally),0.49 per call) tcp_sent/40 (524845004 (estimated locally),0.49 per call) tcp_recv/39 (524845004 (estimated locally),0.49 per call) tcp_arg/38 (1073741824 (estimated locally),1.00 per call) 
altcp_tcp_err/6 (altcp_tcp_err) @07203620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_setup_callbacks.part.0/60 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_free/42 (751619278 (estimated locally),0.70 per call) 
   Indirect call(526133494 (estimated locally),0.49 per call)  of param:0 loaded from aggregate passed by reference at offset 288 (vptr maybe changed)
altcp_tcp_poll/5 (altcp_tcp_poll) @07203380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_set_poll/13 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_poll.part.0/58 (13805 (estimated locally),0.06 per call) 
altcp_tcp_sent/4 (altcp_tcp_sent) @072030e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_setup_callbacks.part.0/60 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_sent.part.0/57 (13805 (estimated locally),0.06 per call) 
altcp_tcp_recv/3 (altcp_tcp_recv) @071d9ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_setup_callbacks.part.0/60 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_recv.part.0/61 (72008 (estimated locally),0.33 per call) 
   Indirect call(7536 (estimated locally),0.03 per call)  of param:0 loaded from aggregate passed by reference at offset 192 (vptr maybe changed)
altcp_tcp_connected/2 (altcp_tcp_connected) @071d9c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_connect.part.0/67 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_connected.part.0/56 (13805 (estimated locally),0.06 per call) 
altcp_tcp_accept/1 (altcp_tcp_accept) @071d99a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: altcp_tcp_listen.part.0/66 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: altcp_tcp_setup/9 (1027681399 (estimated locally),0.96 per call) altcp_alloc/36 (1045879706 (estimated locally),0.97 per call) 
   Indirect call(1027681399 (estimated locally),0.96 per call)  of param:0 loaded from aggregate passed by reference at offset 128 (vptr maybe changed)

;; Function altcp_tcp_mss (altcp_tcp_mss, funcdef_no=23, decl_uid=7800, cgraph_uid=24, symbol_order=23)

Modification phase of node altcp_tcp_mss/23
altcp_tcp_mss (struct altcp_pcb * conn)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;
  u16_t _2;
  u16_t _7;

  <bb 2> [local count: 187268]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
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
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_6 = conn_4(D)->state;
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  _7 = pcb_6->mss;

  <bb 6> [local count: 79894]:
  # _2 = PHI <0(2), _7(5)>
  return _2;

}



;; Function altcp_tcp_sndqueuelen (altcp_tcp_sndqueuelen, funcdef_no=25, decl_uid=7810, cgraph_uid=26, symbol_order=25)

Modification phase of node altcp_tcp_sndqueuelen/25
altcp_tcp_sndqueuelen (struct altcp_pcb * conn)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;
  u16_t _2;
  u16_t _7;

  <bb 2> [local count: 187268]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
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
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_6 = conn_4(D)->state;
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  _7 = pcb_6->snd_queuelen;

  <bb 6> [local count: 79894]:
  # _2 = PHI <0(2), _7(5)>
  return _2;

}



;; Function altcp_tcp_nagle_disable (altcp_tcp_nagle_disable, funcdef_no=26, decl_uid=7815, cgraph_uid=27, symbol_order=26)

Modification phase of node altcp_tcp_nagle_disable/26
altcp_tcp_nagle_disable (struct altcp_pcb * conn)
{
  void * _1;
  struct altcp_pcb * _2;
  short unsigned int _3;
  short unsigned int _4;

  <bb 2> [local count: 313044]:
  # DEBUG BEGIN_STMT
  if (conn_7(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 3> [local count: 219131]:
  _1 = conn_7(D)->state;
  if (_1 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 4> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG pcb => _1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = conn_7(D)->inner_conn;
  if (_2 != 0B)
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
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct tcp_pcb *)_1].flags;
  _4 = _3 | 64;
  MEM[(struct tcp_pcb *)_1].flags = _4;

  <bb 7> [local count: 205670]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function altcp_tcp_nagle_enable (altcp_tcp_nagle_enable, funcdef_no=27, decl_uid=7820, cgraph_uid=28, symbol_order=27)

Modification phase of node altcp_tcp_nagle_enable/27
altcp_tcp_nagle_enable (struct altcp_pcb * conn)
{
  void * _1;
  struct altcp_pcb * _2;
  short unsigned int _3;
  short unsigned int _4;

  <bb 2> [local count: 313044]:
  # DEBUG BEGIN_STMT
  if (conn_7(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 3> [local count: 219131]:
  _1 = conn_7(D)->state;
  if (_1 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 4> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG pcb => _1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = conn_7(D)->inner_conn;
  if (_2 != 0B)
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
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct tcp_pcb *)_1].flags;
  _4 = _3 & 65471;
  MEM[(struct tcp_pcb *)_1].flags = _4;

  <bb 7> [local count: 205670]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function altcp_tcp_nagle_disabled (altcp_tcp_nagle_disabled, funcdef_no=28, decl_uid=7825, cgraph_uid=29, symbol_order=28)

Modification phase of node altcp_tcp_nagle_disabled/28
altcp_tcp_nagle_disabled (struct altcp_pcb * conn)
{
  void * _1;
  struct altcp_pcb * _2;
  short unsigned int _3;
  _Bool _4;
  int _5;
  int _9;
  short unsigned int _11;

  <bb 2> [local count: 267526]:
  # DEBUG BEGIN_STMT
  if (conn_7(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 3> [local count: 187268]:
  _1 = conn_7(D)->state;
  if (_1 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 4> [local count: 131088]:
  # DEBUG BEGIN_STMT
  # DEBUG pcb => _1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = conn_7(D)->inner_conn;
  if (_2 != 0B)
    goto <bb 8>; [81.91%]
  else
    goto <bb 6>; [18.09%]

  <bb 8> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 23714]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct tcp_pcb *)_1].flags;
  _11 = _3 & 64;
  _4 = _11 != 0;
  _9 = (int) _4;

  <bb 7> [local count: 160152]:
  # _5 = PHI <_9(6), 0(3), 0(2)>
  return _5;

}



;; Function altcp_tcp_dealloc (altcp_tcp_dealloc, funcdef_no=30, decl_uid=7836, cgraph_uid=31, symbol_order=30)

Modification phase of node altcp_tcp_dealloc/30
altcp_tcp_dealloc (struct altcp_pcb * conn)
{
  struct altcp_pcb * _1;

  <bb 2> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function altcp_tcp_get_ip (altcp_tcp_get_ip, funcdef_no=32, decl_uid=7849, cgraph_uid=33, symbol_order=32)

Modification phase of node altcp_tcp_get_ip/32
altcp_tcp_get_ip (struct altcp_pcb * conn, int local)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;
  struct ip_addr_t * _2;
  struct ip_addr_t * _8;
  struct ip_addr_t * _9;

  <bb 2> [local count: 180248]:
  # DEBUG BEGIN_STMT
  if (conn_4(D) != 0B)
    goto <bb 3>; [85.10%]
  else
    goto <bb 9>; [14.90%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  pcb_6 = conn_4(D)->state;
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 10> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_6 != 0B)
    goto <bb 6>; [85.10%]
  else
    goto <bb 9>; [14.90%]

  <bb 6> [local count: 39161]:
  # DEBUG BEGIN_STMT
  if (local_7(D) != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 19580]:
  # DEBUG BEGIN_STMT
  _9 = &pcb_6->local_ip;
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 19580]:
  # DEBUG BEGIN_STMT
  _8 = &pcb_6->remote_ip;

  <bb 9> [local count: 72874]:
  # _2 = PHI <_9(7), _8(8), 0B(5), 0B(2)>
  return _2;

}



;; Function altcp_tcp_get_port (altcp_tcp_get_port, funcdef_no=33, decl_uid=7855, cgraph_uid=34, symbol_order=33)

Modification phase of node altcp_tcp_get_port/33
altcp_tcp_get_port (struct altcp_pcb * conn, int local)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;
  u16_t _2;
  u16_t _8;
  u16_t _9;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  if (conn_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  pcb_6 = conn_4(D)->state;
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 10> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_6 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 6> [local count: 32212]:
  # DEBUG BEGIN_STMT
  if (local_7(D) != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 16106]:
  # DEBUG BEGIN_STMT
  _9 = pcb_6->local_port;
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 16106]:
  # DEBUG BEGIN_STMT
  _8 = pcb_6->remote_port;

  <bb 9> [local count: 111757]:
  # _2 = PHI <_9(7), _8(8), 0(5), 0(2)>
  return _2;

}



;; Function altcp_tcp_err (altcp_tcp_err, funcdef_no=6, decl_uid=7705, cgraph_uid=7, symbol_order=6)

Modification phase of node altcp_tcp_err/6
altcp_tcp_err (void * arg, err_t err)
{
  void (*<T640>) (void *, err_t) _1;
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
  MEM[(struct altcp_pcb *)arg_5(D)].state = 0B;
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



;; Function altcp_tcp_get_tcp_addrinfo (altcp_tcp_get_tcp_addrinfo, funcdef_no=31, decl_uid=7843, cgraph_uid=32, symbol_order=31)

Modification phase of node altcp_tcp_get_tcp_addrinfo/31
altcp_tcp_get_tcp_addrinfo (struct altcp_pcb * conn, int local, struct ip_addr_t * addr, u16_t * port)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;
  err_t _2;
  err_t _12;

  <bb 2> [local count: 120098]:
  # DEBUG BEGIN_STMT
  if (conn_5(D) != 0B)
    goto <bb 3>; [99.13%]
  else
    goto <bb 6>; [0.87%]

  <bb 3> [local count: 119053]:
  # DEBUG BEGIN_STMT
  pcb_7 = conn_5(D)->state;
  # DEBUG pcb => pcb_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_5(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [90.19%]
  else
    goto <bb 5>; [9.81%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 11679]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = tcp_tcp_get_tcp_addrinfo (pcb_7, local_8(D), addr_9(D), port_10(D));

  <bb 6> [local count: 12724]:
  # _2 = PHI <_12(5), -6(2)>
  return _2;

}



;; Function altcp_tcp_setprio (altcp_tcp_setprio, funcdef_no=29, decl_uid=7831, cgraph_uid=30, symbol_order=29)

Modification phase of node altcp_tcp_setprio/29
altcp_tcp_setprio (struct altcp_pcb * conn, u8_t prio)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;

  <bb 2> [local count: 185771]:
  # DEBUG BEGIN_STMT
  if (conn_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  pcb_6 = conn_4(D)->state;
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_setprio (pcb_6, prio_7(D));

  <bb 6> [local count: 78397]:
  return;

}



;; Function altcp_tcp_set_poll (altcp_tcp_set_poll, funcdef_no=13, decl_uid=7734, cgraph_uid=14, symbol_order=13)

Modification phase of node altcp_tcp_set_poll/13
altcp_tcp_set_poll (struct altcp_pcb * conn, u8_t interval)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;

  <bb 2> [local count: 185771]:
  # DEBUG BEGIN_STMT
  if (conn_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  pcb_6 = conn_4(D)->state;
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_poll (pcb_6, altcp_tcp_poll, interval_7(D));

  <bb 6> [local count: 78397]:
  return;

}



;; Function altcp_tcp_abort (altcp_tcp_abort, funcdef_no=18, decl_uid=7768, cgraph_uid=19, symbol_order=18)

Modification phase of node altcp_tcp_abort/18
altcp_tcp_abort (struct altcp_pcb * conn)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  if (conn_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  pcb_6 = conn_4(D)->state;
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 8>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 8> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_6 != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 6> [local count: 24606]:
  # DEBUG BEGIN_STMT
  tcp_abort (pcb_6);

  <bb 7> [local count: 111757]:
  return;

}



;; Function altcp_tcp_recved (altcp_tcp_recved, funcdef_no=14, decl_uid=7740, cgraph_uid=15, symbol_order=14)

Modification phase of node altcp_tcp_recved/14
altcp_tcp_recved (struct altcp_pcb * conn, u16_t len)
{
  struct tcp_pcb * pcb;
  struct altcp_pcb * _1;

  <bb 2> [local count: 185771]:
  # DEBUG BEGIN_STMT
  if (conn_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  pcb_6 = conn_4(D)->state;
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_recved (pcb_6, len_7(D));

  <bb 6> [local count: 78397]:
  return;

}



;; Function altcp_tcp_connected (altcp_tcp_connected, funcdef_no=2, decl_uid=7674, cgraph_uid=3, symbol_order=2)

Modification phase of node altcp_tcp_connected/2
altcp_tcp_connected (void * arg, struct tcp_pcb * tpcb, err_t err)
{
  void * _1;
  struct altcp_pcb * _2;
  signed char _3;
  err_t _4;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_7(D)
  # DEBUG BEGIN_STMT
  if (arg_7(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct altcp_pcb *)arg_7(D)].state;
  if (_1 != tpcb_10(D))
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

  <bb 11> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct altcp_pcb *)arg_7(D)].inner_conn;
  if (_2 != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 10> [local count: 32212]:

  <bb 6> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 322122547]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 13805]:
  # DEBUG D#1 => tpcb_10(D)
  _3 = altcp_tcp_connected.part.0 (arg_7(D), err_11(D));

  <bb 8> [local count: 79544]:
  # _4 = PHI <_3(7), 0(2)>
  return _4;

}



;; Function altcp_tcp_sent (altcp_tcp_sent, funcdef_no=4, decl_uid=7691, cgraph_uid=5, symbol_order=4)

Modification phase of node altcp_tcp_sent/4
altcp_tcp_sent (void * arg, struct tcp_pcb * tpcb, u16_t len)
{
  void * _1;
  struct altcp_pcb * _2;
  signed char _3;
  err_t _4;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_7(D)
  # DEBUG BEGIN_STMT
  if (arg_7(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct altcp_pcb *)arg_7(D)].state;
  if (_1 != tpcb_10(D))
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

  <bb 11> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct altcp_pcb *)arg_7(D)].inner_conn;
  if (_2 != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 10> [local count: 32212]:

  <bb 6> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 322122547]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 13805]:
  # DEBUG D#3 => tpcb_10(D)
  _3 = altcp_tcp_sent.part.0 (arg_7(D), len_11(D));

  <bb 8> [local count: 79544]:
  # _4 = PHI <_3(7), 0(2)>
  return _4;

}



;; Function altcp_tcp_poll (altcp_tcp_poll, funcdef_no=5, decl_uid=7698, cgraph_uid=6, symbol_order=5)

Modification phase of node altcp_tcp_poll/5
altcp_tcp_poll (void * arg, struct tcp_pcb * tpcb)
{
  void * _1;
  struct altcp_pcb * _2;
  signed char _3;
  err_t _4;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_7(D)
  # DEBUG BEGIN_STMT
  if (arg_7(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct altcp_pcb *)arg_7(D)].state;
  if (_1 != tpcb_10(D))
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

  <bb 11> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct altcp_pcb *)arg_7(D)].inner_conn;
  if (_2 != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 10> [local count: 32212]:

  <bb 6> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 322122547]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 13805]:
  # DEBUG D#5 => tpcb_10(D)
  _3 = altcp_tcp_poll.part.0 (arg_7(D));

  <bb 8> [local count: 79544]:
  # _4 = PHI <_3(7), 0(2)>
  return _4;

}



;; Function altcp_tcp_sndbuf (altcp_tcp_sndbuf, funcdef_no=24, decl_uid=7805, cgraph_uid=25, symbol_order=24)

Modification phase of node altcp_tcp_sndbuf/24
altcp_tcp_sndbuf (struct altcp_pcb * conn)
{
  struct altcp_pcb * _1;
  u16_t _3;
  short unsigned int _4;

  <bb 2> [local count: 187268]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_6(D) == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_6(D)->inner_conn;
  if (_1 != 0B)
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
  _4 = altcp_tcp_sndbuf.part.0 (conn_6(D));

  <bb 6> [local count: 79894]:
  # _3 = PHI <0(2), _4(5)>
  return _3;

}



;; Function altcp_tcp_setup_callbacks (altcp_tcp_setup_callbacks, funcdef_no=8, decl_uid=7713, cgraph_uid=9, symbol_order=8)

Modification phase of node altcp_tcp_setup_callbacks/8
altcp_tcp_setup_callbacks (struct altcp_pcb * conn, struct tcp_pcb * tpcb)
{
  tcp_state _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  tcp_arg (tpcb_3(D), conn_4(D));
  # DEBUG BEGIN_STMT
  _1 = tpcb_3(D)->state;
  if (_1 != 1)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845000]:
  # DEBUG D#7 => conn_4(D)
  altcp_tcp_setup_callbacks.part.0 (tpcb_3(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function altcp_tcp_recv (altcp_tcp_recv, funcdef_no=3, decl_uid=7683, cgraph_uid=4, symbol_order=3)

Modification phase of node altcp_tcp_recv/3
altcp_tcp_recv (void * arg, struct tcp_pcb * tpcb, struct pbuf * p, err_t err)
{
  void * _1;
  struct altcp_pcb * _2;
  err_t (*<T631>) (void *, struct altcp_pcb *, struct pbuf *, err_t) _3;
  void * _5;
  err_t _6;
  signed char _9;
  err_t _17;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_10(D)
  # DEBUG BEGIN_STMT
  if (arg_10(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct altcp_pcb *)arg_10(D)].state;
  if (_1 != tpcb_13(D))
    goto <bb 11>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 11> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct altcp_pcb *)arg_10(D)].inner_conn;
  if (_2 != 0B)
    goto <bb 12>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 12> [local count: 32212]:

  <bb 6> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 322122547]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 13805]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct altcp_pcb *)arg_10(D)].recv;
  if (_3 != 0B)
    goto <bb 8>; [54.59%]
  else
    goto <bb 9>; [45.41%]

  <bb 8> [local count: 7536]:
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct altcp_pcb *)arg_10(D)].arg;
  _17 = _3 (_5, arg_10(D), p_14(D), err_15(D));
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 72008]:
  # DEBUG D#9 => arg_10(D)
  # DEBUG D#10 => tpcb_13(D)
  # DEBUG D#11 => err_15(D)
  _9 = altcp_tcp_recv.part.0 (p_14(D));

  <bb 10> [local count: 79544]:
  # _6 = PHI <_17(8), _9(9)>
  return _6;

}



;; Function altcp_tcp_output (altcp_tcp_output, funcdef_no=22, decl_uid=7795, cgraph_uid=23, symbol_order=22)

Modification phase of node altcp_tcp_output/22
altcp_tcp_output (struct altcp_pcb * conn)
{
  struct altcp_pcb * _1;
  err_t _2;
  signed char _7;

  <bb 2> [local count: 130628]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  _7 = altcp_tcp_output.part.0 (conn_4(D));

  <bb 6> [local count: 23254]:
  # _2 = PHI <-6(2), _7(5)>
  return _2;

}



;; Function altcp_tcp_write (altcp_tcp_write, funcdef_no=21, decl_uid=7790, cgraph_uid=22, symbol_order=21)

Modification phase of node altcp_tcp_write/21
altcp_tcp_write (struct altcp_pcb * conn, const void * dataptr, u16_t len, u8_t apiflags)
{
  struct altcp_pcb * _1;
  err_t _2;
  signed char _10;

  <bb 2> [local count: 130628]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  _10 = altcp_tcp_write.part.0 (conn_4(D), dataptr_6(D), len_7(D), apiflags_8(D));

  <bb 6> [local count: 23254]:
  # _2 = PHI <-6(2), _10(5)>
  return _2;

}



;; Function altcp_tcp_shutdown (altcp_tcp_shutdown, funcdef_no=20, decl_uid=7782, cgraph_uid=21, symbol_order=20)

Modification phase of node altcp_tcp_shutdown/20
altcp_tcp_shutdown (struct altcp_pcb * conn, int shut_rx, int shut_tx)
{
  struct altcp_pcb * _1;
  err_t _2;
  signed char _9;

  <bb 2> [local count: 130628]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  _9 = altcp_tcp_shutdown.part.0 (conn_4(D), shut_rx_6(D), shut_tx_7(D));

  <bb 6> [local count: 23254]:
  # _2 = PHI <-6(2), _9(5)>
  return _2;

}



;; Function altcp_tcp_close (altcp_tcp_close, funcdef_no=19, decl_uid=7773, cgraph_uid=20, symbol_order=19)

Modification phase of node altcp_tcp_close/19
altcp_tcp_close (struct altcp_pcb * conn)
{
  struct altcp_pcb * _1;
  err_t _2;
  signed char _6;

  <bb 2> [local count: 154085]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
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
  _6 = altcp_tcp_close.part.0 (conn_4(D));

  <bb 6> [local count: 46711]:
  # _2 = PHI <-6(2), _6(5)>
  return _2;

}



;; Function altcp_tcp_listen (altcp_tcp_listen, funcdef_no=17, decl_uid=7762, cgraph_uid=18, symbol_order=17)

Modification phase of node altcp_tcp_listen/17
altcp_tcp_listen (struct altcp_pcb * conn, u8_t backlog, err_t * err)
{
  struct altcp_pcb * _1;
  struct altcp_pcb * _2;
  struct altcp_pcb * _8;

  <bb 2> [local count: 141764]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [8.27%]
  else
    goto <bb 3>; [91.73%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  _8 = altcp_tcp_listen.part.0 (conn_4(D), backlog_6(D), err_7(D));

  <bb 6> [local count: 34390]:
  # _2 = PHI <0B(2), _8(5)>
  return _2;

}



;; Function altcp_tcp_connect (altcp_tcp_connect, funcdef_no=16, decl_uid=7755, cgraph_uid=17, symbol_order=16)

Modification phase of node altcp_tcp_connect/16
altcp_tcp_connect (struct altcp_pcb * conn, const struct ip_addr_t * ipaddr, u16_t port, err_t (*altcp_connected_fn) (void *, struct altcp_pcb *, err_t) connected)
{
  struct altcp_pcb * _1;
  err_t _2;
  signed char _10;

  <bb 2> [local count: 130628]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  _10 = altcp_tcp_connect.part.0 (conn_4(D), ipaddr_7(D), port_8(D), connected_6(D));

  <bb 6> [local count: 23254]:
  # _2 = PHI <-6(2), _10(5)>
  return _2;

}



;; Function altcp_tcp_bind (altcp_tcp_bind, funcdef_no=15, decl_uid=7747, cgraph_uid=16, symbol_order=15)

Modification phase of node altcp_tcp_bind/15
altcp_tcp_bind (struct altcp_pcb * conn, const struct ip_addr_t * ipaddr, u16_t port)
{
  struct altcp_pcb * _1;
  err_t _2;
  signed char _9;

  <bb 2> [local count: 130628]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_4(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = conn_4(D)->inner_conn;
  if (_1 != 0B)
    goto <bb 7>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 22666]:
  _9 = altcp_tcp_bind.part.0 (conn_4(D), ipaddr_6(D), port_7(D));

  <bb 6> [local count: 23254]:
  # _2 = PHI <-6(2), _9(5)>
  return _2;

}



;; Function altcp_tcp_accept (altcp_tcp_accept, funcdef_no=1, decl_uid=7667, cgraph_uid=2, symbol_order=1)

Modification phase of node altcp_tcp_accept/1
altcp_tcp_accept (void * arg, struct tcp_pcb * new_tpcb, err_t err)
{
  struct altcp_pcb * new_conn;
  err_t (*<T62b>) (void *, struct altcp_pcb *, err_t) _1;
  err_t (*<T62b>) (void *, struct altcp_pcb *, err_t) _2;
  void * _3;
  err_t _4;
  err_t _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG listen_conn => arg_6(D)
  # DEBUG BEGIN_STMT
  if (arg_6(D) != 0B)
    goto <bb 3>; [99.13%]
  else
    goto <bb 6>; [0.87%]

  <bb 3> [local count: 1064400271]:
  _1 = MEM[(struct altcp_pcb *)arg_6(D)].accept;
  if (_1 != 0B)
    goto <bb 4>; [98.26%]
  else
    goto <bb 6>; [1.74%]

  <bb 4> [local count: 1045879706]:
  # DEBUG BEGIN_STMT
  new_conn_9 = altcp_alloc ();
  # DEBUG new_conn => new_conn_9
  # DEBUG BEGIN_STMT
  if (new_conn_9 == 0B)
    goto <bb 6>; [1.74%]
  else
    goto <bb 5>; [98.26%]

  <bb 5> [local count: 1027681399]:
  # DEBUG BEGIN_STMT
  altcp_tcp_setup (new_conn_9, new_tpcb_10(D));
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct altcp_pcb *)arg_6(D)].accept;
  _3 = MEM[(struct altcp_pcb *)arg_6(D)].arg;
  _14 = _2 (_3, new_conn_9, err_12(D));

  <bb 6> [local count: 1073741824]:
  # _4 = PHI <-1(4), _14(5), -16(3), -16(2)>
  return _4;

}



;; Function altcp_tcp_new_ip_type (altcp_tcp_new_ip_type, funcdef_no=10, decl_uid=6735, cgraph_uid=11, symbol_order=10)

Modification phase of node altcp_tcp_new_ip_type/10
altcp_tcp_new_ip_type (u8_t ip_type)
{
  struct altcp_pcb * ret;
  struct tcp_pcb * tpcb;
  struct altcp_pcb * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  tpcb_6 = tcp_new_ip_type (ip_type_4(D));
  # DEBUG tpcb => tpcb_6
  # DEBUG BEGIN_STMT
  if (tpcb_6 != 0B)
    goto <bb 3>; [73.78%]
  else
    goto <bb 6>; [26.22%]

  <bb 3> [local count: 792206719]:
  # DEBUG BEGIN_STMT
  ret_8 = altcp_alloc ();
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  if (ret_8 != 0B)
    goto <bb 4>; [74.64%]
  else
    goto <bb 5>; [25.36%]

  <bb 4> [local count: 591303095]:
  # DEBUG BEGIN_STMT
  altcp_tcp_setup (ret_8, tpcb_6);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 200903624]:
  # DEBUG BEGIN_STMT
  tcp_close (tpcb_6);

  <bb 6> [local count: 1073741824]:
  # _1 = PHI <ret_8(4), 0B(5), 0B(2)>
  return _1;

}



;; Function altcp_tcp_alloc (altcp_tcp_alloc, funcdef_no=11, decl_uid=6738, cgraph_uid=12, symbol_order=11)

Modification phase of node altcp_tcp_alloc/11
altcp_tcp_alloc (void * arg, u8_t ip_type)
{
  struct altcp_pcb * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = altcp_tcp_new_ip_type (ip_type_2(D));
  return _4;

}



;; Function altcp_tcp_wrap (altcp_tcp_wrap, funcdef_no=12, decl_uid=6741, cgraph_uid=13, symbol_order=12)

Modification phase of node altcp_tcp_wrap/12
altcp_tcp_wrap (struct tcp_pcb * tpcb)
{
  struct altcp_pcb * ret;
  struct altcp_pcb * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (tpcb_3(D) != 0B)
    goto <bb 3>; [73.78%]
  else
    goto <bb 5>; [26.22%]

  <bb 3> [local count: 792206719]:
  # DEBUG BEGIN_STMT
  ret_6 = altcp_alloc ();
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  if (ret_6 != 0B)
    goto <bb 4>; [59.18%]
  else
    goto <bb 5>; [40.82%]

  <bb 4> [local count: 468827936]:
  # DEBUG BEGIN_STMT
  altcp_tcp_setup (ret_6, tpcb_3(D));
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  # _1 = PHI <ret_6(4), 0B(3), 0B(2)>
  return _1;

}


