
IPA constant propagation start:
Determining dynamic type for call: err_16 = ipc_shm_init_a_channel (instance_1(D), chan_id_10, local_chan_shm_14, remote_chan_shm_15, _13);
  Starting walk at: err_16 = ipc_shm_init_a_channel (instance_1(D), chan_id_10, local_chan_shm_14, remote_chan_shm_15, _13);
  instance pointer: _13  Outer instance pointer: _13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = ipc_os_get_remote_shm (instance_1(D));
  Function call may change dynamic type:local_shm_2 = ipc_os_get_local_shm (instance_1(D));
  Function call may change dynamic type:err_16 = ipc_shm_init_a_channel (instance_1(D), chan_id_10, local_chan_shm_14, remote_chan_shm_15, _13);
Determining dynamic type for call: err_24 = ipc_buf_pool_init (instance_1(D), chan_id_3(D), pool_id_20, &mng_pool_addr, _23);
  Starting walk at: err_24 = ipc_buf_pool_init (instance_1(D), chan_id_3(D), pool_id_20, &mng_pool_addr, _23);
  instance pointer: &mng_pool_addr  Outer instance pointer: mng_pool_addr offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_15 = ipc_os_get_local_shm (instance_1(D));
  Function call may change dynamic type:err_24 = ipc_buf_pool_init (instance_1(D), chan_id_3(D), pool_id_20, &mng_pool_addr, _23);
Determining dynamic type for call: err_24 = ipc_buf_pool_init (instance_1(D), chan_id_3(D), pool_id_20, &mng_pool_addr, _23);
  Starting walk at: err_24 = ipc_buf_pool_init (instance_1(D), chan_id_3(D), pool_id_20, &mng_pool_addr, _23);
  instance pointer: _23  Outer instance pointer: _23 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_15 = ipc_os_get_local_shm (instance_1(D));
  Function call may change dynamic type:err_24 = ipc_buf_pool_init (instance_1(D), chan_id_3(D), pool_id_20, &mng_pool_addr, _23);
Determining dynamic type for call: err_12 = ipc_check_uchan_integrity (chan_11);
  Starting walk at: err_12 = ipc_check_uchan_integrity (chan_11);
  instance pointer: chan_11  Outer instance pointer: chan_11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipc_shm_is_remote_ready (instance_8(D));
Determining dynamic type for call: err_12 = ipc_shm_buf_tx (instance_5(D), buf_9(D), size_10(D), chan_8);
  Starting walk at: err_12 = ipc_shm_buf_tx (instance_5(D), buf_9(D), size_10(D), chan_8);
  instance pointer: buf_9(D)  Outer instance pointer: buf_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipc_shm_is_remote_ready (instance_5(D));
Determining dynamic type for call: err_12 = ipc_shm_buf_tx (instance_5(D), buf_9(D), size_10(D), chan_8);
  Starting walk at: err_12 = ipc_shm_buf_tx (instance_5(D), buf_9(D), size_10(D), chan_8);
  instance pointer: chan_8  Outer instance pointer: chan_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipc_shm_is_remote_ready (instance_5(D));
Determining dynamic type for call: err_15 = ipc_check_mchan_integrity (chan_13(D));
  Starting walk at: err_15 = ipc_check_mchan_integrity (chan_13(D));
  instance pointer: chan_13(D)  Outer instance pointer: chan_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_18 = find_pool_for_buf (chan_13(D), buf.20_1, 0, &bd.pool_id);
  Starting walk at: err_18 = find_pool_for_buf (chan_13(D), buf.20_1, 0, &bd.pool_id);
  instance pointer: chan_13(D)  Outer instance pointer: chan_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_15 = ipc_check_mchan_integrity (chan_13(D));
Determining dynamic type for call: err_18 = find_pool_for_buf (chan_13(D), buf.20_1, 0, &bd.pool_id);
  Starting walk at: err_18 = find_pool_for_buf (chan_13(D), buf.20_1, 0, &bd.pool_id);
  instance pointer: &bd.pool_id  Outer instance pointer: bd offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_15 = ipc_check_mchan_integrity (chan_13(D));
Determining dynamic type for call: err_20 = ipc_check_mchan_integrity (chan_17);
  Starting walk at: err_20 = ipc_check_mchan_integrity (chan_17);
  instance pointer: chan_17  Outer instance pointer: chan_17 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipc_shm_is_remote_ready (instance_14(D));
Determining dynamic type for call: err_22 = find_pool_for_buf (chan_17, buf.17_2, 1, &bd.pool_id);
  Starting walk at: err_22 = find_pool_for_buf (chan_17, buf.17_2, 1, &bd.pool_id);
  instance pointer: chan_17  Outer instance pointer: chan_17 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_20 = ipc_check_mchan_integrity (chan_17);
  Function call may change dynamic type:_1 = ipc_shm_is_remote_ready (instance_14(D));
Determining dynamic type for call: err_22 = find_pool_for_buf (chan_17, buf.17_2, 1, &bd.pool_id);
  Starting walk at: err_22 = find_pool_for_buf (chan_17, buf.17_2, 1, &bd.pool_id);
  instance pointer: &bd.pool_id  Outer instance pointer: bd offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_20 = ipc_check_mchan_integrity (chan_17);
  Function call may change dynamic type:_1 = ipc_shm_is_remote_ready (instance_14(D));
Determining dynamic type for call: err_18 = ipc_shm_init_instance (instance_id_8, _6);
  Starting walk at: err_18 = ipc_shm_init_instance (instance_id_8, _6);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_18 = ipc_shm_init_instance (instance_id_8, _6);
Determining dynamic type for call: _2 = ipc_check_mchan_integrity (chan_9);
  Starting walk at: _2 = ipc_check_mchan_integrity (chan_9);
  instance pointer: chan_9  Outer instance pointer: chan_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = ipc_shm_is_remote_ready (instance_6(D));
Determining dynamic type for call: buf_addr_13 = ipc_shm_acquire_buf_from_pool (instance_6(D), mem_size_10(D), chan_9);
  Starting walk at: buf_addr_13 = ipc_shm_acquire_buf_from_pool (instance_6(D), mem_size_10(D), chan_9);
  instance pointer: chan_9  Outer instance pointer: chan_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = ipc_check_mchan_integrity (chan_9);
  Function call may change dynamic type:_1 = ipc_shm_is_remote_ready (instance_6(D));
