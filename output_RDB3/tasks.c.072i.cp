
IPA constant propagation start:
Determining dynamic type for call: vTaskGetInfo (pxNextTCB_12, _16, 1, eState_17(D));
  Starting walk at: vTaskGetInfo (pxNextTCB_12, _16, 1, eState_17(D));
  instance pointer: pxNextTCB_12  Outer instance pointer: pxNextTCB_12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vTaskGetInfo (pxNextTCB_12, _16, 1, eState_17(D));
Determining dynamic type for call: vTaskGetInfo (pxNextTCB_12, _16, 1, eState_17(D));
  Starting walk at: vTaskGetInfo (pxNextTCB_12, _16, 1, eState_17(D));
  instance pointer: _16  Outer instance pointer: _16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vTaskGetInfo (pxNextTCB_12, _16, 1, eState_17(D));
Determining dynamic type for call: uxArraySize_28 = uxTaskGetSystemState (pxTaskStatusArray_26, uxArraySize_24, 0B);
  Starting walk at: uxArraySize_28 = uxTaskGetSystemState (pxTaskStatusArray_26, uxArraySize_24, 0B);
  instance pointer: pxTaskStatusArray_26  Outer instance pointer: pxTaskStatusArray_26 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTaskStatusArray_26 = pvPortMalloc (_2);
