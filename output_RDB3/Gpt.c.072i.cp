
IPA constant propagation start:
Determining dynamic type for call: _2 = Gpt_ValidateParamPtrInit (configPtr_15(D));
  Starting walk at: _2 = Gpt_ValidateParamPtrInit (configPtr_15(D));
  instance pointer: configPtr_15(D)  Outer instance pointer: configPtr_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = Gpt_ValidateGlobalCall (1, 0);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Gpt_ValidateChannelStatus.part.0/37:
  Jump functions of caller  Gpt_ValidateChannelNotification.part.0/36:
  Jump functions of caller  Gpt_ValidateChannelCall.part.0/35:
  Jump functions of caller  Gpt_ValidateGlobalCall.part.0/34:
  Jump functions of caller  Gpt_Ipw_DisableInterrupt/33:
  Jump functions of caller  Gpt_Ipw_StopTimer/32:
  Jump functions of caller  Gpt_Ipw_StartTimer/31:
  Jump functions of caller  Gpt_Ipw_EnableInterrupt/30:
  Jump functions of caller  Gpt_Ipw_GetTimeElapsed/29:
  Jump functions of caller  Det_ReportRuntimeError/28:
  Jump functions of caller  Gpt_Ipw_DeInit/27:
  Jump functions of caller  Gpt_Ipw_Init/26:
  Jump functions of caller  Gpt_Ipw_InitInstances/25:
  Jump functions of caller  Det_ReportError/23:
  Jump functions of caller  Gpt_ProcessCommonInterrupt/22:
    indirect simple callsite, calling param -1, offset 0, for stmt _9 ();
  Jump functions of caller  Gpt_DisableNotification/21:
    callsite  Gpt_DisableNotification/21 -> Gpt_ValidateChannelNotification/8 : 
       param 0: CONST: 8
         value: 0x8, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gpt_DisableNotification/21 -> Gpt_ValidateChannelCall/6 : 
       param 0: CONST: 8
         value: 0x8, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Gpt_EnableNotification/20:
    callsite  Gpt_EnableNotification/20 -> Gpt_ValidateChannelNotification/8 : 
       param 0: CONST: 7
         value: 0x7, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gpt_EnableNotification/20 -> Gpt_ValidateChannelCall/6 : 
       param 0: CONST: 7
         value: 0x7, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Gpt_StopTimer/19:
    callsite  Gpt_StopTimer/19 -> Gpt_ValidateChannelCall/6 : 
       param 0: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Gpt_StartTimer/18:
    callsite  Gpt_StartTimer/18 -> Gpt_ValidateParamValue/10 : 
       param 0: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gpt_StartTimer/18 -> Gpt_ValidateChannelStatus/9 : 
       param 0: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Gpt_GetTimeRemaining/17:
    callsite  Gpt_GetTimeRemaining/17 -> Gpt_ValidateChannelCall/6 : 
       param 0: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Gpt_GetTimeElapsed/16:
    callsite  Gpt_GetTimeElapsed/16 -> Gpt_ValidateChannelCall/6 : 
       param 0: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Gpt_DeInit/15:
    callsite  Gpt_DeInit/15 -> Gpt_ConvertChannelIndexToChannel/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gpt_DeInit/15 -> Gpt_ValidateChannelStatus/9 : 
       param 0: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gpt_DeInit/15 -> Gpt_ConvertChannelIndexToChannel/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gpt_DeInit/15 -> Gpt_ValidateGlobalCall/7 : 
       param 0: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Gpt_Init/14:
    callsite  Gpt_Init/14 -> Gpt_ConvertChannelIndexToChannel/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gpt_Init/14 -> Gpt_ValidateParamPtrInit/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Gpt_Init/14 -> Gpt_ValidateGlobalCall/7 : 
       param 0: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Gpt_GetVersionInfo/13:
  Jump functions of caller  Gpt_ConvertChannelIndexToChannel/12:
  Jump functions of caller  Gpt_ValidateParamPtrInit/11:
  Jump functions of caller  Gpt_ValidateParamValue/10:
  Jump functions of caller  Gpt_ValidateChannelStatus/9:
    callsite  Gpt_ValidateChannelStatus/9 -> Gpt_ValidateChannelStatus.part.0/37 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Gpt_ValidateChannelStatus/9 -> Gpt_ValidateChannelCall/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Gpt_ValidateChannelNotification/8:
    callsite  Gpt_ValidateChannelNotification/8 -> Gpt_ValidateChannelNotification.part.0/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Gpt_ValidateGlobalCall/7:
    callsite  Gpt_ValidateGlobalCall/7 -> Gpt_ValidateGlobalCall.part.0/34 : 
  Jump functions of caller  Gpt_ValidateChannelCall/6:
    callsite  Gpt_ValidateChannelCall/6 -> Gpt_ValidateChannelCall.part.0/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR

 Propagating constants:

Not considering Gpt_ProcessCommonInterrupt for cloning; -fipa-cp-clone disabled.
Not considering Gpt_DisableNotification for cloning; -fipa-cp-clone disabled.
Not considering Gpt_EnableNotification for cloning; -fipa-cp-clone disabled.
Not considering Gpt_StopTimer for cloning; -fipa-cp-clone disabled.
Not considering Gpt_StartTimer for cloning; -fipa-cp-clone disabled.
Not considering Gpt_GetTimeRemaining for cloning; -fipa-cp-clone disabled.
Not considering Gpt_GetTimeElapsed for cloning; -fipa-cp-clone disabled.
Not considering Gpt_DeInit for cloning; -fipa-cp-clone disabled.
Not considering Gpt_Init for cloning; -fipa-cp-clone disabled.
Not considering Gpt_GetVersionInfo for cloning; -fipa-cp-clone disabled.