Determining dynamic type for call: err_23 = ipc_shm_init_instance_priv (instance_20(D), cfg_21(D));
  Starting walk at: err_23 = ipc_shm_init_instance_priv (instance_20(D), cfg_21(D));
  instance pointer: cfg_21(D)  Outer instance pointer: cfg_21(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_16 = ipc_shm_init_channels.isra.0 (instance_6(D), _20);
  Starting walk at: err_16 = ipc_shm_init_channels.isra.0 (instance_6(D), _20);
  instance pointer: _20  Outer instance pointer: cfg_8(D) offset: 352 (bits) vtbl reference: 
  Function call may change dynamic type:err_14 = ipc_os_init (instance_6(D), cfg_8(D), ipc_shm_rx);
  Function call may change dynamic type:err_12 = ipc_hw_init (instance_6(D), cfg_8(D));
Determining dynamic type for call: ipc_shm_free_managed_channel (mchan_10);
  Starting walk at: ipc_shm_free_managed_channel (mchan_10);
  instance pointer: mchan_10  Outer instance pointer: &ipc_shm_priv_data[_1].channels[_2].ch.mng offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_20 = unmanaged_channel_init (instance_11(D), chan_id_12(D), local_shm_17(D), remote_shm_18(D), _8);
  Starting walk at: err_20 = unmanaged_channel_init (instance_11(D), chan_id_12(D), local_shm_17(D), remote_shm_18(D), _8);
  instance pointer: _8  Outer instance pointer: cfg_15(D) offset: 32 (bits) vtbl reference: 
Determining dynamic type for call: err_22 = managed_channel_init (instance_11(D), chan_id_12(D), local_shm_17(D), remote_shm_18(D), _6);
  Starting walk at: err_22 = managed_channel_init (instance_11(D), chan_id_12(D), local_shm_17(D), remote_shm_18(D), _6);
  instance pointer: _6  Outer instance pointer: cfg_15(D) offset: 32 (bits) vtbl reference: 
Determining dynamic type for call: total_bufs_13 = ipc_get_total_buf_per_chan (instance_8(D), chan_id_9(D), cfg_11(D));
  Starting walk at: total_bufs_13 = ipc_get_total_buf_per_chan (instance_8(D), chan_id_9(D), cfg_11(D));
  instance pointer: cfg_11(D)  Outer instance pointer: cfg_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_25 = managed_pools_init.isra.0 (instance_8(D), chan_id_9(D), local_shm_17(D), remote_shm_19(D), _27);
  Starting walk at: err_25 = managed_pools_init.isra.0 (instance_8(D), chan_id_9(D), local_shm_17(D), remote_shm_19(D), _27);
  instance pointer: _27  Outer instance pointer: cfg_11(D) offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:err_22 = ipc_queue_init (_4, queue_data);
  Function call may change dynamic type:total_bufs_13 = ipc_get_total_buf_per_chan (instance_8(D), chan_id_9(D), cfg_11(D));
Determining dynamic type for call: err_29 = ipc_buffer_populate (instance_12(D), mng_pool_23(D), pool_id_14(D), pool_15, cfg_17(D));
  Starting walk at: err_29 = ipc_buffer_populate (instance_12(D), mng_pool_23(D), pool_id_14(D), pool_15, cfg_17(D));
  instance pointer: mng_pool_23(D)  Outer instance pointer: mng_pool_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_27 = ipc_queue_init (_8, queue_data);
Determining dynamic type for call: err_29 = ipc_buffer_populate (instance_12(D), mng_pool_23(D), pool_id_14(D), pool_15, cfg_17(D));
  Starting walk at: err_29 = ipc_buffer_populate (instance_12(D), mng_pool_23(D), pool_id_14(D), pool_15, cfg_17(D));
  instance pointer: pool_15  Outer instance pointer: &MEM[(struct ipc_managed_channel *)&ipc_shm_priv_data][_1].channels[_2].ch.mng.pools[_3] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_27 = ipc_queue_init (_8, queue_data);
Determining dynamic type for call: err_29 = ipc_buffer_populate (instance_12(D), mng_pool_23(D), pool_id_14(D), pool_15, cfg_17(D));
  Starting walk at: err_29 = ipc_buffer_populate (instance_12(D), mng_pool_23(D), pool_id_14(D), pool_15, cfg_17(D));
  instance pointer: cfg_17(D)  Outer instance pointer: cfg_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_27 = ipc_queue_init (_8, queue_data);
Determining dynamic type for call: _25 (_26, instance_35(D), _27, buf_addr.2_28, _29);
  Starting walk at: _25 (_26, instance_35(D), _27, buf_addr.2_28, _29);
  instance pointer: _26  Outer instance pointer: _26 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_22 = ipc_os_get_remote_shm (instance_35(D));
  Function call may change dynamic type:_19 = ipc_os_get_remote_shm (instance_35(D));
  Function call may change dynamic type:result_41 = ipc_queue_pop (_12, &bd);
  Function call may change dynamic type:_19 = ipc_os_get_remote_shm (instance_35(D));
  Function call may change dynamic type:result_41 = ipc_queue_pop (_12, &bd);
  Function call may change dynamic type:_22 = ipc_os_get_remote_shm (instance_35(D));
  Function call may change dynamic type:_25 (_26, instance_35(D), _27, buf_addr.2_28, _29);
Determining dynamic type for call: _25 (_26, instance_35(D), _27, buf_addr.2_28, _29);
  Starting walk at: _25 (_26, instance_35(D), _27, buf_addr.2_28, _29);
  instance pointer: buf_addr.2_28  Outer instance pointer: buf_addr.2_28 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_22 = ipc_os_get_remote_shm (instance_35(D));
  Function call may change dynamic type:_19 = ipc_os_get_remote_shm (instance_35(D));
  Function call may change dynamic type:result_41 = ipc_queue_pop (_12, &bd);
  Function call may change dynamic type:_19 = ipc_os_get_remote_shm (instance_35(D));
  Function call may change dynamic type:result_41 = ipc_queue_pop (_12, &bd);
  Function call may change dynamic type:_22 = ipc_os_get_remote_shm (instance_35(D));
  Function call may change dynamic type:_25 (_26, instance_35(D), _27, buf_addr.2_28, _29);
Determining dynamic type for call: _4 = ipc_check_uchan_integrity (uchan_37);
  Starting walk at: _4 = ipc_check_uchan_integrity (uchan_37);
  instance pointer: uchan_37  Outer instance pointer: &MEM[(struct ipc_shm_channel *)&ipc_shm_priv_data][_1].channels[_2].ch.umng offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 (_9, instance_35(D), _10, _11);
  Starting walk at: _8 (_9, instance_35(D), _10, _11);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 (_9, instance_35(D), _10, _11);
  Starting walk at: _8 (_9, instance_35(D), _10, _11);
  instance pointer: _11  Outer instance pointer: &_5->mem offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_3 = ipc_check_mchan_integrity.part.0 (mchan_8(D));
  Starting walk at: err_3 = ipc_check_mchan_integrity.part.0 (mchan_8(D));
  instance pointer: mchan_8(D)  Outer instance pointer: mchan_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = ipc_queue_check_integrity (_1);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  ipc_shm_free_instance.part.0/64:
    callsite  ipc_shm_free_instance.part.0/64 -> ipc_shm_free_channel/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_check_mchan_integrity.part.0/63:
  Jump functions of caller  ipc_shm_free_channel.part.0/62:
  Jump functions of caller  ipc_shm_init_channels.isra.0/61:
    callsite  ipc_shm_init_channels.isra.0/61 -> get_chan_memmap_size/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_shm_init_channels.isra.0/61 -> ipc_shm_init_a_channel/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  managed_pools_init.isra.0/60:
    callsite  managed_pools_init.isra.0/60 -> ipc_buf_pool_init/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_instance_is_free.part.0/57:
  Jump functions of caller  ipc_os_poll_channels/54:
  Jump functions of caller  ipc_hw_irq_notify/53:
  Jump functions of caller  ipc_queue_check_integrity/52:
  Jump functions of caller  ipc_hw_irq_disable/51:
  Jump functions of caller  ipc_queue_free/50:
  Jump functions of caller  ipc_queue_push/49:
  Jump functions of caller  ipc_queue_init/48:
  Jump functions of caller  ipc_os_get_local_shm/47:
  Jump functions of caller  ipc_os_get_remote_shm/46:
  Jump functions of caller  ipc_queue_pop/45:
  Jump functions of caller  ipc_hw_flush_cache_remote/44:
  Jump functions of caller  ipc_os_free/43:
  Jump functions of caller  ipc_hw_free/42:
  Jump functions of caller  ipc_os_init/41:
  Jump functions of caller  ipc_hw_init/40:
  Jump functions of caller  ipc_hw_flush_cache_local/39:
  Jump functions of caller  ipc_hw_irq_enable/38:
  Jump functions of caller  ipc_hw_irq_clear/37:
  Jump functions of caller  ipc_shm_poll_channels/36:
    callsite  ipc_shm_poll_channels/36 -> ipc_instance_is_free/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_is_remote_ready/35:
    callsite  ipc_shm_is_remote_ready/35 -> ipc_instance_is_free/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_unmanaged_tx/34:
    callsite  ipc_shm_unmanaged_tx/34 -> ipc_check_uchan_integrity/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_shm_unmanaged_tx/34 -> get_unmanaged_chan/4 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_shm_unmanaged_tx/34 -> ipc_shm_is_remote_ready/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_unmanaged_acquire/33:
    callsite  ipc_shm_unmanaged_acquire/33 -> get_unmanaged_chan/4 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_shm_unmanaged_acquire/33 -> ipc_instance_is_free/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_tx/32:
    callsite  ipc_shm_tx/32 -> ipc_shm_buf_tx/31 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_shm_tx/32 -> get_managed_chan/3 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_shm_tx/32 -> ipc_shm_is_remote_ready/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_buf_tx/31:
    callsite  ipc_shm_buf_tx/31 -> find_pool_for_buf/29 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipc_shm_buf_tx/31 -> ipc_check_mchan_integrity/7 : 
       param 0: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_shm_release_buf/30:
    callsite  ipc_shm_release_buf/30 -> find_pool_for_buf/29 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  [1, -1]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  ipc_shm_release_buf/30 -> ipc_check_mchan_integrity/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_shm_release_buf/30 -> get_managed_chan/3 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_shm_release_buf/30 -> ipc_shm_is_remote_ready/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  find_pool_for_buf/29:
  Jump functions of caller  ipc_shm_init/28:
    callsite  ipc_shm_init/28 -> ipc_shm_init_instance/23 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_shm_init/28 -> ipc_instance_is_free/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_acquire_buf/27:
    callsite  ipc_shm_acquire_buf/27 -> ipc_shm_acquire_buf_from_pool/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_shm_acquire_buf/27 -> ipc_check_mchan_integrity/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_shm_acquire_buf/27 -> get_managed_chan/3 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_shm_acquire_buf/27 -> ipc_shm_is_remote_ready/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_acquire_buf_from_pool/26:
  Jump functions of caller  ipc_shm_free/25:
    callsite  ipc_shm_free/25 -> ipc_shm_free_instance/24 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  ipc_shm_free_instance/24:
    callsite  ipc_shm_free_instance/24 -> ipc_shm_free_instance.part.0/64 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_shm_free_instance/24 -> ipc_instance_is_free/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_init_instance/23:
    callsite  ipc_shm_init_instance/23 -> ipc_shm_free_channel/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_shm_init_instance/23 -> ipc_shm_init_instance_priv/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ipc_shm_init_instance/23 -> ipc_instance_is_free/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ipc_shm_init_instance_priv/22:
    callsite  ipc_shm_init_instance_priv/22 -> ipc_shm_init_channels.isra.0/61 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  get_chan_memmap_size/20:
  Jump functions of caller  ipc_shm_free_channel/19:
    callsite  ipc_shm_free_channel/19 -> ipc_shm_free_channel.part.0/62 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ipc_shm_free_channel/19 -> ipc_shm_free_managed_channel/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  ipc_shm_free_managed_channel/18:
  Jump functions of caller  ipc_shm_init_a_channel/17:
    callsite  ipc_shm_init_a_channel/17 -> unmanaged_channel_init/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: ANCESTOR: 4, offset 32
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  ipc_shm_init_a_channel/17 -> managed_channel_init/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: ANCESTOR: 4, offset 32
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  unmanaged_channel_init/16:
  Jump functions of caller  managed_channel_init/15:
    callsite  managed_channel_init/15 -> managed_pools_init.isra.0/60 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  managed_channel_init/15 -> ipc_get_total_buf_per_chan/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_get_total_buf_per_chan/13:
  Jump functions of caller  ipc_buf_pool_init/12:
    callsite  ipc_buf_pool_init/12 -> ipc_buffer_populate/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_buffer_populate/11:
  Jump functions of caller  ipc_shm_rx/10:
    callsite  ipc_shm_rx/10 -> ipc_channel_rx/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_instance_is_free/9:
    callsite  ipc_instance_is_free/9 -> ipc_instance_is_free.part.0/57 : 
  Jump functions of caller  ipc_channel_rx/8:
    callsite  ipc_channel_rx/8 -> ipc_check_uchan_integrity/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    indirect simple callsite, calling param -1, offset 0, for stmt _25 (_26, instance_35(D), _27, buf_addr.2_28, _29);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _8 (_9, instance_35(D), _10, _11);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  ipc_check_mchan_integrity/7:
    callsite  ipc_check_mchan_integrity/7 -> ipc_check_mchan_integrity.part.0/63 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ipc_check_uchan_integrity/5:
  Jump functions of caller  get_unmanaged_chan/4:
  Jump functions of caller  get_managed_chan/3:

 Propagating constants:

Not considering ipc_shm_poll_channels for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_is_remote_ready for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_unmanaged_tx for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_unmanaged_acquire for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_tx for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_release_buf for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_init for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_acquire_buf for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_free for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_free_instance for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_init_instance for cloning; -fipa-cp-clone disabled.
Not considering ipc_shm_rx for cloning; -fipa-cp-clone disabled.

overall_size: 932, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: ipc_shm_free_instance.part.0/64:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ipc_check_mchan_integrity.part.0/63:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ipc_shm_free_channel.part.0/62:
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
  Node: ipc_shm_init_channels.isra.0/61:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct ipc_shm_channel_cfg * const * ~[0B, 0B]
        AGGS VARIABLE
  Node: managed_pools_init.isra.0/60:
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
         struct ipc_shm_pool_cfg * const * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipc_instance_is_free.part.0/57:
  Node: ipc_shm_poll_channels/36:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_shm_is_remote_ready/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_shm_unmanaged_tx/34:
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
  Node: ipc_shm_unmanaged_acquire/33:
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
  Node: ipc_shm_tx/32:
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
  Node: ipc_shm_buf_tx/31:
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
  Node: ipc_shm_release_buf/30:
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
  Node: find_pool_for_buf/29:
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
    param [2]: 1 [loc_time: 24, loc_size: 17, prop_time: 0, prop_size: 0]
               0 [loc_time: 24, loc_size: 17, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         uint8 [0, 1]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint16 * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipc_shm_init/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_shm_acquire_buf/27:
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
  Node: ipc_shm_acquire_buf_from_pool/26:
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
  Node: ipc_shm_free/25:
  Node: ipc_shm_free_instance/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: ipc_shm_init_instance/23:
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
  Node: ipc_shm_init_instance_priv/22:
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
  Node: get_chan_memmap_size/20:
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
  Node: ipc_shm_free_channel/19:
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
  Node: ipc_shm_free_managed_channel/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct ipc_managed_channel * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipc_shm_init_a_channel/17:
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
  Node: unmanaged_channel_init/16:
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
         const struct ipc_shm_unmanaged_cfg * ~[0B, 0B]
        AGGS VARIABLE
  Node: managed_channel_init/15:
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
         const struct ipc_shm_managed_cfg * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipc_get_total_buf_per_chan/13:
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
         const struct ipc_shm_managed_cfg * ~[0B, 0B]
        AGGS VARIABLE
  Node: ipc_buf_pool_init/12:
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
         Bits: value = 0x0, mask = 0xfffffffc
         struct ipc_shm_pool_addr * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ipc_buffer_populate/11:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct ipc_shm_pool_addr * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct ipc_shm_pool * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ipc_shm_rx/10:
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
  Node: ipc_instance_is_free/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ipc_channel_rx/8:
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
  Node: ipc_check_mchan_integrity/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ipc_check_uchan_integrity/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: get_unmanaged_chan/4:
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
  Node: get_managed_chan/3:
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

IPA decision stage:

Propagated bits info for function find_pool_for_buf/29:
 param 2: value = 0x0, mask = 0x1
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function ipc_shm_free_managed_channel/18:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function ipc_buf_pool_init/12:
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function ipc_buffer_populate/11:
 param 1: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

ipc_shm_free_instance.part.0/64 (ipc_shm_free_instance.part.0) @070bf8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: ipc_shm_free_instance/24 (118111600 (estimated locally),0.50 per call) 
  Calls: ipc_shm_free_channel/19 (955630223 (estimated locally),8.09 per call) ipc_hw_flush_cache_local/39 (118111601 (estimated locally),1.00 per call) ipc_hw_irq_disable/51 (118111601 (estimated locally),1.00 per call) ipc_os_free/43 (118111601 (estimated locally),1.00 per call) ipc_hw_free/42 (118111601 (estimated locally),1.00 per call) 
ipc_check_mchan_integrity.part.0/63 (ipc_check_mchan_integrity.part.0) @070bf000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: ipc_check_mchan_integrity/7 (118111600 (estimated locally),0.98 per call) 
  Calls: ipc_queue_check_integrity/52 (955630223 (estimated locally),8.09 per call) 
ipc_shm_free_channel.part.0/62 (ipc_shm_free_channel.part.0) @07095700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: ipc_shm_free_channel/19 (182536112 (estimated locally),0.17 per call) 
  Calls: 
ipc_shm_init_channels.isra.0/61 (ipc_shm_init_channels.isra.0) @06f80b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:88896196 (estimated locally) body local optimize_size
  Called by: ipc_shm_init_instance_priv/22 (177167401 (estimated locally),0.17 per call) 
  Calls: get_chan_memmap_size/20 (512712222 (estimated locally),5.77 per call) ipc_shm_init_a_channel/17 (542552617 (estimated locally),6.10 per call) ipc_os_get_remote_shm/46 (88896196 (estimated locally),1.00 per call) ipc_os_get_local_shm/47 (88896196 (estimated locally),1.00 per call) 
managed_pools_init.isra.0/60 (managed_pools_init.isra.0) @06e63c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:117207686 (estimated locally) body local optimize_size
  Called by: managed_channel_init/15 (340232277 (estimated locally),0.32 per call) 
  Calls: ipc_buf_pool_init/12 (1014686023 (estimated locally),8.66 per call) ipc_os_get_local_shm/47 (117207686 (estimated locally),1.00 per call) 
ipc_instance_is_free.part.0/57 (ipc_instance_is_free.part.0) @06f81620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: ipc_instance_is_free/9 (697932184 (estimated locally),0.65 per call) 
  Calls: 
ipc_os_poll_channels/54 (ipc_os_poll_channels) @06f418c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_poll_channels/36 (327972293 (estimated locally),0.31 per call) 
  Calls: 
ipc_hw_irq_notify/53 (ipc_hw_irq_notify) @06f412a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_unmanaged_tx/34 (344227047 (estimated locally),0.32 per call) ipc_shm_buf_tx/31 (38587060 (estimated locally),0.04 per call) 
  Calls: 
ipc_queue_check_integrity/52 (ipc_queue_check_integrity) @06f24c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_check_mchan_integrity/7 (120522041 (estimated locally),1.00 per call) ipc_check_mchan_integrity.part.0/63 (955630223 (estimated locally),8.09 per call) 
  Calls: 
ipc_hw_irq_disable/51 (ipc_hw_irq_disable) @06f24700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_free_instance.part.0/64 (118111601 (estimated locally),1.00 per call) 
  Calls: 
ipc_queue_free/50 (ipc_queue_free) @06f24540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_free_managed_channel/18 (373688027 (estimated locally),1.50 per call) ipc_shm_free_managed_channel/18 (118111600 (estimated locally),0.47 per call) 
  Calls: 
ipc_queue_push/49 (ipc_queue_push) @06f240e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_release_buf/30 (111618374 (estimated locally),0.10 per call) ipc_shm_buf_tx/31 (116930485 (estimated locally),0.11 per call) ipc_buffer_populate/11 (1014686023 (estimated locally),8.66 per call) 
  Calls: 
ipc_queue_init/48 (ipc_queue_init) @06f0ab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: managed_channel_init/15 (1031006900 (estimated locally),0.96 per call) ipc_buf_pool_init/12 (1031006900 (estimated locally),0.96 per call) 
  Calls: 
ipc_os_get_local_shm/47 (ipc_os_get_local_shm) @06f0a8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_init_channels.isra.0/61 (88896196 (estimated locally),1.00 per call) managed_pools_init.isra.0/60 (117207686 (estimated locally),1.00 per call) ipc_buffer_populate/11 (117207686 (estimated locally),1.00 per call) ipc_shm_acquire_buf_from_pool/26 (14026942 (estimated locally),0.16 per call) ipc_shm_acquire_buf_from_pool/26 (42505885 (estimated locally),0.49 per call) 
  Calls: 
ipc_os_get_remote_shm/46 (ipc_os_get_remote_shm) @06f0a620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_poll_channels/36 (354334802 (estimated locally),0.33 per call) ipc_shm_is_remote_ready/35 (1031006900 (estimated locally),0.96 per call) ipc_shm_init_channels.isra.0/61 (88896196 (estimated locally),1.00 per call) ipc_channel_rx/8 (316429836 (estimated locally),1.82 per call) ipc_channel_rx/8 (958878293 (estimated locally),5.51 per call) 
  Calls: 
ipc_queue_pop/45 (ipc_queue_pop) @06f0a540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_acquire_buf_from_pool/26 (507343012 (estimated locally),5.83 per call) ipc_channel_rx/8 (1014686025 (estimated locally),5.83 per call) 
  Calls: 
ipc_hw_flush_cache_remote/44 (ipc_hw_flush_cache_remote) @06f0a380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_poll_channels/36 (354334802 (estimated locally),0.33 per call) ipc_shm_is_remote_ready/35 (1031006900 (estimated locally),0.96 per call) ipc_shm_rx/10 (118111600 (estimated locally),8.35 per call) 
  Calls: 
ipc_os_free/43 (ipc_os_free) @06f0a1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_free_instance.part.0/64 (118111601 (estimated locally),1.00 per call) ipc_shm_init_instance_priv/22 (58465242 (estimated locally),0.05 per call) 
  Calls: 
ipc_hw_free/42 (ipc_hw_free) @06f0a0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_free_instance.part.0/64 (118111601 (estimated locally),1.00 per call) ipc_shm_init_instance_priv/22 (58465242 (estimated locally),0.05 per call) ipc_shm_init_instance_priv/22 (177167401 (estimated locally),0.17 per call) 
  Calls: 
ipc_os_init/41 (ipc_os_init) @06f0a000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_init_instance_priv/22 (354334802 (estimated locally),0.33 per call) 
  Calls: 
ipc_hw_init/40 (ipc_hw_init) @06ee0620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_init_instance_priv/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ipc_hw_flush_cache_local/39 (ipc_hw_flush_cache_local) @06ee0ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_unmanaged_tx/34 (344227047 (estimated locally),0.32 per call) ipc_shm_release_buf/30 (111618374 (estimated locally),0.10 per call) ipc_shm_free_instance.part.0/64 (118111601 (estimated locally),1.00 per call) ipc_shm_init_instance/23 (58174370 (estimated locally),0.29 per call) ipc_shm_buf_tx/31 (38587060 (estimated locally),0.04 per call) 
  Calls: 
ipc_hw_irq_enable/38 (ipc_hw_irq_enable) @06ee0e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_init_instance/23 (58174370 (estimated locally),0.29 per call) 
  Calls: 
ipc_hw_irq_clear/37 (ipc_hw_irq_clear) @06ee0d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ipc_shm_init_instance/23 (58174370 (estimated locally),0.29 per call) 
  Calls: 
ipc_shm_poll_channels/36 (ipc_shm_poll_channels) @06ee07e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_os_poll_channels/54 (327972293 (estimated locally),0.31 per call) ipc_os_get_remote_shm/46 (354334802 (estimated locally),0.33 per call) ipc_hw_flush_cache_remote/44 (354334802 (estimated locally),0.33 per call) ipc_instance_is_free/9 (1073741824 (estimated locally),1.00 per call) 
ipc_shm_is_remote_ready/35 (ipc_shm_is_remote_ready) @06ee0540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: ipc_shm_unmanaged_tx/34 (1073741824 (estimated locally),1.00 per call) ipc_shm_tx/32 (1073741824 (estimated locally),1.00 per call) ipc_shm_release_buf/30 (1073741824 (estimated locally),1.00 per call) ipc_shm_acquire_buf/27 (1073741823 (estimated locally),1.00 per call) 
  Calls: ipc_os_get_remote_shm/46 (1031006900 (estimated locally),0.96 per call) ipc_hw_flush_cache_remote/44 (1031006900 (estimated locally),0.96 per call) ipc_instance_is_free/9 (1073741824 (estimated locally),1.00 per call) 
ipc_shm_unmanaged_tx/34 (ipc_shm_unmanaged_tx) @06ee02a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_hw_irq_notify/53 (344227047 (estimated locally),0.32 per call) ipc_hw_flush_cache_local/39 (344227047 (estimated locally),0.32 per call) ipc_check_uchan_integrity/5 (1043112264 (estimated locally),0.97 per call) get_unmanaged_chan/4 (1052266988 (estimated locally),0.98 per call) ipc_shm_is_remote_ready/35 (1073741824 (estimated locally),1.00 per call) 
ipc_shm_unmanaged_acquire/33 (ipc_shm_unmanaged_acquire) @06ee0000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: get_unmanaged_chan/4 (762356696 (estimated locally),0.71 per call) ipc_instance_is_free/9 (1073741824 (estimated locally),1.00 per call) 
ipc_shm_tx/32 (ipc_shm_tx) @06ed1540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_shm_buf_tx/31 (992882505 (estimated locally),0.92 per call) get_managed_chan/3 (1052266988 (estimated locally),0.98 per call) ipc_shm_is_remote_ready/35 (1073741824 (estimated locally),1.00 per call) 
ipc_shm_buf_tx/31 (ipc_shm_buf_tx) @06ed1ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_tx/32 (992882505 (estimated locally),0.92 per call) 
  Calls: ipc_hw_irq_notify/53 (38587060 (estimated locally),0.04 per call) ipc_hw_flush_cache_local/39 (38587060 (estimated locally),0.04 per call) ipc_queue_push/49 (116930485 (estimated locally),0.11 per call) find_pool_for_buf/29 (354334802 (estimated locally),0.33 per call) ipc_check_mchan_integrity/7 (1073741824 (estimated locally),1.00 per call) 
ipc_shm_release_buf/30 (ipc_shm_release_buf) @06ed1c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_hw_flush_cache_local/39 (111618374 (estimated locally),0.10 per call) ipc_queue_push/49 (111618374 (estimated locally),0.10 per call) find_pool_for_buf/29 (338237496 (estimated locally),0.32 per call) ipc_check_mchan_integrity/7 (1024962110 (estimated locally),0.95 per call) get_managed_chan/3 (1052266988 (estimated locally),0.98 per call) ipc_shm_is_remote_ready/35 (1073741824 (estimated locally),1.00 per call) 
find_pool_for_buf/29 (find_pool_for_buf) @06ed19a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:86959666 (estimated locally) body local optimize_size
  Called by: ipc_shm_release_buf/30 (338237496 (estimated locally),0.32 per call) ipc_shm_buf_tx/31 (354334802 (estimated locally),0.33 per call) 
  Calls: 
ipc_shm_init/28 (ipc_shm_init) @06ed1700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:91197479 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_shm_init_instance/23 (507343012 (estimated locally),5.56 per call) ipc_instance_is_free/9 (1014686025 (estimated locally),11.13 per call) 
ipc_shm_acquire_buf/27 (ipc_shm_acquire_buf) @06ed1460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_shm_acquire_buf_from_pool/26 (40925670 (estimated locally),0.04 per call) ipc_check_mchan_integrity/7 (124017180 (estimated locally),0.12 per call) get_managed_chan/3 (536870911 (estimated locally),0.50 per call) ipc_shm_is_remote_ready/35 (1073741823 (estimated locally),1.00 per call) 
ipc_shm_acquire_buf_from_pool/26 (ipc_shm_acquire_buf_from_pool) @06ed11c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:86959666 (estimated locally) body local optimize_size
  Called by: ipc_shm_acquire_buf/27 (40925670 (estimated locally),0.04 per call) 
  Calls: ipc_os_get_local_shm/47 (14026942 (estimated locally),0.16 per call) ipc_os_get_local_shm/47 (42505885 (estimated locally),0.49 per call) ipc_queue_pop/45 (507343012 (estimated locally),5.83 per call) 
ipc_shm_free/25 (ipc_shm_free) @06eb4d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:536870913 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_shm_free_instance/24 (536870913 (estimated locally),1.00 per call) 
ipc_shm_free_instance/24 (ipc_shm_free_instance) @06eb4ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:236223200 (estimated locally) body optimize_size
  Called by: ipc_shm_free/25 (536870913 (estimated locally),1.00 per call) 
  Calls: ipc_shm_free_instance.part.0/64 (118111600 (estimated locally),0.50 per call) ipc_instance_is_free/9 (236223200 (estimated locally),1.00 per call) 
ipc_shm_init_instance/23 (ipc_shm_init_instance) @06eb4c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: available
  Function flags: count:200792109 (estimated locally) body optimize_size
  Called by: ipc_shm_init/28 (507343012 (estimated locally),5.56 per call) 
  Calls: ipc_hw_flush_cache_local/39 (58174370 (estimated locally),0.29 per call) ipc_hw_irq_enable/38 (58174370 (estimated locally),0.29 per call) ipc_hw_irq_clear/37 (58174370 (estimated locally),0.29 per call) ipc_shm_free_channel/19 (510975480 (estimated locally),2.54 per call) ipc_shm_init_instance_priv/22 (176285970 (estimated locally),0.88 per call) ipc_instance_is_free/9 (200792109 (estimated locally),1.00 per call) 
ipc_shm_init_instance_priv/22 (ipc_shm_init_instance_priv) @06eb49a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)ipc_shm_rx/10 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_init_instance/23 (176285970 (estimated locally),0.88 per call) 
  Calls: ipc_hw_free/42 (58465242 (estimated locally),0.05 per call) ipc_os_free/43 (58465242 (estimated locally),0.05 per call) ipc_shm_init_channels.isra.0/61 (177167401 (estimated locally),0.17 per call) ipc_hw_free/42 (177167401 (estimated locally),0.17 per call) ipc_os_init/41 (354334802 (estimated locally),0.33 per call) ipc_hw_init/40 (1073741824 (estimated locally),1.00 per call) 
get_chan_memmap_size/20 (get_chan_memmap_size) @06eb4460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:178956970 (estimated locally) body local optimize_size
  Called by: ipc_shm_init_channels.isra.0/61 (512712222 (estimated locally),5.77 per call) 
  Calls: 
ipc_shm_free_channel/19 (ipc_shm_free_channel) @06eb41c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (addr)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_free_instance.part.0/64 (955630223 (estimated locally),8.09 per call) ipc_shm_init_instance/23 (510975480 (estimated locally),2.54 per call) 
  Calls: ipc_shm_free_channel.part.0/62 (182536112 (estimated locally),0.17 per call) ipc_shm_free_managed_channel/18 (287064877 (estimated locally),0.27 per call) 
ipc_shm_free_managed_channel/18 (ipc_shm_free_managed_channel) @06ea3ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:249399473 (estimated locally) body local optimize_size
  Called by: ipc_shm_free_channel/19 (287064877 (estimated locally),0.27 per call) 
  Calls: ipc_queue_free/50 (373688027 (estimated locally),1.50 per call) ipc_queue_free/50 (118111600 (estimated locally),0.47 per call) 
ipc_shm_init_a_channel/17 (ipc_shm_init_a_channel) @06ea3c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_init_channels.isra.0/61 (542552617 (estimated locally),6.10 per call) 
  Calls: unmanaged_channel_init/16 (507430489 (estimated locally),0.47 per call) managed_channel_init/15 (522939853 (estimated locally),0.49 per call) 
unmanaged_channel_init/16 (unmanaged_channel_init) @06ea39a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_init_a_channel/17 (507430489 (estimated locally),0.47 per call) 
  Calls: 
managed_channel_init/15 (managed_channel_init) @06ea3700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (addr)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_init_a_channel/17 (522939853 (estimated locally),0.49 per call) 
  Calls: managed_pools_init.isra.0/60 (340232277 (estimated locally),0.32 per call) ipc_queue_init/48 (1031006900 (estimated locally),0.96 per call) ipc_get_total_buf_per_chan/13 (1073741824 (estimated locally),1.00 per call) 
ipc_get_total_buf_per_chan/13 (ipc_get_total_buf_per_chan) @06ea31c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)
  Referring: 
  Availability: local
  Function flags: count:227268940 (estimated locally) body local optimize_size
  Called by: managed_channel_init/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ipc_buf_pool_init/12 (ipc_buf_pool_init) @06e82ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (addr)ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (write)ipc_shm_priv_data/1 (addr)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: managed_pools_init.isra.0/60 (1014686023 (estimated locally),8.66 per call) 
  Calls: ipc_buffer_populate/11 (340232277 (estimated locally),0.32 per call) ipc_queue_init/48 (1031006900 (estimated locally),0.96 per call) 
