
IPA constant propagation start:
Determining dynamic type for call: returnValue_8 = Gpt_Ipw_PitGetTimeElapsed (pHwChannelConfig_5(D), pReturnHwChannelInfo_6(D));
  Starting walk at: returnValue_8 = Gpt_Ipw_PitGetTimeElapsed (pHwChannelConfig_5(D), pReturnHwChannelInfo_6(D));
  instance pointer: pHwChannelConfig_5(D)  Outer instance pointer: pHwChannelConfig_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: returnValue_8 = Gpt_Ipw_PitGetTimeElapsed (pHwChannelConfig_5(D), pReturnHwChannelInfo_6(D));
  Starting walk at: returnValue_8 = Gpt_Ipw_PitGetTimeElapsed (pHwChannelConfig_5(D), pReturnHwChannelInfo_6(D));
  instance pointer: pReturnHwChannelInfo_6(D)  Outer instance pointer: pReturnHwChannelInfo_6(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Pit_Ip_DisableChannelInterrupt/20:
  Jump functions of caller  Pit_Ip_Deinit/19:
  Jump functions of caller  Pit_Ip_EnableChannelInterrupt/18:
  Jump functions of caller  Pit_Ip_StopChannel/17:
  Jump functions of caller  Pit_Ip_GetCurrentTimer/15:
  Jump functions of caller  Pit_Ip_GetLoadValue/14:
  Jump functions of caller  Pit_Ip_StartChannel/13:
  Jump functions of caller  Pit_Ip_InitChannel/12:
  Jump functions of caller  Pit_Ip_Init/11:
  Jump functions of caller  Gpt_Ipw_DisableInterrupt/10:
  Jump functions of caller  Gpt_Ipw_DeInit/9:
  Jump functions of caller  Gpt_Ipw_EnableInterrupt/8:
  Jump functions of caller  Gpt_Ipw_StopTimer/7:
  Jump functions of caller  Gpt_Ipw_GetTimeElapsed/6:
    callsite  Gpt_Ipw_GetTimeElapsed/6 -> Gpt_Ipw_PitGetTimeElapsed/2 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Gpt_Ipw_StartTimer/5:
  Jump functions of caller  Gpt_Ipw_Init/4:
  Jump functions of caller  Gpt_Ipw_InitInstances/3:
  Jump functions of caller  Gpt_Ipw_PitGetTimeElapsed/2:

 Propagating constants:

Not considering Gpt_Ipw_DisableInterrupt for cloning; -fipa-cp-clone disabled.
Not considering Gpt_Ipw_DeInit for cloning; -fipa-cp-clone disabled.
Not considering Gpt_Ipw_EnableInterrupt for cloning; -fipa-cp-clone disabled.
Not considering Gpt_Ipw_StopTimer for cloning; -fipa-cp-clone disabled.
Not considering Gpt_Ipw_GetTimeElapsed for cloning; -fipa-cp-clone disabled.
Not considering Gpt_Ipw_StartTimer for cloning; -fipa-cp-clone disabled.
Not considering Gpt_Ipw_Init for cloning; -fipa-cp-clone disabled.
Not considering Gpt_Ipw_InitInstances for cloning; -fipa-cp-clone disabled.

overall_size: 119, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Gpt_Ipw_DisableInterrupt/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_Ipw_DeInit/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_Ipw_EnableInterrupt/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_Ipw_StopTimer/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_Ipw_GetTimeElapsed/6:
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
  Node: Gpt_Ipw_StartTimer/5:
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
  Node: Gpt_Ipw_Init/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_Ipw_InitInstances/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gpt_Ipw_PitGetTimeElapsed/2:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Pit_Ip_DisableChannelInterrupt/20 (Pit_Ip_DisableChannelInterrupt) @06f99000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_DisableInterrupt/10 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Pit_Ip_Deinit/19 (Pit_Ip_Deinit) @06f8fe00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_DeInit/9 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Pit_Ip_EnableChannelInterrupt/18 (Pit_Ip_EnableChannelInterrupt) @06f8fc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_EnableInterrupt/8 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Pit_Ip_StopChannel/17 (Pit_Ip_StopChannel) @06f8fa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_StopTimer/7 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pitBase/16 (pitBase) @06f94678
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Gpt_Ipw_PitGetTimeElapsed/2 (read)
  Availability: not_available
  Varpool flags: read-only
Pit_Ip_GetCurrentTimer/15 (Pit_Ip_GetCurrentTimer) @06f8f7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_PitGetTimeElapsed/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Pit_Ip_GetLoadValue/14 (Pit_Ip_GetLoadValue) @06f8f700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_PitGetTimeElapsed/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Pit_Ip_StartChannel/13 (Pit_Ip_StartChannel) @06f8f460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_StartTimer/5 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Pit_Ip_InitChannel/12 (Pit_Ip_InitChannel) @06f8f2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_Init/4 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Pit_Ip_Init/11 (Pit_Ip_Init) @06f8f0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gpt_Ipw_InitInstances/3 (315357973 (estimated locally),2.67 per call) 
  Calls: 
Gpt_Ipw_DisableInterrupt/10 (Gpt_Ipw_DisableInterrupt) @06f85620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_DisableChannelInterrupt/20 (354334802 (estimated locally),0.33 per call) 
Gpt_Ipw_DeInit/9 (Gpt_Ipw_DeInit) @06f850e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_Deinit/19 (354334802 (estimated locally),0.33 per call) 
Gpt_Ipw_EnableInterrupt/8 (Gpt_Ipw_EnableInterrupt) @06f85d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_EnableChannelInterrupt/18 (354334802 (estimated locally),0.33 per call) 
Gpt_Ipw_StopTimer/7 (Gpt_Ipw_StopTimer) @06f85a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_StopChannel/17 (354334802 (estimated locally),0.33 per call) 
Gpt_Ipw_GetTimeElapsed/6 (Gpt_Ipw_GetTimeElapsed) @06f857e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_Ipw_PitGetTimeElapsed/2 (354334802 (estimated locally),0.33 per call) 
Gpt_Ipw_StartTimer/5 (Gpt_Ipw_StartTimer) @06f85540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_StartChannel/13 (354334802 (estimated locally),0.33 per call) 
Gpt_Ipw_Init/4 (Gpt_Ipw_Init) @06f852a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_InitChannel/12 (354334802 (estimated locally),0.33 per call) 
Gpt_Ipw_InitInstances/3 (Gpt_Ipw_InitInstances) @06f85000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111602 (estimated locally) body optimize_size
  Called by: 
  Calls: Pit_Ip_Init/11 (315357973 (estimated locally),2.67 per call) 
Gpt_Ipw_PitGetTimeElapsed/2 (Gpt_Ipw_PitGetTimeElapsed) @06f7eee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pitBase/16 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Gpt_Ipw_GetTimeElapsed/6 (354334802 (estimated locally),0.33 per call) 
  Calls: Pit_Ip_GetCurrentTimer/15 (1073741824 (estimated locally),1.00 per call) Pit_Ip_GetLoadValue/14 (1073741824 (estimated locally),1.00 per call) 

;; Function Gpt_Ipw_InitInstances (Gpt_Ipw_InitInstances, funcdef_no=3, decl_uid=6208, cgraph_uid=4, symbol_order=3)

Modification phase of node Gpt_Ipw_InitInstances/3
Gpt_Ipw_InitInstances (const struct Gpt_ConfigType * configPtr)
{
  uint8 index;
  struct Gpt_Ipw_HwInstanceConfigType[<unknown>] * _1;
  int _2;
  <unnamed type> _3;
  unsigned char _4;
  const struct Pit_Ip_InstanceConfigType * _5;
  unsigned char _6;

  <bb 2> [local count: 118111602]:
  # DEBUG BEGIN_STMT
  # DEBUG index => 0
  # DEBUG BEGIN_STMT
  # DEBUG index => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = configPtr_11(D)->Gpt_Ipw_HwInstanceConfig;
  _2 = (int) index_7;
  _3 = *_1[_2].instanceType;
  if (_3 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 315357973]:
<L1>:
  # DEBUG BEGIN_STMT
  _4 = *_1[_2].instance;
  _5 = *_1[_2].Gpt_Ipw_InstanceConfig.Pit_Ip_InstanceConfig;
  Pit_Ip_Init (_4, _5);
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  index_13 = index_7 + 1;
  # DEBUG index => index_13

  <bb 6> [local count: 1073741824]:
  # index_7 = PHI <0(2), index_13(5)>
  # DEBUG index => index_7
  # DEBUG BEGIN_STMT
  _6 = configPtr_11(D)->instanceCount;
  if (_6 > index_7)
    goto <bb 3>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_Ipw_Init (Gpt_Ipw_Init, funcdef_no=4, decl_uid=6206, cgraph_uid=5, symbol_order=4)

Modification phase of node Gpt_Ipw_Init/4
Gpt_Ipw_Init (const struct Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
  <unnamed type> _1;
  unsigned char _2;
  const struct Pit_Ip_ChannelConfigType * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pHwChannelConfig_6(D)->instanceType;
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
<L0>:
  # DEBUG BEGIN_STMT
  _2 = pHwChannelConfig_6(D)->instance;
  _3 = pHwChannelConfig_6(D)->Gpt_Ipw_ChannelConfig.Pit_Ip_ChannelConfig;
  Pit_Ip_InitChannel (_2, _3);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_Ipw_StartTimer (Gpt_Ipw_StartTimer, funcdef_no=5, decl_uid=6214, cgraph_uid=6, symbol_order=5)

Modification phase of node Gpt_Ipw_StartTimer/5
Gpt_Ipw_StartTimer (const struct Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_ValueType uValue)
{
  Std_ReturnType returnValue;
  <unnamed type> _1;
  unsigned char _2;
  unsigned char _3;
  <unnamed type> _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 1
  # DEBUG BEGIN_STMT
  _1 = pHwChannelConfig_8(D)->instanceType;
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
<L0>:
  # DEBUG BEGIN_STMT
  _2 = pHwChannelConfig_8(D)->instance;
  _3 = pHwChannelConfig_8(D)->channel;
  _4 = Pit_Ip_StartChannel (_2, _3, uValue_9(D));
  returnValue_11 = (Std_ReturnType) _4;
  # DEBUG returnValue => returnValue_11
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # returnValue_5 = PHI <returnValue_11(3), 1(2)>
  # DEBUG returnValue => returnValue_5
  # DEBUG BEGIN_STMT
  return returnValue_5;

}



;; Function Gpt_Ipw_GetTimeElapsed (Gpt_Ipw_GetTimeElapsed, funcdef_no=6, decl_uid=6211, cgraph_uid=7, symbol_order=6)

Modification phase of node Gpt_Ipw_GetTimeElapsed/6
Gpt_Ipw_GetTimeElapsed (const struct Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, struct Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
  uint32 returnValue;
  <unnamed type> _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT
  _1 = pHwChannelConfig_5(D)->instanceType;
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
<L0>:
  # DEBUG BEGIN_STMT
  returnValue_8 = Gpt_Ipw_PitGetTimeElapsed (pHwChannelConfig_5(D), pReturnHwChannelInfo_6(D));
  # DEBUG returnValue => returnValue_8
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # returnValue_2 = PHI <returnValue_8(3), 0(2)>
  # DEBUG returnValue => returnValue_2
  # DEBUG BEGIN_STMT
  return returnValue_2;

}



;; Function Gpt_Ipw_StopTimer (Gpt_Ipw_StopTimer, funcdef_no=7, decl_uid=6216, cgraph_uid=8, symbol_order=7)

Modification phase of node Gpt_Ipw_StopTimer/7
Gpt_Ipw_StopTimer (const struct Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
  <unnamed type> _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pHwChannelConfig_6(D)->instanceType;
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
<L0>:
  # DEBUG BEGIN_STMT
  _2 = pHwChannelConfig_6(D)->instance;
  _3 = pHwChannelConfig_6(D)->channel;
  Pit_Ip_StopChannel (_2, _3);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_Ipw_EnableInterrupt (Gpt_Ipw_EnableInterrupt, funcdef_no=8, decl_uid=6218, cgraph_uid=9, symbol_order=8)

Modification phase of node Gpt_Ipw_EnableInterrupt/8
Gpt_Ipw_EnableInterrupt (const struct Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
  <unnamed type> _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pHwChannelConfig_6(D)->instanceType;
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
<L0>:
  # DEBUG BEGIN_STMT
  _2 = pHwChannelConfig_6(D)->instance;
  _3 = pHwChannelConfig_6(D)->channel;
  Pit_Ip_EnableChannelInterrupt (_2, _3);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_Ipw_DeInit (Gpt_Ipw_DeInit, funcdef_no=9, decl_uid=6220, cgraph_uid=10, symbol_order=9)

Modification phase of node Gpt_Ipw_DeInit/9
Gpt_Ipw_DeInit (const struct Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
  <unnamed type> _1;
  unsigned char _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pHwChannelConfig_5(D)->instanceType;
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
<L0>:
  # DEBUG BEGIN_STMT
  _2 = pHwChannelConfig_5(D)->instance;
  Pit_Ip_Deinit (_2);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Gpt_Ipw_DisableInterrupt (Gpt_Ipw_DisableInterrupt, funcdef_no=10, decl_uid=6222, cgraph_uid=11, symbol_order=10)

Modification phase of node Gpt_Ipw_DisableInterrupt/10
Gpt_Ipw_DisableInterrupt (const struct Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
  <unnamed type> _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pHwChannelConfig_6(D)->instanceType;
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
<L0>:
  # DEBUG BEGIN_STMT
  _2 = pHwChannelConfig_6(D)->instance;
  _3 = pHwChannelConfig_6(D)->channel;
  Pit_Ip_DisableChannelInterrupt (_2, _3);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}


