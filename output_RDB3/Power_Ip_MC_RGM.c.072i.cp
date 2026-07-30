
IPA constant propagation start:
Determining dynamic type for call: ResetReason_17 = Power_Ip_MC_RGM_CheckResetReason (ActiveValue_15, 0, &Position);
  Starting walk at: ResetReason_17 = Power_Ip_MC_RGM_CheckResetReason (ActiveValue_15, 0, &Position);
  instance pointer: &Position  Outer instance pointer: Position offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ResetReason_23 = Power_Ip_MC_RGM_CheckResetReason (ActiveValue_21, 1, &Position);
  Starting walk at: ResetReason_23 = Power_Ip_MC_RGM_CheckResetReason (ActiveValue_21, 1, &Position);
  instance pointer: &Position  Outer instance pointer: Position offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Power_Ip_MC_RGM_ClearDesResetFlags (RegValue_13);
  Function call may change dynamic type:ResetReason_17 = Power_Ip_MC_RGM_CheckResetReason (ActiveValue_15, 0, &Position);
Determining dynamic type for call: Power_Ip_MC_RGM_ConfigureResetDomainController (TempDomainConfigPtr_12);
  Starting walk at: Power_Ip_MC_RGM_ConfigureResetDomainController (TempDomainConfigPtr_12);
  instance pointer: TempDomainConfigPtr_12  Outer instance pointer: &*_1[_2] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Power_Ip_MC_RGM_AssertDomainReset (_4);
Determining dynamic type for call: Power_Ip_MC_RGM_ConfigureResetDomainController (TempDomainConfigPtr_13);
  Starting walk at: Power_Ip_MC_RGM_ConfigureResetDomainController (TempDomainConfigPtr_13);
  instance pointer: TempDomainConfigPtr_13  Outer instance pointer: &*_1[_2] offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Power_Ip_MC_RGM_CheckConfigureCore (_13, _14);
  Starting walk at: Power_Ip_MC_RGM_CheckConfigureCore (_13, _14);
  instance pointer: _13  Outer instance pointer: &*_10[_11] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Power_Ip_MC_RGM_CheckConfigureCOFB (_7, _8);
  Function call may change dynamic type:Power_Ip_MC_RGM_CheckConfigureCore (_13, _14);
Determining dynamic type for call: Power_Ip_MC_RGM_CheckConfigureCOFB (_7, _8);
  Starting walk at: Power_Ip_MC_RGM_CheckConfigureCOFB (_7, _8);
  instance pointer: _7  Outer instance pointer: &*_4[_5] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Power_Ip_MC_RGM_CheckConfigureCOFB (_7, _8);
Determining dynamic type for call: Power_Ip_MC_RGM_ConfigureCore (_13, _14);
  Starting walk at: Power_Ip_MC_RGM_ConfigureCore (_13, _14);
  instance pointer: _13  Outer instance pointer: &*_10[_11] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Power_Ip_MC_RGM_ConfigureCOFB (_7, _8);
  Function call may change dynamic type:Power_Ip_MC_RGM_ConfigureCore (_13, _14);
Determining dynamic type for call: Power_Ip_MC_RGM_ConfigureCOFB (_7, _8);
  Starting walk at: Power_Ip_MC_RGM_ConfigureCOFB (_7, _8);
  instance pointer: _7  Outer instance pointer: &*_4[_5] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Power_Ip_MC_RGM_ConfigureCOFB (_7, _8);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Power_Ip_MC_RGM_ClearDesResetFlags.part.0/25:
  Jump functions of caller  Power_Ip_MC_RGM_ClearFesResetFlags.part.0/24:
  Jump functions of caller  Power_Ip_ReportPowerErrors/23:
  Jump functions of caller  Power_Ip_TimeoutExpired/22:
  Jump functions of caller  Power_Ip_StartTimeout/21:
  Jump functions of caller  Power_Ip_MC_RGM_GetResetRawValue/20:
    callsite  Power_Ip_MC_RGM_GetResetRawValue/20 -> Power_Ip_MC_RGM_ClearDesResetFlags/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xc0073f5b
         VR  [0, -1073266853]
    callsite  Power_Ip_MC_RGM_GetResetRawValue/20 -> Power_Ip_MC_RGM_ClearFesResetFlags/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xc0340059
         VR  [0, -1070333863]
  Jump functions of caller  Power_Ip_MC_RGM_GetResetReason/19:
    callsite  Power_Ip_MC_RGM_GetResetReason/19 -> Power_Ip_MC_RGM_ClearFesResetFlags/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xc0340059
         VR  [0, -1070333863]
    callsite  Power_Ip_MC_RGM_GetResetReason/19 -> Power_Ip_MC_RGM_CheckResetReason/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  Power_Ip_MC_RGM_GetResetReason/19 -> Power_Ip_MC_RGM_ClearDesResetFlags/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xc0073f5b
         VR  [0, -1073266853]
    callsite  Power_Ip_MC_RGM_GetResetReason/19 -> Power_Ip_MC_RGM_CheckResetReason/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  Power_Ip_MC_RGM_CheckResetReason/18:
  Jump functions of caller  Power_Ip_MC_RGM_DisableResetDomain/17:
    callsite  Power_Ip_MC_RGM_DisableResetDomain/17 -> Power_Ip_MC_RGM_ConfigureResetDomainController/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Power_Ip_MC_RGM_DisableResetDomain/17 -> Power_Ip_MC_RGM_AssertDomainReset/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Power_Ip_MC_RGM_EnableResetDomain/16:
    callsite  Power_Ip_MC_RGM_EnableResetDomain/16 -> Power_Ip_MC_RGM_ReleaseDomainReset/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Power_Ip_MC_RGM_EnableResetDomain/16 -> Power_Ip_MC_RGM_ConfigureResetDomainController/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Power_Ip_MC_RGM_CheckModeConfig/15:
    callsite  Power_Ip_MC_RGM_CheckModeConfig/15 -> Power_Ip_MC_RGM_CheckConfigureCore/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Power_Ip_MC_RGM_CheckModeConfig/15 -> Power_Ip_MC_RGM_CheckConfigureCOFB/10 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Power_Ip_MC_RGM_ModeConfig/14:
    callsite  Power_Ip_MC_RGM_ModeConfig/14 -> Power_Ip_MC_RGM_ConfigureCore/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Power_Ip_MC_RGM_ModeConfig/14 -> Power_Ip_MC_RGM_ConfigureCOFB/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Power_Ip_MC_RGM_ResetInit/13:
    callsite  Power_Ip_MC_RGM_ResetInit/13 -> Power_Ip_MC_RGM_ClearFesResetFlags/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Power_Ip_MC_RGM_CheckConfigureCore/12:
  Jump functions of caller  Power_Ip_MC_RGM_ConfigureCore/11:
  Jump functions of caller  Power_Ip_MC_RGM_CheckConfigureCOFB/10:
  Jump functions of caller  Power_Ip_MC_RGM_ConfigureCOFB/9:
  Jump functions of caller  Power_Ip_MC_RGM_ConfigureResetDomainController/8:
  Jump functions of caller  Power_Ip_MC_RGM_AssertDomainReset/7:
  Jump functions of caller  Power_Ip_MC_RGM_ReleaseDomainReset/6:
  Jump functions of caller  Power_Ip_MC_RGM_ClearDesResetFlags/5:
    callsite  Power_Ip_MC_RGM_ClearDesResetFlags/5 -> Power_Ip_MC_RGM_ClearDesResetFlags.part.0/25 : 
  Jump functions of caller  Power_Ip_MC_RGM_ClearFesResetFlags/4:
    callsite  Power_Ip_MC_RGM_ClearFesResetFlags/4 -> Power_Ip_MC_RGM_ClearFesResetFlags.part.0/24 : 

 Propagating constants:

