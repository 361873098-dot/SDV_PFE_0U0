
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18/29:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheCleanByAddr/28:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/27:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18/26:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17/25:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/24:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/23:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17/22:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16/21:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheClean/20:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheClean/19:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16/18:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15/17:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheInvalidate/16:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheInvalidate/15:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15/14:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14/13:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheDisable/12:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheDisable/11:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14/10:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13/9:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheEnable/8:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheEnable/7:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13/6:
  Jump functions of caller  Cache_Ip_CleanByAddr/5:
  Jump functions of caller  Cache_Ip_InvalidateByAddr/4:
  Jump functions of caller  Cache_Ip_Clean/3:
  Jump functions of caller  Cache_Ip_Invalidate/2:
  Jump functions of caller  Cache_Ip_Disable/1:
  Jump functions of caller  Cache_Ip_Enable/0:

 Propagating constants:

Not considering Cache_Ip_CleanByAddr for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_InvalidateByAddr for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_Clean for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_Invalidate for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_Disable for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_Enable for cloning; -fipa-cp-clone disabled.

overall_size: 126, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Cache_Ip_CleanByAddr/5:
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
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Cache_Ip_InvalidateByAddr/4:
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
  Node: Cache_Ip_Clean/3:
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
  Node: Cache_Ip_Invalidate/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Cache_Ip_Disable/1:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Cache_Ip_Enable/0:
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

SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18/29 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18) @0713c7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_CleanByAddr/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheCleanByAddr/28 (hwAcc_ArmCoreMx_DataCacheCleanByAddr) @0713c700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_CleanByAddr/5 (268435456 (estimated locally),0.25 per call) Cache_Ip_CleanByAddr/5 (268435456 (estimated locally),0.25 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/27 (hwAcc_ArmCoreMx_InstructionCacheCleanByAddr) @0713c620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_CleanByAddr/5 (268435456 (estimated locally),0.25 per call) Cache_Ip_CleanByAddr/5 (268435456 (estimated locally),0.25 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18/26 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18) @0713c540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_CleanByAddr/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17/25 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17) @0713c380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_InvalidateByAddr/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/24 (hwAcc_ArmCoreMx_DataCacheInvalidateByAddr) @0713c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_InvalidateByAddr/4 (268435456 (estimated locally),0.25 per call) Cache_Ip_InvalidateByAddr/4 (268435456 (estimated locally),0.25 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/23 (hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr) @0713c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_InvalidateByAddr/4 (268435456 (estimated locally),0.25 per call) Cache_Ip_InvalidateByAddr/4 (268435456 (estimated locally),0.25 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17/22 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17) @0713c0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_InvalidateByAddr/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16/21 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16) @07046ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Clean/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheClean/20 (hwAcc_ArmCoreMx_DataCacheClean) @07046e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Clean/3 (268435456 (estimated locally),0.25 per call) Cache_Ip_Clean/3 (268435456 (estimated locally),0.25 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheClean/19 (hwAcc_ArmCoreMx_InstructionCacheClean) @07046d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Clean/3 (268435456 (estimated locally),0.25 per call) Cache_Ip_Clean/3 (268435456 (estimated locally),0.25 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16/18 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16) @07046c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Clean/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15/17 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15) @07046a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Invalidate/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheInvalidate/16 (hwAcc_ArmCoreMx_DataCacheInvalidate) @070469a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Invalidate/2 (268435456 (estimated locally),0.25 per call) Cache_Ip_Invalidate/2 (268435456 (estimated locally),0.25 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheInvalidate/15 (hwAcc_ArmCoreMx_InstructionCacheInvalidate) @070468c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Invalidate/2 (268435456 (estimated locally),0.25 per call) Cache_Ip_Invalidate/2 (268435456 (estimated locally),0.25 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15/14 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15) @070467e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Invalidate/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14/13 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14) @07046620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Disable/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheDisable/12 (hwAcc_ArmCoreMx_DataCacheDisable) @07046540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Disable/1 (268435456 (estimated locally),0.25 per call) Cache_Ip_Disable/1 (268435456 (estimated locally),0.25 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheDisable/11 (hwAcc_ArmCoreMx_InstructionCacheDisable) @07046460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Disable/1 (268435456 (estimated locally),0.25 per call) Cache_Ip_Disable/1 (268435456 (estimated locally),0.25 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14/10 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14) @07046380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Disable/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13/9 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13) @070461c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Enable/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheEnable/8 (hwAcc_ArmCoreMx_DataCacheEnable) @070460e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Enable/0 (268435456 (estimated locally),0.25 per call) Cache_Ip_Enable/0 (268435456 (estimated locally),0.25 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheEnable/7 (hwAcc_ArmCoreMx_InstructionCacheEnable) @07046000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Enable/0 (268435456 (estimated locally),0.25 per call) Cache_Ip_Enable/0 (268435456 (estimated locally),0.25 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13/6 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13) @0703ee00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Enable/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Cache_Ip_CleanByAddr/5 (Cache_Ip_CleanByAddr) @0703e0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18/29 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheCleanByAddr/28 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/27 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_DataCacheCleanByAddr/28 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/27 (268435456 (estimated locally),0.25 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18/26 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_InvalidateByAddr/4 (Cache_Ip_InvalidateByAddr) @0703ed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17/25 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/24 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/23 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/24 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/23 (268435456 (estimated locally),0.25 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17/22 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_Clean/3 (Cache_Ip_Clean) @0703ea80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16/21 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheClean/20 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheClean/19 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_DataCacheClean/20 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheClean/19 (268435456 (estimated locally),0.25 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16/18 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_Invalidate/2 (Cache_Ip_Invalidate) @0703e7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15/17 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheInvalidate/16 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheInvalidate/15 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_DataCacheInvalidate/16 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheInvalidate/15 (268435456 (estimated locally),0.25 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15/14 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_Disable/1 (Cache_Ip_Disable) @0703e540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14/13 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheDisable/12 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheDisable/11 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_DataCacheDisable/12 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheDisable/11 (268435456 (estimated locally),0.25 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14/10 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_Enable/0 (Cache_Ip_Enable) @0703e2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13/9 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheEnable/8 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheEnable/7 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_DataCacheEnable/8 (268435456 (estimated locally),0.25 per call) hwAcc_ArmCoreMx_InstructionCacheEnable/7 (268435456 (estimated locally),0.25 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13/6 (1073741824 (estimated locally),1.00 per call) 

;; Function Cache_Ip_Enable (Cache_Ip_Enable, funcdef_no=0, decl_uid=5702, cgraph_uid=1, symbol_order=0)

Modification phase of node Cache_Ip_Enable/0
Cache_Ip_Enable (const Cache_Ip_Type CacheType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13 ();
  # DEBUG BEGIN_STMT
  switch (CacheType_4(D)) <default: <L6> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheEnable ();
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheEnable ();
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheEnable ();
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheEnable ();
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L6>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_Disable (Cache_Ip_Disable, funcdef_no=1, decl_uid=5704, cgraph_uid=2, symbol_order=1)

Modification phase of node Cache_Ip_Disable/1
Cache_Ip_Disable (const Cache_Ip_Type CacheType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14 ();
  # DEBUG BEGIN_STMT
  switch (CacheType_4(D)) <default: <L6> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheDisable ();
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheDisable ();
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheDisable ();
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheDisable ();
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L6>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_Invalidate (Cache_Ip_Invalidate, funcdef_no=2, decl_uid=5706, cgraph_uid=3, symbol_order=2)

Modification phase of node Cache_Ip_Invalidate/2
Cache_Ip_Invalidate (const Cache_Ip_Type CacheType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15 ();
  # DEBUG BEGIN_STMT
  switch (CacheType_4(D)) <default: <L6> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheInvalidate ();
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheInvalidate ();
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheInvalidate ();
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheInvalidate ();
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L6>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_Clean (Cache_Ip_Clean, funcdef_no=3, decl_uid=5709, cgraph_uid=4, symbol_order=3)

Modification phase of node Cache_Ip_Clean/3
Cache_Ip_Clean (const Cache_Ip_Type CacheType, const boolean EnInvalidate)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16 ();
  # DEBUG BEGIN_STMT
  switch (CacheType_4(D)) <default: <L6> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheClean (EnInvalidate_5(D));
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheClean (EnInvalidate_5(D));
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheClean (EnInvalidate_5(D));
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheClean (EnInvalidate_5(D));
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L6>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_InvalidateByAddr (Cache_Ip_InvalidateByAddr, funcdef_no=4, decl_uid=5713, cgraph_uid=5, symbol_order=4)

Modification phase of node Cache_Ip_InvalidateByAddr/4
Cache_Ip_InvalidateByAddr (const Cache_Ip_Type CacheType, const uint32 Addr, const uint32 Length)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17 ();
  # DEBUG BEGIN_STMT
  switch (CacheType_4(D)) <default: <L6> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr (Addr_5(D), Length_6(D));
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheInvalidateByAddr (Addr_5(D), Length_6(D));
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr (Addr_5(D), Length_6(D));
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheInvalidateByAddr (Addr_5(D), Length_6(D));
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L6>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_CleanByAddr (Cache_Ip_CleanByAddr, funcdef_no=5, decl_uid=5718, cgraph_uid=6, symbol_order=5)

Modification phase of node Cache_Ip_CleanByAddr/5
Cache_Ip_CleanByAddr (const Cache_Ip_Type CacheType, const boolean EnInvalidate, const uint32 Addr, const uint32 Length)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18 ();
  # DEBUG BEGIN_STMT
  switch (CacheType_4(D)) <default: <L6> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheCleanByAddr (EnInvalidate_5(D), Addr_6(D), Length_7(D));
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheCleanByAddr (EnInvalidate_5(D), Addr_6(D), Length_7(D));
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheCleanByAddr (EnInvalidate_5(D), Addr_6(D), Length_7(D));
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheCleanByAddr (EnInvalidate_5(D), Addr_6(D), Length_7(D));
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L6>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18 ();
  # DEBUG BEGIN_STMT
  return 0;

}


