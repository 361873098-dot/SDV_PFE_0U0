
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  vTaskStartScheduler/28:
  Jump functions of caller  xTaskCreate/27:
  Jump functions of caller  vTaskDelay/26:
  Jump functions of caller  creat_tasks_m7/24:
  Jump functions of caller  task_m7_core0_1000ms/23:
  Jump functions of caller  task_m7_core0_100ms/22:
  Jump functions of caller  task_m7_core0_10ms/21:
  Jump functions of caller  task_m7_core0_5ms/20:
  Jump functions of caller  task_m7_core0_1ms/19:

 Propagating constants:

Not considering creat_tasks_m7 for cloning; -fipa-cp-clone disabled.
Not considering task_m7_core0_1000ms for cloning; -fipa-cp-clone disabled.
Not considering task_m7_core0_100ms for cloning; -fipa-cp-clone disabled.
Not considering task_m7_core0_10ms for cloning; -fipa-cp-clone disabled.
Not considering task_m7_core0_5ms for cloning; -fipa-cp-clone disabled.
Not considering task_m7_core0_1ms for cloning; -fipa-cp-clone disabled.

overall_size: 79, max_new_size: 11001
 - context independent values, size: 8, time_benefit: 1.000000
 - context independent values, size: 8, time_benefit: 1.000000
 - context independent values, size: 8, time_benefit: 1.000000
 - context independent values, size: 8, time_benefit: 1.000000
 - context independent values, size: 8, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: creat_tasks_m7/24:
  Node: task_m7_core0_1000ms/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: task_m7_core0_100ms/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: task_m7_core0_10ms/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: task_m7_core0_5ms/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: task_m7_core0_1ms/19:
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

vTaskStartScheduler/28 (vTaskStartScheduler) @0ab17540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: creat_tasks_m7/24 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
xTaskCreate/27 (xTaskCreate) @0ab17460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: creat_tasks_m7/24 (1073741824 (estimated locally),1.00 per call) creat_tasks_m7/24 (1073741824 (estimated locally),1.00 per call) creat_tasks_m7/24 (1073741824 (estimated locally),1.00 per call) creat_tasks_m7/24 (1073741824 (estimated locally),1.00 per call) creat_tasks_m7/24 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
vTaskDelay/26 (vTaskDelay) @0a765ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: task_m7_core0_1000ms/23 (1073741824 (estimated locally),10000.02 per call) task_m7_core0_100ms/22 (1073741824 (estimated locally),10000.02 per call) task_m7_core0_10ms/21 (1073741824 (estimated locally),10000.02 per call) task_m7_core0_5ms/20 (1073741824 (estimated locally),10000.02 per call) task_m7_core0_1ms/19 (1073741824 (estimated locally),10000.02 per call) 
  Calls: 
OsTaskCount/25 (OsTaskCount) @0a75eca8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: task_m7_core0_10ms/21 (read)task_m7_core0_100ms/22 (read)task_m7_core0_1ms/19 (read)task_m7_core0_5ms/20 (read)task_m7_core0_1000ms/23 (read)
  Availability: not_available
  Varpool flags:
creat_tasks_m7/24 (creat_tasks_m7) @0a765a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: task_m7_core0_1ms/19 (addr)task_m7_core0_5ms/20 (addr)task_m7_core0_10ms/21 (addr)task_m7_core0_100ms/22 (addr)task_m7_core0_1000ms/23 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: vTaskStartScheduler/28 (1073741824 (estimated locally),1.00 per call) xTaskCreate/27 (1073741824 (estimated locally),1.00 per call) xTaskCreate/27 (1073741824 (estimated locally),1.00 per call) xTaskCreate/27 (1073741824 (estimated locally),1.00 per call) xTaskCreate/27 (1073741824 (estimated locally),1.00 per call) xTaskCreate/27 (1073741824 (estimated locally),1.00 per call) 
task_m7_core0_1000ms/23 (task_m7_core0_1000ms) @0a7657e0
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: OsTaskCount/25 (read)
  Referring: creat_tasks_m7/24 (addr)
  Availability: available
  Function flags: count:107374 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: vTaskDelay/26 (1073741824 (estimated locally),10000.02 per call) 
task_m7_core0_100ms/22 (task_m7_core0_100ms) @0a765460
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: OsTaskCount/25 (read)
  Referring: creat_tasks_m7/24 (addr)
  Availability: available
  Function flags: count:107374 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: vTaskDelay/26 (1073741824 (estimated locally),10000.02 per call) 
