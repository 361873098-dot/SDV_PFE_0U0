
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheDisable/11:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheDisable/10:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheEnable/9:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheEnable/8:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheCleanByAddr/7:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/6:
    callsite  hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/6 -> hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/4 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/5:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/4:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheClean/3:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheClean/2:
    callsite  hwAcc_ArmCoreMx_InstructionCacheClean/2 -> hwAcc_ArmCoreMx_InstructionCacheInvalidate/0 : 
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheInvalidate/1:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheInvalidate/0:

 Propagating constants:

Not considering hwAcc_ArmCoreMx_DataCacheDisable for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_InstructionCacheDisable for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_DataCacheEnable for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_InstructionCacheEnable for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_DataCacheCleanByAddr for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_InstructionCacheCleanByAddr for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_DataCacheInvalidateByAddr for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_DataCacheClean for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_InstructionCacheClean for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_DataCacheInvalidate for cloning; -fipa-cp-clone disabled.
Not considering hwAcc_ArmCoreMx_InstructionCacheInvalidate for cloning; -fipa-cp-clone disabled.

overall_size: 176, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: hwAcc_ArmCoreMx_DataCacheDisable/11:
  Node: hwAcc_ArmCoreMx_InstructionCacheDisable/10:
  Node: hwAcc_ArmCoreMx_DataCacheEnable/9:
  Node: hwAcc_ArmCoreMx_InstructionCacheEnable/8:
  Node: hwAcc_ArmCoreMx_DataCacheCleanByAddr/7:
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
  Node: hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/6:
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
  Node: hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/5:
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
  Node: hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/4:
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
  Node: hwAcc_ArmCoreMx_DataCacheClean/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: hwAcc_ArmCoreMx_InstructionCacheClean/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: hwAcc_ArmCoreMx_DataCacheInvalidate/1:
  Node: hwAcc_ArmCoreMx_InstructionCacheInvalidate/0:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

