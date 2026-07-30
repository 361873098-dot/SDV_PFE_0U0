
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  System_Ip_SetAhbSlavePriorityPrivileged.part.0/9:
  Jump functions of caller  System_Ip_GetPlatformRevision/8:
  Jump functions of caller  System_Ip_ClearWriteAbortFlag/7:
  Jump functions of caller  System_Ip_ConfigIrq/6:
    callsite  System_Ip_ConfigIrq/6 -> System_Ip_ConfigIrqPrivileged/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  System_Ip_SetAhbSlavePriority/5:
    callsite  System_Ip_SetAhbSlavePriority/5 -> System_Ip_SetAhbSlavePriorityPrivileged/1 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  System_Ip_GetPlatformRevisionPrivileged/4:
  Jump functions of caller  System_Ip_ClearWriteAbortFlagPrivileged/3:
  Jump functions of caller  System_Ip_ConfigIrqPrivileged/2:
  Jump functions of caller  System_Ip_SetAhbSlavePriorityPrivileged/1:
    callsite  System_Ip_SetAhbSlavePriorityPrivileged/1 -> System_Ip_SetAhbSlavePriorityPrivileged.part.0/9 : 

 Propagating constants:

Not considering System_Ip_GetPlatformRevision for cloning; -fipa-cp-clone disabled.
Not considering System_Ip_ClearWriteAbortFlag for cloning; -fipa-cp-clone disabled.
Not considering System_Ip_ConfigIrq for cloning; -fipa-cp-clone disabled.
Not considering System_Ip_SetAhbSlavePriority for cloning; -fipa-cp-clone disabled.
Function System_Ip_GetPlatformRevisionPrivileged/4 is not versionable, reason: not a tree_versionable_function.
Function System_Ip_ClearWriteAbortFlagPrivileged/3 is not versionable, reason: not a tree_versionable_function.
Not considering System_Ip_ConfigIrqPrivileged for cloning; -fipa-cp-clone disabled.
Not considering System_Ip_SetAhbSlavePriorityPrivileged for cloning; -fipa-cp-clone disabled.

overall_size: 56, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: System_Ip_SetAhbSlavePriorityPrivileged.part.0/9:
  Node: System_Ip_GetPlatformRevision/8:
  Node: System_Ip_ClearWriteAbortFlag/7:
  Node: System_Ip_ConfigIrq/6:
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
  Node: System_Ip_SetAhbSlavePriority/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: System_Ip_GetPlatformRevisionPrivileged/4:
  Node: System_Ip_ClearWriteAbortFlagPrivileged/3:
  Node: System_Ip_ConfigIrqPrivileged/2:
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
  Node: System_Ip_SetAhbSlavePriorityPrivileged/1:
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

System_Ip_SetAhbSlavePriorityPrivileged.part.0/9 (System_Ip_SetAhbSlavePriorityPrivileged.part.0) @06eb9000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: System_Ip_SetAhbSlavePriorityPrivileged/1 (536870912 (estimated locally),0.50 per call) 
  Calls: 
System_Ip_GetPlatformRevision/8 (System_Ip_GetPlatformRevision) @06ec39a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: System_Ip_GetPlatformRevisionPrivileged/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
System_Ip_ClearWriteAbortFlag/7 (System_Ip_ClearWriteAbortFlag) @06ec3700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: System_Ip_ClearWriteAbortFlagPrivileged/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
System_Ip_ConfigIrq/6 (System_Ip_ConfigIrq) @06ec3460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: System_Ip_ConfigIrqPrivileged/2 (1073741824 (estimated locally),1.00 per call) 
System_Ip_SetAhbSlavePriority/5 (System_Ip_SetAhbSlavePriority) @06ec31c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: System_Ip_SetAhbSlavePriorityPrivileged/1 (1073741824 (estimated locally),1.00 per call) 
System_Ip_GetPlatformRevisionPrivileged/4 (System_Ip_GetPlatformRevisionPrivileged) @06eb9e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: System_Ip_GetPlatformRevision/8 (1073741824 (estimated locally),1.00 per call) 
System_Ip_ClearWriteAbortFlagPrivileged/3 (System_Ip_ClearWriteAbortFlagPrivileged) @06eb98c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: System_Ip_ClearWriteAbortFlag/7 (1073741824 (estimated locally),1.00 per call) 
System_Ip_ConfigIrqPrivileged/2 (System_Ip_ConfigIrqPrivileged) @06eb9d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: System_Ip_ConfigIrq/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
System_Ip_SetAhbSlavePriorityPrivileged/1 (System_Ip_SetAhbSlavePriorityPrivileged) @06eb9a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: System_Ip_SetAhbSlavePriority/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: System_Ip_SetAhbSlavePriorityPrivileged.part.0/9 (536870912 (estimated locally),0.50 per call) 

;; Function System_Ip_SetAhbSlavePriorityPrivileged (System_Ip_SetAhbSlavePriorityPrivileged, funcdef_no=1, decl_uid=5661, cgraph_uid=2, symbol_order=1)

