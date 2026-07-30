
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Sys_GetCoreID/21:
  Jump functions of caller  SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20:
  Jump functions of caller  SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19:
  Jump functions of caller  SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18:
  Jump functions of caller  SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17:
  Jump functions of caller  SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16:
  Jump functions of caller  SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15:
  Jump functions of caller  SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14:
  Jump functions of caller  SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13:
  Jump functions of caller  SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12:
  Jump functions of caller  SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11:
  Jump functions of caller  Ocotp_schm_read_msr/10:

 Propagating constants:

Not considering SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00 for cloning; -fipa-cp-clone disabled.
Not considering SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00 for cloning; -fipa-cp-clone disabled.
Not considering Ocotp_schm_read_msr for cloning; -fipa-cp-clone disabled.

overall_size: 169, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20:
  Node: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19:
  Node: SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18:
  Node: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17:
  Node: SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16:
  Node: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15:
  Node: SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14:
  Node: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13:
  Node: SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12:
  Node: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11:
  Node: Ocotp_schm_read_msr/10:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Sys_GetCoreID/21 (Sys_GetCoreID) @06e22ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04) @06e229a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_04/9 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_04/9 (write)msr_OCOTP_EXCLUSIVE_AREA_04/8 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_04/9 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04) @06e22700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_04/9 (read)msr_OCOTP_EXCLUSIVE_AREA_04/8 (write)reentry_guard_OCOTP_EXCLUSIVE_AREA_04/9 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_04/9 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03) @06e22380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_03/7 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_03/7 (write)msr_OCOTP_EXCLUSIVE_AREA_03/6 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_03/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03) @06e220e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_03/7 (read)msr_OCOTP_EXCLUSIVE_AREA_03/6 (write)reentry_guard_OCOTP_EXCLUSIVE_AREA_03/7 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_03/7 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02) @06e1ec40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_02/5 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_02/5 (write)msr_OCOTP_EXCLUSIVE_AREA_02/4 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_02/5 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02) @06e1e620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_02/5 (read)msr_OCOTP_EXCLUSIVE_AREA_02/4 (write)reentry_guard_OCOTP_EXCLUSIVE_AREA_02/5 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_02/5 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01) @06e1ee00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_01/3 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_01/3 (write)msr_OCOTP_EXCLUSIVE_AREA_01/2 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_01/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01) @06e1eb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_01/3 (read)msr_OCOTP_EXCLUSIVE_AREA_01/2 (write)reentry_guard_OCOTP_EXCLUSIVE_AREA_01/3 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_01/3 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00) @06e1e7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_00/1 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_00/1 (write)msr_OCOTP_EXCLUSIVE_AREA_00/0 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_00/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00) @06e1e540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: reentry_guard_OCOTP_EXCLUSIVE_AREA_00/1 (read)msr_OCOTP_EXCLUSIVE_AREA_00/0 (write)reentry_guard_OCOTP_EXCLUSIVE_AREA_00/1 (read)reentry_guard_OCOTP_EXCLUSIVE_AREA_00/1 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Sys_GetCoreID/21 (1073741824 (estimated locally),1.00 per call) 
Ocotp_schm_read_msr/10 (Ocotp_schm_read_msr) @06e1e1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
reentry_guard_OCOTP_EXCLUSIVE_AREA_04/9 (reentry_guard_OCOTP_EXCLUSIVE_AREA_04) @06e1a2d0
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20 (read)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20 (read)
  Availability: available
  Varpool flags:
msr_OCOTP_EXCLUSIVE_AREA_04/8 (msr_OCOTP_EXCLUSIVE_AREA_04) @06e1a240
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20 (read)
  Availability: available
  Varpool flags:
reentry_guard_OCOTP_EXCLUSIVE_AREA_03/7 (reentry_guard_OCOTP_EXCLUSIVE_AREA_03) @06e1a1b0
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18 (read)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18 (read)
  Availability: available
  Varpool flags:
msr_OCOTP_EXCLUSIVE_AREA_03/6 (msr_OCOTP_EXCLUSIVE_AREA_03) @06e1a120
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18 (read)
  Availability: available
  Varpool flags:
reentry_guard_OCOTP_EXCLUSIVE_AREA_02/5 (reentry_guard_OCOTP_EXCLUSIVE_AREA_02) @06e1a090
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16 (read)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16 (read)
  Availability: available
  Varpool flags:
msr_OCOTP_EXCLUSIVE_AREA_02/4 (msr_OCOTP_EXCLUSIVE_AREA_02) @06e1a000
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16 (read)
  Availability: available
  Varpool flags:
reentry_guard_OCOTP_EXCLUSIVE_AREA_01/3 (reentry_guard_OCOTP_EXCLUSIVE_AREA_01) @06e15f30
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14 (read)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14 (read)
  Availability: available
  Varpool flags:
msr_OCOTP_EXCLUSIVE_AREA_01/2 (msr_OCOTP_EXCLUSIVE_AREA_01) @06e15ea0
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14 (read)
  Availability: available
  Varpool flags:
reentry_guard_OCOTP_EXCLUSIVE_AREA_00/1 (reentry_guard_OCOTP_EXCLUSIVE_AREA_00) @06e15e10
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11 (read)SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12 (read)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12 (read)
  Availability: available
  Varpool flags:
msr_OCOTP_EXCLUSIVE_AREA_00/0 (msr_OCOTP_EXCLUSIVE_AREA_00) @06e15d80
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11 (write)SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12 (read)
  Availability: available
  Varpool flags:

;; Function Ocotp_schm_read_msr (Ocotp_schm_read_msr, funcdef_no=0, decl_uid=5675, cgraph_uid=1, symbol_order=10)

Modification phase of node Ocotp_schm_read_msr/10
Ocotp_schm_read_msr ()
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



;; Function SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00, funcdef_no=1, decl_uid=5645, cgraph_uid=2, symbol_order=11)

Modification phase of node SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00/11
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_00[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Ocotp_schm_read_msr
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
  msr_OCOTP_EXCLUSIVE_AREA_00[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_00[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_00[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00, funcdef_no=2, decl_uid=5647, cgraph_uid=3, symbol_order=12)

Modification phase of node SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00/12
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_00[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_00[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_OCOTP_EXCLUSIVE_AREA_00[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_00[u32CoreId_10];
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



;; Function SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01, funcdef_no=3, decl_uid=5649, cgraph_uid=4, symbol_order=13)

Modification phase of node SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01/13
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_01[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Ocotp_schm_read_msr
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
  msr_OCOTP_EXCLUSIVE_AREA_01[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_01[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_01[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01, funcdef_no=4, decl_uid=5651, cgraph_uid=5, symbol_order=14)

Modification phase of node SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01/14
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_01[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_01[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_OCOTP_EXCLUSIVE_AREA_01[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_01[u32CoreId_10];
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



;; Function SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02, funcdef_no=5, decl_uid=5653, cgraph_uid=6, symbol_order=15)

Modification phase of node SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02/15
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_02[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Ocotp_schm_read_msr
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
  msr_OCOTP_EXCLUSIVE_AREA_02[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_02[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_02[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02, funcdef_no=6, decl_uid=5655, cgraph_uid=7, symbol_order=16)

Modification phase of node SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02/16
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_02[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_02[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_OCOTP_EXCLUSIVE_AREA_02[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_02[u32CoreId_10];
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



;; Function SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03, funcdef_no=7, decl_uid=5657, cgraph_uid=8, symbol_order=17)

Modification phase of node SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03/17
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_03 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_03[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Ocotp_schm_read_msr
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
  msr_OCOTP_EXCLUSIVE_AREA_03[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_03[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_03[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03, funcdef_no=8, decl_uid=5659, cgraph_uid=9, symbol_order=18)

Modification phase of node SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03/18
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_03 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_03[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_03[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_OCOTP_EXCLUSIVE_AREA_03[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_03[u32CoreId_10];
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



;; Function SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04 (SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04, funcdef_no=9, decl_uid=5661, cgraph_uid=10, symbol_order=19)

Modification phase of node SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04/19
SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_04 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_04[u32CoreId_10];
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Ocotp_schm_read_msr
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
  msr_OCOTP_EXCLUSIVE_AREA_04[u32CoreId_10] ={v} reg_tmp_14;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_04[u32CoreId_10];
  _5 = _4 + 1;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_04[u32CoreId_10] ={v} _5;
  return;

}



;; Function SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04 (SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04, funcdef_no=10, decl_uid=5663, cgraph_uid=11, symbol_order=20)

Modification phase of node SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04/20
SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_04 ()
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
  _2 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_04[u32CoreId_10];
  _3 = _2 + 4294967295;
  reentry_guard_OCOTP_EXCLUSIVE_AREA_04[u32CoreId_10] ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} msr_OCOTP_EXCLUSIVE_AREA_04[u32CoreId_10];
  _5 = _4 & 1;
  if (_5 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  _6 ={v} reentry_guard_OCOTP_EXCLUSIVE_AREA_04[u32CoreId_10];
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


