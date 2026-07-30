
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03/37:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03/36:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01/35:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01/34:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02/33:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02/32:
  Jump functions of caller  SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00/31:
  Jump functions of caller  SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00/30:
  Jump functions of caller  PIT_1_ISR/29:
    callsite  PIT_1_ISR/29 -> Pit_Ip_ProcessCommonInterrupt/18 : 
       param 0: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 6]
  Jump functions of caller  Pit_Ip_GetLifetimeTimer/28:
    callsite  Pit_Ip_GetLifetimeTimer/28 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_SetLifetimeTimer/27:
    callsite  Pit_Ip_SetLifetimeTimer/27 -> Pit_Ip_EnableTimer/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_SetLifetimeTimer/27 -> Pit_Ip_EnableTimer/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_SetLifetimeTimer/27 -> Pit_Ip_SetChainMode/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_SetLifetimeTimer/27 -> Pit_Ip_SetEnableInterruptFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_SetLifetimeTimer/27 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_DisableChannelInterrupt/26:
    callsite  Pit_Ip_DisableChannelInterrupt/26 -> Pit_Ip_ClearInterruptStatusFlag/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_DisableChannelInterrupt/26 -> Pit_Ip_SetEnableInterruptFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_DisableChannelInterrupt/26 -> DevAssert/0 : 
       param 0: PASS THROUGH: 1, op le_expr 6
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_DisableChannelInterrupt/26 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_EnableChannelInterrupt/25:
    callsite  Pit_Ip_EnableChannelInterrupt/25 -> Pit_Ip_SetEnableInterruptFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_EnableChannelInterrupt/25 -> Pit_Ip_ClearInterruptStatusFlag/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_EnableChannelInterrupt/25 -> DevAssert/0 : 
       param 0: PASS THROUGH: 1, op le_expr 6
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_EnableChannelInterrupt/25 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_GetCurrentTimer/24:
    callsite  Pit_Ip_GetCurrentTimer/24 -> DevAssert/0 : 
       param 0: PASS THROUGH: 1, op le_expr 6
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_GetCurrentTimer/24 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_StopChannel/23:
    callsite  Pit_Ip_StopChannel/23 -> Pit_Ip_ClearInterruptStatusFlag/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_StopChannel/23 -> Pit_Ip_EnableTimer/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_StopChannel/23 -> DevAssert/0 : 
       param 0: PASS THROUGH: 1, op le_expr 6
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_StopChannel/23 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_StartChannel/22:
    callsite  Pit_Ip_StartChannel/22 -> Pit_Ip_EnableTimer/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_StartChannel/22 -> DevAssert/0 : 
       param 0: PASS THROUGH: 1, op le_expr 6
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_StartChannel/22 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_Deinit/21:
    callsite  Pit_Ip_Deinit/21 -> Pit_Ip_Reset/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_Deinit/21 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_InitChannel/20:
    callsite  Pit_Ip_InitChannel/20 -> Pit_Ip_ClearInterruptStatusFlag/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_InitChannel/20 -> Pit_Ip_SetEnableInterruptFlag/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_InitChannel/20 -> Pit_Ip_EnableTimer/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_InitChannel/20 -> DevAssert/0 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_InitChannel/20 -> DevAssert/0 : 
       param 0: PASS THROUGH: 1, op ne_expr 0B
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_InitChannel/20 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_Init/19:
    callsite  Pit_Ip_Init/19 -> Pit_Ip_SetDebugMode/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_Init/19 -> Pit_Ip_EnableModule/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Pit_Ip_Init/19 -> DevAssert/0 : 
       param 0: PASS THROUGH: 1, op ne_expr 0B
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Pit_Ip_Init/19 -> DevAssert/0 : 
       param 0: PASS THROUGH: 0, op le_expr 1
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  Pit_Ip_ProcessCommonInterrupt/18:
    callsite  Pit_Ip_ProcessCommonInterrupt/18 -> Pit_Ip_StopChannel/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Pit_Ip_ProcessCommonInterrupt/18 -> Pit_Ip_ClearInterruptStatusFlag/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt callback_11 (callbackParam_13);
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Pit_Ip_ClearInterruptStatusFlag/14:
  Jump functions of caller  Pit_Ip_SetEnableInterruptFlag/13:
  Jump functions of caller  Pit_Ip_Reset/9:
  Jump functions of caller  Pit_Ip_SetChainMode/8:
  Jump functions of caller  Pit_Ip_SetDebugMode/7:
  Jump functions of caller  Pit_Ip_EnableTimer/6:
  Jump functions of caller  Pit_Ip_EnableModule/5:
  Jump functions of caller  Pit_Ip_GetLoadValue/4:
  Jump functions of caller  DevAssert/0:

 Propagating constants:

