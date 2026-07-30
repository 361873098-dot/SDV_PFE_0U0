
IPA constant propagation start:
Determining dynamic type for call: prvInitialiseNewStreamBuffer.part.0 (pxStreamBuffer_7(D), pucBuffer_4(D), xBufferSizeBytes_5(D), xTriggerLevelBytes_8(D), ucFlags_9(D));
  Starting walk at: prvInitialiseNewStreamBuffer.part.0 (pxStreamBuffer_7(D), pucBuffer_4(D), xBufferSizeBytes_5(D), xTriggerLevelBytes_8(D), ucFlags_9(D));
  instance pointer: pxStreamBuffer_7(D)  Outer instance pointer: pxStreamBuffer_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = memset (pucBuffer_4(D), 85, xBufferSizeBytes_5(D));
Determining dynamic type for call: prvInitialiseNewStreamBuffer.part.0 (pxStreamBuffer_7(D), pucBuffer_4(D), xBufferSizeBytes_5(D), xTriggerLevelBytes_8(D), ucFlags_9(D));
  Starting walk at: prvInitialiseNewStreamBuffer.part.0 (pxStreamBuffer_7(D), pucBuffer_4(D), xBufferSizeBytes_5(D), xTriggerLevelBytes_8(D), ucFlags_9(D));
  instance pointer: pucBuffer_4(D)  Outer instance pointer: pucBuffer_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = memset (pucBuffer_4(D), 85, xBufferSizeBytes_5(D));
Determining dynamic type for call: xTail_1 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_5(D), pucData_7(D), xCount_3(D), xTail_6(D));
  Starting walk at: xTail_1 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_5(D), pucData_7(D), xCount_3(D), xTail_6(D));
  instance pointer: pxStreamBuffer_5(D)  Outer instance pointer: pxStreamBuffer_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xTail_1 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_5(D), pucData_7(D), xCount_3(D), xTail_6(D));
  Starting walk at: xTail_1 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_5(D), pucData_7(D), xCount_3(D), xTail_6(D));
  instance pointer: pucData_7(D)  Outer instance pointer: pucData_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xHead_1 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_5(D), pucData_7(D), xCount_3(D), xHead_6(D));
  Starting walk at: xHead_1 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_5(D), pucData_7(D), xCount_3(D), xHead_6(D));
  instance pointer: pxStreamBuffer_5(D)  Outer instance pointer: pxStreamBuffer_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xHead_1 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_5(D), pucData_7(D), xCount_3(D), xHead_6(D));
  Starting walk at: xHead_1 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_5(D), pucData_7(D), xCount_3(D), xHead_6(D));
  instance pointer: pucData_7(D)  Outer instance pointer: pucData_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = xStreamBufferSpacesAvailable (xStreamBuffer_5(D));
  Starting walk at: _2 = xStreamBufferSpacesAvailable (xStreamBuffer_5(D));
  instance pointer: xStreamBuffer_5(D)  Outer instance pointer: xStreamBuffer_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xTail_21 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_9(D), &xTempNextMessageLength, 4, xNextTail_10);
  Starting walk at: xTail_21 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_9(D), &xTempNextMessageLength, 4, xNextTail_10);
  instance pointer: pxStreamBuffer_9(D)  Outer instance pointer: pxStreamBuffer_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xTail_21 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_9(D), &xTempNextMessageLength, 4, xNextTail_10);
  Starting walk at: xTail_21 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_9(D), &xTempNextMessageLength, 4, xNextTail_10);
  instance pointer: &xTempNextMessageLength  Outer instance pointer: xTempNextMessageLength offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = prvReadBytesFromBuffer (pxStreamBuffer_9(D), pvRxData_17(D), xCount_16, xNextTail_5);
  Starting walk at: _2 = prvReadBytesFromBuffer (pxStreamBuffer_9(D), pvRxData_17(D), xCount_16, xNextTail_5);
  instance pointer: pxStreamBuffer_9(D)  Outer instance pointer: pxStreamBuffer_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xTail_21 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_9(D), &xTempNextMessageLength, 4, xNextTail_10);
Determining dynamic type for call: _2 = prvReadBytesFromBuffer (pxStreamBuffer_9(D), pvRxData_17(D), xCount_16, xNextTail_5);
  Starting walk at: _2 = prvReadBytesFromBuffer (pxStreamBuffer_9(D), pvRxData_17(D), xCount_16, xNextTail_5);
  instance pointer: pvRxData_17(D)  Outer instance pointer: pvRxData_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xTail_21 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_9(D), &xTempNextMessageLength, 4, xNextTail_10);
Determining dynamic type for call: xBytesAvailable_13 = prvBytesInBuffer (xStreamBuffer_8(D));
  Starting walk at: xBytesAvailable_13 = prvBytesInBuffer (xStreamBuffer_8(D));
  instance pointer: xStreamBuffer_8(D)  Outer instance pointer: xStreamBuffer_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xReceivedLength_16 = prvReadMessageFromBuffer (xStreamBuffer_8(D), pvRxData_10(D), xBufferLengthBytes_14(D), xBytesAvailable_13);
  Starting walk at: xReceivedLength_16 = prvReadMessageFromBuffer (xStreamBuffer_8(D), pvRxData_10(D), xBufferLengthBytes_14(D), xBytesAvailable_13);
  instance pointer: xStreamBuffer_8(D)  Outer instance pointer: xStreamBuffer_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xBytesAvailable_13 = prvBytesInBuffer (xStreamBuffer_8(D));
Determining dynamic type for call: xReceivedLength_16 = prvReadMessageFromBuffer (xStreamBuffer_8(D), pvRxData_10(D), xBufferLengthBytes_14(D), xBytesAvailable_13);
  Starting walk at: xReceivedLength_16 = prvReadMessageFromBuffer (xStreamBuffer_8(D), pvRxData_10(D), xBufferLengthBytes_14(D), xBytesAvailable_13);
  instance pointer: pvRxData_10(D)  Outer instance pointer: pvRxData_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xBytesAvailable_13 = prvBytesInBuffer (xStreamBuffer_8(D));
Determining dynamic type for call: xBytesAvailable_9 = prvBytesInBuffer (xStreamBuffer_5(D));
  Starting walk at: xBytesAvailable_9 = prvBytesInBuffer (xStreamBuffer_5(D));
  instance pointer: xStreamBuffer_5(D)  Outer instance pointer: xStreamBuffer_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: prvReadBytesFromBuffer (xStreamBuffer_5(D), &xTempReturn, 4, _2);
  Starting walk at: prvReadBytesFromBuffer (xStreamBuffer_5(D), &xTempReturn, 4, _2);
  instance pointer: xStreamBuffer_5(D)  Outer instance pointer: xStreamBuffer_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xBytesAvailable_9 = prvBytesInBuffer (xStreamBuffer_5(D));
Determining dynamic type for call: prvReadBytesFromBuffer (xStreamBuffer_5(D), &xTempReturn, 4, _2);
  Starting walk at: prvReadBytesFromBuffer (xStreamBuffer_5(D), &xTempReturn, 4, _2);
  instance pointer: &xTempReturn  Outer instance pointer: xTempReturn offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xBytesAvailable_9 = prvBytesInBuffer (xStreamBuffer_5(D));
Determining dynamic type for call: xBytesAvailable_19 = prvBytesInBuffer (xStreamBuffer_13(D));
  Starting walk at: xBytesAvailable_19 = prvBytesInBuffer (xStreamBuffer_13(D));
  instance pointer: xStreamBuffer_13(D)  Outer instance pointer: xStreamBuffer_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xBytesAvailable_22 = prvBytesInBuffer (xStreamBuffer_13(D));
  Starting walk at: xBytesAvailable_22 = prvBytesInBuffer (xStreamBuffer_13(D));
  instance pointer: xStreamBuffer_13(D)  Outer instance pointer: xStreamBuffer_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortEnterCritical ();
Determining dynamic type for call: xBytesAvailable_30 = prvBytesInBuffer (xStreamBuffer_13(D));
  Starting walk at: xBytesAvailable_30 = prvBytesInBuffer (xStreamBuffer_13(D));
  instance pointer: xStreamBuffer_13(D)  Outer instance pointer: xStreamBuffer_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait_17(D));
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:xBytesAvailable_22 = prvBytesInBuffer (xStreamBuffer_13(D));
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:_3 = xTaskGetCurrentTaskHandle ();
  Function call may change dynamic type:xTaskGenericNotifyStateClear (0B, 0);
Determining dynamic type for call: xReceivedLength_33 = prvReadMessageFromBuffer (xStreamBuffer_13(D), pvRxData_15(D), xBufferLengthBytes_31(D), xBytesAvailable_7);
  Starting walk at: xReceivedLength_33 = prvReadMessageFromBuffer (xStreamBuffer_13(D), pvRxData_15(D), xBufferLengthBytes_31(D), xBytesAvailable_7);
  instance pointer: xStreamBuffer_13(D)  Outer instance pointer: xStreamBuffer_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xBytesAvailable_30 = prvBytesInBuffer (xStreamBuffer_13(D));
  Function call may change dynamic type:xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait_17(D));
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:xBytesAvailable_22 = prvBytesInBuffer (xStreamBuffer_13(D));
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:_3 = xTaskGetCurrentTaskHandle ();
  Function call may change dynamic type:xTaskGenericNotifyStateClear (0B, 0);
  Function call may change dynamic type:xBytesAvailable_19 = prvBytesInBuffer (xStreamBuffer_13(D));
Determining dynamic type for call: xReceivedLength_33 = prvReadMessageFromBuffer (xStreamBuffer_13(D), pvRxData_15(D), xBufferLengthBytes_31(D), xBytesAvailable_7);
  Starting walk at: xReceivedLength_33 = prvReadMessageFromBuffer (xStreamBuffer_13(D), pvRxData_15(D), xBufferLengthBytes_31(D), xBytesAvailable_7);
  instance pointer: pvRxData_15(D)  Outer instance pointer: pvRxData_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xBytesAvailable_30 = prvBytesInBuffer (xStreamBuffer_13(D));
  Function call may change dynamic type:xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait_17(D));
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:xBytesAvailable_22 = prvBytesInBuffer (xStreamBuffer_13(D));
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:_3 = xTaskGetCurrentTaskHandle ();
  Function call may change dynamic type:xTaskGenericNotifyStateClear (0B, 0);
  Function call may change dynamic type:xBytesAvailable_19 = prvBytesInBuffer (xStreamBuffer_13(D));
Determining dynamic type for call: xHead_20 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_10(D), &xDataLengthBytes, 4, xNextHead_11);
  Starting walk at: xHead_20 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_10(D), &xDataLengthBytes, 4, xNextHead_11);
  instance pointer: pxStreamBuffer_10(D)  Outer instance pointer: pxStreamBuffer_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xHead_20 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_10(D), &xDataLengthBytes, 4, xNextHead_11);
  Starting walk at: xHead_20 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_10(D), &xDataLengthBytes, 4, xNextHead_11);
  instance pointer: &xDataLengthBytes  Outer instance pointer: xDataLengthBytes offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = prvWriteBytesToBuffer (pxStreamBuffer_10(D), pvTxData_16(D), xDataLengthBytes.3_4, xNextHead_6);
  Starting walk at: _5 = prvWriteBytesToBuffer (pxStreamBuffer_10(D), pvTxData_16(D), xDataLengthBytes.3_4, xNextHead_6);
  instance pointer: pxStreamBuffer_10(D)  Outer instance pointer: pxStreamBuffer_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xHead_20 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_10(D), &xDataLengthBytes, 4, xNextHead_11);
