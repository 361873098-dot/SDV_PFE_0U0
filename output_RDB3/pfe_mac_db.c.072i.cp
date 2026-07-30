
IPA constant propagation start:
Determining dynamic type for call: ret_6 = pfe_mac_db_check_crit_by_type (_4, type_5(D));
  Starting walk at: ret_6 = pfe_mac_db_check_crit_by_type (_4, type_5(D));
  instance pointer: _4  Outer instance pointer: entry_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_emac_is_multi (addr_1(D));
  Starting walk at: _2 = pfe_emac_is_multi (addr_1(D));
  instance pointer: addr_1(D)  Outer instance pointer: addr_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_mac_db_criterion_eval (entry_14, crit_15(D), type_16(D), owner_17(D));
  Starting walk at: _1 = pfe_mac_db_criterion_eval (entry_14, crit_15(D), type_16(D), owner_17(D));
  instance pointer: entry_14  Outer instance pointer: entry_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_14 = isa_item (isa_11, db_idx_7);
  Function call may change dynamic type:entry_14 = isa_item (isa_11, db_idx_7);
Determining dynamic type for call: _6 = pfe_mac_db_criterion_eval (entry_21, _3, _4, _5);
  Starting walk at: _6 = pfe_mac_db_criterion_eval (entry_21, _3, _4, _5);
  instance pointer: entry_21  Outer instance pointer: entry_21 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_21 = isa_item (isa_18, _7);
  Function call may change dynamic type:entry_21 = isa_item (isa_18, _7);
Determining dynamic type for call: _1 = pfe_mac_db_criterion_eval (entry_21, crit_22(D), type_23(D), owner_24(D));
  Starting walk at: _1 = pfe_mac_db_criterion_eval (entry_21, crit_22(D), type_23(D), owner_24(D));
  instance pointer: entry_21  Outer instance pointer: entry_21 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_21 = isa_item (isa_17, _4);
  Function call may change dynamic type:entry_21 = isa_item (isa_17, _4);
Determining dynamic type for call: _1 = pfe_mac_db_criterion_eval (entry_13, crit_14(D), type_15(D), owner_16(D));
  Starting walk at: _1 = pfe_mac_db_criterion_eval (entry_13, crit_14(D), type_15(D), owner_16(D));
  instance pointer: entry_13  Outer instance pointer: entry_13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:entry_13 = isa_item (isa_10, mac_idx_6);
  Function call may change dynamic type:entry_13 = isa_item (isa_10, mac_idx_6);
  Function call may change dynamic type:isa_release_subscript (isa_10, mac_idx_6);