Determining dynamic type for call: uxArraySize_28 = uxTaskGetSystemState (pxTaskStatusArray_26, uxArraySize_24, 0B);
  Starting walk at: uxArraySize_28 = uxTaskGetSystemState (pxTaskStatusArray_26, uxArraySize_24, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTaskStatusArray_26 = pvPortMalloc (_2);
Determining dynamic type for call: pcWriteBuffer_31 = prvWriteNameToBuffer (pcWriteBuffer_16, _8);
  Starting walk at: pcWriteBuffer_31 = prvWriteNameToBuffer (pcWriteBuffer_16, _8);
  instance pointer: pcWriteBuffer_16  Outer instance pointer: pcWriteBuffer_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:uxArraySize_28 = uxTaskGetSystemState (pxTaskStatusArray_26, uxArraySize_24, 0B);
  Function call may change dynamic type:pxTaskStatusArray_26 = pvPortMalloc (_2);
  Function call may change dynamic type:sprintf (pcWriteBuffer_31, "\t%c\t%u\t%u\t%u\r\n", _9, _11, _13, _14);
  Function call may change dynamic type:pcWriteBuffer_31 = prvWriteNameToBuffer (pcWriteBuffer_16, _8);
Determining dynamic type for call: pcWriteBuffer_31 = prvWriteNameToBuffer (pcWriteBuffer_16, _8);
  Starting walk at: pcWriteBuffer_31 = prvWriteNameToBuffer (pcWriteBuffer_16, _8);
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:uxArraySize_28 = uxTaskGetSystemState (pxTaskStatusArray_26, uxArraySize_24, 0B);
  Function call may change dynamic type:pxTaskStatusArray_26 = pvPortMalloc (_2);
  Function call may change dynamic type:sprintf (pcWriteBuffer_31, "\t%c\t%u\t%u\t%u\r\n", _9, _11, _13, _14);
  Function call may change dynamic type:pcWriteBuffer_31 = prvWriteNameToBuffer (pcWriteBuffer_16, _8);
Determining dynamic type for call: _1 = prvTaskCheckFreeStackSpace (pucEndOfStack_6);
  Starting walk at: _1 = prvTaskCheckFreeStackSpace (pucEndOfStack_6);
  instance pointer: pucEndOfStack_6  Outer instance pointer: pucEndOfStack_6 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: uxTask_2 = prvListTasksWithinSingleList.part.0 (pxTaskStatusArray_8(D), pxList_7(D), eState_9(D));
  Starting walk at: uxTask_2 = prvListTasksWithinSingleList.part.0 (pxTaskStatusArray_8(D), pxList_7(D), eState_9(D));
  instance pointer: pxTaskStatusArray_8(D)  Outer instance pointer: pxTaskStatusArray_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: uxTask_2 = prvListTasksWithinSingleList.part.0 (pxTaskStatusArray_8(D), pxList_7(D), eState_9(D));
  Starting walk at: uxTask_2 = prvListTasksWithinSingleList.part.0 (pxTaskStatusArray_8(D), pxList_7(D), eState_9(D));
  instance pointer: pxList_7(D)  Outer instance pointer: pxList_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = eTaskGetState (iftmp.122_11);
  Starting walk at: _8 = eTaskGetState (iftmp.122_11);
  instance pointer: iftmp.122_11  Outer instance pointer: iftmp.122_11 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = prvTaskCheckFreeStackSpace (_9);
  Starting walk at: _10 = prvTaskCheckFreeStackSpace (_9);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = eTaskGetState (iftmp.122_11);
  Function call may change dynamic type:xTaskResumeAll ();
  Function call may change dynamic type:vTaskSuspendAll ();
Determining dynamic type for call: prvDeleteTCB (pxTCB_11);
  Starting walk at: prvDeleteTCB (pxTCB_11);
  instance pointer: pxTCB_11  Outer instance pointer: pxTCB_11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:uxListRemove (_2);
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:prvDeleteTCB (pxTCB_11);
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:uxListRemove (_2);
  Function call may change dynamic type:vPortEnterCritical ();
Determining dynamic type for call: vTaskInternalSetTimeOutState (pxTimeOut_11(D));
  Starting walk at: vTaskInternalSetTimeOutState (pxTimeOut_11(D));
  instance pointer: pxTimeOut_11(D)  Outer instance pointer: pxTimeOut_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortEnterCritical ();
Determining dynamic type for call: _1 = eTaskGetState (xTask_18(D));
  Starting walk at: _1 = eTaskGetState (xTask_18(D));
  instance pointer: xTask_18(D)  Outer instance pointer: xTask_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vTaskSuspendAll ();
Determining dynamic type for call: _27 = prvListTasksWithinSingleList (_3, _4, 1);
  Starting walk at: _27 = prvListTasksWithinSingleList (_3, _4, 1);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _27 = prvListTasksWithinSingleList (_3, _4, 1);
  Starting walk at: _27 = prvListTasksWithinSingleList (_3, _4, 1);
  instance pointer: _4  Outer instance pointer: &pxReadyTasksLists[uxQueue_24] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  Starting walk at: _30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  Starting walk at: _30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  instance pointer: pxDelayedTaskList.74_7  Outer instance pointer: pxDelayedTaskList.74_7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  Starting walk at: _33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  Starting walk at: _33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  instance pointer: pxOverflowDelayedTaskList.75_10  Outer instance pointer: pxOverflowDelayedTaskList.75_10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _36 = prvListTasksWithinSingleList (_12, &xTasksWaitingTermination, 4);
  Starting walk at: _36 = prvListTasksWithinSingleList (_12, &xTasksWaitingTermination, 4);
  instance pointer: _12  Outer instance pointer: _12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  Function call may change dynamic type:_30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _36 = prvListTasksWithinSingleList (_12, &xTasksWaitingTermination, 4);
  Starting walk at: _36 = prvListTasksWithinSingleList (_12, &xTasksWaitingTermination, 4);
  instance pointer: &xTasksWaitingTermination  Outer instance pointer: xTasksWaitingTermination offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  Function call may change dynamic type:_30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _39 = prvListTasksWithinSingleList (_14, &xSuspendedTaskList, 3);
  Starting walk at: _39 = prvListTasksWithinSingleList (_14, &xSuspendedTaskList, 3);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_36 = prvListTasksWithinSingleList (_12, &xTasksWaitingTermination, 4);
  Function call may change dynamic type:_33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  Function call may change dynamic type:_30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: _39 = prvListTasksWithinSingleList (_14, &xSuspendedTaskList, 3);
  Starting walk at: _39 = prvListTasksWithinSingleList (_14, &xSuspendedTaskList, 3);
  instance pointer: &xSuspendedTaskList  Outer instance pointer: xSuspendedTaskList offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_36 = prvListTasksWithinSingleList (_12, &xTasksWaitingTermination, 4);
  Function call may change dynamic type:_33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  Function call may change dynamic type:_30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:_27 = prvListTasksWithinSingleList (_3, _4, 1);
Determining dynamic type for call: pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Starting walk at: pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  instance pointer: _2  Outer instance pointer: &pxReadyTasksLists[uxQueue_19] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Starting walk at: pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  instance pointer: pcNameToQuery_17(D)  Outer instance pointer: pcNameToQuery_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  Starting walk at: pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  instance pointer: pxDelayedTaskList.71_3  Outer instance pointer: pxDelayedTaskList.71_3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  Starting walk at: pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  instance pointer: pcNameToQuery_17(D)  Outer instance pointer: pcNameToQuery_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
  Starting walk at: pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
  instance pointer: pxOverflowDelayedTaskList.72_4  Outer instance pointer: pxOverflowDelayedTaskList.72_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
  Starting walk at: pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
  instance pointer: pcNameToQuery_17(D)  Outer instance pointer: pcNameToQuery_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_27 = prvSearchForNameWithinSingleList (&xSuspendedTaskList, pcNameToQuery_17(D));
  Starting walk at: pxTCB_27 = prvSearchForNameWithinSingleList (&xSuspendedTaskList, pcNameToQuery_17(D));
  instance pointer: &xSuspendedTaskList  Outer instance pointer: xSuspendedTaskList offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  Function call may change dynamic type:pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_27 = prvSearchForNameWithinSingleList (&xSuspendedTaskList, pcNameToQuery_17(D));
  Starting walk at: pxTCB_27 = prvSearchForNameWithinSingleList (&xSuspendedTaskList, pcNameToQuery_17(D));
  instance pointer: pcNameToQuery_17(D)  Outer instance pointer: pcNameToQuery_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  Function call may change dynamic type:pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_29 = prvSearchForNameWithinSingleList (&xTasksWaitingTermination, pcNameToQuery_17(D));
  Starting walk at: pxTCB_29 = prvSearchForNameWithinSingleList (&xTasksWaitingTermination, pcNameToQuery_17(D));
  instance pointer: &xTasksWaitingTermination  Outer instance pointer: xTasksWaitingTermination offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  Function call may change dynamic type:pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
  Function call may change dynamic type:pxTCB_27 = prvSearchForNameWithinSingleList (&xSuspendedTaskList, pcNameToQuery_17(D));
Determining dynamic type for call: pxTCB_29 = prvSearchForNameWithinSingleList (&xTasksWaitingTermination, pcNameToQuery_17(D));
  Starting walk at: pxTCB_29 = prvSearchForNameWithinSingleList (&xTasksWaitingTermination, pcNameToQuery_17(D));
  instance pointer: pcNameToQuery_17(D)  Outer instance pointer: pcNameToQuery_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  Function call may change dynamic type:vTaskSuspendAll ();
  Function call may change dynamic type:pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  Function call may change dynamic type:pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
  Function call may change dynamic type:pxTCB_27 = prvSearchForNameWithinSingleList (&xSuspendedTaskList, pcNameToQuery_17(D));
Determining dynamic type for call: xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  Starting walk at: xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  instance pointer: prvIdleTask  Outer instance pointer: prvIdleTask offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  Starting walk at: xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  instance pointer: "IDLE"  Outer instance pointer: "IDLE" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  Starting walk at: xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  Starting walk at: xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  instance pointer: &xIdleTaskHandle  Outer instance pointer: xIdleTaskHandle offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = prvTaskIsTaskSuspended (xTaskToResume_20(D));
  Starting walk at: _1 = prvTaskIsTaskSuspended (xTaskToResume_20(D));
  instance pointer: xTaskToResume_20(D)  Outer instance pointer: xTaskToResume_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortValidateInterruptPriority ();
Determining dynamic type for call: _2 = prvTaskIsTaskSuspended (xTaskToResume_16(D));
  Starting walk at: _2 = prvTaskIsTaskSuspended (xTaskToResume_16(D));
  instance pointer: xTaskToResume_16(D)  Outer instance pointer: xTaskToResume_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortEnterCritical ();
Determining dynamic type for call: xReturn_2 = prvTaskIsTaskSuspended.part.0 (xTask_5(D));
  Starting walk at: xReturn_2 = prvTaskIsTaskSuspended.part.0 (xTask_5(D));
  instance pointer: xTask_5(D)  Outer instance pointer: xTask_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: eReturn_13 = eTaskGetState.part.0 (xTask_5(D));
  Starting walk at: eReturn_13 = eTaskGetState.part.0 (xTask_5(D));
  instance pointer: xTask_5(D)  Outer instance pointer: xTask_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:vPortEnterCritical ();
Determining dynamic type for call: prvDeleteTCB (iftmp.12_15);
  Starting walk at: prvDeleteTCB (iftmp.12_15);
  instance pointer: iftmp.12_15  Outer instance pointer: iftmp.12_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:vListInsertEnd (&xTasksWaitingTermination, _1);
  Function call may change dynamic type:uxListRemove (_1);
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:uxListRemove (_3);
  Function call may change dynamic type:prvResetNextTaskUnblockTime ();
Determining dynamic type for call: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  Starting walk at: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  instance pointer: pxTaskCode_14(D)  Outer instance pointer: pxTaskCode_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortFree (pxStack_9);
  Function call may change dynamic type:pxNewTCB_11 = pvPortMalloc (96);
  Function call may change dynamic type:pxStack_9 = pvPortMalloc (_2);
Determining dynamic type for call: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  Starting walk at: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  instance pointer: pcName_15(D)  Outer instance pointer: pcName_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortFree (pxStack_9);
  Function call may change dynamic type:pxNewTCB_11 = pvPortMalloc (96);
  Function call may change dynamic type:pxStack_9 = pvPortMalloc (_2);
Determining dynamic type for call: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  Starting walk at: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  instance pointer: pvParameters_16(D)  Outer instance pointer: pvParameters_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortFree (pxStack_9);
  Function call may change dynamic type:pxNewTCB_11 = pvPortMalloc (96);
  Function call may change dynamic type:pxStack_9 = pvPortMalloc (_2);
Determining dynamic type for call: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  Starting walk at: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  instance pointer: pxCreatedTask_18(D)  Outer instance pointer: pxCreatedTask_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortFree (pxStack_9);
  Function call may change dynamic type:pxNewTCB_11 = pvPortMalloc (96);
  Function call may change dynamic type:pxStack_9 = pvPortMalloc (_2);
Determining dynamic type for call: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  Starting walk at: prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  instance pointer: pxNewTCB_11  Outer instance pointer: pxNewTCB_11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortFree (pxStack_9);
  Function call may change dynamic type:pxNewTCB_11 = pvPortMalloc (96);
  Function call may change dynamic type:pxStack_9 = pvPortMalloc (_2);
Determining dynamic type for call: prvAddNewTaskToReadyList (pxNewTCB_11);
  Starting walk at: prvAddNewTaskToReadyList (pxNewTCB_11);
  instance pointer: pxNewTCB_11  Outer instance pointer: pxNewTCB_11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  Function call may change dynamic type:vPortFree (pxStack_9);
  Function call may change dynamic type:pxNewTCB_11 = pvPortMalloc (96);
  Function call may change dynamic type:pxStack_9 = pvPortMalloc (_2);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  prvListTasksWithinSingleList.part.0/161:
    callsite  prvListTasksWithinSingleList.part.0/161 -> vTaskGetInfo/74 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  vTaskSwitchContext.part.0/148:
  Jump functions of caller  xTaskResumeAll.part.0/139:
    callsite  xTaskResumeAll.part.0/139 -> prvResetNextTaskUnblockTime/79 : 
    callsite  xTaskResumeAll.part.0/139 -> xTaskIncrementTick/56 : 
  Jump functions of caller  xTaskIncrementTick.part.0/137:
    callsite  xTaskIncrementTick.part.0/137 -> prvResetNextTaskUnblockTime/79 : 
  Jump functions of caller  eTaskGetState.part.0/124:
  Jump functions of caller  prvAddCurrentTaskToDelayedList.part.0/121:
  Jump functions of caller  prvInitialiseNewTask.isra.0/120:
  Jump functions of caller  prvResetNextTaskUnblockTime.part.0/117:
  Jump functions of caller  prvTaskIsTaskSuspended.part.0/116:
  Jump functions of caller  strcpy/114:
  Jump functions of caller  sprintf/113:
  Jump functions of caller  strlen/112:
  Jump functions of caller  vPortEndScheduler/111:
  Jump functions of caller  xPortStartScheduler/110:
  Jump functions of caller  xTimerCreateTimerTask/109:
  Jump functions of caller  vPortValidateInterruptPriority/108:
  Jump functions of caller  vListInsert/107:
  Jump functions of caller  vListInsertEnd/106:
  Jump functions of caller  uxListRemove/105:
  Jump functions of caller  vListInitialise/104:
  Jump functions of caller  vPortExitCritical/103:
  Jump functions of caller  vPortEnterCritical/102:
  Jump functions of caller  pxPortInitialiseStack/101:
  Jump functions of caller  vListInitialiseItem/100:
  Jump functions of caller  memset/99:
  Jump functions of caller  vPortFree/98:
  Jump functions of caller  pvPortMalloc/97:
  Jump functions of caller  prvAddCurrentTaskToDelayedList/96:
    callsite  prvAddCurrentTaskToDelayedList/96 -> prvAddCurrentTaskToDelayedList.part.0/121 : 
  Jump functions of caller  ulTaskGenericNotifyValueClear/95:
  Jump functions of caller  xTaskGenericNotifyStateClear/94:
  Jump functions of caller  vTaskGenericNotifyGiveFromISR/93:
  Jump functions of caller  xTaskGenericNotifyFromISR/92:
  Jump functions of caller  xTaskGenericNotify/91:
  Jump functions of caller  xTaskGenericNotifyWait/90:
    callsite  xTaskGenericNotifyWait/90 -> prvAddCurrentTaskToDelayedList/96 : 
       param 0: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  ulTaskGenericNotifyTake/89:
    callsite  ulTaskGenericNotifyTake/89 -> prvAddCurrentTaskToDelayedList/96 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  pvTaskIncrementMutexHeldCount/88:
  Jump functions of caller  uxTaskResetEventItemValue/87:
  Jump functions of caller  vTaskList/86:
    callsite  vTaskList/86 -> prvWriteNameToBuffer/85 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  vTaskList/86 -> uxTaskGetSystemState/53 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  prvWriteNameToBuffer/85:
  Jump functions of caller  vTaskPriorityDisinheritAfterTimeout/84:
  Jump functions of caller  xTaskPriorityDisinherit/83:
  Jump functions of caller  xTaskPriorityInherit/82:
  Jump functions of caller  xTaskGetSchedulerState/81:
  Jump functions of caller  xTaskGetCurrentTaskHandle/80:
  Jump functions of caller  prvResetNextTaskUnblockTime/79:
    callsite  prvResetNextTaskUnblockTime/79 -> prvResetNextTaskUnblockTime.part.0/117 : 
  Jump functions of caller  prvDeleteTCB/78:
  Jump functions of caller  uxTaskGetStackHighWaterMark/77:
    callsite  uxTaskGetStackHighWaterMark/77 -> prvTaskCheckFreeStackSpace/76 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  prvTaskCheckFreeStackSpace/76:
  Jump functions of caller  prvListTasksWithinSingleList/75:
    callsite  prvListTasksWithinSingleList/75 -> prvListTasksWithinSingleList.part.0/161 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  vTaskGetInfo/74:
    callsite  vTaskGetInfo/74 -> prvTaskCheckFreeStackSpace/76 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  vTaskGetInfo/74 -> eTaskGetState/35 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  vTaskGetInfo/74 -> xTaskResumeAll/46 : 
    callsite  vTaskGetInfo/74 -> vTaskSuspendAll/45 : 
  Jump functions of caller  prvCheckTasksWaitingTermination/73:
    callsite  prvCheckTasksWaitingTermination/73 -> prvDeleteTCB/78 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  prvInitialiseTaskLists/72:
  Jump functions of caller  pvTaskGetThreadLocalStoragePointer/71:
  Jump functions of caller  vTaskSetThreadLocalStoragePointer/70:
  Jump functions of caller  prvIdleTask/69:
    callsite  prvIdleTask/69 -> prvCheckTasksWaitingTermination/73 : 
  Jump functions of caller  vTaskSetTaskNumber/68:
  Jump functions of caller  uxTaskGetTaskNumber/67:
  Jump functions of caller  vTaskMissedYield/66:
  Jump functions of caller  xTaskCheckForTimeOut/65:
    callsite  xTaskCheckForTimeOut/65 -> vTaskInternalSetTimeOutState/64 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  vTaskInternalSetTimeOutState/64:
  Jump functions of caller  vTaskSetTimeOutState/63:
  Jump functions of caller  vTaskRemoveFromUnorderedEventList/62:
  Jump functions of caller  xTaskRemoveFromEventList/61:
  Jump functions of caller  vTaskPlaceOnEventListRestricted/60:
    callsite  vTaskPlaceOnEventListRestricted/60 -> prvAddCurrentTaskToDelayedList/96 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  vTaskPlaceOnUnorderedEventList/59:
    callsite  vTaskPlaceOnUnorderedEventList/59 -> prvAddCurrentTaskToDelayedList/96 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  vTaskPlaceOnEventList/58:
    callsite  vTaskPlaceOnEventList/58 -> prvAddCurrentTaskToDelayedList/96 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  vTaskSwitchContext/57:
    callsite  vTaskSwitchContext/57 -> vTaskSwitchContext.part.0/148 : 
  Jump functions of caller  xTaskIncrementTick/56:
    callsite  xTaskIncrementTick/56 -> xTaskIncrementTick.part.0/137 : 
  Jump functions of caller  xTaskAbortDelay/55:
    callsite  xTaskAbortDelay/55 -> xTaskResumeAll/46 : 
    callsite  xTaskAbortDelay/55 -> eTaskGetState/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xTaskAbortDelay/55 -> vTaskSuspendAll/45 : 
  Jump functions of caller  xTaskCatchUpTicks/54:
    callsite  xTaskCatchUpTicks/54 -> xTaskResumeAll/46 : 
    callsite  xTaskCatchUpTicks/54 -> vTaskSuspendAll/45 : 
  Jump functions of caller  uxTaskGetSystemState/53:
    callsite  uxTaskGetSystemState/53 -> xTaskResumeAll/46 : 
    callsite  uxTaskGetSystemState/53 -> prvListTasksWithinSingleList/75 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &xSuspendedTaskList
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
    callsite  uxTaskGetSystemState/53 -> prvListTasksWithinSingleList/75 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &xTasksWaitingTermination
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  uxTaskGetSystemState/53 -> prvListTasksWithinSingleList/75 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
    callsite  uxTaskGetSystemState/53 -> prvListTasksWithinSingleList/75 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
    callsite  uxTaskGetSystemState/53 -> prvListTasksWithinSingleList/75 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  uxTaskGetSystemState/53 -> vTaskSuspendAll/45 : 
  Jump functions of caller  xTaskGetHandle/52:
    callsite  xTaskGetHandle/52 -> xTaskResumeAll/46 : 
    callsite  xTaskGetHandle/52 -> prvSearchForNameWithinSingleList/51 : 
       param 0: CONST: &xTasksWaitingTermination
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xTaskGetHandle/52 -> prvSearchForNameWithinSingleList/51 : 
       param 0: CONST: &xSuspendedTaskList
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xTaskGetHandle/52 -> prvSearchForNameWithinSingleList/51 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xTaskGetHandle/52 -> prvSearchForNameWithinSingleList/51 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xTaskGetHandle/52 -> prvSearchForNameWithinSingleList/51 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xTaskGetHandle/52 -> vTaskSuspendAll/45 : 
  Jump functions of caller  prvSearchForNameWithinSingleList/51:
  Jump functions of caller  pcTaskGetName/50:
  Jump functions of caller  uxTaskGetNumberOfTasks/49:
  Jump functions of caller  xTaskGetTickCountFromISR/48:
  Jump functions of caller  xTaskGetTickCount/47:
  Jump functions of caller  xTaskResumeAll/46:
    callsite  xTaskResumeAll/46 -> xTaskResumeAll.part.0/139 : 
  Jump functions of caller  vTaskSuspendAll/45:
  Jump functions of caller  vTaskEndScheduler/44:
  Jump functions of caller  vTaskStartScheduler/43:
    callsite  vTaskStartScheduler/43 -> xTaskCreate/29 : 
       param 0: CONST: prvIdleTask
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: "IDLE"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 90
         value: 0x5a, mask: 0x0
         Unknown VR
       param 3: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 5: CONST: &xIdleTaskHandle
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  xTaskResumeFromISR/42:
    callsite  xTaskResumeFromISR/42 -> prvTaskIsTaskSuspended/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  vTaskResume/41:
    callsite  vTaskResume/41 -> prvTaskIsTaskSuspended/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  prvTaskIsTaskSuspended/40:
    callsite  prvTaskIsTaskSuspended/40 -> prvTaskIsTaskSuspended.part.0/116 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  vTaskSuspend/39:
    callsite  vTaskSuspend/39 -> vTaskSwitchContext/57 : 
    callsite  vTaskSuspend/39 -> prvResetNextTaskUnblockTime/79 : 
  Jump functions of caller  vTaskPrioritySet/38:
  Jump functions of caller  uxTaskPriorityGetFromISR/37:
  Jump functions of caller  uxTaskPriorityGet/36:
  Jump functions of caller  eTaskGetState/35:
    callsite  eTaskGetState/35 -> eTaskGetState.part.0/124 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  vTaskDelay/34:
    callsite  vTaskDelay/34 -> xTaskResumeAll/46 : 
    callsite  vTaskDelay/34 -> prvAddCurrentTaskToDelayedList/96 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  vTaskDelay/34 -> vTaskSuspendAll/45 : 
  Jump functions of caller  xTaskDelayUntil/33:
    callsite  xTaskDelayUntil/33 -> xTaskResumeAll/46 : 
    callsite  xTaskDelayUntil/33 -> prvAddCurrentTaskToDelayedList/96 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  xTaskDelayUntil/33 -> vTaskSuspendAll/45 : 
  Jump functions of caller  vTaskDelete/32:
    callsite  vTaskDelete/32 -> prvDeleteTCB/78 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  vTaskDelete/32 -> prvResetNextTaskUnblockTime/79 : 
  Jump functions of caller  prvAddNewTaskToReadyList/31:
    callsite  prvAddNewTaskToReadyList/31 -> prvInitialiseTaskLists/72 : 
  Jump functions of caller  xTaskCreate/29:
    callsite  xTaskCreate/29 -> prvAddNewTaskToReadyList/31 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xTaskCreate/29 -> prvInitialiseNewTask.isra.0/120 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR

 Propagating constants:

Not considering ulTaskGenericNotifyValueClear for cloning; -fipa-cp-clone disabled.
Not considering xTaskGenericNotifyStateClear for cloning; -fipa-cp-clone disabled.
Not considering vTaskGenericNotifyGiveFromISR for cloning; -fipa-cp-clone disabled.
Not considering xTaskGenericNotifyFromISR for cloning; -fipa-cp-clone disabled.
Not considering xTaskGenericNotify for cloning; -fipa-cp-clone disabled.
Not considering xTaskGenericNotifyWait for cloning; -fipa-cp-clone disabled.
Not considering ulTaskGenericNotifyTake for cloning; -fipa-cp-clone disabled.
Not considering pvTaskIncrementMutexHeldCount for cloning; -fipa-cp-clone disabled.
Not considering uxTaskResetEventItemValue for cloning; -fipa-cp-clone disabled.
Not considering vTaskList for cloning; -fipa-cp-clone disabled.
Not considering vTaskPriorityDisinheritAfterTimeout for cloning; -fipa-cp-clone disabled.
Not considering xTaskPriorityDisinherit for cloning; -fipa-cp-clone disabled.
Not considering xTaskPriorityInherit for cloning; -fipa-cp-clone disabled.
Not considering xTaskGetSchedulerState for cloning; -fipa-cp-clone disabled.
Not considering xTaskGetCurrentTaskHandle for cloning; -fipa-cp-clone disabled.
Not considering uxTaskGetStackHighWaterMark for cloning; -fipa-cp-clone disabled.
Not considering vTaskGetInfo for cloning; -fipa-cp-clone disabled.
Not considering pvTaskGetThreadLocalStoragePointer for cloning; -fipa-cp-clone disabled.
Not considering vTaskSetThreadLocalStoragePointer for cloning; -fipa-cp-clone disabled.
Not considering prvIdleTask for cloning; -fipa-cp-clone disabled.
Not considering vTaskSetTaskNumber for cloning; -fipa-cp-clone disabled.
Not considering uxTaskGetTaskNumber for cloning; -fipa-cp-clone disabled.
Not considering vTaskMissedYield for cloning; -fipa-cp-clone disabled.
Not considering xTaskCheckForTimeOut for cloning; -fipa-cp-clone disabled.
Not considering vTaskInternalSetTimeOutState for cloning; -fipa-cp-clone disabled.
Not considering vTaskSetTimeOutState for cloning; -fipa-cp-clone disabled.
Not considering vTaskRemoveFromUnorderedEventList for cloning; -fipa-cp-clone disabled.
Not considering xTaskRemoveFromEventList for cloning; -fipa-cp-clone disabled.
Not considering vTaskPlaceOnEventListRestricted for cloning; -fipa-cp-clone disabled.
Not considering vTaskPlaceOnUnorderedEventList for cloning; -fipa-cp-clone disabled.
Not considering vTaskPlaceOnEventList for cloning; -fipa-cp-clone disabled.
Not considering vTaskSwitchContext for cloning; -fipa-cp-clone disabled.
Not considering xTaskIncrementTick for cloning; -fipa-cp-clone disabled.
Not considering xTaskAbortDelay for cloning; -fipa-cp-clone disabled.
Not considering xTaskCatchUpTicks for cloning; -fipa-cp-clone disabled.
Not considering uxTaskGetSystemState for cloning; -fipa-cp-clone disabled.
Not considering xTaskGetHandle for cloning; -fipa-cp-clone disabled.
Not considering pcTaskGetName for cloning; -fipa-cp-clone disabled.
Not considering uxTaskGetNumberOfTasks for cloning; -fipa-cp-clone disabled.
Not considering xTaskGetTickCountFromISR for cloning; -fipa-cp-clone disabled.
Not considering xTaskGetTickCount for cloning; -fipa-cp-clone disabled.
Not considering xTaskResumeAll for cloning; -fipa-cp-clone disabled.
Not considering vTaskSuspendAll for cloning; -fipa-cp-clone disabled.
Not considering vTaskEndScheduler for cloning; -fipa-cp-clone disabled.
Not considering vTaskStartScheduler for cloning; -fipa-cp-clone disabled.
Not considering xTaskResumeFromISR for cloning; -fipa-cp-clone disabled.
Not considering vTaskResume for cloning; -fipa-cp-clone disabled.
Not considering vTaskSuspend for cloning; -fipa-cp-clone disabled.
Not considering vTaskPrioritySet for cloning; -fipa-cp-clone disabled.
Not considering uxTaskPriorityGetFromISR for cloning; -fipa-cp-clone disabled.
Not considering uxTaskPriorityGet for cloning; -fipa-cp-clone disabled.
Not considering eTaskGetState for cloning; -fipa-cp-clone disabled.
Not considering vTaskDelay for cloning; -fipa-cp-clone disabled.
Not considering xTaskDelayUntil for cloning; -fipa-cp-clone disabled.
Not considering vTaskDelete for cloning; -fipa-cp-clone disabled.
Not considering xTaskCreate for cloning; -fipa-cp-clone disabled.

overall_size: 2489, max_new_size: 11001
 - context independent values, size: 9, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: prvListTasksWithinSingleList.part.0/161:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               &xSuspendedTaskList [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               &xTasksWaitingTermination [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 3 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               4 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               2 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x3, mask = 0x7
         eTaskState [1, 4]
        AGGS VARIABLE
  Node: vTaskSwitchContext.part.0/148:
  Node: xTaskResumeAll.part.0/139:
  Node: xTaskIncrementTick.part.0/137:
  Node: eTaskGetState.part.0/124:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: prvAddCurrentTaskToDelayedList.part.0/121:
  Node: prvInitialiseNewTask.isra.0/120:
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
         Bits: value = 0x0, mask = 0xffff
         const uint32_t [0, 65535]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [6]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: prvResetNextTaskUnblockTime.part.0/117:
  Node: prvTaskIsTaskSuspended.part.0/116:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: prvAddCurrentTaskToDelayedList/96:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 1, loc_size: 30, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ulTaskGenericNotifyValueClear/95:
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
  Node: xTaskGenericNotifyStateClear/94:
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
  Node: vTaskGenericNotifyGiveFromISR/93:
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
  Node: xTaskGenericNotifyFromISR/92:
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
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xTaskGenericNotify/91:
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
  Node: xTaskGenericNotifyWait/90:
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
  Node: ulTaskGenericNotifyTake/89:
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
  Node: pvTaskIncrementMutexHeldCount/88:
  Node: uxTaskResetEventItemValue/87:
  Node: vTaskList/86:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: prvWriteNameToBuffer/85:
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
  Node: vTaskPriorityDisinheritAfterTimeout/84:
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
  Node: xTaskPriorityDisinherit/83:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xTaskPriorityInherit/82:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xTaskGetSchedulerState/81:
  Node: xTaskGetCurrentTaskHandle/80:
  Node: prvResetNextTaskUnblockTime/79:
  Node: prvDeleteTCB/78:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: uxTaskGetStackHighWaterMark/77:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: prvTaskCheckFreeStackSpace/76:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: prvListTasksWithinSingleList/75:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               &xTasksWaitingTermination [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
               &xSuspendedTaskList [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 1 [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
               2 [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
               4 [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
               3 [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x3, mask = 0x7
         eTaskState [1, 4]
        AGGS VARIABLE
  Node: vTaskGetInfo/74:
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
  Node: prvCheckTasksWaitingTermination/73:
  Node: prvInitialiseTaskLists/72:
  Node: pvTaskGetThreadLocalStoragePointer/71:
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
  Node: vTaskSetThreadLocalStoragePointer/70:
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
  Node: prvIdleTask/69:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vTaskSetTaskNumber/68:
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
  Node: uxTaskGetTaskNumber/67:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vTaskMissedYield/66:
  Node: xTaskCheckForTimeOut/65:
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
  Node: vTaskInternalSetTimeOutState/64:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vTaskSetTimeOutState/63:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vTaskRemoveFromUnorderedEventList/62:
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
  Node: xTaskRemoveFromEventList/61:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vTaskPlaceOnEventListRestricted/60:
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
  Node: vTaskPlaceOnUnorderedEventList/59:
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
  Node: vTaskPlaceOnEventList/58:
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
  Node: vTaskSwitchContext/57:
  Node: xTaskIncrementTick/56:
  Node: xTaskAbortDelay/55:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xTaskCatchUpTicks/54:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: uxTaskGetSystemState/53:
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
  Node: xTaskGetHandle/52:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: prvSearchForNameWithinSingleList/51:
    param [0]: VARIABLE
               &xSuspendedTaskList [loc_time: 1, loc_size: 38, prop_time: 0, prop_size: 0]
               &xTasksWaitingTermination [loc_time: 1, loc_size: 38, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pcTaskGetName/50:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: uxTaskGetNumberOfTasks/49:
  Node: xTaskGetTickCountFromISR/48:
  Node: xTaskGetTickCount/47:
  Node: xTaskResumeAll/46:
  Node: vTaskSuspendAll/45:
  Node: vTaskEndScheduler/44:
  Node: vTaskStartScheduler/43:
  Node: xTaskResumeFromISR/42:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vTaskResume/41:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: prvTaskIsTaskSuspended/40:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: vTaskSuspend/39:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vTaskPrioritySet/38:
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
  Node: uxTaskPriorityGetFromISR/37:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: uxTaskPriorityGet/36:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: eTaskGetState/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vTaskDelay/34:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xTaskDelayUntil/33:
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
  Node: vTaskDelete/32:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: prvAddNewTaskToReadyList/31:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: xTaskCreate/29:
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
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:

Propagated bits info for function prvListTasksWithinSingleList.part.0/161:
 param 2: value = 0x3, mask = 0x7
Propagated bits info for function prvInitialiseNewTask.isra.0/120:
 param 2: value = 0x0, mask = 0xffff
Propagated bits info for function prvListTasksWithinSingleList/75:
 param 2: value = 0x3, mask = 0x7

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

CSWTCH.230/166 (CSWTCH.230) @07349dc8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: vTaskList/86 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
prvListTasksWithinSingleList.part.0/161 (prvListTasksWithinSingleList.part.0) @072c8d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: prvListTasksWithinSingleList/75 (118111600 (estimated locally),0.50 per call) 
  Calls: vTaskGetInfo/74 (1073741824 (estimated locally),9.09 per call) 
vTaskSwitchContext.part.0/148 (vTaskSwitchContext.part.0) @0716bb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:107374 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: vTaskSwitchContext/57 (107374 (estimated locally),0.24 per call) 
  Calls: 
xTaskResumeAll.part.0/139 (xTaskResumeAll.part.0) @072ad8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: uxSchedulerSuspended/28 (read)uxSchedulerSuspended/28 (write)uxSchedulerSuspended/28 (read)uxCurrentNumberOfTasks/17 (read)xPendingReadyList/13 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)pxCurrentTCB/7 (read)xYieldPending/22 (write)xPendingReadyList/13 (read)xPendedTicks/21 (read)xYieldPending/22 (write)xPendedTicks/21 (write)xYieldPending/22 (read)
  Referring: 
  Availability: local
  Function flags: count:472446400 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: xTaskResumeAll/46 (52886 (estimated locally),0.33 per call) 
  Calls: vPortEnterCritical/102 (472446400 (estimated locally),1.00 per call) prvResetNextTaskUnblockTime/79 (63154273 (estimated locally),0.13 per call) xTaskIncrementTick/56 (536870915 (estimated locally),1.14 per call) vPortExitCritical/103 (472446401 (estimated locally),1.00 per call) 
xTaskIncrementTick.part.0/137 (xTaskIncrementTick.part.0) @072ad700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: xTickCount/18 (read)xTickCount/18 (write)pxDelayedTaskList/11 (read)pxDelayedTaskList/11 (read)pxOverflowDelayedTaskList/12 (read)pxDelayedTaskList/11 (write)pxOverflowDelayedTaskList/12 (write)xNumOfOverflows/23 (read)xNumOfOverflows/23 (write)xNextTaskUnblockTime/25 (read)pxDelayedTaskList/11 (read)xNextTaskUnblockTime/25 (write)pxDelayedTaskList/11 (read)xNextTaskUnblockTime/25 (write)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxReadyTasksLists/8 (read)xYieldPending/22 (read)
  Referring: 
  Availability: local
  Function flags: count:320519 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: xTaskIncrementTick/56 (320520 (estimated locally),0.50 per call) 
  Calls: prvResetNextTaskUnblockTime/79 (52886 (estimated locally),0.17 per call) 
eTaskGetState.part.0/124 (eTaskGetState.part.0) @072ad7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:566398813 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: eTaskGetState/35 (11759 (estimated locally),0.03 per call) 
  Calls: 
prvAddCurrentTaskToDelayedList.part.0/121 (prvAddCurrentTaskToDelayedList.part.0) @06ec1a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: xSuspendedTaskList/16 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)xSuspendedTaskList/16 (addr)xSuspendedTaskList/16 (read)xSuspendedTaskList/16 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: prvAddCurrentTaskToDelayedList/96 (182536110 (estimated locally),0.17 per call) 
  Calls: 
prvInitialiseNewTask.isra.0/120 (prvInitialiseNewTask.isra.0) @06ec17e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:160260 (estimated locally) body local optimize_size
  Called by: xTaskCreate/29 (306987179 (estimated locally),0.29 per call) 
  Calls: pxPortInitialiseStack/101 (52886 (estimated locally),0.33 per call) memset/99 (52886 (estimated locally),0.33 per call) memset/99 (52886 (estimated locally),0.33 per call) memset/99 (52886 (estimated locally),0.33 per call) vListInitialiseItem/100 (52886 (estimated locally),0.33 per call) vListInitialiseItem/100 (52886 (estimated locally),0.33 per call) memset/99 (160260 (estimated locally),1.00 per call) 
prvResetNextTaskUnblockTime.part.0/117 (prvResetNextTaskUnblockTime.part.0) @06ec1380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: pxDelayedTaskList/11 (read)xNextTaskUnblockTime/25 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: prvResetNextTaskUnblockTime/79 (536870912 (estimated locally),0.50 per call) 
  Calls: 
prvTaskIsTaskSuspended.part.0/116 (prvTaskIsTaskSuspended.part.0) @06de3380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: xPendingReadyList/13 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: prvTaskIsTaskSuspended/40 (75162 (estimated locally),0.21 per call) 
  Calls: 
strcpy/114 (strcpy) @070f8000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prvWriteNameToBuffer/85 (118111600 (estimated locally),1.00 per call) 
  Calls: 
sprintf/113 (sprintf) @070dcee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskList/86 (955630226 (estimated locally),4.33 per call) 
  Calls: 
strlen/112 (strlen) @0707a7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskList/86 (955630226 (estimated locally),4.33 per call) xTaskGetHandle/52 (160260 (estimated locally),1.00 per call) prvWriteNameToBuffer/85 (118111600 (estimated locally),1.00 per call) 
  Calls: 
vPortEndScheduler/111 (vPortEndScheduler) @07065000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskEndScheduler/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
xPortStartScheduler/110 (xPortStartScheduler) @07065a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskStartScheduler/43 (80139 (estimated locally),0.20 per call) 
  Calls: 
xTimerCreateTimerTask/109 (xTimerCreateTimerTask) @070659a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskStartScheduler/43 (80139 (estimated locally),0.20 per call) 
  Calls: 
vPortValidateInterruptPriority/108 (vPortValidateInterruptPriority) @06a0da80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskGenericNotifyGiveFromISR/93 (52886 (estimated locally),0.23 per call) xTaskGenericNotifyFromISR/92 (52886 (estimated locally),0.23 per call) xTaskGetTickCountFromISR/48 (1073741824 (estimated locally),1.00 per call) xTaskResumeFromISR/42 (123389 (estimated locally),0.53 per call) uxTaskPriorityGetFromISR/37 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
vListInsert/107 (vListInsert) @06a0d460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskPlaceOnEventList/58 (123389 (estimated locally),0.53 per call) prvAddCurrentTaskToDelayedList/96 (445602856 (estimated locally),0.41 per call) prvAddCurrentTaskToDelayedList/96 (445602856 (estimated locally),0.41 per call) 
  Calls: 
vListInsertEnd/106 (vListInsertEnd) @0705a8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskSuspend/39 (1431653 (estimated locally),1.00 per call) xTaskResumeFromISR/42 (20359 (estimated locally),0.09 per call) vTaskDelete/32 (429496 (estimated locally),0.30 per call) 
  Calls: 
uxListRemove/105 (uxListRemove) @0705aee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskPriorityDisinheritAfterTimeout/84 (2940 (estimated locally),0.01 per call) xTaskPriorityDisinherit/83 (5011 (estimated locally),0.02 per call) xTaskPriorityInherit/82 (65503620 (estimated locally),0.06 per call) vTaskSuspend/39 (765505 (estimated locally),0.53 per call) vTaskSuspend/39 (1431653 (estimated locally),1.00 per call) xTaskAbortDelay/55 (13354 (estimated locally),0.06 per call) xTaskAbortDelay/55 (24974 (estimated locally),0.11 per call) xTaskResumeFromISR/42 (41335 (estimated locally),0.18 per call) vTaskResume/41 (44208 (estimated locally),0.12 per call) vTaskPrioritySet/38 (6084 (estimated locally),0.04 per call) vTaskDelete/32 (765505 (estimated locally),0.53 per call) vTaskDelete/32 (1431653 (estimated locally),1.00 per call) prvAddCurrentTaskToDelayedList/96 (1073741823 (estimated locally),1.00 per call) prvCheckTasksWaitingTermination/73 (955630223 (estimated locally),8.09 per call) 
  Calls: 
vListInitialise/104 (vListInitialise) @0705ab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prvInitialiseTaskLists/72 (97603132 (estimated locally),1.00 per call) prvInitialiseTaskLists/72 (97603132 (estimated locally),1.00 per call) prvInitialiseTaskLists/72 (97603132 (estimated locally),1.00 per call) prvInitialiseTaskLists/72 (97603132 (estimated locally),1.00 per call) prvInitialiseTaskLists/72 (97603132 (estimated locally),1.00 per call) prvInitialiseTaskLists/72 (976138694 (estimated locally),10.00 per call) 
  Calls: 
vPortExitCritical/103 (vPortExitCritical) @0705a9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ulTaskGenericNotifyValueClear/95 (1073741824 (estimated locally),1.00 per call) xTaskGenericNotifyStateClear/94 (107374 (estimated locally),0.50 per call) xTaskGenericNotify/91 (33803 (estimated locally),0.16 per call) xTaskGenericNotifyWait/90 (52886 (estimated locally),0.33 per call) xTaskGenericNotifyWait/90 (52886 (estimated locally),0.33 per call) ulTaskGenericNotifyTake/89 (52886 (estimated locally),0.33 per call) ulTaskGenericNotifyTake/89 (52886 (estimated locally),0.33 per call) xTaskCheckForTimeOut/65 (123389 (estimated locally),0.37 per call) vTaskSetTimeOutState/63 (123389 (estimated locally),0.53 per call) vTaskSuspend/39 (472446 (estimated locally),0.33 per call) vTaskSuspend/39 (1431653 (estimated locally),1.00 per call) xTaskAbortDelay/55 (24974 (estimated locally),0.11 per call) xTaskResumeAll.part.0/139 (472446401 (estimated locally),1.00 per call) vTaskResume/41 (133963 (estimated locally),0.37 per call) vTaskPrioritySet/38 (52886 (estimated locally),0.33 per call) uxTaskPriorityGet/36 (1073741824 (estimated locally),1.00 per call) eTaskGetState/35 (133963 (estimated locally),0.37 per call) vTaskDelete/32 (1431653 (estimated locally),1.00 per call) prvCheckTasksWaitingTermination/73 (955630223 (estimated locally),8.09 per call) prvAddNewTaskToReadyList/31 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
vPortEnterCritical/102 (vPortEnterCritical) @0705a7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ulTaskGenericNotifyValueClear/95 (1073741824 (estimated locally),1.00 per call) xTaskGenericNotifyStateClear/94 (107374 (estimated locally),0.50 per call) xTaskGenericNotify/91 (57413 (estimated locally),0.27 per call) xTaskGenericNotifyWait/90 (52886 (estimated locally),0.33 per call) xTaskGenericNotifyWait/90 (52886 (estimated locally),0.33 per call) ulTaskGenericNotifyTake/89 (52886 (estimated locally),0.33 per call) ulTaskGenericNotifyTake/89 (52886 (estimated locally),0.33 per call) xTaskCheckForTimeOut/65 (123389 (estimated locally),0.37 per call) vTaskSetTimeOutState/63 (123389 (estimated locally),0.53 per call) vTaskSuspend/39 (472446 (estimated locally),0.33 per call) vTaskSuspend/39 (1431653 (estimated locally),1.00 per call) xTaskAbortDelay/55 (24974 (estimated locally),0.11 per call) xTaskResumeAll.part.0/139 (472446400 (estimated locally),1.00 per call) vTaskResume/41 (133963 (estimated locally),0.37 per call) vTaskPrioritySet/38 (52886 (estimated locally),0.33 per call) uxTaskPriorityGet/36 (1073741824 (estimated locally),1.00 per call) eTaskGetState/35 (133963 (estimated locally),0.37 per call) vTaskDelete/32 (1431653 (estimated locally),1.00 per call) prvCheckTasksWaitingTermination/73 (955630223 (estimated locally),8.09 per call) prvAddNewTaskToReadyList/31 (1073741821 (estimated locally),1.00 per call) 
  Calls: 
pxPortInitialiseStack/101 (pxPortInitialiseStack) @0705a460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prvInitialiseNewTask.isra.0/120 (52886 (estimated locally),0.33 per call) 
  Calls: 
vListInitialiseItem/100 (vListInitialiseItem) @0705a380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prvInitialiseNewTask.isra.0/120 (52886 (estimated locally),0.33 per call) prvInitialiseNewTask.isra.0/120 (52886 (estimated locally),0.33 per call) 
  Calls: 
memset/99 (memset) @0705a2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prvInitialiseNewTask.isra.0/120 (52886 (estimated locally),0.33 per call) prvInitialiseNewTask.isra.0/120 (52886 (estimated locally),0.33 per call) prvInitialiseNewTask.isra.0/120 (52886 (estimated locally),0.33 per call) prvInitialiseNewTask.isra.0/120 (160260 (estimated locally),1.00 per call) 
  Calls: 
vPortFree/98 (vPortFree) @0705a0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskList/86 (118111601 (estimated locally),0.53 per call) xTaskCreate/29 (100070816 (estimated locally),0.09 per call) prvDeleteTCB/78 (1073741824 (estimated locally),1.00 per call) prvDeleteTCB/78 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pvPortMalloc/97 (pvPortMalloc) @0705a000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vTaskList/86 (220893212 (estimated locally),1.00 per call) xTaskCreate/29 (574129754 (estimated locally),0.53 per call) xTaskCreate/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
prvAddCurrentTaskToDelayedList/96 (prvAddCurrentTaskToDelayedList) @07029ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: xTickCount/18 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxOverflowDelayedTaskList/12 (read)pxCurrentTCB/7 (read)pxDelayedTaskList/11 (read)pxCurrentTCB/7 (read)xNextTaskUnblockTime/25 (read)xNextTaskUnblockTime/25 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: xTaskGenericNotifyWait/90 (11519 (estimated locally),0.07 per call) ulTaskGenericNotifyTake/89 (8726 (estimated locally),0.05 per call) vTaskPlaceOnEventListRestricted/60 (250539 (estimated locally),0.70 per call) vTaskPlaceOnUnorderedEventList/59 (52886 (estimated locally),0.23 per call) vTaskPlaceOnEventList/58 (123389 (estimated locally),0.53 per call) vTaskDelay/34 (52886 (estimated locally),0.17 per call) xTaskDelayUntil/33 (17717 (estimated locally),0.06 per call) 
  Calls: vListInsert/107 (445602856 (estimated locally),0.41 per call) vListInsert/107 (445602856 (estimated locally),0.41 per call) prvAddCurrentTaskToDelayedList.part.0/121 (182536110 (estimated locally),0.17 per call) uxListRemove/105 (1073741823 (estimated locally),1.00 per call) 
ulTaskGenericNotifyValueClear/95 (ulTaskGenericNotifyValueClear) @07029b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (1073741824 (estimated locally),1.00 per call) vPortEnterCritical/102 (1073741824 (estimated locally),1.00 per call) 
xTaskGenericNotifyStateClear/94 (xTaskGenericNotifyStateClear) @070297e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (107374 (estimated locally),0.50 per call) vPortEnterCritical/102 (107374 (estimated locally),0.50 per call) 
vTaskGenericNotifyGiveFromISR/93 (vTaskGenericNotifyGiveFromISR) @07029380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)xPendingReadyList/13 (read)xPendingReadyList/13 (addr)xPendingReadyList/13 (read)xPendingReadyList/13 (write)pxCurrentTCB/7 (read)xYieldPending/22 (write)
  Referring: 
  Availability: available
  Function flags: count:228942 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortValidateInterruptPriority/108 (52886 (estimated locally),0.23 per call) 
xTaskGenericNotifyFromISR/92 (xTaskGenericNotifyFromISR) @07012d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xTickCount/18 (read)uxSchedulerSuspended/28 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)xPendingReadyList/13 (read)xPendingReadyList/13 (addr)xPendingReadyList/13 (read)xPendingReadyList/13 (write)pxCurrentTCB/7 (read)xYieldPending/22 (write)
  Referring: 
  Availability: available
  Function flags: count:228942 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortValidateInterruptPriority/108 (52886 (estimated locally),0.23 per call) 
xTaskGenericNotify/91 (xTaskGenericNotify) @07012c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xTickCount/18 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (33803 (estimated locally),0.16 per call) vPortEnterCritical/102 (57413 (estimated locally),0.27 per call) 
xTaskGenericNotifyWait/90 (xTaskGenericNotifyWait) @07012620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:160260 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (52886 (estimated locally),0.33 per call) vPortEnterCritical/102 (52886 (estimated locally),0.33 per call) vPortExitCritical/103 (52886 (estimated locally),0.33 per call) prvAddCurrentTaskToDelayedList/96 (11519 (estimated locally),0.07 per call) vPortEnterCritical/102 (52886 (estimated locally),0.33 per call) 
ulTaskGenericNotifyTake/89 (ulTaskGenericNotifyTake) @070121c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:160260 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (52886 (estimated locally),0.33 per call) vPortEnterCritical/102 (52886 (estimated locally),0.33 per call) vPortExitCritical/103 (52886 (estimated locally),0.33 per call) prvAddCurrentTaskToDelayedList/96 (8726 (estimated locally),0.05 per call) vPortEnterCritical/102 (52886 (estimated locally),0.33 per call) 
pvTaskIncrementMutexHeldCount/88 (pvTaskIncrementMutexHeldCount) @07004c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
uxTaskResetEventItemValue/87 (uxTaskResetEventItemValue) @07004540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vTaskList/86 (vTaskList) @07004e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxCurrentNumberOfTasks/17 (read)uxCurrentNumberOfTasks/17 (read)CSWTCH.230/166 (read)
  Referring: 
  Availability: available
  Function flags: count:220893212 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortFree/98 (118111601 (estimated locally),0.53 per call) strlen/112 (955630226 (estimated locally),4.33 per call) sprintf/113 (955630226 (estimated locally),4.33 per call) prvWriteNameToBuffer/85 (955630226 (estimated locally),4.33 per call) uxTaskGetSystemState/53 (118111600 (estimated locally),0.53 per call) pvPortMalloc/97 (220893212 (estimated locally),1.00 per call) 
prvWriteNameToBuffer/85 (prvWriteNameToBuffer) @07004b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: vTaskList/86 (955630226 (estimated locally),4.33 per call) 
  Calls: strlen/112 (118111600 (estimated locally),1.00 per call) strcpy/114 (118111600 (estimated locally),1.00 per call) 
vTaskPriorityDisinheritAfterTimeout/84 (vTaskPriorityDisinheritAfterTimeout) @070048c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxReadyTasksLists/8 (addr)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)
  Referring: 
  Availability: available
  Function flags: count:306783 (estimated locally) body optimize_size
  Called by: 
  Calls: uxListRemove/105 (2940 (estimated locally),0.01 per call) 
xTaskPriorityDisinherit/83 (xTaskPriorityDisinherit) @07004460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)
  Referring: 
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: uxListRemove/105 (5011 (estimated locally),0.02 per call) 
xTaskPriorityInherit/82 (xTaskPriorityInherit) @07004000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxReadyTasksLists/8 (addr)pxCurrentTCB/7 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: uxListRemove/105 (65503620 (estimated locally),0.06 per call) 
xTaskGetSchedulerState/81 (xTaskGetSchedulerState) @06fee9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xSchedulerRunning/20 (read)uxSchedulerSuspended/28 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xTaskGetCurrentTaskHandle/80 (xTaskGetCurrentTaskHandle) @06fee380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
prvResetNextTaskUnblockTime/79 (prvResetNextTaskUnblockTime) @06feeee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pxDelayedTaskList/11 (read)xNextTaskUnblockTime/25 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: vTaskSuspend/39 (472446 (estimated locally),0.33 per call) xTaskResumeAll.part.0/139 (63154273 (estimated locally),0.13 per call) xTaskIncrementTick.part.0/137 (52886 (estimated locally),0.17 per call) vTaskDelete/32 (1002157 (estimated locally),0.70 per call) 
  Calls: prvResetNextTaskUnblockTime.part.0/117 (536870912 (estimated locally),0.50 per call) 
prvDeleteTCB/78 (prvDeleteTCB) @06feeb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: vTaskDelete/32 (765505 (estimated locally),0.53 per call) prvCheckTasksWaitingTermination/73 (955630223 (estimated locally),8.09 per call) 
  Calls: vPortFree/98 (1073741824 (estimated locally),1.00 per call) vPortFree/98 (1073741824 (estimated locally),1.00 per call) 
uxTaskGetStackHighWaterMark/77 (uxTaskGetStackHighWaterMark) @06fee8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: prvTaskCheckFreeStackSpace/76 (1073741824 (estimated locally),1.00 per call) 
prvTaskCheckFreeStackSpace/76 (prvTaskCheckFreeStackSpace) @06fee540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: uxTaskGetStackHighWaterMark/77 (1073741824 (estimated locally),1.00 per call) vTaskGetInfo/74 (354334802 (estimated locally),0.33 per call) 
  Calls: 
prvListTasksWithinSingleList/75 (prvListTasksWithinSingleList) @06fee2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:236223200 (estimated locally) body local optimize_size
  Called by: uxTaskGetSystemState/53 (107374182 (estimated locally),0.50 per call) uxTaskGetSystemState/53 (107374182 (estimated locally),0.50 per call) uxTaskGetSystemState/53 (107374182 (estimated locally),0.50 per call) uxTaskGetSystemState/53 (107374182 (estimated locally),0.50 per call) uxTaskGetSystemState/53 (1073741824 (estimated locally),5.00 per call) 
  Calls: prvListTasksWithinSingleList.part.0/161 (118111600 (estimated locally),0.50 per call) 
vTaskGetInfo/74 (vTaskGetInfo) @06fee000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: prvListTasksWithinSingleList.part.0/161 (1073741824 (estimated locally),9.09 per call) 
  Calls: prvTaskCheckFreeStackSpace/76 (354334802 (estimated locally),0.33 per call) eTaskGetState/35 (217325345 (estimated locally),0.20 per call) xTaskResumeAll/46 (121337087 (estimated locally),0.11 per call) vTaskSuspendAll/45 (121337087 (estimated locally),0.11 per call) 
prvCheckTasksWaitingTermination/73 (prvCheckTasksWaitingTermination) @06fe68c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: xTasksWaitingTermination/14 (read)uxCurrentNumberOfTasks/17 (read)uxCurrentNumberOfTasks/17 (write)uxDeletedTasksWaitingCleanUp/15 (read)uxDeletedTasksWaitingCleanUp/15 (write)uxDeletedTasksWaitingCleanUp/15 (read)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: prvIdleTask/69 (1073741824 (estimated locally),16949.09 per call) 
  Calls: prvDeleteTCB/78 (955630223 (estimated locally),8.09 per call) vPortExitCritical/103 (955630223 (estimated locally),8.09 per call) uxListRemove/105 (955630223 (estimated locally),8.09 per call) vPortEnterCritical/102 (955630223 (estimated locally),8.09 per call) 
prvInitialiseTaskLists/72 (prvInitialiseTaskLists) @06fe6e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pxReadyTasksLists/8 (addr)xDelayedTaskList1/9 (addr)xDelayedTaskList2/10 (addr)xPendingReadyList/13 (addr)xTasksWaitingTermination/14 (addr)xSuspendedTaskList/16 (addr)pxDelayedTaskList/11 (write)xDelayedTaskList1/9 (addr)pxOverflowDelayedTaskList/12 (write)xDelayedTaskList2/10 (addr)
  Referring: 
  Availability: local
  Function flags: count:97603132 (estimated locally) body local optimize_size
  Called by: prvAddNewTaskToReadyList/31 (65197603 (estimated locally),0.06 per call) 
  Calls: vListInitialise/104 (97603132 (estimated locally),1.00 per call) vListInitialise/104 (97603132 (estimated locally),1.00 per call) vListInitialise/104 (97603132 (estimated locally),1.00 per call) vListInitialise/104 (97603132 (estimated locally),1.00 per call) vListInitialise/104 (97603132 (estimated locally),1.00 per call) vListInitialise/104 (976138694 (estimated locally),10.00 per call) 
pvTaskGetThreadLocalStoragePointer/71 (pvTaskGetThreadLocalStoragePointer) @06fe6b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vTaskSetThreadLocalStoragePointer/70 (vTaskSetThreadLocalStoragePointer) @06fe67e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:872959 (estimated locally) body optimize_size
  Called by: 
  Calls: 
prvIdleTask/69 (prvIdleTask) @06fe6460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: pxReadyTasksLists/8 (read)
  Referring: vTaskStartScheduler/43 (addr)
  Availability: available
  Function flags: count:63351 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: prvCheckTasksWaitingTermination/73 (1073741824 (estimated locally),16949.09 per call) 
vTaskSetTaskNumber/68 (vTaskSetTaskNumber) @06fe6000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
uxTaskGetTaskNumber/67 (uxTaskGetTaskNumber) @06fc9a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vTaskMissedYield/66 (vTaskMissedYield) @06fc9460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xYieldPending/22 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xTaskCheckForTimeOut/65 (xTaskCheckForTimeOut) @06fc9e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xTickCount/18 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)xNumOfOverflows/23 (read)
  Referring: 
  Availability: available
  Function flags: count:329661 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (123389 (estimated locally),0.37 per call) vTaskInternalSetTimeOutState/64 (9003 (estimated locally),0.03 per call) vPortEnterCritical/102 (123389 (estimated locally),0.37 per call) 
vTaskInternalSetTimeOutState/64 (vTaskInternalSetTimeOutState) @06fc99a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xNumOfOverflows/23 (read)xTickCount/18 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: xTaskCheckForTimeOut/65 (9003 (estimated locally),0.03 per call) 
  Calls: 
vTaskSetTimeOutState/63 (vTaskSetTimeOutState) @06fc9700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xNumOfOverflows/23 (read)xTickCount/18 (read)
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (123389 (estimated locally),0.53 per call) vPortEnterCritical/102 (123389 (estimated locally),0.53 per call) 
vTaskRemoveFromUnorderedEventList/62 (vTaskRemoveFromUnorderedEventList) @06fc9380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)pxCurrentTCB/7 (read)xYieldPending/22 (write)
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xTaskRemoveFromEventList/61 (xTaskRemoveFromEventList) @06f87ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)xPendingReadyList/13 (read)xPendingReadyList/13 (addr)xPendingReadyList/13 (read)xPendingReadyList/13 (write)pxCurrentTCB/7 (read)xYieldPending/22 (write)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vTaskPlaceOnEventListRestricted/60 (vTaskPlaceOnEventListRestricted) @06f87e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: prvAddCurrentTaskToDelayedList/96 (250539 (estimated locally),0.70 per call) 
vTaskPlaceOnUnorderedEventList/59 (vTaskPlaceOnUnorderedEventList) @06f87a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:228942 (estimated locally) body optimize_size
  Called by: 
  Calls: prvAddCurrentTaskToDelayedList/96 (52886 (estimated locally),0.23 per call) 
vTaskPlaceOnEventList/58 (vTaskPlaceOnEventList) @06f87540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: prvAddCurrentTaskToDelayedList/96 (123389 (estimated locally),0.53 per call) vListInsert/107 (123389 (estimated locally),0.53 per call) 
vTaskSwitchContext/57 (vTaskSwitchContext) @06f871c0
  Type: function definition analyzed
  Visibility: force_output externally_visible public
  References: uxSchedulerSuspended/28 (read)xYieldPending/22 (write)xYieldPending/22 (write)uxTopReadyPriority/19 (read)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (write)pxReadyTasksLists/8 (read)pxCurrentTCB/7 (write)uxTopReadyPriority/19 (write)
  Referring: 
  Availability: available
  Function flags: count:441995 (estimated locally) body optimize_size
  Called by: vTaskSuspend/39 (104969 (estimated locally),0.07 per call) 
  Calls: vTaskSwitchContext.part.0/148 (107374 (estimated locally),0.24 per call) 
xTaskIncrementTick/56 (xTaskIncrementTick) @06f239a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)xPendedTicks/21 (read)xPendedTicks/21 (write)
  Referring: 
  Availability: available
  Function flags: count:641039 (estimated locally) body optimize_size
  Called by: xTaskResumeAll.part.0/139 (536870915 (estimated locally),1.14 per call) 
  Calls: xTaskIncrementTick.part.0/137 (320520 (estimated locally),0.50 per call) 
