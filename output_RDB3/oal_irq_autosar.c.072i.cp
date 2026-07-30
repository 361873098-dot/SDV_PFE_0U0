
IPA constant propagation start:
Determining dynamic type for call: _1 (_2);
  Starting walk at: _1 (_2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 (_2);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  oal_irq_in_atomic/15:
  Jump functions of caller  oal_irq_get_id/14:
  Jump functions of caller  oal_irq_destroy/13:
  Jump functions of caller  oal_irq_del_handler/12:
  Jump functions of caller  oal_irq_add_handler/11:
  Jump functions of caller  oal_irq_create/10:
    callsite  oal_irq_create/10 -> find_irq_idx_from_id/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  oal_irq_common_handler/9:
    indirect simple callsite, calling param -1, offset 0, for stmt _1 (_2);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  find_irq_idx_from_id/5:

 Propagating constants:

Not considering oal_irq_in_atomic for cloning; -fipa-cp-clone disabled.
Not considering oal_irq_get_id for cloning; -fipa-cp-clone disabled.
Not considering oal_irq_destroy for cloning; -fipa-cp-clone disabled.
Not considering oal_irq_del_handler for cloning; -fipa-cp-clone disabled.
Not considering oal_irq_add_handler for cloning; -fipa-cp-clone disabled.
Not considering oal_irq_create for cloning; -fipa-cp-clone disabled.
Not considering oal_irq_common_handler for cloning; -fipa-cp-clone disabled.

overall_size: 71, max_new_size: 11001
 - context independent values, size: 14, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: oal_irq_in_atomic/15:
  Node: oal_irq_get_id/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: oal_irq_destroy/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: oal_irq_del_handler/12:
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
  Node: oal_irq_add_handler/11:
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
  Node: oal_irq_create/10:
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
  Node: oal_irq_common_handler/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: find_irq_idx_from_id/5:
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

CSWTCH.1/16 (CSWTCH.1) @072b2048
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: find_irq_idx_from_id/5 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
oal_irq_in_atomic/15 (oal_irq_in_atomic) @070571c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_irq_get_id/14 (oal_irq_get_id) @0704dd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_irq_destroy/13 (oal_irq_destroy) @0704d7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:153437706 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_irq_del_handler/12 (oal_irq_del_handler) @0704dee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_irq_add_handler/11 (oal_irq_add_handler) @0704dc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:204054434 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_irq_create/10 (oal_irq_create) @0704d9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: irq_pool/8 (read)irq_pool/8 (write)irq_pool/8 (write)irq_pool/8 (write)irq_pool/8 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: find_irq_idx_from_id/5 (1073741824 (estimated locally),1.00 per call) 
oal_irq_common_handler/9 (oal_irq_common_handler) @0704d700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: irq_pool/8 (read)irq_pool/8 (read)
  Referring: 
  Availability: available
  Function flags: count:153437706 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(644212883 (estimated locally),4.20 per call) 
irq_pool/8 (irq_pool) @07049990
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: oal_irq_common_handler/9 (read)oal_irq_common_handler/9 (read)oal_irq_create/10 (read)oal_irq_create/10 (write)oal_irq_create/10 (write)oal_irq_create/10 (write)oal_irq_create/10 (addr)
  Availability: available
  Varpool flags: initialized
find_irq_idx_from_id/5 (find_irq_idx_from_id) @070eb540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: CSWTCH.1/16 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: oal_irq_create/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function oal_irq_common_handler (oal_irq_common_handler, funcdef_no=6, decl_uid=7167, cgraph_uid=7, symbol_order=9)

Modification phase of node oal_irq_common_handler/9
oal_irq_common_handler (oal_irq_idx_t idx)
{
  uint32_t ctr;
  bool_t (*<T4f7>) (void *) _1;
  void * _2;

  <bb 2> [local count: 153437706]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ctr => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 920304118]:
  # DEBUG BEGIN_STMT
  _1 = irq_pool[idx_7(D)].handler[ctr_3];
  if (_1 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 644212883]:
  # DEBUG BEGIN_STMT
  _2 = irq_pool[idx_7(D)].data[ctr_3];
  _1 (_2);

  <bb 5> [local count: 920304118]:
  # DEBUG BEGIN_STMT
  ctr_9 = ctr_3 + 1;
  # DEBUG ctr => ctr_9

  <bb 6> [local count: 1073741824]:
  # ctr_3 = PHI <0(2), ctr_9(5)>
  # DEBUG ctr => ctr_3
  # DEBUG BEGIN_STMT
  if (ctr_3 != 6)
    goto <bb 3>; [85.71%]
  else
    goto <bb 7>; [14.29%]

  <bb 7> [local count: 153437707]:
  return;

}



;; Function oal_irq_create (oal_irq_create, funcdef_no=7, decl_uid=7181, cgraph_uid=8, symbol_order=10)

