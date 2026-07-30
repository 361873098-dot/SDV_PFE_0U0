
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  prvTaskExitError.part.0/25:
  Jump functions of caller  xTaskIncrementTick/22:
  Jump functions of caller  vTaskSwitchContext/21:
  Jump functions of caller  vPortValidateInterruptPriority/20:
  Jump functions of caller  vPortEnableVFP/19:
  Jump functions of caller  vPortSetupTimerInterrupt/18:
  Jump functions of caller  SysTick_Handler/17:
  Jump functions of caller  PendSV_Handler/16:
  Jump functions of caller  vPortExitCritical/15:
  Jump functions of caller  vPortEnterCritical/14:
  Jump functions of caller  vPortEndScheduler/13:
  Jump functions of caller  xPortStartScheduler/12:
    callsite  xPortStartScheduler/12 -> prvTaskExitError/9 : 
    callsite  xPortStartScheduler/12 -> prvPortStartFirstTask/11 : 
    callsite  xPortStartScheduler/12 -> vPortEnableVFP/19 : 
    callsite  xPortStartScheduler/12 -> vPortSetupTimerInterrupt/18 : 
  Jump functions of caller  prvPortStartFirstTask/11:
  Jump functions of caller  SVC_Handler/10:
  Jump functions of caller  prvTaskExitError/9:
    callsite  prvTaskExitError/9 -> prvTaskExitError.part.0/25 : 
  Jump functions of caller  pxPortInitialiseStack/8:

 Propagating constants:

Not considering vPortValidateInterruptPriority for cloning; -fipa-cp-clone disabled.
Function vPortEnableVFP/19 is not versionable, reason: not a tree_versionable_function.
Function vPortSetupTimerInterrupt/18 is not versionable, reason: insufficient body availability.
Not considering SysTick_Handler for cloning; -fipa-cp-clone disabled.
Function PendSV_Handler/16 is not versionable, reason: not a tree_versionable_function.
Not considering vPortExitCritical for cloning; -fipa-cp-clone disabled.
Not considering vPortEnterCritical for cloning; -fipa-cp-clone disabled.
Not considering vPortEndScheduler for cloning; -fipa-cp-clone disabled.
Not considering xPortStartScheduler for cloning; -fipa-cp-clone disabled.
Function prvPortStartFirstTask/11 is not versionable, reason: not a tree_versionable_function.
Function SVC_Handler/10 is not versionable, reason: not a tree_versionable_function.
Not considering prvTaskExitError for cloning; -fipa-cp-clone disabled.
Not considering pxPortInitialiseStack for cloning; -fipa-cp-clone disabled.

overall_size: 288, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: prvTaskExitError.part.0/25:
  Node: vPortValidateInterruptPriority/20:
  Node: vPortEnableVFP/19:
  Node: vPortSetupTimerInterrupt/18:
  Node: SysTick_Handler/17:
  Node: PendSV_Handler/16:
  Node: vPortExitCritical/15:
  Node: vPortEnterCritical/14:
  Node: vPortEndScheduler/13:
  Node: xPortStartScheduler/12:
  Node: prvPortStartFirstTask/11:
  Node: SVC_Handler/10:
  Node: prvTaskExitError/9:
  Node: pxPortInitialiseStack/8:
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

prvTaskExitError.part.0/25 (prvTaskExitError.part.0) @06d9a380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:107374 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: prvTaskExitError/9 (107374 (estimated locally),0.66 per call) 
  Calls: 
xTaskIncrementTick/22 (xTaskIncrementTick) @06e00e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SysTick_Handler/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
vTaskSwitchContext/21 (vTaskSwitchContext) @06e00540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: xPortStartScheduler/12 (27247 (estimated locally),0.20 per call) 
  Calls: 
vPortValidateInterruptPriority/20 (vPortValidateInterruptPriority) @06dfb0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ucMaxSysCallPriority/5 (read)ulMaxPRIGROUPValue/6 (read)
  Referring: 
  Availability: available
  Function flags: count:286331 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vPortEnableVFP/19 (vPortEnableVFP) @06dfbc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: xPortStartScheduler/12 (27247 (estimated locally),0.20 per call) 
  Calls: 
