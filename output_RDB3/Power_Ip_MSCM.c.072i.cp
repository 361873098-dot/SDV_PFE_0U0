
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Power_Ip_MSCM_GetPersonality/0:

 Propagating constants:

Not considering Power_Ip_MSCM_GetPersonality for cloning; -fipa-cp-clone disabled.

overall_size: 9, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Power_Ip_MSCM_GetPersonality/0:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Power_Ip_MSCM_GetPersonality/0 (Power_Ip_MSCM_GetPersonality) @074898c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Power_Ip_MSCM_GetPersonality (Power_Ip_MSCM_GetPersonality, funcdef_no=0, decl_uid=6367, cgraph_uid=1, symbol_order=0)

Modification phase of node Power_Ip_MSCM_GetPersonality/0
Power_Ip_MSCM_GetPersonality ()
{
  Power_Ip_MSCM_CpxType MSCMPersonality;
  uint32 MSCMCpxType;
  long unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG MSCMPersonality => 0
  # DEBUG BEGIN_STMT
  MSCMCpxType_4 ={v} MEM[(struct MSCM_Type *)1075412992B].CPXTYPE;
  # DEBUG MSCMCpxType => MSCMCpxType_4
  # DEBUG BEGIN_STMT
  _1 = MSCMCpxType_4 & 4278190080;
  if (_1 == 1090519040)
    goto <bb 5>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  if (_1 == 1124073472)
    goto <bb 4>; [21.72%]
  else
    goto <bb 5>; [78.28%]

  <bb 4> [local count: 153923038]:
  # DEBUG BEGIN_STMT
  # DEBUG MSCMPersonality => 2

  <bb 5> [local count: 1073741824]:
  # MSCMPersonality_2 = PHI <1(2), 0(3), 2(4)>
  # DEBUG MSCMPersonality => MSCMPersonality_2
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return MSCMPersonality_2;

}


