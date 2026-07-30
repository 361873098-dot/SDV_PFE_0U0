
IPA constant propagation start:
Determining dynamic type for call: err_10 = ipc_hw_set_core (instance_7(D), cfg_8(D));
  Starting walk at: err_10 = ipc_hw_set_core (instance_7(D), cfg_8(D));
  instance pointer: cfg_8(D)  Outer instance pointer: cfg_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_12 = ipc_hw_set_irq_idx (instance_7(D), cfg_8(D));
  Starting walk at: err_12 = ipc_hw_set_irq_idx (instance_7(D), cfg_8(D));
  instance pointer: cfg_8(D)  Outer instance pointer: cfg_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_10 = ipc_hw_set_core (instance_7(D), cfg_8(D));
Determining dynamic type for call: err_13 = ipc_hw_set_remote_core (instance_10(D), cfg_11(D));
  Starting walk at: err_13 = ipc_hw_set_remote_core (instance_10(D), cfg_11(D));
  instance pointer: cfg_11(D)  Outer instance pointer: cfg_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_15 = ipc_hw_set_local_core (instance_10(D), cfg_11(D));
  Starting walk at: err_15 = ipc_hw_set_local_core (instance_10(D), cfg_11(D));
  instance pointer: cfg_11(D)  Outer instance pointer: cfg_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = ipc_hw_set_remote_core (instance_10(D), cfg_11(D));

IPA structures before propagation:

Jump functions:
  Jump functions of caller  ipc_hw_set_rx_irq_idx.isra.0/19:
  Jump functions of caller  ipc_hw_set_tx_irq_idx.isra.0/18:
  Jump functions of caller  ipc_hw_flush_cache_remote/16:
  Jump functions of caller  ipc_hw_flush_cache_local/15:
  Jump functions of caller  ipc_hw_irq_clear/14:
  Jump functions of caller  ipc_hw_irq_notify/13:
  Jump functions of caller  ipc_hw_irq_disable/12:
  Jump functions of caller  ipc_hw_irq_enable/11:
  Jump functions of caller  ipc_hw_free/10:
    callsite  ipc_hw_free/10 -> ipc_hw_irq_clear/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_hw_init/9:
    callsite  ipc_hw_init/9 -> ipc_hw_irq_clear/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_hw_init/9 -> ipc_hw_irq_disable/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_hw_init/9 -> ipc_hw_set_irq_idx/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_hw_init/9 -> ipc_hw_set_core/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_hw_set_irq_idx/8:
    callsite  ipc_hw_set_irq_idx/8 -> ipc_hw_set_rx_irq_idx.isra.0/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
    callsite  ipc_hw_set_irq_idx/8 -> ipc_hw_set_tx_irq_idx.isra.0/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  ipc_hw_set_core/5:
    callsite  ipc_hw_set_core/5 -> ipc_hw_set_local_core/4 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_hw_set_core/5 -> ipc_hw_set_remote_core/3 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_hw_set_local_core/4:
    callsite  ipc_hw_set_local_core/4 -> ipc_hw_get_core_index_m7/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [1, 8]
    callsite  ipc_hw_set_local_core/4 -> ipc_hw_get_core_index_a53/2 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [1, -128]
  Jump functions of caller  ipc_hw_set_remote_core/3:
    callsite  ipc_hw_set_remote_core/3 -> ipc_hw_get_core_index_m7/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [1, 8]
    callsite  ipc_hw_set_remote_core/3 -> ipc_hw_get_core_index_a53/2 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [1, -128]
  Jump functions of caller  ipc_hw_get_core_index_a53/2:
  Jump functions of caller  ipc_hw_get_core_index_m7/1:

 Propagating constants:

Function ipc_hw_flush_cache_remote/16 is not versionable, reason: not a tree_versionable_function.
Not considering ipc_hw_flush_cache_local for cloning; -fipa-cp-clone disabled.
Not considering ipc_hw_irq_clear for cloning; -fipa-cp-clone disabled.
Not considering ipc_hw_irq_notify for cloning; -fipa-cp-clone disabled.
Not considering ipc_hw_irq_disable for cloning; -fipa-cp-clone disabled.
Not considering ipc_hw_irq_enable for cloning; -fipa-cp-clone disabled.
Not considering ipc_hw_free for cloning; -fipa-cp-clone disabled.
Not considering ipc_hw_init for cloning; -fipa-cp-clone disabled.