Not considering Power_Ip_MC_RGM_GetResetRawValue for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_MC_RGM_GetResetReason for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_MC_RGM_DisableResetDomain for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_MC_RGM_EnableResetDomain for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_MC_RGM_CheckModeConfig for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_MC_RGM_ModeConfig for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_MC_RGM_ResetInit for cloning; -fipa-cp-clone disabled.

overall_size: 436, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Power_Ip_MC_RGM_ClearFesResetFlags.part.0/24:
  Node: Power_Ip_MC_RGM_GetResetRawValue/20:
  Node: Power_Ip_MC_RGM_GetResetReason/19:
  Node: Power_Ip_MC_RGM_CheckResetReason/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 3, loc_size: 19, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 19, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         uint8 [0, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32 * ~[0B, 0B]
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_DisableResetDomain/17:
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
  Node: Power_Ip_MC_RGM_EnableResetDomain/16:
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
  Node: Power_Ip_MC_RGM_CheckModeConfig/15:
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
  Node: Power_Ip_MC_RGM_ModeConfig/14:
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
  Node: Power_Ip_MC_RGM_ResetInit/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Power_Ip_MC_RGM_CheckConfigureCore/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct Power_Ip_MC_RGM_CoreConfigType * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_ConfigureCore/11:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct Power_Ip_MC_RGM_CoreConfigType * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_CheckConfigureCOFB/10:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct Power_Ip_MC_RGM_CofbConfigType * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_ConfigureCOFB/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct Power_Ip_MC_RGM_CofbConfigType * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_ConfigureResetDomainController/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_AssertDomainReset/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_ReleaseDomainReset/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_ClearDesResetFlags/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xc0073f5b
         uint32 [0, 3221700443]
        AGGS VARIABLE
  Node: Power_Ip_MC_RGM_ClearFesResetFlags/4:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

Propagated bits info for function Power_Ip_MC_RGM_CheckResetReason/18:
 param 1: value = 0x1, mask = 0x1
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function Power_Ip_MC_RGM_ClearDesResetFlags/5:
 param 0: value = 0x0, mask = 0xc0073f5b

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Power_Ip_MC_RGM_ClearDesResetFlags.part.0/25 (Power_Ip_MC_RGM_ClearDesResetFlags.part.0) @077647e0
  Type: function definition analyzed alias
  Visibility: prevailing_def_ironly artificial
  References: Power_Ip_MC_RGM_ClearFesResetFlags.part.0/24 (alias)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 local icf_merged split_part optimize_size
  Called by: Power_Ip_MC_RGM_ClearDesResetFlags/5 (37904965 (estimated locally),0.11 per call) 
  Calls: 
Power_Ip_MC_RGM_ClearFesResetFlags.part.0/24 (Power_Ip_MC_RGM_ClearFesResetFlags.part.0) @07764b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: Power_Ip_MC_RGM_ClearDesResetFlags.part.0/25 (alias)
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local icf_merged split_part optimize_size
  Called by: Power_Ip_MC_RGM_ClearFesResetFlags/4 (37904965 (estimated locally),0.11 per call) 
  Calls: Power_Ip_ReportPowerErrors/23 (1073741824 (estimated locally),1.00 per call) 
Power_Ip_ReportPowerErrors/23 (Power_Ip_ReportPowerErrors) @07564d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_MC_RGM_ConfigureResetDomainController/8 (37904965 (estimated locally),0.33 per call) Power_Ip_MC_RGM_CheckConfigureCore/12 (37904965 (estimated locally),0.33 per call) Power_Ip_MC_RGM_CheckConfigureCOFB/10 (37904965 (estimated locally),0.33 per call) Power_Ip_MC_RGM_ClearFesResetFlags.part.0/24 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Power_Ip_TimeoutExpired/22 (Power_Ip_TimeoutExpired) @07564c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_MC_RGM_ClearDesResetFlags/5 (1073741824 (estimated locally),3.08 per call) Power_Ip_MC_RGM_ConfigureResetDomainController/8 (1073741824 (estimated locally),9.35 per call) Power_Ip_MC_RGM_CheckConfigureCore/12 (1073741824 (estimated locally),9.35 per call) Power_Ip_MC_RGM_CheckConfigureCOFB/10 (1073741824 (estimated locally),9.35 per call) Power_Ip_MC_RGM_ClearFesResetFlags/4 (1073741824 (estimated locally),3.08 per call) 
  Calls: 
Power_Ip_StartTimeout/21 (Power_Ip_StartTimeout) @07564b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Power_Ip_MC_RGM_ClearDesResetFlags/5 (114863532 (estimated locally),0.33 per call) Power_Ip_MC_RGM_ConfigureResetDomainController/8 (114863532 (estimated locally),1.00 per call) Power_Ip_MC_RGM_CheckConfigureCore/12 (114863532 (estimated locally),1.00 per call) Power_Ip_MC_RGM_CheckConfigureCOFB/10 (114863532 (estimated locally),1.00 per call) Power_Ip_MC_RGM_ClearFesResetFlags/4 (114863532 (estimated locally),0.33 per call) 
  Calls: 
Power_Ip_MC_RGM_GetResetRawValue/20 (Power_Ip_MC_RGM_GetResetRawValue) @07564540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Power_Ip_pxMC_RGM/2 (read)Power_Ip_u32FesResetStatus/1 (write)Power_Ip_u32FesResetStatus/1 (read)Power_Ip_pxMC_RGM/2 (read)Power_Ip_u32DesResetStatus/0 (write)Power_Ip_u32DesResetStatus/0 (read)
  Referring: 
  Availability: available
  Function flags: count:65068756 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_ClearDesResetFlags/5 (32534377 (estimated locally),0.50 per call) Power_Ip_MC_RGM_ClearFesResetFlags/4 (32534377 (estimated locally),0.50 per call) 
Power_Ip_MC_RGM_GetResetReason/19 (Power_Ip_MC_RGM_GetResetReason) @075640e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Power_Ip_pxMC_RGM/2 (read)Power_Ip_u32DesResetStatus/0 (write)Power_Ip_u32DesResetStatus/0 (read)Power_Ip_pxMC_RGM/2 (read)Power_Ip_u32FesResetStatus/1 (write)Power_Ip_u32FesResetStatus/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_ClearFesResetFlags/4 (536870913 (estimated locally),0.50 per call) Power_Ip_MC_RGM_CheckResetReason/18 (177167401 (estimated locally),0.17 per call) Power_Ip_MC_RGM_ClearDesResetFlags/5 (1073741824 (estimated locally),1.00 per call) Power_Ip_MC_RGM_CheckResetReason/18 (1073741824 (estimated locally),1.00 per call) 
Power_Ip_MC_RGM_CheckResetReason/18 (Power_Ip_MC_RGM_CheckResetReason) @0774fa80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:46850980 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_GetResetReason/19 (177167401 (estimated locally),0.17 per call) Power_Ip_MC_RGM_GetResetReason/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Power_Ip_MC_RGM_DisableResetDomain/17 (Power_Ip_MC_RGM_DisableResetDomain) @0774f2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_ConfigureResetDomainController/8 (44291850 (estimated locally),0.04 per call) Power_Ip_MC_RGM_AssertDomainReset/7 (44291850 (estimated locally),0.04 per call) 
Power_Ip_MC_RGM_EnableResetDomain/16 (Power_Ip_MC_RGM_EnableResetDomain) @0774fee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_ReleaseDomainReset/6 (44291850 (estimated locally),0.04 per call) Power_Ip_MC_RGM_ConfigureResetDomainController/8 (44291850 (estimated locally),0.04 per call) 
Power_Ip_MC_RGM_CheckModeConfig/15 (Power_Ip_MC_RGM_CheckModeConfig) @0774fc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:236223204 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_CheckConfigureCore/12 (315357971 (estimated locally),1.33 per call) Power_Ip_MC_RGM_CheckConfigureCOFB/10 (315357973 (estimated locally),1.33 per call) 
Power_Ip_MC_RGM_ModeConfig/14 (Power_Ip_MC_RGM_ModeConfig) @0774f9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:236223204 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_ConfigureCore/11 (315357971 (estimated locally),1.33 per call) Power_Ip_MC_RGM_ConfigureCOFB/9 (315357973 (estimated locally),1.33 per call) 
Power_Ip_MC_RGM_ResetInit/13 (Power_Ip_MC_RGM_ResetInit) @0774f700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Power_Ip_pxMC_RGM/2 (read)Power_Ip_u32FesResetStatus/1 (write)Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Power_Ip_MC_RGM_ClearFesResetFlags/4 (354334802 (estimated locally),0.33 per call) 
Power_Ip_MC_RGM_CheckConfigureCore/12 (Power_Ip_MC_RGM_CheckConfigureCore) @0774f460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_CheckModeConfig/15 (315357971 (estimated locally),1.33 per call) 
  Calls: Power_Ip_ReportPowerErrors/23 (37904965 (estimated locally),0.33 per call) Power_Ip_TimeoutExpired/22 (1073741824 (estimated locally),9.35 per call) Power_Ip_StartTimeout/21 (114863532 (estimated locally),1.00 per call) 
Power_Ip_MC_RGM_ConfigureCore/11 (Power_Ip_MC_RGM_ConfigureCore) @0774f1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_ModeConfig/14 (315357971 (estimated locally),1.33 per call) 
  Calls: 
Power_Ip_MC_RGM_CheckConfigureCOFB/10 (Power_Ip_MC_RGM_CheckConfigureCOFB) @075d7c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_CheckModeConfig/15 (315357973 (estimated locally),1.33 per call) 
  Calls: Power_Ip_ReportPowerErrors/23 (37904965 (estimated locally),0.33 per call) Power_Ip_TimeoutExpired/22 (1073741824 (estimated locally),9.35 per call) Power_Ip_StartTimeout/21 (114863532 (estimated locally),1.00 per call) 
Power_Ip_MC_RGM_ConfigureCOFB/9 (Power_Ip_MC_RGM_ConfigureCOFB) @075d7700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_ModeConfig/14 (315357973 (estimated locally),1.33 per call) 
  Calls: 
Power_Ip_MC_RGM_ConfigureResetDomainController/8 (Power_Ip_MC_RGM_ConfigureResetDomainController) @075d70e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxRdc/3 (read)Power_Ip_pxRdc/3 (read)Power_Ip_pxRdc/3 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_DisableResetDomain/17 (44291850 (estimated locally),0.04 per call) Power_Ip_MC_RGM_EnableResetDomain/16 (44291850 (estimated locally),0.04 per call) 
  Calls: Power_Ip_ReportPowerErrors/23 (37904965 (estimated locally),0.33 per call) Power_Ip_TimeoutExpired/22 (1073741824 (estimated locally),9.35 per call) Power_Ip_StartTimeout/21 (114863532 (estimated locally),1.00 per call) 
Power_Ip_MC_RGM_AssertDomainReset/7 (Power_Ip_MC_RGM_AssertDomainReset) @075d7b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_DisableResetDomain/17 (44291850 (estimated locally),0.04 per call) 
  Calls: 
Power_Ip_MC_RGM_ReleaseDomainReset/6 (Power_Ip_MC_RGM_ReleaseDomainReset) @075d78c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_EnableResetDomain/16 (44291850 (estimated locally),0.04 per call) 
  Calls: 
Power_Ip_MC_RGM_ClearDesResetFlags/5 (Power_Ip_MC_RGM_ClearDesResetFlags) @075d7620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: local
  Function flags: count:348071309 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_GetResetRawValue/20 (32534377 (estimated locally),0.50 per call) Power_Ip_MC_RGM_GetResetReason/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: Power_Ip_MC_RGM_ClearDesResetFlags.part.0/25 (37904965 (estimated locally),0.11 per call) Power_Ip_TimeoutExpired/22 (1073741824 (estimated locally),3.08 per call) Power_Ip_StartTimeout/21 (114863532 (estimated locally),0.33 per call) 
Power_Ip_MC_RGM_ClearFesResetFlags/4 (Power_Ip_MC_RGM_ClearFesResetFlags) @075d7380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Power_Ip_pxMC_RGM/2 (read)
  Referring: 
  Availability: local
  Function flags: count:348071309 (estimated locally) body local optimize_size
  Called by: Power_Ip_MC_RGM_GetResetRawValue/20 (32534377 (estimated locally),0.50 per call) Power_Ip_MC_RGM_GetResetReason/19 (536870913 (estimated locally),0.50 per call) Power_Ip_MC_RGM_ResetInit/13 (354334802 (estimated locally),0.33 per call) 
  Calls: Power_Ip_MC_RGM_ClearFesResetFlags.part.0/24 (37904965 (estimated locally),0.11 per call) Power_Ip_TimeoutExpired/22 (1073741824 (estimated locally),3.08 per call) Power_Ip_StartTimeout/21 (114863532 (estimated locally),0.33 per call) 
Power_Ip_pxRdc/3 (Power_Ip_pxRdc) @0755df30
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Power_Ip_MC_RGM_ConfigureResetDomainController/8 (read)Power_Ip_MC_RGM_ConfigureResetDomainController/8 (read)Power_Ip_MC_RGM_ConfigureResetDomainController/8 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Power_Ip_pxMC_RGM/2 (Power_Ip_pxMC_RGM) @0755dea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Power_Ip_MC_RGM_ClearDesResetFlags/5 (read)Power_Ip_MC_RGM_GetResetReason/19 (read)Power_Ip_MC_RGM_CheckConfigureCOFB/10 (read)Power_Ip_MC_RGM_GetResetReason/19 (read)Power_Ip_MC_RGM_CheckConfigureCore/12 (read)Power_Ip_MC_RGM_ClearFesResetFlags/4 (read)Power_Ip_MC_RGM_ConfigureCOFB/9 (read)Power_Ip_MC_RGM_ResetInit/13 (read)Power_Ip_MC_RGM_ReleaseDomainReset/6 (read)Power_Ip_MC_RGM_ResetInit/13 (read)Power_Ip_MC_RGM_AssertDomainReset/7 (read)Power_Ip_MC_RGM_ConfigureCore/11 (read)Power_Ip_MC_RGM_GetResetRawValue/20 (read)Power_Ip_MC_RGM_GetResetRawValue/20 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Power_Ip_u32FesResetStatus/1 (Power_Ip_u32FesResetStatus) @0755ddc8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Power_Ip_MC_RGM_ResetInit/13 (write)Power_Ip_MC_RGM_GetResetReason/19 (write)Power_Ip_MC_RGM_GetResetReason/19 (read)Power_Ip_MC_RGM_GetResetRawValue/20 (write)Power_Ip_MC_RGM_GetResetRawValue/20 (read)
  Availability: available
  Varpool flags:
Power_Ip_u32DesResetStatus/0 (Power_Ip_u32DesResetStatus) @0755dd38
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Power_Ip_MC_RGM_GetResetReason/19 (write)Power_Ip_MC_RGM_GetResetReason/19 (read)Power_Ip_MC_RGM_GetResetRawValue/20 (write)Power_Ip_MC_RGM_GetResetRawValue/20 (read)
  Availability: available
  Varpool flags:

;; Function Power_Ip_MC_RGM_ConfigureResetDomainController (Power_Ip_MC_RGM_ConfigureResetDomainController, funcdef_no=4, decl_uid=6586, cgraph_uid=5, symbol_order=8)

Modification phase of node Power_Ip_MC_RGM_ConfigureResetDomainController/8
Power_Ip_MC_RGM_ConfigureResetDomainController (const struct Power_Ip_MC_RGM_DomainConfigType * ResetDomainConfigPtr)
{
  uint8 DomainIndex;
  boolean TimeoutOccurred;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  uint32 ResetDomainStatus;
  uint32 ResetDomainConfig;
  uint32 TempValue;
  struct Power_Ip_RDC_Type * Power_Ip_pxRdc.16_1;
  int _2;
  long unsigned int TimeoutTicks.20_4;
  struct Power_Ip_RDC_Type * Power_Ip_pxRdc.21_5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  struct Power_Ip_RDC_Type * Power_Ip_pxRdc.22_10;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG TempValue => 0
  # DEBUG BEGIN_STMT
  ResetDomainConfig_15 = ResetDomainConfigPtr_14(D)->DomainRdcRegValue;
  # DEBUG ResetDomainConfig => ResetDomainConfig_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  DomainIndex_16 = ResetDomainConfigPtr_14(D)->DomainIndex;
  # DEBUG DomainIndex => DomainIndex_16
  # DEBUG BEGIN_STMT
  Power_Ip_pxRdc.16_1 = Power_Ip_pxRdc;
  _2 = (int) DomainIndex_16;
  TempValue_17 ={v} Power_Ip_pxRdc.16_1->RDC_CTRL_REG[_2];
  # DEBUG TempValue => TempValue_17
  # DEBUG BEGIN_STMT
  TempValue_18 = TempValue_17 & 2147483647;
  # DEBUG TempValue => TempValue_18
  # DEBUG BEGIN_STMT
  TempValue_19 = TempValue_18 | 2147483648;
  # DEBUG TempValue => TempValue_19
  # DEBUG BEGIN_STMT
  Power_Ip_pxRdc.16_1->RDC_CTRL_REG[_2] ={v} TempValue_19;
  # DEBUG BEGIN_STMT
  TempValue_21 ={v} Power_Ip_pxRdc.16_1->RDC_CTRL_REG[_2];
  # DEBUG TempValue => TempValue_21
  # DEBUG BEGIN_STMT
  TempValue_22 = TempValue_21 & 4294967287;
  # DEBUG TempValue => TempValue_22
  # DEBUG BEGIN_STMT
  TempValue_23 = ResetDomainConfig_15 | TempValue_22;
  # DEBUG TempValue => TempValue_23
  # DEBUG BEGIN_STMT
  Power_Ip_pxRdc.16_1->RDC_CTRL_REG[_2] ={v} TempValue_23;
  # DEBUG BEGIN_STMT
  Power_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.20_4 = TimeoutTicks;
  TimeoutOccurred_27 = Power_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.20_4);
  # DEBUG TimeoutOccurred => TimeoutOccurred_27
  # DEBUG BEGIN_STMT
  Power_Ip_pxRdc.21_5 = Power_Ip_pxRdc;
  ResetDomainStatus_28 ={v} Power_Ip_pxRdc.21_5->RDC_STAT_REG[_2];
  # DEBUG ResetDomainStatus => ResetDomainStatus_28
  # DEBUG BEGIN_STMT
  _6 = ResetDomainStatus_28 >> 4;
  _7 = ResetDomainConfig_15 >> 3;
  _8 = _6 ^ _7;
  _9 = _8 & 1;
  if (_9 != 0)
    goto <bb 4>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 4> [local count: 1014686025]:
  if (TimeoutOccurred_27 != 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 8> [local count: 958878293]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 114863532]:
  # TimeoutOccurred_3 = PHI <TimeoutOccurred_27(3), TimeoutOccurred_27(4)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_3 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  Power_Ip_ReportPowerErrors (0, 255);

  <bb 7> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Power_Ip_pxRdc.22_10 = Power_Ip_pxRdc;
  TempValue_30 ={v} Power_Ip_pxRdc.22_10->RDC_CTRL_REG[_2];
  # DEBUG TempValue => TempValue_30
  # DEBUG BEGIN_STMT
  TempValue_31 = TempValue_30 & 2147483647;
  # DEBUG TempValue => TempValue_31
  # DEBUG BEGIN_STMT
  # DEBUG TempValue => TempValue_31
  # DEBUG BEGIN_STMT
  Power_Ip_pxRdc.22_10->RDC_CTRL_REG[_2] ={v} TempValue_31;
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Power_Ip_MC_RGM_ClearFesResetFlags (Power_Ip_MC_RGM_ClearFesResetFlags, funcdef_no=0, decl_uid=6566, cgraph_uid=1, symbol_order=4)

Modification phase of node Power_Ip_MC_RGM_ClearFesResetFlags/4
Power_Ip_MC_RGM_ClearFesResetFlags (uint32 RegValue)
{
  uint32 RegValueTemp;
  boolean TimeoutOccurred;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  long unsigned int TimeoutTicks.5_1;
  struct Power_Ip_MC_RGM_Type * Power_Ip_pxMC_RGM.6_2;
  long unsigned int _4;

  <bb 2> [local count: 348071309]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG RegValueTemp => RegValue_9(D)
  # DEBUG BEGIN_STMT
  if (RegValue_9(D) != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 3> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Power_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 4> [local count: 1073741824]:
  # RegValueTemp_6 = PHI <RegValue_9(D)(3), RegValueTemp_15(9)>
  # DEBUG RegValueTemp => RegValueTemp_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.5_1 = TimeoutTicks;
  TimeoutOccurred_13 = Power_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.5_1);
  # DEBUG TimeoutOccurred => TimeoutOccurred_13
  # DEBUG BEGIN_STMT
  Power_Ip_pxMC_RGM.6_2 = Power_Ip_pxMC_RGM;
  Power_Ip_pxMC_RGM.6_2->FES ={v} RegValueTemp_6;
  # DEBUG BEGIN_STMT
  _4 ={v} Power_Ip_pxMC_RGM.6_2->FES;
  RegValueTemp_15 = _4 & 3224633433;
  # DEBUG RegValueTemp => RegValueTemp_15
  # DEBUG BEGIN_STMT
  if (RegValueTemp_15 != 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686025]:
  if (TimeoutOccurred_13 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 9> [local count: 958878294]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 114863532]:
  # TimeoutOccurred_3 = PHI <TimeoutOccurred_13(4), TimeoutOccurred_13(5)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_3 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 37904965]:
  # DEBUG D#3 => RegValue_9(D)
  Power_Ip_MC_RGM_ClearFesResetFlags.part.0 ();

  <bb 8> [local count: 348071309]:
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Power_Ip_MC_RGM_ClearDesResetFlags (Power_Ip_MC_RGM_ClearDesResetFlags, funcdef_no=1, decl_uid=6568, cgraph_uid=2, symbol_order=5)

Modification phase of node Power_Ip_MC_RGM_ClearDesResetFlags/5
Adjusting mask for param 0 to 0xc0073f5b
Setting value range of param 0 [0, -1073266853]
Power_Ip_MC_RGM_ClearDesResetFlags (uint32 RegValue)
{
  uint32 RegValueTemp;
  boolean TimeoutOccurred;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  long unsigned int TimeoutTicks.30_1;
  struct Power_Ip_MC_RGM_Type * Power_Ip_pxMC_RGM.31_2;
  long unsigned int _4;

  <bb 2> [local count: 348071309]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG RegValueTemp => RegValue_9(D)
  # DEBUG BEGIN_STMT
  if (RegValue_9(D) != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 3> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Power_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 4> [local count: 1073741824]:
  # RegValueTemp_6 = PHI <RegValue_9(D)(3), RegValueTemp_15(9)>
  # DEBUG RegValueTemp => RegValueTemp_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.30_1 = TimeoutTicks;
  TimeoutOccurred_13 = Power_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.30_1);
  # DEBUG TimeoutOccurred => TimeoutOccurred_13
  # DEBUG BEGIN_STMT
  Power_Ip_pxMC_RGM.31_2 = Power_Ip_pxMC_RGM;
  Power_Ip_pxMC_RGM.31_2->DES ={v} RegValueTemp_6;
  # DEBUG BEGIN_STMT
  _4 ={v} Power_Ip_pxMC_RGM.31_2->DES;
  RegValueTemp_15 = _4 & 3221700443;
  # DEBUG RegValueTemp => RegValueTemp_15
  # DEBUG BEGIN_STMT
  if (RegValueTemp_15 != 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686025]:
  if (TimeoutOccurred_13 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 9> [local count: 958878294]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 114863532]:
  # TimeoutOccurred_3 = PHI <TimeoutOccurred_13(4), TimeoutOccurred_13(5)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_3 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 37904965]:
  # DEBUG D#5 => RegValue_9(D)
  Power_Ip_MC_RGM_ClearDesResetFlags.part.0 ();

  <bb 8> [local count: 348071309]:
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}



;; Function Power_Ip_MC_RGM_ResetInit (Power_Ip_MC_RGM_ResetInit, funcdef_no=9, decl_uid=6511, cgraph_uid=10, symbol_order=13)

Modification phase of node Power_Ip_MC_RGM_ResetInit/13
Power_Ip_MC_RGM_ResetInit (const struct Power_Ip_MC_RGM_ConfigType * ConfigPtr)
{
  uint32 DesResetReason;
  uint32 FesResetReason;
  struct Power_Ip_MC_RGM_Type * Power_Ip_pxMC_RGM.0_1;
  struct Power_Ip_MC_RGM_Type * Power_Ip_pxMC_RGM.1_2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG FesResetReason => 0
  # DEBUG BEGIN_STMT
  # DEBUG DesResetReason => 0
  # DEBUG BEGIN_STMT
  Power_Ip_pxMC_RGM.0_1 = Power_Ip_pxMC_RGM;
  FesResetReason_11 ={v} Power_Ip_pxMC_RGM.0_1->FES;
  # DEBUG FesResetReason => FesResetReason_11
  # DEBUG BEGIN_STMT
  if (FesResetReason_11 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Power_Ip_u32FesResetStatus = FesResetReason_11;
  # DEBUG BEGIN_STMT
  Power_Ip_MC_RGM_ClearFesResetFlags (FesResetReason_11);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Power_Ip_pxMC_RGM.1_2 = Power_Ip_pxMC_RGM;
  _3 = ConfigPtr_14(D)->FuncResetOpt;
  Power_Ip_pxMC_RGM.1_2->FERD ={v} _3;
  # DEBUG BEGIN_STMT
  DesResetReason_16 ={v} Power_Ip_pxMC_RGM.1_2->DES;
  # DEBUG DesResetReason => DesResetReason_16
  # DEBUG BEGIN_STMT
  if (DesResetReason_16 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _4 = ConfigPtr_14(D)->FesThresholdReset;
  Power_Ip_pxMC_RGM.1_2->FRET ={v} _4;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = DesResetReason_16 & 1;
  if (_5 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _6 = ConfigPtr_14(D)->DesThresholdReset;
  Power_Ip_pxMC_RGM.1_2->DRET ={v} _6;

  <bb 8> [local count: 1073741824]:
  return;

}



;; Function Power_Ip_MC_RGM_ModeConfig (Power_Ip_MC_RGM_ModeConfig, funcdef_no=10, decl_uid=6518, cgraph_uid=11, symbol_order=14)

Modification phase of node Power_Ip_MC_RGM_ModeConfig/14
Power_Ip_MC_RGM_ModeConfig (const struct Power_Ip_MC_RGM_ModeConfigType * ModeConfigPtr, uint8 DomainIndex)
{
  uint8 CoreIndex;
  uint8 CofbIndex;
  const struct Power_Ip_MC_RGM_DomainConfigType[4] * _1;
  int _2;
  _Bool _3;
  const struct Power_Ip_MC_RGM_CofbConfigType[<unknown>] * _4;
  int _5;
  _Bool _6;
  const struct Power_Ip_MC_RGM_CofbConfigType * _7;
  unsigned char _8;
  unsigned char _9;
  const struct Power_Ip_MC_RGM_CoreConfigType[<unknown>] * _10;
  int _11;
  _Bool _12;
  const struct Power_Ip_MC_RGM_CoreConfigType * _13;
  unsigned char _14;
  unsigned char _15;

  <bb 2> [local count: 236223204]:
  # DEBUG BEGIN_STMT
  # DEBUG TempDomainConfigPtr => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = ModeConfigPtr_24(D)->ArrayDomainConfigPtr;
  _2 = (int) DomainIndex_25(D);
  # DEBUG D#7 => &*_1[_2]
  # DEBUG TempDomainConfigPtr => D#7
  # DEBUG BEGIN_STMT
  _3 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainUnderMcuControl;
  if (_3 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 13> [local count: 118111602]:
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _4 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].ArrayDomainCofbConfigPtr;
  _5 = (int) CofbIndex_16;
  _6 = *_4[_5].CofbUnderMcuControl;
  if (_6 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 315357973]:
  # DEBUG BEGIN_STMT
  _7 = &*_4[_5];
  _8 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainIndex;
  Power_Ip_MC_RGM_ConfigureCOFB (_7, _8);

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  CofbIndex_29 = CofbIndex_16 + 1;
  # DEBUG CofbIndex => CofbIndex_29

  <bb 6> [local count: 1073741824]:
  # CofbIndex_16 = PHI <CofbIndex_29(5), 0(13)>
  # DEBUG CofbIndex => CofbIndex_16
  # DEBUG BEGIN_STMT
  _9 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].NumberOfCofbs;
  if (_9 > CofbIndex_16)
    goto <bb 3>; [89.00%]
  else
    goto <bb 12>; [11.00%]

  <bb 12> [local count: 118111601]:
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 955630215]:
  # DEBUG BEGIN_STMT
  _10 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].ArrayDomainCoreConfigPtr;
  _11 = (int) CoreIndex_17;
  _12 = *_10[_11].CoreUnderMcuControl;
  if (_12 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 315357971]:
  # DEBUG BEGIN_STMT
  _13 = &*_10[_11];
  _14 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainIndex;
  Power_Ip_MC_RGM_ConfigureCore (_13, _14);

  <bb 9> [local count: 955630215]:
  # DEBUG BEGIN_STMT
  CoreIndex_27 = CoreIndex_17 + 1;
  # DEBUG CoreIndex => CoreIndex_27

  <bb 10> [local count: 1073741813]:
  # CoreIndex_17 = PHI <CoreIndex_27(9), 0(12)>
  # DEBUG CoreIndex => CoreIndex_17
  # DEBUG BEGIN_STMT
  _15 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].NumberOfCores;
  if (_15 > CoreIndex_17)
    goto <bb 7>; [89.00%]
  else
    goto <bb 11>; [11.00%]

  <bb 11> [local count: 236223201]:
  return;

}



;; Function Power_Ip_MC_RGM_CheckModeConfig (Power_Ip_MC_RGM_CheckModeConfig, funcdef_no=11, decl_uid=6521, cgraph_uid=12, symbol_order=15)

Modification phase of node Power_Ip_MC_RGM_CheckModeConfig/15
Power_Ip_MC_RGM_CheckModeConfig (const struct Power_Ip_MC_RGM_ModeConfigType * ModeConfigPtr, uint8 DomainIndex)
{
  uint8 CoreIndex;
  uint8 CofbIndex;
  const struct Power_Ip_MC_RGM_DomainConfigType[4] * _1;
  int _2;
  _Bool _3;
  const struct Power_Ip_MC_RGM_CofbConfigType[<unknown>] * _4;
  int _5;
  _Bool _6;
  const struct Power_Ip_MC_RGM_CofbConfigType * _7;
  unsigned char _8;
  unsigned char _9;
  const struct Power_Ip_MC_RGM_CoreConfigType[<unknown>] * _10;
  int _11;
  _Bool _12;
  const struct Power_Ip_MC_RGM_CoreConfigType * _13;
  unsigned char _14;
  unsigned char _15;

  <bb 2> [local count: 236223204]:
  # DEBUG BEGIN_STMT
  # DEBUG TempDomainConfigPtr => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = ModeConfigPtr_24(D)->ArrayDomainConfigPtr;
  _2 = (int) DomainIndex_25(D);
  # DEBUG D#8 => &*_1[_2]
  # DEBUG TempDomainConfigPtr => D#8
  # DEBUG BEGIN_STMT
  _3 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainUnderMcuControl;
  if (_3 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 13> [local count: 118111602]:
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _4 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].ArrayDomainCofbConfigPtr;
  _5 = (int) CofbIndex_16;
  _6 = *_4[_5].CofbUnderMcuControl;
  if (_6 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 315357973]:
  # DEBUG BEGIN_STMT
  _7 = &*_4[_5];
  _8 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainIndex;
  Power_Ip_MC_RGM_CheckConfigureCOFB (_7, _8);

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  CofbIndex_29 = CofbIndex_16 + 1;
  # DEBUG CofbIndex => CofbIndex_29

  <bb 6> [local count: 1073741824]:
  # CofbIndex_16 = PHI <CofbIndex_29(5), 0(13)>
  # DEBUG CofbIndex => CofbIndex_16
  # DEBUG BEGIN_STMT
  _9 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].NumberOfCofbs;
  if (_9 > CofbIndex_16)
    goto <bb 3>; [89.00%]
  else
    goto <bb 12>; [11.00%]

  <bb 12> [local count: 118111601]:
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 955630215]:
  # DEBUG BEGIN_STMT
  _10 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].ArrayDomainCoreConfigPtr;
  _11 = (int) CoreIndex_17;
  _12 = *_10[_11].CoreUnderMcuControl;
  if (_12 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 315357971]:
  # DEBUG BEGIN_STMT
  _13 = &*_10[_11];
  _14 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainIndex;
  Power_Ip_MC_RGM_CheckConfigureCore (_13, _14);

  <bb 9> [local count: 955630215]:
  # DEBUG BEGIN_STMT
  CoreIndex_27 = CoreIndex_17 + 1;
  # DEBUG CoreIndex => CoreIndex_27

  <bb 10> [local count: 1073741813]:
  # CoreIndex_17 = PHI <CoreIndex_27(9), 0(12)>
  # DEBUG CoreIndex => CoreIndex_17
  # DEBUG BEGIN_STMT
  _15 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].NumberOfCores;
  if (_15 > CoreIndex_17)
    goto <bb 7>; [89.00%]
  else
    goto <bb 11>; [11.00%]

  <bb 11> [local count: 236223201]:
  return;

}



