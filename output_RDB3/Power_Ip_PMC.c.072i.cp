
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Power_Ip_PMC_PowerInit/0:

 Propagating constants:

Not considering Power_Ip_PMC_PowerInit for cloning; -fipa-cp-clone disabled.

overall_size: 5, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Power_Ip_PMC_PowerInit/0:
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

Power_Ip_PMC_PowerInit/0 (Power_Ip_PMC_PowerInit) @074d9ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Power_Ip_PMC_PowerInit (Power_Ip_PMC_PowerInit, funcdef_no=0, decl_uid=6511, cgraph_uid=1, symbol_order=0)

Modification phase of node Power_Ip_PMC_PowerInit/0
Power_Ip_PMC_PowerInit (const struct Power_Ip_PMC_ConfigType * ConfigPtr)
{
  long unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = ConfigPtr_3(D)->NcspdCtrl;
  MEM[(struct PMC_Type *)1074315264B].NCSPD_CTL ={v} _1;
  return;

}


