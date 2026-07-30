
IPA constant propagation start:
Determining dynamic type for call: ipc_strcpy (buf_37, &sharpstr);
  Starting walk at: ipc_strcpy (buf_37, &sharpstr);
  instance pointer: buf_37  Outer instance pointer: buf_37 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: ipc_strcpy (buf_37, &sharpstr);
  Starting walk at: ipc_strcpy (buf_37, &sharpstr);
  instance pointer: &sharpstr  Outer instance pointer: sharpstr offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: _9 = ipc_strrchr (buf_37, 35);
  Starting walk at: _9 = ipc_strrchr (buf_37, 35);
  instance pointer: buf_37  Outer instance pointer: buf_37 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: ipc_numtostr (_8, _9);
  Starting walk at: ipc_numtostr (_8, _9);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: _10 = ipc_strlen (buf_37);
  Starting walk at: _10 = ipc_strlen (buf_37);
  instance pointer: buf_37  Outer instance pointer: buf_37 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: ipc_strcpy (_11, &hellostr);
  Starting walk at: ipc_strcpy (_11, &hellostr);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: ipc_strcpy (_11, &hellostr);
  Starting walk at: ipc_strcpy (_11, &hellostr);
  instance pointer: &hellostr  Outer instance pointer: hellostr offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: _14 = ipc_strrchr (buf_37, 32);
  Starting walk at: _14 = ipc_strrchr (buf_37, 32);
  instance pointer: buf_37  Outer instance pointer: buf_37 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: ipc_numtostr (_13, _14);
  Starting walk at: ipc_numtostr (_13, _14);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: _15 = ipc_strlen (buf_37);
  Starting walk at: _15 = ipc_strlen (buf_37);
  instance pointer: buf_37  Outer instance pointer: buf_37 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:reply_ctrl_msg (0, 0);
  Function call may change dynamic type:err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  Function call may change dynamic type:ipc_numtostr (_13, _14);
  Function call may change dynamic type:_12 = Sys_GetCoreID ();
  Function call may change dynamic type:ipc_strcpy (_11, &hellostr);
  Function call may change dynamic type:ipc_numtostr (_8, _9);
  Function call may change dynamic type:ipc_strcpy (buf_37, &sharpstr);
  Function call may change dynamic type:buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  Function call may change dynamic type:_6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  Function call may change dynamic type:_3 = ipc_shm_unmanaged_acquire (0, 0);
  Function call may change dynamic type:_2 = ipc_shm_is_remote_ready (0);
  Function call may change dynamic type:err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  Function call may change dynamic type:_1 = xQueueCreateCountingSemaphore (255, 0);
Determining dynamic type for call: ipc_strcpy (_1, &repl_buf);
  Starting walk at: ipc_strcpy (_1, &repl_buf);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ipc_strcpy (_1, &repl_buf);
  Starting walk at: ipc_strcpy (_1, &repl_buf);
  instance pointer: &repl_buf  Outer instance pointer: repl_buf offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = ipc_strrchr (_3, 32);
  Starting walk at: _4 = ipc_strrchr (_3, 32);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipc_strcpy (_1, &repl_buf);
