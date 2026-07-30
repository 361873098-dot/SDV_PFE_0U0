
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  OsIf_MicrosToTicks/8:
  Jump functions of caller  OsIf_SetTimerFrequency/7:
  Jump functions of caller  OsIf_GetElapsed/6:
  Jump functions of caller  OsIf_GetCounter/5:
  Jump functions of caller  OsIf_Init/4:

 Propagating constants:

Not considering OsIf_MicrosToTicks for cloning; -fipa-cp-clone disabled.
Not considering OsIf_SetTimerFrequency for cloning; -fipa-cp-clone disabled.
Not considering OsIf_GetElapsed for cloning; -fipa-cp-clone disabled.
Not considering OsIf_GetCounter for cloning; -fipa-cp-clone disabled.
Not considering OsIf_Init for cloning; -fipa-cp-clone disabled.

overall_size: 19, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 2.000000
 - context independent values, size: 5, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: OsIf_MicrosToTicks/8:
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
  Node: OsIf_SetTimerFrequency/7:
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
  Node: OsIf_GetElapsed/6:
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
  Node: OsIf_GetCounter/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: OsIf_Init/4:
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

OsIf_MicrosToTicks/8 (OsIf_MicrosToTicks) @06e8a620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_SetTimerFrequency/7 (OsIf_SetTimerFrequency) @06e8a0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_GetElapsed/6 (OsIf_GetElapsed) @06e8ad20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_GetCounter/5 (OsIf_GetCounter) @06e8aa80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_Init/4 (OsIf_Init) @06e8a7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function OsIf_Init (OsIf_Init, funcdef_no=4, decl_uid=5628, cgraph_uid=5, symbol_order=4)

Modification phase of node OsIf_Init/4
OsIf_Init (const void * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function OsIf_GetCounter (OsIf_GetCounter, funcdef_no=5, decl_uid=5630, cgraph_uid=6, symbol_order=5)

Modification phase of node OsIf_GetCounter/5
OsIf_GetCounter (OsIf_CounterType SelectedCounter)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Value => 0
  # DEBUG BEGIN_STMT
  # DEBUG Value => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function OsIf_GetElapsed (OsIf_GetElapsed, funcdef_no=6, decl_uid=5633, cgraph_uid=7, symbol_order=6)

Modification phase of node OsIf_GetElapsed/6
OsIf_GetElapsed (uint32 * const CurrentRef, OsIf_CounterType SelectedCounter)
{
  uint32 Value;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Value => 0
  # DEBUG BEGIN_STMT
  if (SelectedCounter_2(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => CurrentRef_4(D)
  # DEBUG INLINE_ENTRY NULL
  # DEBUG CurrentRef => D#1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Value => 1
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # Value_1 = PHI <1(3), 0(2)>
  # DEBUG Value => Value_1
  # DEBUG BEGIN_STMT
  return Value_1;

}



;; Function OsIf_SetTimerFrequency (OsIf_SetTimerFrequency, funcdef_no=7, decl_uid=5636, cgraph_uid=8, symbol_order=7)

Modification phase of node OsIf_SetTimerFrequency/7
OsIf_SetTimerFrequency (uint32 Freq, OsIf_CounterType SelectedCounter)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Freq => NULL
  return;

}



;; Function OsIf_MicrosToTicks (OsIf_MicrosToTicks, funcdef_no=8, decl_uid=5639, cgraph_uid=9, symbol_order=8)

Modification phase of node OsIf_MicrosToTicks/8
OsIf_MicrosToTicks (uint32 Micros, OsIf_CounterType SelectedCounter)
{
  uint32 Value;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Value => 0
  # DEBUG BEGIN_STMT
  if (SelectedCounter_2(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG Micros => Micros_4(D)
  # DEBUG INLINE_ENTRY NULL
  # DEBUG BEGIN_STMT
  # DEBUG Micros => NULL
  # DEBUG Value => Micros_4(D)
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # Value_1 = PHI <Micros_4(D)(3), 0(2)>
  # DEBUG Value => Value_1
  # DEBUG BEGIN_STMT
  return Value_1;

}


