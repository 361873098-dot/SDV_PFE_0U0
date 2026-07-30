
IPA constant propagation start:
Determining dynamic type for call: netif_10 = tcp_route.isra.0 (pcb_1(D), _9);
  Starting walk at: netif_10 = tcp_route.isra.0 (pcb_1(D), _9);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_10 = tcp_route.isra.0 (pcb_1(D), _9);
  Starting walk at: netif_10 = tcp_route.isra.0 (pcb_1(D), _9);
  instance pointer: _9  Outer instance pointer: pcb_1(D) offset: 32 (bits) vtbl reference: 
Determining dynamic type for call: err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  Starting walk at: err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  instance pointer: seg_31  Outer instance pointer: seg_31 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_34 = lwip_htons (_33);
  Function call may change dynamic type:_114 = lwip_htonl (_113);
  Function call may change dynamic type:_16 = lwip_htonl (_15);
  Function call may change dynamic type:netif_10 = tcp_route.isra.0 (pcb_1(D), _9);
  Function call may change dynamic type:_81 = lwip_htons (_80);
  Function call may change dynamic type:_68 = lwip_htons (_67);
  Function call may change dynamic type:_63 = lwip_htonl (_62);
  Function call may change dynamic type:err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  Function call may change dynamic type:_51 = lwip_htons (16);
  Function call may change dynamic type:_93 = lwip_htonl (_92);
  Function call may change dynamic type:_89 = lwip_htonl (_88);
  Function call may change dynamic type:_106 = lwip_htonl (_105);
  Function call may change dynamic type:_103 = lwip_htonl (_102);
  Function call may change dynamic type:tcp_seg_free (seg_31);
Determining dynamic type for call: err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  Starting walk at: err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_34 = lwip_htons (_33);
  Function call may change dynamic type:_114 = lwip_htonl (_113);
  Function call may change dynamic type:_16 = lwip_htonl (_15);
  Function call may change dynamic type:netif_10 = tcp_route.isra.0 (pcb_1(D), _9);
  Function call may change dynamic type:_81 = lwip_htons (_80);
  Function call may change dynamic type:_68 = lwip_htons (_67);
  Function call may change dynamic type:_63 = lwip_htonl (_62);
  Function call may change dynamic type:err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  Function call may change dynamic type:_51 = lwip_htons (16);
  Function call may change dynamic type:_93 = lwip_htonl (_92);
  Function call may change dynamic type:_89 = lwip_htonl (_88);
  Function call may change dynamic type:_106 = lwip_htonl (_105);
  Function call may change dynamic type:_103 = lwip_htonl (_102);
  Function call may change dynamic type:tcp_seg_free (seg_31);
Determining dynamic type for call: err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  Starting walk at: err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  instance pointer: netif_10  Outer instance pointer: netif_10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_34 = lwip_htons (_33);
  Function call may change dynamic type:_114 = lwip_htonl (_113);
  Function call may change dynamic type:_16 = lwip_htonl (_15);
  Function call may change dynamic type:netif_10 = tcp_route.isra.0 (pcb_1(D), _9);
  Function call may change dynamic type:_81 = lwip_htons (_80);
  Function call may change dynamic type:_68 = lwip_htons (_67);
  Function call may change dynamic type:_63 = lwip_htonl (_62);
  Function call may change dynamic type:err_54 = tcp_output_segment (seg_31, pcb_1(D), netif_10);
  Function call may change dynamic type:_51 = lwip_htons (16);
  Function call may change dynamic type:_93 = lwip_htonl (_92);
  Function call may change dynamic type:_89 = lwip_htonl (_88);
  Function call may change dynamic type:_106 = lwip_htonl (_105);
  Function call may change dynamic type:_103 = lwip_htonl (_102);
  Function call may change dynamic type:tcp_seg_free (seg_31);
Determining dynamic type for call: _27 = tcp_send_empty_ack (pcb_1(D));
  Starting walk at: _27 = tcp_send_empty_ack (pcb_1(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_16 = lwip_htonl (_15);
  Function call may change dynamic type:netif_10 = tcp_route.isra.0 (pcb_1(D), _9);
Determining dynamic type for call: _8 = tcp_send_empty_ack (pcb_1(D));
  Starting walk at: _8 = tcp_send_empty_ack (pcb_1(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Starting walk at: p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  Starting walk at: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_4, 0);
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  Starting walk at: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  instance pointer: p_4  Outer instance pointer: p_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_4, 0);
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  Starting walk at: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  instance pointer: _7  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_4, 0);
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  Starting walk at: err_9 = tcp_output_control_segment (pcb_1(D), p_4, _7, _8);
  instance pointer: _8  Outer instance pointer: pcb_1(D) offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_4, 0);
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: tcp_output_fill_options.isra.0 (p_4, 0);
  Starting walk at: tcp_output_fill_options.isra.0 (p_4, 0);
  instance pointer: p_4  Outer instance pointer: p_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_4 = tcp_output_alloc_header (pcb_1(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: seg_23 = tcp_create_segment (pcb_3(D), p_16, flags_1(D), _22, optflags_7);
  Starting walk at: seg_23 = tcp_create_segment (pcb_3(D), p_16, flags_1(D), _22, optflags_7);
  instance pointer: pcb_3(D)  Outer instance pointer: pcb_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_16 = pbuf_alloc (54, _15, 640);
Determining dynamic type for call: seg_23 = tcp_create_segment (pcb_3(D), p_16, flags_1(D), _22, optflags_7);
  Starting walk at: seg_23 = tcp_create_segment (pcb_3(D), p_16, flags_1(D), _22, optflags_7);
  instance pointer: p_16  Outer instance pointer: p_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_16 = pbuf_alloc (54, _15, 640);
Determining dynamic type for call: netif_3 = tcp_route.isra.0 (pcb_1(D), dst_2(D));
  Starting walk at: netif_3 = tcp_route.isra.0 (pcb_1(D), dst_2(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netif_3 = tcp_route.isra.0 (pcb_1(D), dst_2(D));
  Starting walk at: netif_3 = tcp_route.isra.0 (pcb_1(D), dst_2(D));
  instance pointer: dst_2(D)  Outer instance pointer: dst_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Starting walk at: p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  instance pointer: pcb_38(D)  Outer instance pointer: pcb_38(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = lwip_htons (_5);
Determining dynamic type for call: tcp_output_fill_options.isra.0 (p_46, 0);
  Starting walk at: tcp_output_fill_options.isra.0 (p_46, 0);
  instance pointer: p_46  Outer instance pointer: p_46 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  Starting walk at: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  instance pointer: pcb_38(D)  Outer instance pointer: pcb_38(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_46, 0);
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  Starting walk at: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  instance pointer: p_46  Outer instance pointer: p_46 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_46, 0);
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  Starting walk at: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  instance pointer: _28  Outer instance pointer: pcb_38(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_46, 0);
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  Starting walk at: err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  instance pointer: _29  Outer instance pointer: pcb_38(D) offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_46, 0);
  Function call may change dynamic type:_24 = lwip_htonl (_23);
  Function call may change dynamic type:_14 = lwip_htons (17);
  Function call may change dynamic type:p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  Function call may change dynamic type:_6 = lwip_htons (_5);
  Function call may change dynamic type:pbuf_copy_partial (_18, d_48, 1, _21);
Determining dynamic type for call: p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Starting walk at: p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: tcp_output_fill_options.isra.0 (p_13, 0);
  Starting walk at: tcp_output_fill_options.isra.0 (p_13, 0);
  instance pointer: p_13  Outer instance pointer: p_13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  Starting walk at: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_13, 0);
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  Starting walk at: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  instance pointer: p_13  Outer instance pointer: p_13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_13, 0);
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  Starting walk at: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  instance pointer: _4  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_13, 0);
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  Starting walk at: err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  instance pointer: _5  Outer instance pointer: pcb_9(D) offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_13, 0);
  Function call may change dynamic type:p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  Function call may change dynamic type:_3 = lwip_htonl (_2);
Determining dynamic type for call: _2 = tcp_send_empty_ack.part.0 (pcb_4(D));
  Starting walk at: _2 = tcp_send_empty_ack.part.0 (pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_output_fill_options.isra.0 (p_16, 0);
  Starting walk at: tcp_output_fill_options.isra.0 (p_16, 0);
  instance pointer: p_16  Outer instance pointer: p_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 16475);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  Starting walk at: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  instance pointer: pcb_17(D)  Outer instance pointer: pcb_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_16, 0);
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 16475);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  Starting walk at: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  instance pointer: p_16  Outer instance pointer: p_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_16, 0);
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 16475);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  Starting walk at: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  instance pointer: local_ip_7(D)  Outer instance pointer: local_ip_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_16, 0);
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 16475);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  Starting walk at: tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));
  instance pointer: remote_ip_9(D)  Outer instance pointer: remote_ip_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_output_fill_options.isra.0 (p_16, 0);
  Function call may change dynamic type:p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 16475);
  Function call may change dynamic type:_1 = lwip_htonl (seqno_10(D));
Determining dynamic type for call: _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  Starting walk at: _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  Starting walk at: _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  Starting walk at: _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  instance pointer: src_5(D)  Outer instance pointer: src_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  Starting walk at: _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  instance pointer: dst_6(D)  Outer instance pointer: dst_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_output_alloc_header.part.0 (pcb_12(D));
  Starting walk at: tcp_output_alloc_header.part.0 (pcb_12(D));
  instance pointer: pcb_12(D)  Outer instance pointer: pcb_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_19 = tcp_output_alloc_header_common (_1, optlen_15(D), datalen_16(D), seqno_be_17(D), _2, _3, 16, iftmp.18_10);
