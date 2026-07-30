
IPA constant propagation start:
Determining dynamic type for call: fci_hm_cb (0B);
  Starting walk at: fci_hm_cb (0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_hm_register_event_cb/23:
  Jump functions of caller  fci_core_client_send_broadcast/22:
  Jump functions of caller  autolibc_memcpy/21:
  Jump functions of caller  pfe_hm_get/20:
  Jump functions of caller  fci_hm_cb_deregister/18:
  Jump functions of caller  fci_hm_cb_register/17:
  Jump functions of caller  fci_hm_send_events/16:
    callsite  fci_hm_send_events/16 -> fci_hm_cb/15 : 
       param 0: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  fci_hm_cb/15:

 Propagating constants:

Not considering fci_hm_cb_deregister for cloning; -fipa-cp-clone disabled.
Not considering fci_hm_cb_register for cloning; -fipa-cp-clone disabled.
Not considering fci_hm_send_events for cloning; -fipa-cp-clone disabled.
Not considering fci_hm_cb for cloning; -fipa-cp-clone disabled.

overall_size: 57, max_new_size: 11001
 - context independent values, size: 40, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: fci_hm_cb_deregister/18:
  Node: fci_hm_cb_register/17:
  Node: fci_hm_send_events/16:
  Node: fci_hm_cb/15:
    param [0]: BOTTOM
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

pfe_hm_register_event_cb/23 (pfe_hm_register_event_cb) @07677460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_hm_cb_register/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
fci_core_client_send_broadcast/22 (fci_core_client_send_broadcast) @076772a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_hm_cb/15 (341366148 (estimated locally),3.00 per call) 
  Calls: 
autolibc_memcpy/21 (autolibc_memcpy) @076771c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_hm_cb/15 (341366148 (estimated locally),3.00 per call) 
  Calls: 
pfe_hm_get/20 (pfe_hm_get) @076770e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fci_hm_cb/15 (1034442874 (estimated locally),9.10 per call) 
  Calls: 
context/19 (context) @075bd3f0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: fci_hm_cb/15 (read)
  Availability: not_available
  Varpool flags:
fci_hm_cb_deregister/18 (fci_hm_cb_deregister) @075b4e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
fci_hm_cb_register/17 (fci_hm_cb_register) @075b4b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: fci_hm_cb/15 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hm_register_event_cb/23 (1073741824 (estimated locally),1.00 per call) 
fci_hm_send_events/16 (fci_hm_send_events) @075b48c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: fci_hm_cb/15 (1073741824 (estimated locally),1.00 per call) 
fci_hm_cb/15 (fci_hm_cb) @075b4620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: context/19 (read)
  Referring: fci_hm_cb_register/17 (addr)
  Availability: available
  Function flags: count:113634470 (estimated locally) body optimize_size
  Called by: fci_hm_send_events/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: fci_core_client_send_broadcast/22 (341366148 (estimated locally),3.00 per call) autolibc_memcpy/21 (341366148 (estimated locally),3.00 per call) pfe_hm_get/20 (1034442874 (estimated locally),9.10 per call) 

;; Function fci_hm_cb (fci_hm_cb, funcdef_no=12, decl_uid=12323, cgraph_uid=13, symbol_order=15)

Modification phase of node fci_hm_cb/15
fci_hm_cb (struct pfe_hm_item_t * unused)
{
  uint8_t u8LoopCnt;
  struct fpp_health_monitor_cmd_t hm_event;
  struct fci_msg_t msg;
  struct pfe_hm_item_t item;
  errno_t ret;
  unsigned char _1;
  <unnamed type> _2;
  short unsigned int _3;
  short unsigned int _4;
  <unnamed type> _5;
  unsigned char _6;
  <unnamed type> _7;
  unsigned char _8;

  <bb 2> [local count: 113634470]:
  # DEBUG BEGIN_STMT
  # DEBUG fci_context => &context
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  hm_event = {};
  # DEBUG BEGIN_STMT
  # DEBUG u8LoopCnt => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  msg.type = 4099;
  # DEBUG BEGIN_STMT
  msg.msg_cmd.code = 63072;
  # DEBUG BEGIN_STMT
  msg.msg_cmd.length = 70;
  # DEBUG BEGIN_STMT
  msg.msg_cmd.sender = 0;
  # DEBUG BEGIN_STMT
  msg.client = 0B;

  <bb 3> [local count: 1073741824]:
  # u8LoopCnt_10 = PHI <0(2), u8LoopCnt_11(10)>
  # DEBUG u8LoopCnt => u8LoopCnt_10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = context.is_some_client;
  if (_1 == 0)
    goto <bb 9>; [3.66%]
  else
    goto <bb 5>; [96.34%]

  <bb 5> [local count: 1034442874]:
  # DEBUG BEGIN_STMT
  ret_22 = pfe_hm_get (&item);
  # DEBUG ret => ret_22
  # DEBUG BEGIN_STMT
  if (ret_22 != 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 6>; [33.00%]

  <bb 6> [local count: 341366148]:
  # DEBUG BEGIN_STMT
  hm_event.action = 0;
  # DEBUG BEGIN_STMT
  _2 = item.id;
  _3 = (short unsigned int) _2;
  _4 = _3 r>> 8;
  hm_event.id = _4;
  # DEBUG BEGIN_STMT
  _5 = item.type;
  _6 = (unsigned char) _5;
  hm_event.type = _6;
  # DEBUG BEGIN_STMT
  _7 = item.src;
  _8 = (unsigned char) _7;
  hm_event.src = _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memcpy (&msg.msg_cmd.payload, &hm_event, 70);
  # DEBUG BEGIN_STMT
  ret_29 = fci_core_client_send_broadcast (&msg, 0B);
  # DEBUG ret => ret_29
  # DEBUG BEGIN_STMT
  u8LoopCnt_30 = u8LoopCnt_10 + 1;
  # DEBUG u8LoopCnt => u8LoopCnt_30

  <bb 7> [local count: 1034442874]:
  # ret_9 = PHI <ret_29(6), ret_22(5)>
  # u8LoopCnt_11 = PHI <u8LoopCnt_30(6), u8LoopCnt_10(5)>
  # DEBUG u8LoopCnt => u8LoopCnt_11
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  if (ret_9 == 0)
    goto <bb 8>; [96.34%]
  else
    goto <bb 9>; [3.66%]

  <bb 8> [local count: 996582265]:
  if (u8LoopCnt_11 <= 7)
    goto <bb 10>; [96.34%]
  else
    goto <bb 9>; [3.66%]

  <bb 10> [local count: 960107354]:
  goto <bb 3>; [100.00%]

  <bb 9> [local count: 113634471]:
  # DEBUG u8LoopCnt => NULL
  # DEBUG ret => NULL
  item ={v} {CLOBBER};
  msg ={v} {CLOBBER};
  hm_event ={v} {CLOBBER};
  return;

}



;; Function fci_hm_send_events (fci_hm_send_events, funcdef_no=13, decl_uid=12285, cgraph_uid=14, symbol_order=16)

Modification phase of node fci_hm_send_events/16
fci_hm_send_events ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  fci_hm_cb (0B);
  return;

}



;; Function fci_hm_cb_register (fci_hm_cb_register, funcdef_no=14, decl_uid=12287, cgraph_uid=15, symbol_order=17)

Modification phase of node fci_hm_cb_register/17
fci_hm_cb_register ()
{
  errno_t ret;
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  _1 = pfe_hm_register_event_cb (fci_hm_cb);
  if (_1 == 1)
    goto <bb 3>; [48.89%]
  else
    goto <bb 4>; [51.11%]

  <bb 3> [local count: 524952378]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_2 = PHI <22(2), 0(3)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function fci_hm_cb_deregister (fci_hm_cb_deregister, funcdef_no=15, decl_uid=12289, cgraph_uid=16, symbol_order=18)

Modification phase of node fci_hm_cb_deregister/18
fci_hm_cb_deregister ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}


