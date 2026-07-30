
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Serdes_Ip_SetMode/9:
  Jump functions of caller  Serdes_Ip_GetStatus/8:
  Jump functions of caller  Serdes_Ip_MainFunction/7:
  Jump functions of caller  Serdes_Ip_GetJobResult/6:
  Jump functions of caller  Serdes_Ip_Init/5:
  Jump functions of caller  Serdes_Ipw_SetMode/4:
  Jump functions of caller  Serdes_Ipw_GetJobResult/3:
  Jump functions of caller  Serdes_Ipw_GetStatus/2:
  Jump functions of caller  Serdes_Ipw_MainFunction/1:
  Jump functions of caller  Serdes_Ipw_InitChannel/0:

 Propagating constants:

Not considering Serdes_Ipw_SetMode for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ipw_GetJobResult for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ipw_GetStatus for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ipw_MainFunction for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ipw_InitChannel for cloning; -fipa-cp-clone disabled.

overall_size: 63, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Serdes_Ipw_SetMode/4:
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
  Node: Serdes_Ipw_GetJobResult/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Serdes_Ipw_GetStatus/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Serdes_Ipw_MainFunction/1:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Serdes_Ipw_InitChannel/0:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Serdes_Ip_SetMode/9 (Serdes_Ip_SetMode) @0756c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ipw_SetMode/4 (268435456 (estimated locally),0.25 per call) Serdes_Ipw_SetMode/4 (268435456 (estimated locally),0.25 per call) Serdes_Ipw_SetMode/4 (268435456 (estimated locally),0.25 per call) 
  Calls: 
Serdes_Ip_GetStatus/8 (Serdes_Ip_GetStatus) @075637e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ipw_GetStatus/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_MainFunction/7 (Serdes_Ip_MainFunction) @075632a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ipw_MainFunction/1 (343919506 (estimated locally),0.32 per call) 
  Calls: 
Serdes_Ip_GetJobResult/6 (Serdes_Ip_GetJobResult) @07563000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ipw_GetJobResult/3 (1073741823 (estimated locally),1.00 per call) Serdes_Ipw_MainFunction/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_Init/5 (Serdes_Ip_Init) @07563e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ipw_InitChannel/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ipw_SetMode/4 (Serdes_Ipw_SetMode) @075639a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Serdes_Ip_SetMode/9 (268435456 (estimated locally),0.25 per call) Serdes_Ip_SetMode/9 (268435456 (estimated locally),0.25 per call) Serdes_Ip_SetMode/9 (268435456 (estimated locally),0.25 per call) 
Serdes_Ipw_GetJobResult/3 (Serdes_Ipw_GetJobResult) @07563700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: Serdes_Ip_GetJobResult/6 (1073741823 (estimated locally),1.00 per call) 
Serdes_Ipw_GetStatus/2 (Serdes_Ipw_GetStatus) @07563460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Serdes_Ip_GetStatus/8 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ipw_MainFunction/1 (Serdes_Ipw_MainFunction) @075631c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Serdes_Ip_MainFunction/7 (343919506 (estimated locally),0.32 per call) Serdes_Ip_GetJobResult/6 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ipw_InitChannel/0 (Serdes_Ipw_InitChannel) @0755be00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Serdes_Ip_Init/5 (1073741824 (estimated locally),1.00 per call) 

;; Function Serdes_Ipw_InitChannel (Serdes_Ipw_InitChannel, funcdef_no=0, decl_uid=5726, cgraph_uid=1, symbol_order=0)

