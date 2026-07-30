
IPA constant propagation start:
Determining dynamic type for call: ret_5 = pfe_l2br_config_domain (bridge_1(D), domain_3);
  Starting walk at: ret_5 = pfe_l2br_config_domain (bridge_1(D), domain_3);
  instance pointer: bridge_1(D)  Outer instance pointer: bridge_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (domain_3, 0, 72);
  Function call may change dynamic type:domain_3 = isa_reserve (_2);
Determining dynamic type for call: ret_5 = pfe_l2br_config_domain (bridge_1(D), domain_3);
  Starting walk at: ret_5 = pfe_l2br_config_domain (bridge_1(D), domain_3);
  instance pointer: domain_3  Outer instance pointer: domain_3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (domain_3, 0, 72);
  Function call may change dynamic type:domain_3 = isa_reserve (_2);
Determining dynamic type for call: ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_1(D), sentry_4);
  Starting walk at: ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_1(D), sentry_4);
  instance pointer: bridge_1(D)  Outer instance pointer: bridge_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sentry_4 = isa_item (_2, index_3);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] NULL static entry detected!\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 1530, "");
  Function call may change dynamic type:sentry_4 = isa_item (_2, index_3);
  Function call may change dynamic type:ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_1(D), sentry_4);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Unable to remove static entry: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 1542, ret_13, "");
Determining dynamic type for call: ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_1(D), sentry_4);
  Starting walk at: ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_1(D), sentry_4);
  instance pointer: sentry_4  Outer instance pointer: sentry_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sentry_4 = isa_item (_2, index_3);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] NULL static entry detected!\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 1530, "");
  Function call may change dynamic type:sentry_4 = isa_item (_2, index_3);
  Function call may change dynamic type:ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_1(D), sentry_4);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Unable to remove static entry: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 1542, ret_13, "");
Determining dynamic type for call: pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  instance pointer: _5  Outer instance pointer: _5 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
Determining dynamic type for call: pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
Determining dynamic type for call: pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  Starting walk at: pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
Determining dynamic type for call: pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  Starting walk at: pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  instance pointer: &vlan_tmp_entry  Outer instance pointer: vlan_tmp_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
Determining dynamic type for call: pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
  Starting walk at: pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
Determining dynamic type for call: pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
  Starting walk at: pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
  instance pointer: &vlan_tmp_entry  Outer instance pointer: vlan_tmp_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_20, _21, vlan_new_entry_22(D));
  Starting walk at: pfe_vlan_write_to_class (_20, _21, vlan_new_entry_22(D));
  instance pointer: _20  Outer instance pointer: _20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_20, _21, vlan_new_entry_22(D));
  Starting walk at: pfe_vlan_write_to_class (_20, _21, vlan_new_entry_22(D));
  instance pointer: vlan_new_entry_22(D)  Outer instance pointer: vlan_new_entry_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_27, _7, &vlan_current_entry);
  Starting walk at: pfe_vlan_write_to_class (_27, _7, &vlan_current_entry);
  instance pointer: _27  Outer instance pointer: _27 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_write_to_class (_20, _21, vlan_new_entry_22(D));
  Function call may change dynamic type:pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_27, _7, &vlan_current_entry);
  Starting walk at: pfe_vlan_write_to_class (_27, _7, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_write_to_class (_20, _21, vlan_new_entry_22(D));
  Function call may change dynamic type:pfe_vlan_read_from_class (_5, _7, &vlan_current_entry);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config size\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 507, "");
  Function call may change dynamic type:ret_1 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "size", &hash_size);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:ret_2 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "coll_space", &coll_space);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Wrong vlan software table config collision space\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 514, "");
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_tmp_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_14, _15, &vlan_tmp_entry);
Determining dynamic type for call: _5 = pfe_l2br_domain_match_criterion (bridge_16(D), domain_18);
  Starting walk at: _5 = pfe_l2br_domain_match_criterion (bridge_16(D), domain_18);
  instance pointer: bridge_16(D)  Outer instance pointer: bridge_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:domain_18 = isa_item (_1, _6);
  Function call may change dynamic type:domain_18 = isa_item (_1, _6);
  Function call may change dynamic type:_5 = pfe_l2br_domain_match_criterion (bridge_16(D), domain_18);
Determining dynamic type for call: _5 = pfe_l2br_domain_match_criterion (bridge_16(D), domain_18);
  Starting walk at: _5 = pfe_l2br_domain_match_criterion (bridge_16(D), domain_18);
  instance pointer: domain_18  Outer instance pointer: domain_18 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:domain_18 = isa_item (_1, _6);
  Function call may change dynamic type:domain_18 = isa_item (_1, _6);
  Function call may change dynamic type:_5 = pfe_l2br_domain_match_criterion (bridge_16(D), domain_18);
Determining dynamic type for call: domain_16 = pfe_l2br_get_next_domain (bridge_8(D));
  Starting walk at: domain_16 = pfe_l2br_get_next_domain (bridge_8(D));
  instance pointer: bridge_8(D)  Outer instance pointer: bridge_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_l2br_domain_destroy (_1);
  Starting walk at: _2 = pfe_l2br_domain_destroy (_1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = pfe_l2br_domain_destroy (_3);
  Starting walk at: _4 = pfe_l2br_domain_destroy (_3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_l2br_domain_destroy (_1);
Determining dynamic type for call: pfe_l2br_destroy_vlan_stats_table (_6, _7);
  Starting walk at: pfe_l2br_destroy_vlan_stats_table (_6, _7);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:isa_isempty (_5);
  Function call may change dynamic type:_2 = pfe_l2br_domain_destroy (_1);
  Function call may change dynamic type:_4 = pfe_l2br_domain_destroy (_3);
Determining dynamic type for call: _4 = pfe_l2br_create_vlan_stats_table (class_8(D), vlan_stats_size_18(D));
  Starting walk at: _4 = pfe_l2br_create_vlan_stats_table (class_8(D), vlan_stats_size_18(D));
  instance pointer: class_8(D)  Outer instance pointer: class_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&stats_index, 0, 128);
  Function call may change dynamic type:isa_init (&l2_bridge_instance.domains, &l2_bridge_instance_domains_isa_def);
  Function call may change dynamic type:isa_init (&l2_bridge_instance.static_entries, &l2_bridge_instance_statics_isa_def);
  Function call may change dynamic type:autolibc_memset (&l2_bridge_instance, 0, 5632);
Determining dynamic type for call: pfe_l2br_create_mandatory_domains (class_8(D), &bridge, def_vlan_14(D), def_aging_time_23(D));
  Starting walk at: pfe_l2br_create_mandatory_domains (class_8(D), &bridge, def_vlan_14(D), def_aging_time_23(D));
  instance pointer: class_8(D)  Outer instance pointer: class_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = pfe_l2br_create_vlan_stats_table (class_8(D), vlan_stats_size_18(D));
  Function call may change dynamic type:autolibc_memset (&stats_index, 0, 128);
  Function call may change dynamic type:isa_init (&l2_bridge_instance.domains, &l2_bridge_instance_domains_isa_def);
  Function call may change dynamic type:isa_init (&l2_bridge_instance.static_entries, &l2_bridge_instance_statics_isa_def);
  Function call may change dynamic type:autolibc_memset (&l2_bridge_instance, 0, 5632);
Determining dynamic type for call: pfe_l2br_create_mandatory_domains (class_8(D), &bridge, def_vlan_14(D), def_aging_time_23(D));
  Starting walk at: pfe_l2br_create_mandatory_domains (class_8(D), &bridge, def_vlan_14(D), def_aging_time_23(D));
  instance pointer: &bridge  Outer instance pointer: bridge offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = pfe_l2br_create_vlan_stats_table (class_8(D), vlan_stats_size_18(D));
  Function call may change dynamic type:autolibc_memset (&stats_index, 0, 128);
  Function call may change dynamic type:isa_init (&l2_bridge_instance.domains, &l2_bridge_instance_domains_isa_def);
  Function call may change dynamic type:isa_init (&l2_bridge_instance.static_entries, &l2_bridge_instance_statics_isa_def);
  Function call may change dynamic type:autolibc_memset (&l2_bridge_instance, 0, 5632);
Determining dynamic type for call: _2 = pfe_l2br_create_default_domain (_1, def_vlan_18(D));
  Starting walk at: _2 = pfe_l2br_create_default_domain (_1, def_vlan_18(D));
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = pfe_l2br_create_fallback_domain (_3);
  Starting walk at: _5 = pfe_l2br_create_fallback_domain (_3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_l2br_create_default_domain (_1, def_vlan_18(D));
Determining dynamic type for call: _10 = pfe_l2br_set_mac_aging_timeout (_9, def_aging_time_25(D));
  Starting walk at: _10 = pfe_l2br_set_mac_aging_timeout (_9, def_aging_time_25(D));
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_class_set_default_vlan (class_23(D), def_vlan_18(D));
  Function call may change dynamic type:_5 = pfe_l2br_create_fallback_domain (_3);
  Function call may change dynamic type:_2 = pfe_l2br_create_default_domain (_1, def_vlan_18(D));
Determining dynamic type for call: pfe_l2br_destroy (_14);
  Starting walk at: pfe_l2br_destroy (_14);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not enable L2 bridge aging in FW\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2948, "");
  Function call may change dynamic type:_13 = pfe_feature_mgr_enable ("l2_bridge_aging");
  Function call may change dynamic type:_12 = pfe_feature_mgr_is_available ("l2_bridge_aging");
  Function call may change dynamic type:_10 = pfe_l2br_set_mac_aging_timeout (_9, def_aging_time_25(D));
  Function call may change dynamic type:pfe_class_set_default_vlan (class_23(D), def_vlan_18(D));
  Function call may change dynamic type:_5 = pfe_l2br_create_fallback_domain (_3);
  Function call may change dynamic type:_2 = pfe_l2br_create_default_domain (_1, def_vlan_18(D));
Determining dynamic type for call: pfe_l2br_destroy (_11);
  Starting walk at: pfe_l2br_destroy (_11);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = pfe_l2br_set_mac_aging_timeout (_9, def_aging_time_25(D));
  Function call may change dynamic type:pfe_class_set_default_vlan (class_23(D), def_vlan_18(D));
  Function call may change dynamic type:_5 = pfe_l2br_create_fallback_domain (_3);
  Function call may change dynamic type:_2 = pfe_l2br_create_default_domain (_1, def_vlan_18(D));
Determining dynamic type for call: pfe_l2br_destroy (_6);
  Starting walk at: pfe_l2br_destroy (_6);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = pfe_l2br_create_fallback_domain (_3);
  Function call may change dynamic type:_2 = pfe_l2br_create_default_domain (_1, def_vlan_18(D));
Determining dynamic type for call: pfe_l2br_destroy (_3);
  Starting walk at: pfe_l2br_destroy (_3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_l2br_create_default_domain (_1, def_vlan_18(D));
Determining dynamic type for call: ret_4 = pfe_l2br_flush (bridge_2(D), 0);
  Starting walk at: ret_4 = pfe_l2br_flush (bridge_2(D), 0);
  instance pointer: bridge_2(D)  Outer instance pointer: bridge_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_4 = pfe_l2br_flush (bridge_2(D), 1);
  Starting walk at: ret_4 = pfe_l2br_flush (bridge_2(D), 1);
  instance pointer: bridge_2(D)  Outer instance pointer: bridge_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_4 = pfe_l2br_flush (bridge_2(D), 2);
  Starting walk at: ret_4 = pfe_l2br_flush (bridge_2(D), 2);
  instance pointer: bridge_2(D)  Outer instance pointer: bridge_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
  Starting walk at: pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
  instance pointer: _16  Outer instance pointer: _16 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
  Starting walk at: pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
  instance pointer: &l2t_iter  Outer instance pointer: l2t_iter offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
  Starting walk at: pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
  instance pointer: &entry  Outer instance pointer: entry offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_8 = pfe_l2br_flush_learned_mac_table.isra.0 (_17, &entry, &l2t_iter);
  Starting walk at: ret_8 = pfe_l2br_flush_learned_mac_table.isra.0 (_17, &entry, &l2t_iter);
  instance pointer: _17  Outer instance pointer: bridge_4(D) offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
Determining dynamic type for call: ret_8 = pfe_l2br_flush_learned_mac_table.isra.0 (_17, &entry, &l2t_iter);
  Starting walk at: ret_8 = pfe_l2br_flush_learned_mac_table.isra.0 (_17, &entry, &l2t_iter);
  instance pointer: &entry  Outer instance pointer: entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
Determining dynamic type for call: ret_8 = pfe_l2br_flush_learned_mac_table.isra.0 (_17, &entry, &l2t_iter);
  Starting walk at: ret_8 = pfe_l2br_flush_learned_mac_table.isra.0 (_17, &entry, &l2t_iter);
  instance pointer: &l2t_iter  Outer instance pointer: l2t_iter offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
Determining dynamic type for call: ret_10 = pfe_l2br_flush_static_mac_table (bridge_4(D));
  Starting walk at: ret_10 = pfe_l2br_flush_static_mac_table (bridge_4(D));
  instance pointer: bridge_4(D)  Outer instance pointer: bridge_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
Determining dynamic type for call: ret_12 = pfe_l2br_flush_all_mac_table (bridge_4(D));
  Starting walk at: ret_12 = pfe_l2br_flush_all_mac_table (bridge_4(D));
  instance pointer: bridge_4(D)  Outer instance pointer: bridge_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
Determining dynamic type for call: pfe_l2br_table_destroy_entry_iterator (&l2t_iter, &entry);
  Starting walk at: pfe_l2br_table_destroy_entry_iterator (&l2t_iter, &entry);
  instance pointer: &l2t_iter  Outer instance pointer: l2t_iter offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_l2br_flush_static_mac_table (bridge_4(D));
  Function call may change dynamic type:pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
  Function call may change dynamic type:ret_12 = pfe_l2br_flush_all_mac_table (bridge_4(D));
  Function call may change dynamic type:ret_8 = pfe_l2br_flush_learned_mac_table.isra.0 (_17, &entry, &l2t_iter);
Determining dynamic type for call: pfe_l2br_table_destroy_entry_iterator (&l2t_iter, &entry);
  Starting walk at: pfe_l2br_table_destroy_entry_iterator (&l2t_iter, &entry);
  instance pointer: &entry  Outer instance pointer: entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_l2br_flush_static_mac_table (bridge_4(D));
  Function call may change dynamic type:pfe_l2br_table_create_entry_iterator.isra.0 (_16, &l2t_iter, &entry);
  Function call may change dynamic type:ret_12 = pfe_l2br_flush_all_mac_table (bridge_4(D));
  Function call may change dynamic type:ret_8 = pfe_l2br_flush_learned_mac_table.isra.0 (_17, &entry, &l2t_iter);
Determining dynamic type for call: pfe_l2br_static_entry_destroy_nolock (bridge_8(D), sentry_15);
  Starting walk at: pfe_l2br_static_entry_destroy_nolock (bridge_8(D), sentry_15);
  instance pointer: bridge_8(D)  Outer instance pointer: bridge_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sentry_15 = isa_item (_1, _2);
  Function call may change dynamic type:pfe_l2br_static_entry_destroy_nolock (bridge_8(D), sentry_15);
  Function call may change dynamic type:sentry_15 = isa_item (_1, _2);
Determining dynamic type for call: pfe_l2br_static_entry_destroy_nolock (bridge_8(D), sentry_15);
  Starting walk at: pfe_l2br_static_entry_destroy_nolock (bridge_8(D), sentry_15);
  instance pointer: sentry_15  Outer instance pointer: sentry_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sentry_15 = isa_item (_1, _2);
  Function call may change dynamic type:pfe_l2br_static_entry_destroy_nolock (bridge_8(D), sentry_15);
  Function call may change dynamic type:sentry_15 = isa_item (_1, _2);
Determining dynamic type for call: ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_7(D), sentry_11);
  Starting walk at: ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_7(D), sentry_11);
  instance pointer: bridge_7(D)  Outer instance pointer: bridge_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sentry_11 = isa_item (_1, _2);
  Function call may change dynamic type:ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_7(D), sentry_11);
  Function call may change dynamic type:sentry_11 = isa_item (_1, _2);
Determining dynamic type for call: ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_7(D), sentry_11);
  Starting walk at: ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_7(D), sentry_11);
  instance pointer: sentry_11  Outer instance pointer: sentry_11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sentry_11 = isa_item (_1, _2);
  Function call may change dynamic type:ret_13 = pfe_l2br_static_entry_destroy_nolock (bridge_7(D), sentry_11);
  Function call may change dynamic type:sentry_11 = isa_item (_1, _2);
Determining dynamic type for call: _5 = pfe_l2br_static_entry_match_criterion (bridge_17(D), static_ent_19);
  Starting walk at: _5 = pfe_l2br_static_entry_match_criterion (bridge_17(D), static_ent_19);
  instance pointer: bridge_17(D)  Outer instance pointer: bridge_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:static_ent_19 = isa_item (_1, _6);
  Function call may change dynamic type:static_ent_19 = isa_item (_1, _6);
  Function call may change dynamic type:_5 = pfe_l2br_static_entry_match_criterion (bridge_17(D), static_ent_19);
Determining dynamic type for call: _5 = pfe_l2br_static_entry_match_criterion (bridge_17(D), static_ent_19);
  Starting walk at: _5 = pfe_l2br_static_entry_match_criterion (bridge_17(D), static_ent_19);
  instance pointer: static_ent_19  Outer instance pointer: static_ent_19 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:static_ent_19 = isa_item (_1, _6);
  Function call may change dynamic type:static_ent_19 = isa_item (_1, _6);
  Function call may change dynamic type:_5 = pfe_l2br_static_entry_match_criterion (bridge_17(D), static_ent_19);
Determining dynamic type for call: static_ent_20 = pfe_l2br_static_entry_get_next (bridge_9(D));
  Starting walk at: static_ent_20 = pfe_l2br_static_entry_get_next (bridge_9(D));
  instance pointer: bridge_9(D)  Outer instance pointer: bridge_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_1, arg2_14(D), 6);
  Function call may change dynamic type:autolibc_memcpy (_6, arg2_14(D), 6);
Determining dynamic type for call: ret_5 = pfe_l2br_static_entry_destroy_nolock (bridge_2(D), static_ent_3(D));
  Starting walk at: ret_5 = pfe_l2br_static_entry_destroy_nolock (bridge_2(D), static_ent_3(D));
  instance pointer: bridge_2(D)  Outer instance pointer: bridge_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_5 = pfe_l2br_static_entry_destroy_nolock (bridge_2(D), static_ent_3(D));
  Starting walk at: ret_5 = pfe_l2br_static_entry_destroy_nolock (bridge_2(D), static_ent_3(D));
  instance pointer: static_ent_3(D)  Outer instance pointer: static_ent_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_33 = pfe_l2br_set_static_entry (bridge_19(D), vlan_22(D), mac_23(D), new_fw_list_31(D), &static_entry);
  Starting walk at: ret_33 = pfe_l2br_set_static_entry (bridge_19(D), vlan_22(D), mac_23(D), new_fw_list_31(D), &static_entry);
  instance pointer: bridge_19(D)  Outer instance pointer: bridge_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_9, mac_23(D), 6);
  Function call may change dynamic type:autolibc_memset (_7, 0, 48);
  Function call may change dynamic type:_7 = isa_reserve (_6);
  Function call may change dynamic type:_4 = autolibc_memcmp (_3, mac_23(D), 6);
  Function call may change dynamic type:static_ent_tmp_21 = isa_item (_1, index_11);
Determining dynamic type for call: ret_33 = pfe_l2br_set_static_entry (bridge_19(D), vlan_22(D), mac_23(D), new_fw_list_31(D), &static_entry);
  Starting walk at: ret_33 = pfe_l2br_set_static_entry (bridge_19(D), vlan_22(D), mac_23(D), new_fw_list_31(D), &static_entry);
  instance pointer: mac_23(D)  Outer instance pointer: mac_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_9, mac_23(D), 6);
  Function call may change dynamic type:autolibc_memset (_7, 0, 48);
  Function call may change dynamic type:_7 = isa_reserve (_6);
  Function call may change dynamic type:_4 = autolibc_memcmp (_3, mac_23(D), 6);
  Function call may change dynamic type:static_ent_tmp_21 = isa_item (_1, index_11);
Determining dynamic type for call: ret_33 = pfe_l2br_set_static_entry (bridge_19(D), vlan_22(D), mac_23(D), new_fw_list_31(D), &static_entry);
  Starting walk at: ret_33 = pfe_l2br_set_static_entry (bridge_19(D), vlan_22(D), mac_23(D), new_fw_list_31(D), &static_entry);
  instance pointer: &static_entry  Outer instance pointer: static_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_9, mac_23(D), 6);
  Function call may change dynamic type:autolibc_memset (_7, 0, 48);
  Function call may change dynamic type:_7 = isa_reserve (_6);
  Function call may change dynamic type:_4 = autolibc_memcmp (_3, mac_23(D), 6);
  Function call may change dynamic type:static_ent_tmp_21 = isa_item (_1, index_11);
Determining dynamic type for call: _7 = pfe_l2br_domain_match_if_criterion (domain_23(D), phy_if_28);
  Starting walk at: _7 = pfe_l2br_domain_match_if_criterion (domain_23(D), phy_if_28);
  instance pointer: domain_23(D)  Outer instance pointer: domain_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_7 = pfe_l2br_domain_match_if_criterion (domain_23(D), phy_if_28);
Determining dynamic type for call: _7 = pfe_l2br_domain_match_if_criterion (domain_23(D), phy_if_28);
  Starting walk at: _7 = pfe_l2br_domain_match_if_criterion (domain_23(D), phy_if_28);
  instance pointer: phy_if_28  Outer instance pointer: phy_if_28 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_7 = pfe_l2br_domain_match_if_criterion (domain_23(D), phy_if_28);
Determining dynamic type for call: phy_if_16 = pfe_l2br_domain_get_next_if (domain_5(D));
  Starting walk at: phy_if_16 = pfe_l2br_domain_get_next_if (domain_5(D));
  instance pointer: domain_5(D)  Outer instance pointer: domain_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  Starting walk at: ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  instance pointer: domain_5(D)  Outer instance pointer: domain_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_iterator_create (&l2t_iter);
  Function call may change dynamic type:pfe_l2br_table_entry_create (_3, &entry);
Determining dynamic type for call: ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  Starting walk at: ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  instance pointer: bridge_6  Outer instance pointer: bridge_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_iterator_create (&l2t_iter);
  Function call may change dynamic type:pfe_l2br_table_entry_create (_3, &entry);
Determining dynamic type for call: ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  Starting walk at: ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  instance pointer: &l2t_iter  Outer instance pointer: l2t_iter offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_iterator_create (&l2t_iter);
  Function call may change dynamic type:pfe_l2br_table_entry_create (_3, &entry);
Determining dynamic type for call: ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  Starting walk at: ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  instance pointer: &entry  Outer instance pointer: entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_iterator_create (&l2t_iter);
  Function call may change dynamic type:pfe_l2br_table_entry_create (_3, &entry);
Determining dynamic type for call: ret_23 = pfe_l2br_domain_flush_by_if_static.isra.0 (domain_19(D), bridge_20(D), iface_bitflag_21(D));
  Starting walk at: ret_23 = pfe_l2br_domain_flush_by_if_static.isra.0 (domain_19(D), bridge_20(D), iface_bitflag_21(D));
  instance pointer: domain_19(D)  Outer instance pointer: domain_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_23 = pfe_l2br_domain_flush_by_if_static.isra.0 (domain_19(D), bridge_20(D), iface_bitflag_21(D));
  Starting walk at: ret_23 = pfe_l2br_domain_flush_by_if_static.isra.0 (domain_19(D), bridge_20(D), iface_bitflag_21(D));
  instance pointer: bridge_20(D)  Outer instance pointer: bridge_20(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_27 = pfe_l2br_update_hw_entry (domain_23(D));
  Starting walk at: ret_27 = pfe_l2br_update_hw_entry (domain_23(D));
  instance pointer: domain_23(D)  Outer instance pointer: domain_23(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_27 = pfe_l2br_update_hw_entry (domain_22(D));
  Starting walk at: ret_27 = pfe_l2br_update_hw_entry (domain_22(D));
  instance pointer: domain_22(D)  Outer instance pointer: domain_22(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_10 = pfe_l2br_update_hw_entry (domain_5(D));
  Starting walk at: ret_10 = pfe_l2br_update_hw_entry (domain_5(D));
  instance pointer: domain_5(D)  Outer instance pointer: domain_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_10 = pfe_l2br_update_hw_entry (domain_5(D));
  Starting walk at: ret_10 = pfe_l2br_update_hw_entry (domain_5(D));
  instance pointer: domain_5(D)  Outer instance pointer: domain_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _14 = pfe_l2br_update_hw_entry (domain_20);
  Starting walk at: _14 = pfe_l2br_update_hw_entry (domain_20);
  instance pointer: domain_20  Outer instance pointer: domain_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_class_get_mmap (_2, 0, &class_mmap);
  Function call may change dynamic type:autolibc_memset (domain_20, 0, 72);
  Function call may change dynamic type:domain_20 = isa_reserve (_1);
Determining dynamic type for call: ret_33 = pfe_l2br_domain_create (bridge_23(D), vlan_31(D));
  Starting walk at: ret_33 = pfe_l2br_domain_create (bridge_23(D), vlan_31(D));
  instance pointer: bridge_23(D)  Outer instance pointer: bridge_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = pfe_feature_mgr_enable ("software_vlan_table");
  Function call may change dynamic type:_2 = pfe_class_get_mmap (_1, 0, &class_mmap);
  Function call may change dynamic type:pfe_feature_mgr_disable ("software_vlan_table");
  Function call may change dynamic type:ret_28 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "vlan_hash", &vlan_hash_addr);
Determining dynamic type for call: domain_35 = pfe_l2br_get_first_domain (bridge_23(D), 1, _16);
  Starting walk at: domain_35 = pfe_l2br_get_first_domain (bridge_23(D), 1, _16);
  instance pointer: bridge_23(D)  Outer instance pointer: bridge_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_33 = pfe_l2br_domain_create (bridge_23(D), vlan_31(D));
  Function call may change dynamic type:_13 = pfe_feature_mgr_enable ("software_vlan_table");
  Function call may change dynamic type:_2 = pfe_class_get_mmap (_1, 0, &class_mmap);
  Function call may change dynamic type:pfe_feature_mgr_disable ("software_vlan_table");
  Function call may change dynamic type:ret_28 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "vlan_hash", &vlan_hash_addr);
Determining dynamic type for call: domain_35 = pfe_l2br_get_first_domain (bridge_23(D), 1, _16);
  Starting walk at: domain_35 = pfe_l2br_get_first_domain (bridge_23(D), 1, _16);
  instance pointer: _16  Outer instance pointer: _16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_33 = pfe_l2br_domain_create (bridge_23(D), vlan_31(D));
  Function call may change dynamic type:_13 = pfe_feature_mgr_enable ("software_vlan_table");
  Function call may change dynamic type:_2 = pfe_class_get_mmap (_1, 0, &class_mmap);
  Function call may change dynamic type:pfe_feature_mgr_disable ("software_vlan_table");
  Function call may change dynamic type:ret_28 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "vlan_hash", &vlan_hash_addr);
Determining dynamic type for call: _17 = pfe_l2br_update_hw_entry (domain_35);
  Starting walk at: _17 = pfe_l2br_update_hw_entry (domain_35);
  instance pointer: domain_35  Outer instance pointer: domain_35 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:domain_35 = pfe_l2br_get_first_domain (bridge_23(D), 1, _16);
  Function call may change dynamic type:ret_33 = pfe_l2br_domain_create (bridge_23(D), vlan_31(D));
  Function call may change dynamic type:_13 = pfe_feature_mgr_enable ("software_vlan_table");
  Function call may change dynamic type:_2 = pfe_class_get_mmap (_1, 0, &class_mmap);
  Function call may change dynamic type:pfe_feature_mgr_disable ("software_vlan_table");
  Function call may change dynamic type:ret_28 = pfe_feature_mgr_table_get_payload ("software_vlan_table", 1, "vlan_hash", &vlan_hash_addr);
Determining dynamic type for call: ret_24 = pfe_l2br_delete_vlan_hash_entry (domain_19(D));
  Starting walk at: ret_24 = pfe_l2br_delete_vlan_hash_entry (domain_19(D));
  instance pointer: domain_19(D)  Outer instance pointer: domain_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_feature_mgr_is_available ("software_vlan_table");
