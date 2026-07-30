
IPA constant propagation start:
Determining dynamic type for call: oal_irq_detect_handle_bmu_spurious_interrupt (&bDetectSpuriousIsrBmu1, &bDetectSpuriousIsrBmu2);
  Starting walk at: oal_irq_detect_handle_bmu_spurious_interrupt (&bDetectSpuriousIsrBmu1, &bDetectSpuriousIsrBmu2);
  instance pointer: &bDetectSpuriousIsrBmu1  Outer instance pointer: bDetectSpuriousIsrBmu1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: oal_irq_detect_handle_bmu_spurious_interrupt (&bDetectSpuriousIsrBmu1, &bDetectSpuriousIsrBmu2);
  Starting walk at: oal_irq_detect_handle_bmu_spurious_interrupt (&bDetectSpuriousIsrBmu1, &bDetectSpuriousIsrBmu2);
  instance pointer: &bDetectSpuriousIsrBmu2  Outer instance pointer: bDetectSpuriousIsrBmu2 offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  oal_irq_common_handler/36:
  Jump functions of caller  Eth_43_PFE_BmuIrqHdlr/35:
    callsite  Eth_43_PFE_BmuIrqHdlr/35 -> oal_irq_clear_bmu_interrupt_status_flag/33 : 
    callsite  Eth_43_PFE_BmuIrqHdlr/35 -> oal_irq_detect_handle_bmu_spurious_interrupt/32 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  Eth_43_PFE_HifIrqHdlr_0/34:
    callsite  Eth_43_PFE_HifIrqHdlr_0/34 -> oal_irq_detect_hif_spurious_interrupt/30 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  oal_irq_clear_bmu_interrupt_status_flag/33:
  Jump functions of caller  oal_irq_detect_handle_bmu_spurious_interrupt/32:
  Jump functions of caller  oal_irq_detect_hif_spurious_interrupt/30:

 Propagating constants:

Not considering Eth_43_PFE_BmuIrqHdlr for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_HifIrqHdlr_0 for cloning; -fipa-cp-clone disabled.

overall_size: 76, max_new_size: 11001
 - context independent values, size: 9, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: Eth_43_PFE_BmuIrqHdlr/35:
  Node: Eth_43_PFE_HifIrqHdlr_0/34:
  Node: oal_irq_clear_bmu_interrupt_status_flag/33:
  Node: oal_irq_detect_handle_bmu_spurious_interrupt/32:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         bool_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         bool_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: oal_irq_detect_hif_spurious_interrupt/30:
    param [0]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         oal_irq_idx_t [0, 0]
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of oal_irq_detect_hif_spurious_interrupt/30 for all known contexts.
    replacing param #0 idx with const 0
Propagated bits info for function oal_irq_detect_hif_spurious_interrupt.constprop/41:
 param 0: value = 0x0, mask = 0x0
Propagated bits info for function oal_irq_detect_hif_spurious_interrupt/30:
 param 0: value = 0x0, mask = 0x0

IPA constant propagation end

Reclaiming functions: oal_irq_detect_hif_spurious_interrupt/30
Reclaiming variables:
Clearing address taken flags:
Symbol table:

oal_irq_detect_hif_spurious_interrupt.constprop.0/41 (oal_irq_detect_hif_spurious_interrupt.constprop) @079a0ee0
  Type: function definition analyzed
  Visibility:
  References: cbus_hif_int_en_var_addr/27 (read)cbus_hif_int_src_var_addr/28 (read)
  Referring: 
  Clone of oal_irq_detect_hif_spurious_interrupt/30
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Eth_43_PFE_HifIrqHdlr_0/34 (354334802 (estimated locally),0.33 per call) 
  Calls: 
bDetectBmuInit/38 (bDetectBmuInit) @0790ee10
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Eth_43_PFE_BmuIrqHdlr/35 (read)
  Availability: not_available
  Varpool flags:
Eth_PFE_LLD_bIrqInitStatus/37 (Eth_PFE_LLD_bIrqInitStatus) @0790e558
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Eth_43_PFE_HifIrqHdlr_0/34 (read)Eth_43_PFE_BmuIrqHdlr/35 (read)
  Availability: not_available
  Varpool flags:
oal_irq_common_handler/36 (oal_irq_common_handler) @0790c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_BmuIrqHdlr/35 (474808634 (estimated locally),0.44 per call) Eth_43_PFE_BmuIrqHdlr/35 (235632643 (estimated locally),0.22 per call) Eth_43_PFE_HifIrqHdlr_0/34 (116930485 (estimated locally),0.11 per call) 
  Calls: 
Eth_43_PFE_BmuIrqHdlr/35 (Eth_43_PFE_BmuIrqHdlr) @079a59a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_PFE_LLD_bIrqInitStatus/37 (read)bDetectBmuInit/38 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_irq_common_handler/36 (474808634 (estimated locally),0.44 per call) oal_irq_clear_bmu_interrupt_status_flag/33 (244598387 (estimated locally),0.23 per call) oal_irq_common_handler/36 (235632643 (estimated locally),0.22 per call) oal_irq_detect_handle_bmu_spurious_interrupt/32 (354334802 (estimated locally),0.33 per call) 
Eth_43_PFE_HifIrqHdlr_0/34 (Eth_43_PFE_HifIrqHdlr_0) @079a50e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_PFE_LLD_bIrqInitStatus/37 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_irq_common_handler/36 (116930485 (estimated locally),0.11 per call) oal_irq_detect_hif_spurious_interrupt.constprop/41 (354334802 (estimated locally),0.33 per call) 
oal_irq_clear_bmu_interrupt_status_flag/33 (oal_irq_clear_bmu_interrupt_status_flag) @079a5d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_43_PFE_BmuIrqHdlr/35 (244598387 (estimated locally),0.23 per call) 
  Calls: 
oal_irq_detect_handle_bmu_spurious_interrupt/32 (oal_irq_detect_handle_bmu_spurious_interrupt) @079a58c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_43_PFE_BmuIrqHdlr/35 (354334802 (estimated locally),0.33 per call) 
  Calls: 
oal_irq_detect_hif_spurious_interrupt/30 (oal_irq_detect_hif_spurious_interrupt) @079a5000
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
cbus_hif_int_src_var_addr/28 (cbus_hif_int_src_var_addr) @0799c798
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: oal_irq_detect_hif_spurious_interrupt.constprop.0/41 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
cbus_hif_int_en_var_addr/27 (cbus_hif_int_en_var_addr) @0799c6c0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: oal_irq_detect_hif_spurious_interrupt.constprop.0/41 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function Eth_43_PFE_HifIrqHdlr_0 (Eth_43_PFE_HifIrqHdlr_0, funcdef_no=29, decl_uid=11367, cgraph_uid=30, symbol_order=34)