overall_size: 301, max_new_size: 11001
 - context independent values, size: 2, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: ipc_hw_set_rx_irq_idx.isra.0/19:
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
  Node: ipc_hw_set_tx_irq_idx.isra.0/18:
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
  Node: ipc_hw_flush_cache_remote/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_hw_flush_cache_local/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_hw_irq_clear/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_hw_irq_notify/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_hw_irq_disable/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_hw_irq_enable/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_hw_free/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_hw_init/9:
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
  Node: ipc_hw_set_irq_idx/8:
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
  Node: ipc_hw_set_core/5:
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
  Node: ipc_hw_set_local_core/4:
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
  Node: ipc_hw_set_remote_core/3:
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
  Node: ipc_hw_get_core_index_a53/2:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         uint8 [1, 128]
        AGGS VARIABLE
  Node: ipc_hw_get_core_index_m7/1:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xf
         uint8 [1, 8]
        AGGS VARIABLE

IPA decision stage:

Propagated bits info for function ipc_hw_get_core_index_m7/1:
 param 0: value = 0x0, mask = 0xf

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

ipc_hw_set_rx_irq_idx.isra.0/19 (ipc_hw_set_rx_irq_idx.isra.0) @075ff540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_hw_set_irq_idx/8 (347433522 (estimated locally),0.32 per call) 
  Calls: 
ipc_hw_set_tx_irq_idx.isra.0/18 (ipc_hw_set_tx_irq_idx.isra.0) @0750fe00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_hw_set_irq_idx/8 (1052828856 (estimated locally),0.98 per call) 
  Calls: 
CSWTCH.5/17 (CSWTCH.5) @074fa750
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: ipc_hw_get_core_index_m7/1 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
ipc_hw_flush_cache_remote/16 (ipc_hw_flush_cache_remote) @074ae700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: ipc_hw_flush_cache_local/15 (1073741824 (estimated locally),1.00 per call) 
ipc_hw_flush_cache_local/15 (ipc_hw_flush_cache_local) @074ae460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: ipc_hw_flush_cache_remote/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ipc_hw_irq_clear/14 (ipc_hw_irq_clear) @074ae1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_hw_priv/0 (read)ipc_hw_priv/0 (read)ipc_hw_priv/0 (read)ipc_hw_priv/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: ipc_hw_free/10 (1073741824 (estimated locally),1.00 per call) ipc_hw_init/9 (354334802 (estimated locally),0.33 per call) 
  Calls: 
ipc_hw_irq_notify/13 (ipc_hw_irq_notify) @074a1ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_hw_priv/0 (read)ipc_hw_priv/0 (read)ipc_hw_priv/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ipc_hw_irq_disable/12 (ipc_hw_irq_disable) @074a19a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_hw_priv/0 (read)ipc_hw_priv/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: ipc_hw_init/9 (354334802 (estimated locally),0.33 per call) 
  Calls: 
ipc_hw_irq_enable/11 (ipc_hw_irq_enable) @074a1e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_hw_priv/0 (read)ipc_hw_priv/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ipc_hw_free/10 (ipc_hw_free) @074a1b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_hw_irq_clear/14 (1073741824 (estimated locally),1.00 per call) 
ipc_hw_init/9 (ipc_hw_init) @074a18c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_hw_priv/0 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_hw_irq_clear/14 (354334802 (estimated locally),0.33 per call) ipc_hw_irq_disable/12 (354334802 (estimated locally),0.33 per call) ipc_hw_set_irq_idx/8 (354334802 (estimated locally),0.33 per call) ipc_hw_set_core/5 (1073741824 (estimated locally),1.00 per call) 
ipc_hw_set_irq_idx/8 (ipc_hw_set_irq_idx) @074a1620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_hw_init/9 (354334802 (estimated locally),0.33 per call) 
  Calls: ipc_hw_set_rx_irq_idx.isra.0/19 (347433522 (estimated locally),0.32 per call) ipc_hw_set_tx_irq_idx.isra.0/18 (1052828856 (estimated locally),0.98 per call) 