Determining dynamic type for call: _5 = prvWriteBytesToBuffer (pxStreamBuffer_10(D), pvTxData_16(D), xDataLengthBytes.3_4, xNextHead_6);
  Starting walk at: _5 = prvWriteBytesToBuffer (pxStreamBuffer_10(D), pvTxData_16(D), xDataLengthBytes.3_4, xNextHead_6);
  instance pointer: pvTxData_16(D)  Outer instance pointer: pvTxData_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xHead_20 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_10(D), &xDataLengthBytes, 4, xNextHead_11);
Determining dynamic type for call: xSpace_16 = xStreamBufferSpacesAvailable (xStreamBuffer_9(D));
  Starting walk at: xSpace_16 = xStreamBufferSpacesAvailable (xStreamBuffer_9(D));
  instance pointer: xStreamBuffer_9(D)  Outer instance pointer: xStreamBuffer_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: xReturn_18 = prvWriteMessageToBuffer (xStreamBuffer_9(D), pvTxData_12(D), xDataLengthBytes_11(D), xSpace_16, xRequiredSpace_6);
  Starting walk at: xReturn_18 = prvWriteMessageToBuffer (xStreamBuffer_9(D), pvTxData_12(D), xDataLengthBytes_11(D), xSpace_16, xRequiredSpace_6);
  instance pointer: xStreamBuffer_9(D)  Outer instance pointer: xStreamBuffer_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xSpace_16 = xStreamBufferSpacesAvailable (xStreamBuffer_9(D));
Determining dynamic type for call: xReturn_18 = prvWriteMessageToBuffer (xStreamBuffer_9(D), pvTxData_12(D), xDataLengthBytes_11(D), xSpace_16, xRequiredSpace_6);
  Starting walk at: xReturn_18 = prvWriteMessageToBuffer (xStreamBuffer_9(D), pvTxData_12(D), xDataLengthBytes_11(D), xSpace_16, xRequiredSpace_6);
  instance pointer: pvTxData_12(D)  Outer instance pointer: pvTxData_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xSpace_16 = xStreamBufferSpacesAvailable (xStreamBuffer_9(D));
Determining dynamic type for call: _2 = prvBytesInBuffer (xStreamBuffer_9(D));
  Starting walk at: _2 = prvBytesInBuffer (xStreamBuffer_9(D));
  instance pointer: xStreamBuffer_9(D)  Outer instance pointer: xStreamBuffer_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xReturn_18 = prvWriteMessageToBuffer (xStreamBuffer_9(D), pvTxData_12(D), xDataLengthBytes_11(D), xSpace_16, xRequiredSpace_6);
  Function call may change dynamic type:xSpace_16 = xStreamBufferSpacesAvailable (xStreamBuffer_9(D));
Determining dynamic type for call: xSpace_35 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  Starting walk at: xSpace_35 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  instance pointer: xStreamBuffer_22(D)  Outer instance pointer: xStreamBuffer_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:vTaskSetTimeOutState (&xTimeOut);
  Function call may change dynamic type:_8 = xTaskCheckForTimeOut (&xTimeOut, &xTicksToWait);
  Function call may change dynamic type:xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait.1_7);
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:_6 = xTaskGetCurrentTaskHandle ();
  Function call may change dynamic type:xTaskGenericNotifyStateClear (0B, 0);
  Function call may change dynamic type:xSpace_35 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  Function call may change dynamic type:vPortEnterCritical ();
Determining dynamic type for call: xSpace_45 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  Starting walk at: xSpace_45 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  instance pointer: xStreamBuffer_22(D)  Outer instance pointer: xStreamBuffer_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:xSpace_35 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:vTaskSetTimeOutState (&xTimeOut);
  Function call may change dynamic type:_8 = xTaskCheckForTimeOut (&xTimeOut, &xTicksToWait);
  Function call may change dynamic type:xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait.1_7);
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:_6 = xTaskGetCurrentTaskHandle ();
  Function call may change dynamic type:xTaskGenericNotifyStateClear (0B, 0);
Determining dynamic type for call: xReturn_47 = prvWriteMessageToBuffer (xStreamBuffer_22(D), pvTxData_27(D), xDataLengthBytes_25(D), xSpace_14, xRequiredSpace_15);
  Starting walk at: xReturn_47 = prvWriteMessageToBuffer (xStreamBuffer_22(D), pvTxData_27(D), xDataLengthBytes_25(D), xSpace_14, xRequiredSpace_15);
  instance pointer: xStreamBuffer_22(D)  Outer instance pointer: xStreamBuffer_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:xSpace_35 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:vTaskSetTimeOutState (&xTimeOut);
  Function call may change dynamic type:_8 = xTaskCheckForTimeOut (&xTimeOut, &xTicksToWait);
  Function call may change dynamic type:xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait.1_7);
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:_6 = xTaskGetCurrentTaskHandle ();
  Function call may change dynamic type:xTaskGenericNotifyStateClear (0B, 0);
  Function call may change dynamic type:xSpace_45 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
Determining dynamic type for call: xReturn_47 = prvWriteMessageToBuffer (xStreamBuffer_22(D), pvTxData_27(D), xDataLengthBytes_25(D), xSpace_14, xRequiredSpace_15);
  Starting walk at: xReturn_47 = prvWriteMessageToBuffer (xStreamBuffer_22(D), pvTxData_27(D), xDataLengthBytes_25(D), xSpace_14, xRequiredSpace_15);
  instance pointer: pvTxData_27(D)  Outer instance pointer: pvTxData_27(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:xSpace_35 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:vTaskSetTimeOutState (&xTimeOut);
  Function call may change dynamic type:_8 = xTaskCheckForTimeOut (&xTimeOut, &xTicksToWait);
  Function call may change dynamic type:xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait.1_7);
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:_6 = xTaskGetCurrentTaskHandle ();
  Function call may change dynamic type:xTaskGenericNotifyStateClear (0B, 0);
  Function call may change dynamic type:xSpace_45 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
Determining dynamic type for call: _9 = prvBytesInBuffer (xStreamBuffer_22(D));
  Starting walk at: _9 = prvBytesInBuffer (xStreamBuffer_22(D));
  instance pointer: xStreamBuffer_22(D)  Outer instance pointer: xStreamBuffer_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:xReturn_47 = prvWriteMessageToBuffer (xStreamBuffer_22(D), pvTxData_27(D), xDataLengthBytes_25(D), xSpace_14, xRequiredSpace_15);
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:xSpace_35 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  Function call may change dynamic type:vPortEnterCritical ();
  Function call may change dynamic type:vTaskSetTimeOutState (&xTimeOut);
  Function call may change dynamic type:_8 = xTaskCheckForTimeOut (&xTimeOut, &xTicksToWait);
  Function call may change dynamic type:xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait.1_7);
  Function call may change dynamic type:vPortExitCritical ();
  Function call may change dynamic type:_6 = xTaskGetCurrentTaskHandle ();
  Function call may change dynamic type:xTaskGenericNotifyStateClear (0B, 0);
  Function call may change dynamic type:xSpace_45 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
Determining dynamic type for call: xReturn_4 = prvBytesInBuffer (xStreamBuffer_1(D));
  Starting walk at: xReturn_4 = prvBytesInBuffer (xStreamBuffer_1(D));
  instance pointer: xStreamBuffer_1(D)  Outer instance pointer: xStreamBuffer_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: prvInitialiseNewStreamBuffer (xStreamBuffer_9(D), _3, _4, _5, _6);
  Starting walk at: prvInitialiseNewStreamBuffer (xStreamBuffer_9(D), _3, _4, _5, _6);
  instance pointer: xStreamBuffer_9(D)  Outer instance pointer: xStreamBuffer_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortEnterCritical ();
Determining dynamic type for call: prvInitialiseNewStreamBuffer (xStreamBuffer_9(D), _3, _4, _5, _6);
  Starting walk at: prvInitialiseNewStreamBuffer (xStreamBuffer_9(D), _3, _4, _5, _6);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:vPortEnterCritical ();
Determining dynamic type for call: prvInitialiseNewStreamBuffer (pucAllocatedMemory_13, _2, xBufferSizeBytes_11, xTriggerLevelBytes_9, ucFlags_3);
  Starting walk at: prvInitialiseNewStreamBuffer (pucAllocatedMemory_13, _2, xBufferSizeBytes_11, xTriggerLevelBytes_9, ucFlags_3);
  instance pointer: pucAllocatedMemory_13  Outer instance pointer: pucAllocatedMemory_13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pucAllocatedMemory_13 = pvPortMalloc (_1);
Determining dynamic type for call: prvInitialiseNewStreamBuffer (pucAllocatedMemory_13, _2, xBufferSizeBytes_11, xTriggerLevelBytes_9, ucFlags_3);
  Starting walk at: prvInitialiseNewStreamBuffer (pucAllocatedMemory_13, _2, xBufferSizeBytes_11, xTriggerLevelBytes_9, ucFlags_3);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pucAllocatedMemory_13 = pvPortMalloc (_1);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  xStreamBufferSpacesAvailable.part.0/62:
  Jump functions of caller  prvReadBytesFromBuffer.part.0/53:
  Jump functions of caller  prvWriteBytesToBuffer.part.0/48:
  Jump functions of caller  prvInitialiseNewStreamBuffer.part.0/44:
  Jump functions of caller  xTaskGenericNotifyFromISR/42:
  Jump functions of caller  memcpy/41:
  Jump functions of caller  xTaskResumeAll/40:
  Jump functions of caller  xTaskGenericNotify/39:
  Jump functions of caller  vTaskSuspendAll/38:
  Jump functions of caller  xTaskCheckForTimeOut/37:
  Jump functions of caller  xTaskGenericNotifyWait/36:
  Jump functions of caller  xTaskGetCurrentTaskHandle/35:
  Jump functions of caller  xTaskGenericNotifyStateClear/34:
  Jump functions of caller  vTaskSetTimeOutState/33:
  Jump functions of caller  vPortExitCritical/32:
  Jump functions of caller  vPortEnterCritical/31:
  Jump functions of caller  vPortFree/30:
  Jump functions of caller  memset/29:
  Jump functions of caller  pvPortMalloc/28:
  Jump functions of caller  ucStreamBufferGetStreamBufferType/27:
  Jump functions of caller  vStreamBufferSetStreamBufferNumber/26:
  Jump functions of caller  uxStreamBufferGetStreamBufferNumber/25:
  Jump functions of caller  prvInitialiseNewStreamBuffer/24:
    callsite  prvInitialiseNewStreamBuffer/24 -> prvInitialiseNewStreamBuffer.part.0/44 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  prvBytesInBuffer/23:
  Jump functions of caller  prvReadBytesFromBuffer/22:
    callsite  prvReadBytesFromBuffer/22 -> prvReadBytesFromBuffer.part.0/53 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  prvWriteBytesToBuffer/21:
    callsite  prvWriteBytesToBuffer/21 -> prvWriteBytesToBuffer.part.0/48 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferReceiveCompletedFromISR/20:
  Jump functions of caller  xStreamBufferSendCompletedFromISR/19:
  Jump functions of caller  xStreamBufferIsFull/18:
    callsite  xStreamBufferIsFull/18 -> xStreamBufferSpacesAvailable/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferIsEmpty/17:
  Jump functions of caller  prvReadMessageFromBuffer/16:
    callsite  prvReadMessageFromBuffer/16 -> prvReadBytesFromBuffer/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  prvReadMessageFromBuffer/16 -> prvReadBytesFromBuffer.part.0/53 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferReceiveFromISR/15:
    callsite  xStreamBufferReceiveFromISR/15 -> prvReadMessageFromBuffer/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferReceiveFromISR/15 -> prvBytesInBuffer/23 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferNextMessageLengthBytes/14:
    callsite  xStreamBufferNextMessageLengthBytes/14 -> prvReadBytesFromBuffer/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferNextMessageLengthBytes/14 -> prvBytesInBuffer/23 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferReceive/13:
    callsite  xStreamBufferReceive/13 -> prvReadMessageFromBuffer/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferReceive/13 -> prvBytesInBuffer/23 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferReceive/13 -> prvBytesInBuffer/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 128, cst: 0B
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferReceive/13 -> prvBytesInBuffer/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  prvWriteMessageToBuffer/12:
    callsite  prvWriteMessageToBuffer/12 -> prvWriteBytesToBuffer/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  prvWriteMessageToBuffer/12 -> prvWriteBytesToBuffer.part.0/48 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferSendFromISR/11:
    callsite  xStreamBufferSendFromISR/11 -> prvBytesInBuffer/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferSendFromISR/11 -> prvWriteMessageToBuffer/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferSendFromISR/11 -> xStreamBufferSpacesAvailable/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferSend/10:
    callsite  xStreamBufferSend/10 -> prvBytesInBuffer/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferSend/10 -> prvWriteMessageToBuffer/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferSend/10 -> xStreamBufferSpacesAvailable/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  xStreamBufferSend/10 -> xStreamBufferSpacesAvailable/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferBytesAvailable/9:
    callsite  xStreamBufferBytesAvailable/9 -> prvBytesInBuffer/23 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  xStreamBufferSpacesAvailable/8:
    callsite  xStreamBufferSpacesAvailable/8 -> xStreamBufferSpacesAvailable.part.0/62 : 
  Jump functions of caller  xStreamBufferSetTriggerLevel/7:
  Jump functions of caller  xStreamBufferReset/6:
    callsite  xStreamBufferReset/6 -> prvInitialiseNewStreamBuffer/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  vStreamBufferDelete/5:
  Jump functions of caller  xStreamBufferGenericCreate/4:
    callsite  xStreamBufferGenericCreate/4 -> prvInitialiseNewStreamBuffer/24 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: PASS THROUGH: 0, op plus_expr 1
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]

 Propagating constants:

