
IPA constant propagation start:
Determining dynamic type for call: Power_Ip_OnOffPartCoreCofb (ModeConfigPtr_3(D));
  Starting walk at: Power_Ip_OnOffPartCoreCofb (ModeConfigPtr_3(D));
  instance pointer: ModeConfigPtr_3(D)  Outer instance pointer: ModeConfigPtr_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Power_Ip_ConfigPartCoreCofbReset.isra.0 (_21, PartitionIndex_8);
  Starting walk at: Power_Ip_ConfigPartCoreCofbReset.isra.0 (_21, PartitionIndex_8);
  instance pointer: _21  Outer instance pointer: ModeConfigPtr_11(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:Power_Ip_MC_ME_ConfigCoreCOFBClock (_4, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_ME_DisablePartitionOutputSafe (_3, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_RGM_EnableResetDomain (_2, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_ME_EnablePartitionClock (_1, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_ME_EnablePartitionOutputSafe (_7, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_ME_DisablePartitionClock (_6, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_RGM_DisableResetDomain (_5, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_ConfigPartCoreCofbReset.isra.0 (_21, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_ME_ConfigCoreCOFBClock (_4, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_ME_DisablePartitionOutputSafe (_3, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_RGM_EnableResetDomain (_2, PartitionIndex_8);
  Function call may change dynamic type:Power_Ip_MC_ME_EnablePartitionClock (_1, PartitionIndex_8);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Power_Ip_ConfigPartCoreCofbReset.isra.0/25:
  Jump functions of caller  Power_Ip_PMC_PowerInit/24:
  Jump functions of caller  Power_Ip_MC_RGM_ResetInit/23:
  Jump functions of caller  Power_Ip_MC_RGM_GetResetRawValue/22:
  Jump functions of caller  Power_Ip_MC_RGM_GetResetReason/21:
  Jump functions of caller  Power_Ip_MC_RGM_CheckModeConfig/20:
  Jump functions of caller  Power_Ip_MC_RGM_ModeConfig/19:
  Jump functions of caller  Power_Ip_MC_ME_EnablePartitionOutputSafe/18:
  Jump functions of caller  Power_Ip_MC_ME_DisablePartitionClock/17:
  Jump functions of caller  Power_Ip_MC_RGM_DisableResetDomain/16:
  Jump functions of caller  Power_Ip_MC_ME_ConfigCoreCOFBClock/15:
  Jump functions of caller  Power_Ip_MC_ME_DisablePartitionOutputSafe/14:
  Jump functions of caller  Power_Ip_MC_RGM_EnableResetDomain/13:
  Jump functions of caller  Power_Ip_MC_ME_EnablePartitionClock/12:
  Jump functions of caller  Power_Ip_CortexM_WarmReset/11:
  Jump functions of caller  Power_Ip_MSCM_GetPersonality/10:
  Jump functions of caller  Power_Ip_MC_ME_SocTriggerResetEvent/9:
  Jump functions of caller  Power_Ip_ReportPowerErrorsEmptyCallback/8:
  Jump functions of caller  Power_Ip_InstallNotificationsCallback/7:
  Jump functions of caller  Power_Ip_Init/6:
  Jump functions of caller  Power_Ip_GetResetRawValue/5:
  Jump functions of caller  Power_Ip_GetResetReason/4:
  Jump functions of caller  Power_Ip_SetMode/3:
    callsite  Power_Ip_SetMode/3 -> Power_Ip_OnOffPartCoreCofb/2 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Power_Ip_OnOffPartCoreCofb/2:
    callsite  Power_Ip_OnOffPartCoreCofb/2 -> Power_Ip_ConfigPartCoreCofbReset.isra.0/25 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 4]

 Propagating constants:

Not considering Power_Ip_InstallNotificationsCallback for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_Init for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_GetResetRawValue for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_GetResetReason for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_SetMode for cloning; -fipa-cp-clone disabled.

overall_size: 88, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Power_Ip_ConfigPartCoreCofbReset.isra.0/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct Power_Ip_MC_RGM_ModeConfigType * const * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8 [0, 4]
        AGGS VARIABLE
  Node: Power_Ip_InstallNotificationsCallback/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Power_Ip_Init/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Power_Ip_GetResetRawValue/5:
  Node: Power_Ip_GetResetReason/4:
  Node: Power_Ip_SetMode/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Power_Ip_OnOffPartCoreCofb/2:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

Propagated bits info for function Power_Ip_ConfigPartCoreCofbReset.isra.0/25:
 param 1: value = 0x0, mask = 0x7

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Power_Ip_ConfigPartCoreCofbReset.isra.0/25 (Power_Ip_ConfigPartCoreCofbReset.isra.0) @0766eb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Power_Ip_OnOffPartCoreCofb/2 (858993459 (estimated locally),4.00 per call) 
  Calls: Power_Ip_MC_RGM_CheckModeConfig/20 (1073741824 (estimated locally),1.00 per call) Power_Ip_MC_RGM_ModeConfig/19 (1073741824 (estimated locally),1.00 per call) 
Power_Ip_PMC_PowerInit/24 (Power_Ip_PMC_PowerInit) @076697e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_Init/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Power_Ip_MC_RGM_ResetInit/23 (Power_Ip_MC_RGM_ResetInit) @07669700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_Init/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Power_Ip_MC_RGM_GetResetRawValue/22 (Power_Ip_MC_RGM_GetResetRawValue) @07669540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_GetResetRawValue/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Power_Ip_MC_RGM_GetResetReason/21 (Power_Ip_MC_RGM_GetResetReason) @07669380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_GetResetReason/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Power_Ip_MC_RGM_CheckModeConfig/20 (Power_Ip_MC_RGM_CheckModeConfig) @076691c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_ConfigPartCoreCofbReset.isra.0/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Power_Ip_MC_RGM_ModeConfig/19 (Power_Ip_MC_RGM_ModeConfig) @076690e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_ConfigPartCoreCofbReset.isra.0/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Power_Ip_MC_ME_EnablePartitionOutputSafe/18 (Power_Ip_MC_ME_EnablePartitionOutputSafe) @07664000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_OnOffPartCoreCofb/2 (858993459 (estimated locally),4.00 per call) 
  Calls: 
Power_Ip_MC_ME_DisablePartitionClock/17 (Power_Ip_MC_ME_DisablePartitionClock) @07664ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_OnOffPartCoreCofb/2 (858993459 (estimated locally),4.00 per call) 
  Calls: 
Power_Ip_MC_RGM_DisableResetDomain/16 (Power_Ip_MC_RGM_DisableResetDomain) @07664e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_OnOffPartCoreCofb/2 (858993459 (estimated locally),4.00 per call) 
  Calls: 
Power_Ip_MC_ME_ConfigCoreCOFBClock/15 (Power_Ip_MC_ME_ConfigCoreCOFBClock) @07664d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_OnOffPartCoreCofb/2 (858993459 (estimated locally),4.00 per call) 
  Calls: 
Power_Ip_MC_ME_DisablePartitionOutputSafe/14 (Power_Ip_MC_ME_DisablePartitionOutputSafe) @07664c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_OnOffPartCoreCofb/2 (858993459 (estimated locally),4.00 per call) 
  Calls: 
Power_Ip_MC_RGM_EnableResetDomain/13 (Power_Ip_MC_RGM_EnableResetDomain) @07664b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_OnOffPartCoreCofb/2 (858993459 (estimated locally),4.00 per call) 
  Calls: 
Power_Ip_MC_ME_EnablePartitionClock/12 (Power_Ip_MC_ME_EnablePartitionClock) @07664a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_OnOffPartCoreCofb/2 (858993459 (estimated locally),4.00 per call) 
  Calls: 
Power_Ip_CortexM_WarmReset/11 (Power_Ip_CortexM_WarmReset) @076648c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_SetMode/3 (32770054 (estimated locally),0.03 per call) 
  Calls: 
Power_Ip_MSCM_GetPersonality/10 (Power_Ip_MSCM_GetPersonality) @076647e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_SetMode/3 (161907382 (estimated locally),0.15 per call) 
  Calls: 
Power_Ip_MC_ME_SocTriggerResetEvent/9 (Power_Ip_MC_ME_SocTriggerResetEvent) @07664700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_SetMode/3 (273804165 (estimated locally),0.25 per call) 
  Calls: 
Power_Ip_ReportPowerErrorsEmptyCallback/8 (Power_Ip_ReportPowerErrorsEmptyCallback) @076642a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: Power_Ip_pfReportErrorsCallback/0 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
Power_Ip_InstallNotificationsCallback/7 (Power_Ip_InstallNotificationsCallback) @076641c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Power_Ip_pfReportErrorsCallback/0 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Power_Ip_Init/6 (Power_Ip_Init) @07704d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_PMC_PowerInit/24 (1073741824 (estimated locally),1.00 per call) Power_Ip_MC_RGM_ResetInit/23 (1073741824 (estimated locally),1.00 per call) 
Power_Ip_GetResetRawValue/5 (Power_Ip_GetResetRawValue) @077047e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_GetResetRawValue/22 (1073741824 (estimated locally),1.00 per call) 
Power_Ip_GetResetReason/4 (Power_Ip_GetResetReason) @07704ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_GetResetReason/21 (1073741824 (estimated locally),1.00 per call) 
Power_Ip_SetMode/3 (Power_Ip_SetMode) @07704c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_CortexM_WarmReset/11 (32770054 (estimated locally),0.03 per call) Power_Ip_MSCM_GetPersonality/10 (161907382 (estimated locally),0.15 per call) Power_Ip_MC_ME_SocTriggerResetEvent/9 (273804165 (estimated locally),0.25 per call) Power_Ip_OnOffPartCoreCofb/2 (1073741824 (estimated locally),1.00 per call) 
Power_Ip_OnOffPartCoreCofb/2 (Power_Ip_OnOffPartCoreCofb) @077049a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748364 (estimated locally) body local optimize_size
  Called by: Power_Ip_SetMode/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: Power_Ip_MC_ME_EnablePartitionOutputSafe/18 (858993459 (estimated locally),4.00 per call) Power_Ip_MC_ME_DisablePartitionClock/17 (858993459 (estimated locally),4.00 per call) Power_Ip_MC_RGM_DisableResetDomain/16 (858993459 (estimated locally),4.00 per call) Power_Ip_ConfigPartCoreCofbReset.isra.0/25 (858993459 (estimated locally),4.00 per call) Power_Ip_MC_ME_ConfigCoreCOFBClock/15 (858993459 (estimated locally),4.00 per call) Power_Ip_MC_ME_DisablePartitionOutputSafe/14 (858993459 (estimated locally),4.00 per call) Power_Ip_MC_RGM_EnableResetDomain/13 (858993459 (estimated locally),4.00 per call) Power_Ip_MC_ME_EnablePartitionClock/12 (858993459 (estimated locally),4.00 per call) 
Power_Ip_pfReportErrorsCallback/0 (Power_Ip_pfReportErrorsCallback) @07703510
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Power_Ip_ReportPowerErrorsEmptyCallback/8 (addr)
  Referring: Power_Ip_InstallNotificationsCallback/7 (write)
  Availability: available
  Varpool flags: initialized

;; Function Power_Ip_SetMode (Power_Ip_SetMode, funcdef_no=2, decl_uid=6523, cgraph_uid=3, symbol_order=3)

Modification phase of node Power_Ip_SetMode/3
Power_Ip_SetMode (const struct Power_Ip_ModeConfigType * ModeConfigPtr)
{
  Power_Ip_MSCM_CpxType McuCpxType;
  Power_Ip_PowerModeType PowerMode;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  PowerMode_4 = ModeConfigPtr_3(D)->PowerMode;
  # DEBUG PowerMode => PowerMode_4
  # DEBUG BEGIN_STMT
  Power_Ip_OnOffPartCoreCofb (ModeConfigPtr_3(D));
  # DEBUG BEGIN_STMT
  if (PowerMode_4 <= 1)
    goto <bb 3>; [25.50%]
  else
    goto <bb 4>; [74.50%]

  <bb 3> [local count: 273804165]:
  # DEBUG BEGIN_STMT
  Power_Ip_MC_ME_SocTriggerResetEvent (PowerMode_4);
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 799937660]:
  # DEBUG BEGIN_STMT
  if (PowerMode_4 == 3)
    goto <bb 5>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 5> [local count: 161907382]:
  # DEBUG BEGIN_STMT
  McuCpxType_7 = Power_Ip_MSCM_GetPersonality ();
  # DEBUG McuCpxType => McuCpxType_7
  # DEBUG BEGIN_STMT
  if (McuCpxType_7 == 2)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 32770054]:
<L3>:
  # DEBUG BEGIN_STMT
  Power_Ip_CortexM_WarmReset ();
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Power_Ip_GetResetReason (Power_Ip_GetResetReason, funcdef_no=3, decl_uid=6525, cgraph_uid=4, symbol_order=4)

Modification phase of node Power_Ip_GetResetReason/4
Power_Ip_GetResetReason ()
{
  Power_Ip_ResetType ResetReason;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ResetReason => 28
  # DEBUG BEGIN_STMT
  ResetReason_3 = Power_Ip_MC_RGM_GetResetReason ();
  # DEBUG ResetReason => ResetReason_3
  # DEBUG BEGIN_STMT
  return ResetReason_3;

}



;; Function Power_Ip_GetResetRawValue (Power_Ip_GetResetRawValue, funcdef_no=4, decl_uid=6527, cgraph_uid=5, symbol_order=5)

Modification phase of node Power_Ip_GetResetRawValue/5
Power_Ip_GetResetRawValue ()
{
  Power_Ip_RawResetType ResetReason;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ResetReason_3 = Power_Ip_MC_RGM_GetResetRawValue ();
  # DEBUG ResetReason => ResetReason_3
  # DEBUG BEGIN_STMT
  return ResetReason_3;

}



;; Function Power_Ip_Init (Power_Ip_Init, funcdef_no=5, decl_uid=6521, cgraph_uid=6, symbol_order=6)

Modification phase of node Power_Ip_Init/6
Power_Ip_Init (const struct Power_Ip_HwIPsConfigType * HwIPsConfigPtr)
{
  const struct Power_Ip_MC_RGM_ConfigType * _1;
  const struct Power_Ip_PMC_ConfigType * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = HwIPsConfigPtr_4(D)->McRgmConfigPtr;
  Power_Ip_MC_RGM_ResetInit (_1);
  # DEBUG BEGIN_STMT
  _2 = HwIPsConfigPtr_4(D)->PMCConfigPtr;
  Power_Ip_PMC_PowerInit (_2);
  return;

}



;; Function Power_Ip_InstallNotificationsCallback (Power_Ip_InstallNotificationsCallback, funcdef_no=6, decl_uid=6529, cgraph_uid=7, symbol_order=7)

Modification phase of node Power_Ip_InstallNotificationsCallback/7
Power_Ip_InstallNotificationsCallback (void (*Power_Ip_ReportErrorsCallbackType) (Power_Ip_ReportErrorType, uint8) ReportErrorsCallback)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Power_Ip_pfReportErrorsCallback = ReportErrorsCallback_2(D);
  return;

}


