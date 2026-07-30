
IPA constant propagation start:
Determining dynamic type for call: _33 = lwip_standard_chksum (_1, _3);
  Starting walk at: _33 = lwip_standard_chksum (_1, _3);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_33 = lwip_standard_chksum (_1, _3);
Determining dynamic type for call: _2 = lwip_standard_chksum (dataptr_5(D), _1);
  Starting walk at: _2 = lwip_standard_chksum (dataptr_5(D), _1);
  instance pointer: dataptr_5(D)  Outer instance pointer: dataptr_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = inet_chksum_pseudo_partial (p_2(D), proto_3(D), proto_len_4(D), chksum_len_5(D), src_6(D), dest_7(D));
  Starting walk at: _9 = inet_chksum_pseudo_partial (p_2(D), proto_3(D), proto_len_4(D), chksum_len_5(D), src_6(D), dest_7(D));
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = inet_chksum_pseudo_partial (p_2(D), proto_3(D), proto_len_4(D), chksum_len_5(D), src_6(D), dest_7(D));
  Starting walk at: _9 = inet_chksum_pseudo_partial (p_2(D), proto_3(D), proto_len_4(D), chksum_len_5(D), src_6(D), dest_7(D));
  instance pointer: src_6(D)  Outer instance pointer: src_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = inet_chksum_pseudo_partial (p_2(D), proto_3(D), proto_len_4(D), chksum_len_5(D), src_6(D), dest_7(D));
  Starting walk at: _9 = inet_chksum_pseudo_partial (p_2(D), proto_3(D), proto_len_4(D), chksum_len_5(D), src_6(D), dest_7(D));
  instance pointer: dest_7(D)  Outer instance pointer: dest_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _24 = inet_cksum_pseudo_partial_base (p_19(D), proto_20(D), proto_len_21(D), chksum_len_22(D), acc_18);
  Starting walk at: _24 = inet_cksum_pseudo_partial_base (p_19(D), proto_20(D), proto_len_21(D), chksum_len_22(D), acc_18);
  instance pointer: p_19(D)  Outer instance pointer: p_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _43 = lwip_standard_chksum (_1, _2);
  Starting walk at: _43 = lwip_standard_chksum (_1, _2);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_43 = lwip_standard_chksum (_1, _2);
Determining dynamic type for call: _8 = inet_chksum_pseudo (p_2(D), proto_3(D), proto_len_4(D), src_5(D), dest_6(D));
  Starting walk at: _8 = inet_chksum_pseudo (p_2(D), proto_3(D), proto_len_4(D), src_5(D), dest_6(D));
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = inet_chksum_pseudo (p_2(D), proto_3(D), proto_len_4(D), src_5(D), dest_6(D));
  Starting walk at: _8 = inet_chksum_pseudo (p_2(D), proto_3(D), proto_len_4(D), src_5(D), dest_6(D));
  instance pointer: src_5(D)  Outer instance pointer: src_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = inet_chksum_pseudo (p_2(D), proto_3(D), proto_len_4(D), src_5(D), dest_6(D));
  Starting walk at: _8 = inet_chksum_pseudo (p_2(D), proto_3(D), proto_len_4(D), src_5(D), dest_6(D));
  instance pointer: dest_6(D)  Outer instance pointer: dest_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _23 = inet_cksum_pseudo_base (p_19(D), proto_20(D), proto_len_21(D), acc_18);
  Starting walk at: _23 = inet_cksum_pseudo_base (p_19(D), proto_20(D), proto_len_21(D), acc_18);
  instance pointer: p_19(D)  Outer instance pointer: p_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _51 = lwip_standard_chksum (_1, _3);
  Starting walk at: _51 = lwip_standard_chksum (_1, _3);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_51 = lwip_standard_chksum (_1, _3);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  lwip_htons/10:
  Jump functions of caller  inet_chksum_pbuf/9:
    callsite  inet_chksum_pbuf/9 -> lwip_standard_chksum/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
  Jump functions of caller  inet_chksum/8:
    callsite  inet_chksum/8 -> lwip_standard_chksum/1 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
  Jump functions of caller  ip_chksum_pseudo_partial/7:
    callsite  ip_chksum_pseudo_partial/7 -> inet_chksum_pseudo_partial/6 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  inet_chksum_pseudo_partial/6:
    callsite  inet_chksum_pseudo_partial/6 -> inet_cksum_pseudo_partial_base/5 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0x1ffff
         VR  [0, 65536]
  Jump functions of caller  inet_cksum_pseudo_partial_base/5:
    callsite  inet_cksum_pseudo_partial_base/5 -> lwip_standard_chksum/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
  Jump functions of caller  ip_chksum_pseudo/4:
    callsite  ip_chksum_pseudo/4 -> inet_chksum_pseudo/3 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
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
  Jump functions of caller  inet_chksum_pseudo/3:
    callsite  inet_chksum_pseudo/3 -> inet_cksum_pseudo_base/2 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x1ffff
         VR  [0, 65536]
  Jump functions of caller  inet_cksum_pseudo_base/2:
    callsite  inet_cksum_pseudo_base/2 -> lwip_standard_chksum/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
  Jump functions of caller  lwip_standard_chksum/1:

 Propagating constants:

Not considering inet_chksum_pbuf for cloning; -fipa-cp-clone disabled.
Not considering inet_chksum for cloning; -fipa-cp-clone disabled.
Not considering ip_chksum_pseudo_partial for cloning; -fipa-cp-clone disabled.
Not considering inet_chksum_pseudo_partial for cloning; -fipa-cp-clone disabled.
Not considering ip_chksum_pseudo for cloning; -fipa-cp-clone disabled.
Not considering inet_chksum_pseudo for cloning; -fipa-cp-clone disabled.
Not considering lwip_standard_chksum for cloning; -fipa-cp-clone disabled.

overall_size: 254, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: inet_chksum_pbuf/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: inet_chksum/8:
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
  Node: ip_chksum_pseudo_partial/7:
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
  Node: inet_chksum_pseudo_partial/6:
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
  Node: inet_cksum_pseudo_partial_base/5:
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
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1ffff
         u32_t [0, 65536]
        AGGS VARIABLE
  Node: ip_chksum_pseudo/4:
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
  Node: inet_chksum_pseudo/3:
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
  Node: inet_cksum_pseudo_base/2:
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
         Bits: value = 0x0, mask = 0x1ffff
         u32_t [0, 65536]
        AGGS VARIABLE
  Node: lwip_standard_chksum/1:
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

IPA decision stage:

Propagated bits info for function inet_cksum_pseudo_partial_base/5:
 param 4: value = 0x0, mask = 0x1ffff
Propagated bits info for function inet_cksum_pseudo_base/2:
 param 3: value = 0x0, mask = 0x1ffff

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

lwip_htons/10 (lwip_htons) @070d2380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: inet_cksum_pseudo_partial_base/5 (227141 (estimated locally),0.68 per call) inet_cksum_pseudo_partial_base/5 (227141 (estimated locally),0.68 per call) inet_cksum_pseudo_base/2 (118111601 (estimated locally),1.00 per call) inet_cksum_pseudo_base/2 (118111601 (estimated locally),1.00 per call) 
  Calls: 
inet_chksum_pbuf/9 (inet_chksum_pbuf) @0707d700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: lwip_standard_chksum/1 (955630223 (estimated locally),8.09 per call) 
inet_chksum/8 (inet_chksum) @0707db60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: lwip_standard_chksum/1 (1073741824 (estimated locally),1.00 per call) 
ip_chksum_pseudo_partial/7 (ip_chksum_pseudo_partial) @0707d8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: inet_chksum_pseudo_partial/6 (1073741824 (estimated locally),1.00 per call) 
inet_chksum_pseudo_partial/6 (inet_chksum_pseudo_partial) @0707d620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: ip_chksum_pseudo_partial/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: inet_cksum_pseudo_partial_base/5 (1073741824 (estimated locally),1.00 per call) 
inet_cksum_pseudo_partial_base/5 (inet_cksum_pseudo_partial_base) @0707d1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:334515 (estimated locally) body local optimize_size
  Called by: inet_chksum_pseudo_partial/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: lwip_htons/10 (227141 (estimated locally),0.68 per call) lwip_htons/10 (227141 (estimated locally),0.68 per call) lwip_standard_chksum/1 (2933716 (estimated locally),8.77 per call) 
ip_chksum_pseudo/4 (ip_chksum_pseudo) @07075b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: inet_chksum_pseudo/3 (1073741824 (estimated locally),1.00 per call) 
inet_chksum_pseudo/3 (inet_chksum_pseudo) @070758c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: ip_chksum_pseudo/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: inet_cksum_pseudo_base/2 (1073741824 (estimated locally),1.00 per call) 
inet_cksum_pseudo_base/2 (inet_cksum_pseudo_base) @07075460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: inet_chksum_pseudo/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: lwip_htons/10 (118111601 (estimated locally),1.00 per call) lwip_htons/10 (118111601 (estimated locally),1.00 per call) lwip_standard_chksum/1 (955630223 (estimated locally),8.09 per call) 
lwip_standard_chksum/1 (lwip_standard_chksum) @07069d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: inet_chksum_pbuf/9 (955630223 (estimated locally),8.09 per call) inet_chksum/8 (1073741824 (estimated locally),1.00 per call) inet_cksum_pseudo_partial_base/5 (2933716 (estimated locally),8.77 per call) inet_cksum_pseudo_base/2 (955630223 (estimated locally),8.09 per call) 
  Calls: 