Not considering ucStreamBufferGetStreamBufferType for cloning; -fipa-cp-clone disabled.
Not considering vStreamBufferSetStreamBufferNumber for cloning; -fipa-cp-clone disabled.
Not considering uxStreamBufferGetStreamBufferNumber for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferReceiveCompletedFromISR for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferSendCompletedFromISR for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferIsFull for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferIsEmpty for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferReceiveFromISR for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferNextMessageLengthBytes for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferReceive for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferSendFromISR for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferSend for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferBytesAvailable for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferSpacesAvailable for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferSetTriggerLevel for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferReset for cloning; -fipa-cp-clone disabled.
Not considering vStreamBufferDelete for cloning; -fipa-cp-clone disabled.
Not considering xStreamBufferGenericCreate for cloning; -fipa-cp-clone disabled.

overall_size: 876, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: xStreamBufferSpacesAvailable.part.0/62:
  Node: prvReadBytesFromBuffer.part.0/53:
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
               4 [loc_time: 1, loc_size: 45, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: prvWriteBytesToBuffer.part.0/48:
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
               4 [loc_time: 1, loc_size: 46, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: prvInitialiseNewStreamBuffer.part.0/44:
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
  Node: ucStreamBufferGetStreamBufferType/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vStreamBufferSetStreamBufferNumber/26:
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
  Node: uxStreamBufferGetStreamBufferNumber/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: prvInitialiseNewStreamBuffer/24:
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
  Node: prvBytesInBuffer/23:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: prvReadBytesFromBuffer/22:
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
               4 [loc_time: 3, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: prvWriteBytesToBuffer/21:
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
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: xStreamBufferReceiveCompletedFromISR/20:
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
  Node: xStreamBufferSendCompletedFromISR/19:
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
  Node: xStreamBufferIsFull/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xStreamBufferIsEmpty/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: prvReadMessageFromBuffer/16:
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
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: xStreamBufferReceiveFromISR/15:
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
  Node: xStreamBufferNextMessageLengthBytes/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xStreamBufferReceive/13:
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
  Node: prvWriteMessageToBuffer/12:
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
  Node: xStreamBufferSendFromISR/11:
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
  Node: xStreamBufferSend/10:
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
  Node: xStreamBufferBytesAvailable/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xStreamBufferSpacesAvailable/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xStreamBufferSetTriggerLevel/7:
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
  Node: xStreamBufferReset/6:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: vStreamBufferDelete/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: xStreamBufferGenericCreate/4:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

xStreamBufferSpacesAvailable.part.0/62 (xStreamBufferSpacesAvailable.part.0) @06eefee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:107374 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: xStreamBufferSpacesAvailable/8 (107374 (estimated locally),0.30 per call) 
  Calls: 
prvReadBytesFromBuffer.part.0/53 (prvReadBytesFromBuffer.part.0) @06eefe00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: prvReadMessageFromBuffer/16 (354334802 (estimated locally),0.33 per call) prvReadBytesFromBuffer/22 (107374 (estimated locally),0.50 per call) 
  Calls: memcpy/41 (35433 (estimated locally),0.16 per call) memcpy/41 (11693 (estimated locally),0.05 per call) 
prvWriteBytesToBuffer.part.0/48 (prvWriteBytesToBuffer.part.0) @06eefd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:160260 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: prvWriteMessageToBuffer/12 (177167401 (estimated locally),0.17 per call) prvWriteBytesToBuffer/21 (107374 (estimated locally),0.50 per call) 
  Calls: memcpy/41 (52886 (estimated locally),0.33 per call) memcpy/41 (8726 (estimated locally),0.05 per call) 
prvInitialiseNewStreamBuffer.part.0/44 (prvInitialiseNewStreamBuffer.part.0) @06db69a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: prvInitialiseNewStreamBuffer/24 (22666 (estimated locally),0.17 per call) 
  Calls: memset/29 (1073741824 (estimated locally),1.00 per call) 
xTaskGenericNotifyFromISR/42 (xTaskGenericNotifyFromISR) @06eb3700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceiveCompletedFromISR/20 (133963 (estimated locally),0.37 per call) xStreamBufferSendCompletedFromISR/19 (133963 (estimated locally),0.37 per call) xStreamBufferReceiveFromISR/15 (15473 (estimated locally),0.04 per call) xStreamBufferSendFromISR/11 (15473 (estimated locally),0.04 per call) 
  Calls: 
memcpy/41 (memcpy) @06eb3540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prvReadBytesFromBuffer.part.0/53 (35433 (estimated locally),0.16 per call) prvReadBytesFromBuffer.part.0/53 (11693 (estimated locally),0.05 per call) prvWriteBytesToBuffer.part.0/48 (52886 (estimated locally),0.33 per call) prvWriteBytesToBuffer.part.0/48 (8726 (estimated locally),0.05 per call) 
  Calls: 
xTaskResumeAll/40 (xTaskResumeAll) @06eb32a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceive/13 (15156 (estimated locally),0.04 per call) xStreamBufferSend/10 (11938 (estimated locally),0.03 per call) 
  Calls: 
xTaskGenericNotify/39 (xTaskGenericNotify) @06eb31c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceive/13 (8104 (estimated locally),0.02 per call) xStreamBufferSend/10 (6383 (estimated locally),0.02 per call) 
  Calls: 
vTaskSuspendAll/38 (vTaskSuspendAll) @06eb30e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceive/13 (15156 (estimated locally),0.04 per call) xStreamBufferSend/10 (11938 (estimated locally),0.03 per call) 
  Calls: 
xTaskCheckForTimeOut/37 (xTaskCheckForTimeOut) @06eb3000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferSend/10 (576777 (estimated locally),1.61 per call) 
  Calls: 
xTaskGenericNotifyWait/36 (xTaskGenericNotifyWait) @06e90ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceive/13 (16991 (estimated locally),0.05 per call) xStreamBufferSend/10 (576777 (estimated locally),1.61 per call) 
  Calls: 
xTaskGetCurrentTaskHandle/35 (xTaskGetCurrentTaskHandle) @06e90e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceive/13 (7642 (estimated locally),0.02 per call) xStreamBufferSend/10 (576777 (estimated locally),1.61 per call) 
  Calls: 
xTaskGenericNotifyStateClear/34 (xTaskGenericNotifyStateClear) @06e90d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceive/13 (43844 (estimated locally),0.12 per call) xStreamBufferSend/10 (598690 (estimated locally),1.67 per call) 
  Calls: 
vTaskSetTimeOutState/33 (vTaskSetTimeOutState) @06e90c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferSend/10 (65767 (estimated locally),0.18 per call) 
  Calls: 
vPortExitCritical/32 (vPortExitCritical) @06e90540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceive/13 (51486 (estimated locally),0.14 per call) xStreamBufferSend/10 (22744 (estimated locally),0.06 per call) xStreamBufferSend/10 (576777 (estimated locally),1.61 per call) xStreamBufferReset/6 (123389 (estimated locally),0.53 per call) 
  Calls: 
vPortEnterCritical/31 (vPortEnterCritical) @06e90460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferReceive/13 (87689 (estimated locally),0.25 per call) xStreamBufferSend/10 (621434 (estimated locally),1.74 per call) xStreamBufferReset/6 (123389 (estimated locally),0.53 per call) 
  Calls: 
vPortFree/30 (vPortFree) @06e902a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vStreamBufferDelete/5 (125270 (estimated locally),0.35 per call) 
  Calls: 
memset/29 (memset) @06e900e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: vStreamBufferDelete/5 (125270 (estimated locally),0.35 per call) prvInitialiseNewStreamBuffer/24 (130040 (estimated locally),1.00 per call) prvInitialiseNewStreamBuffer.part.0/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pvPortMalloc/28 (pvPortMalloc) @06e85540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xStreamBufferGenericCreate/4 (44471 (estimated locally),0.14 per call) 
  Calls: 
ucStreamBufferGetStreamBufferType/27 (ucStreamBufferGetStreamBufferType) @06e85c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vStreamBufferSetStreamBufferNumber/26 (vStreamBufferSetStreamBufferNumber) @06e859a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
uxStreamBufferGetStreamBufferNumber/25 (uxStreamBufferGetStreamBufferNumber) @06e85700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
prvInitialiseNewStreamBuffer/24 (prvInitialiseNewStreamBuffer) @06e85460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:130040 (estimated locally) body local optimize_size
  Called by: xStreamBufferReset/6 (6452 (estimated locally),0.03 per call) xStreamBufferGenericCreate/4 (23779 (estimated locally),0.07 per call) 
  Calls: prvInitialiseNewStreamBuffer.part.0/44 (22666 (estimated locally),0.17 per call) memset/29 (130040 (estimated locally),1.00 per call) 
prvBytesInBuffer/23 (prvBytesInBuffer) @06e851c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: xStreamBufferReceiveFromISR/15 (175378 (estimated locally),0.49 per call) xStreamBufferNextMessageLengthBytes/14 (82678 (estimated locally),0.23 per call) xStreamBufferReceive/13 (87689 (estimated locally),0.25 per call) xStreamBufferReceive/13 (16991 (estimated locally),0.05 per call) xStreamBufferReceive/13 (87689 (estimated locally),0.25 per call) xStreamBufferSendFromISR/11 (57875 (estimated locally),0.16 per call) xStreamBufferSend/10 (36175 (estimated locally),0.10 per call) xStreamBufferBytesAvailable/9 (123389 (estimated locally),0.53 per call) 
  Calls: 
prvReadBytesFromBuffer/22 (prvReadBytesFromBuffer) @06e32c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: xStreamBufferNextMessageLengthBytes/14 (27284 (estimated locally),0.08 per call) prvReadMessageFromBuffer/16 (354334802 (estimated locally),0.33 per call) 
  Calls: prvReadBytesFromBuffer.part.0/53 (107374 (estimated locally),0.50 per call) 
prvWriteBytesToBuffer/21 (prvWriteBytesToBuffer) @06e32ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: prvWriteMessageToBuffer/12 (354334802 (estimated locally),0.33 per call) 
  Calls: prvWriteBytesToBuffer.part.0/48 (107374 (estimated locally),0.50 per call) 
xStreamBufferReceiveCompletedFromISR/20 (xStreamBufferReceiveCompletedFromISR) @06e32b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskGenericNotifyFromISR/42 (133963 (estimated locally),0.37 per call) 
xStreamBufferSendCompletedFromISR/19 (xStreamBufferSendCompletedFromISR) @06e327e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskGenericNotifyFromISR/42 (133963 (estimated locally),0.37 per call) 
xStreamBufferIsFull/18 (xStreamBufferIsFull) @06e32460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: xStreamBufferSpacesAvailable/8 (250539 (estimated locally),0.70 per call) 
xStreamBufferIsEmpty/17 (xStreamBufferIsEmpty) @06e320e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
prvReadMessageFromBuffer/16 (prvReadMessageFromBuffer) @06e28a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: xStreamBufferReceiveFromISR/15 (57875 (estimated locally),0.16 per call) xStreamBufferReceive/13 (45928 (estimated locally),0.13 per call) 
  Calls: prvReadBytesFromBuffer/22 (354334802 (estimated locally),0.33 per call) prvReadBytesFromBuffer.part.0/53 (354334802 (estimated locally),0.33 per call) 
xStreamBufferReceiveFromISR/15 (xStreamBufferReceiveFromISR) @06e28e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskGenericNotifyFromISR/42 (15473 (estimated locally),0.04 per call) prvReadMessageFromBuffer/16 (57875 (estimated locally),0.16 per call) prvBytesInBuffer/23 (175378 (estimated locally),0.49 per call) 
xStreamBufferNextMessageLengthBytes/14 (xStreamBufferNextMessageLengthBytes) @06e289a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: prvReadBytesFromBuffer/22 (27284 (estimated locally),0.08 per call) prvBytesInBuffer/23 (82678 (estimated locally),0.23 per call) 
xStreamBufferReceive/13 (xStreamBufferReceive) @06e28540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskResumeAll/40 (15156 (estimated locally),0.04 per call) xTaskGenericNotify/39 (8104 (estimated locally),0.02 per call) vTaskSuspendAll/38 (15156 (estimated locally),0.04 per call) prvReadMessageFromBuffer/16 (45928 (estimated locally),0.13 per call) prvBytesInBuffer/23 (87689 (estimated locally),0.25 per call) prvBytesInBuffer/23 (16991 (estimated locally),0.05 per call) xTaskGenericNotifyWait/36 (16991 (estimated locally),0.05 per call) vPortExitCritical/32 (51486 (estimated locally),0.14 per call) xTaskGetCurrentTaskHandle/35 (7642 (estimated locally),0.02 per call) xTaskGenericNotifyStateClear/34 (43844 (estimated locally),0.12 per call) prvBytesInBuffer/23 (87689 (estimated locally),0.25 per call) vPortEnterCritical/31 (87689 (estimated locally),0.25 per call) 
prvWriteMessageToBuffer/12 (prvWriteMessageToBuffer) @06e28000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: xStreamBufferSendFromISR/11 (175378 (estimated locally),0.49 per call) xStreamBufferSend/10 (109621 (estimated locally),0.31 per call) 
  Calls: prvWriteBytesToBuffer/21 (354334802 (estimated locally),0.33 per call) prvWriteBytesToBuffer.part.0/48 (177167401 (estimated locally),0.17 per call) 
xStreamBufferSendFromISR/11 (xStreamBufferSendFromISR) @06e1b380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskGenericNotifyFromISR/42 (15473 (estimated locally),0.04 per call) prvBytesInBuffer/23 (57875 (estimated locally),0.16 per call) prvWriteMessageToBuffer/12 (175378 (estimated locally),0.49 per call) xStreamBufferSpacesAvailable/8 (175378 (estimated locally),0.49 per call) 
xStreamBufferSend/10 (xStreamBufferSend) @06e1bc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskResumeAll/40 (11938 (estimated locally),0.03 per call) xTaskGenericNotify/39 (6383 (estimated locally),0.02 per call) vTaskSuspendAll/38 (11938 (estimated locally),0.03 per call) prvBytesInBuffer/23 (36175 (estimated locally),0.10 per call) prvWriteMessageToBuffer/12 (109621 (estimated locally),0.31 per call) xStreamBufferSpacesAvailable/8 (87694 (estimated locally),0.25 per call) vPortExitCritical/32 (22744 (estimated locally),0.06 per call) xTaskCheckForTimeOut/37 (576777 (estimated locally),1.61 per call) xTaskGenericNotifyWait/36 (576777 (estimated locally),1.61 per call) vPortExitCritical/32 (576777 (estimated locally),1.61 per call) xTaskGetCurrentTaskHandle/35 (576777 (estimated locally),1.61 per call) xTaskGenericNotifyStateClear/34 (598690 (estimated locally),1.67 per call) xStreamBufferSpacesAvailable/8 (621434 (estimated locally),1.74 per call) vPortEnterCritical/31 (621434 (estimated locally),1.74 per call) vTaskSetTimeOutState/33 (65767 (estimated locally),0.18 per call) 
xStreamBufferBytesAvailable/9 (xStreamBufferBytesAvailable) @06e1b620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: prvBytesInBuffer/23 (123389 (estimated locally),0.53 per call) 
xStreamBufferSpacesAvailable/8 (xStreamBufferSpacesAvailable) @06e1b2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: xStreamBufferIsFull/18 (250539 (estimated locally),0.70 per call) xStreamBufferSendFromISR/11 (175378 (estimated locally),0.49 per call) xStreamBufferSend/10 (87694 (estimated locally),0.25 per call) xStreamBufferSend/10 (621434 (estimated locally),1.74 per call) 
  Calls: xStreamBufferSpacesAvailable.part.0/62 (107374 (estimated locally),0.30 per call) 
xStreamBufferSetTriggerLevel/7 (xStreamBufferSetTriggerLevel) @06e7ac40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xStreamBufferReset/6 (xStreamBufferReset) @06e7aee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: vPortExitCritical/32 (123389 (estimated locally),0.53 per call) prvInitialiseNewStreamBuffer/24 (6452 (estimated locally),0.03 per call) vPortEnterCritical/31 (123389 (estimated locally),0.53 per call) 
vStreamBufferDelete/5 (vStreamBufferDelete) @06e7ab60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: memset/29 (125270 (estimated locally),0.35 per call) vPortFree/30 (125270 (estimated locally),0.35 per call) 
xStreamBufferGenericCreate/4 (xStreamBufferGenericCreate) @06e7a7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:325376 (estimated locally) body optimize_size
  Called by: 
  Calls: prvInitialiseNewStreamBuffer/24 (23779 (estimated locally),0.07 per call) pvPortMalloc/28 (44471 (estimated locally),0.14 per call) 

;; Function prvBytesInBuffer (prvBytesInBuffer, funcdef_no=23, decl_uid=6107, cgraph_uid=24, symbol_order=23)

Modification phase of node prvBytesInBuffer/23
prvBytesInBuffer (const struct StreamBuffer_t * const pxStreamBuffer)
{
  size_t xCount;
  unsigned int _1;
  unsigned int _2;
  unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pxStreamBuffer_5(D)->xLength;
  _2 ={v} pxStreamBuffer_5(D)->xHead;
  xCount_6 = _1 + _2;
  # DEBUG xCount => xCount_6
  # DEBUG BEGIN_STMT
  _7 ={v} pxStreamBuffer_5(D)->xTail;
  xCount_8 = xCount_6 - _7;
  # DEBUG xCount => xCount_8
  # DEBUG BEGIN_STMT
  if (_1 <= xCount_8)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  xCount_9 = xCount_8 - _1;
  # DEBUG xCount => xCount_9

  <bb 4> [local count: 1073741824]:
  # xCount_3 = PHI <xCount_8(2), xCount_9(3)>
  # DEBUG xCount => xCount_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xCount_3;

}



;; Function prvInitialiseNewStreamBuffer (prvInitialiseNewStreamBuffer, funcdef_no=24, decl_uid=6134, cgraph_uid=25, symbol_order=24)

Modification phase of node prvInitialiseNewStreamBuffer/24
prvInitialiseNewStreamBuffer (struct StreamBuffer_t * const pxStreamBuffer, uint8_t * const pucBuffer, size_t xBufferSizeBytes, size_t xTriggerLevelBytes, uint8_t ucFlags)
{
  uint32_t ulNewBASEPRI;
  void * _1;

  <bb 2> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG xWriteValue => 85
  # DEBUG BEGIN_STMT
  _1 = memset (pucBuffer_4(D), 85, xBufferSizeBytes_5(D));
  if (_1 != pucBuffer_4(D))
    goto <bb 3>; [82.57%]
  else
    goto <bb 5>; [17.43%]

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

  <bb 5> [local count: 22666]:
  prvInitialiseNewStreamBuffer.part.0 (pxStreamBuffer_7(D), pucBuffer_4(D), xBufferSizeBytes_5(D), xTriggerLevelBytes_8(D), ucFlags_9(D));
  return;

}



;; Function prvWriteBytesToBuffer.part.0 (prvWriteBytesToBuffer.part.0, funcdef_no=29, decl_uid=6645, cgraph_uid=49, symbol_order=48)

Modification phase of node prvWriteBytesToBuffer.part.0/48
prvWriteBytesToBuffer.part.0 (struct StreamBuffer_t * const pxStreamBuffer, const uint8_t * pucData, size_t xCount, size_t xHead)
{
  size_t xFirstLength;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  unsigned int _2;
  unsigned int _4;
  unsigned int _7;
  uint8_t * _9;
  uint8_t * _10;
  unsigned int _12;
  unsigned int _13;
  uint8_t * _15;
  const uint8_t * _16;
  unsigned int _18;

  <bb 15> [local count: 160260]:

  <bb 2> [local count: 160260]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pxStreamBuffer_1(D)->xLength;
  _4 = _2 - xHead_3(D);
  xFirstLength_6 = MIN_EXPR <_4, xCount_5(D)>;
  # DEBUG xFirstLength => xFirstLength_6
  # DEBUG BEGIN_STMT
  _7 = xHead_3(D) + xFirstLength_6;
  if (_2 < _7)
    goto <bb 3>; [67.00%]
  else
    goto <bb 6>; [33.00%]

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

  <bb 5> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = pxStreamBuffer_1(D)->pucBuffer;
  _10 = _9 + xHead_3(D);
  memcpy (_10, pucData_11(D), xFirstLength_6);
  # DEBUG BEGIN_STMT
  if (xCount_5(D) > xFirstLength_6)
    goto <bb 7>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 7> [local count: 26443]:
  # DEBUG BEGIN_STMT
  _12 = xCount_5(D) - xFirstLength_6;
  _13 = pxStreamBuffer_1(D)->xLength;
  if (_12 > _13)
    goto <bb 8>; [67.00%]
  else
    goto <bb 11>; [33.00%]

  <bb 8> [local count: 17717]:
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
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_14

  <bb 9> [local count: 177167401]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 177167401]:
  goto <bb 9>; [100.00%]

  <bb 11> [local count: 8726]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = pxStreamBuffer_1(D)->pucBuffer;
  _16 = pucData_11(D) + xFirstLength_6;
  memcpy (_15, _16, _12);

  <bb 12> [local count: 35169]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xHead_17 = xHead_3(D) + xCount_5(D);
  # DEBUG xHead => xHead_17
  # DEBUG BEGIN_STMT
  _18 = pxStreamBuffer_1(D)->xLength;
  if (xHead_17 >= _18)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 17584]:
  # DEBUG BEGIN_STMT
  xHead_19 = xHead_17 - _18;
  # DEBUG xHead => xHead_19

  <bb 14> [local count: 35169]:
  # xHead_20 = PHI <xHead_17(12), xHead_19(13)>
  # DEBUG xHead => xHead_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xHead_20;

}



;; Function prvWriteMessageToBuffer (prvWriteMessageToBuffer, funcdef_no=12, decl_uid=6123, cgraph_uid=13, symbol_order=12)

Modification phase of node prvWriteMessageToBuffer/12
prvWriteMessageToBuffer (struct StreamBuffer_t * const pxStreamBuffer, const void * pvTxData, size_t xDataLengthBytes, size_t xSpace, size_t xRequiredSpace)
{
  size_t xHead;
  size_t xNextHead;
  unsigned char _1;
  unsigned int xDataLengthBytes.2_2;
  unsigned int _3;
  unsigned int xDataLengthBytes.3_4;
  unsigned int _5;
  size_t _19;
  unsigned char _22;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  xNextHead_11 ={v} pxStreamBuffer_10(D)->xHead;
  # DEBUG xNextHead => xNextHead_11
  # DEBUG BEGIN_STMT
  _1 = pxStreamBuffer_10(D)->ucFlags;
  _22 = _1 & 1;
  if (_22 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (xSpace_12(D) >= xRequiredSpace_14(D))
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => pxStreamBuffer_10(D)
  # DEBUG pucData => &xDataLengthBytes
  # DEBUG xCount => 4
  # DEBUG xHead => xNextHead_11
  # DEBUG INLINE_ENTRY prvWriteBytesToBuffer
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xHead_20 = prvWriteBytesToBuffer.part.0 (pxStreamBuffer_10(D), &xDataLengthBytes, 4, xNextHead_11);
  # DEBUG xHead => xHead_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => NULL
  # DEBUG pucData => NULL
  # DEBUG xCount => NULL
  # DEBUG xHead => NULL
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG xNextHead => xHead_20
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 359703511]:
  # DEBUG BEGIN_STMT
  xDataLengthBytes = 0;
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  xDataLengthBytes.2_2 = xDataLengthBytes;
  _3 = MIN_EXPR <xDataLengthBytes.2_2, xSpace_12(D)>;
  xDataLengthBytes = _3;

  <bb 7> [local count: 1073741824]:
  # xNextHead_6 = PHI <xNextHead_11(5), xNextHead_11(6), xHead_20(4)>
  # DEBUG xNextHead => xNextHead_6
  # DEBUG BEGIN_STMT
  xDataLengthBytes.3_4 = xDataLengthBytes;
  if (xDataLengthBytes.3_4 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _5 = prvWriteBytesToBuffer (pxStreamBuffer_10(D), pvTxData_16(D), xDataLengthBytes.3_4, xNextHead_6);
  pxStreamBuffer_10(D)->xHead ={v} _5;

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _19 = xDataLengthBytes;
  return _19;

}



;; Function prvReadBytesFromBuffer.part.0 (prvReadBytesFromBuffer.part.0, funcdef_no=30, decl_uid=6668, cgraph_uid=54, symbol_order=53)

Modification phase of node prvReadBytesFromBuffer.part.0/53
prvReadBytesFromBuffer.part.0 (struct StreamBuffer_t * pxStreamBuffer, uint8_t * pucData, size_t xCount, size_t xTail)
{
  size_t xFirstLength;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  unsigned int _2;
  unsigned int _4;
  unsigned int _8;
  uint8_t * _10;
  uint8_t * _11;
  uint8_t * _13;
  uint8_t * _14;
  unsigned int _15;
  unsigned int _17;

  <bb 15> [local count: 214748]:

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pxStreamBuffer_1(D)->xLength;
  _4 = _2 - xTail_3(D);
  xFirstLength_6 = MIN_EXPR <_4, xCount_5(D)>;
  # DEBUG xFirstLength => xFirstLength_6
  # DEBUG BEGIN_STMT
  if (xCount_5(D) < xFirstLength_6)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

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
" : "=r" ulNewBASEPRI_7 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_7

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = xTail_3(D) + xFirstLength_6;
  if (_2 < _8)
    goto <bb 7>; [67.00%]
  else
    goto <bb 10>; [33.00%]

  <bb 7> [local count: 71941]:
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

  <bb 8> [local count: 719407023]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 719407023]:
  goto <bb 8>; [100.00%]

  <bb 10> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = pxStreamBuffer_1(D)->pucBuffer;
  _11 = _10 + xTail_3(D);
  memcpy (pucData_12(D), _11, xFirstLength_6);
  # DEBUG BEGIN_STMT
  if (xCount_5(D) > xFirstLength_6)
    goto <bb 11>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 11> [local count: 11693]:
  # DEBUG BEGIN_STMT
  _13 = pucData_12(D) + xFirstLength_6;
  _14 = pxStreamBuffer_1(D)->pucBuffer;
  _15 = xCount_5(D) - xFirstLength_6;
  memcpy (_13, _14, _15);

  <bb 12> [local count: 35433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTail_16 = xTail_3(D) + xCount_5(D);
  # DEBUG xTail => xTail_16
  # DEBUG BEGIN_STMT
  _17 = pxStreamBuffer_1(D)->xLength;
  if (xTail_16 >= _17)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 17717]:
  # DEBUG BEGIN_STMT
  xTail_18 = xTail_16 - _17;
  # DEBUG xTail => xTail_18

  <bb 14> [local count: 35433]:
  # xTail_19 = PHI <xTail_16(12), xTail_18(13)>
  # DEBUG xTail => xTail_19
  # DEBUG BEGIN_STMT
  return xTail_19;

}



;; Function prvReadMessageFromBuffer (prvReadMessageFromBuffer, funcdef_no=16, decl_uid=6117, cgraph_uid=17, symbol_order=16)

Modification phase of node prvReadMessageFromBuffer/16
prvReadMessageFromBuffer (struct StreamBuffer_t * pxStreamBuffer, void * pvRxData, size_t xBufferLengthBytes, size_t xBytesAvailable)
{
  size_t xTail;
  size_t xNextTail;
  size_t xTempNextMessageLength;
  size_t xNextMessageLength;
  size_t xCount;
  unsigned char _1;
  unsigned int _2;
  unsigned char _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xNextTail_10 ={v} pxStreamBuffer_9(D)->xTail;
  # DEBUG xNextTail => xNextTail_10
  # DEBUG BEGIN_STMT
  _1 = pxStreamBuffer_9(D)->ucFlags;
  _12 = _1 & 1;
  if (_12 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => pxStreamBuffer_9(D)
  # DEBUG pucData => &xTempNextMessageLength
  # DEBUG xCount => 4
  # DEBUG xTail => xNextTail_10
  # DEBUG INLINE_ENTRY prvReadBytesFromBuffer
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTail_21 = prvReadBytesFromBuffer.part.0 (pxStreamBuffer_9(D), &xTempNextMessageLength, 4, xNextTail_10);
  # DEBUG xTail => xTail_21
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => NULL
  # DEBUG pucData => NULL
  # DEBUG xCount => NULL
  # DEBUG xTail => NULL
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG xNextTail => xTail_21
  # DEBUG BEGIN_STMT
  xNextMessageLength_14 = xTempNextMessageLength;
  # DEBUG xNextMessageLength => xNextMessageLength_14
  # DEBUG BEGIN_STMT
  xBytesAvailable_15 = xBytesAvailable_13(D) + 4294967292;
  # DEBUG xBytesAvailable => xBytesAvailable_15
  # DEBUG BEGIN_STMT
  if (xBufferLengthBytes_11(D) < xNextMessageLength_14)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  # DEBUG xNextMessageLength => 0

  <bb 5> [local count: 1073741824]:
  # xBytesAvailable_3 = PHI <xBytesAvailable_15(4), xBytesAvailable_13(D)(2), xBytesAvailable_15(3)>
  # xNextMessageLength_4 = PHI <0(4), xBufferLengthBytes_11(D)(2), xNextMessageLength_14(3)>
  # xNextTail_5 = PHI <xTail_21(4), xNextTail_10(2), xTail_21(3)>
  # DEBUG xNextTail => xNextTail_5
  # DEBUG xNextMessageLength => xNextMessageLength_4
  # DEBUG xBytesAvailable => xBytesAvailable_3
  # DEBUG BEGIN_STMT
  xCount_16 = MIN_EXPR <xBytesAvailable_3, xNextMessageLength_4>;
  # DEBUG xCount => xCount_16
  # DEBUG BEGIN_STMT
  if (xCount_16 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = prvReadBytesFromBuffer (pxStreamBuffer_9(D), pvRxData_17(D), xCount_16, xNextTail_5);
  pxStreamBuffer_9(D)->xTail ={v} _2;

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  xTempNextMessageLength ={v} {CLOBBER};
  return xCount_16;

}



;; Function xStreamBufferGenericCreate (xStreamBufferGenericCreate, funcdef_no=4, decl_uid=6080, cgraph_uid=5, symbol_order=4)

Modification phase of node xStreamBufferGenericCreate/4
xStreamBufferGenericCreate (size_t xBufferSizeBytes, size_t xTriggerLevelBytes, BaseType_t xIsMessageBuffer)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint8_t ucFlags;
  uint8_t * pucAllocatedMemory;
  unsigned int _1;
  uint8_t * _2;

  <bb 2> [local count: 325376]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xIsMessageBuffer_5(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 3> [local count: 110628]:
  # DEBUG BEGIN_STMT
  # DEBUG ucFlags => 1
  # DEBUG BEGIN_STMT
  if (xBufferSizeBytes_6(D) <= 4)
    goto <bb 4>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 4> [local count: 55314]:
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

  <bb 5> [local count: 553139728]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 553139728]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG ucFlags => 0
  # DEBUG BEGIN_STMT
  if (xBufferSizeBytes_6(D) == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

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
" : "=r" ulNewBASEPRI_16 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_16

  <bb 8> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 1073741824]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 162688]:
  # ucFlags_3 = PHI <1(3), 0(6)>
  # DEBUG ucFlags => ucFlags_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xBufferSizeBytes_6(D) < xTriggerLevelBytes_8(D))
    goto <bb 10>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 10> [local count: 81344]:
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
" : "=r" ulNewBASEPRI_17 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_17

  <bb 11> [local count: 813440776]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 813440776]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 81344]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTriggerLevelBytes_9 = MAX_EXPR <1, xTriggerLevelBytes_8(D)>;
  # DEBUG xTriggerLevelBytes => xTriggerLevelBytes_9
  # DEBUG BEGIN_STMT
  if (xBufferSizeBytes_6(D) <= 4294967258)
    goto <bb 13>; [54.67%]
  else
    goto <bb 15>; [45.33%]

  <bb 13> [local count: 44471]:
  # DEBUG BEGIN_STMT
  xBufferSizeBytes_11 = xBufferSizeBytes_6(D) + 1;
  # DEBUG xBufferSizeBytes => xBufferSizeBytes_11
  # DEBUG BEGIN_STMT
  _1 = xBufferSizeBytes_6(D) + 37;
  pucAllocatedMemory_13 = pvPortMalloc (_1);
  # DEBUG pucAllocatedMemory => pucAllocatedMemory_13
  # DEBUG xBufferSizeBytes => xBufferSizeBytes_11
  # DEBUG BEGIN_STMT
  if (pucAllocatedMemory_13 != 0B)
    goto <bb 14>; [53.47%]
  else
    goto <bb 15>; [46.53%]

  <bb 14> [local count: 23779]:
  # DEBUG BEGIN_STMT
  _2 = pucAllocatedMemory_13 + 36;
  prvInitialiseNewStreamBuffer (pucAllocatedMemory_13, _2, xBufferSizeBytes_11, xTriggerLevelBytes_9, ucFlags_3);
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 81344]:
  # pucAllocatedMemory_10 = PHI <pucAllocatedMemory_13(13), pucAllocatedMemory_13(14), 0B(12)>
  # DEBUG pucAllocatedMemory => NULL
  # DEBUG xBufferSizeBytes => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return pucAllocatedMemory_10;

}