Modification phase of node Eth_43_PFE_HifIrqHdlr_0/34
Eth_43_PFE_HifIrqHdlr_0 ()
{
  uint32 interrupt_src;
  uint32 interrupt_src;
  unsigned char _1;
  _Bool Eth_PFE_LLD_bIrqInitStatus.0_6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY oal_irq_check_driver_init_status
  # DEBUG BEGIN_STMT
  Eth_PFE_LLD_bIrqInitStatus.0_6 ={v} Eth_PFE_LLD_bIrqInitStatus;
  # DEBUG D#1 => (const bool_t) Eth_PFE_LLD_bIrqInitStatus.0_6
  # DEBUG init_status => D#1
  # DEBUG BEGIN_STMT
  # DEBUG init_status => NULL
  # DEBUG bDriverInitStatus => D#1
  # DEBUG BEGIN_STMT
  if (Eth_PFE_LLD_bIrqInitStatus.0_6 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _1 = oal_irq_detect_hif_spurious_interrupt (0);
  if (_1 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 116930485]:
  # DEBUG BEGIN_STMT
  oal_irq_common_handler (0);
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 237404317]:
  # DEBUG BEGIN_STMT
  # DEBUG int_src_var_addr => 1175028064
  # DEBUG INLINE_ENTRY oal_irq_clear_hif_interrupt_status_flag
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  interrupt_src_7 ={v} MEM[(volatile uint32_t *)1175028064B];
  # DEBUG interrupt_src => interrupt_src_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)1175028064B] ={v} interrupt_src_7;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  # DEBUG int_src_var_addr => 1175028064
  # DEBUG INLINE_ENTRY oal_irq_clear_hif_interrupt_status_flag
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  interrupt_src_8 ={v} MEM[(volatile uint32_t *)1175028064B];
  # DEBUG interrupt_src => interrupt_src_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)1175028064B] ={v} interrupt_src_8;
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  # DEBUG int_src_var_addr => NULL
  # DEBUG interrupt_src => NULL
  # DEBUG int_src_var_addr => NULL
  # DEBUG interrupt_src => NULL
  return;

}



;; Function Eth_43_PFE_BmuIrqHdlr (Eth_43_PFE_BmuIrqHdlr, funcdef_no=30, decl_uid=11369, cgraph_uid=31, symbol_order=35)

Modification phase of node Eth_43_PFE_BmuIrqHdlr/35
Eth_43_PFE_BmuIrqHdlr ()
{
  bool_t bDetectSpuriousIsrBmu2;
  bool_t bDetectSpuriousIsrBmu1;
  unsigned char bDetectSpuriousIsrBmu1.3_1;
  unsigned char bDetectSpuriousIsrBmu2.4_2;
  unsigned char bDetectBmuInit.5_3;
  _Bool Eth_PFE_LLD_bIrqInitStatus.0_14;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  bDetectSpuriousIsrBmu1 = 0;
  # DEBUG BEGIN_STMT
  bDetectSpuriousIsrBmu2 = 0;
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY oal_irq_check_driver_init_status
  # DEBUG BEGIN_STMT
  Eth_PFE_LLD_bIrqInitStatus.0_14 ={v} Eth_PFE_LLD_bIrqInitStatus;
  # DEBUG D#2 => (const bool_t) Eth_PFE_LLD_bIrqInitStatus.0_14
  # DEBUG init_status => D#2
  # DEBUG BEGIN_STMT
  # DEBUG init_status => NULL
  # DEBUG bDriverInitStatus => D#2
  # DEBUG BEGIN_STMT
  if (Eth_PFE_LLD_bIrqInitStatus.0_14 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  oal_irq_detect_handle_bmu_spurious_interrupt (&bDetectSpuriousIsrBmu1, &bDetectSpuriousIsrBmu2);
  # DEBUG BEGIN_STMT
  bDetectSpuriousIsrBmu1.3_1 = bDetectSpuriousIsrBmu1;
  if (bDetectSpuriousIsrBmu1.3_1 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 4> [local count: 237404317]:
  bDetectSpuriousIsrBmu2.4_2 = bDetectSpuriousIsrBmu2;
  if (bDetectSpuriousIsrBmu2.4_2 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 5> [local count: 235632643]:
  # DEBUG BEGIN_STMT
  oal_irq_common_handler (5);
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 719407022]:
  # DEBUG BEGIN_STMT
  bDetectBmuInit.5_3 ={v} bDetectBmuInit;
  if (bDetectBmuInit.5_3 == 1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 244598387]:
  # DEBUG BEGIN_STMT
  oal_irq_clear_bmu_interrupt_status_flag ();
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 474808634]:
  # DEBUG BEGIN_STMT
  oal_irq_common_handler (5);

  <bb 9> [local count: 1073741824]:
  bDetectSpuriousIsrBmu1 ={v} {CLOBBER};
  bDetectSpuriousIsrBmu2 ={v} {CLOBBER};
  return;

}