Determining dynamic type for call: _3 = tcp_rexmit (pcb_24(D));
  Starting walk at: _3 = tcp_rexmit (pcb_24(D));
  instance pointer: pcb_24(D)  Outer instance pointer: pcb_24(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = tcp_output_segment_busy (_1);
  Starting walk at: _2 = tcp_output_segment_busy (_1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_rexmit_rto_prepare (pcb_4(D));
  Starting walk at: _1 = tcp_rexmit_rto_prepare (pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_rexmit_rto_commit (pcb_4(D));
  Starting walk at: tcp_rexmit_rto_commit (pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = tcp_rexmit_rto_prepare (pcb_4(D));
Determining dynamic type for call: tcp_output (pcb_5(D));
  Starting walk at: tcp_output (pcb_5(D));
  instance pointer: pcb_5(D)  Outer instance pointer: pcb_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = tcp_output_segment_busy (seg_28);
  Starting walk at: _4 = tcp_output_segment_busy (seg_28);
  instance pointer: seg_28  Outer instance pointer: seg_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = tcp_output_segment_busy (seg_20);
Determining dynamic type for call: _2 = tcp_output_segment_busy (seg_20);
  Starting walk at: _2 = tcp_output_segment_busy (seg_20);
  instance pointer: seg_20  Outer instance pointer: seg_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = tcp_output_segment_busy (seg_20);
Determining dynamic type for call: _1 = tcp_output_segment_busy (seg_78(D));
  Starting walk at: _1 = tcp_output_segment_busy (seg_78(D));
  instance pointer: seg_78(D)  Outer instance pointer: seg_78(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_build_wnd_scale_option (opts_62);
  Starting walk at: tcp_build_wnd_scale_option (opts_62);
  instance pointer: opts_62  Outer instance pointer: opts_62 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = lwip_htons (iftmp.14_65);
  Function call may change dynamic type:_4 = lwip_htonl (_2);
  Function call may change dynamic type:_1 = tcp_output_segment_busy (seg_78(D));
  Function call may change dynamic type:_16 = lwip_htons (iftmp.15_66);
  Function call may change dynamic type:_26 = lwip_htonl (_25);
  Function call may change dynamic type:mss_94 = tcp_eff_send_mss_netif (1460, netif_81(D), _22);
Determining dynamic type for call: _5 = tcp_output.part.0 (pcb_9(D));
  Starting walk at: _5 = tcp_output.part.0 (pcb_9(D));
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_enqueue_flags.part.0 (pcb_8(D), flags_6(D));
  Starting walk at: _1 = tcp_enqueue_flags.part.0 (pcb_8(D), flags_6(D));
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _28 = tcp_enqueue_flags (pcb_19(D), 1);
  Starting walk at: _28 = tcp_enqueue_flags (pcb_19(D), 1);
  instance pointer: pcb_19(D)  Outer instance pointer: pcb_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htons (_4);
Determining dynamic type for call: seg_86 = tcp_create_segment (pcb_68(D), p_76, remainder_flags_57, _28, optflags_72);
  Starting walk at: seg_86 = tcp_create_segment (pcb_68(D), p_76, remainder_flags_57, _28, optflags_72);
  instance pointer: pcb_68(D)  Outer instance pointer: pcb_68(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_26 = lwip_htonl (_25);
  Function call may change dynamic type:_22 = lwip_htons (_21);
  Function call may change dynamic type:_19 = pbuf_copy_partial (_12, _18, remainder_74, offset_77);
  Function call may change dynamic type:p_76 = pbuf_alloc (54, _11, 640);
Determining dynamic type for call: seg_86 = tcp_create_segment (pcb_68(D), p_76, remainder_flags_57, _28, optflags_72);
  Starting walk at: seg_86 = tcp_create_segment (pcb_68(D), p_76, remainder_flags_57, _28, optflags_72);
  instance pointer: p_76  Outer instance pointer: p_76 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_26 = lwip_htonl (_25);
  Function call may change dynamic type:_22 = lwip_htons (_21);
  Function call may change dynamic type:_19 = pbuf_copy_partial (_12, _18, remainder_74, offset_77);
  Function call may change dynamic type:p_76 = pbuf_alloc (54, _11, 640);
Determining dynamic type for call: err_178 = tcp_write_checks (pcb_171(D), len_176(D));
  Starting walk at: err_178 = tcp_write_checks (pcb_171(D), len_176(D));
  instance pointer: pcb_171(D)  Outer instance pointer: pcb_171(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  Starting walk at: concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  instance pointer: &oversize  Outer instance pointer: oversize offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_178 = tcp_write_checks (pcb_171(D), len_176(D));
Determining dynamic type for call: concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  Starting walk at: concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  instance pointer: pcb_171(D)  Outer instance pointer: pcb_171(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_178 = tcp_write_checks (pcb_171(D), len_176(D));
Determining dynamic type for call: p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  Starting walk at: p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  instance pointer: &oversize  Outer instance pointer: oversize offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_178 = tcp_write_checks (pcb_171(D), len_176(D));
  Function call may change dynamic type:_205 = pbuf_clen (concat_p_202);
  Function call may change dynamic type:memcpy (_41, _43, _44);
  Function call may change dynamic type:concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  Function call may change dynamic type:_199 = pbuf_clen (concat_p_196);
  Function call may change dynamic type:concat_p_196 = pbuf_alloc (0, seglen_191, 1);
  Function call may change dynamic type:seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  Function call may change dynamic type:_247 = pbuf_clen (p_130);
  Function call may change dynamic type:memcpy (_57, _59, _60);
  Function call may change dynamic type:p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  Function call may change dynamic type:pbuf_cat (p_238, p2_235);
  Function call may change dynamic type:p_238 = pbuf_alloc (54, 0, 640);
  Function call may change dynamic type:p2_235 = pbuf_alloc (54, seglen_233, 1);
Determining dynamic type for call: p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  Starting walk at: p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  instance pointer: pcb_171(D)  Outer instance pointer: pcb_171(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_178 = tcp_write_checks (pcb_171(D), len_176(D));
  Function call may change dynamic type:_205 = pbuf_clen (concat_p_202);
  Function call may change dynamic type:memcpy (_41, _43, _44);
  Function call may change dynamic type:concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  Function call may change dynamic type:_199 = pbuf_clen (concat_p_196);
  Function call may change dynamic type:concat_p_196 = pbuf_alloc (0, seglen_191, 1);
  Function call may change dynamic type:seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  Function call may change dynamic type:_247 = pbuf_clen (p_130);
  Function call may change dynamic type:memcpy (_57, _59, _60);
  Function call may change dynamic type:p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  Function call may change dynamic type:pbuf_cat (p_238, p2_235);
  Function call may change dynamic type:p_238 = pbuf_alloc (54, 0, 640);
  Function call may change dynamic type:p2_235 = pbuf_alloc (54, seglen_233, 1);
Determining dynamic type for call: seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  Starting walk at: seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  instance pointer: pcb_171(D)  Outer instance pointer: pcb_171(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_247 = pbuf_clen (p_130);
  Function call may change dynamic type:memcpy (_57, _59, _60);
  Function call may change dynamic type:p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  Function call may change dynamic type:err_178 = tcp_write_checks (pcb_171(D), len_176(D));
  Function call may change dynamic type:_205 = pbuf_clen (concat_p_202);
  Function call may change dynamic type:memcpy (_41, _43, _44);
  Function call may change dynamic type:concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  Function call may change dynamic type:_199 = pbuf_clen (concat_p_196);
  Function call may change dynamic type:concat_p_196 = pbuf_alloc (0, seglen_191, 1);
  Function call may change dynamic type:seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  Function call may change dynamic type:_247 = pbuf_clen (p_130);
  Function call may change dynamic type:pbuf_cat (p_238, p2_235);
  Function call may change dynamic type:p_238 = pbuf_alloc (54, 0, 640);
  Function call may change dynamic type:p2_235 = pbuf_alloc (54, seglen_233, 1);
Determining dynamic type for call: seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  Starting walk at: seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  instance pointer: p_130  Outer instance pointer: p_130 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_247 = pbuf_clen (p_130);
  Function call may change dynamic type:memcpy (_57, _59, _60);
  Function call may change dynamic type:p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  Function call may change dynamic type:err_178 = tcp_write_checks (pcb_171(D), len_176(D));
  Function call may change dynamic type:_205 = pbuf_clen (concat_p_202);
  Function call may change dynamic type:memcpy (_41, _43, _44);
  Function call may change dynamic type:concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  Function call may change dynamic type:_199 = pbuf_clen (concat_p_196);
  Function call may change dynamic type:concat_p_196 = pbuf_alloc (0, seglen_191, 1);
  Function call may change dynamic type:seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  Function call may change dynamic type:_247 = pbuf_clen (p_130);
  Function call may change dynamic type:pbuf_cat (p_238, p2_235);
  Function call may change dynamic type:p_238 = pbuf_alloc (54, 0, 640);
  Function call may change dynamic type:p2_235 = pbuf_alloc (54, seglen_233, 1);
Determining dynamic type for call: _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  Starting walk at: _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  instance pointer: oversize_6(D)  Outer instance pointer: oversize_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  Starting walk at: _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  Starting walk at: _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  instance pointer: pcb_5(D)  Outer instance pointer: pcb_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  Starting walk at: _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  instance pointer: p_7(D)  Outer instance pointer: p_7(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  tcp_output.part.0/55:
    callsite  tcp_output.part.0/55 -> tcp_send_empty_ack/23 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_output.part.0/55 -> tcp_route.isra.0/51 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: ANCESTOR: 0, offset 32, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_output.part.0/55 -> tcp_send_empty_ack/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_output.part.0/55 -> tcp_output_segment/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_send_empty_ack.part.0/54:
    callsite  tcp_send_empty_ack.part.0/54 -> tcp_output_alloc_header/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_send_empty_ack.part.0/54 -> tcp_output_fill_options.isra.0/47 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_send_empty_ack.part.0/54 -> tcp_output_control_segment/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: ANCESTOR: 0, offset 32
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_enqueue_flags.part.0/53:
    callsite  tcp_enqueue_flags.part.0/53 -> tcp_create_segment/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0x9
         VR  [0, 9]
  Jump functions of caller  tcp_output_control_segment.part.0/52:
    callsite  tcp_output_control_segment.part.0/52 -> tcp_route.isra.0/51 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_route.isra.0/51:
  Jump functions of caller  tcp_output_alloc_header.part.0/50:
  Jump functions of caller  tcp_create_segment.part.0/49:
  Jump functions of caller  tcp_pbuf_prealloc.part.0/48:
  Jump functions of caller  tcp_output_fill_options.isra.0/47:
  Jump functions of caller  ip4_output_if/46:
  Jump functions of caller  ip_chksum_pseudo/45:
  Jump functions of caller  tcp_eff_send_mss_netif/43:
  Jump functions of caller  ip4_route/42:
  Jump functions of caller  netif_get_by_index/41:
  Jump functions of caller  pbuf_realloc/39:
  Jump functions of caller  pbuf_copy_partial/38:
  Jump functions of caller  lwip_htonl/37:
  Jump functions of caller  tcp_seg_free/36:
  Jump functions of caller  pbuf_add_header/35:
  Jump functions of caller  memp_malloc/34:
  Jump functions of caller  tcp_segs_free/33:
  Jump functions of caller  lwip_htons/31:
  Jump functions of caller  pbuf_cat/30:
  Jump functions of caller  pbuf_free/29:
  Jump functions of caller  pbuf_alloc/28:
  Jump functions of caller  pbuf_clen/27:
  Jump functions of caller  memcpy/26:
  Jump functions of caller  tcp_zero_window_probe/25:
    callsite  tcp_zero_window_probe/25 -> tcp_output_control_segment/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: ANCESTOR: 0, offset 32
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  tcp_zero_window_probe/25 -> tcp_output_fill_options.isra.0/47 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_zero_window_probe/25 -> tcp_output_alloc_header/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_keepalive/24:
    callsite  tcp_keepalive/24 -> tcp_output_control_segment/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: ANCESTOR: 0, offset 32
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  tcp_keepalive/24 -> tcp_output_fill_options.isra.0/47 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_keepalive/24 -> tcp_output_alloc_header/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_send_empty_ack/23:
    callsite  tcp_send_empty_ack/23 -> tcp_send_empty_ack.part.0/54 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rst/22:
    callsite  tcp_rst/22 -> tcp_output_control_segment/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_rst/22 -> tcp_output_fill_options.isra.0/47 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_rst/22 -> tcp_output_alloc_header_common/18 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: PASS THROUGH: 6, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 6: CONST: 20
         value: 0x14, mask: 0x0
         Unknown VR
       param 7: CONST: 16475
         value: 0x405b, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_output_control_segment/21:
    callsite  tcp_output_control_segment/21 -> tcp_output_control_segment.part.0/52 : 
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
  Jump functions of caller  tcp_output_alloc_header/19:
    callsite  tcp_output_alloc_header/19 -> tcp_output_alloc_header.part.0/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_output_alloc_header/19 -> tcp_output_alloc_header_common/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 6: CONST: 16
         value: 0x10, mask: 0x0
         Unknown VR
       param 7: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  tcp_output_alloc_header_common/18:
  Jump functions of caller  tcp_rexmit_fast/17:
    callsite  tcp_rexmit_fast/17 -> tcp_rexmit/16 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rexmit/16:
    callsite  tcp_rexmit/16 -> tcp_output_segment_busy/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rexmit_rto/15:
    callsite  tcp_rexmit_rto/15 -> tcp_rexmit_rto_commit/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_rexmit_rto/15 -> tcp_rexmit_rto_prepare/13 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rexmit_rto_commit/14:
    callsite  tcp_rexmit_rto_commit/14 -> tcp_output/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_rexmit_rto_prepare/13:
    callsite  tcp_rexmit_rto_prepare/13 -> tcp_output_segment_busy/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  tcp_rexmit_rto_prepare/13 -> tcp_output_segment_busy/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_output_segment/12:
    callsite  tcp_output_segment/12 -> tcp_build_wnd_scale_option/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  tcp_output_segment/12 -> tcp_output_segment_busy/11 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_output_segment_busy/11:
  Jump functions of caller  tcp_output/10:
    callsite  tcp_output/10 -> tcp_output.part.0/55 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_build_wnd_scale_option/9:
  Jump functions of caller  tcp_enqueue_flags/8:
    callsite  tcp_enqueue_flags/8 -> tcp_enqueue_flags.part.0/53 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  tcp_send_fin/7:
    callsite  tcp_send_fin/7 -> tcp_enqueue_flags/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_split_unsent_seg/6:
    callsite  tcp_split_unsent_seg/6 -> tcp_create_segment/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x9
         VR  [0, 9]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  tcp_write/5:
    callsite  tcp_write/5 -> tcp_create_segment/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  tcp_write/5 -> tcp_pbuf_prealloc/3 : 
       param 0: CONST: 54
         value: 0x36, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
       param 4: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
    callsite  tcp_write/5 -> tcp_pbuf_prealloc/3 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
       param 4: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  tcp_write/5 -> tcp_write_checks/4 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  tcp_write_checks/4:
  Jump functions of caller  tcp_pbuf_prealloc/3:
    callsite  tcp_pbuf_prealloc/3 -> tcp_pbuf_prealloc.part.0/48 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 6: PASS THROUGH: 6, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  tcp_create_segment/2:
    callsite  tcp_create_segment/2 -> tcp_create_segment.part.0/49 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR

 Propagating constants:

Not considering tcp_zero_window_probe for cloning; -fipa-cp-clone disabled.
Not considering tcp_keepalive for cloning; -fipa-cp-clone disabled.
Not considering tcp_send_empty_ack for cloning; -fipa-cp-clone disabled.
Not considering tcp_rst for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit_fast for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit_rto for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit_rto_commit for cloning; -fipa-cp-clone disabled.
Not considering tcp_rexmit_rto_prepare for cloning; -fipa-cp-clone disabled.
Not considering tcp_output for cloning; -fipa-cp-clone disabled.
Not considering tcp_enqueue_flags for cloning; -fipa-cp-clone disabled.
Not considering tcp_send_fin for cloning; -fipa-cp-clone disabled.
Not considering tcp_split_unsent_seg for cloning; -fipa-cp-clone disabled.
Not considering tcp_write for cloning; -fipa-cp-clone disabled.

overall_size: 1749, max_new_size: 11001
 - context independent values, size: 10, time_benefit: 5.199982
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 26, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 40, time_benefit: 2.393005
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: tcp_output.part.0/55:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_send_empty_ack.part.0/54:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_enqueue_flags.part.0/53:
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
  Node: tcp_output_control_segment.part.0/52:
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
  Node: tcp_route.isra.0/51:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_output_alloc_header.part.0/50:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_create_segment.part.0/49:
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
               0 [loc_time: 1, loc_size: 66, prop_time: 0, prop_size: 0]
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
               0 [loc_time: 6, loc_size: 58, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_pbuf_prealloc.part.0/48:
    param [0]: 54 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x36, mask = 0x36
         pbuf_layer [0, 54]
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
         Bits: value = 0x0, mask = 0xfffffffe
         u16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [6]: VARIABLE
               1 [loc_time: 1, loc_size: 38, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: tcp_output_fill_options.isra.0/47:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u8_t [0, 0]
        AGGS VARIABLE
  Node: tcp_zero_window_probe/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_keepalive/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_send_empty_ack/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rst/22:
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
  Node: tcp_output_control_segment/21:
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
  Node: tcp_output_alloc_header/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u16_t [0, 0]
        AGGS VARIABLE
    param [2]: VARIABLE
               0 [loc_time: 2, loc_size: 29, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u16_t [0, 1]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_output_alloc_header_common/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u16_t [0, 0]
        AGGS VARIABLE
    param [2]: VARIABLE
               0 [loc_time: 5, loc_size: 40, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u16_t [0, 1]
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
    param [5]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [6]: 16 [loc_time: 3, loc_size: 41, prop_time: 0, prop_size: 0]
               20 [loc_time: 3, loc_size: 41, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x14, mask = 0x4
         u8_t [16, 20]
        AGGS VARIABLE
    param [7]: VARIABLE
               16475 [loc_time: 3, loc_size: 42, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_rexmit_fast/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rexmit/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rexmit_rto/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rexmit_rto_commit/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_rexmit_rto_prepare/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_output_segment/12:
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
  Node: tcp_output_segment_busy/11:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_output/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_build_wnd_scale_option/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         u32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: tcp_enqueue_flags/8:
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
  Node: tcp_send_fin/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_split_unsent_seg/6:
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
  Node: tcp_write/5:
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
  Node: tcp_write_checks/4:
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
  Node: tcp_pbuf_prealloc/3:
    param [0]: 0 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
               54 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x36, mask = 0x36
         pbuf_layer [0, 54]
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
         Bits: value = 0x0, mask = 0xfffffffe
         u16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [6]: VARIABLE
               1 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: tcp_create_segment/2:
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
               0 [loc_time: 1, loc_size: 18, prop_time: 0, prop_size: 0]
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
               0 [loc_time: 1, loc_size: 18, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of tcp_output_fill_options.isra.0/47 for all known contexts.
    replacing param #1 optflags with const 0
 - Creating a specialized node of tcp_output_alloc_header/19 for all known contexts.
    replacing param #1 optlen with const 0
 - Creating a specialized node of tcp_output_alloc_header_common/18 for all known contexts.
    replacing param #1 optlen with const 0
Propagated bits info for function tcp_output_alloc_header_common.constprop/58:
 param 1: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0x1
 param 6: value = 0x14, mask = 0x4
Propagated bits info for function tcp_output_alloc_header.constprop/57:
 param 1: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0x1
Propagated bits info for function tcp_output_fill_options.isra.0.constprop/56:
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function tcp_pbuf_prealloc.part.0/48:
 param 0: value = 0x36, mask = 0x36
 param 3: value = 0x0, mask = 0xfffffffe
 param 6: value = 0x0, mask = 0x1
Propagated bits info for function tcp_output_fill_options.isra.0/47:
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function tcp_output_alloc_header/19:
 param 1: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0x1
Propagated bits info for function tcp_output_alloc_header_common/18:
 param 1: value = 0x0, mask = 0x0
 param 2: value = 0x0, mask = 0x1
 param 6: value = 0x14, mask = 0x4
Propagated bits info for function tcp_pbuf_prealloc/3:
 param 0: value = 0x36, mask = 0x36
 param 3: value = 0x0, mask = 0xfffffffe
 param 6: value = 0x0, mask = 0x1

IPA constant propagation end

Reclaiming functions: tcp_output_fill_options.isra.0/47 tcp_output_alloc_header/19 tcp_output_alloc_header_common/18
Reclaiming variables:
Clearing address taken flags:
Symbol table:

tcp_output_alloc_header_common.constprop.0/58 (tcp_output_alloc_header_common.constprop) @074d0380
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of tcp_output_alloc_header_common/18
  Availability: local
  Function flags: count:228942 (estimated locally) local optimize_size
  Called by: tcp_rst/22 (123389 (estimated locally),0.37 per call) tcp_output_alloc_header.constprop/57 (250539 (estimated locally),0.70 per call) 
  Calls: pbuf_alloc/28 (228942 (estimated locally),1.00 per call) lwip_htons/31 (52886 (estimated locally),0.23 per call) lwip_htons/31 (52886 (estimated locally),0.23 per call) lwip_htonl/37 (52886 (estimated locally),0.23 per call) lwip_htons/31 (52886 (estimated locally),0.23 per call) lwip_htons/31 (52886 (estimated locally),0.23 per call) 
tcp_output_alloc_header.constprop.0/57 (tcp_output_alloc_header.constprop) @071f2a80
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of tcp_output_alloc_header/19
  Availability: local
  Function flags: count:357913 (estimated locally) local optimize_size
  Called by: tcp_send_empty_ack.part.0/54 (1073741824 (estimated locally),1.00 per call) tcp_keepalive/24 (123389 (estimated locally),0.53 per call) tcp_zero_window_probe/25 (205217 (estimated locally),0.57 per call) 
  Calls: tcp_output_alloc_header_common.constprop/58 (250539 (estimated locally),0.70 per call) tcp_output_alloc_header.part.0/50 (175377 (estimated locally),0.49 per call) 
tcp_output_fill_options.isra.0.constprop.0/56 (tcp_output_fill_options.isra.0.constprop) @07159540
  Type: function definition analyzed
  Visibility: artificial
  References: 
  Referring: 
  Clone of tcp_output_fill_options.isra.0/47
  Availability: local
  Function flags: count:219131 (estimated locally) local optimize_size
  Called by: tcp_rst/22 (85200 (estimated locally),0.26 per call) tcp_send_empty_ack.part.0/54 (1063970774 (estimated locally),0.99 per call) tcp_keepalive/24 (122266 (estimated locally),0.53 per call) tcp_zero_window_probe/25 (204293 (estimated locally),0.57 per call) 
  Calls: 
tcp_output.part.0/55 (tcp_output.part.0) @07464380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1652822 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_output/10 (135443 (estimated locally),0.38 per call) 
  Calls: tcp_send_empty_ack/23 (253789 (estimated locally),0.15 per call) tcp_route.isra.0/51 (883764 (estimated locally),0.53 per call) lwip_htonl/37 (879787 (estimated locally),0.53 per call) tcp_send_empty_ack/23 (145165 (estimated locally),0.09 per call) lwip_htons/31 (4880636 (estimated locally),2.95 per call) lwip_htons/31 (2330442 (estimated locally),1.41 per call) tcp_output_segment/12 (4767680 (estimated locally),2.88 per call) lwip_htonl/37 (4662791 (estimated locally),2.82 per call) lwip_htons/31 (4662791 (estimated locally),2.82 per call) lwip_htons/31 (4662791 (estimated locally),2.82 per call) lwip_htonl/37 (1670440 (estimated locally),1.01 per call) lwip_htonl/37 (1670440 (estimated locally),1.01 per call) lwip_htonl/37 (3017684 (estimated locally),1.83 per call) lwip_htonl/37 (3017684 (estimated locally),1.83 per call) tcp_seg_free/36 (1538721 (estimated locally),0.93 per call) lwip_htonl/37 (4990426 (estimated locally),3.02 per call) 
tcp_send_empty_ack.part.0/54 (tcp_send_empty_ack.part.0) @074649a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_send_empty_ack/23 (123389 (estimated locally),0.53 per call) 
  Calls: lwip_htonl/37 (1073741824 (estimated locally),1.00 per call) tcp_output_alloc_header.constprop/57 (1073741824 (estimated locally),1.00 per call) tcp_output_fill_options.isra.0.constprop/56 (1063970774 (estimated locally),0.99 per call) tcp_output_control_segment/21 (1063970774 (estimated locally),0.99 per call) 
tcp_enqueue_flags.part.0/53 (tcp_enqueue_flags.part.0) @06fb29a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwip_stats/32 (read)lwip_stats/32 (write)lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: local
  Function flags: count:160984 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_enqueue_flags/8 (75162 (estimated locally),0.35 per call) 
  Calls: pbuf_alloc/28 (160984 (estimated locally),1.00 per call) tcp_create_segment/2 (52886 (estimated locally),0.33 per call) pbuf_clen/27 (13162 (estimated locally),0.08 per call) 
tcp_output_control_segment.part.0/52 (tcp_output_control_segment.part.0) @06fb2d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_output_control_segment/21 (123389 (estimated locally),0.53 per call) 
  Calls: tcp_route.isra.0/51 (1073741824 (estimated locally),1.00 per call) ip_chksum_pseudo/45 (1055058717 (estimated locally),0.98 per call) ip4_output_if/46 (1055058717 (estimated locally),0.98 per call) pbuf_free/29 (1073741824 (estimated locally),1.00 per call) 
tcp_route.isra.0/51 (tcp_route.isra.0) @06fb2380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: tcp_output.part.0/55 (883764 (estimated locally),0.53 per call) tcp_output_control_segment.part.0/52 (1073741824 (estimated locally),1.00 per call) 
  Calls: ip4_route/42 (754167267 (estimated locally),0.70 per call) netif_get_by_index/41 (319574558 (estimated locally),0.30 per call) 
tcp_output_alloc_header.part.0/50 (tcp_output_alloc_header.part.0) @072ccee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_output_alloc_header.constprop/57 (175377 (estimated locally),0.49 per call) 
  Calls: 
tcp_create_segment.part.0/49 (tcp_create_segment.part.0) @0734c460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: local
  Function flags: count:167373 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_create_segment/2 (123389 (estimated locally),0.37 per call) 
  Calls: memp_malloc/34 (167373 (estimated locally),1.00 per call) pbuf_free/29 (7113 (estimated locally),0.04 per call) pbuf_add_header/35 (52886 (estimated locally),0.32 per call) tcp_seg_free/36 (9192 (estimated locally),0.05 per call) lwip_htons/31 (43694 (estimated locally),0.26 per call) lwip_htons/31 (43694 (estimated locally),0.26 per call) lwip_htonl/37 (43694 (estimated locally),0.26 per call) lwip_htons/31 (43694 (estimated locally),0.26 per call) 
tcp_pbuf_prealloc.part.0/48 (tcp_pbuf_prealloc.part.0) @0734c7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:167221 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_pbuf_prealloc/3 (167221 (estimated locally),0.49 per call) 
  Calls: pbuf_alloc/28 (167221 (estimated locally),1.00 per call) 
tcp_output_fill_options.isra.0/47 (tcp_output_fill_options.isra.0) @06f18620
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ip4_output_if/46 (ip4_output_if) @0725eee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_control_segment.part.0/52 (1055058717 (estimated locally),0.98 per call) tcp_output_segment/12 (7989 (estimated locally),0.02 per call) 
  Calls: 
ip_chksum_pseudo/45 (ip_chksum_pseudo) @0725ee00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_control_segment.part.0/52 (1055058717 (estimated locally),0.98 per call) tcp_output_segment/12 (7989 (estimated locally),0.02 per call) 
  Calls: 
tcp_ticks/44 (tcp_ticks) @0728b828
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_output_segment/12 (read)
  Availability: not_available
  Varpool flags:
tcp_eff_send_mss_netif/43 (tcp_eff_send_mss_netif) @0725ed20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_segment/12 (15126 (estimated locally),0.04 per call) 
  Calls: 
ip4_route/42 (ip4_route) @0725e9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_route.isra.0/51 (754167267 (estimated locally),0.70 per call) 
  Calls: 
netif_get_by_index/41 (netif_get_by_index) @0725e8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_route.isra.0/51 (319574558 (estimated locally),0.30 per call) 
  Calls: 
tcp_input_pcb/40 (tcp_input_pcb) @0727e480
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_output/10 (read)
  Availability: not_available
  Varpool flags:
pbuf_realloc/39 (pbuf_realloc) @0725e0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) 
  Calls: 
pbuf_copy_partial/38 (pbuf_copy_partial) @0725e000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_zero_window_probe/25 (102147 (estimated locally),0.29 per call) tcp_split_unsent_seg/6 (8074 (estimated locally),0.03 per call) 
  Calls: 
lwip_htonl/37 (lwip_htonl) @0720e1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_zero_window_probe/25 (204293 (estimated locally),0.57 per call) tcp_keepalive/24 (123389 (estimated locally),0.53 per call) tcp_output.part.0/55 (879787 (estimated locally),0.53 per call) tcp_output.part.0/55 (4662791 (estimated locally),2.82 per call) tcp_output.part.0/55 (1670440 (estimated locally),1.01 per call) tcp_output.part.0/55 (1670440 (estimated locally),1.01 per call) tcp_output.part.0/55 (3017684 (estimated locally),1.83 per call) tcp_output.part.0/55 (3017684 (estimated locally),1.83 per call) tcp_output.part.0/55 (4990426 (estimated locally),3.02 per call) tcp_send_empty_ack.part.0/54 (1073741824 (estimated locally),1.00 per call) tcp_rst/22 (123389 (estimated locally),0.37 per call) tcp_rexmit/16 (2170276 (estimated locally),6.06 per call) tcp_rexmit/16 (2170276 (estimated locally),6.06 per call) tcp_rexmit_rto_prepare/13 (125552 (estimated locally),0.35 per call) tcp_split_unsent_seg/6 (2664 (estimated locally),0.01 per call) tcp_output_segment/12 (15126 (estimated locally),0.04 per call) tcp_output_segment/12 (15126 (estimated locally),0.04 per call) tcp_output_segment/12 (45837 (estimated locally),0.13 per call) tcp_create_segment.part.0/49 (43694 (estimated locally),0.26 per call) 
  Calls: 
tcp_seg_free/36 (tcp_seg_free) @0720eee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output.part.0/55 (1538721 (estimated locally),0.93 per call) tcp_create_segment.part.0/49 (9192 (estimated locally),0.05 per call) 
  Calls: 
pbuf_add_header/35 (pbuf_add_header) @0720ee00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_create_segment.part.0/49 (52886 (estimated locally),0.32 per call) 
  Calls: 
memp_malloc/34 (memp_malloc) @0720ed20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_create_segment.part.0/49 (167373 (estimated locally),1.00 per call) 
  Calls: 
tcp_segs_free/33 (tcp_segs_free) @0720e8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_write/5 (27397 (estimated locally),0.06 per call) 
  Calls: 
lwip_stats/32 (lwip_stats) @07221ab0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_output_segment/12 (read)tcp_output_segment/12 (write)tcp_create_segment.part.0/49 (read)tcp_create_segment.part.0/49 (write)tcp_rexmit/16 (read)tcp_rexmit/16 (write)tcp_output_control_segment.part.0/52 (read)tcp_output_control_segment.part.0/52 (write)tcp_output_segment/12 (read)tcp_output_segment/12 (write)tcp_write/5 (read)tcp_write/5 (write)tcp_enqueue_flags.part.0/53 (read)tcp_enqueue_flags.part.0/53 (write)tcp_write_checks/4 (read)tcp_write_checks/4 (write)tcp_split_unsent_seg/6 (read)tcp_split_unsent_seg/6 (write)tcp_enqueue_flags.part.0/53 (read)tcp_enqueue_flags.part.0/53 (write)tcp_rst/22 (read)tcp_rst/22 (write)
  Availability: not_available
  Varpool flags:
lwip_htons/31 (lwip_htons) @0720e7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_output_alloc_header_common.constprop/58 (52886 (estimated locally),0.23 per call) tcp_zero_window_probe/25 (102147 (estimated locally),0.29 per call) tcp_zero_window_probe/25 (205217 (estimated locally),0.57 per call) tcp_output.part.0/55 (4880636 (estimated locally),2.95 per call) tcp_output.part.0/55 (2330442 (estimated locally),1.41 per call) tcp_output.part.0/55 (4662791 (estimated locally),2.82 per call) tcp_output.part.0/55 (4662791 (estimated locally),2.82 per call) tcp_rexmit_rto_prepare/13 (125552 (estimated locally),0.35 per call) tcp_send_fin/7 (41871 (estimated locally),0.12 per call) tcp_send_fin/7 (206870 (estimated locally),0.58 per call) tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) tcp_split_unsent_seg/6 (2664 (estimated locally),0.01 per call) tcp_write/5 (1124 (estimated locally),0.00 per call) tcp_output_segment/12 (22918 (estimated locally),0.06 per call) tcp_output_segment/12 (22918 (estimated locally),0.06 per call) tcp_create_segment.part.0/49 (43694 (estimated locally),0.26 per call) tcp_create_segment.part.0/49 (43694 (estimated locally),0.26 per call) tcp_create_segment.part.0/49 (43694 (estimated locally),0.26 per call) 
  Calls: 
pbuf_cat/30 (pbuf_cat) @0720e700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_write/5 (4556 (estimated locally),0.01 per call) tcp_write/5 (376159 (estimated locally),0.80 per call) 
  Calls: 
pbuf_free/29 (pbuf_free) @0720e620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_split_unsent_seg/6 (5269 (estimated locally),0.02 per call) tcp_write/5 (27397 (estimated locally),0.06 per call) tcp_write/5 (11304 (estimated locally),0.02 per call) tcp_write/5 (7677 (estimated locally),0.02 per call) tcp_output_control_segment.part.0/52 (1073741824 (estimated locally),1.00 per call) tcp_create_segment.part.0/49 (7113 (estimated locally),0.04 per call) 
  Calls: 
pbuf_alloc/28 (pbuf_alloc) @0720e540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_output_alloc_header_common.constprop/58 (228942 (estimated locally),1.00 per call) tcp_enqueue_flags.part.0/53 (160984 (estimated locally),1.00 per call) tcp_split_unsent_seg/6 (11693 (estimated locally),0.04 per call) tcp_write/5 (383836 (estimated locally),0.81 per call) tcp_write/5 (391669 (estimated locally),0.83 per call) tcp_write/5 (8687 (estimated locally),0.02 per call) tcp_pbuf_prealloc.part.0/48 (167221 (estimated locally),1.00 per call) 
  Calls: 
pbuf_clen/27 (pbuf_clen) @0720e460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_enqueue_flags.part.0/53 (13162 (estimated locally),0.08 per call) tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) tcp_split_unsent_seg/6 (1840 (estimated locally),0.01 per call) tcp_write/5 (565213 (estimated locally),1.20 per call) tcp_write/5 (2867 (estimated locally),0.01 per call) tcp_write/5 (1767 (estimated locally),0.00 per call) 
  Calls: 
memcpy/26 (memcpy) @0720e380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_write/5 (8584 (estimated locally),0.02 per call) tcp_write/5 (189054 (estimated locally),0.40 per call) tcp_write/5 (1767 (estimated locally),0.00 per call) 
  Calls: 
tcp_zero_window_probe/25 (tcp_zero_window_probe) @07204e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_output_control_segment/21 (204293 (estimated locally),0.57 per call) tcp_output_fill_options.isra.0.constprop/56 (204293 (estimated locally),0.57 per call) lwip_htonl/37 (204293 (estimated locally),0.57 per call) pbuf_copy_partial/38 (102147 (estimated locally),0.29 per call) lwip_htons/31 (102147 (estimated locally),0.29 per call) tcp_output_alloc_header.constprop/57 (205217 (estimated locally),0.57 per call) lwip_htons/31 (205217 (estimated locally),0.57 per call) 
tcp_keepalive/24 (tcp_keepalive) @07204620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_output_control_segment/21 (122266 (estimated locally),0.53 per call) tcp_output_fill_options.isra.0.constprop/56 (122266 (estimated locally),0.53 per call) tcp_output_alloc_header.constprop/57 (123389 (estimated locally),0.53 per call) lwip_htonl/37 (123389 (estimated locally),0.53 per call) 
tcp_send_empty_ack/23 (tcp_send_empty_ack) @07204000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: tcp_output.part.0/55 (253789 (estimated locally),0.15 per call) tcp_output.part.0/55 (145165 (estimated locally),0.09 per call) 
  Calls: tcp_send_empty_ack.part.0/54 (123389 (estimated locally),0.53 per call) 
tcp_rst/22 (tcp_rst) @071f2000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: available
  Function flags: count:329661 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_output_control_segment/21 (85200 (estimated locally),0.26 per call) tcp_output_fill_options.isra.0.constprop/56 (85200 (estimated locally),0.26 per call) tcp_output_alloc_header_common.constprop/58 (123389 (estimated locally),0.37 per call) lwip_htonl/37 (123389 (estimated locally),0.37 per call) 
tcp_output_control_segment/21 (tcp_output_control_segment) @071f2d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:230763 (estimated locally) body local optimize_size
  Called by: tcp_zero_window_probe/25 (204293 (estimated locally),0.57 per call) tcp_keepalive/24 (122266 (estimated locally),0.53 per call) tcp_send_empty_ack.part.0/54 (1063970774 (estimated locally),0.99 per call) tcp_rst/22 (85200 (estimated locally),0.26 per call) 
  Calls: tcp_output_control_segment.part.0/52 (123389 (estimated locally),0.53 per call) 
tcp_output_alloc_header/19 (tcp_output_alloc_header) @071f27e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_output_alloc_header_common/18 (tcp_output_alloc_header_common) @071f2460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:228942 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_rexmit_fast/17 (tcp_rexmit_fast) @071f21c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_rexmit/16 (57875 (estimated locally),0.16 per call) 
tcp_rexmit/16 (tcp_rexmit) @071e2ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_rexmit_fast/17 (57875 (estimated locally),0.16 per call) 
  Calls: lwip_htonl/37 (2170276 (estimated locally),6.06 per call) lwip_htonl/37 (2170276 (estimated locally),6.06 per call) tcp_output_segment_busy/11 (248259 (estimated locally),0.69 per call) 
tcp_rexmit_rto/15 (tcp_rexmit_rto) @071e27e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_rexmit_rto_commit/14 (40718 (estimated locally),0.18 per call) tcp_rexmit_rto_prepare/13 (123389 (estimated locally),0.53 per call) 
tcp_rexmit_rto_commit/14 (tcp_rexmit_rto_commit) @071e2e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_rexmit_rto/15 (40718 (estimated locally),0.18 per call) 
  Calls: tcp_output/10 (250539 (estimated locally),0.70 per call) 
tcp_rexmit_rto_prepare/13 (tcp_rexmit_rto_prepare) @071e2b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_rexmit_rto/15 (123389 (estimated locally),0.53 per call) 
  Calls: lwip_htons/31 (125552 (estimated locally),0.35 per call) lwip_htonl/37 (125552 (estimated locally),0.35 per call) tcp_output_segment_busy/11 (128232 (estimated locally),0.36 per call) tcp_output_segment_busy/11 (2203265 (estimated locally),6.16 per call) 
tcp_output_segment/12 (tcp_output_segment) @071e2700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tcp_ticks/44 (read)lwip_stats/32 (read)lwip_stats/32 (write)lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_output.part.0/55 (4767680 (estimated locally),2.88 per call) 
  Calls: ip4_output_if/46 (7989 (estimated locally),0.02 per call) ip_chksum_pseudo/45 (7989 (estimated locally),0.02 per call) lwip_htonl/37 (15126 (estimated locally),0.04 per call) tcp_build_wnd_scale_option/9 (15126 (estimated locally),0.04 per call) lwip_htonl/37 (15126 (estimated locally),0.04 per call) tcp_eff_send_mss_netif/43 (15126 (estimated locally),0.04 per call) lwip_htons/31 (22918 (estimated locally),0.06 per call) lwip_htons/31 (22918 (estimated locally),0.06 per call) lwip_htonl/37 (45837 (estimated locally),0.13 per call) tcp_output_segment_busy/11 (93774 (estimated locally),0.26 per call) 
tcp_output_segment_busy/11 (tcp_output_segment_busy) @071e22a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_rexmit/16 (248259 (estimated locally),0.69 per call) tcp_rexmit_rto_prepare/13 (128232 (estimated locally),0.36 per call) tcp_rexmit_rto_prepare/13 (2203265 (estimated locally),6.16 per call) tcp_output_segment/12 (93774 (estimated locally),0.26 per call) 
  Calls: 
tcp_output/10 (tcp_output) @071e2000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_input_pcb/40 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_rexmit_rto_commit/14 (250539 (estimated locally),0.70 per call) 
  Calls: tcp_output.part.0/55 (135443 (estimated locally),0.38 per call) 
tcp_build_wnd_scale_option/9 (tcp_build_wnd_scale_option) @071c6460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_output_segment/12 (15126 (estimated locally),0.04 per call) 
  Calls: 
tcp_enqueue_flags/8 (tcp_enqueue_flags) @071c61c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: tcp_send_fin/7 (208669 (estimated locally),0.58 per call) 
  Calls: tcp_enqueue_flags.part.0/53 (75162 (estimated locally),0.35 per call) 
tcp_send_fin/7 (tcp_send_fin) @07189e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_enqueue_flags/8 (208669 (estimated locally),0.58 per call) lwip_htons/31 (41871 (estimated locally),0.12 per call) lwip_htons/31 (206870 (estimated locally),0.58 per call) 
tcp_split_unsent_seg/6 (tcp_split_unsent_seg) @07189d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: available
  Function flags: count:308170 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/29 (5269 (estimated locally),0.02 per call) pbuf_clen/27 (1840 (estimated locally),0.01 per call) pbuf_clen/27 (1840 (estimated locally),0.01 per call) lwip_htons/31 (1840 (estimated locally),0.01 per call) pbuf_realloc/39 (1840 (estimated locally),0.01 per call) pbuf_clen/27 (1840 (estimated locally),0.01 per call) tcp_create_segment/2 (2664 (estimated locally),0.01 per call) lwip_htonl/37 (2664 (estimated locally),0.01 per call) lwip_htons/31 (2664 (estimated locally),0.01 per call) pbuf_copy_partial/38 (8074 (estimated locally),0.03 per call) pbuf_alloc/28 (11693 (estimated locally),0.04 per call) 
tcp_write/5 (tcp_write) @071897e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: available
  Function flags: count:471212 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_segs_free/33 (27397 (estimated locally),0.06 per call) pbuf_free/29 (27397 (estimated locally),0.06 per call) lwip_htons/31 (1124 (estimated locally),0.00 per call) pbuf_cat/30 (4556 (estimated locally),0.01 per call) memcpy/26 (8584 (estimated locally),0.02 per call) tcp_create_segment/2 (553908 (estimated locally),1.18 per call) pbuf_free/29 (11304 (estimated locally),0.02 per call) pbuf_clen/27 (565213 (estimated locally),1.20 per call) pbuf_cat/30 (376159 (estimated locally),0.80 per call) pbuf_free/29 (7677 (estimated locally),0.02 per call) pbuf_alloc/28 (383836 (estimated locally),0.81 per call) pbuf_alloc/28 (391669 (estimated locally),0.83 per call) memcpy/26 (189054 (estimated locally),0.40 per call) tcp_pbuf_prealloc/3 (196849 (estimated locally),0.42 per call) pbuf_clen/27 (2867 (estimated locally),0.01 per call) pbuf_alloc/28 (8687 (estimated locally),0.02 per call) pbuf_clen/27 (1767 (estimated locally),0.00 per call) memcpy/26 (1767 (estimated locally),0.00 per call) tcp_pbuf_prealloc/3 (5355 (estimated locally),0.01 per call) tcp_write_checks/4 (464823 (estimated locally),0.99 per call) 
tcp_write_checks/4 (tcp_write_checks) @07159d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwip_stats/32 (read)lwip_stats/32 (write)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_write/5 (464823 (estimated locally),0.99 per call) 
  Calls: 
tcp_pbuf_prealloc/3 (tcp_pbuf_prealloc) @07159a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:341266 (estimated locally) body local optimize_size
  Called by: tcp_write/5 (196849 (estimated locally),0.42 per call) tcp_write/5 (5355 (estimated locally),0.01 per call) 
  Calls: tcp_pbuf_prealloc.part.0/48 (167221 (estimated locally),0.49 per call) 
tcp_create_segment/2 (tcp_create_segment) @071597e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:329661 (estimated locally) body local optimize_size
  Called by: tcp_enqueue_flags.part.0/53 (52886 (estimated locally),0.33 per call) tcp_split_unsent_seg/6 (2664 (estimated locally),0.01 per call) tcp_write/5 (553908 (estimated locally),1.18 per call) 
  Calls: tcp_create_segment.part.0/49 (123389 (estimated locally),0.37 per call) 

;; Function tcp_output_segment_busy (tcp_output_segment_busy, funcdef_no=11, decl_uid=7597, cgraph_uid=12, symbol_order=11)

Modification phase of node tcp_output_segment_busy/11
tcp_output_segment_busy (const struct tcp_seg * seg)
{
  struct pbuf * _1;
  unsigned char _2;
  int _3;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (seg_5(D) == 0B)
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

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = seg_5(D)->p;
  _2 = _1->ref;
  if (_2 != 1)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 125270]:
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 250539]:
  # _3 = PHI <1(5), 0(4)>
  return _3;

}



;; Function tcp_pbuf_prealloc (tcp_pbuf_prealloc, funcdef_no=3, decl_uid=7450, cgraph_uid=4, symbol_order=3)

Modification phase of node tcp_pbuf_prealloc/3
Adjusting mask for param 0 to 0x36
Adjusting mask for param 3 to 0xfffffffe
Adjusting align: 2, misalign: 0
Adjusting mask for param 6 to 0x1
Setting value range of param 0 [0, 54]
Setting nonnull for 3
Setting value range of param 6 [0, 1]
tcp_pbuf_prealloc (pbuf_layer layer, u16_t length, u16_t max_length, u16_t * oversize, const struct tcp_pcb * pcb, u8_t apiflags, u8_t first_seg)
{
  struct pbuf * _1;

  <bb 2> [local count: 341266]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG alloc => length_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (oversize_6(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 102380]:

  <bb 3> [local count: 1023801147]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1023801147]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 238887]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_8(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 8> [local count: 71666]:

  <bb 5> [local count: 716660804]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 716660804]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 167221]:
  _1 = tcp_pbuf_prealloc.part.0 (layer_12(D), length_5(D), max_length_9(D), oversize_6(D), pcb_8(D), apiflags_10(D), first_seg_11(D));
  return _1;

}



;; Function tcp_create_segment (tcp_create_segment, funcdef_no=2, decl_uid=7436, cgraph_uid=3, symbol_order=2)

Modification phase of node tcp_create_segment/2
tcp_create_segment (const struct tcp_pcb * pcb, struct pbuf * p, u8_t hdrflags, u32_t seqno, u8_t optflags)
{
  struct tcp_seg * _1;

  <bb 2> [local count: 329661]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_5(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 98898]:

  <bb 3> [local count: 988985746]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 988985746]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_7(D) == 0B)
    goto <bb 8>; [46.53%]
  else
    goto <bb 6>; [53.47%]

  <bb 8> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 123389]:
  _1 = tcp_create_segment.part.0 (pcb_5(D), p_7(D), hdrflags_10(D), seqno_9(D), optflags_8(D));
  return _1;

}



;; Function tcp_output_fill_options.isra.0.constprop (tcp_output_fill_options.isra.0.constprop.0, funcdef_no=37, decl_uid=8368, cgraph_uid=54, symbol_order=56)

Modification phase of node tcp_output_fill_options.isra.0.constprop/56
tcp_output_fill_options.isra.0.constprop (struct pbuf * p)
{
  u32_t * opts;
  struct tcp_hdr * tcphdr;
  u8_t optflags;
  sizetype _4;
  sizetype _5;
  sizetype _6;
  int _7;
  int _8;
  sizetype _9;
  sizetype _10;
  sizetype _11;
  sizetype _12;
  u8_t * _13;

  <bb 12> [local count: 219131]:
  # DEBUG optflags => 0

  <bb 2> [local count: 219131]:
  # DEBUG pcb s=> pcb
  # DEBUG num_sacks s=> num_sacks

  <bb 3> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG sacks_len => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_1(D) == 0B)
    goto <bb 4>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 4> [local count: 65739]:

  <bb 5> [local count: 657392954]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 657392954]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcphdr_2 = p_1(D)->payload;
  # DEBUG tcphdr => tcphdr_2
  # DEBUG BEGIN_STMT
  opts_3 = tcphdr_2 + 20;
  # DEBUG opts => opts_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = 0;
  _5 = _4 << 2;
  _6 = _5 & 4;
  _7 = 0;
  _8 = _7 >> 1;
  _9 = (sizetype) _8;
  _10 = _9 & 4;
  _11 = _6 + _10;
  _12 = _11 + 20;
  _13 = tcphdr_2 + _12;
  if (opts_3 != _13)
    goto <bb 8>; [70.00%]
  else
    goto <bb 11>; [30.00%]

  <bb 8> [local count: 107374]:

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 9>; [100.00%]

  <bb 11> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function tcp_output_alloc_header_common.constprop (tcp_output_alloc_header_common.constprop.0, funcdef_no=35, decl_uid=8370, cgraph_uid=56, symbol_order=58)

Modification phase of node tcp_output_alloc_header_common.constprop/58
Adjusting mask for param 2 to 0x1
Adjusting mask for param 6 to 0x4
Setting value range of param 2 [0, 1]
Setting value range of param 6 [16, 20]
tcp_output_alloc_header_common.constprop (u32_t ackno, u16_t datalen, u32_t seqno_be, u16_t src_port, u16_t dst_port, u8_t flags, u16_t wnd)
{
  struct tcp_hdr * tcphdr;
  struct pbuf * p;
  u16_t optlen;
  short unsigned int _2;
  short unsigned int _3;
  int _5;
  int _6;
  short unsigned int _7;
  int _8;
  short unsigned int _11;
  short unsigned int _13;
  long unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _21;
  short unsigned int _22;
  short unsigned int _23;
  short unsigned int _25;

  <bb 9> [local count: 228942]:
  # DEBUG optlen => 0

  <bb 2> [local count: 228942]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = datalen_1(D);
  _3 = _2 + 20;
  p_4 = pbuf_alloc (34, _3, 640);
  # DEBUG p => p_4
  # DEBUG BEGIN_STMT
  if (p_4 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 3> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = 0;
  _6 = _5 + 19;
  _7 = p_4->len;
  _8 = (int) _7;
  if (_6 >= _8)
    goto <bb 4>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 4> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcphdr_9 = p_4->payload;
  # DEBUG tcphdr => tcphdr_9
  # DEBUG BEGIN_STMT
  _11 = lwip_htons (src_port_10(D));
  tcphdr_9->src = _11;
  # DEBUG BEGIN_STMT
  _13 = lwip_htons (dst_port_12(D));
  tcphdr_9->dest = _13;
  # DEBUG BEGIN_STMT
  tcphdr_9->seqno = seqno_be_14(D);
  # DEBUG BEGIN_STMT
  _16 = lwip_htonl (ackno_15(D));
  tcphdr_9->ackno = _16;
  # DEBUG BEGIN_STMT
  _17 = 0;
  _18 = _17 + 5;
  _19 = _18 << 12;
  _21 = (short unsigned int) flags_20(D);
  _22 = _19 | _21;
  _23 = lwip_htons (_22);
  tcphdr_9->_hdrlen_rsvd_flags = _23;
  # DEBUG BEGIN_STMT
  _25 = lwip_htons (wnd_24(D));
  tcphdr_9->wnd = _25;
  # DEBUG BEGIN_STMT
  tcphdr_9->chksum = 0;
  # DEBUG BEGIN_STMT
  tcphdr_9->urgp = 0;

  <bb 8> [local count: 121568]:
  # DEBUG BEGIN_STMT
  return p_4;

}



;; Function tcp_output_alloc_header.constprop (tcp_output_alloc_header.constprop.0, funcdef_no=36, decl_uid=8369, cgraph_uid=55, symbol_order=57)

Modification phase of node tcp_output_alloc_header.constprop/57
Adjusting mask for param 2 to 0x1
Setting value range of param 2 [0, 1]
tcp_output_alloc_header.constprop (struct tcp_pcb * pcb, u16_t datalen, u32_t seqno_be)
{
  struct pbuf * p;
  u16_t optlen;
  long unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  long unsigned int _5;
  unsigned char _6;
  int _7;
  long unsigned int _8;
  long unsigned int _9;
  short unsigned int iftmp.18_10;

  <bb 11> [local count: 357913]:
  # DEBUG optlen => 0

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_1(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 3> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pcb_1(D)->rcv_nxt;
  _3 = pcb_1(D)->local_port;
  _4 = pcb_1(D)->remote_port;
  _5 = pcb_1(D)->rcv_ann_wnd;
  _6 = pcb_1(D)->rcv_scale;
  _7 = (int) _6;
  _8 = _5 >> _7;
  if (_8 <= 65534)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 125270]:

  <bb 8> [local count: 250539]:
  # _9 = PHI <65535(6), _8(7)>
  iftmp.18_10 = (short unsigned int) _9;
  p_13 = tcp_output_alloc_header_common (_2, 0, datalen_11(D), seqno_be_12(D), _3, _4, 16, iftmp.18_10);
  # DEBUG p => p_13
  # DEBUG BEGIN_STMT
  if (p_13 != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 175377]:
  # DEBUG D#3 => 0
  # DEBUG D#4 => datalen_11(D)
  # DEBUG D#5 => seqno_be_12(D)
  tcp_output_alloc_header.part.0 (pcb_1(D));

  <bb 10> [local count: 250539]:
  # DEBUG BEGIN_STMT
  return p_13;

}



;; Function tcp_output_control_segment (tcp_output_control_segment, funcdef_no=21, decl_uid=7678, cgraph_uid=22, symbol_order=21)

Modification phase of node tcp_output_control_segment/21
tcp_output_control_segment (const struct tcp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * src, const struct ip_addr_t * dst)
{
  err_t D.8321;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_2(D) == 0B)
    goto <bb 5>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  _7 = tcp_output_control_segment.part.0 (pcb_4(D), p_2(D), src_5(D), dst_6(D));
  return _7;

}



;; Function tcp_write (tcp_write, funcdef_no=5, decl_uid=7176, cgraph_uid=6, symbol_order=5)

Modification phase of node tcp_write/5
tcp_write (struct tcp_pcb * pcb, const void * arg, u16_t len, u8_t apiflags)
{
  struct pbuf * p;
  struct pbuf * p;
  struct pbuf * p2;
  u16_t seglen;
  u16_t left;
  struct pbuf * p;
  struct pbuf * p;
  u16_t seglen;
  u16_t unsent_optlen;
  u16_t space;
  u16_t mss_local;
  err_t err;
  u16_t extendlen;
  u16_t oversize_used;
  u16_t oversize;
  u16_t queuelen;
  u16_t pos;
  struct tcp_seg * queue;
  struct tcp_seg * prev_seg;
  struct tcp_seg * seg;
  struct tcp_seg * last_unsent;
  struct pbuf * concat_p;
  long unsigned int _1;
  long unsigned int _3;
  short unsigned int _5;
  int _6;
  int _7;
  struct tcp_seg * _8;
  struct tcp_seg * _9;
  unsigned char _10;
  int _11;
  int _12;
  short unsigned int _13;
  short unsigned int _14;
  int _17;
  short unsigned int _18;
  short unsigned int _19;
  int _20;
  short unsigned int _21;
  int _22;
  int _23;
  int _24;
  short unsigned int _26;
  short unsigned int _27;
  short unsigned int _31;
  short unsigned int _33;
  short unsigned int oversize.6_34;
  int _36;
  int _37;
  int _38;
  int _39;
  int _40;
  void * _41;
  sizetype _42;
  const void * _43;
  unsigned int _44;
  struct pbuf * _45;
  unsigned char _46;
  void * _47;
  short unsigned int _48;
  sizetype _49;
  const u8_t * _50;
  sizetype _51;
  const void * _52;
  short unsigned int _53;
  _Bool _54;
  unsigned char _55;
  short unsigned int _56;
  void * _57;
  sizetype _58;
  const void * _59;
  unsigned int _60;
  short unsigned int oversize.7_61;
  sizetype _62;
  const void * _63;
  long unsigned int _64;
  long unsigned int _65;
  long unsigned int _66;
  short unsigned int _67;
  short unsigned int _68;
  struct pbuf * _69;
  void * _70;
  short unsigned int _71;
  sizetype _72;
  void * _73;
  unsigned int _74;
  short unsigned int _75;
  short unsigned int _76;
  short unsigned int _77;
  short unsigned int _78;
  short unsigned int oversize.8_79;
  struct pbuf * _80;
  short unsigned int _81;
  short unsigned int _82;
  short unsigned int _83;
  struct pbuf * _84;
  short unsigned int _85;
  short unsigned int _86;
  struct pbuf * _87;
  short unsigned int _88;
  short unsigned int _89;
  short unsigned int _90;
  short unsigned int _91;
  short unsigned int _92;
  short unsigned int _93;
  long unsigned int _94;
  long unsigned int _95;
  long unsigned int _96;
  long unsigned int _97;
  long unsigned int _98;
  struct tcp_seg * _99;
  struct tcp_seg * _100;
  struct tcp_hdr * _101;
  short unsigned int _102;
  short unsigned int _103;
  struct tcp_hdr * _104;
  short unsigned int _105;
  short unsigned int _106;
  short unsigned int _107;
  short unsigned int _108;
  short unsigned int _109;
  short unsigned int _110;
  struct tcp_seg * _111;
  struct tcp_seg * _112;
  err_t _133;
  int iftmp.0_134;
  u16_t iftmp.1_135;
  long unsigned int _163;
  unsigned char _164;
  unsigned char _165;
  int _166;
  unsigned char _167;
  unsigned char _168;
  int iftmp.0_172;
  short unsigned int _199;
  short unsigned int _205;
  short unsigned int _247;

  <bb 2> [local count: 471212]:
  # DEBUG BEGIN_STMT
  # DEBUG concat_p => 0B
  # DEBUG BEGIN_STMT
  # DEBUG last_unsent => 0B
  # DEBUG seg => 0B
  # DEBUG prev_seg => 0B
  # DEBUG queue => 0B
  # DEBUG BEGIN_STMT
  # DEBUG pos => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optflags => 0
  # DEBUG BEGIN_STMT
  oversize = 0;
  # DEBUG BEGIN_STMT
  # DEBUG oversize_used => 0
  # DEBUG BEGIN_STMT
  # DEBUG extendlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_171(D) == 0B)
    goto <bb 101>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 469091]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_171(D)->snd_wnd_max;
  if (_1 <= 131069)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 234546]:
  _3 = _1 >> 1;
  _163 = _3;
  iftmp.0_172 = (int) _163;

  <bb 5> [local count: 469091]:
  # iftmp.0_134 = PHI <iftmp.0_172(4), 65535(3)>
  _5 = pcb_171(D)->mss;
  _6 = (int) _5;
  _7 = MIN_EXPR <_6, iftmp.0_134>;
  mss_local_173 = (u16_t) _7;
  # DEBUG mss_local => mss_local_173
  # DEBUG BEGIN_STMT
  if (mss_local_173 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 234546]:

  <bb 7> [local count: 469091]:
  # iftmp.1_135 = PHI <_5(6), mss_local_173(5)>
  # DEBUG mss_local => iftmp.1_135
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_175(D) == 0B)
    goto <bb 101>; [0.91%]
  else
    goto <bb 8>; [99.09%]

  <bb 8> [local count: 464823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  err_178 = tcp_write_checks (pcb_171(D), len_176(D));
  # DEBUG err => err_178
  # DEBUG BEGIN_STMT
  if (err_178 != 0)
    goto <bb 101>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 9> [local count: 306783]:
  # DEBUG BEGIN_STMT
  queuelen_179 = pcb_171(D)->snd_queuelen;
  # DEBUG queuelen => queuelen_179
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  _8 = pcb_171(D)->unsent;
  if (_8 != 0B)
    goto <bb 113>; [70.00%]
  else
    goto <bb 37>; [30.00%]

  <bb 113> [local count: 214748]:

  <bb 10> [local count: 1952255]:
  # last_unsent_115 = PHI <_8(113), _9(127)>
  # DEBUG last_unsent => last_unsent_115
  # DEBUG BEGIN_STMT
  _9 = last_unsent_115->next;
  if (_9 != 0B)
    goto <bb 127>; [89.00%]
  else
    goto <bb 11>; [11.00%]

  <bb 127> [local count: 1737507]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 214748]:
  # last_unsent_2 = PHI <last_unsent_115(10)>
  # DEBUG BEGIN_STMT
  _10 = last_unsent_2->flags;
  _11 = (int) _10;
  _12 = _11 << 2;
  _13 = (short unsigned int) _12;
  _14 = _13 & 4;
  _17 = _11 >> 1;
  _18 = (short unsigned int) _17;
  _19 = _18 & 4;
  unsent_optlen_182 = _14 + _19;
  # DEBUG unsent_optlen => unsent_optlen_182
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = (int) iftmp.1_135;
  _21 = last_unsent_2->len;
  _22 = (int) _21;
  _23 = (int) unsent_optlen_182;
  _24 = _22 + _23;
  if (_20 < _24)
    goto <bb 102>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 102> [local count: 107374]:

  <bb 12> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 115> [local count: 1073741824]:
  goto <bb 12>; [100.00%]

  <bb 13> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _26 = _21 + unsent_optlen_182;
  space_183 = iftmp.1_135 - _26;
  # DEBUG space => space_183
  # DEBUG BEGIN_STMT
  _27 = pcb_171(D)->unsent_oversize;
  oversize = _27;
  # DEBUG BEGIN_STMT
  if (_27 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 14> [local count: 53687]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_27 > space_183)
    goto <bb 103>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 103> [local count: 26844]:

  <bb 15> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 116> [local count: 268435456]:
  goto <bb 15>; [100.00%]

  <bb 16> [local count: 26843]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG seg => last_unsent_2
  # DEBUG BEGIN_STMT
  _31 = MIN_EXPR <_27, len_176(D)>;
  oversize_used_186 = MIN_EXPR <_31, space_183>;
  # DEBUG oversize_used => oversize_used_186
  # DEBUG BEGIN_STMT
  # DEBUG pos => oversize_used_186
  # DEBUG BEGIN_STMT
  _33 = _27 - oversize_used_186;
  oversize = _33;
  # DEBUG BEGIN_STMT
  space_188 = space_183 - oversize_used_186;
  # DEBUG space => space_188

  <bb 17> [local count: 80530]:
  # seg_116 = PHI <0B(13), last_unsent_2(16)>
  # pos_122 = PHI <0(13), oversize_used_186(16)>
  # space_128 = PHI <space_183(13), space_188(16)>
  # DEBUG space => space_128
  # DEBUG oversize_used => pos_122
  # DEBUG pos => pos_122
  # DEBUG seg => seg_116
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oversize.6_34 = oversize;
  if (oversize.6_34 != 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 18> [local count: 40265]:
  if (pos_122 != len_176(D))
    goto <bb 104>; [66.00%]
  else
    goto <bb 20>; [34.00%]

  <bb 104> [local count: 26575]:

  <bb 19> [local count: 265751101]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 117> [local count: 265751101]:
  goto <bb 19>; [100.00%]

  <bb 20> [local count: 53955]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pos_122 < len_176(D))
    goto <bb 21>; [67.00%]
  else
    goto <bb 61>; [33.00%]

  <bb 21> [local count: 36150]:
  if (space_128 != 0)
    goto <bb 22>; [67.00%]
  else
    goto <bb 61>; [33.00%]

  <bb 22> [local count: 24221]:
  if (_21 != 0)
    goto <bb 23>; [67.00%]
  else
    goto <bb 61>; [33.00%]

  <bb 23> [local count: 16228]:
  # DEBUG BEGIN_STMT
  _36 = (int) len_176(D);
  _37 = (int) pos_122;
  _38 = _36 - _37;
  _39 = (int) space_128;
  _40 = MIN_EXPR <_38, _39>;
  seglen_191 = (u16_t) _40;
  # DEBUG seglen => seglen_191
  # DEBUG BEGIN_STMT
  # DEBUG seg => last_unsent_2
  # DEBUG BEGIN_STMT
  _164 = apiflags_192(D) & 1;
  if (_164 != 0)
    goto <bb 24>; [33.00%]
  else
    goto <bb 27>; [67.00%]

  <bb 24> [local count: 5355]:
  # DEBUG BEGIN_STMT
  concat_p_202 = tcp_pbuf_prealloc (0, seglen_191, space_128, &oversize, pcb_171(D), apiflags_192(D), 1);
  # DEBUG concat_p => concat_p_202
  if (concat_p_202 == 0B)
    goto <bb 25>; [67.00%]
  else
    goto <bb 26>; [33.00%]

  <bb 25> [local count: 3588]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 93>; [100.00%]

  <bb 26> [local count: 1767]:
  # DEBUG BEGIN_STMT
  _41 = concat_p_202->payload;
  _42 = (sizetype) pos_122;
  _43 = arg_175(D) + _42;
  _166 = _40 & 65535;
  _44 = (unsigned int) _166;
  memcpy (_41, _43, _44);
  # DEBUG BEGIN_STMT
  _205 = pbuf_clen (concat_p_202);
  queuelen_206 = queuelen_179 + _205;
  # DEBUG queuelen => queuelen_206
  goto <bb 36>; [100.00%]

  <bb 27> [local count: 10873]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p_193 = last_unsent_2->p;
  # DEBUG p => p_193

  <bb 28> [local count: 98842]:
  # p_129 = PHI <p_193(27), _45(126)>
  # DEBUG p => p_129
  # DEBUG BEGIN_STMT
  _45 = p_129->next;
  if (_45 != 0B)
    goto <bb 126>; [89.00%]
  else
    goto <bb 29>; [11.00%]

  <bb 126> [local count: 87969]:
  goto <bb 28>; [100.00%]

  <bb 29> [local count: 10873]:
  # p_30 = PHI <p_129(28)>
  # DEBUG BEGIN_STMT
  _46 = p_30->type_internal;
  _165 = _46 & 192;
  if (_165 == 0)
    goto <bb 30>; [67.00%]
  else
    goto <bb 33>; [33.00%]

  <bb 30> [local count: 7285]:
  _47 = p_30->payload;
  _48 = p_30->len;
  _49 = (sizetype) _48;
  _50 = _47 + _49;
  if (_50 == arg_175(D))
    goto <bb 31>; [30.00%]
  else
    goto <bb 33>; [70.00%]

  <bb 31> [local count: 2185]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pos_122 != 0)
    goto <bb 112>; [67.00%]
  else
    goto <bb 36>; [33.00%]

  <bb 112> [local count: 1464]:

  <bb 32> [local count: 14642189]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 125> [local count: 14642189]:
  goto <bb 32>; [100.00%]

  <bb 33> [local count: 8687]:
  # DEBUG BEGIN_STMT
  concat_p_196 = pbuf_alloc (0, seglen_191, 1);
  # DEBUG concat_p => concat_p_196
  if (concat_p_196 == 0B)
    goto <bb 34>; [67.00%]
  else
    goto <bb 35>; [33.00%]

  <bb 34> [local count: 5820]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 93>; [100.00%]

  <bb 35> [local count: 2867]:
  # DEBUG BEGIN_STMT
  _51 = (sizetype) pos_122;
  _52 = arg_175(D) + _51;
  MEM[(struct pbuf_rom *)concat_p_196].payload = _52;
  # DEBUG BEGIN_STMT
  _199 = pbuf_clen (concat_p_196);
  queuelen_200 = queuelen_179 + _199;
  # DEBUG queuelen => queuelen_200

  <bb 36> [local count: 5355]:
  # concat_p_113 = PHI <concat_p_202(26), 0B(31), concat_p_196(35)>
  # queuelen_124 = PHI <queuelen_206(26), queuelen_179(31), queuelen_200(35)>
  # extendlen_127 = PHI <0(26), seglen_191(31), 0(35)>
  # DEBUG extendlen => extendlen_127
  # DEBUG queuelen => queuelen_124
  # DEBUG concat_p => concat_p_113
  # DEBUG BEGIN_STMT
  pos_207 = pos_122 + seglen_191;
  # DEBUG pos => pos_207
  goto <bb 61>; [100.00%]

  <bb 37> [local count: 92035]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _53 = pcb_171(D)->unsent_oversize;
  if (_53 != 0)
    goto <bb 114>; [67.00%]
  else
    goto <bb 61>; [33.00%]

  <bb 114> [local count: 61663]:

  <bb 38> [local count: 616634588]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 128> [local count: 616634588]:
  goto <bb 38>; [100.00%]

  <bb 39> [local count: 596511]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  left_232 = len_176(D) - pos_123;
  # DEBUG left => left_232
  # DEBUG BEGIN_STMT
  # DEBUG max_len => iftmp.1_135
  # DEBUG BEGIN_STMT
  seglen_233 = MIN_EXPR <iftmp.1_135, left_232>;
  # DEBUG seglen => seglen_233
  # DEBUG BEGIN_STMT
  _168 = apiflags_192(D) & 1;
  if (_168 != 0)
    goto <bb 40>; [33.00%]
  else
    goto <bb 45>; [67.00%]

  <bb 40> [local count: 196849]:
  # DEBUG BEGIN_STMT
  _54 = queue_120 == 0B;
  _55 = (unsigned char) _54;
  p_243 = tcp_pbuf_prealloc (54, seglen_233, iftmp.1_135, &oversize, pcb_171(D), apiflags_192(D), _55);
  # DEBUG p => p_243
  if (p_243 == 0B)
    goto <bb 41>; [2.00%]
  else
    goto <bb 42>; [98.00%]

  <bb 41> [local count: 3937]:
  # queue_181 = PHI <queue_120(40)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 93>; [100.00%]

  <bb 42> [local count: 192912]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _56 = p_243->len;
  if (_56 < seglen_233)
    goto <bb 106>; [2.00%]
  else
    goto <bb 44>; [98.00%]

  <bb 106> [local count: 3858]:

  <bb 43> [local count: 38582415]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 119> [local count: 38582415]:
  goto <bb 43>; [100.00%]

  <bb 44> [local count: 189054]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _57 = p_243->payload;
  _58 = (sizetype) pos_123;
  _59 = arg_175(D) + _58;
  _60 = (unsigned int) seglen_233;
  memcpy (_57, _59, _60);
  goto <bb 52>; [100.00%]

  <bb 45> [local count: 399663]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  oversize.7_61 = oversize;
  if (oversize.7_61 != 0)
    goto <bb 108>; [2.00%]
  else
    goto <bb 47>; [98.00%]

  <bb 108> [local count: 7993]:

  <bb 46> [local count: 79932647]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 121> [local count: 79932647]:
  goto <bb 46>; [100.00%]

  <bb 47> [local count: 391669]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p2_235 = pbuf_alloc (54, seglen_233, 1);
  # DEBUG p2 => p2_235
  if (p2_235 == 0B)
    goto <bb 48>; [2.00%]
  else
    goto <bb 49>; [98.00%]

  <bb 48> [local count: 7833]:
  # queue_15 = PHI <queue_120(47)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 93>; [100.00%]

  <bb 49> [local count: 383836]:
  # DEBUG BEGIN_STMT
  _62 = (sizetype) pos_123;
  _63 = arg_175(D) + _62;
  MEM[(struct pbuf_rom *)p2_235].payload = _63;
  # DEBUG BEGIN_STMT
  p_238 = pbuf_alloc (54, 0, 640);
  # DEBUG p => p_238
  if (p_238 == 0B)
    goto <bb 50>; [2.00%]
  else
    goto <bb 51>; [98.00%]

  <bb 50> [local count: 7677]:
  # queue_16 = PHI <queue_120(49)>
  # p2_35 = PHI <p2_235(49)>
  # DEBUG BEGIN_STMT
  pbuf_free (p2_35);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 93>; [100.00%]

  <bb 51> [local count: 376159]:
  # DEBUG BEGIN_STMT
  pbuf_cat (p_238, p2_235);

  <bb 52> [local count: 565213]:
  # p_130 = PHI <p_243(44), p_238(51)>
  # DEBUG p => p_130
  # DEBUG BEGIN_STMT
  _247 = pbuf_clen (p_130);
  queuelen_248 = queuelen_125 + _247;
  # DEBUG queuelen => queuelen_248
  # DEBUG BEGIN_STMT
  if (queuelen_248 > 128)
    goto <bb 53>; [2.00%]
  else
    goto <bb 54>; [98.00%]

  <bb 53> [local count: 11304]:
  # queue_25 = PHI <queue_120(52)>
  # p_32 = PHI <p_130(52)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_32);
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 93>; [100.00%]

  <bb 54> [local count: 553908]:
  # DEBUG BEGIN_STMT
  _64 = pcb_171(D)->snd_lbb;
  _65 = (long unsigned int) pos_123;
  _66 = _64 + _65;
  seg_250 = tcp_create_segment (pcb_171(D), p_130, 0, _66, 0);
  # DEBUG seg => seg_250
  if (seg_250 == 0B)
    goto <bb 55>; [2.00%]
  else
    goto <bb 56>; [98.00%]

  <bb 55> [local count: 11078]:
  # queue_28 = PHI <queue_120(54)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 93>; [100.00%]

  <bb 56> [local count: 542830]:
  # DEBUG BEGIN_STMT
  if (queue_120 == 0B)
    goto <bb 60>; [30.00%]
  else
    goto <bb 57>; [70.00%]

  <bb 57> [local count: 379981]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (prev_seg_118 == 0B)
    goto <bb 107>; [2.00%]
  else
    goto <bb 59>; [98.00%]

  <bb 107> [local count: 7600]:

  <bb 58> [local count: 75996370]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 120> [local count: 75996370]:
  goto <bb 58>; [100.00%]

  <bb 59> [local count: 372382]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  prev_seg_118->next = seg_250;

  <bb 60> [local count: 535231]:
  # queue_119 = PHI <seg_250(56), queue_120(59)>
  # DEBUG queue => queue_119
  # DEBUG BEGIN_STMT
  # DEBUG prev_seg => seg_250
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pos_253 = pos_123 + seglen_233;
  # DEBUG pos => pos_253
  goto <bb 62>; [100.00%]

  <bb 61> [local count: 73454]:
  # concat_p_261 = PHI <0B(37), 0B(20), 0B(21), 0B(22), concat_p_113(36)>
  # last_unsent_262 = PHI <0B(37), last_unsent_2(20), last_unsent_2(21), last_unsent_2(22), last_unsent_2(36)>
  # seg_263 = PHI <0B(37), seg_116(20), seg_116(21), seg_116(22), last_unsent_2(36)>
  # pos_264 = PHI <0(37), pos_122(20), pos_122(21), pos_122(22), pos_207(36)>
  # queuelen_265 = PHI <queuelen_179(37), queuelen_179(20), queuelen_179(21), queuelen_179(22), queuelen_124(36)>
  # oversize_used_266 = PHI <0(37), pos_122(20), pos_122(21), pos_122(22), pos_122(36)>
  # extendlen_267 = PHI <0(37), 0(20), 0(21), 0(22), extendlen_127(36)>

  <bb 62> [local count: 608685]:
  # seg_117 = PHI <seg_263(61), seg_250(60)>
  # prev_seg_118 = PHI <0B(61), seg_250(60)>
  # queue_120 = PHI <0B(61), queue_119(60)>
  # pos_123 = PHI <pos_264(61), pos_253(60)>
  # queuelen_125 = PHI <queuelen_265(61), queuelen_248(60)>
  # DEBUG extendlen => extendlen_267
  # DEBUG oversize_used => oversize_used_266
  # DEBUG queuelen => queuelen_125
  # DEBUG pos => pos_123
  # DEBUG queue => queue_120
  # DEBUG prev_seg => prev_seg_118
  # DEBUG seg => seg_117
  # DEBUG last_unsent => last_unsent_262
  # DEBUG concat_p => concat_p_261
  # DEBUG BEGIN_STMT
  if (pos_123 < len_176(D))
    goto <bb 39>; [98.00%]
  else
    goto <bb 63>; [2.00%]

  <bb 63> [local count: 12174]:
  # seg_174 = PHI <seg_117(62)>
  # queue_29 = PHI <queue_120(62)>
  # queuelen_185 = PHI <queuelen_125(62)>
  # DEBUG BEGIN_STMT
  if (oversize_used_266 != 0)
    goto <bb 64>; [50.00%]
  else
    goto <bb 70>; [50.00%]

  <bb 64> [local count: 6087]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p_209 = last_unsent_262->p;
  # DEBUG p => p_209
  goto <bb 68>; [100.00%]

  <bb 65> [local count: 49248]:
  # DEBUG BEGIN_STMT
  _67 = p_131->tot_len;
  _68 = _67 + oversize_used_266;
  p_131->tot_len = _68;
  # DEBUG BEGIN_STMT
  _69 = p_131->next;
  if (_69 == 0B)
    goto <bb 66>; [17.43%]
  else
    goto <bb 67>; [82.57%]

  <bb 66> [local count: 8584]:
  # DEBUG BEGIN_STMT
  _70 = p_131->payload;
  _71 = p_131->len;
  _72 = (sizetype) _71;
  _73 = _70 + _72;
  _74 = (unsigned int) oversize_used_266;
  memcpy (_73, arg_175(D), _74);
  # DEBUG BEGIN_STMT
  _75 = p_131->len;
  _76 = _75 + oversize_used_266;
  p_131->len = _76;

  <bb 67> [local count: 49248]:
  # DEBUG BEGIN_STMT
  p_214 = p_131->next;
  # DEBUG p => p_214

  <bb 68> [local count: 55335]:
  # p_131 = PHI <p_209(64), p_214(67)>
  # DEBUG p => p_131
  # DEBUG BEGIN_STMT
  if (p_131 != 0B)
    goto <bb 65>; [89.00%]
  else
    goto <bb 69>; [11.00%]

  <bb 69> [local count: 6087]:
  # DEBUG BEGIN_STMT
  _77 = last_unsent_262->len;
  _78 = _77 + oversize_used_266;
  last_unsent_262->len = _78;

  <bb 70> [local count: 12174]:
  # DEBUG BEGIN_STMT
  oversize.8_79 = oversize;
  pcb_171(D)->unsent_oversize = oversize.8_79;
  # DEBUG BEGIN_STMT
  if (concat_p_261 != 0B)
    goto <bb 71>; [70.00%]
  else
    goto <bb 74>; [30.00%]

  <bb 71> [local count: 8522]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (last_unsent_262 == 0B)
    goto <bb 109>; [46.53%]
  else
    goto <bb 73>; [53.47%]

  <bb 109> [local count: 3965]:

  <bb 72> [local count: 39651025]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 122> [local count: 39651025]:
  goto <bb 72>; [100.00%]

  <bb 73> [local count: 4556]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _80 = last_unsent_262->p;
  pbuf_cat (_80, concat_p_261);
  # DEBUG BEGIN_STMT
  _81 = last_unsent_262->len;
  _82 = concat_p_261->tot_len;
  _83 = _81 + _82;
  last_unsent_262->len = _83;
  goto <bb 82>; [100.00%]

  <bb 74> [local count: 3652]:
  # DEBUG BEGIN_STMT
  if (extendlen_267 != 0)
    goto <bb 75>; [50.00%]
  else
    goto <bb 82>; [50.00%]

  <bb 75> [local count: 1826]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (last_unsent_262 == 0B)
    goto <bb 76>; [30.00%]
  else
    goto <bb 77>; [70.00%]

  <bb 76> [local count: 931]:
  goto <bb 78>; [100.00%]

  <bb 77> [local count: 1278]:
  _84 = last_unsent_262->p;
  if (_84 == 0B)
    goto <bb 76>; [30.00%]
  else
    goto <bb 111>; [70.00%]

  <bb 111> [local count: 895]:
  goto <bb 80>; [100.00%]

  <bb 124> [local count: 9312896]:

  <bb 78> [local count: 9312896]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT
  goto <bb 124>; [100.00%]

  <bb 79> [local count: 7239]:
  # DEBUG BEGIN_STMT
  _85 = p_132->tot_len;
  _86 = _85 + extendlen_267;
  p_132->tot_len = _86;
  # DEBUG BEGIN_STMT
  # DEBUG p => _87

  <bb 80> [local count: 8134]:
  # p_132 = PHI <_87(79), _84(111)>
  # DEBUG p => p_132
  # DEBUG BEGIN_STMT
  _87 = p_132->next;
  if (_87 != 0B)
    goto <bb 79>; [89.00%]
  else
    goto <bb 81>; [11.00%]

  <bb 81> [local count: 895]:
  # p_126 = PHI <p_132(80)>
  # DEBUG BEGIN_STMT
  _88 = p_126->tot_len;
  _89 = _88 + extendlen_267;
  p_126->tot_len = _89;
  # DEBUG BEGIN_STMT
  _90 = p_126->len;
  _91 = _90 + extendlen_267;
  p_126->len = _91;
  # DEBUG BEGIN_STMT
  _92 = last_unsent_262->len;
  _93 = _92 + extendlen_267;
  last_unsent_262->len = _93;

  <bb 82> [local count: 7277]:
  # DEBUG BEGIN_STMT
  if (last_unsent_262 == 0B)
    goto <bb 83>; [30.00%]
  else
    goto <bb 84>; [70.00%]

  <bb 83> [local count: 2183]:
  # DEBUG BEGIN_STMT
  pcb_171(D)->unsent = queue_29;
  goto <bb 85>; [100.00%]

  <bb 84> [local count: 5094]:
  # DEBUG BEGIN_STMT
  last_unsent_262->next = queue_29;

  <bb 85> [local count: 7277]:
  # DEBUG BEGIN_STMT
  _94 = pcb_171(D)->snd_lbb;
  _95 = (long unsigned int) len_176(D);
  _96 = _94 + _95;
  pcb_171(D)->snd_lbb = _96;
  # DEBUG BEGIN_STMT
  _97 = pcb_171(D)->snd_buf;
  _98 = _97 - _95;
  pcb_171(D)->snd_buf = _98;
  # DEBUG BEGIN_STMT
  pcb_171(D)->snd_queuelen = queuelen_185;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (queuelen_185 != 0)
    goto <bb 86>; [50.00%]
  else
    goto <bb 89>; [50.00%]

  <bb 86> [local count: 3639]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _99 = pcb_171(D)->unacked;
  if (_99 == 0B)
    goto <bb 87>; [30.00%]
  else
    goto <bb 89>; [70.00%]

  <bb 87> [local count: 1092]:
  _100 = pcb_171(D)->unsent;
  if (_100 == 0B)
    goto <bb 110>; [30.00%]
  else
    goto <bb 89>; [70.00%]

  <bb 110> [local count: 328]:

  <bb 88> [local count: 3274798]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 123> [local count: 3274798]:
  goto <bb 88>; [100.00%]

  <bb 89> [local count: 6950]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (seg_174 != 0B)
    goto <bb 90>; [70.00%]
  else
    goto <bb 101>; [30.00%]

  <bb 90> [local count: 4865]:
  _101 = seg_174->tcphdr;
  if (_101 != 0B)
    goto <bb 91>; [70.00%]
  else
    goto <bb 101>; [30.00%]

  <bb 91> [local count: 3405]:
  _167 = apiflags_192(D) & 2;
  if (_167 == 0)
    goto <bb 92>; [33.00%]
  else
    goto <bb 101>; [67.00%]

  <bb 92> [local count: 1124]:
  # DEBUG BEGIN_STMT
  _102 = _101->_hdrlen_rsvd_flags;
  _103 = lwip_htons (8);
  _104 = seg_174->tcphdr;
  _105 = _102 | _103;
  _104->_hdrlen_rsvd_flags = _105;
  goto <bb 101>; [100.00%]

  <bb 93> [local count: 51238]:
  # concat_p_114 = PHI <0B(25), 0B(34), concat_p_261(41), concat_p_261(48), concat_p_261(50), concat_p_261(53), concat_p_261(55)>
  # queue_121 = PHI <0B(25), 0B(34), queue_181(41), queue_15(48), queue_16(50), queue_25(53), queue_28(55)>
memerr:
  # DEBUG queue => queue_121
  # DEBUG concat_p => concat_p_114
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _106 = pcb_171(D)->flags;
  _107 = _106 | 128;
  pcb_171(D)->flags = _107;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _108 = lwip_stats.tcp.memerr;
  _109 = _108 + 1;
  lwip_stats.tcp.memerr = _109;
  # DEBUG BEGIN_STMT
  if (concat_p_114 != 0B)
    goto <bb 94>; [53.47%]
  else
    goto <bb 95>; [46.53%]

  <bb 94> [local count: 27397]:
  # DEBUG BEGIN_STMT
  pbuf_free (concat_p_114);

  <bb 95> [local count: 51238]:
  # DEBUG BEGIN_STMT
  if (queue_121 != 0B)
    goto <bb 96>; [53.47%]
  else
    goto <bb 97>; [46.53%]

  <bb 96> [local count: 27397]:
  # DEBUG BEGIN_STMT
  tcp_segs_free (queue_121);

  <bb 97> [local count: 51238]:
  # DEBUG BEGIN_STMT
  _110 = pcb_171(D)->snd_queuelen;
  if (_110 != 0)
    goto <bb 98>; [98.00%]
  else
    goto <bb 101>; [2.00%]

  <bb 98> [local count: 50213]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _111 = pcb_171(D)->unacked;
  if (_111 == 0B)
    goto <bb 99>; [95.45%]
  else
    goto <bb 101>; [4.55%]

  <bb 99> [local count: 47928]:
  _112 = pcb_171(D)->unsent;
  if (_112 == 0B)
    goto <bb 105>; [95.45%]
  else
    goto <bb 101>; [4.55%]

  <bb 105> [local count: 45747]:

  <bb 100> [local count: 457477875]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 118> [local count: 457477875]:
  goto <bb 100>; [100.00%]

  <bb 101> [local count: 176869]:
  # _133 = PHI <-16(2), -16(7), err_178(8), 0(90), -1(98), -1(97), -1(99), 0(89), 0(92), 0(91)>
  oversize ={v} {CLOBBER};
  return _133;

}



;; Function tcp_split_unsent_seg (tcp_split_unsent_seg, funcdef_no=6, decl_uid=7283, cgraph_uid=7, symbol_order=6)

Modification phase of node tcp_split_unsent_seg/6
tcp_split_unsent_seg (struct tcp_pcb * pcb, u16_t split)
{
  u16_t offset;
  u16_t remainder;
  u8_t remainder_flags;
  u8_t split_flags;
  u8_t optflags;
  u8_t optlen;
  struct pbuf * p;
  struct tcp_seg * useg;
  struct tcp_seg * seg;
  short unsigned int _1;
  short unsigned int _2;
  int _3;
  int _4;
  unsigned char _5;
  unsigned char _6;
  int _7;
  unsigned char _8;
  unsigned char _9;
  short unsigned int _10;
  short unsigned int _11;
  struct pbuf * _12;
  short unsigned int _13;
  short unsigned int _14;
  short unsigned int _15;
  void * _16;
  sizetype _17;
  void * _18;
  short unsigned int _19;
  struct tcp_hdr * _20;
  short unsigned int _21;
  short unsigned int _22;
  unsigned char _23;
  struct tcp_hdr * _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  struct pbuf * _29;
  short unsigned int _30;
  short unsigned int _31;
  struct pbuf * _32;
  short unsigned int _33;
  short unsigned int _34;
  short unsigned int _35;
  short unsigned int _36;
  struct tcp_hdr * _37;
  short unsigned int _38;
  short unsigned int _39;
  short unsigned int _40;
  struct tcp_hdr * _41;
  short unsigned int _42;
  struct pbuf * _43;
  short unsigned int _44;
  short unsigned int _45;
  struct pbuf * _46;
  short unsigned int _47;
  short unsigned int _48;
  struct tcp_seg * _49;
  struct tcp_seg * _50;
  short unsigned int _51;
  short unsigned int _52;
  err_t _58;
  unsigned char _65;
  unsigned char _66;
  short unsigned int _67;
  short unsigned int _88;
  short unsigned int _95;
  short unsigned int _98;

  <bb 2> [local count: 308170]:
  # DEBUG BEGIN_STMT
  # DEBUG seg => 0B
  # DEBUG useg => 0B
  # DEBUG BEGIN_STMT
  # DEBUG p => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_68(D) == 0B)
    goto <bb 27>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 27> [local count: 92451]:

  <bb 3> [local count: 924510431]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 31> [local count: 924510431]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 215719]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  useg_70 = pcb_68(D)->unsent;
  # DEBUG useg => useg_70
  # DEBUG BEGIN_STMT
  if (useg_70 == 0B)
    goto <bb 26>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 214748]:
  # DEBUG BEGIN_STMT
  if (split_71(D) == 0)
    goto <bb 28>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 28> [local count: 107374]:

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 32> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 107374]:
  # DEBUG BEGIN_STMT
  _1 = useg_70->len;
  if (_1 <= split_71(D))
    goto <bb 26>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 8> [local count: 70867]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pcb_68(D)->mss;
  if (_2 < split_71(D))
    goto <bb 29>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 29> [local count: 35434]:

  <bb 9> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 354334802]:
  goto <bb 9>; [100.00%]

  <bb 10> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_1 == 0)
    goto <bb 30>; [67.00%]
  else
    goto <bb 12>; [33.00%]

  <bb 30> [local count: 23740]:

  <bb 11> [local count: 237404317]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 34> [local count: 237404317]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 11693]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  optflags_72 = useg_70->flags;
  # DEBUG optflags => optflags_72
  # DEBUG BEGIN_STMT
  _3 = (int) optflags_72;
  _4 = _3 << 2;
  _5 = (unsigned char) _4;
  _6 = _5 & 4;
  _7 = _3 >> 1;
  _8 = (unsigned char) _7;
  _9 = _8 & 4;
  optlen_73 = _6 + _9;
  # DEBUG optlen => optlen_73
  # DEBUG BEGIN_STMT
  remainder_74 = _1 - split_71(D);
  # DEBUG remainder => remainder_74
  # DEBUG BEGIN_STMT
  _10 = (short unsigned int) optlen_73;
  _11 = _10 + remainder_74;
  p_76 = pbuf_alloc (54, _11, 640);
  # DEBUG p => p_76
  # DEBUG BEGIN_STMT
  if (p_76 == 0B)
    goto <bb 13>; [30.95%]
  else
    goto <bb 14>; [69.05%]

  <bb 13> [local count: 3619]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 24>; [100.00%]

  <bb 14> [local count: 8074]:
  # DEBUG BEGIN_STMT
  _12 = useg_70->p;
  _13 = _12->tot_len;
  _14 = useg_70->len;
  _15 = _13 - _14;
  offset_77 = _15 + split_71(D);
  # DEBUG offset => offset_77
  # DEBUG BEGIN_STMT
  _16 = p_76->payload;
  _17 = (sizetype) optlen_73;
  _18 = _16 + _17;
  _19 = pbuf_copy_partial (_12, _18, remainder_74, offset_77);
  if (_19 != remainder_74)
    goto <bb 15>; [67.00%]
  else
    goto <bb 16>; [33.00%]

  <bb 15> [local count: 5410]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 24>; [100.00%]

  <bb 16> [local count: 2664]:
  # DEBUG BEGIN_STMT
  _20 = useg_70->tcphdr;
  _21 = _20->_hdrlen_rsvd_flags;
  _22 = lwip_htons (_21);
  _23 = (unsigned char) _22;
  split_flags_80 = _23 & 63;
  # DEBUG split_flags => split_flags_80
  # DEBUG BEGIN_STMT
  # DEBUG remainder_flags => 0
  # DEBUG BEGIN_STMT
  _65 = _23 & 8;
  if (_65 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 17> [local count: 1332]:
  # DEBUG BEGIN_STMT
  split_flags_81 = _23 & 55;
  # DEBUG split_flags => split_flags_81
  # DEBUG BEGIN_STMT
  # DEBUG remainder_flags => 8

  <bb 18> [local count: 2664]:
  # split_flags_54 = PHI <split_flags_80(16), split_flags_81(17)>
  # remainder_flags_56 = PHI <0(16), 8(17)>
  # DEBUG remainder_flags => remainder_flags_56
  # DEBUG split_flags => split_flags_54
  # DEBUG BEGIN_STMT
  _66 = split_flags_54 & 1;
  if (_66 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 19> [local count: 1332]:
  # DEBUG BEGIN_STMT
  split_flags_82 = split_flags_54 & 254;
  # DEBUG split_flags => split_flags_82
  # DEBUG BEGIN_STMT
  remainder_flags_83 = remainder_flags_56 | 1;
  # DEBUG remainder_flags => remainder_flags_83

  <bb 20> [local count: 2664]:
  # split_flags_55 = PHI <split_flags_54(18), split_flags_82(19)>
  # remainder_flags_57 = PHI <remainder_flags_56(18), remainder_flags_83(19)>
  # DEBUG remainder_flags => remainder_flags_57
  # DEBUG split_flags => split_flags_55
  # DEBUG BEGIN_STMT
  _24 = useg_70->tcphdr;
  _25 = _24->seqno;
  _26 = lwip_htonl (_25);
  _27 = (long unsigned int) split_71(D);
  _28 = _26 + _27;
  seg_86 = tcp_create_segment (pcb_68(D), p_76, remainder_flags_57, _28, optflags_72);
  # DEBUG seg => seg_86
  # DEBUG BEGIN_STMT
  if (seg_86 == 0B)
    goto <bb 21>; [30.95%]
  else
    goto <bb 22>; [69.05%]

  <bb 21> [local count: 825]:
  # DEBUG BEGIN_STMT
  # DEBUG p => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 24>; [100.00%]

  <bb 22> [local count: 1840]:
  # DEBUG BEGIN_STMT
  _29 = useg_70->p;
  _88 = pbuf_clen (_29);
  _30 = pcb_68(D)->snd_queuelen;
  _31 = _30 - _88;
  pcb_68(D)->snd_queuelen = _31;
  # DEBUG BEGIN_STMT
  _32 = useg_70->p;
  _33 = _32->tot_len;
  _67 = split_71(D) - _1;
  _34 = _33 + _67;
  pbuf_realloc (_32, _34);
  # DEBUG BEGIN_STMT
  _35 = useg_70->len;
  _36 = _35 + _67;
  useg_70->len = _36;
  # DEBUG BEGIN_STMT
  _37 = useg_70->tcphdr;
  _38 = _37->_hdrlen_rsvd_flags;
  _39 = (short unsigned int) split_flags_55;
  _40 = lwip_htons (_39);
  _41 = useg_70->tcphdr;
  _42 = _38 | _40;
  _41->_hdrlen_rsvd_flags = _42;
  # DEBUG BEGIN_STMT
  _43 = useg_70->p;
  _95 = pbuf_clen (_43);
  _44 = pcb_68(D)->snd_queuelen;
  _45 = _44 + _95;
  pcb_68(D)->snd_queuelen = _45;
  # DEBUG BEGIN_STMT
  _46 = seg_86->p;
  _98 = pbuf_clen (_46);
  _47 = pcb_68(D)->snd_queuelen;
  _48 = _47 + _98;
  pcb_68(D)->snd_queuelen = _48;
  # DEBUG BEGIN_STMT
  _49 = useg_70->next;
  seg_86->next = _49;
  # DEBUG BEGIN_STMT
  useg_70->next = seg_86;
  # DEBUG BEGIN_STMT
  _50 = seg_86->next;
  if (_50 == 0B)
    goto <bb 23>; [30.00%]
  else
    goto <bb 26>; [70.00%]

  <bb 23> [local count: 552]:
  # DEBUG BEGIN_STMT
  pcb_68(D)->unsent_oversize = 0;
  goto <bb 26>; [100.00%]

  <bb 24> [local count: 9853]:
  # p_53 = PHI <0B(13), p_76(15), 0B(21)>
memerr:
  # DEBUG p => p_53
  # DEBUG seg => 0B
  # DEBUG BEGIN_STMT
  _51 = lwip_stats.tcp.memerr;
  _52 = _51 + 1;
  lwip_stats.tcp.memerr = _52;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_53 != 0B)
    goto <bb 25>; [53.47%]
  else
    goto <bb 26>; [46.53%]

  <bb 25> [local count: 5269]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_53);

  <bb 26> [local count: 49171]:
  # _58 = PHI <-1(4), -1(25), 0(7), 0(23), -1(24), 0(22)>
  return _58;

}