xTaskAbortDelay/55 (xTaskAbortDelay) @06f23c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)pxCurrentTCB/7 (read)xYieldPending/22 (write)
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskResumeAll/46 (123389 (estimated locally),0.53 per call) vPortExitCritical/103 (24974 (estimated locally),0.11 per call) uxListRemove/105 (13354 (estimated locally),0.06 per call) vPortEnterCritical/102 (24974 (estimated locally),0.11 per call) uxListRemove/105 (24974 (estimated locally),0.11 per call) eTaskGetState/35 (123389 (estimated locally),0.53 per call) vTaskSuspendAll/45 (123389 (estimated locally),0.53 per call) 
xTaskCatchUpTicks/54 (xTaskCatchUpTicks) @06f238c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)xPendedTicks/21 (read)xPendedTicks/21 (write)
  Referring: 
  Availability: available
  Function flags: count:160260 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskResumeAll/46 (52886 (estimated locally),0.33 per call) vTaskSuspendAll/45 (52886 (estimated locally),0.33 per call) 
uxTaskGetSystemState/53 (uxTaskGetSystemState) @06f23540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxCurrentNumberOfTasks/17 (read)pxReadyTasksLists/8 (addr)pxDelayedTaskList/11 (read)pxOverflowDelayedTaskList/12 (read)xTasksWaitingTermination/14 (addr)xSuspendedTaskList/16 (addr)
  Referring: 
  Availability: available
  Function flags: count:214748364 (estimated locally) body optimize_size
  Called by: vTaskList/86 (118111600 (estimated locally),0.53 per call) 
  Calls: xTaskResumeAll/46 (214748364 (estimated locally),1.00 per call) prvListTasksWithinSingleList/75 (107374182 (estimated locally),0.50 per call) prvListTasksWithinSingleList/75 (107374182 (estimated locally),0.50 per call) prvListTasksWithinSingleList/75 (107374182 (estimated locally),0.50 per call) prvListTasksWithinSingleList/75 (107374182 (estimated locally),0.50 per call) prvListTasksWithinSingleList/75 (1073741824 (estimated locally),5.00 per call) vTaskSuspendAll/45 (214748364 (estimated locally),1.00 per call) 
xTaskGetHandle/52 (xTaskGetHandle) @06f232a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxReadyTasksLists/8 (addr)pxDelayedTaskList/11 (read)pxOverflowDelayedTaskList/12 (read)xSuspendedTaskList/16 (addr)xTasksWaitingTermination/14 (addr)
  Referring: 
  Availability: available
  Function flags: count:160260 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskResumeAll/46 (52886 (estimated locally),0.33 per call) prvSearchForNameWithinSingleList/51 (9218 (estimated locally),0.06 per call) prvSearchForNameWithinSingleList/51 (9218 (estimated locally),0.06 per call) prvSearchForNameWithinSingleList/51 (9218 (estimated locally),0.06 per call) prvSearchForNameWithinSingleList/51 (9218 (estimated locally),0.06 per call) prvSearchForNameWithinSingleList/51 (353751 (estimated locally),2.21 per call) vTaskSuspendAll/45 (52886 (estimated locally),0.33 per call) strlen/112 (160260 (estimated locally),1.00 per call) 
prvSearchForNameWithinSingleList/51 (prvSearchForNameWithinSingleList) @06f23000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:25274560 (estimated locally) body local optimize_size
  Called by: xTaskGetHandle/52 (9218 (estimated locally),0.06 per call) xTaskGetHandle/52 (9218 (estimated locally),0.06 per call) xTaskGetHandle/52 (9218 (estimated locally),0.06 per call) xTaskGetHandle/52 (9218 (estimated locally),0.06 per call) xTaskGetHandle/52 (353751 (estimated locally),2.21 per call) 
  Calls: 
pcTaskGetName/50 (pcTaskGetName) @06f14c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
uxTaskGetNumberOfTasks/49 (uxTaskGetNumberOfTasks) @06f14e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxCurrentNumberOfTasks/17 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xTaskGetTickCountFromISR/48 (xTaskGetTickCountFromISR) @06f14b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xTickCount/18 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortValidateInterruptPriority/108 (1073741824 (estimated locally),1.00 per call) 
xTaskGetTickCount/47 (xTaskGetTickCount) @06f148c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xTickCount/18 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xTaskResumeAll/46 (xTaskResumeAll) @06f14620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)
  Referring: 
  Availability: available
  Function flags: count:160260 (estimated locally) body optimize_size
  Called by: uxTaskGetSystemState/53 (214748364 (estimated locally),1.00 per call) vTaskGetInfo/74 (121337087 (estimated locally),0.11 per call) xTaskAbortDelay/55 (123389 (estimated locally),0.53 per call) xTaskCatchUpTicks/54 (52886 (estimated locally),0.33 per call) xTaskGetHandle/52 (52886 (estimated locally),0.33 per call) vTaskDelay/34 (52886 (estimated locally),0.17 per call) xTaskDelayUntil/33 (35433 (estimated locally),0.12 per call) 
  Calls: xTaskResumeAll.part.0/139 (52886 (estimated locally),0.33 per call) 
vTaskSuspendAll/45 (vTaskSuspendAll) @06f14000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)uxSchedulerSuspended/28 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: uxTaskGetSystemState/53 (214748364 (estimated locally),1.00 per call) vTaskGetInfo/74 (121337087 (estimated locally),0.11 per call) xTaskAbortDelay/55 (123389 (estimated locally),0.53 per call) xTaskCatchUpTicks/54 (52886 (estimated locally),0.33 per call) xTaskGetHandle/52 (52886 (estimated locally),0.33 per call) vTaskDelay/34 (52886 (estimated locally),0.17 per call) xTaskDelayUntil/33 (35433 (estimated locally),0.12 per call) 
  Calls: 
vTaskEndScheduler/44 (vTaskEndScheduler) @06f05a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: xSchedulerRunning/20 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortEndScheduler/111 (1073741824 (estimated locally),1.00 per call) 
vTaskStartScheduler/43 (vTaskStartScheduler) @06f052a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: prvIdleTask/69 (addr)xIdleTaskHandle/26 (addr)xNextTaskUnblockTime/25 (write)xSchedulerRunning/20 (write)xTickCount/18 (write)uxTopUsedPriority/27 (read)
  Referring: 
  Availability: available
  Function flags: count:395945 (estimated locally) body optimize_size
  Called by: 
  Calls: xPortStartScheduler/110 (80139 (estimated locally),0.20 per call) xTimerCreateTimerTask/109 (80139 (estimated locally),0.20 per call) xTaskCreate/29 (395945 (estimated locally),1.00 per call) 
xTaskResumeFromISR/42 (xTaskResumeFromISR) @06f05d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)pxCurrentTCB/7 (read)xYieldPending/22 (write)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)xPendingReadyList/13 (addr)
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: vListInsertEnd/106 (20359 (estimated locally),0.09 per call) uxListRemove/105 (41335 (estimated locally),0.18 per call) prvTaskIsTaskSuspended/40 (123389 (estimated locally),0.53 per call) vPortValidateInterruptPriority/108 (123389 (estimated locally),0.53 per call) 
vTaskResume/41 (vTaskResume) @06f059a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (133963 (estimated locally),0.37 per call) uxListRemove/105 (44208 (estimated locally),0.12 per call) prvTaskIsTaskSuspended/40 (133963 (estimated locally),0.37 per call) vPortEnterCritical/102 (133963 (estimated locally),0.37 per call) 
prvTaskIsTaskSuspended/40 (prvTaskIsTaskSuspended) @06f05540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: xSuspendedTaskList/16 (addr)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: xTaskResumeFromISR/42 (123389 (estimated locally),0.53 per call) vTaskResume/41 (133963 (estimated locally),0.37 per call) 
  Calls: prvTaskIsTaskSuspended.part.0/116 (75162 (estimated locally),0.21 per call) 
vTaskSuspend/39 (vTaskSuspend) @06f051c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)xSuspendedTaskList/16 (addr)xSchedulerRunning/20 (read)pxCurrentTCB/7 (read)xSchedulerRunning/20 (read)uxSchedulerSuspended/28 (read)xSuspendedTaskList/16 (read)uxCurrentNumberOfTasks/17 (read)pxCurrentTCB/7 (write)
  Referring: 
  Availability: available
  Function flags: count:1431653 (estimated locally) body optimize_size
  Called by: 
  Calls: vTaskSwitchContext/57 (104969 (estimated locally),0.07 per call) vPortExitCritical/103 (472446 (estimated locally),0.33 per call) prvResetNextTaskUnblockTime/79 (472446 (estimated locally),0.33 per call) vPortEnterCritical/102 (472446 (estimated locally),0.33 per call) vPortExitCritical/103 (1431653 (estimated locally),1.00 per call) vListInsertEnd/106 (1431653 (estimated locally),1.00 per call) uxListRemove/105 (765505 (estimated locally),0.53 per call) uxListRemove/105 (1431653 (estimated locally),1.00 per call) vPortEnterCritical/102 (1431653 (estimated locally),1.00 per call) 
vTaskPrioritySet/38 (vTaskPrioritySet) @06eea540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (read)pxReadyTasksLists/8 (addr)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)
  Referring: 
  Availability: available
  Function flags: count:160260 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (52886 (estimated locally),0.33 per call) uxListRemove/105 (6084 (estimated locally),0.04 per call) vPortEnterCritical/102 (52886 (estimated locally),0.33 per call) 
uxTaskPriorityGetFromISR/37 (uxTaskPriorityGetFromISR) @06eeab60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortValidateInterruptPriority/108 (1073741824 (estimated locally),1.00 per call) 
uxTaskPriorityGet/36 (uxTaskPriorityGet) @06eea7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/103 (1073741824 (estimated locally),1.00 per call) vPortEnterCritical/102 (1073741824 (estimated locally),1.00 per call) 
eTaskGetState/35 (eTaskGetState) @06eea460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)pxDelayedTaskList/11 (read)pxOverflowDelayedTaskList/12 (read)xSuspendedTaskList/16 (addr)xTasksWaitingTermination/14 (addr)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: vTaskGetInfo/74 (217325345 (estimated locally),0.20 per call) xTaskAbortDelay/55 (123389 (estimated locally),0.53 per call) 
  Calls: eTaskGetState.part.0/124 (11759 (estimated locally),0.03 per call) vPortExitCritical/103 (133963 (estimated locally),0.37 per call) vPortEnterCritical/102 (133963 (estimated locally),0.37 per call) 
vTaskDelay/34 (vTaskDelay) @06eea0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)
  Referring: 
  Availability: available
  Function flags: count:320519 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskResumeAll/46 (52886 (estimated locally),0.17 per call) prvAddCurrentTaskToDelayedList/96 (52886 (estimated locally),0.17 per call) vTaskSuspendAll/45 (52886 (estimated locally),0.17 per call) 
xTaskDelayUntil/33 (xTaskDelayUntil) @06edd1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxSchedulerSuspended/28 (read)xTickCount/18 (read)
  Referring: 
  Availability: available
  Function flags: count:306783 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskResumeAll/46 (35433 (estimated locally),0.12 per call) prvAddCurrentTaskToDelayedList/96 (17717 (estimated locally),0.06 per call) vTaskSuspendAll/45 (35433 (estimated locally),0.12 per call) 
vTaskDelete/32 (vTaskDelete) @06edd9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pxCurrentTCB/7 (read)uxTaskNumber/24 (read)uxTaskNumber/24 (write)pxCurrentTCB/7 (read)xTasksWaitingTermination/14 (addr)uxDeletedTasksWaitingCleanUp/15 (read)uxDeletedTasksWaitingCleanUp/15 (write)uxCurrentNumberOfTasks/17 (read)uxCurrentNumberOfTasks/17 (write)pxCurrentTCB/7 (read)xSchedulerRunning/20 (read)pxCurrentTCB/7 (read)uxSchedulerSuspended/28 (read)
  Referring: 
  Availability: available
  Function flags: count:1431653 (estimated locally) body optimize_size
  Called by: 
  Calls: prvDeleteTCB/78 (765505 (estimated locally),0.53 per call) vPortExitCritical/103 (1431653 (estimated locally),1.00 per call) prvResetNextTaskUnblockTime/79 (1002157 (estimated locally),0.70 per call) vListInsertEnd/106 (429496 (estimated locally),0.30 per call) uxListRemove/105 (765505 (estimated locally),0.53 per call) uxListRemove/105 (1431653 (estimated locally),1.00 per call) vPortEnterCritical/102 (1431653 (estimated locally),1.00 per call) 
prvAddNewTaskToReadyList/31 (prvAddNewTaskToReadyList) @06edd460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: uxCurrentNumberOfTasks/17 (read)uxCurrentNumberOfTasks/17 (write)pxCurrentTCB/7 (read)pxCurrentTCB/7 (write)uxCurrentNumberOfTasks/17 (read)xSchedulerRunning/20 (read)pxCurrentTCB/7 (read)pxCurrentTCB/7 (write)uxTaskNumber/24 (read)uxTaskNumber/24 (write)uxTopReadyPriority/19 (read)uxTopReadyPriority/19 (write)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (addr)pxReadyTasksLists/8 (read)pxReadyTasksLists/8 (write)xSchedulerRunning/20 (read)pxCurrentTCB/7 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741821 (estimated locally) body local optimize_size
  Called by: xTaskCreate/29 (306987179 (estimated locally),0.29 per call) 
  Calls: vPortExitCritical/103 (1073741823 (estimated locally),1.00 per call) prvInitialiseTaskLists/72 (65197603 (estimated locally),0.06 per call) vPortEnterCritical/102 (1073741821 (estimated locally),1.00 per call) 
xTaskCreate/29 (xTaskCreate) @06ed0d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: vTaskStartScheduler/43 (395945 (estimated locally),1.00 per call) 
  Calls: prvAddNewTaskToReadyList/31 (306987179 (estimated locally),0.29 per call) prvInitialiseNewTask.isra.0/120 (306987179 (estimated locally),0.29 per call) vPortFree/98 (100070816 (estimated locally),0.09 per call) pvPortMalloc/97 (574129754 (estimated locally),0.53 per call) pvPortMalloc/97 (1073741824 (estimated locally),1.00 per call) 
uxSchedulerSuspended/28 (uxSchedulerSuspended) @06ecf048
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: xTaskGetSchedulerState/81 (read)xTaskIncrementTick/56 (read)xTaskResumeAll/46 (read)xTaskCatchUpTicks/54 (read)xTaskGenericNotifyFromISR/92 (read)vTaskRemoveFromUnorderedEventList/62 (read)vTaskDelete/32 (read)vTaskPlaceOnUnorderedEventList/59 (read)xTaskRemoveFromEventList/61 (read)vTaskSuspendAll/45 (read)vTaskSuspendAll/45 (write)xTaskDelayUntil/33 (read)xTaskResumeFromISR/42 (read)vTaskDelay/34 (read)vTaskSwitchContext/57 (read)vTaskSuspend/39 (read)xTaskResumeAll.part.0/139 (read)xTaskResumeAll.part.0/139 (read)xTaskResumeAll.part.0/139 (write)vTaskGenericNotifyGiveFromISR/93 (read)
  Availability: available
  Varpool flags: initialized
uxTopUsedPriority/27 (uxTopUsedPriority) @06ec8f78
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: vTaskStartScheduler/43 (read)
  Availability: available
  Varpool flags: initialized read-only
xIdleTaskHandle/26 (xIdleTaskHandle) @06ec8ee8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: vTaskStartScheduler/43 (addr)
  Availability: available
  Varpool flags: initialized
xNextTaskUnblockTime/25 (xNextTaskUnblockTime) @06ec8e58
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: prvResetNextTaskUnblockTime.part.0/117 (write)prvAddCurrentTaskToDelayedList/96 (write)prvAddCurrentTaskToDelayedList/96 (read)vTaskStartScheduler/43 (write)prvResetNextTaskUnblockTime/79 (write)xTaskIncrementTick.part.0/137 (read)xTaskIncrementTick.part.0/137 (write)xTaskIncrementTick.part.0/137 (write)
  Availability: available
  Varpool flags: initialized
uxTaskNumber/24 (uxTaskNumber) @06ec8dc8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: prvAddNewTaskToReadyList/31 (write)prvAddNewTaskToReadyList/31 (read)vTaskDelete/32 (read)vTaskDelete/32 (write)
  Availability: available
  Varpool flags: initialized
xNumOfOverflows/23 (xNumOfOverflows) @06ec8d80
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: xTaskIncrementTick.part.0/137 (write)vTaskSetTimeOutState/63 (read)vTaskInternalSetTimeOutState/64 (read)xTaskIncrementTick.part.0/137 (read)xTaskCheckForTimeOut/65 (read)
  Availability: available
  Varpool flags: initialized
xYieldPending/22 (xYieldPending) @06ec8d38
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: vTaskMissedYield/66 (write)xTaskRemoveFromEventList/61 (write)vTaskRemoveFromUnorderedEventList/62 (write)xTaskResumeFromISR/42 (write)xTaskIncrementTick.part.0/137 (read)xTaskGenericNotifyFromISR/92 (write)xTaskResumeAll.part.0/139 (write)xTaskResumeAll.part.0/139 (read)xTaskAbortDelay/55 (write)vTaskSwitchContext/57 (write)xTaskResumeAll.part.0/139 (write)vTaskSwitchContext/57 (write)vTaskGenericNotifyGiveFromISR/93 (write)
  Availability: available
  Varpool flags: initialized
xPendedTicks/21 (xPendedTicks) @06ec8ca8
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: xTaskResumeAll.part.0/139 (read)xTaskResumeAll.part.0/139 (write)xTaskIncrementTick/56 (read)xTaskIncrementTick/56 (write)xTaskCatchUpTicks/54 (read)xTaskCatchUpTicks/54 (write)
  Availability: available
  Varpool flags: initialized
xSchedulerRunning/20 (xSchedulerRunning) @06ec8c18
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: vTaskDelete/32 (read)vTaskEndScheduler/44 (write)vTaskSuspend/39 (read)prvAddNewTaskToReadyList/31 (read)vTaskStartScheduler/43 (write)prvAddNewTaskToReadyList/31 (read)vTaskSuspend/39 (read)xTaskGetSchedulerState/81 (read)
  Availability: available
  Varpool flags: initialized
uxTopReadyPriority/19 (uxTopReadyPriority) @06ec8b88
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: xTaskGenericNotify/91 (read)xTaskGenericNotify/91 (write)xTaskGenericNotifyFromISR/92 (read)xTaskGenericNotifyFromISR/92 (write)prvAddNewTaskToReadyList/31 (read)prvAddNewTaskToReadyList/31 (write)vTaskPrioritySet/38 (read)vTaskPrioritySet/38 (write)xTaskResumeFromISR/42 (read)xTaskResumeFromISR/42 (write)xTaskIncrementTick.part.0/137 (read)xTaskIncrementTick.part.0/137 (write)vTaskResume/41 (read)vTaskResume/41 (write)xTaskResumeAll.part.0/139 (read)xTaskResumeAll.part.0/139 (write)xTaskAbortDelay/55 (read)xTaskAbortDelay/55 (write)vTaskSwitchContext/57 (read)vTaskSwitchContext/57 (write)xTaskRemoveFromEventList/61 (read)xTaskRemoveFromEventList/61 (write)vTaskRemoveFromUnorderedEventList/62 (read)vTaskRemoveFromUnorderedEventList/62 (write)xTaskPriorityInherit/82 (read)xTaskPriorityInherit/82 (write)xTaskPriorityDisinherit/83 (read)xTaskPriorityDisinherit/83 (write)vTaskPriorityDisinheritAfterTimeout/84 (read)vTaskPriorityDisinheritAfterTimeout/84 (write)vTaskGenericNotifyGiveFromISR/93 (read)vTaskGenericNotifyGiveFromISR/93 (write)
  Availability: available
  Varpool flags: initialized
xTickCount/18 (xTickCount) @06ec8b40
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: xTaskGetTickCountFromISR/48 (read)xTaskCheckForTimeOut/65 (read)xTaskGenericNotify/91 (read)prvAddCurrentTaskToDelayedList/96 (read)vTaskStartScheduler/43 (write)vTaskInternalSetTimeOutState/64 (read)xTaskGetTickCount/47 (read)xTaskIncrementTick.part.0/137 (write)xTaskDelayUntil/33 (read)vTaskSetTimeOutState/63 (read)xTaskIncrementTick.part.0/137 (read)xTaskGenericNotifyFromISR/92 (read)
  Availability: available
  Varpool flags: initialized
uxCurrentNumberOfTasks/17 (uxCurrentNumberOfTasks) @06ec8af8
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: xTaskResumeAll.part.0/139 (read)prvCheckTasksWaitingTermination/73 (read)vTaskSuspend/39 (read)prvAddNewTaskToReadyList/31 (write)prvAddNewTaskToReadyList/31 (read)uxTaskGetNumberOfTasks/49 (read)vTaskDelete/32 (read)uxTaskGetSystemState/53 (read)vTaskDelete/32 (write)prvCheckTasksWaitingTermination/73 (write)prvAddNewTaskToReadyList/31 (read)vTaskList/86 (read)vTaskList/86 (read)
  Availability: available
  Varpool flags: initialized
xSuspendedTaskList/16 (xSuspendedTaskList) @06ec8a20
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: vTaskSuspend/39 (read)eTaskGetState/35 (addr)xTaskGetHandle/52 (addr)prvAddCurrentTaskToDelayedList.part.0/121 (write)prvTaskIsTaskSuspended/40 (addr)prvInitialiseTaskLists/72 (addr)prvAddCurrentTaskToDelayedList.part.0/121 (read)prvAddCurrentTaskToDelayedList.part.0/121 (read)prvAddCurrentTaskToDelayedList.part.0/121 (addr)vTaskSuspend/39 (addr)uxTaskGetSystemState/53 (addr)
  Availability: available
  Varpool flags:
uxDeletedTasksWaitingCleanUp/15 (uxDeletedTasksWaitingCleanUp) @06ec8990
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: prvCheckTasksWaitingTermination/73 (write)prvCheckTasksWaitingTermination/73 (read)prvCheckTasksWaitingTermination/73 (read)vTaskDelete/32 (read)vTaskDelete/32 (write)
  Availability: available
  Varpool flags: initialized
xTasksWaitingTermination/14 (xTasksWaitingTermination) @06ec8900
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: eTaskGetState/35 (addr)prvInitialiseTaskLists/72 (addr)prvCheckTasksWaitingTermination/73 (read)xTaskGetHandle/52 (addr)vTaskDelete/32 (addr)uxTaskGetSystemState/53 (addr)
  Availability: available
  Varpool flags:
xPendingReadyList/13 (xPendingReadyList) @06ec8870
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: xTaskGenericNotifyFromISR/92 (write)xTaskRemoveFromEventList/61 (write)prvTaskIsTaskSuspended.part.0/116 (addr)xTaskRemoveFromEventList/61 (read)prvInitialiseTaskLists/72 (addr)xTaskRemoveFromEventList/61 (read)xTaskRemoveFromEventList/61 (addr)xTaskGenericNotifyFromISR/92 (read)xTaskResumeFromISR/42 (addr)xTaskGenericNotifyFromISR/92 (read)xTaskGenericNotifyFromISR/92 (addr)xTaskResumeAll.part.0/139 (read)xTaskResumeAll.part.0/139 (read)vTaskGenericNotifyGiveFromISR/93 (read)vTaskGenericNotifyGiveFromISR/93 (addr)vTaskGenericNotifyGiveFromISR/93 (read)vTaskGenericNotifyGiveFromISR/93 (write)
  Availability: available
  Varpool flags:
pxOverflowDelayedTaskList/12 (pxOverflowDelayedTaskList) @06ec87e0
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: prvAddCurrentTaskToDelayedList/96 (read)xTaskGetHandle/52 (read)prvInitialiseTaskLists/72 (write)eTaskGetState/35 (read)xTaskIncrementTick.part.0/137 (write)xTaskIncrementTick.part.0/137 (read)uxTaskGetSystemState/53 (read)
  Availability: available
  Varpool flags:
pxDelayedTaskList/11 (pxDelayedTaskList) @06ec8798
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: xTaskGetHandle/52 (read)prvResetNextTaskUnblockTime.part.0/117 (read)prvAddCurrentTaskToDelayedList/96 (read)prvResetNextTaskUnblockTime/79 (read)prvInitialiseTaskLists/72 (write)eTaskGetState/35 (read)xTaskIncrementTick.part.0/137 (read)xTaskIncrementTick.part.0/137 (read)xTaskIncrementTick.part.0/137 (read)xTaskIncrementTick.part.0/137 (write)xTaskIncrementTick.part.0/137 (read)uxTaskGetSystemState/53 (read)
  Availability: available
  Varpool flags:
xDelayedTaskList2/10 (xDelayedTaskList2) @06ec8750
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: prvInitialiseTaskLists/72 (addr)prvInitialiseTaskLists/72 (addr)
  Availability: available
  Varpool flags:
xDelayedTaskList1/9 (xDelayedTaskList1) @06ec86c0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: prvInitialiseTaskLists/72 (addr)prvInitialiseTaskLists/72 (addr)
  Availability: available
  Varpool flags:
pxReadyTasksLists/8 (pxReadyTasksLists) @06ec8630
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: xTaskGenericNotify/91 (read)xTaskGenericNotify/91 (addr)xTaskGenericNotify/91 (read)xTaskGenericNotifyFromISR/92 (write)xTaskGenericNotify/91 (write)vTaskPriorityDisinheritAfterTimeout/84 (write)xTaskGenericNotifyFromISR/92 (read)xTaskGenericNotifyFromISR/92 (addr)xTaskGenericNotifyFromISR/92 (read)prvAddNewTaskToReadyList/31 (write)prvAddNewTaskToReadyList/31 (read)prvAddNewTaskToReadyList/31 (addr)prvAddNewTaskToReadyList/31 (read)prvIdleTask/69 (read)vTaskPrioritySet/38 (read)vTaskPrioritySet/38 (addr)vTaskPrioritySet/38 (read)vTaskPrioritySet/38 (write)prvInitialiseTaskLists/72 (addr)xTaskResumeFromISR/42 (read)xTaskResumeFromISR/42 (addr)xTaskResumeFromISR/42 (read)xTaskResumeFromISR/42 (write)xTaskIncrementTick.part.0/137 (read)xTaskRemoveFromEventList/61 (write)xTaskIncrementTick.part.0/137 (addr)xTaskIncrementTick.part.0/137 (read)xTaskIncrementTick.part.0/137 (write)xTaskResumeAll.part.0/139 (write)xTaskPriorityInherit/82 (addr)vTaskResume/41 (read)vTaskResume/41 (addr)vTaskResume/41 (read)vTaskResume/41 (write)xTaskResumeAll.part.0/139 (read)xTaskGetHandle/52 (addr)xTaskResumeAll.part.0/139 (read)xTaskResumeAll.part.0/139 (addr)xTaskAbortDelay/55 (read)xTaskAbortDelay/55 (write)vTaskSwitchContext/57 (write)vTaskSwitchContext/57 (addr)vTaskSwitchContext/57 (write)vTaskSwitchContext/57 (read)vTaskPrioritySet/38 (addr)xTaskRemoveFromEventList/61 (read)xTaskRemoveFromEventList/61 (addr)xTaskRemoveFromEventList/61 (read)vTaskRemoveFromUnorderedEventList/62 (write)vTaskRemoveFromUnorderedEventList/62 (read)vTaskRemoveFromUnorderedEventList/62 (addr)vTaskRemoveFromUnorderedEventList/62 (read)uxTaskGetSystemState/53 (addr)vTaskSwitchContext/57 (read)xTaskPriorityInherit/82 (read)xTaskPriorityInherit/82 (addr)xTaskPriorityInherit/82 (read)xTaskPriorityInherit/82 (write)xTaskPriorityDisinherit/83 (read)xTaskPriorityDisinherit/83 (addr)xTaskPriorityDisinherit/83 (read)xTaskPriorityDisinherit/83 (write)vTaskPriorityDisinheritAfterTimeout/84 (read)vTaskPriorityDisinheritAfterTimeout/84 (addr)vTaskPriorityDisinheritAfterTimeout/84 (read)xTaskIncrementTick.part.0/137 (read)xTaskAbortDelay/55 (read)xTaskAbortDelay/55 (addr)vTaskSwitchContext/57 (read)vTaskPriorityDisinheritAfterTimeout/84 (addr)vTaskGenericNotifyGiveFromISR/93 (read)vTaskGenericNotifyGiveFromISR/93 (addr)vTaskGenericNotifyGiveFromISR/93 (read)vTaskGenericNotifyGiveFromISR/93 (write)
  Availability: available
  Varpool flags:
pxCurrentTCB/7 (pxCurrentTCB) @06ec85e8
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: ulTaskGenericNotifyTake/89 (read)xTaskGenericNotifyWait/90 (read)xTaskGenericNotify/91 (read)xTaskGenericNotifyFromISR/92 (read)vTaskGenericNotifyGiveFromISR/93 (read)prvAddNewTaskToReadyList/31 (write)prvAddNewTaskToReadyList/31 (read)prvAddNewTaskToReadyList/31 (write)prvAddNewTaskToReadyList/31 (read)xTaskPriorityInherit/82 (read)xTaskPriorityInherit/82 (read)pvTaskIncrementMutexHeldCount/88 (read)pvTaskIncrementMutexHeldCount/88 (read)pvTaskIncrementMutexHeldCount/88 (read)ulTaskGenericNotifyTake/89 (read)ulTaskGenericNotifyTake/89 (read)ulTaskGenericNotifyTake/89 (read)ulTaskGenericNotifyTake/89 (read)xTaskGenericNotifyStateClear/94 (read)prvAddCurrentTaskToDelayedList/96 (read)vTaskDelete/32 (read)eTaskGetState/35 (read)prvAddCurrentTaskToDelayedList/96 (read)prvAddCurrentTaskToDelayedList/96 (read)prvAddCurrentTaskToDelayedList/96 (read)uxTaskPriorityGet/36 (read)vTaskDelete/32 (read)vTaskResume/41 (read)xTaskAbortDelay/55 (read)vTaskDelete/32 (read)uxTaskPriorityGetFromISR/37 (read)vTaskPrioritySet/38 (read)pcTaskGetName/50 (read)vTaskResume/41 (read)xTaskIncrementTick.part.0/137 (read)vTaskPrioritySet/38 (read)xTaskResumeFromISR/42 (read)xTaskResumeAll.part.0/139 (read)vTaskSwitchContext/57 (write)ulTaskGenericNotifyTake/89 (read)prvAddNewTaskToReadyList/31 (read)vTaskDelete/32 (read)vTaskPrioritySet/38 (read)xTaskIncrementTick.part.0/137 (read)vTaskSuspend/39 (write)prvAddCurrentTaskToDelayedList/96 (read)vTaskPrioritySet/38 (read)vTaskSuspend/39 (read)vTaskSuspend/39 (read)vTaskPlaceOnEventList/58 (read)vTaskPlaceOnUnorderedEventList/59 (read)vTaskPlaceOnEventListRestricted/60 (read)vTaskPlaceOnUnorderedEventList/59 (read)xTaskRemoveFromEventList/61 (read)vTaskRemoveFromUnorderedEventList/62 (read)xTaskCheckForTimeOut/65 (read)vTaskPlaceOnEventListRestricted/60 (read)vTaskSetThreadLocalStoragePointer/70 (read)pvTaskGetThreadLocalStoragePointer/71 (read)vTaskGetInfo/74 (read)vTaskPlaceOnUnorderedEventList/59 (read)vTaskPlaceOnUnorderedEventList/59 (read)vTaskPlaceOnUnorderedEventList/59 (read)xTaskCheckForTimeOut/65 (read)uxTaskGetStackHighWaterMark/77 (read)xTaskGetCurrentTaskHandle/80 (read)xTaskPriorityInherit/82 (read)vTaskPlaceOnEventListRestricted/60 (read)vTaskGetInfo/74 (read)xTaskPriorityDisinherit/83 (read)xTaskPriorityInherit/82 (read)xTaskPriorityInherit/82 (read)vTaskPriorityDisinheritAfterTimeout/84 (read)prvAddCurrentTaskToDelayedList.part.0/121 (read)vTaskPlaceOnEventListRestricted/60 (read)vTaskPlaceOnEventListRestricted/60 (read)uxTaskResetEventItemValue/87 (read)uxTaskResetEventItemValue/87 (read)uxTaskResetEventItemValue/87 (read)prvAddCurrentTaskToDelayedList.part.0/121 (read)vTaskPlaceOnUnorderedEventList/59 (read)prvAddCurrentTaskToDelayedList.part.0/121 (read)prvAddCurrentTaskToDelayedList.part.0/121 (read)prvAddCurrentTaskToDelayedList.part.0/121 (read)xTaskGenericNotifyWait/90 (read)xTaskGenericNotifyWait/90 (read)xTaskGenericNotifyWait/90 (read)xTaskGenericNotifyWait/90 (read)xTaskGenericNotifyWait/90 (read)xTaskGenericNotifyWait/90 (read)ulTaskGenericNotifyValueClear/95 (read)
  Availability: available
  Varpool flags: initialized

