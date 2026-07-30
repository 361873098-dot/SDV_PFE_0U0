
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_fw_fail_stop_cfg_irq_unmask/18:
  Jump functions of caller  pfe_fw_fail_stop_cfg_isr/17:
  Jump functions of caller  pfe_fw_fail_stop_cfg_irq_mask/16:
  Jump functions of caller  pfe_fw_fail_stop_cfg_irq_unmask_all/15:
  Jump functions of caller  autolibc_memset/14:
  Jump functions of caller  pfe_fw_fail_stop_irq_unmask/13:
  Jump functions of caller  pfe_fw_fail_stop_irq_mask/12:
  Jump functions of caller  pfe_fw_fail_stop_isr/11:
  Jump functions of caller  pfe_fw_fail_stop_destroy/10:
  Jump functions of caller  pfe_fw_fail_stop_create/9:

 Propagating constants:

Not considering pfe_fw_fail_stop_irq_unmask for cloning; -fipa-cp-clone disabled.
Function pfe_fw_fail_stop_irq_mask/12 is not versionable, reason: not a tree_versionable_function.
Not considering pfe_fw_fail_stop_isr for cloning; -fipa-cp-clone disabled.
Not considering pfe_fw_fail_stop_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_fw_fail_stop_create for cloning; -fipa-cp-clone disabled.

overall_size: 37, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_fw_fail_stop_irq_unmask/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_fw_fail_stop_irq_mask/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_fw_fail_stop_isr/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_fw_fail_stop_destroy/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_fw_fail_stop_create/9:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_fw_fail_stop_cfg_irq_unmask/18 (pfe_fw_fail_stop_cfg_irq_unmask) @06f36e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fw_fail_stop_irq_unmask/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fw_fail_stop_cfg_isr/17 (pfe_fw_fail_stop_cfg_isr) @06f36b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fw_fail_stop_isr/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fw_fail_stop_cfg_irq_mask/16 (pfe_fw_fail_stop_cfg_irq_mask) @06f369a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fw_fail_stop_destroy/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fw_fail_stop_cfg_irq_unmask_all/15 (pfe_fw_fail_stop_cfg_irq_unmask_all) @06f367e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fw_fail_stop_create/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/14 (autolibc_memset) @06f36700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fw_fail_stop_create/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fw_fail_stop_irq_unmask/13 (pfe_fw_fail_stop_irq_unmask) @06f362a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_fw_fail_stop_cfg_irq_unmask/18 (1073741824 (estimated locally),1.00 per call) 
pfe_fw_fail_stop_irq_mask/12 (pfe_fw_fail_stop_irq_mask) @06f36000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: pfe_fw_fail_stop_destroy/10 (1073741824 (estimated locally),1.00 per call) 
pfe_fw_fail_stop_isr/11 (pfe_fw_fail_stop_isr) @06f32c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_fw_fail_stop_cfg_isr/17 (1073741824 (estimated locally),1.00 per call) 
pfe_fw_fail_stop_destroy/10 (pfe_fw_fail_stop_destroy) @06f32e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: pfe_fw_fail_stop_irq_mask/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_fw_fail_stop_cfg_irq_mask/16 (1073741824 (estimated locally),1.00 per call) 
pfe_fw_fail_stop_create/9 (pfe_fw_fail_stop_create) @06f32b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: fw_fail_stop_instance/8 (addr)fw_fail_stop_instance/8 (write)fw_fail_stop_instance/8 (write)fw_fail_stop_instance/8 (write)fw_fail_stop_instance/8 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_fw_fail_stop_cfg_irq_unmask_all/15 (1073741824 (estimated locally),1.00 per call) autolibc_memset/14 (1073741824 (estimated locally),1.00 per call) 
fw_fail_stop_instance/8 (fw_fail_stop_instance) @06f2eb88
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_fw_fail_stop_create/9 (addr)pfe_fw_fail_stop_create/9 (write)pfe_fw_fail_stop_create/9 (write)pfe_fw_fail_stop_create/9 (write)pfe_fw_fail_stop_create/9 (addr)
  Availability: available
  Varpool flags:

;; Function pfe_fw_fail_stop_create (pfe_fw_fail_stop_create, funcdef_no=6, decl_uid=7245, cgraph_uid=7, symbol_order=9)

Modification phase of node pfe_fw_fail_stop_create/9
pfe_fw_fail_stop_create (addr_t cbus_base_va, addr_t fw_fail_stop_base)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG fw_fail_stop => &fw_fail_stop_instance
  # DEBUG BEGIN_STMT
  autolibc_memset (&fw_fail_stop_instance, 0, 12);
  # DEBUG BEGIN_STMT
  fw_fail_stop_instance.cbus_base_va = cbus_base_va_4(D);
  # DEBUG BEGIN_STMT
  fw_fail_stop_instance.fw_fail_stop_base_offset = fw_fail_stop_base_6(D);
  # DEBUG BEGIN_STMT
  _1 = cbus_base_va_4(D) + fw_fail_stop_base_6(D);
  fw_fail_stop_instance.fw_fail_stop_base_va = _1;
  # DEBUG BEGIN_STMT
  pfe_fw_fail_stop_cfg_irq_unmask_all (_1);
  # DEBUG BEGIN_STMT
  return &fw_fail_stop_instance;

}



;; Function pfe_fw_fail_stop_destroy (pfe_fw_fail_stop_destroy, funcdef_no=7, decl_uid=7247, cgraph_uid=8, symbol_order=10)

Modification phase of node pfe_fw_fail_stop_destroy/10
pfe_fw_fail_stop_destroy (struct pfe_fw_fail_stop_t * fw_fail_stop)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = fw_fail_stop_3(D)->fw_fail_stop_base_va;
  pfe_fw_fail_stop_cfg_irq_mask (_1);
  return;

}



;; Function pfe_fw_fail_stop_isr (pfe_fw_fail_stop_isr, funcdef_no=8, decl_uid=7249, cgraph_uid=9, symbol_order=11)

Modification phase of node pfe_fw_fail_stop_isr/11
pfe_fw_fail_stop_isr (const struct pfe_fw_fail_stop_t * fw_fail_stop)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  _1 = fw_fail_stop_3(D)->fw_fail_stop_base_va;
  ret_5 = pfe_fw_fail_stop_cfg_isr (_1);
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_fw_fail_stop_irq_mask (pfe_fw_fail_stop_irq_mask, funcdef_no=12, decl_uid=7251, cgraph_uid=10, symbol_order=12)

Modification phase of node pfe_fw_fail_stop_irq_mask/12
pfe_fw_fail_stop_irq_mask (const struct pfe_fw_fail_stop_t * fw_fail_stop)
{
  <bb 2> [local count: 1073741824]:
  pfe_fw_fail_stop_destroy (fw_fail_stop_2(D)); [tail call]
  return;

}



;; Function pfe_fw_fail_stop_irq_unmask (pfe_fw_fail_stop_irq_unmask, funcdef_no=10, decl_uid=7253, cgraph_uid=11, symbol_order=13)

Modification phase of node pfe_fw_fail_stop_irq_unmask/13
pfe_fw_fail_stop_irq_unmask (const struct pfe_fw_fail_stop_t * fw_fail_stop)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = fw_fail_stop_3(D)->fw_fail_stop_base_va;
  pfe_fw_fail_stop_cfg_irq_unmask (_1);
  return;

}