;; Function Power_Ip_MC_RGM_EnableResetDomain (Power_Ip_MC_RGM_EnableResetDomain, funcdef_no=12, decl_uid=6524, cgraph_uid=13, symbol_order=16)

Modification phase of node Power_Ip_MC_RGM_EnableResetDomain/16
Power_Ip_MC_RGM_EnableResetDomain (const struct Power_Ip_MC_RGM_ModeConfigType * ModeConfigPtr, uint8 DomainIndex)
{
  const struct Power_Ip_MC_RGM_DomainConfigType * TempDomainConfigPtr;
  const struct Power_Ip_MC_RGM_DomainConfigType[4] * _1;
  int _2;
  _Bool _3;
  unsigned char _4;
  _Bool _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned char _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG TempDomainConfigPtr => 0B
  # DEBUG BEGIN_STMT
  _1 = ModeConfigPtr_11(D)->ArrayDomainConfigPtr;
  _2 = (int) DomainIndex_12(D);
  TempDomainConfigPtr_13 = &*_1[_2];
  # DEBUG TempDomainConfigPtr => TempDomainConfigPtr_13
  # DEBUG BEGIN_STMT
  _3 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainUnderMcuControl;
  if (_3 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _4 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainIndex;
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  _5 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainPowerUnderMcuControl;
  if (_5 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 134217728]:
  # DEBUG BEGIN_STMT
  _6 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainRdcRegValue;
  _7 = _6 & 8;
  if (_7 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 44291850]:
  # DEBUG BEGIN_STMT
  Power_Ip_MC_RGM_ConfigureResetDomainController (TempDomainConfigPtr_13);
  # DEBUG BEGIN_STMT
  _8 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainIndex;
  Power_Ip_MC_RGM_ReleaseDomainReset (_8);

  <bb 7> [local count: 1073741824]:
  return;

}



;; Function Power_Ip_MC_RGM_DisableResetDomain (Power_Ip_MC_RGM_DisableResetDomain, funcdef_no=13, decl_uid=6527, cgraph_uid=14, symbol_order=17)

Modification phase of node Power_Ip_MC_RGM_DisableResetDomain/17
Power_Ip_MC_RGM_DisableResetDomain (const struct Power_Ip_MC_RGM_ModeConfigType * ModeConfigPtr, uint8 DomainIndex)
{
  const struct Power_Ip_MC_RGM_DomainConfigType * TempDomainConfigPtr;
  const struct Power_Ip_MC_RGM_DomainConfigType[4] * _1;
  int _2;
  _Bool _3;
  unsigned char _4;
  _Bool _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG TempDomainConfigPtr => 0B
  # DEBUG BEGIN_STMT
  _1 = ModeConfigPtr_10(D)->ArrayDomainConfigPtr;
  _2 = (int) DomainIndex_11(D);
  TempDomainConfigPtr_12 = &*_1[_2];
  # DEBUG TempDomainConfigPtr => TempDomainConfigPtr_12
  # DEBUG BEGIN_STMT
  _3 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainUnderMcuControl;
  if (_3 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _4 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainIndex;
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  _5 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainPowerUnderMcuControl;
  if (_5 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 134217728]:
  # DEBUG BEGIN_STMT
  _6 = MEM[(const struct Power_Ip_MC_RGM_DomainConfigType *)_1][_2].DomainRdcRegValue;
  _7 = _6 & 8;
  if (_7 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 44291850]:
  # DEBUG BEGIN_STMT
  Power_Ip_MC_RGM_AssertDomainReset (_4);
  # DEBUG BEGIN_STMT
  Power_Ip_MC_RGM_ConfigureResetDomainController (TempDomainConfigPtr_12);

  <bb 7> [local count: 1073741824]:
  return;

}



;; Function Power_Ip_MC_RGM_GetResetReason (Power_Ip_MC_RGM_GetResetReason, funcdef_no=15, decl_uid=6513, cgraph_uid=16, symbol_order=19)

Modification phase of node Power_Ip_MC_RGM_GetResetReason/19
Power_Ip_MC_RGM_GetResetReason ()
{
  uint32 Position;
  uint32 ActiveValue;
  uint32 RegValue;
  Power_Ip_ResetType ResetReason;
  struct Power_Ip_MC_RGM_Type * Power_Ip_pxMC_RGM.28_1;
  long unsigned int _2;
  struct Power_Ip_MC_RGM_Type * Power_Ip_pxMC_RGM.29_3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG RegValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Position = 0;
  # DEBUG BEGIN_STMT
  Power_Ip_pxMC_RGM.28_1 = Power_Ip_pxMC_RGM;
  _2 ={v} Power_Ip_pxMC_RGM.28_1->DES;
  RegValue_13 = _2 & 3221700443;
  # DEBUG RegValue => RegValue_13
  # DEBUG BEGIN_STMT
  if (RegValue_13 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Power_Ip_u32DesResetStatus = RegValue_13;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ActiveValue_15 = Power_Ip_u32DesResetStatus;
  # DEBUG ActiveValue => ActiveValue_15
  # DEBUG BEGIN_STMT
  ResetReason_17 = Power_Ip_MC_RGM_CheckResetReason (ActiveValue_15, 0, &Position);
  # DEBUG ResetReason => ResetReason_17
  # DEBUG BEGIN_STMT
  Power_Ip_MC_RGM_ClearDesResetFlags (RegValue_13);
  # DEBUG BEGIN_STMT
  if (RegValue_13 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Power_Ip_pxMC_RGM.29_3 = Power_Ip_pxMC_RGM;
  _4 ={v} Power_Ip_pxMC_RGM.29_3->FES;
  RegValue_19 = _4 & 3224633433;
  # DEBUG RegValue => RegValue_19
  # DEBUG BEGIN_STMT
  if (RegValue_19 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  Power_Ip_u32FesResetStatus = RegValue_19;

  <bb 7> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  ActiveValue_21 = Power_Ip_u32FesResetStatus;
  # DEBUG ActiveValue => ActiveValue_21
  # DEBUG BEGIN_STMT
  if (ActiveValue_21 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  ResetReason_23 = Power_Ip_MC_RGM_CheckResetReason (ActiveValue_21, 1, &Position);
  # DEBUG ResetReason => ResetReason_23

  <bb 9> [local count: 536870913]:
  # ResetReason_5 = PHI <ResetReason_17(7), ResetReason_23(8)>
  # DEBUG ResetReason => ResetReason_5
  # DEBUG BEGIN_STMT
  Power_Ip_MC_RGM_ClearFesResetFlags (RegValue_19);

  <bb 10> [local count: 1073741824]:
  # ResetReason_6 = PHI <ResetReason_17(4), ResetReason_5(9)>
  # DEBUG ResetReason => ResetReason_6
  # DEBUG BEGIN_STMT
  Position ={v} {CLOBBER};
  return ResetReason_6;

}



;; Function Power_Ip_MC_RGM_GetResetRawValue (Power_Ip_MC_RGM_GetResetRawValue, funcdef_no=16, decl_uid=6515, cgraph_uid=17, symbol_order=20)

Modification phase of node Power_Ip_MC_RGM_GetResetRawValue/20
Power_Ip_MC_RGM_GetResetRawValue ()
{
  uint32 Position;
  uint32 DynamicMask;
  uint32 Index;
  uint32 ActiveValue;
  uint32 RegValue;
  uint32 RawReset;
  struct Power_Ip_MC_RGM_Type * Power_Ip_pxMC_RGM.33_1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  struct Power_Ip_MC_RGM_Type * Power_Ip_pxMC_RGM.34_6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 65068756]:
  # DEBUG BEGIN_STMT
  # DEBUG RawReset => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Power_Ip_pxMC_RGM.33_1 = Power_Ip_pxMC_RGM;
  _2 ={v} Power_Ip_pxMC_RGM.33_1->FES;
  RegValue_31 = _2 & 3224633433;
  # DEBUG RegValue => RegValue_31
  # DEBUG BEGIN_STMT
  if (RegValue_31 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 32534378]:
  # DEBUG BEGIN_STMT
  Power_Ip_u32FesResetStatus = RegValue_31;

  <bb 4> [local count: 65068756]:
  # DEBUG BEGIN_STMT
  # DEBUG ResetMask => 3224633433
  # DEBUG BEGIN_STMT
  ActiveValue_33 = Power_Ip_u32FesResetStatus;
  # DEBUG ActiveValue => ActiveValue_33
  # DEBUG BEGIN_STMT
  if (ActiveValue_33 != 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 24> [local count: 32534378]:
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 1041207447]:
  # DEBUG BEGIN_STMT
  DynamicMask_35 = 1 << Index_19;
  # DEBUG DynamicMask => DynamicMask_35
  # DEBUG BEGIN_STMT
  _3 = DynamicMask_35 & 3224633433;
  if (_3 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 6> [local count: 520603723]:
  # DEBUG BEGIN_STMT
  _4 = ActiveValue_33 & DynamicMask_35;
  if (_4 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 260301862]:
  # DEBUG BEGIN_STMT
  _5 = 1 << Position_22;
  RawReset_36 = _5 | RawReset_13;
  # DEBUG RawReset => RawReset_36

  <bb 8> [local count: 520603723]:
  # RawReset_11 = PHI <RawReset_13(6), RawReset_36(7)>
  # DEBUG RawReset => RawReset_11
  # DEBUG BEGIN_STMT
  Position_37 = Position_22 + 1;
  # DEBUG Position => Position_37

  <bb 9> [local count: 1041207447]:
  # RawReset_12 = PHI <RawReset_13(5), RawReset_11(8)>
  # Position_21 = PHI <Position_22(5), Position_37(8)>
  # DEBUG Position => Position_21
  # DEBUG RawReset => RawReset_12
  # DEBUG BEGIN_STMT
  Index_38 = Index_19 + 1;
  # DEBUG Index => Index_38

  <bb 10> [local count: 1073741824]:
  # RawReset_13 = PHI <RawReset_12(9), 0(24)>
  # Index_19 = PHI <Index_38(9), 0(24)>
  # Position_22 = PHI <Position_21(9), 0(24)>
  # DEBUG Position => Position_22
  # DEBUG Index => Index_19
  # DEBUG RawReset => RawReset_13
  # DEBUG BEGIN_STMT
  if (Index_19 != 32)
    goto <bb 5>; [96.97%]
  else
    goto <bb 11>; [3.03%]

  <bb 11> [local count: 32534377]:
  # RawReset_47 = PHI <RawReset_13(10)>
  # DEBUG BEGIN_STMT
  Power_Ip_MC_RGM_ClearFesResetFlags (RegValue_31);

  <bb 12> [local count: 65068755]:
  # RawReset_14 = PHI <0(4), RawReset_47(11)>
  # DEBUG RawReset => RawReset_14
  # DEBUG BEGIN_STMT
  Power_Ip_pxMC_RGM.34_6 = Power_Ip_pxMC_RGM;
  _7 ={v} Power_Ip_pxMC_RGM.34_6->DES;
  RegValue_39 = _7 & 3221700443;
  # DEBUG RegValue => RegValue_39
  # DEBUG BEGIN_STMT
  if (RegValue_39 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 32534378]:
  # DEBUG BEGIN_STMT
  Power_Ip_u32DesResetStatus = RegValue_39;

  <bb 14> [local count: 65068755]:
  # DEBUG BEGIN_STMT
  ActiveValue_41 = Power_Ip_u32DesResetStatus;
  # DEBUG ActiveValue => ActiveValue_41
  # DEBUG BEGIN_STMT
  if (ActiveValue_41 != 0)
    goto <bb 23>; [50.00%]
  else
    goto <bb 22>; [50.00%]

  <bb 23> [local count: 32534378]:
  goto <bb 20>; [100.00%]

  <bb 15> [local count: 1041207436]:
  # DEBUG BEGIN_STMT
  DynamicMask_43 = 1 << Index_20;
  # DEBUG DynamicMask => DynamicMask_43
  # DEBUG BEGIN_STMT
  _8 = DynamicMask_43 & 3221700443;
  if (_8 != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 16> [local count: 520603718]:
  # DEBUG BEGIN_STMT
  _9 = ActiveValue_41 & DynamicMask_43;
  if (_9 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 17> [local count: 260301859]:
  # DEBUG BEGIN_STMT
  _10 = 1 << Position_24;
  RawReset_44 = _10 | RawReset_17;
  # DEBUG RawReset => RawReset_44

  <bb 18> [local count: 520603718]:
  # RawReset_15 = PHI <RawReset_17(16), RawReset_44(17)>
  # DEBUG RawReset => RawReset_15
  # DEBUG BEGIN_STMT
  Position_45 = Position_24 + 1;
  # DEBUG Position => Position_45

  <bb 19> [local count: 1041207436]:
  # RawReset_16 = PHI <RawReset_17(15), RawReset_15(18)>
  # Position_23 = PHI <Position_24(15), Position_45(18)>
  # DEBUG Position => Position_23
  # DEBUG RawReset => RawReset_16
  # DEBUG BEGIN_STMT
  Index_46 = Index_20 + 1;
  # DEBUG Index => Index_46

  <bb 20> [local count: 1073741814]:
  # RawReset_17 = PHI <RawReset_16(19), RawReset_14(23)>
  # Index_20 = PHI <Index_46(19), 0(23)>
  # Position_24 = PHI <Position_23(19), 16(23)>
  # DEBUG Position => Position_24
  # DEBUG Index => Index_20
  # DEBUG RawReset => RawReset_17
  # DEBUG BEGIN_STMT
  if (Index_20 != 32)
    goto <bb 15>; [96.97%]
  else
    goto <bb 21>; [3.03%]

  <bb 21> [local count: 32534377]:
  # RawReset_29 = PHI <RawReset_17(20)>
  # DEBUG BEGIN_STMT
  Power_Ip_MC_RGM_ClearDesResetFlags (RegValue_39);

  <bb 22> [local count: 65068755]:
  # RawReset_18 = PHI <RawReset_14(14), RawReset_29(21)>
  # DEBUG RawReset => RawReset_18
  # DEBUG BEGIN_STMT
  return RawReset_18;

}