ipc_buffer_populate/11 (ipc_buffer_populate) @06e82c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:117207686 (estimated locally) body local optimize_size
  Called by: ipc_buf_pool_init/12 (340232277 (estimated locally),0.32 per call) 
  Calls: ipc_queue_push/49 (1014686023 (estimated locally),8.66 per call) ipc_os_get_local_shm/47 (117207686 (estimated locally),1.00 per call) 
ipc_shm_rx/10 (ipc_shm_rx) @06e829a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: ipc_shm_priv_data/1 (read)
  Referring: ipc_shm_init_instance_priv/22 (addr)
  Availability: available
  Function flags: count:14148526 (estimated locally) body optimize_size
  Called by: 
  Calls: ipc_channel_rx/8 (955630224 (estimated locally),67.54 per call) ipc_hw_flush_cache_remote/44 (118111600 (estimated locally),8.35 per call) 
ipc_instance_is_free/9 (ipc_instance_is_free) @06e82700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_poll_channels/36 (1073741824 (estimated locally),1.00 per call) ipc_shm_is_remote_ready/35 (1073741824 (estimated locally),1.00 per call) ipc_shm_unmanaged_acquire/33 (1073741824 (estimated locally),1.00 per call) ipc_shm_init/28 (1014686025 (estimated locally),11.13 per call) ipc_shm_free_instance/24 (236223200 (estimated locally),1.00 per call) ipc_shm_init_instance/23 (200792109 (estimated locally),1.00 per call) 
  Calls: ipc_instance_is_free.part.0/57 (697932184 (estimated locally),0.65 per call) 