;; Function tcp_enqueue_flags (tcp_enqueue_flags, funcdef_no=8, decl_uid=7265, cgraph_uid=9, symbol_order=8)

Modification phase of node tcp_enqueue_flags/8
tcp_enqueue_flags (struct tcp_pcb * pcb, u8_t flags)
{
  signed char _1;
  unsigned char _5;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optflags => 0
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = flags_6(D) & 3;
  if (_5 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_8(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 8> [local count: 32212]:

  <bb 5> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 322122547]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 75162]:
  _1 = tcp_enqueue_flags.part.0 (pcb_8(D), flags_6(D));
  return _1;

}



;; Function tcp_send_fin (tcp_send_fin, funcdef_no=7, decl_uid=7262, cgraph_uid=8, symbol_order=7)

Modification phase of node tcp_send_fin/7
tcp_send_fin (struct tcp_pcb * pcb)
{
  struct tcp_seg * last_unsent;
  struct tcp_seg * _1;
  struct tcp_seg * _2;
  struct tcp_hdr * _3;
  short unsigned int _4;
  short unsigned int _5;
  unsigned char _6;
  struct tcp_hdr * _7;
  short unsigned int _8;
  short unsigned int _9;
  struct tcp_hdr * _10;
  short unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  err_t _15;
  unsigned char _26;
  err_t _28;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_19(D) == 0B)
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
  _1 = pcb_19(D)->unsent;
  if (_1 != 0B)
    goto <bb 11>; [82.57%]
  else
    goto <bb 8>; [17.43%]

  <bb 11> [local count: 206870]:

  <bb 5> [local count: 1880639]:
  # last_unsent_14 = PHI <_1(11), _2(13)>
  # DEBUG last_unsent => last_unsent_14
  # DEBUG BEGIN_STMT
  _2 = last_unsent_14->next;
  if (_2 != 0B)
    goto <bb 13>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 13> [local count: 1673769]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 206870]:
  # last_unsent_21 = PHI <last_unsent_14(5)>
  # DEBUG BEGIN_STMT
  _3 = last_unsent_21->tcphdr;
  _4 = _3->_hdrlen_rsvd_flags;
  _5 = lwip_htons (_4);
  _6 = (unsigned char) _5;
  _26 = _6 & 7;
  if (_26 == 0)
    goto <bb 7>; [20.24%]
  else
    goto <bb 8>; [79.76%]

  <bb 7> [local count: 41871]:
  # DEBUG BEGIN_STMT
  _7 = last_unsent_21->tcphdr;
  _8 = _7->_hdrlen_rsvd_flags;
  _9 = lwip_htons (1);
  _10 = last_unsent_21->tcphdr;
  _11 = _8 | _9;
  _10->_hdrlen_rsvd_flags = _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = pcb_19(D)->flags;
  _13 = _12 | 32;
  pcb_19(D)->flags = _13;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 208669]:
  # DEBUG BEGIN_STMT
  _28 = tcp_enqueue_flags (pcb_19(D), 1);

  <bb 9> [local count: 250539]:
  # _15 = PHI <0(7), _28(8)>
  return _15;

}



