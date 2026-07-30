
IPA constant propagation start:
Determining dynamic type for call: ret_12 = pfe_idex_rpc (_2, id_6(D), buf_7(D), buf_len_8(D), resp_9(D), resp_len_10(D));
  Starting walk at: ret_12 = pfe_idex_rpc (_2, id_6(D), buf_7(D), buf_len_8(D), resp_9(D), resp_len_10(D));
  instance pointer: buf_7(D)  Outer instance pointer: buf_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_12 = pfe_idex_rpc (_2, id_6(D), buf_7(D), buf_len_8(D), resp_9(D), resp_len_10(D));
  Starting walk at: ret_12 = pfe_idex_rpc (_2, id_6(D), buf_7(D), buf_len_8(D), resp_9(D), resp_len_10(D));
  instance pointer: resp_9(D)  Outer instance pointer: resp_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_39 = pfe_idex_prep_tx_header_xmit.isra.0 (idex_hdr_29, sg_list, _45);
  Starting walk at: ret_39 = pfe_idex_prep_tx_header_xmit.isra.0 (idex_hdr_29, sg_list, _45);
  instance pointer: idex_hdr_29  Outer instance pointer: idex_hdr_29 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:idex_hdr_pa_31 = oal_mm_virt_to_phys_contig (idex_hdr_29);
  Function call may change dynamic type:hif_chnl_22 = pfe_hif_drv_get_chnl (hif_drv_18);
  Function call may change dynamic type:hif_drv_18 = pfe_hif_drv_client_get_drv (_4);
Determining dynamic type for call: ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
  Starting walk at: ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
  instance pointer: &pfe_idex_request_frame.req  Outer instance pointer: pfe_idex_request_frame offset: 144 (bits) vtbl reference: 
  Function call may change dynamic type:ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  Function call may change dynamic type:ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
Determining dynamic type for call: ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  Starting walk at: ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  instance pointer: &timeout_ms  Outer instance pointer: timeout_ms offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
  Function call may change dynamic type:ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  Function call may change dynamic type:ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
Determining dynamic type for call: ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  Starting walk at: ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  instance pointer: &end_sending  Outer instance pointer: end_sending offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
  Function call may change dynamic type:ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  Function call may change dynamic type:ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
Determining dynamic type for call: ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  Starting walk at: ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  instance pointer: &pfe_idex_request_frame.req  Outer instance pointer: pfe_idex_request_frame offset: 144 (bits) vtbl reference: 
  Function call may change dynamic type:ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
  Function call may change dynamic type:ret_53 = check_time_out (&timeout_ms, &end_sending, &pfe_idex_request_frame.req);
  Function call may change dynamic type:ret_50 = pfe_idex_send_frame (dst_phy_41(D), 0, &pfe_idex_request_frame.req, _14);
Determining dynamic type for call: ret_30 = pfe_idex_send_frame (dst_phy_28(D), 1, &pfe_idex_response_frame.resp, _13);
  Starting walk at: ret_30 = pfe_idex_send_frame (dst_phy_28(D), 1, &pfe_idex_response_frame.resp, _13);
  instance pointer: &pfe_idex_response_frame.resp  Outer instance pointer: pfe_idex_response_frame offset: 144 (bits) vtbl reference: 
Determining dynamic type for call: _4 = pfe_idex_send_frame (dst_phy_2(D), 100, &pfe_idex_dummy_frame.dummy_data, 62);
  Starting walk at: _4 = pfe_idex_send_frame (dst_phy_2(D), 100, &pfe_idex_dummy_frame.dummy_data, 62);
  instance pointer: &pfe_idex_dummy_frame.dummy_data  Outer instance pointer: pfe_idex_dummy_frame offset: 144 (bits) vtbl reference: 
Determining dynamic type for call: process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  Starting walk at: process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  instance pointer: idex_19(D)  Outer instance pointer: idex_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_14 = pfe_hif_drv_client_receive_pkt (hif_client_12(D), 0);
  Function call may change dynamic type:pfe_hif_pkt_free (pkt_14);
  Function call may change dynamic type:process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  Function call may change dynamic type:pkt_14 = pfe_hif_drv_client_receive_pkt (hif_client_12(D), 0);
Determining dynamic type for call: process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  Starting walk at: process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  instance pointer: idex_header_17  Outer instance pointer: idex_header_17 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_14 = pfe_hif_drv_client_receive_pkt (hif_client_12(D), 0);
  Function call may change dynamic type:pfe_hif_pkt_free (pkt_14);
  Function call may change dynamic type:process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  Function call may change dynamic type:pkt_14 = pfe_hif_drv_client_receive_pkt (hif_client_12(D), 0);
Determining dynamic type for call: process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  Starting walk at: process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  instance pointer: pkt_14  Outer instance pointer: pkt_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_14 = pfe_hif_drv_client_receive_pkt (hif_client_12(D), 0);
  Function call may change dynamic type:pfe_hif_pkt_free (pkt_14);
  Function call may change dynamic type:process_idex_request (idex_19(D), idex_header_17, _22, pkt_14);
  Function call may change dynamic type:pkt_14 = pfe_hif_drv_client_receive_pkt (hif_client_12(D), 0);
Determining dynamic type for call: _1 = get_client_index (i_phy_id_53(D), &client_index);
  Starting walk at: _1 = get_client_index (i_phy_id_53(D), &client_index);
  instance pointer: &client_index  Outer instance pointer: client_index offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: set_idex_sequence_number (client_61, seqnum_59, &break_switch);
  Starting walk at: set_idex_sequence_number (client_61, seqnum_59, &break_switch);
  instance pointer: client_61  Outer instance pointer: &idex_60(D)->remote.clients[client_index.3_14] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = get_client_index (i_phy_id_53(D), &client_index);
Determining dynamic type for call: set_idex_sequence_number (client_61, seqnum_59, &break_switch);
  Starting walk at: set_idex_sequence_number (client_61, seqnum_59, &break_switch);
  instance pointer: &break_switch  Outer instance pointer: break_switch offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = get_client_index (i_phy_id_53(D), &client_index);
Determining dynamic type for call: _44 (i_phy_id_53(D), rpc_id_67, rpc_msg_payload_ptr_68, _46, _47);
  Starting walk at: _44 (i_phy_id_53(D), rpc_id_67, rpc_msg_payload_ptr_68, _46, _47);
  instance pointer: rpc_msg_payload_ptr_68  Outer instance pointer: rpc_msg_payload_ptr_68 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_43, rpc_req_66, 10);
  Function call may change dynamic type:set_idex_sequence_number (client_61, seqnum_59, &break_switch);
  Function call may change dynamic type:_1 = get_client_index (i_phy_id_53(D), &client_index);
Determining dynamic type for call: _44 (i_phy_id_53(D), rpc_id_67, rpc_msg_payload_ptr_68, _46, _47);
  Starting walk at: _44 (i_phy_id_53(D), rpc_id_67, rpc_msg_payload_ptr_68, _46, _47);
  instance pointer: _47  Outer instance pointer: _47 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_43, rpc_req_66, 10);
  Function call may change dynamic type:set_idex_sequence_number (client_61, seqnum_59, &break_switch);
  Function call may change dynamic type:_1 = get_client_index (i_phy_id_53(D), &client_index);