ipc_channel_rx/8 (ipc_channel_rx) @06e82460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (addr)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (addr)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (read)
  Referring: 
  Availability: local
  Function flags: count:174035658 (estimated locally) body local optimize_size
  Called by: ipc_shm_rx/10 (955630224 (estimated locally),67.54 per call) 
  Calls: ipc_os_get_remote_shm/46 (316429836 (estimated locally),1.82 per call) ipc_os_get_remote_shm/46 (958878293 (estimated locally),5.51 per call) ipc_queue_pop/45 (1014686025 (estimated locally),5.83 per call) ipc_check_uchan_integrity/5 (59172124 (estimated locally),0.34 per call) 
   Indirect call(158214918 (estimated locally),0.91 per call) 
   Indirect call(19526801 (estimated locally),0.11 per call) 
ipc_check_mchan_integrity/7 (ipc_check_mchan_integrity) @06e821c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:120522041 (estimated locally) body local optimize_size
  Called by: ipc_shm_release_buf/30 (1024962110 (estimated locally),0.95 per call) ipc_shm_acquire_buf/27 (124017180 (estimated locally),0.12 per call) ipc_shm_buf_tx/31 (1073741824 (estimated locally),1.00 per call) 
  Calls: ipc_check_mchan_integrity.part.0/63 (118111600 (estimated locally),0.98 per call) ipc_queue_check_integrity/52 (120522041 (estimated locally),1.00 per call) 