vPortSetupTimerInterrupt/18 (vPortSetupTimerInterrupt) @06dfb8c0
  Type: function definition analyzed
  Visibility: externally_visible public weak
  References: 
  Referring: 
  Availability: overwritable
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: xPortStartScheduler/12 (27247 (estimated locally),0.20 per call) 
  Calls: 
SysTick_Handler/17 (SysTick_Handler) @06dfb620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: xTaskIncrementTick/22 (1073741824 (estimated locally),1.00 per call) 
PendSV_Handler/16 (PendSV_Handler) @06dfb380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vPortExitCritical/15 (vPortExitCritical) @06dfb000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxCriticalNesting/4 (read)uxCriticalNesting/4 (write)
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vPortEnterCritical/14 (vPortEnterCritical) @06e47700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxCriticalNesting/4 (read)uxCriticalNesting/4 (write)
  Referring: 
  Availability: available
  Function flags: count:631612 (estimated locally) body optimize_size
  Called by: 
  Calls: 
vPortEndScheduler/13 (vPortEndScheduler) @06e470e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: uxCriticalNesting/4 (read)
  Referring: 
  Availability: available
  Function flags: count:162688 (estimated locally) body optimize_size
  Called by: 
  Calls: 
xPortStartScheduler/12 (xPortStartScheduler) @06e47c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ucMaxSysCallPriority/5 (write)ulMaxPRIGROUPValue/6 (write)ulMaxPRIGROUPValue/6 (read)ulMaxPRIGROUPValue/6 (write)ulMaxPRIGROUPValue/6 (read)ulMaxPRIGROUPValue/6 (write)uxCriticalNesting/4 (write)
  Referring: 
  Availability: available
  Function flags: count:134621 (estimated locally) body optimize_size
  Called by: 
  Calls: prvTaskExitError/9 (27247 (estimated locally),0.20 per call) vTaskSwitchContext/21 (27247 (estimated locally),0.20 per call) prvPortStartFirstTask/11 (27247 (estimated locally),0.20 per call) vPortEnableVFP/19 (27247 (estimated locally),0.20 per call) vPortSetupTimerInterrupt/18 (27247 (estimated locally),0.20 per call) 
prvPortStartFirstTask/11 (prvPortStartFirstTask) @06e479a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: xPortStartScheduler/12 (27247 (estimated locally),0.20 per call) 
  Calls: 
SVC_Handler/10 (SVC_Handler) @06e47620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
prvTaskExitError/9 (prvTaskExitError) @06e47380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: uxCriticalNesting/4 (read)
  Referring: pxPortInitialiseStack/8 (addr)
  Availability: available
  Function flags: count:162688 (estimated locally) body optimize_size
  Called by: xPortStartScheduler/12 (27247 (estimated locally),0.20 per call) 
  Calls: prvTaskExitError.part.0/25 (107374 (estimated locally),0.66 per call) 
pxPortInitialiseStack/8 (pxPortInitialiseStack) @06e47000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: prvTaskExitError/9 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ulMaxPRIGROUPValue/6 (ulMaxPRIGROUPValue) @06e41c60
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: xPortStartScheduler/12 (write)xPortStartScheduler/12 (write)xPortStartScheduler/12 (read)xPortStartScheduler/12 (write)xPortStartScheduler/12 (read)vPortValidateInterruptPriority/20 (read)
  Availability: available
  Varpool flags: initialized
ucMaxSysCallPriority/5 (ucMaxSysCallPriority) @06e41bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: xPortStartScheduler/12 (write)vPortValidateInterruptPriority/20 (read)
  Availability: available
  Varpool flags: initialized
uxCriticalNesting/4 (uxCriticalNesting) @06e41a68
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: vPortEndScheduler/13 (read)vPortEnterCritical/14 (write)vPortExitCritical/15 (write)prvTaskExitError/9 (read)vPortEnterCritical/14 (read)vPortExitCritical/15 (read)xPortStartScheduler/12 (write)
  Availability: available
  Varpool flags: initialized

;; Function prvPortStartFirstTask (prvPortStartFirstTask, funcdef_no=7, decl_uid=5777, cgraph_uid=8, symbol_order=11)