overall_size: 496, max_new_size: 11001
 - context independent values, size: 8, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 15, time_benefit: 2.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 16, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 11, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 15, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 19, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: Gpt_ValidateChannelStatus.part.0/37:
    param [0]: 5 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               2 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x5, mask = 0x7
         uint8 [2, 5]
        AGGS VARIABLE
  Node: Gpt_ValidateChannelNotification.part.0/36:
    param [0]: 8 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               7 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x8, mask = 0xf
         uint8 [7, 8]
        AGGS VARIABLE
  Node: Gpt_ValidateChannelCall.part.0/35:
    param [0]: 8 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               7 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               6 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               4 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               3 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               2 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               5 [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x8, mask = 0xf
         uint8 [2, 8]
        AGGS VARIABLE
  Node: Gpt_ValidateGlobalCall.part.0/34:
  Node: Gpt_ProcessCommonInterrupt/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_DisableNotification/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_EnableNotification/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_StopTimer/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_StartTimer/18:
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
  Node: Gpt_GetTimeRemaining/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_GetTimeElapsed/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_DeInit/15:
  Node: Gpt_Init/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_GetVersionInfo/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_ConvertChannelIndexToChannel/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint32 [0, 0]
        AGGS VARIABLE
  Node: Gpt_ValidateParamPtrInit/11:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gpt_ValidateParamValue/10:
    param [0]: 5 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x5, mask = 0x0
         uint8 [5, 5]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint32 [0, 0]
        AGGS VARIABLE
  Node: Gpt_ValidateChannelStatus/9:
    param [0]: 2 [loc_time: 2, loc_size: 18, prop_time: 0, prop_size: 0]
               5 [loc_time: 2, loc_size: 18, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x5, mask = 0x7
         uint8 [2, 5]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint32 [0, 0]
        AGGS VARIABLE
  Node: Gpt_ValidateChannelNotification/8:
    param [0]: 7 [loc_time: 2, loc_size: 13, prop_time: 0, prop_size: 0]
               8 [loc_time: 2, loc_size: 13, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x8, mask = 0xf
         uint8 [7, 8]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint32 [0, 0]
        AGGS VARIABLE
  Node: Gpt_ValidateGlobalCall/7:
    param [0]: 1 [loc_time: 4, loc_size: 8, prop_time: 0, prop_size: 0]
               2 [loc_time: 4, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x2, mask = 0x3
         uint8 [1, 2]
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint32 [0, 0]
        AGGS VARIABLE
  Node: Gpt_ValidateChannelCall/6:
    param [0]: 5 [loc_time: 2, loc_size: 25, prop_time: 0, prop_size: 0]
               2 [loc_time: 2, loc_size: 25, prop_time: 0, prop_size: 0]
               3 [loc_time: 2, loc_size: 25, prop_time: 0, prop_size: 0]
               4 [loc_time: 2, loc_size: 25, prop_time: 0, prop_size: 0]
               6 [loc_time: 2, loc_size: 25, prop_time: 0, prop_size: 0]
               7 [loc_time: 2, loc_size: 25, prop_time: 0, prop_size: 0]
               8 [loc_time: 2, loc_size: 25, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x8, mask = 0xf
         uint8 [2, 8]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint32 [0, 0]
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of Gpt_ConvertChannelIndexToChannel/12 for all known contexts.
    replacing param #1 coreID with const 0
 - Creating a specialized node of Gpt_ValidateParamValue/10 for all known contexts.
    replacing param #0 u8ServiceId with const 5
    replacing param #3 coreID with const 0
 - Creating a specialized node of Gpt_ValidateChannelStatus/9 for all known contexts.
    replacing param #2 coreID with const 0
 - Creating a specialized node of Gpt_ValidateChannelNotification/8 for all known contexts.
    replacing param #2 coreID with const 0
 - Creating a specialized node of Gpt_ValidateGlobalCall/7 for all known contexts.
    replacing param #1 coreID with const 0
 - Creating a specialized node of Gpt_ValidateChannelCall/6 for all known contexts.
    replacing param #2 coreID with const 0
Propagated bits info for function Gpt_ValidateChannelCall.constprop/43:
 param 0: value = 0x8, mask = 0xf
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateGlobalCall.constprop/42:
 param 0: value = 0x2, mask = 0x3
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateChannelNotification.constprop/41:
 param 0: value = 0x8, mask = 0xf
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateChannelStatus.constprop/40:
 param 0: value = 0x5, mask = 0x7
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateParamValue.constprop/39:
 param 0: value = 0x5, mask = 0x0
 param 3: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ConvertChannelIndexToChannel.constprop/38:
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateChannelStatus.part.0/37:
 param 0: value = 0x5, mask = 0x7
Propagated bits info for function Gpt_ValidateChannelNotification.part.0/36:
 param 0: value = 0x8, mask = 0xf
Propagated bits info for function Gpt_ValidateChannelCall.part.0/35:
 param 0: value = 0x8, mask = 0xf
Propagated bits info for function Gpt_ConvertChannelIndexToChannel/12:
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateParamValue/10:
 param 0: value = 0x5, mask = 0x0
 param 3: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateChannelStatus/9:
 param 0: value = 0x5, mask = 0x7
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateChannelNotification/8:
 param 0: value = 0x8, mask = 0xf
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateGlobalCall/7:
 param 0: value = 0x2, mask = 0x3
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function Gpt_ValidateChannelCall/6:
 param 0: value = 0x8, mask = 0xf
 param 2: value = 0x0, mask = 0x0

IPA constant propagation end

Reclaiming functions: Gpt_ConvertChannelIndexToChannel/12 Gpt_ValidateParamValue/10 Gpt_ValidateChannelStatus/9 Gpt_ValidateChannelNotification/8 Gpt_ValidateGlobalCall/7 Gpt_ValidateChannelCall/6
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Gpt_ValidateChannelCall.constprop.0/43 (Gpt_ValidateChannelCall.constprop) @072f99a0
  Type: function definition analyzed
  Visibility:
  References: Gpt_pConfig/3 (read)
  Referring: 
  Clone of Gpt_ValidateChannelCall/6
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: Gpt_GetTimeElapsed/16 (1073741824 (estimated locally),1.00 per call) Gpt_GetTimeRemaining/17 (1073741824 (estimated locally),1.00 per call) Gpt_StopTimer/19 (1073741824 (estimated locally),1.00 per call) Gpt_EnableNotification/20 (1073741824 (estimated locally),1.00 per call) Gpt_DisableNotification/21 (1073741823 (estimated locally),1.00 per call) Gpt_ValidateChannelStatus.constprop/40 (1073741824 (estimated locally),1.00 per call) 
  Calls: Det_ReportError/23 (187153200 (estimated locally),0.17 per call) Det_ReportError/23 (367756961 (estimated locally),0.34 per call) Gpt_ValidateChannelCall.part.0/35 (105011528 (estimated locally),0.10 per call) 
Gpt_ValidateGlobalCall.constprop.0/42 (Gpt_ValidateGlobalCall.constprop) @072f9700
  Type: function definition analyzed
  Visibility:
  References: Gpt_pConfig/3 (read)
  Referring: 
  Clone of Gpt_ValidateGlobalCall/7
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: Gpt_Init/14 (1073741824 (estimated locally),1.00 per call) Gpt_DeInit/15 (229727064 (estimated locally),1.00 per call) 
  Calls: Det_ReportError/23 (157453501 (estimated locally),0.15 per call) Gpt_ValidateGlobalCall.part.0/34 (152127741 (estimated locally),0.14 per call) 
Gpt_ValidateChannelNotification.constprop.0/41 (Gpt_ValidateChannelNotification.constprop) @072f9380
  Type: function definition analyzed
  Visibility:
  References: Gpt_pConfig/3 (read)
  Referring: 
  Clone of Gpt_ValidateChannelNotification/8
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Gpt_EnableNotification/20 (354334802 (estimated locally),0.33 per call) Gpt_DisableNotification/21 (354334802 (estimated locally),0.33 per call) 
  Calls: Gpt_ValidateChannelNotification.part.0/36 (187153200 (estimated locally),0.17 per call) 
Gpt_ValidateChannelStatus.constprop.0/40 (Gpt_ValidateChannelStatus.constprop) @072eaee0
  Type: function definition analyzed
  Visibility:
  References: Gpt_aChannelInfo/4 (read)
  Referring: 
  Clone of Gpt_ValidateChannelStatus/9
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Gpt_DeInit/15 (1014686025 (estimated locally),4.42 per call) Gpt_StartTimer/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: Gpt_ValidateChannelCall.constprop/43 (1073741824 (estimated locally),1.00 per call) Gpt_ValidateChannelStatus.part.0/37 (44551696 (estimated locally),0.04 per call) 
Gpt_ValidateParamValue.constprop.0/39 (Gpt_ValidateParamValue.constprop) @072eac40
  Type: function definition analyzed
  Visibility:
  References: Gpt_pConfig/3 (read)
  Referring: 
  Clone of Gpt_ValidateParamValue/10
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Gpt_StartTimer/18 (354334802 (estimated locally),0.33 per call) 
  Calls: Det_ReportError/23 (714038314 (estimated locally),0.67 per call) 
Gpt_ConvertChannelIndexToChannel.constprop.0/38 (Gpt_ConvertChannelIndexToChannel.constprop) @072eaa80
  Type: function definition analyzed
  Visibility:
  References: Gpt_pConfig/3 (read)
  Referring: 
  Clone of Gpt_ConvertChannelIndexToChannel/12
  Availability: local
  Function flags: count:397250652 (estimated locally) local optimize_size
  Called by: Gpt_Init/14 (946073927 (estimated locally),0.88 per call) Gpt_DeInit/15 (1014686025 (estimated locally),4.42 per call) Gpt_DeInit/15 (464675199 (estimated locally),2.02 per call) 
  Calls: 
Gpt_ValidateChannelStatus.part.0/37 (Gpt_ValidateChannelStatus.part.0) @072a8e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Gpt_ValidateChannelStatus.constprop/40 (44551696 (estimated locally),0.04 per call) 
  Calls: Det_ReportRuntimeError/28 (1073741824 (estimated locally),1.00 per call) 
Gpt_ValidateChannelNotification.part.0/36 (Gpt_ValidateChannelNotification.part.0) @072a87e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Gpt_ValidateChannelNotification.constprop/41 (187153200 (estimated locally),0.17 per call) 
  Calls: Det_ReportError/23 (1073741824 (estimated locally),1.00 per call) 
Gpt_ValidateChannelCall.part.0/35 (Gpt_ValidateChannelCall.part.0) @06f212a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Gpt_ValidateChannelCall.constprop/43 (105011528 (estimated locally),0.10 per call) 
  Calls: Det_ReportError/23 (1073741824 (estimated locally),1.00 per call) 
Gpt_ValidateGlobalCall.part.0/34 (Gpt_ValidateGlobalCall.part.0) @06ef7a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Gpt_ValidateGlobalCall.constprop/42 (152127741 (estimated locally),0.14 per call) 
  Calls: Det_ReportError/23 (1073741824 (estimated locally),1.00 per call) 
Gpt_Ipw_DisableInterrupt/33 (Gpt_Ipw_DisableInterrupt) @0719ad20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_DisableNotification/21 (68404334 (estimated locally),0.06 per call) 
  Calls: 
Gpt_Ipw_StopTimer/32 (Gpt_Ipw_StopTimer) @0719a7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_StopTimer/19 (71717364 (estimated locally),0.07 per call) 
  Calls: 
Gpt_Ipw_StartTimer/31 (Gpt_Ipw_StartTimer) @0719a540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_StartTimer/18 (177167401 (estimated locally),0.17 per call) 
  Calls: 
Gpt_Ipw_EnableInterrupt/30 (Gpt_Ipw_EnableInterrupt) @0719a460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_EnableNotification/20 (58465242 (estimated locally),0.05 per call) Gpt_StartTimer/18 (35858682 (estimated locally),0.03 per call) 
  Calls: 
Gpt_Ipw_GetTimeElapsed/29 (Gpt_Ipw_GetTimeElapsed) @0719a1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_StopTimer/19 (354334802 (estimated locally),0.33 per call) Gpt_GetTimeRemaining/17 (354334802 (estimated locally),0.33 per call) Gpt_GetTimeElapsed/16 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Det_ReportRuntimeError/28 (Det_ReportRuntimeError) @0717aee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_StartTimer/18 (58465242 (estimated locally),0.05 per call) Gpt_ValidateChannelStatus.part.0/37 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Gpt_Ipw_DeInit/27 (Gpt_Ipw_DeInit) @0717ac40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_DeInit/15 (118492176 (estimated locally),0.52 per call) 
  Calls: 
Gpt_Ipw_Init/26 (Gpt_Ipw_Init) @0717a7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Init/14 (946073927 (estimated locally),0.88 per call) 
  Calls: 
Gpt_Ipw_InitInstances/25 (Gpt_Ipw_InitInstances) @0717a620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Init/14 (116930485 (estimated locally),0.11 per call) 
  Calls: 
Gpt_Config/24 (Gpt_Config) @07166d38
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Gpt_Init/14 (addr)Gpt_Init/14 (addr)
  Availability: not_available
  Varpool flags: read-only
Det_ReportError/23 (Det_ReportError) @0717a460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_ValidateChannelCall.constprop/43 (187153200 (estimated locally),0.17 per call) Gpt_ValidateChannelCall.constprop/43 (367756961 (estimated locally),0.34 per call) Gpt_ValidateGlobalCall.constprop/42 (157453501 (estimated locally),0.15 per call) Gpt_ValidateParamValue.constprop/39 (714038314 (estimated locally),0.67 per call) Gpt_GetVersionInfo/13 (187153200 (estimated locally),0.17 per call) Gpt_ValidateChannelNotification.part.0/36 (1073741824 (estimated locally),1.00 per call) Gpt_ValidateChannelCall.part.0/35 (1073741824 (estimated locally),1.00 per call) Gpt_ValidateParamPtrInit/11 (574129754 (estimated locally),0.53 per call) Gpt_ValidateGlobalCall.part.0/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Gpt_ProcessCommonInterrupt/22 (Gpt_ProcessCommonInterrupt) @0717a000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (write)Gpt_eMode/2 (read)Gpt_aChannelInfo/4 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(187904819 (estimated locally),0.17 per call) 
Gpt_DisableNotification/21 (Gpt_DisableNotification) @07168b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (write)Gpt_eMode/2 (read)Gpt_aChannelInfo/4 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_Ipw_DisableInterrupt/33 (68404334 (estimated locally),0.06 per call) Gpt_ValidateChannelNotification.constprop/41 (354334802 (estimated locally),0.33 per call) Gpt_ValidateChannelCall.constprop/43 (1073741823 (estimated locally),1.00 per call) 
Gpt_EnableNotification/20 (Gpt_EnableNotification) @07168620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (write)Gpt_eMode/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_Ipw_EnableInterrupt/30 (58465242 (estimated locally),0.05 per call) Gpt_ValidateChannelNotification.constprop/41 (354334802 (estimated locally),0.33 per call) Gpt_ValidateChannelCall.constprop/43 (1073741824 (estimated locally),1.00 per call) 
Gpt_StopTimer/19 (Gpt_StopTimer) @071680e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (read)Gpt_pConfig/3 (read)Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (write)Gpt_aStopTime/5 (write)Gpt_aChannelInfo/4 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_Ipw_StopTimer/32 (71717364 (estimated locally),0.07 per call) Gpt_Ipw_GetTimeElapsed/29 (354334802 (estimated locally),0.33 per call) Gpt_ValidateChannelCall.constprop/43 (1073741824 (estimated locally),1.00 per call) 
Gpt_StartTimer/18 (Gpt_StartTimer) @07168d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (write)Gpt_pConfig/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Det_ReportRuntimeError/28 (58465242 (estimated locally),0.05 per call) Gpt_Ipw_StartTimer/31 (177167401 (estimated locally),0.17 per call) Gpt_Ipw_EnableInterrupt/30 (35858682 (estimated locally),0.03 per call) Gpt_ValidateParamValue.constprop/39 (354334802 (estimated locally),0.33 per call) Gpt_ValidateChannelStatus.constprop/40 (1073741824 (estimated locally),1.00 per call) 
Gpt_GetTimeRemaining/17 (Gpt_GetTimeRemaining) @07168a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (read)Gpt_pConfig/3 (read)Gpt_aStopTime/5 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_Ipw_GetTimeElapsed/29 (354334802 (estimated locally),0.33 per call) Gpt_ValidateChannelCall.constprop/43 (1073741824 (estimated locally),1.00 per call) 
Gpt_GetTimeElapsed/16 (Gpt_GetTimeElapsed) @071687e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (read)Gpt_pConfig/3 (read)Gpt_aStopTime/5 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_Ipw_GetTimeElapsed/29 (354334802 (estimated locally),0.33 per call) Gpt_ValidateChannelCall.constprop/43 (1073741824 (estimated locally),1.00 per call) 
Gpt_DeInit/15 (Gpt_DeInit) @07168540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (read)Gpt_aChannelInfo/4 (write)Gpt_aChannelInfo/4 (write)Gpt_aStopTime/5 (write)Gpt_pConfig/3 (read)Gpt_pConfig/3 (write)
  Referring: 
  Availability: available
  Function flags: count:229727064 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_Ipw_DeInit/27 (118492176 (estimated locally),0.52 per call) Gpt_ConvertChannelIndexToChannel.constprop/38 (464675199 (estimated locally),2.02 per call) Gpt_ValidateChannelStatus.constprop/40 (1014686025 (estimated locally),4.42 per call) Gpt_ConvertChannelIndexToChannel.constprop/38 (1014686025 (estimated locally),4.42 per call) Gpt_ValidateGlobalCall.constprop/42 (229727064 (estimated locally),1.00 per call) 
Gpt_Init/14 (Gpt_Init) @071682a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gpt_pConfig/3 (write)Gpt_Config/24 (addr)Gpt_Config/24 (addr)Gpt_aChannelInfo/4 (write)Gpt_aChannelInfo/4 (write)Gpt_aStopTime/5 (write)Gpt_pConfig/3 (read)Gpt_eMode/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_Ipw_Init/26 (946073927 (estimated locally),0.88 per call) Gpt_ConvertChannelIndexToChannel.constprop/38 (946073927 (estimated locally),0.88 per call) Gpt_Ipw_InitInstances/25 (116930485 (estimated locally),0.11 per call) Gpt_ValidateParamPtrInit/11 (354334802 (estimated locally),0.33 per call) Gpt_ValidateGlobalCall.constprop/42 (1073741824 (estimated locally),1.00 per call) 
Gpt_GetVersionInfo/13 (Gpt_GetVersionInfo) @07168000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Det_ReportError/23 (187153200 (estimated locally),0.17 per call) 
Gpt_ConvertChannelIndexToChannel/12 (Gpt_ConvertChannelIndexToChannel) @07057a80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:397250652 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gpt_ValidateParamPtrInit/11 (Gpt_ValidateParamPtrInit) @07057540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Gpt_Init/14 (354334802 (estimated locally),0.33 per call) 
  Calls: Det_ReportError/23 (574129754 (estimated locally),0.53 per call) 
Gpt_ValidateParamValue/10 (Gpt_ValidateParamValue) @07057ee0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gpt_ValidateChannelStatus/9 (Gpt_ValidateChannelStatus) @07057c40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gpt_ValidateChannelNotification/8 (Gpt_ValidateChannelNotification) @070579a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gpt_ValidateGlobalCall/7 (Gpt_ValidateGlobalCall) @07057700
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gpt_ValidateChannelCall/6 (Gpt_ValidateChannelCall) @07057460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gpt_aStopTime/5 (Gpt_aStopTime) @07052708
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gpt_GetTimeElapsed/16 (read)Gpt_GetTimeRemaining/17 (read)Gpt_Init/14 (write)Gpt_DeInit/15 (write)Gpt_StopTimer/19 (write)
  Availability: available
  Varpool flags:
Gpt_aChannelInfo/4 (Gpt_aChannelInfo) @07052678
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gpt_StopTimer/19 (write)Gpt_DisableNotification/21 (read)Gpt_DisableNotification/21 (write)Gpt_ValidateChannelStatus.constprop.0/40 (read)Gpt_EnableNotification/20 (write)Gpt_Init/14 (write)Gpt_DeInit/15 (write)Gpt_GetTimeElapsed/16 (read)Gpt_StopTimer/19 (write)Gpt_Init/14 (write)Gpt_GetTimeRemaining/17 (read)Gpt_StartTimer/18 (write)Gpt_DeInit/15 (write)Gpt_StopTimer/19 (read)Gpt_ProcessCommonInterrupt/22 (write)Gpt_ProcessCommonInterrupt/22 (read)
  Availability: available
  Varpool flags:
Gpt_pConfig/3 (Gpt_pConfig) @070525e8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: Gpt_StartTimer/18 (read)Gpt_GetTimeRemaining/17 (read)Gpt_GetTimeElapsed/16 (read)Gpt_ValidateGlobalCall.constprop.0/42 (read)Gpt_DisableNotification/21 (read)Gpt_EnableNotification/20 (read)Gpt_GetTimeRemaining/17 (read)Gpt_StopTimer/19 (read)Gpt_StopTimer/19 (read)Gpt_ValidateChannelNotification.constprop.0/41 (read)Gpt_StopTimer/19 (read)Gpt_ValidateChannelCall.constprop.0/43 (read)Gpt_ConvertChannelIndexToChannel.constprop.0/38 (read)Gpt_Init/14 (write)Gpt_Init/14 (read)Gpt_DeInit/15 (read)Gpt_DeInit/15 (read)Gpt_DeInit/15 (write)Gpt_ValidateParamValue.constprop.0/39 (read)Gpt_StartTimer/18 (read)Gpt_GetTimeElapsed/16 (read)Gpt_ProcessCommonInterrupt/22 (read)
  Availability: available
  Varpool flags:
Gpt_eMode/2 (Gpt_eMode) @07052558
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gpt_EnableNotification/20 (read)Gpt_DisableNotification/21 (read)Gpt_Init/14 (write)Gpt_ProcessCommonInterrupt/22 (read)
  Availability: available
  Varpool flags: initialized

;; Function Gpt_ConvertChannelIndexToChannel.constprop (Gpt_ConvertChannelIndexToChannel.constprop.0, funcdef_no=28, decl_uid=6623, cgraph_uid=34, symbol_order=38)

Modification phase of node Gpt_ConvertChannelIndexToChannel.constprop/38
Gpt_ConvertChannelIndexToChannel.constprop (Gpt_ChannelType ChannelIndex)
{
  Gpt_ChannelType Channel;
  uint32 coreID;
  const struct Gpt_ConfigType * _1;
  const uint8[<unknown>] * _2;
  int _4;
  unsigned char _5;

  <bb 7> [local count: 397250652]:
  # DEBUG coreID => 0

  <bb 2> [local count: 397250652]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Channel => 0
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 715863675]:
  # DEBUG BEGIN_STMT
  _1 = Gpt_pConfig[0];
  _2 = _1->u8GptChannelIdToIndexMap;
  _4 = (int) Channel_3;
  _5 = *_2[_4];
  if (_5 == ChannelIndex_6(D))
    goto <bb 6>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 676491173]:
  # DEBUG BEGIN_STMT
  Channel_7 = Channel_3 + 1;
  # DEBUG Channel => Channel_7

  <bb 5> [local count: 1073741824]:
  # Channel_3 = PHI <0(2), Channel_7(4)>
  # DEBUG Channel => Channel_3
  # DEBUG BEGIN_STMT
  if (Channel_3 != 2)
    goto <bb 3>; [66.67%]
  else
    goto <bb 6>; [33.33%]

  <bb 6> [local count: 397250652]:
  # Channel_8 = PHI <Channel_3(3), Channel_3(5)>
  # DEBUG BEGIN_STMT
  return Channel_8;

}



;; Function Gpt_ValidateChannelCall.constprop (Gpt_ValidateChannelCall.constprop.0, funcdef_no=23, decl_uid=6628, cgraph_uid=39, symbol_order=43)

Modification phase of node Gpt_ValidateChannelCall.constprop/43
Adjusting mask for param 0 to 0xf
Setting value range of param 0 [2, 8]
Gpt_ValidateChannelCall.constprop (uint8 u8ServiceId, Gpt_ChannelType channel)
{
  Std_ReturnType returnValue;
  uint32 coreID;
  const struct Gpt_ConfigType * _1;
  const uint8[<unknown>] * _4;
  int _5;
  unsigned char _6;

  <bb 9> [local count: 1073741823]:
  # DEBUG coreID => 0

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 1
  # DEBUG BEGIN_STMT
  _1 = Gpt_pConfig[0];
  if (_1 == 0B)
    goto <bb 3>; [17.43%]
  else
    goto <bb 4>; [82.57%]

  <bb 3> [local count: 187153200]:
  # DEBUG BEGIN_STMT
  Det_ReportError (100, 0, u8ServiceId_2(D), 10);
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 886588623]:
  # DEBUG BEGIN_STMT
  if (channel_3(D) > 1)
    goto <bb 5>; [41.48%]
  else
    goto <bb 6>; [58.52%]

  <bb 5> [local count: 367756961]:
  # DEBUG BEGIN_STMT
  Det_ReportError (100, 0, u8ServiceId_2(D), 20);
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 518831662]:
  # DEBUG BEGIN_STMT
  _4 = _1->u8GptChannelIdToIndexMap;
  _5 = (int) channel_3(D);
  _6 = *_4[_5];
  if (_6 != 255)
    goto <bb 8>; [79.76%]
  else
    goto <bb 7>; [20.24%]

  <bb 7> [local count: 105011528]:
  # DEBUG D#5 => channel_3(D)
  # DEBUG D#6 => 0
  returnValue_7 = Gpt_ValidateChannelCall.part.0 (u8ServiceId_2(D));

  <bb 8> [local count: 1073741824]:
  # returnValue_8 = PHI <1(3), 1(5), 0(6), returnValue_7(7)>
  # DEBUG returnValue => returnValue_8
  # DEBUG BEGIN_STMT
  return returnValue_8;

}



;; Function Gpt_ValidateChannelStatus.constprop (Gpt_ValidateChannelStatus.constprop.0, funcdef_no=26, decl_uid=6625, cgraph_uid=36, symbol_order=40)

Modification phase of node Gpt_ValidateChannelStatus.constprop/40
Adjusting mask for param 0 to 0x7
Setting value range of param 0 [2, 5]
Gpt_ValidateChannelStatus.constprop (uint8 u8ServiceId, Gpt_ChannelType channel)
{
  Std_ReturnType returnValue;
  uint32 coreID;
  unsigned char _3;
  int _4;
  <unnamed type> _5;

  <bb 7> [local count: 1073741824]:
  # DEBUG coreID => 0

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 1
  # DEBUG BEGIN_STMT
  _3 = Gpt_ValidateChannelCall (u8ServiceId_1(D), channel_2(D), 0);
  if (_3 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (channel_2(D) <= 1)
    goto <bb 4>; [41.00%]
  else
    goto <bb 6>; [59.00%]

  <bb 4> [local count: 220117074]:
  # DEBUG BEGIN_STMT
  _4 = (int) channel_2(D);
  _5 = Gpt_aChannelInfo[0][_4].eChannelStatus;
  if (_5 == 4)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 44551696]:
  # DEBUG D#13 => channel_2(D)
  # DEBUG D#14 => 0
  returnValue_6 = Gpt_ValidateChannelStatus.part.0 (u8ServiceId_1(D));

  <bb 6> [local count: 1073741824]:
  # returnValue_7 = PHI <1(2), 1(3), 0(4), returnValue_6(5)>
  # DEBUG returnValue => returnValue_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return returnValue_7;

}



;; Function Gpt_GetVersionInfo (Gpt_GetVersionInfo, funcdef_no=9, decl_uid=6183, cgraph_uid=10, symbol_order=13)

Modification phase of node Gpt_GetVersionInfo/13
Gpt_GetVersionInfo (struct Std_VersionInfoType * VersionInfoPtr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (VersionInfoPtr_2(D) == 0B)
    goto <bb 3>; [17.43%]
  else
    goto <bb 4>; [82.57%]

  <bb 3> [local count: 187153200]:
  # DEBUG BEGIN_STMT
  Det_ReportError (100, 0, 0, 22);
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 886588625]:
  # DEBUG BEGIN_STMT
  VersionInfoPtr_2(D)->vendorID = 43;
  # DEBUG BEGIN_STMT
  VersionInfoPtr_2(D)->moduleID = 100;
  # DEBUG BEGIN_STMT
  VersionInfoPtr_2(D)->sw_major_version = 4;
  # DEBUG BEGIN_STMT
  VersionInfoPtr_2(D)->sw_minor_version = 0;
  # DEBUG BEGIN_STMT
  VersionInfoPtr_2(D)->sw_patch_version = 2;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Gpt_Init (Gpt_Init, funcdef_no=10, decl_uid=6185, cgraph_uid=11, symbol_order=14)

Modification phase of node Gpt_Init/14
Gpt_Init (const struct Gpt_ConfigType * configPtr)
{
  Gpt_ChannelType channel;
  Gpt_ChannelType ChannelIndex;
  unsigned char _1;
  unsigned char _2;
  int _3;
  const struct Gpt_ChannelConfigType[<unknown>] * _4;
  int _5;
  struct Gpt_Ipw_HwChannelConfigType * _6;
  const struct Gpt_ConfigType * _7;
  unsigned char _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_ValidateGlobalCall (1, 0);
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = Gpt_ValidateParamPtrInit (configPtr_15(D));
  if (_2 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 4> [local count: 116930485]:
  # DEBUG BEGIN_STMT
  Gpt_pConfig[0] = &Gpt_Config;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Gpt_Ipw_InitInstances (&Gpt_Config);
  # DEBUG BEGIN_STMT
  # DEBUG ChannelIndex => 0
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 946073927]:
  # DEBUG BEGIN_STMT
  channel_20 = Gpt_ConvertChannelIndexToChannel (ChannelIndex_9, 0);
  # DEBUG channel => channel_20
  # DEBUG BEGIN_STMT
  if (channel_20 <= 1)
    goto <bb 6>; [41.00%]
  else
    goto <bb 7>; [59.00%]

  <bb 6> [local count: 387890310]:
  # DEBUG BEGIN_STMT
  _3 = (int) channel_20;
  Gpt_aChannelInfo[0][_3].bNotificationEnabled = 0;
  # DEBUG BEGIN_STMT
  Gpt_aChannelInfo[0][_3].eChannelStatus = 1;
  # DEBUG BEGIN_STMT
  Gpt_aStopTime[0][_3] = 0;

  <bb 7> [local count: 946073927]:
  # DEBUG BEGIN_STMT
  _4 = _7->Gpt_pChannelConfig;
  _5 = (int) ChannelIndex_9;
  _6 = *_4[_5].Gpt_Ipw_HwChannelConfig;
  Gpt_Ipw_Init (_6);
  # DEBUG BEGIN_STMT
  ChannelIndex_25 = ChannelIndex_9 + 1;
  # DEBUG ChannelIndex => ChannelIndex_25

  <bb 8> [local count: 1063004412]:
  # ChannelIndex_9 = PHI <0(4), ChannelIndex_25(7)>
  # DEBUG ChannelIndex => ChannelIndex_9
  # DEBUG BEGIN_STMT
  _7 = Gpt_pConfig[0];
  _8 = _7->channelCount;
  if (_8 > ChannelIndex_9)
    goto <bb 5>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 116930485]:
  # DEBUG BEGIN_STMT
  Gpt_eMode[0] = 0;

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_DeInit (Gpt_DeInit, funcdef_no=11, decl_uid=6187, cgraph_uid=12, symbol_order=15)

Modification phase of node Gpt_DeInit/15
Gpt_DeInit ()
{
  Std_ReturnType allChannelStatus;
  Gpt_ChannelType ChannelIndex;
  Gpt_ChannelType channel;
  unsigned char _1;
  unsigned char _2;
  const struct Gpt_ConfigType * _3;
  unsigned char _4;
  int _5;
  const struct Gpt_ChannelConfigType[<unknown>] * _6;
  int _7;
  struct Gpt_Ipw_HwChannelConfigType * _8;
  const struct Gpt_ConfigType * _9;
  unsigned char _10;

  <bb 2> [local count: 229727064]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG allChannelStatus => 0
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_ValidateGlobalCall (2, 0);
  if (_1 == 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 14> [local count: 114863532]:
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  channel_21 = Gpt_ConvertChannelIndexToChannel (ChannelIndex_11, 0);
  # DEBUG channel => channel_21
  # DEBUG BEGIN_STMT
  _2 = Gpt_ValidateChannelStatus (2, channel_21, 0);
  if (_2 == 1)
    goto <bb 6>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  ChannelIndex_23 = ChannelIndex_11 + 1;
  # DEBUG ChannelIndex => ChannelIndex_23

  <bb 5> [local count: 1073741824]:
  # ChannelIndex_11 = PHI <ChannelIndex_23(4), 0(14)>
  # DEBUG ChannelIndex => ChannelIndex_11
  # DEBUG BEGIN_STMT
  _3 = Gpt_pConfig[0];
  _4 = _3->channelCount;
  if (_4 > ChannelIndex_11)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 114863532]:
  # allChannelStatus_13 = PHI <1(3), 0(5)>
  # DEBUG allChannelStatus => allChannelStatus_13
  # DEBUG BEGIN_STMT
  if (allChannelStatus_13 == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 13> [local count: 57431766]:
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 464675199]:
  # DEBUG BEGIN_STMT
  channel_25 = Gpt_ConvertChannelIndexToChannel (ChannelIndex_12, 0);
  # DEBUG channel => channel_25
  # DEBUG BEGIN_STMT
  if (channel_25 <= 1)
    goto <bb 8>; [25.50%]
  else
    goto <bb 9>; [74.50%]

  <bb 8> [local count: 118492176]:
  # DEBUG BEGIN_STMT
  _5 = (int) channel_25;
  Gpt_aChannelInfo[0][_5].bNotificationEnabled = 0;
  # DEBUG BEGIN_STMT
  Gpt_aChannelInfo[0][_5].eChannelStatus = 0;
  # DEBUG BEGIN_STMT
  Gpt_aStopTime[0][_5] = 0;
  # DEBUG BEGIN_STMT
  _6 = _9->Gpt_pChannelConfig;
  _7 = (int) ChannelIndex_12;
  _8 = *_6[_7].Gpt_Ipw_HwChannelConfig;
  Gpt_Ipw_DeInit (_8);

  <bb 9> [local count: 464675200]:
  # DEBUG BEGIN_STMT
  ChannelIndex_30 = ChannelIndex_12 + 1;
  # DEBUG ChannelIndex => ChannelIndex_30

  <bb 10> [local count: 522106965]:
  # ChannelIndex_12 = PHI <ChannelIndex_30(9), 0(13)>
  # DEBUG ChannelIndex => ChannelIndex_12
  # DEBUG BEGIN_STMT
  _9 = Gpt_pConfig[0];
  _10 = _9->channelCount;
  if (_10 > ChannelIndex_12)
    goto <bb 7>; [89.00%]
  else
    goto <bb 11>; [11.00%]

  <bb 11> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  Gpt_pConfig[0] = 0B;

  <bb 12> [local count: 229727064]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_GetTimeElapsed (Gpt_GetTimeElapsed, funcdef_no=12, decl_uid=6189, cgraph_uid=13, symbol_order=16)

Modification phase of node Gpt_GetTimeElapsed/16
Gpt_GetTimeElapsed (Gpt_ChannelType channel)
{
  Gpt_ValueType returnValue;
  Gpt_ChannelType ChannelIndex;
  struct Gpt_HwChannelInfoType returnHwChannelInfo;
  unsigned char _1;
  const struct Gpt_ConfigType * _2;
  const uint8[<unknown>] * _3;
  int _4;
  const struct Gpt_ChannelConfigType[<unknown>] * _5;
  int _6;
  struct Gpt_Ipw_HwChannelConfigType * _7;
  <unnamed type> _8;
  _Bool _9;
  const struct Gpt_ConfigType * _10;
  const struct Gpt_ChannelConfigType[<unknown>] * _11;
  <unnamed type> _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  returnHwChannelInfo.bChannelRollover = 0;
  returnHwChannelInfo.uTargetTime = 0;
  # DEBUG BEGIN_STMT
  # DEBUG pRetHwChannelInfo => &returnHwChannelInfo
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_ValidateChannelCall (3, channel_18(D), 0);
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = Gpt_pConfig[0];
  _3 = _2->u8GptChannelIdToIndexMap;
  _4 = (int) channel_18(D);
  ChannelIndex_20 = *_3[_4];
  # DEBUG ChannelIndex => ChannelIndex_20
  # DEBUG BEGIN_STMT
  _5 = _2->Gpt_pChannelConfig;
  _6 = (int) ChannelIndex_20;
  _7 = *_5[_6].Gpt_Ipw_HwChannelConfig;
  returnValue_22 = Gpt_Ipw_GetTimeElapsed (_7, &returnHwChannelInfo);
  # DEBUG returnValue => returnValue_22
  # DEBUG BEGIN_STMT
  _8 = Gpt_aChannelInfo[0][_4].eChannelStatus;
  switch (_8) <default: <L14> [20.00%], case 1: <L6> [20.00%], case 2: <L7> [20.00%], case 3: <L8> [20.00%], case 4: <L1> [20.00%]>

  <bb 4> [local count: 70866960]:
<L1>:
  # DEBUG BEGIN_STMT
  _9 = returnHwChannelInfo.bChannelRollover;
  if (_9 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 5> [local count: 35433480]:
  _10 = Gpt_pConfig[0];
  _11 = _10->Gpt_pChannelConfig;
  _12 = *_11[_6].Gpt_eChannelMode;
  if (_12 == 1)
    goto <bb 6>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 6> [local count: 12047383]:
  # DEBUG BEGIN_STMT
  returnValue_23 = returnHwChannelInfo.uTargetTime;
  # DEBUG returnValue => returnValue_23
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 70866960]:
<L6>:
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 70866960]:
<L7>:
  # DEBUG BEGIN_STMT
  returnValue_25 = Gpt_aStopTime[0][_4];
  # DEBUG returnValue => returnValue_25
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 70866960]:
<L8>:
  # DEBUG BEGIN_STMT
  returnValue_24 = returnHwChannelInfo.uTargetTime;
  # DEBUG returnValue => returnValue_24
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741823]:
  # returnValue_13 = PHI <0(2), returnValue_22(5), 0(7), returnValue_25(8), returnValue_24(9), returnValue_22(3), returnValue_22(4), returnValue_23(6)>