Modification phase of node Serdes_Ipw_InitChannel/0
Serdes_Ipw_InitChannel (const uint8 Instance, const struct Serdes_Ipw_HwChannelConfigType * ConfigPtr)
{
  Std_ReturnType StdStatus;
  Serdes_Ip_StatusType Status;
  const struct Serdes_Ip_ConfigType * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG StdStatus => 1
  # DEBUG BEGIN_STMT
  _1 = ConfigPtr_4(D)->SerdesHwConfig;
  Status_7 = Serdes_Ip_Init (Instance_5(D), _1);
  # DEBUG Status => Status_7
  # DEBUG BEGIN_STMT
  if (Status_7 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG StdStatus => 0

  <bb 4> [local count: 1073741824]:
  # StdStatus_2 = PHI <1(2), 0(3)>
  # DEBUG StdStatus => StdStatus_2
  # DEBUG BEGIN_STMT
  return StdStatus_2;

}



;; Function Serdes_Ipw_MainFunction (Serdes_Ipw_MainFunction, funcdef_no=1, decl_uid=5728, cgraph_uid=2, symbol_order=1)

Modification phase of node Serdes_Ipw_MainFunction/1
Serdes_Ipw_MainFunction (uint8 Instance)
{
  Serdes_StatusType Status;
  <unnamed type> _1;
  <unnamed type> _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 3
  # DEBUG BEGIN_STMT
  _1 = Serdes_Ip_GetJobResult (Instance_6(D));
  if (_1 == 2)
    goto <bb 3>; [32.03%]
  else
    goto <bb 5>; [67.97%]

  <bb 3> [local count: 343919506]:
  # DEBUG BEGIN_STMT
  _2 = Serdes_Ip_MainFunction (Instance_6(D));
  if (_2 == 0)
    goto <bb 4>; [65.00%]
  else
    goto <bb 5>; [35.00%]

  <bb 4> [local count: 223547679]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 1

  <bb 5> [local count: 1073741824]:
  # Status_3 = PHI <3(2), 3(3), 1(4)>
  # DEBUG Status => Status_3
  # DEBUG BEGIN_STMT
  return Status_3;

}



;; Function Serdes_Ipw_GetStatus (Serdes_Ipw_GetStatus, funcdef_no=2, decl_uid=5730, cgraph_uid=3, symbol_order=2)

Modification phase of node Serdes_Ipw_GetStatus/2
Serdes_Ipw_GetStatus (uint8 Instance)
{
  Serdes_Ip_StatusType Status;
  Serdes_StatusType RetStatus;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetStatus => 3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Status_5 = Serdes_Ip_GetStatus (Instance_3(D));
  # DEBUG Status => Status_5
  # DEBUG BEGIN_STMT
  if (Status_5 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (Status_5 == 1)
    goto <bb 5>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 4> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG RetStatus => 3

  <bb 5> [local count: 1073741824]:
  # RetStatus_1 = PHI <1(2), 2(3), 3(4)>
  # DEBUG RetStatus => RetStatus_1
  # DEBUG BEGIN_STMT
  return RetStatus_1;

}



;; Function Serdes_Ipw_GetJobResult (Serdes_Ipw_GetJobResult, funcdef_no=3, decl_uid=5732, cgraph_uid=4, symbol_order=3)

Modification phase of node Serdes_Ipw_GetJobResult/3
Serdes_Ipw_GetJobResult (uint8 Instance)
{
  Serdes_Ip_JobResultType JobResult;
  Serdes_JobResultType RetJobResult;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG RetJobResult => 4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  JobResult_5 = Serdes_Ip_GetJobResult (Instance_3(D));
  # DEBUG JobResult => JobResult_5
  # DEBUG BEGIN_STMT
  if (JobResult_5 == 1)
    goto <bb 5>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  if (JobResult_5 == 2)
    goto <bb 5>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 4> [local count: 467721938]:
  # DEBUG BEGIN_STMT
  # DEBUG RetJobResult => 4

  <bb 5> [local count: 1073741824]:
  # RetJobResult_1 = PHI <1(2), 2(3), 4(4)>
  # DEBUG RetJobResult => RetJobResult_1
  # DEBUG BEGIN_STMT
  return RetJobResult_1;

}



;; Function Serdes_Ipw_SetMode (Serdes_Ipw_SetMode, funcdef_no=4, decl_uid=5735, cgraph_uid=5, symbol_order=4)

Modification phase of node Serdes_Ipw_SetMode/4
Serdes_Ipw_SetMode (uint8 Instance, Serdes_ModeType Mode)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  switch (Mode_2(D)) <default: <L5> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  Serdes_Ip_SetMode (Instance_4(D), 1);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  Serdes_Ip_SetMode (Instance_4(D), 3);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  Serdes_Ip_SetMode (Instance_4(D), 2);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L5>:
  return;

}