Determining dynamic type for call: entry_12 = pfe_mac_db_find_by_addr (db_6(D), addr_9(D), owner_10(D));
  Starting walk at: entry_12 = pfe_mac_db_find_by_addr (db_6(D), addr_9(D), owner_10(D));
  instance pointer: db_6(D)  Outer instance pointer: db_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: entry_12 = pfe_mac_db_find_by_addr (db_6(D), addr_9(D), owner_10(D));
  Starting walk at: entry_12 = pfe_mac_db_find_by_addr (db_6(D), addr_9(D), owner_10(D));
  instance pointer: addr_9(D)  Outer instance pointer: addr_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: entry_10 = pfe_mac_db_find_by_addr (db_6(D), addr_7(D), owner_8(D));
  Starting walk at: entry_10 = pfe_mac_db_find_by_addr (db_6(D), addr_7(D), owner_8(D));
  instance pointer: db_6(D)  Outer instance pointer: db_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: entry_10 = pfe_mac_db_find_by_addr (db_6(D), addr_7(D), owner_8(D));
  Starting walk at: entry_10 = pfe_mac_db_find_by_addr (db_6(D), addr_7(D), owner_8(D));
  instance pointer: addr_7(D)  Outer instance pointer: addr_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_4 = pfe_mac_db_criterion_eval.part.0 (entry_7(D), type_9(D), owner_8(D));
  Starting walk at: ret_4 = pfe_mac_db_criterion_eval.part.0 (entry_7(D), type_9(D), owner_8(D));
  instance pointer: entry_7(D)  Outer instance pointer: entry_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_10 = pfe_mac_db_check_crit_by_type (_2, type_9(D));
  Starting walk at: ret_10 = pfe_mac_db_check_crit_by_type (_2, type_9(D));
  instance pointer: _2  Outer instance pointer: entry_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_emac_is_multi (addr_7(D));
  Starting walk at: _1 = pfe_emac_is_multi (addr_7(D));
  instance pointer: addr_7(D)  Outer instance pointer: addr_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_emac_is_broad (addr_7(D));
  Starting walk at: _2 = pfe_emac_is_broad (addr_7(D));
  instance pointer: addr_7(D)  Outer instance pointer: addr_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_4 = pfe_mac_db_check_crit_by_type.part.0 (addr_7(D));
  Starting walk at: ret_4 = pfe_mac_db_check_crit_by_type.part.0 (addr_7(D));
  instance pointer: addr_7(D)  Outer instance pointer: addr_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_emac_is_broad (addr_5(D));
  Starting walk at: _1 = pfe_emac_is_broad (addr_5(D));
  instance pointer: addr_5(D)  Outer instance pointer: addr_5(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_mac_db_criterion_eval.part.0/30:
    callsite  pfe_mac_db_criterion_eval.part.0/30 -> pfe_mac_db_check_crit_by_type/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_mac_db_check_crit_by_type.part.0/29:
    callsite  pfe_mac_db_check_crit_by_type.part.0/29 -> pfe_emac_is_multi/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  isa_release_subscript/28:
  Jump functions of caller  isa_release/27:
  Jump functions of caller  autolibc_memcmp/26:
  Jump functions of caller  isa_item/25:
  Jump functions of caller  autolibc_memcpy/24:
  Jump functions of caller  isa_reserve/23:
  Jump functions of caller  isa_init/22:
  Jump functions of caller  autolibc_memset/21:
  Jump functions of caller  pfe_mac_db_find_by_crit/20:
    callsite  pfe_mac_db_find_by_crit/20 -> pfe_mac_db_criterion_eval/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_mac_db_get_next_addr/19:
    callsite  pfe_mac_db_get_next_addr/19 -> pfe_mac_db_criterion_eval/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_mac_db_get_first_addr/18:
    callsite  pfe_mac_db_get_first_addr/18 -> pfe_mac_db_criterion_eval/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_mac_db_flush/17:
    callsite  pfe_mac_db_flush/17 -> pfe_mac_db_criterion_eval/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_mac_db_del_addr/16:
    callsite  pfe_mac_db_del_addr/16 -> pfe_mac_db_find_by_addr/14 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_mac_db_add_addr/15:
    callsite  pfe_mac_db_add_addr/15 -> pfe_mac_db_find_by_addr/14 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_mac_db_find_by_addr/14:
  Jump functions of caller  pfe_mac_db_create/13:
  Jump functions of caller  pfe_mac_db_criterion_eval/12:
    callsite  pfe_mac_db_criterion_eval/12 -> pfe_mac_db_criterion_eval.part.0/30 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_mac_db_criterion_eval/12 -> pfe_mac_db_check_crit_by_type/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_mac_db_check_crit_by_type/11:
    callsite  pfe_mac_db_check_crit_by_type/11 -> pfe_mac_db_check_crit_by_type.part.0/29 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_mac_db_check_crit_by_type/11 -> pfe_emac_is_broad/9 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_mac_db_check_crit_by_type/11 -> pfe_emac_is_multi/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_is_multi/10:
    callsite  pfe_emac_is_multi/10 -> pfe_emac_is_broad/9 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_is_broad/9:

 Propagating constants:

Not considering pfe_mac_db_find_by_crit for cloning; -fipa-cp-clone disabled.
Not considering pfe_mac_db_get_next_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_mac_db_get_first_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_mac_db_flush for cloning; -fipa-cp-clone disabled.
Not considering pfe_mac_db_del_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_mac_db_add_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_mac_db_create for cloning; -fipa-cp-clone disabled.

overall_size: 305, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_mac_db_criterion_eval.part.0/30:
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
  Node: pfe_mac_db_check_crit_by_type.part.0/29:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_mac_db_find_by_crit/20:
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
  Node: pfe_mac_db_get_next_addr/19:
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
  Node: pfe_mac_db_get_first_addr/18:
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
  Node: pfe_mac_db_flush/17:
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
  Node: pfe_mac_db_del_addr/16:
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
  Node: pfe_mac_db_add_addr/15:
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
  Node: pfe_mac_db_find_by_addr/14:
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
  Node: pfe_mac_db_create/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mac_db_criterion_eval/12:
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
  Node: pfe_mac_db_check_crit_by_type/11:
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
  Node: pfe_emac_is_multi/10:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_emac_is_broad/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_mac_db_criterion_eval.part.0/30 (pfe_mac_db_criterion_eval.part.0) @070529a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_mac_db_criterion_eval/12 (120473834 (estimated locally),0.11 per call) 
  Calls: pfe_mac_db_check_crit_by_type/11 (365072220 (estimated locally),0.34 per call) 
pfe_mac_db_check_crit_by_type.part.0/29 (pfe_mac_db_check_crit_by_type.part.0) @06e15d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_mac_db_check_crit_by_type/11 (277147700 (estimated locally),0.26 per call) 
  Calls: pfe_emac_is_multi/10 (1073741824 (estimated locally),1.00 per call) 
isa_release_subscript/28 (isa_release_subscript) @072b3620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mac_db_flush/17 (135393690 (estimated locally),1.15 per call) 
  Calls: 
isa_release/27 (isa_release) @072b3460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mac_db_del_addr/16 (731110809 (estimated locally),0.68 per call) 
  Calls: 
autolibc_memcmp/26 (autolibc_memcmp) @072b32a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mac_db_find_by_addr/14 (143760716 (estimated locally),2.15 per call) 
  Calls: 
isa_item/25 (isa_item) @072b31c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mac_db_find_by_crit/20 (1014686024 (estimated locally),10.34 per call) pfe_mac_db_get_next_addr/19 (1014686024 (estimated locally),10.34 per call) pfe_mac_db_get_first_addr/18 (1014686024 (estimated locally),10.34 per call) pfe_mac_db_flush/17 (955630223 (estimated locally),8.09 per call) pfe_mac_db_find_by_addr/14 (1014686025 (estimated locally),15.15 per call) 
  Calls: 
autolibc_memcpy/24 (autolibc_memcpy) @072b3000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mac_db_find_by_crit/20 (20888276 (estimated locally),0.21 per call) pfe_mac_db_get_next_addr/19 (31428224 (estimated locally),0.32 per call) pfe_mac_db_get_first_addr/18 (31428224 (estimated locally),0.32 per call) pfe_mac_db_add_addr/15 (205880803 (estimated locally),0.19 per call) 
  Calls: 
isa_reserve/23 (isa_reserve) @0725fa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mac_db_add_addr/15 (302365698 (estimated locally),0.28 per call) 
  Calls: 
isa_init/22 (isa_init) @0725f540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mac_db_create/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/21 (autolibc_memset) @0725f2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mac_db_create/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_mac_db_find_by_crit/20 (pfe_mac_db_find_by_crit) @0725fc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:98121214 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/24 (20888276 (estimated locally),0.21 per call) pfe_mac_db_criterion_eval/12 (710280217 (estimated locally),7.24 per call) isa_item/25 (1014686024 (estimated locally),10.34 per call) 
pfe_mac_db_get_next_addr/19 (pfe_mac_db_get_next_addr) @0725f9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:98121214 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/24 (31428224 (estimated locally),0.32 per call) pfe_mac_db_criterion_eval/12 (710280217 (estimated locally),7.24 per call) isa_item/25 (1014686024 (estimated locally),10.34 per call) 
pfe_mac_db_get_first_addr/18 (pfe_mac_db_get_first_addr) @0725f700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:98121214 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/24 (31428224 (estimated locally),0.32 per call) pfe_mac_db_criterion_eval/12 (710280217 (estimated locally),7.24 per call) isa_item/25 (1014686024 (estimated locally),10.34 per call) 
pfe_mac_db_flush/17 (pfe_mac_db_flush) @0725f460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_release_subscript/28 (135393690 (estimated locally),1.15 per call) pfe_mac_db_criterion_eval/12 (668941156 (estimated locally),5.66 per call) isa_item/25 (955630223 (estimated locally),8.09 per call) 
pfe_mac_db_del_addr/16 (pfe_mac_db_del_addr) @0725f1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_release/27 (731110809 (estimated locally),0.68 per call) pfe_mac_db_find_by_addr/14 (1073741824 (estimated locally),1.00 per call) 
pfe_mac_db_add_addr/15 (pfe_mac_db_add_addr) @07253b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/24 (205880803 (estimated locally),0.19 per call) isa_reserve/23 (302365698 (estimated locally),0.28 per call) pfe_mac_db_find_by_addr/14 (1073741824 (estimated locally),1.00 per call) 
pfe_mac_db_find_by_addr/14 (pfe_mac_db_find_by_addr) @07253620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:66962640 (estimated locally) body local optimize_size
  Called by: pfe_mac_db_del_addr/16 (1073741824 (estimated locally),1.00 per call) pfe_mac_db_add_addr/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: autolibc_memcmp/26 (143760716 (estimated locally),2.15 per call) isa_item/25 (1014686025 (estimated locally),15.15 per call) 
pfe_mac_db_create/13 (pfe_mac_db_create) @07253d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_init/22 (1073741824 (estimated locally),1.00 per call) autolibc_memset/21 (1073741824 (estimated locally),1.00 per call) 
pfe_mac_db_criterion_eval/12 (pfe_mac_db_criterion_eval) @07253a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_mac_db_find_by_crit/20 (710280217 (estimated locally),7.24 per call) pfe_mac_db_get_next_addr/19 (710280217 (estimated locally),7.24 per call) pfe_mac_db_get_first_addr/18 (710280217 (estimated locally),7.24 per call) pfe_mac_db_flush/17 (668941156 (estimated locally),5.66 per call) 
  Calls: pfe_mac_db_criterion_eval.part.0/30 (120473834 (estimated locally),0.11 per call) pfe_mac_db_check_crit_by_type/11 (354334802 (estimated locally),0.33 per call) 
pfe_mac_db_check_crit_by_type/11 (pfe_mac_db_check_crit_by_type) @072537e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_mac_db_criterion_eval/12 (354334802 (estimated locally),0.33 per call) pfe_mac_db_criterion_eval.part.0/30 (365072220 (estimated locally),0.34 per call) 
  Calls: pfe_mac_db_check_crit_by_type.part.0/29 (277147700 (estimated locally),0.26 per call) pfe_emac_is_broad/9 (213094115 (estimated locally),0.20 per call) pfe_emac_is_multi/10 (240947665 (estimated locally),0.22 per call) 
pfe_emac_is_multi/10 (pfe_emac_is_multi) @07253380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_mac_db_check_crit_by_type/11 (240947665 (estimated locally),0.22 per call) pfe_mac_db_check_crit_by_type.part.0/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_emac_is_broad/9 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_is_broad/9 (pfe_emac_is_broad) @072530e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_mac_db_check_crit_by_type/11 (213094115 (estimated locally),0.20 per call) pfe_emac_is_multi/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function pfe_emac_is_broad (pfe_emac_is_broad, funcdef_no=7, decl_uid=7831, cgraph_uid=8, symbol_order=9)

Modification phase of node pfe_emac_is_broad/9
pfe_emac_is_broad (const uint8_t * addr)
{
  bool_t ReVal;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char _10;
  unsigned char _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = *addr_14(D);
  _2 = MEM[(const uint8_t *)addr_14(D) + 1B];
  _3 = _1 & _2;
  _4 = MEM[(const uint8_t *)addr_14(D) + 2B];
  _5 = _3 & _4;
  _6 = MEM[(const uint8_t *)addr_14(D) + 3B];
  _7 = _5 & _6;
  _8 = MEM[(const uint8_t *)addr_14(D) + 4B];
  _9 = _7 & _8;
  _10 = MEM[(const uint8_t *)addr_14(D) + 5B];
  _11 = _9 & _10;
  if (_11 == 255)
    goto <bb 4>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  # DEBUG ReVal => 0

  <bb 4> [local count: 1073741824]:
  # ReVal_12 = PHI <1(2), 0(3)>
  # DEBUG ReVal => ReVal_12
  # DEBUG BEGIN_STMT
  return ReVal_12;

}



;; Function pfe_mac_db_find_by_addr (pfe_mac_db_find_by_addr, funcdef_no=12, decl_uid=7865, cgraph_uid=13, symbol_order=14)

Modification phase of node pfe_mac_db_find_by_addr/14
pfe_mac_db_find_by_addr (const struct pfe_mac_db_t * db, const uint8_t * addr, pfe_drv_id_t owner)
{
  uint32_t mac_idx;
  bool_t found;
  const struct pfe_isa_t * isa;
  struct pfe_mac_db_list_entry_t * entry;
  <unnamed type> _1;
  uint8_t[6] * _2;
  long int _3;
  long unsigned int _4;

  <bb 2> [local count: 66962640]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  isa_14 = &db_13(D)->mac_list;
  # DEBUG isa => isa_14
  # DEBUG BEGIN_STMT
  # DEBUG found => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mac_idx => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  entry_18 = isa_item (isa_14, mac_idx_9);
  # DEBUG entry => entry_18
  # DEBUG BEGIN_STMT
  if (entry_18 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 4> [local count: 710280218]:
  _1 = entry_18->owner;
  if (_1 == owner_19(D))
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 143760716]:
  _2 = &entry_18->addr;
  _3 = autolibc_memcmp (addr_20(D), _2, 6);
  if (_3 == 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 1006779185]:
  # DEBUG BEGIN_STMT
  mac_idx_22 = mac_idx_9 + 1;
  # DEBUG mac_idx => mac_idx_22

  <bb 7> [local count: 1073741824]:
  # entry_5 = PHI <entry_15(D)(2), entry_18(6)>
  # mac_idx_9 = PHI <0(2), mac_idx_22(6)>
  # DEBUG mac_idx => mac_idx_9
  # DEBUG entry => entry_5
  # DEBUG BEGIN_STMT
  _4 = MEM[(const struct pfe_isa_t *)db_13(D)].occupied_items_count;
  if (_4 > mac_idx_9)
    goto <bb 3>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 66962640]:
  # entry_6 = PHI <entry_18(5), entry_5(7)>
  # found_8 = PHI <1(5), 0(7)>
  # DEBUG found => found_8
  # DEBUG entry => entry_6
  # DEBUG BEGIN_STMT
  if (found_8 == 0)
    goto <bb 9>; [29.00%]
  else
    goto <bb 10>; [71.00%]

  <bb 9> [local count: 19419166]:
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B

  <bb 10> [local count: 66962640]:
  # entry_7 = PHI <entry_6(8), 0B(9)>
  # DEBUG entry => entry_7
  # DEBUG BEGIN_STMT
  return entry_7;

}