<L14>:
  # DEBUG returnValue => returnValue_13
  # DEBUG BEGIN_STMT
  returnHwChannelInfo ={v} {CLOBBER};
  return returnValue_13;

}



;; Function Gpt_GetTimeRemaining (Gpt_GetTimeRemaining, funcdef_no=13, decl_uid=6191, cgraph_uid=14, symbol_order=17)

Modification phase of node Gpt_GetTimeRemaining/17
Gpt_GetTimeRemaining (Gpt_ChannelType channel)
{
  Gpt_ValueType returnValue;
  Gpt_ChannelType ChannelIndex;
  struct Gpt_HwChannelInfoType returnHwChannelInfo;
  unsigned char _1;
  const struct Gpt_ConfigType * _2;
  const uint8[<unknown>] * _3;
  int _4;
  const struct Gpt_ChannelConfigType[<unknown>] * _5;
  int _6;
  struct Gpt_Ipw_HwChannelConfigType * _7;
  <unnamed type> _8;
  _Bool _9;
  const struct Gpt_ConfigType * _10;
  const struct Gpt_ChannelConfigType[<unknown>] * _11;
  <unnamed type> _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  returnHwChannelInfo.bChannelRollover = 0;
  returnHwChannelInfo.uTargetTime = 0;
  # DEBUG BEGIN_STMT
  # DEBUG pRetHwChannelInfo => &returnHwChannelInfo
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_ValidateChannelCall (4, channel_21(D), 0);
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = Gpt_pConfig[0];
  _3 = _2->u8GptChannelIdToIndexMap;
  _4 = (int) channel_21(D);
  ChannelIndex_23 = *_3[_4];
  # DEBUG ChannelIndex => ChannelIndex_23
  # DEBUG BEGIN_STMT
  _5 = _2->Gpt_pChannelConfig;
  _6 = (int) ChannelIndex_23;
  _7 = *_5[_6].Gpt_Ipw_HwChannelConfig;
  returnValue_25 = Gpt_Ipw_GetTimeElapsed (_7, &returnHwChannelInfo);
  # DEBUG returnValue => returnValue_25
  # DEBUG BEGIN_STMT
  _8 = Gpt_aChannelInfo[0][_4].eChannelStatus;
  switch (_8) <default: <L14> [20.00%], case 1: <L6> [20.00%], case 2: <L7> [20.00%], case 3: <L8> [20.00%], case 4: <L1> [20.00%]>

  <bb 4> [local count: 70866960]:
<L1>:
  # DEBUG BEGIN_STMT
  _9 = returnHwChannelInfo.bChannelRollover;
  if (_9 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 35433480]:
  _10 = Gpt_pConfig[0];
  _11 = _10->Gpt_pChannelConfig;
  _12 = *_11[_6].Gpt_eChannelMode;
  if (_12 == 1)
    goto <bb 10>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 58819577]:
  # DEBUG BEGIN_STMT
  _13 = returnHwChannelInfo.uTargetTime;
  returnValue_26 = _13 - returnValue_25;
  # DEBUG returnValue => returnValue_26
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 70866960]:
<L6>:
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 70866960]:
<L7>:
  # DEBUG BEGIN_STMT
  _14 = returnHwChannelInfo.uTargetTime;
  _15 = Gpt_aStopTime[0][_4];
  returnValue_27 = _14 - _15;
  # DEBUG returnValue => returnValue_27
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 70866960]:
<L8>:
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741823]:
  # returnValue_16 = PHI <0(2), returnValue_26(6), 0(7), returnValue_27(8), 0(9), returnValue_25(3), 0(5)>
