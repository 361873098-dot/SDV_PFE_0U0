
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  vTaskGenericNotifyGiveFromISR/20:
  Jump functions of caller  ipc_hw_irq_clear/19:
  Jump functions of caller  ipc_hw_irq_disable/18:
  Jump functions of caller  vTaskDelete/17:
  Jump functions of caller  ipc_hw_irq_enable/16:
  Jump functions of caller  ulTaskGenericNotifyTake/15:
  Jump functions of caller  xTaskCreate/14:
  Jump functions of caller  ipc_os_poll_channels/13:
    indirect simple callsite, calling param -1, offset 0, for stmt _3 (instance_6(D), 128);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 128
         value: 0x80, mask: 0x0
         Unknown VR
  Jump functions of caller  ipc_os_get_remote_shm/12:
  Jump functions of caller  ipc_os_get_local_shm/11:
  Jump functions of caller  ipc_shm_hardirq_instance/10:
  Jump functions of caller  ipc_shm_hardirq/9:
  Jump functions of caller  ipc_shm_softirq/8:
    indirect simple callsite, calling param -1, offset 0, for stmt work_21 = _4 (0, 128);
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: CONST: 128
         value: 0x80, mask: 0x0
         Unknown VR
  Jump functions of caller  ipc_os_free/7:
    callsite  ipc_os_free/7 -> ipc_os_free_irq/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_os_free_irq/6:
  Jump functions of caller  ipc_os_init/5:

 Propagating constants:

Not considering ipc_os_poll_channels for cloning; -fipa-cp-clone disabled.
Not considering ipc_os_get_remote_shm for cloning; -fipa-cp-clone disabled.
Not considering ipc_os_get_local_shm for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_hardirq_instance for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_hardirq for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_softirq for cloning; -fipa-cp-clone disabled.
Not considering ipc_os_free for cloning; -fipa-cp-clone disabled.
Not considering ipc_os_init for cloning; -fipa-cp-clone disabled.

overall_size: 212, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: ipc_os_poll_channels/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_os_get_remote_shm/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_os_get_local_shm/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_shm_hardirq_instance/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_shm_hardirq/9:
  Node: ipc_shm_softirq/8:
  Node: ipc_os_free/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_os_free_irq/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ipc_os_init/5:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

vTaskGenericNotifyGiveFromISR/20 (vTaskGenericNotifyGiveFromISR) @06e83b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_hardirq_instance/10 (177167401 (estimated locally),0.17 per call) ipc_shm_hardirq/9 (118111601 (estimated locally),0.50 per call) 
  Calls: 
ipc_hw_irq_clear/19 (ipc_hw_irq_clear) @06e83a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_hardirq_instance/10 (177167401 (estimated locally),0.17 per call) ipc_shm_hardirq/9 (477815111 (estimated locally),2.02 per call) 
  Calls: 
ipc_hw_irq_disable/18 (ipc_hw_irq_disable) @06e838c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_hardirq_instance/10 (177167401 (estimated locally),0.17 per call) ipc_shm_hardirq/9 (477815111 (estimated locally),2.02 per call) ipc_os_free_irq/6 (31827503 (estimated locally),0.22 per call) 
  Calls: 
vTaskDelete/17 (vTaskDelete) @06e83700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_os_free/7 (6431177 (estimated locally),0.11 per call) 
  Calls: 
ipc_hw_irq_enable/16 (ipc_hw_irq_enable) @06e83460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_softirq/8 (55660688 (estimated locally),10151.50 per call) 
  Calls: 
ulTaskGenericNotifyTake/15 (ulTaskGenericNotifyTake) @06e832a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_softirq/8 (54829931 (estimated locally),9999.99 per call) ipc_shm_softirq/8 (5483 (estimated locally),1.00 per call) 
  Calls: 
xTaskCreate/14 (xTaskCreate) @06e830e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_os_init/5 (231826379 (estimated locally),0.22 per call) 
  Calls: 