;; Function lwip_standard_chksum (lwip_standard_chksum, funcdef_no=1, decl_uid=6713, cgraph_uid=2, symbol_order=1)

Modification phase of node lwip_standard_chksum/1
lwip_standard_chksum (const void * dataptr, int len)
{
  int odd;
  u32_t sum;
  u16_t t;
  const u16_t * ps;
  const u8_t * pb;
  int pb.0_1;
  unsigned char _2;
  long unsigned int _4;
  unsigned char _5;
  short unsigned int t.4_6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  u16_t _39;
  short unsigned int _42;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG pb => dataptr_24(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  t = 0;
  # DEBUG BEGIN_STMT
  # DEBUG sum => 0
  # DEBUG BEGIN_STMT
  pb.0_1 = (int) dataptr_24(D);
  odd_29 = pb.0_1 & 1;
  # DEBUG odd => odd_29
  # DEBUG BEGIN_STMT
  if (odd_29 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 59055800]:
  if (len_30(D) > 0)
    goto <bb 4>; [59.00%]
  else
    goto <bb 5>; [41.00%]

  <bb 4> [local count: 34842922]:
  # DEBUG BEGIN_STMT
  pb_31 = dataptr_24(D) + 1;
  # DEBUG pb => pb_31
  _2 = MEM[(const u8_t *)dataptr_24(D)];
  MEM[(u8_t *)&t + 1B] = _2;
  # DEBUG BEGIN_STMT
  len_33 = len_30(D) + -1;
  # DEBUG len => len_33

  <bb 5> [local count: 118111600]:
  # len_16 = PHI <len_30(D)(2), len_30(D)(3), len_33(4)>
  # pb_18 = PHI <dataptr_24(D)(2), dataptr_24(D)(3), pb_31(4)>
  # DEBUG pb => pb_18
  # DEBUG len => len_16
  # DEBUG BEGIN_STMT
  # DEBUG ps => pb_18
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  ps_41 = ps_19 + 2;
  # DEBUG ps => ps_41
  _42 = *ps_19;
  _4 = (long unsigned int) _42;
  sum_43 = _4 + sum_20;
  # DEBUG sum => sum_43
  # DEBUG BEGIN_STMT
  len_44 = len_17 + -2;
  # DEBUG len => len_44

  <bb 7> [local count: 1073741824]:
  # len_17 = PHI <len_16(5), len_44(6)>
  # ps_19 = PHI <pb_18(5), ps_41(6)>
  # sum_20 = PHI <0(5), sum_43(6)>
  # DEBUG sum => sum_20
  # DEBUG ps => ps_19
  # DEBUG len => len_17
  # DEBUG BEGIN_STMT
  if (len_17 > 1)
    goto <bb 6>; [89.00%]
  else
    goto <bb 8>; [11.00%]

  <bb 8> [local count: 118111601]:
  # len_3 = PHI <len_17(7)>
  # ps_25 = PHI <ps_19(7)>
  # sum_28 = PHI <sum_20(7)>
  # DEBUG BEGIN_STMT
  if (len_3 > 0)
    goto <bb 9>; [59.00%]
  else
    goto <bb 10>; [41.00%]

  <bb 9> [local count: 69685844]:
  # DEBUG BEGIN_STMT
  _5 = MEM[(const u8_t *)ps_25];
  MEM[(u8_t *)&t] = _5;

  <bb 10> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  t.4_6 = t;
  _7 = (long unsigned int) t.4_6;
  sum_35 = _7 + sum_28;
  # DEBUG sum => sum_35
  # DEBUG BEGIN_STMT
  _8 = sum_35 >> 16;
  _9 = sum_35 & 65535;
  sum_36 = _8 + _9;
  # DEBUG sum => sum_36
  # DEBUG BEGIN_STMT
  _10 = sum_36 >> 16;
  _11 = sum_36 & 65535;
  sum_37 = _10 + _11;
  # DEBUG sum => sum_37
  # DEBUG BEGIN_STMT
  if (odd_29 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  _12 = sum_37 << 8;
  _13 = _12 & 65535;
  _14 = sum_37 >> 8;
  _15 = _14 & 255;
  sum_38 = _13 | _15;
  # DEBUG sum => sum_38

  <bb 12> [local count: 118111601]:
  # sum_21 = PHI <sum_37(10), sum_38(11)>
  # DEBUG sum => sum_21
  # DEBUG BEGIN_STMT
  _39 = (u16_t) sum_21;
  t ={v} {CLOBBER};
  return _39;

}



;; Function inet_chksum_pseudo (inet_chksum_pseudo, funcdef_no=3, decl_uid=6603, cgraph_uid=4, symbol_order=3)

Modification phase of node inet_chksum_pseudo/3
inet_chksum_pseudo (struct pbuf * p, u8_t proto, u16_t proto_len, const struct ip4_addr_t * src, const struct ip4_addr_t * dest)
{
  u32_t addr;
  u32_t acc;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  u16_t _23;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_10 = src_9(D)->addr;
  # DEBUG addr => addr_10
  # DEBUG BEGIN_STMT
  acc_11 = addr_10 & 65535;
  # DEBUG acc => acc_11
  # DEBUG BEGIN_STMT
  _1 = addr_10 >> 16;
  acc_12 = _1 + acc_11;
  # DEBUG acc => acc_12
  # DEBUG BEGIN_STMT
  addr_14 = dest_13(D)->addr;
  # DEBUG addr => addr_14
  # DEBUG BEGIN_STMT
  _2 = addr_14 & 65535;
  acc_15 = _2 + acc_12;
  # DEBUG acc => acc_15
  # DEBUG BEGIN_STMT
  _3 = addr_14 >> 16;
  acc_16 = _3 + acc_15;
  # DEBUG acc => acc_16
  # DEBUG BEGIN_STMT
  _4 = acc_16 >> 16;
  _5 = acc_16 & 65535;
  acc_17 = _4 + _5;
  # DEBUG acc => acc_17
  # DEBUG BEGIN_STMT
  _6 = acc_17 >> 16;
  _7 = acc_17 & 65535;
  acc_18 = _6 + _7;
  # DEBUG acc => acc_18
  # DEBUG BEGIN_STMT
  _23 = inet_cksum_pseudo_base (p_19(D), proto_20(D), proto_len_21(D), acc_18);
  return _23;

}



;; Function ip_chksum_pseudo (ip_chksum_pseudo, funcdef_no=4, decl_uid=6616, cgraph_uid=5, symbol_order=4)

Modification phase of node ip_chksum_pseudo/4
ip_chksum_pseudo (struct pbuf * p, u8_t proto, u16_t proto_len, const struct ip_addr_t * src, const struct ip_addr_t * dest)
{
  u16_t _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _8 = inet_chksum_pseudo (p_2(D), proto_3(D), proto_len_4(D), src_5(D), dest_6(D));
  return _8;

}



;; Function inet_chksum_pseudo_partial (inet_chksum_pseudo_partial, funcdef_no=6, decl_uid=6610, cgraph_uid=7, symbol_order=6)

Modification phase of node inet_chksum_pseudo_partial/6
inet_chksum_pseudo_partial (struct pbuf * p, u8_t proto, u16_t proto_len, u16_t chksum_len, const struct ip4_addr_t * src, const struct ip4_addr_t * dest)
{
  u32_t addr;
  u32_t acc;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  u16_t _24;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_10 = src_9(D)->addr;
  # DEBUG addr => addr_10
  # DEBUG BEGIN_STMT
  acc_11 = addr_10 & 65535;
  # DEBUG acc => acc_11
  # DEBUG BEGIN_STMT
  _1 = addr_10 >> 16;
  acc_12 = _1 + acc_11;
  # DEBUG acc => acc_12
  # DEBUG BEGIN_STMT
  addr_14 = dest_13(D)->addr;
  # DEBUG addr => addr_14
  # DEBUG BEGIN_STMT
  _2 = addr_14 & 65535;
  acc_15 = _2 + acc_12;
  # DEBUG acc => acc_15
  # DEBUG BEGIN_STMT
  _3 = addr_14 >> 16;
  acc_16 = _3 + acc_15;
  # DEBUG acc => acc_16
  # DEBUG BEGIN_STMT
  _4 = acc_16 >> 16;
  _5 = acc_16 & 65535;
  acc_17 = _4 + _5;
  # DEBUG acc => acc_17
  # DEBUG BEGIN_STMT
  _6 = acc_17 >> 16;
  _7 = acc_17 & 65535;
  acc_18 = _6 + _7;
  # DEBUG acc => acc_18
  # DEBUG BEGIN_STMT
  _24 = inet_cksum_pseudo_partial_base (p_19(D), proto_20(D), proto_len_21(D), chksum_len_22(D), acc_18);
  return _24;

}



;; Function ip_chksum_pseudo_partial (ip_chksum_pseudo_partial, funcdef_no=7, decl_uid=6623, cgraph_uid=8, symbol_order=7)

Modification phase of node ip_chksum_pseudo_partial/7
ip_chksum_pseudo_partial (struct pbuf * p, u8_t proto, u16_t proto_len, u16_t chksum_len, const struct ip_addr_t * src, const struct ip_addr_t * dest)
{
  u16_t _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _9 = inet_chksum_pseudo_partial (p_2(D), proto_3(D), proto_len_4(D), chksum_len_5(D), src_6(D), dest_7(D));
  return _9;

}



;; Function inet_chksum (inet_chksum, funcdef_no=8, decl_uid=6595, cgraph_uid=9, symbol_order=8)

Modification phase of node inet_chksum/8
inet_chksum (const void * dataptr, u16_t len)
{
  int _1;
  short unsigned int _2;
  u16_t _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) len_3(D);
  _2 = lwip_standard_chksum (dataptr_5(D), _1);
  _7 = ~_2;
  return _7;

}



;; Function inet_chksum_pbuf (inet_chksum_pbuf, funcdef_no=9, decl_uid=6597, cgraph_uid=10, symbol_order=9)

Modification phase of node inet_chksum_pbuf/9
inet_chksum_pbuf (struct pbuf * p)
{
  int swapped;
  struct pbuf * q;
  u32_t acc;
  void * _1;
  short unsigned int _2;
  int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;
  _Bool _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  short unsigned int _18;
  u16_t _31;
  short unsigned int _33;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG swapped => 0
  # DEBUG BEGIN_STMT
  # DEBUG acc => 0
  # DEBUG BEGIN_STMT
  # DEBUG q => p_28(D)
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = q_22->payload;
  _2 = q_22->len;
  _3 = (int) _2;
  _33 = lwip_standard_chksum (_1, _3);
  _4 = (long unsigned int) _33;
  acc_34 = _4 + acc_20;
  # DEBUG acc => acc_34
  # DEBUG BEGIN_STMT
  _5 = acc_34 >> 16;
  _6 = acc_34 & 65535;
  acc_35 = _5 + _6;
  # DEBUG acc => acc_35
  # DEBUG BEGIN_STMT
  _7 = q_22->len;
  _8 = _7 & 1;
  if (_8 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 477815111]:
  # DEBUG BEGIN_STMT
  _9 = swapped_24 == 0;
  swapped_36 = (int) _9;
  # DEBUG swapped => swapped_36
  # DEBUG BEGIN_STMT
  _10 = acc_35 << 8;
  _11 = _10 & 65535;
  _12 = acc_35 >> 8;
  _13 = _12 & 255;
  acc_37 = _11 | _13;
  # DEBUG acc => acc_37

  <bb 5> [local count: 955630223]:
  # acc_19 = PHI <acc_35(3), acc_37(4)>
  # swapped_23 = PHI <swapped_24(3), swapped_36(4)>
  # DEBUG swapped => swapped_23
  # DEBUG acc => acc_19
  # DEBUG BEGIN_STMT
  q_38 = q_22->next;
  # DEBUG q => q_38

  <bb 6> [local count: 1073741824]:
  # acc_20 = PHI <0(2), acc_19(5)>
  # q_22 = PHI <p_28(D)(2), q_38(5)>
  # swapped_24 = PHI <0(2), swapped_23(5)>
  # DEBUG swapped => swapped_24
  # DEBUG q => q_22
  # DEBUG acc => acc_20
  # DEBUG BEGIN_STMT
  if (q_22 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  # acc_26 = PHI <acc_20(6)>
  # swapped_27 = PHI <swapped_24(6)>
  # DEBUG BEGIN_STMT
  if (swapped_27 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  _14 = acc_26 << 8;
  _15 = _14 & 65535;
  _16 = acc_26 >> 8;
  _17 = _16 & 255;
  acc_30 = _15 | _17;
  # DEBUG acc => acc_30

  <bb 9> [local count: 118111601]:
  # acc_21 = PHI <acc_26(7), acc_30(8)>
  # DEBUG acc => acc_21
  # DEBUG BEGIN_STMT
  _18 = (short unsigned int) acc_21;
  _31 = ~_18;
  return _31;

}