<L14>:
  # DEBUG returnValue => returnValue_16
  # DEBUG BEGIN_STMT
  returnHwChannelInfo ={v} {CLOBBER};
  return returnValue_16;

}



;; Function Gpt_StartTimer (Gpt_StartTimer, funcdef_no=14, decl_uid=6194, cgraph_uid=15, symbol_order=18)

Modification phase of node Gpt_StartTimer/18
Gpt_StartTimer (Gpt_ChannelType channel, Gpt_ValueType value)
{
  Std_ReturnType returnValue;
  uint8 ChannelIndex;
  unsigned char _1;
  unsigned char _2;
  const struct Gpt_ConfigType * _3;
  const uint8[<unknown>] * _4;
  int _5;
  const struct Gpt_ChannelConfigType[<unknown>] * _6;
  int _7;
  <unnamed type> _8;
  struct Gpt_Ipw_HwChannelConfigType * _9;
  const struct Gpt_ConfigType * _10;
  const struct Gpt_ChannelConfigType[<unknown>] * _11;
  struct Gpt_Ipw_HwChannelConfigType * _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_ValidateChannelStatus (5, channel_16(D), 0);
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = Gpt_ValidateParamValue (5, channel_16(D), value_18(D), 0);
  if (_2 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  _3 = Gpt_pConfig[0];
  _4 = _3->u8GptChannelIdToIndexMap;
  _5 = (int) channel_16(D);
  ChannelIndex_20 = *_4[_5];
  # DEBUG ChannelIndex => ChannelIndex_20
  # DEBUG BEGIN_STMT
  _6 = _3->Gpt_pChannelConfig;
  _7 = (int) ChannelIndex_20;
  _8 = *_6[_7].Gpt_eChannelMode;
  if (_8 == 1)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 35858682]:
  # DEBUG BEGIN_STMT
  _9 = *_6[_7].Gpt_Ipw_HwChannelConfig;
  Gpt_Ipw_EnableInterrupt (_9);

  <bb 6> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  Gpt_aChannelInfo[0][_5].eChannelStatus = 4;
  # DEBUG BEGIN_STMT
  _10 = Gpt_pConfig[0];
  _11 = _10->Gpt_pChannelConfig;
  _12 = *_11[_7].Gpt_Ipw_HwChannelConfig;
  returnValue_24 = Gpt_Ipw_StartTimer (_12, value_18(D));
  # DEBUG returnValue => returnValue_24
  # DEBUG BEGIN_STMT
  if (returnValue_24 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 58465242]:
  # DEBUG BEGIN_STMT
  Det_ReportRuntimeError (100, 0, 5, 43);

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_StopTimer (Gpt_StopTimer, funcdef_no=15, decl_uid=6196, cgraph_uid=16, symbol_order=19)

Modification phase of node Gpt_StopTimer/19
Gpt_StopTimer (Gpt_ChannelType channel)
{
  Gpt_ChannelType ChannelIndex;
  Gpt_ValueType uElapsedTime;
  struct Gpt_HwChannelInfoType returnHwChannelInfo;
  unsigned char _1;
  const struct Gpt_ConfigType * _2;
  const uint8[<unknown>] * _3;
  int _4;
  const struct Gpt_ChannelConfigType[<unknown>] * _5;
  int _6;
  struct Gpt_Ipw_HwChannelConfigType * _7;
  <unnamed type> _8;
  const struct Gpt_ConfigType * _9;
  const struct Gpt_ChannelConfigType[<unknown>] * _10;
  struct Gpt_Ipw_HwChannelConfigType * _11;
  _Bool _12;
  const struct Gpt_ConfigType * _13;
  const struct Gpt_ChannelConfigType[<unknown>] * _14;
  <unnamed type> _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  returnHwChannelInfo.bChannelRollover = 0;
  returnHwChannelInfo.uTargetTime = 0;
  # DEBUG BEGIN_STMT
  # DEBUG pRetHwChannelInfo => &returnHwChannelInfo
  # DEBUG BEGIN_STMT
  # DEBUG uElapsedTime => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_ValidateChannelCall (6, channel_20(D), 0);
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = Gpt_pConfig[0];
  _3 = _2->u8GptChannelIdToIndexMap;
  _4 = (int) channel_20(D);
  ChannelIndex_22 = *_3[_4];
  # DEBUG ChannelIndex => ChannelIndex_22
  # DEBUG BEGIN_STMT
  _5 = _2->Gpt_pChannelConfig;
  _6 = (int) ChannelIndex_22;
  _7 = *_5[_6].Gpt_Ipw_HwChannelConfig;
  uElapsedTime_24 = Gpt_Ipw_GetTimeElapsed (_7, &returnHwChannelInfo);
  # DEBUG uElapsedTime => uElapsedTime_24
  # DEBUG BEGIN_STMT
  _8 = Gpt_aChannelInfo[0][_4].eChannelStatus;
  if (_8 == 4)
    goto <bb 4>; [20.24%]
  else
    goto <bb 8>; [79.76%]

  <bb 4> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  _9 = Gpt_pConfig[0];
  _10 = _9->Gpt_pChannelConfig;
  _11 = *_10[_6].Gpt_Ipw_HwChannelConfig;
  Gpt_Ipw_StopTimer (_11);
  # DEBUG BEGIN_STMT
  _12 = returnHwChannelInfo.bChannelRollover;
  if (_12 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 35858682]:
  _13 = Gpt_pConfig[0];
  _14 = _13->Gpt_pChannelConfig;
  _15 = *_14[_6].Gpt_eChannelMode;
  if (_15 == 1)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 12191952]:
  # DEBUG BEGIN_STMT
  Gpt_aChannelInfo[0][_4].eChannelStatus = 3;
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 59525412]:
  # DEBUG BEGIN_STMT
  Gpt_aStopTime[0][_4] = uElapsedTime_24;
  # DEBUG BEGIN_STMT
  Gpt_aChannelInfo[0][_4].eChannelStatus = 2;

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  returnHwChannelInfo ={v} {CLOBBER};
  return;

}