ipc_check_uchan_integrity/5 (ipc_check_uchan_integrity) @06e7dc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_unmanaged_tx/34 (1043112264 (estimated locally),0.97 per call) ipc_channel_rx/8 (59172124 (estimated locally),0.34 per call) 
  Calls: 
get_unmanaged_chan/4 (get_unmanaged_chan) @06e7d9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_unmanaged_tx/34 (1052266988 (estimated locally),0.98 per call) ipc_shm_unmanaged_acquire/33 (762356696 (estimated locally),0.71 per call) 
  Calls: 
get_managed_chan/3 (get_managed_chan) @06e7d700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ipc_shm_priv_data/1 (read)ipc_shm_priv_data/1 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ipc_shm_tx/32 (1052266988 (estimated locally),0.98 per call) ipc_shm_release_buf/30 (1052266988 (estimated locally),0.98 per call) ipc_shm_acquire_buf/27 (536870911 (estimated locally),0.50 per call) 
  Calls: 
ipc_shm_priv_data/1 (ipc_shm_priv_data) @06e785a0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ipc_shm_init_instance_priv/22 (write)ipc_shm_init_instance_priv/22 (write)ipc_channel_rx/8 (read)ipc_shm_init_instance/23 (read)ipc_shm_init_instance/23 (read)ipc_shm_init_a_channel/17 (write)ipc_shm_init_a_channel/17 (write)get_chan_memmap_size/20 (read)get_unmanaged_chan/4 (read)unmanaged_channel_init/16 (read)get_managed_chan/3 (addr)ipc_buf_pool_init/12 (addr)managed_channel_init/15 (read)managed_pools_init.isra.0/60 (read)ipc_buf_pool_init/12 (read)get_unmanaged_chan/4 (addr)get_chan_memmap_size/20 (read)ipc_buffer_populate/11 (read)ipc_shm_acquire_buf_from_pool/26 (read)ipc_shm_rx/10 (read)ipc_instance_is_free.part.0/57 (read)ipc_get_total_buf_per_chan/13 (write)ipc_shm_init_channels.isra.0/61 (write)ipc_shm_init_channels.isra.0/61 (read)ipc_shm_free_channel/19 (read)managed_channel_init/15 (addr)ipc_shm_free_channel/19 (addr)ipc_shm_free_instance.part.0/64 (read)ipc_shm_free_channel.part.0/62 (read)get_managed_chan/3 (read)ipc_get_total_buf_per_chan/13 (write)ipc_get_total_buf_per_chan/13 (write)unmanaged_channel_init/16 (write)unmanaged_channel_init/16 (write)unmanaged_channel_init/16 (write)unmanaged_channel_init/16 (write)unmanaged_channel_init/16 (write)get_chan_memmap_size/20 (read)get_chan_memmap_size/20 (read)get_chan_memmap_size/20 (read)get_chan_memmap_size/20 (read)ipc_channel_rx/8 (addr)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (addr)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_channel_rx/8 (read)ipc_buf_pool_init/12 (addr)ipc_buf_pool_init/12 (write)ipc_buf_pool_init/12 (write)managed_pools_init.isra.0/60 (read)managed_pools_init.isra.0/60 (read)ipc_shm_free_instance.part.0/64 (read)ipc_shm_free_instance.part.0/64 (read)ipc_shm_free_instance.part.0/64 (write)managed_pools_init.isra.0/60 (read)managed_pools_init.isra.0/60 (read)
  Availability: available
  Varpool flags:

;; Function ipc_instance_is_free.part.0 (ipc_instance_is_free.part.0, funcdef_no=37, decl_uid=6552, cgraph_uid=57, symbol_order=57)

Modification phase of node ipc_instance_is_free.part.0/57
ipc_instance_is_free.part.0 ()
{
  ipc_shm_instance_state err;
  const uint8 instance;
  struct ipc_shm_global * _1;
  long long unsigned int _2;

  <bb 8> [local count: 1073741824]:
  # DEBUG D#3 s=> instance
  # DEBUG instance => D#3

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = ipc_shm_priv_data[0].global;
  if (_1 != 0B)
    goto <bb 3>; [81.25%]
  else
    goto <bb 7>; [18.75%]

  <bb 3> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  _2 = _1->state;
  if (_2 == 3626036886834991177)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 296621179]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 0

  <bb 5> [local count: 872415233]:
  # err_4 = PHI <2(3), 0(4)>
  # DEBUG err => err_4
  # DEBUG BEGIN_STMT
  if (_2 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 436207616]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 1

  <bb 7> [local count: 1073741824]:
  # err_3 = PHI <2(2), err_4(5), 1(6)>
  # DEBUG err => err_3
  # DEBUG BEGIN_STMT
  return err_3;

}