;; Function vStreamBufferDelete (vStreamBufferDelete, funcdef_no=5, decl_uid=6057, cgraph_uid=6, symbol_order=5)

Modification phase of node vStreamBufferDelete/5
vStreamBufferDelete (struct StreamBufferDef_t * xStreamBuffer)
{
  uint32_t ulNewBASEPRI;
  unsigned char _1;
  unsigned char _4;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_3(D)
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_3(D) == 0B)
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

  <bb 9> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct StreamBuffer_t *)xStreamBuffer_3(D)].ucFlags;
  _4 = _1 & 2;
  if (_4 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 125270]:
  # DEBUG BEGIN_STMT
  vPortFree (xStreamBuffer_3(D));
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 125270]:
  # DEBUG BEGIN_STMT
  memset (xStreamBuffer_3(D), 0, 36);

  <bb 8> [local count: 250539]:
  return;

}



;; Function xStreamBufferReset (xStreamBufferReset, funcdef_no=6, decl_uid=6063, cgraph_uid=7, symbol_order=6)

Modification phase of node xStreamBufferReset/6
xStreamBufferReset (struct StreamBufferDef_t * xStreamBuffer)
{
  uint32_t ulNewBASEPRI;
  UBaseType_t uxStreamBufferNumber;
  BaseType_t xReturn;
  struct tskTaskControlBlock * _1;
  struct tskTaskControlBlock * _2;
  uint8_t * _3;
  unsigned int _4;
  unsigned int _5;
  unsigned char _6;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_9(D)
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_9(D) == 0B)
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
" : "=r" ulNewBASEPRI_16 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_16

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  uxStreamBufferNumber_11 = MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].uxStreamBufferNumber;
  # DEBUG uxStreamBufferNumber => uxStreamBufferNumber_11
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].xTaskWaitingToReceive;
  if (_1 == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 6> [local count: 37017]:
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].xTaskWaitingToSend;
  if (_2 == 0B)
    goto <bb 7>; [17.43%]
  else
    goto <bb 8>; [82.57%]

  <bb 7> [local count: 6452]:
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].pucBuffer;
  _4 = MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].xLength;
  _5 = MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].xTriggerLevelBytes;
  _6 = MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].ucFlags;
  prvInitialiseNewStreamBuffer (xStreamBuffer_9(D), _3, _4, _5, _6);
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].uxStreamBufferNumber = uxStreamBufferNumber_11;

  <bb 8> [local count: 123389]:
  # xReturn_7 = PHI <0(5), 0(6), 1(7)>
  # DEBUG xReturn => xReturn_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  return xReturn_7;

}



