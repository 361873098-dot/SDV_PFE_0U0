
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  sio_tryread/4:
  Jump functions of caller  sio_send/3:
  Jump functions of caller  sio_open/2:
  Jump functions of caller  sys_now/1:

 Propagating constants:

Not considering sio_tryread for cloning; -fipa-cp-clone disabled.
Not considering sio_send for cloning; -fipa-cp-clone disabled.
Not considering sio_open for cloning; -fipa-cp-clone disabled.
Not considering sys_now for cloning; -fipa-cp-clone disabled.

overall_size: 13, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 3.000000
 - context independent values, size: 3, time_benefit: 2.000000
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: sio_tryread/4:
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
  Node: sio_send/3:
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
  Node: sio_open/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: sys_now/1:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

g_sys_milliseconds/5 (g_sys_milliseconds) @06dece58
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: sys_now/1 (read)
  Availability: not_available
  Varpool flags:
sio_tryread/4 (sio_tryread) @06df0b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sio_send/3 (sio_send) @06df08c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sio_open/2 (sio_open) @06df0620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sys_now/1 (sys_now) @06df0380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: g_sys_milliseconds/5 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function sys_now (sys_now, funcdef_no=1, decl_uid=6387, cgraph_uid=2, symbol_order=1)

Modification phase of node sys_now/1
sys_now ()
{
  u32_t _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = g_sys_milliseconds;
  return _2;

}



;; Function sio_open (sio_open, funcdef_no=2, decl_uid=6390, cgraph_uid=3, symbol_order=2)

Modification phase of node sio_open/2
sio_open (u8_t devnum)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0B;

}



;; Function sio_send (sio_send, funcdef_no=3, decl_uid=6393, cgraph_uid=4, symbol_order=3)

Modification phase of node sio_send/3
sio_send (u8_t c, void * fd)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function sio_tryread (sio_tryread, funcdef_no=4, decl_uid=6403, cgraph_uid=5, symbol_order=4)

Modification phase of node sio_tryread/4
sio_tryread (void * fd, u8_t * data, u32_t len)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}


