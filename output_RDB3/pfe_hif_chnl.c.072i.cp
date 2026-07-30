
IPA constant propagation start:
Determining dynamic type for call: _17 = pfe_hif_chnl_rx_pool_init (chnl_2(D));
  Starting walk at: _17 = pfe_hif_chnl_rx_pool_init (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_16 = pfe_hif_ring_create_mcal (_11, _15, 0);
  Function call may change dynamic type:_10 = pfe_hif_ring_create_mcal (_5, _9, 1);
Determining dynamic type for call: _18 = pfe_hif_chnl_create_cfg (chnl_2(D));
  Starting walk at: _18 = pfe_hif_chnl_create_cfg (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_17 = pfe_hif_chnl_rx_pool_init (chnl_2(D));
  Function call may change dynamic type:_16 = pfe_hif_ring_create_mcal (_11, _15, 0);
  Function call may change dynamic type:_10 = pfe_hif_ring_create_mcal (_5, _9, 1);
Determining dynamic type for call: pfe_hif_chnl_refill_rx_buffers (chnl_2(D));
  Starting walk at: pfe_hif_chnl_refill_rx_buffers (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_18 = pfe_hif_chnl_create_cfg (chnl_2(D));
  Function call may change dynamic type:_17 = pfe_hif_chnl_rx_pool_init (chnl_2(D));
  Function call may change dynamic type:_16 = pfe_hif_ring_create_mcal (_11, _15, 0);
  Function call may change dynamic type:_10 = pfe_hif_ring_create_mcal (_5, _9, 1);
Determining dynamic type for call: ret_4 = pfe_hif_chnl_supply_rx_buf (chnl_3(D), _2, 2048);
  Starting walk at: ret_4 = pfe_hif_chnl_supply_rx_buf (chnl_3(D), _2, 2048);
  instance pointer: chnl_3(D)  Outer instance pointer: chnl_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_4 = pfe_hif_chnl_supply_rx_buf (chnl_3(D), _2, 2048);
  Starting walk at: ret_4 = pfe_hif_chnl_supply_rx_buf (chnl_3(D), _2, 2048);
  instance pointer: _2  Outer instance pointer: ISRA.87_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_rx_dma_start (chnl_3(D));
  Starting walk at: pfe_hif_chnl_rx_dma_start (chnl_3(D));
  instance pointer: chnl_3(D)  Outer instance pointer: chnl_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_4 = pfe_hif_chnl_supply_rx_buf (chnl_3(D), _2, 2048);
Determining dynamic type for call: ret_5 = pfe_hif_chnl_send_dummy_frame (chnl_3(D), &dummy_tx_buf, 1);
  Starting walk at: ret_5 = pfe_hif_chnl_send_dummy_frame (chnl_3(D), &dummy_tx_buf, 1);
  instance pointer: chnl_3(D)  Outer instance pointer: chnl_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_rx_dma_start (chnl_3(D));
  Function call may change dynamic type:ret_4 = pfe_hif_chnl_supply_rx_buf (chnl_3(D), _2, 2048);
Determining dynamic type for call: ret_5 = pfe_hif_chnl_send_dummy_frame (chnl_3(D), &dummy_tx_buf, 1);
  Starting walk at: ret_5 = pfe_hif_chnl_send_dummy_frame (chnl_3(D), &dummy_tx_buf, 1);
  instance pointer: &dummy_tx_buf  Outer instance pointer: dummy_tx_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_rx_dma_start (chnl_3(D));
  Function call may change dynamic type:ret_4 = pfe_hif_chnl_supply_rx_buf (chnl_3(D), _2, 2048);
Determining dynamic type for call: pfe_hif_chnl_irq_mask (chnl_4(D));
  Starting walk at: pfe_hif_chnl_irq_mask (chnl_4(D));
  instance pointer: chnl_4(D)  Outer instance pointer: chnl_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_rx_irq_mask (chnl_4(D));
  Starting walk at: pfe_hif_chnl_rx_irq_mask (chnl_4(D));
  instance pointer: chnl_4(D)  Outer instance pointer: chnl_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_irq_mask (chnl_4(D));
Determining dynamic type for call: pfe_hif_chnl_tx_irq_mask (chnl_4(D));
  Starting walk at: pfe_hif_chnl_tx_irq_mask (chnl_4(D));
  instance pointer: chnl_4(D)  Outer instance pointer: chnl_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_rx_irq_mask (chnl_4(D));
  Function call may change dynamic type:pfe_hif_chnl_irq_mask (chnl_4(D));
Determining dynamic type for call: pfe_hif_chnl_destroy_inval_rx_ring.isra.0 (_14);
  Starting walk at: pfe_hif_chnl_destroy_inval_rx_ring.isra.0 (_14);
  instance pointer: _14  Outer instance pointer: chnl_4(D) offset: 64 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_irq_mask (chnl_4(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_irq_mask (chnl_4(D));
  Function call may change dynamic type:pfe_hif_chnl_irq_mask (chnl_4(D));
Determining dynamic type for call: pfe_hif_chnl_destroy_rings (chnl_4(D));
  Starting walk at: pfe_hif_chnl_destroy_rings (chnl_4(D));
  instance pointer: chnl_4(D)  Outer instance pointer: chnl_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_irq_mask (chnl_4(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_irq_mask (chnl_4(D));
  Function call may change dynamic type:pfe_hif_chnl_irq_mask (chnl_4(D));
  Function call may change dynamic type:pfe_hif_chnl_destroy_inval_rx_ring.isra.0 (_14);
Determining dynamic type for call: pfe_hif_chnl_rx_disable (chnl_9(D));
  Starting walk at: pfe_hif_chnl_rx_disable (chnl_9(D));
  instance pointer: chnl_9(D)  Outer instance pointer: chnl_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_tx_disable (chnl_9(D));
  Starting walk at: pfe_hif_chnl_tx_disable (chnl_9(D));
  instance pointer: chnl_9(D)  Outer instance pointer: chnl_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_9(D));
Determining dynamic type for call: pfe_hif_chnl_destroy_chnl (chnl_9(D));
  Starting walk at: pfe_hif_chnl_destroy_chnl (chnl_9(D));
  instance pointer: chnl_9(D)  Outer instance pointer: chnl_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_disable (chnl_9(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_9(D));
  Function call may change dynamic type:pfe_hif_ring_destroy (_1);
  Function call may change dynamic type:pfe_hif_ring_destroy (_5);
  Function call may change dynamic type:pfe_hif_chnl_cfg_is_tx_bdp_fifo_empty (_3, _4);
Determining dynamic type for call: _15 = pfe_hif_chnl_tx (chnl_22(D), tx_buf_va_19(D), tx_buf_va_19(D), 80, 1);
  Starting walk at: _15 = pfe_hif_chnl_tx (chnl_22(D), tx_buf_va_19(D), tx_buf_va_19(D), 80, 1);
  instance pointer: chnl_22(D)  Outer instance pointer: chnl_22(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = pfe_hif_chnl_tx (chnl_22(D), tx_buf_va_19(D), tx_buf_va_19(D), 80, 1);
  Starting walk at: _15 = pfe_hif_chnl_tx (chnl_22(D), tx_buf_va_19(D), tx_buf_va_19(D), 80, 1);
  instance pointer: tx_buf_va_19(D)  Outer instance pointer: tx_buf_va_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = pfe_hif_chnl_tx (chnl_22(D), tx_buf_va_19(D), tx_buf_va_19(D), 80, 1);
  Starting walk at: _15 = pfe_hif_chnl_tx (chnl_22(D), tx_buf_va_19(D), tx_buf_va_19(D), 80, 1);
  instance pointer: tx_buf_va_19(D)  Outer instance pointer: tx_buf_va_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: hw_status_9 = pfe_hif_chnl_inspect_hw_state (chnl_7(D));
  Starting walk at: hw_status_9 = pfe_hif_chnl_inspect_hw_state (chnl_7(D));
  instance pointer: chnl_7(D)  Outer instance pointer: chnl_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_hif_chnl_validate_bdr_setup (chnl_7(D));
  Starting walk at: _2 = pfe_hif_chnl_validate_bdr_setup (chnl_7(D));
  instance pointer: chnl_7(D)  Outer instance pointer: chnl_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:hw_status_9 = pfe_hif_chnl_inspect_hw_state (chnl_7(D));
Determining dynamic type for call: _3 = pfe_hif_chnl_ungraceful_reset (chnl_7(D));
  Starting walk at: _3 = pfe_hif_chnl_ungraceful_reset (chnl_7(D));
  instance pointer: chnl_7(D)  Outer instance pointer: chnl_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_chnl_validate_bdr_setup (chnl_7(D));
  Function call may change dynamic type:hw_status_9 = pfe_hif_chnl_inspect_hw_state (chnl_7(D));
Determining dynamic type for call: ret_11 = pfe_hif_chnl_bind_bd_rings (chnl_7(D));
  Starting walk at: ret_11 = pfe_hif_chnl_bind_bd_rings (chnl_7(D));
  instance pointer: chnl_7(D)  Outer instance pointer: chnl_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:hw_status_9 = pfe_hif_chnl_inspect_hw_state (chnl_7(D));
Determining dynamic type for call: _1 = pfe_hif_chnl_bind_tx_ring (chnl_9(D));
  Starting walk at: _1 = pfe_hif_chnl_bind_tx_ring (chnl_9(D));
  instance pointer: chnl_9(D)  Outer instance pointer: chnl_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_hif_chnl_bind_rx_ring (chnl_9(D));
  Starting walk at: _3 = pfe_hif_chnl_bind_rx_ring (chnl_9(D));
  instance pointer: chnl_9(D)  Outer instance pointer: chnl_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_hif_chnl_bind_tx_ring (chnl_9(D));
Determining dynamic type for call: ret_10 = pfe_hif_chnl_find_tx (chnl_8(D));
  Starting walk at: ret_10 = pfe_hif_chnl_find_tx (chnl_8(D));
  instance pointer: chnl_8(D)  Outer instance pointer: chnl_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_12 = pfe_hif_chnl_find_rx (chnl_8(D));
  Starting walk at: ret_12 = pfe_hif_chnl_find_rx (chnl_8(D));
  instance pointer: chnl_8(D)  Outer instance pointer: chnl_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_hif_chnl_find_tx (chnl_8(D));
Determining dynamic type for call: ret_14 = pfe_hif_chnl_rx_to_head (chnl_8(D));
  Starting walk at: ret_14 = pfe_hif_chnl_rx_to_head (chnl_8(D));
  instance pointer: chnl_8(D)  Outer instance pointer: chnl_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_hif_chnl_find_tx (chnl_8(D));
  Function call may change dynamic type:ret_12 = pfe_hif_chnl_find_rx (chnl_8(D));
Determining dynamic type for call: ret_16 = pfe_hif_chnl_tx_to_head (chnl_8(D));
  Starting walk at: ret_16 = pfe_hif_chnl_tx_to_head (chnl_8(D));
  instance pointer: chnl_8(D)  Outer instance pointer: chnl_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_hif_chnl_find_tx (chnl_8(D));
  Function call may change dynamic type:ret_12 = pfe_hif_chnl_find_rx (chnl_8(D));
  Function call may change dynamic type:ret_14 = pfe_hif_chnl_rx_to_head (chnl_8(D));
Determining dynamic type for call: pfe_hif_chnl_rx_disable (chnl_13(D));
  Starting walk at: pfe_hif_chnl_rx_disable (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_tx_enable (chnl_13(D));
  Starting walk at: pfe_hif_chnl_tx_enable (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_13(D));
Determining dynamic type for call: ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  Starting walk at: ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_tx_enable (chnl_13(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_13(D));
  Function call may change dynamic type:ret_23 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
Determining dynamic type for call: ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  Starting walk at: ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  instance pointer: &dummy_tx_buf  Outer instance pointer: dummy_tx_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_tx_enable (chnl_13(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_13(D));
  Function call may change dynamic type:ret_23 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
Determining dynamic type for call: ret_23 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Starting walk at: ret_23 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_tx_enable (chnl_13(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_13(D));
  Function call may change dynamic type:ret_23 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
Determining dynamic type for call: pfe_hif_chnl_disable_invalidate (chnl_13(D));
  Starting walk at: pfe_hif_chnl_disable_invalidate (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 0);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_tx_enable (chnl_13(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_13(D));
  Function call may change dynamic type:ret_23 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t read TX confirmation\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2506, "");
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t reach TX ring head\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2517, "");
Determining dynamic type for call: pfe_hif_chnl_tx_disable (chnl_6(D));
  Starting walk at: pfe_hif_chnl_tx_disable (chnl_6(D));
  instance pointer: chnl_6(D)  Outer instance pointer: chnl_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_enable (chnl_17(D));
  Starting walk at: pfe_hif_chnl_enable (chnl_17(D));
  instance pointer: chnl_17(D)  Outer instance pointer: chnl_17(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Starting walk at: ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  instance pointer: chnl_17(D)  Outer instance pointer: chnl_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_enable (chnl_17(D));
  Function call may change dynamic type:ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
Determining dynamic type for call: ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Starting walk at: ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  instance pointer: &dummy_rx_buf  Outer instance pointer: dummy_rx_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_enable (chnl_17(D));
  Function call may change dynamic type:ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
Determining dynamic type for call: ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  Starting walk at: ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  instance pointer: chnl_17(D)  Outer instance pointer: chnl_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_enable (chnl_17(D));
  Function call may change dynamic type:ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
Determining dynamic type for call: ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  Starting walk at: ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  instance pointer: &lifm  Outer instance pointer: lifm offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_enable (chnl_17(D));
  Function call may change dynamic type:ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
Determining dynamic type for call: pfe_hif_chnl_disable (chnl_17(D));
  Starting walk at: pfe_hif_chnl_disable (chnl_17(D));
  instance pointer: chnl_17(D)  Outer instance pointer: chnl_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_22 = pfe_hif_chnl_dummy_packet_to_self.isra.0 (chnl_17(D), &dummy_rx_buf);
  Function call may change dynamic type:_3 = pfe_hif_ring_is_on_head (_2);
  Function call may change dynamic type:pfe_hif_chnl_enable (chnl_17(D));
  Function call may change dynamic type:ret_25 = pfe_hif_chnl_do_tx_rx (chnl_17(D), &lifm);
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t reach RX ring head\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2449, "");
  Function call may change dynamic type:pfe_hif_ring_invalidate_direct (_4, ring_item_idx_6);
Determining dynamic type for call: ret_7 = pfe_hif_chnl_get_tx_conf (chnl_5(D));
  Starting walk at: ret_7 = pfe_hif_chnl_get_tx_conf (chnl_5(D));
  instance pointer: chnl_5(D)  Outer instance pointer: chnl_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_16 = pfe_hif_chnl_cache_bd (chnl_13(D));
  Starting walk at: ret_16 = pfe_hif_chnl_cache_bd (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_1, _2);
Determining dynamic type for call: pfe_hif_chnl_enable (chnl_13(D));
  Starting walk at: pfe_hif_chnl_enable (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_16 = pfe_hif_chnl_cache_bd (chnl_13(D));
  Function call may change dynamic type:_3 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_1, _2);
Determining dynamic type for call: ret_19 = pfe_hif_chnl_empty_cached_bd (chnl_13(D));
  Starting walk at: ret_19 = pfe_hif_chnl_empty_cached_bd (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_enable (chnl_13(D));
  Function call may change dynamic type:ret_16 = pfe_hif_chnl_cache_bd (chnl_13(D));
  Function call may change dynamic type:_3 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_1, _2);
Determining dynamic type for call: pfe_hif_chnl_disable (chnl_13(D));
  Starting walk at: pfe_hif_chnl_disable (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_16 = pfe_hif_chnl_cache_bd (chnl_13(D));
  Function call may change dynamic type:_3 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_1, _2);
  Function call may change dynamic type:ret_19 = pfe_hif_chnl_empty_cached_bd (chnl_13(D));
  Function call may change dynamic type:pfe_hif_chnl_enable (chnl_13(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] HIF%u is not able to find correct WB entry\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2343, _6, "");
  Function call may change dynamic type:_5 = pfe_hif_ring_find_wb_entry (_4, 0, &rx_idx);
  Function call may change dynamic type:pfe_hif_ring_force_index (_7, rx_idx.19_8);
Determining dynamic type for call: ret_18 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 1);
  Starting walk at: ret_18 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 1);
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_4, _5);
  Function call may change dynamic type:ret_21 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_18 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 1);
  Function call may change dynamic type:_6 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_4, _5);
Determining dynamic type for call: ret_18 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 1);
  Starting walk at: ret_18 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 1);
  instance pointer: &dummy_tx_buf  Outer instance pointer: dummy_tx_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_4, _5);
  Function call may change dynamic type:ret_21 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_18 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 1);
  Function call may change dynamic type:_6 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_4, _5);
Determining dynamic type for call: ret_21 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Starting walk at: ret_21 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  instance pointer: chnl_13(D)  Outer instance pointer: chnl_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_18 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 1);
  Function call may change dynamic type:_6 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_4, _5);
  Function call may change dynamic type:ret_21 = pfe_hif_chnl_get_tx_conf (chnl_13(D));
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_18 = pfe_hif_chnl_send_dummy_frame (chnl_13(D), &dummy_tx_buf, 1);
  Function call may change dynamic type:_6 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_4, _5);
Determining dynamic type for call: ret_35 = pfe_hif_chnl_supply_rx_buf (chnl_32(D), &dummy_rx_buf, 2048);
  Starting walk at: ret_35 = pfe_hif_chnl_supply_rx_buf (chnl_32(D), &dummy_rx_buf, 2048);
  instance pointer: chnl_32(D)  Outer instance pointer: chnl_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_35 = pfe_hif_chnl_supply_rx_buf (chnl_32(D), &dummy_rx_buf, 2048);
Determining dynamic type for call: ret_35 = pfe_hif_chnl_supply_rx_buf (chnl_32(D), &dummy_rx_buf, 2048);
  Starting walk at: ret_35 = pfe_hif_chnl_supply_rx_buf (chnl_32(D), &dummy_rx_buf, 2048);
  instance pointer: &dummy_rx_buf  Outer instance pointer: dummy_rx_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_35 = pfe_hif_chnl_supply_rx_buf (chnl_32(D), &dummy_rx_buf, 2048);
Determining dynamic type for call: pfe_hif_chnl_bdp_fetch_bd (chnl_32(D));
  Starting walk at: pfe_hif_chnl_bdp_fetch_bd (chnl_32(D));
  instance pointer: chnl_32(D)  Outer instance pointer: chnl_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_ring_invalidate_direct (_2, ring_idx_17);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t provide dummy RX buffer\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2220, "");
  Function call may change dynamic type:ret_35 = pfe_hif_chnl_supply_rx_buf (chnl_32(D), &dummy_rx_buf, 2048);
Determining dynamic type for call: pfe_hif_chnl_bdp_fetch_bd (chnl_32(D));
  Starting walk at: pfe_hif_chnl_bdp_fetch_bd (chnl_32(D));
  instance pointer: chnl_32(D)  Outer instance pointer: chnl_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_ring_force_index (_6, 0);
  Function call may change dynamic type:_5 = pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty (_3, _4);
  Function call may change dynamic type:pfe_hif_chnl_bdp_fetch_bd (chnl_32(D));
  Function call may change dynamic type:pfe_hif_ring_invalidate_direct (_2, ring_idx_17);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t provide dummy RX buffer\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2220, "");
  Function call may change dynamic type:ret_35 = pfe_hif_chnl_supply_rx_buf (chnl_32(D), &dummy_rx_buf, 2048);
  Function call may change dynamic type:pfe_hif_ring_revalidate_direct (_8, _9);
  Function call may change dynamic type:pfe_hif_ring_invalidate_direct (_7, ring_idx_18);