Determining dynamic type for call: ipc_numtostr (_2, _4);
  Starting walk at: ipc_numtostr (_2, _4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ipc_strcpy (_1, &repl_buf);
Determining dynamic type for call: _2 = ipc_strlen (mem_10(D));
  Starting walk at: _2 = ipc_strlen (mem_10(D));
  instance pointer: mem_10(D)  Outer instance pointer: mem_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = ipc_strlen (&send_buf);
  Starting walk at: _3 = ipc_strlen (&send_buf);
  instance pointer: &send_buf  Outer instance pointer: send_buf offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = ipc_strtol (_4);
  Starting walk at: _5 = ipc_strtol (_4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = ipc_strlen (&sharpstr);
  Starting walk at: _2 = ipc_strlen (&sharpstr);
  instance pointer: &sharpstr  Outer instance pointer: sharpstr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = ipc_strtol (_3);
  Starting walk at: _4 = ipc_strtol (_3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  vTaskStartScheduler/37:
  Jump functions of caller  xTaskCreate/36:
  Jump functions of caller  ipc_shm_unmanaged_tx/35:
  Jump functions of caller  ipc_shm_tx/34:
  Jump functions of caller  Sys_GetCoreID/33:
  Jump functions of caller  ipc_shm_acquire_buf/32:
  Jump functions of caller  xQueueSemaphoreTake/31:
  Jump functions of caller  ipc_shm_unmanaged_acquire/30:
  Jump functions of caller  ipc_shm_is_remote_ready/29:
  Jump functions of caller  ipc_shm_init/27:
  Jump functions of caller  xQueueCreateCountingSemaphore/26:
  Jump functions of caller  xQueueGenericSend/25:
  Jump functions of caller  ipc_shm_release_buf/24:
  Jump functions of caller  vApplicationStackOverflowHook/23:
  Jump functions of caller  vApplicationMallocFailedHook/22:
  Jump functions of caller  prepare_demo/21:
  Jump functions of caller  handle_error/20:
  Jump functions of caller  shm_demo/19:
    callsite  shm_demo/19 -> reply_ctrl_msg/18 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  shm_demo/19 -> ipc_strlen/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  shm_demo/19 -> ipc_numtostr/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  shm_demo/19 -> ipc_strrchr/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 32
         value: 0x20, mask: 0x0
         Unknown VR
    callsite  shm_demo/19 -> ipc_strcpy/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: &hellostr
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  shm_demo/19 -> ipc_strlen/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  shm_demo/19 -> ipc_numtostr/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  shm_demo/19 -> ipc_strrchr/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 35
         value: 0x23, mask: 0x0
         Unknown VR
    callsite  shm_demo/19 -> ipc_strcpy/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &sharpstr
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  reply_ctrl_msg/18:
    callsite  reply_ctrl_msg/18 -> ipc_numtostr/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  reply_ctrl_msg/18 -> ipc_strrchr/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 32
         value: 0x20, mask: 0x0
         Unknown VR
    callsite  reply_ctrl_msg/18 -> ipc_strcpy/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &repl_buf
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  ctrl_chan_rx_cb/17:
    callsite  ctrl_chan_rx_cb/17 -> ipc_strtol/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ctrl_chan_rx_cb/17 -> ipc_strlen/12 : 
       param 0: CONST: &send_buf
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  ctrl_chan_rx_cb/17 -> ipc_strlen/12 : 
       param 0: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  data_chan_rx_cb/16:
    callsite  data_chan_rx_cb/16 -> ipc_strtol/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  data_chan_rx_cb/16 -> ipc_strlen/12 : 
       param 0: CONST: &sharpstr
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  ipc_numtostr/15:
  Jump functions of caller  ipc_strrchr/14:
  Jump functions of caller  ipc_strcpy/13:
  Jump functions of caller  ipc_strlen/12:
  Jump functions of caller  ipc_strtol/11:

 Propagating constants:

Not considering vApplicationStackOverflowHook for cloning; -fipa-cp-clone disabled.
Not considering vApplicationMallocFailedHook for cloning; -fipa-cp-clone disabled.
Not considering prepare_demo for cloning; -fipa-cp-clone disabled.
Not considering handle_error for cloning; -fipa-cp-clone disabled.
Not considering shm_demo for cloning; -fipa-cp-clone disabled.
Not considering ctrl_chan_rx_cb for cloning; -fipa-cp-clone disabled.
Not considering data_chan_rx_cb for cloning; -fipa-cp-clone disabled.
Not considering ipc_strrchr for cloning; -fipa-cp-clone disabled.
Not considering ipc_strcpy for cloning; -fipa-cp-clone disabled.
Not considering ipc_strlen for cloning; -fipa-cp-clone disabled.
Not considering ipc_strtol for cloning; -fipa-cp-clone disabled.

overall_size: 273, max_new_size: 11001
 - context independent values, size: 9, time_benefit: 2.000000
 - context independent values, size: 2, time_benefit: 1.000000
 - context independent values, size: 93, time_benefit: 1.000000
 - context independent values, size: 20, time_benefit: 2.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: vApplicationStackOverflowHook/23:
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
  Node: vApplicationMallocFailedHook/22:
  Node: prepare_demo/21:
  Node: handle_error/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: shm_demo/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: reply_ctrl_msg/18:
    param [0]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         const uint8 [0, 0]
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
  Node: ctrl_chan_rx_cb/17:
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
  Node: data_chan_rx_cb/16:
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
  Node: ipc_numtostr/15:
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
  Node: ipc_strrchr/14:
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
  Node: ipc_strcpy/13:
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
  Node: ipc_strlen/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_strtol/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:

 - Creating a specialized node of reply_ctrl_msg/18 for all known contexts.
    replacing param #0 instance with const 0
    replacing param #1 chan_id with const 0
Propagated bits info for function reply_ctrl_msg.constprop/50:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x0, mask = 0x0
Propagated bits info for function reply_ctrl_msg/18:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x0, mask = 0x0

IPA constant propagation end

Reclaiming functions: reply_ctrl_msg/18
Reclaiming variables:
Clearing address taken flags:
Symbol table:

reply_ctrl_msg.constprop.0/50 (reply_ctrl_msg.constprop) @06f41380
  Type: function definition analyzed
  Visibility:
  References: app/8 (read)repl_buf/7 (addr)app/8 (read)app/8 (read)
  Referring: 
  Clone of reply_ctrl_msg/18
  Availability: local
  Function flags: count:214748 (estimated locally) local optimize_size
  Called by: shm_demo/19 (23689 (estimated locally),0.11 per call) 
  Calls: ipc_strcpy/13 (214748 (estimated locally),1.00 per call) ipc_strrchr/14 (214748 (estimated locally),1.00 per call) ipc_numtostr/15 (214748 (estimated locally),1.00 per call) ipc_shm_unmanaged_tx/35 (214748 (estimated locally),1.00 per call) 
vTaskStartScheduler/37 (vTaskStartScheduler) @07008a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prepare_demo/21 (27247 (estimated locally),0.20 per call) 
  Calls: 
xTaskCreate/36 (xTaskCreate) @070089a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prepare_demo/21 (134621 (estimated locally),1.00 per call) 
  Calls: 
ipc_shm_unmanaged_tx/35 (ipc_shm_unmanaged_tx) @07008700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: reply_ctrl_msg.constprop/50 (214748 (estimated locally),1.00 per call) 
  Calls: 
ipc_shm_tx/34 (ipc_shm_tx) @07008460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shm_demo/19 (885769 (estimated locally),4.12 per call) 
  Calls: 
Sys_GetCoreID/33 (Sys_GetCoreID) @07008380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shm_demo/19 (910816 (estimated locally),4.24 per call) 
  Calls: 
ipc_shm_acquire_buf/32 (ipc_shm_acquire_buf) @070082a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shm_demo/19 (936572 (estimated locally),4.36 per call) 
  Calls: 
xQueueSemaphoreTake/31 (xQueueSemaphoreTake) @070081c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shm_demo/19 (8514289 (estimated locally),39.65 per call) 
  Calls: 
ipc_shm_unmanaged_acquire/30 (ipc_shm_unmanaged_acquire) @07008000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shm_demo/19 (107374 (estimated locally),0.50 per call) 
  Calls: 
ipc_shm_is_remote_ready/29 (ipc_shm_is_remote_ready) @06fa6ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shm_demo/19 (976127 (estimated locally),4.55 per call) 
  Calls: 
ipcf_shm_instances_cfg/28 (ipcf_shm_instances_cfg) @07007510
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: shm_demo/19 (addr)
  Availability: not_available
  Varpool flags:
ipc_shm_init/27 (ipc_shm_init) @06fa6e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: shm_demo/19 (1952255 (estimated locally),9.09 per call) 
  Calls: 
xQueueCreateCountingSemaphore/26 (xQueueCreateCountingSemaphore) @06fa6d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: prepare_demo/21 (134621 (estimated locally),1.00 per call) shm_demo/19 (214748 (estimated locally),1.00 per call) 
  Calls: 
xQueueGenericSend/25 (xQueueGenericSend) @06fa6a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: data_chan_rx_cb/16 (788 (estimated locally),0.01 per call) 
  Calls: 
ipc_shm_release_buf/24 (ipc_shm_release_buf) @06fa69a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: data_chan_rx_cb/16 (2388 (estimated locally),0.02 per call) 
  Calls: 
vApplicationStackOverflowHook/23 (vApplicationStackOverflowHook) @06fa61c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:107374 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: 
vApplicationMallocFailedHook/22 (vApplicationMallocFailedHook) @06ffce00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:107374 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: 
prepare_demo/21 (prepare_demo) @06ffc000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: shm_event_rx/10 (write)shm_demo/19 (addr)
  Referring: 
  Availability: available
  Function flags: count:134621 (estimated locally) body optimize_size
  Called by: 
  Calls: vTaskStartScheduler/37 (27247 (estimated locally),0.20 per call) xTaskCreate/36 (134621 (estimated locally),1.00 per call) xQueueCreateCountingSemaphore/26 (134621 (estimated locally),1.00 per call) 
handle_error/20 (handle_error) @06ffcd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:107374 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: 
shm_demo/19 (shm_demo) @06ffca80
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: shm_event_rx/10 (write)app/8 (write)ipcf_shm_instances_cfg/28 (addr)app/8 (write)shm_event_rx/10 (read)app/8 (read)sharpstr/4 (addr)app/8 (read)hellostr/5 (addr)app/8 (read)app/8 (read)app/8 (write)app/8 (read)app/8 (read)
  Referring: prepare_demo/21 (addr)
  Availability: available
  Function flags: count:214748 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: reply_ctrl_msg.constprop/50 (23689 (estimated locally),0.11 per call) ipc_shm_tx/34 (885769 (estimated locally),4.12 per call) ipc_strlen/12 (910816 (estimated locally),4.24 per call) ipc_numtostr/15 (910816 (estimated locally),4.24 per call) ipc_strrchr/14 (910816 (estimated locally),4.24 per call) Sys_GetCoreID/33 (910816 (estimated locally),4.24 per call) ipc_strcpy/13 (910816 (estimated locally),4.24 per call) ipc_strlen/12 (910816 (estimated locally),4.24 per call) ipc_numtostr/15 (910816 (estimated locally),4.24 per call) ipc_strrchr/14 (910816 (estimated locally),4.24 per call) ipc_strcpy/13 (910816 (estimated locally),4.24 per call) ipc_shm_acquire_buf/32 (936572 (estimated locally),4.36 per call) xQueueSemaphoreTake/31 (8514289 (estimated locally),39.65 per call) ipc_shm_unmanaged_acquire/30 (107374 (estimated locally),0.50 per call) ipc_shm_is_remote_ready/29 (976127 (estimated locally),4.55 per call) ipc_shm_init/27 (1952255 (estimated locally),9.09 per call) xQueueCreateCountingSemaphore/26 (214748 (estimated locally),1.00 per call) 
reply_ctrl_msg/18 (reply_ctrl_msg) @06ffc7e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ctrl_chan_rx_cb/17 (ctrl_chan_rx_cb) @06ffc540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: app/8 (addr)send_buf/6 (addr)app/8 (write)app/8 (write)app/8 (write)
  Referring: 
  Availability: available
  Function flags: count:110099 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_strtol/11 (2725 (estimated locally),0.02 per call) ipc_strlen/12 (2725 (estimated locally),0.02 per call) ipc_strlen/12 (33030 (estimated locally),0.30 per call) 
data_chan_rx_cb/16 (data_chan_rx_cb) @06ffc2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: app/8 (addr)sharpstr/4 (addr)app/8 (write)app/8 (write)app/8 (read)app/8 (write)shm_event_rx/10 (read)
  Referring: 
  Availability: available
  Function flags: count:119172 (estimated locally) body optimize_size
  Called by: 
  Calls: xQueueGenericSend/25 (788 (estimated locally),0.01 per call) ipc_shm_release_buf/24 (2388 (estimated locally),0.02 per call) ipc_strtol/11 (11798 (estimated locally),0.10 per call) ipc_strlen/12 (11798 (estimated locally),0.10 per call) 
ipc_numtostr/15 (ipc_numtostr) @06ff0ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: reply_ctrl_msg.constprop/50 (214748 (estimated locally),1.00 per call) shm_demo/19 (910816 (estimated locally),4.24 per call) shm_demo/19 (910816 (estimated locally),4.24 per call) 
  Calls: 
ipc_strrchr/14 (ipc_strrchr) @06ff0c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: reply_ctrl_msg.constprop/50 (214748 (estimated locally),1.00 per call) shm_demo/19 (910816 (estimated locally),4.24 per call) shm_demo/19 (910816 (estimated locally),4.24 per call) 
  Calls: 
ipc_strcpy/13 (ipc_strcpy) @06ff09a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: reply_ctrl_msg.constprop/50 (214748 (estimated locally),1.00 per call) shm_demo/19 (910816 (estimated locally),4.24 per call) shm_demo/19 (910816 (estimated locally),4.24 per call) 
  Calls: 
ipc_strlen/12 (ipc_strlen) @06ff0700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: shm_demo/19 (910816 (estimated locally),4.24 per call) shm_demo/19 (910816 (estimated locally),4.24 per call) ctrl_chan_rx_cb/17 (2725 (estimated locally),0.02 per call) ctrl_chan_rx_cb/17 (33030 (estimated locally),0.30 per call) data_chan_rx_cb/16 (11798 (estimated locally),0.10 per call) 
  Calls: 
ipc_strtol/11 (ipc_strtol) @06ff0460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: ctrl_chan_rx_cb/17 (2725 (estimated locally),0.02 per call) data_chan_rx_cb/16 (11798 (estimated locally),0.10 per call) 
  Calls: 
shm_event_rx/10 (shm_event_rx) @06febcf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: data_chan_rx_cb/16 (read)shm_demo/19 (read)shm_demo/19 (write)prepare_demo/21 (write)
  Availability: available
  Varpool flags:
rx_cb_arg/9 (rx_cb_arg) @06febc60
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: app/8 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized
app/8 (app) @06febc18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: rx_cb_arg/9 (addr)data_chan_rx_cb/16 (write)reply_ctrl_msg.constprop.0/50 (read)ctrl_chan_rx_cb/17 (write)ctrl_chan_rx_cb/17 (write)ctrl_chan_rx_cb/17 (write)reply_ctrl_msg.constprop.0/50 (read)reply_ctrl_msg.constprop.0/50 (read)data_chan_rx_cb/16 (addr)data_chan_rx_cb/16 (write)data_chan_rx_cb/16 (write)data_chan_rx_cb/16 (read)ctrl_chan_rx_cb/17 (addr)shm_demo/19 (write)shm_demo/19 (write)shm_demo/19 (read)shm_demo/19 (read)shm_demo/19 (read)shm_demo/19 (read)shm_demo/19 (write)shm_demo/19 (read)shm_demo/19 (read)
  Availability: available
  Varpool flags:
repl_buf/7 (repl_buf) @06feb990
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: reply_ctrl_msg.constprop.0/50 (addr)
  Availability: available
  Varpool flags: initialized
send_buf/6 (send_buf) @06feb900
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ctrl_chan_rx_cb/17 (addr)
  Availability: available
  Varpool flags: initialized
hellostr/5 (hellostr) @06feb870
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: shm_demo/19 (addr)
  Availability: available
  Varpool flags: initialized
sharpstr/4 (sharpstr) @06feb7e0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: data_chan_rx_cb/16 (addr)shm_demo/19 (addr)
  Availability: available
  Varpool flags: initialized

;; Function ipc_numtostr (ipc_numtostr, funcdef_no=8, decl_uid=6307, cgraph_uid=9, symbol_order=15)

Modification phase of node ipc_numtostr/15
ipc_numtostr (uint16 num, sint8 * str)
{
  uint16 tmp;
  short unsigned int _1;
  unsigned char _2;
  unsigned char _3;
  signed char _4;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG tmp => num_11(D)
  # DEBUG BEGIN_STMT
  if (num_11(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  str_15 = str_13(D) + 1;
  # DEBUG str => str_15
  MEM[(sint8 *)str_13(D) + 1B] = 48;

  <bb 6> [local count: 118111600]:
  # str_26 = PHI <str_13(D)(2), str_15(3)>
  # tmp_24 = PHI <num_11(D)(2), num_11(D)(3)>
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 955630220]:
  # DEBUG BEGIN_STMT
  str_22 = str_6 + 1;
  # DEBUG str => str_22
  # DEBUG BEGIN_STMT
  tmp_23 = tmp_8 / 10;
  # DEBUG tmp => tmp_23

  <bb 11> [local count: 1073741821]:
  # str_6 = PHI <str_26(6), str_22(4)>
  # tmp_8 = PHI <tmp_24(6), tmp_23(4)>
  # DEBUG tmp => tmp_8
  # DEBUG str => str_6
  # DEBUG BEGIN_STMT
  if (tmp_8 != 0)
    goto <bb 4>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111600]:
  # str_25 = PHI <str_6(11)>
  # DEBUG BEGIN_STMT
  str_17 = str_25 + 1;
  # DEBUG str => str_17
  MEM[(sint8 *)str_25 + 1B] = 0;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  _1 = num_5 % 10;
  _2 = (unsigned char) _1;
  _3 = _2 + 48;
  str_19 = str_7 + 4294967295;
  # DEBUG str => str_19
  _4 = (signed char) _3;
  *str_19 = _4;
  # DEBUG BEGIN_STMT
  num_21 = num_5 / 10;
  # DEBUG num => num_21

  <bb 9> [local count: 1073741824]:
  # num_5 = PHI <num_11(D)(7), num_21(8)>
  # str_7 = PHI <str_17(7), str_19(8)>
  # DEBUG str => str_7
  # DEBUG num => num_5
  # DEBUG BEGIN_STMT
  if (num_5 != 0)
    goto <bb 8>; [89.00%]
  else
    goto <bb 10>; [11.00%]

  <bb 10> [local count: 118111601]:
  return;

}



;; Function ipc_strtol (ipc_strtol, funcdef_no=4, decl_uid=6278, cgraph_uid=5, symbol_order=11)

Modification phase of node ipc_strtol/11
ipc_strtol (sint8 * src)
{
  uint32 res;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  signed char _4;
  unsigned char _5;
  unsigned char _6;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG res => 0
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = res_8 * 10;
  src_12 = src_7 + 1;
  # DEBUG src => src_12
  _2 = (long unsigned int) _4;
  _3 = _1 + _2;
  res_13 = _3 + 4294967248;
  # DEBUG res => res_13

  <bb 4> [local count: 1073741824]:
  # src_7 = PHI <src_9(D)(2), src_12(3)>
  # res_8 = PHI <0(2), res_13(3)>
  # DEBUG res => res_8
  # DEBUG src => src_7
  # DEBUG BEGIN_STMT
  _4 = *src_7;
  _5 = (unsigned char) _4;
  _6 = _5 + 208;
  if (_6 <= 9)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # res_11 = PHI <res_8(4)>
  # DEBUG BEGIN_STMT
  return res_11;

}



;; Function ipc_strlen (ipc_strlen, funcdef_no=5, decl_uid=6285, cgraph_uid=6, symbol_order=12)

Modification phase of node ipc_strlen/12
ipc_strlen (const sint8 * src)
{
  uint32 i;
  const sint8 * _1;
  signed char _2;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  i_7 = i_3 + 1;
  # DEBUG i => i_7

  <bb 4> [local count: 1073741824]:
  # i_3 = PHI <0(2), i_7(3)>
  # DEBUG i => i_3
  # DEBUG BEGIN_STMT
  _1 = src_4(D) + i_3;
  _2 = *_1;
  if (_2 != 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # i_6 = PHI <i_3(4)>
  # DEBUG BEGIN_STMT
  return i_6;

}



;; Function ipc_strcpy (ipc_strcpy, funcdef_no=6, decl_uid=6293, cgraph_uid=7, symbol_order=13)

Modification phase of node ipc_strcpy/13
ipc_strcpy (sint8 * dst, const sint8 * src)
{
  signed char _1;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT

  <bb 3> [local count: 1073741824]:
  # dst_2 = PHI <dst_5(D)(2), dst_9(5)>
  # src_3 = PHI <src_6(D)(2), src_8(5)>
  # DEBUG src => src_3
  # DEBUG dst => dst_2
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  src_8 = src_3 + 1;
  # DEBUG src => src_8
  dst_9 = dst_2 + 1;
  # DEBUG dst => dst_9
  _1 = *src_3;
  *dst_2 = _1;
  if (_1 != 0)
    goto <bb 5>; [89.00%]
  else
    goto <bb 4>; [11.00%]

  <bb 5> [local count: 955630223]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 118111601]:
  return;

}



;; Function ipc_strrchr (ipc_strrchr, funcdef_no=7, decl_uid=6300, cgraph_uid=8, symbol_order=14)

Modification phase of node ipc_strrchr/14
ipc_strrchr (const sint8 * s, int c)
{
  sint8 * rtnval;
  signed char _1;
  int _2;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG rtnval => 0B

  <bb 3> [local count: 1073741824]:
  # s_3 = PHI <s_6(D)(2), s_10(7)>
  # rtnval_4 = PHI <0B(2), rtnval_5(7)>
  # DEBUG rtnval => rtnval_4
  # DEBUG s => s_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = *s_3;
  _2 = (int) _1;
  if (_2 == c_8(D))
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  # DEBUG rtnval => s_3

  <bb 5> [local count: 1073741824]:
  # rtnval_5 = PHI <rtnval_4(3), s_3(4)>
  # DEBUG rtnval => rtnval_5
  # DEBUG BEGIN_STMT
  s_10 = s_3 + 1;
  # DEBUG s => s_10
  if (_1 != 0)
    goto <bb 7>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 7> [local count: 955630223]:
  goto <bb 3>; [100.00%]

  <bb 6> [local count: 118111601]:
  # rtnval_9 = PHI <rtnval_5(5)>
  # DEBUG BEGIN_STMT
  return rtnval_9;

}



;; Function shm_demo (shm_demo, funcdef_no=12, decl_uid=6338, cgraph_uid=13, symbol_order=19) (executed once)

Modification phase of node shm_demo/19
shm_demo (void * params)
{
  sint8 * buf;
  sint8 err;
  struct QueueDefinition * _1;
  signed char _2;
  void * _3;
  struct QueueDefinition * shm_event_rx.5_5;
  long int _6;
  unsigned char _7;
  short unsigned int _8;
  sint8 * _9;
  long unsigned int _10;
  sint8 * _11;
  unsigned char _12;
  short unsigned int _13;
  sint8 * _14;
  long unsigned int _15;
  unsigned char _16;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG err => -3
  # DEBUG BEGIN_STMT
  # DEBUG buf => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = xQueueCreateCountingSemaphore (255, 0);
  shm_event_rx = _1;
  # DEBUG BEGIN_STMT
  app.rx_count ={v} 0;

  <bb 3> [local count: 1952255]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  err_31 = ipc_shm_init (&ipcf_shm_instances_cfg);
  # DEBUG err => err_31
  # DEBUG BEGIN_STMT
  if (err_31 == -7)
    goto <bb 35>; [89.00%]
  else
    goto <bb 4>; [11.00%]

  <bb 35> [local count: 1737507]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 214748]:
  # err_25 = PHI <err_31(3)>
  # DEBUG BEGIN_STMT
  if (err_25 != 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 26>; [50.00%]

  <bb 20> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 27> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 26> [local count: 107374]:

  <bb 6> [local count: 976127]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = ipc_shm_is_remote_ready (0);
  if (_2 != 0)
    goto <bb 34>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 34> [local count: 868753]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 107374]:
  # DEBUG BEGIN_STMT
  _3 = ipc_shm_unmanaged_acquire (0, 0);
  app.ctrl_shm = _3;
  # DEBUG BEGIN_STMT
  if (_3 == 0B)
    goto <bb 21>; [30.00%]
  else
    goto <bb 25>; [70.00%]

  <bb 25> [local count: 75162]:
  goto <bb 9>; [100.00%]

  <bb 21> [local count: 32212]:

  <bb 8> [local count: 322122549]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 28> [local count: 322122549]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 98851]:

  <bb 10> [local count: 936572]:

  <bb 11> [local count: 8514289]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  shm_event_rx.5_5 = shm_event_rx;
  _6 = xQueueSemaphoreTake (shm_event_rx.5_5, 1000);
  if (_6 != 0)
    goto <bb 12>; [11.00%]
  else
    goto <bb 33>; [89.00%]

  <bb 33> [local count: 7577717]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 936572]:
  # DEBUG BEGIN_STMT
  _7 = app.last_rx_ch;
  buf_37 = ipc_shm_acquire_buf (0, _7, 32);
  # DEBUG buf => buf_37
  # DEBUG BEGIN_STMT
  if (buf_37 == 0B)
    goto <bb 22>; [2.75%]
  else
    goto <bb 14>; [97.25%]

  <bb 22> [local count: 25756]:

  <bb 13> [local count: 257557674]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 29> [local count: 257557674]:
  goto <bb 13>; [100.00%]

  <bb 14> [local count: 910816]:
  # DEBUG BEGIN_STMT
  ipc_strcpy (buf_37, &sharpstr);
  # DEBUG BEGIN_STMT
  _8 ={v} app.tx_count;
  _9 = ipc_strrchr (buf_37, 35);
  ipc_numtostr (_8, _9);
  # DEBUG BEGIN_STMT
  _10 = ipc_strlen (buf_37);
  _11 = buf_37 + _10;
  ipc_strcpy (_11, &hellostr);
  # DEBUG BEGIN_STMT
  _12 = Sys_GetCoreID ();
  _13 = (short unsigned int) _12;
  _14 = ipc_strrchr (buf_37, 32);
  ipc_numtostr (_13, _14);
  # DEBUG BEGIN_STMT
  _15 = ipc_strlen (buf_37);
  if (_15 > 32)
    goto <bb 23>; [2.75%]
  else
    goto <bb 16>; [97.25%]

  <bb 23> [local count: 25047]:

  <bb 15> [local count: 250474838]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 30> [local count: 250474838]:
  goto <bb 15>; [100.00%]

  <bb 16> [local count: 885769]:
  # DEBUG BEGIN_STMT
  _16 = app.last_rx_ch;
  err_44 = ipc_shm_tx (0, _16, buf_37, _15);
  # DEBUG err => err_44
  # DEBUG BEGIN_STMT
  if (err_44 != 0)
    goto <bb 24>; [2.75%]
  else
    goto <bb 18>; [97.25%]

  <bb 24> [local count: 24359]:

  <bb 17> [local count: 243586781]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 31> [local count: 243586781]:
  goto <bb 17>; [100.00%]

  <bb 18> [local count: 861410]:
  # DEBUG BEGIN_STMT
  _18 ={v} app.tx_count;
  _19 = _18 + 1;
  app.tx_count ={v} _19;
  # DEBUG BEGIN_STMT
  _20 ={v} app.rx_count;
  _21 = app.expected_msgs;
  if (_20 == _21)
    goto <bb 19>; [2.75%]
  else
    goto <bb 32>; [97.25%]

  <bb 32> [local count: 837721]:
  goto <bb 10>; [100.00%]

  <bb 19> [local count: 23689]:
  # DEBUG BEGIN_STMT
  reply_ctrl_msg (0, 0);
  goto <bb 9>; [100.00%]

}