ipc_os_poll_channels/13 (ipc_os_poll_channels) @06e7eee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_os_priv/4 (read)ipc_os_priv/4 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1032832261 (estimated locally),0.96 per call) 
ipc_os_get_remote_shm/12 (ipc_os_get_remote_shm) @06e7ec40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_os_priv/4 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ipc_os_get_local_shm/11 (ipc_os_get_local_shm) @06e7e9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_os_priv/4 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ipc_shm_hardirq_instance/10 (ipc_shm_hardirq_instance) @06e7e700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (write)ipc_os_priv/4 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: vTaskGenericNotifyGiveFromISR/20 (177167401 (estimated locally),0.17 per call) ipc_hw_irq_clear/19 (177167401 (estimated locally),0.17 per call) ipc_hw_irq_disable/18 (177167401 (estimated locally),0.17 per call) 
ipc_shm_hardirq/9 (ipc_shm_hardirq) @06e7e1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (write)ipc_os_priv/4 (read)
  Referring: 
  Availability: available
  Function flags: count:236223200 (estimated locally) body optimize_size
  Called by: 
  Calls: vTaskGenericNotifyGiveFromISR/20 (118111601 (estimated locally),0.50 per call) ipc_hw_irq_clear/19 (477815111 (estimated locally),2.02 per call) ipc_hw_irq_disable/18 (477815111 (estimated locally),2.02 per call) 
ipc_shm_softirq/8 (ipc_shm_softirq) @06ebc540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (write)ipc_os_priv/4 (read)
  Referring: ipc_os_init/5 (addr)
  Availability: available
  Function flags: count:5483 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: ulTaskGenericNotifyTake/15 (54829931 (estimated locally),9999.99 per call) ipc_hw_irq_enable/16 (55660688 (estimated locally),10151.50 per call) ulTaskGenericNotifyTake/15 (5483 (estimated locally),1.00 per call) 
   Indirect call(1073741824 (estimated locally),195831.08 per call) 
ipc_os_free/7 (ipc_os_free) @06ebcc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_os_priv/4 (write)ipc_os_priv/4 (write)ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_os_priv/4 (write)
  Referring: 
  Availability: available
  Function flags: count:59055799 (estimated locally) body optimize_size
  Called by: 
  Calls: vTaskDelete/17 (6431177 (estimated locally),0.11 per call) ipc_os_free_irq/6 (59055799 (estimated locally),1.00 per call) 
ipc_os_free_irq/6 (ipc_os_free_irq) @06ebc9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_os_priv/4 (read)ipc_os_priv/4 (read)
  Referring: 
  Availability: local
  Function flags: count:146131791 (estimated locally) body local optimize_size
  Called by: ipc_os_free/7 (59055799 (estimated locally),1.00 per call) 
  Calls: ipc_hw_irq_disable/18 (31827503 (estimated locally),0.22 per call) 
ipc_os_init/5 (ipc_os_init) @06ebc700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_os_priv/4 (write)ipc_os_priv/4 (write)ipc_os_priv/4 (write)ipc_os_priv/4 (write)ipc_os_priv/4 (write)ipc_os_priv/4 (write)ipc_os_priv/4 (read)ipc_os_priv/4 (read)ipc_shm_softirq/8 (addr)ipc_os_priv/4 (addr)ipc_os_priv/4 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskCreate/14 (231826379 (estimated locally),0.22 per call) 
ipc_os_priv/4 (ipc_os_priv) @06eb3ea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ipc_os_init/5 (write)ipc_os_init/5 (write)ipc_os_free/7 (read)ipc_os_free/7 (read)ipc_os_init/5 (write)ipc_os_free/7 (read)ipc_shm_hardirq/9 (read)ipc_shm_softirq/8 (read)ipc_shm_softirq/8 (write)ipc_shm_softirq/8 (read)ipc_os_free/7 (read)ipc_os_free/7 (write)ipc_shm_hardirq/9 (read)ipc_shm_hardirq_instance/10 (read)ipc_shm_hardirq/9 (write)ipc_os_get_local_shm/11 (read)ipc_os_init/5 (addr)ipc_os_init/5 (write)ipc_os_init/5 (write)ipc_shm_softirq/8 (read)ipc_shm_softirq/8 (read)ipc_shm_softirq/8 (read)ipc_os_free_irq/6 (read)ipc_os_free_irq/6 (read)ipc_shm_hardirq/9 (read)ipc_shm_hardirq_instance/10 (write)ipc_os_get_remote_shm/12 (read)ipc_os_init/5 (read)ipc_os_init/5 (read)ipc_os_init/5 (write)ipc_os_init/5 (write)ipc_os_free/7 (write)ipc_os_free/7 (write)ipc_os_free/7 (read)ipc_shm_hardirq_instance/10 (read)ipc_shm_hardirq_instance/10 (read)ipc_shm_hardirq_instance/10 (read)ipc_os_poll_channels/13 (read)ipc_os_poll_channels/13 (read)
  Availability: available
  Varpool flags:

;; Function ipc_shm_softirq (ipc_shm_softirq, funcdef_no=7, decl_uid=6175, cgraph_uid=8, symbol_order=8) (executed once)

Modification phase of node ipc_shm_softirq/8
ipc_shm_softirq ()
{
  uint8 i;
  uint32 work;
  unsigned char _1;
  unsigned char _2;
  short int _3;
  uint32 (*<T4c4>) (const uint8, uint32) _4;
  unsigned char _6;

  <bb 2> [local count: 5483]:
  # DEBUG BEGIN_STMT
  # DEBUG work => 0
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  # DEBUG BEGIN_STMT
  ulTaskGenericNotifyTake (0, 1, 4294967295);

  <bb 3> [local count: 54829931]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 19>; [100.00%]

  <bb 4> [local count: 443623990]:
  # DEBUG BEGIN_STMT
  _1 = ipc_os_priv.id[0].state;
  if (_1 == 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 5> [local count: 297228074]:
  _2 = ipc_os_priv.id[0].msg_received;
  if (_2 == 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 6> [local count: 199142809]:
  _3 = ipc_os_priv.id[0].rx_irq_num;
  if (_3 == -1)
    goto <bb 7>; [40.69%]
  else
    goto <bb 21>; [59.31%]

  <bb 7> [local count: 325512390]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 11>; [100.00%]

  <bb 21> [local count: 118111600]:

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = ipc_os_priv.id[0].rx_cb;
  work_21 = _4 (0, 128);
  # DEBUG work => work_21
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (work_21 > 127)
    goto <bb 22>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 22> [local count: 955630225]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  ipc_os_priv.id[0].msg_received = 0;

  <bb 11> [local count: 443623991]:
  # i_5 = PHI <1(7), 1(9)>

  <bb 19> [local count: 498453922]:
  # i_7 = PHI <i_5(11), 0(3)>
  # DEBUG i => i_7
  # DEBUG BEGIN_STMT
  if (i_7 == 0)
    goto <bb 4>; [89.00%]
  else
    goto <bb 20>; [11.00%]

  <bb 20> [local count: 54829931]:
  goto <bb 18>; [100.00%]

  <bb 12> [local count: 111321376]:
  # DEBUG BEGIN_STMT
  _6 = ipc_os_priv.id[0].state;
  if (_6 == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 55660688]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 16>; [100.00%]

  <bb 14> [local count: 55660688]:
  # DEBUG BEGIN_STMT
  ipc_hw_irq_enable (0);

  <bb 16> [local count: 111321376]:
  # i_11 = PHI <1(14), 1(13)>

  <bb 18> [local count: 166151307]:
  # i_8 = PHI <i_11(16), 0(20)>
  # DEBUG i => i_8
  # DEBUG BEGIN_STMT
  if (i_8 == 0)
    goto <bb 12>; [67.00%]
  else
    goto <bb 17>; [33.00%]

  <bb 17> [local count: 54829931]:
  # DEBUG BEGIN_STMT
  ulTaskGenericNotifyTake (0, 1, 4294967295);
  # DEBUG BEGIN_STMT
  goto <bb 3>; [100.00%]

}



;; Function ipc_os_init (ipc_os_init, funcdef_no=4, decl_uid=5755, cgraph_uid=5, symbol_order=5)

Modification phase of node ipc_os_init/5
ipc_os_init (const uint8 instance, const struct ipc_shm_cfg * cfg, uint32 (*<T4c4>) (const uint8, uint32) rx_cb)
{
  sint8 err;
  BaseType_t os_status;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  short int _4;
  short int _5;
  _Bool _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG os_status => 0
  # DEBUG BEGIN_STMT
  # DEBUG err => -3
  # DEBUG BEGIN_STMT
  if (rx_cb_9(D) != 0B)
    goto <bb 3>; [99.13%]
  else
    goto <bb 7>; [0.87%]

  <bb 3> [local count: 1064400271]:
  # DEBUG BEGIN_STMT
  _1 = (int) instance_11(D);
  _2 = cfg_12(D)->local_shm_addr;
  ipc_os_priv.id[_1].local_shm = _2;
  # DEBUG BEGIN_STMT
  _3 = cfg_12(D)->remote_shm_addr;
  ipc_os_priv.id[_1].remote_shm = _3;
  # DEBUG BEGIN_STMT
  ipc_os_priv.id[_1].state = 1;
  # DEBUG BEGIN_STMT
  ipc_os_priv.id[_1].rx_cb = rx_cb_9(D);
  # DEBUG BEGIN_STMT
  _4 = cfg_12(D)->inter_core_rx_irq;
  ipc_os_priv.id[_1].rx_irq_num = _4;
  # DEBUG BEGIN_STMT
  ipc_os_priv.id[_1].msg_received = 0;
  # DEBUG BEGIN_STMT
  _5 = ipc_os_priv.id[_1].rx_irq_num;
  if (_5 == -1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 4> [local count: 702504179]:
  _6 = ipc_os_priv.task_is_initialized;
  if (_6 != 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 5>; [33.00%]

  <bb 5> [local count: 231826379]:
  # DEBUG BEGIN_STMT
  os_status_20 = xTaskCreate (ipc_shm_softirq, "softirq", 256, 0B, 9, &ipc_os_priv.softirq_handle);
  # DEBUG os_status => os_status_20
  # DEBUG BEGIN_STMT
  if (os_status_20 != 1)
    goto <bb 7>; [3.81%]
  else
    goto <bb 6>; [96.19%]

  <bb 6> [local count: 222993794]:
  # DEBUG BEGIN_STMT
  ipc_os_priv.task_is_initialized = 1;
  # DEBUG BEGIN_STMT
  # DEBUG err => 0

  <bb 7> [local count: 1073741824]:
  # err_7 = PHI <-3(2), 0(4), -2(5), 0(6), 0(3)>
  # DEBUG err => err_7
  # DEBUG BEGIN_STMT
  return err_7;

}



;; Function ipc_os_free (ipc_os_free, funcdef_no=6, decl_uid=5757, cgraph_uid=7, symbol_order=7)

Modification phase of node ipc_os_free/7
ipc_os_free (const uint8 instance)
{
  int keep_softirq_active;
  uint8 instance_id;
  int _1;
  unsigned char _4;
  short int _5;
  short int _7;
  _Bool _8;
  struct tskTaskControlBlock * _9;

  <bb 2> [local count: 59055799]:
  # DEBUG BEGIN_STMT
  # DEBUG instance_id => 0
  # DEBUG BEGIN_STMT
  # DEBUG keep_softirq_active => 0
  # DEBUG BEGIN_STMT
  ipc_os_free_irq (instance_15(D));
  # DEBUG BEGIN_STMT
  _1 = (int) instance_15(D);
  ipc_os_priv.id[_1].rx_cb = 0B;
  # DEBUG BEGIN_STMT
  ipc_os_priv.id[_1].state = 0;
  # DEBUG BEGIN_STMT
  # DEBUG instance_id => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  _4 = ipc_os_priv.id[0].state;
  if (_4 == 1)
    goto <bb 4>; [67.00%]
  else
    goto <bb 16>; [33.00%]

  <bb 16> [local count: 334846388]:
  goto <bb 13>; [100.00%]

  <bb 4> [local count: 679839635]:
  _5 = ipc_os_priv.id[0].rx_irq_num;
  if (_5 != -1)
    goto <bb 5>; [5.50%]
  else
    goto <bb 15>; [94.50%]

  <bb 15> [local count: 642448455]:
  goto <bb 14>; [100.00%]

  <bb 5> [local count: 37391180]:
  # DEBUG BEGIN_STMT
  keep_softirq_active_21 = keep_softirq_active_12 + 1;
  # DEBUG keep_softirq_active => keep_softirq_active_21

  <bb 7> [local count: 96446979]:
  # instance_id_22 = PHI <0(2), 1(5)>
  # keep_softirq_active_6 = PHI <0(2), keep_softirq_active_21(5)>

  <bb 14> [local count: 738895437]:
  # instance_id_11 = PHI <instance_id_22(7), 1(15)>
  # keep_softirq_active_3 = PHI <keep_softirq_active_6(7), keep_softirq_active_12(15)>

  <bb 13> [local count: 1073741824]:
  # instance_id_10 = PHI <instance_id_11(14), 1(16)>
  # keep_softirq_active_12 = PHI <keep_softirq_active_3(14), keep_softirq_active_12(16)>
  # DEBUG keep_softirq_active => keep_softirq_active_12
  # DEBUG instance_id => instance_id_10
  # DEBUG BEGIN_STMT
  if (instance_id_10 == 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 59055800]:
  # keep_softirq_active_2 = PHI <keep_softirq_active_12(13)>
  # DEBUG BEGIN_STMT
  _7 = ipc_os_priv.id[_1].rx_irq_num;
  if (_7 != -1)
    goto <bb 9>; [66.00%]
  else
    goto <bb 12>; [34.00%]

  <bb 9> [local count: 38976828]:
  if (keep_softirq_active_2 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 10> [local count: 19488414]:
  # DEBUG BEGIN_STMT
  _8 = ipc_os_priv.task_is_initialized;
  if (_8 != 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 11> [local count: 6431177]:
  # DEBUG BEGIN_STMT
  _9 = ipc_os_priv.softirq_handle;
  vTaskDelete (_9);
  # DEBUG BEGIN_STMT
  ipc_os_priv.task_is_initialized = 0;

  <bb 12> [local count: 59055800]:
  return;

}



;; Function ipc_shm_hardirq (ipc_shm_hardirq, funcdef_no=8, decl_uid=5765, cgraph_uid=9, symbol_order=9)

Modification phase of node ipc_shm_hardirq/9
ipc_shm_hardirq ()
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  uint8 i;
  BaseType_t higher_prio_task_woken;
  _Bool _1;
  unsigned char _3;
  struct tskTaskControlBlock * _4;
  long int higher_prio_task_woken.5_5;

  <bb 2> [local count: 236223200]:
  # DEBUG BEGIN_STMT
  higher_prio_task_woken = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  # DEBUG BEGIN_STMT
  _1 = ipc_os_priv.task_is_initialized;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY ulPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mrs %0, basepri											
	mov %1, %2												
	cpsid i													
	msr basepri, %1											
	isb														
	dsb														
	cpsie i													
" : "=r" ulOriginalBASEPRI_20, "=r" ulNewBASEPRI_21 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_21
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_20
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG task_critical_status_from_isr => ulOriginalBASEPRI_20
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 12>; [100.00%]

  <bb 4> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _3 = ipc_os_priv.id[0].state;
  if (_3 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 477815111]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 477815111]:
  # DEBUG BEGIN_STMT
  ipc_hw_irq_disable (0);
  # DEBUG BEGIN_STMT
  ipc_hw_irq_clear (0);
  # DEBUG BEGIN_STMT
  ipc_os_priv.id[0].msg_received = 1;

  <bb 8> [local count: 955630223]:
  # i_7 = PHI <1(5), 1(6)>

  <bb 12> [local count: 1073741824]:
  # i_6 = PHI <i_7(8), 0(3)>
  # DEBUG i => i_6
  # DEBUG BEGIN_STMT
  if (i_6 == 0)
    goto <bb 4>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  _4 = ipc_os_priv.softirq_handle;
  vTaskGenericNotifyGiveFromISR (_4, 0, &higher_prio_task_woken);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_20
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_20 : "memory");
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  higher_prio_task_woken.5_5 = higher_prio_task_woken;
  if (higher_prio_task_woken.5_5 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");

  <bb 11> [local count: 236223201]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  higher_prio_task_woken ={v} {CLOBBER};
  return;

}



;; Function ipc_shm_hardirq_instance (ipc_shm_hardirq_instance, funcdef_no=9, decl_uid=5767, cgraph_uid=10, symbol_order=10)

Modification phase of node ipc_shm_hardirq_instance/10
ipc_shm_hardirq_instance (const uint8 instance)
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  BaseType_t higher_prio_task_woken;
  _Bool _1;
  int _2;
  unsigned char _3;
  unsigned char _4;
  struct tskTaskControlBlock * _5;
  long int higher_prio_task_woken.6_6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  higher_prio_task_woken = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = ipc_os_priv.task_is_initialized;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY ulPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mrs %0, basepri											
	mov %1, %2												
	cpsid i													
	msr basepri, %1											
	isb														
	dsb														
	cpsie i													
" : "=r" ulOriginalBASEPRI_21, "=r" ulNewBASEPRI_22 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_22
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_21
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG task_critical_status_from_isr => ulOriginalBASEPRI_21
  # DEBUG BEGIN_STMT
  _2 = (int) instance_12(D);
  _3 = ipc_os_priv.id[_2].state;
  if (_3 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  ipc_hw_irq_disable (instance_12(D));
  # DEBUG BEGIN_STMT
  ipc_hw_irq_clear (instance_12(D));
  # DEBUG BEGIN_STMT
  _4 = ipc_os_priv.id[_2].msg_received;
  if (_4 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 88583701]:
  # DEBUG BEGIN_STMT
  ipc_os_priv.id[_2].msg_received = 1;

  <bb 6> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  _5 = ipc_os_priv.softirq_handle;
  vTaskGenericNotifyGiveFromISR (_5, 0, &higher_prio_task_woken);

  <bb 7> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_21
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_21 : "memory");
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  higher_prio_task_woken.6_6 = higher_prio_task_woken;
  if (higher_prio_task_woken.6_6 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  higher_prio_task_woken ={v} {CLOBBER};
  return;

}



;; Function ipc_os_get_local_shm (ipc_os_get_local_shm, funcdef_no=10, decl_uid=5759, cgraph_uid=11, symbol_order=11)

Modification phase of node ipc_os_get_local_shm/11
ipc_os_get_local_shm (const uint8 instance)
{
  int _1;
  uintptr _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) instance_2(D);
  _4 = ipc_os_priv.id[_1].local_shm;
  return _4;

}



;; Function ipc_os_get_remote_shm (ipc_os_get_remote_shm, funcdef_no=11, decl_uid=5761, cgraph_uid=12, symbol_order=12)

Modification phase of node ipc_os_get_remote_shm/12
ipc_os_get_remote_shm (const uint8 instance)
{
  int _1;
  uintptr _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) instance_2(D);
  _4 = ipc_os_priv.id[_1].remote_shm;
  return _4;

}



;; Function ipc_os_poll_channels (ipc_os_poll_channels, funcdef_no=12, decl_uid=5763, cgraph_uid=13, symbol_order=13)

Modification phase of node ipc_os_poll_channels/13
ipc_os_poll_channels (const uint8 instance)
{
  sint8 err;
  int _1;
  short int _2;
  uint32 (*<T4c4>) (const uint8, uint32) _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  _1 = (int) instance_6(D);
  _2 = ipc_os_priv.id[_1].rx_irq_num;
  if (_2 == -1)
    goto <bb 3>; [96.19%]
  else
    goto <bb 4>; [3.81%]

  <bb 3> [local count: 1032832261]:
  # DEBUG BEGIN_STMT
  _3 = ipc_os_priv.id[_1].rx_cb;
  _3 (instance_6(D), 128);

  <bb 4> [local count: 1073741824]:
  # err_4 = PHI <0(3), -3(2)>
  # DEBUG err => err_4
  # DEBUG BEGIN_STMT
  return err_4;

}


