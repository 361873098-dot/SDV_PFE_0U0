
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_ReportClockErrors/16:
  Jump functions of caller  Clock_Ip_TimeoutExpired/15:
  Jump functions of caller  Clock_Ip_StartTimeout/14:
  Jump functions of caller  Clock_Ip_EnablePlldigRdivMfiMfnSdmen/10:
  Jump functions of caller  Clock_Ip_CompletePlldigRdivMfiMfnSdmen/9:
  Jump functions of caller  Clock_Ip_SetPlldigRdivMfiMfnSdmen/8:
  Jump functions of caller  Clock_Ip_ResetPlldigRdivMfiMfnSdmen/7:
  Jump functions of caller  Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/6:
  Jump functions of caller  Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5:
  Jump functions of caller  Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/4:
  Jump functions of caller  Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/3:
  Jump functions of caller  Clock_Ip_CallbackPllEmptyDisable/2:
  Jump functions of caller  Clock_Ip_CallbackPllEmptyComplete/1:
  Jump functions of caller  Clock_Ip_CallbackPllEmpty/0:

 Propagating constants:

Function Clock_Ip_EnablePlldigRdivMfiMfnSdmen/10 is not versionable, reason: not a tree_versionable_function.
Function Clock_Ip_CompletePlldigRdivMfiMfnSdmen/9 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_SetPlldigRdivMfiMfnSdmen for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_ResetPlldigRdivMfiMfnSdmen/7 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_CallbackPllEmptyDisable for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_CallbackPllEmptyComplete for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_CallbackPllEmpty for cloning; -fipa-cp-clone disabled.

overall_size: 162, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_EnablePlldigRdivMfiMfnSdmen/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_CompletePlldigRdivMfiMfnSdmen/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetPlldigRdivMfiMfnSdmen/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetPlldigRdivMfiMfnSdmen/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_CallbackPllEmptyDisable/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_CallbackPllEmptyComplete/1:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_CallbackPllEmpty/0:
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

