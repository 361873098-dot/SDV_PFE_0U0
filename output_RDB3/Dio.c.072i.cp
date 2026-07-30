
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Dio_Ipw_WriteChannelGroup/13:
  Jump functions of caller  Dio_Ipw_ReadChannelGroup/12:
  Jump functions of caller  Dio_Ipw_WritePort/11:
  Jump functions of caller  Dio_Ipw_ReadPort/10:
  Jump functions of caller  Dio_Ipw_FlipChannel/9:
  Jump functions of caller  Dio_Ipw_WriteChannel/8:
  Jump functions of caller  Dio_Ipw_ReadChannel/7:
  Jump functions of caller  Dio_WriteChannelGroup/6:
  Jump functions of caller  Dio_ReadChannelGroup/5:
  Jump functions of caller  Dio_WritePort/4:
  Jump functions of caller  Dio_ReadPort/3:
  Jump functions of caller  Dio_FlipChannel/2:
  Jump functions of caller  Dio_WriteChannel/1:
  Jump functions of caller  Dio_ReadChannel/0:

 Propagating constants:

Not considering Dio_WriteChannelGroup for cloning; -fipa-cp-clone disabled.
Not considering Dio_ReadChannelGroup for cloning; -fipa-cp-clone disabled.
Not considering Dio_WritePort for cloning; -fipa-cp-clone disabled.
Not considering Dio_ReadPort for cloning; -fipa-cp-clone disabled.
Not considering Dio_FlipChannel for cloning; -fipa-cp-clone disabled.
Not considering Dio_WriteChannel for cloning; -fipa-cp-clone disabled.
Not considering Dio_ReadChannel for cloning; -fipa-cp-clone disabled.

overall_size: 42, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Dio_WriteChannelGroup/6:
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
  Node: Dio_ReadChannelGroup/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Dio_WritePort/4:
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
  Node: Dio_ReadPort/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Dio_FlipChannel/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Dio_WriteChannel/1:
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
  Node: Dio_ReadChannel/0:
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

Dio_Ipw_WriteChannelGroup/13 (Dio_Ipw_WriteChannelGroup) @070a6540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Dio_WriteChannelGroup/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Dio_Ipw_ReadChannelGroup/12 (Dio_Ipw_ReadChannelGroup) @070a6380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Dio_ReadChannelGroup/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Dio_Ipw_WritePort/11 (Dio_Ipw_WritePort) @070a61c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Dio_WritePort/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Dio_Ipw_ReadPort/10 (Dio_Ipw_ReadPort) @070a6000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Dio_ReadPort/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Dio_Ipw_FlipChannel/9 (Dio_Ipw_FlipChannel) @070a4540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Dio_FlipChannel/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Dio_Ipw_WriteChannel/8 (Dio_Ipw_WriteChannel) @070a4000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Dio_WriteChannel/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Dio_Ipw_ReadChannel/7 (Dio_Ipw_ReadChannel) @070a4e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Dio_ReadChannel/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Dio_WriteChannelGroup/6 (Dio_WriteChannelGroup) @070a49a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dio_Ipw_WriteChannelGroup/13 (1073741824 (estimated locally),1.00 per call) 
Dio_ReadChannelGroup/5 (Dio_ReadChannelGroup) @070a4700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dio_Ipw_ReadChannelGroup/12 (1073741824 (estimated locally),1.00 per call) 
Dio_WritePort/4 (Dio_WritePort) @070a4460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dio_Ipw_WritePort/11 (1073741824 (estimated locally),1.00 per call) 
Dio_ReadPort/3 (Dio_ReadPort) @070a41c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dio_Ipw_ReadPort/10 (1073741824 (estimated locally),1.00 per call) 
Dio_FlipChannel/2 (Dio_FlipChannel) @0709ee00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dio_Ipw_FlipChannel/9 (1073741824 (estimated locally),1.00 per call) 
Dio_WriteChannel/1 (Dio_WriteChannel) @0709e9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dio_Ipw_WriteChannel/8 (1073741824 (estimated locally),1.00 per call) 
Dio_ReadChannel/0 (Dio_ReadChannel) @0709ed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dio_Ipw_ReadChannel/7 (1073741824 (estimated locally),1.00 per call) 

