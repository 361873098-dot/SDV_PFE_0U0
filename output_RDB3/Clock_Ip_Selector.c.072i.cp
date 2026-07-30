
IPA constant propagation start:
Determining dynamic type for call: Clock_Ip_SetRtcRtccClksel_TrustedCall (Config_2(D));
  Starting walk at: Clock_Ip_SetRtcRtccClksel_TrustedCall (Config_2(D));
  instance pointer: Config_2(D)  Outer instance pointer: Config_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Clock_Ip_ConfigureSetGenCtrl1 (Config_2(D));
  Starting walk at: Clock_Ip_ConfigureSetGenCtrl1 (Config_2(D));
  instance pointer: Config_2(D)  Outer instance pointer: Config_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Clock_Ip_ConfigureResetGenCtrl1 (Config_2(D));
  Starting walk at: Clock_Ip_ConfigureResetGenCtrl1 (Config_2(D));
  instance pointer: Config_2(D)  Outer instance pointer: Config_2(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_ReportClockErrors/21:
  Jump functions of caller  Clock_Ip_TimeoutExpired/20:
  Jump functions of caller  Clock_Ip_StartTimeout/19:
  Jump functions of caller  Clock_Ip_SetRtcRtccClksel_TrustedCall/12:
  Jump functions of caller  Clock_Ip_ConfigureSetGenCtrl1/11:
  Jump functions of caller  Clock_Ip_ConfigureResetGenCtrl1/10:
  Jump functions of caller  Clock_Ip_SetRtcRtccClksel/9:
    callsite  Clock_Ip_SetRtcRtccClksel/9 -> Clock_Ip_SetRtcRtccClksel_TrustedCall/12 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Clock_Ip_SetGenctrl1Ctrl/8:
    callsite  Clock_Ip_SetGenctrl1Ctrl/8 -> Clock_Ip_ConfigureSetGenCtrl1/11 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Clock_Ip_ResetGenctrl1Ctrl/7:
    callsite  Clock_Ip_ResetGenctrl1Ctrl/7 -> Clock_Ip_ConfigureResetGenCtrl1/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Clock_Ip_SetCgmXCscCssCsGrip/6:
  Jump functions of caller  Clock_Ip_ResetCgmXCscCssCsGrip/5:
  Jump functions of caller  Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4:
  Jump functions of caller  Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3:
  Jump functions of caller  Clock_Ip_SetCgmXCscCssClkswSwip/2:
  Jump functions of caller  Clock_Ip_ResetCgmXCscCssClkswSwip/1:
  Jump functions of caller  Clock_Ip_CallbackSelectorEmpty/0:

 Propagating constants:

Not considering Clock_Ip_SetRtcRtccClksel_TrustedCall for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ConfigureSetGenCtrl1 for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ConfigureResetGenCtrl1 for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetRtcRtccClksel for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetGenctrl1Ctrl for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ResetGenctrl1Ctrl for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetCgmXCscCssCsGrip for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_ResetCgmXCscCssCsGrip/5 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_SetCgmXCscCssClkswSwip for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ResetCgmXCscCssClkswSwip for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_CallbackSelectorEmpty for cloning; -fipa-cp-clone disabled.

overall_size: 376, max_new_size: 11001
 - context independent values, size: 2, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_SetRtcRtccClksel_TrustedCall/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ConfigureSetGenCtrl1/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ConfigureResetGenCtrl1/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetRtcRtccClksel/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetGenctrl1Ctrl/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetGenctrl1Ctrl/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetCgmXCscCssCsGrip/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetCgmXCscCssCsGrip/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetCgmXCscCssClkswSwip/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ResetCgmXCscCssClkswSwip/1:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_CallbackSelectorEmpty/0:
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

Clock_Ip_ReportClockErrors/21 (Clock_Ip_ReportClockErrors) @0727e460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_SetCgmXCscCssClkswSwip/2 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (28715883 (estimated locally),0.09 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (9476241 (estimated locally),0.03 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (9404337 (estimated locally),0.03 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (28715883 (estimated locally),0.09 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (9476241 (estimated locally),0.03 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (9404337 (estimated locally),0.03 per call) Clock_Ip_SetCgmXCscCssCsGrip/6 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssCsGrip/6 (18952483 (estimated locally),0.06 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/20 (Clock_Ip_TimeoutExpired) @0727e380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_SetCgmXCscCssClkswSwip/2 (268435455 (estimated locally),0.80 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (536870911 (estimated locally),1.60 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (1073741824 (estimated locally),3.20 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (268435455 (estimated locally),0.80 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (536870911 (estimated locally),1.60 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (1073741824 (estimated locally),3.20 per call) Clock_Ip_SetCgmXCscCssCsGrip/6 (536870911 (estimated locally),1.60 per call) Clock_Ip_SetCgmXCscCssCsGrip/6 (1073741824 (estimated locally),3.20 per call) 
  Calls: 
Clock_Ip_StartTimeout/19 (Clock_Ip_StartTimeout) @0727e2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_SetCgmXCscCssClkswSwip/2 (28715883 (estimated locally),0.09 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssClkswSwip/2 (114863532 (estimated locally),0.34 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (28715883 (estimated locally),0.09 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (114863532 (estimated locally),0.34 per call) Clock_Ip_SetCgmXCscCssCsGrip/6 (57431766 (estimated locally),0.17 per call) Clock_Ip_SetCgmXCscCssCsGrip/6 (114863532 (estimated locally),0.34 per call) 
  Calls: 
Clock_Ip_apxCgm/18 (Clock_Ip_apxCgm) @073d42d0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssCsGrip/6 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axFeatureExtensions/17 (Clock_Ip_axFeatureExtensions) @073d4288
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCgmXCscCssCsGrip/6 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssCsGrip/6 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au16SelectorEntryRtcHardwareValue/16 (Clock_Ip_au16SelectorEntryRtcHardwareValue) @07276798
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetRtcRtccClksel_TrustedCall/12 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au16SelectorEntryHardwareValue/15 (Clock_Ip_au16SelectorEntryHardwareValue) @07276678
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssCsGrip/6 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_ConfigureSetGenCtrl1/11 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8ClockFeatures/14 (Clock_Ip_au8ClockFeatures) @07276480
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_SetCgmXCscCssCsGrip/6 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (read)Clock_Ip_SetCgmXCscCssCsGrip/6 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_SetCgmXCscCssClkswSwip/2 (read)Clock_Ip_ConfigureSetGenCtrl1/11 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (read)Clock_Ip_ConfigureResetGenCtrl1/10 (read)Clock_Ip_SetCgmXCscCssCsGrip/6 (read)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axSelectorCallbacks/13 (Clock_Ip_axSelectorCallbacks) @072761b0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_CallbackSelectorEmpty/0 (addr)Clock_Ip_CallbackSelectorEmpty/0 (addr)Clock_Ip_ResetCgmXCscCssClkswSwip/1 (addr)Clock_Ip_SetCgmXCscCssClkswSwip/2 (addr)Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3 (addr)Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (addr)Clock_Ip_ResetCgmXCscCssCsGrip/5 (addr)Clock_Ip_SetCgmXCscCssCsGrip/6 (addr)Clock_Ip_ResetGenctrl1Ctrl/7 (addr)Clock_Ip_SetGenctrl1Ctrl/8 (addr)Clock_Ip_CallbackSelectorEmpty/0 (addr)Clock_Ip_SetRtcRtccClksel/9 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_SetRtcRtccClksel_TrustedCall/12 (Clock_Ip_SetRtcRtccClksel_TrustedCall) @07277a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_au16SelectorEntryRtcHardwareValue/16 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_SetRtcRtccClksel/9 (574129754 (estimated locally),0.53 per call) 
  Calls: 
Clock_Ip_ConfigureSetGenCtrl1/11 (Clock_Ip_ConfigureSetGenCtrl1) @07277700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au16SelectorEntryHardwareValue/15 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_SetGenctrl1Ctrl/8 (574129754 (estimated locally),0.53 per call) 
  Calls: 
Clock_Ip_ConfigureResetGenCtrl1/10 (Clock_Ip_ConfigureResetGenCtrl1) @07277460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_au8ClockFeatures/14 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_ResetGenctrl1Ctrl/7 (574129754 (estimated locally),0.53 per call) 
  Calls: 
Clock_Ip_SetRtcRtccClksel/9 (Clock_Ip_SetRtcRtccClksel) @072771c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_SetRtcRtccClksel_TrustedCall/12 (574129754 (estimated locally),0.53 per call) 
Clock_Ip_SetGenctrl1Ctrl/8 (Clock_Ip_SetGenctrl1Ctrl) @07207d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ConfigureSetGenCtrl1/11 (574129754 (estimated locally),0.53 per call) 
Clock_Ip_ResetGenctrl1Ctrl/7 (Clock_Ip_ResetGenctrl1Ctrl) @072077e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ConfigureResetGenCtrl1/10 (574129754 (estimated locally),0.53 per call) 
Clock_Ip_SetCgmXCscCssCsGrip/6 (Clock_Ip_SetCgmXCscCssCsGrip) @072072a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au16SelectorEntryHardwareValue/15 (read)Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_axFeatureExtensions/17 (read)Clock_Ip_axFeatureExtensions/17 (read)Clock_Ip_apxCgm/18 (read)
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:335701228 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/21 (57431766 (estimated locally),0.17 per call) Clock_Ip_ReportClockErrors/21 (18952483 (estimated locally),0.06 per call) Clock_Ip_TimeoutExpired/20 (536870911 (estimated locally),1.60 per call) Clock_Ip_StartTimeout/19 (57431766 (estimated locally),0.17 per call) Clock_Ip_TimeoutExpired/20 (1073741824 (estimated locally),3.20 per call) Clock_Ip_StartTimeout/19 (114863532 (estimated locally),0.34 per call) 
Clock_Ip_ResetCgmXCscCssCsGrip/5 (Clock_Ip_ResetCgmXCscCssCsGrip) @07207ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_CallbackSelectorEmpty/0 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4 (Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip) @07207c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au16SelectorEntryHardwareValue/15 (read)Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_axFeatureExtensions/17 (read)Clock_Ip_axFeatureExtensions/17 (read)Clock_Ip_apxCgm/18 (read)
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:335701228 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/21 (57431766 (estimated locally),0.17 per call) Clock_Ip_ReportClockErrors/21 (28715883 (estimated locally),0.09 per call) Clock_Ip_ReportClockErrors/21 (9476241 (estimated locally),0.03 per call) Clock_Ip_ReportClockErrors/21 (9404337 (estimated locally),0.03 per call) Clock_Ip_TimeoutExpired/20 (268435455 (estimated locally),0.80 per call) Clock_Ip_StartTimeout/19 (28715883 (estimated locally),0.09 per call) Clock_Ip_TimeoutExpired/20 (536870911 (estimated locally),1.60 per call) Clock_Ip_StartTimeout/19 (57431766 (estimated locally),0.17 per call) Clock_Ip_TimeoutExpired/20 (1073741824 (estimated locally),3.20 per call) Clock_Ip_StartTimeout/19 (114863532 (estimated locally),0.34 per call) 
Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3 (Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip) @072079a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_ResetCgmXCscCssClkswSwip/1 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_SetCgmXCscCssClkswSwip/2 (Clock_Ip_SetCgmXCscCssClkswSwip) @07207700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au16SelectorEntryHardwareValue/15 (read)Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_axFeatureExtensions/17 (read)Clock_Ip_axFeatureExtensions/17 (read)Clock_Ip_apxCgm/18 (read)
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:335701228 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/21 (57431766 (estimated locally),0.17 per call) Clock_Ip_ReportClockErrors/21 (28715883 (estimated locally),0.09 per call) Clock_Ip_ReportClockErrors/21 (9476241 (estimated locally),0.03 per call) Clock_Ip_ReportClockErrors/21 (9404337 (estimated locally),0.03 per call) Clock_Ip_TimeoutExpired/20 (268435455 (estimated locally),0.80 per call) Clock_Ip_StartTimeout/19 (28715883 (estimated locally),0.09 per call) Clock_Ip_TimeoutExpired/20 (536870911 (estimated locally),1.60 per call) Clock_Ip_StartTimeout/19 (57431766 (estimated locally),0.17 per call) Clock_Ip_TimeoutExpired/20 (1073741824 (estimated locally),3.20 per call) Clock_Ip_StartTimeout/19 (114863532 (estimated locally),0.34 per call) 
Clock_Ip_ResetCgmXCscCssClkswSwip/1 (Clock_Ip_ResetCgmXCscCssClkswSwip) @07207460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_au8ClockFeatures/14 (read)Clock_Ip_axFeatureExtensions/17 (read)Clock_Ip_apxCgm/18 (read)
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_CallbackSelectorEmpty/0 (Clock_Ip_CallbackSelectorEmpty) @072071c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axSelectorCallbacks/13 (addr)Clock_Ip_axSelectorCallbacks/13 (addr)Clock_Ip_axSelectorCallbacks/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_ResetCgmXCscCssCsGrip/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function Clock_Ip_CallbackSelectorEmpty (Clock_Ip_CallbackSelectorEmpty, funcdef_no=0, decl_uid=6790, cgraph_uid=1, symbol_order=0)

Modification phase of node Clock_Ip_CallbackSelectorEmpty/0
Clock_Ip_CallbackSelectorEmpty (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ResetCgmXCscCssClkswSwip (Clock_Ip_ResetCgmXCscCssClkswSwip, funcdef_no=1, decl_uid=6792, cgraph_uid=2, symbol_order=1)

Modification phase of node Clock_Ip_ResetCgmXCscCssClkswSwip/1
Clock_Ip_ResetCgmXCscCssClkswSwip (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 SelectorMask;
  uint32 SelectorIndex;
  uint32 Instance;
  <unnamed type> _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  int _5;
  volatile struct Clock_Ip_CgmMuxType * _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_13(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = Config_13(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_15 = (uint32) _2;
  # DEBUG Instance => Instance_15
  # DEBUG BEGIN_STMT
  _3 = Clock_Ip_au8ClockFeatures[_1][4];
  SelectorIndex_16 = (uint32) _3;
  # DEBUG SelectorIndex => SelectorIndex_16
  # DEBUG BEGIN_STMT
  _4 = Clock_Ip_au8ClockFeatures[_1][2];
  _5 = (int) _4;
  SelectorMask_17 = Clock_Ip_axFeatureExtensions[_5].SelectorValueMask;
  # DEBUG SelectorMask => SelectorMask_17
  # DEBUG BEGIN_STMT
  _6 = Clock_Ip_apxCgm[Instance_15][SelectorIndex_16];
  _7 ={v} _6->CSC;
  _8 = _7 | 8;
  _6->CSC ={v} _8;
  # DEBUG BEGIN_STMT
  _9 ={v} _6->CSC;
  _10 = ~SelectorMask_17;
  _11 = _9 & _10;
  _6->CSC ={v} _11;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip (Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip, funcdef_no=16, decl_uid=6796, cgraph_uid=4, symbol_order=3)

Modification phase of node Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip/3
Clock_Ip_ResetCgmXCscCssClkswRampupRampdownSwip (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  Clock_Ip_ResetCgmXCscCssClkswSwip (Config_2(D)); [tail call]
  return;

}



;; Function Clock_Ip_SetCgmXCscCssCsGrip (Clock_Ip_SetCgmXCscCssCsGrip, funcdef_no=6, decl_uid=6800, cgraph_uid=7, symbol_order=6)

Modification phase of node Clock_Ip_SetCgmXCscCssCsGrip/6
Clock_Ip_SetCgmXCscCssCsGrip (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  uint32 RegValue;
  uint32 SelectorShift;
  uint32 SelectorMask;
  uint32 SelectorValue;
  uint32 SelectorIndex;
  uint32 Instance;
  <unnamed type> _1;
  unsigned char _2;
  unsigned char _4;
  <unnamed type> _5;
  short unsigned int _6;
  unsigned char _8;
  int _9;
  volatile struct Clock_Ip_CgmMuxType * _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int TimeoutTicks.0_16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int TimeoutTicks.1_22;
  long unsigned int _23;
  long unsigned int _24;
  <unnamed type> _25;
  <unnamed type> _26;
  long unsigned int _30;
  long unsigned int _54;

  <bb 2> [local count: 335701228]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_31(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 14>; [30.00%]

  <bb 3> [local count: 234990860]:
  # DEBUG BEGIN_STMT
  _1 = Config_31(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_33 = (uint32) _2;
  # DEBUG Instance => Instance_33
  # DEBUG BEGIN_STMT
  _4 = Clock_Ip_au8ClockFeatures[_1][4];
  SelectorIndex_34 = (uint32) _4;
  # DEBUG SelectorIndex => SelectorIndex_34
  # DEBUG BEGIN_STMT
  _5 = Config_31(D)->Value;
  _6 = Clock_Ip_au16SelectorEntryHardwareValue[_5];
  SelectorValue_35 = (uint32) _6;
  # DEBUG SelectorValue => SelectorValue_35
  # DEBUG BEGIN_STMT
  _8 = Clock_Ip_au8ClockFeatures[_1][2];
  _9 = (int) _8;
  SelectorMask_36 = Clock_Ip_axFeatureExtensions[_9].SelectorValueMask;
  # DEBUG SelectorMask => SelectorMask_36
  # DEBUG BEGIN_STMT
  SelectorShift_37 = Clock_Ip_axFeatureExtensions[_9].SelectorValueShift;
  # DEBUG SelectorShift => SelectorShift_37
  # DEBUG BEGIN_STMT
  _10 = Clock_Ip_apxCgm[Instance_33][SelectorIndex_34];
  _11 ={v} _10->CSS;
  _12 = _11 & SelectorMask_36;
  _13 = _12 >> SelectorShift_37;
  if (_13 != SelectorValue_35)
    goto <bb 4>; [48.88%]
  else
    goto <bb 14>; [51.12%]

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _14 ={v} _10->CSC;
  _15 = _14 | 12;
  _10->CSC ={v} _15;
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.0_16 = TimeoutTicks;
  TimeoutOccurred_41 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.0_16);
  # DEBUG TimeoutOccurred => TimeoutOccurred_41
  # DEBUG BEGIN_STMT
  _17 ={v} _10->CSS;
  _18 = _17 & 131072;
  if (_18 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686025]:
  if (TimeoutOccurred_41 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 16>; [94.50%]

  <bb 16> [local count: 958878294]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 114863532]:
  # TimeoutOccurred_3 = PHI <TimeoutOccurred_41(5), TimeoutOccurred_41(6)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_3 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  RegValue_43 ={v} _10->CSC;
  # DEBUG RegValue => RegValue_43
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => ~SelectorMask_36
  # DEBUG RegValue => D#1 & RegValue_43
  # DEBUG BEGIN_STMT
  _19 = SelectorValue_35 << SelectorShift_37;
  _30 = _19 ^ RegValue_43;
  _54 = _30 & SelectorMask_36;
  RegValue_44 = RegValue_43 ^ _54;
  # DEBUG RegValue => RegValue_44
  # DEBUG BEGIN_STMT
  _10->CSC ={v} RegValue_44;
  # DEBUG BEGIN_STMT
  _20 ={v} _10->CSC;
  _21 = _20 & 4294967283;
  _10->CSC ={v} _21;
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 9> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.1_22 = TimeoutTicks;
  TimeoutOccurred_49 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.1_22);
  # DEBUG TimeoutOccurred => TimeoutOccurred_49
  # DEBUG BEGIN_STMT
  _23 ={v} _10->CSS;
  _24 = _23 & 131072;
  if (_24 == 0)
    goto <bb 10>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 10> [local count: 507343011]:
  if (TimeoutOccurred_49 != 0)
    goto <bb 11>; [5.50%]
  else
    goto <bb 15>; [94.50%]

  <bb 15> [local count: 479439145]:
  goto <bb 9>; [100.00%]

  <bb 11> [local count: 57431766]:
  # TimeoutOccurred_7 = PHI <TimeoutOccurred_49(9), TimeoutOccurred_49(10)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_7 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 12> [local count: 18952483]:
  # DEBUG BEGIN_STMT
  _25 = Config_31(D)->Name;
  Clock_Ip_ReportClockErrors (3, _25);
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _26 = Config_31(D)->Name;
  Clock_Ip_ReportClockErrors (1, _26);

  <bb 14> [local count: 335701228]:
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip (Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip, funcdef_no=4, decl_uid=6798, cgraph_uid=5, symbol_order=4)

Modification phase of node Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip/4
Clock_Ip_SetCgmXCscCssClkswRampupRampdownSwip (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  uint32 RegValue;
  uint32 SelectorShift;
  uint32 SelectorMask;
  uint32 SelectorValue;
  uint32 SelectorIndex;
  uint32 Instance;
  <unnamed type> _1;
  unsigned char _2;
  unsigned char _4;
  <unnamed type> _5;
  short unsigned int _6;
  unsigned char _8;
  int _9;
  volatile struct Clock_Ip_CgmMuxType * _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int TimeoutTicks.2_15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int TimeoutTicks.3_19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int TimeoutTicks.4_22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  <unnamed type> _28;
  <unnamed type> _29;
  <unnamed type> _30;
  <unnamed type> _31;
  long unsigned int _36;
  long unsigned int _64;

  <bb 2> [local count: 335701228]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_37(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 21>; [30.00%]

  <bb 3> [local count: 234990860]:
  # DEBUG BEGIN_STMT
  _1 = Config_37(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_39 = (uint32) _2;
  # DEBUG Instance => Instance_39
  # DEBUG BEGIN_STMT
  _4 = Clock_Ip_au8ClockFeatures[_1][4];
  SelectorIndex_40 = (uint32) _4;
  # DEBUG SelectorIndex => SelectorIndex_40
  # DEBUG BEGIN_STMT
  _5 = Config_37(D)->Value;
  _6 = Clock_Ip_au16SelectorEntryHardwareValue[_5];
  SelectorValue_41 = (uint32) _6;
  # DEBUG SelectorValue => SelectorValue_41
  # DEBUG BEGIN_STMT
  _8 = Clock_Ip_au8ClockFeatures[_1][2];
  _9 = (int) _8;
  SelectorMask_42 = Clock_Ip_axFeatureExtensions[_9].SelectorValueMask;
  # DEBUG SelectorMask => SelectorMask_42
  # DEBUG BEGIN_STMT
  SelectorShift_43 = Clock_Ip_axFeatureExtensions[_9].SelectorValueShift;
  # DEBUG SelectorShift => SelectorShift_43
  # DEBUG BEGIN_STMT
  _11 = Clock_Ip_apxCgm[Instance_39][SelectorIndex_40];
  _12 ={v} _11->CSS;
  _13 = _12 & SelectorMask_42;
  _14 = _13 >> SelectorShift_43;
  if (_14 != SelectorValue_41)
    goto <bb 4>; [48.88%]
  else
    goto <bb 21>; [51.12%]

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.2_15 = TimeoutTicks;
  TimeoutOccurred_46 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.2_15);
  # DEBUG TimeoutOccurred => TimeoutOccurred_46
  # DEBUG BEGIN_STMT
  _16 ={v} _11->CSS;
  _17 = _16 & 65536;
  if (_17 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686025]:
  if (TimeoutOccurred_46 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 24>; [94.50%]

  <bb 24> [local count: 958878294]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 114863532]:
  # TimeoutOccurred_3 = PHI <TimeoutOccurred_46(5), TimeoutOccurred_46(6)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_3 != 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  RegValue_48 ={v} _11->CSC;
  # DEBUG RegValue => RegValue_48
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => ~SelectorMask_42
  # DEBUG RegValue => D#2 & RegValue_48
  # DEBUG BEGIN_STMT
  _18 = SelectorValue_41 << SelectorShift_43;
  _36 = _18 ^ RegValue_48;
  _64 = _36 & SelectorMask_42;
  RegValue_49 = RegValue_48 ^ _64;
  # DEBUG RegValue => RegValue_49
  # DEBUG BEGIN_STMT
  RegValue_50 = RegValue_49 | 7;
  # DEBUG RegValue => RegValue_50
  # DEBUG BEGIN_STMT
  _11->CSC ={v} RegValue_50;
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 9> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.3_19 = TimeoutTicks;
  TimeoutOccurred_54 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_19);
  # DEBUG TimeoutOccurred => TimeoutOccurred_54
  # DEBUG BEGIN_STMT
  _20 ={v} _11->CSS;
  _21 = _20 & 4;
  if (_21 == 0)
    goto <bb 10>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 10> [local count: 507343011]:
  if (TimeoutOccurred_54 != 0)
    goto <bb 11>; [5.50%]
  else
    goto <bb 23>; [94.50%]

  <bb 23> [local count: 479439145]:
  goto <bb 9>; [100.00%]

  <bb 11> [local count: 57431766]:
  # TimeoutOccurred_7 = PHI <TimeoutOccurred_54(9), TimeoutOccurred_54(10)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_7 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 13> [local count: 268435455]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.4_22 = TimeoutTicks;
  TimeoutOccurred_58 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.4_22);
  # DEBUG TimeoutOccurred => TimeoutOccurred_58
  # DEBUG BEGIN_STMT
  _23 ={v} _11->CSS;
  _24 = _23 & 65536;
  if (_24 != 0)
    goto <bb 14>; [94.50%]
  else
    goto <bb 15>; [5.50%]

  <bb 14> [local count: 253671505]:
  if (TimeoutOccurred_58 != 0)
    goto <bb 15>; [5.50%]
  else
    goto <bb 22>; [94.50%]

  <bb 22> [local count: 239719572]:
  goto <bb 13>; [100.00%]

  <bb 15> [local count: 28715883]:
  # TimeoutOccurred_10 = PHI <TimeoutOccurred_58(13), TimeoutOccurred_58(14)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_10 != 0)
    goto <bb 18>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 16> [local count: 19239641]:
  # DEBUG BEGIN_STMT
  _25 ={v} _11->CSS;
  _26 = _25 >> 17;
  _27 = _26 & 7;
  if (_27 != 1)
    goto <bb 17>; [48.88%]
  else
    goto <bb 21>; [51.12%]

  <bb 17> [local count: 9404337]:
  # DEBUG BEGIN_STMT
  _28 = Config_37(D)->Name;
  Clock_Ip_ReportClockErrors (3, _28);
  goto <bb 21>; [100.00%]

  <bb 18> [local count: 9476241]:
  # DEBUG BEGIN_STMT
  _29 = Config_37(D)->Name;
  Clock_Ip_ReportClockErrors (1, _29);
  goto <bb 21>; [100.00%]

  <bb 19> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  _30 = Config_37(D)->Name;
  Clock_Ip_ReportClockErrors (1, _30);
  goto <bb 21>; [100.00%]

  <bb 20> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _31 = Config_37(D)->Name;
  Clock_Ip_ReportClockErrors (1, _31);

  <bb 21> [local count: 335701228]:
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Clock_Ip_SetCgmXCscCssClkswSwip (Clock_Ip_SetCgmXCscCssClkswSwip, funcdef_no=2, decl_uid=6794, cgraph_uid=3, symbol_order=2)

Modification phase of node Clock_Ip_SetCgmXCscCssClkswSwip/2
Clock_Ip_SetCgmXCscCssClkswSwip (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  uint32 RegValue;
  uint32 SelectorShift;
  uint32 SelectorMask;
  uint32 SelectorValue;
  uint32 SelectorIndex;
  uint32 Instance;
  <unnamed type> _1;
  unsigned char _2;
  unsigned char _4;
  <unnamed type> _5;
  short unsigned int _6;
  unsigned char _8;
  int _9;
  volatile struct Clock_Ip_CgmMuxType * _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int TimeoutTicks.5_15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int TimeoutTicks.6_19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int TimeoutTicks.7_22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  <unnamed type> _28;
  <unnamed type> _29;
  <unnamed type> _30;
  <unnamed type> _31;
  long unsigned int _36;
  long unsigned int _64;

  <bb 2> [local count: 335701228]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (Config_37(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 21>; [30.00%]

  <bb 3> [local count: 234990860]:
  # DEBUG BEGIN_STMT
  _1 = Config_37(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][0];
  Instance_39 = (uint32) _2;
  # DEBUG Instance => Instance_39
  # DEBUG BEGIN_STMT
  _4 = Clock_Ip_au8ClockFeatures[_1][4];
  SelectorIndex_40 = (uint32) _4;
  # DEBUG SelectorIndex => SelectorIndex_40
  # DEBUG BEGIN_STMT
  _5 = Config_37(D)->Value;
  _6 = Clock_Ip_au16SelectorEntryHardwareValue[_5];
  SelectorValue_41 = (uint32) _6;
  # DEBUG SelectorValue => SelectorValue_41
  # DEBUG BEGIN_STMT
  _8 = Clock_Ip_au8ClockFeatures[_1][2];
  _9 = (int) _8;
  SelectorMask_42 = Clock_Ip_axFeatureExtensions[_9].SelectorValueMask;
  # DEBUG SelectorMask => SelectorMask_42
  # DEBUG BEGIN_STMT
  SelectorShift_43 = Clock_Ip_axFeatureExtensions[_9].SelectorValueShift;
  # DEBUG SelectorShift => SelectorShift_43
  # DEBUG BEGIN_STMT
  _11 = Clock_Ip_apxCgm[Instance_39][SelectorIndex_40];
  _12 ={v} _11->CSS;
  _13 = _12 & SelectorMask_42;
  _14 = _13 >> SelectorShift_43;
  if (_14 != SelectorValue_41)
    goto <bb 4>; [48.88%]
  else
    goto <bb 21>; [51.12%]

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.5_15 = TimeoutTicks;
  TimeoutOccurred_46 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.5_15);
  # DEBUG TimeoutOccurred => TimeoutOccurred_46
  # DEBUG BEGIN_STMT
  _16 ={v} _11->CSS;
  _17 = _16 & 65536;
  if (_17 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686025]:
  if (TimeoutOccurred_46 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 24>; [94.50%]

  <bb 24> [local count: 958878294]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 114863532]:
  # TimeoutOccurred_3 = PHI <TimeoutOccurred_46(5), TimeoutOccurred_46(6)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_3 != 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  RegValue_48 ={v} _11->CSC;
  # DEBUG RegValue => RegValue_48
  # DEBUG BEGIN_STMT
  # DEBUG D#3 => ~SelectorMask_42
  # DEBUG RegValue => D#3 & RegValue_48
  # DEBUG BEGIN_STMT
  _18 = SelectorValue_41 << SelectorShift_43;
  _36 = _18 ^ RegValue_48;
  _64 = _36 & SelectorMask_42;
  RegValue_49 = RegValue_48 ^ _64;
  # DEBUG RegValue => RegValue_49
  # DEBUG BEGIN_STMT
  RegValue_50 = RegValue_49 | 4;
  # DEBUG RegValue => RegValue_50
  # DEBUG BEGIN_STMT
  _11->CSC ={v} RegValue_50;
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 9> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.6_19 = TimeoutTicks;
  TimeoutOccurred_54 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.6_19);
  # DEBUG TimeoutOccurred => TimeoutOccurred_54
  # DEBUG BEGIN_STMT
  _20 ={v} _11->CSS;
  _21 = _20 & 4;
  if (_21 == 0)
    goto <bb 10>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 10> [local count: 507343011]:
  if (TimeoutOccurred_54 != 0)
    goto <bb 11>; [5.50%]
  else
    goto <bb 23>; [94.50%]

  <bb 23> [local count: 479439145]:
  goto <bb 9>; [100.00%]

  <bb 11> [local count: 57431766]:
  # TimeoutOccurred_7 = PHI <TimeoutOccurred_54(9), TimeoutOccurred_54(10)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_7 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 13> [local count: 268435455]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.7_22 = TimeoutTicks;
  TimeoutOccurred_58 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.7_22);
  # DEBUG TimeoutOccurred => TimeoutOccurred_58
  # DEBUG BEGIN_STMT
  _23 ={v} _11->CSS;
  _24 = _23 & 65536;
  if (_24 != 0)
    goto <bb 14>; [94.50%]
  else
    goto <bb 15>; [5.50%]

  <bb 14> [local count: 253671505]:
  if (TimeoutOccurred_58 != 0)
    goto <bb 15>; [5.50%]
  else
    goto <bb 22>; [94.50%]

  <bb 22> [local count: 239719572]:
  goto <bb 13>; [100.00%]

  <bb 15> [local count: 28715883]:
  # TimeoutOccurred_10 = PHI <TimeoutOccurred_58(13), TimeoutOccurred_58(14)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_10 != 0)
    goto <bb 18>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 16> [local count: 19239641]:
  # DEBUG BEGIN_STMT
  _25 ={v} _11->CSS;
  _26 = _25 >> 17;
  _27 = _26 & 7;
  if (_27 != 1)
    goto <bb 17>; [48.88%]
  else
    goto <bb 21>; [51.12%]

  <bb 17> [local count: 9404337]:
  # DEBUG BEGIN_STMT
  _28 = Config_37(D)->Name;
  Clock_Ip_ReportClockErrors (3, _28);
  goto <bb 21>; [100.00%]

  <bb 18> [local count: 9476241]:
  # DEBUG BEGIN_STMT
  _29 = Config_37(D)->Name;
  Clock_Ip_ReportClockErrors (1, _29);
  goto <bb 21>; [100.00%]

  <bb 19> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  _30 = Config_37(D)->Name;
  Clock_Ip_ReportClockErrors (1, _30);
  goto <bb 21>; [100.00%]

  <bb 20> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _31 = Config_37(D)->Name;
  Clock_Ip_ReportClockErrors (1, _31);

  <bb 21> [local count: 335701228]:
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Clock_Ip_ResetCgmXCscCssCsGrip (Clock_Ip_ResetCgmXCscCssCsGrip, funcdef_no=14, decl_uid=6802, cgraph_uid=6, symbol_order=5)

Modification phase of node Clock_Ip_ResetCgmXCscCssCsGrip/5
Clock_Ip_ResetCgmXCscCssCsGrip (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  Clock_Ip_CallbackSelectorEmpty (Config_1(D)); [tail call]
  return;

}



;; Function Clock_Ip_ConfigureResetGenCtrl1 (Clock_Ip_ConfigureResetGenCtrl1, funcdef_no=10, decl_uid=6784, cgraph_uid=11, symbol_order=10)

Modification phase of node Clock_Ip_ConfigureResetGenCtrl1/10
Clock_Ip_ConfigureResetGenCtrl1 (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 SelectorIndex;
  <unnamed type> _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Config_8(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][4];
  SelectorIndex_9 = (uint32) _2;
  # DEBUG SelectorIndex => SelectorIndex_9
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct S32G_GPR_Type *)1074252288B].GENCTRL1;
  _4 = 1 << SelectorIndex_9;
  _5 = ~_4;
  _6 = _3 & _5;
  MEM[(struct S32G_GPR_Type *)1074252288B].GENCTRL1 ={v} _6;
  return;

}



;; Function Clock_Ip_ResetGenctrl1Ctrl (Clock_Ip_ResetGenctrl1Ctrl, funcdef_no=7, decl_uid=6806, cgraph_uid=8, symbol_order=7)

Modification phase of node Clock_Ip_ResetGenctrl1Ctrl/7
Clock_Ip_ResetGenctrl1Ctrl (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (Config_2(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ConfigureResetGenCtrl1 (Config_2(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_ConfigureSetGenCtrl1 (Clock_Ip_ConfigureSetGenCtrl1, funcdef_no=11, decl_uid=6786, cgraph_uid=12, symbol_order=11)

Modification phase of node Clock_Ip_ConfigureSetGenCtrl1/11
Clock_Ip_ConfigureSetGenCtrl1 (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 SelectorIndex;
  <unnamed type> _1;
  unsigned char _2;
  <unnamed type> _3;
  short unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Config_14(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][4];
  SelectorIndex_15 = (uint32) _2;
  # DEBUG SelectorIndex => SelectorIndex_15
  # DEBUG BEGIN_STMT
  _3 = Config_14(D)->Value;
  _4 = Clock_Ip_au16SelectorEntryHardwareValue[_3];
  # DEBUG SelectorValue => (uint32) _4
  # DEBUG BEGIN_STMT
  if (_4 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct S32G_GPR_Type *)1074252288B].GENCTRL1;
  _6 = 1 << SelectorIndex_15;
  _7 = _5 | _6;
  MEM[(struct S32G_GPR_Type *)1074252288B].GENCTRL1 ={v} _7;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _8 ={v} MEM[(struct S32G_GPR_Type *)1074252288B].GENCTRL1;
  _9 = 1 << SelectorIndex_15;
  _10 = ~_9;
  _11 = _8 & _10;
  MEM[(struct S32G_GPR_Type *)1074252288B].GENCTRL1 ={v} _11;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_SetGenctrl1Ctrl (Clock_Ip_SetGenctrl1Ctrl, funcdef_no=8, decl_uid=6804, cgraph_uid=9, symbol_order=8)

Modification phase of node Clock_Ip_SetGenctrl1Ctrl/8
Clock_Ip_SetGenctrl1Ctrl (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (Config_2(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ConfigureSetGenCtrl1 (Config_2(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Clock_Ip_SetRtcRtccClksel_TrustedCall (Clock_Ip_SetRtcRtccClksel_TrustedCall, funcdef_no=12, decl_uid=6788, cgraph_uid=13, symbol_order=12)

Modification phase of node Clock_Ip_SetRtcRtccClksel_TrustedCall/12
Clock_Ip_SetRtcRtccClksel_TrustedCall (const struct Clock_Ip_SelectorConfigType * Config)
{
  uint32 SelectorValue;
  uint32 RegValue;
  <unnamed type> _1;
  short unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Config_6(D)->Value;
  _2 = Clock_Ip_au16SelectorEntryRtcHardwareValue[_1];
  SelectorValue_7 = (uint32) _2;
  # DEBUG SelectorValue => SelectorValue_7
  # DEBUG BEGIN_STMT
  RegValue_8 ={v} MEM[(struct RTC_Type *)1074135040B].RTCC;
  # DEBUG RegValue => RegValue_8
  # DEBUG BEGIN_STMT
  RegValue_9 = RegValue_8 & 4294955007;
  # DEBUG RegValue => RegValue_9
  # DEBUG BEGIN_STMT
  _3 = SelectorValue_7 << 12;
  _4 = _3 & 12288;
  RegValue_10 = _4 | RegValue_9;
  # DEBUG RegValue => RegValue_10
  # DEBUG BEGIN_STMT
  MEM[(struct RTC_Type *)1074135040B].RTCC ={v} RegValue_10;
  return;

}



;; Function Clock_Ip_SetRtcRtccClksel (Clock_Ip_SetRtcRtccClksel, funcdef_no=9, decl_uid=6808, cgraph_uid=10, symbol_order=9)

Modification phase of node Clock_Ip_SetRtcRtccClksel/9
Clock_Ip_SetRtcRtccClksel (const struct Clock_Ip_SelectorConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (Config_2(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  Clock_Ip_SetRtcRtccClksel_TrustedCall (Config_2(D));

  <bb 4> [local count: 1073741824]:
  return;

}


