
IPA constant propagation start:
Determining dynamic type for call: ret_6 = pfe_platform_create_class_object (platform_3(D), class_cfg);
  Starting walk at: ret_6 = pfe_platform_create_class_object (platform_3(D), class_cfg);
  instance pointer: platform_3(D)  Outer instance pointer: platform_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_feature_mgr_is_available ("drv_run_on_g3");
Determining dynamic type for call: ret_9 = pfe_platform_create_failures (platform_1(D), _8, 606208);
  Starting walk at: ret_9 = pfe_platform_create_failures (platform_1(D), _8, 606208);
  instance pointer: platform_1(D)  Outer instance pointer: platform_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bFeatureOnG3_6 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  Function call may change dynamic type:_5 = pfe_wdt_create (_4, 606208);
  Function call may change dynamic type:_3 = pfe_parity_create (_2, 606208);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create PFE_ERRORS:Parity instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 1975, "");
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create PFE_ERRORS:Watchdog instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 1990, "");
Determining dynamic type for call: pfe_platform_irq_unmask_parity_wdt (platform_1(D));
  Starting walk at: pfe_platform_irq_unmask_parity_wdt (platform_1(D));
  instance pointer: platform_1(D)  Outer instance pointer: platform_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bFeatureOnG3_6 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  Function call may change dynamic type:_5 = pfe_wdt_create (_4, 606208);
  Function call may change dynamic type:_3 = pfe_parity_create (_2, 606208);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create PFE_ERRORS:Parity instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 1975, "");
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create PFE_ERRORS:Watchdog instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 1990, "");
  Function call may change dynamic type:ret_9 = pfe_platform_create_failures (platform_1(D), _8, 606208);
Determining dynamic type for call: pfe_platform_irq_unmask_fails_and_errors (platform_1(D));
  Starting walk at: pfe_platform_irq_unmask_fails_and_errors (platform_1(D));
  instance pointer: platform_1(D)  Outer instance pointer: platform_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_11 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  Function call may change dynamic type:pfe_platform_irq_unmask_parity_wdt (platform_1(D));
  Function call may change dynamic type:bFeatureOnG3_6 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  Function call may change dynamic type:_5 = pfe_wdt_create (_4, 606208);
  Function call may change dynamic type:_3 = pfe_parity_create (_2, 606208);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create PFE_ERRORS:Parity instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 1975, "");
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create PFE_ERRORS:Watchdog instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 1990, "");
  Function call may change dynamic type:ret_9 = pfe_platform_create_failures (platform_1(D), _8, 606208);