;; Function xStreamBufferSetTriggerLevel (xStreamBufferSetTriggerLevel, funcdef_no=7, decl_uid=6070, cgraph_uid=8, symbol_order=7)

Modification phase of node xStreamBufferSetTriggerLevel/7
xStreamBufferSetTriggerLevel (struct StreamBufferDef_t * xStreamBuffer, size_t xTriggerLevel)
{
  uint32_t ulNewBASEPRI;
  BaseType_t xReturn;
  unsigned int _1;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_4(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_4(D) == 0B)
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
" : "=r" ulNewBASEPRI_9 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_9

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
  xTriggerLevel_8 = MAX_EXPR <1, xTriggerLevel_5(D)>;
  # DEBUG xTriggerLevel => xTriggerLevel_8
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct StreamBuffer_t *)xStreamBuffer_4(D)].xLength;
  if (_1 > xTriggerLevel_8)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 125270]:
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_4(D)].xTriggerLevelBytes = xTriggerLevel_8;
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 7> [local count: 250539]:
  # xReturn_2 = PHI <1(6), 0(5)>
  # DEBUG xReturn => xReturn_2
  # DEBUG BEGIN_STMT
  return xReturn_2;

}



;; Function xStreamBufferSpacesAvailable (xStreamBufferSpacesAvailable, funcdef_no=8, decl_uid=6065, cgraph_uid=9, symbol_order=8)