task_m7_core0_10ms/21 (task_m7_core0_10ms) @0a7650e0
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: OsTaskCount/25 (read)
  Referring: creat_tasks_m7/24 (addr)
  Availability: available
  Function flags: count:107374 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: vTaskDelay/26 (1073741824 (estimated locally),10000.02 per call) 
task_m7_core0_5ms/20 (task_m7_core0_5ms) @0a75cd20
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: OsTaskCount/25 (read)
  Referring: creat_tasks_m7/24 (addr)
  Availability: available
  Function flags: count:107374 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: vTaskDelay/26 (1073741824 (estimated locally),10000.02 per call) 
task_m7_core0_1ms/19 (task_m7_core0_1ms) @0a75c460
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: OsTaskCount/25 (read)
  Referring: creat_tasks_m7/24 (addr)
  Availability: available
  Function flags: count:107374 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: vTaskDelay/26 (1073741824 (estimated locally),10000.02 per call) 

;; Function task_m7_core0_1ms (task_m7_core0_1ms, funcdef_no=17, decl_uid=14469, cgraph_uid=18, symbol_order=19) (executed once)

Modification phase of node task_m7_core0_1ms/19
task_m7_core0_1ms (void * pvParameters)
{
  uint32 * _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = OsTaskCount.M7_Core0_1ms;
  _2 = *_1;
  _3 = _2 + 1;
  *_1 = _3;
  # DEBUG BEGIN_STMT
  vTaskDelay (1);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

}



;; Function task_m7_core0_5ms (task_m7_core0_5ms, funcdef_no=18, decl_uid=14473, cgraph_uid=19, symbol_order=20) (executed once)

Modification phase of node task_m7_core0_5ms/20
task_m7_core0_5ms (void * pvParameters)
{
  uint32 * _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = OsTaskCount.M7_Core0_5ms;
  _2 = *_1;
  _3 = _2 + 1;
  *_1 = _3;
  # DEBUG BEGIN_STMT
  vTaskDelay (5);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

}



;; Function task_m7_core0_10ms (task_m7_core0_10ms, funcdef_no=19, decl_uid=14477, cgraph_uid=20, symbol_order=21) (executed once)

Modification phase of node task_m7_core0_10ms/21
task_m7_core0_10ms (void * pvParameters)
{
  uint32 * _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = OsTaskCount.M7_Core0_10ms;
  _2 = *_1;
  _3 = _2 + 1;
  *_1 = _3;
  # DEBUG BEGIN_STMT
  vTaskDelay (10);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

}



;; Function task_m7_core0_100ms (task_m7_core0_100ms, funcdef_no=20, decl_uid=14481, cgraph_uid=21, symbol_order=22) (executed once)

Modification phase of node task_m7_core0_100ms/22
task_m7_core0_100ms (void * pvParameters)
{
  uint32 * _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = OsTaskCount.M7_Core0_100ms;
  _2 = *_1;
  _3 = _2 + 1;
  *_1 = _3;
  # DEBUG BEGIN_STMT
  vTaskDelay (100);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

}



;; Function task_m7_core0_1000ms (task_m7_core0_1000ms, funcdef_no=21, decl_uid=14485, cgraph_uid=22, symbol_order=23) (executed once)

Modification phase of node task_m7_core0_1000ms/23
task_m7_core0_1000ms (void * pvParameters)
{
  uint32 * _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = OsTaskCount.M7_Core0_1000ms;
  _2 = *_1;
  _3 = _2 + 1;
  *_1 = _3;
  # DEBUG BEGIN_STMT
  vTaskDelay (1000);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

}



;; Function creat_tasks_m7 (creat_tasks_m7, funcdef_no=22, decl_uid=14489, cgraph_uid=23, symbol_order=24)

Modification phase of node creat_tasks_m7/24
creat_tasks_m7 ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  xTaskCreate (task_m7_core0_1ms, "task_m7_core0_1ms", 90, 0B, 1, 0B);
  # DEBUG BEGIN_STMT
  xTaskCreate (task_m7_core0_5ms, "task_m7_core0_5ms", 90, 0B, 2, 0B);
  # DEBUG BEGIN_STMT
  xTaskCreate (task_m7_core0_10ms, "task_m7_core0_10ms", 90, 0B, 3, 0B);
  # DEBUG BEGIN_STMT
  xTaskCreate (task_m7_core0_100ms, "task_m7_core0_100ms", 90, 0B, 4, 0B);
  # DEBUG BEGIN_STMT
  xTaskCreate (task_m7_core0_1000ms, "task_m7_core0_1000ms", 90, 0B, 5, 0B);
  # DEBUG BEGIN_STMT
  vTaskStartScheduler ();
  return;

}