Determining dynamic type for call: pfe_hif_chnl_rx_enable (chnl_2(D));
  Starting walk at: pfe_hif_chnl_rx_enable (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_rx_dma_start (chnl_2(D));
  Starting walk at: pfe_hif_chnl_rx_dma_start (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_rx_enable (chnl_2(D));
Determining dynamic type for call: pfe_hif_chnl_rx_disable (chnl_2(D));
  Starting walk at: pfe_hif_chnl_rx_disable (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:pfe_hif_chnl_rx_dma_start (chnl_2(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_enable (chnl_2(D));
Determining dynamic type for call: pfe_hif_chnl_tx_enable (chnl_19(D));
  Starting walk at: pfe_hif_chnl_tx_enable (chnl_19(D));
  instance pointer: chnl_19(D)  Outer instance pointer: chnl_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_23 = pfe_hif_chnl_send_dummy_frame (chnl_19(D), &dummy_tx_buf, 0);
  Starting walk at: ret_23 = pfe_hif_chnl_send_dummy_frame (chnl_19(D), &dummy_tx_buf, 0);
  instance pointer: chnl_19(D)  Outer instance pointer: chnl_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_enable (chnl_19(D));
  Function call may change dynamic type:pfe_hif_ring_invalidate_direct (_3, ring_idx_11);
  Function call may change dynamic type:ret_26 = pfe_hif_ring_find_wb_entry (_2, 1, &tx_idx);
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_23 = pfe_hif_chnl_send_dummy_frame (chnl_19(D), &dummy_tx_buf, 0);
Determining dynamic type for call: ret_23 = pfe_hif_chnl_send_dummy_frame (chnl_19(D), &dummy_tx_buf, 0);
  Starting walk at: ret_23 = pfe_hif_chnl_send_dummy_frame (chnl_19(D), &dummy_tx_buf, 0);
  instance pointer: &dummy_tx_buf  Outer instance pointer: dummy_tx_buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_enable (chnl_19(D));
  Function call may change dynamic type:pfe_hif_ring_invalidate_direct (_3, ring_idx_11);
  Function call may change dynamic type:ret_26 = pfe_hif_ring_find_wb_entry (_2, 1, &tx_idx);
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:ret_23 = pfe_hif_chnl_send_dummy_frame (chnl_19(D), &dummy_tx_buf, 0);
Determining dynamic type for call: pfe_hif_chnl_tx_disable (chnl_19(D));
  Starting walk at: pfe_hif_chnl_tx_disable (chnl_19(D));
  instance pointer: chnl_19(D)  Outer instance pointer: chnl_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] TX index not found for HIF%u.\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2165, _4, "");
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t send frame\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2144, "");
  Function call may change dynamic type:ret_23 = pfe_hif_chnl_send_dummy_frame (chnl_19(D), &dummy_tx_buf, 0);
  Function call may change dynamic type:pfe_hif_chnl_tx_enable (chnl_19(D));
  Function call may change dynamic type:pfe_hif_ring_invalidate_direct (_3, ring_idx_11);
  Function call may change dynamic type:ret_26 = pfe_hif_ring_find_wb_entry (_2, 1, &tx_idx);
  Function call may change dynamic type:oal_time_usleep (500);
  Function call may change dynamic type:pfe_hif_ring_force_index (_8, _10);
  Function call may change dynamic type:pfe_hif_ring_invalidate_direct (_6, tx_idx.16_5);
Determining dynamic type for call: pfe_hif_chnl_rx_disable (chnl_15(D));
  Starting walk at: pfe_hif_chnl_rx_disable (chnl_15(D));
  instance pointer: chnl_15(D)  Outer instance pointer: chnl_15(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_tx_disable (chnl_15(D));
  Starting walk at: pfe_hif_chnl_tx_disable (chnl_15(D));
  instance pointer: chnl_15(D)  Outer instance pointer: chnl_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_15(D));
Determining dynamic type for call: pfe_hif_chnl_get_hw_state (chnl_15(D), &hws);
  Starting walk at: pfe_hif_chnl_get_hw_state (chnl_15(D), &hws);
  instance pointer: chnl_15(D)  Outer instance pointer: chnl_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_disable (chnl_15(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_15(D));
Determining dynamic type for call: pfe_hif_chnl_get_hw_state (chnl_15(D), &hws);
  Starting walk at: pfe_hif_chnl_get_hw_state (chnl_15(D), &hws);
  instance pointer: &hws  Outer instance pointer: hws offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_disable (chnl_15(D));
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (chnl_15(D));
Determining dynamic type for call: ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  Starting walk at: ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  instance pointer: buf_va_21(D)  Outer instance pointer: buf_va_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_20 = pfe_hif_ring_dequeue_buf (_1, &buf_pa, len_17(D), lifm_18(D));
Determining dynamic type for call: ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  Starting walk at: ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  instance pointer: &hif_hdr_ptr  Outer instance pointer: hif_hdr_ptr offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_20 = pfe_hif_ring_dequeue_buf (_1, &buf_pa, len_17(D), lifm_18(D));
Determining dynamic type for call: ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  Starting walk at: ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  instance pointer: &vlan_header  Outer instance pointer: vlan_header offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_20 = pfe_hif_ring_dequeue_buf (_1, &buf_pa, len_17(D), lifm_18(D));
Determining dynamic type for call: _5 = rx_pool_get_meta_buf (_3, _4);
  Starting walk at: _5 = rx_pool_get_meta_buf (_3, _4);
  instance pointer: _3  Outer instance pointer: chnl_16(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  Function call may change dynamic type:ret_20 = pfe_hif_ring_dequeue_buf (_1, &buf_pa, len_17(D), lifm_18(D));
Determining dynamic type for call: _5 = rx_pool_get_meta_buf (_3, _4);
  Starting walk at: _5 = rx_pool_get_meta_buf (_3, _4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  Function call may change dynamic type:ret_20 = pfe_hif_ring_dequeue_buf (_1, &buf_pa, len_17(D), lifm_18(D));
Determining dynamic type for call: _8 (_9);
  Starting walk at: _8 (_9);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_20 = pfe_hif_ring_dequeue_buf (_1, &buf_pa, len_17(D), lifm_18(D));
  Function call may change dynamic type:ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
Determining dynamic type for call: pfe_hif_chnl_tx_dma_start (chnl_4(D));
  Starting walk at: pfe_hif_chnl_tx_dma_start (chnl_4(D));
  instance pointer: chnl_4(D)  Outer instance pointer: chnl_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_9 = pfe_hif_ring_enqueue_buf (_1, buf_pa_5(D), len_6(D), 0, lifm_7(D));
Determining dynamic type for call: pfe_hif_chnl_tx_disable (chnl_2(D));
  Starting walk at: pfe_hif_chnl_tx_disable (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_rx_disable (chnl_2(D));
  Starting walk at: pfe_hif_chnl_rx_disable (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_disable (chnl_2(D));
Determining dynamic type for call: pfe_hif_chnl_tx_enable (chnl_2(D));
  Starting walk at: pfe_hif_chnl_tx_enable (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_chnl_rx_enable (chnl_2(D));
  Starting walk at: pfe_hif_chnl_rx_enable (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_chnl_tx_enable (chnl_2(D));
Determining dynamic type for call: _12 = pfe_hif_chnl_create_cfg (chnl_2(D));
  Starting walk at: _12 = pfe_hif_chnl_create_cfg (chnl_2(D));
  instance pointer: chnl_2(D)  Outer instance pointer: chnl_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_9 = pfe_hif_chnl_create_mcal_aux.isra.0 (chnl_4(D), cbus_base_va_6(D), id_3(D));
  Starting walk at: ret_9 = pfe_hif_chnl_create_mcal_aux.isra.0 (chnl_4(D), cbus_base_va_6(D), id_3(D));
  instance pointer: chnl_4(D)  Outer instance pointer: chnl_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_10 = pfe_hif_chnl_init (chnl_6(D));
  Starting walk at: ret_10 = pfe_hif_chnl_init (chnl_6(D));
  instance pointer: chnl_6(D)  Outer instance pointer: chnl_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_8 = pfe_hif_chnl_cfg_init (_1, _2);
  Function call may change dynamic type:oal_mutex_lock.part.0 (44);
Determining dynamic type for call: _12 = pfe_hif_chnl_can_accept_rx_buf (chnl_16(D));
  Starting walk at: _12 = pfe_hif_chnl_can_accept_rx_buf (chnl_16(D));
  instance pointer: chnl_16(D)  Outer instance pointer: chnl_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_supply_rx_buf (chnl_16(D), new_buffer_va_18, _8);
  Function call may change dynamic type:new_buffer_va_18 = rx_pool_get (_1);
Determining dynamic type for call: new_buffer_va_18 = rx_pool_get (_1);
  Starting walk at: new_buffer_va_18 = rx_pool_get (_1);
  instance pointer: _1  Outer instance pointer: chnl_16(D) offset: 128 (bits) vtbl reference: 
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_supply_rx_buf (chnl_16(D), new_buffer_va_18, _8);
  Function call may change dynamic type:new_buffer_va_18 = rx_pool_get (_1);
Determining dynamic type for call: ret_20 = pfe_hif_chnl_supply_rx_buf (chnl_16(D), new_buffer_va_18, _8);
  Starting walk at: ret_20 = pfe_hif_chnl_supply_rx_buf (chnl_16(D), new_buffer_va_18, _8);
  instance pointer: chnl_16(D)  Outer instance pointer: chnl_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:new_buffer_va_18 = rx_pool_get (_1);
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_supply_rx_buf (chnl_16(D), new_buffer_va_18, _8);
  Function call may change dynamic type:new_buffer_va_18 = rx_pool_get (_1);
Determining dynamic type for call: ret_20 = pfe_hif_chnl_supply_rx_buf (chnl_16(D), new_buffer_va_18, _8);
  Starting walk at: ret_20 = pfe_hif_chnl_supply_rx_buf (chnl_16(D), new_buffer_va_18, _8);
  instance pointer: new_buffer_va_18  Outer instance pointer: new_buffer_va_18 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:new_buffer_va_18 = rx_pool_get (_1);
  Function call may change dynamic type:ret_20 = pfe_hif_chnl_supply_rx_buf (chnl_16(D), new_buffer_va_18, _8);
  Function call may change dynamic type:new_buffer_va_18 = rx_pool_get (_1);
Determining dynamic type for call: _5 (_6);
  Starting walk at: _5 (_6);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_unlock.part.0 (41);
  Function call may change dynamic type:ret_17 = pfe_hif_chnl_cfg_isr (_1, _2, &events);
  Function call may change dynamic type:oal_mutex_lock.part.0 (41);
Determining dynamic type for call: _9 (_10);
  Starting walk at: _9 (_10);
  instance pointer: _10  Outer instance pointer: _10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_unlock.part.0 (41);
  Function call may change dynamic type:ret_17 = pfe_hif_chnl_cfg_isr (_1, _2, &events);
  Function call may change dynamic type:oal_mutex_lock.part.0 (41);
  Function call may change dynamic type:_5 (_6);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_hif_chnl_create_mcal_aux.isra.0/397:
    callsite  pfe_hif_chnl_create_mcal_aux.isra.0/397 -> pfe_hif_chnl_refill_rx_buffers/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_create_mcal_aux.isra.0/397 -> pfe_hif_chnl_create_cfg/30 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_create_mcal_aux.isra.0/397 -> pfe_hif_chnl_rx_pool_init/77 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_dummy_packet_to_self.isra.0/396:
    callsite  pfe_hif_chnl_dummy_packet_to_self.isra.0/396 -> pfe_hif_chnl_send_dummy_frame/81 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &dummy_tx_buf
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_dummy_packet_to_self.isra.0/396 -> pfe_hif_chnl_rx_dma_start/41 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_dummy_packet_to_self.isra.0/396 -> pfe_hif_chnl_supply_rx_buf/60 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 2048
         value: 0x800, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_destroy_inval_rx_ring.isra.0/368:
  Jump functions of caller  pfe_hif_chnl_add_vlan_tag.isra.0/367:
  Jump functions of caller  oal_mutex_unlock.part.0/366:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  oal_mutex_lock.part.0/365:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  pfe_hif_chnl_cfg_get_emac_timer_ownership/364:
  Jump functions of caller  pfe_hif_nocpy_cfg_get_emac_timer_ownership/363:
  Jump functions of caller  pfe_hif_chnl_cfg_set_emac_timer_ownership/362:
  Jump functions of caller  pfe_hif_nocpy_cfg_set_emac_timer_ownership/361:
  Jump functions of caller  pfe_hif_chnl_cfg_get_rx_cnt/360:
  Jump functions of caller  pfe_hif_chnl_cfg_get_tx_cnt/359:
  Jump functions of caller  pfe_hif_ring_dump/358:
  Jump functions of caller  pfe_hif_chnl_cfg_is_tx_bdp_fifo_empty/357:
  Jump functions of caller  pfe_hif_ring_invalidate/356:
  Jump functions of caller  pfe_hif_ring_drain_buf/355:
  Jump functions of caller  pfe_hif_chnl_cfg_fini/354:
  Jump functions of caller  pfe_hif_chnl_cfg_is_tx_dma_active/353:
  Jump functions of caller  pfe_hif_chnl_cfg_is_rx_dma_active/352:
  Jump functions of caller  pfe_hif_ring_destroy/351:
  Jump functions of caller  pfe_hif_ring_is_on_head/350:
  Jump functions of caller  pfe_hif_ring_revalidate_direct/349:
  Jump functions of caller  pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty/348:
  Jump functions of caller  pfe_hif_ring_force_index/347:
  Jump functions of caller  pfe_hif_ring_invalidate_direct/346:
  Jump functions of caller  pfe_hif_ring_find_wb_entry/345:
  Jump functions of caller  oal_time_usleep/344:
  Jump functions of caller  pfe_hif_chnl_cfg_get_tx_wb_table_len/342:
  Jump functions of caller  pfe_hif_chnl_cfg_get_rx_wb_table_len/341:
  Jump functions of caller  pfe_hif_chnl_cfg_get_tx_wb_table_addr/340:
  Jump functions of caller  pfe_hif_chnl_cfg_get_rx_wb_table_addr/339:
  Jump functions of caller  pfe_hif_chnl_cfg_get_tx_bd_ring_addr/338:
  Jump functions of caller  pfe_hif_chnl_cfg_get_rx_bd_ring_addr/337:
  Jump functions of caller  pfe_hif_chnl_cfg_set_tx_wb_table/336:
  Jump functions of caller  pfe_hif_chnl_cfg_set_tx_bd_ring_addr/335:
  Jump functions of caller  pfe_hif_chnl_cfg_set_rx_wb_table/334:
  Jump functions of caller  pfe_hif_ring_get_wb_tbl_len/333:
  Jump functions of caller  pfe_hif_chnl_cfg_set_rx_bd_ring_addr/332:
  Jump functions of caller  pfe_hif_ring_get_wb_tbl_pa/331:
  Jump functions of caller  pfe_hif_ring_get_base_pa/330:
  Jump functions of caller  autolibc_memcpy/329:
  Jump functions of caller  autolibc_memmove/328:
  Jump functions of caller  pfe_hif_ring_dequeue_buf/326:
  Jump functions of caller  pfe_hif_ring_dequeue_plain/325:
  Jump functions of caller  pfe_hif_ring_enqueue_buf/324:
  Jump functions of caller  pfe_hif_ring_get_len/323:
  Jump functions of caller  pfe_hif_ring_get_fill_level/322:
  Jump functions of caller  pfe_hif_chnl_cfg_tx_irq_unmask/321:
  Jump functions of caller  pfe_hif_chnl_cfg_tx_irq_mask/320:
  Jump functions of caller  pfe_hif_chnl_cfg_rx_irq_unmask/319:
  Jump functions of caller  pfe_hif_chnl_cfg_rx_irq_mask/318:
  Jump functions of caller  pfe_hif_chnl_cfg_tx_dma_start/317:
  Jump functions of caller  pfe_hif_chnl_cfg_rx_dma_start/316:
  Jump functions of caller  pfe_hif_chnl_cfg_rx_disable/315:
  Jump functions of caller  pfe_hif_chnl_cfg_rx_enable/314:
  Jump functions of caller  pfe_hif_chnl_cfg_tx_disable/313:
  Jump functions of caller  pfe_hif_chnl_cfg_tx_enable/312:
  Jump functions of caller  __builtin_expect/311:
  Jump functions of caller  pfe_hif_chnl_cfg_init/310:
  Jump functions of caller  pfe_hif_ring_create_mcal/309:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/307:
  Jump functions of caller  pfe_hm_report/306:
  Jump functions of caller  pfe_hif_chnl_cfg_irq_unmask/305:
  Jump functions of caller  pfe_hif_chnl_cfg_irq_mask/304:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/303:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/302:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/301:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/300:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/299:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/298:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/297:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/296:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/295:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/294:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/293:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/292:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/291:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/290:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/289:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/288:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/287:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/286:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/285:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/284:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/283:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/282:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/281:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/280:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/279:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/278:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/277:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/276:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/275:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/274:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/273:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/272:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/271:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/270:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/269:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/268:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/267:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/266:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/265:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/264:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/263:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/262:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/261:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/260:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/259:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/258:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/257:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/256:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/255:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/254:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/253:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/252:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/251:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/250:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/249:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/248:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/247:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/246:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/245:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/244:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/243:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/242:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/241:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/240:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/239:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/238:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/237:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/236:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/235:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/234:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/233:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/232:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/231:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/230:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/229:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/228:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/227:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/226:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/225:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/224:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/223:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/222:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/221:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/220:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/219:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/218:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/217:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/216:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/215:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/214:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/213:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/212:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/211:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/210:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/209:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/208:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/207:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/206:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/205:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/204:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/203:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/202:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/201:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/200:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/199:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/198:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/197:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/196:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/195:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/194:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/193:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/192:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/191:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/190:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/189:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/188:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/187:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/186:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/185:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/184:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/183:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/182:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/181:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/180:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/179:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/178:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/177:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/176:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/175:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/174:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/173:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/172:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/171:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/170:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/169:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/168:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/167:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/166:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/165:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/164:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/163:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/162:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/161:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/160:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/159:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/158:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/157:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/156:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/155:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/154:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/153:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/152:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/151:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/150:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/149:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/148:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/147:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/146:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/145:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/144:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/143:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/142:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/141:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/140:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/139:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/138:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/137:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/136:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/135:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/134:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/133:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/132:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/131:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/130:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/129:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/128:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/127:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/126:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/125:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/124:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/123:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/122:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/121:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/120:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/119:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/118:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/117:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/116:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/115:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/114:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/113:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/112:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/111:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/110:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/109:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/108:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/107:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/106:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/105:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/104:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/103:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/102:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/101:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/100:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/99:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/98:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/97:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/96:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/95:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/94:
  Jump functions of caller  pfe_hif_chnl_cfg_isr/93:
  Jump functions of caller  pfe_hif_chnl_get_emac_timer_ownership/92:
  Jump functions of caller  pfe_hif_chnl_set_emac_timer_ownership/91:
  Jump functions of caller  pfe_hif_chnl_get_lmem_hdr_size/90:
  Jump functions of caller  pfe_hif_chnl_set_lmem_hdr_size/89:
  Jump functions of caller  pfe_hif_chnl_get_rx_cnt/88:
  Jump functions of caller  pfe_hif_chnl_get_tx_cnt/87:
  Jump functions of caller  pfe_hif_chnl_dump_ring/86:
  Jump functions of caller  pfe_hif_chnl_destroy/85:
    callsite  pfe_hif_chnl_destroy/85 -> pfe_hif_chnl_destroy_rings/83 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_destroy/85 -> pfe_hif_chnl_destroy_inval_rx_ring.isra.0/368 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_hif_chnl_destroy/85 -> pfe_hif_chnl_tx_irq_mask/46 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_destroy/85 -> pfe_hif_chnl_rx_irq_mask/44 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_destroy/85 -> pfe_hif_chnl_irq_mask/27 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_destroy_rings/83:
    callsite  pfe_hif_chnl_destroy_rings/83 -> pfe_hif_chnl_destroy_chnl/82 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_destroy_rings/83 -> pfe_hif_chnl_tx_disable/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_destroy_rings/83 -> pfe_hif_chnl_rx_disable/38 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_destroy_chnl/82:
    callsite  pfe_hif_chnl_destroy_chnl/82 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 53
         value: 0x35, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_destroy_chnl/82 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 53
         value: 0x35, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_send_dummy_frame/81:
    callsite  pfe_hif_chnl_send_dummy_frame/81 -> pfe_hif_chnl_tx/54 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 80
         value: 0x50, mask: 0x0
         Unknown VR
       param 4: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_is_tx_dma_active/80:
  Jump functions of caller  pfe_hif_chnl_is_rx_dma_active/79:
  Jump functions of caller  pfe_hif_chnl_init/78:
    callsite  pfe_hif_chnl_init/78 -> pfe_hif_chnl_bind_bd_rings/76 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_init/78 -> pfe_hif_chnl_ungraceful_reset/75 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_init/78 -> pfe_hif_chnl_validate_bdr_setup/64 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_init/78 -> pfe_hif_chnl_inspect_hw_state/63 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_rx_pool_init/77:
  Jump functions of caller  pfe_hif_chnl_bind_bd_rings/76:
    callsite  pfe_hif_chnl_bind_bd_rings/76 -> pfe_hif_chnl_bind_rx_ring/61 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_bind_bd_rings/76 -> pfe_hif_chnl_bind_tx_ring/62 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_ungraceful_reset/75:
    callsite  pfe_hif_chnl_ungraceful_reset/75 -> pfe_hif_chnl_tx_to_head/74 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_ungraceful_reset/75 -> pfe_hif_chnl_rx_to_head/72 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_ungraceful_reset/75 -> pfe_hif_chnl_find_rx/69 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_ungraceful_reset/75 -> pfe_hif_chnl_find_tx/65 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_tx_to_head/74:
    callsite  pfe_hif_chnl_tx_to_head/74 -> pfe_hif_chnl_disable_invalidate/73 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_tx_to_head/74 -> pfe_hif_chnl_get_tx_conf/55 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_tx_to_head/74 -> pfe_hif_chnl_send_dummy_frame/81 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &dummy_tx_buf
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_tx_to_head/74 -> pfe_hif_chnl_tx_enable/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_tx_to_head/74 -> pfe_hif_chnl_rx_disable/38 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_disable_invalidate/73:
    callsite  pfe_hif_chnl_disable_invalidate/73 -> pfe_hif_chnl_tx_disable/36 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_rx_to_head/72:
    callsite  pfe_hif_chnl_rx_to_head/72 -> pfe_hif_chnl_disable/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_rx_to_head/72 -> pfe_hif_chnl_do_tx_rx/71 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_hif_chnl_rx_to_head/72 -> pfe_hif_chnl_dummy_packet_to_self.isra.0/396 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &dummy_rx_buf
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
    callsite  pfe_hif_chnl_rx_to_head/72 -> pfe_hif_chnl_enable/39 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_do_tx_rx/71:
    callsite  pfe_hif_chnl_do_tx_rx/71 -> pfe_hif_chnl_get_tx_conf/55 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_find_rx/69:
    callsite  pfe_hif_chnl_find_rx/69 -> pfe_hif_chnl_disable/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_find_rx/69 -> pfe_hif_chnl_empty_cached_bd/68 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_find_rx/69 -> pfe_hif_chnl_enable/39 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_find_rx/69 -> pfe_hif_chnl_cache_bd/67 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_empty_cached_bd/68:
    callsite  pfe_hif_chnl_empty_cached_bd/68 -> pfe_hif_chnl_get_tx_conf/55 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_empty_cached_bd/68 -> pfe_hif_chnl_send_dummy_frame/81 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &dummy_tx_buf
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_cache_bd/67:
    callsite  pfe_hif_chnl_cache_bd/67 -> pfe_hif_chnl_bdp_fetch_bd/66 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_cache_bd/67 -> pfe_hif_chnl_bdp_fetch_bd/66 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_cache_bd/67 -> pfe_hif_chnl_supply_rx_buf/60 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &dummy_rx_buf
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 2: CONST: 2048
         value: 0x800, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_bdp_fetch_bd/66:
    callsite  pfe_hif_chnl_bdp_fetch_bd/66 -> pfe_hif_chnl_rx_disable/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_bdp_fetch_bd/66 -> pfe_hif_chnl_rx_dma_start/41 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_bdp_fetch_bd/66 -> pfe_hif_chnl_rx_enable/37 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_find_tx/65:
    callsite  pfe_hif_chnl_find_tx/65 -> pfe_hif_chnl_tx_disable/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_find_tx/65 -> pfe_hif_chnl_send_dummy_frame/81 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &dummy_tx_buf
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_find_tx/65 -> pfe_hif_chnl_tx_enable/35 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_validate_bdr_setup/64:
  Jump functions of caller  pfe_hif_chnl_inspect_hw_state/63:
    callsite  pfe_hif_chnl_inspect_hw_state/63 -> pfe_hif_chnl_get_hw_state/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_hif_chnl_inspect_hw_state/63 -> pfe_hif_chnl_tx_disable/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_inspect_hw_state/63 -> pfe_hif_chnl_rx_disable/38 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_bind_tx_ring/62:
  Jump functions of caller  pfe_hif_chnl_bind_rx_ring/61:
  Jump functions of caller  pfe_hif_chnl_supply_rx_buf/60:
  Jump functions of caller  pfe_hif_chnl_release_buf/59:
    callsite  pfe_hif_chnl_release_buf/59 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 54
         value: 0x36, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_release_buf/59 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 54
         value: 0x36, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_get_meta_size/58:
  Jump functions of caller  pfe_hif_chnl_rx_va/57:
    callsite  pfe_hif_chnl_rx_va/57 -> rx_pool_get_meta_buf/25 : 
       param 0: ANCESTOR: 0, offset 128
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_rx_va/57 -> pfe_hif_chnl_add_vlan_tag.isra.0/367 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    indirect aggregate callsite, calling param 0, offset 384, by reference, for stmt _8 (_9);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_get_tx_conf/55:
  Jump functions of caller  pfe_hif_chnl_tx/54:
    callsite  pfe_hif_chnl_tx/54 -> pfe_hif_chnl_tx_dma_start/42 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_get_tx_fifo_depth/53:
  Jump functions of caller  pfe_hif_chnl_get_rx_fifo_depth/52:
  Jump functions of caller  pfe_hif_chnl_tx_fifo_empty/51:
  Jump functions of caller  pfe_hif_chnl_can_accept_tx_num/50:
  Jump functions of caller  pfe_hif_chnl_can_accept_rx_buf/49:
  Jump functions of caller  pfe_hif_chnl_has_tx_conf/48:
  Jump functions of caller  pfe_hif_chnl_tx_irq_unmask/47:
    callsite  pfe_hif_chnl_tx_irq_unmask/47 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 52
         value: 0x34, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_tx_irq_unmask/47 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 52
         value: 0x34, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_tx_irq_mask/46:
    callsite  pfe_hif_chnl_tx_irq_mask/46 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 51
         value: 0x33, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_tx_irq_mask/46 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 51
         value: 0x33, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_rx_irq_unmask/45:
    callsite  pfe_hif_chnl_rx_irq_unmask/45 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 50
         value: 0x32, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_rx_irq_unmask/45 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 50
         value: 0x32, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_rx_irq_mask/44:
    callsite  pfe_hif_chnl_rx_irq_mask/44 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 49
         value: 0x31, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_rx_irq_mask/44 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 49
         value: 0x31, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_set_event_cbk/43:
  Jump functions of caller  pfe_hif_chnl_tx_dma_start/42:
  Jump functions of caller  pfe_hif_chnl_rx_dma_start/41:
  Jump functions of caller  pfe_hif_chnl_disable/40:
    callsite  pfe_hif_chnl_disable/40 -> pfe_hif_chnl_rx_disable/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_disable/40 -> pfe_hif_chnl_tx_disable/36 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_enable/39:
    callsite  pfe_hif_chnl_enable/39 -> pfe_hif_chnl_rx_enable/37 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_enable/39 -> pfe_hif_chnl_tx_enable/35 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_rx_disable/38:
    callsite  pfe_hif_chnl_rx_disable/38 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 48
         value: 0x30, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_rx_disable/38 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 48
         value: 0x30, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_rx_enable/37:
    callsite  pfe_hif_chnl_rx_enable/37 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 47
         value: 0x2f, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_rx_enable/37 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 47
         value: 0x2f, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_tx_disable/36:
    callsite  pfe_hif_chnl_tx_disable/36 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 46
         value: 0x2e, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_tx_disable/36 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 46
         value: 0x2e, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_tx_enable/35:
    callsite  pfe_hif_chnl_tx_enable/35 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 45
         value: 0x2d, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_tx_enable/35 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 45
         value: 0x2d, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_get_id/34:
  Jump functions of caller  pfe_hif_chnl_create_minihif/33:
    callsite  pfe_hif_chnl_create_minihif/33 -> pfe_hif_chnl_create_cfg/30 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_create_mcal/32:
    callsite  pfe_hif_chnl_create_mcal/32 -> pfe_hif_chnl_create_mcal_aux.isra.0/397 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_create_cfg/30:
    callsite  pfe_hif_chnl_create_cfg/30 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 44
         value: 0x2c, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_create_cfg/30 -> pfe_hif_chnl_init/78 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_create_cfg/30 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 44
         value: 0x2c, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_refill_rx_buffers/29:
    callsite  pfe_hif_chnl_refill_rx_buffers/29 -> pfe_hif_chnl_can_accept_rx_buf/49 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_chnl_refill_rx_buffers/29 -> pfe_hif_chnl_supply_rx_buf/60 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
    callsite  pfe_hif_chnl_refill_rx_buffers/29 -> rx_pool_get/24 : 
       param 0: ANCESTOR: 0, offset 128
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_hif_chnl_irq_unmask/28:
    callsite  pfe_hif_chnl_irq_unmask/28 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 43
         value: 0x2b, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_irq_unmask/28 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 43
         value: 0x2b, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_irq_mask/27:
    callsite  pfe_hif_chnl_irq_mask/27 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 42
         value: 0x2a, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_irq_mask/27 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 42
         value: 0x2a, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_chnl_isr/26:
    callsite  pfe_hif_chnl_isr/26 -> oal_mutex_unlock.part.0/366 : 
       param 0: CONST: 41
         value: 0x29, mask: 0x0
         Unknown VR
    callsite  pfe_hif_chnl_isr/26 -> oal_mutex_lock.part.0/365 : 
       param 0: CONST: 41
         value: 0x29, mask: 0x0
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 320, by reference, for stmt _9 (_10);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 256, by reference, for stmt _5 (_6);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  rx_pool_get_meta_buf/25:
  Jump functions of caller  rx_pool_get/24:
  Jump functions of caller  pfe_hif_chnl_get_hw_state/21:

 Propagating constants:

Not considering pfe_hif_chnl_get_emac_timer_ownership for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_set_emac_timer_ownership for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_get_lmem_hdr_size for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_set_lmem_hdr_size for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_get_rx_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_get_tx_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_dump_ring for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_destroy_chnl for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_is_tx_dma_active for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_is_rx_dma_active for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_inspect_hw_state for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_bind_tx_ring for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_bind_rx_ring for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_supply_rx_buf for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_release_buf for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_get_meta_size for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_rx_va for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_get_tx_conf for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_tx for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_get_tx_fifo_depth for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_get_rx_fifo_depth for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_tx_fifo_empty for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_can_accept_tx_num for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_can_accept_rx_buf for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_has_tx_conf for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_tx_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_tx_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_rx_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_rx_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_set_event_cbk for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_tx_dma_start for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_rx_dma_start for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_rx_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_rx_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_tx_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_tx_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_get_id for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_create_minihif for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_create_mcal for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_chnl_isr for cloning; -fipa-cp-clone disabled.

overall_size: 1756, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 2.000000
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 32, time_benefit: 1.000000
 - context independent values, size: 25, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 41, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 14, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: pfe_hif_chnl_create_mcal_aux.isra.0/397:
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
  Node: pfe_hif_chnl_dummy_packet_to_self.isra.0/396:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &dummy_rx_buf [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffff8
         void * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_hif_chnl_destroy_inval_rx_ring.isra.0/368:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_hif_ring_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_hif_chnl_add_vlan_tag.isra.0/367:
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
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_ct_hif_rx_hdr_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: oal_mutex_unlock.part.0/366:
    param [0]: BOTTOM
         ctxs: VARIABLE
         Bits: value = 0x35, mask = 0x1f
         const oal_mutex_t [41, 54]
        AGGS VARIABLE
  Node: oal_mutex_lock.part.0/365:
    param [0]: BOTTOM
         ctxs: VARIABLE
         Bits: value = 0x35, mask = 0x1f
         const oal_mutex_t [41, 54]
        AGGS VARIABLE
  Node: pfe_hif_chnl_get_emac_timer_ownership/92:
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
  Node: pfe_hif_chnl_set_emac_timer_ownership/91:
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
  Node: pfe_hif_chnl_get_lmem_hdr_size/90:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_set_lmem_hdr_size/89:
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
  Node: pfe_hif_chnl_get_rx_cnt/88:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_get_tx_cnt/87:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_dump_ring/86:
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
  Node: pfe_hif_chnl_destroy/85:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_destroy_rings/83:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_destroy_chnl/82:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_send_dummy_frame/81:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &dummy_tx_buf [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffff8
         void * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: 1 [loc_time: 4, loc_size: 37, prop_time: 0, prop_size: 0]
               0 [loc_time: 4, loc_size: 23, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         send_dummy_frame_mode_t [0, 1]
        AGGS VARIABLE
  Node: pfe_hif_chnl_is_tx_dma_active/80:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_is_rx_dma_active/79:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_init/78:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_rx_pool_init/77:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_bind_bd_rings/76:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_ungraceful_reset/75:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_tx_to_head/74:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_disable_invalidate/73:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_rx_to_head/72:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_do_tx_rx/71:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         bool_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_hif_chnl_find_rx/69:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_empty_cached_bd/68:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_cache_bd/67:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_bdp_fetch_bd/66:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_find_tx/65:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_validate_bdr_setup/64:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_inspect_hw_state/63:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_bind_tx_ring/62:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_bind_rx_ring/61:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_supply_rx_buf/60:
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
  Node: pfe_hif_chnl_release_buf/59:
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
  Node: pfe_hif_chnl_get_meta_size/58:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_rx_va/57:
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
  Node: pfe_hif_chnl_get_tx_conf/55:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_tx/54:
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
  Node: pfe_hif_chnl_get_tx_fifo_depth/53:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_get_rx_fifo_depth/52:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_tx_fifo_empty/51:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_can_accept_tx_num/50:
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
  Node: pfe_hif_chnl_can_accept_rx_buf/49:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_has_tx_conf/48:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_tx_irq_unmask/47:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_tx_irq_mask/46:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_rx_irq_unmask/45:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_rx_irq_mask/44:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_set_event_cbk/43:
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
  Node: pfe_hif_chnl_tx_dma_start/42:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_rx_dma_start/41:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_disable/40:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_enable/39:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_rx_disable/38:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_rx_enable/37:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_tx_disable/36:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_tx_enable/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_get_id/34:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_create_minihif/33:
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
  Node: pfe_hif_chnl_create_mcal/32:
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
  Node: pfe_hif_chnl_create_cfg/30:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_refill_rx_buffers/29:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_chnl_irq_unmask/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_irq_mask/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_isr/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: rx_pool_get_meta_buf/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct rx_pool_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: rx_pool_get/24:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct rx_pool_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_hif_chnl_get_hw_state/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct HifChnlHwStateType * ~[0B, 0B]
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of pfe_hif_chnl_dummy_packet_to_self.isra.0/396 for all known contexts.
    replacing param #1 ISRA.87 with const &dummy_rx_buf
 - Creating a specialized node of pfe_hif_chnl_send_dummy_frame/81 for all known contexts.
    replacing param #1 tx_buf_va with const &dummy_tx_buf
Propagated bits info for function pfe_hif_chnl_send_dummy_frame.constprop/400:
 param 1: value = 0x0, mask = 0xfffffff8
 param 2: value = 0x0, mask = 0x1
Propagated bits info for function pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop/399:
 param 1: value = 0x0, mask = 0xfffffff8
Propagated bits info for function pfe_hif_chnl_dummy_packet_to_self.isra.0/396:
 param 1: value = 0x0, mask = 0xfffffff8
Propagated bits info for function pfe_hif_chnl_add_vlan_tag.isra.0/367:
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function oal_mutex_unlock.part.0/366:
 param 0: value = 0x35, mask = 0x1f
Propagated bits info for function oal_mutex_lock.part.0/365:
 param 0: value = 0x35, mask = 0x1f
Propagated bits info for function pfe_hif_chnl_send_dummy_frame/81:
 param 1: value = 0x0, mask = 0xfffffff8
 param 2: value = 0x0, mask = 0x1
Propagated bits info for function pfe_hif_chnl_get_hw_state/21:
 param 1: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: pfe_hif_chnl_dummy_packet_to_self.isra.0/396 pfe_hif_chnl_send_dummy_frame/81
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_hif_chnl_send_dummy_frame.constprop.0/400 (pfe_hif_chnl_send_dummy_frame.constprop) @076e0e00
  Type: function definition analyzed
  Visibility:
  References: dummy_tx_buf/18 (addr)
  Referring: 
  Clone of pfe_hif_chnl_send_dummy_frame/81
  Availability: local
  Function flags: count:1073741824 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (0 (precise),0.00 per call) pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop/399 (429497 (estimated locally),0.00 per call) 
  Calls: pfe_hif_chnl_tx/54 (1073634451 (estimated locally),1.00 per call) pfe_hm_report/306 (354299369 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/307 (354299369 (estimated locally),0.33 per call) 
pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop.0/399 (pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop) @076a98c0
  Type: function definition analyzed
  Visibility: artificial
  References: dummy_tx_buf/18 (addr)dummy_rx_buf/19 (addr)
  Referring: 
  Clone of pfe_hif_chnl_dummy_packet_to_self.isra.0/396
  Availability: local
  Function flags: count:1073741824 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_supply_rx_buf/60 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/306 (1073312328 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (1073312328 (estimated locally),1.00 per call) pfe_hif_chnl_rx_dma_start/41 (429497 (estimated locally),0.00 per call) pfe_hif_chnl_send_dummy_frame.constprop/400 (429497 (estimated locally),0.00 per call) 
pfe_hif_chnl_create_mcal_aux.isra.0/397 (pfe_hif_chnl_create_mcal_aux.isra.0) @07034c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: tx_rings_memory/16 (addr)rx_rings_memory/15 (addr)Eth_43_PFE_InternalCfgPtr/308 (read)Eth_43_PFE_InternalCfgPtr/308 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_create_mcal/32 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_refill_rx_buffers/29 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_create_cfg/30 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_rx_pool_init/77 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (429497 (estimated locally),0.00 per call) pfe_hm_report/306 (429497 (estimated locally),0.00 per call) pfe_hif_ring_create_mcal/309 (429497 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (1073312328 (estimated locally),1.00 per call) pfe_hm_report/306 (1073312328 (estimated locally),1.00 per call) pfe_hif_ring_create_mcal/309 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_dummy_packet_to_self.isra.0/396 (pfe_hif_chnl_dummy_packet_to_self.isra.0) @0741e460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_destroy_inval_rx_ring.isra.0/368 (pfe_hif_chnl_destroy_inval_rx_ring.isra.0) @070a5700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_destroy/85 (0 (precise),0.00 per call) 
  Calls: pfe_hif_ring_invalidate/356 (118111601 (estimated locally),1.00 per call) pfe_hif_ring_drain_buf/355 (1073741824 (estimated locally),9.09 per call) 
pfe_hif_chnl_add_vlan_tag.isra.0/367 (pfe_hif_chnl_add_vlan_tag.isra.0) @076c1a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: *.LC0/327 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local hot optimize_size
  Called by: pfe_hif_chnl_rx_va/57 (354334802 (estimated locally),0.33 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/307 (225056286 (estimated locally),0.21 per call) pfe_hm_report/306 (225056286 (estimated locally),0.21 per call) autolibc_memcpy/329 (280066228 (estimated locally),0.26 per call) autolibc_memmove/328 (280066228 (estimated locally),0.26 per call) 
oal_mutex_unlock.part.0/366 (oal_mutex_unlock.part.0) @07052540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_chnl_create_cfg/30 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_destroy_chnl/82 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_release_buf/59 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_tx_irq_unmask/47 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_tx_irq_mask/46 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_rx_irq_unmask/45 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_rx_irq_mask/44 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_rx_disable/38 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_rx_enable/37 (872415233 (estimated locally),0.81 per call) pfe_hif_chnl_tx_disable/36 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_tx_enable/35 (872415233 (estimated locally),0.81 per call) pfe_hif_chnl_irq_unmask/28 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_irq_mask/27 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_isr/26 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
oal_mutex_lock.part.0/365 (oal_mutex_lock.part.0) @06df8d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_chnl_create_cfg/30 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_destroy_chnl/82 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_release_buf/59 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_tx_irq_unmask/47 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_tx_irq_mask/46 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_rx_irq_unmask/45 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_rx_irq_mask/44 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_rx_disable/38 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_rx_enable/37 (872415233 (estimated locally),0.81 per call) pfe_hif_chnl_tx_disable/36 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_tx_enable/35 (872415233 (estimated locally),0.81 per call) pfe_hif_chnl_irq_unmask/28 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_irq_mask/27 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_isr/26 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_cfg_get_emac_timer_ownership/364 (pfe_hif_chnl_cfg_get_emac_timer_ownership) @077c87e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_emac_timer_ownership/92 (856416480 (estimated locally),0.80 per call) 
  Calls: 
pfe_hif_nocpy_cfg_get_emac_timer_ownership/363 (pfe_hif_nocpy_cfg_get_emac_timer_ownership) @077c8700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_emac_timer_ownership/92 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_hif_chnl_cfg_set_emac_timer_ownership/362 (pfe_hif_chnl_cfg_set_emac_timer_ownership) @077c8460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_set_emac_timer_ownership/91 (856416480 (estimated locally),0.80 per call) 
  Calls: 
pfe_hif_nocpy_cfg_set_emac_timer_ownership/361 (pfe_hif_nocpy_cfg_set_emac_timer_ownership) @077c8380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_set_emac_timer_ownership/91 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_rx_cnt/360 (pfe_hif_chnl_cfg_get_rx_cnt) @077c8000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_rx_cnt/88 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_tx_cnt/359 (pfe_hif_chnl_cfg_get_tx_cnt) @077bee00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_tx_cnt/87 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_ring_dump/358 (pfe_hif_ring_dump) @077bec40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_dump_ring/86 (429497 (estimated locally),0.00 per call) pfe_hif_chnl_dump_ring/86 (429497 (estimated locally),0.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_is_tx_bdp_fifo_empty/357 (pfe_hif_chnl_cfg_is_tx_bdp_fifo_empty) @077bea80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_destroy_rings/83 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ring_invalidate/356 (pfe_hif_ring_invalidate) @077be8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_destroy_inval_rx_ring.isra.0/368 (118111601 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_ring_drain_buf/355 (pfe_hif_ring_drain_buf) @077be7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_destroy_inval_rx_ring.isra.0/368 (1073741824 (estimated locally),9.09 per call) 
  Calls: 
pfe_hif_chnl_cfg_fini/354 (pfe_hif_chnl_cfg_fini) @077be540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_destroy_chnl/82 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_is_tx_dma_active/353 (pfe_hif_chnl_cfg_is_tx_dma_active) @077be380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_is_tx_dma_active/80 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_is_rx_dma_active/352 (pfe_hif_chnl_cfg_is_rx_dma_active) @077be1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_is_rx_dma_active/79 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_ring_destroy/351 (pfe_hif_ring_destroy) @077be000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_destroy_rings/83 (0 (precise),0.00 per call) pfe_hif_chnl_destroy_rings/83 (0 (precise),0.00 per call) pfe_hif_chnl_bind_bd_rings/76 (0 (precise),0.00 per call) pfe_hif_chnl_bind_bd_rings/76 (0 (precise),0.00 per call) pfe_hif_chnl_bind_bd_rings/76 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ring_is_on_head/350 (pfe_hif_ring_is_on_head) @077a4a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ring_revalidate_direct/349 (pfe_hif_ring_revalidate_direct) @077a4540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty/348 (pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty) @077a42a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_find_rx/69 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_empty_cached_bd/68 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ring_force_index/347 (pfe_hif_ring_force_index) @077a4000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ring_invalidate_direct/346 (pfe_hif_ring_invalidate_direct) @0778cee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (459454908 (estimated locally),4.00 per call) pfe_hif_chnl_disable_invalidate/73 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ring_find_wb_entry/345 (pfe_hif_ring_find_wb_entry) @0778ce00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) 
  Calls: 
oal_time_usleep/344 (oal_time_usleep) @0778cd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_bdp_fetch_bd/66 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_tx_wb_table_len/342 (pfe_hif_chnl_cfg_get_tx_wb_table_len) @0778c8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_hw_state/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_rx_wb_table_len/341 (pfe_hif_chnl_cfg_get_rx_wb_table_len) @0778c7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_hw_state/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_tx_wb_table_addr/340 (pfe_hif_chnl_cfg_get_tx_wb_table_addr) @0778c700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_hw_state/21 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_rx_wb_table_addr/339 (pfe_hif_chnl_cfg_get_rx_wb_table_addr) @0778c620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_hw_state/21 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_tx_bd_ring_addr/338 (pfe_hif_chnl_cfg_get_tx_bd_ring_addr) @0778c540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_hw_state/21 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_rx_bd_ring_addr/337 (pfe_hif_chnl_cfg_get_rx_bd_ring_addr) @0778c460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_get_hw_state/21 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_set_tx_wb_table/336 (pfe_hif_chnl_cfg_set_tx_wb_table) @0778c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_bind_tx_ring/62 (127263 (estimated locally),0.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_set_tx_bd_ring_addr/335 (pfe_hif_chnl_cfg_set_tx_bd_ring_addr) @0778c0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_bind_tx_ring/62 (318157219 (estimated locally),0.30 per call) 
  Calls: 
pfe_hif_chnl_cfg_set_rx_wb_table/334 (pfe_hif_chnl_cfg_set_rx_wb_table) @0777dee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_bind_rx_ring/61 (127263 (estimated locally),0.00 per call) 
  Calls: 
pfe_hif_ring_get_wb_tbl_len/333 (pfe_hif_ring_get_wb_tbl_len) @0777de00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_bind_tx_ring/62 (127263 (estimated locally),0.00 per call) pfe_hif_chnl_bind_rx_ring/61 (127263 (estimated locally),0.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_set_rx_bd_ring_addr/332 (pfe_hif_chnl_cfg_set_rx_bd_ring_addr) @0777dd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_bind_rx_ring/61 (318157219 (estimated locally),0.30 per call) 
  Calls: 
pfe_hif_ring_get_wb_tbl_pa/331 (pfe_hif_ring_get_wb_tbl_pa) @0777dc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_bind_tx_ring/62 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_bind_rx_ring/61 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (0 (estimated locally),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (429497 (estimated locally),0.00 per call) 
  Calls: 
pfe_hif_ring_get_base_pa/330 (pfe_hif_ring_get_base_pa) @0777db60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_bind_tx_ring/62 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_bind_rx_ring/61 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (172 (estimated locally),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memcpy/329 (autolibc_memcpy) @0777d620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_add_vlan_tag.isra.0/367 (280066228 (estimated locally),0.26 per call) 
  Calls: 
autolibc_memmove/328 (autolibc_memmove) @0777d540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_add_vlan_tag.isra.0/367 (280066228 (estimated locally),0.26 per call) 
  Calls: 
*.LC0/327 (*.LC0) @07780630
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: pfe_hif_chnl_add_vlan_tag.isra.0/367 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_hif_ring_dequeue_buf/326 (pfe_hif_ring_dequeue_buf) @0777d380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_rx_va/57 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_ring_dequeue_plain/325 (pfe_hif_ring_dequeue_plain) @0777d1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_do_tx_rx/71 (536870913 (estimated locally),0.50 per call) pfe_hif_chnl_get_tx_conf/55 (1073741824 (estimated locally),9.35 per call) 
  Calls: 
pfe_hif_ring_enqueue_buf/324 (pfe_hif_ring_enqueue_buf) @0777d000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx/54 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_supply_rx_buf/60 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_release_buf/59 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_ring_get_len/323 (pfe_hif_ring_get_len) @07774a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (114863532 (estimated locally),1.00 per call) pfe_hif_chnl_get_tx_fifo_depth/53 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_get_rx_fifo_depth/52 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_can_accept_tx_num/50 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_can_accept_rx_buf/49 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_disable_invalidate/73 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ring_get_fill_level/322 (pfe_hif_ring_get_fill_level) @077748c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_rx_va/57 (1073741823 (estimated locally),1.00 per call) pfe_hif_chnl_tx_fifo_empty/51 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_can_accept_tx_num/50 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_can_accept_rx_buf/49 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_has_tx_conf/48 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_tx_irq_unmask/321 (pfe_hif_chnl_cfg_tx_irq_unmask) @07774700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx_irq_unmask/47 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_tx_irq_mask/320 (pfe_hif_chnl_cfg_tx_irq_mask) @07774540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx_irq_mask/46 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_rx_irq_unmask/319 (pfe_hif_chnl_cfg_rx_irq_unmask) @07774380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_rx_irq_unmask/45 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_rx_irq_mask/318 (pfe_hif_chnl_cfg_rx_irq_mask) @077741c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_rx_irq_mask/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_tx_dma_start/317 (pfe_hif_chnl_cfg_tx_dma_start) @07767ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx_dma_start/42 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_rx_dma_start/316 (pfe_hif_chnl_cfg_rx_dma_start) @07767d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_rx_dma_start/41 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_rx_disable/315 (pfe_hif_chnl_cfg_rx_disable) @07767b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_rx_disable/38 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_rx_enable/314 (pfe_hif_chnl_cfg_rx_enable) @077679a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_rx_enable/37 (872415233 (estimated locally),0.81 per call) 
  Calls: 
pfe_hif_chnl_cfg_tx_disable/313 (pfe_hif_chnl_cfg_tx_disable) @077677e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx_disable/36 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_tx_enable/312 (pfe_hif_chnl_cfg_tx_enable) @07767620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_tx_enable/35 (872415233 (estimated locally),0.81 per call) 
  Calls: 
__builtin_expect/311 (__builtin_expect) @077671c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_refill_rx_buffers/29 (930998585 (estimated locally),3.95 per call) pfe_hif_chnl_refill_rx_buffers/29 (1034442873 (estimated locally),4.39 per call) pfe_hif_chnl_release_buf/59 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_init/310 (pfe_hif_chnl_cfg_init) @07767000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_create_cfg/30 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_ring_create_mcal/309 (pfe_hif_ring_create_mcal) @0775bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_create_mcal_aux.isra.0/397 (429497 (estimated locally),0.00 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Eth_43_PFE_InternalCfgPtr/308 (Eth_43_PFE_InternalCfgPtr) @077613a8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: pfe_hif_chnl_refill_rx_buffers/29 (read)pfe_hif_chnl_release_buf/59 (read)pfe_hif_chnl_rx_pool_init/77 (read)pfe_hif_chnl_create_mcal_aux.isra.0/397 (read)pfe_hif_chnl_create_mcal_aux.isra.0/397 (read)
  Availability: not_available
  Varpool flags:
oal_util_raise_dem_for_drv_runtime_err/307 (oal_util_raise_dem_for_drv_runtime_err) @0775ba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_send_dummy_frame.constprop/400 (354299369 (estimated locally),0.33 per call) pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop/399 (1073312328 (estimated locally),1.00 per call) pfe_hif_chnl_create_mcal/32 (177884489 (estimated locally),0.17 per call) pfe_hif_chnl_create_mcal/32 (225056286 (estimated locally),0.21 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (0 (precise),0.00 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (0 (precise),0.00 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (429497 (estimated locally),0.00 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (1073312328 (estimated locally),1.00 per call) pfe_hif_chnl_create_cfg/30 (0 (precise),0.00 per call) pfe_hif_chnl_create_cfg/30 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_init/78 (0 (precise),0.00 per call) pfe_hif_chnl_init/78 (0 (precise),0.00 per call) pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (1014686024 (estimated locally),0.95 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) pfe_hif_chnl_bind_tx_ring/62 (109629040 (estimated locally),0.10 per call) pfe_hif_chnl_bind_rx_ring/61 (109629040 (estimated locally),0.10 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (55807731 (estimated locally),0.49 per call) pfe_hif_chnl_release_buf/59 (107374182 (estimated locally),0.10 per call) pfe_hif_chnl_do_tx_rx/71 (177167401 (estimated locally),0.17 per call) pfe_hif_chnl_do_tx_rx/71 (536870913 (estimated locally),0.50 per call) pfe_hif_chnl_rx_enable/37 (201326592 (estimated locally),0.19 per call) pfe_hif_chnl_tx_enable/35 (201326592 (estimated locally),0.19 per call) pfe_hif_chnl_validate_bdr_setup/64 (0 (estimated locally),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (172 (estimated locally),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (429325 (estimated locally),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (1073312328 (estimated locally),1.00 per call) pfe_hif_chnl_add_vlan_tag.isra.0/367 (225056286 (estimated locally),0.21 per call) pfe_hif_chnl_rx_pool_init/77 (225056286 (estimated locally),0.21 per call) 
  Calls: 
pfe_hm_report/306 (pfe_hm_report) @0775b9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_send_dummy_frame.constprop/400 (354299369 (estimated locally),0.33 per call) pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop/399 (1073312328 (estimated locally),1.00 per call) pfe_hif_chnl_create_mcal/32 (177884489 (estimated locally),0.17 per call) pfe_hif_chnl_create_mcal/32 (225056286 (estimated locally),0.21 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (0 (precise),0.00 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (0 (precise),0.00 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (429497 (estimated locally),0.00 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (1073312328 (estimated locally),1.00 per call) pfe_hif_chnl_create_cfg/30 (0 (precise),0.00 per call) pfe_hif_chnl_create_cfg/30 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_init/78 (0 (precise),0.00 per call) pfe_hif_chnl_init/78 (0 (precise),0.00 per call) pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (1014686024 (estimated locally),0.95 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) pfe_hif_chnl_bind_tx_ring/62 (109629040 (estimated locally),0.10 per call) pfe_hif_chnl_bind_rx_ring/61 (109629040 (estimated locally),0.10 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (55807731 (estimated locally),0.49 per call) pfe_hif_chnl_release_buf/59 (107374182 (estimated locally),0.10 per call) pfe_hif_chnl_do_tx_rx/71 (177167401 (estimated locally),0.17 per call) pfe_hif_chnl_do_tx_rx/71 (536870913 (estimated locally),0.50 per call) pfe_hif_chnl_rx_enable/37 (201326592 (estimated locally),0.19 per call) pfe_hif_chnl_tx_enable/35 (201326592 (estimated locally),0.19 per call) pfe_hif_chnl_validate_bdr_setup/64 (0 (estimated locally),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (172 (estimated locally),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (429325 (estimated locally),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (1073312328 (estimated locally),1.00 per call) pfe_hif_chnl_add_vlan_tag.isra.0/367 (225056286 (estimated locally),0.21 per call) pfe_hif_chnl_rx_pool_init/77 (225056286 (estimated locally),0.21 per call) 
  Calls: 
pfe_hif_chnl_cfg_irq_unmask/305 (pfe_hif_chnl_cfg_irq_unmask) @0775b7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_irq_unmask/28 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_irq_mask/304 (pfe_hif_chnl_cfg_irq_mask) @0775b620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_irq_mask/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/303 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @0775b460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/302 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @0775b380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/301 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @0775b2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/300 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @0775b1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/299 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @0775b0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/298 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @0775b000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/297 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @07759ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/296 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07759e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/295 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07759d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/294 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @07759c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/293 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @07759b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/292 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @07759a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/291 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @077599a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/290 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @077598c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/289 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @077597e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/288 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07759700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/287 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @07759620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/286 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @07759540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/285 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @07759460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/284 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @07759380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/283 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @077592a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/282 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @077591c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/281 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @077590e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/280 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @07759000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/279 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @07758ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/278 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07758e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/277 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07758d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/276 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07758c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/275 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @07758b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/274 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @07758a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/273 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @077589a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/272 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @077588c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/271 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @077587e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/270 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07758700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/269 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @07758620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/268 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @07758540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/267 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @07758460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/266 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @07758380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/265 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @077582a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/264 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @077581c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/263 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @077580e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/262 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @07758000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/261 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @07757ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/260 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07757e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/259 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07757d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/258 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07757c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/257 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @07757b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/256 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @07757a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/255 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @077579a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/254 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @077578c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/253 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @077577e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/252 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07757700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/251 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07757620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/250 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07757540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/249 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @07757460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/248 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @07757380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/247 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @077572a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/246 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @077571c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/245 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @077570e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/244 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @07757000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/243 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @07756ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/242 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07756e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/241 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07756d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/240 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @07756c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/239 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @07756b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/238 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @07756a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/237 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @077569a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/236 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @077568c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/235 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @077567e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/234 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @07756700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/233 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @07756620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/232 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @07756540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/231 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @07756460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/230 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @07756380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/229 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @077562a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/228 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @077561c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/227 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @077560e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/226 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @07756000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/225 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @07754d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/224 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07755ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/223 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @07755e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/222 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @07755d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/221 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @07755c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/220 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @07755b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/219 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @07755a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/218 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @077559a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/217 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @077558c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/216 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @077557e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/215 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @07755700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/214 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @07755620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/213 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @07755540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/212 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @07755460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/211 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @07755380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/210 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @077552a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/209 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @077551c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/208 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @077550e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/207 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @07755000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/206 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @07754ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/205 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @07754e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/204 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @07754c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/203 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @07754b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/202 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @07754a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/201 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @077549a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/200 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @077548c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/199 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @077547e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/198 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @07754620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/197 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @07754540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/196 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @07754460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/195 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @07754380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/194 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @077542a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/193 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @077541c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/192 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @077540e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/191 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07754000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/190 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07753ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/189 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @07753e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/188 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @07753d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/187 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @07753c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/186 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @07753b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/185 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @07753a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/184 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @077539a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/183 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @077538c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/182 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @077537e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/181 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @07753700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/180 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @07753620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/179 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @07753540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/178 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @07753460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/177 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @07753380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/176 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @077532a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/175 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @077531c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/174 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @077530e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/173 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07753000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/172 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07751ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/171 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07751e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/170 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @07751d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/169 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @07751c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/168 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @07751b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/167 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @07751a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/166 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @077519a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/165 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @077518c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/164 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @077517e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/163 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @07751700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/162 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @07751620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/161 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @07751540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/160 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @07751460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/159 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @07751380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/158 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @077512a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/157 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @077511c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/156 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @077510e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/155 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07751000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/154 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07750ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/153 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07750e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/152 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @07750d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/151 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @07750c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/150 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @07750b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/149 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @07750a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/148 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @077509a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/147 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @077508c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/146 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @077507e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/145 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07750700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/144 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @07750620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/143 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @07750540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/142 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @07750460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/141 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @07750380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/140 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @077502a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/139 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @077501c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/138 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @077500e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/137 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07750000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/136 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @0774fee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/135 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @0774fe00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/134 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @0774fd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/133 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @0774fc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/132 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @0774fb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/131 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @0774fa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/130 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @0774f9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/129 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @0774f8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/128 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @0774f7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/127 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @0774f700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/126 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @0774f620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/125 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @0774f540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/124 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @0774f460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/123 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @0774f380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/122 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @0774f2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/121 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @0774f1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/120 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @0774f0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/119 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @0774f000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/118 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @07748380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/117 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @0774eee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/116 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @0774ee00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/115 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @0774ed20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/114 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @0774ec40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/113 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @0774eb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/112 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @0774ea80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/111 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @0774e9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/110 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @0774e8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/109 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @0774e7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/108 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @0774e700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/107 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @0774e620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/106 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @0774e540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/105 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @0774e460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/104 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @0774e380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/103 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @0774e2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/102 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0774e1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/101 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0774e0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/100 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0774e000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/99 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @077480e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/98 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @07748ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/97 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @07748e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/96 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @07748d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/95 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @07748c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/94 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @07748b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_cfg_isr/93 (pfe_hif_chnl_cfg_isr) @077489a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_isr/26 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_get_emac_timer_ownership/92 (pfe_hif_chnl_get_emac_timer_ownership) @07748540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_timer_owner_hif_ids/14 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_cfg_get_emac_timer_ownership/364 (856416480 (estimated locally),0.80 per call) pfe_hif_nocpy_cfg_get_emac_timer_ownership/363 (217325345 (estimated locally),0.20 per call) 
pfe_hif_chnl_set_emac_timer_ownership/91 (pfe_hif_chnl_set_emac_timer_ownership) @077482a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_timer_owner_hif_ids/14 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_cfg_set_emac_timer_ownership/362 (856416480 (estimated locally),0.80 per call) pfe_hif_nocpy_cfg_set_emac_timer_ownership/361 (217325345 (estimated locally),0.20 per call) 
pfe_hif_chnl_get_lmem_hdr_size/90 (pfe_hif_chnl_get_lmem_hdr_size) @07748000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_set_lmem_hdr_size/89 (pfe_hif_chnl_set_lmem_hdr_size) @0773fb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_get_rx_cnt/88 (pfe_hif_chnl_get_rx_cnt) @0773f620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_cfg_get_rx_cnt/360 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_get_tx_cnt/87 (pfe_hif_chnl_get_tx_cnt) @0773fd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_cfg_get_tx_cnt/359 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_dump_ring/86 (pfe_hif_chnl_dump_ring) @0773fa80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_hif_ring_dump/358 (429497 (estimated locally),0.00 per call) pfe_hif_ring_dump/358 (429497 (estimated locally),0.00 per call) 
pfe_hif_chnl_destroy/85 (pfe_hif_chnl_destroy) @0773f7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_hif_chnl_destroy_rings/83 (0 (precise),0.00 per call) pfe_hif_chnl_destroy_inval_rx_ring.isra.0/368 (0 (precise),0.00 per call) pfe_hif_chnl_tx_irq_mask/46 (429497 (estimated locally),0.00 per call) pfe_hif_chnl_rx_irq_mask/44 (429497 (estimated locally),0.00 per call) pfe_hif_chnl_irq_mask/27 (429497 (estimated locally),0.00 per call) 
pfe_hif_chnl_destroy_rings/83 (pfe_hif_chnl_destroy_rings) @0773f2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_destroy/85 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_destroy_chnl/82 (0 (precise),0.00 per call) pfe_hif_ring_destroy/351 (0 (precise),0.00 per call) pfe_hif_chnl_cfg_is_tx_bdp_fifo_empty/357 (0 (precise),0.00 per call) pfe_hif_ring_destroy/351 (0 (precise),0.00 per call) pfe_hif_chnl_tx_disable/36 (0 (precise),0.00 per call) pfe_hif_chnl_rx_disable/38 (0 (precise),0.00 per call) 
pfe_hif_chnl_destroy_chnl/82 (pfe_hif_chnl_destroy_chnl) @0773f000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_destroy_rings/83 (0 (precise),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_fini/354 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_send_dummy_frame/81 (pfe_hif_chnl_send_dummy_frame) @07735b60
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_is_tx_dma_active/80 (pfe_hif_chnl_is_tx_dma_active) @077350e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: pfe_hif_chnl_cfg_is_tx_dma_active/353 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_is_rx_dma_active/79 (pfe_hif_chnl_is_rx_dma_active) @07735d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: pfe_hif_chnl_cfg_is_rx_dma_active/352 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_init/78 (pfe_hif_chnl_init) @07735a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:0 (precise) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_create_cfg/30 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_bind_bd_rings/76 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_ungraceful_reset/75 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_validate_bdr_setup/64 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) 
pfe_hif_chnl_rx_pool_init/77 (pfe_hif_chnl_rx_pool_init) @07735620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/308 (read)rx_buf_mem/17 (addr)rx_meta_buf_mem/20 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_create_mcal_aux.isra.0/397 (0 (precise),0.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/307 (225056286 (estimated locally),0.21 per call) pfe_hm_report/306 (225056286 (estimated locally),0.21 per call) 
pfe_hif_chnl_bind_bd_rings/76 (pfe_hif_chnl_bind_bd_rings) @077352a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_init/78 (0 (precise),0.00 per call) 
  Calls: pfe_hif_ring_destroy/351 (0 (precise),0.00 per call) pfe_hif_ring_destroy/351 (0 (precise),0.00 per call) pfe_hif_chnl_bind_rx_ring/61 (0 (precise),0.00 per call) pfe_hif_ring_destroy/351 (0 (precise),0.00 per call) pfe_hif_chnl_bind_tx_ring/62 (0 (precise),0.00 per call) 
pfe_hif_chnl_ungraceful_reset/75 (pfe_hif_chnl_ungraceful_reset) @07735000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_init/78 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) 
pfe_hif_chnl_tx_to_head/74 (pfe_hif_chnl_tx_to_head) @0772cd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dummy_tx_buf/18 (addr)
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_ungraceful_reset/75 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_disable_invalidate/73 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_ring_is_on_head/350 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_get_tx_conf/55 (0 (precise),0.00 per call) oal_time_usleep/344 (0 (precise),0.00 per call) pfe_hif_chnl_send_dummy_frame.constprop/400 (0 (precise),0.00 per call) pfe_hif_chnl_tx_enable/35 (0 (precise),0.00 per call) pfe_hif_chnl_rx_disable/38 (0 (precise),0.00 per call) pfe_hif_ring_get_len/323 (0 (precise),0.00 per call) 
pfe_hif_chnl_disable_invalidate/73 (pfe_hif_chnl_disable_invalidate) @0772c8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) 
  Calls: pfe_hif_ring_invalidate_direct/346 (0 (precise),0.00 per call) pfe_hif_chnl_tx_disable/36 (0 (precise),0.00 per call) pfe_hif_ring_get_len/323 (0 (precise),0.00 per call) 
pfe_hif_chnl_rx_to_head/72 (pfe_hif_chnl_rx_to_head) @0772c620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dummy_rx_buf/19 (addr)
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_ungraceful_reset/75 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_disable/40 (0 (precise),0.00 per call) pfe_hif_ring_invalidate_direct/346 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_ring_is_on_head/350 (0 (precise),0.00 per call) pfe_hif_chnl_do_tx_rx/71 (0 (precise),0.00 per call) oal_time_usleep/344 (0 (precise),0.00 per call) pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop/399 (0 (precise),0.00 per call) pfe_hif_chnl_enable/39 (0 (precise),0.00 per call) pfe_hif_ring_get_len/323 (0 (precise),0.00 per call) 
pfe_hif_chnl_do_tx_rx/71 (pfe_hif_chnl_do_tx_rx) @0772c2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/307 (177167401 (estimated locally),0.17 per call) pfe_hm_report/306 (177167401 (estimated locally),0.17 per call) pfe_hif_ring_dequeue_plain/325 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/307 (536870913 (estimated locally),0.50 per call) pfe_hm_report/306 (536870913 (estimated locally),0.50 per call) pfe_hif_chnl_get_tx_conf/55 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_find_rx/69 (pfe_hif_chnl_find_rx) @07720a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_ungraceful_reset/75 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_disable/40 (0 (precise),0.00 per call) pfe_hif_ring_force_index/347 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_ring_find_wb_entry/345 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (0 (precise),0.00 per call) pfe_hif_chnl_enable/39 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty/348 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_empty_cached_bd/68 (pfe_hif_chnl_empty_cached_bd) @07720700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dummy_tx_buf/18 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty/348 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_get_tx_conf/55 (0 (precise),0.00 per call) oal_time_usleep/344 (0 (precise),0.00 per call) pfe_hif_chnl_send_dummy_frame.constprop/400 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (1014686024 (estimated locally),0.95 per call) pfe_hm_report/306 (1014686024 (estimated locally),0.95 per call) pfe_hif_ring_get_len/323 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_cache_bd/67 (pfe_hif_chnl_cache_bd) @077202a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dummy_rx_buf/19 (addr)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) 
  Calls: pfe_hif_ring_invalidate_direct/346 (0 (precise),0.00 per call) pfe_hif_ring_force_index/347 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty/348 (0 (precise),0.00 per call) pfe_hif_chnl_bdp_fetch_bd/66 (0 (precise),0.00 per call) pfe_hif_ring_revalidate_direct/349 (0 (precise),0.00 per call) pfe_hif_ring_invalidate_direct/346 (0 (precise),0.00 per call) pfe_hif_ring_force_index/347 (0 (precise),0.00 per call) pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty/348 (0 (precise),0.00 per call) pfe_hif_chnl_bdp_fetch_bd/66 (0 (precise),0.00 per call) pfe_hif_ring_invalidate_direct/346 (459454908 (estimated locally),4.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (55807731 (estimated locally),0.49 per call) pfe_hm_report/306 (55807731 (estimated locally),0.49 per call) pfe_hif_chnl_supply_rx_buf/60 (1014686025 (estimated locally),8.83 per call) pfe_hif_ring_get_len/323 (114863532 (estimated locally),1.00 per call) 
pfe_hif_chnl_bdp_fetch_bd/66 (pfe_hif_chnl_bdp_fetch_bd) @07716e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) pfe_hif_chnl_cache_bd/67 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_rx_disable/38 (0 (precise),0.00 per call) oal_time_usleep/344 (0 (precise),0.00 per call) pfe_hif_chnl_rx_dma_start/41 (0 (precise),0.00 per call) pfe_hif_chnl_rx_enable/37 (0 (precise),0.00 per call) 
pfe_hif_chnl_find_tx/65 (pfe_hif_chnl_find_tx) @07716b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: dummy_tx_buf/18 (addr)
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_ungraceful_reset/75 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_tx_disable/36 (0 (precise),0.00 per call) pfe_hif_ring_force_index/347 (0 (precise),0.00 per call) pfe_hif_ring_invalidate_direct/346 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_ring_invalidate_direct/346 (0 (precise),0.00 per call) pfe_hif_ring_find_wb_entry/345 (0 (precise),0.00 per call) oal_time_usleep/344 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_send_dummy_frame.constprop/400 (0 (precise),0.00 per call) pfe_hif_chnl_tx_enable/35 (0 (precise),0.00 per call) pfe_hif_ring_get_len/323 (0 (precise),0.00 per call) 
pfe_hif_chnl_validate_bdr_setup/64 (pfe_hif_chnl_validate_bdr_setup) @07716700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_init/78 (0 (precise),0.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/307 (0 (estimated locally),0.00 per call) pfe_hm_report/306 (0 (estimated locally),0.00 per call) pfe_hif_ring_get_wb_tbl_pa/331 (0 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (172 (estimated locally),0.00 per call) pfe_hm_report/306 (172 (estimated locally),0.00 per call) pfe_hif_ring_get_base_pa/330 (172 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (429325 (estimated locally),0.00 per call) pfe_hm_report/306 (429325 (estimated locally),0.00 per call) pfe_hif_ring_get_wb_tbl_pa/331 (429497 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (1073312328 (estimated locally),1.00 per call) pfe_hm_report/306 (1073312328 (estimated locally),1.00 per call) pfe_hif_ring_get_base_pa/330 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_tx_wb_table_addr/340 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_tx_bd_ring_addr/338 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_rx_wb_table_addr/339 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_rx_bd_ring_addr/337 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_inspect_hw_state/63 (pfe_hif_chnl_inspect_hw_state) @077160e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:0 (precise) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_init/78 (0 (precise),0.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_ring_get_len/323 (0 (precise),0.00 per call) pfe_hif_ring_get_len/323 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_get_hw_state/21 (0 (precise),0.00 per call) pfe_hif_chnl_tx_disable/36 (0 (precise),0.00 per call) pfe_hif_chnl_rx_disable/38 (0 (precise),0.00 per call) 
pfe_hif_chnl_bind_tx_ring/62 (pfe_hif_chnl_bind_tx_ring) @0770c540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_bind_bd_rings/76 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_cfg_set_tx_wb_table/336 (127263 (estimated locally),0.00 per call) pfe_hif_ring_get_wb_tbl_len/333 (127263 (estimated locally),0.00 per call) pfe_hif_chnl_cfg_set_tx_bd_ring_addr/335 (318157219 (estimated locally),0.30 per call) oal_util_raise_dem_for_drv_runtime_err/307 (109629040 (estimated locally),0.10 per call) pfe_hm_report/306 (109629040 (estimated locally),0.10 per call) pfe_hif_ring_get_wb_tbl_pa/331 (1073741824 (estimated locally),1.00 per call) pfe_hif_ring_get_base_pa/330 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_bind_rx_ring/61 (pfe_hif_chnl_bind_rx_ring) @0770cee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_bind_bd_rings/76 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_cfg_set_rx_wb_table/334 (127263 (estimated locally),0.00 per call) pfe_hif_ring_get_wb_tbl_len/333 (127263 (estimated locally),0.00 per call) pfe_hif_chnl_cfg_set_rx_bd_ring_addr/332 (318157219 (estimated locally),0.30 per call) oal_util_raise_dem_for_drv_runtime_err/307 (109629040 (estimated locally),0.10 per call) pfe_hm_report/306 (109629040 (estimated locally),0.10 per call) pfe_hif_ring_get_wb_tbl_pa/331 (1073741824 (estimated locally),1.00 per call) pfe_hif_ring_get_base_pa/330 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_supply_rx_buf/60 (pfe_hif_chnl_supply_rx_buf) @0770cb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop/399 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cache_bd/67 (1014686025 (estimated locally),8.83 per call) pfe_hif_chnl_refill_rx_buffers/29 (930998585 (estimated locally),3.95 per call) 
  Calls: pfe_hif_ring_enqueue_buf/324 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_release_buf/59 (pfe_hif_chnl_release_buf) @0770c8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/308 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_ring_enqueue_buf/324 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (107374182 (estimated locally),0.10 per call) pfe_hm_report/306 (107374182 (estimated locally),0.10 per call) __builtin_expect/311 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_get_meta_size/58 (pfe_hif_chnl_get_meta_size) @0770c460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_rx_va/57 (pfe_hif_chnl_rx_va) @0770c1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body hot optimize_size
  Called by: 
  Calls: pfe_hif_ring_get_fill_level/322 (1073741823 (estimated locally),1.00 per call) rx_pool_get_meta_buf/25 (354334802 (estimated locally),0.33 per call) pfe_hif_chnl_add_vlan_tag.isra.0/367 (354334802 (estimated locally),0.33 per call) pfe_hif_ring_dequeue_buf/326 (1073741823 (estimated locally),1.00 per call) 
   Indirect call(375809638 (estimated locally),0.35 per call)  of param:0 loaded from aggregate passed by reference at offset 384 (vptr maybe changed)
pfe_hif_chnl_get_tx_conf/55 (pfe_hif_chnl_get_tx_conf) @076e0620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body hot optimize_size
  Called by: pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_empty_cached_bd/68 (0 (precise),0.00 per call) pfe_hif_chnl_do_tx_rx/71 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_ring_dequeue_plain/325 (1073741824 (estimated locally),9.35 per call) 
pfe_hif_chnl_tx/54 (pfe_hif_chnl_tx) @076e00e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: pfe_hif_chnl_send_dummy_frame.constprop/400 (1073634451 (estimated locally),1.00 per call) 
  Calls: pfe_hif_chnl_tx_dma_start/42 (217325345 (estimated locally),0.20 per call) pfe_hif_ring_enqueue_buf/324 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_get_tx_fifo_depth/53 (pfe_hif_chnl_get_tx_fifo_depth) @076e0d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_hif_ring_get_len/323 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_get_rx_fifo_depth/52 (pfe_hif_chnl_get_rx_fifo_depth) @076e0a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_hif_ring_get_len/323 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_tx_fifo_empty/51 (pfe_hif_chnl_tx_fifo_empty) @076e07e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: pfe_hif_ring_get_fill_level/322 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_can_accept_tx_num/50 (pfe_hif_chnl_can_accept_tx_num) @076e0540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: pfe_hif_ring_get_len/323 (1073741824 (estimated locally),1.00 per call) pfe_hif_ring_get_fill_level/322 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_can_accept_rx_buf/49 (pfe_hif_chnl_can_accept_rx_buf) @076e02a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: pfe_hif_chnl_refill_rx_buffers/29 (1073741824 (estimated locally),4.55 per call) 
  Calls: pfe_hif_ring_get_len/323 (1073741824 (estimated locally),1.00 per call) pfe_hif_ring_get_fill_level/322 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_has_tx_conf/48 (pfe_hif_chnl_has_tx_conf) @076e0000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: pfe_hif_ring_get_fill_level/322 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_tx_irq_unmask/47 (pfe_hif_chnl_tx_irq_unmask) @076ddb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_tx_irq_unmask/321 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_tx_irq_mask/46 (pfe_hif_chnl_tx_irq_mask) @076dd620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: pfe_hif_chnl_destroy/85 (429497 (estimated locally),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_tx_irq_mask/320 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_rx_irq_unmask/45 (pfe_hif_chnl_rx_irq_unmask) @076dd0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_rx_irq_unmask/319 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_rx_irq_mask/44 (pfe_hif_chnl_rx_irq_mask) @076ddd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: pfe_hif_chnl_destroy/85 (429497 (estimated locally),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_rx_irq_mask/318 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_set_event_cbk/43 (pfe_hif_chnl_set_event_cbk) @076dda80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_tx_dma_start/42 (pfe_hif_chnl_tx_dma_start) @076dd7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: pfe_hif_chnl_tx/54 (217325345 (estimated locally),0.20 per call) 
  Calls: pfe_hif_chnl_cfg_tx_dma_start/317 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_rx_dma_start/41 (pfe_hif_chnl_rx_dma_start) @076dd540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop/399 (429497 (estimated locally),0.00 per call) pfe_hif_chnl_bdp_fetch_bd/66 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_cfg_rx_dma_start/316 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_disable/40 (pfe_hif_chnl_disable) @076dd2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_rx_disable/38 (0 (precise),0.00 per call) pfe_hif_chnl_tx_disable/36 (0 (precise),0.00 per call) 
pfe_hif_chnl_enable/39 (pfe_hif_chnl_enable) @076dd000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_rx_to_head/72 (0 (precise),0.00 per call) pfe_hif_chnl_find_rx/69 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_rx_enable/37 (0 (precise),0.00 per call) pfe_hif_chnl_tx_enable/35 (0 (precise),0.00 per call) 
pfe_hif_chnl_rx_disable/38 (pfe_hif_chnl_rx_disable) @076d6b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_destroy_rings/83 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) pfe_hif_chnl_bdp_fetch_bd/66 (0 (precise),0.00 per call) pfe_hif_chnl_disable/40 (0 (precise),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_rx_disable/315 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_rx_enable/37 (pfe_hif_chnl_rx_enable) @076d6540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_bdp_fetch_bd/66 (0 (precise),0.00 per call) pfe_hif_chnl_enable/39 (0 (precise),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (872415233 (estimated locally),0.81 per call) pfe_hif_chnl_cfg_rx_enable/314 (872415233 (estimated locally),0.81 per call) oal_mutex_lock.part.0/365 (872415233 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/307 (201326592 (estimated locally),0.19 per call) pfe_hm_report/306 (201326592 (estimated locally),0.19 per call) 
pfe_hif_chnl_tx_disable/36 (pfe_hif_chnl_tx_disable) @076d6d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_destroy_rings/83 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) pfe_hif_chnl_disable/40 (0 (precise),0.00 per call) pfe_hif_chnl_disable_invalidate/73 (0 (precise),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_tx_disable/313 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_tx_enable/35 (pfe_hif_chnl_tx_enable) @076d6a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: pfe_hif_chnl_tx_to_head/74 (0 (precise),0.00 per call) pfe_hif_chnl_find_tx/65 (0 (precise),0.00 per call) pfe_hif_chnl_enable/39 (0 (precise),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (872415233 (estimated locally),0.81 per call) pfe_hif_chnl_cfg_tx_enable/312 (872415233 (estimated locally),0.81 per call) oal_mutex_lock.part.0/365 (872415233 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/307 (201326592 (estimated locally),0.19 per call) pfe_hm_report/306 (201326592 (estimated locally),0.19 per call) 
pfe_hif_chnl_get_id/34 (pfe_hif_chnl_get_id) @076d6700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_create_minihif/33 (pfe_hif_chnl_create_minihif) @076d6460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:0 (precise) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_hif_chnl_create_cfg/30 (0 (precise),0.00 per call) 
pfe_hif_chnl_create_mcal/32 (pfe_hif_chnl_create_mcal) @076d61c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_hif_chnl_create_mcal_aux.isra.0/397 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (177884489 (estimated locally),0.17 per call) pfe_hm_report/306 (177884489 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/307 (225056286 (estimated locally),0.21 per call) pfe_hm_report/306 (225056286 (estimated locally),0.21 per call) 
pfe_hif_chnl_create_cfg/30 (pfe_hif_chnl_create_cfg) @076a9c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_create_minihif/33 (0 (precise),0.00 per call) pfe_hif_chnl_create_mcal_aux.isra.0/397 (0 (precise),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (0 (precise),0.00 per call) pfe_hm_report/306 (0 (precise),0.00 per call) pfe_hif_chnl_init/78 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/307 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/306 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_init/310 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_refill_rx_buffers/29 (pfe_hif_chnl_refill_rx_buffers) @076a97e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/308 (read)
  Referring: 
  Availability: local
  Function flags: count:235843098 (estimated locally) body local hot optimize_size
  Called by: pfe_hif_chnl_create_mcal_aux.isra.0/397 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_can_accept_rx_buf/49 (1073741824 (estimated locally),4.55 per call) __builtin_expect/311 (930998585 (estimated locally),3.95 per call) pfe_hif_chnl_supply_rx_buf/60 (930998585 (estimated locally),3.95 per call) __builtin_expect/311 (1034442873 (estimated locally),4.39 per call) rx_pool_get/24 (1034442873 (estimated locally),4.39 per call) 
pfe_hif_chnl_irq_unmask/28 (pfe_hif_chnl_irq_unmask) @076a9460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_irq_unmask/305 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_irq_mask/27 (pfe_hif_chnl_irq_mask) @076a91c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_chnl_destroy/85 (429497 (estimated locally),0.00 per call) 
  Calls: oal_mutex_unlock.part.0/366 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_irq_mask/304 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_chnl_isr/26 (pfe_hif_chnl_isr) @076c1ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body hot optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/366 (1073741823 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_isr/93 (1073741823 (estimated locally),1.00 per call) oal_mutex_lock.part.0/365 (1073741823 (estimated locally),1.00 per call) 
   Indirect call(375809639 (estimated locally),0.35 per call)  of param:0 loaded from aggregate passed by reference at offset 320 (vptr maybe changed)
   Indirect call(375809638 (estimated locally),0.35 per call)  of param:0 loaded from aggregate passed by reference at offset 256 (vptr maybe changed)
rx_pool_get_meta_buf/25 (rx_pool_get_meta_buf) @076c18c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_chnl_rx_va/57 (354334802 (estimated locally),0.33 per call) 
  Calls: 
rx_pool_get/24 (rx_pool_get) @076c1e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_chnl_refill_rx_buffers/29 (1034442873 (estimated locally),4.39 per call) 
  Calls: 
pfe_hif_chnl_get_hw_state/21 (pfe_hif_chnl_get_hw_state) @076c1540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_chnl_inspect_hw_state/63 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_cfg_get_tx_wb_table_len/342 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_rx_wb_table_len/341 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_tx_wb_table_addr/340 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_rx_wb_table_addr/339 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_tx_bd_ring_addr/338 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_get_rx_bd_ring_addr/337 (1073741824 (estimated locally),1.00 per call) 
rx_meta_buf_mem/20 (rx_meta_buf_mem) @076b9240
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_hif_chnl_rx_pool_init/77 (addr)
  Availability: available
  Varpool flags:
dummy_rx_buf/19 (dummy_rx_buf) @076b91b0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_hif_chnl_cache_bd/67 (addr)pfe_hif_chnl_rx_to_head/72 (addr)pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop.0/399 (addr)
  Availability: available
  Varpool flags:
dummy_tx_buf/18 (dummy_tx_buf) @076b9120
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_hif_chnl_empty_cached_bd/68 (addr)pfe_hif_chnl_send_dummy_frame.constprop.0/400 (addr)pfe_hif_chnl_find_tx/65 (addr)pfe_hif_chnl_tx_to_head/74 (addr)pfe_hif_chnl_dummy_packet_to_self.isra.0.constprop.0/399 (addr)
  Availability: available
  Varpool flags:
rx_buf_mem/17 (rx_buf_mem) @076b9090
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_hif_chnl_rx_pool_init/77 (addr)
  Availability: available
  Varpool flags:
tx_rings_memory/16 (tx_rings_memory) @076b9000
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_hif_chnl_create_mcal_aux.isra.0/397 (addr)
  Availability: available
  Varpool flags:
rx_rings_memory/15 (rx_rings_memory) @075d2f30
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_hif_chnl_create_mcal_aux.isra.0/397 (addr)
  Availability: available
  Varpool flags:
pfe_timer_owner_hif_ids/14 (pfe_timer_owner_hif_ids) @075d2e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_hif_chnl_set_emac_timer_ownership/91 (read)pfe_hif_chnl_get_emac_timer_ownership/92 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06f9cca8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/199 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/200 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/201 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/202 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/203 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/204 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/205 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/206 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/207 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/208 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/209 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/210 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/211 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/212 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/213 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/214 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/215 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/216 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/217 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/218 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/219 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/220 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/221 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/222 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/223 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/224 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/225 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/226 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/227 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/228 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/229 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/230 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/231 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/232 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/233 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/234 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/235 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/236 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/237 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/238 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/239 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/240 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/241 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/242 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/243 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/244 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/245 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/246 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/247 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/248 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/249 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/250 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/251 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/252 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/253 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/254 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/255 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/256 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/257 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/258 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/259 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/260 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/261 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/262 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/263 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/264 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/265 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/266 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/267 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/268 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/269 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/270 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/271 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/272 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/273 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/274 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/275 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/276 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/277 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/278 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/279 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/280 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/281 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/282 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/283 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/284 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/285 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/286 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/287 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/288 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/289 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/290 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/291 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/292 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/293 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/294 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/295 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/296 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/297 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/298 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/299 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/300 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/301 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/302 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/303 (addr)
  Referring: oal_mutex_unlock.part.0/366 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06f9cbd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/94 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/95 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/96 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/97 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/98 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/99 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/100 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/101 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/102 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/103 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/104 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/105 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/106 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/107 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/108 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/109 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/110 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/111 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/112 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/113 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/114 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/115 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/116 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/117 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/118 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/119 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/120 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/121 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/122 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/123 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/124 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/125 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/126 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/127 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/128 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/129 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/130 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/131 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/132 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/133 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/134 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/135 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/136 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/137 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/138 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/139 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/140 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/141 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/142 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/143 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/144 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/145 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/146 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/147 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/148 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/149 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/150 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/151 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/152 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/153 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/154 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/155 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/156 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/157 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/158 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/159 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/160 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/161 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/162 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/163 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/164 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/165 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/166 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/167 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/168 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/169 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/170 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/171 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/172 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/173 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/174 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/175 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/176 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/177 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/178 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/179 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/180 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/181 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/182 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/183 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/184 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/185 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/186 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/187 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/188 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/189 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/190 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/191 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/192 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/193 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/194 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/195 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/196 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/197 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/198 (addr)
  Referring: oal_mutex_lock.part.0/365 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function oal_mutex_lock.part.0 (oal_mutex_lock.part.0, funcdef_no=84, decl_uid=10971, cgraph_uid=354, symbol_order=365)

Modification phase of node oal_mutex_lock.part.0/365
Adjusting mask for param 0 to 0x1f
Setting value range of param 0 [41, 54]
oal_mutex_lock.part.0 (const oal_mutex_t mutex)
{
  void (*<T4e6>) (void) _2;

  <bb 4> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[mutex_1(D)];
  _2 ();

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function oal_mutex_unlock.part.0 (oal_mutex_unlock.part.0, funcdef_no=85, decl_uid=10976, cgraph_uid=355, symbol_order=366)

Modification phase of node oal_mutex_unlock.part.0/366
Adjusting mask for param 0 to 0x1f
Setting value range of param 0 [41, 54]
oal_mutex_unlock.part.0 (const oal_mutex_t mutex)
{
  void (*<T4e6>) (void) _2;

  <bb 4> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[mutex_1(D)];
  _2 ();

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_chnl_isr (pfe_hif_chnl_isr, funcdef_no=17, decl_uid=9729, cgraph_uid=18, symbol_order=26) (hot)

Modification phase of node pfe_hif_chnl_isr/26
__attribute__((hot))
pfe_hif_chnl_isr (struct pfe_hif_chnl_t * chnl)
{
  pfe_hif_chnl_event_t events;
  errno_t ret;
  unsigned int _1;
  long unsigned int _2;
  <unnamed type> events.0_3;
  long unsigned int _4;
  void (*<Te3>) (void *) _5;
  void * _6;
  <unnamed type> events.1_7;
  long unsigned int _8;
  void (*<Te3>) (void *) _9;
  void * _10;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  events = 0;
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 41
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (41);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_15(D)->cbus_base_va;
  _2 = chnl_15(D)->id;
  ret_17 = pfe_hif_chnl_cfg_isr (_1, _2, &events);
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 41
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (41);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  events.0_3 = events;
  _4 = events.0_3 & 1;
  if (_4 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  _5 = chnl_15(D)->rx_cbk.cbk;
  if (_5 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _6 = chnl_15(D)->rx_cbk.arg;
  _5 (_6);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  events.1_7 = events;
  _8 = events.1_7 & 2;
  if (_8 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _9 = chnl_15(D)->tx_cbk.cbk;
  if (_9 != 0B)
    goto <bb 7>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 7> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  _10 = chnl_15(D)->tx_cbk.arg;
  _9 (_10);

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  events ={v} {CLOBBER};
  return ret_17;

}



;; Function pfe_hif_chnl_irq_mask (pfe_hif_chnl_irq_mask, funcdef_no=18, decl_uid=9740, cgraph_uid=19, symbol_order=27)

Modification phase of node pfe_hif_chnl_irq_mask/27
pfe_hif_chnl_irq_mask (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 42
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (42);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_irq_mask (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 42
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (42);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_irq_unmask (pfe_hif_chnl_irq_unmask, funcdef_no=19, decl_uid=9742, cgraph_uid=20, symbol_order=28)

Modification phase of node pfe_hif_chnl_irq_unmask/28
pfe_hif_chnl_irq_unmask (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 43
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (43);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_irq_unmask (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 43
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (43);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_get_id (pfe_hif_chnl_get_id, funcdef_no=25, decl_uid=9756, cgraph_uid=26, symbol_order=34) (unlikely executed)

Modification phase of node pfe_hif_chnl_get_id/34
__attribute__((cold, pure))
pfe_hif_chnl_get_id (const struct pfe_hif_chnl_t * chnl)
{
  uint32_t chnl_id;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  chnl_id_3 = chnl_2(D)->id;
  # DEBUG chnl_id => chnl_id_3
  # DEBUG BEGIN_STMT
  return chnl_id_3;

}



;; Function pfe_hif_chnl_tx_enable (pfe_hif_chnl_tx_enable, funcdef_no=26, decl_uid=9691, cgraph_uid=27, symbol_order=35) (unlikely executed)

Modification phase of node pfe_hif_chnl_tx_enable/35
__attribute__((cold))
pfe_hif_chnl_tx_enable (struct pfe_hif_chnl_t * chnl)
{
  errno_t ret;
  struct pfe_hif_ring_t * _1;
  unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_7(D)->tx_ring;
  if (_1 == 0B)
    goto <bb 3>; [18.75%]
  else
    goto <bb 4>; [81.25%]

  <bb 3> [local count: 201326592]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t enable TX: TX ring not set\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 830, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 45
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (45);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = chnl_7(D)->cbus_base_va;
  _3 = chnl_7(D)->id;
  pfe_hif_chnl_cfg_tx_enable (_2, _3);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 45
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (45);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_4 = PHI <117(3), 0(4)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_hif_chnl_tx_disable (pfe_hif_chnl_tx_disable, funcdef_no=27, decl_uid=9693, cgraph_uid=28, symbol_order=36) (unlikely executed)

Modification phase of node pfe_hif_chnl_tx_disable/36
__attribute__((cold))
pfe_hif_chnl_tx_disable (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 46
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (46);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_tx_disable (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 46
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (46);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_rx_enable (pfe_hif_chnl_rx_enable, funcdef_no=28, decl_uid=9659, cgraph_uid=29, symbol_order=37) (unlikely executed)

Modification phase of node pfe_hif_chnl_rx_enable/37
__attribute__((cold))
pfe_hif_chnl_rx_enable (struct pfe_hif_chnl_t * chnl)
{
  errno_t ret;
  struct pfe_hif_ring_t * _1;
  unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_7(D)->rx_ring;
  if (_1 == 0B)
    goto <bb 3>; [18.75%]
  else
    goto <bb 4>; [81.25%]

  <bb 3> [local count: 201326592]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t enable RX: RX ring not set\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 917, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 47
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (47);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = chnl_7(D)->cbus_base_va;
  _3 = chnl_7(D)->id;
  pfe_hif_chnl_cfg_rx_enable (_2, _3);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 47
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (47);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_4 = PHI <117(3), 0(4)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_hif_chnl_rx_disable (pfe_hif_chnl_rx_disable, funcdef_no=29, decl_uid=9661, cgraph_uid=30, symbol_order=38) (unlikely executed)

Modification phase of node pfe_hif_chnl_rx_disable/38
__attribute__((cold))
pfe_hif_chnl_rx_disable (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 48
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (48);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_rx_disable (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 48
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (48);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_rx_dma_start (pfe_hif_chnl_rx_dma_start, funcdef_no=32, decl_uid=9679, cgraph_uid=33, symbol_order=41) (hot)

Modification phase of node pfe_hif_chnl_rx_dma_start/41
__attribute__((hot))
pfe_hif_chnl_rx_dma_start (const struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_rx_dma_start (_1, _2);
  return;

}



;; Function pfe_hif_chnl_bdp_fetch_bd (pfe_hif_chnl_bdp_fetch_bd, funcdef_no=57, decl_uid=10376, cgraph_uid=58, symbol_order=66) (unlikely executed)

Modification phase of node pfe_hif_chnl_bdp_fetch_bd/66
__attribute__((cold))
pfe_hif_chnl_bdp_fetch_bd (struct pfe_hif_chnl_t * chnl)
{
  <bb 2> [count: 0]:
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_rx_enable (chnl_2(D));
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_rx_dma_start (chnl_2(D));
  # DEBUG BEGIN_STMT
  oal_time_usleep (500);
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_rx_disable (chnl_2(D));
  return;

}



;; Function pfe_hif_chnl_tx_dma_start (pfe_hif_chnl_tx_dma_start, funcdef_no=33, decl_uid=9701, cgraph_uid=34, symbol_order=42) (hot)

Modification phase of node pfe_hif_chnl_tx_dma_start/42
__attribute__((hot))
pfe_hif_chnl_tx_dma_start (const struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_tx_dma_start (_1, _2);
  return;

}



;; Function pfe_hif_chnl_set_event_cbk (pfe_hif_chnl_set_event_cbk, funcdef_no=34, decl_uid=9738, cgraph_uid=35, symbol_order=43)

Modification phase of node pfe_hif_chnl_set_event_cbk/43
pfe_hif_chnl_set_event_cbk (struct pfe_hif_chnl_t * chnl, pfe_hif_chnl_event_t event, void (*pfe_hif_chnl_cbk_t) (void *) cbk, void * arg)
{
  errno_t ret;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (event_3(D) == 2)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  chnl_5(D)->tx_cbk.arg = arg_6(D);
  # DEBUG BEGIN_STMT
  chnl_5(D)->tx_cbk.cbk = cbk_8(D);
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  if (event_3(D) == 1)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 240947665]:
  # DEBUG BEGIN_STMT
  chnl_5(D)->rx_cbk.arg = arg_6(D);
  # DEBUG BEGIN_STMT
  chnl_5(D)->rx_cbk.cbk = cbk_8(D);
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 467721938]:
  # DEBUG BEGIN_STMT
  if (event_3(D) == 4)
    goto <bb 7>; [48.89%]
  else
    goto <bb 8>; [51.11%]

  <bb 7> [local count: 228669255]:
  # DEBUG BEGIN_STMT
  chnl_5(D)->rx_oob_cbk.arg = arg_6(D);
  # DEBUG BEGIN_STMT
  chnl_5(D)->rx_oob_cbk.cbk = cbk_8(D);

  <bb 8> [local count: 1073741824]:
  # ret_1 = PHI <0(3), 0(5), 0(7), 22(6)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_hif_chnl_rx_irq_mask (pfe_hif_chnl_rx_irq_mask, funcdef_no=35, decl_uid=9744, cgraph_uid=36, symbol_order=44) (hot)

Modification phase of node pfe_hif_chnl_rx_irq_mask/44
__attribute__((hot))
pfe_hif_chnl_rx_irq_mask (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 49
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (49);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_rx_irq_mask (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 49
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (49);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_rx_irq_unmask (pfe_hif_chnl_rx_irq_unmask, funcdef_no=36, decl_uid=9746, cgraph_uid=37, symbol_order=45) (hot)

Modification phase of node pfe_hif_chnl_rx_irq_unmask/45
__attribute__((hot))
pfe_hif_chnl_rx_irq_unmask (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 50
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (50);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_rx_irq_unmask (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 50
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (50);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_tx_irq_mask (pfe_hif_chnl_tx_irq_mask, funcdef_no=37, decl_uid=9748, cgraph_uid=38, symbol_order=46) (hot)

Modification phase of node pfe_hif_chnl_tx_irq_mask/46
__attribute__((hot))
pfe_hif_chnl_tx_irq_mask (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 51
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (51);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_tx_irq_mask (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 51
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (51);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_tx_irq_unmask (pfe_hif_chnl_tx_irq_unmask, funcdef_no=38, decl_uid=9750, cgraph_uid=39, symbol_order=47) (hot)

Modification phase of node pfe_hif_chnl_tx_irq_unmask/47
__attribute__((hot))
pfe_hif_chnl_tx_irq_unmask (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 52
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (52);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_tx_irq_unmask (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 52
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (52);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_has_tx_conf (pfe_hif_chnl_has_tx_conf, funcdef_no=39, decl_uid=9708, cgraph_uid=40, symbol_order=48) (hot)

Modification phase of node pfe_hif_chnl_has_tx_conf/48
__attribute__((hot, pure))
pfe_hif_chnl_has_tx_conf (const struct pfe_hif_chnl_t * chnl)
{
  bool_t has_tx_conf;
  struct pfe_hif_ring_t * _1;
  long unsigned int _2;
  _Bool _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_5(D)->tx_ring;
  _2 = pfe_hif_ring_get_fill_level (_1);
  _3 = _2 != 0;
  has_tx_conf_6 = (bool_t) _3;
  # DEBUG has_tx_conf => has_tx_conf_6
  # DEBUG BEGIN_STMT
  return has_tx_conf_6;

}



;; Function pfe_hif_chnl_can_accept_rx_buf (pfe_hif_chnl_can_accept_rx_buf, funcdef_no=40, decl_uid=9681, cgraph_uid=41, symbol_order=49) (hot)

Modification phase of node pfe_hif_chnl_can_accept_rx_buf/49
__attribute__((hot, pure))
pfe_hif_chnl_can_accept_rx_buf (const struct pfe_hif_chnl_t * chnl)
{
  uint32_t ring_len;
  uint32_t fill_level;
  bool_t accept_rx;
  struct pfe_hif_ring_t * _1;
  long unsigned int _2;
  _Bool _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_5(D)->rx_ring;
  fill_level_6 = pfe_hif_ring_get_fill_level (_1);
  # DEBUG fill_level => fill_level_6
  # DEBUG BEGIN_STMT
  ring_len_7 = pfe_hif_ring_get_len (_1);
  # DEBUG ring_len => ring_len_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = ring_len_7 - fill_level_6;
  _3 = _2 > 1;
  accept_rx_8 = (bool_t) _3;
  # DEBUG accept_rx => accept_rx_8
  # DEBUG BEGIN_STMT
  return accept_rx_8;

}



;; Function pfe_hif_chnl_can_accept_tx_num (pfe_hif_chnl_can_accept_tx_num, funcdef_no=41, decl_uid=9704, cgraph_uid=42, symbol_order=50) (hot)

Modification phase of node pfe_hif_chnl_can_accept_tx_num/50
__attribute__((hot, pure))
pfe_hif_chnl_can_accept_tx_num (const struct pfe_hif_chnl_t * chnl, uint16_t number)
{
  uint32_t ring_len;
  uint32_t fill_level;
  bool_t accept_tx;
  struct pfe_hif_ring_t * _1;
  long unsigned int _2;
  long unsigned int _3;
  _Bool _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_6(D)->tx_ring;
  fill_level_7 = pfe_hif_ring_get_fill_level (_1);
  # DEBUG fill_level => fill_level_7
  # DEBUG BEGIN_STMT
  ring_len_8 = pfe_hif_ring_get_len (_1);
  # DEBUG ring_len => ring_len_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = ring_len_8 - fill_level_7;
  _3 = (long unsigned int) number_9(D);
  _4 = _2 > _3;
  accept_tx_10 = (bool_t) _4;
  # DEBUG accept_tx => accept_tx_10
  # DEBUG BEGIN_STMT
  return accept_tx_10;

}



;; Function pfe_hif_chnl_tx_fifo_empty (pfe_hif_chnl_tx_fifo_empty, funcdef_no=42, decl_uid=9706, cgraph_uid=43, symbol_order=51) (hot)

Modification phase of node pfe_hif_chnl_tx_fifo_empty/51
__attribute__((hot, pure))
pfe_hif_chnl_tx_fifo_empty (const struct pfe_hif_chnl_t * chnl)
{
  bool_t is_empty;
  struct pfe_hif_ring_t * _1;
  long unsigned int _2;
  _Bool _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_5(D)->tx_ring;
  _2 = pfe_hif_ring_get_fill_level (_1);
  _3 = _2 == 0;
  is_empty_6 = (bool_t) _3;
  # DEBUG is_empty => is_empty_6
  # DEBUG BEGIN_STMT
  return is_empty_6;

}



;; Function pfe_hif_chnl_get_rx_fifo_depth (pfe_hif_chnl_get_rx_fifo_depth, funcdef_no=43, decl_uid=9687, cgraph_uid=44, symbol_order=52) (unlikely executed)

Modification phase of node pfe_hif_chnl_get_rx_fifo_depth/52
__attribute__((cold, pure))
pfe_hif_chnl_get_rx_fifo_depth (const struct pfe_hif_chnl_t * chnl)
{
  uint32_t rx_fifo_depth;
  struct pfe_hif_ring_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_3(D)->rx_ring;
  rx_fifo_depth_4 = pfe_hif_ring_get_len (_1);
  # DEBUG rx_fifo_depth => rx_fifo_depth_4
  # DEBUG BEGIN_STMT
  return rx_fifo_depth_4;

}



;; Function pfe_hif_chnl_get_tx_fifo_depth (pfe_hif_chnl_get_tx_fifo_depth, funcdef_no=44, decl_uid=9712, cgraph_uid=45, symbol_order=53) (unlikely executed)

Modification phase of node pfe_hif_chnl_get_tx_fifo_depth/53
__attribute__((cold, pure))
pfe_hif_chnl_get_tx_fifo_depth (const struct pfe_hif_chnl_t * chnl)
{
  uint32_t tx_fifo_depth;
  struct pfe_hif_ring_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_3(D)->tx_ring;
  tx_fifo_depth_4 = pfe_hif_ring_get_len (_1);
  # DEBUG tx_fifo_depth => tx_fifo_depth_4
  # DEBUG BEGIN_STMT
  return tx_fifo_depth_4;

}



;; Function pfe_hif_chnl_tx (pfe_hif_chnl_tx, funcdef_no=45, decl_uid=9699, cgraph_uid=46, symbol_order=54) (hot)

Modification phase of node pfe_hif_chnl_tx/54
__attribute__((hot))
pfe_hif_chnl_tx (const struct pfe_hif_chnl_t * chnl, const void * buf_pa, const void * buf_va, uint32_t len, bool_t lifm)
{
  errno_t ret;
  struct pfe_hif_ring_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG chnl => chnl_4(D)
  # DEBUG INLINE_ENTRY NULL
  # DEBUG BEGIN_STMT
  # DEBUG lmem_header_size => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG chnl => NULL
  # DEBUG lmem_header_size => 0
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->tx_ring;
  ret_9 = pfe_hif_ring_enqueue_buf (_1, buf_pa_5(D), len_6(D), 0, lifm_7(D));
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  if (lifm_7(D) == 1)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_tx_dma_start (chnl_4(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return ret_9;

}



;; Function pfe_hif_chnl_send_dummy_frame.constprop (pfe_hif_chnl_send_dummy_frame.constprop.0, funcdef_no=90, decl_uid=11130, cgraph_uid=389, symbol_order=400) (unlikely executed)

Modification phase of node pfe_hif_chnl_send_dummy_frame.constprop/400
Adjusting mask for param 2 to 0x1
Setting value range of param 2 [0, 1]
__attribute__((cold))
pfe_hif_chnl_send_dummy_frame.constprop (struct pfe_hif_chnl_t * chnl, send_dummy_frame_mode_t mode)
{
  void * tx_buf_va;
  long unsigned int _3;
  unsigned char _4;
  long unsigned int _5;
  int _6;
  int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  int _18;

  <bb 8> [local count: 1073741824]:
  # DEBUG tx_buf_va => &dummy_tx_buf

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG tx_buf_pa => &dummy_tx_buf
  # DEBUG BEGIN_STMT
  # DEBUG tx_hdr => &dummy_tx_buf
  # DEBUG BEGIN_STMT
  switch (mode_1(D)) <default: <L2> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357878150]:
<L0>:
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_ct_hif_tx_hdr_t *)&dummy_tx_buf].e_phy_ifs = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_ct_hif_tx_hdr_t *)&dummy_tx_buf].flags = 0;
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357878150]:
<L1>:
  # DEBUG BEGIN_STMT
  _3 = chnl_2(D)->id;
  # DEBUG BEGIN_STMT
  _4 = (unsigned char) _3;
  _5 = _3 & 255;
  _6 = (int) _5;
  _7 = _6 + 6;
  _8 = 1 << _7;
  _9 = _8 >> 24;
  _10 = _8 >> 8;
  _11 = _10 & 65280;
  _12 = _9 | _11;
  _13 = _8 << 8;
  _14 = _13 & 16711680;
  _15 = _12 | _14;
  _16 = _8 << 24;
  _17 = _15 | _16;
  MEM[(struct pfe_ct_hif_tx_hdr_t *)&dummy_tx_buf].e_phy_ifs = _17;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_ct_hif_tx_hdr_t *)&dummy_tx_buf].flags = 192;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_ct_hif_tx_hdr_t *)&dummy_tx_buf].chid = _4;
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073634451]:
<L2>:
  # DEBUG BEGIN_STMT
  _18 = pfe_hif_chnl_tx (chnl_2(D), &dummy_tx_buf, &dummy_tx_buf, 80, 1);
  if (_18 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 354299369]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Dummy frame TX failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2825, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 7> [local count: 1073634451]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hif_chnl_get_tx_conf (pfe_hif_chnl_get_tx_conf, funcdef_no=46, decl_uid=9710, cgraph_uid=47, symbol_order=55) (hot)

Modification phase of node pfe_hif_chnl_get_tx_conf/55
__attribute__((hot))
pfe_hif_chnl_get_tx_conf (struct pfe_hif_chnl_t * chnl)
{
  errno_t ret;
  bool_t lifm;
  unsigned char lifm.9_1;
  struct pfe_hif_ring_t * _2;
  int _3;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  lifm = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 118
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  lifm.9_1 = lifm;
  if (lifm.9_1 == 1)
    goto <bb 5>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 958878293]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = chnl_8(D)->tx_ring;
  _3 = pfe_hif_ring_dequeue_plain (_2, &lifm);
  if (_3 == 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 5> [local count: 114863532]:
  # ret_4 = PHI <0(3), 118(4)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  lifm ={v} {CLOBBER};
  return ret_4;

}



;; Function pfe_hif_chnl_rx_va (pfe_hif_chnl_rx_va, funcdef_no=48, decl_uid=9672, cgraph_uid=49, symbol_order=57) (hot)

Modification phase of node pfe_hif_chnl_rx_va/57
__attribute__((hot))
pfe_hif_chnl_rx_va (struct pfe_hif_chnl_t * chnl, void * * buf_va, uint32_t * len, bool_t * lifm, void * * meta)
{
  uint32_t vlan_header;
  struct pfe_ct_hif_rx_hdr_t * hif_hdr_ptr;
  void * buf_pa;
  errno_t ret;
  struct pfe_hif_ring_t * _1;
  void * buf_pa.10_2;
  struct rx_pool_t * _3;
  void * _4;
  void * _5;
  struct pfe_hif_ring_t * _6;
  long unsigned int _7;
  void (*<Te3>) (void *) _8;
  void * _9;
  long unsigned int _32;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  buf_pa = 0B;
  # DEBUG BEGIN_STMT
  hif_hdr_ptr = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_16(D)->rx_ring;
  ret_20 = pfe_hif_ring_dequeue_buf (_1, &buf_pa, len_17(D), lifm_18(D));
  # DEBUG ret => ret_20
  # DEBUG BEGIN_STMT
  if (ret_20 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  buf_pa.10_2 = buf_pa;
  *buf_va_21(D) = buf_pa.10_2;
  # DEBUG BEGIN_STMT
  hif_hdr_ptr = buf_pa.10_2;
  # DEBUG BEGIN_STMT
  _32 = MEM[(long unsigned int *)chnl_16(D) + 4B];
  # DEBUG D#2 => chnl_16(D)
  ret_25 = pfe_hif_chnl_add_vlan_tag.isra.0 (_32, buf_va_21(D), &hif_hdr_ptr, &vlan_header);
  # DEBUG ret => ret_25
  # DEBUG BEGIN_STMT
  _3 = &chnl_16(D)->rx_pool;
  _4 = *buf_va_21(D);
  _5 = rx_pool_get_meta_buf (_3, _4);
  *meta_26(D) = _5;

  <bb 4> [local count: 1073741823]:
  # ret_10 = PHI <ret_20(2), ret_25(3)>
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  _6 = chnl_16(D)->rx_ring;
  _7 = pfe_hif_ring_get_fill_level (_6);
  if (_7 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  _8 = chnl_16(D)->rx_oob_cbk.cbk;
  if (_8 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 6> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _9 = chnl_16(D)->rx_oob_cbk.arg;
  _8 (_9);

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  buf_pa ={v} {CLOBBER};
  hif_hdr_ptr ={v} {CLOBBER};
  vlan_header ={v} {CLOBBER};
  return ret_10;

}



;; Function pfe_hif_chnl_get_meta_size (pfe_hif_chnl_get_meta_size, funcdef_no=49, decl_uid=9674, cgraph_uid=50, symbol_order=58) (unlikely executed)

Modification phase of node pfe_hif_chnl_get_meta_size/58
__attribute__((cold))
pfe_hif_chnl_get_meta_size (const struct pfe_hif_chnl_t * chnl)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG meta_size => 32
  # DEBUG BEGIN_STMT
  return 32;

}



;; Function pfe_hif_chnl_release_buf (pfe_hif_chnl_release_buf, funcdef_no=50, decl_uid=9677, cgraph_uid=51, symbol_order=59) (hot)

Modification phase of node pfe_hif_chnl_release_buf/59
__attribute__((hot))
pfe_hif_chnl_release_buf (struct pfe_hif_chnl_t * chnl, const void * buf_va)
{
  errno_t ret;
  _Bool _1;
  long int _2;
  long int _3;
  struct pfe_hif_ring_t * _4;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.13_5;
  const struct Eth_43_PFE_HifCfgType * _6;
  short unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG buf_pa => (addr_t) buf_va_10(D)
  # DEBUG BEGIN_STMT
  _1 = buf_va_10(D) == 0B;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] VA->PA conversion failed, origin buffer VA: v0x%p\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 1821, buf_va_10(D), "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 54
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (54);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _4 = chnl_14(D)->rx_ring;
  Eth_43_PFE_InternalCfgPtr.13_5 = Eth_43_PFE_InternalCfgPtr;
  _6 = Eth_43_PFE_InternalCfgPtr.13_5->pHif;
  _7 = _6->u16RxBufSize;
  _8 = (long unsigned int) _7;
  ret_16 = pfe_hif_ring_enqueue_buf (_4, buf_va_10(D), _8, 0, 1);
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 54
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (54);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_16;

}



;; Function pfe_hif_chnl_supply_rx_buf (pfe_hif_chnl_supply_rx_buf, funcdef_no=51, decl_uid=9685, cgraph_uid=52, symbol_order=60) (hot)

Modification phase of node pfe_hif_chnl_supply_rx_buf/60
__attribute__((hot))
pfe_hif_chnl_supply_rx_buf (const struct pfe_hif_chnl_t * chnl, const void * buf_pa, uint32_t size)
{
  errno_t ret;
  struct pfe_hif_ring_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = chnl_3(D)->rx_ring;
  ret_7 = pfe_hif_ring_enqueue_buf (_1, buf_pa_4(D), size_5(D), 0, 1);
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_hif_chnl_bind_rx_ring (pfe_hif_chnl_bind_rx_ring, funcdef_no=52, decl_uid=9689, cgraph_uid=53, symbol_order=61) (unlikely executed)

Modification phase of node pfe_hif_chnl_bind_rx_ring/61
__attribute__((cold))
pfe_hif_chnl_bind_rx_ring (struct pfe_hif_chnl_t * chnl)
{
  uint32_t wb_tbl_len;
  errno_t ret;
  const void * wb_tbl_pa;
  const void * rx_ring_pa;
  struct pfe_hif_ring_t * ring;
  unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ring_9 = chnl_8(D)->rx_ring;
  # DEBUG ring => ring_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG wb_tbl_len => 0
  # DEBUG BEGIN_STMT
  rx_ring_pa_10 = pfe_hif_ring_get_base_pa (ring_9);
  # DEBUG rx_ring_pa => rx_ring_pa_10
  # DEBUG BEGIN_STMT
  wb_tbl_pa_11 = pfe_hif_ring_get_wb_tbl_pa (ring_9);
  # DEBUG wb_tbl_pa => wb_tbl_pa_11
  # DEBUG BEGIN_STMT
  if (rx_ring_pa_10 == 0B)
    goto <bb 3>; [10.21%]
  else
    goto <bb 4>; [89.79%]

  <bb 3> [local count: 109629040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] RX ring physical address is NULL\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 1915, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 964112785]:
  # DEBUG BEGIN_STMT
  _1 = chnl_8(D)->cbus_base_va;
  if (_1 != 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 5> [local count: 318157219]:
  # DEBUG BEGIN_STMT
  _2 = chnl_8(D)->id;
  pfe_hif_chnl_cfg_set_rx_bd_ring_addr (_1, _2, rx_ring_pa_10);
  # DEBUG BEGIN_STMT
  if (wb_tbl_pa_11 != 0B)
    goto <bb 6>; [0.04%]
  else
    goto <bb 8>; [99.96%]

  <bb 6> [local count: 127263]:
  # DEBUG BEGIN_STMT
  wb_tbl_len_13 = pfe_hif_ring_get_wb_tbl_len (ring_9);
  # DEBUG wb_tbl_len => wb_tbl_len_13
  # DEBUG BEGIN_STMT
  _3 = chnl_8(D)->cbus_base_va;
  _4 = chnl_8(D)->id;
  pfe_hif_chnl_cfg_set_rx_wb_table (_3, _4, wb_tbl_pa_11, wb_tbl_len_13);

  <bb 8> [local count: 1073741824]:
  # ret_5 = PHI <117(3), 0(5), 0(4), 0(6)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_hif_chnl_bind_tx_ring (pfe_hif_chnl_bind_tx_ring, funcdef_no=53, decl_uid=9714, cgraph_uid=54, symbol_order=62) (unlikely executed)

Modification phase of node pfe_hif_chnl_bind_tx_ring/62
__attribute__((cold))
pfe_hif_chnl_bind_tx_ring (struct pfe_hif_chnl_t * chnl)
{
  uint32_t wb_tbl_len;
  errno_t ret;
  const void * wb_tbl_pa;
  const void * tx_ring_pa;
  struct pfe_hif_ring_t * ring;
  unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ring_9 = chnl_8(D)->tx_ring;
  # DEBUG ring => ring_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG wb_tbl_len => 0
  # DEBUG BEGIN_STMT
  tx_ring_pa_10 = pfe_hif_ring_get_base_pa (ring_9);
  # DEBUG tx_ring_pa => tx_ring_pa_10
  # DEBUG BEGIN_STMT
  wb_tbl_pa_11 = pfe_hif_ring_get_wb_tbl_pa (ring_9);
  # DEBUG wb_tbl_pa => wb_tbl_pa_11
  # DEBUG BEGIN_STMT
  if (tx_ring_pa_10 == 0B)
    goto <bb 3>; [10.21%]
  else
    goto <bb 4>; [89.79%]

  <bb 3> [local count: 109629040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] TX ring physical address is NULL\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 1980, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 964112785]:
  # DEBUG BEGIN_STMT
  _1 = chnl_8(D)->cbus_base_va;
  if (_1 != 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 5> [local count: 318157219]:
  # DEBUG BEGIN_STMT
  _2 = chnl_8(D)->id;
  pfe_hif_chnl_cfg_set_tx_bd_ring_addr (_1, _2, tx_ring_pa_10);
  # DEBUG BEGIN_STMT
  if (wb_tbl_pa_11 != 0B)
    goto <bb 6>; [0.04%]
  else
    goto <bb 8>; [99.96%]

  <bb 6> [local count: 127263]:
  # DEBUG BEGIN_STMT
  wb_tbl_len_13 = pfe_hif_ring_get_wb_tbl_len (ring_9);
  # DEBUG wb_tbl_len => wb_tbl_len_13
  # DEBUG BEGIN_STMT
  _3 = chnl_8(D)->cbus_base_va;
  _4 = chnl_8(D)->id;
  pfe_hif_chnl_cfg_set_tx_wb_table (_3, _4, wb_tbl_pa_11, wb_tbl_len_13);

  <bb 8> [local count: 1073741824]:
  # ret_5 = PHI <117(3), 0(5), 0(4), 0(6)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_hif_chnl_inspect_hw_state (pfe_hif_chnl_inspect_hw_state, funcdef_no=54, decl_uid=9785, cgraph_uid=55, symbol_order=63) (unlikely executed)

Modification phase of node pfe_hif_chnl_inspect_hw_state/63
pfe_hif_chnl_inspect_hw_state (struct pfe_hif_chnl_t * chnl)
{
  struct HifChnlHwStateType hws;
  errno_t ret;
  _Bool _1;
  _Bool _2;
  long unsigned int _3;
  struct pfe_hif_ring_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  struct pfe_hif_ring_t * _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  hws = {};
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_rx_disable (chnl_15(D));
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_tx_disable (chnl_15(D));
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_get_hw_state (chnl_15(D), &hws);
  # DEBUG BEGIN_STMT
  _1 = hws.is_all_addr_zero;
  if (_1 != 0)
    goto <bb 8>; [0.00%]
  else
    goto <bb 3>; [0.00%]

  <bb 3> [count: 0]:
  # DEBUG BEGIN_STMT
  _2 = hws.is_any_addr_zero;
  if (_2 != 0)
    goto <bb 4>; [0.00%]
  else
    goto <bb 5>; [0.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = chnl_15(D)->id;
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF%u has incomplete set-up. Ungraceful reset cannot be provided.\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2051, _3, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 8>; [0.00%]

  <bb 5> [count: 0]:
  # DEBUG BEGIN_STMT
  _4 = chnl_15(D)->rx_ring;
  _5 = pfe_hif_ring_get_len (_4);
  _6 = hws.rx_ring_len;
  if (_5 != _6)
    goto <bb 7>; [0.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 6> [count: 0]:
  _7 = chnl_15(D)->tx_ring;
  _8 = pfe_hif_ring_get_len (_7);
  _9 = hws.tx_ring_len;
  if (_8 != _9)
    goto <bb 7>; [0.00%]
  else
    goto <bb 8>; [0.00%]

  <bb 7> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = chnl_15(D)->id;
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF%u ring sizes differ from default. Ungraceful reset cannot be used\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2059, _10, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22

  <bb 8> [count: 0]:
  # ret_11 = PHI <0(2), 22(4), 22(7), 118(6)>
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  hws ={v} {CLOBBER};
  return ret_11;

}



;; Function pfe_hif_chnl_init (pfe_hif_chnl_init, funcdef_no=69, decl_uid=9727, cgraph_uid=70, symbol_order=78) (unlikely executed)

Modification phase of node pfe_hif_chnl_init/78
__attribute__((cold))
pfe_hif_chnl_init (struct pfe_hif_chnl_t * chnl)
{
  errno_t hw_status;
  errno_t ret;
  long unsigned int _1;
  unsigned char _2;
  int _3;

  <bb 2> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG hw_status => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_7(D)->id;
  if (_1 != 0)
    goto <bb 4>; [0.00%]
  else
    goto <bb 9>; [0.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  hw_status_9 = pfe_hif_chnl_inspect_hw_state (chnl_7(D));
  # DEBUG hw_status => hw_status_9
  # DEBUG BEGIN_STMT
  if (hw_status_9 == 118)
    goto <bb 5>; [0.00%]
  else
    goto <bb 9>; [0.00%]

  <bb 5> [count: 0]:
  # DEBUG BEGIN_STMT
  _2 = pfe_hif_chnl_validate_bdr_setup (chnl_7(D));
  if (_2 == 0)
    goto <bb 6>; [0.00%]
  else
    goto <bb 7>; [0.00%]

  <bb 6> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] BDR setup not valid\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2682, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 10>; [0.00%]

  <bb 7> [count: 0]:
  # DEBUG BEGIN_STMT
  _3 = pfe_hif_chnl_ungraceful_reset (chnl_7(D));
  if (_3 != 0)
    goto <bb 8>; [0.00%]
  else
    goto <bb 10>; [0.00%]

  <bb 8> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not perform ungraceful reset\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 2688, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 10>; [0.00%]

  <bb 9> [count: 0]:
  # DEBUG hw_status => NULL
  # DEBUG BEGIN_STMT
  ret_11 = pfe_hif_chnl_bind_bd_rings (chnl_7(D));
  # DEBUG ret => ret_11

  <bb 10> [count: 0]:
  # ret_4 = PHI <0(7), ret_11(9), 117(6), 117(8)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_hif_chnl_create_cfg (pfe_hif_chnl_create_cfg, funcdef_no=21, decl_uid=10093, cgraph_uid=22, symbol_order=30) (unlikely executed)

Modification phase of node pfe_hif_chnl_create_cfg/30
__attribute__((cold))
pfe_hif_chnl_create_cfg (struct pfe_hif_chnl_t * chnl)
{
  errno_t ret;
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 44
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (44);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_6(D)->cbus_base_va;
  _2 = chnl_6(D)->id;
  ret_8 = pfe_hif_chnl_cfg_init (_1, _2);
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  if (ret_8 != 0)
    goto <bb 3>; [100.00%]
  else
    goto <bb 4>; [0.00%]

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF channel cfg init failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 646, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  ret_10 = pfe_hif_chnl_init (chnl_6(D));
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  if (ret_10 != 0)
    goto <bb 5>; [0.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 5> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF channel init failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 653, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 6> [local count: 1073741824]:
  # ret_3 = PHI <ret_8(3), ret_10(4), ret_10(5)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 44
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (44);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_hif_chnl_create_mcal (pfe_hif_chnl_create_mcal, funcdef_no=23, decl_uid=9719, cgraph_uid=24, symbol_order=32) (unlikely executed)

Modification phase of node pfe_hif_chnl_create_mcal/32
__attribute__((cold))
pfe_hif_chnl_create_mcal (struct pfe_hif_chnl_t * chnl, addr_t cbus_base_va, uint32_t id, const struct pfe_bmu_t * bmu)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (id_3(D) > 999)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF NOCPY support is not enabled\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 742, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 19
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  if (id_3(D) > 3)
    goto <bb 5>; [20.96%]
  else
    goto <bb 6>; [79.04%]

  <bb 5> [local count: 177884489]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unsupported channel ID\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_chnl.c", 747, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 19
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 670801049]:
  # DEBUG BEGIN_STMT
  if (chnl_4(D) == 0B)
    goto <bb 8>; [100.00%]
  else
    goto <bb 7>; [0.00%]

  <bb 7> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG D#6 => bmu_7(D)
  ret_9 = pfe_hif_chnl_create_mcal_aux.isra.0 (chnl_4(D), cbus_base_va_6(D), id_3(D));
  # DEBUG ret => ret_9

  <bb 8> [local count: 1073741824]:
  # ret_1 = PHI <19(3), 19(5), 22(6), ret_9(7)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_hif_chnl_create_minihif (pfe_hif_chnl_create_minihif, funcdef_no=24, decl_uid=9725, cgraph_uid=25, symbol_order=33) (unlikely executed)

Modification phase of node pfe_hif_chnl_create_minihif/33
__attribute__((cold))
pfe_hif_chnl_create_minihif (struct pfe_hif_chnl_t * chnl, addr_t cbus_base_va, uint32_t id, struct pfe_hif_ring_t * rx_ring, struct pfe_hif_ring_t * tx_ring)
{
  errno_t _12;

  <bb 2> [count: 0]:
  # DEBUG BEGIN_STMT
  chnl_2(D)->cbus_base_va = cbus_base_va_3(D);
  # DEBUG BEGIN_STMT
  chnl_2(D)->id = id_5(D);
  # DEBUG BEGIN_STMT
  chnl_2(D)->rx_ring = rx_ring_7(D);
  # DEBUG BEGIN_STMT
  chnl_2(D)->tx_ring = tx_ring_9(D);
  # DEBUG BEGIN_STMT
  _12 = pfe_hif_chnl_create_cfg (chnl_2(D));
  return _12;

}



;; Function pfe_hif_chnl_is_rx_dma_active (pfe_hif_chnl_is_rx_dma_active, funcdef_no=70, decl_uid=9752, cgraph_uid=71, symbol_order=79) (hot)

Modification phase of node pfe_hif_chnl_is_rx_dma_active/79
__attribute__((hot))
pfe_hif_chnl_is_rx_dma_active (const struct pfe_hif_chnl_t * chnl)
{
  bool_t is_rx_active;
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  is_rx_active_6 = pfe_hif_chnl_cfg_is_rx_dma_active (_1, _2);
  # DEBUG is_rx_active => is_rx_active_6
  # DEBUG BEGIN_STMT
  return is_rx_active_6;

}



;; Function pfe_hif_chnl_is_tx_dma_active (pfe_hif_chnl_is_tx_dma_active, funcdef_no=71, decl_uid=9754, cgraph_uid=72, symbol_order=80) (hot)

Modification phase of node pfe_hif_chnl_is_tx_dma_active/80
__attribute__((hot))
pfe_hif_chnl_is_tx_dma_active (const struct pfe_hif_chnl_t * chnl)
{
  bool_t is_tx_active;
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  is_tx_active_6 = pfe_hif_chnl_cfg_is_tx_dma_active (_1, _2);
  # DEBUG is_tx_active => is_tx_active_6
  # DEBUG BEGIN_STMT
  return is_tx_active_6;

}



;; Function pfe_hif_chnl_destroy_chnl (pfe_hif_chnl_destroy_chnl, funcdef_no=73, decl_uid=9733, cgraph_uid=74, symbol_order=82) (unlikely executed)

Modification phase of node pfe_hif_chnl_destroy_chnl/82
__attribute__((cold))
pfe_hif_chnl_destroy_chnl (struct pfe_hif_chnl_t * chnl)
{
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 53
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (53);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  pfe_hif_chnl_cfg_fini (_1, _2);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 53
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (53);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_hif_chnl_destroy (pfe_hif_chnl_destroy, funcdef_no=76, decl_uid=9731, cgraph_uid=77, symbol_order=85) (unlikely executed)

Modification phase of node pfe_hif_chnl_destroy/85
__attribute__((cold))
pfe_hif_chnl_destroy (struct pfe_hif_chnl_t * chnl)
{
  struct pfe_hif_ring_t * _1;
  struct pfe_hif_ring_t * * _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (chnl_4(D) != 0B)
    goto <bb 3>; [0.04%]
  else
    goto <bb 6>; [99.96%]

  <bb 3> [local count: 429497]:
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_irq_mask (chnl_4(D));
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_rx_irq_mask (chnl_4(D));
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_tx_irq_mask (chnl_4(D));
  # DEBUG BEGIN_STMT
  chnl_4(D)->rx_cbk.cbk = 0B;
  # DEBUG BEGIN_STMT
  chnl_4(D)->tx_cbk.cbk = 0B;
  # DEBUG BEGIN_STMT
  chnl_4(D)->rx_oob_cbk.cbk = 0B;
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->rx_ring;
  if (_1 != 0B)
    goto <bb 4>; [0.00%]
  else
    goto <bb 5>; [0.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  _14 = &MEM[(struct pfe_hif_ring_t * *)chnl_4(D) + 8B];
  # DEBUG D#3 => chnl_4(D)
  pfe_hif_chnl_destroy_inval_rx_ring.isra.0 (_14);

  <bb 5> [count: 0]:
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_destroy_rings (chnl_4(D));

  <bb 6> [local count: 1073312328]:
  return;

}



;; Function pfe_hif_chnl_dump_ring (pfe_hif_chnl_dump_ring, funcdef_no=77, decl_uid=9760, cgraph_uid=78, symbol_order=86) (unlikely executed)

Modification phase of node pfe_hif_chnl_dump_ring/86
__attribute__((cold))
pfe_hif_chnl_dump_ring (const struct pfe_hif_chnl_t * chnl, bool_t dump_rx, bool_t dump_tx)
{
  struct pfe_hif_ring_t * _1;
  struct pfe_hif_ring_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (dump_rx_5(D) != 0)
    goto <bb 3>; [0.04%]
  else
    goto <bb 4>; [99.96%]

  <bb 3> [local count: 429497]:
  # DEBUG BEGIN_STMT
  _1 = chnl_7(D)->rx_ring;
  pfe_hif_ring_dump (_1, "RX");

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (dump_tx_9(D) != 0)
    goto <bb 5>; [0.04%]
  else
    goto <bb 6>; [99.96%]

  <bb 5> [local count: 429497]:
  # DEBUG BEGIN_STMT
  _2 = chnl_7(D)->tx_ring;
  pfe_hif_ring_dump (_2, "TX");

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function pfe_hif_chnl_get_tx_cnt (pfe_hif_chnl_get_tx_cnt, funcdef_no=78, decl_uid=9767, cgraph_uid=79, symbol_order=87)

Modification phase of node pfe_hif_chnl_get_tx_cnt/87
pfe_hif_chnl_get_tx_cnt (const struct pfe_hif_chnl_t * chnl)
{
  uint32_t tx_cnt;
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  tx_cnt_6 = pfe_hif_chnl_cfg_get_tx_cnt (_1, _2);
  # DEBUG tx_cnt => tx_cnt_6
  # DEBUG BEGIN_STMT
  return tx_cnt_6;

}



;; Function pfe_hif_chnl_get_rx_cnt (pfe_hif_chnl_get_rx_cnt, funcdef_no=79, decl_uid=9769, cgraph_uid=80, symbol_order=88)

Modification phase of node pfe_hif_chnl_get_rx_cnt/88
pfe_hif_chnl_get_rx_cnt (const struct pfe_hif_chnl_t * chnl)
{
  uint32_t rx_cnt;
  unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = chnl_4(D)->cbus_base_va;
  _2 = chnl_4(D)->id;
  rx_cnt_6 = pfe_hif_chnl_cfg_get_rx_cnt (_1, _2);
  # DEBUG rx_cnt => rx_cnt_6
  # DEBUG BEGIN_STMT
  return rx_cnt_6;

}



;; Function pfe_hif_chnl_set_lmem_hdr_size (pfe_hif_chnl_set_lmem_hdr_size, funcdef_no=80, decl_uid=9772, cgraph_uid=81, symbol_order=89)

Modification phase of node pfe_hif_chnl_set_lmem_hdr_size/89
pfe_hif_chnl_set_lmem_hdr_size (struct pfe_hif_chnl_t * chnl, uint16_t lmem_header_size)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_chnl_get_lmem_hdr_size (pfe_hif_chnl_get_lmem_hdr_size, funcdef_no=81, decl_uid=9774, cgraph_uid=82, symbol_order=90)

Modification phase of node pfe_hif_chnl_get_lmem_hdr_size/90
pfe_hif_chnl_get_lmem_hdr_size (const struct pfe_hif_chnl_t * chnl)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG lmem_header_size => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hif_chnl_set_emac_timer_ownership (pfe_hif_chnl_set_emac_timer_ownership, funcdef_no=82, decl_uid=9779, cgraph_uid=83, symbol_order=91)

Modification phase of node pfe_hif_chnl_set_emac_timer_ownership/91
pfe_hif_chnl_set_emac_timer_ownership (addr_t cbus_base_va, pfe_ct_phy_if_id_t hif_id, pfe_ct_phy_if_id_t emac, bool_t value)
{
  pfe_timer_owner_hif_id_t ret_val;
  errno_t ret;
  int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (hif_id_3(D) == 4)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  ret_12 = pfe_hif_nocpy_cfg_set_emac_timer_ownership (emac_7(D), value_8(D));
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 856416480]:
  # DEBUG BEGIN_STMT
  # DEBUG phy => hif_id_3(D)
  # DEBUG INLINE_ENTRY pfe_timer_owner_hif_from_phy_id
  # DEBUG BEGIN_STMT
  # DEBUG ret_val => 4
  # DEBUG BEGIN_STMT
  if (hif_id_3(D) <= 10)
    goto <bb 5>; [65.00%]
  else
    goto <bb 6>; [35.00%]

  <bb 5> [local count: 556670712]:
  # DEBUG BEGIN_STMT
  _5 = (int) hif_id_3(D);
  ret_val_13 = pfe_timer_owner_hif_ids[_5];
  # DEBUG ret_val => ret_val_13

  <bb 6> [local count: 856416480]:
  # ret_val_14 = PHI <4(4), ret_val_13(5)>
  # DEBUG ret_val => ret_val_14
  # DEBUG BEGIN_STMT
  # DEBUG phy => NULL
  # DEBUG ret_val => NULL
  ret_10 = pfe_hif_chnl_cfg_set_emac_timer_ownership (cbus_base_va_6(D), ret_val_14, emac_7(D), value_8(D));
  # DEBUG ret => ret_10

  <bb 7> [local count: 1073741824]:
  # ret_1 = PHI <ret_12(3), ret_10(6)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_hif_chnl_get_emac_timer_ownership (pfe_hif_chnl_get_emac_timer_ownership, funcdef_no=83, decl_uid=9783, cgraph_uid=84, symbol_order=92)

Modification phase of node pfe_hif_chnl_get_emac_timer_ownership/92
pfe_hif_chnl_get_emac_timer_ownership (addr_t cbus_base_va, pfe_ct_phy_if_id_t hif_id, pfe_ct_phy_if_id_t emac)
{
  pfe_timer_owner_hif_id_t ret_val;
  bool_t is_owner;
  int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG is_owner => 0
  # DEBUG BEGIN_STMT
  if (hif_id_3(D) == 4)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  is_owner_11 = pfe_hif_nocpy_cfg_get_emac_timer_ownership (emac_7(D));
  # DEBUG is_owner => is_owner_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 856416480]:
  # DEBUG BEGIN_STMT
  # DEBUG phy => hif_id_3(D)
  # DEBUG INLINE_ENTRY pfe_timer_owner_hif_from_phy_id
  # DEBUG BEGIN_STMT
  # DEBUG ret_val => 4
  # DEBUG BEGIN_STMT
  if (hif_id_3(D) <= 10)
    goto <bb 5>; [65.00%]
  else
    goto <bb 6>; [35.00%]

  <bb 5> [local count: 556670712]:
  # DEBUG BEGIN_STMT
  _5 = (int) hif_id_3(D);
  ret_val_12 = pfe_timer_owner_hif_ids[_5];
  # DEBUG ret_val => ret_val_12

  <bb 6> [local count: 856416480]:
  # ret_val_13 = PHI <4(4), ret_val_12(5)>
  # DEBUG ret_val => ret_val_13
  # DEBUG BEGIN_STMT
  # DEBUG phy => NULL
  # DEBUG ret_val => NULL
  is_owner_9 = pfe_hif_chnl_cfg_get_emac_timer_ownership (cbus_base_va_6(D), ret_val_13, emac_7(D));
  # DEBUG is_owner => is_owner_9

  <bb 7> [local count: 1073741824]:
  # is_owner_1 = PHI <is_owner_11(3), is_owner_9(6)>
  # DEBUG is_owner => is_owner_1
  # DEBUG BEGIN_STMT
  return is_owner_1;

}


