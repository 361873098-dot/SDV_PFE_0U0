
IPA constant propagation start:
Determining dynamic type for call: slipif_rxbyte_input (netif_8(D), c.1_2);
  Starting walk at: slipif_rxbyte_input (netif_8(D), c.1_2);
  instance pointer: netif_8(D)  Outer instance pointer: netif_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = sio_tryread (_3, &c, 1);
  Function call may change dynamic type:slipif_rxbyte_input (netif_8(D), c.1_2);
  Function call may change dynamic type:_4 = sio_tryread (_3, &c, 1);
Determining dynamic type for call: p_8 = slipif_rxbyte (netif_5(D), c_6(D));
  Starting walk at: p_8 = slipif_rxbyte (netif_5(D), c_6(D));
  instance pointer: netif_5(D)  Outer instance pointer: netif_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = _1 (p_8, netif_5(D));
  Starting walk at: _2 = _1 (p_8, netif_5(D));
  instance pointer: p_8  Outer instance pointer: p_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_8 = slipif_rxbyte (netif_5(D), c_6(D));
Determining dynamic type for call: _2 = _1 (p_8, netif_5(D));
  Starting walk at: _2 = _1 (p_8, netif_5(D));
  instance pointer: netif_5(D)  Outer instance pointer: netif_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_8 = slipif_rxbyte (netif_5(D), c_6(D));