;; Function tcp_rexmit_rto_prepare (tcp_rexmit_rto_prepare, funcdef_no=13, decl_uid=7221, cgraph_uid=14, symbol_order=13)

Modification phase of node tcp_rexmit_rto_prepare/13
tcp_rexmit_rto_prepare (struct tcp_pcb * pcb)
{
  struct tcp_seg * seg;
  struct tcp_seg * _1;
  int _2;
  struct tcp_seg * _3;
  int _4;
  struct tcp_seg * _5;
  struct tcp_seg * _6;
  short unsigned int _7;
  short unsigned int _8;
  struct tcp_hdr * _9;
  long unsigned int _10;
  long unsigned int _11;
  short unsigned int _12;
  unsigned int _13;
  struct tcp_hdr * _14;
  short unsigned int _15;
  short unsigned int _16;
  unsigned char _17;
  unsigned int _18;
  long unsigned int _19;
  err_t _21;
  unsigned int iftmp.17_22;
  unsigned char _36;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_26(D) == 0B)
    goto <bb 13>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 13> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_26(D)->unacked;
  if (_1 == 0B)
    goto <bb 12>; [0.45%]
  else
    goto <bb 14>; [99.55%]

  <bb 14> [local count: 249412]:
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 2203265]:
  # DEBUG BEGIN_STMT
  _2 = tcp_output_segment_busy (seg_20);
  if (_2 != 0)
    goto <bb 12>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 2082085]:
  # DEBUG BEGIN_STMT
  seg_40 = seg_20->next;
  # DEBUG seg => seg_40

  <bb 7> [local count: 2331497]:
  # seg_20 = PHI <seg_40(6), _1(14)>
  # DEBUG seg => seg_20
  # DEBUG BEGIN_STMT
  _3 = seg_20->next;
  if (_3 != 0B)
    goto <bb 5>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 128232]:
  # seg_28 = PHI <seg_20(7)>
  # DEBUG BEGIN_STMT
  _4 = tcp_output_segment_busy (seg_28);
  if (_4 != 0)
    goto <bb 12>; [2.09%]
  else
    goto <bb 9>; [97.91%]

  <bb 9> [local count: 125552]:
  # DEBUG BEGIN_STMT
  _5 = pcb_26(D)->unsent;
  seg_28->next = _5;
  # DEBUG BEGIN_STMT
  _6 = pcb_26(D)->unacked;
  pcb_26(D)->unsent = _6;
  # DEBUG BEGIN_STMT
  pcb_26(D)->unacked = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = pcb_26(D)->flags;
  _8 = _7 | 2048;
  pcb_26(D)->flags = _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = seg_28->tcphdr;
  _10 = _9->seqno;
  _11 = lwip_htonl (_10);
  _12 = seg_28->len;
  _13 = (unsigned int) _12;
  _14 = seg_28->tcphdr;
  _15 = _14->_hdrlen_rsvd_flags;
  _16 = lwip_htons (_15);
  _17 = (unsigned char) _16;
  _36 = _17 & 3;
  if (_36 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 10> [local count: 62776]:

  <bb 11> [local count: 125552]:
  # iftmp.17_22 = PHI <1(9), 0(10)>
  _18 = _13 + iftmp.17_22;
  _19 = _11 + _18;
  pcb_26(D)->rto_end = _19;
  # DEBUG BEGIN_STMT
  pcb_26(D)->rttest = 0;
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 250539]:
  # _21 = PHI <-6(4), -6(5), -6(8), 0(11)>
  return _21;

}