;; Function data_chan_rx_cb (data_chan_rx_cb, funcdef_no=9, decl_uid=5715, cgraph_uid=10, symbol_order=16)

Modification phase of node data_chan_rx_cb/16
data_chan_rx_cb (void * arg, const uint8 instance, uint8 chan_id, void * buf, uint32 size)
{
  struct ipc_sample_app * cb_arg_sample;
  sint8 err;
  long unsigned int _1;
  long unsigned int _2;
  sint8 * _3;
  long unsigned int _4;
  short unsigned int _5;
  int _6;
  int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  struct QueueDefinition * shm_event_rx.4_11;

  <bb 2> [local count: 119172]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(uintptr *)arg_13(D)];
  cb_arg_sample_14 = (struct ipc_sample_app *) _1;
  # DEBUG cb_arg_sample => cb_arg_sample_14
  # DEBUG BEGIN_STMT
  if (cb_arg_sample_14 != &app)
    goto <bb 4>; [70.00%]
  else
    goto <bb 3>; [30.00%]

  <bb 3> [local count: 35752]:
  if (size_15(D) > 32)
    goto <bb 4>; [67.00%]
  else
    goto <bb 5>; [33.00%]

  <bb 4> [local count: 107374]:

  <bb 10> [local count: 1073741824]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 11798]:
  # DEBUG BEGIN_STMT
  _2 = ipc_strlen (&sharpstr);
  _3 = buf_16(D) + _2;
  _4 = ipc_strtol (_3);
  _5 = (short unsigned int) _4;
  app.last_rx_no_msg = _5;
  # DEBUG BEGIN_STMT
  _6 = (int) chan_id_18(D);
  _9 = _5 & 1;
  _7 = _9 == 0 ? 1 : 2;
  if (_6 != _7)
    goto <bb 11>; [79.76%]
  else
    goto <bb 7>; [20.24%]

  <bb 11> [local count: 9410]:

  <bb 6> [local count: 94101256]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 94101256]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 2388]:
  # DEBUG BEGIN_STMT
  app.last_rx_ch = chan_id_18(D);
  # DEBUG BEGIN_STMT
  _8 ={v} app.rx_count;
  _10 = _8 + 1;
  app.rx_count ={v} _10;
  # DEBUG BEGIN_STMT
  err_23 = ipc_shm_release_buf (instance_21(D), chan_id_18(D), buf_16(D));
  # DEBUG err => err_23
  # DEBUG BEGIN_STMT
  if (err_23 != 0)
    goto <bb 12>; [67.00%]
  else
    goto <bb 9>; [33.00%]

  <bb 12> [local count: 1600]:

  <bb 8> [local count: 15999101]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 15999101]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 788]:
  # DEBUG BEGIN_STMT
  shm_event_rx.4_11 = shm_event_rx;
  xQueueGenericSend (shm_event_rx.4_11, 0B, 0, 0);
  return;

}



