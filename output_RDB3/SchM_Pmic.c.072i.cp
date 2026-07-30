
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Sys_GetCoreID/17:
  Jump functions of caller  SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16:
  Jump functions of caller  SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15:
  Jump functions of caller  SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14:
  Jump functions of caller  SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13:
  Jump functions of caller  SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12:
  Jump functions of caller  SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11:
  Jump functions of caller  SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10:
  Jump functions of caller  SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9:
  Jump functions of caller  Pmic_schm_read_msr/8:

 Propagating constants:

Not considering SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00 for cloning; -fipa-cp-clone disabled.
Not considering Pmic_schm_read_msr for cloning; -fipa-cp-clone disabled.

overall_size: 136, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16:
  Node: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15:
  Node: SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14:
  Node: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13:
  Node: SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12:
  Node: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11:
  Node: SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10:
  Node: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9:
  Node: Pmic_schm_read_msr/8:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Sys_GetCoreID/17 (Sys_GetCoreID) @06e54460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16 (SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03) @06e50d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_PMIC_EXCLUSIVE_AREA_03/7 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_03/7 (write)msr_PMIC_EXCLUSIVE_AREA_03/6 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_03/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/17 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15 (SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03) @06e50700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_PMIC_EXCLUSIVE_AREA_03/7 (read)msr_PMIC_EXCLUSIVE_AREA_03/6 (write)reentry_guard_PMIC_EXCLUSIVE_AREA_03/7 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_03/7 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/17 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14 (SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02) @06e50ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_PMIC_EXCLUSIVE_AREA_02/5 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_02/5 (write)msr_PMIC_EXCLUSIVE_AREA_02/4 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_02/5 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/17 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13 (SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02) @06e50c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_PMIC_EXCLUSIVE_AREA_02/5 (read)msr_PMIC_EXCLUSIVE_AREA_02/4 (write)reentry_guard_PMIC_EXCLUSIVE_AREA_02/5 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_02/5 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/17 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12 (SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01) @06e508c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_PMIC_EXCLUSIVE_AREA_01/3 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_01/3 (write)msr_PMIC_EXCLUSIVE_AREA_01/2 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_01/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/17 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11 (SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01) @06e50620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_PMIC_EXCLUSIVE_AREA_01/3 (read)msr_PMIC_EXCLUSIVE_AREA_01/2 (write)reentry_guard_PMIC_EXCLUSIVE_AREA_01/3 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_01/3 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/17 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10 (SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00) @06e502a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_PMIC_EXCLUSIVE_AREA_00/1 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_00/1 (write)msr_PMIC_EXCLUSIVE_AREA_00/0 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_00/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/17 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9 (SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00) @06e50000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_PMIC_EXCLUSIVE_AREA_00/1 (read)msr_PMIC_EXCLUSIVE_AREA_00/0 (write)reentry_guard_PMIC_EXCLUSIVE_AREA_00/1 (read)reentry_guard_PMIC_EXCLUSIVE_AREA_00/1 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/17 (1073741824 (estimated locally),1.00 per call) 
Pmic_schm_read_msr/8 (Pmic_schm_read_msr) @06e48e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
reentry_guard_PMIC_EXCLUSIVE_AREA_03/7 (reentry_guard_PMIC_EXCLUSIVE_AREA_03) @06e4c120
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15 (read)SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15 (read)SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16 (read)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16 (read)
  Availability: available
  Varpool flags:
msr_PMIC_EXCLUSIVE_AREA_03/6 (msr_PMIC_EXCLUSIVE_AREA_03) @06e4c090
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16 (read)
  Availability: available
  Varpool flags:
reentry_guard_PMIC_EXCLUSIVE_AREA_02/5 (reentry_guard_PMIC_EXCLUSIVE_AREA_02) @06e4c000
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13 (read)SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13 (read)SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14 (read)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14 (read)
  Availability: available
  Varpool flags:
msr_PMIC_EXCLUSIVE_AREA_02/4 (msr_PMIC_EXCLUSIVE_AREA_02) @06e46f30
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14 (read)
  Availability: available
  Varpool flags:
reentry_guard_PMIC_EXCLUSIVE_AREA_01/3 (reentry_guard_PMIC_EXCLUSIVE_AREA_01) @06e46ea0
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11 (read)SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11 (read)SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12 (read)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12 (read)
  Availability: available
  Varpool flags:
msr_PMIC_EXCLUSIVE_AREA_01/2 (msr_PMIC_EXCLUSIVE_AREA_01) @06e46e10
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12 (read)
  Availability: available
  Varpool flags:
reentry_guard_PMIC_EXCLUSIVE_AREA_00/1 (reentry_guard_PMIC_EXCLUSIVE_AREA_00) @06e46d80
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9 (read)SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9 (read)SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10 (read)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10 (read)
  Availability: available
  Varpool flags:
msr_PMIC_EXCLUSIVE_AREA_00/0 (msr_PMIC_EXCLUSIVE_AREA_00) @06e46cf0
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9 (write)SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10 (read)
  Availability: available
  Varpool flags:

;; Function Pmic_schm_read_msr (Pmic_schm_read_msr, funcdef_no=0, decl_uid=5669, cgraph_uid=1, symbol_order=8)

Modification phase of node Pmic_schm_read_msr/8
Pmic_schm_read_msr ()
{
  register uint32 reg_tmp;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" mrs %0, primask " : "=r" reg_tmp_1);
  # DEBUG reg_tmp => reg_tmp_1
  # DEBUG BEGIN_STMT
  return reg_tmp_1;

}



;; Function SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00 (SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00, funcdef_no=1, decl_uid=5645, cgraph_uid=2, symbol_order=9)

