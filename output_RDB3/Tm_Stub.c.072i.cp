
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Gpt_StopTimer/5:
  Jump functions of caller  Gpt_GetTimeElapsed/4:
  Jump functions of caller  Gpt_StartTimer/3:
  Jump functions of caller  Tm_BusyWait1us32bit/2:

 Propagating constants:

Not considering Tm_BusyWait1us32bit for cloning; -fipa-cp-clone disabled.

overall_size: 22, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Tm_BusyWait1us32bit/2:
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

Gpt_StopTimer/5 (Gpt_StopTimer) @06f99a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Tm_BusyWait1us32bit/2 (118111601 (estimated locally),1.00 per call) 
  Calls: 
Gpt_GetTimeElapsed/4 (Gpt_GetTimeElapsed) @06f999a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Tm_BusyWait1us32bit/2 (1073741824 (estimated locally),9.09 per call) Tm_BusyWait1us32bit/2 (118111600 (estimated locally),1.00 per call) 
  Calls: 
Gpt_StartTimer/3 (Gpt_StartTimer) @06f998c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Tm_BusyWait1us32bit/2 (118111600 (estimated locally),1.00 per call) 
  Calls: 
Tm_BusyWait1us32bit/2 (Tm_BusyWait1us32bit) @06f99460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: Gpt_StopTimer/5 (118111601 (estimated locally),1.00 per call) Gpt_GetTimeElapsed/4 (1073741824 (estimated locally),9.09 per call) Gpt_GetTimeElapsed/4 (118111600 (estimated locally),1.00 per call) Gpt_StartTimer/3 (118111600 (estimated locally),1.00 per call) 

;; Function Tm_BusyWait1us32bit (Tm_BusyWait1us32bit, funcdef_no=2, decl_uid=6202, cgraph_uid=3, symbol_order=2)

Modification phase of node Tm_BusyWait1us32bit/2
Tm_BusyWait1us32bit (uint8 WaitingTimeMin)
{
  volatile Gpt_ValueType TimeNow;
  volatile Gpt_ValueType TimeStart;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int TimeNow.0_3;
  long unsigned int TimeStart.1_4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Gpt_StartTimer (1, 4294967294);
  # DEBUG BEGIN_STMT
  _1 = Gpt_GetTimeElapsed (1);
  TimeStart ={v} _1;

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = Gpt_GetTimeElapsed (1);
  TimeNow ={v} _2;
  # DEBUG BEGIN_STMT
  TimeNow.0_3 ={v} TimeNow;
  TimeStart.1_4 ={v} TimeStart;
  _5 = TimeNow.0_3 - TimeStart.1_4;
  _6 = (long unsigned int) WaitingTimeMin_15(D);
  _7 = _6 * 133;
  if (_5 < _7)
    goto <bb 5>; [89.00%]
  else
    goto <bb 4>; [11.00%]

  <bb 5> [local count: 955630223]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  Gpt_StopTimer (1);
  # DEBUG BEGIN_STMT
  return 0;

}


