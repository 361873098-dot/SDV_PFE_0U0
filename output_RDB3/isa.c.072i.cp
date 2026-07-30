
IPA constant propagation start:
Determining dynamic type for call: _3 (item_5);
  Starting walk at: _3 (item_5);
  instance pointer: item_5  Outer instance pointer: item_5 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: item_5 = isa_item_internal (props_2, index_subscript_4(D));
  Starting walk at: item_5 = isa_item_internal (props_2, index_subscript_4(D));
  instance pointer: props_2  Outer instance pointer: props_2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = compare_cb_8(D) (item_11, match_item_12(D));
  Starting walk at: _1 = compare_cb_8(D) (item_11, match_item_12(D));
  instance pointer: item_11  Outer instance pointer: item_11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = compare_cb_8(D) (item_11, match_item_12(D));
Determining dynamic type for call: _1 = compare_cb_8(D) (item_11, match_item_12(D));
  Starting walk at: _1 = compare_cb_8(D) (item_11, match_item_12(D));
  instance pointer: match_item_12(D)  Outer instance pointer: match_item_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = compare_cb_8(D) (item_11, match_item_12(D));
Determining dynamic type for call: item_11 = isa_item (isa_10(D), ii_3);
  Starting walk at: item_11 = isa_item (isa_10(D), ii_3);
  instance pointer: isa_10(D)  Outer instance pointer: isa_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = compare_cb_8(D) (item_11, match_item_12(D));
Determining dynamic type for call: _2 = isa_item_internal (_1, ii_6);
  Starting walk at: _2 = isa_item_internal (_1, ii_6);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = isa_release_subscript (isa_11(D), ii_9);
  Starting walk at: _3 = isa_release_subscript (isa_11(D), ii_9);
  instance pointer: isa_11(D)  Outer instance pointer: isa_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: result_5 = isa_release_subscript.part.0 (isa_7(D), index_subscript_8(D));
  Starting walk at: result_5 = isa_release_subscript.part.0 (isa_7(D), index_subscript_8(D));
  instance pointer: isa_7(D)  Outer instance pointer: isa_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: item_9 = isa_item_internal (props_8, _1);
  Starting walk at: item_9 = isa_item_internal (props_8, _1);
  instance pointer: props_8  Outer instance pointer: props_8 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: item_7 = isa_item_internal (_2, index_subscript_6(D));
  Starting walk at: item_7 = isa_item_internal (_2, index_subscript_6(D));
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 (item_10);
  Starting walk at: _2 (item_10);
  instance pointer: item_10  Outer instance pointer: item_10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 (item_10);
Determining dynamic type for call: item_10 = isa_item_internal (props_9, ii_4);
  Starting walk at: item_10 = isa_item_internal (props_9, ii_4);
  instance pointer: props_9  Outer instance pointer: props_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 (item_10);
Determining dynamic type for call: isa_init_index (props_9);
  Starting walk at: isa_init_index (props_9);
  instance pointer: props_9  Outer instance pointer: props_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 (item_10);