;; Function prvSearchForNameWithinSingleList (prvSearchForNameWithinSingleList, funcdef_no=29, decl_uid=6968, cgraph_uid=30, symbol_order=51)

Modification phase of node prvSearchForNameWithinSingleList/51
prvSearchForNameWithinSingleList (struct List_t * pxList, const char * pcNameToQuery)
{
  char cNextChar;
  UBaseType_t x;
  struct TCB_t * pxReturn;
  struct TCB_t * pxFirstTCB;
  struct TCB_t * pxNextTCB;
  long unsigned int _1;
  struct ListItem_t * _2;
  struct xLIST_ITEM * _3;
  struct MiniListItem_t * _4;
  struct xLIST_ITEM * _5;
  struct ListItem_t * _6;
  struct ListItem_t * _7;
  struct xLIST_ITEM * _8;
  struct xLIST_ITEM * _9;
  struct ListItem_t * _10;
  const char * _11;
  char _12;

  <bb 2> [local count: 25274560]:
  # DEBUG BEGIN_STMT
  # DEBUG pxReturn => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} pxList_23(D)->uxNumberOfItems;
  if (_1 != 0)
    goto <bb 3>; [71.00%]
  else
    goto <bb 15>; [29.00%]

  <bb 3> [local count: 17944938]:
  # DEBUG BEGIN_STMT
  # DEBUG pxConstList => pxList_23(D)
  # DEBUG BEGIN_STMT
  _2 = pxList_23(D)->pxIndex;
  _3 = _2->pxNext;
  pxList_23(D)->pxIndex = _3;
  # DEBUG BEGIN_STMT
  _4 = &pxList_23(D)->xListEnd;
  if (_3 == _4)
    goto <bb 4>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 4> [local count: 5383481]:
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct ListItem_t *)_3].pxNext;
  pxList_23(D)->pxIndex = _5;

  <bb 5> [local count: 17944938]:
  # DEBUG BEGIN_STMT
  _6 = pxList_23(D)->pxIndex;
  pxFirstTCB_26 = _6->pvOwner;
  # DEBUG pxFirstTCB => pxFirstTCB_26

  <bb 6> [local count: 167748888]:
  # pxReturn_13 = PHI <0B(5), 0B(16)>
  # DEBUG pxReturn => pxReturn_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pxConstList => pxList_23(D)
  # DEBUG BEGIN_STMT
  _7 = pxList_23(D)->pxIndex;
  _8 = _7->pxNext;
  pxList_23(D)->pxIndex = _8;
  # DEBUG BEGIN_STMT
  if (_4 == _8)
    goto <bb 7>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 7> [local count: 50324666]:
  # DEBUG BEGIN_STMT
  _9 = MEM[(struct ListItem_t *)_8].pxNext;
  pxList_23(D)->pxIndex = _9;

  <bb 8> [local count: 167748888]:
  # DEBUG BEGIN_STMT
  _10 = pxList_23(D)->pxIndex;
  pxNextTCB_29 = _10->pvOwner;
  # DEBUG pxNextTCB => pxNextTCB_29
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xBreakLoop => 0
  # DEBUG BEGIN_STMT
  # DEBUG x => 0
  goto <bb 12>; [100.00%]

  <bb 9> [local count: 976138693]:
  # DEBUG BEGIN_STMT
  cNextChar_30 = pxNextTCB_29->pcTaskName[x_17];
  # DEBUG cNextChar => cNextChar_30
  # DEBUG BEGIN_STMT
  _11 = pcNameToQuery_31(D) + x_17;
  _12 = *_11;
  if (_12 != cNextChar_30)
    goto <bb 13>; [3.66%]
  else
    goto <bb 10>; [96.34%]

  <bb 10> [local count: 940412017]:
  # DEBUG BEGIN_STMT
  if (cNextChar_30 == 0)
    goto <bb 13>; [3.66%]
  else
    goto <bb 11>; [96.34%]

  <bb 11> [local count: 905992937]:
  # DEBUG xBreakLoop => 0
  # DEBUG pxReturn => pxReturn_14
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  x_32 = x_17 + 1;
  # DEBUG x => x_32

  <bb 12> [local count: 1073741824]:
  # pxReturn_14 = PHI <pxReturn_13(8), pxReturn_14(11)>
  # x_17 = PHI <0(8), x_32(11)>
  # DEBUG xBreakLoop => 0
  # DEBUG x => x_17
  # DEBUG pxReturn => pxReturn_14
  # DEBUG BEGIN_STMT
  if (x_17 != 10)
    goto <bb 9>; [90.91%]
  else
    goto <bb 13>; [9.09%]

  <bb 13> [local count: 167748888]:
  # pxReturn_15 = PHI <pxNextTCB_29(10), pxReturn_14(12), pxReturn_14(9)>
  # DEBUG xBreakLoop => NULL
  # DEBUG pxReturn => pxReturn_15
  # DEBUG BEGIN_STMT
  if (pxReturn_15 != 0B)
    goto <bb 15>; [5.50%]
  else
    goto <bb 14>; [94.50%]

  <bb 14> [local count: 158522699]:
  # DEBUG BEGIN_STMT
  if (pxFirstTCB_26 != pxNextTCB_29)
    goto <bb 16>; [94.50%]
  else
    goto <bb 15>; [5.50%]

  <bb 16> [local count: 149803950]:
  goto <bb 6>; [100.00%]

  <bb 15> [local count: 25274560]:
  # pxReturn_16 = PHI <0B(2), 0B(14), pxReturn_15(13)>
  # DEBUG pxReturn => pxReturn_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return pxReturn_16;

}



;; Function prvTaskIsTaskSuspended (prvTaskIsTaskSuspended, funcdef_no=18, decl_uid=6950, cgraph_uid=19, symbol_order=40)

Modification phase of node prvTaskIsTaskSuspended/40
prvTaskIsTaskSuspended (struct tskTaskControlBlock * const xTask)
{
  uint32_t ulNewBASEPRI;
  BaseType_t xReturn;
  struct xLIST * _1;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 0
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTask_5(D)
  # DEBUG BEGIN_STMT
  if (xTask_5(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

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
" : "=r" ulNewBASEPRI_8 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_8

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(const struct TCB_t *)xTask_5(D)].xStateListItem.pvContainer;
  if (_1 == &xSuspendedTaskList)
    goto <bb 6>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 6> [local count: 75162]:
  xReturn_2 = prvTaskIsTaskSuspended.part.0 (xTask_5(D));

  <bb 7> [local count: 250539]:
  # xReturn_3 = PHI <0(5), xReturn_2(6)>
  # DEBUG xReturn => xReturn_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xReturn_3;

}



;; Function prvResetNextTaskUnblockTime (prvResetNextTaskUnblockTime, funcdef_no=57, decl_uid=6972, cgraph_uid=58, symbol_order=79)

Modification phase of node prvResetNextTaskUnblockTime/79
prvResetNextTaskUnblockTime ()
{
  struct List_t * pxDelayedTaskList.21_1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pxDelayedTaskList.21_1 ={v} pxDelayedTaskList;
  _2 ={v} pxDelayedTaskList.21_1->uxNumberOfItems;
  if (_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  xNextTaskUnblockTime ={v} 4294967295;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870912]:
  prvResetNextTaskUnblockTime.part.0 ();

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function prvAddCurrentTaskToDelayedList (prvAddCurrentTaskToDelayedList, funcdef_no=74, decl_uid=6961, cgraph_uid=75, symbol_order=96)

Modification phase of node prvAddCurrentTaskToDelayedList/96
prvAddCurrentTaskToDelayedList (TickType_t xTicksToWait, const BaseType_t xCanBlockIndefinitely)
{
  const TickType_t xConstTickCount;
  TickType_t xTimeToWake;
  struct TCB_t * pxCurrentTCB.24_1;
  struct TCB_t * pxCurrentTCB.25_2;
  struct ListItem_t * _3;
  struct TCB_t * pxCurrentTCB.31_5;
  struct List_t * pxOverflowDelayedTaskList.32_6;
  struct TCB_t * pxCurrentTCB.33_7;
  struct ListItem_t * _8;
  struct List_t * pxDelayedTaskList.34_9;
  struct TCB_t * pxCurrentTCB.35_10;
  struct ListItem_t * _11;
  long unsigned int xNextTaskUnblockTime.36_12;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xConstTickCount_14 ={v} xTickCount;
  # DEBUG xConstTickCount => xConstTickCount_14
  # DEBUG BEGIN_STMT
  pxCurrentTCB.24_1 ={v} pxCurrentTCB;
  pxCurrentTCB.24_1->ucDelayAborted = 0;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.25_2 ={v} pxCurrentTCB;
  _3 = &pxCurrentTCB.25_2->xStateListItem;
  uxListRemove (_3);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTicksToWait_17(D) == 4294967295)
    goto <bb 3>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 3> [local count: 365072220]:
  if (xCanBlockIndefinitely_18(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 182536110]:
  # DEBUG D#2 => xTicksToWait_17(D)
  # DEBUG D#3 => xCanBlockIndefinitely_18(D)
  prvAddCurrentTaskToDelayedList.part.0 ();
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 891205713]:
  # DEBUG BEGIN_STMT
  xTimeToWake_19 = xConstTickCount_14 + xTicksToWait_17(D);
  # DEBUG xTimeToWake => xTimeToWake_19
  # DEBUG BEGIN_STMT
  pxCurrentTCB.31_5 ={v} pxCurrentTCB;
  pxCurrentTCB.31_5->xStateListItem.xItemValue = xTimeToWake_19;
  # DEBUG BEGIN_STMT
  if (xConstTickCount_14 > xTimeToWake_19)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 445602856]:
  # DEBUG BEGIN_STMT
  pxOverflowDelayedTaskList.32_6 ={v} pxOverflowDelayedTaskList;
  pxCurrentTCB.33_7 ={v} pxCurrentTCB;
  _8 = &pxCurrentTCB.33_7->xStateListItem;
  vListInsert (pxOverflowDelayedTaskList.32_6, _8);
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 445602856]:
  # DEBUG BEGIN_STMT
  pxDelayedTaskList.34_9 ={v} pxDelayedTaskList;
  pxCurrentTCB.35_10 ={v} pxCurrentTCB;
  _11 = &pxCurrentTCB.35_10->xStateListItem;
  vListInsert (pxDelayedTaskList.34_9, _11);
  # DEBUG BEGIN_STMT
  xNextTaskUnblockTime.36_12 ={v} xNextTaskUnblockTime;
  if (xNextTaskUnblockTime.36_12 > xTimeToWake_19)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 222801428]:
  # DEBUG BEGIN_STMT
  xNextTaskUnblockTime ={v} xTimeToWake_19;

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function prvIdleTask (prvIdleTask, funcdef_no=47, decl_uid=6954, cgraph_uid=48, symbol_order=69) (executed once)

Modification phase of node prvIdleTask/69
prvIdleTask (void * pvParameters)
{
  long unsigned int _1;

  <bb 2> [local count: 63351]:

  <bb 3> [local count: 633507677]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  prvCheckTasksWaitingTermination ();
  # DEBUG BEGIN_STMT
  _1 ={v} pxReadyTasksLists[0].uxNumberOfItems;
  if (_1 > 1)
    goto <bb 5>; [59.00%]
  else
    goto <bb 6>; [41.00%]

  <bb 6> [local count: 440234148]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 633507677]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT
  goto <bb 3>; [100.00%]

}



;; Function xTaskCreate (xTaskCreate, funcdef_no=7, decl_uid=6140, cgraph_uid=8, symbol_order=29)

Modification phase of node xTaskCreate/29
xTaskCreate (void (*TaskFunction_t) (void *) pxTaskCode, const char * const pcName, const uint16_t usStackDepth, void * const pvParameters, UBaseType_t uxPriority, struct tskTaskControlBlock * * const pxCreatedTask)
{
  StackType_t * pxStack;
  BaseType_t xReturn;
  struct TCB_t * pxNewTCB;
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) usStackDepth_6(D);
  _2 = _1 * 4;
  pxStack_9 = pvPortMalloc (_2);
  # DEBUG pxStack => pxStack_9
  # DEBUG BEGIN_STMT
  if (pxStack_9 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 4> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pxNewTCB_11 = pvPortMalloc (96);
  # DEBUG pxNewTCB => pxNewTCB_11
  # DEBUG BEGIN_STMT
  if (pxNewTCB_11 != 0B)
    goto <bb 5>; [82.57%]
  else
    goto <bb 6>; [17.43%]

  <bb 5> [local count: 474058937]:
  # DEBUG BEGIN_STMT
  pxNewTCB_11->pxStack = pxStack_9;
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 100070816]:
  # DEBUG BEGIN_STMT
  vPortFree (pxStack_9);

  <bb 7> [local count: 574129754]:
  # DEBUG pxNewTCB => pxNewTCB_11
  # DEBUG BEGIN_STMT
  if (pxNewTCB_11 != 0B)
    goto <bb 8>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 8> [local count: 306987179]:
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => 0B
  prvInitialiseNewTask.isra.0 (pxTaskCode_14(D), pcName_15(D), _1, pvParameters_16(D), uxPriority_17(D), pxCreatedTask_18(D), pxNewTCB_11);
  # DEBUG BEGIN_STMT
  prvAddNewTaskToReadyList (pxNewTCB_11);
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 9> [local count: 1073741824]:
  # xReturn_3 = PHI <1(8), -1(7), -1(2)>
  # DEBUG pxNewTCB => NULL
  # DEBUG xReturn => xReturn_3
  # DEBUG BEGIN_STMT
  return xReturn_3;

}



;; Function vTaskDelete (vTaskDelete, funcdef_no=10, decl_uid=6145, cgraph_uid=11, symbol_order=32)

Modification phase of node vTaskDelete/32
vTaskDelete (struct tskTaskControlBlock * xTaskToDelete)
{
  uint32_t ulNewBASEPRI;
  struct ListItem_t * _1;
  struct xLIST * _2;
  struct ListItem_t * _3;
  long unsigned int uxTaskNumber.13_4;
  long unsigned int _5;
  struct TCB_t * pxCurrentTCB.14_6;
  long unsigned int uxDeletedTasksWaitingCleanUp.15_7;
  long unsigned int _8;
  long unsigned int uxCurrentNumberOfTasks.16_9;
  long unsigned int _10;
  struct TCB_t * pxCurrentTCB.17_11;
  long int xSchedulerRunning.18_12;
  struct TCB_t * pxCurrentTCB.19_13;
  long unsigned int uxSchedulerSuspended.20_14;
  struct TCB_t * iftmp.12_15;
  struct TCB_t * iftmp.12_23;

  <bb 2> [local count: 1431653]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  if (xTaskToDelete_22(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 429496]:
  iftmp.12_23 ={v} pxCurrentTCB;

  <bb 4> [local count: 1431653]:
  # iftmp.12_15 = PHI <iftmp.12_23(3), xTaskToDelete_22(D)(2)>
  # DEBUG pxTCB => iftmp.12_15
  # DEBUG BEGIN_STMT
  _1 = &iftmp.12_15->xStateListItem;
  uxListRemove (_1);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = iftmp.12_15->xEventListItem.pvContainer;
  if (_2 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 765505]:
  # DEBUG BEGIN_STMT
  _3 = &iftmp.12_15->xEventListItem;
  uxListRemove (_3);

  <bb 6> [local count: 1431653]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxTaskNumber.13_4 = uxTaskNumber;
  _5 = uxTaskNumber.13_4 + 1;
  uxTaskNumber = _5;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.14_6 ={v} pxCurrentTCB;
  if (pxCurrentTCB.14_6 == iftmp.12_15)
    goto <bb 7>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 7> [local count: 429496]:
  # DEBUG BEGIN_STMT
  vListInsertEnd (&xTasksWaitingTermination, _1);
  # DEBUG BEGIN_STMT
  uxDeletedTasksWaitingCleanUp.15_7 ={v} uxDeletedTasksWaitingCleanUp;
  _8 = uxDeletedTasksWaitingCleanUp.15_7 + 1;
  uxDeletedTasksWaitingCleanUp ={v} _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 1002157]:
  # DEBUG BEGIN_STMT
  uxCurrentNumberOfTasks.16_9 ={v} uxCurrentNumberOfTasks;
  _10 = uxCurrentNumberOfTasks.16_9 + 4294967295;
  uxCurrentNumberOfTasks ={v} _10;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  prvResetNextTaskUnblockTime ();

  <bb 9> [local count: 1431653]:
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  pxCurrentTCB.17_11 ={v} pxCurrentTCB;
  if (pxCurrentTCB.17_11 != iftmp.12_15)
    goto <bb 10>; [53.47%]
  else
    goto <bb 11>; [46.53%]

  <bb 10> [local count: 765505]:
  # DEBUG BEGIN_STMT
  prvDeleteTCB (iftmp.12_15);

  <bb 11> [local count: 1431653]:
  # DEBUG BEGIN_STMT
  xSchedulerRunning.18_12 ={v} xSchedulerRunning;
  if (xSchedulerRunning.18_12 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 12> [local count: 715827]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.19_13 ={v} pxCurrentTCB;
  if (pxCurrentTCB.19_13 == iftmp.12_15)
    goto <bb 13>; [30.00%]
  else
    goto <bb 17>; [70.00%]

  <bb 13> [local count: 214748]:
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.20_14 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.20_14 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 14> [local count: 107374]:
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
" : "=r" ulNewBASEPRI_36 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_36

  <bb 15> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 1073741824]:
  goto <bb 15>; [100.00%]

  <bb 16> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1324279]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function eTaskGetState (eTaskGetState, funcdef_no=13, decl_uid=6158, cgraph_uid=14, symbol_order=35)

Modification phase of node eTaskGetState/35
eTaskGetState (struct tskTaskControlBlock * xTask)
{
  uint32_t ulNewBASEPRI;
  BaseType_t x;
  const struct List_t * pxOverflowedDelayedList;
  const struct List_t * pxDelayedList;
  const struct List_t * pxStateList;
  eTaskState eReturn;
  struct TCB_t * pxCurrentTCB.38_1;
  struct xLIST * _2;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTask_5(D)
  # DEBUG BEGIN_STMT
  if (xTask_5(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

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
" : "=r" ulNewBASEPRI_15 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_15

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.38_1 ={v} pxCurrentTCB;
  if (pxCurrentTCB.38_1 == xTask_5(D))
    goto <bb 14>; [46.53%]
  else
    goto <bb 6>; [53.47%]

  <bb 6> [local count: 133963]:
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  pxStateList_9 = MEM[(const struct TCB_t *)xTask_5(D)].xStateListItem.pvContainer;
  # DEBUG pxStateList => pxStateList_9
  # DEBUG BEGIN_STMT
  pxDelayedList_10 ={v} pxDelayedTaskList;
  # DEBUG pxDelayedList => pxDelayedList_10
  # DEBUG BEGIN_STMT
  pxOverflowedDelayedList_11 ={v} pxOverflowDelayedTaskList;
  # DEBUG pxOverflowedDelayedList => pxOverflowedDelayedList_11
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  if (pxStateList_9 == pxDelayedList_10)
    goto <bb 14>; [18.75%]
  else
    goto <bb 7>; [81.25%]

  <bb 7> [local count: 108845]:
  if (pxStateList_9 == pxOverflowedDelayedList_11)
    goto <bb 14>; [18.75%]
  else
    goto <bb 8>; [81.25%]

  <bb 8> [local count: 88437]:
  # DEBUG BEGIN_STMT
  if (pxStateList_9 == &xSuspendedTaskList)
    goto <bb 9>; [30.00%]
  else
    goto <bb 11>; [70.00%]

  <bb 9> [local count: 26531]:
  # DEBUG BEGIN_STMT
  _2 = MEM[(const struct TCB_t *)xTask_5(D)].xEventListItem.pvContainer;
  if (_2 == 0B)
    goto <bb 10>; [44.32%]
  else
    goto <bb 14>; [55.68%]

  <bb 10> [local count: 11759]:
  # x_4 = PHI <0(9)>
  eReturn_13 = eTaskGetState.part.0 (xTask_5(D));
  goto <bb 14>; [100.00%]

  <bb 11> [local count: 61906]:
  # DEBUG BEGIN_STMT
  if (pxStateList_9 == &xTasksWaitingTermination)
    goto <bb 14>; [18.75%]
  else
    goto <bb 12>; [81.25%]

  <bb 12> [local count: 50298]:
  if (pxStateList_9 == 0B)
    goto <bb 14>; [18.75%]
  else
    goto <bb 13>; [81.25%]

  <bb 13> [local count: 40867]:
  # DEBUG BEGIN_STMT
  # DEBUG eReturn => 1

  <bb 14> [local count: 250539]:
  # eReturn_3 = PHI <0(5), 2(7), 2(9), 4(12), 1(13), 4(11), eReturn_13(10), 2(6)>
  # DEBUG eReturn => eReturn_3
  # DEBUG BEGIN_STMT
  return eReturn_3;

}



;; Function uxTaskPriorityGet (uxTaskPriorityGet, funcdef_no=14, decl_uid=6154, cgraph_uid=15, symbol_order=36)

Modification phase of node uxTaskPriorityGet/36
uxTaskPriorityGet (struct tskTaskControlBlock * const xTask)
{
  UBaseType_t uxReturn;
  const struct TCB_t * iftmp.39_1;
  const struct TCB_t * iftmp.39_5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  if (xTask_4(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  iftmp.39_5 ={v} pxCurrentTCB;

  <bb 4> [local count: 1073741824]:
  # iftmp.39_1 = PHI <iftmp.39_5(3), xTask_4(D)(2)>
  # DEBUG pxTCB => iftmp.39_1
  # DEBUG BEGIN_STMT
  uxReturn_6 = iftmp.39_1->uxPriority;
  # DEBUG uxReturn => uxReturn_6
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  return uxReturn_6;

}



;; Function uxTaskPriorityGetFromISR (uxTaskPriorityGetFromISR, funcdef_no=15, decl_uid=6156, cgraph_uid=16, symbol_order=37)

Modification phase of node uxTaskPriorityGetFromISR/37
uxTaskPriorityGetFromISR (struct tskTaskControlBlock * const xTask)
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  UBaseType_t uxReturn;
  const struct TCB_t * iftmp.40_1;
  const struct TCB_t * iftmp.40_5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortValidateInterruptPriority ();
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
" : "=r" ulOriginalBASEPRI_7, "=r" ulNewBASEPRI_8 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_8
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_7
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptState => ulOriginalBASEPRI_7
  # DEBUG BEGIN_STMT
  if (xTask_4(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  iftmp.40_5 ={v} pxCurrentTCB;

  <bb 4> [local count: 1073741824]:
  # iftmp.40_1 = PHI <iftmp.40_5(3), xTask_4(D)(2)>
  # DEBUG pxTCB => iftmp.40_1
  # DEBUG BEGIN_STMT
  uxReturn_6 = iftmp.40_1->uxPriority;
  # DEBUG uxReturn => uxReturn_6
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_7
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_7 : "memory");
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  return uxReturn_6;

}



;; Function vTaskPrioritySet (vTaskPrioritySet, funcdef_no=16, decl_uid=6166, cgraph_uid=17, symbol_order=38)

Modification phase of node vTaskPrioritySet/38
vTaskPrioritySet (struct tskTaskControlBlock * xTask, UBaseType_t uxNewPriority)
{
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  BaseType_t xYieldRequired;
  UBaseType_t uxPriorityUsedOnEntry;
  UBaseType_t uxCurrentBasePriority;
  struct TCB_t * pxCurrentTCB.42_1;
  struct TCB_t * pxCurrentTCB.43_2;
  long unsigned int _3;
  struct TCB_t * pxCurrentTCB.44_4;
  long unsigned int _5;
  signed int _6;
  long unsigned int _7;
  struct xLIST * _8;
  struct List_t * _9;
  struct ListItem_t * _10;
  long unsigned int _11;
  long unsigned int uxTopReadyPriority.45_12;
  struct xLIST_ITEM * _13;
  struct xLIST_ITEM * _14;
  struct List_t * _15;
  long unsigned int _16;
  long unsigned int _17;
  struct TCB_t * iftmp.41_19;
  struct TCB_t * iftmp.41_29;

  <bb 2> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xYieldRequired => 0
  # DEBUG BEGIN_STMT
  if (uxNewPriority_25(D) > 9)
    goto <bb 3>; [67.00%]
  else
    goto <bb 5>; [33.00%]

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
" : "=r" ulNewBASEPRI_48 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_48

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG uxNewPriority => uxNewPriority_25(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  if (xTask_28(D) == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 6> [local count: 15866]:
  iftmp.41_29 ={v} pxCurrentTCB;

  <bb 7> [local count: 52886]:
  # iftmp.41_19 = PHI <iftmp.41_29(6), xTask_28(D)(5)>
  # DEBUG pxTCB => iftmp.41_19
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxCurrentBasePriority_30 = iftmp.41_19->uxBasePriority;
  # DEBUG uxCurrentBasePriority => uxCurrentBasePriority_30
  # DEBUG BEGIN_STMT
  if (uxNewPriority_25(D) != uxCurrentBasePriority_30)
    goto <bb 8>; [66.00%]
  else
    goto <bb 24>; [34.00%]

  <bb 8> [local count: 34905]:
  # DEBUG BEGIN_STMT
  if (uxNewPriority_25(D) > uxCurrentBasePriority_30)
    goto <bb 9>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 9> [local count: 17452]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.42_1 ={v} pxCurrentTCB;
  if (pxCurrentTCB.42_1 != iftmp.41_19)
    goto <bb 10>; [70.00%]
  else
    goto <bb 14>; [30.00%]

  <bb 10> [local count: 12217]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.43_2 ={v} pxCurrentTCB;
  _3 = pxCurrentTCB.43_2->uxPriority;
  if (_3 <= uxNewPriority_25(D))
    goto <bb 11>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 11> [local count: 6108]:
  # DEBUG BEGIN_STMT
  # DEBUG xYieldRequired => 1
  goto <bb 14>; [100.00%]

  <bb 12> [local count: 17452]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.44_4 ={v} pxCurrentTCB;
  if (pxCurrentTCB.44_4 == iftmp.41_19)
    goto <bb 13>; [30.00%]
  else
    goto <bb 14>; [70.00%]

  <bb 13> [local count: 5236]:
  # DEBUG BEGIN_STMT
  # DEBUG xYieldRequired => 1

  <bb 14> [local count: 34905]:
  # xYieldRequired_18 = PHI <1(11), 0(12), 1(13), 0(9), 0(10)>
  # DEBUG xYieldRequired => xYieldRequired_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxPriorityUsedOnEntry_31 = iftmp.41_19->uxPriority;
  # DEBUG uxPriorityUsedOnEntry => uxPriorityUsedOnEntry_31
  # DEBUG BEGIN_STMT
  if (uxCurrentBasePriority_30 == uxPriorityUsedOnEntry_31)
    goto <bb 15>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 15> [local count: 11868]:
  # DEBUG BEGIN_STMT
  iftmp.41_19->uxPriority = uxNewPriority_25(D);

  <bb 16> [local count: 34905]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.41_19->uxBasePriority = uxNewPriority_25(D);
  # DEBUG BEGIN_STMT
  _5 = iftmp.41_19->xEventListItem.xItemValue;
  _6 = (signed int) _5;
  if (_6 >= 0)
    goto <bb 17>; [59.00%]
  else
    goto <bb 18>; [41.00%]

  <bb 17> [local count: 20594]:
  # DEBUG BEGIN_STMT
  _7 = 10 - uxNewPriority_25(D);
  iftmp.41_19->xEventListItem.xItemValue = _7;

  <bb 18> [local count: 34905]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = iftmp.41_19->xStateListItem.pvContainer;
  _9 = &pxReadyTasksLists[uxPriorityUsedOnEntry_31];
  if (_8 == _9)
    goto <bb 19>; [17.43%]
  else
    goto <bb 22>; [82.57%]

  <bb 19> [local count: 6084]:
  # DEBUG BEGIN_STMT
  _10 = &iftmp.41_19->xStateListItem;
  uxListRemove (_10);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = iftmp.41_19->uxPriority;
  uxTopReadyPriority.45_12 ={v} uxTopReadyPriority;
  if (_11 > uxTopReadyPriority.45_12)
    goto <bb 20>; [50.00%]
  else
    goto <bb 21>; [50.00%]

  <bb 20> [local count: 3042]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _11;

  <bb 21> [local count: 6084]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_37 = pxReadyTasksLists[_11].pxIndex;
  # DEBUG pxIndex => pxIndex_37
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.41_19->xStateListItem.pxNext = pxIndex_37;
  # DEBUG BEGIN_STMT
  _13 = pxIndex_37->pxPrevious;
  iftmp.41_19->xStateListItem.pxPrevious = _13;
  # DEBUG BEGIN_STMT
  _14 = pxIndex_37->pxPrevious;
  _14->pxNext = _10;
  # DEBUG BEGIN_STMT
  pxIndex_37->pxPrevious = _10;
  # DEBUG BEGIN_STMT
  _15 = &pxReadyTasksLists[_11];
  iftmp.41_19->xStateListItem.pvContainer = _15;
  # DEBUG BEGIN_STMT
  _16 ={v} pxReadyTasksLists[_11].uxNumberOfItems;
  _17 = _16 + 1;
  pxReadyTasksLists[_11].uxNumberOfItems ={v} _17;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 22> [local count: 34905]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xYieldRequired_18 != 0)
    goto <bb 23>; [50.00%]
  else
    goto <bb 24>; [50.00%]

  <bb 23> [local count: 17452]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 24> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  return;

}



;; Function vTaskResume (vTaskResume, funcdef_no=19, decl_uid=6170, cgraph_uid=20, symbol_order=41)

Modification phase of node vTaskResume/41
vTaskResume (struct tskTaskControlBlock * xTaskToResume)
{
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  struct TCB_t * pxCurrentTCB.52_1;
  long int _2;
  struct ListItem_t * _3;
  long unsigned int _4;
  long unsigned int uxTopReadyPriority.53_5;
  struct xLIST_ITEM * _6;
  struct xLIST_ITEM * _7;
  struct List_t * _8;
  long unsigned int _9;
  long unsigned int _10;
  struct TCB_t * pxCurrentTCB.54_11;
  long unsigned int _12;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTaskToResume_16(D)
  # DEBUG BEGIN_STMT
  if (xTaskToResume_16(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

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
" : "=r" ulNewBASEPRI_33 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_33

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.52_1 ={v} pxCurrentTCB;
  if (pxCurrentTCB.52_1 != xTaskToResume_16(D))
    goto <bb 6>; [53.47%]
  else
    goto <bb 12>; [46.53%]

  <bb 6> [local count: 133963]:
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  _2 = prvTaskIsTaskSuspended (xTaskToResume_16(D));
  if (_2 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 7> [local count: 44208]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = &MEM[(struct TCB_t *)xTaskToResume_16(D)].xStateListItem;
  uxListRemove (_3);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = MEM[(struct TCB_t *)xTaskToResume_16(D)].uxPriority;
  uxTopReadyPriority.53_5 ={v} uxTopReadyPriority;
  if (_4 > uxTopReadyPriority.53_5)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 22104]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _4;

  <bb 9> [local count: 44208]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_22 = pxReadyTasksLists[_4].pxIndex;
  # DEBUG pxIndex => pxIndex_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToResume_16(D)].xStateListItem.pxNext = pxIndex_22;
  # DEBUG BEGIN_STMT
  _6 = pxIndex_22->pxPrevious;
  MEM[(struct TCB_t *)xTaskToResume_16(D)].xStateListItem.pxPrevious = _6;
  # DEBUG BEGIN_STMT
  _7 = pxIndex_22->pxPrevious;
  _7->pxNext = _3;
  # DEBUG BEGIN_STMT
  pxIndex_22->pxPrevious = _3;
  # DEBUG BEGIN_STMT
  _8 = &pxReadyTasksLists[_4];
  MEM[(struct TCB_t *)xTaskToResume_16(D)].xStateListItem.pvContainer = _8;
  # DEBUG BEGIN_STMT
  _9 ={v} pxReadyTasksLists[_4].uxNumberOfItems;
  _10 = _9 + 1;
  pxReadyTasksLists[_4].uxNumberOfItems ={v} _10;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.54_11 ={v} pxCurrentTCB;
  _12 = pxCurrentTCB.54_11->uxPriority;
  if (_4 >= _12)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 22104]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 133963]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();

  <bb 12> [local count: 250539]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function xTaskResumeFromISR (xTaskResumeFromISR, funcdef_no=20, decl_uid=6172, cgraph_uid=21, symbol_order=42)

Modification phase of node xTaskResumeFromISR/42
xTaskResumeFromISR (struct tskTaskControlBlock * xTaskToResume)
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  BaseType_t xYieldRequired;
  long int _1;
  long unsigned int uxSchedulerSuspended.55_2;
  long unsigned int _3;
  struct TCB_t * pxCurrentTCB.56_4;
  long unsigned int _5;
  struct ListItem_t * _6;
  long unsigned int _7;
  long unsigned int uxTopReadyPriority.57_8;
  struct xLIST_ITEM * _9;
  struct xLIST_ITEM * _10;
  struct List_t * _11;
  long unsigned int _12;
  long unsigned int _13;
  struct ListItem_t * _14;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG xYieldRequired => 0
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTaskToResume_20(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTaskToResume_20(D) == 0B)
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
" : "=r" ulNewBASEPRI_35 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_35

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortValidateInterruptPriority ();
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
" : "=r" ulOriginalBASEPRI_36, "=r" ulNewBASEPRI_37 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_37
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_36
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptStatus => ulOriginalBASEPRI_36
  # DEBUG BEGIN_STMT
  _1 = prvTaskIsTaskSuspended (xTaskToResume_20(D));
  if (_1 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 6> [local count: 61694]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.55_2 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.55_2 == 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 12>; [33.00%]

  <bb 7> [local count: 41335]:
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct TCB_t *)xTaskToResume_20(D)].uxPriority;
  pxCurrentTCB.56_4 ={v} pxCurrentTCB;
  _5 = pxCurrentTCB.56_4->uxPriority;
  if (_3 >= _5)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 20668]:
  # DEBUG BEGIN_STMT
  # DEBUG xYieldRequired => 1
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 1;

  <bb 9> [local count: 41335]:
  # xYieldRequired_15 = PHI <0(7), 1(8)>
  # DEBUG xYieldRequired => xYieldRequired_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = &MEM[(struct TCB_t *)xTaskToResume_20(D)].xStateListItem;
  uxListRemove (_6);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct TCB_t *)xTaskToResume_20(D)].uxPriority;
  uxTopReadyPriority.57_8 ={v} uxTopReadyPriority;
  if (_7 > uxTopReadyPriority.57_8)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 20668]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _7;

  <bb 11> [local count: 41335]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_28 = pxReadyTasksLists[_7].pxIndex;
  # DEBUG pxIndex => pxIndex_28
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToResume_20(D)].xStateListItem.pxNext = pxIndex_28;
  # DEBUG BEGIN_STMT
  _9 = pxIndex_28->pxPrevious;
  MEM[(struct TCB_t *)xTaskToResume_20(D)].xStateListItem.pxPrevious = _9;
  # DEBUG BEGIN_STMT
  _10 = pxIndex_28->pxPrevious;
  _10->pxNext = _6;
  # DEBUG BEGIN_STMT
  pxIndex_28->pxPrevious = _6;
  # DEBUG BEGIN_STMT
  _11 = &pxReadyTasksLists[_7];
  MEM[(struct TCB_t *)xTaskToResume_20(D)].xStateListItem.pvContainer = _11;
  # DEBUG BEGIN_STMT
  _12 ={v} pxReadyTasksLists[_7].uxNumberOfItems;
  _13 = _12 + 1;
  pxReadyTasksLists[_7].uxNumberOfItems ={v} _13;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 20359]:
  # DEBUG BEGIN_STMT
  _14 = &MEM[(struct TCB_t *)xTaskToResume_20(D)].xEventListItem;
  vListInsertEnd (&xPendingReadyList, _14);

  <bb 13> [local count: 123389]:
  # xYieldRequired_16 = PHI <0(5), 0(12), xYieldRequired_15(11)>
  # DEBUG xYieldRequired => xYieldRequired_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_36
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_36 : "memory");
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  return xYieldRequired_16;

}



