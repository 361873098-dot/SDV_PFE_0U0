
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Serdes_schm_read_msr/0:

 Propagating constants:

Not considering Serdes_schm_read_msr for cloning; -fipa-cp-clone disabled.

overall_size: 4, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Serdes_schm_read_msr/0:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Serdes_schm_read_msr/0 (Serdes_schm_read_msr) @06dcad20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Serdes_schm_read_msr (Serdes_schm_read_msr, funcdef_no=0, decl_uid=5647, cgraph_uid=1, symbol_order=0)

Modification phase of node Serdes_schm_read_msr/0
Serdes_schm_read_msr ()
{
  register uint32 reg_tmp;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" mrs %0, primask " : "=r" reg_tmp_1);
  # DEBUG reg_tmp => reg_tmp_1
  # DEBUG BEGIN_STMT
  return reg_tmp_1;

}