Modification phase of node System_Ip_SetAhbSlavePriorityPrivileged/1
System_Ip_SetAhbSlavePriorityPrivileged (boolean bPriority)
{
  long unsigned int _2;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (bPriority_5(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870912]:
  # DEBUG D#1 => bPriority_5(D)
  System_Ip_SetAhbSlavePriorityPrivileged.part.0 ();
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct MCM_Type *)3758620672B].CPCR;
  _4 = _2 & 4160749567;
  MEM[(struct MCM_Type *)3758620672B].CPCR ={v} _4;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function System_Ip_ConfigIrqPrivileged (System_Ip_ConfigIrqPrivileged, funcdef_no=2, decl_uid=5664, cgraph_uid=3, symbol_order=2)

Modification phase of node System_Ip_ConfigIrqPrivileged/2
System_Ip_ConfigIrqPrivileged (System_Ip_IrqType eIrq, boolean bEnable)
{
  uint32 u32RegValTemp;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  u32RegValTemp_6 ={v} MEM[(struct MCM_Type *)3758620672B].ISCR;
  # DEBUG u32RegValTemp => u32RegValTemp_6
  # DEBUG BEGIN_STMT
  u32RegValTemp_7 = u32RegValTemp_6 & 4294967263;
  # DEBUG u32RegValTemp => u32RegValTemp_7
  # DEBUG BEGIN_STMT
  if (bEnable_8(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 = 1 << eIrq_9(D);
  u32RegValTemp_11 = _1 | u32RegValTemp_7;
  # DEBUG u32RegValTemp => u32RegValTemp_11
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 = 1 << eIrq_9(D);
  _3 = ~_2;
  u32RegValTemp_10 = _3 & u32RegValTemp_7;
  # DEBUG u32RegValTemp => u32RegValTemp_10

  <bb 5> [local count: 1073741824]:
  # u32RegValTemp_4 = PHI <u32RegValTemp_11(3), u32RegValTemp_10(4)>
  # DEBUG u32RegValTemp => u32RegValTemp_4
  # DEBUG BEGIN_STMT
  MEM[(struct MCM_Type *)3758620672B].ISCR ={v} u32RegValTemp_4;
  return;

}



;; Function System_Ip_ClearWriteAbortFlagPrivileged (System_Ip_ClearWriteAbortFlagPrivileged, funcdef_no=11, decl_uid=5666, cgraph_uid=4, symbol_order=3)

Modification phase of node System_Ip_ClearWriteAbortFlagPrivileged/3
System_Ip_ClearWriteAbortFlagPrivileged ()
{
  <bb 2> [local count: 1073741824]:
  System_Ip_ClearWriteAbortFlag (); [tail call]
  return;

}



;; Function System_Ip_GetPlatformRevisionPrivileged (System_Ip_GetPlatformRevisionPrivileged, funcdef_no=13, decl_uid=5668, cgraph_uid=5, symbol_order=4)

Modification phase of node System_Ip_GetPlatformRevisionPrivileged/4
System_Ip_GetPlatformRevisionPrivileged ()
{
  uint32 retval.8;

  <bb 2> [local count: 1073741824]:
  retval.8_3 = System_Ip_GetPlatformRevision (); [tail call]
  return retval.8_3;

}



;; Function System_Ip_SetAhbSlavePriority (System_Ip_SetAhbSlavePriority, funcdef_no=5, decl_uid=5652, cgraph_uid=6, symbol_order=5)

Modification phase of node System_Ip_SetAhbSlavePriority/5
System_Ip_SetAhbSlavePriority (boolean bPriority)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  System_Ip_SetAhbSlavePriorityPrivileged (bPriority_2(D));
  return;

}



;; Function System_Ip_ConfigIrq (System_Ip_ConfigIrq, funcdef_no=6, decl_uid=5655, cgraph_uid=7, symbol_order=6)

Modification phase of node System_Ip_ConfigIrq/6
System_Ip_ConfigIrq (System_Ip_IrqType eIrq, boolean bEnable)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  System_Ip_ConfigIrqPrivileged (eIrq_2(D), bEnable_3(D));
  return;

}



;; Function System_Ip_ClearWriteAbortFlag (System_Ip_ClearWriteAbortFlag, funcdef_no=7, decl_uid=5657, cgraph_uid=8, symbol_order=7)

Modification phase of node System_Ip_ClearWriteAbortFlag/7
System_Ip_ClearWriteAbortFlag ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY System_Ip_ClearWriteAbortFlagPrivileged
  # DEBUG BEGIN_STMT
  MEM[(struct MCM_Type *)3758620672B].ISCR ={v} 32;
  return;

}



;; Function System_Ip_GetPlatformRevision (System_Ip_GetPlatformRevision, funcdef_no=8, decl_uid=5659, cgraph_uid=9, symbol_order=8)

Modification phase of node System_Ip_GetPlatformRevision/8
System_Ip_GetPlatformRevision ()
{
  short unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY System_Ip_GetPlatformRevisionPrivileged
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct MCM_Type *)3758620672B].PLREV;
  _3 = (long unsigned int) _2;
  return _3;

}