;; Function vTaskStartScheduler (vTaskStartScheduler, funcdef_no=21, decl_uid=6174, cgraph_uid=22, symbol_order=43)

Modification phase of node vTaskStartScheduler/43
vTaskStartScheduler ()
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  BaseType_t xReturn;
  long unsigned int vol.58_13;

  <bb 2> [local count: 395945]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xReturn_6 = xTaskCreate (prvIdleTask, "IDLE", 90, 0B, 0, &xIdleTaskHandle);
  # DEBUG xReturn => xReturn_6
  # DEBUG BEGIN_STMT
  if (xReturn_6 == 1)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 80139]:
  # DEBUG BEGIN_STMT
  xReturn_8 = xTimerCreateTimerTask ();
  # DEBUG xReturn => xReturn_8

  <bb 4> [local count: 395945]:
  # xReturn_1 = PHI <xReturn_6(2), xReturn_8(3)>
  # DEBUG xReturn => xReturn_1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xReturn_1 == 1)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 80139]:
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
" : "=r" ulNewBASEPRI_14 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  xNextTaskUnblockTime ={v} 4294967295;
  # DEBUG BEGIN_STMT
  xSchedulerRunning ={v} 1;
  # DEBUG BEGIN_STMT
  xTickCount ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xPortStartScheduler ();
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 315806]:
  # DEBUG BEGIN_STMT
  if (xReturn_1 == -1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 7> [local count: 107374]:
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
" : "=r" ulNewBASEPRI_15 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_15

  <bb 8> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 288571]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vol.58_13 ={v} uxTopUsedPriority;
  return;

}



;; Function vTaskEndScheduler (vTaskEndScheduler, funcdef_no=22, decl_uid=6176, cgraph_uid=23, symbol_order=44)

Modification phase of node vTaskEndScheduler/44
vTaskEndScheduler ()
{
  uint32_t ulNewBASEPRI;

  <bb 2> [local count: 1073741824]:
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
" : "=r" ulNewBASEPRI_4 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  xSchedulerRunning ={v} 0;
  # DEBUG BEGIN_STMT
  vPortEndScheduler ();
  return;

}



;; Function vTaskSuspendAll (vTaskSuspendAll, funcdef_no=23, decl_uid=6178, cgraph_uid=24, symbol_order=45)

Modification phase of node vTaskSuspendAll/45
vTaskSuspendAll ()
{
  long unsigned int uxSchedulerSuspended.62_1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.62_1 ={v} uxSchedulerSuspended;
  _2 = uxSchedulerSuspended.62_1 + 1;
  uxSchedulerSuspended ={v} _2;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("" :  :  : "memory");
  return;

}



;; Function xTaskGetTickCount (xTaskGetTickCount, funcdef_no=25, decl_uid=6182, cgraph_uid=26, symbol_order=47)

Modification phase of node xTaskGetTickCount/47
xTaskGetTickCount ()
{
  TickType_t xTicks;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTicks_2 ={v} xTickCount;
  # DEBUG xTicks => xTicks_2
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xTicks_2;

}



;; Function xTaskGetTickCountFromISR (xTaskGetTickCountFromISR, funcdef_no=26, decl_uid=6184, cgraph_uid=27, symbol_order=48)

Modification phase of node xTaskGetTickCountFromISR/48
xTaskGetTickCountFromISR ()
{
  TickType_t xReturn;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortValidateInterruptPriority ();
  # DEBUG BEGIN_STMT
  # DEBUG uxSavedInterruptStatus => 0
  # DEBUG BEGIN_STMT
  xReturn_3 ={v} xTickCount;
  # DEBUG xReturn => xReturn_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xReturn_3;

}



;; Function uxTaskGetNumberOfTasks (uxTaskGetNumberOfTasks, funcdef_no=27, decl_uid=6186, cgraph_uid=28, symbol_order=49)

Modification phase of node uxTaskGetNumberOfTasks/49
uxTaskGetNumberOfTasks ()
{
  UBaseType_t _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 ={v} uxCurrentNumberOfTasks;
  return _2;

}



;; Function pcTaskGetName (pcTaskGetName, funcdef_no=28, decl_uid=6188, cgraph_uid=29, symbol_order=50)

Modification phase of node pcTaskGetName/50
pcTaskGetName (struct tskTaskControlBlock * xTaskToQuery)
{
  uint32_t ulNewBASEPRI;
  struct TCB_t * iftmp.70_1;
  struct TCB_t * iftmp.70_4;
  char * _5;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTaskToQuery_2(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 107374]:
  iftmp.70_4 ={v} pxCurrentTCB;

  <bb 4> [local count: 357913]:
  # iftmp.70_1 = PHI <iftmp.70_4(3), xTaskToQuery_2(D)(2)>
  # DEBUG pxTCB => iftmp.70_1
  # DEBUG BEGIN_STMT
  if (iftmp.70_1 == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 5> [local count: 107374]:
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
" : "=r" ulNewBASEPRI_6 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_6

  <bb 6> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = &iftmp.70_1->pcTaskName[0];
  return _5;

}



;; Function xTaskIncrementTick (xTaskIncrementTick, funcdef_no=34, decl_uid=6261, cgraph_uid=35, symbol_order=56)

Modification phase of node xTaskIncrementTick/56
xTaskIncrementTick ()
{
  BaseType_t xSwitchRequired;
  long unsigned int uxSchedulerSuspended.80_1;
  long unsigned int xPendedTicks.92_5;
  long unsigned int _6;

  <bb 2> [local count: 641039]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xSwitchRequired => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.80_1 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.80_1 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 320520]:
  xSwitchRequired_2 = xTaskIncrementTick.part.0 ();
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 320519]:
  # DEBUG BEGIN_STMT
  xPendedTicks.92_5 ={v} xPendedTicks;
  _6 = xPendedTicks.92_5 + 1;
  xPendedTicks ={v} _6;

  <bb 5> [local count: 533665]:
  # xSwitchRequired_7 = PHI <xSwitchRequired_2(3), 0(4)>
  # DEBUG xSwitchRequired => xSwitchRequired_7
  # DEBUG BEGIN_STMT
  return xSwitchRequired_7;

}



;; Function xTaskResumeAll (xTaskResumeAll, funcdef_no=24, decl_uid=6180, cgraph_uid=25, symbol_order=46)

Modification phase of node xTaskResumeAll/46
xTaskResumeAll ()
{
  BaseType_t D.8470;
  uint32_t ulNewBASEPRI;
  long unsigned int uxSchedulerSuspended.63_1;

  <bb 2> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => 0B
  # DEBUG BEGIN_STMT
  # DEBUG xAlreadyYielded => 0
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.63_1 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.63_1 == 0)
    goto <bb 3>; [67.00%]
  else
    goto <bb 5>; [33.00%]

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
" : "=r" ulNewBASEPRI_5 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_5

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 52886]:
  _2 = xTaskResumeAll.part.0 ();
  return _2;

}



;; Function xTaskDelayUntil (xTaskDelayUntil, funcdef_no=11, decl_uid=6150, cgraph_uid=12, symbol_order=33)

Modification phase of node xTaskDelayUntil/33
xTaskDelayUntil (TickType_t * const pxPreviousWakeTime, const TickType_t xTimeIncrement)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  const TickType_t xConstTickCount;
  BaseType_t xShouldDelay;
  BaseType_t xAlreadyYielded;
  TickType_t xTimeToWake;
  long unsigned int uxSchedulerSuspended.23_1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 306783]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xShouldDelay => 0
  # DEBUG BEGIN_STMT
  if (pxPreviousWakeTime_7(D) == 0B)
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
" : "=r" ulNewBASEPRI_21 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_21

  <bb 4> [local count: 920350133]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 920350133]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTimeIncrement_8(D) == 0)
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
" : "=r" ulNewBASEPRI_22 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_22

  <bb 7> [local count: 1073741823]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 26> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.23_1 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.23_1 != 0)
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
" : "=r" ulNewBASEPRI_23 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_23

  <bb 10> [local count: 719407021]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 27> [local count: 719407021]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  xConstTickCount_11 ={v} xTickCount;
  # DEBUG xConstTickCount => xConstTickCount_11
  # DEBUG BEGIN_STMT
  _2 = *pxPreviousWakeTime_7(D);
  xTimeToWake_12 = _2 + xTimeIncrement_8(D);
  # DEBUG xTimeToWake => xTimeToWake_12
  # DEBUG BEGIN_STMT
  if (_2 > xConstTickCount_11)
    goto <bb 12>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 12> [local count: 17717]:
  # DEBUG BEGIN_STMT
  if (_2 > xTimeToWake_12)
    goto <bb 14>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 13> [local count: 8858]:
  # DEBUG xShouldDelay => 0
  # DEBUG BEGIN_STMT
  *pxPreviousWakeTime_7(D) = xTimeToWake_12;
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 14> [local count: 8858]:
  if (xConstTickCount_11 < xTimeToWake_12)
    goto <bb 16>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 15> [local count: 4429]:
  # DEBUG xShouldDelay => 0
  # DEBUG BEGIN_STMT
  *pxPreviousWakeTime_7(D) = xTimeToWake_12;
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 16> [local count: 4429]:
  # DEBUG BEGIN_STMT
  # DEBUG xShouldDelay => 1
  # DEBUG BEGIN_STMT
  *pxPreviousWakeTime_7(D) = xTimeToWake_12;
  # DEBUG BEGIN_STMT
  goto <bb 21>; [100.00%]

  <bb 17> [local count: 17717]:
  # DEBUG BEGIN_STMT
  if (_2 > xTimeToWake_12)
    goto <bb 19>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 18> [local count: 8858]:
  if (xConstTickCount_11 < xTimeToWake_12)
    goto <bb 19>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 19> [local count: 13288]:
  # DEBUG BEGIN_STMT
  # DEBUG xShouldDelay => 1
  # DEBUG BEGIN_STMT
  *pxPreviousWakeTime_7(D) = xTimeToWake_12;
  # DEBUG BEGIN_STMT
  goto <bb 21>; [100.00%]

  <bb 20> [local count: 4429]:
  # DEBUG xShouldDelay => 0
  # DEBUG BEGIN_STMT
  *pxPreviousWakeTime_7(D) = xTimeToWake_12;
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 21> [local count: 17717]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = xTimeToWake_12 - xConstTickCount_11;
  prvAddCurrentTaskToDelayedList (_3, 0);

  <bb 22> [local count: 35433]:
  # xShouldDelay_29 = PHI <0(20), 1(21), 0(15), 0(13)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xAlreadyYielded_16 = xTaskResumeAll ();
  # DEBUG xAlreadyYielded => xAlreadyYielded_16
  # DEBUG BEGIN_STMT
  if (xAlreadyYielded_16 == 0)
    goto <bb 23>; [50.00%]
  else
    goto <bb 24>; [50.00%]

  <bb 23> [local count: 17717]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 24> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xShouldDelay_29;

}



;; Function vTaskDelay (vTaskDelay, funcdef_no=12, decl_uid=6147, cgraph_uid=13, symbol_order=34)

Modification phase of node vTaskDelay/34
vTaskDelay (const TickType_t xTicksToDelay)
{
  uint32_t ulNewBASEPRI;
  BaseType_t xAlreadyYielded;
  long unsigned int uxSchedulerSuspended.37_1;

  <bb 2> [local count: 320519]:
  # DEBUG BEGIN_STMT
  # DEBUG xAlreadyYielded => 0
  # DEBUG BEGIN_STMT
  if (xTicksToDelay_3(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 160260]:
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.37_1 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.37_1 != 0)
    goto <bb 5>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 5> [local count: 107374]:
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
" : "=r" ulNewBASEPRI_13 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_13

  <bb 6> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  prvAddCurrentTaskToDelayedList (xTicksToDelay_3(D), 0);
  # DEBUG BEGIN_STMT
  xAlreadyYielded_8 = xTaskResumeAll ();
  # DEBUG xAlreadyYielded => xAlreadyYielded_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xAlreadyYielded_8 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 186703]:
  # DEBUG xAlreadyYielded => NULL
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 213145]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function xTaskGetHandle (xTaskGetHandle, funcdef_no=30, decl_uid=6190, cgraph_uid=31, symbol_order=52)

Modification phase of node xTaskGetHandle/52
xTaskGetHandle (const char * pcNameToQuery)
{
  uint32_t ulNewBASEPRI;
  struct TCB_t * pxTCB;
  UBaseType_t uxQueue;
  unsigned int _1;
  struct List_t * _2;
  struct List_t * pxDelayedTaskList.71_3;
  struct List_t * pxOverflowDelayedTaskList.72_4;

  <bb 2> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG uxQueue => 10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = strlen (pcNameToQuery_17(D));
  if (_1 > 9)
    goto <bb 3>; [67.00%]
  else
    goto <bb 5>; [33.00%]

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
" : "=r" ulNewBASEPRI_31 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_31

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();

  <bb 6> [local count: 353751]:
  # uxQueue_5 = PHI <10(5), uxQueue_19(18)>
  # DEBUG uxQueue => uxQueue_5
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxQueue_19 = uxQueue_5 + 4294967295;
  # DEBUG uxQueue => uxQueue_19
  # DEBUG BEGIN_STMT
  _2 = &pxReadyTasksLists[uxQueue_19];
  pxTCB_21 = prvSearchForNameWithinSingleList (_2, pcNameToQuery_17(D));
  # DEBUG pxTCB => pxTCB_21
  # DEBUG BEGIN_STMT
  if (pxTCB_21 != 0B)
    goto <bb 8>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 7> [local count: 334294]:
  # DEBUG BEGIN_STMT
  if (uxQueue_19 != 0)
    goto <bb 18>; [90.00%]
  else
    goto <bb 8>; [10.00%]

  <bb 18> [local count: 300865]:
  goto <bb 6>; [100.00%]

  <bb 8> [local count: 52886]:
  # pxTCB_15 = PHI <pxTCB_21(6), 0B(7)>
  # DEBUG BEGIN_STMT
  if (pxTCB_15 == 0B)
    goto <bb 9>; [17.43%]
  else
    goto <bb 10>; [82.57%]

  <bb 9> [local count: 9218]:
  # DEBUG BEGIN_STMT
  pxDelayedTaskList.71_3 ={v} pxDelayedTaskList;
  pxTCB_23 = prvSearchForNameWithinSingleList (pxDelayedTaskList.71_3, pcNameToQuery_17(D));
  # DEBUG pxTCB => pxTCB_23

  <bb 10> [local count: 52886]:
  # pxTCB_6 = PHI <pxTCB_15(8), pxTCB_23(9)>
  # DEBUG pxTCB => pxTCB_6
  # DEBUG BEGIN_STMT
  if (pxTCB_6 == 0B)
    goto <bb 11>; [17.43%]
  else
    goto <bb 12>; [82.57%]

  <bb 11> [local count: 9218]:
  # DEBUG BEGIN_STMT
  pxOverflowDelayedTaskList.72_4 ={v} pxOverflowDelayedTaskList;
  pxTCB_25 = prvSearchForNameWithinSingleList (pxOverflowDelayedTaskList.72_4, pcNameToQuery_17(D));
  # DEBUG pxTCB => pxTCB_25

  <bb 12> [local count: 52886]:
  # pxTCB_7 = PHI <pxTCB_6(10), pxTCB_25(11)>
  # DEBUG pxTCB => pxTCB_7
  # DEBUG BEGIN_STMT
  if (pxTCB_7 == 0B)
    goto <bb 13>; [17.43%]
  else
    goto <bb 14>; [82.57%]

  <bb 13> [local count: 9218]:
  # DEBUG BEGIN_STMT
  pxTCB_27 = prvSearchForNameWithinSingleList (&xSuspendedTaskList, pcNameToQuery_17(D));
  # DEBUG pxTCB => pxTCB_27

  <bb 14> [local count: 52886]:
  # pxTCB_8 = PHI <pxTCB_7(12), pxTCB_27(13)>
  # DEBUG pxTCB => pxTCB_8
  # DEBUG BEGIN_STMT
  if (pxTCB_8 == 0B)
    goto <bb 15>; [17.43%]
  else
    goto <bb 16>; [82.57%]

  <bb 15> [local count: 9218]:
  # DEBUG BEGIN_STMT
  pxTCB_29 = prvSearchForNameWithinSingleList (&xTasksWaitingTermination, pcNameToQuery_17(D));
  # DEBUG pxTCB => pxTCB_29

  <bb 16> [local count: 52886]:
  # pxTCB_9 = PHI <pxTCB_8(14), pxTCB_29(15)>
  # DEBUG pxTCB => pxTCB_9
  # DEBUG BEGIN_STMT
  xTaskResumeAll ();
  # DEBUG BEGIN_STMT
  return pxTCB_9;

}



;; Function xTaskCatchUpTicks (xTaskCatchUpTicks, funcdef_no=32, decl_uid=6259, cgraph_uid=33, symbol_order=54)

Modification phase of node xTaskCatchUpTicks/54
xTaskCatchUpTicks (TickType_t xTicksToCatchUp)
{
  uint32_t ulNewBASEPRI;
  BaseType_t xYieldOccurred;
  long unsigned int uxSchedulerSuspended.76_1;
  long unsigned int xPendedTicks.77_2;
  long unsigned int _3;

  <bb 2> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.76_1 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.76_1 != 0)
    goto <bb 3>; [67.00%]
  else
    goto <bb 5>; [33.00%]

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
" : "=r" ulNewBASEPRI_10 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_10

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  xPendedTicks.77_2 ={v} xPendedTicks;
  _3 = xPendedTicks.77_2 + xTicksToCatchUp_6(D);
  xPendedTicks ={v} _3;
  # DEBUG BEGIN_STMT
  xYieldOccurred_9 = xTaskResumeAll ();
  # DEBUG xYieldOccurred => xYieldOccurred_9
  # DEBUG BEGIN_STMT
  return xYieldOccurred_9;

}



;; Function xTaskAbortDelay (xTaskAbortDelay, funcdef_no=33, decl_uid=6152, cgraph_uid=34, symbol_order=55)

Modification phase of node xTaskAbortDelay/55
xTaskAbortDelay (struct tskTaskControlBlock * xTask)
{
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  BaseType_t xReturn;
  <unnamed type> _1;
  struct ListItem_t * _2;
  struct xLIST * _3;
  struct ListItem_t * _4;
  long unsigned int _5;
  long unsigned int uxTopReadyPriority.78_6;
  struct xLIST_ITEM * _7;
  struct xLIST_ITEM * _8;
  struct List_t * _9;
  long unsigned int _10;
  long unsigned int _11;
  struct TCB_t * pxCurrentTCB.79_12;
  long unsigned int _13;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTask_18(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTask_18(D) == 0B)
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
" : "=r" ulNewBASEPRI_37 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_37

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  _1 = eTaskGetState (xTask_18(D));
  if (_1 == 2)
    goto <bb 6>; [20.24%]
  else
    goto <bb 12>; [79.76%]

  <bb 6> [local count: 24974]:
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1
  # DEBUG BEGIN_STMT
  _2 = &MEM[(struct TCB_t *)xTask_18(D)].xStateListItem;
  uxListRemove (_2);
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct TCB_t *)xTask_18(D)].xEventListItem.pvContainer;
  if (_3 != 0B)
    goto <bb 7>; [53.47%]
  else
    goto <bb 8>; [46.53%]

  <bb 7> [local count: 13354]:
  # DEBUG BEGIN_STMT
  _4 = &MEM[(struct TCB_t *)xTask_18(D)].xEventListItem;
  uxListRemove (_4);
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTask_18(D)].ucDelayAborted = 1;

  <bb 8> [local count: 24974]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct TCB_t *)xTask_18(D)].uxPriority;
  uxTopReadyPriority.78_6 ={v} uxTopReadyPriority;
  if (_5 > uxTopReadyPriority.78_6)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 12487]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _5;

  <bb 10> [local count: 24974]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_28 = pxReadyTasksLists[_5].pxIndex;
  # DEBUG pxIndex => pxIndex_28
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTask_18(D)].xStateListItem.pxNext = pxIndex_28;
  # DEBUG BEGIN_STMT
  _7 = pxIndex_28->pxPrevious;
  MEM[(struct TCB_t *)xTask_18(D)].xStateListItem.pxPrevious = _7;
  # DEBUG BEGIN_STMT
  _8 = pxIndex_28->pxPrevious;
  _8->pxNext = _2;
  # DEBUG BEGIN_STMT
  pxIndex_28->pxPrevious = _2;
  # DEBUG BEGIN_STMT
  _9 = &pxReadyTasksLists[_5];
  MEM[(struct TCB_t *)xTask_18(D)].xStateListItem.pvContainer = _9;
  # DEBUG BEGIN_STMT
  _10 ={v} pxReadyTasksLists[_5].uxNumberOfItems;
  _11 = _10 + 1;
  pxReadyTasksLists[_5].uxNumberOfItems ={v} _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.79_12 ={v} pxCurrentTCB;
  _13 = pxCurrentTCB.79_12->uxPriority;
  if (_5 > _13)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 12487]:
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 1;

  <bb 12> [local count: 123389]:
  # xReturn_14 = PHI <1(11), 0(5), 1(10)>
  # DEBUG xReturn => xReturn_14
  # DEBUG BEGIN_STMT
  xTaskResumeAll ();
  # DEBUG BEGIN_STMT
  return xReturn_14;

}



;; Function vTaskSwitchContext (vTaskSwitchContext, funcdef_no=35, decl_uid=6279, cgraph_uid=36, symbol_order=57)

