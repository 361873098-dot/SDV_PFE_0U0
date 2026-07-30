
IPA constant propagation start:
Determining dynamic type for call: pfe_hif_drv_destroy_data_channel (hif_drv_1(D));
  Starting walk at: pfe_hif_drv_destroy_data_channel (hif_drv_1(D));
  instance pointer: hif_drv_1(D)  Outer instance pointer: hif_drv_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_drv_stop (hif_drv_1(D));
Determining dynamic type for call: pfe_hif_drv_stop (hif_drv_1(D));
  Starting walk at: pfe_hif_drv_stop (hif_drv_1(D));
  instance pointer: hif_drv_1(D)  Outer instance pointer: hif_drv_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_5 = hif_client_create_rx_queues (client_tmp_4(D), _3);
  Starting walk at: err_5 = hif_client_create_rx_queues (client_tmp_4(D), _3);
  instance pointer: client_tmp_4(D)  Outer instance pointer: client_tmp_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_5 = hif_client_create_rx_queues (client_tmp_4(D), _3);
  Starting walk at: err_5 = hif_client_create_rx_queues (client_tmp_4(D), _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_10 = hif_client_create_tx_queues (client_tmp_4(D), _9);
  Starting walk at: err_10 = hif_client_create_tx_queues (client_tmp_4(D), _9);
  instance pointer: client_tmp_4(D)  Outer instance pointer: client_tmp_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_5 = hif_client_create_rx_queues (client_tmp_4(D), _3);
Determining dynamic type for call: err_10 = hif_client_create_tx_queues (client_tmp_4(D), _9);
  Starting walk at: err_10 = hif_client_create_tx_queues (client_tmp_4(D), _9);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_5 = hif_client_create_rx_queues (client_tmp_4(D), _3);
Determining dynamic type for call: _2 = pfe_hif_drv_process_tx (arg_1(D), 128);
  Starting walk at: _2 = pfe_hif_drv_process_tx (arg_1(D), 128);
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_drv_process_tx (arg_1(D), 128);
Determining dynamic type for call: _7 (client_20, _8, 1, qq_5);
  Starting walk at: _7 (client_20, _8, 1, qq_5);
  instance pointer: client_20  Outer instance pointer: &hif_drv_3(D)->clients[ii_4] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_7 (client_20, _8, 1, qq_5);
Determining dynamic type for call: _7 (client_20, _8, 1, qq_5);
  Starting walk at: _7 (client_20, _8, 1, qq_5);
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_7 (client_20, _8, 1, qq_5);
Determining dynamic type for call: pfe_hif_drv_show_rx_ring_status (cl_6);
  Starting walk at: pfe_hif_drv_show_rx_ring_status (cl_6);
  instance pointer: cl_6  Outer instance pointer: hif_drv_5(D) offset: 2048 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_drv_show_tx_ring_status (cl_6);
  Starting walk at: pfe_hif_drv_show_tx_ring_status (cl_6);
  instance pointer: cl_6  Outer instance pointer: hif_drv_5(D) offset: 2048 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_drv_show_rx_ring_status (cl_6);
Determining dynamic type for call: pfe_hif_drv_exit (hif_drv_2(D));
  Starting walk at: pfe_hif_drv_exit (hif_drv_2(D));
  instance pointer: hif_drv_2(D)  Outer instance pointer: hif_drv_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_drv_exit.part.0 (hif_drv_7(D));
  Starting walk at: pfe_hif_drv_exit.part.0 (hif_drv_7(D));
  instance pointer: hif_drv_7(D)  Outer instance pointer: hif_drv_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] A client is still registered within HIF\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2496, "");
Determining dynamic type for call: pfe_hif_drv_stop_rx (hif_drv_2(D));
  Starting walk at: pfe_hif_drv_stop_rx (hif_drv_2(D));
  instance pointer: hif_drv_2(D)  Outer instance pointer: hif_drv_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_drv_stop_tx (hif_drv_2(D));
  Starting walk at: pfe_hif_drv_stop_tx (hif_drv_2(D));
  instance pointer: hif_drv_2(D)  Outer instance pointer: hif_drv_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_drv_stop_rx (hif_drv_2(D));
Determining dynamic type for call: ret_9 = pfe_hif_drv_start.part.0 (hif_drv_4(D));
  Starting walk at: ret_9 = pfe_hif_drv_start.part.0 (hif_drv_4(D));
  instance pointer: hif_drv_4(D)  Outer instance pointer: hif_drv_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_hif_drv_create_data_channel (hif_drv_8(D));
  Starting walk at: _2 = pfe_hif_drv_create_data_channel (hif_drv_8(D));
  instance pointer: hif_drv_8(D)  Outer instance pointer: hif_drv_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_12 = pfe_hif_drv_attach_channels (hif_drv_8(D));
  Starting walk at: ret_12 = pfe_hif_drv_attach_channels (hif_drv_8(D));
  instance pointer: hif_drv_8(D)  Outer instance pointer: hif_drv_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_drv_create_data_channel (hif_drv_8(D));
Determining dynamic type for call: pfe_hif_drv_init_err_handler (hif_drv_8(D), 9);
  Starting walk at: pfe_hif_drv_init_err_handler (hif_drv_8(D), 9);
  instance pointer: hif_drv_8(D)  Outer instance pointer: hif_drv_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = oal_job_create (pfe_hif_drv_tx_job, hif_drv_8(D), "HIF TX JOB", 1, _3);
  Function call may change dynamic type:ret_12 = pfe_hif_drv_attach_channels (hif_drv_8(D));
  Function call may change dynamic type:_2 = pfe_hif_drv_create_data_channel (hif_drv_8(D));
Determining dynamic type for call: pfe_hif_drv_init_err_handler (hif_drv_7(D), 7);
  Starting walk at: pfe_hif_drv_init_err_handler (hif_drv_7(D), 7);
  instance pointer: hif_drv_7(D)  Outer instance pointer: hif_drv_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not register RX OOB handler\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2144, "");
  Function call may change dynamic type:ret_13 = pfe_hif_chnl_set_event_cbk (_3, 4, 0B, 0B);
  Function call may change dynamic type:ret_11 = pfe_hif_chnl_set_event_cbk (_2, 2, pfe_hif_drv_chnl_tx_isr, hif_drv_7(D));
  Function call may change dynamic type:ret_9 = pfe_hif_chnl_set_event_cbk (_1, 1, pfe_hif_drv_rx_job, hif_drv_7(D));
Determining dynamic type for call: pfe_hif_drv_init_err_handler (hif_drv_7(D), 6);
  Starting walk at: pfe_hif_drv_init_err_handler (hif_drv_7(D), 6);
  instance pointer: hif_drv_7(D)  Outer instance pointer: hif_drv_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not register TX ISR\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2133, "");
  Function call may change dynamic type:ret_11 = pfe_hif_chnl_set_event_cbk (_2, 2, pfe_hif_drv_chnl_tx_isr, hif_drv_7(D));
  Function call may change dynamic type:ret_9 = pfe_hif_chnl_set_event_cbk (_1, 1, pfe_hif_drv_rx_job, hif_drv_7(D));
Determining dynamic type for call: pfe_hif_drv_destroy_data_channel (hif_drv_7(D));
  Starting walk at: pfe_hif_drv_destroy_data_channel (hif_drv_7(D));
  instance pointer: hif_drv_7(D)  Outer instance pointer: hif_drv_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not register RX ISR\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2122, "");
  Function call may change dynamic type:ret_9 = pfe_hif_chnl_set_event_cbk (_1, 1, pfe_hif_drv_rx_job, hif_drv_7(D));
Determining dynamic type for call: pfe_hif_drv_destroy_data_channel (hif_drv_12(D));
  Starting walk at: pfe_hif_drv_destroy_data_channel (hif_drv_12(D));
  instance pointer: hif_drv_12(D)  Outer instance pointer: hif_drv_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_chnl_set_event_cbk (_1, 4, 0B, 0B);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] pfe_hif_chnl_set_event_cbk() failed (RX OOB callback)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2087, "");
  Function call may change dynamic type:_4 = pfe_hif_chnl_set_event_cbk (_3, 2, 0B, 0B);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] pfe_hif_chnl_set_event_cbk() failed (TX callback)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2096, "");
  Function call may change dynamic type:_6 = pfe_hif_chnl_set_event_cbk (_5, 1, 0B, 0B);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] pfe_hif_chnl_set_event_cbk() failed (RX callback)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2105, "");
Determining dynamic type for call: _15 = pfe_hif_drv_client_xmit_sg_pkt (client_11(D), queue_12(D), &sg_list, ref_ptr_13(D));
  Starting walk at: _15 = pfe_hif_drv_client_xmit_sg_pkt (client_11(D), queue_12(D), &sg_list, ref_ptr_13(D));
  instance pointer: client_11(D)  Outer instance pointer: client_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = pfe_hif_drv_client_xmit_sg_pkt (client_11(D), queue_12(D), &sg_list, ref_ptr_13(D));
  Starting walk at: _15 = pfe_hif_drv_client_xmit_sg_pkt (client_11(D), queue_12(D), &sg_list, ref_ptr_13(D));
  instance pointer: &sg_list  Outer instance pointer: sg_list offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = pfe_hif_drv_client_xmit_sg_pkt (client_11(D), queue_12(D), &sg_list, ref_ptr_13(D));
  Starting walk at: _15 = pfe_hif_drv_client_xmit_sg_pkt (client_11(D), queue_12(D), &sg_list, ref_ptr_13(D));
  instance pointer: ref_ptr_13(D)  Outer instance pointer: ref_ptr_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  Starting walk at: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  instance pointer: client_22(D)  Outer instance pointer: client_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (92);