;; Function ctrl_chan_rx_cb (ctrl_chan_rx_cb, funcdef_no=10, decl_uid=5709, cgraph_uid=11, symbol_order=17)

Modification phase of node ctrl_chan_rx_cb/17
ctrl_chan_rx_cb (void * arg, const uint8 instance, uint8 chan_id, void * mem)
{
  struct ipc_sample_app * cb_arg_sample;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  sint8 * _4;
  long unsigned int _5;
  short unsigned int _6;

  <bb 2> [local count: 110099]:
  # DEBUG BEGIN_STMT
  _1 = MEM[(uintptr *)arg_8(D)];
  cb_arg_sample_9 = (struct ipc_sample_app *) _1;
  # DEBUG cb_arg_sample => cb_arg_sample_9
  # DEBUG BEGIN_STMT
  if (cb_arg_sample_9 != &app)
    goto <bb 6>; [70.00%]
  else
    goto <bb 3>; [30.00%]

  <bb 3> [local count: 33030]:
  _2 = ipc_strlen (mem_10(D));
  if (_2 > 32)
    goto <bb 6>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 6> [local count: 107374]:
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 16515]:
  if (chan_id_11(D) != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 8257]:
  if (instance_12(D) != 0)
    goto <bb 6>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 9> [local count: 1073741824]:

  <bb 8> [local count: 1073741824]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 2725]:
  # DEBUG BEGIN_STMT
  _3 = ipc_strlen (&send_buf);
  _4 = mem_10(D) + _3;
  _5 = ipc_strtol (_4);
  _6 = (short unsigned int) _5;
  app.expected_msgs = _6;
  # DEBUG BEGIN_STMT
  app.rx_count ={v} 0;
  # DEBUG BEGIN_STMT
  app.tx_count ={v} 0;
  return;

}



