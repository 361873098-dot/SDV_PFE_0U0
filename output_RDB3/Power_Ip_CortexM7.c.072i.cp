
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Power_Ip_CM7_EnableDeepSleep/4:
  Jump functions of caller  Power_Ip_CM7_DisableDeepSleep/3:
  Jump functions of caller  Power_Ip_CortexM_WarmReset/2:
  Jump functions of caller  Power_Ip_CM7_EnableSleepOnExit/1:
  Jump functions of caller  Power_Ip_CM7_DisableSleepOnExit/0:

 Propagating constants:

Not considering Power_Ip_CM7_EnableDeepSleep for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_CM7_DisableDeepSleep for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_CortexM_WarmReset for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_CM7_EnableSleepOnExit for cloning; -fipa-cp-clone disabled.
Not considering Power_Ip_CM7_DisableSleepOnExit for cloning; -fipa-cp-clone disabled.

overall_size: 32, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Power_Ip_CM7_EnableDeepSleep/4:
  Node: Power_Ip_CM7_DisableDeepSleep/3:
  Node: Power_Ip_CortexM_WarmReset/2:
  Node: Power_Ip_CM7_EnableSleepOnExit/1:
  Node: Power_Ip_CM7_DisableSleepOnExit/0:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Power_Ip_CM7_EnableDeepSleep/4 (Power_Ip_CM7_EnableDeepSleep) @074f6ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Power_Ip_CM7_DisableDeepSleep/3 (Power_Ip_CM7_DisableDeepSleep) @074f6c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Power_Ip_CortexM_WarmReset/2 (Power_Ip_CortexM_WarmReset) @074f69a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Power_Ip_CM7_EnableSleepOnExit/1 (Power_Ip_CM7_EnableSleepOnExit) @074f6620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Power_Ip_CM7_DisableSleepOnExit/0 (Power_Ip_CM7_DisableSleepOnExit) @074f6380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Power_Ip_CM7_DisableSleepOnExit (Power_Ip_CM7_DisableSleepOnExit, funcdef_no=0, decl_uid=6513, cgraph_uid=1, symbol_order=0)

Modification phase of node Power_Ip_CM7_DisableSleepOnExit/0
Power_Ip_CM7_DisableSleepOnExit ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].SCR;
  _2 = _1 & 4294967293;
  MEM[(struct S32_SCB_Type *)3758153728B].SCR ={v} _2;
  return;

}



;; Function Power_Ip_CM7_EnableSleepOnExit (Power_Ip_CM7_EnableSleepOnExit, funcdef_no=1, decl_uid=6511, cgraph_uid=2, symbol_order=1)

Modification phase of node Power_Ip_CM7_EnableSleepOnExit/1
Power_Ip_CM7_EnableSleepOnExit ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].SCR;
  _2 = _1 | 2;
  MEM[(struct S32_SCB_Type *)3758153728B].SCR ={v} _2;
  return;

}



;; Function Power_Ip_CortexM_WarmReset (Power_Ip_CortexM_WarmReset, funcdef_no=2, decl_uid=6515, cgraph_uid=3, symbol_order=2)

Modification phase of node Power_Ip_CortexM_WarmReset/2
Power_Ip_CortexM_WarmReset ()
{
  uint32 RegValue;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  RegValue_2 ={v} MEM[(volatile uint32 *)3758157068B];
  # DEBUG RegValue => RegValue_2
  # DEBUG BEGIN_STMT
  RegValue_3 = RegValue_2 & 65531;
  # DEBUG RegValue => RegValue_3
  # DEBUG BEGIN_STMT
  RegValue_4 = RegValue_3 | 100270084;
  # DEBUG RegValue => RegValue_4
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32 *)3758157068B] ={v} RegValue_4;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("  wfi");
  # DEBUG BEGIN_STMT
  return;

}



;; Function Power_Ip_CM7_DisableDeepSleep (Power_Ip_CM7_DisableDeepSleep, funcdef_no=3, decl_uid=6517, cgraph_uid=4, symbol_order=3)

Modification phase of node Power_Ip_CM7_DisableDeepSleep/3
Power_Ip_CM7_DisableDeepSleep ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].SCR;
  _2 = _1 & 4294967291;
  MEM[(struct S32_SCB_Type *)3758153728B].SCR ={v} _2;
  return;

}



;; Function Power_Ip_CM7_EnableDeepSleep (Power_Ip_CM7_EnableDeepSleep, funcdef_no=4, decl_uid=6519, cgraph_uid=5, symbol_order=4)

Modification phase of node Power_Ip_CM7_EnableDeepSleep/4
Power_Ip_CM7_EnableDeepSleep ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].SCR;
  _2 = _1 | 4;
  MEM[(struct S32_SCB_Type *)3758153728B].SCR ={v} _2;
  return;

}