;; Function tcp_rexmit (tcp_rexmit, funcdef_no=16, decl_uid=7219, cgraph_uid=17, symbol_order=16)

Modification phase of node tcp_rexmit/16
tcp_rexmit (struct tcp_pcb * pcb)
{
  struct tcp_seg * * cur_seg;
  struct tcp_seg * _1;
  int _2;
  struct tcp_seg * _3;
  struct tcp_seg * _4;
  struct tcp_seg * _5;
  struct tcp_hdr * _6;
  long unsigned int _7;
  long unsigned int _8;
  struct tcp_hdr * _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long int _13;
  struct tcp_seg * _14;
  struct tcp_seg * _15;
  unsigned char _16;
  unsigned char _17;
  long unsigned int _18;
  long unsigned int _19;
  err_t _21;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_28(D) == 0B)
    goto <bb 16>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 16> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_28(D)->unacked;
  if (_1 == 0B)
    goto <bb 15>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 5> [local count: 248259]:
  # DEBUG BEGIN_STMT
  # DEBUG seg => _1
  # DEBUG BEGIN_STMT
  _2 = tcp_output_segment_busy (_1);
  if (_2 != 0)
    goto <bb 15>; [1.04%]
  else
    goto <bb 6>; [98.96%]

  <bb 6> [local count: 245678]:
  # DEBUG BEGIN_STMT
  _3 = _1->next;
  pcb_28(D)->unacked = _3;
  # DEBUG BEGIN_STMT
  cur_seg_33 = &pcb_28(D)->unsent;
  # DEBUG cur_seg => cur_seg_33
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 2050911]:
  # DEBUG BEGIN_STMT
  _4 = *cur_seg_20;
  cur_seg_36 = &_4->next;
  # DEBUG cur_seg => cur_seg_36

  <bb 8> [local count: 2296588]:
  # cur_seg_20 = PHI <cur_seg_33(6), cur_seg_36(7)>
  # DEBUG cur_seg => cur_seg_20
  # DEBUG BEGIN_STMT
  _5 = *cur_seg_20;
  if (_5 != 0B)
    goto <bb 9>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 9> [local count: 2170276]:
  _6 = _5->tcphdr;
  _7 = _6->seqno;
  _8 = lwip_htonl (_7);
  _9 = _1->tcphdr;
  _10 = _9->seqno;
  _11 = lwip_htonl (_10);
  _12 = _8 - _11;
  _13 = (long int) _12;
  if (_13 < 0)
    goto <bb 7>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 10> [local count: 245678]:
  # cur_seg_30 = PHI <cur_seg_20(8), cur_seg_20(9)>
  # DEBUG BEGIN_STMT
  _14 = *cur_seg_30;
  _1->next = _14;
  # DEBUG BEGIN_STMT
  *cur_seg_30 = _1;
  # DEBUG BEGIN_STMT
  _15 = _1->next;
  if (_15 == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 12>; [70.00%]

  <bb 11> [local count: 73703]:
  # DEBUG BEGIN_STMT
  pcb_28(D)->unsent_oversize = 0;

  <bb 12> [local count: 245678]:
  # DEBUG BEGIN_STMT
  _16 = pcb_28(D)->nrtx;
  if (_16 != 255)
    goto <bb 13>; [66.00%]
  else
    goto <bb 14>; [34.00%]

  <bb 13> [local count: 162147]:
  # DEBUG BEGIN_STMT
  _17 = _16 + 1;
  pcb_28(D)->nrtx = _17;

  <bb 14> [local count: 245678]:
  # DEBUG BEGIN_STMT
  pcb_28(D)->rttest = 0;
  # DEBUG BEGIN_STMT
  _18 = lwip_stats.mib2.tcpretranssegs;
  _19 = _18 + 1;
  lwip_stats.mib2.tcpretranssegs = _19;
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 250539]:
  # _21 = PHI <-6(4), -6(5), 0(14)>
  return _21;

}