Modification phase of node vTaskSwitchContext/57
__attribute__((used))
vTaskSwitchContext ()
{
  UBaseType_t uxTopPriority;
  long unsigned int uxSchedulerSuspended.93_1;
  long unsigned int _2;
  struct ListItem_t * _3;
  struct xLIST_ITEM * _4;
  struct MiniListItem_t * _6;
  struct xLIST_ITEM * _8;
  struct ListItem_t * _9;
  void * _10;

  <bb 2> [local count: 441995]:
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.93_1 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.93_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 220997]:
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 1;
  goto <bb 12>; [100.00%]

  <bb 4> [local count: 220997]:
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxTopPriority_15 ={v} uxTopReadyPriority;
  # DEBUG uxTopPriority => uxTopPriority_15
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 1952255]:
  # DEBUG BEGIN_STMT
  if (uxTopPriority_11 == 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 6> [local count: 107374]:
  vTaskSwitchContext.part.0 ();

  <bb 7> [local count: 1844881]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxTopPriority_21 = uxTopPriority_11 + 4294967295;
  # DEBUG uxTopPriority => uxTopPriority_21

  <bb 8> [local count: 2065878]:
  # uxTopPriority_11 = PHI <uxTopPriority_15(4), uxTopPriority_21(7)>
  # DEBUG uxTopPriority => uxTopPriority_11
  # DEBUG BEGIN_STMT
  _2 ={v} pxReadyTasksLists[uxTopPriority_11].uxNumberOfItems;
  if (_2 == 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 113623]:
  # uxTopPriority_5 = PHI <uxTopPriority_11(8)>
  # DEBUG BEGIN_STMT
  # DEBUG D#6 => &pxReadyTasksLists[uxTopPriority_5]
  # DEBUG pxConstList => D#6
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct List_t *)&pxReadyTasksLists][uxTopPriority_5].pxIndex;
  _4 = _3->pxNext;
  MEM[(struct List_t *)&pxReadyTasksLists][uxTopPriority_5].pxIndex = _4;
  # DEBUG BEGIN_STMT
  _6 = &MEM[(struct List_t *)&pxReadyTasksLists][uxTopPriority_5].xListEnd;
  if (_4 == _6)
    goto <bb 10>; [30.00%]
  else
    goto <bb 11>; [70.00%]

  <bb 10> [local count: 34087]:
  # DEBUG BEGIN_STMT
  _8 = MEM[(struct ListItem_t *)_4].pxNext;
  MEM[(struct List_t *)&pxReadyTasksLists][uxTopPriority_5].pxIndex = _8;

  <bb 11> [local count: 113623]:
  # DEBUG BEGIN_STMT
  _9 = MEM[(struct List_t *)&pxReadyTasksLists][uxTopPriority_5].pxIndex;
  _10 = _9->pvOwner;
  pxCurrentTCB ={v} _10;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} uxTopPriority_5;

  <bb 12> [local count: 334621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function vTaskSuspend (vTaskSuspend, funcdef_no=17, decl_uid=6168, cgraph_uid=18, symbol_order=39)

Modification phase of node vTaskSuspend/39
vTaskSuspend (struct tskTaskControlBlock * xTaskToSuspend)
{
  uint32_t ulNewBASEPRI;
  BaseType_t x;
  struct ListItem_t * _1;
  struct xLIST * _2;
  struct ListItem_t * _3;
  unsigned char _4;
  long int xSchedulerRunning.47_5;
  struct TCB_t * pxCurrentTCB.48_6;
  long int xSchedulerRunning.49_7;
  long unsigned int uxSchedulerSuspended.50_8;
  long unsigned int _9;
  long unsigned int uxCurrentNumberOfTasks.51_10;
  struct TCB_t * iftmp.46_12;
  struct TCB_t * iftmp.46_21;

  <bb 2> [local count: 1431653]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  if (xTaskToSuspend_20(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 429496]:
  iftmp.46_21 ={v} pxCurrentTCB;

  <bb 4> [local count: 1431653]:
  # iftmp.46_12 = PHI <iftmp.46_21(3), xTaskToSuspend_20(D)(2)>
  # DEBUG pxTCB => iftmp.46_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &iftmp.46_12->xStateListItem;
  uxListRemove (_1);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = iftmp.46_12->xEventListItem.pvContainer;
  if (_2 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 765505]:
  # DEBUG BEGIN_STMT
  _3 = &iftmp.46_12->xEventListItem;
  uxListRemove (_3);

  <bb 6> [local count: 1431653]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vListInsertEnd (&xSuspendedTaskList, _1);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG x => 0
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 24598407]:
  # DEBUG BEGIN_STMT
  _4 ={v} iftmp.46_12->ucNotifyState[0];
  if (_4 == 1)
    goto <bb 8>; [67.00%]
  else
    goto <bb 24>; [33.00%]

  <bb 24> [local count: 8117474]:
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 16480933]:
  # DEBUG BEGIN_STMT
  iftmp.46_12->ucNotifyState[0] ={v} 0;

  <bb 9> [local count: 17912586]:
  # x_14 = PHI <0(6), 1(8)>

  <bb 10> [local count: 26030061]:
  # x_11 = PHI <x_14(9), 1(24)>
  # DEBUG x => x_11
  # DEBUG BEGIN_STMT
  if (x_11 == 0)
    goto <bb 7>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 11> [local count: 1431653]:
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  xSchedulerRunning.47_5 ={v} xSchedulerRunning;
  if (xSchedulerRunning.47_5 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 13>; [67.00%]

  <bb 12> [local count: 472446]:
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  prvResetNextTaskUnblockTime ();
  # DEBUG BEGIN_STMT
  vPortExitCritical ();

  <bb 13> [local count: 1431653]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.48_6 ={v} pxCurrentTCB;
  if (pxCurrentTCB.48_6 == iftmp.46_12)
    goto <bb 14>; [30.00%]
  else
    goto <bb 22>; [70.00%]

  <bb 14> [local count: 429496]:
  # DEBUG BEGIN_STMT
  xSchedulerRunning.49_7 ={v} xSchedulerRunning;
  if (xSchedulerRunning.49_7 != 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 15> [local count: 214748]:
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.50_8 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.50_8 != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 16> [local count: 107374]:
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
" : "=r" ulNewBASEPRI_36 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_36

  <bb 17> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 23> [local count: 1073741824]:
  goto <bb 17>; [100.00%]

  <bb 18> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT
  goto <bb 22>; [100.00%]

  <bb 19> [local count: 214748]:
  # DEBUG BEGIN_STMT
  _9 ={v} xSuspendedTaskList.uxNumberOfItems;
  uxCurrentNumberOfTasks.51_10 ={v} uxCurrentNumberOfTasks;
  if (_9 == uxCurrentNumberOfTasks.51_10)
    goto <bb 20>; [51.12%]
  else
    goto <bb 21>; [48.88%]

  <bb 20> [local count: 109779]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB ={v} 0B;
  goto <bb 22>; [100.00%]

  <bb 21> [local count: 104969]:
  # DEBUG BEGIN_STMT
  vTaskSwitchContext ();

  <bb 22> [local count: 1324279]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function vTaskPlaceOnEventList (vTaskPlaceOnEventList, funcdef_no=36, decl_uid=6264, cgraph_uid=37, symbol_order=58)

Modification phase of node vTaskPlaceOnEventList/58
vTaskPlaceOnEventList (struct List_t * const pxEventList, const TickType_t xTicksToWait)
{
  uint32_t ulNewBASEPRI;
  struct TCB_t * pxCurrentTCB.94_1;
  struct ListItem_t * _2;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  if (pxEventList_3(D) == 0B)
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
" : "=r" ulNewBASEPRI_8 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_8

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.94_1 ={v} pxCurrentTCB;
  _2 = &pxCurrentTCB.94_1->xEventListItem;
  vListInsert (pxEventList_3(D), _2);
  # DEBUG BEGIN_STMT
  prvAddCurrentTaskToDelayedList (xTicksToWait_6(D), 1);
  return;

}



;; Function vTaskPlaceOnUnorderedEventList (vTaskPlaceOnUnorderedEventList, funcdef_no=37, decl_uid=6268, cgraph_uid=38, symbol_order=59)

Modification phase of node vTaskPlaceOnUnorderedEventList/59
vTaskPlaceOnUnorderedEventList (struct List_t * pxEventList, const TickType_t xItemValue, const TickType_t xTicksToWait)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  long unsigned int uxSchedulerSuspended.95_1;
  struct TCB_t * pxCurrentTCB.96_2;
  long unsigned int _3;
  struct TCB_t * pxCurrentTCB.97_4;
  struct TCB_t * pxCurrentTCB.98_5;
  struct xLIST_ITEM * _6;
  struct TCB_t * pxCurrentTCB.99_7;
  struct xLIST_ITEM * _8;
  struct ListItem_t * _9;
  struct TCB_t * pxCurrentTCB.100_10;
  struct ListItem_t * _11;
  struct TCB_t * pxCurrentTCB.101_12;
  long unsigned int _13;
  long unsigned int _14;

  <bb 2> [local count: 228942]:
  # DEBUG BEGIN_STMT
  if (pxEventList_15(D) == 0B)
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
" : "=r" ulNewBASEPRI_28 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_28

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
  uxSchedulerSuspended.95_1 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.95_1 == 0)
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
" : "=r" ulNewBASEPRI_29 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_29

  <bb 7> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.96_2 ={v} pxCurrentTCB;
  _3 = xItemValue_17(D) | 2147483648;
  pxCurrentTCB.96_2->xEventListItem.xItemValue = _3;
  # DEBUG BEGIN_STMT
  pxIndex_19 = pxEventList_15(D)->pxIndex;
  # DEBUG pxIndex => pxIndex_19
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.97_4 ={v} pxCurrentTCB;
  pxCurrentTCB.97_4->xEventListItem.pxNext = pxIndex_19;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.98_5 ={v} pxCurrentTCB;
  _6 = pxIndex_19->pxPrevious;
  pxCurrentTCB.98_5->xEventListItem.pxPrevious = _6;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.99_7 ={v} pxCurrentTCB;
  _8 = pxIndex_19->pxPrevious;
  _9 = &pxCurrentTCB.99_7->xEventListItem;
  _8->pxNext = _9;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.100_10 ={v} pxCurrentTCB;
  _11 = &pxCurrentTCB.100_10->xEventListItem;
  pxIndex_19->pxPrevious = _11;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.101_12 ={v} pxCurrentTCB;
  pxCurrentTCB.101_12->xEventListItem.pvContainer = pxEventList_15(D);
  # DEBUG BEGIN_STMT
  _13 ={v} pxEventList_15(D)->uxNumberOfItems;
  _14 = _13 + 1;
  pxEventList_15(D)->uxNumberOfItems ={v} _14;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  prvAddCurrentTaskToDelayedList (xTicksToWait_26(D), 1);
  return;

}



;; Function vTaskPlaceOnEventListRestricted (vTaskPlaceOnEventListRestricted, funcdef_no=38, decl_uid=6272, cgraph_uid=39, symbol_order=60)

Modification phase of node vTaskPlaceOnEventListRestricted/60
vTaskPlaceOnEventListRestricted (struct List_t * const pxEventList, TickType_t xTicksToWait, const BaseType_t xWaitIndefinitely)
{
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  struct TCB_t * pxCurrentTCB.102_1;
  struct TCB_t * pxCurrentTCB.103_2;
  struct xLIST_ITEM * _3;
  struct TCB_t * pxCurrentTCB.104_4;
  struct xLIST_ITEM * _5;
  struct ListItem_t * _6;
  struct TCB_t * pxCurrentTCB.105_7;
  struct ListItem_t * _8;
  struct TCB_t * pxCurrentTCB.106_9;
  long unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  if (pxEventList_13(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

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
" : "=r" ulNewBASEPRI_25 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_25

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_15 = pxEventList_13(D)->pxIndex;
  # DEBUG pxIndex => pxIndex_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.102_1 ={v} pxCurrentTCB;
  pxCurrentTCB.102_1->xEventListItem.pxNext = pxIndex_15;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.103_2 ={v} pxCurrentTCB;
  _3 = pxIndex_15->pxPrevious;
  pxCurrentTCB.103_2->xEventListItem.pxPrevious = _3;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.104_4 ={v} pxCurrentTCB;
  _5 = pxIndex_15->pxPrevious;
  _6 = &pxCurrentTCB.104_4->xEventListItem;
  _5->pxNext = _6;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.105_7 ={v} pxCurrentTCB;
  _8 = &pxCurrentTCB.105_7->xEventListItem;
  pxIndex_15->pxPrevious = _8;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.106_9 ={v} pxCurrentTCB;
  pxCurrentTCB.106_9->xEventListItem.pvContainer = pxEventList_13(D);
  # DEBUG BEGIN_STMT
  _10 ={v} pxEventList_13(D)->uxNumberOfItems;
  _11 = _10 + 1;
  pxEventList_13(D)->uxNumberOfItems ={v} _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xWaitIndefinitely_22(D) != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 125270]:
  # DEBUG BEGIN_STMT
  # DEBUG xTicksToWait => 4294967295

  <bb 7> [local count: 250539]:
  # xTicksToWait_12 = PHI <xTicksToWait_23(D)(5), 4294967295(6)>
  # DEBUG xTicksToWait => xTicksToWait_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  prvAddCurrentTaskToDelayedList (xTicksToWait_12, xWaitIndefinitely_22(D));
  return;

}



;; Function xTaskRemoveFromEventList (xTaskRemoveFromEventList, funcdef_no=39, decl_uid=6274, cgraph_uid=40, symbol_order=61)

Modification phase of node xTaskRemoveFromEventList/61
xTaskRemoveFromEventList (const struct List_t * const pxEventList)
{
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  struct ListItem_t * const pxIndex;
  struct List_t * const pxList;
  struct List_t * const pxList;
  BaseType_t xReturn;
  struct TCB_t * pxUnblockedTCB;
  struct xLIST_ITEM * _1;
  struct xLIST_ITEM * _2;
  struct xLIST_ITEM * _3;
  struct ListItem_t * _4;
  struct ListItem_t * _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int uxSchedulerSuspended.107_8;
  struct xLIST_ITEM * _9;
  struct xLIST_ITEM * _10;
  struct xLIST_ITEM * _11;
  struct ListItem_t * _12;
  struct ListItem_t * _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int uxTopReadyPriority.108_17;
  struct xLIST_ITEM * _18;
  struct xLIST_ITEM * _19;
  struct List_t * _20;
  long unsigned int _21;
  long unsigned int _22;
  struct xLIST_ITEM * _23;
  struct xLIST_ITEM * _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  struct TCB_t * pxCurrentTCB.109_28;
  long unsigned int _29;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pxEventList_37(D)->xListEnd.pxNext;
  pxUnblockedTCB_38 = _1->pvOwner;
  # DEBUG pxUnblockedTCB => pxUnblockedTCB_38
  # DEBUG BEGIN_STMT
  if (pxUnblockedTCB_38 == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

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
" : "=r" ulNewBASEPRI_66 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_66

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxList_39 = pxUnblockedTCB_38->xEventListItem.pvContainer;
  # DEBUG pxList => pxList_39
  # DEBUG BEGIN_STMT
  _2 = pxUnblockedTCB_38->xEventListItem.pxNext;
  _3 = pxUnblockedTCB_38->xEventListItem.pxPrevious;
  _2->pxPrevious = _3;
  # DEBUG BEGIN_STMT
  _3->pxNext = _2;
  # DEBUG BEGIN_STMT
  _4 = pxList_39->pxIndex;
  _5 = &pxUnblockedTCB_38->xEventListItem;
  if (_4 == _5)
    goto <bb 6>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 6> [local count: 75162]:
  # DEBUG BEGIN_STMT
  pxList_39->pxIndex = _3;

  <bb 7> [local count: 250539]:
  # DEBUG BEGIN_STMT
  pxUnblockedTCB_38->xEventListItem.pvContainer = 0B;
  # DEBUG BEGIN_STMT
  _6 ={v} pxList_39->uxNumberOfItems;
  _7 = _6 + 4294967295;
  pxList_39->uxNumberOfItems ={v} _7;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.107_8 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.107_8 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 8> [local count: 125270]:
  # DEBUG BEGIN_STMT
  pxList_52 = pxUnblockedTCB_38->xStateListItem.pvContainer;
  # DEBUG pxList => pxList_52
  # DEBUG BEGIN_STMT
  _9 = pxUnblockedTCB_38->xStateListItem.pxNext;
  _10 = pxUnblockedTCB_38->xStateListItem.pxPrevious;
  _9->pxPrevious = _10;
  # DEBUG BEGIN_STMT
  _11 = pxUnblockedTCB_38->xStateListItem.pxPrevious;
  _11->pxNext = _9;
  # DEBUG BEGIN_STMT
  _12 = pxList_52->pxIndex;
  _13 = &pxUnblockedTCB_38->xStateListItem;
  if (_12 == _13)
    goto <bb 9>; [30.00%]
  else
    goto <bb 10>; [70.00%]

  <bb 9> [local count: 37581]:
  # DEBUG BEGIN_STMT
  pxList_52->pxIndex = _11;

  <bb 10> [local count: 125270]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 ={v} pxList_52->uxNumberOfItems;
  _15 = _14 + 4294967295;
  pxList_52->uxNumberOfItems ={v} _15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = pxUnblockedTCB_38->uxPriority;
  uxTopReadyPriority.108_17 ={v} uxTopReadyPriority;
  if (_16 > uxTopReadyPriority.108_17)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 62635]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _16;

  <bb 12> [local count: 125270]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_58 = pxReadyTasksLists[_16].pxIndex;
  # DEBUG pxIndex => pxIndex_58
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxUnblockedTCB_38->xStateListItem.pxNext = pxIndex_58;
  # DEBUG BEGIN_STMT
  _18 = pxIndex_58->pxPrevious;
  pxUnblockedTCB_38->xStateListItem.pxPrevious = _18;
  # DEBUG BEGIN_STMT
  _19 = pxIndex_58->pxPrevious;
  _19->pxNext = _13;
  # DEBUG BEGIN_STMT
  pxIndex_58->pxPrevious = _13;
  # DEBUG BEGIN_STMT
  _20 = &pxReadyTasksLists[_16];
  pxUnblockedTCB_38->xStateListItem.pvContainer = _20;
  # DEBUG BEGIN_STMT
  _21 ={v} pxReadyTasksLists[_16].uxNumberOfItems;
  _22 = _21 + 1;
  pxReadyTasksLists[_16].uxNumberOfItems ={v} _22;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 125270]:
  # DEBUG BEGIN_STMT
  pxIndex_45 = xPendingReadyList.pxIndex;
  # DEBUG pxIndex => pxIndex_45
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxUnblockedTCB_38->xEventListItem.pxNext = pxIndex_45;
  # DEBUG BEGIN_STMT
  _23 = pxIndex_45->pxPrevious;
  pxUnblockedTCB_38->xEventListItem.pxPrevious = _23;
  # DEBUG BEGIN_STMT
  _24 = pxIndex_45->pxPrevious;
  _24->pxNext = _5;
  # DEBUG BEGIN_STMT
  pxIndex_45->pxPrevious = _5;
  # DEBUG BEGIN_STMT
  pxUnblockedTCB_38->xEventListItem.pvContainer = &xPendingReadyList;
  # DEBUG BEGIN_STMT
  _25 ={v} xPendingReadyList.uxNumberOfItems;
  _26 = _25 + 1;
  xPendingReadyList.uxNumberOfItems ={v} _26;

  <bb 14> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _27 = pxUnblockedTCB_38->uxPriority;
  pxCurrentTCB.109_28 ={v} pxCurrentTCB;
  _29 = pxCurrentTCB.109_28->uxPriority;
  if (_27 > _29)
    goto <bb 15>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 15> [local count: 125270]:
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 1;

  <bb 16> [local count: 250539]:
  # xReturn_30 = PHI <1(15), 0(14)>
  # DEBUG xReturn => xReturn_30
  # DEBUG BEGIN_STMT
  return xReturn_30;

}



;; Function vTaskRemoveFromUnorderedEventList (vTaskRemoveFromUnorderedEventList, funcdef_no=40, decl_uid=6277, cgraph_uid=41, symbol_order=62)

Modification phase of node vTaskRemoveFromUnorderedEventList/62
vTaskRemoveFromUnorderedEventList (struct ListItem_t * pxEventListItem, const TickType_t xItemValue)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  struct List_t * const pxList;
  struct List_t * const pxList;
  struct TCB_t * pxUnblockedTCB;
  long unsigned int uxSchedulerSuspended.110_1;
  long unsigned int _2;
  struct xLIST_ITEM * _3;
  struct xLIST_ITEM * _4;
  struct xLIST_ITEM * _5;
  struct ListItem_t * _6;
  long unsigned int _7;
  long unsigned int _8;
  struct xLIST_ITEM * _9;
  struct xLIST_ITEM * _10;
  struct xLIST_ITEM * _11;
  struct ListItem_t * _12;
  struct ListItem_t * _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int uxTopReadyPriority.111_17;
  struct xLIST_ITEM * _18;
  struct xLIST_ITEM * _19;
  struct List_t * _20;
  long unsigned int _21;
  long unsigned int _22;
  struct TCB_t * pxCurrentTCB.112_23;
  long unsigned int _24;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.110_1 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.110_1 == 0)
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
" : "=r" ulNewBASEPRI_54 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_54

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = xItemValue_30(D) | 2147483648;
  pxEventListItem_31(D)->xItemValue = _2;
  # DEBUG BEGIN_STMT
  pxUnblockedTCB_33 = pxEventListItem_31(D)->pvOwner;
  # DEBUG pxUnblockedTCB => pxUnblockedTCB_33
  # DEBUG BEGIN_STMT
  if (pxUnblockedTCB_33 == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 6> [local count: 32212]:
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
" : "=r" ulNewBASEPRI_55 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_55

  <bb 7> [local count: 322122547]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 322122547]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 75162]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxList_34 = pxEventListItem_31(D)->pvContainer;
  # DEBUG pxList => pxList_34
  # DEBUG BEGIN_STMT
  _3 = pxEventListItem_31(D)->pxNext;
  _4 = pxEventListItem_31(D)->pxPrevious;
  _3->pxPrevious = _4;
  # DEBUG BEGIN_STMT
  _5 = pxEventListItem_31(D)->pxPrevious;
  _5->pxNext = _3;
  # DEBUG BEGIN_STMT
  _6 = pxList_34->pxIndex;
  if (_6 == pxEventListItem_31(D))
    goto <bb 9>; [30.00%]
  else
    goto <bb 10>; [70.00%]

  <bb 9> [local count: 22549]:
  # DEBUG BEGIN_STMT
  pxList_34->pxIndex = _5;

  <bb 10> [local count: 75162]:
  # DEBUG BEGIN_STMT
  pxEventListItem_31(D)->pvContainer = 0B;
  # DEBUG BEGIN_STMT
  _7 ={v} pxList_34->uxNumberOfItems;
  _8 = _7 + 4294967295;
  pxList_34->uxNumberOfItems ={v} _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxList_40 = pxUnblockedTCB_33->xStateListItem.pvContainer;
  # DEBUG pxList => pxList_40
  # DEBUG BEGIN_STMT
  _9 = pxUnblockedTCB_33->xStateListItem.pxNext;
  _10 = pxUnblockedTCB_33->xStateListItem.pxPrevious;
  _9->pxPrevious = _10;
  # DEBUG BEGIN_STMT
  _11 = pxUnblockedTCB_33->xStateListItem.pxPrevious;
  _11->pxNext = _9;
  # DEBUG BEGIN_STMT
  _12 = pxList_40->pxIndex;
  _13 = &pxUnblockedTCB_33->xStateListItem;
  if (_12 == _13)
    goto <bb 11>; [30.00%]
  else
    goto <bb 12>; [70.00%]

  <bb 11> [local count: 22549]:
  # DEBUG BEGIN_STMT
  pxList_40->pxIndex = _11;

  <bb 12> [local count: 75162]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 ={v} pxList_40->uxNumberOfItems;
  _15 = _14 + 4294967295;
  pxList_40->uxNumberOfItems ={v} _15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = pxUnblockedTCB_33->uxPriority;
  uxTopReadyPriority.111_17 ={v} uxTopReadyPriority;
  if (_16 > uxTopReadyPriority.111_17)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 37581]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _16;

  <bb 14> [local count: 75162]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_46 = pxReadyTasksLists[_16].pxIndex;
  # DEBUG pxIndex => pxIndex_46
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxUnblockedTCB_33->xStateListItem.pxNext = pxIndex_46;
  # DEBUG BEGIN_STMT
  _18 = pxIndex_46->pxPrevious;
  pxUnblockedTCB_33->xStateListItem.pxPrevious = _18;
  # DEBUG BEGIN_STMT
  _19 = pxIndex_46->pxPrevious;
  _19->pxNext = _13;
  # DEBUG BEGIN_STMT
  pxIndex_46->pxPrevious = _13;
  # DEBUG BEGIN_STMT
  _20 = &pxReadyTasksLists[_16];
  pxUnblockedTCB_33->xStateListItem.pvContainer = _20;
  # DEBUG BEGIN_STMT
  _21 ={v} pxReadyTasksLists[_16].uxNumberOfItems;
  _22 = _21 + 1;
  pxReadyTasksLists[_16].uxNumberOfItems ={v} _22;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.112_23 ={v} pxCurrentTCB;
  _24 = pxCurrentTCB.112_23->uxPriority;
  if (_16 > _24)
    goto <bb 15>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 15> [local count: 37581]:
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 1;

  <bb 16> [local count: 75162]:
  return;

}



;; Function vTaskSetTimeOutState (vTaskSetTimeOutState, funcdef_no=41, decl_uid=6254, cgraph_uid=42, symbol_order=63)

Modification phase of node vTaskSetTimeOutState/63
vTaskSetTimeOutState (struct TimeOut_t * const pxTimeOut)
{
  uint32_t ulNewBASEPRI;
  long int xNumOfOverflows.113_1;
  long unsigned int xTickCount.114_2;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  if (pxTimeOut_3(D) == 0B)
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
" : "=r" ulNewBASEPRI_9 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_9

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  xNumOfOverflows.113_1 ={v} xNumOfOverflows;
  pxTimeOut_3(D)->xOverflowCount = xNumOfOverflows.113_1;
  # DEBUG BEGIN_STMT
  xTickCount.114_2 ={v} xTickCount;
  pxTimeOut_3(D)->xTimeOnEntering = xTickCount.114_2;
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  return;

}



;; Function vTaskInternalSetTimeOutState (vTaskInternalSetTimeOutState, funcdef_no=42, decl_uid=6307, cgraph_uid=43, symbol_order=64)

Modification phase of node vTaskInternalSetTimeOutState/64
vTaskInternalSetTimeOutState (struct TimeOut_t * const pxTimeOut)
{
  long int xNumOfOverflows.115_1;
  long unsigned int xTickCount.116_2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  xNumOfOverflows.115_1 ={v} xNumOfOverflows;
  pxTimeOut_4(D)->xOverflowCount = xNumOfOverflows.115_1;
  # DEBUG BEGIN_STMT
  xTickCount.116_2 ={v} xTickCount;
  pxTimeOut_4(D)->xTimeOnEntering = xTickCount.116_2;
  return;

}



;; Function xTaskCheckForTimeOut (xTaskCheckForTimeOut, funcdef_no=43, decl_uid=6257, cgraph_uid=44, symbol_order=65)

Modification phase of node xTaskCheckForTimeOut/65
xTaskCheckForTimeOut (struct TimeOut_t * const pxTimeOut, TickType_t * const pxTicksToWait)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  const TickType_t xElapsedTime;
  const TickType_t xConstTickCount;
  BaseType_t xReturn;
  long unsigned int _1;
  struct TCB_t * pxCurrentTCB.117_2;
  unsigned char _3;
  struct TCB_t * pxCurrentTCB.118_4;
  long unsigned int _5;
  long int _6;
  long int xNumOfOverflows.119_7;
  long unsigned int _8;
  long unsigned int _17;

  <bb 2> [local count: 329661]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pxTimeOut_11(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 3> [local count: 98898]:
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
" : "=r" ulNewBASEPRI_24 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_24

  <bb 4> [local count: 988985746]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 988985746]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pxTicksToWait_12(D) == 0B)
    goto <bb 6>; [46.53%]
  else
    goto <bb 8>; [53.47%]

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
" : "=r" ulNewBASEPRI_25 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_25

  <bb 7> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 19> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  xConstTickCount_15 ={v} xTickCount;
  # DEBUG xConstTickCount => xConstTickCount_15
  # DEBUG BEGIN_STMT
  _1 = pxTimeOut_11(D)->xTimeOnEntering;
  xElapsedTime_16 = xConstTickCount_15 - _1;
  # DEBUG xElapsedTime => xElapsedTime_16
  # DEBUG BEGIN_STMT
  pxCurrentTCB.117_2 ={v} pxCurrentTCB;
  _3 = pxCurrentTCB.117_2->ucDelayAborted;
  if (_3 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 61694]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.118_4 ={v} pxCurrentTCB;
  pxCurrentTCB.118_4->ucDelayAborted = 0;
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1
  goto <bb 17>; [100.00%]

  <bb 10> [local count: 61694]:
  # DEBUG BEGIN_STMT
  _5 = *pxTicksToWait_12(D);
  if (_5 == 4294967295)
    goto <bb 17>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 11> [local count: 40718]:
  # DEBUG BEGIN_STMT
  _6 = pxTimeOut_11(D)->xOverflowCount;
  xNumOfOverflows.119_7 ={v} xNumOfOverflows;
  if (_6 != xNumOfOverflows.119_7)
    goto <bb 12>; [66.00%]
  else
    goto <bb 14>; [34.00%]

  <bb 12> [local count: 26874]:
  if (_1 <= xConstTickCount_15)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 13437]:
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1
  # DEBUG BEGIN_STMT
  *pxTicksToWait_12(D) = 0;
  goto <bb 17>; [100.00%]

  <bb 14> [local count: 27281]:
  # DEBUG BEGIN_STMT
  if (_5 > xElapsedTime_16)
    goto <bb 15>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 15> [local count: 9003]:
  # DEBUG BEGIN_STMT
  _17 = _1 - xConstTickCount_15;
  _8 = _5 + _17;
  *pxTicksToWait_12(D) = _8;
  # DEBUG BEGIN_STMT
  vTaskInternalSetTimeOutState (pxTimeOut_11(D));
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 0
  goto <bb 17>; [100.00%]

  <bb 16> [local count: 18278]:
  # DEBUG BEGIN_STMT
  *pxTicksToWait_12(D) = 0;
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 17> [local count: 123389]:
  # xReturn_9 = PHI <1(9), 0(10), 1(13), 0(15), 1(16)>
  # DEBUG xReturn => xReturn_9
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  return xReturn_9;

}



;; Function vTaskMissedYield (vTaskMissedYield, funcdef_no=44, decl_uid=6285, cgraph_uid=45, symbol_order=66)

Modification phase of node vTaskMissedYield/66
vTaskMissedYield ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 1;
  return;

}



;; Function uxTaskGetTaskNumber (uxTaskGetTaskNumber, funcdef_no=45, decl_uid=6296, cgraph_uid=46, symbol_order=67)

Modification phase of node uxTaskGetTaskNumber/67
uxTaskGetTaskNumber (struct tskTaskControlBlock * xTask)
{
  UBaseType_t uxReturn;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTask_2(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTask_2(D)
  # DEBUG BEGIN_STMT
  uxReturn_4 = MEM[(const struct TCB_t *)xTask_2(D)].uxTaskNumber;
  # DEBUG uxReturn => uxReturn_4

  <bb 4> [local count: 1073741824]:
  # uxReturn_1 = PHI <uxReturn_4(3), 0(2)>
  # DEBUG uxReturn => uxReturn_1
  # DEBUG BEGIN_STMT
  return uxReturn_1;

}



;; Function vTaskSetTaskNumber (vTaskSetTaskNumber, funcdef_no=46, decl_uid=6299, cgraph_uid=47, symbol_order=68)

Modification phase of node vTaskSetTaskNumber/68
vTaskSetTaskNumber (struct tskTaskControlBlock * xTask, const UBaseType_t uxHandle)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTask_2(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTask_2(D)
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTask_2(D)].uxTaskNumber = uxHandle_4(D);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function vTaskSetThreadLocalStoragePointer (vTaskSetThreadLocalStoragePointer, funcdef_no=48, decl_uid=6198, cgraph_uid=49, symbol_order=70)

Modification phase of node vTaskSetThreadLocalStoragePointer/70
vTaskSetThreadLocalStoragePointer (struct tskTaskControlBlock * xTaskToSet, BaseType_t xIndex, void * pvValue)
{
  uint32_t ulNewBASEPRI;
  struct TCB_t * iftmp.120_1;
  struct TCB_t * iftmp.120_6;

  <bb 2> [local count: 872959]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xIndex_3(D) <= 1)
    goto <bb 3>; [41.00%]
  else
    goto <bb 9>; [59.00%]

  <bb 3> [local count: 357913]:
  # DEBUG BEGIN_STMT
  if (xTaskToSet_5(D) == 0B)
    goto <bb 4>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 4> [local count: 107374]:
  iftmp.120_6 ={v} pxCurrentTCB;

  <bb 5> [local count: 357913]:
  # iftmp.120_1 = PHI <iftmp.120_6(4), xTaskToSet_5(D)(3)>
  # DEBUG pxTCB => iftmp.120_1
  # DEBUG BEGIN_STMT
  if (iftmp.120_1 == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 8>; [70.00%]

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
" : "=r" ulNewBASEPRI_9 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_9

  <bb 7> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.120_1->pvThreadLocalStoragePointers[xIndex_3(D)] = pvValue_7(D);

  <bb 9> [local count: 765585]:
  return;

}



;; Function pvTaskGetThreadLocalStoragePointer (pvTaskGetThreadLocalStoragePointer, funcdef_no=49, decl_uid=6201, cgraph_uid=50, symbol_order=71)

Modification phase of node pvTaskGetThreadLocalStoragePointer/71
pvTaskGetThreadLocalStoragePointer (struct tskTaskControlBlock * xTaskToQuery, BaseType_t xIndex)
{
  void * pvReturn;
  struct TCB_t * iftmp.121_2;
  struct TCB_t * iftmp.121_6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG pvReturn => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xIndex_3(D) <= 1)
    goto <bb 3>; [62.98%]
  else
    goto <bb 6>; [37.02%]

  <bb 3> [local count: 676242602]:
  # DEBUG BEGIN_STMT
  if (xTaskToQuery_4(D) == 0B)
    goto <bb 4>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 4> [local count: 202872780]:
  iftmp.121_6 ={v} pxCurrentTCB;

  <bb 5> [local count: 676242602]:
  # iftmp.121_2 = PHI <iftmp.121_6(4), xTaskToQuery_4(D)(3)>
  # DEBUG pxTCB => iftmp.121_2
  # DEBUG BEGIN_STMT
  pvReturn_7 = iftmp.121_2->pvThreadLocalStoragePointers[xIndex_3(D)];
  # DEBUG pvReturn => pvReturn_7

  <bb 6> [local count: 1073741824]:
  # pvReturn_1 = PHI <pvReturn_7(5), 0B(2)>
  # DEBUG pvReturn => pvReturn_1
  # DEBUG BEGIN_STMT
  return pvReturn_1;

}



;; Function vTaskGetInfo (vTaskGetInfo, funcdef_no=52, decl_uid=6163, cgraph_uid=53, symbol_order=74)