;; Function Gpt_EnableNotification (Gpt_EnableNotification, funcdef_no=16, decl_uid=6198, cgraph_uid=17, symbol_order=20)

Modification phase of node Gpt_EnableNotification/20
Gpt_EnableNotification (Gpt_ChannelType channel)
{
  uint8 ChannelIndex;
  unsigned char _1;
  unsigned char _2;
  const struct Gpt_ConfigType * _3;
  const uint8[<unknown>] * _4;
  int _5;
  <unnamed type> _6;
  const struct Gpt_ChannelConfigType[<unknown>] * _7;
  int _8;
  struct Gpt_Ipw_HwChannelConfigType * _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_ValidateChannelCall (7, channel_12(D), 0);
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = Gpt_ValidateChannelNotification (7, channel_12(D), 0);
  if (_2 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  _3 = Gpt_pConfig[0];
  _4 = _3->u8GptChannelIdToIndexMap;
  _5 = (int) channel_12(D);
  ChannelIndex_15 = *_4[_5];
  # DEBUG ChannelIndex => ChannelIndex_15
  # DEBUG BEGIN_STMT
  Gpt_aChannelInfo[0][_5].bNotificationEnabled = 1;
  # DEBUG BEGIN_STMT
  _6 = Gpt_eMode[0];
  if (_6 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 58465242]:
  # DEBUG BEGIN_STMT
  _7 = _3->Gpt_pChannelConfig;
  _8 = (int) ChannelIndex_15;
  _9 = *_7[_8].Gpt_Ipw_HwChannelConfig;
  Gpt_Ipw_EnableInterrupt (_9);

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_DisableNotification (Gpt_DisableNotification, funcdef_no=17, decl_uid=6200, cgraph_uid=18, symbol_order=21)

Modification phase of node Gpt_DisableNotification/21
Gpt_DisableNotification (Gpt_ChannelType channel)
{
  uint8 ChannelIndex;
  unsigned char _1;
  unsigned char _2;
  const struct Gpt_ConfigType * _3;
  const uint8[<unknown>] * _4;
  int _5;
  <unnamed type> _6;
  const struct Gpt_ChannelConfigType[<unknown>] * _7;
  int _8;
  <unnamed type> _9;
  <unnamed type> _10;
  struct Gpt_Ipw_HwChannelConfigType * _11;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_ValidateChannelCall (8, channel_14(D), 0);
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = Gpt_ValidateChannelNotification (8, channel_14(D), 0);
  if (_2 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  _3 = Gpt_pConfig[0];
  _4 = _3->u8GptChannelIdToIndexMap;
  _5 = (int) channel_14(D);
  ChannelIndex_17 = *_4[_5];
  # DEBUG ChannelIndex => ChannelIndex_17
  # DEBUG BEGIN_STMT
  Gpt_aChannelInfo[0][_5].bNotificationEnabled = 0;
  # DEBUG BEGIN_STMT
  _6 = Gpt_eMode[0];
  if (_6 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 5> [local count: 88583700]:
  _7 = _3->Gpt_pChannelConfig;
  _8 = (int) ChannelIndex_17;
  _9 = *_7[_8].Gpt_eChannelMode;
  if (_9 == 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 6> [local count: 59351079]:
  _10 = Gpt_aChannelInfo[0][_5].eChannelStatus;
  if (_10 != 4)
    goto <bb 7>; [66.00%]
  else
    goto <bb 8>; [34.00%]

  <bb 7> [local count: 68404334]:
  # DEBUG BEGIN_STMT
  _11 = *_7[_8].Gpt_Ipw_HwChannelConfig;
  Gpt_Ipw_DisableInterrupt (_11);

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_ProcessCommonInterrupt (Gpt_ProcessCommonInterrupt, funcdef_no=18, decl_uid=6202, cgraph_uid=19, symbol_order=22)

Modification phase of node Gpt_ProcessCommonInterrupt/22
Gpt_ProcessCommonInterrupt (uint8 channel)
{
  uint8 ChannelIndex;
  const struct Gpt_ConfigType * _1;
  const uint8[<unknown>] * _2;
  int _3;
  const struct Gpt_ChannelConfigType[<unknown>] * _4;
  int _5;
  <unnamed type> _6;
  <unnamed type> _7;
  _Bool _8;
  void (*<T55c>) (void) _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG coreID => 0
  # DEBUG BEGIN_STMT
  _1 = Gpt_pConfig[0];
  if (_1 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _2 = _1->u8GptChannelIdToIndexMap;
  _3 = (int) channel_13(D);
  ChannelIndex_14 = *_2[_3];
  # DEBUG ChannelIndex => ChannelIndex_14
  # DEBUG BEGIN_STMT
  _4 = _1->Gpt_pChannelConfig;
  _5 = (int) ChannelIndex_14;
  _6 = *_4[_5].Gpt_eChannelMode;
  if (_6 == 1)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 255550554]:
  # DEBUG BEGIN_STMT
  Gpt_aChannelInfo[0][_3].eChannelStatus = 3;

  <bb 5> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _7 = Gpt_eMode[0];
  if (_7 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 375809639]:
  _8 = Gpt_aChannelInfo[0][_3].bNotificationEnabled;
  if (_8 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 187904819]:
  # DEBUG BEGIN_STMT
  _9 = *_4[_5].Gpt_pfNotification;
  _9 ();

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}