Modification phase of node prvPortStartFirstTask/11
__attribute__((naked, noinline, noclone))
prvPortStartFirstTask ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ldr r0, =0xE000ED08 	
 ldr r0, [r0] 			
 ldr r0, [r0] 			
 msr msp, r0			
 mov r0, #0			
 msr control, r0		
 cpsie i				
 cpsie f				
 dsb					
 isb					
 svc 0					
 nop					
 .ltorg				
");
  return;

}



;; Function vPortEnableVFP (vPortEnableVFP, funcdef_no=15, decl_uid=5779, cgraph_uid=16, symbol_order=19)

Modification phase of node vPortEnableVFP/19
__attribute__((naked, noinline, noclone))
vPortEnableVFP ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	ldr.w r0, =0xE000ED88		
	ldr r1, [r0]				
								
	orr r1, r1, #( 0xf << 20 )	
	str r1, [r0]				
	bx r14						
	.ltorg						
");
  return;

}



;; Function prvTaskExitError (prvTaskExitError, funcdef_no=5, decl_uid=5781, cgraph_uid=6, symbol_order=9)

Modification phase of node prvTaskExitError/9
prvTaskExitError ()
{
  uint32_t ulNewBASEPRI;
  volatile uint32_t ulDummy;
  long unsigned int uxCriticalNesting.3_1;
  long unsigned int ulDummy.4_2;

  <bb 2> [local count: 162688]:
  # DEBUG BEGIN_STMT
  ulDummy ={v} 0;
  # DEBUG BEGIN_STMT
  uxCriticalNesting.3_1 = uxCriticalNesting;
  if (uxCriticalNesting.3_1 != 4294967295)
    goto <bb 3>; [66.00%]
  else
    goto <bb 4>; [34.00%]

  <bb 3> [local count: 107374]:
  prvTaskExitError.part.0 ();

  <bb 4> [local count: 55314]:
  # DEBUG BEGIN_STMT
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

  <bb 5> [local count: 502853]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ulDummy.4_2 ={v} ulDummy;
  if (ulDummy.4_2 == 0)
    goto <bb 7>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 7> [local count: 447539]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 55314]:
  return;

}



;; Function pxPortInitialiseStack (pxPortInitialiseStack, funcdef_no=4, decl_uid=5420, cgraph_uid=5, symbol_order=8)

Modification phase of node pxPortInitialiseStack/8
pxPortInitialiseStack (StackType_t * pxTopOfStack, void (*TaskFunction_t) (void *) pxCode, void * pvParameters)
{
  long unsigned int pxCode.0_1;
  long unsigned int _2;
  long unsigned int prvTaskExitError.1_3;
  long unsigned int pvParameters.2_4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG pxTopOfStack => pxTopOfStack_5(D) + 4294967292
  # DEBUG BEGIN_STMT
  MEM[(StackType_t *)pxTopOfStack_5(D) + 4294967292B] = 16777216;
  # DEBUG BEGIN_STMT
  # DEBUG D#4 => &MEM[(void *)pxTopOfStack_5(D) + 4294967288B]
  # DEBUG pxTopOfStack => D#4
  # DEBUG BEGIN_STMT
  pxCode.0_1 = (long unsigned int) pxCode_8(D);
  _2 = pxCode.0_1 & 4294967294;
  MEM[(StackType_t *)pxTopOfStack_5(D) + 4294967288B] = _2;
  # DEBUG BEGIN_STMT
  # DEBUG D#3 => &MEM[(void *)pxTopOfStack_5(D) + 4294967284B]
  # DEBUG pxTopOfStack => D#3
  # DEBUG BEGIN_STMT
  prvTaskExitError.1_3 = (long unsigned int) prvTaskExitError;
  MEM[(StackType_t *)pxTopOfStack_5(D) + 4294967284B] = prvTaskExitError.1_3;
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => &MEM[(void *)pxTopOfStack_5(D) + 4294967264B]
  # DEBUG pxTopOfStack => D#2
  # DEBUG BEGIN_STMT
  pvParameters.2_4 = (long unsigned int) pvParameters_11(D);
  MEM[(StackType_t *)pxTopOfStack_5(D) + 4294967264B] = pvParameters.2_4;
  # DEBUG BEGIN_STMT
  # DEBUG D#1 => &MEM[(void *)pxTopOfStack_5(D) + 4294967260B]
  # DEBUG pxTopOfStack => D#1
  # DEBUG BEGIN_STMT
  MEM[(StackType_t *)pxTopOfStack_5(D) + 4294967260B] = 4294967293;
  # DEBUG BEGIN_STMT
  pxTopOfStack_14 = &MEM[(void *)pxTopOfStack_5(D) + 4294967228B];
  # DEBUG pxTopOfStack => pxTopOfStack_14
  # DEBUG BEGIN_STMT
  return pxTopOfStack_14;

}



