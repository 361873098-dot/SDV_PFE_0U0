
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Cache_Ip_CleanByAddr/15:
  Jump functions of caller  Cache_Ip_InvalidateByAddr/14:
  Jump functions of caller  Cache_Ip_Clean/13:
  Jump functions of caller  Cache_Ip_Invalidate/12:
  Jump functions of caller  Cache_Ip_Disable/11:
  Jump functions of caller  Cache_Ip_Enable/10:
  Jump functions of caller  Mcl_CacheCleanByAddr/8:
  Jump functions of caller  Mcl_CacheInvalidateByAddr/7:
  Jump functions of caller  Mcl_CacheClean/6:
  Jump functions of caller  Mcl_CacheInvalidate/5:
  Jump functions of caller  Mcl_CacheDisable/4:
  Jump functions of caller  Mcl_CacheEnable/3:
  Jump functions of caller  Mcl_DeInit/2:
  Jump functions of caller  Mcl_Init/1:

 Propagating constants:

Not considering Mcl_CacheCleanByAddr for cloning; -fipa-cp-clone disabled.
Not considering Mcl_CacheInvalidateByAddr for cloning; -fipa-cp-clone disabled.
Not considering Mcl_CacheClean for cloning; -fipa-cp-clone disabled.
Not considering Mcl_CacheInvalidate for cloning; -fipa-cp-clone disabled.
Not considering Mcl_CacheDisable for cloning; -fipa-cp-clone disabled.
Not considering Mcl_CacheEnable for cloning; -fipa-cp-clone disabled.
Not considering Mcl_DeInit for cloning; -fipa-cp-clone disabled.
Not considering Mcl_Init for cloning; -fipa-cp-clone disabled.

overall_size: 62, max_new_size: 11001
 - context independent values, size: 7, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Mcl_CacheCleanByAddr/8:
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
  Node: Mcl_CacheInvalidateByAddr/7:
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
  Node: Mcl_CacheClean/6:
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
  Node: Mcl_CacheInvalidate/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Mcl_CacheDisable/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Mcl_CacheEnable/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Mcl_DeInit/2:
  Node: Mcl_Init/1:
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

Cache_Ip_CleanByAddr/15 (Cache_Ip_CleanByAddr) @06fc2ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Mcl_CacheCleanByAddr/8 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Cache_Ip_InvalidateByAddr/14 (Cache_Ip_InvalidateByAddr) @06fc2d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Mcl_CacheInvalidateByAddr/7 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Cache_Ip_Clean/13 (Cache_Ip_Clean) @06fc2b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Mcl_CacheClean/6 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Cache_Ip_Invalidate/12 (Cache_Ip_Invalidate) @06fc29a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Mcl_CacheInvalidate/5 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Cache_Ip_Disable/11 (Cache_Ip_Disable) @06fc27e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Mcl_CacheDisable/4 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Cache_Ip_Enable/10 (Cache_Ip_Enable) @06fc2620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Mcl_CacheEnable/3 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Mcl_Config/9 (Mcl_Config) @06fbeab0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Mcl_Init/1 (addr)
  Availability: not_available
  Varpool flags: read-only
Mcl_CacheCleanByAddr/8 (Mcl_CacheCleanByAddr) @06fc2000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Cache_Ip_CleanByAddr/15 (354334802 (estimated locally),0.33 per call) 
Mcl_CacheInvalidateByAddr/7 (Mcl_CacheInvalidateByAddr) @06fb8a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Cache_Ip_InvalidateByAddr/14 (354334802 (estimated locally),0.33 per call) 
Mcl_CacheClean/6 (Mcl_CacheClean) @06fb8540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Cache_Ip_Clean/13 (354334802 (estimated locally),0.33 per call) 
Mcl_CacheInvalidate/5 (Mcl_CacheInvalidate) @06fb8ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Cache_Ip_Invalidate/12 (354334802 (estimated locally),0.33 per call) 
Mcl_CacheDisable/4 (Mcl_CacheDisable) @06fb8c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Cache_Ip_Disable/11 (354334802 (estimated locally),0.33 per call) 
Mcl_CacheEnable/3 (Mcl_CacheEnable) @06fb89a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Cache_Ip_Enable/10 (354334802 (estimated locally),0.33 per call) 
Mcl_DeInit/2 (Mcl_DeInit) @06fb8700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Mcl_pxConfig/0 (read)Mcl_pxConfig/0 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Mcl_Init/1 (Mcl_Init) @06fb8460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Mcl_pxConfig/0 (read)Mcl_pxConfig/0 (write)Mcl_Config/9 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Mcl_pxConfig/0 (Mcl_pxConfig) @06fba5a0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Mcl_Init/1 (write)Mcl_Init/1 (read)Mcl_DeInit/2 (read)Mcl_DeInit/2 (write)
  Availability: available
  Varpool flags:

;; Function Mcl_Init (Mcl_Init, funcdef_no=0, decl_uid=5878, cgraph_uid=1, symbol_order=1)

Modification phase of node Mcl_Init/1
Mcl_Init (const struct Mcl_ConfigType * const ConfigPtr)
{
  const struct Mcl_ConfigType * Mcl_pxConfig.0_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Mcl_pxConfig.0_1 = Mcl_pxConfig;
  if (Mcl_pxConfig.0_1 == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  Mcl_pxConfig = &Mcl_Config;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Mcl_DeInit (Mcl_DeInit, funcdef_no=1, decl_uid=5880, cgraph_uid=2, symbol_order=2)

Modification phase of node Mcl_DeInit/2
Mcl_DeInit ()
{
  const struct Mcl_ConfigType * Mcl_pxConfig.2_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Mcl_pxConfig.2_1 = Mcl_pxConfig;
  if (Mcl_pxConfig.2_1 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  Mcl_pxConfig = 0B;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Mcl_CacheEnable (Mcl_CacheEnable, funcdef_no=2, decl_uid=5882, cgraph_uid=3, symbol_order=3)

Modification phase of node Mcl_CacheEnable/3
Mcl_CacheEnable (Mcl_CacheType CacheType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  if (CacheType_2(D) > 2)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Cache_Ip_Enable (CacheType_2(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG CacheTypeValidation => NULL
  # DEBUG BEGIN_STMT
  return;

}



;; Function Mcl_CacheDisable (Mcl_CacheDisable, funcdef_no=3, decl_uid=5884, cgraph_uid=4, symbol_order=4)

Modification phase of node Mcl_CacheDisable/4
Mcl_CacheDisable (Mcl_CacheType CacheType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  if (CacheType_2(D) > 2)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Cache_Ip_Disable (CacheType_2(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG CacheTypeValidation => NULL
  # DEBUG BEGIN_STMT
  return;

}



;; Function Mcl_CacheInvalidate (Mcl_CacheInvalidate, funcdef_no=4, decl_uid=5886, cgraph_uid=5, symbol_order=5)

Modification phase of node Mcl_CacheInvalidate/5
Mcl_CacheInvalidate (Mcl_CacheType CacheType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  if (CacheType_2(D) > 2)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Cache_Ip_Invalidate (CacheType_2(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG CacheTypeValidation => NULL
  # DEBUG BEGIN_STMT
  return;

}



;; Function Mcl_CacheClean (Mcl_CacheClean, funcdef_no=5, decl_uid=5889, cgraph_uid=6, symbol_order=6)

Modification phase of node Mcl_CacheClean/6
Mcl_CacheClean (Mcl_CacheType CacheType, boolean EnInvalidate)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  if (CacheType_2(D) > 2)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Cache_Ip_Clean (CacheType_2(D), EnInvalidate_4(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG CacheTypeValidation => NULL
  # DEBUG BEGIN_STMT
  return;

}



;; Function Mcl_CacheInvalidateByAddr (Mcl_CacheInvalidateByAddr, funcdef_no=6, decl_uid=5893, cgraph_uid=7, symbol_order=7)

Modification phase of node Mcl_CacheInvalidateByAddr/7
Mcl_CacheInvalidateByAddr (Mcl_CacheType CacheType, uint32 Addr, uint32 Length)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  if (CacheType_2(D) > 2)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Cache_Ip_InvalidateByAddr (CacheType_2(D), Addr_4(D), Length_5(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG CacheTypeValidation => NULL
  # DEBUG BEGIN_STMT
  return;

}



;; Function Mcl_CacheCleanByAddr (Mcl_CacheCleanByAddr, funcdef_no=7, decl_uid=5898, cgraph_uid=8, symbol_order=8)

Modification phase of node Mcl_CacheCleanByAddr/8
Mcl_CacheCleanByAddr (Mcl_CacheType CacheType, boolean EnInvalidate, uint32 Addr, uint32 Length)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  if (CacheType_2(D) > 2)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG CacheTypeValidation => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Cache_Ip_CleanByAddr (CacheType_2(D), EnInvalidate_4(D), Addr_5(D), Length_6(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG CacheTypeValidation => NULL
  # DEBUG BEGIN_STMT
  return;

}


