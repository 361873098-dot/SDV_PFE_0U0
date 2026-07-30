
IPA constant propagation start:
Determining dynamic type for call: xEventGroupClearBits (pvEventGroup_2(D), ulBitsToClear_3(D));
  Starting walk at: xEventGroupClearBits (pvEventGroup_2(D), ulBitsToClear_3(D));
  instance pointer: pvEventGroup_2(D)  Outer instance pointer: pvEventGroup_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xEventGroupSetBits (pvEventGroup_2(D), ulBitsToSet_3(D));
  Starting walk at: xEventGroupSetBits (pvEventGroup_2(D), ulBitsToSet_3(D));
  instance pointer: pvEventGroup_2(D)  Outer instance pointer: pvEventGroup_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = xEventGroupSetBits.part.0 (xEventGroup_3(D), uxBitsToSet_4(D));
  Starting walk at: _6 = xEventGroupSetBits.part.0 (xEventGroup_3(D), uxBitsToSet_4(D));
  instance pointer: xEventGroup_3(D)  Outer instance pointer: xEventGroup_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = xEventGroupClearBits.part.0 (xEventGroup_3(D), uxBitsToClear_5(D));
  Starting walk at: _2 = xEventGroupClearBits.part.0 (xEventGroup_3(D), uxBitsToClear_5(D));
  instance pointer: xEventGroup_3(D)  Outer instance pointer: xEventGroup_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xEventGroupSetBits (xEventGroup_23(D), uxBitsToSet_30(D));
  Starting walk at: xEventGroupSetBits (xEventGroup_23(D), uxBitsToSet_30(D));
  instance pointer: xEventGroup_23(D)  Outer instance pointer: xEventGroup_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_2 = xTaskGetSchedulerState ();

IPA structures before propagation:

Jump functions:
  Jump functions of caller  xEventGroupSetBits.part.0/39:
  Jump functions of caller  xEventGroupClearBits.part.0/36:
  Jump functions of caller  vPortFree/29:
  Jump functions of caller  vTaskRemoveFromUnorderedEventList/28:
  Jump functions of caller  xTimerPendFunctionCallFromISR/27:
  Jump functions of caller  vPortExitCritical/26:
  Jump functions of caller  vPortEnterCritical/25:
  Jump functions of caller  uxTaskResetEventItemValue/24:
  Jump functions of caller  xTaskResumeAll/23:
  Jump functions of caller  vTaskPlaceOnUnorderedEventList/22:
  Jump functions of caller  vTaskSuspendAll/21:
  Jump functions of caller  xTaskGetSchedulerState/20:
  Jump functions of caller  vListInitialise/19:
  Jump functions of caller  pvPortMalloc/18:
  Jump functions of caller  vEventGroupSetNumber/17:
  Jump functions of caller  uxEventGroupGetNumber/16:
  Jump functions of caller  xEventGroupSetBitsFromISR/15:
  Jump functions of caller  prvTestWaitCondition/14:
  Jump functions of caller  vEventGroupClearBitsCallback/13:
    callsite  vEventGroupClearBitsCallback/13 -> xEventGroupClearBits/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  vEventGroupSetBitsCallback/12:
    callsite  vEventGroupSetBitsCallback/12 -> xEventGroupSetBits/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  vEventGroupDelete/11:
  Jump functions of caller  xEventGroupSetBits/10:
    callsite  xEventGroupSetBits/10 -> xEventGroupSetBits.part.0/39 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xEventGroupGetBitsFromISR/9:
  Jump functions of caller  xEventGroupClearBitsFromISR/8:
  Jump functions of caller  xEventGroupClearBits/7:
    callsite  xEventGroupClearBits/7 -> xEventGroupClearBits.part.0/36 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xEventGroupWaitBits/6:
    callsite  xEventGroupWaitBits/6 -> prvTestWaitCondition/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
    callsite  xEventGroupWaitBits/6 -> prvTestWaitCondition/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  xEventGroupSync/5:
    callsite  xEventGroupSync/5 -> xEventGroupSetBits/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xEventGroupCreate/4:

 Propagating constants:

Not considering vEventGroupSetNumber for cloning; -fipa-cp-clone disabled.
Not considering uxEventGroupGetNumber for cloning; -fipa-cp-clone disabled.
Not considering xEventGroupSetBitsFromISR for cloning; -fipa-cp-clone disabled.
Not considering vEventGroupClearBitsCallback for cloning; -fipa-cp-clone disabled.
Not considering vEventGroupSetBitsCallback for cloning; -fipa-cp-clone disabled.
Not considering vEventGroupDelete for cloning; -fipa-cp-clone disabled.
Not considering xEventGroupSetBits for cloning; -fipa-cp-clone disabled.
Not considering xEventGroupGetBitsFromISR for cloning; -fipa-cp-clone disabled.
Not considering xEventGroupClearBitsFromISR for cloning; -fipa-cp-clone disabled.
Not considering xEventGroupClearBits for cloning; -fipa-cp-clone disabled.
Not considering xEventGroupWaitBits for cloning; -fipa-cp-clone disabled.
Not considering xEventGroupSync for cloning; -fipa-cp-clone disabled.
Not considering xEventGroupCreate for cloning; -fipa-cp-clone disabled.