;; Function SVC_Handler (SVC_Handler, funcdef_no=6, decl_uid=5775, cgraph_uid=7, symbol_order=10)

Modification phase of node SVC_Handler/10
__attribute__((naked, noinline, noclone))
SVC_Handler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	ldr	r3, pxCurrentTCBConst2		
	ldr r1, [r3]					
	ldr r0, [r1]					
	ldmia r0!, {r4-r11, r14}		
	msr psp, r0						
	isb								
	mov r0, #0 						
	msr	basepri, r0					
	bx r14							
									
	.align 4						
pxCurrentTCBConst2: .word pxCurrentTCB				
");
  return;

}



;; Function vPortEndScheduler (vPortEndScheduler, funcdef_no=9, decl_uid=5451, cgraph_uid=10, symbol_order=13)

Modification phase of node vPortEndScheduler/13
vPortEndScheduler ()
{
  uint32_t ulNewBASEPRI;
  long unsigned int uxCriticalNesting.13_1;

  <bb 2> [local count: 162688]:
  # DEBUG BEGIN_STMT
  uxCriticalNesting.13_1 = uxCriticalNesting;
  if (uxCriticalNesting.13_1 != 1000)
    goto <bb 3>; [66.00%]
  else
    goto <bb 5>; [34.00%]

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
" : "=r" ulNewBASEPRI_3 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_3

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 55314]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function vPortEnterCritical (vPortEnterCritical, funcdef_no=10, decl_uid=5393, cgraph_uid=11, symbol_order=14)

Modification phase of node vPortEnterCritical/14
vPortEnterCritical ()
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  long unsigned int uxCriticalNesting.14_1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 631612]:
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
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  uxCriticalNesting.14_1 = uxCriticalNesting;
  _2 = uxCriticalNesting.14_1 + 1;
  uxCriticalNesting = _2;
  # DEBUG BEGIN_STMT
  if (_2 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 3> [local count: 214748]:
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(volatile uint32_t *)3758157060B];
  _4 = _3 & 255;
  if (_4 != 0)
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
" : "=r" ulNewBASEPRI_8 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_8

  <bb 5> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 524238]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function vPortExitCritical (vPortExitCritical, funcdef_no=11, decl_uid=5395, cgraph_uid=12, symbol_order=15)

Modification phase of node vPortExitCritical/15
vPortExitCritical ()
{
  uint32_t ulNewBASEPRI;
  long unsigned int uxCriticalNesting.16_1;
  long unsigned int _2;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  uxCriticalNesting.16_1 = uxCriticalNesting;
  if (uxCriticalNesting.16_1 == 0)
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
" : "=r" ulNewBASEPRI_6 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_6

  <bb 4> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = uxCriticalNesting.16_1 + 4294967295;
  uxCriticalNesting = _2;
  # DEBUG BEGIN_STMT
  if (_2 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 53687]:
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => 0
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" 0 : "memory");

  <bb 7> [local count: 107374]:
  # DEBUG ulNewMaskValue => NULL
  return;

}



;; Function PendSV_Handler (PendSV_Handler, funcdef_no=12, decl_uid=5771, cgraph_uid=13, symbol_order=16)