;; Function tcp_rexmit_fast (tcp_rexmit_fast, funcdef_no=17, decl_uid=7227, cgraph_uid=18, symbol_order=17)

Modification phase of node tcp_rexmit_fast/17
tcp_rexmit_fast (struct tcp_pcb * pcb)
{
  struct tcp_seg * _1;
  short unsigned int _2;
  signed char _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  short unsigned int _8;
  unsigned int _9;
  unsigned int _10;
  int _11;
  int _12;
  long unsigned int _13;
  long unsigned int _14;
  int _15;
  int _16;
  long unsigned int _17;
  long unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _33;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_24(D) == 0B)
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
  _1 = pcb_24(D)->unacked;
  if (_1 != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 5> [local count: 175378]:
  _2 = pcb_24(D)->flags;
  _33 = _2 & 4;
  if (_33 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 6> [local count: 57875]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = tcp_rexmit (pcb_24(D));
  if (_3 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 7> [local count: 28937]:
  # DEBUG BEGIN_STMT
  _4 = pcb_24(D)->snd_wnd;
  _5 = pcb_24(D)->cwnd;
  _6 = MIN_EXPR <_4, _5>;
  _7 = _6 >> 1;
  pcb_24(D)->ssthresh = _7;
  # DEBUG BEGIN_STMT
  _8 = pcb_24(D)->mss;
  _9 = (unsigned int) _8;
  _10 = _9 * 2;
  if (_7 < _10)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 14469]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = (int) _8;
  _12 = _11 * 2;
  _13 = (long unsigned int) _12;
  pcb_24(D)->ssthresh = _13;

  <bb 9> [local count: 28937]:
  # DEBUG BEGIN_STMT
  _14 = pcb_24(D)->ssthresh;
  _15 = (int) _8;
  _16 = _15 * 3;
  _17 = (long unsigned int) _16;
  _18 = _14 + _17;
  pcb_24(D)->cwnd = _18;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = pcb_24(D)->flags;
  _20 = _19 | 4;
  pcb_24(D)->flags = _20;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_24(D)->rtime = 0;

  <bb 10> [local count: 250539]:
  return;

}



;; Function tcp_rst (tcp_rst, funcdef_no=22, decl_uid=7276, cgraph_uid=23, symbol_order=22)

Modification phase of node tcp_rst/22
tcp_rst (const struct tcp_pcb * pcb, u32_t seqno, u32_t ackno, const struct ip_addr_t * local_ip, const struct ip_addr_t * remote_ip, u16_t local_port, u16_t remote_port)
{
  struct pbuf * p;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 329661]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (local_ip_7(D) == 0B)
    goto <bb 9>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 9> [local count: 98898]:

  <bb 3> [local count: 988985746]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 988985746]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (remote_ip_9(D) == 0B)
    goto <bb 10>; [46.53%]
  else
    goto <bb 6>; [53.47%]

  <bb 10> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG wnd => 16475
  # DEBUG BEGIN_STMT
  _1 = lwip_htonl (seqno_10(D));
  p_16 = tcp_output_alloc_header_common (ackno_12(D), 0, 0, _1, local_port_13(D), remote_port_14(D), 20, 16475);
  # DEBUG p => p_16
  # DEBUG BEGIN_STMT
  if (p_16 == 0B)
    goto <bb 8>; [30.95%]
  else
    goto <bb 7>; [69.05%]

  <bb 7> [local count: 85200]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => pcb_17(D)
  # DEBUG D#2 => 0
  tcp_output_fill_options.isra.0 (p_16, 0);
  # DEBUG BEGIN_STMT
  _2 = lwip_stats.mib2.tcpoutrsts;
  _3 = _2 + 1;
  lwip_stats.mib2.tcpoutrsts = _3;
  # DEBUG BEGIN_STMT
  tcp_output_control_segment (pcb_17(D), p_16, local_ip_7(D), remote_ip_9(D));

  <bb 8> [local count: 123389]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function tcp_send_empty_ack (tcp_send_empty_ack, funcdef_no=23, decl_uid=7217, cgraph_uid=24, symbol_order=23)