ipc_hw_set_core/5 (ipc_hw_set_core) @0748de00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_hw_priv/0 (read)ipc_hw_priv/0 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: ipc_hw_init/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: ipc_hw_set_local_core/4 (354334802 (estimated locally),0.33 per call) ipc_hw_set_remote_core/3 (1073741823 (estimated locally),1.00 per call) 
ipc_hw_set_local_core/4 (ipc_hw_set_local_core) @0748db60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_hw_set_core/5 (354334802 (estimated locally),0.33 per call) 
  Calls: ipc_hw_get_core_index_m7/1 (668035907 (estimated locally),0.62 per call) ipc_hw_get_core_index_a53/2 (357770776 (estimated locally),0.33 per call) 
ipc_hw_set_remote_core/3 (ipc_hw_set_remote_core) @0748d8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_hw_priv/0 (write)ipc_hw_priv/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_hw_set_core/5 (1073741823 (estimated locally),1.00 per call) 
  Calls: ipc_hw_get_core_index_m7/1 (668035907 (estimated locally),0.62 per call) ipc_hw_get_core_index_a53/2 (357770776 (estimated locally),0.33 per call) 
ipc_hw_get_core_index_a53/2 (ipc_hw_get_core_index_a53) @0748d620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_hw_set_local_core/4 (357770776 (estimated locally),0.33 per call) ipc_hw_set_remote_core/3 (357770776 (estimated locally),0.33 per call) 
  Calls: 
ipc_hw_get_core_index_m7/1 (ipc_hw_get_core_index_m7) @0748d380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: CSWTCH.5/17 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_hw_set_local_core/4 (668035907 (estimated locally),0.62 per call) ipc_hw_set_remote_core/3 (668035907 (estimated locally),0.62 per call) 
  Calls: 
ipc_hw_priv/0 (ipc_hw_priv) @074896c0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ipc_hw_irq_notify/13 (read)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_remote_core/3 (write)ipc_hw_set_remote_core/3 (write)ipc_hw_irq_disable/12 (read)ipc_hw_irq_disable/12 (read)ipc_hw_irq_notify/13 (read)ipc_hw_irq_clear/14 (read)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_irq_enable/11 (read)ipc_hw_irq_enable/11 (read)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_irq_notify/13 (read)ipc_hw_set_local_core/4 (write)ipc_hw_set_local_core/4 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_tx_irq_idx.isra.0/18 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_core/5 (read)ipc_hw_set_core/5 (read)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_irq_clear/14 (read)ipc_hw_irq_clear/14 (read)ipc_hw_irq_clear/14 (read)ipc_hw_init/9 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)ipc_hw_set_rx_irq_idx.isra.0/19 (write)
  Availability: available
  Varpool flags:

;; Function ipc_hw_get_core_index_a53 (ipc_hw_get_core_index_a53, funcdef_no=1, decl_uid=6341, cgraph_uid=2, symbol_order=2)

Modification phase of node ipc_hw_get_core_index_a53/2
Setting value range of param 0 [1, -128]
ipc_hw_get_core_index_a53 (uint8 index)
{
  sint8 core_index;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  switch (index_2(D)) <default: <L8> [11.11%], case 1: <L11> [11.11%], case 2: <L1> [11.11%], case 4: <L2> [11.11%], case 8: <L3> [11.11%], case 16: <L4> [11.11%], case 32: <L5> [11.11%], case 64: <L6> [11.11%], case 128: <L7> [11.11%]>

  <bb 3> [local count: 119292717]:
<L1>:
  # DEBUG BEGIN_STMT
  # DEBUG core_index => 1
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 119292717]:
<L2>:
  # DEBUG BEGIN_STMT
  # DEBUG core_index => 2
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 5> [local count: 119292717]:
<L3>:
  # DEBUG BEGIN_STMT
  # DEBUG core_index => 3
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 119292717]:
<L4>:
  # DEBUG BEGIN_STMT
  # DEBUG core_index => 8
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 119292717]:
<L5>:
  # DEBUG BEGIN_STMT
  # DEBUG core_index => 9
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 119292717]:
<L6>:
  # DEBUG BEGIN_STMT
  # DEBUG core_index => 10
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 119292717]:
<L7>:
  # DEBUG BEGIN_STMT
  # DEBUG core_index => 11
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 119292717]:
<L8>:
  # DEBUG BEGIN_STMT
  # DEBUG core_index => -3
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073634452]:
  # core_index_1 = PHI <0(2), 1(3), 2(4), 3(5), 8(6), 9(7), 10(8), 11(9), -3(10)>