hwAcc_ArmCoreMx_DataCacheDisable/11 (hwAcc_ArmCoreMx_DataCacheDisable) @06ee2460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheDisable/10 (hwAcc_ArmCoreMx_InstructionCacheDisable) @06ee21c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hwAcc_ArmCoreMx_DataCacheEnable/9 (hwAcc_ArmCoreMx_DataCacheEnable) @06e7cee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheEnable/8 (hwAcc_ArmCoreMx_InstructionCacheEnable) @06e7c9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hwAcc_ArmCoreMx_DataCacheCleanByAddr/7 (hwAcc_ArmCoreMx_DataCacheCleanByAddr) @06e7c380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/6 (hwAcc_ArmCoreMx_InstructionCacheCleanByAddr) @06e7ce00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/4 (354334802 (estimated locally),0.33 per call) 
hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/5 (hwAcc_ArmCoreMx_DataCacheInvalidateByAddr) @06e7cb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/4 (hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr) @06e7c8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/6 (354334802 (estimated locally),0.33 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheClean/3 (hwAcc_ArmCoreMx_DataCacheClean) @06e7c540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:14598062 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheClean/2 (hwAcc_ArmCoreMx_InstructionCacheClean) @06e7c2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: hwAcc_ArmCoreMx_InstructionCacheInvalidate/0 (354334802 (estimated locally),0.33 per call) 
hwAcc_ArmCoreMx_DataCacheInvalidate/1 (hwAcc_ArmCoreMx_DataCacheInvalidate) @06e7c000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:14598062 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheInvalidate/0 (hwAcc_ArmCoreMx_InstructionCacheInvalidate) @06e75ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: hwAcc_ArmCoreMx_InstructionCacheClean/2 (354334802 (estimated locally),0.33 per call) 
  Calls: 

;; Function hwAcc_ArmCoreMx_InstructionCacheInvalidate (hwAcc_ArmCoreMx_InstructionCacheInvalidate, funcdef_no=0, decl_uid=5720, cgraph_uid=1, symbol_order=0)

Modification phase of node hwAcc_ArmCoreMx_InstructionCacheInvalidate/0
hwAcc_ArmCoreMx_InstructionCacheInvalidate ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CSSELR;
  _2 = _1 | 1;
  MEM[(struct S32_SCB_Type *)3758153728B].CSSELR ={v} _2;
  # DEBUG BEGIN_STMT
  MEM[(struct S32_SCB_Type *)3758153728B].ICIALLU ={v} 0;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_DataCacheInvalidate (hwAcc_ArmCoreMx_DataCacheInvalidate, funcdef_no=1, decl_uid=5722, cgraph_uid=2, symbol_order=1)

Modification phase of node hwAcc_ArmCoreMx_DataCacheInvalidate/1
hwAcc_ArmCoreMx_DataCacheInvalidate ()
{
  uint32 invalidate;
  uint32 wayIdx;
  uint32 setIdx;
  uint32 cacheWaySize;
  uint32 cacheSetSize;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 14598062]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CSSELR;
  _2 = _1 & 4294967294;
  MEM[(struct S32_SCB_Type *)3758153728B].CSSELR ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCSIDR;
  _4 = _3 >> 13;
  _5 = _4 & 32767;
  cacheSetSize_17 = _5 + 1;
  # DEBUG cacheSetSize => cacheSetSize_17
  # DEBUG BEGIN_STMT
  _6 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCSIDR;
  _7 = _6 >> 3;
  _8 = _7 & 1023;
  cacheWaySize_18 = _8 + 1;
  # DEBUG cacheWaySize => cacheWaySize_18
  # DEBUG BEGIN_STMT
  # DEBUG setIdx => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  _9 = setIdx_11 << 5;
  invalidate_22 = _9 & 16352;
  # DEBUG invalidate => invalidate_22
  # DEBUG BEGIN_STMT
  _10 = wayIdx_12 << 30;
  invalidate_23 = _10 | invalidate_22;
  # DEBUG invalidate => invalidate_23
  # DEBUG BEGIN_STMT
  MEM[(struct S32_SCB_Type *)3758153728B].DCISW ={v} invalidate_23;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  # DEBUG BEGIN_STMT
  wayIdx_27 = wayIdx_12 + 1;
  # DEBUG wayIdx => wayIdx_27

  <bb 4> [local count: 1073741824]:
  # wayIdx_12 = PHI <wayIdx_27(3), 0(8)>
  # DEBUG wayIdx => wayIdx_12
  # DEBUG BEGIN_STMT
  if (wayIdx_12 < cacheWaySize_18)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  setIdx_21 = setIdx_11 + 1;
  # DEBUG setIdx => setIdx_21

  <bb 6> [local count: 132709663]:
  # setIdx_11 = PHI <0(2), setIdx_21(5)>
  # DEBUG setIdx => setIdx_11
  # DEBUG BEGIN_STMT
  if (setIdx_11 < cacheSetSize_17)
    goto <bb 8>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 8> [local count: 118111600]:
  goto <bb 4>; [100.00%]

  <bb 7> [local count: 14598063]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_InstructionCacheClean (hwAcc_ArmCoreMx_InstructionCacheClean, funcdef_no=2, decl_uid=5724, cgraph_uid=3, symbol_order=2)

Modification phase of node hwAcc_ArmCoreMx_InstructionCacheClean/2
hwAcc_ArmCoreMx_InstructionCacheClean (const boolean enInvalidate)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (enInvalidate_2(D) != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheInvalidate ();

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function hwAcc_ArmCoreMx_DataCacheClean (hwAcc_ArmCoreMx_DataCacheClean, funcdef_no=3, decl_uid=5726, cgraph_uid=4, symbol_order=3)

Modification phase of node hwAcc_ArmCoreMx_DataCacheClean/3
hwAcc_ArmCoreMx_DataCacheClean (const boolean enInvalidate)
{
  volatile uint32 * pDataCacheClean;
  uint32 clean;
  uint32 wayIdx;
  uint32 setIdx;
  uint32 cacheWaySize;
  uint32 cacheSetSize;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 14598062]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CSSELR;
  _2 = _1 & 4294967294;
  MEM[(struct S32_SCB_Type *)3758153728B].CSSELR ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCSIDR;
  _4 = _3 >> 13;
  _5 = _4 & 32767;
  cacheSetSize_18 = _5 + 1;
  # DEBUG cacheSetSize => cacheSetSize_18
  # DEBUG BEGIN_STMT
  _6 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCSIDR;
  _7 = _6 >> 3;
  _8 = _7 & 1023;
  cacheWaySize_19 = _8 + 1;
  # DEBUG cacheWaySize => cacheWaySize_19
  # DEBUG BEGIN_STMT
  if (enInvalidate_20(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 7299031]:
  # DEBUG BEGIN_STMT
  # DEBUG pDataCacheClean => 3758157676B

  <bb 4> [local count: 14598062]:
  # pDataCacheClean_13 = PHI <3758157684B(2), 3758157676B(3)>
  # DEBUG pDataCacheClean => pDataCacheClean_13
  # DEBUG BEGIN_STMT
  # DEBUG setIdx => 0
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  _9 = setIdx_11 << 5;
  clean_24 = _9 & 16352;
  # DEBUG clean => clean_24
  # DEBUG BEGIN_STMT
  _10 = wayIdx_12 << 30;
  clean_25 = _10 | clean_24;
  # DEBUG clean => clean_25
  # DEBUG BEGIN_STMT
  *pDataCacheClean_13 ={v} clean_25;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  # DEBUG BEGIN_STMT
  wayIdx_29 = wayIdx_12 + 1;
  # DEBUG wayIdx => wayIdx_29

  <bb 6> [local count: 1073741824]:
  # wayIdx_12 = PHI <wayIdx_29(5), 0(10)>
  # DEBUG wayIdx => wayIdx_12
  # DEBUG BEGIN_STMT
  if (wayIdx_12 < cacheWaySize_19)
    goto <bb 5>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  setIdx_23 = setIdx_11 + 1;
  # DEBUG setIdx => setIdx_23

  <bb 8> [local count: 132709663]:
  # setIdx_11 = PHI <0(4), setIdx_23(7)>
  # DEBUG setIdx => setIdx_11
  # DEBUG BEGIN_STMT
  if (setIdx_11 < cacheSetSize_18)
    goto <bb 10>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 10> [local count: 118111600]:
  goto <bb 6>; [100.00%]

  <bb 9> [local count: 14598063]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr (hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr, funcdef_no=4, decl_uid=5729, cgraph_uid=5, symbol_order=4)

Modification phase of node hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/4
hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr (const uint32 addr, const uint32 length)
{
  uint32 endAddr;
  uint32 tmpAddr;
  uint32 cacheLineSize;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CSSELR;
  _2 = _1 | 1;
  MEM[(struct S32_SCB_Type *)3758153728B].CSSELR ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCSIDR;
  _4 = _3 & 7;
  _5 = _4 + 1;
  cacheLineSize_10 = _5 * 16;
  # DEBUG cacheLineSize => cacheLineSize_10
  # DEBUG BEGIN_STMT
  # DEBUG tmpAddr => addr_11(D)
  # DEBUG BEGIN_STMT
  endAddr_13 = addr_11(D) + length_12(D);
  # DEBUG endAddr => endAddr_13
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  MEM[(struct S32_SCB_Type *)3758153728B].ICIMVAU ={v} tmpAddr_6;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  # DEBUG BEGIN_STMT
  tmpAddr_19 = tmpAddr_6 + cacheLineSize_10;
  # DEBUG tmpAddr => tmpAddr_19

  <bb 4> [local count: 1073741824]:
  # tmpAddr_6 = PHI <addr_11(D)(2), tmpAddr_19(3)>
  # DEBUG tmpAddr => tmpAddr_6
  # DEBUG BEGIN_STMT
  if (tmpAddr_6 < endAddr_13)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_DataCacheInvalidateByAddr (hwAcc_ArmCoreMx_DataCacheInvalidateByAddr, funcdef_no=5, decl_uid=5732, cgraph_uid=6, symbol_order=5)

Modification phase of node hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/5
hwAcc_ArmCoreMx_DataCacheInvalidateByAddr (const uint32 addr, const uint32 length)
{
  uint32 endAddr;
  uint32 tmpAddr;
  uint32 cacheLineSize;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CSSELR;
  _2 = _1 & 4294967294;
  MEM[(struct S32_SCB_Type *)3758153728B].CSSELR ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCSIDR;
  _4 = _3 & 7;
  _5 = _4 + 1;
  cacheLineSize_10 = _5 * 16;
  # DEBUG cacheLineSize => cacheLineSize_10
  # DEBUG BEGIN_STMT
  # DEBUG tmpAddr => addr_11(D)
  # DEBUG BEGIN_STMT
  endAddr_13 = addr_11(D) + length_12(D);
  # DEBUG endAddr => endAddr_13
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  MEM[(struct S32_SCB_Type *)3758153728B].DCIMVAC ={v} tmpAddr_6;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  # DEBUG BEGIN_STMT
  tmpAddr_19 = tmpAddr_6 + cacheLineSize_10;
  # DEBUG tmpAddr => tmpAddr_19

  <bb 4> [local count: 1073741824]:
  # tmpAddr_6 = PHI <addr_11(D)(2), tmpAddr_19(3)>
  # DEBUG tmpAddr => tmpAddr_6
  # DEBUG BEGIN_STMT
  if (tmpAddr_6 < endAddr_13)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_InstructionCacheCleanByAddr (hwAcc_ArmCoreMx_InstructionCacheCleanByAddr, funcdef_no=6, decl_uid=5736, cgraph_uid=7, symbol_order=6)

Modification phase of node hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/6
hwAcc_ArmCoreMx_InstructionCacheCleanByAddr (const boolean enInvalidate, const uint32 addr, const uint32 length)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (enInvalidate_2(D) != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr (addr_4(D), length_5(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function hwAcc_ArmCoreMx_DataCacheCleanByAddr (hwAcc_ArmCoreMx_DataCacheCleanByAddr, funcdef_no=7, decl_uid=5740, cgraph_uid=8, symbol_order=7)

Modification phase of node hwAcc_ArmCoreMx_DataCacheCleanByAddr/7
hwAcc_ArmCoreMx_DataCacheCleanByAddr (const boolean enInvalidate, const uint32 addr, const uint32 length)
{
  volatile uint32 * pDataCacheCleanByAddr;
  uint32 endAddr;
  uint32 tmpAddr;
  uint32 cacheLineSize;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CSSELR;
  _2 = _1 & 4294967294;
  MEM[(struct S32_SCB_Type *)3758153728B].CSSELR ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCSIDR;
  _4 = _3 & 7;
  _5 = _4 + 1;
  cacheLineSize_10 = _5 * 16;
  # DEBUG cacheLineSize => cacheLineSize_10
  # DEBUG BEGIN_STMT
  # DEBUG tmpAddr => addr_11(D)
  # DEBUG BEGIN_STMT
  endAddr_13 = addr_11(D) + length_12(D);
  # DEBUG endAddr => endAddr_13
  # DEBUG BEGIN_STMT
  if (enInvalidate_14(D) != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG pDataCacheCleanByAddr => 3758157672B
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  *pDataCacheCleanByAddr_21 ={v} tmpAddr_6;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  # DEBUG BEGIN_STMT
  tmpAddr_20 = tmpAddr_6 + cacheLineSize_10;
  # DEBUG tmpAddr => tmpAddr_20
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 118111600]:
  # pDataCacheCleanByAddr_21 = PHI <3758157672B(3), 3758157680B(2)>
  # DEBUG pDataCacheCleanByAddr => NULL

  <bb 6> [local count: 1073741824]:
  # tmpAddr_6 = PHI <addr_11(D)(5), tmpAddr_20(4)>
  # DEBUG pDataCacheCleanByAddr => pDataCacheCleanByAddr_21
  # DEBUG tmpAddr => tmpAddr_6
  # DEBUG BEGIN_STMT
  if (tmpAddr_6 < endAddr_13)
    goto <bb 4>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_InstructionCacheEnable (hwAcc_ArmCoreMx_InstructionCacheEnable, funcdef_no=8, decl_uid=5742, cgraph_uid=9, symbol_order=8)

Modification phase of node hwAcc_ArmCoreMx_InstructionCacheEnable/8
hwAcc_ArmCoreMx_InstructionCacheEnable ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCR;
  _2 = _1 | 131072;
  MEM[(struct S32_SCB_Type *)3758153728B].CCR ={v} _2;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_DataCacheEnable (hwAcc_ArmCoreMx_DataCacheEnable, funcdef_no=9, decl_uid=5744, cgraph_uid=10, symbol_order=9)

Modification phase of node hwAcc_ArmCoreMx_DataCacheEnable/9
hwAcc_ArmCoreMx_DataCacheEnable ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCR;
  _2 = _1 | 65536;
  MEM[(struct S32_SCB_Type *)3758153728B].CCR ={v} _2;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_InstructionCacheDisable (hwAcc_ArmCoreMx_InstructionCacheDisable, funcdef_no=10, decl_uid=5746, cgraph_uid=11, symbol_order=10)

Modification phase of node hwAcc_ArmCoreMx_InstructionCacheDisable/10
hwAcc_ArmCoreMx_InstructionCacheDisable ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCR;
  _2 = _1 & 4294836223;
  MEM[(struct S32_SCB_Type *)3758153728B].CCR ={v} _2;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}



;; Function hwAcc_ArmCoreMx_DataCacheDisable (hwAcc_ArmCoreMx_DataCacheDisable, funcdef_no=11, decl_uid=5748, cgraph_uid=12, symbol_order=11)

Modification phase of node hwAcc_ArmCoreMx_DataCacheDisable/11
hwAcc_ArmCoreMx_DataCacheDisable ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCR;
  _2 = _1 & 4294901759;
  MEM[(struct S32_SCB_Type *)3758153728B].CCR ={v} _2;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  return;

}