overall_size: 387, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: xEventGroupSetBits.part.0/39:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: xEventGroupClearBits.part.0/36:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: vEventGroupSetNumber/17:
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
  Node: uxEventGroupGetNumber/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xEventGroupSetBitsFromISR/15:
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
  Node: prvTestWaitCondition/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: vEventGroupClearBitsCallback/13:
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
  Node: vEventGroupSetBitsCallback/12:
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
  Node: vEventGroupDelete/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xEventGroupSetBits/10:
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
  Node: xEventGroupGetBitsFromISR/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xEventGroupClearBitsFromISR/8:
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
  Node: xEventGroupClearBits/7:
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
  Node: xEventGroupWaitBits/6:
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
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xEventGroupSync/5:
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
  Node: xEventGroupCreate/4:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

xEventGroupSetBits.part.0/39 (xEventGroupSetBits.part.0) @06e2b2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: xEventGroupSetBits/10 (52886 (estimated locally),0.23 per call) 
  Calls: vTaskSuspendAll/21 (118111600 (estimated locally),1.00 per call) vTaskRemoveFromUnorderedEventList/28 (401364694 (estimated locally),3.40 per call) xTaskResumeAll/23 (118111601 (estimated locally),1.00 per call) 
xEventGroupClearBits.part.0/36 (xEventGroupClearBits.part.0) @06e26b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: xEventGroupClearBits/7 (52886 (estimated locally),0.23 per call) 
  Calls: vPortEnterCritical/25 (1073741824 (estimated locally),1.00 per call) vPortExitCritical/26 (1073741824 (estimated locally),1.00 per call) 
vPortFree/29 (vPortFree) @06f182a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vEventGroupDelete/11 (63439 (estimated locally),0.27 per call) 
  Calls: 
vTaskRemoveFromUnorderedEventList/28 (vTaskRemoveFromUnorderedEventList) @06f180e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vEventGroupDelete/11 (1030048 (estimated locally),4.46 per call) xEventGroupSetBits.part.0/39 (401364694 (estimated locally),3.40 per call) 
  Calls: 
xTimerPendFunctionCallFromISR/27 (xTimerPendFunctionCallFromISR) @06f00a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xEventGroupSetBitsFromISR/15 (1073741824 (estimated locally),1.00 per call) xEventGroupClearBitsFromISR/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
vPortExitCritical/26 (vPortExitCritical) @06f002a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xEventGroupSync/5 (3888 (estimated locally),0.02 per call) xEventGroupClearBits.part.0/36 (1073741824 (estimated locally),1.00 per call) xEventGroupWaitBits/6 (3888 (estimated locally),0.01 per call) 
  Calls: 
vPortEnterCritical/25 (vPortEnterCritical) @06f001c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xEventGroupSync/5 (3888 (estimated locally),0.02 per call) xEventGroupClearBits.part.0/36 (1073741824 (estimated locally),1.00 per call) xEventGroupWaitBits/6 (3888 (estimated locally),0.01 per call) 
  Calls: 
uxTaskResetEventItemValue/24 (uxTaskResetEventItemValue) @06f000e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xEventGroupSync/5 (11782 (estimated locally),0.05 per call) xEventGroupWaitBits/6 (11782 (estimated locally),0.04 per call) 
  Calls: 
xTaskResumeAll/23 (xTaskResumeAll) @06f00000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vEventGroupDelete/11 (63439 (estimated locally),0.27 per call) xEventGroupSync/5 (23563 (estimated locally),0.11 per call) xEventGroupSetBits.part.0/39 (118111601 (estimated locally),1.00 per call) xEventGroupWaitBits/6 (23563 (estimated locally),0.08 per call) 
  Calls: 
vTaskPlaceOnUnorderedEventList/22 (vTaskPlaceOnUnorderedEventList) @06e9c540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xEventGroupSync/5 (5132 (estimated locally),0.02 per call) xEventGroupWaitBits/6 (5891 (estimated locally),0.02 per call) 
  Calls: 