Determining dynamic type for call: pfe_platform_destroy_class (&pfe);
  Starting walk at: pfe_platform_destroy_class (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_mirror_deinit ();
Determining dynamic type for call: pfe_platform_destroy_util (&pfe);
  Starting walk at: pfe_platform_destroy_util (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_class (&pfe);
  Function call may change dynamic type:pfe_mirror_deinit ();
Determining dynamic type for call: pfe_platform_destroy_tmu (&pfe);
  Starting walk at: pfe_platform_destroy_tmu (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_util (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_class (&pfe);
  Function call may change dynamic type:pfe_mirror_deinit ();
Determining dynamic type for call: pfe_platform_destroy_emac (&pfe);
  Starting walk at: pfe_platform_destroy_emac (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_tmu (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_util (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_class (&pfe);
  Function call may change dynamic type:pfe_mirror_deinit ();
Determining dynamic type for call: pfe_platform_destroy_pfe_errors (&pfe);
  Starting walk at: pfe_platform_destroy_pfe_errors (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_emac (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_tmu (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_util (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_class (&pfe);
  Function call may change dynamic type:pfe_mirror_deinit ();
Determining dynamic type for call: pfe_platform_destroy_ifaces (&pfe);
  Starting walk at: pfe_platform_destroy_ifaces (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fci_fini ();
Determining dynamic type for call: pfe_platform_destroy_hif (&pfe);
  Starting walk at: pfe_platform_destroy_hif (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_ifaces (&pfe);
  Function call may change dynamic type:fci_fini ();
Determining dynamic type for call: pfe_platform_destroy_gpi (&pfe);
  Starting walk at: pfe_platform_destroy_gpi (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_hif (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_ifaces (&pfe);
  Function call may change dynamic type:fci_fini ();
Determining dynamic type for call: pfe_platform_destroy_etgpi (&pfe);
  Starting walk at: pfe_platform_destroy_etgpi (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_gpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_hif (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_ifaces (&pfe);
  Function call may change dynamic type:fci_fini ();
Determining dynamic type for call: pfe_platform_destroy_hgpi (&pfe);
  Starting walk at: pfe_platform_destroy_hgpi (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_etgpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_gpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_hif (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_ifaces (&pfe);
  Function call may change dynamic type:fci_fini ();
Determining dynamic type for call: pfe_platform_destroy_bmu (&pfe);
  Starting walk at: pfe_platform_destroy_bmu (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_hgpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_etgpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_gpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_hif (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_ifaces (&pfe);
  Function call may change dynamic type:fci_fini ();
Determining dynamic type for call: pfe_platform_destroy_rtable (&pfe);
  Starting walk at: pfe_platform_destroy_rtable (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_bmu (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_hgpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_etgpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_gpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_hif (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_ifaces (&pfe);
  Function call may change dynamic type:fci_fini ();
Determining dynamic type for call: pfe_platform_destroy_l2_bridge (&pfe);
  Starting walk at: pfe_platform_destroy_l2_bridge (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_platform_destroy_rtable (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_bmu (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_hgpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_etgpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_gpi (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_hif (&pfe);
  Function call may change dynamic type:pfe_platform_destroy_ifaces (&pfe);
  Function call may change dynamic type:fci_fini ();
Determining dynamic type for call: ret_6 = pfe_platform_init_hm_fw_features (config_4(D));
  Starting walk at: ret_6 = pfe_platform_init_hm_fw_features (config_4(D));
  instance pointer: config_4(D)  Outer instance pointer: config_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_8 = pfe_platform_init_mirror_spd_acc_features (config_4(D));
  Starting walk at: ret_8 = pfe_platform_init_mirror_spd_acc_features (config_4(D));
  instance pointer: config_4(D)  Outer instance pointer: config_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_6 = pfe_platform_init_hm_fw_features (config_4(D));
Determining dynamic type for call: ret_24 = pfe_platform_init_etgpi_l2br_rtable_hifs (config_22(D));
  Starting walk at: ret_24 = pfe_platform_init_etgpi_l2br_rtable_hifs (config_22(D));
  instance pointer: config_22(D)  Outer instance pointer: config_22(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_platform_enable_ts (&pfe);
  Starting walk at: pfe_platform_enable_ts (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_tmu_enable (_11);
  Function call may change dynamic type:pfe_gpi_enable (_10);
  Function call may change dynamic type:pfe_gpi_enable (_9);
  Function call may change dynamic type:pfe_gpi_enable (_8);
  Function call may change dynamic type:pfe_gpi_enable (_7);
  Function call may change dynamic type:pfe_gpi_enable (_6);
  Function call may change dynamic type:pfe_gpi_enable (_5);
  Function call may change dynamic type:pfe_gpi_enable (_4);
  Function call may change dynamic type:pfe_bmu_enable (_3);
  Function call may change dynamic type:pfe_bmu_enable (_2);
  Function call may change dynamic type:ret_27 = pfe_platform_init_tmu_mirror_queue_ifaces_fci ();
  Function call may change dynamic type:pfe_class_enable (_1);
  Function call may change dynamic type:ret_24 = pfe_platform_init_etgpi_l2br_rtable_hifs (config_22(D));
  Function call may change dynamic type:pfe_util_enable (_13);
Determining dynamic type for call: ret_26 = pfe_platform_create_fci (&pfe);
  Starting walk at: ret_26 = pfe_platform_create_fci (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_23 = pfe_platform_create_ifaces ();
  Function call may change dynamic type:ret_21 = pfe_mirror_init (_3);
  Function call may change dynamic type:ret_16 = pfe_feature_mgr_get_val ("err051211_workaround", &flg);
  Function call may change dynamic type:_2 = pfe_feature_mgr_is_available ("err051211_workaround");
  Function call may change dynamic type:ret_10 = pfe_tmu_queue_reset_tail_drop_policy (_1);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Feature err051211_workaround status unknown\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2946, "");
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Feature err051211_workaround is not supported in firmware\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2959, "");
Determining dynamic type for call: ret_5 = pfe_platform_create_etgpi (&pfe);
  Starting walk at: ret_5 = pfe_platform_create_etgpi (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  Starting walk at: ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_5 = pfe_platform_create_etgpi (&pfe);
Determining dynamic type for call: ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  Starting walk at: ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  instance pointer: config_6(D)  Outer instance pointer: config_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_5 = pfe_platform_create_etgpi (&pfe);
Determining dynamic type for call: ret_10 = pfe_platform_create_rtable (&pfe, config_6(D));
  Starting walk at: ret_10 = pfe_platform_create_rtable (&pfe, config_6(D));
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  Function call may change dynamic type:ret_5 = pfe_platform_create_etgpi (&pfe);
Determining dynamic type for call: ret_10 = pfe_platform_create_rtable (&pfe, config_6(D));
  Starting walk at: ret_10 = pfe_platform_create_rtable (&pfe, config_6(D));
  instance pointer: config_6(D)  Outer instance pointer: config_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  Function call may change dynamic type:ret_5 = pfe_platform_create_etgpi (&pfe);
Determining dynamic type for call: ret_12 = pfe_platform_create_hif (&pfe, config_6(D));
  Starting walk at: ret_12 = pfe_platform_create_hif (&pfe, config_6(D));
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_platform_create_rtable (&pfe, config_6(D));
  Function call may change dynamic type:ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  Function call may change dynamic type:ret_5 = pfe_platform_create_etgpi (&pfe);
Determining dynamic type for call: ret_12 = pfe_platform_create_hif (&pfe, config_6(D));
  Starting walk at: ret_12 = pfe_platform_create_hif (&pfe, config_6(D));
  instance pointer: config_6(D)  Outer instance pointer: config_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_platform_create_rtable (&pfe, config_6(D));
  Function call may change dynamic type:ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  Function call may change dynamic type:ret_5 = pfe_platform_create_etgpi (&pfe);
Determining dynamic type for call: ret_14 = pfe_platform_create_hif_nocpy (&pfe);
  Starting walk at: ret_14 = pfe_platform_create_hif_nocpy (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_12 = pfe_platform_create_hif (&pfe, config_6(D));
  Function call may change dynamic type:ret_10 = pfe_platform_create_rtable (&pfe, config_6(D));
  Function call may change dynamic type:ret_8 = pfe_platform_create_l2_bridge (&pfe, config_6(D));
  Function call may change dynamic type:ret_5 = pfe_platform_create_etgpi (&pfe);
Determining dynamic type for call: ret_53 = pfe_platform_create_err_bmu_class_tmu_emac_util (config_28(D));
  Starting walk at: ret_53 = pfe_platform_create_err_bmu_class_tmu_emac_util (config_28(D));
  instance pointer: config_28(D)  Outer instance pointer: config_28(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hm_init ();
  Function call may change dynamic type:_10 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  Function call may change dynamic type:ret_34 = pfe_feature_mgr_init (_5);
  Function call may change dynamic type:_5 = oal_mm_dev_map (_3, _4);
  Function call may change dynamic type:autolibc_memset (&pfe, 0, 212);
Determining dynamic type for call: ret_55 = pfe_platform_create_gpis_add_modules (config_28(D));
  Starting walk at: ret_55 = pfe_platform_create_gpis_add_modules (config_28(D));
  instance pointer: config_28(D)  Outer instance pointer: config_28(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_53 = pfe_platform_create_err_bmu_class_tmu_emac_util (config_28(D));
  Function call may change dynamic type:pfe_hm_init ();
  Function call may change dynamic type:_10 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  Function call may change dynamic type:ret_34 = pfe_feature_mgr_init (_5);
  Function call may change dynamic type:_5 = oal_mm_dev_map (_3, _4);
  Function call may change dynamic type:autolibc_memset (&pfe, 0, 212);
Determining dynamic type for call: ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
  Starting walk at: ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  Starting walk at: ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
Determining dynamic type for call: ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  Starting walk at: ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  instance pointer: config_7(D)  Outer instance pointer: config_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
Determining dynamic type for call: ret_13 = pfe_platform_create_class.isra.0 (&pfe, _24);
  Starting walk at: ret_13 = pfe_platform_create_class.isra.0 (&pfe, _24);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  Function call may change dynamic type:ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
Determining dynamic type for call: ret_15 = pfe_platform_create_tmu (&pfe);
  Starting walk at: ret_15 = pfe_platform_create_tmu (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_13 = pfe_platform_create_class.isra.0 (&pfe, _24);
  Function call may change dynamic type:ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  Function call may change dynamic type:ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
Determining dynamic type for call: ret_17 = pfe_platform_create_emac (&pfe, config_7(D));
  Starting walk at: ret_17 = pfe_platform_create_emac (&pfe, config_7(D));
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_15 = pfe_platform_create_tmu (&pfe);
  Function call may change dynamic type:ret_13 = pfe_platform_create_class.isra.0 (&pfe, _24);
  Function call may change dynamic type:ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  Function call may change dynamic type:ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
Determining dynamic type for call: ret_17 = pfe_platform_create_emac (&pfe, config_7(D));
  Starting walk at: ret_17 = pfe_platform_create_emac (&pfe, config_7(D));
  instance pointer: config_7(D)  Outer instance pointer: config_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_15 = pfe_platform_create_tmu (&pfe);
  Function call may change dynamic type:ret_13 = pfe_platform_create_class.isra.0 (&pfe, _24);
  Function call may change dynamic type:ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  Function call may change dynamic type:ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
Determining dynamic type for call: pfe_platform_default_init_util (&pfe);
  Starting walk at: pfe_platform_default_init_util (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_17 = pfe_platform_create_emac (&pfe, config_7(D));
  Function call may change dynamic type:ret_15 = pfe_platform_create_tmu (&pfe);
  Function call may change dynamic type:ret_13 = pfe_platform_create_class.isra.0 (&pfe, _24);
  Function call may change dynamic type:ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  Function call may change dynamic type:ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
Determining dynamic type for call: ret_22 = pfe_platform_create_util (&pfe);
  Starting walk at: ret_22 = pfe_platform_create_util (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_17 = pfe_platform_create_emac (&pfe, config_7(D));
  Function call may change dynamic type:ret_15 = pfe_platform_create_tmu (&pfe);
  Function call may change dynamic type:ret_13 = pfe_platform_create_class.isra.0 (&pfe, _24);
  Function call may change dynamic type:ret_11 = pfe_platform_create_bmu (&pfe, config_7(D));
  Function call may change dynamic type:ret_9 = pfe_platform_create_pfe_errors.isra.0 (&pfe);
Determining dynamic type for call: _1 = pfe_platform_soft_reset (&pfe);
  Starting walk at: _1 = pfe_platform_soft_reset (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_cfg_stop_all_chnl_dma ();
Determining dynamic type for call: ret_17 = pfe_platform_create_gpi.isra.0 (&pfe, _23);
  Starting walk at: ret_17 = pfe_platform_create_gpi.isra.0 (&pfe, _23);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_14 = pfe_feature_mgr_add_modules (_2, _3, _4);
  Function call may change dynamic type:_1 = pfe_platform_soft_reset (&pfe);
  Function call may change dynamic type:pfe_hif_cfg_stop_all_chnl_dma ();
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Platform reset failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2665, "");
Determining dynamic type for call: ret_17 = pfe_platform_create_gpi.isra.0 (&pfe, _23);
  Starting walk at: ret_17 = pfe_platform_create_gpi.isra.0 (&pfe, _23);
  instance pointer: _23  Outer instance pointer: config_15(D) offset: 736 (bits) vtbl reference: 
  Function call may change dynamic type:ret_14 = pfe_feature_mgr_add_modules (_2, _3, _4);
  Function call may change dynamic type:_1 = pfe_platform_soft_reset (&pfe);
  Function call may change dynamic type:pfe_hif_cfg_stop_all_chnl_dma ();
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Platform reset failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2665, "");
Determining dynamic type for call: ret_19 = pfe_platform_create_hgpi (&pfe);
  Starting walk at: ret_19 = pfe_platform_create_hgpi (&pfe);
  instance pointer: &pfe  Outer instance pointer: pfe offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_17 = pfe_platform_create_gpi.isra.0 (&pfe, _23);
  Function call may change dynamic type:ret_14 = pfe_feature_mgr_add_modules (_2, _3, _4);
  Function call may change dynamic type:_1 = pfe_platform_soft_reset (&pfe);
  Function call may change dynamic type:pfe_hif_cfg_stop_all_chnl_dma ();
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Platform reset failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2665, "");
Determining dynamic type for call: pfe_platform_destroy_pfe_log_ifs (platform_6(D));
  Starting walk at: pfe_platform_destroy_pfe_log_ifs (platform_6(D));
  instance pointer: platform_6(D)  Outer instance pointer: platform_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_platform_destroy_pfe_phy_ifs (platform_6(D));
  Starting walk at: pfe_platform_destroy_pfe_phy_ifs (platform_6(D));
  instance pointer: platform_6(D)  Outer instance pointer: platform_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_log_ifs_deinit ();
  Function call may change dynamic type:pfe_platform_destroy_pfe_log_ifs (platform_6(D));
Determining dynamic type for call: ret_121 = pfe_platform_prepare_phy_if (phy_if_119, _23, session_id.26_24);
  Starting walk at: ret_121 = pfe_platform_prepare_phy_if (phy_if_119, _23, session_id.26_24);
  instance pointer: phy_if_119  Outer instance pointer: phy_if_119 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:phy_if_119 = pfe_phy_if_create (_19, _20, _21);
  Function call may change dynamic type:pfe_if_db_get_first (_13, session_id.24_14, 1, _17, &entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] DB lock failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2361, "");
  Function call may change dynamic type:_12 = pfe_if_db_lock (&session_id);
  Function call may change dynamic type:channel_hifncpy_53 = pfe_hif_nocpy_get_channel (_5, 1000);
  Function call may change dynamic type:channel_hif3_51 = pfe_hif_get_channel (_4, 8);
  Function call may change dynamic type:channel_hif2_49 = pfe_hif_get_channel (_3, 4);
  Function call may change dynamic type:channel_hif1_47 = pfe_hif_get_channel (_2, 2);
  Function call may change dynamic type:channel_hif0_45 = pfe_hif_get_channel (_1, 1);
  Function call may change dynamic type:pfe_if_db_get_first (_13, session_id.24_14, 1, _17, &entry);
  Function call may change dynamic type:ret_121 = pfe_platform_prepare_phy_if (phy_if_119, _23, session_id.26_24);
  Function call may change dynamic type:phy_if_119 = pfe_phy_if_create (_19, _20, _21);
Determining dynamic type for call: ret_121 = pfe_platform_prepare_phy_if (phy_if_119, _23, session_id.26_24);
  Starting walk at: ret_121 = pfe_platform_prepare_phy_if (phy_if_119, _23, session_id.26_24);
  instance pointer: _23  Outer instance pointer: &phy_ifs[ii_31] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:phy_if_119 = pfe_phy_if_create (_19, _20, _21);
  Function call may change dynamic type:pfe_if_db_get_first (_13, session_id.24_14, 1, _17, &entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] DB lock failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2361, "");
  Function call may change dynamic type:_12 = pfe_if_db_lock (&session_id);
  Function call may change dynamic type:channel_hifncpy_53 = pfe_hif_nocpy_get_channel (_5, 1000);
  Function call may change dynamic type:channel_hif3_51 = pfe_hif_get_channel (_4, 8);
  Function call may change dynamic type:channel_hif2_49 = pfe_hif_get_channel (_3, 4);
  Function call may change dynamic type:channel_hif1_47 = pfe_hif_get_channel (_2, 2);
  Function call may change dynamic type:channel_hif0_45 = pfe_hif_get_channel (_1, 1);
  Function call may change dynamic type:pfe_if_db_get_first (_13, session_id.24_14, 1, _17, &entry);
  Function call may change dynamic type:ret_121 = pfe_platform_prepare_phy_if (phy_if_119, _23, session_id.26_24);
  Function call may change dynamic type:phy_if_119 = pfe_phy_if_create (_19, _20, _21);
Determining dynamic type for call: ret_18 = pfe_platform_prepare_phy_if_hif (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  Starting walk at: ret_18 = pfe_platform_prepare_phy_if_hif (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  instance pointer: phy_if_12(D)  Outer instance pointer: phy_if_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_phy_if_set_op_mode (phy_if_12(D), 0);
Determining dynamic type for call: ret_18 = pfe_platform_prepare_phy_if_hif (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  Starting walk at: ret_18 = pfe_platform_prepare_phy_if_hif (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  instance pointer: p_phy_ifs_15(D)  Outer instance pointer: p_phy_ifs_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_phy_if_set_op_mode (phy_if_12(D), 0);
Determining dynamic type for call: ret_23 = pfe_platform_prepare_phy_if_emac (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  Starting walk at: ret_23 = pfe_platform_prepare_phy_if_emac (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  instance pointer: phy_if_12(D)  Outer instance pointer: phy_if_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_phy_if_set_op_mode (phy_if_12(D), 0);
Determining dynamic type for call: ret_23 = pfe_platform_prepare_phy_if_emac (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  Starting walk at: ret_23 = pfe_platform_prepare_phy_if_emac (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  instance pointer: p_phy_ifs_15(D)  Outer instance pointer: p_phy_ifs_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_phy_if_set_op_mode (phy_if_12(D), 0);
Determining dynamic type for call: _5 = pfe_platform_register_phy_if (session_id_16(D), phy_if_12(D));
  Starting walk at: _5 = pfe_platform_register_phy_if (session_id_16(D), phy_if_12(D));
  instance pointer: phy_if_12(D)  Outer instance pointer: phy_if_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_23 = pfe_platform_prepare_phy_if_emac (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  Function call may change dynamic type:_1 = pfe_phy_if_set_op_mode (phy_if_12(D), 0);
  Function call may change dynamic type:ret_18 = pfe_platform_prepare_phy_if_hif (phy_if_12(D), p_phy_ifs_15(D), session_id_16(D));
  Function call may change dynamic type:_3 = pfe_phy_if_bind_util (phy_if_12(D));
Determining dynamic type for call: _9 = pfe_platform_create_default_log_if (phy_if_15(D), _8, session_id_18(D));
  Starting walk at: _9 = pfe_platform_create_default_log_if (phy_if_15(D), _8, session_id_18(D));
  instance pointer: phy_if_15(D)  Outer instance pointer: phy_if_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = pfe_emac_bind_gpi (_4, _5);
  Function call may change dynamic type:_2 = pfe_phy_if_bind_emac (phy_if_15(D), _1);
Determining dynamic type for call: _9 = pfe_platform_create_default_log_if (phy_if_15(D), _8, session_id_18(D));
  Starting walk at: _9 = pfe_platform_create_default_log_if (phy_if_15(D), _8, session_id_18(D));
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = pfe_emac_bind_gpi (_4, _5);
  Function call may change dynamic type:_2 = pfe_phy_if_bind_emac (phy_if_15(D), _1);
Determining dynamic type for call: _5 = pfe_platform_create_default_log_if (phy_if_11(D), _4, session_id_15(D));
  Starting walk at: _5 = pfe_platform_create_default_log_if (phy_if_11(D), _4, session_id_15(D));
  instance pointer: phy_if_11(D)  Outer instance pointer: phy_if_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_phy_if_bind_hif (phy_if_11(D), _1);
Determining dynamic type for call: _5 = pfe_platform_create_default_log_if (phy_if_11(D), _4, session_id_15(D));
  Starting walk at: _5 = pfe_platform_create_default_log_if (phy_if_11(D), _4, session_id_15(D));
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_phy_if_bind_hif (phy_if_11(D), _1);
Determining dynamic type for call: ret_45 = check_irq_vector.isra.0 (platform_24(D), _53);
  Starting walk at: ret_45 = check_irq_vector.isra.0 (platform_24(D), _53);
  instance pointer: platform_24(D)  Outer instance pointer: platform_24(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_12 = oal_irq_create (_11, 0, "PFE BMU IRQ");
  Function call may change dynamic type:_9 = pfe_bmu_create (_8, 573440, &bmu_cfg, 1);
  Function call may change dynamic type:_6 = oal_mm_virt_to_phys_contig (&pfe_bmu_buffers);
  Function call may change dynamic type:_2 = pfe_bmu_create (_1, 557056, &bmu_cfg, 0);
Determining dynamic type for call: ret_45 = check_irq_vector.isra.0 (platform_24(D), _53);
  Starting walk at: ret_45 = check_irq_vector.isra.0 (platform_24(D), _53);
  instance pointer: _53  Outer instance pointer: config_41(D) offset: 160 (bits) vtbl reference: 
  Function call may change dynamic type:_12 = oal_irq_create (_11, 0, "PFE BMU IRQ");
  Function call may change dynamic type:_9 = pfe_bmu_create (_8, 573440, &bmu_cfg, 1);
  Function call may change dynamic type:_6 = oal_mm_virt_to_phys_contig (&pfe_bmu_buffers);
  Function call may change dynamic type:_2 = pfe_bmu_create (_1, 557056, &bmu_cfg, 0);
Determining dynamic type for call: handled_2 = pfe_platform_bmu_isr.part.0 (arg_7(D));
  Starting walk at: handled_2 = pfe_platform_bmu_isr.part.0 (arg_7(D));
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_bmu_irq_mask (_1);
  Function call may change dynamic type:pfe_bmu_irq_mask (_3);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_platform_create_gpi.isra.0/251:
  Jump functions of caller  pfe_platform_create_class.isra.0/250:
    callsite  pfe_platform_create_class.isra.0/250 -> pfe_platform_create_class_object/52 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Unknown bits
         Unknown VR
  Jump functions of caller  pfe_platform_bmu_isr.part.0/249:
  Jump functions of caller  check_irq_vector.isra.0/248:
  Jump functions of caller  pfe_platform_create_pfe_errors.isra.0/247:
    callsite  pfe_platform_create_pfe_errors.isra.0/247 -> pfe_platform_irq_unmask_fails_and_errors/68 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_create_pfe_errors.isra.0/247 -> pfe_platform_irq_unmask_parity_wdt/67 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_create_pfe_errors.isra.0/247 -> pfe_platform_create_failures/69 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 606208
         value: 0x94000, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_util_get_fw_version/246:
  Jump functions of caller  pfe_class_get_fw_version/245:
  Jump functions of caller  pfe_wdt_destroy/244:
  Jump functions of caller  pfe_parity_destroy/243:
  Jump functions of caller  pfe_bus_err_destroy/242:
  Jump functions of caller  pfe_fw_fail_stop_destroy/241:
  Jump functions of caller  pfe_host_fail_stop_destroy/240:
  Jump functions of caller  pfe_fail_stop_destroy/239:
  Jump functions of caller  pfe_ecc_err_destroy/238:
  Jump functions of caller  pfe_emac_destroy/237:
  Jump functions of caller  pfe_tmu_destroy/236:
  Jump functions of caller  pfe_class_destroy/235:
  Jump functions of caller  pfe_mirror_deinit/234:
  Jump functions of caller  pfe_l2br_destroy/233:
  Jump functions of caller  pfe_rtable_destroy/232:
  Jump functions of caller  pfe_bmu_destroy/231:
  Jump functions of caller  pfe_gpi_destroy/230:
  Jump functions of caller  pfe_hif_destroy/229:
  Jump functions of caller  pfe_hif_irq_mask/228:
  Jump functions of caller  pfe_if_db_destroy/227:
  Jump functions of caller  pfe_if_db_get_next/226:
  Jump functions of caller  pfe_if_db_remove/225:
  Jump functions of caller  pfe_if_db_entry_get_log_if/224:
  Jump functions of caller  pfe_log_ifs_deinit/223:
  Jump functions of caller  fci_fini/222:
  Jump functions of caller  oal_mm_dev_unmap/221:
  Jump functions of caller  pfe_feature_mgr_fini/220:
  Jump functions of caller  pfe_hm_destroy/219:
  Jump functions of caller  oal_irq_destroy/218:
  Jump functions of caller  pfe_emac_enable_ts/217:
  Jump functions of caller  fci_init/216:
  Jump functions of caller  pfe_phy_if_bind_hif/215:
  Jump functions of caller  pfe_log_if_enable/214:
  Jump functions of caller  pfe_log_if_promisc_enable/213:
  Jump functions of caller  pfe_log_if_destroy/212:
  Jump functions of caller  pfe_if_db_add/211:
  Jump functions of caller  pfe_log_if_create/210:
  Jump functions of caller  pfe_emac_bind_gpi/209:
  Jump functions of caller  pfe_phy_if_bind_emac/208:
  Jump functions of caller  pfe_phy_if_get_name/207:
  Jump functions of caller  pfe_phy_if_bind_util/206:
  Jump functions of caller  pfe_phy_if_get_id/205:
  Jump functions of caller  pfe_phy_if_set_op_mode/204:
  Jump functions of caller  pfe_phy_if_destroy/203:
  Jump functions of caller  pfe_phy_if_create/202:
  Jump functions of caller  pfe_hif_nocpy_get_channel/201:
  Jump functions of caller  pfe_hif_get_channel/200:
  Jump functions of caller  pfe_log_ifs_init/199:
  Jump functions of caller  pfe_if_db_create/198:
  Jump functions of caller  pfe_mirror_init/197:
  Jump functions of caller  pfe_feature_mgr_get_val/195:
  Jump functions of caller  pfe_tmu_queue_reset_tail_drop_policy/194:
  Jump functions of caller  pfe_hif_nocpy_create/193:
  Jump functions of caller  pfe_hif_init_emac_timer_ownership/192:
  Jump functions of caller  pfe_hif_clear_master_up/191:
  Jump functions of caller  pfe_hif_irq_unmask/190:
  Jump functions of caller  pfe_hif_set_master_detect_cfg/189:
  Jump functions of caller  pfe_hif_create/188:
  Jump functions of caller  pfe_rtable_create/187:
  Jump functions of caller  pfe_rtable_get_entry_size/186:
  Jump functions of caller  pfe_l2br_create/185:
  Jump functions of caller  pfe_l2br_table_create/184:
  Jump functions of caller  pfe_emac_pps0_configure/183:
  Jump functions of caller  pfe_util_enable/182:
  Jump functions of caller  pfe_tmu_enable/181:
  Jump functions of caller  pfe_gpi_enable/180:
  Jump functions of caller  pfe_bmu_enable/179:
  Jump functions of caller  pfe_class_enable/178:
  Jump functions of caller  pfe_gpi_create/177:
  Jump functions of caller  pfe_feature_mgr_add_modules/176:
  Jump functions of caller  pfe_hif_cfg_stop_all_chnl_dma/175:
  Jump functions of caller  pfe_util_default_init/174:
  Jump functions of caller  pfe_util_load_firmware/173:
  Jump functions of caller  pfe_util_create/172:
  Jump functions of caller  pfe_emac_enable_broadcast/171:
  Jump functions of caller  pfe_emac_enable_rx_flow_control/170:
  Jump functions of caller  pfe_emac_set_max_frame_length/169:
  Jump functions of caller  pfe_emac_create/168:
  Jump functions of caller  pfe_tmu_create/167:
  Jump functions of caller  ELF_Close/166:
  Jump functions of caller  pfe_class_load_firmware/165:
  Jump functions of caller  ELF_Open/164:
  Jump functions of caller  pfe_class_create/163:
  Jump functions of caller  pfe_bmu_isr/162:
  Jump functions of caller  pfe_bmu_irq_mask/161:
  Jump functions of caller  pfe_bmu_irq_unmask/160:
  Jump functions of caller  oal_irq_add_handler/159:
  Jump functions of caller  oal_irq_create/158:
  Jump functions of caller  oal_mm_virt_to_phys_contig/157:
  Jump functions of caller  pfe_bmu_create/156:
  Jump functions of caller  pfe_ecc_err_irq_unmask/155:
  Jump functions of caller  pfe_fail_stop_irq_unmask/154:
  Jump functions of caller  pfe_host_fail_stop_irq_unmask/153:
  Jump functions of caller  pfe_fw_fail_stop_irq_unmask/152:
  Jump functions of caller  pfe_bus_err_irq_unmask/151:
  Jump functions of caller  pfe_wdt_irq_unmask/150:
  Jump functions of caller  pfe_parity_irq_unmask/149:
  Jump functions of caller  pfe_ecc_err_create/148:
  Jump functions of caller  pfe_fail_stop_create/147:
  Jump functions of caller  pfe_host_fail_stop_create/146:
  Jump functions of caller  pfe_fw_fail_stop_create/145:
  Jump functions of caller  pfe_bus_err_create/144:
  Jump functions of caller  pfe_wdt_create/143:
  Jump functions of caller  pfe_parity_create/142:
  Jump functions of caller  pfe_util_destroy/141:
  Jump functions of caller  pfe_hm_init/140:
  Jump functions of caller  pfe_feature_mgr_init/139:
  Jump functions of caller  oal_mm_dev_map/138:
  Jump functions of caller  autolibc_memset/137:
  Jump functions of caller  oal_time_usleep/136:
  Jump functions of caller  pfe_feature_mgr_is_available/135:
  Jump functions of caller  pfe_if_db_lock/134:
  Jump functions of caller  pfe_emac_mdio_unlock/133:
  Jump functions of caller  pfe_emac_mdio_write45/132:
  Jump functions of caller  pfe_emac_mdio_read45/131:
  Jump functions of caller  pfe_emac_mdio_write22/130:
  Jump functions of caller  pfe_emac_mdio_read22/129:
  Jump functions of caller  pfe_emac_mdio_lock/128:
  Jump functions of caller  fci_process_ipc_message/127:
  Jump functions of caller  pfe_emac_get_stat_value/126:
  Jump functions of caller  pfe_phy_if_get_stats/125:
  Jump functions of caller  pfe_phy_if_is_promisc/124:
  Jump functions of caller  pfe_phy_if_is_enabled/123:
  Jump functions of caller  pfe_phy_if_get_op_mode/122:
  Jump functions of caller  pfe_phy_if_get_block_state/121:
  Jump functions of caller  pfe_phy_if_set_block_state/120:
  Jump functions of caller  pfe_phy_if_flush_mac_addrs/119:
  Jump functions of caller  pfe_phy_if_del_mac_addr/118:
  Jump functions of caller  pfe_phy_if_add_mac_addr/117:
  Jump functions of caller  autolibc_memcpy/116:
  Jump functions of caller  pfe_phy_if_allmulti_disable/115:
  Jump functions of caller  pfe_phy_if_allmulti_enable/114:
  Jump functions of caller  pfe_phy_if_loadbalance_disable/113:
  Jump functions of caller  pfe_phy_if_loadbalance_enable/112:
  Jump functions of caller  pfe_phy_if_loopback_disable/111:
  Jump functions of caller  pfe_phy_if_loopback_enable/110:
  Jump functions of caller  pfe_phy_if_promisc_disable/109:
  Jump functions of caller  pfe_phy_if_promisc_enable/108:
  Jump functions of caller  pfe_phy_if_disable/107:
  Jump functions of caller  pfe_phy_if_enable/106:
  Jump functions of caller  pfe_if_db_unlock/105:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/104:
  Jump functions of caller  pfe_hm_report/103:
  Jump functions of caller  pfe_idex_set_rpc_ret_val/102:
  Jump functions of caller  pfe_if_db_lock_owned/101:
  Jump functions of caller  pfe_if_db_entry_get_phy_if/100:
  Jump functions of caller  pfe_if_db_get_first/99:
  Jump functions of caller  pfe_platform_get_fw_versions/98:
  Jump functions of caller  pfe_platform_get_instance/97:
  Jump functions of caller  pfe_platform_remove_sw_if/96:
  Jump functions of caller  pfe_platform_remove/95:
    callsite  pfe_platform_remove/95 -> pfe_platform_destroy_group2/94 : 
    callsite  pfe_platform_remove/95 -> pfe_platform_destroy_group1/93 : 
  Jump functions of caller  pfe_platform_destroy_group2/94:
    callsite  pfe_platform_destroy_group2/94 -> pfe_platform_destroy_pfe_errors/71 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group2/94 -> pfe_platform_destroy_emac/66 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group2/94 -> pfe_platform_destroy_tmu/60 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group2/94 -> pfe_platform_destroy_util/63 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group2/94 -> pfe_platform_destroy_class/54 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_platform_destroy_group1/93:
    callsite  pfe_platform_destroy_group1/93 -> pfe_platform_destroy_l2_bridge/56 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group1/93 -> pfe_platform_destroy_rtable/58 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group1/93 -> pfe_platform_destroy_bmu/45 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group1/93 -> pfe_platform_destroy_hgpi/51 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group1/93 -> pfe_platform_destroy_etgpi/49 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group1/93 -> pfe_platform_destroy_gpi/47 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group1/93 -> pfe_platform_destroy_hif/41 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_destroy_group1/93 -> pfe_platform_destroy_ifaces/84 : 
       param 0: CONST: &pfe
         Aggregate passed by reference:
           offset: 1632, cst: 0
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_platform_init/92:
    callsite  pfe_platform_init/92 -> pfe_platform_init_mirror_spd_acc_features/91 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_init/92 -> pfe_platform_init_hm_fw_features/88 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_platform_init_mirror_spd_acc_features/91:
    callsite  pfe_platform_init_mirror_spd_acc_features/91 -> pfe_platform_enable_ts/65 : 
       param 0: CONST: &pfe
         Aggregate passed by reference:
           offset: 0, cst: 1
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_init_mirror_spd_acc_features/91 -> pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 : 
    callsite  pfe_platform_init_mirror_spd_acc_features/91 -> pfe_platform_init_etgpi_l2br_rtable_hifs/89 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_platform_init_tmu_mirror_queue_ifaces_fci/90:
    callsite  pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 -> pfe_platform_create_fci/72 : 
       param 0: CONST: &pfe
         Aggregate passed by reference:
           offset: 224, cst: 0
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 -> pfe_platform_create_ifaces/81 : 
    callsite  pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 -> pfe_platform_remove/95 : 
  Jump functions of caller  pfe_platform_init_etgpi_l2br_rtable_hifs/89:
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_create_hif_nocpy/42 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_create_hif/40 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_create_rtable/57 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_create_l2_bridge/55 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_etgpi_l2br_rtable_hifs/89 -> pfe_platform_create_etgpi/48 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_platform_init_hm_fw_features/88:
    callsite  pfe_platform_init_hm_fw_features/88 -> pfe_platform_create_gpis_add_modules/86 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_init_hm_fw_features/88 -> pfe_platform_create_err_bmu_class_tmu_emac_util/87 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_init_hm_fw_features/88 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_init_hm_fw_features/88 -> pfe_platform_remove/95 : 
  Jump functions of caller  pfe_platform_create_err_bmu_class_tmu_emac_util/87:
    callsite  pfe_platform_create_err_bmu_class_tmu_emac_util/87 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_create_err_bmu_class_tmu_emac_util/87 -> pfe_platform_default_init_util/61 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_create_err_bmu_class_tmu_emac_util/87 -> pfe_platform_create_util/62 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_create_err_bmu_class_tmu_emac_util/87 -> pfe_platform_create_emac/64 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_create_err_bmu_class_tmu_emac_util/87 -> pfe_platform_create_tmu/59 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_create_err_bmu_class_tmu_emac_util/87 -> pfe_platform_create_class.isra.0/250 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_platform_create_err_bmu_class_tmu_emac_util/87 -> pfe_platform_create_bmu/44 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_create_err_bmu_class_tmu_emac_util/87 -> pfe_platform_create_pfe_errors.isra.0/247 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_platform_create_gpis_add_modules/86:
    callsite  pfe_platform_create_gpis_add_modules/86 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_create_gpis_add_modules/86 -> pfe_platform_create_hgpi/50 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_platform_create_gpis_add_modules/86 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_create_gpis_add_modules/86 -> pfe_platform_create_gpi.isra.0/251 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_platform_create_gpis_add_modules/86 -> pfe_platform_remove/95 : 
    callsite  pfe_platform_create_gpis_add_modules/86 -> pfe_platform_soft_reset/85 : 
       param 0: CONST: &pfe
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_platform_soft_reset/85:
  Jump functions of caller  pfe_platform_destroy_ifaces/84:
    callsite  pfe_platform_destroy_ifaces/84 -> pfe_platform_destroy_pfe_phy_ifs/83 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_destroy_ifaces/84 -> pfe_platform_destroy_pfe_log_ifs/82 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_platform_destroy_pfe_phy_ifs/83:
  Jump functions of caller  pfe_platform_destroy_pfe_log_ifs/82:
  Jump functions of caller  pfe_platform_create_ifaces/81:
    callsite  pfe_platform_create_ifaces/81 -> pfe_platform_bind_ifaces/80 : 
  Jump functions of caller  pfe_platform_bind_ifaces/80:
    callsite  pfe_platform_bind_ifaces/80 -> pfe_platform_prepare_phy_if/79 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_platform_prepare_phy_if/79:
    callsite  pfe_platform_prepare_phy_if/79 -> pfe_platform_register_phy_if/74 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_prepare_phy_if/79 -> pfe_platform_prepare_phy_if_hif/77 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_platform_prepare_phy_if/79 -> pfe_platform_prepare_phy_if_emac/78 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_platform_prepare_phy_if_emac/78:
    callsite  pfe_platform_prepare_phy_if_emac/78 -> pfe_platform_create_default_log_if/76 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_platform_prepare_phy_if_hif/77:
    callsite  pfe_platform_prepare_phy_if_hif/77 -> pfe_platform_create_default_log_if/76 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_platform_create_default_log_if/76:
  Jump functions of caller  pfe_platform_get_phy_if_by_id/75:
  Jump functions of caller  pfe_platform_register_phy_if/74:
  Jump functions of caller  pfe_platform_create_fci/72:
  Jump functions of caller  pfe_platform_destroy_pfe_errors/71:
  Jump functions of caller  pfe_platform_create_failures/69:
  Jump functions of caller  pfe_platform_irq_unmask_fails_and_errors/68:
  Jump functions of caller  pfe_platform_irq_unmask_parity_wdt/67:
  Jump functions of caller  pfe_platform_destroy_emac/66:
  Jump functions of caller  pfe_platform_enable_ts/65:
  Jump functions of caller  pfe_platform_create_emac/64:
  Jump functions of caller  pfe_platform_destroy_util/63:
  Jump functions of caller  pfe_platform_create_util/62:
  Jump functions of caller  pfe_platform_default_init_util/61:
  Jump functions of caller  pfe_platform_destroy_tmu/60:
  Jump functions of caller  pfe_platform_create_tmu/59:
  Jump functions of caller  pfe_platform_destroy_rtable/58:
  Jump functions of caller  pfe_platform_create_rtable/57:
  Jump functions of caller  pfe_platform_destroy_l2_bridge/56:
  Jump functions of caller  pfe_platform_create_l2_bridge/55:
  Jump functions of caller  pfe_platform_destroy_class/54:
  Jump functions of caller  pfe_platform_create_class_object/52:
  Jump functions of caller  pfe_platform_destroy_hgpi/51:
  Jump functions of caller  pfe_platform_create_hgpi/50:
  Jump functions of caller  pfe_platform_destroy_etgpi/49:
  Jump functions of caller  pfe_platform_create_etgpi/48:
  Jump functions of caller  pfe_platform_destroy_gpi/47:
  Jump functions of caller  pfe_platform_destroy_bmu/45:
  Jump functions of caller  pfe_platform_create_bmu/44:
    callsite  pfe_platform_create_bmu/44 -> check_irq_vector.isra.0/248 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_platform_create_hif_nocpy/42:
  Jump functions of caller  pfe_platform_destroy_hif/41:
  Jump functions of caller  pfe_platform_create_hif/40:
  Jump functions of caller  pfe_platform_idex_rpc_cbk/39:
  Jump functions of caller  pfe_platform_bmu_isr/38:
    callsite  pfe_platform_bmu_isr/38 -> pfe_platform_bmu_isr.part.0/249 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR

 Propagating constants:

Not considering pfe_platform_get_fw_versions for cloning; -fipa-cp-clone disabled.
Not considering pfe_platform_get_instance for cloning; -fipa-cp-clone disabled.
Not considering pfe_platform_remove_sw_if for cloning; -fipa-cp-clone disabled.
Not considering pfe_platform_remove for cloning; -fipa-cp-clone disabled.
Not considering pfe_platform_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_platform_soft_reset for cloning; -fipa-cp-clone disabled.
Not considering pfe_platform_get_phy_if_by_id for cloning; -fipa-cp-clone disabled.
Not considering pfe_platform_idex_rpc_cbk for cloning; -fipa-cp-clone disabled.
Not considering pfe_platform_bmu_isr for cloning; -fipa-cp-clone disabled.

overall_size: 3285, max_new_size: 11001
 - context independent values, size: 60, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 44, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 79, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 40, time_benefit: 1.000000
 - context independent values, size: 13, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 44, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 44, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 32, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 44, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 81, time_benefit: 2.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 17, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 8, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 12, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 23, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 94, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 8, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 65, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 26, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 8, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 29, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 9, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 65, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 16, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 66, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 8, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 85, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 12, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 32, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 12, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 78, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 12, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 20, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 85, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 40, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 25, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 14, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 37, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 897, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: pfe_platform_create_gpi.isra.0/251:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const bool_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_class.isra.0/250:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_bmu_isr.part.0/249:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: check_irq_vector.isra.0/248:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const uint32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_pfe_errors.isra.0/247:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_get_fw_versions/98:
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
  Node: pfe_platform_get_instance/97:
  Node: pfe_platform_remove_sw_if/96:
  Node: pfe_platform_remove/95:
  Node: pfe_platform_destroy_group2/94:
  Node: pfe_platform_destroy_group1/93:
  Node: pfe_platform_init/92:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_platform_init_mirror_spd_acc_features/91:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_init_tmu_mirror_queue_ifaces_fci/90:
  Node: pfe_platform_init_etgpi_l2br_rtable_hifs/89:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_init_hm_fw_features/88:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_create_err_bmu_class_tmu_emac_util/87:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_create_gpis_add_modules/86:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_soft_reset/85:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_platform_destroy_ifaces/84:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        ref offset 1632: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: pfe_platform_destroy_pfe_phy_ifs/83:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_destroy_pfe_log_ifs/82:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        ref offset 1632: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: pfe_platform_create_ifaces/81:
  Node: pfe_platform_bind_ifaces/80:
  Node: pfe_platform_prepare_phy_if/79:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_platform_pfy_if * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_prepare_phy_if_emac/78:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_platform_pfy_if * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_prepare_phy_if_hif/77:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct pfe_platform_pfy_if * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_create_default_log_if/76:
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
  Node: pfe_platform_get_phy_if_by_id/75:
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
  Node: pfe_platform_register_phy_if/74:
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
  Node: pfe_platform_create_fci/72:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        ref offset 224: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: pfe_platform_destroy_pfe_errors/71:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_failures/69:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 606208 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x94000, mask = 0x0
         addr_t [606208, 606208]
        AGGS VARIABLE
  Node: pfe_platform_irq_unmask_fails_and_errors/68:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_irq_unmask_parity_wdt/67:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_destroy_emac/66:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_enable_ts/65:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        ref offset 0: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: pfe_platform_create_emac/64:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_destroy_util/63:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_util/62:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_default_init_util/61:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_destroy_tmu/60:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_tmu/59:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_destroy_rtable/58:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_rtable/57:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_destroy_l2_bridge/56:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_l2_bridge/55:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_destroy_class/54:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_class_object/52:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_destroy_hgpi/51:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_hgpi/50:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_destroy_etgpi/49:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_etgpi/48:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_destroy_gpi/47:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_destroy_bmu/45:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_bmu/44:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_create_hif_nocpy/42:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_destroy_hif/41:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_platform_create_hif/40:
    param [0]: &pfe [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_platform_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_platform_idex_rpc_cbk/39:
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
  Node: pfe_platform_bmu_isr/38:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:

 - Creating a specialized node of pfe_platform_create_pfe_errors.isra.0/247 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_class.isra.0/250 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_gpi.isra.0/251 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_ifaces/84 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_pfe_phy_ifs/83 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_pfe_log_ifs/82 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_fci/72 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_pfe_errors/71 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_failures/69 for all known contexts.
    replacing param #0 platform with const &pfe
    replacing param #2 parity_base with const 606208
 - Creating a specialized node of pfe_platform_irq_unmask_fails_and_errors/68 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_irq_unmask_parity_wdt/67 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_emac/66 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_enable_ts/65 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_emac/64 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_util/63 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_util/62 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_default_init_util/61 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_tmu/60 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_tmu/59 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_rtable/58 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_rtable/57 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_l2_bridge/56 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_l2_bridge/55 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_class/54 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_class_object/52 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_hgpi/51 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_hgpi/50 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_etgpi/49 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_etgpi/48 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_gpi/47 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_bmu/45 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_bmu/44 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of check_irq_vector.isra.0/248 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_hif_nocpy/42 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_destroy_hif/41 for all known contexts.
    replacing param #0 platform with const &pfe
 - Creating a specialized node of pfe_platform_create_hif/40 for all known contexts.
    replacing param #0 platform with const &pfe
Propagated bits info for function pfe_platform_create_hif.constprop/287:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_hif.constprop/286:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_hif_nocpy.constprop/285:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function check_irq_vector.isra.0.constprop/284:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_bmu.constprop/283:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_bmu.constprop/282:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_gpi.constprop/281:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_etgpi.constprop/280:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_etgpi.constprop/279:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_hgpi.constprop/278:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_hgpi.constprop/277:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_class_object.constprop/276:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_class.constprop/275:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_l2_bridge.constprop/274:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_l2_bridge.constprop/273:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_rtable.constprop/272:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_rtable.constprop/271:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_tmu.constprop/270:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_tmu.constprop/269:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_default_init_util.constprop/268:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_util.constprop/267:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_util.constprop/266:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_emac.constprop/265:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_enable_ts.constprop/264:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_emac.constprop/263:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_irq_unmask_parity_wdt.constprop/262:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_irq_unmask_fails_and_errors.constprop/261:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_failures.constprop/260:
 param 0: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x94000, mask = 0x0
Propagated bits info for function pfe_platform_destroy_pfe_errors.constprop/259:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_fci.constprop/258:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_pfe_log_ifs.constprop/257:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_pfe_phy_ifs.constprop/256:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_ifaces.constprop/255:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_gpi.isra.0.constprop/254:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_class.isra.0.constprop/253:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_pfe_errors.isra.0.constprop/252:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_gpi.isra.0/251:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_class.isra.0/250:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function check_irq_vector.isra.0/248:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_pfe_errors.isra.0/247:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_ifaces/84:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_pfe_phy_ifs/83:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_pfe_log_ifs/82:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_prepare_phy_if/79:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_prepare_phy_if_emac/78:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_prepare_phy_if_hif/77:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_fci/72:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_pfe_errors/71:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_failures/69:
 param 0: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x94000, mask = 0x0
Propagated bits info for function pfe_platform_irq_unmask_fails_and_errors/68:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_irq_unmask_parity_wdt/67:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_emac/66:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_enable_ts/65:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_emac/64:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_util/63:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_util/62:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_default_init_util/61:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_tmu/60:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_tmu/59:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_rtable/58:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_rtable/57:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_l2_bridge/56:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_l2_bridge/55:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_class/54:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_class_object/52:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_hgpi/51:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_hgpi/50:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_etgpi/49:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_etgpi/48:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_gpi/47:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_bmu/45:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_bmu/44:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_hif_nocpy/42:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_destroy_hif/41:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_platform_create_hif/40:
 param 0: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: pfe_platform_create_gpi.isra.0/251 pfe_platform_create_class.isra.0/250 check_irq_vector.isra.0/248 pfe_platform_create_pfe_errors.isra.0/247 pfe_platform_destroy_ifaces/84 pfe_platform_destroy_pfe_phy_ifs/83 pfe_platform_destroy_pfe_log_ifs/82 pfe_platform_create_fci/72 pfe_platform_destroy_pfe_errors/71 pfe_platform_create_failures/69 pfe_platform_irq_unmask_fails_and_errors/68 pfe_platform_irq_unmask_parity_wdt/67 pfe_platform_destroy_emac/66 pfe_platform_enable_ts/65 pfe_platform_create_emac/64 pfe_platform_destroy_util/63 pfe_platform_create_util/62 pfe_platform_default_init_util/61 pfe_platform_destroy_tmu/60 pfe_platform_create_tmu/59 pfe_platform_destroy_rtable/58 pfe_platform_create_rtable/57 pfe_platform_destroy_l2_bridge/56 pfe_platform_create_l2_bridge/55 pfe_platform_destroy_class/54 pfe_platform_create_class_object/52 pfe_platform_destroy_hgpi/51 pfe_platform_create_hgpi/50 pfe_platform_destroy_etgpi/49 pfe_platform_create_etgpi/48 pfe_platform_destroy_gpi/47 pfe_platform_destroy_bmu/45 pfe_platform_create_bmu/44 pfe_platform_create_hif_nocpy/42 pfe_platform_destroy_hif/41 pfe_platform_create_hif/40
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_platform_create_hif.constprop.0/287 (pfe_platform_create_hif.constprop) @0cbe5ee0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_hif/40
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_init_etgpi_l2br_rtable_hifs/89 (134217728 (estimated locally),0.12 per call) 
  Calls: pfe_hif_create/188 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (201326592 (estimated locally),0.19 per call) oal_util_raise_dem_for_drv_runtime_err/104 (201326592 (estimated locally),0.19 per call) pfe_hif_set_master_detect_cfg/189 (872415233 (estimated locally),0.81 per call) pfe_hif_irq_unmask/190 (872415233 (estimated locally),0.81 per call) pfe_hif_clear_master_up/191 (872415233 (estimated locally),0.81 per call) pfe_hif_init_emac_timer_ownership/192 (872415233 (estimated locally),0.81 per call) 
pfe_platform_destroy_hif.constprop.0/286 (pfe_platform_destroy_hif.constprop) @0cbe5c40
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_hif/41
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_clear_master_up/191 (574129754 (estimated locally),0.53 per call) pfe_hif_irq_mask/228 (574129754 (estimated locally),0.53 per call) pfe_hif_destroy/229 (574129754 (estimated locally),0.53 per call) 
pfe_platform_create_hif_nocpy.constprop.0/285 (pfe_platform_create_hif_nocpy.constprop) @0cbe59a0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (read)pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_hif_nocpy/42
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_init_etgpi_l2br_rtable_hifs/89 (67108864 (estimated locally),0.06 per call) 
  Calls: pfe_hif_nocpy_create/193 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (109629040 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/104 (109629040 (estimated locally),0.10 per call) 
check_irq_vector.isra.0.constprop.0/284 (check_irq_vector.isra.0.constprop) @0cbe5700
  Type: function definition analyzed
  Visibility: artificial
  References: pfe_platform_bmu_isr/38 (addr)bDetectBmuInit/36 (write)pfe/35 (addr)
  Referring: 
  Clone of check_irq_vector.isra.0/248
  Availability: local
  Function flags: count:1073741824 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) 
  Calls: pfe_hm_report/103 (201326592 (estimated locally),0.19 per call) oal_util_raise_dem_for_drv_runtime_err/104 (201326592 (estimated locally),0.19 per call) oal_irq_add_handler/159 (872415233 (estimated locally),0.81 per call) pfe_hm_report/103 (305345331 (estimated locally),0.28 per call) oal_util_raise_dem_for_drv_runtime_err/104 (305345331 (estimated locally),0.28 per call) pfe_bmu_irq_unmask/160 (567069902 (estimated locally),0.53 per call) pfe_bmu_irq_unmask/160 (567069902 (estimated locally),0.53 per call) 
pfe_platform_create_bmu.constprop.0/283 (pfe_platform_create_bmu.constprop) @0cbe5380
  Type: function definition analyzed
  Visibility:
  References: pfe_bmu_buffers/34 (addr)pfe_bmu_buffers/34 (addr)pfe_bmu_buffers/34 (addr)pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_bmu/44
  Availability: local
  Function flags: count:0 (precise) local unlikely_executed optimize_size
  Called by: pfe_platform_create_err_bmu_class_tmu_emac_util/87 (0 (precise),0.00 per call) 
  Calls: pfe_bmu_create/156 (0 (precise),0.00 per call) pfe_hm_report/103 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (0 (precise),0.00 per call) pfe_hm_report/103 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (0 (precise),0.00 per call) oal_mm_virt_to_phys_contig/157 (0 (precise),0.00 per call) pfe_bmu_create/156 (0 (precise),0.00 per call) pfe_hm_report/103 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (0 (precise),0.00 per call) oal_irq_create/158 (0 (precise),0.00 per call) check_irq_vector.isra.0.constprop/284 (0 (precise),0.00 per call) 
pfe_platform_destroy_bmu.constprop.0/282 (pfe_platform_destroy_bmu.constprop) @078029a0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (read)bDetectBmuInit/36 (write)pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_bmu/45
  Availability: local
  Function flags: count:357878150 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_bmu_destroy/231 (0 (precise),0.00 per call) oal_irq_destroy/218 (191357447 (estimated locally),0.53 per call) 
pfe_platform_destroy_gpi.constprop.0/281 (pfe_platform_destroy_gpi.constprop) @07802700
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_gpi/47
  Availability: local
  Function flags: count:268435456 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_gpi_destroy/230 (430597315 (estimated locally),1.60 per call) 
pfe_platform_create_etgpi.constprop.0/280 (pfe_platform_create_etgpi.constprop) @07802460
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_etgpi/48
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_init_etgpi_l2br_rtable_hifs/89 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_gpi_create/177 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (201326592 (estimated locally),0.19 per call) oal_util_raise_dem_for_drv_runtime_err/104 (201326592 (estimated locally),0.19 per call) pfe_gpi_create/177 (872415233 (estimated locally),0.81 per call) pfe_hm_report/103 (163577856 (estimated locally),0.15 per call) oal_util_raise_dem_for_drv_runtime_err/104 (163577856 (estimated locally),0.15 per call) pfe_gpi_create/177 (708837377 (estimated locally),0.66 per call) pfe_hm_report/103 (72372296 (estimated locally),0.07 per call) oal_util_raise_dem_for_drv_runtime_err/104 (72372296 (estimated locally),0.07 per call) 
pfe_platform_destroy_etgpi.constprop.0/279 (pfe_platform_destroy_etgpi.constprop) @078021c0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_etgpi/49
  Availability: local
  Function flags: count:268435456 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_gpi_destroy/230 (430597315 (estimated locally),1.60 per call) 
pfe_platform_create_hgpi.constprop.0/278 (pfe_platform_create_hgpi.constprop) @077ffee0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_hgpi/50
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_create_gpis_add_modules/86 (268435456 (estimated locally),0.25 per call) 
  Calls: pfe_gpi_create/177 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (109629040 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/104 (109629040 (estimated locally),0.10 per call) 
pfe_platform_destroy_hgpi.constprop.0/277 (pfe_platform_destroy_hgpi.constprop) @077ffc40
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_hgpi/51
  Availability: local
  Function flags: count:536870913 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_gpi_destroy/230 (287064877 (estimated locally),0.53 per call) 
pfe_platform_create_class_object.constprop.0/276 (pfe_platform_create_class_object.constprop) @077ff9a0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_class_object/52
  Availability: local
  Function flags: count:1073741824 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_platform_create_class.isra.0.constprop/253 (783341637 (estimated locally),0.73 per call) 
  Calls: pfe_class_create/163 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (109629040 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/104 (109629040 (estimated locally),0.10 per call) ELF_Open/164 (48723064 (estimated locally),0.05 per call) pfe_hm_report/103 (17053072 (estimated locally),0.02 per call) oal_util_raise_dem_for_drv_runtime_err/104 (17053072 (estimated locally),0.02 per call) pfe_class_load_firmware/165 (31669991 (estimated locally),0.03 per call) ELF_Close/166 (31669991 (estimated locally),0.03 per call) pfe_hm_report/103 (6638030 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (6638030 (estimated locally),0.01 per call) pfe_hm_report/103 (915389721 (estimated locally),0.85 per call) oal_util_raise_dem_for_drv_runtime_err/104 (915389721 (estimated locally),0.85 per call) 
pfe_platform_destroy_class.constprop.0/275 (pfe_platform_destroy_class.constprop) @077ff700
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_class/54
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group2/94 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_class_destroy/235 (574129754 (estimated locally),0.53 per call) 
pfe_platform_create_l2_bridge.constprop.0/274 (pfe_platform_create_l2_bridge.constprop) @077ff460
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_l2_bridge/55
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_init_etgpi_l2br_rtable_hifs/89 (536870913 (estimated locally),0.50 per call) 
  Calls: pfe_l2br_table_create/184 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (201326592 (estimated locally),0.19 per call) oal_util_raise_dem_for_drv_runtime_err/104 (201326592 (estimated locally),0.19 per call) pfe_l2br_table_create/184 (872415233 (estimated locally),0.81 per call) pfe_hm_report/103 (89073595 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/104 (89073595 (estimated locally),0.08 per call) pfe_l2br_create/185 (783341638 (estimated locally),0.73 per call) pfe_hm_report/103 (79979181 (estimated locally),0.07 per call) oal_util_raise_dem_for_drv_runtime_err/104 (79979181 (estimated locally),0.07 per call) 
pfe_platform_destroy_l2_bridge.constprop.0/273 (pfe_platform_destroy_l2_bridge.constprop) @077ff1c0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_l2_bridge/56
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_l2br_destroy/233 (574129754 (estimated locally),0.53 per call) 
pfe_platform_create_rtable.constprop.0/272 (pfe_platform_create_rtable.constprop) @07779ee0
  Type: function definition analyzed
  Visibility:
  References: pfe_rtable_buffers/37 (addr)pfe_rtable_buffers/37 (addr)pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_rtable/57
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_init_etgpi_l2br_rtable_hifs/89 (268435456 (estimated locally),0.25 per call) 
  Calls: pfe_hm_report/103 (375809639 (estimated locally),0.35 per call) oal_util_raise_dem_for_drv_runtime_err/104 (375809639 (estimated locally),0.35 per call) pfe_rtable_get_entry_size/186 (697932186 (estimated locally),0.65 per call) pfe_rtable_get_entry_size/186 (697932186 (estimated locally),0.65 per call) pfe_hm_report/103 (130862285 (estimated locally),0.12 per call) oal_util_raise_dem_for_drv_runtime_err/104 (130862285 (estimated locally),0.12 per call) pfe_rtable_create/187 (567069901 (estimated locally),0.53 per call) pfe_hm_report/103 (57897837 (estimated locally),0.05 per call) oal_util_raise_dem_for_drv_runtime_err/104 (57897837 (estimated locally),0.05 per call) 
pfe_platform_destroy_rtable.constprop.0/271 (pfe_platform_destroy_rtable.constprop) @069998c0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_rtable/58
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_rtable_destroy/232 (574129754 (estimated locally),0.53 per call) 
pfe_platform_create_tmu.constprop.0/270 (pfe_platform_create_tmu.constprop) @074390e0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_tmu/59
  Availability: local
  Function flags: count:1073741824 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_platform_create_err_bmu_class_tmu_emac_util/87 (0 (precise),0.00 per call) 
  Calls: pfe_feature_mgr_is_available/135 (1073741824 (estimated locally),1.00 per call) pfe_tmu_create/167 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (109629040 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/104 (109629040 (estimated locally),0.10 per call) 
pfe_platform_destroy_tmu.constprop.0/269 (pfe_platform_destroy_tmu.constprop) @07434e00
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_tmu/60
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group2/94 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_tmu_destroy/236 (574129754 (estimated locally),0.53 per call) 
pfe_platform_default_init_util.constprop.0/268 (pfe_platform_default_init_util.constprop) @07434b60
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_default_init_util/61
  Availability: local
  Function flags: count:1073741824 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_platform_create_err_bmu_class_tmu_emac_util/87 (0 (precise),0.00 per call) 
  Calls: pfe_util_create/172 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (201326592 (estimated locally),0.19 per call) oal_util_raise_dem_for_drv_runtime_err/104 (201326592 (estimated locally),0.19 per call) pfe_util_default_init/174 (872415233 (estimated locally),0.81 per call) 
pfe_platform_create_util.constprop.0/267 (pfe_platform_create_util.constprop) @073d1a80
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_util/62
  Availability: local
  Function flags: count:1073741823 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_platform_create_err_bmu_class_tmu_emac_util/87 (0 (precise),0.00 per call) 
  Calls: pfe_feature_mgr_is_available/135 (1073741823 (estimated locally),1.00 per call) pfe_util_create/172 (1073741823 (estimated locally),1.00 per call) pfe_hm_report/103 (109629040 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/104 (109629040 (estimated locally),0.10 per call) ELF_Open/164 (515511105 (estimated locally),0.48 per call) pfe_hm_report/103 (257755553 (estimated locally),0.24 per call) oal_util_raise_dem_for_drv_runtime_err/104 (257755553 (estimated locally),0.24 per call) pfe_util_load_firmware/173 (257755553 (estimated locally),0.24 per call) ELF_Close/166 (257755553 (estimated locally),0.24 per call) pfe_hm_report/103 (85059332 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/104 (85059332 (estimated locally),0.08 per call) 
pfe_platform_destroy_util.constprop.0/266 (pfe_platform_destroy_util.constprop) @073d17e0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_util/63
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group2/94 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_util_destroy/141 (574129754 (estimated locally),0.53 per call) 
pfe_platform_create_emac.constprop.0/265 (pfe_platform_create_emac.constprop) @07296380
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_emac/64
  Availability: local
  Function flags: count:1073741824 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_platform_create_err_bmu_class_tmu_emac_util/87 (0 (precise),0.00 per call) 
  Calls: pfe_emac_create/168 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (322122547 (estimated locally),0.30 per call) oal_util_raise_dem_for_drv_runtime_err/104 (322122547 (estimated locally),0.30 per call) pfe_emac_set_max_frame_length/169 (751619278 (estimated locally),0.70 per call) pfe_emac_enable_rx_flow_control/170 (751619278 (estimated locally),0.70 per call) pfe_emac_enable_broadcast/171 (751619278 (estimated locally),0.70 per call) pfe_emac_create/168 (751619278 (estimated locally),0.70 per call) pfe_hm_report/103 (140928614 (estimated locally),0.13 per call) oal_util_raise_dem_for_drv_runtime_err/104 (140928614 (estimated locally),0.13 per call) pfe_emac_set_max_frame_length/169 (610690663 (estimated locally),0.57 per call) pfe_emac_enable_rx_flow_control/170 (610690663 (estimated locally),0.57 per call) pfe_emac_enable_broadcast/171 (610690663 (estimated locally),0.57 per call) pfe_emac_create/168 (307828359 (estimated locally),0.29 per call) pfe_hm_report/103 (57717817 (estimated locally),0.05 per call) oal_util_raise_dem_for_drv_runtime_err/104 (57717817 (estimated locally),0.05 per call) pfe_emac_set_max_frame_length/169 (250110542 (estimated locally),0.23 per call) pfe_emac_enable_rx_flow_control/170 (250110542 (estimated locally),0.23 per call) pfe_emac_enable_broadcast/171 (250110542 (estimated locally),0.23 per call) 
pfe_platform_enable_ts.constprop.0/264 (pfe_platform_enable_ts.constprop) @071a17e0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_enable_ts/65
  Availability: local
  Function flags: count:1073741824 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) 
  Calls: pfe_emac_enable_ts/217 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable_ts/217 (354334802 (estimated locally),0.33 per call) pfe_emac_enable_ts/217 (116930485 (estimated locally),0.11 per call) 
pfe_platform_destroy_emac.constprop.0/263 (pfe_platform_destroy_emac.constprop) @071a1540
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_emac/66
  Availability: local
  Function flags: count:268435456 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group2/94 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_emac_destroy/237 (430597315 (estimated locally),1.60 per call) 
pfe_platform_irq_unmask_parity_wdt.constprop.0/262 (pfe_platform_irq_unmask_parity_wdt.constprop) @07039b60
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_irq_unmask_parity_wdt/67
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_create_pfe_errors.isra.0.constprop/252 (354334801 (estimated locally),0.33 per call) 
  Calls: pfe_parity_irq_unmask/149 (1073741824 (estimated locally),1.00 per call) pfe_wdt_irq_unmask/150 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_irq_unmask_fails_and_errors.constprop.0/261 (pfe_platform_irq_unmask_fails_and_errors.constprop) @070398c0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_irq_unmask_fails_and_errors/68
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_create_pfe_errors.isra.0.constprop/252 (71717364 (estimated locally),0.07 per call) 
  Calls: pfe_bus_err_irq_unmask/151 (1073741824 (estimated locally),1.00 per call) pfe_fw_fail_stop_irq_unmask/152 (1073741824 (estimated locally),1.00 per call) pfe_host_fail_stop_irq_unmask/153 (1073741824 (estimated locally),1.00 per call) pfe_fail_stop_irq_unmask/154 (1073741824 (estimated locally),1.00 per call) pfe_ecc_err_irq_unmask/155 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_create_failures.constprop.0/260 (pfe_platform_create_failures.constprop) @07039620
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_failures/69
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_create_pfe_errors.isra.0.constprop/252 (108662672 (estimated locally),0.10 per call) 
  Calls: pfe_bus_err_create/144 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (187153200 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/104 (187153200 (estimated locally),0.17 per call) pfe_fw_fail_stop_create/145 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (187153200 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/104 (187153200 (estimated locally),0.17 per call) pfe_host_fail_stop_create/146 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (187153200 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/104 (187153200 (estimated locally),0.17 per call) pfe_fail_stop_create/147 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (187153200 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/104 (187153200 (estimated locally),0.17 per call) pfe_ecc_err_create/148 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (109629040 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/104 (109629040 (estimated locally),0.10 per call) 
pfe_platform_destroy_pfe_errors.constprop.0/259 (pfe_platform_destroy_pfe_errors.constprop) @07039380
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_pfe_errors/71
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group2/94 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_ecc_err_destroy/238 (574129754 (estimated locally),0.53 per call) pfe_fail_stop_destroy/239 (574129754 (estimated locally),0.53 per call) pfe_host_fail_stop_destroy/240 (574129754 (estimated locally),0.53 per call) pfe_fw_fail_stop_destroy/241 (574129754 (estimated locally),0.53 per call) pfe_bus_err_destroy/242 (574129754 (estimated locally),0.53 per call) pfe_parity_destroy/243 (574129754 (estimated locally),0.53 per call) pfe_wdt_destroy/244 (574129754 (estimated locally),0.53 per call) 
pfe_platform_create_fci.constprop.0/258 (pfe_platform_create_fci.constprop) @070390e0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_fci/72
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (134217728 (estimated locally),0.13 per call) 
  Calls: fci_init/216 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (354334802 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/104 (354334802 (estimated locally),0.33 per call) 
pfe_platform_destroy_pfe_log_ifs.constprop.0/257 (pfe_platform_destroy_pfe_log_ifs.constprop) @07033ee0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_pfe_log_ifs/82
  Availability: local
  Function flags: count:118111600 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_ifaces.constprop/255 (574129754 (estimated locally),0.53 per call) 
  Calls: pfe_if_db_lock/134 (118111600 (estimated locally),1.00 per call) pfe_if_db_get_first/99 (118111600 (estimated locally),1.00 per call) pfe_if_db_entry_get_log_if/224 (955630223 (estimated locally),8.09 per call) pfe_if_db_remove/225 (955630223 (estimated locally),8.09 per call) pfe_log_if_destroy/212 (955630223 (estimated locally),8.09 per call) pfe_if_db_get_next/226 (955630223 (estimated locally),8.09 per call) pfe_if_db_unlock/105 (118111601 (estimated locally),1.00 per call) pfe_if_db_destroy/227 (63154273 (estimated locally),0.53 per call) 
pfe_platform_destroy_pfe_phy_ifs.constprop.0/256 (pfe_platform_destroy_pfe_phy_ifs.constprop) @0c8890e0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_pfe_phy_ifs/83
  Availability: local
  Function flags: count:118111600 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_ifaces.constprop/255 (574129754 (estimated locally),0.53 per call) 
  Calls: pfe_if_db_lock/134 (118111600 (estimated locally),1.00 per call) pfe_if_db_get_first/99 (118111600 (estimated locally),1.00 per call) pfe_if_db_entry_get_phy_if/100 (955630223 (estimated locally),8.09 per call) pfe_if_db_remove/225 (955630223 (estimated locally),8.09 per call) pfe_phy_if_destroy/203 (955630223 (estimated locally),8.09 per call) pfe_if_db_get_next/226 (955630223 (estimated locally),8.09 per call) pfe_if_db_unlock/105 (118111601 (estimated locally),1.00 per call) pfe_if_db_destroy/227 (63154273 (estimated locally),0.53 per call) 
pfe_platform_destroy_ifaces.constprop.0/255 (pfe_platform_destroy_ifaces.constprop) @0c87e7e0
  Type: function definition analyzed
  Visibility:
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_destroy_ifaces/84
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_platform_destroy_pfe_log_ifs.constprop/257 (574129754 (estimated locally),0.53 per call) pfe_log_ifs_deinit/223 (574129754 (estimated locally),0.53 per call) pfe_platform_destroy_pfe_phy_ifs.constprop/256 (574129754 (estimated locally),0.53 per call) 
pfe_platform_create_gpi.isra.0.constprop.0/254 (pfe_platform_create_gpi.isra.0.constprop) @0c8037e0
  Type: function definition analyzed
  Visibility: artificial
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_gpi.isra.0/251
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_platform_create_gpis_add_modules/86 (536870911 (estimated locally),0.50 per call) 
  Calls: pfe_gpi_create/177 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/103 (201326592 (estimated locally),0.19 per call) oal_util_raise_dem_for_drv_runtime_err/104 (201326592 (estimated locally),0.19 per call) pfe_gpi_create/177 (872415233 (estimated locally),0.81 per call) pfe_hm_report/103 (163577856 (estimated locally),0.15 per call) oal_util_raise_dem_for_drv_runtime_err/104 (163577856 (estimated locally),0.15 per call) pfe_gpi_create/177 (708837377 (estimated locally),0.66 per call) pfe_hm_report/103 (72372296 (estimated locally),0.07 per call) oal_util_raise_dem_for_drv_runtime_err/104 (72372296 (estimated locally),0.07 per call) 
pfe_platform_create_class.isra.0.constprop.0/253 (pfe_platform_create_class.isra.0.constprop) @0c7eec40
  Type: function definition analyzed
  Visibility: artificial
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_class.isra.0/250
  Availability: local
  Function flags: count:1073741823 (estimated locally) local unlikely_executed optimize_size
  Called by: pfe_platform_create_err_bmu_class_tmu_emac_util/87 (0 (precise),0.00 per call) 
  Calls: pfe_feature_mgr_is_available/135 (354334802 (estimated locally),0.33 per call) pfe_hm_report/103 (109629040 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/104 (109629040 (estimated locally),0.10 per call) pfe_hm_report/103 (180771147 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/104 (180771147 (estimated locally),0.17 per call) pfe_platform_create_class_object.constprop/276 (783341637 (estimated locally),0.73 per call) 
pfe_platform_create_pfe_errors.isra.0.constprop.0/252 (pfe_platform_create_pfe_errors.isra.0.constprop) @0c7e4c40
  Type: function definition analyzed
  Visibility: artificial
  References: pfe/35 (addr)
  Referring: 
  Clone of pfe_platform_create_pfe_errors.isra.0/247
  Availability: local
  Function flags: count:1073741821 (estimated locally) local optimize_size
  Called by: pfe_platform_create_err_bmu_class_tmu_emac_util/87 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_parity_create/142 (1073741821 (estimated locally),1.00 per call) pfe_wdt_create/143 (751619275 (estimated locally),0.70 per call) pfe_hm_report/103 (322122546 (estimated locally),0.30 per call) oal_util_raise_dem_for_drv_runtime_err/104 (322122546 (estimated locally),0.30 per call) pfe_hm_report/103 (131007240 (estimated locally),0.12 per call) oal_util_raise_dem_for_drv_runtime_err/104 (131007240 (estimated locally),0.12 per call) pfe_feature_mgr_is_available/135 (1073741821 (estimated locally),1.00 per call) pfe_platform_create_failures.constprop/260 (108662672 (estimated locally),0.10 per call) pfe_platform_irq_unmask_parity_wdt.constprop/262 (354334801 (estimated locally),0.33 per call) pfe_feature_mgr_is_available/135 (354334801 (estimated locally),0.33 per call) pfe_platform_irq_unmask_fails_and_errors.constprop/261 (71717364 (estimated locally),0.07 per call) 
pfe_platform_create_gpi.isra.0/251 (pfe_platform_create_gpi.isra.0) @07033c40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_class.isra.0/250 (pfe_platform_create_class.isra.0) @07010540
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_bmu_isr.part.0/249 (pfe_platform_bmu_isr.part.0) @06f6cc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:0 (precise) first_run:1 body local split_part unlikely_executed optimize_size
  Called by: pfe_platform_bmu_isr/38 (0 (precise),0.00 per call) 
  Calls: pfe_bmu_isr/162 (0 (precise),0.00 per call) pfe_bmu_isr/162 (0 (precise),0.00 per call) pfe_bmu_irq_unmask/160 (0 (precise),0.00 per call) pfe_bmu_irq_unmask/160 (0 (precise),0.00 per call) 
check_irq_vector.isra.0/248 (check_irq_vector.isra.0) @06f6c9a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_create_pfe_errors.isra.0/247 (pfe_platform_create_pfe_errors.isra.0) @06db6d20
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741821 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_util_get_fw_version/246 (pfe_util_get_fw_version) @0c9777e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_get_fw_versions/98 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_class_get_fw_version/245 (pfe_class_get_fw_version) @0c977700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_get_fw_versions/98 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_wdt_destroy/244 (pfe_wdt_destroy) @0c977380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_errors.constprop/259 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_parity_destroy/243 (pfe_parity_destroy) @0c9772a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_errors.constprop/259 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_bus_err_destroy/242 (pfe_bus_err_destroy) @0c9771c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_errors.constprop/259 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_fw_fail_stop_destroy/241 (pfe_fw_fail_stop_destroy) @0c9770e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_errors.constprop/259 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_host_fail_stop_destroy/240 (pfe_host_fail_stop_destroy) @0c977000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_errors.constprop/259 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_fail_stop_destroy/239 (pfe_fail_stop_destroy) @0c969ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_errors.constprop/259 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_ecc_err_destroy/238 (pfe_ecc_err_destroy) @0c969e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_errors.constprop/259 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_emac_destroy/237 (pfe_emac_destroy) @0c969c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_emac.constprop/263 (430597315 (estimated locally),1.60 per call) 
  Calls: 
pfe_tmu_destroy/236 (pfe_tmu_destroy) @0c969a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_tmu.constprop/269 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_class_destroy/235 (pfe_class_destroy) @0c9697e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_class.constprop/275 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_mirror_deinit/234 (pfe_mirror_deinit) @0c969620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_group2/94 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_destroy/233 (pfe_l2br_destroy) @0c969460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_l2_bridge.constprop/273 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_rtable_destroy/232 (pfe_rtable_destroy) @0c9692a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_rtable.constprop/271 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_bmu_destroy/231 (pfe_bmu_destroy) @0c9690e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_bmu.constprop/282 (0 (precise),0.00 per call) 
  Calls: 
pfe_gpi_destroy/230 (pfe_gpi_destroy) @0c95cd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_gpi.constprop/281 (430597315 (estimated locally),1.60 per call) pfe_platform_destroy_etgpi.constprop/279 (430597315 (estimated locally),1.60 per call) pfe_platform_destroy_hgpi.constprop/277 (287064877 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_destroy/229 (pfe_hif_destroy) @0c95cb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_hif.constprop/286 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_irq_mask/228 (pfe_hif_irq_mask) @0c95ca80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_hif.constprop/286 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_if_db_destroy/227 (pfe_if_db_destroy) @0c95c7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_log_ifs.constprop/257 (63154273 (estimated locally),0.53 per call) pfe_platform_destroy_pfe_phy_ifs.constprop/256 (63154273 (estimated locally),0.53 per call) 
  Calls: 
pfe_if_db_get_next/226 (pfe_if_db_get_next) @0c95c700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_log_ifs.constprop/257 (955630223 (estimated locally),8.09 per call) pfe_platform_destroy_pfe_phy_ifs.constprop/256 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_if_db_remove/225 (pfe_if_db_remove) @0c95c620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_log_ifs.constprop/257 (955630223 (estimated locally),8.09 per call) pfe_platform_destroy_pfe_phy_ifs.constprop/256 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_if_db_entry_get_log_if/224 (pfe_if_db_entry_get_log_if) @0c95c540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_log_ifs.constprop/257 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_log_ifs_deinit/223 (pfe_log_ifs_deinit) @0c95c380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_ifaces.constprop/255 (574129754 (estimated locally),0.53 per call) 
  Calls: 
fci_fini/222 (fci_fini) @0c95c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_mm_dev_unmap/221 (oal_mm_dev_unmap) @0c951e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_remove/95 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_feature_mgr_fini/220 (pfe_feature_mgr_fini) @0c951c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_remove/95 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hm_destroy/219 (pfe_hm_destroy) @0c951b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_remove/95 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_irq_destroy/218 (oal_irq_destroy) @0c951a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_bmu.constprop/282 (191357447 (estimated locally),0.53 per call) pfe_platform_remove/95 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_emac_enable_ts/217 (pfe_emac_enable_ts) @0c9518c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_enable_ts.constprop/264 (1073741824 (estimated locally),1.00 per call) pfe_platform_enable_ts.constprop/264 (354334802 (estimated locally),0.33 per call) pfe_platform_enable_ts.constprop/264 (116930485 (estimated locally),0.11 per call) 
  Calls: 
fci_init/216 (fci_init) @0c951700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_fci.constprop/258 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_bind_hif/215 (pfe_phy_if_bind_hif) @0c951460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_prepare_phy_if_hif/77 (751619277 (estimated locally),0.70 per call) 
  Calls: 
pfe_log_if_enable/214 (pfe_log_if_enable) @0c9512a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_default_log_if/76 (368595435 (estimated locally),0.34 per call) 
  Calls: 
pfe_log_if_promisc_enable/213 (pfe_log_if_promisc_enable) @0c9511c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_default_log_if/76 (567069901 (estimated locally),0.53 per call) 
  Calls: 
pfe_log_if_destroy/212 (pfe_log_if_destroy) @0c9510e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_log_ifs.constprop/257 (955630223 (estimated locally),8.09 per call) pfe_platform_create_default_log_if/76 (198474465 (estimated locally),0.18 per call) pfe_platform_create_default_log_if/76 (305345331 (estimated locally),0.28 per call) 
  Calls: 
pfe_if_db_add/211 (pfe_if_db_add) @0c951000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_default_log_if/76 (872415231 (estimated locally),0.81 per call) pfe_platform_register_phy_if/74 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_log_if_create/210 (pfe_log_if_create) @0c940540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_default_log_if/76 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_bind_gpi/209 (pfe_emac_bind_gpi) @0c940e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_prepare_phy_if_emac/78 (697932186 (estimated locally),0.65 per call) 
  Calls: 
pfe_phy_if_bind_emac/208 (pfe_phy_if_bind_emac) @0c940d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_prepare_phy_if_emac/78 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_get_name/207 (pfe_phy_if_get_name) @0c940b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_prepare_phy_if/79 (100709858 (estimated locally),0.09 per call) 
  Calls: 
pfe_phy_if_bind_util/206 (pfe_phy_if_bind_util) @0c940a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_prepare_phy_if/79 (193330565 (estimated locally),0.18 per call) 
  Calls: 
pfe_phy_if_get_id/205 (pfe_phy_if_get_id) @0c9409a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_prepare_phy_if/79 (848685538 (estimated locally),0.79 per call) 
  Calls: 
pfe_phy_if_set_op_mode/204 (pfe_phy_if_set_op_mode) @0c9408c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_prepare_phy_if/79 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_destroy/203 (pfe_phy_if_destroy) @0c940700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_phy_ifs.constprop/256 (955630223 (estimated locally),8.09 per call) pfe_platform_bind_ifaces/80 (10942473 (estimated locally),0.18 per call) 
  Calls: 
pfe_phy_if_create/202 (pfe_phy_if_create) @0c940620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_bind_ifaces/80 (310332862 (estimated locally),5.04 per call) 
  Calls: 
pfe_hif_nocpy_get_channel/201 (pfe_hif_nocpy_get_channel) @0c940460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_bind_ifaces/80 (61599606 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_get_channel/200 (pfe_hif_get_channel) @0c940380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_bind_ifaces/80 (61599606 (estimated locally),1.00 per call) pfe_platform_bind_ifaces/80 (61599606 (estimated locally),1.00 per call) pfe_platform_bind_ifaces/80 (61599606 (estimated locally),1.00 per call) pfe_platform_bind_ifaces/80 (61599606 (estimated locally),1.00 per call) 
  Calls: 
pfe_log_ifs_init/199 (pfe_log_ifs_init) @0c9400e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_ifaces/81 (127432614 (estimated locally),0.12 per call) 
  Calls: 
pfe_if_db_create/198 (pfe_if_db_create) @0c940000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_ifaces/81 (176743902 (estimated locally),0.16 per call) pfe_platform_create_ifaces/81 (187153200 (estimated locally),0.17 per call) 
  Calls: 
pfe_mirror_init/197 (pfe_mirror_init) @0c932e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_feature_mgr_get_val/195 (pfe_feature_mgr_get_val) @0c932d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (182536110 (estimated locally),0.17 per call) 
  Calls: 
pfe_tmu_queue_reset_tail_drop_policy/194 (pfe_tmu_queue_reset_tail_drop_policy) @0c932c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_nocpy_create/193 (pfe_hif_nocpy_create) @0c932a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_hif_nocpy.constprop/285 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_init_emac_timer_ownership/192 (pfe_hif_init_emac_timer_ownership) @0c9328c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_hif.constprop/287 (872415233 (estimated locally),0.81 per call) 
  Calls: 
pfe_hif_clear_master_up/191 (pfe_hif_clear_master_up) @0c9327e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_hif.constprop/287 (872415233 (estimated locally),0.81 per call) pfe_platform_destroy_hif.constprop/286 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_irq_unmask/190 (pfe_hif_irq_unmask) @0c932700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_hif.constprop/287 (872415233 (estimated locally),0.81 per call) 
  Calls: 
pfe_hif_set_master_detect_cfg/189 (pfe_hif_set_master_detect_cfg) @0c932620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_hif.constprop/287 (872415233 (estimated locally),0.81 per call) 
  Calls: 
pfe_hif_create/188 (pfe_hif_create) @0c932540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_hif.constprop/287 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_create/187 (pfe_rtable_create) @0c932380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_rtable.constprop/272 (567069901 (estimated locally),0.53 per call) 
  Calls: 
pfe_rtable_get_entry_size/186 (pfe_rtable_get_entry_size) @0c9322a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_rtable.constprop/272 (697932186 (estimated locally),0.65 per call) pfe_platform_create_rtable.constprop/272 (697932186 (estimated locally),0.65 per call) 
  Calls: 
pfe_l2br_create/185 (pfe_l2br_create) @0c9320e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_l2_bridge.constprop/274 (783341638 (estimated locally),0.73 per call) 
  Calls: 
pfe_l2br_table_create/184 (pfe_l2br_table_create) @0c932000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_l2_bridge.constprop/274 (1073741824 (estimated locally),1.00 per call) pfe_platform_create_l2_bridge.constprop/274 (872415233 (estimated locally),0.81 per call) 
  Calls: 
pfe_emac_pps0_configure/183 (pfe_emac_pps0_configure) @0c91ed20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) 
  Calls: 
pfe_util_enable/182 (pfe_util_enable) @0c91ec40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) 
  Calls: 
pfe_tmu_enable/181 (pfe_tmu_enable) @0c91eb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) 
  Calls: 
pfe_gpi_enable/180 (pfe_gpi_enable) @0c91e9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) 
  Calls: 
pfe_bmu_enable/179 (pfe_bmu_enable) @0c91e8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) pfe_platform_init_mirror_spd_acc_features/91 (0 (precise),0.00 per call) 
  Calls: 
pfe_class_enable/178 (pfe_class_enable) @0c91e7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_gpi_create/177 (pfe_gpi_create) @0c91e540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_etgpi.constprop/280 (1073741824 (estimated locally),1.00 per call) pfe_platform_create_etgpi.constprop/280 (872415233 (estimated locally),0.81 per call) pfe_platform_create_etgpi.constprop/280 (708837377 (estimated locally),0.66 per call) pfe_platform_create_hgpi.constprop/278 (1073741824 (estimated locally),1.00 per call) pfe_platform_create_gpi.isra.0.constprop/254 (1073741824 (estimated locally),1.00 per call) pfe_platform_create_gpi.isra.0.constprop/254 (872415233 (estimated locally),0.81 per call) pfe_platform_create_gpi.isra.0.constprop/254 (708837377 (estimated locally),0.66 per call) 
  Calls: 
pfe_feature_mgr_add_modules/176 (pfe_feature_mgr_add_modules) @0c91e2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_gpis_add_modules/86 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_cfg_stop_all_chnl_dma/175 (pfe_hif_cfg_stop_all_chnl_dma) @0c91e1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_gpis_add_modules/86 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_util_default_init/174 (pfe_util_default_init) @0c91e000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_default_init_util.constprop/268 (872415233 (estimated locally),0.81 per call) 
  Calls: 
pfe_util_load_firmware/173 (pfe_util_load_firmware) @0c908e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_util.constprop/267 (257755553 (estimated locally),0.24 per call) 
  Calls: 
pfe_util_create/172 (pfe_util_create) @0c908d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_default_init_util.constprop/268 (1073741824 (estimated locally),1.00 per call) pfe_platform_create_util.constprop/267 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_enable_broadcast/171 (pfe_emac_enable_broadcast) @0c908b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_emac.constprop/265 (751619278 (estimated locally),0.70 per call) pfe_platform_create_emac.constprop/265 (610690663 (estimated locally),0.57 per call) pfe_platform_create_emac.constprop/265 (250110542 (estimated locally),0.23 per call) 
  Calls: 
pfe_emac_enable_rx_flow_control/170 (pfe_emac_enable_rx_flow_control) @0c908a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_emac.constprop/265 (751619278 (estimated locally),0.70 per call) pfe_platform_create_emac.constprop/265 (610690663 (estimated locally),0.57 per call) pfe_platform_create_emac.constprop/265 (250110542 (estimated locally),0.23 per call) 
  Calls: 
pfe_emac_set_max_frame_length/169 (pfe_emac_set_max_frame_length) @0c9089a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_emac.constprop/265 (751619278 (estimated locally),0.70 per call) pfe_platform_create_emac.constprop/265 (610690663 (estimated locally),0.57 per call) pfe_platform_create_emac.constprop/265 (250110542 (estimated locally),0.23 per call) 
  Calls: 
pfe_emac_create/168 (pfe_emac_create) @0c9088c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_emac.constprop/265 (1073741824 (estimated locally),1.00 per call) pfe_platform_create_emac.constprop/265 (751619278 (estimated locally),0.70 per call) pfe_platform_create_emac.constprop/265 (307828359 (estimated locally),0.29 per call) 
  Calls: 
pfe_tmu_create/167 (pfe_tmu_create) @0c908700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_tmu.constprop/270 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ELF_Close/166 (ELF_Close) @0c908540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_class_object.constprop/276 (31669991 (estimated locally),0.03 per call) pfe_platform_create_util.constprop/267 (257755553 (estimated locally),0.24 per call) 
  Calls: 
pfe_class_load_firmware/165 (pfe_class_load_firmware) @0c908460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_class_object.constprop/276 (31669991 (estimated locally),0.03 per call) 
  Calls: 
ELF_Open/164 (ELF_Open) @0c908380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_class_object.constprop/276 (48723064 (estimated locally),0.05 per call) pfe_platform_create_util.constprop/267 (515511105 (estimated locally),0.48 per call) 
  Calls: 
pfe_class_create/163 (pfe_class_create) @0c9082a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_class_object.constprop/276 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_isr/162 (pfe_bmu_isr) @0c908000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_bmu_isr.part.0/249 (0 (precise),0.00 per call) pfe_platform_bmu_isr.part.0/249 (0 (precise),0.00 per call) 
  Calls: 
pfe_bmu_irq_mask/161 (pfe_bmu_irq_mask) @0c8fdee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_bmu_isr/38 (1073741824 (estimated locally),1.00 per call) pfe_platform_bmu_isr/38 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_bmu_irq_unmask/160 (pfe_bmu_irq_unmask) @0c8fdd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: check_irq_vector.isra.0.constprop/284 (567069902 (estimated locally),0.53 per call) check_irq_vector.isra.0.constprop/284 (567069902 (estimated locally),0.53 per call) pfe_platform_bmu_isr.part.0/249 (0 (precise),0.00 per call) pfe_platform_bmu_isr.part.0/249 (0 (precise),0.00 per call) 
  Calls: 
oal_irq_add_handler/159 (oal_irq_add_handler) @0c8fdc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: check_irq_vector.isra.0.constprop/284 (872415233 (estimated locally),0.81 per call) 
  Calls: 
oal_irq_create/158 (oal_irq_create) @0c8fda80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) 
  Calls: 
oal_mm_virt_to_phys_contig/157 (oal_mm_virt_to_phys_contig) @0c8fd9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) 
  Calls: 
pfe_bmu_create/156 (pfe_bmu_create) @0c8fd8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) 
  Calls: 
pfe_ecc_err_irq_unmask/155 (pfe_ecc_err_irq_unmask) @0c8fd700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_irq_unmask_fails_and_errors.constprop/261 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fail_stop_irq_unmask/154 (pfe_fail_stop_irq_unmask) @0c8fd620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_irq_unmask_fails_and_errors.constprop/261 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_host_fail_stop_irq_unmask/153 (pfe_host_fail_stop_irq_unmask) @0c8fd540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_irq_unmask_fails_and_errors.constprop/261 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fw_fail_stop_irq_unmask/152 (pfe_fw_fail_stop_irq_unmask) @0c8fd460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_irq_unmask_fails_and_errors.constprop/261 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bus_err_irq_unmask/151 (pfe_bus_err_irq_unmask) @0c8fd380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_irq_unmask_fails_and_errors.constprop/261 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_wdt_irq_unmask/150 (pfe_wdt_irq_unmask) @0c8fd1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_irq_unmask_parity_wdt.constprop/262 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_parity_irq_unmask/149 (pfe_parity_irq_unmask) @0c8fd0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_irq_unmask_parity_wdt.constprop/262 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_ecc_err_create/148 (pfe_ecc_err_create) @0c8ea380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_failures.constprop/260 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fail_stop_create/147 (pfe_fail_stop_create) @0c8eaee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_failures.constprop/260 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_host_fail_stop_create/146 (pfe_host_fail_stop_create) @0c8eae00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_failures.constprop/260 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fw_fail_stop_create/145 (pfe_fw_fail_stop_create) @0c8ead20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_failures.constprop/260 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bus_err_create/144 (pfe_bus_err_create) @0c8eac40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_failures.constprop/260 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_wdt_create/143 (pfe_wdt_create) @0c8eaa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_pfe_errors.isra.0.constprop/252 (751619275 (estimated locally),0.70 per call) 
  Calls: 
pfe_parity_create/142 (pfe_parity_create) @0c8ea9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_pfe_errors.isra.0.constprop/252 (1073741821 (estimated locally),1.00 per call) 
  Calls: 
pfe_util_destroy/141 (pfe_util_destroy) @0c8ea7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_util.constprop/266 (574129754 (estimated locally),0.53 per call) pfe_platform_create_err_bmu_class_tmu_emac_util/87 (0 (precise),0.00 per call) 
  Calls: 
pfe_hm_init/140 (pfe_hm_init) @0c8ea540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_hm_fw_features/88 (10737418 (estimated locally),0.33 per call) 
  Calls: 
pfe_feature_mgr_init/139 (pfe_feature_mgr_init) @0c8ea460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_hm_fw_features/88 (21474836 (estimated locally),0.65 per call) 
  Calls: 
oal_mm_dev_map/138 (oal_mm_dev_map) @0c8ea2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_hm_fw_features/88 (33038209 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/137 (autolibc_memset) @0c8ea1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_init_hm_fw_features/88 (33038209 (estimated locally),1.00 per call) 
  Calls: 
oal_time_usleep/136 (oal_time_usleep) @0c8e1ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_soft_reset/85 (66170306 (estimated locally),0.49 per call) 
  Calls: 
pfe_feature_mgr_is_available/135 (pfe_feature_mgr_is_available) @0c8e1e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_tmu.constprop/270 (1073741824 (estimated locally),1.00 per call) pfe_platform_create_util.constprop/267 (1073741823 (estimated locally),1.00 per call) pfe_platform_create_class.isra.0.constprop/253 (354334802 (estimated locally),0.33 per call) pfe_platform_create_pfe_errors.isra.0.constprop/252 (1073741821 (estimated locally),1.00 per call) pfe_platform_create_pfe_errors.isra.0.constprop/252 (354334801 (estimated locally),0.33 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (536870911 (estimated locally),0.50 per call) pfe_platform_init_hm_fw_features/88 (10737418 (estimated locally),0.33 per call) pfe_platform_soft_reset/85 (135372966 (estimated locally),1.00 per call) 
  Calls: 
pfe_if_db_lock/134 (pfe_if_db_lock) @0c8e1c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_log_ifs.constprop/257 (118111600 (estimated locally),1.00 per call) pfe_platform_destroy_pfe_phy_ifs.constprop/256 (118111600 (estimated locally),1.00 per call) pfe_platform_get_phy_if_by_id/75 (1073741824 (estimated locally),1.00 per call) pfe_platform_bind_ifaces/80 (61599606 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_mdio_unlock/133 (pfe_emac_mdio_unlock) @0c8e1a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (6917375 (estimated locally),0.01 per call) 
  Calls: 
pfe_emac_mdio_write45/132 (pfe_emac_mdio_write45) @0c8e19a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) 
  Calls: 
pfe_emac_mdio_read45/131 (pfe_emac_mdio_read45) @0c8e18c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) 
  Calls: 
pfe_emac_mdio_write22/130 (pfe_emac_mdio_write22) @0c8e17e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) 
  Calls: 
pfe_emac_mdio_read22/129 (pfe_emac_mdio_read22) @0c8e1700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) 
  Calls: 
pfe_emac_mdio_lock/128 (pfe_emac_mdio_lock) @0c8e1620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (10324441 (estimated locally),0.01 per call) 
  Calls: 
fci_process_ipc_message/127 (fci_process_ipc_message) @0c8e1540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_emac_get_stat_value/126 (pfe_emac_get_stat_value) @0c8e1460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13834750 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_get_stats/125 (pfe_phy_if_get_stats) @0c8e1380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_is_promisc/124 (pfe_phy_if_is_promisc) @0c8e12a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_is_enabled/123 (pfe_phy_if_is_enabled) @0c8e11c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_get_op_mode/122 (pfe_phy_if_get_op_mode) @0c8e10e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_get_block_state/121 (pfe_phy_if_get_block_state) @0c8e1000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_set_block_state/120 (pfe_phy_if_set_block_state) @0c8dfee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_flush_mac_addrs/119 (pfe_phy_if_flush_mac_addrs) @0c8dfe00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_del_mac_addr/118 (pfe_phy_if_del_mac_addr) @0c8dfd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_add_mac_addr/117 (pfe_phy_if_add_mac_addr) @0c8dfc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
autolibc_memcpy/116 (autolibc_memcpy) @0c8dfb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_allmulti_disable/115 (pfe_phy_if_allmulti_disable) @0c8dfa80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_allmulti_enable/114 (pfe_phy_if_allmulti_enable) @0c8df9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_loadbalance_disable/113 (pfe_phy_if_loadbalance_disable) @0c8df8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_loadbalance_enable/112 (pfe_phy_if_loadbalance_enable) @0c8df7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_loopback_disable/111 (pfe_phy_if_loopback_disable) @0c8df700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_loopback_enable/110 (pfe_phy_if_loopback_enable) @0c8df620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_promisc_disable/109 (pfe_phy_if_promisc_disable) @0c8df540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_promisc_enable/108 (pfe_phy_if_promisc_enable) @0c8df460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_disable/107 (pfe_phy_if_disable) @0c8df380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_phy_if_enable/106 (pfe_phy_if_enable) @0c8df2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) 
  Calls: 
pfe_if_db_unlock/105 (pfe_if_db_unlock) @0c8df1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_log_ifs.constprop/257 (118111601 (estimated locally),1.00 per call) pfe_platform_destroy_pfe_phy_ifs.constprop/256 (118111601 (estimated locally),1.00 per call) pfe_platform_get_phy_if_by_id/75 (1073741824 (estimated locally),1.00 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_bind_ifaces/80 (61599607 (estimated locally),1.00 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/104 (oal_util_raise_dem_for_drv_runtime_err) @0c8df0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_hif.constprop/287 (201326592 (estimated locally),0.19 per call) pfe_platform_create_hif_nocpy.constprop/285 (109629040 (estimated locally),0.10 per call) check_irq_vector.isra.0.constprop/284 (201326592 (estimated locally),0.19 per call) check_irq_vector.isra.0.constprop/284 (305345331 (estimated locally),0.28 per call) pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) pfe_platform_create_etgpi.constprop/280 (201326592 (estimated locally),0.19 per call) pfe_platform_create_etgpi.constprop/280 (163577856 (estimated locally),0.15 per call) pfe_platform_create_etgpi.constprop/280 (72372296 (estimated locally),0.07 per call) pfe_platform_create_hgpi.constprop/278 (109629040 (estimated locally),0.10 per call) pfe_platform_create_class_object.constprop/276 (109629040 (estimated locally),0.10 per call) pfe_platform_create_class_object.constprop/276 (17053072 (estimated locally),0.02 per call) pfe_platform_create_class_object.constprop/276 (6638030 (estimated locally),0.01 per call) pfe_platform_create_class_object.constprop/276 (915389721 (estimated locally),0.85 per call) pfe_platform_create_l2_bridge.constprop/274 (201326592 (estimated locally),0.19 per call) pfe_platform_create_l2_bridge.constprop/274 (89073595 (estimated locally),0.08 per call) pfe_platform_create_l2_bridge.constprop/274 (79979181 (estimated locally),0.07 per call) pfe_platform_create_rtable.constprop/272 (375809639 (estimated locally),0.35 per call) pfe_platform_create_rtable.constprop/272 (130862285 (estimated locally),0.12 per call) pfe_platform_create_rtable.constprop/272 (57897837 (estimated locally),0.05 per call) pfe_platform_create_tmu.constprop/270 (109629040 (estimated locally),0.10 per call) pfe_platform_default_init_util.constprop/268 (201326592 (estimated locally),0.19 per call) pfe_platform_create_util.constprop/267 (109629040 (estimated locally),0.10 per call) pfe_platform_create_util.constprop/267 (257755553 (estimated locally),0.24 per call) pfe_platform_create_util.constprop/267 (85059332 (estimated locally),0.08 per call) pfe_platform_create_emac.constprop/265 (322122547 (estimated locally),0.30 per call) pfe_platform_create_emac.constprop/265 (140928614 (estimated locally),0.13 per call) pfe_platform_create_emac.constprop/265 (57717817 (estimated locally),0.05 per call) pfe_platform_create_failures.constprop/260 (187153200 (estimated locally),0.17 per call) pfe_platform_create_failures.constprop/260 (187153200 (estimated locally),0.17 per call) pfe_platform_create_failures.constprop/260 (187153200 (estimated locally),0.17 per call) pfe_platform_create_failures.constprop/260 (187153200 (estimated locally),0.17 per call) pfe_platform_create_failures.constprop/260 (109629040 (estimated locally),0.10 per call) pfe_platform_create_fci.constprop/258 (354334802 (estimated locally),0.33 per call) pfe_platform_create_gpi.isra.0.constprop/254 (201326592 (estimated locally),0.19 per call) pfe_platform_create_gpi.isra.0.constprop/254 (163577856 (estimated locally),0.15 per call) pfe_platform_create_gpi.isra.0.constprop/254 (72372296 (estimated locally),0.07 per call) pfe_platform_create_class.isra.0.constprop/253 (109629040 (estimated locally),0.10 per call) pfe_platform_create_class.isra.0.constprop/253 (180771147 (estimated locally),0.17 per call) pfe_platform_create_pfe_errors.isra.0.constprop/252 (322122546 (estimated locally),0.30 per call) pfe_platform_create_pfe_errors.isra.0.constprop/252 (131007240 (estimated locally),0.12 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (354334802 (estimated locally),0.33 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (60236916 (estimated locally),0.06 per call) pfe_platform_init_hm_fw_features/88 (10737418 (estimated locally),0.33 per call) pfe_platform_init_hm_fw_features/88 (11563373 (estimated locally),0.35 per call) pfe_platform_create_gpis_add_modules/86 (354334802 (estimated locally),0.33 per call) pfe_platform_remove/95 (116930485 (estimated locally),0.11 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (1124332 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (3407065 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (3407065 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (10324441 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (9062794 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (4565468 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (13834750 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_bind_ifaces/80 (20327870 (estimated locally),0.33 per call) pfe_platform_bind_ifaces/80 (11358183 (estimated locally),0.18 per call) pfe_platform_bind_ifaces/80 (20327870 (estimated locally),0.33 per call) pfe_platform_prepare_phy_if/79 (100709858 (estimated locally),0.09 per call) pfe_platform_prepare_phy_if/79 (40522086 (estimated locally),0.04 per call) pfe_platform_prepare_phy_if/79 (225056286 (estimated locally),0.21 per call) pfe_platform_prepare_phy_if_hif/77 (192036028 (estimated locally),0.18 per call) pfe_platform_prepare_phy_if_hif/77 (157539400 (estimated locally),0.15 per call) pfe_platform_prepare_phy_if_emac/78 (95086281 (estimated locally),0.09 per call) pfe_platform_prepare_phy_if_emac/78 (244276265 (estimated locally),0.23 per call) pfe_platform_prepare_phy_if_emac/78 (375809639 (estimated locally),0.35 per call) pfe_platform_create_default_log_if/76 (198474465 (estimated locally),0.18 per call) pfe_platform_create_default_log_if/76 (305345331 (estimated locally),0.28 per call) pfe_platform_create_default_log_if/76 (201326592 (estimated locally),0.19 per call) 
  Calls: 
pfe_hm_report/103 (pfe_hm_report) @0c8df000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_create_hif.constprop/287 (201326592 (estimated locally),0.19 per call) pfe_platform_create_hif_nocpy.constprop/285 (109629040 (estimated locally),0.10 per call) check_irq_vector.isra.0.constprop/284 (201326592 (estimated locally),0.19 per call) check_irq_vector.isra.0.constprop/284 (305345331 (estimated locally),0.28 per call) pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) pfe_platform_create_etgpi.constprop/280 (201326592 (estimated locally),0.19 per call) pfe_platform_create_etgpi.constprop/280 (163577856 (estimated locally),0.15 per call) pfe_platform_create_etgpi.constprop/280 (72372296 (estimated locally),0.07 per call) pfe_platform_create_hgpi.constprop/278 (109629040 (estimated locally),0.10 per call) pfe_platform_create_class_object.constprop/276 (109629040 (estimated locally),0.10 per call) pfe_platform_create_class_object.constprop/276 (17053072 (estimated locally),0.02 per call) pfe_platform_create_class_object.constprop/276 (6638030 (estimated locally),0.01 per call) pfe_platform_create_class_object.constprop/276 (915389721 (estimated locally),0.85 per call) pfe_platform_create_l2_bridge.constprop/274 (201326592 (estimated locally),0.19 per call) pfe_platform_create_l2_bridge.constprop/274 (89073595 (estimated locally),0.08 per call) pfe_platform_create_l2_bridge.constprop/274 (79979181 (estimated locally),0.07 per call) pfe_platform_create_rtable.constprop/272 (375809639 (estimated locally),0.35 per call) pfe_platform_create_rtable.constprop/272 (130862285 (estimated locally),0.12 per call) pfe_platform_create_rtable.constprop/272 (57897837 (estimated locally),0.05 per call) pfe_platform_create_tmu.constprop/270 (109629040 (estimated locally),0.10 per call) pfe_platform_default_init_util.constprop/268 (201326592 (estimated locally),0.19 per call) pfe_platform_create_util.constprop/267 (109629040 (estimated locally),0.10 per call) pfe_platform_create_util.constprop/267 (257755553 (estimated locally),0.24 per call) pfe_platform_create_util.constprop/267 (85059332 (estimated locally),0.08 per call) pfe_platform_create_emac.constprop/265 (322122547 (estimated locally),0.30 per call) pfe_platform_create_emac.constprop/265 (140928614 (estimated locally),0.13 per call) pfe_platform_create_emac.constprop/265 (57717817 (estimated locally),0.05 per call) pfe_platform_create_failures.constprop/260 (187153200 (estimated locally),0.17 per call) pfe_platform_create_failures.constprop/260 (187153200 (estimated locally),0.17 per call) pfe_platform_create_failures.constprop/260 (187153200 (estimated locally),0.17 per call) pfe_platform_create_failures.constprop/260 (187153200 (estimated locally),0.17 per call) pfe_platform_create_failures.constprop/260 (109629040 (estimated locally),0.10 per call) pfe_platform_create_fci.constprop/258 (354334802 (estimated locally),0.33 per call) pfe_platform_create_gpi.isra.0.constprop/254 (201326592 (estimated locally),0.19 per call) pfe_platform_create_gpi.isra.0.constprop/254 (163577856 (estimated locally),0.15 per call) pfe_platform_create_gpi.isra.0.constprop/254 (72372296 (estimated locally),0.07 per call) pfe_platform_create_class.isra.0.constprop/253 (109629040 (estimated locally),0.10 per call) pfe_platform_create_class.isra.0.constprop/253 (180771147 (estimated locally),0.17 per call) pfe_platform_create_pfe_errors.isra.0.constprop/252 (322122546 (estimated locally),0.30 per call) pfe_platform_create_pfe_errors.isra.0.constprop/252 (131007240 (estimated locally),0.12 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (354334802 (estimated locally),0.33 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (60236916 (estimated locally),0.06 per call) pfe_platform_init_hm_fw_features/88 (10737418 (estimated locally),0.33 per call) pfe_platform_init_hm_fw_features/88 (11563373 (estimated locally),0.35 per call) pfe_platform_create_gpis_add_modules/86 (354334802 (estimated locally),0.33 per call) pfe_platform_remove/95 (116930485 (estimated locally),0.11 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (1124332 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (3407065 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (456547 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (3407065 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (10324441 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (9062794 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (4565468 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (13834750 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (13628262 (estimated locally),0.01 per call) pfe_platform_bind_ifaces/80 (20327870 (estimated locally),0.33 per call) pfe_platform_bind_ifaces/80 (11358183 (estimated locally),0.18 per call) pfe_platform_bind_ifaces/80 (20327870 (estimated locally),0.33 per call) pfe_platform_prepare_phy_if/79 (100709858 (estimated locally),0.09 per call) pfe_platform_prepare_phy_if/79 (40522086 (estimated locally),0.04 per call) pfe_platform_prepare_phy_if/79 (225056286 (estimated locally),0.21 per call) pfe_platform_prepare_phy_if_hif/77 (192036028 (estimated locally),0.18 per call) pfe_platform_prepare_phy_if_hif/77 (157539400 (estimated locally),0.15 per call) pfe_platform_prepare_phy_if_emac/78 (95086281 (estimated locally),0.09 per call) pfe_platform_prepare_phy_if_emac/78 (244276265 (estimated locally),0.23 per call) pfe_platform_prepare_phy_if_emac/78 (375809639 (estimated locally),0.35 per call) pfe_platform_create_default_log_if/76 (198474465 (estimated locally),0.18 per call) pfe_platform_create_default_log_if/76 (305345331 (estimated locally),0.28 per call) pfe_platform_create_default_log_if/76 (201326592 (estimated locally),0.19 per call) 
  Calls: 
pfe_idex_set_rpc_ret_val/102 (pfe_idex_set_rpc_ret_val) @0c8cfee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (3407065 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (1383475 (estimated locally),0.00 per call) pfe_platform_idex_rpc_cbk/39 (10324441 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (27463012 (estimated locally),0.03 per call) pfe_platform_idex_rpc_cbk/39 (13834750 (estimated locally),0.01 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) 
  Calls: 
pfe_if_db_lock_owned/101 (pfe_if_db_lock_owned) @0c8cfe00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_idex_rpc_cbk/39 (41297763 (estimated locally),0.04 per call) 
  Calls: 
pfe_if_db_entry_get_phy_if/100 (pfe_if_db_entry_get_phy_if) @0c8cf8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_phy_ifs.constprop/256 (955630223 (estimated locally),8.09 per call) pfe_platform_get_phy_if_by_id/75 (1073741824 (estimated locally),1.00 per call) pfe_platform_idex_rpc_cbk/39 (123893288 (estimated locally),0.12 per call) 
  Calls: 
pfe_if_db_get_first/99 (pfe_if_db_get_first) @0c8cf620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_platform_destroy_pfe_log_ifs.constprop/257 (118111600 (estimated locally),1.00 per call) pfe_platform_destroy_pfe_phy_ifs.constprop/256 (118111600 (estimated locally),1.00 per call) pfe_platform_get_phy_if_by_id/75 (1073741824 (estimated locally),1.00 per call) pfe_platform_idex_rpc_cbk/39 (353980823 (estimated locally),0.33 per call) pfe_platform_bind_ifaces/80 (1034442875 (estimated locally),16.79 per call) 
  Calls: 
pfe_platform_get_fw_versions/98 (pfe_platform_get_fw_versions) @0c8cf7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_util_get_fw_version/246 (574129754 (estimated locally),0.53 per call) pfe_class_get_fw_version/245 (574129754 (estimated locally),0.53 per call) 
pfe_platform_get_instance/97 (pfe_platform_get_instance) @0c8cf540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe/35 (read)pfe/35 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_remove_sw_if/96 (pfe_platform_remove_sw_if) @0c8cf2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe/35 (write)pfe/35 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_remove/95 (pfe_platform_remove) @0c8cf000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe/35 (read)pfe/35 (write)pfe/35 (read)pfe/35 (read)pfe/35 (write)pfe/35 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (44291850 (estimated locally),0.04 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (134217728 (estimated locally),0.13 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (268435456 (estimated locally),0.25 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (536870911 (estimated locally),0.50 per call) pfe_platform_init_etgpi_l2br_rtable_hifs/89 (22145925 (estimated locally),0.02 per call) pfe_platform_init_etgpi_l2br_rtable_hifs/89 (67108864 (estimated locally),0.06 per call) pfe_platform_init_etgpi_l2br_rtable_hifs/89 (134217728 (estimated locally),0.12 per call) pfe_platform_init_etgpi_l2br_rtable_hifs/89 (268435456 (estimated locally),0.25 per call) pfe_platform_init_etgpi_l2br_rtable_hifs/89 (536870913 (estimated locally),0.50 per call) pfe_platform_init_hm_fw_features/88 (10737418 (estimated locally),0.33 per call) pfe_platform_init_hm_fw_features/88 (11563373 (estimated locally),0.35 per call) pfe_platform_create_gpis_add_modules/86 (88583700 (estimated locally),0.08 per call) pfe_platform_create_gpis_add_modules/86 (268435456 (estimated locally),0.25 per call) pfe_platform_create_gpis_add_modules/86 (536870911 (estimated locally),0.50 per call) pfe_platform_create_err_bmu_class_tmu_emac_util/87 (354334802 (estimated locally),0.33 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/104 (116930485 (estimated locally),0.11 per call) pfe_hm_report/103 (116930485 (estimated locally),0.11 per call) oal_mm_dev_unmap/221 (354334802 (estimated locally),0.33 per call) pfe_feature_mgr_fini/220 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_group2/94 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_group1/93 (1073741824 (estimated locally),1.00 per call) pfe_hm_destroy/219 (1073741824 (estimated locally),1.00 per call) oal_irq_destroy/218 (574129754 (estimated locally),0.53 per call) 
pfe_platform_destroy_group2/94 (pfe_platform_destroy_group2) @0c8c4e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_remove/95 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_platform_destroy_pfe_errors.constprop/259 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_emac.constprop/263 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_tmu.constprop/269 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_util.constprop/266 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_class.constprop/275 (1073741824 (estimated locally),1.00 per call) pfe_mirror_deinit/234 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_destroy_group1/93 (pfe_platform_destroy_group1) @0c8c4b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (write)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_remove/95 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_platform_destroy_l2_bridge.constprop/273 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_rtable.constprop/271 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_bmu.constprop/282 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_hgpi.constprop/277 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_etgpi.constprop/279 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_gpi.constprop/281 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_hif.constprop/286 (1073741824 (estimated locally),1.00 per call) pfe_platform_destroy_ifaces.constprop/255 (1073741824 (estimated locally),1.00 per call) fci_fini/222 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_init/92 (pfe_platform_init) @0c8c48c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_platform_init_mirror_spd_acc_features/91 (354334802 (estimated locally),0.33 per call) pfe_platform_init_hm_fw_features/88 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_init_mirror_spd_acc_features/91 (pfe_platform_init_mirror_spd_acc_features) @0c8c4620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (write)pfe/35 (addr)pfe/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_init/92 (354334802 (estimated locally),0.33 per call) 
  Calls: pfe_emac_pps0_configure/183 (0 (precise),0.00 per call) pfe_platform_enable_ts.constprop/264 (0 (precise),0.00 per call) pfe_util_enable/182 (0 (precise),0.00 per call) pfe_tmu_enable/181 (0 (precise),0.00 per call) pfe_gpi_enable/180 (0 (precise),0.00 per call) pfe_gpi_enable/180 (0 (precise),0.00 per call) pfe_gpi_enable/180 (0 (precise),0.00 per call) pfe_gpi_enable/180 (0 (precise),0.00 per call) pfe_gpi_enable/180 (0 (precise),0.00 per call) pfe_gpi_enable/180 (0 (precise),0.00 per call) pfe_gpi_enable/180 (0 (precise),0.00 per call) pfe_bmu_enable/179 (0 (precise),0.00 per call) pfe_bmu_enable/179 (0 (precise),0.00 per call) pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (354334802 (estimated locally),0.33 per call) pfe_class_enable/178 (354334802 (estimated locally),0.33 per call) pfe_platform_init_etgpi_l2br_rtable_hifs/89 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (pfe_platform_init_tmu_mirror_queue_ifaces_fci) @0c8c4380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (read)pfe/35 (read)pfe/35 (write)pfe/35 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (354334802 (estimated locally),0.33 per call) 
  Calls: pfe_platform_remove/95 (44291850 (estimated locally),0.04 per call) pfe_platform_create_fci.constprop/258 (134217728 (estimated locally),0.13 per call) pfe_platform_remove/95 (134217728 (estimated locally),0.13 per call) pfe_platform_create_ifaces/81 (268435456 (estimated locally),0.25 per call) pfe_platform_remove/95 (268435456 (estimated locally),0.25 per call) pfe_mirror_init/197 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/104 (354334802 (estimated locally),0.33 per call) pfe_hm_report/103 (354334802 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/104 (60236916 (estimated locally),0.06 per call) pfe_hm_report/103 (60236916 (estimated locally),0.06 per call) pfe_feature_mgr_get_val/195 (182536110 (estimated locally),0.17 per call) pfe_feature_mgr_is_available/135 (536870911 (estimated locally),0.50 per call) pfe_platform_remove/95 (536870911 (estimated locally),0.50 per call) pfe_tmu_queue_reset_tail_drop_policy/194 (1073741823 (estimated locally),1.00 per call) 
pfe_platform_init_etgpi_l2br_rtable_hifs/89 (pfe_platform_init_etgpi_l2br_rtable_hifs) @0c8a40e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_init_mirror_spd_acc_features/91 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_platform_remove/95 (22145925 (estimated locally),0.02 per call) pfe_platform_create_hif_nocpy.constprop/285 (67108864 (estimated locally),0.06 per call) pfe_platform_remove/95 (67108864 (estimated locally),0.06 per call) pfe_platform_create_hif.constprop/287 (134217728 (estimated locally),0.12 per call) pfe_platform_remove/95 (134217728 (estimated locally),0.12 per call) pfe_platform_create_rtable.constprop/272 (268435456 (estimated locally),0.25 per call) pfe_platform_remove/95 (268435456 (estimated locally),0.25 per call) pfe_platform_create_l2_bridge.constprop/274 (536870913 (estimated locally),0.50 per call) pfe_platform_remove/95 (536870913 (estimated locally),0.50 per call) pfe_platform_create_etgpi.constprop/280 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_init_hm_fw_features/88 (pfe_platform_init_hm_fw_features) @0c8a4d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (addr)pfe/35 (write)pfe/35 (write)pfe/35 (write)pfe/35 (write)pfe/35 (read)pfe/35 (read)pfe/35 (write)pfe/35 (write)pfe/35 (write)pfe/35 (write)pfe/35 (write)pfe/35 (write)pfe/35 (write)pfe/35 (write)pfe/35 (read)pfe/35 (write)
  Referring: 
  Availability: local
  Function flags: count:33038209 (estimated locally) body local optimize_size
  Called by: pfe_platform_init/92 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_platform_create_gpis_add_modules/86 (3543348 (estimated locally),0.11 per call) pfe_platform_create_err_bmu_class_tmu_emac_util/87 (10737418 (estimated locally),0.33 per call) pfe_hm_init/140 (10737418 (estimated locally),0.33 per call) pfe_feature_mgr_is_available/135 (10737418 (estimated locally),0.33 per call) pfe_platform_remove/95 (10737418 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/104 (10737418 (estimated locally),0.33 per call) pfe_hm_report/103 (10737418 (estimated locally),0.33 per call) pfe_feature_mgr_init/139 (21474836 (estimated locally),0.65 per call) pfe_platform_remove/95 (11563373 (estimated locally),0.35 per call) oal_util_raise_dem_for_drv_runtime_err/104 (11563373 (estimated locally),0.35 per call) pfe_hm_report/103 (11563373 (estimated locally),0.35 per call) oal_mm_dev_map/138 (33038209 (estimated locally),1.00 per call) autolibc_memset/137 (33038209 (estimated locally),1.00 per call) 
pfe_platform_create_err_bmu_class_tmu_emac_util/87 (pfe_platform_create_err_bmu_class_tmu_emac_util) @0c8a48c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (addr)pfe/35 (read)pfe/35 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_init_hm_fw_features/88 (10737418 (estimated locally),0.33 per call) 
  Calls: pfe_platform_remove/95 (354334802 (estimated locally),0.33 per call) pfe_util_destroy/141 (0 (precise),0.00 per call) pfe_platform_default_init_util.constprop/268 (0 (precise),0.00 per call) pfe_platform_create_util.constprop/267 (0 (precise),0.00 per call) pfe_platform_create_emac.constprop/265 (0 (precise),0.00 per call) pfe_platform_create_tmu.constprop/270 (0 (precise),0.00 per call) pfe_platform_create_class.isra.0.constprop/253 (0 (precise),0.00 per call) pfe_platform_create_bmu.constprop/283 (0 (precise),0.00 per call) pfe_platform_create_pfe_errors.isra.0.constprop/252 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_create_gpis_add_modules/86 (pfe_platform_create_gpis_add_modules) @0c8a4620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (addr)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (addr)pfe/35 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_platform_init_hm_fw_features/88 (3543348 (estimated locally),0.11 per call) 
  Calls: pfe_platform_remove/95 (88583700 (estimated locally),0.08 per call) pfe_platform_create_hgpi.constprop/278 (268435456 (estimated locally),0.25 per call) pfe_platform_remove/95 (268435456 (estimated locally),0.25 per call) pfe_platform_create_gpi.isra.0.constprop/254 (536870911 (estimated locally),0.50 per call) pfe_platform_remove/95 (536870911 (estimated locally),0.50 per call) pfe_feature_mgr_add_modules/176 (1073741823 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (354334802 (estimated locally),0.33 per call) pfe_hm_report/103 (354334802 (estimated locally),0.33 per call) pfe_platform_soft_reset/85 (1073741823 (estimated locally),1.00 per call) pfe_hif_cfg_stop_all_chnl_dma/175 (1073741823 (estimated locally),1.00 per call) 
pfe_platform_soft_reset/85 (pfe_platform_soft_reset) @0c8a42a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe/35 (read)
  Referring: 
  Availability: available
  Function flags: count:135372966 (estimated locally) body optimize_size
  Called by: pfe_platform_create_gpis_add_modules/86 (1073741823 (estimated locally),1.00 per call) 
  Calls: oal_time_usleep/136 (66170306 (estimated locally),0.49 per call) pfe_feature_mgr_is_available/135 (135372966 (estimated locally),1.00 per call) 
pfe_platform_destroy_ifaces/84 (pfe_platform_destroy_ifaces) @0c8a4000
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_pfe_phy_ifs/83 (pfe_platform_destroy_pfe_phy_ifs) @0c893ee0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_pfe_log_ifs/82 (pfe_platform_destroy_pfe_log_ifs) @0c893c40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_ifaces/81 (pfe_platform_create_ifaces) @0c8939a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (read)pfe/35 (write)pfe/35 (read)pfe/35 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (268435456 (estimated locally),0.25 per call) 
  Calls: pfe_platform_bind_ifaces/80 (120344923 (estimated locally),0.11 per call) pfe_if_db_create/198 (176743902 (estimated locally),0.16 per call) pfe_log_ifs_init/199 (127432614 (estimated locally),0.12 per call) pfe_if_db_create/198 (187153200 (estimated locally),0.17 per call) 
pfe_platform_bind_ifaces/80 (pfe_platform_bind_ifaces) @0c893700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)pfe/35 (read)
  Referring: 
  Availability: local
  Function flags: count:61599606 (estimated locally) body local optimize_size
  Called by: pfe_platform_create_ifaces/81 (120344923 (estimated locally),0.11 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/104 (20327870 (estimated locally),0.33 per call) pfe_hm_report/103 (20327870 (estimated locally),0.33 per call) pfe_if_db_unlock/105 (61599607 (estimated locally),1.00 per call) pfe_phy_if_destroy/203 (10942473 (estimated locally),0.18 per call) pfe_platform_prepare_phy_if/79 (298974679 (estimated locally),4.85 per call) oal_util_raise_dem_for_drv_runtime_err/104 (11358183 (estimated locally),0.18 per call) pfe_hm_report/103 (11358183 (estimated locally),0.18 per call) pfe_phy_if_create/202 (310332862 (estimated locally),5.04 per call) pfe_if_db_get_first/99 (1034442875 (estimated locally),16.79 per call) oal_util_raise_dem_for_drv_runtime_err/104 (20327870 (estimated locally),0.33 per call) pfe_hm_report/103 (20327870 (estimated locally),0.33 per call) pfe_if_db_lock/134 (61599606 (estimated locally),1.00 per call) pfe_hif_nocpy_get_channel/201 (61599606 (estimated locally),1.00 per call) pfe_hif_get_channel/200 (61599606 (estimated locally),1.00 per call) pfe_hif_get_channel/200 (61599606 (estimated locally),1.00 per call) pfe_hif_get_channel/200 (61599606 (estimated locally),1.00 per call) pfe_hif_get_channel/200 (61599606 (estimated locally),1.00 per call) 
pfe_platform_prepare_phy_if/79 (pfe_platform_prepare_phy_if) @0c8930e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_bind_ifaces/80 (298974679 (estimated locally),4.85 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/104 (100709858 (estimated locally),0.09 per call) pfe_hm_report/103 (100709858 (estimated locally),0.09 per call) pfe_phy_if_get_name/207 (100709858 (estimated locally),0.09 per call) pfe_platform_register_phy_if/74 (480485965 (estimated locally),0.45 per call) pfe_platform_prepare_phy_if_hif/77 (375288744 (estimated locally),0.35 per call) oal_util_raise_dem_for_drv_runtime_err/104 (40522086 (estimated locally),0.04 per call) pfe_hm_report/103 (40522086 (estimated locally),0.04 per call) pfe_phy_if_bind_util/206 (193330565 (estimated locally),0.18 per call) pfe_platform_prepare_phy_if_emac/78 (280066228 (estimated locally),0.26 per call) pfe_phy_if_get_id/205 (848685538 (estimated locally),0.79 per call) oal_util_raise_dem_for_drv_runtime_err/104 (225056286 (estimated locally),0.21 per call) pfe_hm_report/103 (225056286 (estimated locally),0.21 per call) pfe_phy_if_set_op_mode/204 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_prepare_phy_if_emac/78 (pfe_platform_prepare_phy_if_emac) @0c88f8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_prepare_phy_if/79 (280066228 (estimated locally),0.26 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/104 (95086281 (estimated locally),0.09 per call) pfe_hm_report/103 (95086281 (estimated locally),0.09 per call) pfe_platform_create_default_log_if/76 (453655921 (estimated locally),0.42 per call) oal_util_raise_dem_for_drv_runtime_err/104 (244276265 (estimated locally),0.23 per call) pfe_hm_report/103 (244276265 (estimated locally),0.23 per call) pfe_emac_bind_gpi/209 (697932186 (estimated locally),0.65 per call) oal_util_raise_dem_for_drv_runtime_err/104 (375809639 (estimated locally),0.35 per call) pfe_hm_report/103 (375809639 (estimated locally),0.35 per call) pfe_phy_if_bind_emac/208 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_prepare_phy_if_hif/77 (pfe_platform_prepare_phy_if_hif) @0c88f0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_platform_prepare_phy_if/79 (375288744 (estimated locally),0.35 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/104 (192036028 (estimated locally),0.18 per call) pfe_hm_report/103 (192036028 (estimated locally),0.18 per call) pfe_platform_create_default_log_if/76 (916202423 (estimated locally),0.85 per call) oal_util_raise_dem_for_drv_runtime_err/104 (157539400 (estimated locally),0.15 per call) pfe_hm_report/103 (157539400 (estimated locally),0.15 per call) pfe_phy_if_bind_hif/215 (751619277 (estimated locally),0.70 per call) 
pfe_platform_create_default_log_if/76 (pfe_platform_create_default_log_if) @0c889b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_platform_prepare_phy_if_hif/77 (916202423 (estimated locally),0.85 per call) pfe_platform_prepare_phy_if_emac/78 (453655921 (estimated locally),0.42 per call) 
  Calls: pfe_log_if_enable/214 (368595435 (estimated locally),0.34 per call) pfe_log_if_destroy/212 (198474465 (estimated locally),0.18 per call) oal_util_raise_dem_for_drv_runtime_err/104 (198474465 (estimated locally),0.18 per call) pfe_hm_report/103 (198474465 (estimated locally),0.18 per call) pfe_log_if_promisc_enable/213 (567069901 (estimated locally),0.53 per call) pfe_log_if_destroy/212 (305345331 (estimated locally),0.28 per call) oal_util_raise_dem_for_drv_runtime_err/104 (305345331 (estimated locally),0.28 per call) pfe_hm_report/103 (305345331 (estimated locally),0.28 per call) pfe_if_db_add/211 (872415231 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/104 (201326592 (estimated locally),0.19 per call) pfe_hm_report/103 (201326592 (estimated locally),0.19 per call) pfe_log_if_create/210 (1073741823 (estimated locally),1.00 per call) 
pfe_platform_get_phy_if_by_id/75 (pfe_platform_get_phy_if_by_id) @0c889620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_if_db_entry_get_phy_if/100 (1073741824 (estimated locally),1.00 per call) pfe_if_db_unlock/105 (1073741824 (estimated locally),1.00 per call) pfe_if_db_get_first/99 (1073741824 (estimated locally),1.00 per call) pfe_if_db_lock/134 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_register_phy_if/74 (pfe_platform_register_phy_if) @0c889380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_platform_prepare_phy_if/79 (480485965 (estimated locally),0.45 per call) 
  Calls: pfe_if_db_add/211 (1073741824 (estimated locally),1.00 per call) 
pfe_platform_create_fci/72 (pfe_platform_create_fci) @0c87ee00
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_pfe_errors/71 (pfe_platform_destroy_pfe_errors) @0c87ea80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_failures/69 (pfe_platform_create_failures) @0c87e380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_irq_unmask_fails_and_errors/68 (pfe_platform_irq_unmask_fails_and_errors) @07993c40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_irq_unmask_parity_wdt/67 (pfe_platform_irq_unmask_parity_wdt) @079939a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_emac/66 (pfe_platform_destroy_emac) @07993700
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:268435456 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_enable_ts/65 (pfe_platform_enable_ts) @07993460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_create_emac/64 (pfe_platform_create_emac) @079931c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_util/63 (pfe_platform_destroy_util) @0798cc40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_util/62 (pfe_platform_create_util) @0798c9a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_default_init_util/61 (pfe_platform_default_init_util) @0798c460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_tmu/60 (pfe_platform_destroy_tmu) @0798c0e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_tmu/59 (pfe_platform_create_tmu) @0c80de00
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_rtable/58 (pfe_platform_destroy_rtable) @0c80da80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_rtable/57 (pfe_platform_create_rtable) @0c80d7e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_l2_bridge/56 (pfe_platform_destroy_l2_bridge) @0c80d2a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_l2_bridge/55 (pfe_platform_create_l2_bridge) @0c80d000
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_class/54 (pfe_platform_destroy_class) @0c803a80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_class_object/52 (pfe_platform_create_class_object) @0c803380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_hgpi/51 (pfe_platform_destroy_hgpi) @0c7fbd20
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:536870913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_hgpi/50 (pfe_platform_create_hgpi) @0c7fba80
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_etgpi/49 (pfe_platform_destroy_etgpi) @0c7fb700
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:268435456 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_etgpi/48 (pfe_platform_create_etgpi) @0c7fb460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_gpi/47 (pfe_platform_destroy_gpi) @0c7eeee0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:268435456 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_bmu/45 (pfe_platform_destroy_bmu) @0c7ee700
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:357878150 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_bmu/44 (pfe_platform_create_bmu) @0c7ee460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:0 (precise) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_platform_create_hif_nocpy/42 (pfe_platform_create_hif_nocpy) @0c7e4b60
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_destroy_hif/41 (pfe_platform_destroy_hif) @0c7e47e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_create_hif/40 (pfe_platform_create_hif) @0c7e4540
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_platform_idex_rpc_cbk/39 (pfe_platform_idex_rpc_cbk) @0c7e41c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe/35 (read)pfe/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1072669162 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) oal_util_raise_dem_for_drv_runtime_err/104 (1124332 (estimated locally),0.00 per call) pfe_hm_report/103 (1124332 (estimated locally),0.00 per call) pfe_idex_set_rpc_ret_val/102 (3407065 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (3407065 (estimated locally),0.00 per call) pfe_hm_report/103 (3407065 (estimated locally),0.00 per call) pfe_emac_mdio_unlock/133 (6917375 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (456547 (estimated locally),0.00 per call) pfe_hm_report/103 (456547 (estimated locally),0.00 per call) pfe_idex_set_rpc_ret_val/102 (1383475 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (1383475 (estimated locally),0.00 per call) pfe_hm_report/103 (1383475 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (456547 (estimated locally),0.00 per call) pfe_hm_report/103 (456547 (estimated locally),0.00 per call) pfe_idex_set_rpc_ret_val/102 (1383475 (estimated locally),0.00 per call) pfe_emac_mdio_write45/132 (1383475 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (456547 (estimated locally),0.00 per call) pfe_hm_report/103 (456547 (estimated locally),0.00 per call) pfe_idex_set_rpc_ret_val/102 (1383475 (estimated locally),0.00 per call) pfe_emac_mdio_read45/131 (1383475 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (456547 (estimated locally),0.00 per call) pfe_hm_report/103 (456547 (estimated locally),0.00 per call) pfe_idex_set_rpc_ret_val/102 (1383475 (estimated locally),0.00 per call) pfe_emac_mdio_write22/130 (1383475 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/104 (456547 (estimated locally),0.00 per call) pfe_hm_report/103 (456547 (estimated locally),0.00 per call) pfe_idex_set_rpc_ret_val/102 (1383475 (estimated locally),0.00 per call) pfe_emac_mdio_read22/129 (1383475 (estimated locally),0.00 per call) pfe_emac_mdio_lock/128 (10324441 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (3407065 (estimated locally),0.00 per call) pfe_hm_report/103 (3407065 (estimated locally),0.00 per call) pfe_idex_set_rpc_ret_val/102 (10324441 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (10324441 (estimated locally),0.01 per call) pfe_hm_report/103 (10324441 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) fci_process_ipc_message/127 (13628262 (estimated locally),0.01 per call) autolibc_memcpy/116 (13628262 (estimated locally),0.01 per call) autolibc_memcpy/116 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (9062794 (estimated locally),0.01 per call) pfe_hm_report/103 (9062794 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (27463012 (estimated locally),0.03 per call) pfe_emac_get_stat_value/126 (13834750 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (4565468 (estimated locally),0.00 per call) pfe_hm_report/103 (4565468 (estimated locally),0.00 per call) pfe_idex_set_rpc_ret_val/102 (13834750 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13834750 (estimated locally),0.01 per call) pfe_hm_report/103 (13834750 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_get_stats/125 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_is_promisc/124 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_is_enabled/123 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_get_op_mode/122 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_get_block_state/121 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_set_block_state/120 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_flush_mac_addrs/119 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_del_mac_addr/118 (13628262 (estimated locally),0.01 per call) autolibc_memcpy/116 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_add_mac_addr/117 (13628262 (estimated locally),0.01 per call) autolibc_memcpy/116 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_allmulti_disable/115 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_allmulti_enable/114 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_loadbalance_disable/113 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_loadbalance_enable/112 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_loopback_disable/111 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_loopback_enable/110 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_promisc_disable/109 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_promisc_enable/108 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_disable/107 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_phy_if_enable/106 (13628262 (estimated locally),0.01 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_if_db_unlock/105 (41297763 (estimated locally),0.04 per call) oal_util_raise_dem_for_drv_runtime_err/104 (13628262 (estimated locally),0.01 per call) pfe_hm_report/103 (13628262 (estimated locally),0.01 per call) pfe_idex_set_rpc_ret_val/102 (41297763 (estimated locally),0.04 per call) pfe_if_db_lock_owned/101 (41297763 (estimated locally),0.04 per call) pfe_if_db_entry_get_phy_if/100 (123893288 (estimated locally),0.12 per call) pfe_if_db_get_first/99 (353980823 (estimated locally),0.33 per call) 
pfe_platform_bmu_isr/38 (pfe_platform_bmu_isr) @0792dd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: check_irq_vector.isra.0.constprop.0/284 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_platform_bmu_isr.part.0/249 (0 (precise),0.00 per call) pfe_bmu_irq_mask/161 (1073741824 (estimated locally),1.00 per call) pfe_bmu_irq_mask/161 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_buffers/37 (pfe_rtable_buffers) @07834ea0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_platform_create_rtable.constprop.0/272 (addr)pfe_platform_create_rtable.constprop.0/272 (addr)
  Availability: available
  Varpool flags:
bDetectBmuInit/36 (bDetectBmuInit) @07834dc8
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: check_irq_vector.isra.0.constprop.0/284 (write)pfe_platform_destroy_bmu.constprop.0/282 (write)
  Availability: available
  Varpool flags: initialized
pfe/35 (pfe) @07834d80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_platform_destroy_group1/93 (addr)pfe_platform_destroy_group1/93 (addr)pfe_platform_destroy_group2/94 (addr)pfe_platform_destroy_group2/94 (addr)pfe_platform_destroy_group1/93 (addr)pfe_platform_destroy_group1/93 (addr)pfe_platform_destroy_group1/93 (addr)pfe_platform_idex_rpc_cbk/39 (read)pfe_platform_idex_rpc_cbk/39 (read)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_bind_ifaces/80 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_init_hm_fw_features/88 (read)pfe_platform_init_hm_fw_features/88 (read)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_remove_sw_if/96 (write)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_bind_ifaces/80 (read)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (addr)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (addr)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (addr)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (addr)pfe_platform_remove/95 (write)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_destroy_group1/93 (write)pfe_platform_destroy_group1/93 (addr)pfe_platform_destroy_group1/93 (addr)pfe_platform_destroy_group1/93 (addr)pfe_platform_destroy_group2/94 (addr)pfe_platform_destroy_group2/94 (addr)pfe_platform_destroy_group2/94 (addr)pfe_platform_soft_reset/85 (read)pfe_platform_remove/95 (read)pfe_platform_remove/95 (write)pfe_platform_remove/95 (read)pfe_platform_remove/95 (read)pfe_platform_remove/95 (write)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_bind_ifaces/80 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_destroy_hif.constprop.0/286 (addr)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (write)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (addr)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (addr)pfe_platform_create_err_bmu_class_tmu_emac_util/87 (addr)pfe_platform_create_gpis_add_modules/86 (addr)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_init_etgpi_l2br_rtable_hifs/89 (addr)pfe_platform_init_etgpi_l2br_rtable_hifs/89 (addr)pfe_platform_init_etgpi_l2br_rtable_hifs/89 (addr)pfe_platform_init_etgpi_l2br_rtable_hifs/89 (addr)pfe_platform_create_gpis_add_modules/86 (read)pfe_platform_create_gpis_add_modules/86 (read)pfe_platform_create_gpis_add_modules/86 (read)pfe_platform_create_gpis_add_modules/86 (addr)pfe_platform_create_gpis_add_modules/86 (addr)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_init_hm_fw_features/88 (read)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_init_hm_fw_features/88 (write)pfe_platform_init_etgpi_l2br_rtable_hifs/89 (addr)pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (read)pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (read)pfe_platform_remove_sw_if/96 (write)pfe_platform_create_default_log_if/76 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_create_ifaces/81 (write)pfe_platform_bind_ifaces/80 (read)pfe_platform_bind_ifaces/80 (read)pfe_platform_create_ifaces/81 (read)pfe_platform_create_ifaces/81 (write)pfe_platform_create_ifaces/81 (read)pfe_platform_create_hif.constprop.0/287 (addr)pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (write)pfe_platform_init_tmu_mirror_queue_ifaces_fci/90 (addr)pfe_platform_init_mirror_spd_acc_features/91 (addr)pfe_platform_register_phy_if/74 (read)pfe_platform_init_hm_fw_features/88 (addr)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (read)pfe_platform_init_mirror_spd_acc_features/91 (write)pfe_platform_get_instance/97 (read)pfe_platform_get_instance/97 (addr)pfe_platform_create_pfe_errors.isra.0.constprop.0/252 (addr)pfe_platform_create_class.isra.0.constprop.0/253 (addr)pfe_platform_create_gpi.isra.0.constprop.0/254 (addr)pfe_platform_destroy_ifaces.constprop.0/255 (addr)pfe_platform_destroy_pfe_phy_ifs.constprop.0/256 (addr)pfe_platform_destroy_pfe_log_ifs.constprop.0/257 (addr)pfe_platform_create_fci.constprop.0/258 (addr)pfe_platform_destroy_pfe_errors.constprop.0/259 (addr)pfe_platform_create_failures.constprop.0/260 (addr)pfe_platform_irq_unmask_fails_and_errors.constprop.0/261 (addr)pfe_platform_irq_unmask_parity_wdt.constprop.0/262 (addr)pfe_platform_destroy_emac.constprop.0/263 (addr)pfe_platform_enable_ts.constprop.0/264 (addr)pfe_platform_create_emac.constprop.0/265 (addr)pfe_platform_destroy_util.constprop.0/266 (addr)pfe_platform_create_util.constprop.0/267 (addr)pfe_platform_default_init_util.constprop.0/268 (addr)pfe_platform_destroy_tmu.constprop.0/269 (addr)pfe_platform_create_tmu.constprop.0/270 (addr)pfe_platform_destroy_rtable.constprop.0/271 (addr)pfe_platform_create_rtable.constprop.0/272 (addr)pfe_platform_destroy_l2_bridge.constprop.0/273 (addr)pfe_platform_create_l2_bridge.constprop.0/274 (addr)pfe_platform_destroy_class.constprop.0/275 (addr)pfe_platform_create_class_object.constprop.0/276 (addr)pfe_platform_destroy_hgpi.constprop.0/277 (addr)pfe_platform_create_hgpi.constprop.0/278 (addr)pfe_platform_destroy_etgpi.constprop.0/279 (addr)pfe_platform_create_etgpi.constprop.0/280 (addr)pfe_platform_destroy_gpi.constprop.0/281 (addr)pfe_platform_destroy_bmu.constprop.0/282 (read)pfe_platform_destroy_bmu.constprop.0/282 (addr)pfe_platform_create_bmu.constprop.0/283 (addr)check_irq_vector.isra.0.constprop.0/284 (addr)pfe_platform_create_hif_nocpy.constprop.0/285 (read)pfe_platform_create_hif_nocpy.constprop.0/285 (addr)
  Availability: available
  Varpool flags: initialized
pfe_bmu_buffers/34 (pfe_bmu_buffers) @07834cf0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: pfe_platform_create_bmu.constprop.0/283 (addr)pfe_platform_create_bmu.constprop.0/283 (addr)pfe_platform_create_bmu.constprop.0/283 (addr)
  Availability: available
  Varpool flags:

;; Function pfe_platform_create_default_log_if (pfe_platform_create_default_log_if, funcdef_no=69, decl_uid=13224, cgraph_uid=70, symbol_order=76)

Modification phase of node pfe_platform_create_default_log_if/76
pfe_platform_create_default_log_if (struct pfe_phy_if_t * phy_if, const char * if_name, uint32_t session_id)
{
  errno_t ret;
  struct pfe_log_if_t * log_if;
  struct pfe_if_db_t * _1;
  int _2;
  int _3;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  log_if_10 = pfe_log_if_create (phy_if_7(D), if_name_8(D));
  # DEBUG log_if => log_if_10
  # DEBUG BEGIN_STMT
  # DEBUG ret => 19
  # DEBUG BEGIN_STMT
  if (log_if_10 == 0B)
    goto <bb 3>; [18.75%]
  else
    goto <bb 4>; [81.25%]

  <bb 3> [local count: 201326592]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create LOG_IF for %s\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2192, if_name_8(D), "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 4> [local count: 872415231]:
  # DEBUG BEGIN_STMT
  _1 = pfe.log_if_db;
  _2 = pfe_if_db_add (_1, session_id_11(D), log_if_10, 6);
  if (_2 != 0)
    goto <bb 5>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 5> [local count: 305345331]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not register LOG_IF %s\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2197, if_name_8(D), "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_log_if_destroy (log_if_10);
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 567069901]:
  # DEBUG BEGIN_STMT
  _3 = pfe_log_if_promisc_enable (log_if_10);
  if (_3 != 0)
    goto <bb 7>; [35.00%]
  else
    goto <bb 8>; [65.00%]

  <bb 7> [local count: 198474465]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not configure LOG_IF %s\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2202, if_name_8(D), "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_log_if_destroy (log_if_10);
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 368595435]:
  # DEBUG BEGIN_STMT
  ret_15 = pfe_log_if_enable (log_if_10);
  # DEBUG ret => ret_15

  <bb 9> [local count: 1073741824]:
  # ret_4 = PHI <19(3), 19(5), 19(7), ret_15(8)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_platform_bind_ifaces (pfe_platform_bind_ifaces, funcdef_no=73, decl_uid=13248, cgraph_uid=74, symbol_order=80)

Modification phase of node pfe_platform_bind_ifaces/80
pfe_platform_bind_ifaces ()
{
  const struct pfe_platform_pfy_if phy_ifs[10];
  struct pfe_hif_chnl_t * channel_hifncpy;
  struct pfe_hif_chnl_t * channel_hif3;
  struct pfe_hif_chnl_t * channel_hif2;
  struct pfe_hif_chnl_t * channel_hif1;
  struct pfe_hif_chnl_t * channel_hif0;
  struct pfe_if_db_entry_t * entry;
  uint32_t session_id;
  struct pfe_phy_if_t * phy_if;
  int32_t ii;
  errno_t ret;
  struct pfe_hif_t * _1;
  struct pfe_hif_t * _2;
  struct pfe_hif_t * _3;
  struct pfe_hif_t * _4;
  struct pfe_hif_nocpy_t * _5;
  struct pfe_emac_t * _6;
  struct pfe_gpi_t * _7;
  struct pfe_emac_t * _8;
  struct pfe_gpi_t * _9;
  struct pfe_emac_t * _10;
  struct pfe_gpi_t * _11;
  int _12;
  struct pfe_if_db_t * _13;
  long unsigned int session_id.24_14;
  unsigned int _16;
  void * _17;
  struct pfe_if_db_entry_t * entry.25_18;
  struct pfe_class_t * _19;
  <unnamed type> _20;
  const char_t * _21;
  const char_t * _22;
  const struct pfe_platform_pfy_if * _23;
  long unsigned int session_id.26_24;
  <unnamed type> _25;
  long unsigned int session_id.27_26;
  int _27;

  <bb 2> [local count: 61599606]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG phy_if => 0B
  # DEBUG BEGIN_STMT
  session_id = 0;
  # DEBUG BEGIN_STMT
  entry = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG channel_hif0 => 0B
  # DEBUG BEGIN_STMT
  # DEBUG channel_hif1 => 0B
  # DEBUG BEGIN_STMT
  # DEBUG channel_hif2 => 0B
  # DEBUG BEGIN_STMT
  # DEBUG channel_hif3 => 0B
  # DEBUG BEGIN_STMT
  # DEBUG channel_hifncpy => 0B
  # DEBUG BEGIN_STMT
  _1 = pfe.hif;
  channel_hif0_45 = pfe_hif_get_channel (_1, 1);
  # DEBUG channel_hif0 => channel_hif0_45
  # DEBUG BEGIN_STMT
  _2 = pfe.hif;
  channel_hif1_47 = pfe_hif_get_channel (_2, 2);
  # DEBUG channel_hif1 => channel_hif1_47
  # DEBUG BEGIN_STMT
  _3 = pfe.hif;
  channel_hif2_49 = pfe_hif_get_channel (_3, 4);
  # DEBUG channel_hif2 => channel_hif2_49
  # DEBUG BEGIN_STMT
  _4 = pfe.hif;
  channel_hif3_51 = pfe_hif_get_channel (_4, 8);
  # DEBUG channel_hif3 => channel_hif3_51
  # DEBUG BEGIN_STMT
  _5 = pfe.hif_nocpy;
  channel_hifncpy_53 = pfe_hif_nocpy_get_channel (_5, 1000);
  # DEBUG channel_hifncpy => channel_hifncpy_53
  # DEBUG BEGIN_STMT
  phy_ifs[0].name = "emac0";
  phy_ifs[0].id = 0;
  phy_ifs[0].mac = "\x00\n\v\f\r\x0e";
  _6 = pfe.emac[0];
  phy_ifs[0].phy.emac = _6;
  _7 = pfe.gpi[0];
  phy_ifs[0].phy.gpi = _7;
  phy_ifs[0].phy.chnl = 0B;
  phy_ifs[1].name = "emac1";
  phy_ifs[1].id = 1;
  phy_ifs[1].mac = "\x00\x1a\x1b\x1c\x1d\x1e";
  _8 = pfe.emac[1];
  phy_ifs[1].phy.emac = _8;
  _9 = pfe.gpi[1];
  phy_ifs[1].phy.gpi = _9;
  phy_ifs[1].phy.chnl = 0B;
  phy_ifs[2].name = "emac2";
  phy_ifs[2].id = 2;
  phy_ifs[2].mac = "\x00*+,-.";
  _10 = pfe.emac[2];
  phy_ifs[2].phy.emac = _10;
  _11 = pfe.gpi[2];
  phy_ifs[2].phy.gpi = _11;
  phy_ifs[2].phy.chnl = 0B;
  phy_ifs[3].name = "util";
  phy_ifs[3].id = 5;
  phy_ifs[3].mac = "\x00";
  phy_ifs[3].phy.emac = 0B;
  phy_ifs[3].phy.gpi = 0B;
  phy_ifs[3].phy.chnl = 0B;
  phy_ifs[4].name = "hif0";
  phy_ifs[4].id = 6;
  phy_ifs[4].mac = "\x00";
  phy_ifs[4].phy.emac = 0B;
  phy_ifs[4].phy.gpi = 0B;
  phy_ifs[4].phy.chnl = channel_hif0_45;
  phy_ifs[5].name = "hif1";
  phy_ifs[5].id = 7;
  phy_ifs[5].mac = "\x00";
  phy_ifs[5].phy.emac = 0B;
  phy_ifs[5].phy.gpi = 0B;
  phy_ifs[5].phy.chnl = channel_hif1_47;
  phy_ifs[6].name = "hif2";
  phy_ifs[6].id = 8;
  phy_ifs[6].mac = "\x00";
  phy_ifs[6].phy.emac = 0B;
  phy_ifs[6].phy.gpi = 0B;
  phy_ifs[6].phy.chnl = channel_hif2_49;
  phy_ifs[7].name = "hif3";
  phy_ifs[7].id = 9;
  phy_ifs[7].mac = "\x00";
  phy_ifs[7].phy.emac = 0B;
  phy_ifs[7].phy.gpi = 0B;
  phy_ifs[7].phy.chnl = channel_hif3_51;
  phy_ifs[8].name = "hifncpy";
  phy_ifs[8].id = 4;
  phy_ifs[8].mac = "\x00";
  phy_ifs[8].phy.emac = 0B;
  phy_ifs[8].phy.gpi = 0B;
  phy_ifs[8].phy.chnl = channel_hifncpy_53;
  phy_ifs[9].name = 0B;
  phy_ifs[9].id = 10;
  phy_ifs[9].mac = "\x00";
  phy_ifs[9].phy.emac = 0B;
  phy_ifs[9].phy.gpi = 0B;
  phy_ifs[9].phy.chnl = 0B;
  # DEBUG BEGIN_STMT
  _12 = pfe_if_db_lock (&session_id);
  if (_12 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 3> [local count: 20327870]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] DB lock failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2361, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 12> [local count: 61599606]:
  # ret_32 = PHI <0(3), 0(2)>
  # ii_42 = PHI <0(3), 0(2)>
  goto <bb 16>; [100.00%]

  <bb 5> [local count: 1034442875]:
  # DEBUG BEGIN_STMT
  _13 = pfe.phy_if_db;
  session_id.24_14 = session_id;
  _16 = (unsigned int) _25;
  _17 = (void *) _16;
  pfe_if_db_get_first (_13, session_id.24_14, 1, _17, &entry);
  # DEBUG BEGIN_STMT
  entry.25_18 = entry;
  if (entry.25_18 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 6> [local count: 724110013]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 310332862]:
  # DEBUG BEGIN_STMT
  _19 = pfe.classifier;
  _20 = phy_ifs[ii_31].id;
  _21 = phy_ifs[ii_31].name;
  phy_if_119 = pfe_phy_if_create (_19, _20, _21);
  # DEBUG phy_if => phy_if_119
  # DEBUG BEGIN_STMT
  if (phy_if_119 == 0B)
    goto <bb 8>; [3.66%]
  else
    goto <bb 9>; [96.34%]

  <bb 8> [local count: 11358183]:
  # ii_15 = PHI <ii_31(7)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 = phy_ifs[ii_15].name;
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create %s\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2380, _22, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 19
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 298974679]:
  # DEBUG BEGIN_STMT
  _23 = &phy_ifs[ii_31];
  session_id.26_24 = session_id;
  ret_121 = pfe_platform_prepare_phy_if (phy_if_119, _23, session_id.26_24);
  # DEBUG ret => ret_121
  # DEBUG BEGIN_STMT
  if (ret_121 != 0)
    goto <bb 10>; [3.66%]
  else
    goto <bb 11>; [96.34%]

  <bb 10> [local count: 10942473]:
  # phy_if_37 = PHI <phy_if_119(9)>
  # ret_38 = PHI <ret_121(9)>
  # DEBUG BEGIN_STMT
  pfe_phy_if_destroy (phy_if_37);
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 1012142219]:
  # ret_28 = PHI <ret_29(6), ret_121(9)>
  # DEBUG ret => ret_28
  # DEBUG BEGIN_STMT
  ii_125 = ii_31 + 1;
  # DEBUG ii => ii_125

  <bb 16> [local count: 1073741824]:
  # ret_29 = PHI <ret_32(12), ret_28(11)>
  # ii_31 = PHI <ii_42(12), ii_125(11)>
  # DEBUG ii => ii_31
  # DEBUG ret => ret_29
  # DEBUG BEGIN_STMT
  _25 = phy_ifs[ii_31].id;
  if (_25 != 10)
    goto <bb 5>; [96.34%]
  else
    goto <bb 13>; [3.66%]

  <bb 13> [local count: 61599607]:
  # ret_30 = PHI <19(8), ret_38(10), ret_29(16)>
  # DEBUG ret => ret_30
  # DEBUG BEGIN_STMT
  session_id.27_26 = session_id;
  _27 = pfe_if_db_unlock (session_id.27_26);
  if (_27 != 0)
    goto <bb 14>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 14> [local count: 20327870]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] DB unlock failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 2397, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 15> [local count: 61599607]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  session_id ={v} {CLOBBER};
  entry ={v} {CLOBBER};
  phy_ifs ={v} {CLOBBER};
  return ret_30;

}



;; Function pfe_platform_bmu_isr (pfe_platform_bmu_isr, funcdef_no=31, decl_uid=12949, cgraph_uid=32, symbol_order=38)

Modification phase of node pfe_platform_bmu_isr/38
pfe_platform_bmu_isr (void * arg)
{
  bool_t handled;
  struct pfe_bmu_t * _1;
  struct pfe_bmu_t * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG platform => arg_7(D)
  # DEBUG BEGIN_STMT
  # DEBUG handled => 0
  # DEBUG BEGIN_STMT
  _1 = MEM[(const struct pfe_platform_t *)arg_7(D)].bmu[0];
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pfe_bmu_irq_mask (_1);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _3 = MEM[(const struct pfe_platform_t *)arg_7(D)].bmu[1];
  if (_3 != 0B)
    goto <bb 5>; [100.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pfe_bmu_irq_mask (_3);

  <bb 6> [count: 0]:
  handled_2 = pfe_platform_bmu_isr.part.0 (arg_7(D));
  # DEBUG BEGIN_STMT
  return handled_2;

}



;; Function pfe_platform_idex_rpc_cbk (pfe_platform_idex_rpc_cbk, funcdef_no=32, decl_uid=11134, cgraph_uid=33, symbol_order=39)

Modification phase of node pfe_platform_idex_rpc_cbk/39
pfe_platform_idex_rpc_cbk (pfe_ct_phy_if_id_t sender, uint32_t id, void * buf, uint16_t buf_len, void * arg)
{
  uint32_t key;
  struct pfe_emac_t * emac;
  struct pfe_platform_rpc_mdio_proxy_ret_t rpc_ret;
  struct fci_msg_t rep_msg;
  struct fci_msg_t msg;
  struct pfe_platform_rpc_pfe_fci_proxy_ret_t rpc_ret;
  struct pfe_emac_t * emac;
  uint32_t stat_val;
  struct pfe_platform_rpc_pfe_phy_if_get_stat_value_ret_t rpc_ret;
  struct pfe_platform_rpc_pfe_phy_if_stats_ret_t rpc_ret;
  bool_t status;
  struct pfe_platform_rpc_pfe_phy_if_is_promisc_ret_t rpc_ret;
  bool_t status;
  struct pfe_platform_rpc_pfe_phy_if_is_enabled_ret_t rpc_ret;
  pfe_ct_if_op_mode_t mode;
  struct pfe_platform_rpc_pfe_phy_if_get_op_mode_ret_t rpc_ret;
  pfe_ct_block_state_t block_state;
  struct pfe_platform_rpc_pfe_phy_if_get_block_state_ret_t rpc_ret;
  uint8_t mac_addr[6];
  uint8_t mac_addr[6];
  errno_t ret;
  struct pfe_if_db_entry_t * entry;
  struct pfe_phy_if_t * phy_if_arg;
  long unsigned int _1;
  struct pfe_if_db_t * _2;
  long unsigned int _3;
  unsigned char _4;
  unsigned int _5;
  void * _6;
  struct pfe_if_db_entry_t * entry.0_7;
  long unsigned int _8;
  int _9;
  long unsigned int _10;
  int _11;
  int _12;
  int _13;
  int _14;
  int _15;
  int _16;
  int _17;
  int _18;
  int _19;
  int _20;
  int _21;
  int _22;
  uint8_t[6] * _23;
  int _24;
  uint8_t[6] * _25;
  int _26;
  <unnamed type> _27;
  <unnamed type> _28;
  int _29;
  <unnamed type> _30;
  int _31;
  <unnamed type> block_state.2_32;
  int _33;
  int _34;
  int _35;
  int _36;
  int _37;
  <unnamed type> _38;
  int _39;
  int _40;
  int _41;
  long unsigned int _42;
  int _43;
  msg_type_t * _44;
  struct fci_msg_cmd_t * _45;
  long unsigned int _46;
  int _47;
  unsigned char _48;
  int _49;
  int _50;
  int _51;
  <unnamed type> _52;
  unsigned char _53;
  short unsigned int _54;
  unsigned char _55;
  long unsigned int key.3_56;
  int _57;
  unsigned char _58;
  short unsigned int _59;
  unsigned char _60;
  short unsigned int _61;
  long unsigned int key.4_62;
  int _63;
  unsigned char _64;
  unsigned char _65;
  short unsigned int _66;
  long unsigned int key.5_67;
  int _68;
  unsigned char _69;
  unsigned char _70;
  short unsigned int _71;
  short unsigned int _72;
  long unsigned int key.6_73;
  int _74;
  int _75;
  long unsigned int key.7_76;
  int _77;
  int _78;

  <bb 2> [local count: 1072669162]:
  # DEBUG BEGIN_STMT
  # DEBUG platform => arg_132(D)
  # DEBUG BEGIN_STMT
  # DEBUG phy_if_arg => 0B
  # DEBUG BEGIN_STMT
  entry = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = id_135(D) + 4294967195;
  if (_1 <= 20)
    goto <bb 3>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 3> [local count: 353980823]:
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct pfe_platform_t *)arg_132(D)].phy_if_db;
  _3 = (long unsigned int) sender_136(D);
  _4 = MEM[(struct pfe_platform_rpc_pfe_phy_if_generic_t *)buf_137(D)].phy_if_id;
  _5 = (unsigned int) _4;
  _6 = (void *) _5;
  ret_139 = pfe_if_db_get_first (_2, _3, 1, _6, &entry);
  # DEBUG ret => ret_139
  # DEBUG BEGIN_STMT
  if (ret_139 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 4> [local count: 176990412]:
  entry.0_7 = entry;
  if (entry.0_7 != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 5> [local count: 123893288]:
  # DEBUG BEGIN_STMT
  phy_if_arg_140 = pfe_if_db_entry_get_phy_if (entry.0_7);
  # DEBUG phy_if_arg => phy_if_arg_140

  <bb 6> [local count: 1072669162]:
  # phy_if_arg_79 = PHI <0B(2), phy_if_arg_140(5), 0B(4), 0B(3)>
  # ret_80 = PHI <0(2), 0(5), 2(4), 2(3)>
  # DEBUG ret => ret_80
  # DEBUG phy_if_arg => phy_if_arg_79
  # DEBUG BEGIN_STMT
  switch (id_135(D)) <default: <L163> [3.85%], case 100: <L12> [3.85%], case 101: <L15> [3.85%], case 102: <L20> [3.85%], case 103: <L25> [3.85%], case 104: <L30> [3.85%], case 105: <L65> [3.85%], case 106: <L71> [3.85%], case 109: <L93> [3.85%], case 110: <L99> [3.85%], case 111: <L105> [3.85%], case 112: <L111> [3.85%], case 113: <L77> [3.85%], case 114: <L55> [3.85%], case 115: <L60> [3.85%], case 116: <L35> [3.85%], case 117: <L40> [3.85%], case 118: <L45> [3.85%], case 119: <L50> [3.85%], case 120: <L82> [3.85%], case 121: <L87> [3.85%], case 122: <L117> [3.85%], case 190: <L6> [3.85%], case 191: <L9> [3.85%], case 300: <L127> [3.85%], case 310: <L133> [3.85%]>

  <bb 7> [local count: 41297763]:
<L6>:
  # DEBUG BEGIN_STMT
  _8 = (long unsigned int) sender_136(D);
  ret_204 = pfe_if_db_lock_owned (_8);
  # DEBUG ret => ret_204
  # DEBUG BEGIN_STMT
  _9 = pfe_idex_set_rpc_ret_val (ret_204, 0B, 0);
  if (_9 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 8> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 230, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 9> [local count: 41297763]:
<L9>:
  # DEBUG BEGIN_STMT
  _10 = (long unsigned int) sender_136(D);
  ret_199 = pfe_if_db_unlock (_10);
  # DEBUG ret => ret_199
  # DEBUG BEGIN_STMT
  _11 = pfe_idex_set_rpc_ret_val (ret_199, 0B, 0);
  if (_11 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 10> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 242, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 11> [local count: 41297763]:
<L12>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = pfe_idex_set_rpc_ret_val (ret_80, 0B, 0);
  if (_12 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 12> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 254, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 13> [local count: 41297763]:
<L15>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 14>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 14> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_333 = pfe_phy_if_enable (phy_if_arg_79);
  # DEBUG ret => ret_333

  <bb 15> [local count: 41297763]:
  # ret_81 = PHI <ret_80(13), ret_333(14)>
  # DEBUG ret => ret_81
  # DEBUG BEGIN_STMT
  _13 = pfe_idex_set_rpc_ret_val (ret_81, 0B, 0);
  if (_13 != 0)
    goto <bb 16>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 16> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 272, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 17> [local count: 41297763]:
<L20>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 18>; [33.00%]
  else
    goto <bb 19>; [67.00%]

  <bb 18> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_328 = pfe_phy_if_disable (phy_if_arg_79);
  # DEBUG ret => ret_328

  <bb 19> [local count: 41297763]:
  # ret_82 = PHI <ret_80(17), ret_328(18)>
  # DEBUG ret => ret_82
  # DEBUG BEGIN_STMT
  _14 = pfe_idex_set_rpc_ret_val (ret_82, 0B, 0);
  if (_14 != 0)
    goto <bb 20>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 20> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 290, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 21> [local count: 41297763]:
<L25>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 22>; [33.00%]
  else
    goto <bb 23>; [67.00%]

  <bb 22> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_323 = pfe_phy_if_promisc_enable (phy_if_arg_79);
  # DEBUG ret => ret_323

  <bb 23> [local count: 41297763]:
  # ret_83 = PHI <ret_80(21), ret_323(22)>
  # DEBUG ret => ret_83
  # DEBUG BEGIN_STMT
  _15 = pfe_idex_set_rpc_ret_val (ret_83, 0B, 0);
  if (_15 != 0)
    goto <bb 24>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 24> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 308, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 25> [local count: 41297763]:
<L30>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 26>; [33.00%]
  else
    goto <bb 27>; [67.00%]

  <bb 26> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_318 = pfe_phy_if_promisc_disable (phy_if_arg_79);
  # DEBUG ret => ret_318

  <bb 27> [local count: 41297763]:
  # ret_84 = PHI <ret_80(25), ret_318(26)>
  # DEBUG ret => ret_84
  # DEBUG BEGIN_STMT
  _16 = pfe_idex_set_rpc_ret_val (ret_84, 0B, 0);
  if (_16 != 0)
    goto <bb 28>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 28> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 326, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 29> [local count: 41297763]:
<L35>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 30>; [33.00%]
  else
    goto <bb 31>; [67.00%]

  <bb 30> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_253 = pfe_phy_if_loopback_enable (phy_if_arg_79);
  # DEBUG ret => ret_253

  <bb 31> [local count: 41297763]:
  # ret_85 = PHI <ret_80(29), ret_253(30)>
  # DEBUG ret => ret_85
  # DEBUG BEGIN_STMT
  _17 = pfe_idex_set_rpc_ret_val (ret_85, 0B, 0);
  if (_17 != 0)
    goto <bb 32>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 32> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 344, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 33> [local count: 41297763]:
<L40>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 34>; [33.00%]
  else
    goto <bb 35>; [67.00%]

  <bb 34> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_248 = pfe_phy_if_loopback_disable (phy_if_arg_79);
  # DEBUG ret => ret_248

  <bb 35> [local count: 41297763]:
  # ret_86 = PHI <ret_80(33), ret_248(34)>
  # DEBUG ret => ret_86
  # DEBUG BEGIN_STMT
  _18 = pfe_idex_set_rpc_ret_val (ret_86, 0B, 0);
  if (_18 != 0)
    goto <bb 36>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 36> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 362, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 37> [local count: 41297763]:
<L45>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 38>; [33.00%]
  else
    goto <bb 39>; [67.00%]

  <bb 38> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_243 = pfe_phy_if_loadbalance_enable (phy_if_arg_79);
  # DEBUG ret => ret_243

  <bb 39> [local count: 41297763]:
  # ret_87 = PHI <ret_80(37), ret_243(38)>
  # DEBUG ret => ret_87
  # DEBUG BEGIN_STMT
  _19 = pfe_idex_set_rpc_ret_val (ret_87, 0B, 0);
  if (_19 != 0)
    goto <bb 40>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 40> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 380, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 41> [local count: 41297763]:
<L50>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 42>; [33.00%]
  else
    goto <bb 43>; [67.00%]

  <bb 42> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_238 = pfe_phy_if_loadbalance_disable (phy_if_arg_79);
  # DEBUG ret => ret_238

  <bb 43> [local count: 41297763]:
  # ret_88 = PHI <ret_80(41), ret_238(42)>
  # DEBUG ret => ret_88
  # DEBUG BEGIN_STMT
  _20 = pfe_idex_set_rpc_ret_val (ret_88, 0B, 0);
  if (_20 != 0)
    goto <bb 44>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 44> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 398, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 45> [local count: 41297763]:
<L55>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 46>; [33.00%]
  else
    goto <bb 47>; [67.00%]

  <bb 46> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_263 = pfe_phy_if_allmulti_enable (phy_if_arg_79);
  # DEBUG ret => ret_263

  <bb 47> [local count: 41297763]:
  # ret_89 = PHI <ret_80(45), ret_263(46)>
  # DEBUG ret => ret_89
  # DEBUG BEGIN_STMT
  _21 = pfe_idex_set_rpc_ret_val (ret_89, 0B, 0);
  if (_21 != 0)
    goto <bb 48>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 48> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 416, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 49> [local count: 41297763]:
<L60>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 50>; [33.00%]
  else
    goto <bb 51>; [67.00%]

  <bb 50> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_258 = pfe_phy_if_allmulti_disable (phy_if_arg_79);
  # DEBUG ret => ret_258

  <bb 51> [local count: 41297763]:
  # ret_90 = PHI <ret_80(49), ret_258(50)>
  # DEBUG ret => ret_90
  # DEBUG BEGIN_STMT
  _22 = pfe_idex_set_rpc_ret_val (ret_90, 0B, 0);
  if (_22 != 0)
    goto <bb 52>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 52> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 434, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 53> [local count: 41297763]:
<L65>:
  # DEBUG BEGIN_STMT
  # DEBUG rpc_arg => buf_137(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 54>; [33.00%]
  else
    goto <bb 55>; [67.00%]

  <bb 54> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = &MEM[(struct pfe_platform_rpc_pfe_phy_if_add_mac_addr_arg_t *)buf_137(D)].mac_addr;
  autolibc_memcpy (&mac_addr, _23, 6);
  # DEBUG BEGIN_STMT
  ret_312 = pfe_phy_if_add_mac_addr (phy_if_arg_79, &mac_addr, sender_136(D));
  # DEBUG ret => ret_312

  <bb 55> [local count: 41297763]:
  # ret_91 = PHI <ret_80(53), ret_312(54)>
  # DEBUG ret => ret_91
  # DEBUG BEGIN_STMT
  _24 = pfe_idex_set_rpc_ret_val (ret_91, 0B, 0);
  if (_24 != 0)
    goto <bb 56>; [33.00%]
  else
    goto <bb 57>; [67.00%]

  <bb 56> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 457, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 57> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mac_addr ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 58> [local count: 41297763]:
<L71>:
  # DEBUG BEGIN_STMT
  # DEBUG rpc_arg => buf_137(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 59>; [33.00%]
  else
    goto <bb 60>; [67.00%]

  <bb 59> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = &MEM[(struct pfe_platform_rpc_pfe_phy_if_del_mac_addr_arg_t *)buf_137(D)].mac_addr;
  autolibc_memcpy (&mac_addr, _25, 6);
  # DEBUG BEGIN_STMT
  ret_305 = pfe_phy_if_del_mac_addr (phy_if_arg_79, &mac_addr, sender_136(D));
  # DEBUG ret => ret_305

  <bb 60> [local count: 41297763]:
  # ret_92 = PHI <ret_80(58), ret_305(59)>
  # DEBUG ret => ret_92
  # DEBUG BEGIN_STMT
  _26 = pfe_idex_set_rpc_ret_val (ret_92, 0B, 0);
  if (_26 != 0)
    goto <bb 61>; [33.00%]
  else
    goto <bb 62>; [67.00%]

  <bb 61> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 480, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 62> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mac_addr ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 63> [local count: 41297763]:
<L77>:
  # DEBUG BEGIN_STMT
  # DEBUG rpc_arg => buf_137(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 64>; [33.00%]
  else
    goto <bb 65>; [67.00%]

  <bb 64> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  _27 = MEM[(struct pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t *)buf_137(D)].crit;
  _28 = MEM[(struct pfe_platform_rpc_pfe_phy_if_flush_mac_addrs_arg_t *)buf_137(D)].type;
  ret_268 = pfe_phy_if_flush_mac_addrs (phy_if_arg_79, _27, _28, sender_136(D));
  # DEBUG ret => ret_268

  <bb 65> [local count: 41297763]:
  # ret_93 = PHI <ret_80(63), ret_268(64)>
  # DEBUG ret => ret_93
  # DEBUG BEGIN_STMT
  _29 = pfe_idex_set_rpc_ret_val (ret_93, 0B, 0);
  if (_29 != 0)
    goto <bb 66>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 66> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 500, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 67> [local count: 41297763]:
<L82>:
  # DEBUG BEGIN_STMT
  # DEBUG rpc_arg => buf_137(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 68>; [33.00%]
  else
    goto <bb 69>; [67.00%]

  <bb 68> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  _30 = MEM[(struct pfe_platform_rpc_pfe_phy_if_set_block_state_arg_t *)buf_137(D)].block_state;
  ret_233 = pfe_phy_if_set_block_state (phy_if_arg_79, _30);
  # DEBUG ret => ret_233

  <bb 69> [local count: 41297763]:
  # ret_94 = PHI <ret_80(67), ret_233(68)>
  # DEBUG ret => ret_94
  # DEBUG BEGIN_STMT
  _31 = pfe_idex_set_rpc_ret_val (ret_94, 0B, 0);
  if (_31 != 0)
    goto <bb 70>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 70> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 520, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 131>; [100.00%]

  <bb 71> [local count: 41297763]:
<L87>:
  # DEBUG BEGIN_STMT
  rpc_ret.state = 0;
  # DEBUG BEGIN_STMT
  block_state = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 72>; [33.00%]
  else
    goto <bb 73>; [67.00%]

  <bb 72> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  ret_225 = pfe_phy_if_get_block_state (phy_if_arg_79, &block_state);
  # DEBUG ret => ret_225
  # DEBUG BEGIN_STMT
  block_state.2_32 = block_state;
  rpc_ret.state = block_state.2_32;

  <bb 73> [local count: 41297763]:
  # ret_95 = PHI <ret_80(71), ret_225(72)>
  # DEBUG ret => ret_95
  # DEBUG BEGIN_STMT
  _33 = pfe_idex_set_rpc_ret_val (ret_95, &rpc_ret, 4);
  if (_33 != 0)
    goto <bb 74>; [33.00%]
  else
    goto <bb 75>; [67.00%]

  <bb 74> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 542, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 75> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rpc_ret ={v} {CLOBBER};
  block_state ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 76> [local count: 41297763]:
<L93>:
  # DEBUG BEGIN_STMT
  rpc_ret.mode = 0;
  # DEBUG BEGIN_STMT
  # DEBUG mode => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 77>; [33.00%]
  else
    goto <bb 78>; [67.00%]

  <bb 77> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  mode_297 = pfe_phy_if_get_op_mode (phy_if_arg_79);
  # DEBUG mode => mode_297
  # DEBUG BEGIN_STMT
  rpc_ret.mode = mode_297;

  <bb 78> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  _34 = pfe_idex_set_rpc_ret_val (ret_80, &rpc_ret, 4);
  if (_34 != 0)
    goto <bb 79>; [33.00%]
  else
    goto <bb 80>; [67.00%]

  <bb 79> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 564, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 80> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rpc_ret ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 81> [local count: 41297763]:
<L99>:
  # DEBUG BEGIN_STMT
  rpc_ret.status = 0;
  # DEBUG BEGIN_STMT
  # DEBUG status => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 82>; [33.00%]
  else
    goto <bb 83>; [67.00%]

  <bb 82> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  status_289 = pfe_phy_if_is_enabled (phy_if_arg_79);
  # DEBUG status => status_289
  # DEBUG BEGIN_STMT
  rpc_ret.status = status_289;

  <bb 83> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  _35 = pfe_idex_set_rpc_ret_val (ret_80, &rpc_ret, 4);
  if (_35 != 0)
    goto <bb 84>; [33.00%]
  else
    goto <bb 85>; [67.00%]

  <bb 84> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 587, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 85> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rpc_ret ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 86> [local count: 41297763]:
<L105>:
  # DEBUG BEGIN_STMT
  rpc_ret.status = 0;
  # DEBUG BEGIN_STMT
  # DEBUG status => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 87>; [33.00%]
  else
    goto <bb 88>; [67.00%]

  <bb 87> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  status_281 = pfe_phy_if_is_promisc (phy_if_arg_79);
  # DEBUG status => status_281
  # DEBUG BEGIN_STMT
  rpc_ret.status = status_281;

  <bb 88> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  _36 = pfe_idex_set_rpc_ret_val (ret_80, &rpc_ret, 4);
  if (_36 != 0)
    goto <bb 89>; [33.00%]
  else
    goto <bb 90>; [67.00%]

  <bb 89> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 610, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 90> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rpc_ret ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 91> [local count: 41297763]:
<L111>:
  # DEBUG BEGIN_STMT
  rpc_ret = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 92>; [33.00%]
  else
    goto <bb 93>; [67.00%]

  <bb 92> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_274 = pfe_phy_if_get_stats (phy_if_arg_79, &rpc_ret.stats);
  # DEBUG ret => ret_274

  <bb 93> [local count: 41297763]:
  # ret_96 = PHI <ret_80(91), ret_274(92)>
  # DEBUG ret => ret_96
  # DEBUG BEGIN_STMT
  _37 = pfe_idex_set_rpc_ret_val (ret_96, &rpc_ret, 16);
  if (_37 != 0)
    goto <bb 94>; [33.00%]
  else
    goto <bb 95>; [67.00%]

  <bb 94> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 631, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 95> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rpc_ret ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 96> [local count: 41297763]:
<L117>:
  # DEBUG BEGIN_STMT
  # DEBUG rpc_arg => buf_137(D)
  # DEBUG BEGIN_STMT
  rpc_ret.stat_val = 0;
  # DEBUG BEGIN_STMT
  # DEBUG stat_val => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 97>; [67.00%]
  else
    goto <bb 101>; [33.00%]

  <bb 97> [local count: 27669501]:
  # DEBUG BEGIN_STMT
  _38 = MEM[(struct pfe_platform_rpc_pfe_phy_if_get_stat_value_arg_t *)buf_137(D)].phy_if_id;
  if (_38 > 2)
    goto <bb 98>; [50.00%]
  else
    goto <bb 100>; [50.00%]

  <bb 98> [local count: 13834750]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _39 = (int) _38;
  pfe_hm_report (1, 2, 1, "[%s:%d] RPC: PFE_PLATFORM_RPC_PFE_PHY_IF_GET_STAT_VALUE: invalid EMAC id: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 650, _39, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _40 = pfe_idex_set_rpc_ret_val (22, 0B, 0);
  if (_40 != 0)
    goto <bb 99>; [33.00%]
  else
    goto <bb 103>; [67.00%]

  <bb 99> [local count: 4565468]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 654, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 103>; [100.00%]

  <bb 100> [local count: 13834750]:
  # DEBUG BEGIN_STMT
  _41 = (int) _38;
  emac_209 = pfe.emac[_41];
  # DEBUG emac => emac_209
  # DEBUG BEGIN_STMT
  _42 = MEM[(struct pfe_platform_rpc_pfe_phy_if_get_stat_value_arg_t *)buf_137(D)].stat_id;
  stat_val_211 = pfe_emac_get_stat_value (emac_209, _42);
  # DEBUG stat_val => stat_val_211
  # DEBUG BEGIN_STMT
  rpc_ret.stat_val = stat_val_211;

  <bb 101> [local count: 27463012]:
  # DEBUG BEGIN_STMT
  _43 = pfe_idex_set_rpc_ret_val (ret_80, &rpc_ret, 4);
  if (_43 != 0)
    goto <bb 102>; [33.00%]
  else
    goto <bb 103>; [67.00%]

  <bb 102> [local count: 9062794]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 669, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 103> [local count: 41297763]:
  rpc_ret ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 104> [local count: 41297763]:
<L127>:
  # DEBUG BEGIN_STMT
  # DEBUG rpc_arg => buf_137(D)
  # DEBUG BEGIN_STMT
  rpc_ret = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 105>; [33.00%]
  else
    goto <bb 106>; [67.00%]

  <bb 105> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _44 = &MEM[(struct pfe_platform_rpc_pfe_fci_proxy_arg_t *)buf_137(D)].type;
  autolibc_memcpy (&msg.type, _44, 4);
  # DEBUG BEGIN_STMT
  _45 = &MEM[(struct pfe_platform_rpc_pfe_fci_proxy_arg_t *)buf_137(D)].msg_cmd;
  autolibc_memcpy (&msg.msg_cmd, _45, 268);
  # DEBUG BEGIN_STMT
  rep_msg = {};
  rep_msg.type = 4099;
  # DEBUG BEGIN_STMT
  _46 = (long unsigned int) sender_136(D);
  msg.msg_cmd.sender = _46;
  # DEBUG BEGIN_STMT
  ret_190 = fci_process_ipc_message (&msg, &rep_msg);
  # DEBUG ret => ret_190
  # DEBUG BEGIN_STMT
  rpc_ret.msg_cmd = rep_msg.msg_cmd;
  msg ={v} {CLOBBER};
  rep_msg ={v} {CLOBBER};

  <bb 106> [local count: 41297763]:
  # ret_97 = PHI <ret_80(104), ret_190(105)>
  # DEBUG ret => ret_97
  # DEBUG BEGIN_STMT
  _47 = pfe_idex_set_rpc_ret_val (ret_97, &rpc_ret, 268);
  if (_47 != 0)
    goto <bb 107>; [33.00%]
  else
    goto <bb 108>; [67.00%]

  <bb 107> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 707, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 108> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rpc_ret ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 109> [local count: 41297763]:
<L133>:
  # DEBUG BEGIN_STMT
  # DEBUG rpc_arg => buf_137(D)
  # DEBUG BEGIN_STMT
  rpc_ret.val = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_80 == 0)
    goto <bb 110>; [50.00%]
  else
    goto <bb 128>; [50.00%]

  <bb 110> [local count: 20648881]:
  # DEBUG BEGIN_STMT
  _48 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].emac_id;
  if (_48 > 2)
    goto <bb 111>; [50.00%]
  else
    goto <bb 113>; [50.00%]

  <bb 111> [local count: 10324441]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _49 = (int) _48;
  pfe_hm_report (1, 2, 1, "[%s:%d] RPC: PFE_PLATFORM_RPC_MDIO_PROXY: invalid EMAC id: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 726, _49, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _50 = pfe_idex_set_rpc_ret_val (22, 0B, 0);
  if (_50 != 0)
    goto <bb 112>; [33.00%]
  else
    goto <bb 128>; [67.00%]

  <bb 112> [local count: 3407065]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 730, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 128>; [100.00%]

  <bb 113> [local count: 10324441]:
  # DEBUG BEGIN_STMT
  _51 = (int) _48;
  emac_142 = pfe.emac[_51];
  # DEBUG emac => emac_142
  # DEBUG BEGIN_STMT
  ret_144 = pfe_emac_mdio_lock (emac_142, &key);
  # DEBUG ret => ret_144
  # DEBUG BEGIN_STMT
  if (ret_144 == 0)
    goto <bb 114>; [67.00%]
  else
    goto <bb 126>; [33.00%]

  <bb 114> [local count: 6917375]:
  # DEBUG BEGIN_STMT
  _52 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].op;
  switch (_52) <default: <L152> [20.00%], case 101: <L140> [20.00%], case 102: <L143> [20.00%], case 103: <L146> [20.00%], case 104: <L149> [20.00%]>

  <bb 115> [local count: 1383475]:
<L140>:
  # DEBUG BEGIN_STMT
  _53 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].pa;
  _54 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].ra;
  _55 = (unsigned char) _54;
  key.3_56 = key;
  ret_166 = pfe_emac_mdio_read22 (emac_142, _53, _55, &rpc_ret.val, key.3_56);
  # DEBUG ret => ret_166
  # DEBUG BEGIN_STMT
  _57 = pfe_idex_set_rpc_ret_val (ret_166, &rpc_ret, 4);
  if (_57 != 0)
    goto <bb 116>; [33.00%]
  else
    goto <bb 125>; [67.00%]

  <bb 116> [local count: 456547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 749, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 125>; [100.00%]

  <bb 117> [local count: 1383475]:
<L143>:
  # DEBUG BEGIN_STMT
  _58 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].pa;
  _59 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].ra;
  _60 = (unsigned char) _59;
  _61 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].val;
  key.4_62 = key;
  ret_161 = pfe_emac_mdio_write22 (emac_142, _58, _60, _61, key.4_62);
  # DEBUG ret => ret_161
  # DEBUG BEGIN_STMT
  _63 = pfe_idex_set_rpc_ret_val (ret_161, 0B, 0);
  if (_63 != 0)
    goto <bb 118>; [33.00%]
  else
    goto <bb 125>; [67.00%]

  <bb 118> [local count: 456547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 759, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 125>; [100.00%]

  <bb 119> [local count: 1383475]:
<L146>:
  # DEBUG BEGIN_STMT
  _64 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].pa;
  _65 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].dev;
  _66 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].ra;
  key.5_67 = key;
  ret_156 = pfe_emac_mdio_read45 (emac_142, _64, _65, _66, &rpc_ret.val, key.5_67);
  # DEBUG ret => ret_156
  # DEBUG BEGIN_STMT
  _68 = pfe_idex_set_rpc_ret_val (ret_156, &rpc_ret, 4);
  if (_68 != 0)
    goto <bb 120>; [33.00%]
  else
    goto <bb 125>; [67.00%]

  <bb 120> [local count: 456547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 769, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 125>; [100.00%]

  <bb 121> [local count: 1383475]:
<L149>:
  # DEBUG BEGIN_STMT
  _69 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].pa;
  _70 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].dev;
  _71 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].ra;
  _72 = MEM[(struct pfe_platform_rpc_mdio_proxy_arg_t *)buf_137(D)].val;
  key.6_73 = key;
  ret_151 = pfe_emac_mdio_write45 (emac_142, _69, _70, _71, _72, key.6_73);
  # DEBUG ret => ret_151
  # DEBUG BEGIN_STMT
  _74 = pfe_idex_set_rpc_ret_val (ret_151, 0B, 0);
  if (_74 != 0)
    goto <bb 122>; [33.00%]
  else
    goto <bb 125>; [67.00%]

  <bb 122> [local count: 456547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 779, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 125>; [100.00%]

  <bb 123> [local count: 1383475]:
<L152>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid MDIO operation\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 785, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _75 = pfe_idex_set_rpc_ret_val (22, 0B, 0);
  if (_75 != 0)
    goto <bb 124>; [33.00%]
  else
    goto <bb 125>; [67.00%]

  <bb 124> [local count: 456547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 789, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 125> [local count: 6917375]:
  # DEBUG BEGIN_STMT
  key.7_76 = key;
  pfe_emac_mdio_unlock (emac_142, key.7_76);
  goto <bb 128>; [100.00%]

  <bb 126> [local count: 3407065]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Lock the MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 799, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _77 = pfe_idex_set_rpc_ret_val (115, 0B, 0);
  if (_77 != 0)
    goto <bb 127>; [33.00%]
  else
    goto <bb 128>; [67.00%]

  <bb 127> [local count: 1124332]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 803, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 128> [local count: 41297763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rpc_ret ={v} {CLOBBER};
  key ={v} {CLOBBER};
  goto <bb 131>; [100.00%]

  <bb 129> [local count: 41297763]:
<L163>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _78 = pfe_idex_set_rpc_ret_val (22, 0B, 0);
  if (_78 != 0)
    goto <bb 130>; [33.00%]
  else
    goto <bb 131>; [67.00%]

  <bb 130> [local count: 13628262]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not send RPC response\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 818, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 131> [local count: 1073741824]:
  entry ={v} {CLOBBER};
  return;

}



;; Function pfe_platform_get_phy_if_by_id (pfe_platform_get_phy_if_by_id, funcdef_no=68, decl_uid=11128, cgraph_uid=69, symbol_order=75)

Modification phase of node pfe_platform_get_phy_if_by_id/75
pfe_platform_get_phy_if_by_id (const struct pfe_platform_t * platform, pfe_ct_phy_if_id_t id)
{
  struct pfe_phy_if_t * phyif;
  uint32_t session_id;
  struct pfe_if_db_entry_t * entry;
  struct pfe_if_db_t * _1;
  long unsigned int session_id.8_2;
  unsigned int _3;
  void * _4;
  long unsigned int session_id.9_5;
  struct pfe_if_db_entry_t * entry.10_6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  entry = 0B;
  # DEBUG BEGIN_STMT
  session_id = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_if_db_lock (&session_id);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = platform_11(D)->phy_if_db;
  session_id.8_2 = session_id;
  _3 = (unsigned int) id_12(D);
  _4 = (void *) _3;
  pfe_if_db_get_first (_1, session_id.8_2, 1, _4, &entry);
  # DEBUG BEGIN_STMT
  session_id.9_5 = session_id;
  pfe_if_db_unlock (session_id.9_5);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry.10_6 = entry;
  phyif_15 = pfe_if_db_entry_get_phy_if (entry.10_6);
  # DEBUG phyif => phyif_15
  # DEBUG BEGIN_STMT
  entry ={v} {CLOBBER};
  session_id ={v} {CLOBBER};
  return phyif_15;

}



;; Function pfe_platform_soft_reset (pfe_platform_soft_reset, funcdef_no=78, decl_uid=11121, cgraph_uid=79, symbol_order=85)

Modification phase of node pfe_platform_soft_reset/85
pfe_platform_soft_reset (const struct pfe_platform_t * platform)
{
  errno_t ret;
  uint32_t timeout;
  bool_t run_on_g3;
  uint32_t regval;
  addr_t addr_dbug;
  addr_t addr_gen;
  unsigned char _1;
  unsigned int _2;
  volatile uint32_t * addr_gen.11_3;
  volatile uint32_t * addr_dbug.15_5;
  long unsigned int _6;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;

  <bb 2> [local count: 135372966]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG run_on_g3 => 0
  # DEBUG BEGIN_STMT
  # DEBUG timeout => 1000
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  if (_1 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 46026808]:
  # DEBUG BEGIN_STMT
  # DEBUG run_on_g3 => 1

  <bb 4> [local count: 135372966]:
  # run_on_g3_8 = PHI <0(2), 1(3)>
  # DEBUG run_on_g3 => run_on_g3_8
  # DEBUG BEGIN_STMT
  _2 = pfe.cbus_baseaddr;
  addr_gen_18 = _2 + 606240;
  # DEBUG addr_gen => addr_gen_18
  # DEBUG BEGIN_STMT
  addr_gen.11_3 = (volatile uint32_t *) addr_gen_18;
  regval_19 ={v} *addr_gen.11_3;
  # DEBUG regval => regval_19
  # DEBUG BEGIN_STMT
  if (run_on_g3_8 == 1)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 46026808]:
  # DEBUG BEGIN_STMT
  regval_20 = regval_19 | 939524096;
  # DEBUG regval => regval_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *addr_gen.11_3 ={v} regval_20;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = regval_19 & 3355443199;
  # DEBUG regval => _13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *addr_gen.11_3 ={v} _13;

  <bb 6> [local count: 135372966]:
  # regval_7 = PHI <regval_19(4), _13(5)>
  # DEBUG regval => regval_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  regval_23 = regval_7 | 1073741824;
  # DEBUG regval => regval_23
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *addr_gen.11_3 ={v} regval_23;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (run_on_g3_8 == 1)
    goto <bb 7>; [51.12%]
  else
    goto <bb 12>; [48.88%]

  <bb 7> [local count: 69202660]:
  # DEBUG BEGIN_STMT
  addr_dbug_27 = _2 + 606372;
  # DEBUG addr_dbug => addr_dbug_27

  <bb 8> [local count: 1073741824]:
  # timeout_9 = PHI <1000(7), timeout_29(14)>
  # DEBUG timeout => timeout_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_dbug.15_5 = (volatile uint32_t *) addr_dbug_27;
  _6 ={v} *addr_dbug.15_5;
  regval_28 = _6 & 524288;
  # DEBUG regval => regval_28
  # DEBUG BEGIN_STMT
  timeout_29 = timeout_9 + 4294967295;
  # DEBUG timeout => timeout_29
  # DEBUG BEGIN_STMT
  if (regval_28 == 0)
    goto <bb 9>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 9> [local count: 1014686025]:
  if (timeout_29 != 0)
    goto <bb 14>; [99.00%]
  else
    goto <bb 10>; [1.00%]

  <bb 14> [local count: 1004539165]:
  goto <bb 8>; [100.00%]

  <bb 10> [local count: 69202661]:
  # timeout_4 = PHI <timeout_29(8), timeout_29(9)>
  # DEBUG BEGIN_STMT
  if (timeout_4 == 0)
    goto <bb 13>; [35.00%]
  else
    goto <bb 11>; [65.00%]

  <bb 11> [local count: 44981729]:
  # DEBUG BEGIN_STMT
  regval_30 ={v} *addr_gen.11_3;
  # DEBUG regval => regval_30
  # DEBUG BEGIN_STMT
  regval_31 = regval_30 & 3221225471;
  # DEBUG regval => regval_31
  # DEBUG BEGIN_STMT
  regval_32 = regval_31 | 939524096;
  # DEBUG regval => regval_32
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *addr_gen.11_3 ={v} regval_32;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = regval_30 & 2281701375;
  # DEBUG regval => _15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *addr_gen.11_3 ={v} _15;
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 66170306]:
  # DEBUG BEGIN_STMT
  oal_time_usleep (5);
  # DEBUG BEGIN_STMT
  _14 = regval_7 & 3221225471;
  # DEBUG regval => _14
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *addr_gen.11_3 ={v} _14;

  <bb 13> [local count: 135372967]:
  # ret_10 = PHI <0(11), 0(12), 110(10)>
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_10;

}



;; Function pfe_platform_remove (pfe_platform_remove, funcdef_no=88, decl_uid=11123, cgraph_uid=89, symbol_order=95)

Modification phase of node pfe_platform_remove/95
pfe_platform_remove ()
{
  errno_t ret;
  struct oal_irq_t * _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  void * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = pfe.irq_global;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  oal_irq_destroy (_1);
  # DEBUG BEGIN_STMT
  pfe.irq_global = 0B;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = pfe.cbus_baseaddr;
  if (_2 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = _2 + 606240;
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} 0;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_destroy ();
  # DEBUG BEGIN_STMT
  pfe_platform_destroy_group1 ();
  # DEBUG BEGIN_STMT
  pfe_platform_destroy_group2 ();
  # DEBUG BEGIN_STMT
  pfe_feature_mgr_fini ();
  # DEBUG BEGIN_STMT
  _5 = pfe.cbus_baseaddr;
  if (_5 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 8> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _6 = (void *) _5;
  ret_20 = oal_mm_dev_unmap (_6, 16777216);
  # DEBUG ret => ret_20
  # DEBUG BEGIN_STMT
  if (ret_20 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 116930485]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t unmap PPFE CBUS: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_platform_master.c", 3131, ret_20, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 10> [local count: 354334802]:
  # DEBUG ret => ret_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_20 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 896574424]:
  # ret_25 = PHI <ret_20(10), 0(6)>
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  pfe.cbus_baseaddr = 0;
  # DEBUG BEGIN_STMT
  pfe.probed ={v} 0;

  <bb 12> [local count: 1073741824]:
  # ret_26 = PHI <ret_20(10), ret_25(11)>
  # DEBUG BEGIN_STMT
  return ret_26;

}



;; Function pfe_platform_init (pfe_platform_init, funcdef_no=85, decl_uid=11119, cgraph_uid=86, symbol_order=92)

Modification phase of node pfe_platform_init/92
pfe_platform_init (const struct pfe_platform_config_t * config)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  ret_6 = pfe_platform_init_hm_fw_features (config_4(D));
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  if (ret_6 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  ret_8 = pfe_platform_init_mirror_spd_acc_features (config_4(D));
  # DEBUG ret => ret_8

  <bb 4> [local count: 1073741824]:
  # ret_1 = PHI <ret_6(2), ret_8(3)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  return ret_1;

}



;; Function pfe_platform_remove_sw_if (pfe_platform_remove_sw_if, funcdef_no=89, decl_uid=11140, cgraph_uid=90, symbol_order=96)

Modification phase of node pfe_platform_remove_sw_if/96
pfe_platform_remove_sw_if ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pfe.log_if_db = 0B;
  # DEBUG BEGIN_STMT
  pfe.phy_if_db = 0B;
  return;

}



;; Function pfe_platform_get_instance (pfe_platform_get_instance, funcdef_no=90, decl_uid=11125, cgraph_uid=91, symbol_order=97)

Modification phase of node pfe_platform_get_instance/97
pfe_platform_get_instance ()
{
  struct pfe_platform_t * pfe_platform;
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG pfe_platform => 0B
  # DEBUG BEGIN_STMT
  _1 ={v} pfe.probed;
  if (_1 == 1)
    goto <bb 3>; [55.78%]
  else
    goto <bb 4>; [44.22%]

  <bb 3> [local count: 598933190]:
  # DEBUG BEGIN_STMT
  # DEBUG pfe_platform => &pfe

  <bb 4> [local count: 1073741824]:
  # pfe_platform_2 = PHI <0B(2), &pfe(3)>
  # DEBUG pfe_platform => pfe_platform_2
  # DEBUG BEGIN_STMT
  return pfe_platform_2;

}



;; Function pfe_platform_get_fw_versions (pfe_platform_get_fw_versions, funcdef_no=91, decl_uid=11138, cgraph_uid=92, symbol_order=98)

Modification phase of node pfe_platform_get_fw_versions/98
pfe_platform_get_fw_versions (const struct pfe_platform_t * platform, struct pfe_ct_version_t * class_fw, struct pfe_ct_version_t * util_fw)
{
  struct pfe_class_t * _1;
  struct pfe_util_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (class_fw_5(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _1 = platform_7(D)->classifier;
  pfe_class_get_fw_version (_1, class_fw_5(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (util_fw_9(D) != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _2 = platform_7(D)->util;
  pfe_util_get_fw_version (_2, util_fw_9(D));

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}