Modification phase of node tcp_send_empty_ack/23
tcp_send_empty_ack (struct tcp_pcb * pcb)
{
  signed char _2;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optflags => 0
  # DEBUG BEGIN_STMT
  # DEBUG num_sacks => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) == 0B)
    goto <bb 5>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  _2 = tcp_send_empty_ack.part.0 (pcb_4(D));
  return _2;

}



;; Function tcp_output (tcp_output, funcdef_no=10, decl_uid=7181, cgraph_uid=11, symbol_order=10)

Modification phase of node tcp_output/10
tcp_output (struct tcp_pcb * pcb)
{
  tcp_state _1;
  struct tcp_pcb * tcp_input_pcb.9_2;
  signed char _5;
  err_t _6;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_9(D) == 0B)
    goto <bb 9>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 9> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_9(D)->state;
  if (_1 == 1)
    goto <bb 10>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 10> [local count: 85183]:

  <bb 5> [local count: 851835183]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 851835183]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 165356]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_input_pcb.9_2 = tcp_input_pcb;
  if (tcp_input_pcb.9_2 == pcb_9(D))
    goto <bb 8>; [18.09%]
  else
    goto <bb 7>; [81.91%]

  <bb 7> [local count: 135443]:
  _5 = tcp_output.part.0 (pcb_9(D));

  <bb 8> [local count: 156557]:
  # _6 = PHI <0(6), _5(7)>
  return _6;

}