Modification phase of node PendSV_Handler/16
__attribute__((naked, noinline, noclone))
PendSV_Handler ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	mrs r0, psp							
	isb									
										
	ldr	r3, pxCurrentTCBConst			
	ldr	r2, [r3]						
										
	tst r14, #0x10						
	it eq								
	vstmdbeq r0!, {s16-s31}				
										
	stmdb r0!, {r4-r11, r14}			
	str r0, [r2]						
										
	stmdb sp!, {r0, r3}					
	mov r0, %0 							
	cpsid i								
	msr basepri, r0						
	dsb									
	isb									
	cpsie i								
	bl vTaskSwitchContext				
	mov r0, #0							
	msr basepri, r0						
	ldmia sp!, {r0, r3}					
										
	ldr r1, [r3]						
	ldr r0, [r1]						
										
	ldmia r0!, {r4-r11, r14}			
										
	tst r14, #0x10						
	it eq								
	vldmiaeq r0!, {s16-s31}				
										
	msr psp, r0							
	isb									
										
										
	bx r14								
										
	.align 4							
pxCurrentTCBConst: .word pxCurrentTCB	
" :  : "i" 16);
  return;

}



;; Function SysTick_Handler (SysTick_Handler, funcdef_no=13, decl_uid=5773, cgraph_uid=14, symbol_order=17)

Modification phase of node SysTick_Handler/17
SysTick_Handler ()
{
  uint32_t ulNewBASEPRI;
  long int _1;

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
" : "=r" ulNewBASEPRI_6 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  _1 = xTaskIncrementTick ();
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758157060B] ={v} 268435456;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ulNewMaskValue => 0
  # DEBUG INLINE_ENTRY vPortSetBASEPRI
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("	msr basepri, %0	" :  : "r" 0 : "memory");
  # DEBUG ulNewMaskValue => NULL
  return;

}



;; Function vPortSetupTimerInterrupt (vPortSetupTimerInterrupt, funcdef_no=14, decl_uid=5769, cgraph_uid=15, symbol_order=18)

Modification phase of node vPortSetupTimerInterrupt/18
__attribute__((weak))
vPortSetupTimerInterrupt ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758153744B] ={v} 0;
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758153752B] ={v} 0;
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758153748B] ={v} 399999;
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)3758153744B] ={v} 7;
  return;

}



;; Function xPortStartScheduler (xPortStartScheduler, funcdef_no=8, decl_uid=5449, cgraph_uid=9, symbol_order=12)