Modification phase of node xStreamBufferSpacesAvailable/8
xStreamBufferSpacesAvailable (struct StreamBufferDef_t * xStreamBuffer)
{
  size_t xOriginalTail;
  size_t xSpace;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _12;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_7(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_7(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 3> [local count: 107374]:
  # DEBUG D#1 => xStreamBuffer_7(D)
  xStreamBufferSpacesAvailable.part.0 ();

  <bb 8> [local count: 250539]:

  <bb 4> [local count: 2277630]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xOriginalTail_10 ={v} MEM[(const struct StreamBuffer_t *)xStreamBuffer_7(D)].xTail;
  # DEBUG xOriginalTail => xOriginalTail_10
  # DEBUG BEGIN_STMT
  _1 = MEM[(const struct StreamBuffer_t *)xStreamBuffer_7(D)].xLength;
  _2 ={v} MEM[(const struct StreamBuffer_t *)xStreamBuffer_7(D)].xTail;
  xSpace_11 = _1 + _2;
  # DEBUG xSpace => xSpace_11
  # DEBUG BEGIN_STMT
  _12 ={v} MEM[(const struct StreamBuffer_t *)xStreamBuffer_7(D)].xHead;
  xSpace_13 = xSpace_11 - _12;
  # DEBUG xSpace => xSpace_13
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(const struct StreamBuffer_t *)xStreamBuffer_7(D)].xTail;
  if (_3 != xOriginalTail_10)
    goto <bb 9>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 9> [local count: 2027091]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # _4 = PHI <_1(4)>
  # xSpace_5 = PHI <xSpace_13(4)>
  # DEBUG BEGIN_STMT
  xSpace_14 = xSpace_5 + 4294967295;
  # DEBUG xSpace => xSpace_14
  # DEBUG BEGIN_STMT
  if (_4 <= xSpace_14)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 125270]:
  # DEBUG BEGIN_STMT
  xSpace_15 = xSpace_14 - _4;
  # DEBUG xSpace => xSpace_15

  <bb 7> [local count: 250539]:
  # xSpace_6 = PHI <xSpace_14(5), xSpace_15(6)>
  # DEBUG xSpace => xSpace_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xSpace_6;

}



;; Function xStreamBufferBytesAvailable (xStreamBufferBytesAvailable, funcdef_no=9, decl_uid=6067, cgraph_uid=10, symbol_order=9)

Modification phase of node xStreamBufferBytesAvailable/9
xStreamBufferBytesAvailable (struct StreamBufferDef_t * xStreamBuffer)
{
  uint32_t ulNewBASEPRI;
  size_t xReturn;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_1(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_1(D) == 0B)
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
" : "=r" ulNewBASEPRI_5 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_5

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
  xReturn_4 = prvBytesInBuffer (xStreamBuffer_1(D));
  # DEBUG xReturn => xReturn_4
  # DEBUG BEGIN_STMT
  return xReturn_4;

}



;; Function xStreamBufferSend (xStreamBufferSend, funcdef_no=10, decl_uid=6040, cgraph_uid=11, symbol_order=10)

Modification phase of node xStreamBufferSend/10
xStreamBufferSend (struct StreamBufferDef_t * xStreamBuffer, const void * pvTxData, size_t xDataLengthBytes, TickType_t xTicksToWait)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  size_t xMaxReportedSpace;
  struct TimeOut_t xTimeOut;
  size_t xRequiredSpace;
  size_t xSpace;
  size_t xReturn;
  unsigned int _1;
  unsigned char _2;
  unsigned int _3;
  long unsigned int xTicksToWait.0_4;
  struct tskTaskControlBlock * _5;
  struct tskTaskControlBlock * _6;
  long unsigned int xTicksToWait.1_7;
  long int _8;
  unsigned int _9;
  unsigned int _10;
  struct tskTaskControlBlock * _11;
  struct tskTaskControlBlock * _12;
  unsigned char _23;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_22(D)
  # DEBUG BEGIN_STMT
  # DEBUG xSpace => 0
  # DEBUG BEGIN_STMT
  # DEBUG xRequiredSpace => xDataLengthBytes_25(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xMaxReportedSpace => 0
  # DEBUG BEGIN_STMT
  if (pvTxData_27(D) == 0B)
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
" : "=r" ulNewBASEPRI_54 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_54

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 31> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_22(D) == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 6> [local count: 75162]:
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

  <bb 7> [local count: 751619279]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 32> [local count: 751619279]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].xLength;
  xMaxReportedSpace_29 = _1 + 4294967295;
  # DEBUG xMaxReportedSpace => xMaxReportedSpace_29
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].ucFlags;
  _23 = _2 & 1;
  if (_23 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 9> [local count: 87689]:
  # DEBUG BEGIN_STMT
  xRequiredSpace_30 = xDataLengthBytes_25(D) + 4;
  # DEBUG xRequiredSpace => xRequiredSpace_30
  # DEBUG BEGIN_STMT
  if (xDataLengthBytes_25(D) >= xRequiredSpace_30)
    goto <bb 10>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 10> [local count: 43844]:
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
" : "=r" ulNewBASEPRI_56 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_56

  <bb 11> [local count: 438444579]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 438444579]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 43844]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xMaxReportedSpace_29 < xRequiredSpace_30)
    goto <bb 13>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 13> [local count: 21922]:
  # DEBUG BEGIN_STMT
  xTicksToWait = 0;
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 87689]:
  # DEBUG BEGIN_STMT
  _3 = MIN_EXPR <xMaxReportedSpace_29, xDataLengthBytes_25(D)>;

  <bb 15> [local count: 131533]:
  # xRequiredSpace_15 = PHI <xRequiredSpace_30(13), _3(14), xRequiredSpace_30(12)>
  # DEBUG xRequiredSpace => xRequiredSpace_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTicksToWait.0_4 = xTicksToWait;
  if (xTicksToWait.0_4 != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 24>; [50.00%]

  <bb 16> [local count: 65767]:
  # DEBUG BEGIN_STMT
  vTaskSetTimeOutState (&xTimeOut);

  <bb 17> [local count: 621434]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  xSpace_35 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  # DEBUG xSpace => xSpace_35
  # DEBUG BEGIN_STMT
  if (xRequiredSpace_15 > xSpace_35)
    goto <bb 18>; [96.34%]
  else
    goto <bb 22>; [3.66%]

  <bb 18> [local count: 598690]:
  # DEBUG BEGIN_STMT
  xTaskGenericNotifyStateClear (0B, 0);
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].xTaskWaitingToSend;
  if (_5 != 0B)
    goto <bb 19>; [3.66%]
  else
    goto <bb 21>; [96.34%]

  <bb 19> [local count: 21912]:
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
" : "=r" ulNewBASEPRI_57 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_57

  <bb 20> [local count: 219120732]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 34> [local count: 219120732]:
  goto <bb 20>; [100.00%]

  <bb 21> [local count: 576777]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = xTaskGetCurrentTaskHandle ();
  MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].xTaskWaitingToSend ={v} _6;
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTicksToWait.1_7 = xTicksToWait;
  xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait.1_7);
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].xTaskWaitingToSend ={v} 0B;
  # DEBUG BEGIN_STMT
  _8 = xTaskCheckForTimeOut (&xTimeOut, &xTicksToWait);
  if (_8 == 0)
    goto <bb 35>; [96.34%]
  else
    goto <bb 23>; [3.66%]

  <bb 35> [local count: 555667]:
  goto <bb 17>; [100.00%]

  <bb 22> [local count: 22744]:
  # xSpace_24 = PHI <xSpace_35(17)>
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT

  <bb 23> [local count: 43855]:
  # xSpace_13 = PHI <xSpace_24(22), xSpace_35(21)>
  # DEBUG xSpace => xSpace_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xSpace_13 == 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 25>; [50.00%]

  <bb 24> [local count: 87694]:
  # DEBUG xSpace => NULL
  # DEBUG BEGIN_STMT
  xSpace_45 = xStreamBufferSpacesAvailable (xStreamBuffer_22(D));
  # DEBUG xSpace => xSpace_45

  <bb 25> [local count: 109621]:
  # xSpace_14 = PHI <xSpace_13(23), xSpace_45(24)>
  # DEBUG xSpace => xSpace_14
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xReturn_47 = prvWriteMessageToBuffer (xStreamBuffer_22(D), pvTxData_27(D), xDataLengthBytes_25(D), xSpace_14, xRequiredSpace_15);
  # DEBUG xReturn => xReturn_47
  # DEBUG BEGIN_STMT
  if (xReturn_47 != 0)
    goto <bb 26>; [33.00%]
  else
    goto <bb 30>; [67.00%]

  <bb 26> [local count: 36175]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = prvBytesInBuffer (xStreamBuffer_22(D));
  _10 = MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].xTriggerLevelBytes;
  if (_9 >= _10)
    goto <bb 27>; [33.00%]
  else
    goto <bb 30>; [67.00%]

  <bb 27> [local count: 11938]:
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].xTaskWaitingToReceive;
  if (_11 != 0B)
    goto <bb 28>; [53.47%]
  else
    goto <bb 29>; [46.53%]

  <bb 28> [local count: 6383]:
  # DEBUG BEGIN_STMT
  _12 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].xTaskWaitingToReceive;
  xTaskGenericNotify (_12, 0, 0, 0, 0B);
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_22(D)].xTaskWaitingToReceive ={v} 0B;

  <bb 29> [local count: 11938]:
  # DEBUG BEGIN_STMT
  xTaskResumeAll ();
  # DEBUG BEGIN_STMT

  <bb 30> [local count: 109621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTimeOut ={v} {CLOBBER};
  return xReturn_47;

}