;; Function ipc_shm_free_channel (ipc_shm_free_channel, funcdef_no=18, decl_uid=6043, cgraph_uid=19, symbol_order=19)

Modification phase of node ipc_shm_free_channel/19
ipc_shm_free_channel (const uint8 instance, uint8 chan_id, ipc_shm_channel_type chan_type)
{
  struct ipc_managed_channel * mchan;
  int _1;
  int _2;
  struct ipc_ring * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG uchan => 0B
  # DEBUG BEGIN_STMT
  # DEBUG mchan => 0B
  # DEBUG BEGIN_STMT
  if (chan_type_6(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 = (int) instance_8(D);
  _2 = (int) chan_id_9(D);
  mchan_10 = &ipc_shm_priv_data[_1].channels[_2].ch.mng;
  # DEBUG mchan => mchan_10
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct ipc_managed_channel *)&ipc_shm_priv_data][_1].channels[_2].ch.mng.bd_queue.push_ring;
  if (_3 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 4> [local count: 287064877]:
  # DEBUG BEGIN_STMT
  ipc_shm_free_managed_channel (mchan_10);
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (chan_type_6(D) == 1)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 182536112]:
  # DEBUG D#22 => chan_type_6(D)
  ipc_shm_free_channel.part.0 (instance_8(D), chan_id_9(D));

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function ipc_check_mchan_integrity (ipc_check_mchan_integrity, funcdef_no=6, decl_uid=5903, cgraph_uid=7, symbol_order=7)

Modification phase of node ipc_check_mchan_integrity/7
ipc_check_mchan_integrity (struct ipc_managed_channel * mchan)
{
  uint16 pool_id;
  sint8 err;
  struct ipc_queue * _1;
  signed char _2;

  <bb 2> [local count: 120522041]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pool => 0B
  # DEBUG BEGIN_STMT
  _1 = &mchan_8(D)->bd_queue;
  _2 = ipc_queue_check_integrity (_1);
  if (_2 == 0)
    goto <bb 3>; [98.00%]
  else
    goto <bb 4>; [2.00%]

  <bb 3> [local count: 118111600]:
  # err_4 = PHI <0(2)>
  # pool_id_6 = PHI <0(2)>
  err_3 = ipc_check_mchan_integrity.part.0 (mchan_8(D));

  <bb 4> [local count: 120522041]:
  # err_5 = PHI <err_3(3), -6(2)>
  # DEBUG err => err_5
  # DEBUG BEGIN_STMT
  return err_5;

}



;; Function ipc_shm_rx (ipc_shm_rx, funcdef_no=9, decl_uid=5935, cgraph_uid=10, symbol_order=10)

Modification phase of node ipc_shm_rx/10
ipc_shm_rx (const uint8 instance, uint32 budget)
{
  uint8 chan_id;
  uint32 work;
  uint8 more_work;
  uint32 chan_work;
  uint32 chan_budget;
  uint8 num_chans;
  int _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 14148526]:
  # DEBUG BEGIN_STMT
  _1 = (int) instance_13(D);
  num_chans_15 = ipc_shm_priv_data[_1].num_channels;
  # DEBUG num_chans => num_chans_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG more_work => 1
  # DEBUG BEGIN_STMT
  # DEBUG work => 0
  # DEBUG BEGIN_STMT
  # DEBUG chan_id => 0
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  _2 = budget_17(D) - work_9;
  _3 = (long unsigned int) num_chans_15;
  chan_budget_18 = _2 / _3;
  # DEBUG chan_budget => chan_budget_18
  # DEBUG BEGIN_STMT
  if (_2 < _3)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG chan_budget => 1

  <bb 5> [local count: 118111600]:
  # chan_budget_4 = PHI <chan_budget_18(3), 1(4)>
  # DEBUG chan_budget => chan_budget_4
  # DEBUG BEGIN_STMT
  # DEBUG more_work => 0
  # DEBUG BEGIN_STMT
  ipc_hw_flush_cache_remote (instance_13(D));
  # DEBUG BEGIN_STMT
  # DEBUG chan_id => 0
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  chan_work_21 = ipc_channel_rx (instance_13(D), chan_id_10, chan_budget_4);
  # DEBUG chan_work => chan_work_21
  # DEBUG BEGIN_STMT
  work_22 = work_8 + chan_work_21;
  # DEBUG work => work_22
  # DEBUG BEGIN_STMT
  if (chan_budget_4 == chan_work_21)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 324914276]:
  # DEBUG BEGIN_STMT
  # DEBUG more_work => 1

  <bb 8> [local count: 955630224]:
  # more_work_5 = PHI <more_work_6(6), 1(7)>
  # DEBUG more_work => more_work_5
  # DEBUG BEGIN_STMT
  chan_id_23 = chan_id_10 + 1;
  # DEBUG chan_id => chan_id_23

  <bb 9> [local count: 1073741824]:
  # more_work_6 = PHI <0(5), more_work_5(8)>
  # work_8 = PHI <work_9(5), work_22(8)>
  # chan_id_10 = PHI <0(5), chan_id_23(8)>
  # DEBUG chan_id => chan_id_10
  # DEBUG work => work_8
  # DEBUG more_work => more_work_6
  # DEBUG BEGIN_STMT
  if (chan_id_10 < num_chans_15)
    goto <bb 6>; [89.00%]
  else
    goto <bb 14>; [11.00%]

  <bb 14> [local count: 118111601]:

  <bb 11> [local count: 132260127]:
  # more_work_7 = PHI <1(2), more_work_6(14)>
  # work_9 = PHI <0(2), work_8(14)>
  # DEBUG work => work_9
  # DEBUG more_work => more_work_7
  # DEBUG BEGIN_STMT
  if (work_9 < budget_17(D))
    goto <bb 12>; [94.50%]
  else
    goto <bb 13>; [5.50%]

  <bb 12> [local count: 124985820]:
  if (more_work_7 != 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 13>; [5.50%]

  <bb 13> [local count: 14148527]:
  # work_16 = PHI <work_9(11), work_9(12)>
  # DEBUG BEGIN_STMT
  return work_16;

}



;; Function ipc_shm_init_instance (ipc_shm_init_instance, funcdef_no=22, decl_uid=5720, cgraph_uid=23, symbol_order=23)

Modification phase of node ipc_shm_init_instance/23
ipc_shm_init_instance (uint8 instance, const struct ipc_shm_cfg * cfg)
{
  uint8 chan_id;
  sint8 err;
  ipc_shm_instance_state _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned char _4;
  struct ipc_shm_channel_cfg * _5;
  unsigned int _6;
  unsigned int _7;
  struct ipc_shm_channel_cfg * _8;
  ipc_shm_channel_type _9;
  int _10;
  unsigned char _11;
  int _12;
  struct ipc_shm_global * _13;

  <bb 2> [local count: 200792109]:
  # DEBUG BEGIN_STMT
  # DEBUG err => -3
  # DEBUG BEGIN_STMT
  # DEBUG chan_id => 0
  # DEBUG BEGIN_STMT
  _1 = ipc_instance_is_free (instance_20(D));
  if (_1 != 0)
    goto <bb 3>; [98.00%]
  else
    goto <bb 14>; [2.00%]

  <bb 3> [local count: 196776266]:
  if (cfg_21(D) != 0B)
    goto <bb 4>; [99.13%]
  else
    goto <bb 14>; [0.87%]

  <bb 4> [local count: 195064313]:
  _2 = cfg_21(D)->local_shm_addr;
  if (_2 != 0)
    goto <bb 5>; [98.00%]
  else
    goto <bb 14>; [2.00%]

  <bb 5> [local count: 191163026]:
  _3 = cfg_21(D)->remote_shm_addr;
  if (_3 != 0)
    goto <bb 6>; [98.00%]
  else
    goto <bb 14>; [2.00%]

  <bb 6> [local count: 187339766]:
  _4 = cfg_21(D)->num_channels;
  if (_4 != 0)
    goto <bb 7>; [98.00%]
  else
    goto <bb 14>; [2.00%]

  <bb 7> [local count: 183592971]:
  if (_4 <= 3)
    goto <bb 8>; [96.02%]
  else
    goto <bb 14>; [3.98%]

  <bb 8> [local count: 176285970]:
  # DEBUG BEGIN_STMT
  err_23 = ipc_shm_init_instance_priv (instance_20(D), cfg_21(D));
  # DEBUG err => err_23
  # DEBUG BEGIN_STMT
  if (err_23 != 0)
    goto <bb 15>; [67.00%]
  else
    goto <bb 13>; [33.00%]

  <bb 15> [local count: 118111600]:
  goto <bb 12>; [100.00%]

  <bb 9> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  _5 = cfg_21(D)->channels;
  if (_5 != 0B)
    goto <bb 10>; [53.47%]
  else
    goto <bb 11>; [46.53%]

  <bb 10> [local count: 510975480]:
  # DEBUG BEGIN_STMT
  _6 = (unsigned int) chan_id_15;
  _7 = _6 * 20;
  _8 = _5 + _7;
  _9 = _8->type;
  ipc_shm_free_channel (instance_20(D), chan_id_15, _9);

  <bb 11> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  chan_id_29 = chan_id_15 + 1;
  # DEBUG chan_id => chan_id_29

  <bb 12> [local count: 1073741824]:
  # chan_id_15 = PHI <chan_id_29(11), 0(15)>
  # DEBUG chan_id => chan_id_15
  # DEBUG BEGIN_STMT
  _10 = (int) instance_20(D);
  _11 = ipc_shm_priv_data[_10].num_channels;
  if (_11 > chan_id_15)
    goto <bb 9>; [89.00%]
  else
    goto <bb 14>; [11.00%]

  <bb 13> [local count: 58174370]:
  # DEBUG BEGIN_STMT
  ipc_hw_irq_clear (instance_20(D));
  # DEBUG BEGIN_STMT
  ipc_hw_irq_enable (instance_20(D));
  # DEBUG BEGIN_STMT
  _12 = (int) instance_20(D);
  _13 = ipc_shm_priv_data[_12].global;
  _13->state = 3626036886834991177;
  # DEBUG BEGIN_STMT
  ipc_hw_flush_cache_local (instance_20(D));

  <bb 14> [local count: 200792109]:
  # err_14 = PHI <-3(2), -3(3), -3(4), -3(5), -3(6), -3(7), err_23(12), 0(13)>
  # DEBUG err => err_14
  # DEBUG BEGIN_STMT
  return err_14;

}