Determining dynamic type for call: _5 = slipif_output (netif_2(D), p_3(D));
  Starting walk at: _5 = slipif_output (netif_2(D), p_3(D));
  instance pointer: netif_2(D)  Outer instance pointer: netif_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = slipif_output (netif_2(D), p_3(D));
  Starting walk at: _5 = slipif_output (netif_2(D), p_3(D));
  instance pointer: p_3(D)  Outer instance pointer: p_3(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pbuf_cat/16:
  Jump functions of caller  pbuf_alloc/15:
  Jump functions of caller  pbuf_realloc/13:
  Jump functions of caller  pbuf_free/12:
  Jump functions of caller  sio_tryread/11:
  Jump functions of caller  sio_send/10:
  Jump functions of caller  mem_free/9:
  Jump functions of caller  sio_open/8:
  Jump functions of caller  mem_malloc/7:
  Jump functions of caller  slipif_poll/6:
    callsite  slipif_poll/6 -> slipif_rxbyte_input/4 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  slipif_init/5:
  Jump functions of caller  slipif_rxbyte_input/4:
    callsite  slipif_rxbyte_input/4 -> slipif_rxbyte/3 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 128, by reference, for stmt _2 = _1 (p_8, netif_5(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  slipif_rxbyte/3:
  Jump functions of caller  slipif_output_v4/2:
    callsite  slipif_output_v4/2 -> slipif_output/1 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  slipif_output/1:

 Propagating constants:

Not considering slipif_poll for cloning; -fipa-cp-clone disabled.
Not considering slipif_init for cloning; -fipa-cp-clone disabled.
Not considering slipif_output_v4 for cloning; -fipa-cp-clone disabled.

overall_size: 255, max_new_size: 11001
 - context independent values, size: 7, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: slipif_poll/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: slipif_init/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: slipif_rxbyte_input/4:
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
  Node: slipif_rxbyte/3:
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
  Node: slipif_output_v4/2:
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
  Node: slipif_output/1:
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

pbuf_cat/16 (pbuf_cat) @070e9000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_rxbyte/3 (11660 (estimated locally),0.03 per call) 
  Calls: 
pbuf_alloc/15 (pbuf_alloc) @06ffcee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_rxbyte/3 (23772 (estimated locally),0.07 per call) 
  Calls: 
lwip_stats/14 (lwip_stats) @070e6120
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: slipif_rxbyte/3 (read)slipif_rxbyte/3 (write)slipif_rxbyte/3 (read)slipif_rxbyte/3 (write)
  Availability: not_available
  Varpool flags:
pbuf_realloc/13 (pbuf_realloc) @06ffce00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_rxbyte/3 (7466 (estimated locally),0.02 per call) 
  Calls: 
pbuf_free/12 (pbuf_free) @06ffca80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_rxbyte_input/4 (248034361 (estimated locally),0.23 per call) 
  Calls: 
sio_tryread/11 (sio_tryread) @06ffc8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_poll/6 (1594341 (estimated locally),4.45 per call) 
  Calls: 
sio_send/10 (sio_send) @06ffc700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_output/1 (93165 (estimated locally),0.26 per call) slipif_output/1 (2031100 (estimated locally),5.67 per call) slipif_output/1 (2031100 (estimated locally),5.67 per call) slipif_output/1 (2031100 (estimated locally),5.67 per call) slipif_output/1 (2031100 (estimated locally),5.67 per call) slipif_output/1 (2031100 (estimated locally),5.67 per call) slipif_output/1 (93774 (estimated locally),0.26 per call) 
  Calls: 
mem_free/9 (mem_free) @06ffc460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_init/5 (269 (estimated locally),0.00 per call) 
  Calls: 
sio_open/8 (sio_open) @06ffc380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_init/5 (122266 (estimated locally),0.53 per call) 
  Calls: 
mem_malloc/7 (mem_malloc) @06ffc2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: slipif_init/5 (123389 (estimated locally),0.53 per call) 
  Calls: 
slipif_poll/6 (slipif_poll) @06fe7a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: sio_tryread/11 (1594341 (estimated locally),4.45 per call) slipif_rxbyte_input/4 (1418964 (estimated locally),3.96 per call) 
slipif_init/5 (slipif_init) @06fe7d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: slipif_output_v4/2 (addr)
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: mem_free/9 (269 (estimated locally),0.00 per call) sio_open/8 (122266 (estimated locally),0.53 per call) mem_malloc/7 (123389 (estimated locally),0.53 per call) 
slipif_rxbyte_input/4 (slipif_rxbyte_input) @06fe79a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: slipif_poll/6 (1418964 (estimated locally),3.96 per call) 
  Calls: pbuf_free/12 (248034361 (estimated locally),0.23 per call) slipif_rxbyte/3 (1073741824 (estimated locally),1.00 per call) 
   Indirect call(751619278 (estimated locally),0.70 per call)  of param:0 loaded from aggregate passed by reference at offset 128 (vptr maybe changed)
slipif_rxbyte/3 (slipif_rxbyte) @06fe7700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwip_stats/14 (read)lwip_stats/14 (write)lwip_stats/14 (read)lwip_stats/14 (write)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: slipif_rxbyte_input/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_cat/16 (11660 (estimated locally),0.03 per call) pbuf_alloc/15 (23772 (estimated locally),0.07 per call) pbuf_realloc/13 (7466 (estimated locally),0.02 per call) 
slipif_output_v4/2 (slipif_output_v4) @06fe7460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: slipif_init/5 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: slipif_output/1 (1073741824 (estimated locally),1.00 per call) 
slipif_output/1 (slipif_output) @06fe71c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: slipif_output_v4/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: sio_send/10 (93165 (estimated locally),0.26 per call) sio_send/10 (2031100 (estimated locally),5.67 per call) sio_send/10 (2031100 (estimated locally),5.67 per call) sio_send/10 (2031100 (estimated locally),5.67 per call) sio_send/10 (2031100 (estimated locally),5.67 per call) sio_send/10 (2031100 (estimated locally),5.67 per call) sio_send/10 (93774 (estimated locally),0.26 per call) 

;; Function slipif_output_v4 (slipif_output_v4, funcdef_no=2, decl_uid=6993, cgraph_uid=3, symbol_order=2)

Modification phase of node slipif_output_v4/2
slipif_output_v4 (struct netif * netif, struct pbuf * p, const struct ip4_addr_t * ipaddr)
{
  err_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = slipif_output (netif_2(D), p_3(D));
  return _5;

}



;; Function slipif_init (slipif_init, funcdef_no=5, decl_uid=6891, cgraph_uid=6, symbol_order=5)

Modification phase of node slipif_init/5
slipif_init (struct netif * netif)
{
  u8_t sio_num;
  struct slipif_priv * priv;
  err_t (*<T651>) (struct pbuf *, struct netif *) _1;
  void * _2;
  int _3;
  void * _4;
  err_t _5;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_9(D)->input;
  if (_1 == 0B)
    goto <bb 9>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 9> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = netif_9(D)->state;
  _3 = (int) _2;
  sio_num_10 = (u8_t) _3;
  # DEBUG sio_num => sio_num_10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  priv_12 = mem_malloc (20);
  # DEBUG priv => priv_12
  # DEBUG BEGIN_STMT
  if (priv_12 == 0B)
    goto <bb 8>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 5> [local count: 122266]:
  # DEBUG BEGIN_STMT
  netif_9(D)->name[0] = 115;
  # DEBUG BEGIN_STMT
  netif_9(D)->name[1] = 108;
  # DEBUG BEGIN_STMT
  netif_9(D)->output = slipif_output_v4;
  # DEBUG BEGIN_STMT
  netif_9(D)->mtu = 1500;
  # DEBUG BEGIN_STMT
  _4 = sio_open (sio_num_10);
  priv_12->sd = _4;
  # DEBUG BEGIN_STMT
  if (_4 == 0B)
    goto <bb 6>; [0.22%]
  else
    goto <bb 7>; [99.78%]

  <bb 6> [local count: 269]:
  # DEBUG BEGIN_STMT
  mem_free (priv_12);
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 121997]:
  # DEBUG BEGIN_STMT
  priv_12->p = 0B;
  # DEBUG BEGIN_STMT
  priv_12->q = 0B;
  # DEBUG BEGIN_STMT
  priv_12->state = 0;
  # DEBUG BEGIN_STMT
  priv_12->i = 0;
  # DEBUG BEGIN_STMT
  priv_12->recved = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->state = priv_12;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_9(D)->link_type = 28;
  # DEBUG BEGIN_STMT
  netif_9(D)->link_speed = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->ts = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifinoctets = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifinucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifinnucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifindiscards = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifinerrors = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifinunknownprotos = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifoutoctets = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifoutucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifoutnucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifoutdiscards = 0;
  # DEBUG BEGIN_STMT
  netif_9(D)->mib2_counters.ifouterrors = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 123389]:
  # _5 = PHI <-1(4), -12(6), 0(7)>
  return _5;

}



;; Function slipif_poll (slipif_poll, funcdef_no=6, decl_uid=6893, cgraph_uid=7, symbol_order=6)

Modification phase of node slipif_poll/6
slipif_poll (struct netif * netif)
{
  u8_t c;
  void * _1;
  unsigned char c.1_2;
  void * _3;
  long unsigned int _4;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_8(D) == 0B)
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

  <bb 12> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_8(D)->state;
  if (_1 == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 11>; [70.00%]

  <bb 11> [local count: 175378]:
  goto <bb 7>; [100.00%]

  <bb 10> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 1418964]:
  # DEBUG BEGIN_STMT
  c.1_2 = c;
  slipif_rxbyte_input (netif_8(D), c.1_2);

  <bb 7> [local count: 1594341]:
  # DEBUG priv => NULL
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct slipif_priv *)_1].sd;
  _4 = sio_tryread (_3, &c, 1);
  if (_4 != 0)
    goto <bb 6>; [89.00%]
  else
    goto <bb 8>; [11.00%]

  <bb 8> [local count: 175378]:
  c ={v} {CLOBBER};
  return;

}