Determining dynamic type for call: isa_init_index (props_4(D));
  Starting walk at: isa_init_index (props_4(D));
  instance pointer: props_4(D)  Outer instance pointer: props_4(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  isa_release_subscript.part.0/20:
    callsite  isa_release_subscript.part.0/20 -> isa_item_internal/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _3 (item_5);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  autolibc_memcpy/19:
  Jump functions of caller  isa_occupiedcount/18:
  Jump functions of caller  isa_isempty/17:
  Jump functions of caller  isa_find/16:
    callsite  isa_find/16 -> isa_item/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param 2, offset 0, for stmt _1 = compare_cb_8(D) (item_11, match_item_12(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  isa_release/15:
    callsite  isa_release/15 -> isa_release_subscript/14 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  isa_release/15 -> isa_item_internal/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  isa_release_subscript/14:
    callsite  isa_release_subscript/14 -> isa_release_subscript.part.0/20 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  isa_reserve/13:
    callsite  isa_reserve/13 -> isa_item_internal/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  isa_item/12:
    callsite  isa_item/12 -> isa_item_internal/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  isa_clear/11:
    callsite  isa_clear/11 -> isa_init_index/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  isa_clear/11 -> isa_item_internal/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _2 (item_10);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  isa_init/10:
    callsite  isa_init/10 -> isa_init_index/9 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  isa_init_index/9:
  Jump functions of caller  isa_item_internal/8:

 Propagating constants:

Not considering isa_occupiedcount for cloning; -fipa-cp-clone disabled.
Not considering isa_isempty for cloning; -fipa-cp-clone disabled.
Not considering isa_find for cloning; -fipa-cp-clone disabled.
Not considering isa_release for cloning; -fipa-cp-clone disabled.
Not considering isa_release_subscript for cloning; -fipa-cp-clone disabled.
Not considering isa_reserve for cloning; -fipa-cp-clone disabled.
Not considering isa_item for cloning; -fipa-cp-clone disabled.
Not considering isa_clear for cloning; -fipa-cp-clone disabled.
Not considering isa_init for cloning; -fipa-cp-clone disabled.

overall_size: 177, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: isa_release_subscript.part.0/20:
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
  Node: isa_occupiedcount/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: isa_isempty/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: isa_find/16:
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
  Node: isa_release/15:
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
  Node: isa_release_subscript/14:
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
  Node: isa_reserve/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: isa_item/12:
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
  Node: isa_clear/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: isa_init/10:
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
  Node: isa_init_index/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: isa_item_internal/8:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

isa_release_subscript.part.0/20 (isa_release_subscript.part.0) @06ee7d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: isa_release_subscript/14 (536870912 (estimated locally),0.50 per call) 
  Calls: isa_item_internal/8 (751619278 (estimated locally),0.70 per call) autolibc_memcpy/19 (177167401 (estimated locally),0.17 per call) 
   Indirect call(751619278 (estimated locally),0.70 per call) 
autolibc_memcpy/19 (autolibc_memcpy) @070a9620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: isa_release_subscript.part.0/20 (177167401 (estimated locally),0.17 per call) 
  Calls: 
isa_occupiedcount/18 (isa_occupiedcount) @0709d620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
isa_isempty/17 (isa_isempty) @0709d0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
isa_find/16 (isa_find) @0709dd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:115871615 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_item/12 (1014686023 (estimated locally),8.76 per call) 
   Indirect call(1014686023 (estimated locally),8.76 per call)  of param:2 (vptr maybe changed)
isa_release/15 (isa_release) @0709da80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_release_subscript/14 (55807731 (estimated locally),0.49 per call) isa_item_internal/8 (1014686025 (estimated locally),8.83 per call) 
isa_release_subscript/14 (isa_release_subscript) @0709d7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: isa_release/15 (55807731 (estimated locally),0.49 per call) 
  Calls: isa_release_subscript.part.0/20 (536870912 (estimated locally),0.50 per call) 
isa_reserve/13 (isa_reserve) @0709d540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_item_internal/8 (762356696 (estimated locally),0.71 per call) 
isa_item/12 (isa_item) @0709d2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: isa_find/16 (1014686023 (estimated locally),8.76 per call) 
  Calls: isa_item_internal/8 (762356696 (estimated locally),0.71 per call) 
isa_clear/11 (isa_clear) @0709d000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:168730857 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_init_index/9 (168730858 (estimated locally),1.00 per call) isa_item_internal/8 (955630225 (estimated locally),5.66 per call) 
   Indirect call(955630225 (estimated locally),5.66 per call) 
isa_init/10 (isa_init) @07096ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_init_index/9 (1073741824 (estimated locally),1.00 per call) 
isa_init_index/9 (isa_init_index) @07096c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: isa_clear/11 (168730858 (estimated locally),1.00 per call) isa_init/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
isa_item_internal/8 (isa_item_internal) @070969a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: isa_release/15 (1014686025 (estimated locally),8.83 per call) isa_release_subscript.part.0/20 (751619278 (estimated locally),0.70 per call) isa_reserve/13 (762356696 (estimated locally),0.71 per call) isa_item/12 (762356696 (estimated locally),0.71 per call) isa_clear/11 (955630225 (estimated locally),5.66 per call) 
  Calls: 

;; Function isa_item_internal (isa_item_internal, funcdef_no=6, decl_uid=7288, cgraph_uid=7, symbol_order=8)

Modification phase of node isa_item_internal/8
isa_item_internal (const struct pfe_isa_definition_t * props, uint32_t index_subscript)
{
  const uint32_t item_index;
  uint8_t * items;
  long unsigned int _1;
  pfe_isa_index_t * _2;
  long unsigned int _3;
  pfe_isa_index_t * _4;
  short unsigned int _5;
  long unsigned int _6;
  void * _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = props_8(D)->item_size;
  _2 = props_8(D)->item_indexes;
  _3 = index_subscript_9(D) * 2;
  _4 = _2 + _3;
  _5 = *_4;
  _6 = (long unsigned int) _5;
  item_index_10 = _1 * _6;
  # DEBUG item_index => item_index_10
  # DEBUG BEGIN_STMT
  items_11 = props_8(D)->items;
  # DEBUG items => items_11
  # DEBUG BEGIN_STMT
  _12 = items_11 + item_index_10;
  return _12;

}



;; Function isa_init (isa_init, funcdef_no=8, decl_uid=7264, cgraph_uid=9, symbol_order=10)

Modification phase of node isa_init/10
isa_init (struct pfe_isa_t * isa, const struct pfe_isa_definition_t * props)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  isa_2(D)->occupied_items_count = 0;
  # DEBUG BEGIN_STMT
  isa_2(D)->props = props_4(D);
  # DEBUG BEGIN_STMT
  isa_init_index (props_4(D));
  return;

}



;; Function isa_clear (isa_clear, funcdef_no=9, decl_uid=7266, cgraph_uid=10, symbol_order=11)

Modification phase of node isa_clear/11
isa_clear (struct pfe_isa_t * isa)
{
  const struct pfe_isa_definition_t * props;
  void * item;
  uint32_t ii;
  void (*<Te3>) (void *) _1;
  void (*<Te3>) (void *) _2;
  long unsigned int _3;

  <bb 2> [local count: 168730857]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  props_9 = isa_8(D)->props;
  # DEBUG props => props_9
  # DEBUG BEGIN_STMT
  _1 = props_9->clear_cb;
  if (_1 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 6> [local count: 118111600]:
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  item_10 = isa_item_internal (props_9, ii_4);
  # DEBUG item => item_10
  # DEBUG BEGIN_STMT
  _2 = props_9->clear_cb;
  _2 (item_10);
  # DEBUG BEGIN_STMT
  ii_12 = ii_4 + 1;
  # DEBUG ii => ii_12

  <bb 4> [local count: 1073741824]:
  # ii_4 = PHI <ii_12(3), 0(6)>
  # DEBUG ii => ii_4
  # DEBUG BEGIN_STMT
  _3 = isa_8(D)->occupied_items_count;
  if (_3 > ii_4)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 168730858]:
  # DEBUG BEGIN_STMT
  isa_8(D)->occupied_items_count = 0;
  # DEBUG BEGIN_STMT
  isa_init_index (props_9);
  return;

}



;; Function isa_item (isa_item, funcdef_no=10, decl_uid=7269, cgraph_uid=11, symbol_order=12)

Modification phase of node isa_item/12
isa_item (const struct pfe_isa_t * isa, uint32_t index_subscript)
{
  void * item;
  long unsigned int _1;
  const struct pfe_isa_definition_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG item => 0B
  # DEBUG BEGIN_STMT
  _1 = isa_5(D)->occupied_items_count;
  if (_1 > index_subscript_6(D))
    goto <bb 3>; [71.00%]
  else
    goto <bb 4>; [29.00%]

  <bb 3> [local count: 762356696]:
  # DEBUG BEGIN_STMT
  _2 = isa_5(D)->props;
  item_7 = isa_item_internal (_2, index_subscript_6(D));
  # DEBUG item => item_7

  <bb 4> [local count: 1073741824]:
  # item_3 = PHI <0B(2), item_7(3)>
  # DEBUG item => item_3
  # DEBUG BEGIN_STMT
  return item_3;

}



;; Function isa_reserve (isa_reserve, funcdef_no=11, decl_uid=7271, cgraph_uid=12, symbol_order=13)

Modification phase of node isa_reserve/13
isa_reserve (struct pfe_isa_t * isa)
{
  const struct pfe_isa_definition_t * props;
  void * item;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG item => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  props_8 = isa_7(D)->props;
  # DEBUG props => props_8
  # DEBUG BEGIN_STMT
  _1 = isa_7(D)->occupied_items_count;
  _2 = props_8->item_count;
  if (_1 < _2)
    goto <bb 3>; [71.00%]
  else
    goto <bb 4>; [29.00%]

  <bb 3> [local count: 762356696]:
  # DEBUG BEGIN_STMT
  item_9 = isa_item_internal (props_8, _1);
  # DEBUG item => item_9
  # DEBUG BEGIN_STMT
  _3 = _1 + 1;
  isa_7(D)->occupied_items_count = _3;

  <bb 4> [local count: 1073741824]:
  # item_4 = PHI <0B(2), item_9(3)>
  # DEBUG item => item_4
  # DEBUG BEGIN_STMT
  return item_4;

}



;; Function isa_release_subscript (isa_release_subscript, funcdef_no=12, decl_uid=7274, cgraph_uid=13, symbol_order=14)

Modification phase of node isa_release_subscript/14
isa_release_subscript (struct pfe_isa_t * isa, uint32_t index_subscript)
{
  bool_t result;
  long unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG result => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = isa_7(D)->occupied_items_count;
  if (_1 > index_subscript_8(D))
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870912]:
  result_5 = isa_release_subscript.part.0 (isa_7(D), index_subscript_8(D));

  <bb 4> [local count: 1073741824]:
  # result_4 = PHI <0(2), result_5(3)>
  # DEBUG result => result_4
  # DEBUG BEGIN_STMT
  return result_4;

}



;; Function isa_release (isa_release, funcdef_no=13, decl_uid=7277, cgraph_uid=14, symbol_order=15)

Modification phase of node isa_release/15
isa_release (struct pfe_isa_t * isa, const void * item)
{
  uint32_t ii;
  int32_t index_subscript;
  const struct pfe_isa_definition_t * _1;
  void * _2;
  unsigned char _3;
  long unsigned int _4;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG index_subscript => -1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _1 = isa_11(D)->props;
  _2 = isa_item_internal (_1, ii_6);
  if (_2 == item_12(D))
    goto <bb 4>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 4> [local count: 55807731]:
  # ii_9 = PHI <ii_6(3)>
  # DEBUG BEGIN_STMT
  _3 = isa_release_subscript (isa_11(D), ii_9);
  if (_3 == 1)
    goto <bb 5>; [96.19%]
  else
    goto <bb 8>; [3.81%]

  <bb 5> [local count: 53681457]:
  # DEBUG BEGIN_STMT
  index_subscript_15 = (int32_t) ii_9;
  # DEBUG index_subscript => index_subscript_15
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  ii_13 = ii_6 + 1;
  # DEBUG ii => ii_13

  <bb 7> [local count: 1073741824]:
  # ii_6 = PHI <0(2), ii_13(6)>
  # DEBUG ii => ii_6
  # DEBUG BEGIN_STMT
  _4 = isa_11(D)->occupied_items_count;
  if (_4 > ii_6)
    goto <bb 3>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 114863532]:
  # index_subscript_5 = PHI <index_subscript_15(5), -1(7), -1(4)>
  # DEBUG index_subscript => index_subscript_5
  # DEBUG BEGIN_STMT
  return index_subscript_5;

}