;; Function ipc_shm_free_instance (ipc_shm_free_instance, funcdef_no=23, decl_uid=5724, cgraph_uid=24, symbol_order=24)

Modification phase of node ipc_shm_free_instance/24
ipc_shm_free_instance (const uint8 instance)
{
  ipc_shm_instance_state _1;

  <bb 2> [local count: 236223200]:
  # DEBUG BEGIN_STMT
  # DEBUG chan_id => 0
  # DEBUG BEGIN_STMT
  _1 = ipc_instance_is_free (instance_5(D));
  if (_1 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 118111600]:
  ipc_shm_free_instance.part.0 (instance_5(D));

  <bb 4> [local count: 236223201]:
  return;

}



;; Function ipc_shm_free (ipc_shm_free, funcdef_no=24, decl_uid=5726, cgraph_uid=25, symbol_order=25)

Modification phase of node ipc_shm_free/25
ipc_shm_free ()
{
  uint8 instance_id;

  <bb 2> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG instance_id => 0
  # DEBUG BEGIN_STMT
  # DEBUG instance_id => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  ipc_shm_free_instance (0);
  # DEBUG BEGIN_STMT
  # DEBUG instance_id => 1

  <bb 4> [local count: 1073741824]:
  # instance_id_1 = PHI <0(2), 1(3)>
  # DEBUG instance_id => instance_id_1
  # DEBUG BEGIN_STMT
  if (instance_id_1 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 536870913]:
  return;

}



;; Function ipc_shm_init (ipc_shm_init, funcdef_no=27, decl_uid=5722, cgraph_uid=28, symbol_order=28)

Modification phase of node ipc_shm_init/28
ipc_shm_init (const struct ipc_shm_instances_cfg * cfg)
{
  sint8 err;
  uint8 instance_id;
  unsigned char _1;
  ipc_shm_instance_state _2;
  struct ipc_shm_cfg * _3;
  unsigned int _4;
  unsigned int _5;
  struct ipc_shm_cfg * _6;
  unsigned char _7;

  <bb 2> [local count: 91197479]:
  # DEBUG BEGIN_STMT
  # DEBUG instance_id => 0
  # DEBUG BEGIN_STMT
  # DEBUG err => -3
  # DEBUG BEGIN_STMT
  if (cfg_15(D) != 0B)
    goto <bb 3>; [99.13%]
  else
    goto <bb 9>; [0.87%]

  <bb 3> [local count: 90404061]:
  # DEBUG BEGIN_STMT
  _1 = cfg_15(D)->num_instances;
  if (_1 != 1)
    goto <bb 9>; [3.81%]
  else
    goto <bb 10>; [96.19%]

  <bb 10> [local count: 86959666]:
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _2 = ipc_instance_is_free (instance_id_8);
  if (_2 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 507343012]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 507343012]:
  # DEBUG BEGIN_STMT
  _3 = cfg_15(D)->shm_cfg;
  _4 = (unsigned int) instance_id_8;
  _5 = _4 * 48;
  _6 = _3 + _5;
  err_18 = ipc_shm_init_instance (instance_id_8, _6);
  # DEBUG err => err_18
  # DEBUG BEGIN_STMT
  if (err_18 != 0)
    goto <bb 9>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 7> [local count: 986782160]:
  # err_9 = PHI <err_10(5), err_18(6)>
  # DEBUG err => err_9
  # DEBUG BEGIN_STMT
  instance_id_19 = instance_id_8 + 1;
  # DEBUG instance_id => instance_id_19

  <bb 8> [local count: 1073741824]:
  # instance_id_8 = PHI <instance_id_19(7), 0(10)>
  # err_10 = PHI <err_9(7), -3(10)>
  # DEBUG err => err_10
  # DEBUG instance_id => instance_id_8
  # DEBUG BEGIN_STMT
  _7 = cfg_15(D)->num_instances;
  if (_7 > instance_id_8)
    goto <bb 4>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 91197479]:
  # err_11 = PHI <-3(2), -3(3), err_18(6), err_10(8)>
  # DEBUG err => err_11
  # DEBUG BEGIN_STMT
  return err_11;

}



;; Function ipc_shm_unmanaged_acquire (ipc_shm_unmanaged_acquire, funcdef_no=32, decl_uid=5742, cgraph_uid=33, symbol_order=33)

Modification phase of node ipc_shm_unmanaged_acquire/33
ipc_shm_unmanaged_acquire (const uint8 instance, uint8 chan_id)
{
  uint8 * umng_mem;
  struct ipc_unmanaged_channel * chan;
  ipc_shm_instance_state _1;
  long unsigned int _6;
  struct ipc_channel_umem * _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG chan => 0B
  # DEBUG BEGIN_STMT
  # DEBUG umng_mem => 0B
  # DEBUG BEGIN_STMT
  _1 = ipc_instance_is_free (instance_4(D));
  if (_1 == 0)
    goto <bb 3>; [71.00%]
  else
    goto <bb 6>; [29.00%]

  <bb 3> [local count: 762356696]:
  # DEBUG BEGIN_STMT
  chan_7 = get_unmanaged_chan (instance_4(D), chan_id_5(D));
  # DEBUG chan => chan_7
  # DEBUG BEGIN_STMT
  if (chan_7 != 0B)
    goto <bb 4>; [85.10%]
  else
    goto <bb 6>; [14.90%]

  <bb 4> [local count: 648765548]:
  # DEBUG BEGIN_STMT
  _9 = MEM[(struct ipc_channel_umem * *)chan_7 + 4B];
  # DEBUG D#1 => chan_7
  # DEBUG INLINE_ENTRY ipc_check_uchan_local_integrity
  # DEBUG uchan => D#1
  # DEBUG BEGIN_STMT
  # DEBUG err => -6
  # DEBUG BEGIN_STMT
  _6 = _9->sentinel;
  if (_6 == 1430474825)
    goto <bb 5>; [96.19%]
  else
    goto <bb 6>; [3.81%]

  <bb 5> [local count: 624047581]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  # DEBUG err => NULL
  # DEBUG BEGIN_STMT
  umng_mem_8 = &_9->mem;
  # DEBUG umng_mem => umng_mem_8

  <bb 6> [local count: 1073741824]:
  # umng_mem_2 = PHI <0B(2), 0B(3), 0B(4), umng_mem_8(5)>
  # DEBUG err => NULL
  # DEBUG umng_mem => umng_mem_2
  # DEBUG BEGIN_STMT
  return umng_mem_2;

}



;; Function ipc_shm_is_remote_ready (ipc_shm_is_remote_ready, funcdef_no=34, decl_uid=5747, cgraph_uid=35, symbol_order=35)

Modification phase of node ipc_shm_is_remote_ready/35
ipc_shm_is_remote_ready (const uint8 instance)
{
  sint8 err;
  struct ipc_shm_global * remote_global;
  ipc_shm_instance_state _1;
  long unsigned int _2;
  long long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG err => -3
  # DEBUG BEGIN_STMT
  _1 = ipc_instance_is_free (instance_7(D));
  if (_1 == 0)
    goto <bb 3>; [96.02%]
  else
    goto <bb 5>; [3.98%]

  <bb 3> [local count: 1031006900]:
  # DEBUG BEGIN_STMT
  ipc_hw_flush_cache_remote (instance_7(D));
  # DEBUG BEGIN_STMT
  _2 = ipc_os_get_remote_shm (instance_7(D));
  remote_global_10 = (struct ipc_shm_global *) _2;
  # DEBUG remote_global => remote_global_10
  # DEBUG BEGIN_STMT
  _3 = remote_global_10->state;
  if (_3 != 3626036886834991177)
    goto <bb 5>; [3.81%]
  else
    goto <bb 4>; [96.19%]

  <bb 4> [local count: 991725538]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 0

  <bb 5> [local count: 1073741824]:
  # err_4 = PHI <-3(2), -1(3), 0(4)>
  # DEBUG err => err_4
  # DEBUG BEGIN_STMT
  return err_4;

}



;; Function ipc_shm_acquire_buf (ipc_shm_acquire_buf, funcdef_no=26, decl_uid=5730, cgraph_uid=27, symbol_order=27)