Not considering PIT_1_ISR for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_GetLifetimeTimer for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_SetLifetimeTimer for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_DisableChannelInterrupt for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_EnableChannelInterrupt for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_GetCurrentTimer for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_StopChannel for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_StartChannel for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_Deinit for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_InitChannel for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_Init for cloning; -fipa-cp-clone disabled.
Not considering Pit_Ip_GetLoadValue for cloning; -fipa-cp-clone disabled.

overall_size: 340, max_new_size: 11001
 - context independent values, size: 38, time_benefit: 51.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 13, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 7, time_benefit: 53.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 6, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: PIT_1_ISR/29:
  Node: Pit_Ip_GetLifetimeTimer/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_SetLifetimeTimer/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_DisableChannelInterrupt/26:
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
  Node: Pit_Ip_EnableChannelInterrupt/25:
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
  Node: Pit_Ip_GetCurrentTimer/24:
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
  Node: Pit_Ip_StopChannel/23:
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
  Node: Pit_Ip_StartChannel/22:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_Deinit/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Pit_Ip_InitChannel/20:
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
  Node: Pit_Ip_Init/19:
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
  Node: Pit_Ip_ProcessCommonInterrupt/18:
    param [0]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         uint8 [1, 1]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8 [0, 6]
        AGGS VARIABLE
  Node: Pit_Ip_ClearInterruptStatusFlag/14:
    param [0]: VARIABLE
               1 [loc_time: 49, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Pit_Ip_SetEnableInterruptFlag/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               1 [loc_time: 49, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 1 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
               0 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         boolean [0, 1]
        AGGS VARIABLE
  Node: Pit_Ip_Reset/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8 [0, 7]
        AGGS VARIABLE
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         boolean [0, 0]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Pit_Ip_SetChainMode/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         uint8 [1, 1]
        AGGS VARIABLE
    param [2]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         boolean [1, 1]
        AGGS VARIABLE
  Node: Pit_Ip_SetDebugMode/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Pit_Ip_EnableTimer/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               1 [loc_time: 49, loc_size: 15, prop_time: 0, prop_size: 0]
               0 [loc_time: 49, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         boolean [0, 1]
        AGGS VARIABLE
  Node: Pit_Ip_EnableModule/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
  Node: Pit_Ip_GetLoadValue/4:
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
  Node: DevAssert/0:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of Pit_Ip_ProcessCommonInterrupt/18 for all known contexts.
    replacing param #0 instance with const 1
 - Creating a specialized node of Pit_Ip_Reset/9 for all known contexts.
    replacing param #2 available with const 0
 - Creating a specialized node of Pit_Ip_SetChainMode/8 for all known contexts.
    replacing param #1 channel with const 1
    replacing param #2 enable with const 1
 - Creating a specialized node of Pit_Ip_EnableModule/5 for all known contexts.
    replacing param #1 timerType with const 0
Propagated bits info for function Pit_Ip_EnableModule.constprop/43:
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function Pit_Ip_SetChainMode.constprop/42:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x1, mask = 0x0
Propagated bits info for function Pit_Ip_Reset.constprop/41:
 param 1: value = 0x0, mask = 0x7
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Pit_Ip_ProcessCommonInterrupt.constprop/40:
 param 0: value = 0x1, mask = 0x0
 param 1: value = 0x0, mask = 0x7
Propagated bits info for function Pit_Ip_ProcessCommonInterrupt/18:
 param 0: value = 0x1, mask = 0x0
 param 1: value = 0x0, mask = 0x7
Propagated bits info for function Pit_Ip_Reset/9:
 param 1: value = 0x0, mask = 0x7
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function Pit_Ip_SetChainMode/8:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x1, mask = 0x0
Propagated bits info for function Pit_Ip_EnableModule/5:
 param 1: value = 0x0, mask = 0x0

IPA constant propagation end

Reclaiming functions: Pit_Ip_ProcessCommonInterrupt/18 Pit_Ip_Reset/9 Pit_Ip_SetChainMode/8 Pit_Ip_EnableModule/5
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Pit_Ip_EnableModule.constprop.0/43 (Pit_Ip_EnableModule.constprop) @06ebb540
  Type: function definition analyzed
  Visibility:
  References: pitBase/2 (read)
  Referring: 
  Clone of Pit_Ip_EnableModule/5
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Pit_Ip_Init/19 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Pit_Ip_SetChainMode.constprop.0/42 (Pit_Ip_SetChainMode.constprop) @06ebb2a0
  Type: function definition analyzed
  Visibility:
  References: pitBase/2 (read)pitBase/2 (read)
  Referring: 
  Clone of Pit_Ip_SetChainMode/8
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01/34 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01/35 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_Reset.constprop.0/41 (Pit_Ip_Reset.constprop) @06ebb0e0
  Type: function definition analyzed
  Visibility:
  References: pitBase/2 (read)pitBase/2 (read)
  Referring: 
  Clone of Pit_Ip_Reset/9
  Availability: local
  Function flags: count:134217728 (estimated locally) local optimize_size
  Called by: Pit_Ip_Deinit/21 (1073634451 (estimated locally),1.00 per call) 
  Calls: 
Pit_Ip_ProcessCommonInterrupt.constprop.0/40 (Pit_Ip_ProcessCommonInterrupt.constprop) @06ebbd20
  Type: function definition analyzed
  Visibility:
  References: pitBase/2 (read)Pit_Ip_u32ChState/3 (read)Pit_Ip_u32ChState/3 (read)Pit_Ip_u32ChState/3 (read)Pit_Ip_u32ChState/3 (read)
  Referring: 
  Clone of Pit_Ip_ProcessCommonInterrupt/18
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: PIT_1_ISR/29 (920304118 (estimated locally),6.00 per call) 
  Calls: SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03/36 (145277269 (estimated locally),0.14 per call) Pit_Ip_ClearInterruptStatusFlag/14 (23970749 (estimated locally),0.02 per call) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03/37 (145277269 (estimated locally),0.14 per call) Pit_Ip_StopChannel/23 (7351030 (estimated locally),0.01 per call) 
   Indirect call(12711761 (estimated locally),0.01 per call) 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03/37 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03) @06a842a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_ProcessCommonInterrupt.constprop/40 (145277269 (estimated locally),0.14 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03/36 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03) @06a841c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_ProcessCommonInterrupt.constprop/40 (145277269 (estimated locally),0.14 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01/35 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01) @06fe8c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_SetChainMode.constprop/42 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01/34 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01) @06fe8b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_SetChainMode.constprop/42 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02/33 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02) @06fdc0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_SetEnableInterruptFlag/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02/32 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02) @06fdcee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_SetEnableInterruptFlag/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00/31 (SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00) @06fdcd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_EnableTimer/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00/30 (SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00) @06fdcc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Pit_Ip_EnableTimer/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
