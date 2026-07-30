
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_wdt_cfg_get_stat_value/26:
  Jump functions of caller  pfe_wdt_cfg_irq_unmask/25:
  Jump functions of caller  pfe_wdt_cfg_irq_mask/24:
  Jump functions of caller  pfe_wdt_cfg_isr/23:
  Jump functions of caller  pfe_wdt_cfg_fini/22:
  Jump functions of caller  pfe_wdt_cfg_init/21:
  Jump functions of caller  autolibc_memset/20:
  Jump functions of caller  pfe_wdt_get_stat_value/19:
  Jump functions of caller  pfe_wdt_irq_unmask/18:
  Jump functions of caller  pfe_wdt_irq_mask/17:
  Jump functions of caller  pfe_wdt_isr/16:
  Jump functions of caller  pfe_wdt_destroy/15:
  Jump functions of caller  pfe_wdt_create/14:

 Propagating constants:

Not considering pfe_wdt_get_stat_value for cloning; -fipa-cp-clone disabled.
Not considering pfe_wdt_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_wdt_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_wdt_isr for cloning; -fipa-cp-clone disabled.
Not considering pfe_wdt_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_wdt_create for cloning; -fipa-cp-clone disabled.

overall_size: 52, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_wdt_get_stat_value/19:
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
  Node: pfe_wdt_irq_unmask/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_wdt_irq_mask/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_wdt_isr/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_wdt_destroy/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_wdt_create/14:
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

pfe_wdt_cfg_get_stat_value/26 (pfe_wdt_cfg_get_stat_value) @0753ab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_wdt_get_stat_value/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_wdt_cfg_irq_unmask/25 (pfe_wdt_cfg_irq_unmask) @0753a9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_wdt_irq_unmask/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_wdt_cfg_irq_mask/24 (pfe_wdt_cfg_irq_mask) @0753a7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_wdt_irq_mask/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_wdt_cfg_isr/23 (pfe_wdt_cfg_isr) @0753a620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_wdt_isr/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_wdt_cfg_fini/22 (pfe_wdt_cfg_fini) @0753a460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_wdt_destroy/15 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_wdt_cfg_init/21 (pfe_wdt_cfg_init) @0753a2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_wdt_create/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/20 (autolibc_memset) @0753a1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_wdt_create/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_wdt_get_stat_value/19 (pfe_wdt_get_stat_value) @074af8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_wdt_cfg_get_stat_value/26 (1073741824 (estimated locally),1.00 per call) 
pfe_wdt_irq_unmask/18 (pfe_wdt_irq_unmask) @074af2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_wdt_cfg_irq_unmask/25 (1073741824 (estimated locally),1.00 per call) 
pfe_wdt_irq_mask/17 (pfe_wdt_irq_mask) @074afd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_wdt_cfg_irq_mask/24 (1073741824 (estimated locally),1.00 per call) 
pfe_wdt_isr/16 (pfe_wdt_isr) @074afa80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_wdt_cfg_isr/23 (1073741824 (estimated locally),1.00 per call) 
pfe_wdt_destroy/15 (pfe_wdt_destroy) @074af7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_wdt_cfg_fini/22 (574129754 (estimated locally),0.53 per call) 
pfe_wdt_create/14 (pfe_wdt_create) @074af540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: wdt_instance/13 (addr)wdt_instance/13 (write)wdt_instance/13 (write)wdt_instance/13 (write)wdt_instance/13 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_wdt_cfg_init/21 (1073741824 (estimated locally),1.00 per call) autolibc_memset/20 (1073741824 (estimated locally),1.00 per call) 
wdt_instance/13 (wdt_instance) @074ab7e0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_wdt_create/14 (addr)pfe_wdt_create/14 (write)pfe_wdt_create/14 (write)pfe_wdt_create/14 (write)pfe_wdt_create/14 (addr)
  Availability: available
  Varpool flags:

;; Function pfe_wdt_create (pfe_wdt_create, funcdef_no=11, decl_uid=9452, cgraph_uid=12, symbol_order=14)

Modification phase of node pfe_wdt_create/14
pfe_wdt_create (addr_t cbus_base_va, addr_t wdt_base)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG wdt => &wdt_instance
  # DEBUG BEGIN_STMT
  autolibc_memset (&wdt_instance, 0, 12);
  # DEBUG BEGIN_STMT
  wdt_instance.cbus_base_va = cbus_base_va_4(D);
  # DEBUG BEGIN_STMT
  wdt_instance.wdt_base_offset = wdt_base_6(D);
  # DEBUG BEGIN_STMT
  _1 = cbus_base_va_4(D) + wdt_base_6(D);
  wdt_instance.wdt_base_va = _1;
  # DEBUG BEGIN_STMT
  pfe_wdt_cfg_init (_1);
  # DEBUG BEGIN_STMT
  return &wdt_instance;

}



;; Function pfe_wdt_destroy (pfe_wdt_destroy, funcdef_no=12, decl_uid=9454, cgraph_uid=13, symbol_order=15)

Modification phase of node pfe_wdt_destroy/15
pfe_wdt_destroy (struct pfe_wdt_t * wdt)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (wdt_3(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _1 = wdt_3(D)->wdt_base_va;
  pfe_wdt_cfg_fini (_1);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function pfe_wdt_isr (pfe_wdt_isr, funcdef_no=13, decl_uid=9456, cgraph_uid=14, symbol_order=16)

Modification phase of node pfe_wdt_isr/16
pfe_wdt_isr (struct pfe_wdt_t * wdt)
{
  errno_t ret;
  unsigned int _1;
  unsigned int _2;
  int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = wdt_6(D)->wdt_base_va;
  _2 = wdt_6(D)->cbus_base_va;
  _3 = pfe_wdt_cfg_isr (_1, _2);
  if (_3 == 0)
    goto <bb 4>; [65.00%]
  else
    goto <bb 3>; [35.00%]

  <bb 3> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22

  <bb 4> [local count: 1073741824]:
  # ret_4 = PHI <0(2), 22(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_wdt_irq_mask (pfe_wdt_irq_mask, funcdef_no=14, decl_uid=9458, cgraph_uid=15, symbol_order=17)

Modification phase of node pfe_wdt_irq_mask/17
pfe_wdt_irq_mask (struct pfe_wdt_t * wdt)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = wdt_3(D)->wdt_base_va;
  pfe_wdt_cfg_irq_mask (_1);
  return;

}



;; Function pfe_wdt_irq_unmask (pfe_wdt_irq_unmask, funcdef_no=15, decl_uid=9460, cgraph_uid=16, symbol_order=18)

Modification phase of node pfe_wdt_irq_unmask/18
pfe_wdt_irq_unmask (struct pfe_wdt_t * wdt)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = wdt_3(D)->wdt_base_va;
  pfe_wdt_cfg_irq_unmask (_1);
  return;

}



;; Function pfe_wdt_get_stat_value (pfe_wdt_get_stat_value, funcdef_no=16, decl_uid=9463, cgraph_uid=17, symbol_order=19)

Modification phase of node pfe_wdt_get_stat_value/19
pfe_wdt_get_stat_value (const struct pfe_wdt_t * wdt, uint32_t stat_id)
{
  uint32_t stat_value;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = wdt_3(D)->wdt_base_va;
  stat_value_6 = pfe_wdt_cfg_get_stat_value (_1, stat_id_4(D));
  # DEBUG stat_value => stat_value_6
  # DEBUG BEGIN_STMT
  return stat_value_6;

}