Modification phase of node xPortStartScheduler/12
xPortStartScheduler ()
{
  uint32_t ulNewBASEPRI;
  volatile uint8_t ucMaxPriorityValue;
  volatile uint32_t ulOriginalPriority;
  signed char _1;
  unsigned char _2;
  long unsigned int _3;
  unsigned char _4;
  unsigned char ucMaxPriorityValue.5_5;
  unsigned char _6;
  long unsigned int ulMaxPRIGROUPValue.6_7;
  long unsigned int _8;
  unsigned char ucMaxPriorityValue.7_9;
  unsigned char _10;
  unsigned char ucMaxPriorityValue.8_11;
  long unsigned int ulMaxPRIGROUPValue.9_12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int ulOriginalPriority.12_16;
  unsigned char _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;

  <bb 2> [local count: 134621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pucFirstUserPriorityRegister => 3758154752B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(volatile uint8_t *)3758154752B];
  _3 = (long unsigned int) _2;
  ulOriginalPriority ={v} _3;
  # DEBUG BEGIN_STMT
  MEM[(volatile uint8_t *)3758154752B] ={v} 255;
  # DEBUG BEGIN_STMT
  _4 ={v} MEM[(volatile uint8_t *)3758154752B];
  ucMaxPriorityValue ={v} _4;
  # DEBUG BEGIN_STMT
  ucMaxPriorityValue.5_5 ={v} ucMaxPriorityValue;
  _6 = ucMaxPriorityValue.5_5 & 16;
  ucMaxSysCallPriority = _6;
  # DEBUG BEGIN_STMT
  ulMaxPRIGROUPValue = 7;
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 1089209]:
  # DEBUG BEGIN_STMT
  ulMaxPRIGROUPValue.6_7 = ulMaxPRIGROUPValue;
  _8 = ulMaxPRIGROUPValue.6_7 + 4294967295;
  ulMaxPRIGROUPValue = _8;
  # DEBUG BEGIN_STMT
  ucMaxPriorityValue.7_9 ={v} ucMaxPriorityValue;
  _10 = ucMaxPriorityValue.7_9 << 1;
  ucMaxPriorityValue ={v} _10;

  <bb 4> [local count: 1223831]:
  # DEBUG BEGIN_STMT
  ucMaxPriorityValue.8_11 ={v} ucMaxPriorityValue;
  _1 = (signed char) ucMaxPriorityValue.8_11;
  if (_1 < 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 134621]:
  # DEBUG BEGIN_STMT
  ulMaxPRIGROUPValue.9_12 = ulMaxPRIGROUPValue;
  _13 = 7 - ulMaxPRIGROUPValue.9_12;
  if (_13 != 4)
    goto <bb 6>; [79.76%]
  else
    goto <bb 8>; [20.24%]

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
" : "=r" ulNewBASEPRI_44 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_44

  <bb 7> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 27247]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = ulMaxPRIGROUPValue.9_12 << 8;
  # DEBUG BEGIN_STMT
  _15 = _14 & 1792;
  ulMaxPRIGROUPValue = _15;
  # DEBUG BEGIN_STMT
  ulOriginalPriority.12_16 ={v} ulOriginalPriority;
  _17 = (unsigned char) ulOriginalPriority.12_16;
  MEM[(volatile uint8_t *)3758154752B] ={v} _17;
  # DEBUG BEGIN_STMT
  _18 ={v} MEM[(volatile uint32_t *)3758157088B];
  _19 = _18 | 15728640;
  MEM[(volatile uint32_t *)3758157088B] ={v} _19;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(volatile uint32_t *)3758157088B];
  _21 = _20 | 4026531840;
  MEM[(volatile uint32_t *)3758157088B] ={v} _21;
  # DEBUG BEGIN_STMT
  vPortSetupTimerInterrupt ();
  # DEBUG BEGIN_STMT
  uxCriticalNesting = 0;
  # DEBUG BEGIN_STMT
  vPortEnableVFP ();
  # DEBUG BEGIN_STMT
  _22 ={v} MEM[(volatile uint32_t *)3758157620B];
  _23 = _22 | 3221225472;
  MEM[(volatile uint32_t *)3758157620B] ={v} _23;
  # DEBUG BEGIN_STMT
  prvPortStartFirstTask ();
  # DEBUG BEGIN_STMT
  vTaskSwitchContext ();
  # DEBUG BEGIN_STMT
  prvTaskExitError ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function vPortValidateInterruptPriority (vPortValidateInterruptPriority, funcdef_no=16, decl_uid=5399, cgraph_uid=17, symbol_order=20)

Modification phase of node vPortValidateInterruptPriority/20
vPortValidateInterruptPriority ()
{
  uint32_t ulNewBASEPRI;
  uint32_t ulNewBASEPRI;
  uint8_t ucCurrentPriority;
  uint32_t ulCurrentInterrupt;
  const uint8_t * _1;
  unsigned char ucMaxSysCallPriority.19_2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int ulMaxPRIGROUPValue.20_5;

  <bb 2> [local count: 286331]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("mrs %0, ipsr" : "=r" ulCurrentInterrupt_8 :  : "memory");
  # DEBUG ulCurrentInterrupt => ulCurrentInterrupt_8
  # DEBUG BEGIN_STMT
  if (ulCurrentInterrupt_8 > 15)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 143165]:
  # DEBUG BEGIN_STMT
  _1 = 3758154736B + ulCurrentInterrupt_8;
  ucCurrentPriority_9 ={v} *_1;
  # DEBUG ucCurrentPriority => ucCurrentPriority_9
  # DEBUG BEGIN_STMT
  ucMaxSysCallPriority.19_2 = ucMaxSysCallPriority;
  if (ucMaxSysCallPriority.19_2 > ucCurrentPriority_9)
    goto <bb 4>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 4> [local count: 71583]:
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

  <bb 5> [local count: 715827883]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 715827883]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(volatile uint32_t *)3758157068B];
  _4 = _3 & 1792;
  ulMaxPRIGROUPValue.20_5 = ulMaxPRIGROUPValue;
  if (_4 > ulMaxPRIGROUPValue.20_5)
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
" : "=r" ulNewBASEPRI_11 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_11

  <bb 8> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741823]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 107374]:
  # DEBUG BEGIN_STMT
  return;

}