vTaskSuspendAll/21 (vTaskSuspendAll) @06e9c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vEventGroupDelete/11 (123389 (estimated locally),0.53 per call) xEventGroupSync/5 (23563 (estimated locally),0.11 per call) xEventGroupSetBits.part.0/39 (118111600 (estimated locally),1.00 per call) xEventGroupWaitBits/6 (23563 (estimated locally),0.08 per call) 
  Calls: 
xTaskGetSchedulerState/20 (xTaskGetSchedulerState) @06e9c000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xEventGroupSync/5 (35433 (estimated locally),0.16 per call) xEventGroupWaitBits/6 (35433 (estimated locally),0.12 per call) 
  Calls: 
vListInitialise/19 (vListInitialise) @06e9cc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xEventGroupCreate/4 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pvPortMalloc/18 (pvPortMalloc) @06e9cb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xEventGroupCreate/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
vEventGroupSetNumber/17 (vEventGroupSetNumber) @06e9c700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
uxEventGroupGetNumber/16 (uxEventGroupGetNumber) @06e9c460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xEventGroupSetBitsFromISR/15 (xEventGroupSetBitsFromISR) @06e9c1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: vEventGroupSetBitsCallback/12 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: xTimerPendFunctionCallFromISR/27 (1073741824 (estimated locally),1.00 per call) 
prvTestWaitCondition/14 (prvTestWaitCondition) @06e91e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: xEventGroupWaitBits/6 (3888 (estimated locally),0.01 per call) xEventGroupWaitBits/6 (23563 (estimated locally),0.08 per call) 
  Calls: 
vEventGroupClearBitsCallback/13 (vEventGroupClearBitsCallback) @06e91620
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: 
  Referring: xEventGroupClearBitsFromISR/8 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: xEventGroupClearBits/7 (1073741824 (estimated locally),1.00 per call) 
vEventGroupSetBitsCallback/12 (vEventGroupSetBitsCallback) @06e910e0
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: 
  Referring: xEventGroupSetBitsFromISR/15 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: xEventGroupSetBits/10 (1073741824 (estimated locally),1.00 per call) 
vEventGroupDelete/11 (vEventGroupDelete) @06e91d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskResumeAll/23 (63439 (estimated locally),0.27 per call) vPortFree/29 (63439 (estimated locally),0.27 per call) vTaskRemoveFromUnorderedEventList/28 (1030048 (estimated locally),4.46 per call) vTaskSuspendAll/21 (123389 (estimated locally),0.53 per call) 
xEventGroupSetBits/10 (xEventGroupSetBits) @06e919a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:228942 (estimated locally) body optimize_size
  Called by: vEventGroupSetBitsCallback/12 (1073741824 (estimated locally),1.00 per call) xEventGroupSync/5 (23563 (estimated locally),0.11 per call) 
  Calls: xEventGroupSetBits.part.0/39 (52886 (estimated locally),0.23 per call) 
xEventGroupGetBitsFromISR/9 (xEventGroupGetBitsFromISR) @06e91540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xEventGroupClearBitsFromISR/8 (xEventGroupClearBitsFromISR) @06e912a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: vEventGroupClearBitsCallback/13 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: xTimerPendFunctionCallFromISR/27 (1073741824 (estimated locally),1.00 per call) 
xEventGroupClearBits/7 (xEventGroupClearBits) @06e91000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:228942 (estimated locally) body optimize_size
  Called by: vEventGroupClearBitsCallback/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: xEventGroupClearBits.part.0/36 (52886 (estimated locally),0.23 per call) 
xEventGroupWaitBits/6 (xEventGroupWaitBits) @06ee1460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:306783 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/26 (3888 (estimated locally),0.01 per call) prvTestWaitCondition/14 (3888 (estimated locally),0.01 per call) vPortEnterCritical/25 (3888 (estimated locally),0.01 per call) uxTaskResetEventItemValue/24 (11782 (estimated locally),0.04 per call) xTaskResumeAll/23 (23563 (estimated locally),0.08 per call) vTaskPlaceOnUnorderedEventList/22 (5891 (estimated locally),0.02 per call) prvTestWaitCondition/14 (23563 (estimated locally),0.08 per call) vTaskSuspendAll/21 (23563 (estimated locally),0.08 per call) xTaskGetSchedulerState/20 (35433 (estimated locally),0.12 per call) 
xEventGroupSync/5 (xEventGroupSync) @06ee1a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/26 (3888 (estimated locally),0.02 per call) vPortEnterCritical/25 (3888 (estimated locally),0.02 per call) uxTaskResetEventItemValue/24 (11782 (estimated locally),0.05 per call) xTaskResumeAll/23 (23563 (estimated locally),0.11 per call) vTaskPlaceOnUnorderedEventList/22 (5132 (estimated locally),0.02 per call) xEventGroupSetBits/10 (23563 (estimated locally),0.11 per call) vTaskSuspendAll/21 (23563 (estimated locally),0.11 per call) xTaskGetSchedulerState/20 (35433 (estimated locally),0.16 per call) 
xEventGroupCreate/4 (xEventGroupCreate) @06ee1620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: vListInitialise/19 (574129754 (estimated locally),0.53 per call) pvPortMalloc/18 (1073741824 (estimated locally),1.00 per call) 