Modification phase of node vTaskGetInfo/74
vTaskGetInfo (struct tskTaskControlBlock * xTask, struct TaskStatus_t * pxTaskStatus, BaseType_t xGetFreeStackSpace, eTaskState eState)
{
  char * _1;
  long unsigned int _2;
  StackType_t * _3;
  long unsigned int _4;
  long unsigned int _5;
  struct TCB_t * pxCurrentTCB.123_6;
  struct xLIST * _7;
  <unnamed type> _8;
  StackType_t * _9;
  short unsigned int _10;
  struct TCB_t * iftmp.122_11;
  struct TCB_t * iftmp.122_17;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTask_15(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  iftmp.122_17 ={v} pxCurrentTCB;

  <bb 4> [local count: 1073741823]:
  # iftmp.122_11 = PHI <iftmp.122_17(3), xTask_15(D)(2)>
  # DEBUG pxTCB => iftmp.122_11
  # DEBUG BEGIN_STMT
  pxTaskStatus_18(D)->xHandle = iftmp.122_11;
  # DEBUG BEGIN_STMT
  _1 = &iftmp.122_11->pcTaskName[0];
  pxTaskStatus_18(D)->pcTaskName = _1;
  # DEBUG BEGIN_STMT
  _2 = iftmp.122_11->uxPriority;
  pxTaskStatus_18(D)->uxCurrentPriority = _2;
  # DEBUG BEGIN_STMT
  _3 = iftmp.122_11->pxStack;
  pxTaskStatus_18(D)->pxStackBase = _3;
  # DEBUG BEGIN_STMT
  _4 = iftmp.122_11->uxTCBNumber;
  pxTaskStatus_18(D)->xTaskNumber = _4;
  # DEBUG BEGIN_STMT
  _5 = iftmp.122_11->uxBasePriority;
  pxTaskStatus_18(D)->uxBasePriority = _5;
  # DEBUG BEGIN_STMT
  pxTaskStatus_18(D)->ulRunTimeCounter = 0;
  # DEBUG BEGIN_STMT
  if (eState_26(D) != 5)
    goto <bb 5>; [79.76%]
  else
    goto <bb 11>; [20.24%]

  <bb 5> [local count: 856416478]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.123_6 ={v} pxCurrentTCB;
  if (pxCurrentTCB.123_6 == iftmp.122_11)
    goto <bb 6>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 6> [local count: 256924943]:
  # DEBUG BEGIN_STMT
  pxTaskStatus_18(D)->eCurrentState = 0;
  goto <bb 12>; [100.00%]

  <bb 7> [local count: 599491536]:
  # DEBUG BEGIN_STMT
  pxTaskStatus_18(D)->eCurrentState = eState_26(D);
  # DEBUG BEGIN_STMT
  if (eState_26(D) == 3)
    goto <bb 8>; [20.24%]
  else
    goto <bb 12>; [79.76%]

  <bb 8> [local count: 121337087]:
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  _7 = iftmp.122_11->xEventListItem.pvContainer;
  if (_7 != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 84935961]:
  # DEBUG BEGIN_STMT
  pxTaskStatus_18(D)->eCurrentState = 2;

  <bb 10> [local count: 121337087]:
  # DEBUG BEGIN_STMT
  xTaskResumeAll ();
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  _8 = eTaskGetState (iftmp.122_11);
  pxTaskStatus_18(D)->eCurrentState = _8;

  <bb 12> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (xGetFreeStackSpace_34(D) != 0)
    goto <bb 13>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 13> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _9 = iftmp.122_11->pxStack;
  _10 = prvTaskCheckFreeStackSpace (_9);
  pxTaskStatus_18(D)->usStackHighWaterMark = _10;
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 719407024]:
  # DEBUG BEGIN_STMT
  pxTaskStatus_18(D)->usStackHighWaterMark = 0;

  <bb 15> [local count: 1073741824]:
  return;

}



;; Function prvListTasksWithinSingleList (prvListTasksWithinSingleList, funcdef_no=53, decl_uid=6965, cgraph_uid=54, symbol_order=75)

Modification phase of node prvListTasksWithinSingleList/75
Adjusting mask for param 2 to 0x7
Setting value range of param 2 [1, 4]
prvListTasksWithinSingleList (struct TaskStatus_t * pxTaskStatusArray, struct List_t * pxList, eTaskState eState)
{
  UBaseType_t uxTask;
  long unsigned int _1;

  <bb 2> [local count: 236223200]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG uxTask => 0
  # DEBUG BEGIN_STMT
  _1 ={v} pxList_7(D)->uxNumberOfItems;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 118111600]:
  uxTask_2 = prvListTasksWithinSingleList.part.0 (pxTaskStatusArray_8(D), pxList_7(D), eState_9(D));

  <bb 4> [local count: 236223201]:
  # uxTask_5 = PHI <0(2), uxTask_2(3)>
  # DEBUG uxTask => uxTask_5
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return uxTask_5;

}



;; Function uxTaskGetSystemState (uxTaskGetSystemState, funcdef_no=31, decl_uid=6210, cgraph_uid=32, symbol_order=53)

Modification phase of node uxTaskGetSystemState/53
uxTaskGetSystemState (struct TaskStatus_t * const pxTaskStatusArray, const UBaseType_t uxArraySize, uint32_t * const pulTotalRunTime)
{
  UBaseType_t uxQueue;
  UBaseType_t uxTask;
  long unsigned int uxCurrentNumberOfTasks.73_1;
  long unsigned int _2;
  struct TaskStatus_t * _3;
  struct List_t * _4;
  long unsigned int _5;
  struct TaskStatus_t * _6;
  struct List_t * pxDelayedTaskList.74_7;
  long unsigned int _8;
  struct TaskStatus_t * _9;
  struct List_t * pxOverflowDelayedTaskList.75_10;
  long unsigned int _11;
  struct TaskStatus_t * _12;
  long unsigned int _13;
  struct TaskStatus_t * _14;
  long unsigned int _27;
  long unsigned int _30;
  long unsigned int _33;
  long unsigned int _36;
  long unsigned int _39;

  <bb 2> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  # DEBUG uxTask => 0
  # DEBUG uxQueue => 10
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  uxCurrentNumberOfTasks.73_1 ={v} uxCurrentNumberOfTasks;
  if (uxCurrentNumberOfTasks.73_1 <= uxArraySize_23(D))
    goto <bb 7>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 7> [local count: 107374182]:

  <bb 3> [local count: 1073741824]:
  # uxTask_15 = PHI <0(7), uxTask_28(8)>
  # uxQueue_17 = PHI <10(7), uxQueue_24(8)>
  # DEBUG uxQueue => uxQueue_17
  # DEBUG uxTask => uxTask_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxQueue_24 = uxQueue_17 + 4294967295;
  # DEBUG uxQueue => uxQueue_24
  # DEBUG BEGIN_STMT
  _2 = uxTask_15 * 36;
  _3 = pxTaskStatusArray_25(D) + _2;
  _4 = &pxReadyTasksLists[uxQueue_24];
  _27 = prvListTasksWithinSingleList (_3, _4, 1);
  uxTask_28 = uxTask_15 + _27;
  # DEBUG uxTask => uxTask_28
  # DEBUG BEGIN_STMT
  if (uxQueue_24 != 0)
    goto <bb 8>; [90.00%]
  else
    goto <bb 4>; [10.00%]

  <bb 8> [local count: 966367641]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374182]:
  # uxTask_20 = PHI <uxTask_28(3)>
  # DEBUG BEGIN_STMT
  _5 = uxTask_20 * 36;
  _6 = pxTaskStatusArray_25(D) + _5;
  pxDelayedTaskList.74_7 ={v} pxDelayedTaskList;
  _30 = prvListTasksWithinSingleList (_6, pxDelayedTaskList.74_7, 2);
  uxTask_31 = uxTask_20 + _30;
  # DEBUG uxTask => uxTask_31
  # DEBUG BEGIN_STMT
  _8 = uxTask_31 * 36;
  _9 = pxTaskStatusArray_25(D) + _8;
  pxOverflowDelayedTaskList.75_10 ={v} pxOverflowDelayedTaskList;
  _33 = prvListTasksWithinSingleList (_9, pxOverflowDelayedTaskList.75_10, 2);
  uxTask_34 = uxTask_31 + _33;
  # DEBUG uxTask => uxTask_34
  # DEBUG BEGIN_STMT
  _11 = uxTask_34 * 36;
  _12 = pxTaskStatusArray_25(D) + _11;
  _36 = prvListTasksWithinSingleList (_12, &xTasksWaitingTermination, 4);
  uxTask_37 = uxTask_34 + _36;
  # DEBUG uxTask => uxTask_37
  # DEBUG BEGIN_STMT
  _13 = uxTask_37 * 36;
  _14 = pxTaskStatusArray_25(D) + _13;
  _39 = prvListTasksWithinSingleList (_14, &xSuspendedTaskList, 3);
  uxTask_40 = uxTask_37 + _39;
  # DEBUG uxTask => uxTask_40
  # DEBUG BEGIN_STMT
  if (pulTotalRunTime_41(D) != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 5> [local count: 75161928]:
  # DEBUG BEGIN_STMT
  *pulTotalRunTime_41(D) = 0;

  <bb 6> [local count: 214748364]:
  # uxTask_16 = PHI <0(2), uxTask_40(5), uxTask_40(4)>
  # DEBUG uxTask => uxTask_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTaskResumeAll ();
  # DEBUG BEGIN_STMT
  return uxTask_16;

}



;; Function uxTaskGetStackHighWaterMark (uxTaskGetStackHighWaterMark, funcdef_no=55, decl_uid=6192, cgraph_uid=56, symbol_order=77)

Modification phase of node uxTaskGetStackHighWaterMark/77
uxTaskGetStackHighWaterMark (struct tskTaskControlBlock * xTask)
{
  UBaseType_t uxReturn;
  uint8_t * pucEndOfStack;
  short unsigned int _1;
  struct TCB_t * iftmp.124_2;
  struct TCB_t * iftmp.124_5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTask_3(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  iftmp.124_5 ={v} pxCurrentTCB;

  <bb 4> [local count: 1073741824]:
  # iftmp.124_2 = PHI <iftmp.124_5(3), xTask_3(D)(2)>
  # DEBUG pxTCB => iftmp.124_2
  # DEBUG BEGIN_STMT
  pucEndOfStack_6 = iftmp.124_2->pxStack;
  # DEBUG pucEndOfStack => pucEndOfStack_6
  # DEBUG BEGIN_STMT
  _1 = prvTaskCheckFreeStackSpace (pucEndOfStack_6);
  uxReturn_7 = (UBaseType_t) _1;
  # DEBUG uxReturn => uxReturn_7
  # DEBUG BEGIN_STMT
  return uxReturn_7;

}



;; Function xTaskGetCurrentTaskHandle (xTaskGetCurrentTaskHandle, funcdef_no=58, decl_uid=6283, cgraph_uid=59, symbol_order=80)

Modification phase of node xTaskGetCurrentTaskHandle/80
xTaskGetCurrentTaskHandle ()
{
  struct tskTaskControlBlock * xReturn;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xReturn_2 ={v} pxCurrentTCB;
  # DEBUG xReturn => xReturn_2
  # DEBUG BEGIN_STMT
  return xReturn_2;

}



;; Function xTaskGetSchedulerState (xTaskGetSchedulerState, funcdef_no=59, decl_uid=6287, cgraph_uid=60, symbol_order=81)

Modification phase of node xTaskGetSchedulerState/81
xTaskGetSchedulerState ()
{
  BaseType_t xReturn;
  long int xSchedulerRunning.125_1;
  long unsigned int uxSchedulerSuspended.126_2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xSchedulerRunning.125_1 ={v} xSchedulerRunning;
  if (xSchedulerRunning.125_1 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.126_2 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.126_2 == 0)
    goto <bb 5>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 348966093]:
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 0

  <bb 5> [local count: 1073741824]:
  # xReturn_3 = PHI <1(2), 2(3), 0(4)>
  # DEBUG xReturn => xReturn_3
  # DEBUG BEGIN_STMT
  return xReturn_3;

}



;; Function xTaskPriorityInherit (xTaskPriorityInherit, funcdef_no=60, decl_uid=6289, cgraph_uid=61, symbol_order=82)

Modification phase of node xTaskPriorityInherit/82
xTaskPriorityInherit (struct tskTaskControlBlock * const pxMutexHolder)
{
  struct ListItem_t * const pxIndex;
  BaseType_t xReturn;
  long unsigned int _1;
  struct TCB_t * pxCurrentTCB.127_2;
  long unsigned int _3;
  long unsigned int _4;
  signed int _5;
  struct TCB_t * pxCurrentTCB.128_6;
  long unsigned int _7;
  long unsigned int _8;
  struct xLIST * _9;
  struct List_t * _10;
  struct ListItem_t * _11;
  struct TCB_t * pxCurrentTCB.129_12;
  long unsigned int _13;
  long unsigned int uxTopReadyPriority.130_14;
  struct xLIST_ITEM * _15;
  struct xLIST_ITEM * _16;
  struct List_t * _17;
  long unsigned int _18;
  long unsigned int _19;
  struct TCB_t * pxCurrentTCB.131_20;
  long unsigned int _21;
  long unsigned int _22;
  struct TCB_t * pxCurrentTCB.132_23;
  long unsigned int _24;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG pxMutexHolderTCB => pxMutexHolder_29(D)
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 0
  # DEBUG BEGIN_STMT
  if (pxMutexHolder_29(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 13>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct TCB_t *)pxMutexHolder_29(D)].uxPriority;
  pxCurrentTCB.127_2 ={v} pxCurrentTCB;
  _3 = pxCurrentTCB.127_2->uxPriority;
  if (_1 < _3)
    goto <bb 4>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 4> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  _4 = MEM[(struct TCB_t *)pxMutexHolder_29(D)].xEventListItem.xItemValue;
  _5 = (signed int) _4;
  if (_5 >= 0)
    goto <bb 5>; [59.00%]
  else
    goto <bb 6>; [41.00%]

  <bb 5> [local count: 221727687]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.128_6 ={v} pxCurrentTCB;
  _7 = pxCurrentTCB.128_6->uxPriority;
  _8 = 10 - _7;
  MEM[(struct TCB_t *)pxMutexHolder_29(D)].xEventListItem.xItemValue = _8;

  <bb 6> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = MEM[(struct TCB_t *)pxMutexHolder_29(D)].xStateListItem.pvContainer;
  _10 = &pxReadyTasksLists[_1];
  if (_9 == _10)
    goto <bb 7>; [17.43%]
  else
    goto <bb 10>; [82.57%]

  <bb 7> [local count: 65503620]:
  # DEBUG BEGIN_STMT
  _11 = &MEM[(struct TCB_t *)pxMutexHolder_29(D)].xStateListItem;
  uxListRemove (_11);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.129_12 ={v} pxCurrentTCB;
  _13 = pxCurrentTCB.129_12->uxPriority;
  MEM[(struct TCB_t *)pxMutexHolder_29(D)].uxPriority = _13;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxTopReadyPriority.130_14 ={v} uxTopReadyPriority;
  if (_13 > uxTopReadyPriority.130_14)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 32751810]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _13;

  <bb 9> [local count: 65503620]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_36 = pxReadyTasksLists[_13].pxIndex;
  # DEBUG pxIndex => pxIndex_36
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)pxMutexHolder_29(D)].xStateListItem.pxNext = pxIndex_36;
  # DEBUG BEGIN_STMT
  _15 = pxIndex_36->pxPrevious;
  MEM[(struct TCB_t *)pxMutexHolder_29(D)].xStateListItem.pxPrevious = _15;
  # DEBUG BEGIN_STMT
  _16 = pxIndex_36->pxPrevious;
  _16->pxNext = _11;
  # DEBUG BEGIN_STMT
  pxIndex_36->pxPrevious = _11;
  # DEBUG BEGIN_STMT
  _17 = &pxReadyTasksLists[_13];
  MEM[(struct TCB_t *)pxMutexHolder_29(D)].xStateListItem.pvContainer = _17;
  # DEBUG BEGIN_STMT
  _18 ={v} pxReadyTasksLists[_13].uxNumberOfItems;
  _19 = _18 + 1;
  pxReadyTasksLists[_13].uxNumberOfItems ={v} _19;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 10> [local count: 310306019]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.131_20 ={v} pxCurrentTCB;
  _21 = pxCurrentTCB.131_20->uxPriority;
  MEM[(struct TCB_t *)pxMutexHolder_29(D)].uxPriority = _21;
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  _22 = MEM[(struct TCB_t *)pxMutexHolder_29(D)].uxBasePriority;
  pxCurrentTCB.132_23 ={v} pxCurrentTCB;
  _24 = pxCurrentTCB.132_23->uxPriority;
  if (_22 < _24)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 187904819]:
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 13> [local count: 1073741824]:
  # xReturn_25 = PHI <0(2), 0(11), 1(10), 1(12), 1(9)>
  # DEBUG xReturn => xReturn_25
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xReturn_25;

}



;; Function xTaskPriorityDisinherit (xTaskPriorityDisinherit, funcdef_no=61, decl_uid=6291, cgraph_uid=62, symbol_order=83)

Modification phase of node xTaskPriorityDisinherit/83
xTaskPriorityDisinherit (struct tskTaskControlBlock * const pxMutexHolder)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  BaseType_t xReturn;
  struct TCB_t * pxCurrentTCB.133_1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  struct ListItem_t * _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int uxTopReadyPriority.134_9;
  struct xLIST_ITEM * _10;
  struct xLIST_ITEM * _11;
  struct List_t * _12;
  long unsigned int _13;
  long unsigned int _14;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => pxMutexHolder_18(D)
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 0
  # DEBUG BEGIN_STMT
  if (pxMutexHolder_18(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 14>; [30.00%]

  <bb 3> [local count: 153391]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.133_1 ={v} pxCurrentTCB;
  if (pxCurrentTCB.133_1 != pxMutexHolder_18(D))
    goto <bb 4>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 4> [local count: 107374]:
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
" : "=r" ulNewBASEPRI_32 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_32

  <bb 5> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct TCB_t *)pxMutexHolder_18(D)].uxMutexesHeld;
  if (_2 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 7> [local count: 23009]:
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
" : "=r" ulNewBASEPRI_33 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_33

  <bb 8> [local count: 230087534]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 230087534]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 23009]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = _2 + 4294967295;
  MEM[(struct TCB_t *)pxMutexHolder_18(D)].uxMutexesHeld = _3;
  # DEBUG BEGIN_STMT
  _4 = MEM[(struct TCB_t *)pxMutexHolder_18(D)].uxPriority;
  _5 = MEM[(struct TCB_t *)pxMutexHolder_18(D)].uxBasePriority;
  if (_4 != _5)
    goto <bb 10>; [66.00%]
  else
    goto <bb 14>; [34.00%]

  <bb 10> [local count: 15186]:
  # DEBUG BEGIN_STMT
  if (_3 == 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 11> [local count: 5011]:
  # DEBUG BEGIN_STMT
  _6 = &MEM[(struct TCB_t *)pxMutexHolder_18(D)].xStateListItem;
  uxListRemove (_6);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct TCB_t *)pxMutexHolder_18(D)].uxBasePriority;
  MEM[(struct TCB_t *)pxMutexHolder_18(D)].uxPriority = _7;
  # DEBUG BEGIN_STMT
  _8 = 10 - _7;
  MEM[(struct TCB_t *)pxMutexHolder_18(D)].xEventListItem.xItemValue = _8;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxTopReadyPriority.134_9 ={v} uxTopReadyPriority;
  if (_7 > uxTopReadyPriority.134_9)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 2506]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _7;

  <bb 13> [local count: 5011]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_25 = pxReadyTasksLists[_7].pxIndex;
  # DEBUG pxIndex => pxIndex_25
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)pxMutexHolder_18(D)].xStateListItem.pxNext = pxIndex_25;
  # DEBUG BEGIN_STMT
  _10 = pxIndex_25->pxPrevious;
  MEM[(struct TCB_t *)pxMutexHolder_18(D)].xStateListItem.pxPrevious = _10;
  # DEBUG BEGIN_STMT
  _11 = pxIndex_25->pxPrevious;
  _11->pxNext = _6;
  # DEBUG BEGIN_STMT
  pxIndex_25->pxPrevious = _6;
  # DEBUG BEGIN_STMT
  _12 = &pxReadyTasksLists[_7];
  MEM[(struct TCB_t *)pxMutexHolder_18(D)].xStateListItem.pvContainer = _12;
  # DEBUG BEGIN_STMT
  _13 ={v} pxReadyTasksLists[_7].uxNumberOfItems;
  _14 = _13 + 1;
  pxReadyTasksLists[_7].uxNumberOfItems ={v} _14;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 14> [local count: 88748]:
  # xReturn_15 = PHI <0(2), 1(13), 0(9), 0(10)>
  # DEBUG xReturn => xReturn_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xReturn_15;

}



;; Function vTaskPriorityDisinheritAfterTimeout (vTaskPriorityDisinheritAfterTimeout, funcdef_no=62, decl_uid=6294, cgraph_uid=63, symbol_order=84)

Modification phase of node vTaskPriorityDisinheritAfterTimeout/84
vTaskPriorityDisinheritAfterTimeout (struct tskTaskControlBlock * const pxMutexHolder, UBaseType_t uxHighestPriorityWaitingTask)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  UBaseType_t uxPriorityToUse;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  struct TCB_t * pxCurrentTCB.135_4;
  long unsigned int _5;
  signed int _6;
  long unsigned int _7;
  struct xLIST * _8;
  struct List_t * _9;
  struct ListItem_t * _10;
  long unsigned int _12;
  long unsigned int uxTopReadyPriority.136_13;
  struct xLIST_ITEM * _14;
  struct xLIST_ITEM * _15;
  struct List_t * _16;
  long unsigned int _17;
  long unsigned int _18;

  <bb 2> [local count: 306783]:
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => pxMutexHolder_22(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG uxOnlyOneMutexHeld => 1
  # DEBUG BEGIN_STMT
  if (pxMutexHolder_22(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 17>; [30.00%]

  <bb 3> [local count: 214748]:
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct TCB_t *)pxMutexHolder_22(D)].uxMutexesHeld;
  if (_1 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 4> [local count: 107374]:
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
" : "=r" ulNewBASEPRI_36 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_36

  <bb 5> [local count: 1073741823]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct TCB_t *)pxMutexHolder_22(D)].uxBasePriority;
  uxPriorityToUse_11 = MAX_EXPR <_2, uxHighestPriorityWaitingTask_24(D)>;
  # DEBUG uxPriorityToUse => uxPriorityToUse_11
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct TCB_t *)pxMutexHolder_22(D)].uxPriority;
  if (_3 != uxPriorityToUse_11)
    goto <bb 7>; [66.00%]
  else
    goto <bb 17>; [34.00%]

  <bb 7> [local count: 70867]:
  # DEBUG BEGIN_STMT
  if (_1 == 1)
    goto <bb 8>; [34.00%]
  else
    goto <bb 17>; [66.00%]

  <bb 8> [local count: 24095]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.135_4 ={v} pxCurrentTCB;
  if (pxCurrentTCB.135_4 == pxMutexHolder_22(D))
    goto <bb 9>; [30.00%]
  else
    goto <bb 11>; [70.00%]

  <bb 9> [local count: 7228]:
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
" : "=r" ulNewBASEPRI_37 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_37

  <bb 10> [local count: 72284299]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 19> [local count: 72284299]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 16866]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG uxPriorityUsedOnEntry => _3
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)pxMutexHolder_22(D)].uxPriority = uxPriorityToUse_11;
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct TCB_t *)pxMutexHolder_22(D)].xEventListItem.xItemValue;
  _6 = (signed int) _5;
  if (_6 >= 0)
    goto <bb 12>; [59.00%]
  else
    goto <bb 13>; [41.00%]

  <bb 12> [local count: 9951]:
  # DEBUG BEGIN_STMT
  _7 = 10 - uxPriorityToUse_11;
  MEM[(struct TCB_t *)pxMutexHolder_22(D)].xEventListItem.xItemValue = _7;

  <bb 13> [local count: 16866]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = MEM[(struct TCB_t *)pxMutexHolder_22(D)].xStateListItem.pvContainer;
  _9 = &pxReadyTasksLists[_3];
  if (_8 == _9)
    goto <bb 14>; [17.43%]
  else
    goto <bb 17>; [82.57%]

  <bb 14> [local count: 2940]:
  # DEBUG BEGIN_STMT
  _10 = &MEM[(struct TCB_t *)pxMutexHolder_22(D)].xStateListItem;
  uxListRemove (_10);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = MEM[(struct TCB_t *)pxMutexHolder_22(D)].uxPriority;
  uxTopReadyPriority.136_13 ={v} uxTopReadyPriority;
  if (_12 > uxTopReadyPriority.136_13)
    goto <bb 15>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 15> [local count: 1470]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _12;

  <bb 16> [local count: 2940]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_29 = pxReadyTasksLists[_12].pxIndex;
  # DEBUG pxIndex => pxIndex_29
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)pxMutexHolder_22(D)].xStateListItem.pxNext = pxIndex_29;
  # DEBUG BEGIN_STMT
  _14 = pxIndex_29->pxPrevious;
  MEM[(struct TCB_t *)pxMutexHolder_22(D)].xStateListItem.pxPrevious = _14;
  # DEBUG BEGIN_STMT
  _15 = pxIndex_29->pxPrevious;
  _15->pxNext = _10;
  # DEBUG BEGIN_STMT
  pxIndex_29->pxPrevious = _10;
  # DEBUG BEGIN_STMT
  _16 = &pxReadyTasksLists[_12];
  MEM[(struct TCB_t *)pxMutexHolder_22(D)].xStateListItem.pvContainer = _16;
  # DEBUG BEGIN_STMT
  _17 ={v} pxReadyTasksLists[_12].uxNumberOfItems;
  _18 = _17 + 1;
  pxReadyTasksLists[_12].uxNumberOfItems ={v} _18;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 192180]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function vTaskList (vTaskList, funcdef_no=64, decl_uid=6212, cgraph_uid=65, symbol_order=86)

Modification phase of node vTaskList/86
vTaskList (char * pcWriteBuffer)
{
  char cStatus;
  UBaseType_t x;
  UBaseType_t uxArraySize;
  struct TaskStatus_t * pxTaskStatusArray;
  long unsigned int uxCurrentNumberOfTasks.137_1;
  long unsigned int _2;
  long unsigned int _3;
  struct TaskStatus_t * _4;
  <unnamed type> _5;
  unsigned int _6;
  const char * _8;
  int _9;
  long unsigned int _11;
  short unsigned int _12;
  unsigned int _13;
  long unsigned int _14;
  unsigned int _15;

  <bb 2> [local count: 220893212]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *pcWriteBuffer_22(D) = 0;
  # DEBUG BEGIN_STMT
  uxArraySize_24 ={v} uxCurrentNumberOfTasks;
  # DEBUG uxArraySize => uxArraySize_24
  # DEBUG BEGIN_STMT
  uxCurrentNumberOfTasks.137_1 ={v} uxCurrentNumberOfTasks;
  _2 = uxCurrentNumberOfTasks.137_1 * 36;
  pxTaskStatusArray_26 = pvPortMalloc (_2);
  # DEBUG pxTaskStatusArray => pxTaskStatusArray_26
  # DEBUG BEGIN_STMT
  if (pxTaskStatusArray_26 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 10>; [46.53%]

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  uxArraySize_28 = uxTaskGetSystemState (pxTaskStatusArray_26, uxArraySize_24, 0B);
  # DEBUG uxArraySize => uxArraySize_28
  # DEBUG BEGIN_STMT
  # DEBUG x => 0
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 955630226]:
  # DEBUG BEGIN_STMT
  _3 = x_17 * 36;
  _4 = pxTaskStatusArray_26 + _3;
  _5 = _4->eCurrentState;
  _6 = _5;
  if (_6 <= 4)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 477815113]:
<L15>:
  cStatus_10 = 0;
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 477815113]:
<L16>:
  cStatus_7 = CSWTCH.230[_6];

  <bb 7> [local count: 955630226]:
  # cStatus_18 = PHI <cStatus_7(6), cStatus_10(5)>
<L17>:
<L14>:
  # DEBUG cStatus => cStatus_18
  # DEBUG BEGIN_STMT
  _8 = _4->pcTaskName;
  pcWriteBuffer_31 = prvWriteNameToBuffer (pcWriteBuffer_16, _8);
  # DEBUG pcWriteBuffer => pcWriteBuffer_31
  # DEBUG BEGIN_STMT
  _9 = (int) cStatus_18;
  _11 = _4->uxCurrentPriority;
  _12 = _4->usStackHighWaterMark;
  _13 = (unsigned int) _12;
  _14 = _4->xTaskNumber;
  sprintf (pcWriteBuffer_31, "\t%c\t%u\t%u\t%u\r\n", _9, _11, _13, _14);
  # DEBUG BEGIN_STMT
  _15 = strlen (pcWriteBuffer_31);
  pcWriteBuffer_33 = pcWriteBuffer_31 + _15;
  # DEBUG pcWriteBuffer => pcWriteBuffer_33
  # DEBUG BEGIN_STMT
  x_34 = x_17 + 1;
  # DEBUG x => x_34

  <bb 8> [local count: 1073741824]:
  # pcWriteBuffer_16 = PHI <pcWriteBuffer_22(D)(3), pcWriteBuffer_33(7)>
  # x_17 = PHI <0(3), x_34(7)>
  # DEBUG x => x_17
  # DEBUG pcWriteBuffer => pcWriteBuffer_16
  # DEBUG BEGIN_STMT
  if (x_17 < uxArraySize_28)
    goto <bb 4>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  vPortFree (pxTaskStatusArray_26);

  <bb 10> [local count: 220893212]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function uxTaskResetEventItemValue (uxTaskResetEventItemValue, funcdef_no=65, decl_uid=6281, cgraph_uid=66, symbol_order=87)

Modification phase of node uxTaskResetEventItemValue/87
uxTaskResetEventItemValue ()
{
  TickType_t uxReturn;
  struct TCB_t * pxCurrentTCB.138_1;
  struct TCB_t * pxCurrentTCB.139_2;
  long unsigned int _3;
  struct TCB_t * pxCurrentTCB.140_4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.138_1 ={v} pxCurrentTCB;
  uxReturn_7 = pxCurrentTCB.138_1->xEventListItem.xItemValue;
  # DEBUG uxReturn => uxReturn_7
  # DEBUG BEGIN_STMT
  pxCurrentTCB.139_2 ={v} pxCurrentTCB;
  _3 = pxCurrentTCB.139_2->uxPriority;
  pxCurrentTCB.140_4 ={v} pxCurrentTCB;
  _5 = 10 - _3;
  pxCurrentTCB.140_4->xEventListItem.xItemValue = _5;
  # DEBUG BEGIN_STMT
  return uxReturn_7;

}



;; Function pvTaskIncrementMutexHeldCount (pvTaskIncrementMutexHeldCount, funcdef_no=66, decl_uid=6305, cgraph_uid=67, symbol_order=88)

Modification phase of node pvTaskIncrementMutexHeldCount/88
pvTaskIncrementMutexHeldCount ()
{
  struct TCB_t * pxCurrentTCB.141_1;
  struct TCB_t * pxCurrentTCB.142_2;
  long unsigned int _3;
  long unsigned int _4;
  struct tskTaskControlBlock * _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.141_1 ={v} pxCurrentTCB;
  if (pxCurrentTCB.141_1 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.142_2 ={v} pxCurrentTCB;
  _3 = pxCurrentTCB.142_2->uxMutexesHeld;
  _4 = _3 + 1;
  pxCurrentTCB.142_2->uxMutexesHeld = _4;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _8 ={v} pxCurrentTCB;
  return _8;

}



;; Function ulTaskGenericNotifyTake (ulTaskGenericNotifyTake, funcdef_no=67, decl_uid=6245, cgraph_uid=68, symbol_order=89)

Modification phase of node ulTaskGenericNotifyTake/89
ulTaskGenericNotifyTake (UBaseType_t uxIndexToWait, BaseType_t xClearCountOnExit, TickType_t xTicksToWait)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulReturn;
  struct TCB_t * pxCurrentTCB.143_1;
  long unsigned int _2;
  struct TCB_t * pxCurrentTCB.144_3;
  struct TCB_t * pxCurrentTCB.145_4;
  struct TCB_t * pxCurrentTCB.146_5;
  struct TCB_t * pxCurrentTCB.147_6;
  long unsigned int _7;
  struct TCB_t * pxCurrentTCB.148_8;

  <bb 2> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (uxIndexToWait_11(D) != 0)
    goto <bb 3>; [67.00%]
  else
    goto <bb 5>; [33.00%]

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
" : "=r" ulNewBASEPRI_28 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_28

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  pxCurrentTCB.143_1 ={v} pxCurrentTCB;
  _2 ={v} pxCurrentTCB.143_1->ulNotifiedValue[0];
  if (_2 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 26443]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.144_3 ={v} pxCurrentTCB;
  pxCurrentTCB.144_3->ucNotifyState[0] ={v} 1;
  # DEBUG BEGIN_STMT
  if (xTicksToWait_15(D) != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 8726]:
  # DEBUG BEGIN_STMT
  prvAddCurrentTaskToDelayedList (xTicksToWait_15(D), 1);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.145_4 ={v} pxCurrentTCB;
  ulReturn_22 ={v} pxCurrentTCB.145_4->ulNotifiedValue[0];
  # DEBUG ulReturn => ulReturn_22
  # DEBUG BEGIN_STMT
  if (ulReturn_22 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 9> [local count: 26443]:
  # DEBUG BEGIN_STMT
  if (xClearCountOnExit_23(D) != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 13221]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.146_5 ={v} pxCurrentTCB;
  pxCurrentTCB.146_5->ulNotifiedValue[0] ={v} 0;
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 13221]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.147_6 ={v} pxCurrentTCB;
  _7 = ulReturn_22 + 4294967295;
  pxCurrentTCB.147_6->ulNotifiedValue[0] ={v} _7;

  <bb 12> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.148_8 ={v} pxCurrentTCB;
  pxCurrentTCB.148_8->ucNotifyState[0] ={v} 0;
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  return ulReturn_22;

}



