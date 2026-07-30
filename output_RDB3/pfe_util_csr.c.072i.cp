
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_util_cfg_isr/8:

 Propagating constants:

Not considering pfe_util_cfg_isr for cloning; -fipa-cp-clone disabled.

overall_size: 6, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_util_cfg_isr/8:
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

pfe_util_cfg_isr/8 (pfe_util_cfg_isr) @0701bee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function pfe_util_cfg_isr (pfe_util_cfg_isr, funcdef_no=6, decl_uid=7242, cgraph_uid=7, symbol_order=8)

Modification phase of node pfe_util_cfg_isr/8
pfe_util_cfg_isr (addr_t base_va)
{
  uint32_t irq_src;
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 836152;
  _2 = (volatile uint32_t *) _1;
  irq_src_5 ={v} *_2;
  # DEBUG irq_src => irq_src_5
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} irq_src_5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}