;; Function xStreamBufferSendFromISR (xStreamBufferSendFromISR, funcdef_no=11, decl_uid=6045, cgraph_uid=12, symbol_order=11)

Modification phase of node xStreamBufferSendFromISR/11
xStreamBufferSendFromISR (struct StreamBufferDef_t * xStreamBuffer, const void * pvTxData, size_t xDataLengthBytes, BaseType_t * const pxHigherPriorityTaskWoken)
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  size_t xRequiredSpace;
  size_t xSpace;
  size_t xReturn;
  unsigned char _1;
  unsigned int _2;
  unsigned int _3;
  struct tskTaskControlBlock * _4;
  struct tskTaskControlBlock * _5;
  unsigned char _10;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_9(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG xRequiredSpace => xDataLengthBytes_11(D)
  # DEBUG BEGIN_STMT
  if (pvTxData_12(D) == 0B)
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
" : "=r" ulNewBASEPRI_23 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_23

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_9(D) == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 6> [local count: 75162]:
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

  <bb 7> [local count: 751619279]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 751619279]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].ucFlags;
  _10 = _1 & 1;
  if (_10 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 87689]:
  # DEBUG BEGIN_STMT
  xRequiredSpace_14 = xDataLengthBytes_11(D) + 4;
  # DEBUG xRequiredSpace => xRequiredSpace_14

  <bb 10> [local count: 175378]:
  # xRequiredSpace_6 = PHI <xDataLengthBytes_11(D)(8), xRequiredSpace_14(9)>
  # DEBUG xRequiredSpace => xRequiredSpace_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xSpace_16 = xStreamBufferSpacesAvailable (xStreamBuffer_9(D));
  # DEBUG xSpace => xSpace_16
  # DEBUG BEGIN_STMT
  xReturn_18 = prvWriteMessageToBuffer (xStreamBuffer_9(D), pvTxData_12(D), xDataLengthBytes_11(D), xSpace_16, xRequiredSpace_6);
  # DEBUG xReturn => xReturn_18
  # DEBUG BEGIN_STMT
  if (xReturn_18 != 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 11> [local count: 57875]:
  # DEBUG BEGIN_STMT
  _2 = prvBytesInBuffer (xStreamBuffer_9(D));
  _3 = MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].xTriggerLevelBytes;
  if (_2 >= _3)
    goto <bb 12>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 12> [local count: 28937]:
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
" : "=r" ulOriginalBASEPRI_25, "=r" ulNewBASEPRI_26 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_26
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_25
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptStatus => ulOriginalBASEPRI_25
  # DEBUG BEGIN_STMT
  _4 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].xTaskWaitingToReceive;
  if (_4 != 0B)
    goto <bb 13>; [53.47%]
  else
    goto <bb 14>; [46.53%]

  <bb 13> [local count: 15473]:
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].xTaskWaitingToReceive;
  xTaskGenericNotifyFromISR (_5, 0, 0, 0, 0B, pxHigherPriorityTaskWoken_20(D));
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_9(D)].xTaskWaitingToReceive ={v} 0B;

  <bb 14> [local count: 28937]:
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_25
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_25 : "memory");

  <bb 15> [local count: 175378]:
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xReturn_18;

}



;; Function xStreamBufferReceive (xStreamBufferReceive, funcdef_no=13, decl_uid=6050, cgraph_uid=14, symbol_order=13)

Modification phase of node xStreamBufferReceive/13
xStreamBufferReceive (struct StreamBufferDef_t * xStreamBuffer, void * pvRxData, size_t xBufferLengthBytes, TickType_t xTicksToWait)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  size_t xBytesToStoreMessageLength;
  size_t xBytesAvailable;
  size_t xReceivedLength;
  unsigned char _1;
  struct tskTaskControlBlock * _2;
  struct tskTaskControlBlock * _3;
  struct tskTaskControlBlock * _4;
  struct tskTaskControlBlock * _5;
  unsigned char _14;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_13(D)
  # DEBUG BEGIN_STMT
  # DEBUG xReceivedLength => 0
  # DEBUG BEGIN_STMT
  if (pvRxData_15(D) == 0B)
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
" : "=r" ulNewBASEPRI_38 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_38

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_13(D) == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 6> [local count: 75162]:
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
" : "=r" ulNewBASEPRI_39 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_39

  <bb 7> [local count: 751619279]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 26> [local count: 751619279]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct StreamBuffer_t *)xStreamBuffer_13(D)].ucFlags;
  _14 = _1 & 1;
  if (_14 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 87689]:
  # DEBUG BEGIN_STMT
  # DEBUG xBytesToStoreMessageLength => 0

  <bb 10> [local count: 175378]:
  # xBytesToStoreMessageLength_8 = PHI <4(8), 0(9)>
  # DEBUG xBytesToStoreMessageLength => xBytesToStoreMessageLength_8
  # DEBUG BEGIN_STMT
  if (xTicksToWait_17(D) != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 11> [local count: 87689]:
  # DEBUG BEGIN_STMT
  vPortEnterCritical ();
  # DEBUG BEGIN_STMT
  xBytesAvailable_22 = prvBytesInBuffer (xStreamBuffer_13(D));
  # DEBUG xBytesAvailable => xBytesAvailable_22
  # DEBUG BEGIN_STMT
  if (xBytesToStoreMessageLength_8 >= xBytesAvailable_22)
    goto <bb 12>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 12> [local count: 43844]:
  # DEBUG BEGIN_STMT
  xTaskGenericNotifyStateClear (0B, 0);
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_13(D)].xTaskWaitingToReceive;
  if (_2 != 0B)
    goto <bb 13>; [82.57%]
  else
    goto <bb 15>; [17.43%]

  <bb 13> [local count: 36202]:
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

  <bb 14> [local count: 362023689]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 27> [local count: 362023689]:
  goto <bb 14>; [100.00%]

  <bb 15> [local count: 7642]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = xTaskGetCurrentTaskHandle ();
  MEM[(struct StreamBuffer_t *)xStreamBuffer_13(D)].xTaskWaitingToReceive ={v} _3;

  <bb 16> [local count: 51486]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vPortExitCritical ();
  # DEBUG BEGIN_STMT
  if (xBytesToStoreMessageLength_8 >= xBytesAvailable_22)
    goto <bb 17>; [33.00%]
  else
    goto <bb 19>; [67.00%]

  <bb 17> [local count: 16991]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  xTaskGenericNotifyWait (0, 0, 0, 0B, xTicksToWait_17(D));
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_13(D)].xTaskWaitingToReceive ={v} 0B;
  # DEBUG BEGIN_STMT
  xBytesAvailable_30 = prvBytesInBuffer (xStreamBuffer_13(D));
  # DEBUG xBytesAvailable => xBytesAvailable_30
  goto <bb 19>; [100.00%]

  <bb 18> [local count: 87689]:
  # DEBUG BEGIN_STMT
  xBytesAvailable_19 = prvBytesInBuffer (xStreamBuffer_13(D));
  # DEBUG xBytesAvailable => xBytesAvailable_19

  <bb 19> [local count: 139175]:
  # xBytesAvailable_7 = PHI <xBytesAvailable_30(17), xBytesAvailable_19(18), xBytesAvailable_22(16)>
  # DEBUG xBytesAvailable => xBytesAvailable_7
  # DEBUG BEGIN_STMT
  if (xBytesAvailable_7 > xBytesToStoreMessageLength_8)
    goto <bb 20>; [33.00%]
  else
    goto <bb 24>; [67.00%]

  <bb 20> [local count: 45928]:
  # DEBUG BEGIN_STMT
  xReceivedLength_33 = prvReadMessageFromBuffer (xStreamBuffer_13(D), pvRxData_15(D), xBufferLengthBytes_31(D), xBytesAvailable_7);
  # DEBUG xReceivedLength => xReceivedLength_33
  # DEBUG BEGIN_STMT
  if (xReceivedLength_33 != 0)
    goto <bb 21>; [33.00%]
  else
    goto <bb 24>; [67.00%]

  <bb 21> [local count: 15156]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  vTaskSuspendAll ();
  # DEBUG BEGIN_STMT
  _4 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_13(D)].xTaskWaitingToSend;
  if (_4 != 0B)
    goto <bb 22>; [53.47%]
  else
    goto <bb 23>; [46.53%]

  <bb 22> [local count: 8104]:
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_13(D)].xTaskWaitingToSend;
  xTaskGenericNotify (_5, 0, 0, 0, 0B);
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_13(D)].xTaskWaitingToSend ={v} 0B;

  <bb 23> [local count: 15156]:
  # DEBUG BEGIN_STMT
  xTaskResumeAll ();
  # DEBUG BEGIN_STMT

  <bb 24> [local count: 139175]:
  # xReceivedLength_6 = PHI <0(19), xReceivedLength_33(23), xReceivedLength_33(20)>
  # DEBUG xReceivedLength => xReceivedLength_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xReceivedLength_6;

}



;; Function xStreamBufferNextMessageLengthBytes (xStreamBufferNextMessageLengthBytes, funcdef_no=14, decl_uid=6088, cgraph_uid=15, symbol_order=14)

Modification phase of node xStreamBufferNextMessageLengthBytes/14
xStreamBufferNextMessageLengthBytes (struct StreamBufferDef_t * xStreamBuffer)
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  size_t xTempReturn;
  size_t xBytesAvailable;
  size_t xReturn;
  unsigned char _1;
  unsigned int _2;
  unsigned char _6;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_5(D) == 0B)
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
" : "=r" ulNewBASEPRI_13 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_13

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct StreamBuffer_t *)xStreamBuffer_5(D)].ucFlags;
  _6 = _1 & 1;
  if (_6 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 6> [local count: 82678]:
  # DEBUG BEGIN_STMT
  xBytesAvailable_9 = prvBytesInBuffer (xStreamBuffer_5(D));
  # DEBUG xBytesAvailable => xBytesAvailable_9
  # DEBUG BEGIN_STMT
  if (xBytesAvailable_9 > 4)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 27284]:
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_5(D)].xTail;
  prvReadBytesFromBuffer (xStreamBuffer_5(D), &xTempReturn, 4, _2);
  # DEBUG BEGIN_STMT
  xReturn_11 = xTempReturn;
  # DEBUG xReturn => xReturn_11
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 55394]:
  # DEBUG BEGIN_STMT
  if (xBytesAvailable_9 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 9> [local count: 27697]:
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
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_14

  <bb 10> [local count: 276971704]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 276971704]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 222842]:
  # xReturn_3 = PHI <0(8), 0(5), xReturn_11(7)>
  # DEBUG xReturn => xReturn_3
  # DEBUG BEGIN_STMT
  xTempReturn ={v} {CLOBBER};
  return xReturn_3;

}