;; Function tcp_rexmit_rto_commit (tcp_rexmit_rto_commit, funcdef_no=14, decl_uid=7223, cgraph_uid=15, symbol_order=14)

Modification phase of node tcp_rexmit_rto_commit/14
tcp_rexmit_rto_commit (struct tcp_pcb * pcb)
{
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_5(D) == 0B)
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

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_5(D)->nrtx;
  if (_1 != 255)
    goto <bb 5>; [66.00%]
  else
    goto <bb 6>; [34.00%]

  <bb 5> [local count: 165356]:
  # DEBUG BEGIN_STMT
  _2 = _1 + 1;
  pcb_5(D)->nrtx = _2;

  <bb 6> [local count: 250539]:
  # DEBUG BEGIN_STMT
  tcp_output (pcb_5(D));
  return;

}



;; Function tcp_rexmit_rto (tcp_rexmit_rto, funcdef_no=15, decl_uid=7225, cgraph_uid=16, symbol_order=15)

Modification phase of node tcp_rexmit_rto/15
tcp_rexmit_rto (struct tcp_pcb * pcb)
{
  signed char _1;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) == 0B)
    goto <bb 7>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tcp_rexmit_rto_prepare (pcb_4(D));
  if (_1 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 40718]:
  # DEBUG BEGIN_STMT
  tcp_rexmit_rto_commit (pcb_4(D));

  <bb 6> [local count: 123389]:
  return;

}



;; Function tcp_keepalive (tcp_keepalive, funcdef_no=24, decl_uid=7280, cgraph_uid=25, symbol_order=24)

Modification phase of node tcp_keepalive/24
tcp_keepalive (struct tcp_pcb * pcb)
{
  struct pbuf * p;
  err_t err;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  struct ip_addr_t * _4;
  struct ip_addr_t * _5;
  err_t _6;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_9(D) == 0B)
    goto <bb 7>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_9(D)->snd_nxt;
  _2 = _1 + 4294967295;
  _3 = lwip_htonl (_2);
  p_13 = tcp_output_alloc_header (pcb_9(D), 0, 0, _3);
  # DEBUG p => p_13
  # DEBUG BEGIN_STMT
  if (p_13 == 0B)
    goto <bb 6>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 5> [local count: 122266]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => pcb_9(D)
  # DEBUG D#2 => 0
  tcp_output_fill_options.isra.0 (p_13, 0);
  # DEBUG BEGIN_STMT
  _4 = &pcb_9(D)->local_ip;
  _5 = &pcb_9(D)->remote_ip;
  err_16 = tcp_output_control_segment (pcb_9(D), p_13, _4, _5);
  # DEBUG err => err_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 123389]:
  # _6 = PHI <-1(4), err_16(5)>
  return _6;

}



;; Function tcp_zero_window_probe (tcp_zero_window_probe, funcdef_no=25, decl_uid=7285, cgraph_uid=26, symbol_order=25)

Modification phase of node tcp_zero_window_probe/25
tcp_zero_window_probe (struct tcp_pcb * pcb)
{
  char * d;
  u32_t snd_nxt;
  u8_t is_fin;
  u16_t len;
  struct tcp_seg * seg;
  struct tcp_hdr * tcphdr;
  struct pbuf * p;
  err_t err;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  struct tcp_hdr * _4;
  short unsigned int _5;
  short unsigned int _6;
  unsigned char _7;
  short unsigned int _8;
  struct tcp_hdr * _9;
  long unsigned int _10;
  short unsigned int _11;
  signed short _12;
  signed short _13;
  short unsigned int _14;
  signed short _15;
  signed short _16;
  short unsigned int _17;
  struct pbuf * _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;
  struct tcp_hdr * _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long int _27;
  struct ip_addr_t * _28;
  struct ip_addr_t * _29;
  err_t _30;
  int iftmp.19_31;
  unsigned char _37;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG optlen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_38(D) == 0B)
    goto <bb 18>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 18> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 19> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  seg_40 = pcb_38(D)->unsent;
  # DEBUG seg => seg_40
  # DEBUG BEGIN_STMT
  if (seg_40 == 0B)
    goto <bb 17>; [18.09%]
  else
    goto <bb 5>; [81.91%]

  <bb 5> [local count: 205217]:
  # DEBUG BEGIN_STMT
  _1 = pcb_38(D)->persist_probe;
  if (_1 != 255)
    goto <bb 6>; [66.00%]
  else
    goto <bb 7>; [34.00%]

  <bb 6> [local count: 135443]:
  # DEBUG BEGIN_STMT
  _3 = _1 + 1;
  pcb_38(D)->persist_probe = _3;

  <bb 7> [local count: 205217]:
  # DEBUG BEGIN_STMT
  _4 = seg_40->tcphdr;
  _5 = _4->_hdrlen_rsvd_flags;
  _6 = lwip_htons (_5);
  _7 = (unsigned char) _6;
  _37 = _7 & 1;
  if (_37 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 102608]:
  _8 = seg_40->len;
  if (_8 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 153913]:

  <bb 10> [local count: 205217]:
  # iftmp.19_31 = PHI <1(8), 0(9)>
  is_fin_43 = (u8_t) iftmp.19_31;
  # DEBUG is_fin => is_fin_43
  # DEBUG BEGIN_STMT
  _2 = is_fin_43 ^ 1;
  len_44 = (u16_t) _2;
  # DEBUG len => len_44
  # DEBUG BEGIN_STMT
  _9 = seg_40->tcphdr;
  _10 = _9->seqno;
  p_46 = tcp_output_alloc_header (pcb_38(D), 0, len_44, _10);
  # DEBUG p => p_46
  # DEBUG BEGIN_STMT
  if (p_46 == 0B)
    goto <bb 17>; [0.45%]
  else
    goto <bb 11>; [99.55%]

  <bb 11> [local count: 204293]:
  # DEBUG BEGIN_STMT
  tcphdr_47 = p_46->payload;
  # DEBUG tcphdr => tcphdr_47
  # DEBUG BEGIN_STMT
  if (is_fin_43 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 102147]:
  # DEBUG BEGIN_STMT
  _11 = tcphdr_47->_hdrlen_rsvd_flags;
  _12 = (signed short) _11;
  _13 = _12 & -16129;
  _14 = lwip_htons (17);
  _15 = (signed short) _14;
  _16 = _13 | _15;
  _17 = (short unsigned int) _16;
  tcphdr_47->_hdrlen_rsvd_flags = _17;
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 102147]:
  # DEBUG BEGIN_STMT
  d_48 = tcphdr_47 + 20;
  # DEBUG d => d_48
  # DEBUG BEGIN_STMT
  _18 = seg_40->p;
  _19 = _18->tot_len;
  _20 = seg_40->len;
  _21 = _19 - _20;
  pbuf_copy_partial (_18, d_48, 1, _21);

  <bb 14> [local count: 204293]:
  # DEBUG BEGIN_STMT
  _22 = seg_40->tcphdr;
  _23 = _22->seqno;
  _24 = lwip_htonl (_23);
  snd_nxt_53 = _24 + 1;
  # DEBUG snd_nxt => snd_nxt_53
  # DEBUG BEGIN_STMT
  _25 = pcb_38(D)->snd_nxt;
  _26 = _25 - snd_nxt_53;
  _27 = (long int) _26;
  if (_27 < 0)
    goto <bb 15>; [41.00%]
  else
    goto <bb 16>; [59.00%]

  <bb 15> [local count: 83760]:
  # DEBUG BEGIN_STMT
  pcb_38(D)->snd_nxt = snd_nxt_53;

  <bb 16> [local count: 204293]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => pcb_38(D)
  # DEBUG D#2 => 0
  tcp_output_fill_options.isra.0 (p_46, 0);
  # DEBUG BEGIN_STMT
  _28 = &pcb_38(D)->local_ip;
  _29 = &pcb_38(D)->remote_ip;
  err_57 = tcp_output_control_segment (pcb_38(D), p_46, _28, _29);
  # DEBUG err => err_57
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 250539]:
  # _30 = PHI <0(4), -1(10), err_57(16)>
  return _30;

}