PIT_1_ISR/29 (PIT_1_ISR) @06fdc2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:153437706 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_ProcessCommonInterrupt.constprop/40 (920304118 (estimated locally),6.00 per call) 
Pit_Ip_GetLifetimeTimer/28 (Pit_Ip_GetLifetimeTimer) @06fdc000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_SetLifetimeTimer/27 (Pit_Ip_SetLifetimeTimer) @06fd3b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_EnableTimer/6 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableTimer/6 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetChainMode.constprop/42 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetEnableInterruptFlag/13 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_DisableChannelInterrupt/26 (Pit_Ip_DisableChannelInterrupt) @06fd3620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_ClearInterruptStatusFlag/14 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetEnableInterruptFlag/13 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_EnableChannelInterrupt/25 (Pit_Ip_EnableChannelInterrupt) @06fd30e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_SetEnableInterruptFlag/13 (1073741824 (estimated locally),1.00 per call) Pit_Ip_ClearInterruptStatusFlag/14 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_GetCurrentTimer/24 (Pit_Ip_GetCurrentTimer) @06fd3d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_StopChannel/23 (Pit_Ip_StopChannel) @06fd3a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Pit_Ip_ProcessCommonInterrupt.constprop/40 (7351030 (estimated locally),0.01 per call) 
  Calls: Pit_Ip_ClearInterruptStatusFlag/14 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableTimer/6 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_StartChannel/22 (Pit_Ip_StartChannel) @06fd37e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_EnableTimer/6 (354334802 (estimated locally),0.33 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_Deinit/21 (Pit_Ip_Deinit) @06fd3540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_Reset.constprop/41 (1073634451 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_InitChannel/20 (Pit_Ip_InitChannel) @06fd32a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Pit_Ip_u32ChState/3 (write)Pit_Ip_u32ChState/3 (write)Pit_Ip_u32ChState/3 (write)Pit_Ip_u32ChState/3 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_ClearInterruptStatusFlag/14 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetEnableInterruptFlag/13 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableTimer/6 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_Init/19 (Pit_Ip_Init) @06fd3000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_SetDebugMode/7 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableModule.constprop/43 (354334802 (estimated locally),0.33 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_ProcessCommonInterrupt/18 (Pit_Ip_ProcessCommonInterrupt) @06ebbb60
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_ClearInterruptStatusFlag/14 (Pit_Ip_ClearInterruptStatusFlag) @06ebba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Pit_Ip_ProcessCommonInterrupt.constprop/40 (23970749 (estimated locally),0.02 per call) Pit_Ip_DisableChannelInterrupt/26 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableChannelInterrupt/25 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StopChannel/23 (1073741824 (estimated locally),1.00 per call) Pit_Ip_InitChannel/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Pit_Ip_SetEnableInterruptFlag/13 (Pit_Ip_SetEnableInterruptFlag) @06ebb7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/2 (read)pitBase/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) Pit_Ip_DisableChannelInterrupt/26 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableChannelInterrupt/25 (1073741824 (estimated locally),1.00 per call) Pit_Ip_InitChannel/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02/33 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02/32 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_Reset/9 (Pit_Ip_Reset) @06eb37e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:134217728 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_SetChainMode/8 (Pit_Ip_SetChainMode) @06eb39a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_SetDebugMode/7 (Pit_Ip_SetDebugMode) @06eb3700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/2 (read)pitBase/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Pit_Ip_Init/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Pit_Ip_EnableTimer/6 (Pit_Ip_EnableTimer) @06eb3460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/2 (read)pitBase/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StopChannel/23 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StartChannel/22 (354334802 (estimated locally),0.33 per call) Pit_Ip_InitChannel/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00/31 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00/30 (1073741824 (estimated locally),1.00 per call) 
Pit_Ip_EnableModule/5 (Pit_Ip_EnableModule) @06eb31c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_GetLoadValue/4 (Pit_Ip_GetLoadValue) @06eafe00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pitBase/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Pit_Ip_u32ChState/3 (Pit_Ip_u32ChState) @06edb3a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Pit_Ip_InitChannel/20 (write)Pit_Ip_InitChannel/20 (write)Pit_Ip_InitChannel/20 (write)Pit_Ip_InitChannel/20 (write)Pit_Ip_ProcessCommonInterrupt.constprop.0/40 (read)Pit_Ip_ProcessCommonInterrupt.constprop.0/40 (read)Pit_Ip_ProcessCommonInterrupt.constprop.0/40 (read)Pit_Ip_ProcessCommonInterrupt.constprop.0/40 (read)
  Availability: available
  Varpool flags: initialized
pitBase/2 (pitBase) @06ed8750
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: Pit_Ip_SetEnableInterruptFlag/13 (read)Pit_Ip_EnableTimer/6 (read)Pit_Ip_Reset.constprop.0/41 (read)Pit_Ip_EnableModule.constprop.0/43 (read)Pit_Ip_ClearInterruptStatusFlag/14 (read)Pit_Ip_SetEnableInterruptFlag/13 (read)Pit_Ip_StartChannel/22 (read)Pit_Ip_SetDebugMode/7 (read)Pit_Ip_EnableTimer/6 (read)Pit_Ip_SetChainMode.constprop.0/42 (read)Pit_Ip_SetLifetimeTimer/27 (read)Pit_Ip_SetChainMode.constprop.0/42 (read)Pit_Ip_GetLoadValue/4 (read)Pit_Ip_ProcessCommonInterrupt.constprop.0/40 (read)Pit_Ip_Reset.constprop.0/41 (read)Pit_Ip_SetDebugMode/7 (read)Pit_Ip_GetCurrentTimer/24 (read)Pit_Ip_GetLifetimeTimer/28 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
DevAssert/0 (DevAssert) @06ea5a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: Pit_Ip_GetLifetimeTimer/28 (1073741824 (estimated locally),1.00 per call) Pit_Ip_SetLifetimeTimer/27 (1073741824 (estimated locally),1.00 per call) Pit_Ip_DisableChannelInterrupt/26 (1073741824 (estimated locally),1.00 per call) Pit_Ip_DisableChannelInterrupt/26 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableChannelInterrupt/25 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableChannelInterrupt/25 (1073741824 (estimated locally),1.00 per call) Pit_Ip_GetCurrentTimer/24 (1073741824 (estimated locally),1.00 per call) Pit_Ip_GetCurrentTimer/24 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StopChannel/23 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StopChannel/23 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StartChannel/22 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StartChannel/22 (1073741824 (estimated locally),1.00 per call) Pit_Ip_Deinit/21 (1073741824 (estimated locally),1.00 per call) Pit_Ip_InitChannel/20 (1073741824 (estimated locally),1.00 per call) Pit_Ip_InitChannel/20 (1073741824 (estimated locally),1.00 per call) Pit_Ip_InitChannel/20 (1073741824 (estimated locally),1.00 per call) Pit_Ip_Init/19 (1073741824 (estimated locally),1.00 per call) Pit_Ip_Init/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function DevAssert (DevAssert, funcdef_no=0, decl_uid=5896, cgraph_uid=1, symbol_order=0)

Modification phase of node DevAssert/0
DevAssert (volatile boolean x)
{
  _Bool x.0_1;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  x.0_1 ={v} x;
  if (x.0_1 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Pit_Ip_GetLoadValue (Pit_Ip_GetLoadValue, funcdef_no=2, decl_uid=5907, cgraph_uid=3, symbol_order=4)

Modification phase of node Pit_Ip_GetLoadValue/4
Pit_Ip_GetLoadValue (uint8 instance, uint8 channel)
{
  uint32 periodValue;
  int _1;
  struct PIT_Type * _2;
  int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG periodValue => 0
  # DEBUG BEGIN_STMT
  _1 = (int) instance_4(D);
  _2 = pitBase[_1];
  _3 = (int) channel_6(D);
  periodValue_7 ={v} _2->TIMER[_3].LDVAL;
  # DEBUG periodValue => periodValue_7
  # DEBUG BEGIN_STMT
  return periodValue_7;

}



;; Function Pit_Ip_Init (Pit_Ip_Init, funcdef_no=17, decl_uid=5910, cgraph_uid=18, symbol_order=19)

Modification phase of node Pit_Ip_Init/19
Pit_Ip_Init (uint8 instance, const struct Pit_Ip_InstanceConfigType * config)
{
  _Bool _1;
  _Bool _2;
  _Bool _3;
  _Bool _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_6(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = config_9(D) != 0B;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = config_9(D)->enableStandardTimers;
  if (_3 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableModule (instance_6(D), 0);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 = config_9(D)->stopRunInDebug;
  Pit_Ip_SetDebugMode (instance_6(D), _4);
  return;

}



;; Function Pit_Ip_InitChannel (Pit_Ip_InitChannel, funcdef_no=18, decl_uid=5913, cgraph_uid=19, symbol_order=20)

Modification phase of node Pit_Ip_InitChannel/20
Pit_Ip_InitChannel (uint8 instance, const struct Pit_Ip_ChannelConfigType * chnlConfig)
{
  _Bool _1;
  _Bool _2;
  unsigned char _3;
  _Bool _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  int _8;
  unsigned char _9;
  int _10;
  void (*<T49c>) (uint8) _11;
  unsigned char _12;
  <unnamed type> _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_14(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = chnlConfig_17(D) != 0B;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  _3 = chnlConfig_17(D)->hwChannel;
  _4 = _3 <= 6;
  DevAssert (_4);
  # DEBUG BEGIN_STMT
  _5 = chnlConfig_17(D)->hwChannel;
  Pit_Ip_EnableTimer (instance_14(D), _5, 0);
  # DEBUG BEGIN_STMT
  _6 = chnlConfig_17(D)->hwChannel;
  Pit_Ip_SetEnableInterruptFlag (instance_14(D), _6, 0);
  # DEBUG BEGIN_STMT
  _7 = chnlConfig_17(D)->hwChannel;
  Pit_Ip_ClearInterruptStatusFlag (instance_14(D), _7);
  # DEBUG BEGIN_STMT
  _8 = (int) instance_14(D);
  _9 = chnlConfig_17(D)->hwChannel;
  _10 = (int) _9;
  Pit_Ip_u32ChState[_8][_10].chInit = 1;
  # DEBUG BEGIN_STMT
  _11 = chnlConfig_17(D)->callback;
  Pit_Ip_u32ChState[_8][_10].callback = _11;
  # DEBUG BEGIN_STMT
  _12 = chnlConfig_17(D)->callbackParam;
  Pit_Ip_u32ChState[_8][_10].callbackParam = _12;
  # DEBUG BEGIN_STMT
  _13 = chnlConfig_17(D)->channelMode;
  Pit_Ip_u32ChState[_8][_10].channelMode = _13;
  return;

}



;; Function Pit_Ip_Deinit (Pit_Ip_Deinit, funcdef_no=19, decl_uid=5915, cgraph_uid=20, symbol_order=21)

Modification phase of node Pit_Ip_Deinit/21
Pit_Ip_Deinit (uint8 instance)
{
  boolean mdisBitExists;
  uint8 channelNum;
  _Bool _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_4(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  # DEBUG channelNum => 0
  # DEBUG BEGIN_STMT
  # DEBUG rtiChannelExists => 0
  # DEBUG BEGIN_STMT
  # DEBUG mdisBitExists => 0
  # DEBUG BEGIN_STMT
  switch (instance_4(D)) <default: <L4> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357878150]:
<L0>:
  # DEBUG BEGIN_STMT
  # DEBUG channelNum => 7
  # DEBUG BEGIN_STMT
  # DEBUG mdisBitExists => 1
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  # DEBUG channelNum => 6
  # DEBUG BEGIN_STMT
  # DEBUG mdisBitExists => 1
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073634451]:
  # channelNum_2 = PHI <7(3), 6(4), 0(2)>
  # mdisBitExists_3 = PHI <1(3), 1(4), 0(2)>
<L4>:
  # DEBUG mdisBitExists => mdisBitExists_3
  # DEBUG channelNum => channelNum_2
  # DEBUG BEGIN_STMT
  Pit_Ip_Reset (instance_4(D), channelNum_2, 0, mdisBitExists_3);
  return;

}



;; Function Pit_Ip_StartChannel (Pit_Ip_StartChannel, funcdef_no=20, decl_uid=5919, cgraph_uid=21, symbol_order=22)

Modification phase of node Pit_Ip_StartChannel/22
Pit_Ip_StartChannel (uint8 instance, uint8 channel, uint32 countValue)
{
  boolean isRunning;
  Pit_Ip_StatusType status;
  _Bool _1;
  _Bool _2;
  long unsigned int _3;
  int _13;
  struct PIT_Type * _14;
  int _15;
  long unsigned int _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_6(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = channel_9(D) <= 6;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  # DEBUG isRunning => 0
  # DEBUG BEGIN_STMT
  # DEBUG status => 1
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_6(D)
  # DEBUG channel => channel_9(D)
  # DEBUG INLINE_ENTRY Pit_Ip_IsChannelRunning
  # DEBUG BEGIN_STMT
  # DEBUG isRunning => 0
  # DEBUG BEGIN_STMT
  _13 = (int) instance_6(D);
  _14 = pitBase[_13];
  _15 = (int) channel_9(D);
  _16 ={v} _14->TIMER[_15].TCTRL;
  isRunning_17 = (boolean) _16;
  # DEBUG isRunning => isRunning_17
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG isRunning => NULL
  # DEBUG isRunning => isRunning_17
  # DEBUG BEGIN_STMT
  if (isRunning_17 != 0)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _3 = countValue_11(D) + 4294967295;
  # DEBUG instance => instance_6(D)
  # DEBUG channel => channel_9(D)
  # DEBUG value => _3
  # DEBUG INLINE_ENTRY Pit_Ip_SetCounterValue
  # DEBUG BEGIN_STMT
  _14->TIMER[_15].LDVAL ={v} _3;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableTimer (instance_6(D), channel_9(D), 1);
  # DEBUG BEGIN_STMT
  # DEBUG status => 0

  <bb 4> [local count: 1073741824]:
  # status_4 = PHI <1(2), 0(3)>
  # DEBUG status => status_4
  # DEBUG BEGIN_STMT
  return status_4;

}



;; Function Pit_Ip_StopChannel (Pit_Ip_StopChannel, funcdef_no=21, decl_uid=5922, cgraph_uid=22, symbol_order=23)

Modification phase of node Pit_Ip_StopChannel/23
Pit_Ip_StopChannel (uint8 instance, uint8 channel)
{
  _Bool _1;
  _Bool _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_3(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = channel_6(D) <= 6;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableTimer (instance_3(D), channel_6(D), 0);
  # DEBUG BEGIN_STMT
  Pit_Ip_ClearInterruptStatusFlag (instance_3(D), channel_6(D));
  return;

}



;; Function Pit_Ip_GetCurrentTimer (Pit_Ip_GetCurrentTimer, funcdef_no=22, decl_uid=5925, cgraph_uid=23, symbol_order=24)

Modification phase of node Pit_Ip_GetCurrentTimer/24
Pit_Ip_GetCurrentTimer (uint8 instance, uint8 channel)
{
  uint32 counterValue;
  uint64 counterValue;
  _Bool _1;
  _Bool _2;
  int _9;
  struct PIT_Type * _10;
  int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_3(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = channel_6(D) <= 6;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  # DEBUG counterValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_3(D)
  # DEBUG channel => channel_6(D)
  # DEBUG INLINE_ENTRY Pit_Ip_GetCounterValue
  # DEBUG BEGIN_STMT
  # DEBUG counterValue => 0
  # DEBUG BEGIN_STMT
  _9 = (int) instance_3(D);
  _10 = pitBase[_9];
  _11 = (int) channel_6(D);
  counterValue_12 ={v} _10->TIMER[_11].CVAL;
  # DEBUG counterValue => counterValue_12
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG counterValue => NULL
  counterValue_8 = (uint64) counterValue_12;
  # DEBUG counterValue => counterValue_8
  # DEBUG BEGIN_STMT
  return counterValue_8;

}



;; Function Pit_Ip_EnableChannelInterrupt (Pit_Ip_EnableChannelInterrupt, funcdef_no=23, decl_uid=5928, cgraph_uid=24, symbol_order=25)

Modification phase of node Pit_Ip_EnableChannelInterrupt/25
Pit_Ip_EnableChannelInterrupt (uint8 instance, uint8 channel)
{
  _Bool _1;
  _Bool _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_3(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = channel_6(D) <= 6;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  Pit_Ip_ClearInterruptStatusFlag (instance_3(D), channel_6(D));
  # DEBUG BEGIN_STMT
  Pit_Ip_SetEnableInterruptFlag (instance_3(D), channel_6(D), 1);
  return;

}



;; Function Pit_Ip_DisableChannelInterrupt (Pit_Ip_DisableChannelInterrupt, funcdef_no=24, decl_uid=5931, cgraph_uid=25, symbol_order=26)

Modification phase of node Pit_Ip_DisableChannelInterrupt/26
Pit_Ip_DisableChannelInterrupt (uint8 instance, uint8 channel)
{
  _Bool _1;
  _Bool _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_3(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = channel_6(D) <= 6;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  Pit_Ip_SetEnableInterruptFlag (instance_3(D), channel_6(D), 0);
  # DEBUG BEGIN_STMT
  Pit_Ip_ClearInterruptStatusFlag (instance_3(D), channel_6(D));
  return;

}



;; Function Pit_Ip_SetLifetimeTimer (Pit_Ip_SetLifetimeTimer, funcdef_no=25, decl_uid=5933, cgraph_uid=26, symbol_order=27)

Modification phase of node Pit_Ip_SetLifetimeTimer/27
Pit_Ip_SetLifetimeTimer (uint8 instance)
{
  _Bool _1;
  int _9;
  struct PIT_Type * _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_2(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG channel => 1
  # DEBUG value => 4294967295
  # DEBUG INLINE_ENTRY Pit_Ip_SetCounterValue
  # DEBUG BEGIN_STMT
  _9 = (int) instance_2(D);
  _10 = pitBase[_9];
  _10->TIMER[1].LDVAL ={v} 4294967295;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  Pit_Ip_SetEnableInterruptFlag (instance_2(D), 1, 0);
  # DEBUG BEGIN_STMT
  Pit_Ip_SetChainMode (instance_2(D), 1, 1);
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableTimer (instance_2(D), 1, 1);
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_2(D)
  # DEBUG channel => 0
  # DEBUG value => 4294967295
  # DEBUG INLINE_ENTRY Pit_Ip_SetCounterValue
  # DEBUG BEGIN_STMT
  _10->TIMER[0].LDVAL ={v} 4294967295;
  # DEBUG instance => NULL
  # DEBUG channel => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableTimer (instance_2(D), 0, 1);
  return;

}



;; Function Pit_Ip_GetLifetimeTimer (Pit_Ip_GetLifetimeTimer, funcdef_no=26, decl_uid=5935, cgraph_uid=27, symbol_order=28)

Modification phase of node Pit_Ip_GetLifetimeTimer/28
Pit_Ip_GetLifetimeTimer (uint8 instance)
{
  uint32 upperValue;
  uint32 lowerValue;
  uint64 lifeTimeValue;
  _Bool _1;
  long long unsigned int _2;
  long long unsigned int _3;
  long long unsigned int _4;
  int _10;
  struct PIT_Type * _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = instance_5(D) <= 1;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  # DEBUG lifeTimeValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG valueH => 0
  # DEBUG BEGIN_STMT
  # DEBUG valueL => 0
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_5(D)
  # DEBUG INLINE_ENTRY Pit_Ip_GetUpperLifetimerValue
  # DEBUG BEGIN_STMT
  # DEBUG upperValue => 0
  # DEBUG BEGIN_STMT
  _10 = (int) instance_5(D);
  _11 = pitBase[_10];
  upperValue_12 ={v} _11->LTMR64H;
  # DEBUG upperValue => upperValue_12
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG upperValue => NULL
  # DEBUG valueH => upperValue_12
  # DEBUG BEGIN_STMT
  # DEBUG instance => instance_5(D)
  # DEBUG INLINE_ENTRY Pit_Ip_GetLowerLifetimerValue
  # DEBUG BEGIN_STMT
  # DEBUG lowerValue => 0
  # DEBUG BEGIN_STMT
  lowerValue_9 ={v} _11->LTMR64L;
  # DEBUG lowerValue => lowerValue_9
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG lowerValue => NULL
  # DEBUG valueL => lowerValue_9
  # DEBUG BEGIN_STMT
  _2 = (long long unsigned int) upperValue_12;
  _3 = _2 << 32;
  _4 = (long long unsigned int) lowerValue_9;
  lifeTimeValue_8 = _3 + _4;
  # DEBUG lifeTimeValue => lifeTimeValue_8
  # DEBUG BEGIN_STMT
  return lifeTimeValue_8;

}



;; Function PIT_1_ISR (PIT_1_ISR, funcdef_no=27, decl_uid=5939, cgraph_uid=28, symbol_order=29)

Modification phase of node PIT_1_ISR/29
PIT_1_ISR ()
{
  uint8 channel;

  <bb 2> [local count: 153437706]:
  # DEBUG BEGIN_STMT
  # DEBUG instance => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG channel => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 920304118]:
  # DEBUG BEGIN_STMT
  Pit_Ip_ProcessCommonInterrupt (1, channel_1);
  # DEBUG BEGIN_STMT
  channel_5 = channel_1 + 1;
  # DEBUG channel => channel_5

  <bb 4> [local count: 1073741824]:
  # channel_1 = PHI <0(2), channel_5(3)>
  # DEBUG channel => channel_1
  # DEBUG BEGIN_STMT
  if (channel_1 != 6)
    goto <bb 3>; [85.71%]
  else
    goto <bb 5>; [14.29%]

  <bb 5> [local count: 153437707]:
  return;

}