Determining dynamic type for call: ret_28 = pfe_idex_send_frame (_6, 1, _5, _9);
  Starting walk at: ret_28 = pfe_idex_send_frame (_6, 1, _5, _9);
  instance pointer: _5  Outer instance pointer: _5 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_idex_do_rx (client_5(D), &pfe_idex);
  Starting walk at: pfe_idex_do_rx (client_5(D), &pfe_idex);
  instance pointer: client_5(D)  Outer instance pointer: client_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_idex_do_rx (client_5(D), &pfe_idex);
  Starting walk at: pfe_idex_do_rx (client_5(D), &pfe_idex);
  instance pointer: &pfe_idex  Outer instance pointer: pfe_idex offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_idex_prep_tx_header_xmit.isra.0/65:
  Jump functions of caller  oal_time_mdelay/63:
  Jump functions of caller  oal_time_msleep/62:
  Jump functions of caller  oal_irq_in_atomic/61:
  Jump functions of caller  pfe_hif_drv_client_unregister/60:
  Jump functions of caller  pfe_hif_clear_master_up/59:
  Jump functions of caller  autolibc_memcpy/58:
  Jump functions of caller  pfe_hif_pkt_free/57:
  Jump functions of caller  pfe_hif_drv_client_receive_pkt/56:
  Jump functions of caller  pfe_hif_drv_ihc_client_register/55:
  Jump functions of caller  autolibc_memset/54:
  Jump functions of caller  pfe_hif_drv_client_xmit_sg_pkt/53:
  Jump functions of caller  oal_mm_virt_to_phys_contig/52:
  Jump functions of caller  pfe_hif_drv_get_chnl/51:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/50:
  Jump functions of caller  pfe_hm_report/49:
  Jump functions of caller  pfe_hif_drv_client_get_drv/48:
  Jump functions of caller  pfe_idex_down/47:
  Jump functions of caller  pfe_idex_set_rpc_ret_val/46:
    callsite  pfe_idex_set_rpc_ret_val/46 -> pfe_idex_send_response/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op plus_expr 10
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pfe_idex_rpc/45:
    callsite  pfe_idex_rpc/45 -> pfe_idex_request_send/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x29
         VR  [1, 40]
       param 3: PASS THROUGH: 3, op plus_expr 10
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pfe_idex_master_rpc/44:
    callsite  pfe_idex_master_rpc/44 -> pfe_idex_rpc/45 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pfe_idex_fini/43:
  Jump functions of caller  pfe_idex_init/42:
    callsite  pfe_idex_init/42 -> pfe_idex_fini/43 : 
  Jump functions of caller  pfe_idex_send_frame/40:
    callsite  pfe_idex_send_frame/40 -> pfe_idex_prep_tx_header_xmit.isra.0/65 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by value:
           offset: 0, cst: 1
         Unknown bits
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_idex_request_send/38:
    callsite  pfe_idex_request_send/38 -> check_time_out/37 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: &pfe_idex_request_frame.req
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_idex_request_send/38 -> pfe_idex_send_frame/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: &pfe_idex_request_frame.req
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: PASS THROUGH: 3, op plus_expr 37
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  check_time_out/37:
  Jump functions of caller  pfe_idex_send_response/36:
    callsite  pfe_idex_send_response/36 -> pfe_idex_send_frame/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: &pfe_idex_response_frame.resp
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: PASS THROUGH: 3, op plus_expr 7
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pfe_idex_send_dummy_frame/35:
    callsite  pfe_idex_send_dummy_frame/35 -> pfe_idex_send_frame/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 100
         value: 0x64, mask: 0x0
         Unknown VR
       param 2: CONST: &pfe_idex_dummy_frame.dummy_data
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: 62
         value: 0x3e, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_idex_do_rx/34:
    callsite  pfe_idex_do_rx/34 -> process_idex_request/33 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  process_idex_request/33:
    callsite  process_idex_request/33 -> set_idex_sequence_number/32 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  process_idex_request/33 -> pfe_idex_send_response/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 15
         value: 0xf, mask: 0x0
         Unknown VR
    callsite  process_idex_request/33 -> get_client_index/31 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    indirect aggregate callsite, calling param 0, offset 64, by reference, for stmt _44 (i_phy_id_53(D), rpc_id_67, rpc_msg_payload_ptr_68, _46, _47);
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  set_idex_sequence_number/32:
    callsite  set_idex_sequence_number/32 -> pfe_idex_send_frame/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  get_client_index/31:
  Jump functions of caller  pfe_idex_ihc_handler/30:
    callsite  pfe_idex_ihc_handler/30 -> pfe_idex_do_rx/34 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &pfe_idex
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]

 Propagating constants:

Not considering pfe_idex_down for cloning; -fipa-cp-clone disabled.
Not considering pfe_idex_set_rpc_ret_val for cloning; -fipa-cp-clone disabled.
Not considering pfe_idex_rpc for cloning; -fipa-cp-clone disabled.
Not considering pfe_idex_master_rpc for cloning; -fipa-cp-clone disabled.
Not considering pfe_idex_fini for cloning; -fipa-cp-clone disabled.
Not considering pfe_idex_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_idex_send_dummy_frame for cloning; -fipa-cp-clone disabled.
Not considering pfe_idex_ihc_handler for cloning; -fipa-cp-clone disabled.