Modification phase of node ipc_shm_acquire_buf/27
ipc_shm_acquire_buf (const uint8 instance, uint8 chan_id, uint32 mem_size)
{
  uintptr buf_addr;
  struct ipc_managed_channel * chan;
  signed char _1;
  signed char _2;
  void * _14;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG buf_addr => 0
  # DEBUG BEGIN_STMT
  _1 = ipc_shm_is_remote_ready (instance_6(D));
  if (_1 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 3> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  chan_9 = get_managed_chan (instance_6(D), chan_id_8(D));
  # DEBUG chan => chan_9
  # DEBUG BEGIN_STMT
  if (chan_9 == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 4> [local count: 375809638]:
  if (mem_size_10(D) == 0)
    goto <bb 8>; [67.00%]
  else
    goto <bb 5>; [33.00%]

  <bb 5> [local count: 124017180]:
  _2 = ipc_check_mchan_integrity (chan_9);
  if (_2 != 0)
    goto <bb 8>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 7> [local count: 40925670]:
  # DEBUG BEGIN_STMT
  buf_addr_13 = ipc_shm_acquire_buf_from_pool (instance_6(D), mem_size_10(D), chan_9);
  # DEBUG buf_addr => buf_addr_13

  <bb 8> [local count: 1073741824]:
  # buf_addr_3 = PHI <0(2), 0(4), buf_addr_13(7), 0(3), 0(5)>
  # DEBUG buf_addr => buf_addr_3
  # DEBUG BEGIN_STMT
  _14 = (void *) buf_addr_3;
  return _14;

}



;; Function ipc_shm_release_buf (ipc_shm_release_buf, funcdef_no=29, decl_uid=5734, cgraph_uid=30, symbol_order=30)

Modification phase of node ipc_shm_release_buf/30
ipc_shm_release_buf (const uint8 instance, uint8 chan_id, const void * buf)
{
  sint8 err;
  struct ipc_shm_bd bd;
  struct ipc_managed_channel * chan;
  signed char _1;
  long unsigned int buf.17_2;
  short unsigned int _3;
  int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  short unsigned int _9;
  struct ipc_queue * _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG err => -3
  # DEBUG BEGIN_STMT
  _1 = ipc_shm_is_remote_ready (instance_14(D));
  if (_1 == 0)
    goto <bb 3>; [98.00%]
  else
    goto <bb 8>; [2.00%]

  <bb 3> [local count: 1052266988]:
  # DEBUG BEGIN_STMT
  chan_17 = get_managed_chan (instance_14(D), chan_id_16(D));
  # DEBUG chan => chan_17
  # DEBUG BEGIN_STMT
  if (chan_17 != 0B)
    goto <bb 4>; [99.13%]
  else
    goto <bb 8>; [0.87%]

  <bb 4> [local count: 1043112264]:
  if (buf_18(D) != 0B)
    goto <bb 5>; [98.26%]
  else
    goto <bb 8>; [1.74%]

  <bb 5> [local count: 1024962110]:
  # DEBUG BEGIN_STMT
  err_20 = ipc_check_mchan_integrity (chan_17);
  # DEBUG err => err_20
  # DEBUG BEGIN_STMT
  if (err_20 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 6> [local count: 338237496]:
  # DEBUG BEGIN_STMT
  buf.17_2 = (long unsigned int) buf_18(D);
  err_22 = find_pool_for_buf (chan_17, buf.17_2, 1, &bd.pool_id);
  # DEBUG err => err_22
  # DEBUG BEGIN_STMT
  if (err_22 == 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 111618374]:
  # DEBUG BEGIN_STMT
  _3 = bd.pool_id;
  _4 = (int) _3;
  # DEBUG D#26 => &chan_17->pools[_4]
  # DEBUG pool => D#26
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct ipc_shm_pool *)chan_17].pools[_4].remote_pool_addr;
  _6 = buf.17_2 - _5;
  _7 = MEM[(struct ipc_shm_pool *)chan_17].pools[_4].buf_size;
  _8 = _6 / _7;
  _9 = (short unsigned int) _8;
  bd.buf_id = _9;
  # DEBUG BEGIN_STMT
  bd.data_size = 0;
  # DEBUG BEGIN_STMT
  _10 = &MEM[(struct ipc_shm_pool *)chan_17].pools[_4].bd_queue;
  err_26 = ipc_queue_push (_10, &bd);
  # DEBUG err => err_26
  # DEBUG BEGIN_STMT
  ipc_hw_flush_cache_local (instance_14(D));

  <bb 8> [local count: 1073741824]:
  # err_11 = PHI <-3(2), -3(3), -3(4), err_20(5), err_22(6), err_26(7)>
  # DEBUG err => err_11
  # DEBUG BEGIN_STMT
  bd ={v} {CLOBBER};
  return err_11;

}



;; Function ipc_shm_tx (ipc_shm_tx, funcdef_no=31, decl_uid=5739, cgraph_uid=32, symbol_order=32)

Modification phase of node ipc_shm_tx/32
ipc_shm_tx (const uint8 instance, uint8 chan_id, void * buf, uint32 size)
{
  sint8 err;
  struct ipc_managed_channel * chan;
  signed char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG err => -3
  # DEBUG BEGIN_STMT
  _1 = ipc_shm_is_remote_ready (instance_5(D));
  if (_1 == 0)
    goto <bb 3>; [98.00%]
  else
    goto <bb 7>; [2.00%]

  <bb 3> [local count: 1052266988]:
  # DEBUG BEGIN_STMT
  chan_8 = get_managed_chan (instance_5(D), chan_id_7(D));
  # DEBUG chan => chan_8
  # DEBUG BEGIN_STMT
  if (chan_8 != 0B)
    goto <bb 4>; [99.13%]
  else
    goto <bb 7>; [0.87%]

  <bb 4> [local count: 1043112264]:
  if (buf_9(D) != 0B)
    goto <bb 5>; [99.13%]
  else
    goto <bb 7>; [0.87%]

  <bb 5> [local count: 1034037186]:
  if (size_10(D) != 0)
    goto <bb 6>; [96.02%]
  else
    goto <bb 7>; [3.98%]

  <bb 6> [local count: 992882505]:
  # DEBUG BEGIN_STMT
  err_12 = ipc_shm_buf_tx (instance_5(D), buf_9(D), size_10(D), chan_8);
  # DEBUG err => err_12

  <bb 7> [local count: 1073741821]:
  # err_2 = PHI <-3(2), -3(3), -3(4), -3(5), err_12(6)>
  # DEBUG err => err_2
  # DEBUG BEGIN_STMT
  return err_2;

}



;; Function ipc_shm_unmanaged_tx (ipc_shm_unmanaged_tx, funcdef_no=33, decl_uid=5745, cgraph_uid=34, symbol_order=34)

Modification phase of node ipc_shm_unmanaged_tx/34
ipc_shm_unmanaged_tx (const uint8 instance, uint8 chan_id)
{
  sint8 err;
  struct ipc_unmanaged_channel * chan;
  signed char _1;
  struct ipc_channel_umem * _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG chan => 0B
  # DEBUG BEGIN_STMT
  # DEBUG err => -3
  # DEBUG BEGIN_STMT
  _1 = ipc_shm_is_remote_ready (instance_8(D));
  if (_1 == 0)
    goto <bb 3>; [98.00%]
  else
    goto <bb 6>; [2.00%]

  <bb 3> [local count: 1052266988]:
  # DEBUG BEGIN_STMT
  chan_11 = get_unmanaged_chan (instance_8(D), chan_id_10(D));
  # DEBUG chan => chan_11
  # DEBUG BEGIN_STMT
  if (chan_11 != 0B)
    goto <bb 4>; [99.13%]
  else
    goto <bb 6>; [0.87%]

  <bb 4> [local count: 1043112264]:
  # DEBUG BEGIN_STMT
  err_12 = ipc_check_uchan_integrity (chan_11);
  # DEBUG err => err_12
  # DEBUG BEGIN_STMT
  if (err_12 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 344227047]:
  # DEBUG BEGIN_STMT
  _2 = chan_11->local_mem;
  _3 ={v} _2->tx_count;
  _4 = _3 + 1;
  _2->tx_count ={v} _4;
  # DEBUG BEGIN_STMT
  ipc_hw_flush_cache_local (instance_8(D));
  # DEBUG BEGIN_STMT
  ipc_hw_irq_notify (instance_8(D));

  <bb 6> [local count: 1073741823]:
  # err_5 = PHI <-3(2), -3(3), err_12(4), 0(5)>
  # DEBUG err => err_5
  # DEBUG BEGIN_STMT
  return err_5;

}



;; Function ipc_shm_poll_channels (ipc_shm_poll_channels, funcdef_no=35, decl_uid=5749, cgraph_uid=36, symbol_order=36)

Modification phase of node ipc_shm_poll_channels/36
ipc_shm_poll_channels (const uint8 instance)
{
  sint8 err;
  ipc_shm_instance_state result;
  struct ipc_shm_global * remote_global;
  long unsigned int _1;
  long long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  result_7 = ipc_instance_is_free (instance_6(D));
  # DEBUG result => result_7
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  if (result_7 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  ipc_hw_flush_cache_remote (instance_6(D));
  # DEBUG BEGIN_STMT
  _1 = ipc_os_get_remote_shm (instance_6(D));
  remote_global_10 = (struct ipc_shm_global *) _1;
  # DEBUG remote_global => remote_global_10
  # DEBUG BEGIN_STMT
  _2 = remote_global_10->state;
  if (_2 != 3626036886834991177)
    goto <bb 7>; [7.44%]
  else
    goto <bb 4>; [92.56%]

  <bb 4> [local count: 327972293]:
  # DEBUG BEGIN_STMT
  err_12 = ipc_os_poll_channels (instance_6(D));
  # DEBUG err => err_12
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  if (result_7 == 1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 474808635]:
  # DEBUG BEGIN_STMT
  # DEBUG err => -3

  <bb 7> [local count: 1073741824]:
  # err_3 = PHI <err_12(4), -1(5), -3(6), -1(3)>
  # DEBUG err => err_3
  # DEBUG BEGIN_STMT
  return err_3;

}