;; Function xEventGroupCreate (xEventGroupCreate, funcdef_no=4, decl_uid=6281, cgraph_uid=5, symbol_order=4)

Modification phase of node xEventGroupCreate/4
xEventGroupCreate ()
{
  struct EventGroup_t * pxEventBits;
  struct List_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxEventBits_5 = pvPortMalloc (28);
  # DEBUG pxEventBits => pxEventBits_5
  # DEBUG BEGIN_STMT
  if (pxEventBits_5 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pxEventBits_5->uxEventBits = 0;
  # DEBUG BEGIN_STMT
  _1 = &pxEventBits_5->xTasksWaitingForBits;
  vListInitialise (_1);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return pxEventBits_5;

}



;; Function xEventGroupWaitBits (xEventGroupWaitBits, funcdef_no=6, decl_uid=6287, cgraph_uid=7, symbol_order=6)

Modification phase of node xEventGroupWaitBits/6
xEventGroupWaitBits (struct EventGroupDef_t * xEventGroup, const EventBits_t uxBitsToWaitFor, const BaseType_t xClearOnExit, const BaseType_t xWaitForAllBits, TickType_t xTicksToWait)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  const EventBits_t uxCurrentEventBits;
  BaseType_t xAlreadyYielded;
  BaseType_t xWaitConditionMet;
  EventBits_t uxControlBits;
  EventBits_t uxReturn;
  long unsigned int _1;
  long int _2;
  long unsigned int _3;
  long unsigned int _4;
  struct List_t * _5;
  long unsigned int _6;
  long unsigned int _7;
  long int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 306783]:
  # DEBUG BEGIN_STMT
  # DEBUG pxEventBits => xEventGroup_22(D)
  # DEBUG BEGIN_STMT
  # DEBUG uxControlBits => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xTimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  if (xEventGroup_22(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 3> [local count: 92035]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_45 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_45

  <bb 4> [local count: 920350133]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 34> [local count: 920350133]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = uxBitsToWaitFor_23(D) & 4278190080;
  if (_1 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_30 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_30

  <bb 7> [local count: 1073741823]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 35> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (uxBitsToWaitFor_23(D) == 0)
    goto <bb 9>; [67.00%]
  else
    goto <bb 11>; [33.00%]

  <bb 9> [local count: 71941]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_49 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_49

  <bb 10> [local count: 719407021]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 36> [local count: 719407021]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = xTaskGetSchedulerState ();
  if (_2 != 0)
    goto <bb 15>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 12> [local count: 23740]:
  if (xTicksToWait_26(D) == 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 13> [local count: 11870]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_50 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_50

  <bb 14> [local count: 118702158]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 37> [local count: 118702158]:
  goto <bb 14>; [100.00%]

  <bb 15> [local count: 23563]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  uxCurrentEventBits_28 = MEM[(struct EventGroup_t *)xEventGroup_22(D)].uxEventBits;
  # DEBUG uxCurrentEventBits => uxCurrentEventBits_28
  # DEBUG BEGIN_STMT
  xWaitConditionMet_31 = prvTestWaitCondition (uxCurrentEventBits_28, uxBitsToWaitFor_23(D), xWaitForAllBits_29(D));
  # DEBUG xWaitConditionMet => xWaitConditionMet_31
  # DEBUG BEGIN_STMT
  if (xWaitConditionMet_31 != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 16> [local count: 11782]:
  # DEBUG BEGIN_STMT
  # DEBUG uxReturn => uxCurrentEventBits_28
  # DEBUG BEGIN_STMT
  # DEBUG xTicksToWait => 0
  # DEBUG BEGIN_STMT
  if (xClearOnExit_32(D) != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 24>; [50.00%]

  <bb 17> [local count: 5891]:
  # DEBUG BEGIN_STMT
  _3 = ~uxBitsToWaitFor_23(D);
  _4 = _3 & uxCurrentEventBits_28;
  MEM[(struct EventGroup_t *)xEventGroup_22(D)].uxEventBits = _4;
  goto <bb 24>; [100.00%]

  <bb 18> [local count: 11782]:
  # DEBUG BEGIN_STMT
  if (xTicksToWait_26(D) == 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 19> [local count: 5891]:
  # DEBUG BEGIN_STMT
  if (xClearOnExit_32(D) != 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 20> [local count: 2945]:
  # DEBUG BEGIN_STMT
  # DEBUG uxControlBits => 16777216

  <bb 21> [local count: 5891]:
  # uxControlBits_15 = PHI <0(19), 16777216(20)>
  # DEBUG uxControlBits => uxControlBits_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xWaitForAllBits_29(D) != 0)
    goto <bb 22>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 22> [local count: 2945]:
  # DEBUG BEGIN_STMT
  uxControlBits_33 = uxControlBits_15 | 67108864;
  # DEBUG uxControlBits => uxControlBits_33

  <bb 23> [local count: 5891]:
  # uxControlBits_16 = PHI <uxControlBits_15(21), uxControlBits_33(22)>
  # DEBUG uxControlBits => uxControlBits_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = &MEM[(struct EventGroup_t *)xEventGroup_22(D)].xTasksWaitingForBits;
  _6 = uxControlBits_16 | uxBitsToWaitFor_23(D);
  vTaskPlaceOnUnorderedEventList (_5, _6, xTicksToWait_26(D));
  # DEBUG BEGIN_STMT
  # DEBUG uxReturn => 0

  <bb 24> [local count: 23563]:
  # xTicksToWait_11 = PHI <0(17), xTicksToWait_26(D)(18), xTicksToWait_26(D)(23), 0(16)>
  # uxReturn_12 = PHI <uxCurrentEventBits_28(17), uxCurrentEventBits_28(18), 0(23), uxCurrentEventBits_28(16)>
  # DEBUG xTimeoutOccurred => NULL
  # DEBUG uxReturn => uxReturn_12
  # DEBUG xTicksToWait => xTicksToWait_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xAlreadyYielded_37 = xTaskResumeAll ();
  # DEBUG xAlreadyYielded => xAlreadyYielded_37
  # DEBUG BEGIN_STMT
  if (xTicksToWait_11 != 0)
    goto <bb 25>; [50.00%]
  else
    goto <bb 33>; [50.00%]

  <bb 25> [local count: 11782]:
  # DEBUG BEGIN_STMT
  if (xAlreadyYielded_37 == 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 27>; [50.00%]

  <bb 26> [local count: 5891]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 27> [local count: 11782]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxReturn_42 = uxTaskResetEventItemValue ();
  # DEBUG uxReturn => uxReturn_42
  # DEBUG BEGIN_STMT
  _7 = uxReturn_42 & 33554432;
  if (_7 == 0)
    goto <bb 28>; [33.00%]
  else
    goto <bb 32>; [67.00%]

  <bb 28> [local count: 3888]:
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  uxReturn_44 = MEM[(struct EventGroup_t *)xEventGroup_22(D)].uxEventBits;
  # DEBUG uxReturn => uxReturn_44
  # DEBUG BEGIN_STMT
  _8 = prvTestWaitCondition (uxReturn_44, uxBitsToWaitFor_23(D), xWaitForAllBits_29(D));
  if (_8 != 0)
    goto <bb 29>; [50.00%]
  else
    goto <bb 31>; [50.00%]

  <bb 29> [local count: 1944]:
  # DEBUG BEGIN_STMT
  if (xClearOnExit_32(D) != 0)
    goto <bb 30>; [50.00%]
  else
    goto <bb 31>; [50.00%]

  <bb 30> [local count: 972]:
  # DEBUG BEGIN_STMT
  _9 = ~uxBitsToWaitFor_23(D);
  _10 = _9 & uxReturn_44;
  MEM[(struct EventGroup_t *)xEventGroup_22(D)].uxEventBits = _10;

  <bb 31> [local count: 3888]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xTimeoutOccurred => 1
  # DEBUG BEGIN_STMT
  vPortExitCritical ();

  <bb 32> [local count: 11782]:
  # uxReturn_13 = PHI <uxReturn_42(27), uxReturn_44(31)>
  # DEBUG uxReturn => uxReturn_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxReturn_48 = uxReturn_13 & 16777215;
  # DEBUG uxReturn => uxReturn_48

  <bb 33> [local count: 23563]:
  # uxReturn_14 = PHI <uxReturn_12(24), uxReturn_48(32)>
  # DEBUG uxReturn => uxReturn_14
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return uxReturn_14;

}



;; Function xEventGroupClearBits (xEventGroupClearBits, funcdef_no=7, decl_uid=6290, cgraph_uid=8, symbol_order=7)

Modification phase of node xEventGroupClearBits/7
xEventGroupClearBits (struct EventGroupDef_t * xEventGroup, const EventBits_t uxBitsToClear)
{
  EventBits_t D.6617;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  long unsigned int _1;

  <bb 2> [local count: 228942]:
  # DEBUG BEGIN_STMT
  # DEBUG pxEventBits => xEventGroup_3(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xEventGroup_3(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 3> [local count: 68683]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_7 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_7

  <bb 4> [local count: 686828460]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 686828460]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = uxBitsToClear_5(D) & 4278190080;
  if (_1 != 0)
    goto <bb 6>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 6> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_8 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_8

  <bb 7> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 52886]:
  _2 = xEventGroupClearBits.part.0 (xEventGroup_3(D), uxBitsToClear_5(D));
  return _2;

}



;; Function vEventGroupClearBitsCallback (vEventGroupClearBitsCallback, funcdef_no=13, decl_uid=6315, cgraph_uid=14, symbol_order=13)

Modification phase of node vEventGroupClearBitsCallback/13
vEventGroupClearBitsCallback (void * pvEventGroup, const uint32_t ulBitsToClear)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  xEventGroupClearBits (pvEventGroup_2(D), ulBitsToClear_3(D));
  return;

}



;; Function xEventGroupClearBitsFromISR (xEventGroupClearBitsFromISR, funcdef_no=8, decl_uid=6293, cgraph_uid=9, symbol_order=8)

Modification phase of node xEventGroupClearBitsFromISR/8
xEventGroupClearBitsFromISR (struct EventGroupDef_t * xEventGroup, const EventBits_t uxBitsToClear)
{
  BaseType_t xReturn;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xReturn_5 = xTimerPendFunctionCallFromISR (vEventGroupClearBitsCallback, xEventGroup_2(D), uxBitsToClear_3(D), 0B);
  # DEBUG xReturn => xReturn_5
  # DEBUG BEGIN_STMT
  return xReturn_5;

}



;; Function xEventGroupGetBitsFromISR (xEventGroupGetBitsFromISR, funcdef_no=9, decl_uid=6307, cgraph_uid=10, symbol_order=9)

Modification phase of node xEventGroupGetBitsFromISR/9
xEventGroupGetBitsFromISR (struct EventGroupDef_t * xEventGroup)
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  EventBits_t uxReturn;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pxEventBits => xEventGroup_1(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY ulPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mrs %0, basepri											
	mov %1, %2												
	cpsid i													
	msr basepri, %1											
	isb														
	dsb														
	cpsie i													
" : "=r" ulOriginalBASEPRI_4, "=r" ulNewBASEPRI_5 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_5
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_4
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptStatus => ulOriginalBASEPRI_4
  # DEBUG BEGIN_STMT
  uxReturn_3 = MEM[(const struct EventGroup_t *)xEventGroup_1(D)].uxEventBits;
  # DEBUG uxReturn => uxReturn_3
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_4
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_4 : "memory");
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  return uxReturn_3;

}



;; Function xEventGroupSetBits (xEventGroupSetBits, funcdef_no=10, decl_uid=6296, cgraph_uid=11, symbol_order=10)

Modification phase of node xEventGroupSetBits/10
xEventGroupSetBits (struct EventGroupDef_t * xEventGroup, const EventBits_t uxBitsToSet)
{
  EventBits_t D.6644;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  long unsigned int _1;

  <bb 2> [local count: 228942]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG uxBitsToClear => 0
  # DEBUG BEGIN_STMT
  # DEBUG pxEventBits => xEventGroup_3(D)
  # DEBUG BEGIN_STMT
  # DEBUG xMatchFound => 0
  # DEBUG BEGIN_STMT
  if (xEventGroup_3(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 3> [local count: 68683]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_7 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_7

  <bb 4> [local count: 686828460]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 686828460]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = uxBitsToSet_4(D) & 4278190080;
  if (_1 != 0)
    goto <bb 6>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 6> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_8 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_8

  <bb 7> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 52886]:
  _6 = xEventGroupSetBits.part.0 (xEventGroup_3(D), uxBitsToSet_4(D));
  return _6;

}



;; Function xEventGroupSync (xEventGroupSync, funcdef_no=5, decl_uid=6305, cgraph_uid=6, symbol_order=5)

Modification phase of node xEventGroupSync/5
xEventGroupSync (struct EventGroupDef_t * xEventGroup, const EventBits_t uxBitsToSet, const EventBits_t uxBitsToWaitFor, TickType_t xTicksToWait)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  BaseType_t xAlreadyYielded;
  EventBits_t uxReturn;
  EventBits_t uxOriginalBitValue;
  long unsigned int _1;
  long int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  struct List_t * _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pxEventBits => xEventGroup_23(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xTimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  _1 = uxBitsToWaitFor_24(D) & 4278190080;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_47 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_47

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 26> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (uxBitsToWaitFor_24(D) == 0)
    goto <bb 6>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 6> [local count: 71941]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_48 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_48

  <bb 7> [local count: 719407023]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 27> [local count: 719407023]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = xTaskGetSchedulerState ();
  if (_2 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 9> [local count: 23740]:
  if (xTicksToWait_27(D) == 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 10> [local count: 11870]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_49 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_49

  <bb 11> [local count: 118702159]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 28> [local count: 118702159]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 23563]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  uxOriginalBitValue_29 = MEM[(struct EventGroup_t *)xEventGroup_23(D)].uxEventBits;
  # DEBUG uxOriginalBitValue => uxOriginalBitValue_29
  # DEBUG BEGIN_STMT
  xEventGroupSetBits (xEventGroup_23(D), uxBitsToSet_30(D));
  # DEBUG BEGIN_STMT
  _3 = uxOriginalBitValue_29 | uxBitsToSet_30(D);
  _4 = _3 & uxBitsToWaitFor_24(D);
  if (_4 == uxBitsToWaitFor_24(D))
    goto <bb 13>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 13> [local count: 8011]:
  # DEBUG BEGIN_STMT
  # DEBUG uxReturn => _3
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct EventGroup_t *)xEventGroup_23(D)].uxEventBits;
  _6 = ~uxBitsToWaitFor_24(D);
  _7 = _5 & _6;
  MEM[(struct EventGroup_t *)xEventGroup_23(D)].uxEventBits = _7;
  # DEBUG BEGIN_STMT
  # DEBUG xTicksToWait => 0
  goto <bb 17>; [100.00%]

  <bb 14> [local count: 15552]:
  # DEBUG BEGIN_STMT
  if (xTicksToWait_27(D) != 0)
    goto <bb 15>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 15> [local count: 5132]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = &MEM[(struct EventGroup_t *)xEventGroup_23(D)].xTasksWaitingForBits;
  _9 = uxBitsToWaitFor_24(D) | 83886080;
  vTaskPlaceOnUnorderedEventList (_8, _9, xTicksToWait_27(D));
  # DEBUG BEGIN_STMT
  # DEBUG uxReturn => 0
  goto <bb 17>; [100.00%]

  <bb 16> [local count: 10420]:
  # DEBUG BEGIN_STMT
  uxReturn_32 = MEM[(struct EventGroup_t *)xEventGroup_23(D)].uxEventBits;
  # DEBUG uxReturn => uxReturn_32
  # DEBUG BEGIN_STMT
  # DEBUG xTimeoutOccurred => 1

  <bb 17> [local count: 23563]:
  # xTicksToWait_14 = PHI <0(13), xTicksToWait_27(D)(15), 0(16)>
  # uxReturn_15 = PHI <_3(13), 0(15), uxReturn_32(16)>
  # DEBUG uxReturn => uxReturn_15
  # DEBUG xTicksToWait => xTicksToWait_14
  # DEBUG BEGIN_STMT
  xAlreadyYielded_36 = xTaskResumeAll ();
  # DEBUG xAlreadyYielded => xAlreadyYielded_36
  # DEBUG BEGIN_STMT
  if (xTicksToWait_14 != 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 25>; [50.00%]

  <bb 18> [local count: 11782]:
  # DEBUG BEGIN_STMT
  if (xAlreadyYielded_36 == 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 19> [local count: 5891]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 20> [local count: 11782]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxReturn_41 = uxTaskResetEventItemValue ();
  # DEBUG uxReturn => uxReturn_41
  # DEBUG BEGIN_STMT
  _10 = uxReturn_41 & 33554432;
  if (_10 == 0)
    goto <bb 21>; [33.00%]
  else
    goto <bb 24>; [67.00%]

  <bb 21> [local count: 3888]:
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  uxReturn_43 = MEM[(struct EventGroup_t *)xEventGroup_23(D)].uxEventBits;
  # DEBUG uxReturn => uxReturn_43
  # DEBUG BEGIN_STMT
  _11 = uxBitsToWaitFor_24(D) & uxReturn_43;
  if (_11 == uxBitsToWaitFor_24(D))
    goto <bb 22>; [34.00%]
  else
    goto <bb 23>; [66.00%]

  <bb 22> [local count: 1322]:
  # DEBUG BEGIN_STMT
  _12 = ~uxBitsToWaitFor_24(D);
  _13 = _12 & uxReturn_43;
  MEM[(struct EventGroup_t *)xEventGroup_23(D)].uxEventBits = _13;

  <bb 23> [local count: 3888]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  # DEBUG xTimeoutOccurred => 1

  <bb 24> [local count: 11782]:
  # uxReturn_16 = PHI <uxReturn_41(20), uxReturn_43(23)>
  # DEBUG uxReturn => uxReturn_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxReturn_46 = uxReturn_16 & 16777215;
  # DEBUG uxReturn => uxReturn_46

  <bb 25> [local count: 23563]:
  # uxReturn_17 = PHI <uxReturn_15(17), uxReturn_46(24)>
  # DEBUG uxReturn => uxReturn_17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return uxReturn_17;

}



;; Function vEventGroupSetBitsCallback (vEventGroupSetBitsCallback, funcdef_no=12, decl_uid=6312, cgraph_uid=13, symbol_order=12)

Modification phase of node vEventGroupSetBitsCallback/12
vEventGroupSetBitsCallback (void * pvEventGroup, const uint32_t ulBitsToSet)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  xEventGroupSetBits (pvEventGroup_2(D), ulBitsToSet_3(D));
  return;

}



;; Function vEventGroupDelete (vEventGroupDelete, funcdef_no=11, decl_uid=6309, cgraph_uid=12, symbol_order=11)

Modification phase of node vEventGroupDelete/11
vEventGroupDelete (struct EventGroupDef_t * xEventGroup)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct xLIST_ITEM * _1;
  const struct MiniListItem_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG pxEventBits => xEventGroup_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xEventGroup_5(D) == 0B)
    goto <bb 3>; [46.53%]
  else
    goto <bb 5>; [53.47%]

  <bb 3> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_11 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_11

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => &MEM[(struct EventGroup_t *)xEventGroup_5(D)].xTasksWaitingForBits
  # DEBUG pxTasksWaitingForBits => D#2
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 6> [local count: 1089998]:
  # DEBUG BEGIN_STMT
  _1 = MEM[(const struct List_t *)xEventGroup_5(D) + 4B].xListEnd.pxNext;
  _2 = &MEM[(const struct List_t *)xEventGroup_5(D) + 4B].xListEnd;
  if (_1 == _2)
    goto <bb 7>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 7> [local count: 59950]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY vPortRaiseBASEPRI
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mov %0, %1												
	cpsid i													
	msr basepri, %0											
	isb														
	dsb														
	cpsie i													
" : "=r" ulNewBASEPRI_12 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_12

  <bb 8> [local count: 599500022]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 599500022]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 1030048]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskRemoveFromUnorderedEventList (_1, 33554432);

  <bb 10> [local count: 1153437]:
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(const struct List_t *)xEventGroup_5(D) + 4B].uxNumberOfItems;
  if (_3 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 11> [local count: 63439]:
  # DEBUG BEGIN_STMT
  vPortFree (xEventGroup_5(D));
  # DEBUG BEGIN_STMT
  xTaskResumeAll ();
  return;

}