Determining dynamic type for call: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  Starting walk at: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  instance pointer: tx_hdr_29  Outer instance pointer: tx_hdr_29 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (92);
Determining dynamic type for call: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  Starting walk at: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  instance pointer: tx_metadata_25  Outer instance pointer: &hif_drv_23->tx_meta[_12] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (92);
Determining dynamic type for call: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  Starting walk at: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  instance pointer: sg_list_24(D)  Outer instance pointer: sg_list_24(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (92);
Determining dynamic type for call: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  Starting walk at: pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  instance pointer: ref_ptr_31(D)  Outer instance pointer: ref_ptr_31(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (92);
Determining dynamic type for call: err_35 = pfe_hif_drv_client_transmit_packet_buffers (client_22(D), sg_list_24(D));
  Starting walk at: err_35 = pfe_hif_drv_client_transmit_packet_buffers (client_22(D), sg_list_24(D));
  instance pointer: client_22(D)  Outer instance pointer: client_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (92);
Determining dynamic type for call: err_35 = pfe_hif_drv_client_transmit_packet_buffers (client_22(D), sg_list_24(D));
  Starting walk at: err_35 = pfe_hif_drv_client_transmit_packet_buffers (client_22(D), sg_list_24(D));
  instance pointer: sg_list_24(D)  Outer instance pointer: sg_list_24(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (92);
Determining dynamic type for call: pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
  Starting walk at: pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
  instance pointer: hif_drv_29(D)  Outer instance pointer: hif_drv_29(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
Determining dynamic type for call: pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
  Starting walk at: pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
  instance pointer: client_33  Outer instance pointer: client_33 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
Determining dynamic type for call: pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
  Starting walk at: pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
  instance pointer: &tx_clients  Outer instance pointer: tx_clients offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
Determining dynamic type for call: pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
  Starting walk at: pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
  instance pointer: tx_metadata_32  Outer instance pointer: &hif_drv_29(D)->tx_meta[_3] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
Determining dynamic type for call: pfe_hif_drv_notify_clients.isra.0 (hif_drv_29(D), tx_clients.38_19);
  Starting walk at: pfe_hif_drv_notify_clients.isra.0 (hif_drv_29(D), tx_clients.38_19);
  instance pointer: hif_drv_29(D)  Outer instance pointer: hif_drv_29(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_tx_conf (_1);
  Function call may change dynamic type:pfe_hif_drv_put_data_to_tx_conf_queue (hif_drv_29(D), client_33, &tx_clients, tx_metadata_32);
Determining dynamic type for call: ret_21 = fifo_put (_3, _4);
  Starting walk at: ret_21 = fifo_put (_3, _4);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_21 = fifo_put (_3, _4);
  Starting walk at: ret_21 = fifo_put (_3, _4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_6 = fifo_get (_1);
  Starting walk at: ret_6 = fifo_get (_1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: release_rx_buffer_with_check (_2, _4);
  Starting walk at: release_rx_buffer_with_check (_2, _4);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: release_rx_buffer_with_check (_2, _4);
  Starting walk at: release_rx_buffer_with_check (_2, _4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_6 = fifo_get (_1);
  Starting walk at: ret_6 = fifo_get (_1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_drv_stop (_1);
  Starting walk at: pfe_hif_drv_stop (_1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: hif_client_free_rx_queues (client_10(D));
  Starting walk at: hif_client_free_rx_queues (client_10(D));
  instance pointer: client_10(D)  Outer instance pointer: client_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_drv_stop (_1);
Determining dynamic type for call: hif_client_free_tx_queues (client_10(D));
  Starting walk at: hif_client_free_tx_queues (client_10(D));
  instance pointer: client_10(D)  Outer instance pointer: client_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:hif_client_free_rx_queues (client_10(D));
  Function call may change dynamic type:pfe_hif_drv_stop (_1);
Determining dynamic type for call: pfe_hif_drv_start (_5);
  Starting walk at: pfe_hif_drv_start (_5);
  instance pointer: _5  Outer instance pointer: _5 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_ptp_ts_db_fini (_4);
  Function call may change dynamic type:hif_client_free_tx_queues (client_10(D));
  Function call may change dynamic type:hif_client_free_rx_queues (client_10(D));
  Function call may change dynamic type:pfe_hif_drv_stop (_1);
Determining dynamic type for call: err_32 = pfe_hif_drv_client_create_rx_tx.isra.0 (client_19(D), _36);
  Starting walk at: err_32 = pfe_hif_drv_client_create_rx_tx.isra.0 (client_19(D), _36);
  instance pointer: client_19(D)  Outer instance pointer: client_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (client_19(D), 0, 1792);
Determining dynamic type for call: err_32 = pfe_hif_drv_client_create_rx_tx.isra.0 (client_19(D), _36);
  Starting walk at: err_32 = pfe_hif_drv_client_create_rx_tx.isra.0 (client_19(D), _36);
  instance pointer: _36  Outer instance pointer: _36 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (client_19(D), 0, 1792);
Determining dynamic type for call: pfe_hif_drv_client_unregister (client_19(D));
  Starting walk at: pfe_hif_drv_client_unregister (client_19(D));
  instance pointer: client_19(D)  Outer instance pointer: client_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_32 = pfe_hif_drv_client_create_rx_tx.isra.0 (client_19(D), _36);
  Function call may change dynamic type:autolibc_memset (client_19(D), 0, 1792);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Client already initialized\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1232, "");
Determining dynamic type for call: client_22 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  Starting walk at: client_22 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  instance pointer: client_20  Outer instance pointer: &hif_drv_6(D)->clients[_2] offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: client_22 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  Starting walk at: client_22 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  instance pointer: &client_data  Outer instance pointer: client_data offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: client_18 = pfe_hif_drv_client_register_ll (client_16, &client_data);
  Starting walk at: client_18 = pfe_hif_drv_client_register_ll (client_16, &client_data);
  instance pointer: client_16  Outer instance pointer: hif_drv_4(D) offset: 159744 (bits) vtbl reference: 
Determining dynamic type for call: client_18 = pfe_hif_drv_client_register_ll (client_16, &client_data);
  Starting walk at: client_18 = pfe_hif_drv_client_register_ll (client_16, &client_data);
  instance pointer: &client_data  Outer instance pointer: client_data offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: client_24 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  Starting walk at: client_24 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  instance pointer: client_20  Outer instance pointer: hif_drv_6(D) offset: 145408 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = fifo_create (8, &ihc_client_fifos.tx_conf_fifo, &ihc_client_fifos.tx_conf_fifo_data);
  Function call may change dynamic type:_1 = fifo_create (8, &ihc_client_fifos.rx_fifo, &ihc_client_fifos.rx_fifo_data);
Determining dynamic type for call: client_24 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  Starting walk at: client_24 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  instance pointer: &client_data  Outer instance pointer: client_data offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = fifo_create (8, &ihc_client_fifos.tx_conf_fifo, &ihc_client_fifos.tx_conf_fifo_data);
  Function call may change dynamic type:_1 = fifo_create (8, &ihc_client_fifos.rx_fifo, &ihc_client_fifos.rx_fifo_data);
Determining dynamic type for call: pkt_16 = fifo_get (_1);
  Starting walk at: pkt_16 = fifo_get (_1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fifo_destroy (_6);
  Function call may change dynamic type:pkt_16 = fifo_get (_1);
  Function call may change dynamic type:pkt_21 = fifo_get (_5);
  Function call may change dynamic type:pfe_hif_pkt_free (pkt_9);
Determining dynamic type for call: pfe_hif_pkt_free (pkt_9);
  Starting walk at: pfe_hif_pkt_free (pkt_9);
  instance pointer: pkt_9  Outer instance pointer: pkt_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_16 = fifo_get (_1);
  Function call may change dynamic type:fifo_destroy (_6);
  Function call may change dynamic type:pkt_21 = fifo_get (_5);
  Function call may change dynamic type:pfe_hif_pkt_free (pkt_9);
Determining dynamic type for call: pkt_21 = fifo_get (_5);
  Starting walk at: pkt_21 = fifo_get (_5);
  instance pointer: _5  Outer instance pointer: _5 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_pkt_free (pkt_9);
  Function call may change dynamic type:pkt_16 = fifo_get (_1);
  Function call may change dynamic type:fifo_destroy (_6);
  Function call may change dynamic type:pkt_21 = fifo_get (_5);
  Function call may change dynamic type:pfe_hif_pkt_free (pkt_9);
Determining dynamic type for call: _5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Starting walk at: _5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  instance pointer: &hif_drv  Outer instance pointer: hif_drv offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: _9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Starting walk at: _9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  instance pointer: hif_drv.4_8  Outer instance pointer: hif_drv.4_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: _9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Starting walk at: _9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  instance pointer: hif_hdr_ptr_58  Outer instance pointer: hif_hdr_ptr_58 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
  Starting walk at: pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
  instance pointer: hif_hdr_ptr_58  Outer instance pointer: hif_hdr_ptr_58 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
  Starting walk at: pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
  Starting walk at: pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
  instance pointer: current_buffer_va.14_29  Outer instance pointer: current_buffer_va.14_29 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: ret_71 = fifo_put (_41, rx_metadata_63);
  Starting walk at: ret_71 = fifo_put (_41, rx_metadata_63);
  instance pointer: _41  Outer instance pointer: _41 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: ret_71 = fifo_put (_41, rx_metadata_63);
  Starting walk at: ret_71 = fifo_put (_41, rx_metadata_63);
  instance pointer: rx_metadata_63  Outer instance pointer: rx_metadata_63 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Starting walk at: release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  instance pointer: hif_drv.23_45  Outer instance pointer: hif_drv.23_45 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Starting walk at: release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  instance pointer: current_buffer_va.24_46  Outer instance pointer: current_buffer_va.24_46 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Starting walk at: pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  instance pointer: &client  Outer instance pointer: client offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Starting walk at: pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  instance pointer: current_buffer_va.8_19  Outer instance pointer: current_buffer_va.8_19 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Starting walk at: release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  instance pointer: hif_drv.9_20  Outer instance pointer: hif_drv.9_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Starting walk at: release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  instance pointer: current_buffer_va.10_21  Outer instance pointer: current_buffer_va.10_21 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Starting walk at: release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  instance pointer: hif_drv.6_15  Outer instance pointer: hif_drv.6_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Starting walk at: release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  instance pointer: current_buffer_va.7_16  Outer instance pointer: current_buffer_va.7_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Starting walk at: release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  instance pointer: hif_drv.2_6  Outer instance pointer: hif_drv.2_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Starting walk at: release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  instance pointer: current_buffer_va.3_7  Outer instance pointer: current_buffer_va.3_7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: pfe_hif_drv_notify_rx_clients (rx_clients_28, hif_drv.29_52);
  Starting walk at: pfe_hif_drv_notify_rx_clients (rx_clients_28, hif_drv.29_52);
  instance pointer: hif_drv.29_52  Outer instance pointer: hif_drv.29_52 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.6_15, current_buffer_va.7_16);
  Function call may change dynamic type:_9 = pfe_hif_drv_assign_client (hif_drv.4_8, hif_hdr_ptr_58);
  Function call may change dynamic type:_5 = pfe_hif_drv_process_lifm (lifm.1_4, &hif_drv);
  Function call may change dynamic type:_3 = pfe_hif_chnl_rx_va (_2, &current_buffer_va, &rx_len, &lifm, &meta_va);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.2_6, current_buffer_va.3_7);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.9_20, current_buffer_va.10_21);
  Function call may change dynamic type:pfe_hif_drv_process_ets (&client, current_buffer_va.8_19);
  Function call may change dynamic type:release_rx_buffer_with_check (hif_drv.23_45, current_buffer_va.24_46);
  Function call may change dynamic type:ret_71 = fifo_put (_41, rx_metadata_63);
  Function call may change dynamic type:pfe_hif_drv_process_ts (rx_len.12_27, hif_hdr_ptr_58, _9, current_buffer_va.14_29);
Determining dynamic type for call: _2 (client_11, _3, 0, 0);
  Starting walk at: _2 (client_11, _3, 0, 0);
  instance pointer: client_11  Outer instance pointer: &hif_drv_10(D)->clients[ii_5] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 (client_11, _3, 0, 0);
Determining dynamic type for call: _2 (client_11, _3, 0, 0);
  Starting walk at: _2 (client_11, _3, 0, 0);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 (client_11, _3, 0, 0);
Determining dynamic type for call: _15 (_13, _16, 2, qq_18);
  Starting walk at: _15 (_13, _16, 2, qq_18);
  instance pointer: _13  Outer instance pointer: _13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = pfe_hif_ptp_ts_db_push_ts (_4, 0, _7, _8, _9);
  Function call may change dynamic type:_15 (_13, _16, 2, qq_18);
Determining dynamic type for call: _15 (_13, _16, 2, qq_18);
  Starting walk at: _15 (_13, _16, 2, qq_18);
  instance pointer: _16  Outer instance pointer: _16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = pfe_hif_ptp_ts_db_push_ts (_4, 0, _7, _8, _9);
  Function call may change dynamic type:_15 (_13, _16, 2, qq_18);
Determining dynamic type for call: pfe_hif_drv_destroy_data_channel (hif_drv_11(D));
  Starting walk at: pfe_hif_drv_destroy_data_channel (hif_drv_11(D));
  instance pointer: hif_drv_11(D)  Outer instance pointer: hif_drv_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Metadata storage size (%u) is less than required (%u)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 411, _4, 21, "");
  Function call may change dynamic type:_4 = pfe_hif_chnl_get_meta_size (_3);
  Function call may change dynamic type:_2 = pfe_hif_chnl_get_meta_size (_1);
Determining dynamic type for call: pfe_hif_drv_tx_job.part.0 (arg_5(D));
  Starting walk at: pfe_hif_drv_tx_job.part.0 (arg_5(D));
  instance pointer: arg_5(D)  Outer instance pointer: arg_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (91);
Determining dynamic type for call: pfe_hif_drv_process_rx (arg_8(D));
  Starting walk at: pfe_hif_drv_process_rx (arg_8(D));
  instance pointer: arg_8(D)  Outer instance pointer: arg_8(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_hif_drv_exit.part.0/350:
    callsite  pfe_hif_drv_exit.part.0/350 -> pfe_hif_drv_stop/77 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_exit.part.0/350 -> pfe_hif_drv_destroy_data_channel/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_start.part.0/349:
  Jump functions of caller  pfe_hif_drv_chnl_tx_isr.part.0/348:
  Jump functions of caller  pfe_hif_drv_cfg_IEEE1588.isra.0/345:
  Jump functions of caller  pfe_hif_drv_client_create_rx_tx.isra.0/344:
    callsite  pfe_hif_drv_client_create_rx_tx.isra.0/344 -> hif_client_create_tx_queues/47 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_client_create_rx_tx.isra.0/344 -> hif_client_create_rx_queues/46 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_tx_job.part.0/343:
    callsite  pfe_hif_drv_tx_job.part.0/343 -> pfe_hif_drv_process_tx/62 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 128
         value: 0x80, mask: 0x0
         Unknown VR
    callsite  pfe_hif_drv_tx_job.part.0/343 -> oal_mutex_unlock.part.0/339 : 
       param 0: CONST: 91
         value: 0x5b, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_drv_notify_clients.isra.0/340:
    indirect simple callsite, calling param -1, offset 0, for stmt _7 (client_20, _8, 1, qq_5);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [0, 8]
  Jump functions of caller  oal_mutex_unlock.part.0/339:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  oal_mutex_lock.part.0/338:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  fifo_peek/337:
  Jump functions of caller  pfe_hif_chnl_tx_irq_mask/336:
  Jump functions of caller  oal_job_drain/335:
  Jump functions of caller  pfe_hif_chnl_is_tx_dma_active/334:
  Jump functions of caller  pfe_hif_chnl_rx_irq_mask/333:
  Jump functions of caller  oal_time_usleep/332:
  Jump functions of caller  pfe_hif_chnl_is_rx_dma_active/331:
  Jump functions of caller  pfe_hif_chnl_tx_enable/330:
  Jump functions of caller  pfe_hif_chnl_rx_enable/329:
  Jump functions of caller  oal_job_run/328:
  Jump functions of caller  pfe_hif_chnl_set_event_cbk/327:
  Jump functions of caller  pfe_hif_chnl_tx_disable/326:
  Jump functions of caller  pfe_hif_chnl_rx_disable/325:
  Jump functions of caller  pfe_hif_chnl_get_tx_fifo_depth/324:
  Jump functions of caller  oal_job_create/323:
  Jump functions of caller  pfe_hif_chnl_get_meta_size/321:
  Jump functions of caller  pfe_hif_ptp_ts_db_pop/320:
  Jump functions of caller  pfe_hif_chnl_tx/319:
  Jump functions of caller  Eth_PFE_LLD_GetTxBufTsRef/318:
  Jump functions of caller  Eth_PFE_LLD_GetTxBufMeta/317:
  Jump functions of caller  pfe_hif_chnl_can_accept_tx_num/316:
  Jump functions of caller  pfe_hif_chnl_get_id/315:
  Jump functions of caller  fifo_get_fill_level/314:
  Jump functions of caller  fifo_destroy/313:
  Jump functions of caller  pfe_hif_ptp_ts_db_fini/312:
  Jump functions of caller  pfe_hif_ptp_ts_db_init/311:
  Jump functions of caller  autolibc_memset/310:
  Jump functions of caller  fifo_create/309:
  Jump functions of caller  pfe_hif_ptp_ts_db_tick_iteration/308:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/307:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/306:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/305:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/304:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/303:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/302:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/301:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/300:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/299:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/298:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/297:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/296:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/295:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/294:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/293:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/292:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/291:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/290:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/289:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/288:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/287:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/286:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/285:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/284:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/283:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/282:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/281:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/280:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/279:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/278:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/277:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/276:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/275:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/274:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/273:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/272:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/271:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/270:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/269:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/268:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/267:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/266:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/265:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/264:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/263:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/262:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/261:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/260:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/259:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/258:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/257:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/256:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/255:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/254:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/253:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/252:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/251:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/250:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/249:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/248:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/247:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/246:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/245:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/244:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/243:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/242:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/241:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/240:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/239:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/238:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/237:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/236:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/235:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/234:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/233:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/232:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/231:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/230:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/229:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/228:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/227:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/226:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/225:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/224:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/223:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/222:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/221:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/220:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/219:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/218:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/217:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/216:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/215:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/214:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/213:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/212:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/211:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/210:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/209:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/208:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/207:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/206:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/205:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/204:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/203:
  Jump functions of caller  pfe_hif_chnl_get_tx_conf/202:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/201:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/200:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/199:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/198:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/197:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/196:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/195:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/194:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/193:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/192:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/191:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/190:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/189:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/188:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/187:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/186:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/185:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/184:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/183:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/182:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/181:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/180:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/179:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/178:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/177:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/176:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/175:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/174:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/173:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/172:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/171:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/170:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/169:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/168:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/167:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/166:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/165:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/164:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/163:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/162:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/161:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/160:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/159:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/158:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/157:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/156:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/155:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/154:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/153:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/152:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/151:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/150:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/149:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/148:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/147:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/146:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/145:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/144:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/143:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/142:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/141:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/140:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/139:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/138:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/137:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/136:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/135:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/134:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/133:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/132:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/131:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/130:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/129:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/128:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/127:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/126:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/125:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/124:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/123:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/122:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/121:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/120:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/119:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/118:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/117:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/116:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/115:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/114:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/113:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/112:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/111:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/110:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/109:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/108:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/107:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/106:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/105:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/104:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/103:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/102:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/101:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/100:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/99:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/98:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/97:
  Jump functions of caller  pfe_hif_chnl_tx_dma_start/96:
  Jump functions of caller  pfe_hif_chnl_tx_irq_unmask/95:
  Jump functions of caller  pfe_hif_chnl_release_buf/94:
  Jump functions of caller  pfe_hif_ptp_ts_db_push_msg/93:
  Jump functions of caller  oal_util_parse_ptp/92:
  Jump functions of caller  oal_util_get_unique_seqnum32/91:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/90:
  Jump functions of caller  pfe_hm_report/89:
  Jump functions of caller  pfe_hif_ptp_ts_db_push_ts/88:
  Jump functions of caller  pfe_hif_chnl_rx_va/87:
  Jump functions of caller  pfe_hif_chnl_rx_dma_start/86:
  Jump functions of caller  pfe_hif_chnl_rx_irq_unmask/85:
  Jump functions of caller  __builtin_expect/84:
  Jump functions of caller  pfe_hif_drv_show_ring_status/83:
    callsite  pfe_hif_drv_show_ring_status/83 -> pfe_hif_drv_show_tx_ring_status/82 : 
       param 0: ANCESTOR: 0, offset 2048
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_hif_drv_show_ring_status/83 -> pfe_hif_drv_show_rx_ring_status/81 : 
       param 0: ANCESTOR: 0, offset 2048, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_hif_drv_show_tx_ring_status/82:
  Jump functions of caller  pfe_hif_drv_show_rx_ring_status/81:
  Jump functions of caller  pfe_hif_drv_get_chnl/80:
  Jump functions of caller  pfe_hif_drv_destroy/79:
    callsite  pfe_hif_drv_destroy/79 -> pfe_hif_drv_exit/78 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_exit/78:
    callsite  pfe_hif_drv_exit/78 -> pfe_hif_drv_exit.part.0/350 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_stop/77:
    callsite  pfe_hif_drv_stop/77 -> pfe_hif_drv_stop_tx/75 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_stop/77 -> pfe_hif_drv_stop_rx/76 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_stop_rx/76:
  Jump functions of caller  pfe_hif_drv_stop_tx/75:
  Jump functions of caller  pfe_hif_drv_start/74:
    callsite  pfe_hif_drv_start/74 -> pfe_hif_drv_start.part.0/349 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_init/73:
    callsite  pfe_hif_drv_init/73 -> pfe_hif_drv_init_err_handler/71 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 9
         value: 0x9, mask: 0x0
         Unknown VR
    callsite  pfe_hif_drv_init/73 -> pfe_hif_drv_attach_channels/72 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_init/73 -> pfe_hif_drv_create_data_channel/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 48, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_attach_channels/72:
    callsite  pfe_hif_drv_attach_channels/72 -> pfe_hif_drv_init_err_handler/71 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 7
         value: 0x7, mask: 0x0
         Unknown VR
    callsite  pfe_hif_drv_attach_channels/72 -> pfe_hif_drv_init_err_handler/71 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
    callsite  pfe_hif_drv_attach_channels/72 -> pfe_hif_drv_destroy_data_channel/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_init_err_handler/71:
    callsite  pfe_hif_drv_init_err_handler/71 -> pfe_hif_drv_destroy_data_channel/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_create/70:
  Jump functions of caller  pfe_hif_drv_client_get_ts/69:
  Jump functions of caller  pfe_hif_drv_client_xmit_pkt/68:
    callsite  pfe_hif_drv_client_xmit_pkt/68 -> pfe_hif_drv_client_xmit_sg_pkt/67 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 1
           offset: 1568, cst: 0
           offset: 1600, cst: 10
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: PASS THROUGH: 5, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_xmit_sg_pkt/67:
    callsite  pfe_hif_drv_client_xmit_sg_pkt/67 -> oal_mutex_unlock.part.0/339 : 
       param 0: CONST: 92
         value: 0x5c, mask: 0x0
         Unknown VR
    callsite  pfe_hif_drv_client_xmit_sg_pkt/67 -> pfe_hif_drv_client_transmit_packet_buffers/66 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_client_xmit_sg_pkt/67 -> pfe_hif_drv_cfg_IEEE1588.isra.0/345 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_client_xmit_sg_pkt/67 -> oal_mutex_lock.part.0/338 : 
       param 0: CONST: 92
         value: 0x5c, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_transmit_packet_buffers/66:
  Jump functions of caller  pfe_hif_drv_init_tx_header/64:
  Jump functions of caller  pfe_hif_drv_client_set_inject_if/63:
  Jump functions of caller  pfe_hif_drv_process_tx/62:
    callsite  pfe_hif_drv_process_tx/62 -> pfe_hif_drv_notify_clients.isra.0/340 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_tx/62 -> pfe_hif_drv_put_data_to_tx_conf_queue/61 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_hif_drv_put_data_to_tx_conf_queue/61:
    callsite  pfe_hif_drv_put_data_to_tx_conf_queue/61 -> fifo_put/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_receive_tx_conf/59:
    callsite  pfe_hif_drv_client_receive_tx_conf/59 -> fifo_get/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_pkt_free/58:
    callsite  pfe_hif_pkt_free/58 -> release_rx_buffer_with_check/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_has_rx_pkt/57:
  Jump functions of caller  pfe_hif_drv_client_receive_pkt/56:
    callsite  pfe_hif_drv_client_receive_pkt/56 -> fifo_get/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_unregister/55:
    callsite  pfe_hif_drv_client_unregister/55 -> pfe_hif_drv_start/74 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_client_unregister/55 -> hif_client_free_tx_queues/45 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_client_unregister/55 -> hif_client_free_rx_queues/44 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 1416, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_client_unregister/55 -> pfe_hif_drv_stop/77 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_get_priv/54:
  Jump functions of caller  pfe_hif_drv_client_get_drv/53:
  Jump functions of caller  pfe_hif_drv_client_register_ll/52:
    callsite  pfe_hif_drv_client_register_ll/52 -> pfe_hif_drv_client_unregister/55 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_client_register_ll/52 -> pfe_hif_drv_client_create_rx_tx.isra.0/344 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 1416, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_register/50:
    callsite  pfe_hif_drv_client_register/50 -> pfe_hif_drv_client_register_ll/52 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_hif_drv_aux_client_register/49:
    callsite  pfe_hif_drv_aux_client_register/49 -> pfe_hif_drv_client_register_ll/52 : 
       param 0: ANCESTOR: 0, offset 159744, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_hif_drv_ihc_client_register/48:
    callsite  pfe_hif_drv_ihc_client_register/48 -> pfe_hif_drv_client_register_ll/52 : 
       param 0: ANCESTOR: 0, offset 145408
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  hif_client_create_tx_queues/47:
  Jump functions of caller  hif_client_create_rx_queues/46:
  Jump functions of caller  hif_client_free_tx_queues/45:
  Jump functions of caller  hif_client_free_rx_queues/44:
    callsite  hif_client_free_rx_queues/44 -> fifo_get/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  hif_client_free_rx_queues/44 -> pfe_hif_pkt_free/58 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  hif_client_free_rx_queues/44 -> fifo_get/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_process_rx/43:
    callsite  pfe_hif_drv_process_rx/43 -> pfe_hif_drv_notify_rx_clients/41 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_rx/43 -> release_rx_buffer_with_check/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_rx/43 -> fifo_put/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_rx/43 -> pfe_hif_drv_process_ts/39 : 
       param 0: UNKNOWN
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
    callsite  pfe_hif_drv_process_rx/43 -> release_rx_buffer_with_check/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_rx/43 -> pfe_hif_drv_process_ets/38 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_rx/43 -> release_rx_buffer_with_check/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_rx/43 -> pfe_hif_drv_assign_client/37 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_rx/43 -> release_rx_buffer_with_check/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_process_rx/43 -> pfe_hif_drv_process_lifm/42 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_hif_drv_process_lifm/42:
  Jump functions of caller  pfe_hif_drv_notify_rx_clients/41:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 (client_11, _3, 0, 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  release_rx_buffer_with_check/40:
  Jump functions of caller  pfe_hif_drv_process_ts/39:
  Jump functions of caller  pfe_hif_drv_process_ets/38:
    indirect simple callsite, calling param -1, offset 0, for stmt _15 (_13, _16, 2, qq_18);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xf
         VR  [0, 8]
  Jump functions of caller  pfe_hif_drv_assign_client/37:
  Jump functions of caller  pfe_hif_drv_destroy_data_channel/36:
  Jump functions of caller  pfe_hif_drv_create_data_channel/35:
    callsite  pfe_hif_drv_create_data_channel/35 -> pfe_hif_drv_destroy_data_channel/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_ptp_ts_db_tick_iteration/34:
  Jump functions of caller  pfe_hif_drv_client_tx_done/33:
  Jump functions of caller  pfe_hif_drv_tx_job/32:
    callsite  pfe_hif_drv_tx_job/32 -> pfe_hif_drv_tx_job.part.0/343 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_drv_tx_job/32 -> oal_mutex_lock.part.0/338 : 
       param 0: CONST: 91
         value: 0x5b, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_drv_chnl_tx_isr/31:
    callsite  pfe_hif_drv_chnl_tx_isr/31 -> pfe_hif_drv_chnl_tx_isr.part.0/348 : 
  Jump functions of caller  pfe_hif_drv_rx_job/30:
    callsite  pfe_hif_drv_rx_job/30 -> pfe_hif_drv_process_rx/43 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_drv_client_rx_done/29:
  Jump functions of caller  fifo_get/13:
  Jump functions of caller  fifo_put/12:

 Propagating constants:

Not considering pfe_hif_drv_show_ring_status for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_get_chnl for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_exit for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_stop for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_start for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_get_ts for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_xmit_pkt for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_xmit_sg_pkt for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_init_tx_header for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_set_inject_if for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_receive_tx_conf for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_pkt_free for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_has_rx_pkt for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_receive_pkt for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_unregister for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_get_priv for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_get_drv for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_register for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_aux_client_register for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_ihc_client_register for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_ptp_ts_db_tick_iteration for cloning; -fipa-cp-clone disabled.
Function pfe_hif_drv_client_tx_done/33 is not versionable, reason: not a tree_versionable_function.
Not considering pfe_hif_drv_tx_job for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_chnl_tx_isr for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_rx_job for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_drv_client_rx_done for cloning; -fipa-cp-clone disabled.

overall_size: 1695, max_new_size: 11001
 - context independent values, size: 47, time_benefit: 65.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 2, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: pfe_hif_drv_exit.part.0/350:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_start.part.0/349:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_chnl_tx_isr.part.0/348:
  Node: pfe_hif_drv_cfg_IEEE1588.isra.0/345:
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
         pfe_ct_hif_tx_flags_t * ~[0B, 0B]
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
  Node: pfe_hif_drv_client_create_rx_tx.isra.0/344:
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
  Node: pfe_hif_drv_tx_job.part.0/343:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_notify_clients.isra.0/340:
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
  Node: oal_mutex_unlock.part.0/339:
    param [0]: 91 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               92 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x5c, mask = 0x7
         const oal_mutex_t [91, 92]
        AGGS VARIABLE
  Node: oal_mutex_lock.part.0/338:
    param [0]: 91 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               92 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x5c, mask = 0x7
         const oal_mutex_t [91, 92]
        AGGS VARIABLE
  Node: pfe_hif_drv_show_ring_status/83:
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
  Node: pfe_hif_drv_show_tx_ring_status/82:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_hif_drv_client_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_hif_drv_show_rx_ring_status/81:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_hif_drv_client_t * ~[0B, 0B]
        AGGS BOTTOM
  Node: pfe_hif_drv_get_chnl/80:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_destroy/79:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_exit/78:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_stop/77:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_stop_rx/76:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_stop_tx/75:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_start/74:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_init/73:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_attach_channels/72:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_init_err_handler/71:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 6 [loc_time: 7, loc_size: 23, prop_time: 0, prop_size: 0]
               7 [loc_time: 7, loc_size: 41, prop_time: 0, prop_size: 0]
               9 [loc_time: 7, loc_size: 59, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x9, mask = 0xf
         uint_t [6, 9]
        AGGS VARIABLE
  Node: pfe_hif_drv_create/70:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_client_get_ts/69:
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
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_client_xmit_pkt/68:
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
  Node: pfe_hif_drv_client_xmit_sg_pkt/67:
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
  Node: pfe_hif_drv_client_transmit_packet_buffers/66:
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
  Node: pfe_hif_drv_init_tx_header/64:
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
  Node: pfe_hif_drv_client_set_inject_if/63:
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
  Node: pfe_hif_drv_process_tx/62:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 128 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x80, mask = 0x0
         uint32_t [128, 128]
        AGGS VARIABLE
  Node: pfe_hif_drv_put_data_to_tx_conf_queue/61:
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
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_hif_tx_meta_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_hif_drv_client_receive_tx_conf/59:
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
  Node: pfe_hif_pkt_free/58:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_client_has_rx_pkt/57:
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
  Node: pfe_hif_drv_client_receive_pkt/56:
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
  Node: pfe_hif_drv_client_unregister/55:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_client_get_priv/54:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_client_get_drv/53:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_client_register_ll/52:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_drv_client_data * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_hif_drv_client_register/50:
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
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_aux_client_register/49:
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
  Node: pfe_hif_drv_ihc_client_register/48:
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
  Node: hif_client_create_tx_queues/47:
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
  Node: hif_client_create_rx_queues/46:
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
  Node: hif_client_free_tx_queues/45:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: hif_client_free_rx_queues/44:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_process_rx/43:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_process_lifm/42:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_drv_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_hif_drv_notify_rx_clients/41:
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
  Node: release_rx_buffer_with_check/40:
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
  Node: pfe_hif_drv_process_ts/39:
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
  Node: pfe_hif_drv_process_ets/38:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_drv_client_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_assign_client/37:
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
  Node: pfe_hif_drv_destroy_data_channel/36:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_create_data_channel/35:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_drv_client_ptp_ts_db_tick_iteration/34:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_client_tx_done/33:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_tx_job/32:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_chnl_tx_isr/31:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_rx_job/30:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_drv_client_rx_done/29:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: fifo_get/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fifo_put/12:
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

 - Creating a specialized node of pfe_hif_drv_process_tx/62 for all known contexts.
    replacing param #1 budget with const 128
Propagated bits info for function pfe_hif_drv_process_tx.constprop/351:
 param 1: value = 0x80, mask = 0x0
Propagated bits info for function oal_mutex_unlock.part.0/339:
 param 0: value = 0x5c, mask = 0x7
Propagated bits info for function oal_mutex_lock.part.0/338:
 param 0: value = 0x5c, mask = 0x7
Propagated bits info for function pfe_hif_drv_init_err_handler/71:
 param 1: value = 0x9, mask = 0xf
Propagated bits info for function pfe_hif_drv_process_tx/62:
 param 1: value = 0x80, mask = 0x0
Propagated bits info for function pfe_hif_drv_put_data_to_tx_conf_queue/61:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_hif_drv_client_register_ll/52:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_hif_drv_process_lifm/42:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_hif_drv_process_ets/38:
 param 0: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: pfe_hif_drv_process_tx/62
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_hif_drv_process_tx.constprop.0/351 (pfe_hif_drv_process_tx.constprop) @078bf700
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of pfe_hif_drv_process_tx/62
  Availability: local
  Function flags: count:114863532 (estimated locally) local optimize_size
  Called by: pfe_hif_drv_tx_job.part.0/343 (1073741824 (estimated locally),9.09 per call) 
  Calls: pfe_hif_chnl_get_tx_conf/202 (1073741824 (estimated locally),9.35 per call) __builtin_expect/84 (1014686025 (estimated locally),8.83 per call) __builtin_expect/84 (913217422 (estimated locally),7.95 per call) pfe_hif_drv_put_data_to_tx_conf_queue/61 (401742608 (estimated locally),3.50 per call) pfe_hif_drv_notify_clients.isra.0/340 (114863532 (estimated locally),1.00 per call) 
pfe_hif_drv_exit.part.0/350 (pfe_hif_drv_exit.part.0) @06ff29a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_drv_exit/78 (82570744 (estimated locally),0.50 per call) 
  Calls: pfe_hif_drv_stop/77 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_destroy_data_channel/36 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_set_event_cbk/327 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_set_event_cbk/327 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_set_event_cbk/327 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_start.part.0/349 (pfe_hif_drv_start.part.0) @06ff2c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) first_run:1 body local split_part unlikely_executed optimize_size
  Called by: pfe_hif_drv_start/74 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_rx_enable/329 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hif_chnl_tx_enable/330 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hif_chnl_rx_irq_unmask/85 (0 (precise),0.00 per call) pfe_hif_chnl_tx_irq_unmask/95 (0 (precise),0.00 per call) 
pfe_hif_drv_chnl_tx_isr.part.0/348 (pfe_hif_drv_chnl_tx_isr.part.0) @07315460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_drv_chnl_tx_isr/31 (107374184 (estimated locally),0.10 per call) 
  Calls: pfe_hm_report/89 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_cfg_IEEE1588.isra.0/345 (pfe_hif_drv_cfg_IEEE1588.isra.0) @073151c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_xmit_sg_pkt/67 (869730877 (estimated locally),0.81 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/90 (41402044 (estimated locally),0.04 per call) pfe_hm_report/89 (41402044 (estimated locally),0.04 per call) pfe_hif_ptp_ts_db_push_msg/93 (125460741 (estimated locally),0.12 per call) Eth_PFE_LLD_GetTxBufTsRef/318 (125460741 (estimated locally),0.12 per call) oal_util_get_unique_seqnum32/91 (125460741 (estimated locally),0.12 per call) oal_util_parse_ptp/92 (354334802 (estimated locally),0.33 per call) Eth_PFE_LLD_GetTxBufMeta/317 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_create_rx_tx.isra.0/344 (pfe_hif_drv_client_create_rx_tx.isra.0) @0729f620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_register_ll/52 (541273254 (estimated locally),0.50 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/90 (287011189 (estimated locally),0.27 per call) pfe_hm_report/89 (287011189 (estimated locally),0.27 per call) pfe_hif_ptp_ts_db_init/311 (869730877 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/90 (96636764 (estimated locally),0.09 per call) pfe_hm_report/89 (96636764 (estimated locally),0.09 per call) __builtin_expect/84 (966367642 (estimated locally),0.90 per call) hif_client_create_tx_queues/47 (966367642 (estimated locally),0.90 per call) oal_util_raise_dem_for_drv_runtime_err/90 (107374182 (estimated locally),0.10 per call) pfe_hm_report/89 (107374182 (estimated locally),0.10 per call) __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) hif_client_create_rx_queues/46 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_tx_job.part.0/343 (pfe_hif_drv_tx_job.part.0) @070639a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_drv_tx_job/32 (118111600 (estimated locally),0.90 per call) 
  Calls: pfe_hif_drv_process_tx.constprop/351 (1073741824 (estimated locally),9.09 per call) oal_mutex_unlock.part.0/339 (118111601 (estimated locally),1.00 per call) pfe_hif_chnl_tx_irq_unmask/95 (118111601 (estimated locally),1.00 per call) pfe_hif_chnl_tx_dma_start/96 (118111601 (estimated locally),1.00 per call) 
pfe_hif_drv_notify_clients.isra.0/340 (pfe_hif_drv_notify_clients.isra.0) @07063700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:54607571 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_process_tx.constprop/351 (114863532 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(324512697 (estimated locally),5.94 per call) 
oal_mutex_unlock.part.0/339 (oal_mutex_unlock.part.0) @07010540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_drv_client_xmit_sg_pkt/67 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_tx_job.part.0/343 (118111601 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
oal_mutex_lock.part.0/338 (oal_mutex_lock.part.0) @06db8d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hif_drv_client_xmit_sg_pkt/67 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_tx_job/32 (118111600 (estimated locally),0.90 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
fifo_peek/337 (fifo_peek) @07976c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_show_tx_ring_status/82 (773191730 (estimated locally),6.55 per call) pfe_hif_drv_show_rx_ring_status/81 (773191730 (estimated locally),6.55 per call) 
  Calls: 
pfe_hif_chnl_tx_irq_mask/336 (pfe_hif_chnl_tx_irq_mask) @07976700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) 
  Calls: 
oal_job_drain/335 (oal_job_drain) @07976620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_is_tx_dma_active/334 (pfe_hif_chnl_is_tx_dma_active) @07976540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_rx_irq_mask/333 (pfe_hif_chnl_rx_irq_mask) @07976380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_rx/76 (0 (precise),0.00 per call) 
  Calls: 
oal_time_usleep/332 (oal_time_usleep) @079762a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) pfe_hif_drv_stop_rx/76 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_is_rx_dma_active/331 (pfe_hif_chnl_is_rx_dma_active) @079761c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_rx/76 (0 (precise),0.00 per call) pfe_hif_drv_stop_rx/76 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_tx_enable/330 (pfe_hif_chnl_tx_enable) @07967ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_rx_enable/329 (pfe_hif_chnl_rx_enable) @07967e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) 
  Calls: 
oal_job_run/328 (oal_job_run) @07967b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) pfe_hif_drv_chnl_tx_isr/31 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_set_event_cbk/327 (pfe_hif_chnl_set_event_cbk) @079679a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_exit.part.0/350 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_exit.part.0/350 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_exit.part.0/350 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_attach_channels/72 (536870913 (estimated locally),0.50 per call) pfe_hif_drv_attach_channels/72 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_attach_channels/72 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_init_err_handler/71 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_init_err_handler/71 (354334802 (estimated locally),0.33 per call) pfe_hif_drv_init_err_handler/71 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_hif_chnl_tx_disable/326 (pfe_hif_chnl_tx_disable) @079677e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) pfe_hif_drv_destroy_data_channel/36 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_rx_disable/325 (pfe_hif_chnl_rx_disable) @07967700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_stop_rx/76 (0 (precise),0.00 per call) pfe_hif_drv_destroy_data_channel/36 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_get_tx_fifo_depth/324 (pfe_hif_chnl_get_tx_fifo_depth) @07967540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_create_data_channel/35 (0 (precise),0.00 per call) 
  Calls: 
oal_job_create/323 (oal_job_create) @07967380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_init/73 (0 (precise),0.00 per call) 
  Calls: 
__func__.11820/322 (__func__) @07968828
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: pfe_hif_drv_init/73 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_hif_chnl_get_meta_size/321 (pfe_hif_chnl_get_meta_size) @079671c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_create/70 (0 (precise),0.00 per call) pfe_hif_drv_create/70 (0 (precise),0.00 per call) pfe_hif_drv_create_data_channel/35 (0 (precise),0.00 per call) pfe_hif_drv_create_data_channel/35 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ptp_ts_db_pop/320 (pfe_hif_ptp_ts_db_pop) @07967000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_get_ts/69 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_tx/319 (pfe_hif_chnl_tx) @0794fd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_transmit_packet_buffers/66 (1014686025 (estimated locally),6.32 per call) 
  Calls: 
Eth_PFE_LLD_GetTxBufTsRef/318 (Eth_PFE_LLD_GetTxBufTsRef) @0794fb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_cfg_IEEE1588.isra.0/345 (125460741 (estimated locally),0.12 per call) 
  Calls: 
Eth_PFE_LLD_GetTxBufMeta/317 (Eth_PFE_LLD_GetTxBufMeta) @0794fa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_cfg_IEEE1588.isra.0/345 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_can_accept_tx_num/316 (pfe_hif_chnl_can_accept_tx_num) @0794f8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_xmit_sg_pkt/67 (966367642 (estimated locally),0.90 per call) 
  Calls: 
pfe_hif_chnl_get_id/315 (pfe_hif_chnl_get_id) @0794f700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_init_tx_header/64 (0 (precise),0.00 per call) 
  Calls: 
fifo_get_fill_level/314 (fifo_get_fill_level) @0794f0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_has_rx_pkt/57 (1073741824 (estimated locally),1.00 per call) hif_client_free_tx_queues/45 (860067202 (estimated locally),0.88 per call) 
  Calls: 
fifo_destroy/313 (fifo_destroy) @07936e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: hif_client_free_rx_queues/44 (0 (precise),0.00 per call) hif_client_free_tx_queues/45 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ptp_ts_db_fini/312 (pfe_hif_ptp_ts_db_fini) @07936c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_unregister/55 (751619278 (estimated locally),0.70 per call) 
  Calls: 
pfe_hif_ptp_ts_db_init/311 (pfe_hif_ptp_ts_db_init) @07936540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_create_rx_tx.isra.0/344 (869730877 (estimated locally),0.81 per call) 
  Calls: 
autolibc_memset/310 (autolibc_memset) @07936380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_register_ll/52 (541273254 (estimated locally),0.50 per call) pfe_hif_drv_client_unregister/55 (751619278 (estimated locally),0.70 per call) pfe_hif_drv_create/70 (0 (precise),0.00 per call) pfe_hif_drv_create_data_channel/35 (0 (precise),0.00 per call) hif_client_create_tx_queues/47 (118111600 (estimated locally),1.00 per call) hif_client_create_rx_queues/46 (118111600 (estimated locally),1.00 per call) 
  Calls: 
fifo_create/309 (fifo_create) @079361c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_ihc_client_register/48 (0 (precise),0.00 per call) pfe_hif_drv_ihc_client_register/48 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ptp_ts_db_tick_iteration/308 (pfe_hif_ptp_ts_db_tick_iteration) @07936000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_ptp_ts_db_tick_iteration/34 (574129754 (estimated locally),0.53 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/307 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @07935d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/306 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @07935c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/305 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @07935b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/304 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @07935a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/303 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @079359a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/302 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @079358c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/301 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @079357e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/300 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07935700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/299 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07935620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/298 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @07935540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/297 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @07935460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/296 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @07935380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/295 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @079352a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/294 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @079351c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/293 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @079350e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/292 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07935000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/291 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @07933ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/290 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @07933e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/289 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @07933d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/288 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @07933c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/287 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @07933b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/286 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @07933a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/285 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @079339a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/284 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @079338c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/283 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @079337e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/282 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07933700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/281 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07933620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/280 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07933540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/279 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @07933460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/278 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @07933380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/277 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @079332a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/276 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @079331c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/275 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @079330e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/274 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07933000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/273 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @07932ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/272 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @07932e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/271 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @07932d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/270 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @07932c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/269 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @07932b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/268 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @07932a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/267 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @079329a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/266 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @079328c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/265 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @079327e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/264 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07932700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/263 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07932620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/262 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07932540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/261 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @07932460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/260 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @07932380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/259 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @079322a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/258 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @079321c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/257 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @079320e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/256 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07932000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/255 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07931ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/254 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07931e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/253 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @07931d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/252 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @07931c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/251 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @07931b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/250 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @07931a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/249 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @079319a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/248 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @079318c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/247 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @079317e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/246 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07931700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/245 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07931620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/244 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @07931540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/243 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @07931460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/242 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @07931380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/241 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @079312a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/240 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @079311c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/239 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @079310e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/238 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @07931000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/237 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @07930ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/236 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @07930e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/235 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @07930d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/234 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @07930c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/233 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @07930b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/232 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @07930a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/231 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @079309a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/230 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @079308c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/229 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @079307e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/228 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07930700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/227 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @07930620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/226 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @07930540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/225 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @07930460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/224 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @07930380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/223 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @079302a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/222 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @079301c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/221 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @079300e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/220 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @07930000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/219 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @0792e620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/218 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @0792eee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/217 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @0792ee00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/216 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @0792ed20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/215 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @0792ec40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/214 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @0792eb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/213 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @0792ea80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/212 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @0792e9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/211 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0792e8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/210 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0792e7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/209 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0792e700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/208 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0792e540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/207 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0792e460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/206 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0792e380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/205 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0792e2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/204 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0792e1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/203 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0792e0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_get_tx_conf/202 (pfe_hif_chnl_get_tx_conf) @07924d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_process_tx.constprop/351 (1073741824 (estimated locally),9.35 per call) 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/201 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @07924b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/200 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @07924a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/199 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @079249a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/198 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @079248c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/197 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @079247e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/196 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @07924700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/195 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @07924620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/194 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07924540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/193 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07924460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/192 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @07924380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/191 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @079242a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/190 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @079241c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/189 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @079240e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/188 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @07924000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/187 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @07923ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/186 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07923e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/185 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @07923d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/184 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @07923c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/183 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @07923b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/182 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @07923a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/181 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @079239a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/180 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @079238c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/179 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @079237e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/178 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @07923700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/177 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @07923620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/176 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07923540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/175 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07923460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/174 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07923380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/173 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @079232a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/172 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @079231c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/171 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @079230e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/170 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @07923000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/169 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @07922ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/168 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07922e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/167 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @07922d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/166 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @07922c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/165 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @07922b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/164 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @07922a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/163 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @079229a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/162 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @079228c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/161 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @079227e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/160 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @07922700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/159 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @07922620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/158 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07922540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/157 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07922460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/156 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07922380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/155 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @079222a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/154 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @079221c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/153 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @079220e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/152 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @07922000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/151 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @07920ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/150 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07920e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/149 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07920d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/148 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07920c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/147 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @07920b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/146 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @07920a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/145 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @079209a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/144 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @079208c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/143 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @079207e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/142 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @07920700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/141 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @07920620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/140 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07920540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/139 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07920460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/138 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @07920380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/137 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @079202a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/136 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @079201c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/135 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @079200e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/134 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @07920000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/133 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @0791fee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/132 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @0791fe00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/131 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @0791fd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/130 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @0791fc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/129 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @0791fb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/128 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @0791fa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/127 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @0791f9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/126 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @0791f8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/125 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @0791f7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/124 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @0791f700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/123 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @0791f620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/122 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @0791f540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/121 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @0791f460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/120 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @0791f380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/119 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @0791f2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/118 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @0791f1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/117 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @0791f0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/116 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @0791f000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/115 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @0791d460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/114 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @0791dee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/113 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @0791de00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/112 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @0791dd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/111 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @0791dc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/110 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @0791db60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/109 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @0791da80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/108 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @0791d9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/107 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @0791d8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/106 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @0791d7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/105 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0791d700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/104 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0791d620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/103 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0791d540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/102 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0791d380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/101 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0791d2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/100 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0791d1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/99 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0791d0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/98 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0791d000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/97 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0790bee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
pfe_hif_chnl_tx_dma_start/96 (pfe_hif_chnl_tx_dma_start) @0790bd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_client_xmit_sg_pkt/67 (96636764 (estimated locally),0.09 per call) pfe_hif_drv_tx_job.part.0/343 (118111601 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_tx_irq_unmask/95 (pfe_hif_chnl_tx_irq_unmask) @0790bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) pfe_hif_drv_tx_job.part.0/343 (118111601 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_release_buf/94 (pfe_hif_chnl_release_buf) @0790b9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: release_rx_buffer_with_check/40 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_ptp_ts_db_push_msg/93 (pfe_hif_ptp_ts_db_push_msg) @0790b700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_cfg_IEEE1588.isra.0/345 (125460741 (estimated locally),0.12 per call) pfe_hif_drv_process_ts/39 (168117393 (estimated locally),0.16 per call) 
  Calls: 
oal_util_parse_ptp/92 (oal_util_parse_ptp) @0790b620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_cfg_IEEE1588.isra.0/345 (354334802 (estimated locally),0.33 per call) pfe_hif_drv_process_ts/39 (354334802 (estimated locally),0.33 per call) 
  Calls: 
oal_util_get_unique_seqnum32/91 (oal_util_get_unique_seqnum32) @0790b540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_cfg_IEEE1588.isra.0/345 (125460741 (estimated locally),0.12 per call) pfe_hif_drv_process_ts/39 (354334802 (estimated locally),0.33 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/90 (oal_util_raise_dem_for_drv_runtime_err) @0790b380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_exit/78 (327086456 (estimated locally),1.98 per call) pfe_hif_drv_client_register/50 (133189620 (estimated locally),0.12 per call) pfe_hif_drv_client_register/50 (179851756 (estimated locally),0.17 per call) pfe_hif_drv_aux_client_register/49 (159987532 (estimated locally),0.15 per call) pfe_hif_drv_ihc_client_register/48 (0 (precise),0.00 per call) pfe_hif_drv_ihc_client_register/48 (0 (precise),0.00 per call) pfe_hif_drv_ihc_client_register/48 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_client_register_ll/52 (221083442 (estimated locally),0.21 per call) pfe_hif_drv_start/74 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) pfe_hif_drv_init/73 (0 (precise),0.00 per call) pfe_hif_drv_init/73 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_create/70 (0 (precise),0.00 per call) pfe_hif_drv_client_has_rx_pkt/57 (107374182 (estimated locally),0.10 per call) pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) pfe_hif_drv_chnl_tx_isr.part.0/348 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_attach_channels/72 (177167401 (estimated locally),0.17 per call) pfe_hif_drv_attach_channels/72 (536870913 (estimated locally),0.50 per call) pfe_hif_drv_attach_channels/72 (0 (precise),0.00 per call) pfe_hif_drv_init_err_handler/71 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_init_err_handler/71 (116930485 (estimated locally),0.11 per call) pfe_hif_drv_init_err_handler/71 (71717364 (estimated locally),0.07 per call) pfe_hif_drv_create_data_channel/35 (0 (precise),0.00 per call) pfe_hif_drv_client_transmit_packet_buffers/66 (101468602 (estimated locally),0.63 per call) pfe_hif_drv_cfg_IEEE1588.isra.0/345 (41402044 (estimated locally),0.04 per call) hif_client_free_tx_queues/45 (860067202 (estimated locally),0.88 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (287011189 (estimated locally),0.27 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (96636764 (estimated locally),0.09 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (107374182 (estimated locally),0.10 per call) release_rx_buffer_with_check/40 (107374182 (estimated locally),0.10 per call) pfe_hif_drv_process_ts/39 (116930485 (estimated locally),0.11 per call) pfe_hif_drv_process_ts/39 (27739370 (estimated locally),0.03 per call) pfe_hif_drv_process_ts/39 (84058696 (estimated locally),0.08 per call) pfe_hif_drv_process_ets/38 (83937307 (estimated locally),0.33 per call) 
  Calls: 
pfe_hm_report/89 (pfe_hm_report) @0790b2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_exit/78 (327086456 (estimated locally),1.98 per call) pfe_hif_drv_client_register/50 (133189620 (estimated locally),0.12 per call) pfe_hif_drv_client_register/50 (179851756 (estimated locally),0.17 per call) pfe_hif_drv_aux_client_register/49 (159987532 (estimated locally),0.15 per call) pfe_hif_drv_ihc_client_register/48 (0 (precise),0.00 per call) pfe_hif_drv_ihc_client_register/48 (0 (precise),0.00 per call) pfe_hif_drv_ihc_client_register/48 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_client_register_ll/52 (221083442 (estimated locally),0.21 per call) pfe_hif_drv_start/74 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) pfe_hif_drv_init/73 (0 (precise),0.00 per call) pfe_hif_drv_init/73 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_create/70 (0 (precise),0.00 per call) pfe_hif_drv_client_has_rx_pkt/57 (107374182 (estimated locally),0.10 per call) pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) pfe_hif_drv_stop_tx/75 (0 (precise),0.00 per call) pfe_hif_drv_chnl_tx_isr.part.0/348 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_attach_channels/72 (177167401 (estimated locally),0.17 per call) pfe_hif_drv_attach_channels/72 (536870913 (estimated locally),0.50 per call) pfe_hif_drv_attach_channels/72 (0 (precise),0.00 per call) pfe_hif_drv_init_err_handler/71 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_init_err_handler/71 (116930485 (estimated locally),0.11 per call) pfe_hif_drv_init_err_handler/71 (71717364 (estimated locally),0.07 per call) pfe_hif_drv_create_data_channel/35 (0 (precise),0.00 per call) pfe_hif_drv_client_transmit_packet_buffers/66 (101468602 (estimated locally),0.63 per call) pfe_hif_drv_cfg_IEEE1588.isra.0/345 (41402044 (estimated locally),0.04 per call) hif_client_free_tx_queues/45 (860067202 (estimated locally),0.88 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (287011189 (estimated locally),0.27 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (96636764 (estimated locally),0.09 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (107374182 (estimated locally),0.10 per call) release_rx_buffer_with_check/40 (107374182 (estimated locally),0.10 per call) pfe_hif_drv_process_ts/39 (116930485 (estimated locally),0.11 per call) pfe_hif_drv_process_ts/39 (27739370 (estimated locally),0.03 per call) pfe_hif_drv_process_ts/39 (84058696 (estimated locally),0.08 per call) pfe_hif_drv_process_ets/38 (83937307 (estimated locally),0.33 per call) 
  Calls: 
pfe_hif_ptp_ts_db_push_ts/88 (pfe_hif_ptp_ts_db_push_ts) @0790b1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_process_ts/39 (84058696 (estimated locally),0.08 per call) pfe_hif_drv_process_ets/38 (254355476 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_rx_va/87 (pfe_hif_chnl_rx_va) @078fb1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_process_rx/43 (1073741824 (estimated locally),9.09 per call) 
  Calls: 
pfe_hif_chnl_rx_dma_start/86 (pfe_hif_chnl_rx_dma_start) @078fbee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_rx_job/30 (966367642 (estimated locally),0.90 per call) 
  Calls: 
pfe_hif_chnl_rx_irq_unmask/85 (pfe_hif_chnl_rx_irq_unmask) @078fbe00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) pfe_hif_drv_rx_job/30 (966367642 (estimated locally),0.90 per call) 
  Calls: 
__builtin_expect/84 (__builtin_expect) @078fbd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_drv_process_tx.constprop/351 (1014686025 (estimated locally),8.83 per call) pfe_hif_drv_process_tx.constprop/351 (913217422 (estimated locally),7.95 per call) pfe_hif_drv_client_xmit_sg_pkt/67 (966367642 (estimated locally),0.90 per call) pfe_hif_drv_client_xmit_sg_pkt/67 (1073741824 (estimated locally),1.00 per call) hif_client_free_rx_queues/44 (119304 (estimated locally),0.98 per call) pfe_hif_drv_client_has_rx_pkt/57 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_show_tx_ring_status/82 (955630223 (estimated locally),8.09 per call) pfe_hif_drv_show_rx_ring_status/81 (955630223 (estimated locally),8.09 per call) pfe_hif_drv_chnl_tx_isr/31 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_client_transmit_packet_buffers/66 (1014686025 (estimated locally),6.32 per call) hif_client_free_tx_queues/45 (860067202 (estimated locally),0.88 per call) hif_client_free_tx_queues/45 (955630225 (estimated locally),0.98 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (966367642 (estimated locally),0.90 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_tx_job/32 (131235111 (estimated locally),1.00 per call) pfe_hif_drv_rx_job/30 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_process_rx/43 (552084429 (estimated locally),4.67 per call) pfe_hif_drv_process_rx/43 (762210666 (estimated locally),6.45 per call) release_rx_buffer_with_check/40 (1073741824 (estimated locally),1.00 per call) fifo_get/13 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_put_data_to_tx_conf_queue/61 (1073741824 (estimated locally),1.00 per call) fifo_put/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_drv_show_ring_status/83 (pfe_hif_drv_show_ring_status) @078fb7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_show_tx_ring_status/82 (108662673 (estimated locally),0.10 per call) pfe_hif_drv_show_rx_ring_status/81 (108662672 (estimated locally),0.10 per call) 
pfe_hif_drv_show_tx_ring_status/82 (pfe_hif_drv_show_tx_ring_status) @078fb540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_show_ring_status/83 (108662673 (estimated locally),0.10 per call) 
  Calls: fifo_peek/337 (773191730 (estimated locally),6.55 per call) __builtin_expect/84 (955630223 (estimated locally),8.09 per call) 
pfe_hif_drv_show_rx_ring_status/81 (pfe_hif_drv_show_rx_ring_status) @078fb0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_show_ring_status/83 (108662672 (estimated locally),0.10 per call) 
  Calls: fifo_peek/337 (773191730 (estimated locally),6.55 per call) __builtin_expect/84 (955630223 (estimated locally),8.09 per call) 
pfe_hif_drv_get_chnl/80 (pfe_hif_drv_get_chnl) @078f27e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_drv_destroy/79 (pfe_hif_drv_destroy) @078f20e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_exit/78 (574129754 (estimated locally),0.53 per call) 
pfe_hif_drv_exit/78 (pfe_hif_drv_exit) @078f2d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:165141492 (estimated locally) body optimize_size
  Called by: pfe_hif_drv_destroy/79 (574129754 (estimated locally),0.53 per call) 
  Calls: pfe_hif_drv_exit.part.0/350 (82570744 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/90 (327086456 (estimated locally),1.98 per call) pfe_hm_report/89 (327086456 (estimated locally),1.98 per call) 
pfe_hif_drv_stop/77 (pfe_hif_drv_stop) @078f29a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_drv_exit.part.0/350 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_client_unregister/55 (248034361 (estimated locally),0.23 per call) 
  Calls: pfe_hif_drv_stop_tx/75 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_stop_rx/76 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_stop_rx/76 (pfe_hif_drv_stop_rx) @078f2700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_stop/77 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_chnl_rx_irq_mask/333 (0 (precise),0.00 per call) pfe_hif_chnl_is_rx_dma_active/331 (0 (precise),0.00 per call) oal_time_usleep/332 (0 (precise),0.00 per call) pfe_hif_chnl_is_rx_dma_active/331 (0 (precise),0.00 per call) pfe_hif_chnl_rx_disable/325 (0 (precise),0.00 per call) 
pfe_hif_drv_stop_tx/75 (pfe_hif_drv_stop_tx) @078f2460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_stop/77 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_chnl_tx_irq_mask/336 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) oal_job_drain/335 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) oal_job_run/328 (0 (precise),0.00 per call) pfe_hif_chnl_is_tx_dma_active/334 (0 (precise),0.00 per call) oal_time_usleep/332 (0 (precise),0.00 per call) pfe_hif_chnl_is_tx_dma_active/334 (0 (precise),0.00 per call) pfe_hif_chnl_tx_disable/326 (0 (precise),0.00 per call) 
pfe_hif_drv_start/74 (pfe_hif_drv_start) @078f2000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_drv_client_unregister/55 (248034361 (estimated locally),0.23 per call) 
  Calls: pfe_hif_drv_start.part.0/349 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/89 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_init/73 (pfe_hif_drv_init) @078e5e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: __func__.11820/322 (addr)pfe_hif_drv_tx_job/32 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_init_err_handler/71 (0 (precise),0.00 per call) oal_job_create/323 (0 (precise),0.00 per call) pfe_hif_drv_attach_channels/72 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) pfe_hif_drv_create_data_channel/35 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/89 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_attach_channels/72 (pfe_hif_drv_attach_channels) @078e59a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_hif_drv_rx_job/30 (addr)pfe_hif_drv_chnl_tx_isr/31 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_drv_init/73 (0 (precise),0.00 per call) 
  Calls: pfe_hif_drv_init_err_handler/71 (177167401 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/90 (177167401 (estimated locally),0.17 per call) pfe_hm_report/89 (177167401 (estimated locally),0.17 per call) pfe_hif_chnl_set_event_cbk/327 (536870913 (estimated locally),0.50 per call) pfe_hif_drv_init_err_handler/71 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/90 (536870913 (estimated locally),0.50 per call) pfe_hm_report/89 (536870913 (estimated locally),0.50 per call) pfe_hif_chnl_set_event_cbk/327 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_destroy_data_channel/36 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) pfe_hif_chnl_set_event_cbk/327 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_init_err_handler/71 (pfe_hif_drv_init_err_handler) @078e5460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local unlikely_executed optimize_size
  Called by: pfe_hif_drv_init/73 (0 (precise),0.00 per call) pfe_hif_drv_attach_channels/72 (177167401 (estimated locally),0.17 per call) pfe_hif_drv_attach_channels/72 (536870913 (estimated locally),0.50 per call) 
  Calls: pfe_hif_drv_destroy_data_channel/36 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/89 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_set_event_cbk/327 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (116930485 (estimated locally),0.11 per call) pfe_hm_report/89 (116930485 (estimated locally),0.11 per call) pfe_hif_chnl_set_event_cbk/327 (354334802 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/90 (71717364 (estimated locally),0.07 per call) pfe_hm_report/89 (71717364 (estimated locally),0.07 per call) pfe_hif_chnl_set_event_cbk/327 (217325345 (estimated locally),0.20 per call) 
pfe_hif_drv_create/70 (pfe_hif_drv_create) @078d4e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: common_hif_drv/28 (addr)common_hif_drv/28 (write)common_hif_drv/28 (addr)
  Referring: 
  Availability: available
  Function flags: count:0 (precise) body unlikely_executed optimize_size
  Called by: 
  Calls: autolibc_memset/310 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) pfe_hif_chnl_get_meta_size/321 (0 (precise),0.00 per call) pfe_hif_chnl_get_meta_size/321 (0 (precise),0.00 per call) 
pfe_hif_drv_client_get_ts/69 (pfe_hif_drv_client_get_ts) @078d4620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_ptp_ts_db_pop/320 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_xmit_pkt/68 (pfe_hif_drv_client_xmit_pkt) @078d4000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_client_xmit_sg_pkt/67 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_xmit_sg_pkt/67 (pfe_hif_drv_client_xmit_sg_pkt) @078d4d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_drv_client_xmit_pkt/68 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_mutex_unlock.part.0/339 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_client_transmit_packet_buffers/66 (869730877 (estimated locally),0.81 per call) pfe_hif_drv_cfg_IEEE1588.isra.0/345 (869730877 (estimated locally),0.81 per call) pfe_hif_chnl_tx_dma_start/96 (96636764 (estimated locally),0.09 per call) __builtin_expect/84 (966367642 (estimated locally),0.90 per call) pfe_hif_chnl_can_accept_tx_num/316 (966367642 (estimated locally),0.90 per call) __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/338 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_transmit_packet_buffers/66 (pfe_hif_drv_client_transmit_packet_buffers) @078d48c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:160524402 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_xmit_sg_pkt/67 (869730877 (estimated locally),0.81 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/90 (101468602 (estimated locally),0.63 per call) pfe_hm_report/89 (101468602 (estimated locally),0.63 per call) __builtin_expect/84 (1014686025 (estimated locally),6.32 per call) pfe_hif_chnl_tx/319 (1014686025 (estimated locally),6.32 per call) 
pfe_hif_drv_init_tx_header/64 (pfe_hif_drv_init_tx_header) @078d41c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:0 (precise) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_hif_chnl_get_id/315 (0 (precise),0.00 per call) 
pfe_hif_drv_client_set_inject_if/63 (pfe_hif_drv_client_set_inject_if) @078c9ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_drv_process_tx/62 (pfe_hif_drv_process_tx) @078c99a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_drv_put_data_to_tx_conf_queue/61 (pfe_hif_drv_put_data_to_tx_conf_queue) @078c9e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_process_tx.constprop/351 (401742608 (estimated locally),3.50 per call) 
  Calls: __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) fifo_put/12 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_receive_tx_conf/59 (pfe_hif_drv_client_receive_tx_conf) @078c98c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: fifo_get/13 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_pkt_free/58 (pfe_hif_pkt_free) @078c9620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: hif_client_free_rx_queues/44 (1073741824 (estimated locally),8792.59 per call) 
  Calls: release_rx_buffer_with_check/40 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_has_rx_pkt/57 (pfe_hif_drv_client_has_rx_pkt) @078c9380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/90 (107374182 (estimated locally),0.10 per call) pfe_hm_report/89 (107374182 (estimated locally),0.10 per call) __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) fifo_get_fill_level/314 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_receive_pkt/56 (pfe_hif_drv_client_receive_pkt) @078c9000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: fifo_get/13 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_unregister/55 (pfe_hif_drv_client_unregister) @078bfb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_drv_client_register_ll/52 (378052685 (estimated locally),0.35 per call) 
  Calls: autolibc_memset/310 (751619278 (estimated locally),0.70 per call) pfe_hif_drv_start/74 (248034361 (estimated locally),0.23 per call) pfe_hif_ptp_ts_db_fini/312 (751619278 (estimated locally),0.70 per call) hif_client_free_tx_queues/45 (751619278 (estimated locally),0.70 per call) hif_client_free_rx_queues/44 (751619278 (estimated locally),0.70 per call) pfe_hif_drv_stop/77 (248034361 (estimated locally),0.23 per call) 
pfe_hif_drv_client_get_priv/54 (pfe_hif_drv_client_get_priv) @078bf2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_drv_client_get_drv/53 (pfe_hif_drv_client_get_drv) @078bfd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_drv_client_register_ll/52 (pfe_hif_drv_client_register_ll) @078bfa80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_register/50 (760700449 (estimated locally),0.71 per call) pfe_hif_drv_aux_client_register/49 (913754293 (estimated locally),0.85 per call) pfe_hif_drv_ihc_client_register/48 (0 (precise),0.00 per call) 
  Calls: pfe_hif_drv_client_unregister/55 (378052685 (estimated locally),0.35 per call) pfe_hif_drv_client_create_rx_tx.isra.0/344 (541273254 (estimated locally),0.50 per call) autolibc_memset/310 (541273254 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/90 (221083442 (estimated locally),0.21 per call) pfe_hm_report/89 (221083442 (estimated locally),0.21 per call) 
pfe_hif_drv_client_register/50 (pfe_hif_drv_client_register) @078bf1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_client_register_ll/52 (760700449 (estimated locally),0.71 per call) oal_util_raise_dem_for_drv_runtime_err/90 (133189620 (estimated locally),0.12 per call) pfe_hm_report/89 (133189620 (estimated locally),0.12 per call) oal_util_raise_dem_for_drv_runtime_err/90 (179851756 (estimated locally),0.17 per call) pfe_hm_report/89 (179851756 (estimated locally),0.17 per call) 
pfe_hif_drv_aux_client_register/49 (pfe_hif_drv_aux_client_register) @078b27e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_client_register_ll/52 (913754293 (estimated locally),0.85 per call) oal_util_raise_dem_for_drv_runtime_err/90 (159987532 (estimated locally),0.15 per call) pfe_hm_report/89 (159987532 (estimated locally),0.15 per call) 
pfe_hif_drv_ihc_client_register/48 (pfe_hif_drv_ihc_client_register) @078b2e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ihc_client_fifos/27 (addr)ihc_client_fifos/27 (addr)ihc_client_fifos/27 (addr)ihc_client_fifos/27 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_client_register_ll/52 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) fifo_create/309 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) fifo_create/309 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/89 (1073741824 (estimated locally),1.00 per call) 
hif_client_create_tx_queues/47 (hif_client_create_tx_queues) @078b2700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_create_rx_tx.isra.0/344 (966367642 (estimated locally),0.90 per call) 
  Calls: autolibc_memset/310 (118111600 (estimated locally),1.00 per call) 
hif_client_create_rx_queues/46 (hif_client_create_rx_queues) @078b2460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_create_rx_tx.isra.0/344 (1073741824 (estimated locally),1.00 per call) 
  Calls: autolibc_memset/310 (118111600 (estimated locally),1.00 per call) 
hif_client_free_tx_queues/45 (hif_client_free_tx_queues) @078b21c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:978178803 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_unregister/55 (751619278 (estimated locally),0.70 per call) 
  Calls: fifo_destroy/313 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (860067202 (estimated locally),0.88 per call) pfe_hm_report/89 (860067202 (estimated locally),0.88 per call) __builtin_expect/84 (860067202 (estimated locally),0.88 per call) fifo_get_fill_level/314 (860067202 (estimated locally),0.88 per call) __builtin_expect/84 (955630225 (estimated locally),0.98 per call) 
hif_client_free_rx_queues/44 (hif_client_free_rx_queues) @077019a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:122119 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_unregister/55 (751619278 (estimated locally),0.70 per call) 
  Calls: fifo_destroy/313 (0 (precise),0.00 per call) fifo_get/13 (1073741824 (estimated locally),8792.59 per call) pfe_hif_pkt_free/58 (1073741824 (estimated locally),8792.59 per call) fifo_get/13 (107374 (estimated locally),0.88 per call) __builtin_expect/84 (119304 (estimated locally),0.98 per call) 
pfe_hif_drv_process_rx/43 (pfe_hif_drv_process_rx) @07701ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_rx_job/30 (966367642 (estimated locally),0.90 per call) 
  Calls: pfe_hif_drv_notify_rx_clients/41 (118111601 (estimated locally),1.00 per call) release_rx_buffer_with_check/40 (55208443 (estimated locally),0.47 per call) __builtin_expect/84 (552084429 (estimated locally),4.67 per call) fifo_put/12 (552084429 (estimated locally),4.67 per call) pfe_hif_drv_process_ts/39 (182187861 (estimated locally),1.54 per call) release_rx_buffer_with_check/40 (133905170 (estimated locally),1.13 per call) pfe_hif_drv_process_ets/38 (133905170 (estimated locally),1.13 per call) release_rx_buffer_with_check/40 (76221067 (estimated locally),0.65 per call) __builtin_expect/84 (762210666 (estimated locally),6.45 per call) pfe_hif_drv_assign_client/37 (762210666 (estimated locally),6.45 per call) release_rx_buffer_with_check/40 (193419557 (estimated locally),1.64 per call) pfe_hif_drv_process_lifm/42 (955630223 (estimated locally),8.09 per call) pfe_hif_chnl_rx_va/87 (1073741824 (estimated locally),9.09 per call) 
pfe_hif_drv_process_lifm/42 (pfe_hif_drv_process_lifm) @07701b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_process_rx/43 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_hif_drv_notify_rx_clients/41 (pfe_hif_drv_notify_rx_clients) @077018c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_process_rx/43 (118111601 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(477815111 (estimated locally),4.05 per call) 
release_rx_buffer_with_check/40 (release_rx_buffer_with_check) @07701620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_pkt_free/58 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_process_rx/43 (55208443 (estimated locally),0.47 per call) pfe_hif_drv_process_rx/43 (133905170 (estimated locally),1.13 per call) pfe_hif_drv_process_rx/43 (76221067 (estimated locally),0.65 per call) pfe_hif_drv_process_rx/43 (193419557 (estimated locally),1.64 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/90 (107374182 (estimated locally),0.10 per call) pfe_hm_report/89 (107374182 (estimated locally),0.10 per call) __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_release_buf/94 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_process_ts/39 (pfe_hif_drv_process_ts) @077012a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_process_rx/43 (182187861 (estimated locally),1.54 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/90 (116930485 (estimated locally),0.11 per call) pfe_hm_report/89 (116930485 (estimated locally),0.11 per call) oal_util_raise_dem_for_drv_runtime_err/90 (27739370 (estimated locally),0.03 per call) pfe_hm_report/89 (27739370 (estimated locally),0.03 per call) pfe_hif_ptp_ts_db_push_ts/88 (84058696 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/90 (84058696 (estimated locally),0.08 per call) pfe_hm_report/89 (84058696 (estimated locally),0.08 per call) pfe_hif_ptp_ts_db_push_msg/93 (168117393 (estimated locally),0.16 per call) oal_util_parse_ptp/92 (354334802 (estimated locally),0.33 per call) oal_util_get_unique_seqnum32/91 (354334802 (estimated locally),0.33 per call) 
pfe_hif_drv_process_ets/38 (pfe_hif_drv_process_ets) @07831c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:254355476 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_process_rx/43 (133905170 (estimated locally),1.13 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/90 (83937307 (estimated locally),0.33 per call) pfe_hm_report/89 (83937307 (estimated locally),0.33 per call) pfe_hif_ptp_ts_db_push_ts/88 (254355476 (estimated locally),1.00 per call) 
   Indirect call(324512696 (estimated locally),1.28 per call) 
pfe_hif_drv_assign_client/37 (pfe_hif_drv_assign_client) @07831460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_process_rx/43 (762210666 (estimated locally),6.45 per call) 
  Calls: 
pfe_hif_drv_destroy_data_channel/36 (pfe_hif_drv_destroy_data_channel) @07831e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_drv_exit.part.0/350 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_attach_channels/72 (0 (precise),0.00 per call) pfe_hif_drv_init_err_handler/71 (0 (precise),0.00 per call) pfe_hif_drv_create_data_channel/35 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_tx_disable/326 (0 (precise),0.00 per call) pfe_hif_chnl_rx_disable/325 (0 (precise),0.00 per call) 
pfe_hif_drv_create_data_channel/35 (pfe_hif_drv_create_data_channel) @07831b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) body local unlikely_executed optimize_size
  Called by: pfe_hif_drv_init/73 (0 (precise),0.00 per call) 
  Calls: autolibc_memset/310 (0 (precise),0.00 per call) pfe_hif_chnl_get_tx_fifo_depth/324 (0 (precise),0.00 per call) pfe_hif_drv_destroy_data_channel/36 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/90 (0 (precise),0.00 per call) pfe_hm_report/89 (0 (precise),0.00 per call) pfe_hif_chnl_get_meta_size/321 (0 (precise),0.00 per call) pfe_hif_chnl_get_meta_size/321 (0 (precise),0.00 per call) 
pfe_hif_drv_client_ptp_ts_db_tick_iteration/34 (pfe_hif_drv_client_ptp_ts_db_tick_iteration) @078318c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_ptp_ts_db_tick_iteration/308 (574129754 (estimated locally),0.53 per call) 
pfe_hif_drv_client_tx_done/33 (pfe_hif_drv_client_tx_done) @07831620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: pfe_hif_drv_client_rx_done/29 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_tx_job/32 (pfe_hif_drv_tx_job) @07831380
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: 
  Referring: pfe_hif_drv_init/73 (addr)
  Availability: available
  Function flags: count:131235111 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_tx_job.part.0/343 (118111600 (estimated locally),0.90 per call) oal_mutex_lock.part.0/338 (118111600 (estimated locally),0.90 per call) __builtin_expect/84 (131235111 (estimated locally),1.00 per call) 
pfe_hif_drv_chnl_tx_isr/31 (pfe_hif_drv_chnl_tx_isr) @07831000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: pfe_hif_drv_attach_channels/72 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_chnl_tx_isr.part.0/348 (107374184 (estimated locally),0.10 per call) __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) oal_job_run/328 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_rx_job/30 (pfe_hif_drv_rx_job) @0782be00
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: 
  Referring: pfe_hif_drv_attach_channels/72 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_rx_dma_start/86 (966367642 (estimated locally),0.90 per call) pfe_hif_chnl_rx_irq_unmask/85 (966367642 (estimated locally),0.90 per call) pfe_hif_drv_process_rx/43 (966367642 (estimated locally),0.90 per call) __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_drv_client_rx_done/29 (pfe_hif_drv_client_rx_done) @0782ba80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: pfe_hif_drv_client_tx_done/33 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
common_hif_drv/28 (common_hif_drv) @078830d8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_hif_drv_create/70 (addr)pfe_hif_drv_create/70 (write)pfe_hif_drv_create/70 (addr)
  Availability: available
  Varpool flags:
ihc_client_fifos/27 (ihc_client_fifos) @07883048
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_hif_drv_ihc_client_register/48 (addr)pfe_hif_drv_ihc_client_register/48 (addr)pfe_hif_drv_ihc_client_register/48 (addr)pfe_hif_drv_ihc_client_register/48 (addr)
  Availability: available
  Varpool flags:
fifo_get/13 (fifo_get) @073b1620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_client_receive_tx_conf/59 (1073741824 (estimated locally),1.00 per call) hif_client_free_rx_queues/44 (1073741824 (estimated locally),8792.59 per call) hif_client_free_rx_queues/44 (107374 (estimated locally),0.88 per call) pfe_hif_drv_client_receive_pkt/56 (1073741824 (estimated locally),1.00 per call) 
  Calls: __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) 
fifo_put/12 (fifo_put) @073b1380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_hif_drv_process_rx/43 (552084429 (estimated locally),4.67 per call) pfe_hif_drv_put_data_to_tx_conf_queue/61 (1073741824 (estimated locally),1.00 per call) 
  Calls: __builtin_expect/84 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06f60ca8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/203 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/204 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/205 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/206 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/207 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/208 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/209 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/210 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/211 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/212 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/213 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/214 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/215 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/216 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/217 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/218 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/219 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/220 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/221 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/222 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/223 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/224 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/225 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/226 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/227 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/228 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/229 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/230 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/231 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/232 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/233 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/234 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/235 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/236 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/237 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/238 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/239 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/240 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/241 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/242 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/243 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/244 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/245 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/246 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/247 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/248 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/249 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/250 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/251 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/252 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/253 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/254 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/255 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/256 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/257 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/258 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/259 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/260 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/261 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/262 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/263 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/264 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/265 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/266 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/267 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/268 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/269 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/270 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/271 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/272 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/273 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/274 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/275 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/276 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/277 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/278 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/279 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/280 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/281 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/282 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/283 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/284 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/285 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/286 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/287 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/288 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/289 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/290 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/291 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/292 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/293 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/294 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/295 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/296 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/297 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/298 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/299 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/300 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/301 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/302 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/303 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/304 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/305 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/306 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/307 (addr)
  Referring: oal_mutex_unlock.part.0/339 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06f60bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/97 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/98 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/99 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/100 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/101 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/102 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/103 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/104 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/105 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/106 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/107 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/108 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/109 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/110 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/111 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/112 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/113 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/114 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/115 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/116 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/117 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/118 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/119 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/120 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/121 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/122 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/123 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/124 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/125 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/126 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/127 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/128 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/129 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/130 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/131 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/132 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/133 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/134 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/135 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/136 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/137 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/138 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/139 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/140 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/141 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/142 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/143 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/144 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/145 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/146 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/147 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/148 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/149 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/150 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/151 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/152 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/153 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/154 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/155 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/156 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/157 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/158 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/159 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/160 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/161 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/162 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/163 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/164 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/165 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/166 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/167 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/168 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/169 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/170 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/171 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/172 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/173 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/174 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/175 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/176 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/177 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/178 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/179 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/180 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/181 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/182 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/183 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/184 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/185 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/186 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/187 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/188 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/189 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/190 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/191 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/192 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/193 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/194 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/195 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/196 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/197 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/198 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/199 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/200 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/201 (addr)
  Referring: oal_mutex_lock.part.0/338 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function fifo_get (fifo_get, funcdef_no=11, decl_uid=9236, cgraph_uid=12, symbol_order=13)

Modification phase of node fifo_get/13
fifo_get (volatile struct fifo_t * const fifo)
{
  void * ret;
  long unsigned int _1;
  long unsigned int _2;
  _Bool _3;
  long int _4;
  long int _5;
  void * * _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  void * * _11;
  long unsigned int _12;
  long unsigned int _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} fifo_17(D)->write;
  _2 ={v} fifo_17(D)->read;
  # DEBUG fill_level => _1 - _2
  # DEBUG BEGIN_STMT
  _3 = _1 != _2;
  _4 = (long int) _3;
  _5 = __builtin_expect (_4, 1);
  if (_5 != 0)
    goto <bb 3>; [90.00%]
  else
    goto <bb 4>; [10.00%]

  <bb 3> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _6 ={v} fifo_17(D)->data;
  _7 ={v} fifo_17(D)->read;
  _8 ={v} fifo_17(D)->depth_mask;
  _9 = _7 & _8;
  _10 = _9 * 4;
  _11 = _6 + _10;
  ret_18 = *_11;
  # DEBUG ret => ret_18
  # DEBUG BEGIN_STMT
  _12 ={v} fifo_17(D)->read;
  _13 = _12 + 1;
  fifo_17(D)->read ={v} _13;

  <bb 4> [local count: 1073741824]:
  # ret_14 = PHI <0B(2), ret_18(3)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  return ret_14;

}



;; Function release_rx_buffer_with_check (release_rx_buffer_with_check, funcdef_no=35, decl_uid=11460, cgraph_uid=36, symbol_order=40)

Modification phase of node release_rx_buffer_with_check/40
release_rx_buffer_with_check (struct pfe_hif_drv_t * hif_drv, const void * current_buffer_va)
{
  errno_t ret;
  struct pfe_hif_chnl_t * _1;
  _Bool _2;
  long int _3;
  long int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = hif_drv_7(D)->channel;
  ret_10 = pfe_hif_chnl_release_buf (_1, current_buffer_va_8(D));
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  _2 = ret_10 != 0;
  _3 = (long int) _2;
  _4 = __builtin_expect (_3, 0);
  if (_4 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unable to release RX buffer%d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 642, ret_10, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_drv_destroy_data_channel (pfe_hif_drv_destroy_data_channel, funcdef_no=31, decl_uid=11423, cgraph_uid=32, symbol_order=36) (unlikely executed)

Modification phase of node pfe_hif_drv_destroy_data_channel/36
pfe_hif_drv_destroy_data_channel (struct pfe_hif_drv_t * hif_drv)
{
  struct pfe_hif_chnl_t * _1;
  struct pfe_hif_chnl_t * _2;

  <bb 2> [count: 0]:
  # DEBUG BEGIN_STMT
  _1 = hif_drv_4(D)->channel;
  pfe_hif_chnl_rx_disable (_1);
  # DEBUG BEGIN_STMT
  _2 = hif_drv_4(D)->channel;
  pfe_hif_chnl_tx_disable (_2);
  return;

}



;; Function pfe_hif_drv_init_err_handler (pfe_hif_drv_init_err_handler, funcdef_no=66, decl_uid=11442, cgraph_uid=67, symbol_order=71) (unlikely executed)

Modification phase of node pfe_hif_drv_init_err_handler/71
Adjusting mask for param 1 to 0xf
Setting value range of param 1 [6, 9]
pfe_hif_drv_init_err_handler (struct pfe_hif_drv_t * hif_drv, uint_t err_level)
{
  struct pfe_hif_chnl_t * _1;
  int _2;
  struct pfe_hif_chnl_t * _3;
  int _4;
  struct pfe_hif_chnl_t * _5;
  int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (err_level_10(D) == 9)
    goto <bb 3>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  _1 = hif_drv_12(D)->channel;
  _2 = pfe_hif_chnl_set_event_cbk (_1, 4, 0B, 0B);
  if (_2 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] pfe_hif_chnl_set_event_cbk() failed (RX OOB callback)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2087, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_level_10(D) > 6)
    goto <bb 6>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 6> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _3 = hif_drv_12(D)->channel;
  _4 = pfe_hif_chnl_set_event_cbk (_3, 2, 0B, 0B);
  if (_4 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 116930485]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] pfe_hif_chnl_set_event_cbk() failed (TX callback)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2096, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_level_10(D) > 5)
    goto <bb 9>; [100.00%]
  else
    goto <bb 11>; [0.00%]

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = hif_drv_12(D)->channel;
  _6 = pfe_hif_chnl_set_event_cbk (_5, 1, 0B, 0B);
  if (_6 != 0)
    goto <bb 10>; [100.00%]
  else
    goto <bb 11>; [0.00%]

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] pfe_hif_chnl_set_event_cbk() failed (RX callback)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2105, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 11> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hif_drv_destroy_data_channel (hif_drv_12(D));
  return;

}



;; Function pfe_hif_drv_chnl_tx_isr (pfe_hif_drv_chnl_tx_isr, funcdef_no=26, decl_uid=11465, cgraph_uid=27, symbol_order=31)

Modification phase of node pfe_hif_drv_chnl_tx_isr/31
pfe_hif_drv_chnl_tx_isr (void * arg)
{
  struct oal_job_t * _1;
  int _2;
  _Bool _3;
  long int _4;
  long int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG hif_drv => arg_6(D)
  # DEBUG BEGIN_STMT
  _1 = &MEM[(struct pfe_hif_drv_t *)arg_6(D)].tx_job;
  _2 = oal_job_run (_1);
  _3 = _2 != 0;
  _4 = (long int) _3;
  _5 = __builtin_expect (_4, 0);
  if (_5 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374184]:
  # DEBUG D#10 => arg_6(D)
  pfe_hif_drv_chnl_tx_isr.part.0 ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_drv_tx_job (pfe_hif_drv_tx_job, funcdef_no=27, decl_uid=9383, cgraph_uid=28, symbol_order=32)

Modification phase of node pfe_hif_drv_tx_job/32
pfe_hif_drv_tx_job (void * arg)
{
  unsigned char _1;
  _Bool _2;
  long int _3;
  long int _4;

  <bb 2> [local count: 131235111]:
  # DEBUG BEGIN_STMT
  # DEBUG hif_drv => arg_5(D)
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct pfe_hif_drv_t *)arg_5(D)].tx_enabled;
  _2 = _1 == 1;
  _3 = (long int) _2;
  _4 = __builtin_expect (_3, 1);
  if (_4 != 0)
    goto <bb 3>; [90.00%]
  else
    goto <bb 4>; [10.00%]

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 91
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (91);
  # DEBUG BEGIN_STMT
  pfe_hif_drv_tx_job.part.0 (arg_5(D));

  <bb 4> [local count: 131235112]:
  return;

}



;; Function pfe_hif_drv_rx_job (pfe_hif_drv_rx_job, funcdef_no=25, decl_uid=9381, cgraph_uid=26, symbol_order=30)

Modification phase of node pfe_hif_drv_rx_job/30
pfe_hif_drv_rx_job (void * arg)
{
  unsigned char _1;
  _Bool _2;
  long int _3;
  long int _4;
  struct pfe_hif_chnl_t * _5;
  struct pfe_hif_chnl_t * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG hif_drv => arg_8(D)
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct pfe_hif_drv_t *)arg_8(D)].rx_enabled;
  _2 = _1 == 1;
  _3 = (long int) _2;
  _4 = __builtin_expect (_3, 1);
  if (_4 != 0)
    goto <bb 3>; [90.00%]
  else
    goto <bb 4>; [10.00%]

  <bb 3> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_process_rx (arg_8(D));
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct pfe_hif_drv_t *)arg_8(D)].channel;
  pfe_hif_chnl_rx_irq_unmask (_5);
  # DEBUG BEGIN_STMT
  _6 = MEM[(struct pfe_hif_drv_t *)arg_8(D)].channel;
  pfe_hif_chnl_rx_dma_start (_6);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function pfe_hif_drv_client_rx_done (pfe_hif_drv_client_rx_done, funcdef_no=24, decl_uid=9416, cgraph_uid=25, symbol_order=29)

Modification phase of node pfe_hif_drv_client_rx_done/29
pfe_hif_drv_client_rx_done (const struct pfe_hif_drv_client_t * client)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_drv_client_tx_done (pfe_hif_drv_client_tx_done, funcdef_no=89, decl_uid=9418, cgraph_uid=29, symbol_order=33)

Modification phase of node pfe_hif_drv_client_tx_done/33
pfe_hif_drv_client_tx_done (const struct pfe_hif_drv_client_t * client)
{
  <bb 2> [local count: 1073741824]:
  pfe_hif_drv_client_rx_done (client_1(D)); [tail call]
  return;

}



;; Function pfe_hif_drv_client_ptp_ts_db_tick_iteration (pfe_hif_drv_client_ptp_ts_db_tick_iteration, funcdef_no=29, decl_uid=9420, cgraph_uid=30, symbol_order=34)

Modification phase of node pfe_hif_drv_client_ptp_ts_db_tick_iteration/34
pfe_hif_drv_client_ptp_ts_db_tick_iteration (struct pfe_hif_drv_client_t * client)
{
  struct pfe_hif_ptp_ts_db_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (client_3(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _1 = &client_3(D)->ptpdb;
  pfe_hif_ptp_ts_db_tick_iteration (_1);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function pfe_hif_drv_client_get_drv (pfe_hif_drv_client_get_drv, funcdef_no=48, decl_uid=9410, cgraph_uid=49, symbol_order=53)

Modification phase of node pfe_hif_drv_client_get_drv/53
pfe_hif_drv_client_get_drv (const struct pfe_hif_drv_client_t * client)
{
  struct pfe_hif_drv_t * ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0B
  # DEBUG BEGIN_STMT
  ret_3 = client_2(D)->hif_drv;
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_hif_drv_client_get_priv (pfe_hif_drv_client_get_priv, funcdef_no=49, decl_uid=9412, cgraph_uid=50, symbol_order=54)

Modification phase of node pfe_hif_drv_client_get_priv/54
pfe_hif_drv_client_get_priv (const struct pfe_hif_drv_client_t * client)
{
  void * ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0B
  # DEBUG BEGIN_STMT
  ret_3 = client_2(D)->priv;
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_hif_drv_client_receive_pkt (pfe_hif_drv_client_receive_pkt, funcdef_no=51, decl_uid=9445, cgraph_uid=52, symbol_order=56)

Modification phase of node pfe_hif_drv_client_receive_pkt/56
pfe_hif_drv_client_receive_pkt (struct pfe_hif_drv_client_t * client, uint32_t queue)
{
  struct pfe_hif_pkt_t * ret;
  volatile struct fifo_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = client_3(D)->rx_q[queue_4(D)].rx_fifo;
  ret_6 = fifo_get (_1);
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_hif_drv_client_has_rx_pkt (pfe_hif_drv_client_has_rx_pkt, funcdef_no=52, decl_uid=9442, cgraph_uid=53, symbol_order=57)

Modification phase of node pfe_hif_drv_client_has_rx_pkt/57
pfe_hif_drv_client_has_rx_pkt (const struct pfe_hif_drv_client_t * client, uint32_t queue)
{
  bool_t ret;
  errno_t err;
  uint32_t fill_level;
  volatile struct fifo_t * _1;
  _Bool _2;
  long int _3;
  long int _4;
  long unsigned int fill_level.41_5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1
  # DEBUG BEGIN_STMT
  _1 = client_9(D)->rx_q[queue_10(D)].rx_fifo;
  err_12 = fifo_get_fill_level (_1, &fill_level);
  # DEBUG err => err_12
  # DEBUG BEGIN_STMT
  _2 = err_12 != 0;
  _3 = (long int) _2;
  _4 = __builtin_expect (_3, 0);
  if (_4 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unable to get fifo fill level: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1441, err_12, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  fill_level = 0;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  fill_level.41_5 = fill_level;
  if (fill_level.41_5 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 6> [local count: 1073741823]:
  # ret_6 = PHI <1(4), 0(5)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  fill_level ={v} {CLOBBER};
  return ret_6;

}



;; Function pfe_hif_pkt_free (pfe_hif_pkt_free, funcdef_no=53, decl_uid=9447, cgraph_uid=54, symbol_order=58)

Modification phase of node pfe_hif_pkt_free/58
pfe_hif_pkt_free (const struct pfe_hif_pkt_t * pkt)
{
  struct pfe_hif_drv_client_t * _1;
  struct pfe_hif_drv_t * _2;
  unsigned int _3;
  const void * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pkt_6(D)->client;
  _2 = _1->hif_drv;
  _3 = pkt_6(D)->data;
  _4 = (const void *) _3;
  release_rx_buffer_with_check (_2, _4);
  return;

}



;; Function pfe_hif_drv_client_receive_tx_conf (pfe_hif_drv_client_receive_tx_conf, funcdef_no=54, decl_uid=9439, cgraph_uid=55, symbol_order=59)

Modification phase of node pfe_hif_drv_client_receive_tx_conf/59
pfe_hif_drv_client_receive_tx_conf (const struct pfe_hif_drv_client_t * client, uint32_t queue)
{
  void * ret;
  volatile struct fifo_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = client_3(D)->tx_q[queue_4(D)].tx_conf_fifo;
  ret_6 = fifo_get (_1);
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_hif_drv_client_set_inject_if (pfe_hif_drv_client_set_inject_if, funcdef_no=58, decl_uid=9408, cgraph_uid=59, symbol_order=63)

Modification phase of node pfe_hif_drv_client_set_inject_if/63
pfe_hif_drv_client_set_inject_if (struct pfe_hif_drv_client_t * client, pfe_ct_phy_if_id_t phy_if_id)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (phy_if_id_3(D) > 9)
    goto <bb 4>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  client_5(D)->phy_if_id = phy_if_id_3(D);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_1 = PHI <22(2), 0(3)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_hif_drv_init_tx_header (pfe_hif_drv_init_tx_header, funcdef_no=59, decl_uid=9424, cgraph_uid=60, symbol_order=64) (unlikely executed)

Modification phase of node pfe_hif_drv_init_tx_header/64
pfe_hif_drv_init_tx_header (struct pfe_hif_drv_client_t * client, struct pfe_ct_hif_tx_hdr_t * tx_header, const uint32_t queue)
{
  struct pfe_hif_drv_t * _1;
  struct pfe_hif_chnl_t * _2;
  long unsigned int _3;
  unsigned char _4;
  unsigned char _5;
  long unsigned int _6;
  <unnamed type> _7;
  int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;

  <bb 2> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = client_21(D)->hif_drv;
  _2 = _1->channel;
  _3 = pfe_hif_chnl_get_id (_2);
  _4 = (unsigned char) _3;
  tx_header_22(D)->chid = _4;
  # DEBUG BEGIN_STMT
  _5 = (unsigned char) queue_24(D);
  tx_header_22(D)->queue = _5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tx_header_22(D)->flags = 58;
  # DEBUG BEGIN_STMT
  _6 = client_21(D)->id_mask;
  if (_6 == 2048)
    goto <bb 3>; [0.00%]
  else
    goto <bb 4>; [0.00%]

  <bb 3> [count: 0]:
  # DEBUG BEGIN_STMT
  tx_header_22(D)->e_phy_ifs = 0;
  goto <bb 5>; [0.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  _7 = client_21(D)->phy_if_id;
  _8 = (int) _7;
  _9 = 1 << _8;
  _10 = _9 >> 24;
  _11 = _9 >> 8;
  _12 = _11 & 65280;
  _13 = _10 | _12;
  _14 = _9 << 8;
  _15 = _14 & 16711680;
  _16 = _13 | _15;
  _17 = _9 << 24;
  _18 = _16 | _17;
  tx_header_22(D)->e_phy_ifs = _18;
  # DEBUG BEGIN_STMT
  tx_header_22(D)->flags = 122;

  <bb 5> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hif_drv_client_xmit_sg_pkt (pfe_hif_drv_client_xmit_sg_pkt, funcdef_no=62, decl_uid=9436, cgraph_uid=63, symbol_order=67)

Modification phase of node pfe_hif_drv_client_xmit_sg_pkt/67
pfe_hif_drv_client_xmit_sg_pkt (struct pfe_hif_drv_client_t * client, uint32_t queue, const struct hif_drv_sg_list_t * const sg_list, void * ref_ptr)
{
  struct pfe_ct_hif_tx_hdr_t * tx_hdr;
  struct pfe_hif_drv_t * hif_drv;
  struct pfe_hif_tx_meta_t * tx_metadata;
  errno_t err;
  unsigned char _1;
  _Bool _2;
  long int _3;
  long int _4;
  struct pfe_hif_chnl_t * _5;
  long unsigned int _6;
  short unsigned int _7;
  unsigned char _8;
  _Bool _9;
  long int _10;
  long int _11;
  long unsigned int _12;
  unsigned char _13;
  unsigned char _14;
  unsigned char _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  hif_drv_23 = client_22(D)->hif_drv;
  # DEBUG hif_drv => hif_drv_23
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 92
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (92);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = hif_drv_23->tx_enabled;
  _2 = _1 == 0;
  _3 = (long int) _2;
  _4 = __builtin_expect (_3, 0);
  if (_4 != 0)
    goto <bb 8>; [10.00%]
  else
    goto <bb 3>; [90.00%]

  <bb 3> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _5 = hif_drv_23->channel;
  _6 = sg_list_24(D)->size;
  _7 = (short unsigned int) _6;
  _8 = pfe_hif_chnl_can_accept_tx_num (_5, _7);
  _9 = _8 == 0;
  _10 = (long int) _9;
  _11 = __builtin_expect (_10, 0);
  if (_11 != 0)
    goto <bb 4>; [10.00%]
  else
    goto <bb 5>; [90.00%]

  <bb 4> [local count: 96636764]:
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_tx_dma_start (_5);
  # DEBUG BEGIN_STMT
  # DEBUG err => 113
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 869730877]:
  # DEBUG BEGIN_STMT
  _12 = hif_drv_23->tx_meta_wr_idx;
  tx_metadata_25 = &hif_drv_23->tx_meta[_12];
  # DEBUG tx_metadata => tx_metadata_25
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_hif_tx_meta_t *)hif_drv_23].tx_meta[_12].client = client_22(D);
  # DEBUG BEGIN_STMT
  _13 = (unsigned char) queue_27(D);
  MEM[(struct pfe_hif_tx_meta_t *)hif_drv_23].tx_meta[_12].q_no = _13;
  # DEBUG BEGIN_STMT
  tx_hdr_29 = sg_list_24(D)->items[0].data_va;
  # DEBUG tx_hdr => tx_hdr_29
  # DEBUG BEGIN_STMT
  _14 = tx_hdr_29->flags;
  _15 = _14 & 251;
  tx_hdr_29->flags = _15;
  # DEBUG BEGIN_STMT
  # DEBUG D#9 => tx_metadata_25
  pfe_hif_drv_cfg_IEEE1588.isra.0 (client_22(D), tx_hdr_29, tx_metadata_25, sg_list_24(D), ref_ptr_31(D));
  # DEBUG err => NULL
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_hif_tx_meta_t *)hif_drv_23].tx_meta[_12].ref_ptr = ref_ptr_31(D);
  # DEBUG BEGIN_STMT
  err_35 = pfe_hif_drv_client_transmit_packet_buffers (client_22(D), sg_list_24(D));
  # DEBUG err => err_35
  # DEBUG BEGIN_STMT
  if (err_35 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 434865438]:
  # DEBUG BEGIN_STMT
  _16 = hif_drv_23->tx_meta_wr_idx;
  _17 = _16 + 1;
  hif_drv_23->tx_meta_wr_idx = _17;
  # DEBUG BEGIN_STMT
  _18 = hif_drv_23->tx_meta_number;
  if (_17 >= _18)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 217432719]:
  # DEBUG BEGIN_STMT
  hif_drv_23->tx_meta_wr_idx = 0;

  <bb 8> [local count: 1073741824]:
  # err_19 = PHI <115(2), 113(4), err_35(5), 0(6), 0(7)>
  # DEBUG err => err_19
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 92
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (92);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return err_19;

}



;; Function pfe_hif_drv_client_xmit_pkt (pfe_hif_drv_client_xmit_pkt, funcdef_no=63, decl_uid=9431, cgraph_uid=64, symbol_order=68)

Modification phase of node pfe_hif_drv_client_xmit_pkt/68
pfe_hif_drv_client_xmit_pkt (struct pfe_hif_drv_client_t * client, uint32_t queue, void * data_pa, void * data_va, uint32_t len, void * ref_ptr)
{
  struct hif_drv_sg_list_t sg_list;
  errno_t _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sg_list.size = 1;
  # DEBUG BEGIN_STMT
  sg_list.flags.specific.tx_flags = 0;
  # DEBUG BEGIN_STMT
  sg_list.items[0].data_pa = data_pa_4(D);
  # DEBUG BEGIN_STMT
  sg_list.items[0].data_va = data_va_6(D);
  # DEBUG BEGIN_STMT
  sg_list.items[0].len = len_8(D);
  # DEBUG BEGIN_STMT
  sg_list.dst_phy = 10;
  # DEBUG BEGIN_STMT
  _15 = pfe_hif_drv_client_xmit_sg_pkt (client_11(D), queue_12(D), &sg_list, ref_ptr_13(D));
  sg_list ={v} {CLOBBER};
  return _15;

}



;; Function pfe_hif_drv_client_get_ts (pfe_hif_drv_client_get_ts, funcdef_no=64, decl_uid=9455, cgraph_uid=65, symbol_order=69)

Modification phase of node pfe_hif_drv_client_get_ts/69
pfe_hif_drv_client_get_ts (struct pfe_hif_drv_client_t * const client, bool_t rx, uint8_t type, uint16_t port, uint16_t seq_id, uint32_t * const ts_sec, uint32_t * const ts_nsec)
{
  struct pfe_hif_ptp_ts_db_t * _1;
  errno_t _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = &client_2(D)->ptpdb;
  _11 = pfe_hif_ptp_ts_db_pop (_1, type_4(D), port_5(D), seq_id_6(D), ts_sec_7(D), ts_nsec_8(D), rx_9(D));
  return _11;

}



;; Function pfe_hif_drv_create (pfe_hif_drv_create, funcdef_no=65, decl_uid=9367, cgraph_uid=66, symbol_order=70) (unlikely executed)

Modification phase of node pfe_hif_drv_create/70
pfe_hif_drv_create (struct pfe_hif_chnl_t * channel)
{
  struct pfe_hif_drv_t * hif_drv;
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_hif_chnl_get_meta_size (channel_6(D));
  if (_1 <= 20)
    goto <bb 3>; [0.00%]
  else
    goto <bb 4>; [0.00%]

  <bb 3> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pfe_hif_chnl_get_meta_size (channel_6(D));
  pfe_hm_report (1, 2, 1, "[%s:%d] Meta storage size (%u) is less than required (%u)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2067, _2, 21, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG hif_drv => 0B
  goto <bb 5>; [0.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG hif_drv => &common_hif_drv
  # DEBUG BEGIN_STMT
  autolibc_memset (&common_hif_drv, 0, 21824);
  # DEBUG BEGIN_STMT
  common_hif_drv.channel = channel_6(D);

  <bb 5> [count: 0]:
  # hif_drv_3 = PHI <0B(3), &common_hif_drv(4)>
  # DEBUG hif_drv => hif_drv_3
  # DEBUG BEGIN_STMT
  return hif_drv_3;

}



;; Function pfe_hif_drv_init (pfe_hif_drv_init, funcdef_no=68, decl_uid=9371, cgraph_uid=69, symbol_order=73)

Modification phase of node pfe_hif_drv_init/73
pfe_hif_drv_init (struct pfe_hif_drv_t * hif_drv)
{
  static const char __func__[17] = "pfe_hif_drv_init";
  errno_t ret;
  unsigned char _1;
  int _2;
  struct oal_job_t * _3;
  struct oal_job_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 ={v} hif_drv_8(D)->initialized;
  if (_1 != 0)
    goto <bb 3>; [100.00%]
  else
    goto <bb 4>; [0.00%]

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF already initialized. Exiting.\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2173, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 121
  goto <bb 10>; [100.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  hif_drv_8(D)->started = 0;
  # DEBUG BEGIN_STMT
  _2 = pfe_hif_drv_create_data_channel (hif_drv_8(D));
  if (_2 != 0)
    goto <bb 5>; [0.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 5> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] %s: Could not initialize data channel\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2183, &__func__, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 11
  goto <bb 10>; [0.00%]

  <bb 6> [count: 0]:
  # DEBUG BEGIN_STMT
  ret_12 = pfe_hif_drv_attach_channels (hif_drv_8(D));
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  if (ret_12 == 0)
    goto <bb 7>; [0.00%]
  else
    goto <bb 10>; [0.00%]

  <bb 7> [count: 0]:
  # DEBUG BEGIN_STMT
  _3 = &hif_drv_8(D)->tx_job;
  _4 = oal_job_create (pfe_hif_drv_tx_job, hif_drv_8(D), "HIF TX JOB", 1, _3);
  if (_4 == 0B)
    goto <bb 8>; [0.00%]
  else
    goto <bb 9>; [0.00%]

  <bb 8> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  # DEBUG BEGIN_STMT
  pfe_hif_drv_init_err_handler (hif_drv_8(D), 9);
  goto <bb 10>; [0.00%]

  <bb 9> [count: 0]:
  # DEBUG BEGIN_STMT
  hif_drv_8(D)->rx_enabled = 0;
  # DEBUG BEGIN_STMT
  hif_drv_8(D)->tx_enabled = 0;
  # DEBUG BEGIN_STMT
  hif_drv_8(D)->initialized ={v} 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 10> [local count: 1073741824]:
  # ret_5 = PHI <121(3), 11(5), ret_12(6), 117(8), 0(9)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_hif_drv_start (pfe_hif_drv_start, funcdef_no=69, decl_uid=9373, cgraph_uid=70, symbol_order=74)

Modification phase of node pfe_hif_drv_start/74
pfe_hif_drv_start (struct pfe_hif_drv_t * hif_drv)
{
  errno_t ret;
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} hif_drv_4(D)->initialized;
  if (_1 == 0)
    goto <bb 3>; [100.00%]
  else
    goto <bb 4>; [0.00%]

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF driver not initialized\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2233, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 19
  goto <bb 5>; [100.00%]

  <bb 4> [count: 0]:
  ret_9 = pfe_hif_drv_start.part.0 (hif_drv_4(D));

  <bb 5> [local count: 1073741824]:
  # ret_2 = PHI <19(3), ret_9(4)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_hif_drv_stop (pfe_hif_drv_stop, funcdef_no=72, decl_uid=9375, cgraph_uid=73, symbol_order=77)

Modification phase of node pfe_hif_drv_stop/77
pfe_hif_drv_stop (struct pfe_hif_drv_t * hif_drv)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_stop_rx (hif_drv_2(D));
  # DEBUG BEGIN_STMT
  pfe_hif_drv_stop_tx (hif_drv_2(D));
  return;

}



;; Function pfe_hif_drv_client_unregister (pfe_hif_drv_client_unregister, funcdef_no=50, decl_uid=9414, cgraph_uid=51, symbol_order=55)

Modification phase of node pfe_hif_drv_client_unregister/55
pfe_hif_drv_client_unregister (struct pfe_hif_drv_client_t * client)
{
  bool_t enabled;
  struct pfe_hif_drv_t * _1;
  unsigned char _2;
  unsigned char _3;
  struct pfe_hif_ptp_ts_db_t * _4;
  struct pfe_hif_drv_t * _5;
  int iftmp.39_6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG enabled => 0
  # DEBUG BEGIN_STMT
  if (client_10(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 11>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = client_10(D)->hif_drv;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = _1->tx_enabled;
  if (_2 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 375809639]:
  _3 = _1->rx_enabled;
  if (_3 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 187904819]:

  <bb 6> [local count: 751619278]:
  # iftmp.39_6 = PHI <1(4), 0(5), 1(3)>
  enabled_12 = (bool_t) iftmp.39_6;
  # DEBUG enabled => enabled_12
  # DEBUG BEGIN_STMT
  if (enabled_12 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 248034361]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_stop (_1);

  <bb 8> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  client_10(D)->active = 0;
  # DEBUG BEGIN_STMT
  hif_client_free_rx_queues (client_10(D));
  # DEBUG BEGIN_STMT
  hif_client_free_tx_queues (client_10(D));
  # DEBUG BEGIN_STMT
  _4 = &client_10(D)->ptpdb;
  pfe_hif_ptp_ts_db_fini (_4);
  # DEBUG BEGIN_STMT
  if (enabled_12 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 248034361]:
  # DEBUG BEGIN_STMT
  _5 = client_10(D)->hif_drv;
  pfe_hif_drv_start (_5);

  <bb 10> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  autolibc_memset (client_10(D), 0, 1792);

  <bb 11> [local count: 1073741824]:
  return;

}



;; Function pfe_hif_drv_client_register_ll (pfe_hif_drv_client_register_ll, funcdef_no=47, decl_uid=11435, cgraph_uid=48, symbol_order=52)

Modification phase of node pfe_hif_drv_client_register_ll/52
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
pfe_hif_drv_client_register_ll (struct pfe_hif_drv_client_t * client, struct pfe_hif_drv_client_data * client_data)
{
  struct pfe_hif_drv_client_t * client_tmp;
  uint32_t rxq_num_temp;
  uint32_t txq_num_temp;
  struct pfe_hif_drv_client_rx_tx_count * client_queue;
  errno_t err;
  <unnamed type> _1;
  unsigned char _2;
  <unnamed type> _3;
  int _4;
  long unsigned int _5;
  unsigned char _6;
  struct pfe_hif_drv_t * _7;
  errno_t (*<T972>) (struct pfe_hif_drv_client_t *, void *, uint32_t, uint32_t) _9;
  void * _10;
  struct pfe_hif_drv_client_fifo_queue * _36;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_queue_16 = client_data_15(D)->client_queue;
  # DEBUG client_queue => client_queue_16
  # DEBUG BEGIN_STMT
  txq_num_temp_17 = client_queue_16->txq_num;
  # DEBUG txq_num_temp => txq_num_temp_17
  # DEBUG BEGIN_STMT
  rxq_num_temp_18 = client_queue_16->rxq_num;
  # DEBUG rxq_num_temp => rxq_num_temp_18
  # DEBUG BEGIN_STMT
  # DEBUG client_tmp => client_19(D)
  # DEBUG BEGIN_STMT
  _1 = client_data_15(D)->phy_if_id;
  if (_1 > 11)
    goto <bb 7>; [29.00%]
  else
    goto <bb 3>; [71.00%]

  <bb 3> [local count: 762356696]:
  # DEBUG BEGIN_STMT
  _2 = client_19(D)->active;
  if (_2 != 0)
    goto <bb 4>; [29.00%]
  else
    goto <bb 5>; [71.00%]

  <bb 4> [local count: 221083442]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Client already initialized\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1232, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG err => 121
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 541273254]:
  # DEBUG BEGIN_STMT
  rxq_num_temp_12 = MIN_EXPR <8, rxq_num_temp_18>;
  # DEBUG rxq_num_temp => rxq_num_temp_12
  # DEBUG BEGIN_STMT
  txq_num_temp_8 = MIN_EXPR <8, txq_num_temp_17>;
  # DEBUG txq_num_temp => txq_num_temp_8
  # DEBUG BEGIN_STMT
  autolibc_memset (client_19(D), 0, 1792);
  # DEBUG BEGIN_STMT
  _3 = client_data_15(D)->phy_if_id;
  _4 = (int) _3;
  _5 = 1 << _4;
  client_19(D)->id_mask = _5;
  # DEBUG BEGIN_STMT
  client_19(D)->active = 0;
  # DEBUG BEGIN_STMT
  _6 = client_data_15(D)->promisc;
  client_19(D)->promisc = _6;
  # DEBUG BEGIN_STMT
  _7 = client_data_15(D)->hif_drv;
  client_19(D)->hif_drv = _7;
  # DEBUG BEGIN_STMT
  client_19(D)->phy_if_id = _3;
  # DEBUG BEGIN_STMT
  client_19(D)->rx_qn = rxq_num_temp_12;
  # DEBUG BEGIN_STMT
  client_19(D)->tx_qn = txq_num_temp_8;
  # DEBUG BEGIN_STMT
  _9 = client_data_15(D)->handler;
  client_19(D)->event_handler = _9;
  # DEBUG BEGIN_STMT
  _10 = client_data_15(D)->priv;
  client_19(D)->priv = _10;
  # DEBUG BEGIN_STMT
  _36 = MEM[(struct pfe_hif_drv_client_fifo_queue * *)client_data_15(D) + 12B];
  # DEBUG D#6 => client_data_15(D)
  err_32 = pfe_hif_drv_client_create_rx_tx.isra.0 (client_19(D), _36);
  # DEBUG err => err_32
  # DEBUG BEGIN_STMT
  if (err_32 != 0)
    goto <bb 6>; [29.00%]
  else
    goto <bb 7>; [71.00%]

  <bb 6> [local count: 378052685]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_client_unregister (client_19(D));
  # DEBUG BEGIN_STMT
  # DEBUG client_tmp => 0B

  <bb 7> [local count: 1073741824]:
  # client_tmp_11 = PHI <0B(2), client_19(D)(5), 0B(6)>
  # DEBUG client_tmp => client_tmp_11
  # DEBUG BEGIN_STMT
  return client_tmp_11;

}



;; Function pfe_hif_drv_ihc_client_register (pfe_hif_drv_ihc_client_register, funcdef_no=43, decl_uid=9391, cgraph_uid=44, symbol_order=48)

Modification phase of node pfe_hif_drv_ihc_client_register/48
pfe_hif_drv_ihc_client_register (struct pfe_hif_drv_t * hif_drv, errno_t (*pfe_hif_drv_client_event_handler) (struct pfe_hif_drv_client_t *, void *, uint32_t, uint32_t) handler, void * priv)
{
  struct pfe_hif_drv_client_data client_data;
  struct pfe_hif_drv_client_fifo_queue client_fifo_queue;
  struct pfe_hif_drv_client_rx_tx_count client_queue;
  struct pfe_hif_drv_client_t * client;
  volatile struct fifo_t * _1;
  volatile struct fifo_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_data.hif_drv = hif_drv_6(D);
  client_data.phy_if_id = 10;
  client_data.client_queue = &client_queue;
  client_data.client_fifo_queue = &client_fifo_queue;
  client_data.promisc = 1;
  client_data.handler = handler_12(D);
  client_data.priv = priv_14(D);
  # DEBUG BEGIN_STMT
  if (handler_12(D) == 0B)
    goto <bb 3>; [100.00%]
  else
    goto <bb 4>; [0.00%]

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Event handler is mandatory\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1009, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG client => 0B
  goto <bb 9>; [100.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = fifo_create (8, &ihc_client_fifos.rx_fifo, &ihc_client_fifos.rx_fifo_data);
  client_fifo_queue.rxq_fifo = _1;
  # DEBUG BEGIN_STMT
  if (_1 == 0B)
    goto <bb 5>; [0.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 5> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t create RX queues\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1022, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG client => 0B
  goto <bb 9>; [0.00%]

  <bb 6> [count: 0]:
  # DEBUG BEGIN_STMT
  _2 = fifo_create (8, &ihc_client_fifos.tx_conf_fifo, &ihc_client_fifos.tx_conf_fifo_data);
  client_fifo_queue.txq_fifo = _2;
  # DEBUG BEGIN_STMT
  if (_2 == 0B)
    goto <bb 7>; [0.00%]
  else
    goto <bb 8>; [0.00%]

  <bb 7> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t create TX queues\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1030, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG client => 0B
  goto <bb 9>; [0.00%]

  <bb 8> [count: 0]:
  # DEBUG BEGIN_STMT
  client_20 = &hif_drv_6(D)->clients[10];
  # DEBUG client => client_20
  # DEBUG BEGIN_STMT
  client_queue.txq_num = 1;
  # DEBUG BEGIN_STMT
  client_queue.rxq_num = 1;
  # DEBUG BEGIN_STMT
  client_24 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  # DEBUG client => client_24
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  # client_3 = PHI <0B(3), 0B(5), 0B(7), client_24(8)>
  # DEBUG client => client_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_queue ={v} {CLOBBER};
  client_fifo_queue ={v} {CLOBBER};
  client_data ={v} {CLOBBER};
  return client_3;

}



;; Function pfe_hif_drv_aux_client_register (pfe_hif_drv_aux_client_register, funcdef_no=44, decl_uid=9397, cgraph_uid=45, symbol_order=49)

Modification phase of node pfe_hif_drv_aux_client_register/49
pfe_hif_drv_aux_client_register (struct pfe_hif_drv_t * hif_drv, struct pfe_hif_drv_client_rx_tx_count * client_queue, struct pfe_hif_drv_client_fifo_queue * client_fifo_queue, errno_t (*pfe_hif_drv_client_event_handler) (struct pfe_hif_drv_client_t *, void *, uint32_t, uint32_t) handler, void * priv)
{
  struct pfe_hif_drv_client_data client_data;
  struct pfe_hif_drv_client_t * client;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_data.hif_drv = hif_drv_4(D);
  client_data.phy_if_id = 11;
  client_data.client_queue = client_queue_7(D);
  client_data.client_fifo_queue = client_fifo_queue_9(D);
  client_data.promisc = 1;
  client_data.handler = handler_12(D);
  client_data.priv = priv_14(D);
  # DEBUG BEGIN_STMT
  if (handler_12(D) == 0B)
    goto <bb 3>; [14.90%]
  else
    goto <bb 4>; [85.10%]

  <bb 3> [local count: 159987532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Event handler is mandatory\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1081, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG client => 0B
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 913754293]:
  # DEBUG BEGIN_STMT
  client_16 = &hif_drv_4(D)->clients[11];
  # DEBUG client => client_16
  # DEBUG BEGIN_STMT
  client_18 = pfe_hif_drv_client_register_ll (client_16, &client_data);
  # DEBUG client => client_18
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  # client_1 = PHI <0B(3), client_18(4)>
  # DEBUG client => client_1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_data ={v} {CLOBBER};
  return client_1;

}



;; Function pfe_hif_drv_client_register (pfe_hif_drv_client_register, funcdef_no=45, decl_uid=9405, cgraph_uid=46, symbol_order=50)

Modification phase of node pfe_hif_drv_client_register/50
pfe_hif_drv_client_register (struct pfe_hif_drv_t * hif_drv, pfe_ct_phy_if_id_t phy_if_id, struct pfe_hif_drv_client_rx_tx_count * client_queue, struct pfe_hif_drv_client_fifo_queue * client_fifo_queue, bool_t promisc, errno_t (*pfe_hif_drv_client_event_handler) (struct pfe_hif_drv_client_t *, void *, uint32_t, uint32_t) handler, void * priv)
{
  struct pfe_hif_drv_client_data client_data;
  struct pfe_hif_drv_client_t * client;
  int _1;
  int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_data.hif_drv = hif_drv_6(D);
  client_data.phy_if_id = phy_if_id_8(D);
  client_data.client_queue = client_queue_10(D);
  client_data.client_fifo_queue = client_fifo_queue_12(D);
  client_data.promisc = promisc_14(D);
  client_data.handler = handler_16(D);
  client_data.priv = priv_18(D);
  # DEBUG BEGIN_STMT
  if (phy_if_id_8(D) > 11)
    goto <bb 3>; [16.75%]
  else
    goto <bb 4>; [83.25%]

  <bb 3> [local count: 179851756]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) phy_if_id_8(D);
  pfe_hm_report (1, 2, 1, "[%s:%d] Incompatible interface ID requested: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1140, _1, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG client => 0B
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 893890069]:
  # DEBUG BEGIN_STMT
  if (handler_16(D) == 0B)
    goto <bb 5>; [14.90%]
  else
    goto <bb 6>; [85.10%]

  <bb 5> [local count: 133189620]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Event handler is mandatory\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 1145, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG client => 0B
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 760700449]:
  # DEBUG BEGIN_STMT
  _2 = (int) phy_if_id_8(D);
  client_20 = &hif_drv_6(D)->clients[_2];
  # DEBUG client => client_20
  # DEBUG BEGIN_STMT
  client_22 = pfe_hif_drv_client_register_ll (client_20, &client_data);
  # DEBUG client => client_22
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  # client_3 = PHI <0B(3), 0B(5), client_22(6)>
  # DEBUG client => client_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_data ={v} {CLOBBER};
  return client_3;

}



;; Function pfe_hif_drv_exit (pfe_hif_drv_exit, funcdef_no=73, decl_uid=9377, cgraph_uid=74, symbol_order=78)

Modification phase of node pfe_hif_drv_exit/78
pfe_hif_drv_exit (struct pfe_hif_drv_t * hif_drv)
{
  uint32_t ii;
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 165141492]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} hif_drv_7(D)->initialized;
  if (_1 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 82570746]:
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 991171078]:
  # DEBUG BEGIN_STMT
  _2 = hif_drv_7(D)->clients[ii_3].active;
  if (_2 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 327086456]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] A client is still registered within HIF\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif_drv.c", 2496, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 5> [local count: 991171078]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ii_11 = ii_3 + 1;
  # DEBUG ii => ii_11

  <bb 6> [local count: 1073741824]:
  # ii_3 = PHI <ii_11(5), 0(9)>
  # DEBUG ii => ii_3
  # DEBUG BEGIN_STMT
  if (ii_3 != 12)
    goto <bb 3>; [92.31%]
  else
    goto <bb 7>; [7.69%]

  <bb 7> [local count: 82570744]:
  pfe_hif_drv_exit.part.0 (hif_drv_7(D));

  <bb 8> [local count: 165141492]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_drv_destroy (pfe_hif_drv_destroy, funcdef_no=74, decl_uid=9369, cgraph_uid=75, symbol_order=79)

Modification phase of node pfe_hif_drv_destroy/79
pfe_hif_drv_destroy (struct pfe_hif_drv_t * hif_drv)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (hif_drv_2(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_exit (hif_drv_2(D));
  # DEBUG BEGIN_STMT
  hif_drv_2(D)->channel = 0B;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function pfe_hif_drv_get_chnl (pfe_hif_drv_get_chnl, funcdef_no=75, decl_uid=9379, cgraph_uid=76, symbol_order=80)

Modification phase of node pfe_hif_drv_get_chnl/80
pfe_hif_drv_get_chnl (const struct pfe_hif_drv_t * hif_drv)
{
  struct pfe_hif_chnl_t * entry;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  entry_3 = hif_drv_2(D)->channel;
  # DEBUG entry => entry_3
  # DEBUG BEGIN_STMT
  return entry_3;

}



;; Function pfe_hif_drv_show_ring_status (pfe_hif_drv_show_ring_status, funcdef_no=78, decl_uid=9387, cgraph_uid=79, symbol_order=83)

Modification phase of node pfe_hif_drv_show_ring_status/83
pfe_hif_drv_show_ring_status (struct pfe_hif_drv_t * hif_drv, bool_t rx, bool_t tx)
{
  struct pfe_hif_drv_client_t * cl;
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  cl_6 = &hif_drv_5(D)->clients[0];
  # DEBUG cl => cl_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct pfe_hif_drv_client_t *)hif_drv_5(D) + 256B].active;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870911]:
  if (rx_8(D) == 1)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 108662672]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_show_rx_ring_status (cl_6);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct pfe_hif_drv_client_t *)hif_drv_5(D) + 256B].active;
  if (_2 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 536870913]:
  if (tx_10(D) == 1)
    goto <bb 7>; [20.24%]
  else
    goto <bb 8>; [79.76%]

  <bb 7> [local count: 108662673]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_show_tx_ring_status (cl_6);

  <bb 8> [local count: 1073741824]:
  return;

}