Modification phase of node SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00/9
SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00 ()
{
  register uint32 reg_tmp;
  uint32 u32CoreId;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  u32CoreId_10 = (uint32) _1;
  # DEBUG u32CoreId => u32CoreId_10
  # DEBUG BEGIN_STMT
  _2 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_00[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Pmic_schm_read_msr
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" mrs %0, primask " : "=r" reg_tmp_14);
  # DEBUG reg_tmp => reg_tmp_14
  # DEBUG BEGIN_STMT
  # DEBUG reg_tmp => NULL
  # DEBUG msr => reg_tmp_14
  # DEBUG BEGIN_STMT
  _3 = reg_tmp_14 & 1;
  if (_3 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsid i");

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  msr_PMIC_EXCLUSIVE_AREA_00[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_00[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_PMIC_EXCLUSIVE_AREA_00[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00 (SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00, funcdef_no=2, decl_uid=5647, cgraph_uid=3, symbol_order=10)

Modification phase of node SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00/10
SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00 ()
{
  uint32 u32CoreId;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  u32CoreId_10 = (uint32) _1;
  # DEBUG u32CoreId => u32CoreId_10
  # DEBUG BEGIN_STMT
  _2 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_00[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_PMIC_EXCLUSIVE_AREA_00[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_PMIC_EXCLUSIVE_AREA_00[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_00[u32CoreId_10];
  if (_6 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsie i");

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01 (SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01, funcdef_no=3, decl_uid=5649, cgraph_uid=4, symbol_order=11)

Modification phase of node SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01/11
SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01 ()
{
  register uint32 reg_tmp;
  uint32 u32CoreId;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  u32CoreId_10 = (uint32) _1;
  # DEBUG u32CoreId => u32CoreId_10
  # DEBUG BEGIN_STMT
  _2 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_01[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Pmic_schm_read_msr
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" mrs %0, primask " : "=r" reg_tmp_14);
  # DEBUG reg_tmp => reg_tmp_14
  # DEBUG BEGIN_STMT
  # DEBUG reg_tmp => NULL
  # DEBUG msr => reg_tmp_14
  # DEBUG BEGIN_STMT
  _3 = reg_tmp_14 & 1;
  if (_3 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsid i");

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  msr_PMIC_EXCLUSIVE_AREA_01[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_01[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_PMIC_EXCLUSIVE_AREA_01[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01 (SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01, funcdef_no=4, decl_uid=5651, cgraph_uid=5, symbol_order=12)

Modification phase of node SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01/12
SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01 ()
{
  uint32 u32CoreId;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  u32CoreId_10 = (uint32) _1;
  # DEBUG u32CoreId => u32CoreId_10
  # DEBUG BEGIN_STMT
  _2 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_01[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_PMIC_EXCLUSIVE_AREA_01[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_PMIC_EXCLUSIVE_AREA_01[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_01[u32CoreId_10];
  if (_6 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsie i");

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02 (SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02, funcdef_no=5, decl_uid=5653, cgraph_uid=6, symbol_order=13)

Modification phase of node SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02/13
SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02 ()
{
  register uint32 reg_tmp;
  uint32 u32CoreId;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  u32CoreId_10 = (uint32) _1;
  # DEBUG u32CoreId => u32CoreId_10
  # DEBUG BEGIN_STMT
  _2 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_02[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Pmic_schm_read_msr
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" mrs %0, primask " : "=r" reg_tmp_14);
  # DEBUG reg_tmp => reg_tmp_14
  # DEBUG BEGIN_STMT
  # DEBUG reg_tmp => NULL
  # DEBUG msr => reg_tmp_14
  # DEBUG BEGIN_STMT
  _3 = reg_tmp_14 & 1;
  if (_3 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsid i");

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  msr_PMIC_EXCLUSIVE_AREA_02[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_02[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_PMIC_EXCLUSIVE_AREA_02[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02 (SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02, funcdef_no=6, decl_uid=5655, cgraph_uid=7, symbol_order=14)

Modification phase of node SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02/14
SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02 ()
{
  uint32 u32CoreId;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  u32CoreId_10 = (uint32) _1;
  # DEBUG u32CoreId => u32CoreId_10
  # DEBUG BEGIN_STMT
  _2 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_02[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_PMIC_EXCLUSIVE_AREA_02[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_PMIC_EXCLUSIVE_AREA_02[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_02[u32CoreId_10];
  if (_6 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsie i");

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03 (SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03, funcdef_no=7, decl_uid=5657, cgraph_uid=8, symbol_order=15)

Modification phase of node SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03/15
SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03 ()
{
  register uint32 reg_tmp;
  uint32 u32CoreId;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  u32CoreId_10 = (uint32) _1;
  # DEBUG u32CoreId => u32CoreId_10
  # DEBUG BEGIN_STMT
  _2 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_03[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Pmic_schm_read_msr
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" mrs %0, primask " : "=r" reg_tmp_14);
  # DEBUG reg_tmp => reg_tmp_14
  # DEBUG BEGIN_STMT
  # DEBUG reg_tmp => NULL
  # DEBUG msr => reg_tmp_14
  # DEBUG BEGIN_STMT
  _3 = reg_tmp_14 & 1;
  if (_3 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsid i");

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  msr_PMIC_EXCLUSIVE_AREA_03[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_03[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_PMIC_EXCLUSIVE_AREA_03[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03 (SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03, funcdef_no=8, decl_uid=5659, cgraph_uid=9, symbol_order=16)

Modification phase of node SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03/16
SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03 ()
{
  uint32 u32CoreId;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Sys_GetCoreID ();
  u32CoreId_10 = (uint32) _1;
  # DEBUG u32CoreId => u32CoreId_10
  # DEBUG BEGIN_STMT
  _2 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_03[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_PMIC_EXCLUSIVE_AREA_03[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_PMIC_EXCLUSIVE_AREA_03[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_PMIC_EXCLUSIVE_AREA_03[u32CoreId_10];
  if (_6 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" cpsie i");

  <bb 5> [local count: 1073741824]:
  return;

}