;; Function xEventGroupSetBitsFromISR (xEventGroupSetBitsFromISR, funcdef_no=15, decl_uid=6300, cgraph_uid=16, symbol_order=15)

Modification phase of node xEventGroupSetBitsFromISR/15
xEventGroupSetBitsFromISR (struct EventGroupDef_t * xEventGroup, const EventBits_t uxBitsToSet, BaseType_t * pxHigherPriorityTaskWoken)
{
  BaseType_t xReturn;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xReturn_6 = xTimerPendFunctionCallFromISR (vEventGroupSetBitsCallback, xEventGroup_2(D), uxBitsToSet_3(D), pxHigherPriorityTaskWoken_4(D));
  # DEBUG xReturn => xReturn_6
  # DEBUG BEGIN_STMT
  return xReturn_6;

}



;; Function uxEventGroupGetNumber (uxEventGroupGetNumber, funcdef_no=16, decl_uid=6317, cgraph_uid=17, symbol_order=16)

Modification phase of node uxEventGroupGetNumber/16
uxEventGroupGetNumber (void * xEventGroup)
{
  UBaseType_t xReturn;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pxEventBits => xEventGroup_2(D)
  # DEBUG BEGIN_STMT
  if (xEventGroup_2(D) == 0B)
    goto <bb 4>; [30.00%]
  else
    goto <bb 3>; [70.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  xReturn_4 = MEM[(const struct EventGroup_t *)xEventGroup_2(D)].uxEventGroupNumber;
  # DEBUG xReturn => xReturn_4

  <bb 4> [local count: 1073741824]:
  # xReturn_1 = PHI <0(2), xReturn_4(3)>
  # DEBUG xReturn => xReturn_1
  # DEBUG BEGIN_STMT
  return xReturn_1;

}



;; Function vEventGroupSetNumber (vEventGroupSetNumber, funcdef_no=17, decl_uid=6320, cgraph_uid=18, symbol_order=17)

Modification phase of node vEventGroupSetNumber/17
vEventGroupSetNumber (void * xEventGroup, UBaseType_t uxEventGroupNumber)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  MEM[(struct EventGroup_t *)xEventGroup_2(D)].uxEventGroupNumber = uxEventGroupNumber_3(D);
  return;

}