;; Function Dio_ReadChannel (Dio_ReadChannel, funcdef_no=0, decl_uid=5650, cgraph_uid=1, symbol_order=0)

Modification phase of node Dio_ReadChannel/0
Dio_ReadChannel (Dio_ChannelType ChannelId)
{
  Dio_LevelType ChannelLevel;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ChannelLevel => 0
  # DEBUG BEGIN_STMT
  ChannelLevel_4 = Dio_Ipw_ReadChannel (ChannelId_2(D));
  # DEBUG ChannelLevel => ChannelLevel_4
  # DEBUG BEGIN_STMT
  return ChannelLevel_4;

}



;; Function Dio_WriteChannel (Dio_WriteChannel, funcdef_no=1, decl_uid=5653, cgraph_uid=2, symbol_order=1)

Modification phase of node Dio_WriteChannel/1
Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Dio_Ipw_WriteChannel (ChannelId_2(D), Level_3(D));
  return;

}



;; Function Dio_FlipChannel (Dio_FlipChannel, funcdef_no=2, decl_uid=5655, cgraph_uid=3, symbol_order=2)

Modification phase of node Dio_FlipChannel/2
Dio_FlipChannel (Dio_ChannelType ChannelId)
{
  Dio_LevelType ChannelLevel;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ChannelLevel => 0
  # DEBUG BEGIN_STMT
  ChannelLevel_4 = Dio_Ipw_FlipChannel (ChannelId_2(D));
  # DEBUG ChannelLevel => ChannelLevel_4
  # DEBUG BEGIN_STMT
  return ChannelLevel_4;

}



;; Function Dio_ReadPort (Dio_ReadPort, funcdef_no=3, decl_uid=5657, cgraph_uid=4, symbol_order=3)

Modification phase of node Dio_ReadPort/3
Dio_ReadPort (Dio_PortType PortId)
{
  Dio_PortLevelType PortLevel;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG PortLevel => 0
  # DEBUG BEGIN_STMT
  PortLevel_4 = Dio_Ipw_ReadPort (PortId_2(D));
  # DEBUG PortLevel => PortLevel_4
  # DEBUG BEGIN_STMT
  return PortLevel_4;

}



;; Function Dio_WritePort (Dio_WritePort, funcdef_no=4, decl_uid=5660, cgraph_uid=5, symbol_order=4)

Modification phase of node Dio_WritePort/4
Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Dio_Ipw_WritePort (PortId_2(D), Level_3(D));
  return;

}



;; Function Dio_ReadChannelGroup (Dio_ReadChannelGroup, funcdef_no=5, decl_uid=5662, cgraph_uid=6, symbol_order=5)

Modification phase of node Dio_ReadChannelGroup/5
Dio_ReadChannelGroup (const struct Dio_ChannelGroupType * ChannelGroupIdPtr)
{
  Dio_PortLevelType PortLevel;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG PortLevel => 0
  # DEBUG BEGIN_STMT
  PortLevel_4 = Dio_Ipw_ReadChannelGroup (ChannelGroupIdPtr_2(D));
  # DEBUG PortLevel => PortLevel_4
  # DEBUG BEGIN_STMT
  return PortLevel_4;

}



;; Function Dio_WriteChannelGroup (Dio_WriteChannelGroup, funcdef_no=6, decl_uid=5665, cgraph_uid=7, symbol_order=6)

Modification phase of node Dio_WriteChannelGroup/6
Dio_WriteChannelGroup (const struct Dio_ChannelGroupType * ChannelGroupIdPtr, Dio_PortLevelType Level)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Dio_Ipw_WriteChannelGroup (ChannelGroupIdPtr_2(D), Level_3(D));
  return;

}