;; Function pfe_mac_db_check_crit_by_type (pfe_mac_db_check_crit_by_type, funcdef_no=9, decl_uid=7845, cgraph_uid=10, symbol_order=11)

Modification phase of node pfe_mac_db_check_crit_by_type/11
pfe_mac_db_check_crit_by_type (const uint8_t * addr, pfe_mac_type_t type)
{
  bool_t ret;
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (type_5(D) == 3)
    goto <bb 9>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 708669604]:
  if (type_5(D) == 1)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 240947665]:
  _1 = pfe_emac_is_multi (addr_7(D));
  if (_1 == 1)
    goto <bb 9>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 626747398]:
  if (type_5(D) == 2)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 213094115]:
  _2 = pfe_emac_is_broad (addr_7(D));
  if (_2 == 1)
    goto <bb 9>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 7> [local count: 554295399]:
  if (type_5(D) == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 277147700]:
  # DEBUG D#1 => type_5(D)
  ret_4 = pfe_mac_db_check_crit_by_type.part.0 (addr_7(D));

  <bb 9> [local count: 1073741824]:
  # ret_3 = PHI <0(7), 1(6), 1(4), 1(2), ret_4(8)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_mac_db_criterion_eval (pfe_mac_db_criterion_eval, funcdef_no=10, decl_uid=7842, cgraph_uid=11, symbol_order=12)