;; Function xTaskGenericNotifyWait (xTaskGenericNotifyWait, funcdef_no=68, decl_uid=6237, cgraph_uid=69, symbol_order=90)

Modification phase of node xTaskGenericNotifyWait/90
xTaskGenericNotifyWait (UBaseType_t uxIndexToWait, uint32_t ulBitsToClearOnEntry, uint32_t ulBitsToClearOnExit, uint32_t * pulNotificationValue, TickType_t xTicksToWait)
{
  uint32_t ulNewBASEPRI;
  BaseType_t xReturn;
  struct TCB_t * pxCurrentTCB.149_1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  struct TCB_t * pxCurrentTCB.151_6;
  struct TCB_t * pxCurrentTCB.152_7;
  long unsigned int _8;
  struct TCB_t * pxCurrentTCB.153_9;
  unsigned char _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  struct TCB_t * pxCurrentTCB.155_14;
  struct TCB_t * pxCurrentTCB.150_22;
  struct TCB_t * pxCurrentTCB.154_35;

  <bb 2> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (uxIndexToWait_19(D) != 0)
    goto <bb 3>; [67.00%]
  else
    goto <bb 5>; [33.00%]

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
" : "=r" ulNewBASEPRI_40 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_40

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  pxCurrentTCB.149_1 ={v} pxCurrentTCB;
  _2 ={v} pxCurrentTCB.149_1->ucNotifyState[0];
  if (_2 != 2)
    goto <bb 6>; [66.00%]
  else
    goto <bb 8>; [34.00%]

  <bb 6> [local count: 34905]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.150_22 ={v} pxCurrentTCB;
  _3 ={v} pxCurrentTCB.150_22->ulNotifiedValue[0];
  _4 = ~ulBitsToClearOnEntry_23(D);
  _5 = _3 & _4;
  pxCurrentTCB.150_22->ulNotifiedValue[0] ={v} _5;
  # DEBUG BEGIN_STMT
  pxCurrentTCB.151_6 ={v} pxCurrentTCB;
  pxCurrentTCB.151_6->ucNotifyState[0] ={v} 1;
  # DEBUG BEGIN_STMT
  if (xTicksToWait_26(D) != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 11519]:
  # DEBUG BEGIN_STMT
  prvAddCurrentTaskToDelayedList (xTicksToWait_26(D), 1);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pulNotificationValue_33(D) != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 37020]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.152_7 ={v} pxCurrentTCB;
  _8 ={v} pxCurrentTCB.152_7->ulNotifiedValue[0];
  *pulNotificationValue_33(D) = _8;

  <bb 10> [local count: 52886]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.153_9 ={v} pxCurrentTCB;
  _10 ={v} pxCurrentTCB.153_9->ucNotifyState[0];
  if (_10 != 2)
    goto <bb 12>; [66.00%]
  else
    goto <bb 11>; [34.00%]

  <bb 11> [local count: 17981]:
  # DEBUG BEGIN_STMT
  pxCurrentTCB.154_35 ={v} pxCurrentTCB;
  _11 ={v} pxCurrentTCB.154_35->ulNotifiedValue[0];
  _12 = ~ulBitsToClearOnExit_36(D);
  _13 = _11 & _12;
  pxCurrentTCB.154_35->ulNotifiedValue[0] ={v} _13;
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 12> [local count: 52886]:
  # xReturn_15 = PHI <0(10), 1(11)>
  # DEBUG xReturn => xReturn_15
  # DEBUG BEGIN_STMT
  pxCurrentTCB.155_14 ={v} pxCurrentTCB;
  pxCurrentTCB.155_14->ucNotifyState[0] ={v} 0;
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  return xReturn_15;

}



;; Function xTaskGenericNotify (xTaskGenericNotify, funcdef_no=69, decl_uid=6224, cgraph_uid=70, symbol_order=91)

Modification phase of node xTaskGenericNotify/91
xTaskGenericNotify (struct tskTaskControlBlock * xTaskToNotify, UBaseType_t uxIndexToNotify, uint32_t ulValue, eNotifyAction eAction, uint32_t * pulPreviousNotificationValue)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  struct List_t * const pxList;
  uint8_t ucOriginalNotifyState;
  BaseType_t xReturn;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int xTickCount.156_6;
  struct xLIST_ITEM * _7;
  struct xLIST_ITEM * _8;
  struct xLIST_ITEM * _9;
  struct ListItem_t * _10;
  struct ListItem_t * _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int uxTopReadyPriority.157_15;
  struct xLIST_ITEM * _16;
  struct xLIST_ITEM * _17;
  struct List_t * _18;
  long unsigned int _19;
  long unsigned int _20;
  struct xLIST * _21;
  struct TCB_t * pxCurrentTCB.158_22;
  long unsigned int _23;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (uxIndexToNotify_30(D) != 0)
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
" : "=r" ulNewBASEPRI_61 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_61

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 30> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTaskToNotify_31(D) == 0B)
    goto <bb 6>; [46.53%]
  else
    goto <bb 8>; [53.47%]

  <bb 6> [local count: 49961]:
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
" : "=r" ulNewBASEPRI_62 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_62

  <bb 7> [local count: 499612071]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 31> [local count: 499612071]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 57413]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTaskToNotify_31(D)
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  if (pulPreviousNotificationValue_34(D) != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 40189]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct TCB_t *)xTaskToNotify_31(D)].ulNotifiedValue[0];
  *pulPreviousNotificationValue_34(D) = _1;

  <bb 10> [local count: 57413]:
  # DEBUG BEGIN_STMT
  ucOriginalNotifyState_36 ={v} MEM[(struct TCB_t *)xTaskToNotify_31(D)].ucNotifyState[0];
  # DEBUG ucOriginalNotifyState => ucOriginalNotifyState_36
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_31(D)].ucNotifyState[0] ={v} 2;
  # DEBUG BEGIN_STMT
  switch (eAction_38(D)) <default: <L16> [16.67%], case 0: <L35> [16.67%], case 1: <L8> [16.67%], case 2: <L9> [16.67%], case 3: <L10> [16.67%], case 4: <L11> [16.67%]>

  <bb 11> [local count: 9571]:
<L8>:
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct TCB_t *)xTaskToNotify_31(D)].ulNotifiedValue[0];
  _3 = _2 | ulValue_39(D);
  MEM[(struct TCB_t *)xTaskToNotify_31(D)].ulNotifiedValue[0] ={v} _3;
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 12> [local count: 9571]:
<L9>:
  # DEBUG BEGIN_STMT
  _4 ={v} MEM[(struct TCB_t *)xTaskToNotify_31(D)].ulNotifiedValue[0];
  _5 = _4 + 1;
  MEM[(struct TCB_t *)xTaskToNotify_31(D)].ulNotifiedValue[0] ={v} _5;
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 13> [local count: 9571]:
<L10>:
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_31(D)].ulNotifiedValue[0] ={v} ulValue_39(D);
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 14> [local count: 9571]:
<L11>:
  # DEBUG BEGIN_STMT
  if (ucOriginalNotifyState_36 != 2)
    goto <bb 15>; [66.00%]
  else
    goto <bb 19>; [34.00%]

  <bb 15> [local count: 6317]:
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_31(D)].ulNotifiedValue[0] ={v} ulValue_39(D);
  goto <bb 19>; [100.00%]

  <bb 16> [local count: 9571]:
<L16>:
  # DEBUG BEGIN_STMT
  xTickCount.156_6 ={v} xTickCount;
  if (xTickCount.156_6 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 17> [local count: 4785]:
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
" : "=r" ulNewBASEPRI_63 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_63

  <bb 18> [local count: 47853715]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 32> [local count: 47853715]:
  goto <bb 18>; [100.00%]

  <bb 19> [local count: 52639]:
  # xReturn_24 = PHI <1(11), 1(12), 1(13), 0(14), 1(10), 1(16), 1(15)>
<L35>:
  # DEBUG xReturn => xReturn_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ucOriginalNotifyState_36 == 1)
    goto <bb 20>; [51.12%]
  else
    goto <bb 29>; [48.88%]

  <bb 20> [local count: 26909]:
  # DEBUG BEGIN_STMT
  pxList_44 = MEM[(struct TCB_t *)xTaskToNotify_31(D)].xStateListItem.pvContainer;
  # DEBUG pxList => pxList_44
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct TCB_t *)xTaskToNotify_31(D)].xStateListItem.pxNext;
  _8 = MEM[(struct TCB_t *)xTaskToNotify_31(D)].xStateListItem.pxPrevious;
  _7->pxPrevious = _8;
  # DEBUG BEGIN_STMT
  _9 = MEM[(struct TCB_t *)xTaskToNotify_31(D)].xStateListItem.pxPrevious;
  _9->pxNext = _7;
  # DEBUG BEGIN_STMT
  _10 = pxList_44->pxIndex;
  _11 = &MEM[(struct TCB_t *)xTaskToNotify_31(D)].xStateListItem;
  if (_10 == _11)
    goto <bb 21>; [30.00%]
  else
    goto <bb 22>; [70.00%]

  <bb 21> [local count: 8073]:
  # DEBUG BEGIN_STMT
  pxList_44->pxIndex = _9;

  <bb 22> [local count: 26909]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 ={v} pxList_44->uxNumberOfItems;
  _13 = _12 + 4294967295;
  pxList_44->uxNumberOfItems ={v} _13;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = MEM[(struct TCB_t *)xTaskToNotify_31(D)].uxPriority;
  uxTopReadyPriority.157_15 ={v} uxTopReadyPriority;
  if (_14 > uxTopReadyPriority.157_15)
    goto <bb 23>; [50.00%]
  else
    goto <bb 24>; [50.00%]

  <bb 23> [local count: 13455]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _14;

  <bb 24> [local count: 26909]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_50 = pxReadyTasksLists[_14].pxIndex;
  # DEBUG pxIndex => pxIndex_50
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_31(D)].xStateListItem.pxNext = pxIndex_50;
  # DEBUG BEGIN_STMT
  _16 = pxIndex_50->pxPrevious;
  MEM[(struct TCB_t *)xTaskToNotify_31(D)].xStateListItem.pxPrevious = _16;
  # DEBUG BEGIN_STMT
  _17 = pxIndex_50->pxPrevious;
  _17->pxNext = _11;
  # DEBUG BEGIN_STMT
  pxIndex_50->pxPrevious = _11;
  # DEBUG BEGIN_STMT
  _18 = &pxReadyTasksLists[_14];
  MEM[(struct TCB_t *)xTaskToNotify_31(D)].xStateListItem.pvContainer = _18;
  # DEBUG BEGIN_STMT
  _19 ={v} pxReadyTasksLists[_14].uxNumberOfItems;
  _20 = _19 + 1;
  pxReadyTasksLists[_14].uxNumberOfItems ={v} _20;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _21 = MEM[(struct TCB_t *)xTaskToNotify_31(D)].xEventListItem.pvContainer;
  if (_21 != 0B)
    goto <bb 25>; [70.00%]
  else
    goto <bb 27>; [30.00%]

  <bb 25> [local count: 18836]:
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
" : "=r" ulNewBASEPRI_64 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_64

  <bb 26> [local count: 188363707]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 188363706]:
  goto <bb 26>; [100.00%]

  <bb 27> [local count: 8073]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxCurrentTCB.158_22 ={v} pxCurrentTCB;
  _23 = pxCurrentTCB.158_22->uxPriority;
  if (_14 > _23)
    goto <bb 28>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 28> [local count: 4036]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT

  <bb 29> [local count: 33803]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  return xReturn_24;

}



;; Function xTaskGenericNotifyFromISR (xTaskGenericNotifyFromISR, funcdef_no=70, decl_uid=6231, cgraph_uid=71, symbol_order=92)

Modification phase of node xTaskGenericNotifyFromISR/92
xTaskGenericNotifyFromISR (struct tskTaskControlBlock * xTaskToNotify, UBaseType_t uxIndexToNotify, uint32_t ulValue, eNotifyAction eAction, uint32_t * pulPreviousNotificationValue, BaseType_t * pxHigherPriorityTaskWoken)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  struct ListItem_t * const pxIndex;
  struct List_t * const pxList;
  BaseType_t xReturn;
  uint8_t ucOriginalNotifyState;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int xTickCount.159_6;
  struct xLIST * _7;
  long unsigned int uxSchedulerSuspended.160_8;
  struct xLIST_ITEM * _9;
  struct xLIST_ITEM * _10;
  struct xLIST_ITEM * _11;
  struct ListItem_t * _12;
  struct ListItem_t * _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int uxTopReadyPriority.161_17;
  struct xLIST_ITEM * _18;
  struct xLIST_ITEM * _19;
  struct List_t * _20;
  long unsigned int _21;
  long unsigned int _22;
  struct xLIST_ITEM * _23;
  struct xLIST_ITEM * _24;
  struct ListItem_t * _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  struct TCB_t * pxCurrentTCB.162_29;
  long unsigned int _30;

  <bb 2> [local count: 228942]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTaskToNotify_39(D) == 0B)
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
" : "=r" ulNewBASEPRI_76 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_76

  <bb 4> [local count: 686828460]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 35> [local count: 686828460]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (uxIndexToNotify_40(D) != 0)
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
" : "=r" ulNewBASEPRI_77 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_77

  <bb 7> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 36> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortValidateInterruptPriority ();
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTaskToNotify_39(D)
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
" : "=r" ulOriginalBASEPRI_78, "=r" ulNewBASEPRI_79 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_79
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_78
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptStatus => ulOriginalBASEPRI_78
  # DEBUG BEGIN_STMT
  if (pulPreviousNotificationValue_43(D) != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 37020]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct TCB_t *)xTaskToNotify_39(D)].ulNotifiedValue[0];
  *pulPreviousNotificationValue_43(D) = _1;

  <bb 10> [local count: 52886]:
  # DEBUG BEGIN_STMT
  ucOriginalNotifyState_45 ={v} MEM[(struct TCB_t *)xTaskToNotify_39(D)].ucNotifyState[0];
  # DEBUG ucOriginalNotifyState => ucOriginalNotifyState_45
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].ucNotifyState[0] ={v} 2;
  # DEBUG BEGIN_STMT
  switch (eAction_47(D)) <default: <L16> [16.67%], case 0: <L39> [16.67%], case 1: <L8> [16.67%], case 2: <L9> [16.67%], case 3: <L10> [16.67%], case 4: <L11> [16.67%]>

  <bb 11> [local count: 8816]:
<L8>:
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct TCB_t *)xTaskToNotify_39(D)].ulNotifiedValue[0];
  _3 = _2 | ulValue_48(D);
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].ulNotifiedValue[0] ={v} _3;
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 12> [local count: 8816]:
<L9>:
  # DEBUG BEGIN_STMT
  _4 ={v} MEM[(struct TCB_t *)xTaskToNotify_39(D)].ulNotifiedValue[0];
  _5 = _4 + 1;
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].ulNotifiedValue[0] ={v} _5;
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 13> [local count: 8816]:
<L10>:
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].ulNotifiedValue[0] ={v} ulValue_48(D);
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 14> [local count: 8816]:
<L11>:
  # DEBUG BEGIN_STMT
  if (ucOriginalNotifyState_45 != 2)
    goto <bb 15>; [66.00%]
  else
    goto <bb 19>; [34.00%]

  <bb 15> [local count: 5819]:
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].ulNotifiedValue[0] ={v} ulValue_48(D);
  goto <bb 19>; [100.00%]

  <bb 16> [local count: 8816]:
<L16>:
  # DEBUG BEGIN_STMT
  xTickCount.159_6 ={v} xTickCount;
  if (xTickCount.159_6 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 17> [local count: 4408]:
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
" : "=r" ulNewBASEPRI_80 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_80

  <bb 18> [local count: 44080307]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 37> [local count: 44080307]:
  goto <bb 18>; [100.00%]

  <bb 19> [local count: 48488]:
  # xReturn_31 = PHI <1(11), 1(12), 1(13), 0(14), 1(10), 1(16), 1(15)>
<L39>:
  # DEBUG xReturn => xReturn_31
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ucOriginalNotifyState_45 == 1)
    goto <bb 20>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 20> [local count: 16486]:
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct TCB_t *)xTaskToNotify_39(D)].xEventListItem.pvContainer;
  if (_7 != 0B)
    goto <bb 21>; [70.00%]
  else
    goto <bb 23>; [30.00%]

  <bb 21> [local count: 11540]:
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
" : "=r" ulNewBASEPRI_81 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_81

  <bb 22> [local count: 115402244]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 38> [local count: 115402244]:
  goto <bb 22>; [100.00%]

  <bb 23> [local count: 4946]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.160_8 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.160_8 == 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 24> [local count: 2473]:
  # DEBUG BEGIN_STMT
  pxList_60 = MEM[(struct TCB_t *)xTaskToNotify_39(D)].xStateListItem.pvContainer;
  # DEBUG pxList => pxList_60
  # DEBUG BEGIN_STMT
  _9 = MEM[(struct TCB_t *)xTaskToNotify_39(D)].xStateListItem.pxNext;
  _10 = MEM[(struct TCB_t *)xTaskToNotify_39(D)].xStateListItem.pxPrevious;
  _9->pxPrevious = _10;
  # DEBUG BEGIN_STMT
  _11 = MEM[(struct TCB_t *)xTaskToNotify_39(D)].xStateListItem.pxPrevious;
  _11->pxNext = _9;
  # DEBUG BEGIN_STMT
  _12 = pxList_60->pxIndex;
  _13 = &MEM[(struct TCB_t *)xTaskToNotify_39(D)].xStateListItem;
  if (_12 == _13)
    goto <bb 25>; [30.00%]
  else
    goto <bb 26>; [70.00%]

  <bb 25> [local count: 742]:
  # DEBUG BEGIN_STMT
  pxList_60->pxIndex = _11;

  <bb 26> [local count: 2473]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 ={v} pxList_60->uxNumberOfItems;
  _15 = _14 + 4294967295;
  pxList_60->uxNumberOfItems ={v} _15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = MEM[(struct TCB_t *)xTaskToNotify_39(D)].uxPriority;
  uxTopReadyPriority.161_17 ={v} uxTopReadyPriority;
  if (_16 > uxTopReadyPriority.161_17)
    goto <bb 27>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 27> [local count: 1236]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _16;

  <bb 28> [local count: 2473]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_66 = pxReadyTasksLists[_16].pxIndex;
  # DEBUG pxIndex => pxIndex_66
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].xStateListItem.pxNext = pxIndex_66;
  # DEBUG BEGIN_STMT
  _18 = pxIndex_66->pxPrevious;
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].xStateListItem.pxPrevious = _18;
  # DEBUG BEGIN_STMT
  _19 = pxIndex_66->pxPrevious;
  _19->pxNext = _13;
  # DEBUG BEGIN_STMT
  pxIndex_66->pxPrevious = _13;
  # DEBUG BEGIN_STMT
  _20 = &pxReadyTasksLists[_16];
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].xStateListItem.pvContainer = _20;
  # DEBUG BEGIN_STMT
  _21 ={v} pxReadyTasksLists[_16].uxNumberOfItems;
  _22 = _21 + 1;
  pxReadyTasksLists[_16].uxNumberOfItems ={v} _22;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 30>; [100.00%]

  <bb 29> [local count: 2473]:
  # DEBUG BEGIN_STMT
  pxIndex_53 = xPendingReadyList.pxIndex;
  # DEBUG pxIndex => pxIndex_53
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].xEventListItem.pxNext = pxIndex_53;
  # DEBUG BEGIN_STMT
  _23 = pxIndex_53->pxPrevious;
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].xEventListItem.pxPrevious = _23;
  # DEBUG BEGIN_STMT
  _24 = pxIndex_53->pxPrevious;
  _25 = &MEM[(struct TCB_t *)xTaskToNotify_39(D)].xEventListItem;
  _24->pxNext = _25;
  # DEBUG BEGIN_STMT
  pxIndex_53->pxPrevious = _25;
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_39(D)].xEventListItem.pvContainer = &xPendingReadyList;
  # DEBUG BEGIN_STMT
  _26 ={v} xPendingReadyList.uxNumberOfItems;
  _27 = _26 + 1;
  xPendingReadyList.uxNumberOfItems ={v} _27;

  <bb 30> [local count: 4946]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _28 = MEM[(struct TCB_t *)xTaskToNotify_39(D)].uxPriority;
  pxCurrentTCB.162_29 ={v} pxCurrentTCB;
  _30 = pxCurrentTCB.162_29->uxPriority;
  if (_28 > _30)
    goto <bb 31>; [50.00%]
  else
    goto <bb 34>; [50.00%]

  <bb 31> [local count: 2473]:
  # DEBUG BEGIN_STMT
  if (pxHigherPriorityTaskWoken_73(D) != 0B)
    goto <bb 32>; [70.00%]
  else
    goto <bb 33>; [30.00%]

  <bb 32> [local count: 1731]:
  # DEBUG BEGIN_STMT
  *pxHigherPriorityTaskWoken_73(D) = 1;

  <bb 33> [local count: 2473]:
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 1;

  <bb 34> [local count: 36948]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_78
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_78 : "memory");
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  return xReturn_31;

}



;; Function vTaskGenericNotifyGiveFromISR (vTaskGenericNotifyGiveFromISR, funcdef_no=71, decl_uid=6241, cgraph_uid=72, symbol_order=93)

Modification phase of node vTaskGenericNotifyGiveFromISR/93
vTaskGenericNotifyGiveFromISR (struct tskTaskControlBlock * xTaskToNotify, UBaseType_t uxIndexToNotify, BaseType_t * pxHigherPriorityTaskWoken)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  struct ListItem_t * const pxIndex;
  struct ListItem_t * const pxIndex;
  struct List_t * const pxList;
  uint8_t ucOriginalNotifyState;
  long unsigned int _1;
  long unsigned int _2;
  struct xLIST * _3;
  long unsigned int uxSchedulerSuspended.163_4;
  struct xLIST_ITEM * _5;
  struct xLIST_ITEM * _6;
  struct xLIST_ITEM * _7;
  struct ListItem_t * _8;
  struct ListItem_t * _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int uxTopReadyPriority.164_13;
  struct xLIST_ITEM * _14;
  struct xLIST_ITEM * _15;
  struct List_t * _16;
  long unsigned int _17;
  long unsigned int _18;
  struct xLIST_ITEM * _19;
  struct xLIST_ITEM * _20;
  struct ListItem_t * _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  struct TCB_t * pxCurrentTCB.165_25;
  long unsigned int _26;

  <bb 2> [local count: 228942]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTaskToNotify_32(D) == 0B)
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
" : "=r" ulNewBASEPRI_62 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_62

  <bb 4> [local count: 686828460]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 24> [local count: 686828460]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (uxIndexToNotify_33(D) != 0)
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
" : "=r" ulNewBASEPRI_63 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_63

  <bb 7> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortValidateInterruptPriority ();
  # DEBUG BEGIN_STMT
  # DEBUG pxTCB => xTaskToNotify_32(D)
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
" : "=r" ulOriginalBASEPRI_64, "=r" ulNewBASEPRI_65 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_65
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_64
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptStatus => ulOriginalBASEPRI_64
  # DEBUG BEGIN_STMT
  ucOriginalNotifyState_36 ={v} MEM[(struct TCB_t *)xTaskToNotify_32(D)].ucNotifyState[0];
  # DEBUG ucOriginalNotifyState => ucOriginalNotifyState_36
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_32(D)].ucNotifyState[0] ={v} 2;
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct TCB_t *)xTaskToNotify_32(D)].ulNotifiedValue[0];
  _2 = _1 + 1;
  MEM[(struct TCB_t *)xTaskToNotify_32(D)].ulNotifiedValue[0] ={v} _2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ucOriginalNotifyState_36 == 1)
    goto <bb 9>; [34.00%]
  else
    goto <bb 23>; [66.00%]

  <bb 9> [local count: 17981]:
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct TCB_t *)xTaskToNotify_32(D)].xEventListItem.pvContainer;
  if (_3 != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 12>; [30.00%]

  <bb 10> [local count: 12587]:
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
" : "=r" ulNewBASEPRI_66 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_66

  <bb 11> [local count: 125868183]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 26> [local count: 125868183]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 5394]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxSchedulerSuspended.163_4 ={v} uxSchedulerSuspended;
  if (uxSchedulerSuspended.163_4 == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 13> [local count: 2697]:
  # DEBUG BEGIN_STMT
  pxList_46 = MEM[(struct TCB_t *)xTaskToNotify_32(D)].xStateListItem.pvContainer;
  # DEBUG pxList => pxList_46
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct TCB_t *)xTaskToNotify_32(D)].xStateListItem.pxNext;
  _6 = MEM[(struct TCB_t *)xTaskToNotify_32(D)].xStateListItem.pxPrevious;
  _5->pxPrevious = _6;
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct TCB_t *)xTaskToNotify_32(D)].xStateListItem.pxPrevious;
  _7->pxNext = _5;
  # DEBUG BEGIN_STMT
  _8 = pxList_46->pxIndex;
  _9 = &MEM[(struct TCB_t *)xTaskToNotify_32(D)].xStateListItem;
  if (_8 == _9)
    goto <bb 14>; [30.00%]
  else
    goto <bb 15>; [70.00%]

  <bb 14> [local count: 809]:
  # DEBUG BEGIN_STMT
  pxList_46->pxIndex = _7;

  <bb 15> [local count: 2697]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 ={v} pxList_46->uxNumberOfItems;
  _11 = _10 + 4294967295;
  pxList_46->uxNumberOfItems ={v} _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = MEM[(struct TCB_t *)xTaskToNotify_32(D)].uxPriority;
  uxTopReadyPriority.164_13 ={v} uxTopReadyPriority;
  if (_12 > uxTopReadyPriority.164_13)
    goto <bb 16>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 16> [local count: 1349]:
  # DEBUG BEGIN_STMT
  uxTopReadyPriority ={v} _12;

  <bb 17> [local count: 2697]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pxIndex_52 = pxReadyTasksLists[_12].pxIndex;
  # DEBUG pxIndex => pxIndex_52
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_32(D)].xStateListItem.pxNext = pxIndex_52;
  # DEBUG BEGIN_STMT
  _14 = pxIndex_52->pxPrevious;
  MEM[(struct TCB_t *)xTaskToNotify_32(D)].xStateListItem.pxPrevious = _14;
  # DEBUG BEGIN_STMT
  _15 = pxIndex_52->pxPrevious;
  _15->pxNext = _9;
  # DEBUG BEGIN_STMT
  pxIndex_52->pxPrevious = _9;
  # DEBUG BEGIN_STMT
  _16 = &pxReadyTasksLists[_12];
  MEM[(struct TCB_t *)xTaskToNotify_32(D)].xStateListItem.pvContainer = _16;
  # DEBUG BEGIN_STMT
  _17 ={v} pxReadyTasksLists[_12].uxNumberOfItems;
  _18 = _17 + 1;
  pxReadyTasksLists[_12].uxNumberOfItems ={v} _18;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 18> [local count: 2697]:
  # DEBUG BEGIN_STMT
  pxIndex_39 = xPendingReadyList.pxIndex;
  # DEBUG pxIndex => pxIndex_39
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_32(D)].xEventListItem.pxNext = pxIndex_39;
  # DEBUG BEGIN_STMT
  _19 = pxIndex_39->pxPrevious;
  MEM[(struct TCB_t *)xTaskToNotify_32(D)].xEventListItem.pxPrevious = _19;
  # DEBUG BEGIN_STMT
  _20 = pxIndex_39->pxPrevious;
  _21 = &MEM[(struct TCB_t *)xTaskToNotify_32(D)].xEventListItem;
  _20->pxNext = _21;
  # DEBUG BEGIN_STMT
  pxIndex_39->pxPrevious = _21;
  # DEBUG BEGIN_STMT
  MEM[(struct TCB_t *)xTaskToNotify_32(D)].xEventListItem.pvContainer = &xPendingReadyList;
  # DEBUG BEGIN_STMT
  _22 ={v} xPendingReadyList.uxNumberOfItems;
  _23 = _22 + 1;
  xPendingReadyList.uxNumberOfItems ={v} _23;

  <bb 19> [local count: 5394]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _24 = MEM[(struct TCB_t *)xTaskToNotify_32(D)].uxPriority;
  pxCurrentTCB.165_25 ={v} pxCurrentTCB;
  _26 = pxCurrentTCB.165_25->uxPriority;
  if (_24 > _26)
    goto <bb 20>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 20> [local count: 2697]:
  # DEBUG BEGIN_STMT
  if (pxHigherPriorityTaskWoken_59(D) != 0B)
    goto <bb 21>; [70.00%]
  else
    goto <bb 22>; [30.00%]

  <bb 21> [local count: 1888]:
  # DEBUG BEGIN_STMT
  *pxHigherPriorityTaskWoken_59(D) = 1;

  <bb 22> [local count: 2697]:
  # DEBUG BEGIN_STMT
  xYieldPending ={v} 1;

  <bb 23> [local count: 40299]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_64
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_64 : "memory");
  # DEBUG ulNewMaskValue => NULL
  return;

}



;; Function xTaskGenericNotifyStateClear (xTaskGenericNotifyStateClear, funcdef_no=72, decl_uid=6248, cgraph_uid=73, symbol_order=94)

Modification phase of node xTaskGenericNotifyStateClear/94
xTaskGenericNotifyStateClear (struct tskTaskControlBlock * xTask, UBaseType_t uxIndexToClear)
{
  uint32_t ulNewBASEPRI;
  BaseType_t xReturn;
  unsigned char _1;
  struct TCB_t * iftmp.166_3;
  struct TCB_t * iftmp.166_8;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (uxIndexToClear_5(D) != 0)
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
" : "=r" ulNewBASEPRI_12 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_12

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTask_6(D) == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 6> [local count: 32212]:
  iftmp.166_8 ={v} pxCurrentTCB;

  <bb 7> [local count: 107374]:
  # iftmp.166_3 = PHI <iftmp.166_8(6), xTask_6(D)(5)>
  # DEBUG pxTCB => iftmp.166_3
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  _1 ={v} iftmp.166_3->ucNotifyState[0];
  if (_1 == 2)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 36507]:
  # DEBUG BEGIN_STMT
  iftmp.166_3->ucNotifyState[0] ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 9> [local count: 107374]:
  # xReturn_2 = PHI <1(8), 0(7)>
  # DEBUG xReturn => xReturn_2
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  return xReturn_2;

}



;; Function ulTaskGenericNotifyValueClear (ulTaskGenericNotifyValueClear, funcdef_no=73, decl_uid=6252, cgraph_uid=74, symbol_order=95)

Modification phase of node ulTaskGenericNotifyValueClear/95
ulTaskGenericNotifyValueClear (struct tskTaskControlBlock * xTask, UBaseType_t uxIndexToClear, uint32_t ulBitsToClear)
{
  uint32_t ulReturn;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  struct TCB_t * iftmp.167_4;
  struct TCB_t * iftmp.167_7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xTask_5(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  iftmp.167_7 ={v} pxCurrentTCB;

  <bb 4> [local count: 1073741824]:
  # iftmp.167_4 = PHI <iftmp.167_7(3), xTask_5(D)(2)>
  # DEBUG pxTCB => iftmp.167_4
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  ulReturn_10 ={v} iftmp.167_4->ulNotifiedValue[uxIndexToClear_9(D)];
  # DEBUG ulReturn => ulReturn_10
  # DEBUG BEGIN_STMT
  _1 ={v} iftmp.167_4->ulNotifiedValue[uxIndexToClear_9(D)];
  _2 = ~ulBitsToClear_11(D);
  _3 = _1 & _2;
  iftmp.167_4->ulNotifiedValue[uxIndexToClear_9(D)] ={v} _3;
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  return ulReturn_10;

}