Determining dynamic type for call: ret_29 = pfe_l2br_domain_destroy_instance (domain_19(D));
  Starting walk at: ret_29 = pfe_l2br_domain_destroy_instance (domain_19(D));
  instance pointer: domain_19(D)  Outer instance pointer: domain_19(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_table_entry_destroy (_6);
  Function call may change dynamic type:ret_24 = pfe_l2br_delete_vlan_hash_entry (domain_19(D));
  Function call may change dynamic type:_2 = pfe_feature_mgr_is_available ("software_vlan_table");
  Function call may change dynamic type:ret_22 = pfe_l2br_table_del_entry (_4, _5);
Determining dynamic type for call: ret_7 = pfe_l2br_update_hw_entry (domain_6(D));
  Starting walk at: ret_7 = pfe_l2br_update_hw_entry (domain_6(D));
  instance pointer: domain_6(D)  Outer instance pointer: domain_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_8 = pfe_l2br_update_hw_entry (domain_6(D));
  Starting walk at: ret_8 = pfe_l2br_update_hw_entry (domain_6(D));
  instance pointer: domain_6(D)  Outer instance pointer: domain_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_7 = pfe_l2br_update_hw_entry (domain_6(D));
Determining dynamic type for call: _3 = pfe_l2br_get_first_domain (bridge_9(D), 1, _2);
  Starting walk at: _3 = pfe_l2br_get_first_domain (bridge_9(D), 1, _2);
  instance pointer: bridge_9(D)  Outer instance pointer: bridge_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_l2br_get_first_domain (bridge_9(D), 1, _2);
  Starting walk at: _3 = pfe_l2br_get_first_domain (bridge_9(D), 1, _2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_6 = pfe_l2br_domain_create.part.0 (bridge_9(D), vlan_7(D));
  Starting walk at: ret_6 = pfe_l2br_domain_create.part.0 (bridge_9(D), vlan_7(D));
  instance pointer: bridge_9(D)  Outer instance pointer: bridge_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_l2br_get_first_domain (bridge_9(D), 1, _2);
Determining dynamic type for call: ret_43 = pfe_l2br_add_vlan_hash_entry (domain_22(D));
  Starting walk at: ret_43 = pfe_l2br_add_vlan_hash_entry (domain_22(D));
  instance pointer: domain_22(D)  Outer instance pointer: domain_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_12 = pfe_feature_mgr_is_available ("software_vlan_table");
  Function call may change dynamic type:ret_38 = pfe_l2br_table_entry_set_action_data (_2, _11);
  Function call may change dynamic type:_5 = pfe_l2br_domain_get_free_stats_index.isra.0 (_50);
  Function call may change dynamic type:ret_25 = pfe_l2br_table_entry_set_vlan (_2, _4);
  Function call may change dynamic type:_3 = pfe_l2br_table_entry_create (_1, _2);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] No more space for vlan statistics.The stats will be added to vlan 0 fallback\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 964, "");
Determining dynamic type for call: pfe_l2br_domain_destroy_log (domain_22(D));
  Starting walk at: pfe_l2br_domain_destroy_log (domain_22(D));
  instance pointer: domain_22(D)  Outer instance pointer: domain_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not add VLAN table entry: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 990, ret_15, "");
  Function call may change dynamic type:ret_43 = pfe_l2br_add_vlan_hash_entry (domain_22(D));
  Function call may change dynamic type:_12 = pfe_feature_mgr_is_available ("software_vlan_table");
  Function call may change dynamic type:ret_38 = pfe_l2br_table_entry_set_action_data (_2, _11);
  Function call may change dynamic type:_5 = pfe_l2br_domain_get_free_stats_index.isra.0 (_50);
  Function call may change dynamic type:ret_25 = pfe_l2br_table_entry_set_vlan (_2, _4);
  Function call may change dynamic type:_3 = pfe_l2br_table_entry_create (_1, _2);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] No more space for vlan statistics.The stats will be added to vlan 0 fallback\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 964, "");
  Function call may change dynamic type:ret_41 = pfe_l2br_table_add_entry (_14, _2);
Determining dynamic type for call: pfe_l2br_domain_destroy_log (domain_22(D));
  Starting walk at: pfe_l2br_domain_destroy_log (domain_22(D));
  instance pointer: domain_22(D)  Outer instance pointer: domain_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_38 = pfe_l2br_table_entry_set_action_data (_2, _11);
  Function call may change dynamic type:_5 = pfe_l2br_domain_get_free_stats_index.isra.0 (_50);
  Function call may change dynamic type:ret_25 = pfe_l2br_table_entry_set_vlan (_2, _4);
  Function call may change dynamic type:_3 = pfe_l2br_table_entry_create (_1, _2);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] No more space for vlan statistics.The stats will be added to vlan 0 fallback\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 964, "");
Determining dynamic type for call: pfe_l2br_domain_destroy_log (domain_22(D));
  Starting walk at: pfe_l2br_domain_destroy_log (domain_22(D));
  instance pointer: domain_22(D)  Outer instance pointer: domain_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_25 = pfe_l2br_table_entry_set_vlan (_2, _4);
  Function call may change dynamic type:_3 = pfe_l2br_table_entry_create (_1, _2);
Determining dynamic type for call: pfe_l2br_domain_destroy_log (domain_22(D));
  Starting walk at: pfe_l2br_domain_destroy_log (domain_22(D));
  instance pointer: domain_22(D)  Outer instance pointer: domain_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = pfe_l2br_table_entry_create (_1, _2);
Determining dynamic type for call: _1 = pfe_l2br_domain_destroy (domain_3(D));
  Starting walk at: _1 = pfe_l2br_domain_destroy (domain_3(D));
  instance pointer: domain_3(D)  Outer instance pointer: domain_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_l2br_update_hw_ll_entry (domain_20(D), _7);
  Starting walk at: pfe_l2br_update_hw_ll_entry (domain_20(D), _7);
  instance pointer: domain_20(D)  Outer instance pointer: domain_20(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_l2br_update_vlan_hash_entry (domain_20(D));
  Starting walk at: pfe_l2br_update_vlan_hash_entry (domain_20(D));
  instance pointer: domain_20(D)  Outer instance pointer: domain_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = pfe_feature_mgr_is_available ("software_vlan_table");
  Function call may change dynamic type:pfe_l2br_update_hw_ll_entry (domain_20(D), _7);
Determining dynamic type for call: ret_30 = pfe_l2br_update_vlan_hash_entry (domain_20(D));
  Starting walk at: ret_30 = pfe_l2br_update_vlan_hash_entry (domain_20(D));
  instance pointer: domain_20(D)  Outer instance pointer: domain_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_11 = pfe_feature_mgr_is_available ("software_vlan_table");
  Function call may change dynamic type:ret_25 = pfe_l2br_table_entry_set_action_data (_9, _10);
  Function call may change dynamic type:_8 = pfe_feature_mgr_is_available ("software_vlan_table");
  Function call may change dynamic type:pfe_l2br_update_hw_ll_entry (domain_20(D), _7);
  Function call may change dynamic type:pfe_l2br_update_vlan_hash_entry (domain_20(D));
Determining dynamic type for call: pfe_l2br_update_hw_ll_entry (domain_20(D), _3);
  Starting walk at: pfe_l2br_update_hw_ll_entry (domain_20(D), _3);
  instance pointer: domain_20(D)  Outer instance pointer: domain_20(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_l2br_update_vlan_hash_entry (domain_20(D));
  Starting walk at: pfe_l2br_update_vlan_hash_entry (domain_20(D));
  instance pointer: domain_20(D)  Outer instance pointer: domain_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = pfe_feature_mgr_is_available ("software_vlan_table");
  Function call may change dynamic type:pfe_l2br_update_hw_ll_entry (domain_20(D), _3);
Determining dynamic type for call: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  instance pointer: _17  Outer instance pointer: _17 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
Determining dynamic type for call: pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_24, _25, &vlan_prev_entry);
  Starting walk at: pfe_vlan_write_to_class (_24, _25, &vlan_prev_entry);
  instance pointer: _24  Outer instance pointer: _24 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_write_to_class (_24, _25, &vlan_prev_entry);
  Starting walk at: pfe_vlan_write_to_class (_24, _25, &vlan_prev_entry);
  instance pointer: &vlan_prev_entry  Outer instance pointer: vlan_prev_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_write_to_class (_26, _65, &vlan_zero_entry);
  Starting walk at: pfe_vlan_write_to_class (_26, _65, &vlan_zero_entry);
  instance pointer: _26  Outer instance pointer: _26 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_write_to_class (_24, _25, &vlan_prev_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_write_to_class (_26, _65, &vlan_zero_entry);
  Starting walk at: pfe_vlan_write_to_class (_26, _65, &vlan_zero_entry);
  instance pointer: &vlan_zero_entry  Outer instance pointer: vlan_zero_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_write_to_class (_24, _25, &vlan_prev_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
  Starting walk at: pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
  instance pointer: _10  Outer instance pointer: _10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
  Starting walk at: pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
  instance pointer: &vlan_tmp_entry  Outer instance pointer: vlan_tmp_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_write_to_class (_12, _3, &vlan_tmp_entry);
  Starting walk at: pfe_vlan_write_to_class (_12, _3, &vlan_tmp_entry);
  instance pointer: _12  Outer instance pointer: _12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_12, _3, &vlan_tmp_entry);
  Starting walk at: pfe_vlan_write_to_class (_12, _3, &vlan_tmp_entry);
  instance pointer: &vlan_tmp_entry  Outer instance pointer: vlan_tmp_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_13, _14, &vlan_zero_entry);
  Starting walk at: pfe_vlan_write_to_class (_13, _14, &vlan_zero_entry);
  instance pointer: _13  Outer instance pointer: _13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_write_to_class (_12, _3, &vlan_tmp_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_13, _14, &vlan_zero_entry);
  Starting walk at: pfe_vlan_write_to_class (_13, _14, &vlan_zero_entry);
  instance pointer: &vlan_zero_entry  Outer instance pointer: vlan_zero_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_write_to_class (_12, _3, &vlan_tmp_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_tmp_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_prev_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_zero_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
Determining dynamic type for call: pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Starting walk at: pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  instance pointer: domain_25(D)  Outer instance pointer: domain_25(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Starting walk at: pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  instance pointer: &vlan_new_entry  Outer instance pointer: vlan_new_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_write_to_class (_14, _3, &vlan_new_entry);
  Starting walk at: pfe_vlan_write_to_class (_14, _3, &vlan_new_entry);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_write_to_class (_14, _3, &vlan_new_entry);
  Starting walk at: pfe_vlan_write_to_class (_14, _3, &vlan_new_entry);
  instance pointer: &vlan_new_entry  Outer instance pointer: vlan_new_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
Determining dynamic type for call: pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
Determining dynamic type for call: ret_33 = pfe_l2br_add_vlan_to_collision_space.isra.0 (_37, &vlan_new_entry, pos_16);
  Starting walk at: ret_33 = pfe_l2br_add_vlan_to_collision_space.isra.0 (_37, &vlan_new_entry, pos_16);
  instance pointer: _37  Outer instance pointer: domain_25(D) offset: 320 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: ret_33 = pfe_l2br_add_vlan_to_collision_space.isra.0 (_37, &vlan_new_entry, pos_16);
  Starting walk at: ret_33 = pfe_l2br_add_vlan_to_collision_space.isra.0 (_37, &vlan_new_entry, pos_16);
  instance pointer: &vlan_new_entry  Outer instance pointer: vlan_new_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Starting walk at: pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  instance pointer: domain_28(D)  Outer instance pointer: domain_28(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Starting walk at: pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  instance pointer: &vlan_new_entry  Outer instance pointer: vlan_new_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
  instance pointer: _15  Outer instance pointer: _15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
Determining dynamic type for call: pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
  Starting walk at: pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_19, _42, &vlan_new_entry);
  Starting walk at: pfe_vlan_write_to_class (_19, _42, &vlan_new_entry);
  instance pointer: _19  Outer instance pointer: _19 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_19, _42, &vlan_new_entry);
  Starting walk at: pfe_vlan_write_to_class (_19, _42, &vlan_new_entry);
  instance pointer: &vlan_new_entry  Outer instance pointer: vlan_new_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
  Function call may change dynamic type:pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
Determining dynamic type for call: pfe_vlan_write_to_class (_11, _3, &vlan_current_entry);
  Starting walk at: pfe_vlan_write_to_class (_11, _3, &vlan_current_entry);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_vlan_write_to_class (_11, _3, &vlan_current_entry);
  Starting walk at: pfe_vlan_write_to_class (_11, _3, &vlan_current_entry);
  instance pointer: &vlan_current_entry  Outer instance pointer: vlan_current_entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  Function call may change dynamic type:pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  Function call may change dynamic type:autolibc_memset (&vlan_current_entry, 0, 16);
  Function call may change dynamic type:autolibc_memset (&vlan_new_entry, 0, 16);
Determining dynamic type for call: pfe_bd_write_to_class.isra.0 (_31, base_28(D), &sw_bd);
  Starting walk at: pfe_bd_write_to_class.isra.0 (_31, base_28(D), &sw_bd);
  instance pointer: _31  Outer instance pointer: _31 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&sw_bd, 0, 8);
Determining dynamic type for call: pfe_bd_write_to_class.isra.0 (_31, base_28(D), &sw_bd);
  Starting walk at: pfe_bd_write_to_class.isra.0 (_31, base_28(D), &sw_bd);
  instance pointer: &sw_bd  Outer instance pointer: sw_bd offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&sw_bd, 0, 8);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_l2br_domain_create.part.0/152:
    callsite  pfe_l2br_domain_create.part.0/152 -> pfe_l2br_config_domain/34 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 352, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_get_first_domain.part.0/151:
  Jump functions of caller  pfe_l2br_domain_destroy_log.part.0/150:
  Jump functions of caller  pfe_l2br_flush_learned_mac_table.isra.0/145:
  Jump functions of caller  pfe_l2br_domain_flush_by_if_static.isra.0/144:
    callsite  pfe_l2br_domain_flush_by_if_static.isra.0/144 -> pfe_l2br_static_entry_destroy_nolock/59 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_table_create_entry_iterator.isra.0/143:
  Jump functions of caller  pfe_l2br_add_vlan_to_collision_space.isra.0/142:
    callsite  pfe_l2br_add_vlan_to_collision_space.isra.0/142 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_add_vlan_to_collision_space.isra.0/142 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_add_vlan_to_collision_space.isra.0/142 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_add_vlan_to_collision_space.isra.0/142 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_add_vlan_to_collision_space.isra.0/142 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_bd_write_to_class.isra.0/141:
  Jump functions of caller  pfe_vlan_write_to_class.part.0/140:
  Jump functions of caller  pfe_vlan_read_from_class.part.0/139:
  Jump functions of caller  pfe_l2br_domain_get_free_stats_index.isra.0/138:
  Jump functions of caller  pfe_class_get_num_of_pes/137:
  Jump functions of caller  isa_isempty/136:
  Jump functions of caller  pfe_feature_mgr_disable/135:
  Jump functions of caller  pfe_feature_mgr_enable/134:
  Jump functions of caller  pfe_class_set_default_vlan/133:
  Jump functions of caller  pfe_class_dmem_heap_free/132:
  Jump functions of caller  pfe_class_get_mmap/131:
  Jump functions of caller  pfe_class_dmem_heap_alloc/130:
  Jump functions of caller  isa_init/129:
  Jump functions of caller  pfe_l2br_table_entry_is_static/128:
  Jump functions of caller  pfe_l2br_table_init/127:
  Jump functions of caller  pfe_l2br_table_entry_set_mac_addr/126:
  Jump functions of caller  autolibc_memcmp/125:
  Jump functions of caller  pfe_phy_if_get_phy/124:
  Jump functions of caller  isa_item/122:
  Jump functions of caller  pfe_l2br_table_get_next/121:
  Jump functions of caller  pfe_l2br_table_entry_get_action_data/120:
  Jump functions of caller  pfe_l2br_table_entry_get_vlan/119:
  Jump functions of caller  pfe_l2br_table_get_first/118:
  Jump functions of caller  pfe_l2br_iterator_destroy/117:
  Jump functions of caller  pfe_l2br_iterator_create/116:
  Jump functions of caller  pfe_phy_if_get_id/115:
  Jump functions of caller  pfe_l2br_table_update_entry/114:
  Jump functions of caller  isa_release/113:
  Jump functions of caller  pfe_l2br_table_entry_destroy/112:
  Jump functions of caller  pfe_l2br_table_del_entry/111:
  Jump functions of caller  pfe_l2br_table_add_entry/110:
  Jump functions of caller  pfe_feature_mgr_is_available/109:
  Jump functions of caller  pfe_l2br_table_entry_set_action_data/108:
  Jump functions of caller  pfe_l2br_table_entry_set_vlan/107:
  Jump functions of caller  pfe_l2br_table_entry_create/106:
  Jump functions of caller  isa_reserve/105:
  Jump functions of caller  pfe_feature_mgr_table_get_payload/104:
  Jump functions of caller  pfe_class_write_dmem/103:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/102:
  Jump functions of caller  pfe_hm_report/101:
  Jump functions of caller  pfe_class_read_dmem/100:
  Jump functions of caller  autolibc_memcpy/99:
  Jump functions of caller  autolibc_memset/98:
  Jump functions of caller  pfe_l2br_get_vlan_stats_index/97:
  Jump functions of caller  pfe_l2br_clear_domain_stats/96:
  Jump functions of caller  pfe_l2br_get_domain_stats/95:
  Jump functions of caller  pfe_l2br_static_entry_get_entry/94:
  Jump functions of caller  pfe_l2br_get_stats/93:
  Jump functions of caller  pfe_l2br_get_number_entries/92:
  Jump functions of caller  pfe_l2br_set_mac_aging_timeout/91:
  Jump functions of caller  pfe_l2br_get_next_domain/90:
    callsite  pfe_l2br_get_next_domain/90 -> pfe_l2br_domain_match_criterion/88 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_get_first_domain/89:
    callsite  pfe_l2br_get_first_domain/89 -> pfe_l2br_get_next_domain/90 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 44864, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_get_first_domain/89 -> pfe_l2br_get_first_domain.part.0/151 : 
  Jump functions of caller  pfe_l2br_domain_match_criterion/88:
  Jump functions of caller  pfe_l2br_get_fallback_domain/87:
  Jump functions of caller  pfe_l2br_get_default_domain/86:
  Jump functions of caller  pfe_l2br_destroy/85:
    callsite  pfe_l2br_destroy/85 -> pfe_l2br_destroy_vlan_stats_table/32 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_destroy/85 -> pfe_l2br_domain_destroy/37 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_destroy/85 -> pfe_l2br_domain_destroy/37 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_create/84:
    callsite  pfe_l2br_create/84 -> pfe_l2br_create_mandatory_domains/83 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pfe_l2br_create/84 -> pfe_l2br_create_vlan_stats_table/31 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pfe_l2br_create_mandatory_domains/83:
    callsite  pfe_l2br_create_mandatory_domains/83 -> pfe_l2br_destroy/85 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_create_mandatory_domains/83 -> pfe_l2br_destroy/85 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_create_mandatory_domains/83 -> pfe_l2br_set_mac_aging_timeout/91 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pfe_l2br_create_mandatory_domains/83 -> pfe_l2br_destroy/85 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_create_mandatory_domains/83 -> pfe_l2br_create_fallback_domain/39 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_create_mandatory_domains/83 -> pfe_l2br_destroy/85 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_create_mandatory_domains/83 -> pfe_l2br_create_default_domain/38 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pfe_l2br_flush_all/82:
    callsite  pfe_l2br_flush_all/82 -> pfe_l2br_flush/79 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_l2br_flush_static/81:
    callsite  pfe_l2br_flush_static/81 -> pfe_l2br_flush/79 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_l2br_flush_learned/80:
    callsite  pfe_l2br_flush_learned/80 -> pfe_l2br_flush/79 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_l2br_flush/79:
    callsite  pfe_l2br_flush/79 -> pfe_l2br_table_destroy_entry_iterator/78 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_flush/79 -> pfe_l2br_flush_learned_mac_table.isra.0/145 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_flush/79 -> pfe_l2br_flush_all_mac_table/75 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_flush/79 -> pfe_l2br_flush_static_mac_table/74 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_flush/79 -> pfe_l2br_table_create_entry_iterator.isra.0/143 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_l2br_table_destroy_entry_iterator/78:
  Jump functions of caller  pfe_l2br_flush_all_mac_table/75:
    callsite  pfe_l2br_flush_all_mac_table/75 -> pfe_l2br_static_entry_destroy_nolock/59 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_flush_static_mac_table/74:
    callsite  pfe_l2br_flush_static_mac_table/74 -> pfe_l2br_static_entry_destroy_nolock/59 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_static_entry_match_criterion/73:
  Jump functions of caller  pfe_l2br_static_entry_get_next/72:
    callsite  pfe_l2br_static_entry_get_next/72 -> pfe_l2br_static_entry_match_criterion/73 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_static_entry_get_first/71:
    callsite  pfe_l2br_static_entry_get_first/71 -> pfe_l2br_static_entry_get_next/72 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 44896, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_static_entry_get_mac/70:
  Jump functions of caller  pfe_l2br_static_entry_get_vlan/69:
  Jump functions of caller  pfe_l2br_static_entry_get_fw_list/68:
  Jump functions of caller  pfe_l2br_static_entry_get_dst_discard_flag/67:
  Jump functions of caller  pfe_l2br_static_entry_get_src_discard_flag/66:
  Jump functions of caller  pfe_l2br_static_entry_get_local_flag/65:
  Jump functions of caller  pfe_l2br_static_entry_set_dst_discard_flag/64:
  Jump functions of caller  pfe_l2br_static_entry_set_src_discard_flag/63:
  Jump functions of caller  pfe_l2br_static_entry_set_local_flag/62:
  Jump functions of caller  pfe_l2br_static_entry_replace_fw_list/61:
  Jump functions of caller  pfe_l2br_static_entry_destroy/60:
    callsite  pfe_l2br_static_entry_destroy/60 -> pfe_l2br_static_entry_destroy_nolock/59 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_static_entry_destroy_nolock/59:
  Jump functions of caller  pfe_l2br_static_entry_create/58:
    callsite  pfe_l2br_static_entry_create/58 -> pfe_l2br_set_static_entry/57 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_l2br_set_static_entry/57:
  Jump functions of caller  pfe_l2br_domain_is_fallback/56:
  Jump functions of caller  pfe_l2br_domain_is_default/55:
  Jump functions of caller  pfe_l2br_domain_get_vlan/54:
  Jump functions of caller  pfe_l2br_domain_get_next_if/53:
    callsite  pfe_l2br_domain_get_next_if/53 -> pfe_l2br_domain_match_if_criterion/51 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_get_first_if/52:
    callsite  pfe_l2br_domain_get_first_if/52 -> pfe_l2br_domain_get_next_if/53 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 416, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_match_if_criterion/51:
  Jump functions of caller  pfe_l2br_domain_get_untag_if_list/50:
  Jump functions of caller  pfe_l2br_domain_get_if_list/49:
  Jump functions of caller  pfe_l2br_domain_flush_by_if/48:
    callsite  pfe_l2br_domain_flush_by_if/48 -> pfe_l2br_domain_flush_by_if_dynamic_static/47 : 
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
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_flush_by_if_dynamic_static/47:
    callsite  pfe_l2br_domain_flush_by_if_dynamic_static/47 -> pfe_l2br_domain_flush_by_if_static.isra.0/144 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_del_if/45:
    callsite  pfe_l2br_domain_del_if/45 -> pfe_l2br_update_hw_entry/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_add_if/44:
    callsite  pfe_l2br_domain_add_if/44 -> pfe_l2br_update_hw_entry/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_get_mcast_action/43:
  Jump functions of caller  pfe_l2br_domain_set_mcast_action/42:
    callsite  pfe_l2br_domain_set_mcast_action/42 -> pfe_l2br_update_hw_entry/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_get_ucast_action/41:
  Jump functions of caller  pfe_l2br_domain_set_ucast_action/40:
    callsite  pfe_l2br_domain_set_ucast_action/40 -> pfe_l2br_update_hw_entry/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_create_fallback_domain/39:
    callsite  pfe_l2br_create_fallback_domain/39 -> pfe_l2br_update_hw_entry/28 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_create_default_domain/38:
    callsite  pfe_l2br_create_default_domain/38 -> pfe_l2br_update_hw_entry/28 : 
       param 0: UNKNOWN
         Aggregate passed by reference:
           offset: 352, cst: 1
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_create_default_domain/38 -> pfe_l2br_get_first_domain/89 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_create_default_domain/38 -> pfe_l2br_domain_create/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_destroy/37:
    callsite  pfe_l2br_domain_destroy/37 -> pfe_l2br_domain_destroy_instance/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_domain_destroy/37 -> pfe_l2br_delete_vlan_hash_entry/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_destroy_instance/36:
    callsite  pfe_l2br_domain_destroy_instance/36 -> pfe_l2br_update_hw_entry/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_domain_destroy_instance/36 -> pfe_l2br_update_hw_entry/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_create/35:
    callsite  pfe_l2br_domain_create/35 -> pfe_l2br_domain_create.part.0/152 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pfe_l2br_domain_create/35 -> pfe_l2br_get_first_domain/89 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_config_domain/34:
    callsite  pfe_l2br_config_domain/34 -> pfe_l2br_domain_destroy_log/33 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_config_domain/34 -> pfe_l2br_add_vlan_hash_entry/26 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_config_domain/34 -> pfe_l2br_domain_destroy_log/33 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_config_domain/34 -> pfe_l2br_domain_get_free_stats_index.isra.0/138 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pfe_l2br_config_domain/34 -> pfe_l2br_domain_destroy_log/33 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_config_domain/34 -> pfe_l2br_domain_destroy_log/33 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_domain_destroy_log/33:
    callsite  pfe_l2br_domain_destroy_log/33 -> pfe_l2br_domain_destroy_log.part.0/150 : 
    callsite  pfe_l2br_domain_destroy_log/33 -> pfe_l2br_domain_destroy/37 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_destroy_vlan_stats_table/32:
  Jump functions of caller  pfe_l2br_create_vlan_stats_table/31:
  Jump functions of caller  pfe_l2br_update_hw_entry/28:
    callsite  pfe_l2br_update_hw_entry/28 -> pfe_l2br_update_vlan_hash_entry/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_update_hw_entry/28 -> pfe_l2br_update_vlan_hash_entry/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_update_hw_entry/28 -> pfe_l2br_update_hw_ll_entry/19 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_update_hw_entry/28 -> pfe_l2br_update_vlan_hash_entry/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_l2br_update_hw_entry/28 -> pfe_l2br_update_hw_ll_entry/19 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_l2br_delete_vlan_hash_entry/27:
    callsite  pfe_l2br_delete_vlan_hash_entry/27 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_delete_vlan_hash_entry/27 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_delete_vlan_hash_entry/27 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_delete_vlan_hash_entry/27 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_delete_vlan_hash_entry/27 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3f
         VR  [0, 63]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_delete_vlan_hash_entry/27 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_delete_vlan_hash_entry/27 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3f
         VR  [0, 63]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_l2br_add_vlan_hash_entry/26:
    callsite  pfe_l2br_add_vlan_hash_entry/26 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3f
         VR  [0, 63]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_add_vlan_hash_entry/26 -> pfe_l2br_add_vlan_to_collision_space.isra.0/142 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_l2br_add_vlan_hash_entry/26 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_add_vlan_hash_entry/26 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3f
         VR  [0, 63]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_add_vlan_hash_entry/26 -> pfe_l2br_vlan_action_to_entry/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_l2br_update_vlan_hash_entry/24:
    callsite  pfe_l2br_update_vlan_hash_entry/24 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_update_vlan_hash_entry/24 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_update_vlan_hash_entry/24 -> pfe_vlan_write_to_class/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3f
         VR  [0, 63]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_update_vlan_hash_entry/24 -> pfe_vlan_read_from_class/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3f
         VR  [0, 63]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_l2br_update_vlan_hash_entry/24 -> pfe_l2br_vlan_action_to_entry/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_l2br_vlan_action_to_entry/23:
  Jump functions of caller  pfe_vlan_read_from_class/22:
    callsite  pfe_vlan_read_from_class/22 -> pfe_vlan_read_from_class.part.0/139 : 
  Jump functions of caller  pfe_vlan_write_to_class/21:
    callsite  pfe_vlan_write_to_class/21 -> pfe_vlan_write_to_class.part.0/140 : 
  Jump functions of caller  pfe_l2br_update_hw_ll_entry/19:
    callsite  pfe_l2br_update_hw_ll_entry/19 -> pfe_bd_write_to_class.isra.0/141 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]

 Propagating constants:

Not considering pfe_l2br_get_vlan_stats_index for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_clear_domain_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_get_domain_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_entry for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_get_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_get_number_entries for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_get_next_domain for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_get_first_domain for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_get_fallback_domain for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_get_default_domain for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_flush_all for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_flush_static for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_flush_learned for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_next for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_first for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_mac for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_vlan for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_fw_list for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_dst_discard_flag for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_src_discard_flag for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_get_local_flag for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_set_dst_discard_flag for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_set_src_discard_flag for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_set_local_flag for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_replace_fw_list for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_static_entry_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_is_fallback for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_is_default for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_get_vlan for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_get_next_if for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_get_first_if for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_get_untag_if_list for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_get_if_list for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_flush_by_if for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_del_if for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_add_if for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_get_mcast_action for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_set_mcast_action for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_get_ucast_action for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_set_ucast_action for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_domain_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_delete_vlan_hash_entry for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_add_vlan_hash_entry for cloning; -fipa-cp-clone disabled.
Not considering pfe_l2br_update_vlan_hash_entry for cloning; -fipa-cp-clone disabled.

overall_size: 2540, max_new_size: 11001
 - context independent values, size: 7, time_benefit: 1.000000
 - context independent values, size: 7, time_benefit: 1.000000
 - context independent values, size: 7, time_benefit: 1.000000
 - context independent values, size: 86, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_l2br_domain_create.part.0/152:
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
  Node: pfe_l2br_get_first_domain.part.0/151:
  Node: pfe_l2br_domain_destroy_log.part.0/150:
  Node: pfe_l2br_flush_learned_mac_table.isra.0/145:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_l2br_table_t * const * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_table_entry_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_table_iterator_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_l2br_domain_flush_by_if_static.isra.0/144:
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
  Node: pfe_l2br_table_create_entry_iterator.isra.0/143:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_table_iterator_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_table_entry_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_l2br_add_vlan_to_collision_space.isra.0/142:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_l2br_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct l2br_vlan_hash_entry_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_bd_write_to_class.isra.0/141:
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
         const union pfe_ct_bd_entry_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_vlan_write_to_class.part.0/140:
  Node: pfe_vlan_read_from_class.part.0/139:
  Node: pfe_l2br_domain_get_free_stats_index.isra.0/138:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_l2br_get_vlan_stats_index/97:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_clear_domain_stats/96:
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
  Node: pfe_l2br_get_domain_stats/95:
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
  Node: pfe_l2br_static_entry_get_entry/94:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_get_stats/93:
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
  Node: pfe_l2br_get_number_entries/92:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_set_mac_aging_timeout/91:
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
  Node: pfe_l2br_get_next_domain/90:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_get_first_domain/89:
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
  Node: pfe_l2br_domain_match_criterion/88:
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
  Node: pfe_l2br_get_fallback_domain/87:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_get_default_domain/86:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_destroy/85:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_create/84:
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
  Node: pfe_l2br_create_mandatory_domains/83:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_t * * ~[0B, 0B]
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
  Node: pfe_l2br_flush_all/82:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_flush_static/81:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_flush_learned/80:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_flush/79:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 2 [loc_time: 5, loc_size: 16, prop_time: 0, prop_size: 0]
               1 [loc_time: 5, loc_size: 14, prop_time: 0, prop_size: 0]
               0 [loc_time: 5, loc_size: 14, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x3
         pfe_l2br_flush_types [0, 2]
        AGGS VARIABLE
  Node: pfe_l2br_table_destroy_entry_iterator/78:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_table_iterator_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_table_entry_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_l2br_flush_all_mac_table/75:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_l2br_flush_static_mac_table/74:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_l2br_static_entry_match_criterion/73:
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
  Node: pfe_l2br_static_entry_get_next/72:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_static_entry_get_first/71:
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
  Node: pfe_l2br_static_entry_get_mac/70:
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
  Node: pfe_l2br_static_entry_get_vlan/69:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_static_entry_get_fw_list/68:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_static_entry_get_dst_discard_flag/67:
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
  Node: pfe_l2br_static_entry_get_src_discard_flag/66:
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
  Node: pfe_l2br_static_entry_get_local_flag/65:
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
  Node: pfe_l2br_static_entry_set_dst_discard_flag/64:
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
  Node: pfe_l2br_static_entry_set_src_discard_flag/63:
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
  Node: pfe_l2br_static_entry_set_local_flag/62:
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
  Node: pfe_l2br_static_entry_replace_fw_list/61:
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
  Node: pfe_l2br_static_entry_destroy/60:
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
  Node: pfe_l2br_static_entry_destroy_nolock/59:
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
  Node: pfe_l2br_static_entry_create/58:
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
  Node: pfe_l2br_set_static_entry/57:
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
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_static_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_l2br_domain_is_fallback/56:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_domain_is_default/55:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_domain_get_vlan/54:
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
  Node: pfe_l2br_domain_get_next_if/53:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_domain_get_first_if/52:
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
  Node: pfe_l2br_domain_match_if_criterion/51:
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
  Node: pfe_l2br_domain_get_untag_if_list/50:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_domain_get_if_list/49:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_domain_flush_by_if/48:
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
  Node: pfe_l2br_domain_flush_by_if_dynamic_static/47:
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
         struct pfe_l2br_table_iterator_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_l2br_table_entry_t * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_l2br_domain_del_if/45:
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
  Node: pfe_l2br_domain_add_if/44:
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
  Node: pfe_l2br_domain_get_mcast_action/43:
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
  Node: pfe_l2br_domain_set_mcast_action/42:
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
  Node: pfe_l2br_domain_get_ucast_action/41:
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
  Node: pfe_l2br_domain_set_ucast_action/40:
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
  Node: pfe_l2br_create_fallback_domain/39:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_l2br_create_default_domain/38:
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
  Node: pfe_l2br_domain_destroy/37:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_domain_destroy_instance/36:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_l2br_domain_create/35:
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
  Node: pfe_l2br_config_domain/34:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        ref offset 352: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: pfe_l2br_domain_destroy_log/33:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_l2br_destroy_vlan_stats_table/32:
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
  Node: pfe_l2br_create_vlan_stats_table/31:
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
  Node: pfe_l2br_update_hw_entry/28:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
        ref offset 352: 1 [loc_time: 2, loc_size: 75, prop_time: 0, prop_size: 0]
  Node: pfe_l2br_delete_vlan_hash_entry/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_add_vlan_hash_entry/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_update_vlan_hash_entry/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_l2br_vlan_action_to_entry/23:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct l2br_vlan_hash_entry_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_vlan_read_from_class/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         uint32_t [0, 255]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct l2br_vlan_hash_entry_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_vlan_write_to_class/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         uint32_t [0, 255]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct l2br_vlan_hash_entry_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_l2br_update_hw_ll_entry/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
        ref offset 352: 1 [loc_time: 0, loc_size: 38, prop_time: 0, prop_size: 0]
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of pfe_l2br_config_domain/34 for all known contexts.
Propagated bits info for function pfe_l2br_flush_learned_mac_table.isra.0/145:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_l2br_table_create_entry_iterator.isra.0/143:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_l2br_add_vlan_to_collision_space.isra.0/142:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_bd_write_to_class.isra.0/141:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_l2br_create_mandatory_domains/83:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_l2br_flush/79:
 param 1: value = 0x0, mask = 0x3
Propagated bits info for function pfe_l2br_table_destroy_entry_iterator/78:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_l2br_set_static_entry/57:
 param 4: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_l2br_domain_flush_by_if_dynamic_static/47:
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_l2br_vlan_action_to_entry/23:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_vlan_read_from_class/22:
 param 1: value = 0x0, mask = 0xff
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_vlan_write_to_class/21:
 param 1: value = 0x0, mask = 0xff
 param 2: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: pfe_l2br_config_domain/34
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_l2br_config_domain.constprop.0/153 (pfe_l2br_config_domain.constprop) @07710380
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of pfe_l2br_config_domain/34
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_l2br_domain_create.part.0/152 (731110809 (estimated locally),0.68 per call) 
  Calls: pfe_l2br_table_entry_create/106 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_destroy_log/33 (201326592 (estimated locally),0.19 per call) pfe_l2br_table_entry_set_vlan/107 (872415233 (estimated locally),0.81 per call) pfe_l2br_domain_destroy_log/33 (436207616 (estimated locally),0.41 per call) pfe_l2br_domain_get_free_stats_index.isra.0/138 (436207616 (estimated locally),0.41 per call) pfe_hm_report/101 (143948513 (estimated locally),0.13 per call) oal_util_raise_dem_for_drv_runtime_err/102 (143948513 (estimated locally),0.13 per call) pfe_l2br_table_entry_set_action_data/108 (436207616 (estimated locally),0.41 per call) pfe_l2br_domain_destroy_log/33 (218103808 (estimated locally),0.20 per call) pfe_feature_mgr_is_available/109 (218103808 (estimated locally),0.20 per call) pfe_l2br_add_vlan_hash_entry/26 (74155295 (estimated locally),0.07 per call) pfe_l2br_table_add_entry/110 (143948513 (estimated locally),0.13 per call) pfe_hm_report/101 (71974257 (estimated locally),0.07 per call) oal_util_raise_dem_for_drv_runtime_err/102 (71974257 (estimated locally),0.07 per call) pfe_l2br_domain_destroy_log/33 (71974257 (estimated locally),0.07 per call) 
pfe_l2br_domain_create.part.0/152 (pfe_l2br_domain_create.part.0) @072c7a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_l2br_domain_create/35 (475882376 (estimated locally),0.44 per call) 
  Calls: isa_reserve/105 (1073741824 (estimated locally),1.00 per call) autolibc_memset/98 (731110809 (estimated locally),0.68 per call) pfe_l2br_config_domain.constprop/153 (731110809 (estimated locally),0.68 per call) 
pfe_l2br_get_first_domain.part.0/151 (pfe_l2br_get_first_domain.part.0) @077108c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_l2br_get_first_domain/89 (268435456 (estimated locally),0.25 per call) 
  Calls: pfe_hm_report/101 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/102 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_domain_destroy_log.part.0/150 (pfe_l2br_domain_destroy_log.part.0) @07733380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_l2br_domain_destroy_log/33 (354334800 (estimated locally),0.33 per call) 
  Calls: pfe_hm_report/101 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/102 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_flush_learned_mac_table.isra.0/145 (pfe_l2br_flush_learned_mac_table.isra.0) @072c77e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111602 (estimated locally) body local optimize_size
  Called by: pfe_l2br_flush/79 (268435456 (estimated locally),0.25 per call) 
  Calls: pfe_l2br_table_get_next/121 (955630223 (estimated locally),8.09 per call) oal_util_raise_dem_for_drv_runtime_err/102 (104068131 (estimated locally),0.88 per call) pfe_hm_report/101 (104068131 (estimated locally),0.88 per call) pfe_l2br_table_del_entry/111 (315357973 (estimated locally),2.67 per call) pfe_l2br_table_entry_is_static/128 (955630223 (estimated locally),8.09 per call) pfe_l2br_table_get_first/118 (118111602 (estimated locally),1.00 per call) 
pfe_l2br_domain_flush_by_if_static.isra.0/144 (pfe_l2br_domain_flush_by_if_static.isra.0) @072c7540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_l2br_domain_flush_by_if_dynamic_static/47 (357913939 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (29215879 (estimated locally),0.25 per call) pfe_hm_report/101 (29215879 (estimated locally),0.25 per call) pfe_l2br_static_entry_destroy_nolock/59 (88532967 (estimated locally),0.75 per call) oal_util_raise_dem_for_drv_runtime_err/102 (166566348 (estimated locally),1.41 per call) pfe_hm_report/101 (166566348 (estimated locally),1.41 per call) isa_item/122 (955630223 (estimated locally),8.09 per call) 
pfe_l2br_table_create_entry_iterator.isra.0/143 (pfe_l2br_table_create_entry_iterator.isra.0) @06ecd7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_flush/79 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_l2br_iterator_create/116 (1073741824 (estimated locally),1.00 per call) pfe_l2br_table_entry_create/106 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_add_vlan_to_collision_space.isra.0/142 (pfe_l2br_add_vlan_to_collision_space.isra.0) @06ecd540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:348071309 (estimated locally) body local optimize_size
  Called by: pfe_l2br_add_vlan_hash_entry/26 (114863532 (estimated locally),0.52 per call) 
  Calls: pfe_vlan_write_to_class/21 (37904965 (estimated locally),0.11 per call) pfe_vlan_write_to_class/21 (37904965 (estimated locally),0.11 per call) pfe_vlan_read_from_class/22 (958878292 (estimated locally),2.75 per call) pfe_vlan_read_from_class/22 (37904966 (estimated locally),0.11 per call) pfe_vlan_read_from_class/22 (114863532 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/102 (57431766 (estimated locally),0.17 per call) pfe_hm_report/101 (57431766 (estimated locally),0.17 per call) pfe_feature_mgr_table_get_payload/104 (174035655 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/102 (174035655 (estimated locally),0.50 per call) pfe_hm_report/101 (174035655 (estimated locally),0.50 per call) pfe_feature_mgr_table_get_payload/104 (348071309 (estimated locally),1.00 per call) autolibc_memset/98 (348071309 (estimated locally),1.00 per call) autolibc_memset/98 (348071309 (estimated locally),1.00 per call) 
pfe_bd_write_to_class.isra.0/141 (pfe_bd_write_to_class.isra.0) @070cc380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_update_hw_ll_entry/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_class_write_dmem/103 (1073741824 (estimated locally),1.00 per call) 
pfe_vlan_write_to_class.part.0/140 (pfe_vlan_write_to_class.part.0) @0702c9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_vlan_write_to_class/21 (354334800 (estimated locally),0.33 per call) 
  Calls: pfe_hm_report/101 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/102 (1073741824 (estimated locally),1.00 per call) 
pfe_vlan_read_from_class.part.0/139 (pfe_vlan_read_from_class.part.0) @0702c700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_vlan_read_from_class/22 (354334800 (estimated locally),0.33 per call) 
  Calls: pfe_hm_report/101 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/102 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_domain_get_free_stats_index.isra.0/138 (pfe_l2br_domain_get_free_stats_index.isra.0) @06e7db60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: stats_index/13 (read)stats_index/13 (write)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (436207616 (estimated locally),0.41 per call) 
  Calls: 
pfe_class_get_num_of_pes/137 (pfe_class_get_num_of_pes) @07844460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_get_domain_stats/95 (114863532 (estimated locally),1.00 per call) 
  Calls: 
isa_isempty/136 (isa_isempty) @07829a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_destroy/85 (872415233 (estimated locally),0.81 per call) 
  Calls: 
pfe_feature_mgr_disable/135 (pfe_feature_mgr_disable) @07829700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_create_default_domain/38 (83020644 (estimated locally),0.08 per call) 
  Calls: 
pfe_feature_mgr_enable/134 (pfe_feature_mgr_enable) @07829540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_create_mandatory_domains/83 (86812027 (estimated locally),0.08 per call) pfe_l2br_create_default_domain/38 (762356696 (estimated locally),0.71 per call) 
  Calls: 
pfe_class_set_default_vlan/133 (pfe_class_set_default_vlan) @07829460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_create_mandatory_domains/83 (526133494 (estimated locally),0.49 per call) 
  Calls: 
pfe_class_dmem_heap_free/132 (pfe_class_dmem_heap_free) @078292a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_destroy_vlan_stats_table/32 (88583700 (estimated locally),0.08 per call) pfe_l2br_create_vlan_stats_table/31 (88583700 (estimated locally),0.08 per call) 
  Calls: 
pfe_class_get_mmap/131 (pfe_class_get_mmap) @078291c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_create_default_domain/38 (1073741824 (estimated locally),1.00 per call) pfe_l2br_create_fallback_domain/39 (574129754 (estimated locally),0.53 per call) pfe_l2br_destroy_vlan_stats_table/32 (354334802 (estimated locally),0.33 per call) pfe_l2br_create_vlan_stats_table/31 (536870911 (estimated locally),0.50 per call) pfe_l2br_set_mac_aging_timeout/91 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_class_dmem_heap_alloc/130 (pfe_class_dmem_heap_alloc) @078290e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_create_vlan_stats_table/31 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
isa_init/129 (isa_init) @07814e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_create/84 (1073741824 (estimated locally),1.00 per call) pfe_l2br_create/84 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_table_entry_is_static/128 (pfe_l2br_table_entry_is_static) @078149a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_flush_learned_mac_table.isra.0/145 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_l2br_table_init/127 (pfe_l2br_table_init) @078147e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_flush_all_mac_table/75 (118111601 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_table_entry_set_mac_addr/126 (pfe_l2br_table_entry_set_mac_addr) @077fb620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_set_static_entry/57 (375809639 (estimated locally),0.35 per call) 
  Calls: 
autolibc_memcmp/125 (autolibc_memcmp) @077fb460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_static_entry_create/58 (143760716 (estimated locally),2.15 per call) pfe_l2br_static_entry_match_criterion/73 (43465069 (estimated locally),0.04 per call) pfe_l2br_static_entry_match_criterion/73 (214748364 (estimated locally),0.20 per call) 
  Calls: 
pfe_phy_if_get_phy/124 (pfe_phy_if_get_phy) @077e9ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_domain_get_next_if/53 (334846388 (estimated locally),4.32 per call) pfe_l2br_domain_match_criterion/88 (488069346 (estimated locally),0.98 per call) 
  Calls: 
phys.10869/123 (phys) @077f0cf0
  Type: variable definition analyzed alias
  Visibility: prevailing_def_ironly
  References: pfe_index_to_phy_if_id/16 (alias)
  Referring: pfe_l2br_domain_get_first_if/52 (read)
  Availability: available
  Varpool flags: read-only const-value-known
isa_item/122 (isa_item) @077e99a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_get_next_domain/90 (1014686024 (estimated locally),11.41 per call) pfe_l2br_static_entry_get_next/72 (1014686024 (estimated locally),11.41 per call) pfe_l2br_static_entry_create/58 (1014686025 (estimated locally),15.15 per call) pfe_l2br_flush_all_mac_table/75 (955630223 (estimated locally),8.09 per call) pfe_l2br_flush_static_mac_table/74 (955630223 (estimated locally),8.09 per call) pfe_l2br_domain_flush_by_if_static.isra.0/144 (955630223 (estimated locally),8.09 per call) 
  Calls: 
pfe_l2br_table_get_next/121 (pfe_l2br_table_get_next) @077e97e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_get_stats/93 (958878293 (estimated locally),8.35 per call) pfe_l2br_get_number_entries/92 (955630223 (estimated locally),8.09 per call) pfe_l2br_flush_learned_mac_table.isra.0/145 (955630223 (estimated locally),8.09 per call) pfe_l2br_domain_flush_by_if_dynamic_static/47 (955630224 (estimated locally),2.67 per call) 
  Calls: 
pfe_l2br_table_entry_get_action_data/120 (pfe_l2br_table_entry_get_action_data) @077e9700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_domain_flush_by_if_dynamic_static/47 (955630223 (estimated locally),2.67 per call) 
  Calls: 
pfe_l2br_table_entry_get_vlan/119 (pfe_l2br_table_entry_get_vlan) @077e9620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_domain_flush_by_if_dynamic_static/47 (955630223 (estimated locally),2.67 per call) 
  Calls: 
pfe_l2br_table_get_first/118 (pfe_l2br_table_get_first) @077e9540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_get_stats/93 (114863532 (estimated locally),1.00 per call) pfe_l2br_get_number_entries/92 (118111600 (estimated locally),1.00 per call) pfe_l2br_flush_learned_mac_table.isra.0/145 (118111602 (estimated locally),1.00 per call) pfe_l2br_domain_flush_by_if_dynamic_static/47 (118111600 (estimated locally),0.33 per call) 
  Calls: 
pfe_l2br_iterator_destroy/117 (pfe_l2br_iterator_destroy) @077e9380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_domain_flush_by_if/48 (1073741824 (estimated locally),1.00 per call) pfe_l2br_table_destroy_entry_iterator/78 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_iterator_create/116 (pfe_l2br_iterator_create) @077e92a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_get_stats/93 (114863532 (estimated locally),1.00 per call) pfe_l2br_get_number_entries/92 (118111600 (estimated locally),1.00 per call) pfe_l2br_domain_flush_by_if/48 (1073741824 (estimated locally),1.00 per call) pfe_l2br_table_create_entry_iterator.isra.0/143 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_get_id/115 (pfe_phy_if_get_id) @077e9000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_domain_flush_by_if/48 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_del_if/45 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_add_if/44 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_match_if_criterion/51 (268435456 (estimated locally),0.25 per call) 
  Calls: 
pfe_l2br_table_update_entry/114 (pfe_l2br_table_update_entry) @077d09a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_static_entry_set_dst_discard_flag/64 (697932186 (estimated locally),0.65 per call) pfe_l2br_static_entry_set_src_discard_flag/63 (697932186 (estimated locally),0.65 per call) pfe_l2br_static_entry_set_local_flag/62 (697932186 (estimated locally),0.65 per call) pfe_l2br_static_entry_replace_fw_list/61 (697932186 (estimated locally),0.65 per call) pfe_l2br_update_hw_entry/28 (367402669 (estimated locally),0.34 per call) 
  Calls: 
isa_release/113 (isa_release) @077d0540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_create_default_domain/38 (59408921 (estimated locally),0.06 per call) pfe_l2br_static_entry_create/58 (14054671 (estimated locally),0.21 per call) pfe_l2br_domain_destroy/37 (885837006 (estimated locally),0.83 per call) pfe_l2br_create_fallback_domain/39 (68278381 (estimated locally),0.06 per call) pfe_l2br_create_fallback_domain/39 (166497628 (estimated locally),0.16 per call) pfe_l2br_set_static_entry/57 (1010793711 (estimated locally),0.94 per call) pfe_l2br_static_entry_destroy_nolock/59 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_table_entry_destroy/112 (pfe_l2br_table_entry_destroy) @077d0460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_domain_flush_by_if/48 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_destroy/37 (348966093 (estimated locally),0.33 per call) pfe_l2br_table_destroy_entry_iterator/78 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_table_del_entry/111 (pfe_l2br_table_del_entry) @077d0380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_domain_destroy/37 (354334802 (estimated locally),0.33 per call) pfe_l2br_flush_learned_mac_table.isra.0/145 (315357973 (estimated locally),2.67 per call) pfe_l2br_domain_flush_by_if_dynamic_static/47 (107221711 (estimated locally),0.30 per call) pfe_l2br_static_entry_destroy_nolock/59 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_table_add_entry/110 (pfe_l2br_table_add_entry) @077d0000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (143948513 (estimated locally),0.13 per call) pfe_l2br_set_static_entry/57 (93952410 (estimated locally),0.09 per call) 
  Calls: 
pfe_feature_mgr_is_available/109 (pfe_feature_mgr_is_available) @077bbee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (218103808 (estimated locally),0.20 per call) pfe_l2br_create_mandatory_domains/83 (263066747 (estimated locally),0.25 per call) pfe_l2br_domain_destroy/37 (536870913 (estimated locally),0.50 per call) pfe_l2br_update_hw_entry/28 (556670711 (estimated locally),0.52 per call) pfe_l2br_update_hw_entry/28 (173338695 (estimated locally),0.16 per call) pfe_l2br_update_hw_entry/28 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_l2br_table_entry_set_action_data/108 (pfe_l2br_table_entry_set_action_data) @077bbe00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (436207616 (estimated locally),0.41 per call) pfe_l2br_static_entry_set_dst_discard_flag/64 (1073741824 (estimated locally),1.00 per call) pfe_l2br_static_entry_set_src_discard_flag/63 (1073741824 (estimated locally),1.00 per call) pfe_l2br_static_entry_set_local_flag/62 (1073741824 (estimated locally),1.00 per call) pfe_l2br_static_entry_replace_fw_list/61 (1073741824 (estimated locally),1.00 per call) pfe_l2br_update_hw_entry/28 (856416479 (estimated locally),0.80 per call) pfe_l2br_set_static_entry/57 (187904819 (estimated locally),0.17 per call) 
  Calls: 
pfe_l2br_table_entry_set_vlan/107 (pfe_l2br_table_entry_set_vlan) @077bbd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (872415233 (estimated locally),0.81 per call) pfe_l2br_set_static_entry/57 (751619278 (estimated locally),0.70 per call) 
  Calls: 
pfe_l2br_table_entry_create/106 (pfe_l2br_table_entry_create) @077bbc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (1073741824 (estimated locally),1.00 per call) pfe_l2br_get_stats/93 (114863532 (estimated locally),1.00 per call) pfe_l2br_get_number_entries/92 (118111600 (estimated locally),1.00 per call) pfe_l2br_domain_flush_by_if/48 (1073741824 (estimated locally),1.00 per call) pfe_l2br_set_static_entry/57 (1073741824 (estimated locally),1.00 per call) pfe_l2br_table_create_entry_iterator.isra.0/143 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
isa_reserve/105 (isa_reserve) @077bba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_domain_create.part.0/152 (1073741824 (estimated locally),1.00 per call) pfe_l2br_static_entry_create/58 (52418354 (estimated locally),0.78 per call) pfe_l2br_create_fallback_domain/39 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_feature_mgr_table_get_payload/104 (pfe_feature_mgr_table_get_payload) @077bb7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_create_default_domain/38 (251577709 (estimated locally),0.23 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (174035655 (estimated locally),0.50 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (348071309 (estimated locally),1.00 per call) 
  Calls: 
pfe_class_write_dmem/103 (pfe_class_write_dmem) @077bb540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_clear_domain_stats/96 (1073741824 (estimated locally),1.00 per call) pfe_l2br_destroy_vlan_stats_table/32 (177167401 (estimated locally),0.17 per call) pfe_l2br_create_vlan_stats_table/31 (268435456 (estimated locally),0.25 per call) pfe_l2br_set_mac_aging_timeout/91 (354334802 (estimated locally),0.33 per call) pfe_bd_write_to_class.isra.0/141 (1073741824 (estimated locally),1.00 per call) pfe_vlan_write_to_class/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/102 (oal_util_raise_dem_for_drv_runtime_err) @077bb380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (143948513 (estimated locally),0.13 per call) pfe_l2br_config_domain.constprop/153 (71974257 (estimated locally),0.07 per call) pfe_l2br_create_mandatory_domains/83 (28647969 (estimated locally),0.03 per call) pfe_l2br_create_default_domain/38 (62100280 (estimated locally),0.06 per call) pfe_l2br_create_default_domain/38 (311385129 (estimated locally),0.29 per call) pfe_l2br_domain_create/35 (597859448 (estimated locally),0.56 per call) pfe_l2br_get_first_domain.part.0/151 (1073741824 (estimated locally),1.00 per call) pfe_l2br_static_entry_set_dst_discard_flag/64 (146286586 (estimated locally),0.14 per call) pfe_l2br_static_entry_set_dst_discard_flag/64 (375809639 (estimated locally),0.35 per call) pfe_l2br_static_entry_set_src_discard_flag/63 (146286586 (estimated locally),0.14 per call) pfe_l2br_static_entry_set_src_discard_flag/63 (375809639 (estimated locally),0.35 per call) pfe_l2br_static_entry_set_local_flag/62 (146286586 (estimated locally),0.14 per call) pfe_l2br_static_entry_set_local_flag/62 (375809639 (estimated locally),0.35 per call) pfe_l2br_static_entry_replace_fw_list/61 (146286586 (estimated locally),0.14 per call) pfe_l2br_static_entry_replace_fw_list/61 (375809639 (estimated locally),0.35 per call) pfe_l2br_static_entry_create/58 (9828441 (estimated locally),0.15 per call) pfe_l2br_static_entry_create/58 (14544285 (estimated locally),0.22 per call) pfe_l2br_domain_get_first_if/52 (268435456 (estimated locally),0.25 per call) pfe_l2br_domain_del_if/45 (107509388 (estimated locally),0.10 per call) pfe_l2br_domain_destroy_log.part.0/150 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_destroy/37 (187904819 (estimated locally),0.17 per call) pfe_l2br_create_fallback_domain/39 (166497628 (estimated locally),0.16 per call) pfe_l2br_update_hw_entry/28 (116678181 (estimated locally),0.11 per call) pfe_l2br_update_hw_entry/28 (299745768 (estimated locally),0.28 per call) pfe_l2br_destroy_vlan_stats_table/32 (88583700 (estimated locally),0.08 per call) pfe_l2br_destroy_vlan_stats_table/32 (177167401 (estimated locally),0.17 per call) pfe_l2br_create_vlan_stats_table/31 (88583700 (estimated locally),0.08 per call) pfe_l2br_create_vlan_stats_table/31 (268435456 (estimated locally),0.25 per call) pfe_l2br_create_vlan_stats_table/31 (536870911 (estimated locally),0.50 per call) pfe_l2br_flush_learned_mac_table.isra.0/145 (104068131 (estimated locally),0.88 per call) pfe_l2br_flush_all_mac_table/75 (38976828 (estimated locally),0.33 per call) pfe_l2br_set_static_entry/57 (31004295 (estimated locally),0.03 per call) pfe_l2br_set_static_entry/57 (93952410 (estimated locally),0.09 per call) pfe_l2br_set_static_entry/57 (187904819 (estimated locally),0.17 per call) pfe_l2br_set_static_entry/57 (375809639 (estimated locally),0.35 per call) pfe_l2br_set_static_entry/57 (322122547 (estimated locally),0.30 per call) pfe_l2br_static_entry_match_criterion/73 (214748364 (estimated locally),0.20 per call) pfe_l2br_domain_match_criterion/88 (124446946 (estimated locally),0.25 per call) pfe_l2br_domain_flush_by_if_dynamic_static/47 (35383165 (estimated locally),0.10 per call) pfe_l2br_domain_flush_by_if_static.isra.0/144 (29215879 (estimated locally),0.25 per call) pfe_l2br_domain_flush_by_if_static.isra.0/144 (166566348 (estimated locally),1.41 per call) pfe_l2br_domain_match_if_criterion/51 (268435456 (estimated locally),0.25 per call) pfe_l2br_static_entry_destroy_nolock/59 (354334802 (estimated locally),0.33 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (57431766 (estimated locally),0.17 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (174035655 (estimated locally),0.50 per call) pfe_vlan_write_to_class.part.0/140 (1073741824 (estimated locally),1.00 per call) pfe_vlan_read_from_class.part.0/139 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hm_report/101 (pfe_hm_report) @077bb2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (143948513 (estimated locally),0.13 per call) pfe_l2br_config_domain.constprop/153 (71974257 (estimated locally),0.07 per call) pfe_l2br_create_mandatory_domains/83 (28647969 (estimated locally),0.03 per call) pfe_l2br_create_default_domain/38 (62100280 (estimated locally),0.06 per call) pfe_l2br_create_default_domain/38 (311385129 (estimated locally),0.29 per call) pfe_l2br_domain_create/35 (597859448 (estimated locally),0.56 per call) pfe_l2br_get_first_domain.part.0/151 (1073741824 (estimated locally),1.00 per call) pfe_l2br_static_entry_set_dst_discard_flag/64 (146286586 (estimated locally),0.14 per call) pfe_l2br_static_entry_set_dst_discard_flag/64 (375809639 (estimated locally),0.35 per call) pfe_l2br_static_entry_set_src_discard_flag/63 (146286586 (estimated locally),0.14 per call) pfe_l2br_static_entry_set_src_discard_flag/63 (375809639 (estimated locally),0.35 per call) pfe_l2br_static_entry_set_local_flag/62 (146286586 (estimated locally),0.14 per call) pfe_l2br_static_entry_set_local_flag/62 (375809639 (estimated locally),0.35 per call) pfe_l2br_static_entry_replace_fw_list/61 (146286586 (estimated locally),0.14 per call) pfe_l2br_static_entry_replace_fw_list/61 (375809639 (estimated locally),0.35 per call) pfe_l2br_static_entry_create/58 (9828441 (estimated locally),0.15 per call) pfe_l2br_static_entry_create/58 (14544285 (estimated locally),0.22 per call) pfe_l2br_domain_get_first_if/52 (268435456 (estimated locally),0.25 per call) pfe_l2br_domain_del_if/45 (107509388 (estimated locally),0.10 per call) pfe_l2br_domain_destroy_log.part.0/150 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_destroy/37 (187904819 (estimated locally),0.17 per call) pfe_l2br_create_fallback_domain/39 (166497628 (estimated locally),0.16 per call) pfe_l2br_update_hw_entry/28 (116678181 (estimated locally),0.11 per call) pfe_l2br_update_hw_entry/28 (299745768 (estimated locally),0.28 per call) pfe_l2br_destroy_vlan_stats_table/32 (88583700 (estimated locally),0.08 per call) pfe_l2br_destroy_vlan_stats_table/32 (177167401 (estimated locally),0.17 per call) pfe_l2br_create_vlan_stats_table/31 (88583700 (estimated locally),0.08 per call) pfe_l2br_create_vlan_stats_table/31 (268435456 (estimated locally),0.25 per call) pfe_l2br_create_vlan_stats_table/31 (536870911 (estimated locally),0.50 per call) pfe_l2br_flush_learned_mac_table.isra.0/145 (104068131 (estimated locally),0.88 per call) pfe_l2br_flush_all_mac_table/75 (38976828 (estimated locally),0.33 per call) pfe_l2br_set_static_entry/57 (31004295 (estimated locally),0.03 per call) pfe_l2br_set_static_entry/57 (93952410 (estimated locally),0.09 per call) pfe_l2br_set_static_entry/57 (187904819 (estimated locally),0.17 per call) pfe_l2br_set_static_entry/57 (375809639 (estimated locally),0.35 per call) pfe_l2br_set_static_entry/57 (322122547 (estimated locally),0.30 per call) pfe_l2br_static_entry_match_criterion/73 (214748364 (estimated locally),0.20 per call) pfe_l2br_domain_match_criterion/88 (124446946 (estimated locally),0.25 per call) pfe_l2br_domain_flush_by_if_dynamic_static/47 (35383165 (estimated locally),0.10 per call) pfe_l2br_domain_flush_by_if_static.isra.0/144 (29215879 (estimated locally),0.25 per call) pfe_l2br_domain_flush_by_if_static.isra.0/144 (166566348 (estimated locally),1.41 per call) pfe_l2br_domain_match_if_criterion/51 (268435456 (estimated locally),0.25 per call) pfe_l2br_static_entry_destroy_nolock/59 (354334802 (estimated locally),0.33 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (57431766 (estimated locally),0.17 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (174035655 (estimated locally),0.50 per call) pfe_vlan_write_to_class.part.0/140 (1073741824 (estimated locally),1.00 per call) pfe_vlan_read_from_class.part.0/139 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_class_read_dmem/100 (pfe_class_read_dmem) @077bb1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_get_domain_stats/95 (1014686025 (estimated locally),8.83 per call) pfe_vlan_read_from_class/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memcpy/99 (autolibc_memcpy) @077ad8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_static_entry_get_first/71 (268435456 (estimated locally),0.25 per call) pfe_l2br_static_entry_get_first/71 (268435456 (estimated locally),0.25 per call) pfe_l2br_static_entry_get_mac/70 (1073741824 (estimated locally),1.00 per call) pfe_l2br_static_entry_create/58 (42589913 (estimated locally),0.64 per call) pfe_l2br_vlan_action_to_entry/23 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/98 (autolibc_memset) @077adee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_l2br_get_domain_stats/95 (1014686025 (estimated locally),8.83 per call) pfe_l2br_get_domain_stats/95 (114863532 (estimated locally),1.00 per call) pfe_l2br_create/84 (1073741824 (estimated locally),1.00 per call) pfe_l2br_create/84 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_create.part.0/152 (731110809 (estimated locally),0.68 per call) pfe_l2br_static_entry_create/58 (42589913 (estimated locally),0.64 per call) pfe_l2br_delete_vlan_hash_entry/27 (174035655 (estimated locally),1.00 per call) pfe_l2br_delete_vlan_hash_entry/27 (174035655 (estimated locally),1.00 per call) pfe_l2br_delete_vlan_hash_entry/27 (174035655 (estimated locally),1.00 per call) pfe_l2br_delete_vlan_hash_entry/27 (174035655 (estimated locally),1.00 per call) pfe_l2br_add_vlan_hash_entry/26 (219006269 (estimated locally),1.00 per call) pfe_l2br_add_vlan_hash_entry/26 (219006269 (estimated locally),1.00 per call) pfe_l2br_create_fallback_domain/39 (574129754 (estimated locally),0.53 per call) pfe_l2br_update_vlan_hash_entry/24 (221556076 (estimated locally),1.00 per call) pfe_l2br_update_vlan_hash_entry/24 (221556076 (estimated locally),1.00 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (348071309 (estimated locally),1.00 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (348071309 (estimated locally),1.00 per call) pfe_l2br_update_hw_ll_entry/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_get_vlan_stats_index/97 (pfe_l2br_get_vlan_stats_index) @077ada80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_clear_domain_stats/96 (pfe_l2br_clear_domain_stats) @077ad7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_write_dmem/103 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_get_domain_stats/95 (pfe_l2br_get_domain_stats) @077ad460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_read_dmem/100 (1014686025 (estimated locally),8.83 per call) autolibc_memset/98 (1014686025 (estimated locally),8.83 per call) pfe_class_get_num_of_pes/137 (114863532 (estimated locally),1.00 per call) autolibc_memset/98 (114863532 (estimated locally),1.00 per call) 
pfe_l2br_static_entry_get_entry/94 (pfe_l2br_static_entry_get_entry) @0779d9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_get_stats/93 (pfe_l2br_get_stats) @0779d380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_table_get_next/121 (958878293 (estimated locally),8.35 per call) pfe_l2br_table_get_first/118 (114863532 (estimated locally),1.00 per call) pfe_l2br_iterator_create/116 (114863532 (estimated locally),1.00 per call) pfe_l2br_table_entry_create/106 (114863532 (estimated locally),1.00 per call) 
pfe_l2br_get_number_entries/92 (pfe_l2br_get_number_entries) @0779dee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_table_get_next/121 (955630223 (estimated locally),8.09 per call) pfe_l2br_table_get_first/118 (118111600 (estimated locally),1.00 per call) pfe_l2br_iterator_create/116 (118111600 (estimated locally),1.00 per call) pfe_l2br_table_entry_create/106 (118111600 (estimated locally),1.00 per call) 
pfe_l2br_set_mac_aging_timeout/91 (pfe_l2br_set_mac_aging_timeout) @0779db60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_create_mandatory_domains/83 (526133494 (estimated locally),0.49 per call) 
  Calls: pfe_class_write_dmem/103 (354334802 (estimated locally),0.33 per call) pfe_class_get_mmap/131 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_get_next_domain/90 (pfe_l2br_get_next_domain) @0779d8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:88896196 (estimated locally) body optimize_size
  Called by: pfe_l2br_get_first_domain/89 (805306369 (estimated locally),0.75 per call) 
  Calls: pfe_l2br_domain_match_criterion/88 (542552617 (estimated locally),6.10 per call) isa_item/122 (1014686024 (estimated locally),11.41 per call) 
pfe_l2br_get_first_domain/89 (pfe_l2br_get_first_domain) @0779d620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_l2br_create_default_domain/38 (416780405 (estimated locally),0.39 per call) pfe_l2br_domain_create/35 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_l2br_get_next_domain/90 (805306369 (estimated locally),0.75 per call) pfe_l2br_get_first_domain.part.0/151 (268435456 (estimated locally),0.25 per call) 
pfe_l2br_domain_match_criterion/88 (pfe_l2br_domain_match_criterion) @0779d2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_index_to_phy_if_id/16 (read)
  Referring: 
  Availability: local
  Function flags: count:497787785 (estimated locally) body local optimize_size
  Called by: pfe_l2br_get_next_domain/90 (542552617 (estimated locally),6.10 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (124446946 (estimated locally),0.25 per call) pfe_hm_report/101 (124446946 (estimated locally),0.25 per call) pfe_phy_if_get_phy/124 (488069346 (estimated locally),0.98 per call) 
pfe_l2br_get_fallback_domain/87 (pfe_l2br_get_fallback_domain) @07793ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_get_default_domain/86 (pfe_l2br_get_default_domain) @077938c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_destroy/85 (pfe_l2br_destroy) @07793380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_l2br_create_mandatory_domains/83 (28647969 (estimated locally),0.03 per call) pfe_l2br_create_mandatory_domains/83 (263066747 (estimated locally),0.25 per call) pfe_l2br_create_mandatory_domains/83 (225485783 (estimated locally),0.21 per call) pfe_l2br_create_mandatory_domains/83 (322122547 (estimated locally),0.30 per call) 
  Calls: pfe_l2br_destroy_vlan_stats_table/32 (872415233 (estimated locally),0.81 per call) isa_isempty/136 (872415233 (estimated locally),0.81 per call) pfe_l2br_domain_destroy/37 (466480425 (estimated locally),0.43 per call) pfe_l2br_domain_destroy/37 (466480425 (estimated locally),0.43 per call) 
pfe_l2br_create/84 (pfe_l2br_create) @07793e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: l2_bridge_instance/14 (addr)l2_bridge_instance/14 (addr)l2_bridge_instance/14 (addr)l2_bridge_instance_statics_isa_def/15 (addr)l2_bridge_instance/14 (addr)l2_bridge_instance_domains_isa_def/17 (addr)stats_index/13 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_create_mandatory_domains/83 (1073741824 (estimated locally),1.00 per call) pfe_l2br_create_vlan_stats_table/31 (1073741824 (estimated locally),1.00 per call) autolibc_memset/98 (1073741824 (estimated locally),1.00 per call) isa_init/129 (1073741824 (estimated locally),1.00 per call) isa_init/129 (1073741824 (estimated locally),1.00 per call) autolibc_memset/98 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_create_mandatory_domains/83 (pfe_l2br_create_mandatory_domains) @07793b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_create/84 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_l2br_destroy/85 (28647969 (estimated locally),0.03 per call) oal_util_raise_dem_for_drv_runtime_err/102 (28647969 (estimated locally),0.03 per call) pfe_hm_report/101 (28647969 (estimated locally),0.03 per call) pfe_feature_mgr_enable/134 (86812027 (estimated locally),0.08 per call) pfe_feature_mgr_is_available/109 (263066747 (estimated locally),0.25 per call) pfe_l2br_destroy/85 (263066747 (estimated locally),0.25 per call) pfe_l2br_set_mac_aging_timeout/91 (526133494 (estimated locally),0.49 per call) pfe_class_set_default_vlan/133 (526133494 (estimated locally),0.49 per call) pfe_l2br_destroy/85 (225485783 (estimated locally),0.21 per call) pfe_l2br_create_fallback_domain/39 (751619278 (estimated locally),0.70 per call) pfe_l2br_destroy/85 (322122547 (estimated locally),0.30 per call) pfe_l2br_create_default_domain/38 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_flush_all/82 (pfe_l2br_flush_all) @077937e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_flush/79 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_flush_static/81 (pfe_l2br_flush_static) @07793540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_flush/79 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_flush_learned/80 (pfe_l2br_flush_learned) @077932a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_flush/79 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_flush/79 (pfe_l2br_flush) @07793000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_flush_all/82 (1073741824 (estimated locally),1.00 per call) pfe_l2br_flush_static/81 (1073741824 (estimated locally),1.00 per call) pfe_l2br_flush_learned/80 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_l2br_table_destroy_entry_iterator/78 (1073741824 (estimated locally),1.00 per call) pfe_l2br_flush_learned_mac_table.isra.0/145 (268435456 (estimated locally),0.25 per call) pfe_l2br_flush_all_mac_table/75 (268435456 (estimated locally),0.25 per call) pfe_l2br_flush_static_mac_table/74 (268435456 (estimated locally),0.25 per call) pfe_l2br_table_create_entry_iterator.isra.0/143 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_table_destroy_entry_iterator/78 (pfe_l2br_table_destroy_entry_iterator) @07788700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_flush/79 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_l2br_iterator_destroy/117 (1073741824 (estimated locally),1.00 per call) pfe_l2br_table_entry_destroy/112 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_flush_all_mac_table/75 (pfe_l2br_flush_all_mac_table) @077889a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_l2br_flush/79 (268435456 (estimated locally),0.25 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (38976828 (estimated locally),0.33 per call) pfe_hm_report/101 (38976828 (estimated locally),0.33 per call) pfe_l2br_table_init/127 (118111601 (estimated locally),1.00 per call) pfe_l2br_static_entry_destroy_nolock/59 (955630223 (estimated locally),8.09 per call) isa_item/122 (955630223 (estimated locally),8.09 per call) 
pfe_l2br_flush_static_mac_table/74 (pfe_l2br_flush_static_mac_table) @07788620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_l2br_flush/79 (268435456 (estimated locally),0.25 per call) 
  Calls: pfe_l2br_static_entry_destroy_nolock/59 (955630223 (estimated locally),8.09 per call) isa_item/122 (955630223 (estimated locally),8.09 per call) 
pfe_l2br_static_entry_match_criterion/73 (pfe_l2br_static_entry_match_criterion) @07788380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_l2br_static_entry_get_next/72 (542552617 (estimated locally),6.10 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (214748364 (estimated locally),0.20 per call) pfe_hm_report/101 (214748364 (estimated locally),0.20 per call) autolibc_memcmp/125 (43465069 (estimated locally),0.04 per call) autolibc_memcmp/125 (214748364 (estimated locally),0.20 per call) 
pfe_l2br_static_entry_get_next/72 (pfe_l2br_static_entry_get_next) @07788000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:88896196 (estimated locally) body optimize_size
  Called by: pfe_l2br_static_entry_get_first/71 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_l2br_static_entry_match_criterion/73 (542552617 (estimated locally),6.10 per call) isa_item/122 (1014686024 (estimated locally),11.41 per call) 
pfe_l2br_static_entry_get_first/71 (pfe_l2br_static_entry_get_first) @0777fa80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_static_entry_get_next/72 (1073741824 (estimated locally),1.00 per call) autolibc_memcpy/99 (268435456 (estimated locally),0.25 per call) autolibc_memcpy/99 (268435456 (estimated locally),0.25 per call) 
pfe_l2br_static_entry_get_mac/70 (pfe_l2br_static_entry_get_mac) @0777f540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/99 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_static_entry_get_vlan/69 (pfe_l2br_static_entry_get_vlan) @0777fee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_static_entry_get_fw_list/68 (pfe_l2br_static_entry_get_fw_list) @0777fc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_static_entry_get_dst_discard_flag/67 (pfe_l2br_static_entry_get_dst_discard_flag) @0777f9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_static_entry_get_src_discard_flag/66 (pfe_l2br_static_entry_get_src_discard_flag) @0777f700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_static_entry_get_local_flag/65 (pfe_l2br_static_entry_get_local_flag) @0777f460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_static_entry_set_dst_discard_flag/64 (pfe_l2br_static_entry_set_dst_discard_flag) @0777f1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (146286586 (estimated locally),0.14 per call) pfe_hm_report/101 (146286586 (estimated locally),0.14 per call) pfe_l2br_table_update_entry/114 (697932186 (estimated locally),0.65 per call) oal_util_raise_dem_for_drv_runtime_err/102 (375809639 (estimated locally),0.35 per call) pfe_hm_report/101 (375809639 (estimated locally),0.35 per call) pfe_l2br_table_entry_set_action_data/108 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_static_entry_set_src_discard_flag/63 (pfe_l2br_static_entry_set_src_discard_flag) @07773a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (146286586 (estimated locally),0.14 per call) pfe_hm_report/101 (146286586 (estimated locally),0.14 per call) pfe_l2br_table_update_entry/114 (697932186 (estimated locally),0.65 per call) oal_util_raise_dem_for_drv_runtime_err/102 (375809639 (estimated locally),0.35 per call) pfe_hm_report/101 (375809639 (estimated locally),0.35 per call) pfe_l2br_table_entry_set_action_data/108 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_static_entry_set_local_flag/62 (pfe_l2br_static_entry_set_local_flag) @07773e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (146286586 (estimated locally),0.14 per call) pfe_hm_report/101 (146286586 (estimated locally),0.14 per call) pfe_l2br_table_update_entry/114 (697932186 (estimated locally),0.65 per call) oal_util_raise_dem_for_drv_runtime_err/102 (375809639 (estimated locally),0.35 per call) pfe_hm_report/101 (375809639 (estimated locally),0.35 per call) pfe_l2br_table_entry_set_action_data/108 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_static_entry_replace_fw_list/61 (pfe_l2br_static_entry_replace_fw_list) @077739a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (146286586 (estimated locally),0.14 per call) pfe_hm_report/101 (146286586 (estimated locally),0.14 per call) pfe_l2br_table_update_entry/114 (697932186 (estimated locally),0.65 per call) oal_util_raise_dem_for_drv_runtime_err/102 (375809639 (estimated locally),0.35 per call) pfe_hm_report/101 (375809639 (estimated locally),0.35 per call) pfe_l2br_table_entry_set_action_data/108 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_static_entry_destroy/60 (pfe_l2br_static_entry_destroy) @07773540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_static_entry_destroy_nolock/59 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_static_entry_destroy_nolock/59 (pfe_l2br_static_entry_destroy_nolock) @077732a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_static_entry_destroy/60 (1073741824 (estimated locally),1.00 per call) pfe_l2br_flush_all_mac_table/75 (955630223 (estimated locally),8.09 per call) pfe_l2br_flush_static_mac_table/74 (955630223 (estimated locally),8.09 per call) pfe_l2br_domain_flush_by_if_static.isra.0/144 (88532967 (estimated locally),0.75 per call) 
  Calls: isa_release/113 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/102 (354334802 (estimated locally),0.33 per call) pfe_hm_report/101 (354334802 (estimated locally),0.33 per call) pfe_l2br_table_del_entry/111 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_static_entry_create/58 (pfe_l2br_static_entry_create) @0776c8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:66962640 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_release/113 (14054671 (estimated locally),0.21 per call) pfe_l2br_set_static_entry/57 (42589913 (estimated locally),0.64 per call) autolibc_memcpy/99 (42589913 (estimated locally),0.64 per call) autolibc_memset/98 (42589913 (estimated locally),0.64 per call) oal_util_raise_dem_for_drv_runtime_err/102 (9828441 (estimated locally),0.15 per call) pfe_hm_report/101 (9828441 (estimated locally),0.15 per call) isa_reserve/105 (52418354 (estimated locally),0.78 per call) oal_util_raise_dem_for_drv_runtime_err/102 (14544285 (estimated locally),0.22 per call) pfe_hm_report/101 (14544285 (estimated locally),0.22 per call) autolibc_memcmp/125 (143760716 (estimated locally),2.15 per call) isa_item/122 (1014686025 (estimated locally),15.15 per call) 
pfe_l2br_set_static_entry/57 (pfe_l2br_set_static_entry) @0776cee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_static_entry_create/58 (42589913 (estimated locally),0.64 per call) 
  Calls: isa_release/113 (1010793711 (estimated locally),0.94 per call) oal_util_raise_dem_for_drv_runtime_err/102 (31004295 (estimated locally),0.03 per call) pfe_hm_report/101 (31004295 (estimated locally),0.03 per call) pfe_l2br_table_add_entry/110 (93952410 (estimated locally),0.09 per call) oal_util_raise_dem_for_drv_runtime_err/102 (93952410 (estimated locally),0.09 per call) pfe_hm_report/101 (93952410 (estimated locally),0.09 per call) pfe_l2br_table_entry_set_action_data/108 (187904819 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/102 (187904819 (estimated locally),0.17 per call) pfe_hm_report/101 (187904819 (estimated locally),0.17 per call) pfe_l2br_table_entry_set_mac_addr/126 (375809639 (estimated locally),0.35 per call) oal_util_raise_dem_for_drv_runtime_err/102 (375809639 (estimated locally),0.35 per call) pfe_hm_report/101 (375809639 (estimated locally),0.35 per call) pfe_l2br_table_entry_set_vlan/107 (751619278 (estimated locally),0.70 per call) oal_util_raise_dem_for_drv_runtime_err/102 (322122547 (estimated locally),0.30 per call) pfe_hm_report/101 (322122547 (estimated locally),0.30 per call) pfe_l2br_table_entry_create/106 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_domain_is_fallback/56 (pfe_l2br_domain_is_fallback) @0776c7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_domain_is_default/55 (pfe_l2br_domain_is_default) @0776c540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_domain_get_vlan/54 (pfe_l2br_domain_get_vlan) @0776c2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_domain_get_next_if/53 (pfe_l2br_domain_get_next_if) @0776c000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_index_to_phy_if_id/16 (read)
  Referring: 
  Availability: available
  Function flags: count:77472354 (estimated locally) body optimize_size
  Called by: pfe_l2br_domain_get_first_if/52 (805306369 (estimated locally),0.75 per call) 
  Calls: pfe_l2br_domain_match_if_criterion/51 (334846388 (estimated locally),4.32 per call) pfe_phy_if_get_phy/124 (334846388 (estimated locally),4.32 per call) 
pfe_l2br_domain_get_first_if/52 (pfe_l2br_domain_get_first_if) @0775f9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: phys.10869/123 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_domain_get_next_if/53 (805306369 (estimated locally),0.75 per call) oal_util_raise_dem_for_drv_runtime_err/102 (268435456 (estimated locally),0.25 per call) pfe_hm_report/101 (268435456 (estimated locally),0.25 per call) 
pfe_l2br_domain_match_if_criterion/51 (pfe_l2br_domain_match_if_criterion) @0775fee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_domain_get_next_if/53 (334846388 (estimated locally),4.32 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (268435456 (estimated locally),0.25 per call) pfe_hm_report/101 (268435456 (estimated locally),0.25 per call) pfe_phy_if_get_id/115 (268435456 (estimated locally),0.25 per call) 
pfe_l2br_domain_get_untag_if_list/50 (pfe_l2br_domain_get_untag_if_list) @0775fb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_domain_get_if_list/49 (pfe_l2br_domain_get_if_list) @0775f8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_domain_flush_by_if/48 (pfe_l2br_domain_flush_by_if) @0775f620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_iterator_destroy/117 (1073741824 (estimated locally),1.00 per call) pfe_l2br_table_entry_destroy/112 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_flush_by_if_dynamic_static/47 (1073741824 (estimated locally),1.00 per call) pfe_l2br_iterator_create/116 (1073741824 (estimated locally),1.00 per call) pfe_l2br_table_entry_create/106 (1073741824 (estimated locally),1.00 per call) pfe_phy_if_get_id/115 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_domain_flush_by_if_dynamic_static/47 (pfe_l2br_domain_flush_by_if_dynamic_static) @0775f380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913939 (estimated locally) body local optimize_size
  Called by: pfe_l2br_domain_flush_by_if/48 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_l2br_table_get_next/121 (955630224 (estimated locally),2.67 per call) oal_util_raise_dem_for_drv_runtime_err/102 (35383165 (estimated locally),0.10 per call) pfe_hm_report/101 (35383165 (estimated locally),0.10 per call) pfe_l2br_table_del_entry/111 (107221711 (estimated locally),0.30 per call) pfe_l2br_table_entry_get_action_data/120 (955630223 (estimated locally),2.67 per call) pfe_l2br_table_entry_get_vlan/119 (955630223 (estimated locally),2.67 per call) pfe_l2br_table_get_first/118 (118111600 (estimated locally),0.33 per call) pfe_l2br_domain_flush_by_if_static.isra.0/144 (357913939 (estimated locally),1.00 per call) 
pfe_l2br_domain_del_if/45 (pfe_l2br_domain_del_if) @0774f700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (107509388 (estimated locally),0.10 per call) pfe_hm_report/101 (107509388 (estimated locally),0.10 per call) pfe_l2br_update_hw_entry/28 (512926469 (estimated locally),0.48 per call) pfe_phy_if_get_id/115 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_domain_add_if/44 (pfe_l2br_domain_add_if) @0774fe00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_update_hw_entry/28 (697932186 (estimated locally),0.65 per call) pfe_phy_if_get_id/115 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_domain_get_mcast_action/43 (pfe_l2br_domain_get_mcast_action) @0774fb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_domain_set_mcast_action/42 (pfe_l2br_domain_set_mcast_action) @0774f8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_update_hw_entry/28 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_domain_get_ucast_action/41 (pfe_l2br_domain_get_ucast_action) @0774f620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_domain_set_ucast_action/40 (pfe_l2br_domain_set_ucast_action) @0774f380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_update_hw_entry/28 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_create_fallback_domain/39 (pfe_l2br_create_fallback_domain) @0774f0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_create_mandatory_domains/83 (751619278 (estimated locally),0.70 per call) 
  Calls: isa_release/113 (68278381 (estimated locally),0.06 per call) pfe_l2br_update_hw_entry/28 (407632125 (estimated locally),0.38 per call) isa_release/113 (166497628 (estimated locally),0.16 per call) oal_util_raise_dem_for_drv_runtime_err/102 (166497628 (estimated locally),0.16 per call) pfe_hm_report/101 (166497628 (estimated locally),0.16 per call) pfe_class_get_mmap/131 (574129754 (estimated locally),0.53 per call) autolibc_memset/98 (574129754 (estimated locally),0.53 per call) isa_reserve/105 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_create_default_domain/38 (pfe_l2br_create_default_domain) @07740b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_create_mandatory_domains/83 (1073741824 (estimated locally),1.00 per call) 
  Calls: isa_release/113 (59408921 (estimated locally),0.06 per call) pfe_l2br_update_hw_entry/28 (354680125 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/102 (62100280 (estimated locally),0.06 per call) pfe_hm_report/101 (62100280 (estimated locally),0.06 per call) pfe_l2br_get_first_domain/89 (416780405 (estimated locally),0.39 per call) pfe_l2br_domain_create/35 (762356696 (estimated locally),0.71 per call) pfe_feature_mgr_disable/135 (83020644 (estimated locally),0.08 per call) pfe_feature_mgr_table_get_payload/104 (251577709 (estimated locally),0.23 per call) pfe_feature_mgr_enable/134 (762356696 (estimated locally),0.71 per call) oal_util_raise_dem_for_drv_runtime_err/102 (311385129 (estimated locally),0.29 per call) pfe_hm_report/101 (311385129 (estimated locally),0.29 per call) pfe_class_get_mmap/131 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_domain_destroy/37 (pfe_l2br_domain_destroy) @07740e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_l2br_destroy/85 (466480425 (estimated locally),0.43 per call) pfe_l2br_destroy/85 (466480425 (estimated locally),0.43 per call) pfe_l2br_domain_destroy_log/33 (1073741824 (estimated locally),1.00 per call) 
  Calls: isa_release/113 (885837006 (estimated locally),0.83 per call) pfe_l2br_domain_destroy_instance/36 (885837006 (estimated locally),0.83 per call) pfe_l2br_table_entry_destroy/112 (348966093 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/102 (187904819 (estimated locally),0.17 per call) pfe_hm_report/101 (187904819 (estimated locally),0.17 per call) pfe_l2br_table_del_entry/111 (354334802 (estimated locally),0.33 per call) pfe_l2br_delete_vlan_hash_entry/27 (182536110 (estimated locally),0.17 per call) pfe_feature_mgr_is_available/109 (536870913 (estimated locally),0.50 per call) 
pfe_l2br_domain_destroy_instance/36 (pfe_l2br_domain_destroy_instance) @07740a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: stats_index/13 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_domain_destroy/37 (885837006 (estimated locally),0.83 per call) 
  Calls: pfe_l2br_update_hw_entry/28 (71717364 (estimated locally),0.07 per call) pfe_l2br_update_hw_entry/28 (217325345 (estimated locally),0.20 per call) 
pfe_l2br_domain_create/35 (pfe_l2br_domain_create) @077407e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_l2br_create_default_domain/38 (762356696 (estimated locally),0.71 per call) 
  Calls: pfe_l2br_domain_create.part.0/152 (475882376 (estimated locally),0.44 per call) oal_util_raise_dem_for_drv_runtime_err/102 (597859448 (estimated locally),0.56 per call) pfe_hm_report/101 (597859448 (estimated locally),0.56 per call) pfe_l2br_get_first_domain/89 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_config_domain/34 (pfe_l2br_config_domain) @07740460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_l2br_domain_destroy_log/33 (pfe_l2br_domain_destroy_log) @07740000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (201326592 (estimated locally),0.19 per call) pfe_l2br_config_domain.constprop/153 (436207616 (estimated locally),0.41 per call) pfe_l2br_config_domain.constprop/153 (218103808 (estimated locally),0.20 per call) pfe_l2br_config_domain.constprop/153 (71974257 (estimated locally),0.07 per call) 
  Calls: pfe_l2br_domain_destroy_log.part.0/150 (354334800 (estimated locally),0.33 per call) pfe_l2br_domain_destroy/37 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_destroy_vlan_stats_table/32 (pfe_l2br_destroy_vlan_stats_table) @07733d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_l2br_destroy/85 (872415233 (estimated locally),0.81 per call) 
  Calls: pfe_class_dmem_heap_free/132 (88583700 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/102 (88583700 (estimated locally),0.08 per call) pfe_hm_report/101 (88583700 (estimated locally),0.08 per call) pfe_class_write_dmem/103 (177167401 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/102 (177167401 (estimated locally),0.17 per call) pfe_hm_report/101 (177167401 (estimated locally),0.17 per call) pfe_class_get_mmap/131 (354334802 (estimated locally),0.33 per call) 
pfe_l2br_create_vlan_stats_table/31 (pfe_l2br_create_vlan_stats_table) @077338c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_l2br_create/84 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_class_dmem_heap_free/132 (88583700 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/102 (88583700 (estimated locally),0.08 per call) pfe_hm_report/101 (88583700 (estimated locally),0.08 per call) pfe_class_write_dmem/103 (268435456 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/102 (268435456 (estimated locally),0.25 per call) pfe_hm_report/101 (268435456 (estimated locally),0.25 per call) pfe_class_get_mmap/131 (536870911 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/102 (536870911 (estimated locally),0.50 per call) pfe_hm_report/101 (536870911 (estimated locally),0.50 per call) pfe_class_dmem_heap_alloc/130 (1073741823 (estimated locally),1.00 per call) 
pfe_l2br_update_hw_entry/28 (pfe_l2br_update_hw_entry) @07718c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_create_default_domain/38 (354680125 (estimated locally),0.33 per call) pfe_l2br_domain_del_if/45 (512926469 (estimated locally),0.48 per call) pfe_l2br_domain_add_if/44 (697932186 (estimated locally),0.65 per call) pfe_l2br_domain_destroy_instance/36 (71717364 (estimated locally),0.07 per call) pfe_l2br_domain_destroy_instance/36 (217325345 (estimated locally),0.20 per call) pfe_l2br_domain_set_mcast_action/42 (1073741824 (estimated locally),1.00 per call) pfe_l2br_domain_set_ucast_action/40 (1073741824 (estimated locally),1.00 per call) pfe_l2br_create_fallback_domain/39 (407632125 (estimated locally),0.38 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/102 (116678181 (estimated locally),0.11 per call) pfe_hm_report/101 (116678181 (estimated locally),0.11 per call) pfe_l2br_table_update_entry/114 (367402669 (estimated locally),0.34 per call) pfe_l2br_update_vlan_hash_entry/24 (189268041 (estimated locally),0.18 per call) pfe_feature_mgr_is_available/109 (556670711 (estimated locally),0.52 per call) oal_util_raise_dem_for_drv_runtime_err/102 (299745768 (estimated locally),0.28 per call) pfe_hm_report/101 (299745768 (estimated locally),0.28 per call) pfe_l2br_table_entry_set_action_data/108 (856416479 (estimated locally),0.80 per call) pfe_l2br_update_vlan_hash_entry/24 (35083752 (estimated locally),0.03 per call) pfe_feature_mgr_is_available/109 (173338695 (estimated locally),0.16 per call) pfe_l2br_update_hw_ll_entry/19 (173338695 (estimated locally),0.16 per call) pfe_l2br_update_vlan_hash_entry/24 (43986650 (estimated locally),0.04 per call) pfe_feature_mgr_is_available/109 (217325345 (estimated locally),0.20 per call) pfe_l2br_update_hw_ll_entry/19 (217325345 (estimated locally),0.20 per call) 
pfe_l2br_delete_vlan_hash_entry/27 (pfe_l2br_delete_vlan_hash_entry) @07718e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:174035655 (estimated locally) body optimize_size
  Called by: pfe_l2br_domain_destroy/37 (182536110 (estimated locally),0.17 per call) 
  Calls: pfe_vlan_write_to_class/21 (55807731 (estimated locally),0.32 per call) pfe_vlan_write_to_class/21 (55807731 (estimated locally),0.32 per call) pfe_vlan_read_from_class/22 (1014686025 (estimated locally),5.83 per call) pfe_vlan_write_to_class/21 (11976438 (estimated locally),0.07 per call) pfe_vlan_write_to_class/21 (59172123 (estimated locally),0.34 per call) pfe_vlan_read_from_class/22 (19526800 (estimated locally),0.11 per call) pfe_vlan_read_from_class/22 (174035655 (estimated locally),1.00 per call) autolibc_memset/98 (174035655 (estimated locally),1.00 per call) autolibc_memset/98 (174035655 (estimated locally),1.00 per call) autolibc_memset/98 (174035655 (estimated locally),1.00 per call) autolibc_memset/98 (174035655 (estimated locally),1.00 per call) 
pfe_l2br_add_vlan_hash_entry/26 (pfe_l2br_add_vlan_hash_entry) @07718b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:219006269 (estimated locally) body optimize_size
  Called by: pfe_l2br_config_domain.constprop/153 (74155295 (estimated locally),0.07 per call) 
  Calls: pfe_vlan_write_to_class/21 (56574575 (estimated locally),0.26 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (114863532 (estimated locally),0.52 per call) pfe_vlan_read_from_class/22 (1014686025 (estimated locally),4.63 per call) pfe_vlan_read_from_class/22 (219006269 (estimated locally),1.00 per call) pfe_l2br_vlan_action_to_entry/23 (219006269 (estimated locally),1.00 per call) autolibc_memset/98 (219006269 (estimated locally),1.00 per call) autolibc_memset/98 (219006269 (estimated locally),1.00 per call) 
pfe_l2br_update_vlan_hash_entry/24 (pfe_l2br_update_vlan_hash_entry) @07718460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:221556076 (estimated locally) body optimize_size
  Called by: pfe_l2br_update_hw_entry/28 (189268041 (estimated locally),0.18 per call) pfe_l2br_update_hw_entry/28 (35083752 (estimated locally),0.03 per call) pfe_l2br_update_hw_entry/28 (43986650 (estimated locally),0.04 per call) 
  Calls: pfe_vlan_write_to_class/21 (55807731 (estimated locally),0.25 per call) pfe_vlan_read_from_class/22 (1014686025 (estimated locally),4.58 per call) pfe_vlan_write_to_class/21 (44842950 (estimated locally),0.20 per call) pfe_vlan_read_from_class/22 (221556076 (estimated locally),1.00 per call) pfe_l2br_vlan_action_to_entry/23 (221556076 (estimated locally),1.00 per call) autolibc_memset/98 (221556076 (estimated locally),1.00 per call) autolibc_memset/98 (221556076 (estimated locally),1.00 per call) 
pfe_l2br_vlan_action_to_entry/23 (pfe_l2br_vlan_action_to_entry) @077181c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_add_vlan_hash_entry/26 (219006269 (estimated locally),1.00 per call) pfe_l2br_update_vlan_hash_entry/24 (221556076 (estimated locally),1.00 per call) 
  Calls: autolibc_memcpy/99 (1073741824 (estimated locally),1.00 per call) 
pfe_vlan_read_from_class/22 (pfe_vlan_read_from_class) @077101c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_delete_vlan_hash_entry/27 (1014686025 (estimated locally),5.83 per call) pfe_l2br_delete_vlan_hash_entry/27 (19526800 (estimated locally),0.11 per call) pfe_l2br_delete_vlan_hash_entry/27 (174035655 (estimated locally),1.00 per call) pfe_l2br_add_vlan_hash_entry/26 (1014686025 (estimated locally),4.63 per call) pfe_l2br_add_vlan_hash_entry/26 (219006269 (estimated locally),1.00 per call) pfe_l2br_update_vlan_hash_entry/24 (1014686025 (estimated locally),4.58 per call) pfe_l2br_update_vlan_hash_entry/24 (221556076 (estimated locally),1.00 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (958878292 (estimated locally),2.75 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (37904966 (estimated locally),0.11 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (114863532 (estimated locally),0.33 per call) 
  Calls: pfe_vlan_read_from_class.part.0/139 (354334800 (estimated locally),0.33 per call) pfe_class_read_dmem/100 (1073741824 (estimated locally),1.00 per call) 
pfe_vlan_write_to_class/21 (pfe_vlan_write_to_class) @07710c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_delete_vlan_hash_entry/27 (55807731 (estimated locally),0.32 per call) pfe_l2br_delete_vlan_hash_entry/27 (55807731 (estimated locally),0.32 per call) pfe_l2br_delete_vlan_hash_entry/27 (11976438 (estimated locally),0.07 per call) pfe_l2br_delete_vlan_hash_entry/27 (59172123 (estimated locally),0.34 per call) pfe_l2br_add_vlan_hash_entry/26 (56574575 (estimated locally),0.26 per call) pfe_l2br_update_vlan_hash_entry/24 (55807731 (estimated locally),0.25 per call) pfe_l2br_update_vlan_hash_entry/24 (44842950 (estimated locally),0.20 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (37904965 (estimated locally),0.11 per call) pfe_l2br_add_vlan_to_collision_space.isra.0/142 (37904965 (estimated locally),0.11 per call) 
  Calls: pfe_vlan_write_to_class.part.0/140 (354334800 (estimated locally),0.33 per call) pfe_class_write_dmem/103 (1073741824 (estimated locally),1.00 per call) 
pfe_l2br_update_hw_ll_entry/19 (pfe_l2br_update_hw_ll_entry) @07710620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_l2br_update_hw_entry/28 (173338695 (estimated locally),0.16 per call) pfe_l2br_update_hw_entry/28 (217325345 (estimated locally),0.20 per call) 
  Calls: pfe_bd_write_to_class.isra.0/141 (1073741824 (estimated locally),1.00 per call) autolibc_memset/98 (1073741824 (estimated locally),1.00 per call) 
l2_bridge_instance_domains_isa_def/17 (l2_bridge_instance_domains_isa_def) @0770b000
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: l2_bridge_instance/14 (addr)l2_bridge_instance/14 (addr)
  Referring: pfe_l2br_create/84 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_index_to_phy_if_id/16 (pfe_index_to_phy_if_id) @07625f30
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: phys.10869/123 (alias)pfe_l2br_domain_match_criterion/88 (read)pfe_l2br_domain_get_next_if/53 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
l2_bridge_instance_statics_isa_def/15 (l2_bridge_instance_statics_isa_def) @07625e58
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: l2_bridge_instance/14 (addr)l2_bridge_instance/14 (addr)
  Referring: pfe_l2br_create/84 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
l2_bridge_instance/14 (l2_bridge_instance) @07625d80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: l2_bridge_instance_domains_isa_def/17 (addr)l2_bridge_instance_statics_isa_def/15 (addr)l2_bridge_instance_statics_isa_def/15 (addr)l2_bridge_instance_domains_isa_def/17 (addr)pfe_l2br_create/84 (addr)pfe_l2br_create/84 (addr)pfe_l2br_create/84 (addr)pfe_l2br_create/84 (addr)
  Availability: available
  Varpool flags:
stats_index/13 (stats_index) @07625cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_l2br_domain_destroy_instance/36 (write)pfe_l2br_domain_get_free_stats_index.isra.0/138 (write)pfe_l2br_domain_get_free_stats_index.isra.0/138 (read)pfe_l2br_create/84 (addr)
  Availability: available
  Varpool flags:

;; Function pfe_l2br_vlan_action_to_entry (pfe_l2br_vlan_action_to_entry, funcdef_no=16, decl_uid=10653, cgraph_uid=17, symbol_order=23)

Modification phase of node pfe_l2br_vlan_action_to_entry/23
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
pfe_l2br_vlan_action_to_entry (const struct pfe_l2br_domain_t * domain, struct l2br_vlan_hash_entry_t * entry)
{
  uint64_t tmp64;
  short unsigned int _1;
  short unsigned int _2;
  long long unsigned int _3;
  long long unsigned int _4;
  long long unsigned int _5;
  long long unsigned int _6;
  long long unsigned int _7;
  long long unsigned int _8;
  long long unsigned int _9;
  long long unsigned int _10;
  long long unsigned int _11;
  long long unsigned int _12;
  long long unsigned int _13;
  long long unsigned int _14;
  long long unsigned int _15;
  long long unsigned int _16;
  long long unsigned int _17;
  long long unsigned int _18;
  long long unsigned int _19;
  long long unsigned int _20;
  long long unsigned int _21;
  long long unsigned int _22;
  long long unsigned int _23;
  long long unsigned int _24;
  uint64_t * _25;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_27(D)->vlan;
  _2 = _1 r>> 8;
  entry_28(D)->vlan = _2;
  # DEBUG BEGIN_STMT
  _3 = domain_27(D)->u.action_data.val;
  entry_28(D)->entry.val = _3;
  # DEBUG BEGIN_STMT
  _4 = _3 >> 56;
  _5 = _3 >> 40;
  _6 = _5 & 65280;
  _7 = _4 | _6;
  _8 = _3 >> 24;
  _9 = _8 & 16711680;
  _10 = _7 | _9;
  _11 = _3 >> 8;
  _12 = _11 & 4278190080;
  _13 = _10 | _12;
  _14 = _3 << 8;
  _15 = _14 & 1095216660480;
  _16 = _13 | _15;
  _17 = _3 << 24;
  _18 = _17 & 280375465082880;
  _19 = _16 | _18;
  _20 = _3 << 40;
  _21 = _20 & 71776119061217280;
  _22 = _19 | _21;
  _23 = _3 << 56;
  _24 = _22 | _23;
  tmp64 = _24;
  # DEBUG BEGIN_STMT
  _25 = &entry_28(D)->entry.val;
  autolibc_memcpy (_25, &tmp64, 8);
  # DEBUG BEGIN_STMT
  entry_28(D)->flags = 8;
  # DEBUG BEGIN_STMT
  entry_28(D)->field_valids = 2;
  tmp64 ={v} {CLOBBER};
  return;

}



;; Function pfe_l2br_static_entry_destroy_nolock (pfe_l2br_static_entry_destroy_nolock, funcdef_no=52, decl_uid=10591, cgraph_uid=53, symbol_order=59)

Modification phase of node pfe_l2br_static_entry_destroy_nolock/59
pfe_l2br_static_entry_destroy_nolock (struct pfe_l2br_t * bridge, struct pfe_l2br_static_entry_t * static_ent)
{
  errno_t ret;
  struct pfe_l2br_table_t * _1;
  struct pfe_l2br_table_entry_t * _2;
  struct pfe_isa_t * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bridge_6(D)->mac_table;
  _2 = &static_ent_7(D)->entry;
  ret_9 = pfe_l2br_table_del_entry (_1, _2);
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  if (ret_9 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Static entry couldn\'t be deleted from HW table (errno %d)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2116, ret_9, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = &bridge_6(D)->static_entries;
  isa_release (_3, static_ent_7(D));
  # DEBUG BEGIN_STMT
  return ret_9;

}



;; Function pfe_vlan_read_from_class (pfe_vlan_read_from_class, funcdef_no=15, decl_uid=10649, cgraph_uid=16, symbol_order=22)

Modification phase of node pfe_vlan_read_from_class/22
Adjusting mask for param 1 to 0xff
Adjusting mask for param 2 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting value range of param 1 [0, 255]
Setting nonnull for 2
pfe_vlan_read_from_class (const struct pfe_l2br_t * bridge, uint32_t pos, struct l2br_vlan_hash_entry_t * class_entry)
{
  struct pfe_class_t * _1;
  long unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = bridge_7(D)->class;
  _2 = bridge_7(D)->dmem_vlan_hash_base;
  _3 = pos_8(D) * 16;
  _4 = _2 + _3;
  _5 = pfe_class_read_dmem (_1, 0, class_entry_9(D), _4, 16);
  if (_5 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG D#2 => bridge_7(D)
  # DEBUG D#3 => pos_8(D)
  # DEBUG D#4 => class_entry_9(D)
  pfe_vlan_read_from_class.part.0 ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_vlan_write_to_class (pfe_vlan_write_to_class, funcdef_no=14, decl_uid=10644, cgraph_uid=15, symbol_order=21)

Modification phase of node pfe_vlan_write_to_class/21
Adjusting mask for param 1 to 0xff
Adjusting mask for param 2 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting value range of param 1 [0, 255]
Setting nonnull for 2
pfe_vlan_write_to_class (const struct pfe_l2br_t * bridge, uint32_t pos, const struct l2br_vlan_hash_entry_t * class_entry)
{
  struct pfe_class_t * _1;
  long unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = bridge_7(D)->class;
  _2 = bridge_7(D)->dmem_vlan_hash_base;
  _3 = pos_8(D) * 16;
  _4 = _2 + _3;
  _5 = pfe_class_write_dmem (_1, -1, _4, class_entry_9(D), 16);
  if (_5 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG D#8 => bridge_7(D)
  # DEBUG D#9 => pos_8(D)
  # DEBUG D#10 => class_entry_9(D)
  pfe_vlan_write_to_class.part.0 ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_l2br_update_hw_ll_entry (pfe_l2br_update_hw_ll_entry, funcdef_no=12, decl_uid=10633, cgraph_uid=13, symbol_order=19)

Modification phase of node pfe_l2br_update_hw_ll_entry/19
pfe_l2br_update_hw_ll_entry (struct pfe_l2br_domain_t * domain, uint32_t base)
{
  union pfe_ct_bd_entry_t sw_bd;
  long long unsigned int _1;
  long long unsigned int _2;
  long long unsigned int _3;
  long long unsigned int _4;
  long long unsigned int _5;
  long long unsigned int _6;
  long long unsigned int _7;
  long long unsigned int _8;
  long long unsigned int _9;
  long long unsigned int _10;
  long long unsigned int _11;
  long long unsigned int _12;
  long long unsigned int _13;
  long long unsigned int _14;
  long long unsigned int _15;
  long long unsigned int _16;
  long long unsigned int _17;
  long long unsigned int _18;
  long long unsigned int _19;
  long long unsigned int _20;
  long long unsigned int _21;
  long long unsigned int _22;
  struct pfe_l2br_t * _23;
  struct pfe_class_t * _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&sw_bd, 0, 8);
  # DEBUG BEGIN_STMT
  _1 = domain_26(D)->u.action_data.val;
  # DEBUG BEGIN_STMT
  _2 = _1 >> 56;
  _3 = _1 >> 40;
  _4 = _3 & 65280;
  _5 = _2 | _4;
  _6 = _1 >> 24;
  _7 = _6 & 16711680;
  _8 = _5 | _7;
  _9 = _1 >> 8;
  _10 = _9 & 4278190080;
  _11 = _8 | _10;
  _12 = _1 << 8;
  _13 = _12 & 1095216660480;
  _14 = _11 | _13;
  _15 = _1 << 24;
  _16 = _15 & 280375465082880;
  _17 = _14 | _16;
  _18 = _1 << 40;
  _19 = _18 & 71776119061217280;
  _20 = _17 | _19;
  _21 = _1 << 56;
  _22 = _20 | _21;
  MEM[(uint64_t *)&sw_bd] = _22;
  # DEBUG BEGIN_STMT
  _23 = domain_26(D)->bridge;
  _31 = MEM[(struct pfe_class_t * *)_23];
  # DEBUG D#14 => _23
  pfe_bd_write_to_class.isra.0 (_31, base_28(D), &sw_bd);
  # DEBUG BEGIN_STMT
  sw_bd ={v} {CLOBBER};
  return;

}



;; Function pfe_l2br_update_vlan_hash_entry (pfe_l2br_update_vlan_hash_entry, funcdef_no=17, decl_uid=10479, cgraph_uid=18, symbol_order=24)

Modification phase of node pfe_l2br_update_vlan_hash_entry/24
pfe_l2br_update_vlan_hash_entry (struct pfe_l2br_domain_t * domain)
{
  errno_t ret;
  struct l2br_vlan_hash_entry_t vlan_current_entry;
  struct l2br_vlan_hash_entry_t vlan_new_entry;
  short unsigned int _1;
  struct pfe_l2br_t * _2;
  long unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  long long unsigned int _6;
  unsigned char _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char _10;
  struct pfe_l2br_t * _11;
  unsigned char _12;
  short unsigned int _13;
  short unsigned int _14;
  struct pfe_l2br_t * _15;
  long unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  struct pfe_l2br_t * _19;
  unsigned char _20;
  unsigned char _24;
  unsigned char _30;
  unsigned char _34;
  unsigned char _41;
  long unsigned int _42;

  <bb 2> [local count: 221556076]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  autolibc_memset (&vlan_new_entry, 0, 16);
  # DEBUG BEGIN_STMT
  autolibc_memset (&vlan_current_entry, 0, 16);
  # DEBUG BEGIN_STMT
  pfe_l2br_vlan_action_to_entry (domain_28(D), &vlan_new_entry);
  # DEBUG BEGIN_STMT
  _1 = domain_28(D)->vlan;
  # DEBUG vlan_id => _1
  # DEBUG INLINE_ENTRY fp_l2br_vlan_table_get_hash
  # DEBUG BEGIN_STMT
  _30 = (unsigned char) _1;
  _41 = _30 & 63;
  # DEBUG vlan_id => NULL
  # DEBUG pos => _41
  # DEBUG BEGIN_STMT
  _2 = domain_28(D)->bridge;
  _3 = (long unsigned int) _41;
  pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  # DEBUG BEGIN_STMT
  _4 = vlan_current_entry.vlan;
  _5 = vlan_new_entry.vlan;
  if (_4 == _5)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 44842950]:
  # DEBUG BEGIN_STMT
  _6 = vlan_new_entry.entry.val;
  vlan_current_entry.entry.val = _6;
  # DEBUG BEGIN_STMT
  _7 = vlan_current_entry.flags;
  _8 = _7 | 8;
  vlan_current_entry.flags = _8;
  # DEBUG BEGIN_STMT
  _9 = vlan_current_entry.field_valids;
  _10 = _9 | 2;
  vlan_current_entry.field_valids = _10;
  # DEBUG BEGIN_STMT
  _11 = domain_28(D)->bridge;
  pfe_vlan_write_to_class (_11, _3, &vlan_current_entry);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 176713126]:
  # DEBUG BEGIN_STMT
  _12 = vlan_current_entry.flags;
  _24 = _12 & 8;
  if (_24 != 0)
    goto <bb 9>; [65.00%]
  else
    goto <bb 8>; [35.00%]

  <bb 5> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _13 = vlan_current_entry.col_ptr;
  _14 = _13 >> 8;
  # DEBUG pos => (uint8_t) _14
  # DEBUG BEGIN_STMT
  _15 = domain_28(D)->bridge;
  _16 = (long unsigned int) _14;
  pfe_vlan_read_from_class (_15, _16, &vlan_current_entry);
  # DEBUG BEGIN_STMT
  _17 = vlan_new_entry.vlan;
  _18 = vlan_current_entry.vlan;
  if (_17 == _18)
    goto <bb 6>; [5.50%]
  else
    goto <bb 10>; [94.50%]

  <bb 10> [local count: 958878294]:
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 55807731]:
  # _42 = PHI <_16(5)>
  # DEBUG BEGIN_STMT
  _19 = domain_28(D)->bridge;
  pfe_vlan_write_to_class (_19, _42, &vlan_new_entry);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 114863532]:

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _20 = vlan_current_entry.flags;
  _34 = _20 & 4;
  if (_34 != 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 221556076]:
  # ret_21 = PHI <0(3), 2(4), 0(6), 2(7)>
  # DEBUG ret => ret_21
  # DEBUG BEGIN_STMT
  vlan_new_entry ={v} {CLOBBER};
  vlan_current_entry ={v} {CLOBBER};
  return ret_21;

}



;; Function pfe_l2br_update_hw_entry (pfe_l2br_update_hw_entry, funcdef_no=21, decl_uid=10557, cgraph_uid=22, symbol_order=28)

Modification phase of node pfe_l2br_update_hw_entry/28
pfe_l2br_update_hw_entry (struct pfe_l2br_domain_t * domain)
{
  errno_t ret;
  unsigned char _1;
  struct pfe_l2br_t * _2;
  long unsigned int _3;
  unsigned char _4;
  unsigned char _5;
  struct pfe_l2br_t * _6;
  long unsigned int _7;
  unsigned char _8;
  struct pfe_l2br_table_entry_t * _9;
  long long unsigned int _10;
  unsigned char _11;
  struct pfe_l2br_t * _12;
  struct pfe_l2br_table_t * _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_20(D)->is_fallback;
  if (_1 == 1)
    goto <bb 3>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  _2 = domain_20(D)->bridge;
  _3 = _2->dmem_fb_bd_base;
  pfe_l2br_update_hw_ll_entry (domain_20(D), _3);
  # DEBUG BEGIN_STMT
  _4 = pfe_feature_mgr_is_available ("software_vlan_table");
  if (_4 == 1)
    goto <bb 4>; [20.24%]
  else
    goto <bb 16>; [79.76%]

  <bb 4> [local count: 43986650]:
  # DEBUG BEGIN_STMT
  pfe_l2br_update_vlan_hash_entry (domain_20(D));
  goto <bb 16>; [100.00%]

  <bb 6> [local count: 856416480]:
  # DEBUG BEGIN_STMT
  _5 = domain_20(D)->is_default;
  if (_5 == 1)
    goto <bb 7>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 7> [local count: 173338695]:
  # DEBUG BEGIN_STMT
  _6 = domain_20(D)->bridge;
  _7 = _6->dmem_def_bd_base;
  pfe_l2br_update_hw_ll_entry (domain_20(D), _7);
  # DEBUG BEGIN_STMT
  _8 = pfe_feature_mgr_is_available ("software_vlan_table");
  if (_8 == 1)
    goto <bb 8>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 8> [local count: 35083752]:
  # DEBUG BEGIN_STMT
  pfe_l2br_update_vlan_hash_entry (domain_20(D));

  <bb 9> [local count: 856416479]:
  # DEBUG BEGIN_STMT
  _9 = &domain_20(D)->vlan_entry;
  _10 = domain_20(D)->u.action_data_u64val;
  ret_25 = pfe_l2br_table_entry_set_action_data (_9, _10);
  # DEBUG ret => ret_25
  # DEBUG BEGIN_STMT
  if (ret_25 != 0)
    goto <bb 10>; [35.00%]
  else
    goto <bb 11>; [65.00%]

  <bb 10> [local count: 299745768]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t set action data: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 757, ret_25, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 114
  goto <bb 16>; [100.00%]

  <bb 11> [local count: 556670711]:
  # DEBUG BEGIN_STMT
  _11 = pfe_feature_mgr_is_available ("software_vlan_table");
  if (_11 == 1)
    goto <bb 12>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 12> [local count: 189268041]:
  # DEBUG BEGIN_STMT
  ret_30 = pfe_l2br_update_vlan_hash_entry (domain_20(D));
  # DEBUG ret => ret_30
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 367402669]:
  # DEBUG BEGIN_STMT
  _12 = domain_20(D)->bridge;
  _13 = _12->vlan_table;
  ret_28 = pfe_l2br_table_update_entry (_13, _9);
  # DEBUG ret => ret_28

  <bb 14> [local count: 556670711]:
  # ret_14 = PHI <ret_30(12), ret_28(13)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  if (ret_14 != 0)
    goto <bb 15>; [20.96%]
  else
    goto <bb 16>; [79.04%]

  <bb 15> [local count: 116678181]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t update VLAN table entry: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 773, ret_14, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 114

  <bb 16> [local count: 1073741824]:
  # ret_15 = PHI <0(4), 114(10), ret_14(14), 114(15), 0(3)>
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  return ret_15;

}



;; Function pfe_l2br_add_vlan_hash_entry (pfe_l2br_add_vlan_hash_entry, funcdef_no=19, decl_uid=10481, cgraph_uid=20, symbol_order=26)

Modification phase of node pfe_l2br_add_vlan_hash_entry/26
pfe_l2br_add_vlan_hash_entry (struct pfe_l2br_domain_t * domain)
{
  errno_t ret;
  uint8_t pos;
  struct l2br_vlan_hash_entry_t vlan_current_entry;
  struct l2br_vlan_hash_entry_t vlan_new_entry;
  short unsigned int _1;
  struct pfe_l2br_t * _2;
  long unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  unsigned char _6;
  short unsigned int _7;
  short unsigned int _8;
  struct pfe_l2br_t * _9;
  long unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  unsigned char _13;
  struct pfe_l2br_t * _14;
  unsigned char _21;
  unsigned char _27;
  unsigned char _34;
  struct pfe_l2br_t * * _37;
  unsigned char _38;

  <bb 2> [local count: 219006269]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  autolibc_memset (&vlan_new_entry, 0, 16);
  # DEBUG BEGIN_STMT
  autolibc_memset (&vlan_current_entry, 0, 16);
  # DEBUG BEGIN_STMT
  pfe_l2br_vlan_action_to_entry (domain_25(D), &vlan_new_entry);
  # DEBUG BEGIN_STMT
  _1 = domain_25(D)->vlan;
  # DEBUG vlan_id => _1
  # DEBUG INLINE_ENTRY fp_l2br_vlan_table_get_hash
  # DEBUG BEGIN_STMT
  _27 = (unsigned char) _1;
  _38 = _27 & 63;
  # DEBUG vlan_id => NULL
  # DEBUG pos => _38
  # DEBUG BEGIN_STMT
  _2 = domain_25(D)->bridge;
  _3 = (long unsigned int) _38;
  pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  # DEBUG BEGIN_STMT
  _4 = vlan_current_entry.vlan;
  _5 = vlan_new_entry.vlan;
  if (_4 == _5)
    goto <bb 8>; [21.72%]
  else
    goto <bb 3>; [78.28%]

  <bb 3> [local count: 171438108]:
  # DEBUG BEGIN_STMT
  _6 = vlan_current_entry.flags;
  _21 = _6 & 8;
  if (_21 != 0)
    goto <bb 9>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 9> [local count: 114863532]:
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _7 = vlan_current_entry.col_ptr;
  _8 = _7 >> 8;
  pos_30 = (uint8_t) _8;
  # DEBUG pos => pos_30
  # DEBUG BEGIN_STMT
  _9 = domain_25(D)->bridge;
  _10 = (long unsigned int) _8;
  pfe_vlan_read_from_class (_9, _10, &vlan_current_entry);
  # DEBUG BEGIN_STMT
  _11 = vlan_new_entry.vlan;
  _12 = vlan_current_entry.vlan;
  if (_11 == _12)
    goto <bb 6>; [5.50%]
  else
    goto <bb 10>; [94.50%]

  <bb 10> [local count: 958878294]:

  <bb 5> [local count: 1073741824]:
  # pos_15 = PHI <_38(9), pos_30(10)>
  # DEBUG pos => pos_15
  # DEBUG BEGIN_STMT
  _13 = vlan_current_entry.flags;
  _34 = _13 & 4;
  if (_34 != 0)
    goto <bb 4>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 114863532]:
  # pos_16 = PHI <pos_30(4), pos_15(5)>
  # DEBUG pos => pos_16
  # DEBUG BEGIN_STMT
  _37 = &MEM[(struct pfe_l2br_t * *)domain_25(D) + 40B];
  # DEBUG D#15 => domain_25(D)
  ret_33 = pfe_l2br_add_vlan_to_collision_space.isra.0 (_37, &vlan_new_entry, pos_16);
  # DEBUG ret => ret_33
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 56574575]:
  # DEBUG BEGIN_STMT
  _14 = domain_25(D)->bridge;
  pfe_vlan_write_to_class (_14, _3, &vlan_new_entry);

  <bb 8> [local count: 219006269]:
  # ret_17 = PHI <116(2), ret_33(6), 0(7)>
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  vlan_new_entry ={v} {CLOBBER};
  vlan_current_entry ={v} {CLOBBER};
  return ret_17;

}



;; Function pfe_l2br_delete_vlan_hash_entry (pfe_l2br_delete_vlan_hash_entry, funcdef_no=20, decl_uid=10483, cgraph_uid=21, symbol_order=27)

Modification phase of node pfe_l2br_delete_vlan_hash_entry/27
pfe_l2br_delete_vlan_hash_entry (struct pfe_l2br_domain_t * domain)
{
  bool_t erase_collision_entry;
  uint8_t next_entry_pos;
  uint8_t pos;
  struct l2br_vlan_hash_entry_t vlan_tmp_entry;
  struct l2br_vlan_hash_entry_t vlan_prev_entry;
  struct l2br_vlan_hash_entry_t vlan_current_entry;
  struct l2br_vlan_hash_entry_t vlan_zero_entry;
  short unsigned int _1;
  struct pfe_l2br_t * _2;
  long unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  short unsigned int _6;
  unsigned char _7;
  short unsigned int _8;
  short unsigned int _9;
  struct pfe_l2br_t * _10;
  long unsigned int _11;
  struct pfe_l2br_t * _12;
  struct pfe_l2br_t * _13;
  long unsigned int _14;
  short unsigned int _15;
  short unsigned int _16;
  struct pfe_l2br_t * _17;
  long unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;
  unsigned char _22;
  short unsigned int _23;
  struct pfe_l2br_t * _24;
  long unsigned int _25;
  struct pfe_l2br_t * _26;
  unsigned char _27;
  unsigned char _35;
  unsigned char _36;
  unsigned char _43;
  unsigned char _57;
  unsigned char _64;
  long unsigned int _65;

  <bb 2> [local count: 174035655]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG erase_collision_entry => 0
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  autolibc_memset (&vlan_zero_entry, 0, 16);
  # DEBUG BEGIN_STMT
  autolibc_memset (&vlan_current_entry, 0, 16);
  # DEBUG BEGIN_STMT
  autolibc_memset (&vlan_prev_entry, 0, 16);
  # DEBUG BEGIN_STMT
  autolibc_memset (&vlan_tmp_entry, 0, 16);
  # DEBUG BEGIN_STMT
  _1 = domain_42(D)->vlan;
  # DEBUG vlan_id => _1
  # DEBUG INLINE_ENTRY fp_l2br_vlan_table_get_hash
  # DEBUG BEGIN_STMT
  _43 = (unsigned char) _1;
  _64 = _43 & 63;
  # DEBUG vlan_id => NULL
  # DEBUG pos => _64
  # DEBUG BEGIN_STMT
  _2 = domain_42(D)->bridge;
  _3 = (long unsigned int) _64;
  pfe_vlan_read_from_class (_2, _3, &vlan_current_entry);
  # DEBUG BEGIN_STMT
  _4 = domain_42(D)->vlan;
  _5 = vlan_current_entry.vlan;
  _6 = _5 r>> 8;
  if (_4 == _6)
    goto <bb 3>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 3> [local count: 59172123]:
  # DEBUG BEGIN_STMT
  _7 = vlan_current_entry.flags;
  _57 = _7 & 4;
  if (_57 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 19526800]:
  # DEBUG BEGIN_STMT
  _8 = vlan_current_entry.col_ptr;
  _9 = _8 >> 8;
  next_entry_pos_55 = (uint8_t) _9;
  # DEBUG next_entry_pos => next_entry_pos_55
  # DEBUG BEGIN_STMT
  _10 = domain_42(D)->bridge;
  _11 = (long unsigned int) _9;
  pfe_vlan_read_from_class (_10, _11, &vlan_tmp_entry);
  # DEBUG BEGIN_STMT
  # DEBUG erase_collision_entry => 1

  <bb 5> [local count: 59172123]:
  # next_entry_pos_29 = PHI <next_entry_pos_54(D)(3), next_entry_pos_55(4)>
  # erase_collision_entry_30 = PHI <0(3), 1(4)>
  # DEBUG erase_collision_entry => erase_collision_entry_30
  # DEBUG next_entry_pos => next_entry_pos_29
  # DEBUG BEGIN_STMT
  _12 = domain_42(D)->bridge;
  pfe_vlan_write_to_class (_12, _3, &vlan_tmp_entry);
  # DEBUG BEGIN_STMT
  if (erase_collision_entry_30 == 1)
    goto <bb 6>; [20.24%]
  else
    goto <bb 13>; [79.76%]

  <bb 6> [local count: 11976438]:
  # DEBUG BEGIN_STMT
  _13 = domain_42(D)->bridge;
  _14 = (long unsigned int) next_entry_pos_29;
  pfe_vlan_write_to_class (_13, _14, &vlan_zero_entry);
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  # DEBUG prev_entry_pos => pos_28
  # DEBUG BEGIN_STMT
  vlan_prev_entry = vlan_current_entry;
  # DEBUG BEGIN_STMT
  _15 = vlan_current_entry.col_ptr;
  _16 = _15 >> 8;
  pos_47 = (uint8_t) _16;
  # DEBUG pos => pos_47
  # DEBUG BEGIN_STMT
  _17 = domain_42(D)->bridge;
  _18 = (long unsigned int) _16;
  pfe_vlan_read_from_class (_17, _18, &vlan_current_entry);
  # DEBUG BEGIN_STMT
  _19 = domain_42(D)->vlan;
  _20 = vlan_current_entry.vlan;
  _21 = _20 r>> 8;
  if (_19 == _21)
    goto <bb 8>; [5.50%]
  else
    goto <bb 15>; [94.50%]

  <bb 15> [local count: 958878292]:
  goto <bb 12>; [100.00%]

  <bb 8> [local count: 55807731]:
  # _65 = PHI <_18(7)>
  # pos_44 = PHI <pos_28(7)>
  # DEBUG BEGIN_STMT
  _22 = vlan_current_entry.flags;
  _36 = _22 & 4;
  if (_36 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 27903866]:
  # DEBUG BEGIN_STMT
  _23 = vlan_current_entry.col_ptr;
  vlan_prev_entry.col_ptr = _23;
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 27903866]:
  # DEBUG BEGIN_STMT
  vlan_prev_entry.flags = 0;
  # DEBUG BEGIN_STMT
  vlan_prev_entry.col_ptr = 0;

  <bb 11> [local count: 55807731]:
  # DEBUG BEGIN_STMT
  _24 = domain_42(D)->bridge;
  _25 = (long unsigned int) pos_44;
  pfe_vlan_write_to_class (_24, _25, &vlan_prev_entry);
  # DEBUG BEGIN_STMT
  _26 = domain_42(D)->bridge;
  pfe_vlan_write_to_class (_26, _65, &vlan_zero_entry);
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 14> [local count: 114863532]:

  <bb 12> [local count: 1073741824]:
  # pos_28 = PHI <_64(14), pos_47(15)>
  # DEBUG pos => pos_28
  # DEBUG BEGIN_STMT
  _27 = vlan_current_entry.flags;
  _35 = _27 & 4;
  if (_35 != 0)
    goto <bb 7>; [94.50%]
  else
    goto <bb 13>; [5.50%]

  <bb 13> [local count: 174035654]:
  # DEBUG BEGIN_STMT
  vlan_zero_entry ={v} {CLOBBER};
  vlan_current_entry ={v} {CLOBBER};
  vlan_prev_entry ={v} {CLOBBER};
  vlan_tmp_entry ={v} {CLOBBER};
  return 0;

}



;; Function pfe_l2br_domain_destroy (pfe_l2br_domain_destroy, funcdef_no=30, decl_uid=10342, cgraph_uid=31, symbol_order=37)

Modification phase of node pfe_l2br_domain_destroy/37
pfe_l2br_domain_destroy (struct pfe_l2br_domain_t * domain)
{
  const int64_t domain_subscript;
  errno_t ret;
  <unnamed type> _1;
  unsigned char _2;
  struct pfe_l2br_t * _3;
  struct pfe_l2br_table_t * _4;
  struct pfe_l2br_table_entry_t * _5;
  struct pfe_l2br_table_entry_t * _6;
  struct pfe_l2br_t * _7;
  struct pfe_isa_t * _8;
  long int _9;
  struct pfe_l2br_t * _10;
  long unsigned int _11;
  long long int _12;
  long unsigned int _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_19(D)->vlan_entry.type;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 = pfe_feature_mgr_is_available ("software_vlan_table");
  if (_2 == 1)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 182536110]:
  # DEBUG BEGIN_STMT
  ret_24 = pfe_l2br_delete_vlan_hash_entry (domain_19(D));
  # DEBUG ret => ret_24
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _3 = domain_19(D)->bridge;
  _4 = _3->vlan_table;
  _5 = &domain_19(D)->vlan_entry;
  ret_22 = pfe_l2br_table_del_entry (_4, _5);
  # DEBUG ret => ret_22

  <bb 6> [local count: 536870913]:
  # ret_14 = PHI <ret_24(4), ret_22(5)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  if (ret_14 != 0)
    goto <bb 7>; [35.00%]
  else
    goto <bb 8>; [65.00%]

  <bb 7> [local count: 187904819]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t delete entry from VLAN table: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 1116, ret_14, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 114
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 8> [local count: 348966093]:
  # DEBUG BEGIN_STMT
  _6 = &domain_19(D)->vlan_entry;
  pfe_l2br_table_entry_destroy (_6);
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 885837006]:
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  ret_29 = pfe_l2br_domain_destroy_instance (domain_19(D));
  # DEBUG ret => ret_29
  # DEBUG BEGIN_STMT
  _7 = domain_19(D)->bridge;
  _8 = &_7->domains;
  _9 = isa_release (_8, domain_19(D));
  domain_subscript_31 = (const int64_t) _9;
  # DEBUG domain_subscript => domain_subscript_31
  # DEBUG BEGIN_STMT
  if (domain_subscript_31 >= 0)
    goto <bb 10>; [59.00%]
  else
    goto <bb 12>; [41.00%]

  <bb 10> [local count: 522643833]:
  _10 = domain_19(D)->bridge;
  _11 = _10->curr_domain;
  _12 = (long long int) _11;
  if (_12 > domain_subscript_31)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 261321916]:
  # DEBUG BEGIN_STMT
  _13 = _11 + 4294967295;
  _10->curr_domain = _13;

  <bb 12> [local count: 1073741824]:
  # ret_15 = PHI <114(7), ret_29(9), ret_29(10), ret_29(11)>
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  return ret_15;

}



;; Function pfe_l2br_domain_destroy_log (pfe_l2br_domain_destroy_log, funcdef_no=26, decl_uid=10624, cgraph_uid=27, symbol_order=33)

Modification phase of node pfe_l2br_domain_destroy_log/33
pfe_l2br_domain_destroy_log (struct pfe_l2br_domain_t * domain)
{
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pfe_l2br_domain_destroy (domain_3(D));
  if (_1 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG D#19 => domain_3(D)
  pfe_l2br_domain_destroy_log.part.0 ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_l2br_domain_set_ucast_action (pfe_l2br_domain_set_ucast_action, funcdef_no=33, decl_uid=10346, cgraph_uid=34, symbol_order=40)

Modification phase of node pfe_l2br_domain_set_ucast_action/40
pfe_l2br_domain_set_ucast_action (struct pfe_l2br_domain_t * domain, pfe_ct_l2br_action_t hit, pfe_ct_l2br_action_t miss)
{
  errno_t ret;
  <unnamed-unsigned:3> _1;
  <unnamed-unsigned:3> _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (<unnamed-unsigned:3>) hit_3(D);
  domain_5(D)->u.action_data.item.ucast_hit_action = _1;
  # DEBUG BEGIN_STMT
  _2 = (<unnamed-unsigned:3>) miss_7(D);
  domain_5(D)->u.action_data.item.ucast_miss_action = _2;
  # DEBUG BEGIN_STMT
  ret_10 = pfe_l2br_update_hw_entry (domain_5(D));
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  return ret_10;

}



;; Function pfe_l2br_domain_get_ucast_action (pfe_l2br_domain_get_ucast_action, funcdef_no=34, decl_uid=10373, cgraph_uid=35, symbol_order=41)

Modification phase of node pfe_l2br_domain_get_ucast_action/41
pfe_l2br_domain_get_ucast_action (const struct pfe_l2br_domain_t * domain, pfe_ct_l2br_action_t * hit, pfe_ct_l2br_action_t * miss)
{
  <unnamed-unsigned:3> _1;
  <unnamed type> _2;
  <unnamed-unsigned:3> _3;
  <unnamed type> _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_6(D)->u.action_data.item.ucast_hit_action;
  _2 = (<unnamed type>) _1;
  *hit_7(D) = _2;
  # DEBUG BEGIN_STMT
  _3 = domain_6(D)->u.action_data.item.ucast_miss_action;
  _4 = (<unnamed type>) _3;
  *miss_9(D) = _4;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_l2br_domain_set_mcast_action (pfe_l2br_domain_set_mcast_action, funcdef_no=35, decl_uid=10350, cgraph_uid=36, symbol_order=42)

Modification phase of node pfe_l2br_domain_set_mcast_action/42
pfe_l2br_domain_set_mcast_action (struct pfe_l2br_domain_t * domain, pfe_ct_l2br_action_t hit, pfe_ct_l2br_action_t miss)
{
  errno_t ret;
  <unnamed-unsigned:3> _1;
  <unnamed-unsigned:3> _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (<unnamed-unsigned:3>) hit_3(D);
  domain_5(D)->u.action_data.item.mcast_hit_action = _1;
  # DEBUG BEGIN_STMT
  _2 = (<unnamed-unsigned:3>) miss_7(D);
  domain_5(D)->u.action_data.item.mcast_miss_action = _2;
  # DEBUG BEGIN_STMT
  ret_10 = pfe_l2br_update_hw_entry (domain_5(D));
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  return ret_10;

}



;; Function pfe_l2br_domain_get_mcast_action (pfe_l2br_domain_get_mcast_action, funcdef_no=36, decl_uid=10377, cgraph_uid=37, symbol_order=43)

Modification phase of node pfe_l2br_domain_get_mcast_action/43
pfe_l2br_domain_get_mcast_action (const struct pfe_l2br_domain_t * domain, pfe_ct_l2br_action_t * hit, pfe_ct_l2br_action_t * miss)
{
  <unnamed-unsigned:3> _1;
  <unnamed type> _2;
  <unnamed-unsigned:3> _3;
  <unnamed type> _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_6(D)->u.action_data.item.mcast_hit_action;
  _2 = (<unnamed type>) _1;
  *hit_7(D) = _2;
  # DEBUG BEGIN_STMT
  _3 = domain_6(D)->u.action_data.item.mcast_miss_action;
  _4 = (<unnamed type>) _3;
  *miss_9(D) = _4;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_l2br_domain_add_if (pfe_l2br_domain_add_if, funcdef_no=37, decl_uid=10354, cgraph_uid=38, symbol_order=44)

Modification phase of node pfe_l2br_domain_add_if/44
pfe_l2br_domain_add_if (struct pfe_l2br_domain_t * domain, struct pfe_phy_if_t * iface, bool_t tagged)
{
  uint64_t ifc_mask;
  pfe_ct_phy_if_id_t id;
  errno_t ret;
  int _1;
  long long unsigned int _2;
  long long unsigned int _3;
  <unnamed-unsigned:18> _4;
  unsigned int _5;
  unsigned int _6;
  unsigned int _7;
  <unnamed-unsigned:18> _8;
  <unnamed-unsigned:18> _9;
  unsigned int _10;
  unsigned int _11;
  <unnamed-unsigned:18> _12;
  long long unsigned int _13;
  long long unsigned int _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  id_20 = pfe_phy_if_get_id (iface_19(D));
  # DEBUG id => id_20
  # DEBUG BEGIN_STMT
  _1 = (int) id_20;
  ifc_mask_21 = 1 << _1;
  # DEBUG ifc_mask => ifc_mask_21
  # DEBUG BEGIN_STMT
  _2 = domain_22(D)->ifaces;
  _3 = _2 & ifc_mask_21;
  if (_3 == 0)
    goto <bb 3>; [65.00%]
  else
    goto <bb 7>; [35.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _4 = domain_22(D)->u.action_data.item.forward_list;
  _5 = (unsigned int) _4;
  _6 = (unsigned int) ifc_mask_21;
  _7 = _5 | _6;
  _8 = (<unnamed-unsigned:18>) _7;
  domain_22(D)->u.action_data.item.forward_list = _8;
  # DEBUG BEGIN_STMT
  if (tagged_24(D) == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 348966093]:
  # DEBUG BEGIN_STMT
  _9 = domain_22(D)->u.action_data.item.untag_list;
  _10 = (unsigned int) _9;
  _11 = _6 | _10;
  _12 = (<unnamed-unsigned:18>) _11;
  domain_22(D)->u.action_data.item.untag_list = _12;

  <bb 5> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  ret_27 = pfe_l2br_update_hw_entry (domain_22(D));
  # DEBUG ret => ret_27
  # DEBUG BEGIN_STMT
  if (ret_27 != 0)
    goto <bb 7>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 6> [local count: 453655921]:
  # DEBUG BEGIN_STMT
  _13 = domain_22(D)->ifaces;
  _14 = _13 | ifc_mask_21;
  domain_22(D)->ifaces = _14;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741824]:
  # ret_15 = PHI <0(6), 116(2), 114(5)>
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  return ret_15;

}



;; Function pfe_l2br_domain_del_if (pfe_l2br_domain_del_if, funcdef_no=38, decl_uid=10357, cgraph_uid=39, symbol_order=45)

Modification phase of node pfe_l2br_domain_del_if/45
pfe_l2br_domain_del_if (struct pfe_l2br_domain_t * domain, const struct pfe_phy_if_t * iface)
{
  uint64_t ifc_mask;
  pfe_ct_phy_if_id_t id;
  errno_t ret;
  int _1;
  long long unsigned int _2;
  long long unsigned int _3;
  <unnamed-unsigned:18> _4;
  unsigned int _5;
  unsigned int _6;
  unsigned int _7;
  unsigned int _8;
  <unnamed-unsigned:18> _9;
  <unnamed-unsigned:18> _10;
  unsigned int _11;
  unsigned int _12;
  <unnamed-unsigned:18> _13;
  long long unsigned int _14;
  long long unsigned int _15;
  long long unsigned int _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  id_21 = pfe_phy_if_get_id (iface_20(D));
  # DEBUG id => id_21
  # DEBUG BEGIN_STMT
  _1 = (int) id_21;
  ifc_mask_22 = 1 << _1;
  # DEBUG ifc_mask => ifc_mask_22
  # DEBUG BEGIN_STMT
  _2 = domain_23(D)->ifaces;
  _3 = _2 & ifc_mask_22;
  if (_3 != 0)
    goto <bb 3>; [47.77%]
  else
    goto <bb 6>; [52.23%]

  <bb 3> [local count: 512926469]:
  # DEBUG BEGIN_STMT
  _4 = domain_23(D)->u.action_data.item.forward_list;
  _5 = (unsigned int) _4;
  _6 = (unsigned int) ifc_mask_22;
  _7 = ~_6;
  _8 = _5 & _7;
  _9 = (<unnamed-unsigned:18>) _8;
  domain_23(D)->u.action_data.item.forward_list = _9;
  # DEBUG BEGIN_STMT
  _10 = domain_23(D)->u.action_data.item.untag_list;
  _11 = (unsigned int) _10;
  _12 = _7 & _11;
  _13 = (<unnamed-unsigned:18>) _12;
  domain_23(D)->u.action_data.item.untag_list = _13;
  # DEBUG BEGIN_STMT
  ret_27 = pfe_l2br_update_hw_entry (domain_23(D));
  # DEBUG ret => ret_27
  # DEBUG BEGIN_STMT
  if (ret_27 != 0)
    goto <bb 4>; [20.96%]
  else
    goto <bb 5>; [79.04%]

  <bb 4> [local count: 107509388]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] VLAN table entry update failed: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 1495, ret_27, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 114
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 405417081]:
  # DEBUG BEGIN_STMT
  _14 = domain_23(D)->ifaces;
  _15 = ~ifc_mask_22;
  _16 = _14 & _15;
  domain_23(D)->ifaces = _16;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 6> [local count: 1073741824]:
  # ret_17 = PHI <0(5), 2(2), 114(4)>
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  return ret_17;

}



;; Function pfe_l2br_domain_flush_by_if (pfe_l2br_domain_flush_by_if, funcdef_no=41, decl_uid=10360, cgraph_uid=42, symbol_order=48)

Modification phase of node pfe_l2br_domain_flush_by_if/48
pfe_l2br_domain_flush_by_if (const struct pfe_l2br_domain_t * domain, const struct pfe_phy_if_t * iface)
{
  struct pfe_l2br_t * bridge;
  uint32_t iface_bitflag;
  struct pfe_l2br_table_iterator_t l2t_iter;
  struct pfe_l2br_table_entry_t entry;
  errno_t ret;
  <unnamed type> _1;
  long unsigned int _2;
  struct pfe_l2br_table_t * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG iface_bitflag => 0
  # DEBUG BEGIN_STMT
  # DEBUG bridge => 0B
  # DEBUG BEGIN_STMT
  bridge_6 = domain_5(D)->bridge;
  # DEBUG bridge => bridge_6
  # DEBUG BEGIN_STMT
  _1 = pfe_phy_if_get_id (iface_7(D));
  _2 = (long unsigned int) _1;
  iface_bitflag_8 = 1 << _2;
  # DEBUG iface_bitflag => iface_bitflag_8
  # DEBUG BEGIN_STMT
  _3 = bridge_6->mac_table;
  pfe_l2br_table_entry_create (_3, &entry);
  # DEBUG BEGIN_STMT
  pfe_l2br_iterator_create (&l2t_iter);
  # DEBUG BEGIN_STMT
  ret_12 = pfe_l2br_domain_flush_by_if_dynamic_static (domain_5(D), bridge_6, &l2t_iter, &entry, iface_bitflag_8);
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  pfe_l2br_table_entry_destroy (&entry);
  # DEBUG BEGIN_STMT
  pfe_l2br_iterator_destroy (&l2t_iter);
  # DEBUG BEGIN_STMT
  entry ={v} {CLOBBER};
  l2t_iter ={v} {CLOBBER};
  return ret_12;

}



;; Function pfe_l2br_domain_get_if_list (pfe_l2br_domain_get_if_list, funcdef_no=42, decl_uid=10383, cgraph_uid=43, symbol_order=49)

Modification phase of node pfe_l2br_domain_get_if_list/49
__attribute__((pure))
pfe_l2br_domain_get_if_list (const struct pfe_l2br_domain_t * domain)
{
  uint32_t ret;
  <unnamed-unsigned:18> _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_3(D)->u.action_data.item.forward_list;
  ret_4 = (uint32_t) _1;
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_l2br_domain_get_untag_if_list (pfe_l2br_domain_get_untag_if_list, funcdef_no=43, decl_uid=10385, cgraph_uid=44, symbol_order=50)

Modification phase of node pfe_l2br_domain_get_untag_if_list/50
__attribute__((pure))
pfe_l2br_domain_get_untag_if_list (const struct pfe_l2br_domain_t * domain)
{
  uint32_t untag_if_list;
  <unnamed-unsigned:18> _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_3(D)->u.action_data.item.untag_list;
  untag_if_list_4 = (uint32_t) _1;
  # DEBUG untag_if_list => untag_if_list_4
  # DEBUG BEGIN_STMT
  return untag_if_list_4;

}



;; Function pfe_l2br_domain_get_next_if (pfe_l2br_domain_get_next_if, funcdef_no=46, decl_uid=10366, cgraph_uid=47, symbol_order=53)

Modification phase of node pfe_l2br_domain_get_next_if/53
pfe_l2br_domain_get_next_if (struct pfe_l2br_domain_t * domain)
{
  bool_t match;
  uint64_t ifaces;
  uint64_t ifc_mask;
  struct pfe_phy_if_t * phy_if;
  unsigned char _1;
  int _2;
  long long unsigned int _3;
  long long unsigned int _4;
  int _5;
  <unnamed type> _6;
  unsigned char _7;
  long long unsigned int _8;
  unsigned char _9;
  unsigned char _10;
  unsigned char _11;

  <bb 2> [local count: 77472354]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG match => 0
  # DEBUG BEGIN_STMT
  _1 = domain_23(D)->cur_item;
  _2 = (int) _1;
  ifc_mask_24 = 1 << _2;
  # DEBUG ifc_mask => ifc_mask_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ifaces_25 = domain_23(D)->ifaces;
  # DEBUG ifaces => ifaces_25
  # DEBUG BEGIN_STMT
  _3 = -ifc_mask_24;
  ifaces_26 = _3 & ifaces_25;
  # DEBUG ifaces => ifaces_26
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  _4 = ifc_mask_16 & ifaces_17;
  if (_4 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 334846388]:
  # DEBUG BEGIN_STMT
  _5 = (int) _11;
  _6 = pfe_index_to_phy_if_id[_5];
  phy_if_28 = pfe_phy_if_get_phy (_6);
  # DEBUG phy_if => phy_if_28
  # DEBUG BEGIN_STMT
  _7 = pfe_l2br_domain_match_if_criterion (domain_23(D), phy_if_28);
  if (_7 == 1)
    goto <bb 7>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 5> [local count: 996269474]:
  # phy_if_12 = PHI <phy_if_13(3), phy_if_28(4)>
  # DEBUG phy_if => phy_if_12
  # DEBUG BEGIN_STMT
  _8 = ~ifc_mask_16;
  ifaces_30 = _8 & ifaces_17;
  # DEBUG ifaces => ifaces_30
  # DEBUG BEGIN_STMT
  ifc_mask_31 = ifc_mask_16 << 1;
  # DEBUG ifc_mask => ifc_mask_31
  # DEBUG BEGIN_STMT
  _9 = domain_23(D)->cur_item;
  _10 = _9 + 1;
  domain_23(D)->cur_item = _10;

  <bb 6> [local count: 1073741824]:
  # phy_if_13 = PHI <phy_if_27(D)(2), phy_if_12(5)>
  # ifc_mask_16 = PHI <ifc_mask_24(2), ifc_mask_31(5)>
  # ifaces_17 = PHI <ifaces_26(2), ifaces_30(5)>
  # DEBUG ifaces => ifaces_17
  # DEBUG ifc_mask => ifc_mask_16
  # DEBUG phy_if => phy_if_13
  # DEBUG BEGIN_STMT
  _11 = domain_23(D)->cur_item;
  if (_11 <= 9)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 77472352]:
  # phy_if_14 = PHI <phy_if_28(4), phy_if_13(6)>
  # match_18 = PHI <1(4), 0(6)>
  # DEBUG match => match_18
  # DEBUG phy_if => phy_if_14
  # DEBUG BEGIN_STMT
  if (match_18 == 0)
    goto <bb 8>; [29.00%]
  else
    goto <bb 9>; [71.00%]

  <bb 8> [local count: 22466982]:
  # DEBUG BEGIN_STMT
  # DEBUG phy_if => 0B

  <bb 9> [local count: 77472352]:
  # phy_if_15 = PHI <phy_if_14(7), 0B(8)>
  # DEBUG phy_if => phy_if_15
  # DEBUG BEGIN_STMT
  return phy_if_15;

}



;; Function pfe_l2br_domain_get_first_if (pfe_l2br_domain_get_first_if, funcdef_no=45, decl_uid=10364, cgraph_uid=46, symbol_order=52)

Modification phase of node pfe_l2br_domain_get_first_if/52
pfe_l2br_domain_get_first_if (struct pfe_l2br_domain_t * domain, pfe_l2br_domain_if_get_crit_t crit, void * arg)
{
  uint32_t phy_idx;
  static const pfe_ct_phy_if_id_t phys[10];
  struct pfe_phy_if_t * phy_if;
  <unnamed type> _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG phy_if => 0B
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG phy_idx => 0
  # DEBUG BEGIN_STMT
  domain_5(D)->cur_crit = crit_6(D);
  # DEBUG BEGIN_STMT
  switch (crit_6(D)) <default: <L3> [25.00%], case 0: <L10> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  phy_idx_10 = (uint32_t) arg_8(D);
  # DEBUG phy_idx => phy_idx_10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = phys[phy_idx_10];
  domain_5(D)->cur_crit_arg.id = _1;
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  domain_5(D)->cur_crit_arg.phy_if = arg_8(D);
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 268435456]:
<L3>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unknown criterion\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 1799, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 0
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 0
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 805306369]:
<L10>:
  # DEBUG known_crit => NULL
  # DEBUG BEGIN_STMT
  domain_5(D)->cur_item = 0;
  # DEBUG BEGIN_STMT
  phy_if_16 = pfe_l2br_domain_get_next_if (domain_5(D));
  # DEBUG phy_if => phy_if_16

  <bb 8> [local count: 1073741824]:
  # phy_if_2 = PHI <0B(6), phy_if_16(7)>
  # DEBUG phy_if => phy_if_2
  # DEBUG BEGIN_STMT
  return phy_if_2;

}



;; Function pfe_l2br_domain_get_vlan (pfe_l2br_domain_get_vlan, funcdef_no=47, decl_uid=10369, cgraph_uid=48, symbol_order=54)

Modification phase of node pfe_l2br_domain_get_vlan/54
pfe_l2br_domain_get_vlan (const struct pfe_l2br_domain_t * domain, uint16_t * vlan)
{
  short unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_3(D)->vlan;
  *vlan_4(D) = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_l2br_domain_is_default (pfe_l2br_domain_is_default, funcdef_no=48, decl_uid=10379, cgraph_uid=49, symbol_order=55)

Modification phase of node pfe_l2br_domain_is_default/55
__attribute__((pure))
pfe_l2br_domain_is_default (const struct pfe_l2br_domain_t * domain)
{
  bool_t is_deft;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  is_deft_3 = domain_2(D)->is_default;
  # DEBUG is_deft => is_deft_3
  # DEBUG BEGIN_STMT
  return is_deft_3;

}



;; Function pfe_l2br_domain_is_fallback (pfe_l2br_domain_is_fallback, funcdef_no=49, decl_uid=10381, cgraph_uid=50, symbol_order=56)

Modification phase of node pfe_l2br_domain_is_fallback/56
__attribute__((pure))
pfe_l2br_domain_is_fallback (const struct pfe_l2br_domain_t * domain)
{
  bool_t is_fallback;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  is_fallback_3 = domain_2(D)->is_fallback;
  # DEBUG is_fallback => is_fallback_3
  # DEBUG BEGIN_STMT
  return is_fallback_3;

}



;; Function pfe_l2br_static_entry_create (pfe_l2br_static_entry_create, funcdef_no=51, decl_uid=10390, cgraph_uid=52, symbol_order=58)

Modification phase of node pfe_l2br_static_entry_create/58
pfe_l2br_static_entry_create (struct pfe_l2br_t * bridge, uint16_t vlan, const uint8_t * mac, uint32_t new_fw_list)
{
  errno_t ret;
  bool_t match;
  uint32_t index;
  struct pfe_l2br_static_entry_t * static_ent_tmp;
  struct pfe_l2br_static_entry_t * static_entry;
  struct pfe_isa_t * _1;
  short unsigned int _2;
  uint8_t[6] * _3;
  long int _4;
  long unsigned int _5;
  struct pfe_isa_t * _6;
  void * _7;
  struct pfe_l2br_static_entry_t * static_entry.16_8;
  uint8_t[6] * _9;
  struct pfe_l2br_static_entry_t * static_entry.18_10;

  <bb 2> [local count: 66962640]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG match => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG index => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _1 = &bridge_19(D)->static_entries;
  static_ent_tmp_21 = isa_item (_1, index_11);
  # DEBUG static_ent_tmp => static_ent_tmp_21
  # DEBUG BEGIN_STMT
  if (static_ent_tmp_21 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 4> [local count: 710280218]:
  # DEBUG BEGIN_STMT
  _2 = static_ent_tmp_21->vlan;
  if (_2 == vlan_22(D))
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 143760716]:
  # DEBUG BEGIN_STMT
  _3 = &static_ent_tmp_21->mac;
  _4 = autolibc_memcmp (_3, mac_23(D), 6);
  if (_4 == 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 1006779185]:
  # DEBUG BEGIN_STMT
  index_25 = index_11 + 1;
  # DEBUG index => index_25

  <bb 7> [local count: 1073741824]:
  # index_11 = PHI <0(2), index_25(6)>
  # DEBUG index => index_11
  # DEBUG BEGIN_STMT
  _5 = bridge_19(D)->static_entries.occupied_items_count;
  if (_5 > index_11)
    goto <bb 3>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 66962640]:
  # match_12 = PHI <1(5), 0(7)>
  # DEBUG match => match_12
  # DEBUG BEGIN_STMT
  if (match_12 == 1)
    goto <bb 9>; [21.72%]
  else
    goto <bb 10>; [78.28%]

  <bb 9> [local count: 14544285]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Duplicit entry\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2060, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 115
  goto <bb 14>; [100.00%]

  <bb 10> [local count: 52418354]:
  # DEBUG BEGIN_STMT
  _6 = &bridge_19(D)->static_entries;
  _7 = isa_reserve (_6);
  static_entry = _7;
  # DEBUG BEGIN_STMT
  if (_7 == 0B)
    goto <bb 11>; [18.75%]
  else
    goto <bb 12>; [81.25%]

  <bb 11> [local count: 9828441]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] No more L2 bridge static entries available\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2069, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 11
  goto <bb 14>; [100.00%]

  <bb 12> [local count: 42589913]:
  # DEBUG BEGIN_STMT
  autolibc_memset (_7, 0, 48);
  # DEBUG BEGIN_STMT
  static_entry.16_8 = static_entry;
  static_entry.16_8->vlan = vlan_22(D);
  # DEBUG BEGIN_STMT
  _9 = &static_entry.16_8->mac;
  autolibc_memcpy (_9, mac_23(D), 6);
  # DEBUG BEGIN_STMT
  ret_33 = pfe_l2br_set_static_entry (bridge_19(D), vlan_22(D), mac_23(D), new_fw_list_31(D), &static_entry);
  # DEBUG ret => ret_33
  # DEBUG BEGIN_STMT
  if (ret_33 != 0)
    goto <bb 13>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 13> [local count: 14054671]:
  # DEBUG BEGIN_STMT
  static_entry.18_10 = static_entry;
  isa_release (_6, static_entry.18_10);
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 66962640]:
  # ret_13 = PHI <115(9), 11(11), ret_33(12), ret_33(13)>
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  static_entry ={v} {CLOBBER};
  return ret_13;

}



;; Function pfe_l2br_static_entry_destroy (pfe_l2br_static_entry_destroy, funcdef_no=53, decl_uid=10393, cgraph_uid=54, symbol_order=60)

Modification phase of node pfe_l2br_static_entry_destroy/60
pfe_l2br_static_entry_destroy (struct pfe_l2br_t * bridge, struct pfe_l2br_static_entry_t * static_ent)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_5 = pfe_l2br_static_entry_destroy_nolock (bridge_2(D), static_ent_3(D));
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_l2br_static_entry_replace_fw_list (pfe_l2br_static_entry_replace_fw_list, funcdef_no=54, decl_uid=10397, cgraph_uid=55, symbol_order=61)

Modification phase of node pfe_l2br_static_entry_replace_fw_list/61
pfe_l2br_static_entry_replace_fw_list (const struct pfe_l2br_t * bridge, struct pfe_l2br_static_entry_t * static_ent, uint32_t new_fw_list)
{
  errno_t ret;
  <unnamed-unsigned:20> _1;
  <unnamed-unsigned:20> _2;
  struct pfe_l2br_table_entry_t * _3;
  long long unsigned int _4;
  int _5;
  struct pfe_l2br_table_t * _6;
  int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = static_ent_11(D)->u.action_data.item.forward_list;
  # DEBUG tmp => (uint32_t) _1
  # DEBUG BEGIN_STMT
  _2 = (<unnamed-unsigned:20>) new_fw_list_12(D);
  static_ent_11(D)->u.action_data.item.forward_list = _2;
  # DEBUG BEGIN_STMT
  _3 = &static_ent_11(D)->entry;
  _4 = static_ent_11(D)->u.action_data_u64val;
  _5 = pfe_l2br_table_entry_set_action_data (_3, _4);
  if (_5 != 0)
    goto <bb 3>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 3> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  static_ent_11(D)->u.action_data.item.forward_list = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t set action data\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2187, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _6 = bridge_15(D)->mac_table;
  _7 = pfe_l2br_table_update_entry (_6, _3);
  if (_7 != 0)
    goto <bb 5>; [20.96%]
  else
    goto <bb 6>; [79.04%]

  <bb 5> [local count: 146286586]:
  # DEBUG BEGIN_STMT
  static_ent_11(D)->u.action_data.item.forward_list = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t update entry\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2194, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2

  <bb 6> [local count: 1073741824]:
  # ret_8 = PHI <22(3), 2(5), 0(4)>
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  return ret_8;

}



;; Function pfe_l2br_static_entry_set_local_flag (pfe_l2br_static_entry_set_local_flag, funcdef_no=55, decl_uid=10427, cgraph_uid=56, symbol_order=62)

Modification phase of node pfe_l2br_static_entry_set_local_flag/62
pfe_l2br_static_entry_set_local_flag (const struct pfe_l2br_t * bridge, struct pfe_l2br_static_entry_t * static_ent, bool_t local)
{
  errno_t ret;
  <unnamed-unsigned:1> _1;
  struct pfe_l2br_table_entry_t * _2;
  long long unsigned int _3;
  int _4;
  struct pfe_l2br_table_t * _5;
  int _6;
  <unnamed-unsigned:1> iftmp.19_8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = static_ent_11(D)->u.action_data.item.local_l3;
  # DEBUG tmp => (uint32_t) _1
  # DEBUG BEGIN_STMT
  if (local_12(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.19_8 = PHI <1(2), 0(3)>
  static_ent_11(D)->u.action_data.item.local_l3 = iftmp.19_8;
  # DEBUG BEGIN_STMT
  _2 = &static_ent_11(D)->entry;
  _3 = static_ent_11(D)->u.action_data_u64val;
  _4 = pfe_l2br_table_entry_set_action_data (_2, _3);
  if (_4 != 0)
    goto <bb 5>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 5> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  static_ent_11(D)->u.action_data.item.local_l3 = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t set action data\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2235, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _5 = bridge_15(D)->mac_table;
  _6 = pfe_l2br_table_update_entry (_5, _2);
  if (_6 != 0)
    goto <bb 7>; [20.96%]
  else
    goto <bb 8>; [79.04%]

  <bb 7> [local count: 146286586]:
  # DEBUG BEGIN_STMT
  static_ent_11(D)->u.action_data.item.local_l3 = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t update entry\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2242, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2

  <bb 8> [local count: 1073741824]:
  # ret_7 = PHI <22(5), 2(7), 0(6)>
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_l2br_static_entry_set_src_discard_flag (pfe_l2br_static_entry_set_src_discard_flag, funcdef_no=56, decl_uid=10431, cgraph_uid=57, symbol_order=63)

Modification phase of node pfe_l2br_static_entry_set_src_discard_flag/63
pfe_l2br_static_entry_set_src_discard_flag (const struct pfe_l2br_t * bridge, struct pfe_l2br_static_entry_t * static_ent, bool_t src_discard)
{
  errno_t ret;
  <unnamed-unsigned:1> _1;
  struct pfe_l2br_table_entry_t * _2;
  long long unsigned int _3;
  int _4;
  struct pfe_l2br_table_t * _5;
  int _6;
  <unnamed-unsigned:1> iftmp.20_8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = static_ent_11(D)->u.action_data.item.src_discard;
  # DEBUG tmp => (uint32_t) _1
  # DEBUG BEGIN_STMT
  if (src_discard_12(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.20_8 = PHI <1(2), 0(3)>
  static_ent_11(D)->u.action_data.item.src_discard = iftmp.20_8;
  # DEBUG BEGIN_STMT
  _2 = &static_ent_11(D)->entry;
  _3 = static_ent_11(D)->u.action_data_u64val;
  _4 = pfe_l2br_table_entry_set_action_data (_2, _3);
  if (_4 != 0)
    goto <bb 5>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 5> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  static_ent_11(D)->u.action_data.item.src_discard = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t set action data\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2282, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _5 = bridge_15(D)->mac_table;
  _6 = pfe_l2br_table_update_entry (_5, _2);
  if (_6 != 0)
    goto <bb 7>; [20.96%]
  else
    goto <bb 8>; [79.04%]

  <bb 7> [local count: 146286586]:
  # DEBUG BEGIN_STMT
  static_ent_11(D)->u.action_data.item.src_discard = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t update entry\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2289, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2

  <bb 8> [local count: 1073741824]:
  # ret_7 = PHI <22(5), 2(7), 0(6)>
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_l2br_static_entry_set_dst_discard_flag (pfe_l2br_static_entry_set_dst_discard_flag, funcdef_no=57, decl_uid=10435, cgraph_uid=58, symbol_order=64)

Modification phase of node pfe_l2br_static_entry_set_dst_discard_flag/64
pfe_l2br_static_entry_set_dst_discard_flag (const struct pfe_l2br_t * bridge, struct pfe_l2br_static_entry_t * static_ent, bool_t dst_discard)
{
  errno_t ret;
  <unnamed-unsigned:1> _1;
  struct pfe_l2br_table_entry_t * _2;
  long long unsigned int _3;
  struct pfe_l2br_table_t * _4;
  int _5;
  <unnamed-unsigned:1> iftmp.21_7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = static_ent_10(D)->u.action_data.item.dst_discard;
  # DEBUG tmp => (uint32_t) _1
  # DEBUG BEGIN_STMT
  if (dst_discard_11(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.21_7 = PHI <1(2), 0(3)>
  static_ent_10(D)->u.action_data.item.dst_discard = iftmp.21_7;
  # DEBUG BEGIN_STMT
  _2 = &static_ent_10(D)->entry;
  _3 = static_ent_10(D)->u.action_data_u64val;
  ret_14 = pfe_l2br_table_entry_set_action_data (_2, _3);
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  if (ret_14 != 0)
    goto <bb 5>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 5> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  static_ent_10(D)->u.action_data.item.dst_discard = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t set action data\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2331, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _4 = bridge_15(D)->mac_table;
  _5 = pfe_l2br_table_update_entry (_4, _2);
  if (_5 != 0)
    goto <bb 7>; [20.96%]
  else
    goto <bb 8>; [79.04%]

  <bb 7> [local count: 146286586]:
  # DEBUG BEGIN_STMT
  static_ent_10(D)->u.action_data.item.dst_discard = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t update entry\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 2340, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2

  <bb 8> [local count: 1073741824]:
  # ret_6 = PHI <22(5), 0(6), 2(7)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_l2br_static_entry_get_local_flag (pfe_l2br_static_entry_get_local_flag, funcdef_no=58, decl_uid=10415, cgraph_uid=59, symbol_order=65)

Modification phase of node pfe_l2br_static_entry_get_local_flag/65
pfe_l2br_static_entry_get_local_flag (const struct pfe_l2br_t * bridge, const struct pfe_l2br_static_entry_t * static_ent, bool_t * local)
{
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = BIT_FIELD_REF <static_ent_5(D)->u.action_data.item, 8, 24>;
  _2 = _1 >> 4;
  _3 = _2 & 1;
  *local_6(D) = _3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_l2br_static_entry_get_src_discard_flag (pfe_l2br_static_entry_get_src_discard_flag, funcdef_no=59, decl_uid=10419, cgraph_uid=60, symbol_order=66)

Modification phase of node pfe_l2br_static_entry_get_src_discard_flag/66
pfe_l2br_static_entry_get_src_discard_flag (struct pfe_l2br_t * bridge, const struct pfe_l2br_static_entry_t * static_ent, bool_t * src_discard)
{
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = BIT_FIELD_REF <static_ent_5(D)->u.action_data.item, 8, 24>;
  _2 = _1 >> 3;
  _3 = _2 & 1;
  *src_discard_6(D) = _3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_l2br_static_entry_get_dst_discard_flag (pfe_l2br_static_entry_get_dst_discard_flag, funcdef_no=60, decl_uid=10423, cgraph_uid=61, symbol_order=67)

Modification phase of node pfe_l2br_static_entry_get_dst_discard_flag/67
pfe_l2br_static_entry_get_dst_discard_flag (const struct pfe_l2br_t * bridge, const struct pfe_l2br_static_entry_t * static_ent, bool_t * dst_discard)
{
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = BIT_FIELD_REF <static_ent_5(D)->u.action_data.item, 8, 24>;
  _2 = _1 >> 2;
  _3 = _2 & 1;
  *dst_discard_6(D) = _3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_l2br_static_entry_get_fw_list (pfe_l2br_static_entry_get_fw_list, funcdef_no=61, decl_uid=10399, cgraph_uid=62, symbol_order=68)

Modification phase of node pfe_l2br_static_entry_get_fw_list/68
__attribute__((pure))
pfe_l2br_static_entry_get_fw_list (const struct pfe_l2br_static_entry_t * static_ent)
{
  uint32_t fw_list;
  <unnamed-unsigned:20> _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = static_ent_3(D)->u.action_data.item.forward_list;
  fw_list_4 = (uint32_t) _1;
  # DEBUG fw_list => fw_list_4
  # DEBUG BEGIN_STMT
  return fw_list_4;

}



;; Function pfe_l2br_static_entry_get_vlan (pfe_l2br_static_entry_get_vlan, funcdef_no=62, decl_uid=10401, cgraph_uid=63, symbol_order=69)

Modification phase of node pfe_l2br_static_entry_get_vlan/69
__attribute__((pure))
pfe_l2br_static_entry_get_vlan (const struct pfe_l2br_static_entry_t * static_ent)
{
  uint16_t _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _3 = static_ent_2(D)->vlan;
  return _3;

}



;; Function pfe_l2br_static_entry_get_mac (pfe_l2br_static_entry_get_mac, funcdef_no=63, decl_uid=10404, cgraph_uid=64, symbol_order=70)

Modification phase of node pfe_l2br_static_entry_get_mac/70
pfe_l2br_static_entry_get_mac (const struct pfe_l2br_static_entry_t * static_ent, uint8_t * mac)
{
  const uint8_t[6] * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = &static_ent_2(D)->mac;
  autolibc_memcpy (mac_4(D), _1, 6);
  return;

}



;; Function pfe_l2br_static_entry_get_next (pfe_l2br_static_entry_get_next, funcdef_no=65, decl_uid=10411, cgraph_uid=66, symbol_order=72)

Modification phase of node pfe_l2br_static_entry_get_next/72
pfe_l2br_static_entry_get_next (struct pfe_l2br_t * bridge)
{
  bool_t match;
  struct pfe_l2br_static_entry_t * static_ent;
  struct pfe_isa_t * _1;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 88896196]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG match => 0
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  _1 = &bridge_17(D)->static_entries;
  static_ent_19 = isa_item (_1, _6);
  # DEBUG static_ent => static_ent_19
  # DEBUG BEGIN_STMT
  _3 = bridge_17(D)->curr_static_ent;
  _4 = _3 + 1;
  bridge_17(D)->curr_static_ent = _4;
  # DEBUG BEGIN_STMT
  if (static_ent_19 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 4> [local count: 542552617]:
  # DEBUG BEGIN_STMT
  _5 = pfe_l2br_static_entry_match_criterion (bridge_17(D), static_ent_19);
  if (_5 == 1)
    goto <bb 7>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 984845630]:
  # static_ent_14 = PHI <static_ent_19(3), static_ent_19(4)>

  <bb 10> [local count: 1073741824]:
  # static_ent_8 = PHI <static_ent_14(6), static_ent_15(D)(2)>
  # DEBUG static_ent => static_ent_8
  # DEBUG BEGIN_STMT
  _6 = bridge_17(D)->curr_static_ent;
  _7 = bridge_17(D)->static_entries.occupied_items_count;
  if (_6 < _7)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 88896194]:
  # static_ent_9 = PHI <static_ent_19(4), static_ent_8(10)>
  # match_11 = PHI <1(4), 0(10)>
  # DEBUG match => match_11
  # DEBUG static_ent => static_ent_9
  # DEBUG BEGIN_STMT
  if (match_11 != 1)
    goto <bb 8>; [44.22%]
  else
    goto <bb 9>; [55.78%]

  <bb 8> [local count: 39309897]:
  # DEBUG BEGIN_STMT
  # DEBUG static_ent => 0B

  <bb 9> [local count: 88896194]:
  # static_ent_10 = PHI <static_ent_9(7), 0B(8)>
  # DEBUG static_ent => static_ent_10
  # DEBUG BEGIN_STMT
  return static_ent_10;

}



;; Function pfe_l2br_static_entry_get_first (pfe_l2br_static_entry_get_first, funcdef_no=64, decl_uid=10409, cgraph_uid=65, symbol_order=71)

Modification phase of node pfe_l2br_static_entry_get_first/71
pfe_l2br_static_entry_get_first (struct pfe_l2br_t * bridge, pfe_l2br_static_ent_get_crit_t crit, void * arg1, const void * arg2)
{
  struct pfe_l2br_static_entry_t * static_ent;
  uint8_t[6] * _1;
  int arg1.22_2;
  short unsigned int _3;
  int arg1.23_4;
  short unsigned int _5;
  uint8_t[6] * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  bridge_9(D)->cur_crit_ent = crit_10(D);
  # DEBUG BEGIN_STMT
  switch (crit_10(D)) <default: <L7> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%], case 3: <L3> [25.00%]>

  <bb 3> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  _1 = &bridge_9(D)->cur_static_ent_crit_arg.mac;
  autolibc_memcpy (_1, arg2_14(D), 6);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  arg1.22_2 = (int) arg1_12(D);
  _3 = (short unsigned int) arg1.22_2;
  bridge_9(D)->cur_static_ent_crit_arg.vlan = _3;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L3>:
  # DEBUG BEGIN_STMT
  arg1.23_4 = (int) arg1_12(D);
  _5 = (short unsigned int) arg1.23_4;
  bridge_9(D)->cur_static_ent_crit_arg.vlan = _5;
  # DEBUG BEGIN_STMT
  _6 = &bridge_9(D)->cur_static_ent_crit_arg.mac;
  autolibc_memcpy (_6, arg2_14(D), 6);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L7>:
  # DEBUG BEGIN_STMT
  bridge_9(D)->curr_static_ent = 0;
  # DEBUG BEGIN_STMT
  static_ent_20 = pfe_l2br_static_entry_get_next (bridge_9(D));
  # DEBUG static_ent => static_ent_20
  # DEBUG BEGIN_STMT
  return static_ent_20;

}



;; Function pfe_l2br_flush_learned (pfe_l2br_flush_learned, funcdef_no=73, decl_uid=10471, cgraph_uid=74, symbol_order=80)

Modification phase of node pfe_l2br_flush_learned/80
pfe_l2br_flush_learned (struct pfe_l2br_t * bridge)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_4 = pfe_l2br_flush (bridge_2(D), 2);
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_l2br_flush_static (pfe_l2br_flush_static, funcdef_no=74, decl_uid=10473, cgraph_uid=75, symbol_order=81)

Modification phase of node pfe_l2br_flush_static/81
pfe_l2br_flush_static (struct pfe_l2br_t * bridge)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_4 = pfe_l2br_flush (bridge_2(D), 1);
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_l2br_flush_all (pfe_l2br_flush_all, funcdef_no=75, decl_uid=10475, cgraph_uid=76, symbol_order=82)

Modification phase of node pfe_l2br_flush_all/82
pfe_l2br_flush_all (struct pfe_l2br_t * bridge)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_4 = pfe_l2br_flush (bridge_2(D), 0);
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_l2br_destroy (pfe_l2br_destroy, funcdef_no=78, decl_uid=10444, cgraph_uid=79, symbol_order=85)

Modification phase of node pfe_l2br_destroy/85
pfe_l2br_destroy (struct pfe_l2br_t * bridge)
{
  errno_t ret;
  struct pfe_l2br_domain_t * _1;
  int _2;
  struct pfe_l2br_domain_t * _3;
  int _4;
  struct pfe_isa_t * _5;
  struct pfe_class_t * _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (bridge_12(D) != 0B)
    goto <bb 3>; [81.25%]
  else
    goto <bb 10>; [18.75%]

  <bb 3> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  _1 = bridge_12(D)->default_domain;
  if (_1 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 4> [local count: 466480425]:
  # DEBUG BEGIN_STMT
  _2 = pfe_l2br_domain_destroy (_1);
  if (_2 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 233240212]:
  # DEBUG BEGIN_STMT
  bridge_12(D)->default_domain = 0B;

  <bb 6> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = bridge_12(D)->fallback_domain;
  if (_3 != 0B)
    goto <bb 7>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 7> [local count: 466480425]:
  # DEBUG BEGIN_STMT
  _4 = pfe_l2br_domain_destroy (_3);
  if (_4 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 233240212]:
  # DEBUG BEGIN_STMT
  bridge_12(D)->fallback_domain = 0B;

  <bb 9> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = &bridge_12(D)->domains;
  isa_isempty (_5);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = bridge_12(D)->class;
  _7 = bridge_12(D)->domain_stats_table_addr;
  pfe_l2br_destroy_vlan_stats_table (_6, _7);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 10> [local count: 1073741824]:
  # ret_8 = PHI <0(9), 22(2)>
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  return ret_8;

}



;; Function pfe_l2br_get_default_domain (pfe_l2br_get_default_domain, funcdef_no=79, decl_uid=10446, cgraph_uid=80, symbol_order=86)

Modification phase of node pfe_l2br_get_default_domain/86
__attribute__((pure))
pfe_l2br_get_default_domain (const struct pfe_l2br_t * bridge)
{
  struct pfe_l2br_domain_t * default_domain;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  default_domain_3 = bridge_2(D)->default_domain;
  # DEBUG default_domain => default_domain_3
  # DEBUG BEGIN_STMT
  return default_domain_3;

}



;; Function pfe_l2br_get_fallback_domain (pfe_l2br_get_fallback_domain, funcdef_no=80, decl_uid=10448, cgraph_uid=81, symbol_order=87)

Modification phase of node pfe_l2br_get_fallback_domain/87
__attribute__((pure))
pfe_l2br_get_fallback_domain (const struct pfe_l2br_t * bridge)
{
  struct pfe_l2br_domain_t * fallback_domain;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  fallback_domain_3 = bridge_2(D)->fallback_domain;
  # DEBUG fallback_domain => fallback_domain_3
  # DEBUG BEGIN_STMT
  return fallback_domain_3;

}



;; Function pfe_l2br_get_next_domain (pfe_l2br_get_next_domain, funcdef_no=83, decl_uid=10454, cgraph_uid=84, symbol_order=90)

Modification phase of node pfe_l2br_get_next_domain/90
pfe_l2br_get_next_domain (struct pfe_l2br_t * bridge)
{
  bool_t match;
  struct pfe_l2br_domain_t * domain;
  struct pfe_isa_t * _1;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 88896196]:
  # DEBUG BEGIN_STMT
  # DEBUG domain => 0B
  # DEBUG BEGIN_STMT
  # DEBUG match => 0
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  _1 = &bridge_16(D)->domains;
  domain_18 = isa_item (_1, _6);
  # DEBUG domain => domain_18
  # DEBUG BEGIN_STMT
  _3 = bridge_16(D)->curr_domain;
  _4 = _3 + 1;
  bridge_16(D)->curr_domain = _4;
  # DEBUG BEGIN_STMT
  if (domain_18 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 4> [local count: 542552617]:
  # DEBUG BEGIN_STMT
  _5 = pfe_l2br_domain_match_criterion (bridge_16(D), domain_18);
  if (_5 == 1)
    goto <bb 7>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 984845630]:
  # domain_14 = PHI <domain_18(3), domain_18(4)>

  <bb 10> [local count: 1073741824]:
  # domain_8 = PHI <domain_14(6), 0B(2)>
  # DEBUG domain => domain_8
  # DEBUG BEGIN_STMT
  _6 = bridge_16(D)->curr_domain;
  _7 = bridge_16(D)->domains.occupied_items_count;
  if (_6 < _7)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 88896194]:
  # domain_9 = PHI <domain_18(4), domain_8(10)>
  # match_11 = PHI <1(4), 0(10)>
  # DEBUG match => match_11
  # DEBUG domain => domain_9
  # DEBUG BEGIN_STMT
  if (match_11 != 1)
    goto <bb 8>; [44.22%]
  else
    goto <bb 9>; [55.78%]

  <bb 8> [local count: 39309897]:
  # DEBUG BEGIN_STMT
  # DEBUG domain => 0B

  <bb 9> [local count: 88896194]:
  # domain_10 = PHI <domain_9(7), 0B(8)>
  # DEBUG domain => domain_10
  # DEBUG BEGIN_STMT
  return domain_10;

}



;; Function pfe_l2br_get_first_domain (pfe_l2br_get_first_domain, funcdef_no=82, decl_uid=10452, cgraph_uid=83, symbol_order=89)

Modification phase of node pfe_l2br_get_first_domain/89
pfe_l2br_get_first_domain (struct pfe_l2br_t * bridge, pfe_l2br_domain_get_crit_t crit, void * arg)
{
  struct pfe_l2br_domain_t * domain;
  int arg.32_2;
  short unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG domain => 0B
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  bridge_8(D)->cur_crit = crit_9(D);
  # DEBUG BEGIN_STMT
  switch (crit_9(D)) <default: <L3> [25.00%], case 0: <L10> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  arg.32_2 = (int) arg_11(D);
  _3 = (short unsigned int) arg.32_2;
  bridge_8(D)->cur_domain_crit_arg.vlan = _3;
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  bridge_8(D)->cur_domain_crit_arg.phy_if = arg_11(D);
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L3>:
  # DEBUG D#21 => bridge_8(D)
  # DEBUG D#22 => crit_9(D)
  # DEBUG D#23 => arg_11(D)
  domain_6 = pfe_l2br_get_first_domain.part.0 ();
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 805306369]:
<L10>:
  # DEBUG known_crit => NULL
  # DEBUG BEGIN_STMT
  bridge_8(D)->curr_domain = 0;
  # DEBUG BEGIN_STMT
  domain_16 = pfe_l2br_get_next_domain (bridge_8(D));
  # DEBUG domain => domain_16

  <bb 7> [local count: 1073741824]:
  # domain_4 = PHI <domain_6(5), domain_16(6)>
  # DEBUG domain => domain_4
  # DEBUG BEGIN_STMT
  return domain_4;

}



;; Function pfe_l2br_domain_create (pfe_l2br_domain_create, funcdef_no=28, decl_uid=10340, cgraph_uid=29, symbol_order=35)

Modification phase of node pfe_l2br_domain_create/35
pfe_l2br_domain_create (struct pfe_l2br_t * bridge, uint16_t vlan)
{
  errno_t ret;
  unsigned int _1;
  void * _2;
  struct pfe_l2br_domain_t * _3;
  int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) vlan_7(D);
  _2 = (void *) _1;
  _3 = pfe_l2br_get_first_domain (bridge_9(D), 1, _2);
  if (_3 != 0B)
    goto <bb 3>; [55.68%]
  else
    goto <bb 4>; [44.32%]

  <bb 3> [local count: 597859448]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = (int) vlan_7(D);
  pfe_hm_report (1, 2, 1, "[%s:%d] Domain with vlan %d does already exist\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_l2br.c", 1031, _4, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 115
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 475882376]:
  ret_6 = pfe_l2br_domain_create.part.0 (bridge_9(D), vlan_7(D));

  <bb 5> [local count: 1073741824]:
  # ret_5 = PHI <115(3), ret_6(4)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_l2br_create (pfe_l2br_create, funcdef_no=77, decl_uid=10442, cgraph_uid=78, symbol_order=84)

Modification phase of node pfe_l2br_create/84
pfe_l2br_create (struct pfe_class_t * class, uint16_t def_vlan, uint16_t def_aging_time, uint16_t vlan_stats_size, struct pfe_l2br_table_t * mac_table, struct pfe_l2br_table_t * vlan_table)
{
  struct pfe_l2br_t * bridge;
  struct pfe_l2br_t * bridge.25_1;
  struct pfe_l2br_t * bridge.29_2;
  struct pfe_l2br_t * bridge.30_3;
  long unsigned int _4;
  struct pfe_l2br_t * _25;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  bridge = &l2_bridge_instance;
  # DEBUG BEGIN_STMT
  autolibc_memset (&l2_bridge_instance, 0, 5632);
  # DEBUG BEGIN_STMT
  bridge.25_1 = bridge;
  bridge.25_1->class = class_8(D);
  # DEBUG BEGIN_STMT
  bridge.25_1->mac_table = mac_table_10(D);
  # DEBUG BEGIN_STMT
  bridge.25_1->vlan_table = vlan_table_12(D);
  # DEBUG BEGIN_STMT
  bridge.25_1->def_vlan = def_vlan_14(D);
  # DEBUG BEGIN_STMT
  isa_init (&l2_bridge_instance.static_entries, &l2_bridge_instance_statics_isa_def);
  # DEBUG BEGIN_STMT
  isa_init (&l2_bridge_instance.domains, &l2_bridge_instance_domains_isa_def);
  # DEBUG BEGIN_STMT
  bridge.29_2 = bridge;
  bridge.29_2->domain_stats_table_size = vlan_stats_size_18(D);
  # DEBUG BEGIN_STMT
  autolibc_memset (&stats_index, 0, 128);
  # DEBUG BEGIN_STMT
  bridge.30_3 = bridge;
  _4 = pfe_l2br_create_vlan_stats_table (class_8(D), vlan_stats_size_18(D));
  bridge.30_3->domain_stats_table_addr = _4;
  # DEBUG BEGIN_STMT
  pfe_l2br_create_mandatory_domains (class_8(D), &bridge, def_vlan_14(D), def_aging_time_23(D));
  # DEBUG BEGIN_STMT
  _25 = bridge;
  bridge ={v} {CLOBBER};
  return _25;

}



;; Function pfe_l2br_get_number_entries (pfe_l2br_get_number_entries, funcdef_no=85, decl_uid=10460, cgraph_uid=86, symbol_order=92)

Modification phase of node pfe_l2br_get_number_entries/92
pfe_l2br_get_number_entries (const struct pfe_l2br_t * bridge)
{
  uint32_t number_entries;
  errno_t ret;
  struct pfe_l2br_table_iterator_t l2t_iter;
  struct pfe_l2br_table_entry_t entry;
  struct pfe_l2br_table_t * _1;
  struct pfe_l2br_table_t * _2;
  struct pfe_l2br_table_t * _3;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG number_entries => 0
  # DEBUG BEGIN_STMT
  _1 = bridge_8(D)->mac_table;
  pfe_l2br_table_entry_create (_1, &entry);
  # DEBUG BEGIN_STMT
  pfe_l2br_iterator_create (&l2t_iter);
  # DEBUG BEGIN_STMT
  _2 = bridge_8(D)->mac_table;
  ret_12 = pfe_l2br_table_get_first (_2, &l2t_iter, 1, &entry);
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  number_entries_16 = number_entries_5 + 1;
  # DEBUG number_entries => number_entries_16
  # DEBUG BEGIN_STMT
  _3 = bridge_8(D)->mac_table;
  ret_18 = pfe_l2br_table_get_next (_3, &l2t_iter, &entry);
  # DEBUG ret => ret_18

  <bb 4> [local count: 1073741824]:
  # ret_4 = PHI <ret_12(2), ret_18(3)>
  # number_entries_5 = PHI <0(2), number_entries_16(3)>
  # DEBUG number_entries => number_entries_5
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  if (ret_4 == 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # number_entries_13 = PHI <number_entries_5(4)>
  # DEBUG BEGIN_STMT
  entry ={v} {CLOBBER};
  l2t_iter ={v} {CLOBBER};
  return number_entries_13;

}



;; Function pfe_l2br_get_stats (pfe_l2br_get_stats, funcdef_no=86, decl_uid=10458, cgraph_uid=87, symbol_order=93)

Modification phase of node pfe_l2br_get_stats/93
pfe_l2br_get_stats (const struct pfe_l2br_t * bridge, struct Eth_43_PFE_L2BridgeStatsType * stat, uint32_t index_entry)
{
  errno_t order_entry;
  uint32_t count;
  errno_t ret;
  struct pfe_l2br_table_iterator_t l2t_iter;
  struct pfe_l2br_table_entry_t entry;
  struct pfe_l2br_table_t * _1;
  struct pfe_l2br_table_t * _2;
  <unnamed type> _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  unsigned char _9;
  <unnamed-unsigned:13> _10;
  long unsigned int _11;
  <unnamed-unsigned:31> _12;
  long unsigned int _13;
  short unsigned int _14;
  long unsigned int _15;
  <unnamed-unsigned:4> _16;
  long unsigned int _17;
  <unnamed-unsigned:13> _18;
  long unsigned int _19;
  <unnamed-unsigned:55> _20;
  long unsigned int _21;
  short unsigned int _22;
  long unsigned int _23;
  <unnamed-unsigned:4> _24;
  long unsigned int _25;
  struct pfe_l2br_table_t * _26;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG count => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bridge_33(D)->mac_table;
  pfe_l2br_table_entry_create (_1, &entry);
  # DEBUG BEGIN_STMT
  pfe_l2br_iterator_create (&l2t_iter);
  # DEBUG BEGIN_STMT
  _2 = bridge_33(D)->mac_table;
  order_entry_37 = pfe_l2br_table_get_first (_2, &l2t_iter, 1, &entry);
  # DEBUG order_entry => order_entry_37
  # DEBUG BEGIN_STMT
  if (order_entry_37 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 3> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1
  goto <bb 10>; [100.00%]

  <bb 4> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  if (count_27 == index_entry_38(D))
    goto <bb 5>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 5> [local count: 55807731]:
  # DEBUG BEGIN_STMT
  _3 = entry.type;
  if (_3 == 1)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 18974629]:
  # DEBUG BEGIN_STMT
  _4 = entry.u.mac2f_entry.mac[0];
  stat_42(D)->mac_address[0] = _4;
  # DEBUG BEGIN_STMT
  _5 = entry.u.mac2f_entry.mac[1];
  stat_42(D)->mac_address[1] = _5;
  # DEBUG BEGIN_STMT
  _6 = entry.u.mac2f_entry.mac[2];
  stat_42(D)->mac_address[2] = _6;
  # DEBUG BEGIN_STMT
  _7 = entry.u.mac2f_entry.mac[3];
  stat_42(D)->mac_address[3] = _7;
  # DEBUG BEGIN_STMT
  _8 = entry.u.mac2f_entry.mac[4];
  stat_42(D)->mac_address[4] = _8;
  # DEBUG BEGIN_STMT
  _9 = entry.u.mac2f_entry.mac[5];
  stat_42(D)->mac_address[5] = _9;
  # DEBUG BEGIN_STMT
  _10 = entry.u.mac2f_entry.vlan;
  _11 = (long unsigned int) _10;
  stat_42(D)->vlan = _11;
  # DEBUG BEGIN_STMT
  _12 = entry.u.mac2f_entry.action_data;
  _13 = (long unsigned int) _12;
  stat_42(D)->action_data = _13;
  # DEBUG BEGIN_STMT
  _14 = entry.u.mac2f_entry.col_ptr;
  _15 = (long unsigned int) _14;
  stat_42(D)->col_ptr = _15;
  # DEBUG BEGIN_STMT
  _16 = entry.u.mac2f_entry.flags;
  _17 = (long unsigned int) _16;
  stat_42(D)->flags = _17;

  <bb 7> [local count: 55807731]:
  # DEBUG BEGIN_STMT
  if (_3 == 2)
    goto <bb 8>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 8> [local count: 18974629]:
  # DEBUG BEGIN_STMT
  _18 = entry.u.vlan_entry.vlan;
  _19 = (long unsigned int) _18;
  stat_42(D)->vlan = _19;
  # DEBUG BEGIN_STMT
  _20 = entry.u.vlan_entry.action_data;
  _21 = (long unsigned int) _20;
  stat_42(D)->action_data = _21;
  # DEBUG BEGIN_STMT
  _22 = entry.u.vlan_entry.col_ptr;
  _23 = (long unsigned int) _22;
  stat_42(D)->col_ptr = _23;
  # DEBUG BEGIN_STMT
  _24 = entry.u.vlan_entry.flags;
  _25 = (long unsigned int) _24;
  stat_42(D)->flags = _25;
  goto <bb 12>; [100.00%]

  <bb 9> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  count_39 = count_27 + 1;
  # DEBUG count => count_39
  # DEBUG BEGIN_STMT
  _26 = bridge_33(D)->mac_table;
  order_entry_41 = pfe_l2br_table_get_next (_26, &l2t_iter, &entry);
  # DEBUG order_entry => order_entry_41
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 114863532]:
  # ret_59 = PHI <1(3), 0(2)>

  <bb 11> [local count: 1073741824]:
  # count_27 = PHI <0(10), count_39(9)>
  # order_entry_28 = PHI <order_entry_37(10), order_entry_41(9)>
  # DEBUG order_entry => order_entry_28
  # DEBUG count => count_27
  # DEBUG ret => ret_59
  # DEBUG BEGIN_STMT
  if (order_entry_28 == 0)
    goto <bb 4>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 12> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  entry ={v} {CLOBBER};
  l2t_iter ={v} {CLOBBER};
  return ret_59;

}



;; Function pfe_l2br_static_entry_get_entry (pfe_l2br_static_entry_get_entry, funcdef_no=87, decl_uid=10477, cgraph_uid=88, symbol_order=94)

Modification phase of node pfe_l2br_static_entry_get_entry/94
pfe_l2br_static_entry_get_entry (struct pfe_l2br_static_entry_t * static_ent)
{
  struct pfe_l2br_table_entry_t * new_entry;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  new_entry_2 = &static_ent_1(D)->entry;
  # DEBUG new_entry => new_entry_2
  # DEBUG BEGIN_STMT
  return new_entry_2;

}



;; Function pfe_l2br_get_domain_stats (pfe_l2br_get_domain_stats, funcdef_no=88, decl_uid=10467, cgraph_uid=89, symbol_order=95)

Modification phase of node pfe_l2br_get_domain_stats/95
pfe_l2br_get_domain_stats (const struct pfe_l2br_t * bridge, struct pfe_ct_vlan_stats_t * stat, uint8_t vlan_index)
{
  const uint32_t egress_bytes_add;
  const uint32_t ingress_bytes_add;
  const uint32_t egress_add;
  const uint32_t ingress_add;
  const uint16_t offset;
  struct pfe_ct_vlan_stats_t stats;
  errno_t ret;
  uint32_t num_of_pes;
  uint32_t i;
  short unsigned int _1;
  struct pfe_class_t * _2;
  struct pfe_class_t * _3;
  long int i.33_4;
  long unsigned int _5;
  unsigned int _6;
  unsigned int _7;
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
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  long unsigned int _36;
  long unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _41;
  long unsigned int _42;
  long unsigned int _43;
  long unsigned int _44;
  long unsigned int _45;
  long unsigned int _46;
  long unsigned int _47;
  long unsigned int _48;
  long unsigned int _49;
  long unsigned int _50;
  long unsigned int _51;
  long unsigned int _52;
  long unsigned int _53;
  long unsigned int _54;
  long unsigned int _55;
  long unsigned int _56;
  long unsigned int _57;
  long unsigned int _58;
  long unsigned int _59;
  long unsigned int _60;
  long unsigned int _61;
  long unsigned int _62;
  long unsigned int _63;
  long unsigned int _64;
  long unsigned int _65;
  long unsigned int _66;
  long unsigned int _67;
  long unsigned int _68;
  long unsigned int _69;
  long unsigned int _70;
  long unsigned int _71;
  long unsigned int _72;
  long unsigned int _73;
  long unsigned int _74;
  long unsigned int _75;
  long unsigned int _76;
  long unsigned int _77;
  long unsigned int _78;
  long unsigned int _79;
  long unsigned int _80;
  long unsigned int _81;
  long unsigned int _82;
  long unsigned int _83;
  long unsigned int _84;
  long unsigned int _85;
  long unsigned int _86;
  long unsigned int _87;
  long unsigned int _88;
  long unsigned int _89;
  long unsigned int _90;
  long unsigned int _91;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (stat_98(D), 0, 16);
  # DEBUG BEGIN_STMT
  _1 = (short unsigned int) vlan_index_100(D);
  offset_101 = _1 * 16;
  # DEBUG offset => offset_101
  # DEBUG BEGIN_STMT
  _2 = bridge_102(D)->class;
  num_of_pes_104 = pfe_class_get_num_of_pes (_2);
  # DEBUG num_of_pes => num_of_pes_104
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  autolibc_memset (&stats, 0, 16);
  # DEBUG BEGIN_STMT
  _3 = bridge_102(D)->class;
  i.33_4 = (long int) i_92;
  _5 = bridge_102(D)->domain_stats_table_addr;
  _6 = (unsigned int) offset_101;
  _7 = _5 + _6;
  ret_107 = pfe_class_read_dmem (_3, i.33_4, &stats, _7, 16);
  # DEBUG ret => ret_107
  # DEBUG BEGIN_STMT
  if (ret_107 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  _8 = stats.ingress;
  _9 = _8 >> 24;
  _10 = _8 >> 8;
  _11 = _10 & 65280;
  _12 = _9 | _11;
  _13 = _8 << 8;
  _14 = _13 & 16711680;
  _15 = _12 | _14;
  _16 = _8 << 24;
  ingress_add_108 = _15 | _16;
  # DEBUG ingress_add => ingress_add_108
  # DEBUG BEGIN_STMT
  _17 = stats.egress;
  _18 = _17 >> 24;
  _19 = _17 >> 8;
  _20 = _19 & 65280;
  _21 = _18 | _20;
  _22 = _17 << 8;
  _23 = _22 & 16711680;
  _24 = _21 | _23;
  _25 = _17 << 24;
  egress_add_109 = _24 | _25;
  # DEBUG egress_add => egress_add_109
  # DEBUG BEGIN_STMT
  _26 = stats.ingress_bytes;
  _27 = _26 >> 24;
  _28 = _26 >> 8;
  _29 = _28 & 65280;
  _30 = _27 | _29;
  _31 = _26 << 8;
  _32 = _31 & 16711680;
  _33 = _30 | _32;
  _34 = _26 << 24;
  ingress_bytes_add_110 = _33 | _34;
  # DEBUG ingress_bytes_add => ingress_bytes_add_110
  # DEBUG BEGIN_STMT
  _35 = stats.egress_bytes;
  _36 = _35 >> 24;
  _37 = _35 >> 8;
  _38 = _37 & 65280;
  _39 = _36 | _38;
  _40 = _35 << 8;
  _41 = _40 & 16711680;
  _42 = _39 | _41;
  _43 = _35 << 24;
  egress_bytes_add_111 = _42 | _43;
  # DEBUG egress_bytes_add => egress_bytes_add_111
  # DEBUG BEGIN_STMT
  _44 = stat_98(D)->ingress;
  _45 = _44 + ingress_add_108;
  stat_98(D)->ingress = _45;
  # DEBUG BEGIN_STMT
  _46 = stat_98(D)->egress;
  _47 = _46 + egress_add_109;
  stat_98(D)->egress = _47;
  # DEBUG BEGIN_STMT
  _48 = stat_98(D)->ingress_bytes;
  _49 = _48 + ingress_bytes_add_110;
  stat_98(D)->ingress_bytes = _49;
  # DEBUG BEGIN_STMT
  _50 = stat_98(D)->egress_bytes;
  _51 = _50 + egress_bytes_add_111;
  stat_98(D)->egress_bytes = _51;
  # DEBUG BEGIN_STMT
  i_116 = i_92 + 1;
  # DEBUG i => i_116

  <bb 5> [local count: 1073741824]:
  # i_92 = PHI <0(2), i_116(4)>
  # ret_93 = PHI <0(2), 0(4)>
  # DEBUG ret => ret_93
  # DEBUG i => i_92
  # DEBUG BEGIN_STMT
  if (i_92 < num_of_pes_104)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 114863532]:
  # ret_94 = PHI <ret_107(3), ret_93(5)>
  # DEBUG ret => ret_94
  # DEBUG BEGIN_STMT
  _52 = stat_98(D)->ingress;
  _53 = _52 >> 24;
  _54 = _52 >> 8;
  _55 = _54 & 65280;
  _56 = _53 | _55;
  _57 = _52 << 8;
  _58 = _57 & 16711680;
  _59 = _56 | _58;
  _60 = _52 << 24;
  _61 = _59 | _60;
  stat_98(D)->ingress = _61;
  # DEBUG BEGIN_STMT
  _62 = stat_98(D)->egress;
  _63 = _62 >> 24;
  _64 = _62 >> 8;
  _65 = _64 & 65280;
  _66 = _63 | _65;
  _67 = _62 << 8;
  _68 = _67 & 16711680;
  _69 = _66 | _68;
  _70 = _62 << 24;
  _71 = _69 | _70;
  stat_98(D)->egress = _71;
  # DEBUG BEGIN_STMT
  _72 = stat_98(D)->ingress_bytes;
  _73 = _72 >> 24;
  _74 = _72 >> 8;
  _75 = _74 & 65280;
  _76 = _73 | _75;
  _77 = _72 << 8;
  _78 = _77 & 16711680;
  _79 = _76 | _78;
  _80 = _72 << 24;
  _81 = _79 | _80;
  stat_98(D)->ingress_bytes = _81;
  # DEBUG BEGIN_STMT
  _82 = stat_98(D)->egress_bytes;
  _83 = _82 >> 24;
  _84 = _82 >> 8;
  _85 = _84 & 65280;
  _86 = _83 | _85;
  _87 = _82 << 8;
  _88 = _87 & 16711680;
  _89 = _86 | _88;
  _90 = _82 << 24;
  _91 = _89 | _90;
  stat_98(D)->egress_bytes = _91;
  # DEBUG BEGIN_STMT
  stats ={v} {CLOBBER};
  return ret_94;

}



;; Function pfe_l2br_clear_domain_stats (pfe_l2br_clear_domain_stats, funcdef_no=89, decl_uid=10463, cgraph_uid=90, symbol_order=96)

Modification phase of node pfe_l2br_clear_domain_stats/96
pfe_l2br_clear_domain_stats (const struct pfe_l2br_t * bridge, uint8_t vlan_index)
{
  const uint16_t offset;
  struct pfe_ct_vlan_stats_t stat;
  errno_t ret;
  short unsigned int _1;
  struct pfe_class_t * _2;
  long unsigned int _3;
  unsigned int _4;
  unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stat = {};
  # DEBUG BEGIN_STMT
  _1 = (short unsigned int) vlan_index_8(D);
  offset_9 = _1 * 16;
  # DEBUG offset => offset_9
  # DEBUG BEGIN_STMT
  _2 = bridge_10(D)->class;
  _3 = bridge_10(D)->domain_stats_table_addr;
  _4 = (unsigned int) offset_9;
  _5 = _3 + _4;
  ret_12 = pfe_class_write_dmem (_2, -1, _5, &stat, 16);
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  stat ={v} {CLOBBER};
  return ret_12;

}



;; Function pfe_l2br_get_vlan_stats_index (pfe_l2br_get_vlan_stats_index, funcdef_no=90, decl_uid=10469, cgraph_uid=91, symbol_order=97)

Modification phase of node pfe_l2br_get_vlan_stats_index/97
pfe_l2br_get_vlan_stats_index (const struct pfe_l2br_domain_t * domain)
{
  uint8_t stats_idx;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stats_idx_3 = domain_2(D)->stats_index;
  # DEBUG stats_idx => stats_idx_3
  # DEBUG BEGIN_STMT
  return stats_idx_3;

}