overall_size: 685, max_new_size: 11001
 - context independent values, size: 36, time_benefit: 1.000000
 - context independent values, size: 78, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 25, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 8, time_benefit: 2.000000
 - context independent values, size: 32, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 109, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 8, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 35, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 36, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 36, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_idex_prep_tx_header_xmit.isra.0/65:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        offset 0: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_idex_down/47:
  Node: pfe_idex_set_rpc_ret_val/46:
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
  Node: pfe_idex_rpc/45:
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
  Node: pfe_idex_master_rpc/44:
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
  Node: pfe_idex_fini/43:
  Node: pfe_idex_init/42:
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
  Node: pfe_idex_send_frame/40:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 1, loc_size: 79, prop_time: 0, prop_size: 0]
               100 [loc_time: 1, loc_size: 79, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 79, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x65
         pfe_idex_frame_type_t [0, 100]
        AGGS VARIABLE
    param [2]: VARIABLE
               &pfe_idex_response_frame.resp [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               &pfe_idex_dummy_frame.dummy_data [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               &pfe_idex_request_frame.req [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
               22 [loc_time: 1, loc_size: 78, prop_time: 0, prop_size: 0]
               62 [loc_time: 1, loc_size: 78, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_idex_request_send/38:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         pfe_idex_request_type_t [1, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x29
         const uint32_t [1, 40]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: check_time_out/37:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         bool_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: &pfe_idex_request_frame.req [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_idex_request_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_idex_send_response/36:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         pfe_idex_response_type_t [1, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
               15 [loc_time: 4, loc_size: 35, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_idex_send_dummy_frame/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_idex_do_rx/34:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &pfe_idex [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_idex_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: process_idex_request/33:
    param [0]: &pfe_idex [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_idex_t * ~[0B, 0B]
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
  Node: set_idex_sequence_number/32:
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
         bool_t * ~[0B, 0B]
        ref offset 0: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: get_client_index/31:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * const ~[0B, 0B]
        ref offset 0: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: pfe_idex_ihc_handler/30:
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

IPA decision stage:

 - Creating a specialized node of pfe_idex_request_send/38 for all known contexts.
    replacing param #1 type with const 1
 - Creating a specialized node of check_time_out/37 for all known contexts.
    replacing param #2 request with const &pfe_idex_request_frame.req
 - Creating a specialized node of pfe_idex_do_rx/34 for all known contexts.
    replacing param #1 idex with const &pfe_idex
 - Creating a specialized node of process_idex_request/33 for all known contexts.
    replacing param #0 idex with const &pfe_idex
 - Creating a specialized node of get_client_index/31 for all known contexts.
 - Creating a specialized node of pfe_idex_send_response/36 for all known contexts.
    replacing param #1 type with const 1
 - Creating a specialized node of set_idex_sequence_number/32 for all known contexts.
 - Creating a specialized node of pfe_idex_prep_tx_header_xmit.isra.0/65 for all known contexts.
Propagated bits info for function pfe_idex_send_response.constprop/72:
 param 1: value = 0x1, mask = 0x0
Propagated bits info for function get_client_index.constprop/71:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function process_idex_request.constprop/70:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_idex_do_rx.constprop/69:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function check_time_out.constprop/68:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_idex_request_send.constprop/67:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x0, mask = 0x29
Propagated bits info for function pfe_idex_send_frame/40:
 param 1: value = 0x0, mask = 0x65
Propagated bits info for function pfe_idex_request_send/38:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x0, mask = 0x29
Propagated bits info for function check_time_out/37:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_idex_send_response/36:
 param 1: value = 0x1, mask = 0x0
Propagated bits info for function pfe_idex_do_rx/34:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function process_idex_request/33:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function get_client_index/31:
 param 1: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: pfe_idex_prep_tx_header_xmit.isra.0/65 pfe_idex_request_send/38 check_time_out/37 pfe_idex_send_response/36 pfe_idex_do_rx/34 process_idex_request/33 set_idex_sequence_number/32 get_client_index/31
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_idex_prep_tx_header_xmit.isra.0.constprop.0/74 (pfe_idex_prep_tx_header_xmit.isra.0.constprop) @0702c540
  Type: function definition analyzed
  Visibility: artificial
  References: pfe_idex/25 (read)
  Referring: 
  Clone of pfe_idex_prep_tx_header_xmit.isra.0/65
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_idex_send_frame/40 (221974905 (estimated locally),0.21 per call) 
  Calls: pfe_hif_drv_client_xmit_sg_pkt/53 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/49 (354334802 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/50 (354334802 (estimated locally),0.33 per call) 
set_idex_sequence_number.constprop.0/73 (set_idex_sequence_number.constprop) @0700ec40
  Type: function definition analyzed
  Visibility:
  References: pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (read)pfe_idex/25 (write)
  Referring: 
  Clone of set_idex_sequence_number/32
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: process_idex_request.constprop/70 (80717468 (estimated locally),0.08 per call) 
  Calls: pfe_idex_send_frame/40 (115170429 (estimated locally),0.11 per call) 
pfe_idex_send_response.constprop.0/72 (pfe_idex_send_response.constprop) @073d5c40
  Type: function definition analyzed
  Visibility:
  References: idex_current_client/26 (read)pfe_idex_response_frame/27 (write)pfe_idex_response_frame/27 (write)pfe_idex_response_frame/27 (write)pfe_idex_response_frame/27 (addr)pfe_idex/25 (read)pfe_idex/25 (write)idex_current_client/26 (read)pfe_idex_response_frame/27 (addr)
  Referring: 
  Clone of pfe_idex_send_response/36
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_idex_set_rpc_ret_val/46 (1073741824 (estimated locally),1.00 per call) process_idex_request.constprop/70 (41581726 (estimated locally),0.04 per call) 
  Calls: pfe_idex_send_frame/40 (1073741824 (estimated locally),1.00 per call) 
get_client_index.constprop.0/71 (get_client_index.constprop) @06dd5d20
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of get_client_index/31
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: process_idex_request.constprop/70 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
process_idex_request.constprop.0/70 (process_idex_request.constprop) @073d59a0
  Type: function definition analyzed
  Visibility:
  References: idex_current_client/26 (write)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex_response_frame/27 (addr)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (addr)
  Referring: 
  Clone of process_idex_request/33
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: pfe_idex_do_rx.constprop/69 (325638113 (estimated locally),3.74 per call) 
  Calls: get_client_index.constprop/71 (1073741823 (estimated locally),1.00 per call) pfe_hm_report/49 (354334802 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/50 (354334802 (estimated locally),0.33 per call) autolibc_memcpy/58 (41581726 (estimated locally),0.04 per call) pfe_idex_send_response.constprop/72 (41581726 (estimated locally),0.04 per call) set_idex_sequence_number.constprop/73 (80717468 (estimated locally),0.08 per call) autolibc_memcpy/58 (28485356 (estimated locally),0.03 per call) 
   Indirect call(28485356 (estimated locally),0.03 per call)  of param:0 loaded from aggregate passed by reference at offset 64 (vptr maybe changed)
pfe_idex_do_rx.constprop.0/69 (pfe_idex_do_rx.constprop) @077632a0
  Type: function definition analyzed
  Visibility:
  References: pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (addr)
  Referring: 
  Clone of pfe_idex_do_rx/34
  Availability: local
  Function flags: count:86959666 (estimated locally) local optimize_size
  Called by: pfe_idex_ihc_handler/30 (512926469 (estimated locally),0.48 per call) 
  Calls: pfe_hif_drv_client_receive_pkt/56 (1073741824 (estimated locally),12.35 per call) process_idex_request.constprop/70 (325638113 (estimated locally),3.74 per call) pfe_hif_pkt_free/57 (986782160 (estimated locally),11.35 per call) 
check_time_out.constprop.0/68 (check_time_out.constprop) @07750ee0
  Type: function definition analyzed
  Visibility:
  References: pfe_idex_request_frame/28 (addr)
  Referring: 
  Clone of check_time_out/37
  Availability: local
  Function flags: count:113634470 (estimated locally) local optimize_size
  Called by: pfe_idex_request_send.constprop/67 (996582265 (estimated locally),8.77 per call) 
  Calls: oal_irq_in_atomic/61 (960107354 (estimated locally),8.45 per call) oal_time_msleep/62 (480053677 (estimated locally),4.22 per call) oal_time_mdelay/63 (480053677 (estimated locally),4.22 per call) 
pfe_idex_request_send.constprop.0/67 (pfe_idex_request_send.constprop) @073d8460
  Type: function definition analyzed
  Visibility:
  References: pfe_idex_request_frame/28 (write)pfe_idex/25 (read)pfe_idex_request_frame/28 (write)pfe_idex_request_frame/28 (write)pfe_idex_request_frame/28 (write)pfe_idex_request_frame/28 (write)pfe_idex/25 (write)pfe_idex_request_frame/28 (addr)pfe_idex_request_frame/28 (write)pfe_idex_request_frame/28 (addr)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex_request_frame/28 (addr)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex_request_frame/28 (write)pfe_idex/25 (write)pfe_idex/25 (write)
  Referring: 
  Clone of pfe_idex_request_send/38
  Availability: local
  Function flags: count:113634470 (estimated locally) local optimize_size
  Called by: pfe_idex_rpc/45 (405417081 (estimated locally),0.38 per call) 
  Calls: pfe_idex_send_frame/40 (1034442874 (estimated locally),9.10 per call) pfe_hm_report/49 (37860609 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/50 (37860609 (estimated locally),0.33 per call) check_time_out.constprop/68 (996582265 (estimated locally),8.77 per call) 
pfe_idex_prep_tx_header_xmit.isra.0/65 (pfe_idex_prep_tx_header_xmit.isra.0) @0700e9a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_time_mdelay/63 (oal_time_mdelay) @0784d8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: check_time_out.constprop/68 (480053677 (estimated locally),4.22 per call) 
  Calls: 
oal_time_msleep/62 (oal_time_msleep) @0784d7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: check_time_out.constprop/68 (480053677 (estimated locally),4.22 per call) 
  Calls: 
oal_irq_in_atomic/61 (oal_irq_in_atomic) @0784d700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: check_time_out.constprop/68 (960107354 (estimated locally),8.45 per call) 
  Calls: 
pfe_hif_drv_client_unregister/60 (pfe_hif_drv_client_unregister) @0784d000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_fini/43 (337723386 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_clear_master_up/59 (pfe_hif_clear_master_up) @07836700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_fini/43 (631612842 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memcpy/58 (autolibc_memcpy) @078367e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: process_idex_request.constprop/70 (41581726 (estimated locally),0.04 per call) process_idex_request.constprop/70 (28485356 (estimated locally),0.03 per call) pfe_idex_rpc/45 (23088503 (estimated locally),0.02 per call) pfe_idex_rpc/45 (405417081 (estimated locally),0.38 per call) pfe_idex_set_rpc_ret_val/46 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_pkt_free/57 (pfe_hif_pkt_free) @07836460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_do_rx.constprop/69 (986782160 (estimated locally),11.35 per call) 
  Calls: 
pfe_hif_drv_client_receive_pkt/56 (pfe_hif_drv_client_receive_pkt) @07836380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_do_rx.constprop/69 (1073741824 (estimated locally),12.35 per call) 
  Calls: 
pfe_hif_drv_ihc_client_register/55 (pfe_hif_drv_ihc_client_register) @078360e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_init/42 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/54 (autolibc_memset) @07836000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_rpc/45 (405417081 (estimated locally),0.38 per call) pfe_idex_rpc/45 (405417081 (estimated locally),0.38 per call) pfe_idex_set_rpc_ret_val/46 (1073741824 (estimated locally),1.00 per call) pfe_idex_init/42 (1073741824 (estimated locally),1.00 per call) pfe_idex_init/42 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_drv_client_xmit_sg_pkt/53 (pfe_hif_drv_client_xmit_sg_pkt) @07818ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_prep_tx_header_xmit.isra.0.constprop/74 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_mm_virt_to_phys_contig/52 (oal_mm_virt_to_phys_contig) @07818d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_send_frame/40 (273199883 (estimated locally),0.25 per call) 
  Calls: 
pfe_hif_drv_get_chnl/51 (pfe_hif_drv_get_chnl) @07818c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_send_frame/40 (336246010 (estimated locally),0.31 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/50 (oal_util_raise_dem_for_drv_runtime_err) @07818b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_prep_tx_header_xmit.isra.0.constprop/74 (354334802 (estimated locally),0.33 per call) process_idex_request.constprop/70 (354334802 (estimated locally),0.33 per call) pfe_idex_request_send.constprop/67 (37860609 (estimated locally),0.33 per call) pfe_idex_rpc/45 (23088503 (estimated locally),0.02 per call) pfe_idex_rpc/45 (133787637 (estimated locally),0.12 per call) pfe_idex_rpc/45 (668324743 (estimated locally),0.62 per call) pfe_idex_set_rpc_ret_val/46 (354334802 (estimated locally),0.33 per call) pfe_idex_init/42 (109629040 (estimated locally),0.10 per call) pfe_idex_send_frame/40 (51224978 (estimated locally),0.05 per call) pfe_idex_send_frame/40 (63046127 (estimated locally),0.06 per call) pfe_idex_send_frame/40 (54814520 (estimated locally),0.05 per call) 
  Calls: 
pfe_hm_report/49 (pfe_hm_report) @07818a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_prep_tx_header_xmit.isra.0.constprop/74 (354334802 (estimated locally),0.33 per call) process_idex_request.constprop/70 (354334802 (estimated locally),0.33 per call) pfe_idex_request_send.constprop/67 (37860609 (estimated locally),0.33 per call) pfe_idex_rpc/45 (23088503 (estimated locally),0.02 per call) pfe_idex_rpc/45 (133787637 (estimated locally),0.12 per call) pfe_idex_rpc/45 (668324743 (estimated locally),0.62 per call) pfe_idex_set_rpc_ret_val/46 (354334802 (estimated locally),0.33 per call) pfe_idex_init/42 (109629040 (estimated locally),0.10 per call) pfe_idex_send_frame/40 (51224978 (estimated locally),0.05 per call) pfe_idex_send_frame/40 (63046127 (estimated locally),0.06 per call) pfe_idex_send_frame/40 (54814520 (estimated locally),0.05 per call) 
  Calls: 
pfe_hif_drv_client_get_drv/48 (pfe_hif_drv_client_get_drv) @078189a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_idex_send_frame/40 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_idex_down/47 (pfe_idex_down) @07818460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_idex/25 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_idex_set_rpc_ret_val/46 (pfe_idex_set_rpc_ret_val) @078181c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: idex_current_client/26 (read)pfe_idex_response_frame/27 (addr)pfe_idex_response_frame/27 (write)pfe_idex_response_frame/27 (write)pfe_idex_response_frame/27 (write)pfe_idex_response_frame/27 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/50 (354334802 (estimated locally),0.33 per call) pfe_hm_report/49 (354334802 (estimated locally),0.33 per call) pfe_idex_send_response.constprop/72 (1073741824 (estimated locally),1.00 per call) autolibc_memcpy/58 (1073741824 (estimated locally),1.00 per call) autolibc_memset/54 (1073741824 (estimated locally),1.00 per call) 
pfe_idex_rpc/45 (pfe_idex_rpc) @077639a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_idex/25 (read)pfe_idex_response_frame/27 (addr)pfe_idex_request_frame/28 (addr)pfe_idex_request_frame/28 (write)pfe_idex_request_frame/28 (write)pfe_idex_request_frame/28 (write)pfe_idex_response_frame/27 (write)pfe_idex/25 (write)pfe_idex_response_frame/27 (addr)pfe_idex_request_frame/28 (addr)pfe_idex_response_frame/27 (read)pfe_idex_response_frame/27 (read)pfe_idex_response_frame/27 (read)pfe_idex_response_frame/27 (addr)pfe_idex/25 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_idex_master_rpc/44 (512926469 (estimated locally),0.48 per call) 
  Calls: autolibc_memcpy/58 (23088503 (estimated locally),0.02 per call) oal_util_raise_dem_for_drv_runtime_err/50 (23088503 (estimated locally),0.02 per call) pfe_hm_report/49 (23088503 (estimated locally),0.02 per call) oal_util_raise_dem_for_drv_runtime_err/50 (133787637 (estimated locally),0.12 per call) pfe_hm_report/49 (133787637 (estimated locally),0.12 per call) oal_util_raise_dem_for_drv_runtime_err/50 (668324743 (estimated locally),0.62 per call) pfe_hm_report/49 (668324743 (estimated locally),0.62 per call) pfe_idex_request_send.constprop/67 (405417081 (estimated locally),0.38 per call) autolibc_memcpy/58 (405417081 (estimated locally),0.38 per call) autolibc_memset/54 (405417081 (estimated locally),0.38 per call) autolibc_memset/54 (405417081 (estimated locally),0.38 per call) 
pfe_idex_master_rpc/44 (pfe_idex_master_rpc) @07763b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_idex/25 (read)pfe_idex/25 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_idex_rpc/45 (512926469 (estimated locally),0.48 per call) 
pfe_idex_fini/43 (pfe_idex_fini) @077638c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_idex/25 (write)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (write)pfe_idex/25 (write)pfe_idex/25 (write)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (read)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (write)
  Referring: 
  Availability: available
  Function flags: count:631612842 (estimated locally) body optimize_size
  Called by: pfe_idex_init/42 (109629040 (estimated locally),0.10 per call) 
  Calls: pfe_hif_drv_client_unregister/60 (337723386 (estimated locally),0.53 per call) pfe_hif_clear_master_up/59 (631612842 (estimated locally),1.00 per call) 
pfe_idex_init/42 (pfe_idex_init) @07763620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_idex/25 (addr)pfe_idex_dummy_frame/29 (addr)pfe_idex/25 (write)pfe_idex/25 (write)pfe_idex/25 (write)pfe_idex/25 (write)pfe_idex_ihc_handler/30 (addr)pfe_idex/25 (write)pfe_idex/25 (write)pfe_idex/25 (write)pfe_idex/25 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_idex_fini/43 (109629040 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/50 (109629040 (estimated locally),0.10 per call) pfe_hm_report/49 (109629040 (estimated locally),0.10 per call) pfe_hif_drv_ihc_client_register/55 (1073741824 (estimated locally),1.00 per call) autolibc_memset/54 (1073741824 (estimated locally),1.00 per call) autolibc_memset/54 (1073741824 (estimated locally),1.00 per call) 
pfe_idex_send_frame/40 (pfe_idex_send_frame) @07763000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_idex/25 (read)pfe_idex/25 (read)pfe_idex/25 (write)pfe_idex/25 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: set_idex_sequence_number.constprop/73 (115170429 (estimated locally),0.11 per call) pfe_idex_send_response.constprop/72 (1073741824 (estimated locally),1.00 per call) pfe_idex_request_send.constprop/67 (1034442874 (estimated locally),9.10 per call) pfe_idex_send_dummy_frame/35 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_idex_prep_tx_header_xmit.isra.0.constprop/74 (221974905 (estimated locally),0.21 per call) oal_util_raise_dem_for_drv_runtime_err/50 (51224978 (estimated locally),0.05 per call) pfe_hm_report/49 (51224978 (estimated locally),0.05 per call) oal_mm_virt_to_phys_contig/52 (273199883 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/50 (63046127 (estimated locally),0.06 per call) pfe_hm_report/49 (63046127 (estimated locally),0.06 per call) pfe_hif_drv_get_chnl/51 (336246010 (estimated locally),0.31 per call) oal_util_raise_dem_for_drv_runtime_err/50 (54814520 (estimated locally),0.05 per call) pfe_hm_report/49 (54814520 (estimated locally),0.05 per call) pfe_hif_drv_client_get_drv/48 (1073741824 (estimated locally),1.00 per call) 
pfe_idex_request_send/38 (pfe_idex_request_send) @07750b60
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:113634470 (estimated locally) body optimize_size
  Called by: 
  Calls: 
check_time_out/37 (check_time_out) @07750620
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:113634470 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_idex_send_response/36 (pfe_idex_send_response) @07750380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_idex_send_dummy_frame/35 (pfe_idex_send_dummy_frame) @07750000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_idex_dummy_frame/29 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_idex_send_frame/40 (1073741824 (estimated locally),1.00 per call) 
pfe_idex_do_rx/34 (pfe_idex_do_rx) @0765d9a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:86959666 (estimated locally) body optimize_size
  Called by: 
  Calls: 
process_idex_request/33 (process_idex_request) @0765d380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
set_idex_sequence_number/32 (set_idex_sequence_number) @0765db60
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
get_client_index/31 (get_client_index) @0765d8c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_idex_ihc_handler/30 (pfe_idex_ihc_handler) @0765d540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: pfe_idex/25 (addr)
  Referring: pfe_idex_init/42 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_idex_do_rx.constprop/69 (512926469 (estimated locally),0.48 per call) 
pfe_idex_dummy_frame/29 (pfe_idex_dummy_frame) @07653630
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_idex_send_dummy_frame/35 (addr)pfe_idex_init/42 (addr)
  Availability: available
  Varpool flags:
pfe_idex_request_frame/28 (pfe_idex_request_frame) @076535a0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: check_time_out.constprop.0/68 (addr)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (addr)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (addr)pfe_idex_request_send.constprop.0/67 (addr)pfe_idex_rpc/45 (addr)pfe_idex_rpc/45 (write)pfe_idex_rpc/45 (write)pfe_idex_rpc/45 (write)pfe_idex_rpc/45 (addr)pfe_idex_request_send.constprop.0/67 (write)
  Availability: available
  Varpool flags:
pfe_idex_response_frame/27 (pfe_idex_response_frame) @07653510
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_idex_set_rpc_ret_val/46 (addr)pfe_idex_send_response.constprop.0/72 (addr)pfe_idex_send_response.constprop.0/72 (addr)process_idex_request.constprop.0/70 (addr)pfe_idex_set_rpc_ret_val/46 (write)pfe_idex_send_response.constprop.0/72 (write)pfe_idex_send_response.constprop.0/72 (write)pfe_idex_send_response.constprop.0/72 (write)pfe_idex_set_rpc_ret_val/46 (addr)pfe_idex_set_rpc_ret_val/46 (write)pfe_idex_set_rpc_ret_val/46 (write)pfe_idex_rpc/45 (addr)pfe_idex_rpc/45 (write)pfe_idex_rpc/45 (addr)pfe_idex_rpc/45 (read)pfe_idex_rpc/45 (read)pfe_idex_rpc/45 (read)pfe_idex_rpc/45 (addr)
  Availability: available
  Varpool flags:
idex_current_client/26 (idex_current_client) @07653480
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: process_idex_request.constprop.0/70 (write)pfe_idex_send_response.constprop.0/72 (read)pfe_idex_send_response.constprop.0/72 (read)pfe_idex_set_rpc_ret_val/46 (read)
  Availability: available
  Varpool flags:
pfe_idex/25 (pfe_idex) @076533f0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (read)pfe_idex_init/42 (write)pfe_idex_fini/43 (write)pfe_idex_rpc/45 (write)pfe_idex_ihc_handler/30 (addr)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (read)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (read)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_send_frame/40 (read)pfe_idex_send_frame/40 (read)pfe_idex_do_rx.constprop.0/69 (read)pfe_idex_do_rx.constprop.0/69 (write)pfe_idex_master_rpc/44 (read)pfe_idex_prep_tx_header_xmit.isra.0.constprop.0/74 (read)set_idex_sequence_number.constprop.0/73 (read)pfe_idex_fini/43 (read)pfe_idex_send_frame/40 (write)pfe_idex_send_frame/40 (read)pfe_idex_fini/43 (write)pfe_idex_do_rx.constprop.0/69 (write)set_idex_sequence_number.constprop.0/73 (write)pfe_idex_init/42 (write)pfe_idex_init/42 (write)pfe_idex_down/47 (write)pfe_idex_request_send.constprop.0/67 (read)pfe_idex_init/42 (write)pfe_idex_init/42 (write)pfe_idex_init/42 (write)pfe_idex_init/42 (write)set_idex_sequence_number.constprop.0/73 (write)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_request_send.constprop.0/67 (write)pfe_idex_do_rx.constprop.0/69 (read)pfe_idex_fini/43 (write)pfe_idex_fini/43 (read)pfe_idex_fini/43 (write)pfe_idex_fini/43 (write)pfe_idex_fini/43 (write)pfe_idex_fini/43 (write)pfe_idex_fini/43 (read)pfe_idex_fini/43 (write)pfe_idex_fini/43 (read)pfe_idex_init/42 (addr)pfe_idex_init/42 (write)pfe_idex_do_rx.constprop.0/69 (addr)process_idex_request.constprop.0/70 (read)process_idex_request.constprop.0/70 (write)process_idex_request.constprop.0/70 (read)process_idex_request.constprop.0/70 (write)process_idex_request.constprop.0/70 (addr)pfe_idex_send_response.constprop.0/72 (read)pfe_idex_send_response.constprop.0/72 (write)set_idex_sequence_number.constprop.0/73 (read)pfe_idex_rpc/45 (read)pfe_idex_rpc/45 (write)pfe_idex_master_rpc/44 (read)pfe_idex_request_send.constprop.0/67 (read)pfe_idex_request_send.constprop.0/67 (write)
  Availability: available
  Varpool flags: initialized

;; Function pfe_idex_send_frame (pfe_idex_send_frame, funcdef_no=33, decl_uid=11680, cgraph_uid=34, symbol_order=40)

Modification phase of node pfe_idex_send_frame/40
Adjusting mask for param 1 to 0x65
Setting value range of param 1 [0, 100]
pfe_idex_send_frame (pfe_ct_phy_if_id_t dst_phy, pfe_idex_frame_type_t type, const void * data, uint16_t data_len)
{
  struct pfe_hif_chnl_t * hif_chnl;
  struct pfe_hif_drv_t * hif_drv;
  struct hif_drv_sg_list_t sg_list;
  errno_t ret;
  struct pfe_idex_frame_header_t * idex_hdr_pa;
  struct pfe_idex_frame_header_t * idex_hdr;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  struct pfe_hif_drv_client_t * _4;
  unsigned int data.0_5;
  unsigned int _6;
  unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _45;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  sg_list = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_idex.is_up;
  if (_1 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 = pfe_idex.stats.tx_skips;
  _3 = _2 + 1;
  pfe_idex.stats.tx_skips = _3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22

  <bb 4> [local count: 1073741824]:
  # ret_10 = PHI <0(2), 22(3)>
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  _4 = pfe_idex.ihc_client;
  hif_drv_18 = pfe_hif_drv_client_get_drv (_4);
  # DEBUG hif_drv => hif_drv_18
  # DEBUG BEGIN_STMT
  if (ret_10 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 536870913]:
  if (hif_drv_18 == 0B)
    goto <bb 6>; [10.21%]
  else
    goto <bb 7>; [89.79%]

  <bb 6> [local count: 54814520]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Get hif_drv instance associated with the client failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_idex.c", 1100, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 1018927305]:
  # DEBUG BEGIN_STMT
  if (ret_10 == 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 13>; [67.00%]

  <bb 8> [local count: 336246010]:
  # DEBUG BEGIN_STMT
  hif_chnl_22 = pfe_hif_drv_get_chnl (hif_drv_18);
  # DEBUG hif_chnl => hif_chnl_22
  # DEBUG BEGIN_STMT
  if (hif_chnl_22 == 0B)
    goto <bb 9>; [18.75%]
  else
    goto <bb 10>; [81.25%]

  <bb 9> [local count: 63046127]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Get channel associated with the hif_drv instance failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_idex.c", 1108, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  goto <bb 13>; [100.00%]

  <bb 10> [local count: 273199883]:
  # DEBUG BEGIN_STMT
  data.0_5 = (unsigned int) data_23(D);
  _6 = data.0_5 + 4294967294;
  idex_hdr_24 = (struct pfe_idex_frame_header_t *) _6;
  # DEBUG idex_hdr => idex_hdr_24
  # DEBUG BEGIN_STMT
  idex_hdr_24->dst_phy_if = dst_phy_25(D);
  # DEBUG BEGIN_STMT
  idex_hdr_24->type = type_27(D);
  # DEBUG BEGIN_STMT
  _7 = data.0_5 + 4294967278;
  idex_hdr_29 = (struct pfe_idex_frame_header_t *) _7;
  # DEBUG idex_hdr => idex_hdr_29
  # DEBUG BEGIN_STMT
  idex_hdr_pa_31 = oal_mm_virt_to_phys_contig (idex_hdr_29);
  # DEBUG idex_hdr_pa => idex_hdr_pa_31
  # DEBUG BEGIN_STMT
  if (idex_hdr_pa_31 == 0B)
    goto <bb 11>; [18.75%]
  else
    goto <bb 12>; [81.25%]

  <bb 11> [local count: 51224978]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] VA to PA conversion failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_idex.c", 1155, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 11
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 221974905]:
  # DEBUG BEGIN_STMT
  sg_list.size = 1;
  # DEBUG BEGIN_STMT
  sg_list.dst_phy = dst_phy_25(D);
  # DEBUG BEGIN_STMT
  sg_list.items[0].data_va = idex_hdr_29;
  # DEBUG BEGIN_STMT
  sg_list.items[0].data_pa = idex_hdr_pa_31;
  # DEBUG BEGIN_STMT
  _8 = (long unsigned int) data_len_36(D);
  _9 = _8 + 18;
  sg_list.items[0].len = _9;
  # DEBUG BEGIN_STMT
  _45 = MEM[(long unsigned int *)hif_chnl_22 + 4B];
  # DEBUG D#2 => hif_chnl_22
  ret_39 = pfe_idex_prep_tx_header_xmit.isra.0 (idex_hdr_29, sg_list, _45);
  # DEBUG ret => ret_39

  <bb 13> [local count: 1073741824]:
  # ret_11 = PHI <2(6), ret_10(7), 2(9), 11(11), ret_39(12)>
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  sg_list ={v} {CLOBBER};
  return ret_11;

}



;; Function pfe_idex_send_response.constprop (pfe_idex_send_response.constprop.0, funcdef_no=45, decl_uid=12116, cgraph_uid=66, symbol_order=72)

Modification phase of node pfe_idex_send_response.constprop/72
pfe_idex_send_response.constprop (pfe_ct_phy_if_id_t dst_phy, pfe_idex_seqnum_t seqnum, uint16_t data_len)
{
  errno_t ret;
  pfe_idex_response_type_t type;
  struct pfe_remote_client_t * idex_current_client.7_1;
  struct pfe_idex_response_t * _2;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  short unsigned int _14;
  short unsigned int _15;
  long unsigned int _18;
  long unsigned int _19;
  struct pfe_remote_client_t * idex_current_client.10_20;

  <bb 7> [local count: 1073741824]:
  # DEBUG type => 1

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  idex_current_client.7_1 = idex_current_client;
  _2 = idex_current_client.7_1->response;
  if (_2 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  *_2 = {};
  # DEBUG BEGIN_STMT
  idex_current_client.7_1->response = 0B;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG resp => &pfe_idex_response_frame.resp
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = seqnum_3(D) >> 24;
  _5 = seqnum_3(D) >> 8;
  _6 = _5 & 65280;
  _7 = _4 | _6;
  _8 = seqnum_3(D) << 8;
  _9 = _8 & 16711680;
  _10 = _7 | _9;
  _11 = seqnum_3(D) << 24;
  _12 = _10 | _11;
  MEM[(struct pfe_idex_response_t *)&pfe_idex_response_frame + 18B].seqnum = _12;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_idex_response_t *)&pfe_idex_response_frame + 18B].type = 1;
  # DEBUG BEGIN_STMT
  _14 = data_len_13(D) r>> 8;
  MEM[(struct pfe_idex_response_t *)&pfe_idex_response_frame + 18B].plen = _14;
  # DEBUG BEGIN_STMT
  _15 = data_len_13(D) + 7;
  ret_17 = pfe_idex_send_frame (dst_phy_16(D), 1, &pfe_idex_response_frame.resp, _15);
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  if (ret_17 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _18 = pfe_idex.stats.tx_count;
  _19 = _18 + 1;
  pfe_idex.stats.tx_count = _19;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  idex_current_client.10_20 = idex_current_client;
  idex_current_client.10_20->response = &pfe_idex_response_frame.resp;
  # DEBUG BEGIN_STMT
  return ret_17;

}



;; Function pfe_idex_ihc_handler (pfe_idex_ihc_handler, funcdef_no=23, decl_uid=11690, cgraph_uid=24, symbol_order=30)

Modification phase of node pfe_idex_ihc_handler/30
pfe_idex_ihc_handler (struct pfe_hif_drv_client_t * client, void * arg, uint32_t event, uint32_t qno)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (event_3(D) == 0)
    goto <bb 3>; [47.77%]
  else
    goto <bb 4>; [52.23%]

  <bb 3> [local count: 512926469]:
<L0>:
  # DEBUG BEGIN_STMT
  pfe_idex_do_rx (client_5(D), &pfe_idex);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # ret_1 = PHI <0(3), 22(2)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_idex_send_dummy_frame (pfe_idex_send_dummy_frame, funcdef_no=28, decl_uid=9533, cgraph_uid=29, symbol_order=35)

Modification phase of node pfe_idex_send_dummy_frame/35
pfe_idex_send_dummy_frame (pfe_ct_phy_if_id_t dst_phy)
{
  errno_t _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 = pfe_idex_send_frame (dst_phy_2(D), 100, &pfe_idex_dummy_frame.dummy_data, 62);
  return _4;

}



;; Function pfe_idex_fini (pfe_idex_fini, funcdef_no=36, decl_uid=9537, cgraph_uid=37, symbol_order=43)

Modification phase of node pfe_idex_fini/43
pfe_idex_fini ()
{
  uint8_t i;
  struct pfe_hif_t * _1;
  struct pfe_hif_drv_client_t * _2;
  unsigned char _3;
  int _4;
  struct pfe_idex_response_t * _5;

  <bb 2> [local count: 631612842]:
  # DEBUG BEGIN_STMT
  # DEBUG idex => &pfe_idex
  # DEBUG BEGIN_STMT
  pfe_idex.is_up = 0;
  # DEBUG BEGIN_STMT
  _1 = pfe_idex.hif;
  pfe_hif_clear_master_up (_1);
  # DEBUG BEGIN_STMT
  pfe_idex.hif = 0B;
  # DEBUG BEGIN_STMT
  pfe_idex.rpc_cbk = 0B;
  # DEBUG BEGIN_STMT
  pfe_idex.rpc_cbk_arg = 0B;
  # DEBUG BEGIN_STMT
  pfe_idex.txc_free_cbk = 0B;
  # DEBUG BEGIN_STMT
  _2 = pfe_idex.ihc_client;
  if (_2 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 337723386]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_client_unregister (_2);
  # DEBUG BEGIN_STMT
  pfe_idex.ihc_client = 0B;

  <bb 4> [local count: 631612842]:
  # DEBUG BEGIN_STMT
  _3 = pfe_idex.is_server;
  if (_3 == 1)
    goto <bb 10>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 10> [local count: 214748366]:
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 858993460]:
  # DEBUG BEGIN_STMT
  _4 = (int) i_6;
  _5 = pfe_idex.remote.clients[_4].response;
  if (_5 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 6> [local count: 601295422]:
  # DEBUG BEGIN_STMT
  *_5 = {};
  # DEBUG BEGIN_STMT
  pfe_idex.remote.clients[_4].response = 0B;

  <bb 7> [local count: 858993460]:
  # DEBUG BEGIN_STMT
  i_22 = i_6 + 1;
  # DEBUG i => i_22

  <bb 8> [local count: 1073741824]:
  # i_6 = PHI <i_22(7), 0(10)>
  # DEBUG i => i_6
  # DEBUG BEGIN_STMT
  if (i_6 != 4)
    goto <bb 5>; [80.00%]
  else
    goto <bb 9>; [20.00%]

  <bb 9> [local count: 631612841]:
  # DEBUG BEGIN_STMT
  pfe_idex.rpc_req_lock_init = 0;
  return;

}



;; Function pfe_idex_init (pfe_idex_init, funcdef_no=35, decl_uid=9514, cgraph_uid=36, symbol_order=42)

Modification phase of node pfe_idex_init/42
pfe_idex_init (struct pfe_hif_drv_t * hif_drv, pfe_ct_phy_if_id_t master, struct pfe_hif_t * hif, void (*pfe_idex_rpc_cbk_t) (pfe_ct_phy_if_id_t, uint32_t, void *, uint16_t, void *) cbk, void * arg, void (*pfe_idex_tx_conf_free_cbk_t) (void *) txcf_cbk)
{
  errno_t ret;
  struct pfe_hif_drv_client_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG idex => &pfe_idex
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_idex, 0, 180);
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_idex_dummy_frame, 0, 80);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_idex.is_server = 1;
  # DEBUG BEGIN_STMT
  pfe_idex.hif = hif_7(D);
  # DEBUG BEGIN_STMT
  pfe_idex.txc_free_cbk = txcf_cbk_9(D);
  # DEBUG BEGIN_STMT
  pfe_idex.rpc_req_lock_init = 1;
  # DEBUG BEGIN_STMT
  _1 = pfe_hif_drv_ihc_client_register (hif_drv_12(D), pfe_idex_ihc_handler, 0B);
  pfe_idex.ihc_client = _1;
  # DEBUG BEGIN_STMT
  if (_1 == 0B)
    goto <bb 4>; [10.21%]
  else
    goto <bb 3>; [89.79%]

  <bb 3> [local count: 964112785]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG cbk => cbk_18(D)
  # DEBUG arg => arg_19(D)
  # DEBUG INLINE_ENTRY pfe_idex_set_rpc_cbk
  # DEBUG BEGIN_STMT
  # DEBUG idex => &pfe_idex
  # DEBUG BEGIN_STMT
  pfe_idex.rpc_cbk_arg = arg_19(D);
  # DEBUG BEGIN_STMT
  pfe_idex.rpc_cbk = cbk_18(D);
  # DEBUG BEGIN_STMT
  # DEBUG cbk => NULL
  # DEBUG arg => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_idex.is_up = 1;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 109629040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t register IHC client\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_idex.c", 1261, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_idex_fini ();
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  # ret_23 = PHI <117(4), 0(3)>
  # DEBUG BEGIN_STMT
  return ret_23;

}



;; Function pfe_idex_rpc (pfe_idex_rpc, funcdef_no=38, decl_uid=9521, cgraph_uid=39, symbol_order=45)

Modification phase of node pfe_idex_rpc/45
pfe_idex_rpc (pfe_ct_phy_if_id_t dst_phy, uint32_t id, const void * buf, uint16_t buf_len, void * resp, uint16_t resp_len)
{
  void * payload;
  const uint16_t response_buf_size;
  const uint16_t request_buf_size;
  errno_t ret;
  <unnamed type> _1;
  unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  short unsigned int _15;
  unsigned int msg_req.13_16;
  unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  short unsigned int _20;
  unsigned int msg_resp.14_21;
  unsigned int _22;
  long unsigned int _23;
  const uint32_t iftmp.12_26;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  request_buf_size_30 = buf_len_29(D) + 10;
  # DEBUG request_buf_size => request_buf_size_30
  # DEBUG BEGIN_STMT
  response_buf_size_32 = resp_len_31(D) + 10;
  # DEBUG response_buf_size => response_buf_size_32
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_idex.remote.server.version;
  if (_1 > 1)
    goto <bb 5>; [59.00%]
  else
    goto <bb 3>; [41.00%]

  <bb 3> [local count: 440234148]:
  if (id_34(D) == 4294967295)
    goto <bb 5>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 4> [local count: 290554537]:

  <bb 5> [local count: 1073741824]:
  # iftmp.12_26 = PHI <40(3), 1(4), 40(2)>
  # DEBUG resend_count => iftmp.12_26
  # DEBUG BEGIN_STMT
  _2 = (unsigned int) request_buf_size_30;
  _3 = _2 + 39;
  if (_3 > 1522)
    goto <bb 8>; [20.96%]
  else
    goto <bb 6>; [79.04%]

  <bb 6> [local count: 848685538]:
  _4 = (unsigned int) response_buf_size_32;
  _5 = _4 + 39;
  if (_5 > 1522)
    goto <bb 8>; [52.23%]
  else
    goto <bb 7>; [47.77%]

  <bb 7> [local count: 405417081]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_idex_response_frame.msg_rpc, 0, _4);
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_idex_request_frame.msg, 0, _2);
  # DEBUG BEGIN_STMT
  # DEBUG msg_req => &pfe_idex_request_frame.msg
  # DEBUG BEGIN_STMT
  # DEBUG msg_resp => &pfe_idex_response_frame.msg_rpc
  # DEBUG BEGIN_STMT
  _6 = id_34(D) >> 24;
  _7 = id_34(D) >> 8;
  _8 = _7 & 65280;
  _9 = _6 | _8;
  _10 = id_34(D) << 8;
  _11 = _10 & 16711680;
  _12 = _9 | _11;
  _13 = id_34(D) << 24;
  _14 = _12 | _13;
  MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_request_frame + 55B].rpc_id = _14;
  # DEBUG BEGIN_STMT
  _15 = buf_len_29(D) r>> 8;
  MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_request_frame + 55B].plen = _15;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_request_frame + 55B].rpc_ret = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_response_frame + 25B].plen = resp_len_31(D);
  # DEBUG BEGIN_STMT
  pfe_idex.remote.server.rpc_msg = &pfe_idex_response_frame.msg_rpc;
  # DEBUG BEGIN_STMT
  msg_req.13_16 = (unsigned int) &pfe_idex_request_frame.msg;
  _17 = msg_req.13_16 + 10;
  payload_44 = (void *) _17;
  # DEBUG payload => payload_44
  # DEBUG BEGIN_STMT
  _18 = (long unsigned int) buf_len_29(D);
  autolibc_memcpy (payload_44, buf_45(D), _18);
  # DEBUG BEGIN_STMT
  ret_49 = pfe_idex_request_send (dst_phy_47(D), 1, iftmp.12_26, request_buf_size_30);
  # DEBUG ret => ret_49
  # DEBUG BEGIN_STMT
  if (ret_49 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 8> [local count: 668324743]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Buffers too big for request/response transport\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_idex.c", 1406, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 11
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 9> [local count: 133787637]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] RPC transport failed: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_idex.c", 1445, ret_49, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 10> [local count: 271629444]:
  # DEBUG BEGIN_STMT
  _19 = MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_response_frame + 25B].rpc_id;
  if (_19 != id_34(D))
    goto <bb 15>; [66.00%]
  else
    goto <bb 11>; [34.00%]

  <bb 11> [local count: 92354011]:
  # DEBUG BEGIN_STMT
  ret_50 = MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_response_frame + 25B].rpc_ret;
  # DEBUG ret => ret_50
  # DEBUG BEGIN_STMT
  _20 = MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_response_frame + 25B].plen;
  if (_20 == 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 46177005]:
  # DEBUG BEGIN_STMT
  if (_20 > resp_len_31(D))
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 23088503]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Caller\'s buffer is too small\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_idex.c", 1469, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 11
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 23088503]:
  # DEBUG BEGIN_STMT
  msg_resp.14_21 = (unsigned int) &pfe_idex_response_frame.msg_rpc;
  _22 = msg_resp.14_21 + 10;
  payload_51 = (void *) _22;
  # DEBUG payload => payload_51
  # DEBUG BEGIN_STMT
  _23 = (long unsigned int) _20;
  autolibc_memcpy (resp_52(D), payload_51, _23);

  <bb 15> [local count: 405417080]:
  # ret_24 = PHI <ret_49(9), 22(10), ret_50(11), 11(13), ret_50(14)>
  # DEBUG ret => ret_24
  # DEBUG BEGIN_STMT
  pfe_idex.remote.server.rpc_msg = 0B;

  <bb 16> [local count: 1073741823]:
  # ret_25 = PHI <11(8), ret_24(15)>
  # DEBUG ret => ret_25
  # DEBUG BEGIN_STMT
  return ret_25;

}



;; Function pfe_idex_master_rpc (pfe_idex_master_rpc, funcdef_no=37, decl_uid=9527, cgraph_uid=38, symbol_order=44)

Modification phase of node pfe_idex_master_rpc/44
pfe_idex_master_rpc (uint32_t id, const void * buf, uint16_t buf_len, void * resp, uint16_t resp_len)
{
  errno_t ret;
  unsigned char _1;
  <unnamed type> _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG idex => &pfe_idex
  # DEBUG BEGIN_STMT
  # DEBUG ret => 115
  # DEBUG BEGIN_STMT
  _1 = pfe_idex.is_server;
  if (_1 == 0)
    goto <bb 3>; [47.77%]
  else
    goto <bb 4>; [52.23%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  _2 = pfe_idex.remote.server.phy_id;
  ret_12 = pfe_idex_rpc (_2, id_6(D), buf_7(D), buf_len_8(D), resp_9(D), resp_len_10(D));
  # DEBUG ret => ret_12

  <bb 4> [local count: 1073741824]:
  # ret_3 = PHI <115(2), ret_12(3)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_idex_set_rpc_ret_val (pfe_idex_set_rpc_ret_val, funcdef_no=39, decl_uid=9531, cgraph_uid=40, symbol_order=46)

Modification phase of node pfe_idex_set_rpc_ret_val/46
pfe_idex_set_rpc_ret_val (errno_t retval, void * resp, uint16_t resp_len)
{
  errno_t ret;
  void * payload;
  struct pfe_remote_client_t * client;
  long unsigned int _1;
  short unsigned int _2;
  long unsigned int retval.17_3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  int _13;
  unsigned int rpc_resp.21_14;
  unsigned int _15;
  long unsigned int _16;
  <unnamed type> _17;
  long unsigned int _18;
  short unsigned int _19;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  client_22 = idex_current_client;
  # DEBUG client => client_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG rpc_resp => &pfe_idex_response_frame.msg_rpc
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_idex_response_frame, 0, 1538);
  # DEBUG BEGIN_STMT
  _1 = client_22->rpc_msg.rpc_id;
  MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_response_frame + 25B].rpc_id = _1;
  # DEBUG BEGIN_STMT
  _2 = resp_len_25(D) r>> 8;
  MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_response_frame + 25B].plen = _2;
  # DEBUG BEGIN_STMT
  retval.17_3 = (long unsigned int) retval_27(D);
  _4 = retval.17_3 >> 24;
  _5 = retval.17_3 >> 8;
  _6 = _5 & 65280;
  _7 = _4 | _6;
  _8 = retval.17_3 << 8;
  _9 = _8 & 16711680;
  _10 = _7 | _9;
  _11 = retval.17_3 << 24;
  _12 = _10 | _11;
  _13 = (int) _12;
  MEM[(struct pfe_idex_msg_rpc_t *)&pfe_idex_response_frame + 25B].rpc_ret = _13;
  # DEBUG BEGIN_STMT
  rpc_resp.21_14 = (unsigned int) &pfe_idex_response_frame.msg_rpc;
  _15 = rpc_resp.21_14 + 10;
  payload_29 = (void *) _15;
  # DEBUG payload => payload_29
  # DEBUG BEGIN_STMT
  _16 = (long unsigned int) resp_len_25(D);
  autolibc_memcpy (payload_29, resp_30(D), _16);
  # DEBUG BEGIN_STMT
  _17 = client_22->phy_id;
  _18 = client_22->seqnum;
  _19 = resp_len_25(D) + 10;
  ret_33 = pfe_idex_send_response (_17, 1, _18, _19);
  # DEBUG ret => ret_33
  # DEBUG BEGIN_STMT
  if (ret_33 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] IDEX RPC response failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_idex.c", 1534, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_33;

}



;; Function pfe_idex_down (pfe_idex_down, funcdef_no=40, decl_uid=9535, cgraph_uid=41, symbol_order=47)

Modification phase of node pfe_idex_down/47
pfe_idex_down ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pfe_idex.is_up = 0;
  return;

}


