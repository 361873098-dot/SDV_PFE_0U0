
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  IntCtrl_Ip_Init/7:
  Jump functions of caller  Platform_Ipw_Init/6:

 Propagating constants:

Not considering Platform_Ipw_Init for cloning; -fipa-cp-clone disabled.

overall_size: 8, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Platform_Ipw_Init/6:
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

IntCtrl_Ip_Init/7 (IntCtrl_Ip_Init) @07531000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Platform_Ipw_Init/6 (574129754 (estimated locally),0.53 per call) 
  Calls: 
Platform_Ipw_Init/6 (Platform_Ipw_Init) @07529b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_Init/7 (574129754 (estimated locally),0.53 per call) 

;; Function Platform_Ipw_Init (Platform_Ipw_Init, funcdef_no=6, decl_uid=6308, cgraph_uid=7, symbol_order=6)

Modification phase of node Platform_Ipw_Init/6
Platform_Ipw_Init (const struct Platform_Ipw_ConfigType * pConfig)
{
  const struct IntCtrl_Ip_CtrlConfigType * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = pConfig_4(D)->pIntCtrlConfig;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG pIntCtrlCtrlConfig => _1
  # DEBUG INLINE_ENTRY Platform_Ipw_InitIntCtrl
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_Init (_1);
  # DEBUG BEGIN_STMT
  # DEBUG pIntCtrlCtrlConfig => NULL
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}