Modification phase of node pfe_mac_db_criterion_eval/12
pfe_mac_db_criterion_eval (const struct pfe_mac_db_list_entry_t * entry, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
{
  bool_t ret;
  <unnamed type> _1;
  const uint8_t[6] * _2;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (crit_5(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  _1 = entry_7(D)->owner;
  if (_1 == owner_8(D))
    goto <bb 4>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 4> [local count: 124124555]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1
  goto <bb 11>; [100.00%]

  <bb 5> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  if (crit_5(D) == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = &entry_7(D)->addr;
  ret_10 = pfe_mac_db_check_crit_by_type (_2, type_9(D));
  # DEBUG ret => ret_10
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  if (crit_5(D) == 2)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 120473834]:
  # DEBUG D#3 => crit_5(D)
  ret_4 = pfe_mac_db_criterion_eval.part.0 (entry_7(D), type_9(D), owner_8(D));
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 233860969]:
  # DEBUG BEGIN_STMT
  if (crit_5(D) == 3)
    goto <bb 10>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 10> [local count: 79512729]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1

  <bb 11> [local count: 1073741824]:
  # ret_3 = PHI <1(4), ret_10(6), ret_4(8), 0(9), 1(10), 0(3)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_mac_db_create (pfe_mac_db_create, funcdef_no=11, decl_uid=7797, cgraph_uid=12, symbol_order=13)

Modification phase of node pfe_mac_db_create/13
pfe_mac_db_create (struct pfe_mac_db_t * db)
{
  pfe_isa_index_t[8] * _1;
  struct pfe_mac_db_list_entry_t[8] * _2;
  struct pfe_isa_t * _3;
  struct pfe_isa_definition_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (db_6(D), 0, 116);
  # DEBUG BEGIN_STMT
  db_6(D)->crit.crit = 4;
  # DEBUG BEGIN_STMT
  db_6(D)->next_item = 0;
  # DEBUG BEGIN_STMT
  db_6(D)->isa_def.item_count = 8;
  # DEBUG BEGIN_STMT
  db_6(D)->isa_def.item_size = 7;
  # DEBUG BEGIN_STMT
  db_6(D)->isa_def.flags.ordered = 1;
  # DEBUG BEGIN_STMT
  _1 = &db_6(D)->mac_list_idx;
  db_6(D)->isa_def.item_indexes = _1;
  # DEBUG BEGIN_STMT
  _2 = &db_6(D)->mac_list_pool;
  db_6(D)->isa_def.items = _2;
  # DEBUG BEGIN_STMT
  db_6(D)->isa_def.clear_cb = 0B;
  # DEBUG BEGIN_STMT
  _3 = &db_6(D)->mac_list;
  _4 = &db_6(D)->isa_def;
  isa_init (_3, _4);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_mac_db_add_addr (pfe_mac_db_add_addr, funcdef_no=13, decl_uid=7801, cgraph_uid=14, symbol_order=15)

Modification phase of node pfe_mac_db_add_addr/15
pfe_mac_db_add_addr (struct pfe_mac_db_t * db, const uint8_t * addr, pfe_drv_id_t owner)
{
  struct pfe_mac_db_list_entry_t * entry;
  errno_t ret;
  struct pfe_isa_t * _1;
  uint8_t[6] * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_10 = pfe_mac_db_find_by_addr (db_6(D), addr_7(D), owner_8(D));
  # DEBUG entry => entry_10
  # DEBUG BEGIN_STMT
  if (entry_10 == 0B)
    goto <bb 3>; [28.16%]
  else
    goto <bb 5>; [71.84%]

  <bb 3> [local count: 302365698]:
  # DEBUG BEGIN_STMT
  _1 = &db_6(D)->mac_list;
  entry_12 = isa_reserve (_1);
  # DEBUG entry => entry_12
  # DEBUG BEGIN_STMT
  if (entry_12 == 0B)
    goto <bb 5>; [31.91%]
  else
    goto <bb 4>; [68.09%]

  <bb 4> [local count: 205880803]:
  # DEBUG BEGIN_STMT
  _2 = &entry_12->addr;
  autolibc_memcpy (_2, addr_7(D), 6);
  # DEBUG BEGIN_STMT
  entry_12->owner = owner_8(D);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_3 = PHI <0(4), 116(2), 11(3)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_mac_db_del_addr (pfe_mac_db_del_addr, funcdef_no=14, decl_uid=7805, cgraph_uid=15, symbol_order=16)

Modification phase of node pfe_mac_db_del_addr/16
pfe_mac_db_del_addr (struct pfe_mac_db_t * db, const uint8_t * addr, pfe_drv_id_t owner)
{
  const int32_t item_index;
  struct pfe_isa_t * isa;
  struct pfe_mac_db_list_entry_t * entry;
  errno_t ret;
  long unsigned int _1;
  long unsigned int item_index.0_2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  isa_7 = &db_6(D)->mac_list;
  # DEBUG isa => isa_7
  # DEBUG BEGIN_STMT
  entry_12 = pfe_mac_db_find_by_addr (db_6(D), addr_9(D), owner_10(D));
  # DEBUG entry => entry_12
  # DEBUG BEGIN_STMT
  if (entry_12 == 0B)
    goto <bb 7>; [31.91%]
  else
    goto <bb 3>; [68.09%]

  <bb 3> [local count: 731110809]:
  # DEBUG BEGIN_STMT
  item_index_14 = isa_release (isa_7, entry_12);
  # DEBUG item_index => item_index_14
  # DEBUG BEGIN_STMT
  if (item_index_14 != -1)
    goto <bb 4>; [78.28%]
  else
    goto <bb 7>; [21.72%]

  <bb 4> [local count: 572313541]:
  # DEBUG BEGIN_STMT
  _1 = db_6(D)->next_item;
  item_index.0_2 = (long unsigned int) item_index_14;
  if (_1 > item_index.0_2)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 286156770]:
  # DEBUG BEGIN_STMT
  _3 = _1 + 4294967295;
  db_6(D)->next_item = _3;

  <bb 7> [local count: 1073741824]:
  # ret_4 = PHI <2(2), 2(3), 0(5), 0(4)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_mac_db_flush (pfe_mac_db_flush, funcdef_no=15, decl_uid=7810, cgraph_uid=16, symbol_order=17)

Modification phase of node pfe_mac_db_flush/17
pfe_mac_db_flush (struct pfe_mac_db_t * db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
{
  uint32_t mac_idx;
  struct pfe_isa_t * isa;
  const struct pfe_mac_db_list_entry_t * entry;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  isa_10 = &db_9(D)->mac_list;
  # DEBUG isa => isa_10
  # DEBUG BEGIN_STMT
  # DEBUG mac_idx => 0
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  entry_13 = isa_item (isa_10, mac_idx_6);
  # DEBUG entry => entry_13
  # DEBUG BEGIN_STMT
  if (entry_13 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 4> [local count: 668941156]:
  # DEBUG BEGIN_STMT
  _1 = pfe_mac_db_criterion_eval (entry_13, crit_14(D), type_15(D), owner_16(D));
  if (_1 == 1)
    goto <bb 5>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 5> [local count: 135393690]:
  # DEBUG BEGIN_STMT
  isa_release_subscript (isa_10, mac_idx_6);
  # DEBUG BEGIN_STMT
  _2 = db_9(D)->next_item;
  if (_2 > mac_idx_6)
    goto <bb 6>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 6> [local count: 67696845]:
  # DEBUG BEGIN_STMT
  _4 = _2 + 4294967295;
  db_9(D)->next_item = _4;
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 533547465]:
  # DEBUG BEGIN_STMT
  mac_idx_17 = mac_idx_6 + 1;
  # DEBUG mac_idx => mac_idx_17

  <bb 9> [local count: 955630223]:
  # mac_idx_8 = PHI <mac_idx_6(3), mac_idx_6(6), mac_idx_6(5), mac_idx_17(7)>

  <bb 11> [local count: 1073741824]:
  # mac_idx_6 = PHI <mac_idx_8(9), 0(2)>
  # DEBUG mac_idx => mac_idx_6
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct pfe_isa_t *)db_9(D)].occupied_items_count;
  if (_5 > mac_idx_6)
    goto <bb 3>; [89.00%]
  else
    goto <bb 10>; [11.00%]

  <bb 10> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_mac_db_get_first_addr (pfe_mac_db_get_first_addr, funcdef_no=16, decl_uid=7816, cgraph_uid=17, symbol_order=18)

Modification phase of node pfe_mac_db_get_first_addr/18
pfe_mac_db_get_first_addr (struct pfe_mac_db_t * db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner, uint8_t * addr)
{
  bool_t found;
  const struct pfe_isa_t * isa;
  const struct pfe_mac_db_list_entry_t * entry;
  errno_t ret;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  const uint8_t[6] * _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 98121214]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  isa_17 = &db_16(D)->mac_list;
  # DEBUG isa => isa_17
  # DEBUG BEGIN_STMT
  # DEBUG found => 0
  # DEBUG BEGIN_STMT
  db_16(D)->next_item = 0;
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  entry_21 = isa_item (isa_17, _4);
  # DEBUG entry => entry_21
  # DEBUG BEGIN_STMT
  if (entry_21 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 710280217]:
  # DEBUG BEGIN_STMT
  _1 = pfe_mac_db_criterion_eval (entry_21, crit_22(D), type_23(D), owner_24(D));
  if (_1 == 1)
    goto <bb 7>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 5> [local count: 975620612]:
  # DEBUG BEGIN_STMT
  _2 = db_16(D)->next_item;
  _3 = _2 + 1;
  db_16(D)->next_item = _3;

  <bb 6> [local count: 1073741824]:
  # entry_10 = PHI <0B(2), entry_21(5)>
  # DEBUG entry => entry_10
  # DEBUG BEGIN_STMT
  _4 = db_16(D)->next_item;
  _5 = MEM[(const struct pfe_isa_t *)db_16(D)].occupied_items_count;
  if (_4 < _5)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 98121212]:
  # entry_11 = PHI <entry_21(4), entry_10(6)>
  # found_12 = PHI <1(4), 0(6)>
  # DEBUG found => found_12
  # DEBUG entry => entry_11
  # DEBUG BEGIN_STMT
  if (found_12 == 1)
    goto <bb 8>; [32.03%]
  else
    goto <bb 9>; [67.97%]

  <bb 8> [local count: 31428224]:
  # DEBUG BEGIN_STMT
  _6 = &entry_11->addr;
  autolibc_memcpy (addr_26(D), _6, 6);
  # DEBUG BEGIN_STMT
  _7 = db_16(D)->next_item;
  _8 = _7 + 1;
  db_16(D)->next_item = _8;
  # DEBUG BEGIN_STMT
  db_16(D)->crit.crit = crit_22(D);
  # DEBUG BEGIN_STMT
  db_16(D)->crit.owner = owner_24(D);
  # DEBUG BEGIN_STMT
  db_16(D)->crit.type = type_23(D);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 9> [local count: 98121212]:
  # ret_9 = PHI <2(7), 0(8)>
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  return ret_9;

}



;; Function pfe_mac_db_get_next_addr (pfe_mac_db_get_next_addr, funcdef_no=17, decl_uid=7819, cgraph_uid=18, symbol_order=19)

Modification phase of node pfe_mac_db_get_next_addr/19
pfe_mac_db_get_next_addr (struct pfe_mac_db_t * db, uint8_t * addr)
{
  bool_t found;
  const struct pfe_isa_t * isa;
  const struct pfe_mac_db_list_entry_t * entry;
  errno_t ret;
  long unsigned int _1;
  long unsigned int _2;
  <unnamed type> _3;
  <unnamed type> _4;
  <unnamed type> _5;
  unsigned char _6;
  long unsigned int _7;
  long unsigned int _8;
  const uint8_t[6] * _9;

  <bb 2> [local count: 98121214]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  isa_18 = &db_17(D)->mac_list;
  # DEBUG isa => isa_18
  # DEBUG BEGIN_STMT
  # DEBUG found => 0
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  entry_21 = isa_item (isa_18, _7);
  # DEBUG entry => entry_21
  # DEBUG BEGIN_STMT
  _1 = db_17(D)->next_item;
  _2 = _1 + 1;
  db_17(D)->next_item = _2;
  # DEBUG BEGIN_STMT
  if (entry_21 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 710280217]:
  # DEBUG BEGIN_STMT
  _3 = db_17(D)->crit.crit;
  _4 = db_17(D)->crit.type;
  _5 = db_17(D)->crit.owner;
  _6 = pfe_mac_db_criterion_eval (entry_21, _3, _4, _5);
  if (_6 == 1)
    goto <bb 7>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 5> [local count: 975620612]:
  # entry_25 = PHI <entry_21(3), entry_21(4)>

  <bb 6> [local count: 1073741824]:
  # entry_11 = PHI <entry_25(5), 0B(2)>
  # DEBUG entry => entry_11
  # DEBUG BEGIN_STMT
  _7 = db_17(D)->next_item;
  _8 = MEM[(const struct pfe_isa_t *)db_17(D)].occupied_items_count;
  if (_7 < _8)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 98121212]:
  # entry_12 = PHI <entry_21(4), entry_11(6)>
  # found_13 = PHI <1(4), 0(6)>
  # DEBUG found => found_13
  # DEBUG entry => entry_12
  # DEBUG BEGIN_STMT
  if (found_13 == 1)
    goto <bb 8>; [32.03%]
  else
    goto <bb 9>; [67.97%]

  <bb 8> [local count: 31428224]:
  # DEBUG BEGIN_STMT
  _9 = &entry_12->addr;
  autolibc_memcpy (addr_23(D), _9, 6);

  <bb 9> [local count: 98121212]:
  # ret_10 = PHI <0(8), 2(7)>
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  return ret_10;

}



;; Function pfe_mac_db_find_by_crit (pfe_mac_db_find_by_crit, funcdef_no=18, decl_uid=7825, cgraph_uid=19, symbol_order=20)

Modification phase of node pfe_mac_db_find_by_crit/20
pfe_mac_db_find_by_crit (struct pfe_mac_db_t * db, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner, struct pfe_mac_db_list_entry_t * match_entry)
{
  uint32_t db_idx;
  const struct pfe_isa_t * isa;
  const struct pfe_mac_db_list_entry_t * entry;
  errno_t ret;
  unsigned char _1;
  uint8_t[6] * _2;
  const uint8_t[6] * _3;
  <unnamed type> _4;
  long unsigned int _5;

  <bb 2> [local count: 98121214]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  isa_11 = &db_10(D)->mac_list;
  # DEBUG isa => isa_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG db_idx => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  entry_14 = isa_item (isa_11, db_idx_7);
  # DEBUG entry => entry_14
  # DEBUG BEGIN_STMT
  if (entry_14 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 4> [local count: 710280217]:
  # DEBUG BEGIN_STMT
  _1 = pfe_mac_db_criterion_eval (entry_14, crit_15(D), type_16(D), owner_17(D));
  if (_1 == 1)
    goto <bb 5>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 5> [local count: 39065412]:
  # entry_22 = PHI <entry_14(4)>
  # DEBUG BEGIN_STMT
  if (match_entry_18(D) != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 6> [local count: 20888276]:
  # DEBUG BEGIN_STMT
  _2 = &match_entry_18(D)->addr;
  _3 = &entry_22->addr;
  autolibc_memcpy (_2, _3, 6);
  # DEBUG BEGIN_STMT
  _4 = entry_22->owner;
  match_entry_18(D)->owner = _4;
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 975620612]:
  # DEBUG BEGIN_STMT
  db_idx_21 = db_idx_7 + 1;
  # DEBUG db_idx => db_idx_21

  <bb 8> [local count: 1073741824]:
  # db_idx_7 = PHI <0(2), db_idx_21(7)>
  # DEBUG db_idx => db_idx_7
  # DEBUG BEGIN_STMT
  _5 = MEM[(const struct pfe_isa_t *)db_10(D)].occupied_items_count;
  if (_5 > db_idx_7)
    goto <bb 3>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 98121212]:
  # ret_6 = PHI <0(6), 2(8), 0(5)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}