;; Function isa_find (isa_find, funcdef_no=14, decl_uid=7281, cgraph_uid=15, symbol_order=16)

Modification phase of node isa_find/16
isa_find (const struct pfe_isa_t * isa, const void * match_item, bool_t (*pfe_isa_items_compare_cb_t) (const void *, const void *) compare_cb)
{
  const void * item;
  int32_t find_index;
  uint32_t ii;
  unsigned char _1;
  long unsigned int _2;

  <bb 2> [local count: 115871615]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG find_index => -1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (compare_cb_8(D) != 0B)
    goto <bb 8>; [99.13%]
  else
    goto <bb 7>; [0.87%]

  <bb 8> [local count: 114863532]:
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 1014686023]:
  # DEBUG BEGIN_STMT
  item_11 = isa_item (isa_10(D), ii_3);
  # DEBUG item => item_11
  # DEBUG BEGIN_STMT
  _1 = compare_cb_8(D) (item_11, match_item_12(D));
  if (_1 == 1)
    goto <bb 4>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 4> [local count: 55807731]:
  # ii_7 = PHI <ii_3(3)>
  # DEBUG BEGIN_STMT
  find_index_15 = (int32_t) ii_7;
  # DEBUG find_index => find_index_15
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  ii_14 = ii_3 + 1;
  # DEBUG ii => ii_14

  <bb 6> [local count: 1073741824]:
  # ii_3 = PHI <ii_14(5), 0(8)>
  # DEBUG ii => ii_3
  # DEBUG BEGIN_STMT
  _2 = isa_10(D)->occupied_items_count;
  if (_2 > ii_3)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 115871615]:
  # find_index_4 = PHI <-1(2), find_index_15(4), -1(6)>
  # DEBUG find_index => find_index_4
  # DEBUG BEGIN_STMT
  return find_index_4;

}



;; Function isa_isempty (isa_isempty, funcdef_no=15, decl_uid=7283, cgraph_uid=16, symbol_order=17)

Modification phase of node isa_isempty/17
isa_isempty (const struct pfe_isa_t * isa)
{
  bool_t result;
  long unsigned int _1;
  _Bool _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = isa_4(D)->occupied_items_count;
  _2 = _1 == 0;
  result_5 = (bool_t) _2;
  # DEBUG result => result_5
  # DEBUG BEGIN_STMT
  return result_5;

}



;; Function isa_occupiedcount (isa_occupiedcount, funcdef_no=16, decl_uid=7285, cgraph_uid=17, symbol_order=18)

Modification phase of node isa_occupiedcount/18
isa_occupiedcount (const struct pfe_isa_t * isa)
{
  uint32_t result;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  result_3 = isa_2(D)->occupied_items_count;
  # DEBUG result => result_3
  # DEBUG BEGIN_STMT
  return result_3;

}