Clock_Ip_ReportClockErrors/16 (Clock_Ip_ReportClockErrors) @07273540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5 (54870309 (estimated locally),0.20 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/15 (Clock_Ip_TimeoutExpired) @07273460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5 (1073741824 (estimated locally),3.88 per call) 
  Calls: 
Clock_Ip_StartTimeout/14 (Clock_Ip_StartTimeout) @07273380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5 (114863532 (estimated locally),0.41 per call) 
  Calls: 
Clock_Ip_pxPll/13 (Clock_Ip_pxPll) @07272438
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/6 (read)Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5 (read)Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/4 (read)Clock_Ip_SetPlldigRdivMfiMfnSdmen/8 (read)Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/3 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8ClockFeatures/12 (Clock_Ip_au8ClockFeatures) @072723f0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5 (read)Clock_Ip_SetPlldigRdivMfiMfnSdmen/8 (read)Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/6 (read)Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/4 (read)Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/3 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axPllCallbacks/11 (Clock_Ip_axPllCallbacks) @07272048
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_CallbackPllEmpty/0 (addr)Clock_Ip_CallbackPllEmpty/0 (addr)Clock_Ip_CallbackPllEmptyComplete/1 (addr)Clock_Ip_CallbackPllEmpty/0 (addr)Clock_Ip_CallbackPllEmptyDisable/2 (addr)Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/3 (addr)Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/4 (addr)Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5 (addr)Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/6 (addr)Clock_Ip_CallbackPllEmptyDisable/2 (addr)Clock_Ip_ResetPlldigRdivMfiMfnSdmen/7 (addr)Clock_Ip_SetPlldigRdivMfiMfnSdmen/8 (addr)Clock_Ip_CompletePlldigRdivMfiMfnSdmen/9 (addr)Clock_Ip_EnablePlldigRdivMfiMfnSdmen/10 (addr)Clock_Ip_CallbackPllEmptyDisable/2 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_EnablePlldigRdivMfiMfnSdmen/10 (Clock_Ip_EnablePlldigRdivMfiMfnSdmen) @0722b380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/6 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_CompletePlldigRdivMfiMfnSdmen/9 (Clock_Ip_CompletePlldigRdivMfiMfnSdmen) @0722bee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:276913048 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5 (276913048 (estimated locally),1.00 per call) 
Clock_Ip_SetPlldigRdivMfiMfnSdmen/8 (Clock_Ip_SetPlldigRdivMfiMfnSdmen) @0722bc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/12 (read)Clock_Ip_pxPll/13 (read)
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ResetPlldigRdivMfiMfnSdmen/7 (Clock_Ip_ResetPlldigRdivMfiMfnSdmen) @0722b540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/3 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/6 (Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize) @0722b2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/12 (read)Clock_Ip_pxPll/13 (read)
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_EnablePlldigRdivMfiMfnSdmen/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5 (Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize) @0722b000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/12 (read)Clock_Ip_pxPll/13 (read)
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:276913048 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_CompletePlldigRdivMfiMfnSdmen/9 (276913048 (estimated locally),1.00 per call) 
  Calls: Clock_Ip_ReportClockErrors/16 (54870309 (estimated locally),0.20 per call) Clock_Ip_TimeoutExpired/15 (1073741824 (estimated locally),3.88 per call) Clock_Ip_StartTimeout/14 (114863532 (estimated locally),0.41 per call) 
Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/4 (Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize) @07224540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/12 (read)Clock_Ip_pxPll/13 (read)
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/3 (Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize) @07224700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/12 (read)Clock_Ip_pxPll/13 (read)
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_ResetPlldigRdivMfiMfnSdmen/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_CallbackPllEmptyDisable/2 (Clock_Ip_CallbackPllEmptyDisable) @07224460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axPllCallbacks/11 (addr)Clock_Ip_axPllCallbacks/11 (addr)Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_CallbackPllEmptyComplete/1 (Clock_Ip_CallbackPllEmptyComplete) @072241c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_CallbackPllEmpty/0 (Clock_Ip_CallbackPllEmpty) @0725ee00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axPllCallbacks/11 (addr)Clock_Ip_axPllCallbacks/11 (addr)Clock_Ip_axPllCallbacks/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Clock_Ip_CallbackPllEmpty (Clock_Ip_CallbackPllEmpty, funcdef_no=0, decl_uid=6784, cgraph_uid=1, symbol_order=0)

Modification phase of node Clock_Ip_CallbackPllEmpty/0
Clock_Ip_CallbackPllEmpty (const struct Clock_Ip_PllConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_CallbackPllEmptyComplete (Clock_Ip_CallbackPllEmptyComplete, funcdef_no=1, decl_uid=6786, cgraph_uid=2, symbol_order=1)

Modification phase of node Clock_Ip_CallbackPllEmptyComplete/1
Clock_Ip_CallbackPllEmptyComplete (Clock_Ip_NameType PllName)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Clock_Ip_CallbackPllEmptyDisable (Clock_Ip_CallbackPllEmptyDisable, funcdef_no=2, decl_uid=6788, cgraph_uid=3, symbol_order=2)

Modification phase of node Clock_Ip_CallbackPllEmptyDisable/2
Clock_Ip_CallbackPllEmptyDisable (Clock_Ip_NameType PllName)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize, funcdef_no=3, decl_uid=6790, cgraph_uid=4, symbol_order=3)

Modification phase of node Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/3
Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (const struct Clock_Ip_PllConfigType * Config)
{
  uint32 Instance;
  <unnamed type> _1;
  unsigned char _2;
  struct PLLDIG_Type * _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_7(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = Config_7(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_9 = (uint32) _2;
  # DEBUG Instance => Instance_9
  # DEBUG BEGIN_STMT
  _3 = Clock_Ip_pxPll[Instance_9];
  _4 ={v} _3->PLLCR;
  _5 = _4 | 2147483648;
  _3->PLLCR ={v} _5;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize, funcdef_no=4, decl_uid=6792, cgraph_uid=5, symbol_order=4)

Modification phase of node Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/4
Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (const struct Clock_Ip_PllConfigType * Config)
{
  uint32 Value;
  uint32 Instance;
  <unnamed type> _1;
  unsigned char _2;
  short unsigned int _3;
  <unnamed type> _4;
  struct PLLDIG_Type * _5;
  long unsigned int _6;
  unsigned char _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned char _11;
  long unsigned int _12;
  long unsigned int _13;
  short unsigned int _14;
  long unsigned int _15;
  unsigned char _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  unsigned char _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  unsigned char _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  short unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  short unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  short unsigned int _52;
  short unsigned int _53;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_37(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619277]:
  # DEBUG BEGIN_STMT
  _1 = Config_37(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_39 = (uint32) _2;
  # DEBUG Instance => Instance_39
  # DEBUG BEGIN_STMT
  _3 = Config_37(D)->Enable;
  if (_3 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _4 = Config_37(D)->InputReference;
  _5 = Clock_Ip_pxPll[Instance_39];
  _6 = _4 & 1;
  _5->PLLCLKMUX ={v} _6;
  # DEBUG BEGIN_STMT
  Value_41 ={v} _5->PLLDV;
  # DEBUG Value => Value_41
  # DEBUG BEGIN_STMT
  Value_42 = Value_41 & 4294938368;
  # DEBUG Value => Value_42
  # DEBUG BEGIN_STMT
  _7 = Config_37(D)->Predivider;
  _8 = (long unsigned int) _7;
  _9 = _8 << 12;
  _10 = _9 & 28672;
  _11 = Config_37(D)->MulFactorDiv;
  _12 = (long unsigned int) _11;
  _13 = _10 | _12;
  Value_43 = _13 | Value_42;
  # DEBUG Value => Value_43
  # DEBUG BEGIN_STMT
  _5->PLLDV ={v} Value_43;
  # DEBUG BEGIN_STMT
  Value_45 ={v} _5->PLLFD;
  # DEBUG Value => Value_45
  # DEBUG BEGIN_STMT
  Value_46 = Value_45 & 3221192704;
  # DEBUG Value => Value_46
  # DEBUG BEGIN_STMT
  _14 = Config_37(D)->NumeratorFracLoopDiv;
  _52 = _14 & 32767;
  _15 = (long unsigned int) _52;
  Value_47 = _15 | Value_46;
  # DEBUG Value => Value_47
  # DEBUG BEGIN_STMT
  _16 = Config_37(D)->SigmaDelta;
  _17 = (long unsigned int) _16;
  _18 = _17 << 30;
  _19 = _18 & 1073741824;
  Value_48 = _19 | Value_47;
  # DEBUG Value => Value_48
  # DEBUG BEGIN_STMT
  _5->PLLFD ={v} Value_48;
  # DEBUG BEGIN_STMT
  _20 = Config_37(D)->FrequencyModulationBypass;
  _21 = (long unsigned int) _20;
  _22 = _21 << 30;
  _23 = _22 & 1073741824;
  _24 = Config_37(D)->ModulationType;
  _25 = (long unsigned int) _24;
  _26 = _25 << 29;
  _27 = _26 & 536870912;
  _28 = _23 | _27;
  _29 = Config_37(D)->IncrementStep;
  _53 = _29 & 2047;
  _30 = (long unsigned int) _53;
  _31 = _28 | _30;
  _32 = Config_37(D)->ModulationPeriod;
  _33 = (long unsigned int) _32;
  _34 = _33 << 16;
  _35 = _34 & 67043328;
  Value_50 = _31 | _35;
  # DEBUG Value => Value_50
  # DEBUG BEGIN_STMT
  _5->PLLFM ={v} Value_50;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize, funcdef_no=6, decl_uid=6796, cgraph_uid=7, symbol_order=6)

Modification phase of node Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/6
Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (const struct Clock_Ip_PllConfigType * Config)
{
  uint32 Instance;
  <unnamed type> _1;
  unsigned char _2;
  short unsigned int _3;
  struct PLLDIG_Type * _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_8(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = Config_8(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_10 = (uint32) _2;
  # DEBUG Instance => Instance_10
  # DEBUG BEGIN_STMT
  _3 = Config_8(D)->Enable;
  if (_3 == 1)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 255550554]:
  # DEBUG BEGIN_STMT
  _4 = Clock_Ip_pxPll[Instance_10];
  _5 ={v} _4->PLLCR;
  _6 = _5 & 2147483647;
  _4->PLLCR ={v} _6;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_ResetPlldigRdivMfiMfnSdmen (Clock_Ip_ResetPlldigRdivMfiMfnSdmen, funcdef_no=12, decl_uid=6798, cgraph_uid=8, symbol_order=7)

Modification phase of node Clock_Ip_ResetPlldigRdivMfiMfnSdmen/7
Clock_Ip_ResetPlldigRdivMfiMfnSdmen (const struct Clock_Ip_PllConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (Config_2(D)); [tail call]
  return;

}



;; Function Clock_Ip_SetPlldigRdivMfiMfnSdmen (Clock_Ip_SetPlldigRdivMfiMfnSdmen, funcdef_no=8, decl_uid=6800, cgraph_uid=9, symbol_order=8)

Modification phase of node Clock_Ip_SetPlldigRdivMfiMfnSdmen/8
Clock_Ip_SetPlldigRdivMfiMfnSdmen (const struct Clock_Ip_PllConfigType * Config)
{
  uint32 Value;
  uint32 Instance;
  <unnamed type> _1;
  unsigned char _2;
  short unsigned int _3;
  <unnamed type> _4;
  struct PLLDIG_Type * _5;
  long unsigned int _6;
  unsigned char _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned char _11;
  long unsigned int _12;
  long unsigned int _13;
  short unsigned int _14;
  long unsigned int _15;
  unsigned char _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  short unsigned int _34;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_21(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619277]:
  # DEBUG BEGIN_STMT
  _1 = Config_21(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_23 = (uint32) _2;
  # DEBUG Instance => Instance_23
  # DEBUG BEGIN_STMT
  _3 = Config_21(D)->Enable;
  if (_3 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _4 = Config_21(D)->InputReference;
  _5 = Clock_Ip_pxPll[Instance_23];
  _6 = _4 & 1;
  _5->PLLCLKMUX ={v} _6;
  # DEBUG BEGIN_STMT
  Value_25 ={v} _5->PLLDV;
  # DEBUG Value => Value_25
  # DEBUG BEGIN_STMT
  Value_26 = Value_25 & 4294938368;
  # DEBUG Value => Value_26
  # DEBUG BEGIN_STMT
  _7 = Config_21(D)->Predivider;
  _8 = (long unsigned int) _7;
  _9 = _8 << 12;
  _10 = _9 & 28672;
  _11 = Config_21(D)->MulFactorDiv;
  _12 = (long unsigned int) _11;
  _13 = _10 | _12;
  Value_27 = _13 | Value_26;
  # DEBUG Value => Value_27
  # DEBUG BEGIN_STMT
  _5->PLLDV ={v} Value_27;
  # DEBUG BEGIN_STMT
  Value_29 ={v} _5->PLLFD;
  # DEBUG Value => Value_29
  # DEBUG BEGIN_STMT
  Value_30 = Value_29 & 3221192704;
  # DEBUG Value => Value_30
  # DEBUG BEGIN_STMT
  _14 = Config_21(D)->NumeratorFracLoopDiv;
  _34 = _14 & 32767;
  _15 = (long unsigned int) _34;
  Value_31 = _15 | Value_30;
  # DEBUG Value => Value_31
  # DEBUG BEGIN_STMT
  _16 = Config_21(D)->SigmaDelta;
  _17 = (long unsigned int) _16;
  _18 = _17 << 30;
  _19 = _18 & 1073741824;
  Value_32 = _19 | Value_31;
  # DEBUG Value => Value_32
  # DEBUG BEGIN_STMT
  _5->PLLFD ={v} Value_32;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_EnablePlldigRdivMfiMfnSdmen (Clock_Ip_EnablePlldigRdivMfiMfnSdmen, funcdef_no=16, decl_uid=6804, cgraph_uid=11, symbol_order=10)

Modification phase of node Clock_Ip_EnablePlldigRdivMfiMfnSdmen/10
Clock_Ip_EnablePlldigRdivMfiMfnSdmen (const struct Clock_Ip_PllConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (Config_2(D)); [tail call]
  return;

}



;; Function Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize, funcdef_no=5, decl_uid=6794, cgraph_uid=6, symbol_order=5)

Modification phase of node Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize/5
Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (Clock_Ip_NameType PllName)
{
  uint32 Instance;
  uint32 PllLockStatus;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  Clock_Ip_PllStatusReturnType PllStatus;
  unsigned char _1;
  struct PLLDIG_Type * _2;
  long unsigned int _3;
  signed int _4;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int TimeoutTicks.1_8;

  <bb 2> [local count: 276913048]:
  # DEBUG BEGIN_STMT
  # DEBUG PllStatus => 2
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_au8ClockFeatures[PllName_13(D)][0];
  Instance_14 = (uint32) _1;
  # DEBUG Instance => Instance_14
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_pxPll[Instance_14];
  _3 ={v} _2->PLLCR;
  _4 = (signed int) _3;
  if (_4 >= 0)
    goto <bb 3>; [41.48%]
  else
    goto <bb 8>; [58.52%]

  <bb 3> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 ={v} _2->PLLSR;
  _7 = _6 >> 2;
  PllLockStatus_16 = _7 & 1;
  # DEBUG PllLockStatus => PllLockStatus_16
  # DEBUG BEGIN_STMT
  TimeoutTicks.1_8 = TimeoutTicks;
  TimeoutOccurred_18 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.1_8);
  # DEBUG TimeoutOccurred => TimeoutOccurred_18
  # DEBUG BEGIN_STMT
  if (PllLockStatus_16 == 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686024]:
  if (TimeoutOccurred_18 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 9> [local count: 958878294]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 114863532]:
  # TimeoutOccurred_5 = PHI <TimeoutOccurred_18(4), TimeoutOccurred_18(5)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_5 != 0)
    goto <bb 7>; [47.77%]
  else
    goto <bb 8>; [52.23%]

  <bb 7> [local count: 54870309]:
  # DEBUG BEGIN_STMT
  # DEBUG PllStatus => 1
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (1, PllName_13(D));

  <bb 8> [local count: 276913047]:
  # PllStatus_9 = PHI <1(7), 0(2), 2(6)>
  # DEBUG PllStatus => PllStatus_9
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return PllStatus_9;

}



;; Function Clock_Ip_CompletePlldigRdivMfiMfnSdmen (Clock_Ip_CompletePlldigRdivMfiMfnSdmen, funcdef_no=14, decl_uid=6802, cgraph_uid=10, symbol_order=9)

Modification phase of node Clock_Ip_CompletePlldigRdivMfiMfnSdmen/9
Clock_Ip_CompletePlldigRdivMfiMfnSdmen (Clock_Ip_NameType PllName)
{
  Clock_Ip_PllStatusReturnType retval.13;

  <bb 2> [local count: 276913048]:
  retval.13_4 = Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize (PllName_2(D)); [tail call]
  return retval.13_4;

}