Modification phase of node oal_irq_create/10
oal_irq_create (int32_t id, oal_irq_flags_t flags, const char_t * name)
{
  uint32_t idx;
  struct oal_irq_t * ret_val;
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret_val => 0B
  # DEBUG BEGIN_STMT
  idx_6 = find_irq_idx_from_id (id_5(D));
  # DEBUG idx => idx_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (idx_6 <= 5)
    goto <bb 3>; [71.00%]
  else
    goto <bb 5>; [29.00%]

  <bb 3> [local count: 762356696]:
  _1 = irq_pool[idx_6].created;
  if (_1 == 0)
    goto <bb 4>; [71.00%]
  else
    goto <bb 5>; [29.00%]

  <bb 4> [local count: 541273254]:
  # DEBUG BEGIN_STMT
  irq_pool[idx_6].created = 1;
  # DEBUG BEGIN_STMT
  irq_pool[idx_6].id = id_5(D);
  # DEBUG BEGIN_STMT
  irq_pool[idx_6].flags = flags_9(D);
  # DEBUG BEGIN_STMT
  ret_val_11 = &irq_pool[idx_6];
  # DEBUG ret_val => ret_val_11

  <bb 5> [local count: 1073741824]:
  # ret_val_2 = PHI <0B(2), 0B(3), ret_val_11(4)>
  # DEBUG ret_val => ret_val_2
  # DEBUG BEGIN_STMT
  return ret_val_2;

}



;; Function oal_irq_add_handler (oal_irq_add_handler, funcdef_no=8, decl_uid=7186, cgraph_uid=9, symbol_order=11)

Modification phase of node oal_irq_add_handler/11
oal_irq_add_handler (struct oal_irq_t * irq, bool_t (*oal_irq_handler_t) (void *) handler, void * data, oal_irq_isr_handle_t * handle)
{
  uint32_t ctr;
  errno_t ret_val;
  bool_t (*<T4f7>) (void *) _1;

  <bb 2> [local count: 204054434]:
  # DEBUG BEGIN_STMT
  # DEBUG ret_val => 11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ctr => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 920304117]:
  # DEBUG BEGIN_STMT
  _1 = irq_7(D)->handler[ctr_3];
  if (_1 == 0B)
    goto <bb 4>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 4> [local count: 50616726]:
  # ctr_15 = PHI <ctr_3(3)>
  # DEBUG BEGIN_STMT
  if (handle_9(D) != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 5> [local count: 35431708]:
  # DEBUG BEGIN_STMT
  *handle_9(D) = ctr_15;

  <bb 6> [local count: 50616726]:
  # DEBUG BEGIN_STMT
  irq_7(D)->handler[ctr_15] = handler_11(D);
  # DEBUG BEGIN_STMT
  irq_7(D)->data[ctr_15] = data_13(D);
  # DEBUG BEGIN_STMT
  # DEBUG ret_val => 0
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 869687391]:
  # DEBUG BEGIN_STMT
  ctr_8 = ctr_3 + 1;
  # DEBUG ctr => ctr_8

  <bb 8> [local count: 1073741824]:
  # ctr_3 = PHI <0(2), ctr_8(7)>
  # DEBUG ctr => ctr_3
  # DEBUG BEGIN_STMT
  if (ctr_3 != 6)
    goto <bb 3>; [85.71%]
  else
    goto <bb 9>; [14.29%]

  <bb 9> [local count: 204054433]:
  # ret_val_2 = PHI <0(6), 11(8)>
  # DEBUG ret_val => ret_val_2
  # DEBUG BEGIN_STMT
  return ret_val_2;

}



;; Function oal_irq_del_handler (oal_irq_del_handler, funcdef_no=9, decl_uid=7189, cgraph_uid=10, symbol_order=12)

Modification phase of node oal_irq_del_handler/12
oal_irq_del_handler (struct oal_irq_t * irq, oal_irq_isr_handle_t handle)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret_val => 0
  # DEBUG BEGIN_STMT
  irq_2(D)->handler[handle_3(D)] = 0B;
  # DEBUG BEGIN_STMT
  irq_2(D)->data[handle_3(D)] = 0B;
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function oal_irq_destroy (oal_irq_destroy, funcdef_no=10, decl_uid=7191, cgraph_uid=11, symbol_order=13)

Modification phase of node oal_irq_destroy/13
oal_irq_destroy (struct oal_irq_t * irq)
{
  uint32_t ctr;

  <bb 2> [local count: 153437706]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  irq_4(D)->created = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ctr => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 920304118]:
  # DEBUG BEGIN_STMT
  irq_4(D)->handler[ctr_1] = 0B;
  # DEBUG BEGIN_STMT
  irq_4(D)->data[ctr_1] = 0B;
  # DEBUG BEGIN_STMT
  ctr_9 = ctr_1 + 1;
  # DEBUG ctr => ctr_9

  <bb 4> [local count: 1073741824]:
  # ctr_1 = PHI <0(2), ctr_9(3)>
  # DEBUG ctr => ctr_1
  # DEBUG BEGIN_STMT
  if (ctr_1 != 6)
    goto <bb 3>; [85.71%]
  else
    goto <bb 5>; [14.29%]

  <bb 5> [local count: 153437707]:
  # DEBUG BEGIN_STMT
  irq_4(D)->flags = 0;
  return;

}



;; Function oal_irq_get_id (oal_irq_get_id, funcdef_no=11, decl_uid=7197, cgraph_uid=12, symbol_order=14)

Modification phase of node oal_irq_get_id/14
oal_irq_get_id (const struct oal_irq_t * irq)
{
  int32_t retval;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  retval_3 = irq_2(D)->id;
  # DEBUG retval => retval_3
  # DEBUG BEGIN_STMT
  return retval_3;

}



;; Function oal_irq_in_atomic (oal_irq_in_atomic, funcdef_no=12, decl_uid=7199, cgraph_uid=13, symbol_order=15)

Modification phase of node oal_irq_in_atomic/15
oal_irq_in_atomic ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}


