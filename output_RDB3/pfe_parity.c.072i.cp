
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_parity_cfg_irq_unmask/18:
  Jump functions of caller  pfe_parity_cfg_isr/17:
  Jump functions of caller  pfe_parity_cfg_irq_mask/16:
  Jump functions of caller  pfe_parity_cfg_irq_unmask_all/15:
  Jump functions of caller  autolibc_memset/14:
  Jump functions of caller  pfe_parity_irq_unmask/13:
  Jump functions of caller  pfe_parity_irq_mask/12:
  Jump functions of caller  pfe_parity_isr/11:
  Jump functions of caller  pfe_parity_destroy/10:
  Jump functions of caller  pfe_parity_create/9:

 Propagating constants:

Not considering pfe_parity_irq_unmask for cloning; -fipa-cp-clone disabled.
Function pfe_parity_irq_mask/12 is not versionable, reason: not a tree_versionable_function.
Not considering pfe_parity_isr for cloning; -fipa-cp-clone disabled.
Not considering pfe_parity_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_parity_create for cloning; -fipa-cp-clone disabled.

overall_size: 37, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_parity_irq_unmask/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_parity_irq_mask/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_parity_isr/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_parity_destroy/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_parity_create/9:
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

pfe_parity_cfg_irq_unmask/18 (pfe_parity_cfg_irq_unmask) @070dce00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_parity_irq_unmask/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_parity_cfg_isr/17 (pfe_parity_cfg_isr) @070dcb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_parity_isr/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_parity_cfg_irq_mask/16 (pfe_parity_cfg_irq_mask) @070dc9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_parity_destroy/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_parity_cfg_irq_unmask_all/15 (pfe_parity_cfg_irq_unmask_all) @070dc7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_parity_create/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/14 (autolibc_memset) @070dc700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_parity_create/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_parity_irq_unmask/13 (pfe_parity_irq_unmask) @070dc2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_parity_cfg_irq_unmask/18 (1073741824 (estimated locally),1.00 per call) 
pfe_parity_irq_mask/12 (pfe_parity_irq_mask) @070dc000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: pfe_parity_destroy/10 (1073741824 (estimated locally),1.00 per call) 
pfe_parity_isr/11 (pfe_parity_isr) @070d8c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_parity_cfg_isr/17 (1073741824 (estimated locally),1.00 per call) 
pfe_parity_destroy/10 (pfe_parity_destroy) @070d8e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: pfe_parity_irq_mask/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_parity_cfg_irq_mask/16 (1073741824 (estimated locally),1.00 per call) 
pfe_parity_create/9 (pfe_parity_create) @070d8b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: parity_instance/8 (addr)parity_instance/8 (write)parity_instance/8 (write)parity_instance/8 (write)parity_instance/8 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_parity_cfg_irq_unmask_all/15 (1073741824 (estimated locally),1.00 per call) autolibc_memset/14 (1073741824 (estimated locally),1.00 per call) 
parity_instance/8 (parity_instance) @070d4b88
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_parity_create/9 (addr)pfe_parity_create/9 (write)pfe_parity_create/9 (write)pfe_parity_create/9 (write)pfe_parity_create/9 (addr)
  Availability: available
  Varpool flags:

;; Function pfe_parity_create (pfe_parity_create, funcdef_no=6, decl_uid=7245, cgraph_uid=7, symbol_order=9)

Modification phase of node pfe_parity_create/9
pfe_parity_create (addr_t cbus_base_va, addr_t parity_base)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG parity => &parity_instance
  # DEBUG BEGIN_STMT
  autolibc_memset (&parity_instance, 0, 12);
  # DEBUG BEGIN_STMT
  parity_instance.cbus_base_va = cbus_base_va_4(D);
  # DEBUG BEGIN_STMT
  parity_instance.parity_base_offset = parity_base_6(D);
  # DEBUG BEGIN_STMT
  _1 = cbus_base_va_4(D) + parity_base_6(D);
  parity_instance.parity_base_va = _1;
  # DEBUG BEGIN_STMT
  pfe_parity_cfg_irq_unmask_all (_1);
  # DEBUG BEGIN_STMT
  return &parity_instance;

}



;; Function pfe_parity_destroy (pfe_parity_destroy, funcdef_no=7, decl_uid=7247, cgraph_uid=8, symbol_order=10)

Modification phase of node pfe_parity_destroy/10
pfe_parity_destroy (struct pfe_parity_t * parity)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = parity_3(D)->parity_base_va;
  pfe_parity_cfg_irq_mask (_1);
  return;

}



;; Function pfe_parity_isr (pfe_parity_isr, funcdef_no=8, decl_uid=7249, cgraph_uid=9, symbol_order=11)

Modification phase of node pfe_parity_isr/11
pfe_parity_isr (const struct pfe_parity_t * parity)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  _1 = parity_3(D)->parity_base_va;
  ret_5 = pfe_parity_cfg_isr (_1);
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_parity_irq_mask (pfe_parity_irq_mask, funcdef_no=12, decl_uid=7251, cgraph_uid=10, symbol_order=12)

Modification phase of node pfe_parity_irq_mask/12
pfe_parity_irq_mask (const struct pfe_parity_t * parity)
{
  <bb 2> [local count: 1073741824]:
  pfe_parity_destroy (parity_2(D)); [tail call]
  return;

}



;; Function pfe_parity_irq_unmask (pfe_parity_irq_unmask, funcdef_no=10, decl_uid=7253, cgraph_uid=11, symbol_order=13)

Modification phase of node pfe_parity_irq_unmask/13
pfe_parity_irq_unmask (const struct pfe_parity_t * parity)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = parity_3(D)->parity_base_va;
  pfe_parity_cfg_irq_unmask (_1);
  return;

}