<L11>:
  # DEBUG core_index => core_index_1
  # DEBUG BEGIN_STMT
  return core_index_1;

}



;; Function ipc_hw_irq_enable (ipc_hw_irq_enable, funcdef_no=10, decl_uid=5774, cgraph_uid=11, symbol_order=11)

Modification phase of node ipc_hw_irq_enable/11
ipc_hw_irq_enable (const uint8 instance)
{
  int _1;
  short int _2;
  int _3;
  short unsigned int _4;
  signed short _5;
  unsigned char _6;
  unsigned int _7;
  unsigned int _8;
  int _9;
  signed short _10;
  signed short _11;
  short unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) instance_14(D);
  _2 = ipc_hw_priv[_1].mscm_rx_irq;
  if (_2 != -1)
    goto <bb 3>; [66.00%]
  else
    goto <bb 4>; [34.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _3 = (int) _2;
  _4 ={v} MEM[(struct MSCM_Type *)1075412992B].IRSPRC[_3];
  _5 = (signed short) _4;
  _6 = ipc_hw_priv[_1].local_core;
  _7 = (unsigned int) _6;
  _8 = _7 + 4294967293;
  _9 = 1 << _8;
  _10 = (signed short) _9;
  _11 = _5 | _10;
  _12 = (short unsigned int) _11;
  MEM[(struct MSCM_Type *)1075412992B].IRSPRC[_3] ={v} _12;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function ipc_hw_irq_disable (ipc_hw_irq_disable, funcdef_no=11, decl_uid=5776, cgraph_uid=12, symbol_order=12)

Modification phase of node ipc_hw_irq_disable/12
ipc_hw_irq_disable (const uint8 instance)
{
  int _1;
  short int _2;
  int _3;
  short unsigned int _4;
  signed short _5;
  unsigned char _6;
  unsigned int _7;
  unsigned int _8;
  int _9;
  signed short _10;
  signed short _11;
  signed short _12;
  short unsigned int _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) instance_15(D);
  _2 = ipc_hw_priv[_1].mscm_rx_irq;
  if (_2 != -1)
    goto <bb 3>; [66.00%]
  else
    goto <bb 4>; [34.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _3 = (int) _2;
  _4 ={v} MEM[(struct MSCM_Type *)1075412992B].IRSPRC[_3];
  _5 = (signed short) _4;
  _6 = ipc_hw_priv[_1].local_core;
  _7 = (unsigned int) _6;
  _8 = _7 + 4294967293;
  _9 = 1 << _8;
  _10 = (signed short) _9;
  _11 = ~_10;
  _12 = _5 & _11;
  _13 = (short unsigned int) _12;
  MEM[(struct MSCM_Type *)1075412992B].IRSPRC[_3] ={v} _13;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function ipc_hw_irq_notify (ipc_hw_irq_notify, funcdef_no=12, decl_uid=5778, cgraph_uid=13, symbol_order=13)

Modification phase of node ipc_hw_irq_notify/13
ipc_hw_irq_notify (const uint8 instance)
{
  uint8 msi_tx_index;
  uint8 remote_core;
  int _1;
  short int _2;
  int _3;
  int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) instance_8(D);
  _2 = ipc_hw_priv[_1].mscm_tx_irq;
  if (_2 != -1)
    goto <bb 3>; [66.00%]
  else
    goto <bb 4>; [34.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  remote_core_10 = ipc_hw_priv[_1].remote_core;
  # DEBUG remote_core => remote_core_10
  # DEBUG BEGIN_STMT
  msi_tx_index_11 = ipc_hw_priv[_1].msi_tx_irq;
  # DEBUG msi_tx_index => msi_tx_index_11
  # DEBUG BEGIN_STMT
  _3 = (int) remote_core_10;
  _4 = (int) msi_tx_index_11;
  _5 ={v} MEM[(volatile struct IPC_MSCM_IRCPnIRx_Type *)1075415648B].IRCPnIRx[_3][_4].IPC_IGR;
  _6 = _5 | 1;
  MEM[(volatile struct IPC_MSCM_IRCPnIRx_Type *)1075415648B].IRCPnIRx[_3][_4].IPC_IGR ={v} _6;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function ipc_hw_irq_clear (ipc_hw_irq_clear, funcdef_no=13, decl_uid=5780, cgraph_uid=14, symbol_order=14)

Modification phase of node ipc_hw_irq_clear/14
ipc_hw_irq_clear (const uint8 instance)
{
  uint8 msi_rx_index;
  uint8 remote_core;
  uint8 local_core;
  int _1;
  short int _2;
  unsigned char _3;
  int _4;
  int _5;
  int _6;
  long unsigned int _7;
  int _8;
  int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) instance_11(D);
  _2 = ipc_hw_priv[_1].mscm_rx_irq;
  if (_2 != -1)
    goto <bb 3>; [66.00%]
  else
    goto <bb 6>; [34.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  local_core_13 = ipc_hw_priv[_1].local_core;
  # DEBUG local_core => local_core_13
  # DEBUG BEGIN_STMT
  remote_core_14 = ipc_hw_priv[_1].remote_core;
  # DEBUG remote_core => remote_core_14
  # DEBUG BEGIN_STMT
  msi_rx_index_15 = ipc_hw_priv[_1].msi_rx_irq;
  # DEBUG msi_rx_index => msi_rx_index_15
  # DEBUG BEGIN_STMT
  _3 = remote_core_14 + 252;
  if (_3 <= 3)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _4 = (int) remote_core_14;
  _5 = (int) local_core_13;
  _6 = (int) msi_rx_index_15;
  _7 = 1 << _4;
  MEM[(volatile struct IPC_MSCM_IRCPnIRx_Type *)1075415648B].IRCPnIRx[_5][_6].IPC_ISR ={v} _7;
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _8 = (int) local_core_13;
  _9 = (int) msi_rx_index_15;
  MEM[(volatile struct IPC_MSCM_IRCPnIRx_Type *)1075415648B].IRCPnIRx[_8][_9].IPC_ISR ={v} 3855;

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function ipc_hw_init (ipc_hw_init, funcdef_no=8, decl_uid=5770, cgraph_uid=9, symbol_order=9)

Modification phase of node ipc_hw_init/9
ipc_hw_init (const uint8 instance, const struct ipc_shm_cfg * cfg)
{
  sint8 err;
  int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  err_10 = ipc_hw_set_core (instance_7(D), cfg_8(D));
  # DEBUG err => err_10
  # DEBUG BEGIN_STMT
  if (err_10 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  err_12 = ipc_hw_set_irq_idx (instance_7(D), cfg_8(D));
  # DEBUG err => err_12

  <bb 4> [local count: 1073741824]:
  # err_3 = PHI <err_10(2), err_12(3)>
  # DEBUG err => err_3
  # DEBUG BEGIN_STMT
  if (err_3 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _1 = (int) instance_7(D);
  _2 = cfg_8(D)->shm_size;
  ipc_hw_priv[_1].shm_size = _2;
  # DEBUG BEGIN_STMT
  ipc_hw_irq_disable (instance_7(D));
  # DEBUG BEGIN_STMT
  ipc_hw_irq_clear (instance_7(D));

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return err_3;

}



;; Function ipc_hw_free (ipc_hw_free, funcdef_no=9, decl_uid=5772, cgraph_uid=10, symbol_order=10)

Modification phase of node ipc_hw_free/10
ipc_hw_free (const uint8 instance)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ipc_hw_irq_clear (instance_2(D));
  return;

}



;; Function ipc_hw_flush_cache_local (ipc_hw_flush_cache_local, funcdef_no=14, decl_uid=5782, cgraph_uid=15, symbol_order=15)

Modification phase of node ipc_hw_flush_cache_local/15
ipc_hw_flush_cache_local (const uint8 instance)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function ipc_hw_flush_cache_remote (ipc_hw_flush_cache_remote, funcdef_no=19, decl_uid=5784, cgraph_uid=16, symbol_order=16)

Modification phase of node ipc_hw_flush_cache_remote/16
ipc_hw_flush_cache_remote (const uint8 instance)
{
  <bb 2> [local count: 1073741824]:
  ipc_hw_flush_cache_local (instance_1(D)); [tail call]
  return;

}