;; Function handle_error (handle_error, funcdef_no=13, decl_uid=5753, cgraph_uid=14, symbol_order=20) (executed once)

Modification phase of node handle_error/20
handle_error (sint8 error)
{
  <bb 2> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

}



;; Function prepare_demo (prepare_demo, funcdef_no=14, decl_uid=5751, cgraph_uid=15, symbol_order=21)

Modification phase of node prepare_demo/21
prepare_demo ()
{
  BaseType_t os_status;
  struct QueueDefinition * _1;

  <bb 2> [local count: 134621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = xQueueCreateCountingSemaphore (255, 0);
  shm_event_rx = _1;
  # DEBUG BEGIN_STMT
  os_status_6 = xTaskCreate (shm_demo, "sample", 256, 0B, 1, 0B);
  # DEBUG os_status => os_status_6
  # DEBUG BEGIN_STMT
  if (os_status_6 != 1)
    goto <bb 5>; [79.76%]
  else
    goto <bb 4>; [20.24%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG error => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 27247]:
  # DEBUG BEGIN_STMT
  vTaskStartScheduler ();
  return;

}



;; Function vApplicationMallocFailedHook (vApplicationMallocFailedHook, funcdef_no=15, decl_uid=6357, cgraph_uid=16, symbol_order=22) (executed once)

Modification phase of node vApplicationMallocFailedHook/22
vApplicationMallocFailedHook ()
{
  uint32_t ulNewBASEPRI;

  <bb 2> [local count: 107374]:
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
" : "=r" ulNewBASEPRI_2 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_2

  <bb 3> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

}



;; Function vApplicationStackOverflowHook (vApplicationStackOverflowHook, funcdef_no=16, decl_uid=6362, cgraph_uid=17, symbol_order=23) (executed once)

Modification phase of node vApplicationStackOverflowHook/23
vApplicationStackOverflowHook (struct tskTaskControlBlock * pxTask, char * pcTaskName)
{
  uint32_t ulNewBASEPRI;

  <bb 2> [local count: 107374]:
  # DEBUG BEGIN_STMT
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
" : "=r" ulNewBASEPRI_2 : "i" 16 : "memory");
  # DEBUG ulNewBASEPRI => ulNewBASEPRI_2

  <bb 3> [local count: 1073741824]:
  # DEBUG ulNewBASEPRI => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

}