;; Function xStreamBufferReceiveFromISR (xStreamBufferReceiveFromISR, funcdef_no=15, decl_uid=6055, cgraph_uid=16, symbol_order=15)

Modification phase of node xStreamBufferReceiveFromISR/15
xStreamBufferReceiveFromISR (struct StreamBufferDef_t * xStreamBuffer, void * pvRxData, size_t xBufferLengthBytes, BaseType_t * const pxHigherPriorityTaskWoken)
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  size_t xBytesToStoreMessageLength;
  size_t xBytesAvailable;
  size_t xReceivedLength;
  unsigned char _1;
  struct tskTaskControlBlock * _2;
  struct tskTaskControlBlock * _3;
  unsigned char _9;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_8(D)
  # DEBUG BEGIN_STMT
  # DEBUG xReceivedLength => 0
  # DEBUG BEGIN_STMT
  if (pvRxData_10(D) == 0B)
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
" : "=r" ulNewBASEPRI_20 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_20

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_8(D) == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 6> [local count: 75162]:
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

  <bb 7> [local count: 751619279]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 751619279]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct StreamBuffer_t *)xStreamBuffer_8(D)].ucFlags;
  _9 = _1 & 1;
  if (_9 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 87689]:
  # DEBUG BEGIN_STMT
  # DEBUG xBytesToStoreMessageLength => 0

  <bb 10> [local count: 175378]:
  # xBytesToStoreMessageLength_5 = PHI <4(8), 0(9)>
  # DEBUG xBytesToStoreMessageLength => xBytesToStoreMessageLength_5
  # DEBUG BEGIN_STMT
  xBytesAvailable_13 = prvBytesInBuffer (xStreamBuffer_8(D));
  # DEBUG xBytesAvailable => xBytesAvailable_13
  # DEBUG BEGIN_STMT
  if (xBytesToStoreMessageLength_5 < xBytesAvailable_13)
    goto <bb 11>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 11> [local count: 57875]:
  # DEBUG BEGIN_STMT
  xReceivedLength_16 = prvReadMessageFromBuffer (xStreamBuffer_8(D), pvRxData_10(D), xBufferLengthBytes_14(D), xBytesAvailable_13);
  # DEBUG xReceivedLength => xReceivedLength_16
  # DEBUG BEGIN_STMT
  if (xReceivedLength_16 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 12> [local count: 28937]:
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
" : "=r" ulOriginalBASEPRI_22, "=r" ulNewBASEPRI_23 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_23
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_22
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptStatus => ulOriginalBASEPRI_22
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_8(D)].xTaskWaitingToSend;
  if (_2 != 0B)
    goto <bb 13>; [53.47%]
  else
    goto <bb 14>; [46.53%]

  <bb 13> [local count: 15473]:
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_8(D)].xTaskWaitingToSend;
  xTaskGenericNotifyFromISR (_3, 0, 0, 0, 0B, pxHigherPriorityTaskWoken_17(D));
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_8(D)].xTaskWaitingToSend ={v} 0B;

  <bb 14> [local count: 28937]:
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_22
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_22 : "memory");

  <bb 15> [local count: 175378]:
  # xReceivedLength_4 = PHI <0(10), xReceivedLength_16(14), xReceivedLength_16(11)>
  # DEBUG ulNewMaskValue => NULL
  # DEBUG xReceivedLength => xReceivedLength_4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return xReceivedLength_4;

}



;; Function xStreamBufferIsEmpty (xStreamBufferIsEmpty, funcdef_no=17, decl_uid=6061, cgraph_uid=18, symbol_order=17)

Modification phase of node xStreamBufferIsEmpty/17
xStreamBufferIsEmpty (struct StreamBufferDef_t * xStreamBuffer)
{
  uint32_t ulNewBASEPRI;
  size_t xTail;
  BaseType_t xReturn;
  unsigned int _1;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_3(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_3(D) == 0B)
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
" : "=r" ulNewBASEPRI_6 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_6

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
  xTail_5 ={v} MEM[(const struct StreamBuffer_t *)xStreamBuffer_3(D)].xTail;
  # DEBUG xTail => xTail_5
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(const struct StreamBuffer_t *)xStreamBuffer_3(D)].xHead;
  if (_1 == xTail_5)
    goto <bb 7>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 165356]:
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 0

  <bb 7> [local count: 250539]:
  # xReturn_2 = PHI <1(5), 0(6)>
  # DEBUG xReturn => xReturn_2
  # DEBUG BEGIN_STMT
  return xReturn_2;

}



;; Function xStreamBufferIsFull (xStreamBufferIsFull, funcdef_no=18, decl_uid=6059, cgraph_uid=19, symbol_order=18)

Modification phase of node xStreamBufferIsFull/18
xStreamBufferIsFull (struct StreamBufferDef_t * xStreamBuffer)
{
  uint32_t ulNewBASEPRI;
  size_t xBytesToStoreMessageLength;
  BaseType_t xReturn;
  unsigned char _1;
  unsigned int _2;
  unsigned char _6;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_5(D)
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_5(D) == 0B)
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
" : "=r" ulNewBASEPRI_9 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_9

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(const struct StreamBuffer_t *)xStreamBuffer_5(D)].ucFlags;
  _6 = _1 & 1;
  if (_6 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 125270]:
  # DEBUG BEGIN_STMT
  # DEBUG xBytesToStoreMessageLength => 0

  <bb 7> [local count: 250539]:
  # xBytesToStoreMessageLength_4 = PHI <4(5), 0(6)>
  # DEBUG xBytesToStoreMessageLength => xBytesToStoreMessageLength_4
  # DEBUG BEGIN_STMT
  _2 = xStreamBufferSpacesAvailable (xStreamBuffer_5(D));
  if (_2 <= xBytesToStoreMessageLength_4)
    goto <bb 9>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 125270]:
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 0

  <bb 9> [local count: 250539]:
  # xReturn_3 = PHI <1(7), 0(8)>
  # DEBUG xReturn => xReturn_3
  # DEBUG BEGIN_STMT
  return xReturn_3;

}



;; Function xStreamBufferSendCompletedFromISR (xStreamBufferSendCompletedFromISR, funcdef_no=19, decl_uid=6073, cgraph_uid=20, symbol_order=19)

Modification phase of node xStreamBufferSendCompletedFromISR/19
xStreamBufferSendCompletedFromISR (struct StreamBufferDef_t * xStreamBuffer, BaseType_t * pxHigherPriorityTaskWoken)
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  BaseType_t xReturn;
  struct tskTaskControlBlock * _1;
  struct tskTaskControlBlock * _2;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_5(D) == 0B)
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
" : "=r" ulNewBASEPRI_10 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_10

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
" : "=r" ulOriginalBASEPRI_11, "=r" ulNewBASEPRI_12 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_12
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_11
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptStatus => ulOriginalBASEPRI_11
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_5(D)].xTaskWaitingToReceive;
  if (_1 != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 6> [local count: 133963]:
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_5(D)].xTaskWaitingToReceive;
  xTaskGenericNotifyFromISR (_2, 0, 0, 0, 0B, pxHigherPriorityTaskWoken_7(D));
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_5(D)].xTaskWaitingToReceive ={v} 0B;
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 7> [local count: 250539]:
  # xReturn_3 = PHI <1(6), 0(5)>
  # DEBUG xReturn => xReturn_3
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_11
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_11 : "memory");
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  return xReturn_3;

}



;; Function xStreamBufferReceiveCompletedFromISR (xStreamBufferReceiveCompletedFromISR, funcdef_no=20, decl_uid=6076, cgraph_uid=21, symbol_order=20)

Modification phase of node xStreamBufferReceiveCompletedFromISR/20
xStreamBufferReceiveCompletedFromISR (struct StreamBufferDef_t * xStreamBuffer, BaseType_t * pxHigherPriorityTaskWoken)
{
  uint32_t ulOriginalBASEPRI;
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  BaseType_t xReturn;
  struct tskTaskControlBlock * _1;
  struct tskTaskControlBlock * _2;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG pxStreamBuffer => xStreamBuffer_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (xStreamBuffer_5(D) == 0B)
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
" : "=r" ulNewBASEPRI_10 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_10

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
" : "=r" ulOriginalBASEPRI_11, "=r" ulNewBASEPRI_12 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_12
  # DEBUG ulOriginalBASEPRI => ulOriginalBASEPRI_11
  # DEBUG BEGIN_STMT
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG ulOriginalBASEPRI => NULL
  # DEBUG uxSavedInterruptStatus => ulOriginalBASEPRI_11
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_5(D)].xTaskWaitingToSend;
  if (_1 != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 6> [local count: 133963]:
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct StreamBuffer_t *)xStreamBuffer_5(D)].xTaskWaitingToSend;
  xTaskGenericNotifyFromISR (_2, 0, 0, 0, 0B, pxHigherPriorityTaskWoken_7(D));
  # DEBUG BEGIN_STMT
  MEM[(struct StreamBuffer_t *)xStreamBuffer_5(D)].xTaskWaitingToSend ={v} 0B;
  # DEBUG BEGIN_STMT
  # DEBUG xReturn => 1

  <bb 7> [local count: 250539]:
  # xReturn_3 = PHI <1(6), 0(5)>
  # DEBUG xReturn => xReturn_3
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => ulOriginalBASEPRI_11
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" ulOriginalBASEPRI_11 : "memory");
  # DEBUG ulNewMaskValue => NULL
  # DEBUG BEGIN_STMT
  return xReturn_3;

}



;; Function uxStreamBufferGetStreamBufferNumber (uxStreamBufferGetStreamBufferNumber, funcdef_no=25, decl_uid=6093, cgraph_uid=26, symbol_order=25)

Modification phase of node uxStreamBufferGetStreamBufferNumber/25
uxStreamBufferGetStreamBufferNumber (struct StreamBufferDef_t * xStreamBuffer)
{
  UBaseType_t _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _3 = xStreamBuffer_2(D)->uxStreamBufferNumber;
  return _3;

}



;; Function vStreamBufferSetStreamBufferNumber (vStreamBufferSetStreamBufferNumber, funcdef_no=26, decl_uid=6091, cgraph_uid=27, symbol_order=26)

Modification phase of node vStreamBufferSetStreamBufferNumber/26
vStreamBufferSetStreamBufferNumber (struct StreamBufferDef_t * xStreamBuffer, UBaseType_t uxStreamBufferNumber)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  xStreamBuffer_2(D)->uxStreamBufferNumber = uxStreamBufferNumber_3(D);
  return;

}



;; Function ucStreamBufferGetStreamBufferType (ucStreamBufferGetStreamBufferType, funcdef_no=27, decl_uid=6095, cgraph_uid=28, symbol_order=27)

Modification phase of node ucStreamBufferGetStreamBufferType/27
ucStreamBufferGetStreamBufferType (struct StreamBufferDef_t * xStreamBuffer)
{
  unsigned char _1;
  uint8_t _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = xStreamBuffer_3(D)->ucFlags;
  _4 = _1 & 1;
  return _4;

}


