
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Dem_SetEventStatus/18:
  Jump functions of caller  pfe_hm_report/17:
  Jump functions of caller  pfe_host_fail_stop_cfg_irq_unmask_all/16:
  Jump functions of caller  pfe_host_fail_stop_cfg_irq_unmask/15:
  Jump functions of caller  pfe_host_fail_stop_cfg_irq_mask/14:
  Jump functions of caller  pfe_host_fail_stop_cfg_isr/13:

 Propagating constants:

Not considering pfe_host_fail_stop_cfg_irq_unmask_all for cloning; -fipa-cp-clone disabled.
Not considering pfe_host_fail_stop_cfg_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_host_fail_stop_cfg_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_host_fail_stop_cfg_isr for cloning; -fipa-cp-clone disabled.

overall_size: 47, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_host_fail_stop_cfg_irq_unmask_all/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_host_fail_stop_cfg_irq_unmask/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_host_fail_stop_cfg_irq_mask/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_host_fail_stop_cfg_isr/13:
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

Dem_SetEventStatus/18 (Dem_SetEventStatus) @075e9620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_host_fail_stop_cfg_isr/13 (512926469 (estimated locally),0.48 per call) 
  Calls: 
pfe_hm_report/17 (pfe_hm_report) @075e92a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_host_fail_stop_cfg_isr/13 (512926469 (estimated locally),0.48 per call) 
  Calls: 
pfe_host_fail_stop_cfg_irq_unmask_all/16 (pfe_host_fail_stop_cfg_irq_unmask_all) @075e9b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_host_fail_stop_cfg_irq_unmask/15 (pfe_host_fail_stop_cfg_irq_unmask) @075e98c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_host_fail_stop_cfg_irq_mask/14 (pfe_host_fail_stop_cfg_irq_mask) @075e9540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_host_fail_stop_cfg_isr/13 (pfe_host_fail_stop_cfg_isr) @075e91c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dem_SetEventStatus/18 (512926469 (estimated locally),0.48 per call) pfe_hm_report/17 (512926469 (estimated locally),0.48 per call) 

;; Function pfe_host_fail_stop_cfg_isr (pfe_host_fail_stop_cfg_isr, funcdef_no=11, decl_uid=7255, cgraph_uid=12, symbol_order=13)

Modification phase of node pfe_host_fail_stop_cfg_isr/13
pfe_host_fail_stop_cfg_isr (addr_t base_va)
{
  uint32_t trig_en_interrupts;
  errno_t ret;
  uint32_t reg_src;
  uint32_t reg_en;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  unsigned int _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_11(D) + 228;
  _2 = (volatile uint32_t *) _1;
  reg_en_13 ={v} *_2;
  # DEBUG reg_en => reg_en_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_en_13 & 4294967294;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = base_va_11(D) + 224;
  _5 = (volatile uint32_t *) _4;
  reg_src_15 ={v} *_5;
  # DEBUG reg_src => reg_src_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_5 ={v} reg_src_15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = reg_en_13 & reg_src_15;
  trig_en_interrupts_17 = _6 & 3;
  # DEBUG trig_en_interrupts => trig_en_interrupts_17
  # DEBUG BEGIN_STMT
  if (trig_en_interrupts_17 != 0)
    goto <bb 3>; [47.77%]
  else
    goto <bb 4>; [52.23%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  pfe_hm_report (10, 2, 151, "[%s:%d] ", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_host_fail_stop_csr.c", 69, "");
  # DEBUG BEGIN_STMT
  Dem_SetEventStatus (51, 3);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_9 = PHI <2(2), 0(3)>
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = ~reg_src_15;
  _8 = _7 & reg_en_13;
  *_2 ={v} _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_9;

}



;; Function pfe_host_fail_stop_cfg_irq_mask (pfe_host_fail_stop_cfg_irq_mask, funcdef_no=12, decl_uid=7257, cgraph_uid=13, symbol_order=14)

Modification phase of node pfe_host_fail_stop_cfg_irq_mask/14
pfe_host_fail_stop_cfg_irq_mask (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 228;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  reg_6 = _3 & 4294967294;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_host_fail_stop_cfg_irq_unmask (pfe_host_fail_stop_cfg_irq_unmask, funcdef_no=13, decl_uid=7259, cgraph_uid=14, symbol_order=15)

Modification phase of node pfe_host_fail_stop_cfg_irq_unmask/15
pfe_host_fail_stop_cfg_irq_unmask (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 228;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  reg_6 = _3 | 1;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_host_fail_stop_cfg_irq_unmask_all (pfe_host_fail_stop_cfg_irq_unmask_all, funcdef_no=14, decl_uid=7261, cgraph_uid=15, symbol_order=16)

Modification phase of node pfe_host_fail_stop_cfg_irq_unmask_all/16
pfe_host_fail_stop_cfg_irq_unmask_all (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 228;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 3;
  # DEBUG BEGIN_STMT
  return;

}


